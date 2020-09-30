/*
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

#include "application/xlib_window.h"

#include "util/logging.h"

#include "X11/Xatom.h"

#include <cassert>
#include <cstdlib>
#include <limits>
#include <unistd.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

XlibWindow::XlibWindow(XlibApplication* application) :
    xlib_application_(application), display_(nullptr), window_(0), width_(0), height_(0),
    screen_width_(std::numeric_limits<uint32_t>::max()), screen_height_(std::numeric_limits<uint32_t>::max()),
    visible_(false), fullscreen_(false)
{
    assert(application != nullptr);
}

XlibWindow::~XlibWindow() {}

bool XlibWindow::Create(
    const std::string& title, const int32_t xpos, const int32_t ypos, const uint32_t width, const uint32_t height)
{
    display_ = xlib_application_->OpenDisplay();

    const auto xlib   = xlib_application_->GetXlibFunctionTable();
    const auto screen = DefaultScreen(display_);
    const auto root   = RootWindow(display_, screen);

    xlib_application_->RegisterXlibWindow(this);

    // Get screen size
    XWindowAttributes root_attributes;
    xlib.GetWindowAttributes(display_, root, &root_attributes);
    screen_width_  = root_attributes.width;
    screen_height_ = root_attributes.height;

    // Determine if fullscreen mode is required.
    int32_t x             = xpos;
    int32_t y             = ypos;
    bool    go_fullscreen = false;

    if ((root_attributes.height <= height) || (root_attributes.width <= width))
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

    // Set window event mask to receive keyboard events
    XSetWindowAttributes attributes = {};
    attributes.event_mask           = KeyPressMask | KeyReleaseMask;
    unsigned long attribute_mask    = CWEventMask;

    // Create window
    window_ = xlib.CreateWindow(display_,
                                RootWindow(display_, screen),
                                x,
                                y,
                                width,
                                height,
                                0,
                                CopyFromParent,
                                InputOutput,
                                CopyFromParent,
                                attribute_mask,
                                &attributes);

    // Set window title
    SetTitle(title);

    // Display the window
    SetVisibility(true);

    // Enable fullscreen if necessary.
    if (go_fullscreen)
    {
        SetFullscreen(true);
    }

    return true;
}

bool XlibWindow::Destroy()
{
    if (window_ != 0)
    {
        const auto xlib = xlib_application_->GetXlibFunctionTable();

        SetFullscreen(false);
        SetVisibility(false);

        xlib.DestroyWindow(display_, window_);
        xlib.Sync(display_, true);

        xlib_application_->CloseDisplay(display_);
        display_ = nullptr;

        xlib_application_->UnregisterXlibWindow(this);
        window_ = 0;

        return true;
    }

    return false;
}

void XlibWindow::SetTitle(const std::string& title)
{
    const auto xlib = xlib_application_->GetXlibFunctionTable();
    xlib.StoreName(display_, window_, title.c_str());
}

void XlibWindow::SetPosition(const int32_t x, const int32_t y)
{
    const auto xlib = xlib_application_->GetXlibFunctionTable();
    xlib.MoveWindow(display_, window_, x, y);
}

void XlibWindow::SetSize(const uint32_t width, const uint32_t height)
{
    if ((width != width_) || (height != height_))
    {
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
            const auto xlib = xlib_application_->GetXlibFunctionTable();
            xlib.ResizeWindow(display_, window_, width, height);
            xlib.Sync(display_, true);
        }
        // Sleep to ensure window resize has completed.
        usleep(50000); // 0.05 seconds (same as vktrace)
    }
}

void XlibWindow::SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform)
{
    GFXRECON_UNREFERENCED_PARAMETER(pre_transform);
    SetSize(width, height);
}

void XlibWindow::SetFullscreen(bool fullscreen)
{
    if (fullscreen != fullscreen_)
    {
        const auto xlib   = xlib_application_->GetXlibFunctionTable();
        const auto screen = DefaultScreen(display_);
        const auto root   = RootWindow(display_, screen);

        XEvent event;
        event.type                 = ClientMessage;
        event.xclient.window       = window_;
        event.xclient.format       = 32;
        event.xclient.message_type = xlib.InternAtom(display_, "_NET_WM_STATE", false);
        event.xclient.data.l[0]    = fullscreen ? 1 : 0;
        event.xclient.data.l[1]    = xlib.InternAtom(display_, "_NET_WM_STATE_FULLSCREEN", false);
        event.xclient.data.l[2]    = 0;
        event.xclient.data.l[3]    = 0;
        event.xclient.data.l[4]    = 0;

        xlib.SendEvent(display_, root, false, (SubstructureNotifyMask | SubstructureRedirectMask), &event);

        // Use same compositor workaround as XcbWindow for GNOME/NVIDIA VK_ERROR_OUT_OF_DATE_KHR issue
        int32_t bypass = fullscreen ? 2 : 0;
        xlib.ChangeProperty(display_,
                            window_,
                            xlib.InternAtom(display_, "_NET_WM_BYPASS_COMPOSITOR", false),
                            XA_CARDINAL,
                            32,
                            PropModeReplace,
                            reinterpret_cast<unsigned char*>(&bypass),
                            1);

        xlib.Sync(display_, true);

        // Sleep to ensure window resize has completed.
        usleep(50000); // 0.05 seconds (same as vktrace)
        fullscreen_ = fullscreen;
    }
}

void XlibWindow::SetVisibility(bool show)
{
    if (show != visible_)
    {
        const auto xlib = xlib_application_->GetXlibFunctionTable();
        if (show)
        {
            xlib.MapWindow(display_, window_);
        }
        else
        {
            xlib.UnmapWindow(display_, window_);
        }
        xlib.Sync(display_, true);
        visible_ = show;
    }
}

void XlibWindow::SetForeground()
{
    const auto xlib   = xlib_application_->GetXlibFunctionTable();
    const auto screen = DefaultScreen(display_);
    const auto root   = RootWindow(display_, screen);

    XEvent event;
    event.type                 = ClientMessage;
    event.xclient.window       = window_;
    event.xclient.format       = 32;
    event.xclient.message_type = xlib.InternAtom(display_, "_NET_ACTIVE_WINDOW", false);
    event.xclient.data.l[0]    = 1;
    event.xclient.data.l[1]    = 0;
    event.xclient.data.l[2]    = 0;
    event.xclient.data.l[3]    = 0;
    event.xclient.data.l[4]    = 0;

    xlib.SendEvent(display_, root, false, (SubstructureNotifyMask | SubstructureRedirectMask), &event);
}

bool XlibWindow::GetNativeHandle(HandleType type, void** handle)
{
    assert(handle != nullptr);
    switch (type)
    {
        case Window::kXlibDisplay:
            *handle = reinterpret_cast<void*>(display_);
            return true;
        case Window::kXlibWindow:
            *handle = reinterpret_cast<void*>(window_);
            return true;
        default:
            return false;
    }
}

VkResult XlibWindow::CreateSurface(const encode::InstanceTable* table,
                                   VkInstance                   instance,
                                   VkFlags                      flags,
                                   VkSurfaceKHR*                pSurface)
{
    if (table != nullptr)
    {
        VkXlibSurfaceCreateInfoKHR create_info{
            VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR, nullptr, flags, display_, window_
        };

        return table->CreateXlibSurfaceKHR(instance, &create_info, nullptr, pSurface);
    }
    return VK_ERROR_INITIALIZATION_FAILED;
}

void XlibWindow::DestroySurface(const encode::InstanceTable* table, VkInstance instance, VkSurfaceKHR surface)
{
    if (table != nullptr)
    {
        table->DestroySurfaceKHR(instance, surface, nullptr);
    }
}

XlibWindowFactory::XlibWindowFactory(XlibApplication* application) : xlib_application_(application)
{
    assert(application != nullptr);
}

decode::Window* XlibWindowFactory::Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height)
{
    const auto window = new XlibWindow(xlib_application_);
    window->Create(xlib_application_->GetName(), x, y, width, height);
    return window;
}

void XlibWindowFactory::Destroy(decode::Window* window)
{
    if (window != nullptr)
    {
        window->Destroy();
        delete window;
    }
}

VkBool32 XlibWindowFactory::GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                                 VkPhysicalDevice             physical_device,
                                                                 uint32_t                     queue_family_index)
{
    return table->GetPhysicalDeviceXlibPresentationSupportKHR(physical_device, queue_family_index, nullptr, 0);
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
