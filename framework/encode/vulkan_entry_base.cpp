/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#include PROJECT_VERSION_HEADER_FILE

#include "encode/vulkan_entry_base.h"

#include "encode/custom_vulkan_layer_func_table.h"
#include "encode/vulkan_capture_manager.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "generated/generated_vulkan_api_call_encoders.h"
#include "util/platform.h"

#include "vulkan/vk_layer.h"
#include "vulkan/vulkan_ohos.h"

#include <array>
#include <cstring>
#include <mutex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanEntryBase* VulkanEntryBase::singleton_ = nullptr;

void VulkanEntryBase::DestroySingleton()
{
    if (singleton_)
    {
        delete singleton_;
        singleton_ = nullptr;
    }
}

const VkLayerProperties VulkanEntryBase::kLayerProps = {
    GFXRECON_PROJECT_VULKAN_LAYER_NAME,
    VK_HEADER_VERSION_COMPLETE,
    VK_MAKE_VERSION(GFXRECON_PROJECT_VERSION_MAJOR, GFXRECON_PROJECT_VERSION_MINOR, GFXRECON_PROJECT_VERSION_PATCH),
    GFXRECON_PROJECT_DESCRIPTION
    " Version " GFXRECON_VERSION_STR(GFXRECON_PROJECT_VERSION_MAJOR) "." GFXRECON_VERSION_STR(
        GFXRECON_PROJECT_VERSION_MINOR) "." GFXRECON_VERSION_STR(GFXRECON_PROJECT_VERSION_PATCH)
        GFXRECON_PROJECT_VERSION_DESIGNATION
};

const std::vector<VulkanEntryBase::VulkanLayerExtensionProps> VulkanEntryBase::kVulkanDeviceExtensionProps = {
    { VkExtensionProperties{ "VK_EXT_tooling_info", 1 }, { "vkGetPhysicalDeviceToolPropertiesEXT" }, {} },
    { VkExtensionProperties{ VK_EXT_DEBUG_MARKER_EXTENSION_NAME, VK_EXT_DEBUG_MARKER_SPEC_VERSION },
      {},
      { "vkCmdDebugMarkerBeginEXT",
        "vkCmdDebugMarkerEndEXT",
        "vkCmdDebugMarkerInsertEXT",
        "vkDebugMarkerSetObjectNameEXT",
        "vkDebugMarkerSetObjectTagEXT" } },
    { VkExtensionProperties{ "VK_ANDROID_frame_boundary", 1 }, {}, { "vkFrameBoundaryANDROID" } },
    { VkExtensionProperties{ "VK_EXT_frame_boundary", 1 }, {}, {} },
};

/// An alphabetical list of device extensions which we do not report upstream if
/// other layers or ICDs expose them to us.
const std::vector<const char*> VulkanEntryBase::kVulkanUnsupportedDeviceExtensions = {
    VK_AMDX_SHADER_ENQUEUE_EXTENSION_NAME,
    VK_ARM_TENSORS_EXTENSION_NAME,
    VK_ARM_DATA_GRAPH_EXTENSION_NAME,
    VK_EXT_DESCRIPTOR_BUFFER_EXTENSION_NAME,
    VK_EXT_PIPELINE_PROPERTIES_EXTENSION_NAME,
    VK_EXT_SHADER_MODULE_IDENTIFIER_EXTENSION_NAME,
    VK_HUAWEI_SUBPASS_SHADING_EXTENSION_NAME,
    VK_NVX_BINARY_IMPORT_EXTENSION_NAME,
    VK_NV_COPY_MEMORY_INDIRECT_EXTENSION_NAME,
    VK_NV_LOW_LATENCY_2_EXTENSION_NAME,
    VK_NV_MEMORY_DECOMPRESSION_EXTENSION_NAME,
    VK_VALVE_DESCRIPTOR_SET_HOST_MAPPING_EXTENSION_NAME,
    VK_NV_CUDA_KERNEL_LAUNCH_EXTENSION_NAME,
    VK_NV_CLUSTER_ACCELERATION_STRUCTURE_EXTENSION_NAME,
    VK_NV_EXTERNAL_COMPUTE_QUEUE_EXTENSION_NAME,
    VK_OHOS_SURFACE_EXTENSION_NAME
};

