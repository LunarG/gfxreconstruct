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

#ifdef ENABLE_OPENXR_SUPPORT

#include "util/defines.h"
#include "generated/generated_openxr_json_consumer.h"
#include "decode/custom_openxr_struct_to_json.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::JsonOptions;

void OpenXrExportJsonConsumer::Process_xrDestroyInstance(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyInstance");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetInstanceProperties(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrInstanceProperties>* instanceProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetInstanceProperties");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["instanceProperties"], instanceProperties, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPollEvent(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrEventDataBuffer>* eventData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPollEvent");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["eventData"], eventData, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["value"], value, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["value"], value, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSystemProperties(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    StructPointerDecoder<Decoded_XrSystemProperties>* properties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSystemProperties");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["properties"], properties, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateEnvironmentBlendModes(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    environmentBlendModeCapacityInput,
    PointerDecoder<uint32_t>*                   environmentBlendModeCountOutput,
    PointerDecoder<XrEnvironmentBlendMode>*     environmentBlendModes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateEnvironmentBlendModes");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["viewConfigurationType"], viewConfigurationType, json_options);
        FieldToJson(args["environmentBlendModeCapacityInput"], environmentBlendModeCapacityInput, json_options);
        FieldToJson(args["environmentBlendModeCountOutput"], environmentBlendModeCountOutput, json_options);
        FieldToJson(args["environmentBlendModes"], environmentBlendModes, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["session"], session, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySession");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["spaceCapacityInput"], spaceCapacityInput, json_options);
        FieldToJson(args["spaceCountOutput"], spaceCountOutput, json_options);
        FieldToJson(args["spaces"], spaces, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["space"], space, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["referenceSpaceType"], referenceSpaceType, json_options);
        FieldToJson(args["bounds"], bounds, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["space"], space, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space, json_options);
        HandleToJson(args["baseSpace"], baseSpace, json_options);
        FieldToJson(args["time"], time, json_options);
        FieldToJson(args["location"], location, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySpace(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySpace");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateViewConfigurations(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    uint32_t                                    viewConfigurationTypeCapacityInput,
    PointerDecoder<uint32_t>*                   viewConfigurationTypeCountOutput,
    PointerDecoder<XrViewConfigurationType>*    viewConfigurationTypes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateViewConfigurations");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["viewConfigurationTypeCapacityInput"], viewConfigurationTypeCapacityInput, json_options);
        FieldToJson(args["viewConfigurationTypeCountOutput"], viewConfigurationTypeCountOutput, json_options);
        FieldToJson(args["viewConfigurationTypes"], viewConfigurationTypes, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetViewConfigurationProperties(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    StructPointerDecoder<Decoded_XrViewConfigurationProperties>* configurationProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetViewConfigurationProperties");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["viewConfigurationType"], viewConfigurationType, json_options);
        FieldToJson(args["configurationProperties"], configurationProperties, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateViewConfigurationViews(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewCapacityInput,
    PointerDecoder<uint32_t>*                   viewCountOutput,
    StructPointerDecoder<Decoded_XrViewConfigurationView>* views)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateViewConfigurationViews");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["viewConfigurationType"], viewConfigurationType, json_options);
        FieldToJson(args["viewCapacityInput"], viewCapacityInput, json_options);
        FieldToJson(args["viewCountOutput"], viewCountOutput, json_options);
        FieldToJson(args["views"], views, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["formatCapacityInput"], formatCapacityInput, json_options);
        FieldToJson(args["formatCountOutput"], formatCountOutput, json_options);
        FieldToJson(args["formats"], formats, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySwapchain(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySwapchain");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateSwapchainImages(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    uint32_t                                    imageCapacityInput,
    PointerDecoder<uint32_t>*                   imageCountOutput,
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateSwapchainImages");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["imageCapacityInput"], imageCapacityInput, json_options);
        FieldToJson(args["imageCountOutput"], imageCountOutput, json_options);
        FieldToJson(args["images"], images, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["acquireInfo"], acquireInfo, json_options);
        FieldToJson(args["index"], index, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrWaitSwapchainImage(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageWaitInfo>* waitInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrWaitSwapchainImage");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["waitInfo"], waitInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrReleaseSwapchainImage(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrReleaseSwapchainImage");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["releaseInfo"], releaseInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrBeginSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSessionBeginInfo>* beginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrBeginSession");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["beginInfo"], beginInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEndSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEndSession");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrRequestExitSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrRequestExitSession");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["frameWaitInfo"], frameWaitInfo, json_options);
        FieldToJson(args["frameState"], frameState, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrBeginFrame(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFrameBeginInfo>* frameBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrBeginFrame");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["frameBeginInfo"], frameBeginInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEndFrame(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFrameEndInfo>* frameEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEndFrame");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["frameEndInfo"], frameEndInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["viewLocateInfo"], viewLocateInfo, json_options);
        FieldToJson(args["viewState"], viewState, json_options);
        FieldToJson(args["viewCapacityInput"], viewCapacityInput, json_options);
        FieldToJson(args["viewCountOutput"], viewCountOutput, json_options);
        FieldToJson(args["views"], views, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pathString"], pathString, json_options);
        HandleToJson(args["path"], path, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPathToString(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrPath                                      path,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPathToString");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["path"], path, json_options);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput, json_options);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["actionSet"], actionSet, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyActionSet(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            actionSet)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyActionSet");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["actionSet"], actionSet, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["actionSet"], actionSet, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["action"], action, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyAction(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            action)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyAction");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["action"], action, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSuggestInteractionProfileBindings(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrInteractionProfileSuggestedBinding>* suggestedBindings)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSuggestInteractionProfileBindings");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["suggestedBindings"], suggestedBindings, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrAttachSessionActionSets(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSessionActionSetsAttachInfo>* attachInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrAttachSessionActionSets");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["attachInfo"], attachInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetCurrentInteractionProfile(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPath                                      topLevelUserPath,
    StructPointerDecoder<Decoded_XrInteractionProfileState>* interactionProfile)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetCurrentInteractionProfile");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["topLevelUserPath"], topLevelUserPath, json_options);
        FieldToJson(args["interactionProfile"], interactionProfile, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        FieldToJson(args["state"], state, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        FieldToJson(args["state"], state, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        FieldToJson(args["state"], state, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        FieldToJson(args["state"], state, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSyncActions(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionsSyncInfo>* syncInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSyncActions");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["syncInfo"], syncInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["enumerateInfo"], enumerateInfo, json_options);
        FieldToJson(args["sourceCapacityInput"], sourceCapacityInput, json_options);
        FieldToJson(args["sourceCountOutput"], sourceCountOutput, json_options);
        HandleToJson(args["sources"], sources, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput, json_options);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["hapticActionInfo"], hapticActionInfo, json_options);
        FieldToJson(args["hapticFeedback"], hapticFeedback, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrStopHapticFeedback(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrStopHapticFeedback");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["hapticActionInfo"], hapticActionInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        FieldToJson(args["info"], info, json_options);
        FieldToJson(args["layerInfo"], layerInfo, json_options);
        HandleToJson(args["instance"], instance, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["threadType"], threadType, json_options);
        FieldToJson(args["threadId"], threadId, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["surface"], surface, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetOpenGLGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLKHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetOpenGLGraphicsRequirementsKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetOpenGLESGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLESKHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetOpenGLESGraphicsRequirementsKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanInstanceExtensionsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanInstanceExtensionsKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput, json_options);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanDeviceExtensionsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanDeviceExtensionsKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput, json_options);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanGraphicsDeviceKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    format::HandleId                            vkInstance,
    HandlePointerDecoder<VkPhysicalDevice>*     vkPhysicalDevice)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanGraphicsDeviceKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        HandleToJson(args["vkInstance"], vkInstance, json_options);
        HandleToJson(args["vkPhysicalDevice"], vkPhysicalDevice, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanGraphicsRequirementsKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetD3D11GraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D11KHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetD3D11GraphicsRequirementsKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetD3D12GraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D12KHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetD3D12GraphicsRequirementsKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["viewConfigurationType"], viewConfigurationType, json_options);
        FieldToJson(args["viewIndex"], viewIndex, json_options);
        FieldToJson(args["visibilityMaskType"], visibilityMaskType, json_options);
        FieldToJson(args["visibilityMask"], visibilityMask, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["performanceCounter"], *performanceCounter->GetPointer(), json_options);
        FieldToJson(args["time"], time, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["time"], time, json_options);
        FieldToJson(args["performanceCounter"], *performanceCounter->GetPointer(), json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["timespecTime"], timespecTime, json_options);
        FieldToJson(args["time"], time, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["time"], time, json_options);
        FieldToJson(args["timespecTime"], timespecTime, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["vulkanInstance"], vulkanInstance, json_options);
        FieldToJson(args["vulkanResult"], vulkanResult, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["vulkanDevice"], vulkanDevice, json_options);
        FieldToJson(args["vulkanResult"], vulkanResult, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        HandleToJson(args["vulkanPhysicalDevice"], vulkanPhysicalDevice, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVulkanGraphicsRequirements2KHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVulkanGraphicsRequirements2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["graphicsRequirements"], graphicsRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["domain"], domain, json_options);
        FieldToJson(args["level"], level, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["domain"], domain, json_options);
        FieldToJson(args["notificationLevel"], notificationLevel, json_options);
        FieldToJson(args["tempHeadroom"], tempHeadroom, json_options);
        FieldToJson(args["tempSlope"], tempSlope, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrDebugUtilsObjectNameInfoEXT>* nameInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetDebugUtilsObjectNameEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["nameInfo"], nameInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["messenger"], messenger, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            messenger)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyDebugUtilsMessengerEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["messenger"], messenger, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(XrDebugUtilsMessageSeverityFlagsEXT_t(), args["messageSeverity"], messageSeverity, json_options);
        FieldToJson(XrDebugUtilsMessageTypeFlagsEXT_t(), args["messageTypes"], messageTypes, json_options);
        FieldToJson(args["callbackData"], callbackData, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSessionBeginDebugUtilsLabelRegionEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* labelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSessionBeginDebugUtilsLabelRegionEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["labelInfo"], labelInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSessionEndDebugUtilsLabelRegionEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSessionEndDebugUtilsLabelRegionEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSessionInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* labelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSessionInsertDebugUtilsLabelEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["labelInfo"], labelInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["anchor"], anchor, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["space"], space, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            anchor)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySpatialAnchorMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["anchor"], anchor, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetInputDeviceActiveEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPath                                      interactionProfile,
    XrPath                                      topLevelPath,
    XrBool32                                    isActive)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetInputDeviceActiveEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["interactionProfile"], interactionProfile, json_options);
        HandleToJson(args["topLevelPath"], topLevelPath, json_options);
        Bool32ToJson(args["isActive"], isActive, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetInputDeviceStateBoolEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    XrBool32                                    state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetInputDeviceStateBoolEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["topLevelPath"], topLevelPath, json_options);
        HandleToJson(args["inputSourcePath"], inputSourcePath, json_options);
        Bool32ToJson(args["state"], state, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetInputDeviceStateFloatEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    float                                       state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetInputDeviceStateFloatEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["topLevelPath"], topLevelPath, json_options);
        HandleToJson(args["inputSourcePath"], inputSourcePath, json_options);
        FieldToJson(args["state"], state, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetInputDeviceStateVector2fEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    Decoded_XrVector2f                          state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetInputDeviceStateVector2fEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["topLevelPath"], topLevelPath, json_options);
        HandleToJson(args["inputSourcePath"], inputSourcePath, json_options);
        FieldToJson(args["state"], &state, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetInputDeviceLocationEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    format::HandleId                            space,
    Decoded_XrPosef                             pose)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetInputDeviceLocationEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["topLevelPath"], topLevelPath, json_options);
        HandleToJson(args["inputSourcePath"], inputSourcePath, json_options);
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["pose"], &pose, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["space"], space, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["nodeBinding"], nodeBinding, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySpatialGraphNodeBindingMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            nodeBinding)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySpatialGraphNodeBindingMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["nodeBinding"], nodeBinding, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["nodeBinding"], nodeBinding, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        FieldToJson(args["properties"], properties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["handTracker"], handTracker, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyHandTrackerEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyHandTrackerEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker, json_options);
        FieldToJson(args["locateInfo"], locateInfo, json_options);
        FieldToJson(args["locations"], locations, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["space"], space, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker, json_options);
        FieldToJson(args["updateInfo"], updateInfo, json_options);
        FieldToJson(args["handMesh"], handMesh, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetControllerModelKeyMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPath                                      topLevelUserPath,
    StructPointerDecoder<Decoded_XrControllerModelKeyStateMSFT>* controllerModelKeyState)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetControllerModelKeyMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["topLevelUserPath"], topLevelUserPath, json_options);
        FieldToJson(args["controllerModelKeyState"], controllerModelKeyState, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrLoadControllerModelMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrControllerModelKeyMSFT                    modelKey,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    PointerDecoder<uint8_t>*                    buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrLoadControllerModelMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["modelKey"], modelKey, json_options);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput, json_options);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetControllerModelPropertiesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrControllerModelKeyMSFT                    modelKey,
    StructPointerDecoder<Decoded_XrControllerModelPropertiesMSFT>* properties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetControllerModelPropertiesMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["modelKey"], modelKey, json_options);
        FieldToJson(args["properties"], properties, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetControllerModelStateMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrControllerModelKeyMSFT                    modelKey,
    StructPointerDecoder<Decoded_XrControllerModelStateMSFT>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetControllerModelStateMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["modelKey"], modelKey, json_options);
        FieldToJson(args["state"], state, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["perceptionAnchor"], perceptionAnchor, json_options);
        HandleToJson(args["anchor"], anchor, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["anchor"], anchor, json_options);
        FieldToJson(args["perceptionAnchor"], perceptionAnchor, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateReprojectionModesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    modeCapacityInput,
    PointerDecoder<uint32_t>*                   modeCountOutput,
    PointerDecoder<XrReprojectionModeMSFT>*     modes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateReprojectionModesMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["viewConfigurationType"], viewConfigurationType, json_options);
        FieldToJson(args["modeCapacityInput"], modeCapacityInput, json_options);
        FieldToJson(args["modeCountOutput"], modeCountOutput, json_options);
        FieldToJson(args["modes"], modes, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrUpdateSwapchainFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrUpdateSwapchainFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["state"], state, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSwapchainStateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSwapchainStateFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["state"], state, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["bodyTracker"], bodyTracker, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyBodyTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            bodyTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyBodyTrackerFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["bodyTracker"], bodyTracker, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["bodyTracker"], bodyTracker, json_options);
        FieldToJson(args["locateInfo"], locateInfo, json_options);
        FieldToJson(args["locations"], locations, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetBodySkeletonFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            bodyTracker,
    StructPointerDecoder<Decoded_XrBodySkeletonFB>* skeleton)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetBodySkeletonFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["bodyTracker"], bodyTracker, json_options);
        FieldToJson(args["skeleton"], skeleton, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnumerateSceneComputeFeaturesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrSystemId                                  systemId,
    uint32_t                                    featureCapacityInput,
    PointerDecoder<uint32_t>*                   featureCountOutput,
    PointerDecoder<XrSceneComputeFeatureMSFT>*  features)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnumerateSceneComputeFeaturesMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["systemId"], systemId, json_options);
        FieldToJson(args["featureCapacityInput"], featureCapacityInput, json_options);
        FieldToJson(args["featureCountOutput"], featureCountOutput, json_options);
        FieldToJson(args["features"], features, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["sceneObserver"], sceneObserver, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySceneObserverMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySceneObserverMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["sceneObserver"], sceneObserver, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["sceneObserver"], sceneObserver, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["scene"], scene, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySceneMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrComputeNewSceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    StructPointerDecoder<Decoded_XrNewSceneComputeInfoMSFT>* computeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrComputeNewSceneMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["sceneObserver"], sceneObserver, json_options);
        FieldToJson(args["computeInfo"], computeInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSceneComputeStateMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    PointerDecoder<XrSceneComputeStateMSFT>*    state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSceneComputeStateMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["sceneObserver"], sceneObserver, json_options);
        FieldToJson(args["state"], state, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        FieldToJson(args["components"], components, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene, json_options);
        FieldToJson(args["locateInfo"], locateInfo, json_options);
        FieldToJson(args["locations"], locations, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        FieldToJson(args["buffers"], buffers, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDeserializeSceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    StructPointerDecoder<Decoded_XrSceneDeserializeInfoMSFT>* deserializeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDeserializeSceneMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["sceneObserver"], sceneObserver, json_options);
        FieldToJson(args["deserializeInfo"], deserializeInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        FieldToJson(args["countInput"], countInput, json_options);
        FieldToJson(args["readOutput"], readOutput, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["displayRefreshRateCapacityInput"], displayRefreshRateCapacityInput, json_options);
        FieldToJson(args["displayRefreshRateCountOutput"], displayRefreshRateCountOutput, json_options);
        FieldToJson(args["displayRefreshRates"], displayRefreshRates, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetDisplayRefreshRateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    PointerDecoder<float>*                      displayRefreshRate)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetDisplayRefreshRateFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["displayRefreshRate"], displayRefreshRate, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrRequestDisplayRefreshRateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    float                                       displayRefreshRate)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrRequestDisplayRefreshRateFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["displayRefreshRate"], displayRefreshRate, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pathCapacityInput"], pathCapacityInput, json_options);
        FieldToJson(args["pathCountOutput"], pathCountOutput, json_options);
        FieldToJson(args["paths"], paths, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["facialTracker"], facialTracker, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyFacialTrackerHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            facialTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyFacialTrackerHTC");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["facialTracker"], facialTracker, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetFacialExpressionsHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            facialTracker,
    StructPointerDecoder<Decoded_XrFacialExpressionsHTC>* facialExpressions)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetFacialExpressionsHTC");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["facialTracker"], facialTracker, json_options);
        FieldToJson(args["facialExpressions"], facialExpressions, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["colorSpaceCapacityInput"], colorSpaceCapacityInput, json_options);
        FieldToJson(args["colorSpaceCountOutput"], colorSpaceCountOutput, json_options);
        FieldToJson(args["colorSpaces"], colorSpaces, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetColorSpaceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrColorSpaceFB                              colorSpace)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetColorSpaceFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["colorSpace"], colorSpace, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetHandMeshFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker,
    StructPointerDecoder<Decoded_XrHandTrackingMeshFB>* mesh)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetHandMeshFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker, json_options);
        FieldToJson(args["mesh"], mesh, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        HandleToJson(args["requestId"], requestId, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceUuidFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrUuidEXT>*    uuid)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceUuidFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["uuid"], uuid, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["componentTypeCapacityInput"], componentTypeCapacityInput, json_options);
        FieldToJson(args["componentTypeCountOutput"], componentTypeCountOutput, json_options);
        FieldToJson(args["componentTypes"], componentTypes, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["info"], info, json_options);
        HandleToJson(args["requestId"], requestId, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["componentType"], componentType, json_options);
        FieldToJson(args["status"], status, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["profile"], profile, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyFoveationProfileFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            profile)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyFoveationProfileFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["profile"], profile, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["queryInfo"], queryInfo, json_options);
        FieldToJson(args["keyboard"], keyboard, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["keyboardSpace"], keyboardSpace, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrTriangleMeshBeginUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrTriangleMeshBeginUpdateFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["mesh"], mesh, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["mesh"], mesh, json_options);
        FieldToJson(args["vertexCount"], vertexCount, json_options);
        FieldToJson(args["triangleCount"], triangleCount, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrTriangleMeshBeginVertexBufferUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh,
    PointerDecoder<uint32_t>*                   outVertexCount)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrTriangleMeshBeginVertexBufferUpdateFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["mesh"], mesh, json_options);
        FieldToJson(args["outVertexCount"], outVertexCount, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrTriangleMeshEndVertexBufferUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrTriangleMeshEndVertexBufferUpdateFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["mesh"], mesh, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["outPassthrough"], outPassthrough, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyPassthroughFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyPassthroughFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["passthrough"], passthrough, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughStartFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughStartFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["passthrough"], passthrough, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughPauseFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughPauseFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["passthrough"], passthrough, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["outLayer"], outLayer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyPassthroughLayerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyPassthroughLayerFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["layer"], layer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughLayerPauseFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughLayerPauseFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["layer"], layer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughLayerResumeFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughLayerResumeFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["layer"], layer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughLayerSetStyleFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer,
    StructPointerDecoder<Decoded_XrPassthroughStyleFB>* style)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughLayerSetStyleFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["layer"], layer, json_options);
        FieldToJson(args["style"], style, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["outGeometryInstance"], outGeometryInstance, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyGeometryInstanceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyGeometryInstanceFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGeometryInstanceSetTransformFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrGeometryInstanceTransformFB>* transformation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGeometryInstanceSetTransformFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["transformation"], transformation, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["pathCapacityInput"], pathCapacityInput, json_options);
        FieldToJson(args["pathCountOutput"], pathCountOutput, json_options);
        FieldToJson(args["paths"], paths, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetRenderModelPropertiesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPath                                      path,
    StructPointerDecoder<Decoded_XrRenderModelPropertiesFB>* properties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetRenderModelPropertiesFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["path"], path, json_options);
        FieldToJson(args["properties"], properties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetEnvironmentDepthEstimationVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrBool32                                    enabled)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetEnvironmentDepthEstimationVARJO");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        Bool32ToJson(args["enabled"], enabled, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetMarkerTrackingVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrBool32                                    enabled)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetMarkerTrackingVARJO");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        Bool32ToJson(args["enabled"], enabled, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["markerId"], markerId, json_options);
        FieldToJson(args["timeout"], timeout, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["markerId"], markerId, json_options);
        Bool32ToJson(args["enable"], enable, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["markerId"], markerId, json_options);
        FieldToJson(args["size"], size, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["space"], space, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetViewOffsetVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    float                                       offset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetViewOffsetVARJO");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["offset"], offset, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["space"], space, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["markerDetector"], markerDetector, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyMarkerDetectorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyMarkerDetectorML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSnapshotMarkerDetectorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    StructPointerDecoder<Decoded_XrMarkerDetectorSnapshotInfoML>* snapshotInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSnapshotMarkerDetectorML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector, json_options);
        FieldToJson(args["snapshotInfo"], snapshotInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerDetectorStateML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    StructPointerDecoder<Decoded_XrMarkerDetectorStateML>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerDetectorStateML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector, json_options);
        FieldToJson(args["state"], state, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector, json_options);
        FieldToJson(args["markerCapacityInput"], markerCapacityInput, json_options);
        FieldToJson(args["markerCountOutput"], markerCountOutput, json_options);
        HandleToJson(args["markers"], markers, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerReprojectionErrorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    XrMarkerML                                  marker,
    PointerDecoder<float>*                      reprojectionErrorMeters)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerReprojectionErrorML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector, json_options);
        HandleToJson(args["marker"], marker, json_options);
        FieldToJson(args["reprojectionErrorMeters"], reprojectionErrorMeters, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerLengthML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    XrMarkerML                                  marker,
    PointerDecoder<float>*                      meters)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerLengthML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector, json_options);
        HandleToJson(args["marker"], marker, json_options);
        FieldToJson(args["meters"], meters, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerNumberML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    XrMarkerML                                  marker,
    PointerDecoder<uint64_t>*                   number)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerNumberML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector, json_options);
        HandleToJson(args["marker"], marker, json_options);
        FieldToJson(args["number"], number, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetMarkerStringML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    XrMarkerML                                  marker,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetMarkerStringML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["markerDetector"], markerDetector, json_options);
        HandleToJson(args["marker"], marker, json_options);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput, json_options);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["space"], space, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnableLocalizationEventsML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrLocalizationEnableEventsInfoML>* info)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnableLocalizationEventsML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["queryInfo"], queryInfo, json_options);
        FieldToJson(args["mapCapacityInput"], mapCapacityInput, json_options);
        FieldToJson(args["mapCountOutput"], mapCountOutput, json_options);
        FieldToJson(args["maps"], maps, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrRequestMapLocalizationML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrMapLocalizationRequestInfoML>* requestInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrRequestMapLocalizationML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["requestInfo"], requestInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrImportLocalizationMapML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrLocalizationMapImportInfoML>* importInfo,
    StructPointerDecoder<Decoded_XrUuidEXT>*    mapUuid)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrImportLocalizationMapML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["importInfo"], importInfo, json_options);
        FieldToJson(args["mapUuid"], mapUuid, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateExportedLocalizationMapML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrUuidEXT>*    mapUuid,
    HandlePointerDecoder<XrExportedLocalizationMapML>* map)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateExportedLocalizationMapML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["mapUuid"], mapUuid, json_options);
        HandleToJson(args["map"], map, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyExportedLocalizationMapML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            map)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyExportedLocalizationMapML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["map"], map, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["map"], map, json_options);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput, json_options);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrCreateSpatialAnchorStoreConnectionMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    HandlePointerDecoder<XrSpatialAnchorStoreConnectionMSFT>* spatialAnchorStore)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrCreateSpatialAnchorStoreConnectionMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySpatialAnchorStoreConnectionMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySpatialAnchorStoreConnectionMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPersistSpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore,
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceInfoMSFT>* spatialAnchorPersistenceInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPersistSpatialAnchorMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore, json_options);
        FieldToJson(args["spatialAnchorPersistenceInfo"], spatialAnchorPersistenceInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore, json_options);
        FieldToJson(args["spatialAnchorNameCapacityInput"], spatialAnchorNameCapacityInput, json_options);
        FieldToJson(args["spatialAnchorNameCountOutput"], spatialAnchorNameCountOutput, json_options);
        FieldToJson(args["spatialAnchorNames"], spatialAnchorNames, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["spatialAnchorCreateInfo"], spatialAnchorCreateInfo, json_options);
        HandleToJson(args["spatialAnchor"], spatialAnchor, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrUnpersistSpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore,
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT>* spatialAnchorPersistenceName)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrUnpersistSpatialAnchorMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore, json_options);
        FieldToJson(args["spatialAnchorPersistenceName"], spatialAnchorPersistenceName, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrClearSpatialAnchorStoreMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrClearSpatialAnchorStoreMSFT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["spatialAnchorStore"], spatialAnchorStore, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene, json_options);
        FieldToJson(args["markerId"], markerId, json_options);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput, json_options);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["scene"], scene, json_options);
        FieldToJson(args["markerId"], markerId, json_options);
        FieldToJson(args["bufferCapacityInput"], bufferCapacityInput, json_options);
        FieldToJson(args["bufferCountOutput"], bufferCountOutput, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        HandleToJson(args["requestId"], requestId, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrRetrieveSpaceQueryResultsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrAsyncRequestIdFB                          requestId,
    StructPointerDecoder<Decoded_XrSpaceQueryResultsFB>* results)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrRetrieveSpaceQueryResultsFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["requestId"], requestId, json_options);
        FieldToJson(args["results"], results, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        HandleToJson(args["requestId"], requestId, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        HandleToJson(args["requestId"], requestId, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetAudioOutputDeviceGuidOculus(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    WStringDecoder*                             buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetAudioOutputDeviceGuidOculus");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetAudioInputDeviceGuidOculus(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    WStringDecoder*                             buffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetAudioInputDeviceGuidOculus");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        HandleToJson(args["requestId"], requestId, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["boundingBox2DOutput"], boundingBox2DOutput, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["boundingBox3DOutput"], boundingBox3DOutput, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["semanticLabelsOutput"], semanticLabelsOutput, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["boundary2DOutput"], boundary2DOutput, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["roomLayoutOutput"], roomLayoutOutput, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetDigitalLensControlALMALENCE(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrDigitalLensControlALMALENCE>* digitalLensControl)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetDigitalLensControlALMALENCE");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["digitalLensControl"], digitalLensControl, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        HandleToJson(args["requestId"], requestId, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["spaceContainerOutput"], spaceContainerOutput, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetFoveationEyeTrackedStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFoveationEyeTrackedStateMETA>* foveationState)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetFoveationEyeTrackedStateMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["foveationState"], foveationState, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["faceTracker"], faceTracker, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyFaceTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            faceTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyFaceTrackerFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["faceTracker"], faceTracker, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["faceTracker"], faceTracker, json_options);
        FieldToJson(args["expressionInfo"], expressionInfo, json_options);
        FieldToJson(args["expressionWeights"], expressionWeights, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["eyeTracker"], eyeTracker, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyEyeTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            eyeTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyEyeTrackerFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["eyeTracker"], eyeTracker, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["eyeTracker"], eyeTracker, json_options);
        FieldToJson(args["gazeInfo"], gazeInfo, json_options);
        FieldToJson(args["eyeGazes"], eyeGazes, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrPassthroughLayerSetKeyboardHandsIntensityFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer,
    StructPointerDecoder<Decoded_XrPassthroughKeyboardHandsIntensityFB>* intensity)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrPassthroughLayerSetKeyboardHandsIntensityFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["layer"], layer, json_options);
        FieldToJson(args["intensity"], intensity, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetDeviceSampleRateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo,
    StructPointerDecoder<Decoded_XrDevicePcmSampleRateGetInfoFB>* deviceSampleRate)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetDeviceSampleRateFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["hapticActionInfo"], hapticActionInfo, json_options);
        FieldToJson(args["deviceSampleRate"], deviceSampleRate, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetPassthroughPreferencesMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPassthroughPreferencesMETA>* preferences)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetPassthroughPreferencesMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["preferences"], preferences, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["keyboard"], keyboard, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyVirtualKeyboardMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyVirtualKeyboardMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["keyboard"], keyboard, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["keyboardSpace"], keyboardSpace, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSuggestVirtualKeyboardLocationMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardLocationInfoMETA>* locationInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSuggestVirtualKeyboardLocationMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard, json_options);
        FieldToJson(args["locationInfo"], locationInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVirtualKeyboardScaleMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    PointerDecoder<float>*                      scale)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVirtualKeyboardScaleMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard, json_options);
        FieldToJson(args["scale"], scale, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetVirtualKeyboardModelVisibilityMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA>* modelVisibility)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetVirtualKeyboardModelVisibilityMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard, json_options);
        FieldToJson(args["modelVisibility"], modelVisibility, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetVirtualKeyboardModelAnimationStatesMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardModelAnimationStatesMETA>* animationStates)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetVirtualKeyboardModelAnimationStatesMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard, json_options);
        FieldToJson(args["animationStates"], animationStates, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard, json_options);
        FieldToJson(args["textureIdCapacityInput"], textureIdCapacityInput, json_options);
        FieldToJson(args["textureIdCountOutput"], textureIdCountOutput, json_options);
        FieldToJson(args["textureIds"], textureIds, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard, json_options);
        FieldToJson(args["textureId"], textureId, json_options);
        FieldToJson(args["textureData"], textureData, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard, json_options);
        FieldToJson(args["info"], info, json_options);
        FieldToJson(args["interactorRootPose"], interactorRootPose, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrChangeVirtualKeyboardTextContextMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardTextContextChangeInfoMETA>* changeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrChangeVirtualKeyboardTextContextMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["keyboard"], keyboard, json_options);
        FieldToJson(args["changeInfo"], changeInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["cameraCapacityInput"], cameraCapacityInput, json_options);
        FieldToJson(args["cameraCountOutput"], cameraCountOutput, json_options);
        FieldToJson(args["cameras"], cameras, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["counterPathCapacityInput"], counterPathCapacityInput, json_options);
        FieldToJson(args["counterPathCountOutput"], counterPathCountOutput, json_options);
        HandleToJson(args["counterPaths"], counterPaths, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrSetPerformanceMetricsStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrSetPerformanceMetricsStateMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["state"], state, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetPerformanceMetricsStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA>* state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetPerformanceMetricsStateMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["state"], state, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrQueryPerformanceMetricsCounterMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPath                                      counterPath,
    StructPointerDecoder<Decoded_XrPerformanceMetricsCounterMETA>* counter)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrQueryPerformanceMetricsCounterMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        HandleToJson(args["counterPath"], counterPath, json_options);
        FieldToJson(args["counter"], counter, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        HandleToJson(args["requestId"], requestId, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        HandleToJson(args["user"], user, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpaceUserIdFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            user,
    PointerDecoder<XrSpaceUserIdFB>*            userId)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpaceUserIdFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["user"], user, json_options);
        FieldToJson(args["userId"], userId, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroySpaceUserFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            user)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroySpaceUserFB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["user"], user, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["info"], info, json_options);
        FieldToJson(args["resolution"], resolution, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["passthrough"], passthrough, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["colorLut"], colorLut, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyPassthroughColorLutMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            colorLut)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyPassthroughColorLutMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["colorLut"], colorLut, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrUpdatePassthroughColorLutMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            colorLut,
    StructPointerDecoder<Decoded_XrPassthroughColorLutUpdateInfoMETA>* updateInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrUpdatePassthroughColorLutMETA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["colorLut"], colorLut, json_options);
        FieldToJson(args["updateInfo"], updateInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["space"], space, json_options);
        FieldToJson(args["getInfo"], getInfo, json_options);
        FieldToJson(args["triangleMeshOutput"], triangleMeshOutput, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["faceTracker"], faceTracker, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyFaceTracker2FB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            faceTracker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyFaceTracker2FB");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["faceTracker"], faceTracker, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["faceTracker"], faceTracker, json_options);
        FieldToJson(args["expressionInfo"], expressionInfo, json_options);
        FieldToJson(args["expressionWeights"], expressionWeights, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["domain"], domain, json_options);
        FieldToJson(args["hint"], hint, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["passthrough"], passthrough, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyPassthroughHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyPassthroughHTC");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["passthrough"], passthrough, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrApplyFoveationHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFoveationApplyInfoHTC>* applyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrApplyFoveationHTC");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["applyInfo"], applyInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["anchor"], anchor, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetSpatialAnchorNameHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            anchor,
    StructPointerDecoder<Decoded_XrSpatialAnchorNameHTC>* name)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetSpatialAnchorNameHTC");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["anchor"], anchor, json_options);
        FieldToJson(args["name"], name, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrApplyForceFeedbackCurlMNDX(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker,
    StructPointerDecoder<Decoded_XrForceFeedbackCurlApplyLocationsMNDX>* locations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrApplyForceFeedbackCurlMNDX");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["handTracker"], handTracker, json_options);
        FieldToJson(args["locations"], locations, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["createInfo"], createInfo, json_options);
        HandleToJson(args["planeDetector"], planeDetector, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrDestroyPlaneDetectorEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrDestroyPlaneDetectorEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["planeDetector"], planeDetector, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrBeginPlaneDetectionEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector,
    StructPointerDecoder<Decoded_XrPlaneDetectorBeginInfoEXT>* beginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrBeginPlaneDetectionEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["planeDetector"], planeDetector, json_options);
        FieldToJson(args["beginInfo"], beginInfo, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrGetPlaneDetectionStateEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector,
    PointerDecoder<XrPlaneDetectionStateEXT>*   state)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrGetPlaneDetectionStateEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["planeDetector"], planeDetector, json_options);
        FieldToJson(args["state"], state, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["planeDetector"], planeDetector, json_options);
        FieldToJson(args["info"], info, json_options);
        FieldToJson(args["locations"], locations, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["planeDetector"], planeDetector, json_options);
        FieldToJson(args["planeId"], planeId, json_options);
        FieldToJson(args["polygonBufferIndex"], polygonBufferIndex, json_options);
        FieldToJson(args["polygonBuffer"], polygonBuffer, json_options);
    WriteBlockEnd();
}

void OpenXrExportJsonConsumer::Process_xrEnableUserCalibrationEventsML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrUserCalibrationEnableEventsInfoML>* enableInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "xrEnableUserCalibrationEventsML");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["enableInfo"], enableInfo, json_options);
    WriteBlockEnd();
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
