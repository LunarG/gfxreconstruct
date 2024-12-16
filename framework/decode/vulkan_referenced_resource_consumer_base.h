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

    virtual void Process_vkQueueSubmit(const ApiCallInfo&                          call_info,
                                       VkResult                                    returnValue,
                                       format::HandleId                            queue,
                                       uint32_t                                    submitCount,
                                       StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                       format::HandleId                            fence) override;

    virtual void Process_vkQueueSubmit2(const ApiCallInfo&                           call_info,
                                        VkResult                                     returnValue,
                                        format::HandleId                             queue,
                                        uint32_t                                     submitCount,
                                        StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                        format::HandleId                             fence) override;

    virtual void Process_vkCreateBuffer(const ApiCallInfo&                                   call_info,
                                        VkResult                                             returnValue,
                                        format::HandleId                                     device,
                                        StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                        HandlePointerDecoder<VkBuffer>*                      pBuffer) override;

    virtual void Process_vkCreateBufferView(const ApiCallInfo&                                    call_info,
                                            VkResult                                              returnValue,
                                            format::HandleId                                      device,
                                            StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
                                            HandlePointerDecoder<VkBufferView>*                   pView) override;

    virtual void Process_vkCreateImage(const ApiCallInfo&                                   call_info,
                                       VkResult                                             returnValue,
                                       format::HandleId                                     device,
                                       StructPointerDecoder<Decoded_VkImageCreateInfo>*     pCreateInfo,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                       HandlePointerDecoder<VkImage>*                       pImage) override;

    virtual void Process_vkCreateImageView(const ApiCallInfo&                                   call_info,
                                           VkResult                                             returnValue,
                                           format::HandleId                                     device,
                                           StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                           HandlePointerDecoder<VkImageView>*                   pView) override;

    virtual void Process_vkCreateFramebuffer(const ApiCallInfo&                                     call_info,
                                             VkResult                                               returnValue,
                                             format::HandleId                                       device,
                                             StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
                                             StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                             HandlePointerDecoder<VkFramebuffer>* pFramebuffer) override;

    virtual void
    Process_vkCreateDescriptorSetLayout(const ApiCallInfo&                                             call_info,
                                        VkResult                                                       returnValue,
                                        format::HandleId                                               device,
                                        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*           pAllocator,
                                        HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) override;

    virtual void Process_vkCreateDescriptorUpdateTemplate(
        const ApiCallInfo&                                                  call_info,
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate) override;

    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                                                  call_info,
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate) override;

    virtual void Process_vkCreateAccelerationStructureKHR(
        const ApiCallInfo&                                                  call_info,
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkAccelerationStructureKHR>*                   pAccelerationStructure) override;

    virtual void
    Process_vkDestroyDescriptorPool(const ApiCallInfo&                                   call_info,
                                    format::HandleId                                     device,
                                    format::HandleId                                     descriptorPool,
                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetDescriptorPool(const ApiCallInfo&         call_info,
                                               VkResult                   returnValue,
                                               format::HandleId           device,
                                               format::HandleId           descriptorPool,
                                               VkDescriptorPoolResetFlags flags) override;

    virtual void
    Process_vkAllocateDescriptorSets(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void Process_vkFreeDescriptorSets(const ApiCallInfo&                     call_info,
                                              VkResult                               returnValue,
                                              format::HandleId                       device,
                                              format::HandleId                       descriptorPool,
                                              uint32_t                               descriptorSetCount,
                                              HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void
    Process_vkUpdateDescriptorSets(const ApiCallInfo&                                  call_info,
                                   format::HandleId                                    device,
                                   uint32_t                                            descriptorWriteCount,
                                   StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
                                   uint32_t                                            descriptorCopyCount,
                                   StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&               call_info,
                                                           format::HandleId                 device,
                                                           format::HandleId                 descriptorSet,
                                                           format::HandleId                 descriptorUpdateTemplate,
                                                           DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                               format::HandleId   commandBuffer,
                                                               format::HandleId   descriptorUpdateTemplate,
                                                               format::HandleId   layout,
                                                               uint32_t           set,
                                                               DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplate2KHR(
        const ApiCallInfo&                                                 call_info,
        format::HandleId                                                   commandBuffer,
        StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfo>* pPushDescriptorSetWithTemplateInfo) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&               call_info,
                                                              format::HandleId                 device,
                                                              format::HandleId                 descriptorSet,
                                                              format::HandleId                 descriptorUpdateTemplate,
                                                              DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkDestroyCommandPool(const ApiCallInfo&                                   call_info,
                                              format::HandleId                                     device,
                                              format::HandleId                                     commandPool,
                                              StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetCommandPool(const ApiCallInfo&      call_info,
                                            VkResult                returnValue,
                                            format::HandleId        device,
                                            format::HandleId        commandPool,
                                            VkCommandPoolResetFlags flags) override;

    virtual void
    Process_vkAllocateCommandBuffers(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void Process_vkFreeCommandBuffers(const ApiCallInfo&                     call_info,
                                              format::HandleId                       device,
                                              format::HandleId                       commandPool,
                                              uint32_t                               commandBufferCount,
                                              HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void
    Process_vkBeginCommandBuffer(const ApiCallInfo&                                      call_info,
                                 VkResult                                                returnValue,
                                 format::HandleId                                        commandBuffer,
                                 StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override;

    virtual void Process_vkResetCommandBuffer(const ApiCallInfo&        call_info,
                                              VkResult                  returnValue,
                                              format::HandleId          commandBuffer,
                                              VkCommandBufferResetFlags flags) override;

    virtual void ProcessSetTlasToBlasRelationCommand(format::HandleId                     tlas,
                                                     const std::vector<format::HandleId>& blases) override;

    virtual void Process_vkCmdTraceRaysKHR(
        const ApiCallInfo&                                             call_info,
        format::HandleId                                               commandBuffer,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
        uint32_t                                                       width,
        uint32_t                                                       height,
        uint32_t                                                       depth) override;

    virtual void
    ProcessSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, uint64_t address) override;

    virtual void Process_vkBindBufferMemory(const ApiCallInfo& call_info,
                                            VkResult           returnValue,
                                            format::HandleId   device,
                                            format::HandleId   buffer,
                                            format::HandleId   memory,
                                            VkDeviceSize       memoryOffset) override;

    bool IsComplete(uint64_t current_block_index) override { return not_optimizable_; }

    bool WasNotOptimizable() { return not_optimizable_; }

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

  private:
    bool                    loading_state_;
    bool                    loaded_state_;
    ReferencedResourceTable table_;
    LayoutBindingCounts     layout_binding_counts_;
    SetLayouts              set_layouts_;
    UpdateTemplateInfos     template_infos_;
    bool                    not_optimizable_;

    std::unordered_map<format::HandleId, VkDeviceAddress> dev_address_to_resource_map;
    std::unordered_map<VkDeviceAddress, format::HandleId> dev_address_to_buffers_map;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REFERENCED_RESOURCE_CONSUMER_BASE_H
