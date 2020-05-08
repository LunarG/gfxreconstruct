//=============================================================================
/// Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file   vulkan_memory_data_consumer_base.cpp
/// \brief  Header file of TcpClient class,
///         which is used to send messages over TCP
//=============================================================================

#include "decode/vulkan_resource_tracking_consumer_base.h"

#include <unordered_set>
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanResourceTrackingConsumerBase::VulkanResourceTrackingConsumerBase(const ReplayOptions& options) :
    options_(options), create_instance_function_(nullptr), enumerate_physical_devices_function_(nullptr),
    create_device_function_(nullptr), create_buffer_function_(nullptr), create_image_function_(nullptr),
    get_buffer_memory_requirement_function_(nullptr), get_image_memory_requirement_function_(nullptr),
    destroy_buffer_function_(nullptr), destroy_image_function_(nullptr), destroy_device_function_(nullptr),
    destroy_instance_function_(nullptr)
{}

VulkanResourceTrackingConsumerBase::~VulkanResourceTrackingConsumerBase() {}

void VulkanResourceTrackingConsumerBase::OverrideCreateInstance(
    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkInstance>*                         pInstance)
{
    assert((pCreateInfo != nullptr) && (pInstance != nullptr) && (pInstance->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_instance    = pInstance->GetHandlePointer();

    // TODO(gfxrec-28): Replace WSI extension in extension list??

    // TODO(gfxrec-28): Disable layers??

    VkResult result = create_instance_function_(replay_create_info, nullptr, replay_instance);

    if ((replay_instance != nullptr) && (result == VK_SUCCESS))
    {
        TrackedInstanceInfo instance_info;
        instance_info.SetCaptureId(*(pInstance->GetPointer()));
        instance_info.SetHandleId(*replay_instance);
        GetTrackedObjectInfoTable().AddTrackedInstanceInfo(std::move(instance_info));
    }
}

void VulkanResourceTrackingConsumerBase::OverrideCreateDevice(
    format::HandleId                                        physicalDevice,
    const StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkDevice>*                         pDevice)
{
    auto physical_device_info = GetTrackedObjectInfoTable().GetTrackedPhysicalDeviceInfo(physicalDevice);

    assert((physical_device_info != nullptr) && (pCreateInfo != nullptr) && (pDevice != nullptr) &&
           (pDevice->GetHandlePointer() != nullptr));

    VkResult         result          = VK_ERROR_INITIALIZATION_FAILED;
    VkPhysicalDevice physical_device = physical_device_info->GetHandleId();

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_device      = pDevice->GetHandlePointer();

    result = create_device_function_(physical_device, replay_create_info, nullptr, replay_device);

    if ((replay_device != nullptr) && (result == VK_SUCCESS))
    {
        TrackedDeviceInfo device_info;

        device_info.SetParentPhysicalDevice(physical_device);

        device_info.SetCaptureId(*(pDevice->GetPointer()));
        device_info.SetHandleId(*(replay_device));
        GetTrackedObjectInfoTable().AddTrackedDeviceInfo(std::move(device_info));
    }
}

void VulkanResourceTrackingConsumerBase::OverrideEnumeratePhysicalDevices(
    format::HandleId                        instance,
    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices)
{
    auto instance_info = GetTrackedObjectInfoTable().GetTrackedInstanceInfo(instance);

    std::vector<TrackedPhysicalDeviceInfo> handle_info(*pPhysicalDeviceCount->GetOutputPointer());

    assert((instance_info != nullptr) && (pPhysicalDeviceCount != nullptr) &&
           (pPhysicalDeviceCount->GetPointer() != nullptr) && (pPhysicalDevices != nullptr));

    VkInstance        instance_id         = instance_info->GetHandleId();
    uint32_t          replay_device_count = (*pPhysicalDeviceCount->GetPointer());
    VkPhysicalDevice* replay_devices      = pPhysicalDevices->GetHandlePointer();

    VkResult result = enumerate_physical_devices_function_(instance_id, &replay_device_count, replay_devices);

    // TODO (gfxrec-28): check for memory type properties compatibility between capture and replay devices

    if ((result >= 0) && (replay_devices != nullptr))
    {

        if ((pPhysicalDevices->GetPointer() != nullptr) && (pPhysicalDevices->GetHandlePointer() != nullptr))
        {
            size_t capture_physical_device_length  = pPhysicalDevices->GetLength();
            size_t playback_physical_device_length = *pPhysicalDeviceCount->GetOutputPointer();
            size_t len = std::min(capture_physical_device_length, playback_physical_device_length);

            assert(len <= handle_info.size());

            for (size_t i = 0; i < len; ++i)
            {
                auto info_iterator = std::next(handle_info.begin(), i);
                info_iterator->SetHandleId(pPhysicalDevices->GetHandlePointer()[i]);
                info_iterator->SetCaptureId(pPhysicalDevices->GetPointer()[i]);
                GetTrackedObjectInfoTable().AddTrackedPhysicalDeviceInfo(std::move(*info_iterator));
            }
        }
    }
}

void VulkanResourceTrackingConsumerBase::OverrideCreateBuffer(
    format::HandleId                                           device,
    const StructPointerDecoder<Decoded_VkBufferCreateInfo>*    create_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
    HandlePointerDecoder<VkBuffer>*                            buffer)
{
    TrackedBufferInfo buffer_info;

    assert((create_info != nullptr) && (buffer != nullptr) && (buffer->GetHandlePointer() != nullptr));

    auto buffer_create_info = create_info->GetPointer();
    auto replay_buffer      = buffer->GetHandlePointer();

    auto in_device = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);

    VkResult result = create_buffer_function_(in_device->GetHandleId(), buffer_create_info, nullptr, replay_buffer);

    if ((result == VK_SUCCESS) && (buffer_create_info != nullptr) && ((*replay_buffer) != VK_NULL_HANDLE))
    {
        if ((buffer_create_info->sharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (buffer_create_info->queueFamilyIndexCount > 0) && (buffer_create_info->pQueueFamilyIndices != nullptr))
        {
            buffer_info.SetQueueFamilyIndex(buffer_create_info->pQueueFamilyIndices[0]);
        }
        else
        {
            buffer_info.SetQueueFamilyIndex(0);
        }

        buffer_info.SetBufferCreateInfo(*(buffer_create_info));
        buffer_info.SetHandleId(*replay_buffer);
        buffer_info.SetCaptureId(*(buffer->GetPointer()));
        GetTrackedObjectInfoTable().AddTrackedBufferInfo(std::move(buffer_info));
    }
}

void VulkanResourceTrackingConsumerBase::OverrideCreateImage(
    format::HandleId                                           device,
    const StructPointerDecoder<Decoded_VkImageCreateInfo>*     create_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
    HandlePointerDecoder<VkImage>*                             image)
{
    TrackedImageInfo image_info;

    assert((create_info != nullptr) && (image != nullptr) && (image->GetHandlePointer() != nullptr));

    auto in_device = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);

    auto image_create_info = create_info->GetPointer();
    auto replay_image      = image->GetHandlePointer();

    VkResult result = create_image_function_(in_device->GetHandleId(), image_create_info, nullptr, replay_image);

    if ((result == VK_SUCCESS) && (image_create_info != nullptr) && ((*replay_image) != VK_NULL_HANDLE))
    {
        if ((image_create_info->sharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (image_create_info->queueFamilyIndexCount > 0) && (image_create_info->pQueueFamilyIndices != nullptr))
        {
            image_info.SetQueueFamilyIndex(image_create_info->pQueueFamilyIndices[0]);
        }
        else
        {
            image_info.SetQueueFamilyIndex(0);
        }

        image_info.SetImageCreateInfo(*(image_create_info));
        image_info.SetHandleId(*replay_image);
        image_info.SetCaptureId(*(image->GetPointer()));
        GetTrackedObjectInfoTable().AddTrackedImageInfo(std::move(image_info));
    }
}

void VulkanResourceTrackingConsumerBase::OverrideAllocateMemory(
    format::HandleId                                           device,
    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  allocate_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
    HandlePointerDecoder<VkDeviceMemory>*                      memory)
{
    TrackedDeviceMemoryInfo memory_info;

    assert((allocate_info != nullptr) && (memory != nullptr) && (memory->GetHandlePointer() != nullptr));

    const VkMemoryAllocateInfo* replay_allocate_info = allocate_info->GetPointer();

    if (!options_.skip_failed_allocations)
    {
        auto replay_memory = memory->GetHandlePointer();

        if ((replay_allocate_info != nullptr) && ((*replay_memory) != VK_NULL_HANDLE))
        {
            memory_info.SetMemoryAllocationSize(replay_allocate_info->allocationSize);
            // TODO (gfxrec-28): check for replay allocaion memory type index and the memory propertyFlags
        }
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateMemory call as per user option set.")
    }

    memory_info.SetCaptureId(*(memory->GetPointer()));
    GetTrackedObjectInfoTable().AddTrackedDeviceMemoryInfo(std::move(memory_info));
}

void VulkanResourceTrackingConsumerBase::OverrideBindBufferMemory(format::HandleId device,
                                                                  format::HandleId buffer,
                                                                  format::HandleId memory,
                                                                  VkDeviceSize     memory_offset)
{
    auto buffer_info = GetTrackedObjectInfoTable().GetTrackedBufferInfo(buffer);
    auto memory_info = GetTrackedObjectInfoTable().GetTrackedDeviceMemoryInfo(memory);

    assert((buffer_info != nullptr) && (memory_info != nullptr));

    buffer_info->SetBoundMemoryId(memory);
    // TODO (gfxrec-28): track buffer info memory property flags in new device
    buffer_info->SetBufferBindOffset(memory_offset);
    memory_info->InsertBoundBufferIdList(buffer);
}

void VulkanResourceTrackingConsumerBase::OverrideBindImageMemory(format::HandleId device,
                                                                 format::HandleId image,
                                                                 format::HandleId memory,
                                                                 VkDeviceSize     memory_offset)
{
    auto image_info  = GetTrackedObjectInfoTable().GetTrackedImageInfo(image);
    auto memory_info = GetTrackedObjectInfoTable().GetTrackedDeviceMemoryInfo(memory);

    assert((image_info != nullptr) && (memory_info != nullptr));

    image_info->SetBoundMemoryId(memory);
    // TODO (gfxrec-28): track image info memory property flags in new device
    image_info->SetImageBindOffset(memory_offset);
    memory_info->InsertBoundImageIdList(image);
}

void VulkanResourceTrackingConsumerBase::OverrideMapMemory(format::HandleId                 device,
                                                           format::HandleId                 memory,
                                                           VkDeviceSize                     offset,
                                                           VkDeviceSize                     size,
                                                           VkMemoryMapFlags                 flags,
                                                           PointerDecoder<uint64_t, void*>* data_pointer)
{
    auto memory_info = GetTrackedObjectInfoTable().GetTrackedDeviceMemoryInfo(memory);

    assert((memory_info != nullptr));

    memory_info->InsertMappedMemoryOffsetsList(offset);
    memory_info->InsertMappedMemorySizesList(size);
}

void VulkanResourceTrackingConsumerBase::OverrideGetBufferMemoryRequirements(
    format::HandleId                                    device,
    format::HandleId                                    buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    auto device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    auto buffer_info = GetTrackedObjectInfoTable().GetTrackedBufferInfo(buffer);

    VkDevice              in_device               = device_info->GetHandleId();
    VkBuffer              in_buffer               = buffer_info->GetHandleId();
    VkMemoryRequirements* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1);

    get_buffer_memory_requirement_function_(in_device, in_buffer, out_pMemoryRequirements);

    if (out_pMemoryRequirements != nullptr)
    {
        buffer_info->SetMemoryRequirement(*out_pMemoryRequirements);
    }

    // TODO (gfxrec-28): recalculate and update the buffer offset
}

void VulkanResourceTrackingConsumerBase::OverrideGetImageMemoryRequirements(
    format::HandleId                                    device,
    format::HandleId                                    image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    auto device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    auto image_info  = GetTrackedObjectInfoTable().GetTrackedImageInfo(image);

    VkDevice              in_device               = device_info->GetHandleId();
    VkImage               in_image                = image_info->GetHandleId();
    VkMemoryRequirements* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1);

    get_image_memory_requirement_function_(in_device, in_image, out_pMemoryRequirements);

    if (out_pMemoryRequirements != nullptr)
    {
        image_info->SetMemoryRequirement(*out_pMemoryRequirements);
    }

    // TODO (gfxrec-28): recalculate and update the image offset
}

