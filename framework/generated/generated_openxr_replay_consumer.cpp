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

#include "decode/custom_openxr_struct_handle_mappers.h"
#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/openxr_handle_mapping_util.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "generated/generated_openxr_dispatch_table.h"
#include "generated/generated_openxr_replay_consumer.h"
#include "generated/generated_openxr_struct_handle_mappers.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
void InitializeOutputStructNext(StructPointerDecoder<T> *decoder);

void OpenXrReplayConsumer::Process_xrDestroyInstance(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);

    XrResult replay_result = GetInstanceTable(in_instance)->DestroyInstance(in_instance);
    CheckResult("xrDestroyInstance", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyInstance>::UpdateState(this, call_info, returnValue, instance, replay_result);
    RemoveHandle(instance, &CommonObjectInfoTable::RemoveXrInstanceInfo);
}

void OpenXrReplayConsumer::Process_xrGetInstanceProperties(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrInstanceProperties>* instanceProperties)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrInstanceProperties* out_instanceProperties = instanceProperties->IsNull() ? nullptr : instanceProperties->AllocateOutputData(1, { XR_TYPE_INSTANCE_PROPERTIES, nullptr });
    InitializeOutputStructNext(instanceProperties);

    XrResult replay_result = GetInstanceTable(in_instance)->GetInstanceProperties(in_instance, out_instanceProperties);
    CheckResult("xrGetInstanceProperties", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetInstanceProperties>::UpdateState(this, call_info, returnValue, instance, instanceProperties, replay_result);
}

