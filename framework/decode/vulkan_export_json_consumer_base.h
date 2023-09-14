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

#ifndef GFXRECON_DECODE_VULKAN_EXPORT_JSON_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_EXPORT_JSON_CONSUMER_BASE_H

#include "util/defines.h"
#include "annotation_handler.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_consumer.h"
#include "decode/vulkan_json_util.h"
#include "vulkan/vulkan.h"

#include <cstdio>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanExportJsonConsumerBase : public VulkanConsumer, public AnnotationHandler
{
  public:
    VulkanExportJsonConsumerBase();

    virtual ~VulkanExportJsonConsumerBase() override;

    void Initialize(const JsonOptions&     options,
                    const std::string_view gfxrVersion,
                    const std::string_view vulkanVersion,
                    const std::string_view inputFilepath);

    void Destroy();

    void StartFile(FILE* file);

    void EndFile();

    bool IsValid() const { return (file_ != nullptr); }

    virtual void ProcessStateBeginMarker(uint64_t frame_number) override;

    virtual void ProcessStateEndMarker(uint64_t frame_number) override;

    virtual void ProcessFrameEndMarker(uint64_t frame_number) override;

    virtual void ProcessDisplayMessageCommand(const std::string& message) override;

    virtual void
    ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height) override;

    virtual void ProcessResizeWindowCommand2(format::HandleId surface_id,
                                             uint32_t         width,
                                             uint32_t         height,
                                             uint32_t         pre_transform) override;

    virtual void
    ProcessCreateHardwareBufferCommand(format::HandleId                                    memory_id,
                                       uint64_t                                            buffer_id,
                                       uint32_t                                            format,
                                       uint32_t                                            width,
                                       uint32_t                                            height,
                                       uint32_t                                            stride,
                                       uint64_t                                            usage,
                                       uint32_t                                            layers,
                                       const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override;

    virtual void ProcessDestroyHardwareBufferCommand(uint64_t buffer_id) override;

    virtual void ProcessSetDevicePropertiesCommand(format::HandleId   physical_device_id,
                                                   uint32_t           api_version,
                                                   uint32_t           driver_version,
                                                   uint32_t           vendor_id,
                                                   uint32_t           device_id,
                                                   uint32_t           device_type,
                                                   const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                   const std::string& device_name) override;

    virtual void
    ProcessSetDeviceMemoryPropertiesCommand(format::HandleId                             physical_device_id,
                                            const std::vector<format::DeviceMemoryType>& memory_types,
                                            const std::vector<format::DeviceMemoryHeap>& memory_heaps) override;

    virtual void
    ProcessSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, uint64_t address) override;

    virtual void ProcessSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                               format::HandleId pipeline_id,
                                                               size_t           data_size,
                                                               const uint8_t*   data) override;

    virtual void
    ProcessSetSwapchainImageStateCommand(format::HandleId                                    device_id,
                                         format::HandleId                                    swapchain_id,
                                         uint32_t                                            last_presented_image,
                                         const std::vector<format::SwapchainImageStateInfo>& image_state) override;

    virtual void ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                 uint64_t         max_resource_size,
                                                 uint64_t         max_copy_size) override;

    virtual void ProcessEndResourceInitCommand(format::HandleId device_id) override;

    virtual void ProcessInitBufferCommand(format::HandleId device_id,
                                          format::HandleId buffer_id,
                                          uint64_t         data_size,
                                          const uint8_t*   data) override;

    virtual void ProcessInitImageCommand(format::HandleId             device_id,
                                         format::HandleId             image_id,
                                         uint64_t                     data_size,
                                         uint32_t                     aspect,
                                         uint32_t                     layout,
                                         const std::vector<uint64_t>& level_sizes,
                                         const uint8_t*               data) override;

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

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&               call_info,
                                                              format::HandleId                 device,
                                                              format::HandleId                 descriptorSet,
                                                              format::HandleId                 descriptorUpdateTemplate,
                                                              DescriptorUpdateTemplateDecoder* pData) override;

    /// @brief Convert annotations, which are simple {type:enum, key:string, value:string} objects.
    virtual void ProcessAnnotation(uint64_t               block_index,
                                   format::AnnotationType type,
                                   const std::string&     label,
                                   const std::string&     data) override;

  private:
    // Delete the in-memory JSON tree from the last line and count the new object.
    // Putting it in one non-inline function allows all the JSON deletion work
    // to show up in one place in a profile.
    void WriteBlockStart();

  protected:
    // Output the current in-memory json tree to the destination file:
    // Putting it in one non-inline function avoids code bloat and allows all
    // The JSON->string work to show up in one place in a profile.
    void WriteBlockEnd();

    // Wrappers for json field names allowing change without code gen and
    // leaving door open for switching output based on internal state.
    constexpr const char* NameFunction() const { return "function"; }
    constexpr const char* NameMeta() const { return "meta"; }
    constexpr const char* NameState() const { return "state"; }
    constexpr const char* NameFrame() const { return "frame"; }
    constexpr const char* NameName() const { return "name"; }
    constexpr const char* NameIndex() const { return "index"; }
    constexpr const char* NameThread() const { return "thread"; }
    constexpr const char* NameReturn() const { return "return"; }
    constexpr const char* NameArgs() const { return "args"; }
    constexpr const char* NameThreadId() const { return "thread"; }
    /// A field not present in binary format which identifies the index of each
    /// command within its command buffer.
    /// @todo Make this field optional.
    constexpr const char* NameCommandIndex() const { return "cmd_index"; }
    /// A field not present in binary format which identifies the index of each
    /// submit in the global order of all submits to all queues as recorded in
    /// the binary trace file.
    /// @todo Make this field optional.
    constexpr const char* NameSubmitIndex() const { return "sub_index"; }

    nlohmann::ordered_json& WriteApiCallStart(const ApiCallInfo& call_info, const std::string& command_name);

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

    template <typename ToJsonFunctionType>
    inline void WriteMetaCommandToFile(const std::string& command_name, ToJsonFunctionType to_json_function)
    {
        using namespace util;
        WriteBlockStart();

        nlohmann::ordered_json& meta = json_data_[NameMeta()];
        meta[NameName()]             = command_name;
        to_json_function(meta[NameArgs()]);

        WriteBlockEnd();
    }

    inline void WriteStateMarkerToFile(const std::string& marker_type, uint64_t frame_number)
    {
        using namespace util;
        WriteBlockStart();

        nlohmann::ordered_json& state = json_data_[NameState()];
        state["marker_type"]          = marker_type;
        state["frame_number"]         = frame_number;

        WriteBlockEnd();
    }

    inline void WriteFrameMarkerToFile(const std::string& marker_type, uint64_t frame_number)
    {
        using namespace util;
        WriteBlockStart();

        nlohmann::ordered_json& frame = json_data_[NameFrame()];
        frame["marker_type"]          = marker_type;
        frame["frame_number"]         = frame_number;

        WriteBlockEnd();
    }

    std::string GenerateFilename(const std::string& filename);
    bool        WriteBinaryFile(const std::string& filename, uint64_t buffer_size, const uint8_t* data);

    uint32_t GetCommandBufferRecordIndex(format::HandleId command_buffer)
    {
        uint32_t index = ++rec_cmd_index_[command_buffer];
        return index;
    }

    void ResetCommandBufferRecordIndex(format::HandleId command_buffer) { rec_cmd_index_[command_buffer] = 0; }

    JsonOptions                                    json_options_;
    uint32_t                                       submit_index_{ 0 }; // index of submissions across the trace
    std::unordered_map<format::HandleId, uint32_t> rec_cmd_index_;

  private:
    FILE*                  file_{ nullptr };
    nlohmann::ordered_json header_;
    nlohmann::ordered_json json_data_;
    uint32_t               num_objects_{ 0 };
    uint32_t               num_files_{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_EXPORT_JSON_CONSUMER_BASE_H
