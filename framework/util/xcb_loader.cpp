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

#include "util/xcb_loader.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

const std::vector<std::string> kXcbLibNames = {
#if defined(XCB_LIBRARY)
    XCB_LIBRARY,
#endif
    "libxcb.so.1",
    "libxcb.so"
};

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
        libxcb_ = util::platform::OpenLibrary(kXcbLibNames);
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
            function_table_.generate_id = reinterpret_cast<decltype(xcb_generate_id)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_generate_id"));
            function_table_.get_geometry = reinterpret_cast<decltype(xcb_get_geometry)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_get_geometry"));
            function_table_.get_geometry_reply = reinterpret_cast<decltype(xcb_get_geometry_reply)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_get_geometry_reply"));
            function_table_.get_setup =
                reinterpret_cast<decltype(xcb_get_setup)*>(util::platform::GetProcAddress(libxcb_, "xcb_get_setup"));
            function_table_.intern_atom = reinterpret_cast<decltype(xcb_intern_atom)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_intern_atom"));
            function_table_.intern_atom_reply = reinterpret_cast<decltype(xcb_intern_atom_reply)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_intern_atom_reply"));
            function_table_.map_window =
                reinterpret_cast<decltype(xcb_map_window)*>(util::platform::GetProcAddress(libxcb_, "xcb_map_window"));
            function_table_.poll_for_event = reinterpret_cast<decltype(xcb_poll_for_event)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_poll_for_event"));
            function_table_.request_check = reinterpret_cast<decltype(xcb_request_check)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_request_check"));
            function_table_.screen_next = reinterpret_cast<decltype(xcb_screen_next)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_screen_next"));
            function_table_.send_event =
                reinterpret_cast<decltype(xcb_send_event)*>(util::platform::GetProcAddress(libxcb_, "xcb_send_event"));
            function_table_.setup_roots_iterator = reinterpret_cast<decltype(xcb_setup_roots_iterator)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_setup_roots_iterator"));
            function_table_.unmap_window = reinterpret_cast<decltype(xcb_unmap_window)*>(
                util::platform::GetProcAddress(libxcb_, "xcb_unmap_window"));
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
