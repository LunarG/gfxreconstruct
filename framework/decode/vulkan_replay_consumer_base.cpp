/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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

#include "decode/vulkan_replay_consumer_base.h"

#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/vulkan_enum_util.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cstdint>
#include <limits>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const int32_t  kDefaultWindowPositionX = 0;
const int32_t  kDefaultWindowPositionY = 0;
const uint32_t kDefaultWindowWidth     = 320;
const uint32_t kDefaultWindowHeight    = 240;

const std::vector<std::string> kLoaderLibNames = {
#if defined(WIN32)
    "vulkan-1.dll"
#else
    "libvulkan.so", "libvulkan.so.1"
#endif
};

const std::unordered_set<std::string> kSurfaceExtensions = {
    VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, VK_MVK_IOS_SURFACE_EXTENSION_NAME, VK_MVK_MACOS_SURFACE_EXTENSION_NAME,
    VK_KHR_MIR_SURFACE_EXTENSION_NAME,     VK_NN_VI_SURFACE_EXTENSION_NAME,   VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
    VK_KHR_WIN32_SURFACE_EXTENSION_NAME,   VK_KHR_XCB_SURFACE_EXTENSION_NAME, VK_KHR_XLIB_SURFACE_EXTENSION_NAME
};

VulkanReplayConsumerBase::VulkanReplayConsumerBase(WindowFactory* window_factory, const ReplayOptions& options) :
    loader_handle_(nullptr), get_instance_proc_addr_(nullptr), create_instance_proc_(nullptr),
    window_factory_(window_factory), options_(options)
{
    assert(window_factory != nullptr);
}

VulkanReplayConsumerBase::~VulkanReplayConsumerBase()
{
    // Destroy any windows that were created for Vulkan surfaces.
    for (const auto& entry : window_map_)
    {
        window_factory_->Destroy(entry.second);
    }

    if (loader_handle_ != nullptr)
    {
        util::platform::CloseLibrary(loader_handle_);
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
    // We need to find the device memory associated with this ID, and then lookup its mapped pointer.
    VkDeviceMemory memory = object_mapper_.MapVkDeviceMemory(memory_id);

    if (memory != VK_NULL_HANDLE)
    {
        auto entry = memory_map_.find(memory);

        if ((entry != memory_map_.end()) && (entry->second != nullptr))
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
            memcpy(static_cast<uint8_t*>(entry->second) + offset, data, static_cast<size_t>(size));
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping memory fill for VkDeviceMemory object that is not mapped (%" PRIx64 ")",
                                 memory_id);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping memory fill for unrecognized VkDeviceMemory object (%" PRIx64 ")", memory_id);
    }
}

void VulkanReplayConsumerBase::ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    // We need to find the surface associated with this ID, and then lookup its window.
    VkSurfaceKHR surface = object_mapper_.MapVkSurfaceKHR(surface_id);

    if (surface != VK_NULL_HANDLE)
    {
        auto entry = window_map_.find(surface);

        if ((entry != window_map_.end()) && (entry->second != nullptr))
        {
            Window* window = entry->second;
            window->SetSize(width, height);
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "Skipping window resize for VkSurface object (%" PRIx64 ") without an associated window", surface_id);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping window resize for unrecognized VkSurface object (%" PRIx64 ")", surface_id);
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
        create_instance_proc_ =
            reinterpret_cast<PFN_vkCreateInstance>(get_instance_proc_addr_(nullptr, "vkCreateInstance"));
    }

    if (create_instance_proc_ == nullptr)
    {
        GFXRECON_LOG_FATAL("Failed to load Vulkan runtime library; please ensure that the path to the Vulkan "
                           "loader (eg. %s) has been added to the appropriate system path",
                           kLoaderLibNames[0].c_str());
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

    if ((call_id == format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR) ||
        (call_id == format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR))
    {
        // For window system related handles, we put the object ID into the pointer.
        // The dispatch override for the API call will use this ID as a key to the window map.
        // TODO: For x86 builds, we should map the object_id to a 32-bit sequence number that won't be truncated by the
        // cast.
        object = reinterpret_cast<void*>(object_id);
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                             call_name);
    }

    return object;
}

void VulkanReplayConsumerBase::PostProcessExternalObject(const PointerDecoder<uint64_t>& object_id,
                                                         void*                           object,
                                                         format::ApiCallId               call_id,
                                                         const char*                     call_name)
{
    if (call_id == format::ApiCallId::ApiCall_vkMapMemory)
    {
        // Mapped memory tracking is handled by mapping the VkDeviceMemory handle to the mapped pointer, rather than
        // mapping the traced pointer address to the mapped pointer.  The memory needs to be tracked by handle so that
        // it can be removed from the unordered_map when memory is unmapped or freed.
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                             call_name);
    }
}

