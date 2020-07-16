/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "decode/vulkan_replay_consumer_base.h"

#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/resource_util.h"
#include "decode/vulkan_enum_util.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "util/file_path.h"
#include "util/hash.h"
#include "util/platform.h"

#include <cstdint>
#include <limits>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const int32_t  kDefaultWindowPositionX = 0;
const int32_t  kDefaultWindowPositionY = 0;
const uint32_t kDefaultWindowWidth     = 320;
const uint32_t kDefaultWindowHeight    = 240;

const char kUnknownDeviceLabel[] = "<Unknown>";

const std::vector<std::string> kLoaderLibNames = {
#if defined(WIN32)
    "vulkan-1.dll"
#else
    "libvulkan.so.1", "libvulkan.so"
#endif
};

const std::unordered_set<std::string> kSurfaceExtensions = {
    VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, VK_MVK_IOS_SURFACE_EXTENSION_NAME, VK_MVK_MACOS_SURFACE_EXTENSION_NAME,
    VK_KHR_MIR_SURFACE_EXTENSION_NAME,     VK_NN_VI_SURFACE_EXTENSION_NAME,   VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
    VK_KHR_WIN32_SURFACE_EXTENSION_NAME,   VK_KHR_XCB_SURFACE_EXTENSION_NAME, VK_KHR_XLIB_SURFACE_EXTENSION_NAME
};

// Device extensions to enable for trimming state setup, when available.
const std::unordered_set<std::string> kTrimStateSetupDeviceExtensions = { VK_EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME };

static VKAPI_ATTR VkBool32 VKAPI_CALL DebugReportCallback(VkDebugReportFlagsEXT      flags,
                                                          VkDebugReportObjectTypeEXT objectType,
                                                          uint64_t                   object,
                                                          size_t                     location,
                                                          int32_t                    messageCode,
                                                          const char*                pLayerPrefix,
                                                          const char*                pMessage,
                                                          void*                      pUserData)
{
    GFXRECON_UNREFERENCED_PARAMETER(objectType);
    GFXRECON_UNREFERENCED_PARAMETER(object);
    GFXRECON_UNREFERENCED_PARAMETER(location);
    GFXRECON_UNREFERENCED_PARAMETER(messageCode);
    GFXRECON_UNREFERENCED_PARAMETER(pUserData);

    if ((pLayerPrefix != nullptr) && (pMessage != nullptr) &&
        ((flags & VK_DEBUG_REPORT_ERROR_BIT_EXT) == VK_DEBUG_REPORT_ERROR_BIT_EXT))
    {
        GFXRECON_WRITE_CONSOLE("DEBUG REPORT: %s: %s", pLayerPrefix, pMessage);
    }

    return VK_FALSE;
}

static VKAPI_ATTR VkBool32 VKAPI_CALL DebugUtilsCallback(VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
                                                         VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
                                                         const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                         void*                                       pUserData)
{
    GFXRECON_UNREFERENCED_PARAMETER(pUserData);

    if ((pCallbackData != nullptr) && (pCallbackData->pMessageIdName != nullptr) &&
        (pCallbackData->pMessage != nullptr) &&
        ((messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) ==
         VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) &&
        ((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) ==
         VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT))
    {
        GFXRECON_WRITE_CONSOLE("DEBUG MESSENGER: %s: %s", pCallbackData->pMessageIdName, pCallbackData->pMessage);
    }

    return VK_FALSE;
}

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
static uint32_t GetHardwareBufferFormatBpp(uint32_t format)
{
    switch (format)
    {
        case AHARDWAREBUFFER_FORMAT_BLOB:
        case AHARDWAREBUFFER_FORMAT_S8_UINT: // VK_FORMAT_S8_UINT
            return 1;
        case AHARDWAREBUFFER_FORMAT_R5G6B5_UNORM: // VK_FORMAT_R5G6B5_UNORM_PACK16
        case AHARDWAREBUFFER_FORMAT_D16_UNORM:    // VK_FORMAT_D16_UNORM
            return 2;
        case AHARDWAREBUFFER_FORMAT_R8G8B8_UNORM: // VK_FORMAT_R8G8B8_UNORM
            return 3;
        case AHARDWAREBUFFER_FORMAT_R8G8B8A8_UNORM:    // VK_FORMAT_R8G8B8A8_UNORM
        case AHARDWAREBUFFER_FORMAT_R8G8B8X8_UNORM:    // VK_FORMAT_R8G8B8A8_UNORM
        case AHARDWAREBUFFER_FORMAT_R10G10B10A2_UNORM: // VK_FORMAT_A2B10G10R10_UNORM_PACK32
        case AHARDWAREBUFFER_FORMAT_D24_UNORM:         // VK_FORMAT_X8_D24_UNORM_PACK32
        case AHARDWAREBUFFER_FORMAT_D24_UNORM_S8_UINT: // VK_FORMAT_D24_UNORM_S8_UINT
        case AHARDWAREBUFFER_FORMAT_D32_FLOAT:         // VK_FORMAT_D32_SFLOAT
            return 4;
        case AHARDWAREBUFFER_FORMAT_R16G16B16A16_FLOAT: // VK_FORMAT_R16G16B16A16_SFLOAT
        case AHARDWAREBUFFER_FORMAT_D32_FLOAT_S8_UINT:  // VK_FORMAT_D32_SFLOAT_S8_UINT
            return 8;
        default:
            break;
    }

    return 0;
}
#endif

VulkanReplayConsumerBase::VulkanReplayConsumerBase(WindowFactory* window_factory, const ReplayOptions& options) :
    loader_handle_(nullptr), get_instance_proc_addr_(nullptr), create_instance_proc_(nullptr),
    window_factory_(window_factory), options_(options), loading_trim_state_(false)
{
    assert(window_factory != nullptr);
    assert(options.create_resource_allocator != nullptr);
}

VulkanReplayConsumerBase::~VulkanReplayConsumerBase()
{
    for (auto device_id : active_device_ids_)
    {
        auto device_info = object_info_table_.GetDeviceInfo(device_id);

        if (device_info != nullptr)
        {
            VkDevice device = device_info->handle;

            // Idle device before destroying other resources.
            GetDeviceTable(device)->DeviceWaitIdle(device);

            for (auto swapchain : device_info->active_swapchains)
            {
                GetDeviceTable(device)->DestroySwapchainKHR(device, swapchain, nullptr);
            }
        }
    }

    for (auto instance_id : active_instance_ids_)
    {
        auto instance_info = object_info_table_.GetInstanceInfo(instance_id);

        if (instance_info != nullptr)
        {
            VkInstance instance = instance_info->handle;

            for (auto surface : instance_info->active_surfaces)
            {
                GetInstanceTable(instance)->DestroySurfaceKHR(instance, surface, nullptr);
            }
        }
    }

    // Destroy any windows that were created for Vulkan surfaces.
    for (auto window : active_windows_)
    {
        window_factory_->Destroy(window);
    }

    if (loader_handle_ != nullptr)
    {
        util::platform::CloseLibrary(loader_handle_);
    }
}

void VulkanReplayConsumerBase::ProcessStateBeginMarker(uint64_t frame_number)
{
    GFXRECON_LOG_INFO("Loading state for captured frame %" PRId64, frame_number);
    loading_trim_state_ = true;
}

void VulkanReplayConsumerBase::ProcessStateEndMarker(uint64_t frame_number)
{
    GFXRECON_LOG_INFO("Finished loading state for captured frame %" PRId64, frame_number);
    loading_trim_state_ = false;
}

void VulkanReplayConsumerBase::ProcessDisplayMessageCommand(const std::string& message)
{
    GFXRECON_LOG_INFO("Trace Message: %s", message.c_str());
}

void VulkanReplayConsumerBase::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                        uint64_t       offset,
                                                        uint64_t       size,
                                                        const uint8_t* data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    // We need to find the device memory associated with this ID, and then lookup its mapped pointer.
    const DeviceMemoryInfo* memory_info = object_info_table_.GetDeviceMemoryInfo(memory_id);

    if (memory_info != nullptr)
    {
        auto allocator = memory_info->allocator;

        if (allocator != nullptr)
        {
            result = allocator->WriteMappedMemoryRange(memory_info->allocator_data, offset, size, data);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping memory fill for VkDeviceMemory object (ID = %" PRIu64
                                 ") that is not associated with a resource allocator",
                                 memory_id);
        }
    }
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    else
    {
        auto entry = hardware_buffer_memory_info_.find(memory_id);
        if (entry != hardware_buffer_memory_info_.end())
        {
            result = VK_SUCCESS;

            void*                           buffer_data = nullptr;
            const HardwareBufferMemoryInfo& buffer_info = entry->second;

            int lock_result = AHardwareBuffer_lock(
                buffer_info.hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN, -1, nullptr, &buffer_data);

            if (lock_result == 0)
            {
                assert(buffer_data != nullptr);

                if (buffer_info.compatible_strides)
                {
                    // Copy entire range without adjustment.
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
                    size_t copy_size = static_cast<size_t>(size);
                    util::platform::MemoryCopy(static_cast<uint8_t*>(buffer_data) + offset, copy_size, data, copy_size);
                }
                else if (buffer_info.plane_info.size() == 1)
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, offset);

                    size_t data_size         = static_cast<size_t>(size);
                    size_t data_offset       = static_cast<size_t>(offset);
                    size_t capture_row_pitch = buffer_info.plane_info[0].capture_row_pitch;
                    size_t replay_row_pitch  = buffer_info.plane_info[0].replay_row_pitch;

                    resource::CopyImageSubresourceMemory(static_cast<uint8_t*>(buffer_data),
                                                         data,
                                                         data_offset,
                                                         data_size,
                                                         capture_row_pitch,
                                                         capture_row_pitch);
                }
                else
                {
                    // TODO: multi-plane image format support when strides do not match.
                    GFXRECON_LOG_ERROR("Ignoring fill memory command for AHardwareBuffer with multi-plane format and "
                                       "mismatched capture/replay strides (Memory ID = %" PRIu64
                                       "): support not yet implemented",
                                       memory_id);
                }

                lock_result = AHardwareBuffer_unlock(buffer_info.hardware_buffer, nullptr);
                if (lock_result != 0)
                {
                    GFXRECON_LOG_ERROR("AHardwareBuffer_unlock failed for AHardwareBuffer object (Memory ID = %" PRIu64
                                       ")",
                                       memory_id);
                }
            }
            else
            {
                GFXRECON_LOG_ERROR("AHardwareBuffer_lock failed for AHardwareBuffer object (Memory ID = %" PRIu64 ")",
                                   memory_id);
            }
        }
    }
#endif

    if (result == VK_ERROR_MEMORY_MAP_FAILED)
    {
        GFXRECON_LOG_WARNING("Skipping memory fill for VkDeviceMemory object (ID = %" PRIu64 ") that is not mapped",
                             memory_id);
    }
    else if (result == VK_ERROR_INITIALIZATION_FAILED)
    {
        GFXRECON_LOG_WARNING("Skipping memory fill for unrecognized VkDeviceMemory object (ID = %" PRIu64 ")",
                             memory_id);
    }
}

void VulkanReplayConsumerBase::ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    // We need to find the surface associated with this ID, and then lookup its window.
    const SurfaceKHRInfo* surface_info = object_info_table_.GetSurfaceKHRInfo(surface_id);

    if (surface_info != nullptr)
    {
        Window* window = surface_info->window;

        if (window != nullptr)
        {
            window->SetSize(width, height);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping window resize for VkSurface object (ID = %" PRIu64
                                 ") without an associated window",
                                 surface_id);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping window resize for unrecognized VkSurface object (ID = %" PRIu64 ")", surface_id);
    }
}

