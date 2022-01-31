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

#ifndef GFXRECON_ENCODE_DEFERRED_OPERATION_CREATE_RAY_TRACING_PIPELINES_H
#define GFXRECON_ENCODE_DEFERRED_OPERATION_CREATE_RAY_TRACING_PIPELINES_H

#include "encode/deferred_operation.h"

#include "vulkan/vulkan.h"

#include <mutex>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename T>
struct DeferredOperationCustomArrayDeleter
{
    void operator()(T const* p) { delete[] p; }
};

class DeferredOperationCreateRayTracingPipelines : public DeferredOperation
{
  public:
    DeferredOperationCreateRayTracingPipelines(VkDevice                                 device,
                                               VkDeferredOperationKHR                   deferredOperation,
                                               VkPipelineCache                          pipelineCache,
                                               uint32_t                                 createInfoCount,
                                               const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                               const VkAllocationCallbacks*             pAllocator,
                                               VkPipeline*                              pPipelines) :
        DeferredOperation(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR, device, deferredOperation),
        pipeline_cache_(pipelineCache), create_info_count_(createInfoCount),
        create_infos_(pCreateInfos), allocator_(pAllocator), pipelines_(pPipelines),
        modified_create_infos_(new VkRayTracingPipelineCreateInfoKHR[createInfoCount],
                               DeferredOperationCustomArrayDeleter<VkRayTracingPipelineCreateInfoKHR>())
    {}

    virtual ~DeferredOperationCreateRayTracingPipelines() {}

    void PostProcess();

    std::shared_ptr<VkRayTracingPipelineCreateInfoKHR>& GetModifiedCreateInfos() { return modified_create_infos_; }
    HandleUnwrapMemory&                                   GetHandleUnwrapMemory() { return handle_unwrap_memory_; }
    const VkRayTracingPipelineCreateInfoKHR*&             GetCreateInfosUnwrapped() { return create_infos_unwrapped_; }

  private:
    VkPipelineCache                          pipeline_cache_;
    uint32_t                                 create_info_count_;
    const VkRayTracingPipelineCreateInfoKHR* create_infos_;
    const VkAllocationCallbacks*             allocator_;
    VkPipeline*                              pipelines_;

    HandleUnwrapMemory                                   handle_unwrap_memory_;
    std::shared_ptr<VkRayTracingPipelineCreateInfoKHR> modified_create_infos_;
    const VkRayTracingPipelineCreateInfoKHR*             create_infos_unwrapped_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DEFERRED_OPERATION_CREATE_RAY_TRACING_PIPELINES_H
