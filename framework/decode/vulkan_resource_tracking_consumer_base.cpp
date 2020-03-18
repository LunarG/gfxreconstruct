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

const std::vector<std::string> kLoaderLibNames = {
#if defined(WIN32)
    "vulkan-1.dll"
#else
    "libvulkan.so", "libvulkan.so.1"
#endif
};

VulkanResourceTrackingConsumerBase::VulkanResourceTrackingConsumerBase(const ReplayOptions& options) :
    options_(options), loader_handle_(nullptr), get_instance_proc_addr_(nullptr), create_instance_function_(nullptr)
{}

VulkanResourceTrackingConsumerBase::~VulkanResourceTrackingConsumerBase()
{
    if (loader_handle_ != nullptr)
    {
        util::platform::CloseLibrary(loader_handle_);
    }
}

void VulkanResourceTrackingConsumerBase::InitializeLoader()
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
        create_instance_function_ =
            reinterpret_cast<PFN_vkCreateInstance>(get_instance_proc_addr_(nullptr, "vkCreateInstance"));
    }

    if (create_instance_function_ == nullptr)
    {
        GFXRECON_LOG_FATAL("Failed to load Vulkan runtime library; please ensure that the path to the Vulkan "
                           "loader (eg. %s) has been added to the appropriate system path",
                           kLoaderLibNames[0].c_str());
    }
}

void VulkanResourceTrackingConsumerBase::AddInstanceTable(VkInstance instance)
{
    encode::DispatchKey dispatch_key = encode::GetDispatchKey(instance);

    get_device_proc_addrs_[dispatch_key] =
        reinterpret_cast<PFN_vkGetDeviceProcAddr>(get_instance_proc_addr_(instance, "vkGetDeviceProcAddr"));
    create_device_procs_[dispatch_key] =
        reinterpret_cast<PFN_vkCreateDevice>(get_instance_proc_addr_(instance, "vkCreateDevice"));

    encode::InstanceTable& table = instance_tables_[dispatch_key];
    encode::LoadInstanceTable(get_instance_proc_addr_, instance, &table);
}

void VulkanResourceTrackingConsumerBase::AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa)
{
    encode::DeviceTable& table = device_tables_[encode::GetDispatchKey(device)];
    encode::LoadDeviceTable(gpa, device, &table);
}

PFN_vkGetDeviceProcAddr VulkanResourceTrackingConsumerBase::GetDeviceAddrProc(VkPhysicalDevice physical_device)
{
    return get_device_proc_addrs_[encode::GetDispatchKey(physical_device)];
}

PFN_vkCreateDevice VulkanResourceTrackingConsumerBase::GetCreateDeviceProc(VkPhysicalDevice physical_device)
{
    return create_device_procs_[encode::GetDispatchKey(physical_device)];
}

const encode::InstanceTable* VulkanResourceTrackingConsumerBase::GetInstanceTable(const void* handle) const
{
    auto table = instance_tables_.find(encode::GetDispatchKey(handle));
    assert(table != instance_tables_.end());
    return (table != instance_tables_.end()) ? &table->second : nullptr;
}

const encode::DeviceTable* VulkanResourceTrackingConsumerBase::GetDeviceTable(const void* handle) const
{
    auto table = device_tables_.find(encode::GetDispatchKey(handle));
    assert(table != device_tables_.end());
    return (table != device_tables_.end()) ? &table->second : nullptr;
}

