/*
** Copyright (c) 2024 LunarG, Inc.
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
#include "util/platform.h"
#include "util/defines.h"

#ifdef XR_NO_PROTOTYPES
#undef XR_NO_PROTOTYPES
#endif

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_platform.h"

#include "openxr_replay_consumer_base.h"
#include "vulkan_replay_consumer_base.h"

#include "generated/generated_openxr_enum_to_string.h"
#include "generated/generated_openxr_struct_handle_mappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

OpenXrReplayConsumerBase::OpenXrReplayConsumerBase(std::shared_ptr<application::Application> application,
                                                   const OpenXrReplayOptions&                options) :
    application_(application),
    options_(options), get_instance_proc_addr_(nullptr)
{
    assert(application_ != nullptr);
    object_info_table_ = CommonObjectInfoTable::GetSingleton();
}

OpenXrReplayConsumerBase::~OpenXrReplayConsumerBase() {}

void OpenXrReplayConsumerBase::SetVulkanReplayConsumer(VulkanReplayConsumerBase* vulkan_replay_consumer)
{
    vulkan_replay_consumer_ = vulkan_replay_consumer;
}

void OpenXrReplayConsumerBase::AddInstanceTable(XrInstance instance)
{
    encode::OpenXrInstanceTable& table = instance_tables_[instance];
    encode::LoadOpenXrInstanceTable(get_instance_proc_addr_, instance, &table);
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrInstance handle) const
{
    auto table = instance_tables_.find(handle);
    assert(table != instance_tables_.end());
    return (table != instance_tables_.end()) ? &table->second : nullptr;
}

#if defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)
// NOTE: This won't work on 32-bit builds because OpenXR defines all 32-bit
//       handles as uint64_t breaking the type conversion on each of these
//       override functions.

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrSession handle) const
{
    auto instance = session_to_instance_.find(handle);
    assert(instance != session_to_instance_.end());
    return (instance != session_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrSpace handle) const
{
    auto instance = space_to_instance_.find(handle);
    assert(instance != space_to_instance_.end());
    return (instance != space_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrSwapchain handle) const
{
    auto instance = swapchain_to_instance_.find(handle);
    assert(instance != swapchain_to_instance_.end());
    return (instance != swapchain_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrActionSet handle) const
{
    auto instance = actionset_to_instance_.find(handle);
    assert(instance != actionset_to_instance_.end());
    return (instance != actionset_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrAction handle) const
{
    auto instance = action_to_instance_.find(handle);
    assert(instance != action_to_instance_.end());
    return (instance != action_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrDebugUtilsMessengerEXT handle) const
{
    auto instance = debugutilsmessengerEXT_to_instance_.find(handle);
    assert(instance != debugutilsmessengerEXT_to_instance_.end());
    return (instance != debugutilsmessengerEXT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrSpatialAnchorMSFT handle) const
{
    auto instance = spatialanchorMSFT_to_instance_.find(handle);
    assert(instance != spatialanchorMSFT_to_instance_.end());
    return (instance != spatialanchorMSFT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrHandTrackerEXT handle) const
{
    auto instance = handtrackerEXT_to_instance_.find(handle);
    assert(instance != handtrackerEXT_to_instance_.end());
    return (instance != handtrackerEXT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrBodyTrackerFB handle) const
{
    auto instance = bodytrackerFB_to_instance_.find(handle);
    assert(instance != bodytrackerFB_to_instance_.end());
    return (instance != bodytrackerFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrSceneObserverMSFT handle) const
{
    auto instance = sceneobserverMSFT_to_instance_.find(handle);
    assert(instance != sceneobserverMSFT_to_instance_.end());
    return (instance != sceneobserverMSFT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrSceneMSFT handle) const
{
    auto instance = sceneMSFT_to_instance_.find(handle);
    assert(instance != sceneMSFT_to_instance_.end());
    return (instance != sceneMSFT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrFacialTrackerHTC handle) const
{
    auto instance = facialtrackerHTC_to_instance_.find(handle);
    assert(instance != facialtrackerHTC_to_instance_.end());
    return (instance != facialtrackerHTC_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrFoveationProfileFB handle) const
{
    auto instance = foveationprofileFB_to_instance_.find(handle);
    assert(instance != foveationprofileFB_to_instance_.end());
    return (instance != foveationprofileFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrPassthroughFB handle) const
{
    auto instance = passthroughFB_to_instance_.find(handle);
    assert(instance != passthroughFB_to_instance_.end());
    return (instance != passthroughFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrPassthroughLayerFB handle) const
{
    auto instance = passthroughlayerFB_to_instance_.find(handle);
    assert(instance != passthroughlayerFB_to_instance_.end());
    return (instance != passthroughlayerFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrGeometryInstanceFB handle) const
{
    auto instance = geometryinstanceFB_to_instance_.find(handle);
    assert(instance != geometryinstanceFB_to_instance_.end());
    return (instance != geometryinstanceFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrPlaneDetectorEXT handle) const
{
    auto instance = planedetectorEXT_to_instance_.find(handle);
    assert(instance != planedetectorEXT_to_instance_.end());
    return (instance != planedetectorEXT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrPassthroughHTC handle) const
{
    auto instance = passthroughHTC_to_instance_.find(handle);
    assert(instance != passthroughHTC_to_instance_.end());
    return (instance != passthroughHTC_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrMarkerDetectorML handle) const
{
    auto instance = markerdetectorML_to_instance_.find(handle);
    assert(instance != markerdetectorML_to_instance_.end());
    return (instance != markerdetectorML_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrExportedLocalizationMapML handle) const
{
    auto instance = exportedlocalicationML_to_instance_.find(handle);
    assert(instance != exportedlocalicationML_to_instance_.end());
    return (instance != exportedlocalicationML_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable*
OpenXrReplayConsumerBase::GetInstanceTable(XrSpatialAnchorStoreConnectionMSFT handle) const
{
    auto instance = spatialanchorconnectionMSFT_to_instance_.find(handle);
    assert(instance != spatialanchorconnectionMSFT_to_instance_.end());
    return (instance != spatialanchorconnectionMSFT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrFaceTrackerFB handle) const
{
    auto instance = facetrackerFB_to_instance_.find(handle);
    assert(instance != facetrackerFB_to_instance_.end());
    return (instance != facetrackerFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrEyeTrackerFB handle) const
{
    auto instance = eyetrackerFB_to_instance_.find(handle);
    assert(instance != eyetrackerFB_to_instance_.end());
    return (instance != eyetrackerFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrVirtualKeyboardMETA handle) const
{
    auto instance = virtualkeyboardMETA_to_instance_.find(handle);
    assert(instance != virtualkeyboardMETA_to_instance_.end());
    return (instance != virtualkeyboardMETA_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrSpaceUserFB handle) const
{
    auto instance = spaceuserFB_to_instance_.find(handle);
    assert(instance != spaceuserFB_to_instance_.end());
    return (instance != spaceuserFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrPassthroughColorLutMETA handle) const
{
    auto instance = passthroughcolorlutMETA_to_instance_.find(handle);
    assert(instance != passthroughcolorlutMETA_to_instance_.end());
    return (instance != passthroughcolorlutMETA_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrFaceTracker2FB handle) const
{
    auto instance = facetracker2FB_to_instance_.find(handle);
    assert(instance != facetracker2FB_to_instance_.end());
    return (instance != facetracker2FB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable*
OpenXrReplayConsumerBase::GetInstanceTable(XrSpatialGraphNodeBindingMSFT handle) const
{
    auto instance = spatialgraphnodebindingMSFT_to_instance_.find(handle);
    assert(instance != spatialgraphnodebindingMSFT_to_instance_.end());
    return (instance != spatialgraphnodebindingMSFT_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable* OpenXrReplayConsumerBase::GetInstanceTable(XrTriangleMeshFB handle) const
{
    auto instance = trianglemeshFB_to_instance_.find(handle);
    assert(instance != trianglemeshFB_to_instance_.end());
    return (instance != trianglemeshFB_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}
#endif // defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)

void OpenXrReplayConsumerBase::AssociateParent(XrSession session, XrInstance instance)
{
    session_to_instance_[session] = instance;
}

#if defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)
void OpenXrReplayConsumerBase::AssociateParent(XrSpace space, XrSession session)
{
    space_to_instance_[space] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrSwapchain swapchain, XrSession session)
{
    swapchain_to_instance_[swapchain] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrActionSet action_set, XrInstance instance)
{
    actionset_to_instance_[action_set] = instance;
}

void OpenXrReplayConsumerBase::AssociateParent(XrAction action, XrActionSet action_set)
{
    action_to_instance_[action] = actionset_to_instance_[action_set];
}

void OpenXrReplayConsumerBase::AssociateParent(XrDebugUtilsMessengerEXT debug_messenger, XrInstance instance)
{
    debugutilsmessengerEXT_to_instance_[debug_messenger] = instance;
}

void OpenXrReplayConsumerBase::AssociateParent(XrSpatialAnchorMSFT spatial_anchor, XrSession session)
{
    spatialanchorMSFT_to_instance_[spatial_anchor] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrHandTrackerEXT hand_tracker, XrSession session)
{
    handtrackerEXT_to_instance_[hand_tracker] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrSpace space, XrHandTrackerEXT hand_tracker)
{
    space_to_instance_[space] = handtrackerEXT_to_instance_[hand_tracker];
}

void OpenXrReplayConsumerBase::AssociateParent(XrBodyTrackerFB body_tracker, XrSession session)
{
    bodytrackerFB_to_instance_[body_tracker] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrSceneObserverMSFT scene_observer, XrSession session)
{
    sceneobserverMSFT_to_instance_[scene_observer] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrSceneMSFT scene, XrSceneObserverMSFT scene_observer)
{
    sceneMSFT_to_instance_[scene] = sceneobserverMSFT_to_instance_[scene_observer];
}

void OpenXrReplayConsumerBase::AssociateParent(XrFacialTrackerHTC facial_tracker, XrSession session)
{
    facialtrackerHTC_to_instance_[facial_tracker] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrFoveationProfileFB foveation_profile, XrSession session)
{
    foveationprofileFB_to_instance_[foveation_profile] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrPassthroughFB passthrough, XrSession session)
{
    passthroughFB_to_instance_[passthrough] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrPassthroughLayerFB passthrough_layer, XrSession session)
{
    passthroughlayerFB_to_instance_[passthrough_layer] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrGeometryInstanceFB geometry_instance, XrSession session)
{
    geometryinstanceFB_to_instance_[geometry_instance] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrMarkerDetectorML marker_detector, XrSession session)
{
    markerdetectorML_to_instance_[marker_detector] = session_to_instance_[session];
}
void OpenXrReplayConsumerBase::AssociateParent(XrExportedLocalizationMapML exported_local_map, XrSession session)
{
    exportedlocalicationML_to_instance_[exported_local_map] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrSpatialAnchorStoreConnectionMSFT spatial_anchor_store,
                                               XrSession                          session)
{
    spatialanchorconnectionMSFT_to_instance_[spatial_anchor_store] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrFaceTrackerFB face_tracker, XrSession session)
{
    facetrackerFB_to_instance_[face_tracker] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrEyeTrackerFB eye_tracker, XrSession session)
{
    eyetrackerFB_to_instance_[eye_tracker] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrVirtualKeyboardMETA virtual_keyboard, XrSession session)
{
    virtualkeyboardMETA_to_instance_[virtual_keyboard] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrSpace space, XrVirtualKeyboardMETA virtual_keyboard)
{
    space_to_instance_[space] = virtualkeyboardMETA_to_instance_[virtual_keyboard];
}

void OpenXrReplayConsumerBase::AssociateParent(XrSpaceUserFB space_user, XrSession session)
{
    spaceuserFB_to_instance_[space_user] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrPassthroughColorLutMETA passthrough_color_lut,
                                               XrPassthroughFB           passthrough)
{
    passthroughcolorlutMETA_to_instance_[passthrough_color_lut] = passthroughFB_to_instance_[passthrough];
}

void OpenXrReplayConsumerBase::AssociateParent(XrFaceTracker2FB face_tracker, XrSession session)
{
    facetracker2FB_to_instance_[face_tracker] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrPassthroughHTC passthrough, XrSession session)
{
    passthroughHTC_to_instance_[passthrough] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrPlaneDetectorEXT plane_detector, XrSession session)
{
    planedetectorEXT_to_instance_[plane_detector] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrSpatialGraphNodeBindingMSFT graph_node, XrSession session)
{
    spatialgraphnodebindingMSFT_to_instance_[graph_node] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrTriangleMeshFB triangle_mesh, XrSession session)
{
    trianglemeshFB_to_instance_[triangle_mesh] = session_to_instance_[session];
}

#endif // defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)

void OpenXrReplayConsumerBase::Process_xrInitializeLoaderKHR(
    const ApiCallInfo&                                           call_info,
    XrResult                                                     returnValue,
    StructPointerDecoder<Decoded_XrLoaderInitInfoBaseHeaderKHR>* loaderInitInfo)
{
    const XrLoaderInitInfoBaseHeaderKHR* in_loaderInitInfo = loaderInitInfo->GetPointer();

    // TODO: Call Loader xrInitializeLoader call
    //  XrResult replay_result = xrInitializeLoaderKHR(in_loaderInitInfo);
    XrResult replay_result = XR_SUCCESS;
    CheckResult("xrInitializeLoaderKHR", returnValue, replay_result, call_info);
}

void OpenXrReplayConsumerBase::Process_xrCreateApiLayerInstance(
    const ApiCallInfo&                                  call_info,
    XrResult                                            returnValue,
    StructPointerDecoder<Decoded_XrInstanceCreateInfo>* info,
    StructPointerDecoder<Decoded_XrApiLayerCreateInfo>* apiLayerInfo,
    HandlePointerDecoder<XrInstance>*                   instance)
{

    if (!instance->IsNull())
    {
        instance->SetHandleLength(1);
    }
    XrInstance* replay_instance = instance->GetHandlePointer();

    if (get_instance_proc_addr_ == nullptr)
    {
        get_instance_proc_addr_ = xrGetInstanceProcAddr;
    }

    XrInstanceCreateInfo* create_info = info->GetPointer();
    assert(create_info);

    auto replay_result = xrCreateInstance(create_info, replay_instance);
    CheckResult("xrCreateApiLayerInstance", returnValue, replay_result, call_info);

    AddInstanceTable(*replay_instance);

    // Create the mapping between the recorded and replay instance handles
    AddHandle<OpenXrInstanceInfo>(format::kNullHandleId,
                                  instance->GetPointer(),
                                  instance->GetHandlePointer(),
                                  &CommonObjectInfoTable::AddXrInstanceInfo);
}

void OpenXrReplayConsumerBase::UpdateState_xrCreateSession(
    const ApiCallInfo&                                 call_info,
    XrResult                                           returnValue,
    format::HandleId                                   instance,
    StructPointerDecoder<Decoded_XrSessionCreateInfo>* createInfo,
    HandlePointerDecoder<XrSession>*                   session,
    XrResult                                           replay_result)
{
    XrSession*                   replay_session = session->GetHandlePointer();
    Decoded_XrSessionCreateInfo* decoded_info   = createInfo->GetMetaStructPointer();
    SessionData&                 session_data   = AddSessionData(*replay_session);
    session_data.AddGraphicsBinding(MakeGraphicsBinding(decoded_info));
}

void OpenXrReplayConsumerBase::Process_xrPollEvent(const ApiCallInfo&                               call_info,
                                                   XrResult                                         returnValue,
                                                   format::HandleId                                 instance,
                                                   StructPointerDecoder<Decoded_XrEventDataBuffer>* eventData)
{
    if (returnValue != XR_SUCCESS)
    {
        // Capture did not return an event, skip
        return;
    }

    XrInstance         in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrEventDataBuffer* out_eventData =
        eventData->IsNull() ? nullptr : eventData->AllocateOutputData(1, { XR_TYPE_EVENT_DATA_BUFFER, nullptr });
    InitializeOutputStructNext(eventData);

    XrEventDataBuffer* capture_event = eventData->GetPointer();

    XrResult replay_result;

    // WIP: Put this constant somewhere interesting
    const uint32_t kRetryLimit = 10000;
    uint32_t       retry_count = 0;

    if (out_eventData && capture_event)
    {
        do
        {
            *out_eventData = XrEventDataBuffer{ XR_TYPE_EVENT_DATA_BUFFER };
            replay_result  = GetInstanceTable(in_instance)->PollEvent(in_instance, out_eventData);

            retry_count++;

            if (capture_event->type != out_eventData->type)
            {
                if (replay_result == XR_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("Skipping event %u", out_eventData->type);
                }
                else
                {
                    // Yield and retry
                    std::this_thread::sleep_for(std::chrono::nanoseconds(1));
                }
            }
        } while ((retry_count < kRetryLimit) && capture_event->type != out_eventData->type);
        if (capture_event->type != out_eventData->type)
        {
            replay_result = XR_ERROR_RUNTIME_FAILURE; // Runtime never gave us the event we were looking for
        }
    }
    else
    {
        // Event data can't be null
        replay_result = XR_ERROR_VALIDATION_FAILURE;
    }

    CheckResult("xrPollEvent", returnValue, replay_result, call_info);
}

void OpenXrReplayConsumerBase::UpdateState_xrWaitFrame(const ApiCallInfo&                             call_info,
                                                       XrResult                                       returnValue,
                                                       format::HandleId                               session,
                                                       StructPointerDecoder<Decoded_XrFrameWaitInfo>* frameWaitInfo,
                                                       StructPointerDecoder<Decoded_XrFrameState>*    frameState,
                                                       XrResult                                       replay_result)
{

    // Store wait frame information for this session if needed later
    XrSession    in_session   = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    SessionData& session_data = GetSessionData(in_session);
    session_data.SetDisplayTime(frameState->GetOutputPointer()->predictedDisplayTime);
}

void OpenXrReplayConsumerBase::UpdateState_xrEnumerateReferenceSpaces(const ApiCallInfo&        call_info,
                                                                      XrResult                  returnValue,
                                                                      format::HandleId          session,
                                                                      uint32_t                  spaceCapacityInput,
                                                                      PointerDecoder<uint32_t>* spaceCountOutput,
                                                                      PointerDecoder<XrReferenceSpaceType>* spaces,
                                                                      XrResult replay_result)
{
    // Store wait frame information for this session if needed later
    XrSession             in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    uint32_t*             out_spaceCountOutput = spaceCountOutput->GetOutputPointer();
    XrReferenceSpaceType* out_spaces           = spaces->GetOutputPointer();

    if (out_spaceCountOutput && *out_spaceCountOutput && out_spaces)
    {
        SessionData& session_data = GetSessionData(in_session);
        session_data.AddReferenceSpaces(*out_spaceCountOutput, out_spaces);
    }
}

void* OpenXrReplayConsumerBase::PreProcessExternalObject(uint64_t          object_id,
                                                         format::ApiCallId call_id,
                                                         const char*       call_name)
{
    void* object = nullptr;

    if (call_id == format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR)
    {
        // TODO: Return jobject
    }
    else if (format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT)
    {
        // TODO: Return perceptionAnchor
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                             call_name);
    }

    return object;
}

void OpenXrReplayConsumerBase::PostProcessExternalObject(
    XrResult replay_result, uint64_t object_id, void* object, format::ApiCallId call_id, const char* call_name)
{
    GFXRECON_UNREFERENCED_PARAMETER(replay_result);
    GFXRECON_UNREFERENCED_PARAMETER(object_id);
    GFXRECON_UNREFERENCED_PARAMETER(object);
    GFXRECON_UNREFERENCED_PARAMETER(call_id);
    GFXRECON_UNREFERENCED_PARAMETER(call_name);
}

void OpenXrReplayConsumerBase::CheckResult(const char*                func_name,
                                           XrResult                   original,
                                           XrResult                   replay,
                                           const decode::ApiCallInfo& call_info)
{
    if (original != replay)
    {
        if (replay < 0)
        {
            // Raise a fatal error if replay produced an error that did not occur during capture.  Format not supported
            // errors are not treated as fatal, but will be reported as warnings below, allowing the replay to attempt
            // to continue for the case where an application may have queried for formats that it did not use.
            GFXRECON_LOG_FATAL(
                "API call at index: %d thread: %d %s returned error value %s that does not match the result from the "
                "capture file: %s. Replay cannot continue.",
                call_info.index,
                call_info.thread_id,
                func_name,
                util::ToString<XrResult>(replay).c_str(),
                util::ToString<XrResult>(original).c_str());

            RaiseFatalError(enumutil::GetResultDescription(replay));
        }
        else if (!((replay == XR_SUCCESS) &&
                   ((original == XR_TIMEOUT_EXPIRED) || (original == XR_SESSION_LOSS_PENDING) ||
                    (original == XR_EVENT_UNAVAILABLE) || (original == XR_SPACE_BOUNDS_UNAVAILABLE) ||
                    (original == XR_SESSION_NOT_FOCUSED) || (original == XR_FRAME_DISCARDED))))
        {
            // Report differences between replay result and capture result, unless the replay results indicates
            // that a wait operation completed before the original or a WSI function succeeded when the original failed.
            GFXRECON_LOG_WARNING(
                "API call %s returned value %s that does not match return value from capture file: %s.",
                func_name,
                util::ToString<XrResult>(replay).c_str(),
                util::ToString<XrResult>(original).c_str());
        }
    }
}

void OpenXrReplayConsumerBase::RaiseFatalError(const char* message) const
{
    // TODO: Should there be a default action if no error handler has been provided?
    if (fatal_error_handler_ != nullptr)
    {
        fatal_error_handler_(message);
    }
}

OpenXrReplayConsumerBase::GraphicsBinding
OpenXrReplayConsumerBase::MakeGraphicsBinding(Decoded_XrSessionCreateInfo* create_info)
{
    auto* vk_binding = gfxrecon::decode::GetNextMetaStruct<Decoded_XrGraphicsBindingVulkanKHR>(create_info->next);
    if (vk_binding)
    {
        assert(vulkan_replay_consumer_);
        assert(vk_binding->decoded_value);

        return GraphicsBinding(VulkanGraphicsBinding(*vulkan_replay_consumer_, *vk_binding));
    }

    // Add additional bindings below this

    // Default constructed object !IsValid()
    return GraphicsBinding();
}

OpenXrReplayConsumerBase::VulkanGraphicsBinding::VulkanGraphicsBinding(
    VulkanReplayConsumerBase& vulkan_consumer, const Decoded_XrGraphicsBindingVulkanKHR& xr_binding) :
    XrGraphicsBindingVulkanKHR(*xr_binding.decoded_value),
    vulkan_consumer(&vulkan_consumer), instance_table(vulkan_consumer.GetInstanceTable(physicalDevice)),
    device_table(vulkan_consumer.GetDeviceTable(device)), instance_id(xr_binding.instance),
    physicalDevice_id(xr_binding.physicalDevice), device_id(xr_binding.device)
{
    next = nullptr; // We don't have a safe (deep) copy of the original so stub out the copies downchain pointer

    //
    device_table->GetDeviceQueue(device, queueFamilyIndex, queueIndex, &queue);
}

bool OpenXrReplayConsumerBase::SessionData::AddGraphicsBinding(const GraphicsBinding& binding)
{
    graphics_binding_ = binding;
    return graphics_binding_.IsValid();
}

void OpenXrReplayConsumerBase::SessionData::AddReferenceSpaces(uint32_t                    count,
                                                               const XrReferenceSpaceType* replay_spaces)
{
    reference_spaces_.clear();
    for (uint32_t space = 0; space < count; space++)
    {
        reference_spaces_.insert(replay_spaces[space]);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
