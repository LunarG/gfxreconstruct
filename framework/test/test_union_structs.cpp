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

// Structs that hold a union picked by a selector member. The encoders in namespace oracle are the
// hand-written encoders these structs used before code generation; captures written by them must
// keep decoding.

#include <catch2/catch.hpp>

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/decode_allocator.h"
#include "decode/struct_pointer_decoder.h"
#include "encode/custom_vulkan_struct_encoders.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <cstring>
#include <memory>
#include <vector>

using namespace gfxrecon;

namespace oracle
{
using encode::ParameterEncoder;

void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureMotionInstanceNV& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeFlagsValue(value.flags);

    switch (value.type)
    {
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV:
            encode::EncodeStruct(encoder, value.data.staticInstance);
            break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV:
            encode::EncodeStruct(encoder, value.data.matrixMotionInstance);
            break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV:
            encode::EncodeStruct(encoder, value.data.srtMotionInstance);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const VkIndirectExecutionSetCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode::EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.type);
    switch (value.type)
    {
        case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT:
            encode::EncodeStructPtr(encoder, value.info.pPipelineInfo);
            break;
        case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_SHADER_OBJECTS_EXT:
            encode::EncodeStructPtr(encoder, value.info.pShaderInfo);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const VkIndirectCommandsLayoutTokenEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode::EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.type);
    switch (value.type)
    {
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_EXT:
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_SEQUENCE_INDEX_EXT:
            encode::EncodeStructPtr(encoder, value.data.pPushConstant);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT:
            encode::EncodeStructPtr(encoder, value.data.pVertexBuffer);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT:
            encode::EncodeStructPtr(encoder, value.data.pIndexBuffer);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT:
            encode::EncodeStructPtr(encoder, value.data.pExecutionSet);
            break;
        default:
            break;
    }
    encoder->EncodeUInt32Value(value.offset);
}

void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceValueINTEL& value)
{
    encoder->EncodeEnumValue(value.type);

    if (value.type == VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL)
    {
        encoder->EncodeString(value.data.valueString);
    }
    else
    {
        encoder->EncodeUInt64Value(value.data.value64);
    }
}
} // namespace oracle

namespace
{
using Bytes = std::vector<uint8_t>;

template <typename T>
Bytes EncodeCurrent(const T& value)
{
    encode::ParameterBuffer  buffer;
    encode::ParameterEncoder encoder(&buffer);
    encode::EncodeStruct(&encoder, value);
    return Bytes(buffer.GetData(), buffer.GetData() + buffer.GetDataSize());
}

template <typename T>
Bytes EncodeOracle(const T& value)
{
    encode::ParameterBuffer  buffer;
    encode::ParameterEncoder encoder(&buffer);
    oracle::EncodeStruct(&encoder, value);
    return Bytes(buffer.GetData(), buffer.GetData() + buffer.GetDataSize());
}

// Decodes bytes into wrapper, which must stay alive between DecodeAllocator::Begin and End.
template <typename Decoded>
void Decode(const Bytes& bytes, Decoded* wrapper, typename Decoded::struct_type* value)
{
    wrapper->decoded_value = value;
    REQUIRE(decode::DecodeStruct(bytes.data(), bytes.size(), wrapper) == bytes.size());
}

struct LogScope
{
    LogScope() { util::Log::Init(util::LoggingSeverity::kError); }
    ~LogScope() { util::Log::Release(); }
};

struct AllocatorScope
{
    AllocatorScope() { decode::DecodeAllocator::Begin(); }
    ~AllocatorScope() { decode::DecodeAllocator::End(); }
};
} // namespace

