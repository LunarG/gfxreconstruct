/*
 ** Copyright (c) 2018-2021 Valve Corporation
 ** Copyright (c) 2018-2025 LunarG, Inc.
 ** Copyright (c) 2019-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_VULKAN_CAPTURE_MANAGER_H
#define GFXRECON_ENCODE_VULKAN_CAPTURE_MANAGER_H

#include "encode/api_capture_manager.h"

#include "encode/capture_settings.h"
#include "encode/descriptor_update_template_info.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_tracker.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_command_buffer_util.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vulkan/vulkan_core.h"

#include <atomic>
#include <cassert>
#include <memory>
#include <mutex>
#include <set>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanCaptureManager : public ApiCaptureManager
{
  public:
    static VulkanCaptureManager* Get() { return singleton_; }

    // Creates the capture manager instance if none exists, or increments a reference count if an instance already
    // exists.
    static bool CreateInstance();

    static VulkanCaptureManager* InitSingleton();
    static void                  DestroySingleton();

    // Decrement the instance reference count, releasing resources when the count reaches zero.  Ignored if the count is
    // already zero.
    static void DestroyInstance();

    // Register special layer provided functions, which perform layer specific initialization.
    // These must be set before the application calls vkCreateInstance.
    static void SetLayerFuncs(PFN_vkCreateInstance create_instance, PFN_vkCreateDevice create_device);

    // Called by the layer's vkCreateInstance function, after the driver's vkCreateInstance function has been called, to
    // check for failure.  If vkCreateInstance failed, the reference count will be decremented and resources will be
    // released as necessary.  Allows a failed vkCreateInstance call to be logged to the capture file while performing
    // the appropriate resource cleanup.
    static void CheckVkCreateInstanceStatus(VkResult result);

    static const graphics::VulkanLayerTable* GetLayerTable() { return &vulkan_layer_table_; }

    void InitVkInstance(VkInstance* instance, PFN_vkGetInstanceProcAddr gpa);

    void InitVkDevice(VkDevice* device, PFN_vkGetDeviceProcAddr gpa);

    // Single object creation.
    template <typename ParentHandle, typename Wrapper, typename CreateInfo>
    void EndCreateApiCallCapture(VkResult                      result,
                                 ParentHandle                  parent_handle,
                                 typename Wrapper::HandleType* handle,
                                 const CreateInfo*             create_info)
    {
        if (IsCaptureModeTrack() && result == VK_SUCCESS)
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddEntry<ParentHandle, Wrapper, CreateInfo>(
                parent_handle, handle, create_info, thread_data->call_id_, thread_data->parameter_buffer_.get());
        }

        EndApiCallCapture();
    }

    // Pool allocation.
    template <typename ParentHandle, typename Wrapper, typename AllocateInfo>
    void EndPoolCreateApiCallCapture(VkResult                      result,
                                     ParentHandle                  parent_handle,
                                     uint32_t                      count,
                                     typename Wrapper::HandleType* handles,
                                     const AllocateInfo*           alloc_info)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS) && (handles != nullptr))
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddPoolEntry<ParentHandle, Wrapper, AllocateInfo>(
                parent_handle, count, handles, alloc_info, thread_data->call_id_, thread_data->parameter_buffer_.get());
        }

        EndApiCallCapture();
    }

    // Multiple object creation.
    template <typename ParentHandle, typename SecondaryHandle, typename Wrapper, typename CreateInfo>
    void EndGroupCreateApiCallCapture(VkResult                      result,
                                      ParentHandle                  parent_handle,
                                      SecondaryHandle               secondary_handle,
                                      uint32_t                      count,
                                      typename Wrapper::HandleType* handles,
                                      const CreateInfo*             create_infos)
    {
        if (IsCaptureModeTrack() &&
            ((result == VK_SUCCESS) || (result == VK_OPERATION_DEFERRED_KHR) ||
             (result == VK_OPERATION_NOT_DEFERRED_KHR) || (result == VK_INCOMPLETE)) &&
            (handles != nullptr))
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddGroupEntry<ParentHandle, SecondaryHandle, Wrapper, CreateInfo>(
                parent_handle,
                secondary_handle,
                count,
                handles,
                create_infos,
                thread_data->call_id_,
                thread_data->parameter_buffer_.get());
        }

        EndApiCallCapture();
    }

    // Multiple implicit object creation inside output struct.
    template <typename ParentHandle, typename Wrapper, typename HandleStruct>
    void EndStructGroupCreateApiCallCapture(VkResult                               result,
                                            ParentHandle                           parent_handle,
                                            uint32_t                               count,
                                            HandleStruct*                          handle_structs,
                                            std::function<Wrapper*(HandleStruct*)> unwrap_struct_handle)
    {
        if (IsCaptureModeTrack() && ((result == VK_SUCCESS) || (result == VK_INCOMPLETE)) &&
            (handle_structs != nullptr))
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddStructGroupEntry(parent_handle,
                                                count,
                                                handle_structs,
                                                unwrap_struct_handle,
                                                thread_data->call_id_,
                                                thread_data->parameter_buffer_.get());
        }

        EndApiCallCapture();
    }

    // Single object destruction.
    template <typename Wrapper>
    void EndDestroyApiCallCapture(typename Wrapper::HandleType handle)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->RemoveEntry<Wrapper>(handle);
        }

        EndApiCallCapture();
    }

    // Multiple object destruction.
    template <typename Wrapper>
    void EndDestroyApiCallCapture(uint32_t count, const typename Wrapper::HandleType* handles)
    {
        if (IsCaptureModeTrack() && (handles != nullptr))
        {
            assert(state_tracker_ != nullptr);

            for (uint32_t i = 0; i < count; ++i)
            {
                state_tracker_->RemoveEntry<Wrapper>(handles[i]);
            }
        }

        EndApiCallCapture();
    }

    void ProcessEndCommandApiCallCapture(VkCommandBuffer command_buffer, format::ApiCallId call_id)
    {
        if ((call_id == format::ApiCallId::ApiCall_vkBeginCommandBuffer) ||
            (call_id == format::ApiCallId::ApiCall_vkResetCommandBuffer))
        {
            auto cmd_buffer_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
            GFXRECON_ASSERT(cmd_buffer_wrapper != nullptr);
            cmd_buffer_wrapper->is_frame_boundary = false;
        }
    }

    void EndCommandApiCallCapture(VkCommandBuffer command_buffer)
    {
        auto thread_data = GetThreadData();
        GFXRECON_ASSERT(thread_data != nullptr);

        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackCommand(command_buffer, thread_data->call_id_, thread_data->parameter_buffer_.get());
        }

        ProcessEndCommandApiCallCapture(command_buffer, thread_data->call_id_);

        EndApiCallCapture();
    }

    template <typename GetHandlesFunc, typename... GetHandlesArgs>
    void EndCommandApiCallCapture(VkCommandBuffer command_buffer, GetHandlesFunc func, GetHandlesArgs... args)
    {
        auto thread_data = GetThreadData();
        GFXRECON_ASSERT(thread_data != nullptr);

        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackCommand(
                command_buffer, thread_data->call_id_, thread_data->parameter_buffer_.get(), func, args...);
        }

        ProcessEndCommandApiCallCapture(command_buffer, thread_data->call_id_);

        EndApiCallCapture();
    }

    bool GetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate update_template,
                                         const UpdateTemplateInfo** info) const;

    bool CheckWriteWaitForPresentKHR(
        VkResult result, VkDevice device, VkSwapchainKHR swapchain, graphics::PresentId present_id, uint64_t timeout)
    {
        if (IsCaptureModeWrite())
        {
            // During trimming, WaitForPresent's QueuePresent couldn't be written since it's before trim frame range.
            // In this case, skip writing the WaitForPresent.
            auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);
            GFXRECON_ASSERT(wrapper != nullptr);
            auto entry = wrapper->record_queue_present_ids_not_written.find(present_id);
            if (entry != wrapper->record_queue_present_ids_not_written.end())
            {
                GFXRECON_LOG_WARNING(
                    "Skip writing WaitForPresent(Swapchain: %" PRIu64 ", Present Id: %" PRIu64
                    ") because its QueuePresent is before trim frame range. The QueuePresent isn't written.",
                    swapchain,
                    present_id);
                return false;
            }
        }
        return true;
    }

    static VkResult OverrideCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator,
                                           VkInstance*                  pInstance);

    VkResult OverrideCreateDevice(VkPhysicalDevice             physicalDevice,
                                  const VkDeviceCreateInfo*    pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator,
                                  VkDevice*                    pDevice);

    VkResult OverrideCreateBuffer(VkDevice                     device,
                                  const VkBufferCreateInfo*    pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator,
                                  VkBuffer*                    pBuffer);

    VkResult OverrideCreateImage(VkDevice                     device,
                                 const VkImageCreateInfo*     pCreateInfo,
                                 const VkAllocationCallbacks* pAllocator,
                                 VkImage*                     pImage);

    VkResult OverrideCreateAccelerationStructureKHR(VkDevice                                    device,
                                                    const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
                                                    const VkAllocationCallbacks*                pAllocator,
                                                    VkAccelerationStructureKHR* pAccelerationStructureKHR);

    void
    OverrideCmdBuildAccelerationStructuresKHR(VkCommandBuffer                                        commandBuffer,
                                              uint32_t                                               infoCount,
                                              const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
                                              const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);

    void OverrideCmdCopyAccelerationStructureKHR(VkCommandBuffer                           command_buffer,
                                                 const VkCopyAccelerationStructureInfoKHR* pInfo);

    void OverrideCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer,
                                                             uint32_t        accelerationStructureCount,
                                                             const VkAccelerationStructureKHR* pAccelerationStructures,
                                                             VkQueryType                       queryType,
                                                             VkQueryPool                       queryPool,
                                                             uint32_t                          firstQuery);

    VkResult OverrideAllocateMemory(VkDevice                     device,
                                    const VkMemoryAllocateInfo*  pAllocateInfo,
                                    const VkAllocationCallbacks* pAllocator,
                                    VkDeviceMemory*              pMemory);

    void OverrideGetPhysicalDeviceProperties2(VkPhysicalDevice             physicalDevice,
                                              VkPhysicalDeviceProperties2* pProperties);

    VkResult OverrideGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice                   physicalDevice,
                                                        uint32_t*                          pToolCount,
                                                        VkPhysicalDeviceToolPropertiesEXT* pToolProperties);

    VkResult OverrideCreateRayTracingPipelinesKHR(VkDevice                                 device,
                                                  VkDeferredOperationKHR                   deferredOperation,
                                                  VkPipelineCache                          pipelineCache,
                                                  uint32_t                                 createInfoCount,
                                                  const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                                  const VkAllocationCallbacks*             pAllocator,
                                                  VkPipeline*                              pPipelines);

    VkResult OverrideDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation);

    VkResult OverrideGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation);

    void DeferredOperationPostProcess(VkDevice               device,
                                      VkDeferredOperationKHR deferredOperation,
                                      bool                   capture_manager_tracking);

    void OverrideGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice         physicalDevice,
                                                        uint32_t*                pQueueFamilyPropertyCount,
                                                        VkQueueFamilyProperties* pQueueFamilyProperties);

    void OverrideGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice          physicalDevice,
                                                         uint32_t*                 pQueueFamilyPropertyCount,
                                                         VkQueueFamilyProperties2* pQueueFamilyProperties);

    void OverrideGetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice          physicalDevice,
                                                            uint32_t*                 pQueueFamilyPropertyCount,
                                                            VkQueueFamilyProperties2* pQueueFamilyProperties);

    VkResult OverrideAllocateCommandBuffers(VkDevice                           device,
                                            const VkCommandBufferAllocateInfo* pAllocateInfo,
                                            VkCommandBuffer*                   pCommandBuffers);

    void PreProcess_vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);

    void PostProcess_vkBeginCommandBuffer(VkResult                        result,
                                          VkCommandBuffer                 commandBuffer,
                                          const VkCommandBufferBeginInfo* pBeginInfo)
    {
        if (IsCaptureModeTrack() && result == VK_SUCCESS)
        {
            state_tracker_->TrackBeginCommandBuffer(commandBuffer, pBeginInfo->flags);
        }
    }

    void PostProcess_vkEnumeratePhysicalDevices(VkResult          result,
                                                VkInstance        instance,
                                                uint32_t*         pPhysicalDeviceCount,
                                                VkPhysicalDevice* pPhysicalDevices);

    void PostProcess_vkEnumeratePhysicalDeviceGroups(VkResult                         result,
                                                     VkInstance                       instance,
                                                     uint32_t*                        pPhysicalDeviceGroupCount,
                                                     VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);

    void PostProcess_vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice         physicalDevice,
                                                              uint32_t*                pQueueFamilyPropertyCount,
                                                              VkQueueFamilyProperties* pQueueFamilyProperties)
    {
        if (IsCaptureModeTrack() && (pQueueFamilyPropertyCount != nullptr) && (pQueueFamilyProperties != nullptr))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceQueueFamilyProperties(
                physicalDevice, *pQueueFamilyPropertyCount, pQueueFamilyProperties);
        }
    }

    void PostProcess_vkGetPhysicalDeviceQueueFamilyProperties2(format::ApiCallId         call_id,
                                                               VkPhysicalDevice          physicalDevice,
                                                               uint32_t*                 pQueueFamilyPropertyCount,
                                                               VkQueueFamilyProperties2* pQueueFamilyProperties)
    {
        if (IsCaptureModeTrack() && (pQueueFamilyPropertyCount != nullptr) && (pQueueFamilyProperties != nullptr))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceQueueFamilyProperties2(
                call_id, physicalDevice, *pQueueFamilyPropertyCount, pQueueFamilyProperties);
        }
    }

    void PostProcess_vkGetPhysicalDeviceSurfaceSupportKHR(VkResult         result,
                                                          VkPhysicalDevice physicalDevice,
                                                          uint32_t         queueFamilyIndex,
                                                          VkSurfaceKHR     surface,
                                                          VkBool32*        pSupported)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS) && (pSupported != nullptr))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceSurfaceSupport(physicalDevice, queueFamilyIndex, surface, *pSupported);
        }
    }

    void PostProcess_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkResult                  result,
                                                               VkPhysicalDevice          physicalDevice,
                                                               VkSurfaceKHR              surface,
                                                               VkSurfaceCapabilitiesKHR* pSurfaceCapabilities)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS) && (pSurfaceCapabilities != nullptr))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceSurfaceCapabilities(physicalDevice, surface, pSurfaceCapabilities);
        }
    }

    void PostProcess_vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkResult                               result,
                                                                VkPhysicalDevice                       physicalDevice,
                                                                const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                VkSurfaceCapabilities2KHR* pSurfaceCapabilities)
    {
        GFXRECON_UNREFERENCED_PARAMETER(physicalDevice);

        if (IsCaptureModeTrack() && (result == VK_SUCCESS) && (pSurfaceCapabilities != nullptr))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceSurfaceCapabilities2(
                physicalDevice, *pSurfaceInfo, pSurfaceCapabilities);
        }
    }

    void PostProcess_vkGetPhysicalDeviceSurfaceFormatsKHR(VkResult            result,
                                                          VkPhysicalDevice    physicalDevice,
                                                          VkSurfaceKHR        surface,
                                                          uint32_t*           pSurfaceFormatCount,
                                                          VkSurfaceFormatKHR* pSurfaceFormats)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS) && (pSurfaceFormatCount != nullptr) &&
            (pSurfaceFormats != nullptr))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceSurfaceFormats(
                physicalDevice, surface, *pSurfaceFormatCount, pSurfaceFormats);
        }
    }

    void PostProcess_vkGetPhysicalDeviceSurfaceFormats2KHR(VkResult                               result,
                                                           VkPhysicalDevice                       physicalDevice,
                                                           const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                           uint32_t*                              pSurfaceFormatCount,
                                                           VkSurfaceFormat2KHR*                   pSurfaceFormats)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS) && (pSurfaceFormatCount != nullptr) &&
            (pSurfaceFormats != nullptr))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceSurfaceFormats2(
                physicalDevice, *pSurfaceInfo, *pSurfaceFormatCount, pSurfaceFormats);
        }
    }

    void PostProcess_vkGetPhysicalDeviceSurfacePresentModesKHR(VkResult          result,
                                                               VkPhysicalDevice  physicalDevice,
                                                               VkSurfaceKHR      surface,
                                                               uint32_t*         pPresentModeCount,
                                                               VkPresentModeKHR* pPresentModes)
    {
        if ((pPresentModeCount != nullptr) && (pPresentModes != nullptr))
        {
            if (IsCaptureModeTrack() && (result == VK_SUCCESS))
            {
                assert(state_tracker_ != nullptr);
                state_tracker_->TrackPhysicalDeviceSurfacePresentModes(
                    physicalDevice, surface, *pPresentModeCount, pPresentModes);
            }

#if defined(__ANDROID__)
            OverrideGetPhysicalDeviceSurfacePresentModesKHR(pPresentModeCount, pPresentModes);
#endif
        }
    }

    void PreProcess_vkCreateXlibSurfaceKHR(VkInstance                        instance,
                                           const VkXlibSurfaceCreateInfoKHR* pCreateInfo,
                                           const VkAllocationCallbacks*      pAllocator,
                                           VkSurfaceKHR*                     pSurface);

    void PreProcess_vkCreateXcbSurfaceKHR(VkInstance                       instance,
                                          const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                          const VkAllocationCallbacks*     pAllocator,
                                          VkSurfaceKHR*                    pSurface);

    void PreProcess_vkCreateWaylandSurfaceKHR(VkInstance                           instance,
                                              const VkWaylandSurfaceCreateInfoKHR* pCreateInfo,
                                              const VkAllocationCallbacks*         pAllocator,
                                              VkSurfaceKHR*                        pSurface);

    void PreProcess_vkCreateSwapchainKHR(VkDevice                        device,
                                         const VkSwapchainCreateInfoKHR* pCreateInfo,
                                         const VkAllocationCallbacks*    pAllocator,
                                         VkSwapchainKHR*                 pSwapchain);

    void PostProcess_vkCreateSwapchainKHR(VkResult                        result,
                                          VkDevice                        device,
                                          const VkSwapchainCreateInfoKHR* pCreateInfo,
                                          const VkAllocationCallbacks*    pAllocator,
                                          VkSwapchainKHR*                 pSwapchain);

    void PostProcess_vkAcquireNextImageKHR(VkResult result,
                                           VkDevice,
                                           VkSwapchainKHR swapchain,
                                           uint64_t,
                                           VkSemaphore semaphore,
                                           VkFence     fence,
                                           uint32_t*   index);

    void PostProcess_vkAcquireNextImage2KHR(VkResult result,
                                            VkDevice,
                                            const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                            uint32_t*                        index);

    void PostProcess_vkQueuePresentKHR(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                       VkResult                                               result,
                                       VkQueue                                                queue,
                                       const VkPresentInfoKHR*                                pPresentInfo);

    void PostProcess_vkQueueBindSparse(
        VkResult result, VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert((state_tracker_ != nullptr) && ((bindInfoCount == 0) || (pBindInfo != nullptr)));
            for (uint32_t i = 0; i < bindInfoCount; ++i)
            {
                state_tracker_->TrackSemaphoreSignalState(pBindInfo[i].waitSemaphoreCount,
                                                          pBindInfo[i].pWaitSemaphores,
                                                          pBindInfo[i].signalSemaphoreCount,
                                                          pBindInfo[i].pSignalSemaphores);
            }

            const std::lock_guard<std::mutex> lock(sparse_resource_mutex);
            for (uint32_t bind_info_index = 0; bind_info_index < bindInfoCount; bind_info_index++)
            {
                auto& bind_info = pBindInfo[bind_info_index];

                // TODO: add device group support. In the following handling, we assume that the system only has one
                // physical device or that resourceDeviceIndex and memoryDeviceIndex of VkDeviceGroupBindSparseInfo in
                // the pnext chain are zero.

                if (bind_info.pBufferBinds != nullptr)
                {
                    // The title binds sparse buffers to memory ranges, so we need to track the buffer binding
                    // information. The following updates will reflect the latest binding states for all buffers in this
                    // vkQueueBindSparse command, covering both fully-resident and partially-resident buffers.
                    for (uint32_t buffer_bind_index = 0; buffer_bind_index < bind_info.bufferBindCount;
                         buffer_bind_index++)
                    {
                        auto& buffer_bind   = bind_info.pBufferBinds[buffer_bind_index];
                        auto  sparse_buffer = buffer_bind.buffer;
                        auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(sparse_buffer);

                        if (wrapper != nullptr)
                        {
                            wrapper->sparse_bind_queue = queue;
                            for (uint32_t bind_memory_range_index = 0; bind_memory_range_index < buffer_bind.bindCount;
                                 bind_memory_range_index++)
                            {
                                auto& bind_memory_range = buffer_bind.pBinds[bind_memory_range_index];
                                graphics::UpdateSparseMemoryBindMap(wrapper->sparse_memory_bind_map, bind_memory_range);
                            }
                        }
                    }
                }

                if (bind_info.pImageOpaqueBinds != nullptr)
                {
                    // The title binds sparse images to opaque memory ranges, so we need to track the image binding
                    // information. The following handling will update the latest binding states for all images in this
                    // vkQueueBindSparse command, which utilizes opaque memory binding. There are two cases covered by
                    // the tracking. In the first case, the sparse image exclusively uses opaque memory binding. For
                    // this case, the target title treats the binding memory ranges as a linear unified region. This
                    // should represent a fully-resident binding because this linear region is entirely opaque, meaning
                    // there is no application-visible mapping between texel locations and memory offsets. In another
                    // case, the image utilizes subresource sparse memory binding, just binding only its mip tail region
                    // to an opaque memory range. For this situation, we use the sparse_opaque_memory_bind_map and
                    // sparse_subresource_memory_bind_map of the image wrapper to track the subresource bindings and
                    // opaque bindings separately.
                    for (uint32_t image_opaque_bind_index = 0; image_opaque_bind_index < bind_info.imageOpaqueBindCount;
                         image_opaque_bind_index++)
                    {
                        auto& image_opaque_bind = bind_info.pImageOpaqueBinds[image_opaque_bind_index];
                        auto  sparse_image      = image_opaque_bind.image;
                        auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(sparse_image);

                        if (wrapper != nullptr)
                        {
                            wrapper->sparse_bind_queue = queue;

                            for (uint32_t bind_memory_range_index = 0;
                                 bind_memory_range_index < image_opaque_bind.bindCount;
                                 bind_memory_range_index++)
                            {
                                auto& bind_memory_range = image_opaque_bind.pBinds[bind_memory_range_index];
                                graphics::UpdateSparseMemoryBindMap(wrapper->sparse_opaque_memory_bind_map,
                                                                    bind_memory_range);
                            }
                        }
                    }
                }

                if (bind_info.pImageBinds != nullptr)
                {
                    // The title binds subresources of a sparse image to memory ranges, which requires us to keep track
                    // of the sparse image subresource binding information. It's important to note that while the image
                    // mainly use subresource sparse memory binding, its mip tail region must be bound to an opaque
                    // memory range. Therefore, we use the sparse_opaque_memory_bind_map and
                    // sparse_subresource_memory_bind_map of the image wrapper to separately track both the
                    // subresource bindings and the opaque bindings.
                    for (uint32_t image_bind_index = 0; image_bind_index < bind_info.imageBindCount; image_bind_index++)
                    {
                        auto& image_bind   = bind_info.pImageBinds[image_bind_index];
                        auto  sparse_image = image_bind.image;
                        auto  wrapper      = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(sparse_image);

                        if (wrapper != nullptr)
                        {
                            wrapper->sparse_bind_queue = queue;

                            for (uint32_t bind_memory_range_index = 0; bind_memory_range_index < image_bind.bindCount;
                                 bind_memory_range_index++)
                            {
                                auto& bind_memory_range = image_bind.pBinds[bind_memory_range_index];
                                // TODO: Implement handling for tracking binding information of sparse image
                                // subresources.
                                GFXRECON_LOG_ERROR_ONCE("Binding of sparse image blocks is not supported!");
                            }
                        }
                    }
                }
            }
        }
    }

    void PostProcess_vkGetBufferMemoryRequirements(VkDevice              device,
                                                   VkBuffer              buffer,
                                                   VkMemoryRequirements* pMemoryRequirements)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        GFXRECON_UNREFERENCED_PARAMETER(buffer);

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
             GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
            GetPageGuardAlignBufferSizes() && (pMemoryRequirements != nullptr))
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->size);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->alignment);

            pMemoryRequirements->size = manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->size));
            pMemoryRequirements->alignment =
                manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->alignment));
        }
    }

    void PostProcess_vkGetBufferMemoryRequirements2(VkDevice                               device,
                                                    const VkBufferMemoryRequirementsInfo2* pInfo,
                                                    VkMemoryRequirements2*                 pMemoryRequirements)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        GFXRECON_UNREFERENCED_PARAMETER(pInfo);

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
             GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
            GetPageGuardAlignBufferSizes() && (pMemoryRequirements != nullptr))
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->memoryRequirements.size);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->memoryRequirements.alignment);

            pMemoryRequirements->memoryRequirements.size =
                manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->memoryRequirements.size));
            pMemoryRequirements->memoryRequirements.alignment =
                manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->memoryRequirements.alignment));
        }
    }

    void PostProcess_vkGetDeviceBufferMemoryRequirements(VkDevice                                device,
                                                         const VkDeviceBufferMemoryRequirements* pInfo,
                                                         VkMemoryRequirements2*                  pMemoryRequirements)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        GFXRECON_UNREFERENCED_PARAMETER(pInfo);

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
             GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
            GetPageGuardAlignBufferSizes() && (pMemoryRequirements != nullptr))
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->memoryRequirements.size);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->memoryRequirements.alignment);

            pMemoryRequirements->memoryRequirements.size =
                manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->memoryRequirements.size));
            pMemoryRequirements->memoryRequirements.alignment =
                manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->memoryRequirements.alignment));
        }
    }

    void
    PostProcess_vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        GFXRECON_UNREFERENCED_PARAMETER(image);

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
             GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
            GetPageGuardAlignBufferSizes() && (pMemoryRequirements != nullptr))
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->size);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->alignment);

            pMemoryRequirements->size = manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->size));
            pMemoryRequirements->alignment =
                manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->alignment));
        }
    }

    void PostProcess_vkGetImageMemoryRequirements2(VkDevice                              device,
                                                   const VkImageMemoryRequirementsInfo2* pInfo,
                                                   VkMemoryRequirements2*                pMemoryRequirements)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        GFXRECON_UNREFERENCED_PARAMETER(pInfo);

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
             GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
            GetPageGuardAlignBufferSizes() && (pMemoryRequirements != nullptr))
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->memoryRequirements.size);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->memoryRequirements.alignment);

            pMemoryRequirements->memoryRequirements.size =
                manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->memoryRequirements.size));
            pMemoryRequirements->memoryRequirements.alignment =
                manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->memoryRequirements.alignment));
        }
    }

    void PostProcess_vkGetDeviceImageMemoryRequirements(VkDevice                               device,
                                                        const VkDeviceImageMemoryRequirements* pInfo,
                                                        VkMemoryRequirements2*                 pMemoryRequirements)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        GFXRECON_UNREFERENCED_PARAMETER(pInfo);

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
             GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
            GetPageGuardAlignBufferSizes() && (pMemoryRequirements != nullptr))
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->memoryRequirements.size);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pMemoryRequirements->memoryRequirements.alignment);

            pMemoryRequirements->memoryRequirements.size =
                manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->memoryRequirements.size));
            pMemoryRequirements->memoryRequirements.alignment =
                manager->GetAlignedSize(static_cast<size_t>(pMemoryRequirements->memoryRequirements.alignment));
        }
    }

    void PostProcess_vkGetImageSparseMemoryRequirements(VkDevice                         device,
                                                        VkImage                          image,
                                                        uint32_t*                        pSparseMemoryRequirementCount,
                                                        VkSparseImageMemoryRequirements* pSparseMemoryRequirements)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        GFXRECON_UNREFERENCED_PARAMETER(image);

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
             GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
            GetPageGuardAlignBufferSizes() && (pSparseMemoryRequirements != nullptr))
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pSparseMemoryRequirements->imageMipTailSize);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pSparseMemoryRequirements->imageMipTailOffset);

            pSparseMemoryRequirements->imageMipTailSize =
                manager->GetAlignedSize(static_cast<size_t>(pSparseMemoryRequirements->imageMipTailSize));
            pSparseMemoryRequirements->imageMipTailOffset =
                manager->GetAlignedSize(static_cast<size_t>(pSparseMemoryRequirements->imageMipTailOffset));
        }
    }

    void PostProcess_vkGetImageSparseMemoryRequirements2(VkDevice                                    device,
                                                         const VkImageSparseMemoryRequirementsInfo2* pInfo,
                                                         uint32_t* pSparseMemoryRequirementCount,
                                                         VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        GFXRECON_UNREFERENCED_PARAMETER(pInfo);

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
             GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
            GetPageGuardAlignBufferSizes() && (pSparseMemoryRequirements != nullptr))
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pSparseMemoryRequirements->memoryRequirements.imageMipTailSize);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t,
                                                pSparseMemoryRequirements->memoryRequirements.imageMipTailOffset);

            pSparseMemoryRequirements->memoryRequirements.imageMipTailSize = manager->GetAlignedSize(
                static_cast<size_t>(pSparseMemoryRequirements->memoryRequirements.imageMipTailSize));
            pSparseMemoryRequirements->memoryRequirements.imageMipTailOffset = manager->GetAlignedSize(
                static_cast<size_t>(pSparseMemoryRequirements->memoryRequirements.imageMipTailOffset));
        }
    }

    void
    PostProcess_vkGetDeviceImageSparseMemoryRequirements(VkDevice                               device,
                                                         const VkDeviceImageMemoryRequirements* pInfo,
                                                         uint32_t* pSparseMemoryRequirementCount,
                                                         VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        GFXRECON_UNREFERENCED_PARAMETER(pInfo);

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
             GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
            GetPageGuardAlignBufferSizes() && (pSparseMemoryRequirements != nullptr))
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pSparseMemoryRequirements->memoryRequirements.imageMipTailSize);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t,
                                                pSparseMemoryRequirements->memoryRequirements.imageMipTailOffset);

            pSparseMemoryRequirements->memoryRequirements.imageMipTailSize = manager->GetAlignedSize(
                static_cast<size_t>(pSparseMemoryRequirements->memoryRequirements.imageMipTailSize));
            pSparseMemoryRequirements->memoryRequirements.imageMipTailOffset = manager->GetAlignedSize(
                static_cast<size_t>(pSparseMemoryRequirements->memoryRequirements.imageMipTailOffset));
        }
    }

    void ProcessImportFdForBuffer(VkDevice device, VkBuffer buffer, VkDeviceSize memoryOffset);
    void ProcessImportFdForImage(VkDevice device, VkImage image, VkDeviceSize memoryOffset);

    void PostProcess_vkBindBufferMemory(
        VkResult result, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);

    void PostProcess_vkBindBufferMemory2(VkResult                      result,
                                         VkDevice                      device,
                                         uint32_t                      bindInfoCount,
                                         const VkBindBufferMemoryInfo* pBindInfos);

    void PostProcess_vkBindImageMemory(
        VkResult result, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);

    void PostProcess_vkBindImageMemory2(VkResult                     result,
                                        VkDevice                     device,
                                        uint32_t                     bindInfoCount,
                                        const VkBindImageMemoryInfo* pBindInfos);

    void PostProcess_vkCreateBuffer(VkResult                     result,
                                    VkDevice                     device,
                                    const VkBufferCreateInfo*    pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator,
                                    VkBuffer*                    pBuffer)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS) && (pCreateInfo != nullptr))
        {
            GFXRECON_ASSERT(state_tracker_ != nullptr);

            auto buffer_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(*pBuffer);

            if (buffer_wrapper->is_sparse_buffer)
            {
                // We will need to set the bind_device for handling sparse buffers. There will be no subsequent
                // vkBindBufferMemory, vkBindBufferMemory2 or vkBindBufferMemory2KHR calls for sparse buffer, so we
                // assign bind_device to the device that created the buffer.
                buffer_wrapper->bind_device = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
            }
        }
    }

    void PostProcess_vkCreateImage(VkResult                     result,
                                   VkDevice                     device,
                                   const VkImageCreateInfo*     pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator,
                                   VkImage*                     pImage)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS) && (pCreateInfo != nullptr))
        {
            GFXRECON_ASSERT(state_tracker_ != nullptr);

            auto image_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(*pImage);

            if (image_wrapper->is_sparse_image)
            {
                // We will need to set the bind_device for handling sparse images. There will be no subsequent
                // vkBindImageMemory, vkBindImageMemory2, or vkBindImageMemory2KHR calls for sparse image, so we assign
                // bind_device to the device that created the image.
                image_wrapper->bind_device = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
            }
        }
    }

    void PostProcess_vkCmdBeginRenderPass(VkCommandBuffer              commandBuffer,
                                          const VkRenderPassBeginInfo* pRenderPassBegin,
                                          VkSubpassContents)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackBeginRenderPass(commandBuffer, pRenderPassBegin);
        }
    }

    void PostProcess_vkCmdBeginRenderPass2(VkCommandBuffer              commandBuffer,
                                           const VkRenderPassBeginInfo* pRenderPassBegin,
                                           const VkSubpassBeginInfoKHR*)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackBeginRenderPass(commandBuffer, pRenderPassBegin);
        }
    }

    void PostProcess_vkCmdEndRenderPass(VkCommandBuffer commandBuffer)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackEndRenderPass(commandBuffer);
        }
    }

    void PostProcess_vkCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfoKHR*)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackEndRenderPass(commandBuffer);
        }
    }

    void PostProcess_vkCmdPipelineBarrier(VkCommandBuffer commandBuffer,
                                          VkPipelineStageFlags,
                                          VkPipelineStageFlags,
                                          VkDependencyFlags,
                                          uint32_t,
                                          const VkMemoryBarrier*,
                                          uint32_t,
                                          const VkBufferMemoryBarrier*,
                                          uint32_t                    imageMemoryBarrierCount,
                                          const VkImageMemoryBarrier* pImageMemoryBarriers)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackImageBarriers(commandBuffer, imageMemoryBarrierCount, pImageMemoryBarriers);
        }
    }

    void PostProcess_vkCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfoKHR* pDependencyInfo)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackImageBarriers2KHR(
                commandBuffer, pDependencyInfo->imageMemoryBarrierCount, pDependencyInfo->pImageMemoryBarriers);
        }
    }

    void PostProcess_vkCmdExecuteCommands(VkCommandBuffer        commandBuffer,
                                          uint32_t               commandBufferCount,
                                          const VkCommandBuffer* pCommandBuffers)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
        }
    }

    void PostProcess_vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackTrimCommandPool(device, commandPool);
        }
    }

    void PostProcess_vkResetCommandPool(VkResult result, VkDevice, VkCommandPool commandPool, VkCommandPoolResetFlags)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackResetCommandPool(commandPool);
        }
    }

    void PostProcess_vkQueueSubmit(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                   VkResult                                               result,
                                   VkQueue,
                                   uint32_t            submitCount,
                                   const VkSubmitInfo* pSubmits,
                                   VkFence)
    {
        PostQueueSubmit(current_lock);

        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert((state_tracker_ != nullptr) && ((submitCount == 0) || (pSubmits != nullptr)));

            state_tracker_->TrackCommandBufferSubmissions(submitCount, pSubmits);

            for (uint32_t i = 0; i < submitCount; ++i)
            {
                state_tracker_->TrackSemaphoreSignalState(pSubmits[i].waitSemaphoreCount,
                                                          pSubmits[i].pWaitSemaphores,
                                                          pSubmits[i].signalSemaphoreCount,
                                                          pSubmits[i].pSignalSemaphores);
            }
        }

        // Check whether this queue submission contains a command buffer that should be treated as a frame boundary.
        for (uint32_t i = 0; i < submitCount; ++i)
        {
            if (CheckPNextChainForFrameBoundary(current_lock, reinterpret_cast<const VkBaseInStructure*>(pSubmits + i)))
            {
                break;
            }

            for (uint32_t j = 0; j < pSubmits[i].commandBufferCount; ++j)
            {
                auto cmd_buffer_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(pSubmits[i].pCommandBuffers[j]);
                if (CheckCommandBufferWrapperForFrameBoundary(current_lock, cmd_buffer_wrapper))
                {
                    break;
                }
            }
        }
    }

    void PostProcess_vkQueueSubmit2(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                    VkResult                                               result,
                                    VkQueue                                                queue,
                                    uint32_t                                               submitCount,
                                    const VkSubmitInfo2*                                   pSubmits,
                                    VkFence                                                fence)
    {
        PostQueueSubmit(current_lock);

        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert((state_tracker_ != nullptr) && ((submitCount == 0) || (pSubmits != nullptr)));

            state_tracker_->TrackCommandBufferSubmissions2(submitCount, pSubmits);

            for (uint32_t i = 0; i < submitCount; ++i)
            {
                state_tracker_->TrackSemaphoreInfoSignalState(pSubmits[i].waitSemaphoreInfoCount,
                                                              pSubmits[i].pWaitSemaphoreInfos,
                                                              pSubmits[i].signalSemaphoreInfoCount,
                                                              pSubmits[i].pSignalSemaphoreInfos);
            }
        }

        // Check whether this queue submission contains a command buffer that should be treated as a frame boundary.
        for (uint32_t i = 0; i < submitCount; ++i)
        {
            if (CheckPNextChainForFrameBoundary(current_lock, reinterpret_cast<const VkBaseInStructure*>(pSubmits + i)))
            {
                break;
            }

            for (uint32_t j = 0; j < pSubmits[i].commandBufferInfoCount; ++j)
            {
                auto cmd_buffer_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(
                    pSubmits[i].pCommandBufferInfos[j].commandBuffer);
                if (CheckCommandBufferWrapperForFrameBoundary(current_lock, cmd_buffer_wrapper))
                {
                    break;
                }
            }
        }
    }

    void PostProcess_vkUpdateDescriptorSets(VkDevice,
                                            uint32_t                    descriptorWriteCount,
                                            const VkWriteDescriptorSet* pDescriptorWrites,
                                            uint32_t                    descriptorCopyCount,
                                            const VkCopyDescriptorSet*  pDescriptorCopies)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackUpdateDescriptorSets(
                descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
        }
    }

    void PostProcess_vkUpdateDescriptorSetWithTemplate(VkDevice,
                                                       VkDescriptorSet            descriptorSet,
                                                       VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                       const void*                pData)
    {
        if (IsCaptureModeTrack())
        {
            TrackUpdateDescriptorSetWithTemplate(descriptorSet, descriptorUpdateTemplate, pData);
        }
    }

    void PostProcess_vkUpdateDescriptorSetWithTemplateKHR(VkDevice,
                                                          VkDescriptorSet            descriptorSet,
                                                          VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                          const void*                pData)
    {
        if (IsCaptureModeTrack())
        {
            TrackUpdateDescriptorSetWithTemplate(descriptorSet, descriptorUpdateTemplate, pData);
        }
    }

    void PostProcess_vkCmdPushDescriptorSetKHR(VkCommandBuffer,
                                               VkPipelineBindPoint,
                                               VkPipelineLayout            layout,
                                               uint32_t                    set,
                                               uint32_t                    descriptorWriteCount,
                                               const VkWriteDescriptorSet* pDescriptorWrites)
    {
        GFXRECON_UNREFERENCED_PARAMETER(layout);
        GFXRECON_UNREFERENCED_PARAMETER(set);
        GFXRECON_UNREFERENCED_PARAMETER(descriptorWriteCount);
        GFXRECON_UNREFERENCED_PARAMETER(pDescriptorWrites);
        // TODO: Need to be able to map layout + set to a VkDescriptorSet handle.
    }

    void PostProcess_vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer,
                                                           VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                           VkPipelineLayout           layout,
                                                           uint32_t                   set,
                                                           const void*                pData)
    {
        GFXRECON_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
        GFXRECON_UNREFERENCED_PARAMETER(layout);
        GFXRECON_UNREFERENCED_PARAMETER(set);
        GFXRECON_UNREFERENCED_PARAMETER(pData);
        // TODO: Need to be able to map layout + set to a VkDescriptorSet handle.
    }

    void PostProcess_vkCmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer,
                                                            const VkPushDescriptorSetWithTemplateInfoKHR* info)
    {
        GFXRECON_UNREFERENCED_PARAMETER(info);
        // TODO: Need to be able to map layout + set to a VkDescriptorSet handle.
    }

    void PostProcess_vkResetDescriptorPool(VkResult result,
                                           VkDevice,
                                           VkDescriptorPool descriptorPool,
                                           VkDescriptorPoolResetFlags)
    {
        if (result == VK_SUCCESS)
        {
            if (IsCaptureModeTrack())
            {
                assert(state_tracker_ != nullptr);
                state_tracker_->TrackResetDescriptorPool(descriptorPool);
            }

            vulkan_wrappers::ResetDescriptorPoolWrapper(descriptorPool);
        }
    }

    void PostProcess_vkCmdBeginQuery(VkCommandBuffer     commandBuffer,
                                     VkQueryPool         queryPool,
                                     uint32_t            query,
                                     VkQueryControlFlags flags)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackQueryActivation(
                commandBuffer, queryPool, query, flags, vulkan_state_info::QueryInfo::kInvalidIndex);
        }
    }

    void PostProcess_vkCmdBeginQueryIndexedEXT(
        VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackQueryActivation(commandBuffer, queryPool, query, flags, index);
        }
    }

    void PostProcess_vkCmdWriteTimestamp(VkCommandBuffer         commandBuffer,
                                         VkPipelineStageFlagBits pipelineStage,
                                         VkQueryPool             queryPool,
                                         uint32_t                query)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackQueryActivation(
                commandBuffer, queryPool, query, 0, vulkan_state_info::QueryInfo::kInvalidIndex);
        }
    }

    void PostProcess_vkCmdWriteTimestamp2(VkCommandBuffer          commandBuffer,
                                          VkPipelineStageFlagBits2 pipelineStage,
                                          VkQueryPool              queryPool,
                                          uint32_t                 query)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackQueryActivation(
                commandBuffer, queryPool, query, 0, vulkan_state_info::QueryInfo::kInvalidIndex);
        }
    }

    void
    PostProcess_vkCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer,
                                                             uint32_t        accelerationStructureCount,
                                                             const VkAccelerationStructureNV* pAccelerationStructures,
                                                             VkQueryType                      queryType,
                                                             VkQueryPool                      queryPool,
                                                             uint32_t                         firstQuery)
    {
        GFXRECON_UNREFERENCED_PARAMETER(commandBuffer);
        GFXRECON_UNREFERENCED_PARAMETER(accelerationStructureCount);
        GFXRECON_UNREFERENCED_PARAMETER(pAccelerationStructures);
        GFXRECON_UNREFERENCED_PARAMETER(queryType);
        GFXRECON_UNREFERENCED_PARAMETER(queryPool);
        GFXRECON_UNREFERENCED_PARAMETER(firstQuery);
        // TODO
    }

    void PostProcess_vkCmdResetQueryPool(VkCommandBuffer commandBuffer,
                                         VkQueryPool     queryPool,
                                         uint32_t        firstQuery,
                                         uint32_t        queryCount)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackQueryReset(commandBuffer, queryPool, firstQuery, queryCount);
        }
    }

    void PostProcess_vkResetQueryPool(VkDevice, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackQueryReset(queryPool, firstQuery, queryCount);
        }
    }

    void PostProcess_vkMapMemory(VkResult         result,
                                 VkDevice         device,
                                 VkDeviceMemory   memory,
                                 VkDeviceSize     offset,
                                 VkDeviceSize     size,
                                 VkMemoryMapFlags flags,
                                 void**           ppData);

    void PostProcess_vkAcquireFullScreenExclusiveModeEXT(VkResult result, VkDevice device, VkSwapchainKHR swapchain);

    void PostProcess_vkGetPhysicalDeviceSurfacePresentModes2EXT(VkResult                               result,
                                                                VkPhysicalDevice                       physicalDevice,
                                                                const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                uint32_t*         pPresentModeCount,
                                                                VkPresentModeKHR* pPresentModes);

    void PostProcess_vkReleaseFullScreenExclusiveModeEXT(VkResult result, VkDevice device, VkSwapchainKHR swapchain);

    void PostProcess_vkGetDeviceGroupSurfacePresentModesKHR(VkResult                          result,
                                                            VkDevice                          device,
                                                            VkSurfaceKHR                      surface,
                                                            VkDeviceGroupPresentModeFlagsKHR* pModes);

    void PostProcess_vkGetDeviceGroupSurfacePresentModes2EXT(VkResult                               result,
                                                             VkDevice                               device,
                                                             const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                             VkDeviceGroupPresentModeFlagsKHR*      pModes);

    void PreProcess_vkFlushMappedMemoryRanges(VkDevice                   device,
                                              uint32_t                   memoryRangeCount,
                                              const VkMappedMemoryRange* pMemoryRanges);

    void PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory);

    void PreProcess_vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);

    void PostProcess_vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);

    void PreProcess_vkQueueSubmit(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                  VkQueue                                                queue,
                                  uint32_t                                               submitCount,
                                  const VkSubmitInfo*                                    pSubmits,
                                  VkFence                                                fence);

    void PreProcess_vkQueueSubmit2(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                   VkQueue                                                queue,
                                   uint32_t                                               submitCount,
                                   const VkSubmitInfo2*                                   pSubmits,
                                   VkFence                                                fence);

    void PostProcess_vkCreateDescriptorUpdateTemplate(VkResult                                    result,
                                                      VkDevice                                    device,
                                                      const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks*                pAllocator,
                                                      VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

    void PostProcess_vkCreateDescriptorUpdateTemplateKHR(VkResult                                    result,
                                                         VkDevice                                    device,
                                                         const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                         const VkAllocationCallbacks*                pAllocator,
                                                         VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

    void PostProcess_vkGetBufferDeviceAddress(VkDeviceAddress                  result,
                                              VkDevice                         device,
                                              const VkBufferDeviceAddressInfo* pInfo);

    void PreProcess_vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

    void PreProcess_vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice                                      device,
                                                          const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);

    void
    PreProcess_vkGetAccelerationStructureDeviceAddressKHR(VkDevice                                           device,
                                                          const VkAccelerationStructureDeviceAddressInfoKHR* pInfo);

    void PreProcess_vkGetAndroidHardwareBufferPropertiesANDROID(VkDevice                                  device,
                                                                const struct AHardwareBuffer*             buffer,
                                                                VkAndroidHardwareBufferPropertiesANDROID* pProperties);

    void
    PreProcess_vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);

    void
    PreProcess_vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);

    void PreProcess_vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);

    void
    PreProcess_vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);

    void PreProcess_vkQueueBindSparse(VkQueue                 queue,
                                      uint32_t                bindInfoCount,
                                      const VkBindSparseInfo* pBindInfo,
                                      VkFence                 fence);

#if ENABLE_OPENXR_SUPPORT
    void PreProcess_vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
    void PreProcess_vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences);
    void PreProcess_vkGetFenceStatus(VkDevice device, VkFence fence);
    void PreProcess_vkWaitForFences(
        VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
#endif

    void PostProcess_vkResetFences(VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences);
    void PostProcess_vkWaitForFences(VkResult       result,
                                     VkDevice       device,
                                     uint32_t       fenceCount,
                                     const VkFence* pFences,
                                     VkBool32       waitAll,
                                     uint64_t       timeout);
    void PostProcess_vkGetFenceStatus(VkResult result, VkDevice device, VkFence fence);

    void PostProcess_vkSetPrivateData(VkResult          result,
                                      VkDevice          device,
                                      VkObjectType      objectType,
                                      uint64_t          objectHandle,
                                      VkPrivateDataSlot privateDataSlot,
                                      uint64_t          data);

    void PostProcess_vkSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable);

    void PostProcess_vkCmdDebugMarkerInsertEXT(VkCommandBuffer                   commandBuffer,
                                               const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

    void PostProcess_vkFrameBoundaryANDROID(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                            VkDevice                                               device,
                                            VkSemaphore                                            semaphore,
                                            VkImage                                                image)
    {
        if (!common_manager_->GetIgnoreFrameBoundaryAndroid())
        {
            EndFrame(current_lock);
        }
    }

    void PostProcess_vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer             commandBuffer,
                                                   const VkDebugUtilsLabelEXT* pLabelInfo);

    void PostProcess_vkCmdBindDescriptorSets(VkCommandBuffer        commandBuffer,
                                             VkPipelineBindPoint    pipelineBindPoint,
                                             VkPipelineLayout       layout,
                                             uint32_t               firstSet,
                                             uint32_t               descriptorSetCount,
                                             const VkDescriptorSet* pDescriptorSets,
                                             uint32_t               dynamicOffsetCount,
                                             const uint32_t*        pDynamicOffsets);

    void PostProcess_vkCmdBindDescriptorSets2KHR(VkCommandBuffer                    commandBuffer,
                                                 const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo);

    void PostProcess_vkCmdCopyBuffer(VkCommandBuffer     commandBuffer,
                                     VkBuffer            srcBuffer,
                                     VkBuffer            dstBuffer,
                                     uint32_t            regionCount,
                                     const VkBufferCopy* pRegions);

    void PostProcess_vkCmdCopyImage(VkCommandBuffer    commandBuffer,
                                    VkImage            srcImage,
                                    VkImageLayout      srcImageLayout,
                                    VkImage            dstImage,
                                    VkImageLayout      dstImageLayout,
                                    uint32_t           regionCount,
                                    const VkImageCopy* pRegions);

    void PostProcess_vkCmdCopyBufferToImage(VkCommandBuffer          commandBuffer,
                                            VkBuffer                 srcBuffer,
                                            VkImage                  dstImage,
                                            VkImageLayout            dstImageLayout,
                                            uint32_t                 regionCount,
                                            const VkBufferImageCopy* pRegions);

    void PostProcess_vkCmdCopyImageToBuffer(VkCommandBuffer          commandBuffer,
                                            VkImage                  srcImage,
                                            VkImageLayout            srcImageLayout,
                                            VkBuffer                 dstBuffer,
                                            uint32_t                 regionCount,
                                            const VkBufferImageCopy* pRegions);

    void PostProcess_vkCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

    void PostProcess_vkCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

    void PostProcess_vkCmdCopyBufferToImage2(VkCommandBuffer                 commandBuffer,
                                             const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

    void PostProcess_vkCmdCopyImageToBuffer2(VkCommandBuffer                 commandBuffer,
                                             const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

    void PostProcess_vkCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

    void PostProcess_vkCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

    void PostProcess_vkCmdCopyBufferToImage2KHR(VkCommandBuffer                 commandBuffer,
                                                const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

    void PostProcess_vkCmdCopyImageToBuffer2KHR(VkCommandBuffer                 commandBuffer,
                                                const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

    void PostProcess_vkCmdBlitImage(VkCommandBuffer    commandBuffer,
                                    VkImage            srcImage,
                                    VkImageLayout      srcImageLayout,
                                    VkImage            dstImage,
                                    VkImageLayout      dstImageLayout,
                                    uint32_t           regionCount,
                                    const VkImageBlit* pRegions,
                                    VkFilter           filter);

    void PostProcess_vkCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

    void PostProcess_vkCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

    void PostProcess_vkCmdUpdateBuffer(VkCommandBuffer commandBuffer,
                                       VkBuffer        dstBuffer,
                                       VkDeviceSize    dstOffset,
                                       VkDeviceSize    dataSize,
                                       const void*     pData);

    void PostProcess_vkCmdFillBuffer(
        VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);

    void PostProcess_vkCmdClearColorImage(VkCommandBuffer                commandBuffer,
                                          VkImage                        image,
                                          VkImageLayout                  imageLayout,
                                          const VkClearColorValue*       pColor,
                                          uint32_t                       rangeCount,
                                          const VkImageSubresourceRange* pRanges);

    void PostProcess_vkCmdClearDepthStencilImage(VkCommandBuffer                 commandBuffer,
                                                 VkImage                         image,
                                                 VkImageLayout                   imageLayout,
                                                 const VkClearDepthStencilValue* pDepthStencil,
                                                 uint32_t                        rangeCount,
                                                 const VkImageSubresourceRange*  pRanges);

    void PostProcess_vkCmdBindPipeline(VkCommandBuffer     commandBuffer,
                                       VkPipelineBindPoint pipelineBindPoint,
                                       VkPipeline          pipeline);

    void PostProcess_vkCmdDraw(VkCommandBuffer commandBuffer,
                               uint32_t        vertexCount,
                               uint32_t        instanceCount,
                               uint32_t        firstVertex,
                               uint32_t        firstInstance);

    void PostProcess_vkCmdDrawIndexed(VkCommandBuffer commandBuffer,
                                      uint32_t        indexCount,
                                      uint32_t        instanceCount,
                                      uint32_t        firstIndex,
                                      int32_t         vertexOffset,
                                      uint32_t        firstInstance);

    void PostProcess_vkCmdDrawIndirect(
        VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

    void PostProcess_vkCmdDrawIndexedIndirect(
        VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

    void PostProcess_vkCmdDrawIndirectCount(VkCommandBuffer commandBuffer,
                                            VkBuffer        buffer,
                                            VkDeviceSize    offset,
                                            VkBuffer        countBuffer,
                                            VkDeviceSize    countBufferOffset,
                                            uint32_t        maxDrawCount,
                                            uint32_t        stride);

    void PostProcess_vkCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer,
                                                   VkBuffer        buffer,
                                                   VkDeviceSize    offset,
                                                   VkBuffer        countBuffer,
                                                   VkDeviceSize    countBufferOffset,
                                                   uint32_t        maxDrawCount,
                                                   uint32_t        stride);

    void PostProcess_vkCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer,
                                               VkBuffer        buffer,
                                               VkDeviceSize    offset,
                                               VkBuffer        countBuffer,
                                               VkDeviceSize    countBufferOffset,
                                               uint32_t        maxDrawCount,
                                               uint32_t        stride);

    void PostProcess_vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer,
                                                      VkBuffer        buffer,
                                                      VkDeviceSize    offset,
                                                      VkBuffer        countBuffer,
                                                      VkDeviceSize    countBufferOffset,
                                                      uint32_t        maxDrawCount,
                                                      uint32_t        stride);

    void PostProcess_vkCmdDispatch(VkCommandBuffer commandBuffer,
                                   uint32_t        groupCountX,
                                   uint32_t        groupCountY,
                                   uint32_t        groupCountZ);

    void PostProcess_vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

    void PostProcess_vkCmdDispatchBase(VkCommandBuffer commandBuffer,
                                       uint32_t        baseGroupX,
                                       uint32_t        baseGroupY,
                                       uint32_t        baseGroupZ,
                                       uint32_t        groupCountX,
                                       uint32_t        groupCountY,
                                       uint32_t        groupCountZ);

    void PostProcess_vkCmdDispatchBaseKHR(VkCommandBuffer commandBuffer,
                                          uint32_t        baseGroupX,
                                          uint32_t        baseGroupY,
                                          uint32_t        baseGroupZ,
                                          uint32_t        groupCountX,
                                          uint32_t        groupCountY,
                                          uint32_t        groupCountZ);

    void PostProcess_vkCmdTraceRaysNV(VkCommandBuffer commandBuffer,
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

    void PostProcess_vkCmdTraceRaysKHR(VkCommandBuffer                        commandBuffer,
                                       const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                       const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                       const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                       const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                       uint32_t                               width,
                                       uint32_t                               height,
                                       uint32_t                               depth);

    void PostProcess_vkCmdTraceRaysIndirectKHR(VkCommandBuffer                        commandBuffer,
                                               const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                               VkDeviceAddress                        indirectDeviceAddress);

    void PostProcess_vkCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);

    void PostProcess_vkCmdResolveImage(VkCommandBuffer       commandBuffer,
                                       VkImage               srcImage,
                                       VkImageLayout         srcImageLayout,
                                       VkImage               dstImage,
                                       VkImageLayout         dstImageLayout,
                                       uint32_t              regionCount,
                                       const VkImageResolve* pRegions);

    void PostProcess_vkCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

    void PostProcess_vkCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

    void PostProcess_vkCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);

    void PostProcess_vkCmdDrawMeshTasksIndirectNV(
        VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

    void PostProcess_vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer,
                                                       VkBuffer        buffer,
                                                       VkDeviceSize    offset,
                                                       VkBuffer        countBuffer,
                                                       VkDeviceSize    countBufferOffset,
                                                       uint32_t        maxDrawCount,
                                                       uint32_t        stride);

    void PostProcess_vkCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer,
                                           uint32_t        groupCountX,
                                           uint32_t        groupCountY,
                                           uint32_t        groupCountZ);

    void PostProcess_vkCmdDrawMeshTasksIndirectEXT(
        VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

    void PostProcess_vkCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer,
                                                        VkBuffer        buffer,
                                                        VkDeviceSize    offset,
                                                        VkBuffer        countBuffer,
                                                        VkDeviceSize    countBufferOffset,
                                                        uint32_t        maxDrawCount,
                                                        uint32_t        stride);

    void PostProcess_vkCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

    void PostProcess_vkSetDebugUtilsObjectNameEXT(VkResult                             result,
                                                  VkDevice                             device,
                                                  const VkDebugUtilsObjectNameInfoEXT* pNameInfo);

    void PostProcess_vkSetDebugUtilsObjectTagEXT(VkResult                            result,
                                                 VkDevice                            device,
                                                 const VkDebugUtilsObjectTagInfoEXT* pTagInfo);

#if ENABLE_OPENXR_SUPPORT
    void PostProcess_vkCreateFence(VkResult                     result,
                                   VkDevice                     device,
                                   const VkFenceCreateInfo*     pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator,
                                   VkFence*                     pFence);
    void PostProcess_vkImportFenceWin32HandleKHR(VkResult                               result,
                                                 VkDevice                               device,
                                                 const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo);
    void
    PostProcess_vkImportFenceFdKHR(VkResult result, VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo);

    void AddValidFence(VkFence fence);
    void RemoveValidFence(VkFence fence);
    bool IsValidFence(VkFence fence);
#endif

#if defined(__ANDROID__)
    void OverrideGetPhysicalDeviceSurfacePresentModesKHR(uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
#endif

  protected:
    VulkanCaptureManager() : ApiCaptureManager(format::ApiFamilyId::ApiFamily_Vulkan) {}

    virtual ~VulkanCaptureManager() {}

    virtual void CreateStateTracker() override
    {
        state_tracker_ = std::make_unique<VulkanStateTracker>();
    }

    virtual void DestroyStateTracker() override
    {
        state_tracker_ = nullptr;
    }

    virtual void WriteTrackedState(util::FileOutputStream* file_stream, util::ThreadData* thread_data) override;

    virtual void WriteTrackedStateWithAssetFile(util::FileOutputStream* file_stream,
                                                util::ThreadData*       thread_data,
                                                util::FileOutputStream* asset_file_stream,
                                                const std::string*      asset_file_name) override;

    virtual void WriteAssets(util::FileOutputStream* asset_file_stream,
                             const std::string*      asset_file_name,
                             util::ThreadData*       thread_data) override;

    CaptureSettings::TraceSettings GetDefaultTraceSettings() override
    {
        return layer_settings_;
    }

  private:
    struct HardwareBufferInfo
    {
        format::HandleId      memory_id;
        std::atomic<uint32_t> reference_count;
    };

    typedef std::unordered_map<AHardwareBuffer*, HardwareBufferInfo> HardwareBufferMap;

  private:
    void WriteResizeWindowCmd2(format::HandleId              surface_id,
                               uint32_t                      width,
                               uint32_t                      height,
                               VkSurfaceTransformFlagBitsKHR pre_transform);
    void WriteDestroyHardwareBufferCmd(AHardwareBuffer* buffer);
    void WriteSetDevicePropertiesCommand(format::HandleId                  physical_device_id,
                                         const VkPhysicalDeviceProperties& properties);
    void WriteSetDeviceMemoryPropertiesCommand(format::HandleId                        physical_device_id,
                                               const VkPhysicalDeviceMemoryProperties& memory_properties);
    void WriteSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, uint64_t address);

    void WriteSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                     format::HandleId pipeline_id,
                                                     size_t           data_size,
                                                     const void*      data);

    void SetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate                  update_template,
                                         const VkDescriptorUpdateTemplateCreateInfo* create_info);

    void TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet            set,
                                              VkDescriptorUpdateTemplate update_templat,
                                              const void*                data);

    void
    ProcessEnumeratePhysicalDevices(VkResult result, VkInstance instance, uint32_t count, VkPhysicalDevice* devices);

    VkMemoryPropertyFlags GetMemoryProperties(vulkan_wrappers::DeviceWrapper* device_wrapper,
                                              uint32_t                        memory_type_index);

    void ProcessHardwareBuffer(format::ThreadId thread_id, AHardwareBuffer* hardware_buffer, VkDevice device);
    void ProcessImportAndroidHardwareBuffer(VkDevice device, VkDeviceMemory memory, AHardwareBuffer* hardware_buffer);
    void ReleaseAndroidHardwareBuffer(AHardwareBuffer* hardware_buffer);
    bool CheckBindAlignment(VkDeviceSize memoryOffset);

    bool CheckCommandBufferWrapperForFrameBoundary(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                                   const vulkan_wrappers::CommandBufferWrapper* command_buffer_wrapper);

    bool CheckPNextChainForFrameBoundary(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                         const VkBaseInStructure*                               current);

  private:
    void QueueSubmitWriteFillMemoryCmd();

    static std::mutex                               instance_lock_;
    static VulkanCaptureManager*                    singleton_;
    static graphics::VulkanLayerTable               vulkan_layer_table_;
    std::set<vulkan_wrappers::DeviceMemoryWrapper*> mapped_memory_; // Track mapped memory for unassisted tracking mode.
    std::unique_ptr<VulkanStateTracker>             state_tracker_;
    HardwareBufferMap                               hardware_buffers_;
    std::mutex                                      deferred_operation_mutex;

    // In default mode, the capture manager uses a shared mutex to capture every API function. As a result,
    // multiple threads may access the sparse resource maps concurrently. Therefore, we use a dedicated mutex
    // for write access to these maps.
    std::mutex sparse_resource_mutex;

#if ENABLE_OPENXR_SUPPORT
    std::mutex        fence_mutex;
    std::set<VkFence> valid_fences_;
#endif

    CaptureSettings::TraceSettings layer_settings_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_CAPTURE_MANAGER_H
