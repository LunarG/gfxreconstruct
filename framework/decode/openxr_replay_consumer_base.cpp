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
#include <array>

#if defined(__ANDROID__)
#include <android_native_app_glue.h>
#endif

#include "util/platform.h"
#include "util/defines.h"

#ifdef XR_NO_PROTOTYPES
#undef XR_NO_PROTOTYPES
#endif
#define XR_EXTENSION_PROTOTYPES

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_platform.h"

#include "decode/openxr_handle_mapping_util.h"
#include "decode/vulkan_handle_mapping_util.h"

#include "openxr_replay_consumer_base.h"
#include "vulkan_replay_consumer_base.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"

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

const encode::OpenXrInstanceTable*
OpenXrReplayConsumerBase::GetInstanceTable(XrEnvironmentDepthProviderMETA handle) const
{
    auto instance = envdepthproviderMETA_to_instance_.find(handle);
    assert(instance != envdepthproviderMETA_to_instance_.end());
    return (instance != envdepthproviderMETA_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
}

const encode::OpenXrInstanceTable*
OpenXrReplayConsumerBase::GetInstanceTable(XrEnvironmentDepthSwapchainMETA handle) const
{
    auto instance = envdepthswapchainMETA_to_instance_.find(handle);
    assert(instance != envdepthswapchainMETA_to_instance_.end());
    return (instance != envdepthswapchainMETA_to_instance_.end()) ? GetInstanceTable(instance->second) : nullptr;
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

void OpenXrReplayConsumerBase::AssociateParent(XrEnvironmentDepthProviderMETA env_depth_provider, XrSession session)
{
    envdepthproviderMETA_to_instance_[env_depth_provider] = session_to_instance_[session];
}

void OpenXrReplayConsumerBase::AssociateParent(XrEnvironmentDepthSwapchainMETA env_depth_swapchain,
                                               XrEnvironmentDepthProviderMETA  environment_depth_provider)
{
    envdepthswapchainMETA_to_instance_[env_depth_swapchain] =
        envdepthproviderMETA_to_instance_[environment_depth_provider];
}

#endif // defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)

void OpenXrReplayConsumerBase::Process_xrInitializeLoaderKHR(
    const ApiCallInfo&                                           call_info,
    XrResult                                                     returnValue,
    StructPointerDecoder<Decoded_XrLoaderInitInfoBaseHeaderKHR>* loaderInitInfo)
{
    XrResult replay_result = XR_SUCCESS;

    PFN_xrInitializeLoaderKHR pfn_initialize_loader;
    xrGetInstanceProcAddr(XR_NULL_HANDLE, "xrInitializeLoaderKHR", (PFN_xrVoidFunction*)&pfn_initialize_loader);
    if (pfn_initialize_loader)
    {
#if defined(__ANDROID__)
        XrLoaderInitInfoAndroidKHR loader_init = {
            XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR,
            nullptr,
            android_app_->activity->vm,
            android_app_->activity->clazz,
        };

        replay_result = pfn_initialize_loader((XrLoaderInitInfoBaseHeaderKHR*)&loader_init);
#endif
    }
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

    PFN_xrEnumerateInstanceExtensionProperties instance_extension_proc;
    xrGetInstanceProcAddr(
        XR_NULL_HANDLE, "xrEnumerateInstanceExtensionProperties", (PFN_xrVoidFunction*)&instance_extension_proc);

    uint32_t                           ext_count = 0;
    std::vector<XrExtensionProperties> ext_props;
    XrResult                           ext_result = instance_extension_proc(nullptr, 0, &ext_count, nullptr);
    if (ext_result == XR_SUCCESS && ext_count > 0)
    {
        ext_props.resize(ext_count);
        for (uint32_t i = 0; i < ext_props.size(); ++i)
        {
            ext_props[i].type = XR_TYPE_EXTENSION_PROPERTIES;
            ext_props[i].next = nullptr;
        }
        ext_result = instance_extension_proc(nullptr, ext_count, &ext_count, ext_props.data());
    }

#if defined(__ANDROID__)
    XrInstanceCreateInfoAndroidKHR init_android = {
        XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR,
        nullptr,
        android_app_->activity->vm,
        android_app_->activity->clazz,
    };

    // Remove the original XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR structure with incorrect info
    // TODO: This breaks if there is any structure in front of this in the next call chain.
    const XrBaseInStructure* next_struct = reinterpret_cast<const XrBaseInStructure*>(create_info->next);
    while (next_struct != nullptr && next_struct->type == XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR)
    {
        next_struct = next_struct->next;
    }
    init_android.next = reinterpret_cast<const void*>(next_struct);

    XrInstanceCreateInfo new_create_info = *create_info;
    new_create_info.next                 = &init_android;
    create_info                          = &new_create_info;
#endif // IGL_PLATFORM_ANDROID

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

void OpenXrReplayConsumerBase::UpdateState_xrEndSession(const ApiCallInfo& call_info,
                                                        XrResult           returnValue,
                                                        format::HandleId   session,
                                                        XrResult           replay_result)
{
    XrSession    in_session   = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    SessionData& session_data = GetSessionData(in_session);

    session_data.ClearViewRelativeProxySpaces(GetInstanceTable(in_session));
}

void OpenXrReplayConsumerBase::UpdateState_xrBeginFrame(const ApiCallInfo&                              call_info,
                                                        XrResult                                        returnValue,
                                                        format::HandleId                                session,
                                                        StructPointerDecoder<Decoded_XrFrameBeginInfo>* frameBeginInfo,
                                                        XrResult                                        replay_result)
{
    XrSession    in_session   = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    SessionData& session_data = GetSessionData(in_session);
    session_data.ClearViewRelativeProxySpaces(GetInstanceTable(in_session));
}

struct EventStrings
{
    XrStructureType type;
    char            name[128];
};
static EventStrings events_to_string[] = {
    { XR_TYPE_UNKNOWN, "Unknown Event Type" },
    { XR_TYPE_EVENT_DATA_BUFFER, "XR_TYPE_EVENT_DATA_BUFFER" },
    { XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING, "XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING" },
    { XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED, "XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED" },
    { XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING, "XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING" },
    { XR_TYPE_EVENT_DATA_EVENTS_LOST, "XR_TYPE_EVENT_DATA_EVENTS_LOST" },
    { XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED, "XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED" },
    { XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT, "XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT" },
    { XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR, "XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR" },
    { XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX,
      "XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX" },
    { XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB, "XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB" },
    { XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB, "XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB" },
    { XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB, "XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB" },
    { XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB, "XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB" },
    { XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO, "XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO" },
    { XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML, "XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML" },
    { XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML, "XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML" },
    { XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML, "XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML" },
    { XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB, "XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB" },
    { XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB, "XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB" },
    { XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB, "XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB" },
    { XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB, "XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB" },
    { XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB, "XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB" },
    { XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB, "XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB" },
    { XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META, "XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META" },
    { XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META, "XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META" },
    { XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META, "XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META" },
    { XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META, "XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META" },
    { XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META, "XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META" },
    { XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB, "XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB" },
    { XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT, "XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT" },
};

const char* GetEventTypeString(XrStructureType type)
{
    size_t len = sizeof(events_to_string) / sizeof(EventStrings);
    for (size_t ii = 0; ii < len; ++ii)
    {
        if (type == events_to_string[ii].type)
        {
            return events_to_string[ii].name;
        }
    }
    return events_to_string[0].name;
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
    XrEventDataBuffer* capture_event = eventData->GetPointer();

    // We received events that haven't been handled yet already, so see if this one is in the list already
    for (size_t ii = 0; ii < received_events_.size(); ++ii)
    {
        if (received_events_[ii].type == capture_event->type)
        {
            GFXRECON_LOG_WARNING("Previously received event %s (0x%x, %u)",
                                 GetEventTypeString(capture_event->type),
                                 capture_event->type,
                                 capture_event->type);
            received_events_.erase(received_events_.begin() + ii);
            return;
        }
    }

    XrEventDataBuffer* out_eventData =
        eventData->IsNull() ? nullptr : eventData->AllocateOutputData(1, { XR_TYPE_EVENT_DATA_BUFFER, nullptr });
    InitializeOutputStructNext(eventData);

    XrResult replay_result;

    // WIP: Put this constant somewhere interesting
    const uint32_t kRetryLimit      = 10000;
    const int64_t  kMaxSleepLimitNs = 500000000; // 500ms
    uint32_t       retry_count      = 0;

    if (out_eventData && capture_event)
    {
        int64_t sleep_time = 1;
        do
        {
            *out_eventData = XrEventDataBuffer{ XR_TYPE_EVENT_DATA_BUFFER };
            replay_result  = GetInstanceTable(in_instance)->PollEvent(in_instance, out_eventData);
            retry_count++;

            if (capture_event->type != out_eventData->type)
            {
                if (replay_result == XR_SUCCESS)
                {
                    // Add it to the list of received events
                    received_events_.push_back(*out_eventData);
                    GFXRECON_LOG_WARNING("Recording event for later %s (0x%x, %u)",
                                         GetEventTypeString(capture_event->type),
                                         capture_event->type,
                                         capture_event->type);

                    // If we grow too lare on the event vector, it's probably because we have
                    // received a bunch of events we can not handle.  So remove the first 100
                    // events to make room for more without bloating the list size.
                    // TODO: Perhaps do this more elegantly?
                    if (received_events_.size() > 1000)
                    {
                        GFXRECON_LOG_WARNING("Event list is now %d in size, stripping the first 100!",
                                             received_events_.size());
                        received_events_.erase(received_events_.begin(), received_events_.begin() + 100);
                    }
                }
                else if (replay_result == XR_EVENT_UNAVAILABLE)
                {
                    // Yield and retry
                    std::this_thread::sleep_for(std::chrono::nanoseconds(sleep_time));

                    if (sleep_time < kMaxSleepLimitNs)
                    {
                        // Next time, sleep for double what we initially slept for.  This way if we're just
                        // spinning, we spin less and less each time.
                        sleep_time *= 2;
                    }
                    // Clamp it to the max (should stay here from this point forward)
                    if (sleep_time > kMaxSleepLimitNs)
                    {
                        sleep_time = kMaxSleepLimitNs;
                    }
                }
                else
                {
                    GFXRECON_LOG_ERROR("xrPollEvent encountered an error of type 0x%x", replay_result);
                    break;
                }
            }
        } while ((retry_count < kRetryLimit) && capture_event->type != out_eventData->type);
        if (capture_event->type != out_eventData->type)
        {
            GFXRECON_LOG_ERROR("Event %s (0x%x %d) never occurred!",
                               GetEventTypeString(capture_event->type),
                               capture_event->type,
                               capture_event->type);
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

void OpenXrReplayConsumerBase::Process_xrCreateSwapchain(
    const ApiCallInfo&                                   call_info,
    XrResult                                             returnValue,
    format::HandleId                                     session,
    StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* createInfo,
    HandlePointerDecoder<XrSwapchain>*                   swapchain)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSwapchainCreateInfo* in_createInfo = createInfo->GetPointer();
    if (!swapchain->IsNull())
    {
        swapchain->SetHandleLength(1);
    }
    XrSwapchain* out_swapchain = swapchain->GetHandlePointer();

    XrSwapchainCreateInfo amended_info = *in_createInfo;
    amended_info.usageFlags |= XR_SWAPCHAIN_USAGE_TRANSFER_DST_BIT;

    XrResult replay_result = GetInstanceTable(in_session)->CreateSwapchain(in_session, &amended_info, out_swapchain);
    CheckResult("xrCreateSwapchain", returnValue, replay_result, call_info);

    AddHandle<OpenXrSwapchainInfo>(
        session, swapchain->GetPointer(), out_swapchain, &CommonObjectInfoTable::AddXrSwapchainInfo);

    AssociateParent(*out_swapchain, in_session);

    auto&          session_data = GetSessionData(in_session);
    SwapchainData& swap_data    = AddSwapchainData(*out_swapchain);
    swap_data.InitSwapchainData(session_data.GetGraphicsBinding(), amended_info, *out_swapchain);
}

void OpenXrReplayConsumerBase::UpdateState_xrEnumerateSwapchainImages(
    const ApiCallInfo&                                        call_info,
    XrResult                                                  returnValue,
    format::HandleId                                          swapchain,
    uint32_t                                                  imageCapacityInput,
    PointerDecoder<uint32_t>*                                 imageCountOutput,
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images,
    XrResult                                                  replay_result)
{
    // When there's nothing to do, do nothing
    if (!XR_SUCCEEDED(returnValue) || (imageCapacityInput == 0) || (images->GetOutputLength() == 0))
    {
        return;
    }

    XrSwapchain in_swapchain   = MapHandle<OpenXrSwapchainInfo>(swapchain, &CommonObjectInfoTable::GetXrSwapchainInfo);
    auto&       swapchain_data = GetSwapchainData(in_swapchain);

    XrResult result = swapchain_data.ImportReplaySwapchain(images);
    if (XR_SUCCEEDED(result))
    {
        result = swapchain_data.InitVirtualSwapchain(imageCountOutput, images);
    }

    if (!XR_SUCCEEDED(result))
    {
        GFXRECON_LOG_FATAL("API call at index: %d thread: %d virtual swapchain initialzation returned error value %s.  "
                           "Replay cannot continue.",
                           call_info.index,
                           call_info.thread_id,
                           util::ToString<XrResult>(result).c_str());
        RaiseFatalError(enumutil::GetResultDescription(result));
    }
}

void OpenXrReplayConsumerBase::UpdateState_xrAcquireSwapchainImage(
    const ApiCallInfo&                                         call_info,
    XrResult                                                   returnValue,
    format::HandleId                                           swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageAcquireInfo>* acquireInfo,
    PointerDecoder<uint32_t>*                                  index,
    XrResult                                                   replay_result)
{
    XrSwapchain in_swapchain  = MapHandle<OpenXrSwapchainInfo>(swapchain, &CommonObjectInfoTable::GetXrSwapchainInfo);
    uint32_t    capture_index = *index->GetPointer();
    uint32_t    out_index     = *index->GetOutputPointer();

    auto& swapchain_data = GetSwapchainData(in_swapchain);
    replay_result        = swapchain_data.AcquireSwapchainImage(capture_index, out_index);
}

void OpenXrReplayConsumerBase::Process_xrReleaseSwapchainImage(
    const ApiCallInfo&                                         call_info,
    XrResult                                                   returnValue,
    format::HandleId                                           swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo)
{
    XrSwapchain in_swapchain = MapHandle<OpenXrSwapchainInfo>(swapchain, &CommonObjectInfoTable::GetXrSwapchainInfo);
    const XrSwapchainImageReleaseInfo* in_releaseInfo = releaseInfo->GetPointer();

    auto& swapchain_data = GetSwapchainData(in_swapchain);
    swapchain_data.ReleaseSwapchainImage(releaseInfo);

    XrResult replay_result = GetInstanceTable(in_swapchain)->ReleaseSwapchainImage(in_swapchain, in_releaseInfo);
    CheckResult("xrReleaseSwapchainImage", returnValue, replay_result, call_info);
}

void OpenXrReplayConsumerBase::ProcessViewRelativeLocation(format::ThreadId              thread_id,
                                                           format::ViewRelativeLocation& location)
{
    // Create a proxy space for a given space_id at a view relative location
    XrSession replay_session =
        MapHandle<OpenXrSessionInfo>(location.session_id, &CommonObjectInfoTable::GetXrSessionInfo);
    XrSpace replay_space = MapHandle<OpenXrSpaceInfo>(location.space_id, &CommonObjectInfoTable::GetXrSpaceInfo);
    assert(replay_session != XR_NULL_HANDLE);
    assert(replay_space != XR_NULL_HANDLE);
    auto& session_data = GetSessionData(replay_session);
    session_data.AddViewRelativeProxySpace(GetInstanceTable(replay_session), location, replay_space);
}

void OpenXrReplayConsumerBase::Process_xrEndFrame(const ApiCallInfo&                            call_info,
                                                  XrResult                                      returnValue,
                                                  format::HandleId                              session,
                                                  StructPointerDecoder<Decoded_XrFrameEndInfo>* frameEndInfo)
{
    XrSession             in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrFrameEndInfo* in_frameEndInfo = frameEndInfo->GetPointer();
    MapStructHandles(frameEndInfo->GetMetaStructPointer(), GetObjectInfoTable());

    XrFrameEndInfo replay_frame_end_info = *in_frameEndInfo;
    SessionData&   session_data          = GetSessionData(in_session);

    // The display time must be based on the time given by the runtime at replay time, as the recorded diplayTime
    // may not be a valid time at replay.
    //
    // A first approximation of this is simply using the XrFrameState::predictedDisplayTime
    //
    // NOTE: A closer approximation of the capture would be having the displayTime be at the same offset of
    // the replay predictedDisplayTime, as the recorded displayTime has from the recorded predictedDisplayTime.
    replay_frame_end_info.displayTime = session_data.GetDisplayTime();

    // TODO: Control this with a command line parameter
    session_data.RemapFrameEndSpaces(replay_frame_end_info);

    XrResult replay_result = GetInstanceTable(in_session)->EndFrame(in_session, &replay_frame_end_info);
    CheckResult("xrEndFrame", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEndFrame>::UpdateState(
        this, call_info, returnValue, session, frameEndInfo, replay_result);
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

void OpenXrReplayConsumerBase::Process_xrLocateSpaces(const ApiCallInfo&                                call_info,
                                                      XrResult                                          returnValue,
                                                      format::HandleId                                  session,
                                                      StructPointerDecoder<Decoded_XrSpacesLocateInfo>* locateInfo,
                                                      StructPointerDecoder<Decoded_XrSpaceLocations>*   spaceLocations)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpacesLocateInfo* in_locateInfo = locateInfo->GetPointer();
    MapStructHandles(locateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrSpaceLocations* out_spaceLocations =
        spaceLocations->IsNull() ? nullptr
                                 : spaceLocations->AllocateOutputData(1, { XR_TYPE_SPACE_LOCATIONS, nullptr });
    InitializeOutputStructNext(spaceLocations);

    // We have to create allocated space for the space location data to be written to, otherwise,
    // it will try to write  to a non-existent output location.
    if (out_spaceLocations != nullptr)
    {
        XrSpaceLocations*         in_spaceLocations   = spaceLocations->GetPointer();
        Decoded_XrSpaceLocations* meta_spaceLocations = spaceLocations->GetMetaStructPointer();

        out_spaceLocations->locationCount = in_spaceLocations->locationCount;
        out_spaceLocations->locations     = nullptr;
        if (in_spaceLocations->locationCount > 0 && in_spaceLocations->locations != nullptr)
        {
            out_spaceLocations->locations =
                meta_spaceLocations->locations->AllocateOutputData(out_spaceLocations->locationCount);
        }
    }

    XrResult replay_result = GetInstanceTable(in_session)->LocateSpaces(in_session, in_locateInfo, out_spaceLocations);
    CheckResult("xrLocateSpaces", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrLocateSpaces>::UpdateState(
        this, call_info, returnValue, session, locateInfo, spaceLocations, replay_result);
}

void OpenXrReplayConsumerBase::Process_xrLocateHandJointsEXT(
    const ApiCallInfo&                                       call_info,
    XrResult                                                 returnValue,
    format::HandleId                                         handTracker,
    StructPointerDecoder<Decoded_XrHandJointsLocateInfoEXT>* locateInfo,
    StructPointerDecoder<Decoded_XrHandJointLocationsEXT>*   locations)
{
    XrHandTrackerEXT in_handTracker =
        MapHandle<OpenXrHandTrackerEXTInfo>(handTracker, &CommonObjectInfoTable::GetXrHandTrackerEXTInfo);
    const XrHandJointsLocateInfoEXT* in_locateInfo = locateInfo->GetPointer();
    MapStructHandles(locateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrHandJointLocationsEXT* out_locations =
        locations->IsNull() ? nullptr : locations->AllocateOutputData(1, { XR_TYPE_HAND_JOINT_LOCATIONS_EXT, nullptr });
    InitializeOutputStructNext(locations);

    // We have to create allocated space for the joint data to be written to, otherwise,
    // it will try to write  to a non-existent output location.
    if (out_locations != nullptr)
    {
        XrHandJointLocationsEXT*         in_locations   = locations->GetPointer();
        Decoded_XrHandJointLocationsEXT* meta_locations = locations->GetMetaStructPointer();

        out_locations->jointCount     = in_locations->jointCount;
        out_locations->jointLocations = nullptr;
        if (in_locations->jointCount > 0 && in_locations->jointLocations != nullptr)
        {
            out_locations->jointLocations =
                meta_locations->jointLocations->AllocateOutputData(out_locations->jointCount);
        }
    }

    XrResult replay_result =
        GetInstanceTable(in_handTracker)->LocateHandJointsEXT(in_handTracker, in_locateInfo, out_locations);
    CheckResult("xrLocateHandJointsEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrLocateHandJointsEXT>::UpdateState(
        this, call_info, returnValue, handTracker, locateInfo, locations, replay_result);
}

void OpenXrReplayConsumerBase::Process_xrGetHandMeshFB(const ApiCallInfo&                                  call_info,
                                                       XrResult                                            returnValue,
                                                       format::HandleId                                    handTracker,
                                                       StructPointerDecoder<Decoded_XrHandTrackingMeshFB>* mesh)
{
    XrHandTrackerEXT in_handTracker =
        MapHandle<OpenXrHandTrackerEXTInfo>(handTracker, &CommonObjectInfoTable::GetXrHandTrackerEXTInfo);
    XrHandTrackingMeshFB* out_mesh =
        mesh->IsNull() ? nullptr : mesh->AllocateOutputData(1, { XR_TYPE_HAND_TRACKING_MESH_FB, nullptr });
    InitializeOutputStructNext(mesh);

    // We have to create allocated space for the mesh data to be written to, otherwise,
    // it will try to write  to a non-existent output location.
    if (out_mesh != nullptr)
    {
        XrHandTrackingMeshFB*         in_mesh   = mesh->GetPointer();
        Decoded_XrHandTrackingMeshFB* meta_mesh = mesh->GetMetaStructPointer();

        out_mesh->jointCapacityInput = in_mesh->jointCapacityInput;
        out_mesh->jointBindPoses     = nullptr;
        out_mesh->jointRadii         = nullptr;
        out_mesh->jointParents       = nullptr;
        if (in_mesh->jointCapacityInput > 0)
        {
            if (in_mesh->jointBindPoses != nullptr)
            {
                out_mesh->jointBindPoses = meta_mesh->jointBindPoses->AllocateOutputData(out_mesh->jointCapacityInput);
            }
            if (in_mesh->jointRadii != nullptr)
            {
                out_mesh->jointRadii = meta_mesh->jointRadii.AllocateOutputData(out_mesh->jointCapacityInput);
            }
            if (in_mesh->jointParents != nullptr)
            {
                out_mesh->jointParents = meta_mesh->jointParents.AllocateOutputData(out_mesh->jointCapacityInput);
            }
        }

        out_mesh->vertexCapacityInput = in_mesh->vertexCapacityInput;
        out_mesh->vertexPositions     = nullptr;
        out_mesh->vertexNormals       = nullptr;
        out_mesh->vertexUVs           = nullptr;
        out_mesh->vertexBlendIndices  = nullptr;
        out_mesh->vertexBlendWeights  = nullptr;
        if (in_mesh->vertexCapacityInput > 0)
        {
            if (in_mesh->vertexPositions != nullptr)
            {
                out_mesh->vertexPositions =
                    meta_mesh->vertexPositions->AllocateOutputData(out_mesh->vertexCapacityInput);
            }
            if (in_mesh->vertexNormals != nullptr)
            {
                out_mesh->vertexNormals = meta_mesh->vertexNormals->AllocateOutputData(out_mesh->vertexCapacityInput);
            }
            if (in_mesh->vertexUVs != nullptr)
            {
                out_mesh->vertexUVs = meta_mesh->vertexUVs->AllocateOutputData(out_mesh->vertexCapacityInput);
            }
            if (in_mesh->vertexBlendIndices != nullptr)
            {
                out_mesh->vertexBlendIndices =
                    meta_mesh->vertexBlendIndices->AllocateOutputData(out_mesh->vertexCapacityInput);
            }
            if (in_mesh->vertexBlendWeights != nullptr)
            {
                out_mesh->vertexBlendWeights =
                    meta_mesh->vertexBlendWeights->AllocateOutputData(out_mesh->vertexCapacityInput);
            }
        }

        out_mesh->indexCapacityInput = in_mesh->indexCapacityInput;
        out_mesh->indices            = nullptr;
        if (in_mesh->indexCapacityInput > 0 && in_mesh->indices != nullptr)
        {
            out_mesh->indices = meta_mesh->indices.AllocateOutputData(out_mesh->indexCapacityInput, 0);
        }
    }

    XrResult replay_result = GetInstanceTable(in_handTracker)->GetHandMeshFB(in_handTracker, out_mesh);
    CheckResult("xrGetHandMeshFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetHandMeshFB>::UpdateState(
        this, call_info, returnValue, handTracker, mesh, replay_result);
}

void OpenXrReplayConsumerBase::Process_xrLocateBodyJointsFB(
    const ApiCallInfo&                                      call_info,
    XrResult                                                returnValue,
    format::HandleId                                        bodyTracker,
    StructPointerDecoder<Decoded_XrBodyJointsLocateInfoFB>* locateInfo,
    StructPointerDecoder<Decoded_XrBodyJointLocationsFB>*   locations)
{
    XrBodyTrackerFB in_bodyTracker =
        MapHandle<OpenXrBodyTrackerFBInfo>(bodyTracker, &CommonObjectInfoTable::GetXrBodyTrackerFBInfo);
    const XrBodyJointsLocateInfoFB* in_locateInfo = locateInfo->GetPointer();
    MapStructHandles(locateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrBodyJointLocationsFB* out_locations =
        locations->IsNull() ? nullptr : locations->AllocateOutputData(1, { XR_TYPE_BODY_JOINT_LOCATIONS_FB, nullptr });
    InitializeOutputStructNext(locations);

    // We have to create allocated space for the joint data to be written to, otherwise,
    // it will try to write  to a non-existent output location.
    if (out_locations != nullptr)
    {
        XrBodyJointLocationsFB*         in_locations   = locations->GetPointer();
        Decoded_XrBodyJointLocationsFB* meta_locations = locations->GetMetaStructPointer();

        out_locations->jointCount     = in_locations->jointCount;
        out_locations->jointLocations = nullptr;
        if (in_locations->jointCount > 0 && in_locations->jointLocations != nullptr)
        {
            out_locations->jointLocations =
                meta_locations->jointLocations->AllocateOutputData(out_locations->jointCount);
        }
    }

    XrResult replay_result =
        GetInstanceTable(in_bodyTracker)->LocateBodyJointsFB(in_bodyTracker, in_locateInfo, out_locations);
    CheckResult("xrLocateBodyJointsFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrLocateBodyJointsFB>::UpdateState(
        this, call_info, returnValue, bodyTracker, locateInfo, locations, replay_result);
}

void OpenXrReplayConsumerBase::CheckResult(const char*                func_name,
                                           XrResult                   original,
                                           XrResult                   replay,
                                           const decode::ApiCallInfo& call_info,
                                           bool                       assert_on_error)
{
    if (original != replay)
    {
        if (replay < 0)
        {
            if (assert_on_error)
            {
                // Raise a fatal error if replay produced an error that did not occur during capture.  Format not
                // supported errors are not treated as fatal, but will be reported as warnings below, allowing the
                // replay to attempt to continue for the case where an application may have queried for formats that it
                // did not use.
                GFXRECON_LOG_FATAL("API call at index: %d thread: %d %s returned error value %s that does not match "
                                   "the result from the "
                                   "capture file: %s. Replay cannot continue.",
                                   call_info.index,
                                   call_info.thread_id,
                                   func_name,
                                   util::ToString<XrResult>(replay).c_str(),
                                   util::ToString<XrResult>(original).c_str());

                RaiseFatalError(enumutil::GetResultDescription(replay));
            }
            else
            {
                GFXRECON_LOG_ERROR("API call at index: %d thread: %d %s returned error value %s that does not match "
                                   "the result from the capture file: %s.",
                                   call_info.index,
                                   call_info.thread_id,
                                   func_name,
                                   util::ToString<XrResult>(replay).c_str(),
                                   util::ToString<XrResult>(original).c_str());
            }
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
void OpenXrReplayConsumerBase::SwapchainData::InitSwapchainData(const GraphicsBinding&       binding,
                                                                const XrSwapchainCreateInfo& info,
                                                                XrSwapchain                  replay_handle)
{
    // Save off a reference to the session's graphics binding information
    graphics_binding_ = &binding;

    // Store off a shallow copy
    create_info      = info;
    create_info.next = nullptr; // Add supported deep copies below

    replay_handle_ = replay_handle;
    if (binding.IsVulkan())
    {
        // The type of the swapchain must match the type of the session
        swapchain_graphics_info_.type = GraphicsBindingType::kVulkan;
        swapchain_graphics_info_.vulkan_info.emplace();
        InitSwapchainData(info, *swapchain_graphics_info_.vulkan_info);
    }
    else
    {
        // WIP: Properly log and handle this
        // WIP: For now catch this to ensure we don't need support
        GFXRECON_LOG_FATAL("Unsupported graphics binding");
    }
}

XrResult OpenXrReplayConsumerBase::SwapchainData::ImportReplaySwapchain(
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images)
{
    XrResult                    result             = XR_SUCCESS;
    XrSwapchainImageBaseHeader* replay_images      = images->GetOutputPointer();
    size_t                      replay_image_count = images->GetOutputLength();

    if (replay_image_count == 0)
    {
        return result;
    }
    assert(replay_images);

    if (graphics_binding_->IsVulkan())
    {
        XrSwapchainImageVulkanKHR* vk_images = reinterpret_cast<XrSwapchainImageVulkanKHR*>(replay_images);
        assert(vk_images->type == XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR);
        assert(swapchain_graphics_info_.vulkan_info.has_value());
        VulkanSwapchainInfo& vk_info = *swapchain_graphics_info_.vulkan_info;
        vk_info.replay_images = std::vector<XrSwapchainImageVulkanKHR>(vk_images, vk_images + replay_image_count);
    }
    else
    {
        result = XR_ERROR_RUNTIME_FAILURE; // Our version of replay can't handle any other binding than those above
    }

    return result;
}

XrResult OpenXrReplayConsumerBase::SwapchainData::InitVirtualSwapchain(
    PointerDecoder<uint32_t>*                                 imageCountOutput,
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* capture_images)
{
    // This call is invalid without a Session with a graphics binding specified
    assert(graphics_binding_);

    XrResult result = XR_ERROR_API_VERSION_UNSUPPORTED; // WIP: Determine if there is a better code for this

    if (graphics_binding_->IsVulkan())
    {
        auto* vk_capture_images =
            reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageVulkanKHR>*>(capture_images);
        result = InitVirtualSwapchain(imageCountOutput, vk_capture_images);
    }
    else
    {
        // This call is only supported for Vulkan graphics bindings
        // WIP: Properly log and handle this
        GFXRECON_LOG_FATAL("Unsupported graphics binding");
        return XR_ERROR_RUNTIME_FAILURE;
    }
    return result;
}

XrResult OpenXrReplayConsumerBase::SwapchainData::InitVirtualSwapchain(
    PointerDecoder<uint32_t>* imageCountOutput, StructPointerDecoder<Decoded_XrSwapchainImageVulkanKHR>* capture_images)
{

    // Unpack the graphics binding info, we shouldn't be called unless the binding *is* Vulkan
    assert(graphics_binding_->IsVulkan());

    XrResult xr_result = XR_SUCCESS; // WIP: Determine if there is a better code for this

    const VulkanGraphicsBinding& vk_binding     = graphics_binding_->GetVulkanBinding();
    const VkDevice               vk_device      = vk_binding.device;
    const format::HandleId       device_id      = vk_binding.device_id;
    const VkPhysicalDevice       vk_physical    = vk_binding.physicalDevice;
    auto*                        device_table   = vk_binding.device_table;
    auto*                        instance_table = vk_binding.instance_table;

    assert(swapchain_graphics_info_.vulkan_info.has_value());
    VulkanSwapchainInfo& vk_swap = *swapchain_graphics_info_.vulkan_info;

    // Allocate command buffers
    VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
                                            nullptr,
                                            VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
                                            vk_binding.queueFamilyIndex };

    VkResult vk_result = device_table->CreateCommandPool(vk_device, &create_info, nullptr, &vk_swap.command_pool);
    // WIP: Properly log and handle this
    assert(vk_result == VK_SUCCESS);

    vk_swap.transfer_commandbuffer.resize(vk_swap.replay_images.size());
    VkCommandBufferAllocateInfo cb_alloc_info = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        nullptr,
        vk_swap.command_pool,
        VK_COMMAND_BUFFER_LEVEL_PRIMARY,
        1,
    };

    VkFenceCreateInfo cb_fence_info = {
        VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
        nullptr,
        VK_FENCE_CREATE_SIGNALED_BIT // The first thing we do is wait on the signal
    };

    // Create the virtual images
    uint32_t* output_count = imageCountOutput->GetPointer();
    assert(output_count);

    const Decoded_XrSwapchainImageVulkanKHR* wrappers = capture_images->GetMetaStructPointer();

    VulkanSwapchainInfo::ProxyImage proxy;

    vk_swap.proxy_images.reserve(*output_count);

    for (uint32_t image_entry = 0; image_entry < *output_count; image_entry++)
    {
        const format::HandleId& image_id = wrappers[image_entry].image;

        vk_result = device_table->CreateImage(vk_device, &vk_swap.image_create_info, nullptr, &proxy.image);
        // WIP: Properly log and handle this
        assert(vk_result == VK_SUCCESS);

        VkMemoryRequirements memory_reqs{};
        device_table->GetImageMemoryRequirements(vk_device, proxy.image, &memory_reqs);

        VkMemoryPropertyFlags property_flags    = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
        uint32_t              memory_type_index = std::numeric_limits<uint32_t>::max();
        {
            VkPhysicalDeviceMemoryProperties properties;
            instance_table->GetPhysicalDeviceMemoryProperties(vk_physical, &properties);

            for (uint32_t i = 0; i < properties.memoryTypeCount; i++)
            {
                if ((memory_reqs.memoryTypeBits & (1 << i)) &&
                    ((properties.memoryTypes[i].propertyFlags & property_flags) != 0))
                {
                    memory_type_index = i;
                    break;
                }
            }
            assert(memory_type_index != std::numeric_limits<uint32_t>::max());
        }

        if (memory_type_index == std::numeric_limits<uint32_t>::max())
        {
            // WIP: Properly log and handle this
            break;
        }

        VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
        alloc_info.pNext                = nullptr;
        alloc_info.memoryTypeIndex      = memory_type_index;
        alloc_info.allocationSize       = memory_reqs.size;

        vk_result = device_table->AllocateMemory(vk_device, &alloc_info, nullptr, &proxy.memory);

        if (vk_result != VK_SUCCESS)
        {
            // WIP: Properly log and handle this
            break;
        }

        vk_result = device_table->BindImageMemory(vk_device, proxy.image, proxy.memory, 0);

        if (vk_result != VK_SUCCESS)
        {
            // WIP: Properly log and handle this
            break;
        }

        vk_result = device_table->AllocateCommandBuffers(vk_device, &cb_alloc_info, &proxy.command_buffer);
        if (vk_result != VK_SUCCESS)
        {
            // WIP: Properly log and handle this
            break;
        }

        vk_result = device_table->CreateFence(vk_device, &cb_fence_info, nullptr, &proxy.cb_fence);
        if (vk_result != VK_SUCCESS)
        {
            // WIP: Properly log and handle this
            break;
        }

        // Now tell the Vulkan Consumer to map the proxy image to the matching captured image id
        VulkanImageInfo handle_info;
        handle_info.handle             = proxy.image;
        handle_info.memory             = proxy.memory;
        handle_info.is_swapchain_image = true;
        vk_binding.vulkan_consumer->AddImageHandle(device_id, image_id, proxy.image, std::move(handle_info));

        vk_swap.proxy_images.emplace_back(proxy);

        // Safe the unwind on sucess
        proxy = VulkanSwapchainInfo::ProxyImage();
    }

    if (vk_result != VK_SUCCESS)
    {
        xr_result = XR_ERROR_VALIDATION_FAILURE; // WIP: Determine if there is a better code for this
    }

    // If we failed above, need to unwind any work in progress.
    // WIP: Decide what to do about partial swapchain construction
    if (proxy.memory != VK_NULL_HANDLE)
    {
        device_table->FreeMemory(vk_device, proxy.memory, nullptr);
    }

    if (proxy.image != VK_NULL_HANDLE)
    {
        device_table->DestroyImage(vk_device, proxy.image, nullptr);
    }

    if (proxy.command_buffer != VK_NULL_HANDLE)
    {
        device_table->DestroyFence(vk_device, proxy.cb_fence, nullptr);
    }

    if (proxy.command_buffer != VK_NULL_HANDLE)
    {
        device_table->FreeCommandBuffers(vk_device, vk_swap.command_pool, 1, &proxy.command_buffer);
    }

    return xr_result;
}

XrResult OpenXrReplayConsumerBase::SwapchainData::AcquireSwapchainImage(uint32_t capture_index, uint32_t replay_index)
{
    capture_to_replay_map_[capture_index] = replay_index;
    acquire_release_fifo_.push_front(capture_index);

    if (graphics_binding_->IsVulkan())
    {
        return AcquireSwapchainImage(capture_index, replay_index, *swapchain_graphics_info_.vulkan_info);
    }

    // WIP: Properly log and handle this
    GFXRECON_LOG_FATAL("Unsupported graphics binding");
    return XR_ERROR_VALIDATION_FAILURE;
}

XrResult OpenXrReplayConsumerBase::SwapchainData::ReleaseSwapchainImage(
    StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo)
{
    XrResult xr_result = XR_SUCCESS;

    if (graphics_binding_->IsVulkan())
    {
        return ReleaseSwapchainImage(releaseInfo, *swapchain_graphics_info_.vulkan_info);
    }

    // WIP: Properly log and handle this
    GFXRECON_LOG_FATAL("Unsupported graphics binding");
    return XR_ERROR_VALIDATION_FAILURE;
}

void OpenXrReplayConsumerBase::SwapchainData::WaitedWithoutTimeout()
{
    // WIP: Do we need to track anything here?
    // The calling order will be enforced by the runtime at replay time, and if the application
    // didn't handle XR_TIMEOUT correctly, that's an invalid trace, which the replay runtime may respond poorly
    // to, but it's unsure whether we can do anything about it.
}

XrResult OpenXrReplayConsumerBase::SwapchainData::AcquireSwapchainImage(uint32_t             capture_index,
                                                                        uint32_t             replay_index,
                                                                        VulkanSwapchainInfo& swap)
{
    // Unpack the graphics binding info, we shouldn't be called unless the binding *is* Vulkan
    assert(graphics_binding_->IsVulkan());

    XrResult xr_result = XR_SUCCESS; // WIP: Determine if there is a better code for this

    const VulkanGraphicsBinding& vk_binding   = graphics_binding_->GetVulkanBinding();
    const VkDevice               vk_device    = vk_binding.device;
    auto*                        device_table = vk_binding.device_table;

    VulkanSwapchainInfo::ProxyImage& proxy = swap.proxy_images[capture_index];
    xr_result                              = vk_binding.ResetCommandBuffer(proxy);
    if (!XR_SUCCEEDED(xr_result))
    {
        assert(XR_SUCCEEDED(xr_result));
        return xr_result;
    }

    VkCommandBufferBeginInfo cb_begin = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr
    };

    VkImageMemoryBarrier barrier = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
                                     nullptr,
                                     VK_ACCESS_MEMORY_READ_BIT |
                                         VK_ACCESS_MEMORY_WRITE_BIT, // WIP: Determine the optimal set of accesses
                                     VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT,
                                     VK_IMAGE_LAYOUT_UNDEFINED,
                                     swap.layout,
                                     VK_QUEUE_FAMILY_IGNORED,
                                     VK_QUEUE_FAMILY_IGNORED,
                                     proxy.image,
                                     swap.whole_range };

    VkResult vk_result = device_table->BeginCommandBuffer(proxy.command_buffer, &cb_begin);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    device_table->CmdPipelineBarrier(proxy.command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &barrier);
    vk_result = device_table->EndCommandBuffer(proxy.command_buffer);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    VkSubmitInfo submit_info = { VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr, 0,      nullptr, nullptr, 1,
                                 &proxy.command_buffer,         0,       nullptr };
    vk_result                = device_table->QueueSubmit(vk_binding.queue, 1, &submit_info, proxy.cb_fence);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    return XR_SUCCESS;
}

XrResult OpenXrReplayConsumerBase::SwapchainData::ReleaseSwapchainImage(
    StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo, VulkanSwapchainInfo& vk_swap)
{

    // Unpack the graphics binding info, we shouldn't be called unless the binding *is* Vulkan
    assert(graphics_binding_->IsVulkan());

    XrResult xr_result = XR_SUCCESS; // WIP: Determine if there is a better code for this

    const VulkanGraphicsBinding& vk_binding     = graphics_binding_->GetVulkanBinding();
    const VkDevice               vk_device      = vk_binding.device;
    const format::HandleId       device_id      = vk_binding.device_id;
    const VkPhysicalDevice       vk_physical    = vk_binding.physicalDevice;
    auto*                        device_table   = vk_binding.device_table;
    auto*                        instance_table = vk_binding.instance_table;

    // Copy the head of the AcquireRelease FIFO from the proxy image to the replay image
    assert(!acquire_release_fifo_.empty());
    uint32_t capture_index = acquire_release_fifo_.back();
    acquire_release_fifo_.pop_back();
    auto replay_it = capture_to_replay_map_.find(capture_index);
    assert(replay_it != capture_to_replay_map_.end());
    uint32_t replay_index = replay_it->second;
    VkImage  replay_image = vk_swap.replay_images[replay_index].image;
    capture_to_replay_map_.erase(replay_it);

    VulkanSwapchainInfo::ProxyImage& proxy = vk_swap.proxy_images[capture_index];
    xr_result                              = vk_binding.ResetCommandBuffer(proxy);
    assert(XR_SUCCEEDED(xr_result));

    VkCommandBufferBeginInfo cb_begin = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr
    };

    VkImageMemoryBarrier barriers[2] = {
        { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
          nullptr,
          VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT, // WIP: Determine the optimal set of accesses
          VK_ACCESS_TRANSFER_READ_BIT,
          vk_swap.layout,
          VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
          VK_QUEUE_FAMILY_IGNORED,
          VK_QUEUE_FAMILY_IGNORED,
          proxy.image,
          vk_swap.whole_range },
        { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
          nullptr,
          VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT, // WIP: Determine the optimal set of accesses
          VK_ACCESS_TRANSFER_WRITE_BIT,
          vk_swap.layout,
          VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
          VK_QUEUE_FAMILY_IGNORED,
          VK_QUEUE_FAMILY_IGNORED,
          replay_image,
          vk_swap.whole_range }

    };

    VkResult vk_result = device_table->BeginCommandBuffer(proxy.command_buffer, &cb_begin);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    device_table->CmdPipelineBarrier(proxy.command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     2,
                                     barriers);

    VkImageSubresourceLayers subres_layers = {
        vk_swap.whole_range.aspectMask, 0, vk_swap.whole_range.baseArrayLayer, vk_swap.whole_range.layerCount
    };
    VkOffset3D zero_offset = { 0, 0, 0 };
    VkExtent3D mip_extent  = vk_swap.image_create_info.extent;

    VkImageCopy copy_region = {
        subres_layers, zero_offset, subres_layers, zero_offset, vk_swap.image_create_info.extent
    };

    uint32_t                 mip_count = vk_swap.image_create_info.mipLevels;
    std::vector<VkImageCopy> copy_regions;
    copy_regions.reserve(mip_count);
    for (uint32_t mip_level = 0; mip_level < mip_count; mip_level++)
    {
        subres_layers.mipLevel = mip_level;

        VkExtent3D mip_extent = vk_swap.image_create_info.extent;
        mip_extent.width >>= mip_level;
        mip_extent.height >>= mip_level;

        VkImageCopy copy_region = { subres_layers, zero_offset, subres_layers, zero_offset, mip_extent };
        copy_regions.push_back(copy_region);
    }

    device_table->CmdCopyImage(proxy.command_buffer,
                               proxy.image,
                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                               replay_image,
                               VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                               mip_count,
                               copy_regions.data());

    // Transition replay to the required layout
    // We'll defer the proxy image transition until the next acquire
    barriers[1].oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    barriers[1].newLayout     = vk_swap.layout;
    barriers[1].srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    barriers[1].dstAccessMask =
        VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT; // WIP: Determine the optimal set of accesses

    device_table->CmdPipelineBarrier(proxy.command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &barriers[1]);
    vk_result = device_table->EndCommandBuffer(proxy.command_buffer);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    VkSubmitInfo submit_info = { VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr, 0,      nullptr, nullptr, 1,
                                 &proxy.command_buffer,         0,       nullptr };
    vk_result                = device_table->QueueSubmit(vk_binding.queue, 1, &submit_info, proxy.cb_fence);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    return XR_SUCCESS;
}

void OpenXrReplayConsumerBase::SwapchainData::MapVulkanSwapchainImageFlags(XrSwapchainUsageFlags xr_flags,
                                                                           VkImageCreateInfo&    info)
{
    // NOTE: This is Vulkan specific.
    struct ImageUsageMap
    {
        XrSwapchainUsageFlags xr;
        VkImageUsageFlagBits  vk;
    };
    struct ImageCreateMap
    {
        XrSwapchainUsageFlags xr;
        VkImageCreateFlagBits vk;
    };
    static std::array<ImageUsageMap, 7> usage_map = {
        { { XR_SWAPCHAIN_USAGE_COLOR_ATTACHMENT_BIT, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT },
          { XR_SWAPCHAIN_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT },
          { XR_SWAPCHAIN_USAGE_UNORDERED_ACCESS_BIT, VK_IMAGE_USAGE_STORAGE_BIT },
          { XR_SWAPCHAIN_USAGE_TRANSFER_SRC_BIT, VK_IMAGE_USAGE_TRANSFER_SRC_BIT },
          { XR_SWAPCHAIN_USAGE_TRANSFER_DST_BIT, VK_IMAGE_USAGE_TRANSFER_DST_BIT },
          { XR_SWAPCHAIN_USAGE_SAMPLED_BIT, VK_IMAGE_USAGE_SAMPLED_BIT },
          { XR_SWAPCHAIN_USAGE_INPUT_ATTACHMENT_BIT_KHR, VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT } }
    };
    static std::array<ImageCreateMap, 1> create_map = { {
        { XR_SWAPCHAIN_USAGE_MUTABLE_FORMAT_BIT, VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT },
    } };

    XrSwapchainUsageFlags mapped_flags = 0;
    for (const auto& entry : usage_map)
    {
        if (entry.xr & xr_flags)
        {
            info.usage |= entry.vk;
            mapped_flags |= entry.xr;
        }
    }
    for (const auto& entry : create_map)
    {
        if (entry.xr & xr_flags)
        {
            info.flags |= entry.vk;
            mapped_flags |= entry.xr;
        }
    }
    // WIP: Properly log and handle this
    assert(xr_flags == mapped_flags);
}

XrResult OpenXrReplayConsumerBase::SwapchainData::InitSwapchainData(const XrSwapchainCreateInfo& xr_info,
                                                                    VulkanSwapchainInfo&         vk_swap)
{
    XrResult xr_result = XR_SUCCESS; // WIP: Determine if there is a better code for this

    // Set up the flags and usages
    VkImageCreateInfo& image_create_info = vk_swap.image_create_info;
    image_create_info                    = VkImageCreateInfo{ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO, nullptr };

    MapVulkanSwapchainImageFlags(xr_info.usageFlags, image_create_info);

    // Grab supported extension structs
    auto xr_info_meta = gfxrecon::util::GetNextOfType<XrVulkanSwapchainCreateInfoMETA>(xr_info.next);
    if (xr_info_meta)
    {
        // Apply the extension information
        image_create_info.usage |= xr_info_meta->additionalUsageFlags;
        image_create_info.flags |= xr_info_meta->additionalCreateFlags;

        // Backing store for the deep copy is within the VulkanSwapchainInfo
        vk_swap.xr_info_meta      = *xr_info_meta;
        vk_swap.xr_info_meta.next = nullptr;
        create_info.next          = &vk_swap.xr_info_meta;
    }

    // Need to be able to copy to the real swapchain
    image_create_info.usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;

    // Cube swapchains specific flags
    if (xr_info.faceCount == 6)
    {
        image_create_info.flags |= VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT;
    }

    // And the reset of the create info
    image_create_info.imageType = VK_IMAGE_TYPE_2D;
    image_create_info.format    = static_cast<VkFormat>(xr_info.format);
    VkExtent3D& extent          = image_create_info.extent;
    extent.width                = xr_info.width;
    extent.height               = xr_info.height;
    extent.depth                = 1U;
    image_create_info.mipLevels = xr_info.mipCount;

    // NOTE: Not sure if these are in face major or array major order, but shouldn't matter
    //       to replay unless runtimes vary.
    image_create_info.arrayLayers = xr_info.arraySize * xr_info.faceCount,

    image_create_info.samples = VK_SAMPLE_COUNT_1_BIT;
    image_create_info.tiling  = VK_IMAGE_TILING_OPTIMAL;

    image_create_info.sharingMode   = VK_SHARING_MODE_EXCLUSIVE;
    image_create_info.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;

    VkImageSubresourceRange& subres_range = vk_swap.whole_range;
    subres_range.aspectMask               = 0;
    subres_range.aspectMask |= vkuFormatHasDepth(image_create_info.format) ? VK_IMAGE_ASPECT_DEPTH_BIT : 0;
    subres_range.aspectMask |= vkuFormatHasStencil(image_create_info.format) ? VK_IMAGE_ASPECT_STENCIL_BIT : 0;

    if (subres_range.aspectMask)
    {
        vk_swap.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
    }
    else if (vkuFormatIsColor(image_create_info.format))
    {
        subres_range.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        vk_swap.layout          = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    }
    else
    {
        // WIP: Properly log and handle this
        assert(subres_range.aspectMask);
        vk_swap.layout = VK_IMAGE_LAYOUT_UNDEFINED;
    }

    subres_range.baseMipLevel   = 0;
    subres_range.levelCount     = image_create_info.mipLevels;
    subres_range.baseArrayLayer = 0;
    subres_range.layerCount     = image_create_info.arrayLayers;

    return xr_result;
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

XrResult
OpenXrReplayConsumerBase::VulkanGraphicsBinding::ResetCommandBuffer(VulkanSwapchainInfo::ProxyImage& proxy) const
{
    XrResult xr_result = XR_SUCCESS;
    uint32_t kTimeout  = std::numeric_limits<uint32_t>::max(); // WIP: Better timeout and timeout reporting
    VkResult vk_result = device_table->WaitForFences(device, 1, &proxy.cb_fence, VK_TRUE, kTimeout);

    if (vk_result != VK_SUCCESS)
    {
        xr_result = XR_ERROR_RUNTIME_FAILURE;

        // WIP: Properly log and handle this
        assert(xr_result == XR_SUCCESS);
    }

    // Create and submit the ILT need to for
    device_table->ResetFences(device, 1, &proxy.cb_fence);
    return xr_result;
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

void OpenXrReplayConsumerBase::SessionData::AddViewRelativeProxySpace(const encode::OpenXrInstanceTable* instance_table,
                                                                      const format::ViewRelativeLocation& location,
                                                                      const XrSpace                       replay_space)
{

    // View space at view relative location
    XrReferenceSpaceCreateInfo view_relative_ci = { XR_TYPE_REFERENCE_SPACE_CREATE_INFO,
                                                    nullptr,
                                                    XR_REFERENCE_SPACE_TYPE_VIEW,
                                                    { { location.qx, location.qy, location.qz, location.qw },
                                                      { location.x, location.y, location.z } } };

    XrSpace view_relative_space = XR_NULL_HANDLE;
    // TODO: Cleanup this reference space object at DestroySession time
    XrResult result = instance_table->CreateReferenceSpace(session_, &view_relative_ci, &view_relative_space);

    if (XR_SUCCEEDED(result))
    {
        proxy_spaces_[replay_space] = view_relative_space;
    }
    else
    {
        GFXRECON_LOG_WARNING("Unable to create view relative space for  %" PRIu64, location.space_id);
    }
}

void OpenXrReplayConsumerBase::SessionData::ClearViewRelativeProxySpaces(
    const encode::OpenXrInstanceTable* instance_table)
{
    assert(instance_table);
    for (const auto& proxy : proxy_spaces_)
    {
        if (proxy.second != XR_NULL_HANDLE)
        {
            instance_table->DestroySpace(proxy.second);
        }
    }
    proxy_spaces_.clear();
}

void OpenXrReplayConsumerBase::SessionData::RemapFrameEndSpaces(XrFrameEndInfo& frame_end_info)
{
    const XrCompositionLayerBaseHeader* const* layers = frame_end_info.layers;
    if (!layers)
        return;

    // Replace all spaces in the composition layer with view relative proxies
    for (uint32_t layer_index = 0; layer_index < frame_end_info.layerCount; layer_index++)
    {
        XrCompositionLayerBaseHeader* layer = const_cast<XrCompositionLayerBaseHeader*>(layers[layer_index]);
        if (layer && (layer->space != XR_NULL_HANDLE))
        {
            auto found_it = proxy_spaces_.find(layer->space);
            if (found_it != proxy_spaces_.end())
            {
                layer->space = found_it->second;
            }
        }
    }
}

// Override the handling of the XrSpaceVelocities structure when found in a 'next' chain.
// The problem is that it is an output structure, but it needs initialization done for it to be
// properly filled in by the API.  This includes, setting proper array sizes, and creating
// storage space for those arrays.
XrBaseOutStructure* OverrideOutputStructNext_XrSpaceVelocities(const XrBaseInStructure* in_next,
                                                               XrBaseOutStructure*      output_struct)
{
    XrSpaceVelocities* out_space_velocities = DecodeAllocator::Allocate<XrSpaceVelocities>();
    if (out_space_velocities != nullptr)
    {
        const XrSpaceVelocities* in_space_velocities = reinterpret_cast<const XrSpaceVelocities*>(in_next);
        out_space_velocities->velocityCount          = in_space_velocities->velocityCount;
        if (out_space_velocities->velocityCount > 0)
        {
            out_space_velocities->velocities =
                DecodeAllocator::Allocate<XrSpaceVelocityData>(in_space_velocities->velocityCount);
            memcpy(out_space_velocities->velocities,
                   in_space_velocities->velocities,
                   sizeof(XrSpaceVelocityData) * in_space_velocities->velocityCount);
        }
    }
    return reinterpret_cast<XrBaseOutStructure*>(out_space_velocities);
}

// Override the handling of the XrBindingModificationsKHR structure when found in a 'next' chain.
// The problem is that it is an output structure, but it needs initialization done for it to be
// properly filled in by the API.  This includes, setting proper array sizes, and creating
// storage space for those arrays.  Unfortunately, this is complicated by the fact that some of the
// arrays of structures are for "BaseHeader" type place-holders which need to be deciphered, and then
// those also have arrays of content as well.
XrBaseOutStructure* OverrideOutputStructNext_XrBindingModificationsKHR(const XrBaseInStructure* in_next,
                                                                       XrBaseOutStructure*      output_struct)
{
    XrBindingModificationsKHR* out_binding_mod_parent = DecodeAllocator::Allocate<XrBindingModificationsKHR>();
    if (out_binding_mod_parent != nullptr)
    {
        const XrBindingModificationsKHR* in_binding_mod_parent =
            reinterpret_cast<const XrBindingModificationsKHR*>(in_next);
        out_binding_mod_parent->type                     = in_binding_mod_parent->type;
        out_binding_mod_parent->next                     = nullptr;
        out_binding_mod_parent->bindingModificationCount = in_binding_mod_parent->bindingModificationCount;
        if (in_binding_mod_parent->bindingModificationCount > 0)
        {
            XrBindingModificationBaseHeaderKHR** out_binding_mods =
                DecodeAllocator::Allocate<XrBindingModificationBaseHeaderKHR*>(
                    in_binding_mod_parent->bindingModificationCount);
            const XrBindingModificationBaseHeaderKHR* const* in_binding_mods =
                in_binding_mod_parent->bindingModifications;
            for (uint32_t iii = 0; iii < in_binding_mod_parent->bindingModificationCount; ++iii)
            {
                switch (in_binding_mods[iii]->type)
                {
                    default:
                        out_binding_mods[iii]       = DecodeAllocator::Allocate<XrBindingModificationBaseHeaderKHR>();
                        out_binding_mods[iii]->type = in_binding_mods[iii]->type;
                        GFXRECON_LOG_ERROR(
                            "Unknown bindingModification structure type %u for XrBindingModificationsKHR index %u",
                            in_binding_mods[iii]->type,
                            iii);
                        break;
                    case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
                    {
                        XrInteractionProfileDpadBindingEXT* out_dpad_binding =
                            DecodeAllocator::Allocate<XrInteractionProfileDpadBindingEXT>();
                        const XrInteractionProfileDpadBindingEXT* in_dpad_binding =
                            reinterpret_cast<const XrInteractionProfileDpadBindingEXT*>(in_binding_mods[iii]);
                        memcpy(out_dpad_binding, in_dpad_binding, sizeof(XrInteractionProfileDpadBindingEXT));
                        if (out_dpad_binding->onHaptic != nullptr)
                        {
                            switch (in_dpad_binding->onHaptic->type)
                            {
                                default:
                                {
                                    XrHapticBaseHeader* out_haptic_base =
                                        DecodeAllocator::Allocate<XrHapticBaseHeader>();
                                    out_haptic_base->type = in_dpad_binding->onHaptic->type;
                                    GFXRECON_LOG_ERROR(
                                        "Unknown onHaptic structure type %u for XrBindingModificationsKHR index %u",
                                        in_dpad_binding->onHaptic->type,
                                        iii);
                                    out_dpad_binding->onHaptic = out_haptic_base;
                                    break;
                                }
                                case XR_TYPE_HAPTIC_VIBRATION:
                                {
                                    XrHapticVibration* out_haptic_vib = DecodeAllocator::Allocate<XrHapticVibration>();
                                    memcpy(out_haptic_vib, in_dpad_binding->onHaptic, sizeof(XrHapticVibration));
                                    out_dpad_binding->onHaptic = reinterpret_cast<XrHapticBaseHeader*>(out_haptic_vib);
                                    break;
                                }
                                case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
                                {
                                    XrHapticAmplitudeEnvelopeVibrationFB* out_haptic_vib =
                                        DecodeAllocator::Allocate<XrHapticAmplitudeEnvelopeVibrationFB>();
                                    const XrHapticAmplitudeEnvelopeVibrationFB* in_haptic_vib =
                                        reinterpret_cast<const XrHapticAmplitudeEnvelopeVibrationFB*>(
                                            in_dpad_binding->onHaptic);
                                    memcpy(out_haptic_vib, in_haptic_vib, sizeof(XrHapticAmplitudeEnvelopeVibrationFB));

                                    if (out_haptic_vib->amplitudeCount > 0)
                                    {
                                        float* out_amplitudes =
                                            DecodeAllocator::Allocate<float>(in_haptic_vib->amplitudeCount);
                                        memcpy(out_amplitudes,
                                               in_haptic_vib->amplitudes,
                                               sizeof(float) * in_haptic_vib->amplitudeCount);
                                        out_haptic_vib->amplitudes = out_amplitudes;
                                    }

                                    out_dpad_binding->onHaptic = reinterpret_cast<XrHapticBaseHeader*>(out_haptic_vib);
                                    break;
                                }
                                case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
                                {
                                    XrHapticPcmVibrationFB* out_haptic_vib =
                                        DecodeAllocator::Allocate<XrHapticPcmVibrationFB>();
                                    const XrHapticPcmVibrationFB* in_haptic_vib =
                                        reinterpret_cast<const XrHapticPcmVibrationFB*>(in_dpad_binding->onHaptic);
                                    memcpy(out_haptic_vib, in_haptic_vib, sizeof(XrHapticPcmVibrationFB));

                                    if (in_haptic_vib->samplesConsumed != nullptr)
                                    {
                                        out_haptic_vib->samplesConsumed  = DecodeAllocator::Allocate<uint32_t>();
                                        *out_haptic_vib->samplesConsumed = *in_haptic_vib->samplesConsumed;
                                    }

                                    if (in_haptic_vib->bufferSize > 0)
                                    {
                                        float* out_buffer = DecodeAllocator::Allocate<float>(in_haptic_vib->bufferSize);
                                        memcpy(out_buffer,
                                               in_haptic_vib->buffer,
                                               sizeof(float) * in_haptic_vib->bufferSize);
                                        out_haptic_vib->buffer = out_buffer;
                                    }

                                    out_dpad_binding->onHaptic = reinterpret_cast<XrHapticBaseHeader*>(out_haptic_vib);
                                    break;
                                }
                            }
                        }
                        if (out_dpad_binding->offHaptic != nullptr)
                        {
                            switch (out_dpad_binding->offHaptic->type)
                            {
                                default:
                                {
                                    XrHapticBaseHeader* out_haptic_base =
                                        DecodeAllocator::Allocate<XrHapticBaseHeader>();
                                    out_haptic_base->type = in_dpad_binding->offHaptic->type;
                                    GFXRECON_LOG_ERROR(
                                        "Unknown offHaptic structure type %u for XrBindingModificationsKHR index %u",
                                        in_dpad_binding->offHaptic->type,
                                        iii);
                                    out_dpad_binding->offHaptic = out_haptic_base;
                                    break;
                                }
                                case XR_TYPE_HAPTIC_VIBRATION:
                                {
                                    XrHapticVibration* out_haptic_vib = DecodeAllocator::Allocate<XrHapticVibration>();
                                    memcpy(out_haptic_vib, in_dpad_binding->offHaptic, sizeof(XrHapticVibration));
                                    break;
                                }
                                case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
                                {
                                    XrHapticAmplitudeEnvelopeVibrationFB* out_haptic_vib =
                                        DecodeAllocator::Allocate<XrHapticAmplitudeEnvelopeVibrationFB>();
                                    const XrHapticAmplitudeEnvelopeVibrationFB* in_haptic_vib =
                                        reinterpret_cast<const XrHapticAmplitudeEnvelopeVibrationFB*>(
                                            in_dpad_binding->offHaptic);
                                    memcpy(out_haptic_vib, in_haptic_vib, sizeof(XrHapticAmplitudeEnvelopeVibrationFB));

                                    if (in_haptic_vib->amplitudeCount > 0)
                                    {
                                        float* out_amplitudes =
                                            DecodeAllocator::Allocate<float>(in_haptic_vib->amplitudeCount);
                                        memcpy(out_amplitudes,
                                               in_haptic_vib->amplitudes,
                                               sizeof(float) * in_haptic_vib->amplitudeCount);
                                        out_haptic_vib->amplitudes = out_amplitudes;
                                    }

                                    out_dpad_binding->offHaptic = reinterpret_cast<XrHapticBaseHeader*>(out_haptic_vib);
                                    break;
                                }
                                case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
                                {
                                    XrHapticPcmVibrationFB* out_haptic_vib =
                                        DecodeAllocator::Allocate<XrHapticPcmVibrationFB>();
                                    const XrHapticPcmVibrationFB* in_haptic_vib =
                                        reinterpret_cast<const XrHapticPcmVibrationFB*>(in_dpad_binding->offHaptic);
                                    memcpy(out_haptic_vib, in_haptic_vib, sizeof(XrHapticPcmVibrationFB));

                                    if (in_haptic_vib->samplesConsumed != nullptr)
                                    {
                                        out_haptic_vib->samplesConsumed  = DecodeAllocator::Allocate<uint32_t>();
                                        *out_haptic_vib->samplesConsumed = *in_haptic_vib->samplesConsumed;
                                    }

                                    if (in_haptic_vib->bufferSize > 0)
                                    {
                                        float* out_buffer = DecodeAllocator::Allocate<float>(in_haptic_vib->bufferSize);
                                        ;
                                        memcpy(out_buffer,
                                               in_haptic_vib->buffer,
                                               sizeof(float) * in_haptic_vib->bufferSize);
                                        out_haptic_vib->buffer = out_buffer;
                                    }

                                    out_dpad_binding->offHaptic = reinterpret_cast<XrHapticBaseHeader*>(out_haptic_vib);
                                    break;
                                }
                            }
                        }
                        out_binding_mods[iii] = reinterpret_cast<XrBindingModificationBaseHeaderKHR*>(out_dpad_binding);
                        break;
                    }

                    case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
                    {
                        XrInteractionProfileAnalogThresholdVALVE* out_thresh_binding =
                            DecodeAllocator::Allocate<XrInteractionProfileAnalogThresholdVALVE>();
                        const XrInteractionProfileAnalogThresholdVALVE* in_thresh_binding =
                            reinterpret_cast<const XrInteractionProfileAnalogThresholdVALVE*>(in_binding_mods[iii]);
                        memcpy(out_thresh_binding, in_thresh_binding, sizeof(XrInteractionProfileAnalogThresholdVALVE));
                        if (out_thresh_binding->onHaptic != nullptr)
                        {
                            switch (out_thresh_binding->onHaptic->type)
                            {
                                default:
                                {
                                    XrHapticBaseHeader* out_haptic_base =
                                        DecodeAllocator::Allocate<XrHapticBaseHeader>();
                                    out_haptic_base->type = in_thresh_binding->onHaptic->type;
                                    GFXRECON_LOG_ERROR(
                                        "Unknown onHaptic structure type %u for XrBindingModificationsKHR index %u",
                                        in_thresh_binding->onHaptic->type,
                                        iii);
                                    out_thresh_binding->onHaptic = out_haptic_base;
                                    break;
                                }
                                case XR_TYPE_HAPTIC_VIBRATION:
                                {
                                    XrHapticVibration* out_haptic_vib = DecodeAllocator::Allocate<XrHapticVibration>();
                                    memcpy(out_haptic_vib, in_thresh_binding->onHaptic, sizeof(XrHapticVibration));
                                    break;
                                }
                                case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
                                {
                                    XrHapticAmplitudeEnvelopeVibrationFB* out_haptic_vib =
                                        DecodeAllocator::Allocate<XrHapticAmplitudeEnvelopeVibrationFB>();
                                    const XrHapticAmplitudeEnvelopeVibrationFB* in_haptic_vib =
                                        reinterpret_cast<const XrHapticAmplitudeEnvelopeVibrationFB*>(
                                            in_thresh_binding->onHaptic);
                                    memcpy(out_haptic_vib, in_haptic_vib, sizeof(XrHapticAmplitudeEnvelopeVibrationFB));

                                    if (in_haptic_vib->amplitudeCount > 0)
                                    {
                                        float* out_amplitudes =
                                            DecodeAllocator::Allocate<float>(in_haptic_vib->amplitudeCount);
                                        memcpy(out_amplitudes,
                                               in_haptic_vib->amplitudes,
                                               sizeof(float) * in_haptic_vib->amplitudeCount);
                                        out_haptic_vib->amplitudes = out_amplitudes;
                                    }

                                    out_thresh_binding->onHaptic =
                                        reinterpret_cast<XrHapticBaseHeader*>(out_haptic_vib);
                                    break;
                                }
                                case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
                                {
                                    XrHapticPcmVibrationFB* out_haptic_vib =
                                        DecodeAllocator::Allocate<XrHapticPcmVibrationFB>();
                                    const XrHapticPcmVibrationFB* in_haptic_vib =
                                        reinterpret_cast<const XrHapticPcmVibrationFB*>(in_thresh_binding->onHaptic);
                                    memcpy(out_haptic_vib, in_thresh_binding->onHaptic, sizeof(XrHapticPcmVibrationFB));

                                    if (in_haptic_vib->samplesConsumed != nullptr)
                                    {
                                        out_haptic_vib->samplesConsumed  = DecodeAllocator::Allocate<uint32_t>();
                                        *out_haptic_vib->samplesConsumed = *in_haptic_vib->samplesConsumed;
                                    }

                                    if (in_haptic_vib->bufferSize > 0)
                                    {
                                        float* out_buffer = DecodeAllocator::Allocate<float>(in_haptic_vib->bufferSize);
                                        memcpy(out_buffer,
                                               in_haptic_vib->buffer,
                                               sizeof(float) * in_haptic_vib->bufferSize);
                                        out_haptic_vib->buffer = out_buffer;
                                    }

                                    out_thresh_binding->onHaptic =
                                        reinterpret_cast<XrHapticBaseHeader*>(out_haptic_vib);
                                    break;
                                }
                            }
                        }
                        if (out_thresh_binding->offHaptic != nullptr)
                        {
                            switch (out_thresh_binding->offHaptic->type)
                            {
                                default:
                                {
                                    XrHapticBaseHeader* out_haptic_base =
                                        DecodeAllocator::Allocate<XrHapticBaseHeader>();
                                    out_haptic_base->type = in_thresh_binding->offHaptic->type;
                                    GFXRECON_LOG_ERROR(
                                        "Unknown offHaptic structure type %u for XrBindingModificationsKHR index %u",
                                        in_thresh_binding->offHaptic->type,
                                        iii);
                                    out_thresh_binding->offHaptic = out_haptic_base;
                                    break;
                                }
                                case XR_TYPE_HAPTIC_VIBRATION:
                                {
                                    XrHapticVibration* out_haptic_vib = DecodeAllocator::Allocate<XrHapticVibration>();
                                    memcpy(out_haptic_vib, in_thresh_binding->offHaptic, sizeof(XrHapticVibration));
                                    break;
                                }
                                case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
                                {
                                    XrHapticAmplitudeEnvelopeVibrationFB* out_haptic_vib =
                                        DecodeAllocator::Allocate<XrHapticAmplitudeEnvelopeVibrationFB>();
                                    const XrHapticAmplitudeEnvelopeVibrationFB* in_haptic_vib =
                                        reinterpret_cast<const XrHapticAmplitudeEnvelopeVibrationFB*>(
                                            in_thresh_binding->offHaptic);
                                    memcpy(out_haptic_vib, in_haptic_vib, sizeof(XrHapticAmplitudeEnvelopeVibrationFB));

                                    if (in_haptic_vib->amplitudeCount > 0)
                                    {
                                        float* out_amplitudes =
                                            DecodeAllocator::Allocate<float>(in_haptic_vib->amplitudeCount);
                                        memcpy(out_amplitudes,
                                               in_haptic_vib->amplitudes,
                                               sizeof(float) * in_haptic_vib->amplitudeCount);
                                        out_haptic_vib->amplitudes = out_amplitudes;
                                    }

                                    out_thresh_binding->offHaptic =
                                        reinterpret_cast<XrHapticBaseHeader*>(out_haptic_vib);
                                    break;
                                }
                                case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
                                {
                                    XrHapticPcmVibrationFB* out_haptic_vib =
                                        DecodeAllocator::Allocate<XrHapticPcmVibrationFB>();
                                    const XrHapticPcmVibrationFB* in_haptic_vib =
                                        reinterpret_cast<const XrHapticPcmVibrationFB*>(in_thresh_binding->offHaptic);
                                    memcpy(
                                        out_haptic_vib, in_thresh_binding->offHaptic, sizeof(XrHapticPcmVibrationFB));

                                    if (in_haptic_vib->samplesConsumed != nullptr)
                                    {
                                        out_haptic_vib->samplesConsumed  = DecodeAllocator::Allocate<uint32_t>();
                                        *out_haptic_vib->samplesConsumed = *in_haptic_vib->samplesConsumed;
                                    }

                                    if (in_haptic_vib->bufferSize > 0)
                                    {
                                        float* out_buffer = DecodeAllocator::Allocate<float>(in_haptic_vib->bufferSize);
                                        memcpy(out_buffer,
                                               in_haptic_vib->buffer,
                                               sizeof(float) * in_haptic_vib->bufferSize);
                                        out_haptic_vib->buffer = out_buffer;
                                    }

                                    out_thresh_binding->offHaptic =
                                        reinterpret_cast<XrHapticBaseHeader*>(out_haptic_vib);
                                    break;
                                }
                            }
                        }
                        out_binding_mods[iii] =
                            reinterpret_cast<XrBindingModificationBaseHeaderKHR*>(out_thresh_binding);
                        break;
                    }
                }
            }
            out_binding_mod_parent->bindingModifications =
                reinterpret_cast<const XrBindingModificationBaseHeaderKHR* const*>(out_binding_mods);
        }
    }
    return reinterpret_cast<XrBaseOutStructure*>(out_binding_mod_parent);
}

// Override the handling of the XrHandJointVelocitiesEXT structure when found in a 'next' chain.
// The problem is that it is an output structure, but it needs initialization done for it to be
// properly filled in by the API.  This includes, setting proper array sizes, and creating
// storage space for those arrays.
XrBaseOutStructure* OverrideOutputStructNext_XrHandJointVelocitiesEXT(const XrBaseInStructure* in_next,
                                                                      XrBaseOutStructure*      output_struct)
{
    XrHandJointVelocitiesEXT* out_hand_joint_velocities = DecodeAllocator::Allocate<XrHandJointVelocitiesEXT>();
    if (out_hand_joint_velocities != nullptr)
    {
        const XrHandJointVelocitiesEXT* in_hand_joint_velocities =
            reinterpret_cast<const XrHandJointVelocitiesEXT*>(in_next);
        out_hand_joint_velocities->jointCount = in_hand_joint_velocities->jointCount;
        if (out_hand_joint_velocities->jointCount > 0)
        {
            out_hand_joint_velocities->jointVelocities =
                DecodeAllocator::Allocate<XrHandJointVelocityEXT>(in_hand_joint_velocities->jointCount);
            memcpy(out_hand_joint_velocities->jointVelocities,
                   in_hand_joint_velocities->jointVelocities,
                   sizeof(XrHandJointVelocityEXT) * in_hand_joint_velocities->jointCount);
        }
    }
    return reinterpret_cast<XrBaseOutStructure*>(out_hand_joint_velocities);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
