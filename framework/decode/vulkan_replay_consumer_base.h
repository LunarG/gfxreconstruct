/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H

#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/screenshot_handler.h"
#include "decode/swapchain_image_tracker.h"
#include "decode/vulkan_device_address_tracker.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_object_info_table.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_resource_allocator.h"
#include "decode/vulkan_resource_tracking_consumer.h"
#include "decode/vulkan_resource_initializer.h"
#include "decode/vulkan_swapchain.h"
#include "format/api_call_id.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_consumer.h"
#include "generated/generated_vulkan_replay_dump_resources.h"
#include "graphics/fps_info.h"
#include "util/defines.h"
#include "util/logging.h"
#include "util/threadpool.h"

#include "application/application.h"

#include "vulkan/vulkan.h"

#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
    VulkanReplayConsumerBase(std::shared_ptr<application::Application> application, const VulkanReplayOptions& options);

    ~VulkanReplayConsumerBase() override;

    void SetCurrentBlockIndex(uint64_t block_index) override;

    void Process_ExeFileInfo(util::filepath::FileInfo& info_record) override
    {
        gfxrecon::util::filepath::CheckReplayerName(info_record.AppName);
    }

    void SetFatalErrorHandler(std::function<void(const char*)> handler) { fatal_error_handler_ = handler; }

    void SetFpsInfo(graphics::FpsInfo* fps_info) { fps_info_ = fps_info; }

    virtual void WaitDevicesIdle() override;

    virtual void ProcessStateBeginMarker(uint64_t frame_number) override;

    virtual void ProcessStateEndMarker(uint64_t frame_number) override;

    virtual void ProcessDisplayMessageCommand(const std::string& message) override;

    virtual void
    ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height) override;

    virtual void ProcessResizeWindowCommand2(format::HandleId surface_id,
                                             uint32_t         width,
                                             uint32_t         height,
                                             uint32_t         pre_transform) override;

    virtual void
    ProcessCreateHardwareBufferCommand(format::HandleId                                    memory_id,
                                       uint64_t                                            buffer_id,
                                       uint32_t                                            format,
                                       uint32_t                                            width,
                                       uint32_t                                            height,
                                       uint32_t                                            stride,
                                       uint64_t                                            usage,
                                       uint32_t                                            layers,
                                       const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override;

    virtual void ProcessDestroyHardwareBufferCommand(uint64_t buffer_id) override;

    virtual void ProcessSetDevicePropertiesCommand(format::HandleId   physical_device_id,
                                                   uint32_t           api_version,
                                                   uint32_t           driver_version,
                                                   uint32_t           vendor_id,
                                                   uint32_t           device_id,
                                                   uint32_t           device_type,
                                                   const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                   const std::string& device_name) override;

    virtual void
    ProcessSetDeviceMemoryPropertiesCommand(format::HandleId                             physical_device_id,
                                            const std::vector<format::DeviceMemoryType>& memory_types,
                                            const std::vector<format::DeviceMemoryHeap>& memory_heaps) override;

    virtual void
    ProcessSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, uint64_t address) override;

    virtual void ProcessSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                               format::HandleId pipeline_id,
                                                               size_t           data_size,
                                                               const uint8_t*   data) override;

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

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&               call_info,
                                                              format::HandleId                 device,
                                                              format::HandleId                 descriptorSet,
                                                              format::HandleId                 descriptorUpdateTemplate,
                                                              DescriptorUpdateTemplateDecoder* pData) override;

    virtual void
                 Process_vkCmdPushDescriptorSetWithTemplate2KHR(const ApiCallInfo& call_info,
                                                                format::HandleId   commandBuffer,
                                                                StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfoKHR>*
                                                                    pPushDescriptorSetWithTemplateInfo) override;
    virtual void Process_vkCreateRayTracingPipelinesKHR(
        const ApiCallInfo&                                               call_info,
        VkResult                                                         returnValue,
        format::HandleId                                                 device,
        format::HandleId                                                 deferredOperation,
        format::HandleId                                                 pipelineCache,
        uint32_t                                                         createInfoCount,
        StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
        HandlePointerDecoder<VkPipeline>*                                pPipelines) override;

    template <typename T>
    void AllowCompileDuringPipelineCreation(uint32_t create_info_count, const T* create_infos)
    {
        for (uint32_t i = 0; i < create_info_count; ++i)
        {
            if (create_infos[i].flags & VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT)
            {
                T* create_infos_to_modify = const_cast<T*>(create_infos);
                create_infos_to_modify[i].flags &= (~VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT);
            }
        }
    };

  protected:
    const VulkanObjectInfoTable& GetObjectInfoTable() const { return object_info_table_; }

    VulkanObjectInfoTable& GetObjectInfoTable() { return object_info_table_; }

    const encode::VulkanInstanceTable* GetInstanceTable(const void* handle) const;

    const encode::VulkanDeviceTable* GetDeviceTable(const void* handle) const;

    void* PreProcessExternalObject(uint64_t object_id, format::ApiCallId call_id, const char* call_name);

    void PostProcessExternalObject(
        VkResult replay_reslt, uint64_t object_id, void* object, format::ApiCallId call_id, const char* call_name);

    const VkAllocationCallbacks*
    GetAllocationCallbacks(const StructPointerDecoder<Decoded_VkAllocationCallbacks>* original_callbacks);

    void CheckResult(const char* func_name, VkResult original, VkResult replay, const decode::ApiCallInfo& call_info);

    template <typename T>
    typename T::HandleType MapHandle(format::HandleId id,
                                     const T* (VulkanObjectInfoTable::*MapFunc)(format::HandleId) const) const
    {
        return handle_mapping::MapHandle(id, object_info_table_, MapFunc);
    }

    uint64_t MapHandle(uint64_t object, VkObjectType object_type)
    {
        return handle_mapping::MapHandle(object, object_type, object_info_table_);
    }

    uint64_t MapHandle(uint64_t object, VkDebugReportObjectTypeEXT object_type)
    {
        return handle_mapping::MapHandle(object, object_type, object_info_table_);
    }

    template <typename T>
    typename T::HandleType* MapHandles(HandlePointerDecoder<typename T::HandleType>* handles_pointer,
                                       size_t                                        handles_len,
                                       const T* (VulkanObjectInfoTable::*MapFunc)(format::HandleId) const) const
    {
        // This parameter is only referenced by debug builds.
        GFXRECON_UNREFERENCED_PARAMETER(handles_len);

        typename T::HandleType* handles = nullptr;

        if (handles_pointer != nullptr)
        {
            // The handle and ID array sizes are expected to be the same for mapping operations.
            assert(handles_len == handles_pointer->GetLength());

            handles = handle_mapping::MapHandleArray(handles_pointer, object_info_table_, MapFunc);
        }

        return handles;
    }

    template <typename T>
    void AddHandle(format::HandleId              parent_id,
                   const format::HandleId*       id,
                   const typename T::HandleType* handle,
                   T&&                           initial_info,
                   void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        if ((id != nullptr) && (handle != nullptr))
        {
            handle_mapping::AddHandle(
                parent_id, *id, *handle, std::forward<T>(initial_info), &object_info_table_, AddFunc);
        }
    }

    template <typename T>
    void AddHandle(format::HandleId              parent_id,
                   const format::HandleId*       id,
                   const typename T::HandleType* handle,
                   void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        if ((id != nullptr) && (handle != nullptr))
        {
            handle_mapping::AddHandle(parent_id, *id, *handle, &object_info_table_, AddFunc);
        }
    }

    template <typename T>
    void AddHandles(format::HandleId              parent_id,
                    const format::HandleId*       ids,
                    size_t                        ids_len,
                    const typename T::HandleType* handles,
                    size_t                        handles_len,
                    std::vector<T>&&              initial_infos,
                    void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        handle_mapping::AddHandleArray(
            parent_id, ids, ids_len, handles, handles_len, std::move(initial_infos), &object_info_table_, AddFunc);
    }

    template <typename T>
    void AddHandles(format::HandleId              parent_id,
                    const format::HandleId*       ids,
                    size_t                        ids_len,
                    const typename T::HandleType* handles,
                    size_t                        handles_len,
                    void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        handle_mapping::AddHandleArray(parent_id, ids, ids_len, handles, handles_len, &object_info_table_, AddFunc);
    }

    template <typename T>
    void AddHandlesAsync(format::HandleId        parent_id,
                         const format::HandleId* ids,
                         size_t                  ids_len,
                         void (VulkanObjectInfoTable::*AddFunc)(T&&),
                         std::function<handle_create_result_t<typename T::HandleType>()> create_function)
    {
        if (create_function)
        {
            std::shared_future<handle_create_result_t<typename T::HandleType>> result_future =
                background_queue_.post(std::move(create_function));

            // poll in case there are no worker-threads
            background_queue_.poll();

            handle_mapping::AddHandleArrayAsync(
                parent_id, ids, ids_len, &object_info_table_, AddFunc, std::move(result_future));
        }
    }

    template <typename T>
    void AddHandlesAsync(format::HandleId        parent_id,
                         const format::HandleId* ids,
                         size_t                  ids_len,
                         std::vector<T>&&        initial_infos,
                         void (VulkanObjectInfoTable::*AddFunc)(T&&),
                         std::function<handle_create_result_t<typename T::HandleType>()> create_function)
    {
        if (create_function)
        {
            std::shared_future<handle_create_result_t<typename T::HandleType>> result_future =
                background_queue_.post(std::move(create_function));

            // poll in case there are no worker-threads
            background_queue_.poll();

            handle_mapping::AddHandleArrayAsync(parent_id,
                                                ids,
                                                ids_len,
                                                &object_info_table_,
                                                std::move(initial_infos),
                                                AddFunc,
                                                std::move(result_future));
        }
    }

    //! track arbitrary handles that are currently used by asynchronous operations
    void TrackAsyncHandles(const std::unordered_set<format::HandleId>& async_handles,
                           const std::function<void()>&                sync_fn);

    //! clear handles that are currently used by asynchronous operations,
    //! invoke stored deletion-functions
    void ClearAsyncHandles(const std::unordered_set<format::HandleId>& async_handles);

    //! schedules deletion of already tracked handles
    void DestroyAsyncHandle(format::HandleId handle, std::function<void()> destroy_fn);

    //! return true if this handle is currently being tracked (was passed to 'TrackAsyncHandles' earlier)
    bool IsUsedByAsyncTask(uint64_t handle) const { return async_tracked_handles_.count(handle) > 0; }

    //! returns true if asynchronous operations should be used at all
    bool UseAsyncOperations() { return options_.num_pipeline_creation_jobs != 0 && !options_.dumping_resources; }

    //! returns a thread-safe queue, that is polled on the main-thread, at the beginning of a new block
    util::ThreadPool& MainThreadQueue() { return main_thread_queue_; }

    template <typename S, typename T>
    void AddPoolHandles(format::HandleId              parent_id,
                        format::HandleId              pool_id,
                        const format::HandleId*       ids,
                        size_t                        ids_len,
                        const typename T::HandleType* handles,
                        size_t                        handles_len,
                        std::vector<T>&&              initial_infos,
                        S* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                        void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        handle_mapping::AddHandleArray(parent_id,
                                       pool_id,
                                       ids,
                                       ids_len,
                                       handles,
                                       handles_len,
                                       std::move(initial_infos),
                                       &object_info_table_,
                                       GetPoolInfoFunc,
                                       AddFunc);
    }

    template <typename S, typename T>
    void AddPoolHandles(format::HandleId              parent_id,
                        format::HandleId              pool_id,
                        const format::HandleId*       ids,
                        size_t                        ids_len,
                        const typename T::HandleType* handles,
                        size_t                        handles_len,
                        S* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                        void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        handle_mapping::AddHandleArray(
            parent_id, pool_id, ids, ids_len, handles, handles_len, &object_info_table_, GetPoolInfoFunc, AddFunc);
    }

    void RemoveHandle(format::HandleId id, void (VulkanObjectInfoTable::*RemoveFunc)(format::HandleId))
    {
        handle_mapping::RemoveHandle(id, &object_info_table_, RemoveFunc);
    }

    template <typename T>
    void RemovePoolHandle(format::HandleId id,
                          T* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                          void (VulkanObjectInfoTable::*RemovePoolFunc)(format::HandleId),
                          void (VulkanObjectInfoTable::*RemoveObjectFunc)(format::HandleId))
    {
        handle_mapping::RemovePoolHandle(id, &object_info_table_, GetPoolInfoFunc, RemovePoolFunc, RemoveObjectFunc);
    }

    template <typename S, typename T>
    void RemovePoolHandles(format::HandleId                                    pool_id,
                           const HandlePointerDecoder<typename T::HandleType>* handles_pointer,
                           size_t                                              handles_len,
                           S* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                           void (VulkanObjectInfoTable::*RemoveFunc)(format::HandleId))
    {
        // This parameter is only referenced by debug builds.
        GFXRECON_UNREFERENCED_PARAMETER(handles_len);

        if (handles_pointer != nullptr)
        {
            // The handle and ID array sizes are expected to be the same for mapping operations.
            assert(handles_len == handles_pointer->GetLength());
            handle_mapping::RemoveHandleArray<S, T>(
                pool_id, handles_pointer, &object_info_table_, GetPoolInfoFunc, RemoveFunc);
        }
    }

    template <typename HandleInfoT>
    void SetOutputArrayCount(format::HandleId handle_id,
                             uint32_t         index,
                             size_t           count,
                             HandleInfoT* (VulkanObjectInfoTable::*HandleInfoFunc)(format::HandleId))
    {
        HandleInfoT* info = (object_info_table_.*HandleInfoFunc)(handle_id);
        if (info != nullptr)
        {
            info->array_counts[index] = static_cast<size_t>(count);
        }
    }

    template <typename CountT, typename HandleInfoT, typename ArrayT>
    CountT GetOutputArrayCount(const char*                   func_name,
                               VkResult                      original_result,
                               format::HandleId              handle_id,
                               uint32_t                      index,
                               const PointerDecoder<CountT>* original_count,
                               const ArrayT*                 original_array,
                               const HandleInfoT* (VulkanObjectInfoTable::*HandleInfoFunc)(format::HandleId) const)
    {
        assert((original_count != nullptr) && (original_array != nullptr));

        CountT replay_count = 0;

        if (!original_count->IsNull() && !original_array->IsNull())
        {
            // When the array parameter is not null, start with array count set equal to the capture count and then
            // adjust if the replay count is different.
            replay_count = (*original_count->GetPointer());

            // Only adjust the replay array count if the call succeeded on capture so that errors generated at capture,
            // such as VK_INCOMPLETE, continue to be generated at replay.
            if (original_result == VK_SUCCESS)
            {
                const HandleInfoT* info = (object_info_table_.*HandleInfoFunc)(handle_id);
                if (info != nullptr)
                {
                    auto entry = info->array_counts.find(index);
                    if ((entry != info->array_counts.end()) && (entry->second != replay_count))
                    {
                        GFXRECON_LOG_INFO("Replay adjusted the %s array count: capture count = %" PRIuPTR
                                          ", replay count = %" PRIuPTR,
                                          func_name,
                                          static_cast<size_t>(replay_count),
                                          entry->second);
                        replay_count = static_cast<CountT>(entry->second);
                    }
                }
            }
        }

        return replay_count;
    }

    //
    // Replay function overrides provided to the replay consumer code generator with replay_overrides.json
    //

    VkResult OverrideCreateInstance(VkResult                                                   original_result,
                                    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                    HandlePointerDecoder<VkInstance>*                          pInstance);

    VkResult OverrideCreateDevice(VkResult                                                   original_result,
                                  VulkanPhysicalDeviceInfo*                                  physical_device_info,
                                  const StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                  const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                  HandlePointerDecoder<VkDevice>*                            pDevice);

    void OverrideDestroyDevice(PFN_vkDestroyDevice                                        func,
                               const VulkanDeviceInfo*                                    device_info,
                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideEnumeratePhysicalDevices(PFN_vkEnumeratePhysicalDevices          func,
                                              VkResult                                original_result,
                                              VulkanInstanceInfo*                     instance_info,
                                              PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                              HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices);

    VkResult OverrideEnumeratePhysicalDeviceGroups(
        PFN_vkEnumeratePhysicalDeviceGroups                            func,
        VkResult                                                       original_result,
        VulkanInstanceInfo*                                            instance_info,
        PointerDecoder<uint32_t>*                                      pPhysicalDeviceGroupCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties);

    void OverrideGetPhysicalDeviceProperties(PFN_vkGetPhysicalDeviceProperties func,
                                             VulkanPhysicalDeviceInfo*         physical_device_info,
                                             StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties);

    void OverrideGetPhysicalDeviceProperties2(PFN_vkGetPhysicalDeviceProperties2 func,
                                              VulkanPhysicalDeviceInfo*          physical_device_info,
                                              StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties);

    void OverrideGetPhysicalDeviceMemoryProperties(
        PFN_vkGetPhysicalDeviceMemoryProperties                         func,
        VulkanPhysicalDeviceInfo*                                       physical_device_info,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties);

    void OverrideGetPhysicalDeviceMemoryProperties2(
        PFN_vkGetPhysicalDeviceMemoryProperties2                         func,
        VulkanPhysicalDeviceInfo*                                        physical_device_info,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties);

    VkResult OverrideGetPhysicalDeviceSurfaceCapabilitiesKHR(
        PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR           func,
        VkResult                                                original_result,
        VulkanPhysicalDeviceInfo*                               physical_device_info,
        VulkanSurfaceKHRInfo*                                   surface_info,
        StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities);

    VkResult OverrideGetPhysicalDeviceSurfaceCapabilities2KHR(
        PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR                 func,
        VkResult                                                       original_result,
        VulkanPhysicalDeviceInfo*                                      physical_device_info,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
        StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>*       pSurfaceCapabilities);

    VkResult OverrideGetPhysicalDeviceToolProperties(
        PFN_vkGetPhysicalDeviceToolProperties                         func,
        VkResult                                                      original_result,
        const VulkanPhysicalDeviceInfo*                               physical_device_info,
        PointerDecoder<uint32_t>*                                     pToolCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties);

    void OverrideGetDeviceQueue(PFN_vkGetDeviceQueue           func,
                                VulkanDeviceInfo*              device_info,
                                uint32_t                       queueFamilyIndex,
                                uint32_t                       queueIndex,
                                HandlePointerDecoder<VkQueue>* pQueue);
    void OverrideGetDeviceQueue2(PFN_vkGetDeviceQueue2                             func,
                                 VulkanDeviceInfo*                                 device_info,
                                 StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
                                 HandlePointerDecoder<VkQueue>*                    pQueue);

    VkResult OverrideWaitForFences(PFN_vkWaitForFences                  func,
                                   VkResult                             original_result,
                                   const VulkanDeviceInfo*              device_info,
                                   uint32_t                             fenceCount,
                                   const HandlePointerDecoder<VkFence>* pFences,
                                   VkBool32                             waitAll,
                                   uint64_t                             timeout);

    VkResult OverrideGetFenceStatus(PFN_vkGetFenceStatus    func,
                                    VkResult                original_result,
                                    const VulkanDeviceInfo* device_info,
                                    const VulkanFenceInfo*  fence_info);

    VkResult OverrideGetEventStatus(PFN_vkGetEventStatus    func,
                                    VkResult                original_result,
                                    const VulkanDeviceInfo* device_info,
                                    const VulkanEventInfo*  event_info);

    VkResult OverrideGetQueryPoolResults(PFN_vkGetQueryPoolResults  func,
                                         VkResult                   original_result,
                                         const VulkanDeviceInfo*    device_info,
                                         const VulkanQueryPoolInfo* query_pool_info,
                                         uint32_t                   firstQuery,
                                         uint32_t                   queryCount,
                                         size_t                     dataSize,
                                         PointerDecoder<uint8_t>*   pData,
                                         VkDeviceSize               stride,
                                         VkQueryResultFlags         flags);

    VkResult OverrideQueueSubmit(PFN_vkQueueSubmit                                 func,
                                 uint64_t                                          index,
                                 VkResult                                          original_result,
                                 const VulkanQueueInfo*                            queue_info,
                                 uint32_t                                          submitCount,
                                 const StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                 const VulkanFenceInfo*                            fence_info);

    VkResult OverrideQueueSubmit2(PFN_vkQueueSubmit2                                 func,
                                  VkResult                                           original_result,
                                  const VulkanQueueInfo*                             queue_info,
                                  uint32_t                                           submitCount,
                                  const StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                  const VulkanFenceInfo*                             fence_info);

    VkResult OverrideQueueBindSparse(PFN_vkQueueBindSparse                                 func,
                                     VkResult                                              original_result,
                                     const VulkanQueueInfo*                                queue_info,
                                     uint32_t                                              bindInfoCount,
                                     const StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
                                     const VulkanFenceInfo*                                fence_info);

    VkResult
    OverrideCreateDescriptorSetLayout(PFN_vkCreateDescriptorSetLayout                                func,
                                      VkResult                                                       original_result,
                                      const VulkanDeviceInfo*                                        device_info,
                                      StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>*           pAllocator,
                                      HandlePointerDecoder<VkDescriptorSetLayout>*                   pSetLayout);

    VkResult OverrideCreateDescriptorPool(PFN_vkCreateDescriptorPool func,
                                          VkResult                   original_result,
                                          const VulkanDeviceInfo*    device_info,
                                          const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
                                          const StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                          HandlePointerDecoder<VkDescriptorPool>* pDescriptorPool);

    void OverrideDestroyDescriptorPool(PFN_vkDestroyDescriptorPool                                func,
                                       const VulkanDeviceInfo*                                    device_info,
                                       VulkanDescriptorPoolInfo*                                  descriptor_pool_info,
                                       const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult
    OverrideAllocateDescriptorSets(PFN_vkAllocateDescriptorSets                                     func,
                                   VkResult                                                         original_result,
                                   const VulkanDeviceInfo*                                          device_info,
                                   const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                   HandlePointerDecoder<VkDescriptorSet>*                           pDescriptorSets);

    VkResult
    OverrideAllocateCommandBuffers(PFN_vkAllocateCommandBuffers                                     func,
                                   VkResult                                                         original_result,
                                   const VulkanDeviceInfo*                                          device_info,
                                   const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                   HandlePointerDecoder<VkCommandBuffer>*                           pCommandBuffers);

    void OverrideFreeCommandBuffers(PFN_vkFreeCommandBuffers               func,
                                    const VulkanDeviceInfo*                device_info,
                                    VulkanCommandPoolInfo*                 command_pool_info,
                                    uint32_t                               command_buffer_count,
                                    HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers);

    VkResult OverrideAllocateMemory(PFN_vkAllocateMemory                                       func,
                                    VkResult                                                   original_result,
                                    const VulkanDeviceInfo*                                    device_info,
                                    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  pAllocateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                    HandlePointerDecoder<VkDeviceMemory>*                      pMemory);

    VkResult OverrideMapMemory(PFN_vkMapMemory         func,
                               VkResult                original_result,
                               const VulkanDeviceInfo* device_info,
                               VulkanDeviceMemoryInfo* memory_info,
                               VkDeviceSize            offset,
                               VkDeviceSize            size,
                               VkMemoryMapFlags        flags,
                               void**                  ppData);

    void OverrideUnmapMemory(PFN_vkUnmapMemory       func,
                             const VulkanDeviceInfo* device_info,
                             VulkanDeviceMemoryInfo* memory_info);

    VkResult OverrideFlushMappedMemoryRanges(PFN_vkFlushMappedMemoryRanges                            func,
                                             VkResult                                                 original_result,
                                             const VulkanDeviceInfo*                                  device_info,
                                             uint32_t                                                 memoryRangeCount,
                                             const StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges);

    VkResult
    OverrideInvalidateMappedMemoryRanges(PFN_vkInvalidateMappedMemoryRanges                       func,
                                         VkResult                                                 original_result,
                                         const VulkanDeviceInfo*                                  device_info,
                                         uint32_t                                                 memoryRangeCount,
                                         const StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges);

    void OverrideFreeMemory(PFN_vkFreeMemory                                           func,
                            const VulkanDeviceInfo*                                    device_info,
                            VulkanDeviceMemoryInfo*                                    memory_info,
                            const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideBindBufferMemory(PFN_vkBindBufferMemory  func,
                                      VkResult                original_result,
                                      const VulkanDeviceInfo* device_info,
                                      VulkanBufferInfo*       buffer_info,
                                      VulkanDeviceMemoryInfo* memory_info,
                                      VkDeviceSize            memoryOffset);

    VkResult OverrideBindBufferMemory2(PFN_vkBindBufferMemory2                                     func,
                                       VkResult                                                    original_result,
                                       const VulkanDeviceInfo*                                     device_info,
                                       uint32_t                                                    bindInfoCount,
                                       const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos);

    VkResult OverrideBindImageMemory(PFN_vkBindImageMemory   func,
                                     VkResult                original_result,
                                     const VulkanDeviceInfo* device_info,
                                     VulkanImageInfo*        image_info,
                                     VulkanDeviceMemoryInfo* memory_info,
                                     VkDeviceSize            memoryOffset);

    VkResult OverrideBindImageMemory2(PFN_vkBindImageMemory2                                     func,
                                      VkResult                                                   original_result,
                                      const VulkanDeviceInfo*                                    device_info,
                                      uint32_t                                                   bindInfoCount,
                                      const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos);

    VkResult OverrideBindVideoSessionMemoryKHR(
        PFN_vkBindVideoSessionMemoryKHR                                func,
        VkResult                                                       original_result,
        const VulkanDeviceInfo*                                        device_info,
        VulkanVideoSessionKHRInfo*                                     video_session_info,
        uint32_t                                                       bindSessionMemoryInfoCount,
        StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos);

    VkResult OverrideCreateBuffer(PFN_vkCreateBuffer                                         func,
                                  VkResult                                                   original_result,
                                  const VulkanDeviceInfo*                                    device_info,
                                  const StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
                                  const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                  HandlePointerDecoder<VkBuffer>*                            pBuffer);

    void OverrideDestroyBuffer(PFN_vkDestroyBuffer                                        func,
                               const VulkanDeviceInfo*                                    device_info,
                               VulkanBufferInfo*                                          buffer_info,
                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideCreateImage(PFN_vkCreateImage                                          func,
                                 VkResult                                                   original_result,
                                 const VulkanDeviceInfo*                                    device_info,
                                 const StructPointerDecoder<Decoded_VkImageCreateInfo>*     pCreateInfo,
                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                 HandlePointerDecoder<VkImage>*                             pImage);

    void OverrideDestroyImage(PFN_vkDestroyImage                                         func,
                              const VulkanDeviceInfo*                                    device_info,
                              VulkanImageInfo*                                           image_info,
                              const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideCreateVideoSessionKHR(PFN_vkCreateVideoSessionKHR func,
                                           VkResult                    original_result,
                                           const VulkanDeviceInfo*     device_info,
                                           const StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
                                           const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                           HandlePointerDecoder<VkVideoSessionKHR>* pVideoSession);

    void OverrideDestroyVideoSessionKHR(PFN_vkDestroyVideoSessionKHR                               func,
                                        const VulkanDeviceInfo*                                    device_info,
                                        VulkanVideoSessionKHRInfo*                                 video_session_info,
                                        const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideGetImageSubresourceLayout(PFN_vkGetImageSubresourceLayout                         func,
                                           const VulkanDeviceInfo*                                 device_info,
                                           const VulkanImageInfo*                                  image_info,
                                           const StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
                                           StructPointerDecoder<Decoded_VkSubresourceLayout>*      pLayout);

    VkResult OverrideCreateRenderPass(PFN_vkCreateRenderPass                                      func,
                                      VkResult                                                    original_result,
                                      const VulkanDeviceInfo*                                     device_info,
                                      const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
                                      const StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
                                      HandlePointerDecoder<VkRenderPass>*                         pRenderPass);

    VkResult OverrideCreateRenderPass2(PFN_vkCreateRenderPass2                                      func,
                                       VkResult                                                     original_result,
                                       const VulkanDeviceInfo*                                      device_info,
                                       const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
                                       const StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                       HandlePointerDecoder<VkRenderPass>*                          pRenderPass);

    void OverrideCmdPipelineBarrier(PFN_vkCmdPipelineBarrier                                   func,
                                    VulkanCommandBufferInfo*                                   command_buffer_info,
                                    VkPipelineStageFlags                                       srcStageMask,
                                    VkPipelineStageFlags                                       dstStageMask,
                                    VkDependencyFlags                                          dependencyFlags,
                                    uint32_t                                                   memoryBarrierCount,
                                    const StructPointerDecoder<Decoded_VkMemoryBarrier>*       pMemoryBarriers,
                                    uint32_t                                                   bufferMemoryBarrierCount,
                                    const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
                                    uint32_t                                                   imageMemoryBarrierCount,
                                    const StructPointerDecoder<Decoded_VkImageMemoryBarrier>*  pImageMemoryBarriers);

    void OverrideCmdPipelineBarrier2(PFN_vkCmdPipelineBarrier2                       func,
                                     VulkanCommandBufferInfo*                        command_buffer_info,
                                     StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo);

    void OverrideCmdPipelineBarrier2KHR(PFN_vkCmdPipelineBarrier2                       func,
                                        VulkanCommandBufferInfo*                        command_buffer_info,
                                        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo);

    VkResult OverrideCreateDescriptorUpdateTemplate(
        PFN_vkCreateDescriptorUpdateTemplate                                      func,
        VkResult                                                                  original_result,
        const VulkanDeviceInfo*                                                   device_info,
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                         pDescriptorUpdateTemplate);

    void
    OverrideDestroyDescriptorUpdateTemplate(PFN_vkDestroyDescriptorUpdateTemplate     func,
                                            const VulkanDeviceInfo*                   device_info,
                                            const VulkanDescriptorUpdateTemplateInfo* descriptor_update_template_info,
                                            const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideCreateShaderModule(PFN_vkCreateShaderModule                                      func,
                                        VkResult                                                      original_result,
                                        const VulkanDeviceInfo*                                       device_info,
                                        const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
                                        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                        HandlePointerDecoder<VkShaderModule>*                         pShaderModule);

    VkResult OverrideGetPipelineCacheData(PFN_vkGetPipelineCacheData     func,
                                          VkResult                       original_result,
                                          const VulkanDeviceInfo*        device_info,
                                          const VulkanPipelineCacheInfo* pipeline_cache_info,
                                          PointerDecoder<size_t>*        pDataSize,
                                          PointerDecoder<uint8_t>*       pData);

    VkResult OverrideCreatePipelineCache(PFN_vkCreatePipelineCache                                      func,
                                         VkResult                                                       original_result,
                                         const VulkanDeviceInfo*                                        device_info,
                                         const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
                                         const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
                                         HandlePointerDecoder<VkPipelineCache>*                         pPipelineCache);

    VkResult OverrideResetDescriptorPool(PFN_vkResetDescriptorPool  func,
                                         VkResult                   original_result,
                                         const VulkanDeviceInfo*    device_info,
                                         VulkanDescriptorPoolInfo*  pool_info,
                                         VkDescriptorPoolResetFlags flags);

    VkResult OverrideCreateDebugReportCallbackEXT(
        PFN_vkCreateDebugReportCallbackEXT                                      func,
        VkResult                                                                original_result,
        const VulkanInstanceInfo*                                               instance_info,
        const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*              pAllocator,
        HandlePointerDecoder<VkDebugReportCallbackEXT>*                         pCallback);

    VkResult OverrideCreateDebugUtilsMessengerEXT(
        PFN_vkCreateDebugUtilsMessengerEXT                                      func,
        VkResult                                                                original_result,
        const VulkanInstanceInfo*                                               instance_info,
        const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*              pAllocator,
        HandlePointerDecoder<VkDebugUtilsMessengerEXT>*                         pMessenger);

    VkResult OverrideCreateSwapchainKHR(PFN_vkCreateSwapchainKHR                                      func,
                                        VkResult                                                      original_result,
                                        VulkanDeviceInfo*                                             device_info,
                                        const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
                                        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                        HandlePointerDecoder<VkSwapchainKHR>*                         pSwapchain);

    VkResult
    OverrideCreateSharedSwapchainsKHR(PFN_vkCreateSharedSwapchainsKHR                               func,
                                      VkResult                                                      original_result,
                                      VulkanDeviceInfo*                                             device_info,
                                      uint32_t                                                      swapchainCount,
                                      const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
                                      const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                      HandlePointerDecoder<VkSwapchainKHR>*                         pSwapchains);

    void OverrideDestroySwapchainKHR(PFN_vkDestroySwapchainKHR                                  func,
                                     VulkanDeviceInfo*                                          device_info,
                                     VulkanSwapchainKHRInfo*                                    swapchain_info,
                                     const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideGetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR    func,
                                           VkResult                       original_result,
                                           const VulkanDeviceInfo*        device_info,
                                           VulkanSwapchainKHRInfo*        swapchain_info,
                                           PointerDecoder<uint32_t>*      pSwapchainImageCount,
                                           HandlePointerDecoder<VkImage>* pSwapchainImages);

    VkResult OverrideAcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                         VkResult                  original_result,
                                         const VulkanDeviceInfo*   device_info,
                                         VulkanSwapchainKHRInfo*   swapchain_info,
                                         uint64_t                  timeout,
                                         VulkanSemaphoreInfo*      semaphore_info,
                                         VulkanFenceInfo*          fence_info,
                                         PointerDecoder<uint32_t>* pImageIndex);

    VkResult OverrideAcquireNextImage2KHR(PFN_vkAcquireNextImage2KHR func,
                                          VkResult                   original_result,
                                          const VulkanDeviceInfo*    device_info,
                                          const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
                                          PointerDecoder<uint32_t>*                                      pImageIndex);

    VkResult OverrideQueuePresentKHR(PFN_vkQueuePresentKHR                                 func,
                                     VkResult                                              original_result,
                                     const VulkanQueueInfo*                                queue_info,
                                     const StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo);

    VkResult OverrideImportSemaphoreFdKHR(
        PFN_vkImportSemaphoreFdKHR                                      func,
        VkResult                                                        original_result,
        const VulkanDeviceInfo*                                         device_info,
        const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo);

    VkResult OverrideGetSemaphoreFdKHR(PFN_vkGetSemaphoreFdKHR                                      func,
                                       VkResult                                                     original_result,
                                       const VulkanDeviceInfo*                                      device_info,
                                       const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
                                       const PointerDecoder<int>*                                   pFd);

    VkResult OverrideImportSemaphoreWin32HandleKHR(
        PFN_vkImportSemaphoreWin32HandleKHR                                      func,
        VkResult                                                                 original_result,
        const VulkanDeviceInfo*                                                  device_info,
        const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo);

    VkResult OverrideGetSemaphoreWin32HandleKHR(
        PFN_vkGetSemaphoreWin32HandleKHR                                      func,
        VkResult                                                              original_result,
        const VulkanDeviceInfo*                                               device_info,
        const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
        const PointerDecoder<uint64_t, void*>*                                pHandle);

    VkResult OverrideGetRandROutputDisplayEXT(PFN_vkGetRandROutputDisplayEXT      func,
                                              VkResult                            original_result,
                                              const VulkanPhysicalDeviceInfo*     physicalDevice,
                                              Display*                            dpy,
                                              RROutput                            rrOutput,
                                              HandlePointerDecoder<VkDisplayKHR>* pDisplay);

    // Window/Surface related overrides, which can transform the window/surface type from the platform
    // specific type found in the trace file to the platform specific type used for replay.
    VkResult
    OverrideCreateAndroidSurfaceKHR(PFN_vkCreateAndroidSurfaceKHR                                      func,
                                    VkResult                                                           original_result,
                                    VulkanInstanceInfo*                                                instance_info,
                                    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface);

    VkResult OverrideCreateWin32SurfaceKHR(PFN_vkCreateWin32SurfaceKHR func,
                                           VkResult                    original_result,
                                           VulkanInstanceInfo*         instance_info,
                                           const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
                                           const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                           HandlePointerDecoder<VkSurfaceKHR>*                              pSurface);

    VkBool32
    OverrideGetPhysicalDeviceWin32PresentationSupportKHR(PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
                                                         const VulkanPhysicalDeviceInfo* physical_device_info,
                                                         uint32_t                        queueFamilyIndex);

    VkResult OverrideCreateXcbSurfaceKHR(PFN_vkCreateXcbSurfaceKHR                                      func,
                                         VkResult                                                       original_result,
                                         VulkanInstanceInfo*                                            instance_info,
                                         const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
                                         const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
                                         HandlePointerDecoder<VkSurfaceKHR>*                            pSurface);

    VkBool32 OverrideGetPhysicalDeviceXcbPresentationSupportKHR(PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
                                                                const VulkanPhysicalDeviceInfo* physical_device_info,
                                                                uint32_t                        queueFamilyIndex,
                                                                xcb_connection_t*               connection,
                                                                xcb_visualid_t                  visual_id);

    VkResult OverrideCreateXlibSurfaceKHR(PFN_vkCreateXlibSurfaceKHR func,
                                          VkResult                   original_result,
                                          VulkanInstanceInfo*        instance_info,
                                          const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
                                          const StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                          HandlePointerDecoder<VkSurfaceKHR>*                             pSurface);

    VkBool32 OverrideGetPhysicalDeviceXlibPresentationSupportKHR(PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
                                                                 const VulkanPhysicalDeviceInfo* physical_device_info,
                                                                 uint32_t                        queueFamilyIndex,
                                                                 Display*                        dpy,
                                                                 VisualID                        visualID);

    VkResult
    OverrideCreateWaylandSurfaceKHR(PFN_vkCreateWaylandSurfaceKHR                                      func,
                                    VkResult                                                           original_result,
                                    VulkanInstanceInfo*                                                instance_info,
                                    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface);

    VkResult
    OverrideCreateDisplayPlaneSurfaceKHR(PFN_vkCreateDisplayPlaneSurfaceKHR func,
                                         VkResult                           original_result,
                                         VulkanInstanceInfo*                instance_info,
                                         const StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
                                         const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                         HandlePointerDecoder<VkSurfaceKHR>*                                pSurface);

    VkResult
    OverrideCreateHeadlessSurfaceEXT(PFN_vkCreateHeadlessSurfaceEXT func,
                                     VkResult                       original_result,
                                     VulkanInstanceInfo*            instance_info,
                                     const StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
                                     const StructPointerDecoder<Decoded_VkAllocationCallbacks>*          pAllocator,
                                     HandlePointerDecoder<VkSurfaceKHR>*                                 pSurface);

    VkBool32
    OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
                                                           const VulkanPhysicalDeviceInfo* physical_device_info,
                                                           uint32_t                        queueFamilyIndex,
                                                           struct wl_display*              display);

    VkResult OverrideCreateMetalSurfaceEXT(PFN_vkCreateMetalSurfaceEXT func,
                                           VkResult                    original_result,
                                           VulkanInstanceInfo*         instance_info,
                                           const StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
                                           const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                           HandlePointerDecoder<VkSurfaceKHR>*                              pSurface);

    void OverrideDestroySurfaceKHR(PFN_vkDestroySurfaceKHR                                    func,
                                   VulkanInstanceInfo*                                        instance_info,
                                   const VulkanSurfaceKHRInfo*                                surface_info,
                                   const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideCreateAccelerationStructureKHR(
        PFN_vkCreateAccelerationStructureKHR                                      func,
        VkResult                                                                  original_result,
        const VulkanDeviceInfo*                                                   device_info,
        const StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkAccelerationStructureKHR>*                         pAccelerationStructureKHR);

    void OverrideDestroyAccelerationStructureKHR(PFN_vkDestroyAccelerationStructureKHR     func,
                                                 const VulkanDeviceInfo*                   device_info,
                                                 const VulkanAccelerationStructureKHRInfo* acceleration_structure_info,
                                                 StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideCmdBuildAccelerationStructuresKHR(
        PFN_vkCmdBuildAccelerationStructuresKHR                                    func,
        VulkanCommandBufferInfo*                                                   command_buffer_info,
        uint32_t                                                                   infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   ppBuildRangeInfos);

    void
    OverrideCmdCopyAccelerationStructureKHR(PFN_vkCmdCopyAccelerationStructureKHR func,
                                            VulkanCommandBufferInfo*              command_buffer_info,
                                            StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo);

    void OverrideCmdWriteAccelerationStructuresPropertiesKHR(
        PFN_vkCmdWriteAccelerationStructuresPropertiesKHR func,
        VulkanCommandBufferInfo*                          command_buffer_info,
        uint32_t                                          count,
        HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
        VkQueryType                                       queryType,
        gfxrecon::decode::VulkanQueryPoolInfo*            query_pool_info,
        uint32_t                                          firstQuery);

    VkResult OverrideCreateRayTracingPipelinesKHR(
        PFN_vkCreateRayTracingPipelinesKHR                                     func,
        VkResult                                                               original_result,
        const VulkanDeviceInfo*                                                device_info,
        VulkanDeferredOperationKHRInfo*                                        deferred_operation_info,
        const VulkanPipelineCacheInfo*                                         pipeline_cache_info,
        uint32_t                                                               createInfoCount,
        const StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
        HandlePointerDecoder<VkPipeline>*                                      pPipelines);

    VkResult OverrideDeferredOperationJoinKHR(PFN_vkDeferredOperationJoinKHR  func,
                                              VkResult                        original_result,
                                              const VulkanDeviceInfo*         device_info,
                                              VulkanDeferredOperationKHRInfo* deferred_operation_info);

    VkDeviceAddress
    OverrideGetBufferDeviceAddress(PFN_vkGetBufferDeviceAddress                                   func,
                                   VkDeviceAddress                                                original_result,
                                   const VulkanDeviceInfo*                                        device_info,
                                   const StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);

    void OverrideGetAccelerationStructureDeviceAddressKHR(
        PFN_vkGetAccelerationStructureDeviceAddressKHR                                   func,
        VkDeviceAddress                                                                  original_result,
        const VulkanDeviceInfo*                                                          device_info,
        const StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo);

    VkResult OverrideGetRayTracingShaderGroupHandlesKHR(PFN_vkGetRayTracingShaderGroupHandlesKHR func,
                                                        VkResult                                 original_result,
                                                        const VulkanDeviceInfo*                  device_info,
                                                        const VulkanPipelineInfo*                pipeline_info,
                                                        uint32_t                                 firstGroup,
                                                        uint32_t                                 groupCount,
                                                        size_t                                   dataSize,
                                                        PointerDecoder<uint8_t>*                 pData);
    VkResult OverrideGetAndroidHardwareBufferPropertiesANDROID(
        PFN_vkGetAndroidHardwareBufferPropertiesANDROID                         func,
        VkResult                                                                original_result,
        const VulkanDeviceInfo*                                                 device_info,
        const struct AHardwareBuffer*                                           hardware_buffer,
        StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties);

    void ClearCommandBufferInfo(VulkanCommandBufferInfo* command_buffer_info);

    VkResult OverrideBeginCommandBuffer(PFN_vkBeginCommandBuffer                                func,
                                        uint64_t                                                index,
                                        VkResult                                                original_result,
                                        VulkanCommandBufferInfo*                                command_buffer_info,
                                        StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* begin_info_decoder);

    VkResult OverrideResetCommandBuffer(PFN_vkResetCommandBuffer  func,
                                        VkResult                  original_result,
                                        VulkanCommandBufferInfo*  command_buffer_info,
                                        VkCommandBufferResetFlags flags);

    VkResult OverrideResetCommandPool(PFN_vkResetCommandPool  func,
                                      VkResult                original_result,
                                      const VulkanDeviceInfo* device_info,
                                      VulkanCommandPoolInfo*  pool_info,
                                      VkCommandPoolResetFlags flags);

    void OverrideDestroyCommandPool(PFN_vkDestroyCommandPool                             func,
                                    const VulkanDeviceInfo*                              device_info,
                                    VulkanCommandPoolInfo*                               pool_info,
                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideCmdDebugMarkerInsertEXT(PFN_vkCmdDebugMarkerInsertEXT                             func,
                                         VulkanCommandBufferInfo*                                  command_buffer_info,
                                         StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* marker_info_decoder);

    void OverrideCmdInsertDebugUtilsLabelEXT(PFN_vkCmdInsertDebugUtilsLabelEXT                   func,
                                             VulkanCommandBufferInfo*                            command_buffer_info,
                                             StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* label_info_decoder);

    VkResult OverrideWaitSemaphores(PFN_vkWaitSemaphores                                     func,
                                    VkResult                                                 original_result,
                                    const VulkanDeviceInfo*                                  device_info,
                                    const StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pInfo,
                                    uint64_t                                                 timeout);

    VkResult OverrideAcquireProfilingLockKHR(PFN_vkAcquireProfilingLockKHR func,
                                             VkResult                      original_result,
                                             const VulkanDeviceInfo*       device_info,
                                             const StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo);

    VkResult OverrideWaitForPresentKHR(PFN_vkWaitForPresentKHR func,
                                       VkResult                original_result,
                                       const VulkanDeviceInfo* device_info,
                                       VulkanSwapchainKHRInfo* swapchain_info,
                                       uint64_t                presentid,
                                       uint64_t                timeout);

    void OverrideCmdBeginRenderPass(PFN_vkCmdBeginRenderPass                             func,
                                    VulkanCommandBufferInfo*                             command_buffer_info,
                                    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* render_pass_begin_info_decoder,
                                    VkSubpassContents                                    contents);

    void
    OverrideCmdTraceRaysKHR(PFN_vkCmdTraceRaysKHR                                          func,
                            VulkanCommandBufferInfo*                                       command_buffer_info,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
                            uint32_t                                                       width,
                            uint32_t                                                       height,
                            uint32_t                                                       depth);

    void
    OverrideCmdBeginRenderPass2(PFN_vkCmdBeginRenderPass2                            func,
                                VulkanCommandBufferInfo*                             command_buffer_info,
                                StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* render_pass_begin_info_decoder,
                                StructPointerDecoder<Decoded_VkSubpassBeginInfo>*    subpass_begin_info_decode);

    VkResult OverrideCreateImageView(PFN_vkCreateImageView                                func,
                                     VkResult                                             original_result,
                                     const VulkanDeviceInfo*                              device_info,
                                     StructPointerDecoder<Decoded_VkImageViewCreateInfo>* create_info_decoder,
                                     StructPointerDecoder<Decoded_VkAllocationCallbacks>* allocator_decoder,
                                     HandlePointerDecoder<VkImageView>*                   view_decoder);

    VkResult OverrideCreateFramebuffer(PFN_vkCreateFramebuffer                                func,
                                       VkResult                                               original_result,
                                       const VulkanDeviceInfo*                                device_info,
                                       StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* create_info_decoder,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>*   allocator_decoder,
                                       HandlePointerDecoder<VkFramebuffer>*                   frame_buffer_decoder);

    void OverrideFrameBoundaryANDROID(PFN_vkFrameBoundaryANDROID func,
                                      const VulkanDeviceInfo*    device_info,
                                      const VulkanSemaphoreInfo* semaphore_info,
                                      const VulkanImageInfo*     image_info);

    void OverrideUpdateDescriptorSets(PFN_vkUpdateDescriptorSets                          func,
                                      const VulkanDeviceInfo*                             device_info,
                                      uint32_t                                            descriptor_write_count,
                                      StructPointerDecoder<Decoded_VkWriteDescriptorSet>* p_descriptor_writes,
                                      uint32_t                                            descriptor_copy_count,
                                      StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  p_pescriptor_copies);

    VkResult
    OverrideCreateGraphicsPipelines(PFN_vkCreateGraphicsPipelines  func,
                                    VkResult                       original_result,
                                    const VulkanDeviceInfo*        device_info,
                                    const VulkanPipelineCacheInfo* pipeline_cache_info,
                                    uint32_t                       create_info_count,
                                    const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
                                    HandlePointerDecoder<VkPipeline>*                                 pPipelines);

    VkResult
    OverrideCreateComputePipelines(PFN_vkCreateComputePipelines                                     func,
                                   VkResult                                                         original_result,
                                   const VulkanDeviceInfo*                                          device_info,
                                   const VulkanPipelineCacheInfo*                                   pipeline_cache_info,
                                   uint32_t                                                         create_info_count,
                                   const StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
                                   const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                   HandlePointerDecoder<VkPipeline>*                                pPipelines);

    VkResult OverrideCreateShadersEXT(PFN_vkCreateShadersEXT                                     func,
                                      VkResult                                                   original_result,
                                      const VulkanDeviceInfo*                                    device_info,
                                      uint32_t                                                   create_info_count,
                                      const StructPointerDecoder<Decoded_VkShaderCreateInfoEXT>* pCreateInfos,
                                      const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                      HandlePointerDecoder<VkShaderEXT>*                         pShaders);

    void OverrideDestroyPipeline(PFN_vkDestroyPipeline                                      func,
                                 const VulkanDeviceInfo*                                    device_info,
                                 VulkanPipelineInfo*                                        pipeline_info,
                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideDestroyRenderPass(PFN_vkDestroyRenderPass                                    func,
                                   const VulkanDeviceInfo*                                    device_info,
                                   VulkanRenderPassInfo*                                      renderpass_info,
                                   const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideDestroyShaderModule(PFN_vkDestroyShaderModule                                  func,
                                     const VulkanDeviceInfo*                                    device_info,
                                     VulkanShaderModuleInfo*                                    shader_module_info,
                                     const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    std::function<handle_create_result_t<VkPipeline>()>
    AsyncCreateGraphicsPipelines(const ApiCallInfo&                                          call_info,
                                 VkResult                                                    returnValue,
                                 const VulkanDeviceInfo*                                     device_info,
                                 const VulkanPipelineCacheInfo*                              pipeline_cache_info,
                                 uint32_t                                                    createInfoCount,
                                 StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
                                 StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
                                 HandlePointerDecoder<VkPipeline>*                           pPipelines);

    std::function<handle_create_result_t<VkPipeline>()>
    AsyncCreateComputePipelines(const ApiCallInfo&                                         call_info,
                                VkResult                                                   returnValue,
                                const VulkanDeviceInfo*                                    device_info,
                                const VulkanPipelineCacheInfo*                             pipeline_cache_info,
                                uint32_t                                                   createInfoCount,
                                StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
                                StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                HandlePointerDecoder<VkPipeline>*                          pPipelines);

    std::function<handle_create_result_t<VkShaderEXT>()>
    AsyncCreateShadersEXT(const ApiCallInfo&                                   call_info,
                          VkResult                                             returnValue,
                          const VulkanDeviceInfo*                              device_info,
                          uint32_t                                             createInfoCount,
                          StructPointerDecoder<Decoded_VkShaderCreateInfoEXT>* pCreateInfos,
                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                          HandlePointerDecoder<VkShaderEXT>*                   pShaders);

    const VulkanReplayOptions options_;

    VulkanReplayDumpResources resource_dumper;

  private:
    void RaiseFatalError(const char* message) const;

    void InitializeLoader();

    void AddInstanceTable(VkInstance instance);

    void AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa);

    PFN_vkGetDeviceProcAddr GetDeviceAddrProc(VkPhysicalDevice physical_device);

    PFN_vkCreateDevice GetCreateDeviceProc(VkPhysicalDevice physical_device);

    void SetInstancePhysicalDeviceEntries(VulkanInstanceInfo*     instance_info,
                                          size_t                  capture_device_count,
                                          const format::HandleId* capture_devices,
                                          size_t                  replay_device_count,
                                          const VkPhysicalDevice* replay_devices);

    void CheckReplayDeviceInfo(VulkanPhysicalDeviceInfo* physical_device_info);

    void SetPhysicalDeviceInstanceInfo(VulkanInstanceInfo*       instance_info,
                                       VulkanPhysicalDeviceInfo* physical_device_info,
                                       VkPhysicalDevice          replay_device);

    void SetPhysicalDeviceProperties(VulkanPhysicalDeviceInfo*         physical_device_info,
                                     const VkPhysicalDeviceProperties* capture_properties,
                                     const VkPhysicalDeviceProperties* replay_properties);

    void SetPhysicalDeviceProperties(VulkanPhysicalDeviceInfo*          physical_device_info,
                                     const VkPhysicalDeviceProperties2* capture_properties,
                                     const VkPhysicalDeviceProperties2* replay_properties);

    void SetPhysicalDeviceMemoryProperties(VulkanPhysicalDeviceInfo*               physical_device_info,
                                           const VkPhysicalDeviceMemoryProperties* capture_properties,
                                           const VkPhysicalDeviceMemoryProperties* replay_properties);

    // Can override PhysicalDeviceInfo::handle and PhysicalDeviceInfo::replay_device_info based on comparison between
    // capture and replay physical device properties or GPU override settings.
    void SelectPhysicalDevice(VulkanPhysicalDeviceInfo* physical_device_info);

    void SelectPhysicalDeviceGroup(VulkanPhysicalDeviceInfo*            physical_device_info,
                                   const std::vector<format::HandleId>& capture_device_group,
                                   std::vector<VkPhysicalDevice>&       replay_device_group);

    bool GetOverrideDevice(VulkanInstanceInfo* instance_info, VulkanPhysicalDeviceInfo* physical_device_info);

    bool GetOverrideDeviceGroup(VulkanInstanceInfo*            instance_info,
                                VulkanPhysicalDeviceInfo*      physical_device_info,
                                std::vector<VkPhysicalDevice>& replay_device_group);

    void GetMatchingDevice(VulkanInstanceInfo* instance_info, VulkanPhysicalDeviceInfo* physical_device_info);

    void GetMatchingDeviceGroup(VulkanInstanceInfo*                  instance_info,
                                VulkanPhysicalDeviceInfo*            physical_device_info,
                                const std::vector<format::HandleId>& capture_device_group,
                                std::vector<VkPhysicalDevice>&       replay_device_group);

    void CheckPhysicalDeviceCompatibility(VulkanPhysicalDeviceInfo* physical_device_info);

    void CheckPhysicalDeviceGroupCompatibility(VulkanInstanceInfo*                  instance_info,
                                               const std::vector<format::HandleId>& capture_device_group,
                                               const std::vector<VkPhysicalDevice>& replay_device_group);

    bool CheckTrimDeviceExtensions(VkPhysicalDevice physical_device, std::vector<std::string>* extensions);

    void InitializeResourceAllocator(const VulkanPhysicalDeviceInfo* physical_device_info,
                                     VkDevice                        device,
                                     const std::vector<std::string>& enabled_device_extensions,
                                     VulkanResourceAllocator*        allocator);

    void MapDescriptorUpdateTemplateHandles(const VulkanDescriptorUpdateTemplateInfo* update_template_info,
                                            DescriptorUpdateTemplateDecoder*          decoder);

    void GetImportedSemaphores(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                               std::vector<const VulkanSemaphoreInfo*>* imported_semaphores);

    void GetImportedSemaphores(const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
                               std::vector<const VulkanSemaphoreInfo*>*                   imported_semaphores);

    void SignalShadowSemaphore(VulkanSemaphoreInfo*                     semaphore_info,
                               std::vector<const VulkanSemaphoreInfo*>* shadow_semaphores);

    void GetShadowSemaphores(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                             std::vector<const VulkanSemaphoreInfo*>* shadow_semaphores);

    void GetShadowSemaphores(const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
                             std::vector<const VulkanSemaphoreInfo*>*                   shadow_semaphores);

    void TrackSemaphoreForwardProgress(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                                       std::vector<const VulkanSemaphoreInfo*>* removed_semaphores);

    void TrackSemaphoreForwardProgress(const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
                                       std::vector<const VulkanSemaphoreInfo*>*                   removed_semaphores);

    void GetNonForwardProgress(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                               std::vector<const VulkanSemaphoreInfo*>* non_forward_progress_semaphores);

    void GetNonForwardProgress(const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
                               std::vector<const VulkanSemaphoreInfo*>* non_forward_progress_semaphores);

    VkResult CreateSwapchainImage(const VulkanDeviceInfo*  device_info,
                                  const VkImageCreateInfo* image_create_info,
                                  VkImage*                 image,
                                  VulkanImageInfo*         image_info);

    void ProcessCreateInstanceDebugCallbackInfo(const Decoded_VkInstanceCreateInfo* instance_info);

    void ProcessSwapchainFullScreenExclusiveInfo(const Decoded_VkSwapchainCreateInfoKHR* swapchain_info);

    void
    ProcessImportAndroidHardwareBufferInfo(const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo);

    void SetSwapchainWindowSize(const Decoded_VkSwapchainCreateInfoKHR* swapchain_info);

    void InitializeScreenshotHandler();

    void WriteScreenshots(const Decoded_VkPresentInfoKHR* meta_info) const;

    bool CheckCommandBufferInfoForFrameBoundary(const VulkanCommandBufferInfo* command_buffer_info);
    bool CheckPNextChainForFrameBoundary(const VulkanDeviceInfo* device_info, const PNextNode* pnext);

    void UpdateDescriptorSetInfoWithTemplate(VulkanDescriptorSetInfo*                  desc_set_info,
                                             const VulkanDescriptorUpdateTemplateInfo* template_info,
                                             const DescriptorUpdateTemplateDecoder*    decoder) const;

    VulkanDeviceAddressTracker& GetDeviceAddressTracker(VkDevice device);

    [[nodiscard]] std::vector<std::unique_ptr<char[]>> ReplaceShaders(uint32_t                      create_info_count,
                                                                      VkGraphicsPipelineCreateInfo* create_infos,
                                                                      const format::HandleId*       pipelines) const;

    [[nodiscard]] std::vector<std::unique_ptr<char[]>> ReplaceShaders(uint32_t                create_info_count,
                                                                      VkShaderCreateInfoEXT*  create_infos,
                                                                      const format::HandleId* shaders) const;

  private:
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
        uint32_t height;
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
    util::platform::LibraryHandle                                              loader_handle_;
    PFN_vkGetInstanceProcAddr                                                  get_instance_proc_addr_;
    PFN_vkCreateInstance                                                       create_instance_proc_;
    std::unordered_map<encode::VulkanDispatchKey, PFN_vkGetDeviceProcAddr>     get_device_proc_addrs_;
    std::unordered_map<encode::VulkanDispatchKey, PFN_vkCreateDevice>          create_device_procs_;
    std::unordered_map<encode::VulkanDispatchKey, encode::VulkanInstanceTable> instance_tables_;
    std::unordered_map<encode::VulkanDispatchKey, encode::VulkanDeviceTable>   device_tables_;
    std::function<void(const char*)>                                           fatal_error_handler_;
    std::shared_ptr<application::Application>                                  application_;
    VulkanObjectInfoTable                                                      object_info_table_;
    bool                                                                       loading_trim_state_;
    bool                                                                       replaying_trimmed_capture_;
    SwapchainImageTracker                                                      swapchain_image_tracker_;
    HardwareBufferMap                                                          hardware_buffers_;
    HardwareBufferMemoryMap                                                    hardware_buffer_memory_info_;
    std::unique_ptr<ScreenshotHandler>                                         screenshot_handler_;
    std::unique_ptr<VulkanSwapchain>                                           swapchain_;
    std::string                                                                screenshot_file_prefix_;
    graphics::FpsInfo*                                                         fps_info_;

    std::unordered_map<VkDevice, decode::VulkanDeviceAddressTracker> _device_address_trackers;

    util::ThreadPool main_thread_queue_;
    util::ThreadPool background_queue_;

    //! async_tracked_handle_asset_t groups assets used by tracked async-dependencies
    struct async_tracked_handle_asset_t
    {
        //! function to synchronize (blocking wait) with parent asynchronous-task
        std::function<void()> sync_fn;

        //! function used to defer deletion of a tracked async-dependency
        std::function<void()> destroy_fn;
    };
    //! stores handles used/referenced by currently running async tasks
    std::unordered_map<format::HandleId, async_tracked_handle_asset_t> async_tracked_handles_;

    //! decide whether to sync/wait or defer deletion of handles used by currently running async tasks
    static constexpr bool async_defer_deletion_ = false;

    // Imported semaphores are semaphores that are used to track external memory.
    // During replay, the external memory is not present (we have no Fds or handles to valid
    // data), so we ignore those semaphores when they are encountered.
    bool have_imported_semaphores_;

    // Used to track if any shadow sync objects are active to avoid checking if not needed.
    // SHadowed objects are ignored when they would have been unsignaled (waited on).
    // [Currently set during a call to AcquireNextImage if the VkSurfaceKHR is VK_NULL_HANDLE.
    std::unordered_set<VkSemaphore> shadow_semaphores_;
    std::unordered_set<VkFence>     shadow_fences_;

    // Used to track allocated external memory if replay uses VkImportMemoryHostPointerInfoEXT
    std::unordered_map<VkDeviceMemory, std::pair<void*, size_t>> external_memory_;

    // Temporary data used by OverrideQueuePresentKHR
    std::vector<VkSwapchainKHR>       valid_swapchains_;
    std::vector<uint32_t>             modified_image_indices_;
    std::vector<uint32_t>             modified_device_masks_;
    std::vector<VkPresentRegionKHR>   modified_regions_;
    std::vector<VkPresentTimeGOOGLE>  modified_times_;
    std::vector<const VulkanSemaphoreInfo*> removed_semaphores_;
    std::unordered_set<uint32_t>      removed_swapchain_indices_;
    std::vector<uint32_t>             capture_image_indices_;
    std::vector<VulkanSwapchainKHRInfo*>    swapchain_infos_;

  protected:
    // Used by pipeline cache handling, there are the following two cases for the flag to be set:
    //
    //    1. Replay with command line option --opcd or --omit-pipeline-cache-data and some
    //       pipeline cache data was really omitted.
    //
    //    2. Replay without command line option --opcd or --omit-pipeline-cache-data and there is
    //       at least one vkCreatePipelineCache call with valid initial pipeline cache data and
    //       the initial cache data has no corresponding replay time cache data.
    bool omitted_pipeline_cache_data_;

    // Temporary data used by pipeline cache data handling
    // The following capture time data used for calling VisitPipelineCacheInfo as input parameters
    // , replay time data used as output result.
    uint32_t             capture_pipeline_cache_data_hash_ = 0;
    uint32_t             capture_pipeline_cache_data_size_ = 0;
    void*                capture_pipeline_cache_data_;
    bool                 matched_replay_cache_data_exist_ = false;
    std::vector<uint8_t> matched_replay_cache_data_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H
