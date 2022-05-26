/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
** Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/capture_manager.h"

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

#include <atomic>
#include <cassert>
#include <memory>
#include <mutex>
#include <set>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanCaptureManager : public CaptureManager
{
  public:
    static VulkanCaptureManager* Get() { return instance_; }

    // Creates the capture manager instance if none exists, or increments a reference count if an instance already
    // exists.
    static bool CreateInstance();

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

    static const LayerTable* GetLayerTable() { return &layer_table_; }

    void InitVkInstance(VkInstance* instance, PFN_vkGetInstanceProcAddr gpa);

    void InitVkDevice(VkDevice* device, PFN_vkGetDeviceProcAddr gpa);

    // Single object creation.
    template <typename ParentHandle, typename Wrapper, typename CreateInfo>
    void EndCreateApiCallCapture(VkResult                      result,
                                 ParentHandle                  parent_handle,
                                 typename Wrapper::HandleType* handle,
                                 const CreateInfo*             create_info)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && result == VK_SUCCESS)
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
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS) && (handles != nullptr))
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
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && ((result == VK_SUCCESS) || (result == VK_INCOMPLETE)) &&
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
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && ((result == VK_SUCCESS) || (result == VK_INCOMPLETE)) &&
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
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
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
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (handles != nullptr))
        {
            assert(state_tracker_ != nullptr);

            for (uint32_t i = 0; i < count; ++i)
            {
                state_tracker_->RemoveEntry<Wrapper>(handles[i]);
            }
        }

        EndApiCallCapture();
    }

    void EndCommandApiCallCapture(VkCommandBuffer command_buffer)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->TrackCommand(command_buffer, thread_data->call_id_, thread_data->parameter_buffer_.get());
        }

        EndApiCallCapture();
    }

    template <typename GetHandlesFunc, typename... GetHandlesArgs>
    void EndCommandApiCallCapture(VkCommandBuffer command_buffer, GetHandlesFunc func, GetHandlesArgs... args)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->TrackCommand(
                command_buffer, thread_data->call_id_, thread_data->parameter_buffer_.get(), func, args...);
        }

        EndApiCallCapture();
    }

    bool GetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate update_template,
                                         const UpdateTemplateInfo** info) const;

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

    VkResult OverrideCreateAccelerationStructureKHR(VkDevice                                    device,
                                                    const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
                                                    const VkAllocationCallbacks*                pAllocator,
                                                    VkAccelerationStructureKHR* pAccelerationStructureKHR);

    VkResult OverrideAllocateMemory(VkDevice                     device,
                                    const VkMemoryAllocateInfo*  pAllocateInfo,
                                    const VkAllocationCallbacks* pAllocator,
                                    VkDeviceMemory*              pMemory);

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
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (pQueueFamilyPropertyCount != nullptr) &&
            (pQueueFamilyProperties != nullptr))
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
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (pQueueFamilyPropertyCount != nullptr) &&
            (pQueueFamilyProperties != nullptr))
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
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS) && (pSupported != nullptr))
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
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS) &&
            (pSurfaceCapabilities != nullptr))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceSurfaceCapabilities(physicalDevice, surface, *pSurfaceCapabilities);
        }
    }

    void PostProcess_vkGetPhysicalDeviceSurfaceFormatsKHR(VkResult            result,
                                                          VkPhysicalDevice    physicalDevice,
                                                          VkSurfaceKHR        surface,
                                                          uint32_t*           pSurfaceFormatCount,
                                                          VkSurfaceFormatKHR* pSurfaceFormats)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS) &&
            (pSurfaceFormatCount != nullptr) && (pSurfaceFormats != nullptr))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceSurfaceFormats(
                physicalDevice, surface, *pSurfaceFormatCount, pSurfaceFormats);
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
            if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
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

    void PreProcess_vkCreateSwapchain(VkDevice                        device,
                                      const VkSwapchainCreateInfoKHR* pCreateInfo,
                                      const VkAllocationCallbacks*    pAllocator,
                                      VkSwapchainKHR*                 pSwapchain);

    void PostProcess_vkAcquireNextImageKHR(VkResult result,
                                           VkDevice,
                                           VkSwapchainKHR swapchain,
                                           uint64_t,
                                           VkSemaphore semaphore,
                                           VkFence     fence,
                                           uint32_t*   index)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) &&
            ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR)))
        {
            assert((state_tracker_ != nullptr) && (index != nullptr));
            state_tracker_->TrackSemaphoreSignalState(semaphore);
            state_tracker_->TrackAcquireImage(*index, swapchain, semaphore, fence, 0);
        }
    }

    void PostProcess_vkAcquireNextImage2KHR(VkResult result,
                                            VkDevice,
                                            const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                            uint32_t*                        index)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) &&
            ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR)))
        {
            assert((state_tracker_ != nullptr) && (pAcquireInfo != nullptr) && (index != nullptr));
            state_tracker_->TrackSemaphoreSignalState(pAcquireInfo->semaphore);
            state_tracker_->TrackAcquireImage(*index,
                                              pAcquireInfo->swapchain,
                                              pAcquireInfo->semaphore,
                                              pAcquireInfo->fence,
                                              pAcquireInfo->deviceMask);
        }
    }

    void PostProcess_vkQueuePresentKHR(VkResult result, VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) &&
            ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR)))
        {
            assert((state_tracker_ != nullptr) && (pPresentInfo != nullptr));
            state_tracker_->TrackSemaphoreSignalState(
                pPresentInfo->waitSemaphoreCount, pPresentInfo->pWaitSemaphores, 0, nullptr);
            state_tracker_->TrackPresentedImages(
                pPresentInfo->swapchainCount, pPresentInfo->pSwapchains, pPresentInfo->pImageIndices, queue);
        }

        EndFrame();
    }

    void PostProcess_vkQueueBindSparse(
        VkResult result, VkQueue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert((state_tracker_ != nullptr) && ((bindInfoCount == 0) || (pBindInfo != nullptr)));
            for (uint32_t i = 0; i < bindInfoCount; ++i)
            {
                state_tracker_->TrackSemaphoreSignalState(pBindInfo[i].waitSemaphoreCount,
                                                          pBindInfo[i].pWaitSemaphores,
                                                          pBindInfo[i].signalSemaphoreCount,
                                                          pBindInfo[i].pSignalSemaphores);
            }
        }
    }

    void PostProcess_vkGetBufferMemoryRequirements(VkDevice              device,
                                                   VkBuffer              buffer,
                                                   VkMemoryRequirements* pMemoryRequirements)
    {
        GFXRECON_UNREFERENCED_PARAMETER(device);
        GFXRECON_UNREFERENCED_PARAMETER(buffer);

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard) &&
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

        if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard) &&
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

    void PostProcess_vkBindBufferMemory(
        VkResult result, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackBufferMemoryBinding(device, buffer, memory, memoryOffset);
        }
    }

    void PostProcess_vkBindBufferMemory2(VkResult                      result,
                                         VkDevice                      device,
                                         uint32_t                      bindInfoCount,
                                         const VkBindBufferMemoryInfo* pBindInfos)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS) && (pBindInfos != nullptr))
        {
            assert(state_tracker_ != nullptr);

            for (uint32_t i = 0; i < bindInfoCount; ++i)
            {
                state_tracker_->TrackBufferMemoryBinding(device,
                                                         pBindInfos[i].buffer,
                                                         pBindInfos[i].memory,
                                                         pBindInfos[i].memoryOffset,
                                                         pBindInfos[i].pNext);
            }
        }
    }

    void PostProcess_vkBindImageMemory(
        VkResult result, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackImageMemoryBinding(device, image, memory, memoryOffset);
        }
    }

    void PostProcess_vkBindImageMemory2(VkResult                     result,
                                        VkDevice                     device,
                                        uint32_t                     bindInfoCount,
                                        const VkBindImageMemoryInfo* pBindInfos)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS) && (pBindInfos != nullptr))
        {
            assert(state_tracker_ != nullptr);

            for (uint32_t i = 0; i < bindInfoCount; ++i)
            {
                state_tracker_->TrackImageMemoryBinding(
                    device, pBindInfos[i].image, pBindInfos[i].memory, pBindInfos[i].memoryOffset, pBindInfos[i].pNext);
            }
        }
    }

    void PostProcess_vkCmdBeginRenderPass(VkCommandBuffer              commandBuffer,
                                          const VkRenderPassBeginInfo* pRenderPassBegin,
                                          VkSubpassContents)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackBeginRenderPass(commandBuffer, pRenderPassBegin);
        }
    }

    void PostProcess_vkCmdBeginRenderPass2(VkCommandBuffer              commandBuffer,
                                           const VkRenderPassBeginInfo* pRenderPassBegin,
                                           const VkSubpassBeginInfoKHR*)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackBeginRenderPass(commandBuffer, pRenderPassBegin);
        }
    }

    void PostProcess_vkCmdEndRenderPass(VkCommandBuffer commandBuffer)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackEndRenderPass(commandBuffer);
        }
    }

    void PostProcess_vkCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfoKHR*)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
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
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackImageBarriers(commandBuffer, imageMemoryBarrierCount, pImageMemoryBarriers);
        }
    }

    void PostProcess_vkCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfoKHR* pDependencyInfo)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
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
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
        }
    }

    void PostProcess_vkResetCommandPool(VkResult result, VkDevice, VkCommandPool commandPool, VkCommandPoolResetFlags)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackResetCommandPool(commandPool);
        }
    }

    void
    PostProcess_vkQueueSubmit(VkResult result, VkQueue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
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
    }

    void PostProcess_vkQueueSubmit2(
        VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence)
    {
        if (((GetCaptureMode() & kModeTrack) == kModeTrack) && (result == VK_SUCCESS))
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
    }

    void PostProcess_vkUpdateDescriptorSets(VkDevice,
                                            uint32_t                    descriptorWriteCount,
                                            const VkWriteDescriptorSet* pDescriptorWrites,
                                            uint32_t                    descriptorCopyCount,
                                            const VkCopyDescriptorSet*  pDescriptorCopies)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
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
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            TrackUpdateDescriptorSetWithTemplate(descriptorSet, descriptorUpdateTemplate, pData);
        }
    }

    void PostProcess_vkUpdateDescriptorSetWithTemplateKHR(VkDevice,
                                                          VkDescriptorSet            descriptorSet,
                                                          VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                          const void*                pData)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
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

    void PostProcess_vkResetDescriptorPool(VkResult result,
                                           VkDevice,
                                           VkDescriptorPool descriptorPool,
                                           VkDescriptorPoolResetFlags)
    {
        if (result == VK_SUCCESS)
        {
            if ((GetCaptureMode() & kModeTrack) == kModeTrack)
            {
                assert(state_tracker_ != nullptr);
                state_tracker_->TrackResetDescriptorPool(descriptorPool);
            }

            ResetDescriptorPoolWrapper(descriptorPool);
        }
    }

    void PostProcess_vkCmdBeginQuery(VkCommandBuffer     commandBuffer,
                                     VkQueryPool         queryPool,
                                     uint32_t            query,
                                     VkQueryControlFlags flags)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackQueryActivation(commandBuffer, queryPool, query, flags, QueryInfo::kInvalidIndex);
        }
    }

    void PostProcess_vkCmdBeginQueryIndexedEXT(
        VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
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
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackQueryActivation(commandBuffer, queryPool, query, 0, QueryInfo::kInvalidIndex);
        }
    }

    void PostProcess_vkCmdWriteTimestamp2(VkCommandBuffer          commandBuffer,
                                          VkPipelineStageFlagBits2 pipelineStage,
                                          VkQueryPool              queryPool,
                                          uint32_t                 query)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackQueryActivation(commandBuffer, queryPool, query, 0, QueryInfo::kInvalidIndex);
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
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackQueryReset(commandBuffer, queryPool, firstQuery, queryCount);
        }
    }

    void PostProcess_vkResetQueryPool(VkDevice, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
    {
        if ((GetCaptureMode() & kModeTrack) == kModeTrack)
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

    void PostProcess_vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkResult                               result,
                                                                VkPhysicalDevice                       physicalDevice,
                                                                const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                VkSurfaceCapabilities2KHR* pSurfaceCapabilities);

    void PreProcess_vkFlushMappedMemoryRanges(VkDevice                   device,
                                              uint32_t                   memoryRangeCount,
                                              const VkMappedMemoryRange* pMemoryRanges);

    void PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory);

    void PreProcess_vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);

    void PostProcess_vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);

    void PreProcess_vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);

    void PreProcess_vkQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);

    void PreProcess_vkCreateDescriptorUpdateTemplate(VkResult                                    result,
                                                     VkDevice                                    device,
                                                     const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks*                pAllocator,
                                                     VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

    void PreProcess_vkCreateDescriptorUpdateTemplateKHR(VkResult                                    result,
                                                        VkDevice                                    device,
                                                        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                        const VkAllocationCallbacks*                pAllocator,
                                                        VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

    void PreProcess_vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

    void PreProcess_vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

    void PreProcess_vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice                                      device,
                                                          const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);

    void
    PreProcess_vkGetAccelerationStructureDeviceAddressKHR(VkDevice                                           device,
                                                          const VkAccelerationStructureDeviceAddressInfoKHR* pInfo);

    void PreProcess_vkGetRayTracingShaderGroupHandlesKHR(
        VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);

    void PreProcess_vkGetAndroidHardwareBufferPropertiesANDROID(VkDevice                                  device,
                                                                const struct AHardwareBuffer*             buffer,
                                                                VkAndroidHardwareBufferPropertiesANDROID* pProperties);

#if defined(__ANDROID__)
    void OverrideGetPhysicalDeviceSurfacePresentModesKHR(uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
#endif

  protected:
    VulkanCaptureManager() : CaptureManager(format::ApiFamilyId::ApiFamily_Vulkan) {}

    virtual ~VulkanCaptureManager() override {}

    virtual void CreateStateTracker() override { state_tracker_ = std::make_unique<VulkanStateTracker>(); }

    virtual void DestroyStateTracker() override { state_tracker_ = nullptr; }

    virtual void WriteTrackedState(util::FileOutputStream* file_stream, format::ThreadId thread_id) override;

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
    void WriteCreateHardwareBufferCmd(format::HandleId                                    memory_id,
                                      AHardwareBuffer*                                    buffer,
                                      const std::vector<format::HardwareBufferPlaneInfo>& plane_info);
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

    VkMemoryPropertyFlags GetMemoryProperties(DeviceWrapper* device_wrapper, uint32_t memory_type_index);

    const VkImportAndroidHardwareBufferInfoANDROID*
    FindAllocateMemoryExtensions(const VkMemoryAllocateInfo* allocate_info);

    bool ProcessReferenceToAndroidHardwareBuffer(VkDevice device, AHardwareBuffer* hardware_buffer);
    void ProcessImportAndroidHardwareBuffer(VkDevice device, VkDeviceMemory memory, AHardwareBuffer* hardware_buffer);
    void ReleaseAndroidHardwareBuffer(AHardwareBuffer* hardware_buffer);

  private:
    void QueueSubmitWriteFillMemoryCmd();

    static VulkanCaptureManager*        instance_;
    static LayerTable                   layer_table_;
    std::set<DeviceMemoryWrapper*>      mapped_memory_; // Track mapped memory for unassisted tracking mode.
    std::unique_ptr<VulkanStateTracker> state_tracker_;
    HardwareBufferMap                   hardware_buffers_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_CAPTURE_MANAGER_H
