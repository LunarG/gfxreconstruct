/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#if ENABLE_OPENXR_SUPPORT

#include "decode/openxr_object_info_table_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class OpenXrObjectInfoTable : OpenXrObjectInfoTableBase
{
  public:
    OpenXrObjectInfoTable() {}
    ~OpenXrObjectInfoTable() {}

    void AddXrActionInfo(OpenXrActionInfo&& info) { AddXrObjectInfo(std::move(info), &action_map_); }
    void AddXrActionSetInfo(OpenXrActionSetInfo&& info) { AddXrObjectInfo(std::move(info), &actionSet_map_); }
    void AddXrAsyncRequestIdFBInfo(OpenXrAsyncRequestIdFBInfo&& info) { AddXrObjectInfo(std::move(info), &asyncRequestIdFB_map_); }
    void AddXrBodyTrackerFBInfo(OpenXrBodyTrackerFBInfo&& info) { AddXrObjectInfo(std::move(info), &bodyTrackerFB_map_); }
    void AddXrControllerModelKeyMSFTInfo(OpenXrControllerModelKeyMSFTInfo&& info) { AddXrObjectInfo(std::move(info), &controllerModelKeyMSFT_map_); }
    void AddXrDebugUtilsMessengerEXTInfo(OpenXrDebugUtilsMessengerEXTInfo&& info) { AddXrObjectInfo(std::move(info), &debugUtilsMessengerEXT_map_); }
    void AddXrEnvironmentDepthProviderMETAInfo(OpenXrEnvironmentDepthProviderMETAInfo&& info) { AddXrObjectInfo(std::move(info), &environmentDepthProviderMETA_map_); }
    void AddXrEnvironmentDepthSwapchainMETAInfo(OpenXrEnvironmentDepthSwapchainMETAInfo&& info) { AddXrObjectInfo(std::move(info), &environmentDepthSwapchainMETA_map_); }
    void AddXrExportedLocalizationMapMLInfo(OpenXrExportedLocalizationMapMLInfo&& info) { AddXrObjectInfo(std::move(info), &exportedLocalizationMapML_map_); }
    void AddXrEyeTrackerFBInfo(OpenXrEyeTrackerFBInfo&& info) { AddXrObjectInfo(std::move(info), &eyeTrackerFB_map_); }
    void AddXrFaceTracker2FBInfo(OpenXrFaceTracker2FBInfo&& info) { AddXrObjectInfo(std::move(info), &faceTracker2FB_map_); }
    void AddXrFaceTrackerFBInfo(OpenXrFaceTrackerFBInfo&& info) { AddXrObjectInfo(std::move(info), &faceTrackerFB_map_); }
    void AddXrFacialTrackerHTCInfo(OpenXrFacialTrackerHTCInfo&& info) { AddXrObjectInfo(std::move(info), &facialTrackerHTC_map_); }
    void AddXrFoveationProfileFBInfo(OpenXrFoveationProfileFBInfo&& info) { AddXrObjectInfo(std::move(info), &foveationProfileFB_map_); }
    void AddXrFutureEXTInfo(OpenXrFutureEXTInfo&& info) { AddXrObjectInfo(std::move(info), &futureEXT_map_); }
    void AddXrGeometryInstanceFBInfo(OpenXrGeometryInstanceFBInfo&& info) { AddXrObjectInfo(std::move(info), &geometryInstanceFB_map_); }
    void AddXrHandTrackerEXTInfo(OpenXrHandTrackerEXTInfo&& info) { AddXrObjectInfo(std::move(info), &handTrackerEXT_map_); }
    void AddXrInstanceInfo(OpenXrInstanceInfo&& info) { AddXrObjectInfo(std::move(info), &instance_map_); }
    void AddXrMarkerDetectorMLInfo(OpenXrMarkerDetectorMLInfo&& info) { AddXrObjectInfo(std::move(info), &markerDetectorML_map_); }
    void AddXrMarkerMLInfo(OpenXrMarkerMLInfo&& info) { AddXrObjectInfo(std::move(info), &markerML_map_); }
    void AddXrPassthroughColorLutMETAInfo(OpenXrPassthroughColorLutMETAInfo&& info) { AddXrObjectInfo(std::move(info), &passthroughColorLutMETA_map_); }
    void AddXrPassthroughFBInfo(OpenXrPassthroughFBInfo&& info) { AddXrObjectInfo(std::move(info), &passthroughFB_map_); }
    void AddXrPassthroughHTCInfo(OpenXrPassthroughHTCInfo&& info) { AddXrObjectInfo(std::move(info), &passthroughHTC_map_); }
    void AddXrPassthroughLayerFBInfo(OpenXrPassthroughLayerFBInfo&& info) { AddXrObjectInfo(std::move(info), &passthroughLayerFB_map_); }
    void AddXrPathInfo(OpenXrPathInfo&& info) { AddXrObjectInfo(std::move(info), &path_map_); }
    void AddXrPlaneDetectorEXTInfo(OpenXrPlaneDetectorEXTInfo&& info) { AddXrObjectInfo(std::move(info), &planeDetectorEXT_map_); }
    void AddXrRenderModelKeyFBInfo(OpenXrRenderModelKeyFBInfo&& info) { AddXrObjectInfo(std::move(info), &renderModelKeyFB_map_); }
    void AddXrSceneMSFTInfo(OpenXrSceneMSFTInfo&& info) { AddXrObjectInfo(std::move(info), &sceneMSFT_map_); }
    void AddXrSceneObserverMSFTInfo(OpenXrSceneObserverMSFTInfo&& info) { AddXrObjectInfo(std::move(info), &sceneObserverMSFT_map_); }
    void AddXrSessionInfo(OpenXrSessionInfo&& info) { AddXrObjectInfo(std::move(info), &session_map_); }
    void AddXrSpaceInfo(OpenXrSpaceInfo&& info) { AddXrObjectInfo(std::move(info), &space_map_); }
    void AddXrSpaceUserFBInfo(OpenXrSpaceUserFBInfo&& info) { AddXrObjectInfo(std::move(info), &spaceUserFB_map_); }
    void AddXrSpatialAnchorMSFTInfo(OpenXrSpatialAnchorMSFTInfo&& info) { AddXrObjectInfo(std::move(info), &spatialAnchorMSFT_map_); }
    void AddXrSpatialAnchorStoreConnectionMSFTInfo(OpenXrSpatialAnchorStoreConnectionMSFTInfo&& info) { AddXrObjectInfo(std::move(info), &spatialAnchorStoreConnectionMSFT_map_); }
    void AddXrSpatialGraphNodeBindingMSFTInfo(OpenXrSpatialGraphNodeBindingMSFTInfo&& info) { AddXrObjectInfo(std::move(info), &spatialGraphNodeBindingMSFT_map_); }
    void AddXrSwapchainInfo(OpenXrSwapchainInfo&& info) { AddXrObjectInfo(std::move(info), &swapchain_map_); }
    void AddXrSystemIdInfo(OpenXrSystemIdInfo&& info) { AddXrObjectInfo(std::move(info), &systemId_map_); }
    void AddXrTriangleMeshFBInfo(OpenXrTriangleMeshFBInfo&& info) { AddXrObjectInfo(std::move(info), &triangleMeshFB_map_); }
    void AddXrVirtualKeyboardMETAInfo(OpenXrVirtualKeyboardMETAInfo&& info) { AddXrObjectInfo(std::move(info), &virtualKeyboardMETA_map_); }

    void RemoveXrActionInfo(format::HandleId id) { action_map_.erase(id); }
    void RemoveXrActionSetInfo(format::HandleId id) { actionSet_map_.erase(id); }
    void RemoveXrAsyncRequestIdFBInfo(format::HandleId id) { asyncRequestIdFB_map_.erase(id); }
    void RemoveXrBodyTrackerFBInfo(format::HandleId id) { bodyTrackerFB_map_.erase(id); }
    void RemoveXrControllerModelKeyMSFTInfo(format::HandleId id) { controllerModelKeyMSFT_map_.erase(id); }
    void RemoveXrDebugUtilsMessengerEXTInfo(format::HandleId id) { debugUtilsMessengerEXT_map_.erase(id); }
    void RemoveXrEnvironmentDepthProviderMETAInfo(format::HandleId id) { environmentDepthProviderMETA_map_.erase(id); }
    void RemoveXrEnvironmentDepthSwapchainMETAInfo(format::HandleId id) { environmentDepthSwapchainMETA_map_.erase(id); }
    void RemoveXrExportedLocalizationMapMLInfo(format::HandleId id) { exportedLocalizationMapML_map_.erase(id); }
    void RemoveXrEyeTrackerFBInfo(format::HandleId id) { eyeTrackerFB_map_.erase(id); }
    void RemoveXrFaceTracker2FBInfo(format::HandleId id) { faceTracker2FB_map_.erase(id); }
    void RemoveXrFaceTrackerFBInfo(format::HandleId id) { faceTrackerFB_map_.erase(id); }
    void RemoveXrFacialTrackerHTCInfo(format::HandleId id) { facialTrackerHTC_map_.erase(id); }
    void RemoveXrFoveationProfileFBInfo(format::HandleId id) { foveationProfileFB_map_.erase(id); }
    void RemoveXrFutureEXTInfo(format::HandleId id) { futureEXT_map_.erase(id); }
    void RemoveXrGeometryInstanceFBInfo(format::HandleId id) { geometryInstanceFB_map_.erase(id); }
    void RemoveXrHandTrackerEXTInfo(format::HandleId id) { handTrackerEXT_map_.erase(id); }
    void RemoveXrInstanceInfo(format::HandleId id) { instance_map_.erase(id); }
    void RemoveXrMarkerDetectorMLInfo(format::HandleId id) { markerDetectorML_map_.erase(id); }
    void RemoveXrMarkerMLInfo(format::HandleId id) { markerML_map_.erase(id); }
    void RemoveXrPassthroughColorLutMETAInfo(format::HandleId id) { passthroughColorLutMETA_map_.erase(id); }
    void RemoveXrPassthroughFBInfo(format::HandleId id) { passthroughFB_map_.erase(id); }
    void RemoveXrPassthroughHTCInfo(format::HandleId id) { passthroughHTC_map_.erase(id); }
    void RemoveXrPassthroughLayerFBInfo(format::HandleId id) { passthroughLayerFB_map_.erase(id); }
    void RemoveXrPathInfo(format::HandleId id) { path_map_.erase(id); }
    void RemoveXrPlaneDetectorEXTInfo(format::HandleId id) { planeDetectorEXT_map_.erase(id); }
    void RemoveXrRenderModelKeyFBInfo(format::HandleId id) { renderModelKeyFB_map_.erase(id); }
    void RemoveXrSceneMSFTInfo(format::HandleId id) { sceneMSFT_map_.erase(id); }
    void RemoveXrSceneObserverMSFTInfo(format::HandleId id) { sceneObserverMSFT_map_.erase(id); }
    void RemoveXrSessionInfo(format::HandleId id) { session_map_.erase(id); }
    void RemoveXrSpaceInfo(format::HandleId id) { space_map_.erase(id); }
    void RemoveXrSpaceUserFBInfo(format::HandleId id) { spaceUserFB_map_.erase(id); }
    void RemoveXrSpatialAnchorMSFTInfo(format::HandleId id) { spatialAnchorMSFT_map_.erase(id); }
    void RemoveXrSpatialAnchorStoreConnectionMSFTInfo(format::HandleId id) { spatialAnchorStoreConnectionMSFT_map_.erase(id); }
    void RemoveXrSpatialGraphNodeBindingMSFTInfo(format::HandleId id) { spatialGraphNodeBindingMSFT_map_.erase(id); }
    void RemoveXrSwapchainInfo(format::HandleId id) { swapchain_map_.erase(id); }
    void RemoveXrSystemIdInfo(format::HandleId id) { systemId_map_.erase(id); }
    void RemoveXrTriangleMeshFBInfo(format::HandleId id) { triangleMeshFB_map_.erase(id); }
    void RemoveXrVirtualKeyboardMETAInfo(format::HandleId id) { virtualKeyboardMETA_map_.erase(id); }

    const OpenXrActionInfo* GetXrActionInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrActionInfo>(id, &action_map_); }
    const OpenXrActionSetInfo* GetXrActionSetInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrActionSetInfo>(id, &actionSet_map_); }
    const OpenXrAsyncRequestIdFBInfo* GetXrAsyncRequestIdFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrAsyncRequestIdFBInfo>(id, &asyncRequestIdFB_map_); }
    const OpenXrBodyTrackerFBInfo* GetXrBodyTrackerFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrBodyTrackerFBInfo>(id, &bodyTrackerFB_map_); }
    const OpenXrControllerModelKeyMSFTInfo* GetXrControllerModelKeyMSFTInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrControllerModelKeyMSFTInfo>(id, &controllerModelKeyMSFT_map_); }
    const OpenXrDebugUtilsMessengerEXTInfo* GetXrDebugUtilsMessengerEXTInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrDebugUtilsMessengerEXTInfo>(id, &debugUtilsMessengerEXT_map_); }
    const OpenXrEnvironmentDepthProviderMETAInfo* GetXrEnvironmentDepthProviderMETAInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrEnvironmentDepthProviderMETAInfo>(id, &environmentDepthProviderMETA_map_); }
    const OpenXrEnvironmentDepthSwapchainMETAInfo* GetXrEnvironmentDepthSwapchainMETAInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrEnvironmentDepthSwapchainMETAInfo>(id, &environmentDepthSwapchainMETA_map_); }
    const OpenXrExportedLocalizationMapMLInfo* GetXrExportedLocalizationMapMLInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrExportedLocalizationMapMLInfo>(id, &exportedLocalizationMapML_map_); }
    const OpenXrEyeTrackerFBInfo* GetXrEyeTrackerFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrEyeTrackerFBInfo>(id, &eyeTrackerFB_map_); }
    const OpenXrFaceTracker2FBInfo* GetXrFaceTracker2FBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrFaceTracker2FBInfo>(id, &faceTracker2FB_map_); }
    const OpenXrFaceTrackerFBInfo* GetXrFaceTrackerFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrFaceTrackerFBInfo>(id, &faceTrackerFB_map_); }
    const OpenXrFacialTrackerHTCInfo* GetXrFacialTrackerHTCInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrFacialTrackerHTCInfo>(id, &facialTrackerHTC_map_); }
    const OpenXrFoveationProfileFBInfo* GetXrFoveationProfileFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrFoveationProfileFBInfo>(id, &foveationProfileFB_map_); }
    const OpenXrFutureEXTInfo* GetXrFutureEXTInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrFutureEXTInfo>(id, &futureEXT_map_); }
    const OpenXrGeometryInstanceFBInfo* GetXrGeometryInstanceFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrGeometryInstanceFBInfo>(id, &geometryInstanceFB_map_); }
    const OpenXrHandTrackerEXTInfo* GetXrHandTrackerEXTInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrHandTrackerEXTInfo>(id, &handTrackerEXT_map_); }
    const OpenXrInstanceInfo* GetXrInstanceInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrInstanceInfo>(id, &instance_map_); }
    const OpenXrMarkerDetectorMLInfo* GetXrMarkerDetectorMLInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrMarkerDetectorMLInfo>(id, &markerDetectorML_map_); }
    const OpenXrMarkerMLInfo* GetXrMarkerMLInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrMarkerMLInfo>(id, &markerML_map_); }
    const OpenXrPassthroughColorLutMETAInfo* GetXrPassthroughColorLutMETAInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrPassthroughColorLutMETAInfo>(id, &passthroughColorLutMETA_map_); }
    const OpenXrPassthroughFBInfo* GetXrPassthroughFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrPassthroughFBInfo>(id, &passthroughFB_map_); }
    const OpenXrPassthroughHTCInfo* GetXrPassthroughHTCInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrPassthroughHTCInfo>(id, &passthroughHTC_map_); }
    const OpenXrPassthroughLayerFBInfo* GetXrPassthroughLayerFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrPassthroughLayerFBInfo>(id, &passthroughLayerFB_map_); }
    const OpenXrPathInfo* GetXrPathInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrPathInfo>(id, &path_map_); }
    const OpenXrPlaneDetectorEXTInfo* GetXrPlaneDetectorEXTInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrPlaneDetectorEXTInfo>(id, &planeDetectorEXT_map_); }
    const OpenXrRenderModelKeyFBInfo* GetXrRenderModelKeyFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrRenderModelKeyFBInfo>(id, &renderModelKeyFB_map_); }
    const OpenXrSceneMSFTInfo* GetXrSceneMSFTInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrSceneMSFTInfo>(id, &sceneMSFT_map_); }
    const OpenXrSceneObserverMSFTInfo* GetXrSceneObserverMSFTInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrSceneObserverMSFTInfo>(id, &sceneObserverMSFT_map_); }
    const OpenXrSessionInfo* GetXrSessionInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrSessionInfo>(id, &session_map_); }
    const OpenXrSpaceInfo* GetXrSpaceInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrSpaceInfo>(id, &space_map_); }
    const OpenXrSpaceUserFBInfo* GetXrSpaceUserFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrSpaceUserFBInfo>(id, &spaceUserFB_map_); }
    const OpenXrSpatialAnchorMSFTInfo* GetXrSpatialAnchorMSFTInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrSpatialAnchorMSFTInfo>(id, &spatialAnchorMSFT_map_); }
    const OpenXrSpatialAnchorStoreConnectionMSFTInfo* GetXrSpatialAnchorStoreConnectionMSFTInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(id, &spatialAnchorStoreConnectionMSFT_map_); }
    const OpenXrSpatialGraphNodeBindingMSFTInfo* GetXrSpatialGraphNodeBindingMSFTInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrSpatialGraphNodeBindingMSFTInfo>(id, &spatialGraphNodeBindingMSFT_map_); }
    const OpenXrSwapchainInfo* GetXrSwapchainInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrSwapchainInfo>(id, &swapchain_map_); }
    const OpenXrSystemIdInfo* GetXrSystemIdInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrSystemIdInfo>(id, &systemId_map_); }
    const OpenXrTriangleMeshFBInfo* GetXrTriangleMeshFBInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrTriangleMeshFBInfo>(id, &triangleMeshFB_map_); }
    const OpenXrVirtualKeyboardMETAInfo* GetXrVirtualKeyboardMETAInfo(format::HandleId id) const { return GetXrObjectInfo<OpenXrVirtualKeyboardMETAInfo>(id, &virtualKeyboardMETA_map_); }

    OpenXrActionInfo* GetXrActionInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrActionInfo>(id, &action_map_); }
    OpenXrActionSetInfo* GetXrActionSetInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrActionSetInfo>(id, &actionSet_map_); }
    OpenXrAsyncRequestIdFBInfo* GetXrAsyncRequestIdFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrAsyncRequestIdFBInfo>(id, &asyncRequestIdFB_map_); }
    OpenXrBodyTrackerFBInfo* GetXrBodyTrackerFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrBodyTrackerFBInfo>(id, &bodyTrackerFB_map_); }
    OpenXrControllerModelKeyMSFTInfo* GetXrControllerModelKeyMSFTInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrControllerModelKeyMSFTInfo>(id, &controllerModelKeyMSFT_map_); }
    OpenXrDebugUtilsMessengerEXTInfo* GetXrDebugUtilsMessengerEXTInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrDebugUtilsMessengerEXTInfo>(id, &debugUtilsMessengerEXT_map_); }
    OpenXrEnvironmentDepthProviderMETAInfo* GetXrEnvironmentDepthProviderMETAInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrEnvironmentDepthProviderMETAInfo>(id, &environmentDepthProviderMETA_map_); }
    OpenXrEnvironmentDepthSwapchainMETAInfo* GetXrEnvironmentDepthSwapchainMETAInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrEnvironmentDepthSwapchainMETAInfo>(id, &environmentDepthSwapchainMETA_map_); }
    OpenXrExportedLocalizationMapMLInfo* GetXrExportedLocalizationMapMLInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrExportedLocalizationMapMLInfo>(id, &exportedLocalizationMapML_map_); }
    OpenXrEyeTrackerFBInfo* GetXrEyeTrackerFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrEyeTrackerFBInfo>(id, &eyeTrackerFB_map_); }
    OpenXrFaceTracker2FBInfo* GetXrFaceTracker2FBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrFaceTracker2FBInfo>(id, &faceTracker2FB_map_); }
    OpenXrFaceTrackerFBInfo* GetXrFaceTrackerFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrFaceTrackerFBInfo>(id, &faceTrackerFB_map_); }
    OpenXrFacialTrackerHTCInfo* GetXrFacialTrackerHTCInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrFacialTrackerHTCInfo>(id, &facialTrackerHTC_map_); }
    OpenXrFoveationProfileFBInfo* GetXrFoveationProfileFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrFoveationProfileFBInfo>(id, &foveationProfileFB_map_); }
    OpenXrFutureEXTInfo* GetXrFutureEXTInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrFutureEXTInfo>(id, &futureEXT_map_); }
    OpenXrGeometryInstanceFBInfo* GetXrGeometryInstanceFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrGeometryInstanceFBInfo>(id, &geometryInstanceFB_map_); }
    OpenXrHandTrackerEXTInfo* GetXrHandTrackerEXTInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrHandTrackerEXTInfo>(id, &handTrackerEXT_map_); }
    OpenXrInstanceInfo* GetXrInstanceInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrInstanceInfo>(id, &instance_map_); }
    OpenXrMarkerDetectorMLInfo* GetXrMarkerDetectorMLInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrMarkerDetectorMLInfo>(id, &markerDetectorML_map_); }
    OpenXrMarkerMLInfo* GetXrMarkerMLInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrMarkerMLInfo>(id, &markerML_map_); }
    OpenXrPassthroughColorLutMETAInfo* GetXrPassthroughColorLutMETAInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrPassthroughColorLutMETAInfo>(id, &passthroughColorLutMETA_map_); }
    OpenXrPassthroughFBInfo* GetXrPassthroughFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrPassthroughFBInfo>(id, &passthroughFB_map_); }
    OpenXrPassthroughHTCInfo* GetXrPassthroughHTCInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrPassthroughHTCInfo>(id, &passthroughHTC_map_); }
    OpenXrPassthroughLayerFBInfo* GetXrPassthroughLayerFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrPassthroughLayerFBInfo>(id, &passthroughLayerFB_map_); }
    OpenXrPathInfo* GetXrPathInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrPathInfo>(id, &path_map_); }
    OpenXrPlaneDetectorEXTInfo* GetXrPlaneDetectorEXTInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrPlaneDetectorEXTInfo>(id, &planeDetectorEXT_map_); }
    OpenXrRenderModelKeyFBInfo* GetXrRenderModelKeyFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrRenderModelKeyFBInfo>(id, &renderModelKeyFB_map_); }
    OpenXrSceneMSFTInfo* GetXrSceneMSFTInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrSceneMSFTInfo>(id, &sceneMSFT_map_); }
    OpenXrSceneObserverMSFTInfo* GetXrSceneObserverMSFTInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrSceneObserverMSFTInfo>(id, &sceneObserverMSFT_map_); }
    OpenXrSessionInfo* GetXrSessionInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrSessionInfo>(id, &session_map_); }
    OpenXrSpaceInfo* GetXrSpaceInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrSpaceInfo>(id, &space_map_); }
    OpenXrSpaceUserFBInfo* GetXrSpaceUserFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrSpaceUserFBInfo>(id, &spaceUserFB_map_); }
    OpenXrSpatialAnchorMSFTInfo* GetXrSpatialAnchorMSFTInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrSpatialAnchorMSFTInfo>(id, &spatialAnchorMSFT_map_); }
    OpenXrSpatialAnchorStoreConnectionMSFTInfo* GetXrSpatialAnchorStoreConnectionMSFTInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(id, &spatialAnchorStoreConnectionMSFT_map_); }
    OpenXrSpatialGraphNodeBindingMSFTInfo* GetXrSpatialGraphNodeBindingMSFTInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrSpatialGraphNodeBindingMSFTInfo>(id, &spatialGraphNodeBindingMSFT_map_); }
    OpenXrSwapchainInfo* GetXrSwapchainInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrSwapchainInfo>(id, &swapchain_map_); }
    OpenXrSystemIdInfo* GetXrSystemIdInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrSystemIdInfo>(id, &systemId_map_); }
    OpenXrTriangleMeshFBInfo* GetXrTriangleMeshFBInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrTriangleMeshFBInfo>(id, &triangleMeshFB_map_); }
    OpenXrVirtualKeyboardMETAInfo* GetXrVirtualKeyboardMETAInfo(format::HandleId id) { return GetXrObjectInfo<OpenXrVirtualKeyboardMETAInfo>(id, &virtualKeyboardMETA_map_); }

    void VisitXrActionInfo(std::function<void(const OpenXrActionInfo*)> visitor) const {  for (const auto& entry : action_map_) { visitor(&entry.second); }  }
    void VisitXrActionSetInfo(std::function<void(const OpenXrActionSetInfo*)> visitor) const {  for (const auto& entry : actionSet_map_) { visitor(&entry.second); }  }
    void VisitXrAsyncRequestIdFBInfo(std::function<void(const OpenXrAsyncRequestIdFBInfo*)> visitor) const {  for (const auto& entry : asyncRequestIdFB_map_) { visitor(&entry.second); }  }
    void VisitXrBodyTrackerFBInfo(std::function<void(const OpenXrBodyTrackerFBInfo*)> visitor) const {  for (const auto& entry : bodyTrackerFB_map_) { visitor(&entry.second); }  }
    void VisitXrControllerModelKeyMSFTInfo(std::function<void(const OpenXrControllerModelKeyMSFTInfo*)> visitor) const {  for (const auto& entry : controllerModelKeyMSFT_map_) { visitor(&entry.second); }  }
    void VisitXrDebugUtilsMessengerEXTInfo(std::function<void(const OpenXrDebugUtilsMessengerEXTInfo*)> visitor) const {  for (const auto& entry : debugUtilsMessengerEXT_map_) { visitor(&entry.second); }  }
    void VisitXrEnvironmentDepthProviderMETAInfo(std::function<void(const OpenXrEnvironmentDepthProviderMETAInfo*)> visitor) const {  for (const auto& entry : environmentDepthProviderMETA_map_) { visitor(&entry.second); }  }
    void VisitXrEnvironmentDepthSwapchainMETAInfo(std::function<void(const OpenXrEnvironmentDepthSwapchainMETAInfo*)> visitor) const {  for (const auto& entry : environmentDepthSwapchainMETA_map_) { visitor(&entry.second); }  }
    void VisitXrExportedLocalizationMapMLInfo(std::function<void(const OpenXrExportedLocalizationMapMLInfo*)> visitor) const {  for (const auto& entry : exportedLocalizationMapML_map_) { visitor(&entry.second); }  }
    void VisitXrEyeTrackerFBInfo(std::function<void(const OpenXrEyeTrackerFBInfo*)> visitor) const {  for (const auto& entry : eyeTrackerFB_map_) { visitor(&entry.second); }  }
    void VisitXrFaceTracker2FBInfo(std::function<void(const OpenXrFaceTracker2FBInfo*)> visitor) const {  for (const auto& entry : faceTracker2FB_map_) { visitor(&entry.second); }  }
    void VisitXrFaceTrackerFBInfo(std::function<void(const OpenXrFaceTrackerFBInfo*)> visitor) const {  for (const auto& entry : faceTrackerFB_map_) { visitor(&entry.second); }  }
    void VisitXrFacialTrackerHTCInfo(std::function<void(const OpenXrFacialTrackerHTCInfo*)> visitor) const {  for (const auto& entry : facialTrackerHTC_map_) { visitor(&entry.second); }  }
    void VisitXrFoveationProfileFBInfo(std::function<void(const OpenXrFoveationProfileFBInfo*)> visitor) const {  for (const auto& entry : foveationProfileFB_map_) { visitor(&entry.second); }  }
    void VisitXrFutureEXTInfo(std::function<void(const OpenXrFutureEXTInfo*)> visitor) const {  for (const auto& entry : futureEXT_map_) { visitor(&entry.second); }  }
    void VisitXrGeometryInstanceFBInfo(std::function<void(const OpenXrGeometryInstanceFBInfo*)> visitor) const {  for (const auto& entry : geometryInstanceFB_map_) { visitor(&entry.second); }  }
    void VisitXrHandTrackerEXTInfo(std::function<void(const OpenXrHandTrackerEXTInfo*)> visitor) const {  for (const auto& entry : handTrackerEXT_map_) { visitor(&entry.second); }  }
    void VisitXrInstanceInfo(std::function<void(const OpenXrInstanceInfo*)> visitor) const {  for (const auto& entry : instance_map_) { visitor(&entry.second); }  }
    void VisitXrMarkerDetectorMLInfo(std::function<void(const OpenXrMarkerDetectorMLInfo*)> visitor) const {  for (const auto& entry : markerDetectorML_map_) { visitor(&entry.second); }  }
    void VisitXrMarkerMLInfo(std::function<void(const OpenXrMarkerMLInfo*)> visitor) const {  for (const auto& entry : markerML_map_) { visitor(&entry.second); }  }
    void VisitXrPassthroughColorLutMETAInfo(std::function<void(const OpenXrPassthroughColorLutMETAInfo*)> visitor) const {  for (const auto& entry : passthroughColorLutMETA_map_) { visitor(&entry.second); }  }
    void VisitXrPassthroughFBInfo(std::function<void(const OpenXrPassthroughFBInfo*)> visitor) const {  for (const auto& entry : passthroughFB_map_) { visitor(&entry.second); }  }
    void VisitXrPassthroughHTCInfo(std::function<void(const OpenXrPassthroughHTCInfo*)> visitor) const {  for (const auto& entry : passthroughHTC_map_) { visitor(&entry.second); }  }
    void VisitXrPassthroughLayerFBInfo(std::function<void(const OpenXrPassthroughLayerFBInfo*)> visitor) const {  for (const auto& entry : passthroughLayerFB_map_) { visitor(&entry.second); }  }
    void VisitXrPathInfo(std::function<void(const OpenXrPathInfo*)> visitor) const {  for (const auto& entry : path_map_) { visitor(&entry.second); }  }
    void VisitXrPlaneDetectorEXTInfo(std::function<void(const OpenXrPlaneDetectorEXTInfo*)> visitor) const {  for (const auto& entry : planeDetectorEXT_map_) { visitor(&entry.second); }  }
    void VisitXrRenderModelKeyFBInfo(std::function<void(const OpenXrRenderModelKeyFBInfo*)> visitor) const {  for (const auto& entry : renderModelKeyFB_map_) { visitor(&entry.second); }  }
    void VisitXrSceneMSFTInfo(std::function<void(const OpenXrSceneMSFTInfo*)> visitor) const {  for (const auto& entry : sceneMSFT_map_) { visitor(&entry.second); }  }
    void VisitXrSceneObserverMSFTInfo(std::function<void(const OpenXrSceneObserverMSFTInfo*)> visitor) const {  for (const auto& entry : sceneObserverMSFT_map_) { visitor(&entry.second); }  }
    void VisitXrSessionInfo(std::function<void(const OpenXrSessionInfo*)> visitor) const {  for (const auto& entry : session_map_) { visitor(&entry.second); }  }
    void VisitXrSpaceInfo(std::function<void(const OpenXrSpaceInfo*)> visitor) const {  for (const auto& entry : space_map_) { visitor(&entry.second); }  }
    void VisitXrSpaceUserFBInfo(std::function<void(const OpenXrSpaceUserFBInfo*)> visitor) const {  for (const auto& entry : spaceUserFB_map_) { visitor(&entry.second); }  }
    void VisitXrSpatialAnchorMSFTInfo(std::function<void(const OpenXrSpatialAnchorMSFTInfo*)> visitor) const {  for (const auto& entry : spatialAnchorMSFT_map_) { visitor(&entry.second); }  }
    void VisitXrSpatialAnchorStoreConnectionMSFTInfo(std::function<void(const OpenXrSpatialAnchorStoreConnectionMSFTInfo*)> visitor) const {  for (const auto& entry : spatialAnchorStoreConnectionMSFT_map_) { visitor(&entry.second); }  }
    void VisitXrSpatialGraphNodeBindingMSFTInfo(std::function<void(const OpenXrSpatialGraphNodeBindingMSFTInfo*)> visitor) const {  for (const auto& entry : spatialGraphNodeBindingMSFT_map_) { visitor(&entry.second); }  }
    void VisitXrSwapchainInfo(std::function<void(const OpenXrSwapchainInfo*)> visitor) const {  for (const auto& entry : swapchain_map_) { visitor(&entry.second); }  }
    void VisitXrSystemIdInfo(std::function<void(const OpenXrSystemIdInfo*)> visitor) const {  for (const auto& entry : systemId_map_) { visitor(&entry.second); }  }
    void VisitXrTriangleMeshFBInfo(std::function<void(const OpenXrTriangleMeshFBInfo*)> visitor) const {  for (const auto& entry : triangleMeshFB_map_) { visitor(&entry.second); }  }
    void VisitXrVirtualKeyboardMETAInfo(std::function<void(const OpenXrVirtualKeyboardMETAInfo*)> visitor) const {  for (const auto& entry : virtualKeyboardMETA_map_) { visitor(&entry.second); }  }

  protected:
     std::unordered_map<format::HandleId, OpenXrActionInfo> action_map_;
     std::unordered_map<format::HandleId, OpenXrActionSetInfo> actionSet_map_;
     std::unordered_map<format::HandleId, OpenXrAsyncRequestIdFBInfo> asyncRequestIdFB_map_;
     std::unordered_map<format::HandleId, OpenXrBodyTrackerFBInfo> bodyTrackerFB_map_;
     std::unordered_map<format::HandleId, OpenXrControllerModelKeyMSFTInfo> controllerModelKeyMSFT_map_;
     std::unordered_map<format::HandleId, OpenXrDebugUtilsMessengerEXTInfo> debugUtilsMessengerEXT_map_;
     std::unordered_map<format::HandleId, OpenXrEnvironmentDepthProviderMETAInfo> environmentDepthProviderMETA_map_;
     std::unordered_map<format::HandleId, OpenXrEnvironmentDepthSwapchainMETAInfo> environmentDepthSwapchainMETA_map_;
     std::unordered_map<format::HandleId, OpenXrExportedLocalizationMapMLInfo> exportedLocalizationMapML_map_;
     std::unordered_map<format::HandleId, OpenXrEyeTrackerFBInfo> eyeTrackerFB_map_;
     std::unordered_map<format::HandleId, OpenXrFaceTracker2FBInfo> faceTracker2FB_map_;
     std::unordered_map<format::HandleId, OpenXrFaceTrackerFBInfo> faceTrackerFB_map_;
     std::unordered_map<format::HandleId, OpenXrFacialTrackerHTCInfo> facialTrackerHTC_map_;
     std::unordered_map<format::HandleId, OpenXrFoveationProfileFBInfo> foveationProfileFB_map_;
     std::unordered_map<format::HandleId, OpenXrFutureEXTInfo> futureEXT_map_;
     std::unordered_map<format::HandleId, OpenXrGeometryInstanceFBInfo> geometryInstanceFB_map_;
     std::unordered_map<format::HandleId, OpenXrHandTrackerEXTInfo> handTrackerEXT_map_;
     std::unordered_map<format::HandleId, OpenXrInstanceInfo> instance_map_;
     std::unordered_map<format::HandleId, OpenXrMarkerDetectorMLInfo> markerDetectorML_map_;
     std::unordered_map<format::HandleId, OpenXrMarkerMLInfo> markerML_map_;
     std::unordered_map<format::HandleId, OpenXrPassthroughColorLutMETAInfo> passthroughColorLutMETA_map_;
     std::unordered_map<format::HandleId, OpenXrPassthroughFBInfo> passthroughFB_map_;
     std::unordered_map<format::HandleId, OpenXrPassthroughHTCInfo> passthroughHTC_map_;
     std::unordered_map<format::HandleId, OpenXrPassthroughLayerFBInfo> passthroughLayerFB_map_;
     std::unordered_map<format::HandleId, OpenXrPathInfo> path_map_;
     std::unordered_map<format::HandleId, OpenXrPlaneDetectorEXTInfo> planeDetectorEXT_map_;
     std::unordered_map<format::HandleId, OpenXrRenderModelKeyFBInfo> renderModelKeyFB_map_;
     std::unordered_map<format::HandleId, OpenXrSceneMSFTInfo> sceneMSFT_map_;
     std::unordered_map<format::HandleId, OpenXrSceneObserverMSFTInfo> sceneObserverMSFT_map_;
     std::unordered_map<format::HandleId, OpenXrSessionInfo> session_map_;
     std::unordered_map<format::HandleId, OpenXrSpaceInfo> space_map_;
     std::unordered_map<format::HandleId, OpenXrSpaceUserFBInfo> spaceUserFB_map_;
     std::unordered_map<format::HandleId, OpenXrSpatialAnchorMSFTInfo> spatialAnchorMSFT_map_;
     std::unordered_map<format::HandleId, OpenXrSpatialAnchorStoreConnectionMSFTInfo> spatialAnchorStoreConnectionMSFT_map_;
     std::unordered_map<format::HandleId, OpenXrSpatialGraphNodeBindingMSFTInfo> spatialGraphNodeBindingMSFT_map_;
     std::unordered_map<format::HandleId, OpenXrSwapchainInfo> swapchain_map_;
     std::unordered_map<format::HandleId, OpenXrSystemIdInfo> systemId_map_;
     std::unordered_map<format::HandleId, OpenXrTriangleMeshFBInfo> triangleMeshFB_map_;
     std::unordered_map<format::HandleId, OpenXrVirtualKeyboardMETAInfo> virtualKeyboardMETA_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
