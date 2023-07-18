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

#include "util/json_util.h"
#include "util/platform.h"
#include "util/file_path.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
using namespace util::platform;

namespace
{
/// @brief Convert an annotation to its string representation
/// @note This should be moved into util/to_string.h/cpp after the existing
/// code there that is tied to the deprecated toJSON paths is eliminated.
std::string AnnotationTypeToString(const format::AnnotationType& type)
{
    std::string str;
    switch (type)
    {
        case format::AnnotationType::kUnknown:
            str.assign("kUnknown");
            break;
        case format::AnnotationType::kText:
            str.assign("kText");
            break;
        case format::AnnotationType::kJson:
            str.assign("kJson");
            break;
        case format::AnnotationType::kXml:
            str.assign("kXml");
            break;
        default:
            str.assign("OUT_OF_RANGE_ERROR");
            GFXRECON_LOG_WARNING("format::AnnotationType with out of range value: %lu",
                                 static_cast<long unsigned>(type));
            break;
    }
    return str;
}
} // namespace

VulkanExportJsonConsumerBase::VulkanExportJsonConsumerBase() {}

VulkanExportJsonConsumerBase::~VulkanExportJsonConsumerBase()
{
    Destroy();
}

void VulkanExportJsonConsumerBase::Initialize(JsonWriter* writer, const std::string_view vulkanVersion)
{
    GFXRECON_ASSERT(writer);
    writer_ = writer;

    writer->GetHeaderkJson()["vulkan-version"] = std::string(vulkanVersion);
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
    num_files_++;
    return std::to_string(num_files_) + "_" + filename;
}

bool VulkanExportJsonConsumerBase::WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data)
{
    FILE* file_output = nullptr;
    if (util::platform::FileOpen(&file_output, filename.c_str(), "wb") == 0)
    {
        util::platform::FileWrite(data, static_cast<size_t>(data_size), 1, file_output);
        util::platform::FileClose(file_output);
        return true;
    }
    return false;
}

void VulkanExportJsonConsumerBase::ProcessStateBeginMarker(uint64_t frame_number)
{
    WriteStateMarkerToFile("BeginMarker", frame_number);
}

void VulkanExportJsonConsumerBase::ProcessStateEndMarker(uint64_t frame_number)
{
    WriteStateMarkerToFile("EndMarker", frame_number);
}

void VulkanExportJsonConsumerBase::ProcessFrameEndMarker(uint64_t frame_number)
{
    WriteFrameMarkerToFile("EndMarker", frame_number);
}

void VulkanExportJsonConsumerBase::ProcessDisplayMessageCommand(const std::string& message)
{
    WriteMetaCommandToFile("DisplayMessageCommand",
                           [&](auto& jdata) { FieldToJson(jdata["message"], message, GetJsonOptions()); });
}

void VulkanExportJsonConsumerBase::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                            uint64_t       offset,
                                                            uint64_t       size,
                                                            const uint8_t* data)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("FillMemoryCommand", [&](auto& jdata) {
        HandleToJson(jdata["memory_id"], memory_id, json_options);
        FieldToJson(jdata["offset"], offset, json_options);
        FieldToJson(jdata["size"], size, json_options);
        if (json_options.dump_binaries)
        {
            std::string filename = GenerateFilename("fill_memory.bin");
            std::string basename = gfxrecon::util::filepath::Join(json_options.data_sub_dir, filename);
            std::string filepath = gfxrecon::util::filepath::Join(json_options.root_dir, basename);
            if (WriteBinaryFile(filepath, size, data))
            {
                FieldToJson(jdata["data"], basename, json_options);
            }
            else
            {
                FieldToJson(jdata["data"], "Unable to write file", json_options);
            }
        }
        else
        {
            FieldToJson(jdata["data"], "[Binary data]", json_options);
        }
    });
}

void VulkanExportJsonConsumerBase::ProcessResizeWindowCommand(format::HandleId surface_id,
                                                              uint32_t         width,
                                                              uint32_t         height)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("ResizeWindowCommand", [&](auto& jdata) {
        HandleToJson(jdata["surface_id"], surface_id, json_options);
        FieldToJson(jdata["width"], width, json_options);
        FieldToJson(jdata["height"], height, json_options);
    });
}

