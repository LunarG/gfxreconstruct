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

#include "util/xcb_window.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

XcbWindow::XcbWindow(XcbApplication* application) : Window(application)
{
    xcb_application_ = application;
}

bool XcbWindow::Create(const uint32_t width, const uint32_t height)
{
    width_ = width;
    height_ = height;

    uint32_t value_mask, value_list[32];
    window_ = xcb_generate_id(xcb_application_->connection);

    value_mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    value_list[0] = xcb_application_->screen->black_pixel;
    value_list[1] = XCB_EVENT_MASK_KEY_RELEASE | XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_STRUCTURE_NOTIFY;

    xcb_create_window(xcb_application_->connection, XCB_COPY_FROM_PARENT, window_, xcb_application_->screen->root, 0, 0, width, height, 0,
                      XCB_WINDOW_CLASS_INPUT_OUTPUT, xcb_application_->screen->root_visual, value_mask, value_list);

    // Magic code that will send notification when window is destroyed
    xcb_intern_atom_cookie_t cookie = xcb_intern_atom(xcb_application_->connection, 1, 12, "WM_PROTOCOLS");
    xcb_intern_atom_reply_t *reply = xcb_intern_atom_reply(xcb_application_->connection, cookie, 0);

    xcb_intern_atom_cookie_t cookie2 = xcb_intern_atom(xcb_application_->connection, 0, 16, "WM_DELETE_WINDOW");
    atom_wm_delete_window = xcb_intern_atom_reply(xcb_application_->connection, cookie2, 0);

    xcb_change_property(xcb_application_->connection, XCB_PROP_MODE_REPLACE, window_, (*reply).atom, 4, 32, 1,
                        &(*atom_wm_delete_window).atom);
    free(reply);

    // Make sure window is visible.
    xcb_map_window(xcb_application_->connection, window_);
    xcb_flush(xcb_application_->connection);

    return true;
}

bool XcbWindow::Destroy()
{
    if (window_ != 0) {
        xcb_destroy_window(xcb_application_->connection, window_);
    }
    return true;
}

void XcbWindow::SetPosition(const uint32_t x, const uint32_t y)
{
}

void XcbWindow::SetSize(const uint32_t width, const uint32_t height)
{
    if (width != width_ || height != height_) {
        width_ = width;
        height_ = height;
        uint32_t values[2];
        values[0] = width;
        values[1] = height;
        xcb_configure_window(xcb_application_->connection, window_, XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT, values);
        xcb_flush(xcb_application_->connection);

        // Make sure window is visible.
        xcb_map_window(xcb_application_->connection, window_);
        xcb_flush(xcb_application_->connection);
    }
}

void XcbWindow::SetVisibility(bool show)
{
    // TODO
}

void XcbWindow::SetFocus()
{
    // TODO
}

bool XcbWindow::GetNativeHandle(uint32_t id, void ** handle)
{
    switch (id) {
        case XcbWindow::kConnection:
            *handle = reinterpret_cast<void*>(xcb_application_->connection);
            return true;
        case XcbWindow::kWindow:
            *handle = reinterpret_cast<void*>(window_);
            return true;
        default:
            return false;
    }
}

XcbWindowFactory::XcbWindowFactory(XcbApplication* application) : WindowFactory(application)
{
    xcb_application_ = application;
}

Window* XcbWindowFactory::Create(const uint32_t width, const uint32_t height)
{
    auto window = new XcbWindow(xcb_application_);
    window->Create(width, height);
    return window;
}

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)
