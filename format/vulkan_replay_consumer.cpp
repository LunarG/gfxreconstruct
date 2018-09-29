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

#include <cstdint>
#include <limits>
#include <unordered_set>

#include "volk.h"

#include "util/logging.h"
#include "util/platform.h"
#include "format/descriptor_update_template_decoder.h"
#include "format/vulkan_enum_util.h"
#include "format/vulkan_replay_consumer.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

const int32_t  kDefaultWindowPositionX = 0;
const int32_t  kDefaultWindowPositionY = 0;
const uint32_t kDefaultWindowWidth     = 320;
const uint32_t kDefaultWindowHeight    = 240;

static std::unordered_set<std::string> kSurfaceExtensions = {
    VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, VK_MVK_IOS_SURFACE_EXTENSION_NAME, VK_MVK_MACOS_SURFACE_EXTENSION_NAME,
    VK_KHR_MIR_SURFACE_EXTENSION_NAME,     VK_NN_VI_SURFACE_EXTENSION_NAME,   VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
    VK_KHR_WIN32_SURFACE_EXTENSION_NAME,   VK_KHR_XCB_SURFACE_EXTENSION_NAME, VK_KHR_XLIB_SURFACE_EXTENSION_NAME
};

VulkanReplayConsumer::VulkanReplayConsumer(WindowFactory* window_factory) : window_factory_(window_factory)
{
    assert(window_factory != nullptr);
}

VulkanReplayConsumer::~VulkanReplayConsumer()
{
    // Destroy any windows that were created for Vulkan surfaces.
    for (const auto& entry : window_map_)
    {
        Window* window = entry.second;

        assert(window != nullptr);

        window->Destroy();
        delete window;
    }
}

void VulkanReplayConsumer::ProcessDisplayMessageCommand(const std::string& message)
{
    BRIMSTONE_LOG_INFO("Trace Message: %s", message.c_str());
}

void VulkanReplayConsumer::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                    uint64_t       offset,
                                                    uint64_t       size,
                                                    const uint8_t* data)
{
    // We need to find the device memory associated with this ID, and then lookup its mapped pointer.
    VkDeviceMemory memory = object_mapper_.MapVkDeviceMemory(memory_id);

    if (memory != VK_NULL_HANDLE)
    {
        auto entry = memory_map_.find(memory);

        if ((entry != memory_map_.end()) && (entry->second != nullptr))
        {
            BRIMSTONE_CHECK_CONVERSION_DATA_LOSS(size_t, size);
            memcpy(static_cast<uint8_t*>(entry->second) + offset, data, static_cast<size_t>(size));
        }
        else
        {
            BRIMSTONE_LOG_WARNING("Skipping memory fill for VkDeviceMemory object that is not mapped (%" PRIx64 ")",
                                  memory_id);
        }
    }
    else
    {
        BRIMSTONE_LOG_WARNING("Skipping memory fill for unrecognized VkDeviceMemory object (%" PRIx64 ")", memory_id);
    }
}

void VulkanReplayConsumer::ProcessResizeWindowCommand(HandleId surface_id, uint32_t width, uint32_t height)
{
    // We need to find the surface associated with this ID, and then lookup its window.
    VkSurfaceKHR surface = object_mapper_.MapVkSurfaceKHR(surface_id);

    if (surface != VK_NULL_HANDLE)
    {
        auto entry = window_map_.find(surface);

        if ((entry != window_map_.end()) && (entry->second != nullptr))
        {
            Window* window = entry->second;
            window->SetSize(width, height);
        }
        else
        {
            BRIMSTONE_LOG_WARNING(
                "Skipping window resize for VkSurface object (%" PRIx64 ") without an associated window", surface_id);
        }
    }
    else
    {
        BRIMSTONE_LOG_WARNING("Skipping window resize for unrecognized VkSurface object (%" PRIx64 ")", surface_id);
    }
}

void VulkanReplayConsumer::RaiseFatalError(const char* message) const
{
    // TODO: Should there be a default action if no error handler has been provided?
    if (fatal_error_handler_ != nullptr)
    {
        fatal_error_handler_(message);
    }
}

