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

#ifndef GFXRECON_DECODE_VULKAN_NATIVE_CALL_CALLBACKS_H
#define GFXRECON_DECODE_VULKAN_NATIVE_CALL_CALLBACKS_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct VulkanNativeCallInfo
{
    uint64_t index{ 0 };
    uint64_t thread_id{ 0 };
};

/// Information made available immediately before and after a native Vulkan callback.
/// return_value is only valid for the duration of the hook.
struct VulkanNativeCallContext
{
    VulkanNativeCallInfo call_info;
    uint32_t             call_id{ 0 };
    const char*          name{ nullptr };
    const void*          return_value{ nullptr };
    size_t               return_value_size{ 0 };
};

/// A captured write to mapped Vulkan device memory.
/// data is only valid for the duration of the callback. memory_offset is
/// relative to the start of the VkDeviceMemory allocation, not the mapping.
struct VulkanMemoryUpdate
{
    uint64_t       block_index{ 0 };
    uint64_t       thread_id{ 0 };
    VkDeviceMemory memory{ VK_NULL_HANDLE };
    VkDeviceSize   memory_offset{ 0 };
    size_t         data_size{ 0 };
    const uint8_t* data{ nullptr };
};

/// Captured physical-device memory properties supplied by the
/// SetDeviceMemoryPropertiesCommand metadata block.
struct VulkanDeviceMemoryProperties
{
    uint64_t                         block_index{ 0 };
    uint64_t                         thread_id{ 0 };
    VkPhysicalDevice                 physical_device{ VK_NULL_HANDLE };
    VkPhysicalDeviceMemoryProperties memory_properties{};
};

struct VulkanResourceInitializationBegin
{
    uint64_t block_index{ 0 };
    uint64_t thread_id{ 0 };
    VkDevice device{ VK_NULL_HANDLE };
    uint64_t total_copy_size{ 0 };
    uint64_t max_copy_size{ 0 };
};

/// Captured initial buffer contents. data is valid only for the duration of
/// the callback.
struct VulkanBufferInitialization
{
    uint64_t       block_index{ 0 };
    uint64_t       thread_id{ 0 };
    VkDevice       device{ VK_NULL_HANDLE };
    VkBuffer       buffer{ VK_NULL_HANDLE };
    size_t         data_size{ 0 };
    const uint8_t* data{ nullptr };
};

/// Captured initial image contents. level_sizes and data are valid only for
/// the duration of the callback.
struct VulkanImageInitialization
{
    uint64_t           block_index{ 0 };
    uint64_t           thread_id{ 0 };
    VkDevice           device{ VK_NULL_HANDLE };
    VkImage            image{ VK_NULL_HANDLE };
    VkImageAspectFlags aspect_mask{ 0 };
    VkImageLayout      layout{ VK_IMAGE_LAYOUT_UNDEFINED };
    size_t             level_count{ 0 };
    const uint64_t*    level_sizes{ nullptr };
    size_t             data_size{ 0 };
    const uint8_t*     data{ nullptr };
};

struct VulkanResourceInitializationEnd
{
    uint64_t block_index{ 0 };
    uint64_t thread_id{ 0 };
    VkDevice device{ VK_NULL_HANDLE };
};

struct VulkanDeviceAddressFixup
{
    uint64_t object_id{ 0 };
    uint64_t size{ 0 };
    uint64_t original_address{ 0 };
    uint64_t adjusted_address{ 0 };
    uint64_t data_offset{ 0 };
};

/// Device-address locations associated with an initialization payload. fixups
/// is valid only for the duration of the callback.
struct VulkanDeviceAddressFixups
{
    uint64_t                        block_index{ 0 };
    uint64_t                        relation_id{ 0 };
    size_t                          fixup_count{ 0 };
    const VulkanDeviceAddressFixup* fixups{ nullptr };
};

constexpr size_t kVulkanShaderGroupHandleSize = 32;

struct VulkanShaderGroupHandleFixup
{
    VkPipeline pipeline{ VK_NULL_HANDLE };
    uint32_t   group{ 0 };
    uint32_t   group_size{ 0 };
    uint64_t   data_offset{ 0 };
    uint8_t    original_handle[kVulkanShaderGroupHandleSize]{};
};

