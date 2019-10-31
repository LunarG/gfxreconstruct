/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_DEFAULT_ALLOCATOR_H
#define GFXRECON_DECODE_VULKAN_DEFAULT_ALLOCATOR_H

#include "decode/vulkan_resource_allocator.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanDefaultAllocator : public VulkanResourceAllocator
{
  public:
    virtual VkResult AllocateMemory(PFN_vkAllocateMemory                                      func,
                                    const DeviceInfo*                                         device_info,
                                    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
                                    const VkAllocationCallbacks*                              pAllocator,
                                    HandlePointerDecoder<VkDeviceMemory>*                     pMemory) override;

    virtual void FreeMemory(PFN_vkFreeMemory             func,
                            const DeviceInfo*            device_info,
                            const DeviceMemoryInfo*      memory_info,
                            const VkAllocationCallbacks* pAllocator) override;

    virtual void GetDeviceMemoryCommitment(PFN_vkGetDeviceMemoryCommitment func,
                                           const DeviceInfo*               device_info,
                                           const DeviceMemoryInfo*         memory_info,
                                           VkDeviceSize*                   pCommittedMemoryInBytes) override;

    virtual VkResult BindBufferMemory(PFN_vkBindBufferMemory func,
                                      const DeviceInfo*      device_info,
                                      const BufferInfo*      buffer_info,
                                      DeviceMemoryInfo*      memory_info,
                                      VkDeviceSize           memoryOffset) override;

    virtual VkResult BindBufferMemory2(PFN_vkBindBufferMemory2                                     func,
                                       const DeviceInfo*                                           device_info,
                                       uint32_t                                                    bindInfoCount,
                                       const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos) override;

    virtual VkResult BindImageMemory(PFN_vkBindImageMemory func,
                                     const DeviceInfo*     device_info,
                                     const ImageInfo*      image_info,
                                     DeviceMemoryInfo*     memory_info,
                                     VkDeviceSize          memoryOffset) override;

    virtual VkResult BindImageMemory2(PFN_vkBindImageMemory2                                     func,
                                      const DeviceInfo*                                          device_info,
                                      uint32_t                                                   bindInfoCount,
                                      const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos) override;

    virtual VkResult MapMemory(PFN_vkMapMemory   func,
                               const DeviceInfo* device_info,
                               DeviceMemoryInfo* memory_info,
                               VkDeviceSize      offset,
                               VkDeviceSize      size,
                               VkMemoryMapFlags  flags,
                               void**            ppData) override;

    virtual void
    UnmapMemory(PFN_vkUnmapMemory func, const DeviceInfo* device_info, DeviceMemoryInfo* memory_info) override;

    virtual VkResult
    FlushMappedMemoryRange(PFN_vkFlushMappedMemoryRanges                            func,
                           const DeviceInfo*                                        device_info,
                           uint32_t                                                 memoryRangeCount,
                           const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges) override;

    virtual VkResult
    InvalidateMappedMemoryRange(PFN_vkInvalidateMappedMemoryRanges                       func,
                                const DeviceInfo*                                        device_info,
                                uint32_t                                                 memoryRangeCount,
                                const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges) override;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DEFAULT_ALLOCATOR_H
