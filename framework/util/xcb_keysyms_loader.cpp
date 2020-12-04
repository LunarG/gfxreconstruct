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

#include "util/xcb_keysyms_loader.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

const std::vector<std::string> kXcbKeysymsLibNames = {
#if defined(XCB_KEYSYMS_LIBRARY)
    XCB_KEYSYMS_LIBRARY,
#endif
    "libxcb-keysyms.so.1",
    "libxcb-keysyms.so"
};

XcbKeysymsLoader::XcbKeysymsLoader() : libxcbkeysyms_(nullptr), function_table_{} {}

XcbKeysymsLoader::~XcbKeysymsLoader()
{
    if (libxcbkeysyms_)
    {
        util::platform::CloseLibrary(libxcbkeysyms_);
        libxcbkeysyms_ = nullptr;
    }
}

bool XcbKeysymsLoader::Initialize()
{
    bool success = true;

    // Guard against double initializaiton
    if (!libxcbkeysyms_)
    {
        libxcbkeysyms_ = util::platform::OpenLibrary(kXcbKeysymsLibNames);
        if (libxcbkeysyms_)
        {
            function_table_.key_symbols_alloc = reinterpret_cast<decltype(xcb_key_symbols_alloc)*>(
                util::platform::GetProcAddress(libxcbkeysyms_, "xcb_key_symbols_alloc"));
            function_table_.key_symbols_get_keycode = reinterpret_cast<decltype(xcb_key_symbols_get_keycode)*>(
                util::platform::GetProcAddress(libxcbkeysyms_, "xcb_key_symbols_get_keycode"));
            function_table_.query_keymap = reinterpret_cast<decltype(xcb_query_keymap)*>(
                util::platform::GetProcAddress(libxcbkeysyms_, "xcb_query_keymap"));
            function_table_.query_keymap_reply = reinterpret_cast<decltype(xcb_query_keymap_reply)*>(
                util::platform::GetProcAddress(libxcbkeysyms_, "xcb_query_keymap_reply"));
            function_table_.key_symbols_free = reinterpret_cast<decltype(xcb_key_symbols_free)*>(
                util::platform::GetProcAddress(libxcbkeysyms_, "xcb_key_symbols_free"));
        }
        else
        {
            GFXRECON_LOG_DEBUG("Failed to load libxcb-keysyms.so");
            success = false;
        }
    }

    return success;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
