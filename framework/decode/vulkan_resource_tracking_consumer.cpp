/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/vulkan_resource_tracking_consumer.h"

#include <algorithm>
#include <cassert>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const std::vector<std::string> kLoaderLibNames = {
#if defined(WIN32)
    "vulkan-1.dll"
#else
    "libvulkan.so", "libvulkan.so.1"
#endif
};

VulkanResourceTrackingConsumer::VulkanResourceTrackingConsumer(
    const ReplayOptions& options, VulkanTrackedObjectInfoTable* tracked_object_info_table) :
    options_(options),
    loader_handle_(nullptr), get_instance_proc_addr_(nullptr), create_instance_function_(nullptr),
    tracked_object_info_table_(tracked_object_info_table)
{
    assert(tracked_object_info_table != nullptr);
}

VulkanResourceTrackingConsumer::~VulkanResourceTrackingConsumer()
{
    if (loader_handle_ != nullptr)
    {
        util::platform::CloseLibrary(loader_handle_);
    }
}

void VulkanResourceTrackingConsumer::InitializeLoader()
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

void VulkanResourceTrackingConsumer::AddInstanceTable(VkInstance instance)
{
    encode::DispatchKey dispatch_key = encode::GetDispatchKey(instance);

    get_device_proc_addrs_[dispatch_key] =
        reinterpret_cast<PFN_vkGetDeviceProcAddr>(get_instance_proc_addr_(instance, "vkGetDeviceProcAddr"));
    create_device_procs_[dispatch_key] =
        reinterpret_cast<PFN_vkCreateDevice>(get_instance_proc_addr_(instance, "vkCreateDevice"));

    encode::InstanceTable& table = instance_tables_[dispatch_key];
    encode::LoadInstanceTable(get_instance_proc_addr_, instance, &table);
}

void VulkanResourceTrackingConsumer::AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa)
{
    encode::DeviceTable& table = device_tables_[encode::GetDispatchKey(device)];
    encode::LoadDeviceTable(gpa, device, &table);
}

PFN_vkGetDeviceProcAddr VulkanResourceTrackingConsumer::GetDeviceAddrProc(VkPhysicalDevice physical_device)
{
    return get_device_proc_addrs_[encode::GetDispatchKey(physical_device)];
}

PFN_vkCreateDevice VulkanResourceTrackingConsumer::GetCreateDeviceProc(VkPhysicalDevice physical_device)
{
    return create_device_procs_[encode::GetDispatchKey(physical_device)];
}

const encode::InstanceTable* VulkanResourceTrackingConsumer::GetInstanceTable(const void* handle) const
{
    auto table = instance_tables_.find(encode::GetDispatchKey(handle));
    assert(table != instance_tables_.end());
    return (table != instance_tables_.end()) ? &table->second : nullptr;
}

const encode::DeviceTable* VulkanResourceTrackingConsumer::GetDeviceTable(const void* handle) const
{
    auto table = device_tables_.find(encode::GetDispatchKey(handle));
    assert(table != device_tables_.end());
    return (table != device_tables_.end()) ? &table->second : nullptr;
}

void VulkanResourceTrackingConsumer::Process_vkCreateInstance(
    VkResult                                             returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*                    pInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((pCreateInfo != nullptr) && (pInstance != nullptr));

    if (!pInstance->IsNull())
    {
        pInstance->SetHandleLength(1);
    }

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_instance    = pInstance->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_instance != nullptr));

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
        GetTrackedObjectInfoTable()->AddTrackedInstanceInfo(std::move(instance_info));
        AddInstanceTable(*replay_instance);
    }
}