TEST_CASE("VkAccelerationStructureMotionInstanceNV encodes the active union member only", "[enc/dec][union]")
{
    LogScope log;

    VkAccelerationStructureMotionInstanceNV input;
    // Garbage in every byte the active member does not cover.
    std::memset(&input, 0xab, sizeof(input));
    input.flags = 0;

    const auto type = GENERATE(VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV,
                               VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV,
                               VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV);
    input.type      = type;
    size_t size     = 0;
    switch (type)
    {
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV:
            input.data.staticInstance = {
                { { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } } }, 7, 0x11, 3, 0x2, 0x1234
            };
            size = sizeof(input.data.staticInstance);
            break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV:
            input.data.matrixMotionInstance = { { { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } } },
                                                { { { 13, 14, 15, 16 }, { 17, 18, 19, 20 }, { 21, 22, 23, 24 } } },
                                                7,
                                                0x11,
                                                3,
                                                0x2,
                                                0x1234 };
            size                            = sizeof(input.data.matrixMotionInstance);
            break;
        default:
            input.data.srtMotionInstance = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 },
                                             { 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32 },
                                             7,
                                             0x11,
                                             3,
                                             0x2,
                                             0x1234 };
            size                         = sizeof(input.data.srtMotionInstance);
            break;
    }

    const Bytes bytes = EncodeCurrent(input);
    REQUIRE(bytes == EncodeOracle(input));

    AllocatorScope                                          allocator;
    decode::Decoded_VkAccelerationStructureMotionInstanceNV wrapper{};
    VkAccelerationStructureMotionInstanceNV                 output{};
    Decode(bytes, &wrapper, &output);

    REQUIRE(output.type == input.type);
    REQUIRE(output.flags == input.flags);
    REQUIRE(std::memcmp(&output.data, &input.data, size) == 0);
}

TEST_CASE("VkIndirectExecutionSetCreateInfoEXT encodes the active union member only", "[enc/dec][union]")
{
    LogScope log;

    VkIndirectExecutionSetPipelineInfoEXT pipeline_info{
        VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT, nullptr, VK_NULL_HANDLE, 7
    };
    VkIndirectExecutionSetShaderLayoutInfoEXT layout_info{
        VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT, nullptr, 0, nullptr
    };
    VkShaderEXT                         shader = VK_NULL_HANDLE;
    VkIndirectExecutionSetShaderInfoEXT shader_info{
        VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT, nullptr, 1, &shader, &layout_info, 9, 0, nullptr
    };

    VkIndirectExecutionSetCreateInfoEXT input{ VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT };
    input.type = GENERATE(VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT,
                          VK_INDIRECT_EXECUTION_SET_INFO_TYPE_SHADER_OBJECTS_EXT);
    if (input.type == VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT)
    {
        input.info.pPipelineInfo = &pipeline_info;
    }
    else
    {
        input.info.pShaderInfo = &shader_info;
    }

    const Bytes bytes = EncodeCurrent(input);
    REQUIRE(bytes == EncodeOracle(input));

    AllocatorScope                                      allocator;
    decode::Decoded_VkIndirectExecutionSetCreateInfoEXT wrapper{};
    VkIndirectExecutionSetCreateInfoEXT                 output{};
    Decode(bytes, &wrapper, &output);

    REQUIRE(output.sType == input.sType);
    REQUIRE(output.pNext == nullptr);
    REQUIRE(output.type == input.type);
    if (input.type == VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT)
    {
        REQUIRE(output.info.pPipelineInfo != nullptr);
        REQUIRE(output.info.pPipelineInfo->maxPipelineCount == pipeline_info.maxPipelineCount);
    }
    else
    {
        REQUIRE(output.info.pShaderInfo != nullptr);
        REQUIRE(output.info.pShaderInfo->shaderCount == shader_info.shaderCount);
        REQUIRE(output.info.pShaderInfo->maxShaderCount == shader_info.maxShaderCount);
    }
}