void* VulkanReplayConsumer::PreProcessExternalObject(uint64_t object_id, ApiCallId call_id, const char* call_name)
{
    void* object = nullptr;

    if ((call_id == ApiCallId_vkGetPhysicalDeviceWaylandPresentationSupportKHR) ||
        (call_id == ApiCallId_vkGetPhysicalDeviceXcbPresentationSupportKHR))
    {
        // For window system related handles, we put the object ID into the pointer.
        // The dispatch override for the API call will use this ID as a key to the window map.
        // TODO: For x86 builds, we should map the object_id to a 32-bit sequence number that won't be truncated by the
        // cast.
        object = reinterpret_cast<void*>(object_id);
    }
    else
    {
        BRIMSTONE_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                              call_name);
    }

    return object;
}

void VulkanReplayConsumer::PostProcessExternalObject(const PointerDecoder<uint64_t>& object_id,
                                                     void*                           object,
                                                     ApiCallId                       call_id,
                                                     const char*                     call_name)
{
    if (call_id == ApiCallId_vkMapMemory)
    {
        // Mapped memory tracking is handled by mapping the VkDeviceMemory handle to the mapped pointer, rather than
        // mapping the traced pointer address to the mapped pointer.  The memory needs to be tracked by handle so that
        // it can be removed from the unordered_map when memory is unmapped or freed.
    }
    else
    {
        BRIMSTONE_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                              call_name);
    }
}

const VkAllocationCallbacks* VulkanReplayConsumer::GetAllocationCallbacks(
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& original_callbacks)
{
    // Replay does not currently attempt emulate the captured application's use of VkAllocationCallbacks.
    BRIMSTONE_UNREFERENCED_PARAMETER(original_callbacks);
    return nullptr;
}

void VulkanReplayConsumer::CheckResult(const char* func_name, VkResult original, VkResult replay)
{
    if ((original != VK_ERROR_DEVICE_LOST) && (replay == VK_ERROR_DEVICE_LOST))
    {
        // Only raise a fatal error if the device lost error is unique to playback.  If the original application
        // also encountered a device lost error, it may have handled it and continued.
        BRIMSTONE_LOG_FATAL("API call (%s) returned VK_ERROR_DEVICE_LOST.  Replay cannot continue.", func_name);
        RaiseFatalError(
            "Replay has encountered a fatal error and cannot continue (API call returned VK_ERROR_DEVICE_LOST)");
    }
    else
    {
        // Report error when replay result is different than the original result.
        if (original != replay)
        {
            BRIMSTONE_LOG_ERROR("API call (%s) returned value %s that does not match return value from trace file %s.",
                                func_name,
                                enumutil::GetResultValueString(replay),
                                enumutil::GetResultValueString(original));
        }

        // Warn when an API call returned a failure, regardless of original result (excluding fromat not supported
        // results).
        if ((replay < 0) && (replay != VK_ERROR_FORMAT_NOT_SUPPORTED))
        {
            BRIMSTONE_LOG_WARNING("API call (%s) returned error result %s: %s",
                                  func_name,
                                  enumutil::GetResultValueString(replay),
                                  enumutil::GetResultDescription(replay));
        }
    }
}

VkResult VulkanReplayConsumer::CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* surface)
{
    // Create a window for our surface.
    Window* window = window_factory_->Create(
        kDefaultWindowPositionX, kDefaultWindowPositionY, kDefaultWindowWidth, kDefaultWindowHeight);

    if (window == nullptr)
    {
        // Failure to create a window is a fatal error.
        BRIMSTONE_LOG_FATAL("Failed to create a window for use with surface creation.  Replay cannot continue.");
        RaiseFatalError("Replay has encountered a fatal error and cannot continue (window creation failed)");
    }

    VkResult result = window->CreateSurface(instance, flags, surface);

    if ((result == VK_SUCCESS) && (surface != nullptr))
    {
        VkSurfaceKHR key = (*surface);

        assert(window_map_.find(key) == window_map_.end());

        window_map_.insert(std::make_pair(key, window));
    }

    return result;
}

