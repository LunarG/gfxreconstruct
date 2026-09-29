/*
** Copyright (c) 2026 Arm Limited <open-source-office@arm.com>
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

#include "decode/vulkan_native_call_callbacks.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanNativeCallCallbacks::Register(const VulkanNativeCallbackEntry& entry)
{
    if (entry.callback != nullptr)
    {
        callbacks_[entry.name] = entry.callback;
    }
    else
    {
        callbacks_.erase(entry.name);
    }
}

PFN_vkVoidFunction VulkanNativeCallCallbacks::Resolve(const VulkanNativeCallContext& context)
{
    const auto entry = callbacks_.find(context.name);
    if (entry == callbacks_.end())
    {
        ReportError(context, VulkanNativeCallErrorCode::kMissingCallback);
        return nullptr;
    }
    return entry->second;
}

void VulkanNativeCallCallbacks::UnsupportedCall(const VulkanNativeCallContext& context)
{
    ReportError(context, VulkanNativeCallErrorCode::kUnsupportedCommand);
}

void VulkanNativeCallCallbacks::InvalidMemoryUpdate(uint64_t block_index, uint64_t thread_id)
{
    const VulkanNativeCallContext context = { { block_index, thread_id }, 0, "FillMemoryCommand", nullptr, 0 };
    ReportError(context, VulkanNativeCallErrorCode::kInvalidMemoryUpdate, false);
}

void VulkanNativeCallCallbacks::ClearError()
{
    last_error_  = {};
    fatal_error_ = false;
}

void VulkanNativeCallCallbacks::SetMissingCallbackPolicy(VulkanNativeMissingCallbackPolicy policy)
{
    missing_callback_policy_ = policy;
}

VulkanNativeMissingCallbackPolicy VulkanNativeCallCallbacks::GetMissingCallbackPolicy() const
{
    return missing_callback_policy_;
}

bool VulkanNativeCallCallbacks::HasFatalError() const
{
    return fatal_error_;
}

const VulkanNativeCallError& VulkanNativeCallCallbacks::GetLastError() const
{
    return last_error_;
}

void VulkanNativeCallCallbacks::SetPreCallHook(CallHook hook, void* user_data)
{
    pre_call_ = { hook, user_data };
}

void VulkanNativeCallCallbacks::SetPostCallHook(CallHook hook, void* user_data)
{
    post_call_ = { hook, user_data };
}

void VulkanNativeCallCallbacks::SetMissingCallbackHook(CallHook hook, void* user_data)
{
    missing_callback_ = { hook, user_data };
}

void VulkanNativeCallCallbacks::SetMemoryUpdateCallback(MemoryUpdateCallback callback, void* user_data)
{
    memory_update_ = { callback, user_data };
}

bool VulkanNativeCallCallbacks::HasMemoryUpdateCallback() const
{
    return memory_update_.callback != nullptr;
}

void VulkanNativeCallCallbacks::SetDeviceMemoryPropertiesCallback(DeviceMemoryPropertiesCallback callback,
                                                                  void*                          user_data)
{
    device_memory_properties_ = { callback, user_data };
}

bool VulkanNativeCallCallbacks::HasDeviceMemoryPropertiesCallback() const
{
    return device_memory_properties_.callback != nullptr;
}

void VulkanNativeCallCallbacks::SetResourceInitializationBeginCallback(ResourceInitializationBeginCallback callback,
                                                                       void*                               user_data)
{
    resource_initialization_begin_ = { callback, user_data };
}

void VulkanNativeCallCallbacks::SetBufferInitializationCallback(BufferInitializationCallback callback, void* user_data)
{
    buffer_initialization_ = { callback, user_data };
}

void VulkanNativeCallCallbacks::SetImageInitializationCallback(ImageInitializationCallback callback, void* user_data)
{
    image_initialization_ = { callback, user_data };
}

void VulkanNativeCallCallbacks::SetResourceInitializationEndCallback(ResourceInitializationEndCallback callback,
                                                                     void*                             user_data)
{
    resource_initialization_end_ = { callback, user_data };
}

void VulkanNativeCallCallbacks::SetDeviceAddressFixupCallback(DeviceAddressFixupCallback callback, void* user_data)
{
    device_address_fixup_ = { callback, user_data };
}

void VulkanNativeCallCallbacks::SetShaderGroupHandleFixupCallback(ShaderGroupHandleFixupCallback callback,
                                                                  void*                          user_data)
{
    shader_group_handle_fixup_ = { callback, user_data };
}

void VulkanNativeCallCallbacks::SetUnhandledMetaCommandCallback(UnhandledMetaCommandCallback callback, void* user_data)
{
    unhandled_meta_command_ = { callback, user_data };
}

void VulkanNativeCallCallbacks::SetOpaqueAddressCallback(OpaqueAddressCallback callback, void* user_data)
{
    opaque_address_ = { callback, user_data };
}

void VulkanNativeCallCallbacks::SetAccelerationStructuresBuildCallback(AccelerationStructuresBuildCallback callback,
                                                                       void*                               user_data)
{
    acceleration_structures_build_ = { callback, user_data };
}

void VulkanNativeCallCallbacks::SetAccelerationStructuresCopyCallback(AccelerationStructuresCopyCallback callback,
                                                                      void*                              user_data)
{
    acceleration_structures_copy_ = { callback, user_data };
}

void VulkanNativeCallCallbacks::SetAccelerationStructureWritePropertiesCallback(
    AccelerationStructureWritePropertiesCallback callback, void* user_data)
{
    acceleration_structure_write_properties_ = { callback, user_data };
}

bool VulkanNativeCallCallbacks::HasResourceInitializationBeginCallback() const
{
    return resource_initialization_begin_.callback != nullptr;
}

bool VulkanNativeCallCallbacks::HasBufferInitializationCallback() const
{
    return buffer_initialization_.callback != nullptr;
}

bool VulkanNativeCallCallbacks::HasImageInitializationCallback() const
{
    return image_initialization_.callback != nullptr;
}

bool VulkanNativeCallCallbacks::HasResourceInitializationEndCallback() const
{
    return resource_initialization_end_.callback != nullptr;
}

bool VulkanNativeCallCallbacks::HasDeviceAddressFixupCallback() const
{
    return device_address_fixup_.callback != nullptr;
}

bool VulkanNativeCallCallbacks::HasShaderGroupHandleFixupCallback() const
{
    return shader_group_handle_fixup_.callback != nullptr;
}

bool VulkanNativeCallCallbacks::HasOpaqueAddressCallback() const
{
    return opaque_address_.callback != nullptr;
}

bool VulkanNativeCallCallbacks::HasAccelerationStructuresBuildCallback() const
{
    return acceleration_structures_build_.callback != nullptr;
}

bool VulkanNativeCallCallbacks::HasAccelerationStructuresCopyCallback() const
{
    return acceleration_structures_copy_.callback != nullptr;
}

bool VulkanNativeCallCallbacks::HasAccelerationStructureWritePropertiesCallback() const
{
    return acceleration_structure_write_properties_.callback != nullptr;
}

void VulkanNativeCallCallbacks::UnhandledMetaCommand(const VulkanUnhandledMetaCommand& command) const
{
    if (unhandled_meta_command_.callback != nullptr)
    {
        unhandled_meta_command_.callback(unhandled_meta_command_.user_data, command);
    }
}

void VulkanNativeCallCallbacks::OpaqueAddress(const VulkanOpaqueAddress& opaque_address) const
{
    if (opaque_address_.callback != nullptr)
    {
        opaque_address_.callback(opaque_address_.user_data, opaque_address);
    }
}

void VulkanNativeCallCallbacks::AccelerationStructuresBuild(const VulkanAccelerationStructuresBuild& build) const
{
    if (acceleration_structures_build_.callback != nullptr)
    {
        acceleration_structures_build_.callback(acceleration_structures_build_.user_data, build);
    }
}

void VulkanNativeCallCallbacks::AccelerationStructuresCopy(const VulkanAccelerationStructuresCopy& copy) const
{
    if (acceleration_structures_copy_.callback != nullptr)
    {
        acceleration_structures_copy_.callback(acceleration_structures_copy_.user_data, copy);
    }
}

void VulkanNativeCallCallbacks::AccelerationStructureWriteProperties(
    const VulkanAccelerationStructureWriteProperties& write) const
{
    if (acceleration_structure_write_properties_.callback != nullptr)
    {
        acceleration_structure_write_properties_.callback(acceleration_structure_write_properties_.user_data, write);
    }
}

void VulkanNativeCallCallbacks::PreCall(const VulkanNativeCallContext& context) const
{
    if (pre_call_.callback != nullptr)
    {
        pre_call_.callback(pre_call_.user_data, context);
    }
}

void VulkanNativeCallCallbacks::PostCall(const VulkanNativeCallContext& context) const
{
    if (post_call_.callback != nullptr)
    {
        post_call_.callback(post_call_.user_data, context);
    }
}

void VulkanNativeCallCallbacks::MissingCallback(const VulkanNativeCallContext& context) const
{
    if (missing_callback_.callback != nullptr)
    {
        missing_callback_.callback(missing_callback_.user_data, context);
    }
}

void VulkanNativeCallCallbacks::MemoryUpdate(const VulkanMemoryUpdate& update) const
{
    if (memory_update_.callback != nullptr)
    {
        memory_update_.callback(memory_update_.user_data, update);
    }
}

void VulkanNativeCallCallbacks::DeviceMemoryProperties(const VulkanDeviceMemoryProperties& properties) const
{
    if (device_memory_properties_.callback != nullptr)
    {
        device_memory_properties_.callback(device_memory_properties_.user_data, properties);
    }
}

void VulkanNativeCallCallbacks::ResourceInitializationBegin(
    const VulkanResourceInitializationBegin& initialization) const
{
    if (resource_initialization_begin_.callback != nullptr)
    {
        resource_initialization_begin_.callback(resource_initialization_begin_.user_data, initialization);
    }
}

void VulkanNativeCallCallbacks::BufferInitialization(const VulkanBufferInitialization& initialization) const
{
    if (buffer_initialization_.callback != nullptr)
    {
        buffer_initialization_.callback(buffer_initialization_.user_data, initialization);
    }
}

void VulkanNativeCallCallbacks::ImageInitialization(const VulkanImageInitialization& initialization) const
{
    if (image_initialization_.callback != nullptr)
    {
        image_initialization_.callback(image_initialization_.user_data, initialization);
    }
}

void VulkanNativeCallCallbacks::ResourceInitializationEnd(const VulkanResourceInitializationEnd& initialization) const
{
    if (resource_initialization_end_.callback != nullptr)
    {
        resource_initialization_end_.callback(resource_initialization_end_.user_data, initialization);
    }
}

void VulkanNativeCallCallbacks::DeviceAddressFixups(const VulkanDeviceAddressFixups& fixups) const
{
    if (device_address_fixup_.callback != nullptr)
    {
        device_address_fixup_.callback(device_address_fixup_.user_data, fixups);
    }
}

void VulkanNativeCallCallbacks::ShaderGroupHandleFixups(const VulkanShaderGroupHandleFixups& fixups) const
{
    if (shader_group_handle_fixup_.callback != nullptr)
    {
        shader_group_handle_fixup_.callback(shader_group_handle_fixup_.user_data, fixups);
    }
}

void VulkanNativeCallCallbacks::ReportError(const VulkanNativeCallContext& context,
                                            VulkanNativeCallErrorCode      code,
                                            bool                           notify_hook)
{
    last_error_.code      = code;
    last_error_.name      = context.name != nullptr ? context.name : "";
    last_error_.call_id   = context.call_id;
    last_error_.call_info = context.call_info;

    fatal_error_ = missing_callback_policy_ == VulkanNativeMissingCallbackPolicy::kFail;
    if (notify_hook)
    {
        MissingCallback(context);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