void VulkanReplayConsumerBase::ProcessResizeWindowCommand2(format::HandleId surface_id,
                                                           uint32_t         width,
                                                           uint32_t         height,
                                                           uint32_t         pre_transform)
{
    // We need to find the surface associated with this ID, and then lookup its window.
    const SurfaceKHRInfo* surface_info = object_info_table_.GetSurfaceKHRInfo(surface_id);

    if (surface_info != nullptr)
    {
        Window* window = surface_info->window;

        if (window != nullptr)
        {
            window->SetSizePreTransform(width, height, pre_transform);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping window resize for VkSurface object (ID = %" PRIu64
                                 ") without an associated window",
                                 surface_id);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping window resize for unrecognized VkSurface object (ID = %" PRIu64 ")", surface_id);
    }
}

void VulkanReplayConsumerBase::ProcessCreateHardwareBufferCommand(
    format::HandleId                                    memory_id,
    uint64_t                                            buffer_id,
    uint32_t                                            format,
    uint32_t                                            width,
    uint32_t                                            height,
    uint32_t                                            stride,
    uint32_t                                            usage,
    uint32_t                                            layers,
    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    assert(hardware_buffers_.find(buffer_id) == hardware_buffers_.end());

    AHardwareBuffer_Desc desc = {};
    desc.format               = format;
    desc.height               = height;
    desc.layers               = layers;
    desc.usage                = usage;
    desc.width                = width;

    // Make sure we can write to the buffer.
    desc.usage |= AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN;

    AHardwareBuffer* buffer = nullptr;
    int              result = AHardwareBuffer_allocate(&desc, &buffer);
    if ((result == 0) && (buffer != nullptr))
    {
        HardwareBufferInfo& ahb_info = hardware_buffers_[buffer_id];
        ahb_info.memory_id           = memory_id;
        ahb_info.hardware_buffer     = buffer;

        void* data = nullptr;
        result     = -1;

        std::vector<format::HardwareBufferPlaneInfo> replay_plane_info;

        // The multi-plane functions are declared for API 26, but are only available to link with API 29.  So, this
        // could be turned into a run-time check dependent on dlsym returning a valid pointer for
        // AHardwareBuffer_lockPlanes.
#if __ANDROID_API__ >= 29
        AHardwareBuffer_Planes ahb_planes;
        result = AHardwareBuffer_lockPlanes(buffer, AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN, -1, nullptr, &ahb_planes);
        if (result == 0)
        {
            data = ahb_planes.planes[0].data;

            for (uint32_t i = 0; i < ahb_planes.planeCount; ++i)
            {
                format::HardwareBufferPlaneInfo ahb_plane_info;
                ahb_plane_info.offset =
                    reinterpret_cast<uint8_t*>(ahb_planes.planes[i].data) - reinterpret_cast<uint8_t*>(data);
                ahb_plane_info.pixel_stride = ahb_planes.planes[i].pixelStride;
                ahb_plane_info.row_pitch    = ahb_planes.planes[i].rowStride;
                replay_plane_info.emplace_back(std::move(ahb_plane_info));
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("AHardwareBuffer_lockPlanes failed: AHardwareBuffer_lock will be used instead");
        }
#endif

        if (result != 0)
        {
            result = AHardwareBuffer_lock(buffer, AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN, -1, nullptr, &data);
        }

        if (result == 0)
        {
            assert(data != nullptr);

            HardwareBufferMemoryInfo& memory_info = hardware_buffer_memory_info_[memory_id];
            memory_info.hardware_buffer           = buffer;
            memory_info.compatible_strides        = true;

            // Check for matching strides.
            if (plane_info.empty() || replay_plane_info.empty())
            {
                uint32_t bpp = GetHardwareBufferFormatBpp(format);

                AHardwareBuffer_describe(buffer, &desc);
                if (stride != desc.stride)
                {
                    memory_info.compatible_strides = false;
                }

                memory_info.plane_info.resize(1);
                memory_info.plane_info[0].capture_offset    = 0;
                memory_info.plane_info[0].replay_offset     = 0;
                memory_info.plane_info[0].capture_row_pitch = bpp * stride;
                memory_info.plane_info[0].replay_row_pitch  = bpp * desc.stride;
            }
            else
            {
                assert(plane_info.size() == replay_plane_info.size());

                size_t layer_count = plane_info.size();

                memory_info.plane_info.resize(layer_count);

                for (size_t i = 0; i < layer_count; ++i)
                {
                    memory_info.plane_info[i].capture_offset    = plane_info[i].offset;
                    memory_info.plane_info[i].replay_offset     = replay_plane_info[i].offset;
                    memory_info.plane_info[i].capture_row_pitch = plane_info[i].row_pitch;
                    memory_info.plane_info[i].replay_row_pitch  = replay_plane_info[i].row_pitch;

                    if ((plane_info[i].offset != replay_plane_info[i].offset) ||
                        (plane_info[i].row_pitch != replay_plane_info[i].row_pitch))
                    {
                        memory_info.compatible_strides = false;
                    }
                }
            }

            result = AHardwareBuffer_unlock(buffer, nullptr);
            if (result != 0)
            {
                GFXRECON_LOG_ERROR("AHardwareBuffer_unlock failed for AHardwareBuffer object (Buffer ID = %" PRIu64
                                   ", Memory ID = %" PRIu64 ")",
                                   buffer_id,
                                   memory_id);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("AHardwareBuffer_lock failed for AHardwareBuffer object (Buffer ID = %" PRIu64
                               ", Memory ID = %" PRIu64 ")",
                               buffer_id,
                               memory_id);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("AHardwareBuffer_allocate failed for AHardwareBuffer object (Buffer ID = %" PRIu64
                           ", Memory ID = %" PRIu64 ")",
                           buffer_id,
                           memory_id);
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(memory_id);
    GFXRECON_UNREFERENCED_PARAMETER(buffer_id);
    GFXRECON_UNREFERENCED_PARAMETER(format);
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(stride);
    GFXRECON_UNREFERENCED_PARAMETER(usage);
    GFXRECON_UNREFERENCED_PARAMETER(layers);
    GFXRECON_UNREFERENCED_PARAMETER(plane_info);
#endif
}

void VulkanReplayConsumerBase::ProcessDestroyHardwareBufferCommand(uint64_t buffer_id)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    auto entry = hardware_buffers_.find(buffer_id);
    if (entry != hardware_buffers_.end())
    {
        AHardwareBuffer_release(entry->second.hardware_buffer);
        hardware_buffer_memory_info_.erase(entry->second.memory_id);
        hardware_buffers_.erase(entry);
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping destroy for unrecognized AHardwareBuffer object (Buffer ID = %" PRIu64 ")",
                             buffer_id);
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(buffer_id);
#endif
}

void VulkanReplayConsumerBase::ProcessSetDevicePropertiesCommand(format::HandleId physical_device_id,
                                                                 uint32_t         api_version,
                                                                 uint32_t         driver_version,
                                                                 uint32_t         vendor_id,
                                                                 uint32_t         device_id,
                                                                 uint32_t         device_type,
                                                                 const uint8_t pipeline_cache_uuid[format::kUuidSize],
                                                                 const std::string& device_name)
{
    PhysicalDeviceInfo* physical_device_info = object_info_table_.GetPhysicalDeviceInfo(physical_device_id);

    if (physical_device_info != nullptr)
    {
        physical_device_info->capture_api_version    = api_version;
        physical_device_info->capture_driver_version = driver_version;
        physical_device_info->capture_vendor_id      = vendor_id;
        physical_device_info->capture_device_id      = device_id;
        physical_device_info->capture_device_type    = static_cast<VkPhysicalDeviceType>(device_type);
        physical_device_info->capture_device_name    = device_name;

        util::platform::MemoryCopy(physical_device_info->capture_pipeline_cache_uuid,
                                   format::kUuidSize,
                                   pipeline_cache_uuid,
                                   format::kUuidSize);
    }
}

void VulkanReplayConsumerBase::ProcessSetDeviceMemoryPropertiesCommand(
    format::HandleId                             physical_device_id,
    const std::vector<format::DeviceMemoryType>& memory_types,
    const std::vector<format::DeviceMemoryHeap>& memory_heaps)
{
    PhysicalDeviceInfo* physical_device_info = object_info_table_.GetPhysicalDeviceInfo(physical_device_id);

    if (physical_device_info != nullptr)
    {
        VkPhysicalDeviceMemoryProperties* memory_properties = &physical_device_info->capture_memory_properties;

        memory_properties->memoryTypeCount = static_cast<uint32_t>(memory_types.size());
        memory_properties->memoryHeapCount = static_cast<uint32_t>(memory_heaps.size());

        for (uint32_t i = 0; i < memory_properties->memoryTypeCount; ++i)
        {
            memory_properties->memoryTypes[i].propertyFlags = memory_types[i].property_flags;
            memory_properties->memoryTypes[i].heapIndex     = memory_types[i].heap_index;
        }

        for (uint32_t i = 0; i < memory_properties->memoryHeapCount; ++i)
        {
            memory_properties->memoryHeaps[i].size  = memory_heaps[i].size;
            memory_properties->memoryHeaps[i].flags = memory_heaps[i].flags;
        }
    }
}

void VulkanReplayConsumerBase::ProcessSetSwapchainImageStateCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_info)
{
    const DeviceInfo*       device_info    = object_info_table_.GetDeviceInfo(device_id);
    const SwapchainKHRInfo* swapchain_info = object_info_table_.GetSwapchainKHRInfo(swapchain_id);

    if ((device_info != nullptr) && (swapchain_info != nullptr))
    {
        assert((device_info->handle != VK_NULL_HANDLE) && (swapchain_info->handle != VK_NULL_HANDLE));

        VkDevice       device    = device_info->handle;
        VkSwapchainKHR swapchain = swapchain_info->handle;

        VkPhysicalDevice physical_device = device_info->parent;
        VkSurfaceKHR     surface         = swapchain_info->surface;
        assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE));

        auto instance_table = GetInstanceTable(physical_device);
        auto device_table   = GetDeviceTable(device);
        assert((instance_table != nullptr) && (device_table != nullptr));

        VkSurfaceCapabilitiesKHR surface_caps;
        uint32_t                 image_count = 0;

        VkResult result =
            instance_table->GetPhysicalDeviceSurfaceCapabilitiesKHR(physical_device, surface, &surface_caps);

        if (result == VK_SUCCESS)
        {
            result = device_table->GetSwapchainImagesKHR(device, swapchain, &image_count, nullptr);
        }

        if (result == VK_SUCCESS)
        {
            // TODO: Handle swapchain image count mismatch on replay.
            assert(image_info.size() == image_count);

            // Determine if it is possible to acquire all images at the same time.
            assert(image_count >= surface_caps.minImageCount);
            uint32_t max_acquired_images = (image_count - surface_caps.minImageCount) + 1;

            if (image_count > max_acquired_images)
            {
                // Cannot acquire all images at the same time.
                ProcessSetSwapchainImageStateQueueSubmit(
                    device, swapchain, swapchain_info->queue_family_index, last_presented_image, image_info);
            }
            else
            {
                ProcessSetSwapchainImageStatePreAcquire(
                    device, swapchain, swapchain_info->queue_family_index, image_info);
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("Failed image initialization for VkSwapchainKHR object (ID = %" PRIu64
                                 ", handle = 0x%" PRIx64 ")",
                                 swapchain_id,
                                 swapchain);
        }
    }
    else
    {
        if (device_info != nullptr)
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkSwapchainKHR object (ID = %" PRIu64 ")",
                                 swapchain_id);
        }
        else if (swapchain_info != nullptr)
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkDevice object (ID = %" PRIu64 ")",
                                 device_id);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkDevice (ID = %" PRIu64
                                 ") and VkSwapchainKHR (ID = %" PRIu64 ") objects",
                                 device_id,
                                 swapchain_id);
        }
    }
}

void VulkanReplayConsumerBase::ProcessSetSwapchainImageStatePreAcquire(
    VkDevice                                            device,
    VkSwapchainKHR                                      swapchain,
    uint32_t                                            queue_family_index,
    const std::vector<format::SwapchainImageStateInfo>& image_info)
{
    auto table = GetDeviceTable(device);
    assert(table != nullptr);

    VkResult        result             = VK_SUCCESS;
    VkQueue         transition_queue   = VK_NULL_HANDLE;
    VkCommandPool   transition_pool    = VK_NULL_HANDLE;
    VkCommandBuffer transition_command = VK_NULL_HANDLE;

    // TODO: Improved queue selection?
    table->GetDeviceQueue(device, queue_family_index, 0, &transition_queue);

    VkCommandPoolCreateInfo pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    pool_create_info.pNext                   = nullptr;
    pool_create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    pool_create_info.queueFamilyIndex        = queue_family_index;

    result = table->CreateCommandPool(device, &pool_create_info, nullptr, &transition_pool);

    if (result == VK_SUCCESS)
    {
        VkCommandBufferAllocateInfo command_allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
        command_allocate_info.pNext                       = nullptr;
        command_allocate_info.commandBufferCount          = 1;
        command_allocate_info.commandPool                 = transition_pool;
        command_allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;

        table->AllocateCommandBuffers(device, &command_allocate_info, &transition_command);
    }

    if (result == VK_SUCCESS)
    {
        VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
        begin_info.pNext                    = nullptr;
        begin_info.flags                    = 0;
        begin_info.pInheritanceInfo         = nullptr;

        VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.pNext              = nullptr;
        submit_info.commandBufferCount = 1;
        submit_info.pCommandBuffers    = &transition_command;

        VkImageMemoryBarrier image_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
        image_barrier.pNext                           = nullptr;
        image_barrier.srcAccessMask                   = 0;
        image_barrier.dstAccessMask                   = 0;
        image_barrier.oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
        image_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        image_barrier.subresourceRange.baseMipLevel   = 0;
        image_barrier.subresourceRange.levelCount     = 1;
        image_barrier.subresourceRange.baseArrayLayer = 0;
        image_barrier.subresourceRange.layerCount     = 1;

        for (size_t i = 0; i < image_info.size(); ++i)
        {
            const ImageInfo* image_entry = object_info_table_.GetImageInfo(image_info[i].image_id);

            // Pre-acquire and transition swapchain images while processing trimming state snapshot.
            if (image_entry != nullptr)
            {
                assert(image_entry->handle != VK_NULL_HANDLE);

                VkImage  image       = image_entry->handle;
                uint32_t image_index = 0;

                VkFence     acquire_fence     = VK_NULL_HANDLE;
                VkSemaphore acquire_semaphore = VK_NULL_HANDLE;

                VkFenceCreateInfo fence_create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
                fence_create_info.pNext             = nullptr;
                fence_create_info.flags             = 0;

                VkSemaphoreCreateInfo semaphore_create_info = { VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
                semaphore_create_info.pNext                 = nullptr;
                semaphore_create_info.flags                 = 0;

                result = table->CreateFence(device, &fence_create_info, nullptr, &acquire_fence);

                if (result == VK_SUCCESS)
                {
                    result = table->CreateSemaphore(device, &semaphore_create_info, nullptr, &acquire_semaphore);
                }

                if (result == VK_SUCCESS)
                {
                    result = table->AcquireNextImageKHR(device,
                                                        swapchain,
                                                        std::numeric_limits<uint64_t>::max(),
                                                        acquire_semaphore,
                                                        acquire_fence,
                                                        &image_index);

                    if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                    {
                        // TODO: Handle case where image acquired at replay does not match image acquired at
                        // capture.
                        assert(image_index == i);

                        result =
                            table->WaitForFences(device, 1, &acquire_fence, true, std::numeric_limits<uint64_t>::max());

                        VkImageLayout image_layout = static_cast<VkImageLayout>(image_info[image_index].image_layout);
                        if ((result == VK_SUCCESS) && (image_layout != VK_IMAGE_LAYOUT_UNDEFINED))
                        {
                            image_barrier.newLayout = image_layout;
                            image_barrier.image     = image;

                            result = table->BeginCommandBuffer(transition_command, &begin_info);

                            if (result == VK_SUCCESS)
                            {
                                table->CmdPipelineBarrier(transition_command,
                                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                          VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                          0,
                                                          0,
                                                          nullptr,
                                                          0,
                                                          nullptr,
                                                          1,
                                                          &image_barrier);
                                table->EndCommandBuffer(transition_command);

                                result = table->ResetFences(device, 1, &acquire_fence);
                            }

                            if (result == VK_SUCCESS)
                            {
                                result = table->QueueSubmit(transition_queue, 1, &submit_info, acquire_fence);
                            }

                            if (result == VK_SUCCESS)
                            {
                                result = table->WaitForFences(
                                    device, 1, &acquire_fence, true, std::numeric_limits<uint64_t>::max());
                            }
                        }

                        if (result == VK_SUCCESS)
                        {
                            if (image_info[image_index].acquired)
                            {
                                // The upcoming frames expect the image to be acquired. The synchronization objects
                                // used to acquire the image were already set to the appropriate signaled state when
                                // created, so the temporary objects used to acquire the image here can be
                                // destroyed.
                                table->DestroyFence(device, acquire_fence, nullptr);
                                table->DestroySemaphore(device, acquire_semaphore, nullptr);
                            }
                            else
                            {
                                // The upcoming frames do not expect the image to be acquired. We will store the
                                // image and the synchronization objects used to acquire it in a data structure.
                                // Replay of vkAcquireNextImage will retrieve and use the stored objects.
                                swapchain_image_tracker_.TrackPreAcquiredImage(
                                    swapchain, image_index, acquire_semaphore, acquire_fence);
                            }
                        }
                        else
                        {
                            GFXRECON_LOG_WARNING("Failed to acquire and transition VkImage object (ID = %" PRIu64
                                                 ") for swapchain state initialization",
                                                 image_info[i].image_id);
                        }
                    }
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkImage object (ID = %" PRIu64 ")",
                                     image_info[i].image_id);
            }
        }
    }
    else
    {
        GFXRECON_LOG_WARNING(
            "Failed to create image initialization resources for VkSwapchainKHR object (handle = 0x%" PRIx64 ")",
            swapchain);
    }

    if (transition_pool != VK_NULL_HANDLE)
    {
        table->DestroyCommandPool(device, transition_pool, nullptr);
    }
}

void VulkanReplayConsumerBase::ProcessSetSwapchainImageStateQueueSubmit(
    VkDevice                                            device,
    VkSwapchainKHR                                      swapchain,
    uint32_t                                            queue_family_index,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_info)
{
    auto table = GetDeviceTable(device);
    assert(table != nullptr);

    VkResult        result     = VK_SUCCESS;
    VkQueue         queue      = VK_NULL_HANDLE;
    VkCommandPool   pool       = VK_NULL_HANDLE;
    VkCommandBuffer command    = VK_NULL_HANDLE;
    VkFence         wait_fence = VK_NULL_HANDLE;

    VkCommandPoolCreateInfo pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    pool_create_info.pNext                   = nullptr;
    pool_create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    pool_create_info.queueFamilyIndex        = queue_family_index;

    // TODO: Improved queue selection?
    table->GetDeviceQueue(device, queue_family_index, 0, &queue);

    result = table->CreateCommandPool(device, &pool_create_info, nullptr, &pool);

    if (result == VK_SUCCESS)
    {
        VkCommandBufferAllocateInfo command_allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
        command_allocate_info.pNext                       = nullptr;
        command_allocate_info.commandBufferCount          = 1;
        command_allocate_info.commandPool                 = pool;
        command_allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;

        result = table->AllocateCommandBuffers(device, &command_allocate_info, &command);
    }

    if (result == VK_SUCCESS)
    {
        VkFenceCreateInfo fence_create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
        fence_create_info.pNext             = nullptr;
        fence_create_info.flags             = VK_FENCE_CREATE_SIGNALED_BIT;

        result = table->CreateFence(device, &fence_create_info, nullptr, &wait_fence);
    }

    if (result == VK_SUCCESS)
    {
        VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
        begin_info.pNext                    = nullptr;
        begin_info.flags                    = 0;
        begin_info.pInheritanceInfo         = nullptr;

        VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.pNext              = nullptr;
        submit_info.commandBufferCount = 1;
        submit_info.pCommandBuffers    = &command;

        VkImageMemoryBarrier image_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
        image_barrier.pNext                           = nullptr;
        image_barrier.srcAccessMask                   = 0;
        image_barrier.dstAccessMask                   = 0;
        image_barrier.oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
        image_barrier.newLayout                       = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        image_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        image_barrier.subresourceRange.baseMipLevel   = 0;
        image_barrier.subresourceRange.levelCount     = 1;
        image_barrier.subresourceRange.baseArrayLayer = 0;
        image_barrier.subresourceRange.layerCount     = 1;

        VkPresentInfoKHR present_info   = { VK_STRUCTURE_TYPE_PRESENT_INFO_KHR };
        present_info.pNext              = nullptr;
        present_info.waitSemaphoreCount = 0;
        present_info.pWaitSemaphores    = nullptr;
        present_info.swapchainCount     = 1;
        present_info.pSwapchains        = &swapchain;
        present_info.pResults           = nullptr;

        // Acquire, transition to the present source layout, and present each image.
        for (size_t i = 0; i < image_info.size(); ++i)
        {
            const ImageInfo* image_entry = object_info_table_.GetImageInfo(image_info[i].image_id);

            if (image_entry != nullptr)
            {
                assert(image_entry->handle != VK_NULL_HANDLE);

                VkImage  image       = image_entry->handle;
                uint32_t image_index = 0;

                result = table->ResetFences(device, 1, &wait_fence);

                if (result == VK_SUCCESS)
                {
                    result = table->AcquireNextImageKHR(device,
                                                        swapchain,
                                                        std::numeric_limits<uint64_t>::max(),
                                                        VK_NULL_HANDLE,
                                                        wait_fence,
                                                        &image_index);
                }

                if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                {
                    // TODO: Handle case where image acquired at replay does not match image acquired at capture.
                    assert(image_index == i);

                    result = table->WaitForFences(device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());

                    if (result == VK_SUCCESS)
                    {
                        image_barrier.image        = image;
                        present_info.pImageIndices = &image_index;

                        result = table->BeginCommandBuffer(command, &begin_info);
                    }

                    if (result == VK_SUCCESS)
                    {
                        table->CmdPipelineBarrier(command,
                                                  VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                  VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                  0,
                                                  0,
                                                  nullptr,
                                                  0,
                                                  nullptr,
                                                  1,
                                                  &image_barrier);
                        table->EndCommandBuffer(command);

                        result = table->ResetFences(device, 1, &wait_fence);
                    }

                    if (result == VK_SUCCESS)
                    {
                        result = table->QueueSubmit(queue, 1, &submit_info, wait_fence);
                    }

                    if (result == VK_SUCCESS)
                    {
                        result =
                            table->WaitForFences(device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());
                    }

                    if (result == VK_SUCCESS)
                    {
                        result = table->QueuePresentKHR(queue, &present_info);
                    }

                    if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                    {
                        result = table->QueueWaitIdle(queue);
                    }
                }

                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("Failed to acquire and transition VkImage object (ID = %" PRIu64
                                         ") for swapchain state initialization",
                                         image_info[i].image_id);
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkImage object (ID = %" PRIu64 ")",
                                     image_info[i].image_id);
            }
        }

        // Second pass to set image acquired state.
        // Acquire all images up to the last presented image, to increase the chance that the first image
        // acquired on replay is the same image acquired by the first captured frame.
        for (size_t i = 0; i < image_info.size(); ++i)
        {
            const ImageInfo* image_entry = object_info_table_.GetImageInfo(image_info[i].image_id);

            if ((image_entry != nullptr) && ((image_info[i].acquired) || (i <= last_presented_image)))
            {
                assert(image_entry->handle != VK_NULL_HANDLE);

                VkImage  image       = image_entry->handle;
                uint32_t image_index = 0;

                result = table->ResetFences(device, 1, &wait_fence);

                if (result == VK_SUCCESS)
                {
                    result = table->AcquireNextImageKHR(device,
                                                        swapchain,
                                                        std::numeric_limits<uint64_t>::max(),
                                                        VK_NULL_HANDLE,
                                                        wait_fence,
                                                        &image_index);
                }

                if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                {
                    // TODO: Handle case where image acquired at replay does not match image acquired at capture.
                    assert(image_index == i);

                    result = table->WaitForFences(device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());

                    if (result == VK_SUCCESS)
                    {
                        if (image_info[i].acquired)
                        {
                            // Transition the image to the expected layout and keep it acquired.
                            VkImageLayout image_layout = static_cast<VkImageLayout>(image_info[i].image_layout);
                            if ((image_layout != VK_IMAGE_LAYOUT_UNDEFINED) &&
                                (image_layout != VK_IMAGE_LAYOUT_PRESENT_SRC_KHR))
                            {

                                image_barrier.newLayout = image_layout;
                                image_barrier.image     = image;

                                result = table->BeginCommandBuffer(command, &begin_info);

                                if (result == VK_SUCCESS)
                                {
                                    table->CmdPipelineBarrier(command,
                                                              VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                              VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                              0,
                                                              0,
                                                              nullptr,
                                                              0,
                                                              nullptr,
                                                              1,
                                                              &image_barrier);
                                    table->EndCommandBuffer(command);

                                    result = table->ResetFences(device, 1, &wait_fence);
                                }

                                if (result == VK_SUCCESS)
                                {
                                    result = table->QueueSubmit(queue, 1, &submit_info, wait_fence);
                                }

                                if (result == VK_SUCCESS)
                                {
                                    result = table->WaitForFences(
                                        device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());
                                }
                            }
                        }
                        else
                        {
                            // Image is not expected to be in the acquired state, so present it.
                            present_info.pImageIndices = &image_index;

                            result = table->QueuePresentKHR(queue, &present_info);

                            if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                            {
                                result = table->QueueWaitIdle(queue);
                            }
                        }
                    }
                }

                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("Failed to acquire and transition VkImage object (ID = %" PRIu64
                                         ") for swapchain state initialization",
                                         image_info[i].image_id);
                }
            }
            else if (image_entry == nullptr)
            {
                GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkImage object (ID = %" PRIu64 ")",
                                     image_info[i].image_id);
            }
        }
    }
    else
    {
        GFXRECON_LOG_WARNING(
            "Failed to create image initialization resources for VkSwapchainKHR object (handle = 0x%" PRIx64 ")",
            swapchain);
    }

    if (pool != VK_NULL_HANDLE)
    {
        table->DestroyCommandPool(device, pool, nullptr);
    }

    if (wait_fence != VK_NULL_HANDLE)
    {
        table->DestroyFence(device, wait_fence, nullptr);
    }
}

