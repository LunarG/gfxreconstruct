/*
** Copyright (c) 2019-2020 LunarG, Inc.
** Copyright (c) 2023-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPERS_H
#define GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPERS_H

#include "encode/descriptor_update_template_info.h"
#include "encode/openxr_state_info.h"
#include "encode/handle_unwrap_memory.h"
#include "format/format.h"
#include "generated/generated_openxr_dispatch_table.h"
#include "graphics/openxr_device_util.h"
#include "util/defines.h"
#include "util/memory_output_stream.h"
#include "util/page_guard_manager.h"

#include "openxr/openxr.h"

#include <limits>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

//
// Handle wrappers for storing object state information with object handles.
//

template <typename T>
struct OpenXrHandleWrapper
{
    typedef T HandleType;

    // Dispatch table key for dispatchable handles. Must be the first struct member to be compatible with the
    // loader defined handles.
    void* dispatch_key{ nullptr };

    // Standard state info required for all handles.
    HandleType        handle{ XR_NULL_HANDLE };           // Original handle value provided by the driver.
    format::HandleId  handle_id{ format::kNullHandleId }; // Globally unique ID assigned to the handle by the layer.
    format::ApiCallId create_call_id{ format::ApiCallId::ApiCall_Unknown };
    OpenXrCreateParameters create_parameters;
};

//
// Type definitions for handle wrappers that do not require additional state info.
//

// clang-format off
struct ShaderModuleWrapper                  : public HandleWrapper<VkShaderModule> {};
struct PipelineCacheWrapper                 : public HandleWrapper<VkPipelineCache> {};
struct SamplerWrapper                       : public HandleWrapper<VkSampler> {};
struct SamplerYcbcrConversionWrapper        : public HandleWrapper<VkSamplerYcbcrConversion> {};
struct DebugReportCallbackEXTWrapper        : public HandleWrapper<VkDebugReportCallbackEXT> {};
struct DebugUtilsMessengerEXTWrapper        : public HandleWrapper<VkDebugUtilsMessengerEXT> {};
struct ValidationCacheEXTWrapper            : public HandleWrapper<VkValidationCacheEXT> {};
struct IndirectCommandsLayoutNVWrapper      : public HandleWrapper<VkIndirectCommandsLayoutNV> {};
struct PerformanceConfigurationINTELWrapper : public HandleWrapper<VkPerformanceConfigurationINTEL> {};
struct MicromapEXTWrapper                   : public HandleWrapper<VkMicromapEXT> {};
struct OpticalFlowSessionNVWrapper          : public HandleWrapper<VkOpticalFlowSessionNV> {};
struct VideoSessionKHRWrapper               : public HandleWrapper<VkVideoSessionKHR> {};
struct VideoSessionParametersKHRWrapper     : public HandleWrapper<VkVideoSessionParametersKHR> {};
struct ShaderEXTWrapper                     : public HandleWrapper<VkShaderEXT> {};


GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPERS_H