void VulkanEntryBase::RemoveExtensions(std::vector<VkExtensionProperties>& extensionProps,
                                       const char* const                   screenedExtensions[],
                                       const size_t                        screenedCount)
{
    auto new_end = std::remove_if(
        extensionProps.begin(),
        extensionProps.end(),
        [&screenedExtensions, screenedCount](const VkExtensionProperties& extension) {
            return std::find_if(screenedExtensions, &screenedExtensions[screenedCount], [&extension](auto screened) {
                       return strncmp(extension.extensionName, screened, VK_MAX_EXTENSION_NAME_SIZE) == 0;
                   }) != &screenedExtensions[screenedCount];
        });
    extensionProps.resize(new_end - extensionProps.begin());
}

PFN_vkVoidFunction VulkanEntryBase::GetInstanceProcAddr(VkInstance instance, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;

    // This is required by the loader and is called directly with an "instance" actually
    // set to the internal "loader_instance".  Detect that case and return
    if (!strcmp(pName, "vkCreateInstance"))
    {
        return reinterpret_cast<PFN_vkVoidFunction>(encode::vkCreateInstance);
    }

    bool has_implementation = false;

    // Check for implementation in the next level
    if (instance != VK_NULL_HANDLE)
    {
        auto table = encode::vulkan_wrappers::GetInstanceTable(instance);
        if ((table != nullptr) && (table->GetInstanceProcAddr != nullptr))
        {
            has_implementation = (table->GetInstanceProcAddr(instance, pName) != nullptr);
        }
    }

    // Check for implementation in the layer itself
    if (!has_implementation)
    {
        for (const auto& ext_props : kVulkanDeviceExtensionProps)
        {
            if (std::find(ext_props.instance_funcs.begin(), ext_props.instance_funcs.end(), pName) !=
                ext_props.instance_funcs.end())
            {
                has_implementation = true;
                break;
            }
        }
    }

    // Only intercept the requested function if there is an implementation available, or if
    // the instance handle is null and we can't determine if it is available from the next level.
    if (has_implementation || (instance == VK_NULL_HANDLE))
    {
        const auto entry = vulkan_function_table_.find(pName);

        if (entry != vulkan_function_table_.end())
        {
            result = entry->second;
        }
    }

    return result;
}

PFN_vkVoidFunction VulkanEntryBase::GetDeviceProcAddr(VkDevice device, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;

    if (device != VK_NULL_HANDLE)
    {
        bool has_implementation = false;

        // Check for implementation in the next level
        auto table = encode::vulkan_wrappers::GetDeviceTable(device);
        if ((table != nullptr) && (table->GetDeviceProcAddr != nullptr))
        {
            has_implementation = (table->GetDeviceProcAddr(device, pName) != nullptr);
        }

        // Check for implementation in the layer itself
        if (!has_implementation)
        {
            for (const auto& ext_props : kVulkanDeviceExtensionProps)
            {
                if (std::find(ext_props.device_funcs.begin(), ext_props.device_funcs.end(), pName) !=
                    ext_props.device_funcs.end())
                {
                    has_implementation = true;
                    break;
                }
            }
        }

        // Only intercept the requested function if there is an implementation available
        if (has_implementation)
        {
            const auto entry = vulkan_function_table_.find(pName);
            if (entry != vulkan_function_table_.end())
            {
                result = entry->second;
            }
        }
    }

    return result;
}

/**
 * We don't actually need to do anything for this function,
 * but we do need to unwrap the instance before the downstream layer
 * sees it.
 */
PFN_vkVoidFunction VulkanEntryBase::GetPhysicalDeviceProcAddr(VkInstance ourInstanceWrapper, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;

    if (ourInstanceWrapper != VK_NULL_HANDLE)
    {
        PFN_GetPhysicalDeviceProcAddr vulkan_next_gpdpa = GetNextGPDPA(ourInstanceWrapper);
        if (vulkan_next_gpdpa != nullptr)
        {
            result = vulkan_next_gpdpa(ourInstanceWrapper, pName);
        }
    }

    return result;
}

