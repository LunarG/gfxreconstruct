/*
** Copyright (c) 2019 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPER_UTIL_H
#define GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPER_UTIL_H

#include "encode/vulkan_handle_wrappers.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include <algorithm>
#include <cassert>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

typedef format::HandleId (*PFN_GetHandleId)();

typedef std::vector<uint8_t> HandleUnwrapBuffer;

class HandleUnwrapMemory
{
  public:
    HandleUnwrapMemory() : current_buffer_(0) {}

    uint8_t* GetBuffer(size_t len)
    {
        HandleUnwrapBuffer* next_buffer = nullptr;
        size_t              next_index  = current_buffer_++;

        if (next_index < buffers_.size())
        {
            next_buffer = &buffers_[next_index];

            if (len > next_buffer->size())
            {
                next_buffer->resize(len);
            }
        }
        else
        {
            buffers_.emplace_back(len);
            next_buffer = &buffers_[next_index];
        }

        return next_buffer->data();
    }

    uint8_t* GetFilledBuffer(const uint8_t* data, size_t len)
    {
        HandleUnwrapBuffer* next_buffer = nullptr;
        size_t              next_index  = current_buffer_++;

        if (next_index < buffers_.size())
        {
            next_buffer = &buffers_[next_index];
            next_buffer->clear();
            next_buffer->insert(next_buffer->end(), data, data + len);
        }
        else
        {
            buffers_.emplace_back(data, data + len);
            next_buffer = &buffers_[next_index];
        }

        return next_buffer->data();
    }

    void Reset() { current_buffer_ = 0; }

  private:
    size_t                          current_buffer_;
    std::vector<HandleUnwrapBuffer> buffers_;
};

template <typename T>
T GetWrappedHandle(const T& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<T>*>(handle)->handle : VK_NULL_HANDLE;
}

template <typename T>
format::HandleId GetWrappedId(const T& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<T>*>(handle)->handle_id : 0;
}

inline const InstanceTable* GetInstanceTable(VkInstance handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = reinterpret_cast<const InstanceWrapper*>(handle);
    return &wrapper->layer_table;
}

inline const InstanceTable* GetInstanceTable(VkPhysicalDevice handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = reinterpret_cast<const PhysicalDeviceWrapper*>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const DeviceTable* GetDeviceTable(VkDevice handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = reinterpret_cast<const DeviceWrapper*>(handle);
    return &wrapper->layer_table;
}

inline const DeviceTable* GetDeviceTable(VkQueue handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = reinterpret_cast<const QueueWrapper*>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const DeviceTable* GetDeviceTable(VkCommandBuffer handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = reinterpret_cast<const CommandBufferWrapper*>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

// Wrapper for create wrapper template instantiations that do not make use of all handle parameters.
struct NoParentWrapper : public HandleWrapper<uint64_t>
{
    static const uint64_t kHandleValue{ VK_NULL_HANDLE };
};

template <typename ParentWrapper, typename Wrapper>
void CreateWrappedDispatchHandle(typename ParentWrapper::HandleType parent,
                                 typename Wrapper::HandleType*      handle,
                                 PFN_GetHandleId                    get_id)
{
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

        (*handle) = reinterpret_cast<typename Wrapper::HandleType>(wrapper);
    }
}

template <typename Wrapper>
void CreateWrappedNonDispatchHandle(typename Wrapper::HandleType* handle, PFN_GetHandleId get_id)
{
    assert(handle != nullptr);
    if ((*handle) != VK_NULL_HANDLE)
    {
        Wrapper* wrapper   = new Wrapper;
        wrapper->handle    = (*handle);
        wrapper->handle_id = get_id();
        (*handle)          = reinterpret_cast<typename Wrapper::HandleType>(wrapper);
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

    auto parent_wrapper = reinterpret_cast<InstanceWrapper*>(parent);

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

    if (wrapper != nullptr)
    {
        (*handle) = reinterpret_cast<VkPhysicalDevice>(wrapper);
    }
    else
    {
        CreateWrappedDispatchHandle<InstanceWrapper, PhysicalDeviceWrapper>(parent, handle, get_id);

        wrapper                  = reinterpret_cast<PhysicalDeviceWrapper*>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_physical_devices.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DeviceWrapper>(
    VkPhysicalDevice,            // Unused for device creation.
    NoParentWrapper::HandleType, // VkDevice does not have a co-parent.
    VkDevice*       handle,
    PFN_GetHandleId get_id)
{
    CreateWrappedDispatchHandle<PhysicalDeviceWrapper, DeviceWrapper>(VK_NULL_HANDLE, handle, get_id);
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

    auto parent_wrapper = reinterpret_cast<DeviceWrapper*>(parent);

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

    if (wrapper != nullptr)
    {
        (*handle) = reinterpret_cast<VkQueue>(wrapper);
    }
    else
    {
        CreateWrappedDispatchHandle<DeviceWrapper, QueueWrapper>(parent, handle, get_id);

        wrapper                  = reinterpret_cast<QueueWrapper*>(*handle);
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
    auto parent_wrapper    = reinterpret_cast<DeviceWrapper*>(parent);
    auto co_parent_wrapper = reinterpret_cast<CommandPoolWrapper*>(co_parent);
    auto wrapper           = reinterpret_cast<CommandBufferWrapper*>(*handle);

    wrapper->layer_table_ref = &parent_wrapper->layer_table;
    wrapper->parent_pool     = co_parent_wrapper;
    co_parent_wrapper->child_buffers.insert(std::make_pair(wrapper->handle_id, wrapper));
}

template <>
inline void CreateWrappedHandle<DeviceWrapper, DescriptorPoolWrapper, DescriptorSetWrapper>(
    VkDevice, // Unused for descriptor set creation.
    VkDescriptorPool co_parent,
    VkDescriptorSet* handle,
    PFN_GetHandleId  get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    CreateWrappedNonDispatchHandle<DescriptorSetWrapper>(handle, get_id);

    // The descriptor pool must keep track of allocated command buffers, whose wrappers will need to be destroyed when
    // the pool is destroyed.
    auto parent_wrapper = reinterpret_cast<DescriptorPoolWrapper*>(co_parent);
    auto wrapper        = reinterpret_cast<DescriptorSetWrapper*>(*handle);

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
        auto parent_wrapper = reinterpret_cast<PhysicalDeviceWrapper*>(parent);

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

        if (wrapper != nullptr)
        {
            (*handle) = reinterpret_cast<VkDisplayKHR>(wrapper);
        }
        else
        {
            CreateWrappedNonDispatchHandle<DisplayKHRWrapper>(handle, get_id);
            parent_wrapper->child_displays.push_back(reinterpret_cast<DisplayKHRWrapper*>(*handle));
        }
    }
}

// Override for images retrieved from a swapchain, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void
CreateWrappedHandle<DeviceWrapper, SwapchainKHRWrapper, ImageWrapper>(VkDevice, // Unused for swapchain image retrieval.
                                                                      VkSwapchainKHR  co_parent,
                                                                      VkImage*        handle,
                                                                      PFN_GetHandleId get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = reinterpret_cast<SwapchainKHRWrapper*>(co_parent);

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

    if (wrapper != nullptr)
    {
        (*handle) = reinterpret_cast<VkImage>(wrapper);
    }
    else
    {
        CreateWrappedNonDispatchHandle<ImageWrapper>(handle, get_id);
        parent_wrapper->child_images.push_back(reinterpret_cast<ImageWrapper*>(*handle));
    }
}

// Override for display mode creation/retrieval, which requires the handle wrapper to be owned by a parent to ensure
// the wrapper memory is released when the parent is destroyed.
template <>
inline void CreateWrappedHandle<PhysicalDeviceWrapper, DisplayKHRWrapper, DisplayModeKHRWrapper>(
    VkPhysicalDevice, // Unused for display mode creation.
    VkDisplayKHR      co_parent,
    VkDisplayModeKHR* handle,
    PFN_GetHandleId   get_id)
{
    assert(co_parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = reinterpret_cast<DisplayKHRWrapper*>(co_parent);

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

    if (wrapper != nullptr)
    {
        (*handle) = reinterpret_cast<VkDisplayModeKHR>(wrapper);
    }
    else
    {
        CreateWrappedNonDispatchHandle<DisplayModeKHRWrapper>(handle, get_id);
        parent_wrapper->child_display_modes.push_back(reinterpret_cast<DisplayModeKHRWrapper*>(*handle));
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
        delete reinterpret_cast<Wrapper*>(handle);
    }
}

template <>
inline void DestroyWrappedHandle<InstanceWrapper>(VkInstance handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = reinterpret_cast<InstanceWrapper*>(handle);

        for (auto physical_device_wrapper : wrapper->child_physical_devices)
        {
            for (auto display_wrapper : physical_device_wrapper->child_displays)
            {
                for (auto display_mode_wrapper : display_wrapper->child_display_modes)
                {
                    delete display_mode_wrapper;
                }

                delete display_wrapper;
            }

            delete physical_device_wrapper;
        }

        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<DeviceWrapper>(VkDevice handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = reinterpret_cast<DeviceWrapper*>(handle);

        for (auto queue_wrapper : wrapper->child_queues)
        {
            delete queue_wrapper;
        }

        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<CommandBufferWrapper>(VkCommandBuffer handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Remove from parent list.
        auto wrapper = reinterpret_cast<CommandBufferWrapper*>(handle);
        wrapper->parent_pool->child_buffers.erase(wrapper->handle_id);

        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<CommandPoolWrapper>(VkCommandPool handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = reinterpret_cast<CommandPoolWrapper*>(handle);

        for (const auto& buffer_wrapper : wrapper->child_buffers)
        {
            delete buffer_wrapper.second;
        }

        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<DescriptorSetWrapper>(VkDescriptorSet handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Remove from parent list.
        auto wrapper = reinterpret_cast<DescriptorSetWrapper*>(handle);
        wrapper->parent_pool->child_sets.erase(wrapper->handle_id);

        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<DescriptorPoolWrapper>(VkDescriptorPool handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = reinterpret_cast<DescriptorPoolWrapper*>(handle);

        for (const auto& set_wrapper : wrapper->child_sets)
        {
            delete set_wrapper.second;
        }

        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<SwapchainKHRWrapper>(VkSwapchainKHR handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = reinterpret_cast<SwapchainKHRWrapper*>(handle);

        for (auto image_wrapper : wrapper->child_images)
        {
            delete image_wrapper;
        }

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
    auto wrapper = reinterpret_cast<DescriptorPoolWrapper*>(handle);
    for (const auto& set_wrapper : wrapper->child_sets)
    {
        delete set_wrapper.second;
    }
    wrapper->child_sets.clear();
}

// Unwrap arrays of handles.
template <typename Handle>
const Handle* UnwrapHandles(const Handle* handles, uint32_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((handles != nullptr) && (len > 0))
    {
        assert(unwrap_memory != nullptr);

        size_t num_bytes         = len * sizeof(Handle);
        auto   unwrapped_handles = reinterpret_cast<Handle*>(unwrap_memory->GetBuffer(num_bytes));

        for (uint32_t i = 0; i < len; ++i)
        {
            unwrapped_handles[i] = GetWrappedHandle<Handle>(handles[i]);
        }

        return unwrapped_handles;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return handles;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_HANDLE_WRAPPER_UTIL_H
