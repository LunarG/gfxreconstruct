/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos OpenXR XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_OPENXR_STATE_TABLE_H
#define  GFXRECON_GENERATED_OPENXR_STATE_TABLE_H

#include "encode/openxr_state_table_base.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class OpenXrStateTable : OpenXrStateTableBase
{
  public:
    OpenXrStateTable() {}
    ~OpenXrStateTable() {}

    bool InsertWrapper(format::HandleId id, ActionWrapper* wrapper) { return InsertEntry(id, wrapper, action_map_); }
    bool InsertWrapper(format::HandleId id, ActionSetWrapper* wrapper) { return InsertEntry(id, wrapper, actionSet_map_); }
    bool InsertWrapper(format::HandleId id, BodyTrackerFBWrapper* wrapper) { return InsertEntry(id, wrapper, bodyTrackerFB_map_); }
    bool InsertWrapper(format::HandleId id, DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(id, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(format::HandleId id, ExportedLocalizationMapMLWrapper* wrapper) { return InsertEntry(id, wrapper, exportedLocalizationMapML_map_); }
    bool InsertWrapper(format::HandleId id, EyeTrackerFBWrapper* wrapper) { return InsertEntry(id, wrapper, eyeTrackerFB_map_); }
    bool InsertWrapper(format::HandleId id, FaceTracker2FBWrapper* wrapper) { return InsertEntry(id, wrapper, faceTracker2FB_map_); }
    bool InsertWrapper(format::HandleId id, FaceTrackerFBWrapper* wrapper) { return InsertEntry(id, wrapper, faceTrackerFB_map_); }
    bool InsertWrapper(format::HandleId id, FacialTrackerHTCWrapper* wrapper) { return InsertEntry(id, wrapper, facialTrackerHTC_map_); }
    bool InsertWrapper(format::HandleId id, FoveationProfileFBWrapper* wrapper) { return InsertEntry(id, wrapper, foveationProfileFB_map_); }
    bool InsertWrapper(format::HandleId id, GeometryInstanceFBWrapper* wrapper) { return InsertEntry(id, wrapper, geometryInstanceFB_map_); }
    bool InsertWrapper(format::HandleId id, HandTrackerEXTWrapper* wrapper) { return InsertEntry(id, wrapper, handTrackerEXT_map_); }
    bool InsertWrapper(format::HandleId id, InstanceWrapper* wrapper) { return InsertEntry(id, wrapper, instance_map_); }
    bool InsertWrapper(format::HandleId id, MarkerDetectorMLWrapper* wrapper) { return InsertEntry(id, wrapper, markerDetectorML_map_); }
    bool InsertWrapper(format::HandleId id, PassthroughColorLutMETAWrapper* wrapper) { return InsertEntry(id, wrapper, passthroughColorLutMETA_map_); }
    bool InsertWrapper(format::HandleId id, PassthroughFBWrapper* wrapper) { return InsertEntry(id, wrapper, passthroughFB_map_); }
    bool InsertWrapper(format::HandleId id, PassthroughHTCWrapper* wrapper) { return InsertEntry(id, wrapper, passthroughHTC_map_); }
    bool InsertWrapper(format::HandleId id, PassthroughLayerFBWrapper* wrapper) { return InsertEntry(id, wrapper, passthroughLayerFB_map_); }
    bool InsertWrapper(format::HandleId id, PlaneDetectorEXTWrapper* wrapper) { return InsertEntry(id, wrapper, planeDetectorEXT_map_); }
    bool InsertWrapper(format::HandleId id, SceneMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, sceneMSFT_map_); }
    bool InsertWrapper(format::HandleId id, SceneObserverMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, sceneObserverMSFT_map_); }
    bool InsertWrapper(format::HandleId id, SessionWrapper* wrapper) { return InsertEntry(id, wrapper, session_map_); }
    bool InsertWrapper(format::HandleId id, SpaceWrapper* wrapper) { return InsertEntry(id, wrapper, space_map_); }
    bool InsertWrapper(format::HandleId id, SpaceUserFBWrapper* wrapper) { return InsertEntry(id, wrapper, spaceUserFB_map_); }
    bool InsertWrapper(format::HandleId id, SpatialAnchorMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, spatialAnchorMSFT_map_); }
    bool InsertWrapper(format::HandleId id, SpatialAnchorStoreConnectionMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, spatialAnchorStoreConnectionMSFT_map_); }
    bool InsertWrapper(format::HandleId id, SpatialGraphNodeBindingMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, spatialGraphNodeBindingMSFT_map_); }
    bool InsertWrapper(format::HandleId id, SwapchainWrapper* wrapper) { return InsertEntry(id, wrapper, swapchain_map_); }
    bool InsertWrapper(format::HandleId id, TriangleMeshFBWrapper* wrapper) { return InsertEntry(id, wrapper, triangleMeshFB_map_); }
    bool InsertWrapper(format::HandleId id, VirtualKeyboardMETAWrapper* wrapper) { return InsertEntry(id, wrapper, virtualKeyboardMETA_map_); }

    bool RemoveWrapper(const ActionWrapper* wrapper) { return RemoveEntry(wrapper, action_map_); }
    bool RemoveWrapper(const ActionSetWrapper* wrapper) { return RemoveEntry(wrapper, actionSet_map_); }
    bool RemoveWrapper(const BodyTrackerFBWrapper* wrapper) { return RemoveEntry(wrapper, bodyTrackerFB_map_); }
    bool RemoveWrapper(const DebugUtilsMessengerEXTWrapper* wrapper) { return RemoveEntry(wrapper, debugUtilsMessengerEXT_map_); }
    bool RemoveWrapper(const ExportedLocalizationMapMLWrapper* wrapper) { return RemoveEntry(wrapper, exportedLocalizationMapML_map_); }
    bool RemoveWrapper(const EyeTrackerFBWrapper* wrapper) { return RemoveEntry(wrapper, eyeTrackerFB_map_); }
    bool RemoveWrapper(const FaceTracker2FBWrapper* wrapper) { return RemoveEntry(wrapper, faceTracker2FB_map_); }
    bool RemoveWrapper(const FaceTrackerFBWrapper* wrapper) { return RemoveEntry(wrapper, faceTrackerFB_map_); }
    bool RemoveWrapper(const FacialTrackerHTCWrapper* wrapper) { return RemoveEntry(wrapper, facialTrackerHTC_map_); }
    bool RemoveWrapper(const FoveationProfileFBWrapper* wrapper) { return RemoveEntry(wrapper, foveationProfileFB_map_); }
    bool RemoveWrapper(const GeometryInstanceFBWrapper* wrapper) { return RemoveEntry(wrapper, geometryInstanceFB_map_); }
    bool RemoveWrapper(const HandTrackerEXTWrapper* wrapper) { return RemoveEntry(wrapper, handTrackerEXT_map_); }
    bool RemoveWrapper(const InstanceWrapper* wrapper) { return RemoveEntry(wrapper, instance_map_); }
    bool RemoveWrapper(const MarkerDetectorMLWrapper* wrapper) { return RemoveEntry(wrapper, markerDetectorML_map_); }
    bool RemoveWrapper(const PassthroughColorLutMETAWrapper* wrapper) { return RemoveEntry(wrapper, passthroughColorLutMETA_map_); }
    bool RemoveWrapper(const PassthroughFBWrapper* wrapper) { return RemoveEntry(wrapper, passthroughFB_map_); }
    bool RemoveWrapper(const PassthroughHTCWrapper* wrapper) { return RemoveEntry(wrapper, passthroughHTC_map_); }
    bool RemoveWrapper(const PassthroughLayerFBWrapper* wrapper) { return RemoveEntry(wrapper, passthroughLayerFB_map_); }
    bool RemoveWrapper(const PlaneDetectorEXTWrapper* wrapper) { return RemoveEntry(wrapper, planeDetectorEXT_map_); }
    bool RemoveWrapper(const SceneMSFTWrapper* wrapper) { return RemoveEntry(wrapper, sceneMSFT_map_); }
    bool RemoveWrapper(const SceneObserverMSFTWrapper* wrapper) { return RemoveEntry(wrapper, sceneObserverMSFT_map_); }
    bool RemoveWrapper(const SessionWrapper* wrapper) { return RemoveEntry(wrapper, session_map_); }
    bool RemoveWrapper(const SpaceWrapper* wrapper) { return RemoveEntry(wrapper, space_map_); }
    bool RemoveWrapper(const SpaceUserFBWrapper* wrapper) { return RemoveEntry(wrapper, spaceUserFB_map_); }
    bool RemoveWrapper(const SpatialAnchorMSFTWrapper* wrapper) { return RemoveEntry(wrapper, spatialAnchorMSFT_map_); }
    bool RemoveWrapper(const SpatialAnchorStoreConnectionMSFTWrapper* wrapper) { return RemoveEntry(wrapper, spatialAnchorStoreConnectionMSFT_map_); }
    bool RemoveWrapper(const SpatialGraphNodeBindingMSFTWrapper* wrapper) { return RemoveEntry(wrapper, spatialGraphNodeBindingMSFT_map_); }
    bool RemoveWrapper(const SwapchainWrapper* wrapper) { return RemoveEntry(wrapper, swapchain_map_); }
    bool RemoveWrapper(const TriangleMeshFBWrapper* wrapper) { return RemoveEntry(wrapper, triangleMeshFB_map_); }
    bool RemoveWrapper(const VirtualKeyboardMETAWrapper* wrapper) { return RemoveEntry(wrapper, virtualKeyboardMETA_map_); }

    const ActionWrapper* GetActionWrapper(format::HandleId id) const { return GetWrapper<ActionWrapper>(id, action_map_); }
    const ActionSetWrapper* GetActionSetWrapper(format::HandleId id) const { return GetWrapper<ActionSetWrapper>(id, actionSet_map_); }
    const BodyTrackerFBWrapper* GetBodyTrackerFBWrapper(format::HandleId id) const { return GetWrapper<BodyTrackerFBWrapper>(id, bodyTrackerFB_map_); }
    const DebugUtilsMessengerEXTWrapper* GetDebugUtilsMessengerEXTWrapper(format::HandleId id) const { return GetWrapper<DebugUtilsMessengerEXTWrapper>(id, debugUtilsMessengerEXT_map_); }
    const ExportedLocalizationMapMLWrapper* GetExportedLocalizationMapMLWrapper(format::HandleId id) const { return GetWrapper<ExportedLocalizationMapMLWrapper>(id, exportedLocalizationMapML_map_); }
    const EyeTrackerFBWrapper* GetEyeTrackerFBWrapper(format::HandleId id) const { return GetWrapper<EyeTrackerFBWrapper>(id, eyeTrackerFB_map_); }
    const FaceTracker2FBWrapper* GetFaceTracker2FBWrapper(format::HandleId id) const { return GetWrapper<FaceTracker2FBWrapper>(id, faceTracker2FB_map_); }
    const FaceTrackerFBWrapper* GetFaceTrackerFBWrapper(format::HandleId id) const { return GetWrapper<FaceTrackerFBWrapper>(id, faceTrackerFB_map_); }
    const FacialTrackerHTCWrapper* GetFacialTrackerHTCWrapper(format::HandleId id) const { return GetWrapper<FacialTrackerHTCWrapper>(id, facialTrackerHTC_map_); }
    const FoveationProfileFBWrapper* GetFoveationProfileFBWrapper(format::HandleId id) const { return GetWrapper<FoveationProfileFBWrapper>(id, foveationProfileFB_map_); }
    const GeometryInstanceFBWrapper* GetGeometryInstanceFBWrapper(format::HandleId id) const { return GetWrapper<GeometryInstanceFBWrapper>(id, geometryInstanceFB_map_); }
    const HandTrackerEXTWrapper* GetHandTrackerEXTWrapper(format::HandleId id) const { return GetWrapper<HandTrackerEXTWrapper>(id, handTrackerEXT_map_); }
    const InstanceWrapper* GetInstanceWrapper(format::HandleId id) const { return GetWrapper<InstanceWrapper>(id, instance_map_); }
    const MarkerDetectorMLWrapper* GetMarkerDetectorMLWrapper(format::HandleId id) const { return GetWrapper<MarkerDetectorMLWrapper>(id, markerDetectorML_map_); }
    const PassthroughColorLutMETAWrapper* GetPassthroughColorLutMETAWrapper(format::HandleId id) const { return GetWrapper<PassthroughColorLutMETAWrapper>(id, passthroughColorLutMETA_map_); }
    const PassthroughFBWrapper* GetPassthroughFBWrapper(format::HandleId id) const { return GetWrapper<PassthroughFBWrapper>(id, passthroughFB_map_); }
    const PassthroughHTCWrapper* GetPassthroughHTCWrapper(format::HandleId id) const { return GetWrapper<PassthroughHTCWrapper>(id, passthroughHTC_map_); }
    const PassthroughLayerFBWrapper* GetPassthroughLayerFBWrapper(format::HandleId id) const { return GetWrapper<PassthroughLayerFBWrapper>(id, passthroughLayerFB_map_); }
    const PlaneDetectorEXTWrapper* GetPlaneDetectorEXTWrapper(format::HandleId id) const { return GetWrapper<PlaneDetectorEXTWrapper>(id, planeDetectorEXT_map_); }
    const SceneMSFTWrapper* GetSceneMSFTWrapper(format::HandleId id) const { return GetWrapper<SceneMSFTWrapper>(id, sceneMSFT_map_); }
    const SceneObserverMSFTWrapper* GetSceneObserverMSFTWrapper(format::HandleId id) const { return GetWrapper<SceneObserverMSFTWrapper>(id, sceneObserverMSFT_map_); }
    const SessionWrapper* GetSessionWrapper(format::HandleId id) const { return GetWrapper<SessionWrapper>(id, session_map_); }
    const SpaceWrapper* GetSpaceWrapper(format::HandleId id) const { return GetWrapper<SpaceWrapper>(id, space_map_); }
    const SpaceUserFBWrapper* GetSpaceUserFBWrapper(format::HandleId id) const { return GetWrapper<SpaceUserFBWrapper>(id, spaceUserFB_map_); }
    const SpatialAnchorMSFTWrapper* GetSpatialAnchorMSFTWrapper(format::HandleId id) const { return GetWrapper<SpatialAnchorMSFTWrapper>(id, spatialAnchorMSFT_map_); }
    const SpatialAnchorStoreConnectionMSFTWrapper* GetSpatialAnchorStoreConnectionMSFTWrapper(format::HandleId id) const { return GetWrapper<SpatialAnchorStoreConnectionMSFTWrapper>(id, spatialAnchorStoreConnectionMSFT_map_); }
    const SpatialGraphNodeBindingMSFTWrapper* GetSpatialGraphNodeBindingMSFTWrapper(format::HandleId id) const { return GetWrapper<SpatialGraphNodeBindingMSFTWrapper>(id, spatialGraphNodeBindingMSFT_map_); }
    const SwapchainWrapper* GetSwapchainWrapper(format::HandleId id) const { return GetWrapper<SwapchainWrapper>(id, swapchain_map_); }
    const TriangleMeshFBWrapper* GetTriangleMeshFBWrapper(format::HandleId id) const { return GetWrapper<TriangleMeshFBWrapper>(id, triangleMeshFB_map_); }
    const VirtualKeyboardMETAWrapper* GetVirtualKeyboardMETAWrapper(format::HandleId id) const { return GetWrapper<VirtualKeyboardMETAWrapper>(id, virtualKeyboardMETA_map_); }

    ActionWrapper* GetActionWrapper(format::HandleId id) { return GetWrapper<ActionWrapper>(id, action_map_); }
    ActionSetWrapper* GetActionSetWrapper(format::HandleId id) { return GetWrapper<ActionSetWrapper>(id, actionSet_map_); }
    BodyTrackerFBWrapper* GetBodyTrackerFBWrapper(format::HandleId id) { return GetWrapper<BodyTrackerFBWrapper>(id, bodyTrackerFB_map_); }
    DebugUtilsMessengerEXTWrapper* GetDebugUtilsMessengerEXTWrapper(format::HandleId id) { return GetWrapper<DebugUtilsMessengerEXTWrapper>(id, debugUtilsMessengerEXT_map_); }
    ExportedLocalizationMapMLWrapper* GetExportedLocalizationMapMLWrapper(format::HandleId id) { return GetWrapper<ExportedLocalizationMapMLWrapper>(id, exportedLocalizationMapML_map_); }
    EyeTrackerFBWrapper* GetEyeTrackerFBWrapper(format::HandleId id) { return GetWrapper<EyeTrackerFBWrapper>(id, eyeTrackerFB_map_); }
    FaceTracker2FBWrapper* GetFaceTracker2FBWrapper(format::HandleId id) { return GetWrapper<FaceTracker2FBWrapper>(id, faceTracker2FB_map_); }
    FaceTrackerFBWrapper* GetFaceTrackerFBWrapper(format::HandleId id) { return GetWrapper<FaceTrackerFBWrapper>(id, faceTrackerFB_map_); }
    FacialTrackerHTCWrapper* GetFacialTrackerHTCWrapper(format::HandleId id) { return GetWrapper<FacialTrackerHTCWrapper>(id, facialTrackerHTC_map_); }
    FoveationProfileFBWrapper* GetFoveationProfileFBWrapper(format::HandleId id) { return GetWrapper<FoveationProfileFBWrapper>(id, foveationProfileFB_map_); }
    GeometryInstanceFBWrapper* GetGeometryInstanceFBWrapper(format::HandleId id) { return GetWrapper<GeometryInstanceFBWrapper>(id, geometryInstanceFB_map_); }
    HandTrackerEXTWrapper* GetHandTrackerEXTWrapper(format::HandleId id) { return GetWrapper<HandTrackerEXTWrapper>(id, handTrackerEXT_map_); }
    InstanceWrapper* GetInstanceWrapper(format::HandleId id) { return GetWrapper<InstanceWrapper>(id, instance_map_); }
    MarkerDetectorMLWrapper* GetMarkerDetectorMLWrapper(format::HandleId id) { return GetWrapper<MarkerDetectorMLWrapper>(id, markerDetectorML_map_); }
    PassthroughColorLutMETAWrapper* GetPassthroughColorLutMETAWrapper(format::HandleId id) { return GetWrapper<PassthroughColorLutMETAWrapper>(id, passthroughColorLutMETA_map_); }
    PassthroughFBWrapper* GetPassthroughFBWrapper(format::HandleId id) { return GetWrapper<PassthroughFBWrapper>(id, passthroughFB_map_); }
    PassthroughHTCWrapper* GetPassthroughHTCWrapper(format::HandleId id) { return GetWrapper<PassthroughHTCWrapper>(id, passthroughHTC_map_); }
    PassthroughLayerFBWrapper* GetPassthroughLayerFBWrapper(format::HandleId id) { return GetWrapper<PassthroughLayerFBWrapper>(id, passthroughLayerFB_map_); }
    PlaneDetectorEXTWrapper* GetPlaneDetectorEXTWrapper(format::HandleId id) { return GetWrapper<PlaneDetectorEXTWrapper>(id, planeDetectorEXT_map_); }
    SceneMSFTWrapper* GetSceneMSFTWrapper(format::HandleId id) { return GetWrapper<SceneMSFTWrapper>(id, sceneMSFT_map_); }
    SceneObserverMSFTWrapper* GetSceneObserverMSFTWrapper(format::HandleId id) { return GetWrapper<SceneObserverMSFTWrapper>(id, sceneObserverMSFT_map_); }
    SessionWrapper* GetSessionWrapper(format::HandleId id) { return GetWrapper<SessionWrapper>(id, session_map_); }
    SpaceWrapper* GetSpaceWrapper(format::HandleId id) { return GetWrapper<SpaceWrapper>(id, space_map_); }
    SpaceUserFBWrapper* GetSpaceUserFBWrapper(format::HandleId id) { return GetWrapper<SpaceUserFBWrapper>(id, spaceUserFB_map_); }
    SpatialAnchorMSFTWrapper* GetSpatialAnchorMSFTWrapper(format::HandleId id) { return GetWrapper<SpatialAnchorMSFTWrapper>(id, spatialAnchorMSFT_map_); }
    SpatialAnchorStoreConnectionMSFTWrapper* GetSpatialAnchorStoreConnectionMSFTWrapper(format::HandleId id) { return GetWrapper<SpatialAnchorStoreConnectionMSFTWrapper>(id, spatialAnchorStoreConnectionMSFT_map_); }
    SpatialGraphNodeBindingMSFTWrapper* GetSpatialGraphNodeBindingMSFTWrapper(format::HandleId id) { return GetWrapper<SpatialGraphNodeBindingMSFTWrapper>(id, spatialGraphNodeBindingMSFT_map_); }
    SwapchainWrapper* GetSwapchainWrapper(format::HandleId id) { return GetWrapper<SwapchainWrapper>(id, swapchain_map_); }
    TriangleMeshFBWrapper* GetTriangleMeshFBWrapper(format::HandleId id) { return GetWrapper<TriangleMeshFBWrapper>(id, triangleMeshFB_map_); }
    VirtualKeyboardMETAWrapper* GetVirtualKeyboardMETAWrapper(format::HandleId id) { return GetWrapper<VirtualKeyboardMETAWrapper>(id, virtualKeyboardMETA_map_); }

    void VisitWrappers(std::function<void(ActionWrapper*)> visitor) const { for (auto entry : action_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ActionSetWrapper*)> visitor) const { for (auto entry : actionSet_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(BodyTrackerFBWrapper*)> visitor) const { for (auto entry : bodyTrackerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DebugUtilsMessengerEXTWrapper*)> visitor) const { for (auto entry : debugUtilsMessengerEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ExportedLocalizationMapMLWrapper*)> visitor) const { for (auto entry : exportedLocalizationMapML_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(EyeTrackerFBWrapper*)> visitor) const { for (auto entry : eyeTrackerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(FaceTracker2FBWrapper*)> visitor) const { for (auto entry : faceTracker2FB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(FaceTrackerFBWrapper*)> visitor) const { for (auto entry : faceTrackerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(FacialTrackerHTCWrapper*)> visitor) const { for (auto entry : facialTrackerHTC_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(FoveationProfileFBWrapper*)> visitor) const { for (auto entry : foveationProfileFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(GeometryInstanceFBWrapper*)> visitor) const { for (auto entry : geometryInstanceFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(HandTrackerEXTWrapper*)> visitor) const { for (auto entry : handTrackerEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(InstanceWrapper*)> visitor) const { for (auto entry : instance_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(MarkerDetectorMLWrapper*)> visitor) const { for (auto entry : markerDetectorML_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PassthroughColorLutMETAWrapper*)> visitor) const { for (auto entry : passthroughColorLutMETA_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PassthroughFBWrapper*)> visitor) const { for (auto entry : passthroughFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PassthroughHTCWrapper*)> visitor) const { for (auto entry : passthroughHTC_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PassthroughLayerFBWrapper*)> visitor) const { for (auto entry : passthroughLayerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PlaneDetectorEXTWrapper*)> visitor) const { for (auto entry : planeDetectorEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SceneMSFTWrapper*)> visitor) const { for (auto entry : sceneMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SceneObserverMSFTWrapper*)> visitor) const { for (auto entry : sceneObserverMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SessionWrapper*)> visitor) const { for (auto entry : session_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SpaceWrapper*)> visitor) const { for (auto entry : space_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SpaceUserFBWrapper*)> visitor) const { for (auto entry : spaceUserFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SpatialAnchorMSFTWrapper*)> visitor) const { for (auto entry : spatialAnchorMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SpatialAnchorStoreConnectionMSFTWrapper*)> visitor) const { for (auto entry : spatialAnchorStoreConnectionMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SpatialGraphNodeBindingMSFTWrapper*)> visitor) const { for (auto entry : spatialGraphNodeBindingMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SwapchainWrapper*)> visitor) const { for (auto entry : swapchain_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(TriangleMeshFBWrapper*)> visitor) const { for (auto entry : triangleMeshFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(VirtualKeyboardMETAWrapper*)> visitor) const { for (auto entry : virtualKeyboardMETA_map_) { visitor(entry.second); } }

  private:
    std::map<format::HandleId, ActionWrapper*> action_map_;
    std::map<format::HandleId, ActionSetWrapper*> actionSet_map_;
    std::map<format::HandleId, BodyTrackerFBWrapper*> bodyTrackerFB_map_;
    std::map<format::HandleId, DebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::map<format::HandleId, ExportedLocalizationMapMLWrapper*> exportedLocalizationMapML_map_;
    std::map<format::HandleId, EyeTrackerFBWrapper*> eyeTrackerFB_map_;
    std::map<format::HandleId, FaceTracker2FBWrapper*> faceTracker2FB_map_;
    std::map<format::HandleId, FaceTrackerFBWrapper*> faceTrackerFB_map_;
    std::map<format::HandleId, FacialTrackerHTCWrapper*> facialTrackerHTC_map_;
    std::map<format::HandleId, FoveationProfileFBWrapper*> foveationProfileFB_map_;
    std::map<format::HandleId, GeometryInstanceFBWrapper*> geometryInstanceFB_map_;
    std::map<format::HandleId, HandTrackerEXTWrapper*> handTrackerEXT_map_;
    std::map<format::HandleId, InstanceWrapper*> instance_map_;
    std::map<format::HandleId, MarkerDetectorMLWrapper*> markerDetectorML_map_;
    std::map<format::HandleId, PassthroughColorLutMETAWrapper*> passthroughColorLutMETA_map_;
    std::map<format::HandleId, PassthroughFBWrapper*> passthroughFB_map_;
    std::map<format::HandleId, PassthroughHTCWrapper*> passthroughHTC_map_;
    std::map<format::HandleId, PassthroughLayerFBWrapper*> passthroughLayerFB_map_;
    std::map<format::HandleId, PlaneDetectorEXTWrapper*> planeDetectorEXT_map_;
    std::map<format::HandleId, SceneMSFTWrapper*> sceneMSFT_map_;
    std::map<format::HandleId, SceneObserverMSFTWrapper*> sceneObserverMSFT_map_;
    std::map<format::HandleId, SessionWrapper*> session_map_;
    std::map<format::HandleId, SpaceWrapper*> space_map_;
    std::map<format::HandleId, SpaceUserFBWrapper*> spaceUserFB_map_;
    std::map<format::HandleId, SpatialAnchorMSFTWrapper*> spatialAnchorMSFT_map_;
    std::map<format::HandleId, SpatialAnchorStoreConnectionMSFTWrapper*> spatialAnchorStoreConnectionMSFT_map_;
    std::map<format::HandleId, SpatialGraphNodeBindingMSFTWrapper*> spatialGraphNodeBindingMSFT_map_;
    std::map<format::HandleId, SwapchainWrapper*> swapchain_map_;
    std::map<format::HandleId, TriangleMeshFBWrapper*> triangleMeshFB_map_;
    std::map<format::HandleId, VirtualKeyboardMETAWrapper*> virtualKeyboardMETA_map_;
};

class OpenXrStateHandleTable : OpenXrStateTableBase
{
  public:
    OpenXrStateHandleTable() {}
    ~OpenXrStateHandleTable() {}

    bool InsertWrapper(ActionWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, action_map_); }
    bool InsertWrapper(ActionSetWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, actionSet_map_); }
    bool InsertWrapper(BodyTrackerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, bodyTrackerFB_map_); }
    bool InsertWrapper(DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(ExportedLocalizationMapMLWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, exportedLocalizationMapML_map_); }
    bool InsertWrapper(EyeTrackerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, eyeTrackerFB_map_); }
    bool InsertWrapper(FaceTracker2FBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, faceTracker2FB_map_); }
    bool InsertWrapper(FaceTrackerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, faceTrackerFB_map_); }
    bool InsertWrapper(FacialTrackerHTCWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, facialTrackerHTC_map_); }
    bool InsertWrapper(FoveationProfileFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, foveationProfileFB_map_); }
    bool InsertWrapper(GeometryInstanceFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, geometryInstanceFB_map_); }
    bool InsertWrapper(HandTrackerEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, handTrackerEXT_map_); }
    bool InsertWrapper(InstanceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, instance_map_); }
    bool InsertWrapper(MarkerDetectorMLWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, markerDetectorML_map_); }
    bool InsertWrapper(PassthroughColorLutMETAWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, passthroughColorLutMETA_map_); }
    bool InsertWrapper(PassthroughFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, passthroughFB_map_); }
    bool InsertWrapper(PassthroughHTCWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, passthroughHTC_map_); }
    bool InsertWrapper(PassthroughLayerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, passthroughLayerFB_map_); }
    bool InsertWrapper(PlaneDetectorEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, planeDetectorEXT_map_); }
    bool InsertWrapper(SceneMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, sceneMSFT_map_); }
    bool InsertWrapper(SceneObserverMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, sceneObserverMSFT_map_); }
    bool InsertWrapper(SessionWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, session_map_); }
    bool InsertWrapper(SpaceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, space_map_); }
    bool InsertWrapper(SpaceUserFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, spaceUserFB_map_); }
    bool InsertWrapper(SpatialAnchorMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, spatialAnchorMSFT_map_); }
    bool InsertWrapper(SpatialAnchorStoreConnectionMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, spatialAnchorStoreConnectionMSFT_map_); }
    bool InsertWrapper(SpatialGraphNodeBindingMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, spatialGraphNodeBindingMSFT_map_); }
    bool InsertWrapper(SwapchainWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, swapchain_map_); }
    bool InsertWrapper(TriangleMeshFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, triangleMeshFB_map_); }
    bool InsertWrapper(VirtualKeyboardMETAWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, virtualKeyboardMETA_map_); }

    bool RemoveWrapper(const ActionWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, action_map_);
    }
    bool RemoveWrapper(const ActionSetWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, actionSet_map_);
    }
    bool RemoveWrapper(const BodyTrackerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, bodyTrackerFB_map_);
    }
    bool RemoveWrapper(const DebugUtilsMessengerEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, debugUtilsMessengerEXT_map_);
    }
    bool RemoveWrapper(const ExportedLocalizationMapMLWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, exportedLocalizationMapML_map_);
    }
    bool RemoveWrapper(const EyeTrackerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, eyeTrackerFB_map_);
    }
    bool RemoveWrapper(const FaceTracker2FBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, faceTracker2FB_map_);
    }
    bool RemoveWrapper(const FaceTrackerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, faceTrackerFB_map_);
    }
    bool RemoveWrapper(const FacialTrackerHTCWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, facialTrackerHTC_map_);
    }
    bool RemoveWrapper(const FoveationProfileFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, foveationProfileFB_map_);
    }
    bool RemoveWrapper(const GeometryInstanceFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, geometryInstanceFB_map_);
    }
    bool RemoveWrapper(const HandTrackerEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, handTrackerEXT_map_);
    }
    bool RemoveWrapper(const InstanceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, instance_map_);
    }
    bool RemoveWrapper(const MarkerDetectorMLWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, markerDetectorML_map_);
    }
    bool RemoveWrapper(const PassthroughColorLutMETAWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, passthroughColorLutMETA_map_);
    }
    bool RemoveWrapper(const PassthroughFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, passthroughFB_map_);
    }
    bool RemoveWrapper(const PassthroughHTCWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, passthroughHTC_map_);
    }
    bool RemoveWrapper(const PassthroughLayerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, passthroughLayerFB_map_);
    }
    bool RemoveWrapper(const PlaneDetectorEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, planeDetectorEXT_map_);
    }
    bool RemoveWrapper(const SceneMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, sceneMSFT_map_);
    }
    bool RemoveWrapper(const SceneObserverMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, sceneObserverMSFT_map_);
    }
    bool RemoveWrapper(const SessionWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, session_map_);
    }
    bool RemoveWrapper(const SpaceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, space_map_);
    }
    bool RemoveWrapper(const SpaceUserFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, spaceUserFB_map_);
    }
    bool RemoveWrapper(const SpatialAnchorMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, spatialAnchorMSFT_map_);
    }
    bool RemoveWrapper(const SpatialAnchorStoreConnectionMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, spatialAnchorStoreConnectionMSFT_map_);
    }
    bool RemoveWrapper(const SpatialGraphNodeBindingMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, spatialGraphNodeBindingMSFT_map_);
    }
    bool RemoveWrapper(const SwapchainWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, swapchain_map_);
    }
    bool RemoveWrapper(const TriangleMeshFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, triangleMeshFB_map_);
    }
    bool RemoveWrapper(const VirtualKeyboardMETAWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, virtualKeyboardMETA_map_);
    }

    template<typename Wrapper> const Wrapper* GetWrapper(typename Wrapper::HandleType handle) const { return nullptr; }

    template<typename Wrapper> Wrapper* GetWrapper(typename Wrapper::HandleType handle) { return nullptr; }

  private:
    std::unordered_map<Action, ActionWrapper*> action_map_;
    std::unordered_map<ActionSet, ActionSetWrapper*> actionSet_map_;
    std::unordered_map<BodyTrackerFB, BodyTrackerFBWrapper*> bodyTrackerFB_map_;
    std::unordered_map<DebugUtilsMessengerEXT, DebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::unordered_map<ExportedLocalizationMapML, ExportedLocalizationMapMLWrapper*> exportedLocalizationMapML_map_;
    std::unordered_map<EyeTrackerFB, EyeTrackerFBWrapper*> eyeTrackerFB_map_;
    std::unordered_map<FaceTracker2FB, FaceTracker2FBWrapper*> faceTracker2FB_map_;
    std::unordered_map<FaceTrackerFB, FaceTrackerFBWrapper*> faceTrackerFB_map_;
    std::unordered_map<FacialTrackerHTC, FacialTrackerHTCWrapper*> facialTrackerHTC_map_;
    std::unordered_map<FoveationProfileFB, FoveationProfileFBWrapper*> foveationProfileFB_map_;
    std::unordered_map<GeometryInstanceFB, GeometryInstanceFBWrapper*> geometryInstanceFB_map_;
    std::unordered_map<HandTrackerEXT, HandTrackerEXTWrapper*> handTrackerEXT_map_;
    std::unordered_map<Instance, InstanceWrapper*> instance_map_;
    std::unordered_map<MarkerDetectorML, MarkerDetectorMLWrapper*> markerDetectorML_map_;
    std::unordered_map<PassthroughColorLutMETA, PassthroughColorLutMETAWrapper*> passthroughColorLutMETA_map_;
    std::unordered_map<PassthroughFB, PassthroughFBWrapper*> passthroughFB_map_;
    std::unordered_map<PassthroughHTC, PassthroughHTCWrapper*> passthroughHTC_map_;
    std::unordered_map<PassthroughLayerFB, PassthroughLayerFBWrapper*> passthroughLayerFB_map_;
    std::unordered_map<PlaneDetectorEXT, PlaneDetectorEXTWrapper*> planeDetectorEXT_map_;
    std::unordered_map<SceneMSFT, SceneMSFTWrapper*> sceneMSFT_map_;
    std::unordered_map<SceneObserverMSFT, SceneObserverMSFTWrapper*> sceneObserverMSFT_map_;
    std::unordered_map<Session, SessionWrapper*> session_map_;
    std::unordered_map<Space, SpaceWrapper*> space_map_;
    std::unordered_map<SpaceUserFB, SpaceUserFBWrapper*> spaceUserFB_map_;
    std::unordered_map<SpatialAnchorMSFT, SpatialAnchorMSFTWrapper*> spatialAnchorMSFT_map_;
    std::unordered_map<SpatialAnchorStoreConnectionMSFT, SpatialAnchorStoreConnectionMSFTWrapper*> spatialAnchorStoreConnectionMSFT_map_;
    std::unordered_map<SpatialGraphNodeBindingMSFT, SpatialGraphNodeBindingMSFTWrapper*> spatialGraphNodeBindingMSFT_map_;
    std::unordered_map<Swapchain, SwapchainWrapper*> swapchain_map_;
    std::unordered_map<TriangleMeshFB, TriangleMeshFBWrapper*> triangleMeshFB_map_;
    std::unordered_map<VirtualKeyboardMETA, VirtualKeyboardMETAWrapper*> virtualKeyboardMETA_map_;
};