VkResult VulkanReplayConsumer::OverrideCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator,
                                                      VkInstance*                  pInstance)
{
    static bool initialized = false;
    if (!initialized)
    {
        volkInitialize();
        initialized = true;
    }

    // Replace WSI extension in extension list.
    std::vector<const char*> filtered_extensions;
    if ((pCreateInfo != nullptr) && (pCreateInfo->ppEnabledExtensionNames))
    {
        for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; ++i)
        {
            const char* current_extension = pCreateInfo->ppEnabledExtensionNames[i];
            if (kSurfaceExtensions.find(current_extension) != kSurfaceExtensions.end())
            {
                filtered_extensions.push_back(window_factory_->GetSurfaceExtensionName());
            }
            else
            {
                filtered_extensions.push_back(current_extension);
            }
        }
    }

    VkInstanceCreateInfo modified_create_info    = (*pCreateInfo);
    modified_create_info.enabledExtensionCount   = static_cast<uint32_t>(filtered_extensions.size());
    modified_create_info.ppEnabledExtensionNames = filtered_extensions.data();

    VkResult result = vkCreateInstance(&modified_create_info, pAllocator, pInstance);

    if ((pInstance != nullptr) && (result == VK_SUCCESS))
    {
        volkLoadInstance(*pInstance);
    }

    return result;
}

VkResult VulkanReplayConsumer::OverrideCreateDevice(VkPhysicalDevice             physicalDevice,
                                                    const VkDeviceCreateInfo*    pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator,
                                                    VkDevice*                    pDevice)
{
    VkResult result = vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);

    if ((pDevice != nullptr) && (result == VK_SUCCESS))
    {
        // TODO: Per-device dispatch tables.
        volkLoadDevice(*pDevice);
    }

    return result;
}

VkResult VulkanReplayConsumer::OverrideWaitForFences(VkResult       original_result,
                                                     VkDevice       device,
                                                     uint32_t       fenceCount,
                                                     const VkFence* pFences,
                                                     VkBool32       waitAll,
                                                     uint64_t       timeout)
{
    VkResult result;

    if (original_result == VK_SUCCESS)
    {
        // Ensure that wait for fences waits until the fences have been signaled (or error occurs) by changing the
        // timeout to UINT64_MAX.
        result = vkWaitForFences(device, fenceCount, pFences, waitAll, std::numeric_limits<uint64_t>::max());
    }
    else if (original_result == VK_TIMEOUT)
    {
        // Try to get a timeout result with a 0 timeout.
        result = vkWaitForFences(device, fenceCount, pFences, waitAll, 0);
    }
    else
    {
        result = vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
    }

    return result;
}

VkResult VulkanReplayConsumer::OverrideGetQueryPoolResults(VkResult           original_result,
                                                           VkDevice           device,
                                                           VkQueryPool        queryPool,
                                                           uint32_t           firstQuery,
                                                           uint32_t           queryCount,
                                                           size_t             dataSize,
                                                           void*              pData,
                                                           VkDeviceSize       stride,
                                                           VkQueryResultFlags flags)
{
    VkResult result;

    do
    {
        result = vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    } while ((original_result == VK_SUCCESS) && (result == VK_NOT_READY));

    return result;
}

VkResult VulkanReplayConsumer::OverrideMapMemory(VkDevice         device,
                                                 VkDeviceMemory   memory,
                                                 VkDeviceSize     offset,
                                                 VkDeviceSize     size,
                                                 VkMemoryMapFlags flags,
                                                 void**           ppData)
{
    VkResult result = vkMapMemory(device, memory, offset, size, flags, ppData);

    if ((result == VK_SUCCESS) && (ppData != nullptr) && (*ppData != nullptr))
    {
        memory_map_.insert(std::make_pair(memory, (*ppData)));
    }

    return result;
}

void VulkanReplayConsumer::OverrideUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
    memory_map_.erase(memory);

    vkUnmapMemory(device, memory);
}

