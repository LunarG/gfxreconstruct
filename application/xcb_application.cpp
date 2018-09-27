/*
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

#include <cstdlib>

#include "application/xcb_application.h"
#include "application/xcb_window.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

XcbApplication::XcbApplication()
{
    int screen_count = 0;
    connection_ = xcb_connect(nullptr, &screen_count);

    const xcb_setup_t*    setup = xcb_get_setup(connection_);
    xcb_screen_iterator_t iter  = xcb_setup_roots_iterator(setup);

    for (int i = 0; i < screen_count; ++i)
    {
        xcb_screen_next(&iter);
    }

    screen_ = iter.data;
}

XcbApplication::~XcbApplication()
{
    if (connection_ != nullptr)
    {
        xcb_disconnect(connection_);
    }
}

void XcbApplication::ProcessEvents(bool wait_for_input)
{
    while (IsRunning())
    {
        xcb_generic_event_t* event = nullptr;

        if (wait_for_input)
        {
            event = xcb_wait_for_event(connection_);
        }
        else
        {
            event = xcb_poll_for_event(connection_);        
        }

        if (event != nullptr)
        {
            uint8_t event_code = event->response_type & 0x7f;
            switch (event_code)
            {
                case XCB_EXPOSE:
                {
                    // A portion of the window needs to be redrawn.
                    // If playback is paused, the window may no longer contain a valid image, but the only way to fix this
                    // would be to re-draw the current frame.
                    break;
                }
                case XCB_CLIENT_MESSAGE:
                {
                    xcb_client_message_event_t* message_event = reinterpret_cast<xcb_client_message_event_t*>(event);
                    for (auto window : windows_)
                    {
                        XcbWindow* xcb_window = dynamic_cast<XcbWindow*>(window);
                        if (xcb_window != nullptr)
                        {
                            xcb_intern_atom_reply_t* atom = xcb_window->GetDeleteWindowAtom();

                            if ((atom != nullptr) && (message_event->data.data32[0] == atom->atom))
                            {
                                StopRunning();
                            }
                        }
                    }

                    break;
                }
                case XCB_KEY_RELEASE:
                {
                    const xcb_key_release_event_t *key = (const xcb_key_release_event_t *)event;

                    switch (key->detail)
                    {
                        case 0x9:  // Escape
                            StopRunning();
                            break;
                        case 0x41:  // Space
                            SetPaused(!GetPaused());
                            break;
                    }
    
                    break;
                }
                case XCB_CONFIGURE_NOTIFY:
                {
                    xcb_configure_notify_event_t *cne = reinterpret_cast<xcb_configure_notify_event_t*>(event);
                    // Our window has been resized, probably by the window manager.
                    // TODO
                    break;
                }
                case XCB_MAP_NOTIFY:
                {
                    // If we were waiting for a MapWindow request to be processed,
                    // we can now continue
                    // TODO
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

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)
