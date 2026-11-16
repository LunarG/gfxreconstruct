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

// Before any Vulkan header: on Linux, vulkan.h includes Xlib.h, whose macros break catch.hpp.
#include <catch2/catch.hpp>

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_tracker.h"
#include "format/format.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <array>
#include <deque>
#include <utility>
#include <vector>

namespace // Support functions and data for the VulkanStateTracker tests
{
gfxrecon::format::HandleId GetNextTrackedHandleId()
{
    static gfxrecon::format::HandleId next_id = 1000;
    return ++next_id;
}

// A dispatchable handle points to an object whose first member is the loader's dispatch table pointer.
struct DispatchableObject
{
    void* dispatch_table{ nullptr };
};

// The wrappers the state tracker reads, created as the capture layer creates them, for handles no driver has made.
class TrackedObjects
{
  public:
    TrackedObjects()
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        device_ = reinterpret_cast<VkDevice>(&device_object_);
        CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DeviceWrapper>(
            VK_NULL_HANDLE, NoParentWrapper::kHandleValue, &device_, GetNextTrackedHandleId);
    }

    ~TrackedObjects()
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        // Destroying a pool destroys the wrappers of its command buffers.
        for (VkCommandPool pool : command_pools_)
        {
            DestroyWrappedHandle<CommandPoolWrapper>(pool);
        }
        for (VkAccelerationStructureKHR acceleration_structure : acceleration_structures_)
        {
            DestroyWrappedHandle<AccelerationStructureKHRWrapper>(acceleration_structure);
        }
        for (VkBuffer buffer : buffers_)
        {
            DestroyWrappedHandle<BufferWrapper>(buffer);
        }
        for (VkImage image : images_)
        {
            DestroyWrappedHandle<ImageWrapper>(image);
        }
        DestroyWrappedHandle<DeviceWrapper>(device_);
    }

    VkCommandPool CreateCommandPool(uint32_t queue_family_index)
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        VkCommandPool pool = gfxrecon::format::FromHandleId<VkCommandPool>(NextHandleValue());
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, CommandPoolWrapper>(
            device_, NoParentWrapper::kHandleValue, &pool, GetNextTrackedHandleId);
        GetWrapper<CommandPoolWrapper>(pool)->queue_family_index = queue_family_index;

        command_pools_.push_back(pool);
        return pool;
    }

    VkCommandBuffer CreateCommandBuffer(VkCommandPool pool)
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        VkCommandBuffer command_buffer = reinterpret_cast<VkCommandBuffer>(&command_buffer_objects_.emplace_back());
        CreateWrappedHandle<DeviceWrapper, CommandPoolWrapper, CommandBufferWrapper>(
            device_, pool, &command_buffer, GetNextTrackedHandleId);

        return command_buffer;
    }

    VkBuffer CreateBuffer()
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        VkBuffer buffer = gfxrecon::format::FromHandleId<VkBuffer>(NextHandleValue());
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, BufferWrapper>(
            device_, NoParentWrapper::kHandleValue, &buffer, GetNextTrackedHandleId);

        buffers_.push_back(buffer);
        return buffer;
    }

    VkImage CreateImage()
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        VkImage image = gfxrecon::format::FromHandleId<VkImage>(NextHandleValue());
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ImageWrapper>(
            device_, NoParentWrapper::kHandleValue, &image, GetNextTrackedHandleId);

        images_.push_back(image);
        return image;
    }

    VkAccelerationStructureKHR CreateAccelerationStructure()
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        VkAccelerationStructureKHR acceleration_structure =
            gfxrecon::format::FromHandleId<VkAccelerationStructureKHR>(NextHandleValue());
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, AccelerationStructureKHRWrapper>(
            device_, NoParentWrapper::kHandleValue, &acceleration_structure, GetNextTrackedHandleId);

        acceleration_structures_.push_back(acceleration_structure);
        return acceleration_structure;
    }

    VkDevice GetDevice() const { return device_; }

    gfxrecon::encode::vulkan_wrappers::DeviceWrapper* GetDeviceWrapper() const
    {
        return gfxrecon::encode::vulkan_wrappers::GetWrapper<gfxrecon::encode::vulkan_wrappers::DeviceWrapper>(device_);
    }

  private:
    uint64_t NextHandleValue() { return ++next_handle_value_; }

    uint64_t                       next_handle_value_{ 0x10000 };
    DispatchableObject             device_object_;
    VkDevice                       device_{ VK_NULL_HANDLE };
    std::deque<DispatchableObject> command_buffer_objects_; // A deque keeps the addresses the handles point to.
    std::vector<VkCommandPool>     command_pools_;
    std::vector<VkBuffer>          buffers_;
    std::vector<VkImage>           images_;

    std::vector<VkAccelerationStructureKHR> acceleration_structures_;
};

