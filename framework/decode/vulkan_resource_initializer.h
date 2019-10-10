/*
** Copyright (c) 2019 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_RESOURCE_INITIALIZER_H
#define GFXRECON_DECODE_VULKAN_RESOURCE_INITIALIZER_H

#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanResourceInitializer
{
  public:
    VulkanResourceInitializer(VkDevice                                device,
                              VkDeviceSize                            max_copy_size,
                              const VkPhysicalDeviceMemoryProperties& memory_properties,
                              const encode::DeviceTable*              device_table);

    ~VulkanResourceInitializer();

    VkResult LoadData(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, const uint8_t* data);

    VkResult InitializeBuffer(VkDeviceSize        data_size,
                              const uint8_t*      data,
                              uint32_t            queue_family_index,
                              VkBuffer            buffer,
                              VkBufferUsageFlags  usage,
                              uint32_t            region_count,
                              const VkBufferCopy* regions);

    VkResult InitializeImage(VkDeviceSize             data_size,
                             const uint8_t*           data,
                             uint32_t                 queue_family_index,
                             VkImage                  image,
                             VkImageType              type,
                             VkFormat                 format,
                             const VkExtent3D&        extent,
                             VkImageAspectFlagBits    aspect,
                             VkSampleCountFlagBits    sample_count,
                             VkImageUsageFlags        usage,
                             VkImageLayout            initial_layout,
                             VkImageLayout            final_layout,
                             uint32_t                 layer_count,
                             uint32_t                 level_count,
                             const VkBufferImageCopy* level_copies);

    VkResult TransitionImage(uint32_t              queue_family_index,
                             VkImage               image,
                             VkFormat              format,
                             VkImageAspectFlagBits aspect,
                             VkImageLayout         initial_layout,
                             VkImageLayout         final_layout,
                             uint32_t              layer_count,
                             uint32_t              level_count);

  private:
    VkResult GetCommandExecObjects(uint32_t queue_family_index, VkQueue* queue, VkCommandBuffer* command_buffer);

    VkResult GetDrawDescriptorObjects(VkSampler* sampler, VkDescriptorSetLayout* set_layout, VkDescriptorSet* set);

    VkResult CreateDrawObjects(VkFormat              format,
                               const VkExtent3D&     extent,
                               VkSampleCountFlagBits sample_count,
                               VkImageLayout         initial_layout,
                               VkImageLayout         final_layout,
                               VkDescriptorSetLayout set_layout,
                               VkRenderPass*         pass,
                               VkPipelineLayout*     pipeline_layout,
                               VkPipeline*           pipeline);

    void DestroyDrawObjects(VkRenderPass pass, VkPipelineLayout pipeline_layout, VkPipeline pipeline);

    VkResult CreateStagingImage(const VkImageCreateInfo* image_create_info, VkDeviceMemory* memory, VkImage* image);

    void DestroyStagingImage(VkDeviceMemory memory, VkImage image);

    VkResult CreateFramebufferResources(const VkImageViewCreateInfo* view_create_info,
                                        uint32_t                     width,
                                        uint32_t                     height,
                                        VkRenderPass                 render_pass,
                                        VkImageView*                 view,
                                        VkFramebuffer*               framebuffer);

    void DestroyFramebufferResources(VkImageView view, VkFramebuffer framebuffer);

    VkResult AcquireStagingBuffer(VkDeviceMemory* memory, VkBuffer* buffer, VkDeviceSize size);

    VkResult AcquireInitializedStagingBuffer(VkDeviceSize    data_size,
                                             const uint8_t*  data,
                                             VkDeviceMemory* staging_memory,
                                             VkBuffer*       staging_buffer);

    void ReleaseStagingBuffer(VkDeviceMemory memory, VkBuffer buffer);

    void UpdateDrawDescriptorSet(VkDescriptorSet set, VkImageView view, VkSampler sampler);

    VkResult BeginCommandBuffer(VkCommandBuffer command_buffer);

    VkResult ExecuteCommandBuffer(VkQueue queue, VkCommandBuffer command_buffer);

    VkImageAspectFlags
    GetImageTransitionAspect(VkFormat format, VkImageAspectFlagBits aspect, VkImageLayout* old_layout);

    uint32_t GetMemoryTypeIndex(uint32_t type_bits, VkMemoryPropertyFlags property_flags);

    VkResult BufferToImageCopy(uint32_t                 queue_family_index,
                               VkBuffer                 source,
                               VkImage                  destination,
                               VkFormat                 format,
                               VkImageAspectFlagBits    aspect,
                               VkImageLayout            initial_layout,
                               VkImageLayout            final_layout,
                               uint32_t                 layer_count,
                               uint32_t                 level_count,
                               const VkBufferImageCopy* level_copies);

    VkResult ColorImageShaderCopy(uint32_t                 queue_family_index,
                                  VkBuffer                 source,
                                  VkImage                  destination,
                                  VkImageType              type,
                                  VkFormat                 format,
                                  const VkExtent3D&        extent,
                                  VkImageAspectFlagBits    aspect,
                                  VkSampleCountFlagBits    sample_count,
                                  VkImageLayout            initial_layout,
                                  VkImageLayout            final_layout,
                                  uint32_t                 layer_count,
                                  uint32_t                 level_count,
                                  const VkBufferImageCopy* level_copies);

  private:
    struct CommandExecObjects
    {
        VkQueue         queue;
        VkCommandPool   command_pool;
        VkCommandBuffer command_buffer;
    };

    // Map queue family index to command pool, command buffer, and queue objects for command processing.
    typedef std::unordered_map<uint32_t, CommandExecObjects> CommandExecObjectMap;

  private:
    VkDevice                         device_;
    CommandExecObjectMap             command_exec_objects_;
    VkDeviceMemory                   staging_memory_;
    VkBuffer                         staging_buffer_;
    VkSampler                        draw_sampler_;
    VkDescriptorPool                 draw_pool_;
    VkDescriptorSetLayout            draw_set_layout_;
    VkDescriptorSet                  draw_set_;
    VkDeviceSize                     max_copy_size_;
    VkPhysicalDeviceMemoryProperties memory_properties_;
    const encode::DeviceTable*       device_table_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_RESOURCE_INITIALIZER_H
