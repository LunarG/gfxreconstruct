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

#include "encode/vulkan_resource_aliasing_writer.h"

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "util/logging.h"
#include "util/memory_output_stream.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

namespace
{

template <typename CreateInfo>
ResourceAliasingCreateInfo Encode(format::ResourceAliasingResourceType type, const CreateInfo& create_info)
{
    util::MemoryOutputStream stream;
    ParameterEncoder         encoder(&stream);

    // Encoded as a pointer, so the consumer reads it back with the generated StructPointerDecoder.
    EncodeStructPtr(&encoder, &create_info);

    return { type, std::vector<uint8_t>(stream.GetData(), stream.GetData() + stream.GetDataSize()) };
}

} // namespace

ResourceAliasingCreateInfo EncodeResourceAliasingCreateInfo(const VkBufferCreateInfo& create_info)
{
    return Encode(format::ResourceAliasingResourceType::kBuffer, create_info);
}

ResourceAliasingCreateInfo EncodeResourceAliasingCreateInfo(const VkImageCreateInfo& create_info)
{
    return Encode(format::ResourceAliasingResourceType::kImage, create_info);
}

ResourceAliasingCreateInfo EncodeResourceAliasingCreateInfo(const VkTensorCreateInfoARM& create_info)
{
    return Encode(format::ResourceAliasingResourceType::kTensor, create_info);
}

void WriteResourceAliasingGroupsCommand(util::OutputStream*                           output_stream,
                                        format::ThreadId                              thread_id,
                                        format::HandleId                              device_id,
                                        const std::vector<ResourceAliasingGroupInfo>& groups)
{
    GFXRECON_ASSERT(output_stream != nullptr);

    // The block size is only known once every create-info is encoded, so the groups are assembled here and
    // the header is written in front of them afterwards.
    util::MemoryOutputStream body;

    for (const ResourceAliasingGroupInfo& group : groups)
    {
        format::ResourceAliasingGroupHeader group_header{};
        group_header.memory_id    = group.memory_id;
        group_header.group_id     = group.group_id;
        group_header.member_count = static_cast<uint32_t>(group.members.size());
        body.Write(&group_header, sizeof(group_header));

        for (const ResourceAliasingMemberInfo& member : group.members)
        {
            // Only the EncodeResourceAliasingCreateInfo overloads set the type, so this fires when a
            // member reached the writer without one.
            GFXRECON_ASSERT(member.create_info.type != format::ResourceAliasingResourceType::kUnknown);

            format::ResourceAliasingMemberHeader member_header{};
            member_header.resource_type  = static_cast<uint32_t>(member.create_info.type);
            member_header.property_count = 1;
            member_header.resource_id    = member.resource_id;
            member_header.bind_offset    = member.bind_offset;
            body.Write(&member_header, sizeof(member_header));

            format::ResourceAliasingPropertyHeader property_header{};
            property_header.property_id   = static_cast<uint32_t>(format::ResourceAliasingPropertyId::kCreateInfo);
            property_header.property_size = static_cast<uint32_t>(member.create_info.encoded.size());
            body.Write(&property_header, sizeof(property_header));
            body.Write(member.create_info.encoded.data(), member.create_info.encoded.size());
        }
    }

    format::ResourceAliasingGroupsCommandHeader header{};
    header.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(header) + body.GetDataSize();
    header.meta_header.meta_data_id      = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan,
                                                             format::MetaDataType::kResourceAliasingGroupsCommand);
    header.thread_id                     = thread_id;
    header.device_id                     = device_id;
    header.layout_version                = format::kResourceAliasingGroupsLayoutVersion;
    header.group_count                   = static_cast<uint32_t>(groups.size());

    output_stream->Write(&header, sizeof(header));
    output_stream->Write(body.GetData(), body.GetDataSize());
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