VkImageMemoryBarrier MakeLayoutTransition(VkImage image, VkImageLayout old_layout, VkImageLayout new_layout)
{
    VkImageMemoryBarrier barrier = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
    barrier.oldLayout            = old_layout;
    barrier.newLayout            = new_layout;
    barrier.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
    barrier.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
    barrier.image                = image;
    barrier.subresourceRange     = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 };
    return barrier;
}

constexpr VkDeviceSize       kBufferSize          = 0x1000;
constexpr VkDeviceAddress    kAccelerationAddress = 0x40000;
constexpr VkBufferUsageFlags kInputUsage        = VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR;
constexpr VkBufferUsageFlags kAccelerationUsage = VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR;

// Keeps logging initialized for as long as the objects declared after it are alive.
struct LogScope
{
    LogScope() { gfxrecon::util::Log::Init(gfxrecon::util::LoggingSeverity::kError); }
    ~LogScope() { gfxrecon::util::Log::Release(); }
};

// One acceleration structure, the buffers its build reads, and the command buffer the build is recorded into.
struct AccelerationStructureBuildObjects
{
    LogScope                             log_scope;
    TrackedObjects                       objects;
    gfxrecon::encode::VulkanStateTracker tracker;

    VkCommandBuffer            command_buffer{ objects.CreateCommandBuffer(objects.CreateCommandPool(0)) };
    VkAccelerationStructureKHR acceleration_structure{ VK_NULL_HANDLE };

    // Creates a buffer and registers its device address with the state tracker.
    VkBuffer AddBuffer(VkDeviceAddress address, VkBufferUsageFlags usage)
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        const VkBuffer buffer = objects.CreateBuffer();

        auto* wrapper   = GetWrapper<BufferWrapper>(buffer);
        wrapper->device = objects.GetDeviceWrapper();
        wrapper->size   = kBufferSize;
        wrapper->usage  = usage;
        tracker.TrackBufferDeviceAddress(objects.GetDevice(), buffer, address);

        return buffer;
    }

    // Creates the acceleration structure and places it at the start of a backing buffer.
    gfxrecon::encode::vulkan_wrappers::AccelerationStructureKHRWrapper*
    AddAccelerationStructure(VkAccelerationStructureTypeKHR type, VkBuffer backing_buffer)
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        acceleration_structure = objects.CreateAccelerationStructure();

        auto* wrapper    = GetWrapper<AccelerationStructureKHRWrapper>(acceleration_structure);
        wrapper->device  = objects.GetDeviceWrapper();
        wrapper->type    = type;
        wrapper->buffer  = GetWrapper<BufferWrapper>(backing_buffer);
        wrapper->offset  = 0;
        wrapper->size    = kBufferSize;
        wrapper->address = kAccelerationAddress;
        return wrapper;
    }

    const gfxrecon::encode::AccelerationStructureKHRBuildCommandData& LatestBuildCommand(VkBuffer backing_buffer) const
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        auto* wrapper = GetWrapper<BufferWrapper>(backing_buffer);
        REQUIRE(wrapper->acceleration_structures.count(kAccelerationAddress) == 1);
        const auto& build_state = wrapper->acceleration_structures.at(kAccelerationAddress);
        REQUIRE(build_state.latest_build_command.has_value());
        return *build_state.latest_build_command;
    }

    const std::vector<std::pair<gfxrecon::encode::vulkan_wrappers::AccelerationStructureKHRWrapper*,
                                gfxrecon::encode::vulkan_wrappers::CommandBufferWrapper::tlas_build_info>>&
    TlasBuildInfos() const
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        return GetWrapper<CommandBufferWrapper>(command_buffer)->tlas_build_info_map;
    }
};

