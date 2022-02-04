/*
** Copyright (c) 2021-2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DEFERRED_OPERATION_INFO_H
#define GFXRECON_DECODE_DEFERRED_OPERATION_INFO_H

#include "generated/generated_vulkan_struct_decoders.h"
#include "decode/vulkan_object_info.h"

#include "vulkan/vulkan.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/*
   If some API call is a deferred operation, the process of that call will
   not be finished when the call return to caller, the task of the call will
   be processed on other threads inside the defered operation.

   For an API call which is a deferred operation, we need adding the
   following changes compared with normal API call handling during playback:

       1> Any variables used by calling the API function must have
       lifecycle beyond the API call return, until deferred
       operation finished on all other threads, it might be lots of
       API calls later in trace file.

       2> The handling to result of calling real API function in
       post-process must be happened after deferred operation
       finished on all other threads. This is also different with normal
       API call, because the result is available once the API call return
       to caller.

          The result here is not just return value of the API function,
       it include any result that this API call generated and can be accessed
       by caller.

    So for such API, we store all related variables in an instance of
    VulkanDeferredOperationInfo. Because different API call as deferred operation
    will need to store different related variables, so here the class
    VulkanDeferredOperationInfo is a parent class, class for specific API need
    to be derived from VulkanDeferredOperationInfo, for example, the derived class
    VulkanDeferredOperationInfoCreateRayTracingPipelines is used for API
    vkCreateRayTracingPipelines.
*/
class VulkanDeferredOperationInfo
{
  public:
    VulkanDeferredOperationInfo(format::ApiCallId call_id) : api_call_id_(call_id), operation_completed_(false) {}
    ~VulkanDeferredOperationInfo() {}

    format::ApiCallId GetApiCallId() { return api_call_id_; }
    bool              IsOperationCompleted() { return operation_completed_; }
    void              MarkOperationCompleted() { operation_completed_ = true; }

  protected:
    format::ApiCallId api_call_id_;
    bool              operation_completed_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DEFERRED_OPERATION_INFO_H
