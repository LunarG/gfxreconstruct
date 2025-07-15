/*
** Copyright (c) 2022-2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_JSON_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_JSON_CONSUMER_BASE_H

#include "util/output_stream.h"
#include "util/defines.h"
#include "annotation_handler.h"
#include "format/platform_types.h"
#include "format/format_json.h"
#include "generated/generated_vulkan_consumer.h"
#include "decode/json_writer.h"
#include "util/json_util.h"
#include "vulkan/vulkan.h"

#include <cstdio>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanExportJsonConsumerBase : public VulkanConsumer
{
  public:
    VulkanExportJsonConsumerBase();

    virtual ~VulkanExportJsonConsumerBase() override;

    void Initialize(JsonWriter* writer, const std::string_view vulkanVersion);

    void Destroy();

    bool IsValid() const { return writer_ && writer_->IsValid(); }

    virtual void
    ProcessSetDeviceMemoryPropertiesCommand(format::HandleId                             physical_device_id,
                                            const std::vector<format::DeviceMemoryType>& memory_types,
                                            const std::vector<format::DeviceMemoryHeap>& memory_heaps) override;

    void Process_vkCmdBuildAccelerationStructuresIndirectKHR(
        const ApiCallInfo&                                                         call_info,
        format::HandleId                                                           commandBuffer,
        uint32_t                                                                   infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        PointerDecoder<VkDeviceAddress>*                                           pIndirectDeviceAddresses,
        PointerDecoder<uint32_t>*                                                  pIndirectStrides,
        PointerDecoder<uint32_t*>*                                                 ppMaxPrimitiveCounts) override;

    virtual void Process_vkCreateShaderModule(
        const gfxrecon::decode::ApiCallInfo&                                                        call_info,
        VkResult                                                                                    returnValue,
        gfxrecon::format::HandleId                                                                  device,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*    pAllocator,
        gfxrecon::decode::HandlePointerDecoder<VkShaderModule>* pShaderModule) override;

    virtual void Process_vkGetPipelineCacheData(const ApiCallInfo&       call_info,
                                                VkResult                 returnValue,
                                                format::HandleId         device,
                                                format::HandleId         pipelineCache,
                                                PointerDecoder<size_t>*  pDataSize,
                                                PointerDecoder<uint8_t>* pData) override;

    virtual void Process_vkCreatePipelineCache(const ApiCallInfo&                                       call_info,
                                               VkResult                                                 returnValue,
                                               format::HandleId                                         device,
                                               StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
                                               StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
                                               HandlePointerDecoder<VkPipelineCache>* pPipelineCache) override;

    virtual void Process_vkCmdPushConstants(const ApiCallInfo&       call_info,
                                            format::HandleId         commandBuffer,
                                            format::HandleId         layout,
                                            VkShaderStageFlags       stageFlags,
                                            uint32_t                 offset,
                                            uint32_t                 size,
                                            PointerDecoder<uint8_t>* pValues) override;

    void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&               call_info,
                                                      format::HandleId                 device,
                                                      format::HandleId                 descriptorSet,
                                                      format::HandleId                 descriptorUpdateTemplate,
                                                      DescriptorUpdateTemplateDecoder* pData) override
    {
        Process_vkUpdateDescriptorSetWithTemplate(
            call_info, device, descriptorSet, descriptorUpdateTemplate, pData, true);
    }

    void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&               call_info,
                                                   format::HandleId                 device,
                                                   format::HandleId                 descriptorSet,
                                                   format::HandleId                 descriptorUpdateTemplate,
                                                   DescriptorUpdateTemplateDecoder* pData) override
    {
        Process_vkUpdateDescriptorSetWithTemplate(
            call_info, device, descriptorSet, descriptorUpdateTemplate, pData, false);
    }

  protected:
    void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&               call_info,
                                                   format::HandleId                 device,
                                                   format::HandleId                 descriptorSet,
                                                   format::HandleId                 descriptorUpdateTemplate,
                                                   DescriptorUpdateTemplateDecoder* pData,
                                                   bool                             use_KHR_suffix);

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                               format::HandleId   commandBuffer,
                                                               format::HandleId   descriptorUpdateTemplate,
                                                               format::HandleId   layout,
                                                               uint32_t           set,
                                                               DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplate2KHR(
        const ApiCallInfo&                                                 call_info,
        format::HandleId                                                   commandBuffer,
        StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfo>* pPushDescriptorSetWithTemplateInfo) override;

    const util::JsonOptions& GetJsonOptions() const { return writer_->GetOptions(); }

    nlohmann::ordered_json& WriteBlockStart() { return writer_->WriteBlockStart(); }

    /// Output the current in-memory json tree to the destination file.
    void WriteBlockEnd() { writer_->WriteBlockEnd(); }

    // Wrappers for json field names allowing change without code gen and
    // leaving door open for switching output based on internal state.
    /// @todo Just use the constants directly: the requirement to be able to have
    /// different versions of field names switchable at runtime that I added these
    /// as a first step towards during Export PR integration has gone away.
    constexpr const char* NameFunction() const { return format::kNameFunction; }
    constexpr const char* NameMeta() const { return format::kNameMeta; }
    constexpr const char* NameState() const { return format::kNameState; }
    constexpr const char* NameFrame() const { return format::kNameFrame; }
    constexpr const char* NameName() const { return format::kNameName; }
    constexpr const char* NameIndex() const { return format::kNameIndex; }
    constexpr const char* NameThread() const { return format::kNameThread; }
    constexpr const char* NameReturn() const { return format::kNameReturn; }
    constexpr const char* NameArgs() const { return format::kNameArgs; }
    /// A field not present in binary format which identifies the index of each
    /// command within its command buffer.
    /// @todo Make this field optional.
    constexpr const char* NameCommandIndex() const { return "cmd_index"; }
    /// A field not present in binary format which identifies the index of each
    /// submit in the global order of all submits to all queues as recorded in
    /// the binary trace file.
    /// @todo Make this field optional.
    constexpr const char* NameSubmitIndex() const { return "sub_index"; }

    nlohmann::ordered_json& WriteApiCallStart(const ApiCallInfo& call_info, const std::string& command_name)
    {
        return writer_->WriteApiCallStart(call_info, command_name);
    }

    /// A utility wrapper so that manual output functions can provide a lambda which only needs to output
    /// the fields unique to their call and this tops and tails with the standard boilerplate, defining it
    /// once here. Generated functions avoid the indirection through this.
    template <typename ToJsonFunctionType>
    inline void
    WriteApiCallToFile(const ApiCallInfo& call_info, const std::string& command_name, ToJsonFunctionType toJsonFunction)
    {
        nlohmann::ordered_json& function = WriteApiCallStart(call_info, command_name);
        toJsonFunction(function);
        WriteBlockEnd();
    }

    std::string GenerateFilename(const std::string& filename);
    bool        WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data);

    uint32_t GetCommandBufferRecordIndex(format::HandleId command_buffer)
    {
        uint32_t index = ++rec_cmd_index_[command_buffer];
        return index;
    }

    void ResetCommandBufferRecordIndex(format::HandleId command_buffer) { rec_cmd_index_[command_buffer] = 0; }

    uint32_t                                       submit_index_{ 0 }; // index of submissions across the trace
    std::unordered_map<format::HandleId, uint32_t> rec_cmd_index_;

    JsonWriter* writer_{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_JSON_CONSUMER_BASE_H
