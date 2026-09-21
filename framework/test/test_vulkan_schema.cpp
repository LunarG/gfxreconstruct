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
#include "decode/vulkan_decode_struct_impl.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "encode/vulkan_encode_capture_wrappers.h"
#include "encode/vulkan_encode_struct.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/struct_pointer_encoder.h"
#include "util/logging.h"

#include "generated/generated_vulkan_schema_decoded_command_members.h"
#include "generated/generated_vulkan_schema_decoded_struct_members.h"
#include "generated/generated_vulkan_schema_native_struct_members.h"

#include <cstring>
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

// A void command still carries one Return Field, shaped VoidReturn, and its ReturnType is void.
static_assert(std::is_same_v<schema::Return<Command>, cmd_field::result>);
static_assert(std::is_same_v<schema::ReturnType<Command>, void>);
static_assert(schema::VoidReturnField<cmd_field::result>);

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
static_assert(schema::StructKindField<cmd_field::pBufferMemoryBarriers>);
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

TEST_CASE("Schema EncodeStruct matches scalar-value wire bytes", "[schema][encode]")
{
    // Migration candidate: its concrete public overload bridges to the generic EncodeStruct field walk.
    VkExtent2D migrated{ 0x12345678u, 0x90abcdefu };

    encode::ParameterBuffer  migrated_buffer;
    encode::ParameterEncoder migrated_encoder(&migrated_buffer);
    encode::EncodeStruct(&migrated_encoder, migrated);

    encode::ParameterBuffer  migrated_oracle_buffer;
    encode::ParameterEncoder migrated_oracle(&migrated_oracle_buffer);
    migrated_oracle.EncodeUInt32Value(migrated.width);
    migrated_oracle.EncodeUInt32Value(migrated.height);

    REQUIRE(migrated_buffer.GetDataSize() == migrated_oracle_buffer.GetDataSize());
    CHECK(std::memcmp(migrated_buffer.GetData(), migrated_oracle_buffer.GetData(), migrated_buffer.GetDataSize()) == 0);

    // Comparison candidate: its generated procedural body remains unchanged and exercises the same UInt32/value
    // idiom once more. A separate primitive oracle makes the comparison independent of either implementation.
    VkExtent3D comparison{ 0x10203040u, 0x50607080u, 0x90a0b0c0u };

    encode::ParameterBuffer  comparison_buffer;
    encode::ParameterEncoder comparison_encoder(&comparison_buffer);
    encode::EncodeStruct(&comparison_encoder, comparison);

    encode::ParameterBuffer  comparison_oracle_buffer;
    encode::ParameterEncoder comparison_oracle(&comparison_oracle_buffer);
    comparison_oracle.EncodeUInt32Value(comparison.width);
    comparison_oracle.EncodeUInt32Value(comparison.height);
    comparison_oracle.EncodeUInt32Value(comparison.depth);

    REQUIRE(comparison_buffer.GetDataSize() == comparison_oracle_buffer.GetDataSize());
    CHECK(std::memcmp(
              comparison_buffer.GetData(), comparison_oracle_buffer.GetData(), comparison_buffer.GetDataSize()) == 0);
}

TEST_CASE("Schema EncodeStruct matches fixed-extent array wire bytes", "[schema][encode]")
{
    // Two migrated structures, one per rank, against primitive oracles; two retained partners exercise the same
    // idiom through their procedural bodies. Values are asymmetric so a transposed, truncated or reordered run lands
    // on different bytes.
    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    // Rank one, migrated: four scalars, one of them an enum, then a byte array of VK_UUID_SIZE.
    VkPipelineCacheHeaderVersionOne header{};
    header.headerSize    = 0x00000020u;
    header.headerVersion = VK_PIPELINE_CACHE_HEADER_VERSION_ONE;
    header.vendorID      = 0x000010deu;
    header.deviceID      = 0x00002684u;
    for (size_t i = 0; i < VK_UUID_SIZE; ++i)
    {
        header.pipelineCacheUUID[i] = static_cast<uint8_t>(0xa0 + i);
    }

    encode::ParameterBuffer  header_buffer;
    encode::ParameterEncoder header_encoder(&header_buffer);
    encode::EncodeStruct(&header_encoder, header);

    encode::ParameterBuffer  header_oracle_buffer;
    encode::ParameterEncoder header_oracle(&header_oracle_buffer);
    header_oracle.EncodeUInt32Value(header.headerSize);
    header_oracle.EncodeEnumValue(header.headerVersion);
    header_oracle.EncodeUInt32Value(header.vendorID);
    header_oracle.EncodeUInt32Value(header.deviceID);
    header_oracle.EncodeUInt8Array(header.pipelineCacheUUID, VK_UUID_SIZE);

    CHECK(same_bytes(header_buffer, header_oracle_buffer));

    // Rank two, migrated: a 3x4 float matrix and nothing else. The oracle is the 2DMatrix entry point, so this also
    // pins that a matrix is one flat run of the extent product.
    VkTransformMatrixKHR matrix{};
    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t column = 0; column < 4; ++column)
        {
            matrix.matrix[row][column] = static_cast<float>(row * 10 + column) + 0.5f;
        }
    }

    encode::ParameterBuffer  matrix_buffer;
    encode::ParameterEncoder matrix_encoder(&matrix_buffer);
    encode::EncodeStruct(&matrix_encoder, matrix);

    encode::ParameterBuffer  matrix_oracle_buffer;
    encode::ParameterEncoder matrix_oracle(&matrix_oracle_buffer);
    matrix_oracle.EncodeFloat2DMatrix(matrix.matrix, 3, 4);

    CHECK(same_bytes(matrix_buffer, matrix_oracle_buffer));

    // Rank one, retained partner: the same header shape with a uint32_t array.
    VkPipelineCacheHeaderVersionDataGraphQCOM graph_header{};
    graph_header.headerSize    = 0x00000030u;
    graph_header.headerVersion = VK_PIPELINE_CACHE_HEADER_VERSION_ONE;
    graph_header.cacheVersion  = 0x00000007u;
    for (size_t i = 0; i < VK_DATA_GRAPH_MODEL_TOOLCHAIN_VERSION_LENGTH_QCOM; ++i)
    {
        graph_header.toolchainVersion[i] = static_cast<uint32_t>(0x01000000u * (i + 1) + i);
    }

    encode::ParameterBuffer  graph_buffer;
    encode::ParameterEncoder graph_encoder(&graph_buffer);
    encode::EncodeStruct(&graph_encoder, graph_header);

    encode::ParameterBuffer  graph_oracle_buffer;
    encode::ParameterEncoder graph_oracle(&graph_oracle_buffer);
    graph_oracle.EncodeUInt32Value(graph_header.headerSize);
    graph_oracle.EncodeEnumValue(graph_header.headerVersion);
    graph_oracle.EncodeEnumValue(graph_header.cacheType);
    graph_oracle.EncodeUInt32Value(graph_header.cacheVersion);
    graph_oracle.EncodeUInt32Array(graph_header.toolchainVersion, VK_DATA_GRAPH_MODEL_TOOLCHAIN_VERSION_LENGTH_QCOM);

    CHECK(same_bytes(graph_buffer, graph_oracle_buffer));

    // Rank two, retained partner: two scalars and two byte matrices.
    StdVideoH264ScalingLists lists{};
    lists.scaling_list_present_mask       = 0x0123u;
    lists.use_default_scaling_matrix_mask = 0x4567u;
    for (size_t list = 0; list < STD_VIDEO_H264_SCALING_LIST_4X4_NUM_LISTS; ++list)
    {
        for (size_t element = 0; element < STD_VIDEO_H264_SCALING_LIST_4X4_NUM_ELEMENTS; ++element)
        {
            lists.ScalingList4x4[list][element] = static_cast<uint8_t>(list * 16 + element);
        }
        for (size_t element = 0; element < STD_VIDEO_H264_SCALING_LIST_8X8_NUM_ELEMENTS; ++element)
        {
            lists.ScalingList8x8[list][element] = static_cast<uint8_t>(0x80 + list * 64 + element);
        }
    }

    encode::ParameterBuffer  lists_buffer;
    encode::ParameterEncoder lists_encoder(&lists_buffer);
    encode::EncodeStruct(&lists_encoder, lists);

    encode::ParameterBuffer  lists_oracle_buffer;
    encode::ParameterEncoder lists_oracle(&lists_oracle_buffer);
    lists_oracle.EncodeUInt16Value(lists.scaling_list_present_mask);
    lists_oracle.EncodeUInt16Value(lists.use_default_scaling_matrix_mask);
    lists_oracle.EncodeUInt82DMatrix(
        lists.ScalingList4x4, STD_VIDEO_H264_SCALING_LIST_4X4_NUM_LISTS, STD_VIDEO_H264_SCALING_LIST_4X4_NUM_ELEMENTS);
    lists_oracle.EncodeUInt82DMatrix(
        lists.ScalingList8x8, STD_VIDEO_H264_SCALING_LIST_8X8_NUM_LISTS, STD_VIDEO_H264_SCALING_LIST_8X8_NUM_ELEMENTS);

    CHECK(same_bytes(lists_buffer, lists_oracle_buffer));
}

