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

#ifndef GFXRECON_DECODE_VULKAN_TRIM_STATE_BINDING_CONSUMER_H
#define GFXRECON_DECODE_VULKAN_TRIM_STATE_BINDING_CONSUMER_H

#include "format/format.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <optional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// A buffer or image bound to a memory object.
struct TrimStateMemoryBinding
{
    format::HandleId resource{ format::kNullHandleId };
    bool             is_image{ false };
    VkDeviceSize     offset{ 0 };
};

// The one resource each memory object is bound to, by memory object.
using TrimStateMemoryBindings = std::unordered_map<format::HandleId, TrimStateMemoryBinding>;

// Reads the state setup of a trimmed capture for the memory objects bound to exactly one buffer or image.
//
// Replay adds transfer usage to the buffers and images it creates while loading trim state, which can raise their
// memory requirements past the allocation the capture recorded. An allocation bound to one resource can grow to fit it
// without moving anything else.
class VulkanTrimStateBindingConsumer : public VulkanConsumer
{
  public:
    void ProcessStateBeginMarker(uint64_t frame_number) override;

    void ProcessStateEndMarker(uint64_t frame_number) override;

    // Called for every API call block. One outside the state setup means the setup is over, or that the capture is
    // not trimmed.
    void ProcessApiCall();

    bool IsComplete(uint64_t block_index) override { return complete_; }

    void Process_vkBindBufferMemory(const ApiCallInfo& call_info, args::BindBufferMemory& args) override;

    void Process_vkBindImageMemory(const ApiCallInfo& call_info, args::BindImageMemory& args) override;

    void Process_vkBindBufferMemory2(const ApiCallInfo& call_info, args::BindBufferMemory2& args) override;

    void Process_vkBindImageMemory2(const ApiCallInfo& call_info, args::BindImageMemory2& args) override;

    void Process_vkBindBufferMemory2KHR(const ApiCallInfo& call_info, args::BindBufferMemory2KHR& args) override;

    void Process_vkBindImageMemory2KHR(const ApiCallInfo& call_info, args::BindImageMemory2KHR& args) override;

    TrimStateMemoryBindings GetSoleBindings() const;

  private:
    void AddBufferBindings(uint32_t count, StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& infos);

    void AddImageBindings(uint32_t count, StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& infos);

    void Add(format::HandleId memory, format::HandleId resource, bool is_image, VkDeviceSize offset);

    bool in_state_{ false };
    bool complete_{ false };

    std::unordered_map<format::HandleId, std::vector<TrimStateMemoryBinding>> bindings_;

    // Memory bound to one plane of a disjoint image, whose requirements are per plane.
    std::unordered_set<format::HandleId> plane_bound_memory_;
};

// Runs VulkanTrimStateBindingConsumer over a capture file. Reading stops at the end of the state setup, or at the
// first API call of a capture that has none.
TrimStateMemoryBindings ScanTrimStateMemoryBindings(const std::string& filename);

// The size an allocation needs so that the one resource bound at `binding_offset` fits its replay `requirements`: at
// least `allocation_size`. Empty when the replay alignment rules out the captured offset, which growing cannot fix.
std::optional<VkDeviceSize> GrownTrimStateAllocationSize(VkDeviceSize                allocation_size,
                                                         VkDeviceSize                binding_offset,
                                                         const VkMemoryRequirements& requirements);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_TRIM_STATE_BINDING_CONSUMER_H
