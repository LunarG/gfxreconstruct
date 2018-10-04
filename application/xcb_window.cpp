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
#include <cassert>
#include <cstdlib>
#include <limits>

#include "volk.h"

#include "util/logging.h"
#include "application/xcb_window.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

XcbWindow::XcbWindow(XcbApplication* application) :
    xcb_application_(application), width_(0), height_(0), screen_width_(std::numeric_limits<uint32_t>::max()),
    screen_height_(std::numeric_limits<uint32_t>::max()), fullscreen_(false), window_(0),
    atom_wm_delete_window_(nullptr)
{
    assert(application != nullptr);
}

XcbWindow::~XcbWindow()
{
    if (window_ != 0)
    {
        xcb_destroy_window(xcb_application_->GetConnection(), window_);
    }

    if (atom_wm_delete_window_ != nullptr)
    {
        free(atom_wm_delete_window_);
    }
}

bool XcbWindow::Create(
    const std::string& title, const int32_t xpos, const int32_t ypos, const uint32_t width, const uint32_t height)
{
    xcb_connection_t* connection = xcb_application_->GetConnection();
    xcb_screen_t*     screen     = xcb_application_->GetScreen();

    window_ = xcb_generate_id(connection);
    if (window_ == 0)
    {
        BRIMSTONE_LOG_ERROR("Failed to generate window ID");
        return false;
    }

    xcb_application_->RegisterXcbWindow(this);

    // Get screen dimensions.
    xcb_generic_error_t*      error       = nullptr;
    xcb_get_geometry_cookie_t geom_cookie = xcb_get_geometry(connection, screen->root);
    xcb_get_geometry_reply_t* geom        = xcb_get_geometry_reply(connection, geom_cookie, &error);

    if (geom != nullptr)
    {
        screen_width_  = geom->width;
        screen_height_ = geom->height;
        free(geom);
    }
    else
    {
        BRIMSTONE_LOG_WARNING("Failed to retrieve screen geometry with error code %u", error->error_code);
    }

    // Determine if fullscreen mode is required.
    int32_t  x            = xpos;
    int32_t  y            = ypos;
    bool go_fullscreen    = false;

    if ((screen_height_ <= height) || (screen_width_ <= width))
    {
        if ((screen_height_ < height) || (screen_width_ < width))
        {
            BRIMSTONE_LOG_WARNING(
                "Requested window size (%ux%u) exceeds current screen size (%ux%u); replay may fail due to "
                "inability to create a window of the appropriate size.",
                width,
                height,
                screen_width_,
                screen_height_);
        }

        go_fullscreen = true;

        // Place fullscreen window at 0, 0.
        x = 0;
        y = 0;
    }

    uint32_t value_mask   = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    uint32_t value_list[] = { screen->black_pixel,
                              XCB_EVENT_MASK_KEY_RELEASE | XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_STRUCTURE_NOTIFY };

    xcb_void_cookie_t check_cookie = xcb_create_window_checked(connection,
                                                               XCB_COPY_FROM_PARENT,
                                                               window_,
                                                               screen->root,
                                                               static_cast<int16_t>(x),
                                                               static_cast<int16_t>(y),
                                                               static_cast<uint16_t>(width),
                                                               static_cast<uint16_t>(height),
                                                               0,
                                                               XCB_WINDOW_CLASS_INPUT_OUTPUT,
                                                               screen->root_visual,
                                                               value_mask,
                                                               value_list);

    error = xcb_request_check(connection, check_cookie);
    if (error != nullptr)
    {
        BRIMSTONE_LOG_ERROR("Failed to create window with error %u", error->error_code);
        window_ = 0;
        return false;
    }

    // Set the title.
    xcb_change_property(connection,
                        XCB_PROP_MODE_REPLACE,
                        window_,
                        XCB_ATOM_WM_NAME,
                        XCB_ATOM_STRING,
                        8,
                        static_cast<uint32_t>(title.length()),
                        title.c_str());

    // Request notification when user tries to close the window.
    xcb_intern_atom_cookie_t proto_cookie = xcb_intern_atom(connection, 1, 12, "WM_PROTOCOLS");
    xcb_intern_atom_reply_t* reply        = xcb_intern_atom_reply(connection, proto_cookie, &error);

    if (reply != nullptr)
    {
        xcb_intern_atom_cookie_t delete_cookie = xcb_intern_atom(connection, 0, 16, "WM_DELETE_WINDOW");
        atom_wm_delete_window_                 = xcb_intern_atom_reply(connection, delete_cookie, &error);

        if (atom_wm_delete_window_ != nullptr)
        {
            xcb_change_property(
                connection, XCB_PROP_MODE_REPLACE, window_, reply->atom, 4, 32, 1, &(atom_wm_delete_window_->atom));
        }

        free(reply);
    }

    if (atom_wm_delete_window_ == nullptr)
    {
        BRIMSTONE_LOG_ERROR("Failed to change window property with error %u", error->error_code);
        return false;
    }

    // Display the window.
    check_cookie = xcb_map_window_checked(connection, window_);

    error = xcb_request_check(connection, check_cookie);
    if (error != nullptr)
    {
        BRIMSTONE_LOG_ERROR("Failed to map window with error %u", error->error_code);
        return false;
    }

    // Enable fullscreen if necessary.
    if (go_fullscreen)
    {
        SetFullscreen(true);
    }

    width_  = width;
    height_ = height;

    return true;
}

