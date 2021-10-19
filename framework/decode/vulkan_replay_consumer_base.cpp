/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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
#include "decode/vulkan_enum_util.h"
#include "decode/vulkan_feature_util.h"
#include "decode/vulkan_object_cleanup_util.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_util.h"
#include "util/file_path.h"
#include "util/hash.h"
#include "util/platform.h"

#include <cstdint>
#include <limits>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const size_t kMaxEventStatusRetries      = 16;
const size_t kMaxQueryPoolResultsRetries = 16;

const int32_t  kDefaultWindowPositionX = 0;
const int32_t  kDefaultWindowPositionY = 0;
const uint32_t kDefaultWindowWidth     = 320;
const uint32_t kDefaultWindowHeight    = 240;

const char kUnknownDeviceLabel[] = "<Unknown>";

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
    window_factory_(window_factory), options_(options), loading_trim_state_(false), have_imported_semaphores_(false),
    create_surface_count_(0), fps_info_(nullptr)
{
    assert(window_factory != nullptr);
    assert(options.create_resource_allocator != nullptr);

    if (!options.screenshot_ranges.empty())
    {
        InitializeScreenshotHandler();
    }
}

VulkanReplayConsumerBase::~VulkanReplayConsumerBase()
{
    if (options_.surface_index >= create_surface_count_)
    {
        GFXRECON_LOG_WARNING("Rendering was restricted to surface index %u, but a surface was never created for that "
                             "index; replay created %d surface(s)",
                             options_.surface_index,
                             create_surface_count_);
    }

    // Idle all devices before destroying other resources.
    WaitDevicesIdle();

    // Cleanup screenshot resources before destroying device.
    object_info_table_.VisitDeviceInfo([this](const DeviceInfo* info) {
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
        [this](const void* handle) { return GetDeviceTable(handle); });

    // Destroy any windows that were created for Vulkan surfaces.
    for (auto window : active_windows_)
    {
        window_factory_->Destroy(window);
    }

    if (loader_handle_ != nullptr)
    {
        graphics::ReleaseLoader(loader_handle_);
    }
}

void VulkanReplayConsumerBase::WaitDevicesIdle()
{
    object_info_table_.VisitDeviceInfo([this](const DeviceInfo* info) {
        assert(info != nullptr);
        VkDevice device = info->handle;

        auto device_table = GetDeviceTable(device);
        assert(device_table != nullptr);

        device_table->DeviceWaitIdle(device);
    });
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

void VulkanReplayConsumerBase::ProcessSetOpaqueAddressCommand(format::HandleId device_id,
                                                              format::HandleId object_id,
                                                              uint64_t         address)
{
    DeviceInfo* device_info = object_info_table_.GetDeviceInfo(device_id);

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
    DeviceInfo* device_info = object_info_table_.GetDeviceInfo(device_id);
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
    const DeviceInfo* device_info    = object_info_table_.GetDeviceInfo(device_id);
    SwapchainKHRInfo* swapchain_info = object_info_table_.GetSwapchainKHRInfo(swapchain_id);

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
                ProcessSetSwapchainImageStateQueueSubmit(device, swapchain_info, last_presented_image, image_info);
            }
            else
            {
                ProcessSetSwapchainImageStatePreAcquire(device, swapchain_info, image_info);
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
    VkDevice device, SwapchainKHRInfo* swapchain_info, const std::vector<format::SwapchainImageStateInfo>& image_info)
{
    auto table = GetDeviceTable(device);
    assert(table != nullptr);

    VkResult        result             = VK_SUCCESS;
    VkQueue         transition_queue   = VK_NULL_HANDLE;
    VkCommandPool   transition_pool    = VK_NULL_HANDLE;
    VkCommandBuffer transition_command = VK_NULL_HANDLE;
    VkSwapchainKHR  swapchain          = swapchain_info->handle;
    uint32_t        queue_family_index = swapchain_info->queue_family_index;

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
                                swapchain_info->acquired_indices[i] = image_index;

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
    SwapchainKHRInfo*                                   swapchain_info,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_info)
{
    auto table = GetDeviceTable(device);
    assert(table != nullptr);

    VkResult        result             = VK_SUCCESS;
    VkQueue         queue              = VK_NULL_HANDLE;
    VkCommandPool   pool               = VK_NULL_HANDLE;
    VkCommandBuffer command            = VK_NULL_HANDLE;
    VkFence         wait_fence         = VK_NULL_HANDLE;
    VkSwapchainKHR  swapchain          = swapchain_info->handle;
    uint32_t        queue_family_index = swapchain_info->queue_family_index;

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
                            swapchain_info->acquired_indices[i] = image_index;

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
        (call_id == format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR) ||
        (call_id == format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT) ||
        (call_id == format::ApiCallId::ApiCall_vkCmdSetCheckpointNV))
    {
        // The window system related handles are ignored by replay.
        // The checkpoint marker is ignored by replay.
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

void VulkanReplayConsumerBase::SetInstancePhysicalDeviceEntries(InstanceInfo*           instance_info,
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

void VulkanReplayConsumerBase::CheckReplayDeviceInfo(PhysicalDeviceInfo* physical_device_info)
{
    assert(physical_device_info != nullptr);

    if (physical_device_info->replay_device_info == nullptr)
    {
        // A physical device handle was obtained without calling vkEnumeratePhysicalDevices or
        // vkEnumeratePhysicalDeviceGroups, so the physical device initialization that would have been performed when
        // replaying those calls will be performed here.
        auto instance_info = object_info_table_.GetInstanceInfo(physical_device_info->parent_id);
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

void VulkanReplayConsumerBase::SetPhysicalDeviceInstanceInfo(InstanceInfo*       instance_info,
                                                             PhysicalDeviceInfo* physical_device_info,
                                                             VkPhysicalDevice    replay_device)
{
    assert((instance_info != nullptr) && (physical_device_info != nullptr));

    physical_device_info->parent                    = instance_info->handle;
    physical_device_info->parent_api_version        = instance_info->api_version;
    physical_device_info->parent_enabled_extensions = instance_info->enabled_extensions;
    physical_device_info->replay_device_info        = &instance_info->replay_device_info[replay_device];
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

    CheckReplayDeviceInfo(physical_device_info);
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

    CheckReplayDeviceInfo(physical_device_info);
    auto replay_device_info = physical_device_info->replay_device_info;
    assert(replay_device_info != nullptr);

    if (replay_device_info->memory_properties == nullptr)
    {
        replay_device_info->memory_properties = std::make_unique<VkPhysicalDeviceMemoryProperties>(*replay_properties);
    }
}

void VulkanReplayConsumerBase::SelectPhysicalDevice(PhysicalDeviceInfo* physical_device_info)
{
    assert((physical_device_info != nullptr) && (physical_device_info->parent_id != format::kNullHandleId));

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
    VkResult      result         = VK_SUCCESS;

    if (surface != nullptr)
    {
        replay_surface = surface->GetHandlePointer();
    }

    // For multi-surface captures, when replay is restricted to a specific surface, only create a surface for the
    // specified index.
    if ((options_.surface_index == -1) || (options_.surface_index == create_surface_count_))
    {
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
            auto surface_id   = surface->GetPointer();
            auto surface_info = reinterpret_cast<SurfaceKHRInfo*>(surface->GetConsumerData(0));
            assert((surface_id != nullptr) && (surface_info != nullptr));

            surface_info->window = window;
            active_windows_.insert(window);
        }
        else
        {
            window_factory_->Destroy(window);
        }
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping surface creation for surface index %d", create_surface_count_);
    }

    // Count the number of surfaces created for restricting replay to a specific surface.
    ++create_surface_count_;

    return result;
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

void VulkanReplayConsumerBase::SetSwapchainWindowSize(const Decoded_VkSwapchainCreateInfoKHR* swapchain_info)
{
    assert(swapchain_info != nullptr);

    const auto create_info = swapchain_info->decoded_value;
    if (create_info != nullptr)
    {
        const auto surface_info = object_info_table_.GetSurfaceKHRInfo(swapchain_info->surface);
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
            auto swapchain_info = object_info_table_.GetSwapchainKHRInfo(swapchain_ids[i]);
            if ((swapchain_info != nullptr) && (swapchain_info->device_info != nullptr))
            {
                auto     device_info = swapchain_info->device_info;
                uint32_t image_index = present_info->pImageIndices[i];

                auto instance_table = GetInstanceTable(device_info->parent);
                assert(instance_table != nullptr);

                // TODO: This should be stored in the DeviceInfo structure to avoid the need for frequent queries.
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

                screenshot_handler_->WriteImage(filename_prefix,
                                                device_info->handle,
                                                GetDeviceTable(device_info->handle),
                                                memory_properties,
                                                device_info->allocator.get(),
                                                swapchain_info->images[image_index],
                                                swapchain_info->format,
                                                swapchain_info->width,
                                                swapchain_info->height);
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
        // If VkDebugUtilsMessengerCreateInfoEXT or VkDebugReportCallbackCreateInfoEXT are in the pNext chain, update
        // the callback pointers.
        ProcessCreateInstanceDebugCallbackInfo(pCreateInfo->GetMetaStructPointer());

        if (replay_create_info->ppEnabledExtensionNames)
        {
            // Swap the surface extension supported by platform the replay is running on if different from trace
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

            PFN_vkEnumerateInstanceExtensionProperties instance_extension_proc =
                reinterpret_cast<PFN_vkEnumerateInstanceExtensionProperties>(
                    get_instance_proc_addr_(nullptr, "vkEnumerateInstanceExtensionProperties"));
            std::vector<VkExtensionProperties> properties;
            if (feature_util::GetInstanceExtensions(instance_extension_proc, &properties) == VK_SUCCESS)
            {
                if (options_.remove_unsupported_features)
                {
                    // Remove enabled extensions that are not available from the replay instance.
                    // Proc addresses that can't be used in layers so are not generated into shared dispatch table, but
                    // are needed in the replay application.
                    feature_util::RemoveUnsupportedExtensions(properties, &filtered_extensions);
                }
                else
                {
                    // Check that the requested extensions are present and print warnings if not.
                    for (auto extensionIter = filtered_extensions.begin(); extensionIter != filtered_extensions.end();
                         ++extensionIter)
                    {
                        if (!feature_util::IsSupportedExtension(properties, *extensionIter))
                        {
                            GFXRECON_LOG_WARNING("Extension %s, is not supported by the replay device.",
                                                 *extensionIter);
                        }
                    }
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Failed to get instance extensions. Cannot perform sanity checks or filters for "
                                     "extension availability.");
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
            instance_info->enabled_extensions.assign(modified_create_info.ppEnabledExtensionNames,
                                                     modified_create_info.ppEnabledExtensionNames +
                                                         modified_create_info.enabledExtensionCount);
        }
    }

    return result;
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
        assert(replay_create_info != nullptr);
        VkDeviceCreateInfo modified_create_info = (*replay_create_info);

        // Make copy so list can be modified without effecting original.
        std::vector<const char*> modified_extensions;
        if (replay_create_info->ppEnabledExtensionNames)
        {
            modified_extensions.insert(
                modified_extensions.begin(),
                replay_create_info->ppEnabledExtensionNames,
                std::next(replay_create_info->ppEnabledExtensionNames, replay_create_info->enabledExtensionCount));
        }

        // Enable extensions used for loading resources during initial state setup for trimmed files.
        std::vector<std::string> extensions;
        if (loading_trim_state_ && CheckTrimDeviceExtensions(physical_device, &extensions))
        {
            for (const auto& extension : extensions)
            {
                if (std::find(modified_extensions.begin(), modified_extensions.end(), extension) ==
                    modified_extensions.end())
                {
                    modified_extensions.push_back(extension.c_str());
                }
            }
        }

        if (options_.remove_unsupported_features && (physical_device != VK_NULL_HANDLE))
        {
            // Remove enabled extensions that are not available from the replay device.
            auto table = GetInstanceTable(physical_device);
            assert(table != nullptr);

            std::vector<VkExtensionProperties> properties;
            if (feature_util::GetDeviceExtensions(
                    physical_device, table->EnumerateDeviceExtensionProperties, &properties) == VK_SUCCESS)
            {
                feature_util::RemoveUnsupportedExtensions(properties, &modified_extensions);
            }

            // Remove enabled features that are not available from the replay device.
            feature_util::RemoveUnsupportedFeatures(physical_device,
                                                    table->GetPhysicalDeviceFeatures,
                                                    table->GetPhysicalDeviceFeatures2,
                                                    modified_create_info.pNext,
                                                    modified_create_info.pEnabledFeatures);
        }

        modified_create_info.enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
        modified_create_info.ppEnabledExtensionNames = modified_extensions.data();

        graphics::VulkanDeviceUtil                device_util;
        graphics::VulkanDevicePropertyFeatureInfo property_feature_info =
            device_util.EnableRequiredPhysicalDeviceFeatures(physical_device_info->parent_api_version,
                                                             GetInstanceTable(physical_device),
                                                             physical_device,
                                                             &modified_create_info);

        result = create_device_proc(
            physical_device, &modified_create_info, GetAllocationCallbacks(pAllocator), replay_device);

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

            std::vector<std::string> enabled_extensions(modified_create_info.ppEnabledExtensionNames,
                                                        modified_create_info.ppEnabledExtensionNames +
                                                            modified_create_info.enabledExtensionCount);
            InitializeResourceAllocator(physical_device_info, *replay_device, enabled_extensions, allocator);

            device_info->allocator = std::unique_ptr<VulkanResourceAllocator>(allocator);

            // Track state of physical device properties and features at device creation
            device_info->property_feature_info = property_feature_info;
        }

        // Restore modified property/feature create info values to the original application values
        device_util.RestoreModifiedPhysicalDeviceFeatures();
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
        assert(!pPhysicalDevices->IsNull());

        uint32_t                replay_device_count  = (*replay_device_count_ptr);
        uint32_t                capture_device_count = (*pPhysicalDeviceCount->GetPointer());
        const format::HandleId* capture_devices      = pPhysicalDevices->GetPointer();

        SetInstancePhysicalDeviceEntries(
            instance_info, capture_device_count, capture_devices, replay_device_count, replay_devices);

        for (uint32_t i = 0; i < replay_device_count; ++i)
        {
            auto physical_device_info = reinterpret_cast<PhysicalDeviceInfo*>(pPhysicalDevices->GetConsumerData(i));
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
                PhysicalDeviceInfo overflow_info;

                overflow_info.handle     = overflow_device;
                overflow_info.capture_id = capture_devices[i];
                overflow_info.parent_id  = instance_info->capture_id;
                SetPhysicalDeviceInstanceInfo(instance_info, &overflow_info, overflow_device);

                object_info_table_.AddPhysicalDeviceInfo(std::move(overflow_info));
            }
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideEnumeratePhysicalDeviceGroups(
    PFN_vkEnumeratePhysicalDeviceGroups                            func,
    VkResult                                                       original_result,
    InstanceInfo*                                                  instance_info,
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
                PhysicalDeviceInfo physical_device_info;

                physical_device_info.handle     = entry.second;
                physical_device_info.capture_id = entry.first;
                physical_device_info.parent_id  = instance_info->capture_id;
                SetPhysicalDeviceInstanceInfo(instance_info, &physical_device_info, entry.second);

                object_info_table_.AddPhysicalDeviceInfo(std::move(physical_device_info));
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
                PhysicalDeviceInfo overflow_info;

                overflow_info.handle     = overflow_device;
                overflow_info.capture_id = capture_devices[i];
                overflow_info.parent_id  = instance_info->capture_id;
                SetPhysicalDeviceInstanceInfo(instance_info, &overflow_info, overflow_device);

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

    VkResult             result               = VK_SUCCESS;
    VkDevice             device               = device_info->handle;
    uint32_t             modified_fence_count = fenceCount;
    const VkFence*       modified_fences      = nullptr;
    std::vector<VkFence> valid_fences;

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
            FenceInfo* fence_info = object_info_table_.GetFenceInfo(fence_handles[i]);
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
        result = func(device, modified_fence_count, modified_fences, waitAll, std::numeric_limits<uint64_t>::max());
    }
    else if (original_result == VK_TIMEOUT)
    {
        // Try to get a timeout result with a 0 timeout.
        result = func(device, modified_fence_count, modified_fences, waitAll, 0);
    }
    else
    {
        result = func(device, modified_fence_count, modified_fences, waitAll, timeout);
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

    // If you find this loop to be infinite consider adding a limit in the same way
    // it is done for GetEventStatus and GetQueryPoolResults.
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
    size_t      retries    = 0;

    do
    {
        result = func(device, query_pool, firstQuery, queryCount, dataSize, pData->GetOutputPointer(), stride, flags);
    } while ((((original_result == VK_SUCCESS) && (result == VK_NOT_READY)) ||
              ((original_result == VK_NOT_READY) && (result == VK_SUCCESS))) &&
             (++retries <= kMaxQueryPoolResultsRetries));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideQueueSubmit(PFN_vkQueueSubmit func,
                                                       VkResult          original_result,
                                                       const QueueInfo*  queue_info,
                                                       uint32_t          submitCount,
                                                       const StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                       const FenceInfo*                                  fence_info)
{
    assert((queue_info != nullptr) && (pSubmits != nullptr));

    VkResult            result       = VK_SUCCESS;
    const VkSubmitInfo* submit_infos = pSubmits->GetPointer();
    assert(submit_infos != nullptr);
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
        std::unordered_map<uint32_t, std::vector<const SemaphoreInfo*>> altered_submits;
        std::vector<const SemaphoreInfo*>                               removed_semaphores;

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

        if (altered_submits.empty())
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

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideQueueBindSparse(PFN_vkQueueBindSparse                                 func,
                                                  VkResult                                              original_result,
                                                  const QueueInfo*                                      queue_info,
                                                  uint32_t                                              bindInfoCount,
                                                  const StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
                                                  const FenceInfo*                                      fence_info)
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
        std::unordered_map<uint32_t, std::vector<const SemaphoreInfo*>> altered_submits;
        std::vector<const SemaphoreInfo*>                               removed_semaphores;

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

VkResult VulkanReplayConsumerBase::OverrideCreateDescriptorPool(
    PFN_vkCreateDescriptorPool                                      func,
    VkResult                                                        original_result,
    const DeviceInfo*                                               device_info,
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
        auto pool_info = reinterpret_cast<DescriptorPoolInfo*>(pDescriptorPool->GetConsumerData(0));
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
    const DeviceInfo*                                          device_info,
    DescriptorPoolInfo*                                        descriptor_pool_info,
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

        if ((original_result >= 0) && (result == VK_ERROR_OUT_OF_POOL_MEMORY))
        {
            // Handle case where replay runs out of descriptor pool memory when capture did not by creating a new
            // descriptor pool and attempting the allocation a second time.
            VkDescriptorPool new_pool  = VK_NULL_HANDLE;
            auto             meta_info = pAllocateInfo->GetMetaStructPointer();
            auto             pool_info = object_info_table_.GetDescriptorPoolInfo(meta_info->descriptorPool);

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
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateDescriptorSets call that failed during capture with error %s",
                          enumutil::GetResultValueString(original_result));
    }

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

        // Check if this allocation was captured with an opaque address
        bool                uses_address   = false;
        uint64_t            opaque_address = 0;
        VkBaseOutStructure* current_struct = reinterpret_cast<const VkBaseOutStructure*>(replay_allocate_info)->pNext;
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
            current_struct = current_struct->pNext;
        }

        if (uses_address)
        {
            // Insert VkMemoryOpaqueCaptureAddressAllocateInfo into front of pNext chain before allocating
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

    VkResult                              result = VK_SUCCESS;
    VulkanResourceAllocator::ResourceData allocator_data;
    auto                                  replay_buffer      = pBuffer->GetHandlePointer();
    auto                                  capture_id         = (*pBuffer->GetPointer());
    auto                                  replay_create_info = pCreateInfo->GetPointer();

    // Check for a buffer device address.
    bool                uses_address         = false;
    VkBufferCreateFlags address_create_flags = 0;
    VkBufferUsageFlags  address_usage_flags  = 0;
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
        size_t image_info_count             = 0;
        size_t buffer_info_count            = 0;
        size_t texel_buffer_view_count      = 0;
        size_t acceleration_structure_count = 0;

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

VkResult VulkanReplayConsumerBase::OverrideGetPipelineCacheData(PFN_vkGetPipelineCacheData func,
                                                                VkResult                   original_result,
                                                                const DeviceInfo*          device_info,
                                                                const PipelineCacheInfo*   pipeline_cache_info,
                                                                PointerDecoder<size_t>*    pDataSize,
                                                                PointerDecoder<uint8_t>*   pData)
{
    if (options_.omit_pipeline_cache_data)
    {
        return original_result;
    }
    else
    {
        return func(
            device_info->handle, pipeline_cache_info->handle, pDataSize->GetOutputPointer(), pData->GetOutputPointer());
    }
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

VkResult VulkanReplayConsumerBase::OverrideResetDescriptorPool(PFN_vkResetDescriptorPool  func,
                                                               VkResult                   original_result,
                                                               const DeviceInfo*          device_info,
                                                               DescriptorPoolInfo*        pool_info,
                                                               VkDescriptorPoolResetFlags flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pool_info != nullptr));

    // Descriptor sets allocated from the pool are implicitly freed and must be removed from the object info table.
    for (auto child_id : pool_info->child_ids)
    {
        object_info_table_.RemoveDescriptorSetInfo(child_id);
    }

    pool_info->child_ids.clear();

    return func(device_info->handle, pool_info->handle, flags);
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

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && !pCreateInfo->IsNull() && (pSwapchain != nullptr) &&
           !pSwapchain->IsNull() && (pSwapchain->GetHandlePointer() != nullptr));

    VkResult result             = VK_SUCCESS;
    auto     replay_create_info = pCreateInfo->GetPointer();
    auto     replay_swapchain   = pSwapchain->GetHandlePointer();
    auto     swapchain_info     = reinterpret_cast<SwapchainKHRInfo*>(pSwapchain->GetConsumerData(0));
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

        if (screenshot_handler_ == nullptr)
        {
            result =
                func(device_info->handle, replay_create_info, GetAllocationCallbacks(pAllocator), replay_swapchain);
        }
        else
        {
            // Screenshots are active, so ensure that swapchain images can be used as a transfer source.
            VkSwapchainCreateInfoKHR modified_create_info = (*replay_create_info);
            modified_create_info.imageUsage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
            result =
                func(device_info->handle, &modified_create_info, GetAllocationCallbacks(pAllocator), replay_swapchain);
        }
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

        swapchain_info->surface            = VK_NULL_HANDLE;
        swapchain_info->image_flags        = replay_create_info->flags;
        swapchain_info->image_array_layers = replay_create_info->imageArrayLayers;
        swapchain_info->image_usage        = replay_create_info->imageUsage;
        swapchain_info->image_sharing_mode = replay_create_info->imageSharingMode;
    }

    if ((result == VK_SUCCESS) && (replay_create_info != nullptr) && ((*replay_swapchain) != VK_NULL_HANDLE))
    {
        if ((replay_create_info->imageSharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (replay_create_info->queueFamilyIndexCount > 0) && (replay_create_info->pQueueFamilyIndices != nullptr))
        {
            swapchain_info->queue_family_index = replay_create_info->pQueueFamilyIndices[0];
        }
        else
        {
            swapchain_info->queue_family_index = 0;
        }

        swapchain_info->surface     = replay_create_info->surface;
        swapchain_info->device_info = device_info;
        swapchain_info->width       = replay_create_info->imageExtent.width;
        swapchain_info->height      = replay_create_info->imageExtent.height;
        swapchain_info->format      = replay_create_info->imageFormat;
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
    VkSurfaceKHR   surface   = VK_NULL_HANDLE;

    if (swapchain_info != nullptr)
    {
        swapchain = swapchain_info->handle;
        surface   = swapchain_info->surface;
    }

    // Delete backed images of dummy swapchain.
    if ((swapchain_info != nullptr) && (surface == VK_NULL_HANDLE))
    {
        auto allocator = device_info->allocator.get();
        assert(allocator != nullptr);

        for (const ImageInfo& image_info : swapchain_info->image_infos)
        {
            allocator->DestroyImageDirect(image_info.handle, nullptr, image_info.allocator_data);
            allocator->FreeMemoryDirect(image_info.memory, nullptr, image_info.memory_allocator_data);
        }
    }
    else
    {
        func(device, swapchain, GetAllocationCallbacks(pAllocator));
    }
}

VkResult VulkanReplayConsumerBase::OverrideGetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR    func,
                                                                 VkResult                       original_result,
                                                                 const DeviceInfo*              device_info,
                                                                 SwapchainKHRInfo*              swapchain_info,
                                                                 PointerDecoder<uint32_t>*      pSwapchainImageCount,
                                                                 HandlePointerDecoder<VkImage>* pSwapchainImages)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (swapchain_info != nullptr) && (pSwapchainImageCount != nullptr) &&
           (pSwapchainImages != nullptr));

    VkResult result             = original_result;
    auto     replay_image_count = pSwapchainImageCount->GetOutputPointer();
    auto     replay_images      = pSwapchainImages->GetHandlePointer();

    // Handle if swapchain was never created due to surface-index being skipped
    if (swapchain_info->surface == VK_NULL_HANDLE)
    {
        assert(!pSwapchainImageCount->IsNull());

        const uint32_t swapchain_image_count = *pSwapchainImageCount->GetPointer();
        if (replay_images == nullptr)
        {
            // Set the image count from data saved in trace file.
            (*replay_image_count) = swapchain_image_count;
        }
        else
        {
            // Create an image for the null swapchain.  Based on vkspec.html#swapchain-wsi-image-create-info.
            VkImageCreateInfo image_create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
            image_create_info.pNext                 = nullptr;
            image_create_info.flags                 = 0;
            image_create_info.imageType             = VK_IMAGE_TYPE_2D;
            image_create_info.format                = swapchain_info->format;
            image_create_info.extent                = { swapchain_info->width, swapchain_info->height, 1 };
            image_create_info.mipLevels             = 1;
            image_create_info.arrayLayers           = swapchain_info->image_array_layers;
            image_create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
            image_create_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
            image_create_info.usage                 = swapchain_info->image_usage;
            image_create_info.sharingMode           = swapchain_info->image_sharing_mode;
            image_create_info.queueFamilyIndexCount = 0;
            image_create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

            if ((swapchain_info->image_flags & VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR) ==
                VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR)
            {
                image_create_info.flags |= VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
            }

            GFXRECON_LOG_INFO("Creating %u images of %ux%u to back dummy swapchain (ID = %" PRIu64 ")",
                              swapchain_image_count,
                              image_create_info.extent.width,
                              image_create_info.extent.height,
                              swapchain_info->capture_id);

            for (uint32_t i = 0; i < swapchain_image_count; ++i)
            {
                VkImage*   replay_image = &(replay_images[i]);
                ImageInfo* image_info   = reinterpret_cast<ImageInfo*>(pSwapchainImages->GetConsumerData(i));
                assert(image_info != nullptr);

                result = CreateSwapchainImage(device_info, &image_create_info, replay_image, image_info);

                if ((result != VK_SUCCESS) || (replay_image == VK_NULL_HANDLE))
                {
                    GFXRECON_LOG_ERROR("Unable to create backing images for dummy swapchain (ID = %" PRIu64 ")",
                                       swapchain_info->capture_id);
                    break;
                }

                image_info->is_swapchain_image = true;

                // Create a copy of the image info to use for image cleanup when the swapchain is destroyed.
                swapchain_info->image_infos.push_back(*image_info);
            }
        }
    }
    else
    {
        result = func(device_info->handle, swapchain_info->handle, replay_image_count, replay_images);

        if ((result == VK_SUCCESS) && (replay_images != nullptr) && (replay_image_count != nullptr))
        {
            uint32_t count = (*replay_image_count);

            swapchain_info->acquired_indices.resize(count);

            for (uint32_t i = 0; i < count; ++i)
            {
                auto image_info = reinterpret_cast<ImageInfo*>(pSwapchainImages->GetConsumerData(i));
                assert(image_info != nullptr);

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
                                                               const DeviceInfo*         device_info,
                                                               SwapchainKHRInfo*         swapchain_info,
                                                               uint64_t                  timeout,
                                                               SemaphoreInfo*            semaphore_info,
                                                               FenceInfo*                fence_info,
                                                               PointerDecoder<uint32_t>* pImageIndex)
{
    assert(swapchain_info != nullptr);

    VkResult result = VK_SUCCESS;

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

            swapchain_info->acquired_indices[captured_index] = captured_index;

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

            result = func(device, swapchain, timeout, semaphore, fence, replay_index);

            // Track the index that was acquired on replay, which may be different than the captured index.
            swapchain_info->acquired_indices[captured_index] = (*replay_index);
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
    const DeviceInfo*                                              device_info,
    const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                                      pImageIndex)
{
    assert((pAcquireInfo != nullptr) && !pAcquireInfo->IsNull());

    VkResult          result            = VK_SUCCESS;
    auto              acquire_meta_info = pAcquireInfo->GetMetaStructPointer();
    SwapchainKHRInfo* swapchain_info    = object_info_table_.GetSwapchainKHRInfo(acquire_meta_info->swapchain);
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

            if (swapchain_info != nullptr)
            {
                swapchain_info->acquired_indices[captured_index] = captured_index;
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

            result = func(device, replay_acquire_info, replay_index);

            // Track the index that was acquired on replay, which may be different than the captured index.
            swapchain_info->acquired_indices[captured_index] = (*replay_index);
        }
    }
    else
    {
        // Track semphore and fence objects as shadow objects so that they can be ignored when they would have been
        // unsignaled (waited on).
        SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(acquire_meta_info->semaphore);
        FenceInfo*     fence_info     = object_info_table_.GetFenceInfo(acquire_meta_info->fence);

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
                                                  const QueueInfo*                                      queue_info,
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

    std::vector<VkSwapchainKHR>       valid_swapchains;
    std::vector<uint32_t>             modified_image_indices;
    std::vector<uint32_t>             modified_device_masks;
    std::vector<VkPresentRegionKHR>   modified_regions;
    std::vector<VkPresentTimeGOOGLE>  modified_times;
    std::vector<const SemaphoreInfo*> removed_semaphores;
    std::unordered_set<uint32_t>      removed_swapchain_indices;

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

            const auto swapchain_info = object_info_table_.GetSwapchainKHRInfo(swapchain_ids[i]);
            if ((swapchain_info != nullptr) && (swapchain_info->surface != VK_NULL_HANDLE))
            {
                valid_swapchains.push_back(swapchain_info->handle);
                modified_image_indices.push_back(swapchain_info->acquired_indices[present_info->pImageIndices[i]]);
            }
            else
            {
                removed_swapchain_indices.insert(i);
            }
        }

        // If a swapchain was removed, pNext stucts that reference the swapchain need to be modified as well.
        if (removed_swapchain_indices.empty() == false)
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
                                if (removed_swapchain_indices.find(i) == removed_swapchain_indices.end())
                                {
                                    modified_device_masks.push_back(pNext->pDeviceMasks[i]);
                                }
                            }

                            assert(valid_swapchains.size() == modified_device_masks.size());

                            modified_device_group_present_info.pNext = pNext->pNext;
                            modified_device_group_present_info.swapchainCount =
                                static_cast<uint32_t>(modified_device_masks.size());
                            modified_device_group_present_info.pDeviceMasks = modified_device_masks.data();
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
                                if (removed_swapchain_indices.find(i) == removed_swapchain_indices.end())
                                {
                                    modified_regions.push_back(pNext->pRegions[i]);
                                }
                            }

                            assert(valid_swapchains.size() == modified_regions.size());

                            modified_present_region_info.pNext = pNext->pNext;
                            modified_present_region_info.swapchainCount =
                                static_cast<uint32_t>(modified_regions.size());
                            modified_present_region_info.pRegions = modified_regions.data();
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
                                if (removed_swapchain_indices.find(i) == removed_swapchain_indices.end())
                                {
                                    modified_times.push_back(pNext->pTimes[i]);
                                }
                            }

                            assert(valid_swapchains.size() == modified_times.size());

                            modified_present_times_info.pNext          = pNext->pNext;
                            modified_present_times_info.swapchainCount = static_cast<uint32_t>(modified_times.size());
                            modified_present_times_info.pTimes         = modified_times.data();
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

        modified_present_info.swapchainCount = static_cast<uint32_t>(valid_swapchains.size());
        modified_present_info.pSwapchains    = valid_swapchains.data();
        modified_present_info.pImageIndices  = modified_image_indices.data();
    }
    else
    {
        // Need to match the last acquired image index from replay to avoid OUT_OF_DATE errors from present.
        modified_image_indices.insert(modified_image_indices.end(),
                                      present_info->pImageIndices,
                                      std::next(present_info->pImageIndices, present_info->swapchainCount));

        const auto swapchain_ids = present_info_data->pSwapchains.GetPointer();
        for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
        {
            assert(swapchain_ids != nullptr);

            const auto swapchain_info = object_info_table_.GetSwapchainKHRInfo(swapchain_ids[i]);
            if (swapchain_info != nullptr)
            {
                modified_image_indices[i] = swapchain_info->acquired_indices[present_info->pImageIndices[i]];
            }
        }

        modified_present_info.pImageIndices = modified_image_indices.data();
    }

    // Only attempt to find imported or shadow semaphores if we know at least one around.
    if ((!have_imported_semaphores_) && (shadow_semaphores_.empty()) && (modified_present_info.swapchainCount != 0))
    {
        result = func(queue_info->handle, &modified_present_info);
    }
    else if (modified_present_info.swapchainCount == 0)
    {
        // No need to progress farther if there is no valid swapchain to present.
        dispatched_command = false;

        // Used to mark shadow semaphores as signaled in case acquireNextImage signals were supposed to be waited on
        // here.
        GetShadowSemaphores(present_info_data->pWaitSemaphores, &removed_semaphores);
    }
    else
    {
        // Check for imported semaphores in the present info, creating a vector of imported semaphore info structures.
        if (present_info_data != nullptr)
        {
            GetImportedSemaphores(present_info_data->pWaitSemaphores, &removed_semaphores);
            GetShadowSemaphores(present_info_data->pWaitSemaphores, &removed_semaphores);
        }

        if (removed_semaphores.empty())
        {
            result = func(queue_info->handle, &modified_present_info);
        }
        else
        {
            std::vector<VkSemaphore> semaphore_memory;
            auto                     semaphore_iter = removed_semaphores.begin();

            for (uint32_t i = 0; i < modified_present_info.waitSemaphoreCount; ++i)
            {
                VkSemaphore semaphore = modified_present_info.pWaitSemaphores[i];

                if ((semaphore_iter == removed_semaphores.end()) || ((*semaphore_iter)->handle != semaphore))
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

            result = func(queue_info->handle, &modified_present_info);
        }
    }

    // If running with surface-index on, need to track forward progress of semaphore that have been submitted
    if (options_.surface_index != -1)
    {
        if (dispatched_command)
        {
            TrackSemaphoreForwardProgress(present_info_data->pWaitSemaphores, &removed_semaphores);
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
                    SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(semaphore_ids[i]);
                    if (semaphore_info)
                    {
                        semaphore_info->forward_progress = false;
                    }
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
    const DeviceInfo*                                               device_info,
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

        SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(info->semaphore);

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
    const DeviceInfo*                                            device_info,
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
    const DeviceInfo*                                                        device_info,
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

        SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(info->semaphore);

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
    const DeviceInfo*                                                     device_info,
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
                                                                    const PhysicalDeviceInfo*           physicalDevice,
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
    }

    if (window != nullptr)
    {
        window->DestroySurface(GetInstanceTable(instance), instance, surface);
        active_windows_.erase(window);
        window_factory_->Destroy(window);
    }
    else
    {
        func(instance, surface, GetAllocationCallbacks(pAllocator));
    }
}

VkResult VulkanReplayConsumerBase::OverrideCreateAccelerationStructureKHR(
    PFN_vkCreateAccelerationStructureKHR                                      func,
    VkResult                                                                  original_result,
    const DeviceInfo*                                                         device_info,
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
    const DeviceInfo*                                                      device_info,
    const DeferredOperationKHRInfo*                                        deferred_operation_info,
    const PipelineCacheInfo*                                               pipeline_cache_info,
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
        result = device_table->CreateRayTracingPipelinesKHR(device,
                                                            in_deferredOperation,
                                                            in_pipelineCache,
                                                            createInfoCount,
                                                            modified_create_infos.data(),
                                                            in_pAllocator,
                                                            out_pPipelines);
    }
    else
    {
        result = device_table->CreateRayTracingPipelinesKHR(device,
                                                            in_deferredOperation,
                                                            in_pipelineCache,
                                                            createInfoCount,
                                                            in_pCreateInfos,
                                                            in_pAllocator,
                                                            out_pPipelines);
    }

    return result;
}

VkDeviceAddress VulkanReplayConsumerBase::OverrideGetBufferDeviceAddress(
    PFN_vkGetBufferDeviceAddress                                   func,
    const DeviceInfo*                                              device_info,
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
    const DeviceInfo*                                                                device_info,
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
                                                                     VkResult                 original_result,
                                                                     const DeviceInfo*        device_info,
                                                                     const PipelineInfo*      pipeline_info,
                                                                     uint32_t                 firstGroup,
                                                                     uint32_t                 groupCount,
                                                                     size_t                   dataSize,
                                                                     PointerDecoder<uint8_t>* pData)
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

void VulkanReplayConsumerBase::MapDescriptorUpdateTemplateHandles(
    const DescriptorUpdateTemplateInfo* update_template_info, DescriptorUpdateTemplateDecoder* decoder)
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

    if (accel_struct_count > 0)
    {
        auto accel_struct_ids     = decoder->GetAccelerationStructureKHRHandleIdsPointer();
        auto accel_struct_handles = decoder->GetAccelerationStructureKHRPointer();

        for (size_t i = 0; i < accel_struct_count; ++i)
        {
            auto accel_struct_info = object_info_table_.GetAccelerationStructureKHRInfo(accel_struct_ids[i]);

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
                                                     std::vector<const SemaphoreInfo*>*       imported_semaphores)
{
    assert(imported_semaphores != nullptr);

    const format::HandleId* semaphore_ids = semaphore_data.GetPointer();
    if (semaphore_ids != nullptr)
    {
        size_t count = semaphore_data.GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            const SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(semaphore_ids[i]);
            if ((semaphore_info != nullptr) && semaphore_info->is_external)
            {
                imported_semaphores->push_back(semaphore_info);
            }
        }
    }
}

void VulkanReplayConsumerBase::GetShadowSemaphores(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                                                   std::vector<const SemaphoreInfo*>*       shadow_semaphores)
{
    assert(shadow_semaphores != nullptr);

    const format::HandleId* semaphore_ids = semaphore_data.GetPointer();
    if (semaphore_ids != nullptr)
    {
        size_t count = semaphore_data.GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(semaphore_ids[i]);
            if ((semaphore_info != nullptr) && (semaphore_info->shadow_signaled == true))
            {
                // If found, unsignal the semaphore to represent it being used.
                shadow_semaphores->push_back(semaphore_info);
                semaphore_info->shadow_signaled = false;
                shadow_semaphores_.erase(semaphore_info->handle);
            }
        }
    }
}

void VulkanReplayConsumerBase::TrackSemaphoreForwardProgress(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                                                             std::vector<const SemaphoreInfo*>* removed_semaphores)
{
    assert(removed_semaphores != nullptr);

    const format::HandleId* semaphore_ids = semaphore_data.GetPointer();
    if (semaphore_ids != nullptr)
    {
        size_t count = semaphore_data.GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(semaphore_ids[i]);
            if (semaphore_info != nullptr)
            {
                VkSemaphore semaphore = semaphore_info->handle;
                // Need to ignore if removed.
                bool removed = false;
                for (const SemaphoreInfo* remove_semaphore : *removed_semaphores)
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

void VulkanReplayConsumerBase::GetNonForwardProgress(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                                                     std::vector<const SemaphoreInfo*>* non_forward_progress_semaphores)
{
    assert(non_forward_progress_semaphores != nullptr);

    const format::HandleId* semaphore_ids = semaphore_data.GetPointer();
    if (semaphore_ids != nullptr)
    {
        size_t count = semaphore_data.GetLength();

        for (uint32_t i = 0; i < count; ++i)
        {
            const SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(semaphore_ids[i]);
            if ((semaphore_info != nullptr) && (semaphore_info->forward_progress == false))
            {
                non_forward_progress_semaphores->push_back(semaphore_info);
            }
        }
    }
}

VkResult VulkanReplayConsumerBase::CreateSwapchainImage(const DeviceInfo*        device_info,
                                                        const VkImageCreateInfo* image_create_info,
                                                        VkImage*                 image,
                                                        ImageInfo*               image_info)
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

        // TODO - Move this and VulkanResourceInitializer::GetMemoryTypeIndex to common place
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
