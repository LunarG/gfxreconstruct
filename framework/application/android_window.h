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

#ifndef GFXRECON_APPLICATION_ANDROID_WINDOW_H
#define GFXRECON_APPLICATION_ANDROID_WINDOW_H

#include "application/android_application.h"
#include "decode/window.h"
#include "util/defines.h"
#include "util/platform.h"

#include <android_native_app_glue.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class AndroidWindow : public decode::Window
{
  public:
    AndroidWindow(AndroidApplication* application, ANativeWindow* window);

    virtual ~AndroidWindow() override {}

    virtual bool Create(const std::string&, const int32_t, const int32_t, const uint32_t, const uint32_t) override
    {
        return true;
    }

    virtual bool Destroy() override { return true; }

    virtual void SetTitle(const std::string&) override {}

    virtual void SetPosition(const int32_t, const int32_t) override {}

    virtual void SetSize(const uint32_t width, const uint32_t height) override;

    virtual void
    SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform) override;

    virtual void SetVisibility(bool) override {}

    virtual void SetForeground() override {}

    virtual bool GetNativeHandle(HandleType type, void** handle) override;

    virtual VkResult CreateSurface(const encode::InstanceTable* table,
                                   VkInstance                   instance,
                                   VkFlags                      flags,
                                   VkSurfaceKHR*                pSurface) override;

  private:
    AndroidApplication* android_application_;
    ANativeWindow*      window_;
    uint32_t            width_;
    uint32_t            height_;
    uint32_t            pre_transform_;
};

class AndroidWindowFactory : public decode::WindowFactory
{
  public:
    AndroidWindowFactory(AndroidApplication* application);

    virtual ~AndroidWindowFactory();

    virtual const char* GetSurfaceExtensionName() const override { return VK_KHR_ANDROID_SURFACE_EXTENSION_NAME; }

    virtual decode::Window*
    Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    void Destroy(decode::Window* window) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                          VkPhysicalDevice             physical_device,
                                                          uint32_t                     queue_family_index) override;

  private:
    AndroidApplication* android_application_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_ANDROID_WINDOW_H
