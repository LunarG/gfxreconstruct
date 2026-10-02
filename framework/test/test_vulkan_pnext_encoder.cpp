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

// The pNext encoder's dispatch over the schema's extensible-structure catalog.

#include <catch2/catch.hpp>

#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "generated/generated_vulkan_schema_enumerants.h"
#include "generated/generated_vulkan_schema_types.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "schema/structure_type_index.h"
#include "util/enumerants.h"
#include "util/type_list.h"

#include "vulkan/vulkan.h"

#include <cstring>

namespace
{
using namespace gfxrecon;
} // namespace

// The pNext encoder's dispatch: for a structure the chain can hold, the entry point finds the node by its sType and
// encodes it as EncodeStructPtr of that structure does, byte for byte. A zero-initialized instance with its sType set
// is enough to tell the structures apart and needs no handles registered; the per-structure encoding is proven
// elsewhere, this proves the dispatch reaches it.
//
// The walk samples the catalog rather than exhausting it: ForEachType is a fold, and a fold over 1,144 types exceeds
// clang's nesting limit (findings, "fold expressions nest"). The sample takes the catalog's ends, structures whose
// encoders are hand-written, and structures the schema excludes; the index itself is sized by the generated checks.
TEST_CASE("EncodePNextStruct dispatches an extensible structure to its encoder", "[schema][encode][pnext]")
{
    namespace api_types        = schema::vulkan::api_types;
    using ExtensibleStructures = schema::vulkan::catalog::extensible_structures;
    using Index                = schema::StructureTypeIndex<ExtensibleStructures>;
    using Sample               = util::TypeList<api_types::VkApplicationInfo,
                                  api_types::VkDeviceCreateInfo,
                                  api_types::VkAttachmentReferenceStencilLayout,
                                  api_types::VkPhysicalDeviceFeatures2,
                                  api_types::VkWriteDescriptorSet,
                                  api_types::VkAccelerationStructureGeometryKHR,
                                  api_types::VkDescriptorGetInfoEXT,
                                  api_types::VkImageToMemoryCopy,
                                  api_types::VkPushDescriptorSetWithTemplateInfo,
                                  api_types::VkPipelineCreateInfoKHR,
                                  api_types::VkRenderPassFragmentDensityMapOffsetEndInfoEXT,
                                  api_types::VkDataGraphPipelineConstantARM>;

    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    size_t visited = 0;
    util::ForEachType<Sample>([&]<typename Descriptor>() {
        using Struct = typename Descriptor::element_type;
        INFO(util::NameOf(Descriptor::structure_type));

        Struct value{};
        value.sType = Descriptor::structure_type;

        encode::ParameterBuffer  actual_buffer;
        encode::ParameterEncoder actual(&actual_buffer);
        encode::EncodePNextStruct(&actual, &value);

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        encode::EncodeStructPtr(&oracle, &value);

        CHECK(same_bytes(actual_buffer, oracle_buffer));
        CHECK(Index::Find(Descriptor::structure_type) != Index::End());
        ++visited;
    });
    CHECK(visited == util::TypeListSizeV<Sample>);

    // A null chain, and a chain whose only node is one the loader adds, both encode as a null pointer.
    {
        VkBaseInStructure loader{ VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO, nullptr };

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        oracle.EncodeStructPtrPreamble(nullptr);

        for (const void* chain : { static_cast<const void*>(nullptr), static_cast<const void*>(&loader) })
        {
            encode::ParameterBuffer  actual_buffer;
            encode::ParameterEncoder actual(&actual_buffer);
            encode::EncodePNextStruct(&actual, chain);
            CHECK(same_bytes(actual_buffer, oracle_buffer));
        }
    }

    // A loader node ahead of a recognized one is skipped, and the recognized one is encoded.
    {
        VkAttachmentReferenceStencilLayout stencil{};
        stencil.sType         = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT;
        stencil.stencilLayout = VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL;
        VkBaseInStructure loader{ VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO,
                                  reinterpret_cast<const VkBaseInStructure*>(&stencil) };

        encode::ParameterBuffer  actual_buffer;
        encode::ParameterEncoder actual(&actual_buffer);
        encode::EncodePNextStruct(&actual, &loader);

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        encode::EncodeStructPtr(&oracle, &stencil);

        CHECK(same_bytes(actual_buffer, oracle_buffer));
    }

    // The two loader enumerants name no structure, so they are misses in the index.
    CHECK(Index::Find(VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) == Index::End());
    CHECK(Index::Find(VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO) == Index::End());
}
