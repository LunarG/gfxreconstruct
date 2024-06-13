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
        GFXRECON_LOG_WARNING("openxr_wrappers::GetAtomWrappedId() couldn't find Atom: %" PRIu64
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
        GFXRECON_LOG_WARNING("openxr_wrappers::GetAtomWrapper() couldn't find Atom: %" PRIu64
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

#if defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)
// NOTE: This won't work on 32-bit builds because OpenXR defines all 32-bit
//       handles as uint64_t breaking the type conversion on each of these
//       override functions.
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
#endif // defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)

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
    for (auto entry : parent_wrapper->child_actionsets)
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
        parent_wrapper->child_actionsets.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<InstanceWrapper, NoParentWrapper, DebugUtilsMessengerEXTWrapper>(
    XrInstance parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrDebugUtilsMessengerEXT* handle,
    PFN_GetHandleId           get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<InstanceWrapper>(parent);

    // Filter duplicate object retrieval.
    DebugUtilsMessengerEXTWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_debugutilsmessengers)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<InstanceWrapper, DebugUtilsMessengerEXTWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<DebugUtilsMessengerEXTWrapper>(*handle);
        wrapper->layer_table_ref = &parent_wrapper->layer_table;
        parent_wrapper->child_debugutilsmessengers.push_back(wrapper);
    }
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
    for (auto entry : parent_wrapper->child_systemids)
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
        parent_wrapper->child_systemids.push_back(wrapper);
    }
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
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, SpaceWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrSpace*        handle,
    PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    SpaceWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_spaces)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, SpaceWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<SpaceWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_spaces.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, SwapchainWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrSwapchain*    handle,
    PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    SwapchainWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_swapchains)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, SwapchainWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<SwapchainWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_swapchains.push_back(wrapper);
    }
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
    for (auto entry : parent_wrapper->child_passthroughfbs)
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
        parent_wrapper->child_passthroughfbs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, SpatialAnchorMSFTWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrSpatialAnchorMSFT* handle,
    PFN_GetHandleId      get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    SpatialAnchorMSFTWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_spatialanchormsfts)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, SpatialAnchorMSFTWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<SpatialAnchorMSFTWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_spatialanchormsfts.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, SpatialGraphNodeBindingMSFTWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrSpatialGraphNodeBindingMSFT* handle,
    PFN_GetHandleId                get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    SpatialGraphNodeBindingMSFTWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_spatialgraphnodebindingmsfts)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, SpatialGraphNodeBindingMSFTWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<SpatialGraphNodeBindingMSFTWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_spatialgraphnodebindingmsfts.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, HandTrackerEXTWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrHandTrackerEXT* handle,
    PFN_GetHandleId   get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    HandTrackerEXTWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_handtrackerexts)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, HandTrackerEXTWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<HandTrackerEXTWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_handtrackerexts.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, BodyTrackerFBWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrBodyTrackerFB* handle,
    PFN_GetHandleId  get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    BodyTrackerFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_bodytrackerfbs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, BodyTrackerFBWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<BodyTrackerFBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_bodytrackerfbs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, SceneObserverMSFTWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrSceneObserverMSFT* handle,
    PFN_GetHandleId      get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    SceneObserverMSFTWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_sceneobservermsfts)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, SceneObserverMSFTWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<SceneObserverMSFTWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_sceneobservermsfts.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, FacialTrackerHTCWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrFacialTrackerHTC* handle,
    PFN_GetHandleId     get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    FacialTrackerHTCWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_facialtrackerhtcs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, FacialTrackerHTCWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<FacialTrackerHTCWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_facialtrackerhtcs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, FoveationProfileFBWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrFoveationProfileFB* handle,
    PFN_GetHandleId       get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    FoveationProfileFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_foveationprofilefbs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, FoveationProfileFBWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<FoveationProfileFBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_foveationprofilefbs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, TriangleMeshFBWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrTriangleMeshFB* handle,
    PFN_GetHandleId   get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    TriangleMeshFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_trianglemeshfbs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, TriangleMeshFBWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<TriangleMeshFBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_trianglemeshfbs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, PassthroughHTCWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrPassthroughHTC* handle,
    PFN_GetHandleId   get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    PassthroughHTCWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_passthroughhtcs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, PassthroughHTCWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<PassthroughHTCWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_passthroughhtcs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, PassthroughLayerFBWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrPassthroughLayerFB* handle,
    PFN_GetHandleId       get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    PassthroughLayerFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_passthroughlayerfbs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, PassthroughLayerFBWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<PassthroughLayerFBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_passthroughlayerfbs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, GeometryInstanceFBWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrGeometryInstanceFB* handle,
    PFN_GetHandleId       get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    GeometryInstanceFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_geometryinstancefbs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, GeometryInstanceFBWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<GeometryInstanceFBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_geometryinstancefbs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, MarkerDetectorMLWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrMarkerDetectorML* handle,
    PFN_GetHandleId     get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    MarkerDetectorMLWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_markerdetectormls)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, MarkerDetectorMLWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<MarkerDetectorMLWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_markerdetectormls.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, ExportedLocalizationMapMLWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrExportedLocalizationMapML* handle,
    PFN_GetHandleId              get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    ExportedLocalizationMapMLWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_exportedlocalizationmapmls)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, ExportedLocalizationMapMLWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<ExportedLocalizationMapMLWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_exportedlocalizationmapmls.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, SpatialAnchorStoreConnectionMSFTWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrSpatialAnchorStoreConnectionMSFT* handle,
    PFN_GetHandleId                     get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    SpatialAnchorStoreConnectionMSFTWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_spatialanchorstoreconnmsfts)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, SpatialAnchorStoreConnectionMSFTWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<SpatialAnchorStoreConnectionMSFTWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_spatialanchorstoreconnmsfts.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, SpaceUserFBWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrSpaceUserFB*  handle,
    PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    SpaceUserFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_spaceuserfbs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, SpaceUserFBWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<SpaceUserFBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_spaceuserfbs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, FaceTrackerFBWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrFaceTrackerFB* handle,
    PFN_GetHandleId  get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    FaceTrackerFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_facetrackerfbs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, FaceTrackerFBWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<FaceTrackerFBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_facetrackerfbs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, EyeTrackerFBWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrEyeTrackerFB* handle,
    PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    EyeTrackerFBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_eyetrackerfbs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, EyeTrackerFBWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<EyeTrackerFBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_eyetrackerfbs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, VirtualKeyboardMETAWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrVirtualKeyboardMETA* handle,
    PFN_GetHandleId        get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    VirtualKeyboardMETAWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_virtualkeyboardmetas)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, VirtualKeyboardMETAWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<VirtualKeyboardMETAWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_virtualkeyboardmetas.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, FaceTracker2FBWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrFaceTracker2FB* handle,
    PFN_GetHandleId   get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    FaceTracker2FBWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_facetracker2fbs)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, FaceTracker2FBWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<FaceTracker2FBWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_facetracker2fbs.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SessionWrapper, NoParentWrapper, PlaneDetectorEXTWrapper>(
    XrSession parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrPlaneDetectorEXT* handle,
    PFN_GetHandleId     get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SessionWrapper>(parent);

    // Filter duplicate object retrieval.
    PlaneDetectorEXTWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_planedetectorexts)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SessionWrapper, PlaneDetectorEXTWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<PlaneDetectorEXTWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_planedetectorexts.push_back(wrapper);
    }
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
    for (auto entry : parent_wrapper->child_asyncreqidfbs)
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
        parent_wrapper->child_asyncreqidfbs.push_back(wrapper);
    }
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
    for (auto entry : parent_wrapper->child_rendermodelkeyfbs)
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
        parent_wrapper->child_rendermodelkeyfbs.push_back(wrapper);
    }
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
    for (auto entry : parent_wrapper->child_controllermodelkeymsfts)
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
        parent_wrapper->child_controllermodelkeymsfts.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<ActionSetWrapper, NoParentWrapper, ActionWrapper>(
    XrActionSet parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrAction*       handle,
    PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<ActionSetWrapper>(parent);

    // Filter duplicate object retrieval.
    ActionWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_actions)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<ActionSetWrapper, ActionWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<ActionWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_actions.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<SceneObserverMSFTWrapper, NoParentWrapper, SceneMSFTWrapper>(
    XrSceneObserverMSFT parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrSceneMSFT*    handle,
    PFN_GetHandleId get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<SceneObserverMSFTWrapper>(parent);

    // Filter duplicate object retrieval.
    SceneMSFTWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_scenemsfts)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<SceneObserverMSFTWrapper, SceneMSFTWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<SceneMSFTWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_scenemsfts.push_back(wrapper);
    }
}

