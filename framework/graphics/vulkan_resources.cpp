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

#include "vulkan_resources.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

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

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
