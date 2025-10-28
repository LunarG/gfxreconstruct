/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_OPENXR_TRACKED_OBJECT_MAPPER_H
#define GFXRECON_DECODE_OPENXR_TRACKED_OBJECT_MAPPER_H

#if ENABLE_OPENXR_SUPPORT

#include "decode/openxr_tracked_object_info.h"
#include "util/defines.h"
#include "util/logging.h"

#include "openxr/openxr.h"

#include <cassert>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// This class stores the tables of the tracked OpenXR memories,
// buffers, images objects information during the first pass
// of the replay.
// It is used to generate tables for these tracked objects and
// will be accessed later by replay consumer class during
// second pass of replay for memory portability purpose.
class OpenXrTrackedObjectInfoTable
{
  public:
    void AddTrackedXrInstanceInfo(TrackedXrInstanceInfo&& info);
    void AddTrackedXrSessionInfo(TrackedXrSessionInfo&& info);
    void AddTrackedXrSwapchainInfo(TrackedXrSwapchainInfo&& info);
    void AddTrackedXrActionSetInfo(TrackedXrActionSetInfo&& info);
    void AddTrackedXrActionInfo(TrackedXrActionInfo&& info);
    void AddTrackedXrDebugUtilsMessengerEXTInfo(TrackedXrDebugUtilsMessengerEXTInfo&& info);
    void AddTrackedXrSpatialAnchorMSFTInfo(TrackedXrSpatialAnchorMSFTInfo&& info);
    void AddTrackedXrSpaceInfo(TrackedXrSpaceInfo&& info);
    void AddTrackedXrHandTrackerEXTInfo(TrackedXrHandTrackerEXTInfo&& info);
    void AddTrackedXrBodyTrackerFBInfo(TrackedXrBodyTrackerFBInfo&& info);
    void AddTrackedXrSceneObserverMSFTInfo(TrackedXrSceneObserverMSFTInfo&& info);
    void AddTrackedXrSceneMSFTInfo(TrackedXrSceneMSFTInfo&& info);
    void AddTrackedXrFacialTrackerHTCInfo(TrackedXrFacialTrackerHTCInfo&& info);
    void AddTrackedXrFoveationProfileFBInfo(TrackedXrFoveationProfileFBInfo&& info);
    void AddTrackedXrPassthroughFBInfo(TrackedXrPassthroughFBInfo&& info);
    void AddTrackedXrPassthroughLayerFBInfo(TrackedXrPassthroughLayerFBInfo&& info);
    void AddTrackedXrGeometryInstanceFBInfo(TrackedXrGeometryInstanceFBInfo&& info);
    void AddTrackedXrMarkerDetectorMLInfo(TrackedXrMarkerDetectorMLInfo&& info);
    void AddTrackedXrExportedLocalizationMapMLInfo(TrackedXrExportedLocalizationMapMLInfo&& info);
    void AddTrackedXrSpatialAnchorStoreConnectionMSFTInfo(TrackedXrSpatialAnchorStoreConnectionMSFTInfo&& info);
    void AddTrackedXrFaceTrackerFBInfo(TrackedXrFaceTrackerFBInfo&& info);
    void AddTrackedXrEyeTrackerFBInfo(TrackedXrEyeTrackerFBInfo&& info);
    void AddTrackedXrVirtualKeyboardMETAInfo(TrackedXrVirtualKeyboardMETAInfo&& info);
    void AddTrackedXrSpaceUserFBInfo(TrackedXrSpaceUserFBInfo&& info);
    void AddTrackedXrPassthroughColorLutMETAInfo(TrackedXrPassthroughColorLutMETAInfo&& info);
    void AddTrackedXrFaceTracker2FBInfo(TrackedXrFaceTracker2FBInfo&& info);
    void AddTrackedXrPassthroughHTCInfo(TrackedXrPassthroughHTCInfo&& info);
    void AddTrackedXrPlaneDetectorEXTInfo(TrackedXrPlaneDetectorEXTInfo&& info);

