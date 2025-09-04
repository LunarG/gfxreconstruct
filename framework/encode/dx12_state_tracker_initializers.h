/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_DX12_STATE_TRACKER_INITIALIZERS_H
#define GFXRECON_ENCODE_DX12_STATE_TRACKER_INITIALIZERS_H

#include "encode/iunknown_wrapper.h"
#include "format/format.h"
#include "util/defines.h"
#include "util/memory_output_stream.h"
#include "util/logging.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(dx12_state_tracker)

// InitializeState for Method calls.
template <typename Wrapper, typename ParentWrapper>
typename std::enable_if<!std::is_same<ParentWrapper, IUnknown_Wrapper>::value>::type
InitializeState(Wrapper*                        wrapper,
                format::ApiCallId               create_call_id,
                ParentWrapper*                  create_object_wrapper,
                const util::MemoryOutputStream* create_parameters)
{
    assert(wrapper != nullptr);
    assert(wrapper->GetObjectInfo() != nullptr);
    assert(create_parameters != nullptr);
    assert(create_object_wrapper != nullptr);
    assert(create_object_wrapper->GetCaptureId() != format::kNullHandleId);
    assert(create_object_wrapper->GetObjectInfo() != nullptr);

    auto wrapper_info = wrapper->GetObjectInfo();

    wrapper_info->create_call_id = create_call_id;
    wrapper_info->create_parameters =
        std::make_unique<util::MemoryOutputStream>(create_parameters->GetData(), create_parameters->GetDataSize());

    wrapper_info->create_object_id   = create_object_wrapper->GetCaptureId();
    wrapper_info->create_object_info = create_object_wrapper->GetObjectInfo();
}

// Specialization for method calls where the creating object's wrapper does not have GetObjectInfo(), e.g.,
// IUnknown::QueryInterface()
template <typename Wrapper, typename ParentWrapper>
typename std::enable_if<std::is_same<ParentWrapper, IUnknown_Wrapper>::value>::type
InitializeState(Wrapper*                        wrapper,
                format::ApiCallId               create_call_id,
                ParentWrapper*                  create_object_wrapper,
                const util::MemoryOutputStream* create_parameters)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    GFXRECON_ASSERT(wrapper->GetObjectInfo() != nullptr);
    GFXRECON_ASSERT(create_parameters != nullptr);
    GFXRECON_ASSERT(create_object_wrapper != nullptr);
    GFXRECON_ASSERT(create_object_wrapper->GetCaptureId() != format::kNullHandleId);

    auto wrapper_info = wrapper->GetObjectInfo();

    wrapper_info->create_call_id = create_call_id;
    wrapper_info->create_parameters =
        std::make_unique<util::MemoryOutputStream>(create_parameters->GetData(), create_parameters->GetDataSize());

    wrapper_info->create_object_id   = create_object_wrapper->GetCaptureId();
    wrapper_info->create_object_info = nullptr;
}

// InitializeState for API calls.
template <typename Wrapper>
void InitializeState(Wrapper*                        wrapper,
                     format::ApiCallId               create_call_id,
                     void*                           create_object_wrapper,
                     const util::MemoryOutputStream* create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);
    assert(create_object_wrapper == nullptr);

    auto wrapper_info = wrapper->GetObjectInfo();

    wrapper_info->create_call_id = create_call_id;
    wrapper_info->create_parameters =
        std::make_unique<util::MemoryOutputStream>(create_parameters->GetData(), create_parameters->GetDataSize());

    wrapper_info->create_object_id   = format::kNullHandleId;
    wrapper_info->create_object_info = nullptr;
}

GFXRECON_END_NAMESPACE(dx12_state_tracker)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_STATE_TRACKER_INITIALIZERS_H