bool XcbWindow::Destroy()
{
    if (window_ != 0)
    {
        xcb_destroy_window(xcb_application_->GetConnection(), window_);
        xcb_application_->UnregisterXcbWindow(this);
        window_ = 0;

        if (atom_wm_delete_window_ != nullptr)
        {
            free(atom_wm_delete_window_);
            atom_wm_delete_window_ = nullptr;
        }

        return true;
    }

    return false;
}

void XcbWindow::SetTitle(const std::string& title)
{
    xcb_connection_t* connection = xcb_application_->GetConnection();

    xcb_change_property(connection,
                        XCB_PROP_MODE_REPLACE,
                        window_,
                        XCB_ATOM_WM_NAME,
                        XCB_ATOM_STRING,
                        8,
                        static_cast<uint32_t>(title.length()),
                        title.c_str());
    xcb_flush(connection);
}

void XcbWindow::SetPosition(const int32_t x, const int32_t y)
{
    xcb_connection_t* connection = xcb_application_->GetConnection();
    uint32_t          values[]   = { static_cast<uint32_t>(x), static_cast<uint32_t>(y) };

    xcb_configure_window(connection, window_, XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y, values);
    xcb_flush(connection);
}

void XcbWindow::SetSize(const uint32_t width, const uint32_t height)
{
    if ((width != width_) || (height != height_))
    {
        width_  = width;
        height_ = height;

        if ((screen_width_ <= width) || (screen_height_ <= height))
        {
            if ((screen_height_ < height) || (screen_width_ < width))
            {
                BRIMSTONE_LOG_WARNING(
                    "Requested window size (%ux%u) exceeds current screen size (%ux%u); replay may fail due to "
                    "inability to create a window of the appropriate size.",
                    width,
                    height,
                    screen_width_,
                    screen_height_);
            }

            SetPosition(0, 0);
            SetFullscreen(true);
        }
        else
        {
            SetFullscreen(false);
        }

        xcb_connection_t* connection = xcb_application_->GetConnection();
        uint32_t          values[]   = { width, height };
        xcb_void_cookie_t cookie     = xcb_configure_window_checked(
            connection, window_, XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT, values);

        xcb_generic_error_t* error = xcb_request_check(connection, cookie);
        if (error != nullptr)
        {
            BRIMSTONE_LOG_ERROR("Failed to resize window with error %u", error->error_code);
        }
    }
}

