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

#ifndef GFXRECON_DECODE_OPENXR_REPLAY_CONSUMER_BASE_H
#define GFXRECON_DECODE_OPENXR_REPLAY_CONSUMER_BASE_H

#if ENABLE_OPENXR_SUPPORT

#include <deque>
#include <optional>
#include <unordered_map>
#include "application/application.h"
#include "decode/openxr_handle_mapping_util.h"
#include "decode/openxr_object_info.h"
#include "decode/openxr_replay_options.h"
#include "decode/openxr_resource_tracking_consumer.h"
#include "decode/vulkan_resource_tracking_consumer.h"
#include "generated/generated_openxr_consumer.h"
#include "generated/generated_openxr_dispatch_table.h"
#include "decode/openxr_replay_swapchain_state.h"
#include "decode/openxr_replay_session_state.h"

#include <functional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
class VulkanReplayConsumerBase;

// Declaration of function defined in code gen derived class file
void InitializeOutputStructNextImpl(const XrBaseInStructure* in_next, XrBaseOutStructure* output_struct);

// Specialize Getters at namespace scope
// TODO: This should be an addition to the standard access specializations in code generation
template <typename ObjInfo>
ObjInfo* GetObjectInfo(format::HandleId id, CommonObjectInfoTable* table)
{
    assert("not implemented" == nullptr);
    return nullptr;
}

// TODO: Need to generate these specializations for all types in code gen
template <>
inline OpenXrSessionInfo* GetObjectInfo<OpenXrSessionInfo>(format::HandleId id, CommonObjectInfoTable* table)
{
    return table->GetXrSessionInfo(id);
}
template <>
inline OpenXrSwapchainInfo* GetObjectInfo<OpenXrSwapchainInfo>(format::HandleId id, CommonObjectInfoTable* table)
{
    return table->GetXrSwapchainInfo(id);
}

template <typename T>
void InitializeOutputStructNext(StructPointerDecoder<T>* decoder)
{
    if (decoder->IsNull())
        return;
    size_t len    = decoder->GetOutputLength();
    auto   input  = decoder->GetPointer();
    auto   output = decoder->GetOutputPointer();
    for (size_t i = 0; i < len; ++i)
    {
        const auto* in_next = reinterpret_cast<const XrBaseInStructure*>(input[i].next);
        if (in_next == nullptr)
            continue;
        auto* output_struct = reinterpret_cast<XrBaseOutStructure*>(&output[i]);
        InitializeOutputStructNextImpl(in_next, output_struct);
    }
}

class OpenXrReplayConsumerBase : public OpenXrConsumer
{
  public:
    using SessionData   = openxr::SessionData;
    using SwapchainData = openxr::SwapchainData;

    OpenXrReplayConsumerBase(std::shared_ptr<application::Application> application, const OpenXrReplayOptions& options);

    ~OpenXrReplayConsumerBase() override;

    void SetVulkanReplayConsumer(VulkanReplayConsumerBase* vulkan_replay_consumer);

#if defined(__ANDROID__)
    void SetAndroidApp(struct android_app* app)
    {
        android_app_ = app;
    }
#endif

    virtual void
    Process_xrInitializeLoaderKHR(const ApiCallInfo&                                           call_info,
                                  XrResult                                                     returnValue,
                                  StructPointerDecoder<Decoded_XrLoaderInitInfoBaseHeaderKHR>* loaderInitInfo) override;

    virtual void Process_xrCreateApiLayerInstance(const ApiCallInfo&                                  call_info,
                                                  XrResult                                            returnValue,
                                                  StructPointerDecoder<Decoded_XrInstanceCreateInfo>* info,
                                                  StructPointerDecoder<Decoded_XrApiLayerCreateInfo>* apiLayerInfo,
                                                  HandlePointerDecoder<XrInstance>*) override;

