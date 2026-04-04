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

void VulkanExportJsonConsumerBase::Initialize(JsonWriter* writer, const std::string_view vulkanVersion)
{
    GFXRECON_ASSERT(writer);
    writer_ = writer;

    writer->GetHeaderJson()["vulkan-version"] = std::string(vulkanVersion);
}

void VulkanExportJsonConsumerBase::Destroy()
{
    if (writer_)
    {
        writer_->Destroy();
    }
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
    const ApiCallInfo&                                                         call_info,
    format::HandleId                                                           commandBuffer,
    uint32_t                                                                   infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    PointerDecoder<VkDeviceAddress>*                                           pIndirectDeviceAddresses,
    PointerDecoder<uint32_t>*                                                  pIndirectStrides,
    PointerDecoder<uint32_t*>*                                                 ppMaxPrimitiveCounts)
{
    WriteApiCallToFile(call_info, "vkCmdBuildAccelerationStructuresIndirectKHR", [&](nlohmann::ordered_json& function) {
        function[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);

        auto& args = function[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["infoCount"] = infoCount;
        FieldToJson(args["pInfos"], pInfos);
        FieldToJson(args["pIndirectDeviceAddresses"], pIndirectDeviceAddresses);
        FieldToJson(args["pIndirectStrides"], pIndirectStrides);

        auto infos                     = pInfos ? pInfos->GetPointer() : nullptr;
        auto max_primitive_counts      = ppMaxPrimitiveCounts ? ppMaxPrimitiveCounts->GetPointer() : nullptr;
        auto max_primitive_counts_json = args["ppMaxPrimitiveCounts"];

        for (uint32_t i = 0; i < infoCount; ++i)
        {
            auto element = max_primitive_counts_json[i];
            FieldToJson(max_primitive_counts_json[i], max_primitive_counts[i], infos[i].geometryCount);
        }
    });
}

void VulkanExportJsonConsumerBase::Process_vkCreateShaderModule(
    const gfxrecon::decode::ApiCallInfo&                                                        call_info,
    VkResult                                                                                    returnValue,
    gfxrecon::format::HandleId                                                                  device,
    gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*    pAllocator,
    gfxrecon::decode::HandlePointerDecoder<VkShaderModule>*                                     pShaderModule)
{
    WriteApiCallToFile(call_info, "vkCreateShaderModule", [&](nlohmann::ordered_json& function) {
        function[NameReturn()] = returnValue;
        auto& args = function[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pShaderModule"], pShaderModule);

        const uint64_t handle_id     = *pShaderModule->GetPointer();
        auto           decoded_value = pCreateInfo->GetPointer();
        RepresentBinaryFile(*(this->writer_),
                            args["pCreateInfo"]["pCode"],
                            "shader_module_" + util::to_hex_fixed_width(handle_id) + ".bin",
                            decoded_value->codeSize,
                            (uint8_t*)decoded_value->pCode);
    });
}

void VulkanExportJsonConsumerBase::Process_vkGetPipelineCacheData(const ApiCallInfo&       call_info,
                                                                  VkResult                 returnValue,
                                                                  format::HandleId         device,
                                                                  format::HandleId         pipelineCache,
                                                                  PointerDecoder<size_t>*  pDataSize,
                                                                  PointerDecoder<uint8_t>* pData)
{
    WriteApiCallToFile(call_info, "vkGetPipelineCacheData", [&](nlohmann::ordered_json& function) {
        function[NameReturn()] = returnValue;
        auto& args = function[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipelineCache"], pipelineCache);
        FieldToJson(args["pDataSize"], pDataSize);
        if (pData->IsNull())
        {
            args["pData"] = nullptr;
        }
        else
        {
            RepresentBinaryFile(
                *(this->writer_), args["pData"], "pipeline_cache_data.bin", pData->GetLength(), pData->GetPointer());
        }
    });
}

void VulkanExportJsonConsumerBase::Process_vkCreatePipelineCache(
    const ApiCallInfo&                                       call_info,
    VkResult                                                 returnValue,
    format::HandleId                                         device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkPipelineCache>*                   pPipelineCache)
{
    WriteApiCallToFile(call_info, "vkCreatePipelineCache", [&](nlohmann::ordered_json& function) {
        function[NameReturn()] = returnValue;
        auto& args = function[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pPipelineCache"], pPipelineCache);
        RepresentBinaryFile(*(this->writer_),
                            args["pCreateInfo"]["pInitialData"],
                            "pipeline_cache_data.bin",
                            pCreateInfo->GetPointer()->initialDataSize,
                            reinterpret_cast<const uint8_t*>(pCreateInfo->GetPointer()->pInitialData));
    });
}

void VulkanExportJsonConsumerBase::Process_vkCmdPushConstants(const ApiCallInfo&       call_info,
                                                              format::HandleId         commandBuffer,
                                                              format::HandleId         layout,
                                                              VkShaderStageFlags       stageFlags,
                                                              uint32_t                 offset,
                                                              uint32_t                 size,
                                                              PointerDecoder<uint8_t>* pValues)
{
    WriteApiCallToFile(call_info, "vkCmdPushConstants", [&](nlohmann::ordered_json& function) {
        function[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
        auto& args = function[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["layout"], layout);
        args["stageFlags"] = VkShaderStageFlags_t{ stageFlags };
        args["offset"]     = offset;
        args["size"]       = size;
        FieldToJson(args["pValues"], pValues);
        if (pValues->IsNull())
        {
            args["pValues"] = nullptr;
        }
        else
        {
            RepresentBinaryFile(
                *(this->writer_), args["pValues"], "pushconstants.bin", pValues->GetLength(), pValues->GetPointer());
        }
    });
}

void VulkanExportJsonConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo& call_info,
                                                                             format::HandleId   device,
                                                                             format::HandleId   descriptorSet,
                                                                             format::HandleId descriptorUpdateTemplate,
                                                                             DescriptorUpdateTemplateDecoder* pData,
                                                                             bool use_KHR_suffix)
{
    const char* function_name =
        use_KHR_suffix ? "vkUpdateDescriptorSetWithTemplateKHR" : "vkUpdateDescriptorSetWithTemplate";
    auto& function = WriteApiCallStart(call_info, function_name);
    auto& args     = function[NameArgs()];

    HandleToJson(args["device"], device);
    HandleToJson(args["descriptorSet"], descriptorSet);
    HandleToJson(args["descriptorUpdateTemplate"], descriptorUpdateTemplate);
    FieldToJson(args["pData"], pData);

    WriteBlockEnd();
}

void VulkanExportJsonConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    const ApiCallInfo&               call_info,
    format::HandleId                 commandBuffer,
    format::HandleId                 descriptorUpdateTemplate,
    format::HandleId                 layout,
    uint32_t                         set,
    DescriptorUpdateTemplateDecoder* pData)
{
    auto& function = WriteApiCallStart(call_info, "vkCmdPushDescriptorSetWithTemplateKHR");
    function[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);

    auto& args = function[NameArgs()];
    HandleToJson(args["commandBuffer"], commandBuffer);
    HandleToJson(args["descriptorUpdateTemplate"], descriptorUpdateTemplate);
    HandleToJson(args["layout"], layout);
    args["set"] = set;
    FieldToJson(args["pData"], pData);

    WriteBlockEnd();
}

void VulkanExportJsonConsumerBase::Process_vkCmdPushDescriptorSetWithTemplate2KHR(
    const ApiCallInfo&                                                 call_info,
    format::HandleId                                                   commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfo>* pPushDescriptorSetWithTemplateInfo)
{
    auto& function = WriteApiCallStart(call_info, "vkCmdPushDescriptorSetWithTemplate2KHR");
    function[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);

    auto&                                                                    args = function[NameArgs()];
    const StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfo>* info = pPushDescriptorSetWithTemplateInfo;
    HandleToJson(args["commandBuffer"], commandBuffer);
    FieldToJson(args["pPushDescriptorSetWithTemplateInfo"], info);

    WriteBlockEnd();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
