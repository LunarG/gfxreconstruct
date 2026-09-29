///////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2019 Advanced Micro Devices, Inc.All rights reserved
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
/// \author AMD Developer Tools Team
/// \description gfxrecon_decode test main entry point
///////////////////////////////////////////////////////////////////////////////

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "decode/referenced_resource_table.h"
#include "decode/screenshot_controller.h"
#include "decode/vulkan_screenshot_handler.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "decode/vulkan_object_info.h"
#include "decode/common_object_info_table.h"
#include "format/format.h"
#include "format/format_util.h"
#include "graphics/vulkan_submit_info_util.h"
#include "graphics/vulkan_struct_get_pnext.h"

#include "decode/block_parser.h"
#include "decode/decode_allocator.h"
#include "decode/vulkan_api_call_reader.h"
#include "decode/vulkan_native_call_consumer_base.h"
#include "generated/generated_vulkan_consumer.h"
#include "generated/generated_vulkan_native_call_consumer.h"

#include <algorithm>
#include <cstring>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

namespace
{
class ApiCallReaderTestConsumer : public gfxrecon::decode::VulkanConsumer
{
  public:
    void Process_vkCreateInstance(const gfxrecon::decode::ApiCallInfo& call_info,
                                  gfxrecon::decode::args::CreateInstance&) override
    {
        ++create_instance_count;
        last_call_index = call_info.index;
        last_thread_id  = call_info.thread_id;
    }

    void Process_ExeFileInfo(const gfxrecon::util::filepath::FileInfo&) override { ++metadata_count; }

    void ProcessSetEnvironmentVariablesCommand(const gfxrecon::format::SetEnvironmentVariablesCommand&,
                                               const char*) override
    {
        ++metadata_count;
    }

    void ProcessStateBeginMarker(uint64_t) override { ++marker_count; }

    void ProcessStateEndMarker(uint64_t) override { ++marker_count; }

    void ProcessFrameEndMarker(uint64_t) override { ++marker_count; }

    uint64_t                   create_instance_count{ 0 };
    uint64_t                   metadata_count{ 0 };
    uint64_t                   marker_count{ 0 };
    uint64_t                   last_call_index{ 0 };
    gfxrecon::format::ThreadId last_thread_id{ 0 };
};

struct NativeCallbackTestState
{
    VkResult                                         create_instance_result{ VK_ERROR_UNKNOWN };
    uint64_t                                         pre_call_count{ 0 };
    uint64_t                                         post_call_count{ 0 };
    uint64_t                                         missing_callback_count{ 0 };
    uint64_t                                         create_instance_count{ 0 };
    uint64_t                                         draw_count{ 0 };
    uint64_t                                         create_ray_tracing_pipelines_count{ 0 };
    uint64_t                                         memory_update_count{ 0 };
    uint64_t                                         device_memory_properties_count{ 0 };
    uint64_t                                         unhandled_meta_command_count{ 0 };
    uint64_t                                         last_unhandled_meta_command_block{ 0 };
    uint32_t                                         last_unhandled_metadata_id{ 0 };
    VkDeviceSize                                     last_memory_update_offset{ 0 };
    bool                                             valid_create_info{ false };
    bool                                             valid_instance{ false };
    bool                                             valid_draw{ false };
    bool                                             valid_memory_updates{ true };
    bool                                             valid_device_memory_properties{ true };
    std::unordered_map<VkDeviceMemory, VkDeviceSize> mapped_memory_offsets;
};

NativeCallbackTestState* native_callback_test_state = nullptr;

VKAPI_ATTR VkResult VKAPI_CALL TestCreateInstance(const VkInstanceCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks*,
                                                  VkInstance* pInstance)
{
    NativeCallbackTestState& state = *native_callback_test_state;
    ++state.create_instance_count;
    state.valid_create_info =
        (pCreateInfo != nullptr) && (pCreateInfo->sType == VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO) &&
        (pCreateInfo->pApplicationInfo != nullptr) && (pCreateInfo->pApplicationInfo->pApplicationName != nullptr);
    state.valid_instance = (pInstance != nullptr) && (*pInstance != VK_NULL_HANDLE);
    return state.create_instance_result;
}

VKAPI_ATTR void VKAPI_CALL
TestCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t, uint32_t)
{
    NativeCallbackTestState& state = *native_callback_test_state;
    ++state.draw_count;
    state.valid_draw =
        state.valid_draw || ((commandBuffer != VK_NULL_HANDLE) && (vertexCount > 0) && (instanceCount > 0));
}

