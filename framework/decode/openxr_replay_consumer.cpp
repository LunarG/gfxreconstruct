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
#include "util/platform.h"
#include "util/defines.h"

#ifdef XR_NO_PROTOTYPES
#undef XR_NO_PROTOTYPES
#endif
#include "format/platform_types.h"
#include "openxr/openxr_platform.h"

#include "openxr_replay_consumer.h"
#include "vulkan_replay_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
OpenXrReplayConsumer::OpenXrReplayConsumer() {}

OpenXrReplayConsumer::~OpenXrReplayConsumer() {}

void OpenXrReplayConsumer::SetVulkanReplayConsumer(VulkanReplayConsumerBase* vulkan_replay_consumer)
{
    vulkan_replay_consumer_ = vulkan_replay_consumer;
}

void OpenXrReplayConsumer::Process_xrCreateApiLayerInstance(
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

    XrInstanceCreateInfo* create_info = info->GetPointer();
    assert(create_info);

    auto result = xrCreateInstance(create_info, replay_instance);
    if (result >= 0)
    {
        // Create the mapping between the recorded and replay instance handles
        AddHandleMapping(format::kNullHandleId, *instance, instance_info_map_);
    }
    else
    {
        // WIP: Properly log and handle this
        assert(result > 0);
    }
}

void OpenXrReplayConsumer::Process_xrGetSystem(const ApiCallInfo&                             call_info,
                                               XrResult                                       returnValue,
                                               format::HandleId                               instance,
                                               StructPointerDecoder<Decoded_XrSystemGetInfo>* getInfo,
                                               HandlePointerDecoder<XrSystemId>*              systemId)
{
    // WIP: Properly log and handle this
    assert(systemId->GetPointer());

    auto* instance_info = GetMappingInfo(instance, instance_info_map_);

    // Get a system that matches the request info (from capture
    XrSystemId replay_system_id;
    auto       result = xrGetSystem(instance_info->handle, getInfo->GetPointer(), &replay_system_id);
    if (result < 0)
    {
        assert("always assert: text = " == "GetSystem failed");
    }
    AddValueMapping(*systemId, replay_system_id, system_id_info_map_);
}

void OpenXrReplayConsumer::Process_xrEnumerateViewConfigurationViews(
    const ApiCallInfo&                                     call_info,
    XrResult                                               returnValue,
    format::HandleId                                       instance,
    XrSystemId                                             systemId,
    XrViewConfigurationType                                viewConfigurationType,
    uint32_t                                               viewCapacityInput,
    PointerDecoder<uint32_t>*                              viewCountOutput,
    StructPointerDecoder<Decoded_XrViewConfigurationView>* views)
{}

void OpenXrReplayConsumer::Process_xrGetVulkanGraphicsRequirementsKHR(
    const ApiCallInfo&                                             call_info,
    XrResult                                                       returnValue,
    format::HandleId                                               instance,
    XrSystemId                                                     systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements)
{
    auto* instance_info = GetMappingInfo(instance, instance_info_map_);

    // WIP: Build a table of commonly used extension entry points
    PFN_xrGetVulkanGraphicsRequirementsKHR getVulkanGraphicsRequirementsKHR;

    xrGetInstanceProcAddr(instance_info->handle,
                          "xrGetVulkanGraphicsRequirementsKHR",
                          (PFN_xrVoidFunction*)(&getVulkanGraphicsRequirementsKHR));
    // WIP: Properly compare/adjust? The graphic requirement from the playback runtime with the
    //      captured graphicsRequirements
    // WIP: Properly compare/adjust systemId on playback and runtime
    XrGraphicsRequirementsVulkanKHR dummy{ XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR };
    auto                            system_id_mapping = GetMappingInfo(systemId, system_id_info_map_);
    auto result = getVulkanGraphicsRequirementsKHR(instance_info->handle, system_id_mapping->replay_value, &dummy);
    if (result < 0)
    {
        assert("always assert: text = " == "GetVulkanRequirements failed");
    }
}

