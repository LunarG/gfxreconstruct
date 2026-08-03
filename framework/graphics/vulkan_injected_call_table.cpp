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

#include "graphics/vulkan_injected_call_table.h"

#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

static std::atomic<bool> annotate_injected_commands{ false };
static std::unordered_map<graphics::VulkanDispatchKey, const graphics::VulkanDeviceTable*> device_table_registry_g;
static std::shared_mutex                                                                   registry_mutex_g;

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

void RegisterDeviceTable(VkDevice device, const VulkanDeviceTable* table)
{
    GFXRECON_ASSERT(device != VK_NULL_HANDLE);
    std::unique_lock<std::shared_mutex> lock(registry_mutex_g);
    device_table_registry_g[GetVulkanDispatchKey(device)] = table;
}

const VulkanDeviceTable* GetRegisteredDeviceTable(const void* handle)
{
    static const VulkanDeviceTable noop_table{};

    if (handle == nullptr)
    {
        GFXRECON_ASSERT(false && "Injected call made with a null handle");
        return &noop_table;
    }

    std::shared_lock<std::shared_mutex> lock(registry_mutex_g);

    const auto entry = device_table_registry_g.find(GetVulkanDispatchKey(handle));
    if (entry == device_table_registry_g.end())
    {
        GFXRECON_ASSERT(false && "No device dispatch table registered for injected call handle");
        return &noop_table;
    }

    return entry->second;
}

VKAPI_ATTR VkResult VKAPI_CALL ScopeCheck::vkBeginCommandBuffer(VkCommandBuffer                 commandBuffer,
                                                                const VkCommandBufferBeginInfo* pBeginInfo)
{
    GFXRECON_ASSERT(util::InsideInjectedCommands() && "vkBeginCommandBuffer called outside an InjectedCommandScope");

    const VulkanDeviceTable* table = GetRegisteredDeviceTable(commandBuffer);

    VkResult result = table->BeginCommandBuffer(commandBuffer, pBeginInfo);

    if ((result == VK_SUCCESS) && GetAnnotateInjectedCommands() &&
        (table->CmdInsertDebugUtilsLabelEXT != noop::vkCmdInsertDebugUtilsLabelEXT))
    {
        const std::string          label_name = std::string(kInjectedCommandLabelPrefix) + "Synthesized command buffer";
        const VkDebugUtilsLabelEXT label      = MakeLabel(label_name);
        table->CmdInsertDebugUtilsLabelEXT(commandBuffer, &label);
    }
    return result;
}

InjectedCommandScope::InjectedCommandScope(const VulkanDeviceTable* device_table,
                                           VkCommandBuffer          command_buffer,
                                           const char*              category) :
    device_table_(device_table),
    command_buffer_(command_buffer)
{
    label_active_ = GetAnnotateInjectedCommands() && command_buffer != VK_NULL_HANDLE && (device_table_ != nullptr) &&
                    (device_table_->CmdBeginDebugUtilsLabelEXT != noop::vkCmdBeginDebugUtilsLabelEXT) &&
                    (device_table_->CmdEndDebugUtilsLabelEXT != noop::vkCmdEndDebugUtilsLabelEXT);

    if (label_active_)
    {
        const std::string          label_name = std::string(kInjectedCommandLabelPrefix) + category;
        const VkDebugUtilsLabelEXT label      = MakeLabel(label_name);
        device_table_->CmdBeginDebugUtilsLabelEXT(command_buffer_, &label);
    }
}

InjectedCommandScope::~InjectedCommandScope()
{
    if (label_active_)
    {
        device_table_->CmdEndDebugUtilsLabelEXT(command_buffer_);
    }
}

InjectedCommandScope VulkanInjectedDeviceCallsTable::MarkScope(VkCommandBuffer command_buffer,
                                                               const char*     category) const
{
    // The scope's label calls go straight to the real table: the scope itself
    // opens the injected-commands window, and the noop-entry checks must see
    // the real entries, not the ScopeCheck_* trampolines.
    return InjectedCommandScope(GetRawTable(), command_buffer, category);
}

InjectedCommandScope VulkanInjectedDeviceCallsTable::MarkScope() const
{
    return InjectedCommandScope();
}

void VulkanInjectedDeviceCallsTable::InsertLabel(VkCommandBuffer command_buffer, const char* category) const
{
    GFXRECON_ASSERT(util::InsideInjectedCommands() &&
                    "VulkanInjectedDeviceCallsTable::InsertLabel called outside an InjectedCommandScope");

    const VulkanDeviceTable* table = GetRawTable();

    if ((command_buffer != VK_NULL_HANDLE) && GetAnnotateInjectedCommands() &&
        (table->CmdInsertDebugUtilsLabelEXT != noop::vkCmdInsertDebugUtilsLabelEXT))
    {
        const std::string          label_name = std::string(kInjectedCommandLabelPrefix) + category;
        const VkDebugUtilsLabelEXT label      = MakeLabel(label_name);
        table->CmdInsertDebugUtilsLabelEXT(command_buffer, &label);
    }
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