template <>
inline void CreateWrappedHandle<PassthroughFBWrapper, NoParentWrapper, PassthroughColorLutMETAWrapper>(
    XrPassthroughFB parent,
    NoParentWrapper::HandleType, // Does not have a co-parent
    XrPassthroughColorLutMETA* handle,
    PFN_GetHandleId            get_id)
{
    assert(parent != XR_NULL_HANDLE);
    assert(handle != nullptr);

    auto parent_wrapper = GetWrapper<PassthroughFBWrapper>(parent);

    // Filter duplicate object retrieval.
    PassthroughColorLutMETAWrapper* wrapper = nullptr;
    for (auto entry : parent_wrapper->child_passthroughcolorlutmetas)
    {
        if (entry->handle == (*handle))
        {
            wrapper = entry;
            break;
        }
    }

    if (wrapper == nullptr)
    {
        CreateWrappedDispatchHandle<PassthroughFBWrapper, PassthroughColorLutMETAWrapper>(parent, handle, get_id);

        wrapper                  = GetWrapper<PassthroughColorLutMETAWrapper>(*handle);
        wrapper->layer_table_ref = parent_wrapper->layer_table_ref;
        parent_wrapper->child_passthroughcolorlutmetas.push_back(wrapper);
    }
}

template <typename ParentWrapper, typename CoParentWrapper, typename Wrapper>
void CreateWrappedHandles(typename ParentWrapper::HandleType   parent,
                          typename CoParentWrapper::HandleType co_parent,
                          typename Wrapper::HandleType*        handles,
                          uint32_t                             count,
                          PFN_GetHandleId                      get_id)
{
    if (handles != nullptr)
    {
        for (uint32_t i = 0; i < count; ++i)
        {
            CreateWrappedHandle<ParentWrapper, CoParentWrapper, Wrapper>(parent, co_parent, &handles[i], get_id);
        }
    }
}

