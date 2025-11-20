/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/openxr_resource_tracking_consumer.h"

#include <algorithm>
#include <cassert>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const std::vector<std::string> kLoaderLibNames = {
#if defined(WIN32)
    "openxr-1.dll"
#elif defined(__APPLE__)
    "libopenxr.dylib", "libopenxr.1.dylib", "libMoltenVK.dylib"
#else
    "libopenxr.so", "libopenxr.so.1"
#endif
};

OpenXrResourceTrackingConsumer::OpenXrResourceTrackingConsumer(
    const OpenXrReplayOptions& options, OpenXrTrackedObjectInfoTable* tracked_object_info_table) :
    loader_handle_(nullptr), create_instance_function_(nullptr), get_instance_proc_addr_(nullptr), options_(options),
    tracked_object_info_table_(tracked_object_info_table)
{
    assert(tracked_object_info_table != nullptr);
}

OpenXrResourceTrackingConsumer::~OpenXrResourceTrackingConsumer()
{
    if (loader_handle_ != nullptr)
    {
        util::platform::CloseLibrary(loader_handle_);
    }
}

void OpenXrResourceTrackingConsumer::InitializeLoader()
{
    for (auto name : kLoaderLibNames)
    {
        loader_handle_ = util::platform::OpenLibrary(name.c_str());
        if (loader_handle_ != nullptr)
        {
            get_instance_proc_addr_ = reinterpret_cast<PFN_xrGetInstanceProcAddr>(
                util::platform::GetProcAddress(loader_handle_, "xrGetInstanceProcAddr"));
            break;
        }
    }

    if (get_instance_proc_addr_ != nullptr)
    {
        XrResult result = get_instance_proc_addr_(
            XR_NULL_HANDLE, "xrCreateInstance", reinterpret_cast<PFN_xrVoidFunction*>(create_instance_function_));
        if (create_instance_function_ == nullptr)
        {
            GFXRECON_LOG_FATAL("Failed to load OpenXr runtime library; please ensure that the path to the OpenXr "
                               "loader (eg. %s) has been added to the appropriate system path",
                               kLoaderLibNames[0].c_str());
        }
    }
}

void OpenXrResourceTrackingConsumer::AddInstanceTable(XrInstance instance)
{
    encode::OpenXrInstanceTable& table = instance_tables_[instance];
    encode::LoadOpenXrInstanceTable(get_instance_proc_addr_, instance, &table);
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrInstance handle) const
{
    auto table = instance_tables_.find(handle);
    assert(table != instance_tables_.end());
    return (table != instance_tables_.end()) ? &table->second : nullptr;
}

