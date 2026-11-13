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

#include "decode/vulkan_stage_isolate_render_pass.h"

#include "format/format.h"
#include "generated/generated_vulkan_decoder.h"

#include <vector>
#include <cstring>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace
{

// ByteWriter appends values to a byte vector. Each Put returns the writer, so the calls chain.
class ByteWriter
{
  public:
    template <typename T>
    ByteWriter& Put(T value)
    {
        const auto* first = reinterpret_cast<const uint8_t*>(&value);
        bytes_.insert(bytes_.end(), first, first + sizeof(T));
        return *this;
    }

    const std::vector<uint8_t>& Bytes() const { return bytes_; }

  private:
    std::vector<uint8_t> bytes_;
};

// A pointer starts with an attribute word. An address follows when kHasAddress is set, and the data
// follows when kHasData is set. Array data starts with its length.
constexpr uint32_t kStructPointer     = format::kIsStruct | format::kIsSingle | format::kHasAddress | format::kHasData;
constexpr uint32_t kNullStructPointer = format::kIsStruct | format::kIsSingle | format::kIsNull;
constexpr uint32_t kArrayPointer      = format::kIsArray | format::kHasAddress | format::kHasData;

// The decoder reads the address of a pointer, but these calls never use it, so any non-zero value works.
constexpr uint64_t kUnusedAddress = 1;

// Each function below writes the parameters of one call in the order that its Decode_vk* function
// reads them. The result always comes last.

std::vector<uint8_t> EndBytes(format::HandleId command_buffer)
{
    return ByteWriter().Put<format::HandleId>(command_buffer).Put<int32_t>(VK_SUCCESS).Bytes();
}

std::vector<uint8_t> AllocateBytes(format::HandleId device, format::HandleId pool, format::HandleId command_buffer)
{
    return ByteWriter()
        .Put<format::HandleId>(device)                                 // device
        .Put<uint32_t>(kStructPointer)                                 // pAllocateInfo
        .Put<uint64_t>(kUnusedAddress)                                 //   address
        .Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO) //   sType
        .Put<uint32_t>(kNullStructPointer)                             //   pNext
        .Put<format::HandleId>(pool)                                   //   commandPool
        .Put<uint32_t>(VK_COMMAND_BUFFER_LEVEL_PRIMARY)                //   level
        .Put<uint32_t>(1)                                              //   commandBufferCount
        .Put<uint32_t>(kArrayPointer)                                  // pCommandBuffers
        .Put<uint64_t>(kUnusedAddress)                                 //   address
        .Put<uint64_t>(1)                                              //   array length
        .Put<format::HandleId>(command_buffer)                         //   id
        .Put<int32_t>(VK_SUCCESS)                                      // result
        .Bytes();
}

std::vector<uint8_t> BeginBytes(format::HandleId command_buffer, VkCommandBufferUsageFlags flags)
{
    return ByteWriter()
        .Put<format::HandleId>(command_buffer)                      // commandBuffer
        .Put<uint32_t>(kStructPointer)                              // pBeginInfo
        .Put<uint64_t>(kUnusedAddress)                              //   address
        .Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO) //   sType
        .Put<uint32_t>(kNullStructPointer)                          //   pNext
        .Put<uint32_t>(flags)                                       //   flags
        .Put<uint32_t>(kNullStructPointer)                          //   pInheritanceInfo
        .Put<int32_t>(VK_SUCCESS)                                   // result
        .Bytes();
}

} // namespace

void VulkanStageIsolateRenderPass::Split(Recording& recording, const ApiCallInfo& call_info)
{
    recording.split_pending = false;

    const format::HandleId synthetic_id = kSyntheticBit | next_synthetic_id_++;

    Emit(format::ApiCallId::ApiCall_vkEndCommandBuffer, call_info, EndBytes(recording.current_command_buffer_id));
    Emit(format::ApiCallId::ApiCall_vkAllocateCommandBuffers,
         call_info,
         AllocateBytes(recording.device_id, recording.pool_id, synthetic_id));
    Emit(format::ApiCallId::ApiCall_vkBeginCommandBuffer, call_info, BeginBytes(synthetic_id, recording.begin_flags));

    recording.current_command_buffer_id = synthetic_id;
    recording.working_command_count     = 0;

    ReissueStateCommands(recording);
}

void VulkanStageIsolateRenderPass::ReissueStateCommands(const Recording& recording)
{
    recording.state_log.ForEach([this, &recording](format::ApiCallId  call_id,
                                                   const ApiCallInfo& call_info,
                                                   const uint8_t*     parameter_buffer,
                                                   size_t             buffer_size) {
        std::vector<uint8_t> modified_buffer(parameter_buffer, parameter_buffer + buffer_size);
        // First 8 bytes of the parameter buffer contain the original command buffer ID.
        // Before emitting the state commands, overwrite it with the current command buffer ID.
        GFXRECON_ASSERT(buffer_size >= sizeof(format::HandleId));
        std::memcpy(modified_buffer.data(), &recording.current_command_buffer_id, sizeof(format::HandleId));

        Emit(call_id, call_info, modified_buffer);
    });
}

void VulkanStageIsolateRenderPass::Emit(format::ApiCallId        call_id,
                                        const ApiCallInfo&       call_info,
                                        std::span<const uint8_t> bytes)
{
    // The local decoder hands the call to the next consumers only, so the call never comes back into this stage.
    VulkanDecoder decoder;
    for (auto* consumer : GetNextConsumers())
    {
        decoder.AddConsumer(consumer);
    }

    // Emit opens no DecoderAllocGuard, because the app call's allocator scope is still open
    // and a nested Begin asserts.
    decoder.DecodeFunctionCall(call_id, call_info, bytes.data(), bytes.size());

    // The local decoder gave the next consumers the bytes of the invented call. Give them back the bytes
    // of the app call, because the stage forwards that call next.
    Broadcast(&VulkanConsumer::SetCurrentCallBytes, GetCurrentCallBytes());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
