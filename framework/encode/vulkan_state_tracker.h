/*
** Copyright (c) 2019-2025 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_STATE_TRACKER_H
#define GFXRECON_ENCODE_VULKAN_STATE_TRACKER_H

#include "encode/descriptor_update_template_info.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_device_address_tracker.h"
#include "encode/vulkan_state_info.h"
#include "generated/generated_vulkan_state_table.h"
#include "encode/vulkan_state_tracker_initializers.h"
#include "encode/vulkan_state_writer.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_command_buffer_util.h"
#include "util/file_output_stream.h"
#include "util/defines.h"
#include "util/logging.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"
#include "vulkan/vulkan_core.h"

#include <cassert>
#include <functional>
#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanStateTracker
{
  public:
    VulkanStateTracker();

    ~VulkanStateTracker();

    uint64_t WriteState(util::FileOutputStream*           file_stream,
                        util::ThreadData*                 thread_data,
                        std::function<format::HandleId()> get_unique_id_fn,
                        util::Compressor*                 compressor,
                        uint64_t                          frame_number,
                        util::FileOutputStream*           asset_file_stream,
                        const std::string*                asset_file_name)
    {
        VulkanStateWriter state_writer(file_stream,
                                       compressor,
                                       thread_data,
                                       get_unique_id_fn,
                                       asset_file_stream,
                                       asset_file_name,
                                       asset_file_stream != nullptr ? &asset_file_offsets_ : nullptr);

        std::unique_lock<std::mutex> lock(state_table_mutex_);
        return state_writer.WriteState(state_table_, frame_number);
    }

    uint64_t WriteAssets(util::FileOutputStream*           asset_file_stream,
                         const std::string*                asset_file_name,
                         util::ThreadData*                 thread_data,
                         std::function<format::HandleId()> get_unique_id_fn,
                         util::Compressor*                 compressor)
    {
        assert(asset_file_stream != nullptr);
        assert(asset_file_name != nullptr);

        VulkanStateWriter state_writer(nullptr,
                                       compressor,
                                       thread_data,
                                       get_unique_id_fn,
                                       asset_file_stream,
                                       asset_file_name,
                                       &asset_file_offsets_);

        std::unique_lock<std::mutex> lock(state_table_mutex_);
        return state_writer.WriteAssets(state_table_);
    }

    template <typename ParentHandle, typename Wrapper, typename CreateInfo>
    void AddEntry(ParentHandle                    parent_handle,
                  typename Wrapper::HandleType*   new_handle,
                  const CreateInfo*               create_info,
                  format::ApiCallId               create_call_id,
                  const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handle != nullptr);
        assert(create_parameter_buffer != nullptr);

        if (*new_handle != VK_NULL_HANDLE)
        {
            auto wrapper = vulkan_wrappers::GetWrapper<Wrapper>(*new_handle);

            // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
            std::unique_lock<std::mutex> lock(state_table_mutex_);
            if (state_table_.InsertWrapper(wrapper->handle_id, wrapper))
            {
                vulkan_state_tracker::InitializeState<ParentHandle, Wrapper, CreateInfo>(
                    parent_handle,
                    wrapper,
                    create_info,
                    create_call_id,
                    std::make_shared<util::MemoryOutputStream>(create_parameter_buffer->GetData(),
                                                               create_parameter_buffer->GetDataSize()));
            }
        }
    }

    template <typename ParentHandle, typename Wrapper, typename AllocateInfo>
    void AddPoolEntry(ParentHandle                    parent_handle,
                      uint32_t                        count,
                      typename Wrapper::HandleType*   new_handles,
                      const AllocateInfo*             alloc_info,
                      format::ApiCallId               create_call_id,
                      const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handles != nullptr);
        assert(create_parameter_buffer != nullptr);

        vulkan_state_info::CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
            create_parameter_buffer->GetData(), create_parameter_buffer->GetDataSize());

        std::unique_lock<std::mutex> lock(state_table_mutex_);
        for (uint32_t i = 0; i < count; ++i)
        {
            if (new_handles[i] != VK_NULL_HANDLE)
            {
                auto wrapper = vulkan_wrappers::GetWrapper<Wrapper>(new_handles[i]);

                // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
                if (state_table_.InsertWrapper(wrapper->handle_id, wrapper))
                {
                    vulkan_state_tracker::InitializePoolObjectState(
                        parent_handle, wrapper, i, alloc_info, create_call_id, create_parameters);
                }
            }
        }
    }

    template <typename ParentHandle, typename SecondaryHandle, typename Wrapper, typename CreateInfo>
    void AddGroupEntry(ParentHandle                    parent_handle,
                       SecondaryHandle                 secondary_handle,
                       uint32_t                        count,
                       typename Wrapper::HandleType*   new_handles,
                       const CreateInfo*               create_infos,
                       format::ApiCallId               create_call_id,
                       const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(create_parameter_buffer != nullptr);

        vulkan_state_info::CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
            create_parameter_buffer->GetData(), create_parameter_buffer->GetDataSize());

        {
            AddGroupHandles<ParentHandle, SecondaryHandle, Wrapper, CreateInfo>(
                parent_handle, secondary_handle, count, new_handles, create_infos, create_call_id, create_parameters);
        }
    }

    template <typename ParentHandle, typename Wrapper, typename HandleStruct>
    void AddStructGroupEntry(ParentHandle                           parent_handle,
                             uint32_t                               count,
                             HandleStruct*                          handle_structs,
                             std::function<Wrapper*(HandleStruct*)> unwrap_struct_handle,
                             format::ApiCallId                      create_call_id,
                             const util::MemoryOutputStream*        create_parameter_buffer)
    {
        assert(handle_structs != nullptr);
        assert(unwrap_struct_handle != nullptr);
        assert(create_parameter_buffer != nullptr);

        vulkan_state_info::CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
            create_parameter_buffer->GetData(), create_parameter_buffer->GetDataSize());

        std::unique_lock<std::mutex> lock(state_table_mutex_);
        for (uint32_t i = 0; i < count; ++i)
        {
            auto wrapper = unwrap_struct_handle(&handle_structs[i]);

            // VkDisplayPlaneProperties::currentDisplay can be a null wrapper.
            if ((wrapper != nullptr) && (state_table_.InsertWrapper(wrapper->handle_id, wrapper)))
            {
                vulkan_state_tracker::InitializeGroupObjectState<ParentHandle, void*, Wrapper, void>(
                    parent_handle, nullptr, wrapper, nullptr, create_call_id, create_parameters);
            }
        }
    }

    void AddStructGroupEntry(
        VkInstance                                                                               parent_handle,
        uint32_t                                                                                 count,
        VkPhysicalDeviceGroupProperties*                                                         handle_structs,
        std::function<vulkan_wrappers::PhysicalDeviceWrapper*(VkPhysicalDeviceGroupProperties*)> unwrap_struct_handle,
        format::ApiCallId                                                                        create_call_id,
        const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(handle_structs != nullptr);
        assert(create_parameter_buffer != nullptr);

        GFXRECON_UNREFERENCED_PARAMETER(unwrap_struct_handle);

        vulkan_state_info::CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
            create_parameter_buffer->GetData(), create_parameter_buffer->GetDataSize());

        for (uint32_t i = 0; i < count; ++i)
        {
            AddGroupHandles<VkInstance, void*, vulkan_wrappers::PhysicalDeviceWrapper, void>(
                parent_handle,
                nullptr,
                handle_structs[i].physicalDeviceCount,
                handle_structs[i].physicalDevices,
                nullptr,
                create_call_id,
                create_parameters);
        }
    }

    void AddStructGroupEntry(
        VkDevice                                                                                   parent_handle,
        uint32_t                                                                                   count,
        VkPipelineBinaryHandlesInfoKHR*                                                            handle_structs,
        std::function<vulkan_wrappers::PipelineBinaryKHRWrapper*(VkPipelineBinaryHandlesInfoKHR*)> unwrap_struct_handle,
        format::ApiCallId                                                                          create_call_id,
        const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(handle_structs != nullptr);
        assert(create_parameter_buffer != nullptr);

        GFXRECON_UNREFERENCED_PARAMETER(count);
        GFXRECON_UNREFERENCED_PARAMETER(unwrap_struct_handle);

        if (handle_structs->pPipelineBinaries != nullptr)
        {
            vulkan_state_info::CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
                create_parameter_buffer->GetData(), create_parameter_buffer->GetDataSize());

            AddGroupHandles<VkDevice, void*, vulkan_wrappers::PipelineBinaryKHRWrapper, void>(
                parent_handle,
                nullptr,
                handle_structs->pipelineBinaryCount,
                handle_structs->pPipelineBinaries,
                nullptr,
                create_call_id,
                create_parameters);
        }
    }

    template <typename Wrapper>
    void RemoveEntry(typename Wrapper::HandleType handle)
    {
        if (handle != VK_NULL_HANDLE)
        {
            auto wrapper = vulkan_wrappers::GetWrapper<Wrapper>(handle);

            // Scope the state table mutex lock because DestroyState also modifies the state table and will attempt to
            // lock the mutex.
            {
                std::unique_lock<std::mutex> lock(state_table_mutex_);
                if (!state_table_.RemoveWrapper(wrapper))
                {
                    GFXRECON_LOG_WARNING(
                        "Attempting to remove entry from state tracker for object that is not being tracked");
                }
            }

            DestroyState(wrapper);
        }
    }

    void TrackCommand(VkCommandBuffer                 command_buffer,
                      format::ApiCallId               call_id,
                      const util::MemoryOutputStream* parameter_buffer)
    {
        if (command_buffer != VK_NULL_HANDLE)
        {
            auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

            TrackCommandExecution(wrapper, call_id, parameter_buffer);
        }
    }

    template <typename GetHandlesFunc, typename... GetHandlesArgs>
    void TrackCommand(VkCommandBuffer                 command_buffer,
                      format::ApiCallId               call_id,
                      const util::MemoryOutputStream* parameter_buffer,
                      GetHandlesFunc                  func,
                      GetHandlesArgs... args)
    {
        if (command_buffer != VK_NULL_HANDLE)
        {
            auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

            TrackCommandExecution(wrapper, call_id, parameter_buffer);
            func(wrapper, args...);
        }
    }

    void TrackTrimCommandPool(VkDevice device, VkCommandPool command_pool);

    void TrackResetCommandPool(VkCommandPool command_pool);

    void TrackPhysicalDeviceMemoryProperties(VkPhysicalDevice                        physical_device,
                                             const VkPhysicalDeviceMemoryProperties* properties);

    void TrackPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice               physical_device,
                                                  uint32_t                       property_count,
                                                  const VkQueueFamilyProperties* properties);

    void TrackPhysicalDeviceQueueFamilyProperties2(format::ApiCallId               call_id,
                                                   VkPhysicalDevice                physical_device,
                                                   uint32_t                        property_count,
                                                   const VkQueueFamilyProperties2* properties);

    void TrackPhysicalDeviceSurfaceSupport(VkPhysicalDevice physical_device,
                                           uint32_t         queue_family_index,
                                           VkSurfaceKHR     surface,
                                           VkBool32         supported);

    void TrackPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice                physical_device,
                                                VkSurfaceKHR                    surface,
                                                const VkSurfaceCapabilitiesKHR* capabilities);

    void TrackPhysicalDeviceSurfaceCapabilities2(VkPhysicalDevice                       physical_device,
                                                 const VkPhysicalDeviceSurfaceInfo2KHR& surface_info,
                                                 const VkSurfaceCapabilities2KHR*       surface_capabilities);

    void TrackPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice                 physical_device,
                                                    VkSurfaceKHR                     surface,
                                                    const VkSurfaceCapabilities2EXT* capabilities);

    void TrackPhysicalDeviceSurfaceFormats(VkPhysicalDevice          physical_device,
                                           VkSurfaceKHR              surface,
                                           uint32_t                  format_count,
                                           const VkSurfaceFormatKHR* formats);

    void TrackPhysicalDeviceSurfaceFormats2(VkPhysicalDevice                       physical_device,
                                            const VkPhysicalDeviceSurfaceInfo2KHR& surface_info,
                                            uint32_t                               surface_format_count,
                                            VkSurfaceFormat2KHR*                   surface_formats);

    void TrackPhysicalDeviceSurfacePresentModes(VkPhysicalDevice        physical_device,
                                                VkSurfaceKHR            surface,
                                                uint32_t                mode_count,
                                                const VkPresentModeKHR* modes,
                                                const void*             surface_info_pnext = nullptr);

    void TrackDeviceGroupSurfacePresentModes(VkDevice                          device,
                                             VkSurfaceKHR                      surface,
                                             VkDeviceGroupPresentModeFlagsKHR* pModes,
                                             const void*                       surface_info_pnext = nullptr);

    void TrackBufferDeviceAddress(VkDevice device, VkBuffer buffer, VkDeviceAddress address);

    void TrackOpaqueBufferDeviceAddress(VkDevice device, VkBuffer buffer, VkDeviceAddress opaque_address);

    void TrackBufferMemoryBinding(VkDevice       device,
                                  VkBuffer       buffer,
                                  VkDeviceMemory memory,
                                  VkDeviceSize   memoryOffset,
                                  const void*    bind_info_pnext = nullptr);

    void TrackImageMemoryBinding(VkDevice       device,
                                 VkImage        image,
                                 VkDeviceMemory memory,
                                 VkDeviceSize   memoryOffset,
                                 const void*    bind_info_pnext = nullptr);

    void TrackMappedMemory(VkDevice         device,
                           VkDeviceMemory   memory,
                           void*            mapped_data,
                           VkDeviceSize     mapped_offset,
                           VkDeviceSize     mapped_size,
                           VkMemoryMapFlags mapped_flags,
                           bool             track_assets);

    void TrackBeginRenderPass(VkCommandBuffer command_buffer, const VkRenderPassBeginInfo* begin_info);

    void TrackEndRenderPass(VkCommandBuffer command_buffer);

    void TrackExecuteCommands(VkCommandBuffer        command_buffer,
                              uint32_t               command_buffer_count,
                              const VkCommandBuffer* command_buffers);

    void TrackImageBarriers(VkCommandBuffer             command_buffer,
                            uint32_t                    image_barrier_count,
                            const VkImageMemoryBarrier* image_barriers);

    void TrackImageBarriers2KHR(VkCommandBuffer                 command_buffer,
                                uint32_t                        image_barrier_count,
                                const VkImageMemoryBarrier2KHR* image_barriers);

    void TrackCommandBufferSubmissions(uint32_t submit_count, const VkSubmitInfo* submits);

    void TrackCommandBufferSubmissions2(uint32_t submit_count, const VkSubmitInfo2* submits);

    void TrackUpdateDescriptorSets(uint32_t                    write_count,
                                   const VkWriteDescriptorSet* writes,
                                   uint32_t                    copy_count,
                                   const VkCopyDescriptorSet*  copies);

    void TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet           set,
                                              const UpdateTemplateInfo* template_info,
                                              const void*               data);

    void TrackResetDescriptorPool(VkDescriptorPool descriptor_pool);

    void TrackQueryActivation(VkCommandBuffer     command_buffer,
                              VkQueryPool         query_pool,
                              uint32_t            query,
                              VkQueryControlFlags flags,
                              uint32_t            index);

    void
    TrackQueryReset(VkCommandBuffer command_buffer, VkQueryPool query_pool, uint32_t first_query, uint32_t query_count);

    void TrackQueryReset(VkQueryPool query_pool, uint32_t first_query, uint32_t query_count);

    void TrackSemaphoreSignalState(VkSemaphore signal);

    void TrackSemaphoreSignalState(uint32_t           wait_count,
                                   const VkSemaphore* waits,
                                   uint32_t           signal_count,
                                   const VkSemaphore* signals);

    void TrackSemaphoreInfoSignalState(uint32_t                     wait_count,
                                       const VkSemaphoreSubmitInfo* wait_infos,
                                       uint32_t                     signal_count,
                                       const VkSemaphoreSubmitInfo* signal_infos);

    void TrackAcquireImage(
        uint32_t image_index, VkSwapchainKHR swapchain, VkSemaphore semaphore, VkFence fence, uint32_t deviceMask);

    void TrackPresentedImages(uint32_t              count,
                              const VkSwapchainKHR* swapchains,
                              const uint32_t*       image_indices,
                              VkQueue               queue);

    void TrackAccelerationStructureKHRDeviceAddress(VkDevice                   device,
                                                    VkAccelerationStructureKHR accel_struct,
                                                    VkDeviceAddress            address);

    void
    TrackAccelerationStructureBuildCommand(VkCommandBuffer                                        command_buffer,
                                           uint32_t                                               info_count,
                                           const VkAccelerationStructureBuildGeometryInfoKHR*     infos,
                                           const VkAccelerationStructureBuildRangeInfoKHR* const* pp_buildRange_infos);

    void TrackAccelerationStructureCopyCommand(VkCommandBuffer                           command_buffer,
                                               const VkCopyAccelerationStructureInfoKHR* info);

    void TrackWriteAccelerationStructuresPropertiesCommand(VkCommandBuffer                   commandBuffer,
                                                           uint32_t                          accelerationStructureCount,
                                                           const VkAccelerationStructureKHR* pAccelerationStructures,
                                                           VkQueryType                       queryType,
                                                           VkQueryPool                       queryPool,
                                                           uint32_t                          firstQuery);

    void TrackDeviceMemoryDeviceAddress(VkDevice device, VkDeviceMemory memory, VkDeviceAddress address);

    void TrackRayTracingPipelineProperties(VkPhysicalDevice                                 physicalDevice,
                                           VkPhysicalDeviceRayTracingPipelinePropertiesKHR* ray_properties);

    void TrackAccelerationStructureProperties(
        VkPhysicalDevice                                    physicalDevice,
        VkPhysicalDeviceAccelerationStructurePropertiesKHR* acceleration_structure_properties);

    void TrackRayTracingShaderGroupHandles(VkDevice device, VkPipeline pipeline, size_t data_size, const void* data);

    void TrackAcquireFullScreenExclusiveMode(VkDevice device, VkSwapchainKHR swapchain);

    void TrackReleaseFullScreenExclusiveMode(VkDevice device, VkSwapchainKHR swapchain);

    void TrackSetPrivateData(VkDevice          device,
                             VkObjectType      objectType,
                             uint64_t          objectHandle,
                             VkPrivateDataSlot privateDataSlot,
                             uint64_t          data);

    void TrackSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable);

    void TrackTlasToBlasDependencies(uint32_t command_buffer_count, const VkCommandBuffer* command_buffers);

    void TrackCmdBindDescriptorSets(VkCommandBuffer        commandBuffer,
                                    VkPipelineBindPoint    pipelineBindPoint,
                                    VkPipelineLayout       layout,
                                    uint32_t               firstSet,
                                    uint32_t               descriptorSetCount,
                                    const VkDescriptorSet* pDescriptorSets,
                                    uint32_t               dynamicOffsetCount,
                                    const uint32_t*        pDynamicOffsets);

    void TrackCmdBindDescriptorSets2KHR(VkCommandBuffer                    commandBuffer,
                                        const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo);

    void
    TrackCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);

    void TrackCmdCopyBuffer(VkCommandBuffer     commandBuffer,
                            VkBuffer            srcBuffer,
                            VkBuffer            dstBuffer,
                            uint32_t            regionCount,
                            const VkBufferCopy* pRegions);

    void TrackCmdCopyImage(VkCommandBuffer    commandBuffer,
                           VkImage            srcImage,
                           VkImageLayout      srcImageLayout,
                           VkImage            dstImage,
                           VkImageLayout      dstImageLayout,
                           uint32_t           regionCount,
                           const VkImageCopy* pRegions);

    void TrackCmdCopyBufferToImage(VkCommandBuffer          commandBuffer,
                                   VkBuffer                 srcBuffer,
                                   VkImage                  dstImage,
                                   VkImageLayout            dstImageLayout,
                                   uint32_t                 regionCount,
                                   const VkBufferImageCopy* pRegions);

    void TrackCmdCopyImageToBuffer(VkCommandBuffer          commandBuffer,
                                   VkImage                  srcImage,
                                   VkImageLayout            srcImageLayout,
                                   VkBuffer                 dstBuffer,
                                   uint32_t                 regionCount,
                                   const VkBufferImageCopy* pRegions);

    void TrackCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

    void TrackCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

    void TrackCmdCopyBufferToImage2(VkCommandBuffer                 commandBuffer,
                                    const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

    void TrackCmdCopyImageToBuffer2(VkCommandBuffer                 commandBuffer,
                                    const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

    void TrackCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

    void TrackCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

    void TrackCmdCopyBufferToImage2KHR(VkCommandBuffer                 commandBuffer,
                                       const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

    void TrackCmdCopyImageToBuffer2KHR(VkCommandBuffer                 commandBuffer,
                                       const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

    void TrackCmdBlitImage(VkCommandBuffer    commandBuffer,
                           VkImage            srcImage,
                           VkImageLayout      srcImageLayout,
                           VkImage            dstImage,
                           VkImageLayout      dstImageLayout,
                           uint32_t           regionCount,
                           const VkImageBlit* pRegions,
                           VkFilter           filter);

    void TrackCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

    void TrackCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

    void TrackCmdUpdateBuffer(VkCommandBuffer commandBuffer,
                              VkBuffer        dstBuffer,
                              VkDeviceSize    dstOffset,
                              VkDeviceSize    dataSize,
                              const void*     pData);

    void TrackCmdFillBuffer(
        VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);

    void TrackCmdClearColorImage(VkCommandBuffer                commandBuffer,
                                 VkImage                        image,
                                 VkImageLayout                  imageLayout,
                                 const VkClearColorValue*       pColor,
                                 uint32_t                       rangeCount,
                                 const VkImageSubresourceRange* pRanges);

    void TrackCmdClearDepthStencilImage(VkCommandBuffer                 commandBuffer,
                                        VkImage                         image,
                                        VkImageLayout                   imageLayout,
                                        const VkClearDepthStencilValue* pDepthStencil,
                                        uint32_t                        rangeCount,
                                        const VkImageSubresourceRange*  pRanges);

    void TrackCmdDraw(VkCommandBuffer commandBuffer,
                      uint32_t        vertexCount,
                      uint32_t        instanceCount,
                      uint32_t        firstVertex,
                      uint32_t        firstInstance);

    void TrackCmdDrawIndexed(VkCommandBuffer commandBuffer,
                             uint32_t        indexCount,
                             uint32_t        instanceCount,
                             uint32_t        firstIndex,
                             int32_t         vertexOffset,
                             uint32_t        firstInstance);

    void TrackCmdDrawIndirect(
        VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

    void TrackCmdDrawIndexedIndirect(
        VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

    void TrackCmdDrawIndirectCount(VkCommandBuffer commandBuffer,
                                   VkBuffer        buffer,
                                   VkDeviceSize    offset,
                                   VkBuffer        countBuffer,
                                   VkDeviceSize    countBufferOffset,
                                   uint32_t        maxDrawCount,
                                   uint32_t        stride);

    void TrackCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer,
                                          VkBuffer        buffer,
                                          VkDeviceSize    offset,
                                          VkBuffer        countBuffer,
                                          VkDeviceSize    countBufferOffset,
                                          uint32_t        maxDrawCount,
                                          uint32_t        stride);

    void TrackCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer,
                                      VkBuffer        buffer,
                                      VkDeviceSize    offset,
                                      VkBuffer        countBuffer,
                                      VkDeviceSize    countBufferOffset,
                                      uint32_t        maxDrawCount,
                                      uint32_t        stride);

    void TrackCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer,
                                             VkBuffer        buffer,
                                             VkDeviceSize    offset,
                                             VkBuffer        countBuffer,
                                             VkDeviceSize    countBufferOffset,
                                             uint32_t        maxDrawCount,
                                             uint32_t        stride);

    void
    TrackCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

    void TrackCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

    void TrackCmdDispatchBase(VkCommandBuffer commandBuffer,
                              uint32_t        baseGroupX,
                              uint32_t        baseGroupY,
                              uint32_t        baseGroupZ,
                              uint32_t        groupCountX,
                              uint32_t        groupCountY,
                              uint32_t        groupCountZ);

    void TrackCmdDispatchBaseKHR(VkCommandBuffer commandBuffer,
                                 uint32_t        baseGroupX,
                                 uint32_t        baseGroupY,
                                 uint32_t        baseGroupZ,
                                 uint32_t        groupCountX,
                                 uint32_t        groupCountY,
                                 uint32_t        groupCountZ);

    void TrackCmdTraceRaysNV(VkCommandBuffer commandBuffer,
                             VkBuffer        raygenShaderBindingTableBuffer,
                             VkDeviceSize    raygenShaderBindingOffset,
                             VkBuffer        missShaderBindingTableBuffer,
                             VkDeviceSize    missShaderBindingOffset,
                             VkDeviceSize    missShaderBindingStride,
                             VkBuffer        hitShaderBindingTableBuffer,
                             VkDeviceSize    hitShaderBindingOffset,
                             VkDeviceSize    hitShaderBindingStride,
                             VkBuffer        callableShaderBindingTableBuffer,
                             VkDeviceSize    callableShaderBindingOffset,
                             VkDeviceSize    callableShaderBindingStride,
                             uint32_t        width,
                             uint32_t        height,
                             uint32_t        depth);

    void TrackCmdTraceRaysKHR(VkCommandBuffer                        commandBuffer,
                              const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                              const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                              const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                              const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                              uint32_t                               width,
                              uint32_t                               height,
                              uint32_t                               depth);

    void TrackCmdTraceRaysIndirectKHR(VkCommandBuffer                        commandBuffer,
                                      const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                      VkDeviceAddress                        indirectDeviceAddress);

    void TrackCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);

    void TrackCmdResolveImage(VkCommandBuffer       commandBuffer,
                              VkImage               srcImage,
                              VkImageLayout         srcImageLayout,
                              VkImage               dstImage,
                              VkImageLayout         dstImageLayout,
                              uint32_t              regionCount,
                              const VkImageResolve* pRegions);

    void TrackCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

    void TrackCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);

    void TrackCmdDrawMeshTasksIndirectNV(
        VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

    void TrackCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer,
                                              VkBuffer        buffer,
                                              VkDeviceSize    offset,
                                              VkBuffer        countBuffer,
                                              VkDeviceSize    countBufferOffset,
                                              uint32_t        maxDrawCount,
                                              uint32_t        stride);

    void TrackCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer,
                                  uint32_t        groupCountX,
                                  uint32_t        groupCountY,
                                  uint32_t        groupCountZ);

    void TrackCmdDrawMeshTasksIndirectEXT(
        VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

    void TrackCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer,
                                               VkBuffer        buffer,
                                               VkDeviceSize    offset,
                                               VkBuffer        countBuffer,
                                               VkDeviceSize    countBufferOffset,
                                               uint32_t        maxDrawCount,
                                               uint32_t        stride);

    void TrackAssetsInSubmission(uint32_t submitCount, const VkSubmitInfo* pSubmits);

    void TrackAssetsInSubmission(uint32_t submitCount, const VkSubmitInfo2* pSubmits);

    void TrackBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

    void TrackSetDebugUtilsObjectNameEXT(VkDevice                             device,
                                         const VkDebugUtilsObjectNameInfoEXT* pNameInfo,
                                         const util::MemoryOutputStream*      object_name_parameter_buffer);

    void TrackSetDebugUtilsObjectTagEXT(VkDevice                            device,
                                        const VkDebugUtilsObjectTagInfoEXT* pTagInfo,
                                        const util::MemoryOutputStream*     object_tag_parameter_buffer);

  private:
    template <typename ParentHandle, typename SecondaryHandle, typename Wrapper, typename CreateInfo>
    void AddGroupHandles(ParentHandle                        parent_handle,
                         SecondaryHandle                     secondary_handle,
                         uint32_t                            count,
                         typename Wrapper::HandleType*       new_handles,
                         const CreateInfo*                   create_infos,
                         format::ApiCallId                   create_call_id,
                         vulkan_state_info::CreateParameters create_parameters)
    {
        assert(new_handles != nullptr);
        assert(create_parameters != nullptr);

        std::unique_lock<std::mutex> lock(state_table_mutex_);
        for (uint32_t i = 0; i < count; ++i)
        {
            if (new_handles[i] != VK_NULL_HANDLE)
            {
                auto wrapper = vulkan_wrappers::GetWrapper<Wrapper>(new_handles[i]);

                // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
                if (state_table_.InsertWrapper(wrapper->handle_id, wrapper))
                {
                    const CreateInfo* create_info = nullptr;

                    // Not all handle creation operations will have a create info structure (e.g.
                    // VkPhysicalDevice handles retrieved with vkEnumeratePhysicalDevices).
                    if (create_infos != nullptr)
                    {
                        create_info = vulkan_state_tracker::GetCreateInfoEntry(i, create_infos);
                    }

                    vulkan_state_tracker::
                        InitializeGroupObjectState<ParentHandle, SecondaryHandle, Wrapper, CreateInfo>(
                            parent_handle, secondary_handle, wrapper, create_info, create_call_id, create_parameters);
                }
            }
        }
    }

    void TrackCommandExecution(vulkan_wrappers::CommandBufferWrapper* wrapper,
                               format::ApiCallId                      call_id,
                               const util::MemoryOutputStream*        parameter_buffer);

    template <typename Wrapper>
    void DestroyState(Wrapper* wrapper)
    {
        assert(wrapper != nullptr);
        wrapper->create_parameters = nullptr;
    }

    void DestroyState(vulkan_wrappers::InstanceWrapper* wrapper);

    void DestroyState(vulkan_wrappers::DeviceWrapper* wrapper);

    void DestroyState(vulkan_wrappers::CommandPoolWrapper* wrapper);

    void DestroyState(vulkan_wrappers::DescriptorPoolWrapper* wrapper);

    void DestroyState(vulkan_wrappers::SwapchainKHRWrapper* wrapper);

    void DestroyState(vulkan_wrappers::DeviceMemoryWrapper* wrapper);

    void DestroyState(vulkan_wrappers::BufferWrapper* wrapper);

    void DestroyState(vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper);

    void DestroyState(vulkan_wrappers::AccelerationStructureNVWrapper* wrapper);

    void DestroyState(vulkan_wrappers::ImageWrapper* wrapper);

    void DestroyState(vulkan_wrappers::ImageViewWrapper* wrapper);

    void DestroyState(vulkan_wrappers::BufferViewWrapper* wrapper);

    void DestroyState(vulkan_wrappers::SamplerWrapper* wrapper);

    void DestroyState(vulkan_wrappers::DescriptorSetWrapper* wrapper);

    void TrackQuerySubmissions(vulkan_wrappers::CommandBufferWrapper* command_wrapper);

    void TrackPipelineDescriptors(vulkan_wrappers::CommandBufferWrapper* command_wrapper,
                                  vulkan_state_info::PipelineBindPoints  ppl_bind_point);

    void InsertImageAssetInCommandBuffer(VkCommandBuffer command_buffer, VkImage image);

    void InsertBufferAssetInCommandBuffer(VkCommandBuffer command_buffer, VkBuffer buffer);

    void TrackMappedAssetsWrites(format::HandleId memory_id);

    void MarkReferencedAssetsAsDirty(vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper);

    std::mutex       state_table_mutex_;
    VulkanStateTable state_table_;

    // Keeps track of device memories' device addresses
    std::unordered_map<VkDeviceAddress, const vulkan_wrappers::DeviceMemoryWrapper*> device_memory_addresses_map;

    // Keeps track of buffer- and acceleration-structure device addresses
    std::unordered_map<VkDevice, encode::VulkanDeviceAddressTracker> device_address_trackers_;

    std::map<VkDevice, graphics::VulkanResourcesUtil> resource_utils_;

    VulkanStateWriter::AssetFileOffsetsInfo asset_file_offsets_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_TRACKER_H