    virtual void
    Process_xrCreateVulkanInstanceKHR(const ApiCallInfo&                                           call_info,
                                      XrResult                                                     returnValue,
                                      format::HandleId                                             instance,
                                      StructPointerDecoder<Decoded_XrVulkanInstanceCreateInfoKHR>* createInfo,
                                      HandlePointerDecoder<VkInstance>*                            vulkanInstance,
                                      PointerDecoder<VkResult>* vulkanResult) override;

    virtual void Process_xrCreateVulkanDeviceKHR(const ApiCallInfo&                                         call_info,
                                                 XrResult                                                   returnValue,
                                                 format::HandleId                                           instance,
                                                 StructPointerDecoder<Decoded_XrVulkanDeviceCreateInfoKHR>* createInfo,
                                                 HandlePointerDecoder<VkDevice>* vulkanDevice,
                                                 PointerDecoder<VkResult>*       vulkanResult) override;

    virtual void Process_xrPollEvent(const ApiCallInfo&                               call_info,
                                     XrResult                                         returnValue,
                                     format::HandleId                                 instance,
                                     StructPointerDecoder<Decoded_XrEventDataBuffer>* eventData) override;

    virtual void Process_xrCreateSwapchain(const ApiCallInfo&                                   call_info,
                                           XrResult                                             returnValue,
                                           format::HandleId                                     session,
                                           StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* createInfo,
                                           HandlePointerDecoder<XrSwapchain>*                   swapchain) override;

    void
    Process_xrReleaseSwapchainImage(const ApiCallInfo&                                         call_info,
                                    XrResult                                                   returnValue,
                                    format::HandleId                                           swapchain,
                                    StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo) override;

    void ProcessViewRelativeLocation(format::ThreadId thread_id, format::ViewRelativeLocation& location) override;

    virtual void Process_xrEndFrame(const ApiCallInfo&                            call_info,
                                    XrResult                                      returnValue,
                                    format::HandleId                              session,
                                    StructPointerDecoder<Decoded_XrFrameEndInfo>* frameEndInfo) override;

    virtual void Process_xrLocateSpaces(const ApiCallInfo&                                call_info,
                                        XrResult                                          returnValue,
                                        format::HandleId                                  session,
                                        StructPointerDecoder<Decoded_XrSpacesLocateInfo>* locateInfo,
                                        StructPointerDecoder<Decoded_XrSpaceLocations>*   spaceLocations) override;

    virtual void
    Process_xrLocateHandJointsEXT(const ApiCallInfo&                                       call_info,
                                  XrResult                                                 returnValue,
                                  format::HandleId                                         handTracker,
                                  StructPointerDecoder<Decoded_XrHandJointsLocateInfoEXT>* locateInfo,
                                  StructPointerDecoder<Decoded_XrHandJointLocationsEXT>*   locations) override;

    virtual void Process_xrGetHandMeshFB(const ApiCallInfo&                                  call_info,
                                         XrResult                                            returnValue,
                                         format::HandleId                                    handTracker,
                                         StructPointerDecoder<Decoded_XrHandTrackingMeshFB>* mesh) override;

    virtual void Process_xrLocateBodyJointsFB(const ApiCallInfo&                                      call_info,
                                              XrResult                                                returnValue,
                                              format::HandleId                                        bodyTracker,
                                              StructPointerDecoder<Decoded_XrBodyJointsLocateInfoFB>* locateInfo,
                                              StructPointerDecoder<Decoded_XrBodyJointLocationsFB>* locations) override;

    void UpdateState_xrGetVulkanGraphicsDeviceKHR(const ApiCallInfo&                      call_info,
                                                  XrResult                                returnValue,
                                                  format::HandleId                        instance,
                                                  format::HandleId                        systemId,
                                                  format::HandleId                        vkInstance,
                                                  HandlePointerDecoder<VkPhysicalDevice>* vkPhysicalDevice,
                                                  XrResult                                replay_result);

    void
    UpdateState_xrGetVulkanGraphicsDevice2KHR(const ApiCallInfo& call_info,
                                              XrResult           returnValue,
                                              format::HandleId   instance,
                                              StructPointerDecoder<Decoded_XrVulkanGraphicsDeviceGetInfoKHR>* getInfo,
                                              HandlePointerDecoder<VkPhysicalDevice>* vulkanPhysicalDevice,
                                              XrResult                                replay_result);