VKAPI_ATTR VkResult VKAPI_CALL TestCreateRayTracingPipelinesKHR(VkDevice,
                                                                VkDeferredOperationKHR deferredOperation,
                                                                VkPipelineCache,
                                                                uint32_t createInfoCount,
                                                                const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                                                const VkAllocationCallbacks*,
                                                                VkPipeline* pPipelines)
{
    auto& state = *native_callback_test_state;
    ++state.create_ray_tracing_pipelines_count;
    state.valid_create_info = (deferredOperation == VK_NULL_HANDLE) && (createInfoCount == 0) &&
                              (pCreateInfos == nullptr) && (pPipelines == nullptr);
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL
TestMapMemory(VkDevice, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize, VkMemoryMapFlags, void**)
{
    native_callback_test_state->mapped_memory_offsets[memory] = offset;
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL TestUnmapMemory(VkDevice, VkDeviceMemory memory)
{
    native_callback_test_state->mapped_memory_offsets.erase(memory);
}

void TestPreCall(void* user_data, const gfxrecon::decode::VulkanNativeCallContext& context)
{
    auto& state = *static_cast<NativeCallbackTestState*>(user_data);
    ++state.pre_call_count;
    if (context.call_id == gfxrecon::format::ApiCallId::ApiCall_vkCreateInstance)
    {
        if ((context.return_value != nullptr) && (context.return_value_size == sizeof(state.create_instance_result)))
        {
            std::memcpy(&state.create_instance_result, context.return_value, sizeof(state.create_instance_result));
        }
    }
}

void TestPostCall(void* user_data, const gfxrecon::decode::VulkanNativeCallContext&)
{
    ++static_cast<NativeCallbackTestState*>(user_data)->post_call_count;
}

void TestMissingCallback(void* user_data, const gfxrecon::decode::VulkanNativeCallContext&)
{
    ++static_cast<NativeCallbackTestState*>(user_data)->missing_callback_count;
}

void TestMemoryUpdate(void* user_data, const gfxrecon::decode::VulkanMemoryUpdate& update)
{
    auto& state = *static_cast<NativeCallbackTestState*>(user_data);
    ++state.memory_update_count;
    state.last_memory_update_offset = update.memory_offset;

    const auto mapping         = state.mapped_memory_offsets.find(update.memory);
    state.valid_memory_updates = state.valid_memory_updates && (mapping != state.mapped_memory_offsets.end()) &&
                                 (update.memory_offset >= mapping->second) && (update.data_size > 0) &&
                                 (update.data != nullptr) && (update.block_index > 0) && (update.thread_id > 0);
}

void TestDeviceMemoryProperties(void* user_data, const gfxrecon::decode::VulkanDeviceMemoryProperties& properties)
{
    auto& state = *static_cast<NativeCallbackTestState*>(user_data);
    ++state.device_memory_properties_count;
    state.valid_device_memory_properties =
        state.valid_device_memory_properties && (properties.block_index > 0) && (properties.thread_id > 0) &&
        (properties.physical_device != VK_NULL_HANDLE) && (properties.memory_properties.memoryTypeCount > 0) &&
        (properties.memory_properties.memoryHeapCount > 0);
}

void TestUnhandledMetaCommand(void* user_data, const gfxrecon::decode::VulkanUnhandledMetaCommand& command)
{
    auto& state = *static_cast<NativeCallbackTestState*>(user_data);
    ++state.unhandled_meta_command_count;
    state.last_unhandled_meta_command_block = command.block_index;
    state.last_unhandled_metadata_id        = command.metadata_id;
}

void TestOpaqueAddress(void* user_data, const gfxrecon::decode::VulkanOpaqueAddress& opaque_address)
{
    static_cast<std::vector<gfxrecon::decode::VulkanOpaqueAddress>*>(user_data)->push_back(opaque_address);
}

void TestAccelerationStructuresBuild(void* user_data, const gfxrecon::decode::VulkanAccelerationStructuresBuild& build)
{
    auto& valid = *static_cast<bool*>(user_data);
    valid       = (build.block_index == 17) && (build.device != VK_NULL_HANDLE) && (build.info_count == 0) &&
            (build.build_infos == nullptr) && (build.range_infos == nullptr) && (build.instance_buffer_count == 0);
}

struct AccelerationStructureRelatedTestState
{
    bool copy{ false };
    bool write{ false };
};

void TestAccelerationStructuresCopy(void* user_data, const gfxrecon::decode::VulkanAccelerationStructuresCopy& copy)
{
    auto& state = *static_cast<AccelerationStructureRelatedTestState*>(user_data);
    state.copy  = (copy.block_index == 18) && (copy.device != VK_NULL_HANDLE) && (copy.info_count == 0) &&
                 (copy.infos == nullptr);
}

void TestAccelerationStructureWriteProperties(void* user_data,
                                              const gfxrecon::decode::VulkanAccelerationStructureWriteProperties& write)
{
    auto& state = *static_cast<AccelerationStructureRelatedTestState*>(user_data);
    state.write = (write.block_index == 19) && (write.device != VK_NULL_HANDLE) &&
                  (write.query_type == VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR) &&
                  (write.acceleration_structure != VK_NULL_HANDLE);
}

struct ResourceInitializationTestState
{
    uint32_t callback_index{ 0 };
    bool     valid{ true };
};

void TestResourceInitializationBegin(void*                                                      user_data,
                                     const gfxrecon::decode::VulkanResourceInitializationBegin& initialization)
{
    auto& state = *static_cast<ResourceInitializationTestState*>(user_data);
    state.valid = state.valid && (state.callback_index++ == 0) && (initialization.block_index == 1) &&
                  (initialization.thread_id == 2) && (initialization.device != VK_NULL_HANDLE) &&
                  (initialization.total_copy_size == 12) && (initialization.max_copy_size == 8);
}

void TestBufferInitialization(void* user_data, const gfxrecon::decode::VulkanBufferInitialization& initialization)
{
    const uint8_t expected[] = { 1, 2, 3, 4 };
    auto&         state      = *static_cast<ResourceInitializationTestState*>(user_data);
    state.valid              = state.valid && (state.callback_index++ == 1) && (initialization.block_index == 3) &&
                  (initialization.thread_id == 2) && (initialization.device != VK_NULL_HANDLE) &&
                  (initialization.buffer != VK_NULL_HANDLE) && (initialization.data_size == sizeof(expected)) &&
                  (std::memcmp(initialization.data, expected, sizeof(expected)) == 0);
}

void TestImageInitialization(void* user_data, const gfxrecon::decode::VulkanImageInitialization& initialization)
{
    const uint8_t expected[] = { 5, 6, 7 };
    auto&         state      = *static_cast<ResourceInitializationTestState*>(user_data);
    state.valid =
        state.valid && (state.callback_index++ == 2) && (initialization.block_index == 5) &&
        (initialization.thread_id == 2) && (initialization.device != VK_NULL_HANDLE) &&
        (initialization.image != VK_NULL_HANDLE) && (initialization.aspect_mask == VK_IMAGE_ASPECT_COLOR_BIT) &&
        (initialization.layout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL) && (initialization.level_count == 2) &&
        (initialization.level_sizes != nullptr) && (initialization.level_sizes[0] == 2) &&
        (initialization.level_sizes[1] == 1) && (initialization.data_size == sizeof(expected)) &&
        (std::memcmp(initialization.data, expected, sizeof(expected)) == 0);
}

void TestResourceInitializationEnd(void*                                                    user_data,
                                   const gfxrecon::decode::VulkanResourceInitializationEnd& initialization)
{
    auto& state = *static_cast<ResourceInitializationTestState*>(user_data);
    state.valid = state.valid && (state.callback_index++ == 3) && (initialization.block_index == 7) &&
                  (initialization.thread_id == 2) && (initialization.device != VK_NULL_HANDLE);
}

class TestNativeCallConsumer : public gfxrecon::decode::VulkanNativeCallConsumerBase
{
  public:
    explicit TestNativeCallConsumer(gfxrecon::decode::VulkanNativeCallCallbacks& callbacks) :
        VulkanNativeCallConsumerBase(callbacks)
    {}

    void Map(VkDeviceMemory memory, VkDeviceSize offset) { TrackMappedMemory(VK_SUCCESS, memory, offset); }

    void AddDescriptorUpdateTemplate(gfxrecon::format::HandleId                          id,
                                     const std::vector<VkDescriptorUpdateTemplateEntry>& entries)
    {
        gfxrecon::decode::VulkanDescriptorUpdateTemplateInfo info;
        info.capture_id = id;
        info.handle     = gfxrecon::format::FromHandleId<VkDescriptorUpdateTemplate>(id);
        info.entries    = entries;
        object_info_table_.AddVkDescriptorUpdateTemplateInfo(std::move(info));
    }

    bool MaterializeDescriptorUpdateTemplate(gfxrecon::format::HandleId                         id,
                                             gfxrecon::decode::DescriptorUpdateTemplateDecoder* decoder,
                                             std::vector<uint8_t>*                              data)
    {
        return MaterializeDescriptorUpdateTemplateData(id, decoder, data);
    }

    std::vector<gfxrecon::decode::VulkanAccelerationStructureInstanceBuffer>
    DescribeInstanceBuffers(const VkAccelerationStructureBuildGeometryInfoKHR*                  build_infos,
                            uint32_t                                                            info_count,
                            const std::vector<std::vector<VkAccelerationStructureInstanceKHR>>& instance_buffers)
    {
        return DescribeAccelerationStructureInstanceBuffers(build_infos, info_count, instance_buffers);
    }

    void ResolveOpaqueObject(gfxrecon::format::HandleId id, VkObjectType type, uint64_t handle)
    {
        switch (type)
        {
            case VK_OBJECT_TYPE_BUFFER:
                ResolvePendingOpaqueAddresses(id, type, gfxrecon::format::FromHandleId<VkBuffer>(handle));
                break;
            case VK_OBJECT_TYPE_DEVICE_MEMORY:
                ResolvePendingOpaqueAddresses(id, type, gfxrecon::format::FromHandleId<VkDeviceMemory>(handle));
                break;
            case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
                ResolvePendingOpaqueAddresses(
                    id, type, gfxrecon::format::FromHandleId<VkAccelerationStructureKHR>(handle));
                break;
            case VK_OBJECT_TYPE_MICROMAP_EXT:
                ResolvePendingOpaqueAddresses(id, type, gfxrecon::format::FromHandleId<VkMicromapEXT>(handle));
                break;
            default:
                FAIL("unsupported opaque-address test object type");
        }
    }
};

template <typename T>
void AppendEncodedValue(std::vector<uint8_t>* data, const T& value)
{
    const auto* bytes = reinterpret_cast<const uint8_t*>(&value);
    data->insert(data->end(), bytes, bytes + sizeof(value));
}

struct DecodeAllocatorScope
{
    DecodeAllocatorScope() { gfxrecon::decode::DecodeAllocator::Begin(); }
    ~DecodeAllocatorScope() { gfxrecon::decode::DecodeAllocator::End(); }
};
} // namespace

TEST_CASE("Vulkan API call reader dispatches API calls only", "[vulkan_api_call_reader]")
{
    ApiCallReaderTestConsumer             consumer;
    gfxrecon::decode::VulkanApiCallReader reader(consumer);
    const std::string                     capture_path = std::string(GFXRECON_TEST_DATA_DIR) + "/triangle.gfxr";

    REQUIRE(reader.Initialize(capture_path));
    REQUIRE(reader.ProcessAllFrames());
    CHECK(reader.EntireFileWasProcessed());
    CHECK(reader.GetErrorState() >= gfxrecon::decode::kErrorNone);
    CHECK(consumer.create_instance_count == 1);
    CHECK(consumer.last_call_index > 0);
    CHECK(consumer.last_thread_id > 0);
    CHECK(consumer.metadata_count == 0);
    CHECK(consumer.marker_count == 0);
    CHECK_FALSE(reader.SetMemoryUpdateCallback(TestMemoryUpdate, nullptr));
    CHECK_FALSE(reader.SetDeviceMemoryPropertiesCallback(TestDeviceMemoryProperties, nullptr));
    CHECK_FALSE(reader.SetResourceInitializationBeginCallback(TestResourceInitializationBegin, nullptr));
    CHECK_FALSE(reader.SetBufferInitializationCallback(TestBufferInitialization, nullptr));
    CHECK_FALSE(reader.SetImageInitializationCallback(TestImageInitialization, nullptr));
    CHECK_FALSE(reader.SetResourceInitializationEndCallback(TestResourceInitializationEnd, nullptr));
    CHECK_FALSE(reader.SetDeviceAddressFixupCallback(nullptr, nullptr));
    CHECK_FALSE(reader.SetShaderGroupHandleFixupCallback(nullptr, nullptr));
    CHECK_FALSE(reader.SetUnhandledMetaCommandCallback(TestUnhandledMetaCommand, nullptr));
    CHECK_FALSE(reader.SetOpaqueAddressCallback(TestOpaqueAddress, nullptr));
    CHECK_FALSE(reader.SetAccelerationStructuresBuildCallback(TestAccelerationStructuresBuild, nullptr));
    CHECK_FALSE(reader.SetAccelerationStructuresCopyCallback(TestAccelerationStructuresCopy, nullptr));
    CHECK_FALSE(
        reader.SetAccelerationStructureWritePropertiesCallback(TestAccelerationStructureWriteProperties, nullptr));
}

TEST_CASE("Vulkan native memory updates use allocation-relative offsets", "[vulkan_api_call_reader]")
{
    NativeCallbackTestState                     state;
    gfxrecon::decode::VulkanNativeCallCallbacks callbacks;
    TestNativeCallConsumer                      consumer(callbacks);
    constexpr gfxrecon::format::HandleId        memory_id      = 42;
    constexpr VkDeviceSize                      mapping_offset = 100;
    const VkDeviceMemory                        memory = gfxrecon::format::FromHandleId<VkDeviceMemory>(memory_id);
    const uint8_t                               data[] = { 1, 2, 3, 4 };

    callbacks.SetMemoryUpdateCallback(TestMemoryUpdate, &state);
    state.mapped_memory_offsets[memory] = mapping_offset;
    consumer.Map(memory, mapping_offset);
    consumer.ProcessMemoryUpdate(7, 9, memory_id, 11, sizeof(data), data);

    CHECK(state.memory_update_count == 1);
    CHECK(state.valid_memory_updates);
    CHECK(state.last_memory_update_offset == mapping_offset + 11);
}

TEST_CASE("Vulkan native descriptor template data uses the original layout", "[vulkan_api_call_reader]")
{
    DecodeAllocatorScope                        allocator_scope;
    gfxrecon::decode::VulkanNativeCallCallbacks callbacks;
    TestNativeCallConsumer                      consumer(callbacks);
    constexpr gfxrecon::format::HandleId        template_id = 41;
    constexpr gfxrecon::format::HandleId        buffer_id   = 42;

    VkDescriptorUpdateTemplateEntry entry{};
    entry.descriptorCount = 1;
    entry.descriptorType  = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    entry.offset          = 16;
    entry.stride          = 64;
    consumer.AddDescriptorUpdateTemplate(template_id, { entry });

    std::vector<uint8_t> encoded;
    const uint32_t       attributes = gfxrecon::format::PointerAttributes::kIsStruct |
                                gfxrecon::format::PointerAttributes::kIsSingle |
                                gfxrecon::format::PointerAttributes::kHasData;
    AppendEncodedValue(&encoded, attributes);
    AppendEncodedValue(&encoded, gfxrecon::format::SizeTEncodeType{ 0 });
    AppendEncodedValue(&encoded, gfxrecon::format::SizeTEncodeType{ 1 });
    AppendEncodedValue(&encoded, gfxrecon::format::SizeTEncodeType{ 0 });
    AppendEncodedValue(&encoded, gfxrecon::format::HandleEncodeType{ buffer_id });
    AppendEncodedValue(&encoded, gfxrecon::format::DeviceSizeEncodeType{ 7 });
    AppendEncodedValue(&encoded, gfxrecon::format::DeviceSizeEncodeType{ 9 });

    gfxrecon::decode::DescriptorUpdateTemplateDecoder decoder;
    REQUIRE(decoder.Decode(encoded.data(), encoded.size()) == encoded.size());

    std::vector<uint8_t> materialized;
    REQUIRE(consumer.MaterializeDescriptorUpdateTemplate(template_id, &decoder, &materialized));
    REQUIRE(materialized.size() == (entry.offset + sizeof(VkDescriptorBufferInfo)));
    CHECK(std::all_of(
        materialized.begin(), materialized.begin() + entry.offset, [](uint8_t value) { return value == 0; }));

    VkDescriptorBufferInfo buffer_info{};
    std::memcpy(&buffer_info, materialized.data() + entry.offset, sizeof(buffer_info));
    CHECK(buffer_info.buffer == gfxrecon::format::FromHandleId<VkBuffer>(buffer_id));
    CHECK(buffer_info.offset == 7);
    CHECK(buffer_info.range == 9);
}

TEST_CASE("Vulkan native callbacks export synchronous ray tracing pipeline creation", "[vulkan_api_call_reader]")
{
    NativeCallbackTestState                     state;
    gfxrecon::decode::VulkanNativeCallCallbacks callbacks;
    gfxrecon::decode::VulkanNativeCallConsumer  consumer(callbacks);
    const gfxrecon::decode::ApiCallInfo         call_info{ 7, 9 };

    callbacks.Register(
        { "vkCreateRayTracingPipelinesKHR", reinterpret_cast<PFN_vkVoidFunction>(TestCreateRayTracingPipelinesKHR) });
    native_callback_test_state = &state;
    gfxrecon::decode::args::CreateRayTracingPipelinesKHR args{};
    args.result = VK_SUCCESS;
    args.device = 1;
    consumer.Process_vkCreateRayTracingPipelinesKHR(call_info, args);
    native_callback_test_state = nullptr;

    CHECK(state.create_ray_tracing_pipelines_count == 1);
    CHECK(state.valid_create_info);
    CHECK(callbacks.GetLastError().code == gfxrecon::decode::VulkanNativeCallErrorCode::kNone);

    args.result            = VK_OPERATION_DEFERRED_KHR;
    args.deferredOperation = 2;
    consumer.Process_vkCreateRayTracingPipelinesKHR(call_info, args);
    CHECK(state.create_ray_tracing_pipelines_count == 1);
    CHECK(callbacks.GetLastError().code == gfxrecon::decode::VulkanNativeCallErrorCode::kUnsupportedCommand);
}

TEST_CASE("Vulkan native callbacks export device memory properties metadata", "[vulkan_api_call_reader]")
{
    NativeCallbackTestState                     state;
    gfxrecon::decode::VulkanNativeCallCallbacks callbacks;
    TestNativeCallConsumer                      consumer(callbacks);

    callbacks.SetDeviceMemoryPropertiesCallback(TestDeviceMemoryProperties, &state);
    const std::vector<gfxrecon::format::DeviceMemoryType> memory_types = {
        { VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, 0 },
        { VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, 1 },
    };
    const std::vector<gfxrecon::format::DeviceMemoryHeap> memory_heaps = {
        { 4096, VK_MEMORY_HEAP_DEVICE_LOCAL_BIT },
        { 8192, 0 },
    };
    consumer.ProcessDeviceMemoryProperties(7, 9, 11, memory_types, memory_heaps);

    CHECK(state.device_memory_properties_count == 1);
    CHECK(state.valid_device_memory_properties);
}

TEST_CASE("Vulkan native callbacks export resource initialization metadata", "[vulkan_api_call_reader]")
{
    ResourceInitializationTestState             state;
    gfxrecon::decode::VulkanNativeCallCallbacks callbacks;
    TestNativeCallConsumer                      consumer(callbacks);

    callbacks.SetResourceInitializationBeginCallback(TestResourceInitializationBegin, &state);
    callbacks.SetBufferInitializationCallback(TestBufferInitialization, &state);
    callbacks.SetImageInitializationCallback(TestImageInitialization, &state);
    callbacks.SetResourceInitializationEndCallback(TestResourceInitializationEnd, &state);

    constexpr gfxrecon::format::HandleId device_id = 20;
    consumer.ProcessResourceInitializationBegin(1, 2, device_id, 12, 8);

    const uint8_t buffer_data[] = { 1, 2, 3, 4 };
    consumer.ProcessBufferInitialization(3, 2, device_id, 21, sizeof(buffer_data), buffer_data);

    const uint8_t               image_data[] = { 5, 6, 7 };
    const std::vector<uint64_t> level_sizes  = { 2, 1 };
    consumer.ProcessImageInitialization(5,
                                        2,
                                        device_id,
                                        22,
                                        sizeof(image_data),
                                        VK_IMAGE_ASPECT_COLOR_BIT,
                                        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
                                        level_sizes,
                                        image_data);

    consumer.ProcessResourceInitializationEnd(7, 2, device_id);

    CHECK(state.callback_index == 4);
    CHECK(state.valid);
}

TEST_CASE("Vulkan native callbacks export acceleration structure build metadata", "[vulkan_api_call_reader]")
{
    bool                                        valid = false;
    gfxrecon::decode::VulkanNativeCallCallbacks callbacks;
    TestNativeCallConsumer                      consumer(callbacks);

    callbacks.SetAccelerationStructuresBuildCallback(TestAccelerationStructuresBuild, &valid);
    consumer.SetCurrentBlockIndex(17);
    std::vector<std::vector<VkAccelerationStructureInstanceKHR>> instance_buffers;
    consumer.ProcessVulkanBuildAccelerationStructuresCommand(19, 0, nullptr, nullptr, instance_buffers);

    CHECK(valid);

    VkAccelerationStructureGeometryKHR geometries[3]{};
    for (size_t i = 0; i < std::size(geometries); ++i)
    {
        geometries[i].sType                    = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR;
        geometries[i].geometryType             = VK_GEOMETRY_TYPE_INSTANCES_KHR;
        geometries[i].geometry.instances.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR;
        geometries[i].geometry.instances.data.deviceAddress = 100 + (i * 100);
    }
    const VkAccelerationStructureGeometryKHR* indirect_geometry = &geometries[2];

    VkAccelerationStructureBuildGeometryInfoKHR build_infos[3]{};
    build_infos[0].type          = VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR;
    build_infos[0].geometryCount = 1;
    build_infos[0].pGeometries   = &geometries[0];
    build_infos[1].type          = VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR;
    build_infos[1].geometryCount = 2;
    build_infos[1].pGeometries   = geometries;
    build_infos[2].type          = VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR;
    build_infos[2].geometryCount = 1;
    build_infos[2].ppGeometries  = &indirect_geometry;

    VkAccelerationStructureInstanceKHR instance{};
    instance.instanceCustomIndex = 23;
    instance_buffers             = { { instance }, { instance }, { instance } };
    const auto descriptions      = consumer.DescribeInstanceBuffers(build_infos, 3, instance_buffers);
    REQUIRE(descriptions.size() == 3);
    CHECK(descriptions[0].build_info_index == 1);
    CHECK(descriptions[0].geometry_index == 0);
    CHECK(descriptions[0].source_device_address == 100);
    CHECK(descriptions[1].build_info_index == 1);
    CHECK(descriptions[1].geometry_index == 1);
    CHECK(descriptions[1].source_device_address == 200);
    CHECK(descriptions[2].build_info_index == 2);
    CHECK(descriptions[2].geometry_index == 0);
    CHECK(descriptions[2].source_device_address == 300);
    CHECK(descriptions[2].instance_count == 1);
    CHECK(descriptions[2].instances[0].instanceCustomIndex == 23);

    AccelerationStructureRelatedTestState related_state;
    callbacks.SetAccelerationStructuresCopyCallback(TestAccelerationStructuresCopy, &related_state);
    callbacks.SetAccelerationStructureWritePropertiesCallback(TestAccelerationStructureWriteProperties, &related_state);
    consumer.SetCurrentBlockIndex(18);
    consumer.ProcessVulkanCopyAccelerationStructuresCommand(19, nullptr);
    consumer.SetCurrentBlockIndex(19);
    consumer.ProcessVulkanWriteAccelerationStructuresPropertiesCommand(
        19, VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR, 20);
    CHECK(related_state.copy);
    CHECK(related_state.write);
}

TEST_CASE("Vulkan native callbacks export opaque addresses", "[vulkan_api_call_reader]")
{
    std::vector<gfxrecon::decode::VulkanOpaqueAddress> opaque_addresses;
    gfxrecon::decode::VulkanNativeCallCallbacks        callbacks;
    TestNativeCallConsumer                             consumer(callbacks);

    callbacks.SetOpaqueAddressCallback(TestOpaqueAddress, &opaque_addresses);

    const VkObjectType object_types[] = { VK_OBJECT_TYPE_BUFFER,
                                          VK_OBJECT_TYPE_DEVICE_MEMORY,
                                          VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR,
                                          VK_OBJECT_TYPE_MICROMAP_EXT };
    for (size_t i = 0; i < std::size(object_types); ++i)
    {
        const uint64_t object_id     = 24 + i;
        const uint64_t object_handle = 100 + i;
        consumer.ProcessOpaqueAddress(21 + i, 22, 23, object_id, 0x123456789abcdef0ull + i);
        consumer.ResolveOpaqueObject(object_id, object_types[i], object_handle);
    }

    consumer.ProcessOpaqueAddress(25, 22, 23, 99, 0x5555);
    consumer.FlushPendingOpaqueAddresses();

    REQUIRE(opaque_addresses.size() == 5);
    for (size_t i = 0; i < std::size(object_types); ++i)
    {
        CHECK(opaque_addresses[i].block_index == 21 + i);
        CHECK(opaque_addresses[i].thread_id == 22);
        CHECK(opaque_addresses[i].device != VK_NULL_HANDLE);
        CHECK(opaque_addresses[i].object_id == 24 + i);
        CHECK(opaque_addresses[i].address == 0x123456789abcdef0ull + i);
        CHECK(opaque_addresses[i].object_type == object_types[i]);
        CHECK(opaque_addresses[i].object_handle == 100 + i);
    }
    CHECK(opaque_addresses[4].object_id == 99);
    CHECK(opaque_addresses[4].object_type == VK_OBJECT_TYPE_UNKNOWN);
    CHECK(opaque_addresses[4].object_handle == 0);
}

TEST_CASE("Vulkan API call reader invokes registered native callbacks", "[vulkan_api_call_reader]")
{
    NativeCallbackTestState               state;
    gfxrecon::decode::VulkanApiCallReader reader;
    const std::string                     capture_path = std::string(GFXRECON_TEST_DATA_DIR) + "/triangle.gfxr";

    gfxrecon::decode::VulkanNativeCommandInfo create_instance_info;
    REQUIRE(reader.GetSupportedCallbackInfo("vkCreateInstance", &create_instance_info));
    CHECK(create_instance_info.call_id == gfxrecon::format::ApiCallId::ApiCall_vkCreateInstance);
    gfxrecon::decode::VulkanNativeCommandInfo descriptor_template_info;
    REQUIRE(reader.GetSupportedCallbackInfo("vkUpdateDescriptorSetWithTemplateKHR", &descriptor_template_info));
    CHECK(descriptor_template_info.call_id ==
          gfxrecon::format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR);
    gfxrecon::decode::VulkanNativeCommandInfo ray_tracing_pipeline_info;
    REQUIRE(reader.GetSupportedCallbackInfo("vkCreateRayTracingPipelinesKHR", &ray_tracing_pipeline_info));
    CHECK(ray_tracing_pipeline_info.call_id == gfxrecon::format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);
    CHECK_FALSE(reader.RegisterCallback("vkNotARealCommand", TestCreateInstance));
    REQUIRE(reader.RegisterCallback("vkCreateInstance", TestCreateInstance));
    REQUIRE(reader.RegisterCallback("vkCreateInstance", nullptr));

    const gfxrecon::decode::VulkanNativeCallbackEntry callbacks[] = {
        { "vkCreateInstance", reinterpret_cast<PFN_vkVoidFunction>(TestCreateInstance) },
        { "vkCmdDraw", reinterpret_cast<PFN_vkVoidFunction>(TestCmdDraw) },
        { "vkNotARealCommand", reinterpret_cast<PFN_vkVoidFunction>(TestCmdDraw) }
    };
    std::vector<gfxrecon::decode::VulkanNativeCallbackRegistrationError> rejected;
    CHECK(reader.RegisterCallbacks(callbacks, std::size(callbacks), &rejected) == 2);
    REQUIRE(rejected.size() == 1);
    CHECK(rejected[0].index == 2);
    CHECK(rejected[0].status == gfxrecon::decode::VulkanNativeCallbackRegistrationStatus::kUnsupportedCommand);
    REQUIRE(reader.SetPreCallHook(TestPreCall, &state));
    REQUIRE(reader.SetPostCallHook(TestPostCall, &state));
    REQUIRE(reader.SetMissingCallbackHook(TestMissingCallback, &state));
    REQUIRE(reader.SetDeviceMemoryPropertiesCallback(TestDeviceMemoryProperties, &state));

    native_callback_test_state = &state;
    const bool initialized     = reader.Initialize(capture_path);
    const bool processed       = initialized && reader.ProcessAllFrames();
    native_callback_test_state = nullptr;

    REQUIRE(initialized);
    REQUIRE(processed);
    CHECK(state.create_instance_result == VK_SUCCESS);
    CHECK(state.create_instance_count == 1);
    CHECK(state.valid_create_info);
    CHECK(state.valid_instance);
    CHECK(state.draw_count > 0);
    CHECK(state.valid_draw);
    CHECK(state.pre_call_count == (state.create_instance_count + state.draw_count));
    CHECK(state.post_call_count == state.pre_call_count);
    CHECK(state.missing_callback_count > 0);
    CHECK(state.device_memory_properties_count > 0);
    CHECK(state.valid_device_memory_properties);
}

TEST_CASE("Vulkan API call reader invokes memory update callbacks", "[vulkan_api_call_reader]")
{
    NativeCallbackTestState               state;
    gfxrecon::decode::VulkanApiCallReader reader;
    const std::string capture_path = std::string(GFXRECON_TEST_DATA_DIR) + "/external-memory-fd-import.gfxr";

    REQUIRE(reader.RegisterCallback("vkMapMemory", TestMapMemory));
    REQUIRE(reader.RegisterCallback("vkUnmapMemory", TestUnmapMemory));
    REQUIRE(reader.SetMemoryUpdateCallback(TestMemoryUpdate, &state));

    native_callback_test_state = &state;
    const bool initialized     = reader.Initialize(capture_path);
    const bool processed       = initialized && reader.ProcessAllFrames();
    native_callback_test_state = nullptr;

    REQUIRE(initialized);
    REQUIRE(processed);
    CHECK(state.memory_update_count == 1);
    CHECK(state.valid_memory_updates);
}

TEST_CASE("Vulkan API call reader reports unhandled metacommands", "[vulkan_api_call_reader]")
{
    NativeCallbackTestState               state;
    gfxrecon::decode::VulkanApiCallReader reader;
    const std::string                     capture_path = std::string(GFXRECON_TEST_DATA_DIR) + "/triangle.gfxr";

    REQUIRE(reader.SetUnhandledMetaCommandCallback(TestUnhandledMetaCommand, &state));
    REQUIRE(reader.Initialize(capture_path));
    REQUIRE(reader.ProcessAllFrames());

    CHECK(state.unhandled_meta_command_count > 0);
    CHECK(state.last_unhandled_meta_command_block > 0);
    CHECK(state.last_unhandled_metadata_id != 0);
}

TEST_CASE("Vulkan API call reader strict mode reports missing callbacks", "[vulkan_api_call_reader]")
{
    gfxrecon::decode::VulkanApiCallReader reader;
    const std::string                     capture_path = std::string(GFXRECON_TEST_DATA_DIR) + "/triangle.gfxr";

    REQUIRE(reader.SetMissingCallbackPolicy(gfxrecon::decode::VulkanNativeMissingCallbackPolicy::kFail));
    REQUIRE(reader.Initialize(capture_path));
    CHECK_FALSE(reader.ProcessAllFrames());
    REQUIRE(reader.HasNativeCallError());

    const auto& error = reader.GetLastNativeCallError();
    CHECK(error.code == gfxrecon::decode::VulkanNativeCallErrorCode::kMissingCallback);
    CHECK(error.name == "vkCreateInstance");
    CHECK(error.call_id == gfxrecon::format::ApiCallId::ApiCall_vkCreateInstance);
    CHECK(error.call_info.index > 0);
    CHECK(error.call_info.thread_id > 0);
}

const VkBuffer                   kBufferHandles[] = { gfxrecon::format::FromHandleId<VkBuffer>(0xabcd),
                                                      gfxrecon::format::FromHandleId<VkBuffer>(0xbcda),
                                                      gfxrecon::format::FromHandleId<VkBuffer>(0xcdab),
                                                      gfxrecon::format::FromHandleId<VkBuffer>(0xdabc) };
const gfxrecon::format::HandleId kBufferIds[]     = { 12, 24, 48, 96 };
const gfxrecon::format::HandleId kDeviceId        = 6;

TEST_CASE("handle IDs need to be mapped to valid handles", "[wrapper]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::LoggingSeverity::kError);

    gfxrecon::decode::CommonObjectInfoTable info_table;

    // Basic add.
    gfxrecon::decode::handle_mapping::AddHandle<gfxrecon::decode::VulkanBufferInfo>(
        kDeviceId,
        kBufferIds[0],
        kBufferHandles[0],
        &info_table,
        &gfxrecon::decode::CommonObjectInfoTable::AddVkBufferInfo);

    SECTION("Add a total of four entries to the object table")
    {
        // Basic array add.
        gfxrecon::decode::handle_mapping::AddHandleArray<gfxrecon::decode::VulkanBufferInfo>(
            kDeviceId,
            &kBufferIds[1],
            1,
            &kBufferHandles[1],
            1,
            &info_table,
            &gfxrecon::decode::CommonObjectInfoTable::AddVkBufferInfo);

        // Array add with info and different ID/handle counts.
        gfxrecon::decode::handle_mapping::AddHandleArray<gfxrecon::decode::VulkanBufferInfo>(
            kDeviceId,
            &kBufferIds[2],
            1,
            &kBufferHandles[2],
            2,
            std::vector<gfxrecon::decode::VulkanBufferInfo>(1),
            &info_table,
            &gfxrecon::decode::CommonObjectInfoTable::AddVkBufferInfo);

        // Add with info.
        gfxrecon::decode::handle_mapping::AddHandle<gfxrecon::decode::VulkanBufferInfo>(
            kDeviceId,
            kBufferIds[3],
            kBufferHandles[3],
            gfxrecon::decode::VulkanBufferInfo{},
            &info_table,
            &gfxrecon::decode::CommonObjectInfoTable::AddVkBufferInfo);

        std::vector<const gfxrecon::decode::VulkanBufferInfo*> buffers;
        info_table.VisitVkBufferInfo(
            [&buffers](const gfxrecon::decode::VulkanBufferInfo* info) { buffers.push_back(info); });

        REQUIRE(buffers.size() == 4);
    }

    SECTION("Add a duplicate entry to the object table, which is ignored")
    {
        gfxrecon::decode::handle_mapping::AddHandle<gfxrecon::decode::VulkanBufferInfo>(
            kDeviceId,
            kBufferIds[0],
            kBufferHandles[0],
            &info_table,
            &gfxrecon::decode::CommonObjectInfoTable::AddVkBufferInfo);

        std::vector<const gfxrecon::decode::VulkanBufferInfo*> buffers;
        info_table.VisitVkBufferInfo(
            [&buffers](const gfxrecon::decode::VulkanBufferInfo* info) { buffers.push_back(info); });

        REQUIRE(buffers.size() == 1);
    }

    SECTION("Remove an entry from the object table")
    {
        gfxrecon::decode::handle_mapping::RemoveHandle(
            kBufferIds[0], &info_table, &gfxrecon::decode::CommonObjectInfoTable::RemoveVkBufferInfo);

        std::vector<const gfxrecon::decode::VulkanBufferInfo*> buffers;
        info_table.VisitVkBufferInfo(
            [&buffers](const gfxrecon::decode::VulkanBufferInfo* info) { buffers.push_back(info); });

        REQUIRE(buffers.size() == 0);
    }

    SECTION("Buffer ID 12 maps to a valid buffer handle")
    {
        auto buffer = gfxrecon::decode::handle_mapping::MapHandle<gfxrecon::decode::VulkanBufferInfo>(
            kBufferIds[0], info_table, &gfxrecon::decode::CommonObjectInfoTable::GetVkBufferInfo);

        REQUIRE(buffer == kBufferHandles[0]);
    }

    SECTION("Invalid buffer ID 99 does not map to a valid buffer handle")
    {
        auto buffer = gfxrecon::decode::handle_mapping::MapHandle<gfxrecon::decode::VulkanBufferInfo>(
            99, info_table, &gfxrecon::decode::CommonObjectInfoTable::GetVkBufferInfo);

        REQUIRE(buffer == VK_NULL_HANDLE);
    }

    SECTION("An integer ID with value 12 and type VK_OBJECT_TYPE_BUFFER maps to a valid buffer handle represented as "
            "an integer")
    {
        auto object = gfxrecon::decode::handle_mapping::MapHandle(kBufferIds[0], VK_OBJECT_TYPE_BUFFER, info_table);

        REQUIRE(object == gfxrecon::format::ToHandleId(kBufferHandles[0]));
    }

    gfxrecon::util::Log::Release();
}

TEST_CASE("BlockParser basic usage", "[wrapper]")
{
    bool err_triggered = false;
    auto err_handler   = [&err_triggered](gfxrecon::decode::BlockIOError, const char*) { err_triggered = true; };

    gfxrecon::decode::BlockParser block_parser(err_handler, nullptr);

    // this should trigger some error
    block_parser.HandleBlockReadError(gfxrecon::decode::BlockIOError::kErrorReadingBlockData, "fatal fake error");
    REQUIRE(err_triggered);
}

TEST_CASE("Test a roundtrip between SubmitInfo2Translator and SubmitInfoTranslator", "[]")
{
    const VkSemaphore     wait_semaphores[2]   = { gfxrecon::format::FromHandleId<VkSemaphore>(0x11),
                                                   gfxrecon::format::FromHandleId<VkSemaphore>(0x12) };
    const VkSemaphore     signal_semaphores[1] = { gfxrecon::format::FromHandleId<VkSemaphore>(0x21) };
    const VkCommandBuffer command_buffers[1]   = { gfxrecon::format::FromHandleId<VkCommandBuffer>(0x31) };

    const VkPipelineStageFlags wait_stages[2] = { VK_PIPELINE_STAGE_VERTEX_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT };

    // Values carried by the three pNext structures that must be translated into VkSubmitInfo2 fields and removed from
    // the chain.
    const uint64_t wait_values[2]           = { 7, 8 };
    const uint64_t signal_values[1]         = { 42 };
    const uint32_t wait_device_indices[2]   = { 1, 0 };
    const uint32_t signal_device_indices[1] = { 1 };
    const uint32_t command_buffer_masks[1]  = { 0x2 };

    const VkDeviceGroupSubmitInfo device_group{ VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO,
                                                nullptr,
                                                2,
                                                wait_device_indices,
                                                1,
                                                command_buffer_masks,
                                                1,
                                                signal_device_indices };
    const VkProtectedSubmitInfo   protected_info{ VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO, &device_group, VK_TRUE };
    const VkTimelineSemaphoreSubmitInfo timeline{
        VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO, &protected_info, 2, wait_values, 1, signal_values
    };

    const VkSubmitInfo submit_info{ VK_STRUCTURE_TYPE_SUBMIT_INFO,
                                    &timeline,
                                    2,
                                    wait_semaphores,
                                    wait_stages,
                                    1,
                                    command_buffers,
                                    1,
                                    signal_semaphores };

    const std::vector<VkSubmitInfo>                 infos_v1{ submit_info };
    const gfxrecon::graphics::SubmitInfo2Translator v1_to_v2_translator(infos_v1);
    const auto&                                     infos_v2 = v1_to_v2_translator.GetSubmitInfos2();

    REQUIRE(infos_v1.size() == infos_v2.size());

    const VkSubmitInfo2& submit_info2 = infos_v2[0];
    REQUIRE(submit_info2.sType == VK_STRUCTURE_TYPE_SUBMIT_INFO_2);

    // Verify protected submission flag
    REQUIRE((submit_info2.flags & VK_SUBMIT_PROTECTED_BIT) != 0);

    // Verify Wait semaphores
    REQUIRE(submit_info2.waitSemaphoreInfoCount == 2);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[0].semaphore == wait_semaphores[0]);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[0].stageMask == static_cast<VkPipelineStageFlags2>(wait_stages[0]));
    REQUIRE(submit_info2.pWaitSemaphoreInfos[0].value == wait_values[0]);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[0].deviceIndex == wait_device_indices[0]);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[1].semaphore == wait_semaphores[1]);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[1].stageMask == static_cast<VkPipelineStageFlags2>(wait_stages[1]));
    REQUIRE(submit_info2.pWaitSemaphoreInfos[1].value == wait_values[1]);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[1].deviceIndex == wait_device_indices[1]);

    // Verify command buffers
    REQUIRE(submit_info2.commandBufferInfoCount == 1);
    REQUIRE(submit_info2.pCommandBufferInfos[0].commandBuffer == command_buffers[0]);
    REQUIRE(submit_info2.pCommandBufferInfos[0].deviceMask == command_buffer_masks[0]);

    // Signal semaphores signal at ALL_COMMANDS and carry the timeline value and device index.
    REQUIRE(submit_info2.signalSemaphoreInfoCount == 1);
    REQUIRE(submit_info2.pSignalSemaphoreInfos[0].semaphore == signal_semaphores[0]);
    REQUIRE(submit_info2.pSignalSemaphoreInfos[0].stageMask == VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT);
    REQUIRE(submit_info2.pSignalSemaphoreInfos[0].value == signal_values[0]);
    REQUIRE(submit_info2.pSignalSemaphoreInfos[0].deviceIndex == signal_device_indices[0]);

    // All three translated structures must be stripped from the VkSubmitInfo2 pNext-chain.
    REQUIRE(gfxrecon::graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(&submit_info2) == nullptr);
    REQUIRE(gfxrecon::graphics::vulkan_struct_get_pnext<VkProtectedSubmitInfo>(&submit_info2) == nullptr);
    REQUIRE(gfxrecon::graphics::vulkan_struct_get_pnext<VkDeviceGroupSubmitInfo>(&submit_info2) == nullptr);

    // Round-trip: narrow the VkSubmitInfo2 back into a VkSubmitInfo. The result must be equivalent to the original
    // VkSubmitInfo, with the timeline/device-group/protected information reconstructed into pNext structures.
    const gfxrecon::graphics::SubmitInfoTranslator v2_to_v1_translator(infos_v2);
    const auto&                                    infos_v1_roundtrip = v2_to_v1_translator.GetSubmitInfos();

    REQUIRE(infos_v1_roundtrip.size() == infos_v2.size());

    const VkSubmitInfo& r = infos_v1_roundtrip[0];
    REQUIRE(r.sType == VK_STRUCTURE_TYPE_SUBMIT_INFO);

    // Verify wait semaphores
    REQUIRE(r.waitSemaphoreCount == submit_info.waitSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.waitSemaphoreCount; ++i)
    {
        REQUIRE(r.pWaitSemaphores[i] == submit_info.pWaitSemaphores[i]);
        REQUIRE(r.pWaitDstStageMask[i] == submit_info.pWaitDstStageMask[i]);
    }

    REQUIRE(r.commandBufferCount == submit_info.commandBufferCount);
    for (uint32_t i = 0; i < submit_info.commandBufferCount; ++i)
    {
        REQUIRE(r.pCommandBuffers[i] == submit_info.pCommandBuffers[i]);
    }

    REQUIRE(r.signalSemaphoreCount == submit_info.signalSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.signalSemaphoreCount; ++i)
    {
        REQUIRE(r.pSignalSemaphores[i] == submit_info.pSignalSemaphores[i]);
    }

    // Verify that the protected flag has turned into a VkProtectedSubmitInfo.
    const auto* r_protected = gfxrecon::graphics::vulkan_struct_get_pnext<VkProtectedSubmitInfo>(&r);
    REQUIRE(r_protected != nullptr);
    REQUIRE(r_protected->protectedSubmit == protected_info.protectedSubmit);

    // Verify that the timeline values have turned into a VkTimelineSemaphoreSubmitInfo.
    const auto* r_timeline = gfxrecon::graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(&r);
    REQUIRE(r_timeline != nullptr);
    REQUIRE(r_timeline->waitSemaphoreValueCount == submit_info.waitSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.waitSemaphoreCount; ++i)
    {
        REQUIRE(r_timeline->pWaitSemaphoreValues[i] == wait_values[i]);
    }
    REQUIRE(r_timeline->signalSemaphoreValueCount == submit_info.signalSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.signalSemaphoreCount; ++i)
    {
        REQUIRE(r_timeline->pSignalSemaphoreValues[i] == signal_values[i]);
    }

    // Verify that the device-group indices/masks have turned into a VkDeviceGroupSubmitInfo.
    const auto* r_device_group = gfxrecon::graphics::vulkan_struct_get_pnext<VkDeviceGroupSubmitInfo>(&r);
    REQUIRE(r_device_group != nullptr);
    REQUIRE(r_device_group->waitSemaphoreCount == submit_info.waitSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.waitSemaphoreCount; ++i)
    {
        REQUIRE(r_device_group->pWaitSemaphoreDeviceIndices[i] == wait_device_indices[i]);
    }
    REQUIRE(r_device_group->commandBufferCount == submit_info.commandBufferCount);
    for (uint32_t i = 0; i < submit_info.commandBufferCount; ++i)
    {
        REQUIRE(r_device_group->pCommandBufferDeviceMasks[i] == command_buffer_masks[i]);
    }
    REQUIRE(r_device_group->signalSemaphoreCount == submit_info.signalSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.signalSemaphoreCount; ++i)
    {
        REQUIRE(r_device_group->pSignalSemaphoreDeviceIndices[i] == signal_device_indices[i]);
    }
}

