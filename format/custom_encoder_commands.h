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

#ifndef BRIMSTONE_FORMAT_CUSTOM_ENCODER_COMMANDS_H
#define BRIMSTONE_FORMAT_CUSTOM_ENCODER_COMMANDS_H

#include "util/defines.h"
#include "format/api_call_id.h"
#include "format/trace_manager.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

template <ApiCallId Id>
struct CustomEncoderPreCall
{
    template <typename... Args>
    static void Dispatch(TraceManager*, Args...)
    {
    }
};

template <ApiCallId Id>
struct CustomEncoderPostCall
{
    template <typename... Args>
    static void Dispatch(TraceManager*, Args...)
    {
    }

    template <typename... Args>
    static void Dispatch(TraceManager*, VkResult, Args...)
    {
    }
};

template <>
struct CustomEncoderPreCall<ApiCallId_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateSwapchain(args...);
    }
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_CUSTOM_ENCODER_COMMANDS_H
