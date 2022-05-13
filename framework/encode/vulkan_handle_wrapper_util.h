/*
** Copyright (c) 2019 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc.
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
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include <algorithm>
#include <iterator>
#include <cassert>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// TODO:FAKE_HANDLE: VK_HANDLE_TO_UINT64 is not correct for 32bit dispatch handle.

#if VK_USE_64_BIT_PTR_DEFINES == 1
// Vulkan non-dispatch handle is a pointer in its define for 64bit Vulkan, so
// we need to use reinterpret_cast for the conversion.
#define VK_HANDLE_TO_UINT64(handle) reinterpret_cast<uint64_t>(handle)
#define UINT64_TO_VK_HANDLE(handleType, value) reinterpret_cast<handleType>(value)
#else
// non-dispatch handle is not a pointer for 32bit Vulkan, so we need to use
// static_cast for the conversion.
#define VK_HANDLE_TO_UINT64(handle) static_cast<uint64_t>(handle)
#define UINT64_TO_VK_HANDLE(handleType, value) static_cast<handleType>(value)
#endif

// When capturing some title with GFXR, the target title will actually get
// the fake handle for any created Vulkan object, not the original Vulkan
// object handle. GFXR capture layer do the conversion and store the related
// information about the Vulkan object. The class WrapperManager is used to
// map the fake handle to Vulkan object wrapper struct. Currently it support
// the fake handle is a global ID.
class WrapperManager
{
  public:
    void Add(uint64_t id, void* wrapper)
    {
        const std::lock_guard<std::mutex> lock(mutex_);
        wrapper_map_[id] = wrapper;
    }

    void* Get(uint64_t id)
    {
        const std::lock_guard<std::mutex> lock(mutex_);
        auto                              found = wrapper_map_.find(id);
        if (found == wrapper_map_.end())
        {
            return nullptr;
        }
        else
        {
            return found->second;
        }
    }

    void Remove(uint64_t id)
    {
        const std::lock_guard<std::mutex> lock(mutex_);
        wrapper_map_.erase(id);
    }

    static WrapperManager* GetInstance() { return instance_; }

  private:
    std::mutex                          mutex_;
    std::unordered_map<uint64_t, void*> wrapper_map_;
    static WrapperManager*              instance_;
};

template <typename T>
T GetWrapperPointerFromHandle(typename std::remove_pointer<T>::type::HandleType handle)
{
    T wrapper = reinterpret_cast<T>(WrapperManager::GetInstance()->Get(VK_HANDLE_TO_UINT64(handle)));
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING("The Vulkan object with the following handle %" PRId64
                             " was already destroyed but still being used.",
                             handle);
    }
    return wrapper;
}

template <>
inline InstanceWrapper* GetWrapperPointerFromHandle<InstanceWrapper*>(VkInstance handle)
{
    return reinterpret_cast<InstanceWrapper*>(handle);
}

template <>
inline const InstanceWrapper* GetWrapperPointerFromHandle<const InstanceWrapper*>(VkInstance handle)
{
    return reinterpret_cast<const InstanceWrapper*>(handle);
}

template <>
inline PhysicalDeviceWrapper* GetWrapperPointerFromHandle<PhysicalDeviceWrapper*>(VkPhysicalDevice handle)
{
    return reinterpret_cast<PhysicalDeviceWrapper*>(handle);
}

template <>
inline const PhysicalDeviceWrapper* GetWrapperPointerFromHandle<const PhysicalDeviceWrapper*>(VkPhysicalDevice handle)
{
    return reinterpret_cast<const PhysicalDeviceWrapper*>(handle);
}

template <>
inline DeviceWrapper* GetWrapperPointerFromHandle<DeviceWrapper*>(VkDevice handle)
{
    return reinterpret_cast<DeviceWrapper*>(handle);
}

template <>
inline const DeviceWrapper* GetWrapperPointerFromHandle<const DeviceWrapper*>(VkDevice handle)
{
    return reinterpret_cast<const DeviceWrapper*>(handle);
}

template <>
inline QueueWrapper* GetWrapperPointerFromHandle<QueueWrapper*>(VkQueue handle)
{
    return reinterpret_cast<QueueWrapper*>(handle);
}

template <>
inline const QueueWrapper* GetWrapperPointerFromHandle<const QueueWrapper*>(VkQueue handle)
{
    return reinterpret_cast<const QueueWrapper*>(handle);
}

template <>
inline CommandBufferWrapper* GetWrapperPointerFromHandle<CommandBufferWrapper*>(VkCommandBuffer handle)
{
    return reinterpret_cast<CommandBufferWrapper*>(handle);
}

template <>
inline const CommandBufferWrapper* GetWrapperPointerFromHandle<const CommandBufferWrapper*>(VkCommandBuffer handle)
{
    return reinterpret_cast<const CommandBufferWrapper*>(handle);
}

typedef format::HandleId (*PFN_GetHandleId)();

template <typename T>
T GetWrappedHandle(const T& handle)
{
    // The parameter handle is a handle ID for non-dispatch handle,
    // it's not a pointer to wrapper struct.
    if (handle != VK_NULL_HANDLE)
    {
        void* wrapperPointer = WrapperManager::GetInstance()->Get(VK_HANDLE_TO_UINT64(handle));
        if (wrapperPointer == nullptr)
        {
            GFXRECON_LOG_WARNING("The Vulkan object with the following handle %" PRId64
                                 " was already destroyed but still being used.",
                                 VK_HANDLE_TO_UINT64(handle));
        }
        return (wrapperPointer != nullptr) ? reinterpret_cast<HandleWrapper<T>*>(wrapperPointer)->handle
                                           : VK_NULL_HANDLE;
    }
    else
    {
        return VK_NULL_HANDLE;
    }
}

template <>
inline VkInstance GetWrappedHandle<VkInstance>(const VkInstance& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<VkInstance>*>(handle)->handle : VK_NULL_HANDLE;
}

template <>
inline VkPhysicalDevice GetWrappedHandle<VkPhysicalDevice>(const VkPhysicalDevice& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<VkPhysicalDevice>*>(handle)->handle
                                      : VK_NULL_HANDLE;
}

template <>
inline VkDevice GetWrappedHandle<VkDevice>(const VkDevice& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<VkDevice>*>(handle)->handle : VK_NULL_HANDLE;
}

template <>
inline VkQueue GetWrappedHandle<VkQueue>(const VkQueue& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<VkQueue>*>(handle)->handle : VK_NULL_HANDLE;
}

template <>
inline VkCommandBuffer GetWrappedHandle<VkCommandBuffer>(const VkCommandBuffer& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<VkCommandBuffer>*>(handle)->handle
                                      : VK_NULL_HANDLE;
}

template <typename T>
format::HandleId GetWrappedId(const T& handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // The parameter handle is a handle ID for non-dispatch handle,
        // it's not a pointer to wrapper struct.
        void* wrapperPointer = WrapperManager::GetInstance()->Get(VK_HANDLE_TO_UINT64(handle));
        if (wrapperPointer == nullptr)
        {
            GFXRECON_LOG_WARNING("The Vulkan object with the following handle %" PRId64
                                 " was already destroyed but still being used.",
                                 VK_HANDLE_TO_UINT64(handle));
        }
        return (wrapperPointer != nullptr) ? reinterpret_cast<HandleWrapper<T>*>(wrapperPointer)->handle_id : 0;
    }
    else
    {
        return 0;
    }
}

template <>
inline format::HandleId GetWrappedId(const VkInstance& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<VkInstance>*>(handle)->handle_id : 0;
}

template <>
inline format::HandleId GetWrappedId(const VkPhysicalDevice& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<VkPhysicalDevice>*>(handle)->handle_id : 0;
}

template <>
inline format::HandleId GetWrappedId(const VkDevice& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<VkDevice>*>(handle)->handle_id : 0;
}

template <>
inline format::HandleId GetWrappedId(const VkQueue& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<VkQueue>*>(handle)->handle_id : 0;
}

template <>
inline format::HandleId GetWrappedId(const VkCommandBuffer& handle)
{
    return (handle != VK_NULL_HANDLE) ? reinterpret_cast<HandleWrapper<VkCommandBuffer>*>(handle)->handle_id : 0;
}

uint64_t GetWrappedHandle(uint64_t, VkObjectType object_type);

uint64_t GetWrappedHandle(uint64_t object, VkDebugReportObjectTypeEXT object_type);

uint64_t GetWrappedId(uint64_t, VkObjectType object_type);

uint64_t GetWrappedId(uint64_t object, VkDebugReportObjectTypeEXT object_type);

inline const InstanceTable* GetInstanceTable(VkInstance handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapperPointerFromHandle<const InstanceWrapper*>(handle);
    return &wrapper->layer_table;
}

inline const InstanceTable* GetInstanceTable(VkPhysicalDevice handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapperPointerFromHandle<const PhysicalDeviceWrapper*>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const DeviceTable* GetDeviceTable(VkDevice handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapperPointerFromHandle<const DeviceWrapper*>(handle);
    return &wrapper->layer_table;
}

inline const DeviceTable* GetDeviceTable(VkQueue handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapperPointerFromHandle<const QueueWrapper*>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const DeviceTable* GetDeviceTable(VkCommandBuffer handle)
{
    assert(handle != VK_NULL_HANDLE);
    auto wrapper = GetWrapperPointerFromHandle<const CommandBufferWrapper*>(handle);
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
    assert(handle != nullptr);
    if ((*handle) != VK_NULL_HANDLE)
    {
        Wrapper* wrapper      = new Wrapper;
        wrapper->dispatch_key = *reinterpret_cast<void**>(*handle);
        wrapper->handle       = (*handle);
        wrapper->handle_id    = get_id();
        WrapperManager::GetInstance()->Add(wrapper->handle_id, reinterpret_cast<void*>(wrapper));
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
        (*handle)          = UINT64_TO_VK_HANDLE(typename Wrapper::HandleType, wrapper->handle_id);
        WrapperManager::GetInstance()->Add(wrapper->handle_id, reinterpret_cast<void*>(wrapper));
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

    auto parent_wrapper = GetWrapperPointerFromHandle<InstanceWrapper*>(parent);

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

        wrapper                  = GetWrapperPointerFromHandle<PhysicalDeviceWrapper*>(*handle);
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

    auto parent_wrapper = GetWrapperPointerFromHandle<DeviceWrapper*>(parent);

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

        wrapper                  = GetWrapperPointerFromHandle<QueueWrapper*>(*handle);
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
    auto parent_wrapper    = GetWrapperPointerFromHandle<DeviceWrapper*>(parent);
    auto co_parent_wrapper = GetWrapperPointerFromHandle<CommandPoolWrapper*>(co_parent);

    auto wrapper = GetWrapperPointerFromHandle<CommandBufferWrapper*>(*handle);

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
    auto parent_wrapper = GetWrapperPointerFromHandle<DescriptorPoolWrapper*>(co_parent);

    auto wrapper = GetWrapperPointerFromHandle<DescriptorSetWrapper*>(*handle);

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
        auto parent_wrapper = GetWrapperPointerFromHandle<PhysicalDeviceWrapper*>(parent);

        // Filter duplicate display retrieval.
        DisplayKHRWrapper* wrapper = nullptr;
        for (auto entry : parent_wrapper->child_displays)
        {
            if (entry->handle == *handle)
            {
                wrapper = entry;
                break;
            }
        }

        if (wrapper != nullptr)
        {
            (*handle) = UINT64_TO_VK_HANDLE(VkDisplayKHR, wrapper->handle_id);
        }
        else
        {
            CreateWrappedNonDispatchHandle<DisplayKHRWrapper>(handle, get_id);
            parent_wrapper->child_displays.push_back(GetWrapperPointerFromHandle<DisplayKHRWrapper*>(*handle));
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

    auto parent_wrapper = GetWrapperPointerFromHandle<SwapchainKHRWrapper*>(co_parent);

    // Filter duplicate display retrieval.
    ImageWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_images)
    {
        if (entry->handle == *handle)
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper != nullptr)
    {
        (*handle) = UINT64_TO_VK_HANDLE(VkImage, wrapper->handle_id);
    }
    else
    {
        CreateWrappedNonDispatchHandle<ImageWrapper>(handle, get_id);
        auto image_wrapper                = GetWrapperPointerFromHandle<ImageWrapper*>(*handle);
        image_wrapper->is_swapchain_image = true;
        parent_wrapper->child_images.push_back(image_wrapper);
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

    auto parent_wrapper = GetWrapperPointerFromHandle<DisplayKHRWrapper*>(co_parent);

    // Display modes can either be retrieved or created; filter duplicate display mode retrieval.
    DisplayModeKHRWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_display_modes)
    {
        if (entry->handle == *handle)
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper != nullptr)
    {
        (*handle) = UINT64_TO_VK_HANDLE(VkDisplayModeKHR, wrapper->handle_id);
    }
    else
    {
        CreateWrappedNonDispatchHandle<DisplayModeKHRWrapper>(handle, get_id);
        parent_wrapper->child_display_modes.push_back(GetWrapperPointerFromHandle<DisplayModeKHRWrapper*>(*handle));
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
    // handle is non-dispatch handle because dispatch handle will be processed
    // by the following DestroyWrappedHandle functions for VkInstance, VkDevice
    // and VkCommandBuffer.
    if (handle != VK_NULL_HANDLE)
    {
        Wrapper* wrapper = GetWrapperPointerFromHandle<Wrapper*>(handle);
        if (wrapper != nullptr)
        {
            WrapperManager::GetInstance()->Remove(VK_HANDLE_TO_UINT64(handle));
            delete reinterpret_cast<Wrapper*>(wrapper);
        }
        else
        {
            GFXRECON_LOG_WARNING("The Vulkan object with the following handle ID %" PRId64
                                 " was destroyed multiple times.",
                                 VK_HANDLE_TO_UINT64(handle));
        }
    }
}

template <>
inline void DestroyWrappedHandle<InstanceWrapper>(VkInstance handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapperPointerFromHandle<InstanceWrapper*>(handle);

        for (auto physical_device_wrapper : wrapper->child_physical_devices)
        {
            for (auto display_wrapper : physical_device_wrapper->child_displays)
            {
                for (auto display_mode_wrapper : display_wrapper->child_display_modes)
                {
                    WrapperManager::GetInstance()->Remove(static_cast<uint64_t>(display_mode_wrapper->handle_id));
                    delete display_mode_wrapper;
                }
                WrapperManager::GetInstance()->Remove(static_cast<uint64_t>(display_wrapper->handle_id));
                delete display_wrapper;
            }
            WrapperManager::GetInstance()->Remove(static_cast<uint64_t>(physical_device_wrapper->handle_id));
            delete physical_device_wrapper;
        }
        WrapperManager::GetInstance()->Remove(static_cast<uint64_t>(wrapper->handle_id));
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<DeviceWrapper>(VkDevice handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapperPointerFromHandle<DeviceWrapper*>(handle);

        for (auto queue_wrapper : wrapper->child_queues)
        {
            WrapperManager::GetInstance()->Remove(static_cast<uint64_t>(queue_wrapper->handle_id));
            delete queue_wrapper;
        }
        WrapperManager::GetInstance()->Remove(static_cast<uint64_t>(wrapper->handle_id));
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<CommandBufferWrapper>(VkCommandBuffer handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Remove from parent list.
        auto wrapper = GetWrapperPointerFromHandle<CommandBufferWrapper*>(handle);
        wrapper->parent_pool->child_buffers.erase(wrapper->handle_id);
        WrapperManager::GetInstance()->Remove(static_cast<uint64_t>(wrapper->handle_id));
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<CommandPoolWrapper>(VkCommandPool handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapperPointerFromHandle<CommandPoolWrapper*>(handle);
        if (wrapper != nullptr)
        {
            for (const auto& buffer_wrapper : wrapper->child_buffers)
            {
                WrapperManager::GetInstance()->Remove(static_cast<uint64_t>(buffer_wrapper.second->handle_id));
                delete buffer_wrapper.second;
            }
            WrapperManager::GetInstance()->Remove(static_cast<uint64_t>(wrapper->handle_id));
            delete wrapper;
        }
        else
        {
            GFXRECON_LOG_WARNING("The VkCommandPool object with the following handle ID %" PRId64
                                 " was destroyed multiple times.",
                                 VK_HANDLE_TO_UINT64(handle));
        }
    }
}

template <>
inline void DestroyWrappedHandle<DescriptorSetWrapper>(VkDescriptorSet handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Remove from parent list.
        auto wrapper = GetWrapperPointerFromHandle<DescriptorSetWrapper*>(handle);
        if (wrapper != nullptr)
        {
            wrapper->parent_pool->child_sets.erase(wrapper->handle_id);
            WrapperManager::GetInstance()->Remove(wrapper->handle_id);
            delete wrapper;
        }
        else
        {
            GFXRECON_LOG_WARNING("The VkDescriptorSet object with the following handle ID %" PRId64
                                 " was destroyed multiple times.",
                                 VK_HANDLE_TO_UINT64(handle));
        }
    }
}

template <>
inline void DestroyWrappedHandle<DescriptorPoolWrapper>(VkDescriptorPool handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapperPointerFromHandle<DescriptorPoolWrapper*>(handle);
        if (wrapper != nullptr)
        {
            for (const auto& set_wrapper : wrapper->child_sets)
            {
                WrapperManager::GetInstance()->Remove(set_wrapper.second->handle_id);
                delete set_wrapper.second;
            }
            WrapperManager::GetInstance()->Remove(wrapper->handle_id);
            delete wrapper;
        }
        else
        {
            GFXRECON_LOG_WARNING("The VkDescriptorPool object with the following handle ID %" PRId64
                                 " was destroyed multiple times.",
                                 VK_HANDLE_TO_UINT64(handle));
        }
    }
}

template <>
inline void DestroyWrappedHandle<SwapchainKHRWrapper>(VkSwapchainKHR handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapperPointerFromHandle<SwapchainKHRWrapper*>(handle);
        if (wrapper != nullptr)
        {
            for (auto image_wrapper : wrapper->child_images)
            {
                WrapperManager::GetInstance()->Remove(image_wrapper->handle_id);
                delete image_wrapper;
            }
            WrapperManager::GetInstance()->Remove(wrapper->handle_id);
            delete wrapper;
        }
        else
        {
            GFXRECON_LOG_WARNING("The VkSwapchainKHR object with the following handle ID %" PRId64
                                 " was released multiple times.",
                                 VK_HANDLE_TO_UINT64(handle));
        }
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
    auto wrapper = GetWrapperPointerFromHandle<DescriptorPoolWrapper*>(handle);
    for (const auto& set_wrapper : wrapper->child_sets)
    {
        WrapperManager::GetInstance()->Remove(set_wrapper.second->handle_id);
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
