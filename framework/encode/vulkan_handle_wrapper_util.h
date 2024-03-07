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
#include "vulkan_scoped_destroy_lock.h"
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
format::HandleId GetTempWrapperId(const typename Wrapper::HandleType& handle)
{
    return 0;
}

template <>
inline format::HandleId GetTempWrapperId<VulkanCommandPoolWrapper>(const VkCommandPool& handle)
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
        GFXRECON_LOG_WARNING("GetWrappedId() couldn't find Handle: %" PRIu64 "'s wrapper. It might have been destroyed",
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
        GFXRECON_LOG_WARNING("GetWrapper() couldn't find Handle: %" PRIu64 "'s wrapper. It might have been destroyed",
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

inline const VulkanInstanceTable* GetVulkanInstanceTable(VkInstance handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapper<VulkanInstanceWrapper>(handle);
    return &wrapper->layer_table;
}

inline const VulkanInstanceTable* GetVulkanInstanceTable(VkPhysicalDevice handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapper<VulkanPhysicalDeviceWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const VulkanDeviceTable* GetVulkanDeviceTable(VkDevice handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapper<VulkanDeviceWrapper>(handle);
    return &wrapper->layer_table;
}

inline const VulkanDeviceTable* GetVulkanDeviceTable(VkQueue handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapper<VulkanQueueWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const VulkanDeviceTable* GetVulkanDeviceTable(VkCommandBuffer handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapper<VulkanCommandBufferWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

// Wrapper for create wrapper template instantiations that do not make use of all handle parameters.
struct VulkanNoParentWrapper : public VulkanHandleWrapper<void*>
{
    static constexpr void* kHandleValue{ VK_NULL_HANDLE };
};

template <typename VulkanParentWrapper, typename Wrapper>
void CreateWrappedDispatchHandle(typename VulkanParentWrapper::HandleType parent,
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

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper, typename Wrapper>
void CreateWrappedHandle(typename VulkanParentWrapper::HandleType,   // Unused by default case.
                         typename VulkanCoParentWrapper::HandleType, // Unused by default case.
                         typename Wrapper::HandleType* handle,
                         PFN_GetHandleId               get_id)
{
    CreateWrappedNonDispatchHandle<Wrapper>(handle, get_id);
}

template <>
inline void CreateWrappedHandle<VulkanNoParentWrapper, VulkanNoParentWrapper, VulkanInstanceWrapper>(
    VulkanNoParentWrapper::HandleType, // VkInstance does not have a parent.
    VulkanNoParentWrapper::HandleType, // VkInstance does not have a co-parent.
    VkInstance*     handle,
    PFN_GetHandleId get_id)
{
    CreateWrappedDispatchHandle<VulkanNoParentWrapper, VulkanInstanceWrapper>(
        VulkanNoParentWrapper::kHandleValue, handle, get_id);
}

template <>
inline void CreateWrappedHandle<VulkanInstanceWrapper, VulkanNoParentWrapper, VulkanPhysicalDeviceWrapper>(
    VkInstance parent,
    VulkanNoParentWrapper::HandleType, // VkPhysicalDevice does not have a co-parent.
    VkPhysicalDevice* handle,
    PFN_GetHandleId   get_id)
{
    assert(parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<VulkanInstanceWrapper>(parent);

    // Filter duplicate physical device retrieval.
    VulkanPhysicalDeviceWrapper* wrapper = nullptr;
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
        CreateWrappedDispatchHandle<VulkanInstanceWrapper, VulkanPhysicalDeviceWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<VulkanPhysicalDeviceWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_physical_devices.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<VulkanPhysicalDeviceWrapper, VulkanNoParentWrapper, VulkanDeviceWrapper>(
    VkPhysicalDevice,                  // Unused for device creation.
    VulkanNoParentWrapper::HandleType, // VkDevice does not have a co-parent.
    VkDevice*       handle,
    PFN_GetHandleId get_id)
{
    CreateWrappedDispatchHandle<VulkanPhysicalDeviceWrapper, VulkanDeviceWrapper>(VK_NULL_HANDLE, handle, get_id);
}

template <>
inline void CreateWrappedHandle<VulkanDeviceWrapper, VulkanNoParentWrapper, VulkanDeviceMemoryWrapper>(
    VkDevice device, VulkanNoParentWrapper::HandleType, VkDeviceMemory* handle, PFN_GetHandleId get_id)
{
    CreateWrappedNonDispatchHandle<VulkanDeviceMemoryWrapper>(handle, get_id);
    auto memory_wrapper           = GetWrapper<VulkanDeviceMemoryWrapper>(*handle);
    memory_wrapper->parent_device = GetWrapper<VulkanDeviceWrapper>(device);
}

template <>
inline void CreateWrappedHandle<VulkanDeviceWrapper, VulkanNoParentWrapper, VulkanQueueWrapper>(
    VkDevice parent,
    VulkanNoParentWrapper::HandleType, // VkQueue does not have a co-parent.
    VkQueue*        handle,
    PFN_GetHandleId get_id)
{
    assert(parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<VulkanDeviceWrapper>(parent);

    // Filter duplicate physical device retrieval.
    VulkanQueueWrapper* wrapper = nullptr;
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
        CreateWrappedDispatchHandle<VulkanDeviceWrapper, VulkanQueueWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<VulkanQueueWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_queues.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<VulkanDeviceWrapper, VulkanCommandPoolWrapper, VulkanCommandBufferWrapper>(
    VkDevice parent, VkCommandPool co_parent, VkCommandBuffer* handle, PFN_GetHandleId get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    CreateWrappedDispatchHandle<VulkanDeviceWrapper, VulkanCommandBufferWrapper>(parent, handle, get_id);

    // The command pool must keep track of allocated command buffers, whose wrappers will need to be destroyed when the
    // pool is destroyed.
    auto parent_wrapper    = GetWrapper<VulkanDeviceWrapper>(parent);
    auto co_parent_wrapper = GetWrapper<VulkanCommandPoolWrapper>(co_parent);
    auto wrapper           = GetWrapper<VulkanCommandBufferWrapper>(*handle);

    wrapper->layer_table_ref = &parent_wrapper->layer_table;
    wrapper->parent_pool     = co_parent_wrapper;
    co_parent_wrapper->child_buffers.insert(std::make_pair(wrapper->handle_id, wrapper));
}

template <>
inline void CreateWrappedHandle<VulkanDeviceWrapper, VulkanDescriptorPoolWrapper, VulkanDescriptorSetWrapper>(
    VkDevice, // Unused for descriptor set creation.
    VkDescriptorPool co_parent,
    VkDescriptorSet* handle,
    PFN_GetHandleId  get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    CreateWrappedNonDispatchHandle<VulkanDescriptorSetWrapper>(handle, get_id);

    // The descriptor pool must keep track of allocated command buffers, whose wrappers will need to be destroyed when
    // the pool is destroyed.
    auto parent_wrapper = GetWrapper<VulkanDescriptorPoolWrapper>(co_parent);
    auto wrapper        = GetWrapper<VulkanDescriptorSetWrapper>(*handle);

    parent_wrapper->child_sets.insert(std::make_pair(wrapper->handle_id, wrapper));
    wrapper->parent_pool = parent_wrapper;
}

// Override for display retrieval, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void CreateWrappedHandle<VulkanPhysicalDeviceWrapper, VulkanNoParentWrapper, VulkanDisplayKHRWrapper>(
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
        auto parent_wrapper = GetWrapper<VulkanPhysicalDeviceWrapper>(parent);

        // Filter duplicate display retrieval.
        VulkanDisplayKHRWrapper* wrapper = nullptr;
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
            CreateWrappedNonDispatchHandle<VulkanDisplayKHRWrapper>(handle, get_id);
            wrapper = GetWrapper<VulkanDisplayKHRWrapper>(*handle);
            parent_wrapper->child_displays.push_back(wrapper);
        }
    }
}

// Override for images retrieved from a swapchain, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void CreateWrappedHandle<VulkanDeviceWrapper, VulkanSwapchainKHRWrapper, VulkanImageWrapper>(
    VkDevice, // Unused for swapchain image retrieval.
    VkSwapchainKHR  co_parent,
    VkImage*        handle,
    PFN_GetHandleId get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<VulkanSwapchainKHRWrapper>(co_parent);

    // Filter duplicate display retrieval.
    VulkanImageWrapper* wrapper = nullptr;
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
        CreateWrappedNonDispatchHandle<VulkanImageWrapper>(handle, get_id);
        wrapper                     = GetWrapper<VulkanImageWrapper>(*handle);
        wrapper->is_swapchain_image = true;
        wrapper->parent_swapchains.insert(co_parent);
        parent_wrapper->child_images.push_back(wrapper);
    }
}

// Override for display mode creation/retrieval, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void CreateWrappedHandle<VulkanPhysicalDeviceWrapper, VulkanDisplayKHRWrapper, VulkanDisplayModeKHRWrapper>(
    VkPhysicalDevice, // Unused for display mode creation.
    VkDisplayKHR      co_parent,
    VkDisplayModeKHR* handle,
    PFN_GetHandleId   get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<VulkanDisplayKHRWrapper>(co_parent);

    // Display modes can either be retrieved or created; filter duplicate display mode retrieval.
    VulkanDisplayModeKHRWrapper* wrapper = nullptr;
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
        CreateWrappedNonDispatchHandle<VulkanDisplayModeKHRWrapper>(handle, get_id);
        wrapper = GetWrapper<VulkanDisplayModeKHRWrapper>(*handle);
        parent_wrapper->child_display_modes.push_back(wrapper);
    }
}

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper, typename Wrapper>
void CreateWrappedHandles(typename VulkanParentWrapper::HandleType   parent,
                          typename VulkanCoParentWrapper::HandleType co_parent,
                          typename Wrapper::HandleType*              handles,
                          uint32_t                                   count,
                          PFN_GetHandleId                            get_id)
{
    if (handles != nullptr)
    {
        for (uint32_t i = 0; i < count; ++i)
        {
            CreateWrappedHandle<VulkanParentWrapper, VulkanCoParentWrapper, Wrapper>(
                parent, co_parent, &handles[i], get_id);
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
inline void DestroyWrappedHandle<VulkanInstanceWrapper>(VkInstance handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<VulkanInstanceWrapper>(handle);

        for (auto physical_device_wrapper : wrapper->child_physical_devices)
        {
            for (auto display_wrapper : physical_device_wrapper->child_displays)
            {
                for (auto display_mode_wrapper : display_wrapper->child_display_modes)
                {
                    RemoveWrapper<VulkanDisplayModeKHRWrapper>(display_mode_wrapper);
                    delete display_mode_wrapper;
                }

                RemoveWrapper<VulkanDisplayKHRWrapper>(display_wrapper);
                delete display_wrapper;
            }

            RemoveWrapper<VulkanPhysicalDeviceWrapper>(physical_device_wrapper);
            delete physical_device_wrapper;
        }

        RemoveWrapper<VulkanInstanceWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<VulkanDeviceWrapper>(VkDevice handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<VulkanDeviceWrapper>(handle);

        for (auto queue_wrapper : wrapper->child_queues)
        {
            RemoveWrapper<VulkanQueueWrapper>(queue_wrapper);
            delete queue_wrapper;
        }

        RemoveWrapper<VulkanDeviceWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<VulkanCommandBufferWrapper>(VkCommandBuffer handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Remove from parent list.
        auto wrapper = GetWrapper<VulkanCommandBufferWrapper>(handle);
        wrapper->parent_pool->child_buffers.erase(wrapper->handle_id);

        RemoveWrapper<VulkanCommandBufferWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<VulkanCommandPoolWrapper>(VkCommandPool handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<VulkanCommandPoolWrapper>(handle);

        for (const auto& buffer_wrapper : wrapper->child_buffers)
        {
            RemoveWrapper<VulkanCommandBufferWrapper>(buffer_wrapper.second);
            delete buffer_wrapper.second;
        }

        RemoveWrapper<VulkanCommandPoolWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<VulkanDescriptorSetWrapper>(VkDescriptorSet handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Remove from parent list.
        auto wrapper = GetWrapper<VulkanDescriptorSetWrapper>(handle);
        wrapper->parent_pool->child_sets.erase(wrapper->handle_id);

        RemoveWrapper<VulkanDescriptorSetWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<VulkanDescriptorPoolWrapper>(VkDescriptorPool handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<VulkanDescriptorPoolWrapper>(handle);

        for (const auto& set_wrapper : wrapper->child_sets)
        {
            RemoveWrapper<VulkanDescriptorSetWrapper>(set_wrapper.second);
            delete set_wrapper.second;
        }

        RemoveWrapper<VulkanDescriptorPoolWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<VulkanSwapchainKHRWrapper>(VkSwapchainKHR handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<VulkanSwapchainKHRWrapper>(handle);

        for (auto image_wrapper : wrapper->child_images)
        {
            image_wrapper->parent_swapchains.erase(handle);
            if (image_wrapper->parent_swapchains.empty())
            {
                RemoveWrapper<VulkanImageWrapper>(image_wrapper);
                delete image_wrapper;
            }
        }

        RemoveWrapper<VulkanSwapchainKHRWrapper>(wrapper);
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
    auto wrapper = GetWrapper<VulkanDescriptorPoolWrapper>(handle);
    for (const auto& set_wrapper : wrapper->child_sets)
    {
        RemoveWrapper<VulkanDescriptorSetWrapper>(set_wrapper.second);
        delete set_wrapper.second;
    }
    wrapper->child_sets.clear();
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPER_UTIL_H