void VulkanReplayConsumerBase::ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                               uint64_t         max_resource_size,
                                                               uint64_t         max_copy_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(max_resource_size);

    DeviceInfo* device_info = object_info_table_.GetDeviceInfo(device_id);

    if (device_info != nullptr)
    {
        assert(device_info->handle != VK_NULL_HANDLE);

        VkResult       result = VK_SUCCESS;
        VkDevice       device = device_info->handle;
        VkBuffer       buffer = VK_NULL_HANDLE;
        VkDeviceMemory memory = VK_NULL_HANDLE;

        auto allocator = device_info->allocator.get();
        assert(allocator != nullptr);

        auto table = GetDeviceTable(device);
        assert(table != nullptr);

        VkPhysicalDevice physical_device = device_info->parent;
        assert(physical_device != VK_NULL_HANDLE);

        VkPhysicalDeviceMemoryProperties properties;
        auto                             instance_table = GetInstanceTable(physical_device);
        assert(instance_table != nullptr);

        instance_table->GetPhysicalDeviceMemoryProperties(physical_device, &properties);

        const auto& available_extensions      = device_info->extensions;
        bool        have_shader_stencil_write = false;

        if (std::find(available_extensions.begin(),
                      available_extensions.end(),
                      VK_EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME) != available_extensions.end())
        {
            have_shader_stencil_write = true;
        }

        device_info->resource_initializer = std::make_unique<VulkanResourceInitializer>(
            device, max_copy_size, properties, have_shader_stencil_write, allocator, table);
    }
}

void VulkanReplayConsumerBase::ProcessEndResourceInitCommand(format::HandleId device_id)
{
    DeviceInfo* device_info = object_info_table_.GetDeviceInfo(device_id);

    if ((device_info != nullptr) && (device_info->resource_initializer != nullptr))
    {
        device_info->resource_initializer.reset();
    }
}

void VulkanReplayConsumerBase::ProcessInitBufferCommand(format::HandleId device_id,
                                                        format::HandleId buffer_id,
                                                        uint64_t         data_size,
                                                        const uint8_t*   data)
{
    DeviceInfo*       device_info = object_info_table_.GetDeviceInfo(device_id);
    const BufferInfo* buffer_info = object_info_table_.GetBufferInfo(buffer_id);

    if ((device_info != nullptr) && (buffer_info != nullptr))
    {
        VkResult                   result      = VK_SUCCESS;
        VkDevice                   device      = device_info->handle;
        VkBuffer                   buffer      = buffer_info->handle;
        VulkanResourceInitializer* initializer = device_info->resource_initializer.get();

        assert((device != VK_NULL_HANDLE) && (buffer != VK_NULL_HANDLE));

        if (initializer != nullptr)
        {
            if ((buffer_info->memory_property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) ==
                VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
            {
                assert(buffer_info->memory != VK_NULL_HANDLE);

                result = initializer->LoadData(
                    buffer_info->memory, buffer_info->bind_offset, data_size, data, buffer_info->memory_allocator_data);

                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("State snapshot mapped memory copy failed for VkBuffer object (ID = %" PRIu64
                                         ", handle = 0x%" PRIx64 ")",
                                         buffer_id,
                                         buffer);
                }
            }
            else
            {
                VkBufferCopy copy_region;
                copy_region.srcOffset = 0;
                copy_region.dstOffset = 0;
                copy_region.size      = data_size;

                result = initializer->InitializeBuffer(
                    data_size, data, buffer_info->queue_family_index, buffer, buffer_info->usage, 1, &copy_region);

                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("State snapshot staging buffer copy failed for VkBuffer object (ID = %" PRIu64
                                         ", handle = 0x%" PRIx64 ")",
                                         buffer_id,
                                         buffer);
                }
            }
        }
    }
    else
    {
        if (device_info != nullptr)
        {
            GFXRECON_LOG_WARNING(
                "Skipping state snapshot buffer upload for unrecognized VkBuffer object (ID = %" PRIu64 ")", buffer_id);
        }
        else if (buffer_info != nullptr)
        {
            GFXRECON_LOG_WARNING(
                "Skipping state snapshot buffer upload for unrecognized VkDevice object (ID = %" PRIu64 ")", device_id);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping state snapshot buffer upload for unrecognized VkDevice (ID = %" PRIu64
                                 ") and VkBuffer (ID = %" PRIu64 ") objects",
                                 device_id,
                                 buffer_id);
        }
    }
}

void VulkanReplayConsumerBase::ProcessInitImageCommand(format::HandleId             device_id,
                                                       format::HandleId             image_id,
                                                       uint64_t                     data_size,
                                                       uint32_t                     aspect,
                                                       uint32_t                     layout,
                                                       const std::vector<uint64_t>& level_sizes,
                                                       const uint8_t*               data)
{
    DeviceInfo*      device_info = object_info_table_.GetDeviceInfo(device_id);
    const ImageInfo* image_info  = object_info_table_.GetImageInfo(image_id);

    if ((device_info != nullptr) && (image_info != nullptr))
    {
        VkResult                   result      = VK_SUCCESS;
        VkDevice                   device      = device_info->handle;
        VkImage                    image       = image_info->handle;
        VulkanResourceInitializer* initializer = device_info->resource_initializer.get();

        assert((device != VK_NULL_HANDLE) && (image != VK_NULL_HANDLE));

        if (initializer != nullptr)
        {
            std::vector<VkBufferImageCopy> copy_regions;

            if (data_size > 0)
            {
                if ((image_info->tiling == VK_IMAGE_TILING_LINEAR) &&
                    (image_info->memory_property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) ==
                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                {
                    assert(image_info->memory != VK_NULL_HANDLE);

                    result = initializer->LoadData(image_info->memory,
                                                   image_info->bind_offset,
                                                   data_size,
                                                   data,
                                                   image_info->memory_allocator_data);

                    if (result != VK_SUCCESS)
                    {
                        GFXRECON_LOG_WARNING(
                            "State snapshot mapped memory copy failed for VkImage object (ID = %" PRIu64
                            ", handle = 0x%" PRIx64 ")",
                            image_id,
                            image);
                    }
                }
                else
                {
                    // Create one copy region per mip-level.
                    VkBufferImageCopy copy_region;
                    copy_region.bufferRowLength                 = 0; // Request tightly packed data.
                    copy_region.bufferImageHeight               = 0; // Request tightly packed data.
                    copy_region.bufferOffset                    = 0;
                    copy_region.imageOffset.x                   = 0;
                    copy_region.imageOffset.y                   = 0;
                    copy_region.imageOffset.z                   = 0;
                    copy_region.imageSubresource.aspectMask     = aspect;
                    copy_region.imageSubresource.baseArrayLayer = 0;
                    copy_region.imageSubresource.layerCount     = image_info->layer_count;

                    assert(image_info->level_count == level_sizes.size());

                    for (uint32_t i = 0; i < image_info->level_count; ++i)
                    {
                        copy_region.imageSubresource.mipLevel = i;
                        copy_region.imageExtent.width         = std::max(1u, (image_info->extent.width >> i));
                        copy_region.imageExtent.height        = std::max(1u, (image_info->extent.height >> i));
                        copy_region.imageExtent.depth         = std::max(1u, (image_info->extent.depth >> i));

                        copy_regions.push_back(copy_region);
                        copy_region.bufferOffset += level_sizes[i];
                    }
                }
            }

            if (!copy_regions.empty())
            {
                result = initializer->InitializeImage(data_size,
                                                      data,
                                                      image_info->queue_family_index,
                                                      image,
                                                      image_info->type,
                                                      image_info->format,
                                                      image_info->extent,
                                                      static_cast<VkImageAspectFlagBits>(aspect),
                                                      image_info->sample_count,
                                                      image_info->usage,
                                                      static_cast<VkImageLayout>(image_info->initial_layout),
                                                      static_cast<VkImageLayout>(layout),
                                                      image_info->layer_count,
                                                      static_cast<uint32_t>(copy_regions.size()),
                                                      copy_regions.data());
            }
            else if ((layout != VK_IMAGE_LAYOUT_UNDEFINED) && (layout != VK_IMAGE_LAYOUT_PREINITIALIZED))
            {
                // Only transition to the final layout when a staging copy is not required for image data upload.
                result = initializer->TransitionImage(image_info->queue_family_index,
                                                      image,
                                                      image_info->format,
                                                      static_cast<VkImageAspectFlagBits>(aspect),
                                                      static_cast<VkImageLayout>(image_info->initial_layout),
                                                      static_cast<VkImageLayout>(layout),
                                                      image_info->layer_count,
                                                      image_info->level_count);
            }

            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING(
                    "State snapshot image upload/layout transition failed for VkImage object (ID = %" PRIu64
                    ", handle = 0x%" PRIx64 ")",
                    image_id,
                    image);
            }
        }
    }
    else
    {
        if (device_info != nullptr)
        {
            GFXRECON_LOG_WARNING(
                "Skipping state snapshot image upload for unrecognized VkImage object (ID = %" PRIu64 ")", image_id);
        }
        else if (image_info != nullptr)
        {
            GFXRECON_LOG_WARNING(
                "Skipping state snapshot image upload for unrecognized VkDevice object (ID = %" PRIu64 ")", device_id);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping state snapshot image upload for unrecognized VkDevice (ID = %" PRIu64
                                 ") and VkImage (ID = %" PRIu64 ") objects",
                                 device_id,
                                 image_id);
        }
    }
}

void VulkanReplayConsumerBase::RaiseFatalError(const char* message) const
{
    // TODO: Should there be a default action if no error handler has been provided?
    if (fatal_error_handler_ != nullptr)
    {
        fatal_error_handler_(message);
    }
}

void VulkanReplayConsumerBase::InitializeLoader()
{
    for (auto name : kLoaderLibNames)
    {
        loader_handle_ = util::platform::OpenLibrary(name.c_str());
        if (loader_handle_ != nullptr)
        {
            get_instance_proc_addr_ = reinterpret_cast<PFN_vkGetInstanceProcAddr>(
                util::platform::GetProcAddress(loader_handle_, "vkGetInstanceProcAddr"));
            break;
        }
    }

    if (get_instance_proc_addr_ != nullptr)
    {
        create_instance_proc_ =
            reinterpret_cast<PFN_vkCreateInstance>(get_instance_proc_addr_(nullptr, "vkCreateInstance"));
    }

    if (create_instance_proc_ == nullptr)
    {
        GFXRECON_LOG_FATAL("Failed to load Vulkan runtime library; please ensure that the path to the Vulkan "
                           "loader (eg. %s) has been added to the appropriate system path",
                           kLoaderLibNames[0].c_str());
        RaiseFatalError("Failed to load Vulkan runtime library");
    }
}