/// Shader-group-handle locations associated with an initialization payload.
/// fixups is valid only for the duration of the callback.
struct VulkanShaderGroupHandleFixups
{
    uint64_t                            block_index{ 0 };
    uint64_t                            relation_id{ 0 };
    size_t                              fixup_count{ 0 };
    const VulkanShaderGroupHandleFixup* fixups{ nullptr };
};

/// Captured instance data associated with a top-level acceleration-structure
/// build. instances is valid only for the duration of the callback.
struct VulkanAccelerationStructureInstanceBuffer
{
    uint32_t                                  build_info_index{ 0 };
    uint32_t                                  geometry_index{ 0 };
    VkDeviceAddress                           source_device_address{ 0 };
    size_t                                    instance_count{ 0 };
    const VkAccelerationStructureInstanceKHR* instances{ nullptr };
};

/// Device-side acceleration-structure copies reconstructed from trim-state
/// metadata. infos is valid only for the duration of the callback.
struct VulkanAccelerationStructuresCopy
{
    uint64_t                                  block_index{ 0 };
    VkDevice                                  device{ VK_NULL_HANDLE };
    size_t                                    info_count{ 0 };
    const VkCopyAccelerationStructureInfoKHR* infos{ nullptr };
};

struct VulkanAccelerationStructureWriteProperties
{
    uint64_t                   block_index{ 0 };
    VkDevice                   device{ VK_NULL_HANDLE };
    VkQueryType                query_type{ VK_QUERY_TYPE_OCCLUSION };
    VkAccelerationStructureKHR acceleration_structure{ VK_NULL_HANDLE };
};

/// A device-side acceleration-structure build reconstructed from the
/// kVulkanBuildAccelerationStructuresCommand metacommand. All pointer members
/// are valid only for the duration of the callback.
struct VulkanAccelerationStructuresBuild
{
    uint64_t                                               block_index{ 0 };
    VkDevice                                               device{ VK_NULL_HANDLE };
    uint32_t                                               info_count{ 0 };
    const VkAccelerationStructureBuildGeometryInfoKHR*     build_infos{ nullptr };
    const VkAccelerationStructureBuildRangeInfoKHR* const* range_infos{ nullptr };
    size_t                                                 instance_buffer_count{ 0 };
    const VulkanAccelerationStructureInstanceBuffer*       instance_buffers{ nullptr };
};

/// A parsed metacommand for which the native importer has no registered
/// handler. metadata_id contains the API family and metadata type encoded in
/// the trace format.
struct VulkanUnhandledMetaCommand
{
    uint64_t block_index{ 0 };
    uint32_t metadata_id{ 0 };
};

/// A captured opaque address associated with a Vulkan object. The trace
/// metacommand does not encode the object type, so object_type is UNKNOWN and
/// object_handle is zero when the native reader cannot resolve object_id.
struct VulkanOpaqueAddress
{
    uint64_t        block_index{ 0 };
    uint64_t        thread_id{ 0 };
    VkDevice        device{ VK_NULL_HANDLE };
    uint64_t        object_id{ 0 };
    VkDeviceAddress address{ 0 };
    VkObjectType    object_type{ VK_OBJECT_TYPE_UNKNOWN };
    uint64_t        object_handle{ 0 };
};

struct VulkanNativeCommandInfo
{
    const char* name{ nullptr };
    uint32_t    call_id{ 0 };
};

struct VulkanNativeCallbackEntry
{
    const char*        name{ nullptr };
    PFN_vkVoidFunction callback{ nullptr };
};

enum class VulkanNativeCallbackRegistrationStatus
{
    kSuccess,
    kInvalidEntry,
    kUnsupportedCommand,
    kExternalConsumer
};

struct VulkanNativeCallbackRegistrationError
{
    size_t                                 index{ 0 };
    std::string                            name;
    VulkanNativeCallbackRegistrationStatus status{ VulkanNativeCallbackRegistrationStatus::kSuccess };
};

enum class VulkanNativeMissingCallbackPolicy
{
    kIgnore,
    kFail
};

enum class VulkanNativeCallErrorCode
{
    kNone,
    kMissingCallback,
    kUnsupportedCommand,
    kInvalidMemoryUpdate
};