TEST_CASE("Schema EncodeStruct matches extension-chain wire bytes", "[schema][encode]")
{
    // Two migrated structures that are sType and pNext and nothing else, one per pNext policy, so the comparison
    // isolates the choice the Field's has_extensions makes; two retained partners exercise each policy through their
    // procedural bodies. Each is encoded with a null chain and with a one-node chain, against an oracle that calls
    // the same pNext entry point the procedural body did.
    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    auto encode_via_schema = [](const auto& value, encode::ParameterBuffer& buffer) {
        encode::ParameterEncoder encoder(&buffer);
        encode::EncodeStruct(&encoder, value);
    };

    // One registered extension of VkSubpassEndInfo, and the one registered extension of VkAttachmentReference2. The
    // two probed partners take the stencil-layout node as well: the walk resolves a node by its sType alone and
    // never asks whether the registry allows it on this owner, so any recognized node shows the probe followed the
    // pointer.
    VkRenderPassFragmentDensityMapOffsetEndInfoEXT offsets{};
    offsets.sType = VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT;

    VkAttachmentReferenceStencilLayout stencil{};
    stencil.sType         = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT;
    stencil.stencilLayout = VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL;

    // Migrated, has_extensions: the chain is walked trusting the pointer.
    for (const void* chain : { static_cast<const void*>(nullptr), static_cast<const void*>(&offsets) })
    {
        VkSubpassEndInfo end{ VK_STRUCTURE_TYPE_SUBPASS_END_INFO, chain };

        encode::ParameterBuffer end_buffer;
        encode_via_schema(end, end_buffer);

        encode::ParameterBuffer  end_oracle_buffer;
        encode::ParameterEncoder end_oracle(&end_oracle_buffer);
        end_oracle.EncodeEnumValue(end.sType);
        encode::EncodePNextStruct(&end_oracle, end.pNext);

        CHECK(same_bytes(end_buffer, end_oracle_buffer));
    }

    // Migrated, no registered extensions: the pointer is probed before the chain is walked. The registry has
    // nothing declared for VkPipelineCreateInfoKHR, though the spec text requires a pipeline create-info node here,
    // so this is also the case where the registry fact and the spec's prose disagree and the probe covers the gap.
    for (void* chain : { static_cast<void*>(nullptr), static_cast<void*>(&stencil) })
    {
        VkPipelineCreateInfoKHR create{ VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR, chain };

        encode::ParameterBuffer create_buffer;
        encode_via_schema(create, create_buffer);

        encode::ParameterBuffer  create_oracle_buffer;
        encode::ParameterEncoder create_oracle(&create_oracle_buffer);
        create_oracle.EncodeEnumValue(create.sType);
        encode::EncodePNextStructIfValid(&create_oracle, create.pNext);

        CHECK(same_bytes(create_buffer, create_oracle_buffer));
    }

    // Retained partner, has_extensions, with three scalars after the chain so the chain's length on the wire is
    // seen to leave the fields behind it in place.
    for (const void* chain : { static_cast<const void*>(nullptr), static_cast<const void*>(&stencil) })
    {
        VkAttachmentReference2 reference{ VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2,
                                          chain,
                                          7u,
                                          VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
                                          VK_IMAGE_ASPECT_COLOR_BIT };

        encode::ParameterBuffer reference_buffer;
        encode_via_schema(reference, reference_buffer);

        encode::ParameterBuffer  reference_oracle_buffer;
        encode::ParameterEncoder reference_oracle(&reference_oracle_buffer);
        reference_oracle.EncodeEnumValue(reference.sType);
        encode::EncodePNextStruct(&reference_oracle, reference.pNext);
        reference_oracle.EncodeUInt32Value(reference.attachment);
        reference_oracle.EncodeEnumValue(reference.layout);
        reference_oracle.EncodeFlagsValue(reference.aspectMask);

        CHECK(same_bytes(reference_buffer, reference_oracle_buffer));
    }

    // Retained partner, no registered extensions.
    for (const void* chain : { static_cast<const void*>(nullptr), static_cast<const void*>(&stencil) })
    {
        VkPerTileBeginInfoQCOM begin{ VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM, chain };

        encode::ParameterBuffer begin_buffer;
        encode_via_schema(begin, begin_buffer);

        encode::ParameterBuffer  begin_oracle_buffer;
        encode::ParameterEncoder begin_oracle(&begin_oracle_buffer);
        begin_oracle.EncodeEnumValue(begin.sType);
        encode::EncodePNextStructIfValid(&begin_oracle, begin.pNext);

        CHECK(same_bytes(begin_buffer, begin_oracle_buffer));
    }
}

TEST_CASE("Schema EncodeStruct matches scalar-pointer wire bytes", "[schema][encode]")
{
    // One migrated structure whose only field beyond sType and pNext is a pointer to one scalar, encoded with the
    // pointer null and with it set; one retained partner takes the same entry point twice through its procedural
    // body, one pointer down each path. The value behind the pointer is a negative enum so a sign or width slip
    // lands on different bytes.
    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    VkResult result = VK_ERROR_OUT_OF_HOST_MEMORY;

    for (VkResult* pointer : { static_cast<VkResult*>(nullptr), &result })
    {
        VkBindMemoryStatus status{ VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS, nullptr, pointer };

        encode::ParameterBuffer  status_buffer;
        encode::ParameterEncoder status_encoder(&status_buffer);
        encode::EncodeStruct(&status_encoder, status);

        encode::ParameterBuffer  status_oracle_buffer;
        encode::ParameterEncoder status_oracle(&status_oracle_buffer);
        status_oracle.EncodeEnumValue(status.sType);
        encode::EncodePNextStruct(&status_oracle, status.pNext);
        status_oracle.EncodeEnumPtr(status.pResult);

        CHECK(same_bytes(status_buffer, status_oracle_buffer));
    }

    // Retained partner: a counted run keeps it on its procedural body, and its two scalar pointers go one each way.
    uint32_t depth_index = 0x0badf00du;

    VkRenderingInputAttachmentIndexInfo indices{
        VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO, nullptr, 0u, nullptr, &depth_index, nullptr
    };

    encode::ParameterBuffer  indices_buffer;
    encode::ParameterEncoder indices_encoder(&indices_buffer);
    encode::EncodeStruct(&indices_encoder, indices);

    encode::ParameterBuffer  indices_oracle_buffer;
    encode::ParameterEncoder indices_oracle(&indices_oracle_buffer);
    indices_oracle.EncodeEnumValue(indices.sType);
    encode::EncodePNextStruct(&indices_oracle, indices.pNext);
    indices_oracle.EncodeUInt32Value(indices.colorAttachmentCount);
    indices_oracle.EncodeUInt32Array(indices.pColorAttachmentInputIndices, indices.colorAttachmentCount);
    indices_oracle.EncodeUInt32Ptr(indices.pDepthInputAttachmentIndex);
    indices_oracle.EncodeUInt32Ptr(indices.pStencilInputAttachmentIndex);

    CHECK(same_bytes(indices_buffer, indices_oracle_buffer));
}

