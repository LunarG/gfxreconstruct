/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2025 LunarG, Inc.
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

#include "openxr_tracked_object_info_table.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// TODO: Add code generation for below
// Add tracked instance information into the instances table map
void OpenXrTrackedObjectInfoTable::AddTrackedXrInstanceInfo(TrackedXrInstanceInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_instance_map_);
}

// Add tracked physical device information into the physical devices table map
void OpenXrTrackedObjectInfoTable::AddTrackedXrSessionInfo(TrackedXrSessionInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_session_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrSwapchainInfo(TrackedXrSwapchainInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_swapchain_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrActionSetInfo(TrackedXrActionSetInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_actionset_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrActionInfo(TrackedXrActionInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_action_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrDebugUtilsMessengerEXTInfo(TrackedXrDebugUtilsMessengerEXTInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_debugutilsmessengerEXT_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrSpatialAnchorMSFTInfo(TrackedXrSpatialAnchorMSFTInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_spatialanchorMSFT_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrSpaceInfo(TrackedXrSpaceInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_space_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrHandTrackerEXTInfo(TrackedXrHandTrackerEXTInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_handtrackerEXT_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrBodyTrackerFBInfo(TrackedXrBodyTrackerFBInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_bodytrackerFB_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrSceneObserverMSFTInfo(TrackedXrSceneObserverMSFTInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_sceneobserverMSFT_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrSceneMSFTInfo(TrackedXrSceneMSFTInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_sceneMSFT_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrFacialTrackerHTCInfo(TrackedXrFacialTrackerHTCInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_facialtrackerHTC_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrFoveationProfileFBInfo(TrackedXrFoveationProfileFBInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_foveationprofileFB_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrPassthroughFBInfo(TrackedXrPassthroughFBInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_passthroughFB_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrPassthroughLayerFBInfo(TrackedXrPassthroughLayerFBInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_passthroughLayerFB_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrGeometryInstanceFBInfo(TrackedXrGeometryInstanceFBInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_geometryinstanceFB_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrMarkerDetectorMLInfo(TrackedXrMarkerDetectorMLInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_markerdetectorML_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrExportedLocalizationMapMLInfo(
    TrackedXrExportedLocalizationMapMLInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_exportedlocalizationmapML_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrSpatialAnchorStoreConnectionMSFTInfo(
    TrackedXrSpatialAnchorStoreConnectionMSFTInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_spatialanchorstoreconnectionMSFT_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrFaceTrackerFBInfo(TrackedXrFaceTrackerFBInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_facetrackerFB_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrEyeTrackerFBInfo(TrackedXrEyeTrackerFBInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_eyetrackerFB_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrVirtualKeyboardMETAInfo(TrackedXrVirtualKeyboardMETAInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_virtualkeyboardMETA_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrSpaceUserFBInfo(TrackedXrSpaceUserFBInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_spaceuserFB_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrPassthroughColorLutMETAInfo(TrackedXrPassthroughColorLutMETAInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_passthroughcolorlutMETA_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrFaceTracker2FBInfo(TrackedXrFaceTracker2FBInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_facetracker2FB_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrPassthroughHTCInfo(TrackedXrPassthroughHTCInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_passthroughHTC_map_);
}

void OpenXrTrackedObjectInfoTable::AddTrackedXrPlaneDetectorEXTInfo(TrackedXrPlaneDetectorEXTInfo&& info)
{
    AddTrackedXrObjectInfo(std::move(info), &tracked_planedetectorEXT_map_);
}

TrackedXrInstanceInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrInstanceInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrInstanceInfo>(id, &tracked_instance_map_);
}

const TrackedXrInstanceInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrInstanceInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrInstanceInfo>(id, &tracked_instance_map_);
}

TrackedXrSessionInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSessionInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrSessionInfo>(id, &tracked_session_map_);
}

const TrackedXrSessionInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSessionInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrSessionInfo>(id, &tracked_session_map_);
}

TrackedXrSwapchainInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSwapchainInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrSwapchainInfo>(id, &tracked_swapchain_map_);
}

const TrackedXrSwapchainInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSwapchainInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrSwapchainInfo>(id, &tracked_swapchain_map_);
}

TrackedXrActionSetInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrActionSetInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrActionSetInfo>(id, &tracked_actionset_map_);
}

const TrackedXrActionSetInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrActionSetInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrActionSetInfo>(id, &tracked_actionset_map_);
}

TrackedXrActionInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrActionInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrActionInfo>(id, &tracked_action_map_);
}

const TrackedXrActionInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrActionInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrActionInfo>(id, &tracked_action_map_);
}

TrackedXrDebugUtilsMessengerEXTInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrDebugUtilsMessengerEXTInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrDebugUtilsMessengerEXTInfo>(id, &tracked_debugutilsmessengerEXT_map_);
}

const TrackedXrDebugUtilsMessengerEXTInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrDebugUtilsMessengerEXTInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrDebugUtilsMessengerEXTInfo>(id, &tracked_debugutilsmessengerEXT_map_);
}

TrackedXrSpatialAnchorMSFTInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSpatialAnchorMSFTInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrSpatialAnchorMSFTInfo>(id, &tracked_spatialanchorMSFT_map_);
}

const TrackedXrSpatialAnchorMSFTInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrSpatialAnchorMSFTInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrSpatialAnchorMSFTInfo>(id, &tracked_spatialanchorMSFT_map_);
}

TrackedXrSpaceInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSpaceInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrSpaceInfo>(id, &tracked_space_map_);
}

const TrackedXrSpaceInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSpaceInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrSpaceInfo>(id, &tracked_space_map_);
}

TrackedXrHandTrackerEXTInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrHandTrackerEXTInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrHandTrackerEXTInfo>(id, &tracked_handtrackerEXT_map_);
}

const TrackedXrHandTrackerEXTInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrHandTrackerEXTInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrHandTrackerEXTInfo>(id, &tracked_handtrackerEXT_map_);
}

TrackedXrBodyTrackerFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrBodyTrackerFBInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrBodyTrackerFBInfo>(id, &tracked_bodytrackerFB_map_);
}

const TrackedXrBodyTrackerFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrBodyTrackerFBInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrBodyTrackerFBInfo>(id, &tracked_bodytrackerFB_map_);
}

TrackedXrSceneObserverMSFTInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSceneObserverMSFTInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrSceneObserverMSFTInfo>(id, &tracked_sceneobserverMSFT_map_);
}

const TrackedXrSceneObserverMSFTInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrSceneObserverMSFTInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrSceneObserverMSFTInfo>(id, &tracked_sceneobserverMSFT_map_);
}

TrackedXrSceneMSFTInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSceneMSFTInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrSceneMSFTInfo>(id, &tracked_sceneMSFT_map_);
}

const TrackedXrSceneMSFTInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSceneMSFTInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrSceneMSFTInfo>(id, &tracked_sceneMSFT_map_);
}

TrackedXrFacialTrackerHTCInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrFacialTrackerHTCInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrFacialTrackerHTCInfo>(id, &tracked_facialtrackerHTC_map_);
}

const TrackedXrFacialTrackerHTCInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrFacialTrackerHTCInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrFacialTrackerHTCInfo>(id, &tracked_facialtrackerHTC_map_);
}

TrackedXrFoveationProfileFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrFoveationProfileFBInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrFoveationProfileFBInfo>(id, &tracked_foveationprofileFB_map_);
}

const TrackedXrFoveationProfileFBInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrFoveationProfileFBInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrFoveationProfileFBInfo>(id, &tracked_foveationprofileFB_map_);
}

TrackedXrPassthroughFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrPassthroughFBInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrPassthroughFBInfo>(id, &tracked_passthroughFB_map_);
}

const TrackedXrPassthroughFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrPassthroughFBInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrPassthroughFBInfo>(id, &tracked_passthroughFB_map_);
}

TrackedXrPassthroughLayerFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrPassthroughLayerFBInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrPassthroughLayerFBInfo>(id, &tracked_passthroughLayerFB_map_);
}

const TrackedXrPassthroughLayerFBInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrPassthroughLayerFBInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrPassthroughLayerFBInfo>(id, &tracked_passthroughLayerFB_map_);
}

TrackedXrGeometryInstanceFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrGeometryInstanceFBInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrGeometryInstanceFBInfo>(id, &tracked_geometryinstanceFB_map_);
}

const TrackedXrGeometryInstanceFBInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrGeometryInstanceFBInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrGeometryInstanceFBInfo>(id, &tracked_geometryinstanceFB_map_);
}

TrackedXrMarkerDetectorMLInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrMarkerDetectorMLInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrMarkerDetectorMLInfo>(id, &tracked_markerdetectorML_map_);
}

const TrackedXrMarkerDetectorMLInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrMarkerDetectorMLInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrMarkerDetectorMLInfo>(id, &tracked_markerdetectorML_map_);
}

TrackedXrExportedLocalizationMapMLInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrExportedLocalizationMapMLInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrExportedLocalizationMapMLInfo>(id, &tracked_exportedlocalizationmapML_map_);
}

const TrackedXrExportedLocalizationMapMLInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrExportedLocalizationMapMLInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrExportedLocalizationMapMLInfo>(id, &tracked_exportedlocalizationmapML_map_);
}

TrackedXrSpatialAnchorStoreConnectionMSFTInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrSpatialAnchorStoreConnectionMSFTInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrSpatialAnchorStoreConnectionMSFTInfo>(
        id, &tracked_spatialanchorstoreconnectionMSFT_map_);
}

const TrackedXrSpatialAnchorStoreConnectionMSFTInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrSpatialAnchorStoreConnectionMSFTInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrSpatialAnchorStoreConnectionMSFTInfo>(
        id, &tracked_spatialanchorstoreconnectionMSFT_map_);
}

TrackedXrFaceTrackerFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrFaceTrackerFBInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrFaceTrackerFBInfo>(id, &tracked_facetrackerFB_map_);
}

const TrackedXrFaceTrackerFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrFaceTrackerFBInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrFaceTrackerFBInfo>(id, &tracked_facetrackerFB_map_);
}

TrackedXrEyeTrackerFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrEyeTrackerFBInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrEyeTrackerFBInfo>(id, &tracked_eyetrackerFB_map_);
}

const TrackedXrEyeTrackerFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrEyeTrackerFBInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrEyeTrackerFBInfo>(id, &tracked_eyetrackerFB_map_);
}

TrackedXrVirtualKeyboardMETAInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrVirtualKeyboardMETAInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrVirtualKeyboardMETAInfo>(id, &tracked_virtualkeyboardMETA_map_);
}

const TrackedXrVirtualKeyboardMETAInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrVirtualKeyboardMETAInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrVirtualKeyboardMETAInfo>(id, &tracked_virtualkeyboardMETA_map_);
}

TrackedXrSpaceUserFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSpaceUserFBInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrSpaceUserFBInfo>(id, &tracked_spaceuserFB_map_);
}

const TrackedXrSpaceUserFBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrSpaceUserFBInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrSpaceUserFBInfo>(id, &tracked_spaceuserFB_map_);
}

TrackedXrPassthroughColorLutMETAInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrPassthroughColorLutMETAInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrPassthroughColorLutMETAInfo>(id, &tracked_passthroughcolorlutMETA_map_);
}

const TrackedXrPassthroughColorLutMETAInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrPassthroughColorLutMETAInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrPassthroughColorLutMETAInfo>(id, &tracked_passthroughcolorlutMETA_map_);
}
TrackedXrFaceTracker2FBInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrFaceTracker2FBInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrFaceTracker2FBInfo>(id, &tracked_facetracker2FB_map_);
}
const TrackedXrFaceTracker2FBInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrFaceTracker2FBInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrFaceTracker2FBInfo>(id, &tracked_facetracker2FB_map_);
}
TrackedXrPassthroughHTCInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrPassthroughHTCInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrPassthroughHTCInfo>(id, &tracked_passthroughHTC_map_);
}
const TrackedXrPassthroughHTCInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrPassthroughHTCInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrPassthroughHTCInfo>(id, &tracked_passthroughHTC_map_);
}
TrackedXrPlaneDetectorEXTInfo* OpenXrTrackedObjectInfoTable::GetTrackedXrPlaneDetectorEXTInfo(format::HandleId id)
{
    return GetTrackedXrObjectInfo<TrackedXrPlaneDetectorEXTInfo>(id, &tracked_planedetectorEXT_map_);
}
const TrackedXrPlaneDetectorEXTInfo*
OpenXrTrackedObjectInfoTable::GetTrackedXrPlaneDetectorEXTInfo(format::HandleId id) const
{
    return GetTrackedXrObjectInfo<TrackedXrPlaneDetectorEXTInfo>(id, &tracked_planedetectorEXT_map_);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
