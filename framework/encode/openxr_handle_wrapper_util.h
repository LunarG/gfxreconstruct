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

#if (XR_PTR_SIZE == 8) && XR_CPP_NULLPTR_SUPPORTED
#define UINT64_TO_XR_HANDLE(handle_type, value) reinterpret_cast<handle_type>(value)
#else
#define UINT64_TO_XR_HANDLE(handle_type, value) static_cast<handle_type>(value)
#endif

typedef format::HandleId (*PFN_GetHandleId)();

extern OpenXrStateHandleTable openxr_state_handle_table_;

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

    auto wrapper = openxr_state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING("GetWrappedId() couldn't find Handle: %" PRIu64 "'s wrapper. It might have been destroyed",
                             handle);
        return format::kNullHandleId;
    }
    return wrapper->handle_id;
}

template <typename Wrapper>
format::HandleId GetOpenXrAtomWrappedId(const typename Wrapper::HandleType& handle)
{
    auto temp_id = GetTempOpenXrWrapperId<Wrapper>(handle);
    if (temp_id != 0)
    {
        return temp_id;
    }

    auto wrapper = openxr_state_handle_table_.GetWrapper<Wrapper>(handle);
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
    auto wrapper = openxr_state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING(
            "GetOpenXrWrapper() couldn't find Handle: %" PRIu64 "'s wrapper. It might have been destroyed", handle);
    }
    return wrapper;
}

template <typename Wrapper>
Wrapper* GetOpenXrAtomWrapper(const typename Wrapper::HandleType& handle)
{
    if (handle == 0ULL)
    {
        return 0;
    }
    auto wrapper = openxr_state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING(
            "GetOpenXrAtomWrapper() couldn't find Handle: %" PRIu64 "'s wrapper. It might have been destroyed", handle);
    }
    return wrapper;
}

template <typename Wrapper>
bool RemoveOpenXrWrapper(const Wrapper* wrapper)
{
    return openxr_state_handle_table_.RemoveWrapper(wrapper);
}

uint64_t GetOpenXrWrappedId(uint64_t object, XrObjectType object_type);

enum OpenXrAtomName
{
    OPENXR_ATOM_NAME_UNKNOWN = 0,
    OPENXR_ATOM_NAME_SYSTEM_ID,
    OPENXR_ATOM_NAME_PATH,
    OPENXR_ATOM_NAME_ASYNC_REQUEST_ID_FB,
    OPENXR_ATOM_NAME_RENDER_MODEL_KEY_FB,
    OPENXR_ATOM_NAME_MARKER_ML,
    OPENXR_ATOM_NAME_CONTROLLER_MODEL_KEY_MSFT,
};

