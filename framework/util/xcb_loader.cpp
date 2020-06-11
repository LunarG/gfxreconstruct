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

#include "util/xcb_loader.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

XcbLoader::XcbLoader() : libxcb_(nullptr), function_table_{} {}

XcbLoader::~XcbLoader()
{
    if (libxcb_)
    {
        util::platform::CloseLibrary(libxcb_);
        libxcb_ = nullptr;
    }
}

bool XcbLoader::Initialize()
{
    bool success = true;

    // Guard against double initializaiton
    if (!libxcb_)
    {
        libxcb_ = util::platform::OpenLibrary("libxcb.so");
        if (libxcb_)
        {
            function_table_.change_property = reinterpret_cast<decltype(xcb_change_property)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_change_property"));
            function_table_.configure_window = reinterpret_cast<decltype(xcb_configure_window)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_configure_window"));
            function_table_.connect =
                reinterpret_cast<decltype(xcb_connect)*>(util::platform::GetProcAddress(libxcb_, "xcb_connect"));
            function_table_.connection_has_error = reinterpret_cast<decltype(xcb_connection_has_error)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_connection_has_error"));
            function_table_.create_window_checked = reinterpret_cast<decltype(xcb_create_window_checked)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_create_window_checked"));
            function_table_.destroy_window = reinterpret_cast<decltype(xcb_destroy_window)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_destroy_window"));
            function_table_.disconnect =
                reinterpret_cast<decltype(xcb_disconnect)*>(util::platform::GetProcAddress(libxcb_, "xcb_disconnect"));
            function_table_.flush =
                reinterpret_cast<decltype(xcb_flush)*>(util::platform::GetProcAddress(libxcb_, "xcb_flush"));
            function_table_.generate_id =
                reinterpret_cast<decltype(xcb_generate_id)*>(util::platform::GetProcAddress(libxcb_, "xcb_generate_id"));
            function_table_.get_geometry =
                reinterpret_cast<decltype(xcb_get_geometry)*>(util::platform::GetProcAddress(libxcb_, "xcb_get_geometry"));
            function_table_.get_geometry_reply = reinterpret_cast<decltype(xcb_get_geometry_reply)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_get_geometry_reply"));
            function_table_.get_setup =
                reinterpret_cast<decltype(xcb_get_setup)*>(util::platform::GetProcAddress(libxcb_, "xcb_get_setup"));
            function_table_.intern_atom =
                reinterpret_cast<decltype(xcb_intern_atom)*>(util::platform::GetProcAddress(libxcb_, "xcb_intern_atom"));
            function_table_.intern_atom_reply = reinterpret_cast<decltype(xcb_intern_atom_reply)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_intern_atom_reply"));
            function_table_.map_window =
                reinterpret_cast<decltype(xcb_map_window)*>(util::platform::GetProcAddress(libxcb_, "xcb_map_window"));
            function_table_.poll_for_event = reinterpret_cast<decltype(xcb_poll_for_event)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_poll_for_event"));
            function_table_.request_check = reinterpret_cast<decltype(xcb_request_check)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_request_check"));
            function_table_.screen_next =
                reinterpret_cast<decltype(xcb_screen_next)*>(util::platform::GetProcAddress(libxcb_, "xcb_screen_next"));
            function_table_.send_event =
                reinterpret_cast<decltype(xcb_send_event)*>(util::platform::GetProcAddress(libxcb_, "xcb_send_event"));
            function_table_.setup_roots_iterator = reinterpret_cast<decltype(xcb_setup_roots_iterator)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_setup_roots_iterator"));
            function_table_.unmap_window =
                reinterpret_cast<decltype(xcb_unmap_window)*>(util::platform::GetProcAddress(libxcb_, "xcb_unmap_window"));
            function_table_.wait_for_event = reinterpret_cast<decltype(xcb_wait_for_event)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_wait_for_event"));
        }
        else
        {
            GFXRECON_LOG_DEBUG("Failed to load libxcb.so");
            success = false;
        }
    }

    return success;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
