/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DEFERRED_OPERATION_INFO_CREATE_RAY_TRACING_PIPELINES_H
#define GFXRECON_DECODE_DEFERRED_OPERATION_INFO_CREATE_RAY_TRACING_PIPELINES_H

#include "generated/generated_vulkan_struct_decoders.h"
#include "decode/vulkan_object_info.h"
#include "decode/deferred_operation_info.h"

#include "vulkan/vulkan.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DeferredOperationInfoCreateRayTracingPipelines : public DeferredOperationInfo
{
  public:
    DeferredOperationInfoCreateRayTracingPipelines() :
        DeferredOperationInfo(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR)
    {}

    ~DeferredOperationInfoCreateRayTracingPipelines() {}

    format::HandleId& GetDeviceId() { return device_; }

    format::HandleId& GetDeferredOperationId() { return deferred_operation_; }

    format::HandleId& GetPipelineCacheId() { return pipeline_cache_; }

    uint32_t& GetCreateInfoCount() { return create_info_count_; }

    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>& GetCreateInfos() { return create_infos_; }

    StructPointerDecoder<Decoded_VkAllocationCallbacks>& GetAllocator() { return allocator_; }

    HandlePointerDecoder<VkPipeline>& GetPipelines() { return pipelines_; }

    void SetPipelineHandleInfo(std::unique_ptr<std::vector<PipelineInfo>>& pipeline_infos)
    {
        pipeline_handle_info_ = std::move(pipeline_infos);
    }

    std::unique_ptr<std::vector<PipelineInfo>>& GetPipelineHandleInfo() { return pipeline_handle_info_; }

    void SetModifiedCreateInfos(std::unique_ptr<std::vector<VkRayTracingPipelineCreateInfoKHR>>& modified_create_infos)
    {
        modified_create_infos_ = std::move(modified_create_infos);
    }

    std::unique_ptr<std::vector<VkRayTracingPipelineCreateInfoKHR>>& GetModifiedCreateInfos()
    {
        return modified_create_infos_;
    }

    void
    SetModifiedGroups(std::unique_ptr<std::vector<std::vector<VkRayTracingShaderGroupCreateInfoKHR>>>& modified_groups)
    {
        modified_groups_ = std::move(modified_groups);
    }

    std::unique_ptr<std::vector<std::vector<VkRayTracingShaderGroupCreateInfoKHR>>>& GetModifiedGroups()
    {
        return modified_groups_;
    };

  private:
    format::HandleId                                                                device_;
    format::HandleId                                                                deferred_operation_;
    format::HandleId                                                                pipeline_cache_;
    uint32_t                                                                        create_info_count_;
    HandlePointerDecoder<VkPipeline>                                                pipelines_;
    std::unique_ptr<std::vector<PipelineInfo>>                                      pipeline_handle_info_;
    StructPointerDecoder<Decoded_VkAllocationCallbacks>                             allocator_;
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>                 create_infos_;
    std::unique_ptr<std::vector<VkRayTracingPipelineCreateInfoKHR>>                 modified_create_infos_;
    std::unique_ptr<std::vector<std::vector<VkRayTracingShaderGroupCreateInfoKHR>>> modified_groups_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DEFERRED_OPERATION_INFO_CREATE_RAY_TRACING_PIPELINES_H