template<> inline const ActionWrapper* OpenXrStateHandleTable::GetWrapper<ActionWrapper>(Action handle) const { return OpenXrStateTableBase::GetWrapper(handle, action_map_); }
template<> inline const ActionSetWrapper* OpenXrStateHandleTable::GetWrapper<ActionSetWrapper>(ActionSet handle) const { return OpenXrStateTableBase::GetWrapper(handle, actionSet_map_); }
template<> inline const BodyTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<BodyTrackerFBWrapper>(BodyTrackerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, bodyTrackerFB_map_); }
template<> inline const DebugUtilsMessengerEXTWrapper* OpenXrStateHandleTable::GetWrapper<DebugUtilsMessengerEXTWrapper>(DebugUtilsMessengerEXT handle) const { return OpenXrStateTableBase::GetWrapper(handle, debugUtilsMessengerEXT_map_); }
template<> inline const ExportedLocalizationMapMLWrapper* OpenXrStateHandleTable::GetWrapper<ExportedLocalizationMapMLWrapper>(ExportedLocalizationMapML handle) const { return OpenXrStateTableBase::GetWrapper(handle, exportedLocalizationMapML_map_); }
template<> inline const EyeTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<EyeTrackerFBWrapper>(EyeTrackerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, eyeTrackerFB_map_); }
template<> inline const FaceTracker2FBWrapper* OpenXrStateHandleTable::GetWrapper<FaceTracker2FBWrapper>(FaceTracker2FB handle) const { return OpenXrStateTableBase::GetWrapper(handle, faceTracker2FB_map_); }
template<> inline const FaceTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<FaceTrackerFBWrapper>(FaceTrackerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, faceTrackerFB_map_); }
template<> inline const FacialTrackerHTCWrapper* OpenXrStateHandleTable::GetWrapper<FacialTrackerHTCWrapper>(FacialTrackerHTC handle) const { return OpenXrStateTableBase::GetWrapper(handle, facialTrackerHTC_map_); }
template<> inline const FoveationProfileFBWrapper* OpenXrStateHandleTable::GetWrapper<FoveationProfileFBWrapper>(FoveationProfileFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, foveationProfileFB_map_); }
template<> inline const GeometryInstanceFBWrapper* OpenXrStateHandleTable::GetWrapper<GeometryInstanceFBWrapper>(GeometryInstanceFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, geometryInstanceFB_map_); }
template<> inline const HandTrackerEXTWrapper* OpenXrStateHandleTable::GetWrapper<HandTrackerEXTWrapper>(HandTrackerEXT handle) const { return OpenXrStateTableBase::GetWrapper(handle, handTrackerEXT_map_); }
template<> inline const InstanceWrapper* OpenXrStateHandleTable::GetWrapper<InstanceWrapper>(Instance handle) const { return OpenXrStateTableBase::GetWrapper(handle, instance_map_); }
template<> inline const MarkerDetectorMLWrapper* OpenXrStateHandleTable::GetWrapper<MarkerDetectorMLWrapper>(MarkerDetectorML handle) const { return OpenXrStateTableBase::GetWrapper(handle, markerDetectorML_map_); }
template<> inline const PassthroughColorLutMETAWrapper* OpenXrStateHandleTable::GetWrapper<PassthroughColorLutMETAWrapper>(PassthroughColorLutMETA handle) const { return OpenXrStateTableBase::GetWrapper(handle, passthroughColorLutMETA_map_); }
template<> inline const PassthroughFBWrapper* OpenXrStateHandleTable::GetWrapper<PassthroughFBWrapper>(PassthroughFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, passthroughFB_map_); }
template<> inline const PassthroughHTCWrapper* OpenXrStateHandleTable::GetWrapper<PassthroughHTCWrapper>(PassthroughHTC handle) const { return OpenXrStateTableBase::GetWrapper(handle, passthroughHTC_map_); }
template<> inline const PassthroughLayerFBWrapper* OpenXrStateHandleTable::GetWrapper<PassthroughLayerFBWrapper>(PassthroughLayerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, passthroughLayerFB_map_); }
template<> inline const PlaneDetectorEXTWrapper* OpenXrStateHandleTable::GetWrapper<PlaneDetectorEXTWrapper>(PlaneDetectorEXT handle) const { return OpenXrStateTableBase::GetWrapper(handle, planeDetectorEXT_map_); }
template<> inline const SceneMSFTWrapper* OpenXrStateHandleTable::GetWrapper<SceneMSFTWrapper>(SceneMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, sceneMSFT_map_); }
template<> inline const SceneObserverMSFTWrapper* OpenXrStateHandleTable::GetWrapper<SceneObserverMSFTWrapper>(SceneObserverMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, sceneObserverMSFT_map_); }
template<> inline const SessionWrapper* OpenXrStateHandleTable::GetWrapper<SessionWrapper>(Session handle) const { return OpenXrStateTableBase::GetWrapper(handle, session_map_); }
template<> inline const SpaceWrapper* OpenXrStateHandleTable::GetWrapper<SpaceWrapper>(Space handle) const { return OpenXrStateTableBase::GetWrapper(handle, space_map_); }
template<> inline const SpaceUserFBWrapper* OpenXrStateHandleTable::GetWrapper<SpaceUserFBWrapper>(SpaceUserFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, spaceUserFB_map_); }
template<> inline const SpatialAnchorMSFTWrapper* OpenXrStateHandleTable::GetWrapper<SpatialAnchorMSFTWrapper>(SpatialAnchorMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, spatialAnchorMSFT_map_); }
template<> inline const SpatialAnchorStoreConnectionMSFTWrapper* OpenXrStateHandleTable::GetWrapper<SpatialAnchorStoreConnectionMSFTWrapper>(SpatialAnchorStoreConnectionMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, spatialAnchorStoreConnectionMSFT_map_); }
template<> inline const SpatialGraphNodeBindingMSFTWrapper* OpenXrStateHandleTable::GetWrapper<SpatialGraphNodeBindingMSFTWrapper>(SpatialGraphNodeBindingMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, spatialGraphNodeBindingMSFT_map_); }
template<> inline const SwapchainWrapper* OpenXrStateHandleTable::GetWrapper<SwapchainWrapper>(Swapchain handle) const { return OpenXrStateTableBase::GetWrapper(handle, swapchain_map_); }
template<> inline const TriangleMeshFBWrapper* OpenXrStateHandleTable::GetWrapper<TriangleMeshFBWrapper>(TriangleMeshFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, triangleMeshFB_map_); }
template<> inline const VirtualKeyboardMETAWrapper* OpenXrStateHandleTable::GetWrapper<VirtualKeyboardMETAWrapper>(VirtualKeyboardMETA handle) const { return OpenXrStateTableBase::GetWrapper(handle, virtualKeyboardMETA_map_); }

