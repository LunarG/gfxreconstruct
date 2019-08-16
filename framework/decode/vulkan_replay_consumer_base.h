/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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
#include "decode/vulkan_object_mapper.h"
#include "decode/vulkan_replay_options.h"
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
#include <string>
#include <unordered_map>
#include <vector>

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
    ProcessSetSwapchainImageStateCommand(format::HandleId                                     device_id,
                                         format::HandleId                                     swapchain_id,
                                         uint32_t                                             queue_family_index,
                                         const std::vector<format::SwapchainImageStateEntry>& image_info) override;

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
    const VulkanObjectMapper& GetObjectMapper() const { return object_mapper_; }

    const encode::InstanceTable* GetInstanceTable(const void* handle) const;

    const encode::DeviceTable* GetDeviceTable(const void* handle) const;

    void* PreProcessExternalObject(uint64_t object_id, format::ApiCallId call_id, const char* call_name);

    void PostProcessExternalObject(const PointerDecoder<uint64_t>& object_id,
                                   void*                           object,
                                   format::ApiCallId               call_id,
                                   const char*                     call_name);

    const VkAllocationCallbacks*
    GetAllocationCallbacks(const StructPointerDecoder<Decoded_VkAllocationCallbacks>& original_callbacks);

    void CheckResult(const char* func_name, VkResult original, VkResult replay);

    template <typename T>
    T* AllocateArray(size_t len) const
    {
        return new T[len];
    }

    template <typename T>
    T* AllocateArray(size_t len, const T& init) const
    {
        T* data = new T[len];

        for (size_t i = 0; i < len; ++i)
        {
            data[i] = init;
        }

        return data;
    }

    template <typename T>
    void FreeArray(T** arr) const
    {
        if ((*arr) != nullptr)
        {
            delete[](*arr);
            *arr = nullptr;
        }
    }

    template <typename T>
    void MapHandles(const format::HandleId* ids,
                    size_t                  ids_len,
                    T*                      handles,
                    size_t                  handles_len,
                    T (VulkanObjectMapper::*MapFunc)(format::HandleId) const) const
    {
        if ((ids != nullptr) && (handles != nullptr))
        {
            // The array sizes are expected to be the same for mapping operations.
            assert(ids_len == handles_len);
            for (size_t i = 0; i < handles_len; ++i)
            {
                handles[i] = (object_mapper_.*MapFunc)(ids[i]);
            }
        }
    }

    template <typename T>
    void AddHandles(const format::HandleId* ids,
                    size_t                  ids_len,
                    const T*                handles,
                    size_t                  handles_len,
                    void (VulkanObjectMapper::*AddFunc)(format::HandleId, T))
    {
        if ((ids != nullptr) && (handles != nullptr))
        {
            // TODO: Improved handling of array size mismatch.
            size_t len = std::min(ids_len, handles_len);
            for (size_t i = 0; i < len; ++i)
            {
                (object_mapper_.*AddFunc)(ids[i], handles[i]);
            }
        }
    }

    //
    // Replay function overrides provided to the replay consumer code generator with replay_overrides.json
    //

    VkResult OverrideCreateInstance(VkResult                                original_result,
                                    const VkInstanceCreateInfo*             pCreateInfo,
                                    const VkAllocationCallbacks*            pAllocator,
                                    const HandlePointerDecoder<VkInstance>& original_instance,
                                    VkInstance*                             pInstance);

    VkResult OverrideCreateDevice(VkResult                              original_result,
                                  VkPhysicalDevice                      physicalDevice,
                                  const VkDeviceCreateInfo*             pCreateInfo,
                                  const VkAllocationCallbacks*          pAllocator,
                                  const HandlePointerDecoder<VkDevice>& original_device,
                                  VkDevice*                             pDevice);

    VkResult OverrideEnumeratePhysicalDevices(PFN_vkEnumeratePhysicalDevices                func,
                                              VkResult                                      returnValue,
                                              VkInstance                                    instance,
                                              const PointerDecoder<uint32_t>&               original_device_count,
                                              uint32_t*                                     pPhysicalDeviceCount,
                                              const HandlePointerDecoder<VkPhysicalDevice>& original_devices,
                                              VkPhysicalDevice*                             pPhysicalDevices);

    void OverrideGetPhysicalDeviceProperties(
        PFN_vkGetPhysicalDeviceProperties                               func,
        VkPhysicalDevice                                                physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>& original_properties,
        VkPhysicalDeviceProperties*                                     pProperties);

    void OverrideGetPhysicalDeviceProperties2(
        PFN_vkGetPhysicalDeviceProperties2                               func,
        VkPhysicalDevice                                                 physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& original_properties,
        VkPhysicalDeviceProperties2*                                     pProperties);

    void OverrideGetPhysicalDeviceProperties2KHR(
        PFN_vkGetPhysicalDeviceProperties2KHR                               func,
        VkPhysicalDevice                                                    physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2KHR>& original_properties,
        VkPhysicalDeviceProperties2KHR*                                     pProperties);

    VkResult OverrideWaitForFences(PFN_vkWaitForFences func,
                                   VkResult            original_result,
                                   VkDevice            device,
                                   uint32_t            fenceCount,
                                   const VkFence*      pFences,
                                   VkBool32            waitAll,
                                   uint64_t            timeout);

    VkResult
    OverrideGetFenceStatus(PFN_vkGetFenceStatus func, VkResult original_result, VkDevice device, VkFence fence);

    VkResult
    OverrideGetEventStatus(PFN_vkGetEventStatus func, VkResult original_result, VkDevice device, VkEvent event);

    VkResult OverrideGetQueryPoolResults(PFN_vkGetQueryPoolResults      func,
                                         VkResult                       original_result,
                                         VkDevice                       device,
                                         VkQueryPool                    queryPool,
                                         uint32_t                       firstQuery,
                                         uint32_t                       queryCount,
                                         size_t                         dataSize,
                                         const PointerDecoder<uint8_t>& original_data,
                                         void*                          pData,
                                         VkDeviceSize                   stride,
                                         VkQueryResultFlags             flags);

    VkResult OverrideAllocateCommandBuffers(PFN_vkAllocateCommandBuffers                 func,
                                            VkResult                                     original_result,
                                            VkDevice                                     device,
                                            const VkCommandBufferAllocateInfo*           pAllocateInfo,
                                            const HandlePointerDecoder<VkCommandBuffer>& original_command_buffers,
                                            VkCommandBuffer*                             pCommandBuffers);

    VkResult OverrideAllocateDescriptorSets(PFN_vkAllocateDescriptorSets                 func,
                                            VkResult                                     original_result,
                                            VkDevice                                     device,
                                            const VkDescriptorSetAllocateInfo*           pAllocateInfo,
                                            const HandlePointerDecoder<VkDescriptorSet>& original_descriptor_sets,
                                            VkDescriptorSet*                             pDescriptorSets);

    VkResult OverrideAllocateMemory(PFN_vkAllocateMemory                        func,
                                    VkResult                                    original_result,
                                    VkDevice                                    device,
                                    const VkMemoryAllocateInfo*                 pAllocateInfo,
                                    const VkAllocationCallbacks*                pAllocator,
                                    const HandlePointerDecoder<VkDeviceMemory>& original_memory,
                                    VkDeviceMemory*                             pMemory);

    VkResult OverrideMapMemory(PFN_vkMapMemory                 func,
                               VkResult                        original_result,
                               VkDevice                        device,
                               VkDeviceMemory                  memory,
                               VkDeviceSize                    offset,
                               VkDeviceSize                    size,
                               VkMemoryMapFlags                flags,
                               const PointerDecoder<uint64_t>& original_data,
                               void**                          ppData);

    void OverrideUnmapMemory(PFN_vkUnmapMemory func, VkDevice device, VkDeviceMemory memory);

    void OverrideFreeMemory(PFN_vkFreeMemory             func,
                            VkDevice                     device,
                            VkDeviceMemory               memory,
                            const VkAllocationCallbacks* pAllocator);

    VkResult OverrideCreateDescriptorUpdateTemplate(
        PFN_vkCreateDescriptorUpdateTemplate                    func,
        VkResult                                                original_result,
        VkDevice                                                device,
        const VkDescriptorUpdateTemplateCreateInfo*             pCreateInfo,
        const VkAllocationCallbacks*                            pAllocator,
        const HandlePointerDecoder<VkDescriptorUpdateTemplate>& original_update_template,
        VkDescriptorUpdateTemplate*                             pDescriptorUpdateTemplate);

    void OverrideDestroyDescriptorUpdateTemplate(PFN_vkDestroyDescriptorUpdateTemplate func,
                                                 VkDevice                              device,
                                                 VkDescriptorUpdateTemplate            descriptorUpdateTemplate,
                                                 const VkAllocationCallbacks*          pAllocator);

    VkResult OverrideCreatePipelineCache(PFN_vkCreatePipelineCache                    func,
                                         VkResult                                     original_result,
                                         VkDevice                                     device,
                                         const VkPipelineCacheCreateInfo*             pCreateInfo,
                                         const VkAllocationCallbacks*                 pAllocator,
                                         const HandlePointerDecoder<VkPipelineCache>& original_pipeline_cache,
                                         VkPipelineCache*                             pPipelineCache);

    VkResult OverrideAcquireNextImageKHR(PFN_vkAcquireNextImageKHR       func,
                                         VkResult                        original_result,
                                         VkDevice                        device,
                                         VkSwapchainKHR                  swapchain,
                                         uint64_t                        timeout,
                                         VkSemaphore                     semaphore,
                                         VkFence                         fence,
                                         const PointerDecoder<uint32_t>& original_index,
                                         uint32_t*                       pImageIndex);

    VkResult OverrideAcquireNextImage2KHR(PFN_vkAcquireNextImage2KHR       func,
                                          VkResult                         original_result,
                                          VkDevice                         device,
                                          const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                          const PointerDecoder<uint32_t>&  original_index,
                                          uint32_t*                        pImageIndex);

    // Window/Surface related overrides, which can transform the window/surface type from the platform
    // specific type found in the trace file to the platform specific type used for replay.
    VkResult OverrideCreateAndroidSurfaceKHR(PFN_vkCreateAndroidSurfaceKHR             func,
                                             VkResult                                  original_result,
                                             VkInstance                                instance,
                                             const VkAndroidSurfaceCreateInfoKHR*      pCreateInfo,
                                             const VkAllocationCallbacks*              pAllocator,
                                             const HandlePointerDecoder<VkSurfaceKHR>& original_surface,
                                             VkSurfaceKHR*                             pSurface);

    VkResult OverrideCreateWin32SurfaceKHR(PFN_vkCreateWin32SurfaceKHR               func,
                                           VkResult                                  original_result,
                                           VkInstance                                instance,
                                           const VkWin32SurfaceCreateInfoKHR*        pCreateInfo,
                                           const VkAllocationCallbacks*              pAllocator,
                                           const HandlePointerDecoder<VkSurfaceKHR>& original_surface,
                                           VkSurfaceKHR*                             pSurface);

    VkBool32
    OverrideGetPhysicalDeviceWin32PresentationSupportKHR(PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
                                                         VkPhysicalDevice physicalDevice,
                                                         uint32_t         queueFamilyIndex);

    VkResult OverrideCreateXcbSurfaceKHR(PFN_vkCreateXcbSurfaceKHR                 func,
                                         VkResult                                  original_result,
                                         VkInstance                                instance,
                                         const VkXcbSurfaceCreateInfoKHR*          pCreateInfo,
                                         const VkAllocationCallbacks*              pAllocator,
                                         const HandlePointerDecoder<VkSurfaceKHR>& original_surface,
                                         VkSurfaceKHR*                             pSurface);

    VkBool32 OverrideGetPhysicalDeviceXcbPresentationSupportKHR(PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
                                                                VkPhysicalDevice  physicalDevice,
                                                                uint32_t          queueFamilyIndex,
                                                                xcb_connection_t* connection,
                                                                xcb_visualid_t    visual_id);

    VkResult OverrideCreateXlibSurfaceKHR(PFN_vkCreateXlibSurfaceKHR                func,
                                          VkResult                                  original_result,
                                          VkInstance                                instance,
                                          const VkXlibSurfaceCreateInfoKHR*         pCreateInfo,
                                          const VkAllocationCallbacks*              pAllocator,
                                          const HandlePointerDecoder<VkSurfaceKHR>& original_surface,
                                          VkSurfaceKHR*                             pSurface);

    VkBool32 OverrideGetPhysicalDeviceXlibPresentationSupportKHR(PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
                                                                 VkPhysicalDevice physicalDevice,
                                                                 uint32_t         queueFamilyIndex,
                                                                 Display*         dpy,
                                                                 VisualID         visualID);

    VkResult OverrideCreateWaylandSurfaceKHR(PFN_vkCreateWaylandSurfaceKHR             func,
                                             VkResult                                  original_result,
                                             VkInstance                                instance,
                                             const VkWaylandSurfaceCreateInfoKHR*      pCreateInfo,
                                             const VkAllocationCallbacks*              pAllocator,
                                             const HandlePointerDecoder<VkSurfaceKHR>& original_surface,
                                             VkSurfaceKHR*                             pSurface);

    VkBool32
    OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
                                                           VkPhysicalDevice   physicalDevice,
                                                           uint32_t           queueFamilyIndex,
                                                           struct wl_display* display);

    void OverrideDestroySurfaceKHR(PFN_vkDestroySurfaceKHR      func,
                                   VkInstance                   instance,
                                   VkSurfaceKHR                 surface,
                                   const VkAllocationCallbacks* pAllocator);

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

    VkResult CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* surface);

    void MapDescriptorUpdateTemplateHandles(VkDescriptorUpdateTemplate             update_template,
                                            const DescriptorUpdateTemplateDecoder& decoder);

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

    typedef std::unordered_map<VkSurfaceKHR, Window*>                      WindowMap;
    typedef std::unordered_map<VkDeviceMemory, void*>                      MappedMemoryMap;
    typedef std::unordered_map<VkInstance, InstanceDevices>                InstanceDeviceMap;
    typedef std::unordered_map<VkPhysicalDevice, PhysicalDeviceProperties> PhysicalDevicePropertiesMap;

    // Map the descriptor update template handle ID read from the capture file to an array of descriptor image types.
    typedef std::vector<VkDescriptorType>                                        DescriptorImageTypes;
    typedef std::unordered_map<VkDescriptorUpdateTemplate, DescriptorImageTypes> DescriptorUpdateTemplateImageTypes;

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
    VulkanObjectMapper                                               object_mapper_;
    WindowMap                                                        window_map_;
    MappedMemoryMap                                                  memory_map_;
    ReplayOptions                                                    options_;
    InstanceDeviceMap                                                instance_devices_;
    PhysicalDevicePropertiesMap                                      device_properties_;
    DescriptorUpdateTemplateImageTypes                               descriptor_update_template_image_types_;
    SwapchainImageTracker                                            swapchain_image_tracker_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H
