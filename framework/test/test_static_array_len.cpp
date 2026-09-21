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

/// @file Encode/decode round trips for fixed-extent ("static") array members whose registry 'len' names a
/// sibling count member, e.g. VkQueueFamilyGlobalPriorityProperties::priorities[VK_MAX_GLOBAL_PRIORITY_SIZE]
/// with len="priorityCount".  The encoder writes 'count' elements; the decoder must accept that, the full
/// capacity written by older captures, and any other in-range length, while staying in sync with the stream.

#include <catch2/catch.hpp>

#include "decode/decode_allocator.h"
#include "decode/value_decoder.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <memory>

namespace
{
using namespace gfxrecon;

constexpr uint32_t kSentinel = 0xDEADBEEF;

VkQueueFamilyGlobalPriorityProperties MakePriorityProperties(uint32_t count)
{
    VkQueueFamilyGlobalPriorityProperties props{};
    props.sType         = VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES;
    props.priorityCount = count;

    const VkQueueGlobalPriority values[] = { VK_QUEUE_GLOBAL_PRIORITY_LOW,
                                             VK_QUEUE_GLOBAL_PRIORITY_MEDIUM,
                                             VK_QUEUE_GLOBAL_PRIORITY_HIGH,
                                             VK_QUEUE_GLOBAL_PRIORITY_REALTIME };
    for (uint32_t i = 0; i < VK_MAX_GLOBAL_PRIORITY_SIZE; ++i)
    {
        props.priorities[i] = values[i % 4];
    }
    return props;
}

// Writes the struct the way the generated encoders did before the registry 'len' was honored: the count member
// followed by 'array_length' elements of the fixed-extent array.
void EncodeWithArrayLength(encode::ParameterEncoder*                    encoder,
                           const VkQueueFamilyGlobalPriorityProperties& props,
                           size_t                                       array_length)
{
    encoder->EncodeEnumValue(props.sType);
    encode::EncodePNextStruct(encoder, props.pNext);
    encoder->EncodeUInt32Value(props.priorityCount);
    encoder->EncodeEnumArray(props.priorities, array_length);
}

struct DecodeResult
{
    VkQueueFamilyGlobalPriorityProperties value{};
    size_t                                array_length{ 0 };
};

// Decodes the struct followed by the sentinel, verifying the decoder consumed exactly the struct's bytes.
DecodeResult DecodeAndCheckSync(const encode::ParameterBuffer& buffer)
{
    DecodeResult result;

    decode::DecodeAllocator::Begin();

    decode::Decoded_VkQueueFamilyGlobalPriorityProperties wrapper;
    wrapper.decoded_value = &result.value;

    const uint8_t* data       = buffer.GetData();
    size_t         size       = buffer.GetDataSize();
    size_t         bytes_read = decode::DecodeStruct(data, size, &wrapper);
    result.array_length       = wrapper.priorities.GetLength();

    uint32_t sentinel = 0;
    bytes_read += decode::ValueDecoder::DecodeUInt32Value(data + bytes_read, size - bytes_read, &sentinel);
    REQUIRE(bytes_read == size);
    REQUIRE(sentinel == kSentinel);

    decode::DecodeAllocator::End();
    return result;
}
} // namespace

TEST_CASE("Counted static array encodes the counted elements, not the capacity", "[enc/dec]")
{
    util::Log::Init(util::LoggingSeverity::kError);
    auto buffer  = std::make_unique<encode::ParameterBuffer>();
    auto encoder = std::make_unique<encode::ParameterEncoder>(buffer.get());

    const uint32_t count = 3;
    const auto     props = MakePriorityProperties(count);

    encode::EncodeStruct(encoder.get(), props);
    encoder->EncodeUInt32Value(kSentinel);

    const auto decoded = DecodeAndCheckSync(*buffer);
    REQUIRE(decoded.array_length == count);
    REQUIRE(decoded.value.priorityCount == count);
    for (uint32_t i = 0; i < count; ++i)
    {
        REQUIRE(decoded.value.priorities[i] == props.priorities[i]);
    }
    // Elements past the count are never written by the decoder.
    for (uint32_t i = count; i < VK_MAX_GLOBAL_PRIORITY_SIZE; ++i)
    {
        REQUIRE(decoded.value.priorities[i] == 0);
    }
}

TEST_CASE("Counted static array holding the full capacity (older captures) still decodes", "[enc/dec]")
{
    util::Log::Init(util::LoggingSeverity::kError);
    auto buffer  = std::make_unique<encode::ParameterBuffer>();
    auto encoder = std::make_unique<encode::ParameterEncoder>(buffer.get());

    const uint32_t count = 3;
    const auto     props = MakePriorityProperties(count);

    EncodeWithArrayLength(encoder.get(), props, VK_MAX_GLOBAL_PRIORITY_SIZE);
    encoder->EncodeUInt32Value(kSentinel);

    const auto decoded = DecodeAndCheckSync(*buffer);
    REQUIRE(decoded.array_length == VK_MAX_GLOBAL_PRIORITY_SIZE);
    REQUIRE(decoded.value.priorityCount == count);
    for (uint32_t i = 0; i < VK_MAX_GLOBAL_PRIORITY_SIZE; ++i)
    {
        REQUIRE(decoded.value.priorities[i] == props.priorities[i]);
    }
}

