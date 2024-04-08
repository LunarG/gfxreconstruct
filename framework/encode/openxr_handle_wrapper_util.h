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
GFXRECON_BEGIN_NAMESPACE(openxr_wrappers)

#if (XR_PTR_SIZE == 8) && XR_CPP_NULLPTR_SUPPORTED
#define UINT64_TO_XR_HANDLE(handle_type, value) reinterpret_cast<handle_type>(value)
#else
#define UINT64_TO_XR_HANDLE(handle_type, value) static_cast<handle_type>(value)
#endif

typedef format::HandleId (*PFN_GetHandleId)();

extern OpenXrStateHandleTable openxr_state_handle_table_;

template <typename Wrapper>
format::HandleId GetTempWrapperId(const typename Wrapper::HandleType& handle)
{
    return 0;
}

template <typename Wrapper>
format::HandleId GetWrappedId(const typename Wrapper::HandleType& handle)
{
    if (handle == XR_NULL_HANDLE)
    {
        return format::kNullHandleId;
    }
    auto temp_id = GetTempWrapperId<Wrapper>(handle);
    if (temp_id != 0)
    {
        return temp_id;
    }

    auto wrapper = openxr_state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING("openxr_wrappers::GetWrappedId() couldn't find Handle: %" PRIu64
                             "'s wrapper. It might have been destroyed",
                             handle);
        return format::kNullHandleId;
    }
    return wrapper->handle_id;
}

template <typename Wrapper>
format::HandleId GetAtomWrappedId(const typename Wrapper::HandleType& handle)
{
    auto temp_id = GetTempWrapperId<Wrapper>(handle);
    if (temp_id != 0)
    {
        return temp_id;
    }

    auto wrapper = openxr_state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING("openxr_wrappers::GetAtomWrappedId() couldn't find Handle: %" PRIu64
                             "'s wrapper. It might have been destroyed",
                             handle);
        return format::kNullHandleId;
    }
    return wrapper->handle_id;
}

template <typename Wrapper>
Wrapper* GetWrapper(const typename Wrapper::HandleType& handle)
{
    if (handle == XR_NULL_HANDLE)
    {
        return 0;
    }
    auto wrapper = openxr_state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING("openxr_wrappers::GetWrapper() couldn't find Handle: %" PRIu64
                             "'s wrapper. It might have been destroyed",
                             handle);
    }
    return wrapper;
}

template <typename Wrapper>
Wrapper* GetAtomWrapper(const typename Wrapper::HandleType& handle)
{
    if (handle == 0ULL)
    {
        return 0;
    }
    auto wrapper = openxr_state_handle_table_.GetWrapper<Wrapper>(handle);
    if (wrapper == nullptr)
    {
        GFXRECON_LOG_WARNING("openxr_wrappers::GetAtomWrapper() couldn't find Handle: %" PRIu64
                             "'s wrapper. It might have been destroyed",
                             handle);
    }
    return wrapper;
}

template <typename Wrapper>
bool RemoveWrapper(const Wrapper* wrapper)
{
    return openxr_state_handle_table_.RemoveWrapper(wrapper);
}

uint64_t GetWrappedId(uint64_t object, XrObjectType object_type);

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

uint64_t GetWrappedId(uint64_t object, OpenXrAtomName atom_type);

