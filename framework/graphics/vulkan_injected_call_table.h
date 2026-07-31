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

#ifndef GFXRECON_GRAPHICS_VULKAN_INJECTED_CALL_TABLE_H
#define GFXRECON_GRAPHICS_VULKAN_INJECTED_CALL_TABLE_H

#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_injected_call_table.h"
#include "util/callbacks.h"
#include "util/defines.h"
#include "util/logging.h"
#include "vulkan/vulkan_core.h"

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// Common prefix for every debug-utils label emitted around replay-injected commands.
constexpr const char kInjectedCommandLabelPrefix[] = "GFXR Replay: ";

// Process-wide switch for annotating injected commands with VK_EXT_debug_utils
// labels. Set once from the replay options during consumer initialization. The
// callback channel (util::SetInjectedCommandCallbacks) fires regardless of this switch.
void SetAnnotateInjectedCommands(bool enabled);

bool GetAnnotateInjectedCommands();

// Records the real dispatch table for `device` in the registry that the
// generated ScopeCheck trampolines and GetRegisteredDeviceTable() forward
// through. Entries are never removed; re-registering a reused dispatch key
// overwrites.
void RegisterDeviceTable(VkDevice device, const VulkanDeviceTable* table);

// RAII scope marking a run of replay-injected Vulkan calls on the calling thread.
class InjectedCommandScope
{
  public:
    InjectedCommandScope() : device_table_(nullptr), command_buffer_(VK_NULL_HANDLE), label_active_(false) {}

    InjectedCommandScope(const VulkanDeviceTable* device_table, VkCommandBuffer command_buffer, const char* category);

    ~InjectedCommandScope();

    InjectedCommandScope(const InjectedCommandScope&)            = delete;
    InjectedCommandScope& operator=(const InjectedCommandScope&) = delete;
    InjectedCommandScope(InjectedCommandScope&&)                 = delete;
    InjectedCommandScope& operator=(InjectedCommandScope&&)      = delete;

  private:
    util::MarkInjectedCommandsHelper mark_helper_;
    const VulkanDeviceTable*         device_table_;
    VkCommandBuffer                  command_buffer_;
    bool                             label_active_;
};

// Dispatch-table handle for Vulkan calls injected by replay, i.e. calls that
// have no corresponding block in the capture file (staging copies, swapchain
// blits, dump-resources work, SBT patching, sync objects, cleanup, ...).
class VulkanInjectedCallTable : public VulkanInjectedCallTableBase
{
  public:
    VulkanInjectedCallTable() = delete;

    VulkanInjectedCallTable(VkDevice device, const VulkanDeviceTable* raw_table) : raw_table_(raw_table)
    {
        RegisterDeviceTable(device, raw_table);
    }

    const VulkanDeviceTable* GetRawTable() const { return raw_table_; }

    [[nodiscard]] InjectedCommandScope MarkScope(VkCommandBuffer command_buffer, const char* category) const;

    [[nodiscard]] InjectedCommandScope MarkScope() const;

    void InsertLabel(VkCommandBuffer command_buffer, const char* category) const;

  private:
    const VulkanDeviceTable* raw_table_;
};

using DeviceInjectedDispatchTablesMap = std::unordered_map<graphics::VulkanDispatchKey, VulkanInjectedCallTable>;

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_INJECTED_CALL_TABLE_H
