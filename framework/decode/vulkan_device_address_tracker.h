/*
** Copyright (c) 2024 LunarG, Inc.
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef GFXRECON_DECODE_VULKAN_BUFFER_TRACKER_H
#define GFXRECON_DECODE_VULKAN_BUFFER_TRACKER_H

#include "decode/vulkan_object_info.h"
#include "vulkan_object_info_table.h"
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanDeviceAddressTracker
{
  public:
    explicit VulkanDeviceAddressTracker(const VulkanObjectInfoTable& object_info_table);

    //! prevent copying
    VulkanDeviceAddressTracker(const VulkanDeviceAddressTracker&) = delete;

    //! allow moving
    VulkanDeviceAddressTracker(VulkanDeviceAddressTracker&&) = default;

    ~VulkanDeviceAddressTracker() = default;

    /**
     * @brief   Track an existing buffer by its capture-time VkDeviceAddress.
     *
     * @param   buffer_info a provided buffer_info containing a buffer-handle and associated device-addresses.
     */
    void TrackBuffer(const VulkanBufferInfo* buffer_info);

    /**
     * @brief   RemoveBuffer will stop tracking of a currently tracked buffer.
     *
     * @param   buffer_info a provided buffer_info.
     */
    void RemoveBuffer(const VulkanBufferInfo* buffer_info);

    /**
     * @brief   Track an existing acceleration-structure by its capture-time VkDeviceAddress.
     *
     * @param   acceleration_structure_info a provided acceleration-structure containing a handle and associated
     *                                      device-addresses.
     */
    void TrackAccelerationStructure(const VulkanAccelerationStructureKHRInfo* acceleration_structure_info);

    /**
     * @brief   RemoveAccelerationStructure will stop tracking of a currently tracked acceleration-structure.
     *
     * @param   acceleration_structure_info a provided acceleration-structure-info.
     */
    void RemoveAccelerationStructure(const VulkanAccelerationStructureKHRInfo* acceleration_structure_info);

    /**
     * @brief   Retrieve a buffer by providing a capture-time VkDeviceAddress within its range.
     *
     * @param   capture_address  a capture-time VkDeviceAddress pointing inside a buffer.
     * @return  a const-pointer to a found BufferInfo or nullptr.
     */
    [[nodiscard]] const VulkanBufferInfo* GetBufferByCaptureDeviceAddress(VkDeviceAddress capture_address) const;

    /**
     * @brief   Retrieve a buffer by providing a replay-time VkDeviceAddress within its range.
     *
     * @param   replay_address  a replay-time VkDeviceAddress pointing inside a buffer.
     * @return  a const-pointer to a found BufferInfo or nullptr.
     */
    [[nodiscard]] const VulkanBufferInfo* GetBufferByReplayDeviceAddress(VkDeviceAddress replay_address) const;

    /**
     * @brief   Retrieve a buffer info-struct by providing its vulkan-handle.
     *
     * @param   handle  a capture-time VkBuffer handle.
     * @return  a const-pointer to a found BufferInfo or nullptr.
     */
    [[nodiscard]] const VulkanBufferInfo* GetBufferByHandle(VkBuffer handle) const;

    /**
     * @brief   Retrieve an acceleration-structure by providing a capture-time VkDeviceAddress.
     *
     * @param   capture_address  a capture-time VkDeviceAddress for an acceleration-structure.
     * @return  a const-pointer to a found AccelerationStructureKHRInfo or nullptr.
     */
    [[nodiscard]] const VulkanAccelerationStructureKHRInfo*
    GetAccelerationStructureByCaptureDeviceAddress(VkDeviceAddress capture_address) const;

    /**
     * @brief   Retrieve an acceleration-structure info-struct by providing its vulkan-handle.
     *
     * @param   handle  a replay-time VkAccelerationStructureKHR handle.
     * @return  a const-pointer to a found AccelerationStructureKHRInfo or nullptr.
     */
    [[nodiscard]] const VulkanAccelerationStructureKHRInfo*
    GetAccelerationStructureByHandle(VkAccelerationStructureKHR handle) const;

    /**
     * @brief   Create and return a lookup-table containing all internally stored acceleration-structure addresses.
     *
     * @return  a lookup-table for acceleration-structure addresses.
     */
    [[nodiscard]] std::unordered_map<VkDeviceAddress, VkDeviceAddress> GetAccelerationStructureDeviceAddressMap() const;

    //! aggregate to group an address and size
    struct device_address_range_t
    {
        VkDeviceAddress address = 0;
        VkDeviceSize    size    = 0;
    };

    /**
     * @brief   Return a lookup-table containing all internally stored buffer-device-addresses,
     *          mapping from capture- to replay-addresses
     *
     * @return  a lookup-table for buffer-device-addresses.
     */
    const std::unordered_map<VkDeviceAddress, device_address_range_t>& GetBufferDeviceAddressMap() const;

  private:
    //! use a sorted (BST-based) map
    using buffer_address_map_t = std::map<VkDeviceAddress, format::HandleId>;

    [[nodiscard]] const VulkanBufferInfo* GetBufferInfo(VkDeviceAddress             device_address,
                                                        const buffer_address_map_t& address_map) const;

    const VulkanObjectInfoTable&                          object_info_table_;
    buffer_address_map_t                                  buffer_capture_addresses_, buffer_replay_addresses_;
    std::unordered_map<VkDeviceAddress, format::HandleId> acceleration_structure_capture_addresses_;

    std::unordered_map<VkBuffer, format::HandleId>                   buffer_handles_;
    std::unordered_map<VkAccelerationStructureKHR, format::HandleId> acceleration_structure_handles_;

    std::unordered_map<VkDeviceAddress, device_address_range_t> address_lookup_helper_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_BUFFER_TRACKER_H
