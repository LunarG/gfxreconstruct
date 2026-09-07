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

#include "decode/vulkan_decode_struct_impl.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"

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
// One explicit instantiation for each structure the walk owns. This is the only translation unit that
// compiles the walk, so the schema and the member-trait partitions reach no other target.
GFXRECON_BEGIN_NAMESPACE(decode)

template size_t DecodeStruct<Decoded_StdVideoAV1TileInfoFlags>(const uint8_t*, size_t, Decoded_StdVideoAV1TileInfoFlags*);
template size_t DecodeStruct<Decoded_VkAllocationCallbacks>(const uint8_t*, size_t, Decoded_VkAllocationCallbacks*);
template size_t DecodeStruct<Decoded_VkBufferMemoryBarrier>(const uint8_t*, size_t, Decoded_VkBufferMemoryBarrier*);
template size_t DecodeStruct<Decoded_VkCheckpointData2NV>(const uint8_t*, size_t, Decoded_VkCheckpointData2NV*);
template size_t DecodeStruct<Decoded_VkDebugUtilsLabelEXT>(const uint8_t*, size_t, Decoded_VkDebugUtilsLabelEXT*);
template size_t DecodeStruct<Decoded_VkDeviceBufferMemoryRequirements>(const uint8_t*, size_t, Decoded_VkDeviceBufferMemoryRequirements*);
template size_t DecodeStruct<Decoded_VkImageBlit2>(const uint8_t*, size_t, Decoded_VkImageBlit2*);
template size_t DecodeStruct<Decoded_VkImageMemoryBarrier>(const uint8_t*, size_t, Decoded_VkImageMemoryBarrier*);
template size_t DecodeStruct<Decoded_VkImageSubresourceRange>(const uint8_t*, size_t, Decoded_VkImageSubresourceRange*);
template size_t DecodeStruct<Decoded_VkLayerProperties>(const uint8_t*, size_t, Decoded_VkLayerProperties*);
template size_t DecodeStruct<Decoded_VkPipelineCacheCreateInfo>(const uint8_t*, size_t, Decoded_VkPipelineCacheCreateInfo*);
template size_t DecodeStruct<Decoded_VkRenderPassAttachmentBeginInfo>(const uint8_t*, size_t, Decoded_VkRenderPassAttachmentBeginInfo*);
template size_t DecodeStruct<Decoded_VkRenderingInputAttachmentIndexInfo>(const uint8_t*, size_t, Decoded_VkRenderingInputAttachmentIndexInfo*);
template size_t DecodeStruct<Decoded_VkShaderModuleCreateInfo>(const uint8_t*, size_t, Decoded_VkShaderModuleCreateInfo*);
template size_t DecodeStruct<Decoded_VkSparseBufferMemoryBindInfo>(const uint8_t*, size_t, Decoded_VkSparseBufferMemoryBindInfo*);
template size_t DecodeStruct<Decoded_VkTransformMatrixKHR>(const uint8_t*, size_t, Decoded_VkTransformMatrixKHR*);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