TEST_CASE("Schema EncodeStruct matches counted scalar run wire bytes", "[schema][encode]")
{
    // One migrated structure whose run is a counted byte run, OpaqueBytes with a size_t count, encoded with the run
    // null and empty and with it populated; its retained twin takes the same entry point through its procedural
    // body. The count is read from the sibling Field, the first cross-field read in either Action, so the populated
    // case uses an odd length that no default or extent could supply.
    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    const uint8_t bytes[] = { 0xde, 0xad, 0xbe, 0xef, 0x01, 0x02, 0x03 };

    struct Run
    {
        const void* data;
        size_t      size;
    };

    for (const Run& run : { Run{ nullptr, 0 }, Run{ bytes, sizeof(bytes) } })
    {
        VkPipelineCacheCreateInfo cache{ VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO,
                                         nullptr,
                                         VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT,
                                         run.size,
                                         run.data };

        encode::ParameterBuffer  cache_buffer;
        encode::ParameterEncoder cache_encoder(&cache_buffer);
        encode::EncodeStruct(&cache_encoder, cache);

        encode::ParameterBuffer  cache_oracle_buffer;
        encode::ParameterEncoder cache_oracle(&cache_oracle_buffer);
        cache_oracle.EncodeEnumValue(cache.sType);
        encode::EncodePNextStructIfValid(&cache_oracle, cache.pNext);
        cache_oracle.EncodeFlagsValue(cache.flags);
        cache_oracle.EncodeSizeTValue(cache.initialDataSize);
        cache_oracle.EncodeVoidArray(cache.pInitialData, cache.initialDataSize);

        CHECK(same_bytes(cache_buffer, cache_oracle_buffer));

        // Retained twin: the same five fields under another sType, through its procedural body.
        VkValidationCacheCreateInfoEXT validation{
            VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT, nullptr, 0u, run.size, run.data
        };

        encode::ParameterBuffer  validation_buffer;
        encode::ParameterEncoder validation_encoder(&validation_buffer);
        encode::EncodeStruct(&validation_encoder, validation);

        encode::ParameterBuffer  validation_oracle_buffer;
        encode::ParameterEncoder validation_oracle(&validation_oracle_buffer);
        validation_oracle.EncodeEnumValue(validation.sType);
        encode::EncodePNextStructIfValid(&validation_oracle, validation.pNext);
        validation_oracle.EncodeFlagsValue(validation.flags);
        validation_oracle.EncodeSizeTValue(validation.initialDataSize);
        validation_oracle.EncodeVoidArray(validation.pInitialData, validation.initialDataSize);

        CHECK(same_bytes(validation_buffer, validation_oracle_buffer));
    }

    // Migrated, a typed run: uint32_t elements under a uint32_t count, so the element pointer casts to itself and
    // the run goes through the same converting body the UInt32Array entry point uses. Exclusive sharing with no
    // indices, then concurrent sharing with three.
    const uint32_t families[] = { 0u, 2u, 5u };

    struct Sharing
    {
        VkSharingMode   mode;
        uint32_t        count;
        const uint32_t* indices;
    };

    for (const Sharing& sharing :
         { Sharing{ VK_SHARING_MODE_EXCLUSIVE, 0u, nullptr }, Sharing{ VK_SHARING_MODE_CONCURRENT, 3u, families } })
    {
        VkBufferCreateInfo buffer{ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
                                   nullptr,
                                   VK_BUFFER_CREATE_SPARSE_BINDING_BIT,
                                   0x0000000123456789ull,
                                   VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
                                   sharing.mode,
                                   sharing.count,
                                   sharing.indices };

        encode::ParameterBuffer  buffer_buffer;
        encode::ParameterEncoder buffer_encoder(&buffer_buffer);
        encode::EncodeStruct(&buffer_encoder, buffer);

        encode::ParameterBuffer  buffer_oracle_buffer;
        encode::ParameterEncoder buffer_oracle(&buffer_oracle_buffer);
        buffer_oracle.EncodeEnumValue(buffer.sType);
        encode::EncodePNextStruct(&buffer_oracle, buffer.pNext);
        buffer_oracle.EncodeFlagsValue(buffer.flags);
        buffer_oracle.EncodeUInt64Value(buffer.size);
        buffer_oracle.EncodeFlagsValue(buffer.usage);
        buffer_oracle.EncodeEnumValue(buffer.sharingMode);
        buffer_oracle.EncodeUInt32Value(buffer.queueFamilyIndexCount);
        buffer_oracle.EncodeUInt32Array(buffer.pQueueFamilyIndices, buffer.queueFamilyIndexCount);

        CHECK(same_bytes(buffer_buffer, buffer_oracle_buffer));
    }

    // Retained partner: three counted runs in one structure, one of them signed, through its procedural body.
    const uint32_t view_masks[]        = { 0x3u, 0x5u };
    const int32_t  view_offsets[]      = { -1 };
    const uint32_t correlation_masks[] = { 0x6u, 0x1u };

    VkRenderPassMultiviewCreateInfo multiview{ VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO,
                                               nullptr,
                                               2u,
                                               view_masks,
                                               1u,
                                               view_offsets,
                                               2u,
                                               correlation_masks };

    encode::ParameterBuffer  multiview_buffer;
    encode::ParameterEncoder multiview_encoder(&multiview_buffer);
    encode::EncodeStruct(&multiview_encoder, multiview);

    encode::ParameterBuffer  multiview_oracle_buffer;
    encode::ParameterEncoder multiview_oracle(&multiview_oracle_buffer);
    multiview_oracle.EncodeEnumValue(multiview.sType);
    encode::EncodePNextStruct(&multiview_oracle, multiview.pNext);
    multiview_oracle.EncodeUInt32Value(multiview.subpassCount);
    multiview_oracle.EncodeUInt32Array(multiview.pViewMasks, multiview.subpassCount);
    multiview_oracle.EncodeUInt32Value(multiview.dependencyCount);
    multiview_oracle.EncodeInt32Array(multiview.pViewOffsets, multiview.dependencyCount);
    multiview_oracle.EncodeUInt32Value(multiview.correlationMaskCount);
    multiview_oracle.EncodeUInt32Array(multiview.pCorrelationMasks, multiview.correlationMaskCount);

    CHECK(same_bytes(multiview_buffer, multiview_oracle_buffer));
}

namespace
{

// A handle id source for wrappers the tests register themselves.
gfxrecon::format::HandleId TestHandleId()
{
    static gfxrecon::format::HandleId next = 0x1000;
    return next++;
}

// A non-dispatchable handle from a chosen value. A pointer on a 64-bit target and a 64-bit integer elsewhere.
template <typename Handle>
Handle FakeHandle(uint64_t value)
{
    if constexpr (std::is_pointer_v<Handle>)
    {
        return reinterpret_cast<Handle>(static_cast<uintptr_t>(value));
    }
    else
    {
        return static_cast<Handle>(value);
    }
}

// A non-dispatchable handle's bits widened to 64, which is how the API hands a generic handle over. A function
// template, so the branch that does not apply to the platform's handle representation is never instantiated.
template <typename Handle>
uint64_t HandleBits(Handle handle)
{
    if constexpr (std::is_pointer_v<Handle>)
    {
        return static_cast<uint64_t>(reinterpret_cast<uintptr_t>(handle));
    }
    else
    {
        return static_cast<uint64_t>(handle);
    }
}

// A callback with the API's calling convention, so its address converts to the PFN type on every platform.
VKAPI_ATTR VkBool32 VKAPI_CALL TestDebugUtilsCallback(VkDebugUtilsMessageSeverityFlagBitsEXT,
                                                      VkDebugUtilsMessageTypeFlagsEXT,
                                                      const VkDebugUtilsMessengerCallbackDataEXT*,
                                                      void*)
{
    return VK_FALSE;
}

} // namespace

