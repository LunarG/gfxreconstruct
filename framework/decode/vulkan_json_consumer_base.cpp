/*
** Copyright (c) 2022-2023 LunarG, Inc.
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

#include "decode/vulkan_json_consumer_base.h"
#include "decode/custom_vulkan_struct_to_json.h"

#include "generated/generated_vulkan_enum_to_json.h"

#include "util/json_util.h"
#include "util/platform.h"
#include "util/file_path.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using namespace util::platform;
using util::FieldToJson;
using util::HandleToJson;

VulkanExportJsonConsumerBase::VulkanExportJsonConsumerBase() {}

VulkanExportJsonConsumerBase::~VulkanExportJsonConsumerBase()
{
    Destroy();
}

void VulkanExportJsonConsumerBase::Initialize(JsonWriter* writer)
{
    GFXRECON_ASSERT(writer);
    writer_ = writer;

    writer->GetHeaderJson()["vulkan-version"] = std::to_string(VK_API_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                                std::to_string(VK_API_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                                std::to_string(VK_API_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
}

void VulkanExportJsonConsumerBase::Destroy()
{
    writer_ = nullptr;
}

std::string VulkanExportJsonConsumerBase::GenerateFilename(const std::string& filename)
{
    return writer_->GenerateFilename(filename);
}

bool VulkanExportJsonConsumerBase::WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data)
{
    return writer_->WriteBinaryFile(filename, data_size, data);
}

void VulkanExportJsonConsumerBase::ProcessSetDeviceMemoryPropertiesCommand(
    format::HandleId                             physical_device_id,
    const std::vector<format::DeviceMemoryType>& memory_types,
    const std::vector<format::DeviceMemoryHeap>& memory_heaps)
{
    writer_->SetCurrentBlockIndex(block_index_);
    auto& jdata = writer_->WriteMetaCommandStart("SetDeviceMemoryPropertiesCommand");

    HandleToJson(jdata["physical_device_id"], physical_device_id);
    FieldToJson(jdata["memory_types"], memory_types);
    FieldToJson(jdata["memory_heaps"], memory_heaps);

    WriteBlockEnd();
}

void VulkanExportJsonConsumerBase::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo& call_info, args::CmdBuildAccelerationStructuresIndirectKHR& args)

{
    WriteApiCallToFile(call_info, "vkCmdBuildAccelerationStructuresIndirectKHR", [&](nlohmann::ordered_json& function) {
        function[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);

        auto& jargs = function[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["infoCount"] = args.infoCount;
        FieldToJson(jargs["pInfos"], &args.pInfos);
        FieldToJson(jargs["pIndirectDeviceAddresses"], &args.pIndirectDeviceAddresses);
        FieldToJson(jargs["pIndirectStrides"], &args.pIndirectStrides);

        auto infos                     = args.pInfos.GetPointer();
        auto max_primitive_counts      = args.ppMaxPrimitiveCounts.GetPointer();
        auto max_primitive_counts_json = jargs["ppMaxPrimitiveCounts"];

        for (uint32_t i = 0; i < args.infoCount; ++i)
        {
            auto element = max_primitive_counts_json[i];
            FieldToJson(max_primitive_counts_json[i], max_primitive_counts[i], infos[i].geometryCount);
        }
    });
}

void VulkanExportJsonConsumerBase::Process_vkCreateShaderModule(const gfxrecon::decode::ApiCallInfo& call_info,
                                                                args::CreateShaderModule&            args)
{
    WriteApiCallToFile(call_info, "vkCreateShaderModule", [&](nlohmann::ordered_json& function) {
        function[format::kNameReturn] = args.result;
        auto& jargs                   = function[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pShaderModule"], &args.pShaderModule);

        const uint64_t handle_id     = *args.pShaderModule.GetPointer();
        auto           decoded_value = args.pCreateInfo.GetPointer();
        RepresentBinaryFile(*(this->writer_),
                            jargs["pCreateInfo"]["pCode"],
                            "shader_module_" + util::to_hex_fixed_width(handle_id) + ".bin",
                            decoded_value->codeSize,
                            (uint8_t*)decoded_value->pCode);
    });
}

void VulkanExportJsonConsumerBase::Process_vkGetPipelineCacheData(const ApiCallInfo&          call_info,
                                                                  args::GetPipelineCacheData& args)
{
    WriteApiCallToFile(call_info, "vkGetPipelineCacheData", [&](nlohmann::ordered_json& function) {
        function[format::kNameReturn] = args.result;
        auto& jargs                   = function[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipelineCache"], args.pipelineCache);
        FieldToJson(jargs["pDataSize"], args.pDataSize);
        if (args.pData.IsNull())
        {
            jargs["pData"] = nullptr;
        }
        else
        {
            RepresentBinaryFile(*(this->writer_),
                                jargs["pData"],
                                "pipeline_cache_data.bin",
                                args.pData.GetLength(),
                                args.pData.GetPointer());
        }
    });
}

void VulkanExportJsonConsumerBase::Process_vkCreatePipelineCache(const ApiCallInfo&         call_info,
                                                                 args::CreatePipelineCache& args)
{
    WriteApiCallToFile(call_info, "vkCreatePipelineCache", [&](nlohmann::ordered_json& function) {
        function[format::kNameReturn] = args.result;
        auto& jargs                   = function[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pPipelineCache"], &args.pPipelineCache);
        RepresentBinaryFile(*(this->writer_),
                            jargs["pCreateInfo"]["pInitialData"],
                            "pipeline_cache_data.bin",
                            args.pCreateInfo.GetPointer()->initialDataSize,
                            reinterpret_cast<const uint8_t*>(args.pCreateInfo.GetPointer()->pInitialData));
    });
}

void VulkanExportJsonConsumerBase::Process_vkCmdPushConstants(const ApiCallInfo&      call_info,
                                                              args::CmdPushConstants& args)
{
    WriteApiCallToFile(call_info, "vkCmdPushConstants", [&](nlohmann::ordered_json& function) {
        function[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
        auto& jargs                         = function[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["layout"], args.layout);
        jargs["stageFlags"] = VkShaderStageFlags_t{ args.stageFlags };
        jargs["offset"]     = args.offset;
        jargs["size"]       = args.size;
        FieldToJson(jargs["pValues"], &args.pValues);
        if (args.pValues.IsNull())
        {
            jargs["pValues"] = nullptr;
        }
        else
        {
            RepresentBinaryFile(*(this->writer_),
                                jargs["pValues"],
                                "pushconstants.bin",
                                args.pValues.GetLength(),
                                args.pValues.GetPointer());
        }
    });
}

void VulkanExportJsonConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(
    const ApiCallInfo& call_info, args::UpdateDescriptorSetWithTemplate& args)
{
    auto& function = WriteApiCallStart(call_info, "vkUpdateDescriptorSetWithTemplate");
    auto& jargs    = function[format::kNameArgs];

    HandleToJson(jargs["device"], args.device);
    HandleToJson(jargs["descriptorSet"], args.descriptorSet);
    HandleToJson(jargs["descriptorUpdateTemplate"], args.descriptorUpdateTemplate);
    FieldToJson(jargs["pData"], &args.pData);

    WriteBlockEnd();
}

void VulkanExportJsonConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    const ApiCallInfo& call_info, args::UpdateDescriptorSetWithTemplateKHR& args)
{
    auto& function = WriteApiCallStart(call_info, "vkUpdateDescriptorSetWithTemplateKHR");
    auto& jargs    = function[format::kNameArgs];

    HandleToJson(jargs["device"], args.device);
    HandleToJson(jargs["descriptorSet"], args.descriptorSet);
    HandleToJson(jargs["descriptorUpdateTemplate"], args.descriptorUpdateTemplate);
    FieldToJson(jargs["pData"], &args.pData);

    WriteBlockEnd();
}

void VulkanExportJsonConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    const ApiCallInfo& call_info, args::CmdPushDescriptorSetWithTemplateKHR& args)
{
    auto& function                      = WriteApiCallStart(call_info, "vkCmdPushDescriptorSetWithTemplateKHR");
    function[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);

    auto& jargs = function[format::kNameArgs];
    HandleToJson(jargs["commandBuffer"], args.commandBuffer);
    HandleToJson(jargs["descriptorUpdateTemplate"], args.descriptorUpdateTemplate);
    HandleToJson(jargs["layout"], args.layout);
    jargs["set"] = args.set;
    FieldToJson(jargs["pData"], &args.pData);

    WriteBlockEnd();
}

void VulkanExportJsonConsumerBase::Process_vkCmdPushDescriptorSetWithTemplate2KHR(
    const ApiCallInfo& call_info, args::CmdPushDescriptorSetWithTemplate2KHR& args)
{
    auto& function                      = WriteApiCallStart(call_info, "vkCmdPushDescriptorSetWithTemplate2KHR");
    function[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);

    auto& jargs = function[format::kNameArgs];
    HandleToJson(jargs["commandBuffer"], args.commandBuffer);
    FieldToJson(jargs["pPushDescriptorSetWithTemplateInfo"], &args.pPushDescriptorSetWithTemplateInfo);

    WriteBlockEnd();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
