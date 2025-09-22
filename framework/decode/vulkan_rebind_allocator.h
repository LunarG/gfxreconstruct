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

#ifndef GFXRECON_DECODE_VULKAN_REBIND_ALLOCATOR_H
#define GFXRECON_DECODE_VULKAN_REBIND_ALLOCATOR_H

#include "decode/vulkan_resource_allocator.h"
#include "util/defines.h"

#include "vk_mem_alloc.h"

#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanRebindAllocator : public VulkanResourceAllocator
{
  public:
    VulkanRebindAllocator();

    ~VulkanRebindAllocator() override = default;

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
                                        ResourceData*                      allocator_data) override;

    virtual void DestroyVideoSession(VkVideoSessionKHR            session,
                                     const VkAllocationCallbacks* allocation_callbacks,
                                     ResourceData                 allocator_data) override;

    virtual void GetBufferMemoryRequirements(VkBuffer              buffer,
                                             VkMemoryRequirements* memory_requirements,
                                             ResourceData          allocator_data) override;

    virtual void GetBufferMemoryRequirements2(const VkBufferMemoryRequirementsInfo2* info,
                                              VkMemoryRequirements2*                 memory_requirements,
                                              ResourceData                           allocator_data) override;

    virtual void GetImageSubresourceLayout(VkImage                    image,
                                           const VkImageSubresource*  subresource,
                                           VkSubresourceLayout*       layout,
                                           const VkSubresourceLayout* original_layout,
                                           ResourceData               allocator_data) override;

    virtual void GetImageMemoryRequirements(VkImage               image,
                                            VkMemoryRequirements* memory_requirements,
                                            ResourceData          allocator_data) override;

    virtual void GetImageMemoryRequirements2(const VkImageMemoryRequirementsInfo2* info,
                                             VkMemoryRequirements2*                memory_requirements,
                                             ResourceData                          allocator_data) override;

    virtual VkResult GetVideoSessionMemoryRequirementsKHR(VkVideoSessionKHR video_session,
                                                          uint32_t*         memory_requirements_count,
                                                          VkVideoSessionMemoryRequirementsKHR* memory_requirements,
                                                          ResourceData                         allocator_data) override;

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
                                      VkMemoryPropertyFlags* bind_memory_properties) override
    {
        return BindBufferMemory(buffer,
                                memory,
                                memory_offset,
                                allocator_buffer_data,
                                allocator_memory_data,
                                bind_memory_properties,
                                capture_memory_properties_);
    }

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
                                     VkMemoryPropertyFlags* bind_memory_properties) override
    {
        return BindImageMemory(image,
                               memory,
                               memory_offset,
                               allocator_image_data,
                               allocator_memory_data,
                               bind_memory_properties,
                               capture_memory_properties_);
    }

    virtual VkResult BindImageMemory2(uint32_t                     bind_info_count,
                                      const VkBindImageMemoryInfo* bind_infos,
                                      const ResourceData*          allocator_image_datas,
                                      const MemoryData*            allocator_memory_datas,
                                      VkMemoryPropertyFlags*       bind_memory_properties) override;

    virtual VkResult BindVideoSessionMemory(VkVideoSessionKHR                      video_session,
                                            uint32_t                               bind_info_count,
                                            const VkBindVideoSessionMemoryInfoKHR* bind_infos,
                                            const ResourceData                     allocator_session_data,
                                            const MemoryData*                      allocator_memory_datas,
                                            VkMemoryPropertyFlags*                 bind_memory_properties) override;

    virtual VkResult MapMemory(VkDeviceMemory   memory,
                               VkDeviceSize     offset,
                               VkDeviceSize     size,
                               VkMemoryMapFlags flags,
                               void**           data,
                               MemoryData       allocator_data) override;

    virtual VkResult
    MapMemory2(const VkMemoryMapInfo* memory_map_info, void** data, MemoryData allocator_data) override;

    virtual void UnmapMemory(VkDeviceMemory memory, MemoryData allocator_data) override;

    virtual VkResult UnmapMemory2(const VkMemoryUnmapInfo* memory_unmap_info, MemoryData allocator_data) override;

    virtual VkResult FlushMappedMemoryRanges(uint32_t                   memory_range_count,
                                             const VkMappedMemoryRange* memory_ranges,
                                             const MemoryData*          allocator_datas) override;

    virtual VkResult InvalidateMappedMemoryRanges(uint32_t                   memory_range_count,
                                                  const VkMappedMemoryRange* memory_ranges,
                                                  const MemoryData*          allocator_datas) override;

    virtual VkResult SetDebugUtilsObjectNameEXT(VkDevice                       device,
                                                VkDebugUtilsObjectNameInfoEXT* name_info,
                                                uintptr_t                      allocator_data) override;

    virtual VkResult SetDebugUtilsObjectTagEXT(VkDevice                      device,
                                               VkDebugUtilsObjectTagInfoEXT* tag_info,
                                               uintptr_t                     allocator_data) override;

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
                                                       const ResourceData                     allocator_resource_data,
                                                       const MemoryData* allocator_memory_datas) override;

    virtual void
    ReportBindAccelerationStructureMemoryNVIncompatibility(uint32_t bind_info_count,
                                                           const VkBindAccelerationStructureMemoryInfoNV* bind_infos,
                                                           const ResourceData* allocator_acc_datas,
                                                           const MemoryData*   allocator_memory_datas) override;

    virtual void ReportQueueBindSparseIncompatibility(VkQueue                 queue,
                                                      uint32_t                bind_info_count,
                                                      const VkBindSparseInfo* bind_infos,
                                                      VkFence                 fence,
                                                      const ResourceData*     allocator_buf_datas,
                                                      const MemoryData*       allocator_buf_mem_datas,
                                                      const ResourceData*     allocator_img_op_datas,
                                                      const MemoryData*       allocator_img_op_mem_datas,
                                                      const ResourceData*     allocator_img_datas,
                                                      const MemoryData*       allocator_img_mem_datas) override;

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
        return AllocateMemory(allocate_info, allocation_callbacks, format::kNullHandleId, memory, allocator_data);
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
        return BindBufferMemory(buffer,
                                memory,
                                memory_offset,
                                allocator_buffer_data,
                                allocator_memory_data,
                                bind_memory_properties,
                                replay_memory_properties_);
    }

    virtual VkResult BindImageMemoryDirect(VkImage                image,
                                           VkDeviceMemory         memory,
                                           VkDeviceSize           memory_offset,
                                           ResourceData           allocator_image_data,
                                           MemoryData             allocator_memory_data,
                                           VkMemoryPropertyFlags* bind_memory_properties) override
    {
        return BindImageMemory(image,
                               memory,
                               memory_offset,
                               allocator_image_data,
                               allocator_memory_data,
                               bind_memory_properties,
                               replay_memory_properties_);
    }

    virtual VkResult MapResourceMemoryDirect(VkDeviceSize     size,
                                             VkMemoryMapFlags flags,
                                             void**           data,
                                             ResourceData     allocator_data) override;

    virtual void UnmapResourceMemoryDirect(ResourceData) override {}

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

    virtual bool SupportsOpaqueDeviceAddresses() override { return false; }
    virtual bool SupportBindVideoSessionMemory() override { return true; }

    virtual void SetDeviceMemoryPriority(VkDeviceMemory memory, float priority, MemoryData allocator_data) override;

    virtual VkResult GetMemoryRemoteAddressNV(const VkMemoryGetRemoteAddressInfoNV* memory_get_remote_address_info,
                                              VkRemoteAddressNV*                    address,
                                              MemoryData                            allocator_data) override;

    virtual VkResult CreateAccelerationStructureNV(const VkAccelerationStructureCreateInfoNV* create_info,
                                                   const VkAllocationCallbacks*               allocation_callbacks,
                                                   format::HandleId                           capture_id,
                                                   VkAccelerationStructureNV*                 acc_str,
                                                   ResourceData*                              allocator_data) override;

    virtual void DestroyAccelerationStructureNV(VkAccelerationStructureNV    acc_str,
                                                const VkAllocationCallbacks* allocation_callbacks,
                                                ResourceData                 allocator_data) override;

    virtual void
    GetAccelerationStructureMemoryRequirementsNV(const VkAccelerationStructureMemoryRequirementsInfoNV* info,
                                                 VkMemoryRequirements2KHR* memory_requirements,
                                                 ResourceData              allocator_data) override;

    virtual VkResult BindAccelerationStructureMemoryNV(uint32_t                                       bind_info_count,
                                                       const VkBindAccelerationStructureMemoryInfoNV* bind_infos,
                                                       const ResourceData*    allocator_acc_datas,
                                                       const MemoryData*      allocator_memory_datas,
                                                       VkMemoryPropertyFlags* bind_memory_properties) override;

    virtual VkResult GetMemoryFd(const VkMemoryGetFdInfoKHR* get_fd_info, int* pFd, MemoryData allocator_data) override;

    virtual VkResult QueueBindSparse(VkQueue                 queue,
                                     uint32_t                bind_info_count,
                                     const VkBindSparseInfo* bind_infos,
                                     VkFence                 fence,
                                     ResourceData*           allocator_buf_datas,
                                     const MemoryData*       allocator_buf_mem_datas,
                                     VkMemoryPropertyFlags*  bind_buf_mem_properties,
                                     ResourceData*           allocator_img_op_datas,
                                     const MemoryData*       allocator_img_op_mem_datas,
                                     VkMemoryPropertyFlags*  bind_img_op_mem_properties,
                                     ResourceData*           allocator_img_datas,
                                     const MemoryData*       allocator_img_mem_datas,
                                     VkMemoryPropertyFlags*  bind_img_mem_properties) override;

    virtual uint64_t GetDeviceMemoryOpaqueCaptureAddress(const VkDeviceMemoryOpaqueCaptureAddressInfo* info,
                                                         MemoryData allocator_data) override;

  private:
    struct MemoryAllocInfo;

    struct SubresourceLayouts
    {
        VkImageSubresource  subresource{};
        VkSubresourceLayout original{};
        VkSubresourceLayout rebind{};
    };

    enum MemoryInfoType
    {
        kBasic,       // single: buffer, image
        kSparse,      // array: buffer, image
        kVideoSession // array: video_session
    };

    // Create a new allocation for a binding memory case.
    struct VmaMemoryInfo
    {
        MemoryAllocInfo*        memory_info{ nullptr };
        VkMemoryRequirements    mem_req{};
        VmaAllocationCreateInfo alc_create_info{};
        VkDeviceSize            offset_from_original_device_memory{ 0 };

        VmaAllocation     allocation{ VK_NULL_HANDLE };
        VmaAllocationInfo allocation_info{};

        bool             is_host_visible{ false };
        void*            mapped_pointer{ nullptr };

        bool is_compatible(VkDeviceSize                   offset,
                           const VkMemoryRequirements&    req,
                           const VmaAllocationCreateInfo& create_info) const
        {
            // memory offset and size is in the range. mem_req and create_info are the same.
            if (((offset >= offset_from_original_device_memory) &&
                 ((offset + req.size) <= (offset_from_original_device_memory + mem_req.size))) &&
                ((req.alignment == mem_req.alignment) && (req.memoryTypeBits == mem_req.memoryTypeBits) &&
                 (create_info.flags == alc_create_info.flags) && (create_info.usage == alc_create_info.usage) &&
                 (create_info.requiredFlags == alc_create_info.requiredFlags) &&
                 (create_info.preferredFlags == alc_create_info.preferredFlags) &&
                 (create_info.memoryTypeBits == alc_create_info.memoryTypeBits) &&
                 (create_info.pool == alc_create_info.pool) && (create_info.priority == alc_create_info.priority)))
            {
                return true;
            }
            return false;
        }
    };

    struct ResourceAllocInfo
    {
        MemoryInfoType              memory_info_type;
        std::vector<VmaMemoryInfo*> bound_memory_infos; // VideoSeesion and sparse could be multiple bindings.
        VkObjectType                object_type{ VK_OBJECT_TYPE_UNKNOWN };
        VkFlags                     usage{ 0 };
        VkImageTiling               tiling{};
        uint32_t                    height{ 0 };
        bool                        uses_extensions{ false };
        VkFormat                    format{ VK_FORMAT_UNDEFINED };

        std::string          debug_utils_name;
        std::vector<uint8_t> debug_utils_tag;
        uint64_t             debug_utils_tag_name;

        // Image layouts for performing mapped memory writes to linear images with different capture/replay memory
        // alignments.
        std::vector<SubresourceLayouts> layouts;
    };

    struct MemoryAllocInfo
    {
        format::HandleId                                 capture_id{ format::kNullHandleId };
        VkDeviceSize                                     allocation_size{ 0 };
        uint32_t                                         original_index{ std::numeric_limits<uint32_t>::max() };
        bool                                             is_mapped{ false };
        VkDeviceSize                                     mapped_offset{ 0 };
        AHardwareBuffer*                                 ahb{ nullptr };
        VkDeviceMemory                                   ahb_memory{ VK_NULL_HANDLE };
        std::unique_ptr<uint8_t[]>                       original_content;
        std::unordered_map<uint64_t, ResourceAllocInfo*> original_objects; // Key is object handle.

        std::vector<std::unique_ptr<VmaMemoryInfo>> vma_mem_infos;

        std::string          debug_utils_name;
        std::vector<uint8_t> debug_utils_tag;
        uint64_t             debug_utils_tag_name;
    };

  private:
    void WriteBoundResource(ResourceAllocInfo* resource_alloc_info,
                            VmaMemoryInfo*     bound_memory_info,
                            VkDeviceSize       src_offset,
                            VkDeviceSize       dst_offset,
                            VkDeviceSize       data_size,
                            const uint8_t*     data);

    void WriteBoundResourceStaging(ResourceAllocInfo* resource_alloc_info,
                                   VmaMemoryInfo*     bound_memory_info,
                                   size_t             src_offset,
                                   size_t             dst_offset,
                                   size_t             data_size,
                                   const uint8_t*     data);

    void WriteBoundResourceDirect(ResourceAllocInfo* resource_alloc_info,
                                  VmaMemoryInfo*     bound_memory_info,
                                  size_t             src_offset,
                                  size_t             dst_offset,
                                  size_t             data_size,
                                  const uint8_t*     data);

    // Identify sub-ranges of resources that overlap with a memory region from their original memory binding.  If the
    // resource overlapped with the original range, the src_offset is the offset from the start of the original
    // resource, the dst_offset is the offset from the start of the new resource allocation, and the data_size is the
    // region of the resource that overlaps with the original memory region.
    bool TranslateMemoryRange(const VmaMemoryInfo* bound_memory_info,
                              VkDeviceSize         oiriginal_start,
                              VkDeviceSize         original_end,
                              VkDeviceSize*        src_offset,
                              VkDeviceSize*        dst_offset,
                              VkDeviceSize*        data_size);

    void UpdateBoundResource(ResourceAllocInfo* resource_alloc_info,
                             VmaMemoryInfo*     bound_memory_info,
                             VkDeviceSize       write_start,
                             VkDeviceSize       write_end,
                             const uint8_t*     data);

    VkResult UpdateMappedMemoryRange(VmaMemoryInfo* bound_memory_info,
                                     VkDeviceSize   oiriginal_start,
                                     VkDeviceSize   original_end,
                                     VkResult (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize));

    VkResult UpdateMappedMemoryRanges(uint32_t                   memory_range_count,
                                      const VkMappedMemoryRange* memory_ranges,
                                      const MemoryData*          allocator_datas,
                                      VkResult (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize));

    VmaMemoryUsage GetBufferMemoryUsage(VkBufferUsageFlags          buffer_usage,
                                        VkMemoryPropertyFlags       capture_properties,
                                        const VkMemoryRequirements& replay_requirements);

    VmaMemoryUsage GetImageMemoryUsage(VkImageUsageFlags           image_usage,
                                       VkImageTiling               tiling,
                                       VkMemoryPropertyFlags       capture_properties,
                                       const VkMemoryRequirements& replay_requirements);

    VmaMemoryUsage GetVideoSeesionMemoryUsage(VkMemoryPropertyFlags       capture_properties,
                                              const VkMemoryRequirements& replay_requirements);

    VmaMemoryUsage AdjustMemoryUsage(VmaMemoryUsage desired_usage, const VkMemoryRequirements& replay_requirements);

    void ReportBindIncompatibility(const ResourceData* allocator_resource_datas, uint32_t resource_count);

    VkResult BindBufferMemory(VkBuffer                                buffer,
                              VkDeviceMemory                          memory,
                              VkDeviceSize                            memory_offset,
                              ResourceData                            allocator_buffer_data,
                              MemoryData                              allocator_memory_data,
                              VkMemoryPropertyFlags*                  bind_memory_properties,
                              const VkPhysicalDeviceMemoryProperties& device_memory_properties);

    VkResult AllocateAHBMemory(MemoryAllocInfo* memory_alloc_info, const VkImage image);

    VkResult BindImageMemory(VkImage                                 image,
                             VkDeviceMemory                          memory,
                             VkDeviceSize                            memory_offset,
                             ResourceData                            allocator_image_data,
                             MemoryData                              allocator_memory_data,
                             VkMemoryPropertyFlags*                  bind_memory_properties,
                             const VkPhysicalDeviceMemoryProperties& device_memory_properties);

    void SetBindingDebugUtilsNameAndTag(const MemoryAllocInfo*   memory_alloc_info,
                                        const ResourceAllocInfo* resource_alloc_info,
                                        VkDeviceMemory           device_memory,
                                        uint64_t                 resource_handle);

    VkResult AllocateMemoryForBuffer(VkBuffer                                buffer,
                                     VkDeviceSize                            memory_offset,
                                     const VkPhysicalDeviceMemoryProperties& device_memory_properties,
                                     ResourceAllocInfo&                      resource_alloc_info,
                                     MemoryAllocInfo&                        memory_alloc_info,
                                     VmaMemoryInfo**                         vma_mem_info);

    VkResult AllocateMemoryForImage(VkImage                                 image,
                                    VkDeviceSize                            memory_offset,
                                    const VkPhysicalDeviceMemoryProperties& device_memory_properties,
                                    ResourceAllocInfo&                      resource_alloc_info,
                                    MemoryAllocInfo&                        memory_alloc_info,
                                    VmaMemoryInfo**                         vma_mem_info);

    // If it's bind by vma function, like vmaBindBufferMemory2, vmaBindBufferImage2, get the offset from it.
    VkDeviceSize GetRebindOffsetFromVMA(VkDeviceSize original_offset, const VmaMemoryInfo& vma_mem_info);

    // If it bind by vk function, like vkBindVideoSessionMemory, vkQueueBindSparse, get the offset from it.
    VkDeviceSize GetRebindOffsetFromOriginalDeviceMemory(VkDeviceSize         original_offset,
                                                         const VmaMemoryInfo& vma_mem_info);

    VkResult VmaAllocateMemory(MemoryAllocInfo&            memory_alloc_info,
                               VkDeviceSize                original_offset,
                               const VkMemoryRequirements& mem_req,
                               VmaMemoryUsage              usage,
                               VmaMemoryInfo**             vma_mem_info);

    bool FindVmaMemoryInfo(MemoryAllocInfo&               memory_alloc_info,
                           VkDeviceSize                   original_offset,
                           const VkMemoryRequirements&    mem_req,
                           const VmaAllocationCreateInfo& alc_create_info,
                           VmaMemoryInfo**                vma_mem_info);

    void UpdateAllocInfo(ResourceAllocInfo&     resource_alloc_info,
                         uint64_t               object_handle,
                         MemoryInfoType         memory_info_type,
                         MemoryAllocInfo&       memory_alloc_info,
                         VmaMemoryInfo&         vma_mem_info,
                         VkMemoryPropertyFlags& bind_memory_property);

    enum QueueBindSparseType
    {
        kBindBuffer,
        kBindImageOpaqueMemory,
        kBindImageMemory
    };

    VkResult ProcessSingleQueueBindSparse(VkQueue                   queue,
                                          VkFence                   fence,
                                          QueueBindSparseType       type,
                                          const VkBindSparseInfo&   original_bind_info,
                                          bool                      is_last_bind_info,
                                          uint32_t                  object_bind_index,
                                          uint32_t                  memory_bind_index,
                                          std::vector<VkSemaphore>& semaphores,
                                          ResourceData              allocator_data,
                                          MemoryData                allocator_mem_data,
                                          VkMemoryPropertyFlags     mem_properties);

  private:
    VkDevice                         device_ = VK_NULL_HANDLE;
    VmaAllocator                     allocator_;
    Functions                        functions_;
    VmaVulkanFunctions               vma_functions_;
    VkPhysicalDeviceType             capture_device_type_;
    VkPhysicalDeviceMemoryProperties capture_memory_properties_;
    VkPhysicalDeviceMemoryProperties replay_memory_properties_;
    VkCommandBuffer                  cmd_buffer_    = VK_NULL_HANDLE;
    VkCommandPool                    cmd_pool_      = VK_NULL_HANDLE;
    VkQueue                          staging_queue_ = VK_NULL_HANDLE;
    uint32_t                         staging_queue_family_{};
    std::vector<VkSemaphore>         queue_bind_sparse_semaphores;

    //! define a general minimum alignment for buffers
    uint32_t min_buffer_alignment_ = 128;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REBIND_ALLOCATOR_H