void OpenXrReplayConsumer::Process_xrGetVulkanGraphicsDeviceKHR(
    const ApiCallInfo&                      call_info,
    XrResult                                returnValue,
    format::HandleId                        instance,
    XrSystemId                              systemId,
    format::HandleId                        vkInstance,
    HandlePointerDecoder<VkPhysicalDevice>* vkPhysicalDevice)
{
    // Map the inputs
    auto*      instance_info      = GetMappingInfo(instance, instance_info_map_);
    auto*      system_id_info     = GetMappingInfo(systemId, system_id_info_map_);
    VkInstance replay_vk_instance = vulkan_replay_consumer_->MapInstance(vkInstance);

    // WIP: Properly log and handle this
    assert(instance_info);
    assert(system_id_info);
    assert(replay_vk_instance != VK_NULL_HANDLE);

    // Set up the output
    if (!vkPhysicalDevice->IsNull())
    {
        vkPhysicalDevice->SetHandleLength(1);
    }
    VkPhysicalDevice* replay_device = vkPhysicalDevice->GetHandlePointer();

    // WIP: Build a table of commonly used extension entry points
    PFN_xrGetVulkanGraphicsDeviceKHR getVulkanGraphicsDeviceKHR;
    xrGetInstanceProcAddr(
        instance_info->handle, "xrGetVulkanGraphicsDeviceKHR", (PFN_xrVoidFunction*)(&getVulkanGraphicsDeviceKHR));

    auto result = getVulkanGraphicsDeviceKHR(
        instance_info->handle, system_id_info->replay_value, replay_vk_instance, replay_device);

    // Create result mapping
    if (result >= 0)
    {
        // Create the mapping between the recorded and replay instance handles
        AddHandleMapping(format::kNullHandleId, *vkPhysicalDevice, vk_physical_device_info_map_);
    }
    else
    {
        // WIP: Properly log and handle this
        assert(result > 0);
    }
}

#if 1
void OpenXrReplayConsumer::Process_xrCreateSession(const ApiCallInfo&                                 call_info,
                                                   XrResult                                           returnValue,
                                                   gfxrecon::format::HandleId                         instance,
                                                   StructPointerDecoder<Decoded_XrSessionCreateInfo>* info,
                                                   HandlePointerDecoder<XrSession>*                   session)
{
    if (!session->IsNull())
    {
        session->SetHandleLength(1);
    }
    XrSession* replay_session = session->GetHandlePointer();

    XrSessionCreateInfo* create_info = info->GetPointer();
    assert(create_info);

    auto* instance_info = GetMappingInfo(instance, instance_info_map_);
    // WIP: Properly log and handle this
    assert(instance_info);

    // Find and translate the graphics binding
    MapStructHandles(info->GetMetaStructPointer());

    // XrSessionCreateInfo
    auto result = xrCreateSession(instance_info->handle, create_info, replay_session);
    if (result >= 0)
    {
        AddHandleMapping(instance, *session, session_info_map_);
        AddSessionData(*replay_session);
    }
    else
    {
        // WIP: Properly log and handle this
        assert(result > 0);
    }
}
void OpenXrReplayConsumer::Process_xrCreateSwapchain(const ApiCallInfo&                                   call_info,
                                                     XrResult                                             returnValue,
                                                     format::HandleId                                     session,
                                                     StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* createInfo,
                                                     HandlePointerDecoder<XrSwapchain>*                   swapchain)
{

    if (!swapchain->IsNull())
    {
        swapchain->SetHandleLength(1);
    }
    XrSwapchain* replay_swapchain = swapchain->GetHandlePointer();

    XrSwapchainCreateInfo* create_info = createInfo->GetPointer();
    assert(create_info);

    auto* session_info = GetMappingInfo(session, session_info_map_);
    // WIP: Properly log and handle this
    assert(session_info);

    auto result = xrCreateSwapchain(session_info->handle, create_info, replay_swapchain);
    if (result >= 0)
    {
        AddHandleMapping(session, *swapchain, swapchain_info_map_);
        AddSwapchainData(*replay_swapchain);
    }
    else
    {
        // WIP: Properly log and handle this
        assert(result >= 0);
    }
}
void OpenXrReplayConsumer::Process_xrAcquireSwapchainImage(
    const ApiCallInfo&                                         call_info,
    XrResult                                                   returnValue,
    format::HandleId                                           swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageAcquireInfo>* acquireInfo,
    PointerDecoder<uint32_t>*                                  index)
{
    auto swapchain_info = GetMappingInfo(swapchain, swapchain_info_map_);
    // WIP: Properly log and handle this
    assert(swapchain_info);
    XrSwapchain replay_handle = swapchain_info->handle;

    // WIP add handle mapping for acquireInfo, though only needed for non-null next

    if (!index->IsNull())
    {
        index->AllocateOutputData(1);
    }
    uint32_t* replay_index = index->GetOutputPointer();

    auto result = xrAcquireSwapchainImage(replay_handle, acquireInfo->GetPointer(), replay_index);

    if (result >= 0)
    {
        // Need to map indexes between capture and replay
        auto& swapchain_data                           = GetSwapchainData(replay_handle);
        swapchain_data.index_map[*index->GetPointer()] = *replay_index;
    }
    else
    {
        // WIP: Properly log and handle this
        assert(result >= 0);
    }
}

