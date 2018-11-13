/*
** Copyright (c) 2018 Valve Corporation
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

#include "application/xcb_window.h"

#include "util/logging.h"

#include "volk.h"

#include <cassert>
#include <cstdlib>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

// Names for protocol and state atoms.
const char kProtocolName[]           = "WM_PROTOCOLS";
const char kDeleteWindowName[]       = "WM_DELETE_WINDOW";
const char kStateName[]              = "_NET_WM_STATE";
const char kStateFullscreenName[]    = "_NET_WM_STATE_FULLSCREEN";
const char kStateMaximizedHorzName[] = "_NET_WM_STATE_MAXIMIZED_HORZ";
const char kStateMaximizedVertName[] = "_NET_WM_STATE_MAXIMIZED_VERT";

// Masks for window geometry configuration.
const uint16_t kConfigurePositionMask     = XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y;
const uint16_t kConfigureSizeMask         = XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT;
const uint16_t kConfigurePositionSizeMask = kConfigurePositionMask | kConfigureSizeMask;

XcbWindow::XcbWindow(XcbApplication* application) :
    xcb_application_(application), width_(0), height_(0), screen_width_(std::numeric_limits<uint32_t>::max()),
    screen_height_(std::numeric_limits<uint32_t>::max()), visible_(false), fullscreen_(false), window_(0),
    protocol_atom_(0), delete_window_atom_(0), state_atom_(0), state_fullscreen_atom_(0), state_maximized_horz_atom_(0),
    state_maximized_vert_atom_(0)
{
    assert(application != nullptr);
}

XcbWindow::~XcbWindow()
{
    if (window_ != 0)
    {
        xcb_destroy_window(xcb_application_->GetConnection(), window_);
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
        GFXRECON_LOG_ERROR("Failed to generate window ID");
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
        GFXRECON_LOG_WARNING("Failed to retrieve screen geometry with error code %u", error->error_code);
    }

    // Determine if fullscreen mode is required.
    int32_t x             = xpos;
    int32_t y             = ypos;
    bool    go_fullscreen = false;

    if ((screen_height_ <= height) || (screen_width_ <= width))
    {
        if ((screen_height_ < height) || (screen_width_ < width))
        {
            GFXRECON_LOG_WARNING(
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

    xcb_void_cookie_t cookie = xcb_create_window_checked(connection,
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

    error = xcb_request_check(connection, cookie);
    if (error != nullptr)
    {
        GFXRECON_LOG_ERROR("Failed to create window with error %u", error->error_code);
        window_ = 0;
        return false;
    }

    InitializeAtoms();

    // Request notification when user closes window.
    xcb_change_property(connection, XCB_PROP_MODE_REPLACE, window_, protocol_atom_, 4, 32, 1, &(delete_window_atom_));

    // Set the title.
    xcb_change_property(connection,
                        XCB_PROP_MODE_REPLACE,
                        window_,
                        XCB_ATOM_WM_NAME,
                        XCB_ATOM_STRING,
                        8,
                        static_cast<uint32_t>(title.length()),
                        title.c_str());

    // Display the window.
    SetVisibility(true);

    // Enable fullscreen if necessary.
    if (go_fullscreen)
    {
        SetFullscreen(true);

        // If window was created with a reduced size, make sure it is the appropriate size.
        SetSize(width, height);
    }

    return true;
}

bool XcbWindow::Destroy()
{
    if (window_ != 0)
    {
        xcb_destroy_window(xcb_application_->GetConnection(), window_);
        xcb_application_->UnregisterXcbWindow(this);
        window_ = 0;
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

    xcb_configure_window(connection, window_, kConfigurePositionMask, values);
    xcb_flush(connection);
}

void XcbWindow::SetSize(const uint32_t width, const uint32_t height)
{
    if ((width != width_) || (height != height_))
    {
        xcb_void_cookie_t cookie     = { 0 };
        xcb_connection_t* connection = xcb_application_->GetConnection();

        if ((screen_width_ <= width) || (screen_height_ <= height))
        {
            if ((screen_height_ < height) || (screen_width_ < width))
            {
                GFXRECON_LOG_WARNING(
                    "Requested window size (%ux%u) exceeds current screen size (%ux%u); replay may fail due to "
                    "inability to create a window of the appropriate size.",
                    width,
                    height,
                    screen_width_,
                    screen_height_);
            }

            SetFullscreen(true);

            // Make sure the window position is (0,0).
            uint32_t values[] = { 0, 0, width, height };
            cookie            = xcb_configure_window(connection, window_, kConfigurePositionSizeMask, values);
        }
        else
        {
            SetFullscreen(false);

            uint32_t values[] = { width, height };
            cookie            = xcb_configure_window(connection, window_, kConfigureSizeMask, values);
        }

        xcb_flush(connection);

        // Wait for configure notification.
        pending_event_.sequence = cookie.sequence;
        pending_event_.type     = XCB_CONFIGURE_NOTIFY;
        pending_event_.complete = false;
        xcb_application_->ClearLastError();
        while (!pending_event_.complete && xcb_application_->IsRunning())
        {
            xcb_application_->ProcessEvents(true);

            // TODO: We may need to check for any error, not an error for a specific sequence number.
            if (xcb_application_->GetLastErrorSequence() == pending_event_.sequence)
            {
                GFXRECON_LOG_ERROR("Failed to resize window with error %u", xcb_application_->GetLastErrorCode());
                break;
            }
        }
    }
}

void XcbWindow::SetFullscreen(bool fullscreen)
{
    if (fullscreen != fullscreen_)
    {
        xcb_connection_t* connection = xcb_application_->GetConnection();
        xcb_screen_t*     screen     = xcb_application_->GetScreen();

        xcb_client_message_event_t event;
        event.response_type  = XCB_CLIENT_MESSAGE;
        event.format         = 32;
        event.sequence       = 0;
        event.window         = window_;
        event.type           = state_atom_;
        event.data.data32[0] = fullscreen ? 1 : 0;
        event.data.data32[1] = state_fullscreen_atom_;
        event.data.data32[2] = 0;
        event.data.data32[3] = 0;
        event.data.data32[4] = 0;

        xcb_void_cookie_t event_cookie =
            xcb_send_event_checked(connection,
                                   0,
                                   screen->root,
                                   XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT,
                                   reinterpret_cast<const char*>(&event));

        xcb_generic_error_t* error = xcb_request_check(connection, event_cookie);

        if (error == nullptr)
        {
            fullscreen_ = fullscreen;

            if (!fullscreen)
            {
                // Some window managers may maximize when entering full screen, but won't restore when exiting full
                // screen.  Ensure that the window is not in the maximized state.
                event.data.data32[0] = 0;
                event.data.data32[1] = state_maximized_horz_atom_;
                event.data.data32[2] = state_maximized_vert_atom_;

                xcb_void_cookie_t event_cookie =
                    xcb_send_event_checked(connection,
                                           0,
                                           screen->root,
                                           XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT,
                                           reinterpret_cast<const char*>(&event));

                error = xcb_request_check(connection, event_cookie);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to toggle fullscreen mode with error %u", error->error_code);
        }
    }
}

void XcbWindow::SetVisibility(bool show)
{
    if (show != visible_)
    {
        xcb_connection_t* connection = xcb_application_->GetConnection();
        xcb_void_cookie_t cookie;

        if (show)
        {
            cookie = xcb_map_window(connection, window_);
        }
        else
        {
            cookie = xcb_unmap_window(connection, window_);
        }

        xcb_flush(connection);

        // We wait for the map event instead of using xcb_request_check because the
        // result of xcb_request_check seems to indicate the request has been processed
        // successfully, not that the map operation has completed, and we need to wait
        // for the operation to complete. We also do not do both because the sequence
        // number from the checked call does not appear to match the sequence number of
        // the event notifications.  So, we do an unchecked call and check for errors in
        // the event loop.
        pending_event_.sequence = cookie.sequence;
        pending_event_.type     = XCB_MAP_NOTIFY;
        pending_event_.complete = false;
        xcb_application_->ClearLastError();
        while (!pending_event_.complete && xcb_application_->IsRunning())
        {
            xcb_application_->ProcessEvents(true);

            // TODO: We may need to check for any error, not an error for a specific sequence number.
            if (xcb_application_->GetLastErrorSequence() == pending_event_.sequence)
            {
                GFXRECON_LOG_ERROR("Failed to change window visibility with error %u",
                                   xcb_application_->GetLastErrorCode());
                break;
            }
        }
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

xcb_atom_t XcbWindow::GetAtom(const char* name, uint8_t only_if_exists) const
{
    xcb_atom_t               atom       = 0;
    xcb_generic_error_t*     error      = nullptr;
    xcb_connection_t*        connection = xcb_application_->GetConnection();
    xcb_intern_atom_cookie_t cookie     = xcb_intern_atom(connection, only_if_exists, strlen(name), name);
    xcb_intern_atom_reply_t* reply      = xcb_intern_atom_reply(connection, cookie, &error);

    if (reply != nullptr)
    {
        atom = reply->atom;
        free(reply);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to retrieve internal atom for %s with error %u", name, error->error_code);
        return false;
    }

    return atom;
}

void XcbWindow::InitializeAtoms()
{
    protocol_atom_      = GetAtom(kProtocolName, 1);
    delete_window_atom_ = GetAtom(kDeleteWindowName, 0);

    state_atom_                = GetAtom(kStateName, 1);
    state_fullscreen_atom_     = GetAtom(kStateFullscreenName, 0);
    state_maximized_horz_atom_ = GetAtom(kStateMaximizedHorzName, 0);
    state_maximized_vert_atom_ = GetAtom(kStateMaximizedVertName, 0);
}

void XcbWindow::CheckEventStatus(uint32_t sequence, uint32_t type)
{
    if ((sequence == pending_event_.sequence) && (type == pending_event_.type))
    {
        pending_event_.complete = true;
    }
}

XcbWindowFactory::XcbWindowFactory(XcbApplication* application) : xcb_application_(application)
{
    assert(application != nullptr);
}

decode::Window* XcbWindowFactory::Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height)
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

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
