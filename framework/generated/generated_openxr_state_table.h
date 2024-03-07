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

    bool InsertWrapper(format::HandleId id, openxr_wrappers::ActionWrapper* wrapper) { return InsertEntry(id, wrapper, action_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::ActionSetWrapper* wrapper) { return InsertEntry(id, wrapper, actionSet_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::BodyTrackerFBWrapper* wrapper) { return InsertEntry(id, wrapper, bodyTrackerFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(id, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::ExportedLocalizationMapMLWrapper* wrapper) { return InsertEntry(id, wrapper, exportedLocalizationMapML_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::EyeTrackerFBWrapper* wrapper) { return InsertEntry(id, wrapper, eyeTrackerFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::FaceTracker2FBWrapper* wrapper) { return InsertEntry(id, wrapper, faceTracker2FB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::FaceTrackerFBWrapper* wrapper) { return InsertEntry(id, wrapper, faceTrackerFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::FacialTrackerHTCWrapper* wrapper) { return InsertEntry(id, wrapper, facialTrackerHTC_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::FoveationProfileFBWrapper* wrapper) { return InsertEntry(id, wrapper, foveationProfileFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::GeometryInstanceFBWrapper* wrapper) { return InsertEntry(id, wrapper, geometryInstanceFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::HandTrackerEXTWrapper* wrapper) { return InsertEntry(id, wrapper, handTrackerEXT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::InstanceWrapper* wrapper) { return InsertEntry(id, wrapper, instance_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::MarkerDetectorMLWrapper* wrapper) { return InsertEntry(id, wrapper, markerDetectorML_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PassthroughColorLutMETAWrapper* wrapper) { return InsertEntry(id, wrapper, passthroughColorLutMETA_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PassthroughFBWrapper* wrapper) { return InsertEntry(id, wrapper, passthroughFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PassthroughHTCWrapper* wrapper) { return InsertEntry(id, wrapper, passthroughHTC_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PassthroughLayerFBWrapper* wrapper) { return InsertEntry(id, wrapper, passthroughLayerFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PlaneDetectorEXTWrapper* wrapper) { return InsertEntry(id, wrapper, planeDetectorEXT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SceneMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, sceneMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SceneObserverMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, sceneObserverMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SessionWrapper* wrapper) { return InsertEntry(id, wrapper, session_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SpaceWrapper* wrapper) { return InsertEntry(id, wrapper, space_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SpaceUserFBWrapper* wrapper) { return InsertEntry(id, wrapper, spaceUserFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SpatialAnchorMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, spatialAnchorMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, spatialAnchorStoreConnectionMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, spatialGraphNodeBindingMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SwapchainWrapper* wrapper) { return InsertEntry(id, wrapper, swapchain_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::TriangleMeshFBWrapper* wrapper) { return InsertEntry(id, wrapper, triangleMeshFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::VirtualKeyboardMETAWrapper* wrapper) { return InsertEntry(id, wrapper, virtualKeyboardMETA_map_); }

    bool RemoveWrapper(const openxr_wrappers::ActionWrapper* wrapper) { return RemoveEntry(wrapper, action_map_); }
    bool RemoveWrapper(const openxr_wrappers::ActionSetWrapper* wrapper) { return RemoveEntry(wrapper, actionSet_map_); }
    bool RemoveWrapper(const openxr_wrappers::BodyTrackerFBWrapper* wrapper) { return RemoveEntry(wrapper, bodyTrackerFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { return RemoveEntry(wrapper, debugUtilsMessengerEXT_map_); }
    bool RemoveWrapper(const openxr_wrappers::ExportedLocalizationMapMLWrapper* wrapper) { return RemoveEntry(wrapper, exportedLocalizationMapML_map_); }
    bool RemoveWrapper(const openxr_wrappers::EyeTrackerFBWrapper* wrapper) { return RemoveEntry(wrapper, eyeTrackerFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::FaceTracker2FBWrapper* wrapper) { return RemoveEntry(wrapper, faceTracker2FB_map_); }
    bool RemoveWrapper(const openxr_wrappers::FaceTrackerFBWrapper* wrapper) { return RemoveEntry(wrapper, faceTrackerFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::FacialTrackerHTCWrapper* wrapper) { return RemoveEntry(wrapper, facialTrackerHTC_map_); }
    bool RemoveWrapper(const openxr_wrappers::FoveationProfileFBWrapper* wrapper) { return RemoveEntry(wrapper, foveationProfileFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::GeometryInstanceFBWrapper* wrapper) { return RemoveEntry(wrapper, geometryInstanceFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::HandTrackerEXTWrapper* wrapper) { return RemoveEntry(wrapper, handTrackerEXT_map_); }
    bool RemoveWrapper(const openxr_wrappers::InstanceWrapper* wrapper) { return RemoveEntry(wrapper, instance_map_); }
    bool RemoveWrapper(const openxr_wrappers::MarkerDetectorMLWrapper* wrapper) { return RemoveEntry(wrapper, markerDetectorML_map_); }
    bool RemoveWrapper(const openxr_wrappers::PassthroughColorLutMETAWrapper* wrapper) { return RemoveEntry(wrapper, passthroughColorLutMETA_map_); }
    bool RemoveWrapper(const openxr_wrappers::PassthroughFBWrapper* wrapper) { return RemoveEntry(wrapper, passthroughFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::PassthroughHTCWrapper* wrapper) { return RemoveEntry(wrapper, passthroughHTC_map_); }
    bool RemoveWrapper(const openxr_wrappers::PassthroughLayerFBWrapper* wrapper) { return RemoveEntry(wrapper, passthroughLayerFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::PlaneDetectorEXTWrapper* wrapper) { return RemoveEntry(wrapper, planeDetectorEXT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SceneMSFTWrapper* wrapper) { return RemoveEntry(wrapper, sceneMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SceneObserverMSFTWrapper* wrapper) { return RemoveEntry(wrapper, sceneObserverMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SessionWrapper* wrapper) { return RemoveEntry(wrapper, session_map_); }
    bool RemoveWrapper(const openxr_wrappers::SpaceWrapper* wrapper) { return RemoveEntry(wrapper, space_map_); }
    bool RemoveWrapper(const openxr_wrappers::SpaceUserFBWrapper* wrapper) { return RemoveEntry(wrapper, spaceUserFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::SpatialAnchorMSFTWrapper* wrapper) { return RemoveEntry(wrapper, spatialAnchorMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* wrapper) { return RemoveEntry(wrapper, spatialAnchorStoreConnectionMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* wrapper) { return RemoveEntry(wrapper, spatialGraphNodeBindingMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SwapchainWrapper* wrapper) { return RemoveEntry(wrapper, swapchain_map_); }
    bool RemoveWrapper(const openxr_wrappers::TriangleMeshFBWrapper* wrapper) { return RemoveEntry(wrapper, triangleMeshFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::VirtualKeyboardMETAWrapper* wrapper) { return RemoveEntry(wrapper, virtualKeyboardMETA_map_); }

    const openxr_wrappers::ActionWrapper* GetOpenXrActionWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::ActionWrapper>(id, action_map_); }
    const openxr_wrappers::ActionSetWrapper* GetOpenXrActionSetWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::ActionSetWrapper>(id, actionSet_map_); }
    const openxr_wrappers::BodyTrackerFBWrapper* GetOpenXrBodyTrackerFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::BodyTrackerFBWrapper>(id, bodyTrackerFB_map_); }
    const openxr_wrappers::DebugUtilsMessengerEXTWrapper* GetOpenXrDebugUtilsMessengerEXTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(id, debugUtilsMessengerEXT_map_); }
    const openxr_wrappers::ExportedLocalizationMapMLWrapper* GetOpenXrExportedLocalizationMapMLWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::ExportedLocalizationMapMLWrapper>(id, exportedLocalizationMapML_map_); }
    const openxr_wrappers::EyeTrackerFBWrapper* GetOpenXrEyeTrackerFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::EyeTrackerFBWrapper>(id, eyeTrackerFB_map_); }
    const openxr_wrappers::FaceTracker2FBWrapper* GetOpenXrFaceTracker2FBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::FaceTracker2FBWrapper>(id, faceTracker2FB_map_); }
    const openxr_wrappers::FaceTrackerFBWrapper* GetOpenXrFaceTrackerFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::FaceTrackerFBWrapper>(id, faceTrackerFB_map_); }
    const openxr_wrappers::FacialTrackerHTCWrapper* GetOpenXrFacialTrackerHTCWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::FacialTrackerHTCWrapper>(id, facialTrackerHTC_map_); }
    const openxr_wrappers::FoveationProfileFBWrapper* GetOpenXrFoveationProfileFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::FoveationProfileFBWrapper>(id, foveationProfileFB_map_); }
    const openxr_wrappers::GeometryInstanceFBWrapper* GetOpenXrGeometryInstanceFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::GeometryInstanceFBWrapper>(id, geometryInstanceFB_map_); }
    const openxr_wrappers::HandTrackerEXTWrapper* GetOpenXrHandTrackerEXTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::HandTrackerEXTWrapper>(id, handTrackerEXT_map_); }
    const openxr_wrappers::InstanceWrapper* GetOpenXrInstanceWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::InstanceWrapper>(id, instance_map_); }
    const openxr_wrappers::MarkerDetectorMLWrapper* GetOpenXrMarkerDetectorMLWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(id, markerDetectorML_map_); }
    const openxr_wrappers::PassthroughColorLutMETAWrapper* GetOpenXrPassthroughColorLutMETAWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PassthroughColorLutMETAWrapper>(id, passthroughColorLutMETA_map_); }
    const openxr_wrappers::PassthroughFBWrapper* GetOpenXrPassthroughFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PassthroughFBWrapper>(id, passthroughFB_map_); }
    const openxr_wrappers::PassthroughHTCWrapper* GetOpenXrPassthroughHTCWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PassthroughHTCWrapper>(id, passthroughHTC_map_); }
    const openxr_wrappers::PassthroughLayerFBWrapper* GetOpenXrPassthroughLayerFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PassthroughLayerFBWrapper>(id, passthroughLayerFB_map_); }
    const openxr_wrappers::PlaneDetectorEXTWrapper* GetOpenXrPlaneDetectorEXTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PlaneDetectorEXTWrapper>(id, planeDetectorEXT_map_); }
    const openxr_wrappers::SceneMSFTWrapper* GetOpenXrSceneMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SceneMSFTWrapper>(id, sceneMSFT_map_); }
    const openxr_wrappers::SceneObserverMSFTWrapper* GetOpenXrSceneObserverMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SceneObserverMSFTWrapper>(id, sceneObserverMSFT_map_); }
    const openxr_wrappers::SessionWrapper* GetOpenXrSessionWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SessionWrapper>(id, session_map_); }
    const openxr_wrappers::SpaceWrapper* GetOpenXrSpaceWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SpaceWrapper>(id, space_map_); }
    const openxr_wrappers::SpaceUserFBWrapper* GetOpenXrSpaceUserFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SpaceUserFBWrapper>(id, spaceUserFB_map_); }
    const openxr_wrappers::SpatialAnchorMSFTWrapper* GetOpenXrSpatialAnchorMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SpatialAnchorMSFTWrapper>(id, spatialAnchorMSFT_map_); }
    const openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* GetOpenXrSpatialAnchorStoreConnectionMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(id, spatialAnchorStoreConnectionMSFT_map_); }
    const openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* GetOpenXrSpatialGraphNodeBindingMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(id, spatialGraphNodeBindingMSFT_map_); }
    const openxr_wrappers::SwapchainWrapper* GetOpenXrSwapchainWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SwapchainWrapper>(id, swapchain_map_); }
    const openxr_wrappers::TriangleMeshFBWrapper* GetOpenXrTriangleMeshFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(id, triangleMeshFB_map_); }
    const openxr_wrappers::VirtualKeyboardMETAWrapper* GetOpenXrVirtualKeyboardMETAWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::VirtualKeyboardMETAWrapper>(id, virtualKeyboardMETA_map_); }

    openxr_wrappers::ActionWrapper* GetOpenXrActionWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::ActionWrapper>(id, action_map_); }
    openxr_wrappers::ActionSetWrapper* GetOpenXrActionSetWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::ActionSetWrapper>(id, actionSet_map_); }
    openxr_wrappers::BodyTrackerFBWrapper* GetOpenXrBodyTrackerFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::BodyTrackerFBWrapper>(id, bodyTrackerFB_map_); }
    openxr_wrappers::DebugUtilsMessengerEXTWrapper* GetOpenXrDebugUtilsMessengerEXTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(id, debugUtilsMessengerEXT_map_); }
    openxr_wrappers::ExportedLocalizationMapMLWrapper* GetOpenXrExportedLocalizationMapMLWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::ExportedLocalizationMapMLWrapper>(id, exportedLocalizationMapML_map_); }
    openxr_wrappers::EyeTrackerFBWrapper* GetOpenXrEyeTrackerFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::EyeTrackerFBWrapper>(id, eyeTrackerFB_map_); }
    openxr_wrappers::FaceTracker2FBWrapper* GetOpenXrFaceTracker2FBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::FaceTracker2FBWrapper>(id, faceTracker2FB_map_); }
    openxr_wrappers::FaceTrackerFBWrapper* GetOpenXrFaceTrackerFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::FaceTrackerFBWrapper>(id, faceTrackerFB_map_); }
    openxr_wrappers::FacialTrackerHTCWrapper* GetOpenXrFacialTrackerHTCWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::FacialTrackerHTCWrapper>(id, facialTrackerHTC_map_); }
    openxr_wrappers::FoveationProfileFBWrapper* GetOpenXrFoveationProfileFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::FoveationProfileFBWrapper>(id, foveationProfileFB_map_); }
    openxr_wrappers::GeometryInstanceFBWrapper* GetOpenXrGeometryInstanceFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::GeometryInstanceFBWrapper>(id, geometryInstanceFB_map_); }
    openxr_wrappers::HandTrackerEXTWrapper* GetOpenXrHandTrackerEXTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::HandTrackerEXTWrapper>(id, handTrackerEXT_map_); }
    openxr_wrappers::InstanceWrapper* GetOpenXrInstanceWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::InstanceWrapper>(id, instance_map_); }
    openxr_wrappers::MarkerDetectorMLWrapper* GetOpenXrMarkerDetectorMLWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(id, markerDetectorML_map_); }
    openxr_wrappers::PassthroughColorLutMETAWrapper* GetOpenXrPassthroughColorLutMETAWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PassthroughColorLutMETAWrapper>(id, passthroughColorLutMETA_map_); }
    openxr_wrappers::PassthroughFBWrapper* GetOpenXrPassthroughFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PassthroughFBWrapper>(id, passthroughFB_map_); }
    openxr_wrappers::PassthroughHTCWrapper* GetOpenXrPassthroughHTCWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PassthroughHTCWrapper>(id, passthroughHTC_map_); }
    openxr_wrappers::PassthroughLayerFBWrapper* GetOpenXrPassthroughLayerFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PassthroughLayerFBWrapper>(id, passthroughLayerFB_map_); }
    openxr_wrappers::PlaneDetectorEXTWrapper* GetOpenXrPlaneDetectorEXTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PlaneDetectorEXTWrapper>(id, planeDetectorEXT_map_); }
    openxr_wrappers::SceneMSFTWrapper* GetOpenXrSceneMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SceneMSFTWrapper>(id, sceneMSFT_map_); }
    openxr_wrappers::SceneObserverMSFTWrapper* GetOpenXrSceneObserverMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SceneObserverMSFTWrapper>(id, sceneObserverMSFT_map_); }
    openxr_wrappers::SessionWrapper* GetOpenXrSessionWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SessionWrapper>(id, session_map_); }
    openxr_wrappers::SpaceWrapper* GetOpenXrSpaceWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SpaceWrapper>(id, space_map_); }
    openxr_wrappers::SpaceUserFBWrapper* GetOpenXrSpaceUserFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SpaceUserFBWrapper>(id, spaceUserFB_map_); }
    openxr_wrappers::SpatialAnchorMSFTWrapper* GetOpenXrSpatialAnchorMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SpatialAnchorMSFTWrapper>(id, spatialAnchorMSFT_map_); }
    openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* GetOpenXrSpatialAnchorStoreConnectionMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(id, spatialAnchorStoreConnectionMSFT_map_); }
    openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* GetOpenXrSpatialGraphNodeBindingMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(id, spatialGraphNodeBindingMSFT_map_); }
    openxr_wrappers::SwapchainWrapper* GetOpenXrSwapchainWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SwapchainWrapper>(id, swapchain_map_); }
    openxr_wrappers::TriangleMeshFBWrapper* GetOpenXrTriangleMeshFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(id, triangleMeshFB_map_); }
    openxr_wrappers::VirtualKeyboardMETAWrapper* GetOpenXrVirtualKeyboardMETAWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::VirtualKeyboardMETAWrapper>(id, virtualKeyboardMETA_map_); }

    void VisitWrappers(std::function<void(openxr_wrappers::ActionWrapper*)> visitor) const { for (auto entry : action_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::ActionSetWrapper*)> visitor) const { for (auto entry : actionSet_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::BodyTrackerFBWrapper*)> visitor) const { for (auto entry : bodyTrackerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::DebugUtilsMessengerEXTWrapper*)> visitor) const { for (auto entry : debugUtilsMessengerEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::ExportedLocalizationMapMLWrapper*)> visitor) const { for (auto entry : exportedLocalizationMapML_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::EyeTrackerFBWrapper*)> visitor) const { for (auto entry : eyeTrackerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::FaceTracker2FBWrapper*)> visitor) const { for (auto entry : faceTracker2FB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::FaceTrackerFBWrapper*)> visitor) const { for (auto entry : faceTrackerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::FacialTrackerHTCWrapper*)> visitor) const { for (auto entry : facialTrackerHTC_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::FoveationProfileFBWrapper*)> visitor) const { for (auto entry : foveationProfileFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::GeometryInstanceFBWrapper*)> visitor) const { for (auto entry : geometryInstanceFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::HandTrackerEXTWrapper*)> visitor) const { for (auto entry : handTrackerEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::InstanceWrapper*)> visitor) const { for (auto entry : instance_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::MarkerDetectorMLWrapper*)> visitor) const { for (auto entry : markerDetectorML_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PassthroughColorLutMETAWrapper*)> visitor) const { for (auto entry : passthroughColorLutMETA_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PassthroughFBWrapper*)> visitor) const { for (auto entry : passthroughFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PassthroughHTCWrapper*)> visitor) const { for (auto entry : passthroughHTC_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PassthroughLayerFBWrapper*)> visitor) const { for (auto entry : passthroughLayerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PlaneDetectorEXTWrapper*)> visitor) const { for (auto entry : planeDetectorEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SceneMSFTWrapper*)> visitor) const { for (auto entry : sceneMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SceneObserverMSFTWrapper*)> visitor) const { for (auto entry : sceneObserverMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SessionWrapper*)> visitor) const { for (auto entry : session_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SpaceWrapper*)> visitor) const { for (auto entry : space_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SpaceUserFBWrapper*)> visitor) const { for (auto entry : spaceUserFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SpatialAnchorMSFTWrapper*)> visitor) const { for (auto entry : spatialAnchorMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper*)> visitor) const { for (auto entry : spatialAnchorStoreConnectionMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper*)> visitor) const { for (auto entry : spatialGraphNodeBindingMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SwapchainWrapper*)> visitor) const { for (auto entry : swapchain_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::TriangleMeshFBWrapper*)> visitor) const { for (auto entry : triangleMeshFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::VirtualKeyboardMETAWrapper*)> visitor) const { for (auto entry : virtualKeyboardMETA_map_) { visitor(entry.second); } }

  private:
    std::map<format::HandleId, openxr_wrappers::ActionWrapper*> action_map_;
    std::map<format::HandleId, openxr_wrappers::ActionSetWrapper*> actionSet_map_;
    std::map<format::HandleId, openxr_wrappers::BodyTrackerFBWrapper*> bodyTrackerFB_map_;
    std::map<format::HandleId, openxr_wrappers::DebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::map<format::HandleId, openxr_wrappers::ExportedLocalizationMapMLWrapper*> exportedLocalizationMapML_map_;
    std::map<format::HandleId, openxr_wrappers::EyeTrackerFBWrapper*> eyeTrackerFB_map_;
    std::map<format::HandleId, openxr_wrappers::FaceTracker2FBWrapper*> faceTracker2FB_map_;
    std::map<format::HandleId, openxr_wrappers::FaceTrackerFBWrapper*> faceTrackerFB_map_;
    std::map<format::HandleId, openxr_wrappers::FacialTrackerHTCWrapper*> facialTrackerHTC_map_;
    std::map<format::HandleId, openxr_wrappers::FoveationProfileFBWrapper*> foveationProfileFB_map_;
    std::map<format::HandleId, openxr_wrappers::GeometryInstanceFBWrapper*> geometryInstanceFB_map_;
    std::map<format::HandleId, openxr_wrappers::HandTrackerEXTWrapper*> handTrackerEXT_map_;
    std::map<format::HandleId, openxr_wrappers::InstanceWrapper*> instance_map_;
    std::map<format::HandleId, openxr_wrappers::MarkerDetectorMLWrapper*> markerDetectorML_map_;
    std::map<format::HandleId, openxr_wrappers::PassthroughColorLutMETAWrapper*> passthroughColorLutMETA_map_;
    std::map<format::HandleId, openxr_wrappers::PassthroughFBWrapper*> passthroughFB_map_;
    std::map<format::HandleId, openxr_wrappers::PassthroughHTCWrapper*> passthroughHTC_map_;
    std::map<format::HandleId, openxr_wrappers::PassthroughLayerFBWrapper*> passthroughLayerFB_map_;
    std::map<format::HandleId, openxr_wrappers::PlaneDetectorEXTWrapper*> planeDetectorEXT_map_;
    std::map<format::HandleId, openxr_wrappers::SceneMSFTWrapper*> sceneMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::SceneObserverMSFTWrapper*> sceneObserverMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::SessionWrapper*> session_map_;
    std::map<format::HandleId, openxr_wrappers::SpaceWrapper*> space_map_;
    std::map<format::HandleId, openxr_wrappers::SpaceUserFBWrapper*> spaceUserFB_map_;
    std::map<format::HandleId, openxr_wrappers::SpatialAnchorMSFTWrapper*> spatialAnchorMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper*> spatialAnchorStoreConnectionMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper*> spatialGraphNodeBindingMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::SwapchainWrapper*> swapchain_map_;
    std::map<format::HandleId, openxr_wrappers::TriangleMeshFBWrapper*> triangleMeshFB_map_;
    std::map<format::HandleId, openxr_wrappers::VirtualKeyboardMETAWrapper*> virtualKeyboardMETA_map_;
};