void VulkanExportJsonConsumerBase::ProcessResizeWindowCommand2(format::HandleId surface_id,
                                                               uint32_t         width,
                                                               uint32_t         height,
                                                               uint32_t         pre_transform)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("ResizeWindowCommand2", [&](auto& jdata) {
        HandleToJson(jdata["surface_id"], surface_id, json_options);
        FieldToJson(jdata["width"], width, json_options);
        FieldToJson(jdata["height"], height, json_options);
        FieldToJson(jdata["pre_transform"], pre_transform, json_options);
    });
}

void VulkanExportJsonConsumerBase::ProcessCreateHardwareBufferCommand(
    format::HandleId                                    memory_id,
    uint64_t                                            buffer_id,
    uint32_t                                            format,
    uint32_t                                            width,
    uint32_t                                            height,
    uint32_t                                            stride,
    uint64_t                                            usage,
    uint32_t                                            layers,
    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("CreateHardwareBufferCommand", [&](auto& jdata) {
        HandleToJson(jdata["memory_id"], memory_id, json_options);
        HandleToJson(jdata["buffer_id"], buffer_id, json_options);
        FieldToJson(jdata["format"], format, json_options);
        FieldToJson(jdata["width"], width, json_options);
        FieldToJson(jdata["height"], height, json_options);
        FieldToJson(jdata["stride"], stride, json_options);
        FieldToJson(jdata["usage"], usage, json_options);
        FieldToJson(jdata["layers"], layers, json_options);
    });
}

void VulkanExportJsonConsumerBase::ProcessDestroyHardwareBufferCommand(uint64_t buffer_id)
{
    WriteMetaCommandToFile("DestroyHardwareBufferCommand",
                           [&](auto& jdata) { HandleToJson(jdata["buffer_id"], buffer_id, GetJsonOptions()); });
}

void VulkanExportJsonConsumerBase::ProcessSetDevicePropertiesCommand(
    format::HandleId   physical_device_id,
    uint32_t           api_version,
    uint32_t           driver_version,
    uint32_t           vendor_id,
    uint32_t           device_id,
    uint32_t           device_type,
    const uint8_t      pipeline_cache_uuid[format::kUuidSize],
    const std::string& device_name)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("SetDevicePropertiesCommand", [&](auto& jdata) {
        HandleToJson(jdata["physical_device_id"], physical_device_id, json_options);
        FieldToJson(jdata["api_version"], api_version, json_options);
        FieldToJson(jdata["driver_version"], driver_version, json_options);
        FieldToJson(jdata["vendor_id"], vendor_id, json_options);
        FieldToJson(jdata["device_id"], device_id, json_options);
        FieldToJson(jdata["device_type"], device_type, json_options);
        FieldToJson(jdata["pipeline_cache_uuid"], uuid_to_string(format::kUuidSize, pipeline_cache_uuid), json_options);
        FieldToJson(jdata["device_name"], device_name, json_options);
    });
}

void VulkanExportJsonConsumerBase::ProcessSetDeviceMemoryPropertiesCommand(
    format::HandleId                             physical_device_id,
    const std::vector<format::DeviceMemoryType>& memory_types,
    const std::vector<format::DeviceMemoryHeap>& memory_heaps)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("SetDeviceMemoryPropertiesCommand", [&](auto& jdata) {
        HandleToJson(jdata["physical_device_id"], physical_device_id, json_options);
    });
}

void VulkanExportJsonConsumerBase::ProcessSetOpaqueAddressCommand(format::HandleId device_id,
                                                                  format::HandleId object_id,
                                                                  uint64_t         address)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("SetOpaqueAddressCommand", [&](auto& jdata) {
        HandleToJson(jdata["device_id"], device_id, json_options);
        HandleToJson(jdata["object_id"], object_id, json_options);
        FieldToJson(jdata["address"], to_hex_variable_width(address), json_options);
    });
}