void VulkanReplayConsumerBase::AddInstanceTable(VkInstance instance)
{
    encode::DispatchKey dispatch_key = encode::GetDispatchKey(instance);

    get_device_proc_addrs_[dispatch_key] =
        reinterpret_cast<PFN_vkGetDeviceProcAddr>(get_instance_proc_addr_(instance, "vkGetDeviceProcAddr"));
    create_device_procs_[dispatch_key] =
        reinterpret_cast<PFN_vkCreateDevice>(get_instance_proc_addr_(instance, "vkCreateDevice"));

    encode::InstanceTable& table = instance_tables_[dispatch_key];
    encode::LoadInstanceTable(get_instance_proc_addr_, instance, &table);
}

void VulkanReplayConsumerBase::AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa)
{
    encode::DeviceTable& table = device_tables_[encode::GetDispatchKey(device)];
    encode::LoadDeviceTable(gpa, device, &table);
}

PFN_vkGetDeviceProcAddr VulkanReplayConsumerBase::GetDeviceAddrProc(VkPhysicalDevice physical_device)
{
    return get_device_proc_addrs_[encode::GetDispatchKey(physical_device)];
}

PFN_vkCreateDevice VulkanReplayConsumerBase::GetCreateDeviceProc(VkPhysicalDevice physical_device)
{
    return create_device_procs_[encode::GetDispatchKey(physical_device)];
}

const encode::InstanceTable* VulkanReplayConsumerBase::GetInstanceTable(const void* handle) const
{
    auto table = instance_tables_.find(encode::GetDispatchKey(handle));
    assert(table != instance_tables_.end());
    return (table != instance_tables_.end()) ? &table->second : nullptr;
}

const encode::DeviceTable* VulkanReplayConsumerBase::GetDeviceTable(const void* handle) const
{
    auto table = device_tables_.find(encode::GetDispatchKey(handle));
    assert(table != device_tables_.end());
    return (table != device_tables_.end()) ? &table->second : nullptr;
}

void* VulkanReplayConsumerBase::PreProcessExternalObject(uint64_t          object_id,
                                                         format::ApiCallId call_id,
                                                         const char*       call_name)
{
    void* object = nullptr;

    if ((call_id == format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR) ||
        (call_id == format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR) ||
        (call_id == format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR))
    {
        // The window system related handles are ignored by replay.
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                             call_name);
    }

    return object;
}

void VulkanReplayConsumerBase::PostProcessExternalObject(
    VkResult replay_result, uint64_t object_id, void* object, format::ApiCallId call_id, const char* call_name)
{
    GFXRECON_UNREFERENCED_PARAMETER(replay_result);
    GFXRECON_UNREFERENCED_PARAMETER(object_id);
    GFXRECON_UNREFERENCED_PARAMETER(object);

    if (call_id == format::ApiCallId::ApiCall_vkMapMemory)
    {
        // Mapped memory tracking is handled by mapping the VkDeviceMemory handle to the mapped pointer, rather than
        // mapping the captured pointer address to the pointer mapped on replay.  The memory needs to be tracked by
        // handle so that it can be removed from the unordered_map when memory is unmapped or freed.
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                             call_name);
    }
}

const VkAllocationCallbacks* VulkanReplayConsumerBase::GetAllocationCallbacks(
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* original_callbacks)
{
    // Replay does not currently attempt emulate the captured application's use of VkAllocationCallbacks.
    GFXRECON_UNREFERENCED_PARAMETER(original_callbacks);
    return nullptr;
}

void VulkanReplayConsumerBase::CheckResult(const char* func_name, VkResult original, VkResult replay)
{
    if (original != replay)
    {
        if ((replay < 0) && (replay != VK_ERROR_FORMAT_NOT_SUPPORTED))
        {
            // Raise a fatal error if replay produced an error that did not occur during capture.  Format not supported
            // errors are not treated as fatal, but will be reported as warnings below, allowing the replay to attempt
            // to continue for the case where an application may have queried for formats that it did not use.
            GFXRECON_LOG_FATAL("API call %s returned error value %s that does not match the result from the "
                               "capture file: %s.  Replay cannot continue.",
                               func_name,
                               enumutil::GetResultValueString(replay),
                               enumutil::GetResultValueString(original));

            RaiseFatalError(enumutil::GetResultDescription(replay));
        }
        else if (!((replay == VK_SUCCESS) &&
                   ((original == VK_TIMEOUT) || (original == VK_NOT_READY) || (original == VK_ERROR_OUT_OF_DATE_KHR))))
        {
            // Report differences between replay result and capture result, unless the replay results indicates
            // that a wait operation completed before the original or a WSI function succeeded when the original failed.
            GFXRECON_LOG_WARNING(
                "API call %s returned value %s that does not match return value from capture file: %s.",
                func_name,
                enumutil::GetResultValueString(replay),
                enumutil::GetResultValueString(original));
        }
    }
}

void VulkanReplayConsumerBase::SetPhysicalDeviceProperties(PhysicalDeviceInfo*               physical_device_info,
                                                           const VkPhysicalDeviceProperties* capture_properties,
                                                           const VkPhysicalDeviceProperties* replay_properties)
{
    assert((physical_device_info != nullptr) && (capture_properties != nullptr) && (replay_properties != nullptr));

    physical_device_info->capture_api_version    = capture_properties->apiVersion;
    physical_device_info->capture_driver_version = capture_properties->driverVersion;
    physical_device_info->capture_vendor_id      = capture_properties->vendorID;
    physical_device_info->capture_device_id      = capture_properties->deviceID;
    physical_device_info->capture_device_type    = capture_properties->deviceType;
    physical_device_info->capture_device_name    = capture_properties->deviceName;
    util::platform::MemoryCopy(physical_device_info->capture_pipeline_cache_uuid,
                               format::kUuidSize,
                               capture_properties->pipelineCacheUUID,
                               VK_UUID_SIZE);

    auto replay_device_info = physical_device_info->replay_device_info;
    assert(replay_device_info != nullptr);

    if (replay_device_info->properties == nullptr)
    {
        replay_device_info->properties = std::make_unique<VkPhysicalDeviceProperties>(*replay_properties);
    }
}

void VulkanReplayConsumerBase::SetPhysicalDeviceMemoryProperties(
    PhysicalDeviceInfo*                     physical_device_info,
    const VkPhysicalDeviceMemoryProperties* capture_properties,
    const VkPhysicalDeviceMemoryProperties* replay_properties)
{
    assert((physical_device_info != nullptr) && (capture_properties != nullptr) && (replay_properties != nullptr));

    if (physical_device_info->capture_memory_properties.memoryHeapCount == 0)
    {
        physical_device_info->capture_memory_properties = *capture_properties;
    }

    auto replay_device_info = physical_device_info->replay_device_info;
    assert(replay_device_info != nullptr);

    if (replay_device_info->memory_properties == nullptr)
    {
        replay_device_info->memory_properties = std::make_unique<VkPhysicalDeviceMemoryProperties>(*replay_properties);
    }
}

void VulkanReplayConsumerBase::SelectPhysicalDevice(PhysicalDeviceInfo* physical_device_info)
{
    assert((physical_device_info != nullptr) && (physical_device_info->parent_id != 0));

    InstanceInfo* instance_info = object_info_table_.GetInstanceInfo(physical_device_info->parent_id);

    if (instance_info != nullptr)
    {
        const auto&      replay_devices = instance_info->replay_devices;
        VkPhysicalDevice current_device = physical_device_info->handle;

        bool have_override = false;

        if (options_.override_gpu_index >= 0)
        {
            have_override = GetOverrideDevice(instance_info, physical_device_info);
        }

        if (!have_override)
        {
            GetMatchingDevice(instance_info, physical_device_info);
        }

        CheckPhysicalDeviceCompatibility(physical_device_info);
    }
    else
    {
        GFXRECON_LOG_WARNING("Failed to find VkInstance object (ID = %" PRIu64 ", handle = 0x%" PRIx64
                             ") when selecting a match for capture VkPhysicalDevice object (ID = %" PRIu64
                             ") for device creation",
                             physical_device_info->parent_id,
                             physical_device_info->parent,
                             physical_device_info->capture_id);
    }
}

bool VulkanReplayConsumerBase::GetOverrideDevice(InstanceInfo* instance_info, PhysicalDeviceInfo* physical_device_info)
{
    const auto& replay_devices      = instance_info->replay_devices;
    int32_t     replay_devices_size = static_cast<int32_t>(replay_devices.size());

    // Check for a valid override device index.
    if (options_.override_gpu_index >= replay_devices_size)
    {
        GFXRECON_LOG_ERROR("The zero-based index specified for replay device override (%d) exceeds the total number of "
                           "available physical devices (%d). The specified index requires that at least %d devices be "
                           "available. The override will not be applied.",
                           options_.override_gpu_index,
                           replay_devices_size,
                           (options_.override_gpu_index + 1));
        return false;
    }

    std::string      override_device_name;
    VkPhysicalDevice override_device = replay_devices[options_.override_gpu_index];
    VkPhysicalDevice current_device  = physical_device_info->handle;

    // We only need to change the selected device info if the handles don't match.
    if (override_device != current_device)
    {
        physical_device_info->handle             = override_device;
        physical_device_info->replay_device_info = &instance_info->replay_device_info[override_device];
    }

    GFXRECON_LOG_INFO("Creating logical device from manually specified GPU%d", options_.override_gpu_index);
    GFXRECON_LOG_INFO("  Available devices are:");
    for (int32_t i = 0; i < replay_devices_size; ++i)
    {
        VkPhysicalDevice replay_device      = replay_devices[i];
        auto             replay_device_info = &instance_info->replay_device_info[replay_device];

        if (replay_device_info->properties == nullptr)
        {
            auto table = GetInstanceTable(physical_device_info->handle);
            assert(table != nullptr);

            replay_device_info->properties = std::make_unique<VkPhysicalDeviceProperties>();
            table->GetPhysicalDeviceProperties(physical_device_info->handle, replay_device_info->properties.get());
        }

        std::string replay_device_name = replay_device_info->properties->deviceName;
        if (replay_device_name.empty())
        {
            replay_device_name = kUnknownDeviceLabel;
        }

        if (override_device == replay_device)
        {
            override_device_name = replay_device_name;
        }

        GFXRECON_LOG_INFO("    [%d] %s", i, replay_device_name.c_str());
    }

    GFXRECON_LOG_INFO("  Specified device is: %s", override_device_name.c_str());

    return true;
}

void VulkanReplayConsumerBase::GetMatchingDevice(InstanceInfo* instance_info, PhysicalDeviceInfo* physical_device_info)
{
    // Dispatch table for retrieving physical device properties, if necessary.
    auto table = GetInstanceTable(physical_device_info->handle);
    assert(table != nullptr);

    auto replay_device_info = physical_device_info->replay_device_info;
    assert(replay_device_info != nullptr);

    if (replay_device_info->properties == nullptr)
    {
        replay_device_info->properties = std::make_unique<VkPhysicalDeviceProperties>();
        table->GetPhysicalDeviceProperties(physical_device_info->handle, replay_device_info->properties.get());
    }

    auto replay_properties = replay_device_info->properties.get();

    if ((physical_device_info->capture_vendor_id != replay_properties->vendorID) ||
        (physical_device_info->capture_device_id != replay_properties->deviceID))
    {
        VkPhysicalDevice current_device = physical_device_info->handle;

        // Search for matching capture and replay devices based on vendor and device IDs.
        // This is primarily intended to deal with switchable graphics layers that can remove devices from or
        // change the order of devices in the list returned by vkEnumeratePhysicalDevices.  Capture can
        // intercept calls to vkEnumeratePhysicalDevices before the list of physical devices is modified, while
        // replay receives the modified list.  So, we check for a match before logical device creation to ensure
        // capture and replay use the same physical device when both are performed on the same system.
        for (auto& entry : instance_info->replay_device_info)
        {
            // Skip the current physical device, which we already know is not a match.
            if (entry.first != current_device)
            {
                if (entry.second.properties == nullptr)
                {
                    entry.second.properties = std::make_unique<VkPhysicalDeviceProperties>();
                    table->GetPhysicalDeviceProperties(physical_device_info->handle, entry.second.properties.get());
                }

                replay_properties = entry.second.properties.get();

                if ((physical_device_info->capture_vendor_id == replay_properties->vendorID) ||
                    (physical_device_info->capture_device_id == replay_properties->deviceID))
                {
                    // A match has been found.
                    physical_device_info->handle             = entry.first;
                    physical_device_info->replay_device_info = &entry.second;
                    break;
                }
            }
        }
    }
}

void VulkanReplayConsumerBase::CheckPhysicalDeviceCompatibility(PhysicalDeviceInfo* physical_device_info)
{
    auto replay_device_info = physical_device_info->replay_device_info;
    assert(replay_device_info != nullptr);

    auto replay_properties = replay_device_info->properties.get();

    // Warn about potential incompatibilities when replay device type does not match capture device type.
    if ((physical_device_info->capture_vendor_id != 0) && (physical_device_info->capture_device_id != 0) &&
        ((physical_device_info->capture_vendor_id != replay_properties->vendorID) ||
         (physical_device_info->capture_device_id != replay_properties->deviceID)))
    {
        GFXRECON_LOG_WARNING("The replay device differs from the original capture device; replay may fail due to "
                             "device incompatibilities:");
        GFXRECON_LOG_WARNING("  Capture device info:\t[vendorID = 0x%x, deviceId = 0x%x, deviceName = %s]",
                             physical_device_info->capture_vendor_id,
                             physical_device_info->capture_device_id,
                             physical_device_info->capture_device_name.c_str());
        GFXRECON_LOG_WARNING("  Replay device info:\t[vendorID = 0x%x, deviceId = 0x%x, deviceName = %s]",
                             replay_properties->vendorID,
                             replay_properties->deviceID,
                             replay_properties->deviceName);
    }
}

bool VulkanReplayConsumerBase::CheckTrimDeviceExtensions(VkPhysicalDevice          physical_device,
                                                         std::vector<std::string>* extensions)
{
    bool have_extensions = false;
    auto table           = GetInstanceTable(physical_device);

    assert((extensions != nullptr) && (table != nullptr));

    uint32_t count  = 0;
    VkResult result = table->EnumerateDeviceExtensionProperties(physical_device, nullptr, &count, nullptr);

    if ((result == VK_SUCCESS) && (count > 0))
    {
        std::vector<VkExtensionProperties> properties;
        properties.resize(count);

        result = table->EnumerateDeviceExtensionProperties(physical_device, nullptr, &count, properties.data());

        if (result == VK_SUCCESS)
        {
            assert(count == properties.size());

            for (const auto& property : properties)
            {
                if (kTrimStateSetupDeviceExtensions.find(property.extensionName) !=
                    kTrimStateSetupDeviceExtensions.end())
                {
                    extensions->push_back(property.extensionName);
                }
            }

            have_extensions = !extensions->empty();
        }
    }

    return have_extensions;
}

