/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "application/xlib_window.h"
#include "application/application.h"
#include "util/logging.h"

#include "X11/Xatom.h"

#include <cassert>
#include <cstdlib>
#include <limits>
#include <unistd.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

XlibWindow::XlibWindow(XlibContext* xlib_context) :
    xlib_context_(xlib_context), display_(nullptr), window_(0), width_(0), height_(0),
    screen_width_(std::numeric_limits<uint32_t>::max()), screen_height_(std::numeric_limits<uint32_t>::max()),
    visible_(false), fullscreen_(false)
{
    assert(xlib_context_ != nullptr);
}

XlibWindow::~XlibWindow() {}

bool XlibWindow::Create(const std::string& title,
                        const int32_t      xpos,
                        const int32_t      ypos,
                        const uint32_t     width,
                        const uint32_t     height,
                        bool               force_windowed)
{
    GFXRECON_UNREFERENCED_PARAMETER(force_windowed);
    display_ = xlib_context_->OpenDisplay();

    const auto xlib   = xlib_context_->GetXlibFunctionTable();
    const auto screen = DefaultScreen(display_);
    const auto root   = RootWindow(display_, screen);

    xlib_context_->RegisterXlibWindow(this);

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
        const auto xlib = xlib_context_->GetXlibFunctionTable();

        SetFullscreen(false);
        SetVisibility(false);

        xlib.DestroyWindow(display_, window_);
        xlib.Sync(display_, true);

        xlib_context_->CloseDisplay(display_);
        display_ = nullptr;

        xlib_context_->UnregisterXlibWindow(this);
        window_ = 0;

        return true;
    }

    return false;
}

void XlibWindow::SetTitle(const std::string& title)
{
    const auto xlib = xlib_context_->GetXlibFunctionTable();
    xlib.StoreName(display_, window_, title.c_str());
}

void XlibWindow::SetPosition(const int32_t x, const int32_t y)
{
    const auto xlib = xlib_context_->GetXlibFunctionTable();
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
            const auto xlib = xlib_context_->GetXlibFunctionTable();
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
        const auto xlib   = xlib_context_->GetXlibFunctionTable();
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
        const auto xlib = xlib_context_->GetXlibFunctionTable();
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
    const auto xlib   = xlib_context_->GetXlibFunctionTable();
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

std::string XlibWindow::GetWsiExtension() const
{
    return VK_KHR_XLIB_SURFACE_EXTENSION_NAME;
}

VkExtent2D XlibWindow::GetSize() const
{
    return { width_, height_ };
}

VkResult XlibWindow::CreateSurface(const graphics::VulkanInstanceTable* table,
                                   VkInstance                           instance,
                                   VkFlags                              flags,
                                   VkSurfaceKHR*                        pSurface)
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

void XlibWindow::DestroySurface(const graphics::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface)
{
    if (table != nullptr)
    {
        table->DestroySurfaceKHR(instance, surface, nullptr);
    }
}

XlibWindowFactory::XlibWindowFactory(XlibContext* context) : xlib_context_(context)
{
    assert(xlib_context_ != nullptr);
}

decode::Window* XlibWindowFactory::Create(
    const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, bool force_windowed)
{
    assert(xlib_context_);
    decode::Window* window      = new XlibWindow(xlib_context_);
    auto            application = xlib_context_->GetApplication();
    assert(application);
    window->Create(application->GetName(), x, y, width, height, force_windowed);
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

VkBool32 XlibWindowFactory::GetPhysicalDevicePresentationSupport(const graphics::VulkanInstanceTable* table,
                                                                 VkPhysicalDevice                     physical_device,
                                                                 uint32_t queue_family_index)
{
    const auto display = xlib_context_->OpenDisplay();
    const auto xlib    = xlib_context_->GetXlibFunctionTable();

    // Get visual ID which will be inherited from parent at window creation
    XWindowAttributes root_attributes;
    xlib.GetWindowAttributes(display, RootWindow(display, DefaultScreen(display)), &root_attributes);
    const auto visual_id = xlib.VisualIDFromVisual(root_attributes.visual);

    const auto result =
        table->GetPhysicalDeviceXlibPresentationSupportKHR(physical_device, queue_family_index, display, visual_id);

    xlib_context_->CloseDisplay(display);
    return result;
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
