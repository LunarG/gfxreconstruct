/*
** Copyright (c) 2020 Valve Corporation
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_KEYBOARD_H
#define GFXRECON_UTIL_KEYBOARD_H

#include "util/defines.h"

#if defined(VK_USE_PLATFORM_XCB_KHR)
#include "util/xcb_keysyms_loader.h"
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
#include "X11/Xlib.h"
#endif

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class Keyboard
{
  public:
#if defined(VK_USE_PLATFORM_XCB_KHR)
    bool Initialize(xcb_connection_t* connection);
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    bool Initialize(Display* display);
#endif
    bool GetKeyState(const std::string& key);

    Keyboard()
    {
#if defined(VK_USE_PLATFORM_XCB_KHR)
        xcb_connection_ = nullptr;
#endif
    }

  private:
#if defined(VK_USE_PLATFORM_XCB_KHR)
    xcb_connection_t* xcb_connection_;
    XcbKeysymsLoader  xcb_keysyms_loader_;
#endif
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_KEYBOARD_H
