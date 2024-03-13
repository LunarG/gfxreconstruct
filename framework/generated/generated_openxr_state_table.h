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

#ifdef ENABLE_OPENXR_SUPPORT

#include "encode/openxr_state_table_base.h"

#include "encode/vulkan_handle_wrappers.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class OpenXrStateTable : OpenXrStateTableBase
{
  public:
    OpenXrStateTable() {}
    ~OpenXrStateTable() {}

    bool InsertWrapper(format::HandleId id, vulkan_wrappers::DeviceWrapper* wrapper) { return InsertEntry(id, wrapper, v_device_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::ImageWrapper* wrapper) { return InsertEntry(id, wrapper, v_image_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::InstanceWrapper* wrapper) { return InsertEntry(id, wrapper, v_instance_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::PhysicalDeviceWrapper* wrapper) { return InsertEntry(id, wrapper, v_physicalDevice_map_); }
    bool InsertWrapper(format::HandleId id, vulkan_wrappers::SwapchainKHRWrapper* wrapper) { return InsertEntry(id, wrapper, v_swapchainKHR_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::ActionWrapper* wrapper) { return InsertEntry(id, wrapper, x_action_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::ActionSetWrapper* wrapper) { return InsertEntry(id, wrapper, x_actionSet_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::BodyTrackerFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_bodyTrackerFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(id, wrapper, x_debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::ExportedLocalizationMapMLWrapper* wrapper) { return InsertEntry(id, wrapper, x_exportedLocalizationMapML_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::EyeTrackerFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_eyeTrackerFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::FaceTracker2FBWrapper* wrapper) { return InsertEntry(id, wrapper, x_faceTracker2FB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::FaceTrackerFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_faceTrackerFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::FacialTrackerHTCWrapper* wrapper) { return InsertEntry(id, wrapper, x_facialTrackerHTC_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::FoveationProfileFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_foveationProfileFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::GeometryInstanceFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_geometryInstanceFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::HandTrackerEXTWrapper* wrapper) { return InsertEntry(id, wrapper, x_handTrackerEXT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::InstanceWrapper* wrapper) { return InsertEntry(id, wrapper, x_instance_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::MarkerDetectorMLWrapper* wrapper) { return InsertEntry(id, wrapper, x_markerDetectorML_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PassthroughColorLutMETAWrapper* wrapper) { return InsertEntry(id, wrapper, x_passthroughColorLutMETA_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PassthroughFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_passthroughFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PassthroughHTCWrapper* wrapper) { return InsertEntry(id, wrapper, x_passthroughHTC_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PassthroughLayerFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_passthroughLayerFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PlaneDetectorEXTWrapper* wrapper) { return InsertEntry(id, wrapper, x_planeDetectorEXT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SceneMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, x_sceneMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SceneObserverMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, x_sceneObserverMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SessionWrapper* wrapper) { return InsertEntry(id, wrapper, x_session_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SpaceWrapper* wrapper) { return InsertEntry(id, wrapper, x_space_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SpaceUserFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_spaceUserFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SpatialAnchorMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, x_spatialAnchorMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, x_spatialAnchorStoreConnectionMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, x_spatialGraphNodeBindingMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SwapchainWrapper* wrapper) { return InsertEntry(id, wrapper, x_swapchain_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::TriangleMeshFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_triangleMeshFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::VirtualKeyboardMETAWrapper* wrapper) { return InsertEntry(id, wrapper, x_virtualKeyboardMETA_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::AsyncRequestIdFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_asyncRequestIdFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::ControllerModelKeyMSFTWrapper* wrapper) { return InsertEntry(id, wrapper, x_controllerModelKeyMSFT_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::MarkerMLWrapper* wrapper) { return InsertEntry(id, wrapper, x_markerML_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::PathWrapper* wrapper) { return InsertEntry(id, wrapper, x_path_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::RenderModelKeyFBWrapper* wrapper) { return InsertEntry(id, wrapper, x_renderModelKeyFB_map_); }
    bool InsertWrapper(format::HandleId id, openxr_wrappers::SystemIdWrapper* wrapper) { return InsertEntry(id, wrapper, x_systemId_map_); }

    bool RemoveWrapper(const vulkan_wrappers::DeviceWrapper* wrapper) { return RemoveEntry(wrapper, v_device_map_); }
    bool RemoveWrapper(const vulkan_wrappers::ImageWrapper* wrapper) { return RemoveEntry(wrapper, v_image_map_); }
    bool RemoveWrapper(const vulkan_wrappers::InstanceWrapper* wrapper) { return RemoveEntry(wrapper, v_instance_map_); }
    bool RemoveWrapper(const vulkan_wrappers::PhysicalDeviceWrapper* wrapper) { return RemoveEntry(wrapper, v_physicalDevice_map_); }
    bool RemoveWrapper(const vulkan_wrappers::SwapchainKHRWrapper* wrapper) { return RemoveEntry(wrapper, v_swapchainKHR_map_); }
    bool RemoveWrapper(const openxr_wrappers::ActionWrapper* wrapper) { return RemoveEntry(wrapper, x_action_map_); }
    bool RemoveWrapper(const openxr_wrappers::ActionSetWrapper* wrapper) { return RemoveEntry(wrapper, x_actionSet_map_); }
    bool RemoveWrapper(const openxr_wrappers::BodyTrackerFBWrapper* wrapper) { return RemoveEntry(wrapper, x_bodyTrackerFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { return RemoveEntry(wrapper, x_debugUtilsMessengerEXT_map_); }
    bool RemoveWrapper(const openxr_wrappers::ExportedLocalizationMapMLWrapper* wrapper) { return RemoveEntry(wrapper, x_exportedLocalizationMapML_map_); }
    bool RemoveWrapper(const openxr_wrappers::EyeTrackerFBWrapper* wrapper) { return RemoveEntry(wrapper, x_eyeTrackerFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::FaceTracker2FBWrapper* wrapper) { return RemoveEntry(wrapper, x_faceTracker2FB_map_); }
    bool RemoveWrapper(const openxr_wrappers::FaceTrackerFBWrapper* wrapper) { return RemoveEntry(wrapper, x_faceTrackerFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::FacialTrackerHTCWrapper* wrapper) { return RemoveEntry(wrapper, x_facialTrackerHTC_map_); }
    bool RemoveWrapper(const openxr_wrappers::FoveationProfileFBWrapper* wrapper) { return RemoveEntry(wrapper, x_foveationProfileFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::GeometryInstanceFBWrapper* wrapper) { return RemoveEntry(wrapper, x_geometryInstanceFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::HandTrackerEXTWrapper* wrapper) { return RemoveEntry(wrapper, x_handTrackerEXT_map_); }
    bool RemoveWrapper(const openxr_wrappers::InstanceWrapper* wrapper) { return RemoveEntry(wrapper, x_instance_map_); }
    bool RemoveWrapper(const openxr_wrappers::MarkerDetectorMLWrapper* wrapper) { return RemoveEntry(wrapper, x_markerDetectorML_map_); }
    bool RemoveWrapper(const openxr_wrappers::PassthroughColorLutMETAWrapper* wrapper) { return RemoveEntry(wrapper, x_passthroughColorLutMETA_map_); }
    bool RemoveWrapper(const openxr_wrappers::PassthroughFBWrapper* wrapper) { return RemoveEntry(wrapper, x_passthroughFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::PassthroughHTCWrapper* wrapper) { return RemoveEntry(wrapper, x_passthroughHTC_map_); }
    bool RemoveWrapper(const openxr_wrappers::PassthroughLayerFBWrapper* wrapper) { return RemoveEntry(wrapper, x_passthroughLayerFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::PlaneDetectorEXTWrapper* wrapper) { return RemoveEntry(wrapper, x_planeDetectorEXT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SceneMSFTWrapper* wrapper) { return RemoveEntry(wrapper, x_sceneMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SceneObserverMSFTWrapper* wrapper) { return RemoveEntry(wrapper, x_sceneObserverMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SessionWrapper* wrapper) { return RemoveEntry(wrapper, x_session_map_); }
    bool RemoveWrapper(const openxr_wrappers::SpaceWrapper* wrapper) { return RemoveEntry(wrapper, x_space_map_); }
    bool RemoveWrapper(const openxr_wrappers::SpaceUserFBWrapper* wrapper) { return RemoveEntry(wrapper, x_spaceUserFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::SpatialAnchorMSFTWrapper* wrapper) { return RemoveEntry(wrapper, x_spatialAnchorMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* wrapper) { return RemoveEntry(wrapper, x_spatialAnchorStoreConnectionMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* wrapper) { return RemoveEntry(wrapper, x_spatialGraphNodeBindingMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::SwapchainWrapper* wrapper) { return RemoveEntry(wrapper, x_swapchain_map_); }
    bool RemoveWrapper(const openxr_wrappers::TriangleMeshFBWrapper* wrapper) { return RemoveEntry(wrapper, x_triangleMeshFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::VirtualKeyboardMETAWrapper* wrapper) { return RemoveEntry(wrapper, x_virtualKeyboardMETA_map_); }
    bool RemoveWrapper(const openxr_wrappers::AsyncRequestIdFBWrapper* wrapper) { return RemoveEntry(wrapper, x_asyncRequestIdFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::ControllerModelKeyMSFTWrapper* wrapper) { return RemoveEntry(wrapper, x_controllerModelKeyMSFT_map_); }
    bool RemoveWrapper(const openxr_wrappers::MarkerMLWrapper* wrapper) { return RemoveEntry(wrapper, x_markerML_map_); }
    bool RemoveWrapper(const openxr_wrappers::PathWrapper* wrapper) { return RemoveEntry(wrapper, x_path_map_); }
    bool RemoveWrapper(const openxr_wrappers::RenderModelKeyFBWrapper* wrapper) { return RemoveEntry(wrapper, x_renderModelKeyFB_map_); }
    bool RemoveWrapper(const openxr_wrappers::SystemIdWrapper* wrapper) { return RemoveEntry(wrapper, x_systemId_map_); }

    const vulkan_wrappers::DeviceWrapper* GetVulkanDeviceWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::DeviceWrapper>(id, v_device_map_); }
    const vulkan_wrappers::ImageWrapper* GetVulkanImageWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::ImageWrapper>(id, v_image_map_); }
    const vulkan_wrappers::InstanceWrapper* GetVulkanInstanceWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::InstanceWrapper>(id, v_instance_map_); }
    const vulkan_wrappers::PhysicalDeviceWrapper* GetVulkanPhysicalDeviceWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(id, v_physicalDevice_map_); }
    const vulkan_wrappers::SwapchainKHRWrapper* GetVulkanSwapchainKHRWrapper(format::HandleId id) const { return GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(id, v_swapchainKHR_map_); }
    const openxr_wrappers::ActionWrapper* GetOpenXrActionWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::ActionWrapper>(id, x_action_map_); }
    const openxr_wrappers::ActionSetWrapper* GetOpenXrActionSetWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::ActionSetWrapper>(id, x_actionSet_map_); }
    const openxr_wrappers::BodyTrackerFBWrapper* GetOpenXrBodyTrackerFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::BodyTrackerFBWrapper>(id, x_bodyTrackerFB_map_); }
    const openxr_wrappers::DebugUtilsMessengerEXTWrapper* GetOpenXrDebugUtilsMessengerEXTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(id, x_debugUtilsMessengerEXT_map_); }
    const openxr_wrappers::ExportedLocalizationMapMLWrapper* GetOpenXrExportedLocalizationMapMLWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::ExportedLocalizationMapMLWrapper>(id, x_exportedLocalizationMapML_map_); }
    const openxr_wrappers::EyeTrackerFBWrapper* GetOpenXrEyeTrackerFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::EyeTrackerFBWrapper>(id, x_eyeTrackerFB_map_); }
    const openxr_wrappers::FaceTracker2FBWrapper* GetOpenXrFaceTracker2FBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::FaceTracker2FBWrapper>(id, x_faceTracker2FB_map_); }
    const openxr_wrappers::FaceTrackerFBWrapper* GetOpenXrFaceTrackerFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::FaceTrackerFBWrapper>(id, x_faceTrackerFB_map_); }
    const openxr_wrappers::FacialTrackerHTCWrapper* GetOpenXrFacialTrackerHTCWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::FacialTrackerHTCWrapper>(id, x_facialTrackerHTC_map_); }
    const openxr_wrappers::FoveationProfileFBWrapper* GetOpenXrFoveationProfileFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::FoveationProfileFBWrapper>(id, x_foveationProfileFB_map_); }
    const openxr_wrappers::GeometryInstanceFBWrapper* GetOpenXrGeometryInstanceFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::GeometryInstanceFBWrapper>(id, x_geometryInstanceFB_map_); }
    const openxr_wrappers::HandTrackerEXTWrapper* GetOpenXrHandTrackerEXTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::HandTrackerEXTWrapper>(id, x_handTrackerEXT_map_); }
    const openxr_wrappers::InstanceWrapper* GetOpenXrInstanceWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::InstanceWrapper>(id, x_instance_map_); }
    const openxr_wrappers::MarkerDetectorMLWrapper* GetOpenXrMarkerDetectorMLWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(id, x_markerDetectorML_map_); }
    const openxr_wrappers::PassthroughColorLutMETAWrapper* GetOpenXrPassthroughColorLutMETAWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PassthroughColorLutMETAWrapper>(id, x_passthroughColorLutMETA_map_); }
    const openxr_wrappers::PassthroughFBWrapper* GetOpenXrPassthroughFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PassthroughFBWrapper>(id, x_passthroughFB_map_); }
    const openxr_wrappers::PassthroughHTCWrapper* GetOpenXrPassthroughHTCWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PassthroughHTCWrapper>(id, x_passthroughHTC_map_); }
    const openxr_wrappers::PassthroughLayerFBWrapper* GetOpenXrPassthroughLayerFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PassthroughLayerFBWrapper>(id, x_passthroughLayerFB_map_); }
    const openxr_wrappers::PlaneDetectorEXTWrapper* GetOpenXrPlaneDetectorEXTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PlaneDetectorEXTWrapper>(id, x_planeDetectorEXT_map_); }
    const openxr_wrappers::SceneMSFTWrapper* GetOpenXrSceneMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SceneMSFTWrapper>(id, x_sceneMSFT_map_); }
    const openxr_wrappers::SceneObserverMSFTWrapper* GetOpenXrSceneObserverMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SceneObserverMSFTWrapper>(id, x_sceneObserverMSFT_map_); }
    const openxr_wrappers::SessionWrapper* GetOpenXrSessionWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SessionWrapper>(id, x_session_map_); }
    const openxr_wrappers::SpaceWrapper* GetOpenXrSpaceWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SpaceWrapper>(id, x_space_map_); }
    const openxr_wrappers::SpaceUserFBWrapper* GetOpenXrSpaceUserFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SpaceUserFBWrapper>(id, x_spaceUserFB_map_); }
    const openxr_wrappers::SpatialAnchorMSFTWrapper* GetOpenXrSpatialAnchorMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SpatialAnchorMSFTWrapper>(id, x_spatialAnchorMSFT_map_); }
    const openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* GetOpenXrSpatialAnchorStoreConnectionMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(id, x_spatialAnchorStoreConnectionMSFT_map_); }
    const openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* GetOpenXrSpatialGraphNodeBindingMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(id, x_spatialGraphNodeBindingMSFT_map_); }
    const openxr_wrappers::SwapchainWrapper* GetOpenXrSwapchainWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SwapchainWrapper>(id, x_swapchain_map_); }
    const openxr_wrappers::TriangleMeshFBWrapper* GetOpenXrTriangleMeshFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(id, x_triangleMeshFB_map_); }
    const openxr_wrappers::VirtualKeyboardMETAWrapper* GetOpenXrVirtualKeyboardMETAWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::VirtualKeyboardMETAWrapper>(id, x_virtualKeyboardMETA_map_); }
    const openxr_wrappers::AsyncRequestIdFBWrapper* GetOpenXrAsyncRequestIdFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::AsyncRequestIdFBWrapper>(id, x_asyncRequestIdFB_map_); }
    const openxr_wrappers::ControllerModelKeyMSFTWrapper* GetOpenXrControllerModelKeyMSFTWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::ControllerModelKeyMSFTWrapper>(id, x_controllerModelKeyMSFT_map_); }
    const openxr_wrappers::MarkerMLWrapper* GetOpenXrMarkerMLWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::MarkerMLWrapper>(id, x_markerML_map_); }
    const openxr_wrappers::PathWrapper* GetOpenXrPathWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::PathWrapper>(id, x_path_map_); }
    const openxr_wrappers::RenderModelKeyFBWrapper* GetOpenXrRenderModelKeyFBWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::RenderModelKeyFBWrapper>(id, x_renderModelKeyFB_map_); }
    const openxr_wrappers::SystemIdWrapper* GetOpenXrSystemIdWrapper(format::HandleId id) const { return GetWrapper<openxr_wrappers::SystemIdWrapper>(id, x_systemId_map_); }

    vulkan_wrappers::DeviceWrapper* GetVulkanDeviceWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::DeviceWrapper>(id, v_device_map_); }
    vulkan_wrappers::ImageWrapper* GetVulkanImageWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::ImageWrapper>(id, v_image_map_); }
    vulkan_wrappers::InstanceWrapper* GetVulkanInstanceWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::InstanceWrapper>(id, v_instance_map_); }
    vulkan_wrappers::PhysicalDeviceWrapper* GetVulkanPhysicalDeviceWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(id, v_physicalDevice_map_); }
    vulkan_wrappers::SwapchainKHRWrapper* GetVulkanSwapchainKHRWrapper(format::HandleId id) { return GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(id, v_swapchainKHR_map_); }
    openxr_wrappers::ActionWrapper* GetOpenXrActionWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::ActionWrapper>(id, x_action_map_); }
    openxr_wrappers::ActionSetWrapper* GetOpenXrActionSetWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::ActionSetWrapper>(id, x_actionSet_map_); }
    openxr_wrappers::BodyTrackerFBWrapper* GetOpenXrBodyTrackerFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::BodyTrackerFBWrapper>(id, x_bodyTrackerFB_map_); }
    openxr_wrappers::DebugUtilsMessengerEXTWrapper* GetOpenXrDebugUtilsMessengerEXTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(id, x_debugUtilsMessengerEXT_map_); }
    openxr_wrappers::ExportedLocalizationMapMLWrapper* GetOpenXrExportedLocalizationMapMLWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::ExportedLocalizationMapMLWrapper>(id, x_exportedLocalizationMapML_map_); }
    openxr_wrappers::EyeTrackerFBWrapper* GetOpenXrEyeTrackerFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::EyeTrackerFBWrapper>(id, x_eyeTrackerFB_map_); }
    openxr_wrappers::FaceTracker2FBWrapper* GetOpenXrFaceTracker2FBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::FaceTracker2FBWrapper>(id, x_faceTracker2FB_map_); }
    openxr_wrappers::FaceTrackerFBWrapper* GetOpenXrFaceTrackerFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::FaceTrackerFBWrapper>(id, x_faceTrackerFB_map_); }
    openxr_wrappers::FacialTrackerHTCWrapper* GetOpenXrFacialTrackerHTCWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::FacialTrackerHTCWrapper>(id, x_facialTrackerHTC_map_); }
    openxr_wrappers::FoveationProfileFBWrapper* GetOpenXrFoveationProfileFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::FoveationProfileFBWrapper>(id, x_foveationProfileFB_map_); }
    openxr_wrappers::GeometryInstanceFBWrapper* GetOpenXrGeometryInstanceFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::GeometryInstanceFBWrapper>(id, x_geometryInstanceFB_map_); }
    openxr_wrappers::HandTrackerEXTWrapper* GetOpenXrHandTrackerEXTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::HandTrackerEXTWrapper>(id, x_handTrackerEXT_map_); }
    openxr_wrappers::InstanceWrapper* GetOpenXrInstanceWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::InstanceWrapper>(id, x_instance_map_); }
    openxr_wrappers::MarkerDetectorMLWrapper* GetOpenXrMarkerDetectorMLWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(id, x_markerDetectorML_map_); }
    openxr_wrappers::PassthroughColorLutMETAWrapper* GetOpenXrPassthroughColorLutMETAWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PassthroughColorLutMETAWrapper>(id, x_passthroughColorLutMETA_map_); }
    openxr_wrappers::PassthroughFBWrapper* GetOpenXrPassthroughFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PassthroughFBWrapper>(id, x_passthroughFB_map_); }
    openxr_wrappers::PassthroughHTCWrapper* GetOpenXrPassthroughHTCWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PassthroughHTCWrapper>(id, x_passthroughHTC_map_); }
    openxr_wrappers::PassthroughLayerFBWrapper* GetOpenXrPassthroughLayerFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PassthroughLayerFBWrapper>(id, x_passthroughLayerFB_map_); }
    openxr_wrappers::PlaneDetectorEXTWrapper* GetOpenXrPlaneDetectorEXTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PlaneDetectorEXTWrapper>(id, x_planeDetectorEXT_map_); }
    openxr_wrappers::SceneMSFTWrapper* GetOpenXrSceneMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SceneMSFTWrapper>(id, x_sceneMSFT_map_); }
    openxr_wrappers::SceneObserverMSFTWrapper* GetOpenXrSceneObserverMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SceneObserverMSFTWrapper>(id, x_sceneObserverMSFT_map_); }
    openxr_wrappers::SessionWrapper* GetOpenXrSessionWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SessionWrapper>(id, x_session_map_); }
    openxr_wrappers::SpaceWrapper* GetOpenXrSpaceWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SpaceWrapper>(id, x_space_map_); }
    openxr_wrappers::SpaceUserFBWrapper* GetOpenXrSpaceUserFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SpaceUserFBWrapper>(id, x_spaceUserFB_map_); }
    openxr_wrappers::SpatialAnchorMSFTWrapper* GetOpenXrSpatialAnchorMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SpatialAnchorMSFTWrapper>(id, x_spatialAnchorMSFT_map_); }
    openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* GetOpenXrSpatialAnchorStoreConnectionMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(id, x_spatialAnchorStoreConnectionMSFT_map_); }
    openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* GetOpenXrSpatialGraphNodeBindingMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(id, x_spatialGraphNodeBindingMSFT_map_); }
    openxr_wrappers::SwapchainWrapper* GetOpenXrSwapchainWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SwapchainWrapper>(id, x_swapchain_map_); }
    openxr_wrappers::TriangleMeshFBWrapper* GetOpenXrTriangleMeshFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(id, x_triangleMeshFB_map_); }
    openxr_wrappers::VirtualKeyboardMETAWrapper* GetOpenXrVirtualKeyboardMETAWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::VirtualKeyboardMETAWrapper>(id, x_virtualKeyboardMETA_map_); }
    openxr_wrappers::AsyncRequestIdFBWrapper* GetOpenXrAsyncRequestIdFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::AsyncRequestIdFBWrapper>(id, x_asyncRequestIdFB_map_); }
    openxr_wrappers::ControllerModelKeyMSFTWrapper* GetOpenXrControllerModelKeyMSFTWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::ControllerModelKeyMSFTWrapper>(id, x_controllerModelKeyMSFT_map_); }
    openxr_wrappers::MarkerMLWrapper* GetOpenXrMarkerMLWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::MarkerMLWrapper>(id, x_markerML_map_); }
    openxr_wrappers::PathWrapper* GetOpenXrPathWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::PathWrapper>(id, x_path_map_); }
    openxr_wrappers::RenderModelKeyFBWrapper* GetOpenXrRenderModelKeyFBWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::RenderModelKeyFBWrapper>(id, x_renderModelKeyFB_map_); }
    openxr_wrappers::SystemIdWrapper* GetOpenXrSystemIdWrapper(format::HandleId id) { return GetWrapper<openxr_wrappers::SystemIdWrapper>(id, x_systemId_map_); }

    void VisitWrappers(std::function<void(vulkan_wrappers::DeviceWrapper*)> visitor) const { for (auto entry : v_device_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::ImageWrapper*)> visitor) const { for (auto entry : v_image_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::InstanceWrapper*)> visitor) const { for (auto entry : v_instance_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::PhysicalDeviceWrapper*)> visitor) const { for (auto entry : v_physicalDevice_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(vulkan_wrappers::SwapchainKHRWrapper*)> visitor) const { for (auto entry : v_swapchainKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::ActionWrapper*)> visitor) const { for (auto entry : x_action_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::ActionSetWrapper*)> visitor) const { for (auto entry : x_actionSet_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::BodyTrackerFBWrapper*)> visitor) const { for (auto entry : x_bodyTrackerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::DebugUtilsMessengerEXTWrapper*)> visitor) const { for (auto entry : x_debugUtilsMessengerEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::ExportedLocalizationMapMLWrapper*)> visitor) const { for (auto entry : x_exportedLocalizationMapML_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::EyeTrackerFBWrapper*)> visitor) const { for (auto entry : x_eyeTrackerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::FaceTracker2FBWrapper*)> visitor) const { for (auto entry : x_faceTracker2FB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::FaceTrackerFBWrapper*)> visitor) const { for (auto entry : x_faceTrackerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::FacialTrackerHTCWrapper*)> visitor) const { for (auto entry : x_facialTrackerHTC_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::FoveationProfileFBWrapper*)> visitor) const { for (auto entry : x_foveationProfileFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::GeometryInstanceFBWrapper*)> visitor) const { for (auto entry : x_geometryInstanceFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::HandTrackerEXTWrapper*)> visitor) const { for (auto entry : x_handTrackerEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::InstanceWrapper*)> visitor) const { for (auto entry : x_instance_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::MarkerDetectorMLWrapper*)> visitor) const { for (auto entry : x_markerDetectorML_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PassthroughColorLutMETAWrapper*)> visitor) const { for (auto entry : x_passthroughColorLutMETA_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PassthroughFBWrapper*)> visitor) const { for (auto entry : x_passthroughFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PassthroughHTCWrapper*)> visitor) const { for (auto entry : x_passthroughHTC_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PassthroughLayerFBWrapper*)> visitor) const { for (auto entry : x_passthroughLayerFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PlaneDetectorEXTWrapper*)> visitor) const { for (auto entry : x_planeDetectorEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SceneMSFTWrapper*)> visitor) const { for (auto entry : x_sceneMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SceneObserverMSFTWrapper*)> visitor) const { for (auto entry : x_sceneObserverMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SessionWrapper*)> visitor) const { for (auto entry : x_session_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SpaceWrapper*)> visitor) const { for (auto entry : x_space_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SpaceUserFBWrapper*)> visitor) const { for (auto entry : x_spaceUserFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SpatialAnchorMSFTWrapper*)> visitor) const { for (auto entry : x_spatialAnchorMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper*)> visitor) const { for (auto entry : x_spatialAnchorStoreConnectionMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper*)> visitor) const { for (auto entry : x_spatialGraphNodeBindingMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SwapchainWrapper*)> visitor) const { for (auto entry : x_swapchain_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::TriangleMeshFBWrapper*)> visitor) const { for (auto entry : x_triangleMeshFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::VirtualKeyboardMETAWrapper*)> visitor) const { for (auto entry : x_virtualKeyboardMETA_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::AsyncRequestIdFBWrapper*)> visitor) const { for (auto entry : x_asyncRequestIdFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::ControllerModelKeyMSFTWrapper*)> visitor) const { for (auto entry : x_controllerModelKeyMSFT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::MarkerMLWrapper*)> visitor) const { for (auto entry : x_markerML_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::PathWrapper*)> visitor) const { for (auto entry : x_path_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::RenderModelKeyFBWrapper*)> visitor) const { for (auto entry : x_renderModelKeyFB_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(openxr_wrappers::SystemIdWrapper*)> visitor) const { for (auto entry : x_systemId_map_) { visitor(entry.second); } }

  private:
    std::map<format::HandleId, vulkan_wrappers::DeviceWrapper*> v_device_map_;
    std::map<format::HandleId, vulkan_wrappers::ImageWrapper*> v_image_map_;
    std::map<format::HandleId, vulkan_wrappers::InstanceWrapper*> v_instance_map_;
    std::map<format::HandleId, vulkan_wrappers::PhysicalDeviceWrapper*> v_physicalDevice_map_;
    std::map<format::HandleId, vulkan_wrappers::SwapchainKHRWrapper*> v_swapchainKHR_map_;
    std::map<format::HandleId, openxr_wrappers::ActionWrapper*> x_action_map_;
    std::map<format::HandleId, openxr_wrappers::ActionSetWrapper*> x_actionSet_map_;
    std::map<format::HandleId, openxr_wrappers::BodyTrackerFBWrapper*> x_bodyTrackerFB_map_;
    std::map<format::HandleId, openxr_wrappers::DebugUtilsMessengerEXTWrapper*> x_debugUtilsMessengerEXT_map_;
    std::map<format::HandleId, openxr_wrappers::ExportedLocalizationMapMLWrapper*> x_exportedLocalizationMapML_map_;
    std::map<format::HandleId, openxr_wrappers::EyeTrackerFBWrapper*> x_eyeTrackerFB_map_;
    std::map<format::HandleId, openxr_wrappers::FaceTracker2FBWrapper*> x_faceTracker2FB_map_;
    std::map<format::HandleId, openxr_wrappers::FaceTrackerFBWrapper*> x_faceTrackerFB_map_;
    std::map<format::HandleId, openxr_wrappers::FacialTrackerHTCWrapper*> x_facialTrackerHTC_map_;
    std::map<format::HandleId, openxr_wrappers::FoveationProfileFBWrapper*> x_foveationProfileFB_map_;
    std::map<format::HandleId, openxr_wrappers::GeometryInstanceFBWrapper*> x_geometryInstanceFB_map_;
    std::map<format::HandleId, openxr_wrappers::HandTrackerEXTWrapper*> x_handTrackerEXT_map_;
    std::map<format::HandleId, openxr_wrappers::InstanceWrapper*> x_instance_map_;
    std::map<format::HandleId, openxr_wrappers::MarkerDetectorMLWrapper*> x_markerDetectorML_map_;
    std::map<format::HandleId, openxr_wrappers::PassthroughColorLutMETAWrapper*> x_passthroughColorLutMETA_map_;
    std::map<format::HandleId, openxr_wrappers::PassthroughFBWrapper*> x_passthroughFB_map_;
    std::map<format::HandleId, openxr_wrappers::PassthroughHTCWrapper*> x_passthroughHTC_map_;
    std::map<format::HandleId, openxr_wrappers::PassthroughLayerFBWrapper*> x_passthroughLayerFB_map_;
    std::map<format::HandleId, openxr_wrappers::PlaneDetectorEXTWrapper*> x_planeDetectorEXT_map_;
    std::map<format::HandleId, openxr_wrappers::SceneMSFTWrapper*> x_sceneMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::SceneObserverMSFTWrapper*> x_sceneObserverMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::SessionWrapper*> x_session_map_;
    std::map<format::HandleId, openxr_wrappers::SpaceWrapper*> x_space_map_;
    std::map<format::HandleId, openxr_wrappers::SpaceUserFBWrapper*> x_spaceUserFB_map_;
    std::map<format::HandleId, openxr_wrappers::SpatialAnchorMSFTWrapper*> x_spatialAnchorMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper*> x_spatialAnchorStoreConnectionMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper*> x_spatialGraphNodeBindingMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::SwapchainWrapper*> x_swapchain_map_;
    std::map<format::HandleId, openxr_wrappers::TriangleMeshFBWrapper*> x_triangleMeshFB_map_;
    std::map<format::HandleId, openxr_wrappers::VirtualKeyboardMETAWrapper*> x_virtualKeyboardMETA_map_;
    std::map<format::HandleId, openxr_wrappers::AsyncRequestIdFBWrapper*> x_asyncRequestIdFB_map_;
    std::map<format::HandleId, openxr_wrappers::ControllerModelKeyMSFTWrapper*> x_controllerModelKeyMSFT_map_;
    std::map<format::HandleId, openxr_wrappers::MarkerMLWrapper*> x_markerML_map_;
    std::map<format::HandleId, openxr_wrappers::PathWrapper*> x_path_map_;
    std::map<format::HandleId, openxr_wrappers::RenderModelKeyFBWrapper*> x_renderModelKeyFB_map_;
    std::map<format::HandleId, openxr_wrappers::SystemIdWrapper*> x_systemId_map_;
};

class OpenXrStateHandleTable : OpenXrStateTableBase
{
  public:
    OpenXrStateHandleTable() {}
    ~OpenXrStateHandleTable() {}

    bool InsertWrapper(vulkan_wrappers::DeviceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, v_device_map_); }
    bool InsertWrapper(vulkan_wrappers::ImageWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, v_image_map_); }
    bool InsertWrapper(vulkan_wrappers::InstanceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, v_instance_map_); }
    bool InsertWrapper(vulkan_wrappers::PhysicalDeviceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, v_physicalDevice_map_); }
    bool InsertWrapper(vulkan_wrappers::SwapchainKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, v_swapchainKHR_map_); }
    bool InsertWrapper(openxr_wrappers::ActionWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_action_map_); }
    bool InsertWrapper(openxr_wrappers::ActionSetWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_actionSet_map_); }
    bool InsertWrapper(openxr_wrappers::BodyTrackerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_bodyTrackerFB_map_); }
    bool InsertWrapper(openxr_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(openxr_wrappers::ExportedLocalizationMapMLWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_exportedLocalizationMapML_map_); }
    bool InsertWrapper(openxr_wrappers::EyeTrackerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_eyeTrackerFB_map_); }
    bool InsertWrapper(openxr_wrappers::FaceTracker2FBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_faceTracker2FB_map_); }
    bool InsertWrapper(openxr_wrappers::FaceTrackerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_faceTrackerFB_map_); }
    bool InsertWrapper(openxr_wrappers::FacialTrackerHTCWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_facialTrackerHTC_map_); }
    bool InsertWrapper(openxr_wrappers::FoveationProfileFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_foveationProfileFB_map_); }
    bool InsertWrapper(openxr_wrappers::GeometryInstanceFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_geometryInstanceFB_map_); }
    bool InsertWrapper(openxr_wrappers::HandTrackerEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_handTrackerEXT_map_); }
    bool InsertWrapper(openxr_wrappers::InstanceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_instance_map_); }
    bool InsertWrapper(openxr_wrappers::MarkerDetectorMLWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_markerDetectorML_map_); }
    bool InsertWrapper(openxr_wrappers::PassthroughColorLutMETAWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_passthroughColorLutMETA_map_); }
    bool InsertWrapper(openxr_wrappers::PassthroughFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_passthroughFB_map_); }
    bool InsertWrapper(openxr_wrappers::PassthroughHTCWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_passthroughHTC_map_); }
    bool InsertWrapper(openxr_wrappers::PassthroughLayerFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_passthroughLayerFB_map_); }
    bool InsertWrapper(openxr_wrappers::PlaneDetectorEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_planeDetectorEXT_map_); }
    bool InsertWrapper(openxr_wrappers::SceneMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_sceneMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::SceneObserverMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_sceneObserverMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::SessionWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_session_map_); }
    bool InsertWrapper(openxr_wrappers::SpaceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_space_map_); }
    bool InsertWrapper(openxr_wrappers::SpaceUserFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_spaceUserFB_map_); }
    bool InsertWrapper(openxr_wrappers::SpatialAnchorMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_spatialAnchorMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_spatialAnchorStoreConnectionMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_spatialGraphNodeBindingMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::SwapchainWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_swapchain_map_); }
    bool InsertWrapper(openxr_wrappers::TriangleMeshFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_triangleMeshFB_map_); }
    bool InsertWrapper(openxr_wrappers::VirtualKeyboardMETAWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_virtualKeyboardMETA_map_); }
    bool InsertWrapper(openxr_wrappers::AsyncRequestIdFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_asyncRequestIdFB_map_); }
    bool InsertWrapper(openxr_wrappers::ControllerModelKeyMSFTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_controllerModelKeyMSFT_map_); }
    bool InsertWrapper(openxr_wrappers::MarkerMLWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_markerML_map_); }
    bool InsertWrapper(openxr_wrappers::PathWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_path_map_); }
    bool InsertWrapper(openxr_wrappers::RenderModelKeyFBWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_renderModelKeyFB_map_); }
    bool InsertWrapper(openxr_wrappers::SystemIdWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, x_systemId_map_); }

    bool RemoveWrapper(const vulkan_wrappers::DeviceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, v_device_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::ImageWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, v_image_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::InstanceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, v_instance_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::PhysicalDeviceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, v_physicalDevice_map_);
    }
    bool RemoveWrapper(const vulkan_wrappers::SwapchainKHRWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, v_swapchainKHR_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::ActionWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_action_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::ActionSetWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_actionSet_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::BodyTrackerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_bodyTrackerFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_debugUtilsMessengerEXT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::ExportedLocalizationMapMLWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_exportedLocalizationMapML_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::EyeTrackerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_eyeTrackerFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::FaceTracker2FBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_faceTracker2FB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::FaceTrackerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_faceTrackerFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::FacialTrackerHTCWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_facialTrackerHTC_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::FoveationProfileFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_foveationProfileFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::GeometryInstanceFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_geometryInstanceFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::HandTrackerEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_handTrackerEXT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::InstanceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_instance_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::MarkerDetectorMLWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_markerDetectorML_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PassthroughColorLutMETAWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_passthroughColorLutMETA_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PassthroughFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_passthroughFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PassthroughHTCWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_passthroughHTC_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PassthroughLayerFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_passthroughLayerFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PlaneDetectorEXTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_planeDetectorEXT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SceneMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_sceneMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SceneObserverMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_sceneObserverMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SessionWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_session_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SpaceWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_space_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SpaceUserFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_spaceUserFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SpatialAnchorMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_spatialAnchorMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_spatialAnchorStoreConnectionMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_spatialGraphNodeBindingMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SwapchainWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_swapchain_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::TriangleMeshFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_triangleMeshFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::VirtualKeyboardMETAWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_virtualKeyboardMETA_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::AsyncRequestIdFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_asyncRequestIdFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::ControllerModelKeyMSFTWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_controllerModelKeyMSFT_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::MarkerMLWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_markerML_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::PathWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_path_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::RenderModelKeyFBWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_renderModelKeyFB_map_);
    }
    bool RemoveWrapper(const openxr_wrappers::SystemIdWrapper* wrapper) {
         if (wrapper == nullptr) return false;
         return RemoveEntry(wrapper->handle, x_systemId_map_);
    }

    template<typename Wrapper> const Wrapper* GetWrapper(typename Wrapper::HandleType handle) const { return nullptr; }

    template<typename Wrapper> Wrapper* GetWrapper(typename Wrapper::HandleType handle) { return nullptr; }

  private:
    std::unordered_map<VkDevice, vulkan_wrappers::DeviceWrapper*> v_device_map_;
    std::unordered_map<VkImage, vulkan_wrappers::ImageWrapper*> v_image_map_;
    std::unordered_map<VkInstance, vulkan_wrappers::InstanceWrapper*> v_instance_map_;
    std::unordered_map<VkPhysicalDevice, vulkan_wrappers::PhysicalDeviceWrapper*> v_physicalDevice_map_;
    std::unordered_map<VkSwapchainKHR, vulkan_wrappers::SwapchainKHRWrapper*> v_swapchainKHR_map_;
    std::unordered_map<XrAction, openxr_wrappers::ActionWrapper*> x_action_map_;
    std::unordered_map<XrActionSet, openxr_wrappers::ActionSetWrapper*> x_actionSet_map_;
    std::unordered_map<XrBodyTrackerFB, openxr_wrappers::BodyTrackerFBWrapper*> x_bodyTrackerFB_map_;
    std::unordered_map<XrDebugUtilsMessengerEXT, openxr_wrappers::DebugUtilsMessengerEXTWrapper*> x_debugUtilsMessengerEXT_map_;
    std::unordered_map<XrExportedLocalizationMapML, openxr_wrappers::ExportedLocalizationMapMLWrapper*> x_exportedLocalizationMapML_map_;
    std::unordered_map<XrEyeTrackerFB, openxr_wrappers::EyeTrackerFBWrapper*> x_eyeTrackerFB_map_;
    std::unordered_map<XrFaceTracker2FB, openxr_wrappers::FaceTracker2FBWrapper*> x_faceTracker2FB_map_;
    std::unordered_map<XrFaceTrackerFB, openxr_wrappers::FaceTrackerFBWrapper*> x_faceTrackerFB_map_;
    std::unordered_map<XrFacialTrackerHTC, openxr_wrappers::FacialTrackerHTCWrapper*> x_facialTrackerHTC_map_;
    std::unordered_map<XrFoveationProfileFB, openxr_wrappers::FoveationProfileFBWrapper*> x_foveationProfileFB_map_;
    std::unordered_map<XrGeometryInstanceFB, openxr_wrappers::GeometryInstanceFBWrapper*> x_geometryInstanceFB_map_;
    std::unordered_map<XrHandTrackerEXT, openxr_wrappers::HandTrackerEXTWrapper*> x_handTrackerEXT_map_;
    std::unordered_map<XrInstance, openxr_wrappers::InstanceWrapper*> x_instance_map_;
    std::unordered_map<XrMarkerDetectorML, openxr_wrappers::MarkerDetectorMLWrapper*> x_markerDetectorML_map_;
    std::unordered_map<XrPassthroughColorLutMETA, openxr_wrappers::PassthroughColorLutMETAWrapper*> x_passthroughColorLutMETA_map_;
    std::unordered_map<XrPassthroughFB, openxr_wrappers::PassthroughFBWrapper*> x_passthroughFB_map_;
    std::unordered_map<XrPassthroughHTC, openxr_wrappers::PassthroughHTCWrapper*> x_passthroughHTC_map_;
    std::unordered_map<XrPassthroughLayerFB, openxr_wrappers::PassthroughLayerFBWrapper*> x_passthroughLayerFB_map_;
    std::unordered_map<XrPlaneDetectorEXT, openxr_wrappers::PlaneDetectorEXTWrapper*> x_planeDetectorEXT_map_;
    std::unordered_map<XrSceneMSFT, openxr_wrappers::SceneMSFTWrapper*> x_sceneMSFT_map_;
    std::unordered_map<XrSceneObserverMSFT, openxr_wrappers::SceneObserverMSFTWrapper*> x_sceneObserverMSFT_map_;
    std::unordered_map<XrSession, openxr_wrappers::SessionWrapper*> x_session_map_;
    std::unordered_map<XrSpace, openxr_wrappers::SpaceWrapper*> x_space_map_;
    std::unordered_map<XrSpaceUserFB, openxr_wrappers::SpaceUserFBWrapper*> x_spaceUserFB_map_;
    std::unordered_map<XrSpatialAnchorMSFT, openxr_wrappers::SpatialAnchorMSFTWrapper*> x_spatialAnchorMSFT_map_;
    std::unordered_map<XrSpatialAnchorStoreConnectionMSFT, openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper*> x_spatialAnchorStoreConnectionMSFT_map_;
    std::unordered_map<XrSpatialGraphNodeBindingMSFT, openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper*> x_spatialGraphNodeBindingMSFT_map_;
    std::unordered_map<XrSwapchain, openxr_wrappers::SwapchainWrapper*> x_swapchain_map_;
    std::unordered_map<XrTriangleMeshFB, openxr_wrappers::TriangleMeshFBWrapper*> x_triangleMeshFB_map_;
    std::unordered_map<XrVirtualKeyboardMETA, openxr_wrappers::VirtualKeyboardMETAWrapper*> x_virtualKeyboardMETA_map_;
    std::unordered_map<XrAsyncRequestIdFB, openxr_wrappers::AsyncRequestIdFBWrapper*> x_asyncRequestIdFB_map_;
    std::unordered_map<XrControllerModelKeyMSFT, openxr_wrappers::ControllerModelKeyMSFTWrapper*> x_controllerModelKeyMSFT_map_;
    std::unordered_map<XrMarkerML, openxr_wrappers::MarkerMLWrapper*> x_markerML_map_;
    std::unordered_map<XrPath, openxr_wrappers::PathWrapper*> x_path_map_;
    std::unordered_map<XrRenderModelKeyFB, openxr_wrappers::RenderModelKeyFBWrapper*> x_renderModelKeyFB_map_;
    std::unordered_map<XrSystemId, openxr_wrappers::SystemIdWrapper*> x_systemId_map_;
};

