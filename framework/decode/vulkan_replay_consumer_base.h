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

#ifndef BRIMSTONE_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H
#define BRIMSTONE_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H

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

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

class VulkanReplayConsumerBase : public VulkanConsumer
{
  public:
    VulkanReplayConsumerBase(WindowFactory* window_factory);

    virtual ~VulkanReplayConsumerBase();

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
    void FreeArray(T** arr) const
    {
        if ((*arr) != nullptr)
        {
            delete[](*arr);
            *arr = nullptr;
        }
    }

    template <typename T>
    void FreeArray(const T** arr) const
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

    VkResult OverrideCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator,
                                    VkInstance*                  pInstance);

    VkResult OverrideCreateDevice(VkPhysicalDevice             physicalDevice,
                                  const VkDeviceCreateInfo*    pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator,
                                  VkDevice*                    pDevice);

    VkResult OverrideWaitForFences(VkResult       original_result,
                                   VkDevice       device,
                                   uint32_t       fenceCount,
                                   const VkFence* pFences,
                                   VkBool32       waitAll,
                                   uint64_t       timeout);

    VkResult OverrideGetFenceStatus(VkResult original_result, VkDevice device, VkFence fence);

    VkResult OverrideGetEventStatus(VkResult original_result, VkDevice device, VkEvent event);

    VkResult OverrideGetQueryPoolResults(VkResult           original_result,
                                         VkDevice           device,
                                         VkQueryPool        queryPool,
                                         uint32_t           firstQuery,
                                         uint32_t           queryCount,
                                         size_t             dataSize,
                                         void*              pData,
                                         VkDeviceSize       stride,
                                         VkQueryResultFlags flags);

    VkResult OverrideMapMemory(VkDevice         device,
                               VkDeviceMemory   memory,
                               VkDeviceSize     offset,
                               VkDeviceSize     size,
                               VkMemoryMapFlags flags,
                               void**           ppData);

    void OverrideUnmapMemory(VkDevice device, VkDeviceMemory memory);

    void OverrideFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);

    VkResult OverrideCreateDescriptorUpdateTemplate(PFN_vkCreateDescriptorUpdateTemplate        func,
                                                    VkDevice                                    device,
                                                    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks*                pAllocator,
                                                    VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

    // Window/Surface related overrides, which can transform the window/surface type from the platform
    // specific type found in the trace file to the platform specific type used for replay.
    VkResult OverrideCreateWin32SurfaceKHR(VkInstance                         instance,
                                           const VkWin32SurfaceCreateInfoKHR* pCreateInfo,
                                           const VkAllocationCallbacks*       pAllocator,
                                           VkSurfaceKHR*                      pSurface);

    VkBool32 OverrideGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice,
                                                                  uint32_t         queueFamilyIndex);

    VkResult OverrideCreateXcbSurfaceKHR(VkInstance                       instance,
                                         const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                         const VkAllocationCallbacks*     pAllocator,
                                         VkSurfaceKHR*                    pSurface);

    VkBool32 OverrideGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice  physicalDevice,
                                                                uint32_t          queueFamilyIndex,
                                                                xcb_connection_t* connection,
                                                                xcb_visualid_t    visual_id);

    VkResult OverrideCreateXlibSurfaceKHR(VkInstance                        instance,
                                          const VkXlibSurfaceCreateInfoKHR* pCreateInfo,
                                          const VkAllocationCallbacks*      pAllocator,
                                          VkSurfaceKHR*                     pSurface);

    VkBool32 OverrideGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice,
                                                                 uint32_t         queueFamilyIndex,
                                                                 Display*         dpy,
                                                                 VisualID         visualID);

    VkResult OverrideCreateWaylandSurfaceKHR(VkInstance                           instance,
                                             const VkWaylandSurfaceCreateInfoKHR* pCreateInfo,
                                             const VkAllocationCallbacks*         pAllocator,
                                             VkSurfaceKHR*                        pSurface);

    VkBool32 OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice   physicalDevice,
                                                                    uint32_t           queueFamilyIndex,
                                                                    struct wl_display* display);

    void OverrideDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator);

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
            BRIMSTONE_UNREFERENCED_PARAMETER(consumer);
            return func(args...);
        }

        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, Pfn func, Args... args)
        {
            BRIMSTONE_UNREFERENCED_PARAMETER(consumer);
            BRIMSTONE_UNREFERENCED_PARAMETER(original_result);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            BRIMSTONE_UNREFERENCED_PARAMETER(original_result);
            return consumer->OverrideCreateInstance(args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkCreateDevice, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkCreateDevice func, Args... args)
        {
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            BRIMSTONE_UNREFERENCED_PARAMETER(original_result);
            return consumer->OverrideCreateDevice(args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkWaitForFences, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkWaitForFences func, Args... args)
        {
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideWaitForFences(original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkGetFenceStatus, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkGetFenceStatus func, Args... args)
        {
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideGetFenceStatus(original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkGetEventStatus, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkGetEventStatus func, Args... args)
        {
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideGetEventStatus(original_result, args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideGetQueryPoolResults(original_result, args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkMapMemory, Ret, Pfn>
    {
        template <typename... Args>
        static Ret
        Dispatch(VulkanReplayConsumerBase* consumer, VkResult original_result, PFN_vkMapMemory func, Args... args)
        {
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            BRIMSTONE_UNREFERENCED_PARAMETER(original_result);
            return consumer->OverrideMapMemory(args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkUnmapMemory, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer, PFN_vkUnmapMemory func, Args... args)
        {
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideUnmapMemory(args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkFreeMemory, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer, PFN_vkFreeMemory func, Args... args)
        {
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideFreeMemory(args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(original_result);
            return consumer->OverrideCreateDescriptorUpdateTemplate(func, args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(original_result);
            return consumer->OverrideCreateDescriptorUpdateTemplate(func, args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            BRIMSTONE_UNREFERENCED_PARAMETER(original_result);
            return consumer->OverrideCreateWin32SurfaceKHR(args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideGetPhysicalDeviceWin32PresentationSupportKHR(args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            BRIMSTONE_UNREFERENCED_PARAMETER(original_result);
            return consumer->OverrideCreateXcbSurfaceKHR(args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideGetPhysicalDeviceXcbPresentationSupportKHR(args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            BRIMSTONE_UNREFERENCED_PARAMETER(original_result);
            return consumer->OverrideCreateXlibSurfaceKHR(args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideGetPhysicalDeviceXlibPresentationSupportKHR(args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            BRIMSTONE_UNREFERENCED_PARAMETER(original_result);
            return consumer->OverrideCreateWaylandSurfaceKHR(args...);
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
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(args...);
        }
    };

    template <typename Ret, typename Pfn>
    struct Dispatcher<format::ApiCallId::ApiCall_vkDestroySurfaceKHR, Ret, Pfn>
    {
        template <typename... Args>
        static Ret Dispatch(VulkanReplayConsumerBase* consumer, PFN_vkDestroySurfaceKHR func, Args... args)
        {
            BRIMSTONE_UNREFERENCED_PARAMETER(func);
            return consumer->OverrideDestroySurfaceKHR(args...);
        }
    };
};

BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H
