/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_VULKAN_TRACKED_OBJECT_MAPPER_H
#define GFXRECON_DECODE_VULKAN_TRACKED_OBJECT_MAPPER_H

#include "decode/vulkan_tracked_object_info.h"
#include "util/defines.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// This class stores the tables of the tracked Vulkan memories,
// buffers, images objects information during the first pass
// of the replay.
// It is used to generate tables for these tracked objects and
// will be accessed later by replay consumer class during
// second pass of replay for memory portability purpose.
class VulkanTrackedObjectInfoTable
{
  public:
    // Add tracked instance information into the table map
    void AddTrackedInstanceInfo(TrackedInstanceInfo&& info);

    // Add tracked physical device information into the table map
    void AddTrackedPhysicalDeviceInfo(TrackedPhysicalDeviceInfo&& info);

    // Add tracked device information into the table map
    void AddTrackedDeviceInfo(TrackedDeviceInfo&& info);

    // Add tracked memory information into the tracked memories information table map
    void AddTrackedDeviceMemoryInfo(TrackedDeviceMemoryInfo&& info);

    // Add tracked resource information into the tracked resource (buffers and images) information table map
    void AddTrackedResourceInfo(TrackedResourceInfo&& info);

    // Return specified handle ID's instance information from the tracked instances information table map
    TrackedInstanceInfo*       GetTrackedInstanceInfo(format::HandleId id);
    const TrackedInstanceInfo* GetTrackedInstanceInfo(format::HandleId id) const;

    // Return specified handle ID's physical device information from the tracked physical device information table map
    TrackedPhysicalDeviceInfo*       GetTrackedPhysicalDeviceInfo(format::HandleId id);
    const TrackedPhysicalDeviceInfo* GetTrackedPhysicalDeviceInfo(format::HandleId id) const;

    // Return specified handle ID's device information from the tracked device information table map
    TrackedDeviceInfo*       GetTrackedDeviceInfo(format::HandleId id);
    const TrackedDeviceInfo* GetTrackedDeviceInfo(format::HandleId id) const;

    // Return specified handle ID's device memory information from the tracked memories information table map
    TrackedDeviceMemoryInfo*       GetTrackedDeviceMemoryInfo(format::HandleId id);
    const TrackedDeviceMemoryInfo* GetTrackedDeviceMemoryInfo(format::HandleId id) const;

    // Return specified handle ID's resource information from the tracked resources information table map
    TrackedResourceInfo*       GetTrackedResourceInfo(format::HandleId id);
    const TrackedResourceInfo* GetTrackedResourceInfo(format::HandleId id) const;

    // Return tracked device memories information table map
    std::unordered_map<format::HandleId, TrackedDeviceMemoryInfo>*       GetTrackedDeviceMemoriesInfoMap();
    const std::unordered_map<format::HandleId, TrackedDeviceMemoryInfo>* GetTrackedDeviceMemoriesInfoMap() const;

  private:
    // Helper template function for updating tracked objects ID with the information
    // into the objects' table map
    template <typename T>
    void AddTrackedObjectInfo(T&& info, std::unordered_map<format::HandleId, T>* map)
    {
        assert(map != nullptr);

        if ((info.GetCaptureId() != 0))
        {
            auto result = map->emplace(info.GetCaptureId(), std::forward<T>(info));

            if (!result.second)
            {
                // TODO(gfxrec-28): handle duplicate id cases?
                GFXRECON_LOG_WARNING("Duplicate entry for object id %" PRIu64, info.GetCaptureId());
            }
        }
    }

    // Helper template function for retrieving tracked objects information
    // with the specified ID from the objects' table map
    template <typename T>
    T* GetTrackedObjectInfo(format::HandleId id, std::unordered_map<format::HandleId, T>* map)
    {
        assert(map != nullptr);

        T* object_info = nullptr;

        if (id != 0)
        {
            auto entry = map->find(id);

            if (entry != map->end())
            {
                object_info = &entry->second;
            }
            else
            {
                GFXRECON_LOG_WARNING("Failed to map handle for object id %" PRIu64, id);
            }
        }

        return object_info;
    }

    // Helper template function for retrieving tracked objects information
    // with the specified ID from the objects' table map
    template <typename T>
    const T* GetTrackedObjectInfo(format::HandleId id, const std::unordered_map<format::HandleId, T>* map) const
    {
        assert(map != nullptr);

        const T* object_info = nullptr;

        if (id != 0)
        {
            auto entry = map->find(id);

            if (entry != map->end())
            {
                object_info = &entry->second;
            }
            else
            {
                GFXRECON_LOG_WARNING("Failed to map handle for object id %" PRIu64, id);
            }
        }

        return object_info;
    }

  private:
    std::unordered_map<format::HandleId, TrackedInstanceInfo>       tracked_instance_map_;
    std::unordered_map<format::HandleId, TrackedPhysicalDeviceInfo> tracked_physical_device_map_;
    std::unordered_map<format::HandleId, TrackedDeviceInfo>         tracked_device_map_;
    std::unordered_map<format::HandleId, TrackedDeviceMemoryInfo>   tracked_device_memory_map_;
    std::unordered_map<format::HandleId, TrackedResourceInfo>       tracked_resource_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_TRACKED_OBJECT_MAPPER_H
