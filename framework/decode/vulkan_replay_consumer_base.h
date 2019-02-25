/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "decode/pointer_decoder.h"
#include "decode/vulkan_object_mapper.h"
#include "decode/window.h"
#include "format/api_call_id.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <algorithm>
#include <cassert>
#include <functional>
#include <string>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayConsumerBase : public VulkanConsumer
{
  public:
    VulkanReplayConsumerBase(WindowFactory* window_factory);

    virtual ~VulkanReplayConsumerBase() override;

    void SetFatalErrorHandler(std::function<void(const char*)> handler) { fatal_error_handler_ = handler; }

    virtual void ProcessDisplayMessageCommand(const std::string& message) override;

    virtual void
    ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height) override;

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

  private:
    void RaiseFatalError(const char* message) const;

    VkResult CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* surface);

    VkResult OverrideCreateInstance(PFN_vkCreateInstance         func,
                                    VkResult                     original_result,
                                    const VkInstanceCreateInfo*  pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator,
                                    VkInstance*                  pInstance);

    VkResult OverrideCreateDevice(PFN_vkCreateDevice           func,
                                  VkResult                     original_result,
                                  VkPhysicalDevice             physicalDevice,
                                  const VkDeviceCreateInfo*    pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator,
                                  VkDevice*                    pDevice);

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

    VkResult OverrideGetQueryPoolResults(PFN_vkGetQueryPoolResults func,
                                         VkResult                  original_result,
                                         VkDevice                  device,
                                         VkQueryPool               queryPool,
                                         uint32_t                  firstQuery,
                                         uint32_t                  queryCount,
                                         size_t                    dataSize,
                                         void*                     pData,
                                         VkDeviceSize              stride,
                                         VkQueryResultFlags        flags);

    VkResult OverrideMapMemory(PFN_vkMapMemory  func,
                               VkResult         original_result,
                               VkDevice         device,
                               VkDeviceMemory   memory,
                               VkDeviceSize     offset,
                               VkDeviceSize     size,
                               VkMemoryMapFlags flags,
                               void**           ppData);

    void OverrideUnmapMemory(PFN_vkUnmapMemory func, VkDevice device, VkDeviceMemory memory);

    void OverrideFreeMemory(PFN_vkFreeMemory             func,
                            VkDevice                     device,
                            VkDeviceMemory               memory,
                            const VkAllocationCallbacks* pAllocator);

    VkResult OverrideCreateDescriptorUpdateTemplate(PFN_vkCreateDescriptorUpdateTemplate        func,
                                                    VkResult                                    original_result,
                                                    VkDevice                                    device,
                                                    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks*                pAllocator,
                                                    VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

    // Window/Surface related overrides, which can transform the window/surface type from the platform
    // specific type found in the trace file to the platform specific type used for replay.
    VkResult OverrideCreateAndroidSurfaceKHR(PFN_vkCreateAndroidSurfaceKHR        func,
                                             VkResult                             original_result,
                                             VkInstance                           instance,
                                             const VkAndroidSurfaceCreateInfoKHR* pCreateInfo,
                                             const VkAllocationCallbacks*         pAllocator,
                                             VkSurfaceKHR*                        pSurface);

    VkResult OverrideCreateWin32SurfaceKHR(PFN_vkCreateWin32SurfaceKHR        func,
                                           VkResult                           original_result,
                                           VkInstance                         instance,
                                           const VkWin32SurfaceCreateInfoKHR* pCreateInfo,
                                           const VkAllocationCallbacks*       pAllocator,
                                           VkSurfaceKHR*                      pSurface);

    VkBool32
    OverrideGetPhysicalDeviceWin32PresentationSupportKHR(PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
                                                         VkPhysicalDevice physicalDevice,
                                                         uint32_t         queueFamilyIndex);

    VkResult OverrideCreateXcbSurfaceKHR(PFN_vkCreateXcbSurfaceKHR        func,
                                         VkResult                         original_result,
                                         VkInstance                       instance,
                                         const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                         const VkAllocationCallbacks*     pAllocator,
                                         VkSurfaceKHR*                    pSurface);

    VkBool32 OverrideGetPhysicalDeviceXcbPresentationSupportKHR(PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
                                                                VkPhysicalDevice  physicalDevice,
                                                                uint32_t          queueFamilyIndex,
                                                                xcb_connection_t* connection,
                                                                xcb_visualid_t    visual_id);

    VkResult OverrideCreateXlibSurfaceKHR(PFN_vkCreateXlibSurfaceKHR        func,
                                          VkResult                          original_result,
                                          VkInstance                        instance,
                                          const VkXlibSurfaceCreateInfoKHR* pCreateInfo,
                                          const VkAllocationCallbacks*      pAllocator,
                                          VkSurfaceKHR*                     pSurface);

    VkBool32 OverrideGetPhysicalDeviceXlibPresentationSupportKHR(PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
                                                                 VkPhysicalDevice physicalDevice,
                                                                 uint32_t         queueFamilyIndex,
                                                                 Display*         dpy,
                                                                 VisualID         visualID);

    VkResult OverrideCreateWaylandSurfaceKHR(PFN_vkCreateWaylandSurfaceKHR        func,
                                             VkResult                             original_result,
                                             VkInstance                           instance,
                                             const VkWaylandSurfaceCreateInfoKHR* pCreateInfo,
                                             const VkAllocationCallbacks*         pAllocator,
                                             VkSurfaceKHR*                        pSurface);

    VkBool32
    OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
                                                           VkPhysicalDevice   physicalDevice,
                                                           uint32_t           queueFamilyIndex,
                                                           struct wl_display* display);

    void OverrideDestroySurfaceKHR(PFN_vkDestroySurfaceKHR      func,
                                   VkInstance                   instance,
                                   VkSurfaceKHR                 surface,
                                   const VkAllocationCallbacks* pAllocator);

    void MapDescriptorUpdateTemplateHandles(const DescriptorUpdateTemplateDecoder& decoder);

  private:
    typedef std::unordered_map<VkSurfaceKHR, Window*> WindowMap;
    typedef std::unordered_map<VkDeviceMemory, void*> MappedMemoryMap;

  private:
    std::function<void(const char*)> fatal_error_handler_;
    WindowFactory*                   window_factory_;
    VulkanObjectMapper               object_mapper_;
    WindowMap                        window_map_;
    MappedMemoryMap                  memory_map_;

  protected:
    template <format::ApiCallId Id, typename Ret, typename Pfn>
    struct Dispatcher
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer, Pfn func, Args... args)
        {
            GFXRECON_UNREFERENCED_PARAMETER(consumer);
            return func(args...);
        }

        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, Pfn func, Args... args)
        {
            GFXRECON_UNREFERENCED_PARAMETER(consumer);
            GFXRECON_UNREFERENCED_PARAMETER(original_result);
            return func(args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkCreateInstance, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkCreateInstance func, Args... args)
        {
            return consumer->OverrideCreateInstance(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkCreateDevice, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkCreateDevice func, Args... args)
        {
            return consumer->OverrideCreateDevice(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkWaitForFences, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkWaitForFences func, Args... args)
        {
            return consumer->OverrideWaitForFences(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkGetFenceStatus, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkGetFenceStatus func, Args... args)
        {
            return consumer->OverrideGetFenceStatus(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkGetEventStatus, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkGetEventStatus func, Args... args)
        {
            return consumer->OverrideGetEventStatus(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkGetQueryPoolResults, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer,
                            VkResult                  original_result,
                            PFN_vkGetQueryPoolResults func,
                            Args... args)
        {
            return consumer->OverrideGetQueryPoolResults(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkMapMemory, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkMapMemory func, Args... args)
        {
            return consumer->OverrideMapMemory(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkUnmapMemory, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer, PFN_vkUnmapMemory func, Args... args)
        {
            return consumer->OverrideUnmapMemory(func, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkFreeMemory, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer, PFN_vkFreeMemory func, Args... args)
        {
            return consumer->OverrideFreeMemory(func, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase*            consumer,
                            VkResult                             original_result,
                            PFN_vkCreateDescriptorUpdateTemplate func,
                            Args... args)
        {
            return consumer->OverrideCreateDescriptorUpdateTemplate(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase*               consumer,
                            VkResult                                original_result,
                            PFN_vkCreateDescriptorUpdateTemplateKHR func,
                            Args... args)
        {
            return consumer->OverrideCreateDescriptorUpdateTemplate(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase*     consumer,
                            VkResult                      original_result,
                            PFN_vkCreateAndroidSurfaceKHR func,
                            Args... args)
        {
            return consumer->OverrideCreateAndroidSurfaceKHR(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase*   consumer,
                            VkResult                    original_result,
                            PFN_vkCreateWin32SurfaceKHR func,
                            Args... args)
        {
            return consumer->OverrideCreateWin32SurfaceKHR(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase*                          consumer,
                            PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
                            Args... args)
        {
            return consumer->OverrideGetPhysicalDeviceWin32PresentationSupportKHR(func, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer,
                            VkResult                  original_result,
                            PFN_vkCreateXcbSurfaceKHR func,
                            Args... args)
        {
            return consumer->OverrideCreateXcbSurfaceKHR(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase*                        consumer,
                            PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
                            Args... args)
        {
            return consumer->OverrideGetPhysicalDeviceXcbPresentationSupportKHR(func, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase*  consumer,
                            VkResult                   original_result,
                            PFN_vkCreateXlibSurfaceKHR func,
                            Args... args)
        {
            return consumer->OverrideCreateXlibSurfaceKHR(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase*                         consumer,
                            PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
                            Args... args)
        {
            return consumer->OverrideGetPhysicalDeviceXlibPresentationSupportKHR(func, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase*     consumer,
                            VkResult                      original_result,
                            PFN_vkCreateWaylandSurfaceKHR func,
                            Args... args)
        {
            return consumer->OverrideCreateWaylandSurfaceKHR(func, original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase*                            consumer,
                            PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
                            Args... args)
        {
            return consumer->OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(func, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkDestroySurfaceKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer, PFN_vkDestroySurfaceKHR func, Args... args)
        {
            return consumer->OverrideDestroySurfaceKHR(func, args...);
        }
    };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H
