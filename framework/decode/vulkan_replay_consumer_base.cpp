/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#include "decode/vulkan_replay_consumer_base.h"
#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/resource_util.h"
#include "decode/vulkan_captured_swapchain.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_virtual_swapchain.h"
#include "decode/vulkan_offscreen_swapchain.h"
#include "decode/vulkan_enum_util.h"
#include "decode/vulkan_feature_util.h"
#include "decode/vulkan_object_cleanup_util.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "generated/generated_vulkan_constant_maps.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_util.h"
#include "util/file_path.h"
#include "util/hash.h"
#include "util/platform.h"
#include "util/logging.h"
#include "util/spirv_parsing_util.h"

#include "spirv_reflect.h"

#include "generated/generated_vulkan_enum_to_string.h"
#include "util/to_string.h"
#include "vulkan/vulkan_core.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <numeric>
#include <unordered_set>
#include <future>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const size_t kMaxEventStatusRetries      = 16;
const size_t kMaxQueryPoolResultsRetries = 16;

const char kUnknownDeviceLabel[]  = "<Unknown>";
const char kValidationLayerName[] = "VK_LAYER_KHRONOS_validation";

const std::unordered_set<std::string> kSurfaceExtensions = {
    VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, VK_MVK_IOS_SURFACE_EXTENSION_NAME, VK_MVK_MACOS_SURFACE_EXTENSION_NAME,
    VK_KHR_MIR_SURFACE_EXTENSION_NAME,     VK_NN_VI_SURFACE_EXTENSION_NAME,   VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
    VK_KHR_WIN32_SURFACE_EXTENSION_NAME,   VK_KHR_XCB_SURFACE_EXTENSION_NAME, VK_KHR_XLIB_SURFACE_EXTENSION_NAME,
    VK_EXT_METAL_SURFACE_EXTENSION_NAME,
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
        (pCallbackData->pMessage != nullptr))
    {
        if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT)
        {
            GFXRECON_LOG_ERROR("DEBUG MESSENGER: %s: %s", pCallbackData->pMessageIdName, pCallbackData->pMessage);
        }
        else if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
        {
            GFXRECON_LOG_WARNING("DEBUG MESSENGER: %s: %s", pCallbackData->pMessageIdName, pCallbackData->pMessage);
        }
        else if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT)
        {
            GFXRECON_LOG_INFO("DEBUG MESSENGER: %s: %s", pCallbackData->pMessageIdName, pCallbackData->pMessage);
        }
        else
        {
            GFXRECON_LOG_DEBUG("DEBUG MESSENGER: %s: %s", pCallbackData->pMessageIdName, pCallbackData->pMessage);
        }
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

VulkanReplayConsumerBase::VulkanReplayConsumerBase(std::shared_ptr<application::Application> application,
                                                   const VulkanReplayOptions&                options) :
    resource_dumper_(options, object_info_table_),
    loader_handle_(nullptr), get_instance_proc_addr_(nullptr), create_instance_proc_(nullptr),
    application_(application), options_(options), loading_trim_state_(false), replaying_trimmed_capture_(false),
    have_imported_semaphores_(false), fps_info_(nullptr), omitted_pipeline_cache_data_(false)
{
    assert(application_ != nullptr);
    assert(options.create_resource_allocator != nullptr);
    if (!options.screenshot_ranges.empty())
    {
        InitializeScreenshotHandler();
    }

    switch (options.swapchain_option)
    {
        case util::SwapchainOption::kCaptured:
            swapchain_ = std::make_unique<VulkanCapturedSwapchain>();
            break;
        case util::SwapchainOption::kOffscreen:
            swapchain_ = std::make_unique<VulkanOffscreenSwapchain>();
            break;
        default:
            swapchain_ = std::make_unique<VulkanVirtualSwapchain>();
    }

    VulkanSwapchainOptions swapchain_options;
    swapchain_options.skip_additional_present_blts = options.virtual_swapchain_skip_blit;
    swapchain_options.select_surface_index         = options_.surface_index;
    swapchain_->SetOptions(swapchain_options);

    if (options_.enable_debug_device_lost)
    {
        GFXRECON_LOG_WARNING("This debugging feature has not been implemented for Vulkan.");
    }
}

VulkanReplayConsumerBase::~VulkanReplayConsumerBase()
{
    // Idle all devices before destroying other resources.
    WaitDevicesIdle();

    // Cleanup screenshot resources before destroying device.
    object_info_table_.VisitVkDeviceInfo([this](const VulkanDeviceInfo* info) {
        assert(info != nullptr);
        VkDevice device = info->handle;

        auto device_table = GetDeviceTable(device);
        assert(device_table != nullptr);

        if (screenshot_handler_ != nullptr)
        {
            screenshot_handler_->DestroyDeviceResources(device, device_table);
        }
    });

    object_cleanup::FreeAllLiveObjects(
        &object_info_table_,
        false,
        true,
        [this](const void* handle) { return GetInstanceTable(handle); },
        [this](const void* handle) { return GetDeviceTable(handle); },
        swapchain_.get());

    swapchain_->Clean();

    // Finally destroy vkInstances
    object_cleanup::FreeAllLiveInstances(
        &object_info_table_,
        false,
        true,
        [this](const void* handle) { return GetInstanceTable(handle); },
        [this](const void* handle) { return GetDeviceTable(handle); });

    if (loader_handle_ != nullptr)
    {
        graphics::ReleaseLoader(loader_handle_);
    }
}

void VulkanReplayConsumerBase::WaitDevicesIdle()
{
    object_info_table_.VisitVkDeviceInfo([this](const VulkanDeviceInfo* info) {
        assert(info != nullptr);
        VkDevice device = info->handle;

        auto device_table = GetDeviceTable(device);
        assert(device_table != nullptr);

        device_table->DeviceWaitIdle(device);
    });
}

void VulkanReplayConsumerBase::ProcessStateBeginMarker(uint64_t frame_number)
{
    GFXRECON_UNREFERENCED_PARAMETER(frame_number);
    loading_trim_state_ = true;

    // If a trace file has the state begin marker, it must be a trim trace file.
    replaying_trimmed_capture_ = true;
}

void VulkanReplayConsumerBase::ProcessStateEndMarker(uint64_t frame_number)
{
    GFXRECON_UNREFERENCED_PARAMETER(frame_number);
    loading_trim_state_ = false;
    if (fps_info_ != nullptr)
    {
        fps_info_->ProcessStateEndMarker(frame_number);
    }
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
    const VulkanDeviceMemoryInfo* memory_info = object_info_table_.GetVkDeviceMemoryInfo(memory_id);

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

                if (buffer_info.plane_info.size() == 1)
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, offset);

                    size_t   data_size         = static_cast<size_t>(size);
                    size_t   data_offset       = static_cast<size_t>(offset);
                    size_t   capture_row_pitch = buffer_info.plane_info[0].capture_row_pitch;
                    size_t   replay_row_pitch  = buffer_info.plane_info[0].replay_row_pitch;
                    uint32_t height            = buffer_info.plane_info[0].height;

                    resource::CopyImageSubresourceMemory(static_cast<uint8_t*>(buffer_data),
                                                         data,
                                                         data_offset,
                                                         data_size,
                                                         replay_row_pitch,
                                                         capture_row_pitch,
                                                         height);
                }
                else
                {
                    // TODO: multi-plane image format support when strides do not match.
                    GFXRECON_LOG_WARNING("Ignoring fill memory command for AHardwareBuffer with multi-plane format and "
                                         "mismatched capture/replay strides (Memory ID = %" PRIu64
                                         "): support not yet implemented",
                                         memory_id);
                }

                lock_result = AHardwareBuffer_unlock(buffer_info.hardware_buffer, nullptr);
                if (lock_result != 0)
                {
                    GFXRECON_LOG_WARNING(
                        "AHardwareBuffer_unlock failed for AHardwareBuffer object (Memory ID = %" PRIu64 ")",
                        memory_id);
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("AHardwareBuffer_lock failed for AHardwareBuffer object (Memory ID = %" PRIu64 ")",
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
    const VulkanSurfaceKHRInfo* surface_info = object_info_table_.GetVkSurfaceKHRInfo(surface_id);

    if (surface_info != nullptr)
    {
        Window* window = surface_info->window;

        if (window != nullptr)
        {
            window->SetSize(width, height);
        }
        else
        {
            if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
            {
                GFXRECON_LOG_DEBUG("Skipping window resize for VkSurface object (ID = %" PRIu64
                                   ") without an associated window",
                                   surface_id);
            }
            else
            {
                GFXRECON_LOG_WARNING("Skipping window resize for VkSurface object (ID = %" PRIu64
                                     ") without an associated window",
                                     surface_id);
            }
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
    const VulkanSurfaceKHRInfo* surface_info = object_info_table_.GetVkSurfaceKHRInfo(surface_id);

    if (surface_info != nullptr)
    {
        Window* window = surface_info->window;

        if (window != nullptr)
        {
            window->SetSizePreTransform(width, height, pre_transform);
        }
        else
        {
            if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
            {
                GFXRECON_LOG_DEBUG("Skipping window resize for VkSurface object (ID = %" PRIu64
                                   ") without an associated window",
                                   surface_id);
            }
            else
            {
                GFXRECON_LOG_WARNING("Skipping window resize for VkSurface object (ID = %" PRIu64
                                     ") without an associated window",
                                     surface_id);
            }
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
    uint64_t                                            usage,
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

    AHardwareBuffer* buffer = nullptr;
    int              result = AHardwareBuffer_allocate(&desc, &buffer);
    if ((result == 0) && (buffer != nullptr))
    {
        HardwareBufferInfo& ahb_info = hardware_buffers_[buffer_id];
        ahb_info.memory_id           = memory_id;
        ahb_info.hardware_buffer     = buffer;

        result = -1;

        std::vector<format::HardwareBufferPlaneInfo> replay_plane_info;

        // The multi-plane functions are declared for API 26, but are only available to link with API 29.  So, this
        // could be turned into a run-time check dependent on dlsym returning a valid pointer for
        // AHardwareBuffer_lockPlanes.
#if __ANDROID_API__ >= 29
        if (desc.usage & AHARDWAREBUFFER_USAGE_CPU_WRITE_MASK)
        {
            AHardwareBuffer_Planes ahb_planes;
            result =
                AHardwareBuffer_lockPlanes(buffer, AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN, -1, nullptr, &ahb_planes);
            if (result == 0)
            {
                void* data = ahb_planes.planes[0].data;

                for (uint32_t i = 0; i < ahb_planes.planeCount; ++i)
                {
                    format::HardwareBufferPlaneInfo ahb_plane_info;
                    ahb_plane_info.offset =
                        reinterpret_cast<uint8_t*>(ahb_planes.planes[i].data) - reinterpret_cast<uint8_t*>(data);
                    ahb_plane_info.pixel_stride = ahb_planes.planes[i].pixelStride;
                    ahb_plane_info.row_pitch    = ahb_planes.planes[i].rowStride;
                    replay_plane_info.emplace_back(std::move(ahb_plane_info));
                }

                if (AHardwareBuffer_unlock(buffer, nullptr) != 0)
                {
                    GFXRECON_LOG_ERROR("AHardwareBuffer_unlock failed for AHardwareBuffer object (Buffer ID = %" PRIu64
                                       ", Memory ID = %" PRIu64 ")",
                                       buffer_id,
                                       memory_id);
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("AHardwareBuffer_lockPlanes failed.");
            }
        }
#endif

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
            memory_info.plane_info[0].height            = height;
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
                memory_info.plane_info[i].height            = height;

                if ((plane_info[i].offset != replay_plane_info[i].offset) ||
                    (plane_info[i].row_pitch != replay_plane_info[i].row_pitch))
                {
                    memory_info.compatible_strides = false;
                }
            }
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
    VulkanPhysicalDeviceInfo* physical_device_info = object_info_table_.GetVkPhysicalDeviceInfo(physical_device_id);

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
    VulkanPhysicalDeviceInfo* physical_device_info = object_info_table_.GetVkPhysicalDeviceInfo(physical_device_id);

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

void VulkanReplayConsumerBase::ProcessSetOpaqueAddressCommand(format::HandleId device_id,
                                                              format::HandleId object_id,
                                                              uint64_t         address)
{
    VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(device_id);

    if (device_info != nullptr)
    {
        // Store the opaque address to use at object creation.
        device_info->opaque_addresses[object_id] = address;
    }
}

void VulkanReplayConsumerBase::ProcessSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                                             format::HandleId pipeline_id,
                                                                             size_t           data_size,
                                                                             const uint8_t*   data)
{
    VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(device_id);
    if (device_info != nullptr)
    {
        // There should only be one dataset per pipeline.
        assert(device_info->shader_group_handles.find(pipeline_id) == device_info->shader_group_handles.end());

        // Store the ray tracing shader group handle data to use at ray tracing pipeline creation.
        device_info->shader_group_handles.emplace(pipeline_id, std::vector<uint8_t>(data, data + data_size));
    }
}

void VulkanReplayConsumerBase::ProcessSetSwapchainImageStateCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_info)
{
    const VulkanDeviceInfo* device_info    = object_info_table_.GetVkDeviceInfo(device_id);
    VulkanSwapchainKHRInfo* swapchain_info = object_info_table_.GetVkSwapchainKHRInfo(swapchain_id);

    if ((device_info != nullptr) && (swapchain_info != nullptr))
    {
        assert((device_info->handle != VK_NULL_HANDLE) && (swapchain_info->handle != VK_NULL_HANDLE));
        swapchain_->ProcessSetSwapchainImageStateCommand(device_info,
                                                         swapchain_info,
                                                         last_presented_image,
                                                         image_info,
                                                         object_info_table_,
                                                         swapchain_image_tracker_);
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

void VulkanReplayConsumerBase::ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                               uint64_t         max_resource_size,
                                                               uint64_t         max_copy_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(max_resource_size);

    VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(device_id);

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
            device_info, max_copy_size, properties, have_shader_stencil_write, allocator, table);
    }
}

void VulkanReplayConsumerBase::ProcessEndResourceInitCommand(format::HandleId device_id)
{
    VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(device_id);

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
    VulkanDeviceInfo*       device_info = object_info_table_.GetVkDeviceInfo(device_id);
    const VulkanBufferInfo* buffer_info = object_info_table_.GetVkBufferInfo(buffer_id);

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
                result = initializer->LoadData(data_size, data, buffer_info->allocator_data);

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
    VulkanDeviceInfo*      device_info = object_info_table_.GetVkDeviceInfo(device_id);
    const VulkanImageInfo* image_info  = object_info_table_.GetVkImageInfo(image_id);

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
                    (image_info->memory_property_flags &
                     (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT)) ==
                        (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT))
                {
                    result = initializer->LoadData(data_size, data, image_info->allocator_data);

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
    loader_handle_ = graphics::InitializeLoader();
    if (loader_handle_ != nullptr)
    {
        get_instance_proc_addr_ = reinterpret_cast<PFN_vkGetInstanceProcAddr>(
            util::platform::GetProcAddress(loader_handle_, "vkGetInstanceProcAddr"));
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
                           graphics::kLoaderLibNames[0].c_str());
        RaiseFatalError("Failed to load Vulkan runtime library");
    }
}

void VulkanReplayConsumerBase::AddInstanceTable(VkInstance instance)
{
    encode::VulkanDispatchKey dispatch_key = encode::GetVulkanDispatchKey(instance);

    get_device_proc_addrs_[dispatch_key] =
        reinterpret_cast<PFN_vkGetDeviceProcAddr>(get_instance_proc_addr_(instance, "vkGetDeviceProcAddr"));
    create_device_procs_[dispatch_key] =
        reinterpret_cast<PFN_vkCreateDevice>(get_instance_proc_addr_(instance, "vkCreateDevice"));

    encode::VulkanInstanceTable& table = instance_tables_[dispatch_key];
    encode::LoadVulkanInstanceTable(get_instance_proc_addr_, instance, &table);
}

void VulkanReplayConsumerBase::AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa)
{
    encode::VulkanDeviceTable& table = device_tables_[encode::GetVulkanDispatchKey(device)];
    encode::LoadVulkanDeviceTable(gpa, device, &table);
}

PFN_vkGetDeviceProcAddr VulkanReplayConsumerBase::GetDeviceAddrProc(VkPhysicalDevice physical_device)
{
    return get_device_proc_addrs_[encode::GetVulkanDispatchKey(physical_device)];
}

PFN_vkCreateDevice VulkanReplayConsumerBase::GetCreateDeviceProc(VkPhysicalDevice physical_device)
{
    return create_device_procs_[encode::GetVulkanDispatchKey(physical_device)];
}

const encode::VulkanInstanceTable* VulkanReplayConsumerBase::GetInstanceTable(const void* handle) const
{
    auto table = instance_tables_.find(encode::GetVulkanDispatchKey(handle));
    assert(table != instance_tables_.end());
    return (table != instance_tables_.end()) ? &table->second : nullptr;
}

const encode::VulkanDeviceTable* VulkanReplayConsumerBase::GetDeviceTable(const void* handle) const
{
    auto table = device_tables_.find(encode::GetVulkanDispatchKey(handle));
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
        (call_id == format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR) ||
        (call_id == format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT) ||
        (call_id == format::ApiCallId::ApiCall_vkCmdSetCheckpointNV))
    {
        // The window system related handles are ignored by replay.
        // The checkpoint marker is ignored by replay.
    }
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    else if (call_id == format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID)
    {
        // Get the hardware buffer from the decoded buffer id.
        auto entry = hardware_buffers_.find(object_id);
        if (entry != hardware_buffers_.end())
        {
            object = entry->second.hardware_buffer;
        }
        else
        {
            GFXRECON_LOG_WARNING_ONCE("Failed to find a valid AHardwareBuffer handle for a call to %s", call_name);
        }
    }
#endif
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

void VulkanReplayConsumerBase::CheckResult(const char*                func_name,
                                           VkResult                   original,
                                           VkResult                   replay,
                                           const decode::ApiCallInfo& call_info)
{
    if (original != replay)
    {
        if ((replay < 0) && (replay != VK_ERROR_FORMAT_NOT_SUPPORTED))
        {
            // Raise a fatal error if replay produced an error that did not occur during capture.  Format not supported
            // errors are not treated as fatal, but will be reported as warnings below, allowing the replay to attempt
            // to continue for the case where an application may have queried for formats that it did not use.
            GFXRECON_LOG_FATAL(
                "API call at index: %d thread: %d %s returned error value %s that does not match the result from the "
                "capture file: %s. Replay cannot continue.",
                call_info.index,
                call_info.thread_id,
                func_name,
                util::ToString<VkResult>(replay).c_str(),
                util::ToString<VkResult>(original).c_str());

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
                util::ToString<VkResult>(replay).c_str(),
                util::ToString<VkResult>(original).c_str());
        }
    }
}

void VulkanReplayConsumerBase::SetInstancePhysicalDeviceEntries(VulkanInstanceInfo*     instance_info,
                                                                size_t                  capture_device_count,
                                                                const format::HandleId* capture_devices,
                                                                size_t                  replay_device_count,
                                                                const VkPhysicalDevice* replay_devices)
{
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
        for (size_t i = 0; i < capture_device_count; ++i)
        {
            instance_info->capture_devices.push_back(capture_devices[i]);
        }
    }

    if (instance_info->replay_devices.empty())
    {
        for (size_t i = 0; i < replay_device_count; ++i)
        {
            instance_info->replay_devices.push_back(replay_devices[i]);
        }
    }
}

void VulkanReplayConsumerBase::CheckReplayDeviceInfo(VulkanPhysicalDeviceInfo* physical_device_info)
{
    assert(physical_device_info != nullptr);

    if (physical_device_info->replay_device_info == nullptr)
    {
        // A physical device handle was obtained without calling vkEnumeratePhysicalDevices or
        // vkEnumeratePhysicalDeviceGroups, so the physical device initialization that would have been performed when
        // replaying those calls will be performed here.
        auto instance_info = object_info_table_.GetVkInstanceInfo(physical_device_info->parent_id);
        if (instance_info != nullptr)
        {
            assert(physical_device_info->handle != VK_NULL_HANDLE);
            SetPhysicalDeviceInstanceInfo(instance_info, physical_device_info, physical_device_info->handle);
        }
        else
        {
            GFXRECON_LOG_WARNING("Failed to find VkInstance object (ID = %" PRIu64
                                 ") when attempting to initialize VkPhysicalDevice object (ID = %" PRIu64 ")",
                                 physical_device_info->parent_id,
                                 physical_device_info->capture_id);
        }
    }
}

void VulkanReplayConsumerBase::SetPhysicalDeviceInstanceInfo(VulkanInstanceInfo*       instance_info,
                                                             VulkanPhysicalDeviceInfo* physical_device_info,
                                                             VkPhysicalDevice          replay_device)
{
    assert((instance_info != nullptr) && (physical_device_info != nullptr));

    physical_device_info->parent                    = instance_info->handle;
    physical_device_info->parent_api_version        = instance_info->api_version;
    physical_device_info->parent_enabled_extensions = instance_info->enabled_extensions;
    physical_device_info->replay_device_info        = &instance_info->replay_device_info[replay_device];
}

void VulkanReplayConsumerBase::SetPhysicalDeviceProperties(VulkanPhysicalDeviceInfo*         physical_device_info,
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

    CheckReplayDeviceInfo(physical_device_info);
    auto replay_device_info = physical_device_info->replay_device_info;
    assert(replay_device_info != nullptr);

    if (replay_device_info->properties == nullptr)
    {
        replay_device_info->properties = std::make_unique<VkPhysicalDeviceProperties>(*replay_properties);
    }
}

void VulkanReplayConsumerBase::SetPhysicalDeviceMemoryProperties(
    VulkanPhysicalDeviceInfo*               physical_device_info,
    const VkPhysicalDeviceMemoryProperties* capture_properties,
    const VkPhysicalDeviceMemoryProperties* replay_properties)
{
    assert((physical_device_info != nullptr) && (capture_properties != nullptr) && (replay_properties != nullptr));

    if (physical_device_info->capture_memory_properties.memoryHeapCount == 0)
    {
        physical_device_info->capture_memory_properties = *capture_properties;
    }

    CheckReplayDeviceInfo(physical_device_info);
    auto replay_device_info = physical_device_info->replay_device_info;
    assert(replay_device_info != nullptr);

    if (replay_device_info->memory_properties == nullptr)
    {
        replay_device_info->memory_properties = std::make_unique<VkPhysicalDeviceMemoryProperties>(*replay_properties);
    }
}

void VulkanReplayConsumerBase::SelectPhysicalDevice(VulkanPhysicalDeviceInfo* physical_device_info)
{
    assert((physical_device_info != nullptr) && (physical_device_info->parent_id != format::kNullHandleId));

    VulkanInstanceInfo* instance_info = object_info_table_.GetVkInstanceInfo(physical_device_info->parent_id);

    if (instance_info != nullptr)
    {
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
        GFXRECON_LOG_ERROR("Failed to find VkInstance object (ID = %" PRIu64 ", handle = 0x%" PRIx64
                           ") when selecting a match for capture VkPhysicalDevice object (ID = %" PRIu64
                           ") for device creation",
                           physical_device_info->parent_id,
                           physical_device_info->parent,
                           physical_device_info->capture_id);
    }
}

void VulkanReplayConsumerBase::SelectPhysicalDeviceGroup(VulkanPhysicalDeviceInfo*            physical_device_info,
                                                         const std::vector<format::HandleId>& capture_device_group,
                                                         std::vector<VkPhysicalDevice>&       replay_device_group)
{
    assert((physical_device_info != nullptr) && (physical_device_info->parent_id != format::kNullHandleId));

    VulkanInstanceInfo* instance_info = object_info_table_.GetVkInstanceInfo(physical_device_info->parent_id);

    if (instance_info != nullptr)
    {
        bool have_override = false;

        if (options_.override_gpu_group_index >= 0)
        {
            have_override = GetOverrideDeviceGroup(instance_info, physical_device_info, replay_device_group);
        }

        if (!have_override)
        {
            GetMatchingDeviceGroup(instance_info, physical_device_info, capture_device_group, replay_device_group);
        }

        CheckPhysicalDeviceGroupCompatibility(instance_info, capture_device_group, replay_device_group);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to find VkInstance object (ID = %" PRIu64 ", handle = 0x%" PRIx64
                           ") when selecting a match for capture group VkPhysicalDevice object (ID = %" PRIu64
                           ") for device creation",
                           physical_device_info->parent_id,
                           physical_device_info->parent,
                           physical_device_info->capture_id);
    }
}

bool VulkanReplayConsumerBase::GetOverrideDevice(VulkanInstanceInfo*       instance_info,
                                                 VulkanPhysicalDeviceInfo* physical_device_info)
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

bool VulkanReplayConsumerBase::GetOverrideDeviceGroup(VulkanInstanceInfo*            instance_info,
                                                      VulkanPhysicalDeviceInfo*      physical_device_info,
                                                      std::vector<VkPhysicalDevice>& replay_device_group)
{
    VkInstance instance               = instance_info->handle;
    auto       table                  = GetInstanceTable(instance);
    uint32_t   replay_gpu_group_count = 0;
    VkResult   err = table->EnumeratePhysicalDeviceGroups(instance, &replay_gpu_group_count, nullptr);
    GFXRECON_ASSERT(!err);

    std::vector<VkPhysicalDeviceGroupProperties> replay_group_props;
    if (replay_gpu_group_count > 0)
    {
        replay_group_props.resize(replay_gpu_group_count);
        err = table->EnumeratePhysicalDeviceGroups(instance, &replay_gpu_group_count, replay_group_props.data());
        GFXRECON_ASSERT(!err);
    }
    else
    {
        return false;
    }

    // Check for a valid override device index.
    if (options_.override_gpu_group_index >= static_cast<int32_t>(replay_gpu_group_count))
    {
        GFXRECON_LOG_ERROR(
            "The zero-based index specified for replay device override (%d) exceeds the total number of "
            "available physical device groups (%d). The specified index requires that at least %d devices be "
            "available. The override will not be applied.",
            options_.override_gpu_group_index,
            replay_gpu_group_count,
            (options_.override_gpu_group_index + 1));
        return false;
    }

    const auto& override_group_props = replay_group_props[options_.override_gpu_group_index];
    replay_device_group.clear();
    std::copy(override_group_props.physicalDevices,
              override_group_props.physicalDevices + override_group_props.physicalDeviceCount,
              std::back_inserter(replay_device_group));

    GFXRECON_LOG_INFO("Creating logical device from manually specified GPU group[%d]",
                      options_.override_gpu_group_index);
    GFXRECON_LOG_INFO("  Available device groups are:");

    std::string override_device_name;
    bool        first_override_device_name = false;

    for (uint32_t i = 0; i < replay_gpu_group_count; ++i)
    {
        GFXRECON_LOG_INFO("  group[%d]:", i);

        const auto& replay_group_prop = replay_group_props[i];

        for (uint32_t j = 0; j < replay_group_prop.physicalDeviceCount; ++j)
        {
            auto replay_device      = replay_group_prop.physicalDevices[j];
            auto replay_device_info = &instance_info->replay_device_info[replay_device];

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

            if (std::find(replay_device_group.begin(), replay_device_group.end(), replay_device) !=
                replay_device_group.end())
            {
                if (first_override_device_name)
                {
                    override_device_name.append(", ");
                }
                else
                {
                    first_override_device_name = true;
                }
                override_device_name.append(replay_device_name);
            }

            GFXRECON_LOG_INFO("    [%d] %s", j, replay_device_name.c_str());
        }
    }

    GFXRECON_LOG_INFO("  Specified device is: %s", override_device_name.c_str());

    return true;
}

