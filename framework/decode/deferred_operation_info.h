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

#ifndef GFXRECON_DECODE_DEFERRED_OPERATION_INFO_H
#define GFXRECON_DECODE_DEFERRED_OPERATION_INFO_H

#include "generated/generated_vulkan_struct_decoders.h"
#include "decode/vulkan_object_info.h"
//#include "decode/vulkan_resource_allocator.h"
//#include "decode/vulkan_resource_initializer.h"
//#include "decode/window.h"
//#include "format/format.h"
//#include "generated/generated_vulkan_dispatch_table.h"
//#include "graphics/vulkan_device_util.h"
//#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DeferredOperationInfo
{
  public:
    DeferredOperationInfo(format::ApiCallId call_id) : api_call_id_(call_id), process_done_(false) {}
    ~DeferredOperationInfo() {}

    format::ApiCallId GetApiCallId() { return api_call_id_; }
    bool              IsProcessDone() { return process_done_; }
    void              ProcessDone() { process_done_ = true; }

  protected:
    format::ApiCallId api_call_id_;
    bool              process_done_;
};

class DeferredOperationInfoManager
{
  public:
    static std::unique_ptr<DeferredOperationInfoManager>& Get() { return instance_; }

    void add(format::HandleId deferred_operation_handle, std::unique_ptr<DeferredOperationInfo> operation)
    {
        if ((deferred_operation_handle != gfxrecon::format::kNullHandleId) && (operation))
        {
            deferred_operations_[deferred_operation_handle] = std::move(operation);
        }
    }

    std::unique_ptr<DeferredOperationInfo>& find(format::HandleId deferred_operation_handle)
    {
        if (deferred_operations_.find(deferred_operation_handle) != deferred_operations_.end())
        {
            return deferred_operations_[deferred_operation_handle];
        }
        else
        {
            return null_operation_;
        }
    }

    void Remove(format::HandleId deferred_operation_handle)
    {
        std::unique_ptr<DeferredOperationInfo> deferred_operation = std::move(find(deferred_operation_handle));
        deferred_operations_.erase(deferred_operation_handle);
    }

    DeferredOperationInfoManager() {}

    ~DeferredOperationInfoManager() {}

  protected:
    std::unordered_map<format::HandleId, std::unique_ptr<DeferredOperationInfo>> deferred_operations_;
    static std::unique_ptr<DeferredOperationInfoManager>                         instance_;
    std::unique_ptr<DeferredOperationInfo> null_operation_ = std::unique_ptr<DeferredOperationInfo>(nullptr);
};

class DeferredOperationInfoCreateRayTracingPipelines : public DeferredOperationInfo
{
  public:
    DeferredOperationInfoCreateRayTracingPipelines() :
        DeferredOperationInfo(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR)
    {}

    ~DeferredOperationInfoCreateRayTracingPipelines() {}

    format::HandleId& GetDeviceId() { return device_; }

    format::HandleId& GetDeferredOperationId() { return deferredOperation_; }

    format::HandleId& GetPipelineCacheId() { return pipelineCache_; }

    uint32_t& GetCreateInfoCount() { return createInfoCount_; }

    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>& GetCreateInfos() { return CreateInfos_; }

    StructPointerDecoder<Decoded_VkAllocationCallbacks>& GetAllocator() { return Allocator_; }

    HandlePointerDecoder<VkPipeline>& GetPipelines() { return Pipelines_; }

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
    SetModifiedGroups(std::unique_ptr<std::vector<std::vector<VkRayTracingShaderGroupCreateInfoKHR>>>& modified_pgroups)
    {
        modified_pgroups_ = std::move(modified_pgroups);
    }

    std::unique_ptr<std::vector<std::vector<VkRayTracingShaderGroupCreateInfoKHR>>>& GetModifiedGroups()
    {
        return modified_pgroups_;
    };

  private:
    format::HandleId                                                                device_;
    format::HandleId                                                                deferredOperation_;
    format::HandleId                                                                pipelineCache_;
    uint32_t                                                                        createInfoCount_;
    HandlePointerDecoder<VkPipeline>                                                Pipelines_;
    std::unique_ptr<std::vector<PipelineInfo>>                                      pipeline_handle_info_;
    StructPointerDecoder<Decoded_VkAllocationCallbacks>                             Allocator_;
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>                 CreateInfos_;
    std::unique_ptr<std::vector<VkRayTracingPipelineCreateInfoKHR>>                 modified_create_infos_;
    std::unique_ptr<std::vector<std::vector<VkRayTracingShaderGroupCreateInfoKHR>>> modified_pgroups_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DEFERRED_OPERATION_INFO_H
