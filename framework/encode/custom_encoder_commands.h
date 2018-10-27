/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef BRIMSTONE_ENCODE_CUSTOM_ENCODER_COMMANDS_H
#define BRIMSTONE_ENCODE_CUSTOM_ENCODER_COMMANDS_H

#include "util/defines.h"
#include "format/api_call_id.h"
#include "encode/trace_manager.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(encode)

template <format::ApiCallId Id>
struct CustomEncoderPreCall
{
    template <typename... Args>
    static void Dispatch(TraceManager*, Args...)
    {}
};

template <format::ApiCallId Id>
struct CustomEncoderPostCall
{
    template <typename... Args>
    static void Dispatch(TraceManager*, Args...)
    {}

    template <typename... Args>
    static void Dispatch(TraceManager*, VkResult, Args...)
    {}
};

// Dispatch custom command for window resize command generation.
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateSwapchain(args...);
    }
};

// Dispatch custom commands for fill memory command generation.
template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkAllocateMemory(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkMapMemory(result, args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkFlushMappedMemoryRanges(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkUnmapMemory(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkFreeMemory(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkQueueSubmit(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateDescriptorUpdateTemplate(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateDescriptorUpdateTemplateKHR(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkDestroyDescriptorUpdateTemplate(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkDestroyDescriptorUpdateTemplateKHR(args...);
    }
};

BRIMSTONE_END_NAMESPACE(encode)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_ENCODE_CUSTOM_ENCODER_COMMANDS_H
