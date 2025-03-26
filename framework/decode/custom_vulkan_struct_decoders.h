/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_CUSTOM_STRUCT_DECODERS_H
#define GFXRECON_DECODE_CUSTOM_STRUCT_DECODERS_H

#include "format/platform_types.h"
#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/vulkan_pnext_node.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Decoded union wrappers.
struct Decoded_VkClearColorValue
{
    using struct_type = VkClearColorValue;
    VkClearColorValue*       decoded_value{ nullptr };
    PointerDecoder<uint32_t> uint32;
};

struct Decoded_VkClearValue
{
    using struct_type = VkClearValue;
    VkClearValue*              decoded_value{ nullptr };
    Decoded_VkClearColorValue* color{ nullptr };
};

struct Decoded_VkPipelineExecutableStatisticValueKHR
{
    using struct_type = VkPipelineExecutableStatisticValueKHR;
    VkPipelineExecutableStatisticValueKHR* decoded_value{ nullptr };
};

struct Decoded_VkDeviceOrHostAddressKHR
{
    using struct_type = VkDeviceOrHostAddressKHR;
    VkDeviceOrHostAddressKHR* decoded_value{ nullptr };
    uint64_t                  hostAddress{ 0 };
};

struct Decoded_VkDeviceOrHostAddressConstKHR
{
    using struct_type = VkDeviceOrHostAddressConstKHR;
    VkDeviceOrHostAddressConstKHR* decoded_value{ nullptr };
    uint64_t                       hostAddress{ 0 };
};

// This union wrapper does not have a DecodeStruct function.  It is decoded by the
// Decoded_VkAccelerationStructureGeometryKHR DecodeStruct function, based on the value of
// VkAccelerationStructureGeometryKHR::geometryType.
struct Decoded_VkAccelerationStructureGeometryDataKHR
{
    using struct_type = VkAccelerationStructureGeometryDataKHR;
    VkAccelerationStructureGeometryDataKHR* decoded_value{ nullptr };

    Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* triangles{ nullptr };
    Decoded_VkAccelerationStructureGeometryAabbsDataKHR*     aabbs{ nullptr };
    Decoded_VkAccelerationStructureGeometryInstancesDataKHR* instances{ nullptr };
};

// This union wrapper does not have a DecodeStruct function.  It is decoded by the Decoded_VkPerformanceValueINTEL
// DecodeStruct function, based on the value of VkPerformanceValueINTEL::type.
struct Decoded_VkPerformanceValueDataINTEL
{
    using struct_type = VkPerformanceValueDataINTEL;

    VkPerformanceValueDataINTEL* decoded_value{ nullptr };

    StringDecoder valueString;
};

struct Decoded_VkAccelerationStructureMotionInstanceNV
{
    using struct_type = VkAccelerationStructureMotionInstanceNV;

    VkAccelerationStructureMotionInstanceNV* decoded_value{ nullptr };

    Decoded_VkAccelerationStructureInstanceKHR*            staticInstance{ nullptr };
    Decoded_VkAccelerationStructureMatrixMotionInstanceNV* matrixMotionInstance{ nullptr };
    Decoded_VkAccelerationStructureSRTMotionInstanceNV*    srtMotionInstance{ nullptr };
};

// Decoded struct wrappers for Vulkan structures that require special processing.
struct Decoded_VkDescriptorImageInfo
{
    using struct_type = VkDescriptorImageInfo;

    VkDescriptorImageInfo* decoded_value{ nullptr };

    format::HandleId sampler{ format::kNullHandleId };
    format::HandleId imageView{ format::kNullHandleId };
};

struct Decoded_VkWriteDescriptorSet
{
    using struct_type = VkWriteDescriptorSet;

    VkWriteDescriptorSet* decoded_value{ nullptr };

    PNextNode*                                            pNext{ nullptr };
    format::HandleId                                      dstSet{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkDescriptorImageInfo>*  pImageInfo{ nullptr };
    StructPointerDecoder<Decoded_VkDescriptorBufferInfo>* pBufferInfo{ nullptr };
    HandlePointerDecoder<VkBufferView>                    pTexelBufferView;
};

struct Decoded_VkPerformanceValueINTEL
{
    using struct_type = VkPerformanceValueINTEL;

    VkPerformanceValueINTEL* decoded_value{ nullptr };

    Decoded_VkPerformanceValueDataINTEL* data{ nullptr };
};

struct Decoded_VkAccelerationStructureGeometryKHR
{
    using struct_type = VkAccelerationStructureGeometryKHR;

    VkAccelerationStructureGeometryKHR* decoded_value{ nullptr };

    PNextNode*                                      pNext{ nullptr };
    Decoded_VkAccelerationStructureGeometryDataKHR* geometry{ nullptr };
};

struct Decoded_VkPushDescriptorSetWithTemplateInfo
{
    using struct_type = VkPushDescriptorSetWithTemplateInfoKHR;

    struct_type* decoded_value{ nullptr };

