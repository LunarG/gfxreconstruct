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

#include "util/xcb_application.h"
#include "util/xcb_window.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

XcbApplication::XcbApplication()
{
    const xcb_setup_t *setup;    
    int scr;
    connection = xcb_connect(NULL, &scr);
    xcb_screen_iterator_t iter;
    setup = xcb_get_setup(connection);
    iter = xcb_setup_roots_iterator(setup);
    while (scr-- > 0) xcb_screen_next(&iter);
    screen = iter.data;
}

void XcbApplication::ProcessEvents(bool wait_for_input)
{
    xcb_generic_event_t *event = xcb_poll_for_event(connection);
    xcb_flush(connection);
    uint8_t event_code = 0;

    while (event)
    {
        event_code = event->response_type & 0x7f;
        switch (event_code)
        {
            case XCB_EXPOSE:
                // TODO: Resize window
                break;
            case XCB_CLIENT_MESSAGE:
                for (auto window : windows)
                {
                    auto xcb_window = dynamic_cast<XcbWindow*>(window);
                    if (xcb_window && (*(xcb_client_message_event_t *)event).data.data32[0] == (*xcb_window->atom_wm_delete_window).atom)
                    {
                        window->Destroy();
                    }
                }
                break;
            case XCB_KEY_RELEASE:
            {
                const xcb_key_release_event_t *key = (const xcb_key_release_event_t *)event;

                switch (key->detail)
                {
                    case 0x9:  // Escape
                        // Close all windows for now
                        for (auto window : windows)
                        {
                            window->Destroy();
                        }
                        break;
                    case 0x41:  // Space
                        SetPaused(!GetPaused());
                        break;
                }
            } break;
            case XCB_CONFIGURE_NOTIFY:
            {
                xcb_configure_notify_event_t *cne = (xcb_configure_notify_event_t *)event;
                // Our window has been resized, probably by the window manager.
                // TODO
            } break;
            case XCB_MAP_NOTIFY:
            {
                // If we were waiting for a MapWindow request to be processed,
                // we can now continue
                // TODO
            } break;
        }
        free(event);
        event = xcb_poll_for_event(connection);
    }
}

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)