const VkAllocationCallbacks* VulkanReplayConsumerBase::GetAllocationCallbacks(
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& original_callbacks)
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
        else if (replay == VK_INCOMPLETE)
        {
            // VK_INCOMPLETE is generated when replaying a 'vkGet' function with a size value read from the capture file
            // that is smaller than the size expected by the replay device.  Replay does not make use of the values
            // retrieved by this function, so the error should be safe to ignore.  Log this case as a debug message
            // until replay is modified to adjust sizes used when replaying.
            GFXRECON_LOG_DEBUG("API call %s returned value VK_INCOMPLETE that does not match return value from "
                               "capture file: %s.  This may be caused by platform differences.",
                               func_name,
                               enumutil::GetResultValueString(original));
        }
        else if (!((replay == VK_SUCCESS) &&
                   ((original == VK_TIMEOUT) || (original == VK_NOT_READY) || (original == VK_ERROR_OUT_OF_DATE_KHR))))
        {
            // Report differences between replay result and capture result, unless the replay results indicates
            // that a wait operation completed before the original or a WSI function succeded when the original failed.
            GFXRECON_LOG_WARNING(
                "API call %s returned value %s that does not match return value from capture file: %s.",
                func_name,
                enumutil::GetResultValueString(replay),
                enumutil::GetResultValueString(original));
        }
    }
}

void VulkanReplayConsumerBase::ProcessPhysicalDeviceProperties(VkPhysicalDevice                  physical_device,
                                                               const VkPhysicalDeviceProperties* capture_properties,
                                                               const VkPhysicalDeviceProperties* replay_properties)
{
    if (device_properties_.find(physical_device) == device_properties_.end())
    {
        PhysicalDeviceProperties properties = { (*capture_properties), (*replay_properties) };
        device_properties_.emplace(physical_device, properties);
    }
}

void VulkanReplayConsumerBase::OverridePhysicalDevice(VkPhysicalDevice* physical_device)
{
    assert(physical_device != nullptr);

    // Match the current physical device with its parent instance.
    VkInstance instance = VK_NULL_HANDLE;

    for (const auto& entry : instance_devices_)
    {
        auto result =
            std::find(entry.second.replay_devices.begin(), entry.second.replay_devices.end(), (*physical_device));
        if (result != entry.second.replay_devices.end())
        {
            instance = entry.first;
            break;
        }
    }

    if (instance != VK_NULL_HANDLE)
    {
        auto devices_entry = instance_devices_.find(instance);
        if (devices_entry != instance_devices_.end())
        {
            const auto& replay_devices = devices_entry->second.replay_devices;
            if (options_.override_gpu_index < replay_devices.size())
            {
                VkPhysicalDevice override_device = replay_devices[options_.override_gpu_index];

                if (override_device != (*physical_device))
                {
                    GFXRECON_LOG_INFO("Overriding replay device with GPU%d", options_.override_gpu_index);
                    GFXRECON_LOG_INFO("  Available devices are:");
                    for (size_t i = 0; i < replay_devices.size(); ++i)
                    {
                        GFXRECON_LOG_INFO("    [%d] %p", i, replay_devices[i]);
                    }
                    GFXRECON_LOG_INFO("  Original device is: %p", *physical_device);
                    GFXRECON_LOG_INFO("  Override device is: %p", override_device);

                    // Warn about potential incompatibilities when replay device type does not match capture
                    // device type.
                    auto capture_entry = device_properties_.find(*physical_device);
                    auto replay_entry  = device_properties_.find(override_device);
                    if ((capture_entry != device_properties_.end()) && (replay_entry != device_properties_.end()))
                    {
                        const auto& capture_properties = capture_entry->second.capture_properties;
                        const auto& replay_properties  = replay_entry->second.replay_properties;
                        if ((capture_properties.vendorID != replay_properties.vendorID) &&
                            (capture_properties.deviceID != replay_properties.deviceID))
                        {
                            GFXRECON_LOG_WARNING(
                                "The type of device selected for replay differs from the type of the original capture "
                                "device; replay may fail due to device incompatibilities:");
                            GFXRECON_LOG_WARNING(
                                "  Capture device info:\t[vendorID = 0x%x, deviceId = 0x%x, deviceName = %s]",
                                capture_properties.vendorID,
                                capture_properties.deviceID,
                                capture_properties.deviceName);
                            GFXRECON_LOG_WARNING(
                                "  Replay device info:\t[vendorID = 0x%x, deviceId = 0x%x, deviceName = %s]",
                                replay_properties.vendorID,
                                replay_properties.deviceID,
                                replay_properties.deviceName);
                        }
                    }
                    else
                    {
                        // No query was made for physical device properties prior to device creation at capture,
                        // so provide a generic warning.
                        GFXRECON_LOG_WARNING(
                            "If the type of device selected for replay differs from the type of the original capture "
                            "device, replay may fail due to device incompatibilities.");
                    }

                    (*physical_device) = override_device;
                }
            }
            else
            {
                GFXRECON_LOG_ERROR("Index specified for replay device override (%d) exceeds the range of "
                                   "available physical devices (0-%d); the override will not be applied",
                                   options_.override_gpu_index,
                                   (replay_devices.size() - 1));
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Replay device override failed to find a list of physical devices associated with "
                               "the current instance; the override will not be applied")
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Replay device override failed to match the original physical device handle with an "
                           "instance; the override will not be applied")
    }
}

