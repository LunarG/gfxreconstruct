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

#include "decode/vulkan_default_allocator.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/vulkan_object_info.h"
#include "generated/generated_vulkan_struct_decoders.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanDefaultAllocator::AllocateMemory(PFN_vkAllocateMemory                                      func,
                                                const DeviceInfo*                                         device_info,
                                                const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
                                                const VkAllocationCallbacks*                              pAllocator,
                                                HandlePointerDecoder<VkDeviceMemory>*                     pMemory)
{
    return func(device_info->handle, pAllocateInfo.GetPointer(), pAllocator, pMemory->GetHandlePointer());
}

void VulkanDefaultAllocator::FreeMemory(PFN_vkFreeMemory             func,
                                        const DeviceInfo*            device_info,
                                        const DeviceMemoryInfo*      memory_info,
                                        const VkAllocationCallbacks* pAllocator)
{
    VkDeviceMemory memory = VK_NULL_HANDLE;

    if (memory_info != nullptr)
    {
        memory = memory_info->handle;
    }

    func(device_info->handle, memory, pAllocator);
}

void VulkanDefaultAllocator::GetDeviceMemoryCommitment(PFN_vkGetDeviceMemoryCommitment func,
                                                       const DeviceInfo*               device_info,
                                                       const DeviceMemoryInfo*         memory_info,
                                                       VkDeviceSize*                   pCommittedMemoryInBytes)
{
    func(device_info->handle, memory_info->handle, pCommittedMemoryInBytes);
}

VkResult VulkanDefaultAllocator::BindBufferMemory(PFN_vkBindBufferMemory func,
                                                  const DeviceInfo*      device_info,
                                                  const BufferInfo*      buffer_info,
                                                  DeviceMemoryInfo*      memory_info,
                                                  VkDeviceSize           memoryOffset)
{
    return func(device_info->handle, buffer_info->handle, memory_info->handle, memoryOffset);
}

VkResult
VulkanDefaultAllocator::BindBufferMemory2(PFN_vkBindBufferMemory2                                     func,
                                          const DeviceInfo*                                           device_info,
                                          uint32_t                                                    bindInfoCount,
                                          const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos)
{
    return func(device_info->handle, bindInfoCount, pBindInfos.GetPointer());
}

VkResult VulkanDefaultAllocator::BindImageMemory(PFN_vkBindImageMemory func,
                                                 const DeviceInfo*     device_info,
                                                 const ImageInfo*      image_info,
                                                 DeviceMemoryInfo*     memory_info,
                                                 VkDeviceSize          memoryOffset)
{
    return func(device_info->handle, image_info->handle, memory_info->handle, memoryOffset);
}

VkResult VulkanDefaultAllocator::BindImageMemory2(PFN_vkBindImageMemory2 func,
                                                  const DeviceInfo*      device_info,
                                                  uint32_t               bindInfoCount,
                                                  const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos)
{
    return func(device_info->handle, bindInfoCount, pBindInfos.GetPointer());
}

VkResult VulkanDefaultAllocator::MapMemory(PFN_vkMapMemory   func,
                                           const DeviceInfo* device_info,
                                           DeviceMemoryInfo* memory_info,
                                           VkDeviceSize      offset,
                                           VkDeviceSize      size,
                                           VkMemoryMapFlags  flags,
                                           void**            ppData)
{
    return func(device_info->handle, memory_info->handle, offset, size, flags, ppData);
}

void VulkanDefaultAllocator::UnmapMemory(PFN_vkUnmapMemory func,
                                         const DeviceInfo* device_info,
                                         DeviceMemoryInfo* memory_info)
{
    func(device_info->handle, memory_info->handle);
}

VkResult
VulkanDefaultAllocator::FlushMappedMemoryRange(PFN_vkFlushMappedMemoryRanges func,
                                               const DeviceInfo*             device_info,
                                               uint32_t                      memoryRangeCount,
                                               const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges)
{
    return func(device_info->handle, memoryRangeCount, pMemoryRanges.GetPointer());
}

VkResult VulkanDefaultAllocator::InvalidateMappedMemoryRange(
    PFN_vkInvalidateMappedMemoryRanges                       func,
    const DeviceInfo*                                        device_info,
    uint32_t                                                 memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges)
{
    return func(device_info->handle, memoryRangeCount, pMemoryRanges.GetPointer());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
