/*
** Copyright (c) 2019-2021 LunarG, Inc.
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

    uint64_t WriteState(VulkanStateWriter* writer, uint64_t frame_number)
    {
        if (writer != nullptr)
        {
            std::unique_lock<std::mutex> lock(state_table_mutex_);
            return writer->WriteState(state_table_, frame_number);
        }

        return 0;
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
                                                 VkSurfaceCapabilities2KHR*             surface_capabilities);

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
                           VkMemoryMapFlags mapped_flags);

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

    void TrackTLASBuildCommand(VkCommandBuffer                                        command_buffer,
                               uint32_t                                               info_count,
                               const VkAccelerationStructureBuildGeometryInfoKHR*     infos,
                               const VkAccelerationStructureBuildRangeInfoKHR* const* pp_buildRange_infos);

    void TrackDeviceMemoryDeviceAddress(VkDevice device, VkDeviceMemory memory, VkDeviceAddress address);

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

    void DestroyState(vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper);

    void TrackQuerySubmissions(vulkan_wrappers::CommandBufferWrapper* command_wrapper);

    std::mutex       state_table_mutex_;
    VulkanStateTable state_table_;

    // Keeps track of device memories' device addresses
    std::unordered_map<VkDeviceAddress, const vulkan_wrappers::DeviceMemoryWrapper*> device_memory_addresses_map;

    // Keeps track of acceleration structures' device addresses
    std::unordered_map<VkDeviceAddress, vulkan_wrappers::AccelerationStructureKHRWrapper*> as_device_addresses_map;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_TRACKER_H