void VulkanResourceTrackingConsumer::Process_vkCreateDevice(
    VkResult                                             returnValue,
    format::HandleId                                     physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*                      pDevice)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((pCreateInfo != nullptr) && (pDevice != nullptr));

    if (!pDevice->IsNull())
    {
        pDevice->SetHandleLength(1);
    }

    auto physical_device_info = GetTrackedObjectInfoTable()->GetTrackedPhysicalDeviceInfo(physicalDevice);
    assert(physical_device_info != nullptr);

    VkResult                result               = VK_ERROR_INITIALIZATION_FAILED;
    VkPhysicalDevice        physical_device      = physical_device_info->GetHandleId();
    PFN_vkGetDeviceProcAddr get_device_proc_addr = GetDeviceAddrProc(physical_device);
    PFN_vkCreateDevice      create_device_proc   = GetCreateDeviceProc(physical_device);

    if ((get_device_proc_addr != nullptr) && (create_device_proc != nullptr))
    {
        auto replay_create_info = pCreateInfo->GetPointer();
        auto replay_device      = pDevice->GetHandlePointer();
        assert((replay_create_info != nullptr) && (replay_device != nullptr));

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

            GetTrackedObjectInfoTable()->AddTrackedDeviceInfo(std::move(device_info));
            AddDeviceTable(*replay_device, get_device_proc_addr);
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to create device during resource tracking. Replay cannot continue.");
        }
    }
}

void VulkanResourceTrackingConsumer::Process_vkEnumeratePhysicalDevices(
    VkResult                                returnValue,
    format::HandleId                        instance,
    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    auto instance_info = GetTrackedObjectInfoTable()->GetTrackedInstanceInfo(instance);
    pPhysicalDeviceCount->AllocateOutputData(
        1, pPhysicalDeviceCount->IsNull() ? static_cast<uint32_t>(0) : (*pPhysicalDeviceCount->GetPointer()));
    if (!pPhysicalDevices->IsNull())
    {
        pPhysicalDevices->SetHandleLength(*pPhysicalDeviceCount->GetOutputPointer());
    }

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
                GetTrackedObjectInfoTable()->AddTrackedPhysicalDeviceInfo(std::move(*info_iterator));
            }
        }
    }
}

void VulkanResourceTrackingConsumer::Process_vkCreateBuffer(
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>*    create_info,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
    HandlePointerDecoder<VkBuffer>*                      buffer)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((create_info != nullptr) && (buffer != nullptr));

    if (!buffer->IsNull())
    {
        buffer->SetHandleLength(1);
    }

    auto buffer_create_info = create_info->GetPointer();
    auto replay_buffer      = buffer->GetHandlePointer();
    assert((buffer_create_info != nullptr) && (replay_buffer != nullptr));

    auto in_device = GetTrackedObjectInfoTable()->GetTrackedDeviceInfo(device);

    VkResult result = GetDeviceTable(in_device->GetHandleId())
                          ->CreateBuffer(in_device->GetHandleId(), buffer_create_info, nullptr, replay_buffer);

    if ((result == VK_SUCCESS) && (buffer_create_info != nullptr) && ((*replay_buffer) != VK_NULL_HANDLE))
    {
        TrackedResourceInfo buffer_info;

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
        GetTrackedObjectInfoTable()->AddTrackedResourceInfo(std::move(buffer_info));
    }
}

void VulkanResourceTrackingConsumer::Process_vkCreateImage(
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>*     create_info,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
    HandlePointerDecoder<VkImage>*                       image)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((create_info != nullptr) && (image != nullptr));

    if (!image->IsNull())
    {
        image->SetHandleLength(1);
    }

    auto in_device = GetTrackedObjectInfoTable()->GetTrackedDeviceInfo(device);

    auto image_create_info = create_info->GetPointer();
    auto replay_image      = image->GetHandlePointer();
    assert((image_create_info != nullptr) && (replay_image != nullptr));

    VkResult result = GetDeviceTable(in_device->GetHandleId())
                          ->CreateImage(in_device->GetHandleId(), image_create_info, nullptr, replay_image);

    if ((result == VK_SUCCESS) && (image_create_info != nullptr) && ((*replay_image) != VK_NULL_HANDLE))
    {
        TrackedResourceInfo image_info;

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
        GetTrackedObjectInfoTable()->AddTrackedResourceInfo(std::move(image_info));
    }
}

