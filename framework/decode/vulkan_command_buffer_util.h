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
#ifndef GFXRECON_DECODE_VULKAN_COMMAND_BUFFER_UTIL_H
#define GFXRECON_DECODE_VULKAN_COMMAND_BUFFER_UTIL_H

#include "decode/vulkan_object_info.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// @brief Sizes the command buffer's layout map for an image, so that later SetLayout calls have somewhere to record.
///
/// Every subresource of the new map starts VK_IMAGE_LAYOUT_UNDEFINED, which marks it as untouched by this command
/// buffer. Does nothing if the map already exists.
/// @param command_buffer_info Command buffer that records the layout transitions.
/// @param image_info Image whose subresources the map is sized from.
void InitializeCommandBufferImageLayouts(VulkanCommandBufferInfo* command_buffer_info,
                                         const VulkanImageInfo*   image_info);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_COMMAND_BUFFER_UTIL_H
