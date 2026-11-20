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

// This file tests the generated Vulkan schema, its bindings, and the encode and decode field walks. Including the
// generated schema headers is part of the check: they must compile together in one translation unit. The file-scope
// static_asserts check the schema's contracts on vkCmdPipelineBarrier and VkBufferMemoryBarrier. Most TEST_CASEs
// compare EncodeStruct's bytes with an oracle built from ParameterEncoder calls, or decode such bytes with
// DecodeStruct and check each field.

#include <catch2/catch.hpp>

#include "generated/generated_vulkan_call_id.h"
#include "generated/generated_vulkan_schema.h"

#include "binding/vulkan_wire_type.h"
#include "decode/vulkan_decoder_args.h"
#include "generated/generated_vulkan_api_element_of.h"
#include "generated/generated_vulkan_decoder_args.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "test/schema_fill.h"

#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <type_traits>

namespace
{
using namespace gfxrecon;

using Command = schema::vulkan::api_elements::CmdPipelineBarrier;

using Barrier = schema::vulkan::api_elements::VkBufferMemoryBarrier;

namespace cmd_field     = schema::vulkan::fields::CmdPipelineBarrier;
namespace barrier_field = schema::vulkan::fields::VkBufferMemoryBarrier;

// A command schema has exactly one return Field, and a structure schema has none.
static_assert(schema::HasSchemaFields<Command>);
static_assert(schema::HasCommandSchema<Command>);
static_assert(schema::HasSchemaFields<Barrier>);
static_assert(!schema::HasCommandSchema<Barrier>);

// A void command still has one return Field: VoidReturnField holds, and its API type is void.
static_assert(std::is_same_v<schema::ReturnField_t<Command>, cmd_field::result>);
static_assert(std::is_same_v<schema::ApiTypeOf_t<schema::ReturnField_t<Command>::api_element>, void>);
static_assert(schema::VoidReturnField<cmd_field::result>);

// The parameter partition keeps registry order and drops only the return Field.
static_assert(std::is_same_v<schema::ParameterFields_t<Command>,
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

// A non-void command's API return type comes from the same return Field.
static_assert(
    std::is_same_v<schema::ApiTypeOf_t<schema::ReturnField_t<schema::vulkan::api_elements::CreateBuffer>::api_element>,
                   VkResult>);

// category follows vk.xml's category attribute, except that VkSampleMask and VkDeviceSize, basetype in vk.xml, are
// Scalar. A union is a StructOrUnionApiElement.
static_assert(
    std::is_same_v<schema::ApiTypeOf_t<schema::vulkan::api_elements::VkPipelineStageFlags>, VkPipelineStageFlags>);
static_assert(std::is_same_v<schema::vulkan::api_elements::VkPipelineStageFlags::category, schema::category::Bitmask>);
static_assert(std::is_same_v<schema::vulkan::api_elements::VkAccessFlags2::category, schema::category::Bitmask>);
static_assert(std::is_same_v<schema::vulkan::api_elements::VkAccessFlagBits2::category, schema::category::Enum>);
static_assert(std::is_same_v<schema::vulkan::api_elements::VkResult::category, schema::category::Enum>);
static_assert(std::is_same_v<schema::vulkan::api_elements::VkSampleMask::category, schema::category::Scalar>);
static_assert(std::is_same_v<schema::vulkan::api_elements::VkDeviceSize::category, schema::category::Scalar>);
static_assert(std::is_same_v<schema::vulkan::api_elements::VkClearColorValue::category, schema::category::Union>);
static_assert(schema::StructOrUnionApiElement<schema::vulkan::api_elements::VkClearColorValue>);

// A bits enum carries the Bitvalues token. A bitmask holds its flags_type and its bitvalues; a bitmask that vk.xml
// gives no bits enum holds EmptyBitvalues, whose enumerant table is empty.
static_assert(schema::BitvaluesApiElement<schema::vulkan::api_elements::VkAccessFlagBits2>);
static_assert(!schema::BitvaluesApiElement<schema::vulkan::api_elements::VkResult>);
static_assert(
    std::is_same_v<schema::vulkan::api_elements::VkAccessFlags2::flags_type, schema::vulkan::api_elements::VkFlags64>);
static_assert(std::is_same_v<schema::vulkan::api_elements::VkAccessFlags2::bitvalues,
                             schema::vulkan::api_elements::VkAccessFlagBits2>);
static_assert(std::is_same_v<schema::vulkan::api_elements::VkDeviceCreateFlags::bitvalues,
                             schema::vulkan::api_elements::EmptyBitvalues>);

// VkAccessFlags2 and VkPipelineStageFlags2 are one C++ type and two distinct API elements.
static_assert(std::is_same_v<VkAccessFlags2, VkPipelineStageFlags2>);
static_assert(
    !std::is_same_v<schema::vulkan::api_elements::VkAccessFlags2, schema::vulkan::api_elements::VkPipelineStageFlags2>);

// HandleValueField and SimpleValueField match a handle, or a scalar, enum or bitmask, held by value. Only this file
// uses them: in the assertions below and to constrain CountingAction.
template <typename Field>
concept HandleValueField = schema::HandleApiElement<typename Field::api_element> && schema::ValueField<Field>;

template <typename Field>
concept SimpleValueField = schema::SimpleApiElement<typename Field::api_element> && schema::ValueField<Field>;

// UInt32 and VkBool32 are both Scalar; ApiTypeOf_t<UInt32> is uint32_t, and srcQueueFamilyIndex is a SimpleValueField.
static_assert(std::is_same_v<schema::vulkan::api_elements::UInt32::category, schema::category::Scalar>);
static_assert(std::is_same_v<schema::vulkan::api_elements::VkBool32::category, schema::category::Scalar>);
static_assert(std::is_same_v<schema::ApiTypeOf_t<schema::vulkan::api_elements::UInt32>, uint32_t>);
static_assert(SimpleValueField<barrier_field::srcQueueFamilyIndex>);

// SimpleValueField holds for a scalar (offset), a bitmask (srcAccessMask) and an enum (sType).
static_assert(SimpleValueField<barrier_field::srcAccessMask>);
static_assert(SimpleValueField<barrier_field::offset>);
static_assert(SimpleValueField<barrier_field::sType>);

// WireTypeOf: specializations generated for scalar, enum and text (generated_vulkan_wire_types.h); partial
// specializations for bitmask, handle, funcpointer and opaque (binding/wire_type_of.h).
static_assert(
    std::is_same_v<binding::WireTypeOf_t<barrier_field::srcAccessMask::api_element>, format::FlagsEncodeType>);
static_assert(
    std::is_same_v<binding::WireTypeOf_t<schema::vulkan::api_elements::VkAccessFlags2>, format::Flags64EncodeType>);
static_assert(std::is_same_v<binding::WireTypeOf_t<barrier_field::sType::api_element>, format::EnumEncodeType>);
static_assert(std::is_same_v<binding::WireTypeOf_t<barrier_field::offset::api_element>, format::DeviceSizeEncodeType>);
static_assert(std::is_same_v<binding::WireTypeOf_t<barrier_field::srcQueueFamilyIndex::api_element>, uint32_t>);
static_assert(std::is_same_v<binding::WireTypeOf_t<barrier_field::buffer::api_element>, format::HandleEncodeType>);
static_assert(std::is_same_v<binding::WireTypeOf_t<schema::vulkan::api_elements::SizeT>, format::SizeTEncodeType>);
static_assert(std::is_same_v<binding::WireTypeOf_t<schema::vulkan::api_elements::PFN_vkAllocationFunction>,
                             format::AddressEncodeType>);

// The form and category concepts select on the barrier's Fields, and LengthOf_t is the count Field of a run.
static_assert(HandleValueField<barrier_field::buffer>);
static_assert(schema::StructOrUnionApiElement<cmd_field::pBufferMemoryBarriers::api_element>);
static_assert(schema::ArrayField<cmd_field::pBufferMemoryBarriers>);
static_assert(std::is_same_v<schema::LengthOf_t<cmd_field::pBufferMemoryBarriers>,
                             schema::FieldValue<cmd_field::bufferMemoryBarrierCount>>);
static_assert(schema::ExtensionChainField<barrier_field::pNext>);

// One Field reaches a member of every storage type that holds it.
static_assert(schema::StorageFor<VkBufferMemoryBarrier, barrier_field::buffer>);
static_assert(schema::StorageFor<decode::Decoded_VkBufferMemoryBarrier, barrier_field::buffer>);
static_assert(schema::StorageFor<decode::args::CmdPipelineBarrier, cmd_field::pBufferMemoryBarriers>);
static_assert(schema::StoresElementField<VkBufferMemoryBarrier, barrier_field::buffer>);

// A scalar that decode leaves in the wrapped API structure has no decoded-wrapper mapping.
static_assert(schema::StorageFor<VkBufferMemoryBarrier, barrier_field::srcAccessMask>);
static_assert(!schema::StorageFor<decode::Decoded_VkBufferMemoryBarrier, barrier_field::srcAccessMask>);

// objectHandle is a uint64_t vk.xml marks objecttype="objectType": its API element is UInt64, and its
// objecttype_field is objectType, the sibling that holds the handle type at run time.
namespace debug_field = schema::vulkan::fields::VkDebugUtilsObjectNameInfoEXT;
static_assert(std::is_same_v<debug_field::objectHandle::api_element, schema::vulkan::api_elements::UInt64>);
static_assert(std::is_same_v<debug_field::objectHandle::objecttype_field, debug_field::objectType>);
static_assert(SimpleValueField<debug_field::objectHandle>);

// VkAccelerationStructureInstanceKHR::mask is a bitfield, `uint32_t mask : 8`: it has no address, so its Field
// carries bit_width with Get and Set and has no GetRef.
static_assert(schema::StorageFor<VkAccelerationStructureInstanceKHR,
                                 schema::vulkan::fields::VkAccelerationStructureInstanceKHR::mask>);
static_assert(schema::FieldWithBitWidth<schema::vulkan::fields::VkAccelerationStructureInstanceKHR::mask>);
static_assert(schema::vulkan::fields::VkAccelerationStructureInstanceKHR::mask::bit_width::value == 8);
static_assert(!schema::FieldWithBitWidth<barrier_field::buffer>);

static_assert(binding::CallId_v<Command> == format::ApiCallId::ApiCall_vkCmdPipelineBarrier);

// Counts the Fields WalkFields visits, as HandleValueField, SimpleValueField, or neither.
struct CountingAction
{
    size_t handles       = 0;
    size_t simple_values = 0;
    size_t others        = 0;

    template <typename Storage, typename Field>
    requires HandleValueField<Field>
    void Apply(Storage&, Field) { ++handles; }

    template <typename Storage, typename Field>
    requires SimpleValueField<Field>
    void Apply(Storage&, Field) { ++simple_values; }

    template <typename Storage, typename Field>
    requires(!HandleValueField<Field> && !SimpleValueField<Field>) void Apply(Storage&, Field) { ++others; }
};

// Stands in for vkCmdPipelineBarrier in the InvokeFromFields test: the same signature, an empty body. ApiCallStorage
// and AllocateCallStorage below are hand-written command stores for the InvokeFromFields and FieldValue tests. A
// Field's accessor reads the member of its name from any storage type, so a hand-written store serves the same Fields
// as the API structure and its Decoded_ wrapper with no declaration beyond its members.
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

struct ApiCallStorage
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

namespace alloc_field = schema::vulkan::fields::AllocateCommandBuffers;

struct AllocateCallStorage
{
    VkDevice                           device;
    const VkCommandBufferAllocateInfo* pAllocateInfo;
    VkCommandBuffer*                   pCommandBuffers;
};
} // namespace

TEST_CASE("One field walk covers a generated structure schema", "[schema]")
{
    CountingAction        action{};
    VkBufferMemoryBarrier barrier{};

    schema::WalkFields<Barrier>(action, barrier);

    // sType, srcAccessMask, dstAccessMask, srcQueueFamilyIndex, dstQueueFamilyIndex, offset and size are
    // SimpleValueFields, buffer is the one handle, and pNext is the extension chain.
    CHECK(action.handles == 1);
    CHECK(action.simple_values == 7);
    CHECK(action.others == 1);
}

TEST_CASE("Get yields a Field's value in place or by copy", "[schema]")
{
    // An ordinary member is referenced where it lives: Get returns the member itself. A bitfield has no address, so
    // Get reads it through the Field's Get and yields the value.
    using width = schema::vulkan::fields::VkExtent2D::width;
    static_assert(!schema::FieldWithBitWidth<width>);
    static_assert(std::is_same_v<decltype(schema::Get(std::declval<const VkExtent2D&>(), width{})), const uint32_t&>);

    VkExtent2D extent{ 3u, 4u };
    CHECK(&schema::Get(extent, width{}) == &extent.width);
    CHECK(schema::Get(extent, width{}) == 3u);

    using flag = schema::vulkan::fields::StdVideoH264SpsVuiFlags::aspect_ratio_info_present_flag;
    static_assert(schema::FieldWithBitWidth<flag>);
    static_assert(!std::is_reference_v<decltype(schema::Get(std::declval<const StdVideoH264SpsVuiFlags&>(), flag{}))>);

    StdVideoH264SpsVuiFlags flags{};
    flags.aspect_ratio_info_present_flag = 1u;
    CHECK(schema::Get(flags, flag{}) == 1u);
}

TEST_CASE("A length reads a length through a pointer sibling", "[schema]")
{
    // Three command parameters have a vk.xml len of the form param->member, with no parameter that holds the count
    // itself. The generator emits StorageValue<Deref<FieldValue<param>>, member> for each; its Get reads param,
    // dereferences it, and reads member from the structure it points at. That structure's own Fields serve the inner
    // read, so the schema declares the member and emits nothing else for it.
    namespace alloc_info_field = schema::vulkan::fields::VkCommandBufferAllocateInfo;
    namespace set_field        = schema::vulkan::fields::AllocateDescriptorSets;
    namespace set_info_field   = schema::vulkan::fields::VkDescriptorSetAllocateInfo;
    namespace sizes_field      = schema::vulkan::fields::GetAccelerationStructureBuildSizesKHR;
    namespace build_field      = schema::vulkan::fields::VkAccelerationStructureBuildGeometryInfoKHR;

    static_assert(schema::PointerField<alloc_field::pAllocateInfo>);
    static_assert(std::is_same_v<schema::LengthOf_t<alloc_field::pCommandBuffers>,
                                 schema::StorageValue<schema::Deref<schema::FieldValue<alloc_field::pAllocateInfo>>,
                                                      alloc_info_field::commandBufferCount>>);
    static_assert(std::is_same_v<schema::LengthOf_t<set_field::pDescriptorSets>,
                                 schema::StorageValue<schema::Deref<schema::FieldValue<set_field::pAllocateInfo>>,
                                                      set_info_field::descriptorSetCount>>);
    static_assert(std::is_same_v<schema::LengthOf_t<sizes_field::pMaxPrimitiveCounts>,
                                 schema::StorageValue<schema::Deref<schema::FieldValue<sizes_field::pBuildInfo>>,
                                                      build_field::geometryCount>>);

    // It is a length the Action can evaluate on a store that holds the pointer parameter (StorageWithLength); Deref
    // yields the structure the pointer points at, which member is read from.
    static_assert(schema::StorageWithLength<AllocateCallStorage, alloc_field::pCommandBuffers>);
    static_assert(std::is_same_v<decltype(schema::Deref<schema::FieldValue<alloc_field::pAllocateInfo>>::Get(
                                     std::declval<const AllocateCallStorage&>())),
                                 const VkCommandBufferAllocateInfo&>);

    VkCommandBufferAllocateInfo info{};
    info.commandBufferCount = 3u;
    AllocateCallStorage store{ VK_NULL_HANDLE, &info, nullptr };

    CHECK(schema::LengthOf_t<alloc_field::pCommandBuffers>::Get(store) == 3u);
    CHECK(schema::FieldValue<alloc_field::pAllocateInfo>::Get(store) == &info);
}

TEST_CASE("A generated command schema invokes a positional call in parameter order", "[schema]")
{
    ApiCallStorage store{};

    // The requires clause on InvokeFromFields is the assertion: it is satisfied only when every parameter Field
    // reaches the store and the resulting positional call matches the command's signature.
    schema::InvokeFromFields<Command>(RecordPipelineBarrier, store);

    CHECK(store.memoryBarrierCount == 0);
}

TEST_CASE("The schema filler populates every described field", "[schema][fill]")
{
    test::fill::FillContext context;
    VkInstanceCreateInfo    info{};

    test::fill::Fill<schema::vulkan::api_elements::VkInstanceCreateInfo>(context, info);

    // Scalars take the pattern, so do counts, and a counted run is allocated to its count; text is "ab"; a pointer to a
    // described structure is allocated and filled through that structure's schema; the extension chain stays null.
    CHECK(info.flags == 2);
    CHECK(info.enabledLayerCount == 2);
    REQUIRE(info.ppEnabledLayerNames != nullptr);
    CHECK(std::string(info.ppEnabledLayerNames[1]) == "ab");
    REQUIRE(info.pApplicationInfo != nullptr);
    CHECK(info.pApplicationInfo->apiVersion == 2);
    CHECK(std::string(info.pApplicationInfo->pApplicationName) == "ab");
    CHECK(info.pNext == nullptr);
}
