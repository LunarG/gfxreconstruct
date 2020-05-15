
/*
** Copyright (c) 2020 Valve Corporation
** Copyright (c) 2020 LunarG, Inc.
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

#include "util/keyboard.h"

#include "util/logging.h"
#include "util/platform.h"

#if defined(VK_USE_PLATFORM_XCB_KHR)
#include <X11/keysym.h>
#if defined(VK_USE_PLATFORM_XLIB_KHR)
#include <X11/Xlib-xcb.h>
#endif
#endif

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#if defined(VK_USE_PLATFORM_XCB_KHR)
bool Keyboard::Initialize(xcb_connection_t* connection)
{
    if (xcb_keysyms_loader_.Initialize())
    {
        xcb_connection_ = connection;
        return true;
    }
    return false;
}
#endif

#if defined(VK_USE_PLATFORM_XLIB_KHR)
bool Keyboard::Initialize(Display* display)
{
#if defined(VK_USE_PLATFORM_XCB_KHR)
    // TODO: Native Xlib support
    auto xlib_xcb = util::platform::OpenLibrary("libX11-xcb.so");
    if (xlib_xcb)
    {
        // Convert X display to XCB connection
        auto x_get_xcb_connection = reinterpret_cast<decltype(XGetXCBConnection)*>(
            util::platform::GetProcAddress(xlib_xcb, "XGetXCBConnection"));
        auto xcb_connection = x_get_xcb_connection(display);
        util::platform::CloseLibrary(xlib_xcb);

        // Initialize using XCB keyboard implementation
        return Initialize(xcb_connection);
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(display);
    GFXRECON_LOG_WARNING("Xlib-XCB interop is not enabled on this system");
#endif
    return false;
}
#endif

bool Keyboard::GetKeyState(const std::string& key)
{
    bool result = false;

#if defined(VK_USE_PLATFORM_WIN32_KHR)
    static const std::unordered_map<std::string, int> win32_key_code_map = { { "F1", VK_F1 },
                                                                             { "F2", VK_F2 },
                                                                             { "F3", VK_F3 },
                                                                             { "F4", VK_F4 },
                                                                             { "F5", VK_F5 },
                                                                             { "F6", VK_F6 },
                                                                             { "F7", VK_F7 },
                                                                             { "F8", VK_F8 },
                                                                             { "F9", VK_F9 },
                                                                             { "F10", VK_F10 },
                                                                             { "F11", VK_F11 },
                                                                             { "F12", VK_F12 },
                                                                             { "TAB", VK_TAB },
                                                                             { "ControlLeft", VK_LCONTROL },
                                                                             { "ControlRight", VK_RCONTROL } };

    auto iterator_key_code = win32_key_code_map.find(key);
    if (iterator_key_code != win32_key_code_map.end())
    {
        result |= (GetAsyncKeyState(iterator_key_code->second) != 0);
    }
#endif

#if defined(VK_USE_PLATFORM_XCB_KHR)
    static const std::unordered_map<std::string, int> xcb_key_code_map = { { "F1", XK_F1 },
                                                                           { "F2", XK_F2 },
                                                                           { "F3", XK_F3 },
                                                                           { "F4", XK_F4 },
                                                                           { "F5", XK_F5 },
                                                                           { "F6", XK_F6 },
                                                                           { "F7", XK_F7 },
                                                                           { "F8", XK_F8 },
                                                                           { "F9", XK_F9 },
                                                                           { "F10", XK_F10 },
                                                                           { "F11", XK_F11 },
                                                                           { "F12", XK_F12 },
                                                                           { "Tab", XK_Tab },
                                                                           { "ControlLeft", XK_Control_L },
                                                                           { "ControlRight", XK_Control_R } };
    if (xcb_connection_)
    {
        auto& xcb_keysyms       = xcb_keysyms_loader_.GetFunctionTable();
        auto  iterator_key_code = xcb_key_code_map.find(key);
        if (iterator_key_code != xcb_key_code_map.end())
        {
            int                key_state      = 0;
            xcb_key_symbols_t* hot_key_symbol = xcb_keysyms.key_symbols_alloc(xcb_connection_);
            if (hot_key_symbol != nullptr)
            {
                xcb_keycode_t* xcb_key_code =
                    xcb_keysyms.key_symbols_get_keycode(hot_key_symbol, iterator_key_code->second);
                if (xcb_key_code != nullptr)
                {
                    xcb_query_keymap_cookie_t cookie = xcb_keysyms.query_keymap(xcb_connection_);
                    xcb_query_keymap_reply_t* keys_bit_map =
                        xcb_keysyms.query_keymap_reply(xcb_connection_, cookie, NULL);
                    if ((keys_bit_map->keys[(*xcb_key_code / 8)] & (1 << (*xcb_key_code % 8))) != 0)
                    {
                        result = true;
                    }
                    free(keys_bit_map);
                    free(xcb_key_code);
                }
                xcb_keysyms.key_symbols_free(hot_key_symbol);
            }
        }
    }
#endif

    return result;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
