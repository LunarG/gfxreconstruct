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

#include <unordered_map>
#include <string>
#include <sstream>
#include <mutex>

#include "util/platform.h"
#include "format/metadata_handler.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

MetadataHandler::MetadataHandler()
{
    last_enum_instance_ = VK_NULL_HANDLE;
    alloc_index_        = 0;
}

MetadataHandler::~MetadataHandler()
{
    instance_tracker_.clear();
    device_info_.clear();
    alloc_info_.clear();
    last_enum_instance_ = VK_NULL_HANDLE;
}

static bool GenerateMemoryDesc(VkPhysicalDevice phys_device, InternalPhysicalDeviceMemoryDescriptor& descriptor)
{
    try
    {
        VkPhysicalDeviceMemoryProperties memory_props;
        vkGetPhysicalDeviceMemoryProperties(phys_device, &memory_props);

        descriptor.types.resize(memory_props.memoryTypeCount);
        descriptor.heaps.resize(memory_props.memoryHeapCount);
        for (uint32_t type = 0; type < memory_props.memoryTypeCount; ++type)
        {
            descriptor.types[type]                            = {};
            descriptor.types[type].flags                      = memory_props.memoryTypes[type].propertyFlags;
            descriptor.types[type].unique_flags               = memory_props.memoryTypes[type].propertyFlags;
            descriptor.types[type].largest_of_flags           = memory_props.memoryTypes[type].propertyFlags;
            descriptor.types[type].largest_of_remaining_flags = memory_props.memoryTypes[type].propertyFlags;
            descriptor.types[type].heap_index                 = memory_props.memoryTypes[type].heapIndex;
        }
        for (uint32_t heap = 0; heap < memory_props.memoryHeapCount; ++heap)
        {
            descriptor.heaps[heap]                            = {};
            descriptor.heaps[heap].flags                      = memory_props.memoryHeaps[heap].flags;
            descriptor.heaps[heap].unique_flags               = memory_props.memoryHeaps[heap].flags;
            descriptor.heaps[heap].largest_of_flags           = memory_props.memoryHeaps[heap].flags;
            descriptor.heaps[heap].largest_of_remaining_flags = memory_props.memoryHeaps[heap].flags;
            descriptor.heaps[heap].size                       = memory_props.memoryHeaps[heap].size;
            descriptor.heaps[heap].remaining_size             = memory_props.memoryHeaps[heap].size;
        }

        // Generate the comparison type information
        for (uint32_t type = 0; type < memory_props.memoryTypeCount; ++type)
        {
            VkDeviceSize cur_type_heap_size = descriptor.heaps[descriptor.types[type].heap_index].size;
            for (uint32_t other_type = 0; other_type < memory_props.memoryTypeCount; ++other_type)
            {
                if (type == other_type)
                {
                    continue;
                }
                VkMemoryPropertyFlags other_type_flags = descriptor.types[other_type].flags;
                descriptor.types[type].unique_flags &= ~other_type_flags;
                VkDeviceSize other_type_heap_size = descriptor.heaps[descriptor.types[other_type].heap_index].size;
                if (other_type_heap_size > cur_type_heap_size)
                {
                    descriptor.types[type].largest_of_flags &= ~other_type_flags;
                    descriptor.types[type].largest_of_remaining_flags &= ~other_type_flags;
                }
            }
        }

        // Generate the comparison heap information
        for (uint32_t heap = 0; heap < memory_props.memoryHeapCount; ++heap)
        {
            VkDeviceSize cur_heap_size = descriptor.heaps[heap].size;
            for (uint32_t other_heap = 0; other_heap < memory_props.memoryHeapCount; ++other_heap)
            {
                if (heap == other_heap)
                {
                    continue;
                }
                VkMemoryHeapFlags other_heap_flags = descriptor.heaps[other_heap].flags;
                descriptor.heaps[heap].unique_flags &= ~other_heap_flags;
                VkDeviceSize other_heap_size = descriptor.heaps[other_heap].size;
                if (other_heap_size > cur_heap_size)
                {
                    descriptor.heaps[heap].largest_of_flags &= ~other_heap_flags;
                    descriptor.heaps[heap].largest_of_remaining_flags &= ~other_heap_flags;
                }
            }
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

// Update the largest of the heap and type information based on the remaining heap size
static bool UpdateMemoryDesc(InternalPhysicalDeviceMemoryDescriptor& descriptor)
{
    uint32_t type_count = descriptor.types.size();
    uint32_t heap_count = descriptor.heaps.size();

    // Generate the comparison type information
    for (uint32_t type = 0; type < type_count; ++type)
    {
        uint32_t     cur_heap_index     = descriptor.types[type].heap_index;
        VkDeviceSize cur_type_heap_size = descriptor.heaps[cur_heap_index].remaining_size;
        VkDeviceSize cur_type_flags     = descriptor.types[type].flags;
        for (uint32_t other_type = 0; other_type < type_count; ++other_type)
        {
            if (type == other_type)
            {
                continue;
            }
            uint32_t     other_heap_index     = descriptor.types[other_type].heap_index;
            VkDeviceSize other_type_heap_size = descriptor.heaps[other_heap_index].remaining_size;
            VkDeviceSize other_type_flags     = descriptor.types[other_type].flags;
            if (other_type_heap_size > cur_type_heap_size)
            {
                descriptor.types[type].largest_of_remaining_flags &= ~other_type_flags;
            }
        }
    }

    // Generate the comparison heap information
    for (uint32_t heap = 0; heap < heap_count; ++heap)
    {
        VkDeviceSize cur_heap_size  = descriptor.heaps[heap].remaining_size;
        VkDeviceSize cur_heap_flags = descriptor.heaps[heap].flags;
        for (uint32_t other_heap = 0; other_heap < heap_count; ++other_heap)
        {
            if (heap == other_heap)
            {
                continue;
            }
            VkDeviceSize other_heap_size  = descriptor.heaps[other_heap].remaining_size;
            VkDeviceSize other_heap_flags = descriptor.heaps[other_heap].flags;
            if (other_heap_size > cur_heap_size)
            {
                descriptor.heaps[heap].largest_of_remaining_flags &= ~other_heap_flags;
            }
        }
    }
    return true;
}

// We need to record certain information after a successful vkCreateInstance call.
size_t MetadataHandler::RecordingUpdate_CreateInstance(const VkInstanceCreateInfo*  create_info,
                                                       const VkAllocationCallbacks* alloc_callbacks,
                                                       VkInstance*                  instance)
{
    General_CreateInstance(create_info, alloc_callbacks, instance);
    return 0;
}

// We need to record certain information after a successful vkDestroyInstance call.
size_t MetadataHandler::RecordingUpdate_DestroyInstance(VkInstance                   instance,
                                                        const VkAllocationCallbacks* alloc_callbacks)
{
    General_DestroyInstance(instance, alloc_callbacks);
    return 0;
}

// We need to record certain information after a successful vkEnumeratePhysicalDevices call.
size_t MetadataHandler::RecordingUpdate_EnumeratePhysicalDevices(VkInstance        instance,
                                                                 uint32_t*         count,
                                                                 VkPhysicalDevice* phys_devices)
{
    General_EnumeratePhysicalDevices(instance, count, phys_devices);
    return 0;
}

// We need to record certain information after a successful vkEnumeratePhysicalDeviceGroups call.
size_t MetadataHandler::RecordingUpdate_EnumeratePhysicalDeviceGroups(
    VkInstance instance, uint32_t* count, VkPhysicalDeviceGroupProperties* phys_device_groups)
{
    General_EnumeratePhysicalDeviceGroups(instance, count, phys_device_groups);
    return 0;
}

// We need to record certain information after a successful vkCreateDevice call.
bool MetadataHandler::Generate_CreateDeviceMetadata(VkPhysicalDevice             phys_device,
                                                    const VkDeviceCreateInfo*    create_info,
                                                    const VkAllocationCallbacks* alloc_callbacks,
                                                    VkDevice*                    device,
                                                    CreateDeviceMetadata*        create_device_metadata)
{
    try
    {
        if (nullptr == create_device_metadata)
        {
            return false;
        }
        // Setup the metadata
        *create_device_metadata                             = {};
        create_device_metadata->struct_id                   = CREATE_DEVICE_METADATA_STRUCT_ID;
        create_device_metadata->struct_version              = CURRENT_CREATE_DEVICE_METADATA_VERSION;
        create_device_metadata->enabled_instance_extensions = nullptr;
        create_device_metadata->enabled_device_extensions   = nullptr;
        create_device_metadata->memory_types                = nullptr;
        create_device_metadata->memory_heaps                = nullptr;

        VkInstance instance = VK_NULL_HANDLE;
        if (!FindInstanceForPhysicalDevice(phys_device, instance))
        {
            return false;
        }

        auto instance_tracker = instance_tracker_[instance];
        auto phys_dev_info    = instance_tracker.physical_device_info[phys_device];

        // Copy over the physical device properties used by the application
        create_device_metadata->api_version = instance_tracker.desired_api_version;
        create_device_metadata->vendor_id   = phys_dev_info.device_props.vendorID;
        create_device_metadata->hardware_id = phys_dev_info.device_props.deviceID;
        create_device_metadata->type        = phys_dev_info.device_props.deviceType;
        util::platform::MemoryCopy(create_device_metadata->unique_id,
                                   VK_UUID_SIZE * sizeof(uint8_t),
                                   phys_dev_info.device_props.pipelineCacheUUID,
                                   VK_UUID_SIZE * sizeof(uint8_t));

        // Record the enabled instance extensions because that can have an impact
        // on what device is used.
        create_device_metadata->has_instance_extensions = VK_FALSE;
        if (0 < instance_tracker.instance_extensions.size())
        {
            create_device_metadata->has_instance_extensions = VK_TRUE;
            std::string extension_list;
            for (uint32_t ext = 0; ext < instance_tracker.instance_extensions.size(); ++ext)
            {
                if (ext > 0)
                {
                    extension_list += ",";
                }
                extension_list += instance_tracker.instance_extensions[ext];
            }

            size_t ext_string_len                               = extension_list.size() + 1;
            create_device_metadata->enabled_instance_extensions = new char[ext_string_len];
            if (nullptr == create_device_metadata->enabled_instance_extensions)
            {
                return false;
            }
            else
            {
                if (util::platform::StringCopy(create_device_metadata->enabled_instance_extensions,
                                               ext_string_len,
                                               extension_list.c_str(),
                                               extension_list.size()))
                {
                    return false;
                }
                create_device_metadata->enabled_instance_extensions[ext_string_len] = '\0';
            }
        }

        // Record the enabled device extensions
        create_device_metadata->has_device_extensions = VK_FALSE;
        if (nullptr != create_info)
        {
            if (create_info->enabledExtensionCount > 0)
            {
                create_device_metadata->has_device_extensions = VK_TRUE;
                std::string extension_list;
                for (uint32_t ext = 0; ext < create_info->enabledExtensionCount; ++ext)
                {
                    if (ext > 0)
                    {
                        extension_list += ",";
                    }
                    extension_list += create_info->ppEnabledExtensionNames[ext];
                }

                size_t ext_string_len                             = extension_list.size() + 1;
                create_device_metadata->enabled_device_extensions = new char[ext_string_len];
                if (nullptr == create_device_metadata->enabled_device_extensions)
                {
                    if (nullptr != create_device_metadata->enabled_instance_extensions)
                    {
                        delete[] create_device_metadata->enabled_instance_extensions;
                        create_device_metadata->enabled_instance_extensions = nullptr;
                    }
                    return false;
                }
                else
                {
                    if (util::platform::StringCopy(create_device_metadata->enabled_device_extensions,
                                                   ext_string_len,
                                                   extension_list.c_str(),
                                                   extension_list.size()))
                    {
                        return false;
                    }
                    create_device_metadata->enabled_device_extensions[ext_string_len] = '\0';
                }
            }
        }

        if (instance_tracker.physical_device_info.size() == 1)
        {
            // Only one device, so we have nothing to compare it against.  Therefor,
            // when we select a device later, we just select the one we think is best.
            create_device_metadata->only_device_present = VK_TRUE;
        }
        else
        {
            // Determine what queue flags are available for the selected physical device
            create_device_metadata->cummulative_queue_flags = 0;
            for (uint32_t family = 0; family < phys_dev_info.queue_family_props.size(); ++family)
            {
                create_device_metadata->cummulative_queue_flags |= phys_dev_info.queue_family_props[family].queueFlags;
            }
            create_device_metadata->unique_queue_flags = create_device_metadata->cummulative_queue_flags;
            for (auto other_phys_dev_info : instance_tracker.physical_device_info)
            {
                if (other_phys_dev_info.first == phys_device)
                {
                    continue;
                }
                // Determine unique queue family flags for the selected physical device compared to the other
                // physical devices on the system.
                for (uint32_t family = 0; family < other_phys_dev_info.second.queue_family_props.size(); ++family)
                {
                    create_device_metadata->cummulative_queue_flags &=
                        ~other_phys_dev_info.second.queue_family_props[family].queueFlags;
                }
            }

            // Save this physical device's memory layout so we can do comparisons on playback
            create_device_metadata->num_memory_types = phys_dev_info.memory_desc.types.size();
            create_device_metadata->num_memory_heaps = phys_dev_info.memory_desc.heaps.size();
            create_device_metadata->memory_types     = new VkMemoryType[create_device_metadata->num_memory_types];
            create_device_metadata->memory_heaps     = new VkMemoryHeap[create_device_metadata->num_memory_heaps];
            if (nullptr == create_device_metadata->memory_types || nullptr == create_device_metadata->memory_heaps)
            {
                Destroy_CreateDeviceMetadata(create_device_metadata);
                return false;
            }
            for (uint32_t mem_type = 0; mem_type < phys_dev_info.memory_desc.types.size(); ++mem_type)
            {
                create_device_metadata->memory_types[mem_type].propertyFlags =
                    phys_dev_info.memory_desc.types[mem_type].flags;
                create_device_metadata->memory_types[mem_type].heapIndex =
                    phys_dev_info.memory_desc.types[mem_type].heap_index;
            }
            for (uint32_t mem_heap = 0; mem_heap < phys_dev_info.memory_desc.heaps.size(); ++mem_heap)
            {
                create_device_metadata->memory_heaps[mem_heap].flags = phys_dev_info.memory_desc.heaps[mem_heap].flags;
                create_device_metadata->memory_heaps[mem_heap].size  = phys_dev_info.memory_desc.heaps[mem_heap].size;
            }

            // Determine if this device has the most of any particular kind of memory
            create_device_metadata->device_local_mem_size  = phys_dev_info.device_local_mem_size;
            create_device_metadata->host_visible_mem_size  = phys_dev_info.host_visible_mem_size;
            create_device_metadata->host_coherent_mem_size = phys_dev_info.host_coherent_mem_size;
            create_device_metadata->host_cached_mem_size   = phys_dev_info.host_cached_mem_size;
            create_device_metadata->protected_mem_size     = phys_dev_info.protected_mem_size;

            // Setup group info
            create_device_metadata->use_device_group            = phys_dev_info.is_device_group;
            create_device_metadata->device_group_index          = phys_dev_info.index_in_device_group;
            create_device_metadata->devices_in_group            = phys_dev_info.grouped_phys_devices.size() + 1;
            create_device_metadata->group_supports_subset_alloc = phys_dev_info.group_supports_subset_alloc;
        }

        InternalDeviceInfo device_info = {};
        device_info.instance           = instance;
        device_info.physical_device    = phys_device;
        device_info_[*device]          = device_info;
    }
    catch (...)
    {
        Destroy_CreateDeviceMetadata(create_device_metadata);
        return false;
    }

    return true;
}

void MetadataHandler::Destroy_CreateDeviceMetadata(CreateDeviceMetadata* create_device_metadata)
{
    if (nullptr != create_device_metadata)
    {
        if (nullptr != create_device_metadata->enabled_instance_extensions)
        {
            delete[] create_device_metadata->enabled_instance_extensions;
        }
        if (nullptr != create_device_metadata->enabled_device_extensions)
        {
            delete[] create_device_metadata->enabled_device_extensions;
        }
        if (nullptr != create_device_metadata->memory_types)
        {
            delete[] create_device_metadata->memory_types;
        }
        if (nullptr != create_device_metadata->memory_heaps)
        {
            delete[] create_device_metadata->memory_heaps;
        }
    }
}

size_t MetadataHandler::RecordingUpdate_DestroyDevice(VkDevice device, const VkAllocationCallbacks* allocator)
{
    device_info_.erase(device);
    return 0;
}

bool MetadataHandler::Generate_AllocateMemoryMetadata(VkDevice                     device,
                                                      const VkMemoryAllocateInfo*  allocate_info,
                                                      const VkAllocationCallbacks* allocator,
                                                      VkDeviceMemory*              memory,
                                                      AllocateMemoryMetadata*      allocate_memory_metadata)
{
    try
    {
        VkInstance       instance         = device_info_[device].instance;
        VkPhysicalDevice phys_device      = device_info_[device].physical_device;
        auto             physdevice_info_ = instance_tracker_[instance].physical_device_info[phys_device];
        uint32_t         type_index       = allocate_info->memoryTypeIndex;
        uint32_t         heap_index       = physdevice_info_.memory_desc.types[type_index].heap_index;
        VkDeviceSize     alloc_size       = allocate_info->allocationSize;

        InternalAllocationInfo internalalloc_info_ = {};
        internalalloc_info_.device                 = device;
        internalalloc_info_.type_index             = type_index;
        internalalloc_info_.heap_index             = heap_index;

        uint32_t cur_alloc_index;
        alloc_index_mutex_.lock();
        cur_alloc_index = alloc_index_++;
        alloc_index_mutex_.unlock();

        // Get the appropriate metadata.
        auto type_metadata = physdevice_info_.memory_desc.types[type_index];
        auto heap_metadata = physdevice_info_.memory_desc.heaps[heap_index];
        heap_metadata.remaining_size -= alloc_size;

        // Generate the metadata to store
        auto alloc_metadata                                = internalalloc_info_.metadata;
        alloc_metadata.struct_version                      = CURRENT_ALLOCATE_MEMORY_METADATA_VERSION;
        alloc_metadata.struct_id                           = ALLOCATE_MEMORY_METADATA_STRUCT_ID;
        alloc_metadata.alloc_index                         = cur_alloc_index;
        alloc_metadata.requested_size                      = alloc_size;
        alloc_metadata.property_flags                      = type_metadata.flags;
        alloc_metadata.unique_property_flags               = type_metadata.unique_flags;
        alloc_metadata.largest_of_property_flags           = type_metadata.largest_of_flags;
        alloc_metadata.largest_of_remaining_property_flags = type_metadata.largest_of_remaining_flags;
        alloc_metadata.heap_flags                          = heap_metadata.flags;
        alloc_metadata.unique_heap_flags                   = heap_metadata.unique_flags;
        alloc_metadata.largest_of_heap_flags               = heap_metadata.largest_of_flags;
        alloc_metadata.largest_of_remaining_heap_flags     = heap_metadata.largest_of_remaining_flags;
        *allocate_memory_metadata                          = alloc_metadata;

        // Update the information on the memory now that we've removed some from the available
        // space.
        if (!UpdateMemoryDesc(physdevice_info_.memory_desc))
        {
            return false;
        }

        // The memory map really points to a stack because memory allocs/frees come
        // much more frequently and we might see the same memory value get returned
        // multiple times for two different memory blocks.
        alloc_info_[*memory].push_back(internalalloc_info_);
    }
    catch (...)
    {
        Destroy_AllocateMemoryMetadata(allocate_memory_metadata);
        return false;
    }
    return true;
}

void MetadataHandler::Destroy_AllocateMemoryMetadata(AllocateMemoryMetadata* allocate_memory_metadata)
{
    // Nothing to do here
}

size_t MetadataHandler::RecordingUpdate_FreeMemory(VkDevice                     device,
                                                   VkDeviceMemory               memory,
                                                   const VkAllocationCallbacks* allocator)
{
    General_FreeMemory(device, memory, allocator);
    return 0;
}

size_t MetadataHandler::RecordingUpdate_CreateBuffer(VkDevice                     device,
                                                     const VkBufferCreateInfo*    create_info,
                                                     const VkAllocationCallbacks* alloc_callbacks,
                                                     VkBuffer*                    buffer)
{
    InternalBufferInfo buffer_info = {};
    buffer_info.current_memory     = VK_NULL_HANDLE;
    buffer_info.create_flags       = create_info->flags;
    buffer_info.usage_flags        = create_info->usage;
    buffer_info.sharing_mode       = create_info->sharingMode;
    buffer_info.estimated_size     = 0;

    buffer_info_[*buffer] = buffer_info;
    return 0;
}

size_t MetadataHandler::RecordingUpdate_CreateImage(VkDevice                     device,
                                                    const VkImageCreateInfo*     create_info,
                                                    const VkAllocationCallbacks* alloc_callbacks,
                                                    VkImage*                     image)
{
    InternalImageInfo image_info = {};
    image_info.current_memory    = VK_NULL_HANDLE;
    image_info.create_flags      = create_info->flags;
    image_info.usage_flags       = create_info->usage;
    image_info.sharing_mode      = create_info->sharingMode;
    image_info.tiling            = create_info->tiling;
    image_info.estimated_size    = 0;

    image_info_[*image] = image_info;
    return 0;
}

size_t MetadataHandler::RecordingUpdate_BindBufferMemory(VkDevice       device,
                                                         VkBuffer       buffer,
                                                         VkDeviceMemory memory,
                                                         VkDeviceSize   memory_offset)
{
    try
    {
        auto buffer_info = buffer_info_[buffer];

        VkDeviceMemory cur_memory = buffer_info.current_memory;
        if (cur_memory == memory)
        {
            // Already bound to this memory, nothing to do, just return
            return 0;
        }
        else if (cur_memory != VK_NULL_HANDLE)
        {
            // Remove this buffer size from that memory's current size
            auto otheralloc_info__vec = alloc_info_[cur_memory];
            auto otheralloc_info_     = otheralloc_info__vec[otheralloc_info__vec.size() - 1];
            otheralloc_info_.cur_size[ALLOC_USED_FOR_BUFFER] -= buffer_info.estimated_size;
        }

        if (VK_NULL_HANDLE != memory)
        {
            auto alloc_info_vec     = alloc_info_[memory];
            auto alloc_info         = alloc_info_vec[alloc_info_vec.size() - 1];
            auto cur_alloc_size_buf = alloc_info.cur_size.find(ALLOC_USED_FOR_BUFFER);
            if (cur_alloc_size_buf != alloc_info.cur_size.end())
            {
                // This memory already has some buffers bound to part of it.
                cur_alloc_size_buf->second += buffer_info.estimated_size;
                if (alloc_info.high_water_marks[ALLOC_USED_FOR_BUFFER] < cur_alloc_size_buf->second)
                {
                    alloc_info.high_water_marks[ALLOC_USED_FOR_BUFFER] = cur_alloc_size_buf->second;
                }
            }
            else
            {
                // This memory does not already have buffers bound to part of it.
                alloc_info.cur_size[ALLOC_USED_FOR_BUFFER]         = buffer_info.estimated_size;
                alloc_info.high_water_marks[ALLOC_USED_FOR_BUFFER] = buffer_info.estimated_size;
            }
            alloc_info.used_for_flags |= ALLOC_USED_FOR_BUFFER;
            if (0 != (buffer_info.create_flags & VK_BUFFER_CREATE_SPARSE_BINDING_BIT) ||
                0 != (buffer_info.create_flags & VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT) ||
                0 != (buffer_info.create_flags & VK_BUFFER_CREATE_SPARSE_ALIASED_BIT))
            {
                alloc_info.used_for_flags |= ALLOC_USED_FOR_SPARSE;
            }
            if (0 != (buffer_info.create_flags & VK_BUFFER_CREATE_PROTECTED_BIT))
            {
                alloc_info.used_for_flags |= ALLOC_USED_FOR_PROTECTED;
            }
        }
    }
    catch (...)
    {}
    return 0;
}

size_t MetadataHandler::RecordingUpdate_BindImageMemory(VkDevice       device,
                                                        VkImage        image,
                                                        VkDeviceMemory memory,
                                                        VkDeviceSize   memory_offset)
{
    try
    {
        auto image_info = image_info_[image];

        // If image was already bound somewhere, make sure it wasn't to a different
        // memory location, because, if it was, we need to delete it there and add it here.
        VkDeviceMemory cur_memory = image_info.current_memory;
        if (cur_memory == memory)
        {
            // Already bound to this memory, nothing to do, just return
            return 0;
        }
        else if (cur_memory != VK_NULL_HANDLE)
        {
            // Remove this image size from that memory's current size
            auto otheralloc_info__vec = alloc_info_[cur_memory];
            auto otheralloc_info_     = otheralloc_info__vec[otheralloc_info__vec.size() - 1];
            otheralloc_info_.cur_size[ALLOC_USED_FOR_IMAGE] -= image_info.estimated_size;
        }
        if (VK_NULL_HANDLE != memory)
        {
            auto alloc_info_vec     = alloc_info_[memory];
            auto alloc_info         = alloc_info_vec[alloc_info_vec.size() - 1];
            auto cur_alloc_size_buf = alloc_info.cur_size.find(ALLOC_USED_FOR_IMAGE);
            if (cur_alloc_size_buf != alloc_info.cur_size.end())
            {
                // This memory already has some images bound to part of it.
                cur_alloc_size_buf->second += image_info.estimated_size;
                if (alloc_info.high_water_marks[ALLOC_USED_FOR_IMAGE] < cur_alloc_size_buf->second)
                {
                    alloc_info.high_water_marks[ALLOC_USED_FOR_IMAGE] = cur_alloc_size_buf->second;
                }
            }
            else
            {
                // This memory does not already have images bound to part of it.
                alloc_info.cur_size[ALLOC_USED_FOR_IMAGE]         = image_info.estimated_size;
                alloc_info.high_water_marks[ALLOC_USED_FOR_IMAGE] = image_info.estimated_size;
            }
            alloc_info.used_for_flags |= ALLOC_USED_FOR_IMAGE;
            if (0 != (image_info.create_flags & VK_IMAGE_CREATE_SPARSE_BINDING_BIT) ||
                0 != (image_info.create_flags & VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT) ||
                0 != (image_info.create_flags & VK_IMAGE_CREATE_SPARSE_ALIASED_BIT))
            {
                alloc_info.used_for_flags |= ALLOC_USED_FOR_SPARSE;
            }
            if (0 != (image_info.create_flags & VK_IMAGE_CREATE_PROTECTED_BIT))
            {
                alloc_info.used_for_flags |= ALLOC_USED_FOR_PROTECTED;
            }
        }
    }
    catch (...)
    {}
    return 0;
}

static uint32_t EstimateNormalMemoryRequired(VkMemoryRequirements* memory_requirements)
{
    return ((memory_requirements->alignment / 4) - 1) + memory_requirements->size;
}

static uint32_t EstimateSparseImageMemoryRequired(uint32_t count, VkSparseImageMemoryRequirements* memory_requirements)
{
    uint32_t size = 0;
    for (uint32_t mip_layer = 0; mip_layer < count; ++mip_layer)
    {
        uint32_t cur_size =
            memory_requirements[mip_layer].imageMipTailSize + memory_requirements[mip_layer].imageMipTailOffset;
        uint32_t max_strides = cur_size / memory_requirements[mip_layer].imageMipTailStride;
        if (max_strides > 0)
        {
            cur_size = (max_strides + 1) * memory_requirements[mip_layer].imageMipTailStride;
        }
        size += cur_size;
    }
    return size;
}

size_t MetadataHandler::RecordingUpdate_GetBufferMemoryRequirements(VkDevice              device,
                                                                    VkBuffer              buffer,
                                                                    VkMemoryRequirements* memory_requirements)
{
    buffer_info_[buffer].estimated_size = EstimateNormalMemoryRequired(memory_requirements);
    return 0;
}

size_t MetadataHandler::RecordingUpdate_GetImageMemoryRequirements(VkDevice              device,
                                                                   VkImage               image,
                                                                   VkMemoryRequirements* memory_requirements)
{
    image_info_[image].estimated_size = EstimateNormalMemoryRequired(memory_requirements);

    return 0;
}

size_t
MetadataHandler::RecordingUpdate_GetImageSparseMemoryRequirements(VkDevice  device,
                                                                  VkImage   image,
                                                                  uint32_t* memory_requirement_count,
                                                                  VkSparseImageMemoryRequirements* memory_requirements)
{
    image_info_[image].estimated_size =
        EstimateSparseImageMemoryRequired(*memory_requirement_count, memory_requirements);

    return 0;
}

size_t
MetadataHandler::RecordingUpdate_DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* allocator)
{
    try
    {
        auto buffer_info = buffer_info_[buffer];

        // If buffer was already bound somewhere, make sure it wasn't to a different
        // memory location, because, if it was, we need to delete it there and add it here.
        if (buffer_info.current_memory != VK_NULL_HANDLE)
        {
            // Remove this buffer size from that memory's current size
            auto otheralloc_info__vec = alloc_info_[buffer_info.current_memory];
            auto otheralloc_info_     = otheralloc_info__vec[otheralloc_info__vec.size() - 1];
            otheralloc_info_.cur_size[ALLOC_USED_FOR_BUFFER] -= buffer_info.estimated_size;
        }
    }
    catch (...)
    {}
    return 0;
}

size_t
MetadataHandler::RecordingUpdate_DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* allocator)
{
    try
    {
        auto image_info = image_info_[image];

        // If image was already bound somewhere, make sure it wasn't to a different
        // memory location, because, if it was, we need to delete it there and add it here.
        if (image_info.current_memory != VK_NULL_HANDLE)
        {
            // Remove this image size from that memory's current size
            auto otheralloc_info__vec = alloc_info_[image_info.current_memory];
            auto otheralloc_info_     = otheralloc_info__vec[otheralloc_info__vec.size() - 1];
            otheralloc_info_.cur_size[ALLOC_USED_FOR_IMAGE] -= image_info.estimated_size;
        }
    }
    catch (...)
    {}
    return 0;
}

size_t MetadataHandler::PlaybackUpdate_CreateInstance(const VkInstanceCreateInfo*  create_info,
                                                      const VkAllocationCallbacks* alloc_callbacks,
                                                      VkInstance*                  instance)
{
    General_CreateInstance(create_info, alloc_callbacks, instance);
    return 0;
}

size_t MetadataHandler::PlaybackUpdate_DestroyInstance(VkInstance                   instance,
                                                       const VkAllocationCallbacks* alloc_callbacks)
{
    General_DestroyInstance(instance, alloc_callbacks);
    return 0;
}

size_t MetadataHandler::PlaybackUpdate_EnumeratePhysicalDevices(VkInstance        instance,
                                                                uint32_t*         count,
                                                                VkPhysicalDevice* phys_devices)
{
    General_EnumeratePhysicalDevices(instance, count, phys_devices);
    return 0;
}

size_t MetadataHandler::PlaybackUpdate_EnumeratePhysicalDeviceGroups(
    VkInstance instance, uint32_t* count, VkPhysicalDeviceGroupProperties* phys_device_groups)
{
    General_EnumeratePhysicalDeviceGroups(instance, count, phys_device_groups);
    return 0;
}

size_t MetadataHandler::PlaybackDecode_CreateDevice(const uint8_t*               buffer,
                                                    size_t                       buffer_size,
                                                    VkPhysicalDevice             phys_device,
                                                    const VkDeviceCreateInfo*    create_info,
                                                    const VkAllocationCallbacks* alloc_callbacks,
                                                    VkDevice*                    device,
                                                    CreateDeviceMetadata*        create_device_metadata)
{
    // Unused variables - left in call to simplify generation
    (void)phys_device;
    (void)create_info;
    (void)alloc_callbacks;
    (void)device;
#if 0
    VkInstance                   instance        = VK_NULL_HANDLE;
    Decoded_CreateDeviceMetadata decoded_wrapper = {};
    size_t                       cur_size        = DecodeCreateDeviceMetadata(buffer, buffer_size, &decoded_wrapper);
    create_device_metadata                       = decoded_wrapper.value;
    if (FindInstanceForPhysicalDevice(phys_device, instance))
    {
        InternalDeviceInfo device_info = {};
        device_info.instance           = instance;
        device_info.physical_device    = phys_device;
        device_info_[*device]          = device_info;
    }
    return cur_size;
#else
    return 0;
#endif
}

size_t MetadataHandler::PlaybackUpdate_DestroyDevice(VkDevice device, const VkAllocationCallbacks* allocator)
{
    device_info_.erase(device);
    return 0;
}

size_t MetadataHandler::PlaybackDecode_AllocateMemory(const uint8_t*               buffer,
                                                      size_t                       buffer_size,
                                                      VkDevice                     device,
                                                      const VkMemoryAllocateInfo*  allocate_info,
                                                      const VkAllocationCallbacks* allocator,
                                                      VkDeviceMemory*              memory,
                                                      AllocateMemoryMetadata*      allocate_memory_metadata)
{
    // Unused variables left to make it easier on codegen
    (void)allocate_info;
    (void)allocator;
    (void)memory;
#if 0
    VkInstance                     instance         = device_info_[device].instance;
    VkPhysicalDevice               phys_device      = device_info_[device].physical_device;
    auto                           physdevice_info_ = instance_tracker_[instance].physical_device_info[phys_device];
    Decoded_AllocateMemoryMetadata decoded_wrapper  = {};
    size_t                         cur_size = DecodeAllocateMemoryMetadata(buffer, buffer_size, &decoded_wrapper);
    allocate_memory_metadata                = decoded_wrapper.value;
    return cur_size;
#else
    return 0;
#endif
}

// Find out if the selected physical device has the most of a given type of memory when
// compared to all the other available physical devices on the system.
bool MetadataHandler::DetermineMemoryTypeSize(VkInstance               instance,
                                              VkPhysicalDevice         phys_device,
                                              VkMemoryPropertyFlagBits memory_flag,
                                              VkDeviceSize&            size)
{
    auto phys_dev_info = instance_tracker_[instance].physical_device_info[phys_device];

    size = 0;

    // Add up all memory heaps on our selected device to see how much memory that
    // uses.
    for (uint32_t mem_type = 0; mem_type < phys_dev_info.memory_desc.types.size(); ++mem_type)
    {
        uint32_t heap_index = phys_dev_info.memory_desc.types[mem_type].heap_index;
        size_t   heap_size  = phys_dev_info.memory_desc.heaps[heap_index].size;
        if (0 != (memory_flag & phys_dev_info.memory_desc.types[mem_type].flags))
        {
            size += heap_size;
        }
    }

    return true;
}

bool MetadataHandler::FindInstanceForPhysicalDevice(VkPhysicalDevice phys_device, VkInstance& instance)
{
    instance = VK_NULL_HANDLE;
    if (last_enum_instance_ != VK_NULL_HANDLE)
    {
        auto phys_dev_found_iter = instance_tracker_[last_enum_instance_].physical_device_info.find(phys_device);
        if (phys_dev_found_iter != instance_tracker_[last_enum_instance_].physical_device_info.end())
        {
            instance = last_enum_instance_;
        }
    }

    if (instance == VK_NULL_HANDLE)
    {
        for (auto temp_instance_iter : instance_tracker_)
        {
            auto phys_dev_found_iter = temp_instance_iter.second.physical_device_info.find(phys_device);
            if (phys_dev_found_iter == temp_instance_iter.second.physical_device_info.end())
            {
                instance = temp_instance_iter.first;
                break;
            }
        }
    }

    if (instance == VK_NULL_HANDLE)
    {
        return false;
    }
    return true;
}

// We need to record certain information after a successful vkCreateInstance call.
bool MetadataHandler::General_CreateInstance(const VkInstanceCreateInfo*  create_info,
                                             const VkAllocationCallbacks* alloc_callbacks,
                                             VkInstance*                  instance)
{
    try
    {
        uint16_t                 major_version     = 1;
        uint16_t                 minor_version     = 0;
        InternalInstanceMetadata instance_metadata = {};

        if (nullptr != create_info)
        {
            if (nullptr != create_info->pApplicationInfo)
            {
                uint16_t api_major                    = VK_VERSION_MAJOR(create_info->pApplicationInfo->apiVersion);
                uint16_t api_minor                    = VK_VERSION_MINOR(create_info->pApplicationInfo->apiVersion);
                instance_metadata.desired_api_version = VK_MAKE_VERSION(api_major, api_minor, 0);
            }
            if (0 < create_info->enabledExtensionCount)
            {
                instance_metadata.instance_extensions.resize(create_info->enabledExtensionCount);
                for (uint32_t inst_ext = 0; inst_ext < create_info->enabledExtensionCount; ++inst_ext)
                {
                    instance_metadata.instance_extensions[inst_ext] = create_info->ppEnabledExtensionNames[inst_ext];
                }
            }
        }

        instance_tracker_[*instance] = instance_metadata;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

// We need to record certain information after a successful vkDestroyInstance call.
bool MetadataHandler::General_DestroyInstance(VkInstance instance, const VkAllocationCallbacks* allocator)
{
    instance_tracker_.erase(instance);
    if (last_enum_instance_ == instance)
    {
        last_enum_instance_ = VK_NULL_HANDLE;
    }
    return true;
}

// We need to record certain information after a successful vkEnumeratePhysicalDevices call.
bool MetadataHandler::General_EnumeratePhysicalDevices(VkInstance        instance,
                                                       uint32_t*         count,
                                                       VkPhysicalDevice* phys_devices)
{
    try
    {
        for (uint32_t pd = 0; pd < *count; ++pd)
        {
            InternalPhysicalDeviceMetadata phys_dev_metadata = {};
            vkGetPhysicalDeviceProperties(phys_devices[pd], &phys_dev_metadata.device_props);

            if (!GenerateMemoryDesc(phys_devices[pd], phys_dev_metadata.memory_desc))
            {
                return false;
            }

            uint32_t num_queue_families = 0;
            vkGetPhysicalDeviceQueueFamilyProperties(phys_devices[pd], &num_queue_families, nullptr);
            phys_dev_metadata.queue_family_props.resize(num_queue_families);
            vkGetPhysicalDeviceQueueFamilyProperties(
                phys_devices[pd], &num_queue_families, phys_dev_metadata.queue_family_props.data());

            instance_tracker_[instance].physical_device_info[phys_devices[pd]] = phys_dev_metadata;
        }

        // Now, loop through again and determine who has the most of anything
        for (uint32_t pd = 0; pd < *count; ++pd)
        {
            auto physdevice_info_ = instance_tracker_[instance].physical_device_info[phys_devices[pd]];
            // Determine if this device has the most of any particular kind of memory
            DetermineMemoryTypeSize(instance,
                                    phys_devices[pd],
                                    VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                    physdevice_info_.device_local_mem_size);
            DetermineMemoryTypeSize(instance,
                                    phys_devices[pd],
                                    VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
                                    physdevice_info_.host_visible_mem_size);
            DetermineMemoryTypeSize(instance,
                                    phys_devices[pd],
                                    VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                                    physdevice_info_.host_coherent_mem_size);
            DetermineMemoryTypeSize(
                instance, phys_devices[pd], VK_MEMORY_PROPERTY_HOST_CACHED_BIT, physdevice_info_.host_cached_mem_size);
            DetermineMemoryTypeSize(
                instance, phys_devices[pd], VK_MEMORY_PROPERTY_PROTECTED_BIT, physdevice_info_.protected_mem_size);
        }
        last_enum_instance_ = instance;
        return true;
    }
    catch (...)
    {
        return false;
    }
}
bool MetadataHandler::General_EnumeratePhysicalDeviceGroups(VkInstance                       instance,
                                                            uint32_t*                        count,
                                                            VkPhysicalDeviceGroupProperties* phys_device_groups)
{
    try
    {
        for (uint32_t group = 0; group < *count; ++group)
        {
            for (uint32_t pd = 0; pd < phys_device_groups[group].physicalDeviceCount; ++pd)
            {
                VkPhysicalDevice cur_phys_device = phys_device_groups[group].physicalDevices[pd];

                // Only create it if the physical device information isn't already found.
                auto phys_dev_found_iter = instance_tracker_[instance].physical_device_info.find(cur_phys_device);
                if (phys_dev_found_iter == instance_tracker_[instance].physical_device_info.end())
                {
                    InternalPhysicalDeviceMetadata phys_dev_metadata = {};
                    vkGetPhysicalDeviceProperties(cur_phys_device, &phys_dev_metadata.device_props);

                    if (!GenerateMemoryDesc(cur_phys_device, phys_dev_metadata.memory_desc))
                    {
                        return false;
                    }

                    uint32_t num_queue_families = 0;
                    vkGetPhysicalDeviceQueueFamilyProperties(cur_phys_device, &num_queue_families, nullptr);
                    phys_dev_metadata.queue_family_props.resize(num_queue_families);
                    vkGetPhysicalDeviceQueueFamilyProperties(
                        cur_phys_device, &num_queue_families, phys_dev_metadata.queue_family_props.data());

                    instance_tracker_[instance].physical_device_info[cur_phys_device] = phys_dev_metadata;
                }
            }

            // Now, loop through again and determine who has the most of anything
            for (uint32_t pd = 0; pd < phys_device_groups[group].physicalDeviceCount; ++pd)
            {
                VkPhysicalDevice cur_phys_device  = phys_device_groups[group].physicalDevices[pd];
                auto             physdevice_info_ = instance_tracker_[instance].physical_device_info[cur_phys_device];

                physdevice_info_.is_device_group             = true;
                physdevice_info_.index_in_device_group       = pd;
                physdevice_info_.group_supports_subset_alloc = (phys_device_groups[group].subsetAllocation == VK_TRUE);
                for (uint32_t other_pd = 0; other_pd < phys_device_groups[group].physicalDeviceCount - 1; ++other_pd)
                {
                    if (other_pd == pd)
                    {
                        continue;
                    }
                    physdevice_info_.grouped_phys_devices.push_back(
                        phys_device_groups[group].physicalDevices[other_pd]);
                }

                // Determine if this device has the most of any particular kind of memory
                DetermineMemoryTypeSize(instance,
                                        cur_phys_device,
                                        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                        physdevice_info_.device_local_mem_size);
                DetermineMemoryTypeSize(instance,
                                        cur_phys_device,
                                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
                                        physdevice_info_.host_visible_mem_size);
                DetermineMemoryTypeSize(instance,
                                        cur_phys_device,
                                        VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                                        physdevice_info_.host_coherent_mem_size);
                DetermineMemoryTypeSize(instance,
                                        cur_phys_device,
                                        VK_MEMORY_PROPERTY_HOST_CACHED_BIT,
                                        physdevice_info_.host_cached_mem_size);
                DetermineMemoryTypeSize(
                    instance, cur_phys_device, VK_MEMORY_PROPERTY_PROTECTED_BIT, physdevice_info_.protected_mem_size);
            }
        }

        last_enum_instance_ = instance;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool MetadataHandler::General_FreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* allocator)
{
    if (VK_NULL_HANDLE != memory)
    {
        VkInstance       instance         = device_info_[device].instance;
        VkPhysicalDevice phys_device      = device_info_[device].physical_device;
        auto             physdevice_info_ = instance_tracker_[instance].physical_device_info[phys_device];

        // Grab the most recent one and re-add the size back to the appropriate
        // location.
        auto alloc_info_vec = alloc_info_[memory];
        auto alloc_info     = alloc_info_vec[alloc_info_vec.size() - 1];
        auto heap_metadata  = physdevice_info_.memory_desc.heaps[alloc_info.heap_index];
        heap_metadata.remaining_size += alloc_info.metadata.requested_size;

        // Update the information on the memory now that we've freed some from the available
        // space.
        if (!UpdateMemoryDesc(physdevice_info_.memory_desc))
        {
            return false;
        }
    }
    return true;
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
