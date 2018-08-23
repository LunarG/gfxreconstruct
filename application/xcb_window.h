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

#ifndef BRIMSTONE_APPLICATION_XCB_WINDOW_H
#define BRIMSTONE_APPLICATION_XCB_WINDOW_H

#include <xcb/xcb.h>

#include "format/window.h"
#include "application/xcb_application.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

class XcbWindow : public format::Window
{
public:
    enum HandleId : uint32_t
    {
        kConnection = 0,
        kWindow = 1
    };

public:
    XcbWindow(XcbApplication* application);

    virtual ~XcbWindow();

    bool Create(const uint32_t width, const uint32_t height) override;

    bool Destroy() override;

    void SetPosition(const uint32_t x, const uint32_t y) override;

    void SetSize(const uint32_t width, const uint32_t height) override;

    void SetVisibility(bool show) override;

    void SetFocus() override;

    bool GetNativeHandle(uint32_t id, void ** handle) override;

    VkResult CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* pSurface) override;

public:
    xcb_intern_atom_reply_t*    atom_wm_delete_window;

private:
    XcbApplication*             xcb_application_;
    uint32_t                    width_;
    uint32_t                    height_;
    xcb_window_t                window_;
};

class XcbWindowFactory : public format::WindowFactory
{
public:
    XcbWindowFactory(XcbApplication* application);

    virtual format::Window* Create(const uint32_t width, const uint32_t height) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(VkPhysicalDevice physical_device,
                                                          uint32_t         queue_family_index) override;

private:
    XcbApplication*            xcb_application_;
};

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_APPLICATION_XCB_WINDOW_H