TEST_CASE("ReferencedResourceTable classifies destroyed command buffers", "[optimize]")
{
    using gfxrecon::decode::ReferencedResourceTable;
    using gfxrecon::format::HandleId;

    constexpr HandleId kPool     = 1;
    constexpr HandleId kCmd      = 2;
    constexpr HandleId kPipeline = 3;

    ReferencedResourceTable table;
    table.AddResource(kPipeline);
    table.AddUser(kPool, kCmd);
    table.AddResourceToUser(kCmd, kPipeline);

    std::unordered_set<HandleId> unreferenced;

    SECTION("recorded, never submitted, then freed: user and resource are both unreferenced")
    {
        // The recorded blocks of a destroyed command buffer stay in the capture file, so the user must still be
        // classified as unreferenced for those blocks to be removed together with the pipeline creation call.
        table.RemoveUser(kCmd); // vkFreeCommandBuffers

        table.GetReferencedHandleIds(nullptr, &unreferenced);
        REQUIRE(unreferenced.count(kCmd) == 1);
        REQUIRE(unreferenced.count(kPipeline) == 1);
    }

    SECTION("recorded, never submitted, then pool destroyed: user and resource are both unreferenced")
    {
        table.ClearUsers(kPool); // vkDestroyCommandPool

        table.GetReferencedHandleIds(nullptr, &unreferenced);
        REQUIRE(unreferenced.count(kCmd) == 1);
        REQUIRE(unreferenced.count(kPipeline) == 1);
    }

    SECTION("submitted and then freed: user and resource are both referenced")
    {
        table.ProcessUserSubmission(kCmd);
        table.RemoveUser(kCmd);

        table.GetReferencedHandleIds(nullptr, &unreferenced);
        REQUIRE(unreferenced.count(kCmd) == 0);
        REQUIRE(unreferenced.count(kPipeline) == 0);
    }
}