VkAccelerationStructureBuildGeometryInfoKHR MakeBuildInfo(VkAccelerationStructureTypeKHR type,
                                                          VkAccelerationStructureKHR     acceleration_structure,
                                                          uint32_t                       geometry_count)
{
    VkAccelerationStructureBuildGeometryInfoKHR build_info{};
    build_info.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR;
    build_info.type  = type;
    // Updates must be recorded as full builds with no source; the tracker is expected to rewrite these.
    build_info.mode                     = VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR;
    build_info.srcAccelerationStructure = acceleration_structure;
    build_info.dstAccelerationStructure = acceleration_structure;
    build_info.geometryCount            = geometry_count;
    return build_info;
}

VkAccelerationStructureGeometryKHR MakeTrianglesGeometry(VkDeviceAddress vertex_address, VkDeviceAddress index_address)
{
    VkAccelerationStructureGeometryKHR geometry{};
    geometry.sType                           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR;
    geometry.geometryType                    = VK_GEOMETRY_TYPE_TRIANGLES_KHR;
    geometry.geometry.triangles.sType        = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR;
    geometry.geometry.triangles.vertexFormat = VK_FORMAT_R32G32B32_SFLOAT;
    geometry.geometry.triangles.vertexData.deviceAddress = vertex_address;
    geometry.geometry.triangles.vertexStride             = 12;
    geometry.geometry.triangles.maxVertex                = 2;
    geometry.geometry.triangles.indexType                = VK_INDEX_TYPE_UINT32;
    geometry.geometry.triangles.indexData.deviceAddress  = index_address;
    return geometry;
}

VkAccelerationStructureGeometryKHR MakeAabbsGeometry(VkDeviceAddress aabb_address)
{
    VkAccelerationStructureGeometryKHR geometry{};
    geometry.sType                             = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR;
    geometry.geometryType                      = VK_GEOMETRY_TYPE_AABBS_KHR;
    geometry.geometry.aabbs.sType              = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR;
    geometry.geometry.aabbs.data.deviceAddress = aabb_address;
    geometry.geometry.aabbs.stride             = sizeof(VkAabbPositionsKHR);
    return geometry;
}

VkAccelerationStructureGeometryKHR MakeInstancesGeometry(VkDeviceAddress instance_address, VkBool32 array_of_pointers)
{
    VkAccelerationStructureGeometryKHR geometry{};
    geometry.sType                              = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR;
    geometry.geometryType                       = VK_GEOMETRY_TYPE_INSTANCES_KHR;
    geometry.geometry.instances.sType           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR;
    geometry.geometry.instances.arrayOfPointers = array_of_pointers;
    geometry.geometry.instances.data.deviceAddress = instance_address;
    return geometry;
}

void CheckRangeEqual(const VkAccelerationStructureBuildRangeInfoKHR& actual,
                     const VkAccelerationStructureBuildRangeInfoKHR& expected)
{
    CHECK(actual.primitiveCount == expected.primitiveCount);
    CHECK(actual.primitiveOffset == expected.primitiveOffset);
    CHECK(actual.firstVertex == expected.firstVertex);
    CHECK(actual.transformOffset == expected.transformOffset);
}

void CheckInputBuffer(const gfxrecon::encode::AccelerationStructureKHRBuildCommandData& command,
                      VkBuffer                                                          buffer,
                      VkDeviceAddress                                                   address)
{
    using namespace gfxrecon::encode::vulkan_wrappers;

    const gfxrecon::format::HandleId handle_id = GetWrappedId<BufferWrapper>(buffer);
    REQUIRE(command.input_buffers.count(handle_id) == 1);

    const auto& input = command.input_buffers.at(handle_id);
    CHECK(input.handle == buffer);
    CHECK(input.handle_id == handle_id);
    CHECK(input.capture_address == address);
    CHECK(input.created_size == kBufferSize);
}
} // namespace

