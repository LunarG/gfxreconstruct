//=============================================================================
/// Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file   vulkan_resource_tracking_consumer_base.h
/// \brief  Header file of vulkan resource_tracking_consumer_base class,
///         which is used to track memory data mapping during
///         the first pass of the replay. This data will then be
///         used in second pass of replay for memory portability.
//=============================================================================

#ifndef GFXRECON_DECODE_VULKAN_RESOURCE_TRACKING_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_RESOURCE_TRACKING_CONSUMER_BASE_H

#include "decode/vulkan_tracked_object_info.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "decode/vulkan_replay_options.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_consumer.h"
#include "generated/generated_vulkan_dispatch_table.h"

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstdio>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// The class is used to track memory data mapping during
// the first pass of the replay. This data will then be
// used in second pass of replay for memory portability.
class VulkanResourceTrackingConsumerBase : public VulkanConsumer
{
  public:
    VulkanResourceTrackingConsumerBase(const ReplayOptions& options);

    virtual ~VulkanResourceTrackingConsumerBase() override;

    // Initialize Loader and set key function pointers like vkGetInstanceProcAddr, vkCreateInstance.
    void InitializeLoader();

    // Query dispatch_key then load instance table.
    void AddInstanceTable(VkInstance instance);

    // Query dispatch key through device, get and load device table.
    void AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa);

    // Get proc address for physical device.
    PFN_vkGetDeviceProcAddr GetDeviceAddrProc(VkPhysicalDevice physical_device);

    // Get proc address for creating device.
    PFN_vkCreateDevice GetCreateDeviceProc(VkPhysicalDevice physical_device);

    // Get dispatch key through object handle then return the instance table.
    const encode::InstanceTable* GetInstanceTable(const void* handle) const;

    // Get dispatch key through object handle then find and return related device table.
    const encode::DeviceTable* GetDeviceTable(const void* handle) const;

    // Get info for TrackedInstanceInfo, this is vkCreateInstance handling for resource tracking during playback
    // decoding.
    void OverrideCreateInstance(const StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                HandlePointerDecoder<VkInstance>*                          pInstance);

    // Used for setting TrackedDeviceInfo, this is vkCreateDevice handling for resource tracking during playback
    // decoding.
    void OverrideCreateDevice(format::HandleId                                           physicalDevice,
                              const StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                              const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                              HandlePointerDecoder<VkDevice>*                            pDevice);

    // vkEnumeratePhysicalDevices handling for resource tracking during playback decoding. Mainly used for setting
    // TrackedPhysicalDeviceInfo for enumerated physical devices.
    void OverrideEnumeratePhysicalDevices(format::HandleId                        instance,
                                          PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                          HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices);

    // vkCreateBuffer handling for resource tracking during playback decoding. TrackedResourceInfo of target buffer will
    // be set through this function.
    void OverrideCreateBuffer(format::HandleId                                           device,
                              const StructPointerDecoder<Decoded_VkBufferCreateInfo>*    create_info,
                              const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                              HandlePointerDecoder<VkBuffer>*                            buffer);

    // vkCreateImage handling for resource tracking during playback decoding. TrackedResourceInfo of target image will
    // be set through this function.
    void OverrideCreateImage(format::HandleId                                           device,
                             const StructPointerDecoder<Decoded_VkImageCreateInfo>*     create_info,
                             const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                             HandlePointerDecoder<VkImage>*                             image);

    // vkAllocateMemory handling for resource tracking during playback decoding. TrackedDeviceMemoryInfo of the memory
    // will be set through this function.
    void OverrideAllocateMemory(format::HandleId                                           device,
                                const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  allocate_info,
                                const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                                HandlePointerDecoder<VkDeviceMemory>*                      memory);

    // vkBindBufferMemory handling for resource tracking during playback decoding. Both buffer and memory object track
    // info will be updated through this function.
    void OverrideBindBufferMemory(format::HandleId device,
                                  format::HandleId buffer,
                                  format::HandleId memory,
                                  VkDeviceSize     memory_offset);

    // vkBindImageMemory handling for resource tracking during playback decoding. Both image and memory object track
    // info will be updated through this function.
    void OverrideBindImageMemory(format::HandleId device,
                                 format::HandleId image,
                                 format::HandleId memory,
                                 VkDeviceSize     memory_offset);

    // vkBindBufferMemory2 handling for resource tracking during playback decoding. Both buffer and memory object track
    // info will be updated through this function if target app use this call bind image to memory.
    void OverrideBindBufferMemory2(format::HandleId                                            device,
                                   uint32_t                                                    bindInfoCount,
                                   const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos);

    // vkBindImageMemory2 handling for resource tracking during playback decoding.  Both image and memory object track
    // info will be updated through this function if target app use this call bind buffer to memory.
    void OverrideBindImageMemory2(format::HandleId                                           device,
                                  uint32_t                                                   bindInfoCount,
                                  const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos);

    // vkMapMemory handling for resource tracking during playback decoding. This memory object track info will be
    // updated to record this mapping.
    void OverrideMapMemory(format::HandleId                 device,
                           format::HandleId                 memory,
                           VkDeviceSize                     offset,
                           VkDeviceSize                     size,
                           VkMemoryMapFlags                 flags,
                           PointerDecoder<uint64_t, void*>* data_pointer);

    // vkGetBufferMemoryRequirements handling for resource tracking during playback decoding. Buffer track info will be
    // updated through this function.
    void OverrideGetBufferMemoryRequirements(format::HandleId                                    device,
                                             format::HandleId                                    buffer,
                                             StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements);

    // vkGetImageMemoryRequirements handling for resource tracking during playback decoding. Image track info will be
    // updated through this function.
    void OverrideGetImageMemoryRequirements(format::HandleId                                    device,
                                            format::HandleId                                    image,
                                            StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements);

    // vkDestroyInstance handling for resource tracking during playback decoding. Query instance real object handle
    // through trackinfo and destroy the instance.
    void OverrideDestroyInstance(format::HandleId                                           instance,
                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    // vkDestroyDevice handling for resource tracking during playback decoding. Query the device real object handle
    // through trackinfo and destroy the device.
    void OverrideDestroyDevice(format::HandleId                                           device,
                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    // vkDestroyBuffer handling for resource tracking during playback decoding. Query the buffer real object handle
    // through trackinfo and destroy the buffer.
    void OverrideDestroyBuffer(format::HandleId                                           device,
                               format::HandleId                                           buffer,
                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    // vkDestroyImage handling for resource tracking during playback decoding.Query the image real object handle through
    // trackinfo and destroy the image.
    void OverrideDestroyImage(format::HandleId                                           device,
                              format::HandleId                                           image,
                              const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    // Handling for fill memory command when processing meta data.
    void ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    // return tracked object info table.
    VulkanTrackedObjectInfoTable& GetTrackedObjectInfoTable() { return tracked_object_info_table_; }

    // Sort the bound resources in each device memory object according to their trace binding offset.
    void SortMemoriesBoundResourcesByOffset();

    // Calculate the replay binding offset and memory allocation size.
    void CalculateReplayBindingOffsetAndMemoryAllocationSize();

  private:
    util::platform::LibraryHandle loader_handle_;

    // map to function pointers to API calls
    std::unordered_map<encode::DispatchKey, PFN_vkGetDeviceProcAddr> get_device_proc_addrs_;
    std::unordered_map<encode::DispatchKey, PFN_vkCreateDevice>      create_device_procs_;
    std::unordered_map<encode::DispatchKey, encode::InstanceTable>   instance_tables_;
    std::unordered_map<encode::DispatchKey, encode::DeviceTable>     device_tables_;
    // funtion pointers to the API calls that will be made during the first pass of replay
    PFN_vkCreateInstance      create_instance_function_;
    PFN_vkGetInstanceProcAddr get_instance_proc_addr_;

    ReplayOptions                options_;
    VulkanTrackedObjectInfoTable tracked_object_info_table_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_RESOURCE_TRACKING_CONSUMER_BASE_H
