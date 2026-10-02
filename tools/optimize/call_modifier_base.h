/*
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef GFXRECON_CALL_MODIFIER_BASE_H
#define GFXRECON_CALL_MODIFIER_BASE_H

#include "encode/parameter_buffer.h"
#include "format/format.h"
#include "util/logging.h"
#include "util/memory_output_stream.h"

#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

/**
 * @brief   The edits requested for the one block a file optimizer is about to write.
 *
 * The optimizer creates one of these per block and points every modifier at it in turn, so the
 * modifiers accumulate into it in the order they run, and the optimizer reads it back once.
 */
class BlockEdit
{
  public:
    /**
     * @brief   defines a position relative to the block being written.
     */
    enum class Position
    {
        kBefore,
        kAfter
    };

    /**
     * @brief   define the type of newly added blocks.
     */
    enum class CallType
    {
        kApiCall,
        kMetaCommand
    };

    /**
     * @brief   defines a call the modifier has queued for addition (around the current block).
     */
    struct QueuedCall
    {
        CallType             kind;
        format::ApiCallId    call_id;
        format::ThreadId     thread_id;
        std::vector<uint8_t> data;
    };

    /**
     * @brief   Create a new BlockEdit.
     *
     * @param   parameters  the parameter buffer of the block being written, owned by the caller and
     *                      expected to outlive this object.
     */
    explicit BlockEdit(encode::ParameterBuffer& parameters) : parameters_(parameters) {}

    /**
     * @brief   The parameters of the block being written, empty for a meta-data block.
     * @return  a reference to the parameter buffer of the block being written.
     */
    encode::ParameterBuffer& Parameters() { return parameters_; }

    /**
     * @brief   Drop the block from the output.
     *
     * The optimizer writes an annotation in its place, so block indices stay aligned.
     */
    void DropBlock() { dropped_ = true; }

    /**
     * @brief   Queue an API call to be written around the current block.
     *
     * @param   where       whether the call is written before or after the current block.
     * @param   call_id     the API call to write.
     * @param   thread_id   the thread the call is attributed to.
     * @param   parameters  the call parameters, encoded the way the capture layer encodes them.
     */
    void AddCall(const Position                  where,
                 const format::ApiCallId         call_id,
                 const format::ThreadId          thread_id,
                 const util::MemoryOutputStream& parameters)
    {
        auto& calls = where == Position::kBefore ? pre_calls_ : post_calls_;
        calls.push_back(
            { .kind = CallType::kApiCall, .call_id = call_id, .thread_id = thread_id, .data = to_bytes(parameters) });
    }

    /**
     * @brief   Queue a meta-command to be written around the current block.
     *
     * Meta-commands are not compressed and use custom structs, so the modifier serialises the whole
     * block, header included.
     *
     * @param   where  whether the meta-command is written before or after the current block.
     * @param   block  the complete serialised meta-data block.
     */
    void AddMetaCommand(const Position where, const util::MemoryOutputStream& block)
    {
        auto& calls = where == Position::kBefore ? pre_calls_ : post_calls_;
        calls.push_back({ .kind = CallType::kMetaCommand, .call_id = {}, .thread_id = {}, .data = to_bytes(block) });
    }

    /**
     * @brief   Whether a modifier asked for the current block to be dropped.
     *
     * @return  true if the block must not be written.
     */
    bool IsBlockDropped() const { return dropped_; }

    /**
     * @brief   The calls queued for one side of the current block.
     *
     * @param   where  whether to return the calls written before or after the current block.
     * @return  the queued calls, in the order the modifiers added them.
     */
    const std::vector<QueuedCall>& Calls(const Position where) const
    {
        return where == Position::kBefore ? pre_calls_ : post_calls_;
    }

  private:
    /**
     * @brief   Copy a stream's contents out, so that a queued call owns movable storage.
     *
     * @param   stream  the stream to copy.
     * @return  the stream's bytes.
     */
    static std::vector<uint8_t> to_bytes(const util::MemoryOutputStream& stream)
    {
        return { stream.GetData(), stream.GetData() + stream.GetDataSize() };
    }

    encode::ParameterBuffer& parameters_;
    bool                     dropped_{ false };
    std::vector<QueuedCall>  pre_calls_;
    std::vector<QueuedCall>  post_calls_;
};

/**
 * @brief   A modifier that a file optimizer can run over the blocks it writes.
 *
 * A modifier is decoded twice: in the scan pass it only collects state, and in the modification pass
 * the optimizer points it at the BlockEdit for the block about to be written.
 */
class CallModifierBase
{
  public:
    virtual ~CallModifierBase() = default;

    /**
     * @brief   Whether the scan pass found something for this modifier to do.
     *
     * @return  true if this modifier should take part in the modification pass.
     */
    virtual bool CanOptimize() = 0;

    /**
     * @brief   Point this modifier at the block being dispatched.
     *
     * Set by the file optimizer for the duration of one block dispatch, and cleared again.
     *
     * @param   block_edit  the edits for the current block, or null outside a dispatch.
     */
    void SetCurrentBlockEdit(BlockEdit* block_edit) { block_edit_ = block_edit; }

  protected:
    /**
     * @brief   Whether the modification pass is dispatching a block right now.
     *
     * @return  true in the modification pass, false during the scan pass.
     */
    bool IsModificationPass() const { return block_edit_ != nullptr; }

    /**
     * @brief   The edits for the block being dispatched.
     *
     * Only valid while IsModificationPass() is true.
     *
     * @return  a reference to the current block's edits.
     */
    BlockEdit& CurrentBlockEdit()
    {
        GFXRECON_ASSERT(IsModificationPass());
        return *block_edit_;
    }

  private:
    BlockEdit* block_edit_{ nullptr };
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CALL_MODIFIER_BASE_H
