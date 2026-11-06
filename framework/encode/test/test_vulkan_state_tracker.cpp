/*
** Copyright (c) 2026 LunarG, Inc.
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

// Catch must come before the Vulkan headers because Xlib defines None and Always as macros.
#include <catch2/catch.hpp>

#include "encode/vulkan_device_address_tracker.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_tracker.h"
#include "encode/vulkan_state_writer.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_state_table.h"
#include "util/file_output_stream.h"
#include "util/logging.h"
#include "util/memory_output_stream.h"
#include "util/thread_data.h"

#include "vulkan/vulkan.h"

#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace gfxrecon;
namespace wrappers = encode::vulkan_wrappers;

namespace
{

using Geometry   = VkAccelerationStructureGeometryKHR;
using BuildRange = VkAccelerationStructureBuildRangeInfoKHR;

const VkDeviceAddress kAccelerationStructureAddress = 0x200000;
const VkDeviceAddress kInputBufferAddress           = 0x100000;
const VkDeviceSize    kInputBufferSize              = 0x1000;

const std::vector<VkDeviceAddress> kVertexAddresses = { kInputBufferAddress + 0x40,
                                                        kInputBufferAddress + 0x80,
                                                        kInputBufferAddress + 0xc0 };

format::HandleId GetHandleId()
{
    return format::kNullHandleId;
}

Geometry MakeTriangles(VkDeviceAddress vertex_address)
{
    Geometry geometry{};
    geometry.sType                           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR;
    geometry.geometryType                    = VK_GEOMETRY_TYPE_TRIANGLES_KHR;
    geometry.geometry.triangles.sType        = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR;
    geometry.geometry.triangles.vertexFormat = VK_FORMAT_R32G32B32_SFLOAT;
    geometry.geometry.triangles.vertexData.deviceAddress = vertex_address;
    geometry.geometry.triangles.vertexStride             = 12;
    geometry.geometry.triangles.maxVertex                = 3;
    geometry.geometry.triangles.indexType                = VK_INDEX_TYPE_NONE_KHR;
    return geometry;
}

Geometry MakeInstances(VkDeviceAddress instances_address)
{
    Geometry geometry{};
    geometry.sType                    = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR;
    geometry.geometryType             = VK_GEOMETRY_TYPE_INSTANCES_KHR;
    geometry.geometry.instances.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR;
    geometry.geometry.instances.data.deviceAddress = instances_address;
    return geometry;
}

std::vector<Geometry> MakeTriangleGeometries()
{
    std::vector<Geometry> geometries;
    for (const VkDeviceAddress address : kVertexAddresses)
    {
        geometries.push_back(MakeTriangles(address));
    }
    return geometries;
}

std::vector<BuildRange> MakeRanges(size_t count)
{
    std::vector<BuildRange> ranges(count);
    for (size_t i = 0; i < count; ++i)
    {
        ranges[i].primitiveCount  = static_cast<uint32_t>(10 + i);
        ranges[i].primitiveOffset = static_cast<uint32_t>(16 * i);
    }
    return ranges;
}

// Registers the handles an acceleration structure build refers to, without needing a Vulkan device.
class AccelerationStructureFixture
{
  public:
    explicit AccelerationStructureFixture(VkAccelerationStructureTypeKHR type)
    {
        util::Log::Init(util::LoggingSeverity::kError);

        device.handle    = format::FromHandleId<VkDevice>(0x1001);
        device.handle_id = 1;

        pool.handle    = format::FromHandleId<VkCommandPool>(0x1002);
        pool.handle_id = 2;
        pool.device    = &device;

        command_buffer.handle      = format::FromHandleId<VkCommandBuffer>(0x1003);
        command_buffer.handle_id   = 3;
        command_buffer.parent_pool = &pool;

        as_buffer.handle            = format::FromHandleId<VkBuffer>(0x1004);
        as_buffer.handle_id         = 4;
        as_buffer.device            = &device;
        as_buffer.size              = 0x1000;
        as_buffer.create_call_id    = format::ApiCall_vkCreateBuffer;
        as_buffer.create_parameters = std::make_shared<util::MemoryOutputStream>();

        input_buffer.handle    = format::FromHandleId<VkBuffer>(0x1005);
        input_buffer.handle_id = 5;
        input_buffer.device    = &device;
        input_buffer.size      = kInputBufferSize;

        acceleration_structure.handle    = format::FromHandleId<VkAccelerationStructureKHR>(0x1006);
        acceleration_structure.handle_id = 6;
        acceleration_structure.device    = &device;
        acceleration_structure.address   = kAccelerationStructureAddress;
        acceleration_structure.type      = type;
        acceleration_structure.buffer    = &as_buffer;
        acceleration_structure.size      = 0x1000;

        wrappers::state_handle_table_.InsertWrapper(&device);
        wrappers::state_handle_table_.InsertWrapper(&pool);
        wrappers::state_handle_table_.InsertWrapper(&command_buffer);
        wrappers::state_handle_table_.InsertWrapper(&as_buffer);
        wrappers::state_handle_table_.InsertWrapper(&input_buffer);
        wrappers::state_handle_table_.InsertWrapper(&acceleration_structure);

        tracker.TrackBufferDeviceAddress(device.handle, input_buffer.handle, kInputBufferAddress);
    }

    ~AccelerationStructureFixture()
    {
        wrappers::RemoveWrapper(&acceleration_structure);
        wrappers::RemoveWrapper(&input_buffer);
        wrappers::RemoveWrapper(&as_buffer);
        wrappers::RemoveWrapper(&command_buffer);
        wrappers::RemoveWrapper(&pool);
        wrappers::RemoveWrapper(&device);

        util::Log::Release();
    }

    // Tracks a build that uses pGeometries. The application's array is overwritten once the call returns.
    void TrackWithArray(std::vector<Geometry> geometries)
    {
        VkAccelerationStructureBuildGeometryInfoKHR info = MakeBuildInfo(geometries.size());
        info.pGeometries                                 = geometries.data();

        Track(info);

        std::fill(geometries.begin(), geometries.end(), Geometry{});
    }

    // Tracks a build that uses ppGeometries, with separately allocated geometries so they are not contiguous. The
    // application's allocations are released once the call returns.
    void TrackWithPointerArray(const std::vector<Geometry>& geometries)
    {
        std::vector<std::unique_ptr<Geometry>> allocations;
        std::vector<const Geometry*>           pointers;
        for (const Geometry& geometry : geometries)
        {
            allocations.push_back(std::make_unique<Geometry>(geometry));
            pointers.push_back(allocations.back().get());
        }

        VkAccelerationStructureBuildGeometryInfoKHR info = MakeBuildInfo(geometries.size());
        info.ppGeometries                                = pointers.data();

        Track(info);
    }

    const encode::AccelerationStructureKHRBuildCommandData& GetTrackedBuild() const
    {
        const auto& build_state = as_buffer.acceleration_structures.at(kAccelerationStructureAddress);
        REQUIRE(build_state.latest_build_command.has_value());
        return *build_state.latest_build_command;
    }

    // Runs the state writer over the tracked state and returns the bytes it wrote.
    std::vector<uint8_t> WriteState()
    {
        const std::filesystem::path path =
            std::filesystem::temp_directory_path() / "gfxrecon_encode_test_as_build_state.gfxr";

        {
            util::FileOutputStream output(path.string(), 0);
            util::ThreadData       thread_data;

            encode::VulkanStateTable state_table;
            state_table.InsertWrapper(as_buffer.handle_id, &as_buffer);

            std::unordered_map<VkDevice, encode::VulkanDeviceAddressTracker> address_trackers;
            address_trackers[device.handle];

            encode::VulkanStateWriter writer(&output, nullptr, &thread_data, GetHandleId, address_trackers);
            writer.WriteState(state_table, 0);
        }

        std::ifstream        file(path, std::ios::binary);
        std::vector<uint8_t> bytes{ std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };
        file.close();
        std::filesystem::remove(path);
        return bytes;
    }

    wrappers::DeviceWrapper                   device;
    wrappers::CommandPoolWrapper              pool;
    wrappers::CommandBufferWrapper            command_buffer;
    wrappers::BufferWrapper                   as_buffer;
    wrappers::BufferWrapper                   input_buffer;
    wrappers::AccelerationStructureKHRWrapper acceleration_structure;
    encode::VulkanStateTracker                tracker;

  private:
    VkAccelerationStructureBuildGeometryInfoKHR MakeBuildInfo(size_t geometry_count) const
    {
        VkAccelerationStructureBuildGeometryInfoKHR info{};
        info.sType                     = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR;
        info.type                      = acceleration_structure.type;
        info.mode                      = VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR;
        info.dstAccelerationStructure  = acceleration_structure.handle;
        info.geometryCount             = static_cast<uint32_t>(geometry_count);
        info.scratchData.deviceAddress = 0x300000;
        return info;
    }

    void Track(const VkAccelerationStructureBuildGeometryInfoKHR& info)
    {
        const std::vector<BuildRange> ranges     = MakeRanges(info.geometryCount);
        const BuildRange*             ranges_ptr = ranges.data();

        tracker.TrackAccelerationStructureBuildCommand(command_buffer.handle, 1, &info, &ranges_ptr);
    }
};

void RequireTrackedTriangles(const encode::AccelerationStructureKHRBuildCommandData& command,
                             const wrappers::BufferWrapper&                          input_buffer)
{
    const uint32_t count = static_cast<uint32_t>(kVertexAddresses.size());

    REQUIRE(command.geometry_info.geometryCount == count);
    REQUIRE(command.geometry_info.pGeometries != nullptr);
    REQUIRE(command.geometry_info.ppGeometries == nullptr);

    for (uint32_t g = 0; g < count; ++g)
    {
        const Geometry& geometry = command.geometry_info.pGeometries[g];
        REQUIRE(geometry.geometryType == VK_GEOMETRY_TYPE_TRIANGLES_KHR);
        REQUIRE(geometry.geometry.triangles.vertexData.deviceAddress == kVertexAddresses[g]);
    }

    const std::vector<BuildRange> expected_ranges = MakeRanges(count);
    REQUIRE(command.build_range_infos.size() == count);
    for (uint32_t g = 0; g < count; ++g)
    {
        REQUIRE(command.build_range_infos[g].primitiveCount == expected_ranges[g].primitiveCount);
        REQUIRE(command.build_range_infos[g].primitiveOffset == expected_ranges[g].primitiveOffset);
    }

    REQUIRE(command.input_buffers.size() == 1);
    REQUIRE(command.input_buffers.count(input_buffer.handle_id) == 1);
}

// Walks the block stream and returns each acceleration structure build meta command, including its header.
std::vector<std::vector<uint8_t>> FindBuildBlocks(const std::vector<uint8_t>& bytes)
{
    std::vector<std::vector<uint8_t>> blocks;

    size_t offset = 0;
    while (offset + sizeof(format::BlockHeader) <= bytes.size())
    {
        format::BlockHeader header{};
        std::memcpy(&header, bytes.data() + offset, sizeof(header));

        const size_t block_size = sizeof(header) + static_cast<size_t>(header.size);
        REQUIRE(offset + block_size <= bytes.size());

        if (header.type == format::kMetaDataBlock)
        {
            format::MetaDataId meta_data_id{};
            std::memcpy(&meta_data_id, bytes.data() + offset + sizeof(header), sizeof(meta_data_id));

            if (format::GetMetaDataType(meta_data_id) ==
                format::MetaDataType::kVulkanBuildAccelerationStructuresCommand)
            {
                blocks.emplace_back(bytes.begin() + offset, bytes.begin() + offset + block_size);
            }
        }

        offset += block_size;
    }

    REQUIRE(offset == bytes.size());
    return blocks;
}

bool ContainsAddress(const std::vector<uint8_t>& block, VkDeviceAddress address)
{
    const auto* address_bytes = reinterpret_cast<const uint8_t*>(&address);
    return std::search(block.begin(), block.end(), address_bytes, address_bytes + sizeof(address)) != block.end();
}

} // namespace

TEST_CASE("Build using ppGeometries is tracked as a deep copied array", "[state_tracker][acceleration_structure]")
{
    AccelerationStructureFixture fixture(VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR);

    fixture.TrackWithPointerArray(MakeTriangleGeometries());

    RequireTrackedTriangles(fixture.GetTrackedBuild(), fixture.input_buffer);
}

TEST_CASE("Build using pGeometries is tracked as a deep copied array", "[state_tracker][acceleration_structure]")
{
    AccelerationStructureFixture fixture(VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR);

    fixture.TrackWithArray(MakeTriangleGeometries());

    RequireTrackedTriangles(fixture.GetTrackedBuild(), fixture.input_buffer);
}

TEST_CASE("TLAS build info is recorded for both geometry pointer forms", "[state_tracker][acceleration_structure]")
{
    const VkDeviceAddress instances_address = kInputBufferAddress + 0x100;

    AccelerationStructureFixture fixture(VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR);

    SECTION("pGeometries")
    {
        fixture.TrackWithArray({ MakeInstances(instances_address) });
    }

    SECTION("ppGeometries")
    {
        fixture.TrackWithPointerArray({ MakeInstances(instances_address) });
    }

    const BuildRange expected_range = MakeRanges(1)[0];

    REQUIRE(fixture.command_buffer.tlas_build_info_map.size() == 1);

    const auto& [tlas_wrapper, tlas_info] = fixture.command_buffer.tlas_build_info_map[0];
    REQUIRE(tlas_wrapper == &fixture.acceleration_structure);
    REQUIRE(tlas_info.address == instances_address);
    REQUIRE(tlas_info.blas_count == expected_range.primitiveCount);
    REQUIRE(tlas_info.offset == expected_range.primitiveOffset);
}

TEST_CASE("State writer encodes the same build for both geometry pointer forms",
          "[state_tracker][state_writer][acceleration_structure]")
{
    std::vector<std::vector<uint8_t>> array_blocks;
    {
        AccelerationStructureFixture fixture(VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR);
        fixture.TrackWithArray(MakeTriangleGeometries());
        array_blocks = FindBuildBlocks(fixture.WriteState());
    }

    std::vector<std::vector<uint8_t>> pointer_array_blocks;
    {
        AccelerationStructureFixture fixture(VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR);
        fixture.TrackWithPointerArray(MakeTriangleGeometries());
        pointer_array_blocks = FindBuildBlocks(fixture.WriteState());
    }

    REQUIRE(array_blocks.size() == 1);
    REQUIRE(pointer_array_blocks.size() == 1);

    // A ppGeometries pointer left in the tracked struct would be encoded in addition to pGeometries, growing the block.
    // The blocks can't be compared byte for byte because they contain the addresses of the tracked allocations.
    REQUIRE(pointer_array_blocks[0].size() == array_blocks[0].size());

    for (const VkDeviceAddress address : kVertexAddresses)
    {
        REQUIRE(ContainsAddress(array_blocks[0], address));
        REQUIRE(ContainsAddress(pointer_array_blocks[0], address));
    }
}