TEST_CASE("Schema EncodeStruct matches address-value wire bytes", "[schema][encode]")
{
    // Four migrated structures cover the address kind's forms: two typed platform handles, a lone platform handle,
    // a platform HANDLE beside a flags value, and a function pointer beside a void pointer. Two retained partners
    // take a void pointer through their procedural bodies. The encoder records the pointer and nothing behind it,
    // so a chosen integer reinterpreted as each handle type stands in for a real window, monitor or allocation;
    // the platform handle types are the platform's on Windows and void pointers everywhere else.
    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    auto matches = [&](const auto& value, auto&& write_oracle) {
        encode::ParameterBuffer  buffer;
        encode::ParameterEncoder encoder(&buffer);
        encode::EncodeStruct(&encoder, value);

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        write_oracle(oracle);

        return same_bytes(buffer, oracle_buffer);
    };

    // The non-null value fits a 32-bit pointer, so the list-initialization narrows on no target.
    for (uintptr_t address : { uintptr_t{ 0 }, uintptr_t{ 0x7ff6a1b0u } })
    {
        // Migrated: two typed platform handles, under the probed chain walk.
        VkWin32SurfaceCreateInfoKHR surface{ VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
                                             nullptr,
                                             0u,
                                             reinterpret_cast<HINSTANCE>(address),
                                             reinterpret_cast<HWND>(address + 0x10) };

        CHECK(matches(surface, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(surface.sType);
            encode::EncodePNextStructIfValid(&oracle, surface.pNext);
            oracle.EncodeFlagsValue(surface.flags);
            oracle.EncodeVoidPtr(surface.hinstance);
            oracle.EncodeVoidPtr(surface.hwnd);
        }));

        // Migrated: one platform handle and nothing else.
        VkSurfaceFullScreenExclusiveWin32InfoEXT exclusive{
            VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT, nullptr, reinterpret_cast<HMONITOR>(address)
        };

        CHECK(matches(exclusive, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(exclusive.sType);
            encode::EncodePNextStruct(&oracle, exclusive.pNext);
            oracle.EncodeVoidPtr(exclusive.hmonitor);
        }));

        // Migrated: a HANDLE beside a flags value.
        VkImportMemoryWin32HandleInfoNV import_handle{ VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV,
                                                       nullptr,
                                                       VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV,
                                                       reinterpret_cast<HANDLE>(address) };

        CHECK(matches(import_handle, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(import_handle.sType);
            encode::EncodePNextStruct(&oracle, import_handle.pNext);
            oracle.EncodeFlagsValue(import_handle.handleType);
            oracle.EncodeVoidPtr(import_handle.handle);
        }));

        // Migrated: a function pointer and a void pointer, the two named entry points the address kind replaces.
        VkDebugUtilsMessengerCreateInfoEXT messenger{ VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
                                                      nullptr,
                                                      0u,
                                                      VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
                                                      VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT,
                                                      address != 0 ? &TestDebugUtilsCallback : nullptr,
                                                      reinterpret_cast<void*>(address) };

        CHECK(matches(messenger, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(messenger.sType);
            encode::EncodePNextStruct(&oracle, messenger.pNext);
            oracle.EncodeFlagsValue(messenger.flags);
            oracle.EncodeFlagsValue(messenger.messageSeverity);
            oracle.EncodeFlagsValue(messenger.messageType);
            oracle.EncodeFunctionPtr(messenger.pfnUserCallback);
            oracle.EncodeVoidPtr(messenger.pUserData);
        }));

        // Retained partners: a void pointer through each procedural body, one per chain walk.
        VkImportMemoryHostPointerInfoEXT host_pointer{ VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT,
                                                       nullptr,
                                                       VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT,
                                                       reinterpret_cast<void*>(address) };

        CHECK(matches(host_pointer, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(host_pointer.sType);
            encode::EncodePNextStruct(&oracle, host_pointer.pNext);
            oracle.EncodeEnumValue(host_pointer.handleType);
            oracle.EncodeVoidPtr(host_pointer.pHostPointer);
        }));

        VkCheckpointDataNV checkpoint{ VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV,
                                       nullptr,
                                       VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       reinterpret_cast<void*>(address) };

        CHECK(matches(checkpoint, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(checkpoint.sType);
            encode::EncodePNextStructIfValid(&oracle, checkpoint.pNext);
            oracle.EncodeEnumValue(checkpoint.stage);
            oracle.EncodeVoidPtr(checkpoint.pCheckpointMarker);
        }));
    }
}

TEST_CASE("Schema EncodeStruct matches wrapped-handle wire bytes", "[schema][encode]")
{
    // Two migrated structures, one handle each of the two wrapper types the pilot maps, one per chain walk; two
    // retained partners, one carrying both handles. A handle encodes as the id of the wrapper the state handle table
    // holds for it, so the test registers wrappers for chosen handle values and destroys them after, and also encodes
    // the null handle, which is the null id with no lookup. An unregistered non-null handle would encode as the null
    // id with a warning; that case is not taken, since both sides would make the same lookup and prove nothing.
    using namespace gfxrecon::encode::vulkan_wrappers;

    util::Log::Init(util::LoggingSeverity::kError);

    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    auto matches = [&](const auto& value, auto&& write_oracle) {
        encode::ParameterBuffer  buffer;
        encode::ParameterEncoder encoder(&buffer);
        encode::EncodeStruct(&encoder, value);

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        write_oracle(oracle);

        return same_bytes(buffer, oracle_buffer);
    };

    VkBuffer       buffer = FakeHandle<VkBuffer>(0x0b0fu);
    VkDeviceMemory memory = FakeHandle<VkDeviceMemory>(0x0d0eu);
    CreateWrappedNonDispatchHandle<BufferWrapper>(&buffer, TestHandleId);
    CreateWrappedNonDispatchHandle<DeviceMemoryWrapper>(&memory, TestHandleId);
    REQUIRE(GetWrappedId<BufferWrapper>(buffer) != format::kNullHandleId);
    REQUIRE(GetWrappedId<DeviceMemoryWrapper>(memory) != format::kNullHandleId);

    struct Handles
    {
        VkBuffer       buffer;
        VkDeviceMemory memory;
    };

    for (const Handles& handles : { Handles{ VK_NULL_HANDLE, VK_NULL_HANDLE }, Handles{ buffer, memory } })
    {
        // Migrated: a device memory handle under the probed chain walk.
        VkMappedMemoryRange range{ VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE, nullptr, handles.memory, 0x100u, 0x200u };

        CHECK(matches(range, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(range.sType);
            encode::EncodePNextStructIfValid(&oracle, range.pNext);
            oracle.EncodeVulkanHandleValue<DeviceMemoryWrapper>(range.memory);
            oracle.EncodeUInt64Value(range.offset);
            oracle.EncodeUInt64Value(range.size);
        }));

        // Migrated: the design's canonical example, a buffer handle among six scalars, trusted chain walk.
        VkBufferMemoryBarrier barrier{ VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
                                       nullptr,
                                       VK_ACCESS_TRANSFER_WRITE_BIT,
                                       VK_ACCESS_SHADER_READ_BIT,
                                       1u,
                                       2u,
                                       handles.buffer,
                                       0x10u,
                                       VK_WHOLE_SIZE };

        CHECK(matches(barrier, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(barrier.sType);
            encode::EncodePNextStruct(&oracle, barrier.pNext);
            oracle.EncodeFlagsValue(barrier.srcAccessMask);
            oracle.EncodeFlagsValue(barrier.dstAccessMask);
            oracle.EncodeUInt32Value(barrier.srcQueueFamilyIndex);
            oracle.EncodeUInt32Value(barrier.dstQueueFamilyIndex);
            oracle.EncodeVulkanHandleValue<BufferWrapper>(barrier.buffer);
            oracle.EncodeUInt64Value(barrier.offset);
            oracle.EncodeUInt64Value(barrier.size);
        }));

        // Retained partners: both handles in one body, and a buffer handle among scalars and an enum.
        VkBindBufferMemoryInfo bind{
            VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO, nullptr, handles.buffer, handles.memory, 0x40u
        };

        CHECK(matches(bind, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(bind.sType);
            encode::EncodePNextStruct(&oracle, bind.pNext);
            oracle.EncodeVulkanHandleValue<BufferWrapper>(bind.buffer);
            oracle.EncodeVulkanHandleValue<DeviceMemoryWrapper>(bind.memory);
            oracle.EncodeUInt64Value(bind.memoryOffset);
        }));

        VkBufferViewCreateInfo view{
            VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO, nullptr, 0u, handles.buffer, VK_FORMAT_R32_UINT, 0x20u, 0x80u
        };

        CHECK(matches(view, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(view.sType);
            encode::EncodePNextStruct(&oracle, view.pNext);
            oracle.EncodeFlagsValue(view.flags);
            oracle.EncodeVulkanHandleValue<BufferWrapper>(view.buffer);
            oracle.EncodeEnumValue(view.format);
            oracle.EncodeUInt64Value(view.offset);
            oracle.EncodeUInt64Value(view.range);
        }));
    }

    DestroyWrappedHandle<BufferWrapper>(buffer);
    DestroyWrappedHandle<DeviceMemoryWrapper>(memory);
}

