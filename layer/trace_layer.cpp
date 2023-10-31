/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#include "project_version.h"

#include "layer/trace_layer.h"

#include "encode/custom_layer_func_table.h"
#include "encode/vulkan_capture_manager.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "generated/generated_layer_func_table.h"
#include "generated/generated_vulkan_api_call_encoders.h"
#include "util/platform.h"

#include "vulkan/vk_layer.h"

#include <array>
#include <cstring>
#include <mutex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

const VkLayerProperties kLayerProps = {
    GFXRECON_PROJECT_LAYER_NAME,
    VK_HEADER_VERSION_COMPLETE,
    VK_MAKE_VERSION(GFXRECON_PROJECT_VERSION_MAJOR, GFXRECON_PROJECT_VERSION_MINOR, GFXRECON_PROJECT_VERSION_PATCH),
    GFXRECON_PROJECT_DESCRIPTION
    " Version " GFXRECON_VERSION_STR(GFXRECON_PROJECT_VERSION_MAJOR) "." GFXRECON_VERSION_STR(
        GFXRECON_PROJECT_VERSION_MINOR) "." GFXRECON_VERSION_STR(GFXRECON_PROJECT_VERSION_PATCH)
        GFXRECON_PROJECT_VERSION_DESIGNATION
};

struct LayerExtensionProps
{
    VkExtensionProperties    props;
    std::vector<std::string> instance_funcs;
    std::vector<std::string> device_funcs;
};

