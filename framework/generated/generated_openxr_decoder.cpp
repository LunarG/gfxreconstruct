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

#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/value_decoder.h"
#include "decode/openxr_next_node.h"
#include "generated/generated_openxr_decoder.h"
#include "generated/generated_openxr_struct_decoders_forward.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

#include <cstddef>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t OpenXrDecoder::Decode_xrDestroyInstance(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyInstance(call_info, return_value, instance);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetInstanceProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrInstanceProperties> instanceProperties;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += instanceProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetInstanceProperties(call_info, return_value, instance, &instanceProperties);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrPollEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrEventDataBuffer> eventData;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += eventData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrPollEvent(call_info, return_value, instance, &eventData);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrResultToString(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrResult value;
    StringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &value);
    char* buffer_store = nullptr;
    if (XR_MAX_RESULT_STRING_SIZE > 0)
    {
        buffer_store = new char[XR_MAX_RESULT_STRING_SIZE];
        buffer.SetExternalMemory(buffer_store, XR_MAX_RESULT_STRING_SIZE);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrResultToString(call_info, return_value, instance, value, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrStructureTypeToString(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrStructureType value;
    StringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &value);
    char* buffer_store = nullptr;
    if (XR_MAX_STRUCTURE_NAME_SIZE > 0)
    {
        buffer_store = new char[XR_MAX_STRUCTURE_NAME_SIZE];
        buffer.SetExternalMemory(buffer_store, XR_MAX_STRUCTURE_NAME_SIZE);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrStructureTypeToString(call_info, return_value, instance, value, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSystem(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrSystemGetInfo> getInfo;
    HandlePointerDecoder<XrSystemId> systemId;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += systemId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSystem(call_info, return_value, instance, &getInfo, &systemId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSystemProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    StructPointerDecoder<Decoded_XrSystemProperties> properties;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += properties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSystemProperties(call_info, return_value, instance, systemId, &properties);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateEnvironmentBlendModes(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    XrViewConfigurationType viewConfigurationType;
    uint32_t environmentBlendModeCapacityInput;
    PointerDecoder<uint32_t> environmentBlendModeCountOutput;
    PointerDecoder<XrEnvironmentBlendMode> environmentBlendModes;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewConfigurationType);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &environmentBlendModeCapacityInput);
    bytes_read += environmentBlendModeCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += environmentBlendModes.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateEnvironmentBlendModes(call_info, return_value, instance, systemId, viewConfigurationType, environmentBlendModeCapacityInput, &environmentBlendModeCountOutput, &environmentBlendModes);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSession(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrSessionCreateInfo> createInfo;
    HandlePointerDecoder<XrSession> session;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += session.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSession(call_info, return_value, instance, &createInfo, &session);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroySession(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroySession(call_info, return_value, session);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateReferenceSpaces(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    uint32_t spaceCapacityInput;
    PointerDecoder<uint32_t> spaceCountOutput;
    PointerDecoder<XrReferenceSpaceType> spaces;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &spaceCapacityInput);
    bytes_read += spaceCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += spaces.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateReferenceSpaces(call_info, return_value, session, spaceCapacityInput, &spaceCountOutput, &spaces);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateReferenceSpace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrReferenceSpaceCreateInfo> createInfo;
    HandlePointerDecoder<XrSpace> space;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += space.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateReferenceSpace(call_info, return_value, session, &createInfo, &space);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetReferenceSpaceBoundsRect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrReferenceSpaceType referenceSpaceType;
    StructPointerDecoder<Decoded_XrExtent2Df> bounds;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &referenceSpaceType);
    bytes_read += bounds.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetReferenceSpaceBoundsRect(call_info, return_value, session, referenceSpaceType, &bounds);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateActionSpace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrActionSpaceCreateInfo> createInfo;
    HandlePointerDecoder<XrSpace> space;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += space.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateActionSpace(call_info, return_value, session, &createInfo, &space);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrLocateSpace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId space;
    format::HandleId baseSpace;
    XrTime time;
    StructPointerDecoder<Decoded_XrSpaceLocation> location;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseSpace);
    bytes_read += ValueDecoder::DecodeInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &time);
    bytes_read += location.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrLocateSpace(call_info, return_value, space, baseSpace, time, &location);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroySpace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId space;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroySpace(call_info, return_value, space);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateViewConfigurations(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    uint32_t viewConfigurationTypeCapacityInput;
    PointerDecoder<uint32_t> viewConfigurationTypeCountOutput;
    PointerDecoder<XrViewConfigurationType> viewConfigurationTypes;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewConfigurationTypeCapacityInput);
    bytes_read += viewConfigurationTypeCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += viewConfigurationTypes.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateViewConfigurations(call_info, return_value, instance, systemId, viewConfigurationTypeCapacityInput, &viewConfigurationTypeCountOutput, &viewConfigurationTypes);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetViewConfigurationProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    XrViewConfigurationType viewConfigurationType;
    StructPointerDecoder<Decoded_XrViewConfigurationProperties> configurationProperties;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewConfigurationType);
    bytes_read += configurationProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetViewConfigurationProperties(call_info, return_value, instance, systemId, viewConfigurationType, &configurationProperties);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateViewConfigurationViews(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    XrViewConfigurationType viewConfigurationType;
    uint32_t viewCapacityInput;
    PointerDecoder<uint32_t> viewCountOutput;
    StructPointerDecoder<Decoded_XrViewConfigurationView> views;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewConfigurationType);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewCapacityInput);
    bytes_read += viewCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += views.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateViewConfigurationViews(call_info, return_value, instance, systemId, viewConfigurationType, viewCapacityInput, &viewCountOutput, &views);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateSwapchainFormats(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    uint32_t formatCapacityInput;
    PointerDecoder<uint32_t> formatCountOutput;
    PointerDecoder<int64_t> formats;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &formatCapacityInput);
    bytes_read += formatCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += formats.DecodeInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateSwapchainFormats(call_info, return_value, session, formatCapacityInput, &formatCountOutput, &formats);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSwapchain(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSwapchainCreateInfo> createInfo;
    HandlePointerDecoder<XrSwapchain> swapchain;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += swapchain.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSwapchain(call_info, return_value, session, &createInfo, &swapchain);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroySwapchain(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId swapchain;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroySwapchain(call_info, return_value, swapchain);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrAcquireSwapchainImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId swapchain;
    StructPointerDecoder<Decoded_XrSwapchainImageAcquireInfo> acquireInfo;
    PointerDecoder<uint32_t> index;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += acquireInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += index.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrAcquireSwapchainImage(call_info, return_value, swapchain, &acquireInfo, &index);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrWaitSwapchainImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId swapchain;
    StructPointerDecoder<Decoded_XrSwapchainImageWaitInfo> waitInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += waitInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrWaitSwapchainImage(call_info, return_value, swapchain, &waitInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrReleaseSwapchainImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId swapchain;
    StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo> releaseInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += releaseInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrReleaseSwapchainImage(call_info, return_value, swapchain, &releaseInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrBeginSession(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSessionBeginInfo> beginInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += beginInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrBeginSession(call_info, return_value, session, &beginInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEndSession(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEndSession(call_info, return_value, session);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrRequestExitSession(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrRequestExitSession(call_info, return_value, session);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrWaitFrame(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrFrameWaitInfo> frameWaitInfo;
    StructPointerDecoder<Decoded_XrFrameState> frameState;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += frameWaitInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += frameState.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrWaitFrame(call_info, return_value, session, &frameWaitInfo, &frameState);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrBeginFrame(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrFrameBeginInfo> frameBeginInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += frameBeginInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrBeginFrame(call_info, return_value, session, &frameBeginInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEndFrame(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrFrameEndInfo> frameEndInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += frameEndInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEndFrame(call_info, return_value, session, &frameEndInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrLocateViews(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrViewLocateInfo> viewLocateInfo;
    StructPointerDecoder<Decoded_XrViewState> viewState;
    uint32_t viewCapacityInput;
    PointerDecoder<uint32_t> viewCountOutput;
    StructPointerDecoder<Decoded_XrView> views;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += viewLocateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += viewState.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewCapacityInput);
    bytes_read += viewCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += views.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrLocateViews(call_info, return_value, session, &viewLocateInfo, &viewState, viewCapacityInput, &viewCountOutput, &views);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrStringToPath(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StringDecoder pathString;
    HandlePointerDecoder<XrPath> path;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pathString.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += path.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrStringToPath(call_info, return_value, instance, &pathString, &path);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrPathToString(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrPath path;
    uint32_t bufferCapacityInput;
    PointerDecoder<uint32_t> bufferCountOutput;
    StringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &path);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferCapacityInput);
    bytes_read += bufferCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    char* buffer_store = nullptr;
    if (bufferCapacityInput > 0)
    {
        buffer_store = new char[bufferCapacityInput];
        buffer.SetExternalMemory(buffer_store, bufferCapacityInput);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrPathToString(call_info, return_value, instance, path, bufferCapacityInput, &bufferCountOutput, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateActionSet(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrActionSetCreateInfo> createInfo;
    HandlePointerDecoder<XrActionSet> actionSet;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += actionSet.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateActionSet(call_info, return_value, instance, &createInfo, &actionSet);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyActionSet(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId actionSet;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &actionSet);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyActionSet(call_info, return_value, actionSet);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateAction(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId actionSet;
    StructPointerDecoder<Decoded_XrActionCreateInfo> createInfo;
    HandlePointerDecoder<XrAction> action;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &actionSet);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += action.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateAction(call_info, return_value, actionSet, &createInfo, &action);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyAction(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId action;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &action);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyAction(call_info, return_value, action);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSuggestInteractionProfileBindings(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrInteractionProfileSuggestedBinding> suggestedBindings;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += suggestedBindings.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSuggestInteractionProfileBindings(call_info, return_value, instance, &suggestedBindings);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrAttachSessionActionSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSessionActionSetsAttachInfo> attachInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += attachInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrAttachSessionActionSets(call_info, return_value, session, &attachInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetCurrentInteractionProfile(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPath topLevelUserPath;
    StructPointerDecoder<Decoded_XrInteractionProfileState> interactionProfile;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &topLevelUserPath);
    bytes_read += interactionProfile.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetCurrentInteractionProfile(call_info, return_value, session, topLevelUserPath, &interactionProfile);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetActionStateBoolean(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrActionStateGetInfo> getInfo;
    StructPointerDecoder<Decoded_XrActionStateBoolean> state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += state.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetActionStateBoolean(call_info, return_value, session, &getInfo, &state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetActionStateFloat(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrActionStateGetInfo> getInfo;
    StructPointerDecoder<Decoded_XrActionStateFloat> state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += state.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetActionStateFloat(call_info, return_value, session, &getInfo, &state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetActionStateVector2f(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrActionStateGetInfo> getInfo;
    StructPointerDecoder<Decoded_XrActionStateVector2f> state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += state.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetActionStateVector2f(call_info, return_value, session, &getInfo, &state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetActionStatePose(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrActionStateGetInfo> getInfo;
    StructPointerDecoder<Decoded_XrActionStatePose> state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += state.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetActionStatePose(call_info, return_value, session, &getInfo, &state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSyncActions(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrActionsSyncInfo> syncInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += syncInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSyncActions(call_info, return_value, session, &syncInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateBoundSourcesForAction(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrBoundSourcesForActionEnumerateInfo> enumerateInfo;
    uint32_t sourceCapacityInput;
    PointerDecoder<uint32_t> sourceCountOutput;
    HandlePointerDecoder<XrPath> sources;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += enumerateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sourceCapacityInput);
    bytes_read += sourceCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += sources.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateBoundSourcesForAction(call_info, return_value, session, &enumerateInfo, sourceCapacityInput, &sourceCountOutput, &sources);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetInputSourceLocalizedName(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrInputSourceLocalizedNameGetInfo> getInfo;
    uint32_t bufferCapacityInput;
    PointerDecoder<uint32_t> bufferCountOutput;
    StringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferCapacityInput);
    bytes_read += bufferCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    char* buffer_store = nullptr;
    if (bufferCapacityInput > 0)
    {
        buffer_store = new char[bufferCapacityInput];
        buffer.SetExternalMemory(buffer_store, bufferCapacityInput);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetInputSourceLocalizedName(call_info, return_value, session, &getInfo, bufferCapacityInput, &bufferCountOutput, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrApplyHapticFeedback(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrHapticActionInfo> hapticActionInfo;
    StructPointerDecoder<Decoded_XrHapticBaseHeader>* hapticFeedback;
    StructPointerDecoder<Decoded_XrHapticBaseHeader> haptic_base_header;
    StructPointerDecoder<Decoded_XrHapticVibration> haptic_vibration;
    StructPointerDecoder<Decoded_XrHapticAmplitudeEnvelopeVibrationFB> haptic_amplitude_envelope_vibration_fb;
    StructPointerDecoder<Decoded_XrHapticPcmVibrationFB> haptic_pcm_vibration_fb;
    XrResult return_value;

    bool     peak_is_null    = false;
    bool     peak_is_struct  = false;
    bool     peak_has_length = false;
    size_t   peak_length{};
    uint32_t peak_structure_type = 0;
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += hapticActionInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    if (PointerDecoderBase::PeekAttributesAndType((parameter_buffer + bytes_read),
                                                   (buffer_size - bytes_read),
                                                   peak_is_null,
                                                   peak_is_struct,
                                                   peak_has_length,
                                                   peak_length,
                                                   peak_structure_type))
     {
         XrStructureType xr_type = static_cast<XrStructureType>(peak_structure_type);
         switch (xr_type)
         {
             case XR_TYPE_HAPTIC_VIBRATION:
                 bytes_read += haptic_vibration.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 hapticFeedback = reinterpret_cast<StructPointerDecoder<Decoded_XrHapticBaseHeader>*>(&haptic_vibration);
                 break;
             case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
                 bytes_read += haptic_amplitude_envelope_vibration_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 hapticFeedback = reinterpret_cast<StructPointerDecoder<Decoded_XrHapticBaseHeader>*>(&haptic_amplitude_envelope_vibration_fb);
                 break;
             case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
                 bytes_read += haptic_pcm_vibration_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 hapticFeedback = reinterpret_cast<StructPointerDecoder<Decoded_XrHapticBaseHeader>*>(&haptic_pcm_vibration_fb);
                 break;
             default:
                 bytes_read += haptic_base_header.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 hapticFeedback = &haptic_base_header;
                 break;
         }
     }
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrApplyHapticFeedback(call_info, return_value, session, &hapticActionInfo, hapticFeedback);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrStopHapticFeedback(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrHapticActionInfo> hapticActionInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += hapticActionInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrStopHapticFeedback(call_info, return_value, session, &hapticActionInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateApiLayerInstance(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_XrInstanceCreateInfo> info;
    StructPointerDecoder<Decoded_XrApiLayerCreateInfo> layerInfo;
    HandlePointerDecoder<XrInstance> instance;
    XrResult return_value;

    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += layerInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += instance.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateApiLayerInstance(call_info, return_value, &info, &layerInfo, &instance);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetAndroidApplicationThreadKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrAndroidThreadTypeKHR threadType;
    uint32_t threadId;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &threadType);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &threadId);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetAndroidApplicationThreadKHR(call_info, return_value, session, threadType, threadId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSwapchainAndroidSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSwapchainCreateInfo> info;
    HandlePointerDecoder<XrSwapchain> swapchain;
    uint64_t surface;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += swapchain.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSwapchainAndroidSurfaceKHR(call_info, return_value, session, &info, &swapchain, surface);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetOpenGLGraphicsRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLKHR> graphicsRequirements;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += graphicsRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetOpenGLGraphicsRequirementsKHR(call_info, return_value, instance, systemId, &graphicsRequirements);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetOpenGLESGraphicsRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLESKHR> graphicsRequirements;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += graphicsRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetOpenGLESGraphicsRequirementsKHR(call_info, return_value, instance, systemId, &graphicsRequirements);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVulkanInstanceExtensionsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    uint32_t bufferCapacityInput;
    PointerDecoder<uint32_t> bufferCountOutput;
    StringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferCapacityInput);
    bytes_read += bufferCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    char* buffer_store = nullptr;
    if (bufferCapacityInput > 0)
    {
        buffer_store = new char[bufferCapacityInput];
        buffer.SetExternalMemory(buffer_store, bufferCapacityInput);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVulkanInstanceExtensionsKHR(call_info, return_value, instance, systemId, bufferCapacityInput, &bufferCountOutput, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVulkanDeviceExtensionsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    uint32_t bufferCapacityInput;
    PointerDecoder<uint32_t> bufferCountOutput;
    StringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferCapacityInput);
    bytes_read += bufferCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    char* buffer_store = nullptr;
    if (bufferCapacityInput > 0)
    {
        buffer_store = new char[bufferCapacityInput];
        buffer.SetExternalMemory(buffer_store, bufferCapacityInput);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVulkanDeviceExtensionsKHR(call_info, return_value, instance, systemId, bufferCapacityInput, &bufferCountOutput, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVulkanGraphicsDeviceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    format::HandleId vkInstance;
    HandlePointerDecoder<VkPhysicalDevice> vkPhysicalDevice;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vkInstance);
    bytes_read += vkPhysicalDevice.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVulkanGraphicsDeviceKHR(call_info, return_value, instance, systemId, vkInstance, &vkPhysicalDevice);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVulkanGraphicsRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR> graphicsRequirements;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += graphicsRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVulkanGraphicsRequirementsKHR(call_info, return_value, instance, systemId, &graphicsRequirements);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetD3D11GraphicsRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D11KHR> graphicsRequirements;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += graphicsRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetD3D11GraphicsRequirementsKHR(call_info, return_value, instance, systemId, &graphicsRequirements);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetD3D12GraphicsRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D12KHR> graphicsRequirements;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += graphicsRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetD3D12GraphicsRequirementsKHR(call_info, return_value, instance, systemId, &graphicsRequirements);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVisibilityMaskKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrViewConfigurationType viewConfigurationType;
    uint32_t viewIndex;
    XrVisibilityMaskTypeKHR visibilityMaskType;
    StructPointerDecoder<Decoded_XrVisibilityMaskKHR> visibilityMask;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewConfigurationType);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewIndex);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &visibilityMaskType);
    bytes_read += visibilityMask.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVisibilityMaskKHR(call_info, return_value, session, viewConfigurationType, viewIndex, visibilityMaskType, &visibilityMask);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrConvertWin32PerformanceCounterToTimeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<LARGE_INTEGER> performanceCounter;
    PointerDecoder<XrTime> time;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += performanceCounter.DecodeLARGE_INTEGER((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += time.DecodeInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrConvertWin32PerformanceCounterToTimeKHR(call_info, return_value, instance, &performanceCounter, &time);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrConvertTimeToWin32PerformanceCounterKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrTime time;
    PointerDecoder<LARGE_INTEGER> performanceCounter;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &time);
    bytes_read += performanceCounter.DecodeLARGE_INTEGER((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrConvertTimeToWin32PerformanceCounterKHR(call_info, return_value, instance, time, &performanceCounter);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrConvertTimespecTimeToTimeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_timespec> timespecTime;
    PointerDecoder<XrTime> time;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += timespecTime.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += time.DecodeInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrConvertTimespecTimeToTimeKHR(call_info, return_value, instance, &timespecTime, &time);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrConvertTimeToTimespecTimeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrTime time;
    StructPointerDecoder<Decoded_timespec> timespecTime;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &time);
    bytes_read += timespecTime.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrConvertTimeToTimespecTimeKHR(call_info, return_value, instance, time, &timespecTime);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrInitializeLoaderKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_XrLoaderInitInfoBaseHeaderKHR>* loaderInitInfo;
    StructPointerDecoder<Decoded_XrLoaderInitInfoBaseHeaderKHR> loader_init_info_base_header_khr;
    StructPointerDecoder<Decoded_XrLoaderInitInfoAndroidKHR> loader_init_info_android_khr;
    XrResult return_value;

    bool     peak_is_null    = false;
    bool     peak_is_struct  = false;
    bool     peak_has_length = false;
    size_t   peak_length{};
    uint32_t peak_structure_type = 0;
    if (PointerDecoderBase::PeekAttributesAndType((parameter_buffer + bytes_read),
                                                   (buffer_size - bytes_read),
                                                   peak_is_null,
                                                   peak_is_struct,
                                                   peak_has_length,
                                                   peak_length,
                                                   peak_structure_type))
     {
         XrStructureType xr_type = static_cast<XrStructureType>(peak_structure_type);
         switch (xr_type)
         {
             case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
                 bytes_read += loader_init_info_android_khr.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 loaderInitInfo = reinterpret_cast<StructPointerDecoder<Decoded_XrLoaderInitInfoBaseHeaderKHR>*>(&loader_init_info_android_khr);
                 break;
             default:
                 bytes_read += loader_init_info_base_header_khr.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 loaderInitInfo = &loader_init_info_base_header_khr;
                 break;
         }
     }
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrInitializeLoaderKHR(call_info, return_value, loaderInitInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateVulkanInstanceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrVulkanInstanceCreateInfoKHR> createInfo;
    HandlePointerDecoder<VkInstance> vulkanInstance;
    PointerDecoder<VkResult> vulkanResult;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += vulkanInstance.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += vulkanResult.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateVulkanInstanceKHR(call_info, return_value, instance, &createInfo, &vulkanInstance, &vulkanResult);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateVulkanDeviceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrVulkanDeviceCreateInfoKHR> createInfo;
    HandlePointerDecoder<VkDevice> vulkanDevice;
    PointerDecoder<VkResult> vulkanResult;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += vulkanDevice.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += vulkanResult.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateVulkanDeviceKHR(call_info, return_value, instance, &createInfo, &vulkanDevice, &vulkanResult);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVulkanGraphicsDevice2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrVulkanGraphicsDeviceGetInfoKHR> getInfo;
    HandlePointerDecoder<VkPhysicalDevice> vulkanPhysicalDevice;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += vulkanPhysicalDevice.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVulkanGraphicsDevice2KHR(call_info, return_value, instance, &getInfo, &vulkanPhysicalDevice);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVulkanGraphicsRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR> graphicsRequirements;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += graphicsRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVulkanGraphicsRequirements2KHR(call_info, return_value, instance, systemId, &graphicsRequirements);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrPerfSettingsSetPerformanceLevelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPerfSettingsDomainEXT domain;
    XrPerfSettingsLevelEXT level;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &domain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &level);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrPerfSettingsSetPerformanceLevelEXT(call_info, return_value, session, domain, level);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrThermalGetTemperatureTrendEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPerfSettingsDomainEXT domain;
    PointerDecoder<XrPerfSettingsNotificationLevelEXT> notificationLevel;
    PointerDecoder<float> tempHeadroom;
    PointerDecoder<float> tempSlope;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &domain);
    bytes_read += notificationLevel.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += tempHeadroom.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += tempSlope.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrThermalGetTemperatureTrendEXT(call_info, return_value, session, domain, &notificationLevel, &tempHeadroom, &tempSlope);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetDebugUtilsObjectNameEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrDebugUtilsObjectNameInfoEXT> nameInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += nameInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetDebugUtilsObjectNameEXT(call_info, return_value, instance, &nameInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateDebugUtilsMessengerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrDebugUtilsMessengerCreateInfoEXT> createInfo;
    HandlePointerDecoder<XrDebugUtilsMessengerEXT> messenger;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += messenger.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateDebugUtilsMessengerEXT(call_info, return_value, instance, &createInfo, &messenger);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyDebugUtilsMessengerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId messenger;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messenger);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyDebugUtilsMessengerEXT(call_info, return_value, messenger);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSubmitDebugUtilsMessageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrDebugUtilsMessageSeverityFlagsEXT messageSeverity;
    XrDebugUtilsMessageTypeFlagsEXT messageTypes;
    StructPointerDecoder<Decoded_XrDebugUtilsMessengerCallbackDataEXT> callbackData;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeFlags64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messageSeverity);
    bytes_read += ValueDecoder::DecodeFlags64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messageTypes);
    bytes_read += callbackData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSubmitDebugUtilsMessageEXT(call_info, return_value, instance, messageSeverity, messageTypes, &callbackData);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSessionBeginDebugUtilsLabelRegionEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT> labelInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += labelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSessionBeginDebugUtilsLabelRegionEXT(call_info, return_value, session, &labelInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSessionEndDebugUtilsLabelRegionEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSessionEndDebugUtilsLabelRegionEXT(call_info, return_value, session);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSessionInsertDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT> labelInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += labelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSessionInsertDebugUtilsLabelEXT(call_info, return_value, session, &labelInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSpatialAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoMSFT> createInfo;
    HandlePointerDecoder<XrSpatialAnchorMSFT> anchor;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += anchor.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSpatialAnchorMSFT(call_info, return_value, session, &createInfo, &anchor);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSpatialAnchorSpaceMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpatialAnchorSpaceCreateInfoMSFT> createInfo;
    HandlePointerDecoder<XrSpace> space;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += space.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSpatialAnchorSpaceMSFT(call_info, return_value, session, &createInfo, &space);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroySpatialAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId anchor;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &anchor);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroySpatialAnchorMSFT(call_info, return_value, anchor);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetInputDeviceActiveEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPath interactionProfile;
    XrPath topLevelPath;
    XrBool32 isActive;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &interactionProfile);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &topLevelPath);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &isActive);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetInputDeviceActiveEXT(call_info, return_value, session, interactionProfile, topLevelPath, isActive);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetInputDeviceStateBoolEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPath topLevelPath;
    XrPath inputSourcePath;
    XrBool32 state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &topLevelPath);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &inputSourcePath);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &state);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetInputDeviceStateBoolEXT(call_info, return_value, session, topLevelPath, inputSourcePath, state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetInputDeviceStateFloatEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPath topLevelPath;
    XrPath inputSourcePath;
    float state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &topLevelPath);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &inputSourcePath);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &state);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetInputDeviceStateFloatEXT(call_info, return_value, session, topLevelPath, inputSourcePath, state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetInputDeviceStateVector2fEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPath topLevelPath;
    XrPath inputSourcePath;
    Decoded_XrVector2f state;
    XrVector2f value_state;
    state.decoded_value = &value_state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &topLevelPath);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &inputSourcePath);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &state);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetInputDeviceStateVector2fEXT(call_info, return_value, session, topLevelPath, inputSourcePath, state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetInputDeviceLocationEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPath topLevelPath;
    XrPath inputSourcePath;
    format::HandleId space;
    Decoded_XrPosef pose;
    XrPosef value_pose;
    pose.decoded_value = &value_pose;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &topLevelPath);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &inputSourcePath);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pose);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetInputDeviceLocationEXT(call_info, return_value, session, topLevelPath, inputSourcePath, space, pose);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSpatialGraphNodeSpaceMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT> createInfo;
    HandlePointerDecoder<XrSpace> space;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += space.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSpatialGraphNodeSpaceMSFT(call_info, return_value, session, &createInfo, &space);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrTryCreateSpatialGraphStaticNodeBindingMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT> createInfo;
    HandlePointerDecoder<XrSpatialGraphNodeBindingMSFT> nodeBinding;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += nodeBinding.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrTryCreateSpatialGraphStaticNodeBindingMSFT(call_info, return_value, session, &createInfo, &nodeBinding);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroySpatialGraphNodeBindingMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId nodeBinding;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &nodeBinding);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroySpatialGraphNodeBindingMSFT(call_info, return_value, nodeBinding);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpatialGraphNodeBindingPropertiesMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId nodeBinding;
    StructPointerDecoder<Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT> getInfo;
    StructPointerDecoder<Decoded_XrSpatialGraphNodeBindingPropertiesMSFT> properties;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &nodeBinding);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += properties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpatialGraphNodeBindingPropertiesMSFT(call_info, return_value, nodeBinding, &getInfo, &properties);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateHandTrackerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrHandTrackerCreateInfoEXT> createInfo;
    HandlePointerDecoder<XrHandTrackerEXT> handTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += handTracker.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateHandTrackerEXT(call_info, return_value, session, &createInfo, &handTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyHandTrackerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId handTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handTracker);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyHandTrackerEXT(call_info, return_value, handTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrLocateHandJointsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId handTracker;
    StructPointerDecoder<Decoded_XrHandJointsLocateInfoEXT> locateInfo;
    StructPointerDecoder<Decoded_XrHandJointLocationsEXT> locations;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handTracker);
    bytes_read += locateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += locations.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrLocateHandJointsEXT(call_info, return_value, handTracker, &locateInfo, &locations);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateHandMeshSpaceMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId handTracker;
    StructPointerDecoder<Decoded_XrHandMeshSpaceCreateInfoMSFT> createInfo;
    HandlePointerDecoder<XrSpace> space;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handTracker);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += space.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateHandMeshSpaceMSFT(call_info, return_value, handTracker, &createInfo, &space);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrUpdateHandMeshMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId handTracker;
    StructPointerDecoder<Decoded_XrHandMeshUpdateInfoMSFT> updateInfo;
    StructPointerDecoder<Decoded_XrHandMeshMSFT> handMesh;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handTracker);
    bytes_read += updateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += handMesh.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrUpdateHandMeshMSFT(call_info, return_value, handTracker, &updateInfo, &handMesh);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetControllerModelKeyMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPath topLevelUserPath;
    StructPointerDecoder<Decoded_XrControllerModelKeyStateMSFT> controllerModelKeyState;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &topLevelUserPath);
    bytes_read += controllerModelKeyState.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetControllerModelKeyMSFT(call_info, return_value, session, topLevelUserPath, &controllerModelKeyState);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrLoadControllerModelMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrControllerModelKeyMSFT modelKey;
    uint32_t bufferCapacityInput;
    PointerDecoder<uint32_t> bufferCountOutput;
    PointerDecoder<uint8_t> buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &modelKey);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferCapacityInput);
    bytes_read += bufferCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += buffer.DecodeUInt8((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrLoadControllerModelMSFT(call_info, return_value, session, modelKey, bufferCapacityInput, &bufferCountOutput, &buffer);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetControllerModelPropertiesMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrControllerModelKeyMSFT modelKey;
    StructPointerDecoder<Decoded_XrControllerModelPropertiesMSFT> properties;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &modelKey);
    bytes_read += properties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetControllerModelPropertiesMSFT(call_info, return_value, session, modelKey, &properties);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetControllerModelStateMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrControllerModelKeyMSFT modelKey;
    StructPointerDecoder<Decoded_XrControllerModelStateMSFT> state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &modelKey);
    bytes_read += state.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetControllerModelStateMSFT(call_info, return_value, session, modelKey, &state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    uint64_t perceptionAnchor;
    HandlePointerDecoder<XrSpatialAnchorMSFT> anchor;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &perceptionAnchor);
    bytes_read += anchor.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(call_info, return_value, session, perceptionAnchor, &anchor);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    format::HandleId anchor;
    PointerDecoder<uint64_t, void*> perceptionAnchor;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &anchor);
    bytes_read += perceptionAnchor.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(call_info, return_value, session, anchor, &perceptionAnchor);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateReprojectionModesMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    XrViewConfigurationType viewConfigurationType;
    uint32_t modeCapacityInput;
    PointerDecoder<uint32_t> modeCountOutput;
    PointerDecoder<XrReprojectionModeMSFT> modes;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewConfigurationType);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &modeCapacityInput);
    bytes_read += modeCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += modes.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateReprojectionModesMSFT(call_info, return_value, instance, systemId, viewConfigurationType, modeCapacityInput, &modeCountOutput, &modes);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrUpdateSwapchainFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId swapchain;
    StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state;
    StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB> swapchain_state_base_header_fb;
    StructPointerDecoder<Decoded_XrSwapchainStateFoveationFB> swapchain_state_foveation_fb;
    StructPointerDecoder<Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB> swapchain_state_android_surface_dimensions_fb;
    StructPointerDecoder<Decoded_XrSwapchainStateSamplerOpenGLESFB> swapchain_state_sampler_open_glesfb;
    StructPointerDecoder<Decoded_XrSwapchainStateSamplerVulkanFB> swapchain_state_sampler_vulkan_fb;
    XrResult return_value;

    bool     peak_is_null    = false;
    bool     peak_is_struct  = false;
    bool     peak_has_length = false;
    size_t   peak_length{};
    uint32_t peak_structure_type = 0;
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    if (PointerDecoderBase::PeekAttributesAndType((parameter_buffer + bytes_read),
                                                   (buffer_size - bytes_read),
                                                   peak_is_null,
                                                   peak_is_struct,
                                                   peak_has_length,
                                                   peak_length,
                                                   peak_structure_type))
     {
         XrStructureType xr_type = static_cast<XrStructureType>(peak_structure_type);
         switch (xr_type)
         {
             case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
                 bytes_read += swapchain_state_foveation_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 state = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>*>(&swapchain_state_foveation_fb);
                 break;
             case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
                 bytes_read += swapchain_state_android_surface_dimensions_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 state = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>*>(&swapchain_state_android_surface_dimensions_fb);
                 break;
             case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
                 bytes_read += swapchain_state_sampler_open_glesfb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 state = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>*>(&swapchain_state_sampler_open_glesfb);
                 break;
             case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
                 bytes_read += swapchain_state_sampler_vulkan_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 state = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>*>(&swapchain_state_sampler_vulkan_fb);
                 break;
             default:
                 bytes_read += swapchain_state_base_header_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 state = &swapchain_state_base_header_fb;
                 break;
         }
     }
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrUpdateSwapchainFB(call_info, return_value, swapchain, state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSwapchainStateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId swapchain;
    StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state;
    StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB> swapchain_state_base_header_fb;
    StructPointerDecoder<Decoded_XrSwapchainStateFoveationFB> swapchain_state_foveation_fb;
    StructPointerDecoder<Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB> swapchain_state_android_surface_dimensions_fb;
    StructPointerDecoder<Decoded_XrSwapchainStateSamplerOpenGLESFB> swapchain_state_sampler_open_glesfb;
    StructPointerDecoder<Decoded_XrSwapchainStateSamplerVulkanFB> swapchain_state_sampler_vulkan_fb;
    XrResult return_value;

    bool     peak_is_null    = false;
    bool     peak_is_struct  = false;
    bool     peak_has_length = false;
    size_t   peak_length{};
    uint32_t peak_structure_type = 0;
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    if (PointerDecoderBase::PeekAttributesAndType((parameter_buffer + bytes_read),
                                                   (buffer_size - bytes_read),
                                                   peak_is_null,
                                                   peak_is_struct,
                                                   peak_has_length,
                                                   peak_length,
                                                   peak_structure_type))
     {
         XrStructureType xr_type = static_cast<XrStructureType>(peak_structure_type);
         switch (xr_type)
         {
             case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
                 bytes_read += swapchain_state_foveation_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 state = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>*>(&swapchain_state_foveation_fb);
                 break;
             case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
                 bytes_read += swapchain_state_android_surface_dimensions_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 state = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>*>(&swapchain_state_android_surface_dimensions_fb);
                 break;
             case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
                 bytes_read += swapchain_state_sampler_open_glesfb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 state = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>*>(&swapchain_state_sampler_open_glesfb);
                 break;
             case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
                 bytes_read += swapchain_state_sampler_vulkan_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 state = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>*>(&swapchain_state_sampler_vulkan_fb);
                 break;
             default:
                 bytes_read += swapchain_state_base_header_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 state = &swapchain_state_base_header_fb;
                 break;
         }
     }
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSwapchainStateFB(call_info, return_value, swapchain, state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateBodyTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrBodyTrackerCreateInfoFB> createInfo;
    HandlePointerDecoder<XrBodyTrackerFB> bodyTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += bodyTracker.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateBodyTrackerFB(call_info, return_value, session, &createInfo, &bodyTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyBodyTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId bodyTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bodyTracker);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyBodyTrackerFB(call_info, return_value, bodyTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrLocateBodyJointsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId bodyTracker;
    StructPointerDecoder<Decoded_XrBodyJointsLocateInfoFB> locateInfo;
    StructPointerDecoder<Decoded_XrBodyJointLocationsFB> locations;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bodyTracker);
    bytes_read += locateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += locations.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrLocateBodyJointsFB(call_info, return_value, bodyTracker, &locateInfo, &locations);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetBodySkeletonFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId bodyTracker;
    StructPointerDecoder<Decoded_XrBodySkeletonFB> skeleton;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bodyTracker);
    bytes_read += skeleton.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetBodySkeletonFB(call_info, return_value, bodyTracker, &skeleton);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateSceneComputeFeaturesMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrSystemId systemId;
    uint32_t featureCapacityInput;
    PointerDecoder<uint32_t> featureCountOutput;
    PointerDecoder<XrSceneComputeFeatureMSFT> features;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &systemId);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &featureCapacityInput);
    bytes_read += featureCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += features.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateSceneComputeFeaturesMSFT(call_info, return_value, instance, systemId, featureCapacityInput, &featureCountOutput, &features);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSceneObserverMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSceneObserverCreateInfoMSFT> createInfo;
    HandlePointerDecoder<XrSceneObserverMSFT> sceneObserver;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += sceneObserver.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSceneObserverMSFT(call_info, return_value, session, &createInfo, &sceneObserver);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroySceneObserverMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId sceneObserver;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sceneObserver);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroySceneObserverMSFT(call_info, return_value, sceneObserver);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSceneMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId sceneObserver;
    StructPointerDecoder<Decoded_XrSceneCreateInfoMSFT> createInfo;
    HandlePointerDecoder<XrSceneMSFT> scene;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sceneObserver);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += scene.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSceneMSFT(call_info, return_value, sceneObserver, &createInfo, &scene);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroySceneMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId scene;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scene);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroySceneMSFT(call_info, return_value, scene);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrComputeNewSceneMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId sceneObserver;
    StructPointerDecoder<Decoded_XrNewSceneComputeInfoMSFT> computeInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sceneObserver);
    bytes_read += computeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrComputeNewSceneMSFT(call_info, return_value, sceneObserver, &computeInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSceneComputeStateMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId sceneObserver;
    PointerDecoder<XrSceneComputeStateMSFT> state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sceneObserver);
    bytes_read += state.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSceneComputeStateMSFT(call_info, return_value, sceneObserver, &state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSceneComponentsMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId scene;
    StructPointerDecoder<Decoded_XrSceneComponentsGetInfoMSFT> getInfo;
    StructPointerDecoder<Decoded_XrSceneComponentsMSFT> components;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scene);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += components.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSceneComponentsMSFT(call_info, return_value, scene, &getInfo, &components);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrLocateSceneComponentsMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId scene;
    StructPointerDecoder<Decoded_XrSceneComponentsLocateInfoMSFT> locateInfo;
    StructPointerDecoder<Decoded_XrSceneComponentLocationsMSFT> locations;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scene);
    bytes_read += locateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += locations.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrLocateSceneComponentsMSFT(call_info, return_value, scene, &locateInfo, &locations);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSceneMeshBuffersMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId scene;
    StructPointerDecoder<Decoded_XrSceneMeshBuffersGetInfoMSFT> getInfo;
    StructPointerDecoder<Decoded_XrSceneMeshBuffersMSFT> buffers;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scene);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += buffers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSceneMeshBuffersMSFT(call_info, return_value, scene, &getInfo, &buffers);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDeserializeSceneMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId sceneObserver;
    StructPointerDecoder<Decoded_XrSceneDeserializeInfoMSFT> deserializeInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sceneObserver);
    bytes_read += deserializeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDeserializeSceneMSFT(call_info, return_value, sceneObserver, &deserializeInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSerializedSceneFragmentDataMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId scene;
    StructPointerDecoder<Decoded_XrSerializedSceneFragmentDataGetInfoMSFT> getInfo;
    uint32_t countInput;
    PointerDecoder<uint32_t> readOutput;
    PointerDecoder<uint8_t> buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scene);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countInput);
    bytes_read += readOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += buffer.DecodeUInt8((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSerializedSceneFragmentDataMSFT(call_info, return_value, scene, &getInfo, countInput, &readOutput, &buffer);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateDisplayRefreshRatesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    uint32_t displayRefreshRateCapacityInput;
    PointerDecoder<uint32_t> displayRefreshRateCountOutput;
    PointerDecoder<float> displayRefreshRates;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &displayRefreshRateCapacityInput);
    bytes_read += displayRefreshRateCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += displayRefreshRates.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateDisplayRefreshRatesFB(call_info, return_value, session, displayRefreshRateCapacityInput, &displayRefreshRateCountOutput, &displayRefreshRates);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetDisplayRefreshRateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    PointerDecoder<float> displayRefreshRate;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += displayRefreshRate.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetDisplayRefreshRateFB(call_info, return_value, session, &displayRefreshRate);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrRequestDisplayRefreshRateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    float displayRefreshRate;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &displayRefreshRate);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrRequestDisplayRefreshRateFB(call_info, return_value, session, displayRefreshRate);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateViveTrackerPathsHTCX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    uint32_t pathCapacityInput;
    PointerDecoder<uint32_t> pathCountOutput;
    StructPointerDecoder<Decoded_XrViveTrackerPathsHTCX> paths;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pathCapacityInput);
    bytes_read += pathCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += paths.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateViveTrackerPathsHTCX(call_info, return_value, instance, pathCapacityInput, &pathCountOutput, &paths);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateFacialTrackerHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrFacialTrackerCreateInfoHTC> createInfo;
    HandlePointerDecoder<XrFacialTrackerHTC> facialTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += facialTracker.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateFacialTrackerHTC(call_info, return_value, session, &createInfo, &facialTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyFacialTrackerHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId facialTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &facialTracker);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyFacialTrackerHTC(call_info, return_value, facialTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetFacialExpressionsHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId facialTracker;
    StructPointerDecoder<Decoded_XrFacialExpressionsHTC> facialExpressions;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &facialTracker);
    bytes_read += facialExpressions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetFacialExpressionsHTC(call_info, return_value, facialTracker, &facialExpressions);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateColorSpacesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    uint32_t colorSpaceCapacityInput;
    PointerDecoder<uint32_t> colorSpaceCountOutput;
    PointerDecoder<XrColorSpaceFB> colorSpaces;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &colorSpaceCapacityInput);
    bytes_read += colorSpaceCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += colorSpaces.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateColorSpacesFB(call_info, return_value, session, colorSpaceCapacityInput, &colorSpaceCountOutput, &colorSpaces);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetColorSpaceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrColorSpaceFB colorSpace;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &colorSpace);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetColorSpaceFB(call_info, return_value, session, colorSpace);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetHandMeshFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId handTracker;
    StructPointerDecoder<Decoded_XrHandTrackingMeshFB> mesh;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handTracker);
    bytes_read += mesh.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetHandMeshFB(call_info, return_value, handTracker, &mesh);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSpatialAnchorFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoFB> info;
    HandlePointerDecoder<XrAsyncRequestIdFB> requestId;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += requestId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSpatialAnchorFB(call_info, return_value, session, &info, &requestId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpaceUuidFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId space;
    StructPointerDecoder<Decoded_XrUuidEXT> uuid;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += uuid.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpaceUuidFB(call_info, return_value, space, &uuid);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateSpaceSupportedComponentsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId space;
    uint32_t componentTypeCapacityInput;
    PointerDecoder<uint32_t> componentTypeCountOutput;
    PointerDecoder<XrSpaceComponentTypeFB> componentTypes;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &componentTypeCapacityInput);
    bytes_read += componentTypeCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += componentTypes.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateSpaceSupportedComponentsFB(call_info, return_value, space, componentTypeCapacityInput, &componentTypeCountOutput, &componentTypes);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetSpaceComponentStatusFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId space;
    StructPointerDecoder<Decoded_XrSpaceComponentStatusSetInfoFB> info;
    HandlePointerDecoder<XrAsyncRequestIdFB> requestId;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += requestId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetSpaceComponentStatusFB(call_info, return_value, space, &info, &requestId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpaceComponentStatusFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId space;
    XrSpaceComponentTypeFB componentType;
    StructPointerDecoder<Decoded_XrSpaceComponentStatusFB> status;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &componentType);
    bytes_read += status.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpaceComponentStatusFB(call_info, return_value, space, componentType, &status);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateFoveationProfileFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrFoveationProfileCreateInfoFB> createInfo;
    HandlePointerDecoder<XrFoveationProfileFB> profile;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += profile.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateFoveationProfileFB(call_info, return_value, session, &createInfo, &profile);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyFoveationProfileFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId profile;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &profile);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyFoveationProfileFB(call_info, return_value, profile);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrQuerySystemTrackedKeyboardFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrKeyboardTrackingQueryFB> queryInfo;
    StructPointerDecoder<Decoded_XrKeyboardTrackingDescriptionFB> keyboard;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += queryInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += keyboard.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrQuerySystemTrackedKeyboardFB(call_info, return_value, session, &queryInfo, &keyboard);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateKeyboardSpaceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrKeyboardSpaceCreateInfoFB> createInfo;
    HandlePointerDecoder<XrSpace> keyboardSpace;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += keyboardSpace.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateKeyboardSpaceFB(call_info, return_value, session, &createInfo, &keyboardSpace);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrTriangleMeshBeginUpdateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId mesh;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &mesh);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrTriangleMeshBeginUpdateFB(call_info, return_value, mesh);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrTriangleMeshEndUpdateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId mesh;
    uint32_t vertexCount;
    uint32_t triangleCount;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &mesh);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &triangleCount);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrTriangleMeshEndUpdateFB(call_info, return_value, mesh, vertexCount, triangleCount);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrTriangleMeshBeginVertexBufferUpdateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId mesh;
    PointerDecoder<uint32_t> outVertexCount;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &mesh);
    bytes_read += outVertexCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrTriangleMeshBeginVertexBufferUpdateFB(call_info, return_value, mesh, &outVertexCount);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrTriangleMeshEndVertexBufferUpdateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId mesh;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &mesh);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrTriangleMeshEndVertexBufferUpdateFB(call_info, return_value, mesh);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreatePassthroughFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrPassthroughCreateInfoFB> createInfo;
    HandlePointerDecoder<XrPassthroughFB> outPassthrough;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += outPassthrough.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreatePassthroughFB(call_info, return_value, session, &createInfo, &outPassthrough);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyPassthroughFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId passthrough;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &passthrough);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyPassthroughFB(call_info, return_value, passthrough);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrPassthroughStartFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId passthrough;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &passthrough);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrPassthroughStartFB(call_info, return_value, passthrough);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrPassthroughPauseFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId passthrough;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &passthrough);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrPassthroughPauseFB(call_info, return_value, passthrough);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreatePassthroughLayerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrPassthroughLayerCreateInfoFB> createInfo;
    HandlePointerDecoder<XrPassthroughLayerFB> outLayer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += outLayer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreatePassthroughLayerFB(call_info, return_value, session, &createInfo, &outLayer);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyPassthroughLayerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId layer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyPassthroughLayerFB(call_info, return_value, layer);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrPassthroughLayerPauseFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId layer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrPassthroughLayerPauseFB(call_info, return_value, layer);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrPassthroughLayerResumeFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId layer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrPassthroughLayerResumeFB(call_info, return_value, layer);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrPassthroughLayerSetStyleFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId layer;
    StructPointerDecoder<Decoded_XrPassthroughStyleFB> style;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layer);
    bytes_read += style.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrPassthroughLayerSetStyleFB(call_info, return_value, layer, &style);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateGeometryInstanceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrGeometryInstanceCreateInfoFB> createInfo;
    HandlePointerDecoder<XrGeometryInstanceFB> outGeometryInstance;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += outGeometryInstance.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateGeometryInstanceFB(call_info, return_value, session, &createInfo, &outGeometryInstance);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyGeometryInstanceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyGeometryInstanceFB(call_info, return_value, instance);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGeometryInstanceSetTransformFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrGeometryInstanceTransformFB> transformation;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += transformation.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGeometryInstanceSetTransformFB(call_info, return_value, instance, &transformation);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateRenderModelPathsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    uint32_t pathCapacityInput;
    PointerDecoder<uint32_t> pathCountOutput;
    StructPointerDecoder<Decoded_XrRenderModelPathInfoFB> paths;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pathCapacityInput);
    bytes_read += pathCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += paths.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateRenderModelPathsFB(call_info, return_value, session, pathCapacityInput, &pathCountOutput, &paths);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetRenderModelPropertiesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPath path;
    StructPointerDecoder<Decoded_XrRenderModelPropertiesFB> properties;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &path);
    bytes_read += properties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetRenderModelPropertiesFB(call_info, return_value, session, path, &properties);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrLoadRenderModelFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrRenderModelLoadInfoFB> info;
    StructPointerDecoder<Decoded_XrRenderModelBufferFB> buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrLoadRenderModelFB(call_info, return_value, session, &info, &buffer);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetEnvironmentDepthEstimationVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrBool32 enabled;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &enabled);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetEnvironmentDepthEstimationVARJO(call_info, return_value, session, enabled);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetMarkerTrackingVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrBool32 enabled;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &enabled);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetMarkerTrackingVARJO(call_info, return_value, session, enabled);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetMarkerTrackingTimeoutVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    uint64_t markerId;
    XrDuration timeout;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerId);
    bytes_read += ValueDecoder::DecodeInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetMarkerTrackingTimeoutVARJO(call_info, return_value, session, markerId, timeout);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetMarkerTrackingPredictionVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    uint64_t markerId;
    XrBool32 enable;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerId);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &enable);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetMarkerTrackingPredictionVARJO(call_info, return_value, session, markerId, enable);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetMarkerSizeVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    uint64_t markerId;
    StructPointerDecoder<Decoded_XrExtent2Df> size;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerId);
    bytes_read += size.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetMarkerSizeVARJO(call_info, return_value, session, markerId, &size);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateMarkerSpaceVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoVARJO> createInfo;
    HandlePointerDecoder<XrSpace> space;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += space.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateMarkerSpaceVARJO(call_info, return_value, session, &createInfo, &space);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetViewOffsetVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    float offset;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetViewOffsetVARJO(call_info, return_value, session, offset);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSpaceFromCoordinateFrameUIDML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrCoordinateSpaceCreateInfoML> createInfo;
    HandlePointerDecoder<XrSpace> space;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += space.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSpaceFromCoordinateFrameUIDML(call_info, return_value, session, &createInfo, &space);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateMarkerDetectorML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrMarkerDetectorCreateInfoML> createInfo;
    HandlePointerDecoder<XrMarkerDetectorML> markerDetector;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += markerDetector.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateMarkerDetectorML(call_info, return_value, session, &createInfo, &markerDetector);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyMarkerDetectorML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId markerDetector;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerDetector);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyMarkerDetectorML(call_info, return_value, markerDetector);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSnapshotMarkerDetectorML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId markerDetector;
    StructPointerDecoder<Decoded_XrMarkerDetectorSnapshotInfoML> snapshotInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerDetector);
    bytes_read += snapshotInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSnapshotMarkerDetectorML(call_info, return_value, markerDetector, &snapshotInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetMarkerDetectorStateML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId markerDetector;
    StructPointerDecoder<Decoded_XrMarkerDetectorStateML> state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerDetector);
    bytes_read += state.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetMarkerDetectorStateML(call_info, return_value, markerDetector, &state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetMarkersML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId markerDetector;
    uint32_t markerCapacityInput;
    PointerDecoder<uint32_t> markerCountOutput;
    HandlePointerDecoder<XrMarkerML> markers;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerDetector);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerCapacityInput);
    bytes_read += markerCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += markers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetMarkersML(call_info, return_value, markerDetector, markerCapacityInput, &markerCountOutput, &markers);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetMarkerReprojectionErrorML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId markerDetector;
    XrMarkerML marker;
    PointerDecoder<float> reprojectionErrorMeters;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerDetector);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &marker);
    bytes_read += reprojectionErrorMeters.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetMarkerReprojectionErrorML(call_info, return_value, markerDetector, marker, &reprojectionErrorMeters);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetMarkerLengthML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId markerDetector;
    XrMarkerML marker;
    PointerDecoder<float> meters;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerDetector);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &marker);
    bytes_read += meters.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetMarkerLengthML(call_info, return_value, markerDetector, marker, &meters);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetMarkerNumberML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId markerDetector;
    XrMarkerML marker;
    PointerDecoder<uint64_t> number;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerDetector);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &marker);
    bytes_read += number.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetMarkerNumberML(call_info, return_value, markerDetector, marker, &number);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetMarkerStringML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId markerDetector;
    XrMarkerML marker;
    uint32_t bufferCapacityInput;
    PointerDecoder<uint32_t> bufferCountOutput;
    StringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &markerDetector);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &marker);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferCapacityInput);
    bytes_read += bufferCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    char* buffer_store = nullptr;
    if (bufferCapacityInput > 0)
    {
        buffer_store = new char[bufferCapacityInput];
        buffer.SetExternalMemory(buffer_store, bufferCapacityInput);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetMarkerStringML(call_info, return_value, markerDetector, marker, bufferCapacityInput, &bufferCountOutput, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateMarkerSpaceML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoML> createInfo;
    HandlePointerDecoder<XrSpace> space;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += space.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateMarkerSpaceML(call_info, return_value, session, &createInfo, &space);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnableLocalizationEventsML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrLocalizationEnableEventsInfoML> info;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnableLocalizationEventsML(call_info, return_value, session, &info);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrQueryLocalizationMapsML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrLocalizationMapQueryInfoBaseHeaderML> queryInfo;
    uint32_t mapCapacityInput;
    PointerDecoder<uint32_t> mapCountOutput;
    StructPointerDecoder<Decoded_XrLocalizationMapML> maps;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += queryInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &mapCapacityInput);
    bytes_read += mapCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += maps.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrQueryLocalizationMapsML(call_info, return_value, session, &queryInfo, mapCapacityInput, &mapCountOutput, &maps);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrRequestMapLocalizationML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrMapLocalizationRequestInfoML> requestInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += requestInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrRequestMapLocalizationML(call_info, return_value, session, &requestInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrImportLocalizationMapML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrLocalizationMapImportInfoML> importInfo;
    StructPointerDecoder<Decoded_XrUuidEXT> mapUuid;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += importInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += mapUuid.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrImportLocalizationMapML(call_info, return_value, session, &importInfo, &mapUuid);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateExportedLocalizationMapML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrUuidEXT> mapUuid;
    HandlePointerDecoder<XrExportedLocalizationMapML> map;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += mapUuid.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += map.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateExportedLocalizationMapML(call_info, return_value, session, &mapUuid, &map);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyExportedLocalizationMapML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId map;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &map);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyExportedLocalizationMapML(call_info, return_value, map);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetExportedLocalizationMapDataML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId map;
    uint32_t bufferCapacityInput;
    PointerDecoder<uint32_t> bufferCountOutput;
    StringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &map);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferCapacityInput);
    bytes_read += bufferCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    char* buffer_store = nullptr;
    if (bufferCapacityInput > 0)
    {
        buffer_store = new char[bufferCapacityInput];
        buffer.SetExternalMemory(buffer_store, bufferCapacityInput);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetExportedLocalizationMapDataML(call_info, return_value, map, bufferCapacityInput, &bufferCountOutput, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSpatialAnchorStoreConnectionMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    HandlePointerDecoder<XrSpatialAnchorStoreConnectionMSFT> spatialAnchorStore;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += spatialAnchorStore.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSpatialAnchorStoreConnectionMSFT(call_info, return_value, session, &spatialAnchorStore);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroySpatialAnchorStoreConnectionMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId spatialAnchorStore;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &spatialAnchorStore);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroySpatialAnchorStoreConnectionMSFT(call_info, return_value, spatialAnchorStore);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrPersistSpatialAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId spatialAnchorStore;
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceInfoMSFT> spatialAnchorPersistenceInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &spatialAnchorStore);
    bytes_read += spatialAnchorPersistenceInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrPersistSpatialAnchorMSFT(call_info, return_value, spatialAnchorStore, &spatialAnchorPersistenceInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumeratePersistedSpatialAnchorNamesMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId spatialAnchorStore;
    uint32_t spatialAnchorNameCapacityInput;
    PointerDecoder<uint32_t> spatialAnchorNameCountOutput;
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT> spatialAnchorNames;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &spatialAnchorStore);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &spatialAnchorNameCapacityInput);
    bytes_read += spatialAnchorNameCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += spatialAnchorNames.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumeratePersistedSpatialAnchorNamesMSFT(call_info, return_value, spatialAnchorStore, spatialAnchorNameCapacityInput, &spatialAnchorNameCountOutput, &spatialAnchorNames);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSpatialAnchorFromPersistedNameMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT> spatialAnchorCreateInfo;
    HandlePointerDecoder<XrSpatialAnchorMSFT> spatialAnchor;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += spatialAnchorCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += spatialAnchor.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSpatialAnchorFromPersistedNameMSFT(call_info, return_value, session, &spatialAnchorCreateInfo, &spatialAnchor);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrUnpersistSpatialAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId spatialAnchorStore;
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT> spatialAnchorPersistenceName;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &spatialAnchorStore);
    bytes_read += spatialAnchorPersistenceName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrUnpersistSpatialAnchorMSFT(call_info, return_value, spatialAnchorStore, &spatialAnchorPersistenceName);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrClearSpatialAnchorStoreMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId spatialAnchorStore;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &spatialAnchorStore);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrClearSpatialAnchorStoreMSFT(call_info, return_value, spatialAnchorStore);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSceneMarkerRawDataMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId scene;
    StructPointerDecoder<Decoded_XrUuidMSFT> markerId;
    uint32_t bufferCapacityInput;
    PointerDecoder<uint32_t> bufferCountOutput;
    PointerDecoder<uint8_t> buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scene);
    bytes_read += markerId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferCapacityInput);
    bytes_read += bufferCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += buffer.DecodeUInt8((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSceneMarkerRawDataMSFT(call_info, return_value, scene, &markerId, bufferCapacityInput, &bufferCountOutput, &buffer);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSceneMarkerDecodedStringMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId scene;
    StructPointerDecoder<Decoded_XrUuidMSFT> markerId;
    uint32_t bufferCapacityInput;
    PointerDecoder<uint32_t> bufferCountOutput;
    StringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scene);
    bytes_read += markerId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferCapacityInput);
    bytes_read += bufferCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    char* buffer_store = nullptr;
    if (bufferCapacityInput > 0)
    {
        buffer_store = new char[bufferCapacityInput];
        buffer.SetExternalMemory(buffer_store, bufferCapacityInput);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSceneMarkerDecodedStringMSFT(call_info, return_value, scene, &markerId, bufferCapacityInput, &bufferCountOutput, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrQuerySpacesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpaceQueryInfoBaseHeaderFB>* info;
    StructPointerDecoder<Decoded_XrSpaceQueryInfoBaseHeaderFB> space_query_info_base_header_fb;
    StructPointerDecoder<Decoded_XrSpaceQueryInfoFB> space_query_info_fb;
    HandlePointerDecoder<XrAsyncRequestIdFB> requestId;
    XrResult return_value;

    bool     peak_is_null    = false;
    bool     peak_is_struct  = false;
    bool     peak_has_length = false;
    size_t   peak_length{};
    uint32_t peak_structure_type = 0;
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    if (PointerDecoderBase::PeekAttributesAndType((parameter_buffer + bytes_read),
                                                   (buffer_size - bytes_read),
                                                   peak_is_null,
                                                   peak_is_struct,
                                                   peak_has_length,
                                                   peak_length,
                                                   peak_structure_type))
     {
         XrStructureType xr_type = static_cast<XrStructureType>(peak_structure_type);
         switch (xr_type)
         {
             case XR_TYPE_SPACE_QUERY_INFO_FB:
                 bytes_read += space_query_info_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 info = reinterpret_cast<StructPointerDecoder<Decoded_XrSpaceQueryInfoBaseHeaderFB>*>(&space_query_info_fb);
                 break;
             default:
                 bytes_read += space_query_info_base_header_fb.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                 info = &space_query_info_base_header_fb;
                 break;
         }
     }
    bytes_read += requestId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrQuerySpacesFB(call_info, return_value, session, info, &requestId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrRetrieveSpaceQueryResultsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrAsyncRequestIdFB requestId;
    StructPointerDecoder<Decoded_XrSpaceQueryResultsFB> results;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &requestId);
    bytes_read += results.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrRetrieveSpaceQueryResultsFB(call_info, return_value, session, requestId, &results);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSaveSpaceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpaceSaveInfoFB> info;
    HandlePointerDecoder<XrAsyncRequestIdFB> requestId;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += requestId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSaveSpaceFB(call_info, return_value, session, &info, &requestId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEraseSpaceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpaceEraseInfoFB> info;
    HandlePointerDecoder<XrAsyncRequestIdFB> requestId;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += requestId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEraseSpaceFB(call_info, return_value, session, &info, &requestId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetAudioOutputDeviceGuidOculus(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    WStringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    wchar_t* buffer_store = nullptr;
    if (XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS > 0)
    {
        buffer_store = new wchar_t[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS];
        buffer.SetExternalMemory(buffer_store, XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetAudioOutputDeviceGuidOculus(call_info, return_value, instance, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetAudioInputDeviceGuidOculus(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    WStringDecoder buffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    wchar_t* buffer_store = nullptr;
    if (XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS > 0)
    {
        buffer_store = new wchar_t[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS];
        buffer.SetExternalMemory(buffer_store, XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS);
    }
    bytes_read += buffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetAudioInputDeviceGuidOculus(call_info, return_value, instance, &buffer);
    }
    if (buffer_store != nullptr)
    {
        delete[] buffer_store;
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrShareSpacesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpaceShareInfoFB> info;
    HandlePointerDecoder<XrAsyncRequestIdFB> requestId;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += requestId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrShareSpacesFB(call_info, return_value, session, &info, &requestId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpaceBoundingBox2DFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    format::HandleId space;
    StructPointerDecoder<Decoded_XrRect2Df> boundingBox2DOutput;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += boundingBox2DOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpaceBoundingBox2DFB(call_info, return_value, session, space, &boundingBox2DOutput);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpaceBoundingBox3DFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    format::HandleId space;
    StructPointerDecoder<Decoded_XrRect3DfFB> boundingBox3DOutput;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += boundingBox3DOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpaceBoundingBox3DFB(call_info, return_value, session, space, &boundingBox3DOutput);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpaceSemanticLabelsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    format::HandleId space;
    StructPointerDecoder<Decoded_XrSemanticLabelsFB> semanticLabelsOutput;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += semanticLabelsOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpaceSemanticLabelsFB(call_info, return_value, session, space, &semanticLabelsOutput);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpaceBoundary2DFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    format::HandleId space;
    StructPointerDecoder<Decoded_XrBoundary2DFB> boundary2DOutput;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += boundary2DOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpaceBoundary2DFB(call_info, return_value, session, space, &boundary2DOutput);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpaceRoomLayoutFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    format::HandleId space;
    StructPointerDecoder<Decoded_XrRoomLayoutFB> roomLayoutOutput;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += roomLayoutOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpaceRoomLayoutFB(call_info, return_value, session, space, &roomLayoutOutput);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetDigitalLensControlALMALENCE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrDigitalLensControlALMALENCE> digitalLensControl;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += digitalLensControl.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetDigitalLensControlALMALENCE(call_info, return_value, session, &digitalLensControl);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrRequestSceneCaptureFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSceneCaptureRequestInfoFB> info;
    HandlePointerDecoder<XrAsyncRequestIdFB> requestId;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += requestId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrRequestSceneCaptureFB(call_info, return_value, session, &info, &requestId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpaceContainerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    format::HandleId space;
    StructPointerDecoder<Decoded_XrSpaceContainerFB> spaceContainerOutput;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += spaceContainerOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpaceContainerFB(call_info, return_value, session, space, &spaceContainerOutput);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetFoveationEyeTrackedStateMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrFoveationEyeTrackedStateMETA> foveationState;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += foveationState.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetFoveationEyeTrackedStateMETA(call_info, return_value, session, &foveationState);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateFaceTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrFaceTrackerCreateInfoFB> createInfo;
    HandlePointerDecoder<XrFaceTrackerFB> faceTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += faceTracker.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateFaceTrackerFB(call_info, return_value, session, &createInfo, &faceTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyFaceTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId faceTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceTracker);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyFaceTrackerFB(call_info, return_value, faceTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetFaceExpressionWeightsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId faceTracker;
    StructPointerDecoder<Decoded_XrFaceExpressionInfoFB> expressionInfo;
    StructPointerDecoder<Decoded_XrFaceExpressionWeightsFB> expressionWeights;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceTracker);
    bytes_read += expressionInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += expressionWeights.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetFaceExpressionWeightsFB(call_info, return_value, faceTracker, &expressionInfo, &expressionWeights);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateEyeTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrEyeTrackerCreateInfoFB> createInfo;
    HandlePointerDecoder<XrEyeTrackerFB> eyeTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += eyeTracker.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateEyeTrackerFB(call_info, return_value, session, &createInfo, &eyeTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyEyeTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId eyeTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &eyeTracker);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyEyeTrackerFB(call_info, return_value, eyeTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetEyeGazesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId eyeTracker;
    StructPointerDecoder<Decoded_XrEyeGazesInfoFB> gazeInfo;
    StructPointerDecoder<Decoded_XrEyeGazesFB> eyeGazes;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &eyeTracker);
    bytes_read += gazeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += eyeGazes.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetEyeGazesFB(call_info, return_value, eyeTracker, &gazeInfo, &eyeGazes);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrPassthroughLayerSetKeyboardHandsIntensityFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId layer;
    StructPointerDecoder<Decoded_XrPassthroughKeyboardHandsIntensityFB> intensity;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layer);
    bytes_read += intensity.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrPassthroughLayerSetKeyboardHandsIntensityFB(call_info, return_value, layer, &intensity);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetDeviceSampleRateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrHapticActionInfo> hapticActionInfo;
    StructPointerDecoder<Decoded_XrDevicePcmSampleRateGetInfoFB> deviceSampleRate;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += hapticActionInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += deviceSampleRate.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetDeviceSampleRateFB(call_info, return_value, session, &hapticActionInfo, &deviceSampleRate);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetPassthroughPreferencesMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrPassthroughPreferencesMETA> preferences;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += preferences.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetPassthroughPreferencesMETA(call_info, return_value, session, &preferences);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateVirtualKeyboardMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrVirtualKeyboardCreateInfoMETA> createInfo;
    HandlePointerDecoder<XrVirtualKeyboardMETA> keyboard;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += keyboard.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateVirtualKeyboardMETA(call_info, return_value, session, &createInfo, &keyboard);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyVirtualKeyboardMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId keyboard;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &keyboard);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyVirtualKeyboardMETA(call_info, return_value, keyboard);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateVirtualKeyboardSpaceMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    format::HandleId keyboard;
    StructPointerDecoder<Decoded_XrVirtualKeyboardSpaceCreateInfoMETA> createInfo;
    HandlePointerDecoder<XrSpace> keyboardSpace;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &keyboard);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += keyboardSpace.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateVirtualKeyboardSpaceMETA(call_info, return_value, session, keyboard, &createInfo, &keyboardSpace);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSuggestVirtualKeyboardLocationMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId keyboard;
    StructPointerDecoder<Decoded_XrVirtualKeyboardLocationInfoMETA> locationInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &keyboard);
    bytes_read += locationInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSuggestVirtualKeyboardLocationMETA(call_info, return_value, keyboard, &locationInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVirtualKeyboardScaleMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId keyboard;
    PointerDecoder<float> scale;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &keyboard);
    bytes_read += scale.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVirtualKeyboardScaleMETA(call_info, return_value, keyboard, &scale);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetVirtualKeyboardModelVisibilityMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId keyboard;
    StructPointerDecoder<Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA> modelVisibility;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &keyboard);
    bytes_read += modelVisibility.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetVirtualKeyboardModelVisibilityMETA(call_info, return_value, keyboard, &modelVisibility);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVirtualKeyboardModelAnimationStatesMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId keyboard;
    StructPointerDecoder<Decoded_XrVirtualKeyboardModelAnimationStatesMETA> animationStates;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &keyboard);
    bytes_read += animationStates.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVirtualKeyboardModelAnimationStatesMETA(call_info, return_value, keyboard, &animationStates);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVirtualKeyboardDirtyTexturesMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId keyboard;
    uint32_t textureIdCapacityInput;
    PointerDecoder<uint32_t> textureIdCountOutput;
    PointerDecoder<uint64_t> textureIds;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &keyboard);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &textureIdCapacityInput);
    bytes_read += textureIdCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += textureIds.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVirtualKeyboardDirtyTexturesMETA(call_info, return_value, keyboard, textureIdCapacityInput, &textureIdCountOutput, &textureIds);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetVirtualKeyboardTextureDataMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId keyboard;
    uint64_t textureId;
    StructPointerDecoder<Decoded_XrVirtualKeyboardTextureDataMETA> textureData;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &keyboard);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &textureId);
    bytes_read += textureData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetVirtualKeyboardTextureDataMETA(call_info, return_value, keyboard, textureId, &textureData);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSendVirtualKeyboardInputMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId keyboard;
    StructPointerDecoder<Decoded_XrVirtualKeyboardInputInfoMETA> info;
    StructPointerDecoder<Decoded_XrPosef> interactorRootPose;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &keyboard);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += interactorRootPose.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSendVirtualKeyboardInputMETA(call_info, return_value, keyboard, &info, &interactorRootPose);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrChangeVirtualKeyboardTextContextMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId keyboard;
    StructPointerDecoder<Decoded_XrVirtualKeyboardTextContextChangeInfoMETA> changeInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &keyboard);
    bytes_read += changeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrChangeVirtualKeyboardTextContextMETA(call_info, return_value, keyboard, &changeInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumerateExternalCamerasOCULUS(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    uint32_t cameraCapacityInput;
    PointerDecoder<uint32_t> cameraCountOutput;
    StructPointerDecoder<Decoded_XrExternalCameraOCULUS> cameras;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &cameraCapacityInput);
    bytes_read += cameraCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += cameras.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateExternalCamerasOCULUS(call_info, return_value, session, cameraCapacityInput, &cameraCountOutput, &cameras);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnumeratePerformanceMetricsCounterPathsMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    uint32_t counterPathCapacityInput;
    PointerDecoder<uint32_t> counterPathCountOutput;
    HandlePointerDecoder<XrPath> counterPaths;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counterPathCapacityInput);
    bytes_read += counterPathCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += counterPaths.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumeratePerformanceMetricsCounterPathsMETA(call_info, return_value, instance, counterPathCapacityInput, &counterPathCountOutput, &counterPaths);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetPerformanceMetricsStateMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA> state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += state.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetPerformanceMetricsStateMETA(call_info, return_value, session, &state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetPerformanceMetricsStateMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA> state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += state.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetPerformanceMetricsStateMETA(call_info, return_value, session, &state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrQueryPerformanceMetricsCounterMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrPath counterPath;
    StructPointerDecoder<Decoded_XrPerformanceMetricsCounterMETA> counter;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counterPath);
    bytes_read += counter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrQueryPerformanceMetricsCounterMETA(call_info, return_value, session, counterPath, &counter);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSaveSpaceListFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpaceListSaveInfoFB> info;
    HandlePointerDecoder<XrAsyncRequestIdFB> requestId;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += requestId.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSaveSpaceListFB(call_info, return_value, session, &info, &requestId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSpaceUserFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpaceUserCreateInfoFB> info;
    HandlePointerDecoder<XrSpaceUserFB> user;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += user.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSpaceUserFB(call_info, return_value, session, &info, &user);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpaceUserIdFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId user;
    PointerDecoder<XrSpaceUserIdFB> userId;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &user);
    bytes_read += userId.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpaceUserIdFB(call_info, return_value, user, &userId);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroySpaceUserFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId user;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &user);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroySpaceUserFB(call_info, return_value, user);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetRecommendedLayerResolutionMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrRecommendedLayerResolutionGetInfoMETA> info;
    StructPointerDecoder<Decoded_XrRecommendedLayerResolutionMETA> resolution;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += resolution.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetRecommendedLayerResolutionMETA(call_info, return_value, session, &info, &resolution);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreatePassthroughColorLutMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId passthrough;
    StructPointerDecoder<Decoded_XrPassthroughColorLutCreateInfoMETA> createInfo;
    HandlePointerDecoder<XrPassthroughColorLutMETA> colorLut;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &passthrough);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += colorLut.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreatePassthroughColorLutMETA(call_info, return_value, passthrough, &createInfo, &colorLut);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyPassthroughColorLutMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId colorLut;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &colorLut);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyPassthroughColorLutMETA(call_info, return_value, colorLut);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrUpdatePassthroughColorLutMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId colorLut;
    StructPointerDecoder<Decoded_XrPassthroughColorLutUpdateInfoMETA> updateInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &colorLut);
    bytes_read += updateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrUpdatePassthroughColorLutMETA(call_info, return_value, colorLut, &updateInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpaceTriangleMeshMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId space;
    StructPointerDecoder<Decoded_XrSpaceTriangleMeshGetInfoMETA> getInfo;
    StructPointerDecoder<Decoded_XrSpaceTriangleMeshMETA> triangleMeshOutput;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &space);
    bytes_read += getInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += triangleMeshOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpaceTriangleMeshMETA(call_info, return_value, space, &getInfo, &triangleMeshOutput);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateFaceTracker2FB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrFaceTrackerCreateInfo2FB> createInfo;
    HandlePointerDecoder<XrFaceTracker2FB> faceTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += faceTracker.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateFaceTracker2FB(call_info, return_value, session, &createInfo, &faceTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyFaceTracker2FB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId faceTracker;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceTracker);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyFaceTracker2FB(call_info, return_value, faceTracker);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetFaceExpressionWeights2FB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId faceTracker;
    StructPointerDecoder<Decoded_XrFaceExpressionInfo2FB> expressionInfo;
    StructPointerDecoder<Decoded_XrFaceExpressionWeights2FB> expressionWeights;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceTracker);
    bytes_read += expressionInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += expressionWeights.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetFaceExpressionWeights2FB(call_info, return_value, faceTracker, &expressionInfo, &expressionWeights);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrSetTrackingOptimizationSettingsHintQCOM(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    XrTrackingOptimizationSettingsDomainQCOM domain;
    XrTrackingOptimizationSettingsHintQCOM hint;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &domain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hint);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrSetTrackingOptimizationSettingsHintQCOM(call_info, return_value, session, domain, hint);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreatePassthroughHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrPassthroughCreateInfoHTC> createInfo;
    HandlePointerDecoder<XrPassthroughHTC> passthrough;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += passthrough.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreatePassthroughHTC(call_info, return_value, session, &createInfo, &passthrough);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyPassthroughHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId passthrough;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &passthrough);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyPassthroughHTC(call_info, return_value, passthrough);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrApplyFoveationHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrFoveationApplyInfoHTC> applyInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += applyInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrApplyFoveationHTC(call_info, return_value, session, &applyInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreateSpatialAnchorHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoHTC> createInfo;
    HandlePointerDecoder<XrSpace> anchor;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += anchor.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreateSpatialAnchorHTC(call_info, return_value, session, &createInfo, &anchor);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetSpatialAnchorNameHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId anchor;
    StructPointerDecoder<Decoded_XrSpatialAnchorNameHTC> name;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &anchor);
    bytes_read += name.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetSpatialAnchorNameHTC(call_info, return_value, anchor, &name);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrApplyForceFeedbackCurlMNDX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId handTracker;
    StructPointerDecoder<Decoded_XrForceFeedbackCurlApplyLocationsMNDX> locations;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handTracker);
    bytes_read += locations.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrApplyForceFeedbackCurlMNDX(call_info, return_value, handTracker, &locations);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrCreatePlaneDetectorEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId session;
    StructPointerDecoder<Decoded_XrPlaneDetectorCreateInfoEXT> createInfo;
    HandlePointerDecoder<XrPlaneDetectorEXT> planeDetector;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += createInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += planeDetector.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrCreatePlaneDetectorEXT(call_info, return_value, session, &createInfo, &planeDetector);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrDestroyPlaneDetectorEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId planeDetector;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeDetector);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrDestroyPlaneDetectorEXT(call_info, return_value, planeDetector);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrBeginPlaneDetectionEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId planeDetector;
    StructPointerDecoder<Decoded_XrPlaneDetectorBeginInfoEXT> beginInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeDetector);
    bytes_read += beginInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrBeginPlaneDetectionEXT(call_info, return_value, planeDetector, &beginInfo);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetPlaneDetectionStateEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId planeDetector;
    PointerDecoder<XrPlaneDetectionStateEXT> state;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeDetector);
    bytes_read += state.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetPlaneDetectionStateEXT(call_info, return_value, planeDetector, &state);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetPlaneDetectionsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId planeDetector;
    StructPointerDecoder<Decoded_XrPlaneDetectorGetInfoEXT> info;
    StructPointerDecoder<Decoded_XrPlaneDetectorLocationsEXT> locations;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeDetector);
    bytes_read += info.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += locations.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetPlaneDetectionsEXT(call_info, return_value, planeDetector, &info, &locations);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrGetPlanePolygonBufferEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId planeDetector;
    uint64_t planeId;
    uint32_t polygonBufferIndex;
    StructPointerDecoder<Decoded_XrPlaneDetectorPolygonBufferEXT> polygonBuffer;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeDetector);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeId);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &polygonBufferIndex);
    bytes_read += polygonBuffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrGetPlanePolygonBufferEXT(call_info, return_value, planeDetector, planeId, polygonBufferIndex, &polygonBuffer);
    }

    return bytes_read;
}

