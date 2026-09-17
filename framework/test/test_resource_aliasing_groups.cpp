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

/// @file Resource aliasing groups meta-data block, encode -> decode round trip.

#include <catch2/catch.hpp>

#include "decode/decode_allocator.h"
#include "decode/struct_pointer_decoder.h"
#include "encode/vulkan_resource_aliasing_writer.h"
#include "format/format.h"
#include "generated/generated_vulkan_consumer.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"

#include <cstring>
#include <vector>

namespace
{

// Records what the decoder handed the consumer, so the test can compare it against what was written.
class AliasingGroupsRecorder : public gfxrecon::decode::VulkanConsumer
{
  public:
    void
    ProcessResourceAliasingGroupsCommand(gfxrecon::format::HandleId                                  device_id,
                                         const std::vector<gfxrecon::decode::ResourceAliasingGroup>& groups) override
    {
        ++call_count;
        this->device_id = device_id;
        this->groups    = groups;
    }

    uint32_t                                             call_count{ 0 };
    gfxrecon::format::HandleId                           device_id{ gfxrecon::format::kNullHandleId };
    std::vector<gfxrecon::decode::ResourceAliasingGroup> groups;
};

// The block a writer produces, and its payload: everything the decoder is handed, i.e. the block without
// its MetaDataHeader.
struct WrittenBlock
{
    std::vector<uint8_t> bytes;

    const uint8_t* Payload() const { return bytes.data() + sizeof(gfxrecon::format::MetaDataHeader); }
    size_t         PayloadSize() const { return bytes.size() - sizeof(gfxrecon::format::MetaDataHeader); }
};

WrittenBlock WriteTwoGroups()
{
    VkBufferCreateInfo buffer_create_info{};
    buffer_create_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.size  = 4096;
    buffer_create_info.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT;

    VkImageCreateInfo image_create_info{};
    image_create_info.sType       = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_create_info.imageType   = VK_IMAGE_TYPE_2D;
    image_create_info.format      = VK_FORMAT_R8G8B8A8_UNORM;
    image_create_info.extent      = { 64, 32, 1 };
    image_create_info.mipLevels   = 1;
    image_create_info.arrayLayers = 1;
    image_create_info.samples     = VK_SAMPLE_COUNT_1_BIT;
    image_create_info.usage       = VK_IMAGE_USAGE_SAMPLED_BIT;

    // Two members of different resource types at distinct bind offsets, so the round trip covers a
    // per-member offset and a per-member create-info type rather than one repeated value.
    const gfxrecon::encode::ResourceAliasingCreateInfo encoded_buffer =
        gfxrecon::encode::EncodeResourceAliasingCreateInfo(buffer_create_info);
    const gfxrecon::encode::ResourceAliasingCreateInfo encoded_image =
        gfxrecon::encode::EncodeResourceAliasingCreateInfo(image_create_info);

    gfxrecon::encode::ResourceAliasingGroupInfo group_0;
    group_0.memory_id = 12;
    group_0.group_id  = 1;
    group_0.members.push_back({ 100, 0, encoded_buffer });
    group_0.members.push_back({ 101, 2048, encoded_image });

    gfxrecon::encode::ResourceAliasingGroupInfo group_1;
    group_1.memory_id = 15;
    group_1.group_id  = 2;
    group_1.members.push_back({ 200, 4096, encoded_image });
    group_1.members.push_back({ 201, 4096, encoded_buffer });

    gfxrecon::util::MemoryOutputStream stream;
    gfxrecon::encode::WriteResourceAliasingGroupsCommand(&stream, 7, 42, { group_0, group_1 });

    WrittenBlock block;
    block.bytes.assign(stream.GetData(), stream.GetData() + stream.GetDataSize());
    return block;
}

// The first member header follows the block header fields and the first group header.
constexpr size_t kFirstMemberOffset = sizeof(gfxrecon::format::ThreadId) + sizeof(gfxrecon::format::HandleId) +
                                      sizeof(uint32_t) + sizeof(uint32_t) +
                                      sizeof(gfxrecon::format::ResourceAliasingGroupHeader);

} // namespace