template<> inline const vulkan_wrappers::DeviceWrapper* OpenXrStateHandleTable::GetWrapper<vulkan_wrappers::DeviceWrapper>(VkDevice handle) const { return OpenXrStateTableBase::GetWrapper(handle, v_device_map_); }
template<> inline const vulkan_wrappers::ImageWrapper* OpenXrStateHandleTable::GetWrapper<vulkan_wrappers::ImageWrapper>(VkImage handle) const { return OpenXrStateTableBase::GetWrapper(handle, v_image_map_); }
template<> inline const vulkan_wrappers::InstanceWrapper* OpenXrStateHandleTable::GetWrapper<vulkan_wrappers::InstanceWrapper>(VkInstance handle) const { return OpenXrStateTableBase::GetWrapper(handle, v_instance_map_); }
template<> inline const vulkan_wrappers::PhysicalDeviceWrapper* OpenXrStateHandleTable::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(VkPhysicalDevice handle) const { return OpenXrStateTableBase::GetWrapper(handle, v_physicalDevice_map_); }
template<> inline const vulkan_wrappers::SwapchainKHRWrapper* OpenXrStateHandleTable::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(VkSwapchainKHR handle) const { return OpenXrStateTableBase::GetWrapper(handle, v_swapchainKHR_map_); }
template<> inline const openxr_wrappers::ActionWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ActionWrapper>(XrAction handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_action_map_); }
template<> inline const openxr_wrappers::ActionSetWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ActionSetWrapper>(XrActionSet handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_actionSet_map_); }
template<> inline const openxr_wrappers::BodyTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::BodyTrackerFBWrapper>(XrBodyTrackerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_bodyTrackerFB_map_); }
template<> inline const openxr_wrappers::DebugUtilsMessengerEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(XrDebugUtilsMessengerEXT handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_debugUtilsMessengerEXT_map_); }
template<> inline const openxr_wrappers::ExportedLocalizationMapMLWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ExportedLocalizationMapMLWrapper>(XrExportedLocalizationMapML handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_exportedLocalizationMapML_map_); }
template<> inline const openxr_wrappers::EyeTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::EyeTrackerFBWrapper>(XrEyeTrackerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_eyeTrackerFB_map_); }
template<> inline const openxr_wrappers::FaceTracker2FBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FaceTracker2FBWrapper>(XrFaceTracker2FB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_faceTracker2FB_map_); }
template<> inline const openxr_wrappers::FaceTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FaceTrackerFBWrapper>(XrFaceTrackerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_faceTrackerFB_map_); }
template<> inline const openxr_wrappers::FacialTrackerHTCWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FacialTrackerHTCWrapper>(XrFacialTrackerHTC handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_facialTrackerHTC_map_); }
template<> inline const openxr_wrappers::FoveationProfileFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FoveationProfileFBWrapper>(XrFoveationProfileFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_foveationProfileFB_map_); }
template<> inline const openxr_wrappers::GeometryInstanceFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::GeometryInstanceFBWrapper>(XrGeometryInstanceFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_geometryInstanceFB_map_); }
template<> inline const openxr_wrappers::HandTrackerEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::HandTrackerEXTWrapper>(XrHandTrackerEXT handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_handTrackerEXT_map_); }
template<> inline const openxr_wrappers::InstanceWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::InstanceWrapper>(XrInstance handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_instance_map_); }
template<> inline const openxr_wrappers::MarkerDetectorMLWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(XrMarkerDetectorML handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_markerDetectorML_map_); }
template<> inline const openxr_wrappers::PassthroughColorLutMETAWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughColorLutMETAWrapper>(XrPassthroughColorLutMETA handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_passthroughColorLutMETA_map_); }
template<> inline const openxr_wrappers::PassthroughFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughFBWrapper>(XrPassthroughFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_passthroughFB_map_); }
template<> inline const openxr_wrappers::PassthroughHTCWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughHTCWrapper>(XrPassthroughHTC handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_passthroughHTC_map_); }
template<> inline const openxr_wrappers::PassthroughLayerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughLayerFBWrapper>(XrPassthroughLayerFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_passthroughLayerFB_map_); }
template<> inline const openxr_wrappers::PlaneDetectorEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PlaneDetectorEXTWrapper>(XrPlaneDetectorEXT handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_planeDetectorEXT_map_); }
template<> inline const openxr_wrappers::SceneMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SceneMSFTWrapper>(XrSceneMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_sceneMSFT_map_); }
template<> inline const openxr_wrappers::SceneObserverMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SceneObserverMSFTWrapper>(XrSceneObserverMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_sceneObserverMSFT_map_); }
template<> inline const openxr_wrappers::SessionWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SessionWrapper>(XrSession handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_session_map_); }
template<> inline const openxr_wrappers::SpaceWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpaceWrapper>(XrSpace handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_space_map_); }
template<> inline const openxr_wrappers::SpaceUserFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpaceUserFBWrapper>(XrSpaceUserFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_spaceUserFB_map_); }
template<> inline const openxr_wrappers::SpatialAnchorMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialAnchorMSFTWrapper>(XrSpatialAnchorMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_spatialAnchorMSFT_map_); }
template<> inline const openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(XrSpatialAnchorStoreConnectionMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_spatialAnchorStoreConnectionMSFT_map_); }
template<> inline const openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(XrSpatialGraphNodeBindingMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_spatialGraphNodeBindingMSFT_map_); }
template<> inline const openxr_wrappers::SwapchainWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SwapchainWrapper>(XrSwapchain handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_swapchain_map_); }
template<> inline const openxr_wrappers::TriangleMeshFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(XrTriangleMeshFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_triangleMeshFB_map_); }
template<> inline const openxr_wrappers::VirtualKeyboardMETAWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::VirtualKeyboardMETAWrapper>(XrVirtualKeyboardMETA handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_virtualKeyboardMETA_map_); }
template<> inline const openxr_wrappers::AsyncRequestIdFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::AsyncRequestIdFBWrapper>(XrAsyncRequestIdFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_asyncRequestIdFB_map_); }
template<> inline const openxr_wrappers::ControllerModelKeyMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ControllerModelKeyMSFTWrapper>(XrControllerModelKeyMSFT handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_controllerModelKeyMSFT_map_); }
template<> inline const openxr_wrappers::MarkerMLWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::MarkerMLWrapper>(XrMarkerML handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_markerML_map_); }
template<> inline const openxr_wrappers::PathWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PathWrapper>(XrPath handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_path_map_); }
template<> inline const openxr_wrappers::RenderModelKeyFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::RenderModelKeyFBWrapper>(XrRenderModelKeyFB handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_renderModelKeyFB_map_); }
template<> inline const openxr_wrappers::SystemIdWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SystemIdWrapper>(XrSystemId handle) const { return OpenXrStateTableBase::GetWrapper(handle, x_systemId_map_); }