void VulkanResourceTrackingConsumerBase::OverrideDestroyInstance(
    format::HandleId instance, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto       instance_info = GetTrackedObjectInfoTable().GetTrackedInstanceInfo(instance);
    VkInstance in_instance   = instance_info->GetHandleId();

    destroy_instance_function_(in_instance, nullptr);
}

void VulkanResourceTrackingConsumerBase::OverrideDestroyDevice(
    format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto     device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    VkDevice in_device   = device_info->GetHandleId();

    destroy_device_function_(in_device, nullptr);
}

void VulkanResourceTrackingConsumerBase::OverrideDestroyBuffer(
    format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto     device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    auto     buffer_info = GetTrackedObjectInfoTable().GetTrackedBufferInfo(buffer);
    VkDevice in_device   = device_info->GetHandleId();
    VkBuffer in_buffer   = buffer_info->GetHandleId();

    destroy_buffer_function_(in_device, in_buffer, nullptr);
}

void VulkanResourceTrackingConsumerBase::OverrideDestroyImage(
    format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto     device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    auto     image_info  = GetTrackedObjectInfoTable().GetTrackedImageInfo(image);
    VkDevice in_device   = device_info->GetHandleId();
    VkImage  in_image    = image_info->GetHandleId();

    destroy_image_function_(in_device, in_image, nullptr);
}

