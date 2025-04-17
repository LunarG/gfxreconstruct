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

#ifndef GFXRECON_ENCODE_OPENXR_STATE_TRACKER_INITIALIZERS_H
#define GFXRECON_ENCODE_OPENXR_STATE_TRACKER_INITIALIZERS_H

#if ENABLE_OPENXR_SUPPORT

#include "encode/openxr_handle_wrapper_util.h"
#include "encode/openxr_handle_wrappers.h"
#include "generated/generated_openxr_state_table.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/defines.h"
#include "util/logging.h"
#include "util/memory_output_stream.h"

#include "openxr/openxr.h"

#include <cassert>
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(openxr_state_tracker)

// Functions to initialize the object creation data stored by Vulkan handle wrappers. Explicit specialization is used to
// support special cases that require tracking the creation parameters of the wrapped handle and other handles that
// creation depend on (eg. graphics pipeline creation depends on a VkShaderModule, VkPipelineLayout, and VkRenderPass
// handles). These functions are only intended to be used by the VulkanStateTracker class, but must be in namespace
// scope to meet C++ language requirements for explicit template specialization.

// Utility functions for indexing arrays of "create info" structures, with a specialization for the 'void'
// type, which is used with handles that do not have a "create info" structure.
template <typename CreateInfo>
const CreateInfo* GetCreateInfoEntry(uint32_t index, const CreateInfo* create_infos)
{
    return &create_infos[index];
}

template <>
inline const void* GetCreateInfoEntry<void>(uint32_t, const void*)
{
    return nullptr;
}

template <typename ParentHandle, typename Wrapper, typename CreateInfo>
void InitializeState(ParentHandle                        parent_handle,
                     Wrapper*                            wrapper,
                     const CreateInfo*                   create_info,
                     format::ApiCallId                   create_call_id,
                     openxr_state_info::CreateParameters create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);
    GFXRECON_UNREFERENCED_PARAMETER(create_info);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);
}

template <typename ParentHandle, typename SecondaryHandle, typename Wrapper, typename CreateInfo>
void InitializeGroupObjectState(ParentHandle                        parent_handle,
                                SecondaryHandle                     secondary_handle,
                                Wrapper*                            wrapper,
                                const CreateInfo*                   create_info,
                                format::ApiCallId                   create_call_id,
                                openxr_state_info::CreateParameters create_parameters)
{
    // The secondary handle is only used by sepcializations.
    GFXRECON_UNREFERENCED_PARAMETER(secondary_handle);
    InitializeState<ParentHandle, Wrapper, CreateInfo>(
        parent_handle, wrapper, create_info, create_call_id, create_parameters);
}

template <>
inline void InitializeState<XrSession, openxr_wrappers::InstanceWrapper, XrSessionCreateInfo>(
    XrSession                           parent_handle,
    openxr_wrappers::InstanceWrapper*   wrapper,
    const XrSessionCreateInfo*          create_info,
    format::ApiCallId                   create_call_id,
    openxr_state_info::CreateParameters create_parameters)
{
    assert(parent_handle != VK_NULL_HANDLE);
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(create_info);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);
}

GFXRECON_END_NAMESPACE(openxr_state_tracker)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_ENCODE_OPENXR_STATE_TRACKER_INITIALIZERS_H
