/*
** Copyright (c) 2020 Samsung
** Copyright (c) 2023 Google
** Copyright (c) 2023 LunarG, Inc.
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

#include "generated/generated_vulkan_cpp_consumer.h"

#include "decode/vulkan_cpp_consumer_base.h"
#include "decode/vulkan_cpp_structs.h"
#include "generated/generated_vulkan_cpp_structs.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"
#include "format/packet_call_id.h"
#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <iostream>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Packet_vkAllocateCommandBuffers
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo> pAllocateInfo;
    HandlePointerDecoder<VkCommandBuffer>       pCommandBuffers;
};


struct Packet_vkAllocateDescriptorSets
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo> pAllocateInfo;
    HandlePointerDecoder<VkDescriptorSet>       pDescriptorSets;
};


struct Packet_vkAllocateMemory
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo> pAllocateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDeviceMemory>        pMemory;
};


struct Packet_vkBeginCommandBuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo> pBeginInfo;
};


struct Packet_vkBindBufferMemory
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            buffer;
    format::HandleId                            memory;
    VkDeviceSize                                memoryOffset;
};


struct Packet_vkBindImageMemory
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            image;
    format::HandleId                            memory;
    VkDeviceSize                                memoryOffset;
};


struct Packet_vkCmdBeginQuery
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            queryPool;
    uint32_t                                    query;
    VkQueryControlFlags                         flags;
};


struct Packet_vkCmdBeginRenderPass
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    VkSubpassContents                           contents;
};


struct Packet_vkCmdBindDescriptorSets
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineBindPoint                         pipelineBindPoint;
    format::HandleId                            layout;
    uint32_t                                    firstSet;
    uint32_t                                    descriptorSetCount;
    HandlePointerDecoder<VkDescriptorSet>       pDescriptorSets;
    uint32_t                                    dynamicOffsetCount;
    PointerDecoder<uint32_t>                    pDynamicOffsets;
};


struct Packet_vkCmdBindIndexBuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    VkIndexType                                 indexType;
};


struct Packet_vkCmdBindPipeline
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineBindPoint                         pipelineBindPoint;
    format::HandleId                            pipeline;
};


struct Packet_vkCmdBindVertexBuffers
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstBinding;
    uint32_t                                    bindingCount;
    HandlePointerDecoder<VkBuffer>              pBuffers;
    PointerDecoder<VkDeviceSize>                pOffsets;
};


struct Packet_vkCmdBlitImage
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            srcImage;
    VkImageLayout                               srcImageLayout;
    format::HandleId                            dstImage;
    VkImageLayout                               dstImageLayout;
    uint32_t                                    regionCount;
    StructPointerDecoder<Decoded_VkImageBlit>   pRegions;
    VkFilter                                    filter;
};


struct Packet_vkCmdClearAttachments
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    attachmentCount;
    StructPointerDecoder<Decoded_VkClearAttachment> pAttachments;
    uint32_t                                    rectCount;
    StructPointerDecoder<Decoded_VkClearRect>   pRects;
};


struct Packet_vkCmdClearColorImage
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            image;
    VkImageLayout                               imageLayout;
    StructPointerDecoder<Decoded_VkClearColorValue> pColor;
    uint32_t                                    rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;
};


struct Packet_vkCmdClearDepthStencilImage
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            image;
    VkImageLayout                               imageLayout;
    StructPointerDecoder<Decoded_VkClearDepthStencilValue> pDepthStencil;
    uint32_t                                    rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;
};


struct Packet_vkCmdCopyBuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            srcBuffer;
    format::HandleId                            dstBuffer;
    uint32_t                                    regionCount;
    StructPointerDecoder<Decoded_VkBufferCopy>  pRegions;
};


struct Packet_vkCmdCopyBufferToImage
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            srcBuffer;
    format::HandleId                            dstImage;
    VkImageLayout                               dstImageLayout;
    uint32_t                                    regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;
};


struct Packet_vkCmdCopyImage
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            srcImage;
    VkImageLayout                               srcImageLayout;
    format::HandleId                            dstImage;
    VkImageLayout                               dstImageLayout;
    uint32_t                                    regionCount;
    StructPointerDecoder<Decoded_VkImageCopy>   pRegions;
};


struct Packet_vkCmdCopyImageToBuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            srcImage;
    VkImageLayout                               srcImageLayout;
    format::HandleId                            dstBuffer;
    uint32_t                                    regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;
};


struct Packet_vkCmdCopyQueryPoolResults
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            queryPool;
    uint32_t                                    firstQuery;
    uint32_t                                    queryCount;
    format::HandleId                            dstBuffer;
    VkDeviceSize                                dstOffset;
    VkDeviceSize                                stride;
    VkQueryResultFlags                          flags;
};


struct Packet_vkCmdDispatch
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    groupCountX;
    uint32_t                                    groupCountY;
    uint32_t                                    groupCountZ;
};


struct Packet_vkCmdDispatchIndirect
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
};


struct Packet_vkCmdDraw
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    vertexCount;
    uint32_t                                    instanceCount;
    uint32_t                                    firstVertex;
    uint32_t                                    firstInstance;
};


struct Packet_vkCmdDrawIndexed
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    indexCount;
    uint32_t                                    instanceCount;
    uint32_t                                    firstIndex;
    int32_t                                     vertexOffset;
    uint32_t                                    firstInstance;
};


struct Packet_vkCmdDrawIndexedIndirect
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    uint32_t                                    drawCount;
    uint32_t                                    stride;
};


struct Packet_vkCmdDrawIndirect
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    uint32_t                                    drawCount;
    uint32_t                                    stride;
};


struct Packet_vkCmdEndQuery
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            queryPool;
    uint32_t                                    query;
};


struct Packet_vkCmdEndRenderPass
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
};


struct Packet_vkCmdExecuteCommands
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    commandBufferCount;
    HandlePointerDecoder<VkCommandBuffer>       pCommandBuffers;
};


struct Packet_vkCmdFillBuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            dstBuffer;
    VkDeviceSize                                dstOffset;
    VkDeviceSize                                size;
    uint32_t                                    data;
};


struct Packet_vkCmdNextSubpass
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkSubpassContents                           contents;
};


struct Packet_vkCmdPipelineBarrier
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineStageFlags                        srcStageMask;
    VkPipelineStageFlags                        dstStageMask;
    VkDependencyFlags                           dependencyFlags;
    uint32_t                                    memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t                                    bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t                                    imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;
};


struct Packet_vkCmdPushConstants
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            layout;
    VkShaderStageFlags                          stageFlags;
    uint32_t                                    offset;
    uint32_t                                    size;
    PointerDecoder<uint8_t>                     pValues;
};


struct Packet_vkCmdResetEvent
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            event;
    VkPipelineStageFlags                        stageMask;
};


struct Packet_vkCmdResetQueryPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            queryPool;
    uint32_t                                    firstQuery;
    uint32_t                                    queryCount;
};


struct Packet_vkCmdResolveImage
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            srcImage;
    VkImageLayout                               srcImageLayout;
    format::HandleId                            dstImage;
    VkImageLayout                               dstImageLayout;
    uint32_t                                    regionCount;
    StructPointerDecoder<Decoded_VkImageResolve> pRegions;
};


struct Packet_vkCmdSetBlendConstants
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    PointerDecoder<float>                       blendConstants;
};


struct Packet_vkCmdSetDepthBias
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    float                                       depthBiasConstantFactor;
    float                                       depthBiasClamp;
    float                                       depthBiasSlopeFactor;
};


struct Packet_vkCmdSetDepthBounds
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    float                                       minDepthBounds;
    float                                       maxDepthBounds;
};


struct Packet_vkCmdSetEvent
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            event;
    VkPipelineStageFlags                        stageMask;
};


struct Packet_vkCmdSetLineWidth
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    float                                       lineWidth;
};


struct Packet_vkCmdSetScissor
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstScissor;
    uint32_t                                    scissorCount;
    StructPointerDecoder<Decoded_VkRect2D>      pScissors;
};


struct Packet_vkCmdSetStencilCompareMask
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkStencilFaceFlags                          faceMask;
    uint32_t                                    compareMask;
};


struct Packet_vkCmdSetStencilReference
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkStencilFaceFlags                          faceMask;
    uint32_t                                    reference;
};


struct Packet_vkCmdSetStencilWriteMask
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkStencilFaceFlags                          faceMask;
    uint32_t                                    writeMask;
};


struct Packet_vkCmdSetViewport
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstViewport;
    uint32_t                                    viewportCount;
    StructPointerDecoder<Decoded_VkViewport>    pViewports;
};


struct Packet_vkCmdUpdateBuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            dstBuffer;
    VkDeviceSize                                dstOffset;
    VkDeviceSize                                dataSize;
    PointerDecoder<uint8_t>                     pData;
};


struct Packet_vkCmdWaitEvents
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    eventCount;
    HandlePointerDecoder<VkEvent>               pEvents;
    VkPipelineStageFlags                        srcStageMask;
    VkPipelineStageFlags                        dstStageMask;
    uint32_t                                    memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t                                    bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t                                    imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;
};


struct Packet_vkCmdWriteTimestamp
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineStageFlagBits                     pipelineStage;
    format::HandleId                            queryPool;
    uint32_t                                    query;
};


struct Packet_vkCreateBuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkBufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkBuffer>              pBuffer;
};


struct Packet_vkCreateBufferView
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkBufferView>          pView;
};


struct Packet_vkCreateCommandPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkCommandPool>         pCommandPool;
};


struct Packet_vkCreateComputePipelines
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            pipelineCache;
    uint32_t                                    createInfoCount;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipeline>            pPipelines;
};


struct Packet_vkCreateDescriptorPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorPool>      pDescriptorPool;
};


struct Packet_vkCreateDescriptorSetLayout
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayout;
};


struct Packet_vkCreateDevice
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDevice>              pDevice;
};


struct Packet_vkCreateEvent
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkEventCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkEvent>               pEvent;
};


struct Packet_vkCreateFence
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkFenceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence>               pFence;
};


struct Packet_vkCreateFramebuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFramebuffer>         pFramebuffer;
};


struct Packet_vkCreateGraphicsPipelines
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            pipelineCache;
    uint32_t                                    createInfoCount;
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipeline>            pPipelines;
};


struct Packet_vkCreateImage
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImageCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkImage>               pImage;
};


struct Packet_vkCreateImageView
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImageViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkImageView>           pView;
};


struct Packet_vkCreateInstance
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    StructPointerDecoder<Decoded_VkInstanceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkInstance>            pInstance;
};


struct Packet_vkCreatePipelineCache
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipelineCache>       pPipelineCache;
};


struct Packet_vkCreatePipelineLayout
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipelineLayout>      pPipelineLayout;
};


struct Packet_vkCreateQueryPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkQueryPool>           pQueryPool;
};


struct Packet_vkCreateRenderPass
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass>          pRenderPass;
};


struct Packet_vkCreateSampler
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSamplerCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSampler>             pSampler;
};


struct Packet_vkCreateSemaphore
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSemaphore>           pSemaphore;
};


struct Packet_vkCreateShaderModule
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkShaderModule>        pShaderModule;
};


struct Packet_vkDestroyBuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            buffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyBufferView
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            bufferView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyCommandPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            commandPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyDescriptorPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            descriptorPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyDescriptorSetLayout
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            descriptorSetLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyDevice
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyEvent
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            event;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyFence
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            fence;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyFramebuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            framebuffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyImage
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            image;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyImageView
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            imageView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyInstance
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyPipeline
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            pipeline;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyPipelineCache
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            pipelineCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyPipelineLayout
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            pipelineLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyQueryPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            queryPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyRenderPass
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            renderPass;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroySampler
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            sampler;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroySemaphore
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            semaphore;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyShaderModule
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            shaderModule;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDeviceWaitIdle
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
};


struct Packet_vkEndCommandBuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            commandBuffer;
};


struct Packet_vkEnumeratePhysicalDevices
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    PointerDecoder<uint32_t>                    pPhysicalDeviceCount;
    HandlePointerDecoder<VkPhysicalDevice>      pPhysicalDevices;
};


struct Packet_vkFlushMappedMemoryRanges
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
};


struct Packet_vkFreeCommandBuffers
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            commandPool;
    uint32_t                                    commandBufferCount;
    HandlePointerDecoder<VkCommandBuffer>       pCommandBuffers;
};


struct Packet_vkFreeDescriptorSets
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            descriptorPool;
    uint32_t                                    descriptorSetCount;
    HandlePointerDecoder<VkDescriptorSet>       pDescriptorSets;
};


struct Packet_vkFreeMemory
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            memory;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetBufferMemoryRequirements
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            buffer;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;
};


struct Packet_vkGetDeviceMemoryCommitment
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            memory;
    PointerDecoder<VkDeviceSize>                pCommittedMemoryInBytes;
};


struct Packet_vkGetDeviceQueue
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    uint32_t                                    queueFamilyIndex;
    uint32_t                                    queueIndex;
    HandlePointerDecoder<VkQueue>               pQueue;
};


struct Packet_vkGetEventStatus
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            event;
};


struct Packet_vkGetFenceStatus
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            fence;
};


struct Packet_vkGetImageMemoryRequirements
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            image;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;
};


struct Packet_vkGetImageSparseMemoryRequirements
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            image;
    PointerDecoder<uint32_t>                    pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements> pSparseMemoryRequirements;
};


struct Packet_vkGetImageSubresourceLayout
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            image;
    StructPointerDecoder<Decoded_VkImageSubresource> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout> pLayout;
};


struct Packet_vkGetPhysicalDeviceFeatures
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pFeatures;
};


struct Packet_vkGetPhysicalDeviceFormatProperties
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    VkFormat                                    format;
    StructPointerDecoder<Decoded_VkFormatProperties> pFormatProperties;
};


struct Packet_vkGetPhysicalDeviceImageFormatProperties
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    VkFormat                                    format;
    VkImageType                                 type;
    VkImageTiling                               tiling;
    VkImageUsageFlags                           usage;
    VkImageCreateFlags                          flags;
    StructPointerDecoder<Decoded_VkImageFormatProperties> pImageFormatProperties;
};


struct Packet_vkGetPhysicalDeviceMemoryProperties
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties> pMemoryProperties;
};


struct Packet_vkGetPhysicalDeviceProperties
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties> pProperties;
};


struct Packet_vkGetPhysicalDeviceQueueFamilyProperties
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties> pQueueFamilyProperties;
};


struct Packet_vkGetPhysicalDeviceSparseImageFormatProperties
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    VkFormat                                    format;
    VkImageType                                 type;
    VkSampleCountFlagBits                       samples;
    VkImageUsageFlags                           usage;
    VkImageTiling                               tiling;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties> pProperties;
};


struct Packet_vkGetPipelineCacheData
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            pipelineCache;
    PointerDecoder<size_t>                      pDataSize;
    PointerDecoder<uint8_t>                     pData;
};


struct Packet_vkGetQueryPoolResults
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            queryPool;
    uint32_t                                    firstQuery;
    uint32_t                                    queryCount;
    size_t                                      dataSize;
    PointerDecoder<uint8_t>                     pData;
    VkDeviceSize                                stride;
    VkQueryResultFlags                          flags;
};


struct Packet_vkGetRenderAreaGranularity
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            renderPass;
    StructPointerDecoder<Decoded_VkExtent2D>    pGranularity;
};


struct Packet_vkInvalidateMappedMemoryRanges
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
};


struct Packet_vkMapMemory
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            memory;
    VkDeviceSize                                offset;
    VkDeviceSize                                size;
    VkMemoryMapFlags                            flags;
    PointerDecoder<uint64_t, void*>             ppData;
};


struct Packet_vkMergePipelineCaches
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            dstCache;
    uint32_t                                    srcCacheCount;
    HandlePointerDecoder<VkPipelineCache>       pSrcCaches;
};


struct Packet_vkQueueBindSparse
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            queue;
    uint32_t                                    bindInfoCount;
    StructPointerDecoder<Decoded_VkBindSparseInfo> pBindInfo;
    format::HandleId                            fence;
};


struct Packet_vkQueueSubmit
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            queue;
    uint32_t                                    submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo>  pSubmits;
    format::HandleId                            fence;
};


struct Packet_vkQueueWaitIdle
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            queue;
};


struct Packet_vkResetCommandBuffer
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            commandBuffer;
    VkCommandBufferResetFlags                   flags;
};


struct Packet_vkResetCommandPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            commandPool;
    VkCommandPoolResetFlags                     flags;
};


struct Packet_vkResetDescriptorPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            descriptorPool;
    VkDescriptorPoolResetFlags                  flags;
};


struct Packet_vkResetEvent
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            event;
};


struct Packet_vkResetFences
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    fenceCount;
    HandlePointerDecoder<VkFence>               pFences;
};


struct Packet_vkSetEvent
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            event;
};


struct Packet_vkUnmapMemory
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            memory;
};


struct Packet_vkUpdateDescriptorSets
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    uint32_t                                    descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;
    uint32_t                                    descriptorCopyCount;
    StructPointerDecoder<Decoded_VkCopyDescriptorSet> pDescriptorCopies;
};


struct Packet_vkWaitForFences
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    fenceCount;
    HandlePointerDecoder<VkFence>               pFences;
    VkBool32                                    waitAll;
    uint64_t                                    timeout;
};

struct Packet_vkBindBufferMemory2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
};


struct Packet_vkBindImageMemory2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
};


struct Packet_vkCmdDispatchBase
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    baseGroupX;
    uint32_t                                    baseGroupY;
    uint32_t                                    baseGroupZ;
    uint32_t                                    groupCountX;
    uint32_t                                    groupCountY;
    uint32_t                                    groupCountZ;
};


struct Packet_vkCmdSetDeviceMask
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    deviceMask;
};


struct Packet_vkCreateDescriptorUpdateTemplate
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;
};


struct Packet_vkCreateSamplerYcbcrConversion
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;
};


struct Packet_vkDestroyDescriptorUpdateTemplate
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroySamplerYcbcrConversion
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkEnumeratePhysicalDeviceGroups
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    PointerDecoder<uint32_t>                    pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
};


struct Packet_vkGetBufferMemoryRequirements2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;
};


struct Packet_vkGetDescriptorSetLayoutSupport
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;
};


struct Packet_vkGetDeviceGroupPeerMemoryFeatures
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    uint32_t                                    heapIndex;
    uint32_t                                    localDeviceIndex;
    uint32_t                                    remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags>    pPeerMemoryFeatures;
};


struct Packet_vkGetDeviceQueue2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2> pQueueInfo;
    HandlePointerDecoder<VkQueue>               pQueue;
};


struct Packet_vkGetImageMemoryRequirements2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;
};


struct Packet_vkGetImageSparseMemoryRequirements2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t>                    pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;
};


struct Packet_vkGetPhysicalDeviceExternalBufferProperties
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;
};


struct Packet_vkGetPhysicalDeviceExternalFenceProperties
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;
};


struct Packet_vkGetPhysicalDeviceExternalSemaphoreProperties
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;
};


struct Packet_vkGetPhysicalDeviceFeatures2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;
};


struct Packet_vkGetPhysicalDeviceFormatProperties2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    VkFormat                                    format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;
};


struct Packet_vkGetPhysicalDeviceImageFormatProperties2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
};


struct Packet_vkGetPhysicalDeviceMemoryProperties2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;
};


struct Packet_vkGetPhysicalDeviceProperties2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;
};


struct Packet_vkGetPhysicalDeviceQueueFamilyProperties2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;
};


struct Packet_vkGetPhysicalDeviceSparseImageFormatProperties2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;
};


struct Packet_vkTrimCommandPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            commandPool;
    VkCommandPoolTrimFlags                      flags;
};

struct Packet_vkCmdBeginRenderPass2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
};


struct Packet_vkCmdDrawIndexedIndirectCount
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    format::HandleId                            countBuffer;
    VkDeviceSize                                countBufferOffset;
    uint32_t                                    maxDrawCount;
    uint32_t                                    stride;
};


struct Packet_vkCmdDrawIndirectCount
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    format::HandleId                            countBuffer;
    VkDeviceSize                                countBufferOffset;
    uint32_t                                    maxDrawCount;
    uint32_t                                    stride;
};


struct Packet_vkCmdEndRenderPass2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;
};


struct Packet_vkCmdNextSubpass2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;
};


struct Packet_vkCreateRenderPass2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass>          pRenderPass;
};


struct Packet_vkGetBufferDeviceAddress
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkDeviceAddress                             return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
};


struct Packet_vkGetBufferOpaqueCaptureAddress
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    uint64_t                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
};


struct Packet_vkGetDeviceMemoryOpaqueCaptureAddress
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    uint64_t                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo> pInfo;
};


struct Packet_vkGetSemaphoreCounterValue
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            semaphore;
    PointerDecoder<uint64_t>                    pValue;
};


struct Packet_vkResetQueryPool
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            queryPool;
    uint32_t                                    firstQuery;
    uint32_t                                    queryCount;
};


struct Packet_vkSignalSemaphore
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo> pSignalInfo;
};


struct Packet_vkWaitSemaphores
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo> pWaitInfo;
    uint64_t                                    timeout;
};

struct Packet_vkCmdBeginRendering
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;
};


struct Packet_vkCmdBindVertexBuffers2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstBinding;
    uint32_t                                    bindingCount;
    HandlePointerDecoder<VkBuffer>              pBuffers;
    PointerDecoder<VkDeviceSize>                pOffsets;
    PointerDecoder<VkDeviceSize>                pSizes;
    PointerDecoder<VkDeviceSize>                pStrides;
};


struct Packet_vkCmdBlitImage2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkBlitImageInfo2> pBlitImageInfo;
};


struct Packet_vkCmdCopyBuffer2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferInfo2> pCopyBufferInfo;
};


struct Packet_vkCmdCopyBufferToImage2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2> pCopyBufferToImageInfo;
};


struct Packet_vkCmdCopyImage2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageInfo2> pCopyImageInfo;
};


struct Packet_vkCmdCopyImageToBuffer2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2> pCopyImageToBufferInfo;
};


struct Packet_vkCmdEndRendering
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
};


struct Packet_vkCmdPipelineBarrier2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;
};


struct Packet_vkCmdResetEvent2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            event;
    VkPipelineStageFlags2                       stageMask;
};


struct Packet_vkCmdResolveImage2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkResolveImageInfo2> pResolveImageInfo;
};


struct Packet_vkCmdSetCullMode
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkCullModeFlags                             cullMode;
};


struct Packet_vkCmdSetDepthBiasEnable
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    depthBiasEnable;
};


struct Packet_vkCmdSetDepthBoundsTestEnable
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    depthBoundsTestEnable;
};


struct Packet_vkCmdSetDepthCompareOp
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkCompareOp                                 depthCompareOp;
};


struct Packet_vkCmdSetDepthTestEnable
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    depthTestEnable;
};


struct Packet_vkCmdSetDepthWriteEnable
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    depthWriteEnable;
};


struct Packet_vkCmdSetEvent2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            event;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;
};


struct Packet_vkCmdSetFrontFace
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkFrontFace                                 frontFace;
};


struct Packet_vkCmdSetPrimitiveRestartEnable
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    primitiveRestartEnable;
};


struct Packet_vkCmdSetPrimitiveTopology
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPrimitiveTopology                         primitiveTopology;
};


struct Packet_vkCmdSetRasterizerDiscardEnable
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    rasterizerDiscardEnable;
};


struct Packet_vkCmdSetScissorWithCount
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    scissorCount;
    StructPointerDecoder<Decoded_VkRect2D>      pScissors;
};


struct Packet_vkCmdSetStencilOp
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkStencilFaceFlags                          faceMask;
    VkStencilOp                                 failOp;
    VkStencilOp                                 passOp;
    VkStencilOp                                 depthFailOp;
    VkCompareOp                                 compareOp;
};


struct Packet_vkCmdSetStencilTestEnable
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    stencilTestEnable;
};


struct Packet_vkCmdSetViewportWithCount
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    viewportCount;
    StructPointerDecoder<Decoded_VkViewport>    pViewports;
};


struct Packet_vkCmdWaitEvents2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    eventCount;
    HandlePointerDecoder<VkEvent>               pEvents;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfos;
};


struct Packet_vkCmdWriteTimestamp2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineStageFlags2                       stage;
    format::HandleId                            queryPool;
    uint32_t                                    query;
};


struct Packet_vkCreatePrivateDataSlot
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlot>     pPrivateDataSlot;
};


struct Packet_vkDestroyPrivateDataSlot
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            privateDataSlot;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetDeviceBufferMemoryRequirements
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;
};


struct Packet_vkGetDeviceImageMemoryRequirements
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;
};


struct Packet_vkGetDeviceImageSparseMemoryRequirements
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    PointerDecoder<uint32_t>                    pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;
};


struct Packet_vkGetPhysicalDeviceToolProperties
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties> pToolProperties;
};


struct Packet_vkGetPrivateData
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    VkObjectType                                objectType;
    uint64_t                                    objectHandle;
    format::HandleId                            privateDataSlot;
    PointerDecoder<uint64_t>                    pData;
};


struct Packet_vkQueueSubmit2
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            queue;
    uint32_t                                    submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo2> pSubmits;
    format::HandleId                            fence;
};


struct Packet_vkSetPrivateData
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    VkObjectType                                objectType;
    uint64_t                                    objectHandle;
    format::HandleId                            privateDataSlot;
    uint64_t                                    data;
};

struct Packet_vkDestroySurfaceKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            instance;
    format::HandleId                            surface;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR> pSurfaceCapabilities;
};


struct Packet_vkGetPhysicalDeviceSurfaceFormatsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            surface;
    PointerDecoder<uint32_t>                    pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR> pSurfaceFormats;
};


struct Packet_vkGetPhysicalDeviceSurfacePresentModesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            surface;
    PointerDecoder<uint32_t>                    pPresentModeCount;
    PointerDecoder<VkPresentModeKHR>            pPresentModes;
};


struct Packet_vkGetPhysicalDeviceSurfaceSupportKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    uint32_t                                    queueFamilyIndex;
    format::HandleId                            surface;
    PointerDecoder<VkBool32>                    pSupported;
};

struct Packet_vkAcquireNextImage2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR> pAcquireInfo;
    PointerDecoder<uint32_t>                    pImageIndex;
};


struct Packet_vkAcquireNextImageKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    uint64_t                                    timeout;
    format::HandleId                            semaphore;
    format::HandleId                            fence;
    PointerDecoder<uint32_t>                    pImageIndex;
};


struct Packet_vkCreateSwapchainKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSwapchainKHR>        pSwapchain;
};


struct Packet_vkDestroySwapchainKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetDeviceGroupPresentCapabilitiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR> pDeviceGroupPresentCapabilities;
};


struct Packet_vkGetDeviceGroupSurfacePresentModesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            surface;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;
};


struct Packet_vkGetPhysicalDevicePresentRectanglesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            surface;
    PointerDecoder<uint32_t>                    pRectCount;
    StructPointerDecoder<Decoded_VkRect2D>      pRects;
};


struct Packet_vkGetSwapchainImagesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    PointerDecoder<uint32_t>                    pSwapchainImageCount;
    HandlePointerDecoder<VkImage>               pSwapchainImages;
};


struct Packet_vkQueuePresentKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            queue;
    StructPointerDecoder<Decoded_VkPresentInfoKHR> pPresentInfo;
};

struct Packet_vkCreateDisplayModeKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            display;
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDisplayModeKHR>      pMode;
};


struct Packet_vkCreateDisplayPlaneSurfaceKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};


struct Packet_vkGetDisplayModePropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            display;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR> pProperties;
};


struct Packet_vkGetDisplayPlaneCapabilitiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            mode;
    uint32_t                                    planeIndex;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR> pCapabilities;
};


struct Packet_vkGetDisplayPlaneSupportedDisplaysKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    uint32_t                                    planeIndex;
    PointerDecoder<uint32_t>                    pDisplayCount;
    HandlePointerDecoder<VkDisplayKHR>          pDisplays;
};


struct Packet_vkGetPhysicalDeviceDisplayPlanePropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR> pProperties;
};


struct Packet_vkGetPhysicalDeviceDisplayPropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR> pProperties;
};

struct Packet_vkCreateSharedSwapchainsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    swapchainCount;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSwapchainKHR>        pSwapchains;
};

struct Packet_vkCreateXlibSurfaceKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};


struct Packet_vkGetPhysicalDeviceXlibPresentationSupportKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkBool32                                    return_value;
    format::HandleId                            physicalDevice;
    uint32_t                                    queueFamilyIndex;
    uint64_t                                    dpy;
    size_t                                      visualID;
};

struct Packet_vkCreateXcbSurfaceKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};


struct Packet_vkGetPhysicalDeviceXcbPresentationSupportKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkBool32                                    return_value;
    format::HandleId                            physicalDevice;
    uint32_t                                    queueFamilyIndex;
    uint64_t                                    connection;
    uint32_t                                    visual_id;
};

struct Packet_vkCreateWaylandSurfaceKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};


struct Packet_vkGetPhysicalDeviceWaylandPresentationSupportKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkBool32                                    return_value;
    format::HandleId                            physicalDevice;
    uint32_t                                    queueFamilyIndex;
    uint64_t                                    display;
};

struct Packet_vkCreateAndroidSurfaceKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};

struct Packet_vkCreateWin32SurfaceKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};


struct Packet_vkGetPhysicalDeviceWin32PresentationSupportKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkBool32                                    return_value;
    format::HandleId                            physicalDevice;
    uint32_t                                    queueFamilyIndex;
};

struct Packet_vkBindVideoSessionMemoryKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            videoSession;
    uint32_t                                    bindSessionMemoryInfoCount;
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR> pBindSessionMemoryInfos;
};


struct Packet_vkCmdBeginVideoCodingKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR> pBeginInfo;
};


struct Packet_vkCmdControlVideoCodingKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR> pCodingControlInfo;
};


struct Packet_vkCmdEndVideoCodingKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR> pEndCodingInfo;
};


struct Packet_vkCreateVideoSessionKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkVideoSessionKHR>     pVideoSession;
};


struct Packet_vkCreateVideoSessionParametersKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkVideoSessionParametersKHR> pVideoSessionParameters;
};


struct Packet_vkDestroyVideoSessionKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            videoSession;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkDestroyVideoSessionParametersKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            videoSessionParameters;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetPhysicalDeviceVideoCapabilitiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR> pVideoProfile;
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR> pCapabilities;
};


struct Packet_vkGetPhysicalDeviceVideoFormatPropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR> pVideoFormatInfo;
    PointerDecoder<uint32_t>                    pVideoFormatPropertyCount;
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR> pVideoFormatProperties;
};


struct Packet_vkGetVideoSessionMemoryRequirementsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            videoSession;
    PointerDecoder<uint32_t>                    pMemoryRequirementsCount;
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR> pMemoryRequirements;
};


struct Packet_vkUpdateVideoSessionParametersKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            videoSessionParameters;
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR> pUpdateInfo;
};

struct Packet_vkCmdDecodeVideoKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR> pDecodeInfo;
};

struct Packet_vkCmdBeginRenderingKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;
};


struct Packet_vkCmdEndRenderingKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
};

struct Packet_vkGetPhysicalDeviceFeatures2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;
};


struct Packet_vkGetPhysicalDeviceFormatProperties2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    VkFormat                                    format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;
};


struct Packet_vkGetPhysicalDeviceImageFormatProperties2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
};


struct Packet_vkGetPhysicalDeviceMemoryProperties2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;
};


struct Packet_vkGetPhysicalDeviceProperties2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;
};


struct Packet_vkGetPhysicalDeviceQueueFamilyProperties2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;
};


struct Packet_vkGetPhysicalDeviceSparseImageFormatProperties2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;
};

struct Packet_vkCmdDispatchBaseKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    baseGroupX;
    uint32_t                                    baseGroupY;
    uint32_t                                    baseGroupZ;
    uint32_t                                    groupCountX;
    uint32_t                                    groupCountY;
    uint32_t                                    groupCountZ;
};


struct Packet_vkCmdSetDeviceMaskKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    deviceMask;
};


struct Packet_vkGetDeviceGroupPeerMemoryFeaturesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    uint32_t                                    heapIndex;
    uint32_t                                    localDeviceIndex;
    uint32_t                                    remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags>    pPeerMemoryFeatures;
};

struct Packet_vkTrimCommandPoolKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            commandPool;
    VkCommandPoolTrimFlags                      flags;
};

struct Packet_vkEnumeratePhysicalDeviceGroupsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    PointerDecoder<uint32_t>                    pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
};

struct Packet_vkGetPhysicalDeviceExternalBufferPropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;
};

struct Packet_vkGetMemoryWin32HandleKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*>             pHandle;
};


struct Packet_vkGetMemoryWin32HandlePropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    VkExternalMemoryHandleTypeFlagBits          handleType;
    uint64_t                                    handle;
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR> pMemoryWin32HandleProperties;
};

struct Packet_vkGetMemoryFdKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int>                         pFd;
};


struct Packet_vkGetMemoryFdPropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    VkExternalMemoryHandleTypeFlagBits          handleType;
    int                                         fd;
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR> pMemoryFdProperties;
};

struct Packet_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;
};

struct Packet_vkGetSemaphoreWin32HandleKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*>             pHandle;
};


struct Packet_vkImportSemaphoreWin32HandleKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR> pImportSemaphoreWin32HandleInfo;
};

struct Packet_vkGetSemaphoreFdKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int>                         pFd;
};


struct Packet_vkImportSemaphoreFdKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR> pImportSemaphoreFdInfo;
};

struct Packet_vkCmdPushDescriptorSetKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineBindPoint                         pipelineBindPoint;
    format::HandleId                            layout;
    uint32_t                                    set;
    uint32_t                                    descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;
};

struct Packet_vkCreateDescriptorUpdateTemplateKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;
};


struct Packet_vkDestroyDescriptorUpdateTemplateKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};

struct Packet_vkCmdBeginRenderPass2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
};


struct Packet_vkCmdEndRenderPass2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;
};


struct Packet_vkCmdNextSubpass2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;
};


struct Packet_vkCreateRenderPass2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass>          pRenderPass;
};

struct Packet_vkGetSwapchainStatusKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
};

struct Packet_vkGetPhysicalDeviceExternalFencePropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;
};

struct Packet_vkGetFenceWin32HandleKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*>             pHandle;
};


struct Packet_vkImportFenceWin32HandleKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR> pImportFenceWin32HandleInfo;
};

struct Packet_vkGetFenceFdKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int>                         pFd;
};


struct Packet_vkImportFenceFdKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR> pImportFenceFdInfo;
};

struct Packet_vkAcquireProfilingLockKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR> pInfo;
};


struct Packet_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    uint32_t                                    queueFamilyIndex;
    PointerDecoder<uint32_t>                    pCounterCount;
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR> pCounters;
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR> pCounterDescriptions;
};


struct Packet_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR> pPerformanceQueryCreateInfo;
    PointerDecoder<uint32_t>                    pNumPasses;
};


struct Packet_vkReleaseProfilingLockKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
};

struct Packet_vkGetPhysicalDeviceSurfaceCapabilities2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR> pSurfaceCapabilities;
};


struct Packet_vkGetPhysicalDeviceSurfaceFormats2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t>                    pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR> pSurfaceFormats;
};

struct Packet_vkGetDisplayModeProperties2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            display;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR> pProperties;
};


struct Packet_vkGetDisplayPlaneCapabilities2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR> pDisplayPlaneInfo;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR> pCapabilities;
};


struct Packet_vkGetPhysicalDeviceDisplayPlaneProperties2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR> pProperties;
};


struct Packet_vkGetPhysicalDeviceDisplayProperties2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR> pProperties;
};

struct Packet_vkGetBufferMemoryRequirements2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;
};


struct Packet_vkGetImageMemoryRequirements2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;
};


struct Packet_vkGetImageSparseMemoryRequirements2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t>                    pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;
};

struct Packet_vkCreateSamplerYcbcrConversionKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;
};


struct Packet_vkDestroySamplerYcbcrConversionKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};

struct Packet_vkBindBufferMemory2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
};


struct Packet_vkBindImageMemory2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
};

struct Packet_vkGetDescriptorSetLayoutSupportKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;
};

struct Packet_vkCmdDrawIndexedIndirectCountKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    format::HandleId                            countBuffer;
    VkDeviceSize                                countBufferOffset;
    uint32_t                                    maxDrawCount;
    uint32_t                                    stride;
};


struct Packet_vkCmdDrawIndirectCountKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    format::HandleId                            countBuffer;
    VkDeviceSize                                countBufferOffset;
    uint32_t                                    maxDrawCount;
    uint32_t                                    stride;
};

struct Packet_vkGetSemaphoreCounterValueKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            semaphore;
    PointerDecoder<uint64_t>                    pValue;
};


struct Packet_vkSignalSemaphoreKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo> pSignalInfo;
};


struct Packet_vkWaitSemaphoresKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo> pWaitInfo;
    uint64_t                                    timeout;
};

struct Packet_vkCmdSetFragmentShadingRateKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkExtent2D>    pFragmentSize;
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;
};


struct Packet_vkGetPhysicalDeviceFragmentShadingRatesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pFragmentShadingRateCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR> pFragmentShadingRates;
};

struct Packet_vkCmdSetRenderingAttachmentLocationsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfoKHR> pLocationInfo;
};


struct Packet_vkCmdSetRenderingInputAttachmentIndicesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfoKHR> pInputAttachmentIndexInfo;
};

struct Packet_vkWaitForPresentKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    uint64_t                                    presentId;
    uint64_t                                    timeout;
};

struct Packet_vkGetBufferDeviceAddressKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkDeviceAddress                             return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
};


struct Packet_vkGetBufferOpaqueCaptureAddressKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    uint64_t                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
};


struct Packet_vkGetDeviceMemoryOpaqueCaptureAddressKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    uint64_t                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo> pInfo;
};

struct Packet_vkCreateDeferredOperationKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDeferredOperationKHR> pDeferredOperation;
};


struct Packet_vkDeferredOperationJoinKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            operation;
};


struct Packet_vkDestroyDeferredOperationKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            operation;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetDeferredOperationMaxConcurrencyKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    uint32_t                                    return_value;
    format::HandleId                            device;
    format::HandleId                            operation;
};


struct Packet_vkGetDeferredOperationResultKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            operation;
};

struct Packet_vkGetPipelineExecutableInternalRepresentationsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR> pExecutableInfo;
    PointerDecoder<uint32_t>                    pInternalRepresentationCount;
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR> pInternalRepresentations;
};


struct Packet_vkGetPipelineExecutablePropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkPipelineInfoKHR> pPipelineInfo;
    PointerDecoder<uint32_t>                    pExecutableCount;
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR> pProperties;
};


struct Packet_vkGetPipelineExecutableStatisticsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR> pExecutableInfo;
    PointerDecoder<uint32_t>                    pStatisticCount;
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR> pStatistics;
};

struct Packet_vkMapMemory2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkMemoryMapInfoKHR> pMemoryMapInfo;
    PointerDecoder<uint64_t, void*>             ppData;
};


struct Packet_vkUnmapMemory2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkMemoryUnmapInfoKHR> pMemoryUnmapInfo;
};

struct Packet_vkCmdEncodeVideoKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR> pEncodeInfo;
};


struct Packet_vkGetEncodedVideoSessionParametersKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersGetInfoKHR> pVideoSessionParametersInfo;
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR> pFeedbackInfo;
    PointerDecoder<size_t>                      pDataSize;
    PointerDecoder<uint8_t>                     pData;
};


struct Packet_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR> pQualityLevelInfo;
    StructPointerDecoder<Decoded_VkVideoEncodeQualityLevelPropertiesKHR> pQualityLevelProperties;
};

struct Packet_vkCmdPipelineBarrier2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;
};


struct Packet_vkCmdResetEvent2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            event;
    VkPipelineStageFlags2                       stageMask;
};


struct Packet_vkCmdSetEvent2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            event;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;
};


struct Packet_vkCmdWaitEvents2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    eventCount;
    HandlePointerDecoder<VkEvent>               pEvents;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfos;
};


struct Packet_vkCmdWriteBufferMarker2AMD
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineStageFlags2                       stage;
    format::HandleId                            dstBuffer;
    VkDeviceSize                                dstOffset;
    uint32_t                                    marker;
};


struct Packet_vkCmdWriteTimestamp2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineStageFlags2                       stage;
    format::HandleId                            queryPool;
    uint32_t                                    query;
};


struct Packet_vkGetQueueCheckpointData2NV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            queue;
    PointerDecoder<uint32_t>                    pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointData2NV> pCheckpointData;
};


struct Packet_vkQueueSubmit2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            queue;
    uint32_t                                    submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo2> pSubmits;
    format::HandleId                            fence;
};

struct Packet_vkCmdBlitImage2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkBlitImageInfo2> pBlitImageInfo;
};


struct Packet_vkCmdCopyBuffer2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferInfo2> pCopyBufferInfo;
};


struct Packet_vkCmdCopyBufferToImage2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2> pCopyBufferToImageInfo;
};


struct Packet_vkCmdCopyImage2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageInfo2> pCopyImageInfo;
};


struct Packet_vkCmdCopyImageToBuffer2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2> pCopyImageToBufferInfo;
};


struct Packet_vkCmdResolveImage2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkResolveImageInfo2> pResolveImageInfo;
};

struct Packet_vkCmdTraceRaysIndirect2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkDeviceAddress                             indirectDeviceAddress;
};

struct Packet_vkGetDeviceBufferMemoryRequirementsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;
};


struct Packet_vkGetDeviceImageMemoryRequirementsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;
};


struct Packet_vkGetDeviceImageSparseMemoryRequirementsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    PointerDecoder<uint32_t>                    pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;
};

struct Packet_vkCmdBindIndexBuffer2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    VkDeviceSize                                size;
    VkIndexType                                 indexType;
};


struct Packet_vkGetDeviceImageSubresourceLayoutKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfoKHR> pInfo;
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR> pLayout;
};


struct Packet_vkGetImageSubresourceLayout2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            image;
    StructPointerDecoder<Decoded_VkImageSubresource2KHR> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR> pLayout;
};


struct Packet_vkGetRenderingAreaGranularityKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkRenderingAreaInfoKHR> pRenderingAreaInfo;
    StructPointerDecoder<Decoded_VkExtent2D>    pGranularity;
};

struct Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesKHR> pProperties;
};

struct Packet_vkCmdSetLineStippleKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    lineStippleFactor;
    uint16_t                                    lineStipplePattern;
};

struct Packet_vkGetCalibratedTimestampsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    timestampCount;
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR> pTimestampInfos;
    PointerDecoder<uint64_t>                    pTimestamps;
    PointerDecoder<uint64_t>                    pMaxDeviation;
};


struct Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pTimeDomainCount;
    PointerDecoder<VkTimeDomainKHR>             pTimeDomains;
};

struct Packet_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT> pBindDescriptorBufferEmbeddedSamplersInfo;
};


struct Packet_vkCmdBindDescriptorSets2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfoKHR> pBindDescriptorSetsInfo;
};


struct Packet_vkCmdPushConstants2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkPushConstantsInfoKHR> pPushConstantsInfo;
};


struct Packet_vkCmdPushDescriptorSet2KHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfoKHR> pPushDescriptorSetInfo;
};


struct Packet_vkCmdSetDescriptorBufferOffsets2EXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT> pSetDescriptorBufferOffsetsInfo;
};

struct Packet_vkFrameBoundaryANDROID
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            semaphore;
    format::HandleId                            image;
};

struct Packet_vkCreateDebugReportCallbackEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDebugReportCallbackEXT> pCallback;
};


struct Packet_vkDebugReportMessageEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            instance;
    VkDebugReportFlagsEXT                       flags;
    VkDebugReportObjectTypeEXT                  objectType;
    uint64_t                                    object;
    size_t                                      location;
    int32_t                                     messageCode;
    StringDecoder                               pLayerPrefix;
    StringDecoder                               pMessage;
};


struct Packet_vkDestroyDebugReportCallbackEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            instance;
    format::HandleId                            callback;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};

struct Packet_vkCmdDebugMarkerBeginEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;
};


struct Packet_vkCmdDebugMarkerEndEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
};


struct Packet_vkCmdDebugMarkerInsertEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;
};


struct Packet_vkDebugMarkerSetObjectNameEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT> pNameInfo;
};


struct Packet_vkDebugMarkerSetObjectTagEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT> pTagInfo;
};

struct Packet_vkCmdBeginQueryIndexedEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            queryPool;
    uint32_t                                    query;
    VkQueryControlFlags                         flags;
    uint32_t                                    index;
};


struct Packet_vkCmdBeginTransformFeedbackEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstCounterBuffer;
    uint32_t                                    counterBufferCount;
    HandlePointerDecoder<VkBuffer>              pCounterBuffers;
    PointerDecoder<VkDeviceSize>                pCounterBufferOffsets;
};


struct Packet_vkCmdBindTransformFeedbackBuffersEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstBinding;
    uint32_t                                    bindingCount;
    HandlePointerDecoder<VkBuffer>              pBuffers;
    PointerDecoder<VkDeviceSize>                pOffsets;
    PointerDecoder<VkDeviceSize>                pSizes;
};


struct Packet_vkCmdDrawIndirectByteCountEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    instanceCount;
    uint32_t                                    firstInstance;
    format::HandleId                            counterBuffer;
    VkDeviceSize                                counterBufferOffset;
    uint32_t                                    counterOffset;
    uint32_t                                    vertexStride;
};


struct Packet_vkCmdEndQueryIndexedEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            queryPool;
    uint32_t                                    query;
    uint32_t                                    index;
};


struct Packet_vkCmdEndTransformFeedbackEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstCounterBuffer;
    uint32_t                                    counterBufferCount;
    HandlePointerDecoder<VkBuffer>              pCounterBuffers;
    PointerDecoder<VkDeviceSize>                pCounterBufferOffsets;
};

struct Packet_vkGetImageViewAddressNVX
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            imageView;
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX> pProperties;
};


struct Packet_vkGetImageViewHandleNVX
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    uint32_t                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX> pInfo;
};

struct Packet_vkCmdDrawIndexedIndirectCountAMD
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    format::HandleId                            countBuffer;
    VkDeviceSize                                countBufferOffset;
    uint32_t                                    maxDrawCount;
    uint32_t                                    stride;
};


struct Packet_vkCmdDrawIndirectCountAMD
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    format::HandleId                            countBuffer;
    VkDeviceSize                                countBufferOffset;
    uint32_t                                    maxDrawCount;
    uint32_t                                    stride;
};

struct Packet_vkGetShaderInfoAMD
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            pipeline;
    VkShaderStageFlagBits                       shaderStage;
    VkShaderInfoTypeAMD                         infoType;
    PointerDecoder<size_t>                      pInfoSize;
    PointerDecoder<uint8_t>                     pInfo;
};

struct Packet_vkCreateStreamDescriptorSurfaceGGP
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};

struct Packet_vkGetPhysicalDeviceExternalImageFormatPropertiesNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    VkFormat                                    format;
    VkImageType                                 type;
    VkImageTiling                               tiling;
    VkImageUsageFlags                           usage;
    VkImageCreateFlags                          flags;
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType;
    StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV> pExternalImageFormatProperties;
};

struct Packet_vkGetMemoryWin32HandleNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            memory;
    VkExternalMemoryHandleTypeFlagsNV           handleType;
    PointerDecoder<uint64_t, void*>             pHandle;
};

struct Packet_vkCreateViSurfaceNN
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};

struct Packet_vkCmdBeginConditionalRenderingEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT> pConditionalRenderingBegin;
};


struct Packet_vkCmdEndConditionalRenderingEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
};

struct Packet_vkCmdSetViewportWScalingNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstViewport;
    uint32_t                                    viewportCount;
    StructPointerDecoder<Decoded_VkViewportWScalingNV> pViewportWScalings;
};

struct Packet_vkReleaseDisplayEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            display;
};

struct Packet_vkAcquireXlibDisplayEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    uint64_t                                    dpy;
    format::HandleId                            display;
};


struct Packet_vkGetRandROutputDisplayEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    uint64_t                                    dpy;
    size_t                                      rrOutput;
    HandlePointerDecoder<VkDisplayKHR>          pDisplay;
};

struct Packet_vkGetPhysicalDeviceSurfaceCapabilities2EXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT> pSurfaceCapabilities;
};

struct Packet_vkDisplayPowerControlEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            display;
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT> pDisplayPowerInfo;
};


struct Packet_vkGetSwapchainCounterEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    VkSurfaceCounterFlagBitsEXT                 counter;
    PointerDecoder<uint64_t>                    pCounterValue;
};


struct Packet_vkRegisterDeviceEventEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT> pDeviceEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence>               pFence;
};


struct Packet_vkRegisterDisplayEventEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            display;
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT> pDisplayEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence>               pFence;
};

struct Packet_vkGetPastPresentationTimingGOOGLE
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    PointerDecoder<uint32_t>                    pPresentationTimingCount;
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE> pPresentationTimings;
};


struct Packet_vkGetRefreshCycleDurationGOOGLE
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE> pDisplayTimingProperties;
};

struct Packet_vkCmdSetDiscardRectangleEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstDiscardRectangle;
    uint32_t                                    discardRectangleCount;
    StructPointerDecoder<Decoded_VkRect2D>      pDiscardRectangles;
};


struct Packet_vkCmdSetDiscardRectangleEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    discardRectangleEnable;
};


struct Packet_vkCmdSetDiscardRectangleModeEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkDiscardRectangleModeEXT                   discardRectangleMode;
};

struct Packet_vkSetHdrMetadataEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    uint32_t                                    swapchainCount;
    HandlePointerDecoder<VkSwapchainKHR>        pSwapchains;
    StructPointerDecoder<Decoded_VkHdrMetadataEXT> pMetadata;
};

struct Packet_vkCreateIOSSurfaceMVK
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};

struct Packet_vkCreateMacOSSurfaceMVK
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};

struct Packet_vkCmdBeginDebugUtilsLabelEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;
};


struct Packet_vkCmdEndDebugUtilsLabelEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
};


struct Packet_vkCmdInsertDebugUtilsLabelEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;
};


struct Packet_vkCreateDebugUtilsMessengerEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDebugUtilsMessengerEXT> pMessenger;
};


struct Packet_vkDestroyDebugUtilsMessengerEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            instance;
    format::HandleId                            messenger;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkQueueBeginDebugUtilsLabelEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;
};


struct Packet_vkQueueEndDebugUtilsLabelEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            queue;
};


struct Packet_vkQueueInsertDebugUtilsLabelEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;
};


struct Packet_vkSetDebugUtilsObjectNameEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT> pNameInfo;
};


struct Packet_vkSetDebugUtilsObjectTagEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT> pTagInfo;
};


struct Packet_vkSubmitDebugUtilsMessageEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            instance;
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity;
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT> pCallbackData;
};

struct Packet_vkGetAndroidHardwareBufferPropertiesANDROID
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint64_t                                    buffer;
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID> pProperties;
};


struct Packet_vkGetMemoryAndroidHardwareBufferANDROID
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID> pInfo;
    PointerDecoder<uint64_t, void*>             pBuffer;
};

struct Packet_vkCmdSetSampleLocationsEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT> pSampleLocationsInfo;
};


struct Packet_vkGetPhysicalDeviceMultisamplePropertiesEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            physicalDevice;
    VkSampleCountFlagBits                       samples;
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT> pMultisampleProperties;
};

struct Packet_vkGetImageDrmFormatModifierPropertiesEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            image;
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT> pProperties;
};

struct Packet_vkCreateValidationCacheEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkValidationCacheEXT>  pValidationCache;
};


struct Packet_vkDestroyValidationCacheEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            validationCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetValidationCacheDataEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            validationCache;
    PointerDecoder<size_t>                      pDataSize;
    PointerDecoder<uint8_t>                     pData;
};


struct Packet_vkMergeValidationCachesEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            dstCache;
    uint32_t                                    srcCacheCount;
    HandlePointerDecoder<VkValidationCacheEXT>  pSrcCaches;
};

struct Packet_vkCmdBindShadingRateImageNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            imageView;
    VkImageLayout                               imageLayout;
};


struct Packet_vkCmdSetCoarseSampleOrderNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkCoarseSampleOrderTypeNV                   sampleOrderType;
    uint32_t                                    customSampleOrderCount;
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV> pCustomSampleOrders;
};


struct Packet_vkCmdSetViewportShadingRatePaletteNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstViewport;
    uint32_t                                    viewportCount;
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV> pShadingRatePalettes;
};

struct Packet_vkBindAccelerationStructureMemoryNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    bindInfoCount;
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV> pBindInfos;
};


struct Packet_vkCmdBuildAccelerationStructureNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV> pInfo;
    format::HandleId                            instanceData;
    VkDeviceSize                                instanceOffset;
    VkBool32                                    update;
    format::HandleId                            dst;
    format::HandleId                            src;
    format::HandleId                            scratch;
    VkDeviceSize                                scratchOffset;
};


struct Packet_vkCmdCopyAccelerationStructureNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            dst;
    format::HandleId                            src;
    VkCopyAccelerationStructureModeKHR          mode;
};


struct Packet_vkCmdTraceRaysNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            raygenShaderBindingTableBuffer;
    VkDeviceSize                                raygenShaderBindingOffset;
    format::HandleId                            missShaderBindingTableBuffer;
    VkDeviceSize                                missShaderBindingOffset;
    VkDeviceSize                                missShaderBindingStride;
    format::HandleId                            hitShaderBindingTableBuffer;
    VkDeviceSize                                hitShaderBindingOffset;
    VkDeviceSize                                hitShaderBindingStride;
    format::HandleId                            callableShaderBindingTableBuffer;
    VkDeviceSize                                callableShaderBindingOffset;
    VkDeviceSize                                callableShaderBindingStride;
    uint32_t                                    width;
    uint32_t                                    height;
    uint32_t                                    depth;
};


struct Packet_vkCmdWriteAccelerationStructuresPropertiesNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    accelerationStructureCount;
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructures;
    VkQueryType                                 queryType;
    format::HandleId                            queryPool;
    uint32_t                                    firstQuery;
};


struct Packet_vkCompileDeferredNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            pipeline;
    uint32_t                                    shader;
};


struct Packet_vkCreateAccelerationStructureNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructure;
};


struct Packet_vkCreateRayTracingPipelinesNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            pipelineCache;
    uint32_t                                    createInfoCount;
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipeline>            pPipelines;
};


struct Packet_vkDestroyAccelerationStructureNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetAccelerationStructureHandleNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            accelerationStructure;
    size_t                                      dataSize;
    PointerDecoder<uint8_t>                     pData;
};


struct Packet_vkGetAccelerationStructureMemoryRequirementsNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR> pMemoryRequirements;
};


struct Packet_vkGetRayTracingShaderGroupHandlesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            pipeline;
    uint32_t                                    firstGroup;
    uint32_t                                    groupCount;
    size_t                                      dataSize;
    PointerDecoder<uint8_t>                     pData;
};


struct Packet_vkGetRayTracingShaderGroupHandlesNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            pipeline;
    uint32_t                                    firstGroup;
    uint32_t                                    groupCount;
    size_t                                      dataSize;
    PointerDecoder<uint8_t>                     pData;
};

struct Packet_vkGetMemoryHostPointerPropertiesEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    VkExternalMemoryHandleTypeFlagBits          handleType;
    uint64_t                                    pHostPointer;
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT> pMemoryHostPointerProperties;
};

struct Packet_vkCmdWriteBufferMarkerAMD
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineStageFlagBits                     pipelineStage;
    format::HandleId                            dstBuffer;
    VkDeviceSize                                dstOffset;
    uint32_t                                    marker;
};

struct Packet_vkGetCalibratedTimestampsEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    timestampCount;
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR> pTimestampInfos;
    PointerDecoder<uint64_t>                    pTimestamps;
    PointerDecoder<uint64_t>                    pMaxDeviation;
};


struct Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pTimeDomainCount;
    PointerDecoder<VkTimeDomainKHR>             pTimeDomains;
};

struct Packet_vkCmdDrawMeshTasksIndirectCountNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    format::HandleId                            countBuffer;
    VkDeviceSize                                countBufferOffset;
    uint32_t                                    maxDrawCount;
    uint32_t                                    stride;
};


struct Packet_vkCmdDrawMeshTasksIndirectNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    uint32_t                                    drawCount;
    uint32_t                                    stride;
};


struct Packet_vkCmdDrawMeshTasksNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    taskCount;
    uint32_t                                    firstTask;
};

struct Packet_vkCmdSetExclusiveScissorEnableNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstExclusiveScissor;
    uint32_t                                    exclusiveScissorCount;
    PointerDecoder<VkBool32>                    pExclusiveScissorEnables;
};


struct Packet_vkCmdSetExclusiveScissorNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstExclusiveScissor;
    uint32_t                                    exclusiveScissorCount;
    StructPointerDecoder<Decoded_VkRect2D>      pExclusiveScissors;
};

struct Packet_vkCmdSetCheckpointNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint64_t                                    pCheckpointMarker;
};


struct Packet_vkGetQueueCheckpointDataNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            queue;
    PointerDecoder<uint32_t>                    pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointDataNV> pCheckpointData;
};

struct Packet_vkAcquirePerformanceConfigurationINTEL
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL> pAcquireInfo;
    HandlePointerDecoder<VkPerformanceConfigurationINTEL> pConfiguration;
};


struct Packet_vkCmdSetPerformanceMarkerINTEL
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL> pMarkerInfo;
};


struct Packet_vkCmdSetPerformanceOverrideINTEL
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL> pOverrideInfo;
};


struct Packet_vkCmdSetPerformanceStreamMarkerINTEL
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL> pMarkerInfo;
};


struct Packet_vkGetPerformanceParameterINTEL
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    VkPerformanceParameterTypeINTEL             parameter;
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL> pValue;
};


struct Packet_vkInitializePerformanceApiINTEL
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL> pInitializeInfo;
};


struct Packet_vkQueueSetPerformanceConfigurationINTEL
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            queue;
    format::HandleId                            configuration;
};


struct Packet_vkReleasePerformanceConfigurationINTEL
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            configuration;
};


struct Packet_vkUninitializePerformanceApiINTEL
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
};

struct Packet_vkSetLocalDimmingAMD
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            swapChain;
    VkBool32                                    localDimmingEnable;
};

struct Packet_vkCreateImagePipeSurfaceFUCHSIA
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};

struct Packet_vkCreateMetalSurfaceEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};

struct Packet_vkGetBufferDeviceAddressEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkDeviceAddress                             return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
};

struct Packet_vkGetPhysicalDeviceToolPropertiesEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties> pToolProperties;
};

struct Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV> pProperties;
};

struct Packet_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    PointerDecoder<uint32_t>                    pCombinationCount;
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV> pCombinations;
};

struct Packet_vkAcquireFullScreenExclusiveModeEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
};


struct Packet_vkGetDeviceGroupSurfacePresentModes2EXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;
};


struct Packet_vkGetPhysicalDeviceSurfacePresentModes2EXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t>                    pPresentModeCount;
    PointerDecoder<VkPresentModeKHR>            pPresentModes;
};


struct Packet_vkReleaseFullScreenExclusiveModeEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
};

struct Packet_vkCreateHeadlessSurfaceEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};

struct Packet_vkCmdSetLineStippleEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    lineStippleFactor;
    uint16_t                                    lineStipplePattern;
};

struct Packet_vkResetQueryPoolEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            queryPool;
    uint32_t                                    firstQuery;
    uint32_t                                    queryCount;
};

struct Packet_vkCmdBindVertexBuffers2EXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstBinding;
    uint32_t                                    bindingCount;
    HandlePointerDecoder<VkBuffer>              pBuffers;
    PointerDecoder<VkDeviceSize>                pOffsets;
    PointerDecoder<VkDeviceSize>                pSizes;
    PointerDecoder<VkDeviceSize>                pStrides;
};


struct Packet_vkCmdSetCullModeEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkCullModeFlags                             cullMode;
};


struct Packet_vkCmdSetDepthBoundsTestEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    depthBoundsTestEnable;
};


struct Packet_vkCmdSetDepthCompareOpEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkCompareOp                                 depthCompareOp;
};


struct Packet_vkCmdSetDepthTestEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    depthTestEnable;
};


struct Packet_vkCmdSetDepthWriteEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    depthWriteEnable;
};


struct Packet_vkCmdSetFrontFaceEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkFrontFace                                 frontFace;
};


struct Packet_vkCmdSetPrimitiveTopologyEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPrimitiveTopology                         primitiveTopology;
};


struct Packet_vkCmdSetScissorWithCountEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    scissorCount;
    StructPointerDecoder<Decoded_VkRect2D>      pScissors;
};


struct Packet_vkCmdSetStencilOpEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkStencilFaceFlags                          faceMask;
    VkStencilOp                                 failOp;
    VkStencilOp                                 passOp;
    VkStencilOp                                 depthFailOp;
    VkCompareOp                                 compareOp;
};


struct Packet_vkCmdSetStencilTestEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    stencilTestEnable;
};


struct Packet_vkCmdSetViewportWithCountEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    viewportCount;
    StructPointerDecoder<Decoded_VkViewport>    pViewports;
};

struct Packet_vkCopyImageToImageEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkCopyImageToImageInfoEXT> pCopyImageToImageInfo;
};


struct Packet_vkCopyImageToMemoryEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfoEXT> pCopyImageToMemoryInfo;
};


struct Packet_vkCopyMemoryToImageEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfoEXT> pCopyMemoryToImageInfo;
};


struct Packet_vkGetImageSubresourceLayout2EXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            image;
    StructPointerDecoder<Decoded_VkImageSubresource2KHR> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR> pLayout;
};


struct Packet_vkTransitionImageLayoutEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    transitionCount;
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfoEXT> pTransitions;
};

struct Packet_vkReleaseSwapchainImagesEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT> pReleaseInfo;
};

struct Packet_vkCmdBindPipelineShaderGroupNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineBindPoint                         pipelineBindPoint;
    format::HandleId                            pipeline;
    uint32_t                                    groupIndex;
};


struct Packet_vkCmdExecuteGeneratedCommandsNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    isPreprocessed;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;
};


struct Packet_vkCmdPreprocessGeneratedCommandsNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;
};


struct Packet_vkCreateIndirectCommandsLayoutNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkIndirectCommandsLayoutNV> pIndirectCommandsLayout;
};


struct Packet_vkDestroyIndirectCommandsLayoutNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetGeneratedCommandsMemoryRequirementsNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;
};

struct Packet_vkCmdSetDepthBias2EXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT> pDepthBiasInfo;
};

struct Packet_vkAcquireDrmDisplayEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    int32_t                                     drmFd;
    format::HandleId                            display;
};


struct Packet_vkGetDrmDisplayEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    int32_t                                     drmFd;
    uint32_t                                    connectorId;
    HandlePointerDecoder<VkDisplayKHR>          display;
};

struct Packet_vkCreatePrivateDataSlotEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlot>     pPrivateDataSlot;
};


struct Packet_vkDestroyPrivateDataSlotEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            privateDataSlot;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetPrivateDataEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    VkObjectType                                objectType;
    uint64_t                                    objectHandle;
    format::HandleId                            privateDataSlot;
    PointerDecoder<uint64_t>                    pData;
};


struct Packet_vkSetPrivateDataEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    VkObjectType                                objectType;
    uint64_t                                    objectHandle;
    format::HandleId                            privateDataSlot;
    uint64_t                                    data;
};

struct Packet_vkCmdSetFragmentShadingRateEnumNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkFragmentShadingRateNV                     shadingRate;
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;
};

struct Packet_vkGetDeviceFaultInfoEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT> pFaultCounts;
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT> pFaultInfo;
};

struct Packet_vkAcquireWinrtDisplayNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    format::HandleId                            display;
};


struct Packet_vkGetWinrtDisplayNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    uint32_t                                    deviceRelativeId;
    HandlePointerDecoder<VkDisplayKHR>          pDisplay;
};

struct Packet_vkCreateDirectFBSurfaceEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};


struct Packet_vkGetPhysicalDeviceDirectFBPresentationSupportEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkBool32                                    return_value;
    format::HandleId                            physicalDevice;
    uint32_t                                    queueFamilyIndex;
    uint64_t                                    dfb;
};

struct Packet_vkCmdSetVertexInputEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    vertexBindingDescriptionCount;
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT> pVertexBindingDescriptions;
    uint32_t                                    vertexAttributeDescriptionCount;
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT> pVertexAttributeDescriptions;
};

struct Packet_vkGetMemoryZirconHandleFUCHSIA
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA> pGetZirconHandleInfo;
    PointerDecoder<uint32_t>                    pZirconHandle;
};


struct Packet_vkGetMemoryZirconHandlePropertiesFUCHSIA
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    VkExternalMemoryHandleTypeFlagBits          handleType;
    uint32_t                                    zirconHandle;
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA> pMemoryZirconHandleProperties;
};

struct Packet_vkGetSemaphoreZirconHandleFUCHSIA
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA> pGetZirconHandleInfo;
    PointerDecoder<uint32_t>                    pZirconHandle;
};


struct Packet_vkImportSemaphoreZirconHandleFUCHSIA
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA> pImportSemaphoreZirconHandleInfo;
};

struct Packet_vkCmdBindInvocationMaskHUAWEI
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            imageView;
    VkImageLayout                               imageLayout;
};

struct Packet_vkGetMemoryRemoteAddressNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV> pMemoryGetRemoteAddressInfo;
    PointerDecoder<uint64_t, void*>             pAddress;
};

struct Packet_vkCmdSetDepthBiasEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    depthBiasEnable;
};


struct Packet_vkCmdSetLogicOpEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkLogicOp                                   logicOp;
};


struct Packet_vkCmdSetPatchControlPointsEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    patchControlPoints;
};


struct Packet_vkCmdSetPrimitiveRestartEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    primitiveRestartEnable;
};


struct Packet_vkCmdSetRasterizerDiscardEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    rasterizerDiscardEnable;
};

struct Packet_vkCreateScreenSurfaceQNX
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            instance;
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR>          pSurface;
};


struct Packet_vkGetPhysicalDeviceScreenPresentationSupportQNX
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkBool32                                    return_value;
    format::HandleId                            physicalDevice;
    uint32_t                                    queueFamilyIndex;
    uint64_t                                    window;
};

struct Packet_vkCmdSetColorWriteEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    attachmentCount;
    PointerDecoder<VkBool32>                    pColorWriteEnables;
};

struct Packet_vkCmdDrawMultiEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    drawCount;
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT> pVertexInfo;
    uint32_t                                    instanceCount;
    uint32_t                                    firstInstance;
    uint32_t                                    stride;
};


struct Packet_vkCmdDrawMultiIndexedEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    drawCount;
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT> pIndexInfo;
    uint32_t                                    instanceCount;
    uint32_t                                    firstInstance;
    uint32_t                                    stride;
    PointerDecoder<int32_t>                     pVertexOffset;
};

struct Packet_vkBuildMicromapsEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            deferredOperation;
    uint32_t                                    infoCount;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pInfos;
};


struct Packet_vkCmdBuildMicromapsEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    infoCount;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pInfos;
};


struct Packet_vkCmdCopyMemoryToMicromapEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT> pInfo;
};


struct Packet_vkCmdCopyMicromapEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT> pInfo;
};


struct Packet_vkCmdCopyMicromapToMemoryEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT> pInfo;
};


struct Packet_vkCmdWriteMicromapsPropertiesEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    micromapCount;
    HandlePointerDecoder<VkMicromapEXT>         pMicromaps;
    VkQueryType                                 queryType;
    format::HandleId                            queryPool;
    uint32_t                                    firstQuery;
};


struct Packet_vkCopyMemoryToMicromapEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT> pInfo;
};


struct Packet_vkCopyMicromapEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT> pInfo;
};


struct Packet_vkCopyMicromapToMemoryEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT> pInfo;
};


struct Packet_vkCreateMicromapEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkMicromapEXT>         pMicromap;
};


struct Packet_vkDestroyMicromapEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            micromap;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetDeviceMicromapCompatibilityEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT> pVersionInfo;
    PointerDecoder<VkAccelerationStructureCompatibilityKHR> pCompatibility;
};


struct Packet_vkGetMicromapBuildSizesEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    VkAccelerationStructureBuildTypeKHR         buildType;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pBuildInfo;
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT> pSizeInfo;
};


struct Packet_vkWriteMicromapsPropertiesEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    micromapCount;
    HandlePointerDecoder<VkMicromapEXT>         pMicromaps;
    VkQueryType                                 queryType;
    size_t                                      dataSize;
    PointerDecoder<uint8_t>                     pData;
    size_t                                      stride;
};

struct Packet_vkCmdDrawClusterHUAWEI
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    groupCountX;
    uint32_t                                    groupCountY;
    uint32_t                                    groupCountZ;
};


struct Packet_vkCmdDrawClusterIndirectHUAWEI
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
};

struct Packet_vkSetDeviceMemoryPriorityEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            memory;
    float                                       priority;
};

struct Packet_vkGetDescriptorSetHostMappingVALVE
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            descriptorSet;
    PointerDecoder<uint64_t, void*>             ppData;
};


struct Packet_vkGetDescriptorSetLayoutHostMappingInfoVALVE
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE> pBindingReference;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE> pHostMapping;
};

struct Packet_vkCmdUpdatePipelineIndirectBufferNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPipelineBindPoint                         pipelineBindPoint;
    format::HandleId                            pipeline;
};


struct Packet_vkGetPipelineIndirectDeviceAddressNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkDeviceAddress                             return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV> pInfo;
};


struct Packet_vkGetPipelineIndirectMemoryRequirementsNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;
};

struct Packet_vkCmdSetAlphaToCoverageEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    alphaToCoverageEnable;
};


struct Packet_vkCmdSetAlphaToOneEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    alphaToOneEnable;
};


struct Packet_vkCmdSetColorBlendAdvancedEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstAttachment;
    uint32_t                                    attachmentCount;
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT> pColorBlendAdvanced;
};


struct Packet_vkCmdSetColorBlendEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstAttachment;
    uint32_t                                    attachmentCount;
    PointerDecoder<VkBool32>                    pColorBlendEnables;
};


struct Packet_vkCmdSetColorBlendEquationEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstAttachment;
    uint32_t                                    attachmentCount;
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT> pColorBlendEquations;
};


struct Packet_vkCmdSetColorWriteMaskEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstAttachment;
    uint32_t                                    attachmentCount;
    PointerDecoder<VkColorComponentFlags>       pColorWriteMasks;
};


struct Packet_vkCmdSetConservativeRasterizationModeEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode;
};


struct Packet_vkCmdSetCoverageModulationModeNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkCoverageModulationModeNV                  coverageModulationMode;
};


struct Packet_vkCmdSetCoverageModulationTableEnableNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    coverageModulationTableEnable;
};


struct Packet_vkCmdSetCoverageModulationTableNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    coverageModulationTableCount;
    PointerDecoder<float>                       pCoverageModulationTable;
};


struct Packet_vkCmdSetCoverageReductionModeNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkCoverageReductionModeNV                   coverageReductionMode;
};


struct Packet_vkCmdSetCoverageToColorEnableNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    coverageToColorEnable;
};


struct Packet_vkCmdSetCoverageToColorLocationNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    coverageToColorLocation;
};


struct Packet_vkCmdSetDepthClampEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    depthClampEnable;
};


struct Packet_vkCmdSetDepthClipEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    depthClipEnable;
};


struct Packet_vkCmdSetDepthClipNegativeOneToOneEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    negativeOneToOne;
};


struct Packet_vkCmdSetExtraPrimitiveOverestimationSizeEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    float                                       extraPrimitiveOverestimationSize;
};


struct Packet_vkCmdSetLineRasterizationModeEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkLineRasterizationModeEXT                  lineRasterizationMode;
};


struct Packet_vkCmdSetLineStippleEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    stippledLineEnable;
};


struct Packet_vkCmdSetLogicOpEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    logicOpEnable;
};


struct Packet_vkCmdSetPolygonModeEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkPolygonMode                               polygonMode;
};


struct Packet_vkCmdSetProvokingVertexModeEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkProvokingVertexModeEXT                    provokingVertexMode;
};


struct Packet_vkCmdSetRasterizationSamplesEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkSampleCountFlagBits                       rasterizationSamples;
};


struct Packet_vkCmdSetRasterizationStreamEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    rasterizationStream;
};


struct Packet_vkCmdSetRepresentativeFragmentTestEnableNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    representativeFragmentTestEnable;
};


struct Packet_vkCmdSetSampleLocationsEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    sampleLocationsEnable;
};


struct Packet_vkCmdSetSampleMaskEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkSampleCountFlagBits                       samples;
    PointerDecoder<VkSampleMask>                pSampleMask;
};


struct Packet_vkCmdSetShadingRateImageEnableNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    shadingRateImageEnable;
};


struct Packet_vkCmdSetTessellationDomainOriginEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkTessellationDomainOrigin                  domainOrigin;
};


struct Packet_vkCmdSetViewportSwizzleNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    firstViewport;
    uint32_t                                    viewportCount;
    StructPointerDecoder<Decoded_VkViewportSwizzleNV> pViewportSwizzles;
};


struct Packet_vkCmdSetViewportWScalingEnableNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkBool32                                    viewportWScalingEnable;
};

struct Packet_vkGetShaderModuleCreateInfoIdentifierEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT> pIdentifier;
};


struct Packet_vkGetShaderModuleIdentifierEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            shaderModule;
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT> pIdentifier;
};

struct Packet_vkBindOpticalFlowSessionImageNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            session;
    VkOpticalFlowSessionBindingPointNV          bindingPoint;
    format::HandleId                            view;
    VkImageLayout                               layout;
};


struct Packet_vkCmdOpticalFlowExecuteNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            session;
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV> pExecuteInfo;
};


struct Packet_vkCreateOpticalFlowSessionNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkOpticalFlowSessionNV> pSession;
};


struct Packet_vkDestroyOpticalFlowSessionNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            session;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetPhysicalDeviceOpticalFlowImageFormatsNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            physicalDevice;
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV> pOpticalFlowImageFormatInfo;
    PointerDecoder<uint32_t>                    pFormatCount;
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV> pImageFormatProperties;
};

struct Packet_vkCmdBindShadersEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    stageCount;
    PointerDecoder<VkShaderStageFlagBits>       pStages;
    HandlePointerDecoder<VkShaderEXT>           pShaders;
};


struct Packet_vkCreateShadersEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    createInfoCount;
    StructPointerDecoder<Decoded_VkShaderCreateInfoEXT> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkShaderEXT>           pShaders;
};


struct Packet_vkDestroyShaderEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            shader;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetShaderBinaryDataEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            shader;
    PointerDecoder<size_t>                      pDataSize;
    PointerDecoder<uint8_t>                     pData;
};

struct Packet_vkGetDynamicRenderingTilePropertiesQCOM
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM> pProperties;
};


struct Packet_vkGetFramebufferTilePropertiesQCOM
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            framebuffer;
    PointerDecoder<uint32_t>                    pPropertiesCount;
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM> pProperties;
};

struct Packet_vkGetLatencyTimingsNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    StructPointerDecoder<Decoded_VkGetLatencyMarkerInfoNV> pLatencyMarkerInfo;
};


struct Packet_vkLatencySleepNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    StructPointerDecoder<Decoded_VkLatencySleepInfoNV> pSleepInfo;
};


struct Packet_vkQueueNotifyOutOfBandNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            queue;
    StructPointerDecoder<Decoded_VkOutOfBandQueueTypeInfoNV> pQueueTypeInfo;
};


struct Packet_vkSetLatencyMarkerNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    StructPointerDecoder<Decoded_VkSetLatencyMarkerInfoNV> pLatencyMarkerInfo;
};


struct Packet_vkSetLatencySleepModeNV
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            swapchain;
    StructPointerDecoder<Decoded_VkLatencySleepModeInfoNV> pSleepModeInfo;
};

struct Packet_vkCmdSetAttachmentFeedbackLoopEnableEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    VkImageAspectFlags                          aspectMask;
};

struct Packet_vkCmdBuildAccelerationStructuresIndirectKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    infoCount;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    PointerDecoder<VkDeviceAddress>             pIndirectDeviceAddresses;
    PointerDecoder<uint32_t>                    pIndirectStrides;
    PointerDecoder<uint32_t*>                   ppMaxPrimitiveCounts;
};


struct Packet_vkCmdBuildAccelerationStructuresKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    infoCount;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*> ppBuildRangeInfos;
};


struct Packet_vkCmdCopyAccelerationStructureKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR> pInfo;
};


struct Packet_vkCmdCopyAccelerationStructureToMemoryKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;
};


struct Packet_vkCmdCopyMemoryToAccelerationStructureKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;
};


struct Packet_vkCmdWriteAccelerationStructuresPropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    accelerationStructureCount;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructures;
    VkQueryType                                 queryType;
    format::HandleId                            queryPool;
    uint32_t                                    firstQuery;
};


struct Packet_vkCopyAccelerationStructureToMemoryKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            deferredOperation;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;
};


struct Packet_vkCopyMemoryToAccelerationStructureKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;
};


struct Packet_vkCreateAccelerationStructureKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructure;
};


struct Packet_vkDestroyAccelerationStructureKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    format::HandleId                            accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
};


struct Packet_vkGetAccelerationStructureBuildSizesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    VkAccelerationStructureBuildTypeKHR         buildType;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pBuildInfo;
    PointerDecoder<uint32_t>                    pMaxPrimitiveCounts;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR> pSizeInfo;
};


struct Packet_vkGetAccelerationStructureDeviceAddressKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkDeviceAddress                             return_value;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR> pInfo;
};


struct Packet_vkGetDeviceAccelerationStructureCompatibilityKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            device;
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR> pVersionInfo;
    PointerDecoder<VkAccelerationStructureCompatibilityKHR> pCompatibility;
};


struct Packet_vkWriteAccelerationStructuresPropertiesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    uint32_t                                    accelerationStructureCount;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructures;
    VkQueryType                                 queryType;
    size_t                                      dataSize;
    PointerDecoder<uint8_t>                     pData;
    size_t                                      stride;
};

struct Packet_vkCmdSetRayTracingPipelineStackSizeKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    pipelineStackSize;
};


struct Packet_vkCmdTraceRaysIndirectKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pRaygenShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pMissShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pHitShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pCallableShaderBindingTable;
    VkDeviceAddress                             indirectDeviceAddress;
};


struct Packet_vkCmdTraceRaysKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pRaygenShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pMissShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pHitShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pCallableShaderBindingTable;
    uint32_t                                    width;
    uint32_t                                    height;
    uint32_t                                    depth;
};


struct Packet_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkResult                                    return_value;
    format::HandleId                            device;
    format::HandleId                            pipeline;
    uint32_t                                    firstGroup;
    uint32_t                                    groupCount;
    size_t                                      dataSize;
    PointerDecoder<uint8_t>                     pData;
};


struct Packet_vkGetRayTracingShaderGroupStackSizeKHR
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    VkDeviceSize                                return_value;
    format::HandleId                            device;
    format::HandleId                            pipeline;
    uint32_t                                    group;
    VkShaderGroupShaderKHR                      groupShader;
};

struct Packet_vkCmdDrawMeshTasksEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    uint32_t                                    groupCountX;
    uint32_t                                    groupCountY;
    uint32_t                                    groupCountZ;
};


struct Packet_vkCmdDrawMeshTasksIndirectCountEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    format::HandleId                            countBuffer;
    VkDeviceSize                                countBufferOffset;
    uint32_t                                    maxDrawCount;
    uint32_t                                    stride;
};


struct Packet_vkCmdDrawMeshTasksIndirectEXT
{
    format::PacketCallId                        packet_id;
    ApiCallInfo                                 call_info;
    format::HandleId                            commandBuffer;
    format::HandleId                            buffer;
    VkDeviceSize                                offset;
    uint32_t                                    drawCount;
    uint32_t                                    stride;
};


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