struct VulkanNativeCallError
{
    VulkanNativeCallErrorCode code{ VulkanNativeCallErrorCode::kNone };
    std::string               name;
    uint32_t                  call_id{ 0 };
    VulkanNativeCallInfo      call_info;
};

class VulkanNativeCallCallbacks
{
  public:
    using CallHook                       = void (*)(void* user_data, const VulkanNativeCallContext& context);
    using MemoryUpdateCallback           = void (*)(void* user_data, const VulkanMemoryUpdate& update);
    using DeviceMemoryPropertiesCallback = void (*)(void* user_data, const VulkanDeviceMemoryProperties& properties);
    using ResourceInitializationBeginCallback = void (*)(void*                                    user_data,
                                                         const VulkanResourceInitializationBegin& initialization);
    using BufferInitializationCallback = void (*)(void* user_data, const VulkanBufferInitialization& initialization);
    using ImageInitializationCallback  = void (*)(void* user_data, const VulkanImageInitialization& initialization);
    using ResourceInitializationEndCallback   = void (*)(void*                                  user_data,
                                                       const VulkanResourceInitializationEnd& initialization);
    using DeviceAddressFixupCallback          = void (*)(void* user_data, const VulkanDeviceAddressFixups& fixups);
    using ShaderGroupHandleFixupCallback      = void (*)(void* user_data, const VulkanShaderGroupHandleFixups& fixups);
    using UnhandledMetaCommandCallback        = void (*)(void* user_data, const VulkanUnhandledMetaCommand& command);
    using OpaqueAddressCallback               = void (*)(void* user_data, const VulkanOpaqueAddress& opaque_address);
    using AccelerationStructuresBuildCallback = void (*)(void*                                    user_data,
                                                         const VulkanAccelerationStructuresBuild& build);
    using AccelerationStructuresCopyCallback  = void (*)(void* user_data, const VulkanAccelerationStructuresCopy& copy);
    using AccelerationStructureWritePropertiesCallback =
        void (*)(void* user_data, const VulkanAccelerationStructureWriteProperties& write);

    void Register(const VulkanNativeCallbackEntry& entry);

    PFN_vkVoidFunction Resolve(const VulkanNativeCallContext& context);

    void UnsupportedCall(const VulkanNativeCallContext& context);

    void InvalidMemoryUpdate(uint64_t block_index, uint64_t thread_id);

    void ClearError();

    void SetMissingCallbackPolicy(VulkanNativeMissingCallbackPolicy policy);

    VulkanNativeMissingCallbackPolicy GetMissingCallbackPolicy() const;

    bool HasFatalError() const;

    const VulkanNativeCallError& GetLastError() const;

    void SetPreCallHook(CallHook hook, void* user_data);

    void SetPostCallHook(CallHook hook, void* user_data);

    void SetMissingCallbackHook(CallHook hook, void* user_data);

    void SetMemoryUpdateCallback(MemoryUpdateCallback callback, void* user_data);

    bool HasMemoryUpdateCallback() const;

    void SetDeviceMemoryPropertiesCallback(DeviceMemoryPropertiesCallback callback, void* user_data);

    bool HasDeviceMemoryPropertiesCallback() const;

    void SetResourceInitializationBeginCallback(ResourceInitializationBeginCallback callback, void* user_data);
    void SetBufferInitializationCallback(BufferInitializationCallback callback, void* user_data);
    void SetImageInitializationCallback(ImageInitializationCallback callback, void* user_data);
    void SetResourceInitializationEndCallback(ResourceInitializationEndCallback callback, void* user_data);
    void SetDeviceAddressFixupCallback(DeviceAddressFixupCallback callback, void* user_data);
    void SetShaderGroupHandleFixupCallback(ShaderGroupHandleFixupCallback callback, void* user_data);
    void SetUnhandledMetaCommandCallback(UnhandledMetaCommandCallback callback, void* user_data);
    void SetOpaqueAddressCallback(OpaqueAddressCallback callback, void* user_data);
    void SetAccelerationStructuresBuildCallback(AccelerationStructuresBuildCallback callback, void* user_data);
    void SetAccelerationStructuresCopyCallback(AccelerationStructuresCopyCallback callback, void* user_data);
    void SetAccelerationStructureWritePropertiesCallback(AccelerationStructureWritePropertiesCallback callback,
                                                         void*                                        user_data);

