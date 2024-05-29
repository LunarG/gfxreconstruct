/*
** Copyright (c) 2018,2020 Valve Corporation
** Copyright (c) 2018,2020 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "application/xcb_window.h"
#include "application/application.h"
#include "util/logging.h"

#include <cassert>
#include <cstdlib>
#include <limits>
#include <unistd.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

// Names for protocol and state atoms.
const char kProtocolName[]         = "WM_PROTOCOLS";
const char kDeleteWindowName[]     = "WM_DELETE_WINDOW";
const char kStateName[]            = "_NET_WM_STATE";
const char kStateFullscreenName[]  = "_NET_WM_STATE_FULLSCREEN";
const char kBypassCompositorName[] = "_NET_WM_BYPASS_COMPOSITOR";

// Masks for window geometry configuration.
const uint16_t kConfigurePositionMask     = XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y;
const uint16_t kConfigureSizeMask         = XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT;
const uint16_t kConfigurePositionSizeMask = kConfigurePositionMask | kConfigureSizeMask;

XcbWindow::XcbWindow(XcbContext* xcb_context) :
    xcb_context_(xcb_context), width_(0), height_(0), screen_width_(std::numeric_limits<uint32_t>::max()),
    screen_height_(std::numeric_limits<uint32_t>::max()), visible_(false), fullscreen_(false), window_(0),
    protocol_atom_(0), delete_window_atom_(0), state_atom_(0), state_fullscreen_atom_(0), bypass_compositor_atom_(0)
{
    assert(xcb_context_ != nullptr);
}

XcbWindow::~XcbWindow()
{
    if (window_ != 0)
    {
        auto&             xcb        = xcb_context_->GetXcbFunctionTable();
        xcb_connection_t* connection = xcb_context_->GetConnection();
        xcb.destroy_window(connection, window_);
        xcb.flush(connection);
    }
}

bool XcbWindow::Create(const std::string& title,
                       const int32_t      xpos,
                       const int32_t      ypos,
                       const uint32_t     width,
                       const uint32_t     height,
                       bool               force_windowed)
{
    GFXRECON_UNREFERENCED_PARAMETER(force_windowed);
    auto&             xcb        = xcb_context_->GetXcbFunctionTable();
    xcb_connection_t* connection = xcb_context_->GetConnection();
    xcb_screen_t*     screen     = xcb_context_->GetScreen();

    window_ = xcb.generate_id(connection);
    if (window_ == 0)
    {
        GFXRECON_LOG_ERROR("Failed to generate window ID");
        return false;
    }

    xcb_context_->RegisterXcbWindow(this);

    // Get screen dimensions.
    xcb_generic_error_t*      error       = nullptr;
    xcb_get_geometry_cookie_t geom_cookie = xcb.get_geometry(connection, screen->root);
    xcb_get_geometry_reply_t* geom        = xcb.get_geometry_reply(connection, geom_cookie, &error);

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
        if ((screen_height_ == height) || (screen_width_ == width))
        {
            go_fullscreen = true;

            // Place fullscreen window at 0, 0.
            x = 0;
            y = 0;
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "Requested window size (%ux%u) exceeds current screen size (%ux%u); replay may fail due to "
                "inability to create a window of the appropriate size.",
                width,
                height,
                screen_width_,
                screen_height_);
        }
    }

    uint32_t value_mask   = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    uint32_t value_list[] = { screen->black_pixel,
                              XCB_EVENT_MASK_KEY_RELEASE | XCB_EVENT_MASK_KEY_PRESS | XCB_EVENT_MASK_EXPOSURE |
                                  XCB_EVENT_MASK_STRUCTURE_NOTIFY };

    xcb_void_cookie_t cookie = xcb.create_window_checked(connection,
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

    error = xcb.request_check(connection, cookie);
    if (error != nullptr)
    {
        GFXRECON_LOG_ERROR("Failed to create window with error %u", error->error_code);
        window_ = 0;
        return false;
    }

    InitializeAtoms();

    // Request notification when user closes window.
    xcb.change_property(connection, XCB_PROP_MODE_REPLACE, window_, protocol_atom_, 4, 32, 1, &(delete_window_atom_));

    // Set the title.
    xcb.change_property(connection,
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
    }

    return true;
}

bool XcbWindow::Destroy()
{
    if (window_ != 0)
    {
        auto&             xcb        = xcb_context_->GetXcbFunctionTable();
        xcb_connection_t* connection = xcb_context_->GetConnection();

        SetFullscreen(false);
        SetVisibility(false);

        xcb_void_cookie_t cookie = xcb.destroy_window(connection, window_);
        xcb.flush(connection);

        if (!WaitForEvent(cookie.sequence, XCB_DESTROY_NOTIFY))
        {
            GFXRECON_LOG_ERROR("Failed to destroy window with error %u", xcb_context_->GetLastErrorCode());
        }

        xcb_context_->UnregisterXcbWindow(this);
        window_ = 0;
        return true;
    }

    return false;
}

void XcbWindow::SetTitle(const std::string& title)
{
    auto&             xcb        = xcb_context_->GetXcbFunctionTable();
    xcb_connection_t* connection = xcb_context_->GetConnection();

    xcb.change_property(connection,
                        XCB_PROP_MODE_REPLACE,
                        window_,
                        XCB_ATOM_WM_NAME,
                        XCB_ATOM_STRING,
                        8,
                        static_cast<uint32_t>(title.length()),
                        title.c_str());
    xcb.flush(connection);
}

void XcbWindow::SetPosition(const int32_t x, const int32_t y)
{
    auto&             xcb        = xcb_context_->GetXcbFunctionTable();
    xcb_connection_t* connection = xcb_context_->GetConnection();
    uint32_t          values[]   = { static_cast<uint32_t>(x), static_cast<uint32_t>(y) };

    xcb.configure_window(connection, window_, kConfigurePositionMask, values);
    xcb.flush(connection);
}

void XcbWindow::SetSize(const uint32_t width, const uint32_t height)
{
    if ((width != width_) || (height != height_))
    {
        auto&             xcb        = xcb_context_->GetXcbFunctionTable();
        xcb_connection_t* connection = xcb_context_->GetConnection();
        xcb_void_cookie_t cookie     = { 0 };

        if ((screen_width_ == width) || (screen_height_ == height))
        {
            SetFullscreen(true);
        }
        else
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

            SetFullscreen(false);

            uint32_t values[] = { width, height };
            cookie            = xcb.configure_window(connection, window_, kConfigureSizeMask, values);

            xcb.flush(connection);

            // Wait for configure notification.
            if (!WaitForEvent(cookie.sequence, XCB_CONFIGURE_NOTIFY))
            {
                GFXRECON_LOG_ERROR("Failed to resize window with error %u", xcb_context_->GetLastErrorCode());
            }
            else
            {
                // Sleep to ensure window resize has completed.
                usleep(50000); // 0.05 seconds (same as vktrace)
            }
        }
    }
}

void XcbWindow::SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform)
{
    GFXRECON_UNREFERENCED_PARAMETER(pre_transform);
    SetSize(width, height);
}

void XcbWindow::SetFullscreen(bool fullscreen)
{
    if (fullscreen != fullscreen_)
    {
        auto&             xcb        = xcb_context_->GetXcbFunctionTable();
        xcb_connection_t* connection = xcb_context_->GetConnection();
        xcb_screen_t*     screen     = xcb_context_->GetScreen();

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
            xcb.send_event(connection,
                           0,
                           screen->root,
                           XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT,
                           reinterpret_cast<const char*>(&event));

        xcb.flush(connection);

        // Wait for configure notification.
        if (WaitForEvent(event_cookie.sequence, XCB_CONFIGURE_NOTIFY))
        {
            fullscreen_ = fullscreen;

            if (bypass_compositor_atom_ != 0)
            {
                // Specify that the WM should not bypass the compositor for the full screen window, or specify no
                // preference on exiting full screen. Compositor bypass is disabled to work around a GNOME + NVIDIA
                // issue that leads to a VK_ERROR_OUT_OF_DATE_KHR error with full screen replay.
                // TODO: This could be an option.
                int32_t bypass = fullscreen ? 2 : 0;
                xcb.change_property(connection,
                                    XCB_PROP_MODE_REPLACE,
                                    window_,
                                    bypass_compositor_atom_,
                                    XCB_ATOM_CARDINAL,
                                    32,
                                    1,
                                    &bypass);
                xcb.flush(connection);
            }

            // Sleep to ensure window resize has completed.
            usleep(50000); // 0.05 seconds (same as vktrace)
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to %s fullscreen mode with error %u",
                               fullscreen ? "enter" : "exit",
                               xcb_context_->GetLastErrorCode());
        }
    }
}

void XcbWindow::SetVisibility(bool show)
{
    if (show != visible_)
    {
        auto&             xcb        = xcb_context_->GetXcbFunctionTable();
        xcb_connection_t* connection = xcb_context_->GetConnection();
        xcb_void_cookie_t cookie;

        if (show)
        {
            cookie = xcb.map_window(connection, window_);
        }
        else
        {
            cookie = xcb.unmap_window(connection, window_);
        }

        xcb.flush(connection);

        // Wait for map/unmap notification.
        if (!WaitForEvent(cookie.sequence, XCB_MAP_NOTIFY))
        {
            GFXRECON_LOG_ERROR("Failed to change window visibility with error %u", xcb_context_->GetLastErrorCode());
        }
    }
}

void XcbWindow::SetForeground()
{
    auto&             xcb        = xcb_context_->GetXcbFunctionTable();
    xcb_connection_t* connection = xcb_context_->GetConnection();
    uint32_t          values[]   = { XCB_STACK_MODE_ABOVE };

    xcb.configure_window(connection, window_, XCB_CONFIG_WINDOW_STACK_MODE, values);
    xcb.flush(connection);
}

bool XcbWindow::GetNativeHandle(HandleType type, void** handle)
{
    assert(handle != nullptr);
    switch (type)
    {
        case Window::kXcbConnection:
            *handle = reinterpret_cast<void*>(xcb_context_->GetConnection());
            return true;
        case Window::kXcbWindow:
            *handle = reinterpret_cast<void*>(window_);
            return true;
        default:
            return false;
    }
}

std::string XcbWindow::GetWsiExtension() const
{
    return VK_KHR_XCB_SURFACE_EXTENSION_NAME;
}

VkExtent2D XcbWindow::GetSize() const
{
    return { width_, height_ };
}

VkResult XcbWindow::CreateSurface(const encode::VulkanInstanceTable* table,
                                  VkInstance                         instance,
                                  VkFlags                            flags,
                                  VkSurfaceKHR*                      pSurface)
{
    if (table != nullptr)
    {
        VkXcbSurfaceCreateInfoKHR create_info{
            VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR, nullptr, flags, xcb_context_->GetConnection(), window_
        };

        return table->CreateXcbSurfaceKHR(instance, &create_info, nullptr, pSurface);
    }

    return VK_ERROR_INITIALIZATION_FAILED;
}

void XcbWindow::DestroySurface(const encode::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface)
{
    if (table != nullptr)
    {
        table->DestroySurfaceKHR(instance, surface, nullptr);
    }
}

xcb_intern_atom_cookie_t
XcbWindow::SendAtomRequest(xcb_connection_t* connection, const char* name, uint8_t only_if_exists) const
{
    auto& xcb = xcb_context_->GetXcbFunctionTable();
    return xcb.intern_atom(connection, only_if_exists, strlen(name), name);
}

xcb_atom_t
XcbWindow::GetAtomReply(xcb_connection_t* connection, const char* name, xcb_intern_atom_cookie_t cookie) const
{
    auto&                    xcb   = xcb_context_->GetXcbFunctionTable();
    xcb_atom_t               atom  = 0;
    xcb_generic_error_t*     error = nullptr;
    xcb_intern_atom_reply_t* reply = xcb.intern_atom_reply(connection, cookie, &error);

    if (reply != nullptr)
    {
        atom = reply->atom;
        free(reply);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to retrieve internal XCB atom for %s with error %u", name, error->error_code);
    }

    return atom;
}

void XcbWindow::InitializeAtoms()
{
    xcb_connection_t* connection = xcb_context_->GetConnection();

    // Send requests.
    xcb_intern_atom_cookie_t protocol_atom_cookie          = SendAtomRequest(connection, kProtocolName, 1);
    xcb_intern_atom_cookie_t delete_window_atom_cookie     = SendAtomRequest(connection, kDeleteWindowName, 0);
    xcb_intern_atom_cookie_t state_atom_cookie             = SendAtomRequest(connection, kStateName, 1);
    xcb_intern_atom_cookie_t state_fullscreen_atom_cookie  = SendAtomRequest(connection, kStateFullscreenName, 0);
    xcb_intern_atom_cookie_t bypass_compositor_atom_cookie = SendAtomRequest(connection, kBypassCompositorName, 0);

    // Get replies.
    protocol_atom_          = GetAtomReply(connection, kProtocolName, protocol_atom_cookie);
    delete_window_atom_     = GetAtomReply(connection, kDeleteWindowName, delete_window_atom_cookie);
    state_atom_             = GetAtomReply(connection, kStateName, state_atom_cookie);
    state_fullscreen_atom_  = GetAtomReply(connection, kStateFullscreenName, state_fullscreen_atom_cookie);
    bypass_compositor_atom_ = GetAtomReply(connection, kBypassCompositorName, bypass_compositor_atom_cookie);
}

void XcbWindow::CheckEventStatus(uint16_t sequence, uint32_t type)
{
    // Note that sequence is 16 bits and pending_event_.sequence is 32 bits, so we only compare the lower 16 bits.
    // We're checking for equality, so checking for the arrival of certain events needs to be done in the same order
    // as the xcb calls that cause those events to be generated.
    if ((sequence == static_cast<uint16_t>(pending_event_.sequence & 0xffff)) && (type == pending_event_.type))
    {
        pending_event_.complete = true;
    }
}

bool XcbWindow::WaitForEvent(uint32_t sequence, uint32_t type)
{
    pending_event_.sequence = sequence;
    pending_event_.type     = type;
    pending_event_.complete = false;

    xcb_context_->ClearLastError();

    auto application = xcb_context_->GetApplication();
    assert(application);
    while (!pending_event_.complete && application->IsRunning())
    {
        xcb_context_->ProcessEvents(true);

        // TODO: We may need to check for any error, not an error for a specific sequence number.
        if (xcb_context_->GetLastErrorSequence() == pending_event_.sequence)
        {
            return false;
        }
    }

    return true;
}

XcbWindowFactory::XcbWindowFactory(XcbContext* xcb_context) : xcb_context_(xcb_context)
{
    assert(xcb_context_ != nullptr);
}

decode::Window* XcbWindowFactory::Create(
    const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, bool force_windowed)
{
    assert(xcb_context_);
    decode::Window* window      = new XcbWindow(xcb_context_);
    auto            application = xcb_context_->GetApplication();
    assert(application);
    window->Create(application->GetName(), x, y, width, height, force_windowed);
    return window;
}

void XcbWindowFactory::Destroy(decode::Window* window)
{
    if (window != nullptr)
    {
        window->Destroy();
        delete window;
    }
}

VkBool32 XcbWindowFactory::GetPhysicalDevicePresentationSupport(const encode::VulkanInstanceTable* table,
                                                                VkPhysicalDevice                   physical_device,
                                                                uint32_t                           queue_family_index)
{
    xcb_connection_t* connection = xcb_context_->GetConnection();
    xcb_screen_t*     screen     = xcb_context_->GetScreen();

    assert((connection != nullptr) && (screen != nullptr));

    return table->GetPhysicalDeviceXcbPresentationSupportKHR(
        physical_device, queue_family_index, connection, screen->root_visual);
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
