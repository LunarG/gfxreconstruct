/*
 ** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_CAPTURE_COMMON_H
#define GFXRECON_ENCODE_VULKAN_CAPTURE_COMMON_H

#include "encode/parameter_encoder.h"
#include "vulkan/vulkan.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "vulkan_capture_manager.h"
#include "vulkan_state_writer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void CommonWriteCreateHardwareBufferCmd(format::ThreadId                                    thread_id,
                                        format::HandleId                                    memory_id,
                                        AHardwareBuffer*                                    hardware_buffer,
                                        const std::vector<format::HardwareBufferPlaneInfo>& plane_info,
                                        VulkanCaptureManager*                               vulkan_capture_manager,
                                        VulkanStateWriter*                                  vulkan_state_writer);

void CommonProcessHardwareBuffer(format::ThreadId      thread_id,
                                 format::HandleId      memory_id,
                                 AHardwareBuffer*      hardware_buffer,
                                 size_t                allocation_size,
                                 VulkanCaptureManager* vulkan_capture_manager,
                                 VulkanStateWriter*    vulkan_state_writer);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_CAPTURE_COMMON_H