#if defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)
// NOTE: This won't work on 32-bit builds because OpenXR defines all 32-bit
//       handles as uint64_t breaking the type conversion on each of these
//       override functions.
//
// TODO: Add code generation for below
const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrSession handle) const
{
    auto instance = session_to_instance_.find(handle);
    assert(instance != session_to_instance_.end());
    return (instance != session_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrSpace handle) const
{
    auto instance = space_to_instance_.find(handle);
    assert(instance != space_to_instance_.end());
    return (instance != space_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrSwapchain handle) const
{
    auto instance = swapchain_to_instance_.find(handle);
    assert(instance != swapchain_to_instance_.end());
    return (instance != swapchain_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrActionSet handle) const
{
    auto instance = actionset_to_instance_.find(handle);
    assert(instance != actionset_to_instance_.end());
    return (instance != actionset_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrAction handle) const
{
    auto instance = action_to_instance_.find(handle);
    assert(instance != action_to_instance_.end());
    return (instance != action_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable*
OpenXrResourceTrackingConsumer::GetInstanceTable(XrDebugUtilsMessengerEXT handle) const
{
    auto instance = debugutilsmessengerEXT_to_instance_.find(handle);
    assert(instance != debugutilsmessengerEXT_to_instance_.end());
    return (instance != debugutilsmessengerEXT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrSpatialAnchorMSFT handle) const
{
    auto instance = spatialanchorMSFT_to_instance_.find(handle);
    assert(instance != spatialanchorMSFT_to_instance_.end());
    return (instance != spatialanchorMSFT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrHandTrackerEXT handle) const
{
    auto instance = handtrackerEXT_to_instance_.find(handle);
    assert(instance != handtrackerEXT_to_instance_.end());
    return (instance != handtrackerEXT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrBodyTrackerFB handle) const
{
    auto instance = bodytrackerFB_to_instance_.find(handle);
    assert(instance != bodytrackerFB_to_instance_.end());
    return (instance != bodytrackerFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrSceneObserverMSFT handle) const
{
    auto instance = sceneobserverMSFT_to_instance_.find(handle);
    assert(instance != sceneobserverMSFT_to_instance_.end());
    return (instance != sceneobserverMSFT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrSceneMSFT handle) const
{
    auto instance = sceneMSFT_to_instance_.find(handle);
    assert(instance != sceneMSFT_to_instance_.end());
    return (instance != sceneMSFT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrFacialTrackerHTC handle) const
{
    auto instance = facialtrackerHTC_to_instance_.find(handle);
    assert(instance != facialtrackerHTC_to_instance_.end());
    return (instance != facialtrackerHTC_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrFoveationProfileFB handle) const
{
    auto instance = foveationprofileFB_to_instance_.find(handle);
    assert(instance != foveationprofileFB_to_instance_.end());
    return (instance != foveationprofileFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrPassthroughFB handle) const
{
    auto instance = passthroughFB_to_instance_.find(handle);
    assert(instance != passthroughFB_to_instance_.end());
    return (instance != passthroughFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrPassthroughLayerFB handle) const
{
    auto instance = passthroughlayerFB_to_instance_.find(handle);
    assert(instance != passthroughlayerFB_to_instance_.end());
    return (instance != passthroughlayerFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrGeometryInstanceFB handle) const
{
    auto instance = geometryinstanceFB_to_instance_.find(handle);
    assert(instance != geometryinstanceFB_to_instance_.end());
    return (instance != geometryinstanceFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrPlaneDetectorEXT handle) const
{
    auto instance = planedetectorEXT_to_instance_.find(handle);
    assert(instance != planedetectorEXT_to_instance_.end());
    return (instance != planedetectorEXT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrPassthroughHTC handle) const
{
    auto instance = passthroughHTC_to_instance_.find(handle);
    assert(instance != passthroughHTC_to_instance_.end());
    return (instance != passthroughHTC_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrMarkerDetectorML handle) const
{
    auto instance = markerdetectorML_to_instance_.find(handle);
    assert(instance != markerdetectorML_to_instance_.end());
    return (instance != markerdetectorML_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable*
OpenXrResourceTrackingConsumer::GetInstanceTable(XrExportedLocalizationMapML handle) const
{
    auto instance = exportedlocalicationML_to_instance_.find(handle);
    assert(instance != exportedlocalicationML_to_instance_.end());
    return (instance != exportedlocalicationML_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable*
OpenXrResourceTrackingConsumer::GetInstanceTable(XrSpatialAnchorStoreConnectionMSFT handle) const
{
    auto instance = spatialanchorconnectionMSFT_to_instance_.find(handle);
    assert(instance != spatialanchorconnectionMSFT_to_instance_.end());
    return (instance != spatialanchorconnectionMSFT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrFaceTrackerFB handle) const
{
    auto instance = facetrackerFB_to_instance_.find(handle);
    assert(instance != facetrackerFB_to_instance_.end());
    return (instance != facetrackerFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrEyeTrackerFB handle) const
{
    auto instance = eyetrackerFB_to_instance_.find(handle);
    assert(instance != eyetrackerFB_to_instance_.end());
    return (instance != eyetrackerFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrVirtualKeyboardMETA handle) const
{
    auto instance = virtualkeyboardMETA_to_instance_.find(handle);
    assert(instance != virtualkeyboardMETA_to_instance_.end());
    return (instance != virtualkeyboardMETA_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrSpaceUserFB handle) const
{
    auto instance = spaceuserFB_to_instance_.find(handle);
    assert(instance != spaceuserFB_to_instance_.end());
    return (instance != spaceuserFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable*
OpenXrResourceTrackingConsumer::GetInstanceTable(XrPassthroughColorLutMETA handle) const
{
    auto instance = passthroughcolorlutMETA_to_instance_.find(handle);
    assert(instance != passthroughcolorlutMETA_to_instance_.end());
    return (instance != passthroughcolorlutMETA_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrResourceTrackingConsumer::GetInstanceTable(XrFaceTracker2FB handle) const
{
    auto instance = facetracker2FB_to_instance_.find(handle);
    assert(instance != facetracker2FB_to_instance_.end());
    return (instance != facetracker2FB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}
#endif // defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)

void OpenXrResourceTrackingConsumer::Process_xrCreateInstance(
    const ApiCallInfo&                                  call_info,
    XrResult                                            returnValue,
    StructPointerDecoder<Decoded_XrInstanceCreateInfo>* pCreateInfo,
    HandlePointerDecoder<XrInstance>*                   pInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((pCreateInfo != nullptr) && (pInstance != nullptr));

    if (!pInstance->IsNull())
    {
        pInstance->SetHandleLength(1);
    }

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_instance    = pInstance->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_instance != nullptr));

    if (loader_handle_ == nullptr)
    {
        InitializeLoader();
    }

    // TODO(gfxrec-28): Replace WSI extension in extension list??

    // TODO(gfxrec-28): Disable layers??

    XrResult result = create_instance_function_(replay_create_info, replay_instance);

    if ((replay_instance != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrInstanceInfo instance_info;
        instance_info.SetCaptureId(*(pInstance->GetPointer()));
        instance_info.SetHandleId(*replay_instance);
        GetTrackedObjectInfoTable()->AddTrackedXrInstanceInfo(std::move(instance_info));
        AddInstanceTable(*replay_instance);
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyInstance(const ApiCallInfo& call_info, format::HandleId instance)
{
    auto       instance_info = GetTrackedObjectInfoTable()->GetTrackedXrInstanceInfo(instance);
    XrInstance in_instance   = instance_info->GetHandleId();

    GetInstanceTable(in_instance)->DestroyInstance(in_instance);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSession(
    const ApiCallInfo&                                 call_info,
    XrResult                                           returnValue,
    format::HandleId                                   instance,
    StructPointerDecoder<Decoded_XrSessionCreateInfo>* createInfo,
    HandlePointerDecoder<XrSession>*                   session)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (session != nullptr));

    if (!session->IsNull())
    {
        session->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_session     = session->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_session != nullptr));

    auto       instance_info   = GetTrackedObjectInfoTable()->GetTrackedXrInstanceInfo(instance);
    XrInstance replay_instance = instance_info->GetHandleId();

    XrResult result =
        GetInstanceTable(replay_instance)->CreateSession(replay_instance, replay_create_info, replay_session);

    if ((replay_session != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSessionInfo session_info;
        session_info.SetCaptureId(*(session->GetPointer()));
        session_info.SetHandleId(*replay_session);
        GetTrackedObjectInfoTable()->AddTrackedXrSessionInfo(std::move(session_info));

        session_to_instance_[*replay_session] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroySession(const ApiCallInfo& call_info,
                                                              XrResult           returnValue,
                                                              format::HandleId   session)
{
    auto      session_info = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession in_session   = session_info->GetHandleId();

    GetInstanceTable(in_session)->DestroySession(in_session);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateReferenceSpace(
    const ApiCallInfo&                                        call_info,
    XrResult                                                  returnValue,
    format::HandleId                                          session,
    StructPointerDecoder<Decoded_XrReferenceSpaceCreateInfo>* createInfo,
    HandlePointerDecoder<XrSpace>*                            space)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (space != nullptr));

    if (!space->IsNull())
    {
        space->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = space->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();
    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateReferenceSpace(replay_session, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(space->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreateActionSpace(
    const ApiCallInfo&                                     call_info,
    XrResult                                               returnValue,
    format::HandleId                                       session,
    StructPointerDecoder<Decoded_XrActionSpaceCreateInfo>* createInfo,
    HandlePointerDecoder<XrSpace>*                         space)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (space != nullptr));

    if (!space->IsNull())
    {
        space->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = space->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateActionSpace(replay_session, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(space->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroySpace(const ApiCallInfo& call_info,
                                                            XrResult           returnValue,
                                                            format::HandleId   space)
{
    auto    space_info = GetTrackedObjectInfoTable()->GetTrackedXrSpaceInfo(space);
    XrSpace in_space   = space_info->GetHandleId();

    GetInstanceTable(in_space)->DestroySpace(in_space);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSwapchain(
    const ApiCallInfo&                                   call_info,
    XrResult                                             returnValue,
    format::HandleId                                     session,
    StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* createInfo,
    HandlePointerDecoder<XrSwapchain>*                   swapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (swapchain != nullptr));

    if (!swapchain->IsNull())
    {
        swapchain->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_swapchain   = swapchain->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_swapchain != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();
    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateSwapchain(replay_session, replay_create_info, replay_swapchain);

    if ((replay_swapchain != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSwapchainInfo swapchain_info;
        swapchain_info.SetCaptureId(*(swapchain->GetPointer()));
        swapchain_info.SetHandleId(*replay_swapchain);
        GetTrackedObjectInfoTable()->AddTrackedXrSwapchainInfo(std::move(swapchain_info));

        swapchain_to_instance_[*replay_swapchain] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroySwapchain(const ApiCallInfo& call_info,
                                                                XrResult           returnValue,
                                                                format::HandleId   swapchain)
{
    auto        swapchain_info = GetTrackedObjectInfoTable()->GetTrackedXrSwapchainInfo(swapchain);
    XrSwapchain in_swapchain   = swapchain_info->GetHandleId();

    GetInstanceTable(in_swapchain)->DestroySwapchain(in_swapchain);
}

// TODO: Add code generation for below
void OpenXrResourceTrackingConsumer::Process_xrCreateActionSet(
    const ApiCallInfo&                                   call_info,
    XrResult                                             returnValue,
    format::HandleId                                     instance,
    StructPointerDecoder<Decoded_XrActionSetCreateInfo>* createInfo,
    HandlePointerDecoder<XrActionSet>*                   actionSet)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (actionSet != nullptr));

    if (!actionSet->IsNull())
    {
        actionSet->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_actionset   = actionSet->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_actionset != nullptr));

    auto       instance_info   = GetTrackedObjectInfoTable()->GetTrackedXrInstanceInfo(instance);
    XrInstance replay_instance = instance_info->GetHandleId();

    XrResult result =
        GetInstanceTable(replay_instance)->CreateActionSet(replay_instance, replay_create_info, replay_actionset);

    if ((replay_actionset != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrActionSetInfo actionset_info;
        actionset_info.SetCaptureId(*(actionSet->GetPointer()));
        actionset_info.SetHandleId(*replay_actionset);
        GetTrackedObjectInfoTable()->AddTrackedXrActionSetInfo(std::move(actionset_info));

        actionset_to_instance_[*replay_actionset] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyActionSet(const ApiCallInfo& call_info,
                                                                XrResult           returnValue,
                                                                format::HandleId   actionSet)
{
    auto        actionset_info = GetTrackedObjectInfoTable()->GetTrackedXrActionSetInfo(actionSet);
    XrActionSet in_actionset   = actionset_info->GetHandleId();

    GetInstanceTable(in_actionset)->DestroyActionSet(in_actionset);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateAction(
    const ApiCallInfo&                                call_info,
    XrResult                                          returnValue,
    format::HandleId                                  actionSet,
    StructPointerDecoder<Decoded_XrActionCreateInfo>* createInfo,
    HandlePointerDecoder<XrAction>*                   action)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (action != nullptr));

    if (!action->IsNull())
    {
        action->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_action      = action->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_action != nullptr));

    auto        actionset_info   = GetTrackedObjectInfoTable()->GetTrackedXrActionSetInfo(actionSet);
    XrActionSet replay_actionset = actionset_info->GetHandleId();
    assert(actionset_to_instance_.find(replay_actionset) != actionset_to_instance_.end());
    XrInstance replay_instance = actionset_to_instance_[replay_actionset];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateAction(replay_actionset, replay_create_info, replay_action);

    if ((replay_action != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrActionInfo action_info;
        action_info.SetCaptureId(*(action->GetPointer()));
        action_info.SetHandleId(*replay_action);
        GetTrackedObjectInfoTable()->AddTrackedXrActionInfo(std::move(action_info));

        action_to_instance_[*replay_action] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyAction(const ApiCallInfo& call_info,
                                                             XrResult           returnValue,
                                                             format::HandleId   action)
{
    auto     action_info = GetTrackedObjectInfoTable()->GetTrackedXrActionInfo(action);
    XrAction in_action   = action_info->GetHandleId();

    GetInstanceTable(in_action)->DestroyAction(in_action);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                                                call_info,
    XrResult                                                          returnValue,
    format::HandleId                                                  instance,
    StructPointerDecoder<Decoded_XrDebugUtilsMessengerCreateInfoEXT>* createInfo,
    HandlePointerDecoder<XrDebugUtilsMessengerEXT>*                   messenger)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (messenger != nullptr));

    if (!messenger->IsNull())
    {
        messenger->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_messenger   = messenger->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_messenger != nullptr));

    auto       instance_info   = GetTrackedObjectInfoTable()->GetTrackedXrInstanceInfo(instance);
    XrInstance replay_instance = instance_info->GetHandleId();

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateDebugUtilsMessengerEXT(replay_instance, replay_create_info, replay_messenger);

    if ((replay_messenger != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrDebugUtilsMessengerEXTInfo messenger_info;
        messenger_info.SetCaptureId(*(messenger->GetPointer()));
        messenger_info.SetHandleId(*replay_messenger);
        GetTrackedObjectInfoTable()->AddTrackedXrDebugUtilsMessengerEXTInfo(std::move(messenger_info));

        debugutilsmessengerEXT_to_instance_[*replay_messenger] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyDebugUtilsMessengerEXT(const ApiCallInfo& call_info,
                                                                             XrResult           returnValue,
                                                                             format::HandleId   messenger)
{
    auto messenger_info = GetTrackedObjectInfoTable()->GetTrackedXrDebugUtilsMessengerEXTInfo(messenger);
    XrDebugUtilsMessengerEXT in_messenger = messenger_info->GetHandleId();

    GetInstanceTable(in_messenger)->DestroyDebugUtilsMessengerEXT(in_messenger);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSpatialAnchorSpaceMSFT(
    const ApiCallInfo&                                                call_info,
    XrResult                                                          returnValue,
    format::HandleId                                                  session,
    StructPointerDecoder<Decoded_XrSpatialAnchorSpaceCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpace>*                                    space)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (space != nullptr));

    if (!space->IsNull())
    {
        space->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = space->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateSpatialAnchorSpaceMSFT(replay_session, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(space->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSpatialAnchorMSFT(
    const ApiCallInfo&                                           call_info,
    XrResult                                                     returnValue,
    format::HandleId                                             session,
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpatialAnchorMSFT>*                   anchor)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (anchor != nullptr));

    if (!anchor->IsNull())
    {
        anchor->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_anchor      = anchor->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_anchor != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateSpatialAnchorMSFT(replay_session, replay_create_info, replay_anchor);

    if ((replay_anchor != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpatialAnchorMSFTInfo anchor_info;
        anchor_info.SetCaptureId(*(anchor->GetPointer()));
        anchor_info.SetHandleId(*replay_anchor);
        GetTrackedObjectInfoTable()->AddTrackedXrSpatialAnchorMSFTInfo(std::move(anchor_info));

        spatialanchorMSFT_to_instance_[*replay_anchor] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroySpatialAnchorMSFT(const ApiCallInfo& call_info,
                                                                        XrResult           returnValue,
                                                                        format::HandleId   anchor)
{
    auto                anchor_info = GetTrackedObjectInfoTable()->GetTrackedXrSpatialAnchorMSFTInfo(anchor);
    XrSpatialAnchorMSFT in_anchor   = anchor_info->GetHandleId();

    GetInstanceTable(in_anchor)->DestroySpatialAnchorMSFT(in_anchor);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSpatialGraphNodeSpaceMSFT(
    const ApiCallInfo&                                                   call_info,
    XrResult                                                             returnValue,
    format::HandleId                                                     session,
    StructPointerDecoder<Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpace>*                                       space)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (space != nullptr));

    if (!space->IsNull())
    {
        space->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = space->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateSpatialGraphNodeSpaceMSFT(replay_session, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(space->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreateHandTrackerEXT(
    const ApiCallInfo&                                        call_info,
    XrResult                                                  returnValue,
    format::HandleId                                          session,
    StructPointerDecoder<Decoded_XrHandTrackerCreateInfoEXT>* createInfo,
    HandlePointerDecoder<XrHandTrackerEXT>*                   handTracker)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (handTracker != nullptr));

    if (!handTracker->IsNull())
    {
        handTracker->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_handtracker = handTracker->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_handtracker != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateHandTrackerEXT(replay_session, replay_create_info, replay_handtracker);

    if ((replay_handtracker != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrHandTrackerEXTInfo handtracker_info;
        handtracker_info.SetCaptureId(*(handTracker->GetPointer()));
        handtracker_info.SetHandleId(*replay_handtracker);
        GetTrackedObjectInfoTable()->AddTrackedXrHandTrackerEXTInfo(std::move(handtracker_info));

        handtrackerEXT_to_instance_[*replay_handtracker] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyHandTrackerEXT(const ApiCallInfo& call_info,
                                                                     XrResult           returnValue,
                                                                     format::HandleId   handTracker)
{
    auto             handTracker_info = GetTrackedObjectInfoTable()->GetTrackedXrHandTrackerEXTInfo(handTracker);
    XrHandTrackerEXT in_handTracker   = handTracker_info->GetHandleId();

    GetInstanceTable(in_handTracker)->DestroyHandTrackerEXT(in_handTracker);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateHandMeshSpaceMSFT(
    const ApiCallInfo&                                           call_info,
    XrResult                                                     returnValue,
    format::HandleId                                             handTracker,
    StructPointerDecoder<Decoded_XrHandMeshSpaceCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpace>*                               space)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (space != nullptr));

    if (!space->IsNull())
    {
        space->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = space->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto             handtracker_info   = GetTrackedObjectInfoTable()->GetTrackedXrHandTrackerEXTInfo(handTracker);
    XrHandTrackerEXT replay_handtracker = handtracker_info->GetHandleId();

    assert(handtrackerEXT_to_instance_.find(replay_handtracker) != handtrackerEXT_to_instance_.end());
    XrInstance replay_instance = handtrackerEXT_to_instance_[replay_handtracker];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateHandMeshSpaceMSFT(replay_handtracker, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(space->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(
    const ApiCallInfo&                         call_info,
    XrResult                                   returnValue,
    format::HandleId                           session,
    uint64_t                                   perceptionAnchor,
    HandlePointerDecoder<XrSpatialAnchorMSFT>* anchor)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert(anchor != nullptr);

    if (!anchor->IsNull())
    {
        anchor->SetHandleLength(1);
    }

    auto replay_anchor = anchor->GetHandlePointer();
    assert(replay_anchor != nullptr);

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateSpatialAnchorFromPerceptionAnchorMSFT(
                              replay_session, reinterpret_cast<IUnknown*>(perceptionAnchor), replay_anchor);

    if ((replay_anchor != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpatialAnchorMSFTInfo anchor_info;
        anchor_info.SetCaptureId(*(anchor->GetPointer()));
        anchor_info.SetHandleId(*replay_anchor);
        GetTrackedObjectInfoTable()->AddTrackedXrSpatialAnchorMSFTInfo(std::move(anchor_info));

        spatialanchorMSFT_to_instance_[*replay_anchor] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreateBodyTrackerFB(
    const ApiCallInfo&                                       call_info,
    XrResult                                                 returnValue,
    format::HandleId                                         session,
    StructPointerDecoder<Decoded_XrBodyTrackerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrBodyTrackerFB>*                   bodyTracker)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (bodyTracker != nullptr));

    if (!bodyTracker->IsNull())
    {
        bodyTracker->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_bodytracker = bodyTracker->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_bodytracker != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateBodyTrackerFB(replay_session, replay_create_info, replay_bodytracker);

    if ((replay_bodytracker != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrBodyTrackerFBInfo bodytracker_info;
        bodytracker_info.SetCaptureId(*(bodyTracker->GetPointer()));
        bodytracker_info.SetHandleId(*replay_bodytracker);
        GetTrackedObjectInfoTable()->AddTrackedXrBodyTrackerFBInfo(std::move(bodytracker_info));

        bodytrackerFB_to_instance_[*replay_bodytracker] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyBodyTrackerFB(const ApiCallInfo& call_info,
                                                                    XrResult           returnValue,
                                                                    format::HandleId   bodyTracker)
{
    auto            info   = GetTrackedObjectInfoTable()->GetTrackedXrBodyTrackerFBInfo(bodyTracker);
    XrBodyTrackerFB handle = info->GetHandleId();

    GetInstanceTable(handle)->DestroyBodyTrackerFB(handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSceneObserverMSFT(
    const ApiCallInfo&                                           call_info,
    XrResult                                                     returnValue,
    format::HandleId                                             session,
    StructPointerDecoder<Decoded_XrSceneObserverCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSceneObserverMSFT>*                   sceneObserver)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (sceneObserver != nullptr));

    if (!sceneObserver->IsNull())
    {
        sceneObserver->SetHandleLength(1);
    }

    auto replay_create_info   = createInfo->GetPointer();
    auto replay_sceneobserver = sceneObserver->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_sceneobserver != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateSceneObserverMSFT(replay_session, replay_create_info, replay_sceneobserver);

    if ((replay_sceneobserver != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSceneObserverMSFTInfo sceneobserver_info;
        sceneobserver_info.SetCaptureId(*(sceneObserver->GetPointer()));
        sceneobserver_info.SetHandleId(*replay_sceneobserver);
        GetTrackedObjectInfoTable()->AddTrackedXrSceneObserverMSFTInfo(std::move(sceneobserver_info));

        sceneobserverMSFT_to_instance_[*replay_sceneobserver] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroySceneObserverMSFT(const ApiCallInfo& call_info,
                                                                        XrResult           returnValue,
                                                                        format::HandleId   sceneObserver)
{
    auto sceneObserver_info = GetTrackedObjectInfoTable()->GetTrackedXrSceneObserverMSFTInfo(sceneObserver);
    XrSceneObserverMSFT in_sceneObserver = sceneObserver_info->GetHandleId();

    GetInstanceTable(in_sceneObserver)->DestroySceneObserverMSFT(in_sceneObserver);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSceneMSFT(
    const ApiCallInfo&                                   call_info,
    XrResult                                             returnValue,
    format::HandleId                                     sceneObserver,
    StructPointerDecoder<Decoded_XrSceneCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSceneMSFT>*                   scene)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (scene != nullptr));

    if (!scene->IsNull())
    {
        scene->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_scene       = scene->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_scene != nullptr));

    auto sceneObserver_info = GetTrackedObjectInfoTable()->GetTrackedXrSceneObserverMSFTInfo(sceneObserver);
    XrSceneObserverMSFT replay_sceneObserver = sceneObserver_info->GetHandleId();

    assert(sceneobserverMSFT_to_instance_.find(replay_sceneObserver) != sceneobserverMSFT_to_instance_.end());
    XrInstance replay_instance = sceneobserverMSFT_to_instance_[replay_sceneObserver];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateSceneMSFT(replay_sceneObserver, replay_create_info, replay_scene);

    if ((replay_scene != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSceneMSFTInfo scene_info;
        scene_info.SetCaptureId(*(scene->GetPointer()));
        scene_info.SetHandleId(*replay_scene);
        GetTrackedObjectInfoTable()->AddTrackedXrSceneMSFTInfo(std::move(scene_info));

        sceneMSFT_to_instance_[*replay_scene] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroySceneMSFT(const ApiCallInfo& call_info,
                                                                XrResult           returnValue,
                                                                format::HandleId   scene)
{
    auto        scene_info = GetTrackedObjectInfoTable()->GetTrackedXrSceneMSFTInfo(scene);
    XrSceneMSFT in_scene   = scene_info->GetHandleId();

    GetInstanceTable(in_scene)->DestroySceneMSFT(in_scene);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateFacialTrackerHTC(
    const ApiCallInfo&                                          call_info,
    XrResult                                                    returnValue,
    format::HandleId                                            session,
    StructPointerDecoder<Decoded_XrFacialTrackerCreateInfoHTC>* createInfo,
    HandlePointerDecoder<XrFacialTrackerHTC>*                   facialTracker)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (facialTracker != nullptr));

    if (!facialTracker->IsNull())
    {
        facialTracker->SetHandleLength(1);
    }

    auto replay_create_info   = createInfo->GetPointer();
    auto replay_facialTracker = facialTracker->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_facialTracker != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateFacialTrackerHTC(replay_session, replay_create_info, replay_facialTracker);

    if ((replay_facialTracker != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrFacialTrackerHTCInfo facialTracker_info;
        facialTracker_info.SetCaptureId(*(facialTracker->GetPointer()));
        facialTracker_info.SetHandleId(*replay_facialTracker);
        GetTrackedObjectInfoTable()->AddTrackedXrFacialTrackerHTCInfo(std::move(facialTracker_info));

        facialtrackerHTC_to_instance_[*replay_facialTracker] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyFacialTrackerHTC(const ApiCallInfo& call_info,
                                                                       XrResult           returnValue,
                                                                       format::HandleId   facialTracker)
{
    auto facialTracker_info             = GetTrackedObjectInfoTable()->GetTrackedXrFacialTrackerHTCInfo(facialTracker);
    XrFacialTrackerHTC in_facialTracker = facialTracker_info->GetHandleId();

    GetInstanceTable(in_facialTracker)->DestroyFacialTrackerHTC(in_facialTracker);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateFoveationProfileFB(
    const ApiCallInfo&                                            call_info,
    XrResult                                                      returnValue,
    format::HandleId                                              session,
    StructPointerDecoder<Decoded_XrFoveationProfileCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrFoveationProfileFB>*                   profile)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (profile != nullptr));

    if (!profile->IsNull())
    {
        profile->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_profile     = profile->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_profile != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateFoveationProfileFB(replay_session, replay_create_info, replay_profile);

    if ((replay_profile != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrFoveationProfileFBInfo profile_info;
        profile_info.SetCaptureId(*(profile->GetPointer()));
        profile_info.SetHandleId(*replay_profile);
        GetTrackedObjectInfoTable()->AddTrackedXrFoveationProfileFBInfo(std::move(profile_info));

        foveationprofileFB_to_instance_[*replay_profile] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyFoveationProfileFB(const ApiCallInfo& call_info,
                                                                         XrResult           returnValue,
                                                                         format::HandleId   profile)
{
    auto                 profile_info = GetTrackedObjectInfoTable()->GetTrackedXrFoveationProfileFBInfo(profile);
    XrFoveationProfileFB in_profile   = profile_info->GetHandleId();

    GetInstanceTable(in_profile)->DestroyFoveationProfileFB(in_profile);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateKeyboardSpaceFB(
    const ApiCallInfo&                                         call_info,
    XrResult                                                   returnValue,
    format::HandleId                                           session,
    StructPointerDecoder<Decoded_XrKeyboardSpaceCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrSpace>*                             keyboardSpace)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (keyboardSpace != nullptr));

    if (!keyboardSpace->IsNull())
    {
        keyboardSpace->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = keyboardSpace->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateKeyboardSpaceFB(replay_session, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(keyboardSpace->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreatePassthroughFB(
    const ApiCallInfo&                                       call_info,
    XrResult                                                 returnValue,
    format::HandleId                                         session,
    StructPointerDecoder<Decoded_XrPassthroughCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrPassthroughFB>*                   outPassthrough)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (outPassthrough != nullptr));

    if (!outPassthrough->IsNull())
    {
        outPassthrough->SetHandleLength(1);
    }

    auto replay_create_info    = createInfo->GetPointer();
    auto replay_outPassthrough = outPassthrough->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outPassthrough != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreatePassthroughFB(replay_session, replay_create_info, replay_outPassthrough);

    if ((replay_outPassthrough != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrPassthroughFBInfo info;
        info.SetCaptureId(*(outPassthrough->GetPointer()));
        info.SetHandleId(*replay_outPassthrough);
        GetTrackedObjectInfoTable()->AddTrackedXrPassthroughFBInfo(std::move(info));

        passthroughFB_to_instance_[*replay_outPassthrough] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyPassthroughFB(const ApiCallInfo& call_info,
                                                                    XrResult           returnValue,
                                                                    format::HandleId   passthrough)
{
    auto            info      = GetTrackedObjectInfoTable()->GetTrackedXrPassthroughFBInfo(passthrough);
    XrPassthroughFB in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroyPassthroughFB(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreatePassthroughLayerFB(
    const ApiCallInfo&                                            call_info,
    XrResult                                                      returnValue,
    format::HandleId                                              session,
    StructPointerDecoder<Decoded_XrPassthroughLayerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrPassthroughLayerFB>*                   outLayer)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (outLayer != nullptr));

    if (!outLayer->IsNull())
    {
        outLayer->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_outLayer    = outLayer->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outLayer != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreatePassthroughLayerFB(replay_session, replay_create_info, replay_outLayer);

    if ((replay_outLayer != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrPassthroughLayerFBInfo info;
        info.SetCaptureId(*(outLayer->GetPointer()));
        info.SetHandleId(*replay_outLayer);
        GetTrackedObjectInfoTable()->AddTrackedXrPassthroughLayerFBInfo(std::move(info));

        passthroughlayerFB_to_instance_[*replay_outLayer] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyPassthroughLayerFB(const ApiCallInfo& call_info,
                                                                         XrResult           returnValue,
                                                                         format::HandleId   layer)
{
    auto                 layer_info = GetTrackedObjectInfoTable()->GetTrackedXrPassthroughLayerFBInfo(layer);
    XrPassthroughLayerFB in_layer   = layer_info->GetHandleId();

    GetInstanceTable(in_layer)->DestroyPassthroughLayerFB(in_layer);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateGeometryInstanceFB(
    const ApiCallInfo&                                            call_info,
    XrResult                                                      returnValue,
    format::HandleId                                              session,
    StructPointerDecoder<Decoded_XrGeometryInstanceCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrGeometryInstanceFB>*                   outGeometryInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (outGeometryInstance != nullptr));

    if (!outGeometryInstance->IsNull())
    {
        outGeometryInstance->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_outhandle   = outGeometryInstance->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateGeometryInstanceFB(replay_session, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrGeometryInstanceFBInfo info;
        info.SetCaptureId(*(outGeometryInstance->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrGeometryInstanceFBInfo(std::move(info));

        geometryinstanceFB_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyGeometryInstanceFB(const ApiCallInfo& call_info,
                                                                         XrResult           returnValue,
                                                                         format::HandleId   instance)
{
    auto                 instance_info = GetTrackedObjectInfoTable()->GetTrackedXrGeometryInstanceFBInfo(instance);
    XrGeometryInstanceFB in_instance   = instance_info->GetHandleId();

    GetInstanceTable(in_instance)->DestroyGeometryInstanceFB(in_instance);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateMarkerSpaceVARJO(
    const ApiCallInfo&                                          call_info,
    XrResult                                                    returnValue,
    format::HandleId                                            session,
    StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoVARJO>* createInfo,
    HandlePointerDecoder<XrSpace>*                              space)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (space != nullptr));

    if (!space->IsNull())
    {
        space->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = space->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateMarkerSpaceVARJO(replay_session, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(space->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSpaceFromCoordinateFrameUIDML(
    const ApiCallInfo&                                           call_info,
    XrResult                                                     returnValue,
    format::HandleId                                             session,
    StructPointerDecoder<Decoded_XrCoordinateSpaceCreateInfoML>* createInfo,
    HandlePointerDecoder<XrSpace>*                               space)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (space != nullptr));

    if (!space->IsNull())
    {
        space->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = space->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateSpaceFromCoordinateFrameUIDML(replay_session, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(space->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreateMarkerDetectorML(
    const ApiCallInfo&                                          call_info,
    XrResult                                                    returnValue,
    format::HandleId                                            session,
    StructPointerDecoder<Decoded_XrMarkerDetectorCreateInfoML>* createInfo,
    HandlePointerDecoder<XrMarkerDetectorML>*                   markerDetector)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (markerDetector != nullptr));

    if (!markerDetector->IsNull())
    {
        markerDetector->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_outhandle   = markerDetector->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateMarkerDetectorML(replay_session, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrMarkerDetectorMLInfo info;
        info.SetCaptureId(*(markerDetector->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrMarkerDetectorMLInfo(std::move(info));

        markerdetectorML_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyMarkerDetectorML(const ApiCallInfo& call_info,
                                                                       XrResult           returnValue,
                                                                       format::HandleId   markerDetector)
{
    auto               info      = GetTrackedObjectInfoTable()->GetTrackedXrMarkerDetectorMLInfo(markerDetector);
    XrMarkerDetectorML in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroyMarkerDetectorML(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateMarkerSpaceML(
    const ApiCallInfo&                                       call_info,
    XrResult                                                 returnValue,
    format::HandleId                                         session,
    StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoML>* createInfo,
    HandlePointerDecoder<XrSpace>*                           space)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (space != nullptr));

    if (!space->IsNull())
    {
        space->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = space->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateMarkerSpaceML(replay_session, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(space->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreateExportedLocalizationMapML(
    const ApiCallInfo&                                 call_info,
    XrResult                                           returnValue,
    format::HandleId                                   session,
    StructPointerDecoder<Decoded_XrUuid>*              mapUuid,
    HandlePointerDecoder<XrExportedLocalizationMapML>* map)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((mapUuid != nullptr) && (map != nullptr));

    if (!map->IsNull())
    {
        map->SetHandleLength(1);
    }

    auto replay_mapuuid   = mapUuid->GetPointer();
    auto replay_outhandle = map->GetHandlePointer();
    assert((replay_mapuuid != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateExportedLocalizationMapML(replay_session, replay_mapuuid, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrExportedLocalizationMapMLInfo info;
        info.SetCaptureId(*(map->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrExportedLocalizationMapMLInfo(std::move(info));

        exportedlocalicationML_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyExportedLocalizationMapML(const ApiCallInfo& call_info,
                                                                                XrResult           returnValue,
                                                                                format::HandleId   map)
{
    auto                        info      = GetTrackedObjectInfoTable()->GetTrackedXrExportedLocalizationMapMLInfo(map);
    XrExportedLocalizationMapML in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroyExportedLocalizationMapML(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSpatialAnchorStoreConnectionMSFT(
    const ApiCallInfo&                                        call_info,
    XrResult                                                  returnValue,
    format::HandleId                                          session,
    HandlePointerDecoder<XrSpatialAnchorStoreConnectionMSFT>* spatialAnchorStore)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert(spatialAnchorStore != nullptr);

    if (!spatialAnchorStore->IsNull())
    {
        spatialAnchorStore->SetHandleLength(1);
    }

    auto replay_outhandle = spatialAnchorStore->GetHandlePointer();
    assert(replay_outhandle != nullptr);

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateSpatialAnchorStoreConnectionMSFT(replay_session, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpatialAnchorStoreConnectionMSFTInfo info;
        info.SetCaptureId(*(spatialAnchorStore->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrSpatialAnchorStoreConnectionMSFTInfo(std::move(info));

        spatialanchorconnectionMSFT_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroySpatialAnchorStoreConnectionMSFT(
    const ApiCallInfo& call_info, XrResult returnValue, format::HandleId spatialAnchorStore)
{
    auto info = GetTrackedObjectInfoTable()->GetTrackedXrSpatialAnchorStoreConnectionMSFTInfo(spatialAnchorStore);
    XrSpatialAnchorStoreConnectionMSFT in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroySpatialAnchorStoreConnectionMSFT(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSpatialAnchorFromPersistedNameMSFT(
    const ApiCallInfo&                                                              call_info,
    XrResult                                                                        returnValue,
    format::HandleId                                                                session,
    StructPointerDecoder<Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT>* spatialAnchorCreateInfo,
    HandlePointerDecoder<XrSpatialAnchorMSFT>*                                      spatialAnchor)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((spatialAnchorCreateInfo != nullptr) && (spatialAnchor != nullptr));

    if (!spatialAnchor->IsNull())
    {
        spatialAnchor->SetHandleLength(1);
    }

    auto replay_create_info = spatialAnchorCreateInfo->GetPointer();
    auto replay_outhandle   = spatialAnchor->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)
            ->CreateSpatialAnchorFromPersistedNameMSFT(replay_session, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpatialAnchorMSFTInfo info;
        info.SetCaptureId(*(spatialAnchor->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrSpatialAnchorMSFTInfo(std::move(info));

        spatialanchorMSFT_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreateFaceTrackerFB(
    const ApiCallInfo&                                       call_info,
    XrResult                                                 returnValue,
    format::HandleId                                         session,
    StructPointerDecoder<Decoded_XrFaceTrackerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrFaceTrackerFB>*                   faceTracker)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (faceTracker != nullptr));

    if (!faceTracker->IsNull())
    {
        faceTracker->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_outhandle   = faceTracker->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateFaceTrackerFB(replay_session, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrFaceTrackerFBInfo info;
        info.SetCaptureId(*(faceTracker->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrFaceTrackerFBInfo(std::move(info));

        facetrackerFB_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyFaceTrackerFB(const ApiCallInfo& call_info,
                                                                    XrResult           returnValue,
                                                                    format::HandleId   faceTracker)
{
    auto            info      = GetTrackedObjectInfoTable()->GetTrackedXrFaceTrackerFBInfo(faceTracker);
    XrFaceTrackerFB in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroyFaceTrackerFB(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateEyeTrackerFB(
    const ApiCallInfo&                                      call_info,
    XrResult                                                returnValue,
    format::HandleId                                        session,
    StructPointerDecoder<Decoded_XrEyeTrackerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrEyeTrackerFB>*                   eyeTracker)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (eyeTracker != nullptr));

    if (!eyeTracker->IsNull())
    {
        eyeTracker->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_outhandle   = eyeTracker->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateEyeTrackerFB(replay_session, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrEyeTrackerFBInfo info;
        info.SetCaptureId(*(eyeTracker->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrEyeTrackerFBInfo(std::move(info));

        eyetrackerFB_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyEyeTrackerFB(const ApiCallInfo& call_info,
                                                                   XrResult           returnValue,
                                                                   format::HandleId   eyeTracker)
{
    auto           info      = GetTrackedObjectInfoTable()->GetTrackedXrEyeTrackerFBInfo(eyeTracker);
    XrEyeTrackerFB in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroyEyeTrackerFB(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateVirtualKeyboardMETA(
    const ApiCallInfo&                                             call_info,
    XrResult                                                       returnValue,
    format::HandleId                                               session,
    StructPointerDecoder<Decoded_XrVirtualKeyboardCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrVirtualKeyboardMETA>*                   keyboard)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (keyboard != nullptr));

    if (!keyboard->IsNull())
    {
        keyboard->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_outhandle   = keyboard->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreateVirtualKeyboardMETA(replay_session, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrVirtualKeyboardMETAInfo info;
        info.SetCaptureId(*(keyboard->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrVirtualKeyboardMETAInfo(std::move(info));

        virtualkeyboardMETA_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyVirtualKeyboardMETA(const ApiCallInfo& call_info,
                                                                          XrResult           returnValue,
                                                                          format::HandleId   keyboard)
{
    auto                  info      = GetTrackedObjectInfoTable()->GetTrackedXrVirtualKeyboardMETAInfo(keyboard);
    XrVirtualKeyboardMETA in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroyVirtualKeyboardMETA(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateVirtualKeyboardSpaceMETA(
    const ApiCallInfo&                                                  call_info,
    XrResult                                                            returnValue,
    format::HandleId                                                    session,
    format::HandleId                                                    keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardSpaceCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrSpace>*                                      keyboardSpace)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (keyboardSpace != nullptr));

    if (!keyboardSpace->IsNull())
    {
        keyboardSpace->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = keyboardSpace->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto                  session_info    = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession             replay_session  = session_info->GetHandleId();
    auto                  keyboard_info   = GetTrackedObjectInfoTable()->GetTrackedXrVirtualKeyboardMETAInfo(keyboard);
    XrVirtualKeyboardMETA replay_keyboard = keyboard_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)
            ->CreateVirtualKeyboardSpaceMETA(replay_session, replay_keyboard, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(keyboardSpace->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSpaceUserFB(
    const ApiCallInfo&                                     call_info,
    XrResult                                               returnValue,
    format::HandleId                                       session,
    StructPointerDecoder<Decoded_XrSpaceUserCreateInfoFB>* info,
    HandlePointerDecoder<XrSpaceUserFB>*                   user)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((info != nullptr) && (user != nullptr));

    if (!user->IsNull())
    {
        user->SetHandleLength(1);
    }

    auto replay_create_info = info->GetPointer();
    auto replay_outhandle   = user->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateSpaceUserFB(replay_session, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceUserFBInfo tracked_info;
        tracked_info.SetCaptureId(*(user->GetPointer()));
        tracked_info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceUserFBInfo(std::move(tracked_info));

        spaceuserFB_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroySpaceUserFB(const ApiCallInfo& call_info,
                                                                  XrResult           returnValue,
                                                                  format::HandleId   user)
{
    auto          info      = GetTrackedObjectInfoTable()->GetTrackedXrSpaceUserFBInfo(user);
    XrSpaceUserFB in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroySpaceUserFB(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreatePassthroughColorLutMETA(
    const ApiCallInfo&                                                 call_info,
    XrResult                                                           returnValue,
    format::HandleId                                                   passthrough,
    StructPointerDecoder<Decoded_XrPassthroughColorLutCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrPassthroughColorLutMETA>*                   colorLut)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (colorLut != nullptr));

    if (!colorLut->IsNull())
    {
        colorLut->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_outhandle   = colorLut->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto            passthrough_info   = GetTrackedObjectInfoTable()->GetTrackedXrPassthroughFBInfo(passthrough);
    XrPassthroughFB replay_passthrough = passthrough_info->GetHandleId();

    assert(passthroughFB_to_instance_.find(replay_passthrough) != passthroughFB_to_instance_.end());
    XrInstance replay_instance = passthroughFB_to_instance_[replay_passthrough];

    XrResult result = GetInstanceTable(replay_instance)
                          ->CreatePassthroughColorLutMETA(replay_passthrough, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrPassthroughColorLutMETAInfo info;
        info.SetCaptureId(*(colorLut->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrPassthroughColorLutMETAInfo(std::move(info));

        passthroughcolorlutMETA_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyPassthroughColorLutMETA(const ApiCallInfo& call_info,
                                                                              XrResult           returnValue,
                                                                              format::HandleId   colorLut)
{
    auto                      info = GetTrackedObjectInfoTable()->GetTrackedXrPassthroughColorLutMETAInfo(colorLut);
    XrPassthroughColorLutMETA in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroyPassthroughColorLutMETA(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateFaceTracker2FB(
    const ApiCallInfo&                                        call_info,
    XrResult                                                  returnValue,
    format::HandleId                                          session,
    StructPointerDecoder<Decoded_XrFaceTrackerCreateInfo2FB>* createInfo,
    HandlePointerDecoder<XrFaceTracker2FB>*                   faceTracker)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (faceTracker != nullptr));

    if (!faceTracker->IsNull())
    {
        faceTracker->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_outhandle   = faceTracker->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateFaceTracker2FB(replay_session, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrFaceTracker2FBInfo info;
        info.SetCaptureId(*(faceTracker->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrFaceTracker2FBInfo(std::move(info));

        facetracker2FB_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyFaceTracker2FB(const ApiCallInfo& call_info,
                                                                     XrResult           returnValue,
                                                                     format::HandleId   faceTracker)
{
    auto             info      = GetTrackedObjectInfoTable()->GetTrackedXrFaceTracker2FBInfo(faceTracker);
    XrFaceTracker2FB in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroyFaceTracker2FB(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreatePassthroughHTC(
    const ApiCallInfo&                                        call_info,
    XrResult                                                  returnValue,
    format::HandleId                                          session,
    StructPointerDecoder<Decoded_XrPassthroughCreateInfoHTC>* createInfo,
    HandlePointerDecoder<XrPassthroughHTC>*                   passthrough)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (passthrough != nullptr));

    if (!passthrough->IsNull())
    {
        passthrough->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_outhandle   = passthrough->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreatePassthroughHTC(replay_session, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrPassthroughHTCInfo info;
        info.SetCaptureId(*(passthrough->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrPassthroughHTCInfo(std::move(info));

        passthroughHTC_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyPassthroughHTC(const ApiCallInfo& call_info,
                                                                     XrResult           returnValue,
                                                                     format::HandleId   passthrough)
{
    auto             info      = GetTrackedObjectInfoTable()->GetTrackedXrPassthroughHTCInfo(passthrough);
    XrPassthroughHTC in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroyPassthroughHTC(in_handle);
}

void OpenXrResourceTrackingConsumer::Process_xrCreateSpatialAnchorHTC(
    const ApiCallInfo&                                          call_info,
    XrResult                                                    returnValue,
    format::HandleId                                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoHTC>* createInfo,
    HandlePointerDecoder<XrSpace>*                              anchor)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (anchor != nullptr));

    if (!anchor->IsNull())
    {
        anchor->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_space       = anchor->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_space != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreateSpatialAnchorHTC(replay_session, replay_create_info, replay_space);

    if ((replay_space != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrSpaceInfo space_info;
        space_info.SetCaptureId(*(anchor->GetPointer()));
        space_info.SetHandleId(*replay_space);
        GetTrackedObjectInfoTable()->AddTrackedXrSpaceInfo(std::move(space_info));

        space_to_instance_[*replay_space] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrCreatePlaneDetectorEXT(
    const ApiCallInfo&                                          call_info,
    XrResult                                                    returnValue,
    format::HandleId                                            session,
    StructPointerDecoder<Decoded_XrPlaneDetectorCreateInfoEXT>* createInfo,
    HandlePointerDecoder<XrPlaneDetectorEXT>*                   planeDetector)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);

    assert((createInfo != nullptr) && (planeDetector != nullptr));

    if (!planeDetector->IsNull())
    {
        planeDetector->SetHandleLength(1);
    }

    auto replay_create_info = createInfo->GetPointer();
    auto replay_outhandle   = planeDetector->GetHandlePointer();
    assert((replay_create_info != nullptr) && (replay_outhandle != nullptr));

    auto      session_info   = GetTrackedObjectInfoTable()->GetTrackedXrSessionInfo(session);
    XrSession replay_session = session_info->GetHandleId();

    assert(session_to_instance_.find(replay_session) != session_to_instance_.end());
    XrInstance replay_instance = session_to_instance_[replay_session];

    XrResult result =
        GetInstanceTable(replay_instance)->CreatePlaneDetectorEXT(replay_session, replay_create_info, replay_outhandle);

    if ((replay_outhandle != nullptr) && (result == XR_SUCCESS))
    {
        TrackedXrPlaneDetectorEXTInfo info;
        info.SetCaptureId(*(planeDetector->GetPointer()));
        info.SetHandleId(*replay_outhandle);
        GetTrackedObjectInfoTable()->AddTrackedXrPlaneDetectorEXTInfo(std::move(info));

        planedetectorEXT_to_instance_[*replay_outhandle] = replay_instance;
    }
}

void OpenXrResourceTrackingConsumer::Process_xrDestroyPlaneDetectorEXT(const ApiCallInfo& call_info,
                                                                       XrResult           returnValue,
                                                                       format::HandleId   planeDetector)
{
    auto               info      = GetTrackedObjectInfoTable()->GetTrackedXrPlaneDetectorEXTInfo(planeDetector);
    XrPlaneDetectorEXT in_handle = info->GetHandleId();

    GetInstanceTable(in_handle)->DestroyPlaneDetectorEXT(in_handle);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