    void UpdateState_xrCreateSession(const ApiCallInfo&                                 call_info,
                                     XrResult                                           returnValue,
                                     format::HandleId                                   instance,
                                     StructPointerDecoder<Decoded_XrSessionCreateInfo>* createInfo,
                                     HandlePointerDecoder<XrSession>*                   session,
                                     XrResult                                           replay_result);

    void UpdateState_xrEndSession(const ApiCallInfo& call_info,
                                  XrResult           returnValue,
                                  format::HandleId   session,
                                  XrResult           replay_result);

    void UpdateState_xrBeginFrame(const ApiCallInfo&                              call_info,
                                  XrResult                                        returnValue,
                                  format::HandleId                                session,
                                  StructPointerDecoder<Decoded_XrFrameBeginInfo>* frameBeginInfo,
                                  XrResult                                        replay_result);

    void UpdateState_xrWaitFrame(const ApiCallInfo&                             call_info,
                                 XrResult                                       returnValue,
                                 format::HandleId                               session,
                                 StructPointerDecoder<Decoded_XrFrameWaitInfo>* frameWaitInfo,
                                 StructPointerDecoder<Decoded_XrFrameState>*    frameState,
                                 XrResult                                       replay_result);

    void UpdateState_xrEnumerateReferenceSpaces(const ApiCallInfo&                    call_info,
                                                XrResult                              returnValue,
                                                format::HandleId                      session,
                                                uint32_t                              spaceCapacityInput,
                                                PointerDecoder<uint32_t>*             spaceCountOutput,
                                                PointerDecoder<XrReferenceSpaceType>* spaces,
                                                XrResult                              replay_result);

    void UpdateState_xrEnumerateSwapchainImages(const ApiCallInfo&        call_info,
                                                XrResult                  returnValue,
                                                format::HandleId          swapchain,
                                                uint32_t                  imageCapacityInput,
                                                PointerDecoder<uint32_t>* imageCountOutput,
                                                StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images,
                                                XrResult replay_result);

    void UpdateState_xrAcquireSwapchainImage(const ApiCallInfo&                                         call_info,
                                             XrResult                                                   returnValue,
                                             format::HandleId                                           swapchain,
                                             StructPointerDecoder<Decoded_XrSwapchainImageAcquireInfo>* acquireInfo,
                                             PointerDecoder<uint32_t>*                                  index,
                                             XrResult                                                   replay_result);

    void UpdateState_xrDestroySwapchain(const ApiCallInfo& call_info,
                                        XrResult           returnValue,
                                        format::HandleId   swapchain,
                                        XrResult           replay_result);

    void SetFatalErrorHandler(std::function<void(const char*)> handler)
    {
        fatal_error_handler_ = handler;
    }

    const OpenXrReplayOptions options_;

  protected:
    const CommonObjectInfoTable& GetObjectInfoTable() const
    {
        return *object_info_table_;
    }

    CommonObjectInfoTable& GetObjectInfoTable()
    {
        return *object_info_table_;
    }

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
    const encode::OpenXrInstanceTable* GetInstanceTable(XrSpatialGraphNodeBindingMSFT handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrTriangleMeshFB handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrEnvironmentDepthProviderMETA handle) const;
    const encode::OpenXrInstanceTable* GetInstanceTable(XrEnvironmentDepthSwapchainMETA handle) const;
#endif // defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)

