/*
** Copyright (c) 2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
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
    VulkanReferencedResourceConsumerBase();

    void GetReferencedResourceIds(std::unordered_set<format::HandleId>* referenced_ids,
                                  std::unordered_set<format::HandleId>* unreferenced_ids) const
    {
        table_.GetReferencedResourceIds(referenced_ids, unreferenced_ids);
    }

    virtual void ProcessStateBeginMarker(uint64_t) override { loading_state_ = true; }

    virtual void ProcessStateEndMarker(uint64_t) override
    {
        loading_state_ = false;
        loaded_state_  = true;
    }

    virtual void Process_vkQueueSubmit(VkResult                                    returnValue,
                                       format::HandleId                            queue,
                                       uint32_t                                    submitCount,
                                       StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                       format::HandleId                            fence) override;

    virtual void Process_vkCreateBuffer(VkResult                                             returnValue,
                                        format::HandleId                                     device,
                                        StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                        HandlePointerDecoder<VkBuffer>*                      pBuffer) override;

    virtual void Process_vkCreateBufferView(VkResult                                              returnValue,
                                            format::HandleId                                      device,
                                            StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
                                            HandlePointerDecoder<VkBufferView>*                   pView) override;

    virtual void Process_vkCreateImage(VkResult                                             returnValue,
                                       format::HandleId                                     device,
                                       StructPointerDecoder<Decoded_VkImageCreateInfo>*     pCreateInfo,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                       HandlePointerDecoder<VkImage>*                       pImage) override;

    virtual void Process_vkCreateImageView(VkResult                                             returnValue,
                                           format::HandleId                                     device,
                                           StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                           HandlePointerDecoder<VkImageView>*                   pView) override;

    virtual void Process_vkCreateFramebuffer(VkResult                                               returnValue,
                                             format::HandleId                                       device,
                                             StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
                                             StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                             HandlePointerDecoder<VkFramebuffer>* pFramebuffer) override;

    virtual void
    Process_vkCreateDescriptorSetLayout(VkResult                                                       returnValue,
                                        format::HandleId                                               device,
                                        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*           pAllocator,
                                        HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) override;

    virtual void Process_vkCreateDescriptorUpdateTemplate(
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate) override;

    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate) override;

    virtual void
    Process_vkDestroyDescriptorPool(format::HandleId                                     device,
                                    format::HandleId                                     descriptorPool,
                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetDescriptorPool(VkResult                   returnValue,
                                               format::HandleId           device,
                                               format::HandleId           descriptorPool,
                                               VkDescriptorPoolResetFlags flags) override;

    virtual void
    Process_vkAllocateDescriptorSets(VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void Process_vkFreeDescriptorSets(VkResult                               returnValue,
                                              format::HandleId                       device,
                                              format::HandleId                       descriptorPool,
                                              uint32_t                               descriptorSetCount,
                                              HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void
    Process_vkUpdateDescriptorSets(format::HandleId                                    device,
                                   uint32_t                                            descriptorWriteCount,
                                   StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
                                   uint32_t                                            descriptorCopyCount,
                                   StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplate(format::HandleId                 device,
                                                           format::HandleId                 descriptorSet,
                                                           format::HandleId                 descriptorUpdateTemplate,
                                                           DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(format::HandleId commandBuffer,
                                                               format::HandleId descriptorUpdateTemplate,
                                                               format::HandleId layout,
                                                               uint32_t         set,
                                                               DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(format::HandleId                 device,
                                                              format::HandleId                 descriptorSet,
                                                              format::HandleId                 descriptorUpdateTemplate,
                                                              DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkDestroyCommandPool(format::HandleId                                     device,
                                              format::HandleId                                     commandPool,
                                              StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetCommandPool(VkResult                returnValue,
                                            format::HandleId        device,
                                            format::HandleId        commandPool,
                                            VkCommandPoolResetFlags flags) override;

    virtual void
    Process_vkAllocateCommandBuffers(VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void Process_vkFreeCommandBuffers(format::HandleId                       device,
                                              format::HandleId                       commandPool,
                                              uint32_t                               commandBufferCount,
                                              HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void
    Process_vkBeginCommandBuffer(VkResult                                                returnValue,
                                 format::HandleId                                        commandBuffer,
                                 StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override;

    virtual void Process_vkResetCommandBuffer(VkResult                  returnValue,
                                              format::HandleId          commandBuffer,
                                              VkCommandBufferResetFlags flags) override;

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
    };

    // Table of descriptor update template info, keyed by VkDescriptorUpdateTemplate ID.
    typedef std::unordered_map<format::HandleId, UpdateTemplateInfo> UpdateTemplateInfos;

    // Table of descriptor set layout binding counts, keyed by VkDescriptorSetLayout ID.  Each entry is a table of
    // descriptor counts keyed by binding index.
    typedef std::unordered_map<format::HandleId, std::unordered_map<uint32_t, uint32_t>> LayoutBindingCounts;

    // Table to associate VkDescriptorSet IDs with the VkDescriptorSetLayout IDs used to create them, keyed by
    // VkDescriptorSet ID.
    typedef std::unordered_map<format::HandleId, format::HandleId> SetLayouts;

  private:
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

    void AddTexelBufferViewsToContainer(format::HandleId        container_id,
                                        int32_t                 binding,
                                        uint32_t                element,
                                        uint32_t                count,
                                        const format::HandleId* view_ids);

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

  private:
    bool                    loading_state_;
    bool                    loaded_state_;
    ReferencedResourceTable table_;
    LayoutBindingCounts     layout_binding_counts_;
    SetLayouts              set_layouts_;
    UpdateTemplateInfos     template_infos_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REFERENCED_RESOURCE_CONSUMER_BASE_H
