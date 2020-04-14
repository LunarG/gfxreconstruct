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

#include "util/xcb_keysyms_loader.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

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
        libxcbkeysyms_ = util::platform::OpenLibrary("libxcb-keysyms.so");
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
