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

// Contract check for the generated Vulkan field schema.
//
// Including every generated part is itself most of the check: the whole schema, all member-trait partitions, and the
// decoded representation traits have to parse and agree. The assertions below then hold the contracts to the
// canonical vkCmdPipelineBarrier and VkBufferMemoryBarrier example.

#include <catch2/catch.hpp>

#include "generated/generated_vulkan_schema.h"
#include "generated/generated_vulkan_schema_decoded_traits.h"

#include "generated/generated_vulkan_schema_decoded_command_traits.inc"
#include "generated/generated_vulkan_schema_decoded_struct_traits.inc"
#include "generated/generated_vulkan_schema_native_struct_traits.inc"

#include <type_traits>

namespace
{
using namespace gfxrecon;

using Command = schema::command::vulkan::CmdPipelineBarrier;
namespace cmd_field     = schema::field::vulkan::CmdPipelineBarrier;
namespace barrier_field = schema::field::vulkan::VkBufferMemoryBarrier;

// A command schema has exactly one return Field, and a structure schema has none.
static_assert(schema::HasSchema<Command>);
static_assert(schema::HasCommandSchema<Command>);
static_assert(schema::HasSchema<VkBufferMemoryBarrier>);
static_assert(!schema::HasCommandSchema<VkBufferMemoryBarrier>);

// A void command still carries one Return Field, shaped NoValue, and its ReturnType is void.
static_assert(std::is_same_v<schema::Return<Command>, cmd_field::result>);
static_assert(std::is_same_v<schema::ReturnType<Command>, void>);
static_assert(schema::NoValueField<cmd_field::result>);

// The parameter partition keeps registry order and drops only the return Field.
static_assert(std::is_same_v<schema::ParameterFields<Command>,
                             util::TypeList<cmd_field::commandBuffer,
                                            cmd_field::srcStageMask,
                                            cmd_field::dstStageMask,
                                            cmd_field::dependencyFlags,
                                            cmd_field::memoryBarrierCount,
                                            cmd_field::pMemoryBarriers,
                                            cmd_field::bufferMemoryBarrierCount,
                                            cmd_field::pBufferMemoryBarriers,
                                            cmd_field::imageMemoryBarrierCount,
                                            cmd_field::pImageMemoryBarriers>>);

// A non-void command resolves its native return type from the same Return Field.
static_assert(std::is_same_v<schema::ReturnType<schema::command::vulkan::CreateBuffer>, VkResult>);

// Logical kind selects the operation. Two named types that share one C++ representation stay distinct.
static_assert(std::is_same_v<schema::api_type::vulkan::VkPipelineStageFlags::native_type, VkPipelineStageFlags>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkPipelineStageFlags::kind, schema::field_kind::Flags>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkResult::kind, schema::field_kind::Enum>);
static_assert(std::is_same_v<schema::api_type::vulkan::UInt32::kind, schema::field_kind::UInt32>);

// Shape concepts select on exactly the logical kind and the use-site shape.
static_assert(schema::HandleField<barrier_field::buffer>);
static_assert(schema::StructField<cmd_field::pBufferMemoryBarriers>);
static_assert(schema::PointerArrayField<cmd_field::pBufferMemoryBarriers>);
static_assert(std::is_same_v<cmd_field::pBufferMemoryBarriers::count_field, cmd_field::bufferMemoryBarrierCount>);
static_assert(schema::ExtensionChainField<barrier_field::pNext>);

// One Field reaches a member of every storage type that holds it.
static_assert(schema::Addressable<VkBufferMemoryBarrier, barrier_field::buffer>);
static_assert(schema::Addressable<decode::Decoded_VkBufferMemoryBarrier, barrier_field::buffer>);
static_assert(schema::Addressable<decode::args::CmdPipelineBarrier, cmd_field::pBufferMemoryBarriers>);
static_assert(schema::StoresNativeField<VkBufferMemoryBarrier, barrier_field::buffer>);

// A scalar that decode leaves in the wrapped native structure has no decoded-wrapper mapping.
static_assert(schema::HasMember<VkBufferMemoryBarrier, barrier_field::srcAccessMask>);
static_assert(!schema::HasMember<decode::Decoded_VkBufferMemoryBarrier, barrier_field::srcAccessMask>);

// A bitfield member keeps a mapping, but it is not addressable, so GetRef drops out of the overload set.
static_assert(schema::HasMember<VkAccelerationStructureInstanceKHR,
                                schema::field::vulkan::VkAccelerationStructureInstanceKHR::mask>);
static_assert(schema::NonAddressable<VkAccelerationStructureInstanceKHR,
                                     schema::field::vulkan::VkAccelerationStructureInstanceKHR::mask>);

// Decoded representation resolves through the traits key, not through the schema.
static_assert(std::is_same_v<decode::Decoded<schema::api_type::vulkan::VkBufferMemoryBarrier>,
                             decode::Decoded_VkBufferMemoryBarrier>);
static_assert(std::is_same_v<decode::Decoded<Command>, decode::args::CmdPipelineBarrier>);
static_assert(decode::TraitsFor<Command>::call_id == format::ApiCallId::ApiCall_vkCmdPipelineBarrier);

// One walk visits the whole field list, and one Action supplies the Apply overloads that its shapes select.
struct CountingAction
{
    size_t handles = 0;
    size_t scalars = 0;
    size_t others  = 0;

