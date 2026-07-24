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

#ifndef GFXRECON_GRAPHICS_VULKAN_RESOURCES_H
#define GFXRECON_GRAPHICS_VULKAN_RESOURCES_H

#include "util/defines.h"
#include "format/format.h"
#include <vulkan/vulkan_core.h>

#include <unordered_map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

enum ResourceType
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
    ImageResource() : AssetBase(kImage) {}
};

struct ImageViewResource : AssetBase
{
    ImageViewResource() : AssetBase(kImageView) {}
};

struct BufferResource : AssetBase
{
    BufferResource() : AssetBase(kBuffer) {}
};

struct BufferViewResource : AssetBase
{
    BufferViewResource() : AssetBase(kBufferView) {}
};

struct DescriptorSetResource : ResourceBase
{
    DescriptorSetResource() : ResourceBase(kDescriptorSet) {}

    ~DescriptorSetResource();

    void ReferenceResource(ResourceBase* resource);

    std::unordered_set<ResourceBase*> referenced_resources;
};

struct SamplerResource : ResourceBase
{
    SamplerResource() : ResourceBase(kSampler) {}
};

struct AccelerationStructure : ResourceBase
{
    AccelerationStructure() : ResourceBase(kAccelerationStructure) {}
};

struct TensorResource : AssetBase
{
    TensorResource() : AssetBase(kTensor) {}
};

struct DataGraphResource : AssetBase
{
    DataGraphResource() : AssetBase(kDataGraph) {}
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_RESOURCES_H