class OpenXrStateHandleTable : OpenXrStateTableBase
{
  public:
    OpenXrStateHandleTable() {}
    ~OpenXrStateHandleTable() {}

    bool InsertWrapper(openxr_wrappers::ActionWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, action_map_); }
    bool InsertWrapper(openxr_wrappers::ActionSetWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, actionSet_map_); }
    bool InsertWrapper(openxr_wrappers::BodyTrackerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, bodyTrackerFB_map_); }
    bool InsertWrapper(openxr_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(openxr_wrappers::ExportedLocalizationMapMLWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, exportedLocalizationMapML_map_); }
    bool InsertWrapper(openxr_wrappers::EyeTrackerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, eyeTrackerFB_map_); }
    bool InsertWrapper(openxr_wrappers::FaceTracker2FBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, faceTracker2FB_map_); }
    bool InsertWrapper(openxr_wrappers::FaceTrackerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, faceTrackerFB_map_); }
    bool InsertWrapper(openxr_wrappers::FacialTrackerHTCWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, facialTrackerHTC_map_); }
    bool InsertWrapper(openxr_wrappers::FoveationProfileFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, foveationProfileFB_map_); }
    bool InsertWrapper(openxr_wrappers::GeometryInstanceFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, geometryInstanceFB_map_); }
    bool InsertWrapper(openxr_wrappers::HandTrackerEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, handTrackerEXT_map_); }
    bool InsertWrapper(openxr_wrappers::InstanceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, instance_map_); }
    bool InsertWrapper(openxr_wrappers::MarkerDetectorMLWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, markerDetectorML_map_); }
    bool InsertWrapper(openxr_wrappers::PassthroughColorLutMETAWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, passthroughColorLutMETA_map_); }
    bool InsertWrapper(openxr_wrappers::PassthroughFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, passthroughFB_map_); }
    bool InsertWrapper(openxr_wrappers::PassthroughHTCWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, passthroughHTC_map_); }
    bool InsertWrapper(openxr_wrappers::PassthroughLayerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, passthroughLayerFB_map_); }
    bool InsertWrapper(openxr_wrappers::PlaneDetectorEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, planeDetectorEXT_map_); }
    bool InsertWrapper(openxr_wrappers::SceneMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, sceneMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::SceneObserverMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, sceneObserverMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::SessionWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, session_map_); }
    bool InsertWrapper(openxr_wrappers::SpaceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, space_map_); }
    bool InsertWrapper(openxr_wrappers::SpaceUserFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, spaceUserFB_map_); }
    bool InsertWrapper(openxr_wrappers::SpatialAnchorMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, spatialAnchorMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, spatialAnchorStoreConnectionMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, spatialGraphNodeBindingMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::SwapchainWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, swapchain_map_); }
    bool InsertWrapper(openxr_wrappers::TriangleMeshFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, triangleMeshFB_map_); }
    bool InsertWrapper(openxr_wrappers::VirtualKeyboardMETAWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, virtualKeyboardMETA_map_); }

    bool RemoveWrapper(const openxr_wrappers::ActionWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, action_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::ActionSetWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, actionSet_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::BodyTrackerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, bodyTrackerFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, debugUtilsMessengerEXT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::ExportedLocalizationMapMLWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, exportedLocalizationMapML_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::EyeTrackerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, eyeTrackerFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::FaceTracker2FBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, faceTracker2FB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::FaceTrackerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, faceTrackerFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::FacialTrackerHTCWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, facialTrackerHTC_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::FoveationProfileFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, foveationProfileFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::GeometryInstanceFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, geometryInstanceFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::HandTrackerEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, handTrackerEXT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::InstanceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, instance_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::MarkerDetectorMLWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, markerDetectorML_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PassthroughColorLutMETAWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, passthroughColorLutMETA_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PassthroughFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, passthroughFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PassthroughHTCWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, passthroughHTC_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PassthroughLayerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, passthroughLayerFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PlaneDetectorEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, planeDetectorEXT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SceneMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, sceneMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SceneObserverMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, sceneObserverMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SessionWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, session_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SpaceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, space_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SpaceUserFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, spaceUserFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SpatialAnchorMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, spatialAnchorMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, spatialAnchorStoreConnectionMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, spatialGraphNodeBindingMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SwapchainWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, swapchain_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::TriangleMeshFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, triangleMeshFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::VirtualKeyboardMETAWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, virtualKeyboardMETA_map_);
    }

    template<typename Wrapper> const Wrapper* GetWrapper(typename Wrapper::HandleType handle) const { return nullptr; }

    template<typename Wrapper> Wrapper* GetWrapper(typename Wrapper::HandleType handle) { return nullptr; }

  private:
    std::unordered_map<XrAction, openxr_wrappers::ActionWrapper*> action_map_;
    std::unordered_map<XrActionSet, openxr_wrappers::ActionSetWrapper*> actionSet_map_;
    std::unordered_map<XrBodyTrackerFB, openxr_wrappers::BodyTrackerFBWrapper*> bodyTrackerFB_map_;
    std::unordered_map<XrDebugUtilsMessengerEXT, openxr_wrappers::DebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::unordered_map<XrExportedLocalizationMapML, openxr_wrappers::ExportedLocalizationMapMLWrapper*> exportedLocalizationMapML_map_;
    std::unordered_map<XrEyeTrackerFB, openxr_wrappers::EyeTrackerFBWrapper*> eyeTrackerFB_map_;
    std::unordered_map<XrFaceTracker2FB, openxr_wrappers::FaceTracker2FBWrapper*> faceTracker2FB_map_;
    std::unordered_map<XrFaceTrackerFB, openxr_wrappers::FaceTrackerFBWrapper*> faceTrackerFB_map_;
    std::unordered_map<XrFacialTrackerHTC, openxr_wrappers::FacialTrackerHTCWrapper*> facialTrackerHTC_map_;
    std::unordered_map<XrFoveationProfileFB, openxr_wrappers::FoveationProfileFBWrapper*> foveationProfileFB_map_;
    std::unordered_map<XrGeometryInstanceFB, openxr_wrappers::GeometryInstanceFBWrapper*> geometryInstanceFB_map_;
    std::unordered_map<XrHandTrackerEXT, openxr_wrappers::HandTrackerEXTWrapper*> handTrackerEXT_map_;
    std::unordered_map<XrInstance, openxr_wrappers::InstanceWrapper*> instance_map_;
    std::unordered_map<XrMarkerDetectorML, openxr_wrappers::MarkerDetectorMLWrapper*> markerDetectorML_map_;
    std::unordered_map<XrPassthroughColorLutMETA, openxr_wrappers::PassthroughColorLutMETAWrapper*> passthroughColorLutMETA_map_;
    std::unordered_map<XrPassthroughFB, openxr_wrappers::PassthroughFBWrapper*> passthroughFB_map_;
    std::unordered_map<XrPassthroughHTC, openxr_wrappers::PassthroughHTCWrapper*> passthroughHTC_map_;
    std::unordered_map<XrPassthroughLayerFB, openxr_wrappers::PassthroughLayerFBWrapper*> passthroughLayerFB_map_;
    std::unordered_map<XrPlaneDetectorEXT, openxr_wrappers::PlaneDetectorEXTWrapper*> planeDetectorEXT_map_;
    std::unordered_map<XrSceneMSFT, openxr_wrappers::SceneMSFTWrapper*> sceneMSFT_map_;
    std::unordered_map<XrSceneObserverMSFT, openxr_wrappers::SceneObserverMSFTWrapper*> sceneObserverMSFT_map_;
    std::unordered_map<XrSession, openxr_wrappers::SessionWrapper*> session_map_;
    std::unordered_map<XrSpace, openxr_wrappers::SpaceWrapper*> space_map_;
    std::unordered_map<XrSpaceUserFB, openxr_wrappers::SpaceUserFBWrapper*> spaceUserFB_map_;
    std::unordered_map<XrSpatialAnchorMSFT, openxr_wrappers::SpatialAnchorMSFTWrapper*> spatialAnchorMSFT_map_;
    std::unordered_map<XrSpatialAnchorStoreConnectionMSFT, openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper*> spatialAnchorStoreConnectionMSFT_map_;
    std::unordered_map<XrSpatialGraphNodeBindingMSFT, openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper*> spatialGraphNodeBindingMSFT_map_;
    std::unordered_map<XrSwapchain, openxr_wrappers::SwapchainWrapper*> swapchain_map_;
    std::unordered_map<XrTriangleMeshFB, openxr_wrappers::TriangleMeshFBWrapper*> triangleMeshFB_map_;
    std::unordered_map<XrVirtualKeyboardMETA, openxr_wrappers::VirtualKeyboardMETAWrapper*> virtualKeyboardMETA_map_;
};

