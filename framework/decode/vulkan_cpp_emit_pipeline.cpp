//
// Copyright (c) 2020 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2023 LunarG, Inc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Shader modules, pipeline caches, and pipelines.
// This file holds part of VulkanCppConsumerBase.  See vulkan_cpp_consumer_base.h.

#include "decode/vulkan_cpp_consumer_base.h"
#include "decode/vulkan_cpp_template_strings.h"

#include PROJECT_VERSION_HEADER_FILE
#include "util/file_path.h"
#include "util/platform.h"
#include <util/hash.h>
#include "decode/vulkan_cpp_structs.h"
#include <generated/generated_vulkan_cpp_structs.h>
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "generated/generated_vulkan_enum_to_string.h"

#include <algorithm>
#include <cmath>
#include <iomanip>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
void VulkanCppConsumerBase::Generate_vkCreateShaderModule(args::CreateShaderModule& args)
{
    FILE* file = GetFrameFile();

    const VkShaderModuleCreateInfo* struct_info = args.pCreateInfo.GetPointer();

    // emit spirv data load.
    std::string         code_var_name = "pCode_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    const SavedFileInfo file_info =
        spv_saver_.AddFileContents((const uint8_t*)struct_info->pCode, struct_info->codeSize);

    fprintf(file, "\t{\n");

    fprintf(file, "\t\tuint8_t *%s = new uint8_t[%zu];\n\t", code_var_name.c_str(), struct_info->codeSize);
    GenerateLoadData(file_info.file_path, file_info.byte_offset, code_var_name, 0, struct_info->codeSize);

    std::string create_info_struct_name = "pCreateInfo_" + std::to_string(VulkanCppConsumerBase::GetNextId());

    std::stringstream out_struct;
    out_struct << "\t\tVkShaderModuleCreateInfo " << create_info_struct_name << " = {" << std::endl;
    out_struct << "\t\t" << util::ToString<VkStructureType>(struct_info->sType) << ", // sType" << std::endl;
    out_struct << "\t\t" << struct_info->pNext << ", // pNext" << std::endl;
    out_struct << "\t\t" << util::ToString<VkShaderModuleCreateFlags>(struct_info->flags) << ", // flags" << std::endl;
    out_struct << "\t\t" << struct_info->codeSize << ", // codeSize" << std::endl;
    out_struct << "\t\t(const uint32_t*)" << code_var_name << " // pCode" << std::endl;
    out_struct << "\t\t};" << std::endl;
    fprintf(file, "%s", out_struct.str().c_str());

    std::string shader_module_name = "pShaderModule_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    AddKnownVariables("VkShaderModule", shader_module_name, args.pShaderModule.GetPointer());

    if (args.result == VK_SUCCESS)
    {
        AddHandles(shader_module_name, args.pShaderModule.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateShaderModule(%s, &%s, %s, &%s), %s);\n",
            GetHandle(args.device).c_str(),
            create_info_struct_name.c_str(),
            "nullptr",
            shader_module_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());

    // emit delete the allocated spv data.
    fprintf(file, "\t\tdelete [] %s;\n\n", code_var_name.c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkCreatePipelineCache(args::CreatePipelineCache& args)
{
    FILE* file = GetFrameFile();

    const VkPipelineCacheCreateInfo* struct_info = args.pCreateInfo.GetPointer();

    fprintf(file, "\t{\n");
    std::string       create_info_struct_var_name = "pCreateInfo_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    std::stringstream stream_create_info;

    stream_create_info << "\t\tVkPipelineCacheCreateInfo " << create_info_struct_var_name << " {" << std::endl;
    stream_create_info << "\t\t" << util::ToString<VkStructureType>(struct_info->sType) << ", // sType" << std::endl;
    stream_create_info << "\t\t" << struct_info->pNext << ", // pNext" << std::endl;
    stream_create_info << "\t\t" << util::ToString<VkPipelineCacheCreateFlags>(struct_info->flags) << ", // flags"
                       << std::endl;
    stream_create_info << "\t\t0, // initialDataSize" << std::endl;
    stream_create_info << "\t\tNULL // pInitialData" << std::endl;
    stream_create_info << "\t\t};" << std::endl;
    fprintf(file, "\n%s", stream_create_info.str().c_str());

    std::string pipeline_cache_var_name = "pPipelineCache_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    AddKnownVariables("VkPipelineCache", pipeline_cache_var_name);

    if (args.result == VK_SUCCESS)
    {
        AddHandles(pipeline_cache_var_name, args.pPipelineCache.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreatePipelineCache(%s, &%s, %s, &%s), %s);\n",
            GetHandle(args.device).c_str(),
            create_info_struct_var_name.c_str(),
            "nullptr",
            pipeline_cache_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkCreateGraphicsPipelines(args::CreateGraphicsPipelines& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
    // device
    // pipelineCache
    // createInfoCount
    // pCreateInfos
    std::stringstream stream_create_infos;
    std::string       create_infos_array_variable = "NULL";
    PointerPairContainer<decltype(args.pCreateInfos.GetPointer()), decltype(args.pCreateInfos.GetMetaStructPointer())>
                create_infos_var_pair{ args.pCreateInfos.GetPointer(),
                               args.pCreateInfos.GetMetaStructPointer(),
                               args.createInfoCount };
    std::string create_info_var_name = toStringJoin(
        create_infos_var_pair.begin(),
        create_infos_var_pair.end(),
        [&](auto pair) {
            return GenerateStruct_VkGraphicsPipelineCreateInfo(stream_create_infos, pair.t1, pair.t2, *this);
        },
        ", ");
    fprintf(file, "\n%s", stream_create_infos.str().c_str());
    if (args.createInfoCount == 1)
    {
        create_infos_array_variable = "&" + create_info_var_name;
    }
    else if (args.createInfoCount > 1)
    {
        create_infos_array_variable = "pCreateInfos_" + std::to_string(this->GetNextId());
        fprintf(file,
                "VkGraphicsPipelineCreateInfo %s[] = { %s };\n",
                create_infos_array_variable.c_str(),
                create_info_var_name.c_str());
    }
    // pAllocator
    // pPipelines
    std::string pipeline_var_name = "pPipelines_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pipeline_var_name, args.pPipelines.GetPointer(), args.createInfoCount);
    if (args.result == VK_SUCCESS)
    {
        this->AddHandles(pipeline_var_name, args.pPipelines.GetPointer(), args.createInfoCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateGraphicsPipelines(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipelineCache).c_str(),
            args.createInfoCount,
            create_infos_array_variable.c_str(),
            "nullptr",
            pipeline_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "    }\n");
}

void VulkanCppConsumerBase::Generate_vkCreateRayTracingPipelinesKHR(args::CreateRayTracingPipelinesKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
    // device
    // pipelineCache
    // createInfoCount
    // pCreateInfos
    std::stringstream stream_create_infos;
    std::string       create_infos_array_variable = "NULL";
    PointerPairContainer<decltype(args.pCreateInfos.GetPointer()), decltype(args.pCreateInfos.GetMetaStructPointer())>
                create_infos_var_pair{ args.pCreateInfos.GetPointer(),
                               args.pCreateInfos.GetMetaStructPointer(),
                               args.createInfoCount };
    std::string create_info_var_name = toStringJoin(
        create_infos_var_pair.begin(),
        create_infos_var_pair.end(),
        [&](auto pair) {
            return GenerateStruct_VkRayTracingPipelineCreateInfoKHR(stream_create_infos, pair.t1, pair.t2, *this);
        },
        ", ");
    fprintf(file, "\n%s", stream_create_infos.str().c_str());
    if (args.createInfoCount == 1)
    {
        create_infos_array_variable = "&" + create_info_var_name;
    }
    else if (args.createInfoCount > 1)
    {
        create_infos_array_variable = "pCreateInfos_" + std::to_string(this->GetNextId());
        fprintf(file,
                "VkRayTracingPipelineCreateInfoKHR %s[] = { %s };\n",
                create_infos_array_variable.c_str(),
                create_info_var_name.c_str());
    }
    // pAllocator
    // pPipelines
    std::string pipeline_var_name = "pPipelines_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pipeline_var_name, args.pPipelines.GetPointer(), args.createInfoCount);
    if (args.result == VK_SUCCESS)
    {
        this->AddHandles(pipeline_var_name, args.pPipelines.GetPointer(), args.createInfoCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateRayTracingPipelinesKHR(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipelineCache).c_str(),
            args.createInfoCount,
            create_infos_array_variable.c_str(),
            "nullptr",
            pipeline_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "    }\n");
}

void VulkanCppConsumerBase::Generate_vkCreateComputePipelines(args::CreateComputePipelines& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
    // device
    // pipelineCache
    // createInfoCount
    // pCreateInfos
    std::stringstream stream_create_infos;
    std::string       create_infos_array_variable = "NULL";
    PointerPairContainer<decltype(args.pCreateInfos.GetPointer()), decltype(args.pCreateInfos.GetMetaStructPointer())>
                create_infos_var_pair{ args.pCreateInfos.GetPointer(),
                               args.pCreateInfos.GetMetaStructPointer(),
                               args.createInfoCount };
    std::string create_info_var_name = toStringJoin(
        create_infos_var_pair.begin(),
        create_infos_var_pair.end(),
        [&](auto pair) {
            return GenerateStruct_VkComputePipelineCreateInfo(stream_create_infos, pair.t1, pair.t2, *this);
        },
        ", ");
    fprintf(file, "\n%s", stream_create_infos.str().c_str());
    if (args.createInfoCount == 1)
    {
        create_infos_array_variable = "&" + create_info_var_name;
    }
    else if (args.createInfoCount > 1)
    {
        create_infos_array_variable = "pCreateInfos_" + std::to_string(this->GetNextId());
        fprintf(file,
                "VkComputePipelineCreateInfo %s[] = { %s };\n",
                create_infos_array_variable.c_str(),
                create_info_var_name.c_str());
    }
    // pAllocator
    // pPipelines
    std::string pipeline_var_name = "pPipelines_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pipeline_var_name, args.pPipelines.GetPointer(), args.createInfoCount);
    if (args.result == VK_SUCCESS)
    {
        this->AddHandles(pipeline_var_name, args.pPipelines.GetPointer(), args.createInfoCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateComputePipelines(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.pipelineCache).c_str(),
            args.createInfoCount,
            create_infos_array_variable.c_str(),
            "nullptr",
            pipeline_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "    }\n");
}

void VulkanCppConsumerBase::Process_vkCreateRayTracingPipelinesKHR(const ApiCallInfo&                  call_info,
                                                                   args::CreateRayTracingPipelinesKHR& args)
{
    Generate_vkCreateRayTracingPipelinesKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);
}

void VulkanCppConsumerBase::Process_vkDeferredOperationJoinKHR(const ApiCallInfo&              call_info,
                                                               args::DeferredOperationJoinKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // device
    // operation
    pfn_loader_.AddMethodName("vkDeferredOperationJoinKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkDeferredOperationJoinKHR(%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.operation).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