TEST_CASE("ReferencedResourceTable marks resources recorded into a previously submitted user", "[optimize]")
{
    using gfxrecon::decode::ReferencedResourceTable;
    using gfxrecon::format::HandleId;

    constexpr HandleId kPool      = 1;
    constexpr HandleId kCmd       = 2;
    constexpr HandleId kPipeline1 = 3;
    constexpr HandleId kPipeline2 = 4;

    ReferencedResourceTable table;
    table.AddUser(kPool, kCmd);
    table.AddResource(kPipeline1);
    table.AddResourceToUser(kCmd, kPipeline1);
    table.ProcessUserSubmission(kCmd);

    // Re-record the command buffer with a new pipeline, without a following submission (e.g. the capture ended
    // between recording and submission).  All blocks of the submitted command buffer stay in the capture file,
    // including the new recording, so the new pipeline must be classified as referenced.
    table.ResetUser(kCmd); // vkBeginCommandBuffer
    table.AddResource(kPipeline2);
    table.AddResourceToUser(kCmd, kPipeline2);

    std::unordered_set<HandleId> unreferenced;
    table.GetReferencedHandleIds(nullptr, &unreferenced);
    REQUIRE(unreferenced.count(kPipeline1) == 0);
    REQUIRE(unreferenced.count(kPipeline2) == 0);
}

