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

#include "generated/generated_openxr_struct_encoders.h"

#include "encode/custom_openxr_struct_encoders.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "util/defines.h"

#include "openxr/openxr.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodeStruct(ParameterEncoder* encoder, const XrApiLayerProperties& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeString(value.layerName);
    encoder->EncodeXrVersionValue(value.specVersion);
    encoder->EncodeUInt32Value(value.layerVersion);
    encoder->EncodeString(value.description);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExtensionProperties& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeString(value.extensionName);
    encoder->EncodeUInt32Value(value.extensionVersion);
}

void EncodeStruct(ParameterEncoder* encoder, const XrApplicationInfo& value)
{
    encoder->EncodeString(value.applicationName);
    encoder->EncodeUInt32Value(value.applicationVersion);
    encoder->EncodeString(value.engineName);
    encoder->EncodeUInt32Value(value.engineVersion);
    encoder->EncodeXrVersionValue(value.apiVersion);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInstanceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.createFlags);
    EncodeStruct(encoder, value.applicationInfo);
    encoder->EncodeUInt32Value(value.enabledApiLayerCount);
    encoder->EncodeStringArray(value.enabledApiLayerNames, value.enabledApiLayerCount);
    encoder->EncodeUInt32Value(value.enabledExtensionCount);
    encoder->EncodeStringArray(value.enabledExtensionNames, value.enabledExtensionCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInstanceProperties& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrVersionValue(value.runtimeVersion);
    encoder->EncodeString(value.runtimeName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataBuffer& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt8Array(value.varying, 4000);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemGetInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.formFactor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemGraphicsProperties& value)
{
    encoder->EncodeUInt32Value(value.maxSwapchainImageHeight);
    encoder->EncodeUInt32Value(value.maxSwapchainImageWidth);
    encoder->EncodeUInt32Value(value.maxLayerCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemTrackingProperties& value)
{
    encoder->EncodeXrBool32Value(value.orientationTracking);
    encoder->EncodeXrBool32Value(value.positionTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemProperties& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrSystemIdValue(value.systemId);
    encoder->EncodeUInt32Value(value.vendorId);
    encoder->EncodeString(value.systemName);
    EncodeStruct(encoder, value.graphicsProperties);
    EncodeStruct(encoder, value.trackingProperties);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSessionCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.createFlags);
    encoder->EncodeXrSystemIdValue(value.systemId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVector3f& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
    encoder->EncodeFloatValue(value.z);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceVelocity& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.velocityFlags);
    EncodeStruct(encoder, value.linearVelocity);
    EncodeStruct(encoder, value.angularVelocity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrQuaternionf& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
    encoder->EncodeFloatValue(value.z);
    encoder->EncodeFloatValue(value.w);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPosef& value)
{
    EncodeStruct(encoder, value.orientation);
    EncodeStruct(encoder, value.position);
}

void EncodeStruct(ParameterEncoder* encoder, const XrReferenceSpaceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.referenceSpaceType);
    EncodeStruct(encoder, value.poseInReferenceSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExtent2Df& value)
{
    encoder->EncodeFloatValue(value.width);
    encoder->EncodeFloatValue(value.height);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionSpaceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
    encoder->EncodeXrPathValue(value.subactionPath);
    EncodeStruct(encoder, value.poseInActionSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceLocation& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.locationFlags);
    EncodeStruct(encoder, value.pose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationProperties& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.viewConfigurationType);
    encoder->EncodeXrBool32Value(value.fovMutable);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationView& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.recommendedImageRectWidth);
    encoder->EncodeUInt32Value(value.maxImageRectWidth);
    encoder->EncodeUInt32Value(value.recommendedImageRectHeight);
    encoder->EncodeUInt32Value(value.maxImageRectHeight);
    encoder->EncodeUInt32Value(value.recommendedSwapchainSampleCount);
    encoder->EncodeUInt32Value(value.maxSwapchainSampleCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.createFlags);
    encoder->EncodeFlags64Value(value.usageFlags);
    encoder->EncodeInt64Value(value.format);
    encoder->EncodeUInt32Value(value.sampleCount);
    encoder->EncodeUInt32Value(value.width);
    encoder->EncodeUInt32Value(value.height);
    encoder->EncodeUInt32Value(value.faceCount);
    encoder->EncodeUInt32Value(value.arraySize);
    encoder->EncodeUInt32Value(value.mipCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageBaseHeader& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageAcquireInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageWaitInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrDurationValue(value.timeout);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageReleaseInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSessionBeginInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.primaryViewConfigurationType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFrameWaitInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFrameState& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrTimeValue(value.predictedDisplayTime);
    encoder->EncodeXrDurationValue(value.predictedDisplayPeriod);
    encoder->EncodeXrBool32Value(value.shouldRender);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFrameBeginInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerBaseHeader& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFrameEndInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrTimeValue(value.displayTime);
    encoder->EncodeEnumValue(value.environmentBlendMode);
    encoder->EncodeUInt32Value(value.layerCount);
    EncodeStructArray2D(encoder, value.layers, ArraySize2D<XrStructureType, const void*, XrTime, XrEnvironmentBlendMode, uint32_t, const XrCompositionLayerBaseHeader* const*>(type, next, displayTime, environmentBlendMode, layerCount, layers));
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewLocateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.viewConfigurationType);
    encoder->EncodeXrTimeValue(value.displayTime);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewState& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.viewStateFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFovf& value)
{
    encoder->EncodeFloatValue(value.angleLeft);
    encoder->EncodeFloatValue(value.angleRight);
    encoder->EncodeFloatValue(value.angleUp);
    encoder->EncodeFloatValue(value.angleDown);
}

void EncodeStruct(ParameterEncoder* encoder, const XrView& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.fov);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionSetCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeString(value.actionSetName);
    encoder->EncodeString(value.localizedActionSetName);
    encoder->EncodeUInt32Value(value.priority);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeString(value.actionName);
    encoder->EncodeEnumValue(value.actionType);
    encoder->EncodeUInt32Value(value.countSubactionPaths);
    encoder->EncodeXrPathArray(value.subactionPaths, value.countSubactionPaths);
    encoder->EncodeString(value.localizedActionName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionSuggestedBinding& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
    encoder->EncodeXrPathValue(value.binding);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileSuggestedBinding& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrPathValue(value.interactionProfile);
    encoder->EncodeUInt32Value(value.countSuggestedBindings);
    EncodeStructArray(encoder, value.suggestedBindings, value.countSuggestedBindings);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSessionActionSetsAttachInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.countActionSets);
    encoder->EncodeOpenXrHandleArray<openxr_wrappers::ActionSetWrapper>(value.actionSets, value.countActionSets);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileState& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrPathValue(value.interactionProfile);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionStateGetInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
    encoder->EncodeXrPathValue(value.subactionPath);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionStateBoolean& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.currentState);
    encoder->EncodeXrBool32Value(value.changedSinceLastSync);
    encoder->EncodeXrTimeValue(value.lastChangeTime);
    encoder->EncodeXrBool32Value(value.isActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionStateFloat& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.currentState);
    encoder->EncodeXrBool32Value(value.changedSinceLastSync);
    encoder->EncodeXrTimeValue(value.lastChangeTime);
    encoder->EncodeXrBool32Value(value.isActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVector2f& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionStateVector2f& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.currentState);
    encoder->EncodeXrBool32Value(value.changedSinceLastSync);
    encoder->EncodeXrTimeValue(value.lastChangeTime);
    encoder->EncodeXrBool32Value(value.isActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionStatePose& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.isActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActiveActionSet& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionSetWrapper>(value.actionSet);
    encoder->EncodeXrPathValue(value.subactionPath);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionsSyncInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.countActiveActionSets);
    EncodeStructArray(encoder, value.activeActionSets, value.countActiveActionSets);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBoundSourcesForActionEnumerateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInputSourceLocalizedNameGetInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrPathValue(value.sourcePath);
    encoder->EncodeFlags64Value(value.whichComponents);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHapticActionInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
    encoder->EncodeXrPathValue(value.subactionPath);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHapticBaseHeader& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBaseInStructure& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeStructPtr(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBaseOutStructure& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeStructPtr(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrOffset2Di& value)
{
    encoder->EncodeInt32Value(value.x);
    encoder->EncodeInt32Value(value.y);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExtent2Di& value)
{
    encoder->EncodeInt32Value(value.width);
    encoder->EncodeInt32Value(value.height);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRect2Di& value)
{
    EncodeStruct(encoder, value.offset);
    EncodeStruct(encoder, value.extent);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainSubImage& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(value.swapchain);
    EncodeStruct(encoder, value.imageRect);
    encoder->EncodeUInt32Value(value.imageArrayIndex);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerProjectionView& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.fov);
    EncodeStruct(encoder, value.subImage);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerProjection& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeUInt32Value(value.viewCount);
    EncodeStructArray(encoder, value.views, value.viewCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerQuad& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.eyeVisibility);
    EncodeStruct(encoder, value.subImage);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.size);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataBaseHeader& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataEventsLost& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.lostEventCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataInstanceLossPending& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrTimeValue(value.lossTime);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSessionStateChanged& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
    encoder->EncodeEnumValue(value.state);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataReferenceSpaceChangePending& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
    encoder->EncodeEnumValue(value.referenceSpaceType);
    encoder->EncodeXrTimeValue(value.changeTime);
    encoder->EncodeXrBool32Value(value.poseValid);
    EncodeStruct(encoder, value.poseInPreviousSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataInteractionProfileChanged& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHapticVibration& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrDurationValue(value.duration);
    encoder->EncodeFloatValue(value.frequency);
    encoder->EncodeFloatValue(value.amplitude);
}

void EncodeStruct(ParameterEncoder* encoder, const XrOffset2Df& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRect2Df& value)
{
    EncodeStruct(encoder, value.offset);
    EncodeStruct(encoder, value.extent);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVector4f& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
    encoder->EncodeFloatValue(value.z);
    encoder->EncodeFloatValue(value.w);
}

void EncodeStruct(ParameterEncoder* encoder, const XrColor4f& value)
{
    encoder->EncodeFloatValue(value.r);
    encoder->EncodeFloatValue(value.g);
    encoder->EncodeFloatValue(value.b);
    encoder->EncodeFloatValue(value.a);
}

void EncodeStruct(ParameterEncoder* encoder, const XrApiLayerNextInfo& value)
{
    encoder->EncodeEnumValue(value.structType);
    encoder->EncodeUInt32Value(value.structVersion);
    encoder->EncodeSizeTValue(value.structSize);
    encoder->EncodeString(value.layerName);
    encoder->EncodeFunctionPtr(value.nextGetInstanceProcAddr);
    encoder->EncodeFunctionPtr(value.nextCreateApiLayerInstance);
    EncodeStructPtr(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrApiLayerCreateInfo& value)
{
    encoder->EncodeEnumValue(value.structType);
    encoder->EncodeUInt32Value(value.structVersion);
    encoder->EncodeSizeTValue(value.structSize);
    encoder->EncodeVoidPtr(value.loaderInstance);
    encoder->EncodeString(value.settings_file_location);
    EncodeStructPtr(encoder, value.nextInfo);
}

void EncodeStruct(ParameterEncoder* encoder, const XrNegotiateLoaderInfo& value)
{
    encoder->EncodeEnumValue(value.structType);
    encoder->EncodeUInt32Value(value.structVersion);
    encoder->EncodeSizeTValue(value.structSize);
    encoder->EncodeUInt32Value(value.minInterfaceVersion);
    encoder->EncodeUInt32Value(value.maxInterfaceVersion);
    encoder->EncodeXrVersionValue(value.minApiVersion);
    encoder->EncodeXrVersionValue(value.maxApiVersion);
}

void EncodeStruct(ParameterEncoder* encoder, const XrNegotiateRuntimeRequest& value)
{
    encoder->EncodeEnumValue(value.structType);
    encoder->EncodeUInt32Value(value.structVersion);
    encoder->EncodeSizeTValue(value.structSize);
    encoder->EncodeUInt32Value(value.runtimeInterfaceVersion);
    encoder->EncodeXrVersionValue(value.runtimeApiVersion);
    encoder->EncodeFunctionPtr(value.getInstanceProcAddr);
}

void EncodeStruct(ParameterEncoder* encoder, const XrNegotiateApiLayerRequest& value)
{
    encoder->EncodeEnumValue(value.structType);
    encoder->EncodeUInt32Value(value.structVersion);
    encoder->EncodeSizeTValue(value.structSize);
    encoder->EncodeUInt32Value(value.layerInterfaceVersion);
    encoder->EncodeXrVersionValue(value.layerApiVersion);
    encoder->EncodeFunctionPtr(value.getInstanceProcAddr);
    encoder->EncodeFunctionPtr(value.createApiLayerInstance);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerCubeKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.eyeVisibility);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(value.swapchain);
    encoder->EncodeUInt32Value(value.imageArrayIndex);
    EncodeStruct(encoder, value.orientation);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInstanceCreateInfoAndroidKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeVoidPtr(value.applicationVM);
    encoder->EncodeVoidPtr(value.applicationActivity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerDepthInfoKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.subImage);
    encoder->EncodeFloatValue(value.minDepth);
    encoder->EncodeFloatValue(value.maxDepth);
    encoder->EncodeFloatValue(value.nearZ);
    encoder->EncodeFloatValue(value.farZ);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanSwapchainFormatListCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.viewFormatCount);
    encoder->EncodeVkFormatArray(value.viewFormats, value.viewFormatCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerCylinderKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.eyeVisibility);
    EncodeStruct(encoder, value.subImage);
    EncodeStruct(encoder, value.pose);
    encoder->EncodeFloatValue(value.radius);
    encoder->EncodeFloatValue(value.centralAngle);
    encoder->EncodeFloatValue(value.aspectRatio);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerEquirectKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.eyeVisibility);
    EncodeStruct(encoder, value.subImage);
    EncodeStruct(encoder, value.pose);
    encoder->EncodeFloatValue(value.radius);
    EncodeStruct(encoder, value.scale);
    EncodeStruct(encoder, value.bias);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLWin32KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeHDCValue(value.hDC);
    encoder->EncodeHGLRCValue(value.hGLRC);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLXlibKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeVoidPtr(value.xDisplay);
    encoder->EncodeUInt32Value(value.visualid);
    encoder->EncodeGLXFBConfigValue(value.glxFBConfig);
    encoder->EncodeGLXDrawableValue(value.glxDrawable);
    encoder->EncodeGLXContextValue(value.glxContext);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLXcbKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeVoidPtr(value.connection);
    encoder->EncodeUInt32Value(value.screenNumber);
    encoder->EncodeXcb_Glx_FbconfigValue(value.fbconfigid);
    encoder->EncodeUInt32Value(value.visualid);
    encoder->EncodeXcb_Glx_DrawableValue(value.glxDrawable);
    encoder->EncodeXcb_Glx_ContextValue(value.glxContext);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLWaylandKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeVoidPtr(value.display);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageOpenGLKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.image);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsOpenGLKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrVersionValue(value.minApiVersionSupported);
    encoder->EncodeXrVersionValue(value.maxApiVersionSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLESAndroidKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEGLDisplayValue(value.display);
    encoder->EncodeEGLConfigValue(value.config);
    encoder->EncodeEGLContextValue(value.context);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageOpenGLESKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.image);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsOpenGLESKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrVersionValue(value.minApiVersionSupported);
    encoder->EncodeXrVersionValue(value.maxApiVersionSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingVulkanKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeVkInstanceValue(value.instance);
    encoder->EncodeVkPhysicalDeviceValue(value.physicalDevice);
    encoder->EncodeVkDeviceValue(value.device);
    encoder->EncodeUInt32Value(value.queueFamilyIndex);
    encoder->EncodeUInt32Value(value.queueIndex);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageVulkanKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeVkImageValue(value.image);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsVulkanKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrVersionValue(value.minApiVersionSupported);
    encoder->EncodeXrVersionValue(value.maxApiVersionSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingD3D11KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeID3D11DevicePtr(value.device);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageD3D11KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeID3D11Texture2DPtr(value.texture);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsD3D11KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeLUIDValue(value.adapterLuid);
    encoder->EncodeD3D_FEATURE_LEVELValue(value.minFeatureLevel);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingD3D12KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeID3D12DevicePtr(value.device);
    encoder->EncodeID3D12CommandQueuePtr(value.queue);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageD3D12KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeID3D12ResourcePtr(value.texture);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsD3D12KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeLUIDValue(value.adapterLuid);
    encoder->EncodeD3D_FEATURE_LEVELValue(value.minFeatureLevel);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVisibilityMaskKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeUInt32Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVisibilityMaskChangedKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
    encoder->EncodeEnumValue(value.viewConfigurationType);
    encoder->EncodeUInt32Value(value.viewIndex);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerColorScaleBiasKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.colorScale);
    EncodeStruct(encoder, value.colorBias);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLoaderInitInfoBaseHeaderKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLoaderInitInfoAndroidKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeVoidPtr(value.applicationVM);
    encoder->EncodeVoidPtr(value.applicationContext);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanInstanceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrSystemIdValue(value.systemId);
    encoder->EncodeFlags64Value(value.createFlags);
    encoder->EncodeFunctionPtr(value.pfnGetInstanceProcAddr);
    encoder->EncodeVkInstanceCreateInfoPtr(value.vulkanCreateInfo);
    encoder->EncodeVkAllocationCallbacksPtr(value.vulkanAllocator);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanDeviceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrSystemIdValue(value.systemId);
    encoder->EncodeFlags64Value(value.createFlags);
    encoder->EncodeFunctionPtr(value.pfnGetInstanceProcAddr);
    encoder->EncodeVkPhysicalDeviceValue(value.vulkanPhysicalDevice);
    encoder->EncodeVkDeviceCreateInfoPtr(value.vulkanCreateInfo);
    encoder->EncodeVkAllocationCallbacksPtr(value.vulkanAllocator);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanGraphicsDeviceGetInfoKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrSystemIdValue(value.systemId);
    encoder->EncodeVkInstanceValue(value.vulkanInstance);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerEquirect2KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.eyeVisibility);
    EncodeStruct(encoder, value.subImage);
    EncodeStruct(encoder, value.pose);
    encoder->EncodeFloatValue(value.radius);
    encoder->EncodeFloatValue(value.centralHorizontalAngle);
    encoder->EncodeFloatValue(value.upperVerticalAngle);
    encoder->EncodeFloatValue(value.lowerVerticalAngle);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBindingModificationBaseHeaderKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBindingModificationsKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.bindingModificationCount);
    EncodeStructArray2D(encoder, value.bindingModifications, ArraySize2D<XrStructureType, const void*, uint32_t, const XrBindingModificationBaseHeaderKHR* const*>(type, next, bindingModificationCount, bindingModifications));
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataPerfSettingsEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.domain);
    encoder->EncodeEnumValue(value.subDomain);
    encoder->EncodeEnumValue(value.fromLevel);
    encoder->EncodeEnumValue(value.toLevel);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsObjectNameInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.objectType);
    encoder->EncodeUInt64Value(value.objectHandle);
    encoder->EncodeString(value.objectName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsLabelEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeString(value.labelName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsMessengerCallbackDataEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeString(value.messageId);
    encoder->EncodeString(value.functionName);
    encoder->EncodeString(value.message);
    encoder->EncodeUInt32Value(value.objectCount);
    EncodeStructArray(encoder, value.objects, value.objectCount);
    encoder->EncodeUInt32Value(value.sessionLabelCount);
    EncodeStructArray(encoder, value.sessionLabels, value.sessionLabelCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsMessengerCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.messageSeverities);
    encoder->EncodeFlags64Value(value.messageTypes);
    encoder->EncodeFunctionPtr(value.userCallback);
    encoder->EncodeVoidPtr(value.userData);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemEyeGazeInteractionPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsEyeGazeInteraction);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazeSampleTimeEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSessionCreateInfoOverlayEXTX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.createFlags);
    encoder->EncodeUInt32Value(value.sessionLayersPlacement);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataMainSessionVisibilityChangedEXTX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.visible);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.pose);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorSpaceCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorMSFTWrapper>(value.anchor);
    EncodeStruct(encoder, value.poseInAnchorSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerImageLayoutFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerAlphaBlendFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.srcFactorColor);
    encoder->EncodeEnumValue(value.dstFactorColor);
    encoder->EncodeEnumValue(value.srcFactorAlpha);
    encoder->EncodeEnumValue(value.dstFactorAlpha);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationDepthRangeEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.recommendedNearZ);
    encoder->EncodeFloatValue(value.minNearZ);
    encoder->EncodeFloatValue(value.recommendedFarZ);
    encoder->EncodeFloatValue(value.maxFarZ);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingEGLMNDX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFunctionPtr(value.getProcAddress);
    encoder->EncodeEGLDisplayValue(value.display);
    encoder->EncodeEGLConfigValue(value.config);
    encoder->EncodeEGLContextValue(value.context);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphNodeSpaceCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.nodeType);
    encoder->EncodeUInt8Array(value.nodeId, XR_GUID_SIZE_MSFT);
    EncodeStruct(encoder, value.pose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphStaticNodeBindingCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.poseInSpace);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphNodeBindingPropertiesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt8Array(value.nodeId, XR_GUID_SIZE_MSFT);
    EncodeStruct(encoder, value.poseInNodeSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemHandTrackingPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsHandTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackerCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.hand);
    encoder->EncodeEnumValue(value.handJointSet);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointsLocateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointLocationEXT& value)
{
    encoder->EncodeFlags64Value(value.locationFlags);
    EncodeStruct(encoder, value.pose);
    encoder->EncodeFloatValue(value.radius);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointVelocityEXT& value)
{
    encoder->EncodeFlags64Value(value.velocityFlags);
    EncodeStruct(encoder, value.linearVelocity);
    EncodeStruct(encoder, value.angularVelocity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointLocationsEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.isActive);
    encoder->EncodeUInt32Value(value.jointCount);
    EncodeStructArray(encoder, value.jointLocations, value.jointCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointVelocitiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.jointCount);
    EncodeStructArray(encoder, value.jointVelocities, value.jointCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemHandTrackingMeshPropertiesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsHandTrackingMesh);
    encoder->EncodeUInt32Value(value.maxHandMeshIndexCount);
    encoder->EncodeUInt32Value(value.maxHandMeshVertexCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshSpaceCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.handPoseType);
    EncodeStruct(encoder, value.poseInHandMeshSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshUpdateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrTimeValue(value.time);
    encoder->EncodeEnumValue(value.handPoseType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshIndexBufferMSFT& value)
{
    encoder->EncodeUInt32Value(value.indexBufferKey);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeUInt32Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshVertexMSFT& value)
{
    EncodeStruct(encoder, value.position);
    EncodeStruct(encoder, value.normal);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshVertexBufferMSFT& value)
{
    encoder->EncodeXrTimeValue(value.vertexUpdateTime);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.isActive);
    encoder->EncodeXrBool32Value(value.indexBufferChanged);
    encoder->EncodeXrBool32Value(value.vertexBufferChanged);
    EncodeStruct(encoder, value.indexBuffer);
    EncodeStruct(encoder, value.vertexBuffer);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandPoseTypeInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.handPoseType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationSessionBeginInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.viewConfigurationCount);
    encoder->EncodeEnumArray(value.enabledViewConfigurationTypes, value.viewConfigurationCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationStateMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.viewConfigurationType);
    encoder->EncodeXrBool32Value(value.active);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationFrameStateMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.viewConfigurationCount);
    EncodeStructArray(encoder, value.viewConfigurationStates, value.viewConfigurationCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationLayerInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.viewConfigurationType);
    encoder->EncodeEnumValue(value.environmentBlendMode);
    encoder->EncodeUInt32Value(value.layerCount);
    EncodeStructArray2D(encoder, value.layers, ArraySize2D<XrStructureType, const void*, XrViewConfigurationType, XrEnvironmentBlendMode, uint32_t, const XrCompositionLayerBaseHeader* const*>(type, next, viewConfigurationType, environmentBlendMode, layerCount, layers));
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationFrameEndInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.viewConfigurationCount);
    EncodeStructArray(encoder, value.viewConfigurationLayersInfo, value.viewConfigurationCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.viewConfigurationType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelKeyStateMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrControllerModelKeyMSFTValue(value.modelKey);
}

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelNodePropertiesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeString(value.parentNodeName);
    encoder->EncodeString(value.nodeName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelPropertiesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.nodeCapacityInput);
    encoder->EncodeUInt32Value(value.nodeCountOutput);
    EncodeStructArray(encoder, value.nodeProperties, value.nodeCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelNodeStateMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.nodePose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelStateMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.nodeCapacityInput);
    encoder->EncodeUInt32Value(value.nodeCountOutput);
    EncodeStructArray(encoder, value.nodeStates, value.nodeCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationViewFovEPIC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.recommendedFov);
    EncodeStruct(encoder, value.maxMutableFov);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHolographicWindowAttachmentMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeIUnknownPtr(value.holographicSpace);
    encoder->EncodeIUnknownPtr(value.coreWindow);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerReprojectionInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.reprojectionMode);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerReprojectionPlaneOverrideMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.position);
    EncodeStruct(encoder, value.normal);
    EncodeStruct(encoder, value.velocity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrAndroidSurfaceSwapchainCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.createFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateBaseHeaderFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerSecureContentFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodyJointLocationFB& value)
{
    encoder->EncodeFlags64Value(value.locationFlags);
    EncodeStruct(encoder, value.pose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemBodyTrackingPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsBodyTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodyTrackerCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.bodyJointSet);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodySkeletonJointFB& value)
{
    encoder->EncodeInt32Value(value.joint);
    encoder->EncodeInt32Value(value.parentJoint);
    EncodeStruct(encoder, value.pose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodySkeletonFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.jointCount);
    EncodeStructArray(encoder, value.joints, value.jointCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodyJointsLocateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodyJointLocationsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.isActive);
    encoder->EncodeFloatValue(value.confidence);
    encoder->EncodeUInt32Value(value.jointCount);
    EncodeStructArray(encoder, value.jointLocations, value.jointCount);
    encoder->EncodeUInt32Value(value.skeletonChangedCount);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileDpadBindingEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrPathValue(value.binding);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionSetWrapper>(value.actionSet);
    encoder->EncodeFloatValue(value.forceThreshold);
    encoder->EncodeFloatValue(value.forceThresholdReleased);
    encoder->EncodeFloatValue(value.centerRegion);
    encoder->EncodeFloatValue(value.wedgeAngle);
    encoder->EncodeXrBool32Value(value.isSticky);
    EncodeStructPtr(encoder, value.onHaptic);
    EncodeStructPtr(encoder, value.offHaptic);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileAnalogThresholdVALVE& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
    encoder->EncodeXrPathValue(value.binding);
    encoder->EncodeFloatValue(value.onThreshold);
    encoder->EncodeFloatValue(value.offThreshold);
    EncodeStructPtr(encoder, value.onHaptic);
    EncodeStructPtr(encoder, value.offHaptic);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointsMotionRangeInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.handJointsMotionRange);
}

