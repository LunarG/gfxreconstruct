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

#ifndef GFXRECON_DECODE_VULKAN_DECODER_ARGS_H
#define GFXRECON_DECODE_VULKAN_DECODER_ARGS_H

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/vulkan_pnext_node.h"
#include "format/format.h"
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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(args)

struct UpdateDescriptorSetWithTemplate
{
    format::HandleId                device;
    format::HandleId                descriptorSet;
    format::HandleId                descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;
};

struct UpdateDescriptorSetWithTemplateKHR
{
    format::HandleId                device;
    format::HandleId                descriptorSet;
    format::HandleId                descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;
};

struct CmdPushDescriptorSetWithTemplateKHR
{
    format::HandleId                commandBuffer;
    format::HandleId                descriptorUpdateTemplate;
    format::HandleId                layout;
    uint32_t                        set;
    DescriptorUpdateTemplateDecoder pData;
};

struct CmdPushDescriptorSetWithTemplate2KHR
{
    format::HandleId                                                  commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfo> pPushDescriptorSetWithTemplateInfo;
};

struct CreateRayTracingPipelinesKHR
{
    VkResult                                                        result;
    format::HandleId                                                device;
    format::HandleId                                                deferredOperation;
    format::HandleId                                                pipelineCache;
    uint32_t                                                        createInfoCount;
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks>             pAllocator;
    HandlePointerDecoder<VkPipeline>                                pPipelines;
};

struct DeferredOperationJoinKHR
{
    VkResult         result;
    format::HandleId device;
    format::HandleId operation;
};

GFXRECON_END_NAMESPACE(args)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODER_ARGS_H