VkResult VulkanReplayConsumerBase::CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* surface)
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

    VkResult result = window->CreateSurface(GetInstanceTable(instance), instance, flags, surface);

    if ((result == VK_SUCCESS) && (surface != nullptr))
    {
        VkSurfaceKHR key = (*surface);

        assert(window_map_.find(key) == window_map_.end());

        window_map_.insert(std::make_pair(key, window));
    }
    else
    {
        window_factory_->Destroy(window);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateInstance(VkResult                                original_result,
                                                          const VkInstanceCreateInfo*             pCreateInfo,
                                                          const VkAllocationCallbacks*            pAllocator,
                                                          const HandlePointerDecoder<VkInstance>& original_instance,
                                                          VkInstance*                             pInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(original_instance);

    if (loader_handle_ == nullptr)
    {
        InitializeLoader();
    }

    // Replace WSI extension in extension list.
    std::vector<const char*> filtered_extensions;
    VkInstanceCreateInfo     modified_create_info{};

    if (pCreateInfo != nullptr)
    {
        if (pCreateInfo->ppEnabledExtensionNames)
        {
            for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; ++i)
            {
                const char* current_extension = pCreateInfo->ppEnabledExtensionNames[i];
                if (kSurfaceExtensions.find(current_extension) != kSurfaceExtensions.end())
                {
                    filtered_extensions.push_back(window_factory_->GetSurfaceExtensionName());
                }
                else
                {
                    filtered_extensions.push_back(current_extension);
                }
            }
        }

        modified_create_info                         = (*pCreateInfo);
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

    VkResult result = create_instance_proc_(&modified_create_info, pAllocator, pInstance);

    if ((pInstance != nullptr) && (result == VK_SUCCESS))
    {
        AddInstanceTable(*pInstance);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateDevice(VkResult                              original_result,
                                                        VkPhysicalDevice                      physicalDevice,
                                                        const VkDeviceCreateInfo*             pCreateInfo,
                                                        const VkAllocationCallbacks*          pAllocator,
                                                        const HandlePointerDecoder<VkDevice>& original_device,
                                                        VkDevice*                             pDevice)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(original_device);

    VkResult                result               = VK_ERROR_INITIALIZATION_FAILED;
    PFN_vkGetDeviceProcAddr get_device_proc_addr = GetDeviceAddrProc(physicalDevice);
    PFN_vkCreateDevice      create_device_proc   = GetCreateDeviceProc(physicalDevice);

    if ((get_device_proc_addr != nullptr) && (create_device_proc != nullptr))
    {
        if (options_.override_gpu_index >= 0)
        {
            OverridePhysicalDevice(&physicalDevice);
        }

        result = create_device_proc(physicalDevice, pCreateInfo, pAllocator, pDevice);

        if ((pDevice != nullptr) && (result == VK_SUCCESS))
        {
            AddDeviceTable(*pDevice, get_device_proc_addr);
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideEnumeratePhysicalDevices(
    PFN_vkEnumeratePhysicalDevices                func,
    VkResult                                      returnValue,
    VkInstance                                    instance,
    const PointerDecoder<uint32_t>&               original_device_count,
    uint32_t*                                     pPhysicalDeviceCount,
    const HandlePointerDecoder<VkPhysicalDevice>& original_devices,
    VkPhysicalDevice*                             pPhysicalDevices)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    VkResult result = func(instance, pPhysicalDeviceCount, pPhysicalDevices);

    if ((result >= 0) && (pPhysicalDevices != nullptr) && (instance_devices_.find(instance) == instance_devices_.end()))
    {
        assert(!original_devices.IsNull() && !original_device_count.IsNull() && (pPhysicalDeviceCount != nullptr));

        InstanceDevices   devices;
        format::HandleId* capture_devices = original_devices.GetPointer();
        uint32_t          count           = (*original_device_count.GetPointer());

        for (uint32_t i = 0; i < count; ++i)
        {
            devices.capture_devices.push_back(capture_devices[i]);
        }

        count = (*pPhysicalDeviceCount);

        for (uint32_t i = 0; i < count; ++i)
        {
            devices.replay_devices.push_back(pPhysicalDevices[i]);
        }

        instance_devices_.emplace(instance, devices);
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceProperties(
    PFN_vkGetPhysicalDeviceProperties                               func,
    VkPhysicalDevice                                                physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>& original_properties,
    VkPhysicalDeviceProperties*                                     pProperties)
{
    func(physicalDevice, pProperties);
    ProcessPhysicalDeviceProperties(physicalDevice, original_properties.GetPointer(), pProperties);
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceProperties2(
    PFN_vkGetPhysicalDeviceProperties2                               func,
    VkPhysicalDevice                                                 physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& original_properties,
    VkPhysicalDeviceProperties2*                                     pProperties)
{
    func(physicalDevice, pProperties);

    auto properties = original_properties.GetPointer();
    assert((properties != nullptr) && (pProperties != nullptr));
    ProcessPhysicalDeviceProperties(physicalDevice, &properties->properties, &pProperties->properties);
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceProperties2KHR(
    PFN_vkGetPhysicalDeviceProperties2KHR                               func,
    VkPhysicalDevice                                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2KHR>& original_properties,
    VkPhysicalDeviceProperties2KHR*                                     pProperties)
{
    func(physicalDevice, pProperties);

    auto properties = original_properties.GetPointer();
    assert((properties != nullptr) && (pProperties != nullptr));
    ProcessPhysicalDeviceProperties(physicalDevice, &properties->properties, &pProperties->properties);
}

VkResult VulkanReplayConsumerBase::OverrideWaitForFences(PFN_vkWaitForFences func,
                                                         VkResult            original_result,
                                                         VkDevice            device,
                                                         uint32_t            fenceCount,
                                                         const VkFence*      pFences,
                                                         VkBool32            waitAll,
                                                         uint64_t            timeout)
{
    VkResult result;

    if (original_result == VK_SUCCESS)
    {
        // Ensure that wait for fences waits until the fences have been signaled (or error occurs) by changing the
        // timeout to UINT64_MAX.
        result = func(device, fenceCount, pFences, waitAll, std::numeric_limits<uint64_t>::max());
    }
    else if (original_result == VK_TIMEOUT)
    {
        // Try to get a timeout result with a 0 timeout.
        result = func(device, fenceCount, pFences, waitAll, 0);
    }
    else
    {
        result = func(device, fenceCount, pFences, waitAll, timeout);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetFenceStatus(PFN_vkGetFenceStatus func,
                                                          VkResult             original_result,
                                                          VkDevice             device,
                                                          VkFence              fence)
{
    VkResult result;

    do
    {
        result = func(device, fence);
    } while ((original_result == VK_SUCCESS) && (result == VK_NOT_READY));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetEventStatus(PFN_vkGetEventStatus func,
                                                          VkResult             original_result,
                                                          VkDevice             device,
                                                          VkEvent              event)
{
    VkResult result;

    do
    {
        result = func(device, event);
    } while ((original_result == VK_EVENT_SET) && (result == VK_EVENT_RESET));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetQueryPoolResults(PFN_vkGetQueryPoolResults      func,
                                                               VkResult                       original_result,
                                                               VkDevice                       device,
                                                               VkQueryPool                    queryPool,
                                                               uint32_t                       firstQuery,
                                                               uint32_t                       queryCount,
                                                               size_t                         dataSize,
                                                               const PointerDecoder<uint8_t>& original_data,
                                                               void*                          pData,
                                                               VkDeviceSize                   stride,
                                                               VkQueryResultFlags             flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_data);

    VkResult result;

    do
    {
        result = func(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    } while ((original_result == VK_SUCCESS) && (result == VK_NOT_READY));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAllocateCommandBuffers(
    PFN_vkAllocateCommandBuffers                 func,
    VkResult                                     original_result,
    VkDevice                                     device,
    const VkCommandBufferAllocateInfo*           pAllocateInfo,
    const HandlePointerDecoder<VkCommandBuffer>& original_command_buffers,
    VkCommandBuffer*                             pCommandBuffers)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_command_buffers);

    VkResult result = original_result;

    if ((original_result >= 0) || !options_.skip_failed_allocations)
    {
        result = func(device, pAllocateInfo, pCommandBuffers);
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateCommandBuffers call that failed during capture with error %s",
                          enumutil::GetResultValueString(original_result));
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAllocateDescriptorSets(
    PFN_vkAllocateDescriptorSets                 func,
    VkResult                                     original_result,
    VkDevice                                     device,
    const VkDescriptorSetAllocateInfo*           pAllocateInfo,
    const HandlePointerDecoder<VkDescriptorSet>& original_descriptor_sets,
    VkDescriptorSet*                             pDescriptorSets)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_descriptor_sets);

    VkResult result = original_result;

    if ((original_result >= 0) || !options_.skip_failed_allocations)
    {
        result = func(device, pAllocateInfo, pDescriptorSets);
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateDescriptorSets call that failed during capture with error %s",
                          enumutil::GetResultValueString(original_result));
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAllocateMemory(PFN_vkAllocateMemory                        func,
                                                          VkResult                                    original_result,
                                                          VkDevice                                    device,
                                                          const VkMemoryAllocateInfo*                 pAllocateInfo,
                                                          const VkAllocationCallbacks*                pAllocator,
                                                          const HandlePointerDecoder<VkDeviceMemory>& original_memory,
                                                          VkDeviceMemory*                             pMemory)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_memory);

    VkResult result = original_result;

    if ((original_result >= 0) || !options_.skip_failed_allocations)
    {
        result = func(device, pAllocateInfo, pAllocator, pMemory);
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateMemory call that failed during capture with error %s",
                          enumutil::GetResultValueString(original_result));
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideMapMemory(PFN_vkMapMemory                 func,
                                                     VkResult                        original_result,
                                                     VkDevice                        device,
                                                     VkDeviceMemory                  memory,
                                                     VkDeviceSize                    offset,
                                                     VkDeviceSize                    size,
                                                     VkMemoryMapFlags                flags,
                                                     const PointerDecoder<uint64_t>& original_data,
                                                     void**                          ppData)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(original_data);

    VkResult result = func(device, memory, offset, size, flags, ppData);

    if ((result == VK_SUCCESS) && (ppData != nullptr) && (*ppData != nullptr))
    {
        memory_map_.insert(std::make_pair(memory, (*ppData)));
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideUnmapMemory(PFN_vkUnmapMemory func, VkDevice device, VkDeviceMemory memory)
{
    memory_map_.erase(memory);

    func(device, memory);
}

void VulkanReplayConsumerBase::OverrideFreeMemory(PFN_vkFreeMemory             func,
                                                  VkDevice                     device,
                                                  VkDeviceMemory               memory,
                                                  const VkAllocationCallbacks* pAllocator)
{
    memory_map_.erase(memory);

    func(device, memory, pAllocator);
}

VkResult VulkanReplayConsumerBase::OverrideCreateDescriptorUpdateTemplate(
    PFN_vkCreateDescriptorUpdateTemplate                    func,
    VkResult                                                original_result,
    VkDevice                                                device,
    const VkDescriptorUpdateTemplateCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                            pAllocator,
    const HandlePointerDecoder<VkDescriptorUpdateTemplate>& original_update_template,
    VkDescriptorUpdateTemplate*                             pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(original_update_template);

    if (pCreateInfo != nullptr)
    {
        // Modify the layout of the update template entries to match the tight packing performed by the trace encoding.
        // The trace encoding wrote the update template entries as a tightly packed array of VkDescriptorImageInfo
        // values, followed by an array of VkDescriptorBufferInfo values, followed by an array of VkBufferView values.
        VkDescriptorUpdateTemplateCreateInfo override_create_info = (*pCreateInfo);

        std::vector<VkDescriptorUpdateTemplateEntry> entries(
            override_create_info.pDescriptorUpdateEntries,
            (override_create_info.pDescriptorUpdateEntries + override_create_info.descriptorUpdateEntryCount));

        // Count the number of values of each type.
        size_t image_info_count        = 0;
        size_t buffer_info_count       = 0;
        size_t texel_buffer_view_count = 0;

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
            else
            {
                assert(false);
            }
        }

        // Compute start offsets for each type.
        size_t image_info_offset        = 0;
        size_t buffer_info_offset       = image_info_count * sizeof(VkDescriptorImageInfo);
        size_t texel_buffer_view_offset = buffer_info_offset + (buffer_info_count * sizeof(VkDescriptorBufferInfo));

        // Track descriptor image type.
        DescriptorImageTypes image_types;

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
            else
            {
                assert(false);
            }
        }

        override_create_info.pDescriptorUpdateEntries = entries.data();

        VkResult result = func(device, &override_create_info, pAllocator, pDescriptorUpdateTemplate);

        if ((result == VK_SUCCESS) && (pDescriptorUpdateTemplate != nullptr) &&
            (*pDescriptorUpdateTemplate != VK_NULL_HANDLE))
        {
            descriptor_update_template_image_types_.emplace(*pDescriptorUpdateTemplate, image_types);
        }

        return result;
    }
    else
    {
        return func(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    }
}

void VulkanReplayConsumerBase::OverrideDestroyDescriptorUpdateTemplate(
    PFN_vkDestroyDescriptorUpdateTemplate func,
    VkDevice                              device,
    VkDescriptorUpdateTemplate            descriptorUpdateTemplate,
    const VkAllocationCallbacks*          pAllocator)
{
    descriptor_update_template_image_types_.erase(descriptorUpdateTemplate);
    func(device, descriptorUpdateTemplate, pAllocator);
}

VkResult VulkanReplayConsumerBase::OverrideCreatePipelineCache(
    PFN_vkCreatePipelineCache                    func,
    VkResult                                     original_result,
    VkDevice                                     device,
    const VkPipelineCacheCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                 pAllocator,
    const HandlePointerDecoder<VkPipelineCache>& original_pipeline_cache,
    VkPipelineCache*                             pPipelineCache)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(original_pipeline_cache);

    if (options_.omit_pipeline_cache_data && (pCreateInfo != nullptr))
    {
        // Make a shallow copy of the create info structure and clear the cache data.
        VkPipelineCacheCreateInfo override_create_info = *pCreateInfo;
        override_create_info.initialDataSize           = 0;
        override_create_info.pInitialData              = nullptr;

        return func(device, &override_create_info, pAllocator, pPipelineCache);
    }
    else
    {
        return func(device, pCreateInfo, pAllocator, pPipelineCache);
    }
}

VkResult
VulkanReplayConsumerBase::OverrideCreateAndroidSurfaceKHR(PFN_vkCreateAndroidSurfaceKHR             func,
                                                          VkResult                                  original_result,
                                                          VkInstance                                instance,
                                                          const VkAndroidSurfaceCreateInfoKHR*      pCreateInfo,
                                                          const VkAllocationCallbacks*              pAllocator,
                                                          const HandlePointerDecoder<VkSurfaceKHR>& original_surface,
                                                          VkSurfaceKHR*                             pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(original_surface);
    return CreateSurface(instance, pCreateInfo->flags, pSurface);
}

VkResult
VulkanReplayConsumerBase::OverrideCreateWin32SurfaceKHR(PFN_vkCreateWin32SurfaceKHR               func,
                                                        VkResult                                  original_result,
                                                        VkInstance                                instance,
                                                        const VkWin32SurfaceCreateInfoKHR*        pCreateInfo,
                                                        const VkAllocationCallbacks*              pAllocator,
                                                        const HandlePointerDecoder<VkSurfaceKHR>& original_surface,
                                                        VkSurfaceKHR*                             pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(original_surface);
    return CreateSurface(instance, pCreateInfo->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceWin32PresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physicalDevice), physicalDevice, queueFamilyIndex);
}

VkResult
VulkanReplayConsumerBase::OverrideCreateXcbSurfaceKHR(PFN_vkCreateXcbSurfaceKHR                 func,
                                                      VkResult                                  original_result,
                                                      VkInstance                                instance,
                                                      const VkXcbSurfaceCreateInfoKHR*          pCreateInfo,
                                                      const VkAllocationCallbacks*              pAllocator,
                                                      const HandlePointerDecoder<VkSurfaceKHR>& original_surface,
                                                      VkSurfaceKHR*                             pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(original_surface);
    return CreateSurface(instance, pCreateInfo->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceXcbPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
    VkPhysicalDevice                                 physicalDevice,
    uint32_t                                         queueFamilyIndex,
    xcb_connection_t*                                connection,
    xcb_visualid_t                                   visual_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(connection);
    GFXRECON_UNREFERENCED_PARAMETER(visual_id);
    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physicalDevice), physicalDevice, queueFamilyIndex);
}

VkResult
VulkanReplayConsumerBase::OverrideCreateXlibSurfaceKHR(PFN_vkCreateXlibSurfaceKHR                func,
                                                       VkResult                                  original_result,
                                                       VkInstance                                instance,
                                                       const VkXlibSurfaceCreateInfoKHR*         pCreateInfo,
                                                       const VkAllocationCallbacks*              pAllocator,
                                                       const HandlePointerDecoder<VkSurfaceKHR>& original_surface,
                                                       VkSurfaceKHR*                             pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(original_surface);
    return CreateSurface(instance, pCreateInfo->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceXlibPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
    VkPhysicalDevice                                  physicalDevice,
    uint32_t                                          queueFamilyIndex,
    Display*                                          dpy,
    VisualID                                          visualID)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(dpy);
    GFXRECON_UNREFERENCED_PARAMETER(visualID);
    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physicalDevice), physicalDevice, queueFamilyIndex);
}

VkResult
VulkanReplayConsumerBase::OverrideCreateWaylandSurfaceKHR(PFN_vkCreateWaylandSurfaceKHR             func,
                                                          VkResult                                  original_result,
                                                          VkInstance                                instance,
                                                          const VkWaylandSurfaceCreateInfoKHR*      pCreateInfo,
                                                          const VkAllocationCallbacks*              pAllocator,
                                                          const HandlePointerDecoder<VkSurfaceKHR>& original_surface,
                                                          VkSurfaceKHR*                             pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(original_surface);
    return CreateSurface(instance, pCreateInfo->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
    VkPhysicalDevice                                     physicalDevice,
    uint32_t                                             queueFamilyIndex,
    struct wl_display*                                   display)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(display);
    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physicalDevice), physicalDevice, queueFamilyIndex);
}

void VulkanReplayConsumerBase::OverrideDestroySurfaceKHR(PFN_vkDestroySurfaceKHR      func,
                                                         VkInstance                   instance,
                                                         VkSurfaceKHR                 surface,
                                                         const VkAllocationCallbacks* pAllocator)
{
    func(instance, surface, pAllocator);

    if (surface != VK_NULL_HANDLE)
    {
        auto entry = window_map_.find(surface);

        if (entry != window_map_.end())
        {
            window_factory_->Destroy(entry->second);
            window_map_.erase(entry);
        }
    }
}

void VulkanReplayConsumerBase::MapDescriptorUpdateTemplateHandles(VkDescriptorUpdateTemplate update_template,
                                                                  const DescriptorUpdateTemplateDecoder& decoder)
{
    size_t image_info_count        = decoder.GetImageInfoCount();
    size_t buffer_info_count       = decoder.GetBufferInfoCount();
    size_t texel_buffer_view_count = decoder.GetTexelBufferViewCount();

    if (image_info_count > 0)
    {
        auto image_types_iter = descriptor_update_template_image_types_.find(update_template);
        if (image_types_iter != descriptor_update_template_image_types_.end())
        {
            Decoded_VkDescriptorImageInfo* structs = decoder.GetImageInfoMetaStructPointer();
            for (size_t i = 0; i < image_info_count; ++i)
            {
                MapStructHandles(image_types_iter->second[i], &structs[i], object_mapper_);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Missing descriptor update template image descriptor type info; attempting to map both "
                               "VkDescriptorImageInfo handles");

            Decoded_VkDescriptorImageInfo* structs = decoder.GetImageInfoMetaStructPointer();
            for (size_t i = 0; i < image_info_count; ++i)
            {
                MapStructHandles(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, &structs[i], object_mapper_);
            }
        }
    }

    if (buffer_info_count > 0)
    {
        MapStructArrayHandles(decoder.GetBufferInfoMetaStructPointer(), buffer_info_count, object_mapper_);
    }

    if (texel_buffer_view_count > 0)
    {
        MapHandles<VkBufferView>(decoder.GetTexelBufferViewHandleIdsPointer(),
                                 texel_buffer_view_count,
                                 decoder.GetTexelBufferViewPointer(),
                                 texel_buffer_view_count,
                                 &VulkanObjectMapper::MapVkBufferView);
    }
}

void VulkanReplayConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(format::HandleId device,
                                                                         format::HandleId descriptorSet,
                                                                         format::HandleId descriptorUpdateTemplate,
                                                                         const DescriptorUpdateTemplateDecoder& pData)
{
    VkDevice                   in_device        = object_mapper_.MapVkDevice(device);
    VkDescriptorSet            in_descriptorSet = object_mapper_.MapVkDescriptorSet(descriptorSet);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate =
        object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(in_descriptorUpdateTemplate, pData);

    GetDeviceTable(in_device)->UpdateDescriptorSetWithTemplate(
        in_device, in_descriptorSet, in_descriptorUpdateTemplate, pData.GetPointer());
}

void VulkanReplayConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    format::HandleId                       commandBuffer,
    format::HandleId                       descriptorUpdateTemplate,
    format::HandleId                       layout,
    uint32_t                               set,
    const DescriptorUpdateTemplateDecoder& pData)
{
    VkCommandBuffer            in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate =
        object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);
    VkPipelineLayout in_layout = object_mapper_.MapVkPipelineLayout(layout);

    MapDescriptorUpdateTemplateHandles(in_descriptorUpdateTemplate, pData);

    GetDeviceTable(in_commandBuffer)
        ->CmdPushDescriptorSetWithTemplateKHR(
            in_commandBuffer, in_descriptorUpdateTemplate, in_layout, set, pData.GetPointer());
}

void VulkanReplayConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    format::HandleId                       device,
    format::HandleId                       descriptorSet,
    format::HandleId                       descriptorUpdateTemplate,
    const DescriptorUpdateTemplateDecoder& pData)
{
    VkDevice                   in_device        = object_mapper_.MapVkDevice(device);
    VkDescriptorSet            in_descriptorSet = object_mapper_.MapVkDescriptorSet(descriptorSet);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate =
        object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(in_descriptorUpdateTemplate, pData);

    GetDeviceTable(in_device)->UpdateDescriptorSetWithTemplateKHR(
        in_device, in_descriptorSet, in_descriptorUpdateTemplate, pData.GetPointer());
}

