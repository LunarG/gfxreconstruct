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

#ifndef GFXRECON_VULKAN_ALIASING_GROUP_MODIFIER_H
#define GFXRECON_VULKAN_ALIASING_GROUP_MODIFIER_H

#include "vulkan_aliasing_groups.h"
#include "vulkan_modifier_base.h"

#include "encode/vulkan_resource_aliasing_writer.h"

#include <map>
#include <set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

/**
 * @brief   Detects resources that alias one another in device memory and records them in the capture.
 *
 * The scan pass follows resource creation, memory requirement queries, binds and destruction; the
 * modification pass writes one resource aliasing groups meta-data block per device, right after the
 * vkCreateDevice the groups belong to.  A replayer that understands the block can place the whole
 * group in one allocation instead of discovering the overlaps one bind at a time.
 */
class VulkanAliasingGroupModifier : public VulkanModifierBase
{
  public:
    bool CanOptimize() override;

    void Process_vkCreateDevice(const decode::ApiCallInfo& call_info, decode::args::CreateDevice& args) override;

    void Process_vkCreateBuffer(const decode::ApiCallInfo& call_info, decode::args::CreateBuffer& args) override;
    void Process_vkCreateImage(const decode::ApiCallInfo& call_info, decode::args::CreateImage& args) override;
    void Process_vkCreateTensorARM(const decode::ApiCallInfo& call_info, decode::args::CreateTensorARM& args) override;

    void Process_vkDestroyBuffer(const decode::ApiCallInfo& call_info, decode::args::DestroyBuffer& args) override;
    void Process_vkDestroyImage(const decode::ApiCallInfo& call_info, decode::args::DestroyImage& args) override;
    void Process_vkDestroyTensorARM(const decode::ApiCallInfo&      call_info,
                                    decode::args::DestroyTensorARM& args) override;

    void Process_vkGetBufferMemoryRequirements(const decode::ApiCallInfo&                 call_info,
                                               decode::args::GetBufferMemoryRequirements& args) override;
    void Process_vkGetBufferMemoryRequirements2(const decode::ApiCallInfo&                  call_info,
                                                decode::args::GetBufferMemoryRequirements2& args) override;
    void Process_vkGetBufferMemoryRequirements2KHR(const decode::ApiCallInfo&                     call_info,
                                                   decode::args::GetBufferMemoryRequirements2KHR& args) override;
    void Process_vkGetImageMemoryRequirements(const decode::ApiCallInfo&                call_info,
                                              decode::args::GetImageMemoryRequirements& args) override;
    void Process_vkGetImageMemoryRequirements2(const decode::ApiCallInfo&                 call_info,
                                               decode::args::GetImageMemoryRequirements2& args) override;
    void Process_vkGetImageMemoryRequirements2KHR(const decode::ApiCallInfo&                    call_info,
                                                  decode::args::GetImageMemoryRequirements2KHR& args) override;
    void Process_vkGetTensorMemoryRequirementsARM(const decode::ApiCallInfo&                    call_info,
                                                  decode::args::GetTensorMemoryRequirementsARM& args) override;

    void Process_vkBindBufferMemory(const decode::ApiCallInfo&      call_info,
                                    decode::args::BindBufferMemory& args) override;
    void Process_vkBindBufferMemory2(const decode::ApiCallInfo&       call_info,
                                     decode::args::BindBufferMemory2& args) override;
    void Process_vkBindBufferMemory2KHR(const decode::ApiCallInfo&          call_info,
                                        decode::args::BindBufferMemory2KHR& args) override;
    void Process_vkBindImageMemory(const decode::ApiCallInfo& call_info, decode::args::BindImageMemory& args) override;
    void Process_vkBindImageMemory2(const decode::ApiCallInfo&      call_info,
                                    decode::args::BindImageMemory2& args) override;
    void Process_vkBindImageMemory2KHR(const decode::ApiCallInfo&         call_info,
                                       decode::args::BindImageMemory2KHR& args) override;
    void Process_vkBindTensorMemoryARM(const decode::ApiCallInfo&         call_info,
                                       decode::args::BindTensorMemoryARM& args) override;

    // Binds this pass does not model.  They are not grouped by accident: the memory they touch is
    // excluded, because a group allocation would have to account for what they placed in it.
    void Process_vkQueueBindSparse(const decode::ApiCallInfo& call_info, decode::args::QueueBindSparse& args) override;
    void Process_vkBindVideoSessionMemoryKHR(const decode::ApiCallInfo&               call_info,
                                             decode::args::BindVideoSessionMemoryKHR& args) override;
    void Process_vkBindAccelerationStructureMemoryNV(const decode::ApiCallInfo&                       call_info,
                                                     decode::args::BindAccelerationStructureMemoryNV& args) override;
    void
    Process_vkBindDataGraphPipelineSessionMemoryARM(const decode::ApiCallInfo&                           call_info,
                                                    decode::args::BindDataGraphPipelineSessionMemoryARM& args) override;

  private:
    /// A buffer, image or tensor followed from its creation to its bind.
    struct TrackedResource
    {
        format::HandleId                   device_id{ format::kNullHandleId };
        encode::ResourceAliasingCreateInfo create_info;
        uint64_t                           create_size{ 0 };      ///< Extent from the create-info, buffers only.
        uint64_t                           requirement_size{ 0 }; ///< Extent from a memory requirement query.
        format::HandleId                   memory_id{ format::kNullHandleId };
        uint64_t                           bind_offset{ 0 };
        uint64_t                           bind_index{ 0 };
        uint64_t                           destroy_index{ AliasingCandidate::kNeverDestroyed };
        bool                               bound{ false };
        bool                               excluded{ false }; ///< Left to the replayer's per-bind detection.
    };

    // The KHR promotions take a distinct argument struct holding the same members, so the bodies they
    // share are templates.  They are instantiated in the one translation unit that defines them.
    template <typename Args>
    void RecordBufferRequirements2(Args& args);
    template <typename Args>
    void RecordImageRequirements2(Args& args);
    template <typename Args>
    void RecordBufferBinds2(Args& args, uint64_t block_index);
    template <typename Args>
    void RecordImageBinds2(Args& args, uint64_t block_index);

    void RecordCreate(format::HandleId                     device_id,
                      format::HandleId                     resource_id,
                      encode::ResourceAliasingCreateInfo&& create_info,
                      uint64_t                             create_size);
    void RecordDestroy(format::HandleId resource_id, uint64_t block_index);
    void RecordRequirementSize(format::HandleId resource_id, uint64_t size);
    void RecordBind(format::HandleId resource_id, format::HandleId memory_id, uint64_t offset, uint64_t block_index);
    void ExcludeMemory(format::HandleId memory_id);

    std::map<format::HandleId, TrackedResource> resources_;
    std::set<format::HandleId>                  excluded_memories_;

    /// Filled by CanOptimize(), read by the modification pass.  A device with no groups has no entry.
    std::map<format::HandleId, std::vector<encode::ResourceAliasingGroupInfo>> groups_by_device_;
    std::set<format::HandleId>                                                 emitted_devices_;
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_VULKAN_ALIASING_GROUP_MODIFIER_H
