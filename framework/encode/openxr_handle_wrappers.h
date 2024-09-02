/*
** Copyright (c) 2019-2024 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPERS_H
#define GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPERS_H

#if ENABLE_OPENXR_SUPPORT

#include "encode/openxr_state_info.h"
#include "format/format.h"
#include "generated/generated_openxr_dispatch_table.h"
#include "util/defines.h"

#include "openxr/openxr.h"

#include <algorithm>
#include <limits>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(openxr_wrappers)

template <typename T>
struct HandleWrapper
{
    typedef T HandleType;

    // Standard state info required for all handles.
    HandleType        handle{ XR_NULL_HANDLE };           // Original handle value provided by the driver.
    format::HandleId  handle_id{ format::kNullHandleId }; // Globally unique ID assigned to the handle by the layer.
    format::ApiCallId create_call_id{ format::ApiCallId::ApiCall_Unknown };
    openxr_state_info::CreateParameters create_parameters;
};

template <typename T>
struct AtomWrapper
{
    typedef T HandleType;

    // Standard state info required for all handles.
    HandleType        handle{ 0ULL };                     // Original handle value provided by the driver.
    format::HandleId  handle_id{ format::kNullHandleId }; // Globally unique ID assigned to the handle by the layer.
    format::ApiCallId create_call_id{ format::ApiCallId::ApiCall_Unknown };
    openxr_state_info::CreateParameters create_parameters;
};

template <typename T>
struct OpaqueWrapper
{
    typedef T HandleType;

    // Standard state info required for all handles.
    HandleType        handle{ 0ULL };                     // Original handle value provided by the driver.
    format::HandleId  handle_id{ format::kNullHandleId }; // Globally unique ID assigned to the handle by the layer.
    format::ApiCallId create_call_id{ format::ApiCallId::ApiCall_Unknown };
    openxr_state_info::CreateParameters create_parameters;
};

//
// Container Wrappers
//

struct SessionWrapper;
struct ActionSetWrapper;
struct PathWrapper;
struct SystemIdWrapper;
struct DebugUtilsMessengerEXTWrapper;
struct FutureEXTWrapper;

struct InstanceWrapper : public HandleWrapper<XrInstance>
{
    OpenXrInstanceTable layer_table;
    void                DeleteFromParent() {}

    XrVersion                                   api_version{ XR_MAKE_VERSION(1, 0, 0) };
    std::vector<SessionWrapper*>                child_sessions;
    std::vector<ActionSetWrapper*>              child_actionsets;
    std::vector<SystemIdWrapper*>               child_systemids;
    std::vector<PathWrapper*>                   child_paths;
    std::vector<DebugUtilsMessengerEXTWrapper*> child_debugutilsmessengers;
    std::vector<FutureEXTWrapper*>              child_futureexts;

    std::unordered_map<VkPhysicalDevice, VkInstance>          vkphysdev_vkinstance_map;
    std::unordered_map<PFN_vkGetInstanceProcAddr, VkInstance> vkgipa_vkinstance_map;
};

struct SpaceWrapper;
struct SwapchainWrapper;
struct HandTrackerEXTWrapper;
struct PlaneDetectorEXTWrapper;
struct AsyncRequestIdFBWrapper;
struct BodyTrackerFBWrapper;
struct EyeTrackerFBWrapper;
struct FaceTrackerFBWrapper;
struct FaceTracker2FBWrapper;
struct GeometryInstanceFBWrapper;
struct MarkerDetectorMLWrapper;
struct PassthroughFBWrapper;
struct PassthroughLayerFBWrapper;
struct RenderModelKeyFBWrapper;
struct SpaceUserFBWrapper;
struct TriangleMeshFBWrapper;
struct PassthroughHTCWrapper;
struct VirtualKeyboardMETAWrapper;
struct ExportedLocalizationMapMLWrapper;
struct ControllerModelKeyMSFTWrapper;
struct SceneObserverMSFTWrapper;
struct SpatialAnchorMSFTWrapper;
struct SpatialAnchorStoreConnectionMSFTWrapper;
struct SpatialGraphNodeBindingMSFTWrapper;
struct FacialTrackerHTCWrapper;
struct FoveationProfileFBWrapper;
struct EnvironmentDepthProviderMETAWrapper;

struct SessionWrapper : public HandleWrapper<XrSession>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    InstanceWrapper*     parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_sessions;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }

    std::vector<SpaceWrapper*>                            child_spaces;
    std::vector<SwapchainWrapper*>                        child_swapchains;
    std::vector<AsyncRequestIdFBWrapper*>                 child_asyncreqidfbs;
    std::vector<RenderModelKeyFBWrapper*>                 child_rendermodelkeyfbs;
    std::vector<ControllerModelKeyMSFTWrapper*>           child_controllermodelkeymsfts;
    std::vector<SpatialAnchorMSFTWrapper*>                child_spatialanchormsfts;
    std::vector<SpatialGraphNodeBindingMSFTWrapper*>      child_spatialgraphnodebindingmsfts;
    std::vector<HandTrackerEXTWrapper*>                   child_handtrackerexts;
    std::vector<BodyTrackerFBWrapper*>                    child_bodytrackerfbs;
    std::vector<SceneObserverMSFTWrapper*>                child_sceneobservermsfts;
    std::vector<FacialTrackerHTCWrapper*>                 child_facialtrackerhtcs;
    std::vector<FoveationProfileFBWrapper*>               child_foveationprofilefbs;
    std::vector<TriangleMeshFBWrapper*>                   child_trianglemeshfbs;
    std::vector<PassthroughFBWrapper*>                    child_passthroughfbs;
    std::vector<PassthroughLayerFBWrapper*>               child_passthroughlayerfbs;
    std::vector<GeometryInstanceFBWrapper*>               child_geometryinstancefbs;
    std::vector<MarkerDetectorMLWrapper*>                 child_markerdetectormls;
    std::vector<ExportedLocalizationMapMLWrapper*>        child_exportedlocalizationmapmls;
    std::vector<SpatialAnchorStoreConnectionMSFTWrapper*> child_spatialanchorstoreconnmsfts;
    std::vector<SpaceUserFBWrapper*>                      child_spaceuserfbs;
    std::vector<FaceTrackerFBWrapper*>                    child_facetrackerfbs;
    std::vector<EyeTrackerFBWrapper*>                     child_eyetrackerfbs;
    std::vector<VirtualKeyboardMETAWrapper*>              child_virtualkeyboardmetas;
    std::vector<FaceTracker2FBWrapper*>                   child_facetracker2fbs;
    std::vector<PassthroughHTCWrapper*>                   child_passthroughhtcs;
    std::vector<PlaneDetectorEXTWrapper*>                 child_planedetectorexts;
    std::vector<EnvironmentDepthProviderMETAWrapper*>     child_envdepthprovidermetas;
};

struct MarkerMLWrapper;

struct MarkerDetectorMLWrapper : public HandleWrapper<XrMarkerDetectorML>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_markerdetectormls;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }

    std::vector<MarkerMLWrapper*> child_markers;
};

struct SceneMSFTWrapper;

struct SceneObserverMSFTWrapper : public HandleWrapper<XrSceneObserverMSFT>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_sceneobservermsfts;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }

    std::vector<SceneMSFTWrapper*> child_scenemsfts;
};

struct PassthroughColorLutMETAWrapper;

struct PassthroughFBWrapper : public HandleWrapper<XrPassthroughFB>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_passthroughfbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }

    std::vector<PassthroughColorLutMETAWrapper*> child_passthroughcolorlutmetas;
};

struct EnvironmentDepthSwapchainMETAWrapper;

struct EnvironmentDepthProviderMETAWrapper : public HandleWrapper<XrEnvironmentDepthProviderMETA>
{
    OpenXrInstanceTable*  layer_table_ref{ nullptr };
    SessionWrapper*        parent_wrapper{ nullptr };
    void                  DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_envdepthprovidermetas;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }

    std::vector<EnvironmentDepthSwapchainMETAWrapper*>     child_envdepthswapchainmetas;
};

// Vendor wrappers

struct BodyTrackerFBWrapper : public HandleWrapper<XrBodyTrackerFB>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_bodytrackerfbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct EyeTrackerFBWrapper : public HandleWrapper<XrEyeTrackerFB>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_eyetrackerfbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct FaceTrackerFBWrapper : public HandleWrapper<XrFaceTrackerFB>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_facetrackerfbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct FaceTracker2FBWrapper : public HandleWrapper<XrFaceTracker2FB>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_facetracker2fbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct FoveationProfileFBWrapper : public HandleWrapper<XrFoveationProfileFB>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_foveationprofilefbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct GeometryInstanceFBWrapper : public HandleWrapper<XrGeometryInstanceFB>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_geometryinstancefbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct PassthroughLayerFBWrapper : public HandleWrapper<XrPassthroughLayerFB>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_passthroughlayerfbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct SpaceUserFBWrapper : public HandleWrapper<XrSpaceUserFB>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_spaceuserfbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct TriangleMeshFBWrapper : public HandleWrapper<XrTriangleMeshFB>
{
    OpenXrInstanceTable*       layer_table_ref{ nullptr };
    SessionWrapper*            parent_wrapper{ nullptr };
    XrTriangleMeshCreateInfoFB create_info{};
    void                       DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_trianglemeshfbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct FacialTrackerHTCWrapper : public HandleWrapper<XrFacialTrackerHTC>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_facialtrackerhtcs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct PassthroughHTCWrapper : public HandleWrapper<XrPassthroughHTC>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_passthroughhtcs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct ExportedLocalizationMapMLWrapper : public HandleWrapper<XrExportedLocalizationMapML>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_exportedlocalizationmapmls;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct SceneMSFTWrapper : public HandleWrapper<XrSceneMSFT>
{
    OpenXrInstanceTable*      layer_table_ref{ nullptr };
    SceneObserverMSFTWrapper* parent_wrapper{ nullptr };
    void                      DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_scenemsfts;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct SpatialAnchorMSFTWrapper : public HandleWrapper<XrSpatialAnchorMSFT>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_spatialanchormsfts;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct SpatialAnchorStoreConnectionMSFTWrapper : public HandleWrapper<XrSpatialAnchorStoreConnectionMSFT>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_spatialanchorstoreconnmsfts;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct SpatialGraphNodeBindingMSFTWrapper : public HandleWrapper<XrSpatialGraphNodeBindingMSFT>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_spatialgraphnodebindingmsfts;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct VirtualKeyboardMETAWrapper : public HandleWrapper<XrVirtualKeyboardMETA>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_virtualkeyboardmetas;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct PassthroughColorLutMETAWrapper : public HandleWrapper<XrPassthroughColorLutMETA>
{
    OpenXrInstanceTable*  layer_table_ref{ nullptr };
    PassthroughFBWrapper* parent_wrapper{ nullptr };
    void                  DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_passthroughcolorlutmetas;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct EnvironmentDepthSwapchainMETAWrapper : public HandleWrapper<XrEnvironmentDepthSwapchainMETA>
{
    OpenXrInstanceTable*  layer_table_ref{ nullptr };
    EnvironmentDepthProviderMETAWrapper*        parent_wrapper{ nullptr };
    void                  DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_envdepthswapchainmetas;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

// EXT wrappers

struct DebugUtilsMessengerEXTWrapper : public HandleWrapper<XrDebugUtilsMessengerEXT>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    InstanceWrapper*     parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_debugutilsmessengers;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct HandTrackerEXTWrapper : public HandleWrapper<XrHandTrackerEXT>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_handtrackerexts;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct PlaneDetectorEXTWrapper : public HandleWrapper<XrPlaneDetectorEXT>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_planedetectorexts;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct FutureEXTWrapper : public OpaqueWrapper<XrFutureEXT>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    InstanceWrapper*     parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_futureexts;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

// KHR wrappers

struct ActionWrapper;

struct ActionSetWrapper : public HandleWrapper<XrActionSet>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    InstanceWrapper*     parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_actionsets;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }

    std::vector<ActionWrapper*> child_actions;
};

struct ActionWrapper : public HandleWrapper<XrAction>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    ActionSetWrapper*    parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_actions;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct SpaceWrapper : public HandleWrapper<XrSpace>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_spaces;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

struct SwapchainWrapper : public HandleWrapper<XrSwapchain>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
    SessionWrapper*      parent_wrapper{ nullptr };
    void                 DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_swapchains;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

//
// Atom Wrappers
//

struct SystemIdWrapper : public AtomWrapper<XrSystemId>
{
    InstanceWrapper* parent_wrapper{ nullptr };
    void             DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_systemids;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};
struct PathWrapper : public AtomWrapper<XrPath>
{
    InstanceWrapper* parent_wrapper{ nullptr };
    void             DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_paths;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};
struct AsyncRequestIdFBWrapper : public AtomWrapper<XrAsyncRequestIdFB>
{
    SessionWrapper* parent_wrapper{ nullptr };
    void            DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_asyncreqidfbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};
struct RenderModelKeyFBWrapper : public AtomWrapper<XrRenderModelKeyFB>
{
    SessionWrapper* parent_wrapper{ nullptr };
    void            DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_rendermodelkeyfbs;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};
struct MarkerMLWrapper : public AtomWrapper<XrMarkerML>
{
    MarkerDetectorMLWrapper* parent_wrapper{ nullptr };
    void                     DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_markers;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};
struct ControllerModelKeyMSFTWrapper : public AtomWrapper<XrControllerModelKeyMSFT>
{
    SessionWrapper* parent_wrapper{ nullptr };
    void            DeleteFromParent()
    {
        if (parent_wrapper != nullptr)
        {
            auto& parent_vector = parent_wrapper->child_controllermodelkeymsfts;
            parent_vector.erase(std::remove(parent_vector.begin(), parent_vector.end(), this), parent_vector.end());
        }
    }
};

GFXRECON_END_NAMESPACE(openxr_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPERS_H
