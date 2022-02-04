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

#ifndef GFXRECON_ENCODE_DEFERRED_OPERATION_H
#define GFXRECON_ENCODE_DEFERRED_OPERATION_H

#include "vulkan/vulkan.h"

#include <mutex>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

/*
   If some API call is a deferred operation, the process of that call will
   not be finished when the call return to caller, the task of the call will
   be processed on other threads inside the deferred operation.

   For such title, if vkCreateRayTracingPipelinesKHR is set to a deferred
   operation, when call to vkCreateRayTracingPipelinesKHR return, the real
   task of vkCreateRayTracingPipelinesKHR still not finished, and being
   processed on other threads if vkDeferredOperationJoinKHR was called on
   that thread.

   In gfxr source code before the pull request, any API call handling like
   the following (for example vkCreateRayTracingPipelinesKHR):
          vkCreateRayTracingPipelinesKHR(......)
          {
               pre-process;
               call real API function of vkCreateRayTracingPipelinesKHR(......)
               post-process;
               return result;
          }
   If the API call is a deferred operation, we need adding the
   following changes:

       1> any variables used by calling real API function or after the calling
       must have lifecycle beyond the API call return, until deferred
       operation finished on all other threads.

       2> The handling to result of calling real API function in
       post-process must be happened after deferred operation
       finished on all other threads.

          The result here is not just return value of the real API function,
       it include any result which can be accessed by caller, for example,
       vkCreateRayTracingPipelinesKHR will return pipeline handle in a host
       memory buffer , GFXR need to do some wrap/unwrap handling for the
       returned pipeline handle. Such handling need happened in other threads
       where API vkDeferredOperationJoinKHR was called on that thread if the
       VulkanDeferredOperation was finished.

*/
class VulkanDeferredOperation
{
  public:
    VulkanDeferredOperation(format::ApiCallId call_id, VkDevice device, VkDeferredOperationKHR deferred_operation_handle) :
        api_call_id_(call_id), deferred_operation_(deferred_operation_handle), device_(device)
    {}
    virtual ~VulkanDeferredOperation() {}

    virtual VkResult GetStatus();
    virtual void     PostProcess() = 0;

    format::ApiCallId GetApiCallId() { return api_call_id_; }
  protected:
    format::ApiCallId      api_call_id_;
    VkDeferredOperationKHR deferred_operation_;
    VkDevice               device_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DEFERRED_OPERATION_H
