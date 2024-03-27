/*
 ** Copyright (c) 2023 Codeweavers, Inc.
 ** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_APPLICATION_METAL_WINDOW_H
#define GFXRECON_APPLICATION_METAL_WINDOW_H

#include "decode/window.h"

#include <AppKit/AppKit.h>

@class GFXReconWindowDelegate;

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class MetalContext;
class MetalWindow : public decode::Window
{
public:
    MetalWindow(MetalContext* metal_context);

    ~MetalWindow() override;

    bool Create(const std::string& title,
                const int32_t      xpos,
                const int32_t      ypos,
                const uint32_t     width,
                const uint32_t     height) override;

    bool Destroy() override;

    void SetTitle(const std::string& title) override;

    void SetPosition(const int32_t x, const int32_t y) override;

    void SetSize(const uint32_t width, const uint32_t height) override;

    void SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform) override;

    void SetVisibility(bool show) override;

    void SetForeground() override;

    bool GetNativeHandle(HandleType type, void** handle) override;

    std::string GetWsiExtension() const override;

    VkResult CreateSurface(const encode::VulkanInstanceTable* table,
                           VkInstance                         instance,
                           VkFlags                            flags,
                           VkSurfaceKHR*                      pSurface) override;

    void DestroySurface(const encode::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface) override;

  private:
    GFXReconWindowDelegate* window_delegate_;
    MetalContext* metal_context_;
    NSWindow*     window_;
    CAMetalLayer* layer_;
    uint32_t      width_;
    uint32_t      height_;
};

class MetalWindowFactory : public decode::WindowFactory
{
public:
    MetalWindowFactory(MetalContext* metal_context);

    const char* GetSurfaceExtensionName() const override { return VK_EXT_METAL_SURFACE_EXTENSION_NAME; }

    decode::Window* Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    void Destroy(decode::Window* window) override;

    VkBool32 GetPhysicalDevicePresentationSupport(const encode::VulkanInstanceTable* table,
                                                  VkPhysicalDevice                   physical_device,
                                                  uint32_t                           queue_family_index) override;

  private:
    MetalContext* metal_context_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_METAL_WINDOW_H