void VulkanReplayConsumerBase::InitializeResourceAllocator(const PhysicalDeviceInfo*       physical_device_info,
                                                           VkDevice                        device,
                                                           const std::vector<std::string>& enabled_device_extensions,
                                                           VulkanResourceAllocator*        allocator)
{
    assert((physical_device_info != nullptr) && (physical_device_info->replay_device_info != nullptr) &&
           (device != VK_NULL_HANDLE) && (allocator != nullptr));

    // Initialize the memory allocator's function table.
    auto instance_table = GetInstanceTable(physical_device_info->handle);
    auto device_table   = GetDeviceTable(device);
    assert((instance_table != nullptr) && (device_table != nullptr));

    VulkanResourceAllocator::Functions functions;
    functions.get_physical_device_properties        = instance_table->GetPhysicalDeviceProperties;
    functions.get_physical_device_memory_properties = instance_table->GetPhysicalDeviceMemoryProperties;

    if (instance_table->GetPhysicalDeviceMemoryProperties2 != nullptr)
    {
        functions.get_physical_device_memory_properties2 = instance_table->GetPhysicalDeviceMemoryProperties2;
    }
    else
    {
        functions.get_physical_device_memory_properties2 = instance_table->GetPhysicalDeviceMemoryProperties2KHR;
    }

    functions.allocate_memory                = device_table->AllocateMemory;
    functions.free_memory                    = device_table->FreeMemory;
    functions.get_device_memory_commitment   = device_table->GetDeviceMemoryCommitment;
    functions.map_memory                     = device_table->MapMemory;
    functions.unmap_memory                   = device_table->UnmapMemory;
    functions.flush_memory_ranges            = device_table->FlushMappedMemoryRanges;
    functions.invalidate_memory_ranges       = device_table->InvalidateMappedMemoryRanges;
    functions.create_buffer                  = device_table->CreateBuffer;
    functions.destroy_buffer                 = device_table->DestroyBuffer;
    functions.get_buffer_memory_requirements = device_table->GetBufferMemoryRequirements;
    functions.bind_buffer_memory             = device_table->BindBufferMemory;
    functions.cmd_copy_buffer                = device_table->CmdCopyBuffer;
    functions.create_image                   = device_table->CreateImage;
    functions.destroy_image                  = device_table->DestroyImage;
    functions.get_image_memory_requirements  = device_table->GetImageMemoryRequirements;
    functions.get_image_subresource_layout   = device_table->GetImageSubresourceLayout;
    functions.bind_image_memory              = device_table->BindImageMemory;

    if (device_table->GetBufferMemoryRequirements2 != nullptr)
    {
        functions.get_buffer_memory_requirements2 = device_table->GetBufferMemoryRequirements2;
    }
    else
    {
        functions.get_buffer_memory_requirements2 = device_table->GetBufferMemoryRequirements2KHR;
    }

    if (device_table->BindBufferMemory2 != nullptr)
    {
        functions.bind_buffer_memory2 = device_table->BindBufferMemory2;
    }
    else
    {
        functions.bind_buffer_memory2 = device_table->BindBufferMemory2KHR;
    }

    if (device_table->GetImageMemoryRequirements2 != nullptr)
    {
        functions.get_image_memory_requirements2 = device_table->GetImageMemoryRequirements2;
    }
    else
    {
        functions.get_image_memory_requirements2 = device_table->GetImageMemoryRequirements2KHR;
    }

    if (device_table->BindImageMemory2 != nullptr)
    {
        functions.bind_image_memory2 = device_table->BindImageMemory2;
    }
    else
    {
        functions.bind_image_memory2 = device_table->BindImageMemory2KHR;
    }

    auto replay_device_info = physical_device_info->replay_device_info;
    assert(replay_device_info->memory_properties != nullptr);

    VkResult result = allocator->Initialize(physical_device_info->parent_api_version,
                                            physical_device_info->parent,
                                            physical_device_info->handle,
                                            device,
                                            enabled_device_extensions,
                                            physical_device_info->capture_device_type,
                                            physical_device_info->capture_memory_properties,
                                            *replay_device_info->memory_properties,
                                            functions);

    if (result < 0)
    {
        GFXRECON_LOG_FATAL("Failed to initialize memory allocator.  Replay cannot continue.");
        RaiseFatalError(
            "Replay has encountered a fatal error and cannot continue (failed to initialize memory allocator)");
    }
}

VkResult VulkanReplayConsumerBase::CreateSurface(InstanceInfo*                       instance_info,
                                                 VkFlags                             flags,
                                                 HandlePointerDecoder<VkSurfaceKHR>* surface)
{
    assert(instance_info != nullptr);

    VkInstance    instance       = instance_info->handle;
    VkSurfaceKHR* replay_surface = nullptr;

    if (surface != nullptr)
    {
        replay_surface = surface->GetHandlePointer();
    }

    // Create a window for our surface.
    Window* window = window_factory_->Create(
        kDefaultWindowPositionX, kDefaultWindowPositionY, kDefaultWindowWidth, kDefaultWindowHeight);

    if (window == nullptr)
    {
        // Failure to create a window is a fatal error.
        GFXRECON_LOG_FATAL("Failed to create a window for use with surface creation.  Replay cannot continue.");
        RaiseFatalError("Replay has encountered a fatal error and cannot continue (window creation failed)");
    }

    VkResult result = window->CreateSurface(GetInstanceTable(instance), instance, flags, replay_surface);

    if ((result == VK_SUCCESS) && (replay_surface != nullptr))
    {
        auto surface_info = reinterpret_cast<SurfaceKHRInfo*>(surface->GetConsumerData(0));
        assert(surface_info != nullptr);

        surface_info->window = window;
        active_windows_.insert(window);

        instance_info->active_surfaces.insert(*replay_surface);
    }
    else
    {
        window_factory_->Destroy(window);
    }

    return result;
}

void VulkanReplayConsumerBase::ProcessSwapchainFullScreenExclusiveInfo(
    const Decoded_VkSwapchainCreateInfoKHR* swapchain_info)
{
    assert(swapchain_info != nullptr);

    if (swapchain_info->pNext != nullptr)
    {
        // 'Out' struct for non-const pNext pointers.
        auto pnext = reinterpret_cast<VkBaseOutStructure*>(swapchain_info->pNext->GetPointer());
        while (pnext != nullptr)
        {
            if (pnext->sType == VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT)
            {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
                // Get the surface info from the Decoded_VkSwapchainCreateInfoKHR handle id.
                HMONITOR   hmonitor     = nullptr;
                const auto surface_info = object_info_table_.GetSurfaceKHRInfo(swapchain_info->surface);

                if ((surface_info != nullptr) && (surface_info->window != nullptr))
                {
                    // Try to retrieve an HWND value from the window.
                    HWND hwnd = nullptr;
                    if (surface_info->window->GetNativeHandle(Window::kWin32HWnd, reinterpret_cast<void**>(&hwnd)))
                    {
                        hmonitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
                    }
                }

                if (hmonitor != nullptr)
                {
                    auto full_screen_info      = reinterpret_cast<VkSurfaceFullScreenExclusiveWin32InfoEXT*>(pnext);
                    full_screen_info->hmonitor = hmonitor;
                }
                else
                {
                    GFXRECON_LOG_WARNING(
                        "Failed to obtain a valid HMONITOR handle for the VkSurfaceFullScreenExclusiveWin32InfoEXT "
                        "extension structure provided to vkCreateSwapchainKHR")
                }
#else
                GFXRECON_LOG_WARNING("vkCreateSwapchainKHR called with the VkSurfaceFullScreenExclusiveWin32InfoEXT "
                                     "extension structure, which is not supported by this platform")
#endif
                break;
            }

            pnext = pnext->pNext;
        }
    }
}

void VulkanReplayConsumerBase::ProcessImportAndroidHardwareBufferInfo(const Decoded_VkMemoryAllocateInfo* allocate_info)
{
    assert(allocate_info != nullptr);

    if (allocate_info->pNext != nullptr)
    {
        auto pnext = reinterpret_cast<Decoded_VkBaseOutStructure*>(allocate_info->pNext->GetMetaStructPointer());
        while (pnext != nullptr)
        {
            if (pnext->decoded_value->sType == VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID)
            {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
                auto import_ahb_info = reinterpret_cast<Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(pnext);

                // Get the hardware buffer from the Decoded_VkImportAndroidHardwareBufferInfoANDROID buffer id.
                auto entry = hardware_buffers_.find(import_ahb_info->buffer);
                if (entry != hardware_buffers_.end())
                {
                    import_ahb_info->decoded_value->buffer = entry->second.hardware_buffer;
                }
                else
                {
                    GFXRECON_LOG_WARNING("Failed to find a valid AHardwareBuffer handle for the "
                                         "VkImportAndroidHardwareBufferInfoANDROID "
                                         "extension structure provided to vkAllocateMemory")
                }
#else
                GFXRECON_LOG_WARNING("vkAllocateMemory called with the VkImportAndroidHardwareBufferInfoANDROID "
                                     "extension structure, which is not supported by this platform")
#endif
                break;
            }

            if (pnext->pNext != nullptr)
            {
                pnext = reinterpret_cast<Decoded_VkBaseOutStructure*>(pnext->pNext->GetMetaStructPointer());
            }
            else
            {
                pnext = nullptr;
            }
        }
    }
}