    // Return specified handle ID's instance information from the tracked instances information table map
    TrackedXrInstanceInfo*                        GetTrackedXrInstanceInfo(format::HandleId id);
    const TrackedXrInstanceInfo*                  GetTrackedXrInstanceInfo(format::HandleId id) const;
    TrackedXrSessionInfo*                         GetTrackedXrSessionInfo(format::HandleId id);
    const TrackedXrSessionInfo*                   GetTrackedXrSessionInfo(format::HandleId id) const;
    TrackedXrSwapchainInfo*                       GetTrackedXrSwapchainInfo(format::HandleId id);
    const TrackedXrSwapchainInfo*                 GetTrackedXrSwapchainInfo(format::HandleId id) const;
    TrackedXrActionSetInfo*                       GetTrackedXrActionSetInfo(format::HandleId id);
    const TrackedXrActionSetInfo*                 GetTrackedXrActionSetInfo(format::HandleId id) const;
    TrackedXrActionInfo*                          GetTrackedXrActionInfo(format::HandleId id);
    const TrackedXrActionInfo*                    GetTrackedXrActionInfo(format::HandleId id) const;
    TrackedXrDebugUtilsMessengerEXTInfo*          GetTrackedXrDebugUtilsMessengerEXTInfo(format::HandleId id);
    const TrackedXrDebugUtilsMessengerEXTInfo*    GetTrackedXrDebugUtilsMessengerEXTInfo(format::HandleId id) const;
    TrackedXrSpatialAnchorMSFTInfo*               GetTrackedXrSpatialAnchorMSFTInfo(format::HandleId id);
    const TrackedXrSpatialAnchorMSFTInfo*         GetTrackedXrSpatialAnchorMSFTInfo(format::HandleId id) const;
    TrackedXrSpaceInfo*                           GetTrackedXrSpaceInfo(format::HandleId id);
    const TrackedXrSpaceInfo*                     GetTrackedXrSpaceInfo(format::HandleId id) const;
    TrackedXrHandTrackerEXTInfo*                  GetTrackedXrHandTrackerEXTInfo(format::HandleId id);
    const TrackedXrHandTrackerEXTInfo*            GetTrackedXrHandTrackerEXTInfo(format::HandleId id) const;
    TrackedXrBodyTrackerFBInfo*                   GetTrackedXrBodyTrackerFBInfo(format::HandleId id);
    const TrackedXrBodyTrackerFBInfo*             GetTrackedXrBodyTrackerFBInfo(format::HandleId id) const;
    TrackedXrSceneObserverMSFTInfo*               GetTrackedXrSceneObserverMSFTInfo(format::HandleId id);
    const TrackedXrSceneObserverMSFTInfo*         GetTrackedXrSceneObserverMSFTInfo(format::HandleId id) const;
    TrackedXrSceneMSFTInfo*                       GetTrackedXrSceneMSFTInfo(format::HandleId id);
    const TrackedXrSceneMSFTInfo*                 GetTrackedXrSceneMSFTInfo(format::HandleId id) const;
    TrackedXrFacialTrackerHTCInfo*                GetTrackedXrFacialTrackerHTCInfo(format::HandleId id);
    const TrackedXrFacialTrackerHTCInfo*          GetTrackedXrFacialTrackerHTCInfo(format::HandleId id) const;
    TrackedXrFoveationProfileFBInfo*              GetTrackedXrFoveationProfileFBInfo(format::HandleId id);
    const TrackedXrFoveationProfileFBInfo*        GetTrackedXrFoveationProfileFBInfo(format::HandleId id) const;
    TrackedXrPassthroughFBInfo*                   GetTrackedXrPassthroughFBInfo(format::HandleId id);
    const TrackedXrPassthroughFBInfo*             GetTrackedXrPassthroughFBInfo(format::HandleId id) const;
    TrackedXrPassthroughLayerFBInfo*              GetTrackedXrPassthroughLayerFBInfo(format::HandleId id);
    const TrackedXrPassthroughLayerFBInfo*        GetTrackedXrPassthroughLayerFBInfo(format::HandleId id) const;
    TrackedXrGeometryInstanceFBInfo*              GetTrackedXrGeometryInstanceFBInfo(format::HandleId id);
    const TrackedXrGeometryInstanceFBInfo*        GetTrackedXrGeometryInstanceFBInfo(format::HandleId id) const;
    TrackedXrMarkerDetectorMLInfo*                GetTrackedXrMarkerDetectorMLInfo(format::HandleId id);
    const TrackedXrMarkerDetectorMLInfo*          GetTrackedXrMarkerDetectorMLInfo(format::HandleId id) const;
    TrackedXrExportedLocalizationMapMLInfo*       GetTrackedXrExportedLocalizationMapMLInfo(format::HandleId id);
    const TrackedXrExportedLocalizationMapMLInfo* GetTrackedXrExportedLocalizationMapMLInfo(format::HandleId id) const;
    TrackedXrSpatialAnchorStoreConnectionMSFTInfo*
    GetTrackedXrSpatialAnchorStoreConnectionMSFTInfo(format::HandleId id);
    const TrackedXrSpatialAnchorStoreConnectionMSFTInfo*
                                            GetTrackedXrSpatialAnchorStoreConnectionMSFTInfo(format::HandleId id) const;
    TrackedXrFaceTrackerFBInfo*             GetTrackedXrFaceTrackerFBInfo(format::HandleId id);
    const TrackedXrFaceTrackerFBInfo*       GetTrackedXrFaceTrackerFBInfo(format::HandleId id) const;
    TrackedXrEyeTrackerFBInfo*              GetTrackedXrEyeTrackerFBInfo(format::HandleId id);
    const TrackedXrEyeTrackerFBInfo*        GetTrackedXrEyeTrackerFBInfo(format::HandleId id) const;
    TrackedXrVirtualKeyboardMETAInfo*       GetTrackedXrVirtualKeyboardMETAInfo(format::HandleId id);
    const TrackedXrVirtualKeyboardMETAInfo* GetTrackedXrVirtualKeyboardMETAInfo(format::HandleId id) const;
    TrackedXrSpaceUserFBInfo*               GetTrackedXrSpaceUserFBInfo(format::HandleId id);
    const TrackedXrSpaceUserFBInfo*         GetTrackedXrSpaceUserFBInfo(format::HandleId id) const;
    TrackedXrPassthroughColorLutMETAInfo*   GetTrackedXrPassthroughColorLutMETAInfo(format::HandleId id);
    const TrackedXrPassthroughColorLutMETAInfo* GetTrackedXrPassthroughColorLutMETAInfo(format::HandleId id) const;
    TrackedXrFaceTracker2FBInfo*                GetTrackedXrFaceTracker2FBInfo(format::HandleId id);
    const TrackedXrFaceTracker2FBInfo*          GetTrackedXrFaceTracker2FBInfo(format::HandleId id) const;
    TrackedXrPassthroughHTCInfo*                GetTrackedXrPassthroughHTCInfo(format::HandleId id);
    const TrackedXrPassthroughHTCInfo*          GetTrackedXrPassthroughHTCInfo(format::HandleId id) const;
    TrackedXrPlaneDetectorEXTInfo*              GetTrackedXrPlaneDetectorEXTInfo(format::HandleId id);
    const TrackedXrPlaneDetectorEXTInfo*        GetTrackedXrPlaneDetectorEXTInfo(format::HandleId id) const;