void EncodeStruct(ParameterEncoder* encoder, const XrUuidMSFT& value)
{
    encoder->EncodeUInt8Array(value.bytes, 16);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneObserverCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneSphereBoundMSFT& value)
{
    EncodeStruct(encoder, value.center);
    encoder->EncodeFloatValue(value.radius);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneOrientedBoxBoundMSFT& value)
{
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.extents);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneFrustumBoundMSFT& value)
{
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.fov);
    encoder->EncodeFloatValue(value.farDistance);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneBoundsMSFT& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeXrTimeValue(value.time);
    encoder->EncodeUInt32Value(value.sphereCount);
    EncodeStructArray(encoder, value.spheres, value.sphereCount);
    encoder->EncodeUInt32Value(value.boxCount);
    EncodeStructArray(encoder, value.boxes, value.boxCount);
    encoder->EncodeUInt32Value(value.frustumCount);
    EncodeStructArray(encoder, value.frustums, value.frustumCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrNewSceneComputeInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.requestedFeatureCount);
    encoder->EncodeEnumArray(value.requestedFeatures, value.requestedFeatureCount);
    encoder->EncodeEnumValue(value.consistency);
    EncodeStruct(encoder, value.bounds);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVisualMeshComputeLodInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.lod);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentMSFT& value)
{
    encoder->EncodeEnumValue(value.componentType);
    EncodeStruct(encoder, value.id);
    EncodeStruct(encoder, value.parentId);
    encoder->EncodeXrTimeValue(value.updateTime);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentsMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.componentCapacityInput);
    encoder->EncodeUInt32Value(value.componentCountOutput);
    EncodeStructArray(encoder, value.components, value.componentCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentsGetInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.componentType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentLocationMSFT& value)
{
    encoder->EncodeFlags64Value(value.flags);
    EncodeStruct(encoder, value.pose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentLocationsMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.locationCount);
    EncodeStructArray(encoder, value.locations, value.locationCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentsLocateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeXrTimeValue(value.time);
    encoder->EncodeUInt32Value(value.componentIdCount);
    EncodeStructArray(encoder, value.componentIds, value.componentIdCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneObjectMSFT& value)
{
    encoder->EncodeEnumValue(value.objectType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneObjectsMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.sceneObjectCount);
    EncodeStructArray(encoder, value.sceneObjects, value.sceneObjectCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentParentFilterInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.parentId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneObjectTypesFilterInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.objectTypeCount);
    encoder->EncodeEnumArray(value.objectTypes, value.objectTypeCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrScenePlaneMSFT& value)
{
    encoder->EncodeEnumValue(value.alignment);
    EncodeStruct(encoder, value.size);
    encoder->EncodeUInt64Value(value.meshBufferId);
    encoder->EncodeXrBool32Value(value.supportsIndicesUint16);
}

void EncodeStruct(ParameterEncoder* encoder, const XrScenePlanesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.scenePlaneCount);
    EncodeStructArray(encoder, value.scenePlanes, value.scenePlaneCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrScenePlaneAlignmentFilterInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.alignmentCount);
    encoder->EncodeEnumArray(value.alignments, value.alignmentCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshMSFT& value)
{
    encoder->EncodeUInt64Value(value.meshBufferId);
    encoder->EncodeXrBool32Value(value.supportsIndicesUint16);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.sceneMeshCount);
    EncodeStructArray(encoder, value.sceneMeshes, value.sceneMeshCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshBuffersGetInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt64Value(value.meshBufferId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshBuffersMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshVertexBufferMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshIndicesUint32MSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeUInt32Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshIndicesUint16MSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeUInt16Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSerializedSceneFragmentDataGetInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.sceneFragmentId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDeserializeSceneFragmentMSFT& value)
{
    encoder->EncodeUInt32Value(value.bufferSize);
    encoder->EncodeUInt8Array(value.buffer, value.bufferSize);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneDeserializeInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.fragmentCount);
    EncodeStructArray(encoder, value.fragments, value.fragmentCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataDisplayRefreshRateChangedFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.fromDisplayRefreshRate);
    encoder->EncodeFloatValue(value.toDisplayRefreshRate);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViveTrackerPathsHTCX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrPathValue(value.persistentPath);
    encoder->EncodeXrPathValue(value.rolePath);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataViveTrackerConnectedHTCX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStructPtr(encoder, value.paths);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFacialTrackingPropertiesHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportEyeFacialTracking);
    encoder->EncodeXrBool32Value(value.supportLipFacialTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFacialExpressionsHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.isActive);
    encoder->EncodeXrTimeValue(value.sampleTime);
    encoder->EncodeUInt32Value(value.expressionCount);
    encoder->EncodeFloatPtr(value.expressionWeightings);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFacialTrackerCreateInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.facialTrackingType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemColorSpacePropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.colorSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVector4sFB& value)
{
    encoder->EncodeInt16Value(value.x);
    encoder->EncodeInt16Value(value.y);
    encoder->EncodeInt16Value(value.z);
    encoder->EncodeInt16Value(value.w);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingMeshFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.jointCapacityInput);
    encoder->EncodeUInt32Value(value.jointCountOutput);
    EncodeStructArray(encoder, value.jointBindPoses, value.jointCapacityInput);
    encoder->EncodeFloatArray(value.jointRadii, value.jointCapacityInput);
    encoder->EncodeEnumArray(value.jointParents, value.jointCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertexPositions, value.vertexCapacityInput);
    EncodeStructArray(encoder, value.vertexNormals, value.vertexCapacityInput);
    EncodeStructArray(encoder, value.vertexUVs, value.vertexCapacityInput);
    EncodeStructArray(encoder, value.vertexBlendIndices, value.vertexCapacityInput);
    EncodeStructArray(encoder, value.vertexBlendWeights, value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeInt16Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingScaleFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.sensorOutput);
    encoder->EncodeFloatValue(value.currentOutput);
    encoder->EncodeXrBool32Value(value.overrideHandScale);
    encoder->EncodeFloatValue(value.overrideValueInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingAimStateFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.status);
    EncodeStruct(encoder, value.aimPose);
    encoder->EncodeFloatValue(value.pinchStrengthIndex);
    encoder->EncodeFloatValue(value.pinchStrengthMiddle);
    encoder->EncodeFloatValue(value.pinchStrengthRing);
    encoder->EncodeFloatValue(value.pinchStrengthLittle);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandCapsuleFB& value)
{
    EncodeStructArray(encoder, value.points, XR_HAND_TRACKING_CAPSULE_POINT_COUNT_FB);
    encoder->EncodeFloatValue(value.radius);
    encoder->EncodeEnumValue(value.joint);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingCapsulesStateFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStructArray(encoder, value.capsules, XR_HAND_TRACKING_CAPSULE_COUNT_FB);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemSpatialEntityPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsSpatialEntity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.poseInSpace);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceComponentStatusSetInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.componentType);
    encoder->EncodeXrBool32Value(value.enabled);
    encoder->EncodeXrDurationValue(value.timeout);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceComponentStatusFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.enabled);
    encoder->EncodeXrBool32Value(value.changePending);
}