TEST_CASE("Every submit in a batch applies its command buffers' image layouts", "[state_tracking]")
{
    using gfxrecon::encode::vulkan_wrappers::GetWrapper;
    using gfxrecon::encode::vulkan_wrappers::ImageWrapper;

    gfxrecon::util::Log::Init(gfxrecon::util::LoggingSeverity::kError);

    {
        TrackedObjects                       objects;
        gfxrecon::encode::VulkanStateTracker tracker;

        const VkCommandPool   pool           = objects.CreateCommandPool(0);
        const VkCommandBuffer command_buffer = objects.CreateCommandBuffer(pool);
        const VkImage         image          = objects.CreateImage();

        const VkImageMemoryBarrier barrier =
            MakeLayoutTransition(image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
        tracker.TrackImageBarriers(command_buffer, 1, &barrier);

        REQUIRE(GetWrapper<ImageWrapper>(image)->current_layout == VK_IMAGE_LAYOUT_UNDEFINED);

        // The first submit carries no command buffers, as a submit that only waits on or signals semaphores does.
        SECTION("vkQueueSubmit")
        {
            VkSubmitInfo submits[2]       = { { VK_STRUCTURE_TYPE_SUBMIT_INFO }, { VK_STRUCTURE_TYPE_SUBMIT_INFO } };
            submits[1].commandBufferCount = 1;
            submits[1].pCommandBuffers    = &command_buffer;

            tracker.TrackCommandBufferSubmissions(2, submits);

            REQUIRE(GetWrapper<ImageWrapper>(image)->current_layout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
        }

        SECTION("vkQueueSubmit2")
        {
            VkCommandBufferSubmitInfo command_buffer_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO };
            command_buffer_info.commandBuffer             = command_buffer;

            VkSubmitInfo2 submits[2] = { { VK_STRUCTURE_TYPE_SUBMIT_INFO_2 }, { VK_STRUCTURE_TYPE_SUBMIT_INFO_2 } };
            submits[1].commandBufferInfoCount = 1;
            submits[1].pCommandBufferInfos    = &command_buffer_info;

            tracker.TrackCommandBufferSubmissions2(2, submits);

            REQUIRE(GetWrapper<ImageWrapper>(image)->current_layout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
        }
    }

    gfxrecon::util::Log::Release();
}

TEST_CASE("TrackAccelerationStructureBuildCommand deep-copies geometries passed through pGeometries",
          "[state_tracking][acceleration_structure]")
{
    constexpr VkDeviceAddress kVertexAddress = 0x10000;
    constexpr VkDeviceAddress kIndexAddress  = 0x20000;
    constexpr VkDeviceAddress kAabbAddress   = 0x30000;

    AccelerationStructureBuildObjects fake;

    const VkBuffer vertex_buffer = fake.AddBuffer(kVertexAddress, kInputUsage);
    const VkBuffer index_buffer  = fake.AddBuffer(kIndexAddress, kInputUsage);
    const VkBuffer aabb_buffer   = fake.AddBuffer(kAabbAddress, kInputUsage);
    const VkBuffer blas_buffer   = fake.AddBuffer(kAccelerationAddress, kAccelerationUsage);
    fake.AddAccelerationStructure(VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR, blas_buffer);

    // pGeometries: a contiguous array of geometries. The index address points into the middle of its buffer.
    std::array<VkAccelerationStructureGeometryKHR, 2> geometries = {
        MakeTrianglesGeometry(kVertexAddress, kIndexAddress + 0x100), MakeAabbsGeometry(kAabbAddress)
    };
    std::array<VkAccelerationStructureBuildRangeInfoKHR, 2> ranges       = { { { 1, 0, 0, 0 }, { 4, 0x80, 0, 0 } } };
    const VkAccelerationStructureBuildRangeInfoKHR*         range_ptrs[] = { ranges.data() };

    VkAccelerationStructureBuildGeometryInfoKHR build_info =
        MakeBuildInfo(VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR, fake.acceleration_structure, 2);
    build_info.pGeometries = geometries.data();

    fake.tracker.TrackAccelerationStructureBuildCommand(fake.command_buffer, 1, &build_info, range_ptrs);

    // The application may release its arrays as soon as the command is recorded. Wipe them to prove the tracker
    // keeps its own copy.
    const auto expected_geometries = geometries;
    const auto expected_ranges     = ranges;
    geometries.fill({});
    ranges.fill({});
    build_info = {};

    const auto& command = fake.LatestBuildCommand(blas_buffer);

    SECTION("build info is recorded as a full build of the destination")
    {
        CHECK(command.type == VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR);
        CHECK(command.buffer == blas_buffer);
        CHECK(command.size == kBufferSize);
        CHECK(command.offset == 0);
        CHECK(command.geometry_info.mode == VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR);
        CHECK(command.geometry_info.srcAccelerationStructure == VK_NULL_HANDLE);
        CHECK(command.geometry_info.dstAccelerationStructure == fake.acceleration_structure);
        CHECK(command.geometry_info.geometryCount == expected_geometries.size());
    }

    SECTION("geometries are copied into tracker-owned memory")
    {
        REQUIRE(command.geometry_info.pGeometries != nullptr);
        CHECK(command.geometry_info.ppGeometries == nullptr);
        CHECK(command.geometry_info.pGeometries != geometries.data());
        CHECK(command.geometry_info_memory != nullptr);

        const auto& triangles = command.geometry_info.pGeometries[0];
        CHECK(triangles.geometryType == VK_GEOMETRY_TYPE_TRIANGLES_KHR);
        CHECK(triangles.geometry.triangles.vertexData.deviceAddress == kVertexAddress);
        CHECK(triangles.geometry.triangles.indexData.deviceAddress == kIndexAddress + 0x100);
        CHECK(triangles.geometry.triangles.vertexFormat == VK_FORMAT_R32G32B32_SFLOAT);
        CHECK(triangles.geometry.triangles.maxVertex == 2);

        const auto& aabbs = command.geometry_info.pGeometries[1];
        CHECK(aabbs.geometryType == VK_GEOMETRY_TYPE_AABBS_KHR);
        CHECK(aabbs.geometry.aabbs.data.deviceAddress == kAabbAddress);
        CHECK(aabbs.geometry.aabbs.stride == sizeof(VkAabbPositionsKHR));
    }

    SECTION("exactly one range info is stored per geometry")
    {
        REQUIRE(command.build_range_infos.size() == expected_ranges.size());
        CheckRangeEqual(command.build_range_infos[0], expected_ranges[0]);
        CheckRangeEqual(command.build_range_infos[1], expected_ranges[1]);
    }

    SECTION("every referenced input buffer is resolved from its device address")
    {
        REQUIRE(command.input_buffers.size() == 3);
        CheckInputBuffer(command, vertex_buffer, kVertexAddress);
        CheckInputBuffer(command, index_buffer, kIndexAddress);
        CheckInputBuffer(command, aabb_buffer, kAabbAddress);
    }

    SECTION("a bottom-level build records no TLAS instance information")
    {
        CHECK(fake.TlasBuildInfos().empty());
    }
}

TEST_CASE("TrackAccelerationStructureBuildCommand deep-copies geometries passed through ppGeometries",
          "[state_tracking][acceleration_structure]")
{
    constexpr VkDeviceAddress kInstanceAddress0 = 0x10000;
    constexpr VkDeviceAddress kInstanceAddress1 = 0x20000;

    AccelerationStructureBuildObjects fake;

    const VkBuffer instance_buffer0 = fake.AddBuffer(kInstanceAddress0, kInputUsage);
    const VkBuffer instance_buffer1 = fake.AddBuffer(kInstanceAddress1, kInputUsage);
    const VkBuffer tlas_buffer      = fake.AddBuffer(kAccelerationAddress, kAccelerationUsage);
    auto* as_wrapper = fake.AddAccelerationStructure(VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR, tlas_buffer);

    // ppGeometries: geometries live in separate allocations referenced through an array of pointers.
    VkAccelerationStructureGeometryKHR        geometry0       = MakeInstancesGeometry(kInstanceAddress0, VK_FALSE);
    VkAccelerationStructureGeometryKHR        geometry1       = MakeInstancesGeometry(kInstanceAddress1, VK_TRUE);
    const VkAccelerationStructureGeometryKHR* geometry_ptrs[] = { &geometry0, &geometry1 };

    // Distinct per-geometry ranges, so the TLAS bookkeeping must read ranges[g] rather than ranges[0].
    std::array<VkAccelerationStructureBuildRangeInfoKHR, 2> ranges       = { { { 3, 0, 0, 0 }, { 5, 64, 0, 0 } } };
    const VkAccelerationStructureBuildRangeInfoKHR*         range_ptrs[] = { ranges.data() };

    VkAccelerationStructureBuildGeometryInfoKHR build_info =
        MakeBuildInfo(VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR, fake.acceleration_structure, 2);
    build_info.ppGeometries = geometry_ptrs;

    fake.tracker.TrackAccelerationStructureBuildCommand(fake.command_buffer, 1, &build_info, range_ptrs);

    const auto expected_ranges = ranges;
    geometry0                  = {};
    geometry1                  = {};
    geometry_ptrs[0]           = nullptr;
    geometry_ptrs[1]           = nullptr;
    ranges.fill({});
    build_info = {};

    const auto& command = fake.LatestBuildCommand(tlas_buffer);

    SECTION("build info is recorded as a full build of the destination")
    {
        CHECK(command.type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR);
        CHECK(command.buffer == tlas_buffer);
        CHECK(command.geometry_info.mode == VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR);
        CHECK(command.geometry_info.srcAccelerationStructure == VK_NULL_HANDLE);
        CHECK(command.geometry_info.geometryCount == 2);
    }

    SECTION("the pointer array and every pointee are copied into tracker-owned memory")
    {
        CHECK(command.geometry_info.pGeometries == nullptr);
        REQUIRE(command.geometry_info.ppGeometries != nullptr);
        CHECK(command.geometry_info.ppGeometries != geometry_ptrs);
        CHECK(command.geometry_info_memory != nullptr);

        REQUIRE(command.geometry_info.ppGeometries[0] != nullptr);
        REQUIRE(command.geometry_info.ppGeometries[1] != nullptr);
        CHECK(command.geometry_info.ppGeometries[0] != &geometry0);
        CHECK(command.geometry_info.ppGeometries[1] != &geometry1);

        const auto& instances0 = *command.geometry_info.ppGeometries[0];
        CHECK(instances0.geometryType == VK_GEOMETRY_TYPE_INSTANCES_KHR);
        CHECK(instances0.geometry.instances.data.deviceAddress == kInstanceAddress0);
        CHECK(instances0.geometry.instances.arrayOfPointers == VK_FALSE);

        const auto& instances1 = *command.geometry_info.ppGeometries[1];
        CHECK(instances1.geometryType == VK_GEOMETRY_TYPE_INSTANCES_KHR);
        CHECK(instances1.geometry.instances.data.deviceAddress == kInstanceAddress1);
        CHECK(instances1.geometry.instances.arrayOfPointers == VK_TRUE);
    }

    SECTION("exactly one range info is stored per geometry")
    {
        REQUIRE(command.build_range_infos.size() == expected_ranges.size());
        CheckRangeEqual(command.build_range_infos[0], expected_ranges[0]);
        CheckRangeEqual(command.build_range_infos[1], expected_ranges[1]);
    }

    SECTION("every referenced input buffer is resolved from its device address")
    {
        REQUIRE(command.input_buffers.size() == 2);
        CheckInputBuffer(command, instance_buffer0, kInstanceAddress0);
        CheckInputBuffer(command, instance_buffer1, kInstanceAddress1);
    }

    SECTION("TLAS instance information uses each geometry's own range info")
    {
        const auto& tlas_infos = fake.TlasBuildInfos();
        REQUIRE(tlas_infos.size() == 2);

        CHECK(tlas_infos[0].first == as_wrapper);
        CHECK(tlas_infos[0].second.address == kInstanceAddress0);
        CHECK(tlas_infos[0].second.blas_count == expected_ranges[0].primitiveCount);
        CHECK(tlas_infos[0].second.offset == expected_ranges[0].primitiveOffset);

        CHECK(tlas_infos[1].first == as_wrapper);
        CHECK(tlas_infos[1].second.address == kInstanceAddress1);
        CHECK(tlas_infos[1].second.blas_count == expected_ranges[1].primitiveCount);
        CHECK(tlas_infos[1].second.offset == expected_ranges[1].primitiveOffset);
    }
}
