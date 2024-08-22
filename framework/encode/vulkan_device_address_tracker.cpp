//#pragma once
#include "encode/vulkan_device_address_tracker.h"
#include "encode/vulkan_capture_manager.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void VulkanDeviceAddressTracker::TrackBufferDeviceAddress(format::HandleId id,
                                                          uint64_t         buffer_size,
                                                          VkDeviceAddress  address)
{
    std::lock_guard lg(*this);
    assert(address != 0);
    format::AddressLocationInfo loc{};
    loc.id               = id;
    loc.original_address = address;
    loc.size             = buffer_size;
    tracked_objects[id]  = loc;
}
void VulkanDeviceAddressTracker::TrackAccelerationStructureDeviceAddress(format::HandleId id, VkDeviceAddress address)
{
    std::lock_guard lg(*this);
    assert(address != 0);
    format::AddressLocationInfo loc{};
    loc.id               = id;
    loc.original_address = address;
    loc.adjusted_address = address;
    tracked_objects[id]  = loc;
}

std::vector<format::AddressLocationInfo>
VulkanDeviceAddressTracker::GetAddressesInMemoryRange(const std::vector<uint64_t>& ignored_usages,
                                                      const vulkan_wrappers::DeviceMemoryWrapper*   memory,
                                                      const void*                  start_address,
                                                      size_t                       offset,
                                                      size_t                       size)
{
    std::lock_guard lg(*this);

    if (tracked_objects.empty())
    {
        return {};
    }

    if (memory && !memory->bound_buffers.empty())
    {
        std::vector<vulkan_wrappers::BufferWrapper*> buffers;
        buffers.reserve(memory->bound_buffers.size());

        for (auto& buf : memory->bound_buffers)
        {
            bool ignore = false;
            for (auto usage : ignored_usages)
            {
                if ((buf->usage & usage) == usage)
                {
                    ignore = true;
                    break;
                }
            }
            if (!ignore)
            {
                buffers.push_back(buf);
            }
        }

        if (buffers.empty())
        {
            return {};
        }
    }

    auto [min, max] =
        std::minmax_element(tracked_objects.begin(), tracked_objects.end(), [](const auto& a, const auto& b) {
            return a.second.original_address < b.second.original_address;
        });

    std::vector<format::AddressLocationInfo> locations;
    const VkDeviceAddress                    min_addr = min->second.original_address;
    const VkDeviceAddress                    max_addr = max->second.original_address + max->second.size;
    uint64_t*                                start    = (uint64_t*)((uint8_t*)start_address + offset);
    uint64_t*                                end      = (uint64_t*)((uint8_t*)start_address + offset + size);
    for (int i = 0; i < size / sizeof(uint64_t); i++)
    {
        uint64_t*      ptr               = start + i;
        const uint64_t value             = *ptr;
        bool           value_is_in_range = value >= min_addr && value <= max_addr;
        if (!value_is_in_range)
        {
            continue;
        }
        auto entry = std::find_if(tracked_objects.begin(), tracked_objects.end(), [value](auto& entry) {
            return (value >= entry.second.original_address) &&
                   (value <= entry.second.original_address + entry.second.size);
        });

        if (entry == tracked_objects.end())
        {
            continue;
        }
        entry->second.adjusted_address = value;
        entry->second.offset_in_memory = (uint64_t)ptr - (uint64_t)start;
        locations.push_back(entry->second);
    }
    return locations;
}
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)