void VulkanResourceTrackingConsumer::Process_vkAllocateMemory(
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  allocate_info,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
    HandlePointerDecoder<VkDeviceMemory>*                memory)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    auto                    device_info = GetTrackedObjectInfoTable()->GetTrackedDeviceInfo(device);
    TrackedDeviceMemoryInfo memory_info;

    assert((allocate_info != nullptr) && (memory != nullptr));

    if (!memory->IsNull())
    {
        memory->SetHandleLength(1);
    }

    if (!options_.skip_failed_allocations)
    {
        const VkMemoryAllocateInfo* replay_allocate_info = allocate_info->GetPointer();
        auto                        replay_memory        = memory->GetHandlePointer();
        assert((replay_allocate_info != nullptr) && (replay_memory != nullptr));

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
    GetTrackedObjectInfoTable()->AddTrackedDeviceMemoryInfo(std::move(memory_info));
}

void VulkanResourceTrackingConsumer::Process_vkBindBufferMemory(VkResult         returnValue,
                                                                format::HandleId device,
                                                                format::HandleId buffer,
                                                                format::HandleId memory,
                                                                VkDeviceSize     memory_offset)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    auto buffer_info = GetTrackedObjectInfoTable()->GetTrackedResourceInfo(buffer);
    auto memory_info = GetTrackedObjectInfoTable()->GetTrackedDeviceMemoryInfo(memory);

    assert((buffer_info != nullptr) && (memory_info != nullptr));

    buffer_info->SetBoundMemoryId(memory);
    buffer_info->SetTraceBindOffset(memory_offset);

    // no call to getbuffermemoryrequirement made prior to this,
    // make the getbuffermemoryrequirement call to get the replay size.
    if (buffer_info->GetReplayResourceSize() == 0)
    {
        Process_vkGetBufferMemoryRequirements(device, buffer, nullptr);
    }

    memory_info->InsertBoundResourcesList(buffer_info);
}

void VulkanResourceTrackingConsumer::Process_vkBindImageMemory(VkResult         returnValue,
                                                               format::HandleId device,
                                                               format::HandleId image,
                                                               format::HandleId memory,
                                                               VkDeviceSize     memory_offset)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    auto image_info  = GetTrackedObjectInfoTable()->GetTrackedResourceInfo(image);
    auto memory_info = GetTrackedObjectInfoTable()->GetTrackedDeviceMemoryInfo(memory);

    assert((image_info != nullptr) && (memory_info != nullptr));

    image_info->SetBoundMemoryId(memory);
    image_info->SetTraceBindOffset(memory_offset);

    // no call to getimagememoryrequirement made prior to this,
    // make the getimagememoryrequirement call to get the replay size.
    if (image_info->GetReplayResourceSize() == 0)
    {
        Process_vkGetImageMemoryRequirements(device, image, nullptr);
    }

    memory_info->InsertBoundResourcesList(image_info);
}

void VulkanResourceTrackingConsumer::Process_vkBindBufferMemory2(
    VkResult                                              returnValue,
    format::HandleId                                      device,
    uint32_t                                              bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    auto tracked_device_info = GetTrackedObjectInfoTable()->GetTrackedDeviceInfo(device);

    assert((pBindInfos != nullptr) && (tracked_device_info != nullptr));

    const VkBindBufferMemoryInfo*         replay_bind_infos      = pBindInfos->GetPointer();
    const Decoded_VkBindBufferMemoryInfo* replay_bind_meta_infos = pBindInfos->GetMetaStructPointer();
    assert((replay_bind_infos != nullptr) && (replay_bind_meta_infos != nullptr));

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        const Decoded_VkBindBufferMemoryInfo* bind_meta_info = &replay_bind_meta_infos[i];

        auto buffer_info = GetTrackedObjectInfoTable()->GetTrackedResourceInfo(bind_meta_info->buffer);
        auto memory_info = GetTrackedObjectInfoTable()->GetTrackedDeviceMemoryInfo(bind_meta_info->memory);

        assert((buffer_info != nullptr) && (memory_info != nullptr));

        buffer_info->SetBoundMemoryId(bind_meta_info->memory);
        buffer_info->SetTraceBindOffset(replay_bind_infos[i].memoryOffset);

        // no call to getbuffermemoryrequirement made prior to this,
        // make the getbuffermemoryrequirement call to get the replay size.
        if (buffer_info->GetReplayResourceSize() == 0)
        {
            Process_vkGetBufferMemoryRequirements(device, bind_meta_info->buffer, nullptr);
        }

        memory_info->InsertBoundResourcesList(buffer_info);
    }
}