void VulkanReplayConsumer::OverrideFreeMemory(VkDevice                     device,
                                              VkDeviceMemory               memory,
                                              const VkAllocationCallbacks* pAllocator)
{
    memory_map_.erase(memory);

    vkFreeMemory(device, memory, pAllocator);
}

VkResult
VulkanReplayConsumer::OverrideCreateDescriptorUpdateTemplate(PFN_vkCreateDescriptorUpdateTemplate        func,
                                                             VkDevice                                    device,
                                                             const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                             const VkAllocationCallbacks*                pAllocator,
                                                             VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate)
{
    if (pCreateInfo != nullptr)
    {
        // Modify the layout of the update template entries to match the tight packing performed by the trace encoding.
        // The trace encoding wrote the update template entries as a tightly packed array of VkDescriptorImageInfo
        // values, followed by an array of VkDescriptorBufferInfo values, followed by an array of VkBufferView values.
        VkDescriptorUpdateTemplateCreateInfo override_create_info = (*pCreateInfo);

        std::vector<VkDescriptorUpdateTemplateEntry> entries(
            override_create_info.pDescriptorUpdateEntries,
            (override_create_info.pDescriptorUpdateEntries + override_create_info.descriptorUpdateEntryCount));

        // Count the number of values of each type.
        size_t image_info_count        = 0;
        size_t buffer_info_count       = 0;
        size_t texel_buffer_view_count = 0;

        for (auto entry = entries.begin(); entry != entries.end(); ++entry)
        {
            VkDescriptorType type = entry->descriptorType;

            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                image_info_count += entry->descriptorCount;
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                buffer_info_count += entry->descriptorCount;
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                texel_buffer_view_count += entry->descriptorCount;
            }
            else
            {
                assert(false);
            }
        }

        // Compute start offsets for each type.
        size_t image_info_offset        = 0;
        size_t buffer_info_offset       = image_info_count * sizeof(VkDescriptorImageInfo);
        size_t texel_buffer_view_offset = buffer_info_offset + (buffer_info_count * sizeof(VkDescriptorBufferInfo));

        for (auto entry = entries.begin(); entry != entries.end(); ++entry)
        {
            VkDescriptorType type = entry->descriptorType;

            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                entry->stride = sizeof(VkDescriptorImageInfo);
                entry->offset = image_info_offset;
                image_info_offset += entry->descriptorCount * sizeof(VkDescriptorImageInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                entry->stride = sizeof(VkDescriptorBufferInfo);
                entry->offset = buffer_info_offset;
                buffer_info_offset += entry->descriptorCount * sizeof(VkDescriptorBufferInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                entry->stride = sizeof(VkBufferView);
                entry->offset = texel_buffer_view_offset;
                texel_buffer_view_offset += entry->descriptorCount * sizeof(VkBufferView);
            }
            else
            {
                assert(false);
            }
        }

        override_create_info.pDescriptorUpdateEntries = entries.data();

        return func(device, &override_create_info, pAllocator, pDescriptorUpdateTemplate);
    }
    else
    {
        return func(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    }
}

VkResult VulkanReplayConsumer::OverrideCreateWin32SurfaceKHR(VkInstance                         instance,
                                                             const VkWin32SurfaceCreateInfoKHR* pCreateInfo,
                                                             const VkAllocationCallbacks*       pAllocator,
                                                             VkSurfaceKHR*                      pSurface)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(pAllocator);
    return CreateSurface(instance, pCreateInfo->flags, pSurface);
}

VkBool32 VulkanReplayConsumer::OverrideGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice,
                                                                                    uint32_t         queueFamilyIndex)
{
    return window_factory_->GetPhysicalDevicePresentationSupport(physicalDevice, queueFamilyIndex);
}

VkResult VulkanReplayConsumer::OverrideCreateXcbSurfaceKHR(VkInstance                       instance,
                                                           const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                                           const VkAllocationCallbacks*     pAllocator,
                                                           VkSurfaceKHR*                    pSurface)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(pAllocator);
    return CreateSurface(instance, pCreateInfo->flags, pSurface);
}

