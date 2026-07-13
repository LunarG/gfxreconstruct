/*
** Copyright (c) 2020-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/vulkan_resource_tracking_consumer.h"

#include <algorithm>
#include <cassert>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const std::vector<std::string> kLoaderLibNames = {
#if defined(_WIN32)
    "vulkan-1.dll"
#elif defined(__APPLE__)
    "libvulkan.dylib", "libvulkan.1.dylib", "libMoltenVK.dylib"
#else
    "libvulkan.so", "libvulkan.so.1"
#endif
};

VulkanResourceTrackingConsumer::VulkanResourceTrackingConsumer(
    const VulkanReplayOptions& options, VulkanTrackedObjectInfoTable* tracked_object_info_table) :
    loader_handle_(nullptr),
    create_instance_function_(nullptr), get_instance_proc_addr_(nullptr), options_(options),
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
    graphics::VulkanDispatchKey dispatch_key = graphics::GetVulkanDispatchKey(instance);

    get_device_proc_addrs_[dispatch_key] =
        reinterpret_cast<PFN_vkGetDeviceProcAddr>(get_instance_proc_addr_(instance, "vkGetDeviceProcAddr"));
    create_device_procs_[dispatch_key] =
        reinterpret_cast<PFN_vkCreateDevice>(get_instance_proc_addr_(instance, "vkCreateDevice"));

    graphics::VulkanInstanceTable& table = instance_tables_[dispatch_key];
    graphics::LoadVulkanInstanceTable(get_instance_proc_addr_, instance, &table);
}

void VulkanResourceTrackingConsumer::AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa)
{
    graphics::VulkanDeviceTable& table = device_tables_[graphics::GetVulkanDispatchKey(device)];
    graphics::LoadVulkanDeviceTable(gpa, device, &table);
}

PFN_vkGetDeviceProcAddr VulkanResourceTrackingConsumer::GetDeviceAddrProc(VkPhysicalDevice physical_device)
{
    return get_device_proc_addrs_[graphics::GetVulkanDispatchKey(physical_device)];
}

PFN_vkCreateDevice VulkanResourceTrackingConsumer::GetCreateDeviceProc(VkPhysicalDevice physical_device)
{
    return create_device_procs_[graphics::GetVulkanDispatchKey(physical_device)];
}

const graphics::VulkanInstanceTable* VulkanResourceTrackingConsumer::GetInstanceTable(const void* handle) const
{
    auto table = instance_tables_.find(graphics::GetVulkanDispatchKey(handle));
    assert(table != instance_tables_.end());
    return (table != instance_tables_.end()) ? &table->second : nullptr;
}

const graphics::VulkanDeviceTable* VulkanResourceTrackingConsumer::GetDeviceTable(const void* handle) const
{
    auto table = device_tables_.find(graphics::GetVulkanDispatchKey(handle));
    assert(table != device_tables_.end());
    return (table != device_tables_.end()) ? &table->second : nullptr;
}

void VulkanResourceTrackingConsumer::Process_vkCreateInstance(const ApiCallInfo& call_info, args::CreateInstance& args)
{
    if (!args.pInstance.IsNull())
    {
        args.pInstance.SetHandleLength(1);
    }

    auto replay_create_info = args.pCreateInfo.GetPointer();
    auto replay_instance    = args.pInstance.GetHandlePointer();
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
        TrackedVkInstanceInfo instance_info;
        instance_info.SetCaptureId(*(args.pInstance.GetPointer()));
        instance_info.SetHandleId(*replay_instance);
        GetTrackedObjectInfoTable()->AddTrackedVkInstanceInfo(std::move(instance_info));
        AddInstanceTable(*replay_instance);
    }
}

void VulkanResourceTrackingConsumer::Process_vkCreateDevice(const ApiCallInfo& call_info, args::CreateDevice& args)
{
    if (!args.pDevice.IsNull())
    {
        args.pDevice.SetHandleLength(1);
    }

    auto physical_device_info = GetTrackedObjectInfoTable()->GetTrackedVkPhysicalDeviceInfo(args.physicalDevice);
    assert(physical_device_info != nullptr);

    VkResult                result               = VK_ERROR_INITIALIZATION_FAILED;
    VkPhysicalDevice        physical_device      = physical_device_info->GetHandleId();
    PFN_vkGetDeviceProcAddr get_device_proc_addr = GetDeviceAddrProc(physical_device);
    PFN_vkCreateDevice      create_device_proc   = GetCreateDeviceProc(physical_device);

    if ((get_device_proc_addr != nullptr) && (create_device_proc != nullptr))
    {
        auto replay_create_info = args.pCreateInfo.GetPointer();
        auto replay_device      = args.pDevice.GetHandlePointer();
        assert((replay_create_info != nullptr) && (replay_device != nullptr));

        result = create_device_proc(physical_device, replay_create_info, nullptr, replay_device);

        if ((replay_device != nullptr) && (result == VK_SUCCESS))
        {
            TrackedVkDeviceInfo device_info;

            device_info.SetParentPhysicalDevice(physical_device);

            device_info.SetCaptureId(*(args.pDevice.GetPointer()));
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

            device_info.SetCapturePhysicalDeviceId(physical_device_info->GetCaptureId());

            GetTrackedObjectInfoTable()->AddTrackedVkDeviceInfo(std::move(device_info));
            AddDeviceTable(*replay_device, get_device_proc_addr);
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to create device during resource tracking. Replay cannot continue.");
        }
    }
}

void VulkanResourceTrackingConsumer::Process_vkEnumeratePhysicalDevices(const ApiCallInfo&              call_info,
                                                                        args::EnumeratePhysicalDevices& args)
{
    auto instance_info = GetTrackedObjectInfoTable()->GetTrackedVkInstanceInfo(args.instance);
    args.pPhysicalDeviceCount.AllocateOutputData(
        1, args.pPhysicalDeviceCount.IsNull() ? static_cast<uint32_t>(0) : (*args.pPhysicalDeviceCount.GetPointer()));
    if (!args.pPhysicalDevices.IsNull())
    {
        args.pPhysicalDevices.SetHandleLength(*args.pPhysicalDeviceCount.GetOutputPointer());
    }

    std::vector<TrackedVkPhysicalDeviceInfo> handle_info(*(args.pPhysicalDeviceCount.GetOutputPointer()));

    GFXRECON_ASSERT((instance_info != nullptr) && (args.pPhysicalDeviceCount.GetPointer() != nullptr));

    VkInstance        instance_id         = instance_info->GetHandleId();
    uint32_t          replay_device_count = (*args.pPhysicalDeviceCount.GetPointer());
    VkPhysicalDevice* replay_devices      = args.pPhysicalDevices.GetHandlePointer();

    VkResult result = GetInstanceTable(instance_info->GetHandleId())
                          ->EnumeratePhysicalDevices(instance_id, &replay_device_count, replay_devices);

    // TODO (gfxrec-28): check for memory type properties compatibility between capture and replay devices

    if ((result >= 0) && (replay_devices != nullptr))
    {

        if ((args.pPhysicalDevices.GetPointer() != nullptr) && (args.pPhysicalDevices.GetHandlePointer() != nullptr))
        {
            size_t capture_physical_device_length  = args.pPhysicalDevices.GetLength();
            size_t playback_physical_device_length = replay_device_count;
            size_t len = std::min(capture_physical_device_length, playback_physical_device_length);

            assert(len <= handle_info.size());

            // TODO: better physical device mapping handling between capture time and replay time when
            //       system has multiple replay physical devices.

            for (size_t i = 0; i < len; ++i)
            {
                auto info_iterator = std::next(handle_info.begin(), i);
                info_iterator->SetHandleId(args.pPhysicalDevices.GetHandlePointer()[i]);
                info_iterator->SetCaptureId(args.pPhysicalDevices.GetPointer()[i]);
                GetTrackedObjectInfoTable()->AddTrackedVkPhysicalDeviceInfo(std::move(*info_iterator));
            }

            if ((playback_physical_device_length > 0) &&
                (playback_physical_device_length < capture_physical_device_length))
            {
                VkPhysicalDevice overflow_device = replay_devices[0];

                for (size_t i = playback_physical_device_length; i < capture_physical_device_length; ++i)
                {
                    TrackedVkPhysicalDeviceInfo overflow_info;

                    overflow_info.SetHandleId(overflow_device);
                    overflow_info.SetCaptureId(args.pPhysicalDevices.GetPointer()[i]);
                    GetTrackedObjectInfoTable()->AddTrackedVkPhysicalDeviceInfo(std::move(overflow_info));
                }
            }
        }
    }
}

void VulkanResourceTrackingConsumer::Process_vkCreateBuffer(const ApiCallInfo& call_info, args::CreateBuffer& args)
{
    if (!args.pBuffer.IsNull())
    {
        args.pBuffer.SetHandleLength(1);
    }

    auto buffer_create_info = args.pCreateInfo.GetPointer();
    auto replay_buffer      = args.pBuffer.GetHandlePointer();
    assert((buffer_create_info != nullptr) && (replay_buffer != nullptr));

    auto in_device = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);

    VkResult result = GetDeviceTable(in_device->GetHandleId())
                          ->CreateBuffer(in_device->GetHandleId(), buffer_create_info, nullptr, replay_buffer);

    if ((result == VK_SUCCESS) && (buffer_create_info != nullptr) && ((*replay_buffer) != VK_NULL_HANDLE))
    {
        TrackedVkResourceInfo buffer_info;

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
        buffer_info.SetCaptureId(*(args.pBuffer.GetPointer()));
        GetTrackedObjectInfoTable()->AddTrackedVkResourceInfo(std::move(buffer_info));
    }
}

void VulkanResourceTrackingConsumer::Process_vkCreateImage(const ApiCallInfo& call_info, args::CreateImage& args)
{
    if (!args.pImage.IsNull())
    {
        args.pImage.SetHandleLength(1);
    }

    auto in_device = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);

    auto image_create_info = args.pCreateInfo.GetPointer();
    auto replay_image      = args.pImage.GetHandlePointer();
    assert((image_create_info != nullptr) && (replay_image != nullptr));

    VkResult result = GetDeviceTable(in_device->GetHandleId())
                          ->CreateImage(in_device->GetHandleId(), image_create_info, nullptr, replay_image);

    if ((result == VK_SUCCESS) && (image_create_info != nullptr) && ((*replay_image) != VK_NULL_HANDLE))
    {
        TrackedVkResourceInfo image_info;

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
        image_info.SetCaptureId(*(args.pImage.GetPointer()));
        image_info.SetImageFlag(true);
        image_info.SetCaptureDeviceId(in_device->GetCaptureId());
        GetTrackedObjectInfoTable()->AddTrackedVkResourceInfo(std::move(image_info));
    }
}

void VulkanResourceTrackingConsumer::Process_vkAllocateMemory(const ApiCallInfo& call_info, args::AllocateMemory& args)
{
    auto                      device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);
    TrackedVkDeviceMemoryInfo memory_info;

    if (!args.pMemory.IsNull())
    {
        args.pMemory.SetHandleLength(1);
    }

    if (!options_.skip_failed_allocations)
    {
        const VkMemoryAllocateInfo* replay_allocate_info = args.pAllocateInfo.GetPointer();
        auto                        replay_memory        = args.pMemory.GetHandlePointer();
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

    memory_info.SetCaptureId(*(args.pMemory.GetPointer()));
    GetTrackedObjectInfoTable()->AddTrackedVkDeviceMemoryInfo(std::move(memory_info));
}

void VulkanResourceTrackingConsumer::Process_vkBindBufferMemory(const ApiCallInfo&      call_info,
                                                                args::BindBufferMemory& args)
{
    auto buffer_info = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(args.buffer);
    auto memory_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceMemoryInfo(args.memory);

    assert((buffer_info != nullptr) && (memory_info != nullptr));

    buffer_info->SetBoundMemoryId(args.memory);
    buffer_info->SetTraceBindOffset(args.memoryOffset);

    // no call to getbuffermemoryrequirement made prior to this,
    // make the getbuffermemoryrequirement call to get the replay size.
    if (buffer_info->GetReplayResourceSize() == 0)
    {
        args::GetBufferMemoryRequirements get_buffer_memory_requirements_args;
        get_buffer_memory_requirements_args.device = args.device;
        get_buffer_memory_requirements_args.buffer = args.buffer;
        Process_vkGetBufferMemoryRequirements(call_info, get_buffer_memory_requirements_args);
    }

    memory_info->InsertBoundResourcesList(buffer_info);
}

void VulkanResourceTrackingConsumer::Process_vkBindImageMemory(const ApiCallInfo&     call_info,
                                                               args::BindImageMemory& args)
{
    auto image_info  = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(args.image);
    auto memory_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceMemoryInfo(args.memory);

    assert((image_info != nullptr) && (memory_info != nullptr));

    image_info->SetBoundMemoryId(args.memory);
    image_info->SetTraceBindOffset(args.memoryOffset);

    // no call to getimagememoryrequirement made prior to this,
    // make the getimagememoryrequirement call to get the replay size.
    if (image_info->GetReplayResourceSize() == 0)
    {
        args::GetImageMemoryRequirements get_image_memory_requirements_args;
        get_image_memory_requirements_args.device = args.device;
        get_image_memory_requirements_args.image  = args.image;
        Process_vkGetImageMemoryRequirements(call_info, get_image_memory_requirements_args);
    }

    memory_info->InsertBoundResourcesList(image_info);
}

void VulkanResourceTrackingConsumer::Process_vkBindBufferMemory2(const ApiCallInfo&       call_info,
                                                                 args::BindBufferMemory2& args)
{
    auto tracked_device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);

    GFXRECON_ASSERT(tracked_device_info != nullptr);

    const VkBindBufferMemoryInfo*         replay_bind_infos      = args.pBindInfos.GetPointer();
    const Decoded_VkBindBufferMemoryInfo* replay_bind_meta_infos = args.pBindInfos.GetMetaStructPointer();
    assert((replay_bind_infos != nullptr) && (replay_bind_meta_infos != nullptr));

    for (uint32_t i = 0; i < args.bindInfoCount; ++i)
    {
        const Decoded_VkBindBufferMemoryInfo* bind_meta_info = &replay_bind_meta_infos[i];

        auto buffer_info = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(bind_meta_info->buffer);
        auto memory_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceMemoryInfo(bind_meta_info->memory);

        assert((buffer_info != nullptr) && (memory_info != nullptr));

        buffer_info->SetBoundMemoryId(bind_meta_info->memory);
        buffer_info->SetTraceBindOffset(replay_bind_infos[i].memoryOffset);

        // no call to getbuffermemoryrequirement made prior to this,
        // make the getbuffermemoryrequirement call to get the replay size.
        if (buffer_info->GetReplayResourceSize() == 0)
        {
            args::GetBufferMemoryRequirements get_buffer_memory_requirements_args;
            get_buffer_memory_requirements_args.device = args.device;
            get_buffer_memory_requirements_args.buffer = bind_meta_info->buffer;
            Process_vkGetBufferMemoryRequirements(call_info, get_buffer_memory_requirements_args);
        }

        memory_info->InsertBoundResourcesList(buffer_info);
    }
}

void VulkanResourceTrackingConsumer::Process_vkBindImageMemory2(const ApiCallInfo&      call_info,
                                                                args::BindImageMemory2& args)
{
    auto tracked_device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);

    GFXRECON_ASSERT(tracked_device_info != nullptr);

    const VkBindImageMemoryInfo*         replay_bind_infos      = args.pBindInfos.GetPointer();
    const Decoded_VkBindImageMemoryInfo* replay_bind_meta_infos = args.pBindInfos.GetMetaStructPointer();
    GFXRECON_ASSERT((replay_bind_infos != nullptr) && (replay_bind_meta_infos != nullptr));

    for (uint32_t i = 0; i < args.bindInfoCount; ++i)
    {
        const Decoded_VkBindImageMemoryInfo* bind_meta_info = &replay_bind_meta_infos[i];

        auto image_info  = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(bind_meta_info->image);
        auto memory_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceMemoryInfo(bind_meta_info->memory);

        GFXRECON_ASSERT((image_info != nullptr) && (memory_info != nullptr));

        image_info->SetBoundMemoryId(bind_meta_info->memory);
        image_info->SetTraceBindOffset(replay_bind_infos[i].memoryOffset);

        // no call to getimagememoryrequirement made prior to this,
        // make the getimagememoryrequirement call to get the replay size.
        if (image_info->GetReplayResourceSize() == 0)
        {
            args::GetImageMemoryRequirements get_image_memory_requirements_args;
            get_image_memory_requirements_args.device = args.device;
            get_image_memory_requirements_args.image  = bind_meta_info->image;
            Process_vkGetImageMemoryRequirements(call_info, get_image_memory_requirements_args);
        }

        memory_info->InsertBoundResourcesList(image_info);
    }
}

void VulkanResourceTrackingConsumer::Process_vkMapMemory(const ApiCallInfo& call_info, args::MapMemory& args)
{
    auto memory_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceMemoryInfo(args.memory);

    GFXRECON_ASSERT(memory_info != nullptr);

    memory_info->InsertMappedMemoryOffsetsList(args.offset);
    memory_info->InsertMappedMemorySizesList(args.size);
}

void VulkanResourceTrackingConsumer::Process_vkGetBufferMemoryRequirements(const ApiCallInfo&                 call_info,
                                                                           args::GetBufferMemoryRequirements& args)
{
    auto device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);
    auto buffer_info = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(args.buffer);

    // retrieve trace buffer memory requirements
    if (!args.pMemoryRequirements.IsNull())
    {
        Decoded_VkMemoryRequirements* decoded_buffer_memory_requirements =
            args.pMemoryRequirements.GetMetaStructPointer();
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
    if (!args.pMemoryRequirements.IsNull())
    {
        out_pMemoryRequirements = args.pMemoryRequirements.AllocateOutputData(1);
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

void VulkanResourceTrackingConsumer::Process_vkGetImageMemoryRequirements(const ApiCallInfo&                call_info,
                                                                          args::GetImageMemoryRequirements& args)
{
    auto device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);
    auto image_info  = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(args.image);

    // retrieve trace image memory requirements
    if (!args.pMemoryRequirements.IsNull())
    {
        Decoded_VkMemoryRequirements* decoded_image_memory_requirements =
            args.pMemoryRequirements.GetMetaStructPointer();
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
    if (!args.pMemoryRequirements.IsNull())
    {
        out_pMemoryRequirements = args.pMemoryRequirements.AllocateOutputData(1);
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

void VulkanResourceTrackingConsumer::Process_vkDestroyInstance(const ApiCallInfo&     call_info,
                                                               args::DestroyInstance& args)
{
    auto       instance_info = GetTrackedObjectInfoTable()->GetTrackedVkInstanceInfo(args.instance);
    VkInstance in_instance   = instance_info->GetHandleId();

    GetInstanceTable(in_instance)->DestroyInstance(in_instance, nullptr);
}

void VulkanResourceTrackingConsumer::Process_vkDestroyDevice(const ApiCallInfo& call_info, args::DestroyDevice& args)
{
    auto     device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);
    VkDevice in_device   = device_info->GetHandleId();

    GetDeviceTable(in_device)->DestroyDevice(in_device, nullptr);
}

void VulkanResourceTrackingConsumer::Process_vkDestroyBuffer(const ApiCallInfo& call_info, args::DestroyBuffer& args)
{
    auto     device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);
    auto     buffer_info = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(args.buffer);
    VkDevice in_device   = device_info->GetHandleId();
    VkBuffer in_buffer   = buffer_info->GetBufferReplayHandleId();

    GetDeviceTable(in_device)->DestroyBuffer(in_device, in_buffer, nullptr);
}

void VulkanResourceTrackingConsumer::Process_vkDestroyImage(const ApiCallInfo& call_info, args::DestroyImage& args)
{
    auto     device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);
    auto     image_info  = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(args.image);
    VkDevice in_device   = device_info->GetHandleId();
    VkImage  in_image    = image_info->GetImageReplayHandleId();

    GetDeviceTable(in_device)->DestroyImage(in_device, in_image, nullptr);
}

void VulkanResourceTrackingConsumer::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                              uint64_t       offset,
                                                              uint64_t       size,
                                                              const uint8_t* data)
{
    auto memory_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceMemoryInfo(memory_id);

    assert((memory_info != nullptr));

    memory_info->InsertFilledMemoryOffsetsList(offset);
    memory_info->InsertFilledMemorySizesList(size);
}

// Util function for sorting: compares two resources according to the trace binding offset number.
bool CompareOffset(TrackedVkResourceInfo* resource1, TrackedVkResourceInfo* resource2)
{
    return (resource1->GetTraceBindOffset() < resource2->GetTraceBindOffset());
}

// Sort the bound resources in each device memory object according to their trace binding offset.
void VulkanResourceTrackingConsumer::SortMemoriesBoundResourcesByOffset()
{
    auto tracked_device_memories_map = GetTrackedObjectInfoTable()->GetTrackedVkDeviceMemoriesInfoMap();
    assert(tracked_device_memories_map != nullptr);

    for (auto& iterator : (*tracked_device_memories_map))
    {
        TrackedVkDeviceMemoryInfo tracked_device_memory = iterator.second;

        std::vector<TrackedVkResourceInfo*>* resources = tracked_device_memory.GetBoundResourcesList();

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
    auto tracked_device_memories_map = GetTrackedObjectInfoTable()->GetTrackedVkDeviceMemoriesInfoMap();
    assert(tracked_device_memories_map != nullptr);

    for (auto& iterator : (*tracked_device_memories_map))
    {
        TrackedVkDeviceMemoryInfo tracked_device_memory = iterator.second;

        std::vector<TrackedVkResourceInfo*>* resources = tracked_device_memory.GetBoundResourcesList();

        if ((*resources).empty() == false)
        {
            // recalculate the replay binding offset by looping through the sorted bound resources
            // and update the replay binding offset based on the memory alignment requirement
            // and check for no/partial/complete overlap with previous bound resource memory
            // during trace and update the replay binding offset  and then memory allocation size
            // accordingly.

            // loop through the bound resources and update replay resource binding offset
            // based on the memory alignment requirement and update memory allocation size
            for (size_t i = 0; i < (*resources).size(); i++)
            {
                // assign replay bind offset to be the same as trace offset first
                VkDeviceSize replay_bind_offset = (*resources)[i]->GetTraceBindOffset();

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

void VulkanResourceTrackingConsumer::Process_vkGetImageSubresourceLayout(const ApiCallInfo&               call_info,
                                                                         args::GetImageSubresourceLayout& args)
{
    auto                device_info         = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);
    auto                image_info          = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(args.image);
    VkDevice            in_device           = device_info->GetHandleId();
    VkImage             in_image            = image_info->GetImageReplayHandleId();
    auto                layout_capture_time = args.pLayout.GetPointer();
    VkSubresourceLayout subresource_layout_playback_time;

    GFXRECON_ASSERT(layout_capture_time);
    GetDeviceTable(in_device)->GetImageSubresourceLayout(
        in_device, in_image, args.pSubresource.GetPointer(), &subresource_layout_playback_time);
    image_info->SetImageSubresourceLayout(
        args.pSubresource.GetPointer(), layout_capture_time, &subresource_layout_playback_time);
}

void VulkanResourceTrackingConsumer::Process_vkGetImageSubresourceLayout2(const ApiCallInfo&                call_info,
                                                                          args::GetImageSubresourceLayout2& args)
{
    auto                 device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);
    auto                 image_info  = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(args.image);
    VkDevice             in_device   = device_info->GetHandleId();
    VkImage              in_image    = image_info->GetImageReplayHandleId();
    VkSubresourceLayout2 subresource_layout_playback_time;
    auto                 layout_capture_time = args.pLayout.GetPointer();

    GFXRECON_ASSERT(layout_capture_time);

    GetDeviceTable(in_device)->GetImageSubresourceLayout2(
        in_device, in_image, args.pSubresource.GetPointer(), &subresource_layout_playback_time);
    image_info->SetImageSubresourceLayout(&args.pSubresource.GetPointer()->imageSubresource,
                                          &layout_capture_time->subresourceLayout,
                                          &subresource_layout_playback_time.subresourceLayout);
}

void VulkanResourceTrackingConsumer::Process_vkGetImageSubresourceLayout2KHR(const ApiCallInfo& call_info,
                                                                             args::GetImageSubresourceLayout2KHR& args)
{
    auto                    device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);
    auto                    image_info  = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(args.image);
    VkDevice                in_device   = device_info->GetHandleId();
    VkImage                 in_image    = image_info->GetImageReplayHandleId();
    VkSubresourceLayout2KHR subresource_layout_playback_time;
    auto                    layout_capture_time = args.pLayout.GetPointer();

    GFXRECON_ASSERT(layout_capture_time);

    GetDeviceTable(in_device)->GetImageSubresourceLayout2KHR(
        in_device, in_image, args.pSubresource.GetPointer(), &subresource_layout_playback_time);
    image_info->SetImageSubresourceLayout(&args.pSubresource.GetPointer()->imageSubresource,
                                          &layout_capture_time->subresourceLayout,
                                          &subresource_layout_playback_time.subresourceLayout);
}

void VulkanResourceTrackingConsumer::Process_vkGetImageSubresourceLayout2EXT(const ApiCallInfo& call_info,
                                                                             args::GetImageSubresourceLayout2EXT& args)
{
    auto                    device_info = GetTrackedObjectInfoTable()->GetTrackedVkDeviceInfo(args.device);
    auto                    image_info  = GetTrackedObjectInfoTable()->GetTrackedVkResourceInfo(args.image);
    VkDevice                in_device   = device_info->GetHandleId();
    VkImage                 in_image    = image_info->GetImageReplayHandleId();
    VkSubresourceLayout2KHR subresource_layout_playback_time;
    auto                    layout_capture_time = args.pLayout.GetPointer();

    GFXRECON_ASSERT(layout_capture_time);

    GetDeviceTable(in_device)->GetImageSubresourceLayout2EXT(
        in_device, in_image, args.pSubresource.GetPointer(), &subresource_layout_playback_time);
    image_info->SetImageSubresourceLayout(&args.pSubresource.GetPointer()->imageSubresource,
                                          &layout_capture_time->subresourceLayout,
                                          &subresource_layout_playback_time.subresourceLayout);
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceProperties(const ApiCallInfo&                 call_info,
                                                                           args::GetPhysicalDeviceProperties& args)
{
    auto physical_device_info = GetTrackedObjectInfoTable()->GetTrackedVkPhysicalDeviceInfo(args.physicalDevice);
    VkPhysicalDevice physical_device      = physical_device_info->GetHandleId();
    VkPhysicalDeviceProperties replay_properties;

    GetInstanceTable(physical_device)->GetPhysicalDeviceProperties(physical_device, &replay_properties);
    physical_device_info->SetCaptureDevicePhysicalProperties(*args.pProperties.GetPointer());
    physical_device_info->SetReplayDevicePhysicalProperties(replay_properties);
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceProperties2(const ApiCallInfo& call_info,
                                                                            args::GetPhysicalDeviceProperties2& args)
{
    auto physical_device_info = GetTrackedObjectInfoTable()->GetTrackedVkPhysicalDeviceInfo(args.physicalDevice);
    VkPhysicalDevice physical_device      = physical_device_info->GetHandleId();
    VkPhysicalDeviceProperties2 replay_properties;

    GetInstanceTable(physical_device)->GetPhysicalDeviceProperties2(physical_device, &replay_properties);
    physical_device_info->SetCaptureDevicePhysicalProperties(args.pProperties.GetPointer()->properties);
    physical_device_info->SetReplayDevicePhysicalProperties(replay_properties.properties);
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo& call_info, args::GetPhysicalDeviceProperties2KHR& args)
{
    auto physical_device_info = GetTrackedObjectInfoTable()->GetTrackedVkPhysicalDeviceInfo(args.physicalDevice);
    VkPhysicalDevice physical_device      = physical_device_info->GetHandleId();
    VkPhysicalDeviceProperties2 replay_properties;

    GetInstanceTable(physical_device)->GetPhysicalDeviceProperties2KHR(physical_device, &replay_properties);
    physical_device_info->SetCaptureDevicePhysicalProperties(args.pProperties.GetPointer()->properties);
    physical_device_info->SetReplayDevicePhysicalProperties(replay_properties.properties);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