    template <typename Field, typename Store>
        requires schema::HandleField<Field>
    void Apply(Field, Store&)
    {
        ++handles;
    }

    template <typename Field, typename Store>
        requires schema::ScalarField<Field>
    void Apply(Field, Store&)
    {
        ++scalars;
    }

    template <typename Field, typename Store>
        requires(!schema::HandleField<Field> && !schema::ScalarField<Field>)
    void Apply(Field, Store&)
    {
        ++others;
    }
};

// The positional invocation step expands to the call the driver path already makes.
void RecordPipelineBarrier(VkCommandBuffer,
                           VkPipelineStageFlags,
                           VkPipelineStageFlags,
                           VkDependencyFlags,
                           uint32_t,
                           const VkMemoryBarrier*,
                           uint32_t,
                           const VkBufferMemoryBarrier*,
                           uint32_t,
                           const VkImageMemoryBarrier*)
{}

struct NativeCallStore
{
    VkCommandBuffer              commandBuffer;
    VkPipelineStageFlags         srcStageMask;
    VkPipelineStageFlags         dstStageMask;
    VkDependencyFlags            dependencyFlags;
    uint32_t                     memoryBarrierCount;
    const VkMemoryBarrier*       pMemoryBarriers;
    uint32_t                     bufferMemoryBarrierCount;
    const VkBufferMemoryBarrier* pBufferMemoryBarriers;
    uint32_t                     imageMemoryBarrierCount;
    const VkImageMemoryBarrier*  pImageMemoryBarriers;
};
} // namespace

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// A hand-written store joins the same Fields, which is why member traits key on storage type and Field rather than
// on the Field alone.
template <>
struct MemberPointer<NativeCallStore, cmd_field::commandBuffer>
{
    static constexpr auto value = &NativeCallStore::commandBuffer;
};
template <>
struct MemberPointer<NativeCallStore, cmd_field::srcStageMask>
{
    static constexpr auto value = &NativeCallStore::srcStageMask;
};
template <>
struct MemberPointer<NativeCallStore, cmd_field::dstStageMask>
{
    static constexpr auto value = &NativeCallStore::dstStageMask;
};
template <>
struct MemberPointer<NativeCallStore, cmd_field::dependencyFlags>
{
    static constexpr auto value = &NativeCallStore::dependencyFlags;
};
template <>
struct MemberPointer<NativeCallStore, cmd_field::memoryBarrierCount>
{
    static constexpr auto value = &NativeCallStore::memoryBarrierCount;
};
template <>
struct MemberPointer<NativeCallStore, cmd_field::pMemoryBarriers>
{
    static constexpr auto value = &NativeCallStore::pMemoryBarriers;
};
template <>
struct MemberPointer<NativeCallStore, cmd_field::bufferMemoryBarrierCount>
{
    static constexpr auto value = &NativeCallStore::bufferMemoryBarrierCount;
};
template <>
struct MemberPointer<NativeCallStore, cmd_field::pBufferMemoryBarriers>
{
    static constexpr auto value = &NativeCallStore::pBufferMemoryBarriers;
};
template <>
struct MemberPointer<NativeCallStore, cmd_field::imageMemoryBarrierCount>
{
    static constexpr auto value = &NativeCallStore::imageMemoryBarrierCount;
};
template <>
struct MemberPointer<NativeCallStore, cmd_field::pImageMemoryBarriers>
{
    static constexpr auto value = &NativeCallStore::pImageMemoryBarriers;
};

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

TEST_CASE("One field walk covers a generated structure schema", "[schema]")
{
    CountingAction        action{};
    VkBufferMemoryBarrier barrier{};

    schema::WalkFields<VkBufferMemoryBarrier>(action, barrier);

    // sType, srcAccessMask, dstAccessMask, srcQueueFamilyIndex, dstQueueFamilyIndex, offset and size are value-shaped
    // scalars, buffer is the one handle, and pNext is the extension chain.
    CHECK(action.handles == 1);
    CHECK(action.scalars == 7);
    CHECK(action.others == 1);
}

TEST_CASE("A generated command schema invokes a positional call in parameter order", "[schema]")
{
    NativeCallStore store{};

    // The requires clause on InvokeFromFields is the assertion: it is satisfied only when every parameter Field
    // reaches the store and the resulting positional call matches the command's signature.
    schema::InvokeFromFields<Command>(RecordPipelineBarrier, store);

    CHECK(store.memoryBarrierCount == 0);
}