    bool HasResourceInitializationBeginCallback() const;
    bool HasBufferInitializationCallback() const;
    bool HasImageInitializationCallback() const;
    bool HasResourceInitializationEndCallback() const;
    bool HasDeviceAddressFixupCallback() const;
    bool HasShaderGroupHandleFixupCallback() const;
    bool HasOpaqueAddressCallback() const;
    bool HasAccelerationStructuresBuildCallback() const;
    bool HasAccelerationStructuresCopyCallback() const;
    bool HasAccelerationStructureWritePropertiesCallback() const;

    void PreCall(const VulkanNativeCallContext& context) const;

    void PostCall(const VulkanNativeCallContext& context) const;

    void MissingCallback(const VulkanNativeCallContext& context) const;

    void MemoryUpdate(const VulkanMemoryUpdate& update) const;

    void DeviceMemoryProperties(const VulkanDeviceMemoryProperties& properties) const;

    void ResourceInitializationBegin(const VulkanResourceInitializationBegin& initialization) const;
    void BufferInitialization(const VulkanBufferInitialization& initialization) const;
    void ImageInitialization(const VulkanImageInitialization& initialization) const;
    void ResourceInitializationEnd(const VulkanResourceInitializationEnd& initialization) const;
    void DeviceAddressFixups(const VulkanDeviceAddressFixups& fixups) const;
    void ShaderGroupHandleFixups(const VulkanShaderGroupHandleFixups& fixups) const;
    void UnhandledMetaCommand(const VulkanUnhandledMetaCommand& command) const;
    void OpaqueAddress(const VulkanOpaqueAddress& opaque_address) const;
    void AccelerationStructuresBuild(const VulkanAccelerationStructuresBuild& build) const;
    void AccelerationStructuresCopy(const VulkanAccelerationStructuresCopy& copy) const;
    void AccelerationStructureWriteProperties(const VulkanAccelerationStructureWriteProperties& write) const;

  private:
    struct Hook
    {
        CallHook callback{ nullptr };
        void*    user_data{ nullptr };
    };

    struct MemoryUpdateHook
    {
        MemoryUpdateCallback callback{ nullptr };
        void*                user_data{ nullptr };
    };

    struct DeviceMemoryPropertiesHook
    {
        DeviceMemoryPropertiesCallback callback{ nullptr };
        void*                          user_data{ nullptr };
    };

    template <typename Callback>
    struct MetadataHook
    {
        Callback callback{ nullptr };
        void*    user_data{ nullptr };
    };

    void ReportError(const VulkanNativeCallContext& context, VulkanNativeCallErrorCode code, bool notify_hook = true);

    std::unordered_map<std::string, PFN_vkVoidFunction>        callbacks_;
    Hook                                                       pre_call_;
    Hook                                                       post_call_;
    Hook                                                       missing_callback_;
    MemoryUpdateHook                                           memory_update_;
    DeviceMemoryPropertiesHook                                 device_memory_properties_;
    MetadataHook<ResourceInitializationBeginCallback>          resource_initialization_begin_;
    MetadataHook<BufferInitializationCallback>                 buffer_initialization_;
    MetadataHook<ImageInitializationCallback>                  image_initialization_;
    MetadataHook<ResourceInitializationEndCallback>            resource_initialization_end_;
    MetadataHook<DeviceAddressFixupCallback>                   device_address_fixup_;
    MetadataHook<ShaderGroupHandleFixupCallback>               shader_group_handle_fixup_;
    MetadataHook<UnhandledMetaCommandCallback>                 unhandled_meta_command_;
    MetadataHook<OpaqueAddressCallback>                        opaque_address_;
    MetadataHook<AccelerationStructuresBuildCallback>          acceleration_structures_build_;
    MetadataHook<AccelerationStructuresCopyCallback>           acceleration_structures_copy_;
    MetadataHook<AccelerationStructureWritePropertiesCallback> acceleration_structure_write_properties_;
    VulkanNativeMissingCallbackPolicy missing_callback_policy_{ VulkanNativeMissingCallbackPolicy::kIgnore };
    VulkanNativeCallError             last_error_;
    bool                              fatal_error_{ false };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_NATIVE_CALL_CALLBACKS_H
