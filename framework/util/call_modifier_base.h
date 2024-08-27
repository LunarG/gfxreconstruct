/*
** Copyright (c) 2024 LunarG, Inc.
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef GFXRECON_UTIL_CALL_MODIFIER_BASE_H
#define GFXRECON_UTIL_CALL_MODIFIER_BASE_H

#include "util/defines.h"
#include "format/format.h"
#include "encode/parameter_buffer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Facilitates communication between file optimizer and modificators
// Provides access to buffers and information on types of modification
class CallModifierBase
{
  public:
    struct NewCallData
    {
        format::ApiCallId        call_id;
        format::ThreadId         thread_id;
        util::MemoryOutputStream parameter_buffer;
    };

    virtual void SetParameterBuffer(encode::ParameterBuffer* buffer) { parameter_buffer_ = buffer; }

    // Move new call data to the end of input vector
    // The source data becomes invalid and its container is cleared
    virtual void AppendPreCalls(std::vector<std::unique_ptr<NewCallData>>& pre_calls)
    {
        pre_calls.insert(pre_calls.end(),
                         std::make_move_iterator(new_pre_calls_.begin()),
                         std::make_move_iterator(new_pre_calls_.end()));
        new_pre_calls_.clear();
    }

    // Move new call data to the end of input vector
    // The source data becomes invalid and its container is cleared
    virtual void AppendPostCalls(std::vector<std::unique_ptr<NewCallData>>& post_calls)
    {
        post_calls.insert(post_calls.end(),
                          std::make_move_iterator(new_post_calls_.begin()),
                          std::make_move_iterator(new_post_calls_.end()));
        new_post_calls_.clear();
    }

    virtual bool GetDeleteCurrentCall()
    {
        bool result = delete_current_call;
        // reset the delete flag
        delete_current_call = false;
        return result;
    }

    virtual bool CanOptimize() = 0;

  protected:
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

    // Points to parameter buffer that can be modified
    encode::ParameterBuffer* parameter_buffer_ = nullptr;

    // Set if current call is meant to be removed from the trace
    bool delete_current_call = false;

    // Vector of new calls to add before currently processed call
    std::vector<std::unique_ptr<NewCallData>> new_pre_calls_;

    // Vector of new calls to add before currently processed call
    std::vector<std::unique_ptr<NewCallData>> new_post_calls_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_CALL_MODIFIER_BASE_H