void VulkanResourceTrackingConsumer::Process_vkBindImageMemory2(
    VkResult                                             returnValue,
    format::HandleId                                     device,
    uint32_t                                             bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    auto tracked_device_info = GetTrackedObjectInfoTable()->GetTrackedDeviceInfo(device);

    assert((pBindInfos != nullptr) && (tracked_device_info != nullptr));

    const VkBindImageMemoryInfo*         replay_bind_infos      = pBindInfos->GetPointer();
    const Decoded_VkBindImageMemoryInfo* replay_bind_meta_infos = pBindInfos->GetMetaStructPointer();
    assert((replay_bind_infos != nullptr) && (replay_bind_meta_infos != nullptr));

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        const Decoded_VkBindImageMemoryInfo* bind_meta_info = &replay_bind_meta_infos[i];

        auto image_info  = GetTrackedObjectInfoTable()->GetTrackedResourceInfo(bind_meta_info->image);
        auto memory_info = GetTrackedObjectInfoTable()->GetTrackedDeviceMemoryInfo(bind_meta_info->memory);

        assert((image_info != nullptr) && (memory_info != nullptr));

        image_info->SetBoundMemoryId(bind_meta_info->memory);
        image_info->SetTraceBindOffset(replay_bind_infos[i].memoryOffset);

        // no call to getimagememoryrequirement made prior to this,
        // make the getimagememoryrequirement call to get the replay size.
        if (image_info->GetReplayResourceSize() == 0)
        {
            Process_vkGetImageMemoryRequirements(device, bind_meta_info->image, nullptr);
        }

        memory_info->InsertBoundResourcesList(image_info);
    }
}

void VulkanResourceTrackingConsumer::Process_vkMapMemory(VkResult                         returnValue,
                                                         format::HandleId                 device,
                                                         format::HandleId                 memory,
                                                         VkDeviceSize                     offset,
                                                         VkDeviceSize                     size,
                                                         VkMemoryMapFlags                 flags,
                                                         PointerDecoder<uint64_t, void*>* data_pointer)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    auto memory_info = GetTrackedObjectInfoTable()->GetTrackedDeviceMemoryInfo(memory);

    assert((memory_info != nullptr));

    memory_info->InsertMappedMemoryOffsetsList(offset);
    memory_info->InsertMappedMemorySizesList(size);
}

