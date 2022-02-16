/*
** Copyright (c) 2018,2020 Valve Corporation
** Copyright (c) 2018,2020 LunarG, Inc.
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

#ifndef GFXRECON_APPLICATION_XCB_WINDOW_H
#define GFXRECON_APPLICATION_XCB_WINDOW_H

#include "application/xcb_context.h"
#include "decode/window.h"
#include "util/defines.h"

#include <xcb/xcb.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class XcbWindow : public decode::Window
{
  public:
    XcbWindow(XcbContext* xcb_context);

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

    virtual std::string GetWsiExtension() const override;

    virtual VkResult CreateSurface(const encode::InstanceTable* table,
                                   VkInstance                   instance,
                                   VkFlags                      flags,
                                   VkSurfaceKHR*                pSurface) override;

    virtual void DestroySurface(const encode::InstanceTable* table, VkInstance instance, VkSurfaceKHR surface) override;

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
    XcbContext*  xcb_context_;
    uint32_t     width_;
    uint32_t     height_;
    uint32_t     screen_width_;
    uint32_t     screen_height_;
    EventInfo    pending_event_;
    bool         visible_;
    bool         fullscreen_;
    xcb_window_t window_;
    xcb_atom_t   protocol_atom_;
    xcb_atom_t   delete_window_atom_;
    xcb_atom_t   state_atom_;
    xcb_atom_t   state_fullscreen_atom_;
    xcb_atom_t   bypass_compositor_atom_;
};

class XcbWindowFactory : public decode::WindowFactory
{
  public:
    XcbWindowFactory(XcbContext* xcb_context);

    virtual const char* GetSurfaceExtensionName() const override { return VK_KHR_XCB_SURFACE_EXTENSION_NAME; }

    virtual decode::Window*
    Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    void Destroy(decode::Window* window) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                          VkPhysicalDevice             physical_device,
                                                          uint32_t                     queue_family_index) override;

  private:
    XcbContext* xcb_context_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_XCB_WINDOW_H