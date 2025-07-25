/*
** Copyright (c) 2019-2022 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_OBJECT_INFO_H
#define GFXRECON_DECODE_VULKAN_OBJECT_INFO_H

#include "decode/vulkan_resource_allocator.h"
#include "decode/vulkan_resource_initializer.h"
#include "decode/window.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_instance_util.h"
#include "graphics/vulkan_shader_group_handle.h"
#include "util/defines.h"
#include "util/spirv_parsing_util.h"

#include "vulkan/vulkan.h"

#include <cstdint>
#include <memory>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <future>
#include <optional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

//
// Enumerations defining index values for tables to track array counts reported by Vulkan API calls with variable length
// array parameters.
//
enum InstanceArrayIndices : uint32_t
{
    kInstanceArrayEnumeratePhysicalDevices      = 0,
    kInstanceArrayEnumeratePhysicalDeviceGroups = 1,
    // Aliases for extensions functions that were promoted to core.
    kInstanceArrayEnumeratePhysicalDeviceGroupsKHR = kInstanceArrayEnumeratePhysicalDeviceGroups
};

enum PhysicalDeviceArrayIndices : uint32_t
{
    kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties                           = 0,
    kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties                     = 1,
    kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2                          = 2,
    kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2                    = 3,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR                            = 4,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR                       = 5,
    kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR                              = 6,
    kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR                              = 7,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR                           = 8,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR                      = 9,
    kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT                     = 10,
    kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV                   = 11,
    kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV  = 12,
    kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT                         = 13,
    kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR    = 14,
    kPhysicalDeviceArrayGetPhysicalDeviceToolProperties                                  = 15,
    kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR                         = 16,
    kFramebufferArrayGetFramebufferTilePropertiesQCOM                                    = 17,
    kPhysicalDeviceArrayGetPhysicalDeviceOpticalFlowImageFormatsNV                       = 18,
    kPhysicalDeviceArrayGetPhysicalDeviceVideoFormatPropertiesKHR                        = 19,
    kVideoSessionKHRArrayGetVideoSessionMemoryRequirementsKHR                            = 20,
    kShaderEXTArrayGetShaderBinaryDataEXT                                                = 21,
    kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV = 22,
    kPhysicalDeviceArrayGetPhysicalDeviceCooperativeVectorPropertiesNV                   = 23,

    // Aliases for extensions functions that were promoted to core.
    kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR =
        kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2,
    kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR =
        kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2,
    kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT = kPhysicalDeviceArrayGetPhysicalDeviceToolProperties,
};

enum DeviceArrayIndices : uint32_t
{
    kDeviceArrayGetImageSparseMemoryRequirements2                       = 0,
    kDeviceArrayGetPipelineExecutablePropertiesKHR                      = 1,
    kDeviceArrayGetPipelineExecutableStatisticsKHR                      = 2,
    kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR         = 3,
    kDeviceArrayGetDeviceImageSparseMemoryRequirements                  = 4,
    kDeviceArrayGetEncodedVideoSessionParametersKHR                     = 5,
    kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesKHR = 6,
    kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsKHR    = 7,
    kDeviceArrayGetPipelineBinaryDataKHR                                = 8,

    // Aliases for extensions functions that were promoted to core.
    kDeviceArrayGetImageSparseMemoryRequirements2KHR      = kDeviceArrayGetImageSparseMemoryRequirements2,
    kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR = kDeviceArrayGetDeviceImageSparseMemoryRequirements
};

enum QueueArrayIndices : uint32_t
{
    kQueueArrayGetQueueCheckpointDataNV  = 0,
    kQueueArrayGetQueueCheckpointData2NV = 1
};

enum ImageArrayIndices : uint32_t
{
    kImageArrayGetImageSparseMemoryRequirements = 0
};

enum PipelineCacheArrayIndices : uint32_t
{
    kPipelineCacheArrayGetPipelineCacheData = 0
};

enum PipelineArrayIndices : uint32_t
{
    kPipelineArrayGetShaderInfoAMD = 0
};

enum DisplayKHRArrayIndices : uint32_t
{
    kDisplayKHRArrayGetDisplayModePropertiesKHR  = 0,
    kDisplayKHRArrayGetDisplayModeProperties2KHR = 1
};

enum SurfaceKHRArrayIndices : uint32_t
{
    kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR      = 0,
    kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR = 1,
    kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR   = 2
};

enum SwapchainKHRArrayIndices : uint32_t
{
    kSwapchainKHRArrayGetSwapchainImagesKHR           = 0,
    kSwapchainKHRArrayGetPastPresentationTimingGOOGLE = 1
};

enum ValidationCacheEXTArrayIndices : uint32_t
{
    kValidationCacheEXTArrayGetValidationCacheDataEXT = 0
};

//
// Structures for storing Vulkan object info.
//

struct VulkanReplayDeviceInfo
{
    std::optional<VkPhysicalDeviceProperties>       properties;
    std::optional<VkPhysicalDeviceMemoryProperties> memory_properties;

    // extensions
    std::optional<VkPhysicalDeviceDriverProperties>                   driver_properties;
    std::optional<VkPhysicalDeviceRayTracingPipelinePropertiesKHR>    raytracing_properties;
    std::optional<VkPhysicalDeviceAccelerationStructurePropertiesKHR> acceleration_structure_properties;
};

template <typename T>
struct VulkanObjectInfo
{
    typedef T HandleType;

    // Standard info stored for all Vulkan objects.
    HandleType       handle{ VK_NULL_HANDLE };            // Handle created for the object during replay.
    format::HandleId capture_id{ format::kNullHandleId }; // ID assigned to the object at capture.
    format::HandleId parent_id{ format::kNullHandleId };  // ID of the object's parent instance/device object.
};

template <typename T>
struct handle_create_result_t
{
    VkResult       result = VK_INCOMPLETE;
    std::vector<T> handles;
};

template <typename T>
struct VulkanObjectInfoAsync : public VulkanObjectInfo<T>
{
    // track asynchronous compilation status
    std::shared_future<handle_create_result_t<T>> future;
    uint32_t                                      future_handle_index = 0;
};

// Info for a pool object which other objects will be allocated from.
template <typename T>
struct VulkanPoolInfo : public VulkanObjectInfo<T>
{
    std::unordered_set<format::HandleId> child_ids; // IDs of objects allocated from the pool.
};

// Info for objects that are allocated from pools.
template <typename T>
struct VulkanPoolObjectInfo : public VulkanObjectInfo<T>
{
    format::HandleId pool_id{ format::kNullHandleId }; // ID of the pool that the object was allocated from.
};

//
// Declarations for Vulkan objects without additional replay state info.
//

typedef VulkanObjectInfo<VkEvent>                              VulkanEventInfo;
typedef VulkanObjectInfo<VkQueryPool>                          VulkanQueryPoolInfo;
typedef VulkanObjectInfo<VkPrivateDataSlot>                    VulkanPrivateDataSlotInfo;
typedef VulkanObjectInfo<VkSampler>                            VulkanSamplerInfo;
typedef VulkanPoolInfo<VkCommandPool>                          VulkanCommandPoolInfo;
typedef VulkanObjectInfo<VkSamplerYcbcrConversion>             VulkanSamplerYcbcrConversionInfo;
typedef VulkanObjectInfo<VkDisplayModeKHR>                     VulkanDisplayModeKHRInfo;
typedef VulkanObjectInfo<VkDebugReportCallbackEXT>             VulkanDebugReportCallbackEXTInfo;
typedef VulkanObjectInfo<VkIndirectCommandsLayoutNV>           VulkanIndirectCommandsLayoutNVInfo;
typedef VulkanObjectInfo<VkDebugUtilsMessengerEXT>             VulkanDebugUtilsMessengerEXTInfo;
typedef VulkanObjectInfo<VkAccelerationStructureNV>            VulkanAccelerationStructureNVInfo;
typedef VulkanObjectInfo<VkPerformanceConfigurationINTEL>      VulkanPerformanceConfigurationINTELInfo;
typedef VulkanObjectInfo<VkMicromapEXT>                        VulkanMicromapEXTInfo;
typedef VulkanObjectInfo<VkOpticalFlowSessionNV>               VulkanOpticalFlowSessionNVInfo;
typedef VulkanObjectInfo<VkVideoSessionParametersKHR>          VulkanVideoSessionParametersKHRInfo;
typedef VulkanObjectInfo<VkPipelineBinaryKHR>                  VulkanPipelineBinaryKHRInfo;
typedef VulkanObjectInfo<VkPipelineBinaryCreateInfoKHR>        VulkanPipelineBinaryCreateInfoKHRInfo;
typedef VulkanObjectInfo<VkPipelineBinaryDataInfoKHR>          VulkanPipelineBinaryDataInfoKHRInfo;
typedef VulkanObjectInfo<VkPipelineBinaryDataKHR>              VulkanPipelineBinaryDataKHRInfo;
typedef VulkanObjectInfo<VkPipelineBinaryHandlesInfoKHR>       VulkanPipelineBinaryHandlesInfoKHRInfo;
typedef VulkanObjectInfo<VkPipelineBinaryKeyKHR>               VulkanPipelineBinaryKeyKHRInfo;
typedef VulkanObjectInfo<VkPipelineBinaryKeysAndDataKHR>       VulkanPipelineBinaryKeysAndDataKHRInfo;
typedef VulkanObjectInfo<VkReleaseCapturedPipelineDataInfoKHR> VulkanReleaseCapturedPipelineDataInfoKHRInfo;
typedef VulkanObjectInfo<VkDevicePipelineBinaryInternalCacheControlKHR>
                                                  VulkanDevicePipelineBinaryInternalCacheControlKHRInfo;
typedef VulkanObjectInfo<VkPipelineBinaryInfoKHR> VulkanPipelineBinaryInfoKHRInfo;
typedef VulkanObjectInfo<VkPhysicalDevicePipelineBinaryFeaturesKHR> VulkanPhysicalDevicePipelineBinaryFeaturesKHRInfo;
typedef VulkanObjectInfo<VkPhysicalDevicePipelineBinaryPropertiesKHR>
                                                      VulkanPhysicalDevicePipelineBinaryPropertiesKHRInfo;
typedef VulkanObjectInfo<VkIndirectCommandsLayoutEXT> VulkanIndirectCommandsLayoutEXTInfo;
typedef VulkanObjectInfo<VkIndirectExecutionSetEXT>   VulkanIndirectExecutionSetEXTInfo;
typedef VulkanObjectInfo<VkExternalComputeQueueNV>    VulkanExternalComputeQueueNVInfo;

//
// Declarations for Vulkan objects with additional replay state info.
//

struct VulkanInstanceInfo : public VulkanObjectInfo<VkInstance>
{
    graphics::VulkanInstanceUtilInfo     util_info{};
    std::unordered_map<uint32_t, size_t> array_counts;

    // Capture and replay devices sorted in the order that they were originally retrieved from
    // vkEnumeratePhysicalDevices.
    std::vector<format::HandleId> capture_devices;
    std::vector<VkPhysicalDevice> replay_devices;

    std::unordered_map<VkPhysicalDevice, VulkanReplayDeviceInfo> replay_device_info;

    VkDebugUtilsMessengerEXT debug_messenger{ VK_NULL_HANDLE };
};

struct VulkanPhysicalDeviceInfo : public VulkanObjectInfo<VkPhysicalDevice>
{
    VkInstance parent{ VK_NULL_HANDLE };

    graphics::VulkanInstanceUtilInfo parent_info{};

    std::unordered_map<uint32_t, size_t> array_counts;

    // Capture device properties.
    uint32_t                         capture_api_version{ 0 };
    uint32_t                         capture_driver_version{ 0 };
    uint32_t                         capture_vendor_id{ 0 };
    uint32_t                         capture_device_id{ 0 };
    VkPhysicalDeviceType             capture_device_type{ VK_PHYSICAL_DEVICE_TYPE_OTHER };
    uint8_t                          capture_pipeline_cache_uuid[format::kUuidSize]{};
    std::string                      capture_device_name;
    VkPhysicalDeviceMemoryProperties capture_memory_properties{};

    // capture raytracing (shader-binding-table) properties
    std::optional<VkPhysicalDeviceRayTracingPipelinePropertiesKHR> capture_raytracing_properties = {};

    // Closest matching replay device.
    VulkanReplayDeviceInfo* replay_device_info{ nullptr };

    // Because Vulkan captures unwrapped handles, and layered APIs (like OpenXR)
    // capture wrapped handles, during replay two HandleId values will reference
    // the same VkPhysical device.  The vulkan_alias is the handleId as known by
    // the vulkan_consumers, which will be created/updated, etc, by all Vulkan replay
    // calls, s.t. the information known by the vulkan_consumer need not be duplicated.
    // Operations on this, will use the vulkan_alias as the effective HandleId when set.

    // When Non-null, the GetVkObject will recur on the alias Id
    format::HandleId vulkan_alias{ format::kNullHandleId };
};

struct VulkanDeviceInfo : public VulkanObjectInfo<VkDevice>
{
    VkPhysicalDevice                         parent{ VK_NULL_HANDLE };
    std::unique_ptr<VulkanResourceAllocator> allocator;
    std::unordered_map<uint32_t, size_t>     array_counts;

    std::unordered_map<format::HandleId, uint64_t> opaque_addresses;

    // Map pipeline ID to ray tracing shader group handle capture replay data.
    std::unordered_map<format::HandleId, const std::vector<uint8_t>> shader_group_handles;

    // The following values are only used when loading the initial state for trimmed files.
    std::vector<std::string>                   extensions;
    std::unique_ptr<VulkanResourceInitializer> resource_initializer;

    // Physical device property & feature state at device creation
    graphics::VulkanDevicePropertyFeatureInfo property_feature_info;

    struct EnabledQueueFamilyFlags
    {
        std::unordered_map<uint32_t, VkDeviceQueueCreateFlags> queue_family_creation_flags;
        std::unordered_map<uint32_t, VkDeviceQueueCreateFlags> queue_family_properties_flags;

        std::vector<bool> queue_family_index_enabled;
    } enabled_queue_family_flags;

    std::vector<VkPhysicalDevice> replay_device_group;

    // For use with device deduplication
    bool is_duplicate{ false };
};

struct VulkanQueueInfo : public VulkanObjectInfo<VkQueue>
{
    VkDevice                             parent{ VK_NULL_HANDLE };
    std::unordered_map<uint32_t, size_t> array_counts;
    uint32_t                             family_index;
    uint32_t                             queue_index;
};

struct VulkanSemaphoreInfo : public VulkanObjectInfo<VkSemaphore>
{
    bool is_external{ false };

    // If a null-swapchain/surface interacts with a semaphore, replay needs to shadow signal it until a future call
    // waits on it.
    bool shadow_signaled{ false };
    // Fences can be reset, semaphores can't, so replay needs to know when a semaphore will not be submitted for a wait
    // operation to prevent validation errors around queue forward progress.
    bool forward_progress{ true };
    // If a semaphore is signaled with vkAcquireNextImage and also VkSubmitInfo, then the semaphore needs to be shadow
    // signaled with vkAcquireNextImage and regularly signaled with VkSubmitInfo
    bool signaled{ false };
};

struct VulkanFenceInfo : public VulkanObjectInfo<VkFence>
{
    // If a null-swapchain/surface interacts with a fence, replay needs to to shadow signal it until a future call waits
    // on it.
    bool shadow_signaled{ false };
};

struct VulkanDeviceMemoryInfo : public VulkanObjectInfo<VkDeviceMemory>
{
    VulkanResourceAllocator*            allocator{ nullptr };
    VulkanResourceAllocator::MemoryData allocator_data{ 0 };
};

struct VulkanBufferInfo : public VulkanObjectInfo<VkBuffer>
{
    // The following values are only used for memory portability.
    VulkanResourceAllocator::ResourceData allocator_data{ 0 };
    VkDeviceAddress                       capture_address{ 0 };
    VkDeviceAddress                       replay_address{ 0 };

    // This is only used when loading the initial state for trimmed files.
    VkMemoryPropertyFlags memory_property_flags{ 0 };

    VkBufferUsageFlags usage{ 0 };
    VkDeviceSize       size{ 0 };
    uint32_t           queue_family_index{ 0 };
};

struct VulkanBufferViewInfo : public VulkanObjectInfo<VkBufferView>
{
    format::HandleId buffer_id{ format::kNullHandleId };
    VkDeviceSize     offset{ 0 };
    VkDeviceSize     range{ 0 };
};

struct VulkanImageInfo : public VulkanObjectInfo<VkImage>
{
    std::unordered_map<uint32_t, size_t> array_counts;

    bool is_swapchain_image{ false };

    // The following values are only used for memory portability.
    VulkanResourceAllocator::ResourceData allocator_data{ 0 };

    VkDeviceMemory                      memory{ VK_NULL_HANDLE };
    VulkanResourceAllocator::MemoryData memory_allocator_data{ 0 };

    // This is only used when loading the initial state for trimmed files.
    VkMemoryPropertyFlags memory_property_flags{ 0 };

    VkImageUsageFlags     usage{ 0 };
    VkImageType           type{};
    VkFormat              format{};
    bool                  external_format{ false };
    bool                  external_memory_android{ false };
    VkExtent3D            extent{ 0, 0, 0 };
    VkImageTiling         tiling{};
    VkSampleCountFlagBits sample_count{};
    VkImageLayout         initial_layout{};
    uint32_t              layer_count{ 0 };
    uint32_t              level_count{ 0 };
    uint32_t              queue_family_index{ 0 };

    VkImageLayout current_layout{ VK_IMAGE_LAYOUT_UNDEFINED };
    VkImageLayout intermediate_layout{ VK_IMAGE_LAYOUT_UNDEFINED };

    VkDeviceSize size{ 0 };
};

struct VulkanPipelineCacheData
{
    std::vector<uint8_t> capture_cache_data;
    std::vector<uint8_t> replay_cache_data;
};

struct VulkanPipelineCacheInfo : public VulkanObjectInfo<VkPipelineCache>
{
    std::unordered_map<uint32_t, size_t> array_counts;

    // hash id of capture time pipeline cache data to capture and replay time pipeline cache data map;
    std::unordered_map<uint32_t, std::vector<VulkanPipelineCacheData>> pipeline_cache_data;

    // cache was created using VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT flag.
    bool requires_external_synchronization = false;
};

struct VulkanShaderModuleInfo : public VulkanObjectInfo<VkShaderModule>
{
    // keep track of existing usage of buffer-references
    std::vector<gfxrecon::util::SpirVParsingUtil::BufferReferenceInfo> buffer_reference_infos;
};

struct DescriptorBindingLayout
{
    uint32_t           count;
    VkDescriptorType   type;
    VkShaderStageFlags stage_flags;
};

using DescriptorBindingLayoutMap = std::unordered_map<uint32_t, DescriptorBindingLayout>;

struct VulkanDescriptorSetLayoutInfo : public VulkanObjectInfo<VkDescriptorSetLayout>
{
    // One per descriptor binding
    DescriptorBindingLayoutMap bindings_layout;
};

struct VulkanPipelineLayoutInfo : public VulkanObjectInfo<VkPipelineLayout>
{
    // One per descriptor set
    std::vector<DescriptorBindingLayoutMap> desc_set_layouts;
};

struct VulkanPipelineInfo : public VulkanObjectInfoAsync<VkPipeline>
{
    std::unordered_map<uint32_t, size_t> array_counts;

    // keep track of existing usage of buffer-references
    std::vector<gfxrecon::util::SpirVParsingUtil::BufferReferenceInfo> buffer_reference_infos;

    // map capture- to replay-time shader-group-handles
    std::unordered_map<graphics::shader_group_handle_t, graphics::shader_group_handle_t> shader_group_handle_map;

    // The following information is populated and used only when the dump resources feature is in use

    struct InputBindingDescription
    {
        uint32_t          stride;
        VkVertexInputRate inputRate;
    };

    struct InputAttributeDescription
    {
        uint32_t binding;
        VkFormat format;
        uint32_t offset;
    };

    // Aggregated shader stages flags
    VkShaderStageFlags shader_stages{ 0 };

    // One entry per binding
    using VertexInputBindingMap = std::unordered_map<uint32_t, InputBindingDescription>;
    VertexInputBindingMap vertex_input_binding_map;

    // One entry per location
    using VertexInputAttributeMap = std::unordered_map<uint32_t, InputAttributeDescription>;
    VertexInputAttributeMap vertex_input_attribute_map;

    // Is VK_DYNAMIC_STATE_VERTEX_INPUT_EXT enabled
    bool dynamic_vertex_input{ false };

    // Is VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT enabled
    bool dynamic_vertex_binding_stride{ false };

    // Grahpics pipeline library info
    VkGraphicsPipelineLibraryFlagsEXT gpl_flags{ 0 };

    // Pipeline layout info
    std::vector<DescriptorBindingLayoutMap> desc_set_layouts;
};

struct VulkanDescriptorPoolInfo : public VulkanPoolInfo<VkDescriptorPool>
{
    VkDescriptorPoolCreateFlags       flags{};
    uint32_t                          max_sets{ 0 };
    uint32_t                          max_inline_uniform_block_bindings{ 0 }; // For VK_EXT_inline_uniform_block.
    std::vector<VkDescriptorPoolSize> pool_sizes;
    std::vector<VkDescriptorPool>     retired_pools;
};

struct VulkanDescriptorUpdateTemplateInfo : public VulkanObjectInfo<VkDescriptorUpdateTemplate>
{
    std::vector<VkDescriptorType>                descriptor_image_types;
    std::vector<VkDescriptorUpdateTemplateEntry> entries;
};

struct VulkanDisplayKHRInfo : public VulkanObjectInfo<VkDisplayKHR>
{
    std::unordered_map<uint32_t, size_t> array_counts;
};

struct VulkanSurfaceKHRInfo : public VulkanObjectInfo<VkSurfaceKHR>
{
    Window*                              window{ nullptr };
    std::unordered_map<uint32_t, size_t> array_counts;
    bool                                 surface_creation_skipped{ false };

    std::unordered_map<VkPhysicalDevice, VkSurfaceCapabilitiesKHR> surface_capabilities;
};

struct VulkanSwapchainKHRInfo : public VulkanObjectInfo<VkSwapchainKHR>
{
    VkSurfaceKHR         surface{ VK_NULL_HANDLE };
    format::HandleId     surface_id{ format::kNullHandleId };
    VulkanDeviceInfo*    device_info{ nullptr };
    uint32_t             width{ 0 };
    uint32_t             height{ 0 };
    VkFormat             format{ VK_FORMAT_UNDEFINED };
    std::vector<VkImage> images; // This image could be virtual or real according to if it uses VirtualSwapchain.
    std::unordered_map<uint32_t, size_t> array_counts;

    // The acquired_indices value and the remapping performed with it.
    struct AcquiredData
    {
        uint32_t index = { 0 };
        bool     acquired{ false };
    };
    std::vector<AcquiredData> acquired_indices;

    // The following values are only used when loading the initial state for trimmed files.
    std::vector<uint32_t> queue_family_indices{ 0 };

    // For virtual swapchain, we want the compression on virtual images to be the same as on the true swapchain
    std::vector<VkImageCompressionFixedRateFlagsEXT> compression_fixed_rate_flags;
    std::shared_ptr<VkImageCompressionControlEXT>    compression_control;

    // When replay is restricted to a specific surface, a dummy swapchain is created for the omitted surfaces, requiring
    // backing images.
    uint32_t                     replay_image_count{ 0 };
    std::vector<VulkanImageInfo> image_infos;
    VkSwapchainCreateFlagsKHR    image_flags{ 0 };
    VkFormat                     image_format{ VK_FORMAT_UNDEFINED };
    uint32_t                     image_array_layers{ 0 };
    VkImageUsageFlags            image_usage{ 0 };
    VkSharingMode                image_sharing_mode{ VK_SHARING_MODE_EXCLUSIVE };
};

struct VulkanValidationCacheEXTInfo : public VulkanObjectInfo<VkValidationCacheEXT>
{
    std::unordered_map<uint32_t, size_t> array_counts;
};

struct VulkanImageViewInfo : public VulkanObjectInfo<VkImageView>
{
    format::HandleId image_id{ format::kNullHandleId };
};

struct VulkanFramebufferInfo : public VulkanObjectInfo<VkFramebuffer>
{
    VkFramebufferCreateFlags             framebuffer_flags{ 0 };
    std::unordered_map<uint32_t, size_t> array_counts;
    std::vector<format::HandleId>        attachment_image_view_ids;
};

struct VulkanDeferredOperationKHRInfo : public VulkanObjectInfo<VkDeferredOperationKHR>
{
    bool pending_state{ false };

    // Record CreateRayTracingPipelinesKHR parameters for safety.
    std::vector<VkRayTracingPipelineCreateInfoKHR>                 record_modified_create_infos;
    std::vector<std::vector<VkRayTracingShaderGroupCreateInfoKHR>> record_modified_pgroups;
    std::vector<VkPipeline>                                        replayPipelines;
    std::vector<format::HandleId>                                  capturePipelines;
};

struct VulkanVideoSessionKHRInfo : VulkanObjectInfo<VkVideoSessionKHR>
{
    std::unordered_map<uint32_t, size_t> array_counts;

    // The following values are only used for memory portability.
    std::vector<VulkanResourceAllocator::ResourceData> allocator_datas;

    // This is only used when loading the initial state for trimmed files.
    std::vector<VkMemoryPropertyFlags> memory_property_flags;

    uint32_t queue_family_index{ 0 };
};

struct VulkanShaderEXTInfo : VulkanObjectInfoAsync<VkShaderEXT>
{
    std::unordered_map<uint32_t, size_t> array_counts;

    // keep track of existing usage of buffer-references
    std::vector<gfxrecon::util::SpirVParsingUtil::BufferReferenceInfo> buffer_reference_infos;
};

struct VulkanCommandBufferInfo : public VulkanPoolObjectInfo<VkCommandBuffer>
{
    bool                                                      is_frame_boundary{ false };
    std::vector<format::HandleId>                             frame_buffer_ids;
    std::unordered_map<format::HandleId, VkImageLayout>       image_layout_barriers;
    std::unordered_map<VkPipelineBindPoint, format::HandleId> bound_pipelines;
    std::vector<uint8_t>                                      push_constant_data;
    VkShaderStageFlags                                        push_constant_stage_flags     = 0;
    VkPipelineLayout                                          push_constant_pipeline_layout = VK_NULL_HANDLE;

    // collect buffer-device-addresses of locations to replace before submit
    std::unordered_set<VkDeviceAddress> addresses_to_replace;
    bool                                inside_renderpass = false;
};

struct VulkanRenderPassInfo : public VulkanObjectInfo<VkRenderPass>
{
    std::vector<VkImageLayout>           attachment_description_final_layouts;
    std::vector<VkAttachmentDescription> attachment_descs;

    std::vector<uint8_t> create_info;
    enum FuncVersion
    {
        kCreateRenderPass,
        kCreateRenderPass2,
        kCreateRenderPass2KHR
    };
    FuncVersion func_version;

    std::vector<format::HandleId> begin_renderpass_override_attachments;
};

struct VulkanDescriptorTypeImageInfo
{
    const VulkanImageViewInfo* image_view_info;
    VkImageLayout              image_layout;
};

struct VulkanDescriptorTypeBufferInfo
{
    const VulkanBufferInfo* buffer_info;
    VkDeviceSize            offset;
    VkDeviceSize            range;
};

struct VulkanDescriptorSetBindingInfo
{
    VkDescriptorType   desc_type{ VK_DESCRIPTOR_TYPE_MAX_ENUM };
    VkShaderStageFlags stage_flags{ 0 };

    // Use a map to represent array as many entries can be left unpopulated.
    // Use a sorted map so that array indices are printed in order in the json output
    std::map<uint32_t, VulkanDescriptorTypeImageInfo>  image_info;
    std::map<uint32_t, VulkanDescriptorTypeBufferInfo> buffer_info;
    std::map<uint32_t, const VulkanBufferViewInfo*>    texel_buffer_view_info;
    std::vector<uint8_t>                               inline_uniform_block;
};

struct VulkanDescriptorSetInfo : public VulkanPoolObjectInfo<VkDescriptorSet>
{
    // One entry per binding
    using VulkanDescriptorBindingsInfo = std::unordered_map<uint32_t, VulkanDescriptorSetBindingInfo>;
    VulkanDescriptorBindingsInfo descriptors;
};

struct VulkanAccelerationStructureKHRInfo : public VulkanObjectInfo<VkAccelerationStructureKHR>
{
    VkDeviceAddress capture_address = 0;
    VkDeviceAddress replay_address  = 0;

    VkAccelerationStructureTypeKHR type = VK_ACCELERATION_STRUCTURE_TYPE_MAX_ENUM_KHR;

    //! associated buffer
    VkBuffer buffer = VK_NULL_HANDLE;
};

//
// Handle alias types for extension handle types that have been promoted to core types.
//

typedef VulkanSamplerYcbcrConversionInfo   VulkanSamplerYcbcrConversionKHRInfo;
typedef VulkanDescriptorUpdateTemplateInfo VulkanDescriptorUpdateTemplateKHRInfo;
typedef VulkanPrivateDataSlotInfo          VulkanPrivateDataSlotEXTInfo;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OBJECT_INFO_H
