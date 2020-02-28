//=============================================================================
/// Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file   vulkan_memory_data_consumer_base.cpp
/// \brief  Header file of TcpClient class,
///         which is used to send messages over TCP
//=============================================================================

#include "decode/vulkan_resource_tracking_consumer_base.h"

#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanResourceTrackingConsumerBase::VulkanResourceTrackingConsumerBase(VulkanReplayConsumer* replay_consumer,
                                                                       const ReplayOptions&  options) :
    file_(nullptr),
    options_(options), replay_consumer_(replay_consumer)
{}

VulkanResourceTrackingConsumerBase::~VulkanResourceTrackingConsumerBase()
{
    Destroy();
}

bool VulkanResourceTrackingConsumerBase::Initialize(const std::string& filename)
{
    bool success = false;

    if (file_ == nullptr)
    {
        int32_t result = util::platform::FileOpen(&file_, filename.c_str(), "w");
        if (result == 0)
        {
            success   = true;
            filename_ = filename;
        }
    }

    return success;
}

void VulkanResourceTrackingConsumerBase::Destroy()
{
    if (file_ != nullptr)
    {
        util::platform::FileClose(file_);
    }
}

void VulkanResourceTrackingConsumerBase::OverrideCreateBuffer(
    format::HandleId                                           device,
    const StructPointerDecoder<Decoded_VkBufferCreateInfo>&    create_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& allocator,
    HandlePointerDecoder<VkBuffer>*                            buffer)
{
    BufferInfo buffer_info;

    assert((buffer != nullptr) && (buffer->GetHandlePointer() != nullptr) && (replay_consumer_ != nullptr));

    auto buffer_create_info = create_info.GetPointer();

    if ((buffer_create_info != nullptr))
    {
        buffer_info.buffer_create_info = *(buffer_create_info);

        if ((buffer_create_info->sharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (buffer_create_info->queueFamilyIndexCount > 0) && (buffer_create_info->pQueueFamilyIndices != nullptr))
        {
            buffer_info.queue_family_index = buffer_create_info->pQueueFamilyIndices[0];
        }
        else
        {
            buffer_info.queue_family_index = 0;
        }
    }

    buffer_info.capture_id = *(buffer->GetPointer());
    replay_consumer_->GetObjectInfoTable().AddBufferInfo(std::move(buffer_info));
}

void VulkanResourceTrackingConsumerBase::OverrideCreateImage(
    format::HandleId                                           device,
    const StructPointerDecoder<Decoded_VkImageCreateInfo>&     create_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& allocator,
    HandlePointerDecoder<VkImage>*                             image)
{
    ImageInfo image_info;

    assert((image != nullptr) && (image->GetHandlePointer() != nullptr) && (replay_consumer_ != nullptr));

    auto image_create_info = create_info.GetPointer();

    if ((image_create_info != nullptr))
    {
        image_info.image_create_info = *(image_create_info);

        if ((image_create_info->sharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (image_create_info->queueFamilyIndexCount > 0) && (image_create_info->pQueueFamilyIndices != nullptr))
        {
            image_info.queue_family_index = image_create_info->pQueueFamilyIndices[0];
        }
        else
        {
            image_info.queue_family_index = 0;
        }
    }

    image_info.capture_id = *(image->GetPointer());
    replay_consumer_->GetObjectInfoTable().AddImageInfo(std::move(image_info));
}

void VulkanResourceTrackingConsumerBase::OverrideAllocateMemory(
    format::HandleId                                           device,
    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>&  allocate_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& allocator,
    HandlePointerDecoder<VkDeviceMemory>*                      memory)
{
    DeviceMemoryInfo memory_info;

    assert((memory != nullptr) && (memory->GetHandlePointer() != nullptr) && (replay_consumer_ != nullptr));

    const VkMemoryAllocateInfo* replay_allocate_info = allocate_info.GetPointer();

    if (!options_.skip_failed_allocations)
    {
        auto replay_memory = memory->GetHandlePointer();

        if ((replay_allocate_info != nullptr) && ((*replay_memory) != VK_NULL_HANDLE))
        {
            memory_info.memory_allocation_size = replay_allocate_info->allocationSize;
            // TODO (gfxrec-28): check for replay allocaion memory type index and the memory propertyFlags
        }
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateMemory call as per user option set.")
    }

    memory_info.capture_id = *(memory->GetPointer());
    replay_consumer_->GetObjectInfoTable().AddDeviceMemoryInfo(std::move(memory_info));
}

void VulkanResourceTrackingConsumerBase::OverrideBindBufferMemory(format::HandleId device,
                                                                  format::HandleId buffer,
                                                                  format::HandleId memory,
                                                                  VkDeviceSize     memory_offset)
{
    assert(replay_consumer_ != nullptr);

    auto buffer_info = replay_consumer_->GetObjectInfoTable().GetBufferInfo(buffer);
    auto memory_info = replay_consumer_->GetObjectInfoTable().GetDeviceMemoryInfo(memory);

    assert((buffer_info != nullptr) && (memory_info != nullptr));

    buffer_info->memory_id = memory;
    // TODO (gfxrec-28): track buffer info memory property flags in new device
    buffer_info->bind_offset = memory_offset;
    memory_info->buffers_id.push_back(buffer);
}

void VulkanResourceTrackingConsumerBase::OverrideBindImageMemory(format::HandleId device,
                                                                 format::HandleId image,
                                                                 format::HandleId memory,
                                                                 VkDeviceSize     memory_offset)
{
    assert(replay_consumer_ != nullptr);

    auto image_info  = replay_consumer_->GetObjectInfoTable().GetImageInfo(image);
    auto memory_info = replay_consumer_->GetObjectInfoTable().GetDeviceMemoryInfo(memory);

    assert((image_info != nullptr) && (memory_info != nullptr));

    image_info->memory_id = memory;
    // TODO (gfxrec-28): track image info memory property flags in new device
    image_info->bind_offset = memory_offset;
    memory_info->images_id.push_back(image);
}

void VulkanResourceTrackingConsumerBase::OverrideMapMemory(format::HandleId                 device,
                                                           format::HandleId                 memory,
                                                           VkDeviceSize                     offset,
                                                           VkDeviceSize                     size,
                                                           VkMemoryMapFlags                 flags,
                                                           PointerDecoder<uint64_t, void*>* data_pointer)
{
    assert(replay_consumer_ != nullptr);

    auto memory_info = replay_consumer_->GetObjectInfoTable().GetDeviceMemoryInfo(memory);

    assert((memory_info != nullptr));

    memory_info->mapped_memories_offsets.push_back(offset);
    memory_info->mapped_memories_sizes.push_back(size);
}

void VulkanResourceTrackingConsumerBase::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                                  uint64_t       offset,
                                                                  uint64_t       size,
                                                                  const uint8_t* data)
{
    assert(replay_consumer_ != nullptr);

    auto memory_info = replay_consumer_->GetObjectInfoTable().GetDeviceMemoryInfo(memory_id);

    assert((memory_info != nullptr));

    memory_info->filled_memories_offsets.push_back(offset);
    memory_info->filled_memories_sizes.push_back(size);
    // TODO (gfxrec-28): do we need to store the data content?
}

void VulkanResourceTrackingConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(
    format::HandleId                       device,
    format::HandleId                       descriptor_set,
    format::HandleId                       descriptor_update_template,
    const DescriptorUpdateTemplateDecoder& data)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_set);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_update_template);
    GFXRECON_UNREFERENCED_PARAMETER(data);
}

void VulkanResourceTrackingConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    format::HandleId                       command_buffer,
    format::HandleId                       descriptor_update_template,
    format::HandleId                       layout,
    uint32_t                               set,
    const DescriptorUpdateTemplateDecoder& data)
{
    GFXRECON_UNREFERENCED_PARAMETER(command_buffer);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_update_template);
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(set);
    GFXRECON_UNREFERENCED_PARAMETER(data);
}

void VulkanResourceTrackingConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    format::HandleId                       device,
    format::HandleId                       descriptor_set,
    format::HandleId                       descriptor_update_template,
    const DescriptorUpdateTemplateDecoder& data)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_set);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_update_template);
    GFXRECON_UNREFERENCED_PARAMETER(data);
}

void VulkanResourceTrackingConsumerBase::Process_vkRegisterObjectsNVX(
    VkResult                                                   return_value,
    format::HandleId                                           device,
    format::HandleId                                           object_table,
    uint32_t                                                   object_count,
    const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& object_table_entries_pointer,
    const PointerDecoder<uint32_t>&                            object_indices)
{
    GFXRECON_UNREFERENCED_PARAMETER(return_value);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(object_table);
    GFXRECON_UNREFERENCED_PARAMETER(object_count);
    GFXRECON_UNREFERENCED_PARAMETER(object_table_entries_pointer);
    GFXRECON_UNREFERENCED_PARAMETER(object_indices);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