void OpenXrReplayConsumer::Process_xrWaitSwapchainImage(
    const ApiCallInfo&                                      call_info,
    XrResult                                                returnValue,
    format::HandleId                                        swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageWaitInfo>* waitInfo)
{
    auto swapchain_info = GetMappingInfo(swapchain, swapchain_info_map_);
    // WIP: Properly log and handle this
    assert(swapchain_info);

    if (returnValue == XR_SUCCESS)
    {
        // Only attempt to wait if the captured wait succeeded
        assert(waitInfo);

        // WIP: Call MapStructHandles for wait_info->next mapping (extensions only)
        XrSwapchainImageWaitInfo* wait_info = waitInfo->GetPointer();
        // WIP: Properly log and handle this
        assert(wait_info);
        XrResult result;

        // WIP: Add retry limit
        do
        {
            result = xrWaitSwapchainImage(swapchain_info->handle, wait_info);
        } while (XR_SUCCEEDED(result) && (result == XR_TIMEOUT_EXPIRED));

        // WIP: Properly log and handle this
        assert(result == XR_SUCCESS);
    }
}

void OpenXrReplayConsumer::Process_xrReleaseSwapchainImage(
    const ApiCallInfo&                                         call_info,
    XrResult                                                   returnValue,
    format::HandleId                                           swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo)
{
    auto swapchain_info = GetMappingInfo(swapchain, swapchain_info_map_);
    // WIP: Properly log and handle this
    assert(swapchain_info);

    // NULL release value is valid
    XrSwapchainImageReleaseInfo* release_info = nullptr;
    if (releaseInfo)
    {
        release_info = releaseInfo->GetPointer();
    }

    if (release_info)
    {
        // WIP: MapStructHandles for next, extensions only
    }

    auto result = xrReleaseSwapchainImage(swapchain_info->handle, release_info);

    if (result < 0)
    {
        // WIP: Properly log and handle this
        assert(result > 0);
    }
}

