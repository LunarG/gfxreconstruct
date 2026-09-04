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
#include "generated/generated_vulkan_decode_api_element_traits.h"

// The generated schema reaches no wire representation type, so the encoding join is included separately, the way an
// Encode or Decode adapter would include it.
#include "schema/encoding.h"

#include "decode/decode_allocator.h"
#include "decode/vulkan_decode_struct.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "util/logging.h"

#include "generated/generated_vulkan_schema_decoded_command_members.h"
#include "generated/generated_vulkan_schema_decoded_struct_members.h"
#include "generated/generated_vulkan_schema_native_struct_members.h"

#include <memory>
#include <type_traits>

namespace
{
using namespace gfxrecon;

using Command = schema::command::vulkan::CmdPipelineBarrier;

// A structure keys its schema on its API type descriptor, the same key ApiElementTraits uses.
using Barrier = schema::api_type::vulkan::VkBufferMemoryBarrier;

namespace cmd_field     = schema::field::vulkan::CmdPipelineBarrier;
namespace barrier_field = schema::field::vulkan::VkBufferMemoryBarrier;

// A command schema has exactly one return Field, and a structure schema has none.
static_assert(schema::HasSchema<Command>);
static_assert(schema::HasCommandSchema<Command>);
static_assert(schema::HasSchema<Barrier>);
static_assert(!schema::HasCommandSchema<Barrier>);

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

// A kind names the logical Encode and Decode operation for a registry type, and schema/encoding.h joins it to a wire
// representation.
static_assert(
    std::is_same_v<schema::ElementType<schema::api_type::vulkan::VkPipelineStageFlags>, VkPipelineStageFlags>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkPipelineStageFlags::kind, schema::field_kind::Flags>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkAccessFlags2::kind, schema::field_kind::Flags64>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkResult::kind, schema::field_kind::Enum>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkSampleMask::kind, schema::field_kind::SampleMask>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkDeviceSize::kind, schema::field_kind::DeviceSize>);

// Two registry names that share one C++ representation stay distinct, because the descriptor is the identity.
static_assert(std::is_same_v<VkAccessFlags2, VkPipelineStageFlags2>);
static_assert(
    !std::is_same_v<schema::api_type::vulkan::VkAccessFlags2, schema::api_type::vulkan::VkPipelineStageFlags2>);

// A kind is specific, so each one maps to the ParameterEncoder and ValueDecoder function that already exists for
// it. That restates part of what element_type says, and the generator checks the agreement in the one loop that
// assigns both.
static_assert(std::is_same_v<schema::api_type::vulkan::UInt32::kind, schema::field_kind::UInt32>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkBool32::kind, schema::field_kind::UInt32>);
static_assert(std::is_same_v<schema::ElementType<schema::api_type::vulkan::UInt32>, uint32_t>);
static_assert(schema::ScalarField<barrier_field::srcQueueFamilyIndex>);

// Every scalar kind still selects the shared scalar access pattern.
static_assert(schema::ScalarField<barrier_field::srcAccessMask>);
static_assert(schema::ScalarField<barrier_field::offset>);
static_assert(schema::ScalarField<barrier_field::sType>);

// The wire representation is reached through the encoding join, never through the descriptor.
static_assert(std::is_same_v<schema::EncodedTypeFor<barrier_field::srcAccessMask>, format::FlagsEncodeType>);
static_assert(std::is_same_v<schema::EncodedTypeFor<barrier_field::sType>, format::EnumEncodeType>);
static_assert(std::is_same_v<schema::EncodedTypeFor<barrier_field::offset>, format::DeviceSizeEncodeType>);
static_assert(std::is_same_v<schema::EncodedTypeFor<barrier_field::srcQueueFamilyIndex>, uint32_t>);
static_assert(std::is_same_v<schema::EncodedTypeFor<barrier_field::buffer>, format::HandleEncodeType>);

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
static_assert(schema::StoresElementField<VkBufferMemoryBarrier, barrier_field::buffer>);

// A scalar that decode leaves in the wrapped native structure has no decoded-wrapper mapping.
static_assert(schema::HasMember<VkBufferMemoryBarrier, barrier_field::srcAccessMask>);
static_assert(!schema::HasMember<decode::Decoded_VkBufferMemoryBarrier, barrier_field::srcAccessMask>);

// A field the API declares as a plain integer but GFXReconstruct maps as a handle names one shared descriptor and
// its runtime selector, because no type-level fact can express it.
namespace debug_field = schema::field::vulkan::VkDebugUtilsObjectNameInfoEXT;
static_assert(std::is_same_v<debug_field::objectHandle::api_type, schema::api_type::vulkan::GenericHandle>);
static_assert(std::is_same_v<debug_field::objectHandle::selector_field, debug_field::objectType>);
static_assert(schema::HandleField<debug_field::objectHandle>);

// A bitfield member keeps a mapping, but it is not addressable, so GetRef drops out of the overload set.
static_assert(schema::HasMember<VkAccelerationStructureInstanceKHR,
                                schema::field::vulkan::VkAccelerationStructureInstanceKHR::mask>);
static_assert(schema::NonAddressable<VkAccelerationStructureInstanceKHR,
                                     schema::field::vulkan::VkAccelerationStructureInstanceKHR::mask>);

// Decoded representation resolves through the traits key, which is the same key the schema uses.
static_assert(std::is_same_v<decode::Decoded<Barrier>, decode::Decoded_VkBufferMemoryBarrier>);
static_assert(std::is_same_v<decode::Decoded<Command>, decode::args::CmdPipelineBarrier>);
static_assert(decode::ApiElementTraits<Command>::call_id == format::ApiCallId::ApiCall_vkCmdPipelineBarrier);

// One walk visits the whole field list, and one Action supplies the Apply overloads that its shapes select.
struct CountingAction
{
    size_t handles = 0;
    size_t scalars = 0;
    size_t others  = 0;

