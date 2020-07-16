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

#ifndef GFXRECON_DECODE_VULKAN_RESOURCE_TRACKING_CONSUMER_H
#define GFXRECON_DECODE_VULKAN_RESOURCE_TRACKING_CONSUMER_H

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

class VulkanResourceTrackingConsumer : public VulkanConsumer
{
  public:
    VulkanResourceTrackingConsumer(const ReplayOptions&          options,
                                   VulkanTrackedObjectInfoTable* tracked_object_info_table);

    virtual ~VulkanResourceTrackingConsumer() override;

    void InitializeLoader();

    void AddInstanceTable(VkInstance instance);

    void AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa);

    PFN_vkGetDeviceProcAddr GetDeviceAddrProc(VkPhysicalDevice physical_device);

    PFN_vkCreateDevice GetCreateDeviceProc(VkPhysicalDevice physical_device);

    const encode::InstanceTable* GetInstanceTable(const void* handle) const;

    const encode::DeviceTable* GetDeviceTable(const void* handle) const;

    virtual void Process_vkCreateInstance(VkResult                                             returnValue,
                                          StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                          HandlePointerDecoder<VkInstance>*                    pInstance) override;

    virtual void Process_vkCreateDevice(VkResult                                             returnValue,
                                        format::HandleId                                     physicalDevice,
                                        StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                        HandlePointerDecoder<VkDevice>*                      pDevice) override;

    virtual void Process_vkEnumeratePhysicalDevices(VkResult                                returnValue,
                                                    format::HandleId                        instance,
                                                    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                                    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices) override;

    virtual void Process_vkCreateBuffer(VkResult                                             returnValue,
                                        format::HandleId                                     device,
                                        StructPointerDecoder<Decoded_VkBufferCreateInfo>*    create_info,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                                        HandlePointerDecoder<VkBuffer>*                      buffer) override;

    virtual void Process_vkCreateImage(VkResult                                             returnValue,
                                       format::HandleId                                     device,
                                       StructPointerDecoder<Decoded_VkImageCreateInfo>*     create_info,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                                       HandlePointerDecoder<VkImage>*                       image) override;

    virtual void Process_vkAllocateMemory(VkResult                                             returnValue,
                                          format::HandleId                                     device,
                                          StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  allocate_info,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                                          HandlePointerDecoder<VkDeviceMemory>*                memory) override;

    virtual void Process_vkBindBufferMemory(VkResult         returnValue,
                                            format::HandleId device,
                                            format::HandleId buffer,
                                            format::HandleId memory,
                                            VkDeviceSize     memory_offset) override;

    virtual void Process_vkBindImageMemory(VkResult         returnValue,
                                           format::HandleId device,
                                           format::HandleId image,
                                           format::HandleId memory,
                                           VkDeviceSize     memory_offset) override;

    virtual void Process_vkBindBufferMemory2(VkResult                                              returnValue,
                                             format::HandleId                                      device,
                                             uint32_t                                              bindInfoCount,
                                             StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) override;

    virtual void Process_vkBindImageMemory2(VkResult                                             returnValue,
                                            format::HandleId                                     device,
                                            uint32_t                                             bindInfoCount,
                                            StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos) override;

    virtual void Process_vkMapMemory(VkResult                         returnValue,
                                     format::HandleId                 device,
                                     format::HandleId                 memory,
                                     VkDeviceSize                     offset,
                                     VkDeviceSize                     size,
                                     VkMemoryMapFlags                 flags,
                                     PointerDecoder<uint64_t, void*>* data_pointer) override;

    virtual void Process_vkGetBufferMemoryRequirements(
        format::HandleId                                    device,
        format::HandleId                                    buffer,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) override;

    virtual void Process_vkGetImageMemoryRequirements(
        format::HandleId                                    device,
        format::HandleId                                    image,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) override;

    virtual void Process_vkDestroyInstance(format::HandleId                                     instance,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkDestroyDevice(format::HandleId                                     device,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkDestroyBuffer(format::HandleId                                     device,
                                         format::HandleId                                     buffer,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkDestroyImage(format::HandleId                                     device,
                                        format::HandleId                                     image,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    void ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    void SortMemoriesBoundResourcesByOffset();

    void CalculateReplayBindingOffsetAndMemoryAllocationSize();

  protected:
    VulkanTrackedObjectInfoTable* GetTrackedObjectInfoTable() { return tracked_object_info_table_; }

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

    ReplayOptions                 options_;
    VulkanTrackedObjectInfoTable* tracked_object_info_table_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_RESOURCE_TRACKING_CONSUMER_BASE_H
