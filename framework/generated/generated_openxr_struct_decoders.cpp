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

#include "decode/custom_dx12_struct_decoders.h"
#include "decode/custom_openxr_struct_decoders.h"
#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/decode_allocator.h"

#include "generated/generated_openxr_struct_decoders.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodeNextStruct(const uint8_t* buffer, size_t buffer_size, OpenXrNextNode** next);

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrApiLayerProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrApiLayerProperties* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->layerName.SetExternalMemory(value->layerName, XR_MAX_API_LAYER_NAME_SIZE);
    bytes_read += wrapper->layerName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->specVersion));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerVersion));
    wrapper->description.SetExternalMemory(value->description, XR_MAX_API_LAYER_DESCRIPTION_SIZE);
    bytes_read += wrapper->description.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrExtensionProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrExtensionProperties* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->extensionName.SetExternalMemory(value->extensionName, XR_MAX_EXTENSION_NAME_SIZE);
    bytes_read += wrapper->extensionName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->extensionVersion));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrApplicationInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrApplicationInfo* value = wrapper->decoded_value;

    wrapper->applicationName.SetExternalMemory(value->applicationName, XR_MAX_APPLICATION_NAME_SIZE);
    bytes_read += wrapper->applicationName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->applicationVersion));
    wrapper->engineName.SetExternalMemory(value->engineName, XR_MAX_ENGINE_NAME_SIZE);
    bytes_read += wrapper->engineName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->engineVersion));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->apiVersion));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrInstanceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrInstanceCreateInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->createFlags));
    wrapper->applicationInfo = DecodeAllocator::Allocate<Decoded_XrApplicationInfo>();
    wrapper->applicationInfo->decoded_value = &(value->applicationInfo);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->applicationInfo);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledApiLayerCount));
    bytes_read += wrapper->enabledApiLayerNames.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->enabledApiLayerNames = wrapper->enabledApiLayerNames.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledExtensionCount));
    bytes_read += wrapper->enabledExtensionNames.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->enabledExtensionNames = wrapper->enabledExtensionNames.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrInstanceProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrInstanceProperties* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->runtimeVersion));
    wrapper->runtimeName.SetExternalMemory(value->runtimeName, XR_MAX_RUNTIME_NAME_SIZE);
    bytes_read += wrapper->runtimeName.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataBuffer* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataBuffer* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->varying.SetExternalMemory(value->varying, 4000);
    bytes_read += wrapper->varying.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemGetInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemGetInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->formFactor));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemGraphicsProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemGraphicsProperties* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSwapchainImageHeight));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSwapchainImageWidth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxLayerCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemTrackingProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemTrackingProperties* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->orientationTracking));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->positionTracking));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemProperties* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->systemId));
    value->systemId = XR_NULL_SYSTEM_ID;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vendorId));
    wrapper->systemName.SetExternalMemory(value->systemName, XR_MAX_SYSTEM_NAME_SIZE);
    bytes_read += wrapper->systemName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->graphicsProperties = DecodeAllocator::Allocate<Decoded_XrSystemGraphicsProperties>();
    wrapper->graphicsProperties->decoded_value = &(value->graphicsProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->graphicsProperties);
    wrapper->trackingProperties = DecodeAllocator::Allocate<Decoded_XrSystemTrackingProperties>();
    wrapper->trackingProperties->decoded_value = &(value->trackingProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->trackingProperties);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSessionCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSessionCreateInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->createFlags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->systemId));
    value->systemId = XR_NULL_SYSTEM_ID;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVector3f* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVector3f* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->z));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceVelocity* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceVelocity* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->velocityFlags));
    wrapper->linearVelocity = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->linearVelocity->decoded_value = &(value->linearVelocity);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->linearVelocity);
    wrapper->angularVelocity = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->angularVelocity->decoded_value = &(value->angularVelocity);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->angularVelocity);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrQuaternionf* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrQuaternionf* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->z));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->w));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPosef* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPosef* value = wrapper->decoded_value;

    wrapper->orientation = DecodeAllocator::Allocate<Decoded_XrQuaternionf>();
    wrapper->orientation->decoded_value = &(value->orientation);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->orientation);
    wrapper->position = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->position->decoded_value = &(value->position);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->position);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrReferenceSpaceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrReferenceSpaceCreateInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->referenceSpaceType));
    wrapper->poseInReferenceSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInReferenceSpace->decoded_value = &(value->poseInReferenceSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInReferenceSpace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrExtent2Df* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrExtent2Df* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActionSpaceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActionSpaceCreateInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->action));
    value->action = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->subactionPath));
    value->subactionPath = XR_NULL_PATH;
    wrapper->poseInActionSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInActionSpace->decoded_value = &(value->poseInActionSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInActionSpace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceLocation* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceLocation* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->locationFlags));
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrViewConfigurationProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrViewConfigurationProperties* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewConfigurationType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fovMutable));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrViewConfigurationView* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrViewConfigurationView* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->recommendedImageRectWidth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageRectWidth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->recommendedImageRectHeight));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageRectHeight));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->recommendedSwapchainSampleCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSwapchainSampleCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainCreateInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->createFlags));
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->usageFlags));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->faceCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->arraySize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->mipCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageBaseHeader* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainImageBaseHeader* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageAcquireInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainImageAcquireInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageWaitInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainImageWaitInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->timeout));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageReleaseInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainImageReleaseInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSessionBeginInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSessionBeginInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->primaryViewConfigurationType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFrameWaitInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFrameWaitInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFrameState* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFrameState* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->predictedDisplayTime));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->predictedDisplayPeriod));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shouldRender));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFrameBeginInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFrameBeginInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerBaseHeader* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerBaseHeader* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerFlags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrViewLocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrViewLocateInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewConfigurationType));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->displayTime));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrViewState* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrViewState* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewStateFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFovf* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFovf* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->angleLeft));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->angleRight));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->angleUp));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->angleDown));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrView* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrView* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    wrapper->fov = DecodeAllocator::Allocate<Decoded_XrFovf>();
    wrapper->fov->decoded_value = &(value->fov);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->fov);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActionSetCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActionSetCreateInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->actionSetName.SetExternalMemory(value->actionSetName, XR_MAX_ACTION_SET_NAME_SIZE);
    bytes_read += wrapper->actionSetName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->localizedActionSetName.SetExternalMemory(value->localizedActionSetName, XR_MAX_LOCALIZED_ACTION_SET_NAME_SIZE);
    bytes_read += wrapper->localizedActionSetName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->priority));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActionCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActionCreateInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->actionName.SetExternalMemory(value->actionName, XR_MAX_ACTION_NAME_SIZE);
    bytes_read += wrapper->actionName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->actionType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->countSubactionPaths));
    bytes_read += wrapper->subactionPaths.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->subactionPaths = nullptr;
    wrapper->localizedActionName.SetExternalMemory(value->localizedActionName, XR_MAX_LOCALIZED_ACTION_NAME_SIZE);
    bytes_read += wrapper->localizedActionName.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActionSuggestedBinding* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActionSuggestedBinding* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->action));
    value->action = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->binding));
    value->binding = XR_NULL_PATH;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrInteractionProfileSuggestedBinding* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrInteractionProfileSuggestedBinding* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->interactionProfile));
    value->interactionProfile = XR_NULL_PATH;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->countSuggestedBindings));
    wrapper->suggestedBindings = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrActionSuggestedBinding>>();
    bytes_read += wrapper->suggestedBindings->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->suggestedBindings = wrapper->suggestedBindings->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSessionActionSetsAttachInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSessionActionSetsAttachInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->countActionSets));
    bytes_read += wrapper->actionSets.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->actionSets = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrInteractionProfileState* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrInteractionProfileState* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->interactionProfile));
    value->interactionProfile = XR_NULL_PATH;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActionStateGetInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActionStateGetInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->action));
    value->action = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->subactionPath));
    value->subactionPath = XR_NULL_PATH;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActionStateBoolean* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActionStateBoolean* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->currentState));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->changedSinceLastSync));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->lastChangeTime));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isActive));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActionStateFloat* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActionStateFloat* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->currentState));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->changedSinceLastSync));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->lastChangeTime));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isActive));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVector2f* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVector2f* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActionStateVector2f* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActionStateVector2f* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->currentState = DecodeAllocator::Allocate<Decoded_XrVector2f>();
    wrapper->currentState->decoded_value = &(value->currentState);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->currentState);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->changedSinceLastSync));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->lastChangeTime));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isActive));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActionStatePose* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActionStatePose* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isActive));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActiveActionSet* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActiveActionSet* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->actionSet));
    value->actionSet = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->subactionPath));
    value->subactionPath = XR_NULL_PATH;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActionsSyncInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActionsSyncInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->countActiveActionSets));
    wrapper->activeActionSets = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrActiveActionSet>>();
    bytes_read += wrapper->activeActionSets->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->activeActionSets = wrapper->activeActionSets->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBoundSourcesForActionEnumerateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrBoundSourcesForActionEnumerateInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->action));
    value->action = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrInputSourceLocalizedNameGetInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrInputSourceLocalizedNameGetInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sourcePath));
    value->sourcePath = XR_NULL_PATH;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->whichComponents));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHapticActionInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHapticActionInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->action));
    value->action = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->subactionPath));
    value->subactionPath = XR_NULL_PATH;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHapticBaseHeader* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHapticBaseHeader* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrOffset2Di* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrOffset2Di* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrExtent2Di* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrExtent2Di* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRect2Di* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRect2Di* value = wrapper->decoded_value;

    wrapper->offset = DecodeAllocator::Allocate<Decoded_XrOffset2Di>();
    wrapper->offset->decoded_value = &(value->offset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->offset);
    wrapper->extent = DecodeAllocator::Allocate<Decoded_XrExtent2Di>();
    wrapper->extent->decoded_value = &(value->extent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extent);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainSubImage* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainSubImage* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->swapchain));
    value->swapchain = XR_NULL_HANDLE;
    wrapper->imageRect = DecodeAllocator::Allocate<Decoded_XrRect2Di>();
    wrapper->imageRect->decoded_value = &(value->imageRect);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageRect);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageArrayIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerProjectionView* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerProjectionView* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    wrapper->fov = DecodeAllocator::Allocate<Decoded_XrFovf>();
    wrapper->fov->decoded_value = &(value->fov);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->fov);
    wrapper->subImage = DecodeAllocator::Allocate<Decoded_XrSwapchainSubImage>();
    wrapper->subImage->decoded_value = &(value->subImage);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->subImage);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerProjection* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerProjection* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerFlags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewCount));
    wrapper->views = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrCompositionLayerProjectionView>>();
    bytes_read += wrapper->views->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->views = wrapper->views->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerQuad* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerQuad* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerFlags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->eyeVisibility));
    wrapper->subImage = DecodeAllocator::Allocate<Decoded_XrSwapchainSubImage>();
    wrapper->subImage->decoded_value = &(value->subImage);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->subImage);
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    wrapper->size = DecodeAllocator::Allocate<Decoded_XrExtent2Df>();
    wrapper->size->decoded_value = &(value->size);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->size);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataBaseHeader* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataBaseHeader* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataEventsLost* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataEventsLost* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->lostEventCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataInstanceLossPending* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataInstanceLossPending* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->lossTime));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataSessionStateChanged* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataSessionStateChanged* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->session));
    value->session = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->state));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataReferenceSpaceChangePending* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataReferenceSpaceChangePending* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->session));
    value->session = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->referenceSpaceType));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->changeTime));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->poseValid));
    wrapper->poseInPreviousSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInPreviousSpace->decoded_value = &(value->poseInPreviousSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInPreviousSpace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataInteractionProfileChanged* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataInteractionProfileChanged* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->session));
    value->session = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHapticVibration* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHapticVibration* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->duration));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->frequency));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->amplitude));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrOffset2Df* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrOffset2Df* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRect2Df* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRect2Df* value = wrapper->decoded_value;

    wrapper->offset = DecodeAllocator::Allocate<Decoded_XrOffset2Df>();
    wrapper->offset->decoded_value = &(value->offset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->offset);
    wrapper->extent = DecodeAllocator::Allocate<Decoded_XrExtent2Df>();
    wrapper->extent->decoded_value = &(value->extent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extent);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVector4f* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVector4f* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->z));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->w));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrColor4f* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrColor4f* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->r));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->g));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->b));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->a));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrApiLayerNextInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrApiLayerNextInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->structType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->structVersion));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->structSize));
    wrapper->layerName.SetExternalMemory(value->layerName, XR_MAX_API_LAYER_NAME_SIZE);
    bytes_read += wrapper->layerName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->nextGetInstanceProcAddr));
    value->nextGetInstanceProcAddr = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->nextCreateApiLayerInstance));
    value->nextCreateApiLayerInstance = nullptr;
    wrapper->next = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrApiLayerNextInfo>>();
    bytes_read += wrapper->next->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->next = wrapper->next->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrApiLayerCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrApiLayerCreateInfo* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->structType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->structVersion));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->structSize));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->loaderInstance));
    value->loaderInstance = nullptr;
    wrapper->settings_file_location.SetExternalMemory(value->settings_file_location, XR_API_LAYER_MAX_SETTINGS_PATH_SIZE);
    bytes_read += wrapper->settings_file_location.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->nextInfo = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrApiLayerNextInfo>>();
    bytes_read += wrapper->nextInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->nextInfo = wrapper->nextInfo->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrNegotiateApiLayerRequest* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrNegotiateApiLayerRequest* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->structType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->structVersion));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->structSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerInterfaceVersion));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerApiVersion));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->getInstanceProcAddr));
    value->getInstanceProcAddr = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->createApiLayerInstance));
    value->createApiLayerInstance = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerCubeKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerCubeKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerFlags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->eyeVisibility));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->swapchain));
    value->swapchain = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageArrayIndex));
    wrapper->orientation = DecodeAllocator::Allocate<Decoded_XrQuaternionf>();
    wrapper->orientation->decoded_value = &(value->orientation);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->orientation);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrInstanceCreateInfoAndroidKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrInstanceCreateInfoAndroidKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->applicationVM));
    value->applicationVM = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->applicationActivity));
    value->applicationActivity = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerDepthInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerDepthInfoKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->subImage = DecodeAllocator::Allocate<Decoded_XrSwapchainSubImage>();
    wrapper->subImage->decoded_value = &(value->subImage);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->subImage);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minDepth));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDepth));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->nearZ));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->farZ));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVulkanSwapchainFormatListCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVulkanSwapchainFormatListCreateInfoKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewFormatCount));
    bytes_read += wrapper->viewFormats.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->viewFormats = wrapper->viewFormats.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerCylinderKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerCylinderKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerFlags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->eyeVisibility));
    wrapper->subImage = DecodeAllocator::Allocate<Decoded_XrSwapchainSubImage>();
    wrapper->subImage->decoded_value = &(value->subImage);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->subImage);
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->radius));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->centralAngle));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectRatio));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerEquirectKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerEquirectKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerFlags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->eyeVisibility));
    wrapper->subImage = DecodeAllocator::Allocate<Decoded_XrSwapchainSubImage>();
    wrapper->subImage->decoded_value = &(value->subImage);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->subImage);
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->radius));
    wrapper->scale = DecodeAllocator::Allocate<Decoded_XrVector2f>();
    wrapper->scale->decoded_value = &(value->scale);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->scale);
    wrapper->bias = DecodeAllocator::Allocate<Decoded_XrVector2f>();
    wrapper->bias->decoded_value = &(value->bias);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->bias);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsBindingOpenGLWin32KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsBindingOpenGLWin32KHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->hDC));
    value->hDC = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->hGLRC));
    value->hGLRC = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsBindingOpenGLXlibKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsBindingOpenGLXlibKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->xDisplay));
    value->xDisplay = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->visualid));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->glxFBConfig));
    value->glxFBConfig = nullptr;
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->glxDrawable));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->glxContext));
    value->glxContext = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsBindingOpenGLXcbKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsBindingOpenGLXcbKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->connection));
    value->connection = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->screenNumber));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fbconfigid));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->visualid));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->glxDrawable));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->glxContext));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsBindingOpenGLWaylandKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsBindingOpenGLWaylandKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->display));
    value->display = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageOpenGLKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainImageOpenGLKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->image));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsRequirementsOpenGLKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsRequirementsOpenGLKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minApiVersionSupported));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxApiVersionSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsBindingOpenGLESAndroidKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsBindingOpenGLESAndroidKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->display));
    value->display = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->config));
    value->config = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->context));
    value->context = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageOpenGLESKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainImageOpenGLESKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->image));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsRequirementsOpenGLESKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsRequirementsOpenGLESKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minApiVersionSupported));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxApiVersionSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsBindingVulkanKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsBindingVulkanKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->instance));
    value->instance = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->physicalDevice));
    value->physicalDevice = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->device));
    value->device = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageVulkanKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainImageVulkanKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsRequirementsVulkanKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsRequirementsVulkanKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minApiVersionSupported));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxApiVersionSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsBindingD3D11KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsBindingD3D11KHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->device));
    value->device = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageD3D11KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainImageD3D11KHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->texture));
    value->texture = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsRequirementsD3D11KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsRequirementsD3D11KHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeLUIDValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->adapterLuid));
    bytes_read += ValueDecoder::DecodeD3D_FEATURE_LEVELValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minFeatureLevel));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsBindingD3D12KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsBindingD3D12KHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->device));
    value->device = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->queue));
    value->queue = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageD3D12KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainImageD3D12KHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->texture));
    value->texture = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsRequirementsD3D12KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsRequirementsD3D12KHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeLUIDValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->adapterLuid));
    bytes_read += ValueDecoder::DecodeD3D_FEATURE_LEVELValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minFeatureLevel));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVisibilityMaskKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVisibilityMaskKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCountOutput));
    wrapper->vertices = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector2f>>();
    bytes_read += wrapper->vertices->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertices = wrapper->vertices->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCountOutput));
    bytes_read += wrapper->indices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->indices = wrapper->indices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataVisibilityMaskChangedKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataVisibilityMaskChangedKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->session));
    value->session = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewConfigurationType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerColorScaleBiasKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerColorScaleBiasKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->colorScale = DecodeAllocator::Allocate<Decoded_XrColor4f>();
    wrapper->colorScale->decoded_value = &(value->colorScale);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->colorScale);
    wrapper->colorBias = DecodeAllocator::Allocate<Decoded_XrColor4f>();
    wrapper->colorBias->decoded_value = &(value->colorBias);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->colorBias);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrLoaderInitInfoBaseHeaderKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrLoaderInitInfoBaseHeaderKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrLoaderInitInfoAndroidKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrLoaderInitInfoAndroidKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->applicationVM));
    value->applicationVM = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->applicationContext));
    value->applicationContext = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVulkanGraphicsDeviceGetInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVulkanGraphicsDeviceGetInfoKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->systemId));
    value->systemId = XR_NULL_SYSTEM_ID;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->vulkanInstance));
    value->vulkanInstance = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerEquirect2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerEquirect2KHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerFlags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->eyeVisibility));
    wrapper->subImage = DecodeAllocator::Allocate<Decoded_XrSwapchainSubImage>();
    wrapper->subImage->decoded_value = &(value->subImage);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->subImage);
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->radius));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->centralHorizontalAngle));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->upperVerticalAngle));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->lowerVerticalAngle));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBindingModificationBaseHeaderKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrBindingModificationBaseHeaderKHR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataPerfSettingsEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataPerfSettingsEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->domain));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->subDomain));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->fromLevel));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->toLevel));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrDebugUtilsObjectNameInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrDebugUtilsObjectNameInfoEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectType));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectHandle));
    bytes_read += wrapper->objectName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->objectName = wrapper->objectName.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrDebugUtilsLabelEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrDebugUtilsLabelEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += wrapper->labelName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->labelName = wrapper->labelName.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrDebugUtilsMessengerCallbackDataEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrDebugUtilsMessengerCallbackDataEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += wrapper->messageId.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->messageId = wrapper->messageId.GetPointer();
    bytes_read += wrapper->functionName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->functionName = wrapper->functionName.GetPointer();
    bytes_read += wrapper->message.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->message = wrapper->message.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectCount));
    wrapper->objects = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrDebugUtilsObjectNameInfoEXT>>();
    bytes_read += wrapper->objects->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->objects = wrapper->objects->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sessionLabelCount));
    wrapper->sessionLabels = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>>();
    bytes_read += wrapper->sessionLabels->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->sessionLabels = wrapper->sessionLabels->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrDebugUtilsMessengerCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrDebugUtilsMessengerCreateInfoEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->messageSeverities));
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->messageTypes));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->userCallback));
    value->userCallback = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->userData));
    value->userData = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemEyeGazeInteractionPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemEyeGazeInteractionPropertiesEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsEyeGazeInteraction));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEyeGazeSampleTimeEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEyeGazeSampleTimeEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSessionCreateInfoOverlayEXTX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSessionCreateInfoOverlayEXTX* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->createFlags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sessionLayersPlacement));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataMainSessionVisibilityChangedEXTX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataMainSessionVisibilityChangedEXTX* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->visible));
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialAnchorCreateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialAnchorCreateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialAnchorSpaceCreateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->anchor));
    value->anchor = XR_NULL_HANDLE;
    wrapper->poseInAnchorSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInAnchorSpace->decoded_value = &(value->poseInAnchorSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInAnchorSpace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerImageLayoutFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerImageLayoutFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerAlphaBlendFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerAlphaBlendFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcFactorColor));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstFactorColor));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcFactorAlpha));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstFactorAlpha));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrViewConfigurationDepthRangeEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrViewConfigurationDepthRangeEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->recommendedNearZ));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minNearZ));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->recommendedFarZ));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxFarZ));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGraphicsBindingEGLMNDX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGraphicsBindingEGLMNDX* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->getProcAddress));
    value->getProcAddress = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->display));
    value->display = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->config));
    value->config = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->context));
    value->context = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialGraphNodeSpaceCreateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->nodeType));
    wrapper->nodeId.SetExternalMemory(value->nodeId, XR_GUID_SIZE_MSFT);
    bytes_read += wrapper->nodeId.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialGraphStaticNodeBindingCreateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->poseInSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInSpace->decoded_value = &(value->poseInSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInSpace);
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialGraphNodeBindingPropertiesMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialGraphNodeBindingPropertiesMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->nodeId.SetExternalMemory(value->nodeId, XR_GUID_SIZE_MSFT);
    bytes_read += wrapper->nodeId.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->poseInNodeSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInNodeSpace->decoded_value = &(value->poseInNodeSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInNodeSpace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemHandTrackingPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemHandTrackingPropertiesEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsHandTracking));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandTrackerCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandTrackerCreateInfoEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->hand));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handJointSet));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandJointsLocateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandJointsLocateInfoEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->baseSpace));
    value->baseSpace = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandJointLocationEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandJointLocationEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->locationFlags));
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->radius));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandJointVelocityEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandJointVelocityEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->velocityFlags));
    wrapper->linearVelocity = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->linearVelocity->decoded_value = &(value->linearVelocity);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->linearVelocity);
    wrapper->angularVelocity = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->angularVelocity->decoded_value = &(value->angularVelocity);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->angularVelocity);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandJointLocationsEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandJointLocationsEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isActive));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->jointCount));
    wrapper->jointLocations = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrHandJointLocationEXT>>();
    bytes_read += wrapper->jointLocations->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->jointLocations = wrapper->jointLocations->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandJointVelocitiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandJointVelocitiesEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->jointCount));
    wrapper->jointVelocities = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrHandJointVelocityEXT>>();
    bytes_read += wrapper->jointVelocities->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->jointVelocities = wrapper->jointVelocities->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemHandTrackingMeshPropertiesMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemHandTrackingMeshPropertiesMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsHandTrackingMesh));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxHandMeshIndexCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxHandMeshVertexCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandMeshSpaceCreateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandMeshSpaceCreateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handPoseType));
    wrapper->poseInHandMeshSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInHandMeshSpace->decoded_value = &(value->poseInHandMeshSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInHandMeshSpace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandMeshUpdateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandMeshUpdateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handPoseType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandMeshIndexBufferMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandMeshIndexBufferMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexBufferKey));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCountOutput));
    bytes_read += wrapper->indices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->indices = wrapper->indices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandMeshVertexMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandMeshVertexMSFT* value = wrapper->decoded_value;

    wrapper->position = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->position->decoded_value = &(value->position);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->position);
    wrapper->normal = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->normal->decoded_value = &(value->normal);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->normal);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandMeshVertexBufferMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandMeshVertexBufferMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexUpdateTime));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCountOutput));
    wrapper->vertices = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrHandMeshVertexMSFT>>();
    bytes_read += wrapper->vertices->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertices = wrapper->vertices->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandMeshMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandMeshMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isActive));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexBufferChanged));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexBufferChanged));
    wrapper->indexBuffer = DecodeAllocator::Allocate<Decoded_XrHandMeshIndexBufferMSFT>();
    wrapper->indexBuffer->decoded_value = &(value->indexBuffer);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->indexBuffer);
    wrapper->vertexBuffer = DecodeAllocator::Allocate<Decoded_XrHandMeshVertexBufferMSFT>();
    wrapper->vertexBuffer->decoded_value = &(value->vertexBuffer);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->vertexBuffer);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandPoseTypeInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandPoseTypeInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handPoseType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSecondaryViewConfigurationSessionBeginInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewConfigurationCount));
    bytes_read += wrapper->enabledViewConfigurationTypes.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->enabledViewConfigurationTypes = wrapper->enabledViewConfigurationTypes.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationStateMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSecondaryViewConfigurationStateMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewConfigurationType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->active));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationFrameStateMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSecondaryViewConfigurationFrameStateMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewConfigurationCount));
    wrapper->viewConfigurationStates = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSecondaryViewConfigurationStateMSFT>>();
    bytes_read += wrapper->viewConfigurationStates->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->viewConfigurationStates = wrapper->viewConfigurationStates->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSecondaryViewConfigurationFrameEndInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewConfigurationCount));
    wrapper->viewConfigurationLayersInfo = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSecondaryViewConfigurationLayerInfoMSFT>>();
    bytes_read += wrapper->viewConfigurationLayersInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->viewConfigurationLayersInfo = wrapper->viewConfigurationLayersInfo->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewConfigurationType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrControllerModelKeyStateMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrControllerModelKeyStateMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->modelKey));
    value->modelKey = XR_NULL_CONTROLLER_MODEL_KEY_MSFT;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrControllerModelNodePropertiesMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrControllerModelNodePropertiesMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->parentNodeName.SetExternalMemory(value->parentNodeName, XR_MAX_CONTROLLER_MODEL_NODE_NAME_SIZE_MSFT);
    bytes_read += wrapper->parentNodeName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->nodeName.SetExternalMemory(value->nodeName, XR_MAX_CONTROLLER_MODEL_NODE_NAME_SIZE_MSFT);
    bytes_read += wrapper->nodeName.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrControllerModelPropertiesMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrControllerModelPropertiesMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->nodeCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->nodeCountOutput));
    wrapper->nodeProperties = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrControllerModelNodePropertiesMSFT>>();
    bytes_read += wrapper->nodeProperties->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->nodeProperties = wrapper->nodeProperties->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrControllerModelNodeStateMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrControllerModelNodeStateMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->nodePose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->nodePose->decoded_value = &(value->nodePose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->nodePose);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrControllerModelStateMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrControllerModelStateMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->nodeCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->nodeCountOutput));
    wrapper->nodeStates = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrControllerModelNodeStateMSFT>>();
    bytes_read += wrapper->nodeStates->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->nodeStates = wrapper->nodeStates->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrViewConfigurationViewFovEPIC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrViewConfigurationViewFovEPIC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->recommendedFov = DecodeAllocator::Allocate<Decoded_XrFovf>();
    wrapper->recommendedFov->decoded_value = &(value->recommendedFov);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->recommendedFov);
    wrapper->maxMutableFov = DecodeAllocator::Allocate<Decoded_XrFovf>();
    wrapper->maxMutableFov->decoded_value = &(value->maxMutableFov);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxMutableFov);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHolographicWindowAttachmentMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHolographicWindowAttachmentMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->holographicSpace));
    value->holographicSpace = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->coreWindow));
    value->coreWindow = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerReprojectionInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerReprojectionInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->reprojectionMode));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerReprojectionPlaneOverrideMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->position = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->position->decoded_value = &(value->position);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->position);
    wrapper->normal = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->normal->decoded_value = &(value->normal);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->normal);
    wrapper->velocity = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->velocity->decoded_value = &(value->velocity);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->velocity);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrAndroidSurfaceSwapchainCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrAndroidSurfaceSwapchainCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->createFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainStateBaseHeaderFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainStateBaseHeaderFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerSecureContentFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerSecureContentFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBodyJointLocationFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrBodyJointLocationFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->locationFlags));
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemBodyTrackingPropertiesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemBodyTrackingPropertiesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsBodyTracking));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBodyTrackerCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrBodyTrackerCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->bodyJointSet));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBodySkeletonJointFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrBodySkeletonJointFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->joint));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->parentJoint));
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBodySkeletonFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrBodySkeletonFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->jointCount));
    wrapper->joints = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrBodySkeletonJointFB>>();
    bytes_read += wrapper->joints->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->joints = wrapper->joints->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBodyJointsLocateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrBodyJointsLocateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->baseSpace));
    value->baseSpace = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBodyJointLocationsFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrBodyJointLocationsFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isActive));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->confidence));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->jointCount));
    wrapper->jointLocations = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrBodyJointLocationFB>>();
    bytes_read += wrapper->jointLocations->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->jointLocations = wrapper->jointLocations->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->skeletonChangedCount));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrInteractionProfileDpadBindingEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrInteractionProfileDpadBindingEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->binding));
    value->binding = XR_NULL_PATH;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->actionSet));
    value->actionSet = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->forceThreshold));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->forceThresholdReleased));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->centerRegion));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->wedgeAngle));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isSticky));
    wrapper->onHaptic = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrHapticBaseHeader>>();
    bytes_read += wrapper->onHaptic->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->onHaptic = wrapper->onHaptic->GetPointer();
    wrapper->offHaptic = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrHapticBaseHeader>>();
    bytes_read += wrapper->offHaptic->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->offHaptic = wrapper->offHaptic->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrInteractionProfileAnalogThresholdVALVE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrInteractionProfileAnalogThresholdVALVE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->action));
    value->action = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->binding));
    value->binding = XR_NULL_PATH;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->onThreshold));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offThreshold));
    wrapper->onHaptic = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrHapticBaseHeader>>();
    bytes_read += wrapper->onHaptic->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->onHaptic = wrapper->onHaptic->GetPointer();
    wrapper->offHaptic = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrHapticBaseHeader>>();
    bytes_read += wrapper->offHaptic->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->offHaptic = wrapper->offHaptic->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandJointsMotionRangeInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandJointsMotionRangeInfoEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handJointsMotionRange));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrUuidMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrUuidMSFT* value = wrapper->decoded_value;

    wrapper->bytes.SetExternalMemory(value->bytes, 16);
    bytes_read += wrapper->bytes.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneObserverCreateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneObserverCreateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneCreateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneCreateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneSphereBoundMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneSphereBoundMSFT* value = wrapper->decoded_value;

    wrapper->center = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->center->decoded_value = &(value->center);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->center);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->radius));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneOrientedBoxBoundMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneOrientedBoxBoundMSFT* value = wrapper->decoded_value;

    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    wrapper->extents = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->extents->decoded_value = &(value->extents);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extents);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneFrustumBoundMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneFrustumBoundMSFT* value = wrapper->decoded_value;

    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    wrapper->fov = DecodeAllocator::Allocate<Decoded_XrFovf>();
    wrapper->fov->decoded_value = &(value->fov);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->fov);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->farDistance));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneBoundsMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneBoundsMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sphereCount));
    wrapper->spheres = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSceneSphereBoundMSFT>>();
    bytes_read += wrapper->spheres->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->spheres = wrapper->spheres->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->boxCount));
    wrapper->boxes = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSceneOrientedBoxBoundMSFT>>();
    bytes_read += wrapper->boxes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->boxes = wrapper->boxes->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->frustumCount));
    wrapper->frustums = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSceneFrustumBoundMSFT>>();
    bytes_read += wrapper->frustums->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->frustums = wrapper->frustums->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrNewSceneComputeInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrNewSceneComputeInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->requestedFeatureCount));
    bytes_read += wrapper->requestedFeatures.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->requestedFeatures = wrapper->requestedFeatures.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->consistency));
    wrapper->bounds = DecodeAllocator::Allocate<Decoded_XrSceneBoundsMSFT>();
    wrapper->bounds->decoded_value = &(value->bounds);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->bounds);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVisualMeshComputeLodInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVisualMeshComputeLodInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->lod));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneComponentMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneComponentMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->componentType));
    wrapper->id = DecodeAllocator::Allocate<Decoded_XrUuidMSFT>();
    wrapper->id->decoded_value = &(value->id);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->id);
    wrapper->parentId = DecodeAllocator::Allocate<Decoded_XrUuidMSFT>();
    wrapper->parentId->decoded_value = &(value->parentId);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->parentId);
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->updateTime));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneComponentsMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneComponentsMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->componentCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->componentCountOutput));
    wrapper->components = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSceneComponentMSFT>>();
    bytes_read += wrapper->components->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->components = wrapper->components->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneComponentsGetInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneComponentsGetInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->componentType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneComponentLocationMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneComponentLocationMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneComponentLocationsMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneComponentLocationsMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->locationCount));
    wrapper->locations = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSceneComponentLocationMSFT>>();
    bytes_read += wrapper->locations->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->locations = wrapper->locations->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneComponentsLocateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneComponentsLocateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->baseSpace));
    value->baseSpace = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->componentIdCount));
    wrapper->componentIds = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrUuidMSFT>>();
    bytes_read += wrapper->componentIds->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->componentIds = wrapper->componentIds->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneObjectMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneObjectMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneObjectsMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneObjectsMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sceneObjectCount));
    wrapper->sceneObjects = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSceneObjectMSFT>>();
    bytes_read += wrapper->sceneObjects->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->sceneObjects = wrapper->sceneObjects->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneComponentParentFilterInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneComponentParentFilterInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->parentId = DecodeAllocator::Allocate<Decoded_XrUuidMSFT>();
    wrapper->parentId->decoded_value = &(value->parentId);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->parentId);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneObjectTypesFilterInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneObjectTypesFilterInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectTypeCount));
    bytes_read += wrapper->objectTypes.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->objectTypes = wrapper->objectTypes.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrScenePlaneMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrScenePlaneMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->alignment));
    wrapper->size = DecodeAllocator::Allocate<Decoded_XrExtent2Df>();
    wrapper->size->decoded_value = &(value->size);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->size);
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->meshBufferId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsIndicesUint16));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrScenePlanesMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrScenePlanesMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->scenePlaneCount));
    wrapper->scenePlanes = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrScenePlaneMSFT>>();
    bytes_read += wrapper->scenePlanes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->scenePlanes = wrapper->scenePlanes->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrScenePlaneAlignmentFilterInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrScenePlaneAlignmentFilterInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->alignmentCount));
    bytes_read += wrapper->alignments.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->alignments = wrapper->alignments.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMeshMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMeshMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->meshBufferId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsIndicesUint16));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMeshesMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMeshesMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sceneMeshCount));
    wrapper->sceneMeshes = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSceneMeshMSFT>>();
    bytes_read += wrapper->sceneMeshes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->sceneMeshes = wrapper->sceneMeshes->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMeshBuffersGetInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMeshBuffersGetInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->meshBufferId));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMeshBuffersMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMeshBuffersMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMeshVertexBufferMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMeshVertexBufferMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCountOutput));
    wrapper->vertices = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector3f>>();
    bytes_read += wrapper->vertices->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertices = wrapper->vertices->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMeshIndicesUint32MSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMeshIndicesUint32MSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCountOutput));
    bytes_read += wrapper->indices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->indices = wrapper->indices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMeshIndicesUint16MSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMeshIndicesUint16MSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCountOutput));
    bytes_read += wrapper->indices.DecodeUInt16((buffer + bytes_read), (buffer_size - bytes_read));
    value->indices = wrapper->indices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSerializedSceneFragmentDataGetInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSerializedSceneFragmentDataGetInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->sceneFragmentId = DecodeAllocator::Allocate<Decoded_XrUuidMSFT>();
    wrapper->sceneFragmentId->decoded_value = &(value->sceneFragmentId);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->sceneFragmentId);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrDeserializeSceneFragmentMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrDeserializeSceneFragmentMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferSize));
    bytes_read += wrapper->buffer.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    value->buffer = wrapper->buffer.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneDeserializeInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneDeserializeInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fragmentCount));
    wrapper->fragments = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrDeserializeSceneFragmentMSFT>>();
    bytes_read += wrapper->fragments->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->fragments = wrapper->fragments->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataDisplayRefreshRateChangedFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataDisplayRefreshRateChangedFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->fromDisplayRefreshRate));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->toDisplayRefreshRate));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrViveTrackerPathsHTCX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrViveTrackerPathsHTCX* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->persistentPath));
    value->persistentPath = XR_NULL_PATH;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->rolePath));
    value->rolePath = XR_NULL_PATH;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataViveTrackerConnectedHTCX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataViveTrackerConnectedHTCX* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->paths = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrViveTrackerPathsHTCX>>();
    bytes_read += wrapper->paths->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->paths = wrapper->paths->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemFacialTrackingPropertiesHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemFacialTrackingPropertiesHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportEyeFacialTracking));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportLipFacialTracking));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFacialExpressionsHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFacialExpressionsHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isActive));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleTime));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->expressionCount));
    bytes_read += wrapper->expressionWeightings.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->expressionWeightings = wrapper->expressionWeightings.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFacialTrackerCreateInfoHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFacialTrackerCreateInfoHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->facialTrackingType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemColorSpacePropertiesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemColorSpacePropertiesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorSpace));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVector4sFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVector4sFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->z));
    bytes_read += ValueDecoder::DecodeInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->w));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandTrackingMeshFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandTrackingMeshFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->jointCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->jointCountOutput));
    wrapper->jointBindPoses = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrPosef>>();
    bytes_read += wrapper->jointBindPoses->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->jointBindPoses = wrapper->jointBindPoses->GetPointer();
    bytes_read += wrapper->jointRadii.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->jointRadii = wrapper->jointRadii.GetPointer();
    bytes_read += wrapper->jointParents.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->jointParents = wrapper->jointParents.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCountOutput));
    wrapper->vertexPositions = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector3f>>();
    bytes_read += wrapper->vertexPositions->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertexPositions = wrapper->vertexPositions->GetPointer();
    wrapper->vertexNormals = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector3f>>();
    bytes_read += wrapper->vertexNormals->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertexNormals = wrapper->vertexNormals->GetPointer();
    wrapper->vertexUVs = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector2f>>();
    bytes_read += wrapper->vertexUVs->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertexUVs = wrapper->vertexUVs->GetPointer();
    wrapper->vertexBlendIndices = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector4sFB>>();
    bytes_read += wrapper->vertexBlendIndices->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertexBlendIndices = wrapper->vertexBlendIndices->GetPointer();
    wrapper->vertexBlendWeights = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector4f>>();
    bytes_read += wrapper->vertexBlendWeights->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertexBlendWeights = wrapper->vertexBlendWeights->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCountOutput));
    bytes_read += wrapper->indices.DecodeInt16((buffer + bytes_read), (buffer_size - bytes_read));
    value->indices = wrapper->indices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandTrackingScaleFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandTrackingScaleFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sensorOutput));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->currentOutput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->overrideHandScale));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->overrideValueInput));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandTrackingAimStateFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandTrackingAimStateFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->status));
    wrapper->aimPose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->aimPose->decoded_value = &(value->aimPose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->aimPose);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pinchStrengthIndex));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pinchStrengthMiddle));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pinchStrengthRing));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pinchStrengthLittle));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandCapsuleFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandCapsuleFB* value = wrapper->decoded_value;

    wrapper->points = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector3f>>();
    wrapper->points->SetExternalMemory(value->points, XR_HAND_TRACKING_CAPSULE_POINT_COUNT_FB);
    bytes_read += wrapper->points->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->radius));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->joint));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandTrackingCapsulesStateFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandTrackingCapsulesStateFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->capsules = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrHandCapsuleFB>>();
    wrapper->capsules->SetExternalMemory(value->capsules, XR_HAND_TRACKING_CAPSULE_COUNT_FB);
    bytes_read += wrapper->capsules->Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemSpatialEntityPropertiesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemSpatialEntityPropertiesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsSpatialEntity));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialAnchorCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialAnchorCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->poseInSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInSpace->decoded_value = &(value->poseInSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInSpace);
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceComponentStatusSetInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceComponentStatusSetInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->componentType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabled));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->timeout));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceComponentStatusFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceComponentStatusFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabled));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->changePending));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrUuidEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrUuidEXT* value = wrapper->decoded_value;

    wrapper->data.SetExternalMemory(value->data, XR_UUID_SIZE_EXT);
    bytes_read += wrapper->data.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataSpatialAnchorCreateCompleteFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataSpatialAnchorCreateCompleteFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->requestId));
    value->requestId = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->result));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->uuid = DecodeAllocator::Allocate<Decoded_XrUuidEXT>();
    wrapper->uuid->decoded_value = &(value->uuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->uuid);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataSpaceSetStatusCompleteFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataSpaceSetStatusCompleteFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->requestId));
    value->requestId = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->result));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->uuid = DecodeAllocator::Allocate<Decoded_XrUuidEXT>();
    wrapper->uuid->decoded_value = &(value->uuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->uuid);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->componentType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabled));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFoveationProfileCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFoveationProfileCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainCreateInfoFoveationFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainCreateInfoFoveationFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainStateFoveationFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainStateFoveationFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->profile));
    value->profile = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFoveationLevelProfileCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFoveationLevelProfileCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->level));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->verticalOffset));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dynamic));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemKeyboardTrackingPropertiesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemKeyboardTrackingPropertiesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsKeyboardTracking));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrKeyboardTrackingDescriptionFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrKeyboardTrackingDescriptionFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->trackedKeyboardId));
    wrapper->size = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->size->decoded_value = &(value->size);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->size);
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    wrapper->name.SetExternalMemory(value->name, XR_MAX_KEYBOARD_TRACKING_NAME_SIZE_FB);
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrKeyboardSpaceCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrKeyboardSpaceCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->trackedKeyboardId));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrKeyboardTrackingQueryFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrKeyboardTrackingQueryFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrTriangleMeshCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrTriangleMeshCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->windingOrder));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCount));
    wrapper->vertexBuffer = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector3f>>();
    bytes_read += wrapper->vertexBuffer->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertexBuffer = wrapper->vertexBuffer->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->triangleCount));
    bytes_read += wrapper->indexBuffer.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->indexBuffer = wrapper->indexBuffer.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemPassthroughPropertiesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemPassthroughPropertiesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsPassthrough));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemPassthroughProperties2FB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemPassthroughProperties2FB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->capabilities));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughLayerCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughLayerCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->passthrough));
    value->passthrough = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->purpose));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerPassthroughFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerPassthroughFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->layerHandle));
    value->layerHandle = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGeometryInstanceCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGeometryInstanceCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->layer));
    value->layer = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->mesh));
    value->mesh = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->baseSpace));
    value->baseSpace = XR_NULL_HANDLE;
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    wrapper->scale = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->scale->decoded_value = &(value->scale);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->scale);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGeometryInstanceTransformFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGeometryInstanceTransformFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->baseSpace));
    value->baseSpace = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    wrapper->scale = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->scale->decoded_value = &(value->scale);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->scale);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughStyleFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughStyleFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->textureOpacityFactor));
    wrapper->edgeColor = DecodeAllocator::Allocate<Decoded_XrColor4f>();
    wrapper->edgeColor->decoded_value = &(value->edgeColor);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->edgeColor);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughColorMapMonoToRgbaFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughColorMapMonoToRgbaFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->textureColorMap = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrColor4f>>();
    wrapper->textureColorMap->SetExternalMemory(value->textureColorMap, XR_PASSTHROUGH_COLOR_MAP_MONO_SIZE_FB);
    bytes_read += wrapper->textureColorMap->Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughColorMapMonoToMonoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughColorMapMonoToMonoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->textureColorMap.SetExternalMemory(value->textureColorMap, XR_PASSTHROUGH_COLOR_MAP_MONO_SIZE_FB);
    bytes_read += wrapper->textureColorMap.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughBrightnessContrastSaturationFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughBrightnessContrastSaturationFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->brightness));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->contrast));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->saturation));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataPassthroughStateChangedFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataPassthroughStateChangedFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRenderModelPathInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRenderModelPathInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->path));
    value->path = XR_NULL_PATH;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRenderModelPropertiesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRenderModelPropertiesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vendorId));
    wrapper->modelName.SetExternalMemory(value->modelName, XR_MAX_RENDER_MODEL_NAME_SIZE_FB);
    bytes_read += wrapper->modelName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->modelKey));
    value->modelKey = XR_NULL_RENDER_MODEL_KEY_FB;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->modelVersion));
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRenderModelBufferFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRenderModelBufferFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferCountOutput));
    bytes_read += wrapper->buffer.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    value->buffer = wrapper->buffer.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRenderModelLoadInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRenderModelLoadInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->modelKey));
    value->modelKey = XR_NULL_RENDER_MODEL_KEY_FB;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemRenderModelPropertiesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemRenderModelPropertiesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsRenderModelLoading));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRenderModelCapabilitiesRequestFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRenderModelCapabilitiesRequestFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrViewLocateFoveatedRenderingVARJO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrViewLocateFoveatedRenderingVARJO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->foveatedRenderingActive));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFoveatedViewConfigurationViewVARJO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFoveatedViewConfigurationViewVARJO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->foveatedRenderingActive));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemFoveatedRenderingPropertiesVARJO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemFoveatedRenderingPropertiesVARJO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsFoveatedRendering));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerDepthTestVARJO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerDepthTestVARJO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthTestRangeNearZ));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthTestRangeFarZ));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemMarkerTrackingPropertiesVARJO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemMarkerTrackingPropertiesVARJO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsMarkerTracking));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataMarkerTrackingUpdateVARJO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataMarkerTrackingUpdateVARJO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->markerId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isActive));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isPredicted));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrMarkerSpaceCreateInfoVARJO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrMarkerSpaceCreateInfoVARJO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->markerId));
    wrapper->poseInMarkerSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInMarkerSpace->decoded_value = &(value->poseInMarkerSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInMarkerSpace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFrameEndInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFrameEndInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->focusDistance));
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrGlobalDimmerFrameEndInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrGlobalDimmerFrameEndInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dimmerValue));
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCoordinateSpaceCreateInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCoordinateSpaceCreateInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeMLCoordinateFrameUIDValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->cfuid));
    wrapper->poseInCoordinateSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInCoordinateSpace->decoded_value = &(value->poseInCoordinateSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInCoordinateSpace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemMarkerUnderstandingPropertiesML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemMarkerUnderstandingPropertiesML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsMarkerUnderstanding));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrMarkerDetectorCreateInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrMarkerDetectorCreateInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->profile));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->markerType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrMarkerDetectorArucoInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrMarkerDetectorArucoInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->arucoDict));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrMarkerDetectorSizeInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrMarkerDetectorSizeInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->markerLength));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrMarkerDetectorAprilTagInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrMarkerDetectorAprilTagInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aprilTagDict));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrMarkerDetectorCustomProfileInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrMarkerDetectorCustomProfileInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->fpsHint));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->resolutionHint));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->cameraHint));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->cornerRefineMethod));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->useEdgeRefinement));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->fullAnalysisIntervalHint));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrMarkerDetectorSnapshotInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrMarkerDetectorSnapshotInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrMarkerDetectorStateML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrMarkerDetectorStateML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->state));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrMarkerSpaceCreateInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrMarkerSpaceCreateInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->markerDetector));
    value->markerDetector = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->marker));
    value->marker = 0;
    wrapper->poseInMarkerSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInMarkerSpace->decoded_value = &(value->poseInMarkerSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInMarkerSpace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrLocalizationMapML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrLocalizationMapML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->name.SetExternalMemory(value->name, XR_MAX_LOCALIZATION_MAP_NAME_LENGTH_ML);
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->mapUuid = DecodeAllocator::Allocate<Decoded_XrUuidEXT>();
    wrapper->mapUuid->decoded_value = &(value->mapUuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->mapUuid);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->mapType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataLocalizationChangedML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataLocalizationChangedML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->session));
    value->session = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->state));
    wrapper->map = DecodeAllocator::Allocate<Decoded_XrLocalizationMapML>();
    wrapper->map->decoded_value = &(value->map);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->map);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->confidence));
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->errorFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrLocalizationMapQueryInfoBaseHeaderML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrLocalizationMapQueryInfoBaseHeaderML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrMapLocalizationRequestInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrMapLocalizationRequestInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->mapUuid = DecodeAllocator::Allocate<Decoded_XrUuidEXT>();
    wrapper->mapUuid->decoded_value = &(value->mapUuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->mapUuid);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrLocalizationMapImportInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrLocalizationMapImportInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));
    bytes_read += wrapper->data.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->data = wrapper->data.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrLocalizationEnableEventsInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrLocalizationEnableEventsInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabled));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialAnchorPersistenceNameMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialAnchorPersistenceNameMSFT* value = wrapper->decoded_value;

    wrapper->name.SetExternalMemory(value->name, XR_MAX_SPATIAL_ANCHOR_NAME_SIZE_MSFT);
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialAnchorPersistenceInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialAnchorPersistenceInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->spatialAnchorPersistenceName = DecodeAllocator::Allocate<Decoded_XrSpatialAnchorPersistenceNameMSFT>();
    wrapper->spatialAnchorPersistenceName->decoded_value = &(value->spatialAnchorPersistenceName);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->spatialAnchorPersistenceName);
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->spatialAnchor));
    value->spatialAnchor = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->spatialAnchorStore));
    value->spatialAnchorStore = XR_NULL_HANDLE;
    wrapper->spatialAnchorPersistenceName = DecodeAllocator::Allocate<Decoded_XrSpatialAnchorPersistenceNameMSFT>();
    wrapper->spatialAnchorPersistenceName->decoded_value = &(value->spatialAnchorPersistenceName);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->spatialAnchorPersistenceName);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMarkerMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMarkerMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->markerType));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->lastSeenTime));
    wrapper->center = DecodeAllocator::Allocate<Decoded_XrOffset2Df>();
    wrapper->center->decoded_value = &(value->center);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->center);
    wrapper->size = DecodeAllocator::Allocate<Decoded_XrExtent2Df>();
    wrapper->size->decoded_value = &(value->size);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->size);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMarkersMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMarkersMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sceneMarkerCapacityInput));
    wrapper->sceneMarkers = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSceneMarkerMSFT>>();
    bytes_read += wrapper->sceneMarkers->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->sceneMarkers = wrapper->sceneMarkers->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMarkerTypeFilterMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMarkerTypeFilterMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->markerTypeCount));
    bytes_read += wrapper->markerTypes.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->markerTypes = wrapper->markerTypes.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMarkerQRCodeMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMarkerQRCodeMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->symbolType));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->version));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneMarkerQRCodesMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneMarkerQRCodesMSFT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->qrCodeCapacityInput));
    wrapper->qrCodes = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSceneMarkerQRCodeMSFT>>();
    bytes_read += wrapper->qrCodes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->qrCodes = wrapper->qrCodes->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceQueryInfoBaseHeaderFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceQueryInfoBaseHeaderFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceFilterInfoBaseHeaderFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceFilterInfoBaseHeaderFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceQueryInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceQueryInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->queryAction));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxResultCount));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->timeout));
    wrapper->filter = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSpaceFilterInfoBaseHeaderFB>>();
    bytes_read += wrapper->filter->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->filter = wrapper->filter->GetPointer();
    wrapper->excludeFilter = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSpaceFilterInfoBaseHeaderFB>>();
    bytes_read += wrapper->excludeFilter->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->excludeFilter = wrapper->excludeFilter->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceStorageLocationFilterInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceStorageLocationFilterInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->location));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceUuidFilterInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceUuidFilterInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->uuidCount));
    wrapper->uuids = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrUuidEXT>>();
    bytes_read += wrapper->uuids->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->uuids = wrapper->uuids->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceComponentFilterInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceComponentFilterInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->componentType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceQueryResultFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceQueryResultFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->uuid = DecodeAllocator::Allocate<Decoded_XrUuidEXT>();
    wrapper->uuid->decoded_value = &(value->uuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->uuid);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceQueryResultsFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceQueryResultsFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->resultCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->resultCountOutput));
    wrapper->results = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSpaceQueryResultFB>>();
    bytes_read += wrapper->results->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->results = wrapper->results->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataSpaceQueryResultsAvailableFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataSpaceQueryResultsAvailableFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->requestId));
    value->requestId = 0;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataSpaceQueryCompleteFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataSpaceQueryCompleteFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->requestId));
    value->requestId = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->result));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceSaveInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceSaveInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->location));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->persistenceMode));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceEraseInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceEraseInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->location));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataSpaceSaveCompleteFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataSpaceSaveCompleteFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->requestId));
    value->requestId = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->result));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->uuid = DecodeAllocator::Allocate<Decoded_XrUuidEXT>();
    wrapper->uuid->decoded_value = &(value->uuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->uuid);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->location));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataSpaceEraseCompleteFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataSpaceEraseCompleteFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->requestId));
    value->requestId = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->result));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->uuid = DecodeAllocator::Allocate<Decoded_XrUuidEXT>();
    wrapper->uuid->decoded_value = &(value->uuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->uuid);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->location));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageFoveationVulkanFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainImageFoveationVulkanFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainStateAndroidSurfaceDimensionsFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainStateSamplerOpenGLESFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainStateSamplerOpenGLESFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minFilter));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->magFilter));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->wrapModeS));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->wrapModeT));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swizzleRed));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swizzleGreen));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swizzleBlue));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swizzleAlpha));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxAnisotropy));
    wrapper->borderColor = DecodeAllocator::Allocate<Decoded_XrColor4f>();
    wrapper->borderColor->decoded_value = &(value->borderColor);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->borderColor);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainStateSamplerVulkanFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSwapchainStateSamplerVulkanFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minFilter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->magFilter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->mipmapMode));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->wrapModeS));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->wrapModeT));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->swizzleRed));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->swizzleGreen));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->swizzleBlue));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->swizzleAlpha));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxAnisotropy));
    wrapper->borderColor = DecodeAllocator::Allocate<Decoded_XrColor4f>();
    wrapper->borderColor->decoded_value = &(value->borderColor);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->borderColor);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceShareInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceShareInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->spaceCount));
    bytes_read += wrapper->spaces.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->spaces = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->userCount));
    bytes_read += wrapper->users.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->users = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataSpaceShareCompleteFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataSpaceShareCompleteFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->requestId));
    value->requestId = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->result));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerSpaceWarpInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerSpaceWarpInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerFlags));
    wrapper->motionVectorSubImage = DecodeAllocator::Allocate<Decoded_XrSwapchainSubImage>();
    wrapper->motionVectorSubImage->decoded_value = &(value->motionVectorSubImage);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->motionVectorSubImage);
    wrapper->appSpaceDeltaPose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->appSpaceDeltaPose->decoded_value = &(value->appSpaceDeltaPose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->appSpaceDeltaPose);
    wrapper->depthSubImage = DecodeAllocator::Allocate<Decoded_XrSwapchainSubImage>();
    wrapper->depthSubImage->decoded_value = &(value->depthSubImage);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->depthSubImage);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minDepth));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDepth));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->nearZ));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->farZ));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemSpaceWarpPropertiesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemSpaceWarpPropertiesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->recommendedMotionVectorImageRectWidth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->recommendedMotionVectorImageRectHeight));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHapticAmplitudeEnvelopeVibrationFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHapticAmplitudeEnvelopeVibrationFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->duration));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->amplitudeCount));
    bytes_read += wrapper->amplitudes.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->amplitudes = wrapper->amplitudes.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrExtent3DfFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrExtent3DfFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depth));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrOffset3DfFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrOffset3DfFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->z));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRect3DfFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRect3DfFB* value = wrapper->decoded_value;

    wrapper->offset = DecodeAllocator::Allocate<Decoded_XrOffset3DfFB>();
    wrapper->offset->decoded_value = &(value->offset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->offset);
    wrapper->extent = DecodeAllocator::Allocate<Decoded_XrExtent3DfFB>();
    wrapper->extent->decoded_value = &(value->extent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extent);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSemanticLabelsFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSemanticLabelsFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferCountOutput));
    bytes_read += wrapper->buffer.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->buffer = wrapper->buffer.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRoomLayoutFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRoomLayoutFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->floorUuid = DecodeAllocator::Allocate<Decoded_XrUuidEXT>();
    wrapper->floorUuid->decoded_value = &(value->floorUuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->floorUuid);
    wrapper->ceilingUuid = DecodeAllocator::Allocate<Decoded_XrUuidEXT>();
    wrapper->ceilingUuid->decoded_value = &(value->ceilingUuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->ceilingUuid);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->wallUuidCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->wallUuidCountOutput));
    wrapper->wallUuids = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrUuidEXT>>();
    bytes_read += wrapper->wallUuids->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->wallUuids = wrapper->wallUuids->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBoundary2DFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrBoundary2DFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCountOutput));
    wrapper->vertices = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector2f>>();
    bytes_read += wrapper->vertices->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertices = wrapper->vertices->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSemanticLabelsSupportInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSemanticLabelsSupportInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += wrapper->recognizedLabels.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->recognizedLabels = wrapper->recognizedLabels.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrDigitalLensControlALMALENCE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrDigitalLensControlALMALENCE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataSceneCaptureCompleteFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataSceneCaptureCompleteFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->requestId));
    value->requestId = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->result));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSceneCaptureRequestInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSceneCaptureRequestInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->requestByteCount));
    bytes_read += wrapper->request.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->request = wrapper->request.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceContainerFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceContainerFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->uuidCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->uuidCountOutput));
    wrapper->uuids = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrUuidEXT>>();
    bytes_read += wrapper->uuids->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->uuids = wrapper->uuids->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFoveationEyeTrackedProfileCreateInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFoveationEyeTrackedStateMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFoveationEyeTrackedStateMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->foveationCenter = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector2f>>();
    wrapper->foveationCenter->SetExternalMemory(value->foveationCenter, XR_FOVEATION_CENTER_SIZE_META);
    bytes_read += wrapper->foveationCenter->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemFoveationEyeTrackedPropertiesMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemFoveationEyeTrackedPropertiesMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsFoveationEyeTracked));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemFaceTrackingPropertiesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemFaceTrackingPropertiesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsFaceTracking));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFaceTrackerCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFaceTrackerCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->faceExpressionSet));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFaceExpressionInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFaceExpressionInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFaceExpressionStatusFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFaceExpressionStatusFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isValid));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isEyeFollowingBlendshapesValid));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFaceExpressionWeightsFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFaceExpressionWeightsFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->weightCount));
    bytes_read += wrapper->weights.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->weights = wrapper->weights.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->confidenceCount));
    bytes_read += wrapper->confidences.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->confidences = wrapper->confidences.GetPointer();
    wrapper->status = DecodeAllocator::Allocate<Decoded_XrFaceExpressionStatusFB>();
    wrapper->status->decoded_value = &(value->status);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->status);
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEyeGazeFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEyeGazeFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isValid));
    wrapper->gazePose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->gazePose->decoded_value = &(value->gazePose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->gazePose);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->gazeConfidence));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEyeTrackerCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEyeTrackerCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEyeGazesInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEyeGazesInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->baseSpace));
    value->baseSpace = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemEyeTrackingPropertiesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemEyeTrackingPropertiesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsEyeTracking));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEyeGazesFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEyeGazesFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->gaze = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrEyeGazeFB>>();
    wrapper->gaze->SetExternalMemory(value->gaze, XR_EYE_POSITION_COUNT_FB);
    bytes_read += wrapper->gaze->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughKeyboardHandsIntensityFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughKeyboardHandsIntensityFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->leftHandIntensity));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->rightHandIntensity));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerSettingsFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerSettingsFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHapticPcmVibrationFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHapticPcmVibrationFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferSize));
    bytes_read += wrapper->buffer.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->buffer = wrapper->buffer.GetPointer();
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleRate));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->append));
    bytes_read += wrapper->samplesConsumed.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->samplesConsumed = wrapper->samplesConsumed.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrDevicePcmSampleRateStateFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrDevicePcmSampleRateStateFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleRate));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerDepthTestFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerDepthTestFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthMask));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compareOp));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrLocalDimmingFrameEndInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrLocalDimmingFrameEndInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->localDimmingMode));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughPreferencesMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughPreferencesMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemVirtualKeyboardPropertiesMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemVirtualKeyboardPropertiesMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsVirtualKeyboard));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVirtualKeyboardCreateInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVirtualKeyboardCreateInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVirtualKeyboardSpaceCreateInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->locationType));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->poseInSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInSpace->decoded_value = &(value->poseInSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInSpace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVirtualKeyboardLocationInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVirtualKeyboardLocationInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->locationType));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->poseInSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInSpace->decoded_value = &(value->poseInSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInSpace);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->scale));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVirtualKeyboardModelVisibilitySetInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->visible));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVirtualKeyboardAnimationStateMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVirtualKeyboardAnimationStateMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->animationIndex));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->fraction));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVirtualKeyboardModelAnimationStatesMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVirtualKeyboardModelAnimationStatesMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stateCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stateCountOutput));
    wrapper->states = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVirtualKeyboardAnimationStateMETA>>();
    bytes_read += wrapper->states->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->states = wrapper->states->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVirtualKeyboardTextureDataMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVirtualKeyboardTextureDataMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->textureWidth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->textureHeight));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferCountOutput));
    bytes_read += wrapper->buffer.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    value->buffer = wrapper->buffer.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVirtualKeyboardInputInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVirtualKeyboardInputInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->inputSource));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->inputSpace));
    value->inputSpace = XR_NULL_HANDLE;
    wrapper->inputPoseInSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->inputPoseInSpace->decoded_value = &(value->inputPoseInSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->inputPoseInSpace);
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inputState));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVirtualKeyboardTextContextChangeInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVirtualKeyboardTextContextChangeInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += wrapper->textContext.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->textContext = wrapper->textContext.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataVirtualKeyboardCommitTextMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataVirtualKeyboardCommitTextMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->keyboard));
    value->keyboard = XR_NULL_HANDLE;
    wrapper->text.SetExternalMemory(value->text, XR_MAX_VIRTUAL_KEYBOARD_COMMIT_TEXT_SIZE_META);
    bytes_read += wrapper->text.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataVirtualKeyboardBackspaceMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataVirtualKeyboardBackspaceMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->keyboard));
    value->keyboard = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataVirtualKeyboardEnterMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataVirtualKeyboardEnterMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->keyboard));
    value->keyboard = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataVirtualKeyboardShownMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataVirtualKeyboardShownMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->keyboard));
    value->keyboard = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataVirtualKeyboardHiddenMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataVirtualKeyboardHiddenMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->keyboard));
    value->keyboard = XR_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrExternalCameraIntrinsicsOCULUS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrExternalCameraIntrinsicsOCULUS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->lastChangeTime));
    wrapper->fov = DecodeAllocator::Allocate<Decoded_XrFovf>();
    wrapper->fov->decoded_value = &(value->fov);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->fov);
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->virtualNearPlaneDistance));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->virtualFarPlaneDistance));
    wrapper->imageSensorPixelResolution = DecodeAllocator::Allocate<Decoded_XrExtent2Di>();
    wrapper->imageSensorPixelResolution->decoded_value = &(value->imageSensorPixelResolution);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageSensorPixelResolution);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrExternalCameraExtrinsicsOCULUS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrExternalCameraExtrinsicsOCULUS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->lastChangeTime));
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->cameraStatusFlags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachedToDevice));
    wrapper->relativePose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->relativePose->decoded_value = &(value->relativePose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->relativePose);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrExternalCameraOCULUS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrExternalCameraOCULUS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->name.SetExternalMemory(value->name, XR_MAX_EXTERNAL_CAMERA_NAME_SIZE_OCULUS);
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->intrinsics = DecodeAllocator::Allocate<Decoded_XrExternalCameraIntrinsicsOCULUS>();
    wrapper->intrinsics->decoded_value = &(value->intrinsics);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->intrinsics);
    wrapper->extrinsics = DecodeAllocator::Allocate<Decoded_XrExternalCameraExtrinsicsOCULUS>();
    wrapper->extrinsics->decoded_value = &(value->extrinsics);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extrinsics);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVulkanSwapchainCreateInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrVulkanSwapchainCreateInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->additionalCreateFlags));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->additionalUsageFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPerformanceMetricsStateMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPerformanceMetricsStateMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabled));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPerformanceMetricsCounterMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPerformanceMetricsCounterMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->counterFlags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->counterUnit));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->uintValue));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->floatValue));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceListSaveInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceListSaveInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->spaceCount));
    bytes_read += wrapper->spaces.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->spaces = nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->location));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataSpaceListSaveCompleteFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataSpaceListSaveCompleteFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->requestId));
    value->requestId = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->result));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceUserCreateInfoFB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceUserCreateInfoFB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->userId));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemHeadsetIdPropertiesMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemHeadsetIdPropertiesMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->id = DecodeAllocator::Allocate<Decoded_XrUuidEXT>();
    wrapper->id->decoded_value = &(value->id);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->id);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRecommendedLayerResolutionMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRecommendedLayerResolutionMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->recommendedImageDimensions = DecodeAllocator::Allocate<Decoded_XrExtent2Di>();
    wrapper->recommendedImageDimensions->decoded_value = &(value->recommendedImageDimensions);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->recommendedImageDimensions);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isValid));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrRecommendedLayerResolutionGetInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrRecommendedLayerResolutionGetInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->layer = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrCompositionLayerBaseHeader>>();
    bytes_read += wrapper->layer->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->layer = wrapper->layer->GetPointer();
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->predictedDisplayTime));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughColorLutDataMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughColorLutDataMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferSize));
    bytes_read += wrapper->buffer.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    value->buffer = wrapper->buffer.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughColorLutCreateInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughColorLutCreateInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->channels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->resolution));
    wrapper->data = DecodeAllocator::Allocate<Decoded_XrPassthroughColorLutDataMETA>();
    wrapper->data->decoded_value = &(value->data);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->data);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughColorLutUpdateInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughColorLutUpdateInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    wrapper->data = DecodeAllocator::Allocate<Decoded_XrPassthroughColorLutDataMETA>();
    wrapper->data->decoded_value = &(value->data);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->data);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughColorMapLutMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughColorMapLutMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->colorLut));
    value->colorLut = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->weight));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughColorMapInterpolatedLutMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughColorMapInterpolatedLutMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sourceColorLut));
    value->sourceColorLut = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->targetColorLut));
    value->targetColorLut = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->weight));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemPassthroughColorLutPropertiesMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemPassthroughColorLutPropertiesMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxColorLutResolution));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceTriangleMeshGetInfoMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceTriangleMeshGetInfoMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceTriangleMeshMETA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpaceTriangleMeshMETA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCountOutput));
    wrapper->vertices = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector3f>>();
    bytes_read += wrapper->vertices->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertices = wrapper->vertices->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCountOutput));
    bytes_read += wrapper->indices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->indices = wrapper->indices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemFaceTrackingProperties2FB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemFaceTrackingProperties2FB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsVisualFaceTracking));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsAudioFaceTracking));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFaceTrackerCreateInfo2FB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFaceTrackerCreateInfo2FB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->faceExpressionSet));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->requestedDataSourceCount));
    bytes_read += wrapper->requestedDataSources.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->requestedDataSources = wrapper->requestedDataSources.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFaceExpressionInfo2FB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFaceExpressionInfo2FB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFaceExpressionWeights2FB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFaceExpressionWeights2FB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->weightCount));
    bytes_read += wrapper->weights.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->weights = wrapper->weights.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->confidenceCount));
    bytes_read += wrapper->confidences.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->confidences = wrapper->confidences.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isValid));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isEyeFollowingBlendshapesValid));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dataSource));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughCreateInfoHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughCreateInfoHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->form));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughColorHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughColorHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->alpha));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPassthroughMeshTransformInfoHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPassthroughMeshTransformInfoHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCount));
    wrapper->vertices = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector3f>>();
    bytes_read += wrapper->vertices->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertices = wrapper->vertices->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCount));
    bytes_read += wrapper->indices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->indices = wrapper->indices.GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->baseSpace));
    value->baseSpace = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    wrapper->scale = DecodeAllocator::Allocate<Decoded_XrVector3f>();
    wrapper->scale->decoded_value = &(value->scale);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->scale);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerPassthroughHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrCompositionLayerPassthroughHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerFlags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->passthrough));
    value->passthrough = XR_NULL_HANDLE;
    wrapper->color = DecodeAllocator::Allocate<Decoded_XrPassthroughColorHTC>();
    wrapper->color->decoded_value = &(value->color);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->color);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFoveationApplyInfoHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFoveationApplyInfoHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->mode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subImageCount));
    wrapper->subImages = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrSwapchainSubImage>>();
    bytes_read += wrapper->subImages->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->subImages = wrapper->subImages->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFoveationConfigurationHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFoveationConfigurationHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->level));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->clearFovDegree));
    wrapper->focalCenterOffset = DecodeAllocator::Allocate<Decoded_XrVector2f>();
    wrapper->focalCenterOffset->decoded_value = &(value->focalCenterOffset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->focalCenterOffset);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFoveationDynamicModeInfoHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFoveationDynamicModeInfoHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dynamicFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFoveationCustomModeInfoHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrFoveationCustomModeInfoHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->configCount));
    wrapper->configs = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrFoveationConfigurationHTC>>();
    bytes_read += wrapper->configs->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->configs = wrapper->configs->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemAnchorPropertiesHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemAnchorPropertiesHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsAnchor));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialAnchorNameHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialAnchorNameHTC* value = wrapper->decoded_value;

    wrapper->name.SetExternalMemory(value->name, XR_MAX_SPATIAL_ANCHOR_NAME_SIZE_HTC);
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpatialAnchorCreateInfoHTC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSpatialAnchorCreateInfoHTC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->space));
    value->space = XR_NULL_HANDLE;
    wrapper->poseInSpace = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->poseInSpace->decoded_value = &(value->poseInSpace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->poseInSpace);
    wrapper->name = DecodeAllocator::Allocate<Decoded_XrSpatialAnchorNameHTC>();
    wrapper->name->decoded_value = &(value->name);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->name);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActiveActionSetPriorityEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActiveActionSetPriorityEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->actionSet));
    value->actionSet = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->priorityOverride));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrActiveActionSetPrioritiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrActiveActionSetPrioritiesEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->actionSetPriorityCount));
    wrapper->actionSetPriorities = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrActiveActionSetPriorityEXT>>();
    bytes_read += wrapper->actionSetPriorities->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->actionSetPriorities = wrapper->actionSetPriorities->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemForceFeedbackCurlPropertiesMNDX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemForceFeedbackCurlPropertiesMNDX* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsForceFeedbackCurl));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrForceFeedbackCurlApplyLocationMNDX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrForceFeedbackCurlApplyLocationMNDX* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->location));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->value));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrForceFeedbackCurlApplyLocationsMNDX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrForceFeedbackCurlApplyLocationsMNDX* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->locationCount));
    wrapper->locations = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrForceFeedbackCurlApplyLocationMNDX>>();
    bytes_read += wrapper->locations->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->locations = wrapper->locations->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandTrackingDataSourceInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandTrackingDataSourceInfoEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->requestedDataSourceCount));
    bytes_read += wrapper->requestedDataSources.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->requestedDataSources = wrapper->requestedDataSources.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrHandTrackingDataSourceStateEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrHandTrackingDataSourceStateEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isActive));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dataSource));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemPlaneDetectionPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemPlaneDetectionPropertiesEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedFeatures));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPlaneDetectorCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPlaneDetectorCreateInfoEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrExtent3DfEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrExtent3DfEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depth));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPlaneDetectorBeginInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPlaneDetectorBeginInfoEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->baseSpace));
    value->baseSpace = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->orientationCount));
    bytes_read += wrapper->orientations.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->orientations = wrapper->orientations.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->semanticTypeCount));
    bytes_read += wrapper->semanticTypes.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->semanticTypes = wrapper->semanticTypes.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPlanes));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minArea));
    wrapper->boundingBoxPose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->boundingBoxPose->decoded_value = &(value->boundingBoxPose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->boundingBoxPose);
    wrapper->boundingBoxExtent = DecodeAllocator::Allocate<Decoded_XrExtent3DfEXT>();
    wrapper->boundingBoxExtent->decoded_value = &(value->boundingBoxExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->boundingBoxExtent);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPlaneDetectorGetInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPlaneDetectorGetInfoEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->baseSpace));
    value->baseSpace = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPlaneDetectorLocationEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPlaneDetectorLocationEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeId));
    bytes_read += ValueDecoder::DecodeFlags64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->locationFlags));
    wrapper->pose = DecodeAllocator::Allocate<Decoded_XrPosef>();
    wrapper->pose->decoded_value = &(value->pose);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->pose);
    wrapper->extents = DecodeAllocator::Allocate<Decoded_XrExtent2Df>();
    wrapper->extents->decoded_value = &(value->extents);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extents);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->orientation));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->semanticType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->polygonBufferCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPlaneDetectorLocationsEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPlaneDetectorLocationsEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeLocationCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeLocationCountOutput));
    wrapper->planeLocations = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrPlaneDetectorLocationEXT>>();
    bytes_read += wrapper->planeLocations->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->planeLocations = wrapper->planeLocations->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrPlaneDetectorPolygonBufferEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrPlaneDetectorPolygonBufferEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCapacityInput));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCountOutput));
    wrapper->vertices = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_XrVector2f>>();
    bytes_read += wrapper->vertices->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vertices = wrapper->vertices->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataUserPresenceChangedEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataUserPresenceChangedEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->session));
    value->session = XR_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->isUserPresent));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSystemUserPresencePropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrSystemUserPresencePropertiesEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsUserPresence));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataHeadsetFitChangedML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataHeadsetFitChangedML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->status));
    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->time));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataEyeCalibrationChangedML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrEventDataEyeCalibrationChangedML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->status));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrUserCalibrationEnableEventsInfoML* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    XrUserCalibrationEnableEventsInfoML* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->next));
    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabled));

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
