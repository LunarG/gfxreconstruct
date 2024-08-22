#pragma once
#include "vulkan/vulkan.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "format/format.h"
#include <unordered_map>
#include <vector>
#include <shared_mutex>
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanDeviceAddressTracker
{
  public:
    std::shared_mutex mx{};
    void              lock() { mx.lock(); }
    void              unlock() { mx.unlock(); }

    // Handle to its location
    std::unordered_map<format::HandleId, format::AddressLocationInfo> tracked_objects;

    void TrackBufferDeviceAddress(format::HandleId buffer_id, uint64_t buffer_size, VkDeviceAddress address);
    void TrackAccelerationStructureDeviceAddress(format::HandleId id, VkDeviceAddress address);
    std::vector<format::AddressLocationInfo> GetAddressesInMemoryRange(const std::vector<uint64_t>& ignored_usages,
                                                                       const vulkan_wrappers::DeviceMemoryWrapper*   memory,
                                                                       const void*                  start_address,
                                                                       size_t                       offset,
                                                                       size_t                       size);
};
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)