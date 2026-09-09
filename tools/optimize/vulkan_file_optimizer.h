/*
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
** Copyright (c) 2020-2026 LunarG, Inc.
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

#ifndef GFXRECON_VULKAN_FILE_OPTIMIZER_H
#define GFXRECON_VULKAN_FILE_OPTIMIZER_H

#include "file_optimizer.h"

#include "encode/parameter_buffer.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/defines.h"
#include "util/heap_buffer.h"
#include "vulkan_modifier_base.h"

#include <memory>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

// A FileOptimizer that additionally runs a list of Vulkan modifiers over every block it writes.
//
// Each modifier is decoded twice. The scan pass, driven by the caller through a FileProcessor,
// lets it collect state. This class drives the modification pass: it decodes the block again, hands
// each modifier the block's parameter buffer, and then writes the pre-calls the modifiers queued,
// the block itself unless a modifier dropped it, and the post-calls.
//
// With an empty modifier list this behaves exactly like FileOptimizer, and the output is byte
// identical. A block no modifier rewrote is also passed through verbatim rather than re-encoded.
class VulkanFileOptimizer : public FileOptimizer
{
  public:
    using Modifiers = std::vector<std::unique_ptr<VulkanModifierBase>>;

    VulkanFileOptimizer(const std::unordered_set<format::HandleId>& unreferenced_ids,
                        const std::unordered_set<uint64_t>&         unreferenced_blocks,
                        Modifiers                                   modifiers);

  protected:
    bool ProcessFunctionCall(decode::ParsedBlock& parsed_block) override;
    bool ProcessMetaData(decode::ParsedBlock& parsed_block) override;

  private:
    // Runs every modifier over one decoded block, then writes the result. Defined in the .cpp,
    // which is the only user.
    template <typename Args>
    bool ModifierDispatch(const Args& args, decode::ParsedBlock& parsed_block, encode::ParameterBuffer& buffer);

    bool WriteNewCalls(const std::vector<std::unique_ptr<CallModifierBase::NewCallData>>& new_calls);
    bool WriteFunctionCall(format::ApiCallId               call_id,
                           format::ThreadId                thread_id,
                           const util::MemoryOutputStream& parameter_buffer);

    Modifiers             modifiers_;
    decode::VulkanDecoder decoder_;

    constexpr static size_t kWorkingStoreInitialSize = 4096;
    util::HeapBuffer        working_uncompressed_store_;
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_VULKAN_FILE_OPTIMIZER_H
