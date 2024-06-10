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
GFXRECON_BEGIN_NAMESPACE(vulkan_wrappers)

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
format::HandleId GetTempWrapperId(const typename Wrapper::HandleType& handle)
{
    return 0;
}

template <>
inline format::HandleId GetTempWrapperId<CommandPoolWrapper>(const VkCommandPool& handle)
{
    if (handle == kTempCommandPool)
    {
        return kTempCommandPoolId;
    }
    return 0;
}

template <typename Wrapper>
format::HandleId GetWrappedId(const typename Wrapper::HandleType& handle)
{
    if (handle == VK_NULL_HANDLE)
    {
        return format::kNullHandleId;
    }
    auto temp_id = GetTempWrapperId<Wrapper>(handle);
    if (temp_id != 0)
    {
        return temp_id;
    }

    auto wrapper = state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING("vulkan_wrappers::GetWrappedId() couldn't find Handle: %" PRIu64
                             "'s wrapper. It might have been destroyed",
                             handle);
        return format::kNullHandleId;
    }
    return wrapper->handle_id;
}

template <typename Wrapper>
Wrapper* GetWrapper(const typename Wrapper::HandleType& handle)
{
    if (handle == VK_NULL_HANDLE)
    {
        return 0;
    }
    auto wrapper = state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING("vulkan_wrappers::GetWrapper() couldn't find Handle: %" PRIu64
                             "'s wrapper. It might have been destroyed",
                             handle);
    }
    return wrapper;
}

template <typename Wrapper>
bool RemoveWrapper(const Wrapper* wrapper)
{
    return state_handle_table_.RemoveWrapper(wrapper);
}

uint64_t GetWrappedId(uint64_t, VkObjectType object_type);

uint64_t GetWrappedId(uint64_t object, VkDebugReportObjectTypeEXT object_type);

inline const VulkanInstanceTable* GetInstanceTable(VkInstance handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapper<InstanceWrapper>(handle);
    return &wrapper->layer_table;
}