template<> inline const openxr_wrappers::ActionWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ActionWrapper>(XrAction handle) const { return OpenXrStateTableBase::GetWrapper(handle, action_map_); }
template<> inline const openxr_wrappers::ActionSetWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ActionSetWrapper>(XrActionSet handle) const { return OpenXrStateTableBase::GetWrapper(handle, actionSet_map_); }
template<> inline const openxr_wrappers::BodyTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::BodyTrackerFBWrapper>(XrBodyTrackerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, bodyTrackerFB_map_); }
template<> inline const openxr_wrappers::DebugUtilsMessengerEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(XrDebugUtilsMessengerEXT handle) const { return OpenXrStateTableBase::GetWrapper(handle, debugUtilsMessengerEXT_map_); }
template<> inline const openxr_wrappers::ExportedLocalizationMapMLWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ExportedLocalizationMapMLWrapper>(XrExportedLocalizationMapML handle) const { return OpenXrStateTableBase::GetWrapper(handle, exportedLocalizationMapML_map_); }
template<> inline const openxr_wrappers::EyeTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::EyeTrackerFBWrapper>(XrEyeTrackerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, eyeTrackerFB_map_); }
template<> inline const openxr_wrappers::FaceTracker2FBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FaceTracker2FBWrapper>(XrFaceTracker2FB handle) const { return OpenXrStateTableBase::GetWrapper(handle, faceTracker2FB_map_); }
template<> inline const openxr_wrappers::FaceTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FaceTrackerFBWrapper>(XrFaceTrackerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, faceTrackerFB_map_); }
template<> inline const openxr_wrappers::FacialTrackerHTCWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FacialTrackerHTCWrapper>(XrFacialTrackerHTC handle) const { return OpenXrStateTableBase::GetWrapper(handle, facialTrackerHTC_map_); }
template<> inline const openxr_wrappers::FoveationProfileFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FoveationProfileFBWrapper>(XrFoveationProfileFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, foveationProfileFB_map_); }
template<> inline const openxr_wrappers::GeometryInstanceFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::GeometryInstanceFBWrapper>(XrGeometryInstanceFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, geometryInstanceFB_map_); }
template<> inline const openxr_wrappers::HandTrackerEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::HandTrackerEXTWrapper>(XrHandTrackerEXT handle) const { return OpenXrStateTableBase::GetWrapper(handle, handTrackerEXT_map_); }
template<> inline const openxr_wrappers::InstanceWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::InstanceWrapper>(XrInstance handle) const { return OpenXrStateTableBase::GetWrapper(handle, instance_map_); }
template<> inline const openxr_wrappers::MarkerDetectorMLWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(XrMarkerDetectorML handle) const { return OpenXrStateTableBase::GetWrapper(handle, markerDetectorML_map_); }
template<> inline const openxr_wrappers::PassthroughColorLutMETAWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughColorLutMETAWrapper>(XrPassthroughColorLutMETA handle) const { return OpenXrStateTableBase::GetWrapper(handle, passthroughColorLutMETA_map_); }
template<> inline const openxr_wrappers::PassthroughFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughFBWrapper>(XrPassthroughFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, passthroughFB_map_); }
template<> inline const openxr_wrappers::PassthroughHTCWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughHTCWrapper>(XrPassthroughHTC handle) const { return OpenXrStateTableBase::GetWrapper(handle, passthroughHTC_map_); }
template<> inline const openxr_wrappers::PassthroughLayerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughLayerFBWrapper>(XrPassthroughLayerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, passthroughLayerFB_map_); }
template<> inline const openxr_wrappers::PlaneDetectorEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PlaneDetectorEXTWrapper>(XrPlaneDetectorEXT handle) const { return OpenXrStateTableBase::GetWrapper(handle, planeDetectorEXT_map_); }
template<> inline const openxr_wrappers::SceneMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SceneMSFTWrapper>(XrSceneMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, sceneMSFT_map_); }
template<> inline const openxr_wrappers::SceneObserverMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SceneObserverMSFTWrapper>(XrSceneObserverMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, sceneObserverMSFT_map_); }
template<> inline const openxr_wrappers::SessionWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SessionWrapper>(XrSession handle) const { return OpenXrStateTableBase::GetWrapper(handle, session_map_); }
template<> inline const openxr_wrappers::SpaceWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpaceWrapper>(XrSpace handle) const { return OpenXrStateTableBase::GetWrapper(handle, space_map_); }
template<> inline const openxr_wrappers::SpaceUserFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpaceUserFBWrapper>(XrSpaceUserFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, spaceUserFB_map_); }
template<> inline const openxr_wrappers::SpatialAnchorMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialAnchorMSFTWrapper>(XrSpatialAnchorMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, spatialAnchorMSFT_map_); }
template<> inline const openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(XrSpatialAnchorStoreConnectionMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, spatialAnchorStoreConnectionMSFT_map_); }
template<> inline const openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(XrSpatialGraphNodeBindingMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, spatialGraphNodeBindingMSFT_map_); }
template<> inline const openxr_wrappers::SwapchainWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SwapchainWrapper>(XrSwapchain handle) const { return OpenXrStateTableBase::GetWrapper(handle, swapchain_map_); }
template<> inline const openxr_wrappers::TriangleMeshFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(XrTriangleMeshFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, triangleMeshFB_map_); }
template<> inline const openxr_wrappers::VirtualKeyboardMETAWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::VirtualKeyboardMETAWrapper>(XrVirtualKeyboardMETA handle) const { return OpenXrStateTableBase::GetWrapper(handle, virtualKeyboardMETA_map_); }

