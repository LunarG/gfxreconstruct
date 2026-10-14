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

#include "decode/vulkan_trim_state_binding_consumer.h"

#include "decode/file_processor.h"
#include "generated/generated_vulkan_decoder.h"
#include "graphics/vulkan_struct_get_pnext.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanTrimStateBindingConsumer::ProcessStateBeginMarker(uint64_t frame_number)
{
    GFXRECON_UNREFERENCED_PARAMETER(frame_number);
    in_state_ = true;
}

void VulkanTrimStateBindingConsumer::ProcessStateEndMarker(uint64_t frame_number)
{
    GFXRECON_UNREFERENCED_PARAMETER(frame_number);
    in_state_ = false;
    complete_ = true;
}

void VulkanTrimStateBindingConsumer::ProcessApiCall()
{
    if (!in_state_)
    {
        complete_ = true;
    }
}

void VulkanTrimStateBindingConsumer::Process_vkBindBufferMemory(const ApiCallInfo&      call_info,
                                                                args::BindBufferMemory& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    Add(args.memory, args.buffer, false, args.memoryOffset);
}

void VulkanTrimStateBindingConsumer::Process_vkBindImageMemory(const ApiCallInfo&     call_info,
                                                               args::BindImageMemory& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    Add(args.memory, args.image, true, args.memoryOffset);
}

void VulkanTrimStateBindingConsumer::Process_vkBindBufferMemory2(const ApiCallInfo&       call_info,
                                                                 args::BindBufferMemory2& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    AddBufferBindings(args.bindInfoCount, args.pBindInfos);
}

void VulkanTrimStateBindingConsumer::Process_vkBindImageMemory2(const ApiCallInfo&      call_info,
                                                                args::BindImageMemory2& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    AddImageBindings(args.bindInfoCount, args.pBindInfos);
}

void VulkanTrimStateBindingConsumer::Process_vkBindBufferMemory2KHR(const ApiCallInfo&          call_info,
                                                                    args::BindBufferMemory2KHR& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    AddBufferBindings(args.bindInfoCount, args.pBindInfos);
}

void VulkanTrimStateBindingConsumer::Process_vkBindImageMemory2KHR(const ApiCallInfo&         call_info,
                                                                   args::BindImageMemory2KHR& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    AddImageBindings(args.bindInfoCount, args.pBindInfos);
}

TrimStateMemoryBindings VulkanTrimStateBindingConsumer::GetSoleBindings() const
{
    TrimStateMemoryBindings sole;
    for (const auto& entry : bindings_)
    {
        if ((entry.second.size() == 1) && (plane_bound_memory_.count(entry.first) == 0))
        {
            sole.emplace(entry.first, entry.second.front());
        }
    }
    return sole;
}

void VulkanTrimStateBindingConsumer::AddBufferBindings(uint32_t                                              count,
                                                       StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& infos)
{
    const auto* meta_infos = infos.GetMetaStructPointer();
    for (uint32_t i = 0; (meta_infos != nullptr) && (i < count); ++i)
    {
        Add(meta_infos[i].memory, meta_infos[i].buffer, false, meta_infos[i].decoded_value->memoryOffset);
    }
}

void VulkanTrimStateBindingConsumer::AddImageBindings(uint32_t                                             count,
                                                      StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& infos)
{
    const auto* meta_infos = infos.GetMetaStructPointer();
    for (uint32_t i = 0; (meta_infos != nullptr) && (i < count); ++i)
    {
        const VkBindImageMemoryInfo* info = meta_infos[i].decoded_value;
        Add(meta_infos[i].memory, meta_infos[i].image, true, info->memoryOffset);

        if ((meta_infos[i].memory != format::kNullHandleId) &&
            (graphics::vulkan_struct_get_pnext<VkBindImagePlaneMemoryInfo>(info) != nullptr))
        {
            plane_bound_memory_.insert(meta_infos[i].memory);
        }
    }
}

void VulkanTrimStateBindingConsumer::Add(format::HandleId memory,
                                         format::HandleId resource,
                                         bool             is_image,
                                         VkDeviceSize     offset)
{
    // A null memory handle is a swapchain image's bind, which has no allocation to grow.
    if (!in_state_ || (memory == format::kNullHandleId) || (resource == format::kNullHandleId))
    {
        return;
    }

    bindings_[memory].push_back({ resource, is_image, offset });
}

namespace
{

// Tells the consumer about every API call block, of any API, so that it can stop at the first one outside the state
// setup.
class TrimStateScanDecoder : public VulkanDecoder
{
  public:
    explicit TrimStateScanDecoder(VulkanTrimStateBindingConsumer* consumer) : consumer_(consumer) {}

    bool SupportsApiCall(format::ApiCallId call_id) override
    {
        consumer_->ProcessApiCall();
        return VulkanDecoder::SupportsApiCall(call_id);
    }

  private:
    VulkanTrimStateBindingConsumer* consumer_;
};

} // namespace

TrimStateMemoryBindings ScanTrimStateMemoryBindings(const std::string& filename)
{
    VulkanTrimStateBindingConsumer consumer;
    TrimStateScanDecoder           decoder(&consumer);
    FileProcessor                  file_processor;

    if (!file_processor.Initialize(filename))
    {
        return {};
    }

    decoder.AddConsumer(&consumer);
    file_processor.AddDecoder(&decoder);
    file_processor.InitializeFrameProcessing();
    file_processor.ProcessAllFrames();

    return consumer.GetSoleBindings();
}

std::optional<VkDeviceSize> GrownTrimStateAllocationSize(VkDeviceSize                allocation_size,
                                                         VkDeviceSize                binding_offset,
                                                         const VkMemoryRequirements& requirements)
{
    // The bind keeps its captured offset.
    if ((requirements.alignment != 0) && ((binding_offset % requirements.alignment) != 0))
    {
        return std::nullopt;
    }

    return std::max(allocation_size, binding_offset + requirements.size);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