void VulkanResourceTrackingConsumer::Process_vkGetBufferMemoryRequirements(
    format::HandleId                                    device,
    format::HandleId                                    buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    auto device_info = GetTrackedObjectInfoTable()->GetTrackedDeviceInfo(device);
    auto buffer_info = GetTrackedObjectInfoTable()->GetTrackedResourceInfo(buffer);

    // retrieve trace buffer memory requirements
    if (pMemoryRequirements != nullptr)
    {
        Decoded_VkMemoryRequirements* decoded_buffer_memory_requirements = pMemoryRequirements->GetMetaStructPointer();
        if (decoded_buffer_memory_requirements != nullptr)
        {
            VkMemoryRequirements* trace_buffer_memory_requirements = decoded_buffer_memory_requirements->decoded_value;
            if (trace_buffer_memory_requirements != nullptr)
            {
                buffer_info->SetTraceResourceSize(trace_buffer_memory_requirements->size);
                buffer_info->SetTraceResourceAlignment(trace_buffer_memory_requirements->alignment);
                buffer_info->SetTraceResourceMemoryTypeBits(trace_buffer_memory_requirements->memoryTypeBits);
            }
        }
    }

    // get replay buffer memory requirements
    VkDevice              in_device               = device_info->GetHandleId();
    VkBuffer              in_buffer               = buffer_info->GetBufferReplayHandleId();
    VkMemoryRequirements* out_pMemoryRequirements = nullptr;
    VkMemoryRequirements  memory_requirement;
    if (pMemoryRequirements != nullptr)
    {
        out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1);
    }
    else
    {
        out_pMemoryRequirements = &memory_requirement;
    }

    GetDeviceTable(in_device)->GetBufferMemoryRequirements(in_device, in_buffer, out_pMemoryRequirements);

    if (out_pMemoryRequirements != nullptr)
    {
        buffer_info->SetReplayResourceSize(out_pMemoryRequirements->size);
        buffer_info->SetReplayResourceAlignment(out_pMemoryRequirements->alignment);
        buffer_info->SetReplayResourceMemoryTypeBits(out_pMemoryRequirements->memoryTypeBits);
    }
}

void VulkanResourceTrackingConsumer::Process_vkGetImageMemoryRequirements(
    format::HandleId                                    device,
    format::HandleId                                    image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    auto device_info = GetTrackedObjectInfoTable()->GetTrackedDeviceInfo(device);
    auto image_info  = GetTrackedObjectInfoTable()->GetTrackedResourceInfo(image);

    // retrieve trace image memory requirements
    if (pMemoryRequirements != nullptr)
    {
        Decoded_VkMemoryRequirements* decoded_image_memory_requirements = pMemoryRequirements->GetMetaStructPointer();
        if (decoded_image_memory_requirements != nullptr)
        {
            VkMemoryRequirements* trace_image_memory_requirements = decoded_image_memory_requirements->decoded_value;
            if (trace_image_memory_requirements != nullptr)
            {
                image_info->SetTraceResourceSize(trace_image_memory_requirements->size);
                image_info->SetTraceResourceAlignment(trace_image_memory_requirements->alignment);
                image_info->SetTraceResourceMemoryTypeBits(trace_image_memory_requirements->memoryTypeBits);
            }
        }
    }

    // get replay image memory requirement
    VkDevice              in_device               = device_info->GetHandleId();
    VkImage               in_image                = image_info->GetImageReplayHandleId();
    VkMemoryRequirements* out_pMemoryRequirements = nullptr;
    VkMemoryRequirements  memory_requirement;
    if (pMemoryRequirements != nullptr)
    {
        out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1);
    }
    else
    {
        out_pMemoryRequirements = &memory_requirement;
    }

    GetDeviceTable(in_device)->GetImageMemoryRequirements(in_device, in_image, out_pMemoryRequirements);

    if (out_pMemoryRequirements != nullptr)
    {
        image_info->SetReplayResourceSize(out_pMemoryRequirements->size);
        image_info->SetReplayResourceAlignment(out_pMemoryRequirements->alignment);
        image_info->SetReplayResourceMemoryTypeBits(out_pMemoryRequirements->memoryTypeBits);
    }
}

void VulkanResourceTrackingConsumer::Process_vkDestroyInstance(
    format::HandleId instance, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto       instance_info = GetTrackedObjectInfoTable()->GetTrackedInstanceInfo(instance);
    VkInstance in_instance   = instance_info->GetHandleId();

    GetInstanceTable(in_instance)->DestroyInstance(in_instance, nullptr);
}

void VulkanResourceTrackingConsumer::Process_vkDestroyDevice(
    format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto     device_info = GetTrackedObjectInfoTable()->GetTrackedDeviceInfo(device);
    VkDevice in_device   = device_info->GetHandleId();

    GetDeviceTable(in_device)->DestroyDevice(in_device, nullptr);
}