VkResult
VulkanReplayConsumerBase::OverrideCreateInstance(VkResult original_result,
                                                 const StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                 HandlePointerDecoder<VkInstance>*                          pInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((pInstance != nullptr) && !pInstance->IsNull() && (pInstance->GetHandlePointer() != nullptr) &&
           (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_instance    = pInstance->GetHandlePointer();

    if (loader_handle_ == nullptr)
    {
        InitializeLoader();
    }

    // Replace WSI extension in extension list.
    std::vector<const char*> filtered_extensions;
    VkInstanceCreateInfo     modified_create_info{};

    if (replay_create_info != nullptr)
    {
        if (replay_create_info->ppEnabledExtensionNames)
        {
            for (uint32_t i = 0; i < replay_create_info->enabledExtensionCount; ++i)
            {
                const char* current_extension = replay_create_info->ppEnabledExtensionNames[i];
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

        modified_create_info                         = (*replay_create_info);
        modified_create_info.enabledExtensionCount   = static_cast<uint32_t>(filtered_extensions.size());
        modified_create_info.ppEnabledExtensionNames = filtered_extensions.data();
    }
    else
    {
        GFXRECON_LOG_WARNING("The vkCreateInstance parameter pCreateInfo is NULL.");
    }

    // Disable layers; any layers needed for replay should be enabled for the replay app with the VK_INSTANCE_LAYERS
    // environment variable or debug.vulkan.layers Android property.
    if (modified_create_info.enabledLayerCount > 0)
    {
        GFXRECON_LOG_INFO(
            "Replay has removed the following layers from VkInstanceCreateInfo when calling vkCreateInstance:");

        for (uint32_t i = 0; i < modified_create_info.enabledLayerCount; ++i)
        {
            GFXRECON_LOG_INFO("\t%s", modified_create_info.ppEnabledLayerNames[i]);
        }

        modified_create_info.enabledLayerCount   = 0;
        modified_create_info.ppEnabledLayerNames = nullptr;
    }

    VkResult result = create_instance_proc_(&modified_create_info, GetAllocationCallbacks(pAllocator), replay_instance);

    if ((replay_instance != nullptr) && (result == VK_SUCCESS))
    {
        AddInstanceTable(*replay_instance);

        if (modified_create_info.pApplicationInfo != nullptr)
        {
            auto instance_info = reinterpret_cast<InstanceInfo*>(pInstance->GetConsumerData(0));
            assert(instance_info != nullptr);

            instance_info->api_version = modified_create_info.pApplicationInfo->apiVersion;
        }

        active_instance_ids_.insert(*pInstance->GetPointer());
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideDestroyInstance(
    PFN_vkDestroyInstance                                      func,
    const InstanceInfo*                                        instance_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkInstance instance = VK_NULL_HANDLE;

    if (instance_info != nullptr)
    {
        instance = instance_info->handle;
        active_instance_ids_.erase(instance_info->capture_id);
    }

    func(instance, GetAllocationCallbacks(pAllocator));
}

VkResult
VulkanReplayConsumerBase::OverrideCreateDevice(VkResult            original_result,
                                               PhysicalDeviceInfo* physical_device_info,
                                               const StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                               HandlePointerDecoder<VkDevice>*                            pDevice)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((physical_device_info != nullptr) && (pDevice != nullptr) && !pDevice->IsNull() &&
           (pDevice->GetHandlePointer() != nullptr) && (pCreateInfo != nullptr));

    SelectPhysicalDevice(physical_device_info);

    VkPhysicalDevice        physical_device      = physical_device_info->handle;
    PFN_vkGetDeviceProcAddr get_device_proc_addr = GetDeviceAddrProc(physical_device);
    PFN_vkCreateDevice      create_device_proc   = GetCreateDeviceProc(physical_device);
    VkResult                result               = VK_ERROR_INITIALIZATION_FAILED;

    if ((get_device_proc_addr != nullptr) && (create_device_proc != nullptr))
    {
        auto replay_create_info = pCreateInfo->GetPointer();
        auto replay_device      = pDevice->GetHandlePointer();

        std::vector<std::string> extensions;
        if (loading_trim_state_ && CheckTrimDeviceExtensions(physical_device, &extensions))
        {
            std::vector<const char*> modified_extensions;
            VkDeviceCreateInfo       modified_create_info{};

            if (replay_create_info != nullptr)
            {
                if (replay_create_info->ppEnabledExtensionNames)
                {
                    modified_extensions.insert(
                        modified_extensions.begin(),
                        replay_create_info->ppEnabledExtensionNames,
                        (replay_create_info->ppEnabledExtensionNames + replay_create_info->enabledExtensionCount));
                }

                for (const auto& extension : extensions)
                {
                    if (std::find(modified_extensions.begin(), modified_extensions.end(), extension) ==
                        modified_extensions.end())
                    {
                        modified_extensions.push_back(extension.c_str());
                    }
                }

                modified_create_info                         = (*replay_create_info);
                modified_create_info.enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
                modified_create_info.ppEnabledExtensionNames = modified_extensions.data();
            }
            else
            {
                GFXRECON_LOG_WARNING("The vkCreateDevice parameter pCreateInfo is NULL.");
            }

            result = create_device_proc(
                physical_device, &modified_create_info, GetAllocationCallbacks(pAllocator), replay_device);
        }
        else
        {
            result = create_device_proc(
                physical_device, replay_create_info, GetAllocationCallbacks(pAllocator), replay_device);
        }

        if ((replay_device != nullptr) && (result == VK_SUCCESS))
        {
            AddDeviceTable(*replay_device, get_device_proc_addr);

            auto device_info = reinterpret_cast<DeviceInfo*>(pDevice->GetConsumerData(0));
            assert(device_info != nullptr);

            device_info->extensions = std::move(extensions);
            device_info->parent     = physical_device;

            // Create the memory allocator for the selected physical device.
            auto replay_device_info = physical_device_info->replay_device_info;
            assert(replay_device_info != nullptr);

            if (replay_device_info->memory_properties == nullptr)
            {
                // Memory properties weren't queried before device creation, so retrieve them now.
                auto table = GetInstanceTable(physical_device);
                assert(table != nullptr);

                replay_device_info->memory_properties = std::make_unique<VkPhysicalDeviceMemoryProperties>();
                table->GetPhysicalDeviceMemoryProperties(physical_device, replay_device_info->memory_properties.get());
            }

            auto allocator = options_.create_resource_allocator();

            std::vector<std::string> enabled_extensions(replay_create_info->ppEnabledExtensionNames,
                                                        replay_create_info->ppEnabledExtensionNames +
                                                            replay_create_info->enabledExtensionCount);
            InitializeResourceAllocator(physical_device_info, *replay_device, enabled_extensions, allocator);

            device_info->allocator = std::unique_ptr<VulkanResourceAllocator>(allocator);

            active_device_ids_.insert(*pDevice->GetPointer());
        }
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideDestroyDevice(
    PFN_vkDestroyDevice                                        func,
    const DeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice device = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
        active_device_ids_.erase(device_info->capture_id);
    }

    func(device, GetAllocationCallbacks(pAllocator));
}

VkResult
VulkanReplayConsumerBase::OverrideEnumeratePhysicalDevices(PFN_vkEnumeratePhysicalDevices          func,
                                                           VkResult                                original_result,
                                                           InstanceInfo*                           instance_info,
                                                           PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                                           HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((instance_info != nullptr) && (pPhysicalDeviceCount != nullptr) && !pPhysicalDeviceCount->IsNull() &&
           (pPhysicalDeviceCount->GetOutputPointer() != nullptr) && (pPhysicalDevices != nullptr));

    VkInstance        instance                = instance_info->handle;
    uint32_t*         replay_device_count_ptr = pPhysicalDeviceCount->GetOutputPointer();
    VkPhysicalDevice* replay_devices          = pPhysicalDevices->GetHandlePointer();

    VkResult result = func(instance, replay_device_count_ptr, replay_devices);

    if ((result >= 0) && (replay_devices != nullptr))
    {
        assert(!pPhysicalDeviceCount->IsNull() && !pPhysicalDevices->IsNull());

        uint32_t                replay_device_count  = (*replay_device_count_ptr);
        uint32_t                capture_device_count = (*pPhysicalDeviceCount->GetPointer());
        const format::HandleId* capture_devices      = pPhysicalDevices->GetPointer();
        bool                    store_replay_device  = false;

        // Clear instance info device arrays if the sizes don't match (e.g. a previous call to
        // vkEnumeratePhysicalDevices returned VK_INCOMPLETE).
        if (!instance_info->capture_devices.empty() && (instance_info->capture_devices.size() != capture_device_count))
        {
            instance_info->capture_devices.clear();
        }

        if (!instance_info->replay_devices.empty() && (instance_info->replay_devices.size() != replay_device_count))
        {
            instance_info->replay_devices.clear();
        }

        if (instance_info->capture_devices.empty())
        {
            for (uint32_t i = 0; i < capture_device_count; ++i)
            {
                instance_info->capture_devices.push_back(capture_devices[i]);
            }
        }

        if (instance_info->replay_devices.empty())
        {
            store_replay_device = true;
        }

        for (uint32_t i = 0; i < replay_device_count; ++i)
        {
            auto physical_device_info = reinterpret_cast<PhysicalDeviceInfo*>(pPhysicalDevices->GetConsumerData(i));
            assert(physical_device_info != nullptr);

            physical_device_info->parent             = instance;
            physical_device_info->parent_id          = instance_info->capture_id;
            physical_device_info->parent_api_version = instance_info->api_version;
            physical_device_info->replay_device_info = &instance_info->replay_device_info[replay_devices[i]];

            if (store_replay_device)
            {
                instance_info->replay_devices.push_back(replay_devices[i]);
            }
        }

        if ((replay_device_count > 0) && (replay_device_count < capture_device_count))
        {
            // Make sure all of the capture physical device IDs map to a valid replay physical device handle.
            // The generated code will only add handle mappings for handles returned by vkEnumeratePhysicalDevices on
            // replay, so we add mappings for the handle IDs without matching devices here.
            for (uint32_t i = replay_device_count; i < capture_device_count; ++i)
            {
                VkPhysicalDevice   overflow_device = replay_devices[0];
                PhysicalDeviceInfo overflow_info;

                overflow_info.handle             = overflow_device;
                overflow_info.capture_id         = capture_devices[i];
                overflow_info.parent             = instance;
                overflow_info.parent_id          = instance_info->capture_id;
                overflow_info.parent_api_version = instance_info->api_version;
                overflow_info.replay_device_info = &instance_info->replay_device_info[overflow_device];

                object_info_table_.AddPhysicalDeviceInfo(std::move(overflow_info));
            }
        }
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceProperties(
    PFN_vkGetPhysicalDeviceProperties                         func,
    PhysicalDeviceInfo*                                       physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    assert((physical_device_info != nullptr) && (pProperties != nullptr) && !pProperties->IsNull() &&
           (pProperties->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device   = physical_device_info->handle;
    auto             replay_properties = pProperties->GetOutputPointer();

    func(physical_device, replay_properties);

    // This can be set by ProcessSetDevicePropertiesCommand, but older files will not contain that data.
    SetPhysicalDeviceProperties(physical_device_info, pProperties->GetPointer(), replay_properties);
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceProperties2(
    PFN_vkGetPhysicalDeviceProperties2                         func,
    PhysicalDeviceInfo*                                        physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    assert((physical_device_info != nullptr) && (pProperties != nullptr) && !pProperties->IsNull() &&
           (pProperties->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device   = physical_device_info->handle;
    auto             replay_properties = pProperties->GetOutputPointer();

    func(physical_device, replay_properties);

    // This can be set by ProcessSetDevicePropertiesCommand, but older files will not contain that data.
    auto capture_properties = pProperties->GetPointer();
    SetPhysicalDeviceProperties(physical_device_info, &capture_properties->properties, &replay_properties->properties);
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceMemoryProperties(
    PFN_vkGetPhysicalDeviceMemoryProperties                         func,
    PhysicalDeviceInfo*                                             physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    assert((physical_device_info != nullptr) && (pMemoryProperties != nullptr) && !pMemoryProperties->IsNull() &&
           (pMemoryProperties->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device   = physical_device_info->handle;
    auto             replay_properties = pMemoryProperties->GetOutputPointer();

    func(physical_device, replay_properties);

    // This can be set by ProcessSetDeviceMemoryPropertiesCommand, but older files will not contain that data.
    SetPhysicalDeviceMemoryProperties(physical_device_info, pMemoryProperties->GetPointer(), replay_properties);
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceMemoryProperties2(
    PFN_vkGetPhysicalDeviceMemoryProperties2                         func,
    PhysicalDeviceInfo*                                              physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    assert((physical_device_info != nullptr) && (pMemoryProperties != nullptr) && !pMemoryProperties->IsNull() &&
           (pMemoryProperties->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device   = physical_device_info->handle;
    auto             replay_properties = pMemoryProperties->GetOutputPointer();

    func(physical_device, replay_properties);

    // This can be set by ProcessSetDeviceMemoryPropertiesCommand, but older files will not contain that data.
    auto capture_properties = pMemoryProperties->GetPointer();
    SetPhysicalDeviceMemoryProperties(
        physical_device_info, &capture_properties->memoryProperties, &replay_properties->memoryProperties);
}

VkResult VulkanReplayConsumerBase::OverrideWaitForFences(PFN_vkWaitForFences                  func,
                                                         VkResult                             original_result,
                                                         const DeviceInfo*                    device_info,
                                                         uint32_t                             fenceCount,
                                                         const HandlePointerDecoder<VkFence>* pFences,
                                                         VkBool32                             waitAll,
                                                         uint64_t                             timeout)
{
    assert((device_info != nullptr) && (pFences != nullptr));

    VkResult result;
    VkDevice device = device_info->handle;

    if (original_result == VK_SUCCESS)
    {
        // Ensure that wait for fences waits until the fences have been signaled (or error occurs) by changing the
        // timeout to UINT64_MAX.
        result = func(device, fenceCount, pFences->GetHandlePointer(), waitAll, std::numeric_limits<uint64_t>::max());
    }
    else if (original_result == VK_TIMEOUT)
    {
        // Try to get a timeout result with a 0 timeout.
        result = func(device, fenceCount, pFences->GetHandlePointer(), waitAll, 0);
    }
    else
    {
        result = func(device, fenceCount, pFences->GetHandlePointer(), waitAll, timeout);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetFenceStatus(PFN_vkGetFenceStatus func,
                                                          VkResult             original_result,
                                                          const DeviceInfo*    device_info,
                                                          const FenceInfo*     fence_info)
{
    assert((device_info != nullptr) && (fence_info != nullptr));

    VkResult result;
    VkDevice device = device_info->handle;
    VkFence  fence  = fence_info->handle;

    do
    {
        result = func(device, fence);
    } while ((original_result == VK_SUCCESS) && (result == VK_NOT_READY));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetEventStatus(PFN_vkGetEventStatus func,
                                                          VkResult             original_result,
                                                          const DeviceInfo*    device_info,
                                                          const EventInfo*     event_info)
{
    assert((device_info != nullptr) && (event_info != nullptr));

    VkResult result;
    VkDevice device = device_info->handle;
    VkEvent  event  = event_info->handle;

    do
    {
        result = func(device, event);
    } while ((original_result == VK_EVENT_SET) && (result == VK_EVENT_RESET));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetQueryPoolResults(PFN_vkGetQueryPoolResults func,
                                                               VkResult                  original_result,
                                                               const DeviceInfo*         device_info,
                                                               const QueryPoolInfo*      query_pool_info,
                                                               uint32_t                  firstQuery,
                                                               uint32_t                  queryCount,
                                                               size_t                    dataSize,
                                                               PointerDecoder<uint8_t>*  pData,
                                                               VkDeviceSize              stride,
                                                               VkQueryResultFlags        flags)
{
    assert((device_info != nullptr) && (query_pool_info != nullptr) && (pData != nullptr) &&
           (pData->GetOutputPointer() != nullptr));

    VkResult    result;
    VkDevice    device     = device_info->handle;
    VkQueryPool query_pool = query_pool_info->handle;

    do
    {
        result = func(device, query_pool, firstQuery, queryCount, dataSize, pData->GetOutputPointer(), stride, flags);
    } while ((original_result == VK_SUCCESS) && (result == VK_NOT_READY));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAllocateCommandBuffers(
    PFN_vkAllocateCommandBuffers                                     func,
    VkResult                                                         original_result,
    const DeviceInfo*                                                device_info,
    const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*                           pCommandBuffers)
{
    assert((device_info != nullptr) && (pAllocateInfo != nullptr) && (pCommandBuffers != nullptr) &&
           (pCommandBuffers->GetHandlePointer() != nullptr));

    VkResult result = original_result;

    if ((original_result >= 0) || !options_.skip_failed_allocations)
    {
        result = func(device_info->handle, pAllocateInfo->GetPointer(), pCommandBuffers->GetHandlePointer());
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateCommandBuffers call that failed during capture with error %s",
                          enumutil::GetResultValueString(original_result));
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAllocateDescriptorSets(
    PFN_vkAllocateDescriptorSets                                     func,
    VkResult                                                         original_result,
    const DeviceInfo*                                                device_info,
    const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                           pDescriptorSets)
{
    assert((device_info != nullptr) && (pAllocateInfo != nullptr) && (pDescriptorSets != nullptr) &&
           (pDescriptorSets->GetHandlePointer() != nullptr));

    VkResult result = original_result;

    if ((original_result >= 0) || !options_.skip_failed_allocations)
    {
        result = func(device_info->handle, pAllocateInfo->GetPointer(), pDescriptorSets->GetHandlePointer());
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateDescriptorSets call that failed during capture with error %s",
                          enumutil::GetResultValueString(original_result));
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAllocateMemory(
    PFN_vkAllocateMemory                                       func,
    VkResult                                                   original_result,
    const DeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  pAllocateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*                      pMemory)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert((device_info != nullptr) && (pAllocateInfo != nullptr) && (pMemory != nullptr) && !pMemory->IsNull() &&
           (pMemory->GetHandlePointer() != nullptr));

    VkResult result = original_result;

    if ((original_result >= 0) || !options_.skip_failed_allocations)
    {
        auto allocator = device_info->allocator.get();
        assert(allocator != nullptr);

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        ProcessImportAndroidHardwareBufferInfo(pAllocateInfo->GetMetaStructPointer());
#endif

        VulkanResourceAllocator::MemoryData allocator_data;
        auto                                replay_allocate_info = pAllocateInfo->GetPointer();
        auto                                replay_memory        = pMemory->GetHandlePointer();
        auto                                capture_id           = (*pMemory->GetPointer());

        result = allocator->AllocateMemory(
            replay_allocate_info, GetAllocationCallbacks(pAllocator), capture_id, replay_memory, &allocator_data);

        if ((result == VK_SUCCESS) && (replay_allocate_info != nullptr) && ((*replay_memory) != VK_NULL_HANDLE))
        {
            auto memory_info = reinterpret_cast<DeviceMemoryInfo*>(pMemory->GetConsumerData(0));
            assert(memory_info != nullptr);

            memory_info->allocator      = allocator;
            memory_info->allocator_data = allocator_data;
        }
        else if (original_result == VK_SUCCESS)
        {
            // When memory allocation fails at replay, but succeeded at capture, check for memory incompatibilities and
            // recommend enabling memory translation.
            allocator->ReportAllocateMemoryIncompatibility(replay_allocate_info);
        }
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateMemory call that failed during capture with error %s",
                          enumutil::GetResultValueString(original_result));
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideMapMemory(PFN_vkMapMemory   func,
                                                     VkResult          original_result,
                                                     const DeviceInfo* device_info,
                                                     DeviceMemoryInfo* memory_info,
                                                     VkDeviceSize      offset,
                                                     VkDeviceSize      size,
                                                     VkMemoryMapFlags  flags,
                                                     void**            ppData)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (memory_info != nullptr));

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    return allocator->MapMemory(memory_info->handle, offset, size, flags, ppData, memory_info->allocator_data);
}

void VulkanReplayConsumerBase::OverrideUnmapMemory(PFN_vkUnmapMemory func,
                                                   const DeviceInfo* device_info,
                                                   DeviceMemoryInfo* memory_info)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert((device_info != nullptr) && (memory_info != nullptr));

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    allocator->UnmapMemory(memory_info->handle, memory_info->allocator_data);
}

VkResult VulkanReplayConsumerBase::OverrideFlushMappedMemoryRanges(
    PFN_vkFlushMappedMemoryRanges                            func,
    VkResult                                                 original_result,
    const DeviceInfo*                                        device_info,
    uint32_t                                                 memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert((device_info != nullptr) && (pMemoryRanges != nullptr));

    auto replay_range_meta_datas = pMemoryRanges->GetMetaStructPointer();
    assert(replay_range_meta_datas != nullptr);

    std::vector<VulkanResourceAllocator::MemoryData> allocator_datas(memoryRangeCount, 0);

    for (uint32_t i = 0; i < memoryRangeCount; ++i)
    {
        auto memory_info = object_info_table_.GetDeviceMemoryInfo(replay_range_meta_datas[i].memory);

        if (memory_info != nullptr)
        {
            allocator_datas[i] = memory_info->allocator_data;
        }
    }

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    return allocator->FlushMappedMemoryRanges(memoryRangeCount, pMemoryRanges->GetPointer(), allocator_datas.data());
}

VkResult VulkanReplayConsumerBase::OverrideInvalidateMappedMemoryRanges(
    PFN_vkInvalidateMappedMemoryRanges                       func,
    VkResult                                                 original_result,
    const DeviceInfo*                                        device_info,
    uint32_t                                                 memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert((device_info != nullptr) && (pMemoryRanges != nullptr));

    auto replay_range_meta_datas = pMemoryRanges->GetMetaStructPointer();
    assert(replay_range_meta_datas != nullptr);

    std::vector<VulkanResourceAllocator::MemoryData> allocator_datas(memoryRangeCount, 0);

    for (uint32_t i = 0; i < memoryRangeCount; ++i)
    {
        auto memory_info = object_info_table_.GetDeviceMemoryInfo(replay_range_meta_datas[i].memory);

        if (memory_info != nullptr)
        {
            allocator_datas[i] = memory_info->allocator_data;
        }
    }

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    return allocator->InvalidateMappedMemoryRanges(
        memoryRangeCount, pMemoryRanges->GetPointer(), allocator_datas.data());
}

void VulkanReplayConsumerBase::OverrideFreeMemory(PFN_vkFreeMemory  func,
                                                  const DeviceInfo* device_info,
                                                  DeviceMemoryInfo* memory_info,
                                                  const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert(device_info != nullptr);

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VkDeviceMemory                        memory         = VK_NULL_HANDLE;
    VulkanResourceAllocator::ResourceData allocator_data = 0;

    if (memory_info != nullptr)
    {
        memory         = memory_info->handle;
        allocator_data = memory_info->allocator_data;

        memory_info->allocator_data = 0;
    }

    allocator->FreeMemory(memory, GetAllocationCallbacks(pAllocator), allocator_data);
}

VkResult VulkanReplayConsumerBase::OverrideBindBufferMemory(PFN_vkBindBufferMemory func,
                                                            VkResult               original_result,
                                                            const DeviceInfo*      device_info,
                                                            BufferInfo*            buffer_info,
                                                            DeviceMemoryInfo*      memory_info,
                                                            VkDeviceSize           memoryOffset)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (buffer_info != nullptr) && (memory_info != nullptr));

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VkResult result = allocator->BindBufferMemory(buffer_info->handle,
                                                  memory_info->handle,
                                                  memoryOffset,
                                                  buffer_info->allocator_data,
                                                  memory_info->allocator_data,
                                                  &buffer_info->memory_property_flags);

    if (result == VK_SUCCESS)
    {
        buffer_info->memory                = memory_info->handle;
        buffer_info->memory_allocator_data = memory_info->allocator_data;
        buffer_info->bind_offset           = memoryOffset;
    }
    else if (original_result == VK_SUCCESS)
    {
        // When bind fails at replay, but succeeded at capture, check for memory incompatibilities and recommend
        // enabling memory translation.
        allocator->ReportBindBufferIncompatibility(
            buffer_info->handle, buffer_info->allocator_data, memory_info->allocator_data);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideBindBufferMemory2(
    PFN_vkBindBufferMemory2                                     func,
    VkResult                                                    original_result,
    const DeviceInfo*                                           device_info,
    uint32_t                                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pBindInfos != nullptr));

    auto replay_bind_infos      = pBindInfos->GetPointer();
    auto replay_bind_meta_infos = pBindInfos->GetMetaStructPointer();
    assert((replay_bind_infos != nullptr) && (replay_bind_meta_infos != nullptr));

    std::vector<BufferInfo*>                           buffer_infos;
    std::vector<const DeviceMemoryInfo*>               memory_infos;
    std::vector<VulkanResourceAllocator::ResourceData> allocator_buffer_datas(bindInfoCount, 0);
    std::vector<VulkanResourceAllocator::MemoryData>   allocator_memory_datas(bindInfoCount, 0);
    std::vector<VkMemoryPropertyFlags>                 memory_property_flags(bindInfoCount, 0);

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        const Decoded_VkBindBufferMemoryInfo* bind_meta_info = &replay_bind_meta_infos[i];

        auto buffer_info = object_info_table_.GetBufferInfo(bind_meta_info->buffer);
        auto memory_info = object_info_table_.GetDeviceMemoryInfo(bind_meta_info->memory);

        buffer_infos.push_back(buffer_info);
        memory_infos.push_back(memory_info);

        if (buffer_info != nullptr)
        {
            allocator_buffer_datas[i] = buffer_info->allocator_data;
        }

        if (memory_info != nullptr)
        {
            allocator_memory_datas[i] = memory_info->allocator_data;
        }
    }

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VkResult result = allocator->BindBufferMemory2(bindInfoCount,
                                                   replay_bind_infos,
                                                   allocator_buffer_datas.data(),
                                                   allocator_memory_datas.data(),
                                                   memory_property_flags.data());

    if (result == VK_SUCCESS)
    {
        for (uint32_t i = 0; i < bindInfoCount; ++i)
        {
            const VkBindBufferMemoryInfo* bind_info = &replay_bind_infos[i];

            auto buffer_info = buffer_infos[i];
            auto memory_info = memory_infos[i];

            if ((buffer_info != nullptr) && (memory_info != nullptr))
            {
                buffer_info->bind_offset           = bind_info->memoryOffset;
                buffer_info->memory                = memory_info->handle;
                buffer_info->memory_allocator_data = memory_info->allocator_data;
                buffer_info->memory_property_flags = memory_property_flags[i];
            }
        }
    }
    else if (original_result == VK_SUCCESS)
    {
        // When bind fails at replay, but succeeded at capture, check for memory incompatibilities and recommend
        // enabling memory translation.
        allocator->ReportBindBuffer2Incompatibility(
            bindInfoCount, replay_bind_infos, allocator_buffer_datas.data(), allocator_memory_datas.data());
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideBindImageMemory(PFN_vkBindImageMemory func,
                                                           VkResult              original_result,
                                                           const DeviceInfo*     device_info,
                                                           ImageInfo*            image_info,
                                                           DeviceMemoryInfo*     memory_info,
                                                           VkDeviceSize          memoryOffset)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (image_info != nullptr) && (memory_info != nullptr));

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VkResult result = allocator->BindImageMemory(image_info->handle,
                                                 memory_info->handle,
                                                 memoryOffset,
                                                 image_info->allocator_data,
                                                 memory_info->allocator_data,
                                                 &image_info->memory_property_flags);

    if (result == VK_SUCCESS)
    {
        image_info->memory                = memory_info->handle;
        image_info->memory_allocator_data = memory_info->allocator_data;
        image_info->bind_offset           = memoryOffset;
    }
    else if (original_result == VK_SUCCESS)
    {
        // When bind fails at replay, but succeeded at capture, check for memory incompatibilities and recommend
        // enabling memory translation.
        allocator->ReportBindImageIncompatibility(
            image_info->handle, image_info->allocator_data, memory_info->allocator_data);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideBindImageMemory2(
    PFN_vkBindImageMemory2                                     func,
    VkResult                                                   original_result,
    const DeviceInfo*                                          device_info,
    uint32_t                                                   bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pBindInfos != nullptr));

    auto replay_bind_infos      = pBindInfos->GetPointer();
    auto replay_bind_meta_infos = pBindInfos->GetMetaStructPointer();
    assert((replay_bind_infos != nullptr) && (replay_bind_meta_infos != nullptr));

    std::vector<ImageInfo*>                            image_infos;
    std::vector<const DeviceMemoryInfo*>               memory_infos;
    std::vector<VulkanResourceAllocator::ResourceData> allocator_image_datas(bindInfoCount, 0);
    std::vector<VulkanResourceAllocator::MemoryData>   allocator_memory_datas(bindInfoCount, 0);
    std::vector<VkMemoryPropertyFlags>                 memory_property_flags(bindInfoCount, 0);

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        const Decoded_VkBindImageMemoryInfo* bind_meta_info = &replay_bind_meta_infos[i];

        auto image_info  = object_info_table_.GetImageInfo(bind_meta_info->image);
        auto memory_info = object_info_table_.GetDeviceMemoryInfo(bind_meta_info->memory);

        image_infos.push_back(image_info);
        memory_infos.push_back(memory_info);

        if (image_info != nullptr)
        {
            allocator_image_datas[i] = image_info->allocator_data;
        }

        if (memory_info != nullptr)
        {
            allocator_memory_datas[i] = memory_info->allocator_data;
        }
    }

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VkResult result = allocator->BindImageMemory2(bindInfoCount,
                                                  replay_bind_infos,
                                                  allocator_image_datas.data(),
                                                  allocator_memory_datas.data(),
                                                  memory_property_flags.data());

    if (result == VK_SUCCESS)
    {

        for (uint32_t i = 0; i < bindInfoCount; ++i)
        {
            const VkBindImageMemoryInfo* bind_info = &replay_bind_infos[i];

            auto image_info  = image_infos[i];
            auto memory_info = memory_infos[i];

            image_info->bind_offset           = bind_info->memoryOffset;
            image_info->memory                = memory_info->handle;
            image_info->memory_allocator_data = memory_info->allocator_data;
            image_info->memory_property_flags = memory_property_flags[i];
        }
    }
    else if (original_result == VK_SUCCESS)
    {
        // When bind fails at replay, but succeeded at capture, check for memory incompatibilities and recommend
        // enabling memory translation.
        allocator->ReportBindImage2Incompatibility(
            bindInfoCount, replay_bind_infos, allocator_image_datas.data(), allocator_memory_datas.data());
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideCreateBuffer(PFN_vkCreateBuffer                                      func,
                                               VkResult                                                original_result,
                                               const DeviceInfo*                                       device_info,
                                               const StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
                                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                               HandlePointerDecoder<VkBuffer>*                            pBuffer)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && (pBuffer != nullptr) && !pBuffer->IsNull() &&
           (pBuffer->GetHandlePointer() != nullptr));

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VulkanResourceAllocator::ResourceData allocator_data;
    auto                                  replay_buffer = pBuffer->GetHandlePointer();
    auto                                  capture_id    = (*pBuffer->GetPointer());

    VkResult result = allocator->CreateBuffer(
        pCreateInfo->GetPointer(), GetAllocationCallbacks(pAllocator), capture_id, replay_buffer, &allocator_data);

    auto replay_create_info = pCreateInfo->GetPointer();

    if ((result == VK_SUCCESS) && (replay_create_info != nullptr) && ((*replay_buffer) != VK_NULL_HANDLE))
    {
        auto buffer_info = reinterpret_cast<BufferInfo*>(pBuffer->GetConsumerData(0));
        assert(buffer_info != nullptr);

        buffer_info->allocator_data = allocator_data;
        buffer_info->usage          = replay_create_info->usage;

        if ((replay_create_info->sharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (replay_create_info->queueFamilyIndexCount > 0) && (replay_create_info->pQueueFamilyIndices != nullptr))
        {
            buffer_info->queue_family_index = replay_create_info->pQueueFamilyIndices[0];
        }
        else
        {
            buffer_info->queue_family_index = 0;
        }
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideDestroyBuffer(
    PFN_vkDestroyBuffer                                        func,
    const DeviceInfo*                                          device_info,
    BufferInfo*                                                buffer_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert(device_info != nullptr);

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VkBuffer                              buffer         = VK_NULL_HANDLE;
    VulkanResourceAllocator::ResourceData allocator_data = 0;

    if (buffer_info != nullptr)
    {
        buffer         = buffer_info->handle;
        allocator_data = buffer_info->allocator_data;

        buffer_info->allocator_data = 0;
    }

    allocator->DestroyBuffer(buffer, GetAllocationCallbacks(pAllocator), allocator_data);
}

VkResult
VulkanReplayConsumerBase::OverrideCreateImage(PFN_vkCreateImage                                      func,
                                              VkResult                                               original_result,
                                              const DeviceInfo*                                      device_info,
                                              const StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
                                              const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                              HandlePointerDecoder<VkImage>*                             pImage)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && (pImage != nullptr) &&
           (pImage->GetHandlePointer() != nullptr));

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VulkanResourceAllocator::ResourceData allocator_data;
    auto                                  replay_image = pImage->GetHandlePointer();
    auto                                  capture_id   = (*pImage->GetPointer());

    VkResult result = allocator->CreateImage(
        pCreateInfo->GetPointer(), GetAllocationCallbacks(pAllocator), capture_id, replay_image, &allocator_data);

    auto replay_create_info = pCreateInfo->GetPointer();

    if ((result == VK_SUCCESS) && (replay_create_info != nullptr) && ((*replay_image) != VK_NULL_HANDLE))
    {
        auto image_info = reinterpret_cast<ImageInfo*>(pImage->GetConsumerData(0));
        assert(image_info != nullptr);

        image_info->allocator_data = allocator_data;
        image_info->usage          = replay_create_info->usage;
        image_info->type           = replay_create_info->imageType;
        image_info->format         = replay_create_info->format;
        image_info->extent         = replay_create_info->extent;
        image_info->tiling         = replay_create_info->tiling;
        image_info->sample_count   = replay_create_info->samples;
        image_info->initial_layout = replay_create_info->initialLayout;
        image_info->layer_count    = replay_create_info->arrayLayers;
        image_info->level_count    = replay_create_info->mipLevels;

        if ((replay_create_info->sharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (replay_create_info->queueFamilyIndexCount > 0) && (replay_create_info->pQueueFamilyIndices != nullptr))
        {
            image_info->queue_family_index = replay_create_info->pQueueFamilyIndices[0];
        }
        else
        {
            image_info->queue_family_index = 0;
        }
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideDestroyImage(
    PFN_vkDestroyImage                                         func,
    const DeviceInfo*                                          device_info,
    ImageInfo*                                                 image_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert(device_info != nullptr);

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VkImage                               image          = VK_NULL_HANDLE;
    VulkanResourceAllocator::ResourceData allocator_data = 0;

    if (image_info != nullptr)
    {
        image          = image_info->handle;
        allocator_data = image_info->allocator_data;

        image_info->allocator_data = 0;
    }

    allocator->DestroyImage(image, GetAllocationCallbacks(pAllocator), allocator_data);
}

void VulkanReplayConsumerBase::OverrideGetImageSubresourceLayout(
    PFN_vkGetImageSubresourceLayout                         func,
    const DeviceInfo*                                       device_info,
    const ImageInfo*                                        image_info,
    const StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>*      pLayout)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert((device_info != nullptr) && (image_info != nullptr) && (pSubresource != nullptr) &&
           !pSubresource->IsNull() && (pLayout != nullptr) && !pLayout->IsNull() &&
           (pLayout->GetOutputPointer() != nullptr));

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    allocator->GetImageSubresourceLayout(image_info->handle,
                                         pSubresource->GetPointer(),
                                         pLayout->GetOutputPointer(),
                                         pLayout->GetPointer(),
                                         image_info->allocator_data);
}

VkResult VulkanReplayConsumerBase::OverrideCreateDescriptorUpdateTemplate(
    PFN_vkCreateDescriptorUpdateTemplate                                      func,
    VkResult                                                                  original_result,
    const DeviceInfo*                                                         device_info,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>*                         pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && (pDescriptorUpdateTemplate != nullptr) &&
           (pDescriptorUpdateTemplate->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    if (replay_create_info != nullptr)
    {
        // Modify the layout of the update template entries to match the tight packing performed by the trace encoding.
        // The trace encoding wrote the update template entries as a tightly packed array of VkDescriptorImageInfo
        // values, followed by an array of VkDescriptorBufferInfo values, followed by an array of VkBufferView values.
        VkDescriptorUpdateTemplateCreateInfo override_create_info = (*replay_create_info);

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

        // Track descriptor image type.
        std::vector<VkDescriptorType> image_types;

        for (auto entry = entries.begin(); entry != entries.end(); ++entry)
        {
            VkDescriptorType type = entry->descriptorType;

            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                image_types.insert(image_types.end(), entry->descriptorCount, entry->descriptorType);

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

        auto replay_template = pDescriptorUpdateTemplate->GetHandlePointer();

        VkResult result =
            func(device_info->handle, &override_create_info, GetAllocationCallbacks(pAllocator), replay_template);

        if ((result == VK_SUCCESS) && ((*replay_template) != VK_NULL_HANDLE))
        {
            auto update_template_info =
                reinterpret_cast<DescriptorUpdateTemplateInfo*>(pDescriptorUpdateTemplate->GetConsumerData(0));
            assert(update_template_info != nullptr);

            update_template_info->descriptor_image_types = std::move(image_types);
        }

        return result;
    }
    else
    {
        return func(device_info->handle,
                    replay_create_info,
                    GetAllocationCallbacks(pAllocator),
                    pDescriptorUpdateTemplate->GetHandlePointer());
    }
}

void VulkanReplayConsumerBase::OverrideDestroyDescriptorUpdateTemplate(
    PFN_vkDestroyDescriptorUpdateTemplate                      func,
    const DeviceInfo*                                          device_info,
    const DescriptorUpdateTemplateInfo*                        descriptor_update_template_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    assert(device_info != nullptr);

    VkDevice                   device                     = device_info->handle;
    VkDescriptorUpdateTemplate descriptor_update_template = VK_NULL_HANDLE;

    if (descriptor_update_template_info != nullptr)
    {
        descriptor_update_template = descriptor_update_template_info->handle;
    }

    func(device, descriptor_update_template, GetAllocationCallbacks(pAllocator));
}

VkResult VulkanReplayConsumerBase::OverrideCreateShaderModule(
    PFN_vkCreateShaderModule                                      func,
    VkResult                                                      original_result,
    const DeviceInfo*                                             device_info,
    const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkShaderModule>*                         pShaderModule)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && !pCreateInfo->IsNull() &&
           (pShaderModule != nullptr) && !pShaderModule->IsNull());

    auto original_info = pCreateInfo->GetPointer();
    if (original_result < 0 || options_.replace_dir.empty())
    {
        return func(
            device_info->handle, original_info, GetAllocationCallbacks(pAllocator), pShaderModule->GetHandlePointer());
    }

    VkShaderModuleCreateInfo override_info = *original_info;

    // Replace shader in 'override_info'
    std::unique_ptr<char[]> file_code;
    const uint32_t*         orig_code = original_info->pCode;
    size_t                  orig_size = original_info->codeSize;
    uint32_t                check_sum = util::hash::CheckSum(orig_code, orig_size);
    std::string             file_name = "sh" + std::to_string(check_sum);
    std::string             file_path = util::filepath::Join(options_.replace_dir, file_name);

    FILE*   fp     = nullptr;
    int32_t result = util::platform::FileOpen(&fp, file_path.c_str(), "rb");
    if (result == 0)
    {
        util::platform::FileSeek(fp, 0L, util::platform::FileSeekEnd);
        size_t file_size = static_cast<size_t>(util::platform::FileTell(fp));
        file_code        = std::make_unique<char[]>(file_size);
        util::platform::FileSeek(fp, 0L, util::platform::FileSeekSet);
        util::platform::FileRead(file_code.get(), sizeof(char), file_size, fp);
        override_info.pCode    = (uint32_t*)file_code.get();
        override_info.codeSize = file_size;
        GFXRECON_LOG_INFO("Replacement shader found: %s", file_path.c_str());
    }

    return func(
        device_info->handle, &override_info, GetAllocationCallbacks(pAllocator), pShaderModule->GetHandlePointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreatePipelineCache(
    PFN_vkCreatePipelineCache                                      func,
    VkResult                                                       original_result,
    const DeviceInfo*                                              device_info,
    const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkPipelineCache>*                         pPipelineCache)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && (pPipelineCache != nullptr) &&
           (pPipelineCache->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    if (options_.omit_pipeline_cache_data && (replay_create_info != nullptr))
    {
        // Make a shallow copy of the create info structure and clear the cache data.
        VkPipelineCacheCreateInfo override_create_info = (*replay_create_info);
        override_create_info.initialDataSize           = 0;
        override_create_info.pInitialData              = nullptr;

        return func(device_info->handle,
                    &override_create_info,
                    GetAllocationCallbacks(pAllocator),
                    pPipelineCache->GetHandlePointer());
    }
    else
    {
        return func(device_info->handle,
                    replay_create_info,
                    GetAllocationCallbacks(pAllocator),
                    pPipelineCache->GetHandlePointer());
    }
}

VkResult VulkanReplayConsumerBase::OverrideCreateDebugReportCallbackEXT(
    PFN_vkCreateDebugReportCallbackEXT                                      func,
    VkResult                                                                original_result,
    const InstanceInfo*                                                     instance_info,
    const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*              pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>*                         pCallback)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr) && (pCallback != nullptr) &&
           (pCallback->GetHandlePointer() != nullptr));

    VkDebugReportCallbackCreateInfoEXT modified_create_info{};

    if (!pCreateInfo->IsNull())
    {
        modified_create_info             = (*pCreateInfo->GetPointer());
        modified_create_info.pfnCallback = DebugReportCallback;
    }
    else
    {
        GFXRECON_LOG_WARNING("The vkCreateDebugReportCallbackEXT parameter pCreateInfo is NULL.");
    }

    return func(instance_info->handle,
                &modified_create_info,
                GetAllocationCallbacks(pAllocator),
                pCallback->GetHandlePointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreateDebugUtilsMessengerEXT(
    PFN_vkCreateDebugUtilsMessengerEXT                                      func,
    VkResult                                                                original_result,
    const InstanceInfo*                                                     instance_info,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*              pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>*                         pMessenger)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr) && (pMessenger != nullptr) &&
           (pMessenger->GetHandlePointer() != nullptr));

    VkDebugUtilsMessengerCreateInfoEXT modified_create_info{};
    if (!pCreateInfo->IsNull())
    {
        modified_create_info                 = (*pCreateInfo->GetPointer());
        modified_create_info.pfnUserCallback = DebugUtilsCallback;
    }
    else
    {
        GFXRECON_LOG_WARNING("The vkCreateDebugUtilsMessengerEXT parameter pCreateInfo is NULL.");
    }

    return func(instance_info->handle,
                &modified_create_info,
                GetAllocationCallbacks(pAllocator),
                pMessenger->GetHandlePointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreateSwapchainKHR(
    PFN_vkCreateSwapchainKHR                                      func,
    VkResult                                                      original_result,
    DeviceInfo*                                                   device_info,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                         pSwapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && (pSwapchain != nullptr) &&
           (pSwapchain->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_swapchain   = pSwapchain->GetHandlePointer();

    ProcessSwapchainFullScreenExclusiveInfo(pCreateInfo->GetMetaStructPointer());

    VkResult result =
        func(device_info->handle, replay_create_info, GetAllocationCallbacks(pAllocator), replay_swapchain);

    if ((result == VK_SUCCESS) && (replay_create_info != nullptr) && ((*replay_swapchain) != VK_NULL_HANDLE))
    {
        auto swapchain_info = reinterpret_cast<SwapchainKHRInfo*>(pSwapchain->GetConsumerData(0));
        assert(swapchain_info != nullptr);

        if ((replay_create_info->imageSharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (replay_create_info->queueFamilyIndexCount > 0) && (replay_create_info->pQueueFamilyIndices != nullptr))
        {
            swapchain_info->queue_family_index = replay_create_info->pQueueFamilyIndices[0];
        }
        else
        {
            swapchain_info->queue_family_index = 0;
        }

        swapchain_info->surface = replay_create_info->surface;

        device_info->active_swapchains.insert(*replay_swapchain);
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideDestroySwapchainKHR(
    PFN_vkDestroySwapchainKHR                                  func,
    DeviceInfo*                                                device_info,
    const SwapchainKHRInfo*                                    swapchain_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    assert(device_info != nullptr);

    VkDevice       device    = device_info->handle;
    VkSwapchainKHR swapchain = VK_NULL_HANDLE;

    if (swapchain_info != nullptr)
    {
        swapchain = swapchain_info->handle;
        device_info->active_swapchains.erase(swapchain);
    }

    func(device, swapchain, GetAllocationCallbacks(pAllocator));
}

VkResult VulkanReplayConsumerBase::OverrideAcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                                               VkResult                  original_result,
                                                               const DeviceInfo*         device_info,
                                                               const SwapchainKHRInfo*   swapchain_info,
                                                               uint64_t                  timeout,
                                                               const SemaphoreInfo*      semaphore_info,
                                                               const FenceInfo*          fence_info,
                                                               PointerDecoder<uint32_t>* pImageIndex)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (swapchain_info != nullptr) && (pImageIndex != nullptr) &&
           (pImageIndex->GetPointer() != nullptr));

    VkResult       result               = VK_SUCCESS;
    VkDevice       device               = device_info->handle;
    VkSwapchainKHR swapchain            = swapchain_info->handle;
    VkSemaphore    semaphore            = (semaphore_info != nullptr) ? semaphore_info->handle : VK_NULL_HANDLE;
    VkFence        fence                = (fence_info != nullptr) ? fence_info->handle : VK_NULL_HANDLE;
    VkSemaphore    preacquire_semaphore = VK_NULL_HANDLE;
    VkFence        preacquire_fence     = VK_NULL_HANDLE;
    uint32_t       captured_index       = (*pImageIndex->GetPointer());

    if (swapchain_image_tracker_.RetrievePreAcquiredImage(
            swapchain, captured_index, &preacquire_semaphore, &preacquire_fence))
    {
        auto table = GetDeviceTable(device);
        assert(table != nullptr);

        // The image has already been acquired. Swap the synchronization objects.
        if (semaphore != VK_NULL_HANDLE)
        {
            // TODO: This should be processed at a higher level where the original handle IDs are available, so that the
            // swap can be performed with the original handle ID and the semaphore can be guaranteed not to be used
            // after destroy.
            object_info_table_.ReplaceSemaphore(semaphore, preacquire_semaphore);
            preacquire_semaphore = semaphore;
        }

        if (fence != VK_NULL_HANDLE)
        {
            // TODO: This should be processed at a higher level where the original handle IDs are available, so that the
            // swap can be performed with the original handle ID and the fence can be guaranteed not to be used
            // after destroy.
            object_info_table_.ReplaceFence(fence, preacquire_fence);
            preacquire_fence = fence;
        }

        table->DestroySemaphore(device, preacquire_semaphore, nullptr);
        table->DestroyFence(device, preacquire_fence, nullptr);
    }
    else
    {
        assert(pImageIndex->GetOutputPointer() != nullptr);

        result = func(device, swapchain, timeout, semaphore, fence, pImageIndex->GetOutputPointer());
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAcquireNextImage2KHR(
    PFN_vkAcquireNextImage2KHR                                     func,
    VkResult                                                       original_result,
    const DeviceInfo*                                              device_info,
    const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                                      pImageIndex)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pAcquireInfo != nullptr) && !pAcquireInfo->IsNull() &&
           (pImageIndex != nullptr) && (pImageIndex->GetPointer() != nullptr));

    VkResult    result               = VK_SUCCESS;
    VkDevice    device               = device_info->handle;
    VkSemaphore preacquire_semaphore = VK_NULL_HANDLE;
    VkFence     preacquire_fence     = VK_NULL_HANDLE;
    auto        replay_acquire_info  = pAcquireInfo->GetPointer();
    uint32_t    captured_index       = (*pImageIndex->GetPointer());

    if (swapchain_image_tracker_.RetrievePreAcquiredImage(
            replay_acquire_info->swapchain, captured_index, &preacquire_semaphore, &preacquire_fence))
    {
        auto table = GetDeviceTable(device);
        assert(table != nullptr);

        // The image has already been acquired. Swap the synchronization objects.
        if (replay_acquire_info->semaphore != VK_NULL_HANDLE)
        {
            // TODO: This should be processed at a higher level where the original handle IDs are available, so that the
            // swap can be performed with the original handle ID and the semaphore can be guaranteed not to be used
            // after destroy.
            object_info_table_.ReplaceSemaphore(replay_acquire_info->semaphore, preacquire_semaphore);
            preacquire_semaphore = replay_acquire_info->semaphore;
        }

        if (replay_acquire_info->fence != VK_NULL_HANDLE)
        {
            // TODO: This should be processed at a higher level where the original handle IDs are available, so that the
            // swap can be performed with the original handle ID and the fence can be guaranteed not to be used
            // after destroy.
            object_info_table_.ReplaceFence(replay_acquire_info->fence, preacquire_fence);
            preacquire_fence = replay_acquire_info->fence;
        }

        table->DestroySemaphore(device, preacquire_semaphore, nullptr);
        table->DestroyFence(device, preacquire_fence, nullptr);
    }
    else
    {
        assert(pImageIndex->GetOutputPointer() != nullptr);

        result = func(device, replay_acquire_info, pImageIndex->GetOutputPointer());
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateAndroidSurfaceKHR(
    PFN_vkCreateAndroidSurfaceKHR                                      func,
    VkResult                                                           original_result,
    InstanceInfo*                                                      instance_info,
    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info, replay_create_info->flags, pSurface);
}

VkResult VulkanReplayConsumerBase::OverrideCreateWin32SurfaceKHR(
    PFN_vkCreateWin32SurfaceKHR                                      func,
    VkResult                                                         original_result,
    InstanceInfo*                                                    instance_info,
    const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                              pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info, replay_create_info->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceWin32PresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
    const PhysicalDeviceInfo*                          physical_device_info,
    uint32_t                                           queueFamilyIndex)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physical_device), physical_device, queueFamilyIndex);
}

VkResult VulkanReplayConsumerBase::OverrideCreateXcbSurfaceKHR(
    PFN_vkCreateXcbSurfaceKHR                                      func,
    VkResult                                                       original_result,
    InstanceInfo*                                                  instance_info,
    const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                            pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info, replay_create_info->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceXcbPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
    const PhysicalDeviceInfo*                        physical_device_info,
    uint32_t                                         queueFamilyIndex,
    xcb_connection_t*                                connection,
    xcb_visualid_t                                   visual_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(connection);
    GFXRECON_UNREFERENCED_PARAMETER(visual_id);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physical_device), physical_device, queueFamilyIndex);
}

VkResult VulkanReplayConsumerBase::OverrideCreateXlibSurfaceKHR(
    PFN_vkCreateXlibSurfaceKHR                                      func,
    VkResult                                                        original_result,
    InstanceInfo*                                                   instance_info,
    const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                             pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info, replay_create_info->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceXlibPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
    const PhysicalDeviceInfo*                         physical_device_info,
    uint32_t                                          queueFamilyIndex,
    Display*                                          dpy,
    VisualID                                          visualID)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(dpy);
    GFXRECON_UNREFERENCED_PARAMETER(visualID);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physical_device), physical_device, queueFamilyIndex);
}

VkResult VulkanReplayConsumerBase::OverrideCreateWaylandSurfaceKHR(
    PFN_vkCreateWaylandSurfaceKHR                                      func,
    VkResult                                                           original_result,
    InstanceInfo*                                                      instance_info,
    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info, replay_create_info->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
    const PhysicalDeviceInfo*                            physical_device_info,
    uint32_t                                             queueFamilyIndex,
    struct wl_display*                                   display)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(display);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physical_device), physical_device, queueFamilyIndex);
}

void VulkanReplayConsumerBase::OverrideDestroySurfaceKHR(
    PFN_vkDestroySurfaceKHR                                    func,
    InstanceInfo*                                              instance_info,
    const SurfaceKHRInfo*                                      surface_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    assert(instance_info != nullptr);

    VkInstance   instance = instance_info->handle;
    VkSurfaceKHR surface  = VK_NULL_HANDLE;
    Window*      window   = nullptr;

    if (surface_info != nullptr)
    {
        surface = surface_info->handle;
        window  = surface_info->window;
        instance_info->active_surfaces.erase(surface);
    }

    func(instance, surface, GetAllocationCallbacks(pAllocator));

    if (window != nullptr)
    {
        active_windows_.erase(window);
        window_factory_->Destroy(window);
    }
}

void VulkanReplayConsumerBase::MapDescriptorUpdateTemplateHandles(
    const DescriptorUpdateTemplateInfo* update_template_info, DescriptorUpdateTemplateDecoder* decoder)
{
    assert(decoder != nullptr);

    size_t image_info_count        = decoder->GetImageInfoCount();
    size_t buffer_info_count       = decoder->GetBufferInfoCount();
    size_t texel_buffer_view_count = decoder->GetTexelBufferViewCount();

    if (image_info_count > 0)
    {
        if (update_template_info != nullptr)
        {
            assert(update_template_info->descriptor_image_types.size() >= image_info_count);

            Decoded_VkDescriptorImageInfo* structs = decoder->GetImageInfoMetaStructPointer();
            for (size_t i = 0; i < image_info_count; ++i)
            {
                MapStructHandles(update_template_info->descriptor_image_types[i], &structs[i], object_info_table_);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Missing descriptor update template image descriptor type info; attempting to map both "
                               "VkDescriptorImageInfo handles");

            Decoded_VkDescriptorImageInfo* structs = decoder->GetImageInfoMetaStructPointer();
            for (size_t i = 0; i < image_info_count; ++i)
            {
                MapStructHandles(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, &structs[i], object_info_table_);
            }
        }
    }

    if (buffer_info_count > 0)
    {
        MapStructArrayHandles(decoder->GetBufferInfoMetaStructPointer(), buffer_info_count, object_info_table_);
    }

    if (texel_buffer_view_count > 0)
    {
        auto texel_buffer_view_ids     = decoder->GetTexelBufferViewHandleIdsPointer();
        auto texel_buffer_view_handles = decoder->GetTexelBufferViewPointer();

        for (size_t i = 0; i < texel_buffer_view_count; ++i)
        {
            auto texel_buffer_view_info = object_info_table_.GetBufferViewInfo(texel_buffer_view_ids[i]);

            if (texel_buffer_view_info != nullptr)
            {
                texel_buffer_view_handles[i] = texel_buffer_view_info->handle;
            }
            else
            {
                texel_buffer_view_handles[i] = VK_NULL_HANDLE;
            }
        }
    }
}

void VulkanReplayConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(format::HandleId device,
                                                                         format::HandleId descriptorSet,
                                                                         format::HandleId descriptorUpdateTemplate,
                                                                         DescriptorUpdateTemplateDecoder* pData)
{
    assert(pData != nullptr);

    VkDevice        in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDescriptorSet in_descriptorSet =
        MapHandle<DescriptorSetInfo>(descriptorSet, &VulkanObjectInfoTable::GetDescriptorSetInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = VK_NULL_HANDLE;
    auto update_template_info = object_info_table_.GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(update_template_info, pData);

    if (update_template_info != nullptr)
    {
        in_descriptorUpdateTemplate = update_template_info->handle;
    }

    GetDeviceTable(in_device)->UpdateDescriptorSetWithTemplate(
        in_device, in_descriptorSet, in_descriptorUpdateTemplate, pData->GetPointer());
}

void VulkanReplayConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(format::HandleId commandBuffer,
                                                                             format::HandleId descriptorUpdateTemplate,
                                                                             format::HandleId layout,
                                                                             uint32_t         set,
                                                                             DescriptorUpdateTemplateDecoder* pData)
{
    assert(pData != nullptr);

    VkCommandBuffer in_commandBuffer =
        MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = VK_NULL_HANDLE;
    VkPipelineLayout in_layout = MapHandle<PipelineLayoutInfo>(layout, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    auto update_template_info  = object_info_table_.GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(update_template_info, pData);

    if (update_template_info != nullptr)
    {
        in_descriptorUpdateTemplate = update_template_info->handle;
    }

    GetDeviceTable(in_commandBuffer)
        ->CmdPushDescriptorSetWithTemplateKHR(
            in_commandBuffer, in_descriptorUpdateTemplate, in_layout, set, pData->GetPointer());
}

void VulkanReplayConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(format::HandleId device,
                                                                            format::HandleId descriptorSet,
                                                                            format::HandleId descriptorUpdateTemplate,
                                                                            DescriptorUpdateTemplateDecoder* pData)
{
    assert(pData != nullptr);

    VkDevice        in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDescriptorSet in_descriptorSet =
        MapHandle<DescriptorSetInfo>(descriptorSet, &VulkanObjectInfoTable::GetDescriptorSetInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = VK_NULL_HANDLE;
    auto update_template_info = object_info_table_.GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(update_template_info, pData);

    if (update_template_info != nullptr)
    {
        in_descriptorUpdateTemplate = update_template_info->handle;
    }

    GetDeviceTable(in_device)->UpdateDescriptorSetWithTemplateKHR(
        in_device, in_descriptorSet, in_descriptorUpdateTemplate, pData->GetPointer());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
