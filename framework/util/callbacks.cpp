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
#include "encode/capture_manager.h"
#include "util/logging.h"

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

class MarkInjectedCommands : public CallbackBase
{
  public:
    void EventA()
    {
        encode::CommonCaptureManager::SetForceDefaultUniqueId(true);
        CallbackBase::EventA();
    }

    void EventB()
    {
        encode::CommonCaptureManager::SetForceDefaultUniqueId(false);
        CallbackBase::EventB();
    }
};

static MarkInjectedCommands injected_commands_marker;

void BeginInjectedCommands()
{
    injected_commands_marker.EventA();
}

void EndInjectedCommands()
{
    injected_commands_marker.EventB();
}

extern "C" void GFXR_EXPORT SetInjectedCommandCallbacks(PFN_EventBeginCallBack begin_fp,
                                                        PFN_EventEndCallBack   end_fp,
                                                        void*                  data)
{
    injected_commands_marker.SetCallbacks(begin_fp, end_fp, data);
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