template<> inline ActionWrapper* OpenXrStateHandleTable::GetWrapper<ActionWrapper>(Action handle) { return OpenXrStateTableBase::GetWrapper(handle, action_map_); }
template<> inline ActionSetWrapper* OpenXrStateHandleTable::GetWrapper<ActionSetWrapper>(ActionSet handle) { return OpenXrStateTableBase::GetWrapper(handle, actionSet_map_); }
template<> inline BodyTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<BodyTrackerFBWrapper>(BodyTrackerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, bodyTrackerFB_map_); }
template<> inline DebugUtilsMessengerEXTWrapper* OpenXrStateHandleTable::GetWrapper<DebugUtilsMessengerEXTWrapper>(DebugUtilsMessengerEXT handle) { return OpenXrStateTableBase::GetWrapper(handle, debugUtilsMessengerEXT_map_); }
template<> inline ExportedLocalizationMapMLWrapper* OpenXrStateHandleTable::GetWrapper<ExportedLocalizationMapMLWrapper>(ExportedLocalizationMapML handle) { return OpenXrStateTableBase::GetWrapper(handle, exportedLocalizationMapML_map_); }
template<> inline EyeTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<EyeTrackerFBWrapper>(EyeTrackerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, eyeTrackerFB_map_); }
template<> inline FaceTracker2FBWrapper* OpenXrStateHandleTable::GetWrapper<FaceTracker2FBWrapper>(FaceTracker2FB handle) { return OpenXrStateTableBase::GetWrapper(handle, faceTracker2FB_map_); }
template<> inline FaceTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<FaceTrackerFBWrapper>(FaceTrackerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, faceTrackerFB_map_); }
template<> inline FacialTrackerHTCWrapper* OpenXrStateHandleTable::GetWrapper<FacialTrackerHTCWrapper>(FacialTrackerHTC handle) { return OpenXrStateTableBase::GetWrapper(handle, facialTrackerHTC_map_); }
template<> inline FoveationProfileFBWrapper* OpenXrStateHandleTable::GetWrapper<FoveationProfileFBWrapper>(FoveationProfileFB handle) { return OpenXrStateTableBase::GetWrapper(handle, foveationProfileFB_map_); }
template<> inline GeometryInstanceFBWrapper* OpenXrStateHandleTable::GetWrapper<GeometryInstanceFBWrapper>(GeometryInstanceFB handle) { return OpenXrStateTableBase::GetWrapper(handle, geometryInstanceFB_map_); }
template<> inline HandTrackerEXTWrapper* OpenXrStateHandleTable::GetWrapper<HandTrackerEXTWrapper>(HandTrackerEXT handle) { return OpenXrStateTableBase::GetWrapper(handle, handTrackerEXT_map_); }
template<> inline InstanceWrapper* OpenXrStateHandleTable::GetWrapper<InstanceWrapper>(Instance handle) { return OpenXrStateTableBase::GetWrapper(handle, instance_map_); }
template<> inline MarkerDetectorMLWrapper* OpenXrStateHandleTable::GetWrapper<MarkerDetectorMLWrapper>(MarkerDetectorML handle) { return OpenXrStateTableBase::GetWrapper(handle, markerDetectorML_map_); }
template<> inline PassthroughColorLutMETAWrapper* OpenXrStateHandleTable::GetWrapper<PassthroughColorLutMETAWrapper>(PassthroughColorLutMETA handle) { return OpenXrStateTableBase::GetWrapper(handle, passthroughColorLutMETA_map_); }
template<> inline PassthroughFBWrapper* OpenXrStateHandleTable::GetWrapper<PassthroughFBWrapper>(PassthroughFB handle) { return OpenXrStateTableBase::GetWrapper(handle, passthroughFB_map_); }
template<> inline PassthroughHTCWrapper* OpenXrStateHandleTable::GetWrapper<PassthroughHTCWrapper>(PassthroughHTC handle) { return OpenXrStateTableBase::GetWrapper(handle, passthroughHTC_map_); }
template<> inline PassthroughLayerFBWrapper* OpenXrStateHandleTable::GetWrapper<PassthroughLayerFBWrapper>(PassthroughLayerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, passthroughLayerFB_map_); }
template<> inline PlaneDetectorEXTWrapper* OpenXrStateHandleTable::GetWrapper<PlaneDetectorEXTWrapper>(PlaneDetectorEXT handle) { return OpenXrStateTableBase::GetWrapper(handle, planeDetectorEXT_map_); }
template<> inline SceneMSFTWrapper* OpenXrStateHandleTable::GetWrapper<SceneMSFTWrapper>(SceneMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, sceneMSFT_map_); }
template<> inline SceneObserverMSFTWrapper* OpenXrStateHandleTable::GetWrapper<SceneObserverMSFTWrapper>(SceneObserverMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, sceneObserverMSFT_map_); }
template<> inline SessionWrapper* OpenXrStateHandleTable::GetWrapper<SessionWrapper>(Session handle) { return OpenXrStateTableBase::GetWrapper(handle, session_map_); }
template<> inline SpaceWrapper* OpenXrStateHandleTable::GetWrapper<SpaceWrapper>(Space handle) { return OpenXrStateTableBase::GetWrapper(handle, space_map_); }
template<> inline SpaceUserFBWrapper* OpenXrStateHandleTable::GetWrapper<SpaceUserFBWrapper>(SpaceUserFB handle) { return OpenXrStateTableBase::GetWrapper(handle, spaceUserFB_map_); }
template<> inline SpatialAnchorMSFTWrapper* OpenXrStateHandleTable::GetWrapper<SpatialAnchorMSFTWrapper>(SpatialAnchorMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, spatialAnchorMSFT_map_); }
template<> inline SpatialAnchorStoreConnectionMSFTWrapper* OpenXrStateHandleTable::GetWrapper<SpatialAnchorStoreConnectionMSFTWrapper>(SpatialAnchorStoreConnectionMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, spatialAnchorStoreConnectionMSFT_map_); }
template<> inline SpatialGraphNodeBindingMSFTWrapper* OpenXrStateHandleTable::GetWrapper<SpatialGraphNodeBindingMSFTWrapper>(SpatialGraphNodeBindingMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, spatialGraphNodeBindingMSFT_map_); }
template<> inline SwapchainWrapper* OpenXrStateHandleTable::GetWrapper<SwapchainWrapper>(Swapchain handle) { return OpenXrStateTableBase::GetWrapper(handle, swapchain_map_); }
template<> inline TriangleMeshFBWrapper* OpenXrStateHandleTable::GetWrapper<TriangleMeshFBWrapper>(TriangleMeshFB handle) { return OpenXrStateTableBase::GetWrapper(handle, triangleMeshFB_map_); }
template<> inline VirtualKeyboardMETAWrapper* OpenXrStateHandleTable::GetWrapper<VirtualKeyboardMETAWrapper>(VirtualKeyboardMETA handle) { return OpenXrStateTableBase::GetWrapper(handle, virtualKeyboardMETA_map_); }

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif //  GFXRECON_GENERATED_OPENXR_STATE_TABLE_H
