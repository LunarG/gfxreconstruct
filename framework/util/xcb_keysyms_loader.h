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

#ifndef GFXRECON_UTIL_XCB_KEYSYMS_LOADER_H
#define GFXRECON_UTIL_XCB_KEYSYMS_LOADER_H

#include "util/defines.h"
#include "util/platform.h"

#include <xcb/xcb_keysyms.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class XcbKeysymsLoader
{
  public:
    struct FunctionTable
    {
        decltype(xcb_key_symbols_alloc)*       key_symbols_alloc;
        decltype(xcb_key_symbols_get_keycode)* key_symbols_get_keycode;
        decltype(xcb_query_keymap)*            query_keymap;
        decltype(xcb_query_keymap_reply)*      query_keymap_reply;
        decltype(xcb_key_symbols_free)*        key_symbols_free;
    };

  public:
    XcbKeysymsLoader();

    ~XcbKeysymsLoader();

    bool Initialize();

    const FunctionTable& GetFunctionTable() const { return function_table_; }

  private:
    util::platform::LibraryHandle libxcbkeysyms_;
    FunctionTable                 function_table_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_XCB_KEYSYMS_LOADER_H
