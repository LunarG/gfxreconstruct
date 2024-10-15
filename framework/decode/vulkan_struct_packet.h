#include "generated/generated_vulkan_cpp_consumer.h"

#include "decode/vulkan_cpp_consumer_base.h"
#include "decode/vulkan_cpp_structs.h"
#include "generated/generated_vulkan_cpp_structs.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"
#include "format/packet_call_id.h"
#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <iostream>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Packet_DispatchStateBeginMarker
{
    format::PacketCallId packet_id;
    uint64_t             frame_number;
};

struct Packet_DispatchStateEndMarker
{
    format::PacketCallId packet_id;
    uint64_t             frame_number;
};

struct Packet_DispatchFrameEndMarker
{
    format::PacketCallId packet_id;
    uint64_t             frame_number;
};

struct Packet_DispatchDisplayMessageCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    std::string          message;
};

struct Packet_DispatchFillMemoryCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    uint64_t             memory_id;
    uint64_t             offset;
    uint64_t             size;
    uint8_t*             data;
};

struct Packet_DispatchFixDeviceAddresCommand
{
    format::PacketCallId                  packet_id;
    format::FixDeviceAddressCommandHeader header;
    format::AddressLocationInfo*          infos;
};

struct Packet_DispatchExeFileInfo
{
    format::PacketCallId     packet_id;
    format::ThreadId         thread_id;
    format::ExeFileInfoBlock info;
};

struct Packet_DispatchFillMemoryResourceValueCommand
{
    format::PacketCallId                         packet_id;
    format::FillMemoryResourceValueCommandHeader command_header;
    uint8_t*                                     data;
};

struct Packet_DispatchResizeWindowCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    format::HandleId     surface_id;
    uint32_t             width;
    uint32_t             height;
};

struct Packet_DispatchResizeWindowCommand2
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    format::HandleId     surface_id;
    uint32_t             width;
    uint32_t             height;
    uint32_t             pre_transform;
};

struct Packet_DispatchCreateHardwareBufferCommand
{
    format::PacketCallId                         packet_id;
    format::ThreadId                             thread_id;
    format::HandleId                             memory_id;
    uint64_t                                     buffer_id;
    uint32_t                                     format;
    uint32_t                                     width;
    uint32_t                                     height;
    uint32_t                                     stride;
    uint64_t                                     usage;
    uint32_t                                     layers;
    std::vector<format::HardwareBufferPlaneInfo> plane_info;
};

struct Packet_DispatchDestroyHardwareBufferCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    uint64_t             buffer_id;
};

struct Packet_DispatchCreateHeapAllocationCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    uint64_t             allocation_id;
    uint64_t             allocation_size;
};

struct Packet_DispatchSetDevicePropertiesCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    format::HandleId     physical_device_id;
    uint32_t             api_version;
    uint32_t             driver_version;
    uint32_t             vendor_id;
    uint32_t             device_id;
    uint32_t             device_type;
    uint8_t              pipeline_cache_uuid[format::kUuidSize];
    std::string          device_name;
};

struct Packet_DispatchSetDeviceMemoryPropertiesCommand
{
    format::PacketCallId                  packet_id;
    format::ThreadId                      thread_id;
    format::HandleId                      physical_device_id;
    std::vector<format::DeviceMemoryType> memory_types;
    std::vector<format::DeviceMemoryHeap> memory_heaps;
};

struct Packet_DispatchSetOpaqueAddressCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    format::HandleId     device_id;
    format::HandleId     object_id;
    uint64_t             address;
};

struct Packet_DispatchSetRayTracingShaderGroupHandlesCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    format::HandleId     device_id;
    format::HandleId     pipeline_id;
    size_t               data_size;
    uint8_t*             data;
};

struct Packet_DispatchSetSwapchainImageStateCommand
{
    format::PacketCallId                         packet_id;
    format::ThreadId                             thread_id;
    format::HandleId                             device_id;
    format::HandleId                             swapchain_id;
    uint32_t                                     last_presented_image;
    std::vector<format::SwapchainImageStateInfo> image_state;
};

struct Packet_DispatchBeginResourceInitCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    format::HandleId     device_id;
    uint64_t             max_resource_size;
    uint64_t             max_copy_size;
};

struct Packet_DispatchEndResourceInitCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    format::HandleId     device_id;
};

struct Packet_DispatchInitBufferCommand
{
    format::PacketCallId packet_id;
    format::ThreadId     thread_id;
    format::HandleId     device_id;
    format::HandleId     buffer_id;
    size_t               data_size;
    uint8_t*             data;
};

struct Packet_DispatchInitImageCommand
{
    format::PacketCallId  packet_id;
    format::ThreadId      thread_id;
    format::HandleId      device_id;
    format::HandleId      image_id;
    size_t                data_size;
    uint32_t              aspect;
    uint32_t              layout;
    std::vector<uint64_t> level_sizes;
    uint8_t*              data;
};

struct Packet_DispatchInitSubresourceCommand
{
    format::PacketCallId                 packet_id;
    format::InitSubresourceCommandHeader command_header;
    uint8_t*                             data;
};

// Function Call
struct Packet_vkUpdateDescriptorSetWithTemplate
{
    format::PacketCallId            packet_id;
    ApiCallInfo                     call_info;
    format::HandleId                device;
    format::HandleId                descriptorSet;
    format::HandleId                descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;
};

struct Packet_vkCmdPushDescriptorSetWithTemplateKHR
{
    format::PacketCallId            packet_id;
    ApiCallInfo                     call_info;
    format::HandleId                commandBuffer;
    format::HandleId                descriptorUpdateTemplate;
    format::HandleId                layout;
    uint32_t                        set;
    DescriptorUpdateTemplateDecoder pData;
};

struct Packet_vkCmdPushDescriptorSetWithTemplate2KHR
{
    format::PacketCallId                                                 packet_id;
    ApiCallInfo                                                          call_info;
    format::HandleId                                                     commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfoKHR> pPushDescriptorSetWithTemplateInfo;
};

struct Packet_vkUpdateDescriptorSetWithTemplateKHR
{
    format::PacketCallId            packet_id;
    ApiCallInfo                     call_info;
    format::HandleId                device;
    format::HandleId                descriptorSet;
    format::HandleId                descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;
};

struct Packet_vkCreateRayTracingPipelinesKHR
{
    format::PacketCallId                                            packet_id;
    ApiCallInfo                                                     call_info;
    VkResult                                                        returnValue;
    format::HandleId                                                device;
    format::HandleId                                                deferredOperation;
    format::HandleId                                                pipelineCache;
    uint32_t                                                        createInfoCount;
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks>             pAllocator;
    HandlePointerDecoder<VkPipeline>                                pPipelines;
};

struct Packet_DispatchSetTlasToBlasDependencyCommand
{
    format::PacketCallId          packet_id;
    format::HandleId              tlas;
    std::vector<format::HandleId> blases;
};

struct Packet_DispatchVulkanAccelerationStructuresBuildMetaCommand
{
    format::PacketCallId                                                      packet_id;
    format::HandleId                                                          device;
    uint32_t                                                                  info_count;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>   ppRangeInfos;
    std::vector<std::vector<VkAccelerationStructureInstanceKHR>>              instance_buffers_data;
};

struct Packet_DispatchVulkanAccelerationStructuresCopyMetaCommand
{
    format::PacketCallId                                             packet_id;
    format::HandleId                                                 device;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR> copy_infos;
};

struct Packet_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand
{
    format::PacketCallId packet_id;
    format::HandleId     device_id;
    VkQueryType          copy_query_typeinfos;
    format::HandleId     acceleration_structure_id;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
