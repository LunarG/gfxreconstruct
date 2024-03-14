/*
** Copyright (c) 2019-2024 LunarG, Inc.
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

#if ENABLE_OPENXR_SUPPORT

#include "encode/openxr_state_tracker.h"

#include "encode/openxr_state_info.h"
#include "encode/custom_openxr_struct_handle_wrappers.h"
#include "encode/openxr_handle_wrapper_util.h"
#include "generated/generated_openxr_struct_trackers.h"
#include "graphics/openxr_util.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

OpenXrStateTracker::OpenXrStateTracker() {}

OpenXrStateTracker::~OpenXrStateTracker() {}

void OpenXrStateTracker::DestroyState(openxr_wrappers::InstanceWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto session_entry : wrapper->child_sessions)
    {
        state_table_.RemoveWrapper(session_entry);
    }
    for (const auto action_set_etnry : wrapper->child_action_sets)
    {
        state_table_.RemoveWrapper(action_set_etnry);
    }
}

void OpenXrStateTracker::DestroyState(openxr_wrappers::SessionWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto passthrough_etnry : wrapper->child_passthroughs)
    {
        state_table_.RemoveWrapper(passthrough_etnry);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
