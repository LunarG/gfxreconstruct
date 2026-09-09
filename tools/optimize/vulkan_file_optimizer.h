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

/**
 * @brief   A FileOptimizer that additionally runs a list of Vulkan modifiers over every block it writes.
 *
 * Each modifier is decoded twice. The scan pass collects state.
 *
 * This class performs the modification pass:
 * - decodes the block again, points each modifier at the block's BlockEdit
 * - writes the queued calls before/after the block and the block itself (unless a modifier dropped it)
 *
 * With empty modifier-list the behavior matches FileOptimizer.
 * Blocks no modifier rewrote are passed through verbatim, rather than re-encoded.
 */
class VulkanFileOptimizer : public FileOptimizer
{
  public:
    using Modifiers = std::vector<std::unique_ptr<VulkanModifierBase>>;

    /**
     * @brief   Create an optimizer for one input file.
     *
     * @param   unreferenced_ids     handles never referenced by a command buffer submission, whose
     *                               initialization data is dropped.
     * @param   unreferenced_blocks  block indices belonging to those handles, dropped as a whole.
     * @param   modifiers            the modifiers to run, in the order they should run.
     */
    VulkanFileOptimizer(const std::unordered_set<format::HandleId>& unreferenced_ids,
                        const std::unordered_set<uint64_t>&         unreferenced_blocks,
                        Modifiers                                   modifiers);

  protected:
    /**
     * @brief   Run the modifiers over a function-call block, write the result.
     *
     * @param   parsed_block  the block read from the input file.
     * @return  false if writing failed.
     */
    bool ProcessFunctionCall(decode::ParsedBlock& parsed_block) override;

    /**
     * @brief   Run the modifiers over a meta-data block and write the result.
     *
     * @param   parsed_block  the block read from the input file.
     * @return  false if writing failed.
     */
    bool ProcessMetaData(decode::ParsedBlock& parsed_block) override;

  private:
    /**
     * @brief   Run every modifier over one decoded block, then write the result.
     *
     * @param   args          the decoded arguments of the block.
     * @param   parsed_block  the block as read, used to copy its bytes through unchanged.
     * @param   buffer        the block's parameters, which a modifier may rewrite.
     * @return  false if writing failed.
     */
    template <typename Args>
    bool ModifierDispatch(const Args& args, decode::ParsedBlock& parsed_block, encode::ParameterBuffer& buffer);

    /**
     * @brief   Write calls queued by modifiers for the current block.
     *
     * @param   calls  the queued calls, written in order.
     * @return  false if writing failed.
     */
    bool WriteQueuedCalls(const std::vector<BlockEdit::QueuedCall>& calls);

    /**
     * @brief   Write one function-call block, compressing it if the output file is compressed.
     *
     * @param   call_id    the API call to write.
     * @param   thread_id  the thread the call is attributed to.
     * @param   data       the encoded call parameters.
     * @param   size       the number of parameter bytes.
     * @return  false if writing failed.
     */
    bool WriteFunctionCall(format::ApiCallId call_id, format::ThreadId thread_id, const uint8_t* data, size_t size);

    Modifiers             modifiers_;
    decode::VulkanDecoder decoder_;

    constexpr static size_t kWorkingStoreInitialSize = 4096;
    util::HeapBuffer        working_uncompressed_store_;
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_VULKAN_FILE_OPTIMIZER_H