void VulkanReplayConsumerBase::GetMatchingDevice(VulkanInstanceInfo*       instance_info,
                                                 VulkanPhysicalDeviceInfo* physical_device_info)
{
    // Dispatch table for retrieving physical device properties, if necessary.
    auto table = GetInstanceTable(physical_device_info->handle);
    assert(table != nullptr);

    CheckReplayDeviceInfo(physical_device_info);
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
                    table->GetPhysicalDeviceProperties(entry.first, entry.second.properties.get());
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

void VulkanReplayConsumerBase::GetMatchingDeviceGroup(VulkanInstanceInfo*                  instance_info,
                                                      VulkanPhysicalDeviceInfo*            physical_device_info,
                                                      const std::vector<format::HandleId>& capture_device_group,
                                                      std::vector<VkPhysicalDevice>&       replay_device_group)
{
    for (auto handle_id : capture_device_group)
    {
        auto physical_device_info = GetObjectInfoTable().GetVkPhysicalDeviceInfo(handle_id);
        GetMatchingDevice(instance_info, physical_device_info);
        replay_device_group.emplace_back(physical_device_info->handle);
    }

    // Modified physical device group to fit requirements(VVL).
    auto physical_device = physical_device_info->handle;
    auto result          = std::find(replay_device_group.begin(), replay_device_group.end(), physical_device);
    bool need_modified   = (result == replay_device_group.end());

    std::vector<VkPhysicalDeviceGroupProperties> replay_group_props;

    if (!need_modified)
    {
        VkInstance instance               = instance_info->handle;
        auto       table                  = GetInstanceTable(instance);
        uint32_t   replay_gpu_group_count = 0;
        VkResult   err = table->EnumeratePhysicalDeviceGroups(instance, &replay_gpu_group_count, nullptr);
        GFXRECON_ASSERT(!err);

        if (replay_gpu_group_count > 0)
        {
            replay_group_props.resize(replay_gpu_group_count);
            err = table->EnumeratePhysicalDeviceGroups(instance, &replay_gpu_group_count, replay_group_props.data());
            GFXRECON_ASSERT(!err);

            bool find_in_props = false;
            for (auto& prop : replay_group_props)
            {
                bool find_gpu = true;
                for (auto handle : replay_device_group)
                {
                    auto it = std::find(prop.physicalDevices, prop.physicalDevices + prop.physicalDeviceCount, handle);
                    if (it == (prop.physicalDevices + prop.physicalDeviceCount))
                    {
                        find_gpu = false;
                        break;
                    }
                }
                if (find_gpu)
                {
                    find_in_props = true;
                    break;
                }
            }
            need_modified = !find_in_props;
        }
    }

    if (need_modified)
    {
        for (auto& prop : replay_group_props)
        {
            auto it = std::find(prop.physicalDevices, prop.physicalDevices + prop.physicalDeviceCount, physical_device);
            if (it != (prop.physicalDevices + prop.physicalDeviceCount))
            {
                replay_device_group.clear();
                std::copy(prop.physicalDevices,
                          prop.physicalDevices + prop.physicalDeviceCount,
                          std::back_inserter(replay_device_group));
                break;
            }
        }
    }
}

void VulkanReplayConsumerBase::CheckPhysicalDeviceCompatibility(VulkanPhysicalDeviceInfo* physical_device_info)
{
    CheckReplayDeviceInfo(physical_device_info);
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

void VulkanReplayConsumerBase::CheckPhysicalDeviceGroupCompatibility(
    VulkanInstanceInfo*                  instance_info,
    const std::vector<format::HandleId>& capture_device_group,
    const std::vector<VkPhysicalDevice>& replay_device_group)
{
    auto capture_size = capture_device_group.size();
    auto replay_size  = replay_device_group.size();

    bool diff = false;
    if (capture_size != replay_size)
    {
        diff = true;
    }
    else
    {
        for (size_t i = 0; i < capture_size; ++i)
        {
            auto capture_info = GetObjectInfoTable().GetVkPhysicalDeviceInfo(capture_device_group[i]);
            if (i < replay_size)
            {
                auto* replay_device_info = &instance_info->replay_device_info[replay_device_group[i]];
                auto  replay_properties  = replay_device_info->properties.get();

                if ((capture_info->capture_vendor_id != 0) && (capture_info->capture_device_id != 0) &&
                    ((capture_info->capture_vendor_id != replay_properties->vendorID) ||
                     (capture_info->capture_device_id != replay_properties->deviceID)))
                {
                    diff = true;
                    break;
                }
            }
        }
    }

    if (diff)
    {
        GFXRECON_LOG_WARNING("The replay device group differs from the original capture device group; replay may fail "
                             "due to device incompatibilities:");
        GFXRECON_LOG_WARNING("  Capture device group info:");

        for (size_t i = 0; i < capture_size; ++i)
        {
            auto capture_info = GetObjectInfoTable().GetVkPhysicalDeviceInfo(capture_device_group[i]);

            std::ostringstream string_stream;
            string_stream << "[vendorID = " << capture_info->capture_vendor_id
                          << ", deviceId = " << capture_info->capture_device_id
                          << ", deviceName = " << capture_info->capture_device_name << "]";
            GFXRECON_LOG_WARNING("\t%s", string_stream.str().c_str());
        }

        GFXRECON_LOG_WARNING("  Replay device group info:");

        for (size_t i = 0; i < replay_size; ++i)
        {
            auto* replay_device_info = &instance_info->replay_device_info[replay_device_group[i]];
            auto  replay_properties  = replay_device_info->properties.get();

            std::ostringstream string_stream;
            string_stream << "[vendorID = " << replay_properties->vendorID
                          << ", deviceId = " << replay_properties->deviceID
                          << ", deviceName = " << replay_properties->deviceName << "]";

            GFXRECON_LOG_WARNING("\t%s", string_stream.str().c_str());
        }
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

void VulkanReplayConsumerBase::InitializeResourceAllocator(const VulkanPhysicalDeviceInfo* physical_device_info,
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
    functions.get_instance_proc_addr                = instance_table->GetInstanceProcAddr;

    functions.allocate_memory                             = device_table->AllocateMemory;
    functions.free_memory                                 = device_table->FreeMemory;
    functions.get_device_memory_commitment                = device_table->GetDeviceMemoryCommitment;
    functions.map_memory                                  = device_table->MapMemory;
    functions.unmap_memory                                = device_table->UnmapMemory;
    functions.flush_memory_ranges                         = device_table->FlushMappedMemoryRanges;
    functions.invalidate_memory_ranges                    = device_table->InvalidateMappedMemoryRanges;
    functions.create_buffer                               = device_table->CreateBuffer;
    functions.destroy_buffer                              = device_table->DestroyBuffer;
    functions.get_buffer_memory_requirements              = device_table->GetBufferMemoryRequirements;
    functions.bind_buffer_memory                          = device_table->BindBufferMemory;
    functions.cmd_copy_buffer                             = device_table->CmdCopyBuffer;
    functions.create_image                                = device_table->CreateImage;
    functions.destroy_image                               = device_table->DestroyImage;
    functions.get_image_memory_requirements               = device_table->GetImageMemoryRequirements;
    functions.get_image_subresource_layout                = device_table->GetImageSubresourceLayout;
    functions.bind_image_memory                           = device_table->BindImageMemory;
    functions.get_device_proc_addr                        = device_table->GetDeviceProcAddr;
    functions.get_device_queue                            = device_table->GetDeviceQueue;
    functions.create_command_pool                         = device_table->CreateCommandPool;
    functions.allocate_command_buffers                    = device_table->AllocateCommandBuffers;
    functions.begin_command_buffer                        = device_table->BeginCommandBuffer;
    functions.cmd_copy_buffer                             = device_table->CmdCopyBuffer;
    functions.cmd_copy_buffer_to_image                    = device_table->CmdCopyBufferToImage;
    functions.end_command_buffer                          = device_table->EndCommandBuffer;
    functions.queue_submit                                = device_table->QueueSubmit;
    functions.queue_wait_idle                             = device_table->QueueWaitIdle;
    functions.reset_command_buffer                        = device_table->ResetCommandBuffer;
    functions.free_command_buffers                        = device_table->FreeCommandBuffers;
    functions.destroy_command_pool                        = device_table->DestroyCommandPool;
    functions.create_video_session                        = device_table->CreateVideoSessionKHR;
    functions.destroy_video_session                       = device_table->DestroyVideoSessionKHR;
    functions.bind_video_session_memory                   = device_table->BindVideoSessionMemoryKHR;
    functions.get_video_session_memory_requirements       = device_table->GetVideoSessionMemoryRequirementsKHR;
    functions.get_physical_device_queue_family_properties = instance_table->GetPhysicalDeviceQueueFamilyProperties;

    if (physical_device_info->parent_api_version >= VK_MAKE_VERSION(1, 1, 0))
    {
        functions.get_physical_device_memory_properties2 = instance_table->GetPhysicalDeviceMemoryProperties2;
        functions.get_buffer_memory_requirements2        = device_table->GetBufferMemoryRequirements2;
        functions.get_image_memory_requirements2         = device_table->GetImageMemoryRequirements2;
        functions.bind_buffer_memory2                    = device_table->BindBufferMemory2;
        functions.bind_image_memory2                     = device_table->BindImageMemory2;
    }
    else
    {
        const auto& instance_extensions = physical_device_info->parent_enabled_extensions;

        if (std::find(instance_extensions.begin(),
                      instance_extensions.end(),
                      VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) != instance_extensions.end())
        {
            functions.get_physical_device_memory_properties2 = instance_table->GetPhysicalDeviceMemoryProperties2KHR;
        }

        if (std::find(enabled_device_extensions.begin(),
                      enabled_device_extensions.end(),
                      VK_KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME) != enabled_device_extensions.end())
        {
            functions.get_buffer_memory_requirements2 = device_table->GetBufferMemoryRequirements2KHR;
            functions.get_image_memory_requirements2  = device_table->GetImageMemoryRequirements2KHR;
        }

        if (std::find(enabled_device_extensions.begin(),
                      enabled_device_extensions.end(),
                      VK_KHR_BIND_MEMORY_2_EXTENSION_NAME) != enabled_device_extensions.end())
        {
            functions.bind_buffer_memory2 = device_table->BindBufferMemory2KHR;
            functions.bind_image_memory2  = device_table->BindImageMemory2KHR;
        }
    }

    auto replay_device_info = physical_device_info->replay_device_info;
    assert(replay_device_info->memory_properties != nullptr);

    VkResult result = allocator->Initialize(std::min(physical_device_info->parent_api_version,
                                                     physical_device_info->replay_device_info->properties->apiVersion),
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

void VulkanReplayConsumerBase::ProcessCreateInstanceDebugCallbackInfo(const Decoded_VkInstanceCreateInfo* instance_info)
{
    assert(instance_info != nullptr);

    if (instance_info->pNext != nullptr)
    {
        // 'Out' struct for non-const pNext pointers.
        auto pnext = reinterpret_cast<VkBaseOutStructure*>(instance_info->pNext->GetPointer());
        while (pnext != nullptr)
        {
            if (pnext->sType == VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT)
            {
                auto debug_report_info         = reinterpret_cast<VkDebugReportCallbackCreateInfoEXT*>(pnext);
                debug_report_info->pfnCallback = DebugReportCallback;
            }
            else if (pnext->sType == VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT)
            {
                auto debug_utils_info             = reinterpret_cast<VkDebugUtilsMessengerCreateInfoEXT*>(pnext);
                debug_utils_info->pfnUserCallback = DebugUtilsCallback;
            }

            pnext = pnext->pNext;
        }
    }
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
                const auto surface_info = object_info_table_.GetVkSurfaceKHRInfo(swapchain_info->surface);

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

    const auto* import_ahb_info =
        GetPNextMetaStruct<Decoded_VkImportAndroidHardwareBufferInfoANDROID>(allocate_info->pNext);
    if (import_ahb_info != nullptr)
    {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
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
    }
}

void VulkanReplayConsumerBase::SetSwapchainWindowSize(const Decoded_VkSwapchainCreateInfoKHR* swapchain_info)
{
    assert(swapchain_info != nullptr);

    const auto create_info = swapchain_info->decoded_value;
    if (create_info != nullptr)
    {
        const auto surface_info = object_info_table_.GetVkSurfaceKHRInfo(swapchain_info->surface);
        if (surface_info && (surface_info->window != nullptr))
        {
            uint32_t pre_transform = 0;
            switch (create_info->preTransform)
            {
                default:
                case VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR:
                case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR:
                case VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR:
                    pre_transform = format::ResizeWindowPreTransform::kPreTransform0;
                    break;
                case VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR:
                case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR:
                    pre_transform = format::ResizeWindowPreTransform::kPreTransform90;
                    break;
                case VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR:
                case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR:
                    pre_transform = format::ResizeWindowPreTransform::kPreTransform180;
                    break;
                case VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR:
                case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR:
                    pre_transform = format::ResizeWindowPreTransform::kPreTransform270;
                    break;
            }

            surface_info->window->SetSizePreTransform(
                create_info->imageExtent.width, create_info->imageExtent.height, pre_transform);
        }
    }
}

void VulkanReplayConsumerBase::InitializeScreenshotHandler()
{
    screenshot_file_prefix_ = options_.screenshot_file_prefix;

    if (screenshot_file_prefix_.empty())
    {
        screenshot_file_prefix_ = kDefaultScreenshotFilePrefix;
    }

    if (!options_.screenshot_dir.empty())
    {
        if (util::filepath::Exists(options_.screenshot_dir))
        {
            if (!util::filepath::IsDirectory(options_.screenshot_dir))
            {
                GFXRECON_WRITE_CONSOLE("Error while creating directory %s: Already exists as file",
                                       options_.screenshot_dir.c_str());
                exit(-1);
            }
        }
        else
        {
            int32_t result = gfxrecon::util::platform::MakeDirectory(options_.screenshot_dir.c_str());
            if (result < 0)
            {
                GFXRECON_WRITE_CONSOLE("Error while creating directory %s: Could not open",
                                       options_.screenshot_dir.c_str());
                exit(-1);
            }
        }
        screenshot_file_prefix_ = util::filepath::Join(options_.screenshot_dir, screenshot_file_prefix_);
    }

    screenshot_handler_ = std::make_unique<ScreenshotHandler>(options_.screenshot_format, options_.screenshot_ranges);
}

void VulkanReplayConsumerBase::WriteScreenshots(const Decoded_VkPresentInfoKHR* meta_info) const
{
    if ((meta_info != nullptr) && (meta_info->decoded_value != nullptr) && !meta_info->pSwapchains.IsNull())
    {
        auto present_info  = meta_info->decoded_value;
        auto swapchain_ids = meta_info->pSwapchains.GetPointer();

        for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
        {
            auto swapchain_info = object_info_table_.GetVkSwapchainKHRInfo(swapchain_ids[i]);
            if ((swapchain_info != nullptr) && (swapchain_info->device_info != nullptr) &&
                (swapchain_info->images.size() > 0))
            {
                auto     device_info = swapchain_info->device_info;
                uint32_t image_index = present_info->pImageIndices[i];

                auto instance_table = GetInstanceTable(device_info->parent);
                assert(instance_table != nullptr);

                // TODO: This should be stored in the VulkanDeviceInfo structure to avoid the need for frequent
                // queries.
                VkPhysicalDeviceMemoryProperties memory_properties;
                instance_table->GetPhysicalDeviceMemoryProperties(device_info->parent, &memory_properties);

                std::string filename_prefix = screenshot_file_prefix_;

                if (present_info->swapchainCount > 1)
                {
                    filename_prefix += "_swapchain_";
                    filename_prefix += std::to_string(i);
                }

                filename_prefix += "_frame_";
                filename_prefix += std::to_string(screenshot_handler_->GetCurrentFrame());

                // If both copy_scale and copy_width are provided, use copy_scale.
                const uint32_t screenshot_width =
                    options_.screenshot_scale
                        ? static_cast<uint32_t>(options_.screenshot_scale * swapchain_info->width)
                        : (options_.screenshot_width ? options_.screenshot_width : swapchain_info->width);

                const uint32_t screenshot_height =
                    options_.screenshot_scale
                        ? static_cast<uint32_t>(options_.screenshot_scale * swapchain_info->height)
                        : (options_.screenshot_height ? options_.screenshot_height : swapchain_info->height);

                screenshot_handler_->WriteImage(filename_prefix,
                                                device_info,
                                                GetDeviceTable(device_info->handle),
                                                memory_properties,
                                                device_info->allocator.get(),
                                                swapchain_info->images[image_index],
                                                swapchain_info->format,
                                                swapchain_info->width,
                                                swapchain_info->height,
                                                screenshot_width,
                                                screenshot_height,
                                                VK_IMAGE_LAYOUT_PRESENT_SRC_KHR);
            }
        }
    }
}

bool VulkanReplayConsumerBase::CheckCommandBufferInfoForFrameBoundary(
    const VulkanCommandBufferInfo* command_buffer_info)
{
    GFXRECON_ASSERT(command_buffer_info != nullptr);
    if (command_buffer_info->is_frame_boundary)
    {
        if (screenshot_handler_->IsScreenshotFrame())
        {
            VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(command_buffer_info->parent_id);

            auto instance_table = GetInstanceTable(device_info->parent);
            GFXRECON_ASSERT(instance_table != nullptr);

            // TODO: This should be stored in the VulkanDeviceInfo structure to avoid the need for frequent
            // queries.
            VkPhysicalDeviceMemoryProperties memory_properties;
            instance_table->GetPhysicalDeviceMemoryProperties(device_info->parent, &memory_properties);

            for (size_t i = 0; i < command_buffer_info->frame_buffer_ids.size(); ++i)
            {
                auto framebuffer_info =
                    object_info_table_.GetVkFramebufferInfo(command_buffer_info->frame_buffer_ids[i]);

                for (size_t j = 0; j < framebuffer_info->attachment_image_view_ids.size(); ++j)
                {
                    auto image_view_id   = framebuffer_info->attachment_image_view_ids[j];
                    auto image_view_info = object_info_table_.GetVkImageViewInfo(image_view_id);
                    auto image_info      = object_info_table_.GetVkImageInfo(image_view_info->image_id);

                    // Only screenshot images that are color attachments.
                    if ((image_info->usage & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT) !=
                        VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT)
                    {
                        continue;
                    }

                    std::string filename_prefix = screenshot_file_prefix_;
                    filename_prefix += "_frame_";
                    filename_prefix += std::to_string(screenshot_handler_->GetCurrentFrame());

                    if (command_buffer_info->frame_buffer_ids.size() > 0)
                    {
                        filename_prefix += "_renderpass_";
                        filename_prefix += std::to_string(i);
                    }

                    if (framebuffer_info->attachment_image_view_ids.size() > 0)
                    {
                        filename_prefix += "_attachment_";
                        filename_prefix += std::to_string(j);
                    }

                    // If both copy_scale and copy_width are provided, use copy_scale.
                    const uint32_t screenshot_width =
                        options_.screenshot_scale
                            ? static_cast<uint32_t>(options_.screenshot_scale * image_info->extent.width)
                            : (options_.screenshot_width ? options_.screenshot_width : image_info->extent.width);

                    const uint32_t screenshot_height =
                        options_.screenshot_scale
                            ? static_cast<uint32_t>(options_.screenshot_scale * image_info->extent.height)
                            : (options_.screenshot_height ? options_.screenshot_height : image_info->extent.height);

                    screenshot_handler_->WriteImage(filename_prefix,
                                                    device_info,
                                                    GetDeviceTable(device_info->handle),
                                                    memory_properties,
                                                    device_info->allocator.get(),
                                                    image_info->handle,
                                                    image_info->format,
                                                    image_info->extent.width,
                                                    image_info->extent.height,
                                                    screenshot_width,
                                                    screenshot_height,
                                                    image_info->current_layout);
                }
            }
        }
        screenshot_handler_->EndFrame();
        return true;
    }
    return false;
}

bool VulkanReplayConsumerBase::CheckPNextChainForFrameBoundary(const VulkanDeviceInfo* device_info,
                                                               const PNextNode*        pnext)
{
    const auto* frame_boundary = GetPNextMetaStruct<Decoded_VkFrameBoundaryEXT>(pnext);
    if (frame_boundary == nullptr ||
        ((frame_boundary->decoded_value->flags & VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT) == 0))
    {
        return false;
    }

    auto instance_table = GetInstanceTable(device_info->parent);
    GFXRECON_ASSERT(instance_table != nullptr);

    VkPhysicalDeviceMemoryProperties memory_properties;
    instance_table->GetPhysicalDeviceMemoryProperties(device_info->parent, &memory_properties);

    if (screenshot_handler_->IsScreenshotFrame())
    {
        for (uint32_t i = 0; i < frame_boundary->pImages.GetLength(); ++i)
        {
            const std::string filename_prefix =
                screenshot_file_prefix_ + "_frame_" + std::to_string(screenshot_handler_->GetCurrentFrame());

            const format::HandleId handleId   = frame_boundary->pImages.GetPointer()[i];
            const VulkanImageInfo* image_info = GetObjectInfoTable().GetVkImageInfo(handleId);

            const uint32_t screenshot_width =
                options_.screenshot_scale
                    ? static_cast<uint32_t>(options_.screenshot_scale * image_info->extent.width)
                    : (options_.screenshot_width ? options_.screenshot_width : image_info->extent.width);

            const uint32_t screenshot_height =
                options_.screenshot_scale
                    ? static_cast<uint32_t>(options_.screenshot_scale * image_info->extent.height)
                    : (options_.screenshot_height ? options_.screenshot_height : image_info->extent.height);

            screenshot_handler_->WriteImage(filename_prefix,
                                            device_info,
                                            GetDeviceTable(device_info->handle),
                                            memory_properties,
                                            device_info->allocator.get(),
                                            image_info->handle,
                                            image_info->format,
                                            image_info->extent.width,
                                            image_info->extent.height,
                                            screenshot_width,
                                            screenshot_height,
                                            image_info->current_layout);
        }
    }

    screenshot_handler_->EndFrame();

    return true;
}

VkResult
VulkanReplayConsumerBase::OverrideCreateInstance(VkResult original_result,
                                                 const StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                 HandlePointerDecoder<VkInstance>*                          pInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((pInstance != nullptr) && !pInstance->IsNull() && (pInstance->GetHandlePointer() != nullptr) &&
           (pCreateInfo != nullptr) && (pCreateInfo->GetPointer() != nullptr) &&
           (pInstance->GetHandlePointer() != nullptr));

    const VkInstanceCreateInfo* replay_create_info = pCreateInfo->GetPointer();
    VkInstance*                 replay_instance    = pInstance->GetHandlePointer();

    if (loader_handle_ == nullptr)
    {
        InitializeLoader();
    }

    std::vector<const char*> modified_layers;
    std::vector<const char*> modified_extensions;
    VkInstanceCreateInfo     modified_create_info = (*replay_create_info);

    // If VkDebugUtilsMessengerCreateInfoEXT or VkDebugReportCallbackCreateInfoEXT are in the pNext chain, update the
    // callback pointers.
    ProcessCreateInstanceDebugCallbackInfo(pCreateInfo->GetMetaStructPointer());

    // Proc addresses that can't be used in layers so are not generated into shared dispatch table, but are needed in
    // the replay application.
    PFN_vkEnumerateInstanceLayerProperties instance_layer_proc =
        reinterpret_cast<PFN_vkEnumerateInstanceLayerProperties>(
            get_instance_proc_addr_(nullptr, "vkEnumerateInstanceLayerProperties"));
    PFN_vkEnumerateInstanceExtensionProperties instance_extension_proc =
        reinterpret_cast<PFN_vkEnumerateInstanceExtensionProperties>(
            get_instance_proc_addr_(nullptr, "vkEnumerateInstanceExtensionProperties"));

    // If a specific WSI extension was selected on the command line we need to make sure that extension is
    // loaded and other WSI extensions are disabled
    assert(application_);
    const bool override_wsi_extensions = !application_->GetWsiCliContext().empty();

    for (const auto& itr : application_->GetWsiContexts())
    {
        // TODO : It's kinda ugly to be referencing Dx12 (even if just by name) in the Vulkan codepath, but
        // having a string associated with the WSI context isn't really something Dx12 has a concept of...this
        // should be able to be refactored away in another PR
        if (gfxrecon::util::platform::StringCompareNoCase(itr.first.c_str(), "Dx12WsiContext"))
        {
            modified_extensions.push_back(itr.first.c_str());
        }
    }

    // Transfer requested extensions to filtered extension
    for (uint32_t i = 0; i < replay_create_info->enabledExtensionCount; ++i)
    {
        const auto current_extension    = replay_create_info->ppEnabledExtensionNames[i];
        const bool is_surface_extension = kSurfaceExtensions.find(current_extension) != kSurfaceExtensions.end();
        if (!util::platform::StringCompare(current_extension, VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME))
        {
            // Will always be added if available
            continue;
        }
        else if (is_surface_extension)
        {
            if (!override_wsi_extensions)
            {
                application_->InitializeWsiContext(current_extension);
                modified_extensions.push_back(current_extension);
            }
        }
        else
        {
            modified_extensions.push_back(current_extension);
        }
    }

    // Sanity checks depending on extension availability
    std::vector<VkExtensionProperties> available_extensions;
    if (feature_util::GetInstanceExtensions(instance_extension_proc, &available_extensions) == VK_SUCCESS)
    {
        // Always enable portability enumeration if available
        modified_create_info.flags &= ~VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
        for (const VkExtensionProperties& extension : available_extensions)
        {
            if (!util::platform::StringCompare(extension.extensionName, VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME))
            {
                modified_extensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
                modified_create_info.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
            }
        }

        if (options_.remove_unsupported_features)
        {
            // Remove enabled extensions that are not available from the replay instance.
            feature_util::RemoveUnsupportedExtensions(available_extensions, &modified_extensions);
        }
        else if (options_.use_colorspace_fallback)
        {
            for (auto& extension_name : kColorSpaceExtensionNames)
            {
                feature_util::RemoveExtensionIfUnsupported(available_extensions, &modified_extensions, extension_name);
            }
        }
        else
        {
            // Remove enabled extensions that are ignorable from the replay instance.
            feature_util::RemoveIgnorableExtensions(available_extensions, &modified_extensions);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Failed to get instance extensions. Cannot perform sanity checks or filters for "
                             "extension availability.");
    }

    // Enable validation layer and create a debug messenger if the enable_validation_layer replay option is set.
    VkDebugUtilsMessengerCreateInfoEXT messenger_create_info{};
    if (options_.enable_validation_layer)
    {
        std::vector<VkLayerProperties> available_layers;
        if (feature_util::GetInstanceLayers(instance_layer_proc, &available_layers) == VK_SUCCESS)
        {
            if (feature_util::IsSupportedLayer(available_layers, kValidationLayerName))
            {
                modified_layers.push_back(kValidationLayerName);

                // Create a debug util messenger if replay was run with the enable_validation_layer option and the
                // VK_EXT_debug_utils extension is available. Note that if the app also included one or more
                // VkDebugUtilsMessengerCreateInfoEXT structs in the pNext chain, those messengers will also be
                // created.
                if (feature_util::IsSupportedExtension(available_extensions, VK_EXT_DEBUG_UTILS_EXTENSION_NAME))
                {
                    modified_extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

                    messenger_create_info.sType       = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
                    messenger_create_info.pNext       = modified_create_info.pNext;
                    messenger_create_info.flags       = 0;
                    messenger_create_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                                                        VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
                    messenger_create_info.messageSeverity =
                        VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
                    messenger_create_info.pfnUserCallback = DebugUtilsCallback;
                    messenger_create_info.pUserData       = nullptr;

                    modified_create_info.pNext = &messenger_create_info;
                }
                else
                {
                    GFXRECON_LOG_WARNING(
                        "Failed to create debug utils callback for the validation layer enabled by replay option "
                        "'--validate'. VK_EXT_debug_utils extension is not available for the replay instance.");
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Failed to enable validation layer '%s' required for replay option '--validate'.",
                                     kValidationLayerName);
            }
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "Failed to query for available instance layers. Some replay features may not work correctly.");
        }
    }

    modified_create_info.enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
    modified_create_info.ppEnabledExtensionNames = modified_extensions.data();

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

    // Enable any required layers.
    if (!modified_layers.empty())
    {
        GFXRECON_LOG_INFO(
            "Replay has added the following required layers to VkInstanceCreateInfo when calling vkCreateInstance:");

        for (auto layer : modified_layers)
        {
            GFXRECON_LOG_INFO("\t%s", layer);
        }

        modified_create_info.enabledLayerCount   = static_cast<uint32_t>(modified_layers.size());
        modified_create_info.ppEnabledLayerNames = modified_layers.data();
    }

    VkResult result = create_instance_proc_(&modified_create_info, GetAllocationCallbacks(pAllocator), replay_instance);

    if ((replay_instance != nullptr) && (result == VK_SUCCESS))
    {
        AddInstanceTable(*replay_instance);

        if (modified_create_info.pApplicationInfo != nullptr)
        {
            auto instance_info = reinterpret_cast<VulkanInstanceInfo*>(pInstance->GetConsumerData(0));
            assert(instance_info != nullptr);

            instance_info->api_version = modified_create_info.pApplicationInfo->apiVersion;
            instance_info->enabled_extensions.assign(modified_create_info.ppEnabledExtensionNames,
                                                     modified_create_info.ppEnabledExtensionNames +
                                                         modified_create_info.enabledExtensionCount);
        }
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideCreateDevice(VkResult                  original_result,
                                               VulkanPhysicalDeviceInfo* physical_device_info,
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

    if ((get_device_proc_addr == nullptr) || (create_device_proc == nullptr))
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    VkResult result         = VK_ERROR_INITIALIZATION_FAILED;
    auto     instance_table = GetInstanceTable(physical_device);
    assert(instance_table != nullptr);

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_device      = pDevice->GetHandlePointer();
    assert(replay_create_info != nullptr);

    VkDeviceCreateInfo       modified_create_info = (*replay_create_info);
    std::vector<const char*> modified_extensions;

    // Attempt to recreate capture device group with replay device group

    const auto                    decoded_capture_create_info = pCreateInfo->GetMetaStructPointer();
    std::vector<format::HandleId> capture_device_group;
    const auto*                   capture_next = decoded_capture_create_info->pNext;

    const auto* decoded_capture_device_group_create_info =
        GetPNextMetaStruct<Decoded_VkDeviceGroupDeviceCreateInfo>(decoded_capture_create_info->pNext);
    if (decoded_capture_device_group_create_info != nullptr)
    {
        const auto  len        = decoded_capture_device_group_create_info->pPhysicalDevices.GetLength();
        const auto* handle_ids = decoded_capture_device_group_create_info->pPhysicalDevices.GetPointer();
        std::copy(handle_ids, handle_ids + len, std::back_inserter(capture_device_group));
    }

    VkDeviceGroupDeviceCreateInfo modified_device_group_create_info = {};
    std::vector<VkPhysicalDevice> replay_device_group;
    const VkBaseInStructure* replay_previous_next = reinterpret_cast<const VkBaseInStructure*>(&modified_create_info);
    const VkBaseInStructure* replay_next = reinterpret_cast<const VkBaseInStructure*>(modified_create_info.pNext);

    while (replay_next)
    {
        switch (replay_next->sType)
        {
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            {
                modified_device_group_create_info =
                    (*reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(replay_next));

                SelectPhysicalDeviceGroup(physical_device_info, capture_device_group, replay_device_group);

                modified_device_group_create_info.physicalDeviceCount =
                    static_cast<uint32_t>(replay_device_group.size());
                modified_device_group_create_info.pPhysicalDevices = replay_device_group.data();

                VkBaseInStructure** ppnext = const_cast<VkBaseInStructure**>(&replay_previous_next->pNext);
                (*ppnext)                  = reinterpret_cast<VkBaseInStructure*>(&modified_device_group_create_info);
                break;
            }
            default:
                break;
        }
        replay_previous_next = replay_next;
        replay_next          = replay_next->pNext;
    }

    // Copy requested extensions to modified_extensions
    for (uint32_t i = 0; i < replay_create_info->enabledExtensionCount; ++i)
    {
        modified_extensions.push_back(replay_create_info->ppEnabledExtensionNames[i]);
    }

    // Enable extensions used for loading resources during initial state setup for trimmed files.
    std::vector<std::string> trim_extensions;
    if (loading_trim_state_ && CheckTrimDeviceExtensions(physical_device, &trim_extensions))
    {
        for (const auto& extension : trim_extensions)
        {
            if (std::find(modified_extensions.begin(), modified_extensions.end(), extension) ==
                modified_extensions.end())
            {
                modified_extensions.push_back(extension.c_str());
            }
        }
    }

    // Add VK_EXT_frame_boundary if an option uses it
    if (options_.offscreen_swapchain_frame_boundary)
    {
        if (!feature_util::IsSupportedExtension(modified_extensions, VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME))
        {
            modified_extensions.push_back(VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME);
        }
    }

    // Sanity checks depending on extension availability
    std::vector<VkExtensionProperties> available_extensions;
    if (feature_util::GetDeviceExtensions(
            physical_device, instance_table->EnumerateDeviceExtensionProperties, &available_extensions) == VK_SUCCESS)
    {
        // If VK_EXT_frame_boundary is not supported but requested, fake it
        bool ext_frame_boundary_is_supported =
            feature_util::IsSupportedExtension(available_extensions, VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME);
        bool ext_frame_boundary_is_requested =
            feature_util::IsSupportedExtension(modified_extensions, VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME);

        if (ext_frame_boundary_is_requested && !ext_frame_boundary_is_supported)
        {
            auto iter = std::find_if(modified_extensions.begin(), modified_extensions.end(), [](const char* extension) {
                return util::platform::StringCompare(VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME, extension) == 0;
            });
            modified_extensions.erase(iter);
        }

        if (options_.remove_unsupported_features)
        {
            feature_util::RemoveUnsupportedExtensions(available_extensions, &modified_extensions);
        }
        else
        {
            // Remove enabled extensions that are not available on the replay device, but
            // that can still be safely ignored.
            feature_util::RemoveIgnorableExtensions(available_extensions, &modified_extensions);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Failed to get device extensions. Cannot perform sanity checks or filters for "
                             "extension availability. Some replay features may not work correctly.");
    }

    modified_create_info.enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
    modified_create_info.ppEnabledExtensionNames = modified_extensions.data();

    // Enable necessary features
    graphics::VulkanDeviceUtil                device_util;
    graphics::VulkanDevicePropertyFeatureInfo property_feature_info = device_util.EnableRequiredPhysicalDeviceFeatures(
        physical_device_info->parent_api_version, instance_table, physical_device, &modified_create_info);

    // Remove unsupported features
    if (options_.remove_unsupported_features)
    {
        feature_util::CheckUnsupportedFeatures(physical_device,
                                               instance_table->GetPhysicalDeviceFeatures,
                                               instance_table->GetPhysicalDeviceFeatures2,
                                               modified_create_info.pNext,
                                               modified_create_info.pEnabledFeatures,
                                               options_.remove_unsupported_features);
    }

    // Forward device creation to next layer/driver
    result =
        create_device_proc(physical_device, &modified_create_info, GetAllocationCallbacks(pAllocator), replay_device);

    if ((replay_device == nullptr) || (result != VK_SUCCESS))
    {
        return result;
    }

    AddDeviceTable(*replay_device, get_device_proc_addr);

    auto device_info = reinterpret_cast<VulkanDeviceInfo*>(pDevice->GetConsumerData(0));
    assert(device_info != nullptr);

    device_info->replay_device_group = std::move(replay_device_group);
    device_info->extensions          = std::move(trim_extensions);
    device_info->parent              = physical_device;

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

    std::vector<std::string> enabled_extensions(modified_create_info.ppEnabledExtensionNames,
                                                modified_create_info.ppEnabledExtensionNames +
                                                    modified_create_info.enabledExtensionCount);
    InitializeResourceAllocator(physical_device_info, *replay_device, enabled_extensions, allocator);

    device_info->allocator = std::unique_ptr<VulkanResourceAllocator>(allocator);

    // Track state of physical device properties and features at device creation
    device_info->property_feature_info = property_feature_info;

    // Keep track of what queue families this device is planning on using.  This information is
    // very important if we end up using the VulkanVirtualSwapchain path.
    auto max = [](uint32_t current_max, const VkDeviceQueueCreateInfo& dqci) {
        return std::max(current_max, dqci.queueFamilyIndex);
    };
    uint32_t max_queue_family =
        std::accumulate(modified_create_info.pQueueCreateInfos,
                        modified_create_info.pQueueCreateInfos + modified_create_info.queueCreateInfoCount,
                        0,
                        max);
    device_info->queue_family_index_enabled.clear();
    device_info->queue_family_index_enabled.resize(max_queue_family + 1, false);

    for (uint32_t q = 0; q < modified_create_info.queueCreateInfoCount; ++q)
    {
        const VkDeviceQueueCreateInfo* queue_create_info = &modified_create_info.pQueueCreateInfos[q];
        assert(device_info->queue_family_creation_flags.find(queue_create_info->queueFamilyIndex) ==
               device_info->queue_family_creation_flags.end());
        device_info->queue_family_creation_flags[queue_create_info->queueFamilyIndex] = queue_create_info->flags;
        device_info->queue_family_index_enabled[queue_create_info->queueFamilyIndex]  = true;
    }

    // Restore modified property/feature create info values to the original application values
    device_util.RestoreModifiedPhysicalDeviceFeatures();

    return result;
}

void VulkanReplayConsumerBase::OverrideDestroyDevice(
    PFN_vkDestroyDevice                                        func,
    const VulkanDeviceInfo*                                    device_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice device = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;

        if (screenshot_handler_ != nullptr)
        {
            screenshot_handler_->DestroyDeviceResources(device, GetDeviceTable(device));
        }

        device_info->allocator->Destroy();
    }

    func(device, GetAllocationCallbacks(pAllocator));
}

VkResult
VulkanReplayConsumerBase::OverrideEnumeratePhysicalDevices(PFN_vkEnumeratePhysicalDevices          func,
                                                           VkResult                                original_result,
                                                           VulkanInstanceInfo*                     instance_info,
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
        assert(!pPhysicalDevices->IsNull());

        uint32_t                replay_device_count  = (*replay_device_count_ptr);
        uint32_t                capture_device_count = (*pPhysicalDeviceCount->GetPointer());
        const format::HandleId* capture_devices      = pPhysicalDevices->GetPointer();

        SetInstancePhysicalDeviceEntries(
            instance_info, capture_device_count, capture_devices, replay_device_count, replay_devices);

        for (uint32_t i = 0; i < replay_device_count; ++i)
        {
            auto physical_device_info =
                reinterpret_cast<VulkanPhysicalDeviceInfo*>(pPhysicalDevices->GetConsumerData(i));
            assert(physical_device_info != nullptr);

            SetPhysicalDeviceInstanceInfo(instance_info, physical_device_info, replay_devices[i]);
        }

        if ((replay_device_count > 0) && (replay_device_count < capture_device_count))
        {
            // Make sure all of the capture physical device IDs map to a valid replay physical device handle.
            // The generated code will only add handle mappings for handles returned by vkEnumeratePhysicalDevices on
            // replay, so we add mappings for the handle IDs without matching devices here.
            VkPhysicalDevice overflow_device = replay_devices[0];

            for (uint32_t i = replay_device_count; i < capture_device_count; ++i)
            {
                VulkanPhysicalDeviceInfo overflow_info;

                overflow_info.handle     = overflow_device;
                overflow_info.capture_id = capture_devices[i];
                overflow_info.parent_id  = instance_info->capture_id;
                SetPhysicalDeviceInstanceInfo(instance_info, &overflow_info, overflow_device);

                object_info_table_.AddVkPhysicalDeviceInfo(std::move(overflow_info));
            }
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideEnumeratePhysicalDeviceGroups(
    PFN_vkEnumeratePhysicalDeviceGroups                            func,
    VkResult                                                       original_result,
    VulkanInstanceInfo*                                            instance_info,
    PointerDecoder<uint32_t>*                                      pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((instance_info != nullptr) && (pPhysicalDeviceGroupCount != nullptr) &&
           !pPhysicalDeviceGroupCount->IsNull() && (pPhysicalDeviceGroupCount->GetOutputPointer() != nullptr) &&
           (pPhysicalDeviceGroupProperties != nullptr));

    VkInstance                       instance                      = instance_info->handle;
    uint32_t*                        replay_device_group_count_ptr = pPhysicalDeviceGroupCount->GetOutputPointer();
    VkPhysicalDeviceGroupProperties* replay_device_groups          = pPhysicalDeviceGroupProperties->GetOutputPointer();

    VkResult result = func(instance, replay_device_group_count_ptr, replay_device_groups);

    if ((result >= 0) && (replay_device_groups != nullptr))
    {
        assert(!pPhysicalDeviceGroupProperties->IsNull() &&
               (pPhysicalDeviceGroupProperties->GetLength() == (*pPhysicalDeviceGroupCount->GetPointer())));

        const Decoded_VkPhysicalDeviceGroupProperties* meta_info =
            pPhysicalDeviceGroupProperties->GetMetaStructPointer();
        size_t capture_device_group_count = pPhysicalDeviceGroupProperties->GetLength();
        size_t replay_device_group_count  = (*replay_device_group_count_ptr);

        // Merge the arrays of physical device capture IDs and replay handles from the individual
        // VkPhysicalDeviceGroupProperties array entries into a single data set.
        std::unordered_map<format::HandleId, VkPhysicalDevice> physical_devices;
        std::unordered_set<VkPhysicalDevice>                   overflow_replay_devices;

        auto device_group_count = std::max(capture_device_group_count, replay_device_group_count);

        // Build a map of captured physical device IDs to physical device handles retrieved at replay.
        for (size_t i = 0; i < device_group_count; ++i)
        {
            size_t                  capture_device_count = 0;
            const format::HandleId* capture_devices      = nullptr;
            size_t                  replay_device_count  = 0;
            const VkPhysicalDevice* replay_devices       = nullptr;

            if (i < capture_device_group_count)
            {
                capture_device_count = meta_info[i].physicalDevices.GetLength();
                capture_devices      = meta_info[i].physicalDevices.GetPointer();
            }

            if (i < replay_device_group_count)
            {
                replay_device_count = replay_device_groups[i].physicalDeviceCount;
                replay_devices      = replay_device_groups[i].physicalDevices;
            }

            auto device_count = std::max(capture_device_count, replay_device_count);

            for (size_t j = 0; j < device_count; ++j)
            {
                format::HandleId capture_device = format::kNullHandleId;
                VkPhysicalDevice replay_device  = VK_NULL_HANDLE;

                if (j < capture_device_count)
                {
                    capture_device = capture_devices[j];
                }

                if (j < replay_device_count)
                {
                    replay_device = replay_devices[j];
                }

                if (capture_device != format::kNullHandleId)
                {
                    physical_devices[capture_device] = replay_device;
                }
                else
                {
                    overflow_replay_devices.insert(replay_device);
                }
            }
        }

        // Build lists of capture physical device IDs and replay physical device handles, inserting ID/handle values at
        // matching indexes at the start of the lists, with unpaired values appended to the end.
        std::vector<format::HandleId> capture_devices;
        std::vector<VkPhysicalDevice> replay_devices;

        for (const auto& entry : physical_devices)
        {
            capture_devices.push_back(entry.first);

            if (entry.second != VK_NULL_HANDLE)
            {
                replay_devices.push_back(entry.second);

                // There is currently no way to provide pre-initialized info data for a newly created handle that is a
                // member of a struct, so we insert the handle here.  The generated code will also perform a handle
                // insertion, which will be ignored.
                VulkanPhysicalDeviceInfo physical_device_info;

                physical_device_info.handle     = entry.second;
                physical_device_info.capture_id = entry.first;
                physical_device_info.parent_id  = instance_info->capture_id;
                SetPhysicalDeviceInstanceInfo(instance_info, &physical_device_info, entry.second);

                object_info_table_.AddVkPhysicalDeviceInfo(std::move(physical_device_info));
            }
        }

        replay_devices.insert(replay_devices.end(), overflow_replay_devices.begin(), overflow_replay_devices.end());

        SetInstancePhysicalDeviceEntries(instance_info,
                                         capture_devices.size(),
                                         capture_devices.data(),
                                         replay_devices.size(),
                                         replay_devices.data());

        if ((!replay_devices.empty()) && (replay_devices.size() < capture_devices.size()))
        {
            // Make sure all of the capture physical device IDs map to a valid replay physical device handle.
            // The generated code will only add handle mappings for handles returned by vkEnumeratePhysicalDevices on
            // replay, so we add mappings for the handle IDs without matching devices here.
            VkPhysicalDevice overflow_device = replay_devices[0];

            for (size_t i = replay_devices.size(); i < capture_devices.size(); ++i)
            {
                VulkanPhysicalDeviceInfo overflow_info;

                overflow_info.handle     = overflow_device;
                overflow_info.capture_id = capture_devices[i];
                overflow_info.parent_id  = instance_info->capture_id;
                SetPhysicalDeviceInstanceInfo(instance_info, &overflow_info, overflow_device);

                object_info_table_.AddVkPhysicalDeviceInfo(std::move(overflow_info));
            }
        }
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideGetDeviceQueue(PFN_vkGetDeviceQueue           func,
                                                      VulkanDeviceInfo*              device_info,
                                                      uint32_t                       queueFamilyIndex,
                                                      uint32_t                       queueIndex,
                                                      HandlePointerDecoder<VkQueue>* pQueue)
{
    VkDevice device = device_info->handle;
    if (!pQueue->IsNull())
    {
        pQueue->SetHandleLength(1);
    }
    VkQueue* out_pQueue = pQueue->GetHandlePointer();

    func(device, queueFamilyIndex, queueIndex, out_pQueue);

    // Add tracking for which VkQueue objects are associated with what queue family and index.
    // This is necessary for the virtual swapchain to determine which command buffer to use when
    // Bliting the images on the Presenting Queue.
    auto queue_info          = reinterpret_cast<VulkanQueueInfo*>(pQueue->GetConsumerData(0));
    queue_info->family_index = queueFamilyIndex;
    queue_info->queue_index  = queueIndex;
}

void VulkanReplayConsumerBase::OverrideGetDeviceQueue2(PFN_vkGetDeviceQueue2                             func,
                                                       VulkanDeviceInfo*                                 device_info,
                                                       StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
                                                       HandlePointerDecoder<VkQueue>*                    pQueue)
{
    VkDevice                  device        = device_info->handle;
    const VkDeviceQueueInfo2* in_pQueueInfo = pQueueInfo->GetPointer();
    if (!pQueue->IsNull())
    {
        pQueue->SetHandleLength(1);
    }
    VkQueue* out_pQueue = pQueue->GetHandlePointer();

    func(device, in_pQueueInfo, out_pQueue);

    // Add tracking for which VkQueue objects are associated with what queue family and index.
    // This is necessary for the virtual swapchain to determine which command buffer to use when
    // Bliting the images on the Presenting Queue.
    auto queue_info          = reinterpret_cast<VulkanQueueInfo*>(pQueue->GetConsumerData(0));
    queue_info->family_index = in_pQueueInfo->queueFamilyIndex;
    queue_info->queue_index  = in_pQueueInfo->queueIndex;
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceProperties(
    PFN_vkGetPhysicalDeviceProperties                         func,
    VulkanPhysicalDeviceInfo*                                 physical_device_info,
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
    VulkanPhysicalDeviceInfo*                                  physical_device_info,
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
    VulkanPhysicalDeviceInfo*                                       physical_device_info,
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
    VulkanPhysicalDeviceInfo*                                        physical_device_info,
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

VkResult VulkanReplayConsumerBase::OverrideGetPhysicalDeviceSurfaceCapabilitiesKHR(
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR           func,
    VkResult                                                original_result,
    VulkanPhysicalDeviceInfo*                               physical_device_info,
    VulkanSurfaceKHRInfo*                                   surface_info,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    assert((physical_device_info != nullptr) && (surface_info != nullptr) && (pSurfaceCapabilities != nullptr) &&
           !pSurfaceCapabilities->IsNull() && (pSurfaceCapabilities->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device             = physical_device_info->handle;
    VkSurfaceKHR     surface                     = surface_info->handle;
    auto             replay_surface_capabilities = pSurfaceCapabilities->GetOutputPointer();

    VkResult result = func(physical_device, surface, replay_surface_capabilities);
    if (result == VK_SUCCESS)
    {
        surface_info->surface_capabilities[physical_device] = *replay_surface_capabilities;
    }
    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetPhysicalDeviceSurfaceCapabilities2KHR(
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR                 func,
    VkResult                                                       original_result,
    VulkanPhysicalDeviceInfo*                                      physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>*       pSurfaceCapabilities)
{
    assert((physical_device_info != nullptr) && (pSurfaceInfo != nullptr) && (!pSurfaceInfo->IsNull()) &&
           (pSurfaceInfo->GetPointer() != nullptr) && (pSurfaceCapabilities != nullptr) &&
           !pSurfaceCapabilities->IsNull() && (pSurfaceCapabilities->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device             = physical_device_info->handle;
    auto             replay_surface_info         = pSurfaceInfo->GetPointer();
    auto             replay_surface_capabilities = pSurfaceCapabilities->GetOutputPointer();

    VkResult result = func(physical_device, replay_surface_info, replay_surface_capabilities);
    if (result == VK_SUCCESS)
    {
        auto surface_id                                     = pSurfaceInfo->GetMetaStructPointer()->surface;
        auto surface_info                                   = GetObjectInfoTable().GetVkSurfaceKHRInfo(surface_id);
        surface_info->surface_capabilities[physical_device] = replay_surface_capabilities->surfaceCapabilities;
    }
    return result;
}

VkResult VulkanReplayConsumerBase::OverrideWaitForFences(PFN_vkWaitForFences                  func,
                                                         VkResult                             original_result,
                                                         const VulkanDeviceInfo*              device_info,
                                                         uint32_t                             fenceCount,
                                                         const HandlePointerDecoder<VkFence>* pFences,
                                                         VkBool32                             waitAll,
                                                         uint64_t                             timeout)
{
    assert((device_info != nullptr) && (pFences != nullptr));

    VkResult             result               = VK_SUCCESS;
    VkDevice             device               = device_info->handle;
    uint32_t             modified_fence_count = fenceCount;
    const VkFence*       modified_fences      = nullptr;
    std::vector<VkFence> valid_fences;

    // Check if the call is in a frame range for being skipped (see --skip-get-fence-ranges, --skip-get-fence-status)
    bool           in_skip_range = options_.skip_get_fence_ranges.empty();
    const uint32_t current_frame = application_->GetCurrentFrameNumber() + 1;
    for (const util::UintRange& range : options_.skip_get_fence_ranges)
    {
        if (current_frame >= range.first && current_frame <= range.last)
        {
            in_skip_range = true;
            break;
        }
    }

    if (in_skip_range && options_.skip_get_fence_status == SkipGetFenceStatus::SkipAll)
    {
        return result;
    }

    // Check for fences that need to be removed.
    if (shadow_fences_.empty())
    {
        modified_fences = pFences->GetHandlePointer();
    }
    else
    {
        const format::HandleId* fence_handles = pFences->GetPointer();
        for (size_t i = 0; i < pFences->GetLength(); ++i)
        {
            VulkanFenceInfo* fence_info = object_info_table_.GetVkFenceInfo(fence_handles[i]);
            if (fence_info != nullptr)
            {
                VkFence fence_handle = fence_info->handle;
                if (fence_info->shadow_signaled)
                {
                    // If found, unsignal the fence to represent it being used.
                    fence_info->shadow_signaled = false;
                    shadow_fences_.erase(fence_handle);
                }
                else
                {
                    valid_fences.push_back(fence_handle);
                }
            }
        }

        modified_fence_count = static_cast<uint32_t>(valid_fences.size());
        modified_fences      = valid_fences.data();
    }

    if (original_result == VK_SUCCESS)
    {
        // Ensure that wait for fences waits until the fences have been signaled (or error occurs) by changing the
        // timeout to UINT64_MAX.
        if (modified_fence_count > 0)
        {
            result = func(device, modified_fence_count, modified_fences, waitAll, std::numeric_limits<uint64_t>::max());
        }
    }
    else
    {
        if (in_skip_range && options_.skip_get_fence_status == SkipGetFenceStatus::SkipUnsuccessful)
        {
            return result;
        }

        if (original_result == VK_TIMEOUT)
        {
            // Try to get a timeout result with a 0 timeout.
            result = func(device, modified_fence_count, modified_fences, waitAll, 0);
        }
        else
        {
            result = func(device, modified_fence_count, modified_fences, waitAll, timeout);
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetFenceStatus(PFN_vkGetFenceStatus    func,
                                                          VkResult                original_result,
                                                          const VulkanDeviceInfo* device_info,
                                                          const VulkanFenceInfo*  fence_info)
{
    assert((device_info != nullptr) && (fence_info != nullptr));

    VkResult result = VK_SUCCESS;
    VkDevice device = device_info->handle;
    VkFence  fence  = fence_info->handle;

    // Check if the call is in a frame range for being skipped (see --skip-get-fence-ranges, --skip-get-fence-status)
    bool           in_skip_range = options_.skip_get_fence_ranges.empty();
    const uint32_t current_frame = application_->GetCurrentFrameNumber() + 1;
    for (const util::UintRange& range : options_.skip_get_fence_ranges)
    {
        if (current_frame >= range.first && current_frame <= range.last)
        {
            in_skip_range = true;
            break;
        }
    }

    if (in_skip_range &&
        (options_.skip_get_fence_status == SkipGetFenceStatus::SkipAll ||
         (options_.skip_get_fence_status == SkipGetFenceStatus::SkipUnsuccessful && original_result != VK_SUCCESS)))
    {
        return result;
    }

    if (shadow_fences_.find(fence) != shadow_fences_.end())
    {
        return result;
    }

    // If you find this loop to be infinite consider adding a limit in the same way
    // it is done for GetEventStatus and GetQueryPoolResults.
    do
    {
        result = func(device, fence);
    } while ((original_result == VK_SUCCESS) && (result == VK_NOT_READY));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetEventStatus(PFN_vkGetEventStatus    func,
                                                          VkResult                original_result,
                                                          const VulkanDeviceInfo* device_info,
                                                          const VulkanEventInfo*  event_info)
{
    assert((device_info != nullptr) && (event_info != nullptr));

    VkResult result;
    VkDevice device  = device_info->handle;
    VkEvent  event   = event_info->handle;
    size_t   retries = 0;

    do
    {
        result = func(device, event);
    } while ((((original_result == VK_EVENT_SET) && (result == VK_EVENT_RESET)) ||
              ((original_result == VK_EVENT_RESET) && (result == VK_EVENT_SET))) &&
             (++retries <= kMaxEventStatusRetries));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetQueryPoolResults(PFN_vkGetQueryPoolResults  func,
                                                               VkResult                   original_result,
                                                               const VulkanDeviceInfo*    device_info,
                                                               const VulkanQueryPoolInfo* query_pool_info,
                                                               uint32_t                   firstQuery,
                                                               uint32_t                   queryCount,
                                                               size_t                     dataSize,
                                                               PointerDecoder<uint8_t>*   pData,
                                                               VkDeviceSize               stride,
                                                               VkQueryResultFlags         flags)
{
    assert((device_info != nullptr) && (query_pool_info != nullptr) && (pData != nullptr) &&
           (pData->GetOutputPointer() != nullptr));

    VkResult    result;
    VkDevice    device     = device_info->handle;
    VkQueryPool query_pool = query_pool_info->handle;
    size_t      retries    = 0;

    do
    {
        result = func(device, query_pool, firstQuery, queryCount, dataSize, pData->GetOutputPointer(), stride, flags);
    } while ((((original_result == VK_SUCCESS) && (result == VK_NOT_READY)) ||
              ((original_result == VK_NOT_READY) && (result == VK_SUCCESS))) &&
             (++retries <= kMaxQueryPoolResultsRetries));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideQueueSubmit(PFN_vkQueueSubmit      func,
                                                       uint64_t               index,
                                                       VkResult               original_result,
                                                       const VulkanQueueInfo* queue_info,
                                                       uint32_t               submitCount,
                                                       const StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                       const VulkanFenceInfo*                            fence_info)
{
    assert((queue_info != nullptr) && (pSubmits != nullptr));

    VkResult            result       = VK_SUCCESS;
    const VkSubmitInfo* submit_infos = pSubmits->GetPointer();
    assert(submitCount == 0 || submit_infos != nullptr);
    auto    submit_info_data = pSubmits->GetMetaStructPointer();
    VkFence fence            = VK_NULL_HANDLE;

    if (fence_info != nullptr)
    {
        fence = fence_info->handle;
    }

    // Only attempt to filter imported semaphores if we know at least one has been imported.
    // If rendering is restricted to a specific surface, shadow semaphore and forward progress state will need to be
    // tracked.
    if ((!have_imported_semaphores_) && (options_.surface_index == -1) && (!options_.dumping_resources))
    {
        result = func(queue_info->handle, submitCount, submit_infos, fence);
    }
    else
    {
        // Check for imported semaphores in the current submission list, mapping the pSubmits array index to a vector of
        // imported semaphore info structures.
        std::unordered_map<uint32_t, std::vector<const VulkanSemaphoreInfo*>> altered_submits;
        std::vector<const VulkanSemaphoreInfo*>                               removed_semaphores;

        if (submit_info_data != nullptr)
        {
            for (uint32_t i = 0; i < submitCount; i++)
            {
                GetImportedSemaphores(submit_info_data[i].pWaitSemaphores, &removed_semaphores);
                GetShadowSemaphores(submit_info_data[i].pWaitSemaphores, &removed_semaphores);

                // If rendering is restricted to a specific surface, need to track forward progress for semaphores that
                // have been submitted with a null-swapchain.
                TrackSemaphoreForwardProgress(submit_info_data[i].pWaitSemaphores, &removed_semaphores);

                // Remove non-forward progress of signal semaphores.
                GetNonForwardProgress(submit_info_data[i].pSignalSemaphores, &removed_semaphores);

                if (!removed_semaphores.empty())
                {
                    altered_submits[i].swap(removed_semaphores);
                    assert(removed_semaphores.empty());
                }
            }
        }

        if (altered_submits.empty() && !options_.dumping_resources)
        {
            result = func(queue_info->handle, submitCount, submit_infos, fence);
        }
        else
        {
            // Make shallow copies of the VkSubmit info structures and change pWaitSemaphores to reference a copy of the
            // original semaphore array with the imported semaphores omitted.
            std::vector<VkSubmitInfo> modified_submit_infos(submit_infos, std::next(submit_infos, submitCount));
            std::vector<std::vector<VkSemaphore>> semaphore_memory(altered_submits.size());

            std::vector<VkSemaphore> wait_semaphores;
            std::vector<VkSemaphore> signal_semaphores;

            for (const auto& submit_iter : altered_submits)
            {
                // Shallow copy with filtered copy of pWaitSemaphores for submission info with imported semaphores.
                VkSubmitInfo& modified_submit_info = modified_submit_infos[submit_iter.first];
                auto          semaphore_iter       = submit_iter.second.begin();

                for (uint32_t i = 0; i < modified_submit_info.waitSemaphoreCount; ++i)
                {
                    VkSemaphore semaphore = modified_submit_info.pWaitSemaphores[i];

                    if ((semaphore_iter == submit_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        wait_semaphores.push_back(semaphore);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                for (uint32_t i = 0; i < modified_submit_info.signalSemaphoreCount; ++i)
                {
                    VkSemaphore semaphore = modified_submit_info.pSignalSemaphores[i];

                    if ((semaphore_iter == submit_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        signal_semaphores.push_back(semaphore);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                modified_submit_info.waitSemaphoreCount   = static_cast<uint32_t>(wait_semaphores.size());
                modified_submit_info.pWaitSemaphores      = wait_semaphores.data();
                modified_submit_info.signalSemaphoreCount = static_cast<uint32_t>(signal_semaphores.size());
                modified_submit_info.pSignalSemaphores    = signal_semaphores.data();
            }

            if (submit_info_data != nullptr && (options_.dumping_resources) &&
                resource_dumper_.MustDumpQueueSubmitIndex(index))
            {
                resource_dumper_.QueueSubmit(
                    modified_submit_infos, *GetDeviceTable(queue_info->handle), queue_info->handle, fence, index);
            }
            else
            {
                result = func(queue_info->handle,
                              static_cast<uint32_t>(modified_submit_infos.size()),
                              modified_submit_infos.data(),
                              fence);
            }
        }
    }

    if ((options_.sync_queue_submissions) && (result == VK_SUCCESS))
    {
        GetDeviceTable(queue_info->handle)->QueueWaitIdle(queue_info->handle);
    }

    if (screenshot_handler_ != nullptr)
    {
        VulkanCommandBufferInfo* frame_boundary_command_buffer_info = nullptr;
        for (uint32_t i = 0; i < submitCount; ++i)
        {
            if (submit_info_data != nullptr)
            {
                if (CheckPNextChainForFrameBoundary(object_info_table_.GetVkDeviceInfo(queue_info->parent_id),
                                                    submit_info_data->pNext))
                {
                    break;
                }

                size_t     command_buffer_count = submit_info_data[i].pCommandBuffers.GetLength();
                const auto command_buffer_ids   = submit_info_data[i].pCommandBuffers.GetPointer();
                for (uint32_t j = 0; j < command_buffer_count; ++j)
                {
                    auto command_buffer_info = GetObjectInfoTable().GetVkCommandBufferInfo(command_buffer_ids[j]);

                    // Apply any layouts from submitted command lists.
                    for (auto image_layout : command_buffer_info->image_layout_barriers)
                    {
                        auto image_info = GetObjectInfoTable().GetVkImageInfo(image_layout.first);
                        if (image_info != nullptr)
                        {
                            image_info->current_layout = image_layout.second;
                        }
                    }

                    // Check whether any of the submitted command lists buffers are frame boundaries.
                    if (CheckCommandBufferInfoForFrameBoundary(command_buffer_info))
                    {
                        break;
                    }
                }
            }
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideQueueSubmit2(PFN_vkQueueSubmit2     func,
                                                        VkResult               original_result,
                                                        const VulkanQueueInfo* queue_info,
                                                        uint32_t               submitCount,
                                                        const StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                        const VulkanFenceInfo*                             fence_info)
{
    assert((queue_info != nullptr) && (pSubmits != nullptr));

    VkResult             result       = VK_SUCCESS;
    const VkSubmitInfo2* submit_infos = pSubmits->GetPointer();
    assert(submitCount == 0 || submit_infos != nullptr);
    auto    submit_info_data = pSubmits->GetMetaStructPointer();
    VkFence fence            = VK_NULL_HANDLE;

    if (fence_info != nullptr)
    {
        fence = fence_info->handle;
    }

    // Only attempt to filter imported semaphores if we know at least one has been imported.
    // If rendering is restricted to a specific surface, shadow semaphore and forward progress state will need to be
    // tracked.
    if ((!have_imported_semaphores_) && (options_.surface_index == -1))
    {
        result = func(queue_info->handle, submitCount, submit_infos, fence);
    }
    else
    {
        // Check for imported semaphores in the current submission list, mapping the pSubmits array index to a vector of
        // imported semaphore info structures.
        std::unordered_map<uint32_t, std::vector<const VulkanSemaphoreInfo*>> altered_submits;
        std::vector<const VulkanSemaphoreInfo*>                               removed_semaphores;

        if (submit_info_data != nullptr)
        {
            for (uint32_t i = 0; i < submitCount; i++)
            {
                GetImportedSemaphores(submit_info_data[i].pWaitSemaphoreInfos, &removed_semaphores);
                GetShadowSemaphores(submit_info_data[i].pWaitSemaphoreInfos, &removed_semaphores);

                // If rendering is restricted to a specific surface, need to track forward progress for semaphores that
                // have been submitted with a null-swapchain.
                TrackSemaphoreForwardProgress(submit_info_data[i].pWaitSemaphoreInfos, &removed_semaphores);

                // Remove non-forward progress of signal semaphores.
                GetNonForwardProgress(submit_info_data[i].pWaitSemaphoreInfos, &removed_semaphores);

                if (!removed_semaphores.empty())
                {
                    altered_submits[i].swap(removed_semaphores);
                    assert(removed_semaphores.empty());
                }
            }
        }

        if (altered_submits.empty())
        {
            result = func(queue_info->handle, submitCount, submit_infos, fence);
        }
        else
        {
            // Make shallow copies of the VkSubmit info structures and change pWaitSemaphores to reference a copy of the
            // original semaphore array with the imported semaphores omitted.
            std::vector<VkSubmitInfo2> modified_submit_infos(submit_infos, std::next(submit_infos, submitCount));
            std::vector<std::vector<VkSemaphore>> semaphore_memory(altered_submits.size());

            std::vector<VkSemaphoreSubmitInfo> wait_semaphore_infos;
            std::vector<VkSemaphoreSubmitInfo> signal_semaphore_infos;

            for (const auto& submit_iter : altered_submits)
            {
                // Shallow copy with filtered copy of pWaitSemaphores for submission info with imported semaphores.
                VkSubmitInfo2& modified_submit_info = modified_submit_infos[submit_iter.first];
                auto           semaphore_iter       = submit_iter.second.begin();

                for (uint32_t i = 0; i < modified_submit_info.waitSemaphoreInfoCount; ++i)
                {
                    VkSemaphore semaphore = modified_submit_info.pWaitSemaphoreInfos[i].semaphore;

                    if ((semaphore_iter == submit_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        VkSemaphoreSubmitInfo info{};
                        info.sType     = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
                        info.semaphore = semaphore;

                        wait_semaphore_infos.emplace_back(info);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                for (uint32_t i = 0; i < modified_submit_info.signalSemaphoreInfoCount; ++i)
                {
                    VkSemaphore semaphore = modified_submit_info.pSignalSemaphoreInfos[i].semaphore;

                    if ((semaphore_iter == submit_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        VkSemaphoreSubmitInfo info{};
                        info.sType     = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
                        info.semaphore = semaphore;

                        signal_semaphore_infos.emplace_back(info);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                modified_submit_info.waitSemaphoreInfoCount   = static_cast<uint32_t>(wait_semaphore_infos.size());
                modified_submit_info.pWaitSemaphoreInfos      = wait_semaphore_infos.data();
                modified_submit_info.signalSemaphoreInfoCount = static_cast<uint32_t>(signal_semaphore_infos.size());
                modified_submit_info.pSignalSemaphoreInfos    = signal_semaphore_infos.data();
            }

            result = func(queue_info->handle,
                          static_cast<uint32_t>(modified_submit_infos.size()),
                          modified_submit_infos.data(),
                          fence);
        }
    }

    if ((options_.sync_queue_submissions) && (result == VK_SUCCESS))
    {
        GetDeviceTable(queue_info->handle)->QueueWaitIdle(queue_info->handle);
    }

    // Check whether any of the submitted command buffers are frame boundaries.
    if (screenshot_handler_ != nullptr)
    {
        bool is_frame_boundary = false;
        for (uint32_t i = 0; i < submitCount; ++i)
        {
            if (submit_info_data != nullptr)
            {
                if (CheckPNextChainForFrameBoundary(object_info_table_.GetVkDeviceInfo(queue_info->parent_id),
                                                    submit_info_data->pNext))
                {
                    break;
                }

                size_t     command_buffer_count = submit_info_data[i].pCommandBufferInfos->GetLength();
                const auto command_buffer_infos = submit_info_data[i].pCommandBufferInfos->GetMetaStructPointer();
                for (uint32_t j = 0; j < command_buffer_count; ++j)
                {
                    auto command_buffer_info =
                        GetObjectInfoTable().GetVkCommandBufferInfo(command_buffer_infos[j].commandBuffer);
                    if (CheckCommandBufferInfoForFrameBoundary(command_buffer_info))
                    {
                        break;
                    }
                }
            }
        }
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideQueueBindSparse(PFN_vkQueueBindSparse                                 func,
                                                  VkResult                                              original_result,
                                                  const VulkanQueueInfo*                                queue_info,
                                                  uint32_t                                              bindInfoCount,
                                                  const StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
                                                  const VulkanFenceInfo*                                fence_info)
{
    assert((queue_info != nullptr) && (pBindInfo != nullptr) && !pBindInfo->IsNull());

    VkResult                result     = VK_SUCCESS;
    const VkBindSparseInfo* bind_infos = pBindInfo->GetPointer();
    VkFence                 fence      = VK_NULL_HANDLE;

    if (fence_info != nullptr)
    {
        fence = fence_info->handle;
    }

    // Only attempt to filter imported semaphores if we know at least one has been imported.
    // If rendering is restricted to a specific surface, shadow semaphore and forward progress state will need to be
    // tracked.
    if ((!have_imported_semaphores_) && (options_.surface_index == -1))
    {
        result = func(queue_info->handle, bindInfoCount, bind_infos, fence);
    }
    else
    {
        // Check for imported semaphores in the current bind info list, mapping the pBindInfo array index to a vector of
        // imported semaphore info structures.
        std::unordered_map<uint32_t, std::vector<const VulkanSemaphoreInfo*>> altered_submits;
        std::vector<const VulkanSemaphoreInfo*>                               removed_semaphores;

        auto bind_info_data = pBindInfo->GetMetaStructPointer();
        if (bind_info_data != nullptr)
        {
            for (uint32_t i = 0; i < bindInfoCount; i++)
            {
                GetImportedSemaphores(bind_info_data[i].pWaitSemaphores, &removed_semaphores);
                GetShadowSemaphores(bind_info_data[i].pWaitSemaphores, &removed_semaphores);

                // If rendering is restricted to a specific surface, need to track forward progress for semaphores that
                // have been submitted with a null-swapchain.
                TrackSemaphoreForwardProgress(bind_info_data[i].pWaitSemaphores, &removed_semaphores);

                // Remove non-forward progress of signal semaphores.
                GetNonForwardProgress(bind_info_data[i].pSignalSemaphores, &removed_semaphores);

                if (!removed_semaphores.empty())
                {
                    altered_submits[i].swap(removed_semaphores);
                    assert(removed_semaphores.empty());
                }
            }
        }

        if (altered_submits.empty())
        {
            result = func(queue_info->handle, bindInfoCount, bind_infos, fence);
        }
        else
        {
            // Make shallow copies of the VkBindSparseInfo structures and change pWaitSemaphores to reference a copy of
            // the original semaphore array with the imported semaphores omitted.
            std::vector<VkBindSparseInfo>         modified_bind_infos(bind_infos, std::next(bind_infos, bindInfoCount));
            std::vector<std::vector<VkSemaphore>> semaphore_memory(altered_submits.size());

            std::vector<VkSemaphore> wait_semaphores;
            std::vector<VkSemaphore> signal_semaphores;

            for (const auto& bind_iter : altered_submits)
            {
                // Shallow copy with filtered copy of pWaitSemaphores for bind info with imported semaphores.
                VkBindSparseInfo& modified_bind_info = modified_bind_infos[bind_iter.first];
                auto              semaphore_iter     = bind_iter.second.begin();

                for (uint32_t j = 0; j < modified_bind_info.waitSemaphoreCount; ++j)
                {
                    VkSemaphore semaphore = modified_bind_info.pWaitSemaphores[j];

                    if ((semaphore_iter == bind_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        wait_semaphores.push_back(semaphore);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                for (uint32_t j = 0; j < modified_bind_info.signalSemaphoreCount; ++j)
                {
                    VkSemaphore semaphore = modified_bind_info.pSignalSemaphores[j];

                    if ((semaphore_iter == bind_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        signal_semaphores.push_back(semaphore);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                modified_bind_info.waitSemaphoreCount = static_cast<uint32_t>(wait_semaphores.size());
                modified_bind_info.pWaitSemaphores    = wait_semaphores.data();
                modified_bind_info.waitSemaphoreCount = static_cast<uint32_t>(signal_semaphores.size());
                modified_bind_info.pWaitSemaphores    = signal_semaphores.data();
            }

            result = func(queue_info->handle,
                          static_cast<uint32_t>(modified_bind_infos.size()),
                          modified_bind_infos.data(),
                          fence);
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateDescriptorSetLayout(
    PFN_vkCreateDescriptorSetLayout                                func,
    VkResult                                                       original_result,
    const VulkanDeviceInfo*                                        device_info,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*           pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>*                   pSetLayout)
{
    assert((pCreateInfo != nullptr) && !pCreateInfo->IsNull() && pSetLayout != nullptr && !pSetLayout->IsNull());

    auto       replay_set_layout = pSetLayout->GetHandlePointer();
    const auto create_info       = pCreateInfo->GetPointer();

    VkResult result = func(device_info->handle, create_info, GetAllocationCallbacks(pAllocator), replay_set_layout);

    // The information gathered here is only relevant to the dump resources feature
    if (result >= 0 && options_.dumping_resources)
    {
        auto layout_info = reinterpret_cast<VulkanDescriptorSetLayoutInfo*>(pSetLayout->GetConsumerData(0));
        assert(layout_info != nullptr);

        const auto create_info_meta = pCreateInfo->GetMetaStructPointer();
        assert(create_info_meta != nullptr);
        assert(create_info_meta->decoded_value != nullptr);

        const uint32_t                      binding_count = create_info_meta->decoded_value->bindingCount;
        const VkDescriptorSetLayoutBinding* p_bindings    = create_info_meta->decoded_value->pBindings;
        if (binding_count && p_bindings != nullptr)
        {
            layout_info->bindings_layout.resize(binding_count);
            for (uint32_t i = 0; i < binding_count; ++i)
            {
                layout_info->bindings_layout[i].type    = p_bindings[i].descriptorType;
                layout_info->bindings_layout[i].count   = p_bindings[i].descriptorCount;
                layout_info->bindings_layout[i].binding = p_bindings[i].binding;
            }
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateDescriptorPool(
    PFN_vkCreateDescriptorPool                                      func,
    VkResult                                                        original_result,
    const VulkanDeviceInfo*                                         device_info,
    const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*                         pDescriptorPool)
{
    assert((pCreateInfo != nullptr) && !pCreateInfo->IsNull() && (pDescriptorPool != nullptr) &&
           !pDescriptorPool->IsNull());

    auto       replay_pool = pDescriptorPool->GetHandlePointer();
    const auto create_info = pCreateInfo->GetPointer();

    VkResult result = func(device_info->handle, create_info, GetAllocationCallbacks(pAllocator), replay_pool);

    if (result >= 0)
    {
        // Due to capture and replay differences, it is possible for descriptor set allocation to fail with the
        // descriptor pool running out of memory.  To handle this case, replay will store the pool creation info so that
        // it can attempt to recover from an out of pool memory event by creating a new pool with the same properties.
        auto pool_info = reinterpret_cast<VulkanDescriptorPoolInfo*>(pDescriptorPool->GetConsumerData(0));
        assert(pool_info != nullptr);

        pool_info->flags    = create_info->flags;
        pool_info->max_sets = create_info->maxSets;

        for (uint32_t i = 0; i < create_info->poolSizeCount; i++)
        {
            pool_info->pool_sizes.push_back(create_info->pPoolSizes[i]);
        }

        // 'Out' struct for non-const pNext pointers.
        if (create_info->pNext != nullptr)
        {
            auto meta_info = pCreateInfo->GetMetaStructPointer();
            auto pnext     = reinterpret_cast<VkBaseOutStructure*>(meta_info->pNext->GetPointer());
            while (pnext != nullptr)
            {
                if (pnext->sType == VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT)
                {
                    auto inline_uniform_block_info =
                        reinterpret_cast<VkDescriptorPoolInlineUniformBlockCreateInfoEXT*>(pnext);
                    pool_info->max_inline_uniform_block_bindings =
                        inline_uniform_block_info->maxInlineUniformBlockBindings;
                    break;
                }
                pnext = pnext->pNext;
            }
        }
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideDestroyDescriptorPool(
    PFN_vkDestroyDescriptorPool                                func,
    const VulkanDeviceInfo*                                    device_info,
    VulkanDescriptorPoolInfo*                                  descriptor_pool_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    assert(device_info != nullptr);

    VkDevice         device          = device_info->handle;
    VkDescriptorPool descriptor_pool = VK_NULL_HANDLE;

    if (descriptor_pool_info != nullptr)
    {
        descriptor_pool = descriptor_pool_info->handle;

        // If descriptor allocation ran out of pool memory one or more times, there will be one or more descriptor pools
        // that need to be destroyed.
        for (auto retired_pool : descriptor_pool_info->retired_pools)
        {
            func(device, retired_pool, GetAllocationCallbacks(pAllocator));
        }
    }

    func(device, descriptor_pool, GetAllocationCallbacks(pAllocator));
}

VkResult VulkanReplayConsumerBase::OverrideAllocateDescriptorSets(
    PFN_vkAllocateDescriptorSets                                     func,
    VkResult                                                         original_result,
    const VulkanDeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                           pDescriptorSets)
{
    assert((device_info != nullptr) && (pAllocateInfo != nullptr) && (pDescriptorSets != nullptr) &&
           (pDescriptorSets->GetHandlePointer() != nullptr));

    VkResult result = original_result;

    if ((original_result >= 0) || !options_.skip_failed_allocations)
    {
        result = func(device_info->handle, pAllocateInfo->GetPointer(), pDescriptorSets->GetHandlePointer());

        if ((original_result >= 0) && (result == VK_ERROR_OUT_OF_POOL_MEMORY))
        {
            // Handle case where replay runs out of descriptor pool memory when capture did not by creating a new
            // descriptor pool and attempting the allocation a second time.
            VkDescriptorPool new_pool  = VK_NULL_HANDLE;
            auto             meta_info = pAllocateInfo->GetMetaStructPointer();
            auto             pool_info = object_info_table_.GetVkDescriptorPoolInfo(meta_info->descriptorPool);

            VkDescriptorPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO };
            create_info.pNext                      = nullptr;
            create_info.maxSets                    = pool_info->max_sets;
            create_info.poolSizeCount              = static_cast<uint32_t>(pool_info->pool_sizes.size());
            create_info.pPoolSizes                 = pool_info->pool_sizes.data();

            VkDescriptorPoolInlineUniformBlockCreateInfoEXT inline_uniform_block = {
                VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT,
                nullptr,
                pool_info->max_inline_uniform_block_bindings
            };

            if (pool_info->max_inline_uniform_block_bindings != 0)
            {
                create_info.pNext = &inline_uniform_block;
            }

            result = GetDeviceTable(device_info->handle)
                         ->CreateDescriptorPool(device_info->handle, &create_info, nullptr, &new_pool);

            if (result == VK_SUCCESS)
            {
                GFXRECON_LOG_INFO(
                    "A new VkDescriptorPool object (handle = 0x%" PRIx64
                    ") has been created to replace a VkDescriptorPool object (ID = %" PRIu64 ", handle = 0x%" PRIx64
                    ") that has run our of pool memory (vkAllocateDescriptorSets returned VK_ERROR_OUT_OF_POOL_MEMORY)",
                    new_pool,
                    pool_info->capture_id,
                    pool_info->handle);

                // Retire old pool and swap it with the new pool.
                pool_info->retired_pools.push_back(pool_info->handle);
                pool_info->handle = new_pool;

                // Retry descriptor set allocation.
                VkDescriptorSetAllocateInfo modified_allocate_info = (*pAllocateInfo->GetPointer());
                modified_allocate_info.descriptorPool              = new_pool;

                result = func(device_info->handle, &modified_allocate_info, pDescriptorSets->GetHandlePointer());
            }
        }

        // The information gathered here is only relevant to the dump resources feature
        if (result == VK_SUCCESS && options_.dumping_resources)
        {
            auto meta_info = pAllocateInfo->GetMetaStructPointer();
            assert(meta_info->decoded_value != nullptr);

            const uint32_t          desc_set_count = meta_info->decoded_value->descriptorSetCount;
            const format::HandleId* set_layout_ids = meta_info->pSetLayouts.GetPointer();

            assert(set_layout_ids != nullptr);
            assert(meta_info->pSetLayouts.GetLength() == desc_set_count);

            for (uint32_t i = 0; i < desc_set_count; ++i)
            {
                VulkanDescriptorSetInfo* desc_info =
                    reinterpret_cast<VulkanDescriptorSetInfo*>(pDescriptorSets->GetConsumerData(i));
                assert(desc_info != nullptr);

                VulkanDescriptorSetLayoutInfo* set_layout_info =
                    object_info_table_.GetVkDescriptorSetLayoutInfo(set_layout_ids[i]);
                assert(set_layout_info != nullptr);

                for (const auto& layout_binding : set_layout_info->bindings_layout)
                {
                    assert(desc_info->descriptors.find(layout_binding.binding) == desc_info->descriptors.end());
                    auto new_entry = desc_info->descriptors.emplace(std::piecewise_construct,
                                                                    std::forward_as_tuple(layout_binding.binding),
                                                                    std::forward_as_tuple());
                    assert(new_entry.second);

                    new_entry.first->second.desc_type = layout_binding.type;

                    switch (layout_binding.type)
                    {
                        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                        {
                            new_entry.first->second.image_info.resize(layout_binding.count);
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        {
                            new_entry.first->second.buffer_info.resize(layout_binding.count);
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                        {
                            new_entry.first->second.texel_buffer_view_info.resize(layout_binding.count);
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                        {
                            new_entry.first->second.inline_uniform_block.resize(layout_binding.count);
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_SAMPLER:
                        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                            break;

                        default:
                            GFXRECON_LOG_WARNING("%s() Unrecognized/Unhandled descriptor type (%s)",
                                                 __func__,
                                                 util::ToString<VkDescriptorType>(layout_binding.type).c_str());
                            break;
                    }
                }
            }
        }
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateDescriptorSets call that failed during capture with error %s",
                          util::ToString<VkResult>(original_result).c_str());
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAllocateCommandBuffers(
    PFN_vkAllocateCommandBuffers                                     func,
    VkResult                                                         original_result,
    const VulkanDeviceInfo*                                          device_info,
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
                          util::ToString<VkResult>(original_result).c_str());
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideFreeCommandBuffers(PFN_vkFreeCommandBuffers               func,
                                                          const VulkanDeviceInfo*                device_info,
                                                          VulkanCommandPoolInfo*                 command_pool_info,
                                                          uint32_t                               command_buffer_count,
                                                          HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers)
{
    assert((device_info != nullptr) && (pCommandBuffers != nullptr) &&
           (pCommandBuffers->GetHandlePointer() != nullptr));

    if (options_.dumping_resources && command_pool_info != nullptr)
    {
        const format::HandleId* cmd_buf_handles = pCommandBuffers->GetPointer();
        for (uint32_t i = 0; i < command_buffer_count; ++i)
        {
            auto it = command_pool_info->child_ids.find(cmd_buf_handles[i]);
            if (it != command_pool_info->child_ids.end())
            {
                if (options_.dumping_resources)
                {
                    VulkanCommandBufferInfo* cb_info = object_info_table_.GetVkCommandBufferInfo(*it);
                    assert(cb_info != nullptr);
                    resource_dumper_.ResetCommandBuffer(cb_info->handle);
                }
            }
        }
    }

    const VkCommandBuffer* in_pCommandBuffers = pCommandBuffers->GetHandlePointer();
    func(device_info->handle, command_pool_info->handle, command_buffer_count, in_pCommandBuffers);
}

VkResult VulkanReplayConsumerBase::OverrideAllocateMemory(
    PFN_vkAllocateMemory                                       func,
    VkResult                                                   original_result,
    const VulkanDeviceInfo*                                    device_info,
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

        // Check if this allocation was captured with an opaque address
        bool                uses_address           = false;
        bool                address_override_found = false;
        bool                uses_import_memory     = false;
        uint64_t            opaque_address         = 0;
        VkBaseOutStructure* current_struct = reinterpret_cast<const VkBaseOutStructure*>(replay_allocate_info)->pNext;

        size_t                                            host_pointer_size = 0;
        std::unique_ptr<void, std::function<void(void*)>> external_memory_guard(
            nullptr, [&](void* memory) { util::platform::FreeRawMemory(memory, host_pointer_size); });

        while (current_struct != nullptr)
        {
            if (current_struct->sType == VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO)
            {
                auto alloc_flags_info = reinterpret_cast<VkMemoryAllocateFlagsInfo*>(current_struct);
                if ((alloc_flags_info->flags & VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT) ==
                    VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT)
                {
                    if (device_info->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
                    {
                        uses_address = true;
                        alloc_flags_info->flags |= VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
                        auto opaque_address_pair = device_info->opaque_addresses.find(capture_id);
                        if (opaque_address_pair != device_info->opaque_addresses.end())
                        {
                            opaque_address = opaque_address_pair->second;
                        }
                    }
                }
                break;
            }
            else if (current_struct->sType == VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT)
            {
                auto import_info = reinterpret_cast<VkImportMemoryHostPointerInfoEXT*>(current_struct);

                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, replay_allocate_info->allocationSize);

                size_t allocation_size = static_cast<size_t>(replay_allocate_info->allocationSize);

                host_pointer_size =
                    util::platform::GetAlignedSize(allocation_size, util::platform::GetSystemPageSize());

                // VkAllocateMemory fails when memory was allocated with default malloc func, probably because of extra
                // memory bytes allocated for malloc private info
                import_info->pHostPointer = util::platform::AllocateRawMemory(host_pointer_size);

                if (import_info->pHostPointer == nullptr)
                {
                    GFXRECON_LOG_ERROR("Failed to allocate raw memory with size = %" PRIuPTR " with error code: %u",
                                       host_pointer_size,
                                       util::platform::GetSystemLastErrorCode());
                    std::abort();
                }
                external_memory_guard.reset(import_info->pHostPointer);

                uses_import_memory = true;
            }
            else if (current_struct->sType == VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO)
            {
                address_override_found = true;
            }

            current_struct = current_struct->pNext;
        }

        if (uses_address && !address_override_found)
        {
            // Insert VkMemoryOpaqueCaptureAddressAllocateInfo into front of pNext chain before allocating

            // The Vulkan spec states: If the pNext chain includes a VkImportMemoryHostPointerInfoEXT structure,
            // VkMemoryOpaqueCaptureAddressAllocateInfo::opaqueCaptureAddress must be zero
            // (https://vulkan.lunarg.com/doc/view/1.3.216.0/linux/1.3-extensions/vkspec.html#VUID-VkMemoryAllocateInfo-pNext-03332)
            if (uses_import_memory)
            {
                opaque_address = 0;
            }

            VkMemoryAllocateInfo                     modified_allocate_info = (*replay_allocate_info);
            VkMemoryOpaqueCaptureAddressAllocateInfo address_info           = {
                          VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO,
                          modified_allocate_info.pNext,
                          opaque_address
            };
            modified_allocate_info.pNext = &address_info;

            result = allocator->AllocateMemory(&modified_allocate_info,
                                               GetAllocationCallbacks(pAllocator),
                                               capture_id,
                                               replay_memory,
                                               &allocator_data);
        }
        else
        {
            result = allocator->AllocateMemory(
                replay_allocate_info, GetAllocationCallbacks(pAllocator), capture_id, replay_memory, &allocator_data);
        }

        if ((result == VK_SUCCESS) && (replay_allocate_info != nullptr) && ((*replay_memory) != VK_NULL_HANDLE))
        {
            auto memory_info = reinterpret_cast<VulkanDeviceMemoryInfo*>(pMemory->GetConsumerData(0));
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

        if (result == VK_SUCCESS && uses_import_memory)
        {
            external_memory_.emplace(*replay_memory,
                                     std::make_pair(external_memory_guard.release(), host_pointer_size));
        }
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateMemory call that failed during capture with error %s",
                          util::ToString<VkResult>(original_result).c_str());
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideMapMemory(PFN_vkMapMemory         func,
                                                     VkResult                original_result,
                                                     const VulkanDeviceInfo* device_info,
                                                     VulkanDeviceMemoryInfo* memory_info,
                                                     VkDeviceSize            offset,
                                                     VkDeviceSize            size,
                                                     VkMemoryMapFlags        flags,
                                                     void**                  ppData)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (memory_info != nullptr));

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    return allocator->MapMemory(memory_info->handle, offset, size, flags, ppData, memory_info->allocator_data);
}

void VulkanReplayConsumerBase::OverrideUnmapMemory(PFN_vkUnmapMemory       func,
                                                   const VulkanDeviceInfo* device_info,
                                                   VulkanDeviceMemoryInfo* memory_info)
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
    const VulkanDeviceInfo*                                  device_info,
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
        auto memory_info = object_info_table_.GetVkDeviceMemoryInfo(replay_range_meta_datas[i].memory);

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
    const VulkanDeviceInfo*                                  device_info,
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
        auto memory_info = object_info_table_.GetVkDeviceMemoryInfo(replay_range_meta_datas[i].memory);

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

void VulkanReplayConsumerBase::OverrideFreeMemory(PFN_vkFreeMemory        func,
                                                  const VulkanDeviceInfo* device_info,
                                                  VulkanDeviceMemoryInfo* memory_info,
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

        auto findIt = external_memory_.find(memory);
        if (findIt != external_memory_.end())
        {
            util::platform::FreeRawMemory(findIt->second.first, findIt->second.second);
            external_memory_.erase(findIt);
        }

        memory_info->allocator_data = 0;
    }

    allocator->FreeMemory(memory, GetAllocationCallbacks(pAllocator), allocator_data);
}

VkResult VulkanReplayConsumerBase::OverrideBindBufferMemory(PFN_vkBindBufferMemory  func,
                                                            VkResult                original_result,
                                                            const VulkanDeviceInfo* device_info,
                                                            VulkanBufferInfo*       buffer_info,
                                                            VulkanDeviceMemoryInfo* memory_info,
                                                            VkDeviceSize            memoryOffset)
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

    if ((result != VK_SUCCESS) && (original_result == VK_SUCCESS))
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
    const VulkanDeviceInfo*                                     device_info,
    uint32_t                                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pBindInfos != nullptr));

    auto replay_bind_infos      = pBindInfos->GetPointer();
    auto replay_bind_meta_infos = pBindInfos->GetMetaStructPointer();
    assert((replay_bind_infos != nullptr) && (replay_bind_meta_infos != nullptr));

    std::vector<VulkanBufferInfo*>                     buffer_infos;
    std::vector<const VulkanDeviceMemoryInfo*>         memory_infos;
    std::vector<VulkanResourceAllocator::ResourceData> allocator_buffer_datas(bindInfoCount, 0);
    std::vector<VulkanResourceAllocator::MemoryData>   allocator_memory_datas(bindInfoCount, 0);
    std::vector<VkMemoryPropertyFlags>                 memory_property_flags(bindInfoCount, 0);

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        const Decoded_VkBindBufferMemoryInfo* bind_meta_info = &replay_bind_meta_infos[i];

        auto buffer_info = object_info_table_.GetVkBufferInfo(bind_meta_info->buffer);
        auto memory_info = object_info_table_.GetVkDeviceMemoryInfo(bind_meta_info->memory);

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
            auto buffer_info = buffer_infos[i];

            if (buffer_info != nullptr)
            {
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

VkResult VulkanReplayConsumerBase::OverrideBindImageMemory(PFN_vkBindImageMemory   func,
                                                           VkResult                original_result,
                                                           const VulkanDeviceInfo* device_info,
                                                           VulkanImageInfo*        image_info,
                                                           VulkanDeviceMemoryInfo* memory_info,
                                                           VkDeviceSize            memoryOffset)
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

    if ((result != VK_SUCCESS) && (original_result == VK_SUCCESS))
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
    const VulkanDeviceInfo*                                    device_info,
    uint32_t                                                   bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pBindInfos != nullptr));

    auto replay_bind_infos      = pBindInfos->GetPointer();
    auto replay_bind_meta_infos = pBindInfos->GetMetaStructPointer();
    assert((replay_bind_infos != nullptr) && (replay_bind_meta_infos != nullptr));

    std::vector<VulkanImageInfo*>                      image_infos;
    std::vector<const VulkanDeviceMemoryInfo*>         memory_infos;
    std::vector<VulkanResourceAllocator::ResourceData> allocator_image_datas(bindInfoCount, 0);
    std::vector<VulkanResourceAllocator::MemoryData>   allocator_memory_datas(bindInfoCount, 0);
    std::vector<VkMemoryPropertyFlags>                 memory_property_flags(bindInfoCount, 0);

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        const Decoded_VkBindImageMemoryInfo* bind_meta_info = &replay_bind_meta_infos[i];

        auto image_info  = object_info_table_.GetVkImageInfo(bind_meta_info->image);
        auto memory_info = object_info_table_.GetVkDeviceMemoryInfo(bind_meta_info->memory);

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
            auto image_info = image_infos[i];

            if (image_info != nullptr)
            {
                image_info->memory_property_flags = memory_property_flags[i];
            }
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

VkResult VulkanReplayConsumerBase::OverrideBindVideoSessionMemoryKHR(
    PFN_vkBindVideoSessionMemoryKHR                                func,
    VkResult                                                       original_result,
    const VulkanDeviceInfo*                                        device_info,
    VulkanVideoSessionKHRInfo*                                     video_session_info,
    uint32_t                                                       bindSessionMemoryInfoCount,
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT((device_info != nullptr) && (video_session_info != nullptr) &&
                    (pBindSessionMemoryInfos != nullptr));

    auto allocator = device_info->allocator.get();
    GFXRECON_ASSERT(allocator != nullptr);

    if (!allocator->SupportBindVideoSessionMemory())
    {
        GFXRECON_LOG_WARNING_ONCE("The replay VideoSession's MemoryRequirements could be different, so replay may "
                                  "fail. Try '-m rebind', if it fails.");
    }

    auto replay_bind_infos      = pBindSessionMemoryInfos->GetPointer();
    auto replay_bind_meta_infos = pBindSessionMemoryInfos->GetMetaStructPointer();
    GFXRECON_ASSERT((replay_bind_infos != nullptr) && (replay_bind_meta_infos != nullptr));

    uint32_t                                           session_mem_count = video_session_info->allocator_datas.size();
    std::vector<const VulkanDeviceMemoryInfo*>         memory_infos;
    std::vector<VulkanResourceAllocator::ResourceData> allocator_session_datas(session_mem_count, 0);
    std::vector<VulkanResourceAllocator::MemoryData>   allocator_memory_datas(session_mem_count, 0);
    std::vector<VkMemoryPropertyFlags>                 memory_property_flags(session_mem_count, 0);

    for (uint32_t mem_index = 0; mem_index < session_mem_count; ++mem_index)
    {
        allocator_session_datas[mem_index] = video_session_info->allocator_datas[mem_index];

        for (uint32_t i = 0; i < bindSessionMemoryInfoCount; ++i)
        {
            const auto* bind_meta_info = &replay_bind_meta_infos[i];
            if (mem_index == bind_meta_info->decoded_value->memoryBindIndex)
            {
                auto memory_info = object_info_table_.GetVkDeviceMemoryInfo(bind_meta_info->memory);
                memory_infos.push_back(memory_info);

                if (memory_info != nullptr)
                {
                    allocator_memory_datas[mem_index] = memory_info->allocator_data;
                }
            }
        }
    }
    VkResult result = allocator->BindVideoSessionMemory(video_session_info->handle,
                                                        bindSessionMemoryInfoCount,
                                                        replay_bind_infos,
                                                        allocator_session_datas.data(),
                                                        allocator_memory_datas.data(),
                                                        memory_property_flags.data());

    if (result == VK_SUCCESS)
    {
        video_session_info->memory_property_flags.resize(session_mem_count);
        for (uint32_t i = 0; i < session_mem_count; ++i)
        {
            video_session_info->memory_property_flags[i] = memory_property_flags[i];
        }
    }
    else if (original_result == VK_SUCCESS)
    {
        // When bind fails at replay, but succeeded at capture, check for memory incompatibilities and recommend
        // enabling memory translation.
        allocator->ReportBindVideoSessionIncompatibility(video_session_info->handle,
                                                         bindSessionMemoryInfoCount,
                                                         replay_bind_infos,
                                                         allocator_session_datas.data(),
                                                         allocator_memory_datas.data());
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideCreateBuffer(PFN_vkCreateBuffer                                      func,
                                               VkResult                                                original_result,
                                               const VulkanDeviceInfo*                                 device_info,
                                               const StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
                                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                               HandlePointerDecoder<VkBuffer>*                            pBuffer)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && (pBuffer != nullptr) && !pBuffer->IsNull() &&
           (pBuffer->GetHandlePointer() != nullptr));

    auto allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VkResult                              result = VK_SUCCESS;
    VulkanResourceAllocator::ResourceData allocator_data;
    auto                                  replay_buffer      = pBuffer->GetHandlePointer();
    auto                                  capture_id         = (*pBuffer->GetPointer());
    auto                                  replay_create_info = pCreateInfo->GetPointer();

    // Check for a buffer device address.
    bool                uses_address         = false;
    VkBufferCreateFlags address_create_flags = 0;
    VkBufferUsageFlags  address_usage_flags  = 0;

    if (replaying_trimmed_capture_)
    {
        // The GFXR trimmed capture process sets VK_BUFFER_USAGE_TRANSFER_SRC_BIT flag for buffer VkBufferCreateInfo.
        // Since buffer memory requirements can differ when VK_BUFFER_USAGE_TRANSFER_SRC_BIT is set, we sometimes hit
        // vkBindBufferMemory failures due to memory requirement mismatch during replay. So here we add
        // VK_BUFFER_USAGE_TRANSFER_SRC_BIT to keep things consistent with capture.
        auto modified_create_info = const_cast<VkBufferCreateInfo*>(replay_create_info);
        modified_create_info->usage |= VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    }

    if (device_info->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        if ((replay_create_info->usage & VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT) ==
            VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT)
        {
            uses_address = true;
            address_create_flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
        }
        if ((replay_create_info->usage & VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR) ==
            VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR)
        {
            uses_address = true;
            address_create_flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
            address_usage_flags |= VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT;
        }
    }

    if (uses_address)
    {
        VkBufferCreateInfo modified_create_info = (*replay_create_info);

        VkBufferOpaqueCaptureAddressCreateInfo address_info = {
            VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO
        };

        auto entry = device_info->opaque_addresses.find(capture_id);
        if (entry != device_info->opaque_addresses.end())
        {
            address_info.opaqueCaptureAddress = entry->second;

            // The shallow copy of VkBufferCreateInfo references the same pNext list from the copy source.  We insert
            // the buffer address extension struct at the start of the list to avoid modifying the original by appending
            // to the end.
            address_info.pNext         = modified_create_info.pNext;
            modified_create_info.pNext = &address_info;

            modified_create_info.flags |= address_create_flags;
            modified_create_info.usage |= address_usage_flags;
        }
        else
        {
            GFXRECON_LOG_DEBUG("Opaque device address is not available for VkBuffer object (ID = %" PRIu64 ")",
                               capture_id);
        }

        result = allocator->CreateBuffer(
            &modified_create_info, GetAllocationCallbacks(pAllocator), capture_id, replay_buffer, &allocator_data);
    }
    else
    {
        result = allocator->CreateBuffer(
            replay_create_info, GetAllocationCallbacks(pAllocator), capture_id, replay_buffer, &allocator_data);
    }

    if ((result == VK_SUCCESS) && (replay_create_info != nullptr) && ((*replay_buffer) != VK_NULL_HANDLE))
    {
        auto buffer_info = reinterpret_cast<VulkanBufferInfo*>(pBuffer->GetConsumerData(0));
        assert(buffer_info != nullptr);

        buffer_info->allocator_data = allocator_data;
        buffer_info->usage          = replay_create_info->usage;
        buffer_info->size           = replay_create_info->size;

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
    const VulkanDeviceInfo*                                    device_info,
    VulkanBufferInfo*                                          buffer_info,
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
                                              const VulkanDeviceInfo*                                device_info,
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

    if (replaying_trimmed_capture_ || options_.dumping_resources)
    {
        // The GFXR trimmed capture process sets VK_IMAGE_USAGE_TRANSFER_SRC_BIT flag for image VkImageCreateInfo.
        // Since image memory requirements can differ when VK_IMAGE_USAGE_TRANSFER_SRC_BIT is set, we sometimes hit
        // vkBindImageMemory failures due to memory requirement mismatch during replay. So here we add
        // VK_IMAGE_USAGE_TRANSFER_SRC_BIT to keep things consistent with capture.

        // In the case of dump resources we also want the TRANSFER_SRC_BIT in order to be able to dump all images
        auto modified_create_info = const_cast<VkImageCreateInfo*>(pCreateInfo->GetPointer());
        modified_create_info->usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    }

    VkResult result = allocator->CreateImage(
        pCreateInfo->GetPointer(), GetAllocationCallbacks(pAllocator), capture_id, replay_image, &allocator_data);

    auto replay_create_info = pCreateInfo->GetPointer();

    if ((result == VK_SUCCESS) && (replay_create_info != nullptr) && ((*replay_image) != VK_NULL_HANDLE))
    {
        auto image_info = reinterpret_cast<VulkanImageInfo*>(pImage->GetConsumerData(0));
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

        image_info->current_layout = replay_create_info->initialLayout;

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
    const VulkanDeviceInfo*                                    device_info,
    VulkanImageInfo*                                           image_info,
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

VkResult VulkanReplayConsumerBase::OverrideCreateVideoSessionKHR(
    PFN_vkCreateVideoSessionKHR                                      func,
    VkResult                                                         original_result,
    const VulkanDeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkVideoSessionKHR>*                         pVideoSession)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT((device_info != nullptr) && (pCreateInfo != nullptr) && (pVideoSession != nullptr) &&
                    !pVideoSession->IsNull() && (pVideoSession->GetHandlePointer() != nullptr));

    auto allocator = device_info->allocator.get();
    GFXRECON_ASSERT(allocator != nullptr);

    VkResult                                           result = VK_SUCCESS;
    std::vector<VulkanResourceAllocator::ResourceData> allocator_datas;
    auto                                               replay_session     = pVideoSession->GetHandlePointer();
    auto                                               capture_id         = (*pVideoSession->GetPointer());
    auto                                               replay_create_info = pCreateInfo->GetPointer();

    result = allocator->CreateVideoSession(
        replay_create_info, GetAllocationCallbacks(pAllocator), capture_id, replay_session, &allocator_datas);

    if ((result == VK_SUCCESS) && (replay_create_info != nullptr) && ((*replay_session) != VK_NULL_HANDLE))
    {
        auto session_info = reinterpret_cast<VulkanVideoSessionKHRInfo*>(pVideoSession->GetConsumerData(0));
        GFXRECON_ASSERT(session_info != nullptr);

        session_info->allocator_datas    = allocator_datas;
        session_info->queue_family_index = replay_create_info->queueFamilyIndex;
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideDestroyVideoSessionKHR(
    PFN_vkDestroyVideoSessionKHR                               func,
    const VulkanDeviceInfo*                                    device_info,
    VulkanVideoSessionKHRInfo*                                 video_session_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    GFXRECON_ASSERT(device_info != nullptr);

    auto allocator = device_info->allocator.get();
    GFXRECON_ASSERT(allocator != nullptr);

    VkVideoSessionKHR                                  session = VK_NULL_HANDLE;
    std::vector<VulkanResourceAllocator::ResourceData> allocator_datas;

    if (video_session_info != nullptr)
    {
        session         = video_session_info->handle;
        allocator_datas = video_session_info->allocator_datas;

        video_session_info->allocator_datas.clear();
    }

    allocator->DestroyVideoSession(session, GetAllocationCallbacks(pAllocator), allocator_datas);
}

void VulkanReplayConsumerBase::OverrideGetImageSubresourceLayout(
    PFN_vkGetImageSubresourceLayout                         func,
    const VulkanDeviceInfo*                                 device_info,
    const VulkanImageInfo*                                  image_info,
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

template <typename T>
void StoreAttachmentDescriptionFinalLayouts(const T* pCreateInfo, HandlePointerDecoder<VkRenderPass>* pRenderPass)
{
    GFXRECON_ASSERT(pCreateInfo->GetMetaStructPointer() != nullptr);
    uint32_t attachment_count = pCreateInfo->GetPointer()->attachmentCount;
    if (attachment_count > 0)
    {
        GFXRECON_ASSERT(pCreateInfo->GetMetaStructPointer()->pAttachments != nullptr);
        const auto* attachment_descs = pCreateInfo->GetMetaStructPointer()->pAttachments->GetPointer();
        auto        render_pass_info = reinterpret_cast<VulkanRenderPassInfo*>(pRenderPass->GetConsumerData(0));
        GFXRECON_ASSERT(render_pass_info != nullptr)

        // Save attachment descriptions to VulkanRenderPassInfo.
        render_pass_info->attachment_description_final_layouts.resize(attachment_count);
        for (uint32_t i = 0; i < attachment_count; ++i)
        {
            render_pass_info->attachment_description_final_layouts[i] = attachment_descs[i].finalLayout;
        }
    }
}

VkResult VulkanReplayConsumerBase::OverrideCreateRenderPass(
    PFN_vkCreateRenderPass                                      func,
    VkResult                                                    original_result,
    const VulkanDeviceInfo*                                     device_info,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
    HandlePointerDecoder<VkRenderPass>*                         pRenderPass)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_ASSERT(pCreateInfo != nullptr);

    auto result = swapchain_->CreateRenderPass(original_result,
                                               func,
                                               device_info,
                                               pCreateInfo->GetPointer(),
                                               GetAllocationCallbacks(pAllocator),
                                               pRenderPass->GetHandlePointer());

    if ((result == VK_SUCCESS) && (pCreateInfo->GetPointer() != nullptr))
    {
        StoreAttachmentDescriptionFinalLayouts(pCreateInfo, pRenderPass);
    }

    const VkRenderPassCreateInfo* create_info = pCreateInfo->GetPointer();
    auto render_pass_info = reinterpret_cast<VulkanRenderPassInfo*>(pRenderPass->GetConsumerData(0));
    assert(render_pass_info);

    // Copy attachments
    render_pass_info->attachment_descs.reserve(create_info->attachmentCount);
    for (uint32_t i = 0; i < create_info->attachmentCount; ++i)
    {
        render_pass_info->attachment_descs.push_back(create_info->pAttachments[i]);
    }

    // Copy subpass attachment references
    render_pass_info->subpass_refs.reserve(create_info->subpassCount);
    for (uint32_t i = 0; i < create_info->subpassCount; ++i)
    {
        struct VulkanRenderPassInfo::SubpassReferences sp_ref;

        // Copy input attachment refs
        for (uint32_t s = 0; s < create_info->pSubpasses[i].inputAttachmentCount; ++s)
        {
            if (create_info->pSubpasses[i].pInputAttachments[s].attachment != VK_ATTACHMENT_UNUSED)
            {
                sp_ref.input_att_refs.push_back(create_info->pSubpasses[i].pInputAttachments[s]);
            }
        }

        for (uint32_t s = 0; s < create_info->pSubpasses[i].colorAttachmentCount; ++s)
        {
            // Copy color attachment refs
            if (create_info->pSubpasses[i].pColorAttachments[s].attachment != VK_ATTACHMENT_UNUSED)
            {
                sp_ref.color_att_refs.push_back(create_info->pSubpasses[i].pColorAttachments[s]);
            }

            // Copy resolve attachment refs
            if (create_info->pSubpasses[i].pResolveAttachments &&
                create_info->pSubpasses[i].pResolveAttachments[s].attachment != VK_ATTACHMENT_UNUSED)
            {
                sp_ref.resolve_att_refs.push_back(create_info->pSubpasses[i].pResolveAttachments[s]);
            }
        }

        // Copy preserve attachment indices
        sp_ref.preserve_att_refs.reserve(create_info->pSubpasses[i].preserveAttachmentCount);
        for (uint32_t s = 0; s < create_info->pSubpasses[i].preserveAttachmentCount; ++s)
        {
            sp_ref.preserve_att_refs.push_back(create_info->pSubpasses[i].pPreserveAttachments[s]);
        }

        // Copy depth attachment ref
        if (create_info->pSubpasses[i].pDepthStencilAttachment &&
            create_info->pSubpasses[i].pDepthStencilAttachment->attachment != VK_ATTACHMENT_UNUSED)
        {
            sp_ref.has_depth     = true;
            sp_ref.depth_att_ref = *create_info->pSubpasses[i].pDepthStencilAttachment;
        }
        else
        {
            sp_ref.has_depth = false;
        }

        sp_ref.flags = create_info->pSubpasses[i].flags;

        render_pass_info->subpass_refs.push_back(std::move(sp_ref));
    }

    // Copy dependencies
    render_pass_info->dependencies.resize(create_info->dependencyCount);
    for (uint32_t i = 0; i < create_info->dependencyCount; ++i)
    {
        render_pass_info->dependencies[i] = create_info->pDependencies[i];
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateRenderPass2(
    PFN_vkCreateRenderPass2                                      func,
    VkResult                                                     original_result,
    const VulkanDeviceInfo*                                      device_info,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkRenderPass>*                          pRenderPass)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    auto result = swapchain_->CreateRenderPass2(original_result,
                                                func,
                                                device_info,
                                                pCreateInfo->GetPointer(),
                                                GetAllocationCallbacks(pAllocator),
                                                pRenderPass->GetHandlePointer());

    if ((result == VK_SUCCESS) && (pCreateInfo->GetPointer() != nullptr))
    {
        StoreAttachmentDescriptionFinalLayouts(pCreateInfo, pRenderPass);
    }

    const VkRenderPassCreateInfo2* create_info = pCreateInfo->GetPointer();
    auto render_pass_info = reinterpret_cast<VulkanRenderPassInfo*>(pRenderPass->GetConsumerData(0));
    assert(render_pass_info);

    render_pass_info->attachment_descs.resize(create_info->attachmentCount);
    for (uint32_t i = 0; i < create_info->attachmentCount; ++i)
    {
        render_pass_info->attachment_descs[i].flags          = create_info->pAttachments[i].flags;
        render_pass_info->attachment_descs[i].format         = create_info->pAttachments[i].format;
        render_pass_info->attachment_descs[i].samples        = create_info->pAttachments[i].samples;
        render_pass_info->attachment_descs[i].loadOp         = create_info->pAttachments[i].loadOp;
        render_pass_info->attachment_descs[i].storeOp        = create_info->pAttachments[i].storeOp;
        render_pass_info->attachment_descs[i].stencilLoadOp  = create_info->pAttachments[i].stencilLoadOp;
        render_pass_info->attachment_descs[i].stencilStoreOp = create_info->pAttachments[i].stencilStoreOp;
        render_pass_info->attachment_descs[i].initialLayout  = create_info->pAttachments[i].initialLayout;
        render_pass_info->attachment_descs[i].finalLayout    = create_info->pAttachments[i].finalLayout;
    }

    render_pass_info->subpass_refs.reserve(create_info->subpassCount);
    for (uint32_t i = 0; i < create_info->subpassCount; ++i)
    {
        struct VulkanRenderPassInfo::SubpassReferences sp_ref;
        sp_ref.color_att_refs.resize(create_info->pSubpasses[i].colorAttachmentCount);
        for (uint32_t s = 0; s < create_info->pSubpasses[i].colorAttachmentCount; ++s)
        {
            sp_ref.color_att_refs[s].attachment = create_info->pSubpasses[i].pColorAttachments[s].attachment;
            sp_ref.color_att_refs[s].layout     = create_info->pSubpasses[i].pColorAttachments[s].layout;
        }

        sp_ref.input_att_refs.resize(create_info->pSubpasses[i].inputAttachmentCount);
        for (uint32_t s = 0; s < create_info->pSubpasses[i].inputAttachmentCount; ++s)
        {
            sp_ref.input_att_refs[s].attachment = create_info->pSubpasses[i].pInputAttachments[s].attachment;
            sp_ref.input_att_refs[s].layout     = create_info->pSubpasses[i].pInputAttachments[s].layout;
        }

        if (create_info->pSubpasses[i].pDepthStencilAttachment)
        {
            sp_ref.has_depth                = true;
            sp_ref.depth_att_ref.attachment = create_info->pSubpasses[i].pDepthStencilAttachment->attachment;
            sp_ref.depth_att_ref.layout     = create_info->pSubpasses[i].pDepthStencilAttachment->layout;
        }
        else
        {
            sp_ref.has_depth = false;
        }

        render_pass_info->subpass_refs.push_back(std::move(sp_ref));
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideCmdPipelineBarrier(
    PFN_vkCmdPipelineBarrier                                   func,
    VulkanCommandBufferInfo*                                   command_buffer_info,
    VkPipelineStageFlags                                       srcStageMask,
    VkPipelineStageFlags                                       dstStageMask,
    VkDependencyFlags                                          dependencyFlags,
    uint32_t                                                   memoryBarrierCount,
    const StructPointerDecoder<Decoded_VkMemoryBarrier>*       pMemoryBarriers,
    uint32_t                                                   bufferMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                                   imageMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkImageMemoryBarrier>*  pImageMemoryBarriers)
{
    swapchain_->CmdPipelineBarrier(func,
                                   command_buffer_info,
                                   srcStageMask,
                                   dstStageMask,
                                   dependencyFlags,
                                   memoryBarrierCount,
                                   pMemoryBarriers->GetPointer(),
                                   bufferMemoryBarrierCount,
                                   pBufferMemoryBarriers->GetPointer(),
                                   imageMemoryBarrierCount,
                                   pImageMemoryBarriers->GetPointer());

    for (uint32_t i = 0; i < imageMemoryBarrierCount; ++i)
    {
        auto image_id                                        = pImageMemoryBarriers->GetMetaStructPointer()[i].image;
        command_buffer_info->image_layout_barriers[image_id] = pImageMemoryBarriers->GetPointer()[i].newLayout;
        VulkanImageInfo* img_info                            = object_info_table_.GetVkImageInfo(image_id);
        assert(img_info != nullptr);
        img_info->intermediate_layout = pImageMemoryBarriers->GetPointer()[i].newLayout;
    }
}

void VulkanReplayConsumerBase::OverrideCmdPipelineBarrier2(
    PFN_vkCmdPipelineBarrier2                       func,
    VulkanCommandBufferInfo*                        command_buffer_info,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    swapchain_->CmdPipelineBarrier2(func, command_buffer_info, pDependencyInfo->GetPointer());

    if (pDependencyInfo != nullptr)
    {
        const auto* dependency_info_meta = pDependencyInfo->GetMetaStructPointer();
        if (dependency_info_meta->pImageMemoryBarriers != nullptr)
        {
            const auto* img_barriers_meta = dependency_info_meta->pImageMemoryBarriers->GetMetaStructPointer();
            for (uint32_t i = 0; i < dependency_info_meta->pImageMemoryBarriers->GetLength(); ++i)
            {
                format::HandleId image_id = img_barriers_meta[i].image;
                command_buffer_info->image_layout_barriers[image_id] =
                    dependency_info_meta->pImageMemoryBarriers->GetPointer()[i].newLayout;

                VulkanImageInfo* img_info     = object_info_table_.GetVkImageInfo(image_id);
                img_info->intermediate_layout = dependency_info_meta->pImageMemoryBarriers->GetPointer()[i].newLayout;
            }
        }
    }
}

void VulkanReplayConsumerBase::OverrideCmdPipelineBarrier2KHR(
    PFN_vkCmdPipelineBarrier2                       func,
    VulkanCommandBufferInfo*                        command_buffer_info,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    OverrideCmdPipelineBarrier2(func, command_buffer_info, pDependencyInfo);
}

VkResult VulkanReplayConsumerBase::OverrideCreateDescriptorUpdateTemplate(
    PFN_vkCreateDescriptorUpdateTemplate                                      func,
    VkResult                                                                  original_result,
    const VulkanDeviceInfo*                                                   device_info,
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
        size_t image_info_count             = 0;
        size_t buffer_info_count            = 0;
        size_t texel_buffer_view_count      = 0;
        size_t acceleration_structure_count = 0;
        size_t inline_uniform_block_count   = 0;

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
            else if (type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                acceleration_structure_count += entry->descriptorCount;
            }
            else if (type == VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK)
            {
                inline_uniform_block_count += entry->descriptorCount;
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
        size_t accel_struct_offset      = texel_buffer_view_offset + (texel_buffer_view_count * sizeof(VkBufferView));
        size_t inline_uniform_block_offset =
            accel_struct_offset + (acceleration_structure_count * sizeof(VkAccelerationStructureKHR));

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
            else if (type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                entry->stride = sizeof(VkAccelerationStructureKHR);
                entry->offset = accel_struct_offset;
                accel_struct_offset += entry->descriptorCount * sizeof(VkAccelerationStructureKHR);
            }
            else if (type == VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK)
            {
                constexpr size_t byte_stride = 1;
                entry->stride                = byte_stride;
                entry->offset                = inline_uniform_block_offset;
                inline_uniform_block_offset += entry->descriptorCount * byte_stride;
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
                reinterpret_cast<VulkanDescriptorUpdateTemplateInfo*>(pDescriptorUpdateTemplate->GetConsumerData(0));
            assert(update_template_info != nullptr);

            update_template_info->descriptor_image_types = std::move(image_types);
            update_template_info->entries                = std::move(entries);
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
    const VulkanDeviceInfo*                                    device_info,
    const VulkanDescriptorUpdateTemplateInfo*                  descriptor_update_template_info,
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

static VkDescriptorType SpvReflectToVkDescriptorType(SpvReflectDescriptorType type)
{
    switch (type)
    {
        case SPV_REFLECT_DESCRIPTOR_TYPE_SAMPLER:
            return VK_DESCRIPTOR_TYPE_SAMPLER;

        case SPV_REFLECT_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            return VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;

        case SPV_REFLECT_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            return VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;

        case SPV_REFLECT_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            return VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;

        case SPV_REFLECT_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            return VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER;

        case SPV_REFLECT_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            return VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER;

        case SPV_REFLECT_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            return VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;

        case SPV_REFLECT_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;

        case SPV_REFLECT_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            return VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC;

        case SPV_REFLECT_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC;

        case SPV_REFLECT_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            return VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT;

        case SPV_REFLECT_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            return VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR;

        default:
            GFXRECON_LOG_WARNING("%s(): Unrecognised SPIRV-Reflect descriptor type");
            assert(0);
            return VK_DESCRIPTOR_TYPE_MAX_ENUM;
    }
}

static bool SPIRVReflectPerformReflectionOnShaderModule(VulkanShaderModuleInfo*       shader_info,
                                                        size_t                        spirv_size,
                                                        const uint32_t*               spirv_code,
                                                        const VkPhysicalDeviceLimits& phys_dev_limits)
{
    assert(shader_info != nullptr);
    assert(spirv_size);
    assert(spirv_code != nullptr);

    spv_reflect::ShaderModule reflection(spirv_size, spirv_code);
    if (reflection.GetResult() != SPV_REFLECT_RESULT_SUCCESS)
    {
        GFXRECON_LOG_WARNING("Could not generate reflection data about shader module")
        assert(0);
        return false;
    }

    // Scan shader descriptor bindings
    uint32_t         count  = 0;
    SpvReflectResult result = reflection.EnumerateDescriptorBindings(&count, nullptr);
    if (result != SPV_REFLECT_RESULT_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Shader reflection on shader %" PRIu64 " failed", shader_info->capture_id);
        assert(0);
        return false;
    }

    if (count)
    {
        std::vector<SpvReflectDescriptorBinding*> bindings(count, nullptr);
        result = reflection.EnumerateDescriptorBindings(&count, bindings.data());
        if (result != SPV_REFLECT_RESULT_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Shader reflection on shader %" PRIu64 " failed", shader_info->capture_id);
            assert(0);
            return false;
        }

        for (const auto binding : bindings)
        {
            VkDescriptorType type     = SpvReflectToVkDescriptorType(binding->descriptor_type);
            bool             readonly = ((binding->decoration_flags & SPV_REFLECT_DECORATION_NON_WRITABLE) ==
                             SPV_REFLECT_DECORATION_NON_WRITABLE);
            const uint32_t   count    = binding->count;
            const bool       is_array = binding->array.dims_count > 0;

            shader_info->used_descriptors_info[binding->set].emplace(
                binding->binding,
                VulkanShaderModuleInfo::ShaderDescriptorInfo(type, readonly, binding->accessed, count, is_array));
        }
    }

    return true;
}

VkResult VulkanReplayConsumerBase::OverrideCreateShaderModule(
    PFN_vkCreateShaderModule                                      func,
    VkResult                                                      original_result,
    const VulkanDeviceInfo*                                       device_info,
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
        VkResult vk_res = func(
            device_info->handle, original_info, GetAllocationCallbacks(pAllocator), pShaderModule->GetHandlePointer());

        if (vk_res == VK_SUCCESS)
        {
            // check for buffer-references, issue warning
            gfxrecon::util::SpirVParsingUtil spirv_util;

            if (spirv_util.ParseBufferReferences(original_info->pCode, original_info->codeSize))
            {
                auto buffer_reference_infos = spirv_util.GetBufferReferenceInfos();

                if (!buffer_reference_infos.empty())
                {
                    GFXRECON_LOG_WARNING_ONCE("A Shader is using the 'SPV_KHR_physical_storage_buffer' feature. "
                                              "Resource tracking for buffers accessed via references is currently "
                                              "unsupported, so replay may fail.");
                }
            }

            if (options_.dumping_resources)
            {
                VulkanShaderModuleInfo* shader_info =
                    reinterpret_cast<VulkanShaderModuleInfo*>(pShaderModule->GetConsumerData(0));
                assert(shader_info);

                const VulkanPhysicalDeviceInfo* phys_dev =
                    object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
                assert(phys_dev);
                assert(phys_dev->replay_device_info);

                SPIRVReflectPerformReflectionOnShaderModule(shader_info,
                                                            original_info->codeSize,
                                                            original_info->pCode,
                                                            phys_dev->replay_device_info->properties->limits);
            }
        }

        return vk_res;
    }

    VkShaderModuleCreateInfo override_info = *original_info;

    // Replace shader in 'override_info'
    std::unique_ptr<char[]> file_code;
    const uint32_t* const   orig_code = original_info->pCode;
    const size_t            orig_size = original_info->codeSize;
    uint64_t                handle_id = *pShaderModule->GetPointer();
    std::string             file_name = "sh" + std::to_string(handle_id);
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

    VkResult vk_res = func(
        device_info->handle, &override_info, GetAllocationCallbacks(pAllocator), pShaderModule->GetHandlePointer());

    if (vk_res == VK_SUCCESS)
    {
        // check for buffer-references, issue warning
        gfxrecon::util::SpirVParsingUtil spirv_util;

        if (spirv_util.ParseBufferReferences(original_info->pCode, original_info->codeSize))
        {
            auto buffer_reference_infos = spirv_util.GetBufferReferenceInfos();

            if (!buffer_reference_infos.empty())
            {
                GFXRECON_LOG_WARNING_ONCE("A Shader is using the 'SPV_KHR_physical_storage_buffer' feature. "
                                          "Resource tracking for buffers accessed via references is currently "
                                          "unsupported, so replay may fail.");
            }
        }

        if (vk_res == VK_SUCCESS && options_.dumping_resources)
        {
            VulkanShaderModuleInfo* shader_info =
                reinterpret_cast<VulkanShaderModuleInfo*>(pShaderModule->GetConsumerData(0));
            assert(shader_info);

            const VulkanPhysicalDeviceInfo* phys_dev =
                object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
            assert(phys_dev);
            assert(phys_dev->replay_device_info);

            SPIRVReflectPerformReflectionOnShaderModule(shader_info,
                                                        override_info.codeSize,
                                                        override_info.pCode,
                                                        phys_dev->replay_device_info->properties->limits);
        }
    }

    return vk_res;
}

VkResult VulkanReplayConsumerBase::OverrideGetPipelineCacheData(PFN_vkGetPipelineCacheData     func,
                                                                VkResult                       original_result,
                                                                const VulkanDeviceInfo*        device_info,
                                                                const VulkanPipelineCacheInfo* pipeline_cache_info,
                                                                PointerDecoder<size_t>*        pDataSize,
                                                                PointerDecoder<uint8_t>*       pData)
{
    if ((options_.omit_pipeline_cache_data) || (original_result != VK_SUCCESS) || pData->GetPointer() == nullptr)
    {
        // If original result is not VK_SUCCESS, it means target title cannot get valid pipeline cache data, also means
        // there's no need to map the capture time pipeline cache data to playback time, so we can skip the call.
        //
        // If user set omit_pipeline_cache_data, it will be different for using pipeline cache data between capture and
        // playback time, we don't need to track pipeline cache data, so we also skip the call.
        //
        // If pData->GetPointer() == nullptr, it means the call is just used to get the buffer size, so we also skip the
        // call.
        return original_result;
    }
    else
    {
        // If capture/playback on same system, the pipeline cache data size should be same, otherwise it's not guarantee
        // that the cache data size is same. So here we first query the replay time cache data size, then get the cache
        // data.

        size_t*  replay_cache_data_size = pDataSize->AllocateOutputData(1);
        uint8_t* replay_cache_data      = nullptr;

        VkResult replay_result =
            func(device_info->handle, pipeline_cache_info->handle, replay_cache_data_size, nullptr);

        GFXRECON_ASSERT(replay_result == VK_SUCCESS);

        if (*replay_cache_data_size != 0)
        {
            replay_cache_data = pData->AllocateOutputData(*replay_cache_data_size);

            replay_result =
                func(device_info->handle, pipeline_cache_info->handle, replay_cache_data_size, replay_cache_data);

            GFXRECON_ASSERT(replay_result == VK_SUCCESS);

            bool     new_cache_data  = true;
            auto     cache_data_size = *pDataSize->GetPointer();
            uint32_t capture_pipeline_cache_data_hash =
                gfxrecon::util::hash::GenerateCheckSum<uint32_t>(pData->GetPointer(), cache_data_size);

            auto iterator = pipeline_cache_info->pipeline_cache_data.find(capture_pipeline_cache_data_hash);
            if (iterator != pipeline_cache_info->pipeline_cache_data.end())
            {
                // We found some existing pipeline cache data has same hash, so we continue to check if it's same with
                // current pipeline cache data

                const std::vector<VulkanPipelineCacheData>& cache_data = iterator->second;

                for (auto& existing_cache_data : cache_data)
                {
                    if (cache_data_size == existing_cache_data.capture_cache_data.size())
                    {
                        if (memcmp(existing_cache_data.capture_cache_data.data(),
                                   pData->GetPointer(),
                                   cache_data_size) == 0)
                        {
                            // The pipeline cache data is not new. This is possible, by doc, two calls to
                            // vkGetPipelineCacheData with the same parameters must retrieve the same data unless a
                            // command that modifies the contents of the cache is called between them.
                            new_cache_data = false;
                            break;
                        }
                    }
                }
            }

            if (new_cache_data)
            {
                std::vector<VulkanPipelineCacheData>& item =
                    const_cast<VulkanPipelineCacheInfo*>(pipeline_cache_info)
                        ->pipeline_cache_data[capture_pipeline_cache_data_hash];
                auto                    output_cache_data_size = *pDataSize->GetOutputPointer();
                VulkanPipelineCacheData pipeline_cache_data;
                pipeline_cache_data.capture_cache_data.resize(cache_data_size);
                memcpy(pipeline_cache_data.capture_cache_data.data(), pData->GetPointer(), cache_data_size);
                pipeline_cache_data.replay_cache_data.resize(output_cache_data_size);
                memcpy(pipeline_cache_data.replay_cache_data.data(), pData->GetOutputPointer(), output_cache_data_size);
                item.push_back(std::move(pipeline_cache_data));
            }
        }
        return replay_result;
    }
}

VkResult VulkanReplayConsumerBase::OverrideCreatePipelineCache(
    PFN_vkCreatePipelineCache                                      func,
    VkResult                                                       original_result,
    const VulkanDeviceInfo*                                        device_info,
    const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkPipelineCache>*                         pPipelineCache)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    GFXRECON_ASSERT((device_info != nullptr) && (pCreateInfo != nullptr) && (pPipelineCache != nullptr) &&
                    (pPipelineCache->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();
    GFXRECON_ASSERT(replay_create_info != nullptr);

    if (options_.omit_pipeline_cache_data)
    {
        // Make a shallow copy of the create info structure and clear the cache data.
        VkPipelineCacheCreateInfo override_create_info = (*replay_create_info);

        if (replay_create_info->initialDataSize != 0)
        {
            omitted_pipeline_cache_data_ = true;
        }

        override_create_info.initialDataSize = 0;
        override_create_info.pInitialData    = nullptr;

        return func(device_info->handle,
                    &override_create_info,
                    GetAllocationCallbacks(pAllocator),
                    pPipelineCache->GetHandlePointer());
    }
    else
    {
        auto& create_info = *pCreateInfo->GetPointer();
        if ((create_info.pInitialData != nullptr) && (create_info.initialDataSize != 0))
        {
            // This vkCreatePipelineCache call has initial pipeline cache data, the data is valid for capture time,
            // but it might not be valid for replay time if considering platform/driver version change. So in the
            // following process, we'll try to find corresponding replay time pipeline cache data.
            matched_replay_cache_data_exist_  = false;
            capture_pipeline_cache_data_hash_ = gfxrecon::util::hash::GenerateCheckSum<uint32_t>(
                reinterpret_cast<const uint8_t*>(create_info.pInitialData), create_info.initialDataSize);
            capture_pipeline_cache_data_      = const_cast<void*>(create_info.pInitialData);
            capture_pipeline_cache_data_size_ = create_info.initialDataSize;

            object_info_table_.VisitVkPipelineCacheInfo([this](const VulkanPipelineCacheInfo* pipeline_cache_info) {
                GFXRECON_ASSERT(pipeline_cache_info != nullptr);

                auto iterator = pipeline_cache_info->pipeline_cache_data.find(capture_pipeline_cache_data_hash_);

                if (iterator != pipeline_cache_info->pipeline_cache_data.end())
                {
                    // We found pipeline cache data vector which has same hash value, will continue to check if it
                    // has same capture time pipeline cache data.
                    auto& cache_data = iterator->second;

                    for (auto& existing_cache_data : cache_data)
                    {
                        if (capture_pipeline_cache_data_size_ == existing_cache_data.capture_cache_data.size())
                        {
                            // Target pipeline cache data has same size, we continue to check if it also has same
                            // data.
                            if (memcmp(existing_cache_data.capture_cache_data.data(),
                                       capture_pipeline_cache_data_,
                                       capture_pipeline_cache_data_size_) == 0)
                            {
                                // Now we found the pipeline cache data, here we record its replay time data because
                                // we need this data to replace capture time cache data in the vkCreatePipelineCache
                                // call.
                                matched_replay_cache_data_exist_ = true;
                                matched_replay_cache_data_.resize(existing_cache_data.replay_cache_data.size());
                                memcpy(matched_replay_cache_data_.data(),
                                       existing_cache_data.replay_cache_data.data(),
                                       existing_cache_data.replay_cache_data.size());
                                break;
                            }
                        }
                    }
                }
            });

            if (matched_replay_cache_data_exist_)
            {
                VkPipelineCacheCreateInfo override_create_info = (*replay_create_info);
                override_create_info.initialDataSize           = matched_replay_cache_data_.size();
                override_create_info.pInitialData              = matched_replay_cache_data_.data();

                return func(device_info->handle,
                            &override_create_info,
                            GetAllocationCallbacks(pAllocator),
                            pPipelineCache->GetHandlePointer());
            }
            else
            {
                GFXRECON_LOG_DEBUG(
                    "There's initial pipeline cache data in VkPipelineCacheCreateInfo, but no corresponding "
                    "replay time cache data!");

                omitted_pipeline_cache_data_ = true;
            }
        }

        return func(device_info->handle,
                    replay_create_info,
                    GetAllocationCallbacks(pAllocator),
                    pPipelineCache->GetHandlePointer());
    }
}

VkResult VulkanReplayConsumerBase::OverrideResetDescriptorPool(PFN_vkResetDescriptorPool  func,
                                                               VkResult                   original_result,
                                                               const VulkanDeviceInfo*    device_info,
                                                               VulkanDescriptorPoolInfo*  pool_info,
                                                               VkDescriptorPoolResetFlags flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pool_info != nullptr));

    // Descriptor sets allocated from the pool are implicitly freed and must be removed from the object info table.
    for (auto child_id : pool_info->child_ids)
    {
        object_info_table_.RemoveVkDescriptorSetInfo(child_id);
    }

    pool_info->child_ids.clear();

    return func(device_info->handle, pool_info->handle, flags);
}

VkResult VulkanReplayConsumerBase::OverrideCreateDebugReportCallbackEXT(
    PFN_vkCreateDebugReportCallbackEXT                                      func,
    VkResult                                                                original_result,
    const VulkanInstanceInfo*                                               instance_info,
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
    const VulkanInstanceInfo*                                               instance_info,
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
    VulkanDeviceInfo*                                             device_info,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                         pSwapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && !pCreateInfo->IsNull() && (pSwapchain != nullptr) &&
           !pSwapchain->IsNull() && (pSwapchain->GetHandlePointer() != nullptr));

    VkResult result             = VK_SUCCESS;
    auto     replay_create_info = pCreateInfo->GetPointer();
    GFXRECON_ASSERT(replay_create_info != nullptr);
    auto replay_swapchain = pSwapchain->GetHandlePointer();
    auto swapchain_info   = reinterpret_cast<VulkanSwapchainKHRInfo*>(pSwapchain->GetConsumerData(0));
    assert(swapchain_info != nullptr);

    // Ignore swapchain creation if surface creation was skipped when rendering is restricted to a specific surface.
    if (replay_create_info->surface != VK_NULL_HANDLE)
    {
        // Ensure that the window has been resized properly.  For Android, this ensures that we will set the proper
        // screen orientation when the swapchain pre-transform specifies a 90 or 270 degree rotation for older files
        // that do not include a ResizeWindowCmd2 command.
        auto meta_info = pCreateInfo->GetMetaStructPointer();
        if (meta_info != nullptr)
        {
            SetSwapchainWindowSize(meta_info);
        }

        ProcessSwapchainFullScreenExclusiveInfo(pCreateInfo->GetMetaStructPointer());

        VkSwapchainCreateInfoKHR modified_create_info = (*replay_create_info);

        // Screenshots are active, so ensure that swapchain images can be used as a transfer source.
        if (screenshot_handler_ != nullptr || options_.dumping_resources)
        {
            // Screenshots and/or dump resources are active, so ensure that swapchain images can be used as a transfer
            // source.
            modified_create_info.imageUsage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        }

        bool                      colorspace_extension_used_unsupported = false;
        VulkanPhysicalDeviceInfo* physical_device_info =
            object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
        VulkanInstanceInfo* instance_info = object_info_table_.GetVkInstanceInfo(physical_device_info->parent_id);

        auto colorspace_extension_map_iterator = kColorSpaceExtensionMap.find(replay_create_info->imageColorSpace);
        if (colorspace_extension_map_iterator != kColorSpaceExtensionMap.end())
        {
            auto supported_extension_iterator = std::find(instance_info->enabled_extensions.begin(),
                                                          instance_info->enabled_extensions.end(),
                                                          colorspace_extension_map_iterator->second);
            colorspace_extension_used_unsupported =
                supported_extension_iterator == instance_info->enabled_extensions.end();
        }

        if (colorspace_extension_used_unsupported)
        {
            if (options_.use_colorspace_fallback)
            {
                modified_create_info.imageColorSpace = VkColorSpaceKHR::VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
                GFXRECON_LOG_INFO("Forcing supported color space for swapchain (ID = %" PRIu64 ")",
                                  swapchain_info->capture_id);
            }
            else
            {
                GFXRECON_LOG_ERROR("Swapchain (ID = %" PRIu64
                                   ") uses color space provided by unsupported VK_EXT_swapchain_colorspace",
                                   swapchain_info->capture_id);
            }
        }

        const VkBaseInStructure* current = reinterpret_cast<const VkBaseInStructure*>(modified_create_info.pNext);
        while (current != nullptr)
        {
            if (current->sType == VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT)
            {
                const VkImageCompressionControlEXT* compression_control =
                    reinterpret_cast<const VkImageCompressionControlEXT*>(current);

                swapchain_info->compression_control =
                    std::make_shared<VkImageCompressionControlEXT>(*compression_control);
                VkImageCompressionControlEXT* copy_target = swapchain_info->compression_control.get();

                // If the fixed rate flags are present, then create a copy for the internal version of
                // the structure used to pass to swapchain image creation.
                if (compression_control->compressionControlPlaneCount > 0 &&
                    compression_control->pFixedRateFlags != nullptr)
                {
                    std::copy(compression_control->pFixedRateFlags,
                              compression_control->pFixedRateFlags + compression_control->compressionControlPlaneCount,
                              std::back_inserter(swapchain_info->compression_fixed_rate_flags));
                    copy_target->pFixedRateFlags = swapchain_info->compression_fixed_rate_flags.data();
                }
                else
                {
                    // Set everything as if the count was 0 because it could only get here if there was
                    // nothing in it already, or there was no valid data.
                    copy_target->compressionControlPlaneCount = 0;
                    copy_target->pFixedRateFlags              = nullptr;
                    swapchain_info->compression_fixed_rate_flags.clear();
                }
                copy_target->pNext = nullptr;
                break;
            }

            current = current->pNext;
        }

        result = swapchain_->CreateSwapchainKHR(original_result,
                                                func,
                                                device_info,
                                                &modified_create_info,
                                                GetAllocationCallbacks(pAllocator),
                                                pSwapchain,
                                                GetDeviceTable(device_info->handle));
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping creation for swapchain (ID = %" PRIu64 "), which is backed by a disabled surface",
                          swapchain_info->capture_id);

        // Set fax handle data to find uncreated swapchain later.
        // Possible colision of handles from driver, but should not occur starting with uint max.
        static format::HandleId dummy_handle = std::numeric_limits<uint64_t>::max();
        (*replay_swapchain)                  = format::FromHandleId<VkSwapchainKHR>(dummy_handle);
        --dummy_handle;

        swapchain_info->surface    = VK_NULL_HANDLE;
        swapchain_info->surface_id = format::kNullHandleId;
    }

    swapchain_info->image_flags        = replay_create_info->flags;
    swapchain_info->image_array_layers = replay_create_info->imageArrayLayers;
    swapchain_info->image_usage        = replay_create_info->imageUsage;
    swapchain_info->image_sharing_mode = replay_create_info->imageSharingMode;
    swapchain_info->device_info        = device_info;
    swapchain_info->width              = replay_create_info->imageExtent.width;
    swapchain_info->height             = replay_create_info->imageExtent.height;
    swapchain_info->format             = replay_create_info->imageFormat;

    if ((result == VK_SUCCESS) && ((*replay_swapchain) != VK_NULL_HANDLE))
    {
        if ((replay_create_info->imageSharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (replay_create_info->queueFamilyIndexCount > 0) && (replay_create_info->pQueueFamilyIndices != nullptr))
        {
            swapchain_info->queue_family_indices.resize(replay_create_info->queueFamilyIndexCount);
            std::memcpy(swapchain_info->queue_family_indices.data(),
                        replay_create_info->pQueueFamilyIndices,
                        sizeof(uint32_t) * replay_create_info->queueFamilyIndexCount);
        }
        else
        {
            swapchain_info->queue_family_indices.clear();
            swapchain_info->queue_family_indices.emplace_back(0);
        }

        swapchain_info->surface    = replay_create_info->surface;
        swapchain_info->surface_id = pCreateInfo->GetMetaStructPointer()->surface;
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateSharedSwapchainsKHR(
    PFN_vkCreateSharedSwapchainsKHR                               func,
    VkResult                                                      original_result,
    VulkanDeviceInfo*                                             device_info,
    uint32_t                                                      swapchainCount,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                         pSwapchains)
{
    // TODO: It should do something similar to OverrideCreateSwapchainKHR.
    GFXRECON_LOG_ERROR("vkCreateSharedSwapchainsKHR is unsupported");
    return func(device_info->handle,
                swapchainCount,
                pCreateInfos->GetPointer(),
                GetAllocationCallbacks(pAllocator),
                pSwapchains->GetHandlePointer());
}

void VulkanReplayConsumerBase::OverrideDestroySwapchainKHR(
    PFN_vkDestroySwapchainKHR                                  func,
    VulkanDeviceInfo*                                          device_info,
    VulkanSwapchainKHRInfo*                                    swapchain_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Delete backed images of dummy swapchain.
    if ((swapchain_info != nullptr) && (swapchain_info->surface == VK_NULL_HANDLE))
    {
        auto allocator = device_info->allocator.get();
        assert(allocator != nullptr);

        for (const VulkanImageInfo& image_info : swapchain_info->image_infos)
        {
            allocator->DestroyImageDirect(image_info.handle, nullptr, image_info.allocator_data);
            allocator->FreeMemoryDirect(image_info.memory, nullptr, image_info.memory_allocator_data);
        }
    }
    else
    {
        swapchain_->DestroySwapchainKHR(func, device_info, swapchain_info, GetAllocationCallbacks(pAllocator));
    }
}

VkResult VulkanReplayConsumerBase::OverrideGetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR    func,
                                                                 VkResult                       original_result,
                                                                 const VulkanDeviceInfo*        device_info,
                                                                 VulkanSwapchainKHRInfo*        swapchain_info,
                                                                 PointerDecoder<uint32_t>*      pSwapchainImageCount,
                                                                 HandlePointerDecoder<VkImage>* pSwapchainImages)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (swapchain_info != nullptr) && (pSwapchainImageCount != nullptr) &&
           !pSwapchainImageCount->IsNull() && (pSwapchainImages != nullptr));

    VkResult result              = original_result;
    auto     replay_image_count  = pSwapchainImageCount->GetOutputPointer();
    auto     replay_images       = pSwapchainImages->GetHandlePointer();
    uint32_t capture_image_count = *pSwapchainImageCount->GetPointer();

    // Handle if swapchain was never created due to surface-index being skipped
    if (swapchain_info->surface == VK_NULL_HANDLE)
    {
        if (replay_images == nullptr)
        {
            // Set the image count from data saved in trace file.
            (*replay_image_count) = capture_image_count;
        }
        else
        {
            // Create an image for the null swapchain.  Based on vkspec.html#swapchain-wsi-image-create-info.
            VkImageCreateInfo image_create_info = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
            image_create_info.pNext             = nullptr;
            image_create_info.flags             = 0;
            image_create_info.imageType         = VK_IMAGE_TYPE_2D;
            image_create_info.format            = swapchain_info->format;
            image_create_info.extent            = { swapchain_info->width, swapchain_info->height, 1 };
            image_create_info.mipLevels         = 1;
            image_create_info.arrayLayers       = swapchain_info->image_array_layers;
            image_create_info.samples           = VK_SAMPLE_COUNT_1_BIT;
            image_create_info.tiling            = VK_IMAGE_TILING_OPTIMAL;
            image_create_info.usage             = swapchain_info->image_usage;
            image_create_info.sharingMode       = swapchain_info->image_sharing_mode;
            image_create_info.queueFamilyIndexCount =
                static_cast<uint32_t>(swapchain_info->queue_family_indices.size());
            image_create_info.pQueueFamilyIndices = swapchain_info->queue_family_indices.data();
            image_create_info.initialLayout       = VK_IMAGE_LAYOUT_UNDEFINED;

            if ((swapchain_info->image_flags & VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR) ==
                VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR)
            {
                image_create_info.flags |= VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
            }

            GFXRECON_LOG_INFO("Creating %u images of %ux%u to back dummy swapchain (ID = %" PRIu64 ")",
                              capture_image_count,
                              image_create_info.extent.width,
                              image_create_info.extent.height,
                              swapchain_info->capture_id);

            for (uint32_t i = 0; i < capture_image_count; ++i)
            {
                VkImage*         replay_image = &(replay_images[i]);
                VulkanImageInfo* image_info = reinterpret_cast<VulkanImageInfo*>(pSwapchainImages->GetConsumerData(i));
                assert(image_info != nullptr);

                result = CreateSwapchainImage(device_info, &image_create_info, replay_image, image_info);

                if ((result != VK_SUCCESS) || (replay_image == VK_NULL_HANDLE))
                {
                    GFXRECON_LOG_ERROR("Unable to create backing images for dummy swapchain (ID = %" PRIu64 ")",
                                       swapchain_info->capture_id);
                    break;
                }

                image_info->format             = swapchain_info->format;
                image_info->extent             = { swapchain_info->width, swapchain_info->height, 1 };
                image_info->layer_count        = swapchain_info->image_array_layers;
                image_info->level_count        = 1;
                image_info->tiling             = VK_IMAGE_TILING_OPTIMAL;
                image_info->usage              = swapchain_info->image_usage;
                image_info->sample_count       = VK_SAMPLE_COUNT_1_BIT;
                image_info->type               = VK_IMAGE_TYPE_2D;
                image_info->current_layout     = VK_IMAGE_LAYOUT_UNDEFINED;
                image_info->is_swapchain_image = true;

                // Create a copy of the image info to use for image cleanup when the swapchain is destroyed.
                swapchain_info->image_infos.push_back(*image_info);
            }
        }
    }
    else
    {
        // It means the application only ran GetSwapchainImage once. It didn't get image count first.
        if (swapchain_info->replay_image_count == 0 && replay_images != nullptr)
        {
            swapchain_->GetSwapchainImagesKHR(
                original_result, func, device_info, swapchain_info, capture_image_count, replay_image_count, nullptr);
        }

        result = swapchain_->GetSwapchainImagesKHR(
            original_result, func, device_info, swapchain_info, capture_image_count, replay_image_count, replay_images);

        if ((result == VK_SUCCESS) && (replay_images != nullptr) && (replay_image_count != nullptr))
        {
            uint32_t count = (*replay_image_count);

            swapchain_info->acquired_indices.resize(count);

            for (uint32_t i = 0; i < count; ++i)
            {
                auto image_info = reinterpret_cast<VulkanImageInfo*>(pSwapchainImages->GetConsumerData(i));
                assert(image_info != nullptr);

                image_info->format             = swapchain_info->format;
                image_info->extent             = { swapchain_info->width, swapchain_info->height, 1 };
                image_info->layer_count        = swapchain_info->image_array_layers;
                image_info->level_count        = 1;
                image_info->tiling             = VK_IMAGE_TILING_OPTIMAL;
                image_info->usage              = swapchain_info->image_usage;
                image_info->sample_count       = VK_SAMPLE_COUNT_1_BIT;
                image_info->type               = VK_IMAGE_TYPE_2D;
                image_info->current_layout     = VK_IMAGE_LAYOUT_UNDEFINED;
                image_info->is_swapchain_image = true;
            }

            // Store image handles for screenshot generation.
            if ((screenshot_handler_ != nullptr) && (swapchain_info->images.size() < count))
            {
                if (!swapchain_info->images.empty())
                {
                    // Clear any images that may have been stored by a previous, incomplete call to
                    // vkGetSwapchainImagesKHR.
                    swapchain_info->images.clear();
                }

                for (uint32_t i = 0; i < count; ++i)
                {
                    swapchain_info->images.push_back(replay_images[i]);
                }
            }
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                                               VkResult                  original_result,
                                                               const VulkanDeviceInfo*   device_info,
                                                               VulkanSwapchainKHRInfo*   swapchain_info,
                                                               uint64_t                  timeout,
                                                               VulkanSemaphoreInfo*      semaphore_info,
                                                               VulkanFenceInfo*          fence_info,
                                                               PointerDecoder<uint32_t>* pImageIndex)
{
    assert(swapchain_info != nullptr);

    VkResult result = VK_SUCCESS;

    // If image acquire failed at capture, there is nothing worth replaying as the fence and semaphore aren't processed
    // and a successful acquire on replay of an image that does not have a corresponding present to replay can lead to
    // OUT_OF_DATE errors.
    if (original_result != VK_SUCCESS && original_result != VK_SUBOPTIMAL_KHR)
    {
        result = original_result;
    }
    else if (swapchain_info->surface != VK_NULL_HANDLE)
    {
        assert((device_info != nullptr) && (pImageIndex != nullptr) && !pImageIndex->IsNull());

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

            if (captured_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
            {
                swapchain_info->acquired_indices.resize(captured_index + 1);
            }

            swapchain_info->acquired_indices[captured_index] = { captured_index, true };

            // The image has already been acquired. Swap the synchronization objects.
            if (semaphore != VK_NULL_HANDLE)
            {
                // TODO: This should be processed at a higher level where the original handle IDs are available, so that
                // the swap can be performed with the original handle ID and the semaphore can be guaranteed not to be
                // used after destroy.
                object_info_table_.ReplaceSemaphore(semaphore, preacquire_semaphore);
                preacquire_semaphore = semaphore;
            }

            if (fence != VK_NULL_HANDLE)
            {
                // TODO: This should be processed at a higher level where the original handle IDs are available, so that
                // the swap can be performed with the original handle ID and the fence can be guaranteed not to be used
                // after destroy.
                object_info_table_.ReplaceFence(fence, preacquire_fence);
                preacquire_fence = fence;
            }

            table->DestroySemaphore(device, preacquire_semaphore, nullptr);
            table->DestroyFence(device, preacquire_fence, nullptr);
        }
        else
        {
            auto replay_index = pImageIndex->GetOutputPointer();

            assert(replay_index != nullptr);

            // If expected result is VK_SUCCESS, ensure that vkAcquireNextImageKHR waits until the image is
            // available by using a timeout of UINT64_MAX.
            // If expected result is VK_TIMEOUT, try to get a timeout by using a timeout of 0.
            // If expected result is anything else, use the passed in timeout value.
            if (original_result == VK_SUCCESS)
            {
                timeout = std::numeric_limits<uint64_t>::max();
            }
            else if (original_result == VK_TIMEOUT)
            {
                timeout = 0;
            }
            result = swapchain_->AcquireNextImageKHR(original_result,
                                                     func,
                                                     device_info,
                                                     swapchain_info,
                                                     timeout,
                                                     semaphore_info,
                                                     fence_info,
                                                     captured_index,
                                                     replay_index);

            if (captured_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
            {
                swapchain_info->acquired_indices.resize(captured_index + 1);
            }

            // Track the index that was acquired on replay, which may be different than the captured index.
            swapchain_info->acquired_indices[captured_index] = { (*replay_index), true };
        }
    }
    else
    {
        // Track semphore and fence objects as shadow objects so that they can be ignored when they would have been
        // unsignaled (waited on).
        if (semaphore_info != nullptr)
        {
            semaphore_info->shadow_signaled = true;
            shadow_semaphores_.insert(semaphore_info->handle);
        }

        if (fence_info != nullptr)
        {
            fence_info->shadow_signaled = true;
            shadow_fences_.insert(fence_info->handle);
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAcquireNextImage2KHR(
    PFN_vkAcquireNextImage2KHR                                     func,
    VkResult                                                       original_result,
    const VulkanDeviceInfo*                                        device_info,
    const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                                      pImageIndex)
{
    assert((pAcquireInfo != nullptr) && !pAcquireInfo->IsNull());

    VkResult                result            = VK_SUCCESS;
    auto                    acquire_meta_info = pAcquireInfo->GetMetaStructPointer();
    VulkanSwapchainKHRInfo* swapchain_info    = object_info_table_.GetVkSwapchainKHRInfo(acquire_meta_info->swapchain);
    assert(swapchain_info != nullptr);

    // If image acquire failed at capture, there is nothing worth replaying as the fence and semaphore aren't processed
    // and a successful acquire on replay of an image that does not have a corresponding present to replay can lead to
    // OUT_OF_DATE errors.
    if (original_result < 0)
    {
        result = original_result;
    }
    else if (swapchain_info->surface != VK_NULL_HANDLE)
    {
        assert((device_info != nullptr) && (pImageIndex != nullptr) && !pImageIndex->IsNull());

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

            if (captured_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
            {
                swapchain_info->acquired_indices.resize(captured_index + 1);
            }

            if (swapchain_info != nullptr)
            {
                swapchain_info->acquired_indices[captured_index] = { captured_index, true };
            }

            // The image has already been acquired. Swap the synchronization objects.
            if (replay_acquire_info->semaphore != VK_NULL_HANDLE)
            {
                // TODO: This should be processed at a higher level where the original handle IDs are available, so that
                // the swap can be performed with the original handle ID and the semaphore can be guaranteed not to be
                // used after destroy.
                object_info_table_.ReplaceSemaphore(replay_acquire_info->semaphore, preacquire_semaphore);
                preacquire_semaphore = replay_acquire_info->semaphore;
            }

            if (replay_acquire_info->fence != VK_NULL_HANDLE)
            {
                // TODO: This should be processed at a higher level where the original handle IDs are available, so that
                // the swap can be performed with the original handle ID and the fence can be guaranteed not to be used
                // after destroy.
                object_info_table_.ReplaceFence(replay_acquire_info->fence, preacquire_fence);
                preacquire_fence = replay_acquire_info->fence;
            }

            table->DestroySemaphore(device, preacquire_semaphore, nullptr);
            table->DestroyFence(device, preacquire_fence, nullptr);
        }
        else
        {
            auto replay_index = pImageIndex->GetOutputPointer();

            assert(replay_index != nullptr);

            auto swapchain_info = object_info_table_.GetVkSwapchainKHRInfo(acquire_meta_info->swapchain);

            // If expected result is VK_SUCCESS, ensure that vkAcquireNextImageKHR2 waits until the image is
            // available by using a timeout of UINT64_MAX.
            // If expected result is VK_TIMEOUT, try to get a timeout by using a timeout of 0.
            // If expected result is anything else, use the passed in timeout value.
            VkAcquireNextImageInfoKHR modified_acquire_info = *replay_acquire_info;
            if (original_result == VK_SUCCESS)
            {
                modified_acquire_info.timeout = std::numeric_limits<uint64_t>::max();
            }
            else if (original_result == VK_TIMEOUT)
            {
                modified_acquire_info.timeout = 0;
            }
            result = swapchain_->AcquireNextImage2KHR(original_result,
                                                      func,
                                                      device_info,
                                                      swapchain_info,
                                                      &modified_acquire_info,
                                                      captured_index,
                                                      replay_index);

            if (captured_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
            {
                swapchain_info->acquired_indices.resize(captured_index + 1);
            }

            // Track the index that was acquired on replay, which may be different than the captured index.
            swapchain_info->acquired_indices[captured_index] = { (*replay_index), true };
        }
    }
    else
    {
        // Track semphore and fence objects as shadow objects so that they can be ignored when they would have been
        // unsignaled (waited on).
        VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(acquire_meta_info->semaphore);
        VulkanFenceInfo*     fence_info     = object_info_table_.GetVkFenceInfo(acquire_meta_info->fence);

        if (semaphore_info != nullptr)
        {
            semaphore_info->shadow_signaled = true;
            shadow_semaphores_.insert(semaphore_info->handle);
        }

        if (fence_info != nullptr)
        {
            fence_info->shadow_signaled = true;
            shadow_fences_.insert(fence_info->handle);
        }
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideQueuePresentKHR(PFN_vkQueuePresentKHR                                 func,
                                                  VkResult                                              original_result,
                                                  const VulkanQueueInfo*                                queue_info,
                                                  const StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    assert((queue_info != nullptr) && (pPresentInfo != nullptr) && !pPresentInfo->IsNull());

    VkResult   result             = VK_SUCCESS;
    const auto present_info       = pPresentInfo->GetPointer();
    auto       present_info_data  = pPresentInfo->GetMetaStructPointer();
    bool       dispatched_command = true;

    // Make a shallow copy of the VkPresentInfoKHR structure and change pSwapchains to reference a copy of
    // the original swapchain array with the dummy swapchains omitted.
    VkPresentInfoKHR            modified_present_info = *present_info;
    VkDeviceGroupPresentInfoKHR modified_device_group_present_info{ VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR };
    VkPresentRegionsKHR         modified_present_region_info{ VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR };
    VkPresentTimesInfoGOOGLE    modified_present_times_info{ VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE };

    valid_swapchains_.clear();
    modified_image_indices_.clear();
    modified_device_masks_.clear();
    modified_regions_.clear();
    modified_times_.clear();
    removed_semaphores_.clear();
    removed_swapchain_indices_.clear();
    capture_image_indices_.clear();
    swapchain_infos_.clear();

    if ((screenshot_handler_ != nullptr) && (screenshot_handler_->IsScreenshotFrame()))
    {
        auto meta_info = pPresentInfo->GetMetaStructPointer();
        assert((meta_info != nullptr) && !meta_info->pSwapchains.IsNull());

        WriteScreenshots(meta_info);
    }

    // If rendering is restricted to a specific surface, need to check for dummy swapchains at present.
    if (options_.surface_index != -1)
    {
        const auto swapchain_ids = present_info_data->pSwapchains.GetPointer();
        for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
        {
            assert(swapchain_ids != nullptr);

            const auto swapchain_info = object_info_table_.GetVkSwapchainKHRInfo(swapchain_ids[i]);
            if ((swapchain_info != nullptr) && (swapchain_info->surface != VK_NULL_HANDLE))
            {
                valid_swapchains_.emplace_back(swapchain_info->handle);
                swapchain_infos_.emplace_back(swapchain_info);

                uint32_t capture_image_index = present_info->pImageIndices[i];
                capture_image_indices_.emplace_back(capture_image_index);

                if (capture_image_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
                {
                    swapchain_info->acquired_indices.resize(capture_image_index + 1);
                }

                if (!swapchain_info->acquired_indices[capture_image_index].acquired)
                {
                    GFXRECON_ASSERT(swapchain_info->device_info);

                    VkDevice device = swapchain_info->device_info->handle;
                    GFXRECON_ASSERT(device);

                    auto    device_table  = GetDeviceTable(device);
                    VkFence acquire_fence = VK_NULL_HANDLE;

                    VkFenceCreateInfo fence_create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
                    fence_create_info.pNext             = nullptr;
                    fence_create_info.flags             = 0;
                    result = device_table->CreateFence(device, &fence_create_info, nullptr, &acquire_fence);
                    GFXRECON_ASSERT(result == VK_SUCCESS);

                    uint32_t replay_index = 0;
                    result                = swapchain_->AcquireNextImageKHR(original_result,
                                                             device_table->AcquireNextImageKHR,
                                                             swapchain_info->device_info,
                                                             swapchain_info,
                                                             std::numeric_limits<uint64_t>::max(),
                                                             VK_NULL_HANDLE,
                                                             acquire_fence,
                                                             capture_image_index,
                                                             &replay_index);
                    GFXRECON_ASSERT((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR));

                    result = device_table->WaitForFences(
                        device, 1, &acquire_fence, true, std::numeric_limits<uint64_t>::max());
                    GFXRECON_ASSERT(result == VK_SUCCESS);

                    swapchain_info->acquired_indices[capture_image_index] = { replay_index, true };
                }

                uint32_t replay_image_index = swapchain_info->acquired_indices[capture_image_index].index;
                modified_image_indices_.emplace_back(replay_image_index);
            }
            else
            {
                removed_swapchain_indices_.insert(i);
            }
        }

        // If a swapchain was removed, pNext stucts that reference the swapchain need to be modified as well.
        if (removed_swapchain_indices_.empty() == false)
        {
            const VkBaseInStructure* next = reinterpret_cast<const VkBaseInStructure*>(modified_present_info.pNext);
            while (next != nullptr)
            {
                switch (next->sType)
                {
                    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
                    {
                        const VkDeviceGroupPresentInfoKHR* pNext =
                            reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(next);

                        if (pNext->pDeviceMasks != nullptr)
                        {
                            for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
                            {
                                if (removed_swapchain_indices_.find(i) == removed_swapchain_indices_.end())
                                {
                                    modified_device_masks_.push_back(pNext->pDeviceMasks[i]);
                                }
                            }

                            assert(valid_swapchains_.size() == modified_device_masks_.size());

                            modified_device_group_present_info.pNext = pNext->pNext;
                            modified_device_group_present_info.swapchainCount =
                                static_cast<uint32_t>(modified_device_masks_.size());
                            modified_device_group_present_info.pDeviceMasks = modified_device_masks_.data();
                            modified_device_group_present_info.mode         = pNext->mode;
                            pNext                                           = &modified_device_group_present_info;
                        }
                        break;
                    }
                    case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
                    {
                        const VkPresentRegionsKHR* pNext = reinterpret_cast<const VkPresentRegionsKHR*>(next);

                        if (pNext->pRegions != nullptr)
                        {
                            for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
                            {
                                if (removed_swapchain_indices_.find(i) == removed_swapchain_indices_.end())
                                {
                                    modified_regions_.push_back(pNext->pRegions[i]);
                                }
                            }

                            assert(valid_swapchains_.size() == modified_regions_.size());

                            modified_present_region_info.pNext = pNext->pNext;
                            modified_present_region_info.swapchainCount =
                                static_cast<uint32_t>(modified_regions_.size());
                            modified_present_region_info.pRegions = modified_regions_.data();
                            pNext                                 = &modified_present_region_info;
                        }
                        break;
                    }
                    case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
                    {
                        const VkPresentTimesInfoGOOGLE* pNext = reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(next);

                        if (pNext->pTimes != nullptr)
                        {
                            for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
                            {
                                if (removed_swapchain_indices_.find(i) == removed_swapchain_indices_.end())
                                {
                                    modified_times_.push_back(pNext->pTimes[i]);
                                }
                            }

                            assert(valid_swapchains_.size() == modified_times_.size());

                            modified_present_times_info.pNext          = pNext->pNext;
                            modified_present_times_info.swapchainCount = static_cast<uint32_t>(modified_times_.size());
                            modified_present_times_info.pTimes         = modified_times_.data();
                            pNext                                      = &modified_present_times_info;
                        }
                        break;
                    }
                    default:
                        break;
                }

                next = reinterpret_cast<const VkBaseInStructure*>(next->pNext);
            }
        }

        modified_present_info.swapchainCount = static_cast<uint32_t>(valid_swapchains_.size());
        modified_present_info.pSwapchains    = valid_swapchains_.data();
        modified_present_info.pImageIndices  = modified_image_indices_.data();
    }
    else
    {
        // Need to match the last acquired image index from replay to avoid OUT_OF_DATE errors from present.
        modified_image_indices_.insert(modified_image_indices_.end(),
                                       present_info->pImageIndices,
                                       std::next(present_info->pImageIndices, present_info->swapchainCount));

        capture_image_indices_.insert(capture_image_indices_.end(),
                                      present_info->pImageIndices,
                                      std::next(present_info->pImageIndices, present_info->swapchainCount));

        swapchain_infos_.insert(swapchain_infos_.end(), present_info->swapchainCount, nullptr);

        const auto swapchain_ids = present_info_data->pSwapchains.GetPointer();
        for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
        {
            assert(swapchain_ids != nullptr);

            const auto swapchain_info = object_info_table_.GetVkSwapchainKHRInfo(swapchain_ids[i]);
            if (swapchain_info != nullptr)
            {
                swapchain_infos_[i] = swapchain_info;

                uint32_t capture_image_index = present_info->pImageIndices[i];
                capture_image_indices_[i]    = capture_image_index;

                if (capture_image_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
                {
                    swapchain_info->acquired_indices.resize(capture_image_index + 1);
                }

                if (!swapchain_info->acquired_indices[capture_image_index].acquired)
                {
                    GFXRECON_ASSERT(swapchain_info->device_info);

                    VkDevice device = swapchain_info->device_info->handle;
                    GFXRECON_ASSERT(device);

                    auto device_table = GetDeviceTable(device);
                    GFXRECON_ASSERT(device_table);

                    VkFence acquire_fence = VK_NULL_HANDLE;

                    VkFenceCreateInfo fence_create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
                    fence_create_info.pNext             = nullptr;
                    fence_create_info.flags             = 0;
                    result = device_table->CreateFence(device, &fence_create_info, nullptr, &acquire_fence);
                    GFXRECON_ASSERT(result == VK_SUCCESS);

                    uint32_t replay_index = 0;
                    result                = swapchain_->AcquireNextImageKHR(original_result,
                                                             device_table->AcquireNextImageKHR,
                                                             swapchain_info->device_info,
                                                             swapchain_info,
                                                             std::numeric_limits<uint64_t>::max(),
                                                             VK_NULL_HANDLE,
                                                             acquire_fence,
                                                             capture_image_index,
                                                             &replay_index);
                    GFXRECON_ASSERT((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR));

                    result = device_table->WaitForFences(
                        device, 1, &acquire_fence, true, std::numeric_limits<uint64_t>::max());
                    GFXRECON_ASSERT(result == VK_SUCCESS);

                    swapchain_info->acquired_indices[capture_image_index] = { replay_index, true };
                }
                uint32_t replay_image_index = swapchain_info->acquired_indices[capture_image_index].index;
                modified_image_indices_[i]  = replay_image_index;
            }
        }

        modified_present_info.pImageIndices = modified_image_indices_.data();
    }

    if (options_.wait_before_present)
    {
        VkDevice device = MapHandle<VulkanDeviceInfo>(queue_info->parent_id, &CommonObjectInfoTable::GetVkDeviceInfo);
        GetDeviceTable(device)->DeviceWaitIdle(device);
    }

    // Only attempt to find imported or shadow semaphores if we know at least one around.
    if ((!have_imported_semaphores_) && (shadow_semaphores_.empty()) && (modified_present_info.swapchainCount != 0))
    {
        result = swapchain_->QueuePresentKHR(
            original_result, func, capture_image_indices_, swapchain_infos_, queue_info, &modified_present_info);
    }
    else if (modified_present_info.swapchainCount == 0)
    {
        // No need to progress farther if there is no valid swapchain to present.
        dispatched_command = false;

        // Used to mark shadow semaphores as signaled in case acquireNextImage signals were supposed to be waited on
        // here.
        GetShadowSemaphores(present_info_data->pWaitSemaphores, &removed_semaphores_);
    }
    else
    {
        // Check for imported semaphores in the present info, creating a vector of imported semaphore info structures.
        if (present_info_data != nullptr)
        {
            GetImportedSemaphores(present_info_data->pWaitSemaphores, &removed_semaphores_);
            GetShadowSemaphores(present_info_data->pWaitSemaphores, &removed_semaphores_);
        }

        if (removed_semaphores_.empty())
        {
            result = swapchain_->QueuePresentKHR(
                original_result, func, capture_image_indices_, swapchain_infos_, queue_info, &modified_present_info);
        }
        else
        {
            std::vector<VkSemaphore> semaphore_memory;
            auto                     semaphore_iter = removed_semaphores_.begin();

            for (uint32_t i = 0; i < modified_present_info.waitSemaphoreCount; ++i)
            {
                VkSemaphore semaphore = modified_present_info.pWaitSemaphores[i];

                if ((semaphore_iter == removed_semaphores_.end()) || ((*semaphore_iter)->handle != semaphore))
                {
                    semaphore_memory.push_back(semaphore);
                }
                else
                {
                    // Omit the imported semaphore from the current submission.
                    ++semaphore_iter;
                }
            }

            modified_present_info.waitSemaphoreCount = static_cast<uint32_t>(semaphore_memory.size());
            modified_present_info.pWaitSemaphores    = semaphore_memory.data();

            result = swapchain_->QueuePresentKHR(
                original_result, func, capture_image_indices_, swapchain_infos_, queue_info, &modified_present_info);
        }
    }

    // If running with surface-index on, need to track forward progress of semaphore that have been submitted
    if (options_.surface_index != -1)
    {
        if (dispatched_command)
        {
            TrackSemaphoreForwardProgress(present_info_data->pWaitSemaphores, &removed_semaphores_);
        }
        else
        {
            // Need to mark all wait semaphores as not in forward progress.
            const format::HandleId* semaphore_ids = present_info_data->pWaitSemaphores.GetPointer();
            if (semaphore_ids != nullptr)
            {
                size_t count = present_info_data->pWaitSemaphores.GetLength();
                for (uint32_t i = 0; i < count; ++i)
                {
                    VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(semaphore_ids[i]);
                    if (semaphore_info)
                    {
                        semaphore_info->forward_progress = false;
                    }
                }
            }
        }
        const auto* present_fence_info =
            GetPNextMetaStruct<Decoded_VkSwapchainPresentFenceInfoEXT>(pPresentInfo->GetMetaStructPointer()->pNext);
        if (present_fence_info != nullptr)
        {
            for (uint32_t i = 0; i < pPresentInfo->GetPointer()->swapchainCount; ++i)
            {
                format::HandleId fence      = present_fence_info->pFences.GetPointer()[i];
                VulkanFenceInfo* fence_info = object_info_table_.GetVkFenceInfo(fence);
                if (fence_info)
                {
                    fence_info->shadow_signaled = true;
                    shadow_fences_.insert(fence_info->handle);
                }
            }
        }
    }

    if (screenshot_handler_ != nullptr)
    {
        screenshot_handler_->EndFrame();
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideImportSemaphoreFdKHR(
    PFN_vkImportSemaphoreFdKHR                                      func,
    VkResult                                                        original_result,
    const VulkanDeviceInfo*                                         device_info,
    const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    // Skip external semaphore import.  There is no actual file descriptor backing it in replay.
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(device_info);

    assert(pImportSemaphoreFdInfo != nullptr);

    // Track and remove imported sempahore from future wait operations as it will never be signaled.
    if (original_result == VK_SUCCESS)
    {
        auto info = pImportSemaphoreFdInfo->GetMetaStructPointer();
        assert(info != nullptr);

        VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(info->semaphore);

        if (semaphore_info != nullptr)
        {
            have_imported_semaphores_   = true;
            semaphore_info->is_external = true;
        }
    }

    return original_result;
}

VkResult VulkanReplayConsumerBase::OverrideGetSemaphoreFdKHR(
    PFN_vkGetSemaphoreFdKHR                                      func,
    VkResult                                                     original_result,
    const VulkanDeviceInfo*                                      device_info,
    const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    const PointerDecoder<int>*                                   pFd)
{
    // Skip external semaphore file descriptor acquire so that replay is not responsible for closing the file
    // descriptor.
    // From spec:
    //      To avoid leaking resources, the application must release ownership
    //      of the file descriptor when it is no longer needed.
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(device_info);
    GFXRECON_UNREFERENCED_PARAMETER(pGetFdInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pFd);
    return original_result;
}

VkResult VulkanReplayConsumerBase::OverrideImportSemaphoreWin32HandleKHR(
    PFN_vkImportSemaphoreWin32HandleKHR                                      func,
    VkResult                                                                 original_result,
    const VulkanDeviceInfo*                                                  device_info,
    const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    // Skip external semaphore import.  There is no actual OS resource backing it in replay.
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(device_info);

    assert(pImportSemaphoreWin32HandleInfo != nullptr);

    // Track and remove imported sempahore from future wait operations as it will never be signaled.
    if (original_result == VK_SUCCESS)
    {
        auto info = pImportSemaphoreWin32HandleInfo->GetMetaStructPointer();
        assert(info != nullptr);

        VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(info->semaphore);

        if (semaphore_info != nullptr)
        {
            have_imported_semaphores_   = true;
            semaphore_info->is_external = true;
        }
    }

    return original_result;
}

VkResult VulkanReplayConsumerBase::OverrideGetSemaphoreWin32HandleKHR(
    PFN_vkGetSemaphoreWin32HandleKHR                                      func,
    VkResult                                                              original_result,
    const VulkanDeviceInfo*                                               device_info,
    const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    const PointerDecoder<uint64_t, void*>*                                pHandle)
{
    // Skip external semaphore handle acquire so that replay is not responsible for closing the handle.
    // From spec:
    //      To avoid leaking resources, the application must release ownership
    //      of them using the CloseHandle system call when they are no longer needed.
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(device_info);
    GFXRECON_UNREFERENCED_PARAMETER(pGetWin32HandleInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pHandle);
    return original_result;
}

VkResult VulkanReplayConsumerBase::OverrideGetRandROutputDisplayEXT(PFN_vkGetRandROutputDisplayEXT      func,
                                                                    VkResult                            original_result,
                                                                    const VulkanPhysicalDeviceInfo*     physicalDevice,
                                                                    Display*                            dpy,
                                                                    RROutput                            rrOutput,
                                                                    HandlePointerDecoder<VkDisplayKHR>* pDisplay)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(physicalDevice);
    GFXRECON_UNREFERENCED_PARAMETER(dpy);
    GFXRECON_UNREFERENCED_PARAMETER(rrOutput);
    GFXRECON_UNREFERENCED_PARAMETER(pDisplay);
    return original_result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateAndroidSurfaceKHR(
    PFN_vkCreateAndroidSurfaceKHR                                      func,
    VkResult                                                           original_result,
    VulkanInstanceInfo*                                                instance_info,
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

    return swapchain_->CreateSurface(original_result,
                                     instance_info,
                                     VK_KHR_ANDROID_SURFACE_EXTENSION_NAME,
                                     replay_create_info->flags,
                                     pSurface,
                                     GetInstanceTable(instance_info->handle),
                                     application_.get(),
                                     options_.window_topleft_x,
                                     options_.window_topleft_y,
                                     kDefaultWindowWidth,
                                     kDefaultWindowHeight,
                                     options_.force_windowed || options_.force_windowed_origin);
}

VkResult VulkanReplayConsumerBase::OverrideCreateWin32SurfaceKHR(
    PFN_vkCreateWin32SurfaceKHR                                      func,
    VkResult                                                         original_result,
    VulkanInstanceInfo*                                              instance_info,
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

    return swapchain_->CreateSurface(original_result,
                                     instance_info,
                                     VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
                                     replay_create_info->flags,
                                     pSurface,
                                     GetInstanceTable(instance_info->handle),
                                     application_.get(),
                                     options_.window_topleft_x,
                                     options_.window_topleft_y,
                                     kDefaultWindowWidth,
                                     kDefaultWindowHeight,
                                     options_.force_windowed || options_.force_windowed_origin);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceWin32PresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
    const VulkanPhysicalDeviceInfo*                    physical_device_info,
    uint32_t                                           queueFamilyIndex)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    auto wsi_context    = application_ ? application_->GetWsiContext(VK_KHR_WIN32_SURFACE_EXTENSION_NAME) : nullptr;
    auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
    return window_factory ? window_factory->GetPhysicalDevicePresentationSupport(
                                GetInstanceTable(physical_device), physical_device, queueFamilyIndex)
                          : false;
}

VkResult VulkanReplayConsumerBase::OverrideCreateXcbSurfaceKHR(
    PFN_vkCreateXcbSurfaceKHR                                      func,
    VkResult                                                       original_result,
    VulkanInstanceInfo*                                            instance_info,
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

    return swapchain_->CreateSurface(original_result,
                                     instance_info,
                                     VK_KHR_XCB_SURFACE_EXTENSION_NAME,
                                     replay_create_info->flags,
                                     pSurface,
                                     GetInstanceTable(instance_info->handle),
                                     application_.get(),
                                     options_.window_topleft_x,
                                     options_.window_topleft_y,
                                     kDefaultWindowWidth,
                                     kDefaultWindowHeight,
                                     options_.force_windowed || options_.force_windowed_origin);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceXcbPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
    const VulkanPhysicalDeviceInfo*                  physical_device_info,
    uint32_t                                         queueFamilyIndex,
    xcb_connection_t*                                connection,
    xcb_visualid_t                                   visual_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(connection);
    GFXRECON_UNREFERENCED_PARAMETER(visual_id);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    auto wsi_context    = application_ ? application_->GetWsiContext(VK_KHR_XCB_SURFACE_EXTENSION_NAME) : nullptr;
    auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
    return window_factory ? window_factory->GetPhysicalDevicePresentationSupport(
                                GetInstanceTable(physical_device), physical_device, queueFamilyIndex)
                          : false;
}

VkResult VulkanReplayConsumerBase::OverrideCreateXlibSurfaceKHR(
    PFN_vkCreateXlibSurfaceKHR                                      func,
    VkResult                                                        original_result,
    VulkanInstanceInfo*                                             instance_info,
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

    return swapchain_->CreateSurface(original_result,
                                     instance_info,
                                     VK_KHR_XLIB_SURFACE_EXTENSION_NAME,
                                     replay_create_info->flags,
                                     pSurface,
                                     GetInstanceTable(instance_info->handle),
                                     application_.get(),
                                     options_.window_topleft_x,
                                     options_.window_topleft_y,
                                     kDefaultWindowWidth,
                                     kDefaultWindowHeight,
                                     options_.force_windowed || options_.force_windowed_origin);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceXlibPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
    const VulkanPhysicalDeviceInfo*                   physical_device_info,
    uint32_t                                          queueFamilyIndex,
    Display*                                          dpy,
    VisualID                                          visualID)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(dpy);
    GFXRECON_UNREFERENCED_PARAMETER(visualID);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    auto wsi_context    = application_ ? application_->GetWsiContext(VK_KHR_XLIB_SURFACE_EXTENSION_NAME) : nullptr;
    auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
    return window_factory ? window_factory->GetPhysicalDevicePresentationSupport(
                                GetInstanceTable(physical_device), physical_device, queueFamilyIndex)
                          : false;
}

VkResult VulkanReplayConsumerBase::OverrideCreateWaylandSurfaceKHR(
    PFN_vkCreateWaylandSurfaceKHR                                      func,
    VkResult                                                           original_result,
    VulkanInstanceInfo*                                                instance_info,
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

    return swapchain_->CreateSurface(original_result,
                                     instance_info,
                                     VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
                                     replay_create_info->flags,
                                     pSurface,
                                     GetInstanceTable(instance_info->handle),
                                     application_.get(),
                                     options_.window_topleft_x,
                                     options_.window_topleft_y,
                                     kDefaultWindowWidth,
                                     kDefaultWindowHeight,
                                     options_.force_windowed || options_.force_windowed_origin);
}

VkResult VulkanReplayConsumerBase::OverrideCreateDisplayPlaneSurfaceKHR(
    PFN_vkCreateDisplayPlaneSurfaceKHR                                 func,
    VkResult                                                           original_result,
    VulkanInstanceInfo*                                                instance_info,
    const StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return swapchain_->CreateSurface(original_result,
                                     instance_info,
                                     VK_KHR_DISPLAY_EXTENSION_NAME,
                                     replay_create_info->flags,
                                     pSurface,
                                     GetInstanceTable(instance_info->handle),
                                     application_.get(),
                                     options_.window_topleft_x,
                                     options_.window_topleft_y,
                                     kDefaultWindowWidth,
                                     kDefaultWindowHeight,
                                     options_.force_windowed || options_.force_windowed_origin);
}

VkResult VulkanReplayConsumerBase::OverrideCreateHeadlessSurfaceEXT(
    PFN_vkCreateHeadlessSurfaceEXT                                      func,
    VkResult                                                            original_result,
    VulkanInstanceInfo*                                                 instance_info,
    const StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*          pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                                 pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return swapchain_->CreateSurface(original_result,
                                     instance_info,
                                     VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME,
                                     replay_create_info->flags,
                                     pSurface,
                                     GetInstanceTable(instance_info->handle),
                                     application_.get(),
                                     options_.window_topleft_x,
                                     options_.window_topleft_y,
                                     kDefaultWindowWidth,
                                     kDefaultWindowHeight,
                                     options_.force_windowed || options_.force_windowed_origin);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
    const VulkanPhysicalDeviceInfo*                      physical_device_info,
    uint32_t                                             queueFamilyIndex,
    struct wl_display*                                   display)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(display);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    auto wsi_context    = application_ ? application_->GetWsiContext(VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME) : nullptr;
    auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
    return window_factory ? window_factory->GetPhysicalDevicePresentationSupport(
                                GetInstanceTable(physical_device), physical_device, queueFamilyIndex)
                          : false;
}

VkResult VulkanReplayConsumerBase::OverrideCreateMetalSurfaceEXT(
    PFN_vkCreateMetalSurfaceEXT                                      func,
    VkResult                                                         original_result,
    VulkanInstanceInfo*                                              instance_info,
    const StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                              pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return swapchain_->CreateSurface(original_result,
                                     instance_info,
                                     VK_EXT_METAL_SURFACE_EXTENSION_NAME,
                                     replay_create_info->flags,
                                     pSurface,
                                     GetInstanceTable(instance_info->handle),
                                     application_.get(),
                                     options_.window_topleft_x,
                                     options_.window_topleft_y,
                                     kDefaultWindowWidth,
                                     kDefaultWindowHeight,
                                     options_.force_windowed || options_.force_windowed_origin);
}

void VulkanReplayConsumerBase::OverrideDestroySurfaceKHR(
    PFN_vkDestroySurfaceKHR                                    func,
    VulkanInstanceInfo*                                        instance_info,
    const VulkanSurfaceKHRInfo*                                surface_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    swapchain_->DestroySurface(func, instance_info, surface_info, GetAllocationCallbacks(pAllocator));
}

VkResult VulkanReplayConsumerBase::OverrideCreateAccelerationStructureKHR(
    PFN_vkCreateAccelerationStructureKHR                                      func,
    VkResult                                                                  original_result,
    const VulkanDeviceInfo*                                                   device_info,
    const StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>*                         pAccelerationStructureKHR)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && (pAccelerationStructureKHR != nullptr) &&
           !pAccelerationStructureKHR->IsNull() && (pAccelerationStructureKHR->GetHandlePointer() != nullptr));

    VkResult result              = VK_SUCCESS;
    auto     replay_accel_struct = pAccelerationStructureKHR->GetHandlePointer();
    auto     capture_id          = (*pAccelerationStructureKHR->GetPointer());
    auto     replay_create_info  = pCreateInfo->GetPointer();
    VkDevice device              = device_info->handle;
    auto     device_table        = GetDeviceTable(device);
    assert(device_table != nullptr);

    if (device_info->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        // Set opaque device address
        VkAccelerationStructureCreateInfoKHR modified_create_info = (*replay_create_info);
        modified_create_info.createFlags |= VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR;
        auto entry = device_info->opaque_addresses.find(capture_id);
        if (entry != device_info->opaque_addresses.end())
        {
            modified_create_info.deviceAddress = entry->second;
        }
        else
        {
            GFXRECON_LOG_DEBUG(
                "Opaque device address is not available for VkAccelerationStructureKHR object (ID = %" PRIu64 ")",
                capture_id);
        }

        result = device_table->CreateAccelerationStructureKHR(
            device, &modified_create_info, GetAllocationCallbacks(pAllocator), replay_accel_struct);
    }
    else
    {
        result = device_table->CreateAccelerationStructureKHR(
            device, replay_create_info, GetAllocationCallbacks(pAllocator), replay_accel_struct);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateRayTracingPipelinesKHR(
    PFN_vkCreateRayTracingPipelinesKHR                                     func,
    VkResult                                                               original_result,
    const VulkanDeviceInfo*                                                device_info,
    VulkanDeferredOperationKHRInfo*                                        deferred_operation_info,
    const VulkanPipelineCacheInfo*                                         pipeline_cache_info,
    uint32_t                                                               createInfoCount,
    const StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
    HandlePointerDecoder<VkPipeline>*                                      pPipelines)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfos != nullptr) && (pAllocator != nullptr) &&
           (pPipelines != nullptr) && !pPipelines->IsNull() && (pPipelines->GetHandlePointer() != nullptr));

    VkResult                                 result          = VK_SUCCESS;
    VkDevice                                 device          = device_info->handle;
    auto                                     device_table    = GetDeviceTable(device);
    const VkRayTracingPipelineCreateInfoKHR* in_pCreateInfos = pCreateInfos->GetPointer();
    const VkAllocationCallbacks*             in_pAllocator   = GetAllocationCallbacks(pAllocator);
    VkPipeline*                              out_pPipelines  = pPipelines->GetHandlePointer();
    VkDeferredOperationKHR                   in_deferredOperation =
        (deferred_operation_info != nullptr) ? deferred_operation_info->handle : VK_NULL_HANDLE;
    VkPipelineCache in_pipelineCache = (pipeline_cache_info != nullptr) ? pipeline_cache_info->handle : VK_NULL_HANDLE;

    if (deferred_operation_info)
    {
        deferred_operation_info->pending_state = true;
        deferred_operation_info->record_modified_create_infos.clear();
        deferred_operation_info->record_modified_pgroups.clear();
        deferred_operation_info->replayPipelines.resize(createInfoCount);
        deferred_operation_info->capturePipelines.clear();
        deferred_operation_info->capturePipelines.insert(deferred_operation_info->capturePipelines.end(),
                                                         &pPipelines->GetPointer()[0],
                                                         &pPipelines->GetPointer()[createInfoCount]);
    }

    if (device_info->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
    {
        // Modify pipeline create infos with capture replay flag and data.
        std::vector<VkRayTracingPipelineCreateInfoKHR>                 modified_create_infos;
        std::vector<std::vector<VkRayTracingShaderGroupCreateInfoKHR>> modified_pgroups;
        modified_create_infos.reserve(createInfoCount);
        modified_pgroups.resize(createInfoCount);
        for (uint32_t create_info_i = 0; create_info_i < createInfoCount; ++create_info_i)
        {
            format::HandleId pipeline_capture_id = (*pPipelines[create_info_i].GetPointer());

            // Enable capture replay flag.
            modified_create_infos.push_back(in_pCreateInfos[create_info_i]);
            modified_create_infos[create_info_i].flags |=
                VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR;

            uint32_t group_info_count = in_pCreateInfos[create_info_i].groupCount;
            bool     has_data         = (device_info->shader_group_handles.find(pipeline_capture_id) !=
                             device_info->shader_group_handles.end());

            if (has_data)
            {
                assert(device_info->shader_group_handles.at(pipeline_capture_id).size() ==
                       (device_info->property_feature_info.property_shaderGroupHandleCaptureReplaySize *
                        group_info_count));
            }
            else
            {
                GFXRECON_LOG_WARNING("Missing shader group handle data in for ray tracing pipeline (ID = %" PRIu64 ").",
                                     pipeline_capture_id);
            }

            // Set pShaderGroupCaptureReplayHandle in shader group create infos.
            std::vector<VkRayTracingShaderGroupCreateInfoKHR>& modified_group_infos = modified_pgroups[create_info_i];
            modified_group_infos.reserve(group_info_count);

            for (uint32_t group_info_i = 0; group_info_i < group_info_count; ++group_info_i)
            {
                modified_group_infos.push_back(in_pCreateInfos[create_info_i].pGroups[group_info_i]);

                if (has_data)
                {
                    uint32_t byte_offset =
                        device_info->property_feature_info.property_shaderGroupHandleCaptureReplaySize * group_info_i;
                    modified_group_infos[group_info_i].pShaderGroupCaptureReplayHandle =
                        device_info->shader_group_handles.at(pipeline_capture_id).data() + byte_offset;
                }
                else
                {
                    modified_group_infos[group_info_i].pShaderGroupCaptureReplayHandle = nullptr;
                }
            }

            // Use modified shader group infos.
            modified_create_infos[create_info_i].pGroups = modified_group_infos.data();
        }

        if (omitted_pipeline_cache_data_)
        {
            AllowCompileDuringPipelineCreation(createInfoCount, modified_create_infos.data());
        }

        VkPipeline* created_pipelines = nullptr;

        if (deferred_operation_info)
        {
            created_pipelines = deferred_operation_info->replayPipelines.data();
        }
        else
        {
            created_pipelines = out_pPipelines;
        }

        result = device_table->CreateRayTracingPipelinesKHR(device,
                                                            in_deferredOperation,
                                                            in_pipelineCache,
                                                            createInfoCount,
                                                            modified_create_infos.data(),
                                                            in_pAllocator,
                                                            created_pipelines);

        if ((result == VK_SUCCESS) || (result == VK_OPERATION_NOT_DEFERRED_KHR) ||
            (result == VK_PIPELINE_COMPILE_REQUIRED_EXT))
        {
            // The above return values mean the command is not deferred and driver will finish all workload in current
            // thread. Therefore the created pipelines can be read and copied to out_pPipelines which will be
            // referenced later.
            //
            // Note:
            //     Some pipelines might actually fail creation if the return value is VK_PIPELINE_COMPILE_REQUIRED_EXT.
            //     These failed pipelines will generate VK_NULL_HANDLE.
            //
            //     If the return value is VK_OPERATION_DEFERRED_KHR, it means the command is deferred, and thus pipeline
            //     creation is not finished. Subsequent handling will be done by
            //     vkDeferredOperationJoinKHR/vkGetDeferredOperationResultKHR after pipeline creation is finished.

            if (deferred_operation_info)
            {
                memcpy(out_pPipelines, created_pipelines, createInfoCount * sizeof(VkPipeline));

                // Eventhough vkCreateRayTracingPipelinesKHR was called with a valid deferred operation object, the
                // driver may opt to not defer the command. In this case, set pending_state flag to false to skip
                // vkDeferredOperationJoinKHR handling.
                deferred_operation_info->pending_state = false;
            }
        }

        if (deferred_operation_info)
        {
            deferred_operation_info->record_modified_create_infos = std::move(modified_create_infos);
            deferred_operation_info->record_modified_pgroups      = std::move(modified_pgroups);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR_ONCE("The replay used vkCreateRayTracingPipelinesKHR, which may require the "
                                "rayTracingPipelineShaderGroupHandleCaptureReplay feature for accurate capture and "
                                "replay. The replay device does not support this feature, so replay may fail.");

        if (omitted_pipeline_cache_data_)
        {
            AllowCompileDuringPipelineCreation(createInfoCount,
                                               const_cast<VkRayTracingPipelineCreateInfoKHR*>(in_pCreateInfos));
        }

        VkPipeline* created_pipelines = nullptr;

        if (deferred_operation_info)
        {
            created_pipelines = deferred_operation_info->replayPipelines.data();
        }
        else
        {
            created_pipelines = out_pPipelines;
        }

        result = device_table->CreateRayTracingPipelinesKHR(device,
                                                            in_deferredOperation,
                                                            in_pipelineCache,
                                                            createInfoCount,
                                                            in_pCreateInfos,
                                                            in_pAllocator,
                                                            created_pipelines);

        if ((result == VK_SUCCESS) || (result == VK_OPERATION_NOT_DEFERRED_KHR) ||
            (result == VK_PIPELINE_COMPILE_REQUIRED_EXT))
        {

            if (deferred_operation_info)
            {
                memcpy(out_pPipelines, created_pipelines, createInfoCount * sizeof(VkPipeline));
                deferred_operation_info->pending_state = false;
            }
        }
    }

    if (result >= 0)
    {
        const Decoded_VkRayTracingPipelineCreateInfoKHR* create_info_meta = pCreateInfos->GetMetaStructPointer();

        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            VulkanPipelineInfo* pipeline_info = reinterpret_cast<VulkanPipelineInfo*>(pPipelines->GetConsumerData(i));

            const Decoded_VkPipelineShaderStageCreateInfo* stages_info_meta =
                create_info_meta[i].pStages->GetMetaStructPointer();
            const size_t stages_count = create_info_meta->pStages->GetLength();

            for (size_t s = 0; s < stages_count; ++s)
            {
                VulkanShaderModuleInfo* module_info =
                    object_info_table_.GetVkShaderModuleInfo(stages_info_meta[s].module);
                assert(module_info);
                assert(pipeline_info);

                pipeline_info->shaders.insert({ pCreateInfos->GetPointer()->pStages[s].stage, *module_info });
            }
        }
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideDeferredOperationJoinKHR(PFN_vkDeferredOperationJoinKHR  func,
                                                           VkResult                        original_result,
                                                           const VulkanDeviceInfo*         device_info,
                                                           VulkanDeferredOperationKHRInfo* deferred_operation_info)
{
    if (deferred_operation_info->pending_state == false)
    {
        // The deferred operation object has no deferred command or its deferred command has been finished.
        return VK_SUCCESS;
    }

    VkDevice               device             = device_info->handle;
    VkDeferredOperationKHR deferred_operation = deferred_operation_info->handle;

    PFN_vkGetDeferredOperationMaxConcurrencyKHR vkGetDeferredOperationMaxConcurrencyKHR =
        GetDeviceTable(device)->GetDeferredOperationMaxConcurrencyKHR;

    uint32_t max_threads  = std::thread::hardware_concurrency();
    uint32_t thread_count = std::min(vkGetDeferredOperationMaxConcurrencyKHR(device, deferred_operation), max_threads);
    bool     deferred_operation_completed = false;
    std::vector<std::future<void>> deferred_operation_joins;

    for (uint32_t i = 0; i < thread_count; i++)
    {
        // At least one vkDeferredOperationJoinKHR in a thread has to get VK_SUCCESS.
        deferred_operation_joins.emplace_back(
            std::async(std::launch::async, [func, device, deferred_operation, &deferred_operation_completed]() {
                VkResult result = VK_ERROR_UNKNOWN;
                while (result != VK_SUCCESS && !deferred_operation_completed)
                {
                    result = func(device, deferred_operation);
                    assert(result == VK_SUCCESS || result == VK_THREAD_DONE_KHR || result == VK_THREAD_IDLE_KHR);
                    if (result == VK_SUCCESS)
                    {
                        deferred_operation_completed = true;
                    }
                }
            }));
    }

    for (auto& j : deferred_operation_joins)
    {
        j.get();
    }

    AddHandles<VulkanPipelineInfo>(device_info->capture_id,
                                   deferred_operation_info->capturePipelines.data(),
                                   deferred_operation_info->capturePipelines.size(),
                                   deferred_operation_info->replayPipelines.data(),
                                   deferred_operation_info->replayPipelines.size(),
                                   &CommonObjectInfoTable::AddVkPipelineInfo);

    deferred_operation_info->pending_state = false;
    deferred_operation_info->record_modified_create_infos.clear();
    deferred_operation_info->record_modified_pgroups.clear();
    deferred_operation_info->capturePipelines.clear();
    deferred_operation_info->replayPipelines.clear();

    return VK_SUCCESS;
}

VkDeviceAddress VulkanReplayConsumerBase::OverrideGetBufferDeviceAddress(
    PFN_vkGetBufferDeviceAddress                                   func,
    const VulkanDeviceInfo*                                        device_info,
    const StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    assert((device_info != nullptr) && (pInfo != nullptr) && !pInfo->IsNull() && (pInfo->GetPointer() != nullptr));

    if (!device_info->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        GFXRECON_LOG_ERROR_ONCE("The captured application used vkGetBufferDeviceAddress, which requires the "
                                "bufferDeviceAddressCaptureReplay feature for accurate capture and replay. The "
                                "replay device does not support this feature, so replay may fail.");
    }

    if (!device_info->allocator->SupportsOpaqueDeviceAddresses())
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The captured application used vkGetBufferDeviceAddress. The specified replay option '-m rebind' may not "
            "support the replay of captured device addresses, so replay may fail.");
    }

    VkDevice                         device       = device_info->handle;
    const VkBufferDeviceAddressInfo* address_info = pInfo->GetPointer();

    return func(device, address_info);
}

void VulkanReplayConsumerBase::OverrideGetAccelerationStructureDeviceAddressKHR(
    PFN_vkGetAccelerationStructureDeviceAddressKHR                                   func,
    const VulkanDeviceInfo*                                                          device_info,
    const StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    assert((device_info != nullptr) && (pInfo != nullptr) && !pInfo->IsNull() && (pInfo->GetPointer() != nullptr));

    if (!device_info->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        GFXRECON_LOG_WARNING_ONCE("The captured application used vkGetAccelerationStructureDeviceAddressKHR, which may "
                                  "require the accelerationStructureCaptureReplay feature for accurate capture and "
                                  "replay. The replay device does not support this feature, so replay may fail.");
    }

    if (!device_info->allocator->SupportsOpaqueDeviceAddresses())
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The captured application used vkGetAccelerationStructureDeviceAddressKHR. The specified replay option '-m "
            "rebind' may not support the replay of captured device addresses, so replay may fail.");
    }

    VkDevice                                           device       = device_info->handle;
    const VkAccelerationStructureDeviceAddressInfoKHR* address_info = pInfo->GetPointer();

    func(device, address_info);
}

VkResult
VulkanReplayConsumerBase::OverrideGetRayTracingShaderGroupHandlesKHR(PFN_vkGetRayTracingShaderGroupHandlesKHR func,
                                                                     VkResult                  original_result,
                                                                     const VulkanDeviceInfo*   device_info,
                                                                     const VulkanPipelineInfo* pipeline_info,
                                                                     uint32_t                  firstGroup,
                                                                     uint32_t                  groupCount,
                                                                     size_t                    dataSize,
                                                                     PointerDecoder<uint8_t>*  pData)
{
    assert((device_info != nullptr) && (pipeline_info != nullptr) && (pData != nullptr) &&
           (pData->GetOutputPointer() != nullptr));

    if (!device_info->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The captured application used vkGetRayTracingShaderGroupHandlesKHR, which may require the "
            "rayTracingPipelineShaderGroupHandleCaptureReplay feature for accurate capture and replay. The replay "
            "device does not support this feature, so replay may fail.");
    }

    VkDevice   device      = device_info->handle;
    VkPipeline pipeline    = pipeline_info->handle;
    uint8_t*   output_data = pData->GetOutputPointer();

    return func(device, pipeline, firstGroup, groupCount, dataSize, output_data);
}

VkResult VulkanReplayConsumerBase::OverrideGetAndroidHardwareBufferPropertiesANDROID(
    PFN_vkGetAndroidHardwareBufferPropertiesANDROID                         func,
    VkResult                                                                original_result,
    const VulkanDeviceInfo*                                                 device_info,
    const struct AHardwareBuffer*                                           hardware_buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    assert((device_info != nullptr) && (pProperties != nullptr) && (pProperties->GetOutputPointer() != nullptr));

    if ((hardware_buffer == nullptr) && options_.omit_null_hardware_buffers)
    {

        GFXRECON_LOG_INFO_ONCE("A call to vkGetAndroidHardwareBufferPropertiesANDROID with a NULL "
                               "AHardwareBuffer* was omitted during replay.");
        return original_result;
    }
    else
    {

        if (hardware_buffer == nullptr)
        {
            GFXRECON_LOG_WARNING_ONCE("The captured application used vkGetAndroidHardwareBufferPropertiesANDROID but "
                                      "replay has no way of mapping the captured AHardwareBuffer*; replay may fail. "
                                      "If replay of this call appears to fail, try the replay option "
                                      "\"--omit-null-hardware-buffers\".");
        }

        VkDevice device            = device_info->handle;
        auto*    output_properties = pProperties->GetOutputPointer();

        return func(device, hardware_buffer, output_properties);
    }
}

void VulkanReplayConsumerBase::ClearCommandBufferInfo(VulkanCommandBufferInfo* command_buffer_info)
{
    command_buffer_info->is_frame_boundary = false;
    command_buffer_info->frame_buffer_ids.clear();
}

VkResult VulkanReplayConsumerBase::OverrideBeginCommandBuffer(
    PFN_vkBeginCommandBuffer                                func,
    uint64_t                                                index,
    VkResult                                                original_result,
    VulkanCommandBufferInfo*                                command_buffer_info,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* begin_info_decoder)
{
    ClearCommandBufferInfo(command_buffer_info);

    VkCommandBuffer                 command_buffer = command_buffer_info->handle;
    const VkCommandBufferBeginInfo* begin_info     = begin_info_decoder->GetPointer();

    VkResult res = VK_SUCCESS;
    if (options_.dumping_resources && resource_dumper_.DumpingBeginCommandBufferIndex(index))
    {
        const VulkanDeviceInfo* device = GetObjectInfoTable().GetVkDeviceInfo(command_buffer_info->parent_id);

        res = resource_dumper_.CloneCommandBuffer(
            index, command_buffer_info, GetDeviceTable(device->handle), GetInstanceTable(device->parent));
    }

    if (res == VK_SUCCESS)
    {
        res = func(command_buffer, begin_info);
    }

    return res;
}

VkResult VulkanReplayConsumerBase::OverrideResetCommandBuffer(PFN_vkResetCommandBuffer  func,
                                                              VkResult                  original_result,
                                                              VulkanCommandBufferInfo*  command_buffer_info,
                                                              VkCommandBufferResetFlags flags)
{
    ClearCommandBufferInfo(command_buffer_info);

    VkCommandBuffer command_buffer = command_buffer_info->handle;

    if (options_.dumping_resources)
    {
        resource_dumper_.ResetCommandBuffer((command_buffer));
    }

    return func(command_buffer, flags);
}

VkResult VulkanReplayConsumerBase::OverrideResetCommandPool(PFN_vkResetCommandPool  func,
                                                            VkResult                original_result,
                                                            const VulkanDeviceInfo* device_info,
                                                            VulkanCommandPoolInfo*  pool_info,
                                                            VkCommandPoolResetFlags flags)
{
    assert(device_info != nullptr && pool_info != nullptr);

    if (options_.dumping_resources && original_result >= 0)
    {
        for (auto& cb_id : pool_info->child_ids)
        {
            VulkanCommandBufferInfo* cb_info = object_info_table_.GetVkCommandBufferInfo(cb_id);
            assert(cb_info != nullptr);

            resource_dumper_.ResetCommandBuffer(cb_info->handle);
        }
    }

    VkResult res = func(device_info->handle, pool_info->handle, flags);
    return res;
}

void VulkanReplayConsumerBase::OverrideDestroyCommandPool(
    PFN_vkDestroyCommandPool                             func,
    const VulkanDeviceInfo*                              device_info,
    VulkanCommandPoolInfo*                               pool_info,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    assert(device_info != nullptr && pool_info != nullptr);

    if (options_.dumping_resources)
    {
        for (auto& cb_id : pool_info->child_ids)
        {
            VulkanCommandBufferInfo* cb_info = object_info_table_.GetVkCommandBufferInfo(cb_id);
            assert(cb_info != nullptr);

            resource_dumper_.ResetCommandBuffer(cb_info->handle);
        }
    }

    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    func(device_info->handle, pool_info->handle, in_pAllocator);
}

void VulkanReplayConsumerBase::OverrideCmdDebugMarkerInsertEXT(
    PFN_vkCmdDebugMarkerInsertEXT                             func,
    VulkanCommandBufferInfo*                                  command_buffer_info,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* marker_info_decoder)
{
    const VkDebugMarkerMarkerInfoEXT* marker_info = marker_info_decoder->GetPointer();
    func(command_buffer_info->handle, marker_info);

    // Look for the debug marker that identifies this command buffer as a VR frame boundary.
    if (util::platform::StringContains(marker_info->pMarkerName, graphics::kVulkanVrFrameDelimiterString))
    {
        command_buffer_info->is_frame_boundary = true;
    }
};

void VulkanReplayConsumerBase::OverrideCmdInsertDebugUtilsLabelEXT(
    PFN_vkCmdInsertDebugUtilsLabelEXT                   func,
    VulkanCommandBufferInfo*                            command_buffer_info,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* label_info_decoder)
{
    const VkDebugUtilsLabelEXT* label_info = label_info_decoder->GetPointer();
    func(command_buffer_info->handle, label_info);

    // Look for the label that identifies this command buffer as a VR frame boundary.
    if (util::platform::StringContains(label_info->pLabelName, graphics::kVulkanVrFrameDelimiterString))
    {
        command_buffer_info->is_frame_boundary = true;
    }
};

void VulkanReplayConsumerBase::OverrideCmdBeginRenderPass(
    PFN_vkCmdBeginRenderPass                             func,
    VulkanCommandBufferInfo*                             command_buffer_info,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* render_pass_begin_info_decoder,
    VkSubpassContents                                    contents)
{
    const auto render_pass_info_meta = render_pass_begin_info_decoder->GetMetaStructPointer();
    auto       framebuffer_id        = render_pass_info_meta->framebuffer;
    auto       render_pass_id        = render_pass_info_meta->renderPass;
    command_buffer_info->frame_buffer_ids.push_back(framebuffer_id);

    auto framebuffer_info = object_info_table_.GetVkFramebufferInfo(framebuffer_id);
    auto render_pass_info = object_info_table_.GetVkRenderPassInfo(render_pass_id);
    if ((render_pass_info != nullptr) && (framebuffer_info != nullptr))
    {
        const format::HandleId* attachment_image_view_ids = nullptr;
        if ((framebuffer_info->framebuffer_flags & VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT) ==
            VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT)
        {
            // The attachments for imageless framebuffers are provided in the pNext chain of vkCmdBeginRenderPass
            const auto* attachment_begin_info = GetPNextMetaStruct<Decoded_VkRenderPassAttachmentBeginInfo>(
                render_pass_begin_info_decoder->GetMetaStructPointer()->pNext);

            GFXRECON_ASSERT(attachment_begin_info)
            GFXRECON_ASSERT(attachment_begin_info->pAttachments.GetLength() ==
                            render_pass_info->attachment_description_final_layouts.size());
            attachment_image_view_ids = attachment_begin_info->pAttachments.GetPointer();
        }
        else
        {
            GFXRECON_ASSERT(framebuffer_info->attachment_image_view_ids.size() ==
                            render_pass_info->attachment_description_final_layouts.size());
            attachment_image_view_ids = framebuffer_info->attachment_image_view_ids.data();
        }

        for (size_t i = 0; i < render_pass_info->attachment_description_final_layouts.size(); ++i)
        {
            auto image_view_id   = attachment_image_view_ids[i];
            auto image_view_info = object_info_table_.GetVkImageViewInfo(image_view_id);
            command_buffer_info->image_layout_barriers[image_view_info->image_id] =
                render_pass_info->attachment_description_final_layouts[i];

            const VulkanImageViewInfo* img_view_info = object_info_table_.GetVkImageViewInfo(image_view_id);
            assert(image_view_info != nullptr);
            VulkanImageInfo* img_info = object_info_table_.GetVkImageInfo(img_view_info->image_id);
            assert(img_info);
            img_info->intermediate_layout = render_pass_info->attachment_description_final_layouts[i];
        }
    }

    VkCommandBuffer command_buffer = command_buffer_info->handle;

    func(command_buffer, render_pass_begin_info_decoder->GetPointer(), contents);
}

void VulkanReplayConsumerBase::OverrideCmdBeginRenderPass2(
    PFN_vkCmdBeginRenderPass2                            func,
    VulkanCommandBufferInfo*                             command_buffer_info,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* render_pass_begin_info_decoder,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>*    subpass_begin_info_decode)
{
    const auto render_pass_info_meta = render_pass_begin_info_decoder->GetMetaStructPointer();
    auto       framebuffer_id        = render_pass_info_meta->framebuffer;
    auto       render_pass_id        = render_pass_info_meta->renderPass;
    command_buffer_info->frame_buffer_ids.push_back(framebuffer_id);

    auto framebuffer_info = object_info_table_.GetVkFramebufferInfo(framebuffer_id);
    auto render_pass_info = object_info_table_.GetVkRenderPassInfo(render_pass_id);
    if ((render_pass_info != nullptr) && (framebuffer_info != nullptr))
    {
        GFXRECON_ASSERT(framebuffer_info->attachment_image_view_ids.size() ==
                        render_pass_info->attachment_description_final_layouts.size());

        for (size_t i = 0; i < render_pass_info->attachment_description_final_layouts.size(); ++i)
        {
            auto image_view_id   = framebuffer_info->attachment_image_view_ids[i];
            auto image_view_info = object_info_table_.GetVkImageViewInfo(image_view_id);
            command_buffer_info->image_layout_barriers[image_view_info->image_id] =
                render_pass_info->attachment_description_final_layouts[i];

            const VulkanImageViewInfo* img_view_info = object_info_table_.GetVkImageViewInfo(image_view_id);
            assert(image_view_info != nullptr);
            VulkanImageInfo* img_info = object_info_table_.GetVkImageInfo(img_view_info->image_id);
            assert(img_info);
            img_info->intermediate_layout = render_pass_info->attachment_description_final_layouts[i];
        }
    }

    VkCommandBuffer command_buffer = command_buffer_info->handle;

    func(command_buffer, render_pass_begin_info_decoder->GetPointer(), subpass_begin_info_decode->GetPointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreateImageView(
    PFN_vkCreateImageView                                func,
    VkResult                                             original_result,
    const VulkanDeviceInfo*                              device_info,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* create_info_decoder,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator_decoder,
    HandlePointerDecoder<VkImageView>*                   view_decoder)
{
    VkDevice                     device      = device_info->handle;
    const VkImageViewCreateInfo* create_info = create_info_decoder->GetPointer();
    const VkAllocationCallbacks* allocator   = GetAllocationCallbacks(allocator_decoder);
    VkImageView*                 out_view    = view_decoder->GetHandlePointer();

    VkResult result = func(device, create_info, allocator, out_view);

    if ((result == VK_SUCCESS) && ((*out_view) != VK_NULL_HANDLE))
    {
        auto image_view_info = reinterpret_cast<VulkanImageViewInfo*>(view_decoder->GetConsumerData(0));
        GFXRECON_ASSERT(image_view_info != nullptr);

        image_view_info->image_id = create_info_decoder->GetMetaStructPointer()->image;
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateFramebuffer(
    PFN_vkCreateFramebuffer                                func,
    VkResult                                               original_result,
    const VulkanDeviceInfo*                                device_info,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* create_info_decoder,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   allocator_decoder,
    HandlePointerDecoder<VkFramebuffer>*                   frame_buffer_decoder)
{
    VkDevice                       device          = device_info->handle;
    const VkFramebufferCreateInfo* create_info     = create_info_decoder->GetPointer();
    const VkAllocationCallbacks*   allocator       = GetAllocationCallbacks(allocator_decoder);
    VkFramebuffer*                 out_framebuffer = frame_buffer_decoder->GetHandlePointer();

    VkResult result = func(device, create_info, allocator, out_framebuffer);

    if ((result == VK_SUCCESS) && ((*out_framebuffer) != VK_NULL_HANDLE))
    {
        auto framebuffer_info = reinterpret_cast<VulkanFramebufferInfo*>(frame_buffer_decoder->GetConsumerData(0));
        GFXRECON_ASSERT(framebuffer_info != nullptr);

        framebuffer_info->framebuffer_flags = create_info->flags;

        if ((create_info->attachmentCount > 0) && (create_info->pAttachments != nullptr) &&
            ((create_info->flags & VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT) != VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT))
        {
            for (uint32_t i = 0; i < create_info->attachmentCount; ++i)
            {
                framebuffer_info->attachment_image_view_ids.push_back(
                    create_info_decoder->GetMetaStructPointer()->pAttachments.GetPointer()[i]);
            }
        }
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideFrameBoundaryANDROID(PFN_vkFrameBoundaryANDROID func,
                                                            const VulkanDeviceInfo*    device_info,
                                                            const VulkanSemaphoreInfo* semaphore_info,
                                                            const VulkanImageInfo*     image_info)
{
    GFXRECON_ASSERT((device_info != nullptr));

    VkDevice    device    = device_info->handle;
    VkSemaphore semaphore = semaphore_info ? semaphore_info->handle : VK_NULL_HANDLE;
    VkImage     image     = image_info ? image_info->handle : VK_NULL_HANDLE;

    if (screenshot_handler_ != nullptr)
    {
        if (screenshot_handler_->IsScreenshotFrame() && image_info != nullptr)
        {
            const std::string filename_prefix =
                screenshot_file_prefix_ + "_frame_" + std::to_string(screenshot_handler_->GetCurrentFrame());

            const uint32_t screenshot_width =
                options_.screenshot_scale
                    ? static_cast<uint32_t>(options_.screenshot_scale * image_info->extent.width)
                    : (options_.screenshot_width ? options_.screenshot_width : image_info->extent.width);

            const uint32_t screenshot_height =
                options_.screenshot_scale
                    ? static_cast<uint32_t>(options_.screenshot_scale * image_info->extent.height)
                    : (options_.screenshot_height ? options_.screenshot_height : image_info->extent.height);

            auto instance_table = GetInstanceTable(device_info->parent);
            GFXRECON_ASSERT(instance_table != nullptr);

            VkPhysicalDeviceMemoryProperties memory_properties;
            instance_table->GetPhysicalDeviceMemoryProperties(device_info->parent, &memory_properties);

            screenshot_handler_->WriteImage(filename_prefix,
                                            device_info,
                                            GetDeviceTable(device),
                                            memory_properties,
                                            device_info->allocator.get(),
                                            image,
                                            image_info->format,
                                            image_info->extent.width,
                                            image_info->extent.height,
                                            screenshot_width,
                                            screenshot_height,
                                            image_info->current_layout);
        }

        screenshot_handler_->EndFrame();
    }

    func(device, semaphore, image);
}

// We want to allow skipping the query for tool properties because the capture layer actually adds this extension
// and the application may end up using the query.  However, this extension may not be present for replay, so
// we stub it out in that case.  This will generate warnings in the GfxReconstruct output, but it shouldn't result
// in a failure.
VkResult VulkanReplayConsumerBase::OverrideGetPhysicalDeviceToolProperties(
    PFN_vkGetPhysicalDeviceToolProperties                         func,
    VkResult                                                      original_result,
    const VulkanPhysicalDeviceInfo*                               physical_device_info,
    PointerDecoder<uint32_t>*                                     pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    const auto& instance_extensions = physical_device_info->parent_enabled_extensions;
    if (std::find(instance_extensions.begin(), instance_extensions.end(), VK_EXT_TOOLING_INFO_EXTENSION_NAME) !=
        instance_extensions.end())
    {
        return func(physical_device_info->handle, pToolCount->GetOutputPointer(), pToolProperties->GetOutputPointer());
    }
    else
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The captured application used vkGetPhysicalDeviceToolProperties. This is not supported by "
            "the replay device, so replay may fail.");
        *pToolCount->GetOutputPointer() = 0;
        return VK_SUCCESS;
    }
}

VkResult
VulkanReplayConsumerBase::OverrideWaitSemaphores(PFN_vkWaitSemaphores    func,
                                                 VkResult                original_result,
                                                 const VulkanDeviceInfo* device_info,
                                                 const StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pInfo,
                                                 uint64_t                                                 timeout)
{
    assert((device_info != nullptr) && (pInfo != nullptr) && !pInfo->IsNull() && (pInfo->GetPointer() != nullptr));
    VkDevice                   device    = device_info->handle;
    const VkSemaphoreWaitInfo* wait_info = pInfo->GetPointer();
    VkResult                   result;

    // If expected result is VK_SUCCESS, ensure that vkWaitSemaphores waits until semaphores
    // are available by using a timeout of UINT64_MAX.
    // If expected result is VK_TIMEOUT, try to get a timeout by using a timeout of 0.
    // If expected result is anything else, use the passed in timeout value.
    if (original_result == VK_SUCCESS)
    {
        timeout = std::numeric_limits<uint64_t>::max();
    }
    else if (original_result == VK_TIMEOUT)
    {
        timeout = 0;
    }
    result = func(device, wait_info, timeout);
    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAcquireProfilingLockKHR(
    PFN_vkAcquireProfilingLockKHR                                      func,
    VkResult                                                           original_result,
    const VulkanDeviceInfo*                                            device_info,
    const StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    assert((device_info != nullptr) && (pInfo != nullptr) && !pInfo->IsNull() && (pInfo->GetPointer() != nullptr));
    VkDevice                             device       = device_info->handle;
    const VkAcquireProfilingLockInfoKHR* acquire_info = pInfo->GetPointer();
    VkResult                             result;

    // If expected result is VK_SUCCESS, ensure that vkAcquireProfilingLockKHR waits for locks
    // using a timeout of UINT64_MAX.
    // If expected result is VK_TIMEOUT, try to get a timeout by using a timeout of 0.
    // If expected result is anything else, use the passed in timeout value.
    VkAcquireProfilingLockInfoKHR modified_acquire_info = *acquire_info;
    if (original_result == VK_SUCCESS)
    {
        modified_acquire_info.timeout = std::numeric_limits<uint64_t>::max();
    }
    else if (original_result == VK_TIMEOUT)
    {
        modified_acquire_info.timeout = 0;
    }
    result = func(device, &modified_acquire_info);
    return result;
}

VkResult VulkanReplayConsumerBase::OverrideWaitForPresentKHR(PFN_vkWaitForPresentKHR func,
                                                             VkResult                original_result,
                                                             const VulkanDeviceInfo* device_info,
                                                             VulkanSwapchainKHRInfo* swapchain_info,
                                                             uint64_t                presentid,
                                                             uint64_t                timeout)
{
    assert((device_info != nullptr) && (swapchain_info != nullptr));
    VkDevice       device    = device_info->handle;
    VkSwapchainKHR swapchain = swapchain_info->handle;
    VkResult       result;

    // If expected result is VK_SUCCESS, ensure that vkWaitForPresent waits for present by
    // using a timeout of UINT64_MAX.
    // If expected result is VK_TIMEOUT, try to get a timeout by using a timeout of 0.
    // If expected result is anything else, use the passed in timeout value.
    if (original_result == VK_SUCCESS)
    {
        timeout = std::numeric_limits<uint64_t>::max();
    }
    else if (original_result == VK_TIMEOUT)
    {
        timeout = 0;
    }
    result = func(device, swapchain, presentid, timeout);
    return result;
}

void VulkanReplayConsumerBase::MapDescriptorUpdateTemplateHandles(
    const VulkanDescriptorUpdateTemplateInfo* update_template_info, DescriptorUpdateTemplateDecoder* decoder)
{
    assert(decoder != nullptr);

    size_t image_info_count        = decoder->GetImageInfoCount();
    size_t buffer_info_count       = decoder->GetBufferInfoCount();
    size_t texel_buffer_view_count = decoder->GetTexelBufferViewCount();
    size_t accel_struct_count      = decoder->GetAccelerationStructureKHRCount();

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
            auto texel_buffer_view_info = object_info_table_.GetVkBufferViewInfo(texel_buffer_view_ids[i]);

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

    if (accel_struct_count > 0)
    {
        auto accel_struct_ids     = decoder->GetAccelerationStructureKHRHandleIdsPointer();
        auto accel_struct_handles = decoder->GetAccelerationStructureKHRPointer();

        for (size_t i = 0; i < accel_struct_count; ++i)
        {
            auto accel_struct_info = object_info_table_.GetVkAccelerationStructureKHRInfo(accel_struct_ids[i]);

            if (accel_struct_info != nullptr)
            {
                accel_struct_handles[i] = accel_struct_info->handle;
            }
            else
            {
                accel_struct_handles[i] = VK_NULL_HANDLE;
            }
        }
    }
}

void VulkanReplayConsumerBase::GetImportedSemaphores(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                                                     std::vector<const VulkanSemaphoreInfo*>* imported_semaphores)
{
    assert(imported_semaphores != nullptr);

    const format::HandleId* semaphore_ids = semaphore_data.GetPointer();
    if (semaphore_ids != nullptr)
    {
        size_t count = semaphore_data.GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            const VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(semaphore_ids[i]);
            if ((semaphore_info != nullptr) && semaphore_info->is_external)
            {
                imported_semaphores->push_back(semaphore_info);
            }
        }
    }
}

void VulkanReplayConsumerBase::GetImportedSemaphores(
    const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
    std::vector<const VulkanSemaphoreInfo*>*                   imported_semaphores)
{
    assert(imported_semaphores != nullptr);

    const Decoded_VkSemaphoreSubmitInfo* semaphore_infos = semaphore_info_data->GetMetaStructPointer();
    if (semaphore_infos != nullptr)
    {
        size_t count = semaphore_info_data->GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            const VulkanSemaphoreInfo* semaphore_info =
                object_info_table_.GetVkSemaphoreInfo(semaphore_infos[i].semaphore);
            if ((semaphore_info != nullptr) && semaphore_info->is_external)
            {
                imported_semaphores->push_back(semaphore_info);
            }
        }
    }
}

void VulkanReplayConsumerBase::SignalShadowSemaphore(VulkanSemaphoreInfo*                     semaphore_info,
                                                     std::vector<const VulkanSemaphoreInfo*>* shadow_semaphores)
{
    if (semaphore_info->shadow_signaled == true)
    {
        // If found, unsignal the semaphore to represent it being used.
        shadow_semaphores->push_back(semaphore_info);
        semaphore_info->shadow_signaled = false;
        shadow_semaphores_.erase(semaphore_info->handle);
    }
    else if (semaphore_info->signaled)
    {
        // If the semaphore was signaled with VkSubmitInfo we need to wait on it
        // and mark that it has been waited on
        semaphore_info->signaled = false;
    }
}

void VulkanReplayConsumerBase::GetShadowSemaphores(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                                                   std::vector<const VulkanSemaphoreInfo*>* shadow_semaphores)
{
    assert(shadow_semaphores != nullptr);

    const format::HandleId* semaphore_ids = semaphore_data.GetPointer();
    if (semaphore_ids != nullptr)
    {
        size_t count = semaphore_data.GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(semaphore_ids[i]);
            if (semaphore_info != nullptr)
            {
                SignalShadowSemaphore(semaphore_info, shadow_semaphores);
            }
        }
    }
}

void VulkanReplayConsumerBase::GetShadowSemaphores(
    const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
    std::vector<const VulkanSemaphoreInfo*>*                   shadow_semaphores)
{
    assert(shadow_semaphores != nullptr);

    const Decoded_VkSemaphoreSubmitInfo* semaphore_infos = semaphore_info_data->GetMetaStructPointer();
    if (semaphore_infos != nullptr)
    {
        size_t count = semaphore_info_data->GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(semaphore_infos[i].semaphore);
            if (semaphore_info != nullptr)
            {
                SignalShadowSemaphore(semaphore_info, shadow_semaphores);
            }
        }
    }
}

void VulkanReplayConsumerBase::TrackSemaphoreForwardProgress(
    const HandlePointerDecoder<VkSemaphore>& semaphore_data,
    std::vector<const VulkanSemaphoreInfo*>* removed_semaphores)
{
    assert(removed_semaphores != nullptr);

    const format::HandleId* semaphore_ids = semaphore_data.GetPointer();
    if (semaphore_ids != nullptr)
    {
        size_t count = semaphore_data.GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(semaphore_ids[i]);
            if (semaphore_info != nullptr)
            {
                VkSemaphore semaphore = semaphore_info->handle;
                // Need to ignore if removed.
                bool removed = false;
                for (const VulkanSemaphoreInfo* remove_semaphore : *removed_semaphores)
                {
                    if (semaphore == remove_semaphore->handle)
                    {
                        removed                          = true;
                        semaphore_info->forward_progress = false;
                        break;
                    }
                }

                // If not removed, mark as forward progress.
                if (removed == false)
                {
                    semaphore_info->forward_progress = true;
                }
            }
        }
    }
}

void VulkanReplayConsumerBase::TrackSemaphoreForwardProgress(
    const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
    std::vector<const VulkanSemaphoreInfo*>*                   removed_semaphores)
{
    assert(removed_semaphores != nullptr);

    const Decoded_VkSemaphoreSubmitInfo* semaphore_infos = semaphore_info_data->GetMetaStructPointer();
    if (semaphore_infos != nullptr)
    {
        size_t count = semaphore_info_data->GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(semaphore_infos[i].semaphore);
            if (semaphore_info != nullptr)
            {
                VkSemaphore semaphore = semaphore_info->handle;
                // Need to ignore if removed.
                bool removed = false;
                for (const VulkanSemaphoreInfo* remove_semaphore : *removed_semaphores)
                {
                    if (semaphore == remove_semaphore->handle)
                    {
                        removed                          = true;
                        semaphore_info->forward_progress = false;
                        break;
                    }
                }

                // If not removed, mark as forward progress.
                if (removed == false)
                {
                    semaphore_info->forward_progress = true;
                }
            }
        }
    }
}

void VulkanReplayConsumerBase::GetNonForwardProgress(
    const HandlePointerDecoder<VkSemaphore>& semaphore_data,
    std::vector<const VulkanSemaphoreInfo*>* non_forward_progress_semaphores)
{
    assert(non_forward_progress_semaphores != nullptr);

    const format::HandleId* semaphore_ids = semaphore_data.GetPointer();
    if (semaphore_ids != nullptr)
    {
        size_t count = semaphore_data.GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(semaphore_ids[i]);
            if ((semaphore_info != nullptr) && (semaphore_info->forward_progress == false))
            {
                if (semaphore_info->signaled == false)
                {
                    semaphore_info->signaled = true;
                }
                else
                {
                    non_forward_progress_semaphores->push_back(semaphore_info);
                }
            }
        }
    }
}

void VulkanReplayConsumerBase::GetNonForwardProgress(
    const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
    std::vector<const VulkanSemaphoreInfo*>*                   non_forward_progress_semaphores)
{
    assert(non_forward_progress_semaphores != nullptr);

    const Decoded_VkSemaphoreSubmitInfo* semaphore_infos = semaphore_info_data->GetMetaStructPointer();
    if (semaphore_infos != nullptr)
    {
        size_t count = semaphore_info_data->GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(semaphore_infos[i].semaphore);
            if ((semaphore_info != nullptr) && (semaphore_info->forward_progress == false))
            {
                if (semaphore_info->signaled == false)
                {
                    semaphore_info->signaled = true;
                }
                else
                {
                    non_forward_progress_semaphores->push_back(semaphore_info);
                }
            }
        }
    }
}

VkResult VulkanReplayConsumerBase::CreateSwapchainImage(const VulkanDeviceInfo*  device_info,
                                                        const VkImageCreateInfo* image_create_info,
                                                        VkImage*                 image,
                                                        VulkanImageInfo*         image_info)
{
    // TODO - Rename/repurpose CreateStagingImage to be more allow single place to create image resources.
    VulkanResourceAllocator* allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VulkanResourceAllocator::ResourceData allocator_image_data;
    VkResult result = allocator->CreateImageDirect(image_create_info, nullptr, image, &allocator_image_data);

    if (result == VK_SUCCESS)
    {
        VkDeviceMemory                      memory                = VK_NULL_HANDLE;
        VulkanResourceAllocator::MemoryData allocator_memory_data = 0;
        VkMemoryRequirements                memory_reqs;

        GetDeviceTable(device_info->handle)->GetImageMemoryRequirements(device_info->handle, *image, &memory_reqs);

        // TODO - Move this and VulkanResourceInitializer::GetVkMemoryTypeIndex to common place
        // Can be any flag
        VkMemoryPropertyFlags property_flags    = VK_QUEUE_FLAG_BITS_MAX_ENUM;
        uint32_t              memory_type_index = std::numeric_limits<uint32_t>::max();
        {
            // TODO - Probably useful to save memory properties as class variable
            VkPhysicalDeviceMemoryProperties properties;
            auto                             instance_table = GetInstanceTable(device_info->parent);
            assert(instance_table != nullptr);
            instance_table->GetPhysicalDeviceMemoryProperties(device_info->parent, &properties);

            for (uint32_t i = 0; i < properties.memoryTypeCount; i++)
            {
                if ((memory_reqs.memoryTypeBits & (1 << i)) &&
                    ((properties.memoryTypes[i].propertyFlags & property_flags) != 0))
                {
                    memory_type_index = i;
                    break;
                }
            }
            assert(memory_type_index != std::numeric_limits<uint32_t>::max());
        }

        VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
        alloc_info.pNext                = nullptr;
        alloc_info.memoryTypeIndex      = memory_type_index;
        alloc_info.allocationSize       = memory_reqs.size;

        result = allocator->AllocateMemoryDirect(&alloc_info, nullptr, &memory, &allocator_memory_data);

        if (result == VK_SUCCESS)
        {
            VkMemoryPropertyFlags flags;
            result = allocator->BindImageMemoryDirect(
                *image, memory, 0, allocator_image_data, allocator_memory_data, &flags);
        }

        if (result == VK_SUCCESS)
        {
            // Only need to save data that is used to delete image
            // Normal swapchain images don't carry any consumer data
            image_info->handle                = *image;
            image_info->allocator_data        = allocator_image_data;
            image_info->memory                = memory;
            image_info->memory_allocator_data = allocator_memory_data;
        }
        else
        {
            allocator->DestroyImageDirect(*image, nullptr, allocator_image_data);
        }
    }
    return result;
}

void VulkanReplayConsumerBase::UpdateDescriptorSetInfoWithTemplate(
    VulkanDescriptorSetInfo*                  desc_set_info,
    const VulkanDescriptorUpdateTemplateInfo* template_info,
    const DescriptorUpdateTemplateDecoder*    decoder) const
{
    if (desc_set_info != nullptr)
    {
        size_t image_info_count        = 0;
        size_t buffer_info_count       = 0;
        size_t texel_buffer_view_count = 0;
        size_t accel_struct_count      = 0;

        for (const auto& entry : template_info->entries)
        {
            const VkDescriptorType type          = entry.descriptorType;
            const uint32_t         binding_index = entry.dstBinding;
            const uint32_t         count         = entry.descriptorCount;

            desc_set_info->descriptors[binding_index].desc_type = type;

            switch (type)
            {
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                {
                    const Decoded_VkDescriptorImageInfo* img_desc_info = decoder->GetImageInfoMetaStructPointer();
                    assert(img_desc_info != nullptr);

                    // Allocate a bit more
                    if (desc_set_info->descriptors[binding_index].image_info.size() < count)
                    {
                        desc_set_info->descriptors[binding_index].image_info.resize(2 * count);
                    }

                    for (uint32_t i = 0; i < count; ++i)
                    {
                        const VulkanImageViewInfo* img_view_info =
                            object_info_table_.GetVkImageViewInfo(img_desc_info[image_info_count].imageView);
                        desc_set_info->descriptors[binding_index].image_info[i] = {
                            img_view_info, img_desc_info[image_info_count].decoded_value->imageLayout
                        };
                        ++image_info_count;
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_SAMPLER:
                {
                    // Allocate a bit more
                    if (desc_set_info->descriptors[binding_index].image_info.size() < count)
                    {
                        desc_set_info->descriptors[binding_index].image_info.resize(2 * count);
                    }

                    image_info_count += count;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                {
                    const Decoded_VkDescriptorBufferInfo* buf_desc_info = decoder->GetBufferInfoMetaStructPointer();
                    assert(buf_desc_info != nullptr);

                    // Allocate a bit more
                    if (desc_set_info->descriptors[binding_index].buffer_info.size() < count)
                    {
                        desc_set_info->descriptors[binding_index].buffer_info.resize(2 * count);
                    }

                    for (uint32_t i = 0; i < count; ++i)
                    {
                        const VulkanBufferInfo* buf_info =
                            object_info_table_.GetVkBufferInfo(buf_desc_info[buffer_info_count].buffer);
                        assert(buf_info != nullptr);

                        desc_set_info->descriptors[binding_index].buffer_info[i] = {
                            buf_info,
                            buf_desc_info[buffer_info_count].decoded_value->offset,
                            buf_desc_info[buffer_info_count].decoded_value->range
                        };

                        ++buffer_info_count;
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    const format::HandleId* buffer_view_ids = decoder->GetTexelBufferViewHandleIdsPointer();
                    assert(buffer_view_ids != nullptr);

                    // Allocate a bit more
                    if (desc_set_info->descriptors[binding_index].texel_buffer_view_info.size() < count)
                    {
                        desc_set_info->descriptors[binding_index].texel_buffer_view_info.resize(2 * count);
                    }

                    for (uint32_t i = 0; i < count; ++i)
                    {
                        const VulkanBufferViewInfo* buf_view_info =
                            object_info_table_.GetVkBufferViewInfo(buffer_view_ids[texel_buffer_view_count]);
                        assert(buf_view_info != nullptr);

                        desc_set_info->descriptors[binding_index].texel_buffer_view_info[i] = buf_view_info;

                        ++texel_buffer_view_count;
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                {
                    desc_set_info->descriptors[binding_index].desc_type = type;
                    accel_struct_count += count;
                }
                break;

                default:
                    GFXRECON_LOG_WARNING("%s() Unrecognized/Unhandled descriptor type (%s)",
                                         __func__,
                                         util::ToString<VkDescriptorType>(type).c_str());
                    break;
            }
        }

        // Sanity checks. These should match else we missed something from the template
        assert(image_info_count == decoder->GetImageInfoCount());
        assert(buffer_info_count == decoder->GetBufferInfoCount());
        assert(texel_buffer_view_count == decoder->GetTexelBufferViewCount());
        assert(accel_struct_count == decoder->GetAccelerationStructureKHRCount());
    }
}

void VulkanReplayConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo& call_info,
                                                                         format::HandleId   device,
                                                                         format::HandleId   descriptorSet,
                                                                         format::HandleId   descriptorUpdateTemplate,
                                                                         DescriptorUpdateTemplateDecoder* pData)
{
    assert(pData != nullptr);

    VkDevice        in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDescriptorSet in_descriptorSet =
        MapHandle<VulkanDescriptorSetInfo>(descriptorSet, &CommonObjectInfoTable::GetVkDescriptorSetInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = VK_NULL_HANDLE;
    auto update_template_info = object_info_table_.GetVkDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(update_template_info, pData);

    if (update_template_info != nullptr)
    {
        in_descriptorUpdateTemplate = update_template_info->handle;
    }

    if (options_.dumping_resources)
    {
        VulkanDescriptorSetInfo* desc_set_info = object_info_table_.GetVkDescriptorSetInfo(descriptorSet);
        UpdateDescriptorSetInfoWithTemplate(desc_set_info, update_template_info, pData);
    }

    GetDeviceTable(in_device)->UpdateDescriptorSetWithTemplate(
        in_device, in_descriptorSet, in_descriptorUpdateTemplate, pData->GetPointer());
}

void VulkanReplayConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                             format::HandleId   commandBuffer,
                                                                             format::HandleId descriptorUpdateTemplate,
                                                                             format::HandleId layout,
                                                                             uint32_t         set,
                                                                             DescriptorUpdateTemplateDecoder* pData)
{
    assert(pData != nullptr);

    VkCommandBuffer in_commandBuffer =
        MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = VK_NULL_HANDLE;
    VkPipelineLayout           in_layout =
        MapHandle<VulkanPipelineLayoutInfo>(layout, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);
    auto update_template_info = object_info_table_.GetVkDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(update_template_info, pData);

    if (update_template_info != nullptr)
    {
        in_descriptorUpdateTemplate = update_template_info->handle;
    }

    GetDeviceTable(in_commandBuffer)
        ->CmdPushDescriptorSetWithTemplateKHR(
            in_commandBuffer, in_descriptorUpdateTemplate, in_layout, set, pData->GetPointer());

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPushDescriptorSetWithTemplateKHR(
            call_info,
            GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSetWithTemplateKHR,
            in_commandBuffer,
            in_descriptorUpdateTemplate,
            in_layout,
            set,
            pData);
    }
}

void VulkanReplayConsumerBase::Process_vkCmdPushDescriptorSetWithTemplate2KHR(
    const ApiCallInfo&                                                    call_info,
    format::HandleId                                                      commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfoKHR>* pPushDescriptorSetWithTemplateInfo)
{
    Decoded_VkPushDescriptorSetWithTemplateInfoKHR* in_info =
        pPushDescriptorSetWithTemplateInfo->GetMetaStructPointer();
    VkPushDescriptorSetWithTemplateInfoKHR* value = in_info->decoded_value;
    VulkanDescriptorUpdateTemplateInfo*     update_template_info =
        object_info_table_.GetVkDescriptorUpdateTemplateInfo(in_info->descriptorUpdateTemplate);

    VkCommandBuffer in_commandBuffer =
        MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    value->layout =
        MapHandle<VulkanPipelineLayoutInfo>(in_info->layout, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

    MapDescriptorUpdateTemplateHandles(update_template_info, &in_info->pData);
    value->pData = in_info->pData.GetPointer();

    if (update_template_info != nullptr)
    {
        value->descriptorUpdateTemplate = update_template_info->handle;
    }

    GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSetWithTemplate2KHR(in_commandBuffer, value);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPushDescriptorSetWithTemplate2KHR(
            call_info, GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSetWithTemplate2KHR, in_commandBuffer, value);
    }
}

void VulkanReplayConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                            format::HandleId   device,
                                                                            format::HandleId   descriptorSet,
                                                                            format::HandleId   descriptorUpdateTemplate,
                                                                            DescriptorUpdateTemplateDecoder* pData)
{
    assert(pData != nullptr);

    VkDevice        in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDescriptorSet in_descriptorSet =
        MapHandle<VulkanDescriptorSetInfo>(descriptorSet, &CommonObjectInfoTable::GetVkDescriptorSetInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = VK_NULL_HANDLE;
    auto update_template_info = object_info_table_.GetVkDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(update_template_info, pData);

    if (update_template_info != nullptr)
    {
        in_descriptorUpdateTemplate = update_template_info->handle;
    }

    if (options_.dumping_resources)
    {
        VulkanDescriptorSetInfo* desc_set_info = object_info_table_.GetVkDescriptorSetInfo(descriptorSet);
        UpdateDescriptorSetInfoWithTemplate(desc_set_info, update_template_info, pData);
    }

    GetDeviceTable(in_device)->UpdateDescriptorSetWithTemplateKHR(
        in_device, in_descriptorSet, in_descriptorUpdateTemplate, pData->GetPointer());
}

void VulkanReplayConsumerBase::Process_vkCreateRayTracingPipelinesKHR(
    const ApiCallInfo&                                               call_info,
    VkResult                                                         returnValue,
    format::HandleId                                                 device,
    format::HandleId                                                 deferredOperation,
    format::HandleId                                                 pipelineCache,
    uint32_t                                                         createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
    HandlePointerDecoder<VkPipeline>*                                pPipelines)
{
    auto in_device            = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_deferredOperation = GetObjectInfoTable().GetVkDeferredOperationKHRInfo(deferredOperation);
    auto in_pipelineCache     = GetObjectInfoTable().GetVkPipelineCacheInfo(pipelineCache);
    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());

    if (!pPipelines->IsNull())
    {
        pPipelines->SetHandleLength(createInfoCount);
    }

    std::vector<VulkanPipelineInfo> handle_info(createInfoCount);

    for (size_t i = 0; i < createInfoCount; ++i)
    {
        pPipelines->SetConsumerData(i, &handle_info[i]);
    }

    VkResult replay_result =
        OverrideCreateRayTracingPipelinesKHR(GetDeviceTable(in_device->handle)->CreateRayTracingPipelinesKHR,
                                             returnValue,
                                             in_device,
                                             in_deferredOperation,
                                             in_pipelineCache,
                                             createInfoCount,
                                             pCreateInfos,
                                             pAllocator,
                                             pPipelines);
    CheckResult("vkCreateRayTracingPipelinesKHR", returnValue, replay_result, call_info);

    if ((replay_result == VK_SUCCESS) || (replay_result == VK_OPERATION_NOT_DEFERRED_KHR) ||
        (replay_result == VK_PIPELINE_COMPILE_REQUIRED_EXT))
    {
        AddHandles<VulkanPipelineInfo>(device,
                                       pPipelines->GetPointer(),
                                       pPipelines->GetLength(),
                                       pPipelines->GetHandlePointer(),
                                       createInfoCount,
                                       std::move(handle_info),
                                       &CommonObjectInfoTable::AddVkPipelineInfo);
    }
}

void VulkanReplayConsumerBase::OverrideUpdateDescriptorSets(
    PFN_vkUpdateDescriptorSets                          func,
    const VulkanDeviceInfo*                             device_info,
    uint32_t                                            descriptor_write_count,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* p_descriptor_writes,
    uint32_t                                            descriptor_copy_count,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  p_pescriptor_copies)
{
    const VkWriteDescriptorSet* in_pDescriptorWrites = p_descriptor_writes->GetPointer();
    const VkCopyDescriptorSet*  in_pDescriptorCopies = p_pescriptor_copies->GetPointer();

    func(
        device_info->handle, descriptor_write_count, in_pDescriptorWrites, descriptor_copy_count, in_pDescriptorCopies);

    // The information gathered here is only relevant to the dump resources feature
    if (options_.dumping_resources)
    {
        const auto* writes_meta = p_descriptor_writes->GetMetaStructPointer();
        for (uint32_t s = 0; s < descriptor_write_count; ++s)
        {
            VulkanDescriptorSetInfo* desc_set_info = GetObjectInfoTable().GetVkDescriptorSetInfo(writes_meta[s].dstSet);

            assert(desc_set_info != nullptr);

            for (uint32_t b = 0; b < in_pDescriptorWrites[s].descriptorCount; ++b)
            {
                const VkWriteDescriptorSet* write = writes_meta[s].decoded_value;
                assert(write != nullptr);

                const uint32_t binding = write->dstBinding;

                assert(desc_set_info->descriptors.find(binding) != desc_set_info->descriptors.end());
                assert(desc_set_info->descriptors[binding].desc_type == write->descriptorType);

                switch (write->descriptorType)
                {
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    {
                        assert(desc_set_info->descriptors[binding].image_info.size() >=
                               write->dstArrayElement + write->descriptorCount);

                        for (uint32_t i = 0; i < write->descriptorCount; ++i)
                        {
                            const uint32_t arr_idx = write->dstArrayElement + i;
                            desc_set_info->descriptors[binding].image_info[arr_idx].image_layout =
                                in_pDescriptorWrites[s].pImageInfo[b].imageLayout;
                            desc_set_info->descriptors[binding].image_info[arr_idx].image_view_info =
                                object_info_table_.GetVkImageViewInfo(
                                    writes_meta[s].pImageInfo->GetMetaStructPointer()[b].imageView);
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    {
                        assert(desc_set_info->descriptors[binding].buffer_info.size() >=
                               write->dstArrayElement + write->descriptorCount);

                        for (uint32_t i = 0; i < write->descriptorCount; ++i)
                        {
                            const uint32_t arr_idx = write->dstArrayElement + i;
                            desc_set_info->descriptors[binding].buffer_info[arr_idx].buffer_info =
                                object_info_table_.GetVkBufferInfo(
                                    writes_meta[s].pBufferInfo->GetMetaStructPointer()[b].buffer);
                            desc_set_info->descriptors[binding].buffer_info[arr_idx].offset =
                                in_pDescriptorWrites[s].pBufferInfo[b].offset;
                            desc_set_info->descriptors[binding].buffer_info[arr_idx].range =
                                in_pDescriptorWrites[s].pBufferInfo[b].range;
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    {
                        assert(desc_set_info->descriptors[binding].texel_buffer_view_info.size() >=
                               write->dstArrayElement + write->descriptorCount);

                        for (uint32_t i = 0; i < write->descriptorCount; ++i)
                        {
                            const uint32_t arr_idx = write->dstArrayElement + i;
                            desc_set_info->descriptors[binding].texel_buffer_view_info[arr_idx] =
                                object_info_table_.GetVkBufferViewInfo(writes_meta[s].pTexelBufferView.GetPointer()[b]);
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        const VkBaseOutStructure* pnext = reinterpret_cast<const VkBaseOutStructure*>(write->pNext);
                        while (pnext != nullptr)
                        {
                            if (pnext->sType == VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK)
                            {
                                const VkWriteDescriptorSetInlineUniformBlock* inline_uni_block_write =
                                    reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(pnext);

                                const uint32_t offset = write->dstArrayElement;
                                const uint32_t size   = write->descriptorCount;
                                assert(desc_set_info->descriptors[binding].inline_uniform_block.size() >=
                                       offset + size);
                                util::platform::MemoryCopy(
                                    desc_set_info->descriptors[binding].inline_uniform_block.data() + offset,
                                    size,
                                    inline_uni_block_write->pData,
                                    size);
                                break;
                            }
                            pnext = pnext->pNext;
                        }
                    }
                    break;

                    default:
                        break;
                }
            }
        }
    }
}

VkResult VulkanReplayConsumerBase::OverrideCreateGraphicsPipelines(
    PFN_vkCreateGraphicsPipelines                                     func,
    VkResult                                                          original_result,
    const VulkanDeviceInfo*                                           device_info,
    const VulkanPipelineCacheInfo*                                    pipeline_cache_info,
    uint32_t                                                          create_info_count,
    const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
    HandlePointerDecoder<VkPipeline>*                                 pPipelines)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfos != nullptr) && (pAllocator != nullptr) &&
           (pPipelines != nullptr) && !pPipelines->IsNull() && (pPipelines->GetHandlePointer() != nullptr));

    VkDevice                            in_device                 = device_info->handle;
    const VkGraphicsPipelineCreateInfo* in_p_create_infos         = pCreateInfos->GetPointer();
    const VkAllocationCallbacks*        in_p_allocation_callbacks = GetAllocationCallbacks(pAllocator);
    VkPipeline*                         out_pipelines             = pPipelines->GetHandlePointer();
    VkPipelineCache in_pipeline_cache = (pipeline_cache_info != nullptr) ? pipeline_cache_info->handle : VK_NULL_HANDLE;

    VkResult replay_result = func(
        in_device, in_pipeline_cache, create_info_count, in_p_create_infos, in_p_allocation_callbacks, out_pipelines);

    // Information is stored in the created PipelineInfos only when the dumping resources feature is in use
    if (replay_result == VK_SUCCESS && options_.dumping_resources)
    {
        const Decoded_VkGraphicsPipelineCreateInfo* create_info_meta = pCreateInfos->GetMetaStructPointer();

        for (uint32_t i = 0; i < create_info_count; ++i)
        {
            VulkanPipelineInfo* pipeline_info = reinterpret_cast<VulkanPipelineInfo*>(pPipelines->GetConsumerData(i));

            // Copy shader stage information
            const Decoded_VkPipelineShaderStageCreateInfo* stages_info_meta =
                create_info_meta[i].pStages->GetMetaStructPointer();
            const size_t stages_count = create_info_meta->pStages->GetLength();

            if (stages_info_meta != nullptr)
            {
                for (size_t s = 0; s < stages_count; ++s)
                {
                    VulkanShaderModuleInfo* module_info =
                        object_info_table_.GetVkShaderModuleInfo(stages_info_meta[s].module);
                    assert(module_info);
                    assert(pipeline_info);

                    pipeline_info->shaders.insert({ pCreateInfos->GetPointer()->pStages[s].stage, *module_info });
                }
            }

            // Copy vertex input state information
            if (in_p_create_infos != nullptr && in_p_create_infos[i].pVertexInputState)
            {
                // Vertex binding info
                for (uint32_t vb = 0; vb < in_p_create_infos[i].pVertexInputState->vertexBindingDescriptionCount; ++vb)
                {
                    VulkanPipelineInfo::InputBindingDescription info{
                        in_p_create_infos[i].pVertexInputState->pVertexBindingDescriptions[vb].stride,
                        in_p_create_infos[i].pVertexInputState->pVertexBindingDescriptions[vb].inputRate
                    };

                    uint32_t binding = in_p_create_infos[i].pVertexInputState->pVertexBindingDescriptions[vb].binding;
                    pipeline_info->vertex_input_binding_map.emplace(binding, info);
                }

                // Vertex attribute info
                for (uint32_t va = 0; va < in_p_create_infos[i].pVertexInputState->vertexAttributeDescriptionCount;
                     ++va)
                {
                    VulkanPipelineInfo::InputAttributeDescription info{
                        in_p_create_infos[i].pVertexInputState->pVertexAttributeDescriptions[va].binding,
                        in_p_create_infos[i].pVertexInputState->pVertexAttributeDescriptions[va].format,
                        in_p_create_infos[i].pVertexInputState->pVertexAttributeDescriptions[va].offset
                    };

                    uint32_t location =
                        in_p_create_infos[i].pVertexInputState->pVertexAttributeDescriptions[va].location;
                    pipeline_info->vertex_input_attribute_map.emplace(location, info);
                }
            }

            // Dynamic state
            if (in_p_create_infos != nullptr && in_p_create_infos[i].pDynamicState)
            {
                for (uint32_t ds = 0; ds < in_p_create_infos[i].pDynamicState->dynamicStateCount; ++ds)
                {
                    if (in_p_create_infos[i].pDynamicState->pDynamicStates[ds] == VK_DYNAMIC_STATE_VERTEX_INPUT_EXT)
                    {
                        pipeline_info->dynamic_vertex_input = true;
                    }
                    else if (in_p_create_infos[i].pDynamicState->pDynamicStates[ds] ==
                             VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT)
                    {
                        pipeline_info->dynamic_vertex_binding_stride = true;
                    }
                }
            }
        }
    }

    return replay_result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateComputePipelines(
    PFN_vkCreateComputePipelines                                     func,
    VkResult                                                         original_result,
    const VulkanDeviceInfo*                                          device_info,
    const VulkanPipelineCacheInfo*                                   pipeline_cache_info,
    uint32_t                                                         create_info_count,
    const StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkPipeline>*                                pPipelines)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfos != nullptr) && (pAllocator != nullptr) &&
           (pPipelines != nullptr) && !pPipelines->IsNull() && (pPipelines->GetHandlePointer() != nullptr));

    VkDevice                           in_device                 = device_info->handle;
    const VkComputePipelineCreateInfo* in_p_create_infos         = pCreateInfos->GetPointer();
    const VkAllocationCallbacks*       in_p_allocation_callbacks = GetAllocationCallbacks(pAllocator);
    VkPipeline*                        out_pipelines             = pPipelines->GetHandlePointer();
    VkPipelineCache in_pipeline_cache = (pipeline_cache_info != nullptr) ? pipeline_cache_info->handle : VK_NULL_HANDLE;

    VkResult replay_result = func(
        in_device, in_pipeline_cache, create_info_count, in_p_create_infos, in_p_allocation_callbacks, out_pipelines);

    if (replay_result == VK_SUCCESS)
    {
        const Decoded_VkComputePipelineCreateInfo* create_info_meta = pCreateInfos->GetMetaStructPointer();
        assert(create_info_meta);

        for (uint32_t i = 0; i < create_info_count; ++i)
        {
            assert(create_info_meta[i].stage);
            VulkanShaderModuleInfo* module_info =
                object_info_table_.GetVkShaderModuleInfo(create_info_meta[i].stage->module);
            assert(module_info);

            VulkanPipelineInfo* pipeline_info = reinterpret_cast<VulkanPipelineInfo*>(pPipelines->GetConsumerData(i));
            assert(pipeline_info);

            pipeline_info->shaders.insert({ VK_SHADER_STAGE_COMPUTE_BIT, *module_info });
        }
    }

    return replay_result;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
