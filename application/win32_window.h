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

#ifndef BRIMSTONE_APPLICATION_WIN32_WINDOW_H
#define BRIMSTONE_APPLICATION_WIN32_WINDOW_H

#include <windows.h>

#include "format/window.h"
#include "application/win32_application.h"

#define IDI_ICON 101

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

class Win32Window : public format::Window
{
public:
    enum HandleId : uint32_t
    {
        kHInstance = 0,
        kHWnd = 1
    };

public:
    Win32Window(Win32Application* application);

    virtual ~Win32Window();

    bool Create(const uint32_t width, const uint32_t height) override;

    bool Destroy() override;

    void SetPosition(const uint32_t x, const uint32_t y) override;

    void SetSize(const uint32_t width, const uint32_t height) override;

    void SetVisibility(bool show) override;

    void SetFocus() override;

    bool GetNativeHandle(uint32_t id, void ** handle) override;

    VkResult CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* pSurface) override;

public:
    HWND                        hwnd_;

private:
    Win32Application *          win32_application_;
    uint32_t                    width_;
    uint32_t                    height_;
    HINSTANCE                   hinstance_;
};

class Win32WindowFactory : public format::WindowFactory
{
public:
    Win32WindowFactory(Win32Application* application);

    format::Window* Create(const uint32_t width, const uint32_t height) override;

private:
    Win32Application * win32_application_;
};

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_APPLICATION_WIN32_WINDOW_H