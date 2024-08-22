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
#include "graphics/vulkan_resources_util.h"
#include "decode/vulkan_buffer_tracker.h"
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanBufferTracker::VulkanBufferTracker(const encode::VulkanDeviceTable* device_table,
                                         const PhysicalDeviceInfo*        physical_device_info,
                                         VkDevice                         device,
                                         VulkanResourceAllocator*         allocator) :
    physical_device_info_(physical_device_info),
    device_(device), allocator_(allocator)
{
    InitializeFunctionPointers(device_table);
}

VulkanBufferTracker::~VulkanBufferTracker()
{
    buffers_.clear();
}

void VulkanBufferTracker::SetBufferInfo(BufferInfo* buffer_info)
{
    auto existing_buffer = std::find_if(buffers_.begin(), buffers_.end(), [&](const BufferInfo* entry) {
        return entry->handle == buffer_info->handle;
    });

    // Handle reuse, update the data in the entry
    if (existing_buffer != buffers_.end())
    {
        *existing_buffer = buffer_info;
    }
    else
    {
        buffers_.push_back(buffer_info);
    }
}

void VulkanBufferTracker::OnDestroyBuffer(const BufferInfo* buffer_info)
{
    // On buffer destruction, we want to stop tracking them
    buffers_.erase(std::remove_if(buffers_.begin(),
                                  buffers_.end(),
                                  [&buffer_info](const BufferInfo* entry) {
                                      return entry->capture_id == buffer_info->capture_id;
                                  }),
                   buffers_.end());
}

// TODO: this is exactly the same method as in VulkanInternalBufferManager. Try to remove this duplication
VkDeviceAddress VulkanBufferTracker::GetBufferDeviceAddress(VkBuffer buffer)
{
    VkBufferDeviceAddressInfo info;
    info.sType  = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
    info.pNext  = nullptr;
    info.buffer = buffer;

    VkDeviceAddress result = 0;

    assert(functions_.get_buffer_device_address != gfxrecon::encode::noop::GetBufferDeviceAddress);

    result = functions_.get_buffer_device_address(device_, &info);

    return result;
}

void VulkanBufferTracker::UpdateBufferDeviceAddress(VkDeviceAddress& address)
{
    if (address == 0)
        return;

    VkDeviceSize offset = 0;
    auto         buffer = std::find_if(buffers_.begin(), buffers_.end(), [&](const BufferInfo* entry) {
        // TODO: allocator_->GetBufferSize(entry->allocator_data) and entry->size should have the same data. This is not
        // true on FF. Investigate why and remove the allocator_ call.
        size_t buffer_size = allocator_->GetBufferSize(entry->allocator_data);
        if (entry->capture_address == address)
        {
            return true;
        }
        else if (entry->capture_address <= address && (entry->capture_address + buffer_size) > address)
        {
            return true;
        }
        return false;
    });
    GFXRECON_ASSERT(buffer != buffers_.end());
    offset  = address - (*buffer)->capture_address;
    address = (*buffer)->replay_address + offset;
}

BufferInfo* VulkanBufferTracker::GetBufferByReplayDeviceAddress(VkDeviceAddress replay_address)
{
    // Try to find buffer by runtime device address
    auto buffer = std::find_if(buffers_.begin(), buffers_.end(), [&](const BufferInfo* entry) {
        size_t buffer_size = allocator_->GetBufferSize(entry->allocator_data);
        if (entry->replay_address == replay_address)
        {
            return true;
        }
        else if (entry->replay_address <= replay_address && (entry->replay_address + buffer_size) > replay_address)
        {
            return true;
        }
        return false;
    });
    GFXRECON_ASSERT(buffer != buffers_.end());
    return *buffer;
}

BufferInfo* VulkanBufferTracker::GetBufferByCaptureDeviceAddress(VkDeviceAddress capture_address)
{
    auto buffer = std::find_if(buffers_.begin(), buffers_.end(), [&](const BufferInfo* entry) {
        size_t buffer_size = allocator_->GetBufferSize(entry->allocator_data);
        if (entry->capture_address == capture_address)
        {
            return true;
        }
        else if (entry->capture_address <= capture_address && (entry->capture_address + buffer_size) > capture_address)
        {
            return true;
        }
        return false;
    });
    if (buffer != buffers_.end())
    {
        return *buffer;
    }
    else
    {
        GFXRECON_LOG_DEBUG("Could not find a buffer with specified capture time device address");
        return nullptr;
    }
}

void VulkanBufferTracker::InitializeFunctionPointers(const encode::VulkanDeviceTable* device_table)
{
    functions_.get_buffer_device_address =
        (device_table->GetBufferDeviceAddress != gfxrecon::encode::noop::GetBufferDeviceAddress)
            ? device_table->GetBufferDeviceAddress
            : device_table->GetBufferDeviceAddressKHR;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)