inline const OpenXrInstanceTable* GetInstanceTable(XrInstance handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<InstanceWrapper>(handle);
    return &wrapper->layer_table;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrSession handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<SessionWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrSpace handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<SpaceWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrActionSet handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<ActionSetWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrAction handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<ActionWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrSwapchain handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<SwapchainWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrDebugUtilsMessengerEXT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<DebugUtilsMessengerEXTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrHandTrackerEXT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<HandTrackerEXTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrPlaneDetectorEXT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<PlaneDetectorEXTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrBodyTrackerFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<BodyTrackerFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrEyeTrackerFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<EyeTrackerFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrFaceTrackerFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<FaceTrackerFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrFaceTracker2FB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<FaceTracker2FBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrFoveationProfileFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<FoveationProfileFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrGeometryInstanceFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<GeometryInstanceFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrPassthroughFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<PassthroughFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrPassthroughLayerFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<PassthroughLayerFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrSpaceUserFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<SpaceUserFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrTriangleMeshFB handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<TriangleMeshFBWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrFacialTrackerHTC handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<FacialTrackerHTCWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrPassthroughHTC handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<PassthroughHTCWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrPassthroughColorLutMETA handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<PassthroughColorLutMETAWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrVirtualKeyboardMETA handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<VirtualKeyboardMETAWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrExportedLocalizationMapML handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<ExportedLocalizationMapMLWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrMarkerDetectorML handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<MarkerDetectorMLWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrSceneMSFT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<SceneMSFTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrSceneObserverMSFT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<SceneObserverMSFTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrSpatialAnchorMSFT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<SpatialAnchorMSFTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrSpatialAnchorStoreConnectionMSFT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<SpatialAnchorStoreConnectionMSFTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

inline const OpenXrInstanceTable* GetInstanceTable(XrSpatialGraphNodeBindingMSFT handle)
{
    assert(handle != XR_NULL_HANDLE);
    auto wrapper = GetWrapper<SpatialGraphNodeBindingMSFTWrapper>(handle);
    assert(wrapper->layer_table_ref != nullptr);
    return wrapper->layer_table_ref;
}

// Wrapper for create wrapper template instantiations that do not make use of all handle parameters.
struct NoParentWrapper : public HandleWrapper<void*>
{
    static constexpr void* kHandleValue{ XR_NULL_HANDLE };
};

template <typename ParentWrapper, typename Wrapper>
void CreateWrappedDispatchHandle(typename ParentWrapper::HandleType parent,
                                 typename Wrapper::HandleType*      handle,
                                 PFN_GetHandleId                    get_id)
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
void CreateWrappedNonDispatchHandle(typename Wrapper::HandleType* handle, PFN_GetHandleId get_id)
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

template <typename ParentWrapper, typename CoParentWrapper, typename Wrapper>
void CreateWrappedHandle(typename ParentWrapper::HandleType,   // Unused by default case.
                         typename CoParentWrapper::HandleType, // Unused by default case.
                         typename Wrapper::HandleType* handle,
                         PFN_GetHandleId               get_id)
{
    CreateWrappedNonDispatchHandle<Wrapper>(handle, get_id);
}

template <typename Wrapper>
void CreateWrappedAtom(typename Wrapper::HandleType* handle, PFN_GetHandleId get_id)
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

template <typename ParentWrapper, typename Wrapper>
void CreateWrappedAtom(typename ParentWrapper::HandleType, // Unused by default case.
                       typename Wrapper::HandleType* handle,
                       PFN_GetHandleId               get_id)
{
    CreateWrappedAtom<Wrapper>(handle, get_id);
}

template <>
inline void CreateWrappedHandle<NoParentWrapper, NoParentWrapper, InstanceWrapper>(
    NoParentWrapper::HandleType, // XrInstance does not have a parent.
    NoParentWrapper::HandleType, // XrInstance does not have a co-parent.
    XrInstance*     handle,
    PFN_GetHandleId get_id)
{
    CreateWrappedDispatchHandle<NoParentWrapper, InstanceWrapper>(NoParentWrapper::kHandleValue, handle, get_id);
}

template <>
inline void CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SessionWrapper>(
    XrInstance parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrSession*      handle,
    PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<InstanceWrapper>(parent);

    // Filter duplicate object retrieval.
    SessionWrapper* wrapper = nullptr;
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
        CreateWrappedDispatchHandle<InstanceWrapper, SessionWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<SessionWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_sessions.push_back(wrapper);
    }

    CreateWrappedDispatchHandle<InstanceWrapper, SessionWrapper>(XR_NULL_HANDLE, handle, get_id);
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, PassthroughFBWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrPassthroughFB* handle,
    PFN_GetHandleId  get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    PassthroughFBWrapper* wrapper = nullptr;
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
        CreateWrappedDispatchHandle<SessionWrapper, PassthroughFBWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<PassthroughFBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_passthroughs.push_back(wrapper);
    }

    CreateWrappedDispatchHandle<SessionWrapper, PassthroughFBWrapper>(XR_NULL_HANDLE, handle, get_id);
}

template <>
inline void CreateWrappedHandle<InstanceWrapper, NoParentWrapper, ActionSetWrapper>(
    XrInstance parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrActionSet*    handle,
    PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<InstanceWrapper>(parent);

    // Filter duplicate object retrieval.
    ActionSetWrapper* wrapper = nullptr;
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
        CreateWrappedDispatchHandle<InstanceWrapper, ActionSetWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<ActionSetWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_action_sets.push_back(wrapper);
    }

    CreateWrappedDispatchHandle<InstanceWrapper, ActionSetWrapper>(XR_NULL_HANDLE, handle, get_id);
}

template <>
inline void
CreateWrappedAtom<InstanceWrapper, SystemIdWrapper>(XrInstance parent, XrSystemId* handle, PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<InstanceWrapper>(parent);

    // Filter duplicate object retrieval.
    SystemIdWrapper* wrapper = nullptr;
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
        CreateWrappedAtom<SystemIdWrapper>(handle, get_id);

        wrapper = GetAtomWrapper<SystemIdWrapper>(*handle);
        parent_wrapper->child_system_ids.push_back(wrapper);
    }

    CreateWrappedAtom<SystemIdWrapper>(handle, get_id);
}