TEST_CASE("ReferencedResourceTable processes executed secondary command buffers", "[optimize]")
{
    using gfxrecon::decode::ReferencedResourceTable;
    using gfxrecon::format::HandleId;

    constexpr HandleId kPool      = 1;
    constexpr HandleId kPrimary   = 2;
    constexpr HandleId kSecondary = 3;
    constexpr HandleId kNested    = 4;
    constexpr HandleId kPipeline  = 5;

    ReferencedResourceTable table;
    table.AddUser(kPool, kPrimary);
    table.AddUser(kPool, kSecondary);

    std::unordered_set<HandleId> unreferenced;

    SECTION("nested secondaries of a submitted primary are marked recursively")
    {
        table.AddUser(kPool, kNested);
        table.AddResource(kPipeline);
        table.AddResourceToUser(kNested, kPipeline);
        table.AddUserToUser(kSecondary, kNested);  // vkCmdExecuteCommands in the secondary
        table.AddUserToUser(kPrimary, kSecondary); // vkCmdExecuteCommands in the primary
        table.ProcessUserSubmission(kPrimary);

        table.GetReferencedHandleIds(nullptr, &unreferenced);
        REQUIRE(unreferenced.count(kSecondary) == 0);
        REQUIRE(unreferenced.count(kNested) == 0);
        REQUIRE(unreferenced.count(kPipeline) == 0);
    }

    SECTION("execute-commands recorded into an already submitted primary marks the secondary")
    {
        table.ProcessUserSubmission(kPrimary);

        // Trailing recording without a following submission: the primary's blocks all stay in the capture file,
        // so the executed secondary and its resources must be classified as referenced.
        table.AddResource(kPipeline);
        table.AddResourceToUser(kSecondary, kPipeline);
        table.AddUserToUser(kPrimary, kSecondary);

        table.GetReferencedHandleIds(nullptr, &unreferenced);
        REQUIRE(unreferenced.count(kSecondary) == 0);
        REQUIRE(unreferenced.count(kPipeline) == 0);
    }
}