uint64_t GetOpenXrWrappedId(uint64_t object, OpenXrAtomName atom_type);

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

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrSpace handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::SpaceWrapper>(handle);
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

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrAction handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::ActionWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrSwapchain handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::SwapchainWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrDebugUtilsMessengerEXT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrHandTrackerEXT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::HandTrackerEXTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrPlaneDetectorEXT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::PlaneDetectorEXTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrBodyTrackerFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::BodyTrackerFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrEyeTrackerFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::EyeTrackerFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrFaceTrackerFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::FaceTrackerFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrFaceTracker2FB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::FaceTracker2FBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrFoveationProfileFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::FoveationProfileFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrGeometryInstanceFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::GeometryInstanceFBWrapper>(handle);
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

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrPassthroughLayerFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::PassthroughLayerFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrSpaceUserFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::SpaceUserFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrTriangleMeshFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::TriangleMeshFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrFacialTrackerHTC handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::FacialTrackerHTCWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrPassthroughHTC handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::PassthroughHTCWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrPassthroughColorLutMETA handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::PassthroughColorLutMETAWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrVirtualKeyboardMETA handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::VirtualKeyboardMETAWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrExportedLocalizationMapML handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::ExportedLocalizationMapMLWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrMarkerDetectorML handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrSceneMSFT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::SceneMSFTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrSceneObserverMSFT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::SceneObserverMSFTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrSpatialAnchorMSFT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::SpatialAnchorMSFTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrSpatialAnchorStoreConnectionMSFT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetOpenXrInstanceTable(XrSpatialGraphNodeBindingMSFT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetOpenXrWrapper<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(handle);
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

        if (!openxr_state_handle_table_.InsertWrapper(wrapper))
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
        if (!openxr_state_handle_table_.InsertWrapper(wrapper))
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

template <typename Wrapper>
void CreateWrappedOpenXrAtom(typename Wrapper::HandleType* handle, PFN_GetHandleId get_id)
{
    ScopedDestroyLock shared_scoped_lock(false);
    assert(handle != nullptr);
    if ((*handle) != 0ULL)
    {
        Wrapper* wrapper   = new Wrapper;
        wrapper->handle    = (*handle);
        wrapper->handle_id = get_id();
        if (!openxr_state_handle_table_.InsertWrapper(wrapper))
        {
            GFXRECON_LOG_WARNING("Create a duplicated Atom: %" PRIu64
                                 ". This wrapper can't be written into OpenXrStateHandleTable.",
                                 *handle);
        }
    }
}

template <typename OpenXrParentWrapper, typename Wrapper>
void CreateWrappedOpenXrAtom(typename OpenXrParentWrapper::HandleType, // Unused by default case.
                             typename Wrapper::HandleType* handle,
                             PFN_GetHandleId               get_id)
{
    CreateWrappedOpenXrAtom<Wrapper>(handle, get_id);
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
    assert(parent != XR_NULL_HANDLE);
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
        XR_NULL_HANDLE, handle, get_id);
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
    assert(parent != XR_NULL_HANDLE);
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
        XR_NULL_HANDLE, handle, get_id);
}

template <>
inline void
CreateWrappedOpenXrHandle<openxr_wrappers::InstanceWrapper, OpenXrNoParentWrapper, openxr_wrappers::ActionSetWrapper>(
    XrInstance parent,
    OpenXrNoParentWrapper::HandleType, // Does not have a co-parent
    XrActionSet*    handle,
    PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
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
        XR_NULL_HANDLE, handle, get_id);
}

template <>
inline void CreateWrappedOpenXrAtom<openxr_wrappers::InstanceWrapper, openxr_wrappers::SystemIdWrapper>(
    XrInstance parent, XrSystemId* handle, PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetOpenXrWrapper<openxr_wrappers::InstanceWrapper>(parent);

    // Filter duplicate object retrieval.
    openxr_wrappers::SystemIdWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_system_ids)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedOpenXrAtom<openxr_wrappers::SystemIdWrapper>(handle, get_id);

        wrapper = GetOpenXrAtomWrapper<openxr_wrappers::SystemIdWrapper>(*handle);
        parent_wrapper->child_system_ids.push_back(wrapper);
    }

    CreateWrappedOpenXrAtom<openxr_wrappers::SystemIdWrapper>(handle, get_id);
}

template <>
inline void CreateWrappedOpenXrAtom<openxr_wrappers::InstanceWrapper, openxr_wrappers::PathWrapper>(
    XrInstance parent, XrPath* handle, PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetOpenXrWrapper<openxr_wrappers::InstanceWrapper>(parent);

    // Filter duplicate object retrieval.
    openxr_wrappers::PathWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_paths)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedOpenXrAtom<openxr_wrappers::PathWrapper>(handle, get_id);

        wrapper = GetOpenXrAtomWrapper<openxr_wrappers::PathWrapper>(*handle);
        parent_wrapper->child_paths.push_back(wrapper);
    }

    CreateWrappedOpenXrAtom<openxr_wrappers::PathWrapper>(handle, get_id);
}