VkBool32 VulkanReplayConsumer::OverrideGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice  physicalDevice,
                                                                                  uint32_t          queueFamilyIndex,
                                                                                  xcb_connection_t* connection,
                                                                                  xcb_visualid_t    visual_id)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(connection);
    BRIMSTONE_UNREFERENCED_PARAMETER(visual_id);
    return window_factory_->GetPhysicalDevicePresentationSupport(physicalDevice, queueFamilyIndex);
}

VkResult VulkanReplayConsumer::OverrideCreateWaylandSurfaceKHR(VkInstance                           instance,
                                                               const VkWaylandSurfaceCreateInfoKHR* pCreateInfo,
                                                               const VkAllocationCallbacks*         pAllocator,
                                                               VkSurfaceKHR*                        pSurface)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(pAllocator);
    return CreateSurface(instance, pCreateInfo->flags, pSurface);
}

VkBool32 VulkanReplayConsumer::OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice,
                                                                                      uint32_t         queueFamilyIndex,
                                                                                      struct wl_display* display)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(display);
    return window_factory_->GetPhysicalDevicePresentationSupport(physicalDevice, queueFamilyIndex);
}

void VulkanReplayConsumer::OverrideDestroySurfaceKHR(VkInstance                   instance,
                                                     VkSurfaceKHR                 surface,
                                                     const VkAllocationCallbacks* pAllocator)
{
    vkDestroySurfaceKHR(instance, surface, pAllocator);

    if (surface != nullptr)
    {
        auto entry = window_map_.find(surface);

        if (entry != window_map_.end())
        {
            Window* window = entry->second;

            assert(window != nullptr);

            window->Destroy();
            delete window;
            window_map_.erase(entry);
        }
    }
}

