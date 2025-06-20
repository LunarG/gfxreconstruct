/*
** Copyright (c) 2018,2020 Valve Corporation
** Copyright (c) 2018,2025 LunarG, Inc.
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

#include "application/win32_window.h"
#include "application/application.h"
#include "util/logging.h"

#include <cassert>
#include <cstdlib>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

// Define a style similar to WS_OVERLAPPEDWINDOW, but without the ability to resize, minimize, or maximize.
const uint32_t kWindowedStyle   = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
const uint32_t kFullscreenStyle = WS_POPUP;

Win32Window::Win32Window(Win32Context* win32_context) :
    hwnd_(nullptr), win32_context_(win32_context), width_(0), height_(0),
    screen_width_(std::numeric_limits<uint32_t>::max()), screen_height_(std::numeric_limits<uint32_t>::max()),
    fullscreen_(false), hinstance_(nullptr)
{
    assert(win32_context_ != nullptr);
}

Win32Window::~Win32Window()
{
    if (hwnd_ != nullptr)
    {
        DestroyWindow(hwnd_);
    }
}

bool Win32Window::Create(const std::string& title,
                         const int32_t      xpos,
                         const int32_t      ypos,
                         const uint32_t     width,
                         const uint32_t     height,
                         bool               force_windowed)
{
    const char class_name[] = "GFXReconstruct Window";

    hinstance_ = GetModuleHandle(nullptr);
    if (hinstance_ == nullptr)
    {
        GFXRECON_LOG_ERROR("Failed to retrieve instance for window creation");
        return false;
    }

    // Register Window class
    WNDCLASSEX wcex    = {};
    wcex.cbSize        = sizeof(WNDCLASSEX);
    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = Win32Context::WindowProc;
    wcex.cbClsExtra    = 0;
    wcex.cbWndExtra    = 0;
    wcex.hInstance     = hinstance_;
    wcex.hIcon         = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON));
    wcex.hIconSm       = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON));
    wcex.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName  = nullptr;
    wcex.lpszClassName = class_name;

    RegisterClassEx(&wcex);

    // Get desktop resolution (ignoring the taskbar).
    HWND screen = GetDesktopWindow();
    RECT screen_rect;
    GetWindowRect(screen, &screen_rect);
    screen_width_  = screen_rect.right;
    screen_height_ = screen_rect.bottom;

    // Determine if fullscreen mode is required.
    uint32_t window_style = kWindowedStyle;
    int32_t  x            = xpos;
    int32_t  y            = ypos;
    fullscreen_           = false;
    force_windowed_       = force_windowed;

    if ((screen_height_ <= ypos) || (screen_width_ <= xpos))
    {
        GFXRECON_LOG_WARNING("Requested window location (%u, %u) exceeds current screen size (%ux%u).",
                             xpos,
                             ypos,
                             screen_width_,
                             screen_height_);
    }

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

        if (!force_windowed)
        {
            fullscreen_ = true;

            window_style = kFullscreenStyle;

            // Place fullscreen window at 0, 0.
            x = 0;
            y = 0;
        }
    }

    // Create the window.
    RECT wr = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
    AdjustWindowRect(&wr, window_style, FALSE);

    hwnd_ = CreateWindow(class_name,
                         title.c_str(),
                         window_style,
                         x,
                         y,
                         wr.right - wr.left,
                         wr.bottom - wr.top,
                         nullptr,
                         nullptr,
                         wcex.hInstance,
                         win32_context_);

    if (hwnd_)
    {
        win32_context_->RegisterWindow(this);

        width_  = width;
        height_ = height;
    }
    else
    {
        GFXRECON_LOG_ERROR("Window creation failed with error code %u", GetLastError());
        return false;
    }

    // Make sure window is visible.
    ShowWindow(hwnd_, SW_SHOWDEFAULT);

    return true;
}

bool Win32Window::Destroy()
{
    if (hwnd_ != nullptr)
    {
        DestroyWindow(hwnd_);
        win32_context_->UnregisterWindow(this);
        hwnd_ = nullptr;
        return true;
    }

    return false;
}

void Win32Window::SetTitle(const std::string& title)
{
    SetWindowTextA(hwnd_, title.c_str());
}

void Win32Window::SetPosition(const int32_t x, const int32_t y)
{
    SetWindowPos(hwnd_, nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void Win32Window::SetSize(const uint32_t width, const uint32_t height)
{
    if ((width != width_) || (height != height_))
    {
        width_  = width;
        height_ = height;

        RECT wr = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };

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

            uint32_t swp_flags = SWP_NOMOVE | SWP_NOZORDER;

            uint32_t current_window_style = GetWindowLong(hwnd_, GWL_STYLE);
            uint32_t window_style = fullscreen_ ? (WS_VISIBLE | kFullscreenStyle) : (WS_VISIBLE | kWindowedStyle);

            if (((current_window_style & kFullscreenStyle) != kFullscreenStyle) && (force_windowed_ == false))
            {
                window_style = WS_VISIBLE | kFullscreenStyle;
                SetWindowLong(hwnd_, GWL_STYLE, window_style);
                swp_flags |= SWP_FRAMECHANGED;
            }

            AdjustWindowRect(&wr, window_style, FALSE);

            // Keep window current position when resizing.
            SetWindowPos(hwnd_, HWND_TOPMOST, 0, 0, wr.right - wr.left, wr.bottom - wr.top, swp_flags);
        }
        else
        {
            uint32_t swp_flags = SWP_NOMOVE | SWP_NOZORDER;

            if (fullscreen_)
            {
                SetWindowLong(hwnd_, GWL_STYLE, WS_VISIBLE | kWindowedStyle);
                swp_flags |= SWP_FRAMECHANGED;
                fullscreen_ = false;
            }

            AdjustWindowRect(&wr, kWindowedStyle, FALSE);

            SetWindowPos(hwnd_, nullptr, 0, 0, wr.right - wr.left, wr.bottom - wr.top, swp_flags);
        }
    }
}

void Win32Window::SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform)
{
    GFXRECON_UNREFERENCED_PARAMETER(pre_transform);
    SetSize(width, height);
}

void Win32Window::SetVisibility(bool show)
{
    ShowWindow(hwnd_, show ? SW_SHOWDEFAULT : SW_HIDE);
}

void Win32Window::SetForeground()
{
    SetForegroundWindow(hwnd_);
}

bool Win32Window::GetNativeHandle(HandleType type, void** handle)
{
    assert(handle != nullptr);
    switch (type)
    {
        case Window::kWin32HInstance:
            *handle = reinterpret_cast<void*>(hinstance_);
            return true;
        case Window::kWin32HWnd:
            *handle = reinterpret_cast<void*>(hwnd_);
            return true;
        default:
            return false;
    }
}

std::string Win32Window::GetWsiExtension() const
{
    return VK_KHR_WIN32_SURFACE_EXTENSION_NAME;
}

VkExtent2D Win32Window::GetSize() const
{
    return { width_, height_ };
}

VkResult Win32Window::CreateSurface(const graphics::VulkanInstanceTable* table,
                                    VkInstance                           instance,
                                    VkFlags                              flags,
                                    VkSurfaceKHR*                        pSurface)
{
    if (table != nullptr)
    {
        VkWin32SurfaceCreateInfoKHR create_info{
            VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR, nullptr, flags, hinstance_, hwnd_
        };

        return table->CreateWin32SurfaceKHR(instance, &create_info, nullptr, pSurface);
    }

    return VK_ERROR_INITIALIZATION_FAILED;
}

void Win32Window::DestroySurface(const graphics::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface)
{
    if (table != nullptr)
    {
        table->DestroySurfaceKHR(instance, surface, nullptr);
    }
}

Win32WindowFactory::Win32WindowFactory(Win32Context* win32_context) : win32_context_(win32_context)
{
    assert(win32_context_);
}

decode::Window* Win32WindowFactory::Create(
    const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, bool force_windowed)
{
    assert(win32_context_);
    decode::Window* window      = new Win32Window(win32_context_);
    auto            application = win32_context_->GetApplication();
    assert(application);
    window->Create(application->GetName(), x, y, width, height, force_windowed);
    return window;
}

void Win32WindowFactory::Destroy(decode::Window* window)
{
    if (window != nullptr)
    {
        window->Destroy();
        delete window;
    }
}

VkBool32 Win32WindowFactory::GetPhysicalDevicePresentationSupport(const graphics::VulkanInstanceTable* table,
                                                                  VkPhysicalDevice                     physical_device,
                                                                  uint32_t queue_family_index)
{
    return table->GetPhysicalDeviceWin32PresentationSupportKHR(physical_device, queue_family_index);
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
