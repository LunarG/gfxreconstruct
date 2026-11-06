/*
** Copyright (c) 2024 - 2025 Valve Corporation
** Copyright (c) 2024 - 2025 LunarG, Inc.
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

#include "callbacks.h"
#include "util/logging.h"

#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class CallbackBase
{
  public:
    CallbackBase() :
        event_a_fp_(NoopCallback), event_b_fp_(NoopCallback), event_a_in_progress_(false), context_(nullptr)
    {}

    void SetCallbacks(PFN_EventBeginCallBack event_a_fp, PFN_EventEndCallBack event_b_fp, void* context)
    {
        event_a_fp_ = event_a_fp != nullptr ? event_a_fp : NoopCallback;
        event_b_fp_ = event_b_fp != nullptr ? event_b_fp : NoopCallback;
        context_    = context;
    }

    void EventA()
    {
#ifdef GFXRECON_DEBUG_BUILD
        // Event A is called twice
        GFXRECON_ASSERT(!event_a_in_progress_);
        event_a_in_progress_ = true;
#endif

        event_a_fp_(context_);
    }

    // Callbacks set while an event is in progress missed its EventA.  This gives them one, so that the EventB
    // that ends the event pairs with it.
    void EventAForNewCallbacks()
    {
#ifdef GFXRECON_DEBUG_BUILD
        event_a_in_progress_ = true;
#endif

        event_a_fp_(context_);
    }

    // Ends an event without the EventB, for callbacks that did not get its EventA.
    void SkipEventB()
    {
#ifdef GFXRECON_DEBUG_BUILD
        event_a_in_progress_ = false;
#endif
    }

    void EventB()
    {
#ifdef GFXRECON_DEBUG_BUILD
        // Event B is called twice
        GFXRECON_ASSERT(event_a_in_progress_);
        event_a_in_progress_ = false;
#endif

        event_b_fp_(context_);
    }

  private:
    static void NoopCallback(void* context)
    {
        GFXRECON_UNREFERENCED_PARAMETER(context);
    }

    PFN_EventBeginCallBack event_a_fp_;
    PFN_EventEndCallBack   event_b_fp_;
    void*                  context_;
    bool                   event_a_in_progress_;
};

static CallbackBase injected_commands_marker;

// Per-thread nesting depth. Gates GetUniqueId() against the thread_local
// unique_id_stack_, so it must not be shared across threads.
static thread_local uint32_t thread_scope_depth = 0;

// Counts threads with an open scope. The mutex also serializes
// EventA/EventB so they strictly alternate process-wide.
static std::mutex scope_transition_mutex;
static uint32_t   global_scope_count = 0;

// Set when callbacks are set while another thread has the open scope.  They did not get its EventA, thus they do
// not get its EventB either.
static bool skip_event_b_for_new_callbacks = false;

MarkInjectedCommandsHelper::MarkInjectedCommandsHelper()
{
    if (thread_scope_depth++ == 0)
    {
        // mark injected commands
        std::lock_guard<std::mutex> lock(scope_transition_mutex);
        if (global_scope_count++ == 0)
        {
            injected_commands_marker.EventA();
        }
    }
}

MarkInjectedCommandsHelper::~MarkInjectedCommandsHelper()
{
    GFXRECON_ASSERT(thread_scope_depth);
    if (--thread_scope_depth == 0)
    {
        // mark end of injected commands
        std::lock_guard<std::mutex> lock(scope_transition_mutex);
        if (--global_scope_count == 0)
        {
            if (skip_event_b_for_new_callbacks)
            {
                skip_event_b_for_new_callbacks = false;
                injected_commands_marker.SkipEventB();
            }
            else
            {
                injected_commands_marker.EventB();
            }
        }
    }
}

bool InjectedCommandsActive()
{
    return thread_scope_depth != 0;
}

extern "C" void GFXR_EXPORT SetInjectedCommandCallbacks(PFN_EventBeginCallBack begin_fp,
                                                        PFN_EventEndCallBack   end_fp,
                                                        void*                  data)
{
    // A tool can register while a scope is open.  When the calling thread is in the scope, as a driver that the
    // loader loads inside one is, the tool gets the begin callback now, on that thread.  When only another thread
    // is, the tool gets no callback for that scope, because the begin callback names the thread of the scope.
    std::lock_guard<std::mutex> lock(scope_transition_mutex);
    injected_commands_marker.SetCallbacks(begin_fp, end_fp, data);
    skip_event_b_for_new_callbacks = false;
    if (global_scope_count != 0)
    {
        if (thread_scope_depth != 0)
        {
            injected_commands_marker.EventAForNewCallbacks();
        }
        else
        {
            skip_event_b_for_new_callbacks = true;
        }
    }
}

class TrimmingStateMarker : public CallbackBase
{};

static TrimmingStateMarker trimming_state_marker;

void SignalTrimmingStart()
{
    trimming_state_marker.EventA();
}

void SignalTrimmingEnd()
{
    trimming_state_marker.EventB();
}

extern "C" void GFXR_EXPORT SetSignalTrimmingCallbacks(PFN_EventBeginCallBack begin_fp,
                                                       PFN_EventEndCallBack   end_fp,
                                                       void*                  data)
{
    trimming_state_marker.SetCallbacks(begin_fp, end_fp, data);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
