/*
** Copyright (c) 2026 Arm Limited <open-source-office@arm.com>
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

#ifndef GFXRECON_DECODE_VULKAN_NATIVE_CALL_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_NATIVE_CALL_CONSUMER_BASE_H

#include "decode/common_object_info_table.h"
#include "decode/vulkan_native_call_callbacks.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_consumer.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "util/defines.h"

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <limits>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanNativeCallConsumerBase : public VulkanConsumer
{
  public:
    explicit VulkanNativeCallConsumerBase(VulkanNativeCallCallbacks& callbacks) : callbacks_(callbacks) {}

    bool IsComplete(uint64_t) override { return callbacks_.HasFatalError(); }

    void SetCurrentBlockIndex(uint64_t block_index) override { current_block_index_ = block_index; }

    void ProcessMemoryUpdate(uint64_t         block_index,
                             format::ThreadId thread_id,
                             format::HandleId memory_id,
                             uint64_t         mapped_offset,
                             uint64_t         size,
                             const uint8_t*   data)
    {
        const VkDeviceMemory memory  = MaterializeMetadataDeviceMemory(memory_id);
        const auto           mapping = mapped_memory_offsets_.find(memory);
        if ((mapping == mapped_memory_offsets_.end()) ||
            (mapped_offset > (std::numeric_limits<VkDeviceSize>::max() - mapping->second)) ||
            (size > std::numeric_limits<size_t>::max()))
        {
            callbacks_.InvalidMemoryUpdate(block_index, thread_id);
            return;
        }

        callbacks_.MemoryUpdate(
            { block_index, thread_id, memory, mapping->second + mapped_offset, static_cast<size_t>(size), data });
    }

    void ProcessDeviceMemoryProperties(uint64_t                                     block_index,
                                       format::ThreadId                             thread_id,
                                       format::HandleId                             physical_device_id,
                                       const std::vector<format::DeviceMemoryType>& memory_types,
                                       const std::vector<format::DeviceMemoryHeap>& memory_heaps)
    {
        if ((memory_types.size() > VK_MAX_MEMORY_TYPES) || (memory_heaps.size() > VK_MAX_MEMORY_HEAPS))
        {
            return;
        }

        VulkanDeviceMemoryProperties properties;
        properties.block_index                       = block_index;
        properties.thread_id                         = thread_id;
        properties.physical_device                   = MaterializeMetadataPhysicalDevice(physical_device_id);
        properties.memory_properties.memoryTypeCount = static_cast<uint32_t>(memory_types.size());
        properties.memory_properties.memoryHeapCount = static_cast<uint32_t>(memory_heaps.size());

        for (size_t i = 0; i < memory_types.size(); ++i)
        {
            properties.memory_properties.memoryTypes[i].propertyFlags = memory_types[i].property_flags;
            properties.memory_properties.memoryTypes[i].heapIndex     = memory_types[i].heap_index;
        }
        for (size_t i = 0; i < memory_heaps.size(); ++i)
        {
            properties.memory_properties.memoryHeaps[i].size  = memory_heaps[i].size;
            properties.memory_properties.memoryHeaps[i].flags = memory_heaps[i].flags;
        }

        callbacks_.DeviceMemoryProperties(properties);
    }

    void ProcessResourceInitializationBegin(uint64_t         block_index,
                                            format::ThreadId thread_id,
                                            format::HandleId device_id,
                                            uint64_t         total_copy_size,
                                            uint64_t         max_copy_size)
    {
        callbacks_.ResourceInitializationBegin(
            { block_index, thread_id, MaterializeMetadataDevice(device_id), total_copy_size, max_copy_size });
    }

    void ProcessBufferInitialization(uint64_t         block_index,
                                     format::ThreadId thread_id,
                                     format::HandleId device_id,
                                     format::HandleId buffer_id,
                                     uint64_t         data_size,
                                     const uint8_t*   data)
    {
        if (data_size > (std::numeric_limits<size_t>::max)())
        {
            return;
        }
        callbacks_.BufferInitialization({ block_index,
                                          thread_id,
                                          MaterializeMetadataDevice(device_id),
                                          MaterializeMetadataBuffer(buffer_id),
                                          static_cast<size_t>(data_size),
                                          data });
    }

    void ProcessImageInitialization(uint64_t                     block_index,
                                    format::ThreadId             thread_id,
                                    format::HandleId             device_id,
                                    format::HandleId             image_id,
                                    uint64_t                     data_size,
                                    uint32_t                     aspect,
                                    uint32_t                     layout,
                                    const std::vector<uint64_t>& level_sizes,
                                    const uint8_t*               data)
    {
        if (data_size > (std::numeric_limits<size_t>::max)())
        {
            return;
        }
        callbacks_.ImageInitialization({ block_index,
                                         thread_id,
                                         MaterializeMetadataDevice(device_id),
                                         MaterializeMetadataImage(image_id),
                                         static_cast<VkImageAspectFlags>(aspect),
                                         static_cast<VkImageLayout>(layout),
                                         level_sizes.size(),
                                         level_sizes.data(),
                                         static_cast<size_t>(data_size),
                                         data });
    }

    void ProcessResourceInitializationEnd(uint64_t block_index, format::ThreadId thread_id, format::HandleId device_id)
    {
        callbacks_.ResourceInitializationEnd({ block_index, thread_id, MaterializeMetadataDevice(device_id) });
    }

    void ProcessOpaqueAddress(uint64_t         block_index,
                              format::ThreadId thread_id,
                              format::HandleId device_id,
                              format::HandleId object_id,
                              uint64_t         address)
    {
        VulkanOpaqueAddress opaque_address{
            block_index, thread_id, MaterializeMetadataDevice(device_id), object_id, address
        };
        if (!ResolveOpaqueAddressFromObjectTable(&opaque_address))
        {
            pending_opaque_addresses_[object_id].push_back(opaque_address);
        }
    }

    void FlushPendingOpaqueAddresses()
    {
        for (const auto& [object_id, opaque_addresses] : pending_opaque_addresses_)
        {
            GFXRECON_UNREFERENCED_PARAMETER(object_id);
            for (const auto& opaque_address : opaque_addresses)
            {
                callbacks_.OpaqueAddress(opaque_address);
            }
        }
        pending_opaque_addresses_.clear();
    }

    void ProcessVulkanBuildAccelerationStructuresCommand(
        format::HandleId                                                           device_id,
        uint32_t                                                                   info_count,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* geometry_infos,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   range_infos,
        std::vector<std::vector<VkAccelerationStructureInstanceKHR>>&              instance_buffers_data) override
    {
        VkAccelerationStructureBuildGeometryInfoKHR* build_infos  = MaterializeStructPointer(geometry_infos);
        VkAccelerationStructureBuildRangeInfoKHR**   build_ranges = GetStructPointer(range_infos);
        auto                                         instance_buffers =
            DescribeAccelerationStructureInstanceBuffers(build_infos, info_count, instance_buffers_data);

        callbacks_.AccelerationStructuresBuild({ current_block_index_,
                                                 MaterializeMetadataDevice(device_id),
                                                 info_count,
                                                 build_infos,
                                                 build_ranges,
                                                 instance_buffers.size(),
                                                 instance_buffers.data() });
    }

    void ProcessVulkanCopyAccelerationStructuresCommand(
        format::HandleId                                                  device_id,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* copy_infos) override
    {
        callbacks_.AccelerationStructuresCopy({ current_block_index_,
                                                MaterializeMetadataDevice(device_id),
                                                copy_infos != nullptr ? copy_infos->GetLength() : 0,
                                                MaterializeStructPointer(copy_infos) });
    }

    void ProcessVulkanWriteAccelerationStructuresPropertiesCommand(format::HandleId device_id,
                                                                   VkQueryType      query_type,
                                                                   format::HandleId acceleration_structure_id) override
    {
        callbacks_.AccelerationStructureWriteProperties(
            { current_block_index_,
              MaterializeMetadataDevice(device_id),
              query_type,
              MaterializeMetadataAccelerationStructure(acceleration_structure_id) });
    }

  protected:
    template <typename Handle>
    void ResolvePendingOpaqueAddresses(format::HandleId object_id, VkObjectType object_type, Handle object_handle)
    {
        auto entry = pending_opaque_addresses_.find(object_id);
        if (entry == pending_opaque_addresses_.end())
        {
            return;
        }
        for (auto& opaque_address : entry->second)
        {
            opaque_address.object_type   = object_type;
            opaque_address.object_handle = format::ToHandleId(object_handle);
            callbacks_.OpaqueAddress(opaque_address);
        }
        pending_opaque_addresses_.erase(entry);
    }

    bool ResolveOpaqueAddressFromObjectTable(VulkanOpaqueAddress* opaque_address)
    {
        GFXRECON_ASSERT(opaque_address != nullptr);

        // Vulkan capture handle IDs are globally unique, so at most one of
        // these type-specific tables can contain object_id.
        if (const auto* info = object_info_table_.GetVkBufferInfo(opaque_address->object_id))
        {
            opaque_address->object_type   = VK_OBJECT_TYPE_BUFFER;
            opaque_address->object_handle = format::ToHandleId(info->handle);
        }
        else if (const auto* info = object_info_table_.GetVkDeviceMemoryInfo(opaque_address->object_id))
        {
            opaque_address->object_type   = VK_OBJECT_TYPE_DEVICE_MEMORY;
            opaque_address->object_handle = format::ToHandleId(info->handle);
        }
        else if (const auto* info = object_info_table_.GetVkAccelerationStructureKHRInfo(opaque_address->object_id))
        {
            opaque_address->object_type   = VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR;
            opaque_address->object_handle = format::ToHandleId(info->handle);
        }
        else if (const auto* info = object_info_table_.GetVkMicromapEXTInfo(opaque_address->object_id))
        {
            opaque_address->object_type   = VK_OBJECT_TYPE_MICROMAP_EXT;
            opaque_address->object_handle = format::ToHandleId(info->handle);
        }
        else
        {
            return false;
        }

        callbacks_.OpaqueAddress(*opaque_address);
        return true;
    }

    static std::vector<VulkanAccelerationStructureInstanceBuffer> DescribeAccelerationStructureInstanceBuffers(
        const VkAccelerationStructureBuildGeometryInfoKHR*                  build_infos,
        uint32_t                                                            info_count,
        const std::vector<std::vector<VkAccelerationStructureInstanceKHR>>& instance_buffers_data)
    {
        std::vector<VulkanAccelerationStructureInstanceBuffer> instance_buffers;
        instance_buffers.reserve(instance_buffers_data.size());
        size_t instance_buffer_index = 0;
        for (uint32_t i = 0;
             (build_infos != nullptr) && (i < info_count) && (instance_buffer_index < instance_buffers_data.size());
             ++i)
        {
            if (build_infos[i].type != VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR)
            {
                continue;
            }
            for (uint32_t g = 0;
                 (g < build_infos[i].geometryCount) && (instance_buffer_index < instance_buffers_data.size());
                 ++g)
            {
                const VkAccelerationStructureGeometryKHR* geometry =
                    (build_infos[i].pGeometries != nullptr)
                        ? &build_infos[i].pGeometries[g]
                        : ((build_infos[i].ppGeometries != nullptr) ? build_infos[i].ppGeometries[g] : nullptr);
                const VkDeviceAddress source_address =
                    (geometry != nullptr && geometry->geometryType == VK_GEOMETRY_TYPE_INSTANCES_KHR)
                        ? geometry->geometry.instances.data.deviceAddress
                        : 0;
                const auto& instances = instance_buffers_data[instance_buffer_index++];
                instance_buffers.push_back({ i, g, source_address, instances.size(), instances.data() });
            }
        }
        return instance_buffers;
    }

    void TrackDescriptorUpdateTemplate(VkResult                                                            result,
                                       StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* create_info,
                                       HandlePointerDecoder<VkDescriptorUpdateTemplate>* update_template)
    {
        if ((result != VK_SUCCESS) || (create_info == nullptr) || create_info->IsNull() ||
            (update_template == nullptr) || update_template->IsNull() || (update_template->GetLength() == 0))
        {
            return;
        }

        const format::HandleId*                     ids  = update_template->GetPointer();
        auto*                                       info = object_info_table_.GetVkDescriptorUpdateTemplateInfo(ids[0]);
        const VkDescriptorUpdateTemplateCreateInfo* value = create_info->GetPointer();
        if ((info == nullptr) || (value == nullptr))
        {
            return;
        }

        if ((value->descriptorUpdateEntryCount == 0) || (value->pDescriptorUpdateEntries == nullptr))
        {
            info->entries.clear();
            return;
        }

        info->entries.assign(value->pDescriptorUpdateEntries,
                             value->pDescriptorUpdateEntries + value->descriptorUpdateEntryCount);
    }

    bool MaterializeDescriptorUpdateTemplateData(format::HandleId                 update_template,
                                                 DescriptorUpdateTemplateDecoder* decoder,
                                                 std::vector<uint8_t>*            data)
    {
        GFXRECON_ASSERT(decoder != nullptr);
        GFXRECON_ASSERT(data != nullptr);

        if (decoder->IsNull())
        {
            data->clear();
            return true;
        }

        const auto* info = object_info_table_.GetVkDescriptorUpdateTemplateInfo(update_template);
        if (info == nullptr)
        {
            return false;
        }
        if (info->entries.empty())
        {
            data->clear();
            return true;
        }

        size_t data_size = 0;
        for (const auto& entry : info->entries)
        {
            const size_t element_size = DescriptorUpdateTemplateElementSize(entry.descriptorType);
            if ((entry.descriptorCount == 0) || (element_size == 0))
            {
                continue;
            }
            const size_t     stride   = entry.stride != 0 ? entry.stride : element_size;
            constexpr size_t max_size = (std::numeric_limits<size_t>::max)();
            if ((entry.offset > (max_size - element_size)) ||
                ((entry.descriptorCount - 1) > ((max_size - entry.offset - element_size) / stride)))
            {
                return false;
            }
            data_size = (std::max)(data_size, entry.offset + (stride * (entry.descriptorCount - 1)) + element_size);
        }
        data->assign(data_size, 0);

        MapDescriptorUpdateTemplateHandles(decoder);

        size_t image_index                  = 0;
        size_t buffer_index                 = 0;
        size_t texel_index                  = 0;
        size_t acceleration_structure_index = 0;
        size_t inline_uniform_index         = 0;
        for (const auto& entry : info->entries)
        {
            const size_t element_size = DescriptorUpdateTemplateElementSize(entry.descriptorType);
            const size_t stride       = entry.stride != 0 ? entry.stride : element_size;
            for (uint32_t i = 0; i < entry.descriptorCount; ++i)
            {
                uint8_t* destination = data->data() + entry.offset + (stride * i);
                switch (entry.descriptorType)
                {
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                        if (image_index >= decoder->GetImageInfoCount())
                        {
                            return false;
                        }
                        {
                            auto        image      = decoder->GetImageInfoPointer()[image_index];
                            const auto& image_meta = decoder->GetImageInfoMetaStructPointer()[image_index++];
                            if ((entry.descriptorType == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                                (entry.descriptorType == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
                            {
                                image.sampler = MaterializeDescriptorHandle<VkSampler, VulkanSamplerInfo>(
                                    image_meta.sampler,
                                    static_cast<const CommonObjectInfoTable&>(object_info_table_)
                                        .GetVkSamplerInfo(image_meta.sampler));
                            }
                            if (entry.descriptorType != VK_DESCRIPTOR_TYPE_SAMPLER)
                            {
                                image.imageView = MaterializeDescriptorHandle<VkImageView, VulkanImageViewInfo>(
                                    image_meta.imageView,
                                    static_cast<const CommonObjectInfoTable&>(object_info_table_)
                                        .GetVkImageViewInfo(image_meta.imageView));
                            }
                            std::memcpy(destination, &image, element_size);
                        }
                        break;
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        if (buffer_index >= decoder->GetBufferInfoCount())
                        {
                            return false;
                        }
                        std::memcpy(destination, &decoder->GetBufferInfoPointer()[buffer_index++], element_size);
                        break;
                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                        if (texel_index >= decoder->GetTexelBufferViewCount())
                        {
                            return false;
                        }
                        std::memcpy(destination, &decoder->GetTexelBufferViewPointer()[texel_index++], element_size);
                        break;
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                        if (acceleration_structure_index >= decoder->GetAccelerationStructureKHRCount())
                        {
                            return false;
                        }
                        std::memcpy(destination,
                                    &decoder->GetAccelerationStructureKHRPointer()[acceleration_structure_index++],
                                    element_size);
                        break;
                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                        if (inline_uniform_index >= decoder->GetInlineUniformBlockCount())
                        {
                            return false;
                        }
                        *destination = decoder->GetInlineUniformBlockPointer()[inline_uniform_index++];
                        break;
                    default:
                        return false;
                }
            }
        }

        return (image_index == decoder->GetImageInfoCount()) && (buffer_index == decoder->GetBufferInfoCount()) &&
               (texel_index == decoder->GetTexelBufferViewCount()) &&
               (acceleration_structure_index == decoder->GetAccelerationStructureKHRCount()) &&
               (inline_uniform_index == decoder->GetInlineUniformBlockCount());
    }

    void TrackMappedMemory(VkResult result, VkDeviceMemory memory, VkDeviceSize offset)
    {
        if ((result == VK_SUCCESS) && (memory != VK_NULL_HANDLE))
        {
            mapped_memory_offsets_[memory] = offset;
        }
    }

    void TrackUnmappedMemory(VkDeviceMemory memory) { mapped_memory_offsets_.erase(memory); }

    void TrackUnmappedMemory(VkResult result, VkDeviceMemory memory)
    {
        if (result == VK_SUCCESS)
        {
            TrackUnmappedMemory(memory);
        }
    }

    static size_t DescriptorUpdateTemplateElementSize(VkDescriptorType type)
    {
        switch (type)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                return sizeof(VkDescriptorImageInfo);
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                return sizeof(VkDescriptorBufferInfo);
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                return sizeof(VkBufferView);
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                return sizeof(VkAccelerationStructureKHR);
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                return 1;
            default:
                return 0;
        }
    }

    template <typename Handle, typename Info>
    Handle MaterializeDescriptorHandle(format::HandleId id, const Info* info)
    {
        if (id == format::kNullHandleId)
        {
            return VK_NULL_HANDLE;
        }
        return info != nullptr ? info->handle : format::FromHandleId<Handle>(id);
    }

    void MapDescriptorUpdateTemplateHandles(DescriptorUpdateTemplateDecoder* decoder)
    {
        auto* buffer_meta = decoder->GetBufferInfoMetaStructPointer();
        auto* buffers     = decoder->GetBufferInfoPointer();
        for (size_t i = 0; i < decoder->GetBufferInfoCount(); ++i)
        {
            buffers[i].buffer = MaterializeDescriptorHandle<VkBuffer, VulkanBufferInfo>(
                buffer_meta[i].buffer,
                static_cast<const CommonObjectInfoTable&>(object_info_table_).GetVkBufferInfo(buffer_meta[i].buffer));
        }

        auto* texel_ids   = decoder->GetTexelBufferViewHandleIdsPointer();
        auto* texel_views = decoder->GetTexelBufferViewPointer();
        for (size_t i = 0; i < decoder->GetTexelBufferViewCount(); ++i)
        {
            texel_views[i] = MaterializeDescriptorHandle<VkBufferView, VulkanBufferViewInfo>(
                texel_ids[i],
                static_cast<const CommonObjectInfoTable&>(object_info_table_).GetVkBufferViewInfo(texel_ids[i]));
        }

        auto* acceleration_structure_ids = decoder->GetAccelerationStructureKHRHandleIdsPointer();
        auto* acceleration_structures    = decoder->GetAccelerationStructureKHRPointer();
        for (size_t i = 0; i < decoder->GetAccelerationStructureKHRCount(); ++i)
        {
            acceleration_structures[i] =
                MaterializeDescriptorHandle<VkAccelerationStructureKHR, VulkanAccelerationStructureKHRInfo>(
                    acceleration_structure_ids[i],
                    static_cast<const CommonObjectInfoTable&>(object_info_table_)
                        .GetVkAccelerationStructureKHRInfo(acceleration_structure_ids[i]));
        }
    }

    template <typename FunctionPointer>
    struct FunctionPointerTraits;

    template <typename Return, typename... Args>
    struct FunctionPointerTraits<Return(VKAPI_PTR*)(Args...)>
    {
        template <size_t Index>
        using Argument = typename std::tuple_element<Index, std::tuple<Args...>>::type;
    };

    template <typename Handle, typename Mapper>
    Handle* MaterializeHandlePointer(HandlePointerDecoder<Handle>* decoder, Mapper&& mapper)
    {
        if ((decoder == nullptr) || decoder->IsNull())
        {
            return nullptr;
        }

        decoder->SetHandleLength(decoder->GetLength());
        Handle*                 handles = decoder->GetHandlePointer();
        const format::HandleId* ids     = decoder->GetPointer();
        for (size_t i = 0; i < decoder->GetLength(); ++i)
        {
            handles[i] = mapper(ids[i]);
        }
        return handles;
    }

    template <typename T>
    typename T::struct_type* GetStructPointer(StructPointerDecoder<T>* decoder)
    {
        return ((decoder == nullptr) || decoder->IsNull()) ? nullptr : decoder->GetPointer();
    }

    template <typename T>
    typename T::struct_type** GetStructPointer(StructPointerDecoder<T*>* decoder)
    {
        return ((decoder == nullptr) || decoder->IsNull()) ? nullptr : decoder->GetPointer();
    }

    template <typename T>
    typename T::struct_type* MaterializeStructPointer(StructPointerDecoder<T>* decoder)
    {
        if ((decoder == nullptr) || decoder->IsNull())
        {
            return nullptr;
        }

        T* wrappers = decoder->GetMetaStructPointer();
        for (size_t i = 0; i < decoder->GetLength(); ++i)
        {
            MapStructHandles(&wrappers[i], object_info_table_);
        }
        return decoder->GetPointer();
    }

    template <typename T>
    typename T::struct_type** MaterializeStructPointer(StructPointerDecoder<T*>* decoder)
    {
        if ((decoder == nullptr) || decoder->IsNull())
        {
            return nullptr;
        }

        T** wrappers = decoder->GetMetaStructPointer();
        for (size_t i = 0; i < decoder->GetLength(); ++i)
        {
            for (size_t j = 0; (wrappers[i] != nullptr) && (j < decoder->GetInnerLength(i)); ++j)
            {
                MapStructHandles(&wrappers[i][j], object_info_table_);
            }
        }
        return decoder->GetPointer();
    }

    void** MaterializeVoidPointer(PointerDecoder<uint64_t, void*>* decoder)
    {
        if ((decoder == nullptr) || decoder->IsNull())
        {
            return nullptr;
        }

        void**          pointers = decoder->AllocateOutputData(decoder->GetLength());
        const uint64_t* values   = decoder->GetPointer();
        for (size_t i = 0; i < decoder->GetLength(); ++i)
        {
            pointers[i] = reinterpret_cast<void*>(values[i]);
        }
        return pointers;
    }

    template <typename Callback, size_t Index, typename Encoded>
    typename FunctionPointerTraits<Callback>::template Argument<Index> MaterializeCallbackArgument(Encoded value)
    {
        using Native = typename FunctionPointerTraits<Callback>::template Argument<Index>;
        if constexpr (std::is_pointer<Native>::value)
        {
            return reinterpret_cast<Native>(value);
        }
        else
        {
            return static_cast<Native>(value);
        }
    }

    VulkanNativeCallContext MakeCallContext(const ApiCallInfo& call_info,
                                            format::ApiCallId  call_id,
                                            const char*        name,
                                            const void*        return_value,
                                            size_t             return_value_size) const
    {
        return { { call_info.index, call_info.thread_id },
                 static_cast<uint32_t>(call_id),
                 name,
                 return_value,
                 return_value_size };
    }

    VkDeviceMemory MaterializeMetadataDeviceMemory(format::HandleId id)
    {
        if (id == format::kNullHandleId)
        {
            return format::FromHandleId<VkDeviceMemory>(id);
        }

        const auto* existing = object_info_table_.GetVkDeviceMemoryInfo(id);
        if (existing != nullptr)
        {
            return existing->handle;
        }

        VulkanDeviceMemoryInfo info;
        info.capture_id             = id;
        info.handle                 = format::FromHandleId<VkDeviceMemory>(id);
        const VkDeviceMemory memory = info.handle;
        object_info_table_.AddVkDeviceMemoryInfo(std::move(info));
        return memory;
    }

    VkDevice MaterializeMetadataDevice(format::HandleId id)
    {
        if (id == format::kNullHandleId)
        {
            return format::FromHandleId<VkDevice>(id);
        }
        const auto* existing = object_info_table_.GetVkDeviceInfo(id);
        if (existing != nullptr)
        {
            return existing->handle;
        }
        VulkanDeviceInfo info;
        info.capture_id       = id;
        info.handle           = format::FromHandleId<VkDevice>(id);
        const VkDevice handle = info.handle;
        object_info_table_.AddVkDeviceInfo(std::move(info));
        return handle;
    }

    VkBuffer MaterializeMetadataBuffer(format::HandleId id)
    {
        if (id == format::kNullHandleId)
        {
            return format::FromHandleId<VkBuffer>(id);
        }
        const auto* existing = object_info_table_.GetVkBufferInfo(id);
        if (existing != nullptr)
        {
            return existing->handle;
        }
        VulkanBufferInfo info;
        info.capture_id       = id;
        info.handle           = format::FromHandleId<VkBuffer>(id);
        const VkBuffer handle = info.handle;
        object_info_table_.AddVkBufferInfo(std::move(info));
        return handle;
    }

    VkImage MaterializeMetadataImage(format::HandleId id)
    {
        if (id == format::kNullHandleId)
        {
            return format::FromHandleId<VkImage>(id);
        }
        const auto* existing = object_info_table_.GetVkImageInfo(id);
        if (existing != nullptr)
        {
            return existing->handle;
        }
        VulkanImageInfo info;
        info.capture_id      = id;
        info.handle          = format::FromHandleId<VkImage>(id);
        const VkImage handle = info.handle;
        object_info_table_.AddVkImageInfo(std::move(info));
        return handle;
    }

    VkPipeline MaterializeMetadataPipeline(format::HandleId id)
    {
        if (id == format::kNullHandleId)
        {
            return format::FromHandleId<VkPipeline>(id);
        }
        const auto* existing = object_info_table_.GetVkPipelineInfo(id);
        if (existing != nullptr)
        {
            return existing->handle;
        }
        VulkanPipelineInfo info;
        info.capture_id         = id;
        info.handle             = format::FromHandleId<VkPipeline>(id);
        const VkPipeline handle = info.handle;
        object_info_table_.AddVkPipelineInfo(std::move(info));
        return handle;
    }

    VkAccelerationStructureKHR MaterializeMetadataAccelerationStructure(format::HandleId id)
    {
        if (id == format::kNullHandleId)
        {
            return format::FromHandleId<VkAccelerationStructureKHR>(id);
        }
        const auto* existing = object_info_table_.GetVkAccelerationStructureKHRInfo(id);
        if (existing != nullptr)
        {
            return existing->handle;
        }
        VulkanAccelerationStructureKHRInfo info;
        info.capture_id                         = id;
        info.handle                             = format::FromHandleId<VkAccelerationStructureKHR>(id);
        const VkAccelerationStructureKHR handle = info.handle;
        object_info_table_.AddVkAccelerationStructureKHRInfo(std::move(info));
        return handle;
    }

    VkPhysicalDevice MaterializeMetadataPhysicalDevice(format::HandleId id)
    {
        if (id == format::kNullHandleId)
        {
            return format::FromHandleId<VkPhysicalDevice>(id);
        }

        const auto* existing = object_info_table_.GetVkPhysicalDeviceInfo(id);
        if (existing != nullptr)
        {
            return existing->handle;
        }

        VulkanPhysicalDeviceInfo info;
        info.capture_id                        = id;
        info.handle                            = format::FromHandleId<VkPhysicalDevice>(id);
        const VkPhysicalDevice physical_device = info.handle;
        object_info_table_.AddVkPhysicalDeviceInfo(std::move(info));
        return physical_device;
    }

    VulkanNativeCallCallbacks&                                             callbacks_;
    CommonObjectInfoTable                                                  object_info_table_;
    std::unordered_map<VkDeviceMemory, VkDeviceSize>                       mapped_memory_offsets_;
    std::unordered_map<format::HandleId, std::vector<VulkanOpaqueAddress>> pending_opaque_addresses_;
    uint64_t                                                               current_block_index_{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_NATIVE_CALL_CONSUMER_BASE_H
