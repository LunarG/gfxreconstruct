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

#ifndef GFXRECON_UTIL_XCB_LOADER_H
#define GFXRECON_UTIL_XCB_LOADER_H

#include "util/defines.h"
#include "util/platform.h"

#include <xcb/xcb.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class XcbLoader
{
  public:
    struct FunctionTable
    {
        decltype(xcb_change_property)*       change_property;
        decltype(xcb_configure_window)*      configure_window;
        decltype(xcb_connect)*               connect;
        decltype(xcb_connection_has_error)*  connection_has_error;
        decltype(xcb_create_window_checked)* create_window_checked;
        decltype(xcb_destroy_window)*        destroy_window;
        decltype(xcb_disconnect)*            disconnect;
        decltype(xcb_flush)*                 flush;
        decltype(xcb_generate_id)*           generate_id;
        decltype(xcb_get_geometry)*          get_geometry;
        decltype(xcb_get_geometry_reply)*    get_geometry_reply;
        decltype(xcb_get_setup)*             get_setup;
        decltype(xcb_intern_atom)*           intern_atom;
        decltype(xcb_intern_atom_reply)*     intern_atom_reply;
        decltype(xcb_map_window)*            map_window;
        decltype(xcb_poll_for_event)*        poll_for_event;
        decltype(xcb_request_check)*         request_check;
        decltype(xcb_screen_next)*           screen_next;
        decltype(xcb_send_event)*            send_event;
        decltype(xcb_setup_roots_iterator)*  setup_roots_iterator;
        decltype(xcb_unmap_window)*          unmap_window;
        decltype(xcb_wait_for_event)*        wait_for_event;
    };

  public:
    XcbLoader();

    ~XcbLoader();

    bool Initialize();

    const FunctionTable& GetFunctionTable() const { return function_table_; }

  private:
    util::platform::LibraryHandle libxcb_;
    FunctionTable                 function_table_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_XCB_LOADER_H
