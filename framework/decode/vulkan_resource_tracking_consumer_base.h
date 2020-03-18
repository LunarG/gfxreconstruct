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

class VulkanResourceTrackingConsumerBase : public VulkanConsumer
{
  public:
    VulkanResourceTrackingConsumerBase(const ReplayOptions& options);

    virtual ~VulkanResourceTrackingConsumerBase() override;

    void InitializeLoader();

    void AddInstanceTable(VkInstance instance);

    void AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa);

    PFN_vkGetDeviceProcAddr GetDeviceAddrProc(VkPhysicalDevice physical_device);

    PFN_vkCreateDevice GetCreateDeviceProc(VkPhysicalDevice physical_device);

    const encode::InstanceTable* GetInstanceTable(const void* handle) const;

    const encode::DeviceTable* GetDeviceTable(const void* handle) const;

    void OverrideCreateInstance(const StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
                                StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                HandlePointerDecoder<VkInstance>*                         pInstance);

    void OverrideCreateDevice(format::HandleId                                        physicalDevice,
                              const StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
                              StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                              HandlePointerDecoder<VkDevice>*                         pDevice);

    void OverrideEnumeratePhysicalDevices(format::HandleId                        instance,
                                          PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                          HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices);

    void OverrideCreateBuffer(format::HandleId                                           device,
                              const StructPointerDecoder<Decoded_VkBufferCreateInfo>*    create_info,
                              const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                              HandlePointerDecoder<VkBuffer>*                            buffer);

    void OverrideCreateImage(format::HandleId                                           device,
                             const StructPointerDecoder<Decoded_VkImageCreateInfo>*     create_info,
                             const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                             HandlePointerDecoder<VkImage>*                             image);

    void OverrideAllocateMemory(format::HandleId                                           device,
                                const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  allocate_info,
                                const StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator,
                                HandlePointerDecoder<VkDeviceMemory>*                      memory);

    void OverrideBindBufferMemory(format::HandleId device,
                                  format::HandleId buffer,
                                  format::HandleId memory,
                                  VkDeviceSize     memory_offset);

    void OverrideBindImageMemory(format::HandleId device,
                                 format::HandleId image,
                                 format::HandleId memory,
                                 VkDeviceSize     memory_offset);

    void OverrideMapMemory(format::HandleId                 device,
                           format::HandleId                 memory,
                           VkDeviceSize                     offset,
                           VkDeviceSize                     size,
                           VkMemoryMapFlags                 flags,
                           PointerDecoder<uint64_t, void*>* data_pointer);

    void OverrideGetBufferMemoryRequirements(format::HandleId                                    device,
                                             format::HandleId                                    buffer,
                                             StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements);

    void OverrideGetImageMemoryRequirements(format::HandleId                                    device,
                                            format::HandleId                                    image,
                                            StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements);

    void OverrideDestroyInstance(format::HandleId                                     instance,
                                 StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideDestroyDevice(format::HandleId                                     device,
                               StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideDestroyBuffer(format::HandleId                                     device,
                               format::HandleId                                     buffer,
                               StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideDestroyImage(format::HandleId                                     device,
                              format::HandleId                                     image,
                              StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    void Process_vkUpdateDescriptorSetWithTemplate(format::HandleId                 device,
                                                   format::HandleId                 descriptor_set,
                                                   format::HandleId                 descriptor_update_template,
                                                   DescriptorUpdateTemplateDecoder* data) override;

    void Process_vkCmdPushDescriptorSetWithTemplateKHR(format::HandleId                 command_buffer,
                                                       format::HandleId                 descriptor_update_template,
                                                       format::HandleId                 layout,
                                                       uint32_t                         set,
                                                       DescriptorUpdateTemplateDecoder* data) override;

    void Process_vkUpdateDescriptorSetWithTemplateKHR(format::HandleId                 device,
                                                      format::HandleId                 descriptor_set,
                                                      format::HandleId                 descriptor_update_template,
                                                      DescriptorUpdateTemplateDecoder* data) override;

    VulkanTrackedObjectInfoTable& GetTrackedObjectInfoTable() { return tracked_object_info_table_; }

    void SortMemoriesBoundResourcesByOffset();

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
