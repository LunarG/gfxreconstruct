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
    DeferredOperationInfo. Because different API call as deferred operation
    will need to store different related variables, so here the class
    DeferredOperationInfo is a parent class, class for specific API need
    to be derived from DeferredOperationInfo, for example, the derived class
    DeferredOperationInfoCreateRayTracingPipelines is used for API
    vkCreateRayTracingPipelines.
*/
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
            // The return of this function is a reference. If changed to nullptr
            // , a std::unique_ptr instance will be initialized with nullptr in
            // the function, the instance's reference will be return. But the
            // instance will be destroyed when the function end. So caller get
            // a reference of destroyed instance. This is the reason we use
            // null_operation_ here.
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

#endif // GFXRECON_DECODE_DEFERRED_OPERATION_INFO_H
