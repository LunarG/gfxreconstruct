/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_DEFAULT_ALLOCATOR_H
#define GFXRECON_DECODE_VULKAN_DEFAULT_ALLOCATOR_H

#include "decode/vulkan_resource_allocator.h"
#include "util/defines.h"

#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanDefaultAllocator : public VulkanResourceAllocator
{
  public:
    VulkanDefaultAllocator();

    VulkanDefaultAllocator(const std::string& custom_error_string);

    VulkanDefaultAllocator(std::string&& custom_error_string);

    virtual VkResult Initialize(uint32_t                                api_version,
                                VkInstance                              instance,
                                VkPhysicalDevice                        physical_device,
                                VkDevice                                device,
                                const std::vector<std::string>&         enabled_device_extensions,
                                VkPhysicalDeviceType                    capture_device_type,
                                const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                const Functions&                        functions) override;

    virtual void Destroy() override;

    virtual VkResult CreateBuffer(const VkBufferCreateInfo*    create_info,
                                  const VkAllocationCallbacks* allocation_callbacks,
                                  format::HandleId             capture_id,
                                  VkBuffer*                    buffer,
                                  ResourceData*                allocator_data) override;

    virtual void DestroyBuffer(VkBuffer                     buffer,
                               const VkAllocationCallbacks* allocation_callbacks,
                               ResourceData                 allocator_data) override;

    virtual VkResult CreateImage(const VkImageCreateInfo*     create_info,
                                 const VkAllocationCallbacks* allocation_callbacks,
                                 format::HandleId             capture_id,
                                 VkImage*                     image,
                                 ResourceData*                allocator_data) override;

    virtual void DestroyImage(VkImage                      image,
                              const VkAllocationCallbacks* allocation_callbacks,
                              ResourceData                 allocator_data) override;

    virtual VkResult CreateVideoSession(const VkVideoSessionCreateInfoKHR* create_info,
                                        const VkAllocationCallbacks*       allocation_callbacks,
                                        format::HandleId                   capture_id,
                                        VkVideoSessionKHR*                 session,
                                        std::vector<ResourceData>*         allocator_datas) override;

    virtual void DestroyVideoSession(VkVideoSessionKHR            session,
                                     const VkAllocationCallbacks* allocation_callbacks,
                                     std::vector<ResourceData>    allocator_datas) override;

    virtual void GetImageSubresourceLayout(VkImage                    image,
                                           const VkImageSubresource*  subresource,
                                           VkSubresourceLayout*       layout,
                                           const VkSubresourceLayout* original_layout,
                                           ResourceData               allocator_data) override;

    virtual VkResult AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                    const VkAllocationCallbacks* allocation_callbacks,
                                    format::HandleId             capture_id,
                                    VkDeviceMemory*              memory,
                                    MemoryData*                  allocator_data) override;

    virtual void FreeMemory(VkDeviceMemory               memory,
                            const VkAllocationCallbacks* allocation_callbacks,
                            MemoryData                   allocator_data) override;

    virtual void GetDeviceMemoryCommitment(VkDeviceMemory memory,
                                           VkDeviceSize*  committed_memory_in_bytes,
                                           MemoryData     allocator_data) override;

    virtual VkResult BindBufferMemory(VkBuffer               buffer,
                                      VkDeviceMemory         memory,
                                      VkDeviceSize           memory_offset,
                                      ResourceData           allocator_buffer_data,
                                      MemoryData             allocator_memory_data,
                                      VkMemoryPropertyFlags* bind_memory_properties) override;

    virtual VkResult BindBufferMemory2(uint32_t                      bind_info_count,
                                       const VkBindBufferMemoryInfo* bind_infos,
                                       const ResourceData*           allocator_buffer_datas,
                                       const MemoryData*             allocator_memory_datas,
                                       VkMemoryPropertyFlags*        bind_memory_properties) override;

    virtual VkResult BindImageMemory(VkImage                image,
                                     VkDeviceMemory         memory,
                                     VkDeviceSize           memory_offset,
                                     ResourceData           allocator_image_data,
                                     MemoryData             allocator_memory_data,
                                     VkMemoryPropertyFlags* bind_memory_properties) override;

    virtual VkResult BindImageMemory2(uint32_t                     bind_info_count,
                                      const VkBindImageMemoryInfo* bind_infos,
                                      const ResourceData*          allocator_image_datas,
                                      const MemoryData*            allocator_memory_datas,
                                      VkMemoryPropertyFlags*       bind_memory_properties) override;

    virtual VkResult BindVideoSessionMemory(VkVideoSessionKHR                      video_session,
                                            uint32_t                               bind_info_count,
                                            const VkBindVideoSessionMemoryInfoKHR* bind_infos,
                                            const ResourceData*                    allocator_session_datas,
                                            const MemoryData*                      allocator_memory_datas,
                                            VkMemoryPropertyFlags*                 bind_memory_properties) override;

    virtual VkResult MapMemory(VkDeviceMemory   memory,
                               VkDeviceSize     offset,
                               VkDeviceSize     size,
                               VkMemoryMapFlags flags,
                               void**           data,
                               MemoryData       allocator_data) override;

    virtual void UnmapMemory(VkDeviceMemory memory, MemoryData allocator_data) override;

    virtual VkResult FlushMappedMemoryRanges(uint32_t                   memory_range_count,
                                             const VkMappedMemoryRange* memory_ranges,
                                             const MemoryData*          allocator_datas) override;

    virtual VkResult InvalidateMappedMemoryRanges(uint32_t                   memory_range_count,
                                                  const VkMappedMemoryRange* memory_ranges,
                                                  const MemoryData*          allocator_datas) override;

    virtual VkResult
    WriteMappedMemoryRange(MemoryData allocator_data, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void ReportAllocateMemoryIncompatibility(const VkMemoryAllocateInfo* allocate_info) override;

    virtual void ReportBindBufferIncompatibility(VkBuffer     buffer,
                                                 ResourceData allocator_resource_data,
                                                 MemoryData   allocator_memory_data) override;

    virtual void ReportBindBuffer2Incompatibility(uint32_t                      bind_info_count,
                                                  const VkBindBufferMemoryInfo* bind_infos,
                                                  const ResourceData*           allocator_resource_datas,
                                                  const MemoryData*             allocator_memory_datas) override;

    virtual void ReportBindImageIncompatibility(VkImage      image,
                                                ResourceData allocator_resource_data,
                                                MemoryData   allocator_memory_data) override;

    virtual void ReportBindImage2Incompatibility(uint32_t                     bind_info_count,
                                                 const VkBindImageMemoryInfo* bind_infos,
                                                 const ResourceData*          allocator_resource_datas,
                                                 const MemoryData*            allocator_memory_datas) override;

    virtual void ReportBindVideoSessionIncompatibility(VkVideoSessionKHR                      video_session,
                                                       uint32_t                               bind_info_count,
                                                       const VkBindVideoSessionMemoryInfoKHR* bind_infos,
                                                       const ResourceData*                    allocator_resource_datas,
                                                       const MemoryData* allocator_memory_datas) override;

    // Direct allocation methods that perform memory allocation and resource creation without performing memory
    // translation.  These methods allow the replay tool to allocate staging resources through the resource allocator so
    // that the allocator is aware of all allocations performed at replay.
    virtual VkResult CreateBufferDirect(const VkBufferCreateInfo*    create_info,
                                        const VkAllocationCallbacks* allocation_callbacks,
                                        VkBuffer*                    buffer,
                                        ResourceData*                allocator_data) override
    {
        return CreateBuffer(create_info, allocation_callbacks, format::kNullHandleId, buffer, allocator_data);
    }

    virtual void DestroyBufferDirect(VkBuffer                     buffer,
                                     const VkAllocationCallbacks* allocation_callbacks,
                                     ResourceData                 allocator_data) override
    {
        DestroyBuffer(buffer, allocation_callbacks, allocator_data);
    }

    virtual VkResult CreateImageDirect(const VkImageCreateInfo*     create_info,
                                       const VkAllocationCallbacks* allocation_callbacks,
                                       VkImage*                     image,
                                       ResourceData*                allocator_data) override
    {
        return CreateImage(create_info, allocation_callbacks, format::kNullHandleId, image, allocator_data);
    }

    virtual void DestroyImageDirect(VkImage                      image,
                                    const VkAllocationCallbacks* allocation_callbacks,
                                    ResourceData                 allocator_data) override
    {
        DestroyImage(image, allocation_callbacks, allocator_data);
    }

    virtual VkResult AllocateMemoryDirect(const VkMemoryAllocateInfo*  allocate_info,
                                          const VkAllocationCallbacks* allocation_callbacks,
                                          VkDeviceMemory*              memory,
                                          MemoryData*                  allocator_data) override
    {
        return Allocate(allocate_info, allocation_callbacks, format::kNullHandleId, memory, allocator_data);
    }

    virtual void FreeMemoryDirect(VkDeviceMemory               memory,
                                  const VkAllocationCallbacks* allocation_callbacks,
                                  MemoryData                   allocator_data) override
    {
        FreeMemory(memory, allocation_callbacks, allocator_data);
    }

    virtual VkResult BindBufferMemoryDirect(VkBuffer               buffer,
                                            VkDeviceMemory         memory,
                                            VkDeviceSize           memory_offset,
                                            ResourceData           allocator_buffer_data,
                                            MemoryData             allocator_memory_data,
                                            VkMemoryPropertyFlags* bind_memory_properties) override
    {
        return BindBufferMemory(
            buffer, memory, memory_offset, allocator_buffer_data, allocator_memory_data, bind_memory_properties);
    }

    virtual VkResult BindImageMemoryDirect(VkImage                image,
                                           VkDeviceMemory         memory,
                                           VkDeviceSize           memory_offset,
                                           ResourceData           allocator_image_data,
                                           MemoryData             allocator_memory_data,
                                           VkMemoryPropertyFlags* bind_memory_properties) override
    {
        return BindImageMemory(
            image, memory, memory_offset, allocator_image_data, allocator_memory_data, bind_memory_properties);
    }

    virtual VkResult MapResourceMemoryDirect(VkDeviceSize     size,
                                             VkMemoryMapFlags flags,
                                             void**           data,
                                             ResourceData     allocator_data) override;

    virtual void UnmapResourceMemoryDirect(ResourceData allocator_data) override;

    virtual VkResult FlushMappedMemoryRangesDirect(uint32_t                   memory_range_count,
                                                   const VkMappedMemoryRange* memory_ranges,
                                                   const MemoryData*          allocator_datas) override
    {
        return FlushMappedMemoryRanges(memory_range_count, memory_ranges, allocator_datas);
    }

    virtual VkResult InvalidateMappedMemoryRangesDirect(uint32_t                   memory_range_count,
                                                        const VkMappedMemoryRange* memory_ranges,
                                                        const MemoryData*          allocator_datas) override
    {
        return InvalidateMappedMemoryRanges(memory_range_count, memory_ranges, allocator_datas);
    }

    virtual bool SupportsOpaqueDeviceAddresses() override { return true; }

    virtual bool SupportBindVideoSessionMemory() override { return false; }

  protected:
    struct ResourceAllocInfo
    {
        format::HandleId capture_id{ format::kNullHandleId };
        VkDeviceMemory   bound_memory{ VK_NULL_HANDLE };
        VkDeviceSize     bound_offset{ 0 };
    };

    struct MemoryAllocInfo
    {
        format::HandleId      capture_id{ format::kNullHandleId };
        uint32_t              memory_type_index{ std::numeric_limits<uint32_t>::max() };
        VkMemoryPropertyFlags property_flags{ 0 };
        uint8_t*              mapped_pointer{ nullptr };
    };

  protected:
    const ResourceAllocInfo* GetResourceAllocInfo(ResourceData allocator_data) const
    {
        return reinterpret_cast<ResourceAllocInfo*>(allocator_data);
    }

    const MemoryAllocInfo* GetMemoryAllocInfo(MemoryData allocator_data) const
    {
        return reinterpret_cast<MemoryAllocInfo*>(allocator_data);
    }

    VkResult Allocate(const VkMemoryAllocateInfo*  allocate_info,
                      const VkAllocationCallbacks* allocation_callbacks,
                      format::HandleId             capture_id,
                      VkDeviceMemory*              memory,
                      MemoryData*                  allocator_data);

  private:
    void ReportBindIncompatibility(const VkMemoryRequirements* requirements,
                                   const MemoryData*           allocator_memory_datas,
                                   uint32_t                    resource_count);

  private:
    VkDevice                         device_;
    Functions                        functions_;
    VkPhysicalDeviceMemoryProperties memory_properties_;
    std::string                      custom_error_string_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DEFAULT_ALLOCATOR_H
