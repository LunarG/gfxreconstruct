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

// Generic EncodeStruct definition. PRIVATE: generated_vulkan_struct_encoders.cpp is the one translation unit that
// includes it and instantiates the walk. Callers see the declaration in encode/vulkan_encode_struct.h, beside the
// prototypes of the structures that keep a generated body, and a call by structure type resolves as it always did.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_IMPL_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_IMPL_H

#include "encode/vulkan_encode_action.h"
#include "encode/vulkan_encode_struct.h"
#include "generated/generated_vulkan_schema.h"
#include "schema/schema.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// The native structure to its API type descriptor. Encode's storage is the API's own structure, which cannot carry
// an api_element alias the way a decoded wrapper does, so the inverse of the descriptor's element_type is a trait.
// For structures it is unique. Hand-written while one structure migrates; at inversion the schema generator emits
// one specialization per structure into the native member partition.
template <typename Struct>
struct DescriptorFor;

// One row per migrated structure while the list is hand-written. At inversion the schema generator emits the
// specializations and this macro retires with the list.
#define GFXRECON_VULKAN_DESCRIPTOR_FOR(Struct)         \
    template <>                                        \
    struct DescriptorFor<Struct>                       \
    {                                                  \
        using type = schema::api_type::vulkan::Struct; \
    }

GFXRECON_VULKAN_DESCRIPTOR_FOR(VkBindMemoryStatus);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkBufferCreateInfo);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkBufferMemoryBarrier);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkDebugUtilsMessengerCreateInfoEXT);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkDebugUtilsObjectNameInfoEXT);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkExtent2D);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkImportMemoryWin32HandleInfoNV);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkMappedMemoryRange);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkPipelineCacheCreateInfo);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkPipelineCacheHeaderVersionOne);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkPipelineCreateInfoKHR);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkSubmitInfo);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkSubpassEndInfo);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkSurfaceFullScreenExclusiveWin32InfoEXT);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkTransformMatrixKHR);
GFXRECON_VULKAN_DESCRIPTOR_FOR(VkWin32SurfaceCreateInfoKHR);

template <typename Struct>
concept HasDescriptor = requires
{
    typename DescriptorFor<Struct>::type;
};

template <SchemaDriven Struct>
void EncodeStruct(ParameterEncoder* encoder, const Struct& value)
{
    static_assert(HasDescriptor<Struct>, "A schema-driven structure must name its API type descriptor");
    using ApiElement = typename DescriptorFor<Struct>::type;
    static_assert(schema::HasSchema<ApiElement>, "A schema-driven structure's API element must have a schema");

    EncodeStructAction action(encoder);
    schema::WalkFields<ApiElement>(action, value);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_IMPL_H