template <>
inline void CreateWrappedAtom<InstanceWrapper, PathWrapper>(XrInstance parent, XrPath* handle, PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<InstanceWrapper>(parent);

    // Filter duplicate object retrieval.
    PathWrapper* wrapper = nullptr;
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
        CreateWrappedAtom<PathWrapper>(handle, get_id);

        wrapper = GetAtomWrapper<PathWrapper>(*handle);
        parent_wrapper->child_paths.push_back(wrapper);
    }

    CreateWrappedAtom<PathWrapper>(handle, get_id);
}

template <>
inline void CreateWrappedAtom<SessionWrapper, AsyncRequestIdFBWrapper>(XrSession           parent,
                                                                       XrAsyncRequestIdFB* handle,
                                                                       PFN_GetHandleId     get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    AsyncRequestIdFBWrapper* wrapper = nullptr;
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
        CreateWrappedAtom<AsyncRequestIdFBWrapper>(handle, get_id);

        wrapper = GetAtomWrapper<AsyncRequestIdFBWrapper>(*handle);
        parent_wrapper->child_async_req_ids.push_back(wrapper);
    }

    CreateWrappedAtom<AsyncRequestIdFBWrapper>(handle, get_id);
}

template <>
inline void CreateWrappedAtom<SessionWrapper, RenderModelKeyFBWrapper>(XrSession           parent,
                                                                       XrRenderModelKeyFB* handle,
                                                                       PFN_GetHandleId     get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    RenderModelKeyFBWrapper* wrapper = nullptr;
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
        CreateWrappedAtom<RenderModelKeyFBWrapper>(handle, get_id);

        wrapper = GetAtomWrapper<RenderModelKeyFBWrapper>(*handle);
        parent_wrapper->child_render_model_keys.push_back(wrapper);
    }

    CreateWrappedAtom<RenderModelKeyFBWrapper>(handle, get_id);
}

template <>
inline void CreateWrappedAtom<MarkerDetectorMLWrapper, MarkerMLWrapper>(XrMarkerDetectorML parent,
                                                                        XrMarkerML*        handle,
                                                                        PFN_GetHandleId    get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<MarkerDetectorMLWrapper>(parent);

    // Filter duplicate object retrieval.
    MarkerMLWrapper* wrapper = nullptr;
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
        CreateWrappedAtom<MarkerMLWrapper>(handle, get_id);

        wrapper = GetAtomWrapper<MarkerMLWrapper>(*handle);
        parent_wrapper->child_markers.push_back(wrapper);
    }

    CreateWrappedAtom<MarkerMLWrapper>(handle, get_id);
}

template <>
inline void CreateWrappedAtom<SessionWrapper, ControllerModelKeyMSFTWrapper>(XrSession                 parent,
                                                                             XrControllerModelKeyMSFT* handle,
                                                                             PFN_GetHandleId           get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    ControllerModelKeyMSFTWrapper* wrapper = nullptr;
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
        CreateWrappedAtom<ControllerModelKeyMSFTWrapper>(handle, get_id);

        wrapper = GetAtomWrapper<ControllerModelKeyMSFTWrapper>(*handle);
        parent_wrapper->child_controller_model_keys.push_back(wrapper);
    }

    CreateWrappedAtom<ControllerModelKeyMSFTWrapper>(handle, get_id);
}

template <typename Wrapper>
void DestroyWrappedHandle(typename Wrapper::HandleType handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        auto wrapper = GetWrapper<Wrapper>(handle);
        RemoveWrapper<Wrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<InstanceWrapper>(XrInstance handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<InstanceWrapper>(handle);

        for (auto session_wrapper : wrapper->child_sessions)
        {
            RemoveWrapper<SessionWrapper>(session_wrapper);
            delete session_wrapper;
        }

        for (auto action_set_wrapper : wrapper->child_action_sets)
        {
            RemoveWrapper<ActionSetWrapper>(action_set_wrapper);
            delete action_set_wrapper;
        }

        RemoveWrapper<InstanceWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<SessionWrapper>(XrSession handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<SessionWrapper>(handle);

        for (auto passthrough_wrapper : wrapper->child_passthroughs)
        {
            RemoveWrapper<PassthroughFBWrapper>(passthrough_wrapper);
            delete passthrough_wrapper;
        }

        RemoveWrapper<SessionWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<MarkerDetectorMLWrapper>(XrMarkerDetectorML handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<MarkerDetectorMLWrapper>(handle);

        for (auto passthrough_wrapper : wrapper->child_markers)
        {
            RemoveWrapper<MarkerMLWrapper>(passthrough_wrapper);
            delete passthrough_wrapper;
        }

        RemoveWrapper<MarkerDetectorMLWrapper>(wrapper);
        delete wrapper;
    }
}

GFXRECON_END_NAMESPACE(openxr_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPER_UTIL_H