    template <typename Field, typename Storage>
    requires schema::HandleField<Field>
    void Apply(Field, Storage&) { ++handles; }

    template <typename Field, typename Storage>
    requires schema::ScalarField<Field>
    void Apply(Field, Storage&) { ++scalars; }

    template <typename Field, typename Storage>
    requires(!schema::HandleField<Field> && !schema::ScalarField<Field>) void Apply(Field, Storage&) { ++others; }
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

    schema::WalkFields<Barrier>(action, barrier);

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

TEST_CASE("The generated DecodeStruct for VkBufferMemoryBarrier is a schema field walk", "[schema]")
{
    using namespace gfxrecon::decode;

    // VkBufferMemoryBarrier is in SCHEMA_OWNED_STRUCT_DECODERS, so the struct-decoders generator emits no
    // procedural body for it and DecodeStruct is the field walk. Nothing below names a field of the structure: the
    // schema orders them and the hand-written Action decides what each one means.
    //
    // Equivalence with the procedural body was checked field for field before the swap, by decoding the same buffer
    // both ways. That comparison is no longer available once the procedural body is gone, so what remains is the
    // round trip against the values written below, which is independent of either implementation.
    util::Log::Init(util::LoggingSeverity::kError);

    auto parameter_buffer  = std::make_unique<encode::ParameterBuffer>();
    auto parameter_encoder = std::make_unique<encode::ParameterEncoder>(parameter_buffer.get());

    // The wire layout is written from the encoder primitives rather than from EncodeStruct, for one reason: a handle
    // encodes through GetWrappedId, so a handle the capture layer never wrapped would record as a null identity and
    // the handle path would not be exercised with a real value. The call order below is the generated encoder's,
    // which is the canonical field order the schema also carries.
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

    // This is the ordinary decode entry point. Its body is DecodeStructByWalk<VkBufferMemoryBarrier>.
    VkBufferMemoryBarrier         walked_value{};
    Decoded_VkBufferMemoryBarrier walked{};
    walked.decoded_value     = &walked_value;
    const size_t walked_read = DecodeStruct(encoded, encoded_size, &walked);

    CHECK(walked_read == encoded_size);

    // ...and round-trips the value that was written, in the right order and at the right width. A field read out of
    // order or at the wrong width would land in a neighbour, so these also pin the canonical field order.
    CHECK(walked_value.sType == VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER);
    CHECK(walked_value.srcAccessMask == kSrcAccess);
    CHECK(walked_value.dstAccessMask == kDstAccess);
    CHECK(walked_value.srcQueueFamilyIndex == kSrcQueueFamily);
    CHECK(walked_value.dstQueueFamilyIndex == kDstQueueFamily);
    CHECK(walked_value.offset == kOffset);
    CHECK(walked_value.size == kSize);

    // The handle lands in the wrapper as a capture-file identity, and the native handle is left for replay to map.
    CHECK(walked.buffer == kBufferId);
    CHECK(walked_value.buffer == VK_NULL_HANDLE);

    // The extension chain took the chain overload.
    CHECK(walked.pNext == nullptr);
    CHECK(walked_value.pNext == nullptr);

    DecodeAllocator::End();
    util::Log::Release();
}

TEST_CASE("A field walk descends into an embedded structure", "[schema]")
{
    using namespace gfxrecon::decode;

    // VkImageMemoryBarrier adds one field the previous structure did not have: an embedded VkImageSubresourceRange.
    // That field needs the fourth Apply overload, which allocates the nested decoded wrapper, links it to the inline
    // native member, and descends through DecodeStruct. VkImageSubresourceRange is itself schema-owned here, so the
    // descent lands in a second field walk -- but the outer Action neither knows nor cares about that.
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

    // The embedded overload allocated a nested wrapper and pointed it at the inline native member. That link is what
    // lets handle mapping and any later pass reach the nested decoded state.
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