void VulkanReplayConsumer::MapDescriptorUpdateTemplateHandles(const DescriptorUpdateTemplateDecoder& decoder)
{
    size_t image_info_count        = decoder.GetImageInfoCount();
    size_t buffer_info_count       = decoder.GetBufferInfoCount();
    size_t texel_buffer_view_count = decoder.GetTexelBufferViewCount();

    if (image_info_count > 0)
    {
        VkDescriptorImageInfo*               image_info         = decoder.GetImageInfoPointer();
        const Decoded_VkDescriptorImageInfo* decoded_image_info = decoder.GetImageInfoMetaStructPointer();

        assert((image_info != nullptr) && (decoded_image_info != nullptr));
        for (size_t i = 0; i < image_info_count; ++i)
        {
            image_info[i].sampler   = object_mapper_.MapVkSampler(decoded_image_info[i].sampler);
            image_info[i].imageView = object_mapper_.MapVkImageView(decoded_image_info[i].imageView);
        }
    }

    if (buffer_info_count > 0)
    {
        VkDescriptorBufferInfo*               buffer_info         = decoder.GetBufferInfoPointer();
        const Decoded_VkDescriptorBufferInfo* decoded_buffer_info = decoder.GetBufferInfoMetaStructPointer();

        assert((buffer_info != nullptr) && (decoded_buffer_info != nullptr));

        for (size_t i = 0; i < buffer_info_count; ++i)
        {
            buffer_info[i].buffer = object_mapper_.MapVkBuffer(decoded_buffer_info[i].buffer);
        }
    }

    if (texel_buffer_view_count > 0)
    {
        VkBufferView*   texel_buffer_views = decoder.GetTexelBufferViewPointer();
        const HandleId* handle_ids         = decoder.GetTexelBufferViewHandleIdsPointer();

        assert((texel_buffer_views != nullptr) && (handle_ids != nullptr));

        MapHandles<VkBufferView>(handle_ids,
                                 texel_buffer_view_count,
                                 texel_buffer_views,
                                 texel_buffer_view_count,
                                 &VulkanObjectMapper::MapVkBufferView);
    }
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSetWithTemplate(HandleId device,
                                                                     HandleId descriptorSet,
                                                                     HandleId descriptorUpdateTemplate,
                                                                     const DescriptorUpdateTemplateDecoder& pData)
{
    VkDevice                   in_device        = object_mapper_.MapVkDevice(device);
    VkDescriptorSet            in_descriptorSet = object_mapper_.MapVkDescriptorSet(descriptorSet);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate =
        object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(pData);

    Dispatcher<ApiCallId_vkUpdateDescriptorSetWithTemplate, void, PFN_vkUpdateDescriptorSetWithTemplate>::Dispatch(
        this,
        vkUpdateDescriptorSetWithTemplate,
        in_device,
        in_descriptorSet,
        in_descriptorUpdateTemplate,
        pData.GetPointer());
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSetWithTemplateKHR(HandleId commandBuffer,
                                                                         HandleId descriptorUpdateTemplate,
                                                                         HandleId layout,
                                                                         uint32_t set,
                                                                         const DescriptorUpdateTemplateDecoder& pData)
{
    VkCommandBuffer            in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate =
        object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);
    VkPipelineLayout in_layout = object_mapper_.MapVkPipelineLayout(layout);

    MapDescriptorUpdateTemplateHandles(pData);

    Dispatcher<ApiCallId_vkCmdPushDescriptorSetWithTemplateKHR, void, PFN_vkCmdPushDescriptorSetWithTemplateKHR>::
        Dispatch(this,
                 vkCmdPushDescriptorSetWithTemplateKHR,
                 in_commandBuffer,
                 in_descriptorUpdateTemplate,
                 in_layout,
                 set,
                 pData.GetPointer());
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSetWithTemplateKHR(HandleId device,
                                                                        HandleId descriptorSet,
                                                                        HandleId descriptorUpdateTemplate,
                                                                        const DescriptorUpdateTemplateDecoder& pData)
{
    VkDevice                   in_device        = object_mapper_.MapVkDevice(device);
    VkDescriptorSet            in_descriptorSet = object_mapper_.MapVkDescriptorSet(descriptorSet);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate =
        object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(pData);

    Dispatcher<ApiCallId_vkUpdateDescriptorSetWithTemplateKHR, void, PFN_vkUpdateDescriptorSetWithTemplateKHR>::
        Dispatch(this,
                 vkUpdateDescriptorSetWithTemplateKHR,
                 in_device,
                 in_descriptorSet,
                 in_descriptorUpdateTemplate,
                 pData.GetPointer());
}

void VulkanReplayConsumer::Process_vkRegisterObjectsNVX(
    VkResult                                                   returnValue,
    HandleId                                                   device,
    HandleId                                                   objectTable,
    uint32_t                                                   objectCount,
    const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& ppObjectTableEntries,
    const PointerDecoder<uint32_t>&                            pObjectIndices)
{
    VkDevice         in_device         = object_mapper_.MapVkDevice(device);
    VkObjectTableNVX in_objectTable    = object_mapper_.MapVkObjectTableNVX(objectTable);
    const uint32_t*  in_pObjectIndices = reinterpret_cast<const uint32_t*>(pObjectIndices.GetPointer());

    assert(objectCount == ppObjectTableEntries.GetLength());

    VkObjectTableEntryNVX**                     in_ppObjectTableEntries = ppObjectTableEntries.GetPointer();
    const Decoded_VkObjectTableEntryNVX* const* in_ppObjectTableEntries_wrapper =
        ppObjectTableEntries.GetMetaStructPointer();

    // Map the object table entry handles.
    if ((in_ppObjectTableEntries != nullptr) && (in_ppObjectTableEntries_wrapper != nullptr))
    {
        for (size_t i = 0; i < objectCount; ++i)
        {
            if ((in_ppObjectTableEntries[i] != nullptr) && (in_ppObjectTableEntries_wrapper[i] != nullptr))
            {
                VkObjectEntryTypeNVX type = in_ppObjectTableEntries[i]->type;

                if (type == VK_OBJECT_ENTRY_TYPE_DESCRIPTOR_SET_NVX)
                {
                    const Decoded_VkObjectTableDescriptorSetEntryNVX* wrapper =
                        reinterpret_cast<const Decoded_VkObjectTableDescriptorSetEntryNVX*>(
                            in_ppObjectTableEntries_wrapper[i]);
                    VkObjectTableDescriptorSetEntryNVX* value =
                        reinterpret_cast<VkObjectTableDescriptorSetEntryNVX*>(in_ppObjectTableEntries[i]);

                    value->pipelineLayout = object_mapper_.MapVkPipelineLayout(wrapper->pipelineLayout);
                    value->descriptorSet  = object_mapper_.MapVkDescriptorSet(wrapper->descriptorSet);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_PIPELINE_NVX)
                {
                    const Decoded_VkObjectTablePipelineEntryNVX* wrapper =
                        reinterpret_cast<const Decoded_VkObjectTablePipelineEntryNVX*>(
                            in_ppObjectTableEntries_wrapper[i]);
                    VkObjectTablePipelineEntryNVX* value =
                        reinterpret_cast<VkObjectTablePipelineEntryNVX*>(in_ppObjectTableEntries[i]);

                    value->pipeline = object_mapper_.MapVkPipeline(wrapper->pipeline);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_INDEX_BUFFER_NVX)
                {
                    const Decoded_VkObjectTableIndexBufferEntryNVX* wrapper =
                        reinterpret_cast<const Decoded_VkObjectTableIndexBufferEntryNVX*>(
                            in_ppObjectTableEntries_wrapper[i]);
                    VkObjectTableIndexBufferEntryNVX* value =
                        reinterpret_cast<VkObjectTableIndexBufferEntryNVX*>(in_ppObjectTableEntries[i]);

                    value->buffer = object_mapper_.MapVkBuffer(wrapper->buffer);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_VERTEX_BUFFER_NVX)
                {
                    const Decoded_VkObjectTableVertexBufferEntryNVX* wrapper =
                        reinterpret_cast<const Decoded_VkObjectTableVertexBufferEntryNVX*>(
                            in_ppObjectTableEntries_wrapper[i]);
                    VkObjectTableVertexBufferEntryNVX* value =
                        reinterpret_cast<VkObjectTableVertexBufferEntryNVX*>(in_ppObjectTableEntries[i]);

                    value->buffer = object_mapper_.MapVkBuffer(wrapper->buffer);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_PUSH_CONSTANT_NVX)
                {
                    const Decoded_VkObjectTablePushConstantEntryNVX* wrapper =
                        reinterpret_cast<const Decoded_VkObjectTablePushConstantEntryNVX*>(
                            in_ppObjectTableEntries_wrapper[i]);
                    VkObjectTablePushConstantEntryNVX* value =
                        reinterpret_cast<VkObjectTablePushConstantEntryNVX*>(in_ppObjectTableEntries[i]);

                    value->pipelineLayout = object_mapper_.MapVkPipelineLayout(wrapper->pipelineLayout);
                }
                else
                {
                    assert(true);
                    BRIMSTONE_LOG_ERROR("Skipping entry with unrecognized type at ppObjectTableEntries[%d] when "
                                        "processing vkRegisterObjectsNVX",
                                        i);
                }
            }
            else
            {
                BRIMSTONE_LOG_WARNING(
                    "Skipping null entry at ppObjectTableEntries[%d] when processing vkRegisterObjectsNVX", i);
            }
        }
    }

    VkResult replay_result = Dispatcher<ApiCallId_vkRegisterObjectsNVX, VkResult, PFN_vkRegisterObjectsNVX>::Dispatch(
        this,
        returnValue,
        vkRegisterObjectsNVX,
        in_device,
        in_objectTable,
        objectCount,
        in_ppObjectTableEntries,
        in_pObjectIndices);

    CheckResult("vkRegisterObjectsNVX", returnValue, replay_result);
}

#include "generated/generated_api_call_replay_consumer_definitions.inc"

    BRIMSTONE_END_NAMESPACE(format)
    BRIMSTONE_END_NAMESPACE(brimstone)
