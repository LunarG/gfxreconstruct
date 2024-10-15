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

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/hardware_buffer.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

static void CommonWriteCreateHardwareBufferCmd(format::ThreadId                                    thread_id,
                                               format::HandleId                                    device_id,
                                               format::HandleId                                    queue_id,
                                               format::HandleId                                    memory_id,
                                               AHardwareBuffer*                                    hardware_buffer,
                                               const std::vector<format::HardwareBufferPlaneInfo>& plane_info,
                                               VulkanCaptureManager* vulkan_capture_manager,
                                               VulkanStateWriter*    vulkan_state_writer)
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
    create_buffer_cmd.queue_id  = queue_id;
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

static void CommonWriteFillMemoryCmd(format::HandleId      memory_id,
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
            thread_id, 0u, 0u, memory_id, hardware_buffer, plane_info, vulkan_capture_manager, vulkan_state_writer);

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
        format::HandleId           device_id               = device_wrapper->handle_id;
        VkDevice                   device                  = device_wrapper->handle;
        auto                       physical_device_wrapper = device_wrapper->physical_device;
        auto                       physical_device         = physical_device_wrapper->handle;
        const VulkanInstanceTable* instance_table          = vulkan_wrappers::GetInstanceTable(physical_device);
        auto                       device_table            = vulkan_wrappers::GetDeviceTable(device);
        auto                       memory_properties       = &physical_device_wrapper->memory_properties;

        uint32_t deviceQueueIndex = -1;
        uint32_t queueFamilyIndex = -1;

        uint32_t queueFamilyCount;
        instance_table->GetPhysicalDeviceQueueFamilyProperties(physical_device, &queueFamilyCount, nullptr);
        std::vector<VkQueueFamilyProperties> queueFamilyProperties(queueFamilyCount);
        instance_table->GetPhysicalDeviceQueueFamilyProperties(
            physical_device, &queueFamilyCount, queueFamilyProperties.data());

        for (size_t i = 0; i < device_wrapper->queue_family_indices.size(); ++i)
        {
            uint32_t qfi = device_wrapper->queue_family_indices[i];
            if ((queueFamilyProperties[qfi].queueFlags & VK_QUEUE_COMPUTE_BIT) != 0)
            {
                deviceQueueIndex = i;
                queueFamilyIndex = qfi;
                break;
            }
        }

        if (deviceQueueIndex == -1 || queueFamilyIndex == -1)
            return;

        auto             queue_wrapper = device_wrapper->child_queues[deviceQueueIndex];
        format::HandleId queue_id      = queue_wrapper->handle_id;

        // Write CreateHardwareBufferCmd without the AHB payload
        CommonWriteCreateHardwareBufferCmd(thread_id,
                                           device_id,
                                           queue_id,
                                           memory_id,
                                           hardware_buffer,
                                           plane_info,
                                           vulkan_capture_manager,
                                           vulkan_state_writer);

        VkResult vk_result = VK_SUCCESS;

        // Query the AHB size
        VkAndroidHardwareBufferFormatPropertiesANDROID formatProperties;
        formatProperties.sType = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID;
        formatProperties.pNext = nullptr;

        VkAndroidHardwareBufferPropertiesANDROID properties;
        properties.sType = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID;
        properties.pNext = &formatProperties;

        if (vk_result == VK_SUCCESS)
            vk_result = device_table->GetAndroidHardwareBufferPropertiesANDROID(device, hardware_buffer, &properties);

        const size_t ahb_size = properties.allocationSize;
        assert(ahb_size);

        VkExternalMemoryBufferCreateInfo externalMemoryBufferCreateInfo;
        externalMemoryBufferCreateInfo.sType       = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO;
        externalMemoryBufferCreateInfo.pNext       = nullptr;
        externalMemoryBufferCreateInfo.handleTypes = VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID;

        VkBufferCreateInfo bufferCreateInfo;
        bufferCreateInfo.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        bufferCreateInfo.pNext                 = &externalMemoryBufferCreateInfo;
        bufferCreateInfo.flags                 = 0u;
        bufferCreateInfo.size                  = ahb_size;
        bufferCreateInfo.usage                 = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
        bufferCreateInfo.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
        bufferCreateInfo.queueFamilyIndexCount = 0u;
        bufferCreateInfo.pQueueFamilyIndices   = nullptr;

        VkBuffer ahbDataBuffer;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateBuffer(device, &bufferCreateInfo, nullptr, &ahbDataBuffer);

        VkMemoryRequirements memoryRequirements;
        device_table->GetBufferMemoryRequirements(device, ahbDataBuffer, &memoryRequirements);

        VkImportAndroidHardwareBufferInfoANDROID importAHBInfo;
        importAHBInfo.sType  = VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID;
        importAHBInfo.pNext  = nullptr;
        importAHBInfo.buffer = hardware_buffer;

        VkMemoryAllocateInfo memoryAllocateInfo;
        memoryAllocateInfo.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        memoryAllocateInfo.pNext          = &importAHBInfo;
        memoryAllocateInfo.allocationSize = memoryRequirements.size;

        uint32_t memoryIndex = memory_properties->memoryTypeCount;
        for (uint32_t i = 0; i < memory_properties->memoryTypeCount; ++i)
        {
            if ((memoryRequirements.memoryTypeBits & (1 << i)) &&
                (memory_properties->memoryTypes[i].propertyFlags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) > 0)
            {
                memoryIndex = i;
                break;
            }
        }
        assert(memoryIndex < memory_properties->memoryTypeCount);
        memoryAllocateInfo.memoryTypeIndex = memoryIndex;

        VkDeviceMemory bufferMemory;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->AllocateMemory(device, &memoryAllocateInfo, nullptr, &bufferMemory);

        if (vk_result == VK_SUCCESS)
            vk_result = device_table->BindBufferMemory(device, ahbDataBuffer, bufferMemory, 0);

        VkBufferCreateInfo hostBufferInfo;
        hostBufferInfo.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        hostBufferInfo.pNext                 = nullptr;
        hostBufferInfo.flags                 = 0u;
        hostBufferInfo.size                  = ahb_size;
        hostBufferInfo.usage                 = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        hostBufferInfo.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
        hostBufferInfo.queueFamilyIndexCount = 0u;
        hostBufferInfo.pQueueFamilyIndices   = nullptr;

        VkBuffer hostBuffer;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateBuffer(device, &hostBufferInfo, nullptr, &hostBuffer);

        VkMemoryRequirements hostReabableMemeryRequirements;
        device_table->GetBufferMemoryRequirements(device, hostBuffer, &hostReabableMemeryRequirements);

        VkMemoryAllocateInfo hostReadableAllocateInfo;
        hostReadableAllocateInfo.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        hostReadableAllocateInfo.pNext          = nullptr;
        hostReadableAllocateInfo.allocationSize = hostReabableMemeryRequirements.size;

        memoryIndex = memory_properties->memoryTypeCount;
        for (uint32_t i = 0; i < memory_properties->memoryTypeCount; ++i)
        {
            if ((hostReabableMemeryRequirements.memoryTypeBits & (1 << i)) &&
                (memory_properties->memoryTypes[i].propertyFlags &
                 (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)) ==
                    (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT))
            {
                memoryIndex = i;
                break;
            }
        }
        assert(memoryIndex < memory_properties->memoryTypeCount);
        hostReadableAllocateInfo.memoryTypeIndex = memoryIndex;

        VkDeviceMemory hostBufferMemory;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->AllocateMemory(device, &hostReadableAllocateInfo, nullptr, &hostBufferMemory);

        if (vk_result == VK_SUCCESS)
            vk_result = device_table->BindBufferMemory(device, hostBuffer, hostBufferMemory, 0);

        // #version 450
        //
        // layout(constant_id = 0) const uint rowLength = 1;
        // layout(constant_id = 1) const uint totalSize = 1;
        //
        // layout(local_size_x = 32, local_size_y = 32) in;
        //
        // layout(set = 0, binding = 0, std430) buffer InputBuffer {
        //     uint in_data[];
        // };
        //
        // layout(set = 0, binding = 1, std430) buffer OutputBuffer {
        //     uint out_data[];
        // };
        //
        // void main() {
        // 	 uint i = gl_GlobalInvocationID.y * rowLength + gl_GlobalInvocationID.x;
        // 	 if (i < totalSize) {
        // 	 	out_data[i] = in_data[i];
        // 	 }
        // }

        std::vector<uint32_t> shader = {
            0x07230203, 0x00010000, 0x0008000b, 0x0000002e, 0x00000000, 0x00020011, 0x00000001, 0x0006000b, 0x00000001,
            0x4c534c47, 0x6474732e, 0x3035342e, 0x00000000, 0x0003000e, 0x00000000, 0x00000001, 0x0006000f, 0x00000005,
            0x00000004, 0x6e69616d, 0x00000000, 0x0000000b, 0x00060010, 0x00000004, 0x00000011, 0x00000020, 0x00000020,
            0x00000001, 0x00030003, 0x00000002, 0x000001c2, 0x00040005, 0x00000004, 0x6e69616d, 0x00000000, 0x00030005,
            0x00000008, 0x00000069, 0x00080005, 0x0000000b, 0x475f6c67, 0x61626f6c, 0x766e496c, 0x7461636f, 0x496e6f69,
            0x00000044, 0x00050005, 0x00000010, 0x4c776f72, 0x74676e65, 0x00000068, 0x00050005, 0x00000017, 0x61746f74,
            0x7a69536c, 0x00000065, 0x00060005, 0x0000001d, 0x7074754f, 0x75427475, 0x72656666, 0x00000000, 0x00060006,
            0x0000001d, 0x00000000, 0x5f74756f, 0x61746164, 0x00000000, 0x00030005, 0x0000001f, 0x00000000, 0x00050005,
            0x00000024, 0x75706e49, 0x66754274, 0x00726566, 0x00050006, 0x00000024, 0x00000000, 0x645f6e69, 0x00617461,
            0x00030005, 0x00000026, 0x00000000, 0x00040047, 0x0000000b, 0x0000000b, 0x0000001c, 0x00040047, 0x00000010,
            0x00000001, 0x00000000, 0x00040047, 0x00000017, 0x00000001, 0x00000001, 0x00040047, 0x0000001c, 0x00000006,
            0x00000004, 0x00050048, 0x0000001d, 0x00000000, 0x00000023, 0x00000000, 0x00030047, 0x0000001d, 0x00000003,
            0x00040047, 0x0000001f, 0x00000022, 0x00000000, 0x00040047, 0x0000001f, 0x00000021, 0x00000001, 0x00040047,
            0x00000023, 0x00000006, 0x00000004, 0x00050048, 0x00000024, 0x00000000, 0x00000023, 0x00000000, 0x00030047,
            0x00000024, 0x00000003, 0x00040047, 0x00000026, 0x00000022, 0x00000000, 0x00040047, 0x00000026, 0x00000021,
            0x00000000, 0x00040047, 0x0000002d, 0x0000000b, 0x00000019, 0x00020013, 0x00000002, 0x00030021, 0x00000003,
            0x00000002, 0x00040015, 0x00000006, 0x00000020, 0x00000000, 0x00040020, 0x00000007, 0x00000007, 0x00000006,
            0x00040017, 0x00000009, 0x00000006, 0x00000003, 0x00040020, 0x0000000a, 0x00000001, 0x00000009, 0x0004003b,
            0x0000000a, 0x0000000b, 0x00000001, 0x0004002b, 0x00000006, 0x0000000c, 0x00000001, 0x00040020, 0x0000000d,
            0x00000001, 0x00000006, 0x00040032, 0x00000006, 0x00000010, 0x00000001, 0x0004002b, 0x00000006, 0x00000012,
            0x00000000, 0x00040032, 0x00000006, 0x00000017, 0x00000001, 0x00020014, 0x00000018, 0x0003001d, 0x0000001c,
            0x00000006, 0x0003001e, 0x0000001d, 0x0000001c, 0x00040020, 0x0000001e, 0x00000002, 0x0000001d, 0x0004003b,
            0x0000001e, 0x0000001f, 0x00000002, 0x00040015, 0x00000020, 0x00000020, 0x00000001, 0x0004002b, 0x00000020,
            0x00000021, 0x00000000, 0x0003001d, 0x00000023, 0x00000006, 0x0003001e, 0x00000024, 0x00000023, 0x00040020,
            0x00000025, 0x00000002, 0x00000024, 0x0004003b, 0x00000025, 0x00000026, 0x00000002, 0x00040020, 0x00000028,
            0x00000002, 0x00000006, 0x0004002b, 0x00000006, 0x0000002c, 0x00000020, 0x0006002c, 0x00000009, 0x0000002d,
            0x0000002c, 0x0000002c, 0x0000000c, 0x00050036, 0x00000002, 0x00000004, 0x00000000, 0x00000003, 0x000200f8,
            0x00000005, 0x0004003b, 0x00000007, 0x00000008, 0x00000007, 0x00050041, 0x0000000d, 0x0000000e, 0x0000000b,
            0x0000000c, 0x0004003d, 0x00000006, 0x0000000f, 0x0000000e, 0x00050084, 0x00000006, 0x00000011, 0x0000000f,
            0x00000010, 0x00050041, 0x0000000d, 0x00000013, 0x0000000b, 0x00000012, 0x0004003d, 0x00000006, 0x00000014,
            0x00000013, 0x00050080, 0x00000006, 0x00000015, 0x00000011, 0x00000014, 0x0003003e, 0x00000008, 0x00000015,
            0x0004003d, 0x00000006, 0x00000016, 0x00000008, 0x000500b0, 0x00000018, 0x00000019, 0x00000016, 0x00000017,
            0x000300f7, 0x0000001b, 0x00000000, 0x000400fa, 0x00000019, 0x0000001a, 0x0000001b, 0x000200f8, 0x0000001a,
            0x0004003d, 0x00000006, 0x00000022, 0x00000008, 0x0004003d, 0x00000006, 0x00000027, 0x00000008, 0x00060041,
            0x00000028, 0x00000029, 0x00000026, 0x00000021, 0x00000027, 0x0004003d, 0x00000006, 0x0000002a, 0x00000029,
            0x00060041, 0x00000028, 0x0000002b, 0x0000001f, 0x00000021, 0x00000022, 0x0003003e, 0x0000002b, 0x0000002a,
            0x000200f9, 0x0000001b, 0x000200f8, 0x0000001b, 0x000100fd, 0x00010038,
        };

        VkShaderModuleCreateInfo shaderModuleCreateInfo;
        shaderModuleCreateInfo.sType       = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        shaderModuleCreateInfo.pNext       = nullptr;
        shaderModuleCreateInfo.flags       = 0u;
        shaderModuleCreateInfo.codeSize    = shader.size() * sizeof(uint32_t);
        shaderModuleCreateInfo.pCode       = shader.data();
        VkShaderModule computeShaderModule = VK_NULL_HANDLE;
        if (vk_result == VK_SUCCESS)
            vk_result =
                device_table->CreateShaderModule(device, &shaderModuleCreateInfo, nullptr, &computeShaderModule);

        uint32_t unitSize    = sizeof(uint32_t);
        uint32_t groupCountX = ahb_size / 32u / 32u / unitSize;
        if (ahb_size % (32u * 32u * unitSize) != 0)
            ++groupCountX;
        uint32_t rowLength = groupCountX * 32u;

        VkSpecializationMapEntry specializationEntries[2];
        specializationEntries[0].constantID = 0u;
        specializationEntries[0].offset     = 0u;
        specializationEntries[0].size       = sizeof(uint32_t);
        specializationEntries[1].constantID = 1u;
        specializationEntries[1].offset     = sizeof(uint32_t);
        specializationEntries[1].size       = sizeof(uint32_t);

        uint32_t specializationData[2];
        specializationData[0] = rowLength;
        specializationData[1] = ahb_size / sizeof(uint32_t);

        VkSpecializationInfo specializationInfo;
        specializationInfo.mapEntryCount = 2u;
        specializationInfo.pMapEntries   = specializationEntries;
        specializationInfo.dataSize      = sizeof(uint32_t) * 2u;
        specializationInfo.pData         = specializationData;

        VkPipelineShaderStageCreateInfo shaderStageCreateInfo;
        shaderStageCreateInfo.sType               = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        shaderStageCreateInfo.pNext               = nullptr;
        shaderStageCreateInfo.flags               = 0u;
        shaderStageCreateInfo.stage               = VK_SHADER_STAGE_COMPUTE_BIT;
        shaderStageCreateInfo.module              = computeShaderModule;
        shaderStageCreateInfo.pName               = "main";
        shaderStageCreateInfo.pSpecializationInfo = &specializationInfo;

        VkDescriptorSetLayoutBinding bindings[2];
        bindings[0].binding            = 0u;
        bindings[0].descriptorType     = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        bindings[0].descriptorCount    = 1u;
        bindings[0].stageFlags         = VK_SHADER_STAGE_COMPUTE_BIT;
        bindings[0].pImmutableSamplers = nullptr;
        bindings[1].binding            = 1u;
        bindings[1].descriptorType     = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        bindings[1].descriptorCount    = 1u;
        bindings[1].stageFlags         = VK_SHADER_STAGE_COMPUTE_BIT;
        bindings[1].pImmutableSamplers = nullptr;

        VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreateInfo;
        descriptorSetLayoutCreateInfo.sType        = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        descriptorSetLayoutCreateInfo.pNext        = nullptr;
        descriptorSetLayoutCreateInfo.flags        = 0u;
        descriptorSetLayoutCreateInfo.bindingCount = 2u;
        descriptorSetLayoutCreateInfo.pBindings    = bindings;

        VkDescriptorSetLayout descriptorSetLayout = VK_NULL_HANDLE;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateDescriptorSetLayout(
                device, &descriptorSetLayoutCreateInfo, nullptr, &descriptorSetLayout);

        VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo;
        pipelineLayoutCreateInfo.sType                  = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutCreateInfo.pNext                  = nullptr;
        pipelineLayoutCreateInfo.flags                  = 0u;
        pipelineLayoutCreateInfo.setLayoutCount         = 1u;
        pipelineLayoutCreateInfo.pSetLayouts            = &descriptorSetLayout;
        pipelineLayoutCreateInfo.pushConstantRangeCount = 0u;
        pipelineLayoutCreateInfo.pPushConstantRanges    = nullptr;

        VkPipelineLayout pipelineLayout = VK_NULL_HANDLE;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreatePipelineLayout(device, &pipelineLayoutCreateInfo, nullptr, &pipelineLayout);

        VkComputePipelineCreateInfo computePipelineCreateInfo;
        computePipelineCreateInfo.sType              = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
        computePipelineCreateInfo.pNext              = nullptr;
        computePipelineCreateInfo.flags              = 0u;
        computePipelineCreateInfo.stage              = shaderStageCreateInfo;
        computePipelineCreateInfo.layout             = pipelineLayout;
        computePipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
        computePipelineCreateInfo.basePipelineIndex  = -1;

        VkPipeline computePipeline = VK_NULL_HANDLE;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateComputePipelines(
                device, VK_NULL_HANDLE, 1u, &computePipelineCreateInfo, nullptr, &computePipeline);

        VkDescriptorPoolSize poolSize;
        poolSize.type            = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        poolSize.descriptorCount = 2u;

        VkDescriptorPoolCreateInfo descriptorPoolCreateInfo;
        descriptorPoolCreateInfo.sType         = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        descriptorPoolCreateInfo.pNext         = nullptr;
        descriptorPoolCreateInfo.flags         = 0u;
        descriptorPoolCreateInfo.maxSets       = 1u;
        descriptorPoolCreateInfo.poolSizeCount = 1u;
        descriptorPoolCreateInfo.pPoolSizes    = &poolSize;

        VkDescriptorPool descriptorPool = VK_NULL_HANDLE;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateDescriptorPool(device, &descriptorPoolCreateInfo, nullptr, &descriptorPool);

        VkDescriptorSetAllocateInfo descriptorSetAllocateInfo;
        descriptorSetAllocateInfo.sType              = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        descriptorSetAllocateInfo.pNext              = nullptr;
        descriptorSetAllocateInfo.descriptorPool     = descriptorPool;
        descriptorSetAllocateInfo.descriptorSetCount = 1u;
        descriptorSetAllocateInfo.pSetLayouts        = &descriptorSetLayout;

        VkDescriptorSet descriptorSet = VK_NULL_HANDLE;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->AllocateDescriptorSets(device, &descriptorSetAllocateInfo, &descriptorSet);

        VkDescriptorBufferInfo bufferInfos[2];
        bufferInfos[0].buffer = ahbDataBuffer;
        bufferInfos[0].offset = 0u;
        bufferInfos[0].range  = VK_WHOLE_SIZE;
        bufferInfos[1].buffer = hostBuffer;
        bufferInfos[1].offset = 0u;
        bufferInfos[1].range  = VK_WHOLE_SIZE;

        VkWriteDescriptorSet descriptorWrites[2];
        descriptorWrites[0].sType            = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[0].pNext            = nullptr;
        descriptorWrites[0].dstSet           = descriptorSet;
        descriptorWrites[0].dstBinding       = 0u;
        descriptorWrites[0].dstArrayElement  = 0u;
        descriptorWrites[0].descriptorCount  = 1u;
        descriptorWrites[0].descriptorType   = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        descriptorWrites[0].pImageInfo       = nullptr;
        descriptorWrites[0].pBufferInfo      = &bufferInfos[0];
        descriptorWrites[0].pTexelBufferView = nullptr;
        descriptorWrites[1].sType            = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[1].pNext            = nullptr;
        descriptorWrites[1].dstSet           = descriptorSet;
        descriptorWrites[1].dstBinding       = 1u;
        descriptorWrites[1].dstArrayElement  = 0u;
        descriptorWrites[1].descriptorCount  = 1u;
        descriptorWrites[1].descriptorType   = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        descriptorWrites[1].pImageInfo       = nullptr;
        descriptorWrites[1].pBufferInfo      = &bufferInfos[1];
        descriptorWrites[1].pTexelBufferView = nullptr;

        if (vk_result == VK_SUCCESS)
            device_table->UpdateDescriptorSets(device, 2u, descriptorWrites, 0u, nullptr);

        VkCommandPoolCreateInfo commandPoolCreateInfo;
        commandPoolCreateInfo.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        commandPoolCreateInfo.pNext            = nullptr;
        commandPoolCreateInfo.flags            = 0u;
        commandPoolCreateInfo.queueFamilyIndex = queueFamilyIndex;

        VkCommandPool commandPool;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateCommandPool(device, &commandPoolCreateInfo, nullptr, &commandPool);

        VkCommandBufferAllocateInfo commandBufferAllocateInfo;
        commandBufferAllocateInfo.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        commandBufferAllocateInfo.pNext              = nullptr;
        commandBufferAllocateInfo.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        commandBufferAllocateInfo.commandPool        = commandPool;
        commandBufferAllocateInfo.commandBufferCount = 1u;

        VkCommandBuffer commandBuffer;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->AllocateCommandBuffers(device, &commandBufferAllocateInfo, &commandBuffer);

        VkCommandBufferBeginInfo commandBufferBeginInfo;
        commandBufferBeginInfo.sType            = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        commandBufferBeginInfo.pNext            = nullptr;
        commandBufferBeginInfo.flags            = 0u;
        commandBufferBeginInfo.pInheritanceInfo = nullptr;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->BeginCommandBuffer(commandBuffer, &commandBufferBeginInfo);

        if (vk_result == VK_SUCCESS)
        {
            VkBufferMemoryBarrier preBufferBarriers[2];
            preBufferBarriers[0].sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            preBufferBarriers[0].pNext               = nullptr;
            preBufferBarriers[0].srcAccessMask       = VK_ACCESS_NONE;
            preBufferBarriers[0].dstAccessMask       = VK_ACCESS_SHADER_READ_BIT;
            preBufferBarriers[0].srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            preBufferBarriers[0].dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            preBufferBarriers[0].buffer              = ahbDataBuffer;
            preBufferBarriers[0].offset              = 0u;
            preBufferBarriers[0].size                = ahb_size;
            preBufferBarriers[1].sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            preBufferBarriers[1].pNext               = nullptr;
            preBufferBarriers[1].srcAccessMask       = VK_ACCESS_NONE;
            preBufferBarriers[1].dstAccessMask       = VK_ACCESS_SHADER_WRITE_BIT;
            preBufferBarriers[1].srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            preBufferBarriers[1].dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            preBufferBarriers[1].buffer              = hostBuffer;
            preBufferBarriers[1].offset              = 0u;
            preBufferBarriers[1].size                = ahb_size;

            device_table->CmdPipelineBarrier(commandBuffer,
                                             VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                             VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                             0,
                                             0,
                                             nullptr,
                                             2,
                                             preBufferBarriers,
                                             0,
                                             nullptr);

            device_table->CmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_COMPUTE, computePipeline);
            device_table->CmdBindDescriptorSets(
                commandBuffer, VK_PIPELINE_BIND_POINT_COMPUTE, pipelineLayout, 0, 1, &descriptorSet, 0, nullptr);
            device_table->CmdDispatch(commandBuffer, groupCountX, 1u, 1u);

            VkBufferMemoryBarrier postBufferBarrier;
            postBufferBarrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            postBufferBarrier.pNext               = nullptr;
            postBufferBarrier.srcAccessMask       = VK_ACCESS_SHADER_WRITE_BIT;
            postBufferBarrier.dstAccessMask       = VK_ACCESS_HOST_READ_BIT;
            postBufferBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            postBufferBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            postBufferBarrier.buffer              = hostBuffer;
            postBufferBarrier.offset              = 0u;
            postBufferBarrier.size                = ahb_size;

            device_table->CmdPipelineBarrier(commandBuffer,
                                             VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                             VK_PIPELINE_STAGE_HOST_BIT,
                                             0,
                                             0,
                                             nullptr,
                                             1,
                                             &postBufferBarrier,
                                             0,
                                             nullptr);

            device_table->EndCommandBuffer(commandBuffer);
        }

        VkSubmitInfo submitInfo;
        submitInfo.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submitInfo.pNext                = nullptr;
        submitInfo.waitSemaphoreCount   = 0u;
        submitInfo.pWaitSemaphores      = nullptr;
        submitInfo.pWaitDstStageMask    = nullptr;
        submitInfo.commandBufferCount   = 1u;
        submitInfo.pCommandBuffers      = &commandBuffer;
        submitInfo.signalSemaphoreCount = 0u;
        submitInfo.pSignalSemaphores    = nullptr;

        VkFenceCreateInfo fenceCreateInfo;
        fenceCreateInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fenceCreateInfo.pNext = nullptr;
        fenceCreateInfo.flags = 0u;

        VkFence fence;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->CreateFence(device, &fenceCreateInfo, nullptr, &fence);

        auto queue = device_wrapper->child_queues[0]->handle;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->QueueSubmit(queue, 1, &submitInfo, fence);
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->WaitForFences(device, 1u, &fence, VK_TRUE, UINT64_MAX);

        void* data;
        if (vk_result == VK_SUCCESS)
            vk_result = device_table->MapMemory(device, hostBufferMemory, 0u, ahb_size, 0u, &data);

        if (vk_result == VK_SUCCESS)
        {
            CommonWriteFillMemoryCmd(memory_id, ahb_size, data, vulkan_capture_manager, vulkan_state_writer);

            if (vulkan_capture_manager)
            {
                // Track the memory with the PageGuardManager
                const auto tracking_mode = vulkan_capture_manager->GetMemoryTrackingMode();
                if ((tracking_mode == CaptureSettings::MemoryTrackingMode::kPageGuard ||
                     tracking_mode == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
                    vulkan_capture_manager->GetPageGuardTrackAhbMemory())
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, ahb_size);

                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    manager->AddTrackedMemory(memory_id,
                                              data,
                                              0,
                                              static_cast<size_t>(ahb_size),
                                              util::PageGuardManager::kNullShadowHandle,
                                              false,  // No shadow memory for the imported AHB memory.
                                              false); // Write watch is not supported for this case.
                }
            }
        }

        device_table->DestroyFence(device, fence, nullptr);
        device_table->DestroyCommandPool(device, commandPool, nullptr);
        device_table->DestroyDescriptorPool(device, descriptorPool, nullptr);
        device_table->DestroyPipeline(device, computePipeline, nullptr);
        device_table->DestroyDescriptorSetLayout(device, descriptorSetLayout, nullptr);
        device_table->DestroyPipelineLayout(device, pipelineLayout, nullptr);
        device_table->DestroyShaderModule(device, computeShaderModule, nullptr);
        device_table->FreeMemory(device, bufferMemory, nullptr);
        device_table->FreeMemory(device, hostBufferMemory, nullptr);
        device_table->DestroyBuffer(device, ahbDataBuffer, nullptr);
        device_table->DestroyBuffer(device, hostBuffer, nullptr);

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
