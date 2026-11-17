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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_DEVICE_CONTEXT_H
#define GFXRECON_DECODE_VULKAN_REPLAY_DEVICE_CONTEXT_H

#include "decode/vulkan_address_replacer.h"
#include "decode/vulkan_command_buffer_util.h"
#include "decode/vulkan_device_address_tracker.h"
#include "decode/vulkan_frame_warm_up.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_submit_job.h"
#include "util/defines.h"

#include <optional>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

//! Per-device state that replay builds. Each member is created on first use.
//! Members are destroyed in reverse order, so the address replacer goes first.
struct VulkanReplayDeviceContext
{
    std::optional<VulkanDeviceAddressTracker> address_tracker;
    std::optional<VulkanSubmitJobExecutor>    submit_job_executor;
    std::optional<VulkanFrameWarmUp>          frame_warm_up;
    std::optional<VulkanCommandBufferUtil>    command_buffer_util;
    std::optional<VulkanAddressReplacer>      address_replacer;
};

using VulkanPerDeviceContexts = std::unordered_map<const VulkanDeviceInfo*, VulkanReplayDeviceContext>;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_DEVICE_CONTEXT_H