void VulkanResourceTrackingConsumerBase::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                                  uint64_t       offset,
                                                                  uint64_t       size,
                                                                  const uint8_t* data)
{
    auto memory_info = GetTrackedObjectInfoTable().GetTrackedDeviceMemoryInfo(memory_id);

    assert((memory_info != nullptr));

    memory_info->InsertFilledMemoryOffsetsList(offset);
    memory_info->InsertFilledMemorySizesList(size);
    // TODO (gfxrec-28): do we need to store the mapped data content?
}

void VulkanResourceTrackingConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(
    format::HandleId                 device,
    format::HandleId                 descriptor_set,
    format::HandleId                 descriptor_update_template,
    DescriptorUpdateTemplateDecoder* data)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_set);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_update_template);
    GFXRECON_UNREFERENCED_PARAMETER(data);
}

void VulkanResourceTrackingConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    format::HandleId                 command_buffer,
    format::HandleId                 descriptor_update_template,
    format::HandleId                 layout,
    uint32_t                         set,
    DescriptorUpdateTemplateDecoder* data)
{
    GFXRECON_UNREFERENCED_PARAMETER(command_buffer);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_update_template);
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(set);
    GFXRECON_UNREFERENCED_PARAMETER(data);
}

void VulkanResourceTrackingConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    format::HandleId                 device,
    format::HandleId                 descriptor_set,
    format::HandleId                 descriptor_update_template,
    DescriptorUpdateTemplateDecoder* data)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_set);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_update_template);
    GFXRECON_UNREFERENCED_PARAMETER(data);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