size_t OpenXrDecoder::Decode_xrEnableUserCalibrationEventsML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_XrUserCalibrationEnableEventsInfoML> enableInfo;
    XrResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += enableInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnableUserCalibrationEventsML(call_info, return_value, instance, &enableInfo);
    }

    return bytes_read;
}

void OpenXrDecoder::DecodeFunctionCall(format::ApiCallId             call_id,
                                       const ApiCallInfo&            call_info,
                                       const uint8_t*                parameter_buffer,
                                       size_t                        buffer_size)
{
    switch(call_id)
    {
    default:
        OpenXrDecoderBase::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);
        break;

    case format::ApiCallId::ApiCall_xrDestroyInstance:
        Decode_xrDestroyInstance(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetInstanceProperties:
        Decode_xrGetInstanceProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrPollEvent:
        Decode_xrPollEvent(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrResultToString:
        Decode_xrResultToString(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrStructureTypeToString:
        Decode_xrStructureTypeToString(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSystem:
        Decode_xrGetSystem(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSystemProperties:
        Decode_xrGetSystemProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateEnvironmentBlendModes:
        Decode_xrEnumerateEnvironmentBlendModes(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSession:
        Decode_xrCreateSession(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroySession:
        Decode_xrDestroySession(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateReferenceSpaces:
        Decode_xrEnumerateReferenceSpaces(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateReferenceSpace:
        Decode_xrCreateReferenceSpace(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetReferenceSpaceBoundsRect:
        Decode_xrGetReferenceSpaceBoundsRect(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateActionSpace:
        Decode_xrCreateActionSpace(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrLocateSpace:
        Decode_xrLocateSpace(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroySpace:
        Decode_xrDestroySpace(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateViewConfigurations:
        Decode_xrEnumerateViewConfigurations(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetViewConfigurationProperties:
        Decode_xrGetViewConfigurationProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateViewConfigurationViews:
        Decode_xrEnumerateViewConfigurationViews(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateSwapchainFormats:
        Decode_xrEnumerateSwapchainFormats(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSwapchain:
        Decode_xrCreateSwapchain(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroySwapchain:
        Decode_xrDestroySwapchain(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateSwapchainImages:
        Decode_xrEnumerateSwapchainImages(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrAcquireSwapchainImage:
        Decode_xrAcquireSwapchainImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrWaitSwapchainImage:
        Decode_xrWaitSwapchainImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrReleaseSwapchainImage:
        Decode_xrReleaseSwapchainImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrBeginSession:
        Decode_xrBeginSession(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEndSession:
        Decode_xrEndSession(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrRequestExitSession:
        Decode_xrRequestExitSession(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrWaitFrame:
        Decode_xrWaitFrame(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrBeginFrame:
        Decode_xrBeginFrame(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEndFrame:
        Decode_xrEndFrame(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrLocateViews:
        Decode_xrLocateViews(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrStringToPath:
        Decode_xrStringToPath(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrPathToString:
        Decode_xrPathToString(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateActionSet:
        Decode_xrCreateActionSet(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyActionSet:
        Decode_xrDestroyActionSet(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateAction:
        Decode_xrCreateAction(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyAction:
        Decode_xrDestroyAction(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSuggestInteractionProfileBindings:
        Decode_xrSuggestInteractionProfileBindings(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrAttachSessionActionSets:
        Decode_xrAttachSessionActionSets(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetCurrentInteractionProfile:
        Decode_xrGetCurrentInteractionProfile(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetActionStateBoolean:
        Decode_xrGetActionStateBoolean(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetActionStateFloat:
        Decode_xrGetActionStateFloat(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetActionStateVector2f:
        Decode_xrGetActionStateVector2f(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetActionStatePose:
        Decode_xrGetActionStatePose(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSyncActions:
        Decode_xrSyncActions(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateBoundSourcesForAction:
        Decode_xrEnumerateBoundSourcesForAction(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetInputSourceLocalizedName:
        Decode_xrGetInputSourceLocalizedName(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrApplyHapticFeedback:
        Decode_xrApplyHapticFeedback(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrStopHapticFeedback:
        Decode_xrStopHapticFeedback(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateApiLayerInstance:
        Decode_xrCreateApiLayerInstance(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetAndroidApplicationThreadKHR:
        Decode_xrSetAndroidApplicationThreadKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR:
        Decode_xrCreateSwapchainAndroidSurfaceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetOpenGLGraphicsRequirementsKHR:
        Decode_xrGetOpenGLGraphicsRequirementsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetOpenGLESGraphicsRequirementsKHR:
        Decode_xrGetOpenGLESGraphicsRequirementsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVulkanInstanceExtensionsKHR:
        Decode_xrGetVulkanInstanceExtensionsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVulkanDeviceExtensionsKHR:
        Decode_xrGetVulkanDeviceExtensionsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVulkanGraphicsDeviceKHR:
        Decode_xrGetVulkanGraphicsDeviceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirementsKHR:
        Decode_xrGetVulkanGraphicsRequirementsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetD3D11GraphicsRequirementsKHR:
        Decode_xrGetD3D11GraphicsRequirementsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetD3D12GraphicsRequirementsKHR:
        Decode_xrGetD3D12GraphicsRequirementsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVisibilityMaskKHR:
        Decode_xrGetVisibilityMaskKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR:
        Decode_xrConvertWin32PerformanceCounterToTimeKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR:
        Decode_xrConvertTimeToWin32PerformanceCounterKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrConvertTimespecTimeToTimeKHR:
        Decode_xrConvertTimespecTimeToTimeKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR:
        Decode_xrConvertTimeToTimespecTimeKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrInitializeLoaderKHR:
        Decode_xrInitializeLoaderKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateVulkanInstanceKHR:
        Decode_xrCreateVulkanInstanceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateVulkanDeviceKHR:
        Decode_xrCreateVulkanDeviceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVulkanGraphicsDevice2KHR:
        Decode_xrGetVulkanGraphicsDevice2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirements2KHR:
        Decode_xrGetVulkanGraphicsRequirements2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrPerfSettingsSetPerformanceLevelEXT:
        Decode_xrPerfSettingsSetPerformanceLevelEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrThermalGetTemperatureTrendEXT:
        Decode_xrThermalGetTemperatureTrendEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetDebugUtilsObjectNameEXT:
        Decode_xrSetDebugUtilsObjectNameEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateDebugUtilsMessengerEXT:
        Decode_xrCreateDebugUtilsMessengerEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyDebugUtilsMessengerEXT:
        Decode_xrDestroyDebugUtilsMessengerEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSubmitDebugUtilsMessageEXT:
        Decode_xrSubmitDebugUtilsMessageEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSessionBeginDebugUtilsLabelRegionEXT:
        Decode_xrSessionBeginDebugUtilsLabelRegionEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSessionEndDebugUtilsLabelRegionEXT:
        Decode_xrSessionEndDebugUtilsLabelRegionEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSessionInsertDebugUtilsLabelEXT:
        Decode_xrSessionInsertDebugUtilsLabelEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSpatialAnchorMSFT:
        Decode_xrCreateSpatialAnchorMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSpatialAnchorSpaceMSFT:
        Decode_xrCreateSpatialAnchorSpaceMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroySpatialAnchorMSFT:
        Decode_xrDestroySpatialAnchorMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetInputDeviceActiveEXT:
        Decode_xrSetInputDeviceActiveEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetInputDeviceStateBoolEXT:
        Decode_xrSetInputDeviceStateBoolEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetInputDeviceStateFloatEXT:
        Decode_xrSetInputDeviceStateFloatEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetInputDeviceStateVector2fEXT:
        Decode_xrSetInputDeviceStateVector2fEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetInputDeviceLocationEXT:
        Decode_xrSetInputDeviceLocationEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSpatialGraphNodeSpaceMSFT:
        Decode_xrCreateSpatialGraphNodeSpaceMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT:
        Decode_xrTryCreateSpatialGraphStaticNodeBindingMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroySpatialGraphNodeBindingMSFT:
        Decode_xrDestroySpatialGraphNodeBindingMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT:
        Decode_xrGetSpatialGraphNodeBindingPropertiesMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateHandTrackerEXT:
        Decode_xrCreateHandTrackerEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyHandTrackerEXT:
        Decode_xrDestroyHandTrackerEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrLocateHandJointsEXT:
        Decode_xrLocateHandJointsEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateHandMeshSpaceMSFT:
        Decode_xrCreateHandMeshSpaceMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrUpdateHandMeshMSFT:
        Decode_xrUpdateHandMeshMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetControllerModelKeyMSFT:
        Decode_xrGetControllerModelKeyMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrLoadControllerModelMSFT:
        Decode_xrLoadControllerModelMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetControllerModelPropertiesMSFT:
        Decode_xrGetControllerModelPropertiesMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetControllerModelStateMSFT:
        Decode_xrGetControllerModelStateMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT:
        Decode_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT:
        Decode_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateReprojectionModesMSFT:
        Decode_xrEnumerateReprojectionModesMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrUpdateSwapchainFB:
        Decode_xrUpdateSwapchainFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSwapchainStateFB:
        Decode_xrGetSwapchainStateFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateBodyTrackerFB:
        Decode_xrCreateBodyTrackerFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyBodyTrackerFB:
        Decode_xrDestroyBodyTrackerFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrLocateBodyJointsFB:
        Decode_xrLocateBodyJointsFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetBodySkeletonFB:
        Decode_xrGetBodySkeletonFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateSceneComputeFeaturesMSFT:
        Decode_xrEnumerateSceneComputeFeaturesMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSceneObserverMSFT:
        Decode_xrCreateSceneObserverMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroySceneObserverMSFT:
        Decode_xrDestroySceneObserverMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSceneMSFT:
        Decode_xrCreateSceneMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroySceneMSFT:
        Decode_xrDestroySceneMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrComputeNewSceneMSFT:
        Decode_xrComputeNewSceneMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSceneComputeStateMSFT:
        Decode_xrGetSceneComputeStateMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSceneComponentsMSFT:
        Decode_xrGetSceneComponentsMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrLocateSceneComponentsMSFT:
        Decode_xrLocateSceneComponentsMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSceneMeshBuffersMSFT:
        Decode_xrGetSceneMeshBuffersMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDeserializeSceneMSFT:
        Decode_xrDeserializeSceneMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSerializedSceneFragmentDataMSFT:
        Decode_xrGetSerializedSceneFragmentDataMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateDisplayRefreshRatesFB:
        Decode_xrEnumerateDisplayRefreshRatesFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetDisplayRefreshRateFB:
        Decode_xrGetDisplayRefreshRateFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrRequestDisplayRefreshRateFB:
        Decode_xrRequestDisplayRefreshRateFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateViveTrackerPathsHTCX:
        Decode_xrEnumerateViveTrackerPathsHTCX(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateFacialTrackerHTC:
        Decode_xrCreateFacialTrackerHTC(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyFacialTrackerHTC:
        Decode_xrDestroyFacialTrackerHTC(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetFacialExpressionsHTC:
        Decode_xrGetFacialExpressionsHTC(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateColorSpacesFB:
        Decode_xrEnumerateColorSpacesFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetColorSpaceFB:
        Decode_xrSetColorSpaceFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetHandMeshFB:
        Decode_xrGetHandMeshFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSpatialAnchorFB:
        Decode_xrCreateSpatialAnchorFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpaceUuidFB:
        Decode_xrGetSpaceUuidFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateSpaceSupportedComponentsFB:
        Decode_xrEnumerateSpaceSupportedComponentsFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetSpaceComponentStatusFB:
        Decode_xrSetSpaceComponentStatusFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpaceComponentStatusFB:
        Decode_xrGetSpaceComponentStatusFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateFoveationProfileFB:
        Decode_xrCreateFoveationProfileFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyFoveationProfileFB:
        Decode_xrDestroyFoveationProfileFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrQuerySystemTrackedKeyboardFB:
        Decode_xrQuerySystemTrackedKeyboardFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateKeyboardSpaceFB:
        Decode_xrCreateKeyboardSpaceFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrTriangleMeshBeginUpdateFB:
        Decode_xrTriangleMeshBeginUpdateFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrTriangleMeshEndUpdateFB:
        Decode_xrTriangleMeshEndUpdateFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB:
        Decode_xrTriangleMeshBeginVertexBufferUpdateFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrTriangleMeshEndVertexBufferUpdateFB:
        Decode_xrTriangleMeshEndVertexBufferUpdateFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreatePassthroughFB:
        Decode_xrCreatePassthroughFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyPassthroughFB:
        Decode_xrDestroyPassthroughFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrPassthroughStartFB:
        Decode_xrPassthroughStartFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrPassthroughPauseFB:
        Decode_xrPassthroughPauseFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreatePassthroughLayerFB:
        Decode_xrCreatePassthroughLayerFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyPassthroughLayerFB:
        Decode_xrDestroyPassthroughLayerFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrPassthroughLayerPauseFB:
        Decode_xrPassthroughLayerPauseFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrPassthroughLayerResumeFB:
        Decode_xrPassthroughLayerResumeFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrPassthroughLayerSetStyleFB:
        Decode_xrPassthroughLayerSetStyleFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateGeometryInstanceFB:
        Decode_xrCreateGeometryInstanceFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyGeometryInstanceFB:
        Decode_xrDestroyGeometryInstanceFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGeometryInstanceSetTransformFB:
        Decode_xrGeometryInstanceSetTransformFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateRenderModelPathsFB:
        Decode_xrEnumerateRenderModelPathsFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetRenderModelPropertiesFB:
        Decode_xrGetRenderModelPropertiesFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrLoadRenderModelFB:
        Decode_xrLoadRenderModelFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetEnvironmentDepthEstimationVARJO:
        Decode_xrSetEnvironmentDepthEstimationVARJO(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetMarkerTrackingVARJO:
        Decode_xrSetMarkerTrackingVARJO(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetMarkerTrackingTimeoutVARJO:
        Decode_xrSetMarkerTrackingTimeoutVARJO(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetMarkerTrackingPredictionVARJO:
        Decode_xrSetMarkerTrackingPredictionVARJO(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetMarkerSizeVARJO:
        Decode_xrGetMarkerSizeVARJO(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateMarkerSpaceVARJO:
        Decode_xrCreateMarkerSpaceVARJO(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetViewOffsetVARJO:
        Decode_xrSetViewOffsetVARJO(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSpaceFromCoordinateFrameUIDML:
        Decode_xrCreateSpaceFromCoordinateFrameUIDML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateMarkerDetectorML:
        Decode_xrCreateMarkerDetectorML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyMarkerDetectorML:
        Decode_xrDestroyMarkerDetectorML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSnapshotMarkerDetectorML:
        Decode_xrSnapshotMarkerDetectorML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetMarkerDetectorStateML:
        Decode_xrGetMarkerDetectorStateML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetMarkersML:
        Decode_xrGetMarkersML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetMarkerReprojectionErrorML:
        Decode_xrGetMarkerReprojectionErrorML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetMarkerLengthML:
        Decode_xrGetMarkerLengthML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetMarkerNumberML:
        Decode_xrGetMarkerNumberML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetMarkerStringML:
        Decode_xrGetMarkerStringML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateMarkerSpaceML:
        Decode_xrCreateMarkerSpaceML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnableLocalizationEventsML:
        Decode_xrEnableLocalizationEventsML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrQueryLocalizationMapsML:
        Decode_xrQueryLocalizationMapsML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrRequestMapLocalizationML:
        Decode_xrRequestMapLocalizationML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrImportLocalizationMapML:
        Decode_xrImportLocalizationMapML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateExportedLocalizationMapML:
        Decode_xrCreateExportedLocalizationMapML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyExportedLocalizationMapML:
        Decode_xrDestroyExportedLocalizationMapML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetExportedLocalizationMapDataML:
        Decode_xrGetExportedLocalizationMapDataML(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT:
        Decode_xrCreateSpatialAnchorStoreConnectionMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT:
        Decode_xrDestroySpatialAnchorStoreConnectionMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrPersistSpatialAnchorMSFT:
        Decode_xrPersistSpatialAnchorMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT:
        Decode_xrEnumeratePersistedSpatialAnchorNamesMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT:
        Decode_xrCreateSpatialAnchorFromPersistedNameMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrUnpersistSpatialAnchorMSFT:
        Decode_xrUnpersistSpatialAnchorMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrClearSpatialAnchorStoreMSFT:
        Decode_xrClearSpatialAnchorStoreMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSceneMarkerRawDataMSFT:
        Decode_xrGetSceneMarkerRawDataMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSceneMarkerDecodedStringMSFT:
        Decode_xrGetSceneMarkerDecodedStringMSFT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrQuerySpacesFB:
        Decode_xrQuerySpacesFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrRetrieveSpaceQueryResultsFB:
        Decode_xrRetrieveSpaceQueryResultsFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSaveSpaceFB:
        Decode_xrSaveSpaceFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEraseSpaceFB:
        Decode_xrEraseSpaceFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetAudioOutputDeviceGuidOculus:
        Decode_xrGetAudioOutputDeviceGuidOculus(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetAudioInputDeviceGuidOculus:
        Decode_xrGetAudioInputDeviceGuidOculus(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrShareSpacesFB:
        Decode_xrShareSpacesFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpaceBoundingBox2DFB:
        Decode_xrGetSpaceBoundingBox2DFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpaceBoundingBox3DFB:
        Decode_xrGetSpaceBoundingBox3DFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpaceSemanticLabelsFB:
        Decode_xrGetSpaceSemanticLabelsFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpaceBoundary2DFB:
        Decode_xrGetSpaceBoundary2DFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpaceRoomLayoutFB:
        Decode_xrGetSpaceRoomLayoutFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetDigitalLensControlALMALENCE:
        Decode_xrSetDigitalLensControlALMALENCE(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrRequestSceneCaptureFB:
        Decode_xrRequestSceneCaptureFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpaceContainerFB:
        Decode_xrGetSpaceContainerFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetFoveationEyeTrackedStateMETA:
        Decode_xrGetFoveationEyeTrackedStateMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateFaceTrackerFB:
        Decode_xrCreateFaceTrackerFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyFaceTrackerFB:
        Decode_xrDestroyFaceTrackerFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetFaceExpressionWeightsFB:
        Decode_xrGetFaceExpressionWeightsFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateEyeTrackerFB:
        Decode_xrCreateEyeTrackerFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyEyeTrackerFB:
        Decode_xrDestroyEyeTrackerFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetEyeGazesFB:
        Decode_xrGetEyeGazesFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrPassthroughLayerSetKeyboardHandsIntensityFB:
        Decode_xrPassthroughLayerSetKeyboardHandsIntensityFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetDeviceSampleRateFB:
        Decode_xrGetDeviceSampleRateFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetPassthroughPreferencesMETA:
        Decode_xrGetPassthroughPreferencesMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateVirtualKeyboardMETA:
        Decode_xrCreateVirtualKeyboardMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyVirtualKeyboardMETA:
        Decode_xrDestroyVirtualKeyboardMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateVirtualKeyboardSpaceMETA:
        Decode_xrCreateVirtualKeyboardSpaceMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSuggestVirtualKeyboardLocationMETA:
        Decode_xrSuggestVirtualKeyboardLocationMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVirtualKeyboardScaleMETA:
        Decode_xrGetVirtualKeyboardScaleMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetVirtualKeyboardModelVisibilityMETA:
        Decode_xrSetVirtualKeyboardModelVisibilityMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA:
        Decode_xrGetVirtualKeyboardModelAnimationStatesMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA:
        Decode_xrGetVirtualKeyboardDirtyTexturesMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetVirtualKeyboardTextureDataMETA:
        Decode_xrGetVirtualKeyboardTextureDataMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSendVirtualKeyboardInputMETA:
        Decode_xrSendVirtualKeyboardInputMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrChangeVirtualKeyboardTextContextMETA:
        Decode_xrChangeVirtualKeyboardTextContextMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumerateExternalCamerasOCULUS:
        Decode_xrEnumerateExternalCamerasOCULUS(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA:
        Decode_xrEnumeratePerformanceMetricsCounterPathsMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetPerformanceMetricsStateMETA:
        Decode_xrSetPerformanceMetricsStateMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetPerformanceMetricsStateMETA:
        Decode_xrGetPerformanceMetricsStateMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrQueryPerformanceMetricsCounterMETA:
        Decode_xrQueryPerformanceMetricsCounterMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSaveSpaceListFB:
        Decode_xrSaveSpaceListFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSpaceUserFB:
        Decode_xrCreateSpaceUserFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpaceUserIdFB:
        Decode_xrGetSpaceUserIdFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroySpaceUserFB:
        Decode_xrDestroySpaceUserFB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetRecommendedLayerResolutionMETA:
        Decode_xrGetRecommendedLayerResolutionMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreatePassthroughColorLutMETA:
        Decode_xrCreatePassthroughColorLutMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyPassthroughColorLutMETA:
        Decode_xrDestroyPassthroughColorLutMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrUpdatePassthroughColorLutMETA:
        Decode_xrUpdatePassthroughColorLutMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpaceTriangleMeshMETA:
        Decode_xrGetSpaceTriangleMeshMETA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateFaceTracker2FB:
        Decode_xrCreateFaceTracker2FB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyFaceTracker2FB:
        Decode_xrDestroyFaceTracker2FB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetFaceExpressionWeights2FB:
        Decode_xrGetFaceExpressionWeights2FB(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrSetTrackingOptimizationSettingsHintQCOM:
        Decode_xrSetTrackingOptimizationSettingsHintQCOM(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreatePassthroughHTC:
        Decode_xrCreatePassthroughHTC(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyPassthroughHTC:
        Decode_xrDestroyPassthroughHTC(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrApplyFoveationHTC:
        Decode_xrApplyFoveationHTC(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreateSpatialAnchorHTC:
        Decode_xrCreateSpatialAnchorHTC(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetSpatialAnchorNameHTC:
        Decode_xrGetSpatialAnchorNameHTC(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrApplyForceFeedbackCurlMNDX:
        Decode_xrApplyForceFeedbackCurlMNDX(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrCreatePlaneDetectorEXT:
        Decode_xrCreatePlaneDetectorEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrDestroyPlaneDetectorEXT:
        Decode_xrDestroyPlaneDetectorEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrBeginPlaneDetectionEXT:
        Decode_xrBeginPlaneDetectionEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetPlaneDetectionStateEXT:
        Decode_xrGetPlaneDetectionStateEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetPlaneDetectionsEXT:
        Decode_xrGetPlaneDetectionsEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrGetPlanePolygonBufferEXT:
        Decode_xrGetPlanePolygonBufferEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_xrEnableUserCalibrationEventsML:
        Decode_xrEnableUserCalibrationEventsML(call_info, parameter_buffer, buffer_size);
        break;
    }
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