  private:
    // Helper template function for updating tracked objects ID with the information
    // into the objects' table map
    template <typename T>
    void AddTrackedXrObjectInfo(T&& info, std::unordered_map<format::HandleId, T>* map)
    {
        assert(map != nullptr);

        if ((info.GetCaptureId() != 0))
        {
            auto result = map->emplace(info.GetCaptureId(), std::forward<T>(info));

            if (!result.second)
            {
                // TODO(gfxrec-28): handle duplicate id cases?
                GFXRECON_LOG_WARNING("Duplicate entry for object id %" PRIu64, info.GetCaptureId());
            }
        }
    }

    // Helper template function for retrieving tracked objects information
    // with the specified ID from the objects' table map
    template <typename T>
    T* GetTrackedXrObjectInfo(format::HandleId id, std::unordered_map<format::HandleId, T>* map)
    {
        assert(map != nullptr);

        T* object_info = nullptr;

        if (id != 0)
        {
            auto entry = map->find(id);

            if (entry != map->end())
            {
                object_info = &entry->second;
            }
            else
            {
                GFXRECON_LOG_WARNING("GetTrackedXrObjectInfo: Failed to map handle for object id %" PRIu64, id);
            }
        }

        return object_info;
    }

    // Helper template function for retrieving tracked objects information
    // with the specified ID from the objects' table map
    template <typename T>
    const T* GetTrackedXrObjectInfo(format::HandleId id, const std::unordered_map<format::HandleId, T>* map) const
    {
        assert(map != nullptr);

        const T* object_info = nullptr;

        if (id != 0)
        {
            auto entry = map->find(id);

            if (entry != map->end())
            {
                object_info = &entry->second;
            }
            else
            {
                GFXRECON_LOG_WARNING("GetTrackedXrObjectInfo: Failed to map handle for object id %" PRIu64, id);
            }
        }

        return object_info;
    }