TEST_CASE("Schema EncodeStruct matches wrapped-handle run wire bytes", "[schema][encode]")
{
    // One migrated structure with three handle runs of two wrapper types beside a flags run that shares a count
    // with the first of them; two retained partners with a handle run beside scalar runs. Semaphores register as
    // non-dispatchable wrappers with no parent. A command buffer is dispatchable: registration reads the dispatch
    // key from the first word of the object the handle points at, so a local pointer slot stands in for the driver's
    // object, and removal goes through the generic path because the command-buffer specialization assumes a pool.
    using namespace gfxrecon::encode::vulkan_wrappers;

    util::Log::Init(util::LoggingSeverity::kError);

    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    auto matches = [&](const auto& value, auto&& write_oracle) {
        encode::ParameterBuffer  buffer;
        encode::ParameterEncoder encoder(&buffer);
        encode::EncodeStruct(&encoder, value);

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        write_oracle(oracle);

        return same_bytes(buffer, oracle_buffer);
    };

    VkSemaphore semaphores[] = { FakeHandle<VkSemaphore>(0x5e01u), FakeHandle<VkSemaphore>(0x5e02u) };
    for (VkSemaphore& semaphore : semaphores)
    {
        CreateWrappedNonDispatchHandle<SemaphoreWrapper>(&semaphore, TestHandleId);
    }

    void*           command_buffer_object = nullptr;
    VkCommandBuffer command_buffer        = reinterpret_cast<VkCommandBuffer>(&command_buffer_object);
    CreateWrappedDispatchHandle<DeviceWrapper, CommandBufferWrapper>(VK_NULL_HANDLE, &command_buffer, TestHandleId);
    REQUIRE(GetWrappedId<CommandBufferWrapper>(command_buffer) != format::kNullHandleId);

    const VkSemaphore          null_semaphores[] = { VK_NULL_HANDLE, VK_NULL_HANDLE };
    const VkCommandBuffer      null_command[]    = { VK_NULL_HANDLE };
    const VkCommandBuffer      one_command[]     = { command_buffer };
    const VkPipelineStageFlags stage_masks[]     = { VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                     VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
    const uint64_t             values[]          = { 7u, 9u };
    const VkSwapchainKHR       null_swapchain[]  = { VK_NULL_HANDLE };
    const uint32_t             image_index[]     = { 3u };
    VkResult                   present_results[] = { VK_SUBOPTIMAL_KHR };

    struct Handles
    {
        const VkSemaphore*     semaphores;
        const VkCommandBuffer* command_buffers;
    };

    for (const Handles& handles : { Handles{ null_semaphores, null_command }, Handles{ semaphores, one_command } })
    {
        // Migrated: three handle runs, the first sharing waitSemaphoreCount with the flags run beside it.
        VkSubmitInfo submit{ VK_STRUCTURE_TYPE_SUBMIT_INFO,
                             nullptr,
                             2u,
                             handles.semaphores,
                             stage_masks,
                             1u,
                             handles.command_buffers,
                             1u,
                             handles.semaphores + 1 };

        CHECK(matches(submit, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(submit.sType);
            encode::EncodePNextStruct(&oracle, submit.pNext);
            oracle.EncodeUInt32Value(submit.waitSemaphoreCount);
            oracle.EncodeVulkanHandleArray<SemaphoreWrapper>(submit.pWaitSemaphores, submit.waitSemaphoreCount);
            oracle.EncodeFlagsArray(submit.pWaitDstStageMask, submit.waitSemaphoreCount);
            oracle.EncodeUInt32Value(submit.commandBufferCount);
            oracle.EncodeVulkanHandleArray<CommandBufferWrapper>(submit.pCommandBuffers, submit.commandBufferCount);
            oracle.EncodeUInt32Value(submit.signalSemaphoreCount);
            oracle.EncodeVulkanHandleArray<SemaphoreWrapper>(submit.pSignalSemaphores, submit.signalSemaphoreCount);
        }));

        // Retained partner: a handle run beside a uint64 run under one count, probed chain walk.
        VkSemaphoreWaitInfo wait{
            VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO, nullptr, VK_SEMAPHORE_WAIT_ANY_BIT, 2u, handles.semaphores, values
        };

        CHECK(matches(wait, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(wait.sType);
            encode::EncodePNextStructIfValid(&oracle, wait.pNext);
            oracle.EncodeFlagsValue(wait.flags);
            oracle.EncodeUInt32Value(wait.semaphoreCount);
            oracle.EncodeVulkanHandleArray<SemaphoreWrapper>(wait.pSemaphores, wait.semaphoreCount);
            oracle.EncodeUInt64Array(wait.pValues, wait.semaphoreCount);
        }));

        // Retained partner: two handle runs of different types beside a uint32 run and a VkResult run.
        VkPresentInfoKHR present{ VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
                                  nullptr,
                                  1u,
                                  handles.semaphores,
                                  1u,
                                  null_swapchain,
                                  image_index,
                                  present_results };

        CHECK(matches(present, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(present.sType);
            encode::EncodePNextStruct(&oracle, present.pNext);
            oracle.EncodeUInt32Value(present.waitSemaphoreCount);
            oracle.EncodeVulkanHandleArray<SemaphoreWrapper>(present.pWaitSemaphores, present.waitSemaphoreCount);
            oracle.EncodeUInt32Value(present.swapchainCount);
            oracle.EncodeVulkanHandleArray<SwapchainKHRWrapper>(present.pSwapchains, present.swapchainCount);
            oracle.EncodeUInt32Array(present.pImageIndices, present.swapchainCount);
            oracle.EncodeEnumArray(present.pResults, present.swapchainCount);
        }));
    }

    for (VkSemaphore semaphore : semaphores)
    {
        DestroyWrappedHandle<SemaphoreWrapper>(semaphore);
    }

    auto* command_buffer_wrapper = GetWrapper<CommandBufferWrapper>(command_buffer);
    RemoveWrapper<CommandBufferWrapper>(command_buffer_wrapper);
    delete command_buffer_wrapper;
}

TEST_CASE("Schema EncodeStruct matches generic-handle and text-pointer wire bytes", "[schema][encode]")
{
    // One migrated structure carrying both idioms: a generic handle, an integer whose object type a sibling enum
    // names and which the encoder resolves to a wrapper id through that enum, and a pointer to text. The retained
    // partner is the debug-marker twin, whose selector is the older VkDebugReportObjectTypeEXT enum and whose chain
    // walk is the probed one. A registered buffer resolves to a real id; the null object resolves to the null id;
    // the text is null, empty, and a short name.
    using namespace gfxrecon::encode::vulkan_wrappers;

    util::Log::Init(util::LoggingSeverity::kError);

    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    auto matches = [&](const auto& value, auto&& write_oracle) {
        encode::ParameterBuffer  buffer;
        encode::ParameterEncoder encoder(&buffer);
        encode::EncodeStruct(&encoder, value);

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        write_oracle(oracle);

        return same_bytes(buffer, oracle_buffer);
    };

    VkBuffer buffer = FakeHandle<VkBuffer>(0x0b0fu);
    CreateWrappedNonDispatchHandle<BufferWrapper>(&buffer, TestHandleId);

    const uint64_t buffer_bits = HandleBits(buffer);
    REQUIRE(GetWrappedId(buffer_bits, VK_OBJECT_TYPE_BUFFER) != format::kNullHandleId);

    struct Case
    {
        uint64_t    object;
        const char* name;
    };

    for (const Case& c : { Case{ 0u, nullptr }, Case{ buffer_bits, "" }, Case{ buffer_bits, "schema" } })
    {
        // Migrated: VkObjectType selector, trusted chain walk.
        VkDebugUtilsObjectNameInfoEXT utils{
            VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT, nullptr, VK_OBJECT_TYPE_BUFFER, c.object, c.name
        };

        CHECK(matches(utils, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(utils.sType);
            encode::EncodePNextStruct(&oracle, utils.pNext);
            oracle.EncodeEnumValue(utils.objectType);
            oracle.EncodeUInt64Value(GetWrappedId(utils.objectHandle, utils.objectType));
            oracle.EncodeString(utils.pObjectName);
        }));

        // Retained partner: VkDebugReportObjectTypeEXT selector, probed chain walk.
        VkDebugMarkerObjectNameInfoEXT marker{ VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT,
                                               nullptr,
                                               VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT,
                                               c.object,
                                               c.name };

        CHECK(matches(marker, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(marker.sType);
            encode::EncodePNextStructIfValid(&oracle, marker.pNext);
            oracle.EncodeEnumValue(marker.objectType);
            oracle.EncodeUInt64Value(GetWrappedId(marker.object, marker.objectType));
            oracle.EncodeString(marker.pObjectName);
        }));
    }

    DestroyWrappedHandle<BufferWrapper>(buffer);
}

