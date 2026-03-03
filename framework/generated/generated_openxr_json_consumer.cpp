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

#include "util/defines.h"
#include "generated/generated_openxr_json_consumer.h"
#include "decode/custom_openxr_struct_to_json.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::FieldToJson;
using util::HandleToJson;
using util::Bool32ToJson;

void OpenXrExportJsonConsumer::Process_xrDestroyInstance(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyInstance");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetInstanceProperties(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrInstanceProperties>* instanceProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetInstanceProperties");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["instanceProperties"], instanceProperties);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrResultToString(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrResult                                    value,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrResultToString");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        args["value"] = value;
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrStructureTypeToString(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrStructureType                             value,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrStructureTypeToString");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        args["value"] = value;
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSystem(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrSystemGetInfo>* getInfo,
    HandlePointerDecoder<XrSystemId>*           systemId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSystem");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["getInfo"], getInfo);
        HandleToJson(args["systemId"], systemId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSystemProperties(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrSystemProperties>* properties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSystemProperties");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["properties"], properties);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateEnvironmentBlendModes(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    environmentBlendModeCapacityInput,
    PointerDecoder<uint32_t>*                   environmentBlendModeCountOutput,
    PointerDecoder<XrEnvironmentBlendMode>*     environmentBlendModes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateEnvironmentBlendModes");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        args["viewConfigurationType"] = viewConfigurationType;
        FieldToJson(args["environmentBlendModeCapacityInput"], environmentBlendModeCapacityInput);
        FieldToJson(args["environmentBlendModeCountOutput"], environmentBlendModeCountOutput);
        FieldToJson(args["environmentBlendModes"], environmentBlendModes);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrSessionCreateInfo>* createInfo,
    HandlePointerDecoder<XrSession>*            session)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSession");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["session"], session);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySession");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateReferenceSpaces(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    spaceCapacityInput,
    PointerDecoder<uint32_t>*                   spaceCountOutput,
    PointerDecoder<XrReferenceSpaceType>*       spaces)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateReferenceSpaces");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["spaceCapacityInput"], spaceCapacityInput);
        FieldToJson(args["spaceCountOutput"], spaceCountOutput);
        FieldToJson(args["spaces"], spaces);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateReferenceSpace(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrReferenceSpaceCreateInfo>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateReferenceSpace");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["space"], space);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetReferenceSpaceBoundsRect(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrReferenceSpaceType                        referenceSpaceType,
    StructPointerDecoder<Decoded_XrExtent2Df>*  bounds)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetReferenceSpaceBoundsRect");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        args["referenceSpaceType"] = referenceSpaceType;
        FieldToJson(args["bounds"], bounds);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateActionSpace(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionSpaceCreateInfo>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateActionSpace");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["space"], space);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrLocateSpace(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    format::HandleId                            baseSpace,
    XrTime                                      time,
    StructPointerDecoder<Decoded_XrSpaceLocation>* location)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrLocateSpace");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space);
        HandleToJson(args["baseSpace"], baseSpace);
        FieldToJson(args["time"], time);
        FieldToJson(args["location"], location);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySpace(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySpace");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateViewConfigurations(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    uint32_t                                    viewConfigurationTypeCapacityInput,
    PointerDecoder<uint32_t>*                   viewConfigurationTypeCountOutput,
    PointerDecoder<XrViewConfigurationType>*    viewConfigurationTypes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateViewConfigurations");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["viewConfigurationTypeCapacityInput"], viewConfigurationTypeCapacityInput);
        FieldToJson(args["viewConfigurationTypeCountOutput"], viewConfigurationTypeCountOutput);
        FieldToJson(args["viewConfigurationTypes"], viewConfigurationTypes);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetViewConfigurationProperties(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    XrViewConfigurationType                     viewConfigurationType,
    StructPointerDecoder<Decoded_XrViewConfigurationProperties>* configurationProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetViewConfigurationProperties");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        args["viewConfigurationType"] = viewConfigurationType;
        FieldToJson(args["configurationProperties"], configurationProperties);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateViewConfigurationViews(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewCapacityInput,
    PointerDecoder<uint32_t>*                   viewCountOutput,
    StructPointerDecoder<Decoded_XrViewConfigurationView>* views)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateViewConfigurationViews");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        args["viewConfigurationType"] = viewConfigurationType;
        FieldToJson(args["viewCapacityInput"], viewCapacityInput);
        FieldToJson(args["viewCountOutput"], viewCountOutput);
        FieldToJson(args["views"], views);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateSwapchainFormats(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    formatCapacityInput,
    PointerDecoder<uint32_t>*                   formatCountOutput,
    PointerDecoder<int64_t>*                    formats)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateSwapchainFormats");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["formatCapacityInput"], formatCapacityInput);
        FieldToJson(args["formatCountOutput"], formatCountOutput);
        FieldToJson(args["formats"], formats);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSwapchain(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* createInfo,
    HandlePointerDecoder<XrSwapchain>*          swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSwapchain");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["swapchain"], swapchain);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySwapchain(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySwapchain");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrAcquireSwapchainImage(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageAcquireInfo>* acquireInfo,
    PointerDecoder<uint32_t>*                   index)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrAcquireSwapchainImage");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["acquireInfo"], acquireInfo);
        FieldToJson(args["index"], index);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrWaitSwapchainImage(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageWaitInfo>* waitInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrWaitSwapchainImage");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["waitInfo"], waitInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrReleaseSwapchainImage(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrReleaseSwapchainImage");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["releaseInfo"], releaseInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrBeginSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSessionBeginInfo>* beginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrBeginSession");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["beginInfo"], beginInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEndSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEndSession");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrRequestExitSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrRequestExitSession");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrWaitFrame(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFrameWaitInfo>* frameWaitInfo,
    StructPointerDecoder<Decoded_XrFrameState>* frameState)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrWaitFrame");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["frameWaitInfo"], frameWaitInfo);
        FieldToJson(args["frameState"], frameState);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrBeginFrame(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFrameBeginInfo>* frameBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrBeginFrame");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["frameBeginInfo"], frameBeginInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEndFrame(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFrameEndInfo>* frameEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEndFrame");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["frameEndInfo"], frameEndInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrLocateViews(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrViewLocateInfo>* viewLocateInfo,
    StructPointerDecoder<Decoded_XrViewState>*  viewState,
    uint32_t                                    viewCapacityInput,
    PointerDecoder<uint32_t>*                   viewCountOutput,
    StructPointerDecoder<Decoded_XrView>*       views)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrLocateViews");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["viewLocateInfo"], viewLocateInfo);
        FieldToJson(args["viewState"], viewState);
        FieldToJson(args["viewCapacityInput"], viewCapacityInput);
        FieldToJson(args["viewCountOutput"], viewCountOutput);
        FieldToJson(args["views"], views);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrStringToPath(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StringDecoder*                              pathString,
    HandlePointerDecoder<XrPath>*               path)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrStringToPath");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pathString"], pathString);
        HandleToJson(args["path"], path);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPathToString(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            path,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPathToString");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["path"], path);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateActionSet(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrActionSetCreateInfo>* createInfo,
    HandlePointerDecoder<XrActionSet>*          actionSet)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateActionSet");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["actionSet"], actionSet);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyActionSet(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            actionSet)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyActionSet");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["actionSet"], actionSet);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateAction(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            actionSet,
    StructPointerDecoder<Decoded_XrActionCreateInfo>* createInfo,
    HandlePointerDecoder<XrAction>*             action)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateAction");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["actionSet"], actionSet);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["action"], action);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyAction(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            action)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyAction");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["action"], action);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSuggestInteractionProfileBindings(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrInteractionProfileSuggestedBinding>* suggestedBindings)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSuggestInteractionProfileBindings");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["suggestedBindings"], suggestedBindings);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrAttachSessionActionSets(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSessionActionSetsAttachInfo>* attachInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrAttachSessionActionSets");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["attachInfo"], attachInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetCurrentInteractionProfile(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelUserPath,
    StructPointerDecoder<Decoded_XrInteractionProfileState>* interactionProfile)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetCurrentInteractionProfile");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["topLevelUserPath"], topLevelUserPath);
        FieldToJson(args["interactionProfile"], interactionProfile);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetActionStateBoolean(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
    StructPointerDecoder<Decoded_XrActionStateBoolean>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetActionStateBoolean");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["getInfo"], getInfo);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetActionStateFloat(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
    StructPointerDecoder<Decoded_XrActionStateFloat>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetActionStateFloat");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["getInfo"], getInfo);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetActionStateVector2f(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
    StructPointerDecoder<Decoded_XrActionStateVector2f>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetActionStateVector2f");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["getInfo"], getInfo);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetActionStatePose(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
    StructPointerDecoder<Decoded_XrActionStatePose>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetActionStatePose");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["getInfo"], getInfo);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSyncActions(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionsSyncInfo>* syncInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSyncActions");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["syncInfo"], syncInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateBoundSourcesForAction(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrBoundSourcesForActionEnumerateInfo>* enumerateInfo,
    uint32_t                                    sourceCapacityInput,
    PointerDecoder<uint32_t>*                   sourceCountOutput,
    HandlePointerDecoder<XrPath>*               sources)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateBoundSourcesForAction");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["enumerateInfo"], enumerateInfo);
        FieldToJson(args["sourceCapacityInput"], sourceCapacityInput);
        FieldToJson(args["sourceCountOutput"], sourceCountOutput);
        HandleToJson(args["sources"], sources);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetInputSourceLocalizedName(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrInputSourceLocalizedNameGetInfo>* getInfo,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetInputSourceLocalizedName");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["getInfo"], getInfo);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrApplyHapticFeedback(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo,
    StructPointerDecoder<Decoded_XrHapticBaseHeader>* hapticFeedback)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrApplyHapticFeedback");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["hapticActionInfo"], hapticActionInfo);
        FieldToJson(args["hapticFeedback"], hapticFeedback);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrStopHapticFeedback(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrStopHapticFeedback");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["hapticActionInfo"], hapticActionInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateApiLayerInstance(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    StructPointerDecoder<Decoded_XrInstanceCreateInfo>* info,
    StructPointerDecoder<Decoded_XrApiLayerCreateInfo>* layerInfo,
    HandlePointerDecoder<XrInstance>*           instance)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateApiLayerInstance");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        FieldToJson(args["info"], info);
        FieldToJson(args["layerInfo"], layerInfo);
        HandleToJson(args["instance"], instance);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrLocateSpaces(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpacesLocateInfo>* locateInfo,
    StructPointerDecoder<Decoded_XrSpaceLocations>* spaceLocations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrLocateSpaces");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["locateInfo"], locateInfo);
        FieldToJson(args["spaceLocations"], spaceLocations);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetAndroidApplicationThreadKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrAndroidThreadTypeKHR                      threadType,
    uint32_t                                    threadId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetAndroidApplicationThreadKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        args["threadType"] = threadType;
        FieldToJson(args["threadId"], threadId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSwapchainAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* info,
    HandlePointerDecoder<XrSwapchain>*          swapchain,
    uint64_t                                    surface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSwapchainAndroidSurfaceKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["surface"], surface);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetOpenGLGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLKHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetOpenGLGraphicsRequirementsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetOpenGLESGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLESKHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetOpenGLESGraphicsRequirementsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanInstanceExtensionsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanInstanceExtensionsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanDeviceExtensionsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanDeviceExtensionsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanGraphicsDeviceKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    format::HandleId                            vkInstance,
    HandlePointerDecoder<VkPhysicalDevice>*     vkPhysicalDevice)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanGraphicsDeviceKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        HandleToJson(args["vkInstance"], vkInstance);
        HandleToJson(args["vkPhysicalDevice"], vkPhysicalDevice);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanGraphicsRequirementsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetD3D11GraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D11KHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetD3D11GraphicsRequirementsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetD3D12GraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D12KHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetD3D12GraphicsRequirementsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMetalGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsMetalKHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMetalGraphicsRequirementsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVisibilityMaskKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewIndex,
    XrVisibilityMaskTypeKHR                     visibilityMaskType,
    StructPointerDecoder<Decoded_XrVisibilityMaskKHR>* visibilityMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVisibilityMaskKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        args["viewConfigurationType"] = viewConfigurationType;
        FieldToJson(args["viewIndex"], viewIndex);
        args["visibilityMaskType"] = visibilityMaskType;
        FieldToJson(args["visibilityMask"], visibilityMask);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrConvertWin32PerformanceCounterToTimeKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<LARGE_INTEGER>*              performanceCounter,
    PointerDecoder<XrTime>*                     time)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrConvertWin32PerformanceCounterToTimeKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["performanceCounter"], *performanceCounter->GetPointer());
        FieldToJson(args["time"], time);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrConvertTimeToWin32PerformanceCounterKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrTime                                      time,
    PointerDecoder<LARGE_INTEGER>*              performanceCounter)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrConvertTimeToWin32PerformanceCounterKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["time"], time);
        FieldToJson(args["performanceCounter"], *performanceCounter->GetPointer());
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrConvertTimespecTimeToTimeKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_timespec>*     timespecTime,
    PointerDecoder<XrTime>*                     time)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrConvertTimespecTimeToTimeKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["timespecTime"], timespecTime);
        FieldToJson(args["time"], time);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrConvertTimeToTimespecTimeKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrTime                                      time,
    StructPointerDecoder<Decoded_timespec>*     timespecTime)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrConvertTimeToTimespecTimeKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["time"], time);
        FieldToJson(args["timespecTime"], timespecTime);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrInitializeLoaderKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    StructPointerDecoder<Decoded_XrLoaderInitInfoBaseHeaderKHR>* loaderInitInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrInitializeLoaderKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        FieldToJson(args["loaderInitInfo"], loaderInitInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateVulkanInstanceKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrVulkanInstanceCreateInfoKHR>* createInfo,
    HandlePointerDecoder<VkInstance>*           vulkanInstance,
    PointerDecoder<VkResult>*                   vulkanResult)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateVulkanInstanceKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["vulkanInstance"], vulkanInstance);
        FieldToJson(args["vulkanResult"], vulkanResult);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateVulkanDeviceKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrVulkanDeviceCreateInfoKHR>* createInfo,
    HandlePointerDecoder<VkDevice>*             vulkanDevice,
    PointerDecoder<VkResult>*                   vulkanResult)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateVulkanDeviceKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["vulkanDevice"], vulkanDevice);
        FieldToJson(args["vulkanResult"], vulkanResult);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanGraphicsDevice2KHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrVulkanGraphicsDeviceGetInfoKHR>* getInfo,
    HandlePointerDecoder<VkPhysicalDevice>*     vulkanPhysicalDevice)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanGraphicsDevice2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["getInfo"], getInfo);
        HandleToJson(args["vulkanPhysicalDevice"], vulkanPhysicalDevice);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanGraphicsRequirements2KHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanGraphicsRequirements2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrLocateSpacesKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpacesLocateInfo>* locateInfo,
    StructPointerDecoder<Decoded_XrSpaceLocations>* spaceLocations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrLocateSpacesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["locateInfo"], locateInfo);
        FieldToJson(args["spaceLocations"], spaceLocations);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPerfSettingsSetPerformanceLevelEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPerfSettingsDomainEXT                     domain,
    XrPerfSettingsLevelEXT                      level)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPerfSettingsSetPerformanceLevelEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        args["domain"] = domain;
        args["level"] = level;
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrThermalGetTemperatureTrendEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPerfSettingsDomainEXT                     domain,
    PointerDecoder<XrPerfSettingsNotificationLevelEXT>* notificationLevel,
    PointerDecoder<float>*                      tempHeadroom,
    PointerDecoder<float>*                      tempSlope)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrThermalGetTemperatureTrendEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        args["domain"] = domain;
        FieldToJson(args["notificationLevel"], notificationLevel);
        FieldToJson(args["tempHeadroom"], tempHeadroom);
        FieldToJson(args["tempSlope"], tempSlope);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrDebugUtilsObjectNameInfoEXT>* nameInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetDebugUtilsObjectNameEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["nameInfo"], nameInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrDebugUtilsMessengerCreateInfoEXT>* createInfo,
    HandlePointerDecoder<XrDebugUtilsMessengerEXT>* messenger)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateDebugUtilsMessengerEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["messenger"], messenger);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            messenger)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyDebugUtilsMessengerEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["messenger"], messenger);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrDebugUtilsMessageSeverityFlagsEXT         messageSeverity,
    XrDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_XrDebugUtilsMessengerCallbackDataEXT>* callbackData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSubmitDebugUtilsMessageEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        args["messageSeverity"] = XrDebugUtilsMessageSeverityFlagsEXT_t{messageSeverity};
        args["messageTypes"] = XrDebugUtilsMessageTypeFlagsEXT_t{messageTypes};
        FieldToJson(args["callbackData"], callbackData);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSessionBeginDebugUtilsLabelRegionEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* labelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSessionBeginDebugUtilsLabelRegionEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["labelInfo"], labelInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSessionEndDebugUtilsLabelRegionEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSessionEndDebugUtilsLabelRegionEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSessionInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* labelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSessionInsertDebugUtilsLabelEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["labelInfo"], labelInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpatialAnchorMSFT>*  anchor)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpatialAnchorMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["anchor"], anchor);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpatialAnchorSpaceMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorSpaceCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpatialAnchorSpaceMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["space"], space);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            anchor)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySpatialAnchorMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["anchor"], anchor);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetInputDeviceActiveEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            interactionProfile,
    format::HandleId                            topLevelPath,
    XrBool32                                    isActive)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetInputDeviceActiveEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["interactionProfile"], interactionProfile);
        HandleToJson(args["topLevelPath"], topLevelPath);
        Bool32ToJson(args["isActive"], isActive);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetInputDeviceStateBoolEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelPath,
    format::HandleId                            inputSourcePath,
    XrBool32                                    state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetInputDeviceStateBoolEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["topLevelPath"], topLevelPath);
        HandleToJson(args["inputSourcePath"], inputSourcePath);
        Bool32ToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetInputDeviceStateFloatEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelPath,
    format::HandleId                            inputSourcePath,
    float                                       state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetInputDeviceStateFloatEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["topLevelPath"], topLevelPath);
        HandleToJson(args["inputSourcePath"], inputSourcePath);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetInputDeviceStateVector2fEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelPath,
    format::HandleId                            inputSourcePath,
    Decoded_XrVector2f                          state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetInputDeviceStateVector2fEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["topLevelPath"], topLevelPath);
        HandleToJson(args["inputSourcePath"], inputSourcePath);
        FieldToJson(args["state"], &state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetInputDeviceLocationEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelPath,
    format::HandleId                            inputSourcePath,
    format::HandleId                            space,
    Decoded_XrPosef                             pose)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetInputDeviceLocationEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["topLevelPath"], topLevelPath);
        HandleToJson(args["inputSourcePath"], inputSourcePath);
        HandleToJson(args["space"], space);
        FieldToJson(args["pose"], &pose);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpatialGraphNodeSpaceMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpatialGraphNodeSpaceMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["space"], space);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrTryCreateSpatialGraphStaticNodeBindingMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpatialGraphNodeBindingMSFT>* nodeBinding)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrTryCreateSpatialGraphStaticNodeBindingMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["nodeBinding"], nodeBinding);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySpatialGraphNodeBindingMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            nodeBinding)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySpatialGraphNodeBindingMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["nodeBinding"], nodeBinding);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpatialGraphNodeBindingPropertiesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            nodeBinding,
    StructPointerDecoder<Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT>* getInfo,
    StructPointerDecoder<Decoded_XrSpatialGraphNodeBindingPropertiesMSFT>* properties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpatialGraphNodeBindingPropertiesMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["nodeBinding"], nodeBinding);
        FieldToJson(args["getInfo"], getInfo);
        FieldToJson(args["properties"], properties);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateHandTrackerEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrHandTrackerCreateInfoEXT>* createInfo,
    HandlePointerDecoder<XrHandTrackerEXT>*     handTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateHandTrackerEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["handTracker"], handTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyHandTrackerEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyHandTrackerEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrLocateHandJointsEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker,
    StructPointerDecoder<Decoded_XrHandJointsLocateInfoEXT>* locateInfo,
    StructPointerDecoder<Decoded_XrHandJointLocationsEXT>* locations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrLocateHandJointsEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker);
        FieldToJson(args["locateInfo"], locateInfo);
        FieldToJson(args["locations"], locations);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateHandMeshSpaceMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker,
    StructPointerDecoder<Decoded_XrHandMeshSpaceCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateHandMeshSpaceMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["space"], space);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrUpdateHandMeshMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker,
    StructPointerDecoder<Decoded_XrHandMeshUpdateInfoMSFT>* updateInfo,
    StructPointerDecoder<Decoded_XrHandMeshMSFT>* handMesh)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrUpdateHandMeshMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker);
        FieldToJson(args["updateInfo"], updateInfo);
        FieldToJson(args["handMesh"], handMesh);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetControllerModelKeyMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelUserPath,
    StructPointerDecoder<Decoded_XrControllerModelKeyStateMSFT>* controllerModelKeyState)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetControllerModelKeyMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["topLevelUserPath"], topLevelUserPath);
        FieldToJson(args["controllerModelKeyState"], controllerModelKeyState);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrLoadControllerModelMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            modelKey,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    PointerDecoder<uint8_t>*                    buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrLoadControllerModelMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["modelKey"], modelKey);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetControllerModelPropertiesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            modelKey,
    StructPointerDecoder<Decoded_XrControllerModelPropertiesMSFT>* properties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetControllerModelPropertiesMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["modelKey"], modelKey);
        FieldToJson(args["properties"], properties);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetControllerModelStateMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            modelKey,
    StructPointerDecoder<Decoded_XrControllerModelStateMSFT>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetControllerModelStateMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["modelKey"], modelKey);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint64_t                                    perceptionAnchor,
    HandlePointerDecoder<XrSpatialAnchorMSFT>*  anchor)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpatialAnchorFromPerceptionAnchorMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["perceptionAnchor"], perceptionAnchor);
        HandleToJson(args["anchor"], anchor);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            anchor,
    PointerDecoder<uint64_t, void*>*            perceptionAnchor)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrTryGetPerceptionAnchorFromSpatialAnchorMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["anchor"], anchor);
        FieldToJson(args["perceptionAnchor"], perceptionAnchor);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateReprojectionModesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    modeCapacityInput,
    PointerDecoder<uint32_t>*                   modeCountOutput,
    PointerDecoder<XrReprojectionModeMSFT>*     modes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateReprojectionModesMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        args["viewConfigurationType"] = viewConfigurationType;
        FieldToJson(args["modeCapacityInput"], modeCapacityInput);
        FieldToJson(args["modeCountOutput"], modeCountOutput);
        FieldToJson(args["modes"], modes);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrUpdateSwapchainFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrUpdateSwapchainFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSwapchainStateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSwapchainStateFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateBodyTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrBodyTrackerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrBodyTrackerFB>*      bodyTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateBodyTrackerFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["bodyTracker"], bodyTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyBodyTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            bodyTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyBodyTrackerFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["bodyTracker"], bodyTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrLocateBodyJointsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            bodyTracker,
    StructPointerDecoder<Decoded_XrBodyJointsLocateInfoFB>* locateInfo,
    StructPointerDecoder<Decoded_XrBodyJointLocationsFB>* locations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrLocateBodyJointsFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["bodyTracker"], bodyTracker);
        FieldToJson(args["locateInfo"], locateInfo);
        FieldToJson(args["locations"], locations);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetBodySkeletonFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            bodyTracker,
    StructPointerDecoder<Decoded_XrBodySkeletonFB>* skeleton)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetBodySkeletonFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["bodyTracker"], bodyTracker);
        FieldToJson(args["skeleton"], skeleton);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateSceneComputeFeaturesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    uint32_t                                    featureCapacityInput,
    PointerDecoder<uint32_t>*                   featureCountOutput,
    PointerDecoder<XrSceneComputeFeatureMSFT>*  features)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateSceneComputeFeaturesMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["systemId"], systemId);
        FieldToJson(args["featureCapacityInput"], featureCapacityInput);
        FieldToJson(args["featureCountOutput"], featureCountOutput);
        FieldToJson(args["features"], features);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSceneObserverMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSceneObserverCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSceneObserverMSFT>*  sceneObserver)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSceneObserverMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["sceneObserver"], sceneObserver);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySceneObserverMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySceneObserverMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["sceneObserver"], sceneObserver);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    StructPointerDecoder<Decoded_XrSceneCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSceneMSFT>*          scene)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSceneMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["sceneObserver"], sceneObserver);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["scene"], scene);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySceneMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrComputeNewSceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    StructPointerDecoder<Decoded_XrNewSceneComputeInfoMSFT>* computeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrComputeNewSceneMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["sceneObserver"], sceneObserver);
        FieldToJson(args["computeInfo"], computeInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSceneComputeStateMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    PointerDecoder<XrSceneComputeStateMSFT>*    state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSceneComputeStateMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["sceneObserver"], sceneObserver);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSceneComponentsMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrSceneComponentsGetInfoMSFT>* getInfo,
    StructPointerDecoder<Decoded_XrSceneComponentsMSFT>* components)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSceneComponentsMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene);
        FieldToJson(args["getInfo"], getInfo);
        FieldToJson(args["components"], components);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrLocateSceneComponentsMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrSceneComponentsLocateInfoMSFT>* locateInfo,
    StructPointerDecoder<Decoded_XrSceneComponentLocationsMSFT>* locations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrLocateSceneComponentsMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene);
        FieldToJson(args["locateInfo"], locateInfo);
        FieldToJson(args["locations"], locations);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSceneMeshBuffersMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrSceneMeshBuffersGetInfoMSFT>* getInfo,
    StructPointerDecoder<Decoded_XrSceneMeshBuffersMSFT>* buffers)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSceneMeshBuffersMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene);
        FieldToJson(args["getInfo"], getInfo);
        FieldToJson(args["buffers"], buffers);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDeserializeSceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    StructPointerDecoder<Decoded_XrSceneDeserializeInfoMSFT>* deserializeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDeserializeSceneMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["sceneObserver"], sceneObserver);
        FieldToJson(args["deserializeInfo"], deserializeInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSerializedSceneFragmentDataMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrSerializedSceneFragmentDataGetInfoMSFT>* getInfo,
    uint32_t                                    countInput,
    PointerDecoder<uint32_t>*                   readOutput,
    PointerDecoder<uint8_t>*                    buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSerializedSceneFragmentDataMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene);
        FieldToJson(args["getInfo"], getInfo);
        FieldToJson(args["countInput"], countInput);
        FieldToJson(args["readOutput"], readOutput);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateDisplayRefreshRatesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    displayRefreshRateCapacityInput,
    PointerDecoder<uint32_t>*                   displayRefreshRateCountOutput,
    PointerDecoder<float>*                      displayRefreshRates)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateDisplayRefreshRatesFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["displayRefreshRateCapacityInput"], displayRefreshRateCapacityInput);
        FieldToJson(args["displayRefreshRateCountOutput"], displayRefreshRateCountOutput);
        FieldToJson(args["displayRefreshRates"], displayRefreshRates);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetDisplayRefreshRateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    PointerDecoder<float>*                      displayRefreshRate)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetDisplayRefreshRateFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["displayRefreshRate"], displayRefreshRate);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrRequestDisplayRefreshRateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    float                                       displayRefreshRate)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrRequestDisplayRefreshRateFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["displayRefreshRate"], displayRefreshRate);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateViveTrackerPathsHTCX(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    uint32_t                                    pathCapacityInput,
    PointerDecoder<uint32_t>*                   pathCountOutput,
    StructPointerDecoder<Decoded_XrViveTrackerPathsHTCX>* paths)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateViveTrackerPathsHTCX");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pathCapacityInput"], pathCapacityInput);
        FieldToJson(args["pathCountOutput"], pathCountOutput);
        FieldToJson(args["paths"], paths);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateFacialTrackerHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFacialTrackerCreateInfoHTC>* createInfo,
    HandlePointerDecoder<XrFacialTrackerHTC>*   facialTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateFacialTrackerHTC");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["facialTracker"], facialTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyFacialTrackerHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            facialTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyFacialTrackerHTC");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["facialTracker"], facialTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetFacialExpressionsHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            facialTracker,
    StructPointerDecoder<Decoded_XrFacialExpressionsHTC>* facialExpressions)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetFacialExpressionsHTC");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["facialTracker"], facialTracker);
        FieldToJson(args["facialExpressions"], facialExpressions);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateColorSpacesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    colorSpaceCapacityInput,
    PointerDecoder<uint32_t>*                   colorSpaceCountOutput,
    PointerDecoder<XrColorSpaceFB>*             colorSpaces)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateColorSpacesFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["colorSpaceCapacityInput"], colorSpaceCapacityInput);
        FieldToJson(args["colorSpaceCountOutput"], colorSpaceCountOutput);
        FieldToJson(args["colorSpaces"], colorSpaces);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetColorSpaceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrColorSpaceFB                              colorSpace)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetColorSpaceFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        args["colorSpace"] = colorSpace;
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetHandMeshFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker,
    StructPointerDecoder<Decoded_XrHandTrackingMeshFB>* mesh)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetHandMeshFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker);
        FieldToJson(args["mesh"], mesh);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpatialAnchorFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpatialAnchorFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        HandleToJson(args["requestId"], requestId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceUuidFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrUuid>*       uuid)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceUuidFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space);
        FieldToJson(args["uuid"], uuid);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateSpaceSupportedComponentsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    uint32_t                                    componentTypeCapacityInput,
    PointerDecoder<uint32_t>*                   componentTypeCountOutput,
    PointerDecoder<XrSpaceComponentTypeFB>*     componentTypes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateSpaceSupportedComponentsFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space);
        FieldToJson(args["componentTypeCapacityInput"], componentTypeCapacityInput);
        FieldToJson(args["componentTypeCountOutput"], componentTypeCountOutput);
        FieldToJson(args["componentTypes"], componentTypes);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetSpaceComponentStatusFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrSpaceComponentStatusSetInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetSpaceComponentStatusFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space);
        FieldToJson(args["info"], info);
        HandleToJson(args["requestId"], requestId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceComponentStatusFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    XrSpaceComponentTypeFB                      componentType,
    StructPointerDecoder<Decoded_XrSpaceComponentStatusFB>* status)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceComponentStatusFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space);
        args["componentType"] = componentType;
        FieldToJson(args["status"], status);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateFoveationProfileFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFoveationProfileCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrFoveationProfileFB>* profile)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateFoveationProfileFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["profile"], profile);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyFoveationProfileFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            profile)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyFoveationProfileFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["profile"], profile);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrQuerySystemTrackedKeyboardFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrKeyboardTrackingQueryFB>* queryInfo,
    StructPointerDecoder<Decoded_XrKeyboardTrackingDescriptionFB>* keyboard)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrQuerySystemTrackedKeyboardFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["queryInfo"], queryInfo);
        FieldToJson(args["keyboard"], keyboard);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateKeyboardSpaceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrKeyboardSpaceCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrSpace>*              keyboardSpace)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateKeyboardSpaceFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["keyboardSpace"], keyboardSpace);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrTriangleMeshBeginUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrTriangleMeshBeginUpdateFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["mesh"], mesh);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrTriangleMeshEndUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh,
    uint32_t                                    vertexCount,
    uint32_t                                    triangleCount)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrTriangleMeshEndUpdateFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["mesh"], mesh);
        FieldToJson(args["vertexCount"], vertexCount);
        FieldToJson(args["triangleCount"], triangleCount);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrTriangleMeshBeginVertexBufferUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh,
    PointerDecoder<uint32_t>*                   outVertexCount)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrTriangleMeshBeginVertexBufferUpdateFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["mesh"], mesh);
        FieldToJson(args["outVertexCount"], outVertexCount);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrTriangleMeshEndVertexBufferUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrTriangleMeshEndVertexBufferUpdateFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["mesh"], mesh);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreatePassthroughFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPassthroughCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrPassthroughFB>*      outPassthrough)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreatePassthroughFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["outPassthrough"], outPassthrough);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyPassthroughFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyPassthroughFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["passthrough"], passthrough);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughStartFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughStartFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["passthrough"], passthrough);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughPauseFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughPauseFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["passthrough"], passthrough);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreatePassthroughLayerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPassthroughLayerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrPassthroughLayerFB>* outLayer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreatePassthroughLayerFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["outLayer"], outLayer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyPassthroughLayerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyPassthroughLayerFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["layer"], layer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughLayerPauseFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughLayerPauseFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["layer"], layer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughLayerResumeFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughLayerResumeFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["layer"], layer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughLayerSetStyleFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer,
    StructPointerDecoder<Decoded_XrPassthroughStyleFB>* style)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughLayerSetStyleFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["layer"], layer);
        FieldToJson(args["style"], style);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateGeometryInstanceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrGeometryInstanceCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrGeometryInstanceFB>* outGeometryInstance)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateGeometryInstanceFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["outGeometryInstance"], outGeometryInstance);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyGeometryInstanceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyGeometryInstanceFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGeometryInstanceSetTransformFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrGeometryInstanceTransformFB>* transformation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGeometryInstanceSetTransformFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["transformation"], transformation);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateRenderModelPathsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    pathCapacityInput,
    PointerDecoder<uint32_t>*                   pathCountOutput,
    StructPointerDecoder<Decoded_XrRenderModelPathInfoFB>* paths)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateRenderModelPathsFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["pathCapacityInput"], pathCapacityInput);
        FieldToJson(args["pathCountOutput"], pathCountOutput);
        FieldToJson(args["paths"], paths);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetRenderModelPropertiesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            path,
    StructPointerDecoder<Decoded_XrRenderModelPropertiesFB>* properties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetRenderModelPropertiesFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["path"], path);
        FieldToJson(args["properties"], properties);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrLoadRenderModelFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrRenderModelLoadInfoFB>* info,
    StructPointerDecoder<Decoded_XrRenderModelBufferFB>* buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrLoadRenderModelFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetEnvironmentDepthEstimationVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrBool32                                    enabled)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetEnvironmentDepthEstimationVARJO");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        Bool32ToJson(args["enabled"], enabled);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetMarkerTrackingVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrBool32                                    enabled)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetMarkerTrackingVARJO");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        Bool32ToJson(args["enabled"], enabled);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetMarkerTrackingTimeoutVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint64_t                                    markerId,
    XrDuration                                  timeout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetMarkerTrackingTimeoutVARJO");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["markerId"], markerId);
        FieldToJson(args["timeout"], timeout);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetMarkerTrackingPredictionVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint64_t                                    markerId,
    XrBool32                                    enable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetMarkerTrackingPredictionVARJO");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["markerId"], markerId);
        Bool32ToJson(args["enable"], enable);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerSizeVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint64_t                                    markerId,
    StructPointerDecoder<Decoded_XrExtent2Df>*  size)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerSizeVARJO");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["markerId"], markerId);
        FieldToJson(args["size"], size);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateMarkerSpaceVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoVARJO>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateMarkerSpaceVARJO");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["space"], space);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetViewOffsetVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    float                                       offset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetViewOffsetVARJO");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["offset"], offset);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpaceFromCoordinateFrameUIDML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrCoordinateSpaceCreateInfoML>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpaceFromCoordinateFrameUIDML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["space"], space);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateMarkerDetectorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrMarkerDetectorCreateInfoML>* createInfo,
    HandlePointerDecoder<XrMarkerDetectorML>*   markerDetector)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateMarkerDetectorML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["markerDetector"], markerDetector);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyMarkerDetectorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyMarkerDetectorML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSnapshotMarkerDetectorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    StructPointerDecoder<Decoded_XrMarkerDetectorSnapshotInfoML>* snapshotInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSnapshotMarkerDetectorML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector);
        FieldToJson(args["snapshotInfo"], snapshotInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerDetectorStateML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    StructPointerDecoder<Decoded_XrMarkerDetectorStateML>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerDetectorStateML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkersML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    uint32_t                                    markerCapacityInput,
    PointerDecoder<uint32_t>*                   markerCountOutput,
    HandlePointerDecoder<XrMarkerML>*           markers)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkersML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector);
        FieldToJson(args["markerCapacityInput"], markerCapacityInput);
        FieldToJson(args["markerCountOutput"], markerCountOutput);
        HandleToJson(args["markers"], markers);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerReprojectionErrorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    format::HandleId                            marker,
    PointerDecoder<float>*                      reprojectionErrorMeters)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerReprojectionErrorML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector);
        HandleToJson(args["marker"], marker);
        FieldToJson(args["reprojectionErrorMeters"], reprojectionErrorMeters);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerLengthML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    format::HandleId                            marker,
    PointerDecoder<float>*                      meters)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerLengthML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector);
        HandleToJson(args["marker"], marker);
        FieldToJson(args["meters"], meters);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerNumberML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    format::HandleId                            marker,
    PointerDecoder<uint64_t>*                   number)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerNumberML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector);
        HandleToJson(args["marker"], marker);
        FieldToJson(args["number"], number);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerStringML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    format::HandleId                            marker,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerStringML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector);
        HandleToJson(args["marker"], marker);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateMarkerSpaceML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoML>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateMarkerSpaceML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["space"], space);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnableLocalizationEventsML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrLocalizationEnableEventsInfoML>* info)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnableLocalizationEventsML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrQueryLocalizationMapsML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrLocalizationMapQueryInfoBaseHeaderML>* queryInfo,
    uint32_t                                    mapCapacityInput,
    PointerDecoder<uint32_t>*                   mapCountOutput,
    StructPointerDecoder<Decoded_XrLocalizationMapML>* maps)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrQueryLocalizationMapsML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["queryInfo"], queryInfo);
        FieldToJson(args["mapCapacityInput"], mapCapacityInput);
        FieldToJson(args["mapCountOutput"], mapCountOutput);
        FieldToJson(args["maps"], maps);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrRequestMapLocalizationML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrMapLocalizationRequestInfoML>* requestInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrRequestMapLocalizationML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["requestInfo"], requestInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrImportLocalizationMapML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrLocalizationMapImportInfoML>* importInfo,
    StructPointerDecoder<Decoded_XrUuid>*       mapUuid)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrImportLocalizationMapML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["importInfo"], importInfo);
        FieldToJson(args["mapUuid"], mapUuid);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateExportedLocalizationMapML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrUuid>*       mapUuid,
    HandlePointerDecoder<XrExportedLocalizationMapML>* map)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateExportedLocalizationMapML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["mapUuid"], mapUuid);
        HandleToJson(args["map"], map);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyExportedLocalizationMapML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            map)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyExportedLocalizationMapML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["map"], map);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetExportedLocalizationMapDataML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            map,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetExportedLocalizationMapDataML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["map"], map);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpatialAnchorStoreConnectionMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    HandlePointerDecoder<XrSpatialAnchorStoreConnectionMSFT>* spatialAnchorStore)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpatialAnchorStoreConnectionMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySpatialAnchorStoreConnectionMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySpatialAnchorStoreConnectionMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPersistSpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore,
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceInfoMSFT>* spatialAnchorPersistenceInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPersistSpatialAnchorMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore);
        FieldToJson(args["spatialAnchorPersistenceInfo"], spatialAnchorPersistenceInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumeratePersistedSpatialAnchorNamesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore,
    uint32_t                                    spatialAnchorNameCapacityInput,
    PointerDecoder<uint32_t>*                   spatialAnchorNameCountOutput,
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT>* spatialAnchorNames)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumeratePersistedSpatialAnchorNamesMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore);
        FieldToJson(args["spatialAnchorNameCapacityInput"], spatialAnchorNameCapacityInput);
        FieldToJson(args["spatialAnchorNameCountOutput"], spatialAnchorNameCountOutput);
        FieldToJson(args["spatialAnchorNames"], spatialAnchorNames);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpatialAnchorFromPersistedNameMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT>* spatialAnchorCreateInfo,
    HandlePointerDecoder<XrSpatialAnchorMSFT>*  spatialAnchor)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpatialAnchorFromPersistedNameMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["spatialAnchorCreateInfo"], spatialAnchorCreateInfo);
        HandleToJson(args["spatialAnchor"], spatialAnchor);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrUnpersistSpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore,
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT>* spatialAnchorPersistenceName)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrUnpersistSpatialAnchorMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore);
        FieldToJson(args["spatialAnchorPersistenceName"], spatialAnchorPersistenceName);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrClearSpatialAnchorStoreMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrClearSpatialAnchorStoreMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSceneMarkerRawDataMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrUuidMSFT>*   markerId,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    PointerDecoder<uint8_t>*                    buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSceneMarkerRawDataMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene);
        FieldToJson(args["markerId"], markerId);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSceneMarkerDecodedStringMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrUuidMSFT>*   markerId,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSceneMarkerDecodedStringMSFT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene);
        FieldToJson(args["markerId"], markerId);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrQuerySpacesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceQueryInfoBaseHeaderFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrQuerySpacesFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        HandleToJson(args["requestId"], requestId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrRetrieveSpaceQueryResultsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            requestId,
    StructPointerDecoder<Decoded_XrSpaceQueryResultsFB>* results)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrRetrieveSpaceQueryResultsFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["requestId"], requestId);
        FieldToJson(args["results"], results);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSaveSpaceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceSaveInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSaveSpaceFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        HandleToJson(args["requestId"], requestId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEraseSpaceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceEraseInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEraseSpaceFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        HandleToJson(args["requestId"], requestId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetAudioOutputDeviceGuidOculus(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    WStringDecoder*                             buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetAudioOutputDeviceGuidOculus");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetAudioInputDeviceGuidOculus(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    WStringDecoder*                             buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetAudioInputDeviceGuidOculus");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["buffer"], buffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrShareSpacesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceShareInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrShareSpacesFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        HandleToJson(args["requestId"], requestId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceBoundingBox2DFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrRect2Df>*    boundingBox2DOutput)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceBoundingBox2DFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["space"], space);
        FieldToJson(args["boundingBox2DOutput"], boundingBox2DOutput);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceBoundingBox3DFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrRect3DfFB>*  boundingBox3DOutput)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceBoundingBox3DFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["space"], space);
        FieldToJson(args["boundingBox3DOutput"], boundingBox3DOutput);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceSemanticLabelsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrSemanticLabelsFB>* semanticLabelsOutput)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceSemanticLabelsFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["space"], space);
        FieldToJson(args["semanticLabelsOutput"], semanticLabelsOutput);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceBoundary2DFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrBoundary2DFB>* boundary2DOutput)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceBoundary2DFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["space"], space);
        FieldToJson(args["boundary2DOutput"], boundary2DOutput);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceRoomLayoutFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrRoomLayoutFB>* roomLayoutOutput)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceRoomLayoutFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["space"], space);
        FieldToJson(args["roomLayoutOutput"], roomLayoutOutput);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetDigitalLensControlALMALENCE(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrDigitalLensControlALMALENCE>* digitalLensControl)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetDigitalLensControlALMALENCE");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["digitalLensControl"], digitalLensControl);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrRequestSceneCaptureFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSceneCaptureRequestInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrRequestSceneCaptureFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        HandleToJson(args["requestId"], requestId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceContainerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrSpaceContainerFB>* spaceContainerOutput)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceContainerFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["space"], space);
        FieldToJson(args["spaceContainerOutput"], spaceContainerOutput);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetFoveationEyeTrackedStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFoveationEyeTrackedStateMETA>* foveationState)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetFoveationEyeTrackedStateMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["foveationState"], foveationState);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateFaceTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFaceTrackerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrFaceTrackerFB>*      faceTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateFaceTrackerFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["faceTracker"], faceTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyFaceTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            faceTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyFaceTrackerFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["faceTracker"], faceTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetFaceExpressionWeightsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            faceTracker,
    StructPointerDecoder<Decoded_XrFaceExpressionInfoFB>* expressionInfo,
    StructPointerDecoder<Decoded_XrFaceExpressionWeightsFB>* expressionWeights)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetFaceExpressionWeightsFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["faceTracker"], faceTracker);
        FieldToJson(args["expressionInfo"], expressionInfo);
        FieldToJson(args["expressionWeights"], expressionWeights);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateEyeTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrEyeTrackerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrEyeTrackerFB>*       eyeTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateEyeTrackerFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["eyeTracker"], eyeTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyEyeTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            eyeTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyEyeTrackerFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["eyeTracker"], eyeTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetEyeGazesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            eyeTracker,
    StructPointerDecoder<Decoded_XrEyeGazesInfoFB>* gazeInfo,
    StructPointerDecoder<Decoded_XrEyeGazesFB>* eyeGazes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetEyeGazesFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["eyeTracker"], eyeTracker);
        FieldToJson(args["gazeInfo"], gazeInfo);
        FieldToJson(args["eyeGazes"], eyeGazes);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughLayerSetKeyboardHandsIntensityFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer,
    StructPointerDecoder<Decoded_XrPassthroughKeyboardHandsIntensityFB>* intensity)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughLayerSetKeyboardHandsIntensityFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["layer"], layer);
        FieldToJson(args["intensity"], intensity);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetDeviceSampleRateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo,
    StructPointerDecoder<Decoded_XrDevicePcmSampleRateStateFB>* deviceSampleRate)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetDeviceSampleRateFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["hapticActionInfo"], hapticActionInfo);
        FieldToJson(args["deviceSampleRate"], deviceSampleRate);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetPassthroughPreferencesMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPassthroughPreferencesMETA>* preferences)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetPassthroughPreferencesMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["preferences"], preferences);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateVirtualKeyboardMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrVirtualKeyboardCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrVirtualKeyboardMETA>* keyboard)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateVirtualKeyboardMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["keyboard"], keyboard);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyVirtualKeyboardMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyVirtualKeyboardMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateVirtualKeyboardSpaceMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardSpaceCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrSpace>*              keyboardSpace)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateVirtualKeyboardSpaceMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["keyboard"], keyboard);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["keyboardSpace"], keyboardSpace);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSuggestVirtualKeyboardLocationMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardLocationInfoMETA>* locationInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSuggestVirtualKeyboardLocationMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard);
        FieldToJson(args["locationInfo"], locationInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVirtualKeyboardScaleMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    PointerDecoder<float>*                      scale)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVirtualKeyboardScaleMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard);
        FieldToJson(args["scale"], scale);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetVirtualKeyboardModelVisibilityMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA>* modelVisibility)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetVirtualKeyboardModelVisibilityMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard);
        FieldToJson(args["modelVisibility"], modelVisibility);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVirtualKeyboardModelAnimationStatesMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardModelAnimationStatesMETA>* animationStates)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVirtualKeyboardModelAnimationStatesMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard);
        FieldToJson(args["animationStates"], animationStates);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVirtualKeyboardDirtyTexturesMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    uint32_t                                    textureIdCapacityInput,
    PointerDecoder<uint32_t>*                   textureIdCountOutput,
    PointerDecoder<uint64_t>*                   textureIds)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVirtualKeyboardDirtyTexturesMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard);
        FieldToJson(args["textureIdCapacityInput"], textureIdCapacityInput);
        FieldToJson(args["textureIdCountOutput"], textureIdCountOutput);
        FieldToJson(args["textureIds"], textureIds);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVirtualKeyboardTextureDataMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    uint64_t                                    textureId,
    StructPointerDecoder<Decoded_XrVirtualKeyboardTextureDataMETA>* textureData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVirtualKeyboardTextureDataMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard);
        FieldToJson(args["textureId"], textureId);
        FieldToJson(args["textureData"], textureData);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSendVirtualKeyboardInputMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardInputInfoMETA>* info,
    StructPointerDecoder<Decoded_XrPosef>*      interactorRootPose)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSendVirtualKeyboardInputMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard);
        FieldToJson(args["info"], info);
        FieldToJson(args["interactorRootPose"], interactorRootPose);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrChangeVirtualKeyboardTextContextMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardTextContextChangeInfoMETA>* changeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrChangeVirtualKeyboardTextContextMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard);
        FieldToJson(args["changeInfo"], changeInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateExternalCamerasOCULUS(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    cameraCapacityInput,
    PointerDecoder<uint32_t>*                   cameraCountOutput,
    StructPointerDecoder<Decoded_XrExternalCameraOCULUS>* cameras)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateExternalCamerasOCULUS");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["cameraCapacityInput"], cameraCapacityInput);
        FieldToJson(args["cameraCountOutput"], cameraCountOutput);
        FieldToJson(args["cameras"], cameras);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumeratePerformanceMetricsCounterPathsMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    uint32_t                                    counterPathCapacityInput,
    PointerDecoder<uint32_t>*                   counterPathCountOutput,
    HandlePointerDecoder<XrPath>*               counterPaths)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumeratePerformanceMetricsCounterPathsMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["counterPathCapacityInput"], counterPathCapacityInput);
        FieldToJson(args["counterPathCountOutput"], counterPathCountOutput);
        HandleToJson(args["counterPaths"], counterPaths);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetPerformanceMetricsStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetPerformanceMetricsStateMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetPerformanceMetricsStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetPerformanceMetricsStateMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrQueryPerformanceMetricsCounterMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            counterPath,
    StructPointerDecoder<Decoded_XrPerformanceMetricsCounterMETA>* counter)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrQueryPerformanceMetricsCounterMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        HandleToJson(args["counterPath"], counterPath);
        FieldToJson(args["counter"], counter);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSaveSpaceListFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceListSaveInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSaveSpaceListFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        HandleToJson(args["requestId"], requestId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpaceUserFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceUserCreateInfoFB>* info,
    HandlePointerDecoder<XrSpaceUserFB>*        user)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpaceUserFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        HandleToJson(args["user"], user);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceUserIdFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            user,
    PointerDecoder<XrSpaceUserIdFB>*            userId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceUserIdFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["user"], user);
        FieldToJson(args["userId"], userId);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySpaceUserFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            user)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySpaceUserFB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["user"], user);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetRecommendedLayerResolutionMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrRecommendedLayerResolutionGetInfoMETA>* info,
    StructPointerDecoder<Decoded_XrRecommendedLayerResolutionMETA>* resolution)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetRecommendedLayerResolutionMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["info"], info);
        FieldToJson(args["resolution"], resolution);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreatePassthroughColorLutMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough,
    StructPointerDecoder<Decoded_XrPassthroughColorLutCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrPassthroughColorLutMETA>* colorLut)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreatePassthroughColorLutMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["passthrough"], passthrough);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["colorLut"], colorLut);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyPassthroughColorLutMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            colorLut)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyPassthroughColorLutMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["colorLut"], colorLut);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrUpdatePassthroughColorLutMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            colorLut,
    StructPointerDecoder<Decoded_XrPassthroughColorLutUpdateInfoMETA>* updateInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrUpdatePassthroughColorLutMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["colorLut"], colorLut);
        FieldToJson(args["updateInfo"], updateInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceTriangleMeshMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrSpaceTriangleMeshGetInfoMETA>* getInfo,
    StructPointerDecoder<Decoded_XrSpaceTriangleMeshMETA>* triangleMeshOutput)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceTriangleMeshMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space);
        FieldToJson(args["getInfo"], getInfo);
        FieldToJson(args["triangleMeshOutput"], triangleMeshOutput);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateFaceTracker2FB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFaceTrackerCreateInfo2FB>* createInfo,
    HandlePointerDecoder<XrFaceTracker2FB>*     faceTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateFaceTracker2FB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["faceTracker"], faceTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyFaceTracker2FB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            faceTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyFaceTracker2FB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["faceTracker"], faceTracker);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetFaceExpressionWeights2FB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            faceTracker,
    StructPointerDecoder<Decoded_XrFaceExpressionInfo2FB>* expressionInfo,
    StructPointerDecoder<Decoded_XrFaceExpressionWeights2FB>* expressionWeights)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetFaceExpressionWeights2FB");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["faceTracker"], faceTracker);
        FieldToJson(args["expressionInfo"], expressionInfo);
        FieldToJson(args["expressionWeights"], expressionWeights);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateEnvironmentDepthProviderMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrEnvironmentDepthProviderCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrEnvironmentDepthProviderMETA>* environmentDepthProvider)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateEnvironmentDepthProviderMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["environmentDepthProvider"], environmentDepthProvider);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyEnvironmentDepthProviderMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyEnvironmentDepthProviderMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["environmentDepthProvider"], environmentDepthProvider);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrStartEnvironmentDepthProviderMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrStartEnvironmentDepthProviderMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["environmentDepthProvider"], environmentDepthProvider);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrStopEnvironmentDepthProviderMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrStopEnvironmentDepthProviderMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["environmentDepthProvider"], environmentDepthProvider);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateEnvironmentDepthSwapchainMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider,
    StructPointerDecoder<Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrEnvironmentDepthSwapchainMETA>* swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateEnvironmentDepthSwapchainMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["environmentDepthProvider"], environmentDepthProvider);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["swapchain"], swapchain);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyEnvironmentDepthSwapchainMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyEnvironmentDepthSwapchainMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateEnvironmentDepthSwapchainImagesMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    uint32_t                                    imageCapacityInput,
    PointerDecoder<uint32_t>*                   imageCountOutput,
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateEnvironmentDepthSwapchainImagesMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["imageCapacityInput"], imageCapacityInput);
        FieldToJson(args["imageCountOutput"], imageCountOutput);
        ParentChildFieldToJson(args["images"], images);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetEnvironmentDepthSwapchainStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrEnvironmentDepthSwapchainStateMETA>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetEnvironmentDepthSwapchainStateMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrAcquireEnvironmentDepthImageMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider,
    StructPointerDecoder<Decoded_XrEnvironmentDepthImageAcquireInfoMETA>* acquireInfo,
    StructPointerDecoder<Decoded_XrEnvironmentDepthImageMETA>* environmentDepthImage)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrAcquireEnvironmentDepthImageMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["environmentDepthProvider"], environmentDepthProvider);
        FieldToJson(args["acquireInfo"], acquireInfo);
        FieldToJson(args["environmentDepthImage"], environmentDepthImage);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetEnvironmentDepthHandRemovalMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider,
    StructPointerDecoder<Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA>* setInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetEnvironmentDepthHandRemovalMETA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["environmentDepthProvider"], environmentDepthProvider);
        FieldToJson(args["setInfo"], setInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetTrackingOptimizationSettingsHintQCOM(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrTrackingOptimizationSettingsDomainQCOM    domain,
    XrTrackingOptimizationSettingsHintQCOM      hint)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetTrackingOptimizationSettingsHintQCOM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        args["domain"] = domain;
        args["hint"] = hint;
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreatePassthroughHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPassthroughCreateInfoHTC>* createInfo,
    HandlePointerDecoder<XrPassthroughHTC>*     passthrough)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreatePassthroughHTC");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["passthrough"], passthrough);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyPassthroughHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyPassthroughHTC");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["passthrough"], passthrough);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrApplyFoveationHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFoveationApplyInfoHTC>* applyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrApplyFoveationHTC");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["applyInfo"], applyInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpatialAnchorHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoHTC>* createInfo,
    HandlePointerDecoder<XrSpace>*              anchor)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpatialAnchorHTC");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["anchor"], anchor);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpatialAnchorNameHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            anchor,
    StructPointerDecoder<Decoded_XrSpatialAnchorNameHTC>* name)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpatialAnchorNameHTC");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["anchor"], anchor);
        FieldToJson(args["name"], name);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrApplyForceFeedbackCurlMNDX(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker,
    StructPointerDecoder<Decoded_XrForceFeedbackCurlApplyLocationsMNDX>* locations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrApplyForceFeedbackCurlMNDX");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker);
        FieldToJson(args["locations"], locations);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreatePlaneDetectorEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPlaneDetectorCreateInfoEXT>* createInfo,
    HandlePointerDecoder<XrPlaneDetectorEXT>*   planeDetector)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreatePlaneDetectorEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session);
        FieldToJson(args["createInfo"], createInfo);
        HandleToJson(args["planeDetector"], planeDetector);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyPlaneDetectorEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyPlaneDetectorEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["planeDetector"], planeDetector);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrBeginPlaneDetectionEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector,
    StructPointerDecoder<Decoded_XrPlaneDetectorBeginInfoEXT>* beginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrBeginPlaneDetectionEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["planeDetector"], planeDetector);
        FieldToJson(args["beginInfo"], beginInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetPlaneDetectionStateEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector,
    PointerDecoder<XrPlaneDetectionStateEXT>*   state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetPlaneDetectionStateEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["planeDetector"], planeDetector);
        FieldToJson(args["state"], state);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetPlaneDetectionsEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector,
    StructPointerDecoder<Decoded_XrPlaneDetectorGetInfoEXT>* info,
    StructPointerDecoder<Decoded_XrPlaneDetectorLocationsEXT>* locations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetPlaneDetectionsEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["planeDetector"], planeDetector);
        FieldToJson(args["info"], info);
        FieldToJson(args["locations"], locations);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetPlanePolygonBufferEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector,
    uint64_t                                    planeId,
    uint32_t                                    polygonBufferIndex,
    StructPointerDecoder<Decoded_XrPlaneDetectorPolygonBufferEXT>* polygonBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetPlanePolygonBufferEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["planeDetector"], planeDetector);
        FieldToJson(args["planeId"], planeId);
        FieldToJson(args["polygonBufferIndex"], polygonBufferIndex);
        FieldToJson(args["polygonBuffer"], polygonBuffer);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPollFutureEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrFuturePollInfoEXT>* pollInfo,
    StructPointerDecoder<Decoded_XrFuturePollResultEXT>* pollResult)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPollFutureEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pollInfo"], pollInfo);
        FieldToJson(args["pollResult"], pollResult);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCancelFutureEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrFutureCancelInfoEXT>* cancelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCancelFutureEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["cancelInfo"], cancelInfo);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnableUserCalibrationEventsML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrUserCalibrationEnableEventsInfoML>* enableInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnableUserCalibrationEventsML");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["enableInfo"], enableInfo);
    WriteBlockEnd();
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