VkResult VulkanEntryBase::EnumerateDeviceExtensionProperties(VkPhysicalDevice       physicalDevice,
                                                             const char*            pLayerName,
                                                             uint32_t*              pPropertyCount,
                                                             VkExtensionProperties* pProperties)
{
    VkResult result = VK_SUCCESS;

    if ((pLayerName != nullptr) && (util::platform::StringCompare(pLayerName, kLayerProps.layerName) == 0))
    {
        if (pPropertyCount != nullptr)
        {
            uint32_t extension_count = static_cast<uint32_t>(kVulkanDeviceExtensionProps.size());

            if (pProperties == nullptr)
            {
                *pPropertyCount = extension_count;
            }
            else
            {
                if ((*pPropertyCount) < extension_count)
                {
                    result          = VK_INCOMPLETE;
                    extension_count = *pPropertyCount;
                }
                else if ((*pPropertyCount) > extension_count)
                {
                    *pPropertyCount = extension_count;
                }

                for (uint32_t i = 0; i < extension_count; ++i)
                {
                    pProperties[i] = kVulkanDeviceExtensionProps[i].props;
                }
            }
        }
    }
    else
    {
        // If this function was not called with the layer's name, we expect to dispatch down the chain to obtain the ICD
        // provided extensions.
        // In order to screen out unsupported extensions, we always query the chain
        // twice, and remove those that are present from the count.
        auto     instance_table            = encode::vulkan_wrappers::GetInstanceTable(physicalDevice);
        uint32_t downstream_property_count = 0;

        result = instance_table->EnumerateDeviceExtensionProperties(
            physicalDevice, pLayerName, &downstream_property_count, nullptr);
        if (result != VK_SUCCESS)
        {
            return result;
        }

        std::vector<VkExtensionProperties> device_extension_properties(downstream_property_count);
        result = instance_table->EnumerateDeviceExtensionProperties(
            physicalDevice, pLayerName, &downstream_property_count, device_extension_properties.data());
        if (result != VK_SUCCESS)
        {
            return result;
        }

        RemoveExtensions(device_extension_properties,
                         kVulkanUnsupportedDeviceExtensions.data(),
                         std::end(kVulkanUnsupportedDeviceExtensions) - std::begin(kVulkanUnsupportedDeviceExtensions));

        // Append the extensions we provide in the list to the caller if they aren't already provided downstream.
        if (pLayerName == nullptr)
        {
            for (auto& provided_prop : kVulkanDeviceExtensionProps)
            {
                bool append_provided_prop =
                    std::find_if(device_extension_properties.begin(),
                                 device_extension_properties.end(),
                                 [&provided_prop](const VkExtensionProperties& downstream_prop) {
                                     return util::platform::StringCompare(provided_prop.props.extensionName,
                                                                          downstream_prop.extensionName,
                                                                          VK_MAX_EXTENSION_NAME_SIZE) == 0;
                                 }) == device_extension_properties.end();
                if (append_provided_prop)
                {
                    device_extension_properties.push_back(provided_prop.props);
                }
            }
        }

        // Output the reduced count or the reduced extension list:
        if (pProperties == nullptr)
        {
            *pPropertyCount = static_cast<uint32_t>(device_extension_properties.size());
        }
        else
        {
            if (*pPropertyCount < static_cast<uint32_t>(device_extension_properties.size()))
            {
                result = VK_INCOMPLETE;
            }
            *pPropertyCount = std::min(*pPropertyCount, static_cast<uint32_t>(device_extension_properties.size()));
            std::copy(device_extension_properties.begin(),
                      device_extension_properties.begin() + *pPropertyCount,
                      pProperties);
        }
    }

    return result;
}