    void AssociateParent(XrSession session, XrInstance instance);
#if defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)
    void AssociateParent(XrSpace space, XrSession session);
    void AssociateParent(XrSwapchain swapchain, XrSession session);
    void AssociateParent(XrActionSet action_set, XrInstance instance);
    void AssociateParent(XrAction action, XrActionSet action_set);
    void AssociateParent(XrDebugUtilsMessengerEXT debug_messenger, XrInstance instance);
    void AssociateParent(XrSpatialAnchorMSFT spatial_anchor, XrSession session);
    void AssociateParent(XrHandTrackerEXT hand_tracker, XrSession session);
    void AssociateParent(XrSpace space, XrHandTrackerEXT hand_tracker);
    void AssociateParent(XrBodyTrackerFB body_tracker, XrSession session);
    void AssociateParent(XrSceneObserverMSFT scene_observer, XrSession session);
    void AssociateParent(XrSceneMSFT scene, XrSceneObserverMSFT);
    void AssociateParent(XrFacialTrackerHTC facial_tracker, XrSession session);
    void AssociateParent(XrFoveationProfileFB foveation_profile, XrSession session);
    void AssociateParent(XrPassthroughFB passthrough, XrSession session);
    void AssociateParent(XrPassthroughLayerFB passthrough_layer, XrSession session);
    void AssociateParent(XrGeometryInstanceFB geometry_instance, XrSession session);
    void AssociateParent(XrMarkerDetectorML marker_detector, XrSession session);
    void AssociateParent(XrExportedLocalizationMapML exported_localization, XrSession session);
    void AssociateParent(XrSpatialAnchorStoreConnectionMSFT spatial_anchor_con, XrSession session);
    void AssociateParent(XrFaceTrackerFB face_tracker, XrSession session);
    void AssociateParent(XrEyeTrackerFB eye_tracker, XrSession session);
    void AssociateParent(XrVirtualKeyboardMETA virtual_keyboard, XrSession session);
    void AssociateParent(XrSpace space, XrVirtualKeyboardMETA virtual_keyboard);
    void AssociateParent(XrSpaceUserFB space_user, XrSession session);
    void AssociateParent(XrPassthroughColorLutMETA passthrough_color_lut, XrPassthroughFB);
    void AssociateParent(XrFaceTracker2FB face_tracker, XrSession session);
    void AssociateParent(XrPassthroughHTC passthrough, XrSession session);
    void AssociateParent(XrPlaneDetectorEXT plane_detector, XrSession session);
    void AssociateParent(XrSpatialGraphNodeBindingMSFT graph_node, XrSession session);
    void AssociateParent(XrTriangleMeshFB triangle_mesh, XrSession session);
    void AssociateParent(XrEnvironmentDepthProviderMETA env_depth_provider, XrSession session);
    void AssociateParent(XrEnvironmentDepthSwapchainMETA env_depth_swapchain,
                         XrEnvironmentDepthProviderMETA  environment_depth_provider);
#endif // defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__)

    void* PreProcessExternalObject(uint64_t object_id, format::ApiCallId call_id, const char* call_name);

    void PostProcessExternalObject(
        XrResult replay_reslt, uint64_t object_id, void* object, format::ApiCallId call_id, const char* call_name);

    template <typename T>
    typename T::HandleType MapHandle(format::HandleId id,
                                     const T* (CommonObjectInfoTable::*MapFunc)(format::HandleId) const) const
    {
        return handle_mapping::MapHandle(id, *object_info_table_, MapFunc);
    }

    uint64_t MapHandle(uint64_t object, XrObjectType object_type)
    {
        return handle_mapping::MapHandle(object, object_type, *object_info_table_);
    }

    void RemoveHandle(format::HandleId id, void (CommonObjectInfoTable::*RemoveFunc)(format::HandleId))
    {
        handle_mapping::RemoveHandle(id, object_info_table_, RemoveFunc);
    }

    template <typename T>
    typename T::HandleType* MapHandles(HandlePointerDecoder<typename T::HandleType>* handles_pointer,
                                       size_t                                        handles_len,
                                       const T* (CommonObjectInfoTable::*MapFunc)(format::HandleId) const) const
    {
        // This parameter is only referenced by debug builds.
        GFXRECON_UNREFERENCED_PARAMETER(handles_len);

        typename T::HandleType* handles = nullptr;

        if (handles_pointer != nullptr)
        {
            // The handle and ID array sizes are expected to be the same for mapping operations.
            assert(handles_len == handles_pointer->GetLength());

            handles = handle_mapping::MapHandleArray(handles_pointer, object_info_table_, MapFunc);
        }

        return handles;
    }

