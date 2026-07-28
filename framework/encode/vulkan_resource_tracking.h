/*
 ** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_RESOURCES_H
#define GFXRECON_ENCODE_VULKAN_RESOURCES_H

#include "util/defines.h"
#include "util/range_list.h"
#include "format/format.h"
#include "encode/vulkan_state_info.h"
#include <vulkan/vulkan_core.h>

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

enum class ResourceType
{
    kUnknown,
    kImage,
    kImageView,
    kBuffer,
    kBufferView,
    kDescriptorSet,
    kAccelerationStructure,
    kSampler,
    kDataGraph,
    kTensor
};

struct DescriptorSetResource;

struct ResourceBase
{
    ResourceBase(ResourceType t) : type(t), dirty(true) {}

    ResourceBase(const ResourceBase&)            = delete;
    ResourceBase& operator=(const ResourceBase&) = delete;

    ~ResourceBase();

    ResourceType type;
    bool         dirty;

    void BindToDescriptorSet(DescriptorSetResource* desc_set);

    void UnbindFromDescriptorSet(DescriptorSetResource* desc_set);

  private:
    std::unordered_set<DescriptorSetResource*> descriptor_sets_bound_to;
};

struct AssetBase : ResourceBase
{
    AssetBase(ResourceType type) :
        ResourceBase(type), queue_family_index{ 0 }, bind_memory_id{ format::kNullHandleId }, bind_offset{ 0 },
        size{ 0 }, bind_pnext{ nullptr }
    {}

    uint32_t                   queue_family_index;
    format::HandleId           bind_memory_id;
    VkDeviceSize               bind_offset;
    VkDeviceSize               size;
    const void*                bind_pnext;
    std::unique_ptr<uint8_t[]> bind_pnext_memory;
};

struct ImageResource : AssetBase
{
    ImageResource() : AssetBase(ResourceType::kImage) {}
};

struct ImageViewResource : AssetBase
{
    ImageViewResource() : AssetBase(ResourceType::kImageView) {}
};

struct BufferResource : AssetBase
{
    BufferResource() : AssetBase(ResourceType::kBuffer) {}
};

struct BufferViewResource : AssetBase
{
    BufferViewResource() : AssetBase(ResourceType::kBufferView) {}
};

struct DescriptorSetResource : ResourceBase
{
    DescriptorSetResource() : ResourceBase(ResourceType::kDescriptorSet) {}

    ~DescriptorSetResource();

    void ReferenceResource(ResourceBase* resource);

    std::unordered_set<ResourceBase*> referenced_resources;
};

struct SamplerResource : ResourceBase
{
    SamplerResource() : ResourceBase(ResourceType::kSampler) {}
};

struct AccelerationStructureResource : ResourceBase
{
    AccelerationStructureResource() : ResourceBase(ResourceType::kAccelerationStructure) {}
};

struct TensorResource : AssetBase
{
    TensorResource() : AssetBase(ResourceType::kTensor) {}
};

struct DataGraphResource : AssetBase
{
    DataGraphResource() : AssetBase(ResourceType::kDataGraph) {}
};

enum class ResourceAccessType : uint8_t
{
    kUnknown = 0,
    kRead    = 1,
    kWrite   = 2
};

GFXRECON_DEFINE_ENUM_BIT_OPERATORS(ResourceAccessType)

struct CommandBufferResourceTracking
{
    // Descriptor sets bound to this command buffer plus the dynamic offsets provided at bind time,
    // stored per binding index and array element so consumers do not need to re-derive the
    // spec-defined dynamic offset ordering.
    struct BoundDescriptorSet
    {
        const vulkan_state_info::DescriptorSetBindingsMap* descriptor_bindings{ nullptr };

        // Binding index -> per-array-element dynamic offsets; only populated for *_DYNAMIC bindings.
        std::unordered_map<uint32_t, std::vector<uint32_t>> dynamic_offsets;
    };

    std::unordered_map<vulkan_state_info::PipelineBindPoints, std::unordered_map<uint32_t, BoundDescriptorSet>>
        bound_descriptors;

    vulkan_state_info::PipelineBindPoints referenced_pipeline_bind_points{
        vulkan_state_info::PipelineBindPoints::kBindPointNone
    };

    std::vector<CommandBufferResourceTracking*> secondaries;

    struct ReferencedResourceRange
    {
        ReferencedResourceRange() = delete;
        ReferencedResourceRange(uint64_t offset, uint64_t size, ResourceAccessType access) :
            range_list(offset, size), access_type(access)
        {}

        void SetAccessType(ResourceAccessType access)
        {
            GFXRECON_ASSERT(access == ResourceAccessType::kRead || access == ResourceAccessType::kWrite ||
                            access == (ResourceAccessType::kRead | ResourceAccessType::kWrite));
            access_type |= access;
        }

        util::RangeList    range_list;
        ResourceAccessType access_type;
    };

    std::unordered_map<AssetBase*, ReferencedResourceRange> referenced_ranges;

    void ReferenceResource(AssetBase* resource, uint64_t offset, uint64_t size, ResourceAccessType access);

    uint32_t GetDynamicOffset(uint32_t                              desc_index,
                              uint32_t                              binding_index,
                              uint32_t                              array_index,
                              vulkan_state_info::PipelineBindPoints ppl_bind_point) const;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_RESOURCES_H
