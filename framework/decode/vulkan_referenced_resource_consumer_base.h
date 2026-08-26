/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_REFERENCED_RESOURCE_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_REFERENCED_RESOURCE_CONSUMER_BASE_H

#include "decode/referenced_resource_table.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <functional>
#include <limits>
#include <unordered_map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReferencedResourceConsumerBase : public VulkanConsumer
{
  public:
    VulkanReferencedResourceConsumerBase() = default;

    void GetReferencedHandleIds(std::unordered_set<format::HandleId>* referenced_ids,
                                std::unordered_set<format::HandleId>* unreferenced_ids) const
    {
        table_.GetReferencedHandleIds(referenced_ids, unreferenced_ids);
    }

    bool WasCommandBufferSubmissionSeen() const { return command_buffer_submission_seen_; }

    void ProcessStateBeginMarker(uint64_t) override { loading_state_ = true; }

    void ProcessStateEndMarker(uint64_t) override
    {
        loading_state_ = false;
        loaded_state_  = true;
    }

    void Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args) override;

    void Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args) override;

    void Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args) override;

    void Process_vkCreateBuffer(const ApiCallInfo& call_info, args::CreateBuffer& args) override;

    void Process_vkCreateBufferView(const ApiCallInfo& call_info, args::CreateBufferView& args) override;

    void Process_vkCreateImage(const ApiCallInfo& call_info, args::CreateImage& args) override;

    void Process_vkCreateImageView(const ApiCallInfo& call_info, args::CreateImageView& args) override;

    void Process_vkCreateFramebuffer(const ApiCallInfo& call_info, args::CreateFramebuffer& args) override;

    void Process_vkCreateDescriptorSetLayout(const ApiCallInfo&               call_info,
                                             args::CreateDescriptorSetLayout& args) override;

    void Process_vkCreateDescriptorUpdateTemplate(const ApiCallInfo&                    call_info,
                                                  args::CreateDescriptorUpdateTemplate& args) override;

    void Process_vkCreateDescriptorUpdateTemplateKHR(const ApiCallInfo&                       call_info,
                                                     args::CreateDescriptorUpdateTemplateKHR& args) override;

    void Process_vkCreateAccelerationStructureKHR(const ApiCallInfo&                    call_info,
                                                  args::CreateAccelerationStructureKHR& args) override;

    void Process_vkCreateTensorARM(const ApiCallInfo& call_info, args::CreateTensorARM& args) override;

    void Process_vkCreateTensorViewARM(const ApiCallInfo& call_info, args::CreateTensorViewARM& args) override;

    void Process_vkDestroyDescriptorPool(const ApiCallInfo& call_info, args::DestroyDescriptorPool& args) override;

    void Process_vkResetDescriptorPool(const ApiCallInfo& call_info, args::ResetDescriptorPool& args) override;

    void Process_vkAllocateDescriptorSets(const ApiCallInfo& call_info, args::AllocateDescriptorSets& args) override;

    void Process_vkFreeDescriptorSets(const ApiCallInfo& call_info, args::FreeDescriptorSets& args) override;

    void Process_vkUpdateDescriptorSets(const ApiCallInfo& call_info, args::UpdateDescriptorSets& args) override;

    void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&                     call_info,
                                                   args::UpdateDescriptorSetWithTemplate& args) override;

    void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo&                         call_info,
                                                       args::CmdPushDescriptorSetWithTemplateKHR& args) override;

    void Process_vkCmdPushDescriptorSetWithTemplate2KHR(const ApiCallInfo&                          call_info,
                                                        args::CmdPushDescriptorSetWithTemplate2KHR& args) override;

    void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&                        call_info,
                                                      args::UpdateDescriptorSetWithTemplateKHR& args) override;

    void Process_vkDestroyCommandPool(const ApiCallInfo& call_info, args::DestroyCommandPool& args) override;

    void Process_vkResetCommandPool(const ApiCallInfo& call_info, args::ResetCommandPool& args) override;

    void Process_vkAllocateCommandBuffers(const ApiCallInfo& call_info, args::AllocateCommandBuffers& args) override;

    void Process_vkFreeCommandBuffers(const ApiCallInfo& call_info, args::FreeCommandBuffers& args) override;

    void Process_vkBeginCommandBuffer(const ApiCallInfo& call_info, args::BeginCommandBuffer& args) override;

    void Process_vkResetCommandBuffer(const ApiCallInfo& call_info, args::ResetCommandBuffer& args) override;

    void ProcessSetTlasToBlasRelationCommand(format::HandleId                     tlas,
                                             const std::vector<format::HandleId>& blases) override;

    void Process_vkCmdTraceRaysKHR(const ApiCallInfo& call_info, args::CmdTraceRaysKHR& args) override;

    void
    ProcessSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, uint64_t address) override;

    void Process_vkBindBufferMemory(const ApiCallInfo& call_info, args::BindBufferMemory& args) override;

    void Process_vkGetBufferDeviceAddress(const ApiCallInfo& call_info, args::GetBufferDeviceAddress& args) override;

    void Process_vkGetBufferDeviceAddressKHR(const ApiCallInfo&               call_info,
                                             args::GetBufferDeviceAddressKHR& args) override;

    void Process_vkGetBufferDeviceAddressEXT(const ApiCallInfo&               call_info,
                                             args::GetBufferDeviceAddressEXT& args) override;

    void Process_vkCreateGraphicsPipelines(const ApiCallInfo& call_info, args::CreateGraphicsPipelines& args) override;

    void Process_vkCreateComputePipelines(const ApiCallInfo& call_info, args::CreateComputePipelines& args) override;

    void Process_vkCreateRayTracingPipelinesKHR(const ApiCallInfo&                  call_info,
                                                args::CreateRayTracingPipelinesKHR& args) override;

  protected:
    bool IsStateLoading() const { return loading_state_; }

    ReferencedResourceTable& GetTable() { return table_; }

  private:
    struct UpdateTemplateEntryInfo
    {
        uint32_t         binding{ std::numeric_limits<uint32_t>::max() };
        uint32_t         array_element{ 0 };
        uint32_t         count{ 0 };
        VkDescriptorType type{};
    };

    struct UpdateTemplateInfo
    {
        format::HandleId                     set_id{ format::kNullHandleId };
        std::vector<UpdateTemplateEntryInfo> image_infos;
        std::vector<UpdateTemplateEntryInfo> buffer_infos;
        std::vector<UpdateTemplateEntryInfo> texel_buffer_view_infos;
        std::vector<UpdateTemplateEntryInfo> acceleration_structure_infos;
        std::vector<UpdateTemplateEntryInfo> inline_uniform_block_infos;
    };

    // Table of descriptor update template info, keyed by VkDescriptorUpdateTemplate ID.
    using UpdateTemplateInfos = std::unordered_map<format::HandleId, UpdateTemplateInfo>;

    // Table of descriptor set layout binding counts, keyed by VkDescriptorSetLayout ID.  Each entry is a table of
    // descriptor counts keyed by binding index.
    using LayoutBindingCounts = std::unordered_map<format::HandleId, std::unordered_map<uint32_t, uint32_t>>;

    // Table to associate VkDescriptorSet IDs with the VkDescriptorSetLayout IDs used to create them, keyed by
    // VkDescriptorSet ID.
    using SetLayouts = std::unordered_map<format::HandleId, format::HandleId>;

    uint32_t GetBindingCount(format::HandleId container_id, uint32_t binding) const;

    void AddDescriptorToContainer(format::HandleId                                 container_id,
                                  int32_t                                          binding,
                                  uint32_t                                         element,
                                  uint32_t                                         count,
                                  std::function<void(uint32_t, int32_t, uint32_t)> add_descriptor);

    void AddImagesToContainer(format::HandleId                     container_id,
                              int32_t                              binding,
                              uint32_t                             element,
                              uint32_t                             count,
                              const Decoded_VkDescriptorImageInfo* image_infos);

    void AddBuffersToContainer(format::HandleId                      container_id,
                               int32_t                               binding,
                               uint32_t                              element,
                               uint32_t                              count,
                               const Decoded_VkDescriptorBufferInfo* buffer_infos);

    void AddResourcesToContainer(format::HandleId        container_id,
                                 int32_t                 binding,
                                 uint32_t                element,
                                 uint32_t                count,
                                 const format::HandleId* resource_ids);

    void AddImagesToUser(format::HandleId user_id, size_t count, const Decoded_VkDescriptorImageInfo* image_info);

    void AddBuffersToUser(format::HandleId user_id, size_t count, const Decoded_VkDescriptorBufferInfo* buffer_info);

    void AddTexelBufferViewsToUser(format::HandleId user_id, size_t count, const format::HandleId* view_ids);

    void CreateDescriptorUpdateTemplate(
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        const HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate);

    void UpdateDescriptorSetWithTemplate(format::HandleId                       container_id,
                                         format::HandleId                       template_id,
                                         const DescriptorUpdateTemplateDecoder* decoder);

    void PushDescriptorSetWithTemplate(format::HandleId                       user_id,
                                       format::HandleId                       template_id,
                                       const DescriptorUpdateTemplateDecoder* decoder);

    void Process_vkGetBufferDeviceAddress(const ApiCallInfo&                                       call_info,
                                          VkDeviceAddress                                          returnValue,
                                          format::HandleId                                         device,
                                          StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);

    template <typename T>
    void Process_vkQueueSubmit2(StructPointerDecoder<T>* pSubmits)
    {
        static_assert(std::is_same_v<T, Decoded_VkSubmitInfo2>);

        if (!pSubmits->IsNull() && pSubmits->HasData())
        {
            size_t     submit_count = pSubmits->GetLength();
            const auto submits      = pSubmits->GetMetaStructPointer();

            for (size_t i = 0; i < submit_count; ++i)
            {
                size_t     command_buffer_count = submits[i].pCommandBufferInfos->GetLength();
                const auto command_buffers      = submits[i].pCommandBufferInfos->GetMetaStructPointer();

                if ((command_buffer_count > 0) && !IsStateLoading())
                {
                    command_buffer_submission_seen_ = true;
                }

                for (size_t j = 0; j < command_buffer_count; ++j)
                {
                    table_.ProcessUserSubmission(command_buffers[j].commandBuffer);
                }
            }
        }
    }

    template <typename T>
    void Process_vkCreatePipelines(uint32_t                                createInfoCount,
                                   StructPointerDecoder<T>*                pCreateInfos,
                                   const HandlePointerDecoder<VkPipeline>* pPipelines)
    {
        static_assert(std::is_same_v<T, Decoded_VkGraphicsPipelineCreateInfo> ||
                      std::is_same_v<T, Decoded_VkComputePipelineCreateInfo> ||
                      std::is_same_v<T, Decoded_VkRayTracingPipelineCreateInfoKHR>);

        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            const format::HandleId pipeline_id = pPipelines->GetPointer()[i];
            table_.AddResource(pipeline_id);

            const auto* meta_create_info = pCreateInfos->GetMetaStructPointer() + i;

            // Track the base pipeline of a derivative pipeline as a child, so that creation of the base pipeline is
            // preserved whenever the derivative pipeline is referenced (its create info names the base handle).
            table_.AddResource(pipeline_id, meta_create_info->basePipelineHandle);

            if (auto* meta_pipeline_info =
                    GetPNextMetaStruct<Decoded_VkPipelineLibraryCreateInfoKHR>(meta_create_info->pNext))
            {
                for (uint32_t l = 0; l < meta_pipeline_info->pLibraries.GetLength(); ++l)
                {
                    const format::HandleId library_id = meta_pipeline_info->pLibraries.GetPointer()[l];
                    table_.AddResource(pipeline_id, library_id);
                }
            }
        }
    }

    bool                    loading_state_                  = false;
    bool                    loaded_state_                   = false;
    bool                    command_buffer_submission_seen_ = false;
    ReferencedResourceTable table_;
    LayoutBindingCounts     layout_binding_counts_;
    SetLayouts              set_layouts_;
    UpdateTemplateInfos     template_infos_;

    std::unordered_map<format::HandleId, VkDeviceAddress> dev_address_to_resource_map_;
    std::unordered_map<VkDeviceAddress, format::HandleId> dev_address_to_buffers_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REFERENCED_RESOURCE_CONSUMER_BASE_H