// ScreenshotController holds every part of a screenshot that is not an API
// call.  None of this had a test: the frame selection lived in
// ScreenshotHandlerBase and the rest lived in the Vulkan consumer.
TEST_CASE("ScreenshotController selects the frames it was asked for", "[screenshot]")
{
    using gfxrecon::decode::ReplayOptions;
    using gfxrecon::decode::ScreenshotController;
    using gfxrecon::decode::ScreenshotRange;

    SECTION("no range asked for")
    {
        ReplayOptions        options;
        ScreenshotController controller(options);

        REQUIRE_FALSE(controller.Enabled());
        REQUIRE_FALSE(controller.IsScreenshotFrame());
    }

    SECTION("one closed range")
    {
        ReplayOptions options;
        options.screenshot_ranges = { ScreenshotRange{ 3, 5 } };

        ScreenshotController controller(options);
        REQUIRE(controller.Enabled());

        // Frames 1 and 2 are outside it, 3 to 5 are inside, 6 is past it.
        const bool expected[] = { false, false, true, true, true, false };
        for (uint32_t frame = 1; frame <= 6; ++frame)
        {
            REQUIRE(controller.GetCurrentFrame() == frame);
            REQUIRE(controller.IsScreenshotFrame() == expected[frame - 1]);
            controller.EndFrame();
        }
    }

    SECTION("an interval counts from the start of the range")
    {
        ReplayOptions options;
        options.screenshot_ranges   = { ScreenshotRange{ 2, 8 } };
        options.screenshot_interval = 3;

        ScreenshotController controller(options);

        // 2, 5 and 8: every third frame counting from the first of the range,
        // not from frame 1.
        const bool expected[] = { false, true, false, false, true, false, false, true };
        for (uint32_t frame = 1; frame <= 8; ++frame)
        {
            REQUIRE(controller.IsScreenshotFrame() == expected[frame - 1]);
            controller.EndFrame();
        }
    }

    SECTION("two ranges are taken in turn")
    {
        ReplayOptions options;
        options.screenshot_ranges = { ScreenshotRange{ 1, 2 }, ScreenshotRange{ 4, 4 } };

        ScreenshotController controller(options);

        const bool expected[] = { true, true, false, true, false };
        for (uint32_t frame = 1; frame <= 5; ++frame)
        {
            REQUIRE(controller.IsScreenshotFrame() == expected[frame - 1]);
            controller.EndFrame();
        }
    }

    SECTION("an interval of zero does not divide by zero")
    {
        ReplayOptions options;
        options.screenshot_ranges   = { ScreenshotRange{ 1, 2 } };
        options.screenshot_interval = 0;

        ScreenshotController controller(options);
        REQUIRE(controller.IsScreenshotFrame());
    }
}

