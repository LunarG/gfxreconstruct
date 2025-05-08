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

#include "util/thread_data.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::mutex                                     ThreadData::count_lock_;
format::ThreadId                               ThreadData::thread_count_ = 0;
std::unordered_map<uint64_t, format::ThreadId> ThreadData::id_map_;

ThreadData::ThreadData() :
    thread_id_(GetThreadId()), object_id_(format::kNullHandleId), call_id_(format::ApiCallId::ApiCall_Unknown)
{
    parameter_buffer_  = std::make_unique<encode::ParameterBuffer>();
    parameter_encoder_ = std::make_unique<encode::ParameterEncoder>(parameter_buffer_.get());
}

format::ThreadId ThreadData::GetThreadId()
{
    format::ThreadId id  = 0;
    uint64_t         tid = util::platform::GetCurrentThreadId();

    // Using a uint64_t sequence number associated with the thread ID.
    std::lock_guard<std::mutex> lock(count_lock_);
    auto                        entry = id_map_.find(tid);
    if (entry != id_map_.end())
    {
        id = entry->second;
    }
    else
    {
        id = ++thread_count_;
        id_map_.insert(std::make_pair(tid, id));
    }

    return id;
}

std::string ThreadData::GetSkipReasonString(SkipReason reason)
{
    switch (reason)
    {
        case SkipReason::kNone:
            return "none";
        case SkipReason::kInvalidHandles:
            return "invalid handles";
        case SkipReason::kDispatchCall:
            return "dispatch call";
        case SkipReason::kDispatchReturn:
            return "dispatch return";
        case SkipReason::kReentryControl:
            return "reentry control";
    }
    return "INVALID REASON ENUM";
}

void ThreadData::SetSkipState(SkipReason reason)
{
#if ENABLE_OPENXR_SUPPORT
    if (skip_reason_ == SkipReason::kInvalidHandles)
        return; // invalid handles is a sticky state

    if ((reason == SkipReason::kNone) || (reason == SkipReason::kDispatchReturn))
    {
        // Dispatch return maps to none
        GFXRECON_LOG_DEBUG("WriteToFile: Removing thread 0x%x from skip list for reason: %s",
                           thread_id_,
                           GetSkipReasonString(reason).c_str());
        skip_reason_ = SkipReason::kNone;
    }
    else
    {
        // Dispatch call maps to reentry control
        GFXRECON_LOG_DEBUG("WriteToFile: Adding thread 0x%x to skip list for reason %s:",
                           thread_id_,
                           GetSkipReasonString(reason).c_str());
        skip_reason_ = (reason == SkipReason::kDispatchCall) ? SkipReason::kReentryControl : reason;
    }
#endif // ENABLE_OPENXR_SUPPORT
}

ThreadData::SkipReason ThreadData::GetSkipState() const
{
#if ENABLE_OPENXR_SUPPORT
    return skip_reason_;
#else
    return SkipReason::kNone;
#endif // ENABLE_OPENXR_SUPPORT
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