TEST_CASE("Schema EncodeStruct matches fixed-extent text wire bytes", "[schema][encode]")
{
    // One migrated structure, a fixed string beside one scalar and nothing else, so a mismatch can only be the
    // string; the retained partner carries two fixed strings around two scalars. The string is empty, short, and
    // filled to the extent minus one, against the procedural body's pointer-form EncodeString. A fourth case fills
    // the whole extent with no terminator: the procedural form would read past the array there, so it is compared
    // against the bounded kind-keyed form the Action calls, which proves the bound holds rather than the bytes.
    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    auto matches = [&](const auto& value, auto&& write_oracle) {
        encode::ParameterBuffer  buffer;
        encode::ParameterEncoder encoder(&buffer);
        encode::EncodeStruct(&encoder, value);

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        write_oracle(oracle);

        return same_bytes(buffer, oracle_buffer);
    };

    auto fill = [](char* text, size_t extent, size_t length) {
        for (size_t i = 0; i < extent; ++i)
        {
            text[i] = (i < length) ? static_cast<char>('a' + (i % 26)) : '\0';
        }
    };

    for (size_t length : { size_t{ 0 }, size_t{ 11 }, size_t{ VK_MAX_EXTENSION_NAME_SIZE - 1 } })
    {
        VkExtensionProperties extension{};
        fill(extension.extensionName, VK_MAX_EXTENSION_NAME_SIZE, length);
        extension.specVersion = 0x00010203u;

        CHECK(matches(extension, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeString(extension.extensionName);
            oracle.EncodeUInt32Value(extension.specVersion);
        }));

        VkLayerProperties layer{};
        fill(layer.layerName, VK_MAX_EXTENSION_NAME_SIZE, length);
        layer.specVersion           = 0x00010203u;
        layer.implementationVersion = 0x00000007u;
        fill(layer.description, VK_MAX_DESCRIPTION_SIZE, length);

        CHECK(matches(layer, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeString(layer.layerName);
            oracle.EncodeUInt32Value(layer.specVersion);
            oracle.EncodeUInt32Value(layer.implementationVersion);
            oracle.EncodeString(layer.description);
        }));
    }

    // No terminator anywhere in the array. The bounded form reports the extent as the length and reads no further.
    VkExtensionProperties unterminated{};
    fill(unterminated.extensionName, VK_MAX_EXTENSION_NAME_SIZE, VK_MAX_EXTENSION_NAME_SIZE);
    unterminated.specVersion = 0x00010203u;

    CHECK(matches(unterminated, [&](encode::ParameterEncoder& oracle) {
        oracle.EncodeString(format::kind::Char{}, unterminated.extensionName, VK_MAX_EXTENSION_NAME_SIZE);
        oracle.EncodeUInt32Value(unterminated.specVersion);
    }));
}

TEST_CASE("Schema EncodeStruct matches wide-text pointer wire bytes", "[schema][encode]")
{
    // One migrated structure with an LPCWSTR beside a HANDLE, and a retained partner adding a semaphore handle. The
    // WChar kind's wire type is 16-bit units on every platform, converted element by element where wchar_t is
    // wider, so the same bytes are expected on Windows and Linux. The name is null and set; the handle is a
    // chosen value reinterpreted as HANDLE, void* off Windows.
    using namespace gfxrecon::encode::vulkan_wrappers;

    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    auto matches = [&](const auto& value, auto&& write_oracle) {
        encode::ParameterBuffer  buffer;
        encode::ParameterEncoder encoder(&buffer);
        encode::EncodeStruct(&encoder, value);

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        write_oracle(oracle);

        return same_bytes(buffer, oracle_buffer);
    };

    const wchar_t wide_name[] = L"schemaé";

    for (LPCWSTR name : { static_cast<LPCWSTR>(nullptr), static_cast<LPCWSTR>(wide_name) })
    {
        // Migrated: enum, HANDLE, LPCWSTR, trusted chain walk.
        VkImportMemoryWin32HandleInfoKHR import_memory{ VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR,
                                                        nullptr,
                                                        VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT,
                                                        reinterpret_cast<HANDLE>(uintptr_t{ 0x4a00u }),
                                                        name };

        CHECK(matches(import_memory, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(import_memory.sType);
            encode::EncodePNextStruct(&oracle, import_memory.pNext);
            oracle.EncodeEnumValue(import_memory.handleType);
            oracle.EncodeVoidPtr(import_memory.handle);
            oracle.EncodeWString(import_memory.name);
        }));

        // Retained partner: a null semaphore handle ahead of the same three, probed chain walk.
        VkImportSemaphoreWin32HandleInfoKHR import_semaphore{ VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR,
                                                              nullptr,
                                                              VK_NULL_HANDLE,
                                                              VK_SEMAPHORE_IMPORT_TEMPORARY_BIT,
                                                              VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT,
                                                              reinterpret_cast<HANDLE>(uintptr_t{ 0x4a10u }),
                                                              name };

        CHECK(matches(import_semaphore, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(import_semaphore.sType);
            encode::EncodePNextStructIfValid(&oracle, import_semaphore.pNext);
            oracle.EncodeVulkanHandleValue<SemaphoreWrapper>(import_semaphore.semaphore);
            oracle.EncodeFlagsValue(import_semaphore.flags);
            oracle.EncodeEnumValue(import_semaphore.handleType);
            oracle.EncodeVoidPtr(import_semaphore.handle);
            oracle.EncodeWString(import_semaphore.name);
        }));
    }
}

