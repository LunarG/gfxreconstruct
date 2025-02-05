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

#include "application/display_window.h"
#include "application/application.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

DisplayWindow::DisplayWindow(DisplayContext* display_context) : display_context_(display_context), width_(0), height_(0)
{
    assert(display_context_ != nullptr);
}

VkResult DisplayWindow::SelectPhysicalDevice(const encode::VulkanInstanceTable* table,
                                             VkInstance                         instance,
                                             VkPhysicalDevice*                  physical_device) const
{
    assert(table);
    uint32_t physical_device_count = 0;
    VkResult error                 = table->EnumeratePhysicalDevices(instance, &physical_device_count, nullptr);
    if (error)
    {
        return error;
    }
    if (!physical_device_count)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
    error = table->EnumeratePhysicalDevices(instance, &physical_device_count, physical_devices.data());
    if (error)
    {
        return error;
    }

    // choose a 1st discrete GPU or just the 1st one
    *physical_device = physical_devices[0];
    for (auto device : physical_devices)
    {
        VkPhysicalDeviceProperties properties;
        table->GetPhysicalDeviceProperties(device, &properties);
        if (properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
        {
            *physical_device = device;
            break;
        }
    }

    return VK_SUCCESS;
}

VkResult DisplayWindow::SelectDisplay(const encode::VulkanInstanceTable* table,
                                      VkPhysicalDevice                   physical_device,
                                      VkDisplayKHR*                      display) const
{
    assert(table);
    uint32_t num_displays;
    VkResult error = table->GetPhysicalDeviceDisplayPropertiesKHR(physical_device, &num_displays, nullptr);
    if (error)
    {
        return error;
    }
    if (!num_displays)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    num_displays = 1;
    VkDisplayPropertiesKHR display_properties;
    error = table->GetPhysicalDeviceDisplayPropertiesKHR(physical_device, &num_displays, &display_properties);
    if (error && error != VK_INCOMPLETE)
    {
        return error;
    }

    *display = display_properties.display;
    return VK_SUCCESS;
}

VkResult DisplayWindow::SelectMode(const encode::VulkanInstanceTable* table,
                                   VkPhysicalDevice                   physical_device,
                                   VkDisplayKHR                       display,
                                   VkDisplayModePropertiesKHR*        mode_props) const
{
    assert(table);
    uint32_t num_modes;
    VkResult error = table->GetDisplayModePropertiesKHR(physical_device, display, &num_modes, nullptr);
    if (error)
    {
        return error;
    }
    if (!num_modes)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    num_modes = 1;
    error     = table->GetDisplayModePropertiesKHR(physical_device, display, &num_modes, mode_props);
    if (error && error != VK_INCOMPLETE)
    {
        return error;
    }

    return VK_SUCCESS;
}

VkResult DisplayWindow::SelectPlane(const encode::VulkanInstanceTable* table,
                                    VkPhysicalDevice                   physical_device,
                                    VkDisplayKHR                       display,
                                    uint32_t*                          plane_index,
                                    VkDisplayPlanePropertiesKHR*       plane_props) const
{
    assert(table);
    uint32_t num_planes;
    VkResult error = table->GetPhysicalDeviceDisplayPlanePropertiesKHR(physical_device, &num_planes, nullptr);
    if (error)
    {
        return error;
    }
    if (!num_planes)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    std::vector<VkDisplayPlanePropertiesKHR> plane_properties(num_planes);

    error = table->GetPhysicalDeviceDisplayPlanePropertiesKHR(physical_device, &num_planes, plane_properties.data());
    if (error && error != VK_INCOMPLETE)
    {
        return error;
    }

    for (uint32_t i = 0; i < plane_properties.size(); ++i)
    {
        if ((plane_properties[i].currentDisplay != VK_NULL_HANDLE) && (plane_properties[i].currentDisplay != display))
        {
            continue;
        }

        uint32_t num_supported;
        error = table->GetDisplayPlaneSupportedDisplaysKHR(physical_device, i, &num_supported, nullptr);
        if (error)
        {
            return error;
        }

        if (!num_supported)
        {
            continue;
        }

        std::vector<VkDisplayKHR> supported_displays(num_supported);
        error =
            table->GetDisplayPlaneSupportedDisplaysKHR(physical_device, i, &num_supported, supported_displays.data());
        if (error)
        {
            return error;
        }

        for (uint32_t j = 0; j < num_supported; ++j)
        {
            if (supported_displays[j] == display)
            {
                *plane_index = i;
                *plane_props = plane_properties[i];
                return VK_SUCCESS;
            }
        }
    }
    return VK_ERROR_INITIALIZATION_FAILED;
}

void DisplayWindow::SetSize(const uint32_t width, const uint32_t height)
{
    width_  = width;
    height_ = height;
}

std::string DisplayWindow::GetWsiExtension() const
{
    return VK_KHR_DISPLAY_EXTENSION_NAME;
}

VkExtent2D DisplayWindow::GetSize() const
{
    return { width_, height_ };
}

VkResult DisplayWindow::CreateSurface(const encode::VulkanInstanceTable* table,
                                      VkInstance                         instance,
                                      VkFlags                            flags,
                                      VkSurfaceKHR*                      pSurface)
{
    VkResult error = VK_ERROR_INITIALIZATION_FAILED;
    if (table)
    {
        VkPhysicalDevice physical_device;
        error = SelectPhysicalDevice(table, instance, &physical_device);
        if (error)
        {
            GFXRECON_LOG_ERROR("Failed to select physical device");
            return error;
        }

        VkDisplayKHR display;
        error = SelectDisplay(table, physical_device, &display);
        if (error)
        {
            GFXRECON_LOG_ERROR("Failed to select display");
            return error;
        }

        VkDisplayModePropertiesKHR mode_props;
        error = SelectMode(table, physical_device, display, &mode_props);
        if (error)
        {
            GFXRECON_LOG_ERROR("Failed to select display mode");
            return error;
        }

        uint32_t                    plane_index;
        VkDisplayPlanePropertiesKHR plane_props;
        error = SelectPlane(table, physical_device, display, &plane_index, &plane_props);
        if (error)
        {
            GFXRECON_LOG_ERROR("Failed to select display plane");
            return error;
        }

        width_  = mode_props.parameters.visibleRegion.width;
        height_ = mode_props.parameters.visibleRegion.height;

        VkExtent2D image_extent;
        image_extent.width  = mode_props.parameters.visibleRegion.width;
        image_extent.height = mode_props.parameters.visibleRegion.height;

        VkDisplaySurfaceCreateInfoKHR surface_create_info{ VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR,
                                                           nullptr,
                                                           0,
                                                           mode_props.displayMode,
                                                           plane_index,
                                                           plane_props.currentStackIndex,
                                                           VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR,
                                                           1.0,
                                                           VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR,
                                                           image_extent };
        error = table->CreateDisplayPlaneSurfaceKHR(instance, &surface_create_info, nullptr, pSurface);
        if (error)
        {
            GFXRECON_LOG_ERROR("Failed to create display plane surface");
            return error;
        }
    }
    return error;
}

void DisplayWindow::DestroySurface(const encode::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface)
{
    if (table)
    {
        table->DestroySurfaceKHR(instance, surface, nullptr);
    }
}

DisplayWindowFactory::DisplayWindowFactory(DisplayContext* display_context) : display_context_(display_context)
{
    assert(display_context_);
}

DisplayWindowFactory::~DisplayWindowFactory() {}

decode::Window* DisplayWindowFactory::Create(
    const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, bool force_windowed)
{
    GFXRECON_UNREFERENCED_PARAMETER(x);
    GFXRECON_UNREFERENCED_PARAMETER(y);
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(force_windowed);

    // Display has a single "window" whose lifetime is managed by DisplayContext.
    return display_context_->GetWindow();
}

void DisplayWindowFactory::Destroy(decode::Window* window)
{
    // Display has a single "window" whose lifetime is managed by DisplayContext.
    GFXRECON_UNREFERENCED_PARAMETER(window);
}

VkBool32 DisplayWindowFactory::GetPhysicalDevicePresentationSupport(const encode::VulkanInstanceTable* table,
                                                                    VkPhysicalDevice                   physical_device,
                                                                    uint32_t queue_family_index)
{
    GFXRECON_UNREFERENCED_PARAMETER(table);
    GFXRECON_UNREFERENCED_PARAMETER(physical_device);
    GFXRECON_UNREFERENCED_PARAMETER(queue_family_index);

    return VK_TRUE;
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
