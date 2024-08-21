/*
** Copyright (c) 2021, Arm Limited.
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

#include "application/headless_window.h"
#include "application/application.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

HeadlessWindow::HeadlessWindow(HeadlessContext* headless_context) : headless_context_(headless_context)
{
    assert(headless_context_ != nullptr);
}

HeadlessWindow::~HeadlessWindow() {}

bool HeadlessWindow::Create(const std::string& title,
                            const int32_t      xpos,
                            const int32_t      ypos,
                            const uint32_t     width,
                            const uint32_t     height,
                            bool               force_windowed)
{
    GFXRECON_UNREFERENCED_PARAMETER(title);
    GFXRECON_UNREFERENCED_PARAMETER(xpos);
    GFXRECON_UNREFERENCED_PARAMETER(ypos);
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(force_windowed);

    return true;
}

bool HeadlessWindow::Destroy()
{
    return true;
}

void HeadlessWindow::SetTitle(const std::string& title)
{
    GFXRECON_UNREFERENCED_PARAMETER(title);
}

void HeadlessWindow::SetPosition(const int32_t x, const int32_t y)
{
    GFXRECON_UNREFERENCED_PARAMETER(x);
    GFXRECON_UNREFERENCED_PARAMETER(y);
}

void HeadlessWindow::SetSize(const uint32_t width, const uint32_t height)
{
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
}

void HeadlessWindow::SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform)
{
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(pre_transform);
}

void HeadlessWindow::SetVisibility(bool show)
{
    GFXRECON_UNREFERENCED_PARAMETER(show);
}

void HeadlessWindow::SetForeground() {}

bool HeadlessWindow::GetNativeHandle(HandleType type, void** handle)
{
    GFXRECON_UNREFERENCED_PARAMETER(type);
    GFXRECON_UNREFERENCED_PARAMETER(handle);
    return false;
}

std::string HeadlessWindow::GetWsiExtension() const
{
    return VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME;
}

VkResult HeadlessWindow::CreateSurface(const encode::VulkanInstanceTable* table,
                                       VkInstance                         instance,
                                       VkFlags                            flags,
                                       VkSurfaceKHR*                      pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    if (table != nullptr)
    {
        VkHeadlessSurfaceCreateInfoEXT create_info{ VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT, nullptr, 0 };

        return table->CreateHeadlessSurfaceEXT(instance, &create_info, nullptr, pSurface);
    }

    return VK_ERROR_INITIALIZATION_FAILED;
}

void HeadlessWindow::DestroySurface(const encode::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface)
{
    if (table != nullptr)
    {
        table->DestroySurfaceKHR(instance, surface, nullptr);
    }
}

HeadlessWindowFactory::HeadlessWindowFactory(HeadlessContext* headless_context) : headless_context_(headless_context)
{
    assert(headless_context_ != nullptr);
}

decode::Window* HeadlessWindowFactory::Create(
    const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, bool force_windowed)
{
    assert(headless_context_);
    decode::Window* window      = new HeadlessWindow(headless_context_);
    auto            application = headless_context_->GetApplication();
    assert(application);
    window->Create(application->GetName(), x, y, width, height, force_windowed);
    return window;
}

void HeadlessWindowFactory::Destroy(decode::Window* window)
{
    if (window != nullptr)
    {
        window->Destroy();
        delete window;
    }
}

VkBool32 HeadlessWindowFactory::GetPhysicalDevicePresentationSupport(const encode::VulkanInstanceTable* table,
                                                                     VkPhysicalDevice                   physical_device,
                                                                     uint32_t queue_family_index)
{
    GFXRECON_UNREFERENCED_PARAMETER(table);
    GFXRECON_UNREFERENCED_PARAMETER(physical_device);
    GFXRECON_UNREFERENCED_PARAMETER(queue_family_index);

    return true;
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
