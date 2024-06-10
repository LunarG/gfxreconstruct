/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
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
    VulkanResourceTrackingConsumer(const VulkanReplayOptions&    options,
                                   VulkanTrackedObjectInfoTable* tracked_object_info_table);

    virtual ~VulkanResourceTrackingConsumer() override;

    void InitializeLoader();

    void AddInstanceTable(VkInstance instance);

    void AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa);

    PFN_vkGetDeviceProcAddr GetDeviceAddrProc(VkPhysicalDevice physical_device);

    PFN_vkCreateDevice GetCreateDeviceProc(VkPhysicalDevice physical_device);

    const encode::VulkanInstanceTable* GetInstanceTable(const void* handle) const;

    const encode::VulkanDeviceTable* GetDeviceTable(const void* handle) const;

    virtual void Process_vkCreateInstance(const ApiCallInfo&                                   call_info,
                                          VkResult                                             returnValue,
                                          StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                          HandlePointerDecoder<VkInstance>*                    pInstance) override;

    virtual void Process_vkCreateDevice(const ApiCallInfo&                                   call_info,
                                        VkResult                                             returnValue,
                                        format::HandleId                                     physicalDevice,
                                        StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                        HandlePointerDecoder<VkDevice>*                      pDevice) override;

    virtual void Process_vkEnumeratePhysicalDevices(const ApiCallInfo&                      call_info,
                                                    VkResult                                returnValue,
                                                    format::HandleId                        instance,
                                                    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                                    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices) override;

    virtual void Process_vkCreateBuffer(const ApiCallInfo&                                   call_info,
                                        VkResult                                             returnValue,
                                        format::HandleId                                     device,
                                        StructPointerDecoder<Decoded_VkBufferCreateInfo>*    create_info,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                                        HandlePointerDecoder<VkBuffer>*                      buffer) override;

    virtual void Process_vkCreateImage(const ApiCallInfo&                                   call_info,
                                       VkResult                                             returnValue,
                                       format::HandleId                                     device,
                                       StructPointerDecoder<Decoded_VkImageCreateInfo>*     create_info,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                                       HandlePointerDecoder<VkImage>*                       image) override;

    virtual void Process_vkAllocateMemory(const ApiCallInfo&                                   call_info,
                                          VkResult                                             returnValue,
                                          format::HandleId                                     device,
                                          StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  allocate_info,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                                          HandlePointerDecoder<VkDeviceMemory>*                memory) override;

    virtual void Process_vkBindBufferMemory(const ApiCallInfo& call_info,
                                            VkResult           returnValue,
                                            format::HandleId   device,
                                            format::HandleId   buffer,
                                            format::HandleId   memory,
                                            VkDeviceSize       memory_offset) override;

    virtual void Process_vkBindImageMemory(const ApiCallInfo& call_info,
                                           VkResult           returnValue,
                                           format::HandleId   device,
                                           format::HandleId   image,
                                           format::HandleId   memory,
                                           VkDeviceSize       memory_offset) override;

    virtual void Process_vkBindBufferMemory2(const ApiCallInfo&                                    call_info,
                                             VkResult                                              returnValue,
                                             format::HandleId                                      device,
                                             uint32_t                                              bindInfoCount,
                                             StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) override;

    virtual void Process_vkBindImageMemory2(const ApiCallInfo&                                   call_info,
                                            VkResult                                             returnValue,
                                            format::HandleId                                     device,
                                            uint32_t                                             bindInfoCount,
                                            StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos) override;

    virtual void Process_vkMapMemory(const ApiCallInfo&               call_info,
                                     VkResult                         returnValue,
                                     format::HandleId                 device,
                                     format::HandleId                 memory,
                                     VkDeviceSize                     offset,
                                     VkDeviceSize                     size,
                                     VkMemoryMapFlags                 flags,
                                     PointerDecoder<uint64_t, void*>* data_pointer) override;

    virtual void Process_vkGetBufferMemoryRequirements(
        const ApiCallInfo&                                  call_info,
        format::HandleId                                    device,
        format::HandleId                                    buffer,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) override;

    virtual void Process_vkGetImageMemoryRequirements(
        const ApiCallInfo&                                  call_info,
        format::HandleId                                    device,
        format::HandleId                                    image,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) override;

    virtual void Process_vkDestroyInstance(const ApiCallInfo&                                   call_info,
                                           format::HandleId                                     instance,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkDestroyDevice(const ApiCallInfo&                                   call_info,
                                         format::HandleId                                     device,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkDestroyBuffer(const ApiCallInfo&                                   call_info,
                                         format::HandleId                                     device,
                                         format::HandleId                                     buffer,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkDestroyImage(const ApiCallInfo&                                   call_info,
                                        format::HandleId                                     device,
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
    std::unordered_map<encode::VulkanDispatchKey, PFN_vkGetDeviceProcAddr>     get_device_proc_addrs_;
    std::unordered_map<encode::VulkanDispatchKey, PFN_vkCreateDevice>          create_device_procs_;
    std::unordered_map<encode::VulkanDispatchKey, encode::VulkanInstanceTable> instance_tables_;
    std::unordered_map<encode::VulkanDispatchKey, encode::VulkanDeviceTable>   device_tables_;
    // funtion pointers to the API calls that will be made during the first pass of replay
    PFN_vkCreateInstance      create_instance_function_;
    PFN_vkGetInstanceProcAddr get_instance_proc_addr_;

    VulkanReplayOptions           options_;
    VulkanTrackedObjectInfoTable* tracked_object_info_table_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_RESOURCE_TRACKING_CONSUMER_BASE_H
