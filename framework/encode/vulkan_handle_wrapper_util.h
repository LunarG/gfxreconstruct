/*
** Copyright (c) 2019 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPER_UTIL_H
#define GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPER_UTIL_H

#include "encode/handle_unwrap_memory.h"
#include "encode/vulkan_handle_wrappers.h"
#include "scoped_destroy_lock.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_state_table.h"
#include "util/defines.h"

#include <algorithm>
#include <iterator>
#include <cassert>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

#if VK_USE_64_BIT_PTR_DEFINES == 1
#define UINT64_TO_VK_HANDLE(handle_type, value) reinterpret_cast<handle_type>(value)
#else
#define UINT64_TO_VK_HANDLE(handle_type, value) static_cast<handle_type>(value)
#endif

// Temporary resource IDs for state processing.
static const format::HandleId kTempQueueId = std::numeric_limits<format::HandleId>::max() - 1;
static const VkCommandPool    kTempCommandPool =
    UINT64_TO_VK_HANDLE(VkCommandPool, std::numeric_limits<uint64_t>::max() - 2);
static const format::HandleId kTempCommandPoolId   = std::numeric_limits<format::HandleId>::max() - 2;
static const format::HandleId kTempCommandBufferId = std::numeric_limits<format::HandleId>::max() - 3;
typedef format::HandleId (*PFN_GetHandleId)();

extern VulkanStateHandleTable state_handle_table_;

template <typename Wrapper>
format::HandleId GetTempVulkanWrapperId(const typename Wrapper::HandleType& handle)
{
    return 0;
}

template <>
inline format::HandleId GetTempVulkanWrapperId<vulkan_wrappers::CommandPoolWrapper>(const VkCommandPool& handle)
{
    if (handle == kTempCommandPool)
    {
        return kTempCommandPoolId;
    }
    return 0;
}

template <typename Wrapper>
format::HandleId GetVulkanWrappedId(const typename Wrapper::HandleType& handle)
{
    if (handle == VK_NULL_HANDLE)
    {
        return format::kNullHandleId;
    }
    auto temp_id = GetTempVulkanWrapperId<Wrapper>(handle);
    if (temp_id != 0)
    {
        return temp_id;
    }

    auto wrapper = state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING(
            "GetVulkanWrappedId() couldn't find Handle: %" PRIu64 "'s wrapper. It might have been destroyed", handle);
        return format::kNullHandleId;
    }
    return wrapper->handle_id;
}

template <typename Wrapper>
Wrapper* GetVulkanWrapper(const typename Wrapper::HandleType& handle)
{
    if (handle == VK_NULL_HANDLE)
    {
        return 0;
    }
    auto wrapper = state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING(
            "GetVulkanWrapper() couldn't find Handle: %" PRIu64 "'s wrapper. It might have been destroyed", handle);
    }
    return wrapper;
}

template <typename Wrapper>
bool RemoveVulkanWrapper(const Wrapper* wrapper)
{
    return state_handle_table_.RemoveWrapper(wrapper);
}

uint64_t GetVulkanWrappedId(uint64_t, VkObjectType object_type);

uint64_t GetVulkanWrappedId(uint64_t object, VkDebugReportObjectTypeEXT object_type);

inline const VulkanInstanceTable* GetVulkanInstanceTable(VkInstance handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetVulkanWrapper<vulkan_wrappers::InstanceWrapper>(handle);
    return &wrapper->layer_table;
}

inline const VulkanInstanceTable* GetVulkanInstanceTable(VkPhysicalDevice handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetVulkanWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const VulkanDeviceTable* GetVulkanDeviceTable(VkDevice handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetVulkanWrapper<vulkan_wrappers::DeviceWrapper>(handle);
    return &wrapper->layer_table;
}

inline const VulkanDeviceTable* GetVulkanDeviceTable(VkQueue handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetVulkanWrapper<vulkan_wrappers::QueueWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const VulkanDeviceTable* GetVulkanDeviceTable(VkCommandBuffer handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

// Wrapper for create wrapper template instantiations that do not make use of all handle parameters.
struct VulkanNoParentWrapper : public vulkan_wrappers::HandleWrapper<void*>
{
    static constexpr void* kHandleValue{ VK_NULL_HANDLE };
};

template <typename VulkanParentWrapper, typename Wrapper>
void CreateWrappedDispatchVulkanHandle(typename VulkanParentWrapper::HandleType parent,
                                       typename Wrapper::HandleType*            handle,
                                       PFN_GetHandleId                          get_id)
{
    ScopedDestroyLock shared_scoped_lock(true);
    assert(handle != nullptr);
    if ((*handle) != VK_NULL_HANDLE)
    {
        Wrapper* wrapper      = new Wrapper;
        wrapper->dispatch_key = *reinterpret_cast<void**>(*handle);
        wrapper->handle       = (*handle);
        wrapper->handle_id    = get_id();

        if (parent != VK_NULL_HANDLE)
        {
            // VkQueue and VkCommandBuffer loader dispatch tables are not assigned until the handles reach the
            // trampoline function, which comes after the layer. The wrapper will be modified by the trampoline
            // function, but the wrapped handle will not, so we set it to the parent VkDevice object's dispatch table.
            // This is also applied to VkPhysicalDevice handles and their parent VkInstance.
            void* disp                         = *reinterpret_cast<void* const*>(parent);
            *reinterpret_cast<void**>(*handle) = disp;
        }
        if (!state_handle_table_.InsertWrapper(wrapper))
        {
            GFXRECON_LOG_WARNING("Create a duplicated Handle: %" PRIu64
                                 ". This wrapper can't be written into VulkanStateHandleTable.",
                                 *handle);
        }
    }
}

template <typename Wrapper>
void CreateWrappedNonDispatchVulkanHandle(typename Wrapper::HandleType* handle, PFN_GetHandleId get_id)
{
    ScopedDestroyLock shared_scoped_lock(false);
    assert(handle != nullptr);
    if ((*handle) != VK_NULL_HANDLE)
    {
        Wrapper* wrapper   = new Wrapper;
        wrapper->handle    = (*handle);
        wrapper->handle_id = get_id();
        if (!state_handle_table_.InsertWrapper(wrapper))
        {
            GFXRECON_LOG_WARNING("Create a duplicated Handle: %" PRIu64
                                 ". This wrapper can't be written into VulkanStateHandleTable.",
                                 *handle);
        }
    }
}

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper, typename Wrapper>
void CreateWrappedVulkanHandle(typename VulkanParentWrapper::HandleType,   // Unused by default case.
                               typename VulkanCoParentWrapper::HandleType, // Unused by default case.
                               typename Wrapper::HandleType* handle,
                               PFN_GetHandleId               get_id)
{
    CreateWrappedNonDispatchVulkanHandle<Wrapper>(handle, get_id);
}

template <>
inline void CreateWrappedVulkanHandle<VulkanNoParentWrapper, VulkanNoParentWrapper, vulkan_wrappers::InstanceWrapper>(
    VulkanNoParentWrapper::HandleType, // VkInstance does not have a parent.
    VulkanNoParentWrapper::HandleType, // VkInstance does not have a co-parent.
    VkInstance*     handle,
    PFN_GetHandleId get_id)
{
    CreateWrappedDispatchVulkanHandle<VulkanNoParentWrapper, vulkan_wrappers::InstanceWrapper>(
        VulkanNoParentWrapper::kHandleValue, handle, get_id);
}

template <>
inline void CreateWrappedVulkanHandle<vulkan_wrappers::InstanceWrapper,
                                      VulkanNoParentWrapper,
                                      vulkan_wrappers::PhysicalDeviceWrapper>(
    VkInstance parent,
    VulkanNoParentWrapper::HandleType, // VkPhysicalDevice does not have a co-parent.
    VkPhysicalDevice* handle,
    PFN_GetHandleId   get_id)
{
    assert(parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetVulkanWrapper<vulkan_wrappers::InstanceWrapper>(parent);

    // Filter duplicate physical device retrieval.
    vulkan_wrappers::PhysicalDeviceWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_physical_devices)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchVulkanHandle<vulkan_wrappers::InstanceWrapper, vulkan_wrappers::PhysicalDeviceWrapper>(
            parent, handle, get_id);

        wrapper                  = GetVulkanWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_physical_devices.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedVulkanHandle<vulkan_wrappers::PhysicalDeviceWrapper,
                                      VulkanNoParentWrapper,
                                      vulkan_wrappers::DeviceWrapper>(
    VkPhysicalDevice,                  // Unused for device creation.
    VulkanNoParentWrapper::HandleType, // VkDevice does not have a co-parent.
    VkDevice*       handle,
    PFN_GetHandleId get_id)
{
    CreateWrappedDispatchVulkanHandle<vulkan_wrappers::PhysicalDeviceWrapper, vulkan_wrappers::DeviceWrapper>(
        VK_NULL_HANDLE, handle, get_id);
}

template <>
inline void
CreateWrappedVulkanHandle<vulkan_wrappers::DeviceWrapper, VulkanNoParentWrapper, vulkan_wrappers::DeviceMemoryWrapper>(
    VkDevice device, VulkanNoParentWrapper::HandleType, VkDeviceMemory* handle, PFN_GetHandleId get_id)
{
    CreateWrappedNonDispatchVulkanHandle<vulkan_wrappers::DeviceMemoryWrapper>(handle, get_id);
    auto memory_wrapper           = GetVulkanWrapper<vulkan_wrappers::DeviceMemoryWrapper>(*handle);
    memory_wrapper->parent_device = GetVulkanWrapper<vulkan_wrappers::DeviceWrapper>(device);
}

template <>
inline void
CreateWrappedVulkanHandle<vulkan_wrappers::DeviceWrapper, VulkanNoParentWrapper, vulkan_wrappers::QueueWrapper>(
    VkDevice parent,
    VulkanNoParentWrapper::HandleType, // VkQueue does not have a co-parent.
    VkQueue*        handle,
    PFN_GetHandleId get_id)
{
    assert(parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetVulkanWrapper<vulkan_wrappers::DeviceWrapper>(parent);

    // Filter duplicate physical device retrieval.
    vulkan_wrappers::QueueWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_queues)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchVulkanHandle<vulkan_wrappers::DeviceWrapper, vulkan_wrappers::QueueWrapper>(
            parent, handle, get_id);

        wrapper                  = GetVulkanWrapper<vulkan_wrappers::QueueWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_queues.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedVulkanHandle<vulkan_wrappers::DeviceWrapper,
                                      vulkan_wrappers::CommandPoolWrapper,
                                      vulkan_wrappers::CommandBufferWrapper>(VkDevice         parent,
                                                                             VkCommandPool    co_parent,
                                                                             VkCommandBuffer* handle,
                                                                             PFN_GetHandleId  get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    CreateWrappedDispatchVulkanHandle<vulkan_wrappers::DeviceWrapper, vulkan_wrappers::CommandBufferWrapper>(
        parent, handle, get_id);

    // The command pool must keep track of allocated command buffers, whose wrappers will need to be destroyed when the
    // pool is destroyed.
    auto parent_wrapper    = GetVulkanWrapper<vulkan_wrappers::DeviceWrapper>(parent);
    auto co_parent_wrapper = GetVulkanWrapper<vulkan_wrappers::CommandPoolWrapper>(co_parent);
    auto wrapper           = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(*handle);

    wrapper->layer_table_ref = &parent_wrapper->layer_table;
    wrapper->parent_pool     = co_parent_wrapper;
    co_parent_wrapper->child_buffers.insert(std::make_pair(wrapper->handle_id, wrapper));
}

template <>
inline void
CreateWrappedVulkanHandle<vulkan_wrappers::DeviceWrapper,
                          vulkan_wrappers::DescriptorPoolWrapper,
                          vulkan_wrappers::DescriptorSetWrapper>(VkDevice, // Unused for descriptor set creation.
                                                                 VkDescriptorPool co_parent,
                                                                 VkDescriptorSet* handle,
                                                                 PFN_GetHandleId  get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    CreateWrappedNonDispatchVulkanHandle<vulkan_wrappers::DescriptorSetWrapper>(handle, get_id);

    // The descriptor pool must keep track of allocated command buffers, whose wrappers will need to be destroyed when
    // the pool is destroyed.
    auto parent_wrapper = GetVulkanWrapper<vulkan_wrappers::DescriptorPoolWrapper>(co_parent);
    auto wrapper        = GetVulkanWrapper<vulkan_wrappers::DescriptorSetWrapper>(*handle);

    parent_wrapper->child_sets.insert(std::make_pair(wrapper->handle_id, wrapper));
    wrapper->parent_pool = parent_wrapper;
}

// Override for display retrieval, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void CreateWrappedVulkanHandle<vulkan_wrappers::PhysicalDeviceWrapper,
                                      VulkanNoParentWrapper,
                                      vulkan_wrappers::DisplayKHRWrapper>(
    VkPhysicalDevice parent,
    VulkanNoParentWrapper::HandleType, // VkDisplayKHR does not have a co-parent.
    VkDisplayKHR*   handle,
    PFN_GetHandleId get_id)
{
    assert(handle != nullptr);

    // vkGetDisplayPlaneProperties is allowed to pass back VK_NULL_HANDLE for VkDisplayPlaneProperties::currentDisplay
    // Do not attempt to wrap the null handle in this case
    if ((*handle) != VK_NULL_HANDLE)
    {
        assert(parent != VK_NULL_HANDLE);
        auto parent_wrapper = GetVulkanWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(parent);

        // Filter duplicate display retrieval.
        vulkan_wrappers::DisplayKHRWrapper* wrapper = nullptr;
        for (auto entry : parent_wrapper->child_displays)
        {
            if (entry->handle == (*handle))
            {
                wrapper = entry;
                break;
            }
        }

        if (wrapper == nullptr)
        {
            CreateWrappedNonDispatchVulkanHandle<vulkan_wrappers::DisplayKHRWrapper>(handle, get_id);
            wrapper = GetVulkanWrapper<vulkan_wrappers::DisplayKHRWrapper>(*handle);
            parent_wrapper->child_displays.push_back(wrapper);
        }
    }
}

// Override for images retrieved from a swapchain, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void CreateWrappedVulkanHandle<vulkan_wrappers::DeviceWrapper,
                                      vulkan_wrappers::SwapchainKHRWrapper,
                                      vulkan_wrappers::ImageWrapper>(VkDevice, // Unused for swapchain image retrieval.
                                                                     VkSwapchainKHR  co_parent,
                                                                     VkImage*        handle,
                                                                     PFN_GetHandleId get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetVulkanWrapper<vulkan_wrappers::SwapchainKHRWrapper>(co_parent);

    // Filter duplicate display retrieval.
    vulkan_wrappers::ImageWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_images)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedNonDispatchVulkanHandle<vulkan_wrappers::ImageWrapper>(handle, get_id);
        wrapper                     = GetVulkanWrapper<vulkan_wrappers::ImageWrapper>(*handle);
        wrapper->is_swapchain_image = true;
        wrapper->parent_swapchains.insert(co_parent);
        parent_wrapper->child_images.push_back(wrapper);
    }
}

// Override for display mode creation/retrieval, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void
CreateWrappedVulkanHandle<vulkan_wrappers::PhysicalDeviceWrapper,
                          vulkan_wrappers::DisplayKHRWrapper,
                          vulkan_wrappers::DisplayModeKHRWrapper>(VkPhysicalDevice, // Unused for display mode creation.
                                                                  VkDisplayKHR      co_parent,
                                                                  VkDisplayModeKHR* handle,
                                                                  PFN_GetHandleId   get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetVulkanWrapper<vulkan_wrappers::DisplayKHRWrapper>(co_parent);

    // Display modes can either be retrieved or created; filter duplicate display mode retrieval.
    vulkan_wrappers::DisplayModeKHRWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_display_modes)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedNonDispatchVulkanHandle<vulkan_wrappers::DisplayModeKHRWrapper>(handle, get_id);
        wrapper = GetVulkanWrapper<vulkan_wrappers::DisplayModeKHRWrapper>(*handle);
        parent_wrapper->child_display_modes.push_back(wrapper);
    }
}

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper, typename Wrapper>
void CreateWrappedVulkanHandles(typename VulkanParentWrapper::HandleType   parent,
                                typename VulkanCoParentWrapper::HandleType co_parent,
                                typename Wrapper::HandleType*              handles,
                                uint32_t                                   count,
                                PFN_GetHandleId                            get_id)
{
    if (handles != nullptr)
    {
        for (uint32_t i = 0; i < count; ++i)
        {
            CreateWrappedVulkanHandle<VulkanParentWrapper, VulkanCoParentWrapper, Wrapper>(
                parent, co_parent, &handles[i], get_id);
        }
    }
}

template <typename Wrapper>
void DestroyWrappedVulkanHandle(typename Wrapper::HandleType handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        auto wrapper = GetVulkanWrapper<Wrapper>(handle);
        RemoveVulkanWrapper<Wrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedVulkanHandle<vulkan_wrappers::InstanceWrapper>(VkInstance handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetVulkanWrapper<vulkan_wrappers::InstanceWrapper>(handle);

        for (auto physical_device_wrapper : wrapper->child_physical_devices)
        {
            for (auto display_wrapper : physical_device_wrapper->child_displays)
            {
                for (auto display_mode_wrapper : display_wrapper->child_display_modes)
                {
                    RemoveVulkanWrapper<vulkan_wrappers::DisplayModeKHRWrapper>(display_mode_wrapper);
                    delete display_mode_wrapper;
                }

                RemoveVulkanWrapper<vulkan_wrappers::DisplayKHRWrapper>(display_wrapper);
                delete display_wrapper;
            }

            RemoveVulkanWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device_wrapper);
            delete physical_device_wrapper;
        }

        RemoveVulkanWrapper<vulkan_wrappers::InstanceWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedVulkanHandle<vulkan_wrappers::DeviceWrapper>(VkDevice handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetVulkanWrapper<vulkan_wrappers::DeviceWrapper>(handle);

        for (auto queue_wrapper : wrapper->child_queues)
        {
            RemoveVulkanWrapper<vulkan_wrappers::QueueWrapper>(queue_wrapper);
            delete queue_wrapper;
        }

        RemoveVulkanWrapper<vulkan_wrappers::DeviceWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedVulkanHandle<vulkan_wrappers::CommandBufferWrapper>(VkCommandBuffer handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Remove from parent list.
        auto wrapper = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(handle);
        wrapper->parent_pool->child_buffers.erase(wrapper->handle_id);

        RemoveVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedVulkanHandle<vulkan_wrappers::CommandPoolWrapper>(VkCommandPool handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetVulkanWrapper<vulkan_wrappers::CommandPoolWrapper>(handle);

        for (const auto& buffer_wrapper : wrapper->child_buffers)
        {
            RemoveVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(buffer_wrapper.second);
            delete buffer_wrapper.second;
        }

        RemoveVulkanWrapper<vulkan_wrappers::CommandPoolWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedVulkanHandle<vulkan_wrappers::DescriptorSetWrapper>(VkDescriptorSet handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Remove from parent list.
        auto wrapper = GetVulkanWrapper<vulkan_wrappers::DescriptorSetWrapper>(handle);
        wrapper->parent_pool->child_sets.erase(wrapper->handle_id);

        RemoveVulkanWrapper<vulkan_wrappers::DescriptorSetWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedVulkanHandle<vulkan_wrappers::DescriptorPoolWrapper>(VkDescriptorPool handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetVulkanWrapper<vulkan_wrappers::DescriptorPoolWrapper>(handle);

        for (const auto& set_wrapper : wrapper->child_sets)
        {
            RemoveVulkanWrapper<vulkan_wrappers::DescriptorSetWrapper>(set_wrapper.second);
            delete set_wrapper.second;
        }

        RemoveVulkanWrapper<vulkan_wrappers::DescriptorPoolWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedVulkanHandle<vulkan_wrappers::SwapchainKHRWrapper>(VkSwapchainKHR handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetVulkanWrapper<vulkan_wrappers::SwapchainKHRWrapper>(handle);

        for (auto image_wrapper : wrapper->child_images)
        {
            image_wrapper->parent_swapchains.erase(handle);
            if (image_wrapper->parent_swapchains.empty())
            {
                RemoveVulkanWrapper<vulkan_wrappers::ImageWrapper>(image_wrapper);
                delete image_wrapper;
            }
        }

        RemoveVulkanWrapper<vulkan_wrappers::SwapchainKHRWrapper>(wrapper);
        delete wrapper;
    }
}

template <typename Wrapper>
void DestroyWrappedVulkanHandles(const typename Wrapper::HandleType* handles, uint32_t count)
{
    if (handles != nullptr)
    {
        for (uint32_t i = 0; i < count; ++i)
        {
            DestroyWrappedVulkanHandle<Wrapper>(handles[i]);
        }
    }
}

inline void ResetDescriptorPoolWrapper(VkDescriptorPool handle)
{
    assert(handle != VK_NULL_HANDLE);

    // Destroy child wrappers.
    auto wrapper = GetVulkanWrapper<vulkan_wrappers::DescriptorPoolWrapper>(handle);
    for (const auto& set_wrapper : wrapper->child_sets)
    {
        RemoveVulkanWrapper<vulkan_wrappers::DescriptorSetWrapper>(set_wrapper.second);
        delete set_wrapper.second;
    }
    wrapper->child_sets.clear();
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPER_UTIL_H
