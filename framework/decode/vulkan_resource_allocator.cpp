/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_resource_allocator.h"

#include "decode/vulkan_object_info.h"
#include "graphics/vulkan_injected_calls.h"
#include "util/logging.h"

#include <algorithm>
#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanResourceAllocator::Initialize(const VulkanPhysicalDeviceInfo*      physical_device_info,
                                             VkDevice                             device,
                                             const VkDeviceCreateInfo&            device_create_info,
                                             const std::vector<std::string>&      enabled_device_extensions,
                                             const graphics::VulkanInstanceTable& instance_table,
                                             const graphics::VulkanDeviceTable*   device_table)
{
    GFXRECON_UNREFERENCED_PARAMETER(device_create_info);

    assert((physical_device_info != nullptr) && (physical_device_info->replay_device_info != nullptr));

    functions_.get_physical_device_properties        = instance_table.GetPhysicalDeviceProperties;
    functions_.get_physical_device_memory_properties = instance_table.GetPhysicalDeviceMemoryProperties;
    functions_.get_instance_proc_addr                = instance_table.GetInstanceProcAddr;

    functions_.allocate_memory                       = device_table->AllocateMemory;
    functions_.free_memory                           = device_table->FreeMemory;
    functions_.get_device_memory_commitment          = device_table->GetDeviceMemoryCommitment;
    functions_.map_memory                            = device_table->MapMemory;
    functions_.unmap_memory                          = device_table->UnmapMemory;
    functions_.flush_memory_ranges                   = device_table->FlushMappedMemoryRanges;
    functions_.invalidate_memory_ranges              = device_table->InvalidateMappedMemoryRanges;
    functions_.create_buffer                         = device_table->CreateBuffer;
    functions_.destroy_buffer                        = device_table->DestroyBuffer;
    functions_.get_buffer_memory_requirements        = device_table->GetBufferMemoryRequirements;
    functions_.bind_buffer_memory                    = device_table->BindBufferMemory;
    functions_.create_image                          = device_table->CreateImage;
    functions_.destroy_image                         = device_table->DestroyImage;
    functions_.get_image_memory_requirements         = device_table->GetImageMemoryRequirements;
    functions_.get_image_subresource_layout          = device_table->GetImageSubresourceLayout;
    functions_.bind_image_memory                     = device_table->BindImageMemory;
    functions_.get_device_proc_addr                  = device_table->GetDeviceProcAddr;
    functions_.get_device_queue                      = device_table->GetDeviceQueue;
    functions_.create_command_pool                   = device_table->CreateCommandPool;
    functions_.allocate_command_buffers              = device_table->AllocateCommandBuffers;
    functions_.begin_command_buffer                  = device_table->BeginCommandBuffer;
    functions_.cmd_copy_buffer                       = device_table->CmdCopyBuffer;
    functions_.cmd_copy_buffer_to_image              = device_table->CmdCopyBufferToImage;
    functions_.end_command_buffer                    = device_table->EndCommandBuffer;
    functions_.queue_submit                          = device_table->QueueSubmit;
    functions_.free_command_buffers                  = device_table->FreeCommandBuffers;
    functions_.destroy_command_pool                  = device_table->DestroyCommandPool;
    functions_.create_video_session                  = device_table->CreateVideoSessionKHR;
    functions_.destroy_video_session                 = device_table->DestroyVideoSessionKHR;
    functions_.bind_video_session_memory             = device_table->BindVideoSessionMemoryKHR;
    functions_.get_video_session_memory_requirements = device_table->GetVideoSessionMemoryRequirementsKHR;
    if (physical_device_info->parent_info.api_version >= VK_MAKE_VERSION(1, 4, 0))
    {
        functions_.map_memory2   = device_table->MapMemory2;
        functions_.unmap_memory2 = device_table->UnmapMemory2;
    }
    else
    {
        functions_.map_memory2   = device_table->MapMemory2KHR;
        functions_.unmap_memory2 = device_table->UnmapMemory2KHR;
    }
    functions_.set_device_memory_priority            = device_table->SetDeviceMemoryPriorityEXT;
    functions_.get_memory_remote_address_nv          = device_table->GetMemoryRemoteAddressNV;
    functions_.create_acceleration_structure_nv      = device_table->CreateAccelerationStructureNV;
    functions_.destroy_acceleration_structure_nv     = device_table->DestroyAccelerationStructureNV;
    functions_.bind_acceleration_structure_memory_nv = device_table->BindAccelerationStructureMemoryNV;
    functions_.get_acceleration_structure_memory_requirements_nv =
        device_table->GetAccelerationStructureMemoryRequirementsNV;
    functions_.queue_bind_sparse                           = device_table->QueueBindSparse;
    functions_.create_semaphore                            = device_table->CreateSemaphore;
    functions_.destroy_semaphore                           = device_table->DestroySemaphore;
    functions_.get_memory_fd                               = device_table->GetMemoryFdKHR;
    functions_.get_device_memory_opaque_capture_address    = device_table->GetDeviceMemoryOpaqueCaptureAddressKHR;
    functions_.get_physical_device_queue_family_properties = instance_table.GetPhysicalDeviceQueueFamilyProperties;
    functions_.set_debug_utils_object_name                 = instance_table.SetDebugUtilsObjectNameEXT;
    functions_.set_debug_utils_object_tag                  = instance_table.SetDebugUtilsObjectTagEXT;
    functions_.get_android_hardware_buffer_properties      = device_table->GetAndroidHardwareBufferPropertiesANDROID;
    functions_.create_fence                                = device_table->CreateFence;
    functions_.wait_for_fences                             = device_table->WaitForFences;
    functions_.destroy_fence                               = device_table->DestroyFence;
    functions_.create_tensor                               = device_table->CreateTensorARM;
    functions_.destroy_tensor                              = device_table->DestroyTensorARM;
    functions_.get_tensor_memory_requirements              = device_table->GetTensorMemoryRequirementsARM;
    functions_.bind_tensor_memory                          = device_table->BindTensorMemoryARM;
    functions_.create_data_graph_pipeline_session          = device_table->CreateDataGraphPipelineSessionARM;
    functions_.get_data_graph_pipeline_session_memory_requirements =
        device_table->GetDataGraphPipelineSessionMemoryRequirementsARM;
    functions_.bind_data_graph_pipeline_session_memory = device_table->BindDataGraphPipelineSessionMemoryARM;
    functions_.destroy_data_graph_pipeline_session     = device_table->DestroyDataGraphPipelineSessionARM;
    functions_.get_data_graph_pipeline_session_bind_point_requirements =
        device_table->GetDataGraphPipelineSessionBindPointRequirementsARM;

    if (physical_device_info->parent_info.api_version >= VK_MAKE_VERSION(1, 1, 0))
    {
        functions_.get_physical_device_memory_properties2 = instance_table.GetPhysicalDeviceMemoryProperties2;
        functions_.get_buffer_memory_requirements2        = device_table->GetBufferMemoryRequirements2;
        functions_.get_image_memory_requirements2         = device_table->GetImageMemoryRequirements2;
        functions_.bind_buffer_memory2                    = device_table->BindBufferMemory2;
        functions_.bind_image_memory2                     = device_table->BindImageMemory2;
    }
    else
    {
        const auto& instance_extensions = physical_device_info->parent_info.enabled_extensions;

        if (std::find(instance_extensions.begin(),
                      instance_extensions.end(),
                      VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) != instance_extensions.end())
        {
            functions_.get_physical_device_memory_properties2 = instance_table.GetPhysicalDeviceMemoryProperties2KHR;
        }

        if (std::find(enabled_device_extensions.begin(),
                      enabled_device_extensions.end(),
                      VK_KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME) != enabled_device_extensions.end())
        {
            functions_.get_buffer_memory_requirements2 = device_table->GetBufferMemoryRequirements2KHR;
            functions_.get_image_memory_requirements2  = device_table->GetImageMemoryRequirements2KHR;
        }

        if (std::find(enabled_device_extensions.begin(),
                      enabled_device_extensions.end(),
                      VK_KHR_BIND_MEMORY_2_EXTENSION_NAME) != enabled_device_extensions.end())
        {
            functions_.bind_buffer_memory2 = device_table->BindBufferMemory2KHR;
            functions_.bind_image_memory2  = device_table->BindImageMemory2KHR;
        }
    }

    auto replay_device_info = physical_device_info->replay_device_info;
    GFXRECON_ASSERT(replay_device_info->memory_properties.has_value());

    device_                   = device;
    replay_memory_properties_ = replay_device_info->memory_properties.value();
    device_table_             = graphics::VulkanInjectedDeviceCalls(device_table);

    return VK_SUCCESS;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