const std::vector<struct LayerExtensionProps> kDeviceExtensionProps = {
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
const char* const kUnsupportedDeviceExtensions[] = { VK_AMDX_SHADER_ENQUEUE_EXTENSION_NAME,
                                                     VK_EXT_DESCRIPTOR_BUFFER_EXTENSION_NAME,
                                                     VK_EXT_PIPELINE_PROPERTIES_EXTENSION_NAME,
                                                     VK_EXT_SHADER_MODULE_IDENTIFIER_EXTENSION_NAME,
                                                     VK_HUAWEI_SUBPASS_SHADING_EXTENSION_NAME,
                                                     VK_NVX_BINARY_IMPORT_EXTENSION_NAME,
                                                     VK_NVX_BINARY_IMPORT_EXTENSION_NAME,
                                                     VK_NV_COPY_MEMORY_INDIRECT_EXTENSION_NAME,
                                                     VK_NV_LOW_LATENCY_2_EXTENSION_NAME,
                                                     VK_NV_MEMORY_DECOMPRESSION_EXTENSION_NAME,
                                                     VK_VALVE_DESCRIPTOR_SET_HOST_MAPPING_EXTENSION_NAME,
                                                     VK_NV_CUDA_KERNEL_LAUNCH_EXTENSION_NAME };

static void remove_extensions(std::vector<VkExtensionProperties>& extensionProps,
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

static const VkLayerInstanceCreateInfo* get_instance_chain_info(const VkInstanceCreateInfo* pCreateInfo,
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

static const VkLayerDeviceCreateInfo* get_device_chain_info(const VkDeviceCreateInfo* pCreateInfo, VkLayerFunction func)
{
    const VkLayerDeviceCreateInfo* chain_info = reinterpret_cast<const VkLayerDeviceCreateInfo*>(pCreateInfo->pNext);

    while (chain_info &&
           ((chain_info->sType != VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO) || (chain_info->function != func)))
    {
        chain_info = reinterpret_cast<const VkLayerDeviceCreateInfo*>(chain_info->pNext);
    }

    return chain_info;
}

static std::mutex                                  instance_handles_lock;
static std::unordered_map<const void*, VkInstance> instance_handles;

static void add_instance_handle(VkInstance instance)
{
    // Store the instance for use with vkCreateDevice.
    std::lock_guard<std::mutex> lock(instance_handles_lock);
    instance_handles[encode::GetDispatchKey(instance)] = instance;
}

static VkInstance get_instance_handle(const void* handle)
{
    std::lock_guard<std::mutex> lock(instance_handles_lock);
    auto                        entry = instance_handles.find(encode::GetDispatchKey(handle));
    return (entry != instance_handles.end()) ? entry->second : VK_NULL_HANDLE;
}

// The GetPhysicalDeviceProcAddr of the next layer in the chain.
// Retrieved during instance creation and forwarded to by this layer's
// GetPhysicalDeviceProcAddr() after unwrapping its VkInstance parameter.
static std::mutex                                                    gpdpa_lock;
static std::unordered_map<VkInstance, PFN_GetPhysicalDeviceProcAddr> next_gpdpa;

static void set_instance_next_gpdpa(const VkInstance instance, PFN_GetPhysicalDeviceProcAddr p_next_gpdpa)
{
    GFXRECON_ASSERT(instance != VK_NULL_HANDLE);
    std::lock_guard<std::mutex> lock(gpdpa_lock);
    next_gpdpa[instance] = p_next_gpdpa;
}

static PFN_GetPhysicalDeviceProcAddr get_instance_next_gpdpa(const VkInstance instance)
{
    GFXRECON_ASSERT(instance != VK_NULL_HANDLE);
    std::lock_guard<std::mutex> lock(gpdpa_lock);
    auto                        it_gpdpa = next_gpdpa.find(instance);
    if (it_gpdpa == next_gpdpa.end())
    {
        return nullptr;
    }
    return it_gpdpa->second;
}

VKAPI_ATTR VkResult VKAPI_CALL dispatch_CreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       VkInstance*                  pInstance)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    VkLayerInstanceCreateInfo* chain_info =
        const_cast<VkLayerInstanceCreateInfo*>(get_instance_chain_info(pCreateInfo, VK_LAYER_LINK_INFO));

    if (chain_info && chain_info->u.pLayerInfo)
    {
        PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;

        if (fpGetInstanceProcAddr)
        {
            PFN_vkCreateInstance fpCreateInstance =
                reinterpret_cast<PFN_vkCreateInstance>(fpGetInstanceProcAddr(VK_NULL_HANDLE, "vkCreateInstance"));

            if (fpCreateInstance)
            {
                // Advance the link info for the next element on the chain
                auto pLayerInfo          = chain_info->u.pLayerInfo;
                chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;

                result = fpCreateInstance(pCreateInfo, pAllocator, pInstance);

                if ((result == VK_SUCCESS) && pInstance && (*pInstance != nullptr))
                {
                    add_instance_handle(*pInstance);
                    VkInstance unwrapped_instance = *pInstance;

                    encode::VulkanCaptureManager* manager = encode::VulkanCaptureManager::Get();
                    assert(manager != nullptr);
                    manager->InitVkInstance(pInstance, fpGetInstanceProcAddr);

                    // Register the next layer's GetPhysicalDeviceProcAddr func only after *pInstance
                    // has been updated to our wrapper in manager->InitVkInstance() above:
                    auto fpNextGetPhysicalDeviceProcAddr = reinterpret_cast<PFN_GetPhysicalDeviceProcAddr>(
                        fpGetInstanceProcAddr(unwrapped_instance, "vk_layerGetPhysicalDeviceProcAddr"));
                    set_instance_next_gpdpa(*pInstance, fpNextGetPhysicalDeviceProcAddr);
                }
            }
        }
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL dispatch_CreateDevice(VkPhysicalDevice             physicalDevice,
                                                     const VkDeviceCreateInfo*    pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator,
                                                     VkDevice*                    pDevice)
{
    VkResult                 result = VK_ERROR_INITIALIZATION_FAILED;
    VkLayerDeviceCreateInfo* chain_info =
        const_cast<VkLayerDeviceCreateInfo*>(get_device_chain_info(pCreateInfo, VK_LAYER_LINK_INFO));

    if (chain_info && chain_info->u.pLayerInfo)
    {
        VkInstance layer_instance = get_instance_handle(physicalDevice);

        PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
        PFN_vkGetDeviceProcAddr   fpGetDeviceProcAddr   = chain_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;

        if (fpGetInstanceProcAddr && fpGetDeviceProcAddr && layer_instance)
        {
            PFN_vkCreateDevice fpCreateDevice =
                reinterpret_cast<PFN_vkCreateDevice>(fpGetInstanceProcAddr(layer_instance, "vkCreateDevice"));

            if (fpCreateDevice)
            {
                // Advance the link info for the next element on the chain
                chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;

                result = fpCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);

                if ((result == VK_SUCCESS) && pDevice && (*pDevice != nullptr))
                {
                    encode::VulkanCaptureManager* manager = encode::VulkanCaptureManager::Get();
                    assert(manager != nullptr);
                    manager->InitVkDevice(pDevice, fpGetDeviceProcAddr);
                }
            }
        }
    }

    return result;
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetInstanceProcAddr(VkInstance instance, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;

    // This is required by the loader and is called directly with an "instance" actually
    // set to the internal "loader_instance".  Detect that case and return
    if (!strcmp(pName, "vkCreateInstance"))
    {
        return reinterpret_cast<PFN_vkVoidFunction>(encode::CreateInstance);
    }

    bool has_implementation = false;

    // Check for implementation in the next level
    if (instance != VK_NULL_HANDLE)
    {
        auto table = encode::GetInstanceTable(instance);
        if ((table != nullptr) && (table->GetInstanceProcAddr != nullptr))
        {
            has_implementation = (table->GetInstanceProcAddr(instance, pName) != nullptr);
        }
    }

    // Check for implementation in the layer itself
    if (!has_implementation)
    {
        for (const auto ext_props : kDeviceExtensionProps)
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
        const auto entry = func_table.find(pName);

        if (entry != func_table.end())
        {
            result = entry->second;
        }
    }

    // Lastly check custom GFXR exposed functions
    if (result == nullptr)
    {
        const auto entry = custom_func_table.find(pName);

        if (entry != custom_func_table.end())
        {
            result = entry->second;
        }
    }

    return result;
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetDeviceProcAddr(VkDevice device, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;

    if (device != VK_NULL_HANDLE)
    {
        bool has_implementation = false;

        // Check for implementation in the next level
        auto table = encode::GetDeviceTable(device);
        if ((table != nullptr) && (table->GetDeviceProcAddr != nullptr))
        {
            has_implementation = (table->GetDeviceProcAddr(device, pName) != nullptr);
        }

        // Check for implementation in the layer itself
        if (!has_implementation)
        {
            for (const auto ext_props : kDeviceExtensionProps)
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
            const auto entry = func_table.find(pName);
            if (entry != func_table.end())
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
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetPhysicalDeviceProcAddr(VkInstance ourInstanceWrapper, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;

    if (ourInstanceWrapper != VK_NULL_HANDLE)
    {
        PFN_GetPhysicalDeviceProcAddr next_gpdpa = get_instance_next_gpdpa(ourInstanceWrapper);
        if (next_gpdpa != nullptr)
        {
            result = next_gpdpa(ourInstanceWrapper, pName);
        }
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceExtensionProperties(VkPhysicalDevice       physicalDevice,
                                                                  const char*            pLayerName,
                                                                  uint32_t*              pPropertyCount,
                                                                  VkExtensionProperties* pProperties)
{
    VkResult result = VK_SUCCESS;

    if ((pLayerName != nullptr) && (util::platform::StringCompare(pLayerName, kLayerProps.layerName) == 0))
    {
        if (pPropertyCount != nullptr)
        {
            uint32_t extension_count = static_cast<uint32_t>(kDeviceExtensionProps.size());

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
                    pProperties[i] = kDeviceExtensionProps[i].props;
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
        auto     instance_table            = encode::GetInstanceTable(physicalDevice);
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

        remove_extensions(device_extension_properties,
                          kUnsupportedDeviceExtensions,
                          std::end(kUnsupportedDeviceExtensions) - std::begin(kUnsupportedDeviceExtensions));

        // Append the extensions we provide in the list to the caller if they aren't already provided downstream.
        if (pLayerName == nullptr)
        {
            for (auto& provided_prop : kDeviceExtensionProps)
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

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceExtensionProperties(const char*            pLayerName,
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

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceLayerProperties(uint32_t*          pPropertyCount,
                                                                VkLayerProperties* pProperties)
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

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                              uint32_t*          pPropertyCount,
                                                              VkLayerProperties* pProperties)
{
    GFXRECON_UNREFERENCED_PARAMETER(physicalDevice);
    return EnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}

GFXRECON_END_NAMESPACE(gfxrecon)

// To be safe, we extern "C" these items to remove name mangling for all the items we want to export for Android and old
// loaders to find.
extern "C"
{

    VKAPI_ATTR VkResult VKAPI_CALL vkNegotiateLoaderLayerInterfaceVersion(VkNegotiateLayerInterface* pVersionStruct)
    {
        assert(pVersionStruct != NULL);
        assert(pVersionStruct->sType == LAYER_NEGOTIATE_INTERFACE_STRUCT);

        // Fill in the function pointers if our version is at least capable of having the structure contain them.
        if (pVersionStruct->loaderLayerInterfaceVersion >= 2)
        {
            pVersionStruct->pfnGetInstanceProcAddr       = gfxrecon::GetInstanceProcAddr;
            pVersionStruct->pfnGetDeviceProcAddr         = gfxrecon::GetDeviceProcAddr;
            pVersionStruct->pfnGetPhysicalDeviceProcAddr = gfxrecon::GetPhysicalDeviceProcAddr;
        }

        if (pVersionStruct->loaderLayerInterfaceVersion > CURRENT_LOADER_LAYER_INTERFACE_VERSION)
        {
            pVersionStruct->loaderLayerInterfaceVersion = CURRENT_LOADER_LAYER_INTERFACE_VERSION;
        }

        return VK_SUCCESS;
    }

    // The following two functions are not directly invoked by the desktop loader, which instead uses the function
    // pointers returned by the negotiate function.
    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char* pName)
    {
        return gfxrecon::GetInstanceProcAddr(instance, pName);
    }

    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice device, const char* pName)
    {
        return gfxrecon::GetDeviceProcAddr(device, pName);
    }

    // The following four functions are not invoked by the desktop loader, which retrieves the layer specific properties
    // and extensions from both the layer's JSON file and during the negotiation process.
    VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(VkPhysicalDevice       physicalDevice,
                                                                        const char*            pLayerName,
                                                                        uint32_t*              pPropertyCount,
                                                                        VkExtensionProperties* pProperties)
    {
        assert(physicalDevice == VK_NULL_HANDLE);
        return gfxrecon::EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                          uint32_t*              pPropertyCount,
                                                                          VkExtensionProperties* pProperties)
    {
        return gfxrecon::EnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t*          pPropertyCount,
                                                                      VkLayerProperties* pProperties)
    {
        return gfxrecon::EnumerateInstanceLayerProperties(pPropertyCount, pProperties);
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                                    uint32_t*          pPropertyCount,
                                                                    VkLayerProperties* pProperties)
    {
        assert(physicalDevice == VK_NULL_HANDLE);
        return gfxrecon::EnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
    }

} // extern "C"