TEST_CASE("Counted static array with a length matching neither count nor capacity stays in sync", "[enc/dec]")
{
    // The decoder reports this case (see PointerDecoderBase::CheckExpectedLength); the block must still decode.
    util::Log::Init(util::LoggingSeverity::kFatal);
    auto buffer  = std::make_unique<encode::ParameterBuffer>();
    auto encoder = std::make_unique<encode::ParameterEncoder>(buffer.get());

    const uint32_t count         = 3;
    const size_t   stream_length = 5;
    const auto     props         = MakePriorityProperties(count);

    EncodeWithArrayLength(encoder.get(), props, stream_length);
    encoder->EncodeUInt32Value(kSentinel);

    const auto decoded = DecodeAndCheckSync(*buffer);
    REQUIRE(decoded.array_length == stream_length);
    for (size_t i = 0; i < stream_length; ++i)
    {
        REQUIRE(decoded.value.priorities[i] == props.priorities[i]);
    }
}

TEST_CASE("Counted static array longer than the capacity is truncated but stays in sync", "[enc/dec]")
{
    util::Log::Init(util::LoggingSeverity::kFatal);
    auto buffer  = std::make_unique<encode::ParameterBuffer>();
    auto encoder = std::make_unique<encode::ParameterEncoder>(buffer.get());

    // Build a source array larger than the struct member so the over-long stream can be produced.
    VkQueueGlobalPriority oversized[VK_MAX_GLOBAL_PRIORITY_SIZE + 4];
    for (auto& priority : oversized)
    {
        priority = VK_QUEUE_GLOBAL_PRIORITY_HIGH;
    }
    auto props = MakePriorityProperties(VK_MAX_GLOBAL_PRIORITY_SIZE + 4);

    encoder->EncodeEnumValue(props.sType);
    encode::EncodePNextStruct(encoder.get(), props.pNext);
    encoder->EncodeUInt32Value(props.priorityCount);
    encoder->EncodeEnumArray(oversized, VK_MAX_GLOBAL_PRIORITY_SIZE + 4);
    encoder->EncodeUInt32Value(kSentinel);

    const auto decoded = DecodeAndCheckSync(*buffer);
    REQUIRE(decoded.array_length == VK_MAX_GLOBAL_PRIORITY_SIZE + 4);
    for (uint32_t i = 0; i < VK_MAX_GLOBAL_PRIORITY_SIZE; ++i)
    {
        REQUIRE(decoded.value.priorities[i] == VK_QUEUE_GLOBAL_PRIORITY_HIGH);
    }
}

TEST_CASE("ClampStaticArrayLength bounds the count by the capacity", "[encode]")
{
    util::Log::Init(util::LoggingSeverity::kFatal);
    REQUIRE(encode::ParameterEncoder::ClampStaticArrayLength(0, 16, "test") == 0);
    REQUIRE(encode::ParameterEncoder::ClampStaticArrayLength(3, 16, "test") == 3);
    REQUIRE(encode::ParameterEncoder::ClampStaticArrayLength(16, 16, "test") == 16);
    REQUIRE(encode::ParameterEncoder::ClampStaticArrayLength(17, 16, "test") == 16);
}

TEST_CASE("Counted static struct array encodes the counted elements", "[enc/dec]")
{
    util::Log::Init(util::LoggingSeverity::kError);
    auto buffer  = std::make_unique<encode::ParameterBuffer>();
    auto encoder = std::make_unique<encode::ParameterEncoder>(buffer.get());

    VkPhysicalDeviceMemoryProperties props{};
    props.memoryTypeCount = 2;
    props.memoryTypes[0]  = { VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, 0 };
    props.memoryTypes[1]  = { VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, 1 };
    props.memoryHeapCount = 1;
    props.memoryHeaps[0]  = { 1024, VK_MEMORY_HEAP_DEVICE_LOCAL_BIT };

    encode::EncodeStruct(encoder.get(), props);
    encoder->EncodeUInt32Value(kSentinel);

    decode::DecodeAllocator::Begin();

    VkPhysicalDeviceMemoryProperties                 decoded{};
    decode::Decoded_VkPhysicalDeviceMemoryProperties wrapper;
    wrapper.decoded_value = &decoded;

    const uint8_t* data       = buffer->GetData();
    size_t         size       = buffer->GetDataSize();
    size_t         bytes_read = decode::DecodeStruct(data, size, &wrapper);

    uint32_t sentinel = 0;
    bytes_read += decode::ValueDecoder::DecodeUInt32Value(data + bytes_read, size - bytes_read, &sentinel);
    REQUIRE(bytes_read == size);
    REQUIRE(sentinel == kSentinel);

    REQUIRE(wrapper.memoryTypes->GetLength() == props.memoryTypeCount);
    REQUIRE(wrapper.memoryHeaps->GetLength() == props.memoryHeapCount);
    REQUIRE(decoded.memoryTypeCount == props.memoryTypeCount);
    REQUIRE(decoded.memoryHeapCount == props.memoryHeapCount);
    for (uint32_t i = 0; i < props.memoryTypeCount; ++i)
    {
        REQUIRE(decoded.memoryTypes[i].propertyFlags == props.memoryTypes[i].propertyFlags);
        REQUIRE(decoded.memoryTypes[i].heapIndex == props.memoryTypes[i].heapIndex);
    }
    REQUIRE(decoded.memoryHeaps[0].size == props.memoryHeaps[0].size);
    REQUIRE(decoded.memoryHeaps[0].flags == props.memoryHeaps[0].flags);

    decode::DecodeAllocator::End();
}
