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

#ifndef GFXRECON_DECODE_OPENXR_JSON_CONSUMER_BASE_H
#define GFXRECON_DECODE_OPENXR_JSON_CONSUMER_BASE_H

#if ENABLE_OPENXR_SUPPORT
#include <unordered_map>
#include <unordered_set>
#include "generated/generated_openxr_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
class VulkanReplayConsumerBase;

class OpenXrReplayConsumer : public OpenXrConsumer
{
  public:
    OpenXrReplayConsumer();
    ~OpenXrReplayConsumer() override;

    void SetVulkanReplayConsumer(VulkanReplayConsumerBase* vulkan_replay_consumer);

    virtual void Process_xrCreateApiLayerInstance(const ApiCallInfo&                                  call_info,
                                                  XrResult                                            returnValue,
                                                  StructPointerDecoder<Decoded_XrInstanceCreateInfo>* info,
                                                  StructPointerDecoder<Decoded_XrApiLayerCreateInfo>* apiLayerInfo,
                                                  HandlePointerDecoder<XrInstance>*) override;
    virtual void Process_xrGetSystem(const ApiCallInfo&                             call_info,
                                     XrResult                                       returnValue,
                                     format::HandleId                               instance,
                                     StructPointerDecoder<Decoded_XrSystemGetInfo>* getInfo,
                                     HandlePointerDecoder<XrSystemId>*              systemId) override;
    virtual void
                 Process_xrEnumerateViewConfigurationViews(const ApiCallInfo&        call_info,
                                                           XrResult                  returnValue,
                                                           format::HandleId          instance,
                                                           XrSystemId                systemId,
                                                           XrViewConfigurationType   viewConfigurationType,
                                                           uint32_t                  viewCapacityInput,
                                                           PointerDecoder<uint32_t>* viewCountOutput,
                                                           StructPointerDecoder<Decoded_XrViewConfigurationView>* views) override;
    virtual void Process_xrGetVulkanGraphicsRequirementsKHR(
        const ApiCallInfo&                                             call_info,
        XrResult                                                       returnValue,
        format::HandleId                                               instance,
        XrSystemId                                                     systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements) override;
    virtual void
    Process_xrGetVulkanGraphicsDeviceKHR(const ApiCallInfo&                      call_info,
                                         XrResult                                returnValue,
                                         format::HandleId                        instance,
                                         XrSystemId                              systemId,
                                         format::HandleId                        vkInstance,
                                         HandlePointerDecoder<VkPhysicalDevice>* vkPhysicalDevice) override;

    virtual void Process_xrCreateSession(const ApiCallInfo&         call_info,
                                         XrResult                   returnValue,
                                         gfxrecon::format::HandleId instance,
                                         StructPointerDecoder<Decoded_XrSessionCreateInfo>*,
                                         HandlePointerDecoder<XrSession>*) override;
    virtual void Process_xrCreateSwapchain(const ApiCallInfo&                                   call_info,
                                           XrResult                                             returnValue,
                                           format::HandleId                                     session,
                                           StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* createInfo,
                                           HandlePointerDecoder<XrSwapchain>*                   swapchain) override;
    virtual void Process_xrAcquireSwapchainImage(const ApiCallInfo&                                         call_info,
                                                 XrResult                                                   returnValue,
                                                 format::HandleId                                           swapchain,
                                                 StructPointerDecoder<Decoded_XrSwapchainImageAcquireInfo>* acquireInfo,
                                                 PointerDecoder<uint32_t>* index) override;

    virtual void
    Process_xrWaitSwapchainImage(const ApiCallInfo&                                      call_info,
                                 XrResult                                                returnValue,
                                 format::HandleId                                        swapchain,
                                 StructPointerDecoder<Decoded_XrSwapchainImageWaitInfo>* waitInfo) override;

    virtual void
    Process_xrReleaseSwapchainImage(const ApiCallInfo&                                         call_info,
                                    XrResult                                                   returnValue,
                                    format::HandleId                                           swapchain,
                                    StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo) override;

    virtual void Process_xrPollEvent(const ApiCallInfo&                               call_info,
                                     XrResult                                         returnValue,
                                     format::HandleId                                 instance,
                                     StructPointerDecoder<Decoded_XrEventDataBuffer>* eventData) override;

    virtual void Process_xrBeginSession(const ApiCallInfo&                                call_info,
                                        XrResult                                          returnValue,
                                        format::HandleId                                  session,
                                        StructPointerDecoder<Decoded_XrSessionBeginInfo>* beginInfo) override;
    virtual void Process_xrWaitFrame(const ApiCallInfo&                             call_info,
                                     XrResult                                       returnValue,
                                     format::HandleId                               session,
                                     StructPointerDecoder<Decoded_XrFrameWaitInfo>* frameWaitInfo,
                                     StructPointerDecoder<Decoded_XrFrameState>*    frameState) override;

    virtual void Process_xrBeginFrame(const ApiCallInfo&                              call_info,
                                      XrResult                                        returnValue,
                                      format::HandleId                                session,
                                      StructPointerDecoder<Decoded_XrFrameBeginInfo>* frameBeginInfo) override;

    virtual void Process_xrEndFrame(const ApiCallInfo&                            call_info,
                                    XrResult                                      returnValue,
                                    format::HandleId                              session,
                                    StructPointerDecoder<Decoded_XrFrameEndInfo>* frameEndInfo) override;

