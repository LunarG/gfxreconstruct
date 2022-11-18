/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "application/xcb_context.h"
#include "application/application.h"
#include "application/xcb_window.h"
#include "util/logging.h"

#include <cstdlib>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

XcbContext::XcbContext(Application* application) : WsiContext(application)
{
    xcb_loader_.Initialize();
    if (!xcb_loader_.Initialize())
    {
        GFXRECON_LOG_DEBUG("Failed to initialize XCB loader");
        return;
    }

    auto& xcb          = xcb_loader_.GetFunctionTable();
    int   screen_count = 0;
    connection_        = xcb.connect(nullptr, &screen_count);

    if (xcb.connection_has_error(connection_))
    {
        GFXRECON_LOG_DEBUG("Failed to connect to an X server");
        return;
    }

    const xcb_setup_t*    setup = xcb.get_setup(connection_);
    xcb_screen_iterator_t iter  = xcb.setup_roots_iterator(setup);

    for (int i = 0; i < screen_count; ++i)
    {
        xcb.screen_next(&iter);
    }

    screen_         = iter.data;
    window_factory_ = std::make_unique<XcbWindowFactory>(this);
}

XcbContext::~XcbContext()
{
    if (connection_ != nullptr)
    {
        auto& xcb = xcb_loader_.GetFunctionTable();
        xcb.disconnect(connection_);
    }
}

bool XcbContext::RegisterXcbWindow(XcbWindow* window)
{
    bool success = WsiContext::RegisterWindow(window);

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

bool XcbContext::UnregisterXcbWindow(XcbWindow* window)
{
    bool success = WsiContext::UnregisterWindow(window);

    if (success)
    {
        xcb_windows_.erase(window->GetWindowId());
    }

    return success;
}

void XcbContext::ProcessEvents(bool wait_for_input)
{
    assert(application_);
    while (application_->IsRunning())
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
                            application_->StopRunning();
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
                            application_->StopRunning();
                            break;
                        case 0x21: // p
                        case 0x41: // Space
                            application_->SetPaused(!application_->GetPaused());
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
                            if (application_->GetPaused())
                            {
                                application_->PlaySingleFrame();
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
