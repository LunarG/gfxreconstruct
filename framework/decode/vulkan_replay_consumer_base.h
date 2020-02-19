/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H

#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/swapchain_image_tracker.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_object_info_table.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_resource_initializer.h"
#include "decode/window.h"
#include "format/api_call_id.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <vector>

// Types provided by this file are defined by format/platform_types.h when VK_USE_PLATFORM_ANDROID_KHR is not set.
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/hardware_buffer.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayConsumerBase : public VulkanConsumer
{
  public:
    VulkanReplayConsumerBase(WindowFactory* window_factory, const ReplayOptions& options);

    virtual ~VulkanReplayConsumerBase() override;

    void SetFatalErrorHandler(std::function<void(const char*)> handler) { fatal_error_handler_ = handler; }

    virtual void ProcessStateBeginMarker(uint64_t frame_number) override;

    virtual void ProcessStateEndMarker(uint64_t frame_number) override;

    virtual void ProcessDisplayMessageCommand(const std::string& message) override;

    virtual void
    ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height) override;

    virtual void
    ProcessCreateHardwareBufferCommand(format::HandleId                                    memory_id,
                                       uint64_t                                            buffer_id,
                                       uint32_t                                            format,
                                       uint32_t                                            width,
                                       uint32_t                                            height,
                                       uint32_t                                            stride,
                                       uint32_t                                            usage,
                                       uint32_t                                            layers,
                                       const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override;

    virtual void ProcessDestroyHardwareBufferCommand(uint64_t buffer_id) override;

    virtual void
    ProcessSetDeviceMemoryPropertiesCommand(format::HandleId                             physical_device_id,
                                            uint32_t                                     memory_type_count,
                                            const std::vector<format::DeviceMemoryType>& memory_types,
                                            uint32_t                                     memory_heap_count,
                                            const std::vector<format::DeviceMemoryHeap>& memory_heaps) override;

    virtual void
    ProcessSetSwapchainImageStateCommand(format::HandleId                                    device_id,
                                         format::HandleId                                    swapchain_id,
                                         uint32_t                                            last_presented_image,
                                         const std::vector<format::SwapchainImageStateInfo>& image_info) override;

    virtual void ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                 uint64_t         max_resource_size,
                                                 uint64_t         max_copy_size) override;

    virtual void ProcessEndResourceInitCommand(format::HandleId device_id) override;

    virtual void ProcessInitBufferCommand(format::HandleId device_id,
                                          format::HandleId buffer_id,
                                          uint64_t         data_size,
                                          const uint8_t*   data) override;

    virtual void ProcessInitImageCommand(format::HandleId             device_id,
                                         format::HandleId             image_id,
                                         uint64_t                     data_size,
                                         uint32_t                     aspect,
                                         uint32_t                     layout,
                                         const std::vector<uint64_t>& level_sizes,
                                         const uint8_t*               data) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplate(format::HandleId device,
                                                           format::HandleId descriptorSet,
                                                           format::HandleId descriptorUpdateTemplate,
                                                           const DescriptorUpdateTemplateDecoder& pData) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(format::HandleId commandBuffer,
                                                               format::HandleId descriptorUpdateTemplate,
                                                               format::HandleId layout,
                                                               uint32_t         set,
                                                               const DescriptorUpdateTemplateDecoder& pData) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(format::HandleId device,
                                                              format::HandleId descriptorSet,
                                                              format::HandleId descriptorUpdateTemplate,
                                                              const DescriptorUpdateTemplateDecoder& pData) override;

    virtual void
    Process_vkRegisterObjectsNVX(VkResult                                                   returnValue,
                                 format::HandleId                                           device,
                                 format::HandleId                                           objectTable,
                                 uint32_t                                                   objectCount,
                                 const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& ppObjectTableEntries,
                                 const PointerDecoder<uint32_t>&                            pObjectIndices) override;

  protected:
    const VulkanObjectInfoTable& GetObjectInfoTable() const { return object_info_table_; }

    VulkanObjectInfoTable& GetObjectInfoTable() { return object_info_table_; }

    const encode::InstanceTable* GetInstanceTable(const void* handle) const;

    const encode::DeviceTable* GetDeviceTable(const void* handle) const;

    void* PreProcessExternalObject(uint64_t object_id, format::ApiCallId call_id, const char* call_name);

    void PostProcessExternalObject(
        VkResult replay_reslt, uint64_t object_id, void* object, format::ApiCallId call_id, const char* call_name);

    const VkAllocationCallbacks*
    GetAllocationCallbacks(const StructPointerDecoder<Decoded_VkAllocationCallbacks>& original_callbacks);

    void CheckResult(const char* func_name, VkResult original, VkResult replay);

    template <typename T>
    typename T::HandleType MapHandle(format::HandleId id,
                                     const T* (VulkanObjectInfoTable::*MapFunc)(format::HandleId) const) const
    {
        typename T::HandleType handle = VK_NULL_HANDLE;
        const T*               info   = (object_info_table_.*MapFunc)(id);

        if (info != nullptr)
        {
            handle = info->handle;
        }

        return handle;
    }

    template <typename T>
    void MapHandles(const format::HandleId* ids,
                    size_t                  ids_len,
                    typename T::HandleType* handles,
                    size_t                  handles_len,
                    const T* (VulkanObjectInfoTable::*MapFunc)(format::HandleId) const) const
    {
        if ((ids != nullptr) && (handles != nullptr))
        {
            // The array sizes are expected to be the same for mapping operations.
            assert(ids_len == handles_len);
            for (size_t i = 0; i < handles_len; ++i)
            {
                const T* info = (object_info_table_.*MapFunc)(ids[i]);

                if (info != nullptr)
                {
                    handles[i] = info->handle;
                }
                else
                {
                    handles[i] = VK_NULL_HANDLE;
                }
            }
        }
    }

    template <typename T>
    void AddHandle(const format::HandleId*       id,
                   const typename T::HandleType* handle,
                   T&&                           initial_info,
                   void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        if ((id != nullptr) && (handle != nullptr))
        {
            initial_info.handle     = *handle;
            initial_info.capture_id = *id;
            (object_info_table_.*AddFunc)(std::forward<T>(initial_info));
        }
    }

    template <typename T>
    void AddHandle(const format::HandleId*       id,
                   const typename T::HandleType* handle,
                   void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        if ((id != nullptr) && (handle != nullptr))
        {
            T info;
            info.handle     = (*handle);
            info.capture_id = (*id);
            (object_info_table_.*AddFunc)(std::move(info));
        }
    }

    template <typename T>
    void AddHandles(const format::HandleId*       ids,
                    size_t                        ids_len,
                    const typename T::HandleType* handles,
                    size_t                        handles_len,
                    std::vector<T>&&              initial_infos,
                    void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        if ((ids != nullptr) && (handles != nullptr))
        {
            size_t len = std::min(ids_len, handles_len);

            assert(len <= initial_infos.size());

            for (size_t i = 0; i < len; ++i)
            {
                auto info_iter        = std::next(initial_infos.begin(), i);
                info_iter->handle     = handles[i];
                info_iter->capture_id = ids[i];
                (object_info_table_.*AddFunc)(std::move(*info_iter));
            }
        }
    }

    template <typename T>
    void AddHandles(const format::HandleId*       ids,
                    size_t                        ids_len,
                    const typename T::HandleType* handles,
                    size_t                        handles_len,
                    void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        if ((ids != nullptr) && (handles != nullptr))
        {
            size_t len = std::min(ids_len, handles_len);
            for (size_t i = 0; i < len; ++i)
            {
                T info;
                info.handle     = handles[i];
                info.capture_id = ids[i];
                (object_info_table_.*AddFunc)(std::move(info));
            }
        }
    }

    //
    // Replay function overrides provided to the replay consumer code generator with replay_overrides.json
    //

    VkResult OverrideCreateInstance(VkResult                                                   original_result,
                                    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>&  pCreateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
                                    HandlePointerDecoder<VkInstance>*                          pInstance);

    VkResult OverrideCreateDevice(VkResult                                                   original_result,
                                  const PhysicalDeviceInfo*                                  physical_device_info,
                                  const StructPointerDecoder<Decoded_VkDeviceCreateInfo>&    pCreateInfo,
                                  const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
                                  HandlePointerDecoder<VkDevice>*                            pDevice);

    VkResult OverrideEnumeratePhysicalDevices(PFN_vkEnumeratePhysicalDevices          func,
                                              VkResult                                original_result,
                                              const InstanceInfo*                     instance_info,
                                              PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                              HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices);

    void OverrideGetPhysicalDeviceProperties(PFN_vkGetPhysicalDeviceProperties func,
                                             const PhysicalDeviceInfo*         physical_device_info,
                                             StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties);

    void OverrideGetPhysicalDeviceProperties2(PFN_vkGetPhysicalDeviceProperties2 func,
                                              const PhysicalDeviceInfo*          physical_device_info,
                                              StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties);

    void
    OverrideGetPhysicalDeviceProperties2KHR(PFN_vkGetPhysicalDeviceProperties2KHR func,
                                            const PhysicalDeviceInfo*             physical_device_info,
                                            StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2KHR>* pProperties);

    VkResult OverrideWaitForFences(PFN_vkWaitForFences                  func,
                                   VkResult                             original_result,
                                   const DeviceInfo*                    device_info,
                                   uint32_t                             fenceCount,
                                   const HandlePointerDecoder<VkFence>& pFences,
                                   VkBool32                             waitAll,
                                   uint64_t                             timeout);

    VkResult OverrideGetFenceStatus(PFN_vkGetFenceStatus func,
                                    VkResult             original_result,
                                    const DeviceInfo*    device_info,
                                    const FenceInfo*     fence_info);

    VkResult OverrideGetEventStatus(PFN_vkGetEventStatus func,
                                    VkResult             original_result,
                                    const DeviceInfo*    device_info,
                                    const EventInfo*     event_info);

    VkResult OverrideGetQueryPoolResults(PFN_vkGetQueryPoolResults func,
                                         VkResult                  original_result,
                                         const DeviceInfo*         device_info,
                                         const QueryPoolInfo*      query_pool_info,
                                         uint32_t                  firstQuery,
                                         uint32_t                  queryCount,
                                         size_t                    dataSize,
                                         PointerDecoder<uint8_t>*  pData,
                                         VkDeviceSize              stride,
                                         VkQueryResultFlags        flags);

    VkResult
    OverrideAllocateCommandBuffers(PFN_vkAllocateCommandBuffers                                     func,
                                   VkResult                                                         original_result,
                                   const DeviceInfo*                                                device_info,
                                   const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>& pAllocateInfo,
                                   HandlePointerDecoder<VkCommandBuffer>*                           pCommandBuffers);

    VkResult
    OverrideAllocateDescriptorSets(PFN_vkAllocateDescriptorSets                                     func,
                                   VkResult                                                         original_result,
                                   const DeviceInfo*                                                device_info,
                                   const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>& pAllocateInfo,
                                   HandlePointerDecoder<VkDescriptorSet>*                           pDescriptorSets);

    VkResult OverrideAllocateMemory(PFN_vkAllocateMemory                                       func,
                                    VkResult                                                   original_result,
                                    const DeviceInfo*                                          device_info,
                                    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>&  pAllocateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
                                    HandlePointerDecoder<VkDeviceMemory>*                      pMemory);

    VkResult OverrideMapMemory(PFN_vkMapMemory   func,
                               VkResult          original_result,
                               const DeviceInfo* device_info,
                               DeviceMemoryInfo* memory_info,
                               VkDeviceSize      offset,
                               VkDeviceSize      size,
                               VkMemoryMapFlags  flags,
                               void**            ppData);

    void OverrideUnmapMemory(PFN_vkUnmapMemory func, const DeviceInfo* device_info, DeviceMemoryInfo* memory_info);

    void OverrideFreeMemory(PFN_vkFreeMemory                                           func,
                            const DeviceInfo*                                          device_info,
                            const DeviceMemoryInfo*                                    memory_info,
                            const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator);

    VkResult OverrideBindBufferMemory(PFN_vkBindBufferMemory func,
                                      VkResult               original_result,
                                      const DeviceInfo*      device_info,
                                      BufferInfo*            buffer_info,
                                      DeviceMemoryInfo*      memory_info,
                                      VkDeviceSize           memoryOffset);

    VkResult OverrideBindBufferMemory2(PFN_vkBindBufferMemory2                                     func,
                                       VkResult                                                    original_result,
                                       const DeviceInfo*                                           device_info,
                                       uint32_t                                                    bindInfoCount,
                                       const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos);

    VkResult OverrideBindImageMemory(PFN_vkBindImageMemory func,
                                     VkResult              original_result,
                                     const DeviceInfo*     device_info,
                                     ImageInfo*            image_info,
                                     DeviceMemoryInfo*     memory_info,
                                     VkDeviceSize          memoryOffset);

    VkResult OverrideBindImageMemory2(PFN_vkBindImageMemory2                                     func,
                                      VkResult                                                   original_result,
                                      const DeviceInfo*                                          device_info,
                                      uint32_t                                                   bindInfoCount,
                                      const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos);

    VkResult OverrideCreateBuffer(PFN_vkCreateBuffer                                         func,
                                  VkResult                                                   original_result,
                                  const DeviceInfo*                                          device_info,
                                  const StructPointerDecoder<Decoded_VkBufferCreateInfo>&    pCreateInfo,
                                  const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
                                  HandlePointerDecoder<VkBuffer>*                            pBuffer);

    VkResult OverrideCreateImage(PFN_vkCreateImage                                          func,
                                 VkResult                                                   original_result,
                                 const DeviceInfo*                                          device_info,
                                 const StructPointerDecoder<Decoded_VkImageCreateInfo>&     pCreateInfo,
                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
                                 HandlePointerDecoder<VkImage>*                             pImage);

    VkResult OverrideCreateDescriptorUpdateTemplate(
        PFN_vkCreateDescriptorUpdateTemplate                                      func,
        VkResult                                                                  original_result,
        const DeviceInfo*                                                         device_info,
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>&                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                         pDescriptorUpdateTemplate);

    void OverrideDestroyDescriptorUpdateTemplate(PFN_vkDestroyDescriptorUpdateTemplate func,
                                                 const DeviceInfo*                     device_info,
                                                 const DescriptorUpdateTemplateInfo*   descriptor_update_template_info,
                                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator);

    VkResult OverrideCreatePipelineCache(PFN_vkCreatePipelineCache                                      func,
                                         VkResult                                                       original_result,
                                         const DeviceInfo*                                              device_info,
                                         const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>& pCreateInfo,
                                         const StructPointerDecoder<Decoded_VkAllocationCallbacks>&     pAllocator,
                                         HandlePointerDecoder<VkPipelineCache>*                         pPipelineCache);

    VkResult OverrideCreateDebugReportCallbackEXT(
        PFN_vkCreateDebugReportCallbackEXT                                      func,
        VkResult                                                                original_result,
        const InstanceInfo*                                                     instance_info,
        const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>&              pAllocator,
        HandlePointerDecoder<VkDebugReportCallbackEXT>*                         pCallback);

    VkResult OverrideCreateDebugUtilsMessengerEXT(
        PFN_vkCreateDebugUtilsMessengerEXT                                      func,
        VkResult                                                                original_result,
        const InstanceInfo*                                                     instance_info,
        const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>&              pAllocator,
        HandlePointerDecoder<VkDebugUtilsMessengerEXT>*                         pMessenger);

    VkResult OverrideCreateSwapchainKHR(PFN_vkCreateSwapchainKHR                                      func,
                                        VkResult                                                      original_result,
                                        const DeviceInfo*                                             device_info,
                                        const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfo,
                                        const StructPointerDecoder<Decoded_VkAllocationCallbacks>&    pAllocator,
                                        HandlePointerDecoder<VkSwapchainKHR>*                         pSwapchain);

    VkResult OverrideAcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                         VkResult                  original_result,
                                         const DeviceInfo*         device_info,
                                         const SwapchainKHRInfo*   swapchain_info,
                                         uint64_t                  timeout,
                                         const SemaphoreInfo*      semaphore_info,
                                         const FenceInfo*          fence_info,
                                         PointerDecoder<uint32_t>* pImageIndex);

    VkResult OverrideAcquireNextImage2KHR(PFN_vkAcquireNextImage2KHR func,
                                          VkResult                   original_result,
                                          const DeviceInfo*          device_info,
                                          const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>& pAcquireInfo,
                                          PointerDecoder<uint32_t>*                                      pImageIndex);

    // Window/Surface related overrides, which can transform the window/surface type from the platform
    // specific type found in the trace file to the platform specific type used for replay.
    VkResult
    OverrideCreateAndroidSurfaceKHR(PFN_vkCreateAndroidSurfaceKHR                                      func,
                                    VkResult                                                           original_result,
                                    const InstanceInfo*                                                instance_info,
                                    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>& pCreateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&         pAllocator,
                                    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface);

    VkResult OverrideCreateWin32SurfaceKHR(PFN_vkCreateWin32SurfaceKHR func,
                                           VkResult                    original_result,
                                           const InstanceInfo*         instance_info,
                                           const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>& pCreateInfo,
                                           const StructPointerDecoder<Decoded_VkAllocationCallbacks>&       pAllocator,
                                           HandlePointerDecoder<VkSurfaceKHR>*                              pSurface);

    VkBool32
    OverrideGetPhysicalDeviceWin32PresentationSupportKHR(PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
                                                         const PhysicalDeviceInfo* physical_device_info,
                                                         uint32_t                  queueFamilyIndex);

    VkResult OverrideCreateXcbSurfaceKHR(PFN_vkCreateXcbSurfaceKHR                                      func,
                                         VkResult                                                       original_result,
                                         const InstanceInfo*                                            instance_info,
                                         const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>& pCreateInfo,
                                         const StructPointerDecoder<Decoded_VkAllocationCallbacks>&     pAllocator,
                                         HandlePointerDecoder<VkSurfaceKHR>*                            pSurface);

    VkBool32 OverrideGetPhysicalDeviceXcbPresentationSupportKHR(PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
                                                                const PhysicalDeviceInfo* physical_device_info,
                                                                uint32_t                  queueFamilyIndex,
                                                                xcb_connection_t*         connection,
                                                                xcb_visualid_t            visual_id);

    VkResult OverrideCreateXlibSurfaceKHR(PFN_vkCreateXlibSurfaceKHR func,
                                          VkResult                   original_result,
                                          const InstanceInfo*        instance_info,
                                          const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>& pCreateInfo,
                                          const StructPointerDecoder<Decoded_VkAllocationCallbacks>&      pAllocator,
                                          HandlePointerDecoder<VkSurfaceKHR>*                             pSurface);

    VkBool32 OverrideGetPhysicalDeviceXlibPresentationSupportKHR(PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
                                                                 const PhysicalDeviceInfo* physical_device_info,
                                                                 uint32_t                  queueFamilyIndex,
                                                                 Display*                  dpy,
                                                                 VisualID                  visualID);

    VkResult
    OverrideCreateWaylandSurfaceKHR(PFN_vkCreateWaylandSurfaceKHR                                      func,
                                    VkResult                                                           original_result,
                                    const InstanceInfo*                                                instance_info,
                                    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>& pCreateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&         pAllocator,
                                    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface);

    VkBool32
    OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
                                                           const PhysicalDeviceInfo* physical_device_info,
                                                           uint32_t                  queueFamilyIndex,
                                                           struct wl_display*        display);

    void OverrideDestroySurfaceKHR(PFN_vkDestroySurfaceKHR                                    func,
                                   const InstanceInfo*                                        instance_info,
                                   const SurfaceKHRInfo*                                      surface_info,
                                   const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator);

  private:
    void RaiseFatalError(const char* message) const;

    void InitializeLoader();

    void AddInstanceTable(VkInstance instance);

    void AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa);

    PFN_vkGetDeviceProcAddr GetDeviceAddrProc(VkPhysicalDevice physical_device);

    PFN_vkCreateDevice GetCreateDeviceProc(VkPhysicalDevice physical_device);

    void ProcessPhysicalDeviceProperties(VkPhysicalDevice                  physical_device,
                                         const VkPhysicalDeviceProperties* capture_properties,
                                         const VkPhysicalDeviceProperties* replay_properties);

    void OverridePhysicalDevice(VkPhysicalDevice* physical_device);

    bool CheckTrimDeviceExtensions(VkPhysicalDevice physical_device, std::vector<std::string>* extensions);

    VkResult CreateSurface(VkInstance instance, VkFlags flags, HandlePointerDecoder<VkSurfaceKHR>* surface);

    void MapDescriptorUpdateTemplateHandles(const DescriptorUpdateTemplateInfo*    update_template_info,
                                            const DescriptorUpdateTemplateDecoder& decoder);

    // When processing swapchain image state for the trimming state setup, acquire all swapchain images to transition to
    // the expected layout and keep them acquired until first use.
    void ProcessSetSwapchainImageStatePreAcquire(VkDevice                                            device,
                                                 VkSwapchainKHR                                      swapchain,
                                                 uint32_t                                            queue_family_index,
                                                 const std::vector<format::SwapchainImageStateInfo>& image_info);

    // When processing swapchain image state for the trimming state setup, acquire an image, transition it to
    // the expected layout, and then call queue present if the image is not expected to be in the acquired state so that
    // no more than one image is acquired at a time.
    void ProcessSetSwapchainImageStateQueueSubmit(VkDevice       device,
                                                  VkSwapchainKHR swapchain,
                                                  uint32_t       queue_family_index,
                                                  uint32_t       last_presented_image,
                                                  const std::vector<format::SwapchainImageStateInfo>& image_info);

    void ProcessSwapchainFullScreenExclusiveInfo(Decoded_VkSwapchainCreateInfoKHR* swapchain_info);

    void ProcessImportAndroidHardwareBufferInfo(Decoded_VkMemoryAllocateInfo* allocate_info);

  private:
    struct InstanceDevices
    {
        std::vector<format::HandleId> capture_devices;
        std::vector<VkPhysicalDevice> replay_devices;
    };

    struct PhysicalDeviceProperties
    {
        VkPhysicalDeviceProperties capture_properties;
        VkPhysicalDeviceProperties replay_properties;
    };

    typedef std::unordered_set<Window*>                                    ActiveWindows;
    typedef std::unordered_map<VkInstance, InstanceDevices>                InstanceDeviceMap;
    typedef std::unordered_map<VkPhysicalDevice, PhysicalDeviceProperties> PhysicalDevicePropertiesMap;

    struct HardwareBufferInfo
    {
        format::HandleId memory_id;
        AHardwareBuffer* hardware_buffer;
    };

    struct HardwareBufferPlaneInfo
    {
        uint64_t capture_offset;
        uint64_t replay_offset;
        uint32_t capture_row_pitch;
        uint32_t replay_row_pitch;
    };

    struct HardwareBufferMemoryInfo
    {
        AHardwareBuffer*                     hardware_buffer;
        bool                                 compatible_strides;
        std::vector<HardwareBufferPlaneInfo> plane_info;
    };

    typedef std::unordered_map<uint64_t, HardwareBufferInfo>               HardwareBufferMap;
    typedef std::unordered_map<format::HandleId, HardwareBufferMemoryInfo> HardwareBufferMemoryMap;

  private:
    util::platform::LibraryHandle                                    loader_handle_;
    PFN_vkGetInstanceProcAddr                                        get_instance_proc_addr_;
    PFN_vkCreateInstance                                             create_instance_proc_;
    std::unordered_map<encode::DispatchKey, PFN_vkGetDeviceProcAddr> get_device_proc_addrs_;
    std::unordered_map<encode::DispatchKey, PFN_vkCreateDevice>      create_device_procs_;
    std::unordered_map<encode::DispatchKey, encode::InstanceTable>   instance_tables_;
    std::unordered_map<encode::DispatchKey, encode::DeviceTable>     device_tables_;
    std::function<void(const char*)>                                 fatal_error_handler_;
    WindowFactory*                                                   window_factory_;
    VulkanObjectInfoTable                                            object_info_table_;
    ActiveWindows                                                    active_windows_;
    ReplayOptions                                                    options_;
    bool                                                             loading_trim_state_;
    InstanceDeviceMap                                                instance_devices_;
    PhysicalDevicePropertiesMap                                      device_properties_;
    SwapchainImageTracker                                            swapchain_image_tracker_;
    HardwareBufferMap                                                hardware_buffers_;
    HardwareBufferMemoryMap                                          hardware_buffer_memory_info_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H