    virtual void Process_xrEnumerateReferenceSpaces(const ApiCallInfo&                    call_info,
                                                    XrResult                              returnValue,
                                                    format::HandleId                      session,
                                                    uint32_t                              spaceCapacityInput,
                                                    PointerDecoder<uint32_t>*             spaceCountOutput,
                                                    PointerDecoder<XrReferenceSpaceType>* spaces) override;

    virtual void Process_xrCreateReferenceSpace(const ApiCallInfo&                                        call_info,
                                                XrResult                                                  returnValue,
                                                format::HandleId                                          session,
                                                StructPointerDecoder<Decoded_XrReferenceSpaceCreateInfo>* createInfo,
                                                HandlePointerDecoder<XrSpace>* space) override;

  private:
    // WIP Refactor out of consumer object to something like the vulkan approach
    void MapNextStructHandles(OpenXrNextNode* next);
    void MapStructHandles(Decoded_XrSessionCreateInfo* wrapper);
    void MapStructHandles(Decoded_XrReferenceSpaceCreateInfo* wrapper);
    void MapStructHandles(Decoded_XrFrameEndInfo* wrapper);
    void MapStructHandles(uint32_t layer_count, Decoded_XrCompositionLayerBaseHeader** layer_wrappers);
    void MapStructHandles(Decoded_XrCompositionLayerProjection* wrapper);
    void MapStructHandles(Decoded_XrCompositionLayerProjectionView* wrapper);
    void MapStructHandles(Decoded_XrSwapchainSubImage* wrapper);
    void MapStructHandles(Decoded_XrGraphicsBindingVulkanKHR* wrapper);

    template <typename T>
    struct OpenXrObjectInfo
    {
        using HandleType = T;
        // Standard info stored for all XR objects.
        HandleType       handle{ XR_NULL_HANDLE };            // Handle created for the object during replay.
        format::HandleId capture_id{ format::kNullHandleId }; // ID assigned to the object at capture.
        format::HandleId parent_id{ format::kNullHandleId };  // ID of the object's parent instance/device object.
    };

    template <typename T>
    struct OpenXrValueInfo
    {
        using ValueType = T;
        ValueType replay_value;  // Value returned for during replay.
        ValueType capture_value; // Value returned at capture.
    };

    template <typename HandleType>
    using HandleMap = std::unordered_map<format::HandleId, OpenXrObjectInfo<HandleType>>;
    template <typename ValueType>
    using ValueMap = std::unordered_map<ValueType, OpenXrValueInfo<ValueType>>;

    HandleMap<XrInstance>       instance_info_map_;
    HandleMap<XrSession>        session_info_map_;
    HandleMap<XrSwapchain>      swapchain_info_map_;
    ValueMap<XrSystemId>        system_id_info_map_;
    HandleMap<VkPhysicalDevice> vk_physical_device_info_map_;
    HandleMap<XrSpace>          space_info_map_;

    // TODO: Should DRY the handle remapping code with the Vulkan side at least.
    template <typename HandleDecoder, typename Map>
    void AddHandleMapping(format::HandleId parent, HandleDecoder& handle_decoder, Map& map)
    {
        using HandleType               = typename HandleDecoder::HandleType;
        using Info                     = OpenXrObjectInfo<HandleType>;
        format::HandleId capture_id    = *handle_decoder.GetPointer();
        HandleType       replay_handle = *handle_decoder.GetHandlePointer();
        map.insert(std::make_pair(capture_id, Info{ replay_handle, capture_id, parent }));
    }

    template <typename PointerDecoder, typename ValueType, typename Map>
    void AddValueMapping(PointerDecoder& pointer_decoder, ValueType& replay_value, Map& map)
    {
        using Info                     = OpenXrValueInfo<ValueType>;
        const ValueType& capture_value = *pointer_decoder.GetPointer();
        map.insert(std::make_pair(capture_value, Info{ replay_value, capture_value }));
    }

    template <typename Map, typename InfoType = typename Map::mapped_type>
    InfoType* GetMappingInfo(typename Map::key_type key, Map& map)
    {
        InfoType* info     = nullptr;
        auto      found_it = map.find(key);
        if (found_it != map.end())
        {
            info = &found_it->second;
        }
        return info;
    }

    using ReferenceSpaceSet = std::unordered_set<XrReferenceSpaceType>;
    struct SessionData
    {
        ReferenceSpaceSet reference_spaces;
        XrTime            last_display_time = XrTime();
    };

    struct SwapchainData
    {
        std::unordered_map<uint32_t, uint32_t> index_map;
    };

    template <typename Handle, typename DataMap>
    static void AddHandleData(Handle handle, DataMap& data_map)
    {
        auto insert_info = data_map.insert(std::make_pair(handle, typename DataMap::mapped_type()));
        assert(insert_info.second);
    }

    template <typename Handle, typename DataMap, typename Data = typename DataMap::mapped_type>
    static Data& GetHandleData(Handle handle, DataMap& data_map)
    {
        auto find_it = data_map.find(handle);
        assert(find_it != data_map.end());
        return find_it->second;
    }

    void AddSessionData(XrSession session) { AddHandleData(session, session_data_); }
    void AddSwapchainData(XrSwapchain swapchain) { AddHandleData(swapchain, swapchain_data_); }

    SessionData&   GetSessionData(XrSession session) { return GetHandleData(session, session_data_); }
    SwapchainData& GetSwapchainData(XrSwapchain swapchain) { return GetHandleData(swapchain, swapchain_data_); }

    VulkanReplayConsumerBase* vulkan_replay_consumer_ = nullptr;

    std::unordered_map<XrSession, SessionData>     session_data_;
    std::unordered_map<XrSwapchain, SwapchainData> swapchain_data_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_JSON_CONSUMER_BASE_H
