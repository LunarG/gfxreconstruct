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
    VulkanDefaultAllocator();

    virtual VkResult Initialize(uint32_t                                api_version,
                                VkInstance                              instance,
                                VkPhysicalDevice                        physical_device,
                                VkDevice                                device,
                                const std::vector<std::string>&         enabled_device_extensions,
                                const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                const Functions&                        functions) override;

    virtual void Destroy() override;

    virtual VkResult CreateBuffer(const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
                                  const VkAllocationCallbacks*                            pAllocator,
                                  HandlePointerDecoder<VkBuffer>*                         pBuffer) override;

    virtual void DestroyBuffer(BufferInfo* buffer_info, const VkAllocationCallbacks* pAllocator) override;

    virtual VkResult CreateImage(const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
                                 const VkAllocationCallbacks*                           pAllocator,
                                 HandlePointerDecoder<VkImage>*                         pImage) override;

    virtual void DestroyImage(ImageInfo* image_info, const VkAllocationCallbacks* pAllocator) override;

    virtual VkResult AllocateMemory(const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
                                    const VkAllocationCallbacks*                              pAllocator,
                                    HandlePointerDecoder<VkDeviceMemory>*                     pMemory) override;

    virtual void FreeMemory(DeviceMemoryInfo* memory_info, const VkAllocationCallbacks* pAllocator) override;

    virtual void GetDeviceMemoryCommitment(const DeviceMemoryInfo* memory_info,
                                           VkDeviceSize*           pCommittedMemoryInBytes) override;

    virtual VkResult
    BindBufferMemory(BufferInfo* buffer_info, DeviceMemoryInfo* memory_info, VkDeviceSize memoryOffset) override;

    virtual VkResult BindBufferMemory2(uint32_t                                                    bindInfoCount,
                                       const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos) override;

    virtual VkResult
    BindImageMemory(ImageInfo* image_info, DeviceMemoryInfo* memory_info, VkDeviceSize memoryOffset) override;

    virtual VkResult BindImageMemory2(uint32_t                                                   bindInfoCount,
                                      const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos) override;

    virtual VkResult MapMemory(DeviceMemoryInfo* memory_info,
                               VkDeviceSize      offset,
                               VkDeviceSize      size,
                               VkMemoryMapFlags  flags,
                               void**            ppData) override;

    virtual void UnmapMemory(DeviceMemoryInfo* memory_info) override;

    virtual VkResult
    FlushMappedMemoryRanges(uint32_t                                                 memoryRangeCount,
                            const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges) override;

    virtual VkResult
    InvalidateMappedMemoryRanges(uint32_t                                                 memoryRangeCount,
                                 const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges) override;

    virtual void WriteMappedMemoryRange(const DeviceMemoryInfo* memory_info,
                                        uint64_t                offset,
                                        uint64_t                size,
                                        const uint8_t*          data) override;

  protected:
    VkDevice         GetDevice() const { return device_; }
    const Functions& GetFunctions() const { return functions_; }

  private:
    VkDevice  device_;
    Functions functions_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DEFAULT_ALLOCATOR_H
