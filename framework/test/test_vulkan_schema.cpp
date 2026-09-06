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

#include "decode/decode_allocator.h"
#include "decode/vulkan_decode_struct.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "encode/struct_pointer_encoder.h"
#include "util/logging.h"

#include "generated/generated_vulkan_schema_decoded_command_members.h"
#include "generated/generated_vulkan_schema_decoded_struct_members.h"
#include "generated/generated_vulkan_schema_native_struct_members.h"

#include <memory>
#include <string>
#include <vector>
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

// A kind names the logical Encode and Decode operation for a registry type, and carries the wire
// representation.
static_assert(
    std::is_same_v<schema::ElementType<schema::api_type::vulkan::VkPipelineStageFlags>, VkPipelineStageFlags>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkPipelineStageFlags::kind, format::kind::Flags>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkAccessFlags2::kind, format::kind::Flags64>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkResult::kind, format::kind::Enum>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkSampleMask::kind, format::kind::SampleMask>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkDeviceSize::kind, format::kind::DeviceSize>);

// Two registry names that share one C++ representation stay distinct, because the descriptor is the identity.
static_assert(std::is_same_v<VkAccessFlags2, VkPipelineStageFlags2>);
static_assert(
    !std::is_same_v<schema::api_type::vulkan::VkAccessFlags2, schema::api_type::vulkan::VkPipelineStageFlags2>);

// A kind is specific, so each one maps to the ParameterEncoder and ValueDecoder function that already exists for
// it. That restates part of what element_type says, and the generator checks the agreement in the one loop that
// assigns both.
static_assert(std::is_same_v<schema::api_type::vulkan::UInt32::kind, format::kind::UInt32>);
static_assert(std::is_same_v<schema::api_type::vulkan::VkBool32::kind, format::kind::UInt32>);
static_assert(std::is_same_v<schema::ElementType<schema::api_type::vulkan::UInt32>, uint32_t>);
static_assert(schema::ScalarField<barrier_field::srcQueueFamilyIndex>);

// Every scalar kind still selects the shared scalar access pattern.
static_assert(schema::ScalarField<barrier_field::srcAccessMask>);
static_assert(schema::ScalarField<barrier_field::offset>);
static_assert(schema::ScalarField<barrier_field::sType>);

// The wire representation is reached through the encoding join, never through the descriptor.
static_assert(std::is_same_v<schema::FieldEncodeType<barrier_field::srcAccessMask>, format::FlagsEncodeType>);
static_assert(std::is_same_v<schema::FieldEncodeType<barrier_field::sType>, format::EnumEncodeType>);
static_assert(std::is_same_v<schema::FieldEncodeType<barrier_field::offset>, format::DeviceSizeEncodeType>);
static_assert(std::is_same_v<schema::FieldEncodeType<barrier_field::srcQueueFamilyIndex>, uint32_t>);
static_assert(std::is_same_v<schema::FieldEncodeType<barrier_field::buffer>, format::HandleEncodeType>);

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