inline const VulkanInstanceTable* GetInstanceTable(VkPhysicalDevice handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapper<PhysicalDeviceWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const VulkanDeviceTable* GetDeviceTable(VkDevice handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapper<DeviceWrapper>(handle);
    return &wrapper->layer_table;
}

inline const VulkanDeviceTable* GetDeviceTable(VkQueue handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapper<QueueWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const VulkanDeviceTable* GetDeviceTable(VkCommandBuffer handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapper<CommandBufferWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

// Wrapper for create wrapper template instantiations that do not make use of all handle parameters.
struct NoParentWrapper : public HandleWrapper<void*>
{
    static constexpr void* kHandleValue{ VK_NULL_HANDLE };
};

template <typename ParentWrapper, typename Wrapper>
void CreateWrappedDispatchHandle(typename ParentWrapper::HandleType parent,
                                 typename Wrapper::HandleType*      handle,
                                 PFN_GetHandleId                    get_id)
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
void CreateWrappedNonDispatchHandle(typename Wrapper::HandleType* handle, PFN_GetHandleId get_id)
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

template <typename ParentWrapper, typename CoParentWrapper, typename Wrapper>
void CreateWrappedHandle(typename ParentWrapper::HandleType,   // Unused by default case.
                         typename CoParentWrapper::HandleType, // Unused by default case.
                         typename Wrapper::HandleType* handle,
                         PFN_GetHandleId               get_id)
{
    CreateWrappedNonDispatchHandle<Wrapper>(handle, get_id);
}

template <>
inline void CreateWrappedHandle<NoParentWrapper, NoParentWrapper, InstanceWrapper>(
    NoParentWrapper::HandleType, // VkInstance does not have a parent.
    NoParentWrapper::HandleType, // VkInstance does not have a co-parent.
    VkInstance*     handle,
    PFN_GetHandleId get_id)
{
    CreateWrappedDispatchHandle<NoParentWrapper, InstanceWrapper>(NoParentWrapper::kHandleValue, handle, get_id);
}

template <>
inline void CreateWrappedHandle<InstanceWrapper, NoParentWrapper, PhysicalDeviceWrapper>(
    VkInstance parent,
    NoParentWrapper::HandleType, // VkPhysicalDevice does not have a co-parent.
    VkPhysicalDevice* handle,
    PFN_GetHandleId   get_id)
{
    assert(parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<InstanceWrapper>(parent);

    // Filter duplicate physical device retrieval.
    PhysicalDeviceWrapper* wrapper = nullptr;
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
        CreateWrappedDispatchHandle<InstanceWrapper, PhysicalDeviceWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<PhysicalDeviceWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_physical_devices.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<PhysicalDeviceWrapper,
                                NoParentWrapper,
                                DeviceWrapper>(VkPhysicalDevice,            // Unused for device creation.
                                               NoParentWrapper::HandleType, // VkDevice does not have a co-parent.
                                               VkDevice*       handle,
                                               PFN_GetHandleId get_id)
{
    CreateWrappedDispatchHandle<PhysicalDeviceWrapper, DeviceWrapper>(VK_NULL_HANDLE, handle, get_id);
}

template <>
inline void CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DeviceMemoryWrapper>(VkDevice device,
                                                                                     NoParentWrapper::HandleType,
                                                                                     VkDeviceMemory* handle,
                                                                                     PFN_GetHandleId get_id)
{
    CreateWrappedNonDispatchHandle<DeviceMemoryWrapper>(handle, get_id);
    auto memory_wrapper           = GetWrapper<DeviceMemoryWrapper>(*handle);
    memory_wrapper->parent_device = GetWrapper<DeviceWrapper>(device);
}

template <>
inline void CreateWrappedHandle<DeviceWrapper, NoParentWrapper, QueueWrapper>(
    VkDevice parent,
    NoParentWrapper::HandleType, // VkQueue does not have a co-parent.
    VkQueue*        handle,
    PFN_GetHandleId get_id)
{
    assert(parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<DeviceWrapper>(parent);

    // Filter duplicate physical device retrieval.
    QueueWrapper* wrapper = nullptr;
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
        CreateWrappedDispatchHandle<DeviceWrapper, QueueWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<QueueWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_queues.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<DeviceWrapper, CommandPoolWrapper, CommandBufferWrapper>(VkDevice         parent,
                                                                                         VkCommandPool    co_parent,
                                                                                         VkCommandBuffer* handle,
                                                                                         PFN_GetHandleId  get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    CreateWrappedDispatchHandle<DeviceWrapper, CommandBufferWrapper>(parent, handle, get_id);

    // The command pool must keep track of allocated command buffers, whose wrappers will need to be destroyed when the
    // pool is destroyed.
    auto parent_wrapper    = GetWrapper<DeviceWrapper>(parent);
    auto co_parent_wrapper = GetWrapper<CommandPoolWrapper>(co_parent);
    auto wrapper           = GetWrapper<CommandBufferWrapper>(*handle);

    wrapper->layer_table_ref = &parent_wrapper->layer_table;
    wrapper->parent_pool     = co_parent_wrapper;
    co_parent_wrapper->child_buffers.insert(std::make_pair(wrapper->handle_id, wrapper));
}

template <>
inline void CreateWrappedHandle<DeviceWrapper,
                                DescriptorPoolWrapper,
                                DescriptorSetWrapper>(VkDevice, // Unused for descriptor set creation.
                                                      VkDescriptorPool co_parent,
                                                      VkDescriptorSet* handle,
                                                      PFN_GetHandleId  get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    CreateWrappedNonDispatchHandle<DescriptorSetWrapper>(handle, get_id);

    // The descriptor pool must keep track of allocated command buffers, whose wrappers will need to be destroyed when
    // the pool is destroyed.
    auto parent_wrapper = GetWrapper<DescriptorPoolWrapper>(co_parent);
    auto wrapper        = GetWrapper<DescriptorSetWrapper>(*handle);

    parent_wrapper->child_sets.insert(std::make_pair(wrapper->handle_id, wrapper));
    wrapper->parent_pool = parent_wrapper;
}

// Override for display retrieval, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DisplayKHRWrapper>(
    VkPhysicalDevice parent,
    NoParentWrapper::HandleType, // VkDisplayKHR does not have a co-parent.
    VkDisplayKHR*   handle,
    PFN_GetHandleId get_id)
{
    assert(handle != nullptr);

    // vkGetDisplayPlaneProperties is allowed to pass back VK_NULL_HANDLE for VkDisplayPlaneProperties::currentDisplay
    // Do not attempt to wrap the null handle in this case
    if ((*handle) != VK_NULL_HANDLE)
    {
        assert(parent != VK_NULL_HANDLE);
        auto parent_wrapper = GetWrapper<PhysicalDeviceWrapper>(parent);

        // Filter duplicate display retrieval.
        DisplayKHRWrapper* wrapper = nullptr;
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
            CreateWrappedNonDispatchHandle<DisplayKHRWrapper>(handle, get_id);
            wrapper = GetWrapper<DisplayKHRWrapper>(*handle);
            parent_wrapper->child_displays.push_back(wrapper);
        }
    }
}

// Override for images retrieved from a swapchain, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void CreateWrappedHandle<DeviceWrapper,
                                SwapchainKHRWrapper,
                                ImageWrapper>(VkDevice, // Unused for swapchain image retrieval.
                                              VkSwapchainKHR  co_parent,
                                              VkImage*        handle,
                                              PFN_GetHandleId get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SwapchainKHRWrapper>(co_parent);

    // Filter duplicate display retrieval.
    ImageWrapper* wrapper = nullptr;
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
        CreateWrappedNonDispatchHandle<ImageWrapper>(handle, get_id);
        wrapper                     = GetWrapper<ImageWrapper>(*handle);
        wrapper->is_swapchain_image = true;
        wrapper->parent_swapchains.insert(co_parent);
        parent_wrapper->child_images.push_back(wrapper);
    }
}

// Override for display mode creation/retrieval, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void CreateWrappedHandle<PhysicalDeviceWrapper,
                                DisplayKHRWrapper,
                                DisplayModeKHRWrapper>(VkPhysicalDevice, // Unused for display mode creation.
                                                       VkDisplayKHR      co_parent,
                                                       VkDisplayModeKHR* handle,
                                                       PFN_GetHandleId   get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<DisplayKHRWrapper>(co_parent);

    // Display modes can either be retrieved or created; filter duplicate display mode retrieval.
    DisplayModeKHRWrapper* wrapper = nullptr;
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
        CreateWrappedNonDispatchHandle<DisplayModeKHRWrapper>(handle, get_id);
        wrapper = GetWrapper<DisplayModeKHRWrapper>(*handle);
        parent_wrapper->child_display_modes.push_back(wrapper);
    }
}

template <typename ParentWrapper, typename CoParentWrapper, typename Wrapper>
void CreateWrappedHandles(typename ParentWrapper::HandleType   parent,
                          typename CoParentWrapper::HandleType co_parent,
                          typename Wrapper::HandleType*        handles,
                          uint32_t                             count,
                          PFN_GetHandleId                      get_id)
{
    if (handles != nullptr)
    {
        for (uint32_t i = 0; i < count; ++i)
        {
            CreateWrappedHandle<ParentWrapper, CoParentWrapper, Wrapper>(parent, co_parent, &handles[i], get_id);
        }
    }
}

template <typename Wrapper>
void DestroyWrappedHandle(typename Wrapper::HandleType handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        auto wrapper = GetWrapper<Wrapper>(handle);
        RemoveWrapper<Wrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<InstanceWrapper>(VkInstance handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<InstanceWrapper>(handle);

        for (auto physical_device_wrapper : wrapper->child_physical_devices)
        {
            for (auto display_wrapper : physical_device_wrapper->child_displays)
            {
                for (auto display_mode_wrapper : display_wrapper->child_display_modes)
                {
                    RemoveWrapper<DisplayModeKHRWrapper>(display_mode_wrapper);
                    delete display_mode_wrapper;
                }

                RemoveWrapper<DisplayKHRWrapper>(display_wrapper);
                delete display_wrapper;
            }

            RemoveWrapper<PhysicalDeviceWrapper>(physical_device_wrapper);
            delete physical_device_wrapper;
        }

        RemoveWrapper<InstanceWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<DeviceWrapper>(VkDevice handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<DeviceWrapper>(handle);

        for (auto queue_wrapper : wrapper->child_queues)
        {
            RemoveWrapper<QueueWrapper>(queue_wrapper);
            delete queue_wrapper;
        }

        RemoveWrapper<DeviceWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<CommandBufferWrapper>(VkCommandBuffer handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Remove from parent list.
        auto wrapper = GetWrapper<CommandBufferWrapper>(handle);
        wrapper->parent_pool->child_buffers.erase(wrapper->handle_id);

        RemoveWrapper<CommandBufferWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<CommandPoolWrapper>(VkCommandPool handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<CommandPoolWrapper>(handle);

        for (const auto& buffer_wrapper : wrapper->child_buffers)
        {
            RemoveWrapper<CommandBufferWrapper>(buffer_wrapper.second);
            delete buffer_wrapper.second;
        }

        RemoveWrapper<CommandPoolWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<DescriptorSetWrapper>(VkDescriptorSet handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Remove from parent list.
        auto wrapper = GetWrapper<DescriptorSetWrapper>(handle);
        wrapper->parent_pool->child_sets.erase(wrapper->handle_id);

        RemoveWrapper<DescriptorSetWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<DescriptorPoolWrapper>(VkDescriptorPool handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<DescriptorPoolWrapper>(handle);

        for (const auto& set_wrapper : wrapper->child_sets)
        {
            RemoveWrapper<DescriptorSetWrapper>(set_wrapper.second);
            delete set_wrapper.second;
        }

        RemoveWrapper<DescriptorPoolWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<SwapchainKHRWrapper>(VkSwapchainKHR handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<SwapchainKHRWrapper>(handle);

        for (auto image_wrapper : wrapper->child_images)
        {
            image_wrapper->parent_swapchains.erase(handle);
            if (image_wrapper->parent_swapchains.empty())
            {
                RemoveWrapper<ImageWrapper>(image_wrapper);
                delete image_wrapper;
            }
        }

        RemoveWrapper<SwapchainKHRWrapper>(wrapper);
        delete wrapper;
    }
}

template <typename Wrapper>
void DestroyWrappedHandles(const typename Wrapper::HandleType* handles, uint32_t count)
{
    if (handles != nullptr)
    {
        for (uint32_t i = 0; i < count; ++i)
        {
            DestroyWrappedHandle<Wrapper>(handles[i]);
        }
    }
}

inline void ResetDescriptorPoolWrapper(VkDescriptorPool handle)
{
    assert(handle != VK_NULL_HANDLE);

    // Destroy child wrappers.
    auto wrapper = GetWrapper<DescriptorPoolWrapper>(handle);
    for (const auto& set_wrapper : wrapper->child_sets)
    {
        RemoveWrapper<DescriptorSetWrapper>(set_wrapper.second);
        delete set_wrapper.second;
    }
    wrapper->child_sets.clear();
}

GFXRECON_END_NAMESPACE(vulkan_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPER_UTIL_H
