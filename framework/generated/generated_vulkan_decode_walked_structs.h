/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_DECODE_WALKED_STRUCTS_H
#define  GFXRECON_GENERATED_VULKAN_DECODE_WALKED_STRUCTS_H

#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"
#include "util/type_list.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#ifdef WIN32
#ifdef CreateEvent
#undef CreateEvent
#endif
#ifdef CreateSemaphore
#undef CreateSemaphore
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
// The structures whose DecodeStruct is the schema field walk. The broadly declared template is
// constrained on this, so a wrapper with no instantiation fails at the call naming its type rather
// than at the link naming a mangled symbol.
//
// The list is generated from the same constant that decides which procedural bodies to skip. See the
// warning on SCHEMA_OWNED_STRUCT_DECODERS for how the three derived artifacts can disagree.
GFXRECON_BEGIN_NAMESPACE(decode)

using WalkedStructs = util::TypeList<
    Decoded_StdVideoAV1TileInfoFlags,
    Decoded_VkAllocationCallbacks,
    Decoded_VkBufferMemoryBarrier,
    Decoded_VkCheckpointData2NV,
    Decoded_VkDebugUtilsLabelEXT,
    Decoded_VkDeviceBufferMemoryRequirements,
    Decoded_VkImageBlit2,
    Decoded_VkImageMemoryBarrier,
    Decoded_VkImageSubresourceRange,
    Decoded_VkLayerProperties,
    Decoded_VkPipelineCacheCreateInfo,
    Decoded_VkRenderPassAttachmentBeginInfo,
    Decoded_VkRenderingInputAttachmentIndexInfo,
    Decoded_VkShaderModuleCreateInfo,
    Decoded_VkSparseBufferMemoryBindInfo,
    Decoded_VkTransformMatrixKHR
>;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_DECODE_WALKED_STRUCTS_H