TEST_CASE("A field walk decodes a scalar array into the wrapper and points the native member at it", "[schema]")
{
    using namespace gfxrecon::decode;

    // VkShaderModuleCreateInfo is the smallest migrated structure carrying a PointerArray of scalars. Its pCode is
    // the case the scalar-array overload exists for: the run decodes into the wrapper's PointerDecoder and the
    // native pointer follows it, the same shape the extension chain already had.
    //
    // codeSize is the sibling count field, and the walk never reads it. It is decoded as its own scalar in its own
    // position, and the array's length travels with the array on the wire, so the two are independent on purpose --
    // a walk that consulted the count would have to know which field it was.
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

    // ...the native member points at that same storage rather than a copy...
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

    // VkSparseBufferMemoryBindInfo is the smallest migrated structure carrying a PointerArray of structures, and it
    // has no sType and no pNext, which is worth having: the walk makes no assumption that a structure is
    // extensible, and this is the first migrated one that is not.
    //
    // Its element type, VkSparseMemoryBind, is not migrated. So each element descends through the procedural
    // DecodeStruct, which is the point of calling this legacy descent: an array of a structure the field walk does
    // not own still decodes, and the two implementations meet at the ordinary entry point.
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

    // Each element descended through the procedural decoder for VkSparseMemoryBind, in order.
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

    // VkTransformMatrixKHR is one field, float matrix[3][4], and it is the case the schema cannot describe: for a
    // multidimensional array the generator records array_dimension and a comma-joined length expression, which is
    // a string, and no extent value at all. The overload takes both extents from std::extent_v on the API member's
    // declared type instead, which the member trait already names, so the one and two dimensional cases need no
    // separate treatment.
    //
    // This is also the only shape so far that writes nothing to the decoded value at the end. The decoder is
    // pointed at the decoded value's own storage, so decoding fills the native array directly.
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

    // VkDeviceBufferMemoryRequirements carries a pointer to one VkBufferCreateInfo. No overload was added for it:
    // StructPointerDecoder reads its own length from the wire, so one structure is a run of one and the body is the
    // array case unchanged. Only the constraint widened, from PointerArrayField to either pointer shape.
    //
    // The element is a large extensible structure that is not migrated, so this descends into the procedural
    // decoder for something substantial rather than a leaf -- including that element's own pNext.
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

    // The procedural decoder for the element ran, all the way through its own trailing fields.
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

    // StdVideoAV1TileInfoFlags is uniform_tile_spacing_flag : 1 and reserved : 31. Neither member has an address --
    // C++ [class.bit]/3 forbids both &member and binding a non-const reference to one -- so the member trait holds
    // generated Get and Set accessors in place of a pointer-to-member, and the walk writes through Set.
    //
    // Each bitfield is recorded as a whole uint32 on the wire, so a one-bit flag costs four bytes. The values below
    // are chosen to prove that: 8 bytes for two fields, and reserved carries a value wider than one bit.
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

    // VkCheckpointData2NV::pCheckpointMarker is a void pointer to something outside the API. The capture recorded
    // whatever address the application held, which means nothing in this process, so it lands in the wrapper as a
    // value and the decoded value's pointer is left null for replay to resolve through PreProcessExternalObject --
    // the same division a handle gets.
    //
    // Its descriptor is api_type::vulkan::ExternalObject, whose kind is Address, so the schema states the wire
    // form and the overload reads it from the kind like every other. The descriptor exists because the declared
    // type cannot state it: this is void*, and so is a counted run of bytes, and so is pNext.
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

    // VkAllocationCallbacks is the densest address case: one pointer to something outside the API, and five
    // function pointers. The first names the ExternalObject descriptor and the rest name their own PFN_* ones,
    // but every field has kind Address, so one overload takes all six and the schema needed no special case for
    // the function pointers.
    //
    // It also has no sType and no pNext.
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

    // VkRenderPassAttachmentBeginInfo::pAttachments is a run of VkImageView. It gets the same division a single
    // handle gets: the capture-file identities land in the wrapper's HandlePointerDecoder and the decoded value's
    // pointer stays null, because replay maps the identities to handles of its own run.
    //
    // The identities are written with EncodeHandleIdArray rather than EncodeVulkanHandleArray, for the reason the
    // single-handle test gives: the latter goes through GetWrappedId, so handles this process never wrapped would
    // record as null and the path would not be exercised with real values.
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

    // VkDebugUtilsLabelEXT is a string beside a fixed-extent array, so it exercises the two shapes that both
    // decode in place of the API's own storage but resolve it differently: the string allocates and the decoded
    // value points at what it allocated, while color decodes straight into the decoded value's own array.
    //
    // One overload serves a single string and a run of them. StringDecoder, WStringDecoder and StringArrayDecoder
    // all read their own length and hand back storage, so only the wrapper's member type differs, and the kind
    // picks that rather than picking a call.
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

    // VkLayerProperties carries two fixed-extent strings of different extents, with scalars between them. Like any
    // fixed-extent array they decode into the decoded value's own storage rather than into storage of the
    // decoder's, so nothing is assigned afterwards and the extents come from the API declaration.
    //
    // The names are shorter than their arrays, which is the case worth pinning: the wire carries the string, not
    // the array, so the two fields are not the same size on the wire even though both arrays are fixed.
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

    // VkPipelineCacheCreateInfo::pInitialData is declared const void* with a byte count. No overload was added for
    // it: the capture stores it as bytes, so the descriptor names uint8_t and the scalar-run overload takes it
    // unchanged. void names no element, and the wrapper had already settled the question by declaring
    // PointerDecoder<uint8_t>.
    //
    // With this the Void descriptor is left with only the two uses where void really means no value: the extension
    // chain and a void command's return.
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