TEST_CASE("A resource aliasing groups block survives an encode-decode round trip", "[optimize]")
{
    using namespace gfxrecon;

    const WrittenBlock block = WriteTwoGroups();

    format::ResourceAliasingGroupsCommandHeader header{};
    std::memcpy(&header, block.bytes.data(), sizeof(format::MetaDataHeader));

    REQUIRE(header.meta_header.block_header.type == format::BlockType::kMetaDataBlock);
    REQUIRE(header.meta_header.meta_data_id ==
            format::MakeMetaDataId(format::ApiFamily_Vulkan, format::MetaDataType::kResourceAliasingGroupsCommand));
    // BlockHeader::size counts everything after the BlockHeader, which is how a reader that does not know
    // this block type skips it.
    REQUIRE(header.meta_header.block_header.size == (block.bytes.size() - sizeof(format::BlockHeader)));

    AliasingGroupsRecorder recorder;
    decode::VulkanDecoder  decoder;
    decoder.AddConsumer(&recorder);

    decode::DecodeAllocator::Begin();
    decoder.DispatchResourceAliasingGroupsCommand(block.Payload(), block.PayloadSize());

    REQUIRE(recorder.call_count == 1);
    REQUIRE(recorder.device_id == 42);
    REQUIRE(recorder.groups.size() == 2);

    REQUIRE(recorder.groups[0].memory_id == 12);
    REQUIRE(recorder.groups[0].group_id == 1);
    REQUIRE(recorder.groups[0].members.size() == 2);

    const decode::ResourceAliasingMember& buffer_member = recorder.groups[0].members[0];
    REQUIRE(buffer_member.GetResourceType() == format::ResourceAliasingResourceType::kBuffer);
    REQUIRE(buffer_member.resource_id == 100);
    REQUIRE(buffer_member.bind_offset == 0);
    const VkBufferCreateInfo* decoded_buffer_info =
        std::get<decode::StructPointerDecoder<decode::Decoded_VkBufferCreateInfo>>(buffer_member.create_info)
            .GetPointer();
    REQUIRE(decoded_buffer_info != nullptr);
    REQUIRE(decoded_buffer_info->size == 4096);
    REQUIRE(decoded_buffer_info->usage == VK_BUFFER_USAGE_STORAGE_BUFFER_BIT);

    const decode::ResourceAliasingMember& image_member = recorder.groups[0].members[1];
    REQUIRE(image_member.GetResourceType() == format::ResourceAliasingResourceType::kImage);
    REQUIRE(image_member.resource_id == 101);
    REQUIRE(image_member.bind_offset == 2048);
    const VkImageCreateInfo* decoded_image_info =
        std::get<decode::StructPointerDecoder<decode::Decoded_VkImageCreateInfo>>(image_member.create_info)
            .GetPointer();
    REQUIRE(decoded_image_info != nullptr);
    REQUIRE(decoded_image_info->format == VK_FORMAT_R8G8B8A8_UNORM);
    REQUIRE(decoded_image_info->extent.width == 64);
    REQUIRE(decoded_image_info->extent.height == 32);

    REQUIRE(recorder.groups[1].memory_id == 15);
    REQUIRE(recorder.groups[1].group_id == 2);
    REQUIRE(recorder.groups[1].members.size() == 2);
    REQUIRE(recorder.groups[1].members[0].bind_offset == 4096);
    REQUIRE(recorder.groups[1].members[1].GetResourceType() == format::ResourceAliasingResourceType::kBuffer);

    decode::DecodeAllocator::End();
}

TEST_CASE("A resource aliasing groups block is dropped whole when it cannot be read", "[optimize]")
{
    using namespace gfxrecon;

    const WrittenBlock block = WriteTwoGroups();

    AliasingGroupsRecorder recorder;
    decode::VulkanDecoder  decoder;
    decoder.AddConsumer(&recorder);

    decode::DecodeAllocator::Begin();

    SECTION("a truncated block reaches no consumer")
    {
        decoder.DispatchResourceAliasingGroupsCommand(block.Payload(), block.PayloadSize() - 1);
        REQUIRE(recorder.call_count == 0);
    }

    SECTION("a block written by a later layout version reaches no consumer")
    {
        std::vector<uint8_t> bytes(block.Payload(), block.Payload() + block.PayloadSize());

        // layout_version follows thread_id and device_id in the payload.
        const size_t   version_offset = sizeof(format::ThreadId) + sizeof(format::HandleId);
        const uint32_t next_version   = format::kResourceAliasingGroupsLayoutVersion + 1;
        std::memcpy(bytes.data() + version_offset, &next_version, sizeof(next_version));

        decoder.DispatchResourceAliasingGroupsCommand(bytes.data(), bytes.size());
        REQUIRE(recorder.call_count == 0);
    }

    decode::DecodeAllocator::End();
}

