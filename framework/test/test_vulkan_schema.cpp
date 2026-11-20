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

#include "decode/decode_allocator.h"
#include "decode/vulkan_decode_struct_impl.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "util/logging.h"

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

TEST_CASE("DecodeStruct for VkBufferMemoryBarrier is a schema field walk", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks DecodeStruct on bytes written from ParameterEncoder calls: every field round-trips, and the bytes read
    // equal the bytes written.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    // Written from ParameterEncoder calls, not EncodeStruct: EncodeStruct encodes a handle through GetWrappedId, so a
    // handle the capture layer never wrapped would encode as the null id and the handle path would not see a real
    // value. The calls follow the schema's field order.
    constexpr format::HandleId kBufferId       = 0x0000BEEFCAFE0001ull;
    constexpr VkAccessFlags    kSrcAccess      = VK_ACCESS_TRANSFER_WRITE_BIT;
    constexpr VkAccessFlags    kDstAccess      = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_UNIFORM_READ_BIT;
    constexpr uint32_t         kSrcQueueFamily = 3;
    constexpr uint32_t         kDstQueueFamily = 7;
    constexpr VkDeviceSize     kOffset         = 0x1122334455667788ull;
    constexpr VkDeviceSize     kSize           = 4096;

    auto* encoder = parameter_encoder.get();
    encoder->EncodeEnumValue(VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER);
    encode::EncodePNextStruct(encoder, nullptr);
    encoder->EncodeFlagsValue(kSrcAccess);
    encoder->EncodeFlagsValue(kDstAccess);
    encoder->EncodeUInt32Value(kSrcQueueFamily);
    encoder->EncodeUInt32Value(kDstQueueFamily);
    encoder->EncodeHandleIdValue(kBufferId);
    encoder->EncodeUInt64Value(kOffset);
    encoder->EncodeUInt64Value(kSize);

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkBufferMemoryBarrier         walked_value{};
    Decoded_VkBufferMemoryBarrier walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);

    // Round-trips the value that was written, in the right order and at the right width. A field read out of order
    // or at the wrong width would land in a neighbour, so these also pin the canonical field order.
    CHECK(walked_value.sType == VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER);
    CHECK(walked_value.srcAccessMask == kSrcAccess);
    CHECK(walked_value.dstAccessMask == kDstAccess);
    CHECK(walked_value.srcQueueFamilyIndex == kSrcQueueFamily);
    CHECK(walked_value.dstQueueFamilyIndex == kDstQueueFamily);
    CHECK(walked_value.offset == kOffset);
    CHECK(walked_value.size == kSize);

    // The handle lands in the wrapper as a capture-file identity, and the API handle is left for replay to map.
    CHECK(walked.buffer == kBufferId);
    CHECK(walked_value.buffer == VK_NULL_HANDLE);

    // A null pNext decodes as null.
    CHECK(walked.pNext == nullptr);
    CHECK(walked_value.pNext == nullptr);

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk decodes a scalar array into the wrapper and points the API structure's member at it",
          "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks an Array of scalars: VkShaderModuleCreateInfo::pCode decodes into the wrapper's PointerDecoder, and the
    // API structure's pCode points at it. codeSize is decoded as its own scalar in its own position, and the walk
    // never reads it: the run's length travels with the run on the wire.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    // A recognizable SPIR-V-shaped run: the magic number first, so a misread offset is obvious rather than subtle.
    constexpr uint32_t          kFlags    = 0;
    const std::vector<uint32_t> kCode     = { 0x07230203u, 0x00010000u, 0x0008000au, 0x0000002bu, 0x00000000u };
    const size_t                kCodeSize = kCode.size() * sizeof(uint32_t);

    auto* encoder = parameter_encoder.get();
    encoder->EncodeEnumValue(VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO);
    encode::EncodePNextStruct(encoder, nullptr);
    encoder->EncodeFlagsValue(kFlags);
    encoder->EncodeSizeTValue(kCodeSize);
    encoder->EncodeUInt32Array(kCode.data(), kCode.size());

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkShaderModuleCreateInfo         walked_value{};
    Decoded_VkShaderModuleCreateInfo walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);

    CHECK(walked_value.sType == VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO);
    CHECK(walked_value.flags == kFlags);
    CHECK(walked_value.codeSize == kCodeSize);
    CHECK(walked_value.pNext == nullptr);

    // The run landed in the wrapper's PointerDecoder at the length the wire carried...
    REQUIRE(walked.pCode.GetPointer() != nullptr);
    CHECK(walked.pCode.GetLength() == kCode.size());

    // ...the API structure's member points at that same storage rather than a copy...
    CHECK(walked_value.pCode == walked.pCode.GetPointer());

    // ...and every element round-tripped in order.
    for (size_t i = 0; i < kCode.size(); ++i)
    {
        CHECK(walked_value.pCode[i] == kCode[i]);
    }

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk decodes an array of structures and descends into each element", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks an Array of structures in VkSparseBufferMemoryBindInfo, which has no sType and no pNext: the walk does
    // not assume a structure is extensible. Each VkSparseMemoryBind decodes through DecodeStruct, a second field walk.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    constexpr format::HandleId kBufferId = 0x0000BEEFCAFE0002ull;

    VkSparseMemoryBind binds[2]{};
    binds[0].resourceOffset = 0x1000;
    binds[0].size           = 0x2000;
    binds[0].memory         = VK_NULL_HANDLE;
    binds[0].memoryOffset   = 0x3000;
    binds[0].flags          = VK_SPARSE_MEMORY_BIND_METADATA_BIT;
    binds[1].resourceOffset = 0x4000;
    binds[1].size           = 0x5000;
    binds[1].memory         = VK_NULL_HANDLE;
    binds[1].memoryOffset   = 0x6000;
    binds[1].flags          = 0;

    const uint32_t kBindCount = 2;

    auto* encoder = parameter_encoder.get();
    encoder->EncodeHandleIdValue(kBufferId);
    encoder->EncodeUInt32Value(kBindCount);
    encode::EncodeStructArray(encoder, binds, kBindCount);

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkSparseBufferMemoryBindInfo         walked_value{};
    Decoded_VkSparseBufferMemoryBindInfo walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);

    CHECK(walked.buffer == kBufferId);
    CHECK(walked_value.buffer == VK_NULL_HANDLE);
    CHECK(walked_value.bindCount == kBindCount);

    // The decoder was allocated, holds the run at the length the wire carried, and the decoded value's pointer
    // aliases its storage rather than a copy.
    REQUIRE(walked.pBinds != nullptr);
    REQUIRE(walked.pBinds->GetPointer() != nullptr);
    CHECK(walked.pBinds->GetLength() == kBindCount);
    CHECK(walked_value.pBinds == walked.pBinds->GetPointer());

    // Each element decoded through its own walk, in order.
    for (uint32_t i = 0; i < kBindCount; ++i)
    {
        CHECK(walked_value.pBinds[i].resourceOffset == binds[i].resourceOffset);
        CHECK(walked_value.pBinds[i].size == binds[i].size);
        CHECK(walked_value.pBinds[i].memoryOffset == binds[i].memoryOffset);
        CHECK(walked_value.pBinds[i].flags == binds[i].flags);
    }

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk decodes a fixed-extent array in place, extents from the API declaration", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkTransformMatrixKHR::matrix, float[3][4], declared FixedArray<FixedArray<Float, UseCapacity, 4>,
    // UseCapacity, 3>. The Action takes both extents from std::extent_v on the API member's type, so one and two
    // dimensions need no separate case. The decoder is pointed at the API structure's own array, so decoding fills it
    // directly and nothing is assigned afterwards.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    // Row-major and asymmetric, so a transposed or flattened read lands on a different value.
    VkTransformMatrixKHR source{};
    float                next = 1.0f;
    for (uint32_t row = 0; row < 3; ++row)
    {
        for (uint32_t col = 0; col < 4; ++col)
        {
            source.matrix[row][col] = next;
            next += 1.0f;
        }
    }

    parameter_encoder->EncodeFloat2DMatrix(source.matrix, 3, 4);

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkTransformMatrixKHR         walked_value{};
    Decoded_VkTransformMatrixKHR walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);

    // The decoder wrote into the decoded value's own storage rather than storage of its own.
    CHECK(walked.matrix.GetPointer() == &walked_value.matrix[0][0]);
    CHECK(walked.matrix.GetLength() == 12);

    for (uint32_t row = 0; row < 3; ++row)
    {
        for (uint32_t col = 0; col < 4; ++col)
        {
            CHECK(walked_value.matrix[row][col] == source.matrix[row][col]);
        }
    }

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk decodes a pointer to a structure through the same overload as a run", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkDeviceBufferMemoryRequirements::pCreateInfo, a pointer to one VkBufferCreateInfo. It takes the
    // structure branch of the pointer Apply: StructPointerDecoder reads its own length from the wire, so one
    // structure is a run of one. The element is a large extensible structure, so this descends into a second walk,
    // including that element's own pNext.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    VkBufferCreateInfo create_info{};
    create_info.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    create_info.pNext                 = nullptr;
    create_info.flags                 = VK_BUFFER_CREATE_SPARSE_BINDING_BIT;
    create_info.size                  = 0x4000;
    create_info.usage                 = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;

    auto* encoder = parameter_encoder.get();
    encoder->EncodeEnumValue(VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS);
    encode::EncodePNextStruct(encoder, nullptr);
    encode::EncodeStructPtr(encoder, &create_info);

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkDeviceBufferMemoryRequirements         walked_value{};
    Decoded_VkDeviceBufferMemoryRequirements walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);
    CHECK(walked_value.sType == VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS);
    CHECK(walked_value.pNext == nullptr);

    // One element, and the decoded value's pointer aliases the decoder's storage.
    REQUIRE(walked.pCreateInfo != nullptr);
    REQUIRE(walked.pCreateInfo->GetPointer() != nullptr);
    CHECK(walked.pCreateInfo->GetLength() == 1);
    CHECK(walked_value.pCreateInfo == walked.pCreateInfo->GetPointer());

    // The element's walk ran all the way through its own trailing fields.
    const VkBufferCreateInfo& decoded_info = *walked_value.pCreateInfo;
    CHECK(decoded_info.sType == VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO);
    CHECK(decoded_info.flags == create_info.flags);
    CHECK(decoded_info.size == create_info.size);
    CHECK(decoded_info.usage == create_info.usage);
    CHECK(decoded_info.sharingMode == create_info.sharingMode);
    CHECK(decoded_info.queueFamilyIndexCount == 0u);
    CHECK(decoded_info.pNext == nullptr);

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk writes a bitfield through Set, since it has no address", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks StdVideoAV1TileInfoFlags: uniform_tile_spacing_flag : 1 and reserved : 31. Neither member has an
    // address, so its Field holds Get and Set accessors in place of GetRef, and the walk writes through Set. Each
    // bitfield is a whole uint32_t on the wire, so a one-bit flag costs four bytes: 8 bytes for two fields, and
    // reserved carries a value wider than one bit.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    constexpr uint32_t kUniformTileSpacing = 1;
    constexpr uint32_t kReserved           = 0x2A;

    parameter_encoder->EncodeUInt32Value(kUniformTileSpacing);
    parameter_encoder->EncodeUInt32Value(kReserved);

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    CHECK(encoded_size == 2 * sizeof(uint32_t));

    DecodeAllocator::Begin();

    StdVideoAV1TileInfoFlags         walked_value{};
    Decoded_StdVideoAV1TileInfoFlags walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);
    CHECK(walked_value.uniform_tile_spacing_flag == kUniformTileSpacing);
    CHECK(walked_value.reserved == kReserved);

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk keeps an opaque pointer in the wrapper and leaves the decoded value null", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkCheckpointData2NV::pCheckpointMarker, a Pointer<Void> to something outside the API. The captured
    // address means nothing in this process, so ValueDecoder::DecodeAddress reads it into the wrapper's uint64_t, and
    // the API structure's pointer is left null -- the same division a handle gets.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    // A value with bits above 32, so a narrowed read would land somewhere visibly wrong.
    constexpr uint64_t              kMarker = 0x00007FFCDEADBEEFull;
    constexpr VkPipelineStageFlags2 kStage  = VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT;

    auto* encoder = parameter_encoder.get();
    encoder->EncodeEnumValue(VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV);
    encode::EncodePNextStruct(encoder, nullptr);
    encoder->EncodeFlags64Value(kStage);
    encoder->EncodeVoidPtr(reinterpret_cast<const void*>(static_cast<uintptr_t>(kMarker)));

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkCheckpointData2NV         walked_value{};
    Decoded_VkCheckpointData2NV walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);
    CHECK(walked_value.sType == VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV);
    CHECK(walked_value.pNext == nullptr);
    CHECK(walked_value.stage == kStage);

    // The captured address is in the wrapper, at full width...
    CHECK(walked.pCheckpointMarker == kMarker);

    // ...and the decoded value's pointer is null, not the captured address reinterpreted.
    CHECK(walked_value.pCheckpointMarker == nullptr);

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk decodes both address populations in one structure", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkAllocationCallbacks: pUserData is a Pointer<Void>, and the five PFN_* members are Funcpointer values.
    // pUserData takes the pointer-to-opaque-or-void overload and the function pointers take the identifier overload;
    // both read an address into the wrapper and null the API structure's member. No sType or pNext.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    constexpr uint64_t kUserData = 0x00007FFCAAAA0001ull;
    constexpr uint64_t kAlloc    = 0x00007FFCAAAA0002ull;
    constexpr uint64_t kRealloc  = 0x00007FFCAAAA0003ull;
    constexpr uint64_t kFree     = 0x00007FFCAAAA0004ull;
    constexpr uint64_t kInternal = 0x00007FFCAAAA0005ull;
    constexpr uint64_t kIntFree  = 0x00007FFCAAAA0006ull;

    auto* encoder = parameter_encoder.get();
    encoder->EncodeVoidPtr(reinterpret_cast<const void*>(static_cast<uintptr_t>(kUserData)));
    for (uint64_t fn : { kAlloc, kRealloc, kFree, kInternal, kIntFree })
    {
        // EncodeFunctionPtr reinterprets its argument, so it takes a function pointer rather than the value.
        encoder->EncodeFunctionPtr(reinterpret_cast<PFN_vkVoidFunction>(static_cast<uintptr_t>(fn)));
    }

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    CHECK(encoded_size == 6 * sizeof(uint64_t));

    DecodeAllocator::Begin();

    VkAllocationCallbacks         walked_value{};
    Decoded_VkAllocationCallbacks walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);

    // Every captured value is in the wrapper, at full width and in order.
    CHECK(walked.pUserData == kUserData);
    CHECK(walked.pfnAllocation == kAlloc);
    CHECK(walked.pfnReallocation == kRealloc);
    CHECK(walked.pfnFree == kFree);
    CHECK(walked.pfnInternalAllocation == kInternal);
    CHECK(walked.pfnInternalFree == kIntFree);

    // ...and every pointer in the decoded value is null, function pointers included.
    CHECK(walked_value.pUserData == nullptr);
    CHECK(walked_value.pfnAllocation == nullptr);
    CHECK(walked_value.pfnReallocation == nullptr);
    CHECK(walked_value.pfnFree == nullptr);
    CHECK(walked_value.pfnInternalAllocation == nullptr);
    CHECK(walked_value.pfnInternalFree == nullptr);

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk decodes a run of handles into the wrapper and nulls the decoded value", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkRenderPassAttachmentBeginInfo::pAttachments, a run of VkImageView, divided as a single handle is: the
    // capture ids go to the wrapper's HandlePointerDecoder, and the API structure's pointer stays null because replay
    // maps the ids into the decoder's own handle storage. The ids are written with EncodeHandleIdArray, since
    // EncodeVulkanHandleArray goes through GetWrappedId and would encode handles this process never wrapped as null.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    const std::vector<format::HandleId> kViews = { 0x0000BEEFCAFE0011ull,
                                                   0x0000BEEFCAFE0012ull,
                                                   0x0000BEEFCAFE0013ull };

    auto* encoder = parameter_encoder.get();
    encoder->EncodeEnumValue(VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO);
    encode::EncodePNextStruct(encoder, nullptr);
    encoder->EncodeUInt32Value(static_cast<uint32_t>(kViews.size()));
    encoder->EncodeHandleIdArray(kViews.data(), kViews.size());

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkRenderPassAttachmentBeginInfo         walked_value{};
    Decoded_VkRenderPassAttachmentBeginInfo walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);
    CHECK(walked_value.sType == VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO);
    CHECK(walked_value.pNext == nullptr);
    CHECK(walked_value.attachmentCount == kViews.size());

    // The identities are in the wrapper, in order and at full length...
    REQUIRE(walked.pAttachments.GetPointer() != nullptr);
    CHECK(walked.pAttachments.GetLength() == kViews.size());
    for (size_t i = 0; i < kViews.size(); ++i)
    {
        CHECK(walked.pAttachments.GetPointer()[i] == kViews[i]);
    }

    // ...and the decoded value's pointer is null, not pointed at them.
    CHECK(walked_value.pAttachments == nullptr);

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk decodes a string and points the decoded value at it", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkDebugUtilsLabelEXT, a string beside a fixed-extent array. The string decodes into storage the
    // StringDecoder allocates, and the API structure points at it; color decodes straight into the API structure's own
    // array. One overload serves a single string and a run of them: StringDecoder, WStringDecoder and
    // StringArrayDecoder each read their own length and hand back storage, so only the wrapper's member type differs.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    const char* const kLabel   = "gfxrecon-schema-walk";
    const float       kColor[] = { 0.25f, 0.5f, 0.75f, 1.0f };

    auto* encoder = parameter_encoder.get();
    encoder->EncodeEnumValue(VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT);
    encode::EncodePNextStruct(encoder, nullptr);
    encoder->EncodeString(kLabel);
    encoder->EncodeFloatArray(kColor, 4);

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkDebugUtilsLabelEXT         walked_value{};
    Decoded_VkDebugUtilsLabelEXT walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);
    CHECK(walked_value.sType == VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT);
    CHECK(walked_value.pNext == nullptr);

    // The string round-tripped, and the decoded value points at the decoder's storage rather than a copy.
    REQUIRE(walked_value.pLabelName != nullptr);
    CHECK(std::string(walked_value.pLabelName) == kLabel);
    CHECK(walked_value.pLabelName == walked.pLabelName.GetPointer());

    // The fixed-extent array beside it decoded into the decoded value directly, as it has no storage of its own.
    CHECK(walked.color.GetPointer() == &walked_value.color[0]);
    for (size_t i = 0; i < 4; ++i)
    {
        CHECK(walked_value.color[i] == kColor[i]);
    }

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk decodes fixed-extent strings in place", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkLayerProperties: two fixed-extent strings of different extents, with scalars between them. They decode
    // into the API structure's own arrays, so nothing is assigned afterwards and the extents come from the API
    // declaration. The names are shorter than their arrays: the wire carries the string, not the array.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    const char* const  kLayer       = "VK_LAYER_LUNARG_gfxreconstruct";
    const char* const  kDescription = "GFXReconstruct capture layer";
    constexpr uint32_t kSpec        = VK_API_VERSION_1_3;
    constexpr uint32_t kImpl        = 42;

    auto* encoder = parameter_encoder.get();
    encoder->EncodeString(kLayer);
    encoder->EncodeUInt32Value(kSpec);
    encoder->EncodeUInt32Value(kImpl);
    encoder->EncodeString(kDescription);

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkLayerProperties         walked_value{};
    Decoded_VkLayerProperties walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);
    CHECK(walked_value.specVersion == kSpec);
    CHECK(walked_value.implementationVersion == kImpl);

    // Both strings landed in the decoded value's own arrays, not in storage the decoder allocated.
    CHECK(walked.layerName.GetPointer() == &walked_value.layerName[0]);
    CHECK(walked.description.GetPointer() == &walked_value.description[0]);

    CHECK(std::string(walked_value.layerName) == kLayer);
    CHECK(std::string(walked_value.description) == kDescription);

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A counted void pointer decodes as the bytes the capture kept", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkPipelineCacheCreateInfo::pInitialData, an Array<Const<Void>> with a byte count. It takes the void-run
    // overload: the bytes decode into the wrapper's PointerDecoder<uint8_t> through DecodeUInt8, and the API
    // structure's pointer points at them.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    // Not a printable string, and with a zero in the middle, so a read that stopped early would be visible.
    const std::vector<uint8_t> kBlob = { 0xDE, 0xAD, 0x00, 0xBE, 0xEF, 0x7F, 0x80, 0x01 };

    auto* encoder = parameter_encoder.get();
    encoder->EncodeEnumValue(VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO);
    encode::EncodePNextStruct(encoder, nullptr);
    encoder->EncodeFlagsValue(VkPipelineCacheCreateFlags{ 0 });
    encoder->EncodeSizeTValue(kBlob.size());
    encoder->EncodeVoidArray(kBlob.data(), kBlob.size());

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkPipelineCacheCreateInfo         walked_value{};
    Decoded_VkPipelineCacheCreateInfo walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);
    CHECK(walked_value.sType == VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO);
    CHECK(walked_value.pNext == nullptr);
    CHECK(walked_value.initialDataSize == kBlob.size());

    // The run landed in the wrapper at full length, and the decoded value points at it rather than a copy.
    REQUIRE(walked.pInitialData.GetPointer() != nullptr);
    CHECK(walked.pInitialData.GetLength() == kBlob.size());
    CHECK(walked_value.pInitialData == walked.pInitialData.GetPointer());

    const uint8_t* decoded_bytes = static_cast<const uint8_t*>(walked_value.pInitialData);
    for (size_t i = 0; i < kBlob.size(); ++i)
    {
        CHECK(decoded_bytes[i] == kBlob[i]);
    }

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("One overload takes a scalar pointer and a scalar run in the same structure", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkRenderingInputAttachmentIndexInfo: a uint32_t run takes the array Apply and two pointers to one
    // uint32_t take the pointer Apply, each in its last branch (SimpleApiElement): PointerDecoder reads its own
    // length from the wire, so one element is a run of one. VkBindMemoryStatus::pResult reaches the pointer Apply's
    // last branch with an enum.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    const std::vector<uint32_t> kIndices = { 3, 1, 4, 1, 5 };
    constexpr uint32_t          kDepth   = 7;
    constexpr uint32_t          kStencil = 9;

    auto* encoder = parameter_encoder.get();
    encoder->EncodeEnumValue(VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO);
    encode::EncodePNextStruct(encoder, nullptr);
    encoder->EncodeUInt32Value(static_cast<uint32_t>(kIndices.size()));
    encoder->EncodeUInt32Array(kIndices.data(), kIndices.size());
    encoder->EncodeUInt32Ptr(&kDepth);
    encoder->EncodeUInt32Ptr(&kStencil);

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkRenderingInputAttachmentIndexInfo         walked_value{};
    Decoded_VkRenderingInputAttachmentIndexInfo walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);
    CHECK(walked_value.sType == VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO);
    CHECK(walked_value.colorAttachmentCount == kIndices.size());

    // The run, at its own length.
    REQUIRE(walked_value.pColorAttachmentInputIndices != nullptr);
    CHECK(walked.pColorAttachmentInputIndices.GetLength() == kIndices.size());
    for (size_t i = 0; i < kIndices.size(); ++i)
    {
        CHECK(walked_value.pColorAttachmentInputIndices[i] == kIndices[i]);
    }

    // The single pointers, each a run of one through the same overload.
    REQUIRE(walked_value.pDepthInputAttachmentIndex != nullptr);
    REQUIRE(walked_value.pStencilInputAttachmentIndex != nullptr);
    CHECK(walked.pDepthInputAttachmentIndex.GetLength() == 1);
    CHECK(walked.pStencilInputAttachmentIndex.GetLength() == 1);
    CHECK(*walked_value.pDepthInputAttachmentIndex == kDepth);
    CHECK(*walked_value.pStencilInputAttachmentIndex == kStencil);

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk decodes a fixed-extent array of structures in place", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkImageBlit2's two VkOffset3D[2]. Each StructPointerDecoder is allocated as for any run of structures,
    // then pointed at the API structure's own array with SetExternalMemory, so nothing is assigned afterwards.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    VkImageSubresourceLayers src_layers{ VK_IMAGE_ASPECT_COLOR_BIT, 1, 2, 3 };
    VkImageSubresourceLayers dst_layers{ VK_IMAGE_ASPECT_DEPTH_BIT, 4, 5, 6 };
    const VkOffset3D         src_offsets[2] = { { 10, 11, 12 }, { 13, 14, 15 } };
    const VkOffset3D         dst_offsets[2] = { { 20, 21, 22 }, { 23, 24, 25 } };

    auto* encoder = parameter_encoder.get();
    encoder->EncodeEnumValue(VK_STRUCTURE_TYPE_IMAGE_BLIT_2);
    encode::EncodePNextStruct(encoder, nullptr);
    encode::EncodeStruct(encoder, src_layers);
    encode::EncodeStructArray(encoder, src_offsets, 2);
    encode::EncodeStruct(encoder, dst_layers);
    encode::EncodeStructArray(encoder, dst_offsets, 2);

    const uint8_t* encoded      = parameter_buffer->GetData();
    const size_t   encoded_size = parameter_buffer->GetDataSize();

    DecodeAllocator::Begin();

    VkImageBlit2         walked_value{};
    Decoded_VkImageBlit2 walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);
    CHECK(walked_value.sType == VK_STRUCTURE_TYPE_IMAGE_BLIT_2);
    CHECK(walked_value.pNext == nullptr);

    // Both runs decoded into the decoded value's own arrays rather than storage of the decoder's.
    REQUIRE(walked.srcOffsets != nullptr);
    REQUIRE(walked.dstOffsets != nullptr);
    CHECK(walked.srcOffsets->GetPointer() == &walked_value.srcOffsets[0]);
    CHECK(walked.dstOffsets->GetPointer() == &walked_value.dstOffsets[0]);

    // Each element descended through DecodeStruct, in order and to the right array.
    for (uint32_t i = 0; i < 2; ++i)
    {
        CHECK(walked_value.srcOffsets[i].x == src_offsets[i].x);
        CHECK(walked_value.srcOffsets[i].y == src_offsets[i].y);
        CHECK(walked_value.srcOffsets[i].z == src_offsets[i].z);
        CHECK(walked_value.dstOffsets[i].x == dst_offsets[i].x);
        CHECK(walked_value.dstOffsets[i].y == dst_offsets[i].y);
        CHECK(walked_value.dstOffsets[i].z == dst_offsets[i].z);
    }

    // The embedded structures between them decoded too.
    CHECK(walked_value.srcSubresource.mipLevel == src_layers.mipLevel);
    CHECK(walked_value.dstSubresource.layerCount == dst_layers.layerCount);

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk descends into an embedded structure", "[schema]")
{
    using namespace gfxrecon::decode;

    // Checks VkImageMemoryBarrier's embedded VkImageSubresourceRange. The embedded-structure overload allocates the
    // nested wrapper, links its decoded_value to the API structure's member, and descends through DecodeStruct, which
    // for VkImageSubresourceRange is a second field walk.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    constexpr format::HandleId   kImageId        = 0x0000FEEDFACE0002ull;
    constexpr VkAccessFlags      kSrcAccess      = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    constexpr VkAccessFlags      kDstAccess      = VK_ACCESS_SHADER_READ_BIT;
    constexpr VkImageLayout      kOldLayout      = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    constexpr VkImageLayout      kNewLayout      = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
    constexpr uint32_t           kSrcQueueFamily = 11;
    constexpr uint32_t           kDstQueueFamily = 13;
    constexpr VkImageAspectFlags kAspect         = VK_IMAGE_ASPECT_COLOR_BIT;
    constexpr uint32_t           kBaseMip        = 2;
    constexpr uint32_t           kLevels         = 3;
    constexpr uint32_t           kBaseLayer      = 4;
    constexpr uint32_t           kLayers         = 5;

    auto* encoder = parameter_encoder.get();
    encoder->EncodeEnumValue(VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER);
    encode::EncodePNextStruct(encoder, nullptr);
    encoder->EncodeFlagsValue(kSrcAccess);
    encoder->EncodeFlagsValue(kDstAccess);
    encoder->EncodeEnumValue(kOldLayout);
    encoder->EncodeEnumValue(kNewLayout);
    encoder->EncodeUInt32Value(kSrcQueueFamily);
    encoder->EncodeUInt32Value(kDstQueueFamily);
    encoder->EncodeHandleIdValue(kImageId);
    // The embedded structure is written inline, in its own schema order.
    encoder->EncodeFlagsValue(kAspect);
    encoder->EncodeUInt32Value(kBaseMip);
    encoder->EncodeUInt32Value(kLevels);
    encoder->EncodeUInt32Value(kBaseLayer);
    encoder->EncodeUInt32Value(kLayers);

    DecodeAllocator::Begin();

    VkImageMemoryBarrier         value{};
    Decoded_VkImageMemoryBarrier wrapper{};
    wrapper.decoded_value = &value;

    const size_t bytes_read = DecodeStruct(parameter_buffer->GetData(), parameter_buffer->GetDataSize(), &wrapper);

    CHECK(bytes_read == parameter_buffer->GetDataSize());

    CHECK(value.sType == VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER);
    CHECK(value.srcAccessMask == kSrcAccess);
    CHECK(value.dstAccessMask == kDstAccess);
    CHECK(value.oldLayout == kOldLayout);
    CHECK(value.newLayout == kNewLayout);
    CHECK(value.srcQueueFamilyIndex == kSrcQueueFamily);
    CHECK(value.dstQueueFamilyIndex == kDstQueueFamily);

    CHECK(wrapper.image == kImageId);
    CHECK(value.image == VK_NULL_HANDLE);

    // The embedded overload allocated a nested wrapper and pointed it at the inline API structure's member. That link
    // is what lets handle mapping and any later pass reach the nested decoded state.
    REQUIRE(wrapper.subresourceRange != nullptr);
    CHECK(wrapper.subresourceRange->decoded_value == &value.subresourceRange);

    // ...and the descent decoded it.
    CHECK(value.subresourceRange.aspectMask == kAspect);
    CHECK(value.subresourceRange.baseMipLevel == kBaseMip);
    CHECK(value.subresourceRange.levelCount == kLevels);
    CHECK(value.subresourceRange.baseArrayLayer == kBaseLayer);
    CHECK(value.subresourceRange.layerCount == kLayers);

    DecodeAllocator::End();
    util::Log::Release();
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
