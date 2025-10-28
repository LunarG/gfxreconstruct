/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_THREAD_DATA_H
#define GFXRECON_UTIL_THREAD_DATA_H

#include "encode/handle_unwrap_memory.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "format/format.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class ThreadData
{
  public:
    ThreadData();

    std::vector<uint8_t>& GetScratchBuffer() { return scratch_buffer_; }

#if ENABLE_OPENXR_SUPPORT
    void EnableSkipCurrentThreadInFuture()
    {
        // If not already in the list, add this thread ID to the list of IDs we
        // will skip content for.
        if (skip_threads_.find(thread_id_) == skip_threads_.end())
        {
            GFXRECON_LOG_INFO("WriteToFile: Adding thread 0x%x to skip list", thread_id_);
            skip_threads_.insert(thread_id_);
        }
    }

    bool SkipCurrentThread() const
    {
        if (skip_threads_.find(thread_id_) != skip_threads_.end())
        {
            return true;
        }
        return false;
    }
#endif

    const format::ThreadId                    thread_id_;
    format::ApiCallId                         call_id_;
    format::HandleId                          object_id_;
    std::unique_ptr<encode::ParameterBuffer>  parameter_buffer_;
    std::unique_ptr<encode::ParameterEncoder> parameter_encoder_;
    std::vector<uint8_t>                      compressed_buffer_;
    encode::HandleUnwrapMemory                handle_unwrap_memory_;

  private:
    static format::ThreadId GetThreadId();

    static std::mutex                                     count_lock_;
    static format::ThreadId                               thread_count_;
    static std::unordered_map<uint64_t, format::ThreadId> id_map_;

    // Used for combining multiple buffers for a single file write.
    std::vector<uint8_t> scratch_buffer_;

#if ENABLE_OPENXR_SUPPORT
    // Used to skip threads we have determined have bad data
    std::set<format::ThreadId> skip_threads_;
#endif
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_THREAD_DATA_H