void OpenXrReplayConsumer::Process_xrPollEvent(const ApiCallInfo&                               call_info,
                                               XrResult                                         returnValue,
                                               format::HandleId                                 instance,
                                               StructPointerDecoder<Decoded_XrEventDataBuffer>* eventData)
{
    if (returnValue != XR_SUCCESS)
    {
        // Capture did not return an event, skip
        return;
    }

    auto* instance_info = GetMappingInfo(instance, instance_info_map_);
    // WIP: Properly log and handle this
    assert(instance_info);

    XrEventDataBuffer* capture_event = eventData->GetPointer();

    XrEventDataBuffer replay_event;
    // WIP: Put this constant somewhere interesting
    const uint32_t kRetryLimit = 10000;
    uint32_t       retry_count = 0;

    do
    {
        replay_event = XrEventDataBuffer{ XR_TYPE_EVENT_DATA_BUFFER };
        auto result  = xrPollEvent(instance_info->handle, &replay_event);
        retry_count++;

        if (capture_event->type != replay_event.type)
        {
            if (result == XR_SUCCESS)
            {
                GFXRECON_LOG_WARNING("Skipping event %u", replay_event.type);
            }
            else
            {
                // Yield and retry
                std::this_thread::sleep_for(std::chrono::nanoseconds(1));
            }
        }
    } while ((retry_count < kRetryLimit) && capture_event->type != replay_event.type);

    if (capture_event->type != replay_event.type)
    {
        assert("always assert: text=" == "event not found");
    }
}
void OpenXrReplayConsumer::Process_xrBeginSession(const ApiCallInfo&                                call_info,
                                                  XrResult                                          returnValue,
                                                  format::HandleId                                  session,
                                                  StructPointerDecoder<Decoded_XrSessionBeginInfo>* beginInfo)
{
    auto* session_info = GetMappingInfo(session, session_info_map_);
    // WIP: Properly log and handle this
    assert(session_info);

    XrSessionBeginInfo* begin_info = beginInfo->GetPointer();
    assert(begin_info);

    auto result = xrBeginSession(session_info->handle, begin_info);

    if (result < 0)
    {
        // WIP: Properly log and handle this
        assert(result > 0);
    }
}

void OpenXrReplayConsumer::Process_xrWaitFrame(const ApiCallInfo&                             call_info,
                                               XrResult                                       returnValue,
                                               format::HandleId                               session,
                                               StructPointerDecoder<Decoded_XrFrameWaitInfo>* frameWaitInfo,
                                               StructPointerDecoder<Decoded_XrFrameState>*    frameState)
{
    auto* session_info = GetMappingInfo(session, session_info_map_);
    // WIP: Properly log and handle this
    assert(session_info);

    XrFrameWaitInfo* capture_frame_wait_info = frameWaitInfo->GetPointer();

    XrFrameState replay_frame_state = { XR_TYPE_FRAME_STATE };
    auto         result             = xrWaitFrame(session_info->handle, capture_frame_wait_info, &replay_frame_state);
    if (result < 0)
    {
        // WIP: Properly log and handle this
        assert("always assert: text=" == "wait frame failed");
    }
    else
    {
        // Store wait frame information for this session if needed later
        SessionData& session_data      = GetSessionData(session_info->handle);
        session_data.last_display_time = replay_frame_state.predictedDisplayTime;
    }
}

void OpenXrReplayConsumer::Process_xrBeginFrame(const ApiCallInfo&                              call_info,
                                                XrResult                                        returnValue,
                                                format::HandleId                                session,
                                                StructPointerDecoder<Decoded_XrFrameBeginInfo>* frameBeginInfo)
{
    auto* session_info = GetMappingInfo(session, session_info_map_);
    // WIP: Properly log and handle this
    assert(session_info);

    XrFrameBeginInfo* capture_frame_begin_info = frameBeginInfo->GetPointer();
    auto              result                   = xrBeginFrame(session_info->handle, capture_frame_begin_info);

    if (result < 0)
    {
        // WIP: Properly log and handle this
        assert("always assert: text=" == "begin frame failed");
    }
}

