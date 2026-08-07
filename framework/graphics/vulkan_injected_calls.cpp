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

#include "graphics/vulkan_injected_calls.h"

#include "util/logging.h"

#include <atomic>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

static std::atomic<bool> annotate_injected_commands{ false };

void SetAnnotateInjectedCommands(bool enabled)
{
    annotate_injected_commands = enabled;
}

bool GetAnnotateInjectedCommands()
{
    return annotate_injected_commands;
}

static VkDebugUtilsLabelEXT MakeLabel(const std::string& label_name)
{
    VkDebugUtilsLabelEXT label = {};
    label.sType                = VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT;
    label.pLabelName           = label_name.c_str();
    return label;
}

VulkanInjectedDeviceCalls::VulkanInjectedDeviceCalls(const VulkanDeviceTable* table) : table_(table)
{
    GFXRECON_ASSERT(table_ != nullptr);
}

void VulkanInjectedDeviceCalls::Scope::InsertLabel(VkCommandBuffer command_buffer, const char* category) const
{
    if ((command_buffer != VK_NULL_HANDLE) && GetAnnotateInjectedCommands() &&
        (table_->CmdInsertDebugUtilsLabelEXT != noop::vkCmdInsertDebugUtilsLabelEXT))
    {
        const std::string          label_name = std::string(kInjectedCommandLabelPrefix) + category;
        const VkDebugUtilsLabelEXT label      = MakeLabel(label_name);
        table_->CmdInsertDebugUtilsLabelEXT(command_buffer, &label);
    }
}

VkResult VulkanInjectedDeviceCalls::Scope::BeginCommandBuffer(VkCommandBuffer                 command_buffer,
                                                              const VkCommandBufferBeginInfo* begin_info) const
{
    VkResult result = table_->BeginCommandBuffer(command_buffer, begin_info);

    if (result == VK_SUCCESS)
    {
        InsertLabel(command_buffer, "Synthesized command buffer");
    }
    return result;
}

VulkanInjectedDeviceCalls::LabelRegion::LabelRegion(const VulkanDeviceTable* table,
                                                    VkCommandBuffer          command_buffer,
                                                    const char*              category) :
    table_(table),
    command_buffer_(command_buffer)
{
    active_ = GetAnnotateInjectedCommands() && (command_buffer_ != VK_NULL_HANDLE) &&
              (table_->CmdBeginDebugUtilsLabelEXT != noop::vkCmdBeginDebugUtilsLabelEXT) &&
              (table_->CmdEndDebugUtilsLabelEXT != noop::vkCmdEndDebugUtilsLabelEXT);

    if (active_)
    {
        const std::string          label_name = std::string(kInjectedCommandLabelPrefix) + category;
        const VkDebugUtilsLabelEXT label      = MakeLabel(label_name);
        table_->CmdBeginDebugUtilsLabelEXT(command_buffer_, &label);
    }
}

VulkanInjectedDeviceCalls::LabelRegion::~LabelRegion()
{
    if (active_)
    {
        table_->CmdEndDebugUtilsLabelEXT(command_buffer_);
    }
}

VulkanInjectedDeviceCalls::LabelRegion
VulkanInjectedDeviceCalls::Label(const Scope& scope, VkCommandBuffer command_buffer, const char* category) const
{
    GFXRECON_UNREFERENCED_PARAMETER(scope);
    return LabelRegion(table_, command_buffer, category);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
