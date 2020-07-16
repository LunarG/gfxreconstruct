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

#ifndef GFXRECON_APPLICATION_XCB_WINDOW_H
#define GFXRECON_APPLICATION_XCB_WINDOW_H

#include "application/xcb_application.h"
#include "decode/window.h"
#include "util/defines.h"

#include <xcb/xcb.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class XcbWindow : public decode::Window
{
  public:
    XcbWindow(XcbApplication* application);

    virtual ~XcbWindow() override;

    xcb_window_t GetWindowId() const { return window_; }

    xcb_atom_t GetDeleteWindowAtom() const { return delete_window_atom_; }

    void MapNotifyReceived(uint32_t sequence, bool visible)
    {
        CheckEventStatus(sequence, XCB_MAP_NOTIFY);
        visible_ = visible;
    }

    void ResizeNotifyReceived(uint32_t sequence, uint32_t width, uint32_t height)
    {
        CheckEventStatus(sequence, XCB_CONFIGURE_NOTIFY);
        width_  = width;
        height_ = height;
    }

    void DestroyNotifyReceived(uint32_t sequence) { CheckEventStatus(sequence, XCB_DESTROY_NOTIFY); }

    virtual bool Create(const std::string& title,
                        const int32_t      xpos,
                        const int32_t      ypos,
                        const uint32_t     width,
                        const uint32_t     height) override;

    virtual bool Destroy() override;

    virtual void SetTitle(const std::string& title) override;

    virtual void SetPosition(const int32_t x, const int32_t y) override;

    virtual void SetSize(const uint32_t width, const uint32_t height) override;

    virtual void
    SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform) override;

    virtual void SetVisibility(bool show) override;

    virtual void SetForeground() override;

    virtual bool GetNativeHandle(HandleType type, void** handle) override;

    virtual VkResult CreateSurface(const encode::InstanceTable* table,
                                   VkInstance                   instance,
                                   VkFlags                      flags,
                                   VkSurfaceKHR*                pSurface) override;

  private:
    void SetFullscreen(bool fullscreen);

    xcb_intern_atom_cookie_t
    SendAtomRequest(xcb_connection_t* connection, const char* name, uint8_t only_if_exists) const;

    xcb_atom_t GetAtomReply(xcb_connection_t* connection, const char* name, xcb_intern_atom_cookie_t cookie) const;

    void InitializeAtoms();

    void CheckEventStatus(uint32_t sequence, uint32_t type);

    bool WaitForEvent(uint32_t sequence, uint32_t type);

  private:
    struct EventInfo
    {
        uint32_t sequence{ 0 };
        uint32_t type{ 0 };
        bool     complete{ false };
    };

  private:
    XcbApplication* xcb_application_;
    uint32_t        width_;
    uint32_t        height_;
    uint32_t        screen_width_;
    uint32_t        screen_height_;
    EventInfo       pending_event_;
    bool            visible_;
    bool            fullscreen_;
    xcb_window_t    window_;
    xcb_atom_t      protocol_atom_;
    xcb_atom_t      delete_window_atom_;
    xcb_atom_t      state_atom_;
    xcb_atom_t      state_fullscreen_atom_;
    xcb_atom_t      bypass_compositor_atom_;
};

class XcbWindowFactory : public decode::WindowFactory
{
  public:
    XcbWindowFactory(XcbApplication* application);

    virtual const char* GetSurfaceExtensionName() const override { return VK_KHR_XCB_SURFACE_EXTENSION_NAME; }

    virtual decode::Window*
    Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    void Destroy(decode::Window* window) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                          VkPhysicalDevice             physical_device,
                                                          uint32_t                     queue_family_index) override;

  private:
    XcbApplication* xcb_application_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_XCB_WINDOW_H