TEST_CASE("Schema EncodeStruct matches embedded-structure wire bytes", "[schema][encode]")
{
    // Two migrated structures cover the four structure shapes. VkRenderingInfo carries a structure value, a counted
    // run of structures and two structure pointers, every inner type procedural, so the walk descends without any
    // inner port; VkImageBlit carries two structure values and two fixed-extent structure arrays. The retained
    // partner VkSpecializationInfo puts a structure run beside an OpaqueBytes run. Inner handles are null and the
    // clear value is a union the inner procedural body owns, so nothing here depends on the wrapper table.
    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    auto matches = [&](const auto& value, auto&& write_oracle) {
        encode::ParameterBuffer  buffer;
        encode::ParameterEncoder encoder(&buffer);
        encode::EncodeStruct(&encoder, value);

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        write_oracle(oracle);

        return same_bytes(buffer, oracle_buffer);
    };

    VkRenderingAttachmentInfo color[2]{};
    for (uint32_t i = 0; i < 2; ++i)
    {
        color[i].sType                       = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO;
        color[i].imageLayout                 = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
        color[i].resolveMode                 = VK_RESOLVE_MODE_NONE;
        color[i].resolveImageLayout          = VK_IMAGE_LAYOUT_UNDEFINED;
        color[i].loadOp                      = VK_ATTACHMENT_LOAD_OP_CLEAR;
        color[i].storeOp                     = VK_ATTACHMENT_STORE_OP_STORE;
        color[i].clearValue.color.float32[0] = 0.25f * static_cast<float>(i + 1);
        color[i].clearValue.color.float32[3] = 1.0f;
    }

    VkRenderingAttachmentInfo depth{};
    depth.sType                           = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO;
    depth.imageLayout                     = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL;
    depth.loadOp                          = VK_ATTACHMENT_LOAD_OP_LOAD;
    depth.storeOp                         = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    depth.clearValue.depthStencil.depth   = 0.5f;
    depth.clearValue.depthStencil.stencil = 7u;

    struct Attachments
    {
        uint32_t                         count;
        const VkRenderingAttachmentInfo* colors;
        const VkRenderingAttachmentInfo* depth;
    };

    // Migrated: a value (renderArea), a counted run (color attachments), two pointers, one null in each case.
    for (const Attachments& a : { Attachments{ 0u, nullptr, nullptr }, Attachments{ 2u, color, &depth } })
    {
        VkRenderingInfo rendering{ VK_STRUCTURE_TYPE_RENDERING_INFO,
                                   nullptr,
                                   VK_RENDERING_SUSPENDING_BIT,
                                   VkRect2D{ VkOffset2D{ 3, -4 }, VkExtent2D{ 640u, 480u } },
                                   1u,
                                   0x5u,
                                   a.count,
                                   a.colors,
                                   a.depth,
                                   nullptr };

        CHECK(matches(rendering, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(rendering.sType);
            encode::EncodePNextStruct(&oracle, rendering.pNext);
            oracle.EncodeFlagsValue(rendering.flags);
            encode::EncodeStruct(&oracle, rendering.renderArea);
            oracle.EncodeUInt32Value(rendering.layerCount);
            oracle.EncodeUInt32Value(rendering.viewMask);
            oracle.EncodeUInt32Value(rendering.colorAttachmentCount);
            encode::EncodeStructArray(&oracle, rendering.pColorAttachments, rendering.colorAttachmentCount);
            encode::EncodeStructPtr(&oracle, rendering.pDepthAttachment);
            encode::EncodeStructPtr(&oracle, rendering.pStencilAttachment);
        }));
    }

    // Migrated: two structure values and two fixed-extent structure arrays, offsets asymmetric so a swapped or
    // truncated array lands on different bytes.
    VkImageBlit blit{ VkImageSubresourceLayers{ VK_IMAGE_ASPECT_COLOR_BIT, 1u, 2u, 3u },
                      { VkOffset3D{ 0, 1, 2 }, VkOffset3D{ 16, 32, 1 } },
                      VkImageSubresourceLayers{ VK_IMAGE_ASPECT_COLOR_BIT, 0u, 5u, 1u },
                      { VkOffset3D{ 4, 8, 0 }, VkOffset3D{ 64, 128, 1 } } };

    CHECK(matches(blit, [&](encode::ParameterEncoder& oracle) {
        encode::EncodeStruct(&oracle, blit.srcSubresource);
        encode::EncodeStructArray(&oracle, blit.srcOffsets, 2);
        encode::EncodeStruct(&oracle, blit.dstSubresource);
        encode::EncodeStructArray(&oracle, blit.dstOffsets, 2);
    }));

    // Retained partner: a structure run beside a byte run, through its procedural body.
    const VkSpecializationMapEntry entries[] = { VkSpecializationMapEntry{ 0u, 0u, 4u },
                                                 VkSpecializationMapEntry{ 1u, 4u, 1u } };
    const uint8_t                  data[]    = { 0x01, 0x02, 0x03, 0x04, 0x05 };

    for (const VkSpecializationInfo& specialization :
         { VkSpecializationInfo{ 0u, nullptr, 0u, nullptr }, VkSpecializationInfo{ 2u, entries, sizeof(data), data } })
    {
        CHECK(matches(specialization, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeUInt32Value(specialization.mapEntryCount);
            encode::EncodeStructArray(&oracle, specialization.pMapEntries, specialization.mapEntryCount);
            oracle.EncodeSizeTValue(specialization.dataSize);
            oracle.EncodeVoidArray(specialization.pData, specialization.dataSize);
        }));
    }
}

TEST_CASE("Schema EncodeStruct matches counted fixed-extent array wire bytes", "[schema][encode]")
{
    // Two migrated structures whose fixed-extent arrays carry a count sibling. The procedural bodies encode the
    // count, not the extent, and the schema records the sibling as count_field, so the static-array overload reads
    // it. VkPhysicalDeviceMemoryProperties holds two structure arrays; VkPhysicalDeviceGroupProperties holds the
    // registry's one handle static array, the only exercise the handle array adapter entry's static-array half
    // gets. Counts sit below the extents so a full-extent run lands on different bytes. The over-extent cases have
    // no procedural oracle, since those bodies would read past the member; their oracle is the primitive sequence
    // with the count written as the driver set it and the run clamped to the extent. Two retained partners:
    // VkPhysicalDeviceMemoryProperties2 reaches a migrated body through a procedural parent, and
    // VkQueueFamilyGlobalPriorityProperties has a count sibling the naming heuristic misses (DF-1), so its body
    // still writes the full extent.
    using namespace gfxrecon::encode::vulkan_wrappers;

    util::Log::Init(util::LoggingSeverity::kError);

    namespace memory_field = schema::field::vulkan::VkPhysicalDeviceMemoryProperties;
    namespace group_field  = schema::field::vulkan::VkPhysicalDeviceGroupProperties;
    static_assert(schema::StaticArrayField<group_field::physicalDevices>);
    static_assert(schema::HandleKindField<group_field::physicalDevices>);
    static_assert(schema::HasCountField<VkPhysicalDeviceGroupProperties, group_field::physicalDevices>);
    static_assert(
        std::is_same_v<schema::FieldCountField<group_field::physicalDevices>, group_field::physicalDeviceCount>);
    static_assert(encode::HasCaptureWrapper<schema::api_type::vulkan::VkPhysicalDevice>);
    static_assert(schema::StaticArrayField<memory_field::memoryTypes>);
    static_assert(schema::StaticArrayField<memory_field::memoryHeaps>);
    static_assert(schema::HasCountField<VkPhysicalDeviceMemoryProperties, memory_field::memoryTypes>);
    static_assert(schema::HasCountField<VkPhysicalDeviceMemoryProperties, memory_field::memoryHeaps>);
    static_assert(std::is_same_v<schema::FieldCountField<memory_field::memoryTypes>, memory_field::memoryTypeCount>);
    static_assert(std::is_same_v<schema::FieldCountField<memory_field::memoryHeaps>, memory_field::memoryHeapCount>);

    auto same_bytes = [](const encode::ParameterBuffer& actual, const encode::ParameterBuffer& oracle) {
        return actual.GetDataSize() == oracle.GetDataSize() &&
               std::memcmp(actual.GetData(), oracle.GetData(), actual.GetDataSize()) == 0;
    };

    auto matches = [&](const auto& value, auto&& write_oracle) {
        encode::ParameterBuffer  buffer;
        encode::ParameterEncoder encoder(&buffer);
        encode::EncodeStruct(&encoder, value);

        encode::ParameterBuffer  oracle_buffer;
        encode::ParameterEncoder oracle(&oracle_buffer);
        write_oracle(oracle);

        return same_bytes(buffer, oracle_buffer);
    };

    // Every element of both arrays is distinct, so a run of the wrong length or from the wrong array differs.
    auto fill = [](VkPhysicalDeviceMemoryProperties& properties) {
        for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; ++i)
        {
            properties.memoryTypes[i].propertyFlags = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT << (i % 5u);
            properties.memoryTypes[i].heapIndex     = i % VK_MAX_MEMORY_HEAPS;
        }
        for (uint32_t i = 0; i < VK_MAX_MEMORY_HEAPS; ++i)
        {
            properties.memoryHeaps[i].size  = 0x10000000ull * (i + 1) + i;
            properties.memoryHeaps[i].flags = (i % 2u) ? VK_MEMORY_HEAP_DEVICE_LOCAL_BIT : 0u;
        }
    };

    struct Counts
    {
        uint32_t types;
        uint32_t heaps;
    };

    // Migrated: counts below the extents, zero counts, and counts equal to the extents.
    for (const Counts& counts :
         { Counts{ 3u, 2u }, Counts{ 0u, 0u }, Counts{ VK_MAX_MEMORY_TYPES, VK_MAX_MEMORY_HEAPS } })
    {
        VkPhysicalDeviceMemoryProperties properties{};
        fill(properties);
        properties.memoryTypeCount = counts.types;
        properties.memoryHeapCount = counts.heaps;

        CHECK(matches(properties, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeUInt32Value(properties.memoryTypeCount);
            encode::EncodeStructArray(&oracle, properties.memoryTypes, properties.memoryTypeCount);
            oracle.EncodeUInt32Value(properties.memoryHeapCount);
            encode::EncodeStructArray(&oracle, properties.memoryHeaps, properties.memoryHeapCount);
        }));
    }

    // Migrated, counts over the extents: the count is recorded as set, the run stops at the extent.
    {
        VkPhysicalDeviceMemoryProperties properties{};
        fill(properties);
        properties.memoryTypeCount = VK_MAX_MEMORY_TYPES + 5u;
        properties.memoryHeapCount = VK_MAX_MEMORY_HEAPS + 1u;

        CHECK(matches(properties, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeUInt32Value(properties.memoryTypeCount);
            encode::EncodeStructArray(&oracle, properties.memoryTypes, VK_MAX_MEMORY_TYPES);
            oracle.EncodeUInt32Value(properties.memoryHeapCount);
            encode::EncodeStructArray(&oracle, properties.memoryHeaps, VK_MAX_MEMORY_HEAPS);
        }));
    }

    // Retained partner: a procedural parent whose structure value is the migrated body.
    {
        VkPhysicalDeviceMemoryProperties2 properties2{};
        properties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2;
        fill(properties2.memoryProperties);
        properties2.memoryProperties.memoryTypeCount = 4u;
        properties2.memoryProperties.memoryHeapCount = 1u;

        CHECK(matches(properties2, [&](encode::ParameterEncoder& oracle) {
            const VkPhysicalDeviceMemoryProperties& inner = properties2.memoryProperties;
            oracle.EncodeEnumValue(properties2.sType);
            encode::EncodePNextStruct(&oracle, properties2.pNext);
            oracle.EncodeUInt32Value(inner.memoryTypeCount);
            encode::EncodeStructArray(&oracle, inner.memoryTypes, inner.memoryTypeCount);
            oracle.EncodeUInt32Value(inner.memoryHeapCount);
            encode::EncodeStructArray(&oracle, inner.memoryHeaps, inner.memoryHeapCount);
        }));
    }

    // Migrated: the handle static array. Physical devices are dispatchable, so each registers from a local pointer
    // slot with a null parent, as the command buffer does in the handle-run test, and is removed through the generic
    // path. Elements past the count stay VK_NULL_HANDLE, so the over-extent run is two ids and thirty nulls.
    void*            device_objects[2] = { nullptr, nullptr };
    VkPhysicalDevice devices[2]        = { reinterpret_cast<VkPhysicalDevice>(&device_objects[0]),
                                           reinterpret_cast<VkPhysicalDevice>(&device_objects[1]) };
    for (VkPhysicalDevice& device : devices)
    {
        CreateWrappedDispatchHandle<InstanceWrapper, PhysicalDeviceWrapper>(VK_NULL_HANDLE, &device, TestHandleId);
        REQUIRE(GetWrappedId<PhysicalDeviceWrapper>(device) != format::kNullHandleId);
    }

    struct GroupCase
    {
        uint32_t count;
        uint32_t encoded;
    };

    for (const GroupCase& group_case : { GroupCase{ 2u, 2u },
                                         GroupCase{ 0u, 0u },
                                         GroupCase{ VK_MAX_DEVICE_GROUP_SIZE + 3u, VK_MAX_DEVICE_GROUP_SIZE } })
    {
        VkPhysicalDeviceGroupProperties group{};
        group.sType               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES;
        group.physicalDeviceCount = group_case.count;
        group.physicalDevices[0]  = devices[0];
        group.physicalDevices[1]  = devices[1];
        group.subsetAllocation    = VK_TRUE;

        CHECK(matches(group, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(group.sType);
            encode::EncodePNextStructIfValid(&oracle, group.pNext);
            oracle.EncodeUInt32Value(group.physicalDeviceCount);
            oracle.EncodeVulkanHandleArray<PhysicalDeviceWrapper>(group.physicalDevices, group_case.encoded);
            oracle.EncodeUInt32Value(group.subsetAllocation);
        }));
    }

    for (VkPhysicalDevice device : devices)
    {
        auto* wrapper = GetWrapper<PhysicalDeviceWrapper>(device);
        RemoveWrapper<PhysicalDeviceWrapper>(wrapper);
        delete wrapper;
    }

    // Retained partner: the count sibling is named priorityCount, which the heuristic does not find for
    // priorities, so the procedural body writes every element of the extent.
    {
        VkQueueFamilyGlobalPriorityProperties priorities{};
        priorities.sType         = VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES;
        priorities.priorityCount = 2u;
        for (uint32_t i = 0; i < VK_MAX_GLOBAL_PRIORITY_SIZE; ++i)
        {
            priorities.priorities[i] = VK_QUEUE_GLOBAL_PRIORITY_MEDIUM;
        }
        priorities.priorities[0] = VK_QUEUE_GLOBAL_PRIORITY_LOW;
        priorities.priorities[1] = VK_QUEUE_GLOBAL_PRIORITY_HIGH;

        CHECK(matches(priorities, [&](encode::ParameterEncoder& oracle) {
            oracle.EncodeEnumValue(priorities.sType);
            encode::EncodePNextStruct(&oracle, priorities.pNext);
            oracle.EncodeUInt32Value(priorities.priorityCount);
            oracle.EncodeEnumArray(priorities.priorities, VK_MAX_GLOBAL_PRIORITY_SIZE);
        }));
    }
}

