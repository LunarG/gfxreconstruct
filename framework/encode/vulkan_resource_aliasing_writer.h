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

#ifndef GFXRECON_ENCODE_VULKAN_RESOURCE_ALIASING_WRITER_H
#define GFXRECON_ENCODE_VULKAN_RESOURCE_ALIASING_WRITER_H

#include "format/format.h"
#include "util/defines.h"
#include "util/output_stream.h"

#include "vulkan/vulkan.h"

#include <variant>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

/**
 * @brief   The create-info of one aliasing group member.
 *
 * The alternative held is the member's resource type, so the two cannot disagree.  The pointed-to
 * struct, including its pNext chain, must outlive the write.
 */
using ResourceAliasingCreateInfo =
    std::variant<const VkBufferCreateInfo*, const VkImageCreateInfo*, const VkTensorCreateInfoARM*>;

/**
 * @brief   One resource of an aliasing group, as handed to the writer.
 */
struct ResourceAliasingMemberInfo
{
    format::HandleId           resource_id{ format::kNullHandleId };
    uint64_t                   bind_offset{ 0 };
    ResourceAliasingCreateInfo create_info;
};

/**
 * @brief   A set of resources that alias one another inside one device memory object.
 */
struct ResourceAliasingGroupInfo
{
    format::HandleId                        memory_id{ format::kNullHandleId };
    uint32_t                                group_id{ 0 };
    std::vector<ResourceAliasingMemberInfo> members;
};

/**
 * @brief   Write a resource aliasing groups meta-data block.
 *
 * The block belongs after the vkCreateDevice of the device it describes, because its consumer queries
 * the replay memory requirements of every member on that device.  It is written uncompressed.
 *
 * @param   output_stream  the stream the complete block is written to.
 * @param   thread_id      the thread the block is attributed to, matching the vkCreateDevice it follows.
 * @param   device_id      the capture handle id of the device the groups belong to.
 * @param   groups         the groups to write, each with at least two members.
 */
void WriteResourceAliasingGroupsCommand(util::OutputStream*                           output_stream,
                                        format::ThreadId                              thread_id,
                                        format::HandleId                              device_id,
                                        const std::vector<ResourceAliasingGroupInfo>& groups);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_RESOURCE_ALIASING_WRITER_H