void OpenXrReplayConsumer::Process_xrEndFrame(const ApiCallInfo&                            call_info,
                                              XrResult                                      returnValue,
                                              format::HandleId                              session,
                                              StructPointerDecoder<Decoded_XrFrameEndInfo>* frameEndInfo)
{
    auto* session_info = GetMappingInfo(session, session_info_map_);
    // WIP: Properly log and handle this
    assert(session_info);
    XrSession replay_session = session_info->handle;

    MapStructHandles(frameEndInfo->GetMetaStructPointer());
    XrFrameEndInfo replay_end_info = *frameEndInfo->GetPointer();
    replay_end_info.displayTime    = GetSessionData(replay_session).last_display_time;
    auto result                    = xrEndFrame(replay_session, &replay_end_info);

    if (result < 0)
    {
        // WIP: Properly log and handle this
        assert("always assert: text=" == "end frame failed");
    }
}

void OpenXrReplayConsumer::Process_xrEnumerateReferenceSpaces(const ApiCallInfo&                    call_info,
                                                              XrResult                              returnValue,
                                                              format::HandleId                      session,
                                                              uint32_t                              spaceCapacityInput,
                                                              PointerDecoder<uint32_t>*             spaceCountOutput,
                                                              PointerDecoder<XrReferenceSpaceType>* spaces)
{
    auto* session_info = GetMappingInfo(session, session_info_map_);
    // WIP: Properly log and handle this
    assert(session_info);

    // Only make the call when we're going to look at the results
    if (spaceCapacityInput)
    {
        const XrSession replay_session = session_info->handle;
        uint32_t*       output_count   = spaceCountOutput->GetPointer();
        if (output_count && *output_count)
        {
            uint32_t replay_req = 0;
            xrEnumerateReferenceSpaces(replay_session, 0, &replay_req, nullptr);
            std::vector<XrReferenceSpaceType> replay_reference_spaces(replay_req);
            uint32_t                          replay_count = 0;
            xrEnumerateReferenceSpaces(replay_session, replay_req, &replay_count, replay_reference_spaces.data());

            SessionData& session_data = GetSessionData(replay_session);

            ReferenceSpaceSet& runtime_spaces = session_data.reference_spaces;
            runtime_spaces.clear();
            for (const auto& space : replay_reference_spaces)
            {
                runtime_spaces.insert(space);
            }

            // Don't check whether a captured space type is missing, only report if/when a space is being created
        }
    }
}

void OpenXrReplayConsumer::Process_xrCreateReferenceSpace(
    const ApiCallInfo&                                        call_info,
    XrResult                                                  returnValue,
    format::HandleId                                          session,
    StructPointerDecoder<Decoded_XrReferenceSpaceCreateInfo>* createInfo,
    HandlePointerDecoder<XrSpace>*                            space)
{
    auto* session_info = GetMappingInfo(session, session_info_map_);
    // WIP: Properly log and handle this
    assert(session_info);

    if (!space->IsNull())
    {
        space->SetHandleLength(1);
    }
    XrSpace* replay_space = space->GetHandlePointer();

    MapStructHandles(createInfo->GetMetaStructPointer());

    auto result = xrCreateReferenceSpace(session_info->handle, createInfo->GetPointer(), replay_space);

    if (result >= 0)
    {
        // Create the mapping between the recorded and replay instance handles
        AddHandleMapping(session, *space, space_info_map_);
    }
    else
    {
        // WIP: Properly log and handle this
        assert(result > 0);
    }
}

void OpenXrReplayConsumer::MapNextStructHandles(OpenXrNextNode* next)
{
    if (!next)
        return; // Don't require callers to validate next

    void* value   = next->GetPointer();
    void* wrapper = next->GetMetaStructPointer();

    if (!value || !wrapper)
    {
        return;
    }

    const XrBaseInStructure* base = reinterpret_cast<const XrBaseInStructure*>(value);
    switch (base->type)
    {
        default:
            // TODO: Report or raise fatal error for unrecongized sType?
            assert("always assert: text=" == "unknown struct type");
            break;
        case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingVulkanKHR*>(wrapper));
    }
}

