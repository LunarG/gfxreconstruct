/*
 ** Copyright (c) 2024 LunarG, Inc.
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

void CommonWriteCreateHardwareBufferCmd(format::ThreadId                                    thread_id,
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

void CommonProcessHardwareBuffer(format::ThreadId      thread_id,
                                 format::HandleId      memory_id,
                                 AHardwareBuffer*      hardware_buffer,
                                 size_t                allocation_size,
                                 VulkanCaptureManager* vulkan_capture_manager,
                                 VulkanStateWriter*    vulkan_state_writer)
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
            thread_id, memory_id, hardware_buffer, plane_info, vulkan_capture_manager, vulkan_state_writer);

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
        // The AHB is not CPU-readable

        // Write CreateHardwareBufferCmd without the AHB payload
        CommonWriteCreateHardwareBufferCmd(
            thread_id, memory_id, hardware_buffer, plane_info, vulkan_capture_manager, vulkan_state_writer);

        // Dump zeros for AHB payload.
        std::vector<uint8_t> zeros(allocation_size, 0);
        CommonWriteFillMemoryCmd(memory_id, zeros.size(), zeros.data(), vulkan_capture_manager, vulkan_state_writer);

        GFXRECON_LOG_WARNING("AHardwareBuffer cannot be read: hardware buffer data will be omitted "
                             "from the capture file");
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