void VulkanResourceTrackingConsumer::Process_vkDestroyBuffer(
    format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto     device_info = GetTrackedObjectInfoTable()->GetTrackedDeviceInfo(device);
    auto     buffer_info = GetTrackedObjectInfoTable()->GetTrackedResourceInfo(buffer);
    VkDevice in_device   = device_info->GetHandleId();
    VkBuffer in_buffer   = buffer_info->GetBufferReplayHandleId();

    GetDeviceTable(in_device)->DestroyBuffer(in_device, in_buffer, nullptr);
}

void VulkanResourceTrackingConsumer::Process_vkDestroyImage(
    format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto     device_info = GetTrackedObjectInfoTable()->GetTrackedDeviceInfo(device);
    auto     image_info  = GetTrackedObjectInfoTable()->GetTrackedResourceInfo(image);
    VkDevice in_device   = device_info->GetHandleId();
    VkImage  in_image    = image_info->GetImageReplayHandleId();

    GetDeviceTable(in_device)->DestroyImage(in_device, in_image, nullptr);
}

void VulkanResourceTrackingConsumer::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                              uint64_t       offset,
                                                              uint64_t       size,
                                                              const uint8_t* data)
{
    auto memory_info = GetTrackedObjectInfoTable()->GetTrackedDeviceMemoryInfo(memory_id);

    assert((memory_info != nullptr));

    memory_info->InsertFilledMemoryOffsetsList(offset);
    memory_info->InsertFilledMemorySizesList(size);
}

// Util function for sorting: compares two resources according to the trace binding offset number.
bool CompareOffset(TrackedResourceInfo* resource1, TrackedResourceInfo* resource2)
{
    return (resource1->GetTraceBindOffset() < resource2->GetTraceBindOffset());
}

// Sort the bound resources in each device memory object according to their trace binding offset.
void VulkanResourceTrackingConsumer::SortMemoriesBoundResourcesByOffset()
{
    auto tracked_device_memories_map = GetTrackedObjectInfoTable()->GetTrackedDeviceMemoriesInfoMap();
    assert(tracked_device_memories_map != nullptr);

    for (auto& iterator : (*tracked_device_memories_map))
    {
        TrackedDeviceMemoryInfo tracked_device_memory = iterator.second;

        std::vector<TrackedResourceInfo*>* resources = tracked_device_memory.GetBoundResourcesList();

        if (resources != nullptr)
        {
            std::sort(resources->begin(), resources->end(), CompareOffset);
        }

        iterator.second = tracked_device_memory;
    }
}