void EncodeStruct(ParameterEncoder* encoder, const XrUuidEXT& value)
{
    encoder->EncodeUInt8Array(value.data, XR_UUID_SIZE_EXT);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpatialAnchorCreateCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrAsyncRequestIdFBValue(value.requestId);
    encoder->EncodeEnumValue(value.result);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.uuid);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceSetStatusCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrAsyncRequestIdFBValue(value.requestId);
    encoder->EncodeEnumValue(value.result);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.uuid);
    encoder->EncodeEnumValue(value.componentType);
    encoder->EncodeXrBool32Value(value.enabled);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationProfileCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainCreateInfoFoveationFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateFoveationFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::FoveationProfileFBWrapper>(value.profile);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationLevelProfileCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.level);
    encoder->EncodeFloatValue(value.verticalOffset);
    encoder->EncodeEnumValue(value.dynamic);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemKeyboardTrackingPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsKeyboardTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrKeyboardTrackingDescriptionFB& value)
{
    encoder->EncodeUInt64Value(value.trackedKeyboardId);
    EncodeStruct(encoder, value.size);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeString(value.name);
}

void EncodeStruct(ParameterEncoder* encoder, const XrKeyboardSpaceCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt64Value(value.trackedKeyboardId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrKeyboardTrackingQueryFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrTriangleMeshCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeEnumValue(value.windingOrder);
    encoder->EncodeUInt32Value(value.vertexCount);
    EncodeStructPtr(encoder, value.vertexBuffer);
    encoder->EncodeUInt32Value(value.triangleCount);
    encoder->EncodeUInt32Ptr(value.indexBuffer);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemPassthroughPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsPassthrough);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemPassthroughProperties2FB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.capabilities);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughLayerCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughFBWrapper>(value.passthrough);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeEnumValue(value.purpose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerPassthroughFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughLayerFBWrapper>(value.layerHandle);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGeometryInstanceCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughLayerFBWrapper>(value.layer);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(value.mesh);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.scale);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGeometryInstanceTransformFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeXrTimeValue(value.time);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.scale);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughStyleFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.textureOpacityFactor);
    EncodeStruct(encoder, value.edgeColor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapMonoToRgbaFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStructArray(encoder, value.textureColorMap, XR_PASSTHROUGH_COLOR_MAP_MONO_SIZE_FB);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapMonoToMonoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt8Array(value.textureColorMap, XR_PASSTHROUGH_COLOR_MAP_MONO_SIZE_FB);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughBrightnessContrastSaturationFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.brightness);
    encoder->EncodeFloatValue(value.contrast);
    encoder->EncodeFloatValue(value.saturation);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataPassthroughStateChangedFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelPathInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrPathValue(value.path);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.vendorId);
    encoder->EncodeString(value.modelName);
    encoder->EncodeXrRenderModelKeyFBValue(value.modelKey);
    encoder->EncodeUInt32Value(value.modelVersion);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelBufferFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.bufferCapacityInput);
    encoder->EncodeUInt32Value(value.bufferCountOutput);
    encoder->EncodeUInt8Array(value.buffer, value.bufferCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelLoadInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrRenderModelKeyFBValue(value.modelKey);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemRenderModelPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsRenderModelLoading);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelCapabilitiesRequestFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewLocateFoveatedRenderingVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.foveatedRenderingActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveatedViewConfigurationViewVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.foveatedRenderingActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFoveatedRenderingPropertiesVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsFoveatedRendering);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerDepthTestVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.depthTestRangeNearZ);
    encoder->EncodeFloatValue(value.depthTestRangeFarZ);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemMarkerTrackingPropertiesVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsMarkerTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataMarkerTrackingUpdateVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt64Value(value.markerId);
    encoder->EncodeXrBool32Value(value.isActive);
    encoder->EncodeXrBool32Value(value.isPredicted);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerSpaceCreateInfoVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt64Value(value.markerId);
    EncodeStruct(encoder, value.poseInMarkerSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFrameEndInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.focusDistance);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGlobalDimmerFrameEndInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.dimmerValue);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCoordinateSpaceCreateInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeMLCoordinateFrameUIDValue(value.cfuid);
    EncodeStruct(encoder, value.poseInCoordinateSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemMarkerUnderstandingPropertiesML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsMarkerUnderstanding);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorCreateInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.profile);
    encoder->EncodeEnumValue(value.markerType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorArucoInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.arucoDict);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorSizeInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.markerLength);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorAprilTagInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.aprilTagDict);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorCustomProfileInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.fpsHint);
    encoder->EncodeEnumValue(value.resolutionHint);
    encoder->EncodeEnumValue(value.cameraHint);
    encoder->EncodeEnumValue(value.cornerRefineMethod);
    encoder->EncodeXrBool32Value(value.useEdgeRefinement);
    encoder->EncodeEnumValue(value.fullAnalysisIntervalHint);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorSnapshotInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorStateML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.state);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerSpaceCreateInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(value.markerDetector);
    encoder->EncodeXrMarkerMLValue(value.marker);
    EncodeStruct(encoder, value.poseInMarkerSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationMapML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeString(value.name);
    EncodeStruct(encoder, value.mapUuid);
    encoder->EncodeEnumValue(value.mapType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataLocalizationChangedML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
    encoder->EncodeEnumValue(value.state);
    EncodeStruct(encoder, value.map);
    encoder->EncodeEnumValue(value.confidence);
    encoder->EncodeFlags64Value(value.errorFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationMapQueryInfoBaseHeaderML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMapLocalizationRequestInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.mapUuid);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationMapImportInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.size);
    encoder->EncodeStringArray(value.data, value.size);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationEnableEventsInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.enabled);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorPersistenceNameMSFT& value)
{
    encoder->EncodeString(value.name);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorPersistenceInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.spatialAnchorPersistenceName);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorMSFTWrapper>(value.spatialAnchor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(value.spatialAnchorStore);
    EncodeStruct(encoder, value.spatialAnchorPersistenceName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerMSFT& value)
{
    encoder->EncodeEnumValue(value.markerType);
    encoder->EncodeXrTimeValue(value.lastSeenTime);
    EncodeStruct(encoder, value.center);
    EncodeStruct(encoder, value.size);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkersMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.sceneMarkerCapacityInput);
    EncodeStructArray(encoder, value.sceneMarkers, value.sceneMarkerCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerTypeFilterMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.markerTypeCount);
    encoder->EncodeEnumArray(value.markerTypes, value.markerTypeCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerQRCodeMSFT& value)
{
    encoder->EncodeEnumValue(value.symbolType);
    encoder->EncodeUInt8Value(value.version);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerQRCodesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.qrCodeCapacityInput);
    EncodeStructArray(encoder, value.qrCodes, value.qrCodeCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryInfoBaseHeaderFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceFilterInfoBaseHeaderFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.queryAction);
    encoder->EncodeUInt32Value(value.maxResultCount);
    encoder->EncodeXrDurationValue(value.timeout);
    EncodeStructPtr(encoder, value.filter);
    EncodeStructPtr(encoder, value.excludeFilter);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceStorageLocationFilterInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.location);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceUuidFilterInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.uuidCount);
    EncodeStructArray(encoder, value.uuids, value.uuidCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceComponentFilterInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.componentType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryResultFB& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.uuid);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryResultsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.resultCapacityInput);
    encoder->EncodeUInt32Value(value.resultCountOutput);
    EncodeStructArray(encoder, value.results, value.resultCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceQueryResultsAvailableFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrAsyncRequestIdFBValue(value.requestId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceQueryCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrAsyncRequestIdFBValue(value.requestId);
    encoder->EncodeEnumValue(value.result);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceSaveInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.location);
    encoder->EncodeEnumValue(value.persistenceMode);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceEraseInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.location);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceSaveCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrAsyncRequestIdFBValue(value.requestId);
    encoder->EncodeEnumValue(value.result);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.uuid);
    encoder->EncodeEnumValue(value.location);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceEraseCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrAsyncRequestIdFBValue(value.requestId);
    encoder->EncodeEnumValue(value.result);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.uuid);
    encoder->EncodeEnumValue(value.location);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageFoveationVulkanFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeVkImageValue(value.image);
    encoder->EncodeUInt32Value(value.width);
    encoder->EncodeUInt32Value(value.height);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateAndroidSurfaceDimensionsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.width);
    encoder->EncodeUInt32Value(value.height);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateSamplerOpenGLESFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEGLenumValue(value.minFilter);
    encoder->EncodeEGLenumValue(value.magFilter);
    encoder->EncodeEGLenumValue(value.wrapModeS);
    encoder->EncodeEGLenumValue(value.wrapModeT);
    encoder->EncodeEGLenumValue(value.swizzleRed);
    encoder->EncodeEGLenumValue(value.swizzleGreen);
    encoder->EncodeEGLenumValue(value.swizzleBlue);
    encoder->EncodeEGLenumValue(value.swizzleAlpha);
    encoder->EncodeFloatValue(value.maxAnisotropy);
    EncodeStruct(encoder, value.borderColor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateSamplerVulkanFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeVkFilterValue(value.minFilter);
    encoder->EncodeVkFilterValue(value.magFilter);
    encoder->EncodeVkSamplerMipmapModeValue(value.mipmapMode);
    encoder->EncodeVkSamplerAddressModeValue(value.wrapModeS);
    encoder->EncodeVkSamplerAddressModeValue(value.wrapModeT);
    encoder->EncodeVkComponentSwizzleValue(value.swizzleRed);
    encoder->EncodeVkComponentSwizzleValue(value.swizzleGreen);
    encoder->EncodeVkComponentSwizzleValue(value.swizzleBlue);
    encoder->EncodeVkComponentSwizzleValue(value.swizzleAlpha);
    encoder->EncodeFloatValue(value.maxAnisotropy);
    EncodeStruct(encoder, value.borderColor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceShareInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.spaceCount);
    encoder->EncodeOpenXrHandleArray<openxr_wrappers::SpaceWrapper>(value.spaces, value.spaceCount);
    encoder->EncodeUInt32Value(value.userCount);
    encoder->EncodeOpenXrHandleArray<openxr_wrappers::SpaceUserFBWrapper>(value.users, value.userCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceShareCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrAsyncRequestIdFBValue(value.requestId);
    encoder->EncodeEnumValue(value.result);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerSpaceWarpInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    EncodeStruct(encoder, value.motionVectorSubImage);
    EncodeStruct(encoder, value.appSpaceDeltaPose);
    EncodeStruct(encoder, value.depthSubImage);
    encoder->EncodeFloatValue(value.minDepth);
    encoder->EncodeFloatValue(value.maxDepth);
    encoder->EncodeFloatValue(value.nearZ);
    encoder->EncodeFloatValue(value.farZ);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemSpaceWarpPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.recommendedMotionVectorImageRectWidth);
    encoder->EncodeUInt32Value(value.recommendedMotionVectorImageRectHeight);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHapticAmplitudeEnvelopeVibrationFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrDurationValue(value.duration);
    encoder->EncodeUInt32Value(value.amplitudeCount);
    encoder->EncodeFloatArray(value.amplitudes, value.amplitudeCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExtent3DfFB& value)
{
    encoder->EncodeFloatValue(value.width);
    encoder->EncodeFloatValue(value.height);
    encoder->EncodeFloatValue(value.depth);
}

void EncodeStruct(ParameterEncoder* encoder, const XrOffset3DfFB& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
    encoder->EncodeFloatValue(value.z);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRect3DfFB& value)
{
    EncodeStruct(encoder, value.offset);
    EncodeStruct(encoder, value.extent);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSemanticLabelsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.bufferCapacityInput);
    encoder->EncodeUInt32Value(value.bufferCountOutput);
    encoder->EncodeStringArray(value.buffer, value.bufferCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRoomLayoutFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.floorUuid);
    EncodeStruct(encoder, value.ceilingUuid);
    encoder->EncodeUInt32Value(value.wallUuidCapacityInput);
    encoder->EncodeUInt32Value(value.wallUuidCountOutput);
    EncodeStructArray(encoder, value.wallUuids, value.wallUuidCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBoundary2DFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSemanticLabelsSupportInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeString(value.recognizedLabels);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDigitalLensControlALMALENCE& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSceneCaptureCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrAsyncRequestIdFBValue(value.requestId);
    encoder->EncodeEnumValue(value.result);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneCaptureRequestInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.requestByteCount);
    encoder->EncodeStringArray(value.request, value.requestByteCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceContainerFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.uuidCapacityInput);
    encoder->EncodeUInt32Value(value.uuidCountOutput);
    EncodeStructArray(encoder, value.uuids, value.uuidCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationEyeTrackedProfileCreateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationEyeTrackedStateMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStructArray(encoder, value.foveationCenter, XR_FOVEATION_CENTER_SIZE_META);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFoveationEyeTrackedPropertiesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsFoveationEyeTracked);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFaceTrackingPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsFaceTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceTrackerCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.faceExpressionSet);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionStatusFB& value)
{
    encoder->EncodeXrBool32Value(value.isValid);
    encoder->EncodeXrBool32Value(value.isEyeFollowingBlendshapesValid);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionWeightsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.weightCount);
    encoder->EncodeFloatArray(value.weights, value.weightCount);
    encoder->EncodeUInt32Value(value.confidenceCount);
    encoder->EncodeFloatArray(value.confidences, value.confidenceCount);
    EncodeStruct(encoder, value.status);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazeFB& value)
{
    encoder->EncodeXrBool32Value(value.isValid);
    EncodeStruct(encoder, value.gazePose);
    encoder->EncodeFloatValue(value.gazeConfidence);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEyeTrackerCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazesInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemEyeTrackingPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsEyeTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStructArray(encoder, value.gaze, XR_EYE_POSITION_COUNT_FB);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughKeyboardHandsIntensityFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.leftHandIntensity);
    encoder->EncodeFloatValue(value.rightHandIntensity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerSettingsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHapticPcmVibrationFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.bufferSize);
    encoder->EncodeFloatArray(value.buffer, value.bufferSize);
    encoder->EncodeFloatValue(value.sampleRate);
    encoder->EncodeXrBool32Value(value.append);
    encoder->EncodeUInt32Ptr(value.samplesConsumed);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDevicePcmSampleRateStateFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.sampleRate);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerDepthTestFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.depthMask);
    encoder->EncodeEnumValue(value.compareOp);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLocalDimmingFrameEndInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.localDimmingMode);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughPreferencesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemVirtualKeyboardPropertiesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsVirtualKeyboard);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardCreateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardSpaceCreateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.locationType);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.poseInSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardLocationInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.locationType);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.poseInSpace);
    encoder->EncodeFloatValue(value.scale);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardModelVisibilitySetInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.visible);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardAnimationStateMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeInt32Value(value.animationIndex);
    encoder->EncodeFloatValue(value.fraction);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardModelAnimationStatesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.stateCapacityInput);
    encoder->EncodeUInt32Value(value.stateCountOutput);
    EncodeStructArray(encoder, value.states, value.stateCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardTextureDataMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.textureWidth);
    encoder->EncodeUInt32Value(value.textureHeight);
    encoder->EncodeUInt32Value(value.bufferCapacityInput);
    encoder->EncodeUInt32Value(value.bufferCountOutput);
    encoder->EncodeUInt8Array(value.buffer, value.bufferCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardInputInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.inputSource);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.inputSpace);
    EncodeStruct(encoder, value.inputPoseInSpace);
    encoder->EncodeFlags64Value(value.inputState);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardTextContextChangeInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeString(value.textContext);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardCommitTextMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(value.keyboard);
    encoder->EncodeString(value.text);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardBackspaceMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(value.keyboard);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardEnterMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(value.keyboard);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardShownMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(value.keyboard);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardHiddenMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(value.keyboard);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExternalCameraIntrinsicsOCULUS& value)
{
    encoder->EncodeXrTimeValue(value.lastChangeTime);
    EncodeStruct(encoder, value.fov);
    encoder->EncodeFloatValue(value.virtualNearPlaneDistance);
    encoder->EncodeFloatValue(value.virtualFarPlaneDistance);
    EncodeStruct(encoder, value.imageSensorPixelResolution);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExternalCameraExtrinsicsOCULUS& value)
{
    encoder->EncodeXrTimeValue(value.lastChangeTime);
    encoder->EncodeFlags64Value(value.cameraStatusFlags);
    encoder->EncodeEnumValue(value.attachedToDevice);
    EncodeStruct(encoder, value.relativePose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExternalCameraOCULUS& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeString(value.name);
    EncodeStruct(encoder, value.intrinsics);
    EncodeStruct(encoder, value.extrinsics);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanSwapchainCreateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeVkImageCreateFlagsValue(value.additionalCreateFlags);
    encoder->EncodeVkImageUsageFlagsValue(value.additionalUsageFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPerformanceMetricsStateMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.enabled);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPerformanceMetricsCounterMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.counterFlags);
    encoder->EncodeEnumValue(value.counterUnit);
    encoder->EncodeUInt32Value(value.uintValue);
    encoder->EncodeFloatValue(value.floatValue);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceListSaveInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.spaceCount);
    encoder->EncodeOpenXrHandleArray<openxr_wrappers::SpaceWrapper>(value.spaces, value.spaceCount);
    encoder->EncodeEnumValue(value.location);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceListSaveCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrAsyncRequestIdFBValue(value.requestId);
    encoder->EncodeEnumValue(value.result);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceUserCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrSpaceUserIdFBValue(value.userId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemHeadsetIdPropertiesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.id);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRecommendedLayerResolutionMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.recommendedImageDimensions);
    encoder->EncodeXrBool32Value(value.isValid);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRecommendedLayerResolutionGetInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStructPtr(encoder, value.layer);
    encoder->EncodeXrTimeValue(value.predictedDisplayTime);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorLutDataMETA& value)
{
    encoder->EncodeUInt32Value(value.bufferSize);
    encoder->EncodeUInt8Array(value.buffer, value.bufferSize);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorLutCreateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.channels);
    encoder->EncodeUInt32Value(value.resolution);
    EncodeStruct(encoder, value.data);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorLutUpdateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    EncodeStruct(encoder, value.data);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapLutMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughColorLutMETAWrapper>(value.colorLut);
    encoder->EncodeFloatValue(value.weight);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapInterpolatedLutMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughColorLutMETAWrapper>(value.sourceColorLut);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughColorLutMETAWrapper>(value.targetColorLut);
    encoder->EncodeFloatValue(value.weight);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemPassthroughColorLutPropertiesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.maxColorLutResolution);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceTriangleMeshGetInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceTriangleMeshMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeUInt32Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFaceTrackingProperties2FB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsVisualFaceTracking);
    encoder->EncodeXrBool32Value(value.supportsAudioFaceTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceTrackerCreateInfo2FB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.faceExpressionSet);
    encoder->EncodeUInt32Value(value.requestedDataSourceCount);
    encoder->EncodeEnumArray(value.requestedDataSources, value.requestedDataSourceCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionInfo2FB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionWeights2FB& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.weightCount);
    encoder->EncodeFloatArray(value.weights, value.weightCount);
    encoder->EncodeUInt32Value(value.confidenceCount);
    encoder->EncodeFloatArray(value.confidences, value.confidenceCount);
    encoder->EncodeXrBool32Value(value.isValid);
    encoder->EncodeXrBool32Value(value.isEyeFollowingBlendshapesValid);
    encoder->EncodeEnumValue(value.dataSource);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughCreateInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.form);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFloatValue(value.alpha);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughMeshTransformInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.vertexCount);
    EncodeStructArray(encoder, value.vertices, value.vertexCount);
    encoder->EncodeUInt32Value(value.indexCount);
    encoder->EncodeUInt32Array(value.indices, value.indexCount);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeXrTimeValue(value.time);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.scale);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerPassthroughHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughHTCWrapper>(value.passthrough);
    EncodeStruct(encoder, value.color);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationApplyInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.mode);
    encoder->EncodeUInt32Value(value.subImageCount);
    EncodeStructArray(encoder, value.subImages, value.subImageCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationConfigurationHTC& value)
{
    encoder->EncodeEnumValue(value.level);
    encoder->EncodeFloatValue(value.clearFovDegree);
    EncodeStruct(encoder, value.focalCenterOffset);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationDynamicModeInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.dynamicFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationCustomModeInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.configCount);
    EncodeStructArray(encoder, value.configs, value.configCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemAnchorPropertiesHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsAnchor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorNameHTC& value)
{
    encoder->EncodeString(value.name);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorCreateInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.poseInSpace);
    EncodeStruct(encoder, value.name);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActiveActionSetPriorityEXT& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionSetWrapper>(value.actionSet);
    encoder->EncodeUInt32Value(value.priorityOverride);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActiveActionSetPrioritiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.actionSetPriorityCount);
    EncodeStructArray(encoder, value.actionSetPriorities, value.actionSetPriorityCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemForceFeedbackCurlPropertiesMNDX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsForceFeedbackCurl);
}