void VulkanExportJsonConsumerBase::ProcessSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                                                 format::HandleId pipeline_id,
                                                                                 size_t           data_size,
                                                                                 const uint8_t*   data)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("SetRayTracingShaderGroupHandleCommand", [&](auto& jdata) {
        HandleToJson(jdata["device_id"], device_id, json_options);
        HandleToJson(jdata["pipeline_id"], pipeline_id, json_options);
        FieldToJson(jdata["data_size"], data_size, json_options);
        if (json_options.dump_binaries)
        {
            std::string filename = GenerateFilename("set_raytracing_shader_group_handle.bin");
            std::string basename = gfxrecon::util::filepath::Join(json_options.data_sub_dir, filename);
            std::string filepath = gfxrecon::util::filepath::Join(json_options.root_dir, basename);
            if (WriteBinaryFile(filepath, data_size, data))
            {
                FieldToJson(jdata["data"], basename, json_options);
            }
            else
            {
                FieldToJson(jdata["data"], "Unable to write file", json_options);
            }
        }
        else
        {
            FieldToJson(jdata["data"], "[Binary data]", json_options);
        }
    });
}

void VulkanExportJsonConsumerBase::ProcessSetSwapchainImageStateCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_state)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("SetSwapchainImageStateCommand", [&](auto& jdata) {
        HandleToJson(jdata["device_id"], device_id, json_options);
        HandleToJson(jdata["swapchain_id"], swapchain_id, json_options);
        FieldToJson(jdata["last_presented_image"], last_presented_image, json_options);
        FieldToJson(jdata["image_state"], "not available", json_options);
    });
}

void VulkanExportJsonConsumerBase::ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                                   uint64_t         max_resource_size,
                                                                   uint64_t         max_copy_size)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("BeginResourceInitCommand", [&](auto& jdata) {
        HandleToJson(jdata["device_id"], device_id, json_options);
        FieldToJson(jdata["max_resource_size"], max_resource_size, json_options);
        FieldToJson(jdata["max_copy_size"], max_copy_size, json_options);
    });
}

void VulkanExportJsonConsumerBase::ProcessEndResourceInitCommand(format::HandleId device_id)
{
    WriteMetaCommandToFile("EndResourceInitCommand",
                           [&](auto& jdata) { HandleToJson(jdata["device_id"], device_id, GetJsonOptions()); });
}

void VulkanExportJsonConsumerBase::ProcessInitBufferCommand(format::HandleId device_id,
                                                            format::HandleId buffer_id,
                                                            uint64_t         data_size,
                                                            const uint8_t*   data)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("InitBufferCommand", [&](auto& jdata) {
        HandleToJson(jdata["device_id"], device_id, json_options);
        HandleToJson(jdata["buffer_id"], buffer_id, json_options);
        FieldToJson(jdata["data_size"], data_size, json_options);
        if (json_options.dump_binaries)
        {
            std::string filename = GenerateFilename("init_buffer.bin");
            std::string basename = gfxrecon::util::filepath::Join(json_options.data_sub_dir, filename);
            std::string filepath = gfxrecon::util::filepath::Join(json_options.root_dir, basename);
            if (WriteBinaryFile(filepath, data_size, data))
            {
                FieldToJson(jdata["data"], basename, json_options);
            }
            else
            {
                FieldToJson(jdata["data"], "Unable to write file", json_options);
            }
        }
        else
        {
            FieldToJson(jdata["data"], "[Binary data]", json_options);
        }
    });
}