// TODO(gfxrec-28): split this function into smaller utility functions
// Calculate the replay binding offset and memory allocation size
void VulkanResourceTrackingConsumer::CalculateReplayBindingOffsetAndMemoryAllocationSize()
{
    auto tracked_device_memories_map = GetTrackedObjectInfoTable()->GetTrackedDeviceMemoriesInfoMap();
    assert(tracked_device_memories_map != nullptr);

    for (auto& iterator : (*tracked_device_memories_map))
    {
        TrackedDeviceMemoryInfo tracked_device_memory = iterator.second;

        std::vector<TrackedResourceInfo*>* resources = tracked_device_memory.GetBoundResourcesList();

        if ((*resources).empty() == false)
        {
            // recalculate the replay binding offset by looping through the sorted bound resources
            // and update the replay binding offset based on the memory alignment requirement
            // and check for no/partial/complete overlap with previous bound resource memory
            // during trace and update the replay binding offset  and then memory allocation size
            // accordingly.

            VkDeviceSize replay_bind_offset = (*resources)[0]->GetTraceBindOffset();

            // loop through the bound resources and update replay resource binding offset
            // based on the memory alignment requirement and update memory allocation size
            for (size_t i = 0; i < (*resources).size(); i++)
            {
                // assign replay bind offset to be the same as trace offset first
                replay_bind_offset = (*resources)[i]->GetTraceBindOffset();

                // make sure the assigned replay bind offset have the same alignment count as trace bind offset
                // if trace alignment number is valid
                VkDeviceSize current_trace_bind_offset        = (*resources)[i]->GetTraceBindOffset();
                VkDeviceSize current_trace_resource_alignment = (*resources)[i]->GetTraceResourceAlignment();
                if (current_trace_resource_alignment > 0)
                {
                    VkDeviceSize trace_bind_alignment_count =
                        current_trace_bind_offset / current_trace_resource_alignment;
                    replay_bind_offset = (*resources)[i]->GetReplayResourceAlignment() * trace_bind_alignment_count;
                }

                // than check for no/partial/complete overlap case for bound resources
                if (i != 0)
                {
                    size_t       previous_resource_index = i - 1;
                    VkDeviceSize previous_trace_bind_offset =
                        (*resources)[previous_resource_index]->GetTraceBindOffset();
                    VkDeviceSize previous_trace_size = (*resources)[previous_resource_index]->GetTraceResourceSize();

                    // check for complete overlap
                    if (current_trace_bind_offset == previous_trace_bind_offset)
                    {
                        replay_bind_offset = (*resources)[previous_resource_index]->GetReplayBindOffset();
                    }
                    // check for no/partial overlap
                    else
                    {
                        // The check only valid when the app calls getimage/buffer memory requirements
                        // during trace (trace size is valid number > 0)
                        if (previous_trace_size > 0)
                        {
                            // check for no overlap: if no overlap during trace,
                            // update replay binding offset to be no overlap as well.
                            if (current_trace_bind_offset > previous_trace_bind_offset + previous_trace_size)
                            {
                                VkDeviceSize diff =
                                    current_trace_bind_offset - (previous_trace_bind_offset + previous_trace_size);
                                // increment to avoid overlap with previous resources
                                VkDeviceSize previous_replay_bind_offset =
                                    (*resources)[previous_resource_index]->GetReplayBindOffset();
                                VkDeviceSize previous_replay_resource_size =
                                    (*resources)[previous_resource_index]->GetReplayResourceSize();
                                replay_bind_offset = previous_replay_bind_offset + previous_replay_resource_size + diff;
                            }
                            // check for partial overlap: if partial overlap during trace,
                            // update replay binding offset to be partial overlap as well.
                            else if ((current_trace_bind_offset > previous_trace_bind_offset) &&
                                     (current_trace_bind_offset < previous_trace_bind_offset + previous_trace_size))
                            {
                                VkDeviceSize diff = current_trace_bind_offset - previous_trace_bind_offset;
                                // increment to avoid overlap with previous resources
                                VkDeviceSize previous_replay_bind_offset =
                                    (*resources)[previous_resource_index]->GetReplayBindOffset();
                                replay_bind_offset = previous_replay_bind_offset + diff;
                            }
                        }
                    }
                }

                // make sure the replay binding offset number fulfills the replay alignment requirement
                if ((*resources)[i]->GetReplayResourceAlignment() > 0)
                {
                    VkDeviceSize alignment_remainder =
                        replay_bind_offset % (*resources)[i]->GetReplayResourceAlignment();
                    if (alignment_remainder != 0)
                    {
                        while ((replay_bind_offset % (*resources)[i]->GetReplayResourceAlignment()) != 0)
                        {
                            // increment offset and new memory allocation size until it aligned
                            replay_bind_offset++;
                        }
                    }
                }
                (*resources)[i]->SetReplayBindOffset(replay_bind_offset);

                // update replay memory allocation size based on replay binding offset and size
                VkDeviceSize replay_memory_allocation_size =
                    std::max(tracked_device_memory.GetReplayMemoryAllocationSize(),
                             replay_bind_offset + (*resources)[i]->GetReplayResourceSize());
                tracked_device_memory.AllocateReplayMemoryAllocationSize(replay_memory_allocation_size);
            }

            iterator.second = tracked_device_memory;
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