    template <typename T>
    void AddHandle(format::HandleId              parent_id,
                   const format::HandleId*       id,
                   const typename T::HandleType* handle,
                   T&&                           initial_info,
                   void (CommonObjectInfoTable::*AddFunc)(T&&))
    {
        if ((id != nullptr) && (handle != nullptr))
        {
            handle_mapping::AddHandle(
                parent_id, *id, *handle, std::forward<T>(initial_info), object_info_table_, AddFunc);
        }
    }

    template <typename T>
    void AddHandle(format::HandleId              parent_id,
                   const format::HandleId*       id,
                   const typename T::HandleType* handle,
                   void (CommonObjectInfoTable::*AddFunc)(T&&))
    {
        if ((id != nullptr) && (handle != nullptr))
        {
            handle_mapping::AddHandle(parent_id, *id, *handle, object_info_table_, AddFunc);
        }
    }

    template <typename T>
    void AddHandles(format::HandleId              parent_id,
                    const format::HandleId*       ids,
                    size_t                        ids_len,
                    const typename T::HandleType* handles,
                    size_t                        handles_len,
                    std::vector<T>&&              initial_infos,
                    void (CommonObjectInfoTable::*AddFunc)(T&&))
    {
        handle_mapping::AddHandleArray(
            parent_id, ids, ids_len, handles, handles_len, std::move(initial_infos), &object_info_table_, AddFunc);
    }

    template <typename T>
    void AddHandles(format::HandleId              parent_id,
                    const format::HandleId*       ids,
                    size_t                        ids_len,
                    const typename T::HandleType* handles,
                    size_t                        handles_len,
                    void (CommonObjectInfoTable::*AddFunc)(T&&))
    {
        handle_mapping::AddHandleArray(parent_id, ids, ids_len, handles, handles_len, object_info_table_, AddFunc);
    }

    void CheckResult(const char*                func_name,
                     XrResult                   original,
                     XrResult                   replay,
                     const decode::ApiCallInfo& call_info,
                     bool                       assert_on_error = true);

  private:
    void RaiseFatalError(const char* message) const;

    PFN_xrGetInstanceProcAddr                                   get_instance_proc_addr_;
    CommonObjectInfoTable*                                      object_info_table_;
    std::unordered_map<XrInstance, encode::OpenXrInstanceTable> instance_tables_;
    std::shared_ptr<application::Application>                   application_;
    std::function<void(const char*)>                            fatal_error_handler_;
#if defined(__ANDROID__)
    struct android_app* android_app_;
#endif

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
    std::unordered_map<XrSpatialGraphNodeBindingMSFT, XrInstance>      spatialgraphnodebindingMSFT_to_instance_;
    std::unordered_map<XrTriangleMeshFB, XrInstance>                   trianglemeshFB_to_instance_;
    std::unordered_map<XrEnvironmentDepthProviderMETA, XrInstance>     envdepthproviderMETA_to_instance_;
    std::unordered_map<XrEnvironmentDepthSwapchainMETA, XrInstance>    envdepthswapchainMETA_to_instance_;

    VulkanReplayConsumerBase* vulkan_replay_consumer_ = nullptr;

    std::vector<XrEventDataBuffer> received_events_;

    // Replay specific state:

    openxr::GraphicsBinding MakeGraphicsBinding(Decoded_XrSessionCreateInfo* create_info);

    template <typename ReplayData>
    ReplayData& AddReplayData(format::HandleId id)
    {
        using ObjectInfo     = OpenXrReplayObjectInfo<typename ReplayData::HandleType, ReplayData>;
        ObjectInfo* obj_info = GetObjectInfo<ObjectInfo>(id, object_info_table_);
        assert(obj_info);
        obj_info->InitReplayData();
        assert(obj_info->replay_data.get());
        return *obj_info->replay_data.get();
    }
    SessionData& AddSessionData(format::HandleId session_id)
    {
        return AddReplayData<SessionData>(session_id);
    }
    SwapchainData& AddSwapchainData(format::HandleId swapchain_id)
    {
        return AddReplayData<SwapchainData>(swapchain_id);
    }

