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

#ifndef GFXRECON_ENCODE_VULKAN_DEVICE_ADDRESS_TRACKER_H
#define GFXRECON_ENCODE_VULKAN_DEVICE_ADDRESS_TRACKER_H

#include "encode/vulkan_handle_wrappers.h"
#include <map>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanDeviceAddressTracker
{
  public:
    VulkanDeviceAddressTracker() = default;

    //! prevent copying
    VulkanDeviceAddressTracker(const VulkanDeviceAddressTracker&) = delete;

    //! allow moving
    VulkanDeviceAddressTracker(VulkanDeviceAddressTracker&&) = default;

    ~VulkanDeviceAddressTracker() = default;

    /**
     * @brief   Track an existing buffer by its VkDeviceAddress.
     *
     * @param   buffer  a provided buffer-handle
     * @param   address a device-address
     * @param   size    buffer-size in bytes
     */
    void TrackBuffer(const vulkan_wrappers::BufferWrapper* wrapper);

    /**
     * @brief   Stop tracking of a currently tracked buffer.
     *
     * @param   wrapper a provided buffer-wrapper.
     */
    void RemoveBuffer(const vulkan_wrappers::BufferWrapper* wrapper);

    /**
     * @brief   Track an existing acceleration-structure by its VkDeviceAddress.
     *
     * @param   wrapper a provided acceleration-structure wrapper containing a handle and device-address.
     */
    void TrackAccelerationStructure(const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper);

    /**
     * @brief   Stop tracking of a currently tracked acceleration-structure.
     *
     * @param   wrapper a provided acceleration-structure wrapper.
     */
    void RemoveAccelerationStructure(const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper);

    /**
     * @brief   Retrieve a buffer by providing a VkDeviceAddress within its range.
     *
     * @param   device_address  a capture-time VkDeviceAddress pointing inside a buffer.
     * @return  a found VkBuffer-handle or VK_NULL_HANDLE.
     */
    [[nodiscard]] VkBuffer GetBufferByDeviceAddress(VkDeviceAddress device_address) const;

    /**
     * @brief   Retrieve an acceleration-structure by providing a capture-time VkDeviceAddress.
     *
     * @param   device_address  a capture-time VkDeviceAddress for an acceleration-structure.
     * @return  a found AccelerationStructureKHR-handle or VK_NULL_HANDLE.
     */
    [[nodiscard]] VkAccelerationStructureKHR
    GetAccelerationStructureByDeviceAddress(VkDeviceAddress device_address) const;

  private:
    struct buffer_item_t
    {
        VkBuffer handle = VK_NULL_HANDLE;
        size_t   size   = 0;
    };
    //! use a sorted (BST-based) map to look-up ranges
    std::map<VkDeviceAddress, buffer_item_t> _buffer_addresses;

    std::unordered_map<VkDeviceAddress, VkAccelerationStructureKHR> _acceleration_structure_addresses;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_DEVICE_ADDRESS_TRACKER_H
