/*
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef BRIMSTONE_FORMAT_METADATA_HANDLER_H
#define BRIMSTONE_FORMAT_METADATA_HANDLER_H

#include <cinttypes>
#include <cstdio>
#include <vector>
#include <string>
#include <mutex>
#include <unordered_map>

#include "util/defines.h"
#include "format/metadata.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

#define ALLOC_USED_FOR_BUFFER 0x00000001
#define ALLOC_USED_FOR_IMAGE 0x00000002
#define ALLOC_USED_FOR_SPARSE 0x00000004
#define ALLOC_USED_FOR_PROTECTED 0x00000008

#if 0 // Brainpain
#define CURRENT_HISTORIC_ALLOCATION_METADATA_VERSION 1
struct HistoricAllocationMetadata
{
    uint32_t      struct_version;
    uint32_t      alloc_used_for_flags;
    VkDeviceSize* high_water_marks; // Only for images/buffers defined in above ALLOC_USED_... flags
};

#define CURRENT_MEMORY_METADATA_VERSION 1
struct HistoricAllocationsMetadata
{
    uint32_t                    struct_version;
    uint32_t                    num_allocations;
    HistoricAllocationMetadata* allocation_info;
};
#endif // Brainpain

struct InternalMemoryTypeMetadata
{
    VkMemoryPropertyFlags flags;
    VkMemoryPropertyFlags unique_flags;
    VkMemoryPropertyFlags largest_of_flags;
    VkMemoryPropertyFlags largest_of_remaining_flags;
    uint32_t              heap_index;
};

struct InternalMemoryHeapMetadata
{
    VkMemoryHeapFlags flags;
    VkMemoryHeapFlags unique_flags;
    VkMemoryHeapFlags largest_of_flags;
    VkMemoryHeapFlags largest_of_remaining_flags;
    VkDeviceSize      size;
    VkDeviceSize      remaining_size;
};

struct InternalPhysicalDeviceMemoryDescriptor
{
    bool                                    matches_recording;
    std::vector<InternalMemoryTypeMetadata> types;
    std::vector<InternalMemoryHeapMetadata> heaps;
};

struct InternalPhysicalDeviceMetadata
{
    VkPhysicalDeviceProperties             device_props;
    InternalPhysicalDeviceMemoryDescriptor memory_desc;
    std::vector<VkQueueFamilyProperties>   queue_family_props;
    bool                                   is_device_group;
    uint32_t                               index_in_device_group;
    std::vector<VkPhysicalDevice>          grouped_phys_devices;
    bool                                   group_supports_subset_alloc;
    VkDeviceSize                           device_local_mem_size;
    VkDeviceSize                           host_visible_mem_size;
    VkDeviceSize                           host_coherent_mem_size;
    VkDeviceSize                           host_cached_mem_size;
    VkDeviceSize                           protected_mem_size;
};

struct InternalInstanceMetadata
{
    uint32_t                                                             desired_api_version;
    std::vector<std::string>                                             instance_extensions;
    std::unordered_map<VkPhysicalDevice, InternalPhysicalDeviceMetadata> physical_device_info;
};

struct InternalDeviceInfo
{
    VkInstance       instance;
    VkPhysicalDevice physical_device;
};

struct InternalAllocationInfo
{
    VkDevice                                   device;
    uint32_t                                   type_index;
    uint32_t                                   heap_index;
    uint32_t                                   used_for_flags;
    AllocateMemoryMetadata                     metadata;
    std::unordered_map<uint32_t, VkDeviceSize> cur_size;
    std::unordered_map<uint32_t, VkDeviceSize> high_water_marks;
};

struct InternalBufferInfo
{
    VkDeviceMemory      current_memory;
    VkBufferCreateFlags create_flags;
    VkBufferUsageFlags  usage_flags;
    VkSharingMode       sharing_mode;
    VkDeviceSize        estimated_size;
};

struct InternalImageInfo
{
    VkDeviceMemory     current_memory;
    VkImageCreateFlags create_flags;
    VkImageUsageFlags  usage_flags;
    VkImageTiling      tiling;
    VkSharingMode      sharing_mode;
    VkDeviceSize       estimated_size;
};

class ParameterEncoder;

class MetadataHandler
{
  public:
    MetadataHandler();
    ~MetadataHandler();

    // Public methods used for recording metadata
    size_t RecordingUpdate_CreateInstance(const VkInstanceCreateInfo*  create_info,
                                          const VkAllocationCallbacks* alloc_callbacks,
                                          VkInstance*                  instance);
    size_t RecordingUpdate_DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator);
    size_t
           RecordingUpdate_EnumeratePhysicalDevices(VkInstance instance, uint32_t* count, VkPhysicalDevice* phys_devices);
    size_t RecordingUpdate_EnumeratePhysicalDeviceGroups(VkInstance                       instance,
                                                         uint32_t*                        count,
                                                         VkPhysicalDeviceGroupProperties* phys_device_groups);
    bool   Generate_CreateDeviceMetadata(VkPhysicalDevice             phys_device,
                                         const VkDeviceCreateInfo*    create_info,
                                         const VkAllocationCallbacks* alloc_callbacks,
                                         VkDevice*                    device,
                                         CreateDeviceMetadata*        create_device_metadata);
    void   Destroy_CreateDeviceMetadata(CreateDeviceMetadata* create_device_metadata);
    size_t RecordingUpdate_DestroyDevice(VkDevice device, const VkAllocationCallbacks* allocator);
    bool   Generate_AllocateMemoryMetadata(VkDevice                     device,
                                           const VkMemoryAllocateInfo*  allocate_info,
                                           const VkAllocationCallbacks* allocator,
                                           VkDeviceMemory*              memory,
                                           AllocateMemoryMetadata*      allocate_memory_metadata);
    void   Destroy_AllocateMemoryMetadata(AllocateMemoryMetadata* allocate_memory_metadata);
    size_t RecordingUpdate_FreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* allocator);
    size_t RecordingUpdate_CreateBuffer(VkDevice                     device,
                                        const VkBufferCreateInfo*    create_info,
                                        const VkAllocationCallbacks* alloc_callbacks,
                                        VkBuffer*                    buffer);
    size_t RecordingUpdate_CreateImage(VkDevice                     device,
                                       const VkImageCreateInfo*     create_info,
                                       const VkAllocationCallbacks* alloc_callbacks,
                                       VkImage*                     image);
    size_t RecordingUpdate_BindBufferMemory(VkDevice       device,
                                            VkBuffer       buffer,
                                            VkDeviceMemory memory,
                                            VkDeviceSize   memory_offset);
    size_t
           RecordingUpdate_BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memory_offset);
    size_t RecordingUpdate_GetBufferMemoryRequirements(VkDevice              device,
                                                       VkBuffer              buffer,
                                                       VkMemoryRequirements* memory_requirements);
    size_t RecordingUpdate_GetImageMemoryRequirements(VkDevice              device,
                                                      VkImage               image,
                                                      VkMemoryRequirements* memory_requirements);
    size_t RecordingUpdate_GetImageSparseMemoryRequirements(VkDevice                         device,
                                                            VkImage                          image,
                                                            uint32_t*                        memory_requirement_count,
                                                            VkSparseImageMemoryRequirements* memory_requirements);
    size_t RecordingUpdate_DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* allocator);
    size_t RecordingUpdate_DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* allocator);

    // Public methods used for playing back using metadata
    size_t PlaybackUpdate_CreateInstance(const VkInstanceCreateInfo*  create_info,
                                         const VkAllocationCallbacks* alloc_callbacks,
                                         VkInstance*                  instance);
    size_t PlaybackUpdate_DestroyInstance(VkInstance instance, const VkAllocationCallbacks* allocator);
    size_t
           PlaybackUpdate_EnumeratePhysicalDevices(VkInstance instance, uint32_t* count, VkPhysicalDevice* phys_devices);
    size_t PlaybackUpdate_EnumeratePhysicalDeviceGroups(VkInstance                       instance,
                                                        uint32_t*                        count,
                                                        VkPhysicalDeviceGroupProperties* phys_device_groups);
    size_t PlaybackDecode_CreateDevice(const uint8_t*               buffer,
                                       size_t                       buffer_size,
                                       VkPhysicalDevice             phys_device,
                                       const VkDeviceCreateInfo*    create_info,
                                       const VkAllocationCallbacks* alloc_callbacks,
                                       VkDevice*                    device,
                                       CreateDeviceMetadata*        create_device_metadata);
    size_t PlaybackUpdate_DestroyDevice(VkDevice device, const VkAllocationCallbacks* allocator);
    size_t PlaybackDecode_AllocateMemory(const uint8_t*               buffer,
                                         size_t                       buffer_size,
                                         VkDevice                     device,
                                         const VkMemoryAllocateInfo*  allocate_info,
                                         const VkAllocationCallbacks* allocator,
                                         VkDeviceMemory*              memory,
                                         AllocateMemoryMetadata*      allocate_memory_metadata);

  private:
    // General private methods
    bool DetermineMemoryTypeSize(VkInstance               instance,
                                 VkPhysicalDevice         phys_device,
                                 VkMemoryPropertyFlagBits memory_flag,
                                 VkDeviceSize&            size);
    bool FindInstanceForPhysicalDevice(VkPhysicalDevice phys_device, VkInstance& instance);
    bool General_CreateInstance(const VkInstanceCreateInfo*  create_info,
                                const VkAllocationCallbacks* alloc_callbacks,
                                VkInstance*                  instance);
    bool General_DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator);
    bool General_EnumeratePhysicalDevices(VkInstance instance, uint32_t* count, VkPhysicalDevice* phys_devices);
    bool General_EnumeratePhysicalDeviceGroups(VkInstance                       instance,
                                               uint32_t*                        count,
                                               VkPhysicalDeviceGroupProperties* phys_device_groups);
    bool General_FreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* allocator);

    // Allocation tracking info
    uint32_t   alloc_index_ = 0;
    std::mutex alloc_index_mutex_;

    // Global items used for assisting in tracking and generating the metadata.
    std::unordered_map<VkInstance, InternalInstanceMetadata>                instance_tracker_;
    VkInstance                                                              last_enum_instance_;
    std::unordered_map<VkDevice, InternalDeviceInfo>                        device_info_;
    std::unordered_map<VkDeviceMemory, std::vector<InternalAllocationInfo>> alloc_info_;
    std::unordered_map<VkBuffer, InternalBufferInfo>                        buffer_info_;
    std::unordered_map<VkImage, InternalImageInfo>                          image_info_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_METADATA_HANDLER_H