void OpenXrReplayConsumer::Process_xrResultToString(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrResult                                    value,
    StringDecoder*                              buffer)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    char* out_buffer = buffer->GetPointer();

    XrResult replay_result = GetInstanceTable(in_instance)->ResultToString(in_instance, value, out_buffer);
    CheckResult("xrResultToString", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrResultToString>::UpdateState(this, call_info, returnValue, instance, value, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrStructureTypeToString(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrStructureType                             value,
    StringDecoder*                              buffer)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    char* out_buffer = buffer->GetPointer();

    XrResult replay_result = GetInstanceTable(in_instance)->StructureTypeToString(in_instance, value, out_buffer);
    CheckResult("xrStructureTypeToString", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrStructureTypeToString>::UpdateState(this, call_info, returnValue, instance, value, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSystem(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrSystemGetInfo>* getInfo,
    HandlePointerDecoder<XrSystemId>*           systemId)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const XrSystemGetInfo* in_getInfo = getInfo->GetPointer();
    if (!systemId->IsNull()) { systemId->SetHandleLength(1); }
    XrSystemId* out_systemId = systemId->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_instance)->GetSystem(in_instance, in_getInfo, out_systemId);
    CheckResult("xrGetSystem", returnValue, replay_result, call_info);

    AddHandle<OpenXrSystemIdInfo>(instance, systemId->GetPointer(), out_systemId, &CommonObjectInfoTable::AddXrSystemIdInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSystem>::UpdateState(this, call_info, returnValue, instance, getInfo, systemId, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSystemProperties(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrSystemProperties>* properties)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    XrSystemProperties* out_properties = properties->IsNull() ? nullptr : properties->AllocateOutputData(1, { XR_TYPE_SYSTEM_PROPERTIES, nullptr });
    InitializeOutputStructNext(properties);

    XrResult replay_result = GetInstanceTable(in_instance)->GetSystemProperties(in_instance, in_systemId, out_properties);
    CheckResult("xrGetSystemProperties", returnValue, replay_result, call_info);

    AddStructHandles(instance, properties->GetMetaStructPointer(), out_properties, &GetObjectInfoTable());
    CustomProcess<format::ApiCallId::ApiCall_xrGetSystemProperties>::UpdateState(this, call_info, returnValue, instance, systemId, properties, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateEnvironmentBlendModes(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    environmentBlendModeCapacityInput,
    PointerDecoder<uint32_t>*                   environmentBlendModeCountOutput,
    PointerDecoder<XrEnvironmentBlendMode>*     environmentBlendModes)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    uint32_t* out_environmentBlendModeCountOutput = environmentBlendModeCountOutput->IsNull() ? nullptr : environmentBlendModeCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrEnvironmentBlendMode* out_environmentBlendModes = environmentBlendModes->IsNull() ? nullptr : environmentBlendModes->AllocateOutputData(environmentBlendModeCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!environmentBlendModes->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_instance)->EnumerateEnvironmentBlendModes(in_instance, in_systemId, viewConfigurationType, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < environmentBlendModeCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrEnumerateEnvironmentBlendModes replay size %d is smaller than capture size %d",
                replay_count,
                environmentBlendModeCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<XrEnvironmentBlendMode> temp_environmentBlendModes(replay_count);
        replay_result = GetInstanceTable(in_instance)->EnumerateEnvironmentBlendModes(in_instance, in_systemId, viewConfigurationType, temp_environmentBlendModes.size(), out_environmentBlendModeCountOutput, temp_environmentBlendModes.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            XrEnvironmentBlendMode* original_environmentBlendModes = environmentBlendModes->GetPointer();
            for (uint32_t iii = 0; iii < environmentBlendModeCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_environmentBlendModes[jjj] == original_environmentBlendModes[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrEnumerateEnvironmentBlendModes failed to find a value of %d during replay",
                        original_environmentBlendModes[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_instance)->EnumerateEnvironmentBlendModes(in_instance, in_systemId, viewConfigurationType, environmentBlendModeCapacityInput, out_environmentBlendModeCountOutput, out_environmentBlendModes);
    }
    CheckResult("xrEnumerateEnvironmentBlendModes", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateEnvironmentBlendModes>::UpdateState(this, call_info, returnValue, instance, systemId, viewConfigurationType, environmentBlendModeCapacityInput, environmentBlendModeCountOutput, environmentBlendModes, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrSessionCreateInfo>* createInfo,
    HandlePointerDecoder<XrSession>*            session)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const XrSessionCreateInfo* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!session->IsNull()) { session->SetHandleLength(1); }
    XrSession* out_session = session->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_instance)->CreateSession(in_instance, in_createInfo, out_session);
    CheckResult("xrCreateSession", returnValue, replay_result, call_info);

    AddHandle<OpenXrSessionInfo>(instance, session->GetPointer(), out_session, &CommonObjectInfoTable::AddXrSessionInfo);
    
    AssociateParent(*out_session, in_instance);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSession>::UpdateState(this, call_info, returnValue, instance, createInfo, session, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroySession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->DestroySession(in_session);
    CheckResult("xrDestroySession", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroySession>::UpdateState(this, call_info, returnValue, session, replay_result);
    RemoveHandle(session, &CommonObjectInfoTable::RemoveXrSessionInfo);
}

void OpenXrReplayConsumer::Process_xrEnumerateReferenceSpaces(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    spaceCapacityInput,
    PointerDecoder<uint32_t>*                   spaceCountOutput,
    PointerDecoder<XrReferenceSpaceType>*       spaces)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    uint32_t* out_spaceCountOutput = spaceCountOutput->IsNull() ? nullptr : spaceCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrReferenceSpaceType* out_spaces = spaces->IsNull() ? nullptr : spaces->AllocateOutputData(spaceCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!spaces->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_session)->EnumerateReferenceSpaces(in_session, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < spaceCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrEnumerateReferenceSpaces replay size %d is smaller than capture size %d",
                replay_count,
                spaceCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<XrReferenceSpaceType> temp_spaces(replay_count);
        replay_result = GetInstanceTable(in_session)->EnumerateReferenceSpaces(in_session, temp_spaces.size(), out_spaceCountOutput, temp_spaces.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            XrReferenceSpaceType* original_spaces = spaces->GetPointer();
            for (uint32_t iii = 0; iii < spaceCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_spaces[jjj] == original_spaces[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrEnumerateReferenceSpaces failed to find a value of %d during replay",
                        original_spaces[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_session)->EnumerateReferenceSpaces(in_session, spaceCapacityInput, out_spaceCountOutput, out_spaces);
    }
    CheckResult("xrEnumerateReferenceSpaces", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateReferenceSpaces>::UpdateState(this, call_info, returnValue, session, spaceCapacityInput, spaceCountOutput, spaces, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateReferenceSpace(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrReferenceSpaceCreateInfo>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrReferenceSpaceCreateInfo* in_createInfo = createInfo->GetPointer();
    if (!space->IsNull()) { space->SetHandleLength(1); }
    XrSpace* out_space = space->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateReferenceSpace(in_session, in_createInfo, out_space);
    CheckResult("xrCreateReferenceSpace", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(session, space->GetPointer(), out_space, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_space, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateReferenceSpace>::UpdateState(this, call_info, returnValue, session, createInfo, space, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetReferenceSpaceBoundsRect(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrReferenceSpaceType                        referenceSpaceType,
    StructPointerDecoder<Decoded_XrExtent2Df>*  bounds)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrExtent2Df* out_bounds = bounds->IsNull() ? nullptr : bounds->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_session)->GetReferenceSpaceBoundsRect(in_session, referenceSpaceType, out_bounds);
    CheckResult("xrGetReferenceSpaceBoundsRect", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetReferenceSpaceBoundsRect>::UpdateState(this, call_info, returnValue, session, referenceSpaceType, bounds, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateActionSpace(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionSpaceCreateInfo>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrActionSpaceCreateInfo* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!space->IsNull()) { space->SetHandleLength(1); }
    XrSpace* out_space = space->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateActionSpace(in_session, in_createInfo, out_space);
    CheckResult("xrCreateActionSpace", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(session, space->GetPointer(), out_space, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_space, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateActionSpace>::UpdateState(this, call_info, returnValue, session, createInfo, space, replay_result);
}

void OpenXrReplayConsumer::Process_xrLocateSpace(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    format::HandleId                            baseSpace,
    XrTime                                      time,
    StructPointerDecoder<Decoded_XrSpaceLocation>* location)
{
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrSpace in_baseSpace = MapHandle<OpenXrSpaceInfo>(baseSpace, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrSpaceLocation* out_location = location->IsNull() ? nullptr : location->AllocateOutputData(1, { XR_TYPE_SPACE_LOCATION, nullptr });
    InitializeOutputStructNext(location);

    XrResult replay_result = GetInstanceTable(in_space)->LocateSpace(in_space, in_baseSpace, time, out_location);
    CheckResult("xrLocateSpace", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrLocateSpace>::UpdateState(this, call_info, returnValue, space, baseSpace, time, location, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroySpace(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space)
{
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);

    XrResult replay_result = GetInstanceTable(in_space)->DestroySpace(in_space);
    CheckResult("xrDestroySpace", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroySpace>::UpdateState(this, call_info, returnValue, space, replay_result);
    RemoveHandle(space, &CommonObjectInfoTable::RemoveXrSpaceInfo);
}

void OpenXrReplayConsumer::Process_xrEnumerateViewConfigurations(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    uint32_t                                    viewConfigurationTypeCapacityInput,
    PointerDecoder<uint32_t>*                   viewConfigurationTypeCountOutput,
    PointerDecoder<XrViewConfigurationType>*    viewConfigurationTypes)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    uint32_t* out_viewConfigurationTypeCountOutput = viewConfigurationTypeCountOutput->IsNull() ? nullptr : viewConfigurationTypeCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrViewConfigurationType* out_viewConfigurationTypes = viewConfigurationTypes->IsNull() ? nullptr : viewConfigurationTypes->AllocateOutputData(viewConfigurationTypeCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!viewConfigurationTypes->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_instance)->EnumerateViewConfigurations(in_instance, in_systemId, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < viewConfigurationTypeCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrEnumerateViewConfigurations replay size %d is smaller than capture size %d",
                replay_count,
                viewConfigurationTypeCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<XrViewConfigurationType> temp_viewConfigurationTypes(replay_count);
        replay_result = GetInstanceTable(in_instance)->EnumerateViewConfigurations(in_instance, in_systemId, temp_viewConfigurationTypes.size(), out_viewConfigurationTypeCountOutput, temp_viewConfigurationTypes.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            XrViewConfigurationType* original_viewConfigurationTypes = viewConfigurationTypes->GetPointer();
            for (uint32_t iii = 0; iii < viewConfigurationTypeCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_viewConfigurationTypes[jjj] == original_viewConfigurationTypes[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrEnumerateViewConfigurations failed to find a value of %d during replay",
                        original_viewConfigurationTypes[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_instance)->EnumerateViewConfigurations(in_instance, in_systemId, viewConfigurationTypeCapacityInput, out_viewConfigurationTypeCountOutput, out_viewConfigurationTypes);
    }
    CheckResult("xrEnumerateViewConfigurations", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateViewConfigurations>::UpdateState(this, call_info, returnValue, instance, systemId, viewConfigurationTypeCapacityInput, viewConfigurationTypeCountOutput, viewConfigurationTypes, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetViewConfigurationProperties(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    XrViewConfigurationType                     viewConfigurationType,
    StructPointerDecoder<Decoded_XrViewConfigurationProperties>* configurationProperties)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    XrViewConfigurationProperties* out_configurationProperties = configurationProperties->IsNull() ? nullptr : configurationProperties->AllocateOutputData(1, { XR_TYPE_VIEW_CONFIGURATION_PROPERTIES, nullptr });
    InitializeOutputStructNext(configurationProperties);

    XrResult replay_result = GetInstanceTable(in_instance)->GetViewConfigurationProperties(in_instance, in_systemId, viewConfigurationType, out_configurationProperties);
    CheckResult("xrGetViewConfigurationProperties", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetViewConfigurationProperties>::UpdateState(this, call_info, returnValue, instance, systemId, viewConfigurationType, configurationProperties, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateViewConfigurationViews(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewCapacityInput,
    PointerDecoder<uint32_t>*                   viewCountOutput,
    StructPointerDecoder<Decoded_XrViewConfigurationView>* views)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    uint32_t* out_viewCountOutput = viewCountOutput->IsNull() ? nullptr : viewCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrViewConfigurationView* out_views = views->IsNull() ? nullptr : views->AllocateOutputData(viewCapacityInput, XrViewConfigurationView{ XR_TYPE_VIEW_CONFIGURATION_VIEW, nullptr });

    XrResult replay_result = GetInstanceTable(in_instance)->EnumerateViewConfigurationViews(in_instance, in_systemId, viewConfigurationType, viewCapacityInput, out_viewCountOutput, out_views);
    CheckResult("xrEnumerateViewConfigurationViews", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateViewConfigurationViews>::UpdateState(this, call_info, returnValue, instance, systemId, viewConfigurationType, viewCapacityInput, viewCountOutput, views, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateSwapchainFormats(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    formatCapacityInput,
    PointerDecoder<uint32_t>*                   formatCountOutput,
    PointerDecoder<int64_t>*                    formats)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    uint32_t* out_formatCountOutput = formatCountOutput->IsNull() ? nullptr : formatCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    int64_t* out_formats = formats->IsNull() ? nullptr : formats->AllocateOutputData(formatCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!formats->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_session)->EnumerateSwapchainFormats(in_session, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < formatCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrEnumerateSwapchainFormats replay size %d is smaller than capture size %d",
                replay_count,
                formatCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<int64_t> temp_formats(replay_count);
        replay_result = GetInstanceTable(in_session)->EnumerateSwapchainFormats(in_session, temp_formats.size(), out_formatCountOutput, temp_formats.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            int64_t* original_formats = formats->GetPointer();
            for (uint32_t iii = 0; iii < formatCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_formats[jjj] == original_formats[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrEnumerateSwapchainFormats failed to find a value of %d during replay",
                        original_formats[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_session)->EnumerateSwapchainFormats(in_session, formatCapacityInput, out_formatCountOutput, out_formats);
    }
    CheckResult("xrEnumerateSwapchainFormats", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateSwapchainFormats>::UpdateState(this, call_info, returnValue, session, formatCapacityInput, formatCountOutput, formats, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroySwapchain(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain)
{
    XrSwapchain in_swapchain = MapHandle<OpenXrSwapchainInfo>(swapchain, &CommonObjectInfoTable::GetXrSwapchainInfo);

    XrResult replay_result = GetInstanceTable(in_swapchain)->DestroySwapchain(in_swapchain);
    CheckResult("xrDestroySwapchain", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroySwapchain>::UpdateState(this, call_info, returnValue, swapchain, replay_result);
    RemoveHandle(swapchain, &CommonObjectInfoTable::RemoveXrSwapchainInfo);
}

void OpenXrReplayConsumer::Process_xrEnumerateSwapchainImages(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    uint32_t                                    imageCapacityInput,
    PointerDecoder<uint32_t>*                   imageCountOutput,
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images)
{
    XrSwapchain in_swapchain = MapHandle<OpenXrSwapchainInfo>(swapchain, &CommonObjectInfoTable::GetXrSwapchainInfo);
    uint32_t* out_imageCountOutput = imageCountOutput->IsNull() ? nullptr : imageCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrSwapchainImageBaseHeader* out_images = images->IsNull() ? nullptr : images->AllocateOutputData(imageCapacityInput);

    XrResult replay_result = GetInstanceTable(in_swapchain)->EnumerateSwapchainImages(in_swapchain, imageCapacityInput, out_imageCountOutput, out_images);
    CheckResult("xrEnumerateSwapchainImages", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateSwapchainImages>::UpdateState(this, call_info, returnValue, swapchain, imageCapacityInput, imageCountOutput, images, replay_result);
}

void OpenXrReplayConsumer::Process_xrAcquireSwapchainImage(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageAcquireInfo>* acquireInfo,
    PointerDecoder<uint32_t>*                   index)
{
    XrSwapchain in_swapchain = MapHandle<OpenXrSwapchainInfo>(swapchain, &CommonObjectInfoTable::GetXrSwapchainInfo);
    const XrSwapchainImageAcquireInfo* in_acquireInfo = acquireInfo->GetPointer();
    uint32_t* out_index = index->IsNull() ? nullptr : index->AllocateOutputData(1, static_cast<uint32_t>(0));

    XrResult replay_result = GetInstanceTable(in_swapchain)->AcquireSwapchainImage(in_swapchain, in_acquireInfo, out_index);
    CheckResult("xrAcquireSwapchainImage", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrAcquireSwapchainImage>::UpdateState(this, call_info, returnValue, swapchain, acquireInfo, index, replay_result);
}

void OpenXrReplayConsumer::Process_xrWaitSwapchainImage(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainImageWaitInfo>* waitInfo)
{
    XrSwapchain in_swapchain = MapHandle<OpenXrSwapchainInfo>(swapchain, &CommonObjectInfoTable::GetXrSwapchainInfo);
    const XrSwapchainImageWaitInfo* in_waitInfo = waitInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_swapchain)->WaitSwapchainImage(in_swapchain, in_waitInfo);
    CheckResult("xrWaitSwapchainImage", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrWaitSwapchainImage>::UpdateState(this, call_info, returnValue, swapchain, waitInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrBeginSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSessionBeginInfo>* beginInfo)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSessionBeginInfo* in_beginInfo = beginInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_session)->BeginSession(in_session, in_beginInfo);
    CheckResult("xrBeginSession", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrBeginSession>::UpdateState(this, call_info, returnValue, session, beginInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrEndSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->EndSession(in_session);
    CheckResult("xrEndSession", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEndSession>::UpdateState(this, call_info, returnValue, session, replay_result);
}

void OpenXrReplayConsumer::Process_xrRequestExitSession(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->RequestExitSession(in_session);
    CheckResult("xrRequestExitSession", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrRequestExitSession>::UpdateState(this, call_info, returnValue, session, replay_result);
}

void OpenXrReplayConsumer::Process_xrWaitFrame(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFrameWaitInfo>* frameWaitInfo,
    StructPointerDecoder<Decoded_XrFrameState>* frameState)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrFrameWaitInfo* in_frameWaitInfo = frameWaitInfo->GetPointer();
    XrFrameState* out_frameState = frameState->IsNull() ? nullptr : frameState->AllocateOutputData(1, { XR_TYPE_FRAME_STATE, nullptr });
    InitializeOutputStructNext(frameState);

    XrResult replay_result = GetInstanceTable(in_session)->WaitFrame(in_session, in_frameWaitInfo, out_frameState);
    CheckResult("xrWaitFrame", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrWaitFrame>::UpdateState(this, call_info, returnValue, session, frameWaitInfo, frameState, replay_result);
}

void OpenXrReplayConsumer::Process_xrBeginFrame(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFrameBeginInfo>* frameBeginInfo)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrFrameBeginInfo* in_frameBeginInfo = frameBeginInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_session)->BeginFrame(in_session, in_frameBeginInfo);
    CheckResult("xrBeginFrame", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrBeginFrame>::UpdateState(this, call_info, returnValue, session, frameBeginInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrLocateViews(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrViewLocateInfo>* viewLocateInfo,
    StructPointerDecoder<Decoded_XrViewState>*  viewState,
    uint32_t                                    viewCapacityInput,
    PointerDecoder<uint32_t>*                   viewCountOutput,
    StructPointerDecoder<Decoded_XrView>*       views)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrViewLocateInfo* in_viewLocateInfo = viewLocateInfo->GetPointer();
    MapStructHandles(viewLocateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrViewState* out_viewState = viewState->IsNull() ? nullptr : viewState->AllocateOutputData(1, { XR_TYPE_VIEW_STATE, nullptr });
    InitializeOutputStructNext(viewState);
    uint32_t* out_viewCountOutput = viewCountOutput->IsNull() ? nullptr : viewCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrView* out_views = views->IsNull() ? nullptr : views->AllocateOutputData(viewCapacityInput, XrView{ XR_TYPE_VIEW, nullptr });

    XrResult replay_result = GetInstanceTable(in_session)->LocateViews(in_session, in_viewLocateInfo, out_viewState, viewCapacityInput, out_viewCountOutput, out_views);
    CheckResult("xrLocateViews", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrLocateViews>::UpdateState(this, call_info, returnValue, session, viewLocateInfo, viewState, viewCapacityInput, viewCountOutput, views, replay_result);
}

void OpenXrReplayConsumer::Process_xrStringToPath(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StringDecoder*                              pathString,
    HandlePointerDecoder<XrPath>*               path)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const char* in_pathString = pathString->GetPointer();
    if (!path->IsNull()) { path->SetHandleLength(1); }
    XrPath* out_path = path->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_instance)->StringToPath(in_instance, in_pathString, out_path);
    CheckResult("xrStringToPath", returnValue, replay_result, call_info);

    AddHandle<OpenXrPathInfo>(instance, path->GetPointer(), out_path, &CommonObjectInfoTable::AddXrPathInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrStringToPath>::UpdateState(this, call_info, returnValue, instance, pathString, path, replay_result);
}

void OpenXrReplayConsumer::Process_xrPathToString(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            path,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrPath in_path = MapHandle<OpenXrPathInfo>(path, &CommonObjectInfoTable::GetXrPathInfo);
    uint32_t* out_bufferCountOutput = bufferCountOutput->IsNull() ? nullptr : bufferCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    char* out_buffer = buffer->GetPointer();

    XrResult replay_result = GetInstanceTable(in_instance)->PathToString(in_instance, in_path, bufferCapacityInput, out_bufferCountOutput, out_buffer);
    CheckResult("xrPathToString", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrPathToString>::UpdateState(this, call_info, returnValue, instance, path, bufferCapacityInput, bufferCountOutput, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateActionSet(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrActionSetCreateInfo>* createInfo,
    HandlePointerDecoder<XrActionSet>*          actionSet)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const XrActionSetCreateInfo* in_createInfo = createInfo->GetPointer();
    if (!actionSet->IsNull()) { actionSet->SetHandleLength(1); }
    XrActionSet* out_actionSet = actionSet->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_instance)->CreateActionSet(in_instance, in_createInfo, out_actionSet);
    CheckResult("xrCreateActionSet", returnValue, replay_result, call_info);

    AddHandle<OpenXrActionSetInfo>(instance, actionSet->GetPointer(), out_actionSet, &CommonObjectInfoTable::AddXrActionSetInfo);
    
    AssociateParent(*out_actionSet, in_instance);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateActionSet>::UpdateState(this, call_info, returnValue, instance, createInfo, actionSet, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyActionSet(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            actionSet)
{
    XrActionSet in_actionSet = MapHandle<OpenXrActionSetInfo>(actionSet, &CommonObjectInfoTable::GetXrActionSetInfo);

    XrResult replay_result = GetInstanceTable(in_actionSet)->DestroyActionSet(in_actionSet);
    CheckResult("xrDestroyActionSet", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyActionSet>::UpdateState(this, call_info, returnValue, actionSet, replay_result);
    RemoveHandle(actionSet, &CommonObjectInfoTable::RemoveXrActionSetInfo);
}

void OpenXrReplayConsumer::Process_xrCreateAction(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            actionSet,
    StructPointerDecoder<Decoded_XrActionCreateInfo>* createInfo,
    HandlePointerDecoder<XrAction>*             action)
{
    XrActionSet in_actionSet = MapHandle<OpenXrActionSetInfo>(actionSet, &CommonObjectInfoTable::GetXrActionSetInfo);
    const XrActionCreateInfo* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!action->IsNull()) { action->SetHandleLength(1); }
    XrAction* out_action = action->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_actionSet)->CreateAction(in_actionSet, in_createInfo, out_action);
    CheckResult("xrCreateAction", returnValue, replay_result, call_info);

    AddHandle<OpenXrActionInfo>(actionSet, action->GetPointer(), out_action, &CommonObjectInfoTable::AddXrActionInfo);
    
    AssociateParent(*out_action, in_actionSet);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateAction>::UpdateState(this, call_info, returnValue, actionSet, createInfo, action, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyAction(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            action)
{
    XrAction in_action = MapHandle<OpenXrActionInfo>(action, &CommonObjectInfoTable::GetXrActionInfo);

    XrResult replay_result = GetInstanceTable(in_action)->DestroyAction(in_action);
    CheckResult("xrDestroyAction", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyAction>::UpdateState(this, call_info, returnValue, action, replay_result);
    RemoveHandle(action, &CommonObjectInfoTable::RemoveXrActionInfo);
}

void OpenXrReplayConsumer::Process_xrSuggestInteractionProfileBindings(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrInteractionProfileSuggestedBinding>* suggestedBindings)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const XrInteractionProfileSuggestedBinding* in_suggestedBindings = suggestedBindings->GetPointer();
    MapStructHandles(suggestedBindings->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_instance)->SuggestInteractionProfileBindings(in_instance, in_suggestedBindings);
    CheckResult("xrSuggestInteractionProfileBindings", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSuggestInteractionProfileBindings>::UpdateState(this, call_info, returnValue, instance, suggestedBindings, replay_result);
}

void OpenXrReplayConsumer::Process_xrAttachSessionActionSets(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSessionActionSetsAttachInfo>* attachInfo)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSessionActionSetsAttachInfo* in_attachInfo = attachInfo->GetPointer();
    MapStructHandles(attachInfo->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_session)->AttachSessionActionSets(in_session, in_attachInfo);
    CheckResult("xrAttachSessionActionSets", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrAttachSessionActionSets>::UpdateState(this, call_info, returnValue, session, attachInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetCurrentInteractionProfile(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelUserPath,
    StructPointerDecoder<Decoded_XrInteractionProfileState>* interactionProfile)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPath in_topLevelUserPath = MapHandle<OpenXrPathInfo>(topLevelUserPath, &CommonObjectInfoTable::GetXrPathInfo);
    XrInteractionProfileState* out_interactionProfile = interactionProfile->IsNull() ? nullptr : interactionProfile->AllocateOutputData(1, { XR_TYPE_INTERACTION_PROFILE_STATE, nullptr });
    InitializeOutputStructNext(interactionProfile);

    XrResult replay_result = GetInstanceTable(in_session)->GetCurrentInteractionProfile(in_session, in_topLevelUserPath, out_interactionProfile);
    CheckResult("xrGetCurrentInteractionProfile", returnValue, replay_result, call_info);

    AddStructHandles(session, interactionProfile->GetMetaStructPointer(), out_interactionProfile, &GetObjectInfoTable());
    CustomProcess<format::ApiCallId::ApiCall_xrGetCurrentInteractionProfile>::UpdateState(this, call_info, returnValue, session, topLevelUserPath, interactionProfile, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetActionStateBoolean(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
    StructPointerDecoder<Decoded_XrActionStateBoolean>* state)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrActionStateGetInfo* in_getInfo = getInfo->GetPointer();
    MapStructHandles(getInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrActionStateBoolean* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1, { XR_TYPE_ACTION_STATE_BOOLEAN, nullptr });
    InitializeOutputStructNext(state);

    XrResult replay_result = GetInstanceTable(in_session)->GetActionStateBoolean(in_session, in_getInfo, out_state);
    CheckResult("xrGetActionStateBoolean", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetActionStateBoolean>::UpdateState(this, call_info, returnValue, session, getInfo, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetActionStateFloat(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
    StructPointerDecoder<Decoded_XrActionStateFloat>* state)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrActionStateGetInfo* in_getInfo = getInfo->GetPointer();
    MapStructHandles(getInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrActionStateFloat* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1, { XR_TYPE_ACTION_STATE_FLOAT, nullptr });
    InitializeOutputStructNext(state);

    XrResult replay_result = GetInstanceTable(in_session)->GetActionStateFloat(in_session, in_getInfo, out_state);
    CheckResult("xrGetActionStateFloat", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetActionStateFloat>::UpdateState(this, call_info, returnValue, session, getInfo, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetActionStateVector2f(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
    StructPointerDecoder<Decoded_XrActionStateVector2f>* state)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrActionStateGetInfo* in_getInfo = getInfo->GetPointer();
    MapStructHandles(getInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrActionStateVector2f* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1, { XR_TYPE_ACTION_STATE_VECTOR2F, nullptr });
    InitializeOutputStructNext(state);

    XrResult replay_result = GetInstanceTable(in_session)->GetActionStateVector2f(in_session, in_getInfo, out_state);
    CheckResult("xrGetActionStateVector2f", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetActionStateVector2f>::UpdateState(this, call_info, returnValue, session, getInfo, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetActionStatePose(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
    StructPointerDecoder<Decoded_XrActionStatePose>* state)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrActionStateGetInfo* in_getInfo = getInfo->GetPointer();
    MapStructHandles(getInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrActionStatePose* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1, { XR_TYPE_ACTION_STATE_POSE, nullptr });
    InitializeOutputStructNext(state);

    XrResult replay_result = GetInstanceTable(in_session)->GetActionStatePose(in_session, in_getInfo, out_state);
    CheckResult("xrGetActionStatePose", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetActionStatePose>::UpdateState(this, call_info, returnValue, session, getInfo, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrSyncActions(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrActionsSyncInfo>* syncInfo)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrActionsSyncInfo* in_syncInfo = syncInfo->GetPointer();
    MapStructHandles(syncInfo->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_session)->SyncActions(in_session, in_syncInfo);
    CheckResult("xrSyncActions", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSyncActions>::UpdateState(this, call_info, returnValue, session, syncInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateBoundSourcesForAction(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrBoundSourcesForActionEnumerateInfo>* enumerateInfo,
    uint32_t                                    sourceCapacityInput,
    PointerDecoder<uint32_t>*                   sourceCountOutput,
    HandlePointerDecoder<XrPath>*               sources)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrBoundSourcesForActionEnumerateInfo* in_enumerateInfo = enumerateInfo->GetPointer();
    MapStructHandles(enumerateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_sourceCountOutput = sourceCountOutput->IsNull() ? nullptr : sourceCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    if (!sources->IsNull()) { sources->SetHandleLength(sourceCapacityInput); }
    XrPath* out_sources = sources->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->EnumerateBoundSourcesForAction(in_session, in_enumerateInfo, sourceCapacityInput, out_sourceCountOutput, out_sources);
    CheckResult("xrEnumerateBoundSourcesForAction", returnValue, replay_result, call_info);

    AddHandles<OpenXrPathInfo>(session, sources->GetPointer(), sources->GetLength(), out_sources, sourceCapacityInput, &CommonObjectInfoTable::AddXrPathInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateBoundSourcesForAction>::UpdateState(this, call_info, returnValue, session, enumerateInfo, sourceCapacityInput, sourceCountOutput, sources, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetInputSourceLocalizedName(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrInputSourceLocalizedNameGetInfo>* getInfo,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrInputSourceLocalizedNameGetInfo* in_getInfo = getInfo->GetPointer();
    MapStructHandles(getInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_bufferCountOutput = bufferCountOutput->IsNull() ? nullptr : bufferCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    char* out_buffer = buffer->GetPointer();

    XrResult replay_result = XR_SUCCESS;
    if (!buffer->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_session)->GetInputSourceLocalizedName(in_session, in_getInfo, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < bufferCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrGetInputSourceLocalizedName replay size %d is smaller than capture size %d",
                replay_count,
                bufferCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<char> temp_buffer(replay_count);
        replay_result = GetInstanceTable(in_session)->GetInputSourceLocalizedName(in_session, in_getInfo, temp_buffer.size(), out_bufferCountOutput, temp_buffer.data());
    }
    else
    {
        replay_result = GetInstanceTable(in_session)->GetInputSourceLocalizedName(in_session, in_getInfo, bufferCapacityInput, out_bufferCountOutput, out_buffer);
    }
    CheckResult("xrGetInputSourceLocalizedName", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetInputSourceLocalizedName>::UpdateState(this, call_info, returnValue, session, getInfo, bufferCapacityInput, bufferCountOutput, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrApplyHapticFeedback(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo,
    StructPointerDecoder<Decoded_XrHapticBaseHeader>* hapticFeedback)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrHapticActionInfo* in_hapticActionInfo = hapticActionInfo->GetPointer();
    MapStructHandles(hapticActionInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const XrHapticBaseHeader* in_hapticFeedback = hapticFeedback->GetPointer();

    XrResult replay_result = GetInstanceTable(in_session)->ApplyHapticFeedback(in_session, in_hapticActionInfo, in_hapticFeedback);
    CheckResult("xrApplyHapticFeedback", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrApplyHapticFeedback>::UpdateState(this, call_info, returnValue, session, hapticActionInfo, hapticFeedback, replay_result);
}

void OpenXrReplayConsumer::Process_xrStopHapticFeedback(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrHapticActionInfo* in_hapticActionInfo = hapticActionInfo->GetPointer();
    MapStructHandles(hapticActionInfo->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_session)->StopHapticFeedback(in_session, in_hapticActionInfo);
    CheckResult("xrStopHapticFeedback", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrStopHapticFeedback>::UpdateState(this, call_info, returnValue, session, hapticActionInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetAndroidApplicationThreadKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrAndroidThreadTypeKHR                      threadType,
    uint32_t                                    threadId)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetAndroidApplicationThreadKHR(in_session, threadType, threadId);
    CheckResult("xrSetAndroidApplicationThreadKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetAndroidApplicationThreadKHR>::UpdateState(this, call_info, returnValue, session, threadType, threadId, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSwapchainAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* info,
    HandlePointerDecoder<XrSwapchain>*          swapchain,
    uint64_t                                    surface)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSwapchainCreateInfo* in_info = info->GetPointer();
    if (!swapchain->IsNull()) { swapchain->SetHandleLength(1); }
    XrSwapchain* out_swapchain = swapchain->GetHandlePointer();
    jobject* in_surface = static_cast<jobject*>(PreProcessExternalObject(surface, format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR, "xrCreateSwapchainAndroidSurfaceKHR"));

    XrResult replay_result = GetInstanceTable(in_session)->CreateSwapchainAndroidSurfaceKHR(in_session, in_info, out_swapchain, in_surface);
    CheckResult("xrCreateSwapchainAndroidSurfaceKHR", returnValue, replay_result, call_info);

    AddHandle<OpenXrSwapchainInfo>(session, swapchain->GetPointer(), out_swapchain, &CommonObjectInfoTable::AddXrSwapchainInfo);
    
    AssociateParent(*out_swapchain, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR>::UpdateState(this, call_info, returnValue, session, info, swapchain, surface, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetOpenGLGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLKHR>* graphicsRequirements)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    XrGraphicsRequirementsOpenGLKHR* out_graphicsRequirements = graphicsRequirements->IsNull() ? nullptr : graphicsRequirements->AllocateOutputData(1, { XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR, nullptr });
    InitializeOutputStructNext(graphicsRequirements);

    XrResult replay_result = GetInstanceTable(in_instance)->GetOpenGLGraphicsRequirementsKHR(in_instance, in_systemId, out_graphicsRequirements);
    CheckResult("xrGetOpenGLGraphicsRequirementsKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetOpenGLGraphicsRequirementsKHR>::UpdateState(this, call_info, returnValue, instance, systemId, graphicsRequirements, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetOpenGLESGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLESKHR>* graphicsRequirements)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    XrGraphicsRequirementsOpenGLESKHR* out_graphicsRequirements = graphicsRequirements->IsNull() ? nullptr : graphicsRequirements->AllocateOutputData(1, { XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR, nullptr });
    InitializeOutputStructNext(graphicsRequirements);

    XrResult replay_result = GetInstanceTable(in_instance)->GetOpenGLESGraphicsRequirementsKHR(in_instance, in_systemId, out_graphicsRequirements);
    CheckResult("xrGetOpenGLESGraphicsRequirementsKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetOpenGLESGraphicsRequirementsKHR>::UpdateState(this, call_info, returnValue, instance, systemId, graphicsRequirements, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVulkanInstanceExtensionsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    uint32_t* out_bufferCountOutput = bufferCountOutput->IsNull() ? nullptr : bufferCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    char* out_buffer = buffer->GetPointer();

    XrResult replay_result = XR_SUCCESS;
    if (!buffer->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_instance)->GetVulkanInstanceExtensionsKHR(in_instance, in_systemId, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < bufferCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrGetVulkanInstanceExtensionsKHR replay size %d is smaller than capture size %d",
                replay_count,
                bufferCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<char> temp_buffer(replay_count);
        replay_result = GetInstanceTable(in_instance)->GetVulkanInstanceExtensionsKHR(in_instance, in_systemId, temp_buffer.size(), out_bufferCountOutput, temp_buffer.data());
    }
    else
    {
        replay_result = GetInstanceTable(in_instance)->GetVulkanInstanceExtensionsKHR(in_instance, in_systemId, bufferCapacityInput, out_bufferCountOutput, out_buffer);
    }
    CheckResult("xrGetVulkanInstanceExtensionsKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVulkanInstanceExtensionsKHR>::UpdateState(this, call_info, returnValue, instance, systemId, bufferCapacityInput, bufferCountOutput, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVulkanDeviceExtensionsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    uint32_t* out_bufferCountOutput = bufferCountOutput->IsNull() ? nullptr : bufferCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    char* out_buffer = buffer->GetPointer();

    XrResult replay_result = XR_SUCCESS;
    if (!buffer->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_instance)->GetVulkanDeviceExtensionsKHR(in_instance, in_systemId, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < bufferCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrGetVulkanDeviceExtensionsKHR replay size %d is smaller than capture size %d",
                replay_count,
                bufferCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<char> temp_buffer(replay_count);
        replay_result = GetInstanceTable(in_instance)->GetVulkanDeviceExtensionsKHR(in_instance, in_systemId, temp_buffer.size(), out_bufferCountOutput, temp_buffer.data());
    }
    else
    {
        replay_result = GetInstanceTable(in_instance)->GetVulkanDeviceExtensionsKHR(in_instance, in_systemId, bufferCapacityInput, out_bufferCountOutput, out_buffer);
    }
    CheckResult("xrGetVulkanDeviceExtensionsKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVulkanDeviceExtensionsKHR>::UpdateState(this, call_info, returnValue, instance, systemId, bufferCapacityInput, bufferCountOutput, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVulkanGraphicsDeviceKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    format::HandleId                            vkInstance,
    HandlePointerDecoder<VkPhysicalDevice>*     vkPhysicalDevice)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    VkInstance in_vkInstance = MapHandle<VulkanInstanceInfo>(vkInstance, &CommonObjectInfoTable::GetVkInstanceInfo);
    if (!vkPhysicalDevice->IsNull()) { vkPhysicalDevice->SetHandleLength(1); }
    VkPhysicalDevice* out_vkPhysicalDevice = vkPhysicalDevice->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_instance)->GetVulkanGraphicsDeviceKHR(in_instance, in_systemId, in_vkInstance, out_vkPhysicalDevice);
    CheckResult("xrGetVulkanGraphicsDeviceKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanPhysicalDeviceInfo>(instance, vkPhysicalDevice->GetPointer(), out_vkPhysicalDevice, &CommonObjectInfoTable::AddVkPhysicalDeviceInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDeviceKHR>::UpdateState(this, call_info, returnValue, instance, systemId, vkInstance, vkPhysicalDevice, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVulkanGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    XrGraphicsRequirementsVulkanKHR* out_graphicsRequirements = graphicsRequirements->IsNull() ? nullptr : graphicsRequirements->AllocateOutputData(1, { XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR, nullptr });
    InitializeOutputStructNext(graphicsRequirements);

    XrResult replay_result = GetInstanceTable(in_instance)->GetVulkanGraphicsRequirementsKHR(in_instance, in_systemId, out_graphicsRequirements);
    CheckResult("xrGetVulkanGraphicsRequirementsKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirementsKHR>::UpdateState(this, call_info, returnValue, instance, systemId, graphicsRequirements, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetD3D11GraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D11KHR>* graphicsRequirements)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    XrGraphicsRequirementsD3D11KHR* out_graphicsRequirements = graphicsRequirements->IsNull() ? nullptr : graphicsRequirements->AllocateOutputData(1, { XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR, nullptr });
    InitializeOutputStructNext(graphicsRequirements);

    XrResult replay_result = GetInstanceTable(in_instance)->GetD3D11GraphicsRequirementsKHR(in_instance, in_systemId, out_graphicsRequirements);
    CheckResult("xrGetD3D11GraphicsRequirementsKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetD3D11GraphicsRequirementsKHR>::UpdateState(this, call_info, returnValue, instance, systemId, graphicsRequirements, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetD3D12GraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D12KHR>* graphicsRequirements)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    XrGraphicsRequirementsD3D12KHR* out_graphicsRequirements = graphicsRequirements->IsNull() ? nullptr : graphicsRequirements->AllocateOutputData(1, { XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR, nullptr });
    InitializeOutputStructNext(graphicsRequirements);

    XrResult replay_result = GetInstanceTable(in_instance)->GetD3D12GraphicsRequirementsKHR(in_instance, in_systemId, out_graphicsRequirements);
    CheckResult("xrGetD3D12GraphicsRequirementsKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetD3D12GraphicsRequirementsKHR>::UpdateState(this, call_info, returnValue, instance, systemId, graphicsRequirements, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetMetalGraphicsRequirementsKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsMetalKHR>* graphicsRequirements)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    XrGraphicsRequirementsMetalKHR* out_graphicsRequirements = graphicsRequirements->IsNull() ? nullptr : graphicsRequirements->AllocateOutputData(1, { XR_TYPE_GRAPHICS_REQUIREMENTS_METAL_KHR, nullptr });
    InitializeOutputStructNext(graphicsRequirements);

    XrResult replay_result = GetInstanceTable(in_instance)->GetMetalGraphicsRequirementsKHR(in_instance, in_systemId, out_graphicsRequirements);
    CheckResult("xrGetMetalGraphicsRequirementsKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetMetalGraphicsRequirementsKHR>::UpdateState(this, call_info, returnValue, instance, systemId, graphicsRequirements, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVisibilityMaskKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewIndex,
    XrVisibilityMaskTypeKHR                     visibilityMaskType,
    StructPointerDecoder<Decoded_XrVisibilityMaskKHR>* visibilityMask)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrVisibilityMaskKHR* out_visibilityMask = visibilityMask->IsNull() ? nullptr : visibilityMask->AllocateOutputData(1, { XR_TYPE_VISIBILITY_MASK_KHR, nullptr });
    InitializeOutputStructNext(visibilityMask);

    XrResult replay_result = GetInstanceTable(in_session)->GetVisibilityMaskKHR(in_session, viewConfigurationType, viewIndex, visibilityMaskType, out_visibilityMask);
    CheckResult("xrGetVisibilityMaskKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVisibilityMaskKHR>::UpdateState(this, call_info, returnValue, session, viewConfigurationType, viewIndex, visibilityMaskType, visibilityMask, replay_result);
}

void OpenXrReplayConsumer::Process_xrConvertWin32PerformanceCounterToTimeKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<LARGE_INTEGER>*              performanceCounter,
    PointerDecoder<XrTime>*                     time)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const LARGE_INTEGER* in_performanceCounter = performanceCounter->GetPointer();
    XrTime* out_time = time->IsNull() ? nullptr : time->AllocateOutputData(1, static_cast<XrTime>(0));

    XrResult replay_result = GetInstanceTable(in_instance)->ConvertWin32PerformanceCounterToTimeKHR(in_instance, in_performanceCounter, out_time);
    CheckResult("xrConvertWin32PerformanceCounterToTimeKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR>::UpdateState(this, call_info, returnValue, instance, performanceCounter, time, replay_result);
}

void OpenXrReplayConsumer::Process_xrConvertTimeToWin32PerformanceCounterKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrTime                                      time,
    PointerDecoder<LARGE_INTEGER>*              performanceCounter)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    LARGE_INTEGER* out_performanceCounter = performanceCounter->IsNull() ? nullptr : performanceCounter->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_instance)->ConvertTimeToWin32PerformanceCounterKHR(in_instance, time, out_performanceCounter);
    CheckResult("xrConvertTimeToWin32PerformanceCounterKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR>::UpdateState(this, call_info, returnValue, instance, time, performanceCounter, replay_result);
}

void OpenXrReplayConsumer::Process_xrConvertTimespecTimeToTimeKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_timespec>*     timespecTime,
    PointerDecoder<XrTime>*                     time)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const struct timespec* in_timespecTime = timespecTime->GetPointer();
    XrTime* out_time = time->IsNull() ? nullptr : time->AllocateOutputData(1, static_cast<XrTime>(0));

    XrResult replay_result = GetInstanceTable(in_instance)->ConvertTimespecTimeToTimeKHR(in_instance, in_timespecTime, out_time);
    CheckResult("xrConvertTimespecTimeToTimeKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrConvertTimespecTimeToTimeKHR>::UpdateState(this, call_info, returnValue, instance, timespecTime, time, replay_result);
}

void OpenXrReplayConsumer::Process_xrConvertTimeToTimespecTimeKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrTime                                      time,
    StructPointerDecoder<Decoded_timespec>*     timespecTime)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    struct timespec* out_timespecTime = timespecTime->IsNull() ? nullptr : timespecTime->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_instance)->ConvertTimeToTimespecTimeKHR(in_instance, time, out_timespecTime);
    CheckResult("xrConvertTimeToTimespecTimeKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR>::UpdateState(this, call_info, returnValue, instance, time, timespecTime, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVulkanGraphicsDevice2KHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrVulkanGraphicsDeviceGetInfoKHR>* getInfo,
    HandlePointerDecoder<VkPhysicalDevice>*     vulkanPhysicalDevice)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const XrVulkanGraphicsDeviceGetInfoKHR* in_getInfo = getInfo->GetPointer();
    MapStructHandles(getInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!vulkanPhysicalDevice->IsNull()) { vulkanPhysicalDevice->SetHandleLength(1); }
    VkPhysicalDevice* out_vulkanPhysicalDevice = vulkanPhysicalDevice->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_instance)->GetVulkanGraphicsDevice2KHR(in_instance, in_getInfo, out_vulkanPhysicalDevice);
    CheckResult("xrGetVulkanGraphicsDevice2KHR", returnValue, replay_result, call_info);

    AddHandle<VulkanPhysicalDeviceInfo>(instance, vulkanPhysicalDevice->GetPointer(), out_vulkanPhysicalDevice, &CommonObjectInfoTable::AddVkPhysicalDeviceInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDevice2KHR>::UpdateState(this, call_info, returnValue, instance, getInfo, vulkanPhysicalDevice, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVulkanGraphicsRequirements2KHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    XrGraphicsRequirementsVulkanKHR* out_graphicsRequirements = graphicsRequirements->IsNull() ? nullptr : graphicsRequirements->AllocateOutputData(1, { XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR, nullptr });
    InitializeOutputStructNext(graphicsRequirements);

    XrResult replay_result = GetInstanceTable(in_instance)->GetVulkanGraphicsRequirements2KHR(in_instance, in_systemId, out_graphicsRequirements);
    CheckResult("xrGetVulkanGraphicsRequirements2KHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirements2KHR>::UpdateState(this, call_info, returnValue, instance, systemId, graphicsRequirements, replay_result);
}

void OpenXrReplayConsumer::Process_xrLocateSpacesKHR(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpacesLocateInfo>* locateInfo,
    StructPointerDecoder<Decoded_XrSpaceLocations>* spaceLocations)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpacesLocateInfo* in_locateInfo = locateInfo->GetPointer();
    MapStructHandles(locateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrSpaceLocations* out_spaceLocations = spaceLocations->IsNull() ? nullptr : spaceLocations->AllocateOutputData(1, { XR_TYPE_SPACE_LOCATIONS, nullptr });
    InitializeOutputStructNext(spaceLocations);

    XrResult replay_result = GetInstanceTable(in_session)->LocateSpacesKHR(in_session, in_locateInfo, out_spaceLocations);
    CheckResult("xrLocateSpacesKHR", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrLocateSpacesKHR>::UpdateState(this, call_info, returnValue, session, locateInfo, spaceLocations, replay_result);
}

void OpenXrReplayConsumer::Process_xrPerfSettingsSetPerformanceLevelEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPerfSettingsDomainEXT                     domain,
    XrPerfSettingsLevelEXT                      level)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->PerfSettingsSetPerformanceLevelEXT(in_session, domain, level);
    CheckResult("xrPerfSettingsSetPerformanceLevelEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrPerfSettingsSetPerformanceLevelEXT>::UpdateState(this, call_info, returnValue, session, domain, level, replay_result);
}

void OpenXrReplayConsumer::Process_xrThermalGetTemperatureTrendEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrPerfSettingsDomainEXT                     domain,
    PointerDecoder<XrPerfSettingsNotificationLevelEXT>* notificationLevel,
    PointerDecoder<float>*                      tempHeadroom,
    PointerDecoder<float>*                      tempSlope)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPerfSettingsNotificationLevelEXT* out_notificationLevel = notificationLevel->IsNull() ? nullptr : notificationLevel->AllocateOutputData(1, static_cast<XrPerfSettingsNotificationLevelEXT>(0));
    float* out_tempHeadroom = tempHeadroom->IsNull() ? nullptr : tempHeadroom->AllocateOutputData(1, static_cast<float>(0));
    float* out_tempSlope = tempSlope->IsNull() ? nullptr : tempSlope->AllocateOutputData(1, static_cast<float>(0));

    XrResult replay_result = GetInstanceTable(in_session)->ThermalGetTemperatureTrendEXT(in_session, domain, out_notificationLevel, out_tempHeadroom, out_tempSlope);
    CheckResult("xrThermalGetTemperatureTrendEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrThermalGetTemperatureTrendEXT>::UpdateState(this, call_info, returnValue, session, domain, notificationLevel, tempHeadroom, tempSlope, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrDebugUtilsObjectNameInfoEXT>* nameInfo)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const XrDebugUtilsObjectNameInfoEXT* in_nameInfo = nameInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_instance)->SetDebugUtilsObjectNameEXT(in_instance, in_nameInfo);
    CheckResult("xrSetDebugUtilsObjectNameEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetDebugUtilsObjectNameEXT>::UpdateState(this, call_info, returnValue, instance, nameInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            messenger)
{
    XrDebugUtilsMessengerEXT in_messenger = MapHandle<OpenXrDebugUtilsMessengerEXTInfo>(messenger, &CommonObjectInfoTable::GetXrDebugUtilsMessengerEXTInfo);

    XrResult replay_result = GetInstanceTable(in_messenger)->DestroyDebugUtilsMessengerEXT(in_messenger);
    CheckResult("xrDestroyDebugUtilsMessengerEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyDebugUtilsMessengerEXT>::UpdateState(this, call_info, returnValue, messenger, replay_result);
    RemoveHandle(messenger, &CommonObjectInfoTable::RemoveXrDebugUtilsMessengerEXTInfo);
}

void OpenXrReplayConsumer::Process_xrSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    XrDebugUtilsMessageSeverityFlagsEXT         messageSeverity,
    XrDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_XrDebugUtilsMessengerCallbackDataEXT>* callbackData)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const XrDebugUtilsMessengerCallbackDataEXT* in_callbackData = callbackData->GetPointer();

    XrResult replay_result = GetInstanceTable(in_instance)->SubmitDebugUtilsMessageEXT(in_instance, messageSeverity, messageTypes, in_callbackData);
    CheckResult("xrSubmitDebugUtilsMessageEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSubmitDebugUtilsMessageEXT>::UpdateState(this, call_info, returnValue, instance, messageSeverity, messageTypes, callbackData, replay_result);
}

void OpenXrReplayConsumer::Process_xrSessionBeginDebugUtilsLabelRegionEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* labelInfo)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrDebugUtilsLabelEXT* in_labelInfo = labelInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_session)->SessionBeginDebugUtilsLabelRegionEXT(in_session, in_labelInfo);
    CheckResult("xrSessionBeginDebugUtilsLabelRegionEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSessionBeginDebugUtilsLabelRegionEXT>::UpdateState(this, call_info, returnValue, session, labelInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrSessionEndDebugUtilsLabelRegionEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SessionEndDebugUtilsLabelRegionEXT(in_session);
    CheckResult("xrSessionEndDebugUtilsLabelRegionEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSessionEndDebugUtilsLabelRegionEXT>::UpdateState(this, call_info, returnValue, session, replay_result);
}

void OpenXrReplayConsumer::Process_xrSessionInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* labelInfo)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrDebugUtilsLabelEXT* in_labelInfo = labelInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_session)->SessionInsertDebugUtilsLabelEXT(in_session, in_labelInfo);
    CheckResult("xrSessionInsertDebugUtilsLabelEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSessionInsertDebugUtilsLabelEXT>::UpdateState(this, call_info, returnValue, session, labelInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpatialAnchorMSFT>*  anchor)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpatialAnchorCreateInfoMSFT* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!anchor->IsNull()) { anchor->SetHandleLength(1); }
    XrSpatialAnchorMSFT* out_anchor = anchor->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSpatialAnchorMSFT(in_session, in_createInfo, out_anchor);
    CheckResult("xrCreateSpatialAnchorMSFT", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpatialAnchorMSFTInfo>(session, anchor->GetPointer(), out_anchor, &CommonObjectInfoTable::AddXrSpatialAnchorMSFTInfo);
    
    AssociateParent(*out_anchor, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSpatialAnchorMSFT>::UpdateState(this, call_info, returnValue, session, createInfo, anchor, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSpatialAnchorSpaceMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorSpaceCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpatialAnchorSpaceCreateInfoMSFT* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!space->IsNull()) { space->SetHandleLength(1); }
    XrSpace* out_space = space->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSpatialAnchorSpaceMSFT(in_session, in_createInfo, out_space);
    CheckResult("xrCreateSpatialAnchorSpaceMSFT", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(session, space->GetPointer(), out_space, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_space, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSpatialAnchorSpaceMSFT>::UpdateState(this, call_info, returnValue, session, createInfo, space, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroySpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            anchor)
{
    XrSpatialAnchorMSFT in_anchor = MapHandle<OpenXrSpatialAnchorMSFTInfo>(anchor, &CommonObjectInfoTable::GetXrSpatialAnchorMSFTInfo);

    XrResult replay_result = GetInstanceTable(in_anchor)->DestroySpatialAnchorMSFT(in_anchor);
    CheckResult("xrDestroySpatialAnchorMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroySpatialAnchorMSFT>::UpdateState(this, call_info, returnValue, anchor, replay_result);
    RemoveHandle(anchor, &CommonObjectInfoTable::RemoveXrSpatialAnchorMSFTInfo);
}

void OpenXrReplayConsumer::Process_xrSetInputDeviceActiveEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            interactionProfile,
    format::HandleId                            topLevelPath,
    XrBool32                                    isActive)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPath in_interactionProfile = MapHandle<OpenXrPathInfo>(interactionProfile, &CommonObjectInfoTable::GetXrPathInfo);
    XrPath in_topLevelPath = MapHandle<OpenXrPathInfo>(topLevelPath, &CommonObjectInfoTable::GetXrPathInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetInputDeviceActiveEXT(in_session, in_interactionProfile, in_topLevelPath, isActive);
    CheckResult("xrSetInputDeviceActiveEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetInputDeviceActiveEXT>::UpdateState(this, call_info, returnValue, session, interactionProfile, topLevelPath, isActive, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetInputDeviceStateBoolEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelPath,
    format::HandleId                            inputSourcePath,
    XrBool32                                    state)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPath in_topLevelPath = MapHandle<OpenXrPathInfo>(topLevelPath, &CommonObjectInfoTable::GetXrPathInfo);
    XrPath in_inputSourcePath = MapHandle<OpenXrPathInfo>(inputSourcePath, &CommonObjectInfoTable::GetXrPathInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetInputDeviceStateBoolEXT(in_session, in_topLevelPath, in_inputSourcePath, state);
    CheckResult("xrSetInputDeviceStateBoolEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetInputDeviceStateBoolEXT>::UpdateState(this, call_info, returnValue, session, topLevelPath, inputSourcePath, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetInputDeviceStateFloatEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelPath,
    format::HandleId                            inputSourcePath,
    float                                       state)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPath in_topLevelPath = MapHandle<OpenXrPathInfo>(topLevelPath, &CommonObjectInfoTable::GetXrPathInfo);
    XrPath in_inputSourcePath = MapHandle<OpenXrPathInfo>(inputSourcePath, &CommonObjectInfoTable::GetXrPathInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetInputDeviceStateFloatEXT(in_session, in_topLevelPath, in_inputSourcePath, state);
    CheckResult("xrSetInputDeviceStateFloatEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetInputDeviceStateFloatEXT>::UpdateState(this, call_info, returnValue, session, topLevelPath, inputSourcePath, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetInputDeviceStateVector2fEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelPath,
    format::HandleId                            inputSourcePath,
    Decoded_XrVector2f                          state)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPath in_topLevelPath = MapHandle<OpenXrPathInfo>(topLevelPath, &CommonObjectInfoTable::GetXrPathInfo);
    XrPath in_inputSourcePath = MapHandle<OpenXrPathInfo>(inputSourcePath, &CommonObjectInfoTable::GetXrPathInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetInputDeviceStateVector2fEXT(in_session, in_topLevelPath, in_inputSourcePath, *state.decoded_value);
    CheckResult("xrSetInputDeviceStateVector2fEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetInputDeviceStateVector2fEXT>::UpdateState(this, call_info, returnValue, session, topLevelPath, inputSourcePath, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetInputDeviceLocationEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelPath,
    format::HandleId                            inputSourcePath,
    format::HandleId                            space,
    Decoded_XrPosef                             pose)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPath in_topLevelPath = MapHandle<OpenXrPathInfo>(topLevelPath, &CommonObjectInfoTable::GetXrPathInfo);
    XrPath in_inputSourcePath = MapHandle<OpenXrPathInfo>(inputSourcePath, &CommonObjectInfoTable::GetXrPathInfo);
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetInputDeviceLocationEXT(in_session, in_topLevelPath, in_inputSourcePath, in_space, *pose.decoded_value);
    CheckResult("xrSetInputDeviceLocationEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetInputDeviceLocationEXT>::UpdateState(this, call_info, returnValue, session, topLevelPath, inputSourcePath, space, pose, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSpatialGraphNodeSpaceMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpatialGraphNodeSpaceCreateInfoMSFT* in_createInfo = createInfo->GetPointer();
    if (!space->IsNull()) { space->SetHandleLength(1); }
    XrSpace* out_space = space->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSpatialGraphNodeSpaceMSFT(in_session, in_createInfo, out_space);
    CheckResult("xrCreateSpatialGraphNodeSpaceMSFT", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(session, space->GetPointer(), out_space, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_space, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSpatialGraphNodeSpaceMSFT>::UpdateState(this, call_info, returnValue, session, createInfo, space, replay_result);
}

void OpenXrReplayConsumer::Process_xrTryCreateSpatialGraphStaticNodeBindingMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpatialGraphNodeBindingMSFT>* nodeBinding)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpatialGraphStaticNodeBindingCreateInfoMSFT* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!nodeBinding->IsNull()) { nodeBinding->SetHandleLength(1); }
    XrSpatialGraphNodeBindingMSFT* out_nodeBinding = nodeBinding->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->TryCreateSpatialGraphStaticNodeBindingMSFT(in_session, in_createInfo, out_nodeBinding);
    CheckResult("xrTryCreateSpatialGraphStaticNodeBindingMSFT", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpatialGraphNodeBindingMSFTInfo>(session, nodeBinding->GetPointer(), out_nodeBinding, &CommonObjectInfoTable::AddXrSpatialGraphNodeBindingMSFTInfo);
    
    AssociateParent(*out_nodeBinding, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT>::UpdateState(this, call_info, returnValue, session, createInfo, nodeBinding, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroySpatialGraphNodeBindingMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            nodeBinding)
{
    XrSpatialGraphNodeBindingMSFT in_nodeBinding = MapHandle<OpenXrSpatialGraphNodeBindingMSFTInfo>(nodeBinding, &CommonObjectInfoTable::GetXrSpatialGraphNodeBindingMSFTInfo);

    XrResult replay_result = GetInstanceTable(in_nodeBinding)->DestroySpatialGraphNodeBindingMSFT(in_nodeBinding);
    CheckResult("xrDestroySpatialGraphNodeBindingMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroySpatialGraphNodeBindingMSFT>::UpdateState(this, call_info, returnValue, nodeBinding, replay_result);
    RemoveHandle(nodeBinding, &CommonObjectInfoTable::RemoveXrSpatialGraphNodeBindingMSFTInfo);
}

void OpenXrReplayConsumer::Process_xrGetSpatialGraphNodeBindingPropertiesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            nodeBinding,
    StructPointerDecoder<Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT>* getInfo,
    StructPointerDecoder<Decoded_XrSpatialGraphNodeBindingPropertiesMSFT>* properties)
{
    XrSpatialGraphNodeBindingMSFT in_nodeBinding = MapHandle<OpenXrSpatialGraphNodeBindingMSFTInfo>(nodeBinding, &CommonObjectInfoTable::GetXrSpatialGraphNodeBindingMSFTInfo);
    const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* in_getInfo = getInfo->GetPointer();
    XrSpatialGraphNodeBindingPropertiesMSFT* out_properties = properties->IsNull() ? nullptr : properties->AllocateOutputData(1, { XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT, nullptr });
    InitializeOutputStructNext(properties);

    XrResult replay_result = GetInstanceTable(in_nodeBinding)->GetSpatialGraphNodeBindingPropertiesMSFT(in_nodeBinding, in_getInfo, out_properties);
    CheckResult("xrGetSpatialGraphNodeBindingPropertiesMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT>::UpdateState(this, call_info, returnValue, nodeBinding, getInfo, properties, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateHandTrackerEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrHandTrackerCreateInfoEXT>* createInfo,
    HandlePointerDecoder<XrHandTrackerEXT>*     handTracker)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrHandTrackerCreateInfoEXT* in_createInfo = createInfo->GetPointer();
    if (!handTracker->IsNull()) { handTracker->SetHandleLength(1); }
    XrHandTrackerEXT* out_handTracker = handTracker->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateHandTrackerEXT(in_session, in_createInfo, out_handTracker);
    CheckResult("xrCreateHandTrackerEXT", returnValue, replay_result, call_info);

    AddHandle<OpenXrHandTrackerEXTInfo>(session, handTracker->GetPointer(), out_handTracker, &CommonObjectInfoTable::AddXrHandTrackerEXTInfo);
    
    AssociateParent(*out_handTracker, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateHandTrackerEXT>::UpdateState(this, call_info, returnValue, session, createInfo, handTracker, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyHandTrackerEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker)
{
    XrHandTrackerEXT in_handTracker = MapHandle<OpenXrHandTrackerEXTInfo>(handTracker, &CommonObjectInfoTable::GetXrHandTrackerEXTInfo);

    XrResult replay_result = GetInstanceTable(in_handTracker)->DestroyHandTrackerEXT(in_handTracker);
    CheckResult("xrDestroyHandTrackerEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyHandTrackerEXT>::UpdateState(this, call_info, returnValue, handTracker, replay_result);
    RemoveHandle(handTracker, &CommonObjectInfoTable::RemoveXrHandTrackerEXTInfo);
}

void OpenXrReplayConsumer::Process_xrCreateHandMeshSpaceMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker,
    StructPointerDecoder<Decoded_XrHandMeshSpaceCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    XrHandTrackerEXT in_handTracker = MapHandle<OpenXrHandTrackerEXTInfo>(handTracker, &CommonObjectInfoTable::GetXrHandTrackerEXTInfo);
    const XrHandMeshSpaceCreateInfoMSFT* in_createInfo = createInfo->GetPointer();
    if (!space->IsNull()) { space->SetHandleLength(1); }
    XrSpace* out_space = space->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_handTracker)->CreateHandMeshSpaceMSFT(in_handTracker, in_createInfo, out_space);
    CheckResult("xrCreateHandMeshSpaceMSFT", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(handTracker, space->GetPointer(), out_space, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_space, in_handTracker);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateHandMeshSpaceMSFT>::UpdateState(this, call_info, returnValue, handTracker, createInfo, space, replay_result);
}

void OpenXrReplayConsumer::Process_xrUpdateHandMeshMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker,
    StructPointerDecoder<Decoded_XrHandMeshUpdateInfoMSFT>* updateInfo,
    StructPointerDecoder<Decoded_XrHandMeshMSFT>* handMesh)
{
    XrHandTrackerEXT in_handTracker = MapHandle<OpenXrHandTrackerEXTInfo>(handTracker, &CommonObjectInfoTable::GetXrHandTrackerEXTInfo);
    const XrHandMeshUpdateInfoMSFT* in_updateInfo = updateInfo->GetPointer();
    XrHandMeshMSFT* out_handMesh = handMesh->IsNull() ? nullptr : handMesh->AllocateOutputData(1, { XR_TYPE_HAND_MESH_MSFT, nullptr });
    InitializeOutputStructNext(handMesh);

    XrResult replay_result = GetInstanceTable(in_handTracker)->UpdateHandMeshMSFT(in_handTracker, in_updateInfo, out_handMesh);
    CheckResult("xrUpdateHandMeshMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrUpdateHandMeshMSFT>::UpdateState(this, call_info, returnValue, handTracker, updateInfo, handMesh, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetControllerModelKeyMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            topLevelUserPath,
    StructPointerDecoder<Decoded_XrControllerModelKeyStateMSFT>* controllerModelKeyState)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPath in_topLevelUserPath = MapHandle<OpenXrPathInfo>(topLevelUserPath, &CommonObjectInfoTable::GetXrPathInfo);
    XrControllerModelKeyStateMSFT* out_controllerModelKeyState = controllerModelKeyState->IsNull() ? nullptr : controllerModelKeyState->AllocateOutputData(1, { XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT, nullptr });
    InitializeOutputStructNext(controllerModelKeyState);

    XrResult replay_result = GetInstanceTable(in_session)->GetControllerModelKeyMSFT(in_session, in_topLevelUserPath, out_controllerModelKeyState);
    CheckResult("xrGetControllerModelKeyMSFT", returnValue, replay_result, call_info);

    AddStructHandles(session, controllerModelKeyState->GetMetaStructPointer(), out_controllerModelKeyState, &GetObjectInfoTable());
    CustomProcess<format::ApiCallId::ApiCall_xrGetControllerModelKeyMSFT>::UpdateState(this, call_info, returnValue, session, topLevelUserPath, controllerModelKeyState, replay_result);
}

void OpenXrReplayConsumer::Process_xrLoadControllerModelMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            modelKey,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    PointerDecoder<uint8_t>*                    buffer)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrControllerModelKeyMSFT in_modelKey = MapHandle<OpenXrControllerModelKeyMSFTInfo>(modelKey, &CommonObjectInfoTable::GetXrControllerModelKeyMSFTInfo);
    uint32_t* out_bufferCountOutput = bufferCountOutput->IsNull() ? nullptr : bufferCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    uint8_t* out_buffer = buffer->IsNull() ? nullptr : buffer->AllocateOutputData(bufferCapacityInput);

    XrResult replay_result = GetInstanceTable(in_session)->LoadControllerModelMSFT(in_session, in_modelKey, bufferCapacityInput, out_bufferCountOutput, out_buffer);
    CheckResult("xrLoadControllerModelMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrLoadControllerModelMSFT>::UpdateState(this, call_info, returnValue, session, modelKey, bufferCapacityInput, bufferCountOutput, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetControllerModelPropertiesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            modelKey,
    StructPointerDecoder<Decoded_XrControllerModelPropertiesMSFT>* properties)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrControllerModelKeyMSFT in_modelKey = MapHandle<OpenXrControllerModelKeyMSFTInfo>(modelKey, &CommonObjectInfoTable::GetXrControllerModelKeyMSFTInfo);
    XrControllerModelPropertiesMSFT* out_properties = properties->IsNull() ? nullptr : properties->AllocateOutputData(1, { XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT, nullptr });
    InitializeOutputStructNext(properties);

    XrResult replay_result = GetInstanceTable(in_session)->GetControllerModelPropertiesMSFT(in_session, in_modelKey, out_properties);
    CheckResult("xrGetControllerModelPropertiesMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetControllerModelPropertiesMSFT>::UpdateState(this, call_info, returnValue, session, modelKey, properties, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetControllerModelStateMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            modelKey,
    StructPointerDecoder<Decoded_XrControllerModelStateMSFT>* state)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrControllerModelKeyMSFT in_modelKey = MapHandle<OpenXrControllerModelKeyMSFTInfo>(modelKey, &CommonObjectInfoTable::GetXrControllerModelKeyMSFTInfo);
    XrControllerModelStateMSFT* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1, { XR_TYPE_CONTROLLER_MODEL_STATE_MSFT, nullptr });
    InitializeOutputStructNext(state);

    XrResult replay_result = GetInstanceTable(in_session)->GetControllerModelStateMSFT(in_session, in_modelKey, out_state);
    CheckResult("xrGetControllerModelStateMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetControllerModelStateMSFT>::UpdateState(this, call_info, returnValue, session, modelKey, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint64_t                                    perceptionAnchor,
    HandlePointerDecoder<XrSpatialAnchorMSFT>*  anchor)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    IUnknown* in_perceptionAnchor = static_cast<IUnknown*>(PreProcessExternalObject(perceptionAnchor, format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT, "xrCreateSpatialAnchorFromPerceptionAnchorMSFT"));
    if (!anchor->IsNull()) { anchor->SetHandleLength(1); }
    XrSpatialAnchorMSFT* out_anchor = anchor->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSpatialAnchorFromPerceptionAnchorMSFT(in_session, in_perceptionAnchor, out_anchor);
    CheckResult("xrCreateSpatialAnchorFromPerceptionAnchorMSFT", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpatialAnchorMSFTInfo>(session, anchor->GetPointer(), out_anchor, &CommonObjectInfoTable::AddXrSpatialAnchorMSFTInfo);
    
    AssociateParent(*out_anchor, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT>::UpdateState(this, call_info, returnValue, session, perceptionAnchor, anchor, replay_result);
}

void OpenXrReplayConsumer::Process_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            anchor,
    PointerDecoder<uint64_t, void*>*            perceptionAnchor)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrSpatialAnchorMSFT in_anchor = MapHandle<OpenXrSpatialAnchorMSFTInfo>(anchor, &CommonObjectInfoTable::GetXrSpatialAnchorMSFTInfo);
    IUnknown** out_perceptionAnchor = perceptionAnchor->IsNull() ? nullptr : reinterpret_cast<IUnknown**>(perceptionAnchor->AllocateOutputData(1));

    XrResult replay_result = GetInstanceTable(in_session)->TryGetPerceptionAnchorFromSpatialAnchorMSFT(in_session, in_anchor, out_perceptionAnchor);
    CheckResult("xrTryGetPerceptionAnchorFromSpatialAnchorMSFT", returnValue, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*perceptionAnchor->GetPointer()), static_cast<void*>(*out_perceptionAnchor), format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT, "xrTryGetPerceptionAnchorFromSpatialAnchorMSFT");
    CustomProcess<format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT>::UpdateState(this, call_info, returnValue, session, anchor, perceptionAnchor, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateReprojectionModesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    modeCapacityInput,
    PointerDecoder<uint32_t>*                   modeCountOutput,
    PointerDecoder<XrReprojectionModeMSFT>*     modes)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    uint32_t* out_modeCountOutput = modeCountOutput->IsNull() ? nullptr : modeCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrReprojectionModeMSFT* out_modes = modes->IsNull() ? nullptr : modes->AllocateOutputData(modeCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!modes->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_instance)->EnumerateReprojectionModesMSFT(in_instance, in_systemId, viewConfigurationType, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < modeCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrEnumerateReprojectionModesMSFT replay size %d is smaller than capture size %d",
                replay_count,
                modeCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<XrReprojectionModeMSFT> temp_modes(replay_count);
        replay_result = GetInstanceTable(in_instance)->EnumerateReprojectionModesMSFT(in_instance, in_systemId, viewConfigurationType, temp_modes.size(), out_modeCountOutput, temp_modes.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            XrReprojectionModeMSFT* original_modes = modes->GetPointer();
            for (uint32_t iii = 0; iii < modeCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_modes[jjj] == original_modes[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrEnumerateReprojectionModesMSFT failed to find a value of %d during replay",
                        original_modes[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_instance)->EnumerateReprojectionModesMSFT(in_instance, in_systemId, viewConfigurationType, modeCapacityInput, out_modeCountOutput, out_modes);
    }
    CheckResult("xrEnumerateReprojectionModesMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateReprojectionModesMSFT>::UpdateState(this, call_info, returnValue, instance, systemId, viewConfigurationType, modeCapacityInput, modeCountOutput, modes, replay_result);
}

void OpenXrReplayConsumer::Process_xrUpdateSwapchainFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state)
{
    XrSwapchain in_swapchain = MapHandle<OpenXrSwapchainInfo>(swapchain, &CommonObjectInfoTable::GetXrSwapchainInfo);
    const XrSwapchainStateBaseHeaderFB* in_state = state->GetPointer();

    XrResult replay_result = GetInstanceTable(in_swapchain)->UpdateSwapchainFB(in_swapchain, in_state);
    CheckResult("xrUpdateSwapchainFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrUpdateSwapchainFB>::UpdateState(this, call_info, returnValue, swapchain, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSwapchainStateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state)
{
    XrSwapchain in_swapchain = MapHandle<OpenXrSwapchainInfo>(swapchain, &CommonObjectInfoTable::GetXrSwapchainInfo);
    XrSwapchainStateBaseHeaderFB* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_swapchain)->GetSwapchainStateFB(in_swapchain, out_state);
    CheckResult("xrGetSwapchainStateFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSwapchainStateFB>::UpdateState(this, call_info, returnValue, swapchain, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateBodyTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrBodyTrackerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrBodyTrackerFB>*      bodyTracker)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrBodyTrackerCreateInfoFB* in_createInfo = createInfo->GetPointer();
    if (!bodyTracker->IsNull()) { bodyTracker->SetHandleLength(1); }
    XrBodyTrackerFB* out_bodyTracker = bodyTracker->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateBodyTrackerFB(in_session, in_createInfo, out_bodyTracker);
    CheckResult("xrCreateBodyTrackerFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrBodyTrackerFBInfo>(session, bodyTracker->GetPointer(), out_bodyTracker, &CommonObjectInfoTable::AddXrBodyTrackerFBInfo);
    
    AssociateParent(*out_bodyTracker, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateBodyTrackerFB>::UpdateState(this, call_info, returnValue, session, createInfo, bodyTracker, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyBodyTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            bodyTracker)
{
    XrBodyTrackerFB in_bodyTracker = MapHandle<OpenXrBodyTrackerFBInfo>(bodyTracker, &CommonObjectInfoTable::GetXrBodyTrackerFBInfo);

    XrResult replay_result = GetInstanceTable(in_bodyTracker)->DestroyBodyTrackerFB(in_bodyTracker);
    CheckResult("xrDestroyBodyTrackerFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyBodyTrackerFB>::UpdateState(this, call_info, returnValue, bodyTracker, replay_result);
    RemoveHandle(bodyTracker, &CommonObjectInfoTable::RemoveXrBodyTrackerFBInfo);
}

void OpenXrReplayConsumer::Process_xrGetBodySkeletonFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            bodyTracker,
    StructPointerDecoder<Decoded_XrBodySkeletonFB>* skeleton)
{
    XrBodyTrackerFB in_bodyTracker = MapHandle<OpenXrBodyTrackerFBInfo>(bodyTracker, &CommonObjectInfoTable::GetXrBodyTrackerFBInfo);
    XrBodySkeletonFB* out_skeleton = skeleton->IsNull() ? nullptr : skeleton->AllocateOutputData(1, { XR_TYPE_BODY_SKELETON_FB, nullptr });
    InitializeOutputStructNext(skeleton);

    XrResult replay_result = GetInstanceTable(in_bodyTracker)->GetBodySkeletonFB(in_bodyTracker, out_skeleton);
    CheckResult("xrGetBodySkeletonFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetBodySkeletonFB>::UpdateState(this, call_info, returnValue, bodyTracker, skeleton, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateSceneComputeFeaturesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    format::HandleId                            systemId,
    uint32_t                                    featureCapacityInput,
    PointerDecoder<uint32_t>*                   featureCountOutput,
    PointerDecoder<XrSceneComputeFeatureMSFT>*  features)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    XrSystemId in_systemId = MapHandle<OpenXrSystemIdInfo>(systemId, &CommonObjectInfoTable::GetXrSystemIdInfo);
    uint32_t* out_featureCountOutput = featureCountOutput->IsNull() ? nullptr : featureCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrSceneComputeFeatureMSFT* out_features = features->IsNull() ? nullptr : features->AllocateOutputData(featureCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!features->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_instance)->EnumerateSceneComputeFeaturesMSFT(in_instance, in_systemId, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < featureCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrEnumerateSceneComputeFeaturesMSFT replay size %d is smaller than capture size %d",
                replay_count,
                featureCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<XrSceneComputeFeatureMSFT> temp_features(replay_count);
        replay_result = GetInstanceTable(in_instance)->EnumerateSceneComputeFeaturesMSFT(in_instance, in_systemId, temp_features.size(), out_featureCountOutput, temp_features.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            XrSceneComputeFeatureMSFT* original_features = features->GetPointer();
            for (uint32_t iii = 0; iii < featureCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_features[jjj] == original_features[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrEnumerateSceneComputeFeaturesMSFT failed to find a value of %d during replay",
                        original_features[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_instance)->EnumerateSceneComputeFeaturesMSFT(in_instance, in_systemId, featureCapacityInput, out_featureCountOutput, out_features);
    }
    CheckResult("xrEnumerateSceneComputeFeaturesMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateSceneComputeFeaturesMSFT>::UpdateState(this, call_info, returnValue, instance, systemId, featureCapacityInput, featureCountOutput, features, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSceneObserverMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSceneObserverCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSceneObserverMSFT>*  sceneObserver)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSceneObserverCreateInfoMSFT* in_createInfo = createInfo->GetPointer();
    if (!sceneObserver->IsNull()) { sceneObserver->SetHandleLength(1); }
    XrSceneObserverMSFT* out_sceneObserver = sceneObserver->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSceneObserverMSFT(in_session, in_createInfo, out_sceneObserver);
    CheckResult("xrCreateSceneObserverMSFT", returnValue, replay_result, call_info);

    AddHandle<OpenXrSceneObserverMSFTInfo>(session, sceneObserver->GetPointer(), out_sceneObserver, &CommonObjectInfoTable::AddXrSceneObserverMSFTInfo);
    
    AssociateParent(*out_sceneObserver, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSceneObserverMSFT>::UpdateState(this, call_info, returnValue, session, createInfo, sceneObserver, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroySceneObserverMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver)
{
    XrSceneObserverMSFT in_sceneObserver = MapHandle<OpenXrSceneObserverMSFTInfo>(sceneObserver, &CommonObjectInfoTable::GetXrSceneObserverMSFTInfo);

    XrResult replay_result = GetInstanceTable(in_sceneObserver)->DestroySceneObserverMSFT(in_sceneObserver);
    CheckResult("xrDestroySceneObserverMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroySceneObserverMSFT>::UpdateState(this, call_info, returnValue, sceneObserver, replay_result);
    RemoveHandle(sceneObserver, &CommonObjectInfoTable::RemoveXrSceneObserverMSFTInfo);
}

void OpenXrReplayConsumer::Process_xrCreateSceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    StructPointerDecoder<Decoded_XrSceneCreateInfoMSFT>* createInfo,
    HandlePointerDecoder<XrSceneMSFT>*          scene)
{
    XrSceneObserverMSFT in_sceneObserver = MapHandle<OpenXrSceneObserverMSFTInfo>(sceneObserver, &CommonObjectInfoTable::GetXrSceneObserverMSFTInfo);
    const XrSceneCreateInfoMSFT* in_createInfo = createInfo->GetPointer();
    if (!scene->IsNull()) { scene->SetHandleLength(1); }
    XrSceneMSFT* out_scene = scene->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_sceneObserver)->CreateSceneMSFT(in_sceneObserver, in_createInfo, out_scene);
    CheckResult("xrCreateSceneMSFT", returnValue, replay_result, call_info);

    AddHandle<OpenXrSceneMSFTInfo>(sceneObserver, scene->GetPointer(), out_scene, &CommonObjectInfoTable::AddXrSceneMSFTInfo);
    
    AssociateParent(*out_scene, in_sceneObserver);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSceneMSFT>::UpdateState(this, call_info, returnValue, sceneObserver, createInfo, scene, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroySceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene)
{
    XrSceneMSFT in_scene = MapHandle<OpenXrSceneMSFTInfo>(scene, &CommonObjectInfoTable::GetXrSceneMSFTInfo);

    XrResult replay_result = GetInstanceTable(in_scene)->DestroySceneMSFT(in_scene);
    CheckResult("xrDestroySceneMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroySceneMSFT>::UpdateState(this, call_info, returnValue, scene, replay_result);
    RemoveHandle(scene, &CommonObjectInfoTable::RemoveXrSceneMSFTInfo);
}

void OpenXrReplayConsumer::Process_xrComputeNewSceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    StructPointerDecoder<Decoded_XrNewSceneComputeInfoMSFT>* computeInfo)
{
    XrSceneObserverMSFT in_sceneObserver = MapHandle<OpenXrSceneObserverMSFTInfo>(sceneObserver, &CommonObjectInfoTable::GetXrSceneObserverMSFTInfo);
    const XrNewSceneComputeInfoMSFT* in_computeInfo = computeInfo->GetPointer();
    MapStructHandles(computeInfo->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_sceneObserver)->ComputeNewSceneMSFT(in_sceneObserver, in_computeInfo);
    CheckResult("xrComputeNewSceneMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrComputeNewSceneMSFT>::UpdateState(this, call_info, returnValue, sceneObserver, computeInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSceneComputeStateMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    PointerDecoder<XrSceneComputeStateMSFT>*    state)
{
    XrSceneObserverMSFT in_sceneObserver = MapHandle<OpenXrSceneObserverMSFTInfo>(sceneObserver, &CommonObjectInfoTable::GetXrSceneObserverMSFTInfo);
    XrSceneComputeStateMSFT* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1, static_cast<XrSceneComputeStateMSFT>(0));

    XrResult replay_result = GetInstanceTable(in_sceneObserver)->GetSceneComputeStateMSFT(in_sceneObserver, out_state);
    CheckResult("xrGetSceneComputeStateMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSceneComputeStateMSFT>::UpdateState(this, call_info, returnValue, sceneObserver, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSceneComponentsMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrSceneComponentsGetInfoMSFT>* getInfo,
    StructPointerDecoder<Decoded_XrSceneComponentsMSFT>* components)
{
    XrSceneMSFT in_scene = MapHandle<OpenXrSceneMSFTInfo>(scene, &CommonObjectInfoTable::GetXrSceneMSFTInfo);
    const XrSceneComponentsGetInfoMSFT* in_getInfo = getInfo->GetPointer();
    XrSceneComponentsMSFT* out_components = components->IsNull() ? nullptr : components->AllocateOutputData(1, { XR_TYPE_SCENE_COMPONENTS_MSFT, nullptr });
    InitializeOutputStructNext(components);

    XrResult replay_result = GetInstanceTable(in_scene)->GetSceneComponentsMSFT(in_scene, in_getInfo, out_components);
    CheckResult("xrGetSceneComponentsMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSceneComponentsMSFT>::UpdateState(this, call_info, returnValue, scene, getInfo, components, replay_result);
}

void OpenXrReplayConsumer::Process_xrLocateSceneComponentsMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrSceneComponentsLocateInfoMSFT>* locateInfo,
    StructPointerDecoder<Decoded_XrSceneComponentLocationsMSFT>* locations)
{
    XrSceneMSFT in_scene = MapHandle<OpenXrSceneMSFTInfo>(scene, &CommonObjectInfoTable::GetXrSceneMSFTInfo);
    const XrSceneComponentsLocateInfoMSFT* in_locateInfo = locateInfo->GetPointer();
    MapStructHandles(locateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrSceneComponentLocationsMSFT* out_locations = locations->IsNull() ? nullptr : locations->AllocateOutputData(1, { XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT, nullptr });
    InitializeOutputStructNext(locations);

    XrResult replay_result = GetInstanceTable(in_scene)->LocateSceneComponentsMSFT(in_scene, in_locateInfo, out_locations);
    CheckResult("xrLocateSceneComponentsMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrLocateSceneComponentsMSFT>::UpdateState(this, call_info, returnValue, scene, locateInfo, locations, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSceneMeshBuffersMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrSceneMeshBuffersGetInfoMSFT>* getInfo,
    StructPointerDecoder<Decoded_XrSceneMeshBuffersMSFT>* buffers)
{
    XrSceneMSFT in_scene = MapHandle<OpenXrSceneMSFTInfo>(scene, &CommonObjectInfoTable::GetXrSceneMSFTInfo);
    const XrSceneMeshBuffersGetInfoMSFT* in_getInfo = getInfo->GetPointer();
    XrSceneMeshBuffersMSFT* out_buffers = buffers->IsNull() ? nullptr : buffers->AllocateOutputData(1, { XR_TYPE_SCENE_MESH_BUFFERS_MSFT, nullptr });
    InitializeOutputStructNext(buffers);

    XrResult replay_result = GetInstanceTable(in_scene)->GetSceneMeshBuffersMSFT(in_scene, in_getInfo, out_buffers);
    CheckResult("xrGetSceneMeshBuffersMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSceneMeshBuffersMSFT>::UpdateState(this, call_info, returnValue, scene, getInfo, buffers, replay_result);
}

void OpenXrReplayConsumer::Process_xrDeserializeSceneMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            sceneObserver,
    StructPointerDecoder<Decoded_XrSceneDeserializeInfoMSFT>* deserializeInfo)
{
    XrSceneObserverMSFT in_sceneObserver = MapHandle<OpenXrSceneObserverMSFTInfo>(sceneObserver, &CommonObjectInfoTable::GetXrSceneObserverMSFTInfo);
    const XrSceneDeserializeInfoMSFT* in_deserializeInfo = deserializeInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_sceneObserver)->DeserializeSceneMSFT(in_sceneObserver, in_deserializeInfo);
    CheckResult("xrDeserializeSceneMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDeserializeSceneMSFT>::UpdateState(this, call_info, returnValue, sceneObserver, deserializeInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSerializedSceneFragmentDataMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrSerializedSceneFragmentDataGetInfoMSFT>* getInfo,
    uint32_t                                    countInput,
    PointerDecoder<uint32_t>*                   readOutput,
    PointerDecoder<uint8_t>*                    buffer)
{
    XrSceneMSFT in_scene = MapHandle<OpenXrSceneMSFTInfo>(scene, &CommonObjectInfoTable::GetXrSceneMSFTInfo);
    const XrSerializedSceneFragmentDataGetInfoMSFT* in_getInfo = getInfo->GetPointer();
    uint32_t* out_readOutput = readOutput->IsNull() ? nullptr : readOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    uint8_t* out_buffer = buffer->IsNull() ? nullptr : buffer->AllocateOutputData(countInput);

    XrResult replay_result = XR_SUCCESS;
    if (!buffer->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_scene)->GetSerializedSceneFragmentDataMSFT(in_scene, in_getInfo, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < countInput)
        {
            GFXRECON_LOG_FATAL("xrGetSerializedSceneFragmentDataMSFT replay size %d is smaller than capture size %d",
                replay_count,
                countInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<uint8_t> temp_buffer(replay_count);
        replay_result = GetInstanceTable(in_scene)->GetSerializedSceneFragmentDataMSFT(in_scene, in_getInfo, temp_buffer.size(), out_readOutput, temp_buffer.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            uint8_t* original_buffer = buffer->GetPointer();
            for (uint32_t iii = 0; iii < countInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_buffer[jjj] == original_buffer[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrGetSerializedSceneFragmentDataMSFT failed to find a value of %d during replay",
                        original_buffer[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_scene)->GetSerializedSceneFragmentDataMSFT(in_scene, in_getInfo, countInput, out_readOutput, out_buffer);
    }
    CheckResult("xrGetSerializedSceneFragmentDataMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSerializedSceneFragmentDataMSFT>::UpdateState(this, call_info, returnValue, scene, getInfo, countInput, readOutput, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateDisplayRefreshRatesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    displayRefreshRateCapacityInput,
    PointerDecoder<uint32_t>*                   displayRefreshRateCountOutput,
    PointerDecoder<float>*                      displayRefreshRates)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    uint32_t* out_displayRefreshRateCountOutput = displayRefreshRateCountOutput->IsNull() ? nullptr : displayRefreshRateCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    float* out_displayRefreshRates = displayRefreshRates->IsNull() ? nullptr : displayRefreshRates->AllocateOutputData(displayRefreshRateCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!displayRefreshRates->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_session)->EnumerateDisplayRefreshRatesFB(in_session, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < displayRefreshRateCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrEnumerateDisplayRefreshRatesFB replay size %d is smaller than capture size %d",
                replay_count,
                displayRefreshRateCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<float> temp_displayRefreshRates(replay_count);
        replay_result = GetInstanceTable(in_session)->EnumerateDisplayRefreshRatesFB(in_session, temp_displayRefreshRates.size(), out_displayRefreshRateCountOutput, temp_displayRefreshRates.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            float* original_displayRefreshRates = displayRefreshRates->GetPointer();
            for (uint32_t iii = 0; iii < displayRefreshRateCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_displayRefreshRates[jjj] == original_displayRefreshRates[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrEnumerateDisplayRefreshRatesFB failed to find a value of %f during replay",
                        original_displayRefreshRates[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_session)->EnumerateDisplayRefreshRatesFB(in_session, displayRefreshRateCapacityInput, out_displayRefreshRateCountOutput, out_displayRefreshRates);
    }
    CheckResult("xrEnumerateDisplayRefreshRatesFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateDisplayRefreshRatesFB>::UpdateState(this, call_info, returnValue, session, displayRefreshRateCapacityInput, displayRefreshRateCountOutput, displayRefreshRates, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetDisplayRefreshRateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    PointerDecoder<float>*                      displayRefreshRate)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    float* out_displayRefreshRate = displayRefreshRate->IsNull() ? nullptr : displayRefreshRate->AllocateOutputData(1, static_cast<float>(0));

    XrResult replay_result = GetInstanceTable(in_session)->GetDisplayRefreshRateFB(in_session, out_displayRefreshRate);
    CheckResult("xrGetDisplayRefreshRateFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetDisplayRefreshRateFB>::UpdateState(this, call_info, returnValue, session, displayRefreshRate, replay_result);
}

void OpenXrReplayConsumer::Process_xrRequestDisplayRefreshRateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    float                                       displayRefreshRate)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->RequestDisplayRefreshRateFB(in_session, displayRefreshRate);
    CheckResult("xrRequestDisplayRefreshRateFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrRequestDisplayRefreshRateFB>::UpdateState(this, call_info, returnValue, session, displayRefreshRate, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateViveTrackerPathsHTCX(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    uint32_t                                    pathCapacityInput,
    PointerDecoder<uint32_t>*                   pathCountOutput,
    StructPointerDecoder<Decoded_XrViveTrackerPathsHTCX>* paths)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    uint32_t* out_pathCountOutput = pathCountOutput->IsNull() ? nullptr : pathCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrViveTrackerPathsHTCX* out_paths = paths->IsNull() ? nullptr : paths->AllocateOutputData(pathCapacityInput, XrViveTrackerPathsHTCX{ XR_TYPE_VIVE_TRACKER_PATHS_HTCX, nullptr });

    XrResult replay_result = GetInstanceTable(in_instance)->EnumerateViveTrackerPathsHTCX(in_instance, pathCapacityInput, out_pathCountOutput, out_paths);
    CheckResult("xrEnumerateViveTrackerPathsHTCX", returnValue, replay_result, call_info);

    AddStructArrayHandles<Decoded_XrViveTrackerPathsHTCX>(instance, paths->GetMetaStructPointer(), paths->GetLength(), out_paths, pathCapacityInput, &GetObjectInfoTable());
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateViveTrackerPathsHTCX>::UpdateState(this, call_info, returnValue, instance, pathCapacityInput, pathCountOutput, paths, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateFacialTrackerHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFacialTrackerCreateInfoHTC>* createInfo,
    HandlePointerDecoder<XrFacialTrackerHTC>*   facialTracker)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrFacialTrackerCreateInfoHTC* in_createInfo = createInfo->GetPointer();
    if (!facialTracker->IsNull()) { facialTracker->SetHandleLength(1); }
    XrFacialTrackerHTC* out_facialTracker = facialTracker->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateFacialTrackerHTC(in_session, in_createInfo, out_facialTracker);
    CheckResult("xrCreateFacialTrackerHTC", returnValue, replay_result, call_info);

    AddHandle<OpenXrFacialTrackerHTCInfo>(session, facialTracker->GetPointer(), out_facialTracker, &CommonObjectInfoTable::AddXrFacialTrackerHTCInfo);
    
    AssociateParent(*out_facialTracker, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateFacialTrackerHTC>::UpdateState(this, call_info, returnValue, session, createInfo, facialTracker, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyFacialTrackerHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            facialTracker)
{
    XrFacialTrackerHTC in_facialTracker = MapHandle<OpenXrFacialTrackerHTCInfo>(facialTracker, &CommonObjectInfoTable::GetXrFacialTrackerHTCInfo);

    XrResult replay_result = GetInstanceTable(in_facialTracker)->DestroyFacialTrackerHTC(in_facialTracker);
    CheckResult("xrDestroyFacialTrackerHTC", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyFacialTrackerHTC>::UpdateState(this, call_info, returnValue, facialTracker, replay_result);
    RemoveHandle(facialTracker, &CommonObjectInfoTable::RemoveXrFacialTrackerHTCInfo);
}

void OpenXrReplayConsumer::Process_xrGetFacialExpressionsHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            facialTracker,
    StructPointerDecoder<Decoded_XrFacialExpressionsHTC>* facialExpressions)
{
    XrFacialTrackerHTC in_facialTracker = MapHandle<OpenXrFacialTrackerHTCInfo>(facialTracker, &CommonObjectInfoTable::GetXrFacialTrackerHTCInfo);
    XrFacialExpressionsHTC* out_facialExpressions = facialExpressions->IsNull() ? nullptr : facialExpressions->AllocateOutputData(1, { XR_TYPE_FACIAL_EXPRESSIONS_HTC, nullptr });
    InitializeOutputStructNext(facialExpressions);

    XrResult replay_result = GetInstanceTable(in_facialTracker)->GetFacialExpressionsHTC(in_facialTracker, out_facialExpressions);
    CheckResult("xrGetFacialExpressionsHTC", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetFacialExpressionsHTC>::UpdateState(this, call_info, returnValue, facialTracker, facialExpressions, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateColorSpacesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    colorSpaceCapacityInput,
    PointerDecoder<uint32_t>*                   colorSpaceCountOutput,
    PointerDecoder<XrColorSpaceFB>*             colorSpaces)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    uint32_t* out_colorSpaceCountOutput = colorSpaceCountOutput->IsNull() ? nullptr : colorSpaceCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrColorSpaceFB* out_colorSpaces = colorSpaces->IsNull() ? nullptr : colorSpaces->AllocateOutputData(colorSpaceCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!colorSpaces->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_session)->EnumerateColorSpacesFB(in_session, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < colorSpaceCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrEnumerateColorSpacesFB replay size %d is smaller than capture size %d",
                replay_count,
                colorSpaceCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<XrColorSpaceFB> temp_colorSpaces(replay_count);
        replay_result = GetInstanceTable(in_session)->EnumerateColorSpacesFB(in_session, temp_colorSpaces.size(), out_colorSpaceCountOutput, temp_colorSpaces.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            XrColorSpaceFB* original_colorSpaces = colorSpaces->GetPointer();
            for (uint32_t iii = 0; iii < colorSpaceCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_colorSpaces[jjj] == original_colorSpaces[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrEnumerateColorSpacesFB failed to find a value of %d during replay",
                        original_colorSpaces[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_session)->EnumerateColorSpacesFB(in_session, colorSpaceCapacityInput, out_colorSpaceCountOutput, out_colorSpaces);
    }
    CheckResult("xrEnumerateColorSpacesFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateColorSpacesFB>::UpdateState(this, call_info, returnValue, session, colorSpaceCapacityInput, colorSpaceCountOutput, colorSpaces, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetColorSpaceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrColorSpaceFB                              colorSpace)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetColorSpaceFB(in_session, colorSpace);
    CheckResult("xrSetColorSpaceFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetColorSpaceFB>::UpdateState(this, call_info, returnValue, session, colorSpace, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSpatialAnchorFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpatialAnchorCreateInfoFB* in_info = info->GetPointer();
    MapStructHandles(info->GetMetaStructPointer(), GetObjectInfoTable());
    if (!requestId->IsNull()) { requestId->SetHandleLength(1); }
    XrAsyncRequestIdFB* out_requestId = requestId->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSpatialAnchorFB(in_session, in_info, out_requestId);
    CheckResult("xrCreateSpatialAnchorFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrAsyncRequestIdFBInfo>(session, requestId->GetPointer(), out_requestId, &CommonObjectInfoTable::AddXrAsyncRequestIdFBInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFB>::UpdateState(this, call_info, returnValue, session, info, requestId, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpaceUuidFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrUuid>*       uuid)
{
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrUuidEXT* out_uuid = uuid->IsNull() ? nullptr : uuid->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_space)->GetSpaceUuidFB(in_space, out_uuid);
    CheckResult("xrGetSpaceUuidFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpaceUuidFB>::UpdateState(this, call_info, returnValue, space, uuid, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateSpaceSupportedComponentsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    uint32_t                                    componentTypeCapacityInput,
    PointerDecoder<uint32_t>*                   componentTypeCountOutput,
    PointerDecoder<XrSpaceComponentTypeFB>*     componentTypes)
{
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    uint32_t* out_componentTypeCountOutput = componentTypeCountOutput->IsNull() ? nullptr : componentTypeCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrSpaceComponentTypeFB* out_componentTypes = componentTypes->IsNull() ? nullptr : componentTypes->AllocateOutputData(componentTypeCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!componentTypes->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_space)->EnumerateSpaceSupportedComponentsFB(in_space, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < componentTypeCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrEnumerateSpaceSupportedComponentsFB replay size %d is smaller than capture size %d",
                replay_count,
                componentTypeCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<XrSpaceComponentTypeFB> temp_componentTypes(replay_count);
        replay_result = GetInstanceTable(in_space)->EnumerateSpaceSupportedComponentsFB(in_space, temp_componentTypes.size(), out_componentTypeCountOutput, temp_componentTypes.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            XrSpaceComponentTypeFB* original_componentTypes = componentTypes->GetPointer();
            for (uint32_t iii = 0; iii < componentTypeCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_componentTypes[jjj] == original_componentTypes[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrEnumerateSpaceSupportedComponentsFB failed to find a value of %d during replay",
                        original_componentTypes[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_space)->EnumerateSpaceSupportedComponentsFB(in_space, componentTypeCapacityInput, out_componentTypeCountOutput, out_componentTypes);
    }
    CheckResult("xrEnumerateSpaceSupportedComponentsFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateSpaceSupportedComponentsFB>::UpdateState(this, call_info, returnValue, space, componentTypeCapacityInput, componentTypeCountOutput, componentTypes, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetSpaceComponentStatusFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrSpaceComponentStatusSetInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    const XrSpaceComponentStatusSetInfoFB* in_info = info->GetPointer();
    if (!requestId->IsNull()) { requestId->SetHandleLength(1); }
    XrAsyncRequestIdFB* out_requestId = requestId->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_space)->SetSpaceComponentStatusFB(in_space, in_info, out_requestId);
    CheckResult("xrSetSpaceComponentStatusFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrAsyncRequestIdFBInfo>(space, requestId->GetPointer(), out_requestId, &CommonObjectInfoTable::AddXrAsyncRequestIdFBInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrSetSpaceComponentStatusFB>::UpdateState(this, call_info, returnValue, space, info, requestId, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpaceComponentStatusFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    XrSpaceComponentTypeFB                      componentType,
    StructPointerDecoder<Decoded_XrSpaceComponentStatusFB>* status)
{
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrSpaceComponentStatusFB* out_status = status->IsNull() ? nullptr : status->AllocateOutputData(1, { XR_TYPE_SPACE_COMPONENT_STATUS_FB, nullptr });
    InitializeOutputStructNext(status);

    XrResult replay_result = GetInstanceTable(in_space)->GetSpaceComponentStatusFB(in_space, componentType, out_status);
    CheckResult("xrGetSpaceComponentStatusFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpaceComponentStatusFB>::UpdateState(this, call_info, returnValue, space, componentType, status, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateFoveationProfileFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFoveationProfileCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrFoveationProfileFB>* profile)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrFoveationProfileCreateInfoFB* in_createInfo = createInfo->GetPointer();
    if (!profile->IsNull()) { profile->SetHandleLength(1); }
    XrFoveationProfileFB* out_profile = profile->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateFoveationProfileFB(in_session, in_createInfo, out_profile);
    CheckResult("xrCreateFoveationProfileFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrFoveationProfileFBInfo>(session, profile->GetPointer(), out_profile, &CommonObjectInfoTable::AddXrFoveationProfileFBInfo);
    
    AssociateParent(*out_profile, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateFoveationProfileFB>::UpdateState(this, call_info, returnValue, session, createInfo, profile, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyFoveationProfileFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            profile)
{
    XrFoveationProfileFB in_profile = MapHandle<OpenXrFoveationProfileFBInfo>(profile, &CommonObjectInfoTable::GetXrFoveationProfileFBInfo);

    XrResult replay_result = GetInstanceTable(in_profile)->DestroyFoveationProfileFB(in_profile);
    CheckResult("xrDestroyFoveationProfileFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyFoveationProfileFB>::UpdateState(this, call_info, returnValue, profile, replay_result);
    RemoveHandle(profile, &CommonObjectInfoTable::RemoveXrFoveationProfileFBInfo);
}

void OpenXrReplayConsumer::Process_xrQuerySystemTrackedKeyboardFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrKeyboardTrackingQueryFB>* queryInfo,
    StructPointerDecoder<Decoded_XrKeyboardTrackingDescriptionFB>* keyboard)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrKeyboardTrackingQueryFB* in_queryInfo = queryInfo->GetPointer();
    XrKeyboardTrackingDescriptionFB* out_keyboard = keyboard->IsNull() ? nullptr : keyboard->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_session)->QuerySystemTrackedKeyboardFB(in_session, in_queryInfo, out_keyboard);
    CheckResult("xrQuerySystemTrackedKeyboardFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrQuerySystemTrackedKeyboardFB>::UpdateState(this, call_info, returnValue, session, queryInfo, keyboard, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateKeyboardSpaceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrKeyboardSpaceCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrSpace>*              keyboardSpace)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrKeyboardSpaceCreateInfoFB* in_createInfo = createInfo->GetPointer();
    if (!keyboardSpace->IsNull()) { keyboardSpace->SetHandleLength(1); }
    XrSpace* out_keyboardSpace = keyboardSpace->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateKeyboardSpaceFB(in_session, in_createInfo, out_keyboardSpace);
    CheckResult("xrCreateKeyboardSpaceFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(session, keyboardSpace->GetPointer(), out_keyboardSpace, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_keyboardSpace, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateKeyboardSpaceFB>::UpdateState(this, call_info, returnValue, session, createInfo, keyboardSpace, replay_result);
}

void OpenXrReplayConsumer::Process_xrTriangleMeshBeginUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh)
{
    XrTriangleMeshFB in_mesh = MapHandle<OpenXrTriangleMeshFBInfo>(mesh, &CommonObjectInfoTable::GetXrTriangleMeshFBInfo);

    XrResult replay_result = GetInstanceTable(in_mesh)->TriangleMeshBeginUpdateFB(in_mesh);
    CheckResult("xrTriangleMeshBeginUpdateFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrTriangleMeshBeginUpdateFB>::UpdateState(this, call_info, returnValue, mesh, replay_result);
}

void OpenXrReplayConsumer::Process_xrTriangleMeshEndUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh,
    uint32_t                                    vertexCount,
    uint32_t                                    triangleCount)
{
    XrTriangleMeshFB in_mesh = MapHandle<OpenXrTriangleMeshFBInfo>(mesh, &CommonObjectInfoTable::GetXrTriangleMeshFBInfo);

    XrResult replay_result = GetInstanceTable(in_mesh)->TriangleMeshEndUpdateFB(in_mesh, vertexCount, triangleCount);
    CheckResult("xrTriangleMeshEndUpdateFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrTriangleMeshEndUpdateFB>::UpdateState(this, call_info, returnValue, mesh, vertexCount, triangleCount, replay_result);
}

void OpenXrReplayConsumer::Process_xrTriangleMeshBeginVertexBufferUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh,
    PointerDecoder<uint32_t>*                   outVertexCount)
{
    XrTriangleMeshFB in_mesh = MapHandle<OpenXrTriangleMeshFBInfo>(mesh, &CommonObjectInfoTable::GetXrTriangleMeshFBInfo);
    uint32_t* out_outVertexCount = outVertexCount->IsNull() ? nullptr : outVertexCount->AllocateOutputData(1, static_cast<uint32_t>(0));

    XrResult replay_result = GetInstanceTable(in_mesh)->TriangleMeshBeginVertexBufferUpdateFB(in_mesh, out_outVertexCount);
    CheckResult("xrTriangleMeshBeginVertexBufferUpdateFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB>::UpdateState(this, call_info, returnValue, mesh, outVertexCount, replay_result);
}

void OpenXrReplayConsumer::Process_xrTriangleMeshEndVertexBufferUpdateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            mesh)
{
    XrTriangleMeshFB in_mesh = MapHandle<OpenXrTriangleMeshFBInfo>(mesh, &CommonObjectInfoTable::GetXrTriangleMeshFBInfo);

    XrResult replay_result = GetInstanceTable(in_mesh)->TriangleMeshEndVertexBufferUpdateFB(in_mesh);
    CheckResult("xrTriangleMeshEndVertexBufferUpdateFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrTriangleMeshEndVertexBufferUpdateFB>::UpdateState(this, call_info, returnValue, mesh, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreatePassthroughFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPassthroughCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrPassthroughFB>*      outPassthrough)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrPassthroughCreateInfoFB* in_createInfo = createInfo->GetPointer();
    if (!outPassthrough->IsNull()) { outPassthrough->SetHandleLength(1); }
    XrPassthroughFB* out_outPassthrough = outPassthrough->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreatePassthroughFB(in_session, in_createInfo, out_outPassthrough);
    CheckResult("xrCreatePassthroughFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrPassthroughFBInfo>(session, outPassthrough->GetPointer(), out_outPassthrough, &CommonObjectInfoTable::AddXrPassthroughFBInfo);
    
    AssociateParent(*out_outPassthrough, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreatePassthroughFB>::UpdateState(this, call_info, returnValue, session, createInfo, outPassthrough, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyPassthroughFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    XrPassthroughFB in_passthrough = MapHandle<OpenXrPassthroughFBInfo>(passthrough, &CommonObjectInfoTable::GetXrPassthroughFBInfo);

    XrResult replay_result = GetInstanceTable(in_passthrough)->DestroyPassthroughFB(in_passthrough);
    CheckResult("xrDestroyPassthroughFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyPassthroughFB>::UpdateState(this, call_info, returnValue, passthrough, replay_result);
    RemoveHandle(passthrough, &CommonObjectInfoTable::RemoveXrPassthroughFBInfo);
}

void OpenXrReplayConsumer::Process_xrPassthroughStartFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    XrPassthroughFB in_passthrough = MapHandle<OpenXrPassthroughFBInfo>(passthrough, &CommonObjectInfoTable::GetXrPassthroughFBInfo);

    XrResult replay_result = GetInstanceTable(in_passthrough)->PassthroughStartFB(in_passthrough);
    CheckResult("xrPassthroughStartFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrPassthroughStartFB>::UpdateState(this, call_info, returnValue, passthrough, replay_result);
}

void OpenXrReplayConsumer::Process_xrPassthroughPauseFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    XrPassthroughFB in_passthrough = MapHandle<OpenXrPassthroughFBInfo>(passthrough, &CommonObjectInfoTable::GetXrPassthroughFBInfo);

    XrResult replay_result = GetInstanceTable(in_passthrough)->PassthroughPauseFB(in_passthrough);
    CheckResult("xrPassthroughPauseFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrPassthroughPauseFB>::UpdateState(this, call_info, returnValue, passthrough, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreatePassthroughLayerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPassthroughLayerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrPassthroughLayerFB>* outLayer)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrPassthroughLayerCreateInfoFB* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!outLayer->IsNull()) { outLayer->SetHandleLength(1); }
    XrPassthroughLayerFB* out_outLayer = outLayer->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreatePassthroughLayerFB(in_session, in_createInfo, out_outLayer);
    CheckResult("xrCreatePassthroughLayerFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrPassthroughLayerFBInfo>(session, outLayer->GetPointer(), out_outLayer, &CommonObjectInfoTable::AddXrPassthroughLayerFBInfo);
    
    AssociateParent(*out_outLayer, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreatePassthroughLayerFB>::UpdateState(this, call_info, returnValue, session, createInfo, outLayer, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyPassthroughLayerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer)
{
    XrPassthroughLayerFB in_layer = MapHandle<OpenXrPassthroughLayerFBInfo>(layer, &CommonObjectInfoTable::GetXrPassthroughLayerFBInfo);

    XrResult replay_result = GetInstanceTable(in_layer)->DestroyPassthroughLayerFB(in_layer);
    CheckResult("xrDestroyPassthroughLayerFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyPassthroughLayerFB>::UpdateState(this, call_info, returnValue, layer, replay_result);
    RemoveHandle(layer, &CommonObjectInfoTable::RemoveXrPassthroughLayerFBInfo);
}

void OpenXrReplayConsumer::Process_xrPassthroughLayerPauseFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer)
{
    XrPassthroughLayerFB in_layer = MapHandle<OpenXrPassthroughLayerFBInfo>(layer, &CommonObjectInfoTable::GetXrPassthroughLayerFBInfo);

    XrResult replay_result = GetInstanceTable(in_layer)->PassthroughLayerPauseFB(in_layer);
    CheckResult("xrPassthroughLayerPauseFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrPassthroughLayerPauseFB>::UpdateState(this, call_info, returnValue, layer, replay_result);
}

void OpenXrReplayConsumer::Process_xrPassthroughLayerResumeFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer)
{
    XrPassthroughLayerFB in_layer = MapHandle<OpenXrPassthroughLayerFBInfo>(layer, &CommonObjectInfoTable::GetXrPassthroughLayerFBInfo);

    XrResult replay_result = GetInstanceTable(in_layer)->PassthroughLayerResumeFB(in_layer);
    CheckResult("xrPassthroughLayerResumeFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrPassthroughLayerResumeFB>::UpdateState(this, call_info, returnValue, layer, replay_result);
}

void OpenXrReplayConsumer::Process_xrPassthroughLayerSetStyleFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer,
    StructPointerDecoder<Decoded_XrPassthroughStyleFB>* style)
{
    XrPassthroughLayerFB in_layer = MapHandle<OpenXrPassthroughLayerFBInfo>(layer, &CommonObjectInfoTable::GetXrPassthroughLayerFBInfo);
    const XrPassthroughStyleFB* in_style = style->GetPointer();
    MapStructHandles(style->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_layer)->PassthroughLayerSetStyleFB(in_layer, in_style);
    CheckResult("xrPassthroughLayerSetStyleFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrPassthroughLayerSetStyleFB>::UpdateState(this, call_info, returnValue, layer, style, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateGeometryInstanceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrGeometryInstanceCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrGeometryInstanceFB>* outGeometryInstance)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrGeometryInstanceCreateInfoFB* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!outGeometryInstance->IsNull()) { outGeometryInstance->SetHandleLength(1); }
    XrGeometryInstanceFB* out_outGeometryInstance = outGeometryInstance->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateGeometryInstanceFB(in_session, in_createInfo, out_outGeometryInstance);
    CheckResult("xrCreateGeometryInstanceFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrGeometryInstanceFBInfo>(session, outGeometryInstance->GetPointer(), out_outGeometryInstance, &CommonObjectInfoTable::AddXrGeometryInstanceFBInfo);
    
    AssociateParent(*out_outGeometryInstance, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateGeometryInstanceFB>::UpdateState(this, call_info, returnValue, session, createInfo, outGeometryInstance, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyGeometryInstanceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance)
{
    XrGeometryInstanceFB in_instance = MapHandle<OpenXrGeometryInstanceFBInfo>(instance, &CommonObjectInfoTable::GetXrGeometryInstanceFBInfo);

    XrResult replay_result = GetInstanceTable(in_instance)->DestroyGeometryInstanceFB(in_instance);
    CheckResult("xrDestroyGeometryInstanceFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyGeometryInstanceFB>::UpdateState(this, call_info, returnValue, instance, replay_result);
    RemoveHandle(instance, &CommonObjectInfoTable::RemoveXrGeometryInstanceFBInfo);
}

void OpenXrReplayConsumer::Process_xrGeometryInstanceSetTransformFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrGeometryInstanceTransformFB>* transformation)
{
    XrGeometryInstanceFB in_instance = MapHandle<OpenXrGeometryInstanceFBInfo>(instance, &CommonObjectInfoTable::GetXrGeometryInstanceFBInfo);
    const XrGeometryInstanceTransformFB* in_transformation = transformation->GetPointer();
    MapStructHandles(transformation->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_instance)->GeometryInstanceSetTransformFB(in_instance, in_transformation);
    CheckResult("xrGeometryInstanceSetTransformFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGeometryInstanceSetTransformFB>::UpdateState(this, call_info, returnValue, instance, transformation, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateRenderModelPathsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    pathCapacityInput,
    PointerDecoder<uint32_t>*                   pathCountOutput,
    StructPointerDecoder<Decoded_XrRenderModelPathInfoFB>* paths)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    uint32_t* out_pathCountOutput = pathCountOutput->IsNull() ? nullptr : pathCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrRenderModelPathInfoFB* out_paths = paths->IsNull() ? nullptr : paths->AllocateOutputData(pathCapacityInput, XrRenderModelPathInfoFB{ XR_TYPE_RENDER_MODEL_PATH_INFO_FB, nullptr });

    XrResult replay_result = GetInstanceTable(in_session)->EnumerateRenderModelPathsFB(in_session, pathCapacityInput, out_pathCountOutput, out_paths);
    CheckResult("xrEnumerateRenderModelPathsFB", returnValue, replay_result, call_info);

    AddStructArrayHandles<Decoded_XrRenderModelPathInfoFB>(session, paths->GetMetaStructPointer(), paths->GetLength(), out_paths, pathCapacityInput, &GetObjectInfoTable());
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateRenderModelPathsFB>::UpdateState(this, call_info, returnValue, session, pathCapacityInput, pathCountOutput, paths, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetRenderModelPropertiesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            path,
    StructPointerDecoder<Decoded_XrRenderModelPropertiesFB>* properties)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPath in_path = MapHandle<OpenXrPathInfo>(path, &CommonObjectInfoTable::GetXrPathInfo);
    XrRenderModelPropertiesFB* out_properties = properties->IsNull() ? nullptr : properties->AllocateOutputData(1, { XR_TYPE_RENDER_MODEL_PROPERTIES_FB, nullptr });
    InitializeOutputStructNext(properties);

    XrResult replay_result = GetInstanceTable(in_session)->GetRenderModelPropertiesFB(in_session, in_path, out_properties);
    CheckResult("xrGetRenderModelPropertiesFB", returnValue, replay_result, call_info);

    AddStructHandles(session, properties->GetMetaStructPointer(), out_properties, &GetObjectInfoTable());
    CustomProcess<format::ApiCallId::ApiCall_xrGetRenderModelPropertiesFB>::UpdateState(this, call_info, returnValue, session, path, properties, replay_result);
}

void OpenXrReplayConsumer::Process_xrLoadRenderModelFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrRenderModelLoadInfoFB>* info,
    StructPointerDecoder<Decoded_XrRenderModelBufferFB>* buffer)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrRenderModelLoadInfoFB* in_info = info->GetPointer();
    MapStructHandles(info->GetMetaStructPointer(), GetObjectInfoTable());
    XrRenderModelBufferFB* out_buffer = buffer->IsNull() ? nullptr : buffer->AllocateOutputData(1, { XR_TYPE_RENDER_MODEL_BUFFER_FB, nullptr });
    InitializeOutputStructNext(buffer);

    XrResult replay_result = GetInstanceTable(in_session)->LoadRenderModelFB(in_session, in_info, out_buffer);
    CheckResult("xrLoadRenderModelFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrLoadRenderModelFB>::UpdateState(this, call_info, returnValue, session, info, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetEnvironmentDepthEstimationVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrBool32                                    enabled)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetEnvironmentDepthEstimationVARJO(in_session, enabled);
    CheckResult("xrSetEnvironmentDepthEstimationVARJO", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetEnvironmentDepthEstimationVARJO>::UpdateState(this, call_info, returnValue, session, enabled, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetMarkerTrackingVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrBool32                                    enabled)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetMarkerTrackingVARJO(in_session, enabled);
    CheckResult("xrSetMarkerTrackingVARJO", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetMarkerTrackingVARJO>::UpdateState(this, call_info, returnValue, session, enabled, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetMarkerTrackingTimeoutVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint64_t                                    markerId,
    XrDuration                                  timeout)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetMarkerTrackingTimeoutVARJO(in_session, markerId, timeout);
    CheckResult("xrSetMarkerTrackingTimeoutVARJO", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetMarkerTrackingTimeoutVARJO>::UpdateState(this, call_info, returnValue, session, markerId, timeout, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetMarkerTrackingPredictionVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint64_t                                    markerId,
    XrBool32                                    enable)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetMarkerTrackingPredictionVARJO(in_session, markerId, enable);
    CheckResult("xrSetMarkerTrackingPredictionVARJO", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetMarkerTrackingPredictionVARJO>::UpdateState(this, call_info, returnValue, session, markerId, enable, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetMarkerSizeVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint64_t                                    markerId,
    StructPointerDecoder<Decoded_XrExtent2Df>*  size)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrExtent2Df* out_size = size->IsNull() ? nullptr : size->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_session)->GetMarkerSizeVARJO(in_session, markerId, out_size);
    CheckResult("xrGetMarkerSizeVARJO", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetMarkerSizeVARJO>::UpdateState(this, call_info, returnValue, session, markerId, size, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateMarkerSpaceVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoVARJO>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrMarkerSpaceCreateInfoVARJO* in_createInfo = createInfo->GetPointer();
    if (!space->IsNull()) { space->SetHandleLength(1); }
    XrSpace* out_space = space->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateMarkerSpaceVARJO(in_session, in_createInfo, out_space);
    CheckResult("xrCreateMarkerSpaceVARJO", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(session, space->GetPointer(), out_space, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_space, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateMarkerSpaceVARJO>::UpdateState(this, call_info, returnValue, session, createInfo, space, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetViewOffsetVARJO(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    float                                       offset)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetViewOffsetVARJO(in_session, offset);
    CheckResult("xrSetViewOffsetVARJO", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetViewOffsetVARJO>::UpdateState(this, call_info, returnValue, session, offset, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSpaceFromCoordinateFrameUIDML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrCoordinateSpaceCreateInfoML>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrCoordinateSpaceCreateInfoML * in_createInfo = createInfo->GetPointer();
    if (!space->IsNull()) { space->SetHandleLength(1); }
    XrSpace* out_space = space->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSpaceFromCoordinateFrameUIDML(in_session, in_createInfo, out_space);
    CheckResult("xrCreateSpaceFromCoordinateFrameUIDML", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(session, space->GetPointer(), out_space, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_space, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSpaceFromCoordinateFrameUIDML>::UpdateState(this, call_info, returnValue, session, createInfo, space, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateMarkerDetectorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrMarkerDetectorCreateInfoML>* createInfo,
    HandlePointerDecoder<XrMarkerDetectorML>*   markerDetector)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrMarkerDetectorCreateInfoML* in_createInfo = createInfo->GetPointer();
    if (!markerDetector->IsNull()) { markerDetector->SetHandleLength(1); }
    XrMarkerDetectorML* out_markerDetector = markerDetector->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateMarkerDetectorML(in_session, in_createInfo, out_markerDetector);
    CheckResult("xrCreateMarkerDetectorML", returnValue, replay_result, call_info);

    AddHandle<OpenXrMarkerDetectorMLInfo>(session, markerDetector->GetPointer(), out_markerDetector, &CommonObjectInfoTable::AddXrMarkerDetectorMLInfo);
    
    AssociateParent(*out_markerDetector, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateMarkerDetectorML>::UpdateState(this, call_info, returnValue, session, createInfo, markerDetector, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyMarkerDetectorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector)
{
    XrMarkerDetectorML in_markerDetector = MapHandle<OpenXrMarkerDetectorMLInfo>(markerDetector, &CommonObjectInfoTable::GetXrMarkerDetectorMLInfo);

    XrResult replay_result = GetInstanceTable(in_markerDetector)->DestroyMarkerDetectorML(in_markerDetector);
    CheckResult("xrDestroyMarkerDetectorML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyMarkerDetectorML>::UpdateState(this, call_info, returnValue, markerDetector, replay_result);
    RemoveHandle(markerDetector, &CommonObjectInfoTable::RemoveXrMarkerDetectorMLInfo);
}

void OpenXrReplayConsumer::Process_xrSnapshotMarkerDetectorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    StructPointerDecoder<Decoded_XrMarkerDetectorSnapshotInfoML>* snapshotInfo)
{
    XrMarkerDetectorML in_markerDetector = MapHandle<OpenXrMarkerDetectorMLInfo>(markerDetector, &CommonObjectInfoTable::GetXrMarkerDetectorMLInfo);
    XrMarkerDetectorSnapshotInfoML* out_snapshotInfo = snapshotInfo->IsNull() ? nullptr : snapshotInfo->AllocateOutputData(1, { XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML, nullptr });
    InitializeOutputStructNext(snapshotInfo);

    XrResult replay_result = GetInstanceTable(in_markerDetector)->SnapshotMarkerDetectorML(in_markerDetector, out_snapshotInfo);
    CheckResult("xrSnapshotMarkerDetectorML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSnapshotMarkerDetectorML>::UpdateState(this, call_info, returnValue, markerDetector, snapshotInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetMarkerDetectorStateML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    StructPointerDecoder<Decoded_XrMarkerDetectorStateML>* state)
{
    XrMarkerDetectorML in_markerDetector = MapHandle<OpenXrMarkerDetectorMLInfo>(markerDetector, &CommonObjectInfoTable::GetXrMarkerDetectorMLInfo);
    XrMarkerDetectorStateML* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1, { XR_TYPE_MARKER_DETECTOR_STATE_ML, nullptr });
    InitializeOutputStructNext(state);

    XrResult replay_result = GetInstanceTable(in_markerDetector)->GetMarkerDetectorStateML(in_markerDetector, out_state);
    CheckResult("xrGetMarkerDetectorStateML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetMarkerDetectorStateML>::UpdateState(this, call_info, returnValue, markerDetector, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetMarkersML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    uint32_t                                    markerCapacityInput,
    PointerDecoder<uint32_t>*                   markerCountOutput,
    HandlePointerDecoder<XrMarkerML>*           markers)
{
    XrMarkerDetectorML in_markerDetector = MapHandle<OpenXrMarkerDetectorMLInfo>(markerDetector, &CommonObjectInfoTable::GetXrMarkerDetectorMLInfo);
    uint32_t* out_markerCountOutput = markerCountOutput->IsNull() ? nullptr : markerCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    if (!markers->IsNull()) { markers->SetHandleLength(markerCapacityInput); }
    XrMarkerML* out_markers = markers->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_markerDetector)->GetMarkersML(in_markerDetector, markerCapacityInput, out_markerCountOutput, out_markers);
    CheckResult("xrGetMarkersML", returnValue, replay_result, call_info);

    AddHandles<OpenXrMarkerMLInfo>(markerDetector, markers->GetPointer(), markers->GetLength(), out_markers, markerCapacityInput, &CommonObjectInfoTable::AddXrMarkerMLInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrGetMarkersML>::UpdateState(this, call_info, returnValue, markerDetector, markerCapacityInput, markerCountOutput, markers, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetMarkerReprojectionErrorML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    format::HandleId                            marker,
    PointerDecoder<float>*                      reprojectionErrorMeters)
{
    XrMarkerDetectorML in_markerDetector = MapHandle<OpenXrMarkerDetectorMLInfo>(markerDetector, &CommonObjectInfoTable::GetXrMarkerDetectorMLInfo);
    XrMarkerML in_marker = MapHandle<OpenXrMarkerMLInfo>(marker, &CommonObjectInfoTable::GetXrMarkerMLInfo);
    float* out_reprojectionErrorMeters = reprojectionErrorMeters->IsNull() ? nullptr : reprojectionErrorMeters->AllocateOutputData(1, static_cast<float>(0));

    XrResult replay_result = GetInstanceTable(in_markerDetector)->GetMarkerReprojectionErrorML(in_markerDetector, in_marker, out_reprojectionErrorMeters);
    CheckResult("xrGetMarkerReprojectionErrorML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetMarkerReprojectionErrorML>::UpdateState(this, call_info, returnValue, markerDetector, marker, reprojectionErrorMeters, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetMarkerLengthML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    format::HandleId                            marker,
    PointerDecoder<float>*                      meters)
{
    XrMarkerDetectorML in_markerDetector = MapHandle<OpenXrMarkerDetectorMLInfo>(markerDetector, &CommonObjectInfoTable::GetXrMarkerDetectorMLInfo);
    XrMarkerML in_marker = MapHandle<OpenXrMarkerMLInfo>(marker, &CommonObjectInfoTable::GetXrMarkerMLInfo);
    float* out_meters = meters->IsNull() ? nullptr : meters->AllocateOutputData(1, static_cast<float>(0));

    XrResult replay_result = GetInstanceTable(in_markerDetector)->GetMarkerLengthML(in_markerDetector, in_marker, out_meters);
    CheckResult("xrGetMarkerLengthML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetMarkerLengthML>::UpdateState(this, call_info, returnValue, markerDetector, marker, meters, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetMarkerNumberML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    format::HandleId                            marker,
    PointerDecoder<uint64_t>*                   number)
{
    XrMarkerDetectorML in_markerDetector = MapHandle<OpenXrMarkerDetectorMLInfo>(markerDetector, &CommonObjectInfoTable::GetXrMarkerDetectorMLInfo);
    XrMarkerML in_marker = MapHandle<OpenXrMarkerMLInfo>(marker, &CommonObjectInfoTable::GetXrMarkerMLInfo);
    uint64_t* out_number = number->IsNull() ? nullptr : number->AllocateOutputData(1, static_cast<uint64_t>(0));

    XrResult replay_result = GetInstanceTable(in_markerDetector)->GetMarkerNumberML(in_markerDetector, in_marker, out_number);
    CheckResult("xrGetMarkerNumberML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetMarkerNumberML>::UpdateState(this, call_info, returnValue, markerDetector, marker, number, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetMarkerStringML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            markerDetector,
    format::HandleId                            marker,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    XrMarkerDetectorML in_markerDetector = MapHandle<OpenXrMarkerDetectorMLInfo>(markerDetector, &CommonObjectInfoTable::GetXrMarkerDetectorMLInfo);
    XrMarkerML in_marker = MapHandle<OpenXrMarkerMLInfo>(marker, &CommonObjectInfoTable::GetXrMarkerMLInfo);
    uint32_t* out_bufferCountOutput = bufferCountOutput->IsNull() ? nullptr : bufferCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    char* out_buffer = buffer->GetPointer();

    XrResult replay_result = GetInstanceTable(in_markerDetector)->GetMarkerStringML(in_markerDetector, in_marker, bufferCapacityInput, out_bufferCountOutput, out_buffer);
    CheckResult("xrGetMarkerStringML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetMarkerStringML>::UpdateState(this, call_info, returnValue, markerDetector, marker, bufferCapacityInput, bufferCountOutput, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateMarkerSpaceML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoML>* createInfo,
    HandlePointerDecoder<XrSpace>*              space)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrMarkerSpaceCreateInfoML* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!space->IsNull()) { space->SetHandleLength(1); }
    XrSpace* out_space = space->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateMarkerSpaceML(in_session, in_createInfo, out_space);
    CheckResult("xrCreateMarkerSpaceML", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(session, space->GetPointer(), out_space, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_space, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateMarkerSpaceML>::UpdateState(this, call_info, returnValue, session, createInfo, space, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnableLocalizationEventsML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrLocalizationEnableEventsInfoML>* info)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrLocalizationEnableEventsInfoML * in_info = info->GetPointer();

    XrResult replay_result = GetInstanceTable(in_session)->EnableLocalizationEventsML(in_session, in_info);
    CheckResult("xrEnableLocalizationEventsML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnableLocalizationEventsML>::UpdateState(this, call_info, returnValue, session, info, replay_result);
}

void OpenXrReplayConsumer::Process_xrQueryLocalizationMapsML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrLocalizationMapQueryInfoBaseHeaderML>* queryInfo,
    uint32_t                                    mapCapacityInput,
    PointerDecoder<uint32_t>*                   mapCountOutput,
    StructPointerDecoder<Decoded_XrLocalizationMapML>* maps)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrLocalizationMapQueryInfoBaseHeaderML* in_queryInfo = queryInfo->GetPointer();
    uint32_t * out_mapCountOutput = mapCountOutput->IsNull() ? nullptr : mapCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrLocalizationMapML* out_maps = maps->IsNull() ? nullptr : maps->AllocateOutputData(mapCapacityInput, XrLocalizationMapML{ XR_TYPE_LOCALIZATION_MAP_ML, nullptr });

    XrResult replay_result = GetInstanceTable(in_session)->QueryLocalizationMapsML(in_session, in_queryInfo, mapCapacityInput, out_mapCountOutput, out_maps);
    CheckResult("xrQueryLocalizationMapsML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrQueryLocalizationMapsML>::UpdateState(this, call_info, returnValue, session, queryInfo, mapCapacityInput, mapCountOutput, maps, replay_result);
}

void OpenXrReplayConsumer::Process_xrRequestMapLocalizationML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrMapLocalizationRequestInfoML>* requestInfo)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrMapLocalizationRequestInfoML* in_requestInfo = requestInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_session)->RequestMapLocalizationML(in_session, in_requestInfo);
    CheckResult("xrRequestMapLocalizationML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrRequestMapLocalizationML>::UpdateState(this, call_info, returnValue, session, requestInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrImportLocalizationMapML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrLocalizationMapImportInfoML>* importInfo,
    StructPointerDecoder<Decoded_XrUuid>*       mapUuid)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrLocalizationMapImportInfoML* in_importInfo = importInfo->GetPointer();
    XrUuidEXT* out_mapUuid = mapUuid->IsNull() ? nullptr : mapUuid->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_session)->ImportLocalizationMapML(in_session, in_importInfo, out_mapUuid);
    CheckResult("xrImportLocalizationMapML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrImportLocalizationMapML>::UpdateState(this, call_info, returnValue, session, importInfo, mapUuid, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateExportedLocalizationMapML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrUuid>*       mapUuid,
    HandlePointerDecoder<XrExportedLocalizationMapML>* map)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrUuidEXT* in_mapUuid = mapUuid->GetPointer();
    if (!map->IsNull()) { map->SetHandleLength(1); }
    XrExportedLocalizationMapML* out_map = map->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateExportedLocalizationMapML(in_session, in_mapUuid, out_map);
    CheckResult("xrCreateExportedLocalizationMapML", returnValue, replay_result, call_info);

    AddHandle<OpenXrExportedLocalizationMapMLInfo>(session, map->GetPointer(), out_map, &CommonObjectInfoTable::AddXrExportedLocalizationMapMLInfo);
    
    AssociateParent(*out_map, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateExportedLocalizationMapML>::UpdateState(this, call_info, returnValue, session, mapUuid, map, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyExportedLocalizationMapML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            map)
{
    XrExportedLocalizationMapML in_map = MapHandle<OpenXrExportedLocalizationMapMLInfo>(map, &CommonObjectInfoTable::GetXrExportedLocalizationMapMLInfo);

    XrResult replay_result = GetInstanceTable(in_map)->DestroyExportedLocalizationMapML(in_map);
    CheckResult("xrDestroyExportedLocalizationMapML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyExportedLocalizationMapML>::UpdateState(this, call_info, returnValue, map, replay_result);
    RemoveHandle(map, &CommonObjectInfoTable::RemoveXrExportedLocalizationMapMLInfo);
}

void OpenXrReplayConsumer::Process_xrGetExportedLocalizationMapDataML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            map,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    XrExportedLocalizationMapML in_map = MapHandle<OpenXrExportedLocalizationMapMLInfo>(map, &CommonObjectInfoTable::GetXrExportedLocalizationMapMLInfo);
    uint32_t* out_bufferCountOutput = bufferCountOutput->IsNull() ? nullptr : bufferCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    char* out_buffer = buffer->GetPointer();

    XrResult replay_result = GetInstanceTable(in_map)->GetExportedLocalizationMapDataML(in_map, bufferCapacityInput, out_bufferCountOutput, out_buffer);
    CheckResult("xrGetExportedLocalizationMapDataML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetExportedLocalizationMapDataML>::UpdateState(this, call_info, returnValue, map, bufferCapacityInput, bufferCountOutput, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSpatialAnchorStoreConnectionMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    HandlePointerDecoder<XrSpatialAnchorStoreConnectionMSFT>* spatialAnchorStore)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    if (!spatialAnchorStore->IsNull()) { spatialAnchorStore->SetHandleLength(1); }
    XrSpatialAnchorStoreConnectionMSFT* out_spatialAnchorStore = spatialAnchorStore->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSpatialAnchorStoreConnectionMSFT(in_session, out_spatialAnchorStore);
    CheckResult("xrCreateSpatialAnchorStoreConnectionMSFT", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(session, spatialAnchorStore->GetPointer(), out_spatialAnchorStore, &CommonObjectInfoTable::AddXrSpatialAnchorStoreConnectionMSFTInfo);
    
    AssociateParent(*out_spatialAnchorStore, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT>::UpdateState(this, call_info, returnValue, session, spatialAnchorStore, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroySpatialAnchorStoreConnectionMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore)
{
    XrSpatialAnchorStoreConnectionMSFT in_spatialAnchorStore = MapHandle<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(spatialAnchorStore, &CommonObjectInfoTable::GetXrSpatialAnchorStoreConnectionMSFTInfo);

    XrResult replay_result = GetInstanceTable(in_spatialAnchorStore)->DestroySpatialAnchorStoreConnectionMSFT(in_spatialAnchorStore);
    CheckResult("xrDestroySpatialAnchorStoreConnectionMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT>::UpdateState(this, call_info, returnValue, spatialAnchorStore, replay_result);
    RemoveHandle(spatialAnchorStore, &CommonObjectInfoTable::RemoveXrSpatialAnchorStoreConnectionMSFTInfo);
}

void OpenXrReplayConsumer::Process_xrPersistSpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore,
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceInfoMSFT>* spatialAnchorPersistenceInfo)
{
    XrSpatialAnchorStoreConnectionMSFT in_spatialAnchorStore = MapHandle<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(spatialAnchorStore, &CommonObjectInfoTable::GetXrSpatialAnchorStoreConnectionMSFTInfo);
    const XrSpatialAnchorPersistenceInfoMSFT* in_spatialAnchorPersistenceInfo = spatialAnchorPersistenceInfo->GetPointer();
    MapStructHandles(spatialAnchorPersistenceInfo->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_spatialAnchorStore)->PersistSpatialAnchorMSFT(in_spatialAnchorStore, in_spatialAnchorPersistenceInfo);
    CheckResult("xrPersistSpatialAnchorMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrPersistSpatialAnchorMSFT>::UpdateState(this, call_info, returnValue, spatialAnchorStore, spatialAnchorPersistenceInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumeratePersistedSpatialAnchorNamesMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore,
    uint32_t                                    spatialAnchorNameCapacityInput,
    PointerDecoder<uint32_t>*                   spatialAnchorNameCountOutput,
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT>* spatialAnchorNames)
{
    XrSpatialAnchorStoreConnectionMSFT in_spatialAnchorStore = MapHandle<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(spatialAnchorStore, &CommonObjectInfoTable::GetXrSpatialAnchorStoreConnectionMSFTInfo);
    uint32_t* out_spatialAnchorNameCountOutput = spatialAnchorNameCountOutput->IsNull() ? nullptr : spatialAnchorNameCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrSpatialAnchorPersistenceNameMSFT* out_spatialAnchorNames = spatialAnchorNames->IsNull() ? nullptr : spatialAnchorNames->AllocateOutputData(spatialAnchorNameCapacityInput);

    XrResult replay_result = GetInstanceTable(in_spatialAnchorStore)->EnumeratePersistedSpatialAnchorNamesMSFT(in_spatialAnchorStore, spatialAnchorNameCapacityInput, out_spatialAnchorNameCountOutput, out_spatialAnchorNames);
    CheckResult("xrEnumeratePersistedSpatialAnchorNamesMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT>::UpdateState(this, call_info, returnValue, spatialAnchorStore, spatialAnchorNameCapacityInput, spatialAnchorNameCountOutput, spatialAnchorNames, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSpatialAnchorFromPersistedNameMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT>* spatialAnchorCreateInfo,
    HandlePointerDecoder<XrSpatialAnchorMSFT>*  spatialAnchor)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* in_spatialAnchorCreateInfo = spatialAnchorCreateInfo->GetPointer();
    MapStructHandles(spatialAnchorCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!spatialAnchor->IsNull()) { spatialAnchor->SetHandleLength(1); }
    XrSpatialAnchorMSFT* out_spatialAnchor = spatialAnchor->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSpatialAnchorFromPersistedNameMSFT(in_session, in_spatialAnchorCreateInfo, out_spatialAnchor);
    CheckResult("xrCreateSpatialAnchorFromPersistedNameMSFT", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpatialAnchorMSFTInfo>(session, spatialAnchor->GetPointer(), out_spatialAnchor, &CommonObjectInfoTable::AddXrSpatialAnchorMSFTInfo);
    
    AssociateParent(*out_spatialAnchor, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT>::UpdateState(this, call_info, returnValue, session, spatialAnchorCreateInfo, spatialAnchor, replay_result);
}

void OpenXrReplayConsumer::Process_xrUnpersistSpatialAnchorMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore,
    StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT>* spatialAnchorPersistenceName)
{
    XrSpatialAnchorStoreConnectionMSFT in_spatialAnchorStore = MapHandle<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(spatialAnchorStore, &CommonObjectInfoTable::GetXrSpatialAnchorStoreConnectionMSFTInfo);
    const XrSpatialAnchorPersistenceNameMSFT* in_spatialAnchorPersistenceName = spatialAnchorPersistenceName->GetPointer();

    XrResult replay_result = GetInstanceTable(in_spatialAnchorStore)->UnpersistSpatialAnchorMSFT(in_spatialAnchorStore, in_spatialAnchorPersistenceName);
    CheckResult("xrUnpersistSpatialAnchorMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrUnpersistSpatialAnchorMSFT>::UpdateState(this, call_info, returnValue, spatialAnchorStore, spatialAnchorPersistenceName, replay_result);
}

void OpenXrReplayConsumer::Process_xrClearSpatialAnchorStoreMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            spatialAnchorStore)
{
    XrSpatialAnchorStoreConnectionMSFT in_spatialAnchorStore = MapHandle<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(spatialAnchorStore, &CommonObjectInfoTable::GetXrSpatialAnchorStoreConnectionMSFTInfo);

    XrResult replay_result = GetInstanceTable(in_spatialAnchorStore)->ClearSpatialAnchorStoreMSFT(in_spatialAnchorStore);
    CheckResult("xrClearSpatialAnchorStoreMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrClearSpatialAnchorStoreMSFT>::UpdateState(this, call_info, returnValue, spatialAnchorStore, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSceneMarkerRawDataMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrUuidMSFT>*   markerId,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    PointerDecoder<uint8_t>*                    buffer)
{
    XrSceneMSFT in_scene = MapHandle<OpenXrSceneMSFTInfo>(scene, &CommonObjectInfoTable::GetXrSceneMSFTInfo);
    const XrUuidMSFT* in_markerId = markerId->GetPointer();
    uint32_t* out_bufferCountOutput = bufferCountOutput->IsNull() ? nullptr : bufferCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    uint8_t* out_buffer = buffer->IsNull() ? nullptr : buffer->AllocateOutputData(bufferCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!buffer->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_scene)->GetSceneMarkerRawDataMSFT(in_scene, in_markerId, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < bufferCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrGetSceneMarkerRawDataMSFT replay size %d is smaller than capture size %d",
                replay_count,
                bufferCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<uint8_t> temp_buffer(replay_count);
        replay_result = GetInstanceTable(in_scene)->GetSceneMarkerRawDataMSFT(in_scene, in_markerId, temp_buffer.size(), out_bufferCountOutput, temp_buffer.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            uint8_t* original_buffer = buffer->GetPointer();
            for (uint32_t iii = 0; iii < bufferCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_buffer[jjj] == original_buffer[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrGetSceneMarkerRawDataMSFT failed to find a value of %d during replay",
                        original_buffer[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_scene)->GetSceneMarkerRawDataMSFT(in_scene, in_markerId, bufferCapacityInput, out_bufferCountOutput, out_buffer);
    }
    CheckResult("xrGetSceneMarkerRawDataMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSceneMarkerRawDataMSFT>::UpdateState(this, call_info, returnValue, scene, markerId, bufferCapacityInput, bufferCountOutput, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSceneMarkerDecodedStringMSFT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            scene,
    StructPointerDecoder<Decoded_XrUuidMSFT>*   markerId,
    uint32_t                                    bufferCapacityInput,
    PointerDecoder<uint32_t>*                   bufferCountOutput,
    StringDecoder*                              buffer)
{
    XrSceneMSFT in_scene = MapHandle<OpenXrSceneMSFTInfo>(scene, &CommonObjectInfoTable::GetXrSceneMSFTInfo);
    const XrUuidMSFT* in_markerId = markerId->GetPointer();
    uint32_t* out_bufferCountOutput = bufferCountOutput->IsNull() ? nullptr : bufferCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    char* out_buffer = buffer->GetPointer();

    XrResult replay_result = XR_SUCCESS;
    if (!buffer->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_scene)->GetSceneMarkerDecodedStringMSFT(in_scene, in_markerId, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < bufferCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrGetSceneMarkerDecodedStringMSFT replay size %d is smaller than capture size %d",
                replay_count,
                bufferCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<char> temp_buffer(replay_count);
        replay_result = GetInstanceTable(in_scene)->GetSceneMarkerDecodedStringMSFT(in_scene, in_markerId, temp_buffer.size(), out_bufferCountOutput, temp_buffer.data());
    }
    else
    {
        replay_result = GetInstanceTable(in_scene)->GetSceneMarkerDecodedStringMSFT(in_scene, in_markerId, bufferCapacityInput, out_bufferCountOutput, out_buffer);
    }
    CheckResult("xrGetSceneMarkerDecodedStringMSFT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSceneMarkerDecodedStringMSFT>::UpdateState(this, call_info, returnValue, scene, markerId, bufferCapacityInput, bufferCountOutput, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrQuerySpacesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceQueryInfoBaseHeaderFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpaceQueryInfoBaseHeaderFB* in_info = info->GetPointer();
    if (!requestId->IsNull()) { requestId->SetHandleLength(1); }
    XrAsyncRequestIdFB* out_requestId = requestId->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->QuerySpacesFB(in_session, in_info, out_requestId);
    CheckResult("xrQuerySpacesFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrAsyncRequestIdFBInfo>(session, requestId->GetPointer(), out_requestId, &CommonObjectInfoTable::AddXrAsyncRequestIdFBInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrQuerySpacesFB>::UpdateState(this, call_info, returnValue, session, info, requestId, replay_result);
}

void OpenXrReplayConsumer::Process_xrRetrieveSpaceQueryResultsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            requestId,
    StructPointerDecoder<Decoded_XrSpaceQueryResultsFB>* results)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrAsyncRequestIdFB in_requestId = MapHandle<OpenXrAsyncRequestIdFBInfo>(requestId, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);
    XrSpaceQueryResultsFB* out_results = results->IsNull() ? nullptr : results->AllocateOutputData(1, { XR_TYPE_SPACE_QUERY_RESULTS_FB, nullptr });
    InitializeOutputStructNext(results);

    XrResult replay_result = GetInstanceTable(in_session)->RetrieveSpaceQueryResultsFB(in_session, in_requestId, out_results);
    CheckResult("xrRetrieveSpaceQueryResultsFB", returnValue, replay_result, call_info);

    AddStructHandles(session, results->GetMetaStructPointer(), out_results, &GetObjectInfoTable());
    CustomProcess<format::ApiCallId::ApiCall_xrRetrieveSpaceQueryResultsFB>::UpdateState(this, call_info, returnValue, session, requestId, results, replay_result);
}

void OpenXrReplayConsumer::Process_xrSaveSpaceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceSaveInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpaceSaveInfoFB* in_info = info->GetPointer();
    MapStructHandles(info->GetMetaStructPointer(), GetObjectInfoTable());
    if (!requestId->IsNull()) { requestId->SetHandleLength(1); }
    XrAsyncRequestIdFB* out_requestId = requestId->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->SaveSpaceFB(in_session, in_info, out_requestId);
    CheckResult("xrSaveSpaceFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrAsyncRequestIdFBInfo>(session, requestId->GetPointer(), out_requestId, &CommonObjectInfoTable::AddXrAsyncRequestIdFBInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrSaveSpaceFB>::UpdateState(this, call_info, returnValue, session, info, requestId, replay_result);
}

void OpenXrReplayConsumer::Process_xrEraseSpaceFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceEraseInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpaceEraseInfoFB* in_info = info->GetPointer();
    MapStructHandles(info->GetMetaStructPointer(), GetObjectInfoTable());
    if (!requestId->IsNull()) { requestId->SetHandleLength(1); }
    XrAsyncRequestIdFB* out_requestId = requestId->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->EraseSpaceFB(in_session, in_info, out_requestId);
    CheckResult("xrEraseSpaceFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrAsyncRequestIdFBInfo>(session, requestId->GetPointer(), out_requestId, &CommonObjectInfoTable::AddXrAsyncRequestIdFBInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrEraseSpaceFB>::UpdateState(this, call_info, returnValue, session, info, requestId, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetAudioOutputDeviceGuidOculus(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    WStringDecoder*                             buffer)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    wchar_t* out_buffer = buffer->GetPointer();

    XrResult replay_result = GetInstanceTable(in_instance)->GetAudioOutputDeviceGuidOculus(in_instance, out_buffer);
    CheckResult("xrGetAudioOutputDeviceGuidOculus", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetAudioOutputDeviceGuidOculus>::UpdateState(this, call_info, returnValue, instance, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetAudioInputDeviceGuidOculus(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    WStringDecoder*                             buffer)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    wchar_t* out_buffer = buffer->GetPointer();

    XrResult replay_result = GetInstanceTable(in_instance)->GetAudioInputDeviceGuidOculus(in_instance, out_buffer);
    CheckResult("xrGetAudioInputDeviceGuidOculus", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetAudioInputDeviceGuidOculus>::UpdateState(this, call_info, returnValue, instance, buffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrShareSpacesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceShareInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpaceShareInfoFB* in_info = info->GetPointer();
    MapStructHandles(info->GetMetaStructPointer(), GetObjectInfoTable());
    if (!requestId->IsNull()) { requestId->SetHandleLength(1); }
    XrAsyncRequestIdFB* out_requestId = requestId->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->ShareSpacesFB(in_session, in_info, out_requestId);
    CheckResult("xrShareSpacesFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrAsyncRequestIdFBInfo>(session, requestId->GetPointer(), out_requestId, &CommonObjectInfoTable::AddXrAsyncRequestIdFBInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrShareSpacesFB>::UpdateState(this, call_info, returnValue, session, info, requestId, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpaceBoundingBox2DFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrRect2Df>*    boundingBox2DOutput)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrRect2Df* out_boundingBox2DOutput = boundingBox2DOutput->IsNull() ? nullptr : boundingBox2DOutput->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_session)->GetSpaceBoundingBox2DFB(in_session, in_space, out_boundingBox2DOutput);
    CheckResult("xrGetSpaceBoundingBox2DFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox2DFB>::UpdateState(this, call_info, returnValue, session, space, boundingBox2DOutput, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpaceBoundingBox3DFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrRect3DfFB>*  boundingBox3DOutput)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrRect3DfFB* out_boundingBox3DOutput = boundingBox3DOutput->IsNull() ? nullptr : boundingBox3DOutput->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_session)->GetSpaceBoundingBox3DFB(in_session, in_space, out_boundingBox3DOutput);
    CheckResult("xrGetSpaceBoundingBox3DFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox3DFB>::UpdateState(this, call_info, returnValue, session, space, boundingBox3DOutput, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpaceSemanticLabelsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrSemanticLabelsFB>* semanticLabelsOutput)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrSemanticLabelsFB* out_semanticLabelsOutput = semanticLabelsOutput->IsNull() ? nullptr : semanticLabelsOutput->AllocateOutputData(1, { XR_TYPE_SEMANTIC_LABELS_FB, nullptr });
    InitializeOutputStructNext(semanticLabelsOutput);

    XrResult replay_result = GetInstanceTable(in_session)->GetSpaceSemanticLabelsFB(in_session, in_space, out_semanticLabelsOutput);
    CheckResult("xrGetSpaceSemanticLabelsFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpaceSemanticLabelsFB>::UpdateState(this, call_info, returnValue, session, space, semanticLabelsOutput, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpaceBoundary2DFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrBoundary2DFB>* boundary2DOutput)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrBoundary2DFB* out_boundary2DOutput = boundary2DOutput->IsNull() ? nullptr : boundary2DOutput->AllocateOutputData(1, { XR_TYPE_BOUNDARY_2D_FB, nullptr });
    InitializeOutputStructNext(boundary2DOutput);

    XrResult replay_result = GetInstanceTable(in_session)->GetSpaceBoundary2DFB(in_session, in_space, out_boundary2DOutput);
    CheckResult("xrGetSpaceBoundary2DFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpaceBoundary2DFB>::UpdateState(this, call_info, returnValue, session, space, boundary2DOutput, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpaceRoomLayoutFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrRoomLayoutFB>* roomLayoutOutput)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrRoomLayoutFB* out_roomLayoutOutput = roomLayoutOutput->IsNull() ? nullptr : roomLayoutOutput->AllocateOutputData(1, { XR_TYPE_ROOM_LAYOUT_FB, nullptr });
    InitializeOutputStructNext(roomLayoutOutput);

    XrResult replay_result = GetInstanceTable(in_session)->GetSpaceRoomLayoutFB(in_session, in_space, out_roomLayoutOutput);
    CheckResult("xrGetSpaceRoomLayoutFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpaceRoomLayoutFB>::UpdateState(this, call_info, returnValue, session, space, roomLayoutOutput, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetDigitalLensControlALMALENCE(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrDigitalLensControlALMALENCE>* digitalLensControl)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrDigitalLensControlALMALENCE* in_digitalLensControl = digitalLensControl->GetPointer();

    XrResult replay_result = GetInstanceTable(in_session)->SetDigitalLensControlALMALENCE(in_session, in_digitalLensControl);
    CheckResult("xrSetDigitalLensControlALMALENCE", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetDigitalLensControlALMALENCE>::UpdateState(this, call_info, returnValue, session, digitalLensControl, replay_result);
}

void OpenXrReplayConsumer::Process_xrRequestSceneCaptureFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSceneCaptureRequestInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSceneCaptureRequestInfoFB* in_info = info->GetPointer();
    if (!requestId->IsNull()) { requestId->SetHandleLength(1); }
    XrAsyncRequestIdFB* out_requestId = requestId->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->RequestSceneCaptureFB(in_session, in_info, out_requestId);
    CheckResult("xrRequestSceneCaptureFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrAsyncRequestIdFBInfo>(session, requestId->GetPointer(), out_requestId, &CommonObjectInfoTable::AddXrAsyncRequestIdFBInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrRequestSceneCaptureFB>::UpdateState(this, call_info, returnValue, session, info, requestId, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpaceContainerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrSpaceContainerFB>* spaceContainerOutput)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrSpaceContainerFB* out_spaceContainerOutput = spaceContainerOutput->IsNull() ? nullptr : spaceContainerOutput->AllocateOutputData(1, { XR_TYPE_SPACE_CONTAINER_FB, nullptr });
    InitializeOutputStructNext(spaceContainerOutput);

    XrResult replay_result = GetInstanceTable(in_session)->GetSpaceContainerFB(in_session, in_space, out_spaceContainerOutput);
    CheckResult("xrGetSpaceContainerFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpaceContainerFB>::UpdateState(this, call_info, returnValue, session, space, spaceContainerOutput, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetFoveationEyeTrackedStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFoveationEyeTrackedStateMETA>* foveationState)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrFoveationEyeTrackedStateMETA* out_foveationState = foveationState->IsNull() ? nullptr : foveationState->AllocateOutputData(1, { XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META, nullptr });
    InitializeOutputStructNext(foveationState);

    XrResult replay_result = GetInstanceTable(in_session)->GetFoveationEyeTrackedStateMETA(in_session, out_foveationState);
    CheckResult("xrGetFoveationEyeTrackedStateMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetFoveationEyeTrackedStateMETA>::UpdateState(this, call_info, returnValue, session, foveationState, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateFaceTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFaceTrackerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrFaceTrackerFB>*      faceTracker)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrFaceTrackerCreateInfoFB* in_createInfo = createInfo->GetPointer();
    if (!faceTracker->IsNull()) { faceTracker->SetHandleLength(1); }
    XrFaceTrackerFB* out_faceTracker = faceTracker->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateFaceTrackerFB(in_session, in_createInfo, out_faceTracker);
    CheckResult("xrCreateFaceTrackerFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrFaceTrackerFBInfo>(session, faceTracker->GetPointer(), out_faceTracker, &CommonObjectInfoTable::AddXrFaceTrackerFBInfo);
    
    AssociateParent(*out_faceTracker, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateFaceTrackerFB>::UpdateState(this, call_info, returnValue, session, createInfo, faceTracker, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyFaceTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            faceTracker)
{
    XrFaceTrackerFB in_faceTracker = MapHandle<OpenXrFaceTrackerFBInfo>(faceTracker, &CommonObjectInfoTable::GetXrFaceTrackerFBInfo);

    XrResult replay_result = GetInstanceTable(in_faceTracker)->DestroyFaceTrackerFB(in_faceTracker);
    CheckResult("xrDestroyFaceTrackerFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyFaceTrackerFB>::UpdateState(this, call_info, returnValue, faceTracker, replay_result);
    RemoveHandle(faceTracker, &CommonObjectInfoTable::RemoveXrFaceTrackerFBInfo);
}

void OpenXrReplayConsumer::Process_xrGetFaceExpressionWeightsFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            faceTracker,
    StructPointerDecoder<Decoded_XrFaceExpressionInfoFB>* expressionInfo,
    StructPointerDecoder<Decoded_XrFaceExpressionWeightsFB>* expressionWeights)
{
    XrFaceTrackerFB in_faceTracker = MapHandle<OpenXrFaceTrackerFBInfo>(faceTracker, &CommonObjectInfoTable::GetXrFaceTrackerFBInfo);
    const XrFaceExpressionInfoFB* in_expressionInfo = expressionInfo->GetPointer();
    XrFaceExpressionWeightsFB* out_expressionWeights = expressionWeights->IsNull() ? nullptr : expressionWeights->AllocateOutputData(1, { XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB, nullptr });
    InitializeOutputStructNext(expressionWeights);

    XrResult replay_result = GetInstanceTable(in_faceTracker)->GetFaceExpressionWeightsFB(in_faceTracker, in_expressionInfo, out_expressionWeights);
    CheckResult("xrGetFaceExpressionWeightsFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetFaceExpressionWeightsFB>::UpdateState(this, call_info, returnValue, faceTracker, expressionInfo, expressionWeights, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateEyeTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrEyeTrackerCreateInfoFB>* createInfo,
    HandlePointerDecoder<XrEyeTrackerFB>*       eyeTracker)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrEyeTrackerCreateInfoFB* in_createInfo = createInfo->GetPointer();
    if (!eyeTracker->IsNull()) { eyeTracker->SetHandleLength(1); }
    XrEyeTrackerFB* out_eyeTracker = eyeTracker->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateEyeTrackerFB(in_session, in_createInfo, out_eyeTracker);
    CheckResult("xrCreateEyeTrackerFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrEyeTrackerFBInfo>(session, eyeTracker->GetPointer(), out_eyeTracker, &CommonObjectInfoTable::AddXrEyeTrackerFBInfo);
    
    AssociateParent(*out_eyeTracker, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateEyeTrackerFB>::UpdateState(this, call_info, returnValue, session, createInfo, eyeTracker, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyEyeTrackerFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            eyeTracker)
{
    XrEyeTrackerFB in_eyeTracker = MapHandle<OpenXrEyeTrackerFBInfo>(eyeTracker, &CommonObjectInfoTable::GetXrEyeTrackerFBInfo);

    XrResult replay_result = GetInstanceTable(in_eyeTracker)->DestroyEyeTrackerFB(in_eyeTracker);
    CheckResult("xrDestroyEyeTrackerFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyEyeTrackerFB>::UpdateState(this, call_info, returnValue, eyeTracker, replay_result);
    RemoveHandle(eyeTracker, &CommonObjectInfoTable::RemoveXrEyeTrackerFBInfo);
}

void OpenXrReplayConsumer::Process_xrGetEyeGazesFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            eyeTracker,
    StructPointerDecoder<Decoded_XrEyeGazesInfoFB>* gazeInfo,
    StructPointerDecoder<Decoded_XrEyeGazesFB>* eyeGazes)
{
    XrEyeTrackerFB in_eyeTracker = MapHandle<OpenXrEyeTrackerFBInfo>(eyeTracker, &CommonObjectInfoTable::GetXrEyeTrackerFBInfo);
    const XrEyeGazesInfoFB* in_gazeInfo = gazeInfo->GetPointer();
    MapStructHandles(gazeInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrEyeGazesFB* out_eyeGazes = eyeGazes->IsNull() ? nullptr : eyeGazes->AllocateOutputData(1, { XR_TYPE_EYE_GAZES_FB, nullptr });
    InitializeOutputStructNext(eyeGazes);

    XrResult replay_result = GetInstanceTable(in_eyeTracker)->GetEyeGazesFB(in_eyeTracker, in_gazeInfo, out_eyeGazes);
    CheckResult("xrGetEyeGazesFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetEyeGazesFB>::UpdateState(this, call_info, returnValue, eyeTracker, gazeInfo, eyeGazes, replay_result);
}

void OpenXrReplayConsumer::Process_xrPassthroughLayerSetKeyboardHandsIntensityFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            layer,
    StructPointerDecoder<Decoded_XrPassthroughKeyboardHandsIntensityFB>* intensity)
{
    XrPassthroughLayerFB in_layer = MapHandle<OpenXrPassthroughLayerFBInfo>(layer, &CommonObjectInfoTable::GetXrPassthroughLayerFBInfo);
    const XrPassthroughKeyboardHandsIntensityFB* in_intensity = intensity->GetPointer();

    XrResult replay_result = GetInstanceTable(in_layer)->PassthroughLayerSetKeyboardHandsIntensityFB(in_layer, in_intensity);
    CheckResult("xrPassthroughLayerSetKeyboardHandsIntensityFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrPassthroughLayerSetKeyboardHandsIntensityFB>::UpdateState(this, call_info, returnValue, layer, intensity, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetDeviceSampleRateFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo,
    StructPointerDecoder<Decoded_XrDevicePcmSampleRateStateFB>* deviceSampleRate)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrHapticActionInfo* in_hapticActionInfo = hapticActionInfo->GetPointer();
    MapStructHandles(hapticActionInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrDevicePcmSampleRateGetInfoFB* out_deviceSampleRate = deviceSampleRate->IsNull() ? nullptr : deviceSampleRate->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_session)->GetDeviceSampleRateFB(in_session, in_hapticActionInfo, out_deviceSampleRate);
    CheckResult("xrGetDeviceSampleRateFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetDeviceSampleRateFB>::UpdateState(this, call_info, returnValue, session, hapticActionInfo, deviceSampleRate, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetPassthroughPreferencesMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPassthroughPreferencesMETA>* preferences)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPassthroughPreferencesMETA* out_preferences = preferences->IsNull() ? nullptr : preferences->AllocateOutputData(1, { XR_TYPE_PASSTHROUGH_PREFERENCES_META, nullptr });
    InitializeOutputStructNext(preferences);

    XrResult replay_result = GetInstanceTable(in_session)->GetPassthroughPreferencesMETA(in_session, out_preferences);
    CheckResult("xrGetPassthroughPreferencesMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetPassthroughPreferencesMETA>::UpdateState(this, call_info, returnValue, session, preferences, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateVirtualKeyboardMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrVirtualKeyboardCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrVirtualKeyboardMETA>* keyboard)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrVirtualKeyboardCreateInfoMETA* in_createInfo = createInfo->GetPointer();
    if (!keyboard->IsNull()) { keyboard->SetHandleLength(1); }
    XrVirtualKeyboardMETA* out_keyboard = keyboard->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateVirtualKeyboardMETA(in_session, in_createInfo, out_keyboard);
    CheckResult("xrCreateVirtualKeyboardMETA", returnValue, replay_result, call_info);

    AddHandle<OpenXrVirtualKeyboardMETAInfo>(session, keyboard->GetPointer(), out_keyboard, &CommonObjectInfoTable::AddXrVirtualKeyboardMETAInfo);
    
    AssociateParent(*out_keyboard, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardMETA>::UpdateState(this, call_info, returnValue, session, createInfo, keyboard, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyVirtualKeyboardMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard)
{
    XrVirtualKeyboardMETA in_keyboard = MapHandle<OpenXrVirtualKeyboardMETAInfo>(keyboard, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);

    XrResult replay_result = GetInstanceTable(in_keyboard)->DestroyVirtualKeyboardMETA(in_keyboard);
    CheckResult("xrDestroyVirtualKeyboardMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyVirtualKeyboardMETA>::UpdateState(this, call_info, returnValue, keyboard, replay_result);
    RemoveHandle(keyboard, &CommonObjectInfoTable::RemoveXrVirtualKeyboardMETAInfo);
}

void OpenXrReplayConsumer::Process_xrCreateVirtualKeyboardSpaceMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardSpaceCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrSpace>*              keyboardSpace)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrVirtualKeyboardMETA in_keyboard = MapHandle<OpenXrVirtualKeyboardMETAInfo>(keyboard, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    const XrVirtualKeyboardSpaceCreateInfoMETA* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!keyboardSpace->IsNull()) { keyboardSpace->SetHandleLength(1); }
    XrSpace* out_keyboardSpace = keyboardSpace->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateVirtualKeyboardSpaceMETA(in_session, in_keyboard, in_createInfo, out_keyboardSpace);
    CheckResult("xrCreateVirtualKeyboardSpaceMETA", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(session, keyboardSpace->GetPointer(), out_keyboardSpace, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_keyboardSpace, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardSpaceMETA>::UpdateState(this, call_info, returnValue, session, keyboard, createInfo, keyboardSpace, replay_result);
}

void OpenXrReplayConsumer::Process_xrSuggestVirtualKeyboardLocationMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardLocationInfoMETA>* locationInfo)
{
    XrVirtualKeyboardMETA in_keyboard = MapHandle<OpenXrVirtualKeyboardMETAInfo>(keyboard, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    const XrVirtualKeyboardLocationInfoMETA* in_locationInfo = locationInfo->GetPointer();
    MapStructHandles(locationInfo->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_keyboard)->SuggestVirtualKeyboardLocationMETA(in_keyboard, in_locationInfo);
    CheckResult("xrSuggestVirtualKeyboardLocationMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSuggestVirtualKeyboardLocationMETA>::UpdateState(this, call_info, returnValue, keyboard, locationInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVirtualKeyboardScaleMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    PointerDecoder<float>*                      scale)
{
    XrVirtualKeyboardMETA in_keyboard = MapHandle<OpenXrVirtualKeyboardMETAInfo>(keyboard, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    float* out_scale = scale->IsNull() ? nullptr : scale->AllocateOutputData(1, static_cast<float>(0));

    XrResult replay_result = GetInstanceTable(in_keyboard)->GetVirtualKeyboardScaleMETA(in_keyboard, out_scale);
    CheckResult("xrGetVirtualKeyboardScaleMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVirtualKeyboardScaleMETA>::UpdateState(this, call_info, returnValue, keyboard, scale, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetVirtualKeyboardModelVisibilityMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA>* modelVisibility)
{
    XrVirtualKeyboardMETA in_keyboard = MapHandle<OpenXrVirtualKeyboardMETAInfo>(keyboard, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    const XrVirtualKeyboardModelVisibilitySetInfoMETA* in_modelVisibility = modelVisibility->GetPointer();

    XrResult replay_result = GetInstanceTable(in_keyboard)->SetVirtualKeyboardModelVisibilityMETA(in_keyboard, in_modelVisibility);
    CheckResult("xrSetVirtualKeyboardModelVisibilityMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetVirtualKeyboardModelVisibilityMETA>::UpdateState(this, call_info, returnValue, keyboard, modelVisibility, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVirtualKeyboardModelAnimationStatesMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardModelAnimationStatesMETA>* animationStates)
{
    XrVirtualKeyboardMETA in_keyboard = MapHandle<OpenXrVirtualKeyboardMETAInfo>(keyboard, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    XrVirtualKeyboardModelAnimationStatesMETA* out_animationStates = animationStates->IsNull() ? nullptr : animationStates->AllocateOutputData(1, { XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META, nullptr });
    InitializeOutputStructNext(animationStates);

    XrResult replay_result = GetInstanceTable(in_keyboard)->GetVirtualKeyboardModelAnimationStatesMETA(in_keyboard, out_animationStates);
    CheckResult("xrGetVirtualKeyboardModelAnimationStatesMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA>::UpdateState(this, call_info, returnValue, keyboard, animationStates, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVirtualKeyboardDirtyTexturesMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    uint32_t                                    textureIdCapacityInput,
    PointerDecoder<uint32_t>*                   textureIdCountOutput,
    PointerDecoder<uint64_t>*                   textureIds)
{
    XrVirtualKeyboardMETA in_keyboard = MapHandle<OpenXrVirtualKeyboardMETAInfo>(keyboard, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    uint32_t* out_textureIdCountOutput = textureIdCountOutput->IsNull() ? nullptr : textureIdCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    uint64_t* out_textureIds = textureIds->IsNull() ? nullptr : textureIds->AllocateOutputData(textureIdCapacityInput);

    XrResult replay_result = XR_SUCCESS;
    if (!textureIds->IsNull() && returnValue == XR_SUCCESS)
    {
        // Get actual count from replay
        uint32_t replay_count = 0;
        replay_result = GetInstanceTable(in_keyboard)->GetVirtualKeyboardDirtyTexturesMETA(in_keyboard, 0, &replay_count, nullptr);
        if (replay_result != XR_SUCCESS || replay_count < textureIdCapacityInput)
        {
            GFXRECON_LOG_FATAL("xrGetVirtualKeyboardDirtyTexturesMETA replay size %d is smaller than capture size %d",
                replay_count,
                textureIdCapacityInput);
            return;
        }

        // Allocate a temporary array to get all the replay values to compare against the capture values.
        std::vector<uint64_t> temp_textureIds(replay_count);
        replay_result = GetInstanceTable(in_keyboard)->GetVirtualKeyboardDirtyTexturesMETA(in_keyboard, temp_textureIds.size(), out_textureIdCountOutput, temp_textureIds.data());
        if (replay_result == XR_SUCCESS)
        {
            // Now loop through and make sure we find each item in the original list in the replay
            uint64_t* original_textureIds = textureIds->GetPointer();
            for (uint32_t iii = 0; iii < textureIdCapacityInput; ++iii)
            {
                bool found = false;
                for (uint32_t jjj = 0; jjj < replay_count; ++jjj)
                {
                    if (temp_textureIds[jjj] == original_textureIds[iii])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    GFXRECON_LOG_ERROR("xrGetVirtualKeyboardDirtyTexturesMETA failed to find a value of %d during replay",
                        original_textureIds[iii]);
                }
             }
        }
    }
    else
    {
        replay_result = GetInstanceTable(in_keyboard)->GetVirtualKeyboardDirtyTexturesMETA(in_keyboard, textureIdCapacityInput, out_textureIdCountOutput, out_textureIds);
    }
    CheckResult("xrGetVirtualKeyboardDirtyTexturesMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA>::UpdateState(this, call_info, returnValue, keyboard, textureIdCapacityInput, textureIdCountOutput, textureIds, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetVirtualKeyboardTextureDataMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    uint64_t                                    textureId,
    StructPointerDecoder<Decoded_XrVirtualKeyboardTextureDataMETA>* textureData)
{
    XrVirtualKeyboardMETA in_keyboard = MapHandle<OpenXrVirtualKeyboardMETAInfo>(keyboard, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    XrVirtualKeyboardTextureDataMETA* out_textureData = textureData->IsNull() ? nullptr : textureData->AllocateOutputData(1, { XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META, nullptr });
    InitializeOutputStructNext(textureData);

    XrResult replay_result = GetInstanceTable(in_keyboard)->GetVirtualKeyboardTextureDataMETA(in_keyboard, textureId, out_textureData);
    CheckResult("xrGetVirtualKeyboardTextureDataMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetVirtualKeyboardTextureDataMETA>::UpdateState(this, call_info, returnValue, keyboard, textureId, textureData, replay_result);
}

void OpenXrReplayConsumer::Process_xrSendVirtualKeyboardInputMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardInputInfoMETA>* info,
    StructPointerDecoder<Decoded_XrPosef>*      interactorRootPose)
{
    XrVirtualKeyboardMETA in_keyboard = MapHandle<OpenXrVirtualKeyboardMETAInfo>(keyboard, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    const XrVirtualKeyboardInputInfoMETA* in_info = info->GetPointer();
    MapStructHandles(info->GetMetaStructPointer(), GetObjectInfoTable());
    XrPosef* out_interactorRootPose = interactorRootPose->IsNull() ? nullptr : interactorRootPose->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_keyboard)->SendVirtualKeyboardInputMETA(in_keyboard, in_info, out_interactorRootPose);
    CheckResult("xrSendVirtualKeyboardInputMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSendVirtualKeyboardInputMETA>::UpdateState(this, call_info, returnValue, keyboard, info, interactorRootPose, replay_result);
}

void OpenXrReplayConsumer::Process_xrChangeVirtualKeyboardTextContextMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            keyboard,
    StructPointerDecoder<Decoded_XrVirtualKeyboardTextContextChangeInfoMETA>* changeInfo)
{
    XrVirtualKeyboardMETA in_keyboard = MapHandle<OpenXrVirtualKeyboardMETAInfo>(keyboard, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    const XrVirtualKeyboardTextContextChangeInfoMETA* in_changeInfo = changeInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_keyboard)->ChangeVirtualKeyboardTextContextMETA(in_keyboard, in_changeInfo);
    CheckResult("xrChangeVirtualKeyboardTextContextMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrChangeVirtualKeyboardTextContextMETA>::UpdateState(this, call_info, returnValue, keyboard, changeInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumerateExternalCamerasOCULUS(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    uint32_t                                    cameraCapacityInput,
    PointerDecoder<uint32_t>*                   cameraCountOutput,
    StructPointerDecoder<Decoded_XrExternalCameraOCULUS>* cameras)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    uint32_t* out_cameraCountOutput = cameraCountOutput->IsNull() ? nullptr : cameraCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrExternalCameraOCULUS* out_cameras = cameras->IsNull() ? nullptr : cameras->AllocateOutputData(cameraCapacityInput, XrExternalCameraOCULUS{ XR_TYPE_EXTERNAL_CAMERA_OCULUS, nullptr });

    XrResult replay_result = GetInstanceTable(in_session)->EnumerateExternalCamerasOCULUS(in_session, cameraCapacityInput, out_cameraCountOutput, out_cameras);
    CheckResult("xrEnumerateExternalCamerasOCULUS", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateExternalCamerasOCULUS>::UpdateState(this, call_info, returnValue, session, cameraCapacityInput, cameraCountOutput, cameras, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnumeratePerformanceMetricsCounterPathsMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    uint32_t                                    counterPathCapacityInput,
    PointerDecoder<uint32_t>*                   counterPathCountOutput,
    HandlePointerDecoder<XrPath>*               counterPaths)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    uint32_t* out_counterPathCountOutput = counterPathCountOutput->IsNull() ? nullptr : counterPathCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    if (!counterPaths->IsNull()) { counterPaths->SetHandleLength(counterPathCapacityInput); }
    XrPath* out_counterPaths = counterPaths->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_instance)->EnumeratePerformanceMetricsCounterPathsMETA(in_instance, counterPathCapacityInput, out_counterPathCountOutput, out_counterPaths);
    CheckResult("xrEnumeratePerformanceMetricsCounterPathsMETA", returnValue, replay_result, call_info);

    AddHandles<OpenXrPathInfo>(instance, counterPaths->GetPointer(), counterPaths->GetLength(), out_counterPaths, counterPathCapacityInput, &CommonObjectInfoTable::AddXrPathInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA>::UpdateState(this, call_info, returnValue, instance, counterPathCapacityInput, counterPathCountOutput, counterPaths, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetPerformanceMetricsStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA>* state)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrPerformanceMetricsStateMETA* in_state = state->GetPointer();

    XrResult replay_result = GetInstanceTable(in_session)->SetPerformanceMetricsStateMETA(in_session, in_state);
    CheckResult("xrSetPerformanceMetricsStateMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetPerformanceMetricsStateMETA>::UpdateState(this, call_info, returnValue, session, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetPerformanceMetricsStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA>* state)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPerformanceMetricsStateMETA* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1, { XR_TYPE_PERFORMANCE_METRICS_STATE_META, nullptr });
    InitializeOutputStructNext(state);

    XrResult replay_result = GetInstanceTable(in_session)->GetPerformanceMetricsStateMETA(in_session, out_state);
    CheckResult("xrGetPerformanceMetricsStateMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetPerformanceMetricsStateMETA>::UpdateState(this, call_info, returnValue, session, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrQueryPerformanceMetricsCounterMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    format::HandleId                            counterPath,
    StructPointerDecoder<Decoded_XrPerformanceMetricsCounterMETA>* counter)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    XrPath in_counterPath = MapHandle<OpenXrPathInfo>(counterPath, &CommonObjectInfoTable::GetXrPathInfo);
    XrPerformanceMetricsCounterMETA* out_counter = counter->IsNull() ? nullptr : counter->AllocateOutputData(1, { XR_TYPE_PERFORMANCE_METRICS_COUNTER_META, nullptr });
    InitializeOutputStructNext(counter);

    XrResult replay_result = GetInstanceTable(in_session)->QueryPerformanceMetricsCounterMETA(in_session, in_counterPath, out_counter);
    CheckResult("xrQueryPerformanceMetricsCounterMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrQueryPerformanceMetricsCounterMETA>::UpdateState(this, call_info, returnValue, session, counterPath, counter, replay_result);
}

void OpenXrReplayConsumer::Process_xrSaveSpaceListFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceListSaveInfoFB>* info,
    HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpaceListSaveInfoFB* in_info = info->GetPointer();
    MapStructHandles(info->GetMetaStructPointer(), GetObjectInfoTable());
    if (!requestId->IsNull()) { requestId->SetHandleLength(1); }
    XrAsyncRequestIdFB* out_requestId = requestId->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->SaveSpaceListFB(in_session, in_info, out_requestId);
    CheckResult("xrSaveSpaceListFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrAsyncRequestIdFBInfo>(session, requestId->GetPointer(), out_requestId, &CommonObjectInfoTable::AddXrAsyncRequestIdFBInfo);
    CustomProcess<format::ApiCallId::ApiCall_xrSaveSpaceListFB>::UpdateState(this, call_info, returnValue, session, info, requestId, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSpaceUserFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpaceUserCreateInfoFB>* info,
    HandlePointerDecoder<XrSpaceUserFB>*        user)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpaceUserCreateInfoFB* in_info = info->GetPointer();
    if (!user->IsNull()) { user->SetHandleLength(1); }
    XrSpaceUserFB* out_user = user->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSpaceUserFB(in_session, in_info, out_user);
    CheckResult("xrCreateSpaceUserFB", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceUserFBInfo>(session, user->GetPointer(), out_user, &CommonObjectInfoTable::AddXrSpaceUserFBInfo);
    
    AssociateParent(*out_user, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSpaceUserFB>::UpdateState(this, call_info, returnValue, session, info, user, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpaceUserIdFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            user,
    PointerDecoder<XrSpaceUserIdFB>*            userId)
{
    XrSpaceUserFB in_user = MapHandle<OpenXrSpaceUserFBInfo>(user, &CommonObjectInfoTable::GetXrSpaceUserFBInfo);
    XrSpaceUserIdFB* out_userId = userId->IsNull() ? nullptr : userId->AllocateOutputData(1, static_cast<XrSpaceUserIdFB>(0));

    XrResult replay_result = GetInstanceTable(in_user)->GetSpaceUserIdFB(in_user, out_userId);
    CheckResult("xrGetSpaceUserIdFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpaceUserIdFB>::UpdateState(this, call_info, returnValue, user, userId, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroySpaceUserFB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            user)
{
    XrSpaceUserFB in_user = MapHandle<OpenXrSpaceUserFBInfo>(user, &CommonObjectInfoTable::GetXrSpaceUserFBInfo);

    XrResult replay_result = GetInstanceTable(in_user)->DestroySpaceUserFB(in_user);
    CheckResult("xrDestroySpaceUserFB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroySpaceUserFB>::UpdateState(this, call_info, returnValue, user, replay_result);
    RemoveHandle(user, &CommonObjectInfoTable::RemoveXrSpaceUserFBInfo);
}

void OpenXrReplayConsumer::Process_xrGetRecommendedLayerResolutionMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrRecommendedLayerResolutionGetInfoMETA>* info,
    StructPointerDecoder<Decoded_XrRecommendedLayerResolutionMETA>* resolution)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrRecommendedLayerResolutionGetInfoMETA* in_info = info->GetPointer();
    MapStructHandles(info->GetMetaStructPointer(), GetObjectInfoTable());
    XrRecommendedLayerResolutionMETA* out_resolution = resolution->IsNull() ? nullptr : resolution->AllocateOutputData(1, { XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META, nullptr });
    InitializeOutputStructNext(resolution);

    XrResult replay_result = GetInstanceTable(in_session)->GetRecommendedLayerResolutionMETA(in_session, in_info, out_resolution);
    CheckResult("xrGetRecommendedLayerResolutionMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetRecommendedLayerResolutionMETA>::UpdateState(this, call_info, returnValue, session, info, resolution, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreatePassthroughColorLutMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough,
    StructPointerDecoder<Decoded_XrPassthroughColorLutCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrPassthroughColorLutMETA>* colorLut)
{
    XrPassthroughFB in_passthrough = MapHandle<OpenXrPassthroughFBInfo>(passthrough, &CommonObjectInfoTable::GetXrPassthroughFBInfo);
    const XrPassthroughColorLutCreateInfoMETA* in_createInfo = createInfo->GetPointer();
    if (!colorLut->IsNull()) { colorLut->SetHandleLength(1); }
    XrPassthroughColorLutMETA* out_colorLut = colorLut->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_passthrough)->CreatePassthroughColorLutMETA(in_passthrough, in_createInfo, out_colorLut);
    CheckResult("xrCreatePassthroughColorLutMETA", returnValue, replay_result, call_info);

    AddHandle<OpenXrPassthroughColorLutMETAInfo>(passthrough, colorLut->GetPointer(), out_colorLut, &CommonObjectInfoTable::AddXrPassthroughColorLutMETAInfo);
    
    AssociateParent(*out_colorLut, in_passthrough);
    CustomProcess<format::ApiCallId::ApiCall_xrCreatePassthroughColorLutMETA>::UpdateState(this, call_info, returnValue, passthrough, createInfo, colorLut, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyPassthroughColorLutMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            colorLut)
{
    XrPassthroughColorLutMETA in_colorLut = MapHandle<OpenXrPassthroughColorLutMETAInfo>(colorLut, &CommonObjectInfoTable::GetXrPassthroughColorLutMETAInfo);

    XrResult replay_result = GetInstanceTable(in_colorLut)->DestroyPassthroughColorLutMETA(in_colorLut);
    CheckResult("xrDestroyPassthroughColorLutMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyPassthroughColorLutMETA>::UpdateState(this, call_info, returnValue, colorLut, replay_result);
    RemoveHandle(colorLut, &CommonObjectInfoTable::RemoveXrPassthroughColorLutMETAInfo);
}

void OpenXrReplayConsumer::Process_xrUpdatePassthroughColorLutMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            colorLut,
    StructPointerDecoder<Decoded_XrPassthroughColorLutUpdateInfoMETA>* updateInfo)
{
    XrPassthroughColorLutMETA in_colorLut = MapHandle<OpenXrPassthroughColorLutMETAInfo>(colorLut, &CommonObjectInfoTable::GetXrPassthroughColorLutMETAInfo);
    const XrPassthroughColorLutUpdateInfoMETA* in_updateInfo = updateInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_colorLut)->UpdatePassthroughColorLutMETA(in_colorLut, in_updateInfo);
    CheckResult("xrUpdatePassthroughColorLutMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrUpdatePassthroughColorLutMETA>::UpdateState(this, call_info, returnValue, colorLut, updateInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpaceTriangleMeshMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            space,
    StructPointerDecoder<Decoded_XrSpaceTriangleMeshGetInfoMETA>* getInfo,
    StructPointerDecoder<Decoded_XrSpaceTriangleMeshMETA>* triangleMeshOutput)
{
    XrSpace in_space = MapHandle<OpenXrSpaceInfo>(space, &CommonObjectInfoTable::GetXrSpaceInfo);
    const XrSpaceTriangleMeshGetInfoMETA* in_getInfo = getInfo->GetPointer();
    XrSpaceTriangleMeshMETA* out_triangleMeshOutput = triangleMeshOutput->IsNull() ? nullptr : triangleMeshOutput->AllocateOutputData(1, { XR_TYPE_SPACE_TRIANGLE_MESH_META, nullptr });
    InitializeOutputStructNext(triangleMeshOutput);

    XrResult replay_result = GetInstanceTable(in_space)->GetSpaceTriangleMeshMETA(in_space, in_getInfo, out_triangleMeshOutput);
    CheckResult("xrGetSpaceTriangleMeshMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpaceTriangleMeshMETA>::UpdateState(this, call_info, returnValue, space, getInfo, triangleMeshOutput, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateFaceTracker2FB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFaceTrackerCreateInfo2FB>* createInfo,
    HandlePointerDecoder<XrFaceTracker2FB>*     faceTracker)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrFaceTrackerCreateInfo2FB* in_createInfo = createInfo->GetPointer();
    if (!faceTracker->IsNull()) { faceTracker->SetHandleLength(1); }
    XrFaceTracker2FB* out_faceTracker = faceTracker->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateFaceTracker2FB(in_session, in_createInfo, out_faceTracker);
    CheckResult("xrCreateFaceTracker2FB", returnValue, replay_result, call_info);

    AddHandle<OpenXrFaceTracker2FBInfo>(session, faceTracker->GetPointer(), out_faceTracker, &CommonObjectInfoTable::AddXrFaceTracker2FBInfo);
    
    AssociateParent(*out_faceTracker, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateFaceTracker2FB>::UpdateState(this, call_info, returnValue, session, createInfo, faceTracker, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyFaceTracker2FB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            faceTracker)
{
    XrFaceTracker2FB in_faceTracker = MapHandle<OpenXrFaceTracker2FBInfo>(faceTracker, &CommonObjectInfoTable::GetXrFaceTracker2FBInfo);

    XrResult replay_result = GetInstanceTable(in_faceTracker)->DestroyFaceTracker2FB(in_faceTracker);
    CheckResult("xrDestroyFaceTracker2FB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyFaceTracker2FB>::UpdateState(this, call_info, returnValue, faceTracker, replay_result);
    RemoveHandle(faceTracker, &CommonObjectInfoTable::RemoveXrFaceTracker2FBInfo);
}

void OpenXrReplayConsumer::Process_xrGetFaceExpressionWeights2FB(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            faceTracker,
    StructPointerDecoder<Decoded_XrFaceExpressionInfo2FB>* expressionInfo,
    StructPointerDecoder<Decoded_XrFaceExpressionWeights2FB>* expressionWeights)
{
    XrFaceTracker2FB in_faceTracker = MapHandle<OpenXrFaceTracker2FBInfo>(faceTracker, &CommonObjectInfoTable::GetXrFaceTracker2FBInfo);
    const XrFaceExpressionInfo2FB* in_expressionInfo = expressionInfo->GetPointer();
    XrFaceExpressionWeights2FB* out_expressionWeights = expressionWeights->IsNull() ? nullptr : expressionWeights->AllocateOutputData(1, { XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB, nullptr });
    InitializeOutputStructNext(expressionWeights);

    XrResult replay_result = GetInstanceTable(in_faceTracker)->GetFaceExpressionWeights2FB(in_faceTracker, in_expressionInfo, out_expressionWeights);
    CheckResult("xrGetFaceExpressionWeights2FB", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetFaceExpressionWeights2FB>::UpdateState(this, call_info, returnValue, faceTracker, expressionInfo, expressionWeights, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateEnvironmentDepthProviderMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrEnvironmentDepthProviderCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrEnvironmentDepthProviderMETA>* environmentDepthProvider)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrEnvironmentDepthProviderCreateInfoMETA* in_createInfo = createInfo->GetPointer();
    if (!environmentDepthProvider->IsNull()) { environmentDepthProvider->SetHandleLength(1); }
    XrEnvironmentDepthProviderMETA* out_environmentDepthProvider = environmentDepthProvider->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateEnvironmentDepthProviderMETA(in_session, in_createInfo, out_environmentDepthProvider);
    CheckResult("xrCreateEnvironmentDepthProviderMETA", returnValue, replay_result, call_info);

    AddHandle<OpenXrEnvironmentDepthProviderMETAInfo>(session, environmentDepthProvider->GetPointer(), out_environmentDepthProvider, &CommonObjectInfoTable::AddXrEnvironmentDepthProviderMETAInfo);
    
    AssociateParent(*out_environmentDepthProvider, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateEnvironmentDepthProviderMETA>::UpdateState(this, call_info, returnValue, session, createInfo, environmentDepthProvider, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyEnvironmentDepthProviderMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider)
{
    XrEnvironmentDepthProviderMETA in_environmentDepthProvider = MapHandle<OpenXrEnvironmentDepthProviderMETAInfo>(environmentDepthProvider, &CommonObjectInfoTable::GetXrEnvironmentDepthProviderMETAInfo);

    XrResult replay_result = GetInstanceTable(in_environmentDepthProvider)->DestroyEnvironmentDepthProviderMETA(in_environmentDepthProvider);
    CheckResult("xrDestroyEnvironmentDepthProviderMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthProviderMETA>::UpdateState(this, call_info, returnValue, environmentDepthProvider, replay_result);
    RemoveHandle(environmentDepthProvider, &CommonObjectInfoTable::RemoveXrEnvironmentDepthProviderMETAInfo);
}

void OpenXrReplayConsumer::Process_xrStartEnvironmentDepthProviderMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider)
{
    XrEnvironmentDepthProviderMETA in_environmentDepthProvider = MapHandle<OpenXrEnvironmentDepthProviderMETAInfo>(environmentDepthProvider, &CommonObjectInfoTable::GetXrEnvironmentDepthProviderMETAInfo);

    XrResult replay_result = GetInstanceTable(in_environmentDepthProvider)->StartEnvironmentDepthProviderMETA(in_environmentDepthProvider);
    CheckResult("xrStartEnvironmentDepthProviderMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrStartEnvironmentDepthProviderMETA>::UpdateState(this, call_info, returnValue, environmentDepthProvider, replay_result);
}

void OpenXrReplayConsumer::Process_xrStopEnvironmentDepthProviderMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider)
{
    XrEnvironmentDepthProviderMETA in_environmentDepthProvider = MapHandle<OpenXrEnvironmentDepthProviderMETAInfo>(environmentDepthProvider, &CommonObjectInfoTable::GetXrEnvironmentDepthProviderMETAInfo);

    XrResult replay_result = GetInstanceTable(in_environmentDepthProvider)->StopEnvironmentDepthProviderMETA(in_environmentDepthProvider);
    CheckResult("xrStopEnvironmentDepthProviderMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrStopEnvironmentDepthProviderMETA>::UpdateState(this, call_info, returnValue, environmentDepthProvider, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateEnvironmentDepthSwapchainMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider,
    StructPointerDecoder<Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA>* createInfo,
    HandlePointerDecoder<XrEnvironmentDepthSwapchainMETA>* swapchain)
{
    XrEnvironmentDepthProviderMETA in_environmentDepthProvider = MapHandle<OpenXrEnvironmentDepthProviderMETAInfo>(environmentDepthProvider, &CommonObjectInfoTable::GetXrEnvironmentDepthProviderMETAInfo);
    const XrEnvironmentDepthSwapchainCreateInfoMETA* in_createInfo = createInfo->GetPointer();
    if (!swapchain->IsNull()) { swapchain->SetHandleLength(1); }
    XrEnvironmentDepthSwapchainMETA* out_swapchain = swapchain->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_environmentDepthProvider)->CreateEnvironmentDepthSwapchainMETA(in_environmentDepthProvider, in_createInfo, out_swapchain);
    CheckResult("xrCreateEnvironmentDepthSwapchainMETA", returnValue, replay_result, call_info);

    AddHandle<OpenXrEnvironmentDepthSwapchainMETAInfo>(environmentDepthProvider, swapchain->GetPointer(), out_swapchain, &CommonObjectInfoTable::AddXrEnvironmentDepthSwapchainMETAInfo);
    
    AssociateParent(*out_swapchain, in_environmentDepthProvider);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateEnvironmentDepthSwapchainMETA>::UpdateState(this, call_info, returnValue, environmentDepthProvider, createInfo, swapchain, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyEnvironmentDepthSwapchainMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain)
{
    XrEnvironmentDepthSwapchainMETA in_swapchain = MapHandle<OpenXrEnvironmentDepthSwapchainMETAInfo>(swapchain, &CommonObjectInfoTable::GetXrEnvironmentDepthSwapchainMETAInfo);

    XrResult replay_result = GetInstanceTable(in_swapchain)->DestroyEnvironmentDepthSwapchainMETA(in_swapchain);
    CheckResult("xrDestroyEnvironmentDepthSwapchainMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthSwapchainMETA>::UpdateState(this, call_info, returnValue, swapchain, replay_result);
    RemoveHandle(swapchain, &CommonObjectInfoTable::RemoveXrEnvironmentDepthSwapchainMETAInfo);
}

void OpenXrReplayConsumer::Process_xrEnumerateEnvironmentDepthSwapchainImagesMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    uint32_t                                    imageCapacityInput,
    PointerDecoder<uint32_t>*                   imageCountOutput,
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images)
{
    XrEnvironmentDepthSwapchainMETA in_swapchain = MapHandle<OpenXrEnvironmentDepthSwapchainMETAInfo>(swapchain, &CommonObjectInfoTable::GetXrEnvironmentDepthSwapchainMETAInfo);
    uint32_t* out_imageCountOutput = imageCountOutput->IsNull() ? nullptr : imageCountOutput->AllocateOutputData(1, static_cast<uint32_t>(0));
    XrSwapchainImageBaseHeader* out_images = images->IsNull() ? nullptr : images->AllocateOutputData(imageCapacityInput);

    XrResult replay_result = GetInstanceTable(in_swapchain)->EnumerateEnvironmentDepthSwapchainImagesMETA(in_swapchain, imageCapacityInput, out_imageCountOutput, out_images);
    CheckResult("xrEnumerateEnvironmentDepthSwapchainImagesMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnumerateEnvironmentDepthSwapchainImagesMETA>::UpdateState(this, call_info, returnValue, swapchain, imageCapacityInput, imageCountOutput, images, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetEnvironmentDepthSwapchainStateMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_XrEnvironmentDepthSwapchainStateMETA>* state)
{
    XrEnvironmentDepthSwapchainMETA in_swapchain = MapHandle<OpenXrEnvironmentDepthSwapchainMETAInfo>(swapchain, &CommonObjectInfoTable::GetXrEnvironmentDepthSwapchainMETAInfo);
    XrEnvironmentDepthSwapchainStateMETA* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1, { XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_STATE_META, nullptr });
    InitializeOutputStructNext(state);

    XrResult replay_result = GetInstanceTable(in_swapchain)->GetEnvironmentDepthSwapchainStateMETA(in_swapchain, out_state);
    CheckResult("xrGetEnvironmentDepthSwapchainStateMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetEnvironmentDepthSwapchainStateMETA>::UpdateState(this, call_info, returnValue, swapchain, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrAcquireEnvironmentDepthImageMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider,
    StructPointerDecoder<Decoded_XrEnvironmentDepthImageAcquireInfoMETA>* acquireInfo,
    StructPointerDecoder<Decoded_XrEnvironmentDepthImageMETA>* environmentDepthImage)
{
    XrEnvironmentDepthProviderMETA in_environmentDepthProvider = MapHandle<OpenXrEnvironmentDepthProviderMETAInfo>(environmentDepthProvider, &CommonObjectInfoTable::GetXrEnvironmentDepthProviderMETAInfo);
    const XrEnvironmentDepthImageAcquireInfoMETA* in_acquireInfo = acquireInfo->GetPointer();
    MapStructHandles(acquireInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrEnvironmentDepthImageMETA* out_environmentDepthImage = environmentDepthImage->IsNull() ? nullptr : environmentDepthImage->AllocateOutputData(1, { XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_META, nullptr });
    InitializeOutputStructNext(environmentDepthImage);

    XrResult replay_result = GetInstanceTable(in_environmentDepthProvider)->AcquireEnvironmentDepthImageMETA(in_environmentDepthProvider, in_acquireInfo, out_environmentDepthImage);
    CheckResult("xrAcquireEnvironmentDepthImageMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrAcquireEnvironmentDepthImageMETA>::UpdateState(this, call_info, returnValue, environmentDepthProvider, acquireInfo, environmentDepthImage, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetEnvironmentDepthHandRemovalMETA(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            environmentDepthProvider,
    StructPointerDecoder<Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA>* setInfo)
{
    XrEnvironmentDepthProviderMETA in_environmentDepthProvider = MapHandle<OpenXrEnvironmentDepthProviderMETAInfo>(environmentDepthProvider, &CommonObjectInfoTable::GetXrEnvironmentDepthProviderMETAInfo);
    const XrEnvironmentDepthHandRemovalSetInfoMETA* in_setInfo = setInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_environmentDepthProvider)->SetEnvironmentDepthHandRemovalMETA(in_environmentDepthProvider, in_setInfo);
    CheckResult("xrSetEnvironmentDepthHandRemovalMETA", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetEnvironmentDepthHandRemovalMETA>::UpdateState(this, call_info, returnValue, environmentDepthProvider, setInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrSetTrackingOptimizationSettingsHintQCOM(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    XrTrackingOptimizationSettingsDomainQCOM    domain,
    XrTrackingOptimizationSettingsHintQCOM      hint)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);

    XrResult replay_result = GetInstanceTable(in_session)->SetTrackingOptimizationSettingsHintQCOM(in_session, domain, hint);
    CheckResult("xrSetTrackingOptimizationSettingsHintQCOM", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrSetTrackingOptimizationSettingsHintQCOM>::UpdateState(this, call_info, returnValue, session, domain, hint, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreatePassthroughHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPassthroughCreateInfoHTC>* createInfo,
    HandlePointerDecoder<XrPassthroughHTC>*     passthrough)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrPassthroughCreateInfoHTC* in_createInfo = createInfo->GetPointer();
    if (!passthrough->IsNull()) { passthrough->SetHandleLength(1); }
    XrPassthroughHTC* out_passthrough = passthrough->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreatePassthroughHTC(in_session, in_createInfo, out_passthrough);
    CheckResult("xrCreatePassthroughHTC", returnValue, replay_result, call_info);

    AddHandle<OpenXrPassthroughHTCInfo>(session, passthrough->GetPointer(), out_passthrough, &CommonObjectInfoTable::AddXrPassthroughHTCInfo);
    
    AssociateParent(*out_passthrough, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreatePassthroughHTC>::UpdateState(this, call_info, returnValue, session, createInfo, passthrough, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyPassthroughHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            passthrough)
{
    XrPassthroughHTC in_passthrough = MapHandle<OpenXrPassthroughHTCInfo>(passthrough, &CommonObjectInfoTable::GetXrPassthroughHTCInfo);

    XrResult replay_result = GetInstanceTable(in_passthrough)->DestroyPassthroughHTC(in_passthrough);
    CheckResult("xrDestroyPassthroughHTC", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyPassthroughHTC>::UpdateState(this, call_info, returnValue, passthrough, replay_result);
    RemoveHandle(passthrough, &CommonObjectInfoTable::RemoveXrPassthroughHTCInfo);
}

void OpenXrReplayConsumer::Process_xrApplyFoveationHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrFoveationApplyInfoHTC>* applyInfo)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrFoveationApplyInfoHTC* in_applyInfo = applyInfo->GetPointer();
    MapStructHandles(applyInfo->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_session)->ApplyFoveationHTC(in_session, in_applyInfo);
    CheckResult("xrApplyFoveationHTC", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrApplyFoveationHTC>::UpdateState(this, call_info, returnValue, session, applyInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreateSpatialAnchorHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoHTC>* createInfo,
    HandlePointerDecoder<XrSpace>*              anchor)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrSpatialAnchorCreateInfoHTC* in_createInfo = createInfo->GetPointer();
    MapStructHandles(createInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!anchor->IsNull()) { anchor->SetHandleLength(1); }
    XrSpace* out_anchor = anchor->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreateSpatialAnchorHTC(in_session, in_createInfo, out_anchor);
    CheckResult("xrCreateSpatialAnchorHTC", returnValue, replay_result, call_info);

    AddHandle<OpenXrSpaceInfo>(session, anchor->GetPointer(), out_anchor, &CommonObjectInfoTable::AddXrSpaceInfo);
    
    AssociateParent(*out_anchor, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreateSpatialAnchorHTC>::UpdateState(this, call_info, returnValue, session, createInfo, anchor, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetSpatialAnchorNameHTC(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            anchor,
    StructPointerDecoder<Decoded_XrSpatialAnchorNameHTC>* name)
{
    XrSpace in_anchor = MapHandle<OpenXrSpaceInfo>(anchor, &CommonObjectInfoTable::GetXrSpaceInfo);
    XrSpatialAnchorNameHTC* out_name = name->IsNull() ? nullptr : name->AllocateOutputData(1);

    XrResult replay_result = GetInstanceTable(in_anchor)->GetSpatialAnchorNameHTC(in_anchor, out_name);
    CheckResult("xrGetSpatialAnchorNameHTC", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetSpatialAnchorNameHTC>::UpdateState(this, call_info, returnValue, anchor, name, replay_result);
}

void OpenXrReplayConsumer::Process_xrApplyForceFeedbackCurlMNDX(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            handTracker,
    StructPointerDecoder<Decoded_XrForceFeedbackCurlApplyLocationsMNDX>* locations)
{
    XrHandTrackerEXT in_handTracker = MapHandle<OpenXrHandTrackerEXTInfo>(handTracker, &CommonObjectInfoTable::GetXrHandTrackerEXTInfo);
    const XrForceFeedbackCurlApplyLocationsMNDX* in_locations = locations->GetPointer();

    XrResult replay_result = GetInstanceTable(in_handTracker)->ApplyForceFeedbackCurlMNDX(in_handTracker, in_locations);
    CheckResult("xrApplyForceFeedbackCurlMNDX", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrApplyForceFeedbackCurlMNDX>::UpdateState(this, call_info, returnValue, handTracker, locations, replay_result);
}

void OpenXrReplayConsumer::Process_xrCreatePlaneDetectorEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_XrPlaneDetectorCreateInfoEXT>* createInfo,
    HandlePointerDecoder<XrPlaneDetectorEXT>*   planeDetector)
{
    XrSession in_session = MapHandle<OpenXrSessionInfo>(session, &CommonObjectInfoTable::GetXrSessionInfo);
    const XrPlaneDetectorCreateInfoEXT* in_createInfo = createInfo->GetPointer();
    if (!planeDetector->IsNull()) { planeDetector->SetHandleLength(1); }
    XrPlaneDetectorEXT* out_planeDetector = planeDetector->GetHandlePointer();

    XrResult replay_result = GetInstanceTable(in_session)->CreatePlaneDetectorEXT(in_session, in_createInfo, out_planeDetector);
    CheckResult("xrCreatePlaneDetectorEXT", returnValue, replay_result, call_info);

    AddHandle<OpenXrPlaneDetectorEXTInfo>(session, planeDetector->GetPointer(), out_planeDetector, &CommonObjectInfoTable::AddXrPlaneDetectorEXTInfo);
    
    AssociateParent(*out_planeDetector, in_session);
    CustomProcess<format::ApiCallId::ApiCall_xrCreatePlaneDetectorEXT>::UpdateState(this, call_info, returnValue, session, createInfo, planeDetector, replay_result);
}

void OpenXrReplayConsumer::Process_xrDestroyPlaneDetectorEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector)
{
    XrPlaneDetectorEXT in_planeDetector = MapHandle<OpenXrPlaneDetectorEXTInfo>(planeDetector, &CommonObjectInfoTable::GetXrPlaneDetectorEXTInfo);

    XrResult replay_result = GetInstanceTable(in_planeDetector)->DestroyPlaneDetectorEXT(in_planeDetector);
    CheckResult("xrDestroyPlaneDetectorEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrDestroyPlaneDetectorEXT>::UpdateState(this, call_info, returnValue, planeDetector, replay_result);
    RemoveHandle(planeDetector, &CommonObjectInfoTable::RemoveXrPlaneDetectorEXTInfo);
}

void OpenXrReplayConsumer::Process_xrBeginPlaneDetectionEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector,
    StructPointerDecoder<Decoded_XrPlaneDetectorBeginInfoEXT>* beginInfo)
{
    XrPlaneDetectorEXT in_planeDetector = MapHandle<OpenXrPlaneDetectorEXTInfo>(planeDetector, &CommonObjectInfoTable::GetXrPlaneDetectorEXTInfo);
    const XrPlaneDetectorBeginInfoEXT* in_beginInfo = beginInfo->GetPointer();
    MapStructHandles(beginInfo->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_planeDetector)->BeginPlaneDetectionEXT(in_planeDetector, in_beginInfo);
    CheckResult("xrBeginPlaneDetectionEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrBeginPlaneDetectionEXT>::UpdateState(this, call_info, returnValue, planeDetector, beginInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetPlaneDetectionStateEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector,
    PointerDecoder<XrPlaneDetectionStateEXT>*   state)
{
    XrPlaneDetectorEXT in_planeDetector = MapHandle<OpenXrPlaneDetectorEXTInfo>(planeDetector, &CommonObjectInfoTable::GetXrPlaneDetectorEXTInfo);
    XrPlaneDetectionStateEXT* out_state = state->IsNull() ? nullptr : state->AllocateOutputData(1, static_cast<XrPlaneDetectionStateEXT>(0));

    XrResult replay_result = GetInstanceTable(in_planeDetector)->GetPlaneDetectionStateEXT(in_planeDetector, out_state);
    CheckResult("xrGetPlaneDetectionStateEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetPlaneDetectionStateEXT>::UpdateState(this, call_info, returnValue, planeDetector, state, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetPlaneDetectionsEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector,
    StructPointerDecoder<Decoded_XrPlaneDetectorGetInfoEXT>* info,
    StructPointerDecoder<Decoded_XrPlaneDetectorLocationsEXT>* locations)
{
    XrPlaneDetectorEXT in_planeDetector = MapHandle<OpenXrPlaneDetectorEXTInfo>(planeDetector, &CommonObjectInfoTable::GetXrPlaneDetectorEXTInfo);
    const XrPlaneDetectorGetInfoEXT* in_info = info->GetPointer();
    MapStructHandles(info->GetMetaStructPointer(), GetObjectInfoTable());
    XrPlaneDetectorLocationsEXT* out_locations = locations->IsNull() ? nullptr : locations->AllocateOutputData(1, { XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT, nullptr });
    InitializeOutputStructNext(locations);

    XrResult replay_result = GetInstanceTable(in_planeDetector)->GetPlaneDetectionsEXT(in_planeDetector, in_info, out_locations);
    CheckResult("xrGetPlaneDetectionsEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetPlaneDetectionsEXT>::UpdateState(this, call_info, returnValue, planeDetector, info, locations, replay_result);
}

void OpenXrReplayConsumer::Process_xrGetPlanePolygonBufferEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            planeDetector,
    uint64_t                                    planeId,
    uint32_t                                    polygonBufferIndex,
    StructPointerDecoder<Decoded_XrPlaneDetectorPolygonBufferEXT>* polygonBuffer)
{
    XrPlaneDetectorEXT in_planeDetector = MapHandle<OpenXrPlaneDetectorEXTInfo>(planeDetector, &CommonObjectInfoTable::GetXrPlaneDetectorEXTInfo);
    XrPlaneDetectorPolygonBufferEXT* out_polygonBuffer = polygonBuffer->IsNull() ? nullptr : polygonBuffer->AllocateOutputData(1, { XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT, nullptr });
    InitializeOutputStructNext(polygonBuffer);

    XrResult replay_result = GetInstanceTable(in_planeDetector)->GetPlanePolygonBufferEXT(in_planeDetector, planeId, polygonBufferIndex, out_polygonBuffer);
    CheckResult("xrGetPlanePolygonBufferEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrGetPlanePolygonBufferEXT>::UpdateState(this, call_info, returnValue, planeDetector, planeId, polygonBufferIndex, polygonBuffer, replay_result);
}

void OpenXrReplayConsumer::Process_xrPollFutureEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrFuturePollInfoEXT>* pollInfo,
    StructPointerDecoder<Decoded_XrFuturePollResultEXT>* pollResult)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const XrFuturePollInfoEXT* in_pollInfo = pollInfo->GetPointer();
    MapStructHandles(pollInfo->GetMetaStructPointer(), GetObjectInfoTable());
    XrFuturePollResultEXT* out_pollResult = pollResult->IsNull() ? nullptr : pollResult->AllocateOutputData(1, { XR_TYPE_FUTURE_POLL_RESULT_EXT, nullptr });
    InitializeOutputStructNext(pollResult);

    XrResult replay_result = GetInstanceTable(in_instance)->PollFutureEXT(in_instance, in_pollInfo, out_pollResult);
    CheckResult("xrPollFutureEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrPollFutureEXT>::UpdateState(this, call_info, returnValue, instance, pollInfo, pollResult, replay_result);
}

void OpenXrReplayConsumer::Process_xrCancelFutureEXT(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrFutureCancelInfoEXT>* cancelInfo)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const XrFutureCancelInfoEXT* in_cancelInfo = cancelInfo->GetPointer();
    MapStructHandles(cancelInfo->GetMetaStructPointer(), GetObjectInfoTable());

    XrResult replay_result = GetInstanceTable(in_instance)->CancelFutureEXT(in_instance, in_cancelInfo);
    CheckResult("xrCancelFutureEXT", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrCancelFutureEXT>::UpdateState(this, call_info, returnValue, instance, cancelInfo, replay_result);
}

void OpenXrReplayConsumer::Process_xrEnableUserCalibrationEventsML(
    const ApiCallInfo&                          call_info,
    XrResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_XrUserCalibrationEnableEventsInfoML>* enableInfo)
{
    XrInstance in_instance = MapHandle<OpenXrInstanceInfo>(instance, &CommonObjectInfoTable::GetXrInstanceInfo);
    const XrUserCalibrationEnableEventsInfoML* in_enableInfo = enableInfo->GetPointer();

    XrResult replay_result = GetInstanceTable(in_instance)->EnableUserCalibrationEventsML(in_instance, in_enableInfo);
    CheckResult("xrEnableUserCalibrationEventsML", returnValue, replay_result, call_info);
    CustomProcess<format::ApiCallId::ApiCall_xrEnableUserCalibrationEventsML>::UpdateState(this, call_info, returnValue, instance, enableInfo, replay_result);
}

void InitializeOutputStructNextImpl(const XrBaseInStructure* in_next, XrBaseOutStructure* output_struct)
{
    while(in_next)
    {
        switch(in_next->type)
        {
            case XR_TYPE_API_LAYER_PROPERTIES:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrApiLayerProperties>());
                break;
            }
            case XR_TYPE_EXTENSION_PROPERTIES:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrExtensionProperties>());
                break;
            }
            case XR_TYPE_INSTANCE_CREATE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrInstanceCreateInfo>());
                break;
            }
            case XR_TYPE_INSTANCE_PROPERTIES:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrInstanceProperties>());
                break;
            }
            case XR_TYPE_EVENT_DATA_BUFFER:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataBuffer>());
                break;
            }
            case XR_TYPE_SYSTEM_GET_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemGetInfo>());
                break;
            }
            case XR_TYPE_SYSTEM_PROPERTIES:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemProperties>());
                break;
            }
            case XR_TYPE_SESSION_CREATE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSessionCreateInfo>());
                break;
            }
            case XR_TYPE_SPACE_VELOCITY:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceVelocity>());
                break;
            }
            case XR_TYPE_REFERENCE_SPACE_CREATE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrReferenceSpaceCreateInfo>());
                break;
            }
            case XR_TYPE_ACTION_SPACE_CREATE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrActionSpaceCreateInfo>());
                break;
            }
            case XR_TYPE_SPACE_LOCATION:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceLocation>());
                break;
            }
            case XR_TYPE_VIEW_CONFIGURATION_PROPERTIES:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrViewConfigurationProperties>());
                break;
            }
            case XR_TYPE_VIEW_CONFIGURATION_VIEW:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrViewConfigurationView>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_CREATE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainCreateInfo>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainImageAcquireInfo>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainImageWaitInfo>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainImageReleaseInfo>());
                break;
            }
            case XR_TYPE_SESSION_BEGIN_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSessionBeginInfo>());
                break;
            }
            case XR_TYPE_FRAME_WAIT_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFrameWaitInfo>());
                break;
            }
            case XR_TYPE_FRAME_STATE:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFrameState>());
                break;
            }
            case XR_TYPE_FRAME_BEGIN_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFrameBeginInfo>());
                break;
            }
            case XR_TYPE_FRAME_END_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFrameEndInfo>());
                break;
            }
            case XR_TYPE_VIEW_LOCATE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrViewLocateInfo>());
                break;
            }
            case XR_TYPE_VIEW_STATE:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrViewState>());
                break;
            }
            case XR_TYPE_VIEW:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrView>());
                break;
            }
            case XR_TYPE_ACTION_SET_CREATE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrActionSetCreateInfo>());
                break;
            }
            case XR_TYPE_ACTION_CREATE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrActionCreateInfo>());
                break;
            }
            case XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrInteractionProfileSuggestedBinding>());
                break;
            }
            case XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSessionActionSetsAttachInfo>());
                break;
            }
            case XR_TYPE_INTERACTION_PROFILE_STATE:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrInteractionProfileState>());
                break;
            }
            case XR_TYPE_ACTION_STATE_GET_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrActionStateGetInfo>());
                break;
            }
            case XR_TYPE_ACTION_STATE_BOOLEAN:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrActionStateBoolean>());
                break;
            }
            case XR_TYPE_ACTION_STATE_FLOAT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrActionStateFloat>());
                break;
            }
            case XR_TYPE_ACTION_STATE_VECTOR2F:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrActionStateVector2f>());
                break;
            }
            case XR_TYPE_ACTION_STATE_POSE:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrActionStatePose>());
                break;
            }
            case XR_TYPE_ACTIONS_SYNC_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrActionsSyncInfo>());
                break;
            }
            case XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrBoundSourcesForActionEnumerateInfo>());
                break;
            }
            case XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrInputSourceLocalizedNameGetInfo>());
                break;
            }
            case XR_TYPE_HAPTIC_ACTION_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHapticActionInfo>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerProjectionView>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerProjection>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_QUAD:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerQuad>());
                break;
            }
            case XR_TYPE_EVENT_DATA_EVENTS_LOST:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataEventsLost>());
                break;
            }
            case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataInstanceLossPending>());
                break;
            }
            case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataSessionStateChanged>());
                break;
            }
            case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataReferenceSpaceChangePending>());
                break;
            }
            case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataInteractionProfileChanged>());
                break;
            }
            case XR_TYPE_HAPTIC_VIBRATION:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHapticVibration>());
                break;
            }
            case XR_TYPE_SPACES_LOCATE_INFO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpacesLocateInfo>());
                break;
            }
            case XR_TYPE_SPACE_LOCATIONS:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceLocations>());
                break;
            }
            case XR_TYPE_SPACE_VELOCITIES:
            {
                output_struct->next = OverrideOutputStructNext_XrSpaceVelocities(in_next, output_struct);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerCubeKHR>());
                break;
            }
            case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrInstanceCreateInfoAndroidKHR>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerDepthInfoKHR>());
                break;
            }
            case XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVulkanSwapchainFormatListCreateInfoKHR>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerCylinderKHR>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerEquirectKHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsBindingOpenGLWin32KHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsBindingOpenGLXlibKHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsBindingOpenGLXcbKHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsBindingOpenGLWaylandKHR>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainImageOpenGLKHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsRequirementsOpenGLKHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsBindingOpenGLESAndroidKHR>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainImageOpenGLESKHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsRequirementsOpenGLESKHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsBindingVulkanKHR>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainImageVulkanKHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsRequirementsVulkanKHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsBindingD3D11KHR>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainImageD3D11KHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsRequirementsD3D11KHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsBindingD3D12KHR>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainImageD3D12KHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsRequirementsD3D12KHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_BINDING_METAL_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsBindingMetalKHR>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_METAL_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainImageMetalKHR>());
                break;
            }
            case XR_TYPE_GRAPHICS_REQUIREMENTS_METAL_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsRequirementsMetalKHR>());
                break;
            }
            case XR_TYPE_VISIBILITY_MASK_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVisibilityMaskKHR>());
                break;
            }
            case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataVisibilityMaskChangedKHR>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerColorScaleBiasKHR>());
                break;
            }
            case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrLoaderInitInfoAndroidKHR>());
                break;
            }
            case XR_TYPE_VULKAN_INSTANCE_CREATE_INFO_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVulkanInstanceCreateInfoKHR>());
                break;
            }
            case XR_TYPE_VULKAN_DEVICE_CREATE_INFO_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVulkanDeviceCreateInfoKHR>());
                break;
            }
            case XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVulkanGraphicsDeviceGetInfoKHR>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerEquirect2KHR>());
                break;
            }
            case XR_TYPE_BINDING_MODIFICATIONS_KHR:
            {
                output_struct->next = OverrideOutputStructNext_XrBindingModificationsKHR(in_next, output_struct);
                break;
            }
            case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataPerfSettingsEXT>());
                break;
            }
            case XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrDebugUtilsObjectNameInfoEXT>());
                break;
            }
            case XR_TYPE_DEBUG_UTILS_LABEL_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrDebugUtilsLabelEXT>());
                break;
            }
            case XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrDebugUtilsMessengerCallbackDataEXT>());
                break;
            }
            case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrDebugUtilsMessengerCreateInfoEXT>());
                break;
            }
            case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemEyeGazeInteractionPropertiesEXT>());
                break;
            }
            case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEyeGazeSampleTimeEXT>());
                break;
            }
            case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSessionCreateInfoOverlayEXTX>());
                break;
            }
            case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataMainSessionVisibilityChangedEXTX>());
                break;
            }
            case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpatialAnchorCreateInfoMSFT>());
                break;
            }
            case XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpatialAnchorSpaceCreateInfoMSFT>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerImageLayoutFB>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerAlphaBlendFB>());
                break;
            }
            case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrViewConfigurationDepthRangeEXT>());
                break;
            }
            case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGraphicsBindingEGLMNDX>());
                break;
            }
            case XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpatialGraphNodeSpaceCreateInfoMSFT>());
                break;
            }
            case XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpatialGraphStaticNodeBindingCreateInfoMSFT>());
                break;
            }
            case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_GET_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpatialGraphNodeBindingPropertiesGetInfoMSFT>());
                break;
            }
            case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpatialGraphNodeBindingPropertiesMSFT>());
                break;
            }
            case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemHandTrackingPropertiesEXT>());
                break;
            }
            case XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandTrackerCreateInfoEXT>());
                break;
            }
            case XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandJointsLocateInfoEXT>());
                break;
            }
            case XR_TYPE_HAND_JOINT_LOCATIONS_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandJointLocationsEXT>());
                break;
            }
            case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
            {
                output_struct->next = OverrideOutputStructNext_XrHandJointVelocitiesEXT(in_next, output_struct);
                break;
            }
            case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemHandTrackingMeshPropertiesMSFT>());
                break;
            }
            case XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandMeshSpaceCreateInfoMSFT>());
                break;
            }
            case XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandMeshUpdateInfoMSFT>());
                break;
            }
            case XR_TYPE_HAND_MESH_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandMeshMSFT>());
                break;
            }
            case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandPoseTypeInfoMSFT>());
                break;
            }
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSecondaryViewConfigurationSessionBeginInfoMSFT>());
                break;
            }
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSecondaryViewConfigurationStateMSFT>());
                break;
            }
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSecondaryViewConfigurationFrameStateMSFT>());
                break;
            }
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSecondaryViewConfigurationLayerInfoMSFT>());
                break;
            }
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSecondaryViewConfigurationFrameEndInfoMSFT>());
                break;
            }
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSecondaryViewConfigurationSwapchainCreateInfoMSFT>());
                break;
            }
            case XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrControllerModelKeyStateMSFT>());
                break;
            }
            case XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrControllerModelNodePropertiesMSFT>());
                break;
            }
            case XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrControllerModelPropertiesMSFT>());
                break;
            }
            case XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrControllerModelNodeStateMSFT>());
                break;
            }
            case XR_TYPE_CONTROLLER_MODEL_STATE_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrControllerModelStateMSFT>());
                break;
            }
            case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrViewConfigurationViewFovEPIC>());
                break;
            }
            case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHolographicWindowAttachmentMSFT>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerReprojectionInfoMSFT>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerReprojectionPlaneOverrideMSFT>());
                break;
            }
            case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrAndroidSurfaceSwapchainCreateInfoFB>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerSecureContentFB>());
                break;
            }
            case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemBodyTrackingPropertiesFB>());
                break;
            }
            case XR_TYPE_BODY_TRACKER_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrBodyTrackerCreateInfoFB>());
                break;
            }
            case XR_TYPE_BODY_SKELETON_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrBodySkeletonFB>());
                break;
            }
            case XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrBodyJointsLocateInfoFB>());
                break;
            }
            case XR_TYPE_BODY_JOINT_LOCATIONS_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrBodyJointLocationsFB>());
                break;
            }
            case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrInteractionProfileDpadBindingEXT>());
                break;
            }
            case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrInteractionProfileAnalogThresholdVALVE>());
                break;
            }
            case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandJointsMotionRangeInfoEXT>());
                break;
            }
            case XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneObserverCreateInfoMSFT>());
                break;
            }
            case XR_TYPE_SCENE_CREATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneCreateInfoMSFT>());
                break;
            }
            case XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrNewSceneComputeInfoMSFT>());
                break;
            }
            case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVisualMeshComputeLodInfoMSFT>());
                break;
            }
            case XR_TYPE_SCENE_COMPONENTS_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneComponentsMSFT>());
                break;
            }
            case XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneComponentsGetInfoMSFT>());
                break;
            }
            case XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneComponentLocationsMSFT>());
                break;
            }
            case XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneComponentsLocateInfoMSFT>());
                break;
            }
            case XR_TYPE_SCENE_OBJECTS_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneObjectsMSFT>());
                break;
            }
            case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneComponentParentFilterInfoMSFT>());
                break;
            }
            case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneObjectTypesFilterInfoMSFT>());
                break;
            }
            case XR_TYPE_SCENE_PLANES_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrScenePlanesMSFT>());
                break;
            }
            case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrScenePlaneAlignmentFilterInfoMSFT>());
                break;
            }
            case XR_TYPE_SCENE_MESHES_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneMeshesMSFT>());
                break;
            }
            case XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneMeshBuffersGetInfoMSFT>());
                break;
            }
            case XR_TYPE_SCENE_MESH_BUFFERS_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneMeshBuffersMSFT>());
                break;
            }
            case XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneMeshVertexBufferMSFT>());
                break;
            }
            case XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneMeshIndicesUint32MSFT>());
                break;
            }
            case XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneMeshIndicesUint16MSFT>());
                break;
            }
            case XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSerializedSceneFragmentDataGetInfoMSFT>());
                break;
            }
            case XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneDeserializeInfoMSFT>());
                break;
            }
            case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataDisplayRefreshRateChangedFB>());
                break;
            }
            case XR_TYPE_VIVE_TRACKER_PATHS_HTCX:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrViveTrackerPathsHTCX>());
                break;
            }
            case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataViveTrackerConnectedHTCX>());
                break;
            }
            case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemFacialTrackingPropertiesHTC>());
                break;
            }
            case XR_TYPE_FACIAL_EXPRESSIONS_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFacialExpressionsHTC>());
                break;
            }
            case XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFacialTrackerCreateInfoHTC>());
                break;
            }
            case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemColorSpacePropertiesFB>());
                break;
            }
            case XR_TYPE_HAND_TRACKING_MESH_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandTrackingMeshFB>());
                break;
            }
            case XR_TYPE_HAND_TRACKING_SCALE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandTrackingScaleFB>());
                break;
            }
            case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandTrackingAimStateFB>());
                break;
            }
            case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandTrackingCapsulesStateFB>());
                break;
            }
            case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemSpatialEntityPropertiesFB>());
                break;
            }
            case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpatialAnchorCreateInfoFB>());
                break;
            }
            case XR_TYPE_SPACE_COMPONENT_STATUS_SET_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceComponentStatusSetInfoFB>());
                break;
            }
            case XR_TYPE_SPACE_COMPONENT_STATUS_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceComponentStatusFB>());
                break;
            }
            case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataSpatialAnchorCreateCompleteFB>());
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataSpaceSetStatusCompleteFB>());
                break;
            }
            case XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFoveationProfileCreateInfoFB>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainCreateInfoFoveationFB>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainStateFoveationFB>());
                break;
            }
            case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFoveationLevelProfileCreateInfoFB>());
                break;
            }
            case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemKeyboardTrackingPropertiesFB>());
                break;
            }
            case XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrKeyboardSpaceCreateInfoFB>());
                break;
            }
            case XR_TYPE_KEYBOARD_TRACKING_QUERY_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrKeyboardTrackingQueryFB>());
                break;
            }
            case XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrTriangleMeshCreateInfoFB>());
                break;
            }
            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemPassthroughPropertiesFB>());
                break;
            }
            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemPassthroughProperties2FB>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughCreateInfoFB>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughLayerCreateInfoFB>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerPassthroughFB>());
                break;
            }
            case XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGeometryInstanceCreateInfoFB>());
                break;
            }
            case XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGeometryInstanceTransformFB>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_STYLE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughStyleFB>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughColorMapMonoToRgbaFB>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughColorMapMonoToMonoFB>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughBrightnessContrastSaturationFB>());
                break;
            }
            case XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataPassthroughStateChangedFB>());
                break;
            }
            case XR_TYPE_RENDER_MODEL_PATH_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrRenderModelPathInfoFB>());
                break;
            }
            case XR_TYPE_RENDER_MODEL_PROPERTIES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrRenderModelPropertiesFB>());
                break;
            }
            case XR_TYPE_RENDER_MODEL_BUFFER_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrRenderModelBufferFB>());
                break;
            }
            case XR_TYPE_RENDER_MODEL_LOAD_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrRenderModelLoadInfoFB>());
                break;
            }
            case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemRenderModelPropertiesFB>());
                break;
            }
            case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrRenderModelCapabilitiesRequestFB>());
                break;
            }
            case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrViewLocateFoveatedRenderingVARJO>());
                break;
            }
            case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFoveatedViewConfigurationViewVARJO>());
                break;
            }
            case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemFoveatedRenderingPropertiesVARJO>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerDepthTestVARJO>());
                break;
            }
            case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemMarkerTrackingPropertiesVARJO>());
                break;
            }
            case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataMarkerTrackingUpdateVARJO>());
                break;
            }
            case XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrMarkerSpaceCreateInfoVARJO>());
                break;
            }
            case XR_TYPE_FRAME_END_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFrameEndInfoML>());
                break;
            }
            case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrGlobalDimmerFrameEndInfoML>());
                break;
            }
            case XR_TYPE_COORDINATE_SPACE_CREATE_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCoordinateSpaceCreateInfoML>());
                break;
            }
            case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemMarkerUnderstandingPropertiesML>());
                break;
            }
            case XR_TYPE_MARKER_DETECTOR_CREATE_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrMarkerDetectorCreateInfoML>());
                break;
            }
            case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrMarkerDetectorArucoInfoML>());
                break;
            }
            case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrMarkerDetectorSizeInfoML>());
                break;
            }
            case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrMarkerDetectorAprilTagInfoML>());
                break;
            }
            case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrMarkerDetectorCustomProfileInfoML>());
                break;
            }
            case XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrMarkerDetectorSnapshotInfoML>());
                break;
            }
            case XR_TYPE_MARKER_DETECTOR_STATE_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrMarkerDetectorStateML>());
                break;
            }
            case XR_TYPE_MARKER_SPACE_CREATE_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrMarkerSpaceCreateInfoML>());
                break;
            }
            case XR_TYPE_LOCALIZATION_MAP_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrLocalizationMapML>());
                break;
            }
            case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataLocalizationChangedML>());
                break;
            }
            case XR_TYPE_MAP_LOCALIZATION_REQUEST_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrMapLocalizationRequestInfoML>());
                break;
            }
            case XR_TYPE_LOCALIZATION_MAP_IMPORT_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrLocalizationMapImportInfoML>());
                break;
            }
            case XR_TYPE_LOCALIZATION_ENABLE_EVENTS_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrLocalizationEnableEventsInfoML>());
                break;
            }
            case XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpatialAnchorPersistenceInfoMSFT>());
                break;
            }
            case XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT>());
                break;
            }
            case XR_TYPE_SCENE_MARKERS_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneMarkersMSFT>());
                break;
            }
            case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneMarkerTypeFilterMSFT>());
                break;
            }
            case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneMarkerQRCodesMSFT>());
                break;
            }
            case XR_TYPE_SPACE_QUERY_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceQueryInfoFB>());
                break;
            }
            case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceStorageLocationFilterInfoFB>());
                break;
            }
            case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceUuidFilterInfoFB>());
                break;
            }
            case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceComponentFilterInfoFB>());
                break;
            }
            case XR_TYPE_SPACE_QUERY_RESULTS_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceQueryResultsFB>());
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataSpaceQueryResultsAvailableFB>());
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataSpaceQueryCompleteFB>());
                break;
            }
            case XR_TYPE_SPACE_SAVE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceSaveInfoFB>());
                break;
            }
            case XR_TYPE_SPACE_ERASE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceEraseInfoFB>());
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataSpaceSaveCompleteFB>());
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataSpaceEraseCompleteFB>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainImageFoveationVulkanFB>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainStateAndroidSurfaceDimensionsFB>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainStateSamplerOpenGLESFB>());
                break;
            }
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSwapchainStateSamplerVulkanFB>());
                break;
            }
            case XR_TYPE_SPACE_SHARE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceShareInfoFB>());
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataSpaceShareCompleteFB>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerSpaceWarpInfoFB>());
                break;
            }
            case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemSpaceWarpPropertiesFB>());
                break;
            }
            case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHapticAmplitudeEnvelopeVibrationFB>());
                break;
            }
            case XR_TYPE_SEMANTIC_LABELS_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSemanticLabelsFB>());
                break;
            }
            case XR_TYPE_ROOM_LAYOUT_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrRoomLayoutFB>());
                break;
            }
            case XR_TYPE_BOUNDARY_2D_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrBoundary2DFB>());
                break;
            }
            case XR_TYPE_SEMANTIC_LABELS_SUPPORT_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSemanticLabelsSupportInfoFB>());
                break;
            }
            case XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrDigitalLensControlALMALENCE>());
                break;
            }
            case XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataSceneCaptureCompleteFB>());
                break;
            }
            case XR_TYPE_SCENE_CAPTURE_REQUEST_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSceneCaptureRequestInfoFB>());
                break;
            }
            case XR_TYPE_SPACE_CONTAINER_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceContainerFB>());
                break;
            }
            case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFoveationEyeTrackedProfileCreateInfoMETA>());
                break;
            }
            case XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFoveationEyeTrackedStateMETA>());
                break;
            }
            case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemFoveationEyeTrackedPropertiesMETA>());
                break;
            }
            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemFaceTrackingPropertiesFB>());
                break;
            }
            case XR_TYPE_FACE_TRACKER_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFaceTrackerCreateInfoFB>());
                break;
            }
            case XR_TYPE_FACE_EXPRESSION_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFaceExpressionInfoFB>());
                break;
            }
            case XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFaceExpressionWeightsFB>());
                break;
            }
            case XR_TYPE_EYE_TRACKER_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEyeTrackerCreateInfoFB>());
                break;
            }
            case XR_TYPE_EYE_GAZES_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEyeGazesInfoFB>());
                break;
            }
            case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemEyeTrackingPropertiesFB>());
                break;
            }
            case XR_TYPE_EYE_GAZES_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEyeGazesFB>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughKeyboardHandsIntensityFB>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerSettingsFB>());
                break;
            }
            case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHapticPcmVibrationFB>());
                break;
            }
            case XR_TYPE_DEVICE_PCM_SAMPLE_RATE_STATE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrDevicePcmSampleRateStateFB>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerDepthTestFB>());
                break;
            }
            case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrLocalDimmingFrameEndInfoMETA>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_PREFERENCES_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughPreferencesMETA>());
                break;
            }
            case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemVirtualKeyboardPropertiesMETA>());
                break;
            }
            case XR_TYPE_VIRTUAL_KEYBOARD_CREATE_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVirtualKeyboardCreateInfoMETA>());
                break;
            }
            case XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVirtualKeyboardSpaceCreateInfoMETA>());
                break;
            }
            case XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVirtualKeyboardLocationInfoMETA>());
                break;
            }
            case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_VISIBILITY_SET_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVirtualKeyboardModelVisibilitySetInfoMETA>());
                break;
            }
            case XR_TYPE_VIRTUAL_KEYBOARD_ANIMATION_STATE_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVirtualKeyboardAnimationStateMETA>());
                break;
            }
            case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVirtualKeyboardModelAnimationStatesMETA>());
                break;
            }
            case XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVirtualKeyboardTextureDataMETA>());
                break;
            }
            case XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVirtualKeyboardInputInfoMETA>());
                break;
            }
            case XR_TYPE_VIRTUAL_KEYBOARD_TEXT_CONTEXT_CHANGE_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVirtualKeyboardTextContextChangeInfoMETA>());
                break;
            }
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataVirtualKeyboardCommitTextMETA>());
                break;
            }
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataVirtualKeyboardBackspaceMETA>());
                break;
            }
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataVirtualKeyboardEnterMETA>());
                break;
            }
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataVirtualKeyboardShownMETA>());
                break;
            }
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataVirtualKeyboardHiddenMETA>());
                break;
            }
            case XR_TYPE_EXTERNAL_CAMERA_OCULUS:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrExternalCameraOCULUS>());
                break;
            }
            case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrVulkanSwapchainCreateInfoMETA>());
                break;
            }
            case XR_TYPE_PERFORMANCE_METRICS_STATE_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPerformanceMetricsStateMETA>());
                break;
            }
            case XR_TYPE_PERFORMANCE_METRICS_COUNTER_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPerformanceMetricsCounterMETA>());
                break;
            }
            case XR_TYPE_SPACE_LIST_SAVE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceListSaveInfoFB>());
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataSpaceListSaveCompleteFB>());
                break;
            }
            case XR_TYPE_SPACE_USER_CREATE_INFO_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceUserCreateInfoFB>());
                break;
            }
            case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemHeadsetIdPropertiesMETA>());
                break;
            }
            case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrRecommendedLayerResolutionMETA>());
                break;
            }
            case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrRecommendedLayerResolutionGetInfoMETA>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_COLOR_LUT_CREATE_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughColorLutCreateInfoMETA>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_COLOR_LUT_UPDATE_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughColorLutUpdateInfoMETA>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughColorMapLutMETA>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughColorMapInterpolatedLutMETA>());
                break;
            }
            case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemPassthroughColorLutPropertiesMETA>());
                break;
            }
            case XR_TYPE_SPACE_TRIANGLE_MESH_GET_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceTriangleMeshGetInfoMETA>());
                break;
            }
            case XR_TYPE_SPACE_TRIANGLE_MESH_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpaceTriangleMeshMETA>());
                break;
            }
            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemFaceTrackingProperties2FB>());
                break;
            }
            case XR_TYPE_FACE_TRACKER_CREATE_INFO2_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFaceTrackerCreateInfo2FB>());
                break;
            }
            case XR_TYPE_FACE_EXPRESSION_INFO2_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFaceExpressionInfo2FB>());
                break;
            }
            case XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFaceExpressionWeights2FB>());
                break;
            }
            case XR_TYPE_ENVIRONMENT_DEPTH_PROVIDER_CREATE_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEnvironmentDepthProviderCreateInfoMETA>());
                break;
            }
            case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_CREATE_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEnvironmentDepthSwapchainCreateInfoMETA>());
                break;
            }
            case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_STATE_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEnvironmentDepthSwapchainStateMETA>());
                break;
            }
            case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_ACQUIRE_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEnvironmentDepthImageAcquireInfoMETA>());
                break;
            }
            case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_VIEW_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEnvironmentDepthImageViewMETA>());
                break;
            }
            case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEnvironmentDepthImageMETA>());
                break;
            }
            case XR_TYPE_ENVIRONMENT_DEPTH_HAND_REMOVAL_SET_INFO_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEnvironmentDepthHandRemovalSetInfoMETA>());
                break;
            }
            case XR_TYPE_SYSTEM_ENVIRONMENT_DEPTH_PROPERTIES_META:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemEnvironmentDepthPropertiesMETA>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_CREATE_INFO_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughCreateInfoHTC>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_COLOR_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughColorHTC>());
                break;
            }
            case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPassthroughMeshTransformInfoHTC>());
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrCompositionLayerPassthroughHTC>());
                break;
            }
            case XR_TYPE_FOVEATION_APPLY_INFO_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFoveationApplyInfoHTC>());
                break;
            }
            case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFoveationDynamicModeInfoHTC>());
                break;
            }
            case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFoveationCustomModeInfoHTC>());
                break;
            }
            case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemAnchorPropertiesHTC>());
                break;
            }
            case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSpatialAnchorCreateInfoHTC>());
                break;
            }
            case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrActiveActionSetPrioritiesEXT>());
                break;
            }
            case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemForceFeedbackCurlPropertiesMNDX>());
                break;
            }
            case XR_TYPE_FORCE_FEEDBACK_CURL_APPLY_LOCATIONS_MNDX:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrForceFeedbackCurlApplyLocationsMNDX>());
                break;
            }
            case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandTrackingDataSourceInfoEXT>());
                break;
            }
            case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrHandTrackingDataSourceStateEXT>());
                break;
            }
            case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemPlaneDetectionPropertiesEXT>());
                break;
            }
            case XR_TYPE_PLANE_DETECTOR_CREATE_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPlaneDetectorCreateInfoEXT>());
                break;
            }
            case XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPlaneDetectorBeginInfoEXT>());
                break;
            }
            case XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPlaneDetectorGetInfoEXT>());
                break;
            }
            case XR_TYPE_PLANE_DETECTOR_LOCATION_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPlaneDetectorLocationEXT>());
                break;
            }
            case XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPlaneDetectorLocationsEXT>());
                break;
            }
            case XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrPlaneDetectorPolygonBufferEXT>());
                break;
            }
            case XR_TYPE_FUTURE_CANCEL_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFutureCancelInfoEXT>());
                break;
            }
            case XR_TYPE_FUTURE_POLL_INFO_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFuturePollInfoEXT>());
                break;
            }
            case XR_TYPE_FUTURE_COMPLETION_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFutureCompletionEXT>());
                break;
            }
            case XR_TYPE_FUTURE_POLL_RESULT_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrFuturePollResultEXT>());
                break;
            }
            case XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataUserPresenceChangedEXT>());
                break;
            }
            case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrSystemUserPresencePropertiesEXT>());
                break;
            }
            case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataHeadsetFitChangedML>());
                break;
            }
            case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrEventDataEyeCalibrationChangedML>());
                break;
            }
            case XR_TYPE_USER_CALIBRATION_ENABLE_EVENTS_INFO_ML:
            {
                output_struct->next = reinterpret_cast<XrBaseOutStructure*>(DecodeAllocator::Allocate<XrUserCalibrationEnableEventsInfoML>());
                break;
            }
            default:
                break;
        }
        output_struct = output_struct->next;
        output_struct->type = in_next->type;
        in_next = in_next->next;
    }
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
