/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved**
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
