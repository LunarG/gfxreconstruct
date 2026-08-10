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

#ifndef GFXRECON_GRAPHICS_VULKAN_INJECTED_CALLS_H
#define GFXRECON_GRAPHICS_VULKAN_INJECTED_CALLS_H

#include "generated/generated_vulkan_dispatch_table.h"
#include "util/callbacks.h"
#include "util/defines.h"

#include "vulkan/vulkan_core.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// Common prefix for every debug-utils label emitted around replay-injected commands.
constexpr const char kInjectedCommandLabelPrefix[] = "GFXR Replay: ";

// Process-wide switch for annotating injected commands with VK_EXT_debug_utils
// labels. Set once from the replay options during consumer initialization. The
// callback channel (util::SetInjectedCommandCallbacks) fires regardless of this switch.
void SetAnnotateInjectedCommands(bool enabled);

bool GetAnnotateInjectedCommands();

// Access point for Vulkan calls injected by replay, i.e. calls that have no
// corresponding block in the capture file (staging copies, swapchain blits,
// dump-resources work, SBT patching, sync objects, cleanup, ...).
//
// The device dispatch table is intentionally not exposed: the only way to call
// through it is to open a Scope, so "injected call made outside an
// injected-commands scope" is a compile error rather than a runtime assert.
class VulkanInjectedDeviceCalls
{
  public:
    // RAII scope marking a run of replay-injected Vulkan calls on the calling
    // thread. Construction/destruction of the outermost scope fires the
    // injected-commands begin/end callbacks. Scopes may nest freely.
    class Scope
    {
      public:
        Scope(const Scope&)            = delete;
        Scope& operator=(const Scope&) = delete;
        Scope(Scope&&)                 = delete;
        Scope& operator=(Scope&&)      = delete;

        const VulkanDeviceTable* operator->() const { return table_; }

        // Bridge for helpers that take the raw dispatch table as a parameter
        // and have not been migrated to this class yet. Only call helpers with
        // it while this scope is open; do not store the pointer.
        const VulkanDeviceTable* GetTable() const { return table_; }

        // Emits a single "GFXR Replay: <category>" label into command_buffer.
        // No-op when annotation is disabled or debug utils is unavailable.
        void InsertLabel(VkCommandBuffer command_buffer, const std::string& category) const;

        // Begins command_buffer and, on success, tags it with an inserted
        // "GFXR Replay: Synthesized command buffer" label so wholly
        // replay-generated command buffers are identifiable in tools.
        VkResult BeginCommandBuffer(VkCommandBuffer                 command_buffer,
                                    const VkCommandBufferBeginInfo* begin_info,
                                    const char*                     label = nullptr) const;

      private:
        friend class VulkanInjectedDeviceCalls;

        explicit Scope(const VulkanDeviceTable* table) : table_(table) {}

        util::MarkInjectedCommandsHelper mark_helper_;
        const VulkanDeviceTable*         table_;
    };

    // RAII "GFXR Replay: <category>" debug-utils label region bracketing
    // injected commands recorded into one command buffer. No-op when
    // annotation is disabled or debug utils is unavailable.
    class LabelRegion
    {
      public:
        ~LabelRegion();

        LabelRegion(const LabelRegion&)            = delete;
        LabelRegion& operator=(const LabelRegion&) = delete;
        LabelRegion(LabelRegion&&)                 = delete;
        LabelRegion& operator=(LabelRegion&&)      = delete;

      private:
        friend class VulkanInjectedDeviceCalls;

        LabelRegion(const VulkanDeviceTable* table, VkCommandBuffer command_buffer, const char* category);

        const VulkanDeviceTable* table_;
        VkCommandBuffer          command_buffer_;
        bool                     active_;
    };

    VulkanInjectedDeviceCalls() = default;

    explicit VulkanInjectedDeviceCalls(const VulkanDeviceTable* table);

    bool IsValid() const { return table_ != nullptr; }

    // Opens the injected-commands window for the calling thread and grants
    // access to the dispatch table for its duration.
    [[nodiscard]] Scope Open() const
    {
        GFXRECON_ASSERT(IsValid());
        return Scope(table_);
    }

    // Brackets injected commands recorded into command_buffer with a
    // Begin/EndDebugUtilsLabelEXT pair. Requires an open Scope; the parameter
    // is the capability witness and is otherwise unused.
    [[nodiscard]] LabelRegion Label(const Scope& scope, VkCommandBuffer command_buffer, const char* category) const;

  private:
    const VulkanDeviceTable* table_{ nullptr };
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_INJECTED_CALLS_H