TEST_CASE("ScreenshotController names one file per presented image", "[screenshot]")
{
    using gfxrecon::decode::ReplayOptions;
    using gfxrecon::decode::ScreenshotController;
    using gfxrecon::decode::ScreenshotRange;

    ReplayOptions options;
    options.screenshot_ranges      = { ScreenshotRange{ 1, 4 } };
    options.screenshot_file_prefix = "shot";

    ScreenshotController controller(options);

    // One image in the frame: the name says nothing about a swapchain, which is
    // the name these files have always had.
    REQUIRE(controller.FilenameFor() == "shot_frame_1");

    // More than one: each gets its own name.
    REQUIRE(controller.FilenameFor(0, 2) == "shot_swapchain_0_frame_1");
    REQUIRE(controller.FilenameFor(1, 2) == "shot_swapchain_1_frame_1");

    controller.EndFrame();
    REQUIRE(controller.FilenameFor() == "shot_frame_2");
}

// The one rule that was written down twice, with opposite emphasis:
// tools/replay/replay_settings.h says --screenshot-size is ignored when a scale
// is given, and android/scripts/gfxrecon.py says the scale overrides the size.
// Same rule; this is the executable statement of it.
TEST_CASE("ScreenshotController resolves a scale, and a scale beats a size", "[screenshot]")
{
    using gfxrecon::decode::ReplayOptions;
    using gfxrecon::decode::ScreenshotController;

    SECTION("neither given: the image is read at its own size")
    {
        ReplayOptions options;
        REQUIRE_FALSE(ScreenshotController(options).ResolveScale(800, 600).has_value());
    }

    SECTION("a scale is used as given, both axes")
    {
        ReplayOptions options;
        options.screenshot_scale = std::array<float, 2>{ 0.5f, -1.0f };

        const auto scale = ScreenshotController(options).ResolveScale(800, 600);
        REQUIRE(scale.has_value());
        REQUIRE(scale.value()[0] == 0.5f);

        // A negative factor is how an axis is flipped, thus the sign has to
        // survive.
        REQUIRE(scale.value()[1] == -1.0f);
    }

    SECTION("a size becomes the scale that reaches it")
    {
        ReplayOptions options;
        options.screenshot_width  = 400;
        options.screenshot_height = 300;

        const auto scale = ScreenshotController(options).ResolveScale(800, 600);
        REQUIRE(scale.has_value());
        REQUIRE(scale.value()[0] == 0.5f);
        REQUIRE(scale.value()[1] == 0.5f);
    }

    SECTION("a size need not keep the aspect ratio")
    {
        ReplayOptions options;
        options.screenshot_width  = 800;
        options.screenshot_height = 300;

        const auto scale = ScreenshotController(options).ResolveScale(800, 600);
        REQUIRE(scale.has_value());
        REQUIRE(scale.value()[0] == 1.0f);
        REQUIRE(scale.value()[1] == 0.5f);
    }

    SECTION("both given: the scale wins and the size is ignored")
    {
        ReplayOptions options;
        options.screenshot_scale  = std::array<float, 2>{ 0.25f, 0.25f };
        options.screenshot_width  = 400;
        options.screenshot_height = 300;

        const auto scale = ScreenshotController(options).ResolveScale(800, 600);
        REQUIRE(scale.has_value());
        REQUIRE(scale.value()[0] == 0.25f);
        REQUIRE(scale.value()[1] == 0.25f);
    }

    SECTION("half a size is no size at all")
    {
        ReplayOptions options;
        options.screenshot_width = 400; // and no height

        REQUIRE_FALSE(ScreenshotController(options).ResolveScale(800, 600).has_value());
    }
}