void EncodeStruct(ParameterEncoder* encoder, const XrForceFeedbackCurlApplyLocationMNDX& value)
{
    encoder->EncodeEnumValue(value.location);
    encoder->EncodeFloatValue(value.value);
}

void EncodeStruct(ParameterEncoder* encoder, const XrForceFeedbackCurlApplyLocationsMNDX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.locationCount);
    EncodeStructArray(encoder, value.locations, value.locationCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingDataSourceInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.requestedDataSourceCount);
    encoder->EncodeEnumArray(value.requestedDataSources, value.requestedDataSourceCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingDataSourceStateEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.isActive);
    encoder->EncodeEnumValue(value.dataSource);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemPlaneDetectionPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.supportedFeatures);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExtent3DfEXT& value)
{
    encoder->EncodeFloatValue(value.width);
    encoder->EncodeFloatValue(value.height);
    encoder->EncodeFloatValue(value.depth);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorBeginInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeXrTimeValue(value.time);
    encoder->EncodeUInt32Value(value.orientationCount);
    encoder->EncodeEnumArray(value.orientations, value.orientationCount);
    encoder->EncodeUInt32Value(value.semanticTypeCount);
    encoder->EncodeEnumArray(value.semanticTypes, value.semanticTypeCount);
    encoder->EncodeUInt32Value(value.maxPlanes);
    encoder->EncodeFloatValue(value.minArea);
    EncodeStruct(encoder, value.boundingBoxPose);
    EncodeStruct(encoder, value.boundingBoxExtent);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorGetInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorLocationEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt64Value(value.planeId);
    encoder->EncodeFlags64Value(value.locationFlags);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.extents);
    encoder->EncodeEnumValue(value.orientation);
    encoder->EncodeEnumValue(value.semanticType);
    encoder->EncodeUInt32Value(value.polygonBufferCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorLocationsEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.planeLocationCapacityInput);
    encoder->EncodeUInt32Value(value.planeLocationCountOutput);
    EncodeStructArray(encoder, value.planeLocations, value.planeLocationCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorPolygonBufferEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataUserPresenceChangedEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
    encoder->EncodeXrBool32Value(value.isUserPresent);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemUserPresencePropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.supportsUserPresence);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataHeadsetFitChangedML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.status);
    encoder->EncodeXrTimeValue(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataEyeCalibrationChangedML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeEnumValue(value.status);
}

void EncodeStruct(ParameterEncoder* encoder, const XrUserCalibrationEnableEventsInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeVoidPtr(value.next);
    encoder->EncodeXrBool32Value(value.enabled);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
