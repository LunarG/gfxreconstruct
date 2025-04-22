/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2024 Qualcomm Technologies, Inc. and/or its subsidiaries.
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
#include "generated/generated_dx12_enum_to_json.h"
#include "generated/generated_dx12_struct_decoders_to_json.h"
#include "util/strings.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
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

/// @brief Convert an InitDx12AccelerationStructureCommand, which is used for trimmed
/// captures as part of establishing the GPU memory state at the start of the trimmed
/// range.
void Dx12JsonConsumerBase::ProcessInitDx12AccelerationStructureCommand(
    const format::InitDx12AccelerationStructureCommandHeader&       command_header,
    std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
    const uint8_t*                                                  build_inputs_data)
{
    const util::JsonOptions& json_options = writer_->GetOptions();
    auto&                    jdata        = writer_->WriteMetaCommandStart("InitDx12AccelerationStructureCommand");
    FieldToJson(jdata["thread_id"], command_header.thread_id, json_options);
    // The GPU address D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC.DestAccelerationStructureData
    // is mapped from this during replay but we'll just dump the raw capture file value:
    FieldToJsonAsHex(
        jdata["dest_acceleration_structure_data"], command_header.dest_acceleration_structure_data, json_options);
    // A GPU virtual address to copy from after pumping througnh a graphics::Dx12GpuVaMap during replay, but we'll just
    // dump the raw capture file value:
    FieldToJsonAsHex(jdata["copy_source_gpu_va"], command_header.copy_source_gpu_va, json_options);
    FieldToJson(jdata["copy_mode"],
                static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE>(command_header.copy_mode),
                json_options);
    FieldToJson(jdata["inputs_type"],
                static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE>(command_header.inputs_type),
                json_options);
    FieldToJson_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(
        jdata["inputs_flags"],
        static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS>(command_header.inputs_flags),
        json_options);
    FieldToJson(jdata["inputs_num_instance_descs"], command_header.inputs_num_instance_descs, json_options);
    FieldToJson(jdata["inputs_num_geometry_descs"], command_header.inputs_num_geometry_descs, json_options);
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
    FieldToJson(jdata["driver_record"],
                util::strings::ViewOfCharArray(info_record, util::filepath::kMaxDriverInfoSize),
                json_options);
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

void Dx12JsonConsumerBase::Process_ID3D12Device_CheckFeatureSupport(format::HandleId      object_id,
                                                                    HRESULT               original_result,
                                                                    D3D12_FEATURE         feature,
                                                                    DxFeatureDataDecoder* feature_data,
                                                                    UINT                  feature_data_size)
{
    using namespace gfxrecon::util;
    ApiCallInfo call_info;
    call_info.index     = GetCurrentBlockIndex();
    call_info.thread_id = format::kNameUnknownThreadId;

    nlohmann::ordered_json& method =
        writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CheckFeatureSupport");
    const JsonOptions& json_options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], original_result, json_options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Feature"], feature, json_options);
        if (feature_data)
        {
            switch (feature)
            {
                case D3D12_FEATURE_D3D12_OPTIONS:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_ARCHITECTURE:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_ARCHITECTURE>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_FEATURE_LEVELS:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_FORMAT_SUPPORT:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_FORMAT_INFO:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_FORMAT_INFO>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_SHADER_MODEL:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_SHADER_MODEL>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_D3D12_OPTIONS1:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_SUPPORT:
                {
                    const auto data =
                        feature_data
                            ->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_ROOT_SIGNATURE:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_ARCHITECTURE1:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_D3D12_OPTIONS2:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_SHADER_CACHE:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_SHADER_CACHE>();
                    reinterpret_cast<StructPointerDecoder<Decoded_D3D12_FEATURE_DATA_SHADER_CACHE>*>(feature_data);
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_COMMAND_QUEUE_PRIORITY:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_D3D12_OPTIONS3:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_EXISTING_HEAPS:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_D3D12_OPTIONS4:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_SERIALIZATION:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_SERIALIZATION>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_CROSS_NODE:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_CROSS_NODE>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_D3D12_OPTIONS5:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_D3D12_OPTIONS6:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_QUERY_META_COMMAND:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_D3D12_OPTIONS7:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPE_COUNT:
                {
                    const auto data = feature_data->GetStructPointerDecoder<
                        Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPES:
                {
                    const auto data =
                        feature_data
                            ->GetStructPointerDecoder<Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::Process_IDXGIFactory5_CheckFeatureSupport(format::HandleId      object_id,
                                                                     HRESULT               original_result,
                                                                     DXGI_FEATURE          feature,
                                                                     DxFeatureDataDecoder* feature_data,
                                                                     UINT                  feature_data_size)
{
    using namespace gfxrecon::util;
    ApiCallInfo call_info;
    call_info.index     = GetCurrentBlockIndex();
    call_info.thread_id = format::kNameUnknownThreadId;

    nlohmann::ordered_json& method =
        writer_->WriteApiCallStart(call_info, "IDXGIFactory5", object_id, "CheckFeatureSupport");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], original_result, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Feature"], feature, options);
        if (!feature_data->IsNull())
        {
            switch (feature)
            {
                case DXGI_FEATURE_PRESENT_ALLOW_TEARING:
                {
                    FieldToJson(args["pFeatureSupportData"],
                                *reinterpret_cast<const bool*>(feature_data->GetPointer()),
                                options);
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::Process_ID3D12Resource_WriteToSubresource(format::HandleId object_id,
                                                                     HRESULT          return_value,
                                                                     UINT             DstSubresource,
                                                                     StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
                                                                     void*                                    pSrcData,
                                                                     UINT SrcRowPitch,
                                                                     UINT SrcDepthPitch)
{
    using namespace gfxrecon::util;
    ApiCallInfo call_info;
    call_info.index     = GetCurrentBlockIndex();
    call_info.thread_id = format::kNameUnknownThreadId;

    nlohmann::ordered_json& method =
        writer_->WriteApiCallStart(call_info, "ID3D12Resource", object_id, "WriteToSubresource");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["DstSubresource"], DstSubresource, options);
        FieldToJson(args["pDstBox"], pDstBox, options);
        /// @todo Complete conversion of the void * member pSrcData of Process_ID3D12Resource_WriteToSubresource.
        FieldToJson(args[format::kNameWarning], "Incomplete conversion: pSrcData not supported yet.", options);
        FieldToJson(args["pSrcData"], nullptr, options);
        FieldToJson(args["SrcRowPitch"], SrcRowPitch, options);
        FieldToJson(args["SrcDepthPitch"], SrcDepthPitch, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::Process_ID3D11Device_CheckFeatureSupport(const ApiCallInfo&    call_info,
                                                                    format::HandleId      object_id,
                                                                    HRESULT               return_value,
                                                                    D3D11_FEATURE         feature,
                                                                    DxFeatureDataDecoder* feature_data,
                                                                    UINT                  feature_data_size)
{

    using namespace gfxrecon::util;

    nlohmann::ordered_json& method =
        writer_->WriteApiCallStart(call_info, "ID3D11Device", object_id, "CheckFeatureSupport");
    const JsonOptions& json_options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, json_options);
    auto& args = method[format::kNameArgs];
    {
        FieldToJson(args["Feature"], feature, json_options);

        if (feature_data)
        {
            switch (feature)
            {
                case D3D11_FEATURE_THREADING:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_THREADING>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_DOUBLES:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_DOUBLES>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_FORMAT_SUPPORT:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_FORMAT_SUPPORT>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_FORMAT_SUPPORT2:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_FORMAT_SUPPORT2>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D10_X_HARDWARE_OPTIONS:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D11_OPTIONS:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_ARCHITECTURE_INFO:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_ARCHITECTURE_INFO>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D9_OPTIONS:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D9_OPTIONS>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_SHADER_MIN_PRECISION_SUPPORT:
                {
                    const auto data =
                        feature_data
                            ->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D9_SHADOW_SUPPORT:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D11_OPTIONS1:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS1>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D9_SIMPLE_INSTANCING_SUPPORT:
                {
                    const auto data =
                        feature_data
                            ->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_MARKER_SUPPORT:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_MARKER_SUPPORT>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D9_OPTIONS1:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D9_OPTIONS1>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D11_OPTIONS2:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS2>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D11_OPTIONS3:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS3>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D11_OPTIONS4:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS4>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_SHADER_CACHE:
                {
                    const auto data = feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_SHADER_CACHE>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                case D3D11_FEATURE_D3D11_OPTIONS5:
                {
                    const auto data =
                        feature_data->GetStructPointerDecoder<Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS5>();
                    FieldToJson(args["pFeatureSupportData"], data, json_options);
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::Process_ID3D11DeviceContext_UpdateSubresource(
    const ApiCallInfo&                       call_info,
    format::HandleId                         object_id,
    format::HandleId                         pDstResource,
    UINT                                     DstSubresource,
    StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
    PointerDecoder<uint8_t>*                 pSrcData,
    UINT                                     SrcRowPitch,
    UINT                                     SrcDepthPitch)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method =
        writer_->WriteApiCallStart(call_info, "ID3D11DeviceContext", object_id, "UpdateSubresource");
    const JsonOptions&      options = writer_->GetOptions();
    nlohmann::ordered_json& args    = method[format::kNameArgs];
    {
        FieldToJson(args["pDstResource"], pDstResource, options);
        FieldToJson(args["DstSubresource"], DstSubresource, options);
        FieldToJson(args["pDstBox"], pDstBox, options);
        RepresentBinaryFile(*writer_,
                            args["pSrcData"],
                            "ID3D11DeviceContext_UpdateSubresource.bin",
                            pSrcData->GetLength(),
                            pSrcData->GetPointer());
        FieldToJson(args["SrcRowPitch"], SrcRowPitch, options);
        FieldToJson(args["SrcDepthPitch"], SrcDepthPitch, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::Process_ID3D11DeviceContext1_UpdateSubresource1(
    const ApiCallInfo&                       call_info,
    format::HandleId                         object_id,
    format::HandleId                         pDstResource,
    UINT                                     DstSubresource,
    StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
    PointerDecoder<uint8_t>*                 pSrcData,
    UINT                                     SrcRowPitch,
    UINT                                     SrcDepthPitch,
    UINT                                     CopyFlags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method =
        writer_->WriteApiCallStart(call_info, "ID3D11DeviceContext1", object_id, "UpdateSubresource1");
    const JsonOptions&      options = writer_->GetOptions();
    nlohmann::ordered_json& args    = method[format::kNameArgs];
    {
        FieldToJson(args["pDstResource"], pDstResource, options);
        FieldToJson(args["DstSubresource"], DstSubresource, options);
        FieldToJson(args["pDstBox"], pDstBox, options);
        RepresentBinaryFile(*writer_,
                            args["pSrcData"],
                            "ID3D11DeviceContext1_UpdateSubresource1.bin",
                            pSrcData->GetLength(),
                            pSrcData->GetPointer());
        FieldToJson(args["SrcRowPitch"], SrcRowPitch, options);
        FieldToJson(args["SrcDepthPitch"], SrcDepthPitch, options);
        FieldToJson(args["CopyFlags"], CopyFlags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::Process_ID3D11Device3_WriteToSubresource(const ApiCallInfo& call_info,
                                                                    format::HandleId   object_id,
                                                                    format::HandleId   pDstResource,
                                                                    UINT               DstSubresource,
                                                                    StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                                    PointerDecoder<uint8_t>*                 pSrcData,
                                                                    UINT SrcRowPitch,
                                                                    UINT SrcDepthPitch)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method =
        writer_->WriteApiCallStart(call_info, "ID3D11Device3", object_id, "WriteToSubresource");
    const JsonOptions&      options = writer_->GetOptions();
    nlohmann::ordered_json& args    = method[format::kNameArgs];
    {
        FieldToJson(args["pDstResource"], pDstResource, options);
        FieldToJson(args["DstSubresource"], DstSubresource, options);
        FieldToJson(args["pDstBox"], pDstBox, options);
        RepresentBinaryFile(*writer_,
                            args["pSrcData"],
                            "ID3D11Device3_WriteToSubresource.bin",
                            pSrcData->GetLength(),
                            pSrcData->GetPointer());
        FieldToJson(args["SrcRowPitch"], SrcRowPitch, options);
        FieldToJson(args["SrcDepthPitch"], SrcDepthPitch, options);
    }
    writer_->WriteBlockEnd();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