template<> inline openxr_wrappers::ActionWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ActionWrapper>(XrAction handle) { return OpenXrStateTableBase::GetWrapper(handle, action_map_); }
template<> inline openxr_wrappers::ActionSetWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ActionSetWrapper>(XrActionSet handle) { return OpenXrStateTableBase::GetWrapper(handle, actionSet_map_); }
template<> inline openxr_wrappers::BodyTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::BodyTrackerFBWrapper>(XrBodyTrackerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, bodyTrackerFB_map_); }
template<> inline openxr_wrappers::DebugUtilsMessengerEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(XrDebugUtilsMessengerEXT handle) { return OpenXrStateTableBase::GetWrapper(handle, debugUtilsMessengerEXT_map_); }
template<> inline openxr_wrappers::ExportedLocalizationMapMLWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ExportedLocalizationMapMLWrapper>(XrExportedLocalizationMapML handle) { return OpenXrStateTableBase::GetWrapper(handle, exportedLocalizationMapML_map_); }
template<> inline openxr_wrappers::EyeTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::EyeTrackerFBWrapper>(XrEyeTrackerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, eyeTrackerFB_map_); }
template<> inline openxr_wrappers::FaceTracker2FBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FaceTracker2FBWrapper>(XrFaceTracker2FB handle) { return OpenXrStateTableBase::GetWrapper(handle, faceTracker2FB_map_); }
template<> inline openxr_wrappers::FaceTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FaceTrackerFBWrapper>(XrFaceTrackerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, faceTrackerFB_map_); }
template<> inline openxr_wrappers::FacialTrackerHTCWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FacialTrackerHTCWrapper>(XrFacialTrackerHTC handle) { return OpenXrStateTableBase::GetWrapper(handle, facialTrackerHTC_map_); }
template<> inline openxr_wrappers::FoveationProfileFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FoveationProfileFBWrapper>(XrFoveationProfileFB handle) { return OpenXrStateTableBase::GetWrapper(handle, foveationProfileFB_map_); }
template<> inline openxr_wrappers::GeometryInstanceFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::GeometryInstanceFBWrapper>(XrGeometryInstanceFB handle) { return OpenXrStateTableBase::GetWrapper(handle, geometryInstanceFB_map_); }
template<> inline openxr_wrappers::HandTrackerEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::HandTrackerEXTWrapper>(XrHandTrackerEXT handle) { return OpenXrStateTableBase::GetWrapper(handle, handTrackerEXT_map_); }
template<> inline openxr_wrappers::InstanceWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::InstanceWrapper>(XrInstance handle) { return OpenXrStateTableBase::GetWrapper(handle, instance_map_); }
template<> inline openxr_wrappers::MarkerDetectorMLWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(XrMarkerDetectorML handle) { return OpenXrStateTableBase::GetWrapper(handle, markerDetectorML_map_); }
template<> inline openxr_wrappers::PassthroughColorLutMETAWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughColorLutMETAWrapper>(XrPassthroughColorLutMETA handle) { return OpenXrStateTableBase::GetWrapper(handle, passthroughColorLutMETA_map_); }
template<> inline openxr_wrappers::PassthroughFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughFBWrapper>(XrPassthroughFB handle) { return OpenXrStateTableBase::GetWrapper(handle, passthroughFB_map_); }
template<> inline openxr_wrappers::PassthroughHTCWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughHTCWrapper>(XrPassthroughHTC handle) { return OpenXrStateTableBase::GetWrapper(handle, passthroughHTC_map_); }
template<> inline openxr_wrappers::PassthroughLayerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughLayerFBWrapper>(XrPassthroughLayerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, passthroughLayerFB_map_); }
template<> inline openxr_wrappers::PlaneDetectorEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PlaneDetectorEXTWrapper>(XrPlaneDetectorEXT handle) { return OpenXrStateTableBase::GetWrapper(handle, planeDetectorEXT_map_); }
template<> inline openxr_wrappers::SceneMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SceneMSFTWrapper>(XrSceneMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, sceneMSFT_map_); }
template<> inline openxr_wrappers::SceneObserverMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SceneObserverMSFTWrapper>(XrSceneObserverMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, sceneObserverMSFT_map_); }
template<> inline openxr_wrappers::SessionWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SessionWrapper>(XrSession handle) { return OpenXrStateTableBase::GetWrapper(handle, session_map_); }
template<> inline openxr_wrappers::SpaceWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpaceWrapper>(XrSpace handle) { return OpenXrStateTableBase::GetWrapper(handle, space_map_); }
template<> inline openxr_wrappers::SpaceUserFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpaceUserFBWrapper>(XrSpaceUserFB handle) { return OpenXrStateTableBase::GetWrapper(handle, spaceUserFB_map_); }
template<> inline openxr_wrappers::SpatialAnchorMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialAnchorMSFTWrapper>(XrSpatialAnchorMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, spatialAnchorMSFT_map_); }
template<> inline openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(XrSpatialAnchorStoreConnectionMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, spatialAnchorStoreConnectionMSFT_map_); }
template<> inline openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(XrSpatialGraphNodeBindingMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, spatialGraphNodeBindingMSFT_map_); }
template<> inline openxr_wrappers::SwapchainWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SwapchainWrapper>(XrSwapchain handle) { return OpenXrStateTableBase::GetWrapper(handle, swapchain_map_); }
template<> inline openxr_wrappers::TriangleMeshFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(XrTriangleMeshFB handle) { return OpenXrStateTableBase::GetWrapper(handle, triangleMeshFB_map_); }
template<> inline openxr_wrappers::VirtualKeyboardMETAWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::VirtualKeyboardMETAWrapper>(XrVirtualKeyboardMETA handle) { return OpenXrStateTableBase::GetWrapper(handle, virtualKeyboardMETA_map_); }

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif //  GFXRECON_GENERATED_OPENXR_STATE_TABLE_H
