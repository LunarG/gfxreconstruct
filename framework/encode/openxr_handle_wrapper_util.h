/*
** Copyright (c) 2019 LunarG, Inc.
** Copyright (c) 2023-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPER_UTIL_H
#define GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPER_UTIL_H

#include "encode/handle_unwrap_memory.h"
#include "encode/openxr_handle_wrappers.h"
#include "scoped_destroy_lock.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_openxr_dispatch_table.h"
#include "generated/generated_openxr_state_table.h"
#include "util/defines.h"

#include <algorithm>
#include <iterator>
#include <cassert>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

#if VK_USE_64_BIT_PTR_DEFINES == 1
#define UINT64_TO_VK_HANDLE(handle_type, value) reinterpret_cast<handle_type>(value)
#else
#define UINT64_TO_VK_HANDLE(handle_type, value) static_cast<handle_type>(value)
#endif

typedef format::HandleId (*PFN_GetHandleId)();

extern OpenXrStateHandleTable state_handle_table_;

template <typename Wrapper>
format::HandleId GetTempOpenXrWrapperId(const typename Wrapper::HandleType& handle)
{
    return 0;
}

template <typename Wrapper>
format::HandleId GetOpenXrWrappedId(const typename Wrapper::HandleType& handle)
{
    if (handle == XR_NULL_HANDLE)
    {
        return format::kNullHandleId;
    }
    auto temp_id = GetTempOpenXrWrapperId<Wrapper>(handle);
    if (temp_id != 0)
    {
        return temp_id;
    }

    auto wrapper = state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING("GetWrappedId() couldn't find Handle: %" PRIu64 "'s wrapper. It might have been destroyed",
                             handle);
        return format::kNullHandleId;
    }
    return wrapper->handle_id;
}

template <typename Wrapper>
Wrapper* GetOpenXrWrapper(const typename Wrapper::HandleType& handle)
{
    if (handle == XR_NULL_HANDLE)
    {
        return 0;
    }
    auto wrapper = state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING(
            "GetOpenXrWrapper() couldn't find Handle: %" PRIu64 "'s wrapper. It might have been destroyed", handle);
    }
    return wrapper;
}

template <typename Wrapper>
bool RemoveOpenXrWrapper(const Wrapper* wrapper)
{
    return state_handle_table_.RemoveWrapper(wrapper);
}

uint64_t GetWrappedId(uint64_t object, XrObjectType object_type);

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrInstance handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::InstanceWrapper>(handle);
    return &wrapper->layer_table;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrSession handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::SessionWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrActionSet handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::ActionSetWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrPassthroughFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::PassthroughFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

// Wrapper for create wrapper template instantiations that do not make use of all handle parameters.
struct OpenXrNoParentWrapper : public openxr_wrappers::HandleWrapper<void*>
{
    static constexpr void* kHandleValue{ XR_NULL_HANDLE };
};

template <typename OpenXrParentWrapper, typename Wrapper>
void CreateWrappedDispatchOpenXrHandle(typename OpenXrParentWrapper::HandleType parent,
                                       typename Wrapper::HandleType*            handle,
                                       PFN_GetHandleId                          get_id)
{
    ScopedDestroyLock shared_scoped_lock(true);
    assert(handle != nullptr);
    if ((*handle) != XR_NULL_HANDLE)
    {
        Wrapper* wrapper      = new Wrapper;
        wrapper->dispatch_key = *reinterpret_cast<void**>(*handle);
        wrapper->handle       = (*handle);
        wrapper->handle_id    = get_id();

        if (!state_handle_table_.InsertWrapper(wrapper))
        {
            GFXRECON_LOG_WARNING("Create a duplicated Handle: %" PRIu64
                                 ". This wrapper can't be written into OpenXrStateHandleTable.",
                                 *handle);
        }
    }
}

template <typename Wrapper>
void CreateWrappedNonDispatchOpenXrHandle(typename Wrapper::HandleType* handle, PFN_GetHandleId get_id)
{
    ScopedDestroyLock shared_scoped_lock(false);
    assert(handle != nullptr);
    if ((*handle) != XR_NULL_HANDLE)
    {
        Wrapper* wrapper   = new Wrapper;
        wrapper->handle    = (*handle);
        wrapper->handle_id = get_id();
        if (!state_handle_table_.InsertWrapper(wrapper))
        {
            GFXRECON_LOG_WARNING("Create a duplicated Handle: %" PRIu64
                                 ". This wrapper can't be written into OpenXrStateHandleTable.",
                                 *handle);
        }
    }
}

template <typename OpenXrParentWrapper, typename OpenXrCoParentWrapper, typename Wrapper>
void CreateWrappedOpenXrHandle(typename OpenXrParentWrapper::HandleType,   // Unused by default case.
                               typename OpenXrCoParentWrapper::HandleType, // Unused by default case.
                               typename Wrapper::HandleType* handle,
                               PFN_GetHandleId               get_id)
{
    CreateWrappedNonDispatchOpenXrHandle<Wrapper>(handle, get_id);
}

template <>
inline void CreateWrappedOpenXrHandle<OpenXrNoParentWrapper, OpenXrNoParentWrapper, openxr_wrappers::InstanceWrapper>(
    OpenXrNoParentWrapper::HandleType, // XrInstance does not have a parent.
    OpenXrNoParentWrapper::HandleType, // XrInstance does not have a co-parent.
    XrInstance*     handle,
    PFN_GetHandleId get_id)
{
    CreateWrappedDispatchOpenXrHandle<OpenXrNoParentWrapper, openxr_wrappers::InstanceWrapper>(
        OpenXrNoParentWrapper::kHandleValue, handle, get_id);
}

template <>
inline void
CreateWrappedOpenXrHandle<openxr_wrappers::InstanceWrapper, OpenXrNoParentWrapper, openxr_wrappers::SessionWrapper>(
    XrInstance parent,
    OpenXrNoParentWrapper::HandleType, // Does not have a co-parent
    XrSession*      handle,
    PFN_GetHandleId get_id)
{
    assert(parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetOpenXrWrapper<openxr_wrappers::InstanceWrapper>(parent);

    // Filter duplicate object retrieval.
    openxr_wrappers::SessionWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_sessions)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchOpenXrHandle<openxr_wrappers::InstanceWrapper, openxr_wrappers::SessionWrapper>(
            parent, handle, get_id);

        wrapper                  = GetOpenXrWrapper<openxr_wrappers::SessionWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_sessions.push_back(wrapper);
    }

    CreateWrappedDispatchOpenXrHandle<openxr_wrappers::InstanceWrapper, openxr_wrappers::SessionWrapper>(
        VK_NULL_HANDLE, handle, get_id);
}

template <>
inline void CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper,
                                      OpenXrNoParentWrapper,
                                      openxr_wrappers::PassthroughFBWrapper>(
    XrSession parent,
    OpenXrNoParentWrapper::HandleType, // Does not have a co-parent
    XrPassthroughFB* handle,
    PFN_GetHandleId  get_id)
{
    assert(parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetOpenXrWrapper<openxr_wrappers::SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    openxr_wrappers::PassthroughFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_passthroughs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchOpenXrHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::PassthroughFBWrapper>(
            parent, handle, get_id);

        wrapper                  = GetOpenXrWrapper<openxr_wrappers::PassthroughFBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_passthroughs.push_back(wrapper);
    }

    CreateWrappedDispatchOpenXrHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::PassthroughFBWrapper>(
        VK_NULL_HANDLE, handle, get_id);
}

template <>
inline void
CreateWrappedOpenXrHandle<openxr_wrappers::InstanceWrapper, OpenXrNoParentWrapper, openxr_wrappers::ActionSetWrapper>(
    XrInstance parent,
    OpenXrNoParentWrapper::HandleType, // Does not have a co-parent
    XrActionSet*    handle,
    PFN_GetHandleId get_id)
{
    assert(parent != VK_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetOpenXrWrapper<openxr_wrappers::InstanceWrapper>(parent);

    // Filter duplicate object retrieval.
    openxr_wrappers::ActionSetWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_action_sets)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchOpenXrHandle<openxr_wrappers::InstanceWrapper, openxr_wrappers::ActionSetWrapper>(
            parent, handle, get_id);

        wrapper                  = GetOpenXrWrapper<openxr_wrappers::ActionSetWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_action_sets.push_back(wrapper);
    }

    CreateWrappedDispatchOpenXrHandle<openxr_wrappers::InstanceWrapper, openxr_wrappers::ActionSetWrapper>(
        VK_NULL_HANDLE, handle, get_id);
}

template <typename Wrapper>
void DestroyWrappedHandle(typename Wrapper::HandleType handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        auto wrapper = GetOpenXrWrapper<Wrapper>(handle);
        RemoveOpenXrWrapper<Wrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<openxr_wrappers::InstanceWrapper>(XrInstance handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetOpenXrWrapper<openxr_wrappers::InstanceWrapper>(handle);

        for (auto session_wrapper : wrapper->child_sessions)
        {
            RemoveOpenXrWrapper<openxr_wrappers::SessionWrapper>(session_wrapper);
            delete session_wrapper;
        }

        for (auto action_set_wrapper : wrapper->child_action_sets)
        {
            RemoveOpenXrWrapper<openxr_wrappers::ActionSetWrapper>(action_set_wrapper);
            delete action_set_wrapper;
        }

        RemoveOpenXrWrapper<openxr_wrappers::InstanceWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<openxr_wrappers::SessionWrapper>(XrSession handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetOpenXrWrapper<openxr_wrappers::SessionWrapper>(handle);

        for (auto passthrough_wrapper : wrapper->child_passthroughs)
        {
            RemoveOpenXrWrapper<openxr_wrappers::PassthroughFBWrapper>(passthrough_wrapper);
            delete passthrough_wrapper;
        }

        RemoveOpenXrWrapper<openxr_wrappers::SessionWrapper>(wrapper);
        delete wrapper;
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPER_UTIL_H