template <typename ParentWrapper, typename Wrapper>
void CreateWrappedAtoms(typename ParentWrapper::HandleType parent,
                        typename Wrapper::HandleType*      handles,
                        uint32_t                           count,
                        PFN_GetHandleId                    get_id)
{
    if (handles != nullptr)
    {
        for (uint32_t i = 0; i < count; ++i)
        {
            CreateWrappedAtom<ParentWrapper, Wrapper>(parent, &handles[i], get_id);
        }
    }
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

        for (auto child : wrapper->child_sessions)
        {
            RemoveWrapper<SessionWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_actionsets)
        {
            RemoveWrapper<ActionSetWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_systemids)
        {
            RemoveWrapper<SystemIdWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_paths)
        {
            RemoveWrapper<PathWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_debugutilsmessengers)
        {
            RemoveWrapper<DebugUtilsMessengerEXTWrapper>(child);
            delete child;
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

        for (auto child : wrapper->child_spaces)
        {
            RemoveWrapper<SpaceWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_swapchains)
        {
            RemoveWrapper<SwapchainWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_asyncreqidfbs)
        {
            RemoveWrapper<AsyncRequestIdFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_rendermodelkeyfbs)
        {
            RemoveWrapper<RenderModelKeyFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_controllermodelkeymsfts)
        {
            RemoveWrapper<ControllerModelKeyMSFTWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_spatialanchormsfts)
        {
            RemoveWrapper<SpatialAnchorMSFTWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_spatialgraphnodebindingmsfts)
        {
            RemoveWrapper<SpatialGraphNodeBindingMSFTWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_handtrackerexts)
        {
            RemoveWrapper<HandTrackerEXTWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_bodytrackerfbs)
        {
            RemoveWrapper<BodyTrackerFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_sceneobservermsfts)
        {
            RemoveWrapper<SceneObserverMSFTWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_facialtrackerhtcs)
        {
            RemoveWrapper<FacialTrackerHTCWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_foveationprofilefbs)
        {
            RemoveWrapper<FoveationProfileFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_trianglemeshfbs)
        {
            RemoveWrapper<TriangleMeshFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_passthroughfbs)
        {
            RemoveWrapper<PassthroughFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_passthroughlayerfbs)
        {
            RemoveWrapper<PassthroughLayerFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_geometryinstancefbs)
        {
            RemoveWrapper<GeometryInstanceFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_markerdetectormls)
        {
            RemoveWrapper<MarkerDetectorMLWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_exportedlocalizationmapmls)
        {
            RemoveWrapper<ExportedLocalizationMapMLWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_spatialanchorstoreconnmsfts)
        {
            RemoveWrapper<SpatialAnchorStoreConnectionMSFTWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_spaceuserfbs)
        {
            RemoveWrapper<SpaceUserFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_facetrackerfbs)
        {
            RemoveWrapper<FaceTrackerFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_eyetrackerfbs)
        {
            RemoveWrapper<EyeTrackerFBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_virtualkeyboardmetas)
        {
            RemoveWrapper<VirtualKeyboardMETAWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_facetracker2fbs)
        {
            RemoveWrapper<FaceTracker2FBWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_passthroughhtcs)
        {
            RemoveWrapper<PassthroughHTCWrapper>(child);
            delete child;
        }
        for (auto child : wrapper->child_planedetectorexts)
        {
            RemoveWrapper<PlaneDetectorEXTWrapper>(child);
            delete child;
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

        for (auto child : wrapper->child_markers)
        {
            RemoveWrapper<MarkerMLWrapper>(child);
            delete child;
        }

        RemoveWrapper<MarkerDetectorMLWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<SceneObserverMSFTWrapper>(XrSceneObserverMSFT handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<SceneObserverMSFTWrapper>(handle);

        for (auto child : wrapper->child_scenemsfts)
        {
            RemoveWrapper<SceneMSFTWrapper>(child);
            delete child;
        }

        RemoveWrapper<SceneObserverMSFTWrapper>(wrapper);
        delete wrapper;
    }
}

template <>
inline void DestroyWrappedHandle<PassthroughFBWrapper>(XrPassthroughFB handle)
{
    if (handle != XR_NULL_HANDLE)
    {
        // Destroy child wrappers.
        auto wrapper = GetWrapper<PassthroughFBWrapper>(handle);

        for (auto child : wrapper->child_passthroughcolorlutmetas)
        {
            RemoveWrapper<PassthroughColorLutMETAWrapper>(child);
            delete child;
        }

        RemoveWrapper<PassthroughFBWrapper>(wrapper);
        delete wrapper;
    }
}

GFXRECON_END_NAMESPACE(openxr_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPER_UTIL_H
