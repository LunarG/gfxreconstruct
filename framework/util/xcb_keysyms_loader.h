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