    template <typename ReplayData>
    ReplayData& GetReplayData(format::HandleId id)
    {
        using ObjectInfo = OpenXrReplayObjectInfo<typename ReplayData::HandleType, ReplayData>;
        ObjectInfo* info = GetObjectInfo<ObjectInfo>(id, object_info_table_);
        assert(info);
        assert(info->replay_data.get());
        return *info->replay_data.get();
    }
    SessionData& GetSessionData(format::HandleId session_id)
    {
        return GetReplayData<SessionData>(session_id);
    }
    SwapchainData& GetSwapchainData(format::HandleId swapchain_id)
    {
        return GetReplayData<SwapchainData>(swapchain_id);
    }
};

template <format::ApiCallId Id>
struct CustomProcess
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase*, Args...)
    {}
};

template <>
struct CustomProcess<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDeviceKHR>
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase* consumer, Args... args)
    {
        consumer->UpdateState_xrGetVulkanGraphicsDeviceKHR(args...);
    }
};

template <>
struct CustomProcess<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDevice2KHR>
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase* consumer, Args... args)
    {
        consumer->UpdateState_xrGetVulkanGraphicsDevice2KHR(args...);
    }
};

template <>
struct CustomProcess<format::ApiCallId::ApiCall_xrCreateSession>
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase* consumer, Args... args)
    {
        consumer->UpdateState_xrCreateSession(args...);
    }
};
template <>
struct CustomProcess<format::ApiCallId::ApiCall_xrEndSession>
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase* consumer, Args... args)
    {
        consumer->UpdateState_xrEndSession(args...);
    }
};

template <>
struct CustomProcess<format::ApiCallId::ApiCall_xrBeginFrame>
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase* consumer, Args... args)
    {
        consumer->UpdateState_xrBeginFrame(args...);
    }
};

template <>
struct CustomProcess<format::ApiCallId::ApiCall_xrWaitFrame>
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase* consumer, Args... args)
    {
        consumer->UpdateState_xrWaitFrame(args...);
    }
};

template <>
struct CustomProcess<format::ApiCallId::ApiCall_xrEnumerateReferenceSpaces>
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase* consumer, Args... args)
    {
        consumer->UpdateState_xrEnumerateReferenceSpaces(args...);
    }
};

template <>
struct CustomProcess<format::ApiCallId::ApiCall_xrEnumerateSwapchainImages>
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase* consumer, Args... args)
    {
        consumer->UpdateState_xrEnumerateSwapchainImages(args...);
    }
};

template <>
struct CustomProcess<format::ApiCallId::ApiCall_xrAcquireSwapchainImage>
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase* consumer, Args... args)
    {
        consumer->UpdateState_xrAcquireSwapchainImage(args...);
    }
};

template <>
struct CustomProcess<format::ApiCallId::ApiCall_xrDestroySwapchain>
{
    template <typename... Args>
    static void UpdateState(OpenXrReplayConsumerBase* consumer, Args... args)
    {
        consumer->UpdateState_xrDestroySwapchain(args...);
    }
};

XrBaseOutStructure* OverrideOutputStructNext_XrSpaceVelocities(const XrBaseInStructure* in_next,
                                                               XrBaseOutStructure*      output_struct);
XrBaseOutStructure* OverrideOutputStructNext_XrBindingModificationsKHR(const XrBaseInStructure* in_next,
                                                                       XrBaseOutStructure*      output_struct);
XrBaseOutStructure* OverrideOutputStructNext_XrHandJointVelocitiesEXT(const XrBaseInStructure* in_next,
                                                                      XrBaseOutStructure*      output_struct);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_REPLAY_CONSUMER_BASE_H