    PNextNode*                      pNext{ nullptr };
    format::HandleId                descriptorUpdateTemplate{ format::kNullHandleId };
    format::HandleId                layout{ format::kNullHandleId };
    DescriptorUpdateTemplateDecoder pData;
};

// Decoded struct wrappers for SECURITY_ATTRIBUTES and related WIN32 structures.
struct Decoded_ACL
{
    using struct_type = ACL;

    ACL* decoded_value{ nullptr };
};

struct Decoded_SECURITY_DESCRIPTOR
{
    using struct_type = SECURITY_DESCRIPTOR;

    SECURITY_DESCRIPTOR* decoded_value{ nullptr };

    uint8_t*                Owner{ nullptr };
    uint8_t*                Group{ nullptr };
    PointerDecoder<uint8_t> PackedOwner;
    PointerDecoder<uint8_t> PackedGroup;

    StructPointerDecoder<Decoded_ACL>* Sacl{ nullptr };
    StructPointerDecoder<Decoded_ACL>* Dacl{ nullptr };
};

struct Decoded_SECURITY_ATTRIBUTES
{
    using struct_type = SECURITY_ATTRIBUTES;

    SECURITY_ATTRIBUTES* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_SECURITY_DESCRIPTOR>* lpSecurityDescriptor{ nullptr };
};

// This union wrapper does not have a DecodeStruct function.  It is decoded by the
// Decoded_VkIndirectExecutionSetCreateInfoEXT DecodeStruct function, based on the value of
// VkIndirectExecutionSetCreateInfoEXT::type.
struct Decoded_VkIndirectExecutionSetInfoEXT
{
    using struct_type = VkIndirectExecutionSetEXT;

    Decoded_VkIndirectExecutionSetPipelineInfoEXT* pPipelineInfo;
    Decoded_VkIndirectExecutionSetShaderInfoEXT*   pShaderInfo;
};

struct Decoded_VkIndirectExecutionSetCreateInfoEXT
{
    using struct_type = VkIndirectExecutionSetCreateInfoEXT;

    VkIndirectExecutionSetCreateInfoEXT* decoded_value{ nullptr };

    PNextNode*                             pNext{ nullptr };
    VkIndirectExecutionSetInfoTypeEXT      decoded_type;
    Decoded_VkIndirectExecutionSetInfoEXT* info;
};

struct Decoded_VkIndirectCommandsTokenDataEXT
{
    using struct_type = VkIndirectCommandsTokenDataEXT;

    Decoded_VkIndirectCommandsPushConstantTokenEXT* pPushConstant;
    Decoded_VkIndirectCommandsVertexBufferTokenEXT* pVertexBuffer;
    Decoded_VkIndirectCommandsIndexBufferTokenEXT*  pIndexBuffer;
    Decoded_VkIndirectCommandsExecutionSetTokenEXT* pExecutionSet;
};

struct Decoded_VkIndirectCommandsLayoutTokenEXT
{
    using struct_type = VkIndirectCommandsLayoutTokenEXT;

    VkIndirectCommandsLayoutTokenEXT* decoded_value;

    PNextNode*                              pNext{ nullptr };
    VkIndirectCommandsTokenTypeEXT          decoded_type;
    Decoded_VkIndirectCommandsTokenDataEXT* data;
    uint32_t                                offset;
};

struct Decoded_VkCopyMemoryToImageInfo
{
    using struct_type = VkCopyMemoryToImageInfo;

    VkCopyMemoryToImageInfo* decoded_value{ nullptr };

    PNextNode*                                         pNext{ nullptr };
    format::HandleId                                   dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkMemoryToImageCopy>* pRegions{ nullptr };
};

struct Decoded_VkMemoryToImageCopy
{
    using struct_type = VkMemoryToImageCopy;

    VkMemoryToImageCopy* decoded_value{ nullptr };

    PNextNode*                        pNext{ nullptr };
    PointerDecoder<uint8_t>           pHostPointer;
    Decoded_VkImageSubresourceLayers* imageSubresource{ nullptr };
    Decoded_VkOffset3D*               imageOffset{ nullptr };
    Decoded_VkExtent3D*               imageExtent{ nullptr };
};

struct Decoded_VkCopyImageToMemoryInfo
{
    using struct_type = VkCopyImageToMemoryInfo;

    VkCopyImageToMemoryInfo* decoded_value{ nullptr };

    PNextNode*                                         pNext{ nullptr };
    format::HandleId                                   srcImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageToMemoryCopy>* pRegions{ nullptr };
};

struct Decoded_VkImageToMemoryCopy
{
    using struct_type = VkImageToMemoryCopy;

    VkImageToMemoryCopy* decoded_value{ nullptr };

    PNextNode*                        pNext{ nullptr };
    PointerDecoder<uint8_t>           pHostPointer;
    Decoded_VkImageSubresourceLayers* imageSubresource{ nullptr };
    Decoded_VkOffset3D*               imageOffset{ nullptr };
    Decoded_VkExtent3D*               imageExtent{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_STRUCT_DECODERS_H
