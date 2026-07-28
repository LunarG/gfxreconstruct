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

#include "vulkan_resource_tracking.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

ResourceBase::~ResourceBase()
{
    for (DescriptorSetResource* desc_set : descriptor_sets_bound_to)
    {
        desc_set->dirty = true;
        desc_set->referenced_resources.erase(this);
    }
}

void ResourceBase::BindToDescriptorSet(DescriptorSetResource* desc_set)
{
    descriptor_sets_bound_to.insert(desc_set);
}

void ResourceBase::UnbindFromDescriptorSet(DescriptorSetResource* desc_set)
{
    descriptor_sets_bound_to.erase(desc_set);
}

DescriptorSetResource::~DescriptorSetResource()
{
    for (auto resource : referenced_resources)
    {
        resource->UnbindFromDescriptorSet(this);
    }
}

void DescriptorSetResource::ReferenceResource(ResourceBase* resource)
{
    referenced_resources.insert(resource);
    resource->BindToDescriptorSet(this);
}

uint32_t CommandBufferResourceTracking::GetDynamicOffset(uint32_t                              desc_index,
                                                         uint32_t                              binding_index,
                                                         uint32_t                              array_index,
                                                         vulkan_state_info::PipelineBindPoints ppl_bind_point) const
{
    const auto bind_point_entry = bound_descriptors.find(ppl_bind_point);
    if (bind_point_entry != bound_descriptors.end())
    {
        const auto& bind_point_descriptors = bind_point_entry->second;
        const auto  set_entry              = bind_point_descriptors.find(desc_index);
        if (set_entry != bind_point_descriptors.end())
        {
            const auto dyn_offset_entry = set_entry->second.dynamic_offsets.find(binding_index);
            if (dyn_offset_entry != set_entry->second.dynamic_offsets.end() &&
                array_index < dyn_offset_entry->second.size())
            {
                return dyn_offset_entry->second[array_index];
            }
        }
    }

    return 0;
}

void CommandBufferResourceTracking::ReferenceResource(AssetBase*         resource,
                                                      uint64_t           offset,
                                                      uint64_t           size,
                                                      ResourceAccessType access)
{
    GFXRECON_ASSERT(offset <= resource->size);
    const uint64_t converted_size =
        size == VK_WHOLE_SIZE ? ((offset < resource->size) ? (resource->size - offset) : 0) : size;

    auto entry = referenced_ranges.find(resource);
    if (entry == referenced_ranges.end())
    {
        referenced_ranges.emplace(std::piecewise_construct,
                                  std::forward_as_tuple(resource),
                                  std::forward_as_tuple(offset, converted_size, access));
    }
    else
    {
        entry->second.range_list.AddRange(offset, converted_size);
        entry->second.SetAccessType(access);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
