/*
 ** Copyright (c) 2024-2025 LunarG, Inc.
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

#include "vulkan_capture_common.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/hardware_buffer.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void CommonWriteCreateHardwareBufferCmd(format::ThreadId                                    thread_id,
                                        format::HandleId                                    device_id,
                                        format::HandleId                                    memory_id,
                                        AHardwareBuffer*                                    hardware_buffer,
                                        const std::vector<format::HardwareBufferPlaneInfo>& plane_info,
                                        VulkanCaptureManager*                               vulkan_capture_manager,
                                        VulkanStateWriter*                                  vulkan_state_writer)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    if (vulkan_capture_manager && !vulkan_capture_manager->IsCaptureModeWrite())
    {
        return;
    }
    assert(hardware_buffer != nullptr);

    format::CreateHardwareBufferCommandHeader create_buffer_cmd;

    create_buffer_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    create_buffer_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(create_buffer_cmd);
    create_buffer_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
        format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kCreateHardwareBufferCommand);
    create_buffer_cmd.thread_id = thread_id;
    create_buffer_cmd.device_id = device_id;
    create_buffer_cmd.memory_id = memory_id;
    create_buffer_cmd.buffer_id = reinterpret_cast<uint64_t>(hardware_buffer);

    // Get AHB description data.
    AHardwareBuffer_Desc ahb_desc = {};
    AHardwareBuffer_describe(hardware_buffer, &ahb_desc);

    create_buffer_cmd.format = ahb_desc.format;
    create_buffer_cmd.width  = ahb_desc.width;
    create_buffer_cmd.height = ahb_desc.height;
    create_buffer_cmd.stride = ahb_desc.stride;
    create_buffer_cmd.usage  = ahb_desc.usage;
    create_buffer_cmd.layers = ahb_desc.layers;

    size_t planes_size = 0;

    if (plane_info.empty())
    {
        create_buffer_cmd.planes = 0;
    }
    else
    {
        create_buffer_cmd.planes = static_cast<uint32_t>(plane_info.size());
        // Update size of packet with compressed or uncompressed data size.
        planes_size = sizeof(plane_info[0]) * plane_info.size();
        create_buffer_cmd.meta_header.block_header.size += planes_size;
    }

    if (vulkan_capture_manager)
    {
        if (planes_size > 0)
        {
            vulkan_capture_manager->CombineAndWriteToFile(
                { { &create_buffer_cmd, sizeof(create_buffer_cmd) }, { plane_info.data(), planes_size } });
        }
        else
        {
            vulkan_capture_manager->WriteToFile(&create_buffer_cmd, sizeof(create_buffer_cmd));
        }
    }
    else if (vulkan_state_writer)
    {
        vulkan_state_writer->OutputStreamWrite(&create_buffer_cmd, sizeof(create_buffer_cmd));

        if (planes_size > 0)
        {
            vulkan_state_writer->OutputStreamWrite(plane_info.data(), planes_size);
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);
    GFXRECON_UNREFERENCED_PARAMETER(memory_id);
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
    GFXRECON_UNREFERENCED_PARAMETER(plane_info);
    GFXRECON_UNREFERENCED_PARAMETER(vulkan_capture_manager);
    GFXRECON_UNREFERENCED_PARAMETER(vulkan_state_writer);

    GFXRECON_LOG_ERROR("Skipping create AHardwareBuffer command write for unsupported platform");
#endif
}

void CommonWriteFillMemoryCmd(format::HandleId      memory_id,
                              uint64_t              size,
                              const void*           data,
                              VulkanCaptureManager* vulkan_capture_manager,
                              VulkanStateWriter*    vulkan_state_writer)
{
    if (vulkan_capture_manager)
    {
        vulkan_capture_manager->WriteFillMemoryCmd(memory_id, 0u, size, data);
    }
    else
    {
        vulkan_state_writer->WriteFillMemoryCmd(memory_id, 0u, size, data);
    }
}

// Wrap vkuFormatRequiresYcbcrConversion so that we handle VK_FORMAT_UNDEFINED as a YCbCr format which applies for AHB
// external formats
inline bool ExternalFormatRequiresYcbcrConversion(VkFormat format)
{
    if (format == VK_FORMAT_UNDEFINED)
    {
        return true;
    }
    else
    {
        return vkuFormatRequiresYcbcrConversion(format);
    }
}

void CommonProcessHardwareBuffer(format::ThreadId                      thread_id,
                                 const vulkan_wrappers::DeviceWrapper* device_wrapper,
                                 format::HandleId                      memory_id,
                                 AHardwareBuffer*                      hardware_buffer,
                                 size_t                                allocation_size,
                                 VulkanCaptureManager*                 vulkan_capture_manager,
                                 VulkanStateWriter*                    vulkan_state_writer)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    assert(hardware_buffer != nullptr);

    // If this is the first device memory object to reference the hardware buffer, write a buffer creation
    // command to the capture file and setup memory tracking.

    std::vector<format::HardwareBufferPlaneInfo> plane_info;

    AHardwareBuffer_Desc desc;
    AHardwareBuffer_describe(hardware_buffer, &desc);

    if ((desc.usage & AHARDWAREBUFFER_USAGE_CPU_READ_MASK) != 0)
    {
        void* data   = nullptr;
        int   result = -1;

        // The multi-plane functions are declared for API 26, but are only available to link with API 29.  So, this
        // could be turned into a run-time check dependent on dlsym returning a valid pointer for
        // AHardwareBuffer_lockPlanes.
#if __ANDROID_API__ >= 29
        AHardwareBuffer_Planes ahb_planes;
        result =
            AHardwareBuffer_lockPlanes(hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, nullptr, &ahb_planes);
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
                plane_info.emplace_back(std::move(ahb_plane_info));
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("AHardwareBuffer_lockPlanes failed: AHardwareBuffer_lock will be used instead");
        }
#endif

        // Write CreateHardwareBufferCmd with or without the AHB payload
        CommonWriteCreateHardwareBufferCmd(
            thread_id, 0u, memory_id, hardware_buffer, plane_info, vulkan_capture_manager, vulkan_state_writer);

        // If AHardwareBuffer_lockPlanes failed (or is not available) try AHardwareBuffer_lock
        if (result != 0)
        {
            result = AHardwareBuffer_lock(hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, nullptr, &data);
        }

        if (result == 0 && data != nullptr)
        {
            CommonWriteFillMemoryCmd(memory_id, allocation_size, data, vulkan_capture_manager, vulkan_state_writer);

            if (vulkan_capture_manager)
            {
                // Track the memory with the PageGuardManager
                const auto tracking_mode = vulkan_capture_manager->GetMemoryTrackingMode();
                if ((tracking_mode == CaptureSettings::MemoryTrackingMode::kPageGuard ||
                     tracking_mode == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
                    vulkan_capture_manager->GetPageGuardTrackAhbMemory())
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, allocation_size);

                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    manager->AddTrackedMemory(memory_id,
                                              data,
                                              0,
                                              static_cast<size_t>(allocation_size),
                                              util::PageGuardManager::kNullShadowHandle,
                                              false,  // No shadow memory for the imported AHB memory.
                                              false); // Write watch is not supported for this case.
                }
            }

            result = AHardwareBuffer_unlock(hardware_buffer, nullptr);
            if (result != 0)
            {
                GFXRECON_LOG_ERROR("AHardwareBuffer_unlock failed");
            }
        }
        else
        {
            GFXRECON_LOG_ERROR(
                "AHardwareBuffer_lock failed: hardware buffer data will be omitted from the capture file");

            // Dump zeros for AHB payload.
            std::vector<uint8_t> zeros(allocation_size, 0);
            CommonWriteFillMemoryCmd(
                memory_id, zeros.size(), zeros.data(), vulkan_capture_manager, vulkan_state_writer);
        }
    }
    else
    {
        // The AHB is not CPU-readable, copy the data into a host visible buffer on the GPU
        format::HandleId                     device_id               = device_wrapper->handle_id;
        VkDevice                             device                  = device_wrapper->handle;
        auto                                 physical_device_wrapper = device_wrapper->physical_device;
        auto                                 physical_device         = physical_device_wrapper->handle;
        const graphics::VulkanInstanceTable* instance_table    = vulkan_wrappers::GetInstanceTable(physical_device);
        auto                                 device_table      = vulkan_wrappers::GetDeviceTable(device);
        auto                                 memory_properties = &physical_device_wrapper->memory_properties;

        uint32_t device_queue_index = -1;
        uint32_t queue_family_index = -1;

        uint32_t queue_family_count;
        instance_table->GetPhysicalDeviceQueueFamilyProperties(physical_device, &queue_family_count, nullptr);
        std::vector<VkQueueFamilyProperties> queue_family_properties(queue_family_count);
        instance_table->GetPhysicalDeviceQueueFamilyProperties(
            physical_device, &queue_family_count, queue_family_properties.data());

        for (size_t i = 0; i < device_wrapper->queue_family_indices.size(); ++i)
        {
            uint32_t qfi = device_wrapper->queue_family_indices[i];
            if ((queue_family_properties[qfi].queueFlags & VK_QUEUE_COMPUTE_BIT) != 0)
            {
                device_queue_index = i;
                queue_family_index = qfi;
                break;
            }
        }

        if (device_queue_index == -1 || queue_family_index == -1)
            return;

        auto             queue_wrapper = device_wrapper->child_queues[device_queue_index];
        format::HandleId queue_id      = queue_wrapper->handle_id;

        // Write CreateHardwareBufferCmd without the AHB payload
        CommonWriteCreateHardwareBufferCmd(
            thread_id, device_id, memory_id, hardware_buffer, plane_info, vulkan_capture_manager, vulkan_state_writer);

        VkResult vk_result = VK_SUCCESS;

        // Query the AHB size
        VkAndroidHardwareBufferFormatPropertiesANDROID format_properties;
        format_properties.sType = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID;
        format_properties.pNext = nullptr;

        VkAndroidHardwareBufferPropertiesANDROID properties;
        properties.sType = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID;
        properties.pNext = &format_properties;

        if (vk_result == VK_SUCCESS)
            vk_result = device_table->GetAndroidHardwareBufferPropertiesANDROID(device, hardware_buffer, &properties);

        const size_t ahb_size = properties.allocationSize;
        GFXRECON_ASSERT(ahb_size > 0);

        VkExternalFormatANDROID external_format = {};
        external_format.sType                   = VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID;
        external_format.pNext                   = nullptr;
        if (format_properties.format == VK_FORMAT_UNDEFINED)
        {
            external_format.externalFormat = format_properties.externalFormat;
        }

        VkExternalMemoryImageCreateInfo external_memory_image_create_info;
        external_memory_image_create_info.sType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO;
        external_memory_image_create_info.pNext = &external_format;
        external_memory_image_create_info.handleTypes =
            VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID;

        VkImageUsageFlags image_usage = 0;
        if (desc.usage & AHARDWAREBUFFER_USAGE_GPU_SAMPLED_IMAGE)
        {
            image_usage |= VK_IMAGE_USAGE_SAMPLED_BIT;
        }
        if (desc.usage & AHARDWAREBUFFER_USAGE_GPU_COLOR_OUTPUT)
        {
            image_usage |= VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        }
        // If the pNext chain includes a VkExternalFormatANDROID structure whose externalFormat member is not 0, usage
        // must not include any usages except VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
        // or VK_IMAGE_USAGE_SAMPLED_BIT.
        if (format_properties.format != VK_FORMAT_UNDEFINED)
        {
            image_usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        }

        VkImageCreateInfo image_create_info;
        image_create_info.sType                 = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        image_create_info.pNext                 = &external_memory_image_create_info;
        image_create_info.flags                 = 0u;
        image_create_info.imageType             = VK_IMAGE_TYPE_2D;
        image_create_info.format                = format_properties.format;
        image_create_info.extent                = { desc.width, desc.height, 1u };
        image_create_info.mipLevels             = 1u;
        image_create_info.arrayLayers           = 1u;
        image_create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
        image_create_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
        image_create_info.usage                 = image_usage;
        image_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
        image_create_info.queueFamilyIndexCount = 0u;
        image_create_info.pQueueFamilyIndices   = nullptr;
        image_create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

        VkImage ahb_image;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateImage(device, &image_create_info, nullptr, &ahb_image);

        VkImportAndroidHardwareBufferInfoANDROID import_ahb_info;
        import_ahb_info.sType  = VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID;
        import_ahb_info.pNext  = nullptr;
        import_ahb_info.buffer = hardware_buffer;

        VkMemoryDedicatedAllocateInfo memory_dedicated_allocate_info;
        memory_dedicated_allocate_info.sType  = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO;
        memory_dedicated_allocate_info.pNext  = &import_ahb_info;
        memory_dedicated_allocate_info.image  = ahb_image;
        memory_dedicated_allocate_info.buffer = VK_NULL_HANDLE;

        VkMemoryAllocateInfo memory_allocate_info;
        memory_allocate_info.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        memory_allocate_info.pNext          = &memory_dedicated_allocate_info;
        memory_allocate_info.allocationSize = properties.allocationSize;

        uint32_t memory_index = memory_properties->memoryTypeCount;
        for (uint32_t i = 0; i < memory_properties->memoryTypeCount; ++i)
        {
            if ((properties.memoryTypeBits & (1 << i)) &&
                (memory_properties->memoryTypes[i].propertyFlags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) > 0)
            {
                memory_index = i;
                break;
            }
        }
        GFXRECON_ASSERT(memory_index < memory_properties->memoryTypeCount);
        memory_allocate_info.memoryTypeIndex = memory_index;

        VkDeviceMemory image_memory;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->AllocateMemory(device, &memory_allocate_info, nullptr, &image_memory);

        if (vk_result == VK_SUCCESS)
            vk_result = device_table->BindImageMemory(device, ahb_image, image_memory, 0);

        VkSamplerYcbcrConversionCreateInfo sampler_ycbcr_conversion_create_info;
        sampler_ycbcr_conversion_create_info.sType         = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO;
        sampler_ycbcr_conversion_create_info.pNext         = &external_format;
        sampler_ycbcr_conversion_create_info.format        = format_properties.format;
        sampler_ycbcr_conversion_create_info.ycbcrModel    = format_properties.suggestedYcbcrModel;
        sampler_ycbcr_conversion_create_info.ycbcrRange    = format_properties.suggestedYcbcrRange;
        sampler_ycbcr_conversion_create_info.components    = format_properties.samplerYcbcrConversionComponents;
        sampler_ycbcr_conversion_create_info.xChromaOffset = format_properties.suggestedXChromaOffset;
        sampler_ycbcr_conversion_create_info.yChromaOffset = format_properties.suggestedYChromaOffset;
        sampler_ycbcr_conversion_create_info.chromaFilter  = VK_FILTER_LINEAR;
        sampler_ycbcr_conversion_create_info.forceExplicitReconstruction = VK_FALSE;

        VkSamplerYcbcrConversion ycbcr_conversion;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateSamplerYcbcrConversion(
                device, &sampler_ycbcr_conversion_create_info, nullptr, &ycbcr_conversion);

        VkSamplerYcbcrConversionInfo sampler_ycbcr_conversion_info = {};
        sampler_ycbcr_conversion_info.sType                        = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO;
        sampler_ycbcr_conversion_info.pNext                        = nullptr;
        sampler_ycbcr_conversion_info.conversion                   = ycbcr_conversion;

        auto ahb_image_aspect_mask = graphics::GetFormatAspects(format_properties.format);

        VkImageViewCreateInfo image_view_create_info;
        image_view_create_info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        image_view_create_info.pNext =
            ExternalFormatRequiresYcbcrConversion(format_properties.format) ? &sampler_ycbcr_conversion_info : nullptr;
        image_view_create_info.flags                           = 0u;
        image_view_create_info.image                           = ahb_image;
        image_view_create_info.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
        image_view_create_info.format                          = format_properties.format;
        image_view_create_info.components.r                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        image_view_create_info.components.g                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        image_view_create_info.components.b                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        image_view_create_info.components.a                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        image_view_create_info.subresourceRange.aspectMask     = ahb_image_aspect_mask;
        image_view_create_info.subresourceRange.baseMipLevel   = 0u;
        image_view_create_info.subresourceRange.levelCount     = 1u;
        image_view_create_info.subresourceRange.baseArrayLayer = 0u;
        image_view_create_info.subresourceRange.layerCount     = 1u;

        VkImageView image_view;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateImageView(device, &image_view_create_info, nullptr, &image_view);

        VkSamplerCreateInfo sampler_create_info;
        sampler_create_info.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
        sampler_create_info.pNext =
            ExternalFormatRequiresYcbcrConversion(format_properties.format) ? &sampler_ycbcr_conversion_info : nullptr;
        sampler_create_info.flags                   = 0u;
        sampler_create_info.magFilter               = VK_FILTER_LINEAR;
        sampler_create_info.minFilter               = VK_FILTER_LINEAR;
        sampler_create_info.mipmapMode              = VK_SAMPLER_MIPMAP_MODE_NEAREST;
        sampler_create_info.addressModeU            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
        sampler_create_info.addressModeV            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
        sampler_create_info.addressModeW            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
        sampler_create_info.mipLodBias              = 0.0f;
        sampler_create_info.anisotropyEnable        = VK_FALSE;
        sampler_create_info.maxAnisotropy           = 1.0f;
        sampler_create_info.compareEnable           = VK_FALSE;
        sampler_create_info.compareOp               = VK_COMPARE_OP_NEVER;
        sampler_create_info.minLod                  = 0.0f;
        sampler_create_info.maxLod                  = 0.0f;
        sampler_create_info.borderColor             = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK;
        sampler_create_info.unnormalizedCoordinates = VK_FALSE;
        VkSampler sampler;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateSampler(device, &sampler_create_info, nullptr, &sampler);

        VkImageUsageFlags host_image_usage  = VK_IMAGE_USAGE_STORAGE_BIT;
        VkFormat          host_image_format = format_properties.format;
        if (format_properties.format == VK_FORMAT_UNDEFINED)
        {
            host_image_format = VK_FORMAT_R8G8B8A8_UNORM;
        }
        else
        {
            host_image_usage |= VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        }

        VkImageCreateInfo host_image_create_info{ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO, nullptr };
        host_image_create_info.flags                 = 0u;
        host_image_create_info.imageType             = VK_IMAGE_TYPE_2D;
        host_image_create_info.format                = host_image_format;
        host_image_create_info.extent                = { desc.width, desc.height, 1u };
        host_image_create_info.mipLevels             = 1u;
        host_image_create_info.arrayLayers           = 1u;
        host_image_create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
        host_image_create_info.tiling                = VK_IMAGE_TILING_LINEAR;
        host_image_create_info.usage                 = host_image_usage;
        host_image_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
        host_image_create_info.queueFamilyIndexCount = 0u;
        host_image_create_info.pQueueFamilyIndices   = nullptr;
        host_image_create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

        VkImage host_image = VK_NULL_HANDLE;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateImage(device, &host_image_create_info, nullptr, &host_image);

        VkMemoryRequirements host_readable_memory_requirements;
        device_table->GetImageMemoryRequirements(device, host_image, &host_readable_memory_requirements);

        VkMemoryAllocateInfo host_readable_allocate_info;
        host_readable_allocate_info.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        host_readable_allocate_info.pNext          = nullptr;
        host_readable_allocate_info.allocationSize = host_readable_memory_requirements.size;

        memory_index = memory_properties->memoryTypeCount;
        for (uint32_t i = 0; i < memory_properties->memoryTypeCount; ++i)
        {
            if ((host_readable_memory_requirements.memoryTypeBits & (1 << i)) &&
                (memory_properties->memoryTypes[i].propertyFlags &
                 (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)) ==
                    (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT))
            {
                memory_index = i;
                break;
            }
        }
        GFXRECON_ASSERT(memory_index < memory_properties->memoryTypeCount);
        host_readable_allocate_info.memoryTypeIndex = memory_index;

        VkDeviceMemory host_image_memory = VK_NULL_HANDLE;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->AllocateMemory(device, &host_readable_allocate_info, nullptr, &host_image_memory);

        if (vk_result == VK_SUCCESS)
            vk_result = device_table->BindImageMemory(device, host_image, host_image_memory, 0);

        auto host_image_aspect_mask = graphics::GetFormatAspects(host_image_format);

        VkImageViewCreateInfo host_image_view_create_info{ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO, nullptr };
        host_image_view_create_info.flags                           = 0u;
        host_image_view_create_info.image                           = host_image;
        host_image_view_create_info.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
        host_image_view_create_info.format                          = host_image_create_info.format;
        host_image_view_create_info.components.r                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        host_image_view_create_info.components.g                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        host_image_view_create_info.components.b                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        host_image_view_create_info.components.a                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        host_image_view_create_info.subresourceRange.aspectMask     = host_image_aspect_mask;
        host_image_view_create_info.subresourceRange.baseMipLevel   = 0u;
        host_image_view_create_info.subresourceRange.levelCount     = 1u;
        host_image_view_create_info.subresourceRange.baseArrayLayer = 0u;
        host_image_view_create_info.subresourceRange.layerCount     = 1u;

        VkImageView host_image_view;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateImageView(device, &host_image_view_create_info, nullptr, &host_image_view);

        VkCommandPoolCreateInfo command_pool_create_info;
        command_pool_create_info.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        command_pool_create_info.pNext            = nullptr;
        command_pool_create_info.flags            = 0u;
        command_pool_create_info.queueFamilyIndex = queue_family_index;

        VkCommandPool command_pool;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateCommandPool(device, &command_pool_create_info, nullptr, &command_pool);

        VkCommandBufferAllocateInfo command_buffer_allocate_info;
        command_buffer_allocate_info.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        command_buffer_allocate_info.pNext              = nullptr;
        command_buffer_allocate_info.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        command_buffer_allocate_info.commandPool        = command_pool;
        command_buffer_allocate_info.commandBufferCount = 1u;

        VkCommandBuffer command_buffer;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->AllocateCommandBuffers(device, &command_buffer_allocate_info, &command_buffer);

        VkCommandBufferBeginInfo command_buffer_begin_info;
        command_buffer_begin_info.sType            = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        command_buffer_begin_info.pNext            = nullptr;
        command_buffer_begin_info.flags            = 0u;
        command_buffer_begin_info.pInheritanceInfo = nullptr;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->BeginCommandBuffer(command_buffer, &command_buffer_begin_info);

        VkShaderModule        compute_shader_module = VK_NULL_HANDLE;
        VkDescriptorSetLayout descriptor_set_layout = VK_NULL_HANDLE;
        VkPipelineLayout      pipeline_layout       = VK_NULL_HANDLE;
        VkPipeline            compute_pipeline      = VK_NULL_HANDLE;
        VkDescriptorPool      descriptor_pool       = VK_NULL_HANDLE;
        VkDescriptorSet       descriptor_set        = VK_NULL_HANDLE;

        if (format_properties.format != VK_FORMAT_UNDEFINED)
        {
            VkImageMemoryBarrier barriers[2]            = {};
            barriers[0].sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            barriers[0].pNext                           = nullptr;
            barriers[0].srcAccessMask                   = 0u;
            barriers[0].dstAccessMask                   = VK_ACCESS_MEMORY_READ_BIT;
            barriers[0].oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
            barriers[0].newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
            barriers[0].srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
            barriers[0].dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
            barriers[0].image                           = ahb_image;
            barriers[0].subresourceRange.aspectMask     = ahb_image_aspect_mask;
            barriers[0].subresourceRange.baseMipLevel   = 0u;
            barriers[0].subresourceRange.levelCount     = 1u;
            barriers[0].subresourceRange.baseArrayLayer = 0u;
            barriers[0].subresourceRange.layerCount     = 1u;
            barriers[1].sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            barriers[1].pNext                           = nullptr;
            barriers[1].srcAccessMask                   = 0u;
            barriers[1].dstAccessMask                   = VK_ACCESS_MEMORY_READ_BIT;
            barriers[1].oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
            barriers[1].newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            barriers[1].srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
            barriers[1].dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
            barriers[1].image                           = host_image;
            barriers[1].subresourceRange.aspectMask     = host_image_aspect_mask;
            barriers[1].subresourceRange.baseMipLevel   = 0u;
            barriers[1].subresourceRange.levelCount     = 1u;
            barriers[1].subresourceRange.baseArrayLayer = 0u;
            barriers[1].subresourceRange.layerCount     = 1u;

            device_table->CmdPipelineBarrier(command_buffer,
                                             VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             0,
                                             0,
                                             nullptr,
                                             0,
                                             nullptr,
                                             2,
                                             barriers);

            VkImageCopy copy_region               = {};
            copy_region.dstSubresource.layerCount = 1;
            copy_region.dstSubresource.aspectMask = host_image_aspect_mask;
            copy_region.extent                    = { desc.width, desc.height, 1 };
            copy_region.srcSubresource.layerCount = 1;
            copy_region.srcSubresource.aspectMask = ahb_image_aspect_mask;

            device_table->CmdCopyImage(command_buffer,
                                       ahb_image,
                                       VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                       host_image,
                                       VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                       1,
                                       &copy_region);
        }
        else
        {
            // #version 450
            //
            // layout(local_size_x = 16, local_size_y = 16, local_size_z = 1) in;
            //
            // layout(set = 0, binding = 0) uniform sampler2D ahb_image;
            // layout(set = 0, binding = 1, rgba8) uniform writeonly image2D host_image;
            //
            // void main() {
            //     int id_x = int(gl_GlobalInvocationID.x);
            //     int id_y = int(gl_GlobalInvocationID.y);
            //
            //     ivec2 image_size = textureSize(ahb_image, 0);
            //
            //     if (id_x >= image_size.x || id_y >= image_size.y) {
            //         return;
            //     }
            //
            //     vec2 coords = vec2(
            //         float(id_x) / float(image_size.x),
            //         float(id_y) / float(image_size.y)
            //     );
            //
            //     vec4 color = texture(ahb_image, coords);
            //     imageStore(host_image, ivec2(id_x, id_y), color);
            // }

            std::vector<uint32_t> shader = {
                0x07230203, 0x00010000, 0x0008000b, 0x00000054, 0x00000000, 0x00020011, 0x00000001, 0x00020011,
                0x00000032, 0x0006000b, 0x00000001, 0x4c534c47, 0x6474732e, 0x3035342e, 0x00000000, 0x0003000e,
                0x00000000, 0x00000001, 0x0006000f, 0x00000005, 0x00000004, 0x6e69616d, 0x00000000, 0x0000000c,
                0x00060010, 0x00000004, 0x00000011, 0x00000010, 0x00000010, 0x00000001, 0x00030003, 0x00000002,
                0x000001c2, 0x00040005, 0x00000004, 0x6e69616d, 0x00000000, 0x00040005, 0x00000008, 0x785f6469,
                0x00000000, 0x00080005, 0x0000000c, 0x475f6c67, 0x61626f6c, 0x766e496c, 0x7461636f, 0x496e6f69,
                0x00000044, 0x00040005, 0x00000012, 0x795f6469, 0x00000000, 0x00050005, 0x00000019, 0x67616d69,
                0x69735f65, 0x0000657a, 0x00050005, 0x0000001e, 0x5f626861, 0x67616d69, 0x00000065, 0x00040005,
                0x00000035, 0x726f6f63, 0x00007364, 0x00040005, 0x00000045, 0x6f6c6f63, 0x00000072, 0x00050005,
                0x0000004c, 0x74736f68, 0x616d695f, 0x00006567, 0x00040047, 0x0000000c, 0x0000000b, 0x0000001c,
                0x00040047, 0x0000001e, 0x00000021, 0x00000000, 0x00040047, 0x0000001e, 0x00000022, 0x00000000,
                0x00030047, 0x0000004c, 0x00000019, 0x00040047, 0x0000004c, 0x00000021, 0x00000001, 0x00040047,
                0x0000004c, 0x00000022, 0x00000000, 0x00040047, 0x00000053, 0x0000000b, 0x00000019, 0x00020013,
                0x00000002, 0x00030021, 0x00000003, 0x00000002, 0x00040015, 0x00000006, 0x00000020, 0x00000001,
                0x00040020, 0x00000007, 0x00000007, 0x00000006, 0x00040015, 0x00000009, 0x00000020, 0x00000000,
                0x00040017, 0x0000000a, 0x00000009, 0x00000003, 0x00040020, 0x0000000b, 0x00000001, 0x0000000a,
                0x0004003b, 0x0000000b, 0x0000000c, 0x00000001, 0x0004002b, 0x00000009, 0x0000000d, 0x00000000,
                0x00040020, 0x0000000e, 0x00000001, 0x00000009, 0x0004002b, 0x00000009, 0x00000013, 0x00000001,
                0x00040017, 0x00000017, 0x00000006, 0x00000002, 0x00040020, 0x00000018, 0x00000007, 0x00000017,
                0x00030016, 0x0000001a, 0x00000020, 0x00090019, 0x0000001b, 0x0000001a, 0x00000001, 0x00000000,
                0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x0003001b, 0x0000001c, 0x0000001b, 0x00040020,
                0x0000001d, 0x00000000, 0x0000001c, 0x0004003b, 0x0000001d, 0x0000001e, 0x00000000, 0x0004002b,
                0x00000006, 0x00000020, 0x00000000, 0x00020014, 0x00000023, 0x00040017, 0x00000033, 0x0000001a,
                0x00000002, 0x00040020, 0x00000034, 0x00000007, 0x00000033, 0x00040017, 0x00000043, 0x0000001a,
                0x00000004, 0x00040020, 0x00000044, 0x00000007, 0x00000043, 0x0004002b, 0x0000001a, 0x00000048,
                0x00000000, 0x00090019, 0x0000004a, 0x0000001a, 0x00000001, 0x00000000, 0x00000000, 0x00000000,
                0x00000002, 0x00000004, 0x00040020, 0x0000004b, 0x00000000, 0x0000004a, 0x0004003b, 0x0000004b,
                0x0000004c, 0x00000000, 0x0004002b, 0x00000009, 0x00000052, 0x00000010, 0x0006002c, 0x0000000a,
                0x00000053, 0x00000052, 0x00000052, 0x00000013, 0x00050036, 0x00000002, 0x00000004, 0x00000000,
                0x00000003, 0x000200f8, 0x00000005, 0x0004003b, 0x00000007, 0x00000008, 0x00000007, 0x0004003b,
                0x00000007, 0x00000012, 0x00000007, 0x0004003b, 0x00000018, 0x00000019, 0x00000007, 0x0004003b,
                0x00000034, 0x00000035, 0x00000007, 0x0004003b, 0x00000044, 0x00000045, 0x00000007, 0x00050041,
                0x0000000e, 0x0000000f, 0x0000000c, 0x0000000d, 0x0004003d, 0x00000009, 0x00000010, 0x0000000f,
                0x0004007c, 0x00000006, 0x00000011, 0x00000010, 0x0003003e, 0x00000008, 0x00000011, 0x00050041,
                0x0000000e, 0x00000014, 0x0000000c, 0x00000013, 0x0004003d, 0x00000009, 0x00000015, 0x00000014,
                0x0004007c, 0x00000006, 0x00000016, 0x00000015, 0x0003003e, 0x00000012, 0x00000016, 0x0004003d,
                0x0000001c, 0x0000001f, 0x0000001e, 0x00040064, 0x0000001b, 0x00000021, 0x0000001f, 0x00050067,
                0x00000017, 0x00000022, 0x00000021, 0x00000020, 0x0003003e, 0x00000019, 0x00000022, 0x0004003d,
                0x00000006, 0x00000024, 0x00000008, 0x00050041, 0x00000007, 0x00000025, 0x00000019, 0x0000000d,
                0x0004003d, 0x00000006, 0x00000026, 0x00000025, 0x000500af, 0x00000023, 0x00000027, 0x00000024,
                0x00000026, 0x000400a8, 0x00000023, 0x00000028, 0x00000027, 0x000300f7, 0x0000002a, 0x00000000,
                0x000400fa, 0x00000028, 0x00000029, 0x0000002a, 0x000200f8, 0x00000029, 0x0004003d, 0x00000006,
                0x0000002b, 0x00000012, 0x00050041, 0x00000007, 0x0000002c, 0x00000019, 0x00000013, 0x0004003d,
                0x00000006, 0x0000002d, 0x0000002c, 0x000500af, 0x00000023, 0x0000002e, 0x0000002b, 0x0000002d,
                0x000200f9, 0x0000002a, 0x000200f8, 0x0000002a, 0x000700f5, 0x00000023, 0x0000002f, 0x00000027,
                0x00000005, 0x0000002e, 0x00000029, 0x000300f7, 0x00000031, 0x00000000, 0x000400fa, 0x0000002f,
                0x00000030, 0x00000031, 0x000200f8, 0x00000030, 0x000100fd, 0x000200f8, 0x00000031, 0x0004003d,
                0x00000006, 0x00000036, 0x00000008, 0x0004006f, 0x0000001a, 0x00000037, 0x00000036, 0x00050041,
                0x00000007, 0x00000038, 0x00000019, 0x0000000d, 0x0004003d, 0x00000006, 0x00000039, 0x00000038,
                0x0004006f, 0x0000001a, 0x0000003a, 0x00000039, 0x00050088, 0x0000001a, 0x0000003b, 0x00000037,
                0x0000003a, 0x0004003d, 0x00000006, 0x0000003c, 0x00000012, 0x0004006f, 0x0000001a, 0x0000003d,
                0x0000003c, 0x00050041, 0x00000007, 0x0000003e, 0x00000019, 0x00000013, 0x0004003d, 0x00000006,
                0x0000003f, 0x0000003e, 0x0004006f, 0x0000001a, 0x00000040, 0x0000003f, 0x00050088, 0x0000001a,
                0x00000041, 0x0000003d, 0x00000040, 0x00050050, 0x00000033, 0x00000042, 0x0000003b, 0x00000041,
                0x0003003e, 0x00000035, 0x00000042, 0x0004003d, 0x0000001c, 0x00000046, 0x0000001e, 0x0004003d,
                0x00000033, 0x00000047, 0x00000035, 0x00070058, 0x00000043, 0x00000049, 0x00000046, 0x00000047,
                0x00000002, 0x00000048, 0x0003003e, 0x00000045, 0x00000049, 0x0004003d, 0x0000004a, 0x0000004d,
                0x0000004c, 0x0004003d, 0x00000006, 0x0000004e, 0x00000008, 0x0004003d, 0x00000006, 0x0000004f,
                0x00000012, 0x00050050, 0x00000017, 0x00000050, 0x0000004e, 0x0000004f, 0x0004003d, 0x00000043,
                0x00000051, 0x00000045, 0x00040063, 0x0000004d, 0x00000050, 0x00000051, 0x000100fd, 0x00010038,
            };

            VkShaderModuleCreateInfo shader_module_create_info;
            shader_module_create_info.sType    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
            shader_module_create_info.pNext    = nullptr;
            shader_module_create_info.flags    = 0u;
            shader_module_create_info.codeSize = shader.size() * sizeof(uint32_t);
            shader_module_create_info.pCode    = shader.data();
            if (vk_result == VK_SUCCESS)
                vk_result = device_table->CreateShaderModule(
                    device, &shader_module_create_info, nullptr, &compute_shader_module);

            VkPipelineShaderStageCreateInfo shader_stage_create_info;
            shader_stage_create_info.sType               = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            shader_stage_create_info.pNext               = nullptr;
            shader_stage_create_info.flags               = 0u;
            shader_stage_create_info.stage               = VK_SHADER_STAGE_COMPUTE_BIT;
            shader_stage_create_info.module              = compute_shader_module;
            shader_stage_create_info.pName               = "main";
            shader_stage_create_info.pSpecializationInfo = nullptr;

            VkDescriptorSetLayoutBinding bindings[2];
            bindings[0].binding            = 0u;
            bindings[0].descriptorType     = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            bindings[0].descriptorCount    = 1u;
            bindings[0].stageFlags         = VK_SHADER_STAGE_COMPUTE_BIT;
            bindings[0].pImmutableSamplers = &sampler;
            bindings[1].binding            = 1u;
            bindings[1].descriptorType     = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
            bindings[1].descriptorCount    = 1u;
            bindings[1].stageFlags         = VK_SHADER_STAGE_COMPUTE_BIT;
            bindings[1].pImmutableSamplers = nullptr;

            VkDescriptorSetLayoutCreateInfo descriptor_set_layout_create_info;
            descriptor_set_layout_create_info.sType        = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
            descriptor_set_layout_create_info.pNext        = nullptr;
            descriptor_set_layout_create_info.flags        = 0u;
            descriptor_set_layout_create_info.bindingCount = 2u;
            descriptor_set_layout_create_info.pBindings    = bindings;

            if (vk_result == VK_SUCCESS)
                vk_result = device_table->CreateDescriptorSetLayout(
                    device, &descriptor_set_layout_create_info, nullptr, &descriptor_set_layout);

            VkPipelineLayoutCreateInfo pipeline_layout_create_info;
            pipeline_layout_create_info.sType                  = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
            pipeline_layout_create_info.pNext                  = nullptr;
            pipeline_layout_create_info.flags                  = 0u;
            pipeline_layout_create_info.setLayoutCount         = 1u;
            pipeline_layout_create_info.pSetLayouts            = &descriptor_set_layout;
            pipeline_layout_create_info.pushConstantRangeCount = 0u;
            pipeline_layout_create_info.pPushConstantRanges    = nullptr;

            if (vk_result == VK_SUCCESS)
                vk_result =
                    device_table->CreatePipelineLayout(device, &pipeline_layout_create_info, nullptr, &pipeline_layout);

            VkComputePipelineCreateInfo compute_pipeline_create_info;
            compute_pipeline_create_info.sType              = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
            compute_pipeline_create_info.pNext              = nullptr;
            compute_pipeline_create_info.flags              = 0u;
            compute_pipeline_create_info.stage              = shader_stage_create_info;
            compute_pipeline_create_info.layout             = pipeline_layout;
            compute_pipeline_create_info.basePipelineHandle = VK_NULL_HANDLE;
            compute_pipeline_create_info.basePipelineIndex  = -1;

            device_table->CreateComputePipelines(
                device, VK_NULL_HANDLE, 1u, &compute_pipeline_create_info, nullptr, &compute_pipeline);

            VkDescriptorPoolSize pool_sizes[2];
            pool_sizes[0].type            = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            pool_sizes[0].descriptorCount = 1u;
            pool_sizes[1].type            = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
            pool_sizes[1].descriptorCount = 1u;

            VkDescriptorPoolCreateInfo descriptor_pool_create_info;
            descriptor_pool_create_info.sType         = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
            descriptor_pool_create_info.pNext         = nullptr;
            descriptor_pool_create_info.flags         = 0u;
            descriptor_pool_create_info.maxSets       = 1u;
            descriptor_pool_create_info.poolSizeCount = 2u;
            descriptor_pool_create_info.pPoolSizes    = pool_sizes;

            if (vk_result == VK_SUCCESS)
                vk_result =
                    device_table->CreateDescriptorPool(device, &descriptor_pool_create_info, nullptr, &descriptor_pool);

            VkDescriptorSetAllocateInfo descriptor_set_allocate_info;
            descriptor_set_allocate_info.sType              = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
            descriptor_set_allocate_info.pNext              = nullptr;
            descriptor_set_allocate_info.descriptorPool     = descriptor_pool;
            descriptor_set_allocate_info.descriptorSetCount = 1u;
            descriptor_set_allocate_info.pSetLayouts        = &descriptor_set_layout;

            if (vk_result == VK_SUCCESS)
                vk_result =
                    device_table->AllocateDescriptorSets(device, &descriptor_set_allocate_info, &descriptor_set);

            VkDescriptorImageInfo image_info = {};
            image_info.sampler               = sampler;
            image_info.imageView             = image_view;
            image_info.imageLayout           = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;

            VkDescriptorImageInfo host_image_info = {};
            host_image_info.imageView             = host_image_view;
            host_image_info.imageLayout           = VK_IMAGE_LAYOUT_GENERAL;

            VkWriteDescriptorSet descriptor_writes[2] = {};
            descriptor_writes[0].sType                = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
            descriptor_writes[0].dstSet               = descriptor_set;
            descriptor_writes[0].dstBinding           = 0u;
            descriptor_writes[0].dstArrayElement      = 0u;
            descriptor_writes[0].descriptorCount      = 1u;
            descriptor_writes[0].descriptorType       = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            descriptor_writes[0].pImageInfo           = &image_info;
            descriptor_writes[1].sType                = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
            descriptor_writes[1].dstSet               = descriptor_set;
            descriptor_writes[1].dstBinding           = 1u;
            descriptor_writes[1].dstArrayElement      = 0u;
            descriptor_writes[1].descriptorCount      = 1u;
            descriptor_writes[1].descriptorType       = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
            descriptor_writes[1].pImageInfo           = &host_image_info;

            device_table->UpdateDescriptorSets(device, 2u, descriptor_writes, 0u, nullptr);

            if (vk_result == VK_SUCCESS)
            {
                VkImageMemoryBarrier barriers[2]            = {};
                barriers[0].sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
                barriers[0].srcAccessMask                   = 0u;
                barriers[0].dstAccessMask                   = VK_ACCESS_SHADER_READ_BIT;
                barriers[0].oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
                barriers[0].newLayout                       = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                barriers[0].srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                barriers[0].dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                barriers[0].image                           = ahb_image;
                barriers[0].subresourceRange.aspectMask     = ahb_image_aspect_mask;
                barriers[0].subresourceRange.baseMipLevel   = 0u;
                barriers[0].subresourceRange.levelCount     = 1u;
                barriers[0].subresourceRange.baseArrayLayer = 0u;
                barriers[0].subresourceRange.layerCount     = 1u;
                barriers[1].sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
                barriers[1].srcAccessMask                   = 0u;
                barriers[1].dstAccessMask                   = VK_ACCESS_SHADER_WRITE_BIT;
                barriers[1].oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
                barriers[1].newLayout                       = VK_IMAGE_LAYOUT_GENERAL;
                barriers[1].srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                barriers[1].dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                barriers[1].image                           = host_image;
                barriers[1].subresourceRange.aspectMask     = host_image_aspect_mask;
                barriers[1].subresourceRange.baseMipLevel   = 0u;
                barriers[1].subresourceRange.levelCount     = 1u;
                barriers[1].subresourceRange.baseArrayLayer = 0u;
                barriers[1].subresourceRange.layerCount     = 1u;

                device_table->CmdPipelineBarrier(command_buffer,
                                                 VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                 VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                                 0,
                                                 0,
                                                 nullptr,
                                                 0,
                                                 nullptr,
                                                 2,
                                                 barriers);

                device_table->CmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, compute_pipeline);
                device_table->CmdBindDescriptorSets(
                    command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_layout, 0, 1, &descriptor_set, 0, nullptr);
                device_table->CmdDispatch(command_buffer, (desc.width + 15) / 16, (desc.height + 15) / 16, 1u);
            }
        }

        device_table->EndCommandBuffer(command_buffer);

        VkSubmitInfo submit_info;
        submit_info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submit_info.pNext                = nullptr;
        submit_info.waitSemaphoreCount   = 0u;
        submit_info.pWaitSemaphores      = nullptr;
        submit_info.pWaitDstStageMask    = nullptr;
        submit_info.commandBufferCount   = 1u;
        submit_info.pCommandBuffers      = &command_buffer;
        submit_info.signalSemaphoreCount = 0u;
        submit_info.pSignalSemaphores    = nullptr;

        VkFenceCreateInfo fence_create_info;
        fence_create_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fence_create_info.pNext = nullptr;
        fence_create_info.flags = 0u;

        VkFence fence;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateFence(device, &fence_create_info, nullptr, &fence);

        auto queue = device_wrapper->child_queues[device_queue_index]->handle;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->QueueSubmit(queue, 1, &submit_info, fence);
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->WaitForFences(device, 1u, &fence, VK_TRUE, UINT64_MAX);

        void*  data;
        size_t data_size = host_readable_memory_requirements.size;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->MapMemory(device, host_image_memory, 0u, data_size, 0u, &data);

        if (vk_result == VK_SUCCESS)
        {
            CommonWriteFillMemoryCmd(memory_id, data_size, data, vulkan_capture_manager, vulkan_state_writer);
        }

        device_table->DestroyFence(device, fence, nullptr);
        device_table->DestroyCommandPool(device, command_pool, nullptr);
        device_table->DestroyDescriptorPool(device, descriptor_pool, nullptr);
        device_table->DestroyPipeline(device, compute_pipeline, nullptr);
        device_table->DestroyDescriptorSetLayout(device, descriptor_set_layout, nullptr);
        device_table->DestroyPipelineLayout(device, pipeline_layout, nullptr);
        device_table->DestroyShaderModule(device, compute_shader_module, nullptr);
        device_table->FreeMemory(device, host_image_memory, nullptr);
        device_table->FreeMemory(device, image_memory, nullptr);
        device_table->DestroyImage(device, ahb_image, nullptr);
        device_table->DestroyImage(device, host_image, nullptr);

        if (vk_result != VK_SUCCESS)
            GFXRECON_LOG_ERROR("Failed to copy data from AHardwareBuffer that is not cpu readable");
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);
    GFXRECON_UNREFERENCED_PARAMETER(memory_id);
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
    GFXRECON_UNREFERENCED_PARAMETER(allocation_size);
    GFXRECON_UNREFERENCED_PARAMETER(vulkan_capture_manager);
    GFXRECON_UNREFERENCED_PARAMETER(vulkan_state_writer);
#endif
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