void OpenXrReplayConsumer::MapStructHandles(Decoded_XrSessionCreateInfo* wrapper)
{
    assert(wrapper);
    MapNextStructHandles(wrapper->next);

    auto                 system_id_info = GetMappingInfo(wrapper->systemId, system_id_info_map_);
    XrSessionCreateInfo* value          = wrapper->decoded_value;
    value->systemId                     = system_id_info->replay_value;
}

void OpenXrReplayConsumer::MapStructHandles(Decoded_XrReferenceSpaceCreateInfo* wrapper)
{
    assert(wrapper);
    MapNextStructHandles(wrapper->next);
}

void OpenXrReplayConsumer::MapStructHandles(Decoded_XrFrameEndInfo* wrapper)
{
    assert(wrapper);
    MapNextStructHandles(wrapper->next);

    XrFrameEndInfo* value = wrapper->decoded_value;
    MapStructHandles(value->layerCount, wrapper->layers->GetMetaStructPointer());
}

void OpenXrReplayConsumer::MapStructHandles(uint32_t layer_count, Decoded_XrCompositionLayerBaseHeader** layer_wrappers)
{
    if (!layer_wrappers || (layer_count == 0))
    {
        return;
    }

    for (uint32_t layer = 0; layer < layer_count; layer++)
    {
        Decoded_XrCompositionLayerBaseHeader* base_wrapper = layer_wrappers[layer];
        if (!base_wrapper)
        {
            continue;
        }
        XrCompositionLayerBaseHeader* base_value = base_wrapper->decoded_value;
        switch (base_value->type)
        {
            default:
                // WIP: Properly log and handle this
                assert("always assert: text = " == "Unknown composition layer type");
                break;
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
                MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerProjection*>(base_wrapper));
                break;
        }
    }
}

void OpenXrReplayConsumer::MapStructHandles(Decoded_XrCompositionLayerProjection* wrapper)
{
    assert(wrapper);
    MapNextStructHandles(wrapper->next);

    XrCompositionLayerProjection* value = wrapper->decoded_value;
    if (!value)
    {
        return;
    }

    auto* space_info = GetMappingInfo(wrapper->space, space_info_map_);
    // WIP: Properly log and handle this
    assert(space_info);

    value->space = space_info->handle;

    if (wrapper->views)
    {
        for (uint32_t view = 0; view < value->viewCount; view++)
        {
            MapStructHandles(wrapper->views[view].GetMetaStructPointer());
        }
    }
}

void OpenXrReplayConsumer::MapStructHandles(Decoded_XrCompositionLayerProjectionView* wrapper)
{
    assert(wrapper);
    MapNextStructHandles(wrapper->next);

    if (wrapper->subImage)
    {
        MapStructHandles(wrapper->subImage);
    }
}

void OpenXrReplayConsumer::MapStructHandles(Decoded_XrSwapchainSubImage* wrapper)
{
    assert(wrapper);

    auto* value = wrapper->decoded_value;
    if (!value)
    {
        return;
    }

    auto replay_swapchain = GetMappingInfo(wrapper->swapchain, swapchain_info_map_);
    // WIP: Properly log and handle this
    assert(replay_swapchain);

    value->swapchain = replay_swapchain->handle;
}

void OpenXrReplayConsumer::MapStructHandles(Decoded_XrGraphicsBindingVulkanKHR* wrapper)
{
    assert(wrapper);
    MapNextStructHandles(wrapper->next);

    XrGraphicsBindingVulkanKHR* value = wrapper->decoded_value;
    if (!value)
    {
        return;
    }

    value->instance       = vulkan_replay_consumer_->MapInstance(wrapper->instance);
    value->device         = vulkan_replay_consumer_->MapDevice(wrapper->device);
    value->physicalDevice = GetMappingInfo(wrapper->physicalDevice, vk_physical_device_info_map_)->handle;
}

#endif

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
