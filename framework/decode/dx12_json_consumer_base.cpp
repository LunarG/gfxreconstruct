/*
** Copyright (c) 2023 LunarG, Inc.
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

/// @file Implementation of manual base class for generated DX12 consumer
/// which outputs a JSON representation of a captured stream.

#include "decode/dx12_json_consumer_base.h"
#include "decode/json_writer.h"
#include "decode/decode_json_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

static std::string_view ViewOfCharArray(const char* array, const size_t capacity)
{
    const char* zero_end = std::find(array, array + capacity, 0);
    return std::string_view(array, zero_end - array);
}

static void FieldToJson(nlohmann::ordered_json&                                  jdata,
                        const format::InitDx12AccelerationStructureGeometryDesc& data,
                        const util::JsonOptions&                                 options)
{
    FieldToJson(jdata["geometry_type"], data.geometry_type, options);
    FieldToJson(jdata["geometry_flags"], data.geometry_flags, options);
    FieldToJson(jdata["aabbs_count"], data.aabbs_count, options);
    FieldToJson(jdata["aabbs_stride"], data.aabbs_stride, options);
    Bool32ToJson(jdata["triangles_has_transform"], data.triangles_has_transform, options);
    FieldToJson(jdata["triangles_index_format"], data.triangles_index_format, options);
    FieldToJson(jdata["triangles_vertex_format"], data.triangles_vertex_format, options);
    FieldToJson(jdata["triangles_index_count"], data.triangles_index_count, options);
    FieldToJson(jdata["triangles_vertex_count"], data.triangles_vertex_count, options);
    FieldToJson(jdata["triangles_vertex_stride"], data.triangles_vertex_stride, options);
}

static void
FieldToJson(nlohmann::ordered_json& jdata, const format::DxgiAdapterDesc& data, const util::JsonOptions& options)
{
    FieldToJson(jdata["Description"], std::wstring_view(data.Description), options);
    FieldToJson(jdata["VendorId"], data.VendorId, options);
    FieldToJson(jdata["DeviceId"], data.DeviceId, options);
    FieldToJson(jdata["SubSysId"], data.SubSysId, options);
    FieldToJson(jdata["Revision"], data.Revision, options);
    FieldToJson(jdata["DedicatedVideoMemory"], data.DedicatedVideoMemory, options);
    FieldToJson(jdata["DedicatedSystemMemory"], data.DedicatedSystemMemory, options);
    FieldToJson(jdata["SharedSystemMemory"], data.SharedSystemMemory, options);
    FieldToJson(jdata["LuidLowPart"], data.LuidLowPart, options);
    FieldToJson(jdata["LuidHighPar"], data.LuidHighPart, options);
    // Should we break out the packed data? (2 bits (LSB) to store Type and 30 bits for object ID)
    FieldToJson(jdata["extra_info"], data.extra_info, options);
}

static void
FieldToJson(nlohmann::ordered_json& jdata, const format::Dx12RuntimeInfo& data, const util::JsonOptions& options)
{
    FieldToJson(jdata["version"], data.version, util::filepath::kFileVersionSize, options);
    FieldToJson(jdata["src"], util::ViewOfCharArray(data.src, util::filepath::kMaxFilePropertySize), options);
}

static void
FieldToJson(nlohmann::ordered_json& jdata, const util::filepath::FileInfo& data, const util::JsonOptions& options)
{
    FieldToJson(jdata["ProductVersion"], ViewOfCharArray(data.ProductVersion, filepath::kMaxFilePropertySize), options);
    FieldToJson(jdata["FileVersion"], ViewOfCharArray(data.FileVersion, filepath::kMaxFilePropertySize), options);
    FieldToJson(jdata["AppVersion"], data.AppVersion, filepath::kMaxFilePropertySize, options);
    FieldToJson(jdata["AppName"], ViewOfCharArray(data.AppName, filepath::kMaxFilePropertySize), options);
    FieldToJson(jdata["CompanyName"], ViewOfCharArray(data.CompanyName, filepath::kMaxFilePropertySize), options);
    FieldToJson(
        jdata["FileDescription"], ViewOfCharArray(data.FileDescription, filepath::kMaxFilePropertySize), options);
    FieldToJson(jdata["InternalName"], ViewOfCharArray(data.InternalName, filepath::kMaxFilePropertySize), options);
    FieldToJson(
        jdata["OriginalFilename"], ViewOfCharArray(data.OriginalFilename, filepath::kMaxFilePropertySize), options);
    FieldToJson(jdata["ProductName"], ViewOfCharArray(data.ProductName, filepath::kMaxFilePropertySize), options);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(decode)

Dx12JsonConsumerBase::Dx12JsonConsumerBase() {}

Dx12JsonConsumerBase::~Dx12JsonConsumerBase()
{
    Destroy();
}

void Dx12JsonConsumerBase::Initialize(JsonWriter* writer)
{
    assert(writer);
    writer_ = writer;
}

void Dx12JsonConsumerBase::Destroy()
{
    writer_ = nullptr;
}

bool Dx12JsonConsumerBase::IsValid() const
{
    return writer_ && writer_->IsValid();
}

void Dx12JsonConsumerBase::ProcessCreateHeapAllocationCommand(uint64_t allocation_id, uint64_t allocation_size)
{
    const util::JsonOptions& json_options = writer_->GetOptions();
    auto&                    jdata        = writer_->WriteMetaCommandStart("CreateHeapAllocationCommand");
    FieldToJson(jdata["allocation_id"], allocation_id, json_options);
    FieldToJson(jdata["allocation_size"], allocation_size, json_options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::ProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                                         const uint8_t*                              data)
{
    const util::JsonOptions& json_options = writer_->GetOptions();
    auto&                    jdata        = writer_->WriteMetaCommandStart("InitSubresourceCommand");

    FieldToJson(jdata["thread_id"], command_header.thread_id, json_options);
    FieldToJson(jdata["device_id"], command_header.device_id, json_options);
    FieldToJson(jdata["resource_id"], command_header.resource_id, json_options);
    FieldToJson(jdata["subresource"], command_header.subresource, json_options);
    FieldToJson(jdata["initial_state"], command_header.initial_state, json_options);
    FieldToJson(jdata["resource_state"], command_header.resource_state, json_options);
    FieldToJson(jdata["barrier_flags"], command_header.barrier_flags, json_options);
    FieldToJson(jdata["data_size"], command_header.data_size, json_options);
    RepresentBinaryFile(
        *(this->writer_), jdata[format::kNameData], "initsubresourcecommand.bin", command_header.data_size, data);

    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::ProcessInitDx12AccelerationStructureCommand(
    const format::InitDx12AccelerationStructureCommandHeader&       command_header,
    std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
    const uint8_t*                                                  build_inputs_data)
{
    const util::JsonOptions& json_options = writer_->GetOptions();
    auto&                    jdata        = writer_->WriteMetaCommandStart("InitDx12AccelerationStructureCommand");
    FieldToJson(jdata["thread_id"], command_header.thread_id, json_options);
    FieldToJson(
        jdata["dest_acceleration_structure_data"], command_header.dest_acceleration_structure_data, json_options);
    FieldToJson(jdata["copy_source_gpu_va"], command_header.copy_source_gpu_va, json_options);
    FieldToJson(jdata["copy_mode"], command_header.copy_mode, json_options);
    FieldToJson(
        jdata["inputs_type"], command_header.inputs_type, json_options); /// @todo does this correspond to a D3D12 enum?
    FieldToJson(
        jdata["inputs_flags"], command_header.inputs_flags, json_options); /// @todo Flags as pretty form or hex?
    FieldToJson(jdata["inputs_num_instance_descs"], command_header.inputs_num_instance_descs, json_options);
    FieldToJson(jdata["inputs_num_geometry_descs"], command_header.inputs_num_geometry_descs, json_options);
    /// @todo Do we want to dump the geometry_descs, the input data, or both?
    /// The data is useful to be closer to the binary capture and to round-trip to it one day, but the constructed descs
    /// are good for eyeballing.
    FieldToJson(jdata["inputs_data_size"], command_header.inputs_data_size, json_options);
    RepresentBinaryFile(*(this->writer_),
                        jdata[format::kNameData],
                        "initdx12accelerationstructurecommand.bin",
                        command_header.inputs_data_size,
                        build_inputs_data);
    FieldToJson(jdata["geometry_descs"], geometry_descs.data(), geometry_descs.size(), json_options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::ProcessFillMemoryResourceValueCommand(
    const format::FillMemoryResourceValueCommandHeader& command_header, const uint8_t* data)
{
    const util::JsonOptions& json_options = writer_->GetOptions();
    auto&                    jdata        = writer_->WriteMetaCommandStart("FillMemoryResourceValueCommand");
    FieldToJson(jdata["thread_id"], command_header.thread_id, json_options);
    FieldToJson(jdata["resource_value_count"], command_header.resource_value_count, json_options);
    // There are two blocks of values in data so we need to add together their sizes to know how big the blob to dump
    // is:
    const auto types_bytes   = command_header.resource_value_count * sizeof(format::ResourceValueType);
    const auto offsets_bytes = command_header.resource_value_count * sizeof(uint64_t);
    RepresentBinaryFile(*(this->writer_),
                        jdata[format::kNameData],
                        "fillmemoryresourcevaluecommand.bin",
                        types_bytes + offsets_bytes,
                        data);

    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::ProcessDxgiAdapterInfo(const format::DxgiAdapterInfoCommandHeader& adapter_info_header)
{
    const util::JsonOptions& json_options = writer_->GetOptions();
    auto&                    jdata        = writer_->WriteMetaCommandStart("DxgiAdapterInfo");
    FieldToJson(jdata["thread_id"], adapter_info_header.thread_id, json_options);
    FieldToJson(jdata["adapter_desc"], adapter_info_header.adapter_desc, json_options);
    writer_->WriteBlockEnd();
}

/// @see DriverInfoBlock in format.h
void Dx12JsonConsumerBase::Process_DriverInfo(const char* info_record)
{
    const util::JsonOptions& json_options = writer_->GetOptions();
    auto&                    jdata        = writer_->WriteMetaCommandStart("DriverInfo");
    char                     driver_record[gfxrecon::util::filepath::kMaxDriverInfoSize + 1];

    FieldToJson(jdata[format::kNameDebug], "thread_id field not exposed.", json_options);
    FieldToJson(
        jdata["driver_record"], util::ViewOfCharArray(info_record, util::filepath::kMaxDriverInfoSize), json_options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::ProcessDx12RuntimeInfo(const format::Dx12RuntimeInfoCommandHeader& runtime_info_header)
{
    const util::JsonOptions& json_options = writer_->GetOptions();
    auto&                    jdata        = writer_->WriteMetaCommandStart("Dx12RuntimeInfoCommandHeader");

    FieldToJson(jdata["thread_id"], runtime_info_header.thread_id, json_options);
    FieldToJson(jdata["runtime_info"], runtime_info_header.runtime_info, json_options);

    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::Process_ExeFileInfo(const util::filepath::FileInfo& info_record)
{
    const util::JsonOptions& json_options = writer_->GetOptions();
    auto&                    jdata        = writer_->WriteMetaCommandStart("Dx12RuntimeInfoCommandHeader");
    /// @todo Plumb through the thread ID so it can be output here.
    FieldToJson(jdata["info_record"], info_record, json_options);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