void XcbWindow::SetFullscreen(bool fullscreen)
{
    if (fullscreen != fullscreen_)
    {
        xcb_connection_t* connection = xcb_application_->GetConnection();

        xcb_generic_error_t*     error        = nullptr;
        xcb_intern_atom_cookie_t state_cookie = xcb_intern_atom(connection, 1, 13, "_NET_WM_STATE");
        xcb_intern_atom_reply_t* state_reply  = xcb_intern_atom_reply(connection, state_cookie, &error);

        if (state_reply != nullptr)
        {
            xcb_intern_atom_cookie_t fullscreen_cookie = xcb_intern_atom(connection, 0, 24, "_NET_WM_STATE_FULLSCREEN");
            xcb_intern_atom_reply_t* fullscreen_reply  = xcb_intern_atom_reply(connection, fullscreen_cookie, &error);

            if (fullscreen_reply != nullptr)
            {
                xcb_client_message_event_t event;
                event.response_type = XCB_CLIENT_MESSAGE;
                event.format = 32;
                event.sequence = 0;
                event.window = window_;
                event.type = state_reply->atom;
                event.data.data32[0] = fullscreen ? 1 : 0;
                event.data.data32[1] = fullscreen_reply->atom;
                event.data.data32[2] = 0;
                event.data.data32[3] = 0;
                event.data.data32[4] = 0;

                xcb_void_cookie_t event_cookie =
                    xcb_send_event_checked(connection,
                                           0,
                                           xcb_application_->GetScreen()->root,
                                           XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT,
                                           reinterpret_cast<const char*>(&event));

                error = xcb_request_check(connection, event_cookie);

                free(fullscreen_reply);
            }

            free(state_reply);
        }

        if (error == nullptr)
        {
            fullscreen_ = fullscreen;
        }
        else
        {
            BRIMSTONE_LOG_ERROR("Failed to toggle fullscreen mode with error %u", error->error_code);
        }
    }
}

void XcbWindow::SetVisibility(bool show)
{
    xcb_connection_t* connection = xcb_application_->GetConnection();
    xcb_void_cookie_t cookie;

    if (show)
    {
        cookie = xcb_map_window_checked(connection, window_);
    }
    else
    {
        cookie = xcb_unmap_window_checked(connection, window_);
    }

    xcb_generic_error_t* error = xcb_request_check(connection, cookie);
    if (error != nullptr)
    {
        BRIMSTONE_LOG_ERROR("Failed to change window visibility with error %u", error->error_code);
    }
}

void XcbWindow::SetForeground()
{
    xcb_connection_t* connection = xcb_application_->GetConnection();
    uint32_t          values[]   = { XCB_STACK_MODE_ABOVE };

    xcb_configure_window(connection, window_, XCB_CONFIG_WINDOW_STACK_MODE, values);
    xcb_flush(connection);
}

bool XcbWindow::GetNativeHandle(uint32_t id, void** handle)
{
    assert(handle != nullptr);
    switch (id)
    {
        case XcbWindow::kConnection:
            *handle = reinterpret_cast<void*>(xcb_application_->GetConnection());
            return true;
        case XcbWindow::kWindow:
            *handle = reinterpret_cast<void*>(window_);
            return true;
        default:
            return false;
    }
}

VkResult XcbWindow::CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* pSurface)
{
    VkXcbSurfaceCreateInfoKHR create_info{
        VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR, nullptr, flags, xcb_application_->GetConnection(), window_
    };

    return vkCreateXcbSurfaceKHR(instance, &create_info, nullptr, pSurface);
}

XcbWindowFactory::XcbWindowFactory(XcbApplication* application) : xcb_application_(application)
{
    assert(application != nullptr);
}

format::Window* XcbWindowFactory::Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height)
{
    auto window = new XcbWindow(xcb_application_);
    window->Create(xcb_application_->GetName(), x, y, width, height);
    return window;
}

VkBool32 XcbWindowFactory::GetPhysicalDevicePresentationSupport(VkPhysicalDevice physical_device,
                                                                uint32_t         queue_family_index)
{
    xcb_connection_t* connection = xcb_application_->GetConnection();
    xcb_screen_t*     screen     = xcb_application_->GetScreen();

    assert((connection != nullptr) && (screen != nullptr));

    return vkGetPhysicalDeviceXcbPresentationSupportKHR(
        physical_device, queue_family_index, connection, screen->root_visual);
}

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)
