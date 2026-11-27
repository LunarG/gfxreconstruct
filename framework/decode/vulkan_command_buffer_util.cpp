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
#include "decode/vulkan_command_buffer_util.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void InitializeCommandBufferImageLayouts(VulkanCommandBufferInfo* command_buffer_info,
                                         const VulkanImageInfo*   image_info)
{
    GFXRECON_ASSERT(command_buffer_info != nullptr);
    GFXRECON_ASSERT(image_info != nullptr);

    graphics::ImageLayoutMap& command_buffer_layouts =
        command_buffer_info->image_layout_barriers[image_info->capture_id];
    if (command_buffer_layouts.IsInitialized())
    {
        return;
    }

    const graphics::ImageLayoutMap& image_layouts = image_info->subresource_layouts;
    command_buffer_layouts.Initialize(
        image_layouts.GetMipLevels(), image_layouts.GetArrayLayers(), image_layouts.GetAspects());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
