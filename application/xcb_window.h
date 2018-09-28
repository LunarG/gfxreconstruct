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
        kWindow     = 1
    };

  public:
    XcbWindow(XcbApplication* application);

    virtual ~XcbWindow();

    xcb_window_t GetWindowId() const { return window_; }

    xcb_intern_atom_reply_t* GetDeleteWindowAtom() const { return atom_wm_delete_window_; }

    void MapNotify() { map_complete_ = true; }

    void ResizeNotify(uint32_t width, uint32_t height)
    {
        if ((width == width_) && (height == height_))
        {
            resize_complete_ = true;
        }
    }

    virtual bool Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    virtual bool Destroy() override;

    virtual void SetPosition(const int32_t x, const int32_t y) override;

    virtual void SetSize(const uint32_t width, const uint32_t height) override;

    virtual void SetVisibility(bool show) override;

    virtual void SetForeground() override;

    virtual bool GetNativeHandle(uint32_t id, void** handle) override;

    virtual VkResult CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* pSurface) override;

  private:
    XcbApplication* xcb_application_;
    int32_t         xpos_;
    int32_t         ypos_;
    uint32_t        width_;
    uint32_t        height_;
    xcb_window_t    window_;
    bool            map_complete_;
    bool            resize_complete_;
    xcb_intern_atom_reply_t* atom_wm_delete_window_;
};

class XcbWindowFactory : public format::WindowFactory
{
  public:
    XcbWindowFactory(XcbApplication* application);

    virtual const char* GetSurfaceExtensionName() const override { return VK_KHR_XCB_SURFACE_EXTENSION_NAME; }

    virtual format::Window* Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(VkPhysicalDevice physical_device,
                                                          uint32_t         queue_family_index) override;

  private:
    XcbApplication* xcb_application_;
};

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_APPLICATION_XCB_WINDOW_H