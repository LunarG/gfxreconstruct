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

#include "volk.h"

#include "util/logging.h"
#include "application/win32_window.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

Win32Window::Win32Window(Win32Application* application) :
    hwnd_(nullptr), win32_application_(application), xpos_(0), ypos_(0), width_(0), height_(0), hinstance_(nullptr)
{
    assert(application != nullptr);

    win32_application_->RegisterWindow(this);

    screen_width_  = GetSystemMetrics(SM_CXFULLSCREEN);
    screen_height_ = GetSystemMetrics(SM_CYFULLSCREEN);
}

Win32Window::~Win32Window()
{
    win32_application_->UnregisterWindow(this);
}

bool Win32Window::Create(const int32_t xpos, const int32_t ypos, const uint32_t width, const uint32_t height)
{
    const char class_name[] = "GCAPPlay Window";

    hinstance_ = GetModuleHandle(0);

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

    // Create the window.
    RECT wr = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

    hwnd_ = CreateWindow(class_name,
                         name.c_str(),
                         WS_OVERLAPPEDWINDOW,
                         xpos,
                         ypos,
                         wr.right - wr.left,
                         wr.bottom - wr.top,
                         nullptr,
                         nullptr,
                         wcex.hInstance,
                         win32_application_);

    if (hwnd_)
    {
        xpos_   = xpos;
        ypos_   = ypos;
        width_  = width;
        height_ = height;
    }
    else
    {
        BRIMSTONE_LOG_ERROR("Window creation failed with error code %u", GetLastError());
        return false;
    }

    // Make sure window is visible.
    ShowWindow(hwnd_, SW_SHOWDEFAULT);

    return true;
}

bool Win32Window::Destroy()
{
    DestroyWindow(hwnd_);
    return true;
}

void Win32Window::SetPosition(const int32_t x, const int32_t y)
{
    if ((x != xpos_) || (y != ypos_))
    {
        xpos_ = x;
        ypos_ = y;

        SetWindowPos(hwnd_, nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    }
}

void Win32Window::SetSize(const uint32_t width, const uint32_t height)
{
    if ((width != width_) || (height != height_))
    {
        width_  = width;
        height_ = height;

        RECT wr = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };

        if (screen_height_ <= height && screen_width_ <= width)
        {
            SetWindowLong(hwnd_, GWL_STYLE, WS_POPUP);
            AdjustWindowRect(&wr, WS_POPUP, FALSE);
        }
        else
        {
            AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
        }

        SetWindowPos(hwnd_,
                     nullptr,
                     0,
                     0,
                     wr.right - wr.left,
                     wr.bottom - wr.top,
                     SWP_NOMOVE | SWP_NOZORDER);
    }
}

void Win32Window::SetVisibility(bool show)
{
    ShowWindow(hwnd_, show ? SW_SHOWDEFAULT : SW_HIDE);
}

void Win32Window::SetForeground()
{
    SetForegroundWindow(hwnd_);
}

bool Win32Window::GetNativeHandle(uint32_t id, void ** handle)
{
    assert(handle != nullptr);
    switch (id) {
    case Win32Window::kHInstance:
        *handle = reinterpret_cast<void*>(hinstance_);
        return true;
    case Win32Window::kHWnd:
        *handle = reinterpret_cast<void*>(hwnd_);
        return true;
    default:
        return false;
    }
}

VkResult Win32Window::CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* pSurface)
{
    VkWin32SurfaceCreateInfoKHR create_info
    {
        VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
        nullptr,
        flags,
        hinstance_,
        hwnd_
    };

    return vkCreateWin32SurfaceKHR(instance, &create_info, nullptr, pSurface);
}

Win32WindowFactory::Win32WindowFactory(Win32Application* application) : win32_application_(application)
{
    assert(application != nullptr);
}

format::Window*
Win32WindowFactory::Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height)
{
    format::Window* window = new Win32Window(win32_application_);
    window->Create(x, y, width, height);
    return window;
}

VkBool32 Win32WindowFactory::GetPhysicalDevicePresentationSupport(VkPhysicalDevice physical_device,
                                                                  uint32_t         queue_family_index)
{
    return vkGetPhysicalDeviceWin32PresentationSupportKHR(physical_device, queue_family_index);
}

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)