template <>
inline void CreateWrappedOpenXrAtom<openxr_wrappers::SessionWrapper, openxr_wrappers::AsyncRequestIdFBWrapper>(
    XrSession parent, XrAsyncRequestIdFB* handle, PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetOpenXrWrapper<openxr_wrappers::SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    openxr_wrappers::AsyncRequestIdFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_async_req_ids)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedOpenXrAtom<openxr_wrappers::AsyncRequestIdFBWrapper>(handle, get_id);

        wrapper = GetOpenXrAtomWrapper<openxr_wrappers::AsyncRequestIdFBWrapper>(*handle);
        parent_wrapper->child_async_req_ids.push_back(wrapper);
    }

    CreateWrappedOpenXrAtom<openxr_wrappers::AsyncRequestIdFBWrapper>(handle, get_id);
}

template <>
inline void CreateWrappedOpenXrAtom<openxr_wrappers::SessionWrapper, openxr_wrappers::RenderModelKeyFBWrapper>(
    XrSession parent, XrRenderModelKeyFB* handle, PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetOpenXrWrapper<openxr_wrappers::SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    openxr_wrappers::RenderModelKeyFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_render_model_keys)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedOpenXrAtom<openxr_wrappers::RenderModelKeyFBWrapper>(handle, get_id);

        wrapper = GetOpenXrAtomWrapper<openxr_wrappers::RenderModelKeyFBWrapper>(*handle);
        parent_wrapper->child_render_model_keys.push_back(wrapper);
    }

    CreateWrappedOpenXrAtom<openxr_wrappers::RenderModelKeyFBWrapper>(handle, get_id);
}

template <>
inline void CreateWrappedOpenXrAtom<openxr_wrappers::MarkerDetectorMLWrapper, openxr_wrappers::MarkerMLWrapper>(
    XrMarkerDetectorML parent, XrMarkerML* handle, PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetOpenXrWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(parent);

    // Filter duplicate object retrieval.
    openxr_wrappers::MarkerMLWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_markers)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedOpenXrAtom<openxr_wrappers::MarkerMLWrapper>(handle, get_id);

        wrapper = GetOpenXrAtomWrapper<openxr_wrappers::MarkerMLWrapper>(*handle);
        parent_wrapper->child_markers.push_back(wrapper);
    }

    CreateWrappedOpenXrAtom<openxr_wrappers::MarkerMLWrapper>(handle, get_id);
}

template <>
inline void CreateWrappedOpenXrAtom<openxr_wrappers::SessionWrapper, openxr_wrappers::ControllerModelKeyMSFTWrapper>(
    XrSession parent, XrControllerModelKeyMSFT* handle, PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetOpenXrWrapper<openxr_wrappers::SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    openxr_wrappers::ControllerModelKeyMSFTWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_controller_model_keys)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedOpenXrAtom<openxr_wrappers::ControllerModelKeyMSFTWrapper>(handle, get_id);

        wrapper = GetOpenXrAtomWrapper<openxr_wrappers::ControllerModelKeyMSFTWrapper>(*handle);
        parent_wrapper->child_controller_model_keys.push_back(wrapper);
    }

    CreateWrappedOpenXrAtom<openxr_wrappers::ControllerModelKeyMSFTWrapper>(handle, get_id);
}

template <typename Wrapper>
void DestroyWrappedOpenXrHandle(typename Wrapper::HandleType handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        auto wrapper = GetOpenXrWrapper<Wrapper>(handle);
        RemoveOpenXrWrapper<Wrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedOpenXrHandle<openxr_wrappers::InstanceWrapper>(XrInstance handle)
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
inline void DestroyWrappedOpenXrHandle<openxr_wrappers::SessionWrapper>(XrSession handle)
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

template <>
inline void DestroyWrappedOpenXrHandle<openxr_wrappers::MarkerDetectorMLWrapper>(XrMarkerDetectorML handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetOpenXrWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(handle);

        for (auto passthrough_wrapper : wrapper->child_markers)
        {
            RemoveOpenXrWrapper<openxr_wrappers::MarkerMLWrapper>(passthrough_wrapper);
            delete passthrough_wrapper;
        }

        RemoveOpenXrWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(wrapper);
        delete wrapper;
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPER_UTIL_H