void VulkanExportJsonConsumerBase::ProcessInitImageCommand(format::HandleId             device_id,
                                                           format::HandleId             image_id,
                                                           uint64_t                     data_size,
                                                           uint32_t                     aspect,
                                                           uint32_t                     layout,
                                                           const std::vector<uint64_t>& level_sizes,
                                                           const uint8_t*               data)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteMetaCommandToFile("InitImageCommand", [&](auto& jdata) {
        HandleToJson(jdata["device_id"], device_id, json_options);
        HandleToJson(jdata["image_id"], image_id, json_options);
        FieldToJson(jdata["data_size"], data_size, json_options);
        FieldToJson(jdata["aspect"], aspect, json_options);
        FieldToJson(jdata["layout"], layout, json_options);
        FieldToJson(jdata["level_sizez"], "not available", json_options); /// @todo Typo: level_sizes

        if (json_options.dump_binaries)
        {
            std::string filename = GenerateFilename("init_image.bin");
            std::string basename = gfxrecon::util::filepath::Join(json_options.data_sub_dir, filename);
            std::string filepath = gfxrecon::util::filepath::Join(json_options.root_dir, basename);
            if (WriteBinaryFile(filepath, data_size, data))
            {
                FieldToJson(jdata["data"], basename, json_options);
            }
            else
            {
                FieldToJson(jdata["data"], "Unable to write file", json_options);
            }
        }
        else
        {
            FieldToJson(jdata["data"], "[Binary data]", json_options);
        }
    });
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
    const JsonOptions& json_options = GetJsonOptions();
    WriteApiCallToFile(call_info, "vkCmdBuildAccelerationStructuresIndirectKHR", [&](nlohmann::ordered_json& function) {
        auto& args = function[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["infoCount"], infoCount, json_options);
        FieldToJson(args["pInfos"], pInfos, json_options);
        FieldToJson(args["pIndirectDeviceAddresses"], pIndirectDeviceAddresses, json_options);
        FieldToJson(args["pIndirectStrides"], pIndirectStrides, json_options);

        auto infos                     = pInfos ? pInfos->GetPointer() : nullptr;
        auto max_primitive_counts      = ppMaxPrimitiveCounts ? ppMaxPrimitiveCounts->GetPointer() : nullptr;
        auto max_primitive_counts_json = args["ppMaxPrimitiveCounts"];

        for (uint32_t i = 0; i < infoCount; ++i)
        {
            auto element = max_primitive_counts_json[i];
            FieldToJson(max_primitive_counts_json[i], max_primitive_counts[i], infos[i].geometryCount, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    WriteApiCallToFile(call_info, "vkCreateShaderModule", [&](nlohmann::ordered_json& function) {
        FieldToJson(function[NameReturn()], returnValue, json_options);
        auto& args = function[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pShaderModule"], pShaderModule, json_options);

        if (json_options.dump_binaries)
        {
            uint64_t    handle_id     = *pShaderModule->GetPointer();
            std::string filename      = GenerateFilename("shader_module_" + to_hex_fixed_width(handle_id) + ".bin");
            std::string basename      = gfxrecon::util::filepath::Join(json_options.data_sub_dir, filename);
            std::string filepath      = gfxrecon::util::filepath::Join(json_options.root_dir, basename);
            auto        decoded_value = pCreateInfo->GetPointer();

            if (WriteBinaryFile(filepath, decoded_value->codeSize, (uint8_t*)decoded_value->pCode))
            {
                args["pCreateInfo"]["pCode"] = basename;
            }
            else
            {
                args["pCreateInfo"]["pCode"] = "Unable to create file";
            }
        }
    });
}

void VulkanExportJsonConsumerBase::Process_vkGetPipelineCacheData(const ApiCallInfo&       call_info,
                                                                  VkResult                 returnValue,
                                                                  format::HandleId         device,
                                                                  format::HandleId         pipelineCache,
                                                                  PointerDecoder<size_t>*  pDataSize,
                                                                  PointerDecoder<uint8_t>* pData)
{
    const JsonOptions& json_options = GetJsonOptions();
    WriteApiCallToFile(call_info, "vkGetPipelineCacheData", [&](nlohmann::ordered_json& function) {
        FieldToJson(function[NameReturn()], returnValue, json_options);
        auto& args = function[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options);
        FieldToJson(args["pDataSize"], pDataSize, json_options);
        if (pData->IsNull())
        {
            args["pData"] = nullptr;
        }
        else if (json_options.dump_binaries)
        {
            auto        decoded_data = pData->GetPointer();
            auto        data_size    = pData->GetLength();
            std::string filename     = GenerateFilename("pipeline_cache_data.bin");
            std::string basename     = gfxrecon::util::filepath::Join(json_options.data_sub_dir, filename);
            std::string filepath     = gfxrecon::util::filepath::Join(json_options.root_dir, basename);
            if (WriteBinaryFile(filepath, data_size, decoded_data))
            {
                FieldToJson(args["pData"], basename, json_options);
            }
            else
            {
                FieldToJson(args["pData"], "Unable to write file", json_options);
            }
        }
        else
        {
            FieldToJson(args["pData"], "[Binary data]", json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    WriteApiCallToFile(call_info, "vkCreatePipelineCache", [&](nlohmann::ordered_json& function) {
        FieldToJson(function[NameReturn()], returnValue, json_options);
        auto& args = function[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pPipelineCache"], pPipelineCache, json_options);
        if (json_options.dump_binaries)
        {
            auto        decoded_data = pCreateInfo->GetPointer();
            std::string filename     = GenerateFilename("pipeilne_cache_data.bin"); /// @todo Typo
            std::string basename     = gfxrecon::util::filepath::Join(json_options.data_sub_dir, filename);
            std::string filepath     = gfxrecon::util::filepath::Join(json_options.root_dir, basename);
            if (WriteBinaryFile(filepath, decoded_data->initialDataSize, (uint8_t*)decoded_data->pInitialData))
            {
                FieldToJson(args["pCreateInfo"]["pInitialData"], basename, json_options);
            }
            else
            {
                FieldToJson(args["pCreateInfo"]["pInitialData"], "Unable to write file", json_options);
            }
        }
        else
        {
            FieldToJson(args["pData"], "[Binary data]", json_options);
        }
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
    const JsonOptions& json_options = GetJsonOptions();
    WriteApiCallToFile(call_info, "vkCmdPushConstants", [&](nlohmann::ordered_json& function) {
        auto& args = function[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["layout"], layout, json_options);
        FieldToJson(VkShaderStageFlags_t(), args["stageFlags"], stageFlags, json_options);
        FieldToJson(args["offset"], offset, json_options);
        FieldToJson(args["size"], size, json_options);
        FieldToJson(args["pValues"], pValues, json_options);
        if (pValues->IsNull())
        {
            args["pValues"] = nullptr;
        }
        else if (json_options.dump_binaries)
        {
            auto        decoded_data = pValues->GetPointer();
            auto        data_size    = pValues->GetLength();
            std::string filename     = GenerateFilename("pushconstants.bin");
            std::string basename     = gfxrecon::util::filepath::Join(json_options.data_sub_dir, filename);
            std::string filepath     = gfxrecon::util::filepath::Join(json_options.root_dir, basename);
            if (WriteBinaryFile(filepath, data_size, decoded_data))
            {
                FieldToJson(args["pValues"], basename, json_options);
            }
            else
            {
                FieldToJson(args["pValues"], "Unable to write file", json_options);
            }
        }
        else
        {
            FieldToJson(args["pValues"], "[Binary data]", json_options);
        }
    });
}

void VulkanExportJsonConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    const ApiCallInfo&               call_info,
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    using namespace gfxrecon::util;
    const JsonOptions& json_options = GetJsonOptions();

    auto& function = WriteApiCallStart(call_info, "vkUpdateDescriptorSetWithTemplateKHR");
    auto& args     = function[NameArgs()];

    HandleToJson(args["device"], device, json_options);
    HandleToJson(args["descriptorSet"], descriptorSet, json_options);
    HandleToJson(args["descriptorUpdateTemplate"], descriptorUpdateTemplate, json_options);
    FieldToJson(args["pData"], pData, json_options);

    WriteBlockEnd();
}

nlohmann::ordered_json& VulkanExportJsonConsumerBase::WriteApiCallStart(const ApiCallInfo& call_info,
                                                                        const std::string& command_name)
{
    using namespace util;
    auto& json_data = WriteBlockStart();

    json_data[NameIndex()] = call_info.index;

    nlohmann::ordered_json& function = json_data[NameFunction()];
    function[NameName()]             = command_name;
    function[NameThread()]           = call_info.thread_id;

    return function;
}

void VulkanExportJsonConsumerBase::ProcessAnnotation(uint64_t               block_index,
                                                     format::AnnotationType type,
                                                     const std::string&     label,
                                                     const std::string&     data)
{
    auto& json_data     = WriteBlockStart();
    json_data["index"]  = block_index;
    auto& annotation    = json_data["annotation"];
    annotation["type"]  = AnnotationTypeToString(type);
    annotation["label"] = label;
    annotation["data"]  = data;
    WriteBlockEnd();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
