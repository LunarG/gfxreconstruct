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

#ifndef GFXRECON_DECODE_OPENXR_RESOURCE_TRACKING_CONSUMER_H
#define GFXRECON_DECODE_OPENXR_RESOURCE_TRACKING_CONSUMER_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "decode/openxr_tracked_object_info.h"
#include "decode/openxr_tracked_object_info_table.h"
#include "decode/openxr_replay_options.h"
#include "format/platform_types.h"
#include "generated/generated_openxr_consumer.h"
#include "generated/generated_openxr_dispatch_table.h"

#include "util/defines.h"

#include "openxr/openxr.h"

#include <cstdio>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class OpenXrResourceTrackingConsumer : public OpenXrConsumer
{
  public:
    OpenXrResourceTrackingConsumer(const OpenXrReplayOptions&    options,
                                   OpenXrTrackedObjectInfoTable* tracked_object_info_table);

    virtual ~OpenXrResourceTrackingConsumer() override;

    void InitializeLoader();

    void AddInstanceTable(XrInstance instance);

    const encode::OpenXrInstanceTable* GetInstanceTable(XrInstance handle) const;
#if defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)
    // NOTE: This won't work on 32-bit builds because OpenXR defines all 32-bit
    //       handles as uint64_t breaking the type conversion on each of these
    //       override functions.
    const encode::OpenXrInstanceTable* GetInstanceTable(XrSession handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrSpace handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrSwapchain handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrActionSet handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrAction handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrDebugUtilsMessengerEXT handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrSpatialAnchorMSFT handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrHandTrackerEXT handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrBodyTrackerFB handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrSceneObserverMSFT handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrSceneMSFT handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrFacialTrackerHTC handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrFoveationProfileFB handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrPassthroughFB handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrPassthroughLayerFB handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrGeometryInstanceFB handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrPlaneDetectorEXT handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrPassthroughHTC handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrMarkerDetectorML handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrExportedLocalizationMapML handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrSpatialAnchorStoreConnectionMSFT handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrFaceTrackerFB handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrEyeTrackerFB handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrVirtualKeyboardMETA handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrSpaceUserFB handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrPassthroughColorLutMETA handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrFaceTracker2FB handle) const;
#endif // defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)

    void Process_xrCreateInstance(const ApiCallInfo&                                  call_info,
                                  XrResult                                            returnValue,
                                  StructPointerDecoder<Decoded_XrInstanceCreateInfo>* pCreateInfo,
                                  HandlePointerDecoder<XrInstance>*                   pInstance);
    void Process_xrDestroyInstance(const ApiCallInfo& call_info, format::HandleId instance);
    void Process_xrCreateSession(const ApiCallInfo&                                 call_info,
                                 XrResult                                           returnValue,
                                 format::HandleId                                   instance,
                                 StructPointerDecoder<Decoded_XrSessionCreateInfo>* createInfo,
                                 HandlePointerDecoder<XrSession>*                   session) override;
    void
    Process_xrDestroySession(const ApiCallInfo& call_info, XrResult returnValue, format::HandleId session) override;
    void Process_xrCreateReferenceSpace(const ApiCallInfo&                                        call_info,
                                        XrResult                                                  returnValue,
                                        format::HandleId                                          session,
                                        StructPointerDecoder<Decoded_XrReferenceSpaceCreateInfo>* createInfo,
                                        HandlePointerDecoder<XrSpace>*                            space) override;
    void Process_xrCreateActionSpace(const ApiCallInfo&                                     call_info,
                                     XrResult                                               returnValue,
                                     format::HandleId                                       session,
                                     StructPointerDecoder<Decoded_XrActionSpaceCreateInfo>* createInfo,
                                     HandlePointerDecoder<XrSpace>*                         space) override;
    void Process_xrDestroySpace(const ApiCallInfo& call_info, XrResult returnValue, format::HandleId space) override;
    void Process_xrCreateSwapchain(const ApiCallInfo&                                   call_info,
                                   XrResult                                             returnValue,
                                   format::HandleId                                     session,
                                   StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* createInfo,
                                   HandlePointerDecoder<XrSwapchain>*                   swapchain) override;
    void
    Process_xrDestroySwapchain(const ApiCallInfo& call_info, XrResult returnValue, format::HandleId swapchain) override;
    void Process_xrCreateActionSet(const ApiCallInfo&                                   call_info,
                                   XrResult                                             returnValue,
                                   format::HandleId                                     instance,
                                   StructPointerDecoder<Decoded_XrActionSetCreateInfo>* createInfo,
                                   HandlePointerDecoder<XrActionSet>*                   actionSet) override;
    void
    Process_xrDestroyActionSet(const ApiCallInfo& call_info, XrResult returnValue, format::HandleId actionSet) override;
    void Process_xrCreateAction(const ApiCallInfo&                                call_info,
                                XrResult                                          returnValue,
                                format::HandleId                                  actionSet,
                                StructPointerDecoder<Decoded_XrActionCreateInfo>* createInfo,
                                HandlePointerDecoder<XrAction>*                   action) override;
    void Process_xrDestroyAction(const ApiCallInfo& call_info, XrResult returnValue, format::HandleId action) override;

    void
    Process_xrCreateDebugUtilsMessengerEXT(const ApiCallInfo& call_info,
                                           XrResult           returnValue,
                                           format::HandleId   instance,
                                           StructPointerDecoder<Decoded_XrDebugUtilsMessengerCreateInfoEXT>* createInfo,
                                           HandlePointerDecoder<XrDebugUtilsMessengerEXT>* messenger) override;

    void Process_xrDestroyDebugUtilsMessengerEXT(const ApiCallInfo& call_info,
                                                 XrResult           returnValue,
                                                 format::HandleId   messenger) override;

    void Process_xrCreateSpatialAnchorMSFT(const ApiCallInfo&                                           call_info,
                                           XrResult                                                     returnValue,
                                           format::HandleId                                             session,
                                           StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoMSFT>* createInfo,
                                           HandlePointerDecoder<XrSpatialAnchorMSFT>* anchor) override;

    void
    Process_xrCreateSpatialAnchorSpaceMSFT(const ApiCallInfo& call_info,
                                           XrResult           returnValue,
                                           format::HandleId   session,
                                           StructPointerDecoder<Decoded_XrSpatialAnchorSpaceCreateInfoMSFT>* createInfo,
                                           HandlePointerDecoder<XrSpace>* space) override;

    void Process_xrDestroySpatialAnchorMSFT(const ApiCallInfo& call_info,
                                            XrResult           returnValue,
                                            format::HandleId   anchor) override;

    void Process_xrCreateSpatialGraphNodeSpaceMSFT(
        const ApiCallInfo&                                                   call_info,
        XrResult                                                             returnValue,
        format::HandleId                                                     session,
        StructPointerDecoder<Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpace>*                                       space) override;

    void Process_xrCreateHandTrackerEXT(const ApiCallInfo&                                        call_info,
                                        XrResult                                                  returnValue,
                                        format::HandleId                                          session,
                                        StructPointerDecoder<Decoded_XrHandTrackerCreateInfoEXT>* createInfo,
                                        HandlePointerDecoder<XrHandTrackerEXT>*                   handTracker) override;

    void Process_xrDestroyHandTrackerEXT(const ApiCallInfo& call_info,
                                         XrResult           returnValue,
                                         format::HandleId   handTracker) override;

    void Process_xrCreateHandMeshSpaceMSFT(const ApiCallInfo&                                           call_info,
                                           XrResult                                                     returnValue,
                                           format::HandleId                                             handTracker,
                                           StructPointerDecoder<Decoded_XrHandMeshSpaceCreateInfoMSFT>* createInfo,
                                           HandlePointerDecoder<XrSpace>*                               space) override;

    void
    Process_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(const ApiCallInfo&                         call_info,
                                                          XrResult                                   returnValue,
                                                          format::HandleId                           session,
                                                          uint64_t                                   perceptionAnchor,
                                                          HandlePointerDecoder<XrSpatialAnchorMSFT>* anchor) override;

    void Process_xrCreateBodyTrackerFB(const ApiCallInfo&                                       call_info,
                                       XrResult                                                 returnValue,
                                       format::HandleId                                         session,
                                       StructPointerDecoder<Decoded_XrBodyTrackerCreateInfoFB>* createInfo,
                                       HandlePointerDecoder<XrBodyTrackerFB>*                   bodyTracker) override;

    void Process_xrDestroyBodyTrackerFB(const ApiCallInfo& call_info,
                                        XrResult           returnValue,
                                        format::HandleId   bodyTracker) override;

    void Process_xrCreateSceneObserverMSFT(const ApiCallInfo&                                           call_info,
                                           XrResult                                                     returnValue,
                                           format::HandleId                                             session,
                                           StructPointerDecoder<Decoded_XrSceneObserverCreateInfoMSFT>* createInfo,
                                           HandlePointerDecoder<XrSceneObserverMSFT>* sceneObserver) override;

    void Process_xrDestroySceneObserverMSFT(const ApiCallInfo& call_info,
                                            XrResult           returnValue,
                                            format::HandleId   sceneObserver) override;

    void Process_xrCreateSceneMSFT(const ApiCallInfo&                                   call_info,
                                   XrResult                                             returnValue,
                                   format::HandleId                                     sceneObserver,
                                   StructPointerDecoder<Decoded_XrSceneCreateInfoMSFT>* createInfo,
                                   HandlePointerDecoder<XrSceneMSFT>*                   scene) override;

    void
    Process_xrDestroySceneMSFT(const ApiCallInfo& call_info, XrResult returnValue, format::HandleId scene) override;

    void Process_xrCreateFacialTrackerHTC(const ApiCallInfo&                                          call_info,
                                          XrResult                                                    returnValue,
                                          format::HandleId                                            session,
                                          StructPointerDecoder<Decoded_XrFacialTrackerCreateInfoHTC>* createInfo,
                                          HandlePointerDecoder<XrFacialTrackerHTC>* facialTracker) override;

    void Process_xrDestroyFacialTrackerHTC(const ApiCallInfo& call_info,
                                           XrResult           returnValue,
                                           format::HandleId   facialTracker) override;

    void Process_xrCreateFoveationProfileFB(const ApiCallInfo&                                            call_info,
                                            XrResult                                                      returnValue,
                                            format::HandleId                                              session,
                                            StructPointerDecoder<Decoded_XrFoveationProfileCreateInfoFB>* createInfo,
                                            HandlePointerDecoder<XrFoveationProfileFB>* profile) override;

    void Process_xrDestroyFoveationProfileFB(const ApiCallInfo& call_info,
                                             XrResult           returnValue,
                                             format::HandleId   profile) override;

    void Process_xrCreateKeyboardSpaceFB(const ApiCallInfo&                                         call_info,
                                         XrResult                                                   returnValue,
                                         format::HandleId                                           session,
                                         StructPointerDecoder<Decoded_XrKeyboardSpaceCreateInfoFB>* createInfo,
                                         HandlePointerDecoder<XrSpace>* keyboardSpace) override;

    void Process_xrCreatePassthroughFB(const ApiCallInfo&                                       call_info,
                                       XrResult                                                 returnValue,
                                       format::HandleId                                         session,
                                       StructPointerDecoder<Decoded_XrPassthroughCreateInfoFB>* createInfo,
                                       HandlePointerDecoder<XrPassthroughFB>* outPassthrough) override;

    void Process_xrDestroyPassthroughFB(const ApiCallInfo& call_info,
                                        XrResult           returnValue,
                                        format::HandleId   passthrough) override;

    void Process_xrCreatePassthroughLayerFB(const ApiCallInfo&                                            call_info,
                                            XrResult                                                      returnValue,
                                            format::HandleId                                              session,
                                            StructPointerDecoder<Decoded_XrPassthroughLayerCreateInfoFB>* createInfo,
                                            HandlePointerDecoder<XrPassthroughLayerFB>* outLayer) override;

    void Process_xrDestroyPassthroughLayerFB(const ApiCallInfo& call_info,
                                             XrResult           returnValue,
                                             format::HandleId   layer) override;

    void Process_xrCreateGeometryInstanceFB(const ApiCallInfo&                                            call_info,
                                            XrResult                                                      returnValue,
                                            format::HandleId                                              session,
                                            StructPointerDecoder<Decoded_XrGeometryInstanceCreateInfoFB>* createInfo,
                                            HandlePointerDecoder<XrGeometryInstanceFB>* outGeometryInstance) override;

    void Process_xrDestroyGeometryInstanceFB(const ApiCallInfo& call_info,
                                             XrResult           returnValue,
                                             format::HandleId   instance) override;

    void Process_xrCreateMarkerSpaceVARJO(const ApiCallInfo&                                          call_info,
                                          XrResult                                                    returnValue,
                                          format::HandleId                                            session,
                                          StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoVARJO>* createInfo,
                                          HandlePointerDecoder<XrSpace>*                              space) override;

    void Process_xrCreateSpaceFromCoordinateFrameUIDML(
        const ApiCallInfo&                                           call_info,
        XrResult                                                     returnValue,
        format::HandleId                                             session,
        StructPointerDecoder<Decoded_XrCoordinateSpaceCreateInfoML>* createInfo,
        HandlePointerDecoder<XrSpace>*                               space) override;

    void Process_xrCreateMarkerDetectorML(const ApiCallInfo&                                          call_info,
                                          XrResult                                                    returnValue,
                                          format::HandleId                                            session,
                                          StructPointerDecoder<Decoded_XrMarkerDetectorCreateInfoML>* createInfo,
                                          HandlePointerDecoder<XrMarkerDetectorML>* markerDetector) override;

    void Process_xrDestroyMarkerDetectorML(const ApiCallInfo& call_info,
                                           XrResult           returnValue,
                                           format::HandleId   markerDetector) override;

    void Process_xrCreateMarkerSpaceML(const ApiCallInfo&                                       call_info,
                                       XrResult                                                 returnValue,
                                       format::HandleId                                         session,
                                       StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoML>* createInfo,
                                       HandlePointerDecoder<XrSpace>*                           space) override;

    void Process_xrCreateExportedLocalizationMapML(const ApiCallInfo&                                 call_info,
                                                   XrResult                                           returnValue,
                                                   format::HandleId                                   session,
                                                   StructPointerDecoder<Decoded_XrUuidEXT>*           mapUuid,
                                                   HandlePointerDecoder<XrExportedLocalizationMapML>* map) override;

    void Process_xrDestroyExportedLocalizationMapML(const ApiCallInfo& call_info,
                                                    XrResult           returnValue,
                                                    format::HandleId   map) override;

    void Process_xrCreateSpatialAnchorStoreConnectionMSFT(
        const ApiCallInfo&                                        call_info,
        XrResult                                                  returnValue,
        format::HandleId                                          session,
        HandlePointerDecoder<XrSpatialAnchorStoreConnectionMSFT>* spatialAnchorStore) override;

    void Process_xrDestroySpatialAnchorStoreConnectionMSFT(const ApiCallInfo& call_info,
                                                           XrResult           returnValue,
                                                           format::HandleId   spatialAnchorStore) override;

    void Process_xrCreateSpatialAnchorFromPersistedNameMSFT(
        const ApiCallInfo&                                                              call_info,
        XrResult                                                                        returnValue,
        format::HandleId                                                                session,
        StructPointerDecoder<Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT>* spatialAnchorCreateInfo,
        HandlePointerDecoder<XrSpatialAnchorMSFT>*                                      spatialAnchor) override;

    void Process_xrCreateFaceTrackerFB(const ApiCallInfo&                                       call_info,
                                       XrResult                                                 returnValue,
                                       format::HandleId                                         session,
                                       StructPointerDecoder<Decoded_XrFaceTrackerCreateInfoFB>* createInfo,
                                       HandlePointerDecoder<XrFaceTrackerFB>*                   faceTracker) override;

    void Process_xrDestroyFaceTrackerFB(const ApiCallInfo& call_info,
                                        XrResult           returnValue,
                                        format::HandleId   faceTracker) override;

    void Process_xrCreateEyeTrackerFB(const ApiCallInfo&                                      call_info,
                                      XrResult                                                returnValue,
                                      format::HandleId                                        session,
                                      StructPointerDecoder<Decoded_XrEyeTrackerCreateInfoFB>* createInfo,
                                      HandlePointerDecoder<XrEyeTrackerFB>*                   eyeTracker) override;

    void Process_xrDestroyEyeTrackerFB(const ApiCallInfo& call_info,
                                       XrResult           returnValue,
                                       format::HandleId   eyeTracker) override;

    void Process_xrCreateVirtualKeyboardMETA(const ApiCallInfo&                                             call_info,
                                             XrResult                                                       returnValue,
                                             format::HandleId                                               session,
                                             StructPointerDecoder<Decoded_XrVirtualKeyboardCreateInfoMETA>* createInfo,
                                             HandlePointerDecoder<XrVirtualKeyboardMETA>* keyboard) override;

    void Process_xrDestroyVirtualKeyboardMETA(const ApiCallInfo& call_info,
                                              XrResult           returnValue,
                                              format::HandleId   keyboard) override;

    void Process_xrCreateVirtualKeyboardSpaceMETA(
        const ApiCallInfo&                                                  call_info,
        XrResult                                                            returnValue,
        format::HandleId                                                    session,
        format::HandleId                                                    keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardSpaceCreateInfoMETA>* createInfo,
        HandlePointerDecoder<XrSpace>*                                      keyboardSpace) override;

    void Process_xrCreateSpaceUserFB(const ApiCallInfo&                                     call_info,
                                     XrResult                                               returnValue,
                                     format::HandleId                                       session,
                                     StructPointerDecoder<Decoded_XrSpaceUserCreateInfoFB>* info,
                                     HandlePointerDecoder<XrSpaceUserFB>*                   user) override;

    void
    Process_xrDestroySpaceUserFB(const ApiCallInfo& call_info, XrResult returnValue, format::HandleId user) override;

    void Process_xrCreatePassthroughColorLutMETA(
        const ApiCallInfo&                                                 call_info,
        XrResult                                                           returnValue,
        format::HandleId                                                   passthrough,
        StructPointerDecoder<Decoded_XrPassthroughColorLutCreateInfoMETA>* createInfo,
        HandlePointerDecoder<XrPassthroughColorLutMETA>*                   colorLut) override;

    void Process_xrDestroyPassthroughColorLutMETA(const ApiCallInfo& call_info,
                                                  XrResult           returnValue,
                                                  format::HandleId   colorLut) override;

    void Process_xrCreateFaceTracker2FB(const ApiCallInfo&                                        call_info,
                                        XrResult                                                  returnValue,
                                        format::HandleId                                          session,
                                        StructPointerDecoder<Decoded_XrFaceTrackerCreateInfo2FB>* createInfo,
                                        HandlePointerDecoder<XrFaceTracker2FB>*                   faceTracker) override;

    void Process_xrDestroyFaceTracker2FB(const ApiCallInfo& call_info,
                                         XrResult           returnValue,
                                         format::HandleId   faceTracker) override;

    void Process_xrCreatePassthroughHTC(const ApiCallInfo&                                        call_info,
                                        XrResult                                                  returnValue,
                                        format::HandleId                                          session,
                                        StructPointerDecoder<Decoded_XrPassthroughCreateInfoHTC>* createInfo,
                                        HandlePointerDecoder<XrPassthroughHTC>*                   passthrough) override;

    void Process_xrDestroyPassthroughHTC(const ApiCallInfo& call_info,
                                         XrResult           returnValue,
                                         format::HandleId   passthrough) override;

    void Process_xrCreateSpatialAnchorHTC(const ApiCallInfo&                                          call_info,
                                          XrResult                                                    returnValue,
                                          format::HandleId                                            session,
                                          StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoHTC>* createInfo,
                                          HandlePointerDecoder<XrSpace>*                              anchor) override;

    void Process_xrCreatePlaneDetectorEXT(const ApiCallInfo&                                          call_info,
                                          XrResult                                                    returnValue,
                                          format::HandleId                                            session,
                                          StructPointerDecoder<Decoded_XrPlaneDetectorCreateInfoEXT>* createInfo,
                                          HandlePointerDecoder<XrPlaneDetectorEXT>* planeDetector) override;

    void Process_xrDestroyPlaneDetectorEXT(const ApiCallInfo& call_info,
                                           XrResult           returnValue,
                                           format::HandleId   planeDetector) override;

  protected:
    OpenXrTrackedObjectInfoTable* GetTrackedObjectInfoTable()
    {
        return tracked_object_info_table_;
    }

  private:
    util::platform::LibraryHandle loader_handle_;

    // map to function pointers to API calls
    std::unordered_map<XrInstance, encode::OpenXrInstanceTable>        instance_tables_;
    std::unordered_map<XrSession, XrInstance>                          session_to_instance_;
    std::unordered_map<XrSpace, XrInstance>                            space_to_instance_;
    std::unordered_map<XrSwapchain, XrInstance>                        swapchain_to_instance_;
    std::unordered_map<XrActionSet, XrInstance>                        actionset_to_instance_;
    std::unordered_map<XrAction, XrInstance>                           action_to_instance_;
    std::unordered_map<XrDebugUtilsMessengerEXT, XrInstance>           debugutilsmessengerEXT_to_instance_;
    std::unordered_map<XrSpatialAnchorMSFT, XrInstance>                spatialanchorMSFT_to_instance_;
    std::unordered_map<XrHandTrackerEXT, XrInstance>                   handtrackerEXT_to_instance_;
    std::unordered_map<XrBodyTrackerFB, XrInstance>                    bodytrackerFB_to_instance_;
    std::unordered_map<XrSceneObserverMSFT, XrInstance>                sceneobserverMSFT_to_instance_;
    std::unordered_map<XrSceneMSFT, XrInstance>                        sceneMSFT_to_instance_;
    std::unordered_map<XrFacialTrackerHTC, XrInstance>                 facialtrackerHTC_to_instance_;
    std::unordered_map<XrFoveationProfileFB, XrInstance>               foveationprofileFB_to_instance_;
    std::unordered_map<XrPassthroughFB, XrInstance>                    passthroughFB_to_instance_;
    std::unordered_map<XrPassthroughLayerFB, XrInstance>               passthroughlayerFB_to_instance_;
    std::unordered_map<XrGeometryInstanceFB, XrInstance>               geometryinstanceFB_to_instance_;
    std::unordered_map<XrPlaneDetectorEXT, XrInstance>                 planedetectorEXT_to_instance_;
    std::unordered_map<XrPassthroughHTC, XrInstance>                   passthroughHTC_to_instance_;
    std::unordered_map<XrMarkerDetectorML, XrInstance>                 markerdetectorML_to_instance_;
    std::unordered_map<XrExportedLocalizationMapML, XrInstance>        exportedlocalicationML_to_instance_;
    std::unordered_map<XrSpatialAnchorStoreConnectionMSFT, XrInstance> spatialanchorconnectionMSFT_to_instance_;
    std::unordered_map<XrFaceTrackerFB, XrInstance>                    facetrackerFB_to_instance_;
    std::unordered_map<XrEyeTrackerFB, XrInstance>                     eyetrackerFB_to_instance_;
    std::unordered_map<XrVirtualKeyboardMETA, XrInstance>              virtualkeyboardMETA_to_instance_;
    std::unordered_map<XrSpaceUserFB, XrInstance>                      spaceuserFB_to_instance_;
    std::unordered_map<XrPassthroughColorLutMETA, XrInstance>          passthroughcolorlutMETA_to_instance_;
    std::unordered_map<XrFaceTracker2FB, XrInstance>                   facetracker2FB_to_instance_;

    // funtion pointers to the API calls that will be made during the first pass of replay
    PFN_xrCreateInstance      create_instance_function_;
    PFN_xrGetInstanceProcAddr get_instance_proc_addr_;

    OpenXrReplayOptions           options_;
    OpenXrTrackedObjectInfoTable* tracked_object_info_table_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_RESOURCE_TRACKING_CONSUMER_BASE_H
