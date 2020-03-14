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
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanDefaultAllocator::VulkanDefaultAllocator() : device_(VK_NULL_HANDLE) {}

VkResult VulkanDefaultAllocator::Initialize(uint32_t                                api_version,
                                            VkInstance                              instance,
                                            VkPhysicalDevice                        physical_device,
                                            VkDevice                                device,
                                            const std::vector<std::string>&         enabled_device_extensions,
                                            const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                            const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                            const Functions&                        functions)
{
    GFXRECON_UNREFERENCED_PARAMETER(api_version);
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(physical_device);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(enabled_device_extensions);
    GFXRECON_UNREFERENCED_PARAMETER(capture_memory_properties);
    GFXRECON_UNREFERENCED_PARAMETER(replay_memory_properties);

    device_    = device;
    functions_ = functions;

    return VK_SUCCESS;
}

void VulkanDefaultAllocator::Destroy()
{
    device_ = VK_NULL_HANDLE;
}

VkResult VulkanDefaultAllocator::CreateBuffer(const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
                                              const VkAllocationCallbacks*                            pAllocator,
                                              HandlePointerDecoder<VkBuffer>*                         pBuffer)
{
    return functions_.create_buffer(device_, pCreateInfo.GetPointer(), pAllocator, pBuffer->GetHandlePointer());
}

void VulkanDefaultAllocator::DestroyBuffer(BufferInfo* buffer_info, const VkAllocationCallbacks* pAllocator)
{
    functions_.destroy_buffer(device_, buffer_info->handle, pAllocator);
}

VkResult VulkanDefaultAllocator::CreateImage(const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
                                             const VkAllocationCallbacks*                           pAllocator,
                                             HandlePointerDecoder<VkImage>*                         pImage)
{
    return functions_.create_image(device_, pCreateInfo.GetPointer(), pAllocator, pImage->GetHandlePointer());
}

void VulkanDefaultAllocator::DestroyImage(ImageInfo* image_info, const VkAllocationCallbacks* pAllocator)
{
    functions_.destroy_image(device_, image_info->handle, pAllocator);
}

VkResult VulkanDefaultAllocator::AllocateMemory(const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
                                                const VkAllocationCallbacks*                              pAllocator,
                                                HandlePointerDecoder<VkDeviceMemory>*                     pMemory)
{
    return functions_.allocate_memory(device_, pAllocateInfo.GetPointer(), pAllocator, pMemory->GetHandlePointer());
}

void VulkanDefaultAllocator::FreeMemory(DeviceMemoryInfo* memory_info, const VkAllocationCallbacks* pAllocator)
{
    VkDeviceMemory memory = VK_NULL_HANDLE;

    if (memory_info != nullptr)
    {
        memory = memory_info->handle;
    }

    functions_.free_memory(device_, memory, pAllocator);
}

void VulkanDefaultAllocator::GetDeviceMemoryCommitment(const DeviceMemoryInfo* memory_info,
                                                       VkDeviceSize*           pCommittedMemoryInBytes)
{
    functions_.get_device_memory_commitment(device_, memory_info->handle, pCommittedMemoryInBytes);
}

VkResult VulkanDefaultAllocator::BindBufferMemory(BufferInfo*       buffer_info,
                                                  DeviceMemoryInfo* memory_info,
                                                  VkDeviceSize      memoryOffset)
{
    return functions_.bind_buffer_memory(device_, buffer_info->handle, memory_info->handle, memoryOffset);
}

VkResult VulkanDefaultAllocator::BindBufferMemory2(uint32_t                      bindInfoCount,
                                                   const VkBindBufferMemoryInfo* pBindInfos,
                                                   DeviceMemoryInfo* const*      memory_infos,
                                                   BufferInfo* const*            buffer_infos)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory_infos);
    GFXRECON_UNREFERENCED_PARAMETER(buffer_infos);

    return functions_.bind_buffer_memory2(device_, bindInfoCount, pBindInfos);
}

VkResult
VulkanDefaultAllocator::BindImageMemory(ImageInfo* image_info, DeviceMemoryInfo* memory_info, VkDeviceSize memoryOffset)
{
    return functions_.bind_image_memory(device_, image_info->handle, memory_info->handle, memoryOffset);
}

VkResult VulkanDefaultAllocator::BindImageMemory2(uint32_t                     bindInfoCount,
                                                  const VkBindImageMemoryInfo* pBindInfos,
                                                  DeviceMemoryInfo* const*     memory_infos,
                                                  ImageInfo* const*            image_infos)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory_infos);
    GFXRECON_UNREFERENCED_PARAMETER(image_infos);

    return functions_.bind_image_memory2(device_, bindInfoCount, pBindInfos);
}

VkResult VulkanDefaultAllocator::MapMemory(
    DeviceMemoryInfo* memory_info, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData)
{
    return functions_.map_memory(device_, memory_info->handle, offset, size, flags, ppData);
}

void VulkanDefaultAllocator::UnmapMemory(DeviceMemoryInfo* memory_info)
{
    functions_.unmap_memory(device_, memory_info->handle);
}

VkResult VulkanDefaultAllocator::FlushMappedMemoryRanges(uint32_t                   memoryRangeCount,
                                                         const VkMappedMemoryRange* pMemoryRanges,
                                                         DeviceMemoryInfo* const*   memory_infos)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory_infos);
    return functions_.flush_memory_ranges(device_, memoryRangeCount, pMemoryRanges);
}

VkResult VulkanDefaultAllocator::InvalidateMappedMemoryRanges(uint32_t                   memoryRangeCount,
                                                              const VkMappedMemoryRange* pMemoryRanges,
                                                              DeviceMemoryInfo* const*   memory_infos)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory_infos);
    return functions_.invalidate_memory_ranges(device_, memoryRangeCount, pMemoryRanges);
}

void VulkanDefaultAllocator::WriteMappedMemoryRange(const DeviceMemoryInfo* memory_info,
                                                    uint64_t                offset,
                                                    uint64_t                size,
                                                    const uint8_t*          data)
{
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
    size_t copy_size = static_cast<size_t>(size);
    util::platform::MemoryCopy(static_cast<uint8_t*>(memory_info->mapped_memory) + offset, copy_size, data, copy_size);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