VkResult VulkanEntryBase::EnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                               uint32_t*              pPropertyCount,
                                                               VkExtensionProperties* pProperties)
{
    VkResult result = VK_SUCCESS;

    if (pLayerName && (util::platform::StringCompare(pLayerName, kLayerProps.layerName) == 0))
    {
        if (pPropertyCount != nullptr)
        {
            *pPropertyCount = 0;
        }
    }
    else
    {
        result = VK_ERROR_LAYER_NOT_PRESENT;
    }

    return result;
}

VkResult VulkanEntryBase::EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties)
{
    VkResult result = VK_SUCCESS;

    if (pProperties == nullptr)
    {
        if (pPropertyCount != nullptr)
        {
            *pPropertyCount = 1;
        }
    }
    else
    {
        if ((pPropertyCount != nullptr) && (*pPropertyCount >= 1))
        {
            util::platform::MemoryCopy(pProperties, sizeof(*pProperties), &kLayerProps, sizeof(kLayerProps));
            *pPropertyCount = 1;
        }
        else
        {
            result = VK_INCOMPLETE;
        }
    }

    return result;
}

VkResult VulkanEntryBase::EnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                         uint32_t*          pPropertyCount,
                                                         VkLayerProperties* pProperties)
{
    GFXRECON_UNREFERENCED_PARAMETER(physicalDevice);
    return EnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}

const VkLayerInstanceCreateInfo* VulkanEntryBase::GetInstanceChainInfo(const VkInstanceCreateInfo* pCreateInfo,
                                                                       VkLayerFunction             func)
{
    const VkLayerInstanceCreateInfo* chain_info =
        reinterpret_cast<const VkLayerInstanceCreateInfo*>(pCreateInfo->pNext);

    while (chain_info &&
           ((chain_info->sType != VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) || (chain_info->function != func)))
    {
        chain_info = reinterpret_cast<const VkLayerInstanceCreateInfo*>(chain_info->pNext);
    }

    return chain_info;
}

const VkLayerDeviceCreateInfo* VulkanEntryBase::GetDeviceChainInfo(const VkDeviceCreateInfo* pCreateInfo,
                                                                   VkLayerFunction           func)
{
    const VkLayerDeviceCreateInfo* chain_info = reinterpret_cast<const VkLayerDeviceCreateInfo*>(pCreateInfo->pNext);

    while (chain_info &&
           ((chain_info->sType != VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO) || (chain_info->function != func)))
    {
        chain_info = reinterpret_cast<const VkLayerDeviceCreateInfo*>(chain_info->pNext);
    }

    return chain_info;
}

void VulkanEntryBase::AddInstanceHandle(VkInstance instance)
{
    // Store the instance for use with vkCreateDevice.
    std::lock_guard<std::mutex> lock(vulkan_instance_handles_lock);
    vulkan_instance_handles[graphics::GetVulkanDispatchKey(instance)] = instance;
}

VkInstance VulkanEntryBase::GetInstanceHandle(const void* handle)
{
    std::lock_guard<std::mutex> lock(vulkan_instance_handles_lock);
    auto                        entry = vulkan_instance_handles.find(graphics::GetVulkanDispatchKey(handle));
    return (entry != vulkan_instance_handles.end()) ? entry->second : VK_NULL_HANDLE;
}

void VulkanEntryBase::SetInstanceNextGPDPA(const VkInstance instance, PFN_GetPhysicalDeviceProcAddr p_vulkan_next_gpdpa)
{
    GFXRECON_ASSERT(instance != VK_NULL_HANDLE);
    std::lock_guard<std::mutex> lock(vulkan_gpdpa_lock);
    vulkan_next_gpdpa[instance] = p_vulkan_next_gpdpa;
}

PFN_GetPhysicalDeviceProcAddr VulkanEntryBase::GetNextGPDPA(const VkInstance instance)
{
    GFXRECON_ASSERT(instance != VK_NULL_HANDLE);
    std::lock_guard<std::mutex> lock(vulkan_gpdpa_lock);
    auto                        it_gpdpa = vulkan_next_gpdpa.find(instance);
    if (it_gpdpa == vulkan_next_gpdpa.end())
    {
        return nullptr;
    }
    return it_gpdpa->second;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