TEST_CASE("A resource aliasing groups block with an unrecognized resource type is dropped", "[optimize]")
{
    using namespace gfxrecon;

    const WrittenBlock   block = WriteTwoGroups();
    std::vector<uint8_t> bytes(block.Payload(), block.Payload() + block.PayloadSize());

    format::ResourceAliasingMemberHeader member_header{};
    std::memcpy(&member_header, bytes.data() + kFirstMemberOffset, sizeof(member_header));
    REQUIRE(member_header.resource_id == 100);

    // kUnknown is what a member whose create-info was never filled in carries, and it is also what a
    // resource type added later looks like to this reader.
    member_header.resource_type = static_cast<uint32_t>(format::ResourceAliasingResourceType::kUnknown);
    std::memcpy(bytes.data() + kFirstMemberOffset, &member_header, sizeof(member_header));

    AliasingGroupsRecorder recorder;
    decode::VulkanDecoder  decoder;
    decoder.AddConsumer(&recorder);

    decode::DecodeAllocator::Begin();
    decoder.DispatchResourceAliasingGroupsCommand(bytes.data(), bytes.size());
    REQUIRE(recorder.call_count == 0);
    decode::DecodeAllocator::End();
}

TEST_CASE("A resource aliasing groups member skips a property it does not know", "[optimize]")
{
    using namespace gfxrecon;

    const WrittenBlock block = WriteTwoGroups();

    // Splice an unknown property into the first member, in front of its create-info, and bump the member's
    // property count.  A reader of a later layout version writes exactly this.

    std::vector<uint8_t> bytes(block.Payload(), block.Payload() + block.PayloadSize());

    format::ResourceAliasingMemberHeader member_header{};
    std::memcpy(&member_header, bytes.data() + kFirstMemberOffset, sizeof(member_header));
    REQUIRE(member_header.resource_id == 100);
    REQUIRE(member_header.property_count == 1);

    member_header.property_count = 2;
    std::memcpy(bytes.data() + kFirstMemberOffset, &member_header, sizeof(member_header));

    const std::vector<uint8_t>             unknown_payload{ 0xde, 0xad, 0xbe, 0xef, 0x01, 0x02 };
    format::ResourceAliasingPropertyHeader unknown_header{};
    unknown_header.property_id   = 0xffff;
    unknown_header.property_size = static_cast<uint32_t>(unknown_payload.size());

    const size_t         properties_offset = kFirstMemberOffset + sizeof(member_header);
    std::vector<uint8_t> unknown_property(sizeof(unknown_header) + unknown_payload.size());
    std::memcpy(unknown_property.data(), &unknown_header, sizeof(unknown_header));
    std::memcpy(unknown_property.data() + sizeof(unknown_header), unknown_payload.data(), unknown_payload.size());
    bytes.insert(bytes.begin() + properties_offset, unknown_property.begin(), unknown_property.end());

    AliasingGroupsRecorder recorder;
    decode::VulkanDecoder  decoder;
    decoder.AddConsumer(&recorder);

    decode::DecodeAllocator::Begin();
    decoder.DispatchResourceAliasingGroupsCommand(bytes.data(), bytes.size());

    REQUIRE(recorder.call_count == 1);
    REQUIRE(recorder.groups.size() == 2);
    REQUIRE(recorder.groups[0].members.size() == 2);

    // The unknown property is skipped by its length, so the create-info behind it still decodes.
    const decode::ResourceAliasingMember& buffer_member = recorder.groups[0].members[0];
    REQUIRE(buffer_member.resource_id == 100);
    const VkBufferCreateInfo* decoded_buffer_info =
        std::get<decode::StructPointerDecoder<decode::Decoded_VkBufferCreateInfo>>(buffer_member.create_info)
            .GetPointer();
    REQUIRE(decoded_buffer_info != nullptr);
    REQUIRE(decoded_buffer_info->size == 4096);

    // The members and groups behind the spliced property are unaffected.
    REQUIRE(recorder.groups[0].members[1].resource_id == 101);
    REQUIRE(recorder.groups[1].members[1].resource_id == 201);

    decode::DecodeAllocator::End();
}