TEST_CASE("Getter yields a Field's value in place or by copy", "[schema]")
{
    // An addressable member is referenced where it lives: the dereferenced Getter is the member itself. A bitfield
    // has no address, so the Getter holds a copy read through the generated accessor and yields that.
    using width = schema::field::vulkan::VkExtent2D::width;
    static_assert(schema::Addressable<VkExtent2D, width>);

    VkExtent2D extent{ 3u, 4u };
    CHECK(&*schema::Getter<VkExtent2D, width>(extent, width{}) == &extent.width);
    CHECK(*schema::Getter<VkExtent2D, width>(extent, width{}) == 3u);
    CHECK(&*schema::Getter(extent, width{}) == &extent.width); // arguments deduced from the primary's constructor

    using flag = schema::field::vulkan::StdVideoH264SpsVuiFlags::aspect_ratio_info_present_flag;
    static_assert(schema::NonAddressable<StdVideoH264SpsVuiFlags, flag>);

    StdVideoH264SpsVuiFlags flags{};
    flags.aspect_ratio_info_present_flag = 1u;
    CHECK(*schema::Getter<StdVideoH264SpsVuiFlags, flag>(flags, flag{}) == 1u);
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

    // VkBufferMemoryBarrier is schema-driven, so the struct-decoders generator emits no procedural body for it and
    // DecodeStruct is the field walk. Nothing below names a field of the structure: the
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

    // This is the ordinary decode entry point. Its body is the field walk.
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

    // VkShaderModuleCreateInfo is the smallest structure carrying a PointerArray of scalars. Its pCode is
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

    // VkSparseBufferMemoryBindInfo is the smallest structure carrying a PointerArray of structures, and it has no
    // sType and no pNext, which is worth having: the walk makes no assumption that a structure is extensible.
    //
    // Each element descends through the ordinary DecodeStruct entry point, which for VkSparseMemoryBind is a second
    // field walk. The array overload does not know or care which: it meets the element at the entry point, the same
    // way it would meet a hand-written body.
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

    // VkTransformMatrixKHR is one field, float matrix[3][4]. The Field records extents {3, 4}, and the overload
    // takes both extents from std::extent_v on the API member's declared type, which the member trait already
    // names, so the one and two dimensional cases need no separate treatment. The generated checks file asserts
    // the recorded and declared extents agree.
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
    // The element is a large extensible structure, so this descends into a substantial second walk rather than a
    // leaf -- including that element's own pNext.
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

TEST_CASE("One overload takes a scalar pointer and a scalar run in the same structure", "[schema]")
{
    using namespace gfxrecon::decode;

    // VkRenderingInputAttachmentIndexInfo carries a run of uint32_t and two pointers to one uint32_t, all the same
    // kind. No overload was added: the scalar-run constraint widened to either pointer shape, because
    // PointerDecoder reads its own length from the wire and one element is a run of one.
    //
    // The reference exemplar VkBindMemoryStatus reaches the same overload with kind Enum, which is the half this
    // structure does not show.
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

    // VkImageBlit2 carries two VkOffset3D[2]. The decoder is allocated as it is for any run of structures, then
    // pointed at the decoded value's own array so it decodes into that, which is the fixed-extent half of the
    // pattern applied to the structure decoder. Nothing is assigned afterwards.
    //
    // Its reference twin VkImageBlit is the same structure without sType and pNext.
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