template<> inline vulkan_wrappers::DeviceWrapper* OpenXrStateHandleTable::GetWrapper<vulkan_wrappers::DeviceWrapper>(VkDevice handle) { return OpenXrStateTableBase::GetWrapper(handle, v_device_map_); }
template<> inline vulkan_wrappers::ImageWrapper* OpenXrStateHandleTable::GetWrapper<vulkan_wrappers::ImageWrapper>(VkImage handle) { return OpenXrStateTableBase::GetWrapper(handle, v_image_map_); }
template<> inline vulkan_wrappers::InstanceWrapper* OpenXrStateHandleTable::GetWrapper<vulkan_wrappers::InstanceWrapper>(VkInstance handle) { return OpenXrStateTableBase::GetWrapper(handle, v_instance_map_); }
template<> inline vulkan_wrappers::PhysicalDeviceWrapper* OpenXrStateHandleTable::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(VkPhysicalDevice handle) { return OpenXrStateTableBase::GetWrapper(handle, v_physicalDevice_map_); }
template<> inline vulkan_wrappers::SwapchainKHRWrapper* OpenXrStateHandleTable::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(VkSwapchainKHR handle) { return OpenXrStateTableBase::GetWrapper(handle, v_swapchainKHR_map_); }
template<> inline openxr_wrappers::ActionWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ActionWrapper>(XrAction handle) { return OpenXrStateTableBase::GetWrapper(handle, x_action_map_); }
template<> inline openxr_wrappers::ActionSetWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ActionSetWrapper>(XrActionSet handle) { return OpenXrStateTableBase::GetWrapper(handle, x_actionSet_map_); }
template<> inline openxr_wrappers::BodyTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::BodyTrackerFBWrapper>(XrBodyTrackerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_bodyTrackerFB_map_); }
template<> inline openxr_wrappers::DebugUtilsMessengerEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(XrDebugUtilsMessengerEXT handle) { return OpenXrStateTableBase::GetWrapper(handle, x_debugUtilsMessengerEXT_map_); }
template<> inline openxr_wrappers::ExportedLocalizationMapMLWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ExportedLocalizationMapMLWrapper>(XrExportedLocalizationMapML handle) { return OpenXrStateTableBase::GetWrapper(handle, x_exportedLocalizationMapML_map_); }
template<> inline openxr_wrappers::EyeTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::EyeTrackerFBWrapper>(XrEyeTrackerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_eyeTrackerFB_map_); }
template<> inline openxr_wrappers::FaceTracker2FBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FaceTracker2FBWrapper>(XrFaceTracker2FB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_faceTracker2FB_map_); }
template<> inline openxr_wrappers::FaceTrackerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FaceTrackerFBWrapper>(XrFaceTrackerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_faceTrackerFB_map_); }
template<> inline openxr_wrappers::FacialTrackerHTCWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FacialTrackerHTCWrapper>(XrFacialTrackerHTC handle) { return OpenXrStateTableBase::GetWrapper(handle, x_facialTrackerHTC_map_); }
template<> inline openxr_wrappers::FoveationProfileFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::FoveationProfileFBWrapper>(XrFoveationProfileFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_foveationProfileFB_map_); }
template<> inline openxr_wrappers::GeometryInstanceFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::GeometryInstanceFBWrapper>(XrGeometryInstanceFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_geometryInstanceFB_map_); }
template<> inline openxr_wrappers::HandTrackerEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::HandTrackerEXTWrapper>(XrHandTrackerEXT handle) { return OpenXrStateTableBase::GetWrapper(handle, x_handTrackerEXT_map_); }
template<> inline openxr_wrappers::InstanceWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::InstanceWrapper>(XrInstance handle) { return OpenXrStateTableBase::GetWrapper(handle, x_instance_map_); }
template<> inline openxr_wrappers::MarkerDetectorMLWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::MarkerDetectorMLWrapper>(XrMarkerDetectorML handle) { return OpenXrStateTableBase::GetWrapper(handle, x_markerDetectorML_map_); }
template<> inline openxr_wrappers::PassthroughColorLutMETAWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughColorLutMETAWrapper>(XrPassthroughColorLutMETA handle) { return OpenXrStateTableBase::GetWrapper(handle, x_passthroughColorLutMETA_map_); }
template<> inline openxr_wrappers::PassthroughFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughFBWrapper>(XrPassthroughFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_passthroughFB_map_); }
template<> inline openxr_wrappers::PassthroughHTCWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughHTCWrapper>(XrPassthroughHTC handle) { return OpenXrStateTableBase::GetWrapper(handle, x_passthroughHTC_map_); }
template<> inline openxr_wrappers::PassthroughLayerFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PassthroughLayerFBWrapper>(XrPassthroughLayerFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_passthroughLayerFB_map_); }
template<> inline openxr_wrappers::PlaneDetectorEXTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PlaneDetectorEXTWrapper>(XrPlaneDetectorEXT handle) { return OpenXrStateTableBase::GetWrapper(handle, x_planeDetectorEXT_map_); }
template<> inline openxr_wrappers::SceneMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SceneMSFTWrapper>(XrSceneMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, x_sceneMSFT_map_); }
template<> inline openxr_wrappers::SceneObserverMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SceneObserverMSFTWrapper>(XrSceneObserverMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, x_sceneObserverMSFT_map_); }
template<> inline openxr_wrappers::SessionWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SessionWrapper>(XrSession handle) { return OpenXrStateTableBase::GetWrapper(handle, x_session_map_); }
template<> inline openxr_wrappers::SpaceWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpaceWrapper>(XrSpace handle) { return OpenXrStateTableBase::GetWrapper(handle, x_space_map_); }
template<> inline openxr_wrappers::SpaceUserFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpaceUserFBWrapper>(XrSpaceUserFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_spaceUserFB_map_); }
template<> inline openxr_wrappers::SpatialAnchorMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialAnchorMSFTWrapper>(XrSpatialAnchorMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, x_spatialAnchorMSFT_map_); }
template<> inline openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(XrSpatialAnchorStoreConnectionMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, x_spatialAnchorStoreConnectionMSFT_map_); }
template<> inline openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(XrSpatialGraphNodeBindingMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, x_spatialGraphNodeBindingMSFT_map_); }
template<> inline openxr_wrappers::SwapchainWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SwapchainWrapper>(XrSwapchain handle) { return OpenXrStateTableBase::GetWrapper(handle, x_swapchain_map_); }
template<> inline openxr_wrappers::TriangleMeshFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(XrTriangleMeshFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_triangleMeshFB_map_); }
template<> inline openxr_wrappers::VirtualKeyboardMETAWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::VirtualKeyboardMETAWrapper>(XrVirtualKeyboardMETA handle) { return OpenXrStateTableBase::GetWrapper(handle, x_virtualKeyboardMETA_map_); }
template<> inline openxr_wrappers::AsyncRequestIdFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::AsyncRequestIdFBWrapper>(XrAsyncRequestIdFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_asyncRequestIdFB_map_); }
template<> inline openxr_wrappers::ControllerModelKeyMSFTWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::ControllerModelKeyMSFTWrapper>(XrControllerModelKeyMSFT handle) { return OpenXrStateTableBase::GetWrapper(handle, x_controllerModelKeyMSFT_map_); }
template<> inline openxr_wrappers::MarkerMLWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::MarkerMLWrapper>(XrMarkerML handle) { return OpenXrStateTableBase::GetWrapper(handle, x_markerML_map_); }
template<> inline openxr_wrappers::PathWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::PathWrapper>(XrPath handle) { return OpenXrStateTableBase::GetWrapper(handle, x_path_map_); }
template<> inline openxr_wrappers::RenderModelKeyFBWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::RenderModelKeyFBWrapper>(XrRenderModelKeyFB handle) { return OpenXrStateTableBase::GetWrapper(handle, x_renderModelKeyFB_map_); }
template<> inline openxr_wrappers::SystemIdWrapper* OpenXrStateHandleTable::GetWrapper<openxr_wrappers::SystemIdWrapper>(XrSystemId handle) { return OpenXrStateTableBase::GetWrapper(handle, x_systemId_map_); }

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_STATE_TABLE_H
