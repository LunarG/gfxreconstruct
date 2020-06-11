/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "application/xcb_window.h"

#include "application/xcb_application.h"
#include "util/logging.h"

#include <cstdlib>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

XcbApplication::XcbApplication(const std::string& name) : Application(name), connection_(nullptr), screen_(nullptr) {}

XcbApplication::~XcbApplication()
{
    if (connection_ != nullptr)
    {
        auto& xcb = xcb_loader_.GetFunctionTable();
        xcb.disconnect(connection_);
    }
}

bool XcbApplication::Initialize(decode::FileProcessor* file_processor)
{
    if (!xcb_loader_.Initialize())
    {
        return false;
    }

    auto& xcb          = xcb_loader_.GetFunctionTable();
    int   screen_count = 0;
    connection_        = xcb.connect(nullptr, &screen_count);

    if (xcb.connection_has_error(connection_))
    {
        GFXRECON_LOG_DEBUG("Failed to connect to an X server");
        return false;
    }

    const xcb_setup_t*    setup = xcb.get_setup(connection_);
    xcb_screen_iterator_t iter  = xcb.setup_roots_iterator(setup);

    for (int i = 0; i < screen_count; ++i)
    {
        xcb.screen_next(&iter);
    }

    screen_ = iter.data;

    SetFileProcessor(file_processor);

    return true;
}

bool XcbApplication::RegisterXcbWindow(XcbWindow* window)
{
    bool success = Application::RegisterWindow(window);

    if (success)
    {
        xcb_window_t window_id = window->GetWindowId();

        if (window_id != 0)
        {
            xcb_windows_.insert(std::make_pair(window_id, window));
        }
    }

    return success;
}

bool XcbApplication::UnregisterXcbWindow(XcbWindow* window)
{
    bool success = Application::UnregisterWindow(window);

    if (success)
    {
        xcb_windows_.erase(window->GetWindowId());
    }

    return success;
}

void XcbApplication::ProcessEvents(bool wait_for_input)
{
    while (IsRunning())
    {
        xcb_generic_event_t* event = nullptr;
        const auto&          xcb   = xcb_loader_.GetFunctionTable();

        if (wait_for_input)
        {
            event = xcb.wait_for_event(connection_);

            // Stop waiting after the first event or this function will never exit.
            wait_for_input = false;
        }
        else
        {
            event = xcb.poll_for_event(connection_);
        }

        if (event != nullptr)
        {
            if (event->response_type == 0)
            {
                // Set error status and break from event processing loop.
                auto error           = reinterpret_cast<xcb_generic_error_t*>(event);
                last_error_sequence_ = error->sequence;
                last_error_code_     = error->error_code;
                break;
            }

            uint8_t event_code = event->response_type & 0x7f;
            switch (event_code)
            {
                case XCB_EXPOSE:
                {
                    // A portion of the window needs to be redrawn.
                    // If playback is paused, the window may no longer contain a valid image, but the only way to fix
                    // this would be to re-draw the current frame.
                    break;
                }
                case XCB_CLIENT_MESSAGE:
                {
                    auto message_event = reinterpret_cast<xcb_client_message_event_t*>(event);
                    auto entry         = xcb_windows_.find(message_event->window);

                    if (entry != xcb_windows_.end())
                    {
                        XcbWindow* xcb_window = entry->second;
                        xcb_atom_t atom       = xcb_window->GetDeleteWindowAtom();

                        if (message_event->data.data32[0] == atom)
                        {
                            StopRunning();
                        }
                    }

                    break;
                }
                case XCB_KEY_RELEASE:
                {
                    auto key = reinterpret_cast<xcb_key_release_event_t*>(event);

                    // TODO: This needs something like XkbKeycodeToKeysym
                    switch (key->detail)
                    {
                        case 0x9: // Escape
                            StopRunning();
                            break;
                        case 0x21: // p
                        case 0x41: // Space
                            SetPaused(!GetPaused());
                            break;
                        default:
                            break;
                    }

                    break;
                }
                case XCB_KEY_PRESS:
                {
                    auto key = reinterpret_cast<xcb_key_press_event_t*>(event);

                    // TODO: This needs something like XkbKeycodeToKeysym
                    switch (key->detail)
                    {
                        // Using XCB_KEY_PRESS for repeat when key is held down.
                        case 0x72: // Right arrow
                        case 0x39: // n
                            if (GetPaused())
                            {
                                PlaySingleFrame();
                            }
                            break;
                        default:
                            break;
                    }

                    break;
                }
                case XCB_CONFIGURE_NOTIFY:
                {
                    auto configure_event = reinterpret_cast<xcb_configure_notify_event_t*>(event);
                    auto entry           = xcb_windows_.find(configure_event->window);

                    if (entry != xcb_windows_.end())
                    {
                        XcbWindow* xcb_window = entry->second;
                        xcb_window->ResizeNotifyReceived(
                            configure_event->sequence, configure_event->width, configure_event->height);
                    }

                    break;
                }
                case XCB_MAP_NOTIFY:
                {
                    auto map_event = reinterpret_cast<xcb_map_notify_event_t*>(event);
                    auto entry     = xcb_windows_.find(map_event->window);

                    if (entry != xcb_windows_.end())
                    {
                        XcbWindow* xcb_window = entry->second;
                        xcb_window->MapNotifyReceived(map_event->sequence, true);
                    }

                    break;
                }
                case XCB_UNMAP_NOTIFY:
                {
                    auto unmap_event = reinterpret_cast<xcb_unmap_notify_event_t*>(event);
                    auto entry       = xcb_windows_.find(unmap_event->window);

                    if (entry != xcb_windows_.end())
                    {
                        XcbWindow* xcb_window = entry->second;
                        xcb_window->MapNotifyReceived(unmap_event->sequence, false);
                    }

                    break;
                }
                case XCB_DESTROY_NOTIFY:
                {
                    auto destroy_event = reinterpret_cast<xcb_destroy_notify_event_t*>(event);
                    auto entry         = xcb_windows_.find(destroy_event->window);

                    if (entry != xcb_windows_.end())
                    {
                        XcbWindow* xcb_window = entry->second;
                        xcb_window->DestroyNotifyReceived(destroy_event->sequence);
                    }

                    break;
                }
            }

            free(event);
        }
        else
        {
            break;
        }
    }
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
