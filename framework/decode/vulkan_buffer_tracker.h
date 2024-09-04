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

class VulkanBufferTracker
{
  public:
    explicit VulkanBufferTracker(const VulkanObjectInfoTable& object_info_table);

    //! prevent copying
    VulkanBufferTracker(const VulkanBufferTracker&) = delete;

    //! allow moving
    VulkanBufferTracker(VulkanBufferTracker&&) = default;

    ~VulkanBufferTracker() = default;

    /**
     * @brief   Track an existing buffer by its capture- and replay-time VkDeviceAddress.
     *
     * @param   buffer_info a provided buffer_info containing a buffer-handle and associated device-addresses.
     */
    void TrackBuffer(const BufferInfo* buffer_info);

    /**
     * @brief   Retrieve a buffer by providing a replay-time VkDeviceAddress within its range.
     *
     * @param   replay_address  a replay-time VkDeviceAddress pointing inside a buffer.
     * @return  a const-pointer to a found BufferInfo or nullptr.
     */
    [[nodiscard]] const BufferInfo* GetBufferByReplayDeviceAddress(VkDeviceAddress replay_address) const;

    /**
     * @brief   Retrieve a buffer by providing a capture-time VkDeviceAddress within its range.
     *
     * @param   replay_address  a capture-time VkDeviceAddress pointing inside a buffer.
     * @return  a const-pointer to a found BufferInfo or nullptr.
     */
    [[nodiscard]] const BufferInfo* GetBufferByCaptureDeviceAddress(VkDeviceAddress capture_address) const;

  private:
    //! use a sorted (BST-based) map
    using device_address_map_t = std::map<VkDeviceAddress, format::HandleId>;

    [[nodiscard]] const BufferInfo* GetBufferInfo(VkDeviceAddress             device_address,
                                                  const device_address_map_t& address_map) const;

    const VulkanObjectInfoTable& _object_info_table;
    device_address_map_t         _capture_addresses, _replay_addresses;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_BUFFER_TRACKER_H