void VulkanResourceTrackingConsumerBase::OverrideCreateInstance(
    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkInstance>*                         pInstance)
{
    assert((pCreateInfo != nullptr) && (pInstance != nullptr) && (pInstance->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_instance    = pInstance->GetHandlePointer();

    if (loader_handle_ == nullptr)
    {
        InitializeLoader();
    }

    // TODO(gfxrec-28): Replace WSI extension in extension list??

    // TODO(gfxrec-28): Disable layers??

    VkResult result = create_instance_function_(replay_create_info, nullptr, replay_instance);

    if ((replay_instance != nullptr) && (result == VK_SUCCESS))
    {
        TrackedInstanceInfo instance_info;
        instance_info.SetCaptureId(*(pInstance->GetPointer()));
        instance_info.SetHandleId(*replay_instance);
        GetTrackedObjectInfoTable().AddTrackedInstanceInfo(std::move(instance_info));
        AddInstanceTable(*replay_instance);
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

    VkResult                result               = VK_ERROR_INITIALIZATION_FAILED;
    VkPhysicalDevice        physical_device      = physical_device_info->GetHandleId();
    PFN_vkGetDeviceProcAddr get_device_proc_addr = GetDeviceAddrProc(physical_device);
    PFN_vkCreateDevice      create_device_proc   = GetCreateDeviceProc(physical_device);

    if ((get_device_proc_addr != nullptr) && (create_device_proc != nullptr))
    {
        auto replay_create_info = pCreateInfo->GetPointer();
        auto replay_device      = pDevice->GetHandlePointer();

        result = create_device_proc(physical_device, replay_create_info, nullptr, replay_device);

        if ((replay_device != nullptr) && (result == VK_SUCCESS))
        {
            TrackedDeviceInfo device_info;

            device_info.SetParentPhysicalDevice(physical_device);

            device_info.SetCaptureId(*(pDevice->GetPointer()));
            device_info.SetHandleId(*(replay_device));

            // Get the memory proeprties for the current physical device.
            if (physical_device_info->GetReplayDevicePhysicalMemoryProperties()->memoryHeapCount == 0)
            {
                // Memory properties weren't queried before device creation, so retrieve them now.
                auto table = GetInstanceTable(physical_device);
                assert(table != nullptr);
                VkPhysicalDeviceMemoryProperties* physical_device_memory =
                    physical_device_info->GetReplayDevicePhysicalMemoryProperties();

                table->GetPhysicalDeviceMemoryProperties(physical_device, physical_device_memory);
            }

            device_info.SetCaptureDevicePhysicalMemoryProperties(
                physical_device_info->GetCaptureDevicePhysicalMemoryProperties());
            device_info.SetReplayDevicePhysicalMemoryProperties(
                physical_device_info->GetReplayDevicePhysicalMemoryProperties());

            GetTrackedObjectInfoTable().AddTrackedDeviceInfo(std::move(device_info));
            AddDeviceTable(*replay_device, get_device_proc_addr);
        }
    }
}

void VulkanResourceTrackingConsumerBase::OverrideEnumeratePhysicalDevices(
    format::HandleId                        instance,
    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices)
{
    auto instance_info = GetTrackedObjectInfoTable().GetTrackedInstanceInfo(instance);
    pPhysicalDeviceCount->AllocateOutputData(
        1, pPhysicalDeviceCount->IsNull() ? static_cast<uint32_t>(0) : (*pPhysicalDeviceCount->GetPointer()));

    std::vector<TrackedPhysicalDeviceInfo> handle_info(*(pPhysicalDeviceCount->GetOutputPointer()));

    assert((instance_info != nullptr) && (pPhysicalDeviceCount != nullptr) &&
           (pPhysicalDeviceCount->GetPointer() != nullptr) && (pPhysicalDevices != nullptr));

    VkInstance        instance_id         = instance_info->GetHandleId();
    uint32_t          replay_device_count = (*pPhysicalDeviceCount->GetPointer());
    VkPhysicalDevice* replay_devices      = pPhysicalDevices->GetHandlePointer();

    VkResult result = GetInstanceTable(instance_info->GetHandleId())
                          ->EnumeratePhysicalDevices(instance_id, &replay_device_count, replay_devices);

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
    TrackedResourceInfo buffer_info;

    assert((create_info != nullptr) && (buffer != nullptr) && (buffer->GetHandlePointer() != nullptr));

    auto buffer_create_info = create_info->GetPointer();
    auto replay_buffer      = buffer->GetHandlePointer();

    auto in_device = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);

    VkResult result = GetDeviceTable(in_device->GetHandleId())
                          ->CreateBuffer(in_device->GetHandleId(), buffer_create_info, nullptr, replay_buffer);

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
        buffer_info.SetBufferReplayHandleId(*replay_buffer);
        buffer_info.SetCaptureId(*(buffer->GetPointer()));
        GetTrackedObjectInfoTable().AddTrackedResourceInfo(std::move(buffer_info));
    }
}

void VulkanResourceTrackingConsumerBase::OverrideCreateImage(
    format::HandleId                                           device,
    const StructPointerDecoder<Decoded_VkImageCreateInfo>*     create_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
    HandlePointerDecoder<VkImage>*                             image)
{
    TrackedResourceInfo image_info;

    assert((create_info != nullptr) && (image != nullptr) && (image->GetHandlePointer() != nullptr));

    auto in_device = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);

    auto image_create_info = create_info->GetPointer();
    auto replay_image      = image->GetHandlePointer();

    VkResult result = GetDeviceTable(in_device->GetHandleId())
                          ->CreateImage(in_device->GetHandleId(), image_create_info, nullptr, replay_image);

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
        image_info.SetImageReplayHandleId(*replay_image);
        image_info.SetCaptureId(*(image->GetPointer()));
        image_info.SetImageFlag(true);
        GetTrackedObjectInfoTable().AddTrackedResourceInfo(std::move(image_info));
    }
}

