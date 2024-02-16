/*
** Copyright (c) 2023 Valve Corporation
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

#ifndef GFXRECON_DECODE_METADATA_JSON_CONSUMER_H
#define GFXRECON_DECODE_METADATA_JSON_CONSUMER_H

#include "util/defines.h"
#include "format/format_json.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// Template shim for turning metadata (metacommands) into JSON using a
/// JsonWriter pointed to by a protected pointer called writer_ in a base class.
/// This can be shimmed into the inheritance hierarchy for any JSON consumer as
/// is done by gfxrecon-convert's main.cpp for both Vulkan and DX12 consumers to
/// provide metacommand support.
/// @note Any API-specific metablocks/metadata/metacommands are best handled directly by the JSON consumer of that API.
/// @note An alternative implementation would make MetadataConsumerBase a virtual base class of the base
/// Vulkan and DX12 consumers, and also a virtual base of a non-template version of MetadataJsonConsumer,
/// and VulkanJSONConsumer and DX12JsonConsumer would both use multiple inheritance to mix-in this posited non-template
/// MetadataJsonConsumer. The advantage would be code space saved due to avoiding two template instantiations with
/// identical code. The downside would be the slower virtual function dispatch due to diamond inheritance from the
/// use of virtual base classes (See Stroustrup, Design and Evolution of C++ for overheads of virtual base classes).
template <class Base>
class MetadataJsonConsumer : public Base
{
    typedef util::JsonOptions JsonOptions;

    inline const util::JsonOptions& GetOptions() const { return this->writer_->GetOptions(); }
    inline const util::JsonOptions& GetJsonOptions() const { return this->writer_->GetOptions(); } // temp
    inline nlohmann::ordered_json&  WriteMetaCommandStart(const std::string& command_name) const
    {
        this->writer_->SetCurrentBlockIndex(this->block_index_);
        return this->writer_->WriteMetaCommandStart(command_name);
    }
    inline void WriteBlockEnd() { this->writer_->WriteBlockEnd(); }

  public:
    /// @defGroup ApiAgnosticMetaBlocks Metablocks used by both Vulkan and DX12.
    /// @{
    virtual void ProcessDisplayMessageCommand(const std::string& message) override
    {
        auto& jdata = WriteMetaCommandStart("DisplayMessageCommand");
        FieldToJson(jdata["message"], message, GetOptions());
        WriteBlockEnd();
    }

    virtual void
    ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override
    {
        const util::JsonOptions& json_options = GetOptions();
        auto&                    jdata        = WriteMetaCommandStart("FillMemoryCommand");
        HandleToJson(jdata["memory_id"], memory_id, json_options);
        FieldToJson(jdata["offset"], offset, json_options);
        FieldToJson(jdata["size"], size, json_options);
        RepresentBinaryFile(*(this->writer_), jdata[format::kNameData], "fill_memory.bin", size, data);
        WriteBlockEnd();
    }

    virtual void ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height) override
    {
        using namespace util;
        const JsonOptions& json_options = GetOptions();
        auto&              jdata        = WriteMetaCommandStart("ResizeWindowCommand");
        HandleToJson(jdata["surface_id"], surface_id, json_options);
        FieldToJson(jdata["width"], width, json_options);
        FieldToJson(jdata["height"], height, json_options);
        WriteBlockEnd();
    }

    virtual void ProcessResizeWindowCommand2(format::HandleId surface_id,
                                             uint32_t         width,
                                             uint32_t         height,
                                             uint32_t         pre_transform) override
    {
        auto&                    jdata        = WriteMetaCommandStart("ResizeWindowCommand2");
        const util::JsonOptions& json_options = GetOptions();
        HandleToJson(jdata["surface_id"], surface_id, json_options);
        FieldToJson(jdata["width"], width, json_options);
        FieldToJson(jdata["height"], height, json_options);
        FieldToJson(jdata["pre_transform"], pre_transform, json_options);
        WriteBlockEnd();
    }

    virtual void
    ProcessCreateHardwareBufferCommand(format::HandleId                                    memory_id,
                                       uint64_t                                            buffer_id,
                                       uint32_t                                            format,
                                       uint32_t                                            width,
                                       uint32_t                                            height,
                                       uint32_t                                            stride,
                                       uint64_t                                            usage,
                                       uint32_t                                            layers,
                                       const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override
    {
        const util::JsonOptions& json_options = GetOptions();
        auto&                    jdata        = WriteMetaCommandStart("CreateHardwareBufferCommand");
        HandleToJson(jdata["memory_id"], memory_id, json_options);
        HandleToJson(jdata["buffer_id"], buffer_id, json_options);
        FieldToJson(jdata["format"], format, json_options);
        FieldToJson(jdata["width"], width, json_options);
        FieldToJson(jdata["height"], height, json_options);
        FieldToJson(jdata["stride"], stride, json_options);
        FieldToJson(jdata["usage"], usage, json_options);
        FieldToJson(jdata["layers"], layers, json_options);
        WriteBlockEnd();
    }

    virtual void ProcessDestroyHardwareBufferCommand(const uint64_t buffer_id) override
    {
        auto& jdata = WriteMetaCommandStart("DestroyHardwareBufferCommand");
        HandleToJson(jdata["buffer_id"], buffer_id, GetOptions());
        WriteBlockEnd();
    }

    virtual void ProcessSetDevicePropertiesCommand(format::HandleId   physical_device_id,
                                                   uint32_t           api_version,
                                                   uint32_t           driver_version,
                                                   uint32_t           vendor_id,
                                                   uint32_t           device_id,
                                                   uint32_t           device_type,
                                                   const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                   const std::string& device_name) override
    {
        const util::JsonOptions& json_options = GetOptions();
        auto&                    jdata        = WriteMetaCommandStart("SetDevicePropertiesCommand");
        HandleToJson(jdata["physical_device_id"], physical_device_id, json_options);
        FieldToJson(jdata["api_version"], api_version, json_options);
        FieldToJson(jdata["driver_version"], driver_version, json_options);
        FieldToJson(jdata["vendor_id"], vendor_id, json_options);
        FieldToJson(jdata["device_id"], device_id, json_options);
        FieldToJson(jdata["device_type"], device_type, json_options);
        FieldToJson(
            jdata["pipeline_cache_uuid"], util::uuid_to_string(format::kUuidSize, pipeline_cache_uuid), json_options);
        FieldToJson(jdata["device_name"], device_name, json_options);
        WriteBlockEnd();
    }

    virtual void
    ProcessSetDeviceMemoryPropertiesCommand(format::HandleId                             physical_device_id,
                                            const std::vector<format::DeviceMemoryType>& memory_types,
                                            const std::vector<format::DeviceMemoryHeap>& memory_heaps) override
    {
        const util::JsonOptions& json_options = GetJsonOptions();
        auto&                    jdata        = WriteMetaCommandStart("SetDeviceMemoryPropertiesCommand");
        HandleToJson(jdata["physical_device_id"], physical_device_id, json_options);
        WriteBlockEnd();
    }

    virtual void
    ProcessSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, uint64_t address) override
    {
        const JsonOptions& json_options = GetJsonOptions();
        auto&              jdata        = WriteMetaCommandStart("SetOpaqueAddressCommand");
        HandleToJson(jdata["device_id"], device_id, json_options);
        HandleToJson(jdata["object_id"], object_id, json_options);
        FieldToJson(jdata["address"], util::to_hex_variable_width(address), json_options);
        WriteBlockEnd();
    }

    virtual void ProcessSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                               format::HandleId pipeline_id,
                                                               size_t           data_size,
                                                               const uint8_t*   data) override
    {
        const JsonOptions& json_options = GetJsonOptions();
        auto&              jdata        = WriteMetaCommandStart("SetRayTracingShaderGroupHandlesCommand");
        HandleToJson(jdata["device_id"], device_id, json_options);
        HandleToJson(jdata["pipeline_id"], pipeline_id, json_options);
        FieldToJson(jdata["data_size"], data_size, json_options);
        RepresentBinaryFile(
            *(this->writer_), jdata[format::kNameData], "set_raytracing_shader_group_handles.bin", data_size, data);
        WriteBlockEnd();
    }

    virtual void
    ProcessSetSwapchainImageStateCommand(format::HandleId                                    device_id,
                                         format::HandleId                                    swapchain_id,
                                         uint32_t                                            last_presented_image,
                                         const std::vector<format::SwapchainImageStateInfo>& image_state) override
    {
        const JsonOptions& json_options = GetJsonOptions();
        auto&              jdata        = WriteMetaCommandStart("SetSwapchainImageStateCommand");
        HandleToJson(jdata["device_id"], device_id, json_options);
        HandleToJson(jdata["swapchain_id"], swapchain_id, json_options);
        FieldToJson(jdata["last_presented_image"], last_presented_image, json_options);
        FieldToJson(jdata["image_state"], "not available", json_options);
        WriteBlockEnd();
    }

    virtual void ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                 uint64_t         max_resource_size,
                                                 uint64_t         max_copy_size) override
    {
        const JsonOptions& json_options = GetJsonOptions();
        auto&              jdata        = WriteMetaCommandStart("BeginResourceInitCommand");
        HandleToJson(jdata["device_id"], device_id, json_options);
        FieldToJson(jdata["max_resource_size"], max_resource_size, json_options);
        FieldToJson(jdata["max_copy_size"], max_copy_size, json_options);
        WriteBlockEnd();
    }

    virtual void ProcessEndResourceInitCommand(format::HandleId device_id) override
    {
        auto& jdata = WriteMetaCommandStart("EndResourceInitCommand");
        HandleToJson(jdata["device_id"], device_id, GetJsonOptions());
        WriteBlockEnd();
    }

    virtual void ProcessInitBufferCommand(format::HandleId device_id,
                                          format::HandleId buffer_id,
                                          uint64_t         data_size,
                                          const uint8_t*   data) override
    {
        const JsonOptions& json_options = GetJsonOptions();
        auto&              jdata        = WriteMetaCommandStart("InitBufferCommand");
        HandleToJson(jdata["device_id"], device_id, json_options);
        HandleToJson(jdata["buffer_id"], buffer_id, json_options);
        FieldToJson(jdata["data_size"], data_size, json_options);
        RepresentBinaryFile(*(this->writer_), jdata[format::kNameData], "init_buffer.bin", data_size, data);
        WriteBlockEnd();
    }

    virtual void ProcessInitImageCommand(format::HandleId             device_id,
                                         format::HandleId             image_id,
                                         uint64_t                     data_size,
                                         uint32_t                     aspect,
                                         uint32_t                     layout,
                                         const std::vector<uint64_t>& level_sizes,
                                         const uint8_t*               data) override
    {
        const JsonOptions& json_options = GetJsonOptions();
        auto&              jdata        = WriteMetaCommandStart("InitImageCommand");
        HandleToJson(jdata["device_id"], device_id, json_options);
        HandleToJson(jdata["image_id"], image_id, json_options);
        FieldToJson(jdata["data_size"], data_size, json_options);
        FieldToJson(jdata["aspect"], aspect, json_options);
        FieldToJson(jdata["layout"], layout, json_options);
        FieldToJson(jdata["level_sizes"], "not available", json_options);
        RepresentBinaryFile(*(this->writer_), jdata[format::kNameData], "init_image.bin", data_size, data);
        WriteBlockEnd();
    }

    /// @}
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_METADATA_JSON_CONSUMER_H