TEST_CASE("VkIndirectCommandsLayoutTokenEXT encodes the active union member and keeps offset", "[enc/dec][union]")
{
    LogScope log;

    VkIndirectCommandsPushConstantTokenEXT push_constant{ { VK_SHADER_STAGE_COMPUTE_BIT, 16, 32 } };
    VkIndirectCommandsVertexBufferTokenEXT vertex_buffer{ 5 };
    VkIndirectCommandsIndexBufferTokenEXT  index_buffer{ VK_INDIRECT_COMMANDS_INPUT_MODE_DXGI_INDEX_BUFFER_EXT };
    VkIndirectCommandsExecutionSetTokenEXT execution_set{ VK_INDIRECT_EXECUTION_SET_INFO_TYPE_SHADER_OBJECTS_EXT,
                                                          VK_SHADER_STAGE_COMPUTE_BIT };

    VkIndirectCommandsLayoutTokenEXT input{ VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT };
    input.offset = 0x1234;
    // Every selector value of the multi-value push constant member, plus one per other member.
    input.type              = GENERATE(VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_EXT,
                          VK_INDIRECT_COMMANDS_TOKEN_TYPE_SEQUENCE_INDEX_EXT,
                          VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_DATA_EXT,
                          VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_DATA_SEQUENCE_INDEX_EXT,
                          VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT,
                          VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT,
                          VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT);
    const bool is_push_data = (input.type == VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_DATA_EXT) ||
                              (input.type == VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_DATA_SEQUENCE_INDEX_EXT);
    switch (input.type)
    {
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT:
            input.data.pVertexBuffer = &vertex_buffer;
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT:
            input.data.pIndexBuffer = &index_buffer;
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT:
            input.data.pExecutionSet = &execution_set;
            break;
        default:
            input.data.pPushConstant = &push_constant;
            break;
    }

    const Bytes bytes = EncodeCurrent(input);
    // The hand-written encoder skipped the push data types; it matches for every other type.
    if (!is_push_data)
    {
        REQUIRE(bytes == EncodeOracle(input));
    }

    AllocatorScope                                   allocator;
    decode::Decoded_VkIndirectCommandsLayoutTokenEXT wrapper{};
    VkIndirectCommandsLayoutTokenEXT                 output{};
    Decode(bytes, &wrapper, &output);

    REQUIRE(output.sType == input.sType);
    REQUIRE(output.pNext == nullptr);
    REQUIRE(output.type == input.type);
    REQUIRE(output.offset == input.offset);
    switch (input.type)
    {
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT:
            REQUIRE(output.data.pVertexBuffer != nullptr);
            REQUIRE(output.data.pVertexBuffer->vertexBindingUnit == vertex_buffer.vertexBindingUnit);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT:
            REQUIRE(output.data.pIndexBuffer != nullptr);
            REQUIRE(output.data.pIndexBuffer->mode == index_buffer.mode);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT:
            REQUIRE(output.data.pExecutionSet != nullptr);
            REQUIRE(output.data.pExecutionSet->type == execution_set.type);
            REQUIRE(output.data.pExecutionSet->shaderStages == execution_set.shaderStages);
            break;
        default:
            REQUIRE(output.data.pPushConstant != nullptr);
            REQUIRE(output.data.pPushConstant->updateRange.stageFlags == push_constant.updateRange.stageFlags);
            REQUIRE(output.data.pPushConstant->updateRange.offset == push_constant.updateRange.offset);
            REQUIRE(output.data.pPushConstant->updateRange.size == push_constant.updateRange.size);
            break;
    }
}

TEST_CASE("VkPerformanceValueINTEL keeps the 8-byte capture layout", "[enc/dec][union]")
{
    LogScope log;

    VkPerformanceValueINTEL input;
    // Garbage in the upper half, which the old encoder copied into the capture.
    std::memset(&input, 0xab, sizeof(input));
    input.type = GENERATE(VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL,
                          VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL,
                          VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL,
                          VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL);
    switch (input.type)
    {
        case VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL:
            input.data.value32 = 0x12345678u;
            break;
        case VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL:
            input.data.value64 = 0x1122334455667788ull;
            break;
        case VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL:
            input.data.valueFloat = 1.5f;
            break;
        default:
            input.data.valueBool = VK_TRUE;
            break;
    }

    const Bytes old_bytes = EncodeOracle(input);
    const Bytes new_bytes = EncodeCurrent(input);
    REQUIRE(new_bytes.size() == old_bytes.size());

    // The active member decodes the same from old and new captures.
    for (const Bytes* bytes : { &old_bytes, &new_bytes })
    {
        AllocatorScope                          allocator;
        decode::Decoded_VkPerformanceValueINTEL wrapper{};
        VkPerformanceValueINTEL                 output{};
        Decode(*bytes, &wrapper, &output);

        REQUIRE(output.type == input.type);
        switch (input.type)
        {
            case VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL:
                REQUIRE(output.data.value32 == input.data.value32);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL:
                REQUIRE(output.data.value64 == input.data.value64);
                break;
            case VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL:
                REQUIRE(output.data.valueFloat == input.data.valueFloat);
                break;
            default:
                REQUIRE(output.data.valueBool == input.data.valueBool);
                break;
        }
    }

    // New captures no longer copy the bytes the active member does not cover.
    if (input.type != VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL)
    {
        uint64_t written = 0;
        std::memcpy(&written, new_bytes.data() + new_bytes.size() - sizeof(written), sizeof(written));
        REQUIRE((written >> 32) == 0);
    }
}
