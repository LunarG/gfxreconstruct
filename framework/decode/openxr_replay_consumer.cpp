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
        // WIP: Properly log and this
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
    }
    else
    {
        // WIP: Properly log and this
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
    }
    else
    {
        // WIP: Properly log and this
        assert(result > 0);
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
        // WIP: Properly log and this
        assert(result > 0);
    }
}

void OpenXrReplayConsumer::MapNextStructHandles(OpenXrNextNode* next)
{
    void* value   = next->GetPointer();
    void* wrapper = next->GetMetaStructPointer();
    if ((value != nullptr) && (wrapper != nullptr))
    {
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
}

void OpenXrReplayConsumer::MapStructHandles(Decoded_XrSessionCreateInfo* wrapper)
{
    auto                 system_id_info = GetMappingInfo(wrapper->systemId, system_id_info_map_);
    XrSessionCreateInfo* value          = wrapper->decoded_value;
    value->systemId                     = system_id_info->replay_value;
    MapNextStructHandles(wrapper->next);
}

void OpenXrReplayConsumer::MapStructHandles(Decoded_XrGraphicsBindingVulkanKHR* wrapper)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrGraphicsBindingVulkanKHR* value = wrapper->decoded_value;
        value->instance                   = vulkan_replay_consumer_->MapInstance(wrapper->instance);
        value->device                     = vulkan_replay_consumer_->MapDevice(wrapper->device);
        value->physicalDevice = GetMappingInfo(wrapper->physicalDevice, vk_physical_device_info_map_)->handle;
    }
}

#endif

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