TEST_CASE("ScreenshotController writes the file, rotating when asked", "[screenshot]")
{
    using gfxrecon::decode::CpuImage;
    using gfxrecon::decode::ReplayOptions;
    using gfxrecon::decode::Rotation;
    using gfxrecon::decode::ScreenshotController;
    namespace imagewriter = gfxrecon::util::imagewriter;

    const uint32_t        width  = 4;
    const uint32_t        height = 2;
    std::vector<uint32_t> pixels(width * height);
    for (size_t i = 0; i < pixels.size(); ++i)
    {
        pixels[i] = static_cast<uint32_t>(0xff000000u | (i * 0x010203u));
    }

    CpuImage image;
    image.width  = width;
    image.height = height;
    image.pitch  = width * 4;
    image.format = imagewriter::kFormat_BGRA;
    image.pixels = pixels.data();

    ReplayOptions options;
    options.screenshot_format = gfxrecon::util::ScreenshotFormat::kBmp;

    SECTION("no rotation")
    {
        ScreenshotController controller(options);
        REQUIRE(controller.Finish("screenshot_controller_plain", image, Rotation{}));
    }

    SECTION("a quarter turn swaps the sides")
    {
        ScreenshotController controller(options);

        Rotation rotation;
        rotation.rotation = imagewriter::ImageRotation::DEG_90;

        REQUIRE(controller.Finish("screenshot_controller_turned", image, rotation));
    }

    SECTION("an image that was never read back is refused")
    {
        ScreenshotController controller(options);

        CpuImage empty;
        REQUIRE_FALSE(controller.Finish("screenshot_controller_empty", empty, Rotation{}));
    }
}
