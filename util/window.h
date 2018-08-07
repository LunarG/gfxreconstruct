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

#ifndef BRIMSTONE_UTIL_WINDOW_H
#define BRIMSTONE_UTIL_WINDOW_H

#include "util/application.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

class Window
{
public:
    Window(Application* application);
    virtual ~Window();

    virtual bool Create(const uint32_t width, const uint32_t height) = 0;

    virtual bool Destroy() = 0;

    virtual void SetPosition(const uint32_t x, const uint32_t y) = 0;

    virtual void SetSize(const uint32_t width, const uint32_t height) = 0;

    virtual void SetVisibility(bool show) = 0;

    virtual void SetFocus() = 0;

    virtual bool GetNativeHandle(uint32_t id, void ** handle) = 0;

    virtual VkResult CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* pSurface) = 0;

public:
    std::string name = "Brimstone";

protected:
    Application* application_;
};

class WindowFactory
{
public:
    WindowFactory(Application* application) {};
    virtual ~WindowFactory() {};

    virtual Window* Create(const uint32_t width, const uint32_t height) = 0;
};

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_WINDOW_H