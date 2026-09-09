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
#include "util/defines.h"

#include <memory>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

// Interface between a file optimizer and the modifiers it runs.
//
// A modifier is decoded twice: once in the scan pass, where it only collects state, and once in the
// modification pass, where the optimizer hands it the parameter buffer of the block being written.
// In the modification pass a modifier may rewrite that buffer, drop the block, or queue new calls to
// be written before or after it.
class CallModifierBase
{
  public:
    virtual ~CallModifierBase() = default;

    enum NewCallDataType
    {
        kUnknownType  = 0,
        kApiCall      = 1,
        kMetaDataCall = 2
    };

    // A call queued by a modifier for the optimizer to write.
    struct NewCallData
    {
        NewCallDataType          type{ kUnknownType };
        format::ApiCallId        call_id{};
        format::ThreadId         thread_id{};
        util::MemoryOutputStream parameter_buffer;
    };

    void SetParameterBuffer(encode::ParameterBuffer* buffer) { parameter_buffer_ = buffer; }

    // Move the queued calls to the end of the optimizer's list, leaving this modifier's list empty.
    void AppendPreCalls(std::vector<std::unique_ptr<NewCallData>>& pre_calls)
    {
        pre_calls.insert(pre_calls.end(),
                         std::make_move_iterator(new_pre_calls_.begin()),
                         std::make_move_iterator(new_pre_calls_.end()));
        new_pre_calls_.clear();
    }

    // Move the queued calls to the end of the optimizer's list, leaving this modifier's list empty.
    void AppendPostCalls(std::vector<std::unique_ptr<NewCallData>>& post_calls)
    {
        post_calls.insert(post_calls.end(),
                          std::make_move_iterator(new_post_calls_.begin()),
                          std::make_move_iterator(new_post_calls_.end()));
        new_post_calls_.clear();
    }

    // Reads and clears the delete flag for the block just dispatched.
    bool TakeDeleteCurrentCall()
    {
        bool result          = delete_current_call_;
        delete_current_call_ = false;
        return result;
    }

    // Returns true if the scan pass found something for this modifier to do.
    virtual bool CanOptimize() = 0;

  protected:
    void SetDeleteCurrentCall() { delete_current_call_ = true; }

    // True while the modification pass is running; false during the scan pass.
    bool IsModificationPass() const { return parameter_buffer_ != nullptr; }

    NewCallData* CreatePreCall()
    {
        new_pre_calls_.push_back(std::make_unique<NewCallData>());
        return new_pre_calls_.back().get();
    }

    NewCallData* CreatePostCall()
    {
        new_post_calls_.push_back(std::make_unique<NewCallData>());
        return new_post_calls_.back().get();
    }

    // Parameters of the block being written, valid in the modification pass only.
    encode::ParameterBuffer* parameter_buffer_{ nullptr };

    // Set when the current block should be dropped from the output.
    bool delete_current_call_{ false };

    // Calls to write before the current block.
    std::vector<std::unique_ptr<NewCallData>> new_pre_calls_;

    // Calls to write after the current block.
    std::vector<std::unique_ptr<NewCallData>> new_post_calls_;
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CALL_MODIFIER_BASE_H