void VulkanResourceTrackingConsumerBase::OverrideAllocateMemory(
    format::HandleId                                           device,
    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  allocate_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
    HandlePointerDecoder<VkDeviceMemory>*                      memory)
{
    auto                    device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    TrackedDeviceMemoryInfo memory_info;

    assert((allocate_info != nullptr) && (memory != nullptr) && (memory->GetHandlePointer() != nullptr));

    const VkMemoryAllocateInfo* replay_allocate_info = allocate_info->GetPointer();

    if (!options_.skip_failed_allocations)
    {
        auto replay_memory = memory->GetHandlePointer();

        if ((replay_allocate_info != nullptr) && ((*replay_memory) != VK_NULL_HANDLE))
        {
            memory_info.SetTraceMemoryAllocationSize(replay_allocate_info->allocationSize);
            memory_info.AllocateReplayMemoryAllocationSize(replay_allocate_info->allocationSize);
            auto replay_memory_properties = device_info->GetReplayDevicePhysicalMemoryProperties();
            assert(replay_allocate_info->memoryTypeIndex < replay_memory_properties->memoryTypeCount);

            memory_info.SetMemoryPropertyFlags(
                replay_memory_properties->memoryTypes[replay_allocate_info->memoryTypeIndex].propertyFlags);
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
    auto buffer_info = GetTrackedObjectInfoTable().GetTrackedResourceInfo(buffer);
    auto memory_info = GetTrackedObjectInfoTable().GetTrackedDeviceMemoryInfo(memory);

    assert((buffer_info != nullptr) && (memory_info != nullptr));

    buffer_info->SetBoundMemoryId(memory);
    buffer_info->SetTraceBindOffset(memory_offset);

    memory_info->InsertBoundResourcesList(*buffer_info);

    if ((buffer_info->GetBufferCreateInfo().usage & VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT))
    {
        VkMemoryPropertyFlags memory_property_flags = memory_info->GetMemoryPropertyFlags();
        if ((memory_property_flags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) == 0 ||
            (memory_property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == 0)
        {
            GFXRECON_LOG_FATAL("Uniform buffer should have device local and host visible bit available.");
        }
    }
}

void VulkanResourceTrackingConsumerBase::OverrideBindImageMemory(format::HandleId device,
                                                                 format::HandleId image,
                                                                 format::HandleId memory,
                                                                 VkDeviceSize     memory_offset)
{
    auto image_info  = GetTrackedObjectInfoTable().GetTrackedResourceInfo(image);
    auto memory_info = GetTrackedObjectInfoTable().GetTrackedDeviceMemoryInfo(memory);

    assert((image_info != nullptr) && (memory_info != nullptr));

    image_info->SetBoundMemoryId(memory);
    image_info->SetTraceBindOffset(memory_offset);

    memory_info->InsertBoundResourcesList(*image_info);
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
    VkMemoryPropertyFlags memory_property_flags = memory_info->GetMemoryPropertyFlags();
    if ((memory_property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == 0)
    {
        GFXRECON_LOG_FATAL("Host visible memory property is needed for a mappable memory.");
    }
}

void VulkanResourceTrackingConsumerBase::OverrideGetBufferMemoryRequirements(
    format::HandleId                                    device,
    format::HandleId                                    buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    auto device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    auto buffer_info = GetTrackedObjectInfoTable().GetTrackedResourceInfo(buffer);

    VkDevice              in_device               = device_info->GetHandleId();
    VkBuffer              in_buffer               = buffer_info->GetBufferReplayHandleId();
    VkMemoryRequirements* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetBufferMemoryRequirements(in_device, in_buffer, out_pMemoryRequirements);

    if (out_pMemoryRequirements != nullptr)
    {
        buffer_info->SetReplayResourceSize(out_pMemoryRequirements->size);
        buffer_info->SetReplayResourceAlignment(out_pMemoryRequirements->alignment);
        buffer_info->SetReplayResourceMemoryTypeBits(out_pMemoryRequirements->memoryTypeBits);
    }
}

void VulkanResourceTrackingConsumerBase::OverrideGetImageMemoryRequirements(
    format::HandleId                                    device,
    format::HandleId                                    image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    auto device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    auto image_info  = GetTrackedObjectInfoTable().GetTrackedResourceInfo(image);

    VkDevice              in_device               = device_info->GetHandleId();
    VkImage               in_image                = image_info->GetImageReplayHandleId();
    VkMemoryRequirements* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetImageMemoryRequirements(in_device, in_image, out_pMemoryRequirements);

    if (out_pMemoryRequirements != nullptr)
    {
        image_info->SetReplayResourceSize(out_pMemoryRequirements->size);
        image_info->SetReplayResourceAlignment(out_pMemoryRequirements->alignment);
        image_info->SetReplayResourceMemoryTypeBits(out_pMemoryRequirements->memoryTypeBits);
    }
}

void VulkanResourceTrackingConsumerBase::OverrideDestroyInstance(
    format::HandleId instance, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto       instance_info = GetTrackedObjectInfoTable().GetTrackedInstanceInfo(instance);
    VkInstance in_instance   = instance_info->GetHandleId();

    GetInstanceTable(in_instance)->DestroyInstance(in_instance, nullptr);
}

void VulkanResourceTrackingConsumerBase::OverrideDestroyDevice(
    format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto     device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    VkDevice in_device   = device_info->GetHandleId();

    GetDeviceTable(in_device)->DestroyDevice(in_device, nullptr);
}

void VulkanResourceTrackingConsumerBase::OverrideDestroyBuffer(
    format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto     device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    auto     buffer_info = GetTrackedObjectInfoTable().GetTrackedResourceInfo(buffer);
    VkDevice in_device   = device_info->GetHandleId();
    VkBuffer in_buffer   = buffer_info->GetBufferReplayHandleId();

    GetDeviceTable(in_device)->DestroyBuffer(in_device, in_buffer, nullptr);
}

void VulkanResourceTrackingConsumerBase::OverrideDestroyImage(
    format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto     device_info = GetTrackedObjectInfoTable().GetTrackedDeviceInfo(device);
    auto     image_info  = GetTrackedObjectInfoTable().GetTrackedResourceInfo(image);
    VkDevice in_device   = device_info->GetHandleId();
    VkImage  in_image    = image_info->GetImageReplayHandleId();

    GetDeviceTable(in_device)->DestroyImage(in_device, in_image, nullptr);
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

// Util function for sorting: compares two resources according to the trace binding offset number.
bool CompareOffset(TrackedResourceInfo resource1, TrackedResourceInfo resource2)
{
    return (resource1.GetTraceBindOffset() < resource2.GetTraceBindOffset());
}

// Sort the bound resources in each device memory object according to their trace binding offset.
void VulkanResourceTrackingConsumerBase::SortMemoriesBoundResourcesByOffset()
{
    auto tracked_device_memories_map = GetTrackedObjectInfoTable().GetTrackedDeviceMemoriesInfoMap();
    assert(tracked_device_memories_map != nullptr);

    for (auto& iterator : (*tracked_device_memories_map))
    {
        TrackedDeviceMemoryInfo tracked_device_memory = iterator.second;

        std::vector<TrackedResourceInfo>* resources = tracked_device_memory.GetBoundResourcesList();

        if (resources != nullptr)
        {
            std::sort(resources->begin(), resources->end(), CompareOffset);
        }

        iterator.second = tracked_device_memory;
    }
}

// TODO(gfxrec-28): split this function into smaller utility functions
// Calculate the replay binding offset and memory allocation size
void VulkanResourceTrackingConsumerBase::CalculateReplayBindingOffsetAndMemoryAllocationSize()
{
    auto tracked_device_memories_map = GetTrackedObjectInfoTable().GetTrackedDeviceMemoriesInfoMap();
    assert(tracked_device_memories_map != nullptr);

    for (auto& iterator : (*tracked_device_memories_map))
    {
        TrackedDeviceMemoryInfo tracked_device_memory = iterator.second;

        std::vector<TrackedResourceInfo>* resources = tracked_device_memory.GetBoundResourcesList();

        // set the replay binding offset for first resource element to be same as trace offset
        // and recalculate the replay binding offset base on replay alignment requirement
        VkDeviceSize replay_bind_offset = (*resources)[0].GetTraceBindOffset();
        if ((*resources)[0].GetReplayResourceAlignment() > 0)
        {
            VkDeviceSize alignment_remainder = replay_bind_offset % (*resources)[0].GetReplayResourceAlignment();
            if (alignment_remainder != 0)
            {
                while ((replay_bind_offset % (*resources)[0].GetReplayResourceAlignment()) != 0)
                {
                    // increment offset and new memory allocation size until it aligned
                    replay_bind_offset++;
                }
            }
        }
        (*resources)[0].SetReplayBindOffset(replay_bind_offset);

        if (replay_bind_offset != (*resources)[0].GetTraceBindOffset())
        {
            GFXRECON_LOG_INFO("Trace binding offset has been recalculated and updated during replay.")
        }

        // update replay memory allocation size based on replay binding offset and size
        VkDeviceSize replay_memory_allocation_size =
            std::max(tracked_device_memory.GetReplayMemoryAllocationSize(),
                     replay_bind_offset + (*resources)[0].GetReplayResourceSize());
        tracked_device_memory.AllocateReplayMemoryAllocationSize(replay_memory_allocation_size);

        // loop through the rest of the resources elements to make sure no overlap with the previous one
        for (size_t i = 1; i < (*resources).size(); i++)
        {
            size_t previous_resource_index             = i - 1;
            replay_bind_offset                         = (*resources)[i].GetTraceBindOffset();
            VkDeviceSize previous_replay_bind_offset   = (*resources)[previous_resource_index].GetReplayBindOffset();
            VkDeviceSize previous_replay_resource_size = (*resources)[previous_resource_index].GetReplayResourceSize();
            // increment to avoid offset with previous resource
            while (replay_bind_offset >= previous_replay_bind_offset &&
                   replay_bind_offset <= previous_replay_bind_offset + previous_replay_resource_size)
            {
                replay_bind_offset++;
            }

            // recalculate base on replay alignment
            if ((*resources)[i].GetReplayResourceAlignment() > 0)
            {
                VkDeviceSize alignment_remainder = replay_bind_offset % (*resources)[i].GetReplayResourceAlignment();
                if (alignment_remainder != 0)
                {
                    while ((replay_bind_offset % (*resources)[i].GetReplayResourceAlignment()) != 0)
                    {
                        // increment offset and new memory allocation size until it aligned
                        replay_bind_offset++;
                    }
                }
            }
            (*resources)[i].SetReplayBindOffset(replay_bind_offset);

            if (replay_bind_offset != (*resources)[i].GetTraceBindOffset())
            {
                GFXRECON_LOG_INFO("Trace binding offset has been recalculated and updated during replay.")
            }

            // update replay memory allocation size based on replay binding offset and size
            VkDeviceSize replay_memory_allocation_size =
                std::max(tracked_device_memory.GetReplayMemoryAllocationSize(),
                         replay_bind_offset + (*resources)[i].GetReplayResourceSize());
            tracked_device_memory.AllocateReplayMemoryAllocationSize(replay_memory_allocation_size);
        }

        iterator.second = tracked_device_memory;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