void VulkanReplayConsumerBase::Process_vkRegisterObjectsNVX(
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    format::HandleId                                           objectTable,
    uint32_t                                                   objectCount,
    const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& ppObjectTableEntries,
    const PointerDecoder<uint32_t>&                            pObjectIndices)
{
    VkDevice         in_device         = object_mapper_.MapVkDevice(device);
    VkObjectTableNVX in_objectTable    = object_mapper_.MapVkObjectTableNVX(objectTable);
    const uint32_t*  in_pObjectIndices = reinterpret_cast<const uint32_t*>(pObjectIndices.GetPointer());

    assert(objectCount == ppObjectTableEntries.GetLength());

    VkObjectTableEntryNVX**         in_ppObjectTableEntries         = ppObjectTableEntries.GetPointer();
    Decoded_VkObjectTableEntryNVX** in_ppObjectTableEntries_wrapper = ppObjectTableEntries.GetMetaStructPointer();

    // Map the object table entry handles.
    if ((in_ppObjectTableEntries != nullptr) && (in_ppObjectTableEntries_wrapper != nullptr))
    {
        for (size_t i = 0; i < objectCount; ++i)
        {
            if (in_ppObjectTableEntries[i] != nullptr)
            {
                VkObjectEntryTypeNVX type = in_ppObjectTableEntries[i]->type;

                if (type == VK_OBJECT_ENTRY_TYPE_DESCRIPTOR_SET_NVX)
                {
                    MapStructHandles(reinterpret_cast<Decoded_VkObjectTableDescriptorSetEntryNVX*>(
                                         in_ppObjectTableEntries_wrapper[i]),
                                     object_mapper_);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_PIPELINE_NVX)
                {
                    MapStructHandles(
                        reinterpret_cast<Decoded_VkObjectTablePipelineEntryNVX*>(in_ppObjectTableEntries_wrapper[i]),
                        object_mapper_);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_INDEX_BUFFER_NVX)
                {
                    MapStructHandles(
                        reinterpret_cast<Decoded_VkObjectTableIndexBufferEntryNVX*>(in_ppObjectTableEntries_wrapper[i]),
                        object_mapper_);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_VERTEX_BUFFER_NVX)
                {
                    MapStructHandles(reinterpret_cast<Decoded_VkObjectTableVertexBufferEntryNVX*>(
                                         in_ppObjectTableEntries_wrapper[i]),
                                     object_mapper_);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_PUSH_CONSTANT_NVX)
                {
                    MapStructHandles(reinterpret_cast<Decoded_VkObjectTablePushConstantEntryNVX*>(
                                         in_ppObjectTableEntries_wrapper[i]),
                                     object_mapper_);
                }
                else
                {
                    assert(true);
                    GFXRECON_LOG_ERROR("Skipping entry with unrecognized type at ppObjectTableEntries[%d] when "
                                       "processing vkRegisterObjectsNVX",
                                       i);
                }
            }
            else
            {
                GFXRECON_LOG_WARNING(
                    "Skipping null entry at ppObjectTableEntries[%d] when processing vkRegisterObjectsNVX", i);
            }
        }
    }

    VkResult replay_result = GetDeviceTable(in_device)->RegisterObjectsNVX(
        in_device, in_objectTable, objectCount, in_ppObjectTableEntries, in_pObjectIndices);

    CheckResult("vkRegisterObjectsNVX", returnValue, replay_result);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
