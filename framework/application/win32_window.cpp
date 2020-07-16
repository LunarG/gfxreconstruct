/*
** Copyright (c) 2018,2020 Valve Corporation
** Copyright (c) 2018,2020 LunarG, Inc.
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

#include "application/win32_window.h"
#include "util/logging.h"

#include <cassert>
#include <cstdlib>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

// Define a style similar to WS_OVERLAPPEDWINDOW, but without the ability to resize, minimize, or maximize.
const uint32_t kWindowedStyle   = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
const uint32_t kFullscreenStyle = WS_POPUP;

Win32Window::Win32Window(Win32Application* application) :
    hwnd_(nullptr), win32_application_(application), width_(0), height_(0),
    screen_width_(std::numeric_limits<uint32_t>::max()), screen_height_(std::numeric_limits<uint32_t>::max()),
    fullscreen_(false), hinstance_(nullptr)
{
    assert(application != nullptr);
}

Win32Window::~Win32Window()
{
    if (hwnd_ != nullptr)
    {
        DestroyWindow(hwnd_);
    }
}

bool Win32Window::Create(
    const std::string& title, const int32_t xpos, const int32_t ypos, const uint32_t width, const uint32_t height)
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
    wcex.lpfnWndProc   = Win32Application::WindowProc;
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

        fullscreen_ = true;

        window_style = kFullscreenStyle;

        // Place fullscreen window at 0, 0.
        x = 0;
        y = 0;
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
                         win32_application_);

    if (hwnd_)
    {
        win32_application_->RegisterWindow(this);

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
        win32_application_->UnregisterWindow(this);
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

            uint32_t swp_flags = 0;

            if (!fullscreen_)
            {
                SetWindowLong(hwnd_, GWL_STYLE, WS_VISIBLE | kFullscreenStyle);
                swp_flags |= SWP_FRAMECHANGED;
                fullscreen_ = true;
            }

            AdjustWindowRect(&wr, kFullscreenStyle, FALSE);

            // Move window to the 0,0 position when resizing.
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

VkResult Win32Window::CreateSurface(const encode::InstanceTable* table,
                                    VkInstance                   instance,
                                    VkFlags                      flags,
                                    VkSurfaceKHR*                pSurface)
{
    VkWin32SurfaceCreateInfoKHR create_info{
        VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR, nullptr, flags, hinstance_, hwnd_
    };

    return table->CreateWin32SurfaceKHR(instance, &create_info, nullptr, pSurface);
}

Win32WindowFactory::Win32WindowFactory(Win32Application* application) : win32_application_(application)
{
    assert(application != nullptr);
}

decode::Window*
Win32WindowFactory::Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height)
{
    decode::Window* window = new Win32Window(win32_application_);
    window->Create(win32_application_->GetName(), x, y, width, height);
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

VkBool32 Win32WindowFactory::GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                                  VkPhysicalDevice             physical_device,
                                                                  uint32_t                     queue_family_index)
{
    return table->GetPhysicalDeviceWin32PresentationSupportKHR(physical_device, queue_family_index);
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