  private:
    std::unordered_map<format::HandleId, TrackedXrInstanceInfo>                  tracked_instance_map_;
    std::unordered_map<format::HandleId, TrackedXrSessionInfo>                   tracked_session_map_;
    std::unordered_map<format::HandleId, TrackedXrSwapchainInfo>                 tracked_swapchain_map_;
    std::unordered_map<format::HandleId, TrackedXrActionSetInfo>                 tracked_actionset_map_;
    std::unordered_map<format::HandleId, TrackedXrActionInfo>                    tracked_action_map_;
    std::unordered_map<format::HandleId, TrackedXrDebugUtilsMessengerEXTInfo>    tracked_debugutilsmessengerEXT_map_;
    std::unordered_map<format::HandleId, TrackedXrSpatialAnchorMSFTInfo>         tracked_spatialanchorMSFT_map_;
    std::unordered_map<format::HandleId, TrackedXrSpaceInfo>                     tracked_space_map_;
    std::unordered_map<format::HandleId, TrackedXrHandTrackerEXTInfo>            tracked_handtrackerEXT_map_;
    std::unordered_map<format::HandleId, TrackedXrBodyTrackerFBInfo>             tracked_bodytrackerFB_map_;
    std::unordered_map<format::HandleId, TrackedXrSceneObserverMSFTInfo>         tracked_sceneobserverMSFT_map_;
    std::unordered_map<format::HandleId, TrackedXrSceneMSFTInfo>                 tracked_sceneMSFT_map_;
    std::unordered_map<format::HandleId, TrackedXrFacialTrackerHTCInfo>          tracked_facialtrackerHTC_map_;
    std::unordered_map<format::HandleId, TrackedXrFoveationProfileFBInfo>        tracked_foveationprofileFB_map_;
    std::unordered_map<format::HandleId, TrackedXrPassthroughFBInfo>             tracked_passthroughFB_map_;
    std::unordered_map<format::HandleId, TrackedXrPassthroughLayerFBInfo>        tracked_passthroughLayerFB_map_;
    std::unordered_map<format::HandleId, TrackedXrGeometryInstanceFBInfo>        tracked_geometryinstanceFB_map_;
    std::unordered_map<format::HandleId, TrackedXrMarkerDetectorMLInfo>          tracked_markerdetectorML_map_;
    std::unordered_map<format::HandleId, TrackedXrExportedLocalizationMapMLInfo> tracked_exportedlocalizationmapML_map_;
    std::unordered_map<format::HandleId, TrackedXrSpatialAnchorStoreConnectionMSFTInfo>
                                                                     tracked_spatialanchorstoreconnectionMSFT_map_;
    std::unordered_map<format::HandleId, TrackedXrFaceTrackerFBInfo> tracked_facetrackerFB_map_;
    std::unordered_map<format::HandleId, TrackedXrEyeTrackerFBInfo>  tracked_eyetrackerFB_map_;
    std::unordered_map<format::HandleId, TrackedXrVirtualKeyboardMETAInfo>     tracked_virtualkeyboardMETA_map_;
    std::unordered_map<format::HandleId, TrackedXrSpaceUserFBInfo>             tracked_spaceuserFB_map_;
    std::unordered_map<format::HandleId, TrackedXrPassthroughColorLutMETAInfo> tracked_passthroughcolorlutMETA_map_;
    std::unordered_map<format::HandleId, TrackedXrFaceTracker2FBInfo>          tracked_facetracker2FB_map_;
    std::unordered_map<format::HandleId, TrackedXrPassthroughHTCInfo>          tracked_passthroughHTC_map_;
    std::unordered_map<format::HandleId, TrackedXrPlaneDetectorEXTInfo>        tracked_planedetectorEXT_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_TRACKED_OBJECT_MAPPER_H
