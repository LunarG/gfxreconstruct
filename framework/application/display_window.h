/*
** Copyright (c) 2021 Broadcom, Inc.
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_APPLICATION_DISPLAY_WINDOW_H
#define GFXRECON_APPLICATION_DISPLAY_WINDOW_H

#include "application/display_context.h"
#include "decode/window.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class DisplayWindow : public decode::Window
{
  public:
    DisplayWindow(DisplayContext* display_context);

    virtual ~DisplayWindow() override {}

    virtual bool Create(const std::string&,
                        const int32_t,
                        const int32_t,
                        const uint32_t,
                        const uint32_t,
                        bool force_windowed = false) override
    {
        return true;
    }

    virtual bool Destroy() override { return true; }

    virtual void SetTitle(const std::string&) override {}

    virtual void SetPosition(const int32_t, const int32_t) override {}

    virtual void SetSize(const uint32_t, const uint32_t) override{};

    virtual void SetSizePreTransform(const uint32_t, const uint32_t, const uint32_t) override{};

    virtual void SetVisibility(bool) override {}

    virtual void SetForeground() override {}

    virtual bool GetNativeHandle(HandleType, void**) override { return false; }

    virtual std::string GetWsiExtension() const override;

    virtual VkResult CreateSurface(const encode::VulkanInstanceTable* table,
                                   VkInstance                         instance,
                                   VkFlags                            flags,
                                   VkSurfaceKHR*                      pSurface) override;

    virtual void
    DestroySurface(const encode::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface) override;

  private:
    VkResult SelectPhysicalDevice(const encode::VulkanInstanceTable* table,
                                  VkInstance                         instance,
                                  VkPhysicalDevice*                  physical_device) const;
    VkResult SelectDisplay(const encode::VulkanInstanceTable* table,
                           VkPhysicalDevice                   physical_device,
                           VkDisplayKHR*                      display) const;
    VkResult SelectMode(const encode::VulkanInstanceTable* table,
                        VkPhysicalDevice                   physical_device,
                        VkDisplayKHR                       display,
                        VkDisplayModePropertiesKHR*        mode_props) const;
    VkResult SelectPlane(const encode::VulkanInstanceTable* table,
                         VkPhysicalDevice                   physical_device,
                         VkDisplayKHR                       display,
                         uint32_t*                          plane_index,
                         VkDisplayPlanePropertiesKHR*       plane_props) const;

  private:
    DisplayContext* display_context_;
};

class DisplayWindowFactory : public decode::WindowFactory
{
  public:
    DisplayWindowFactory(DisplayContext* display_context);

    virtual ~DisplayWindowFactory();

    virtual const char* GetSurfaceExtensionName() const override { return VK_KHR_DISPLAY_EXTENSION_NAME; }

    virtual decode::Window* Create(const int32_t  x,
                                   const int32_t  y,
                                   const uint32_t width,
                                   const uint32_t height,
                                   bool           force_windowed = false) override;

    void Destroy(decode::Window* window) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(const encode::VulkanInstanceTable* table,
                                                          VkPhysicalDevice                   physical_device,
                                                          uint32_t queue_family_index) override;

  private:
    DisplayContext* display_context_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_DISPLAY_WINDOW_H
