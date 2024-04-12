/*
** Copyright (c) 2021-2023 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
*/

/*
** This file is generated from dx12_struct_decoders_to_json_body_generator.py.
**
*/

#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#include "generated_dx12_struct_decoders_to_json.h"
#include "generated_dx12_enum_to_json.h"
#include "decode/custom_dx12_struct_decoders.h"
#include "decode/decode_json_util.h"
#include "graphics/dx12_util.h"
#include "util/json_util.h"
#include "format/format_json.h"

/// @file Implementations of functions for converting decoded D3D12 structs to JSON.

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::JsonOptions;

// TODO Move all these manual functions out of the generator and into a .cpp file.

/// @defgroup ManualD3D12StructFieldToJsons Manual functions to convert raw structs.
/** @{ */
static void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& data, const JsonOptions& options)
{
    using namespace util;
    FieldToJson(jdata["AdditionalWidth"],  data.AdditionalWidth,  options);
    FieldToJson(jdata["AdditionalHeight"], data.AdditionalHeight, options);
}

static void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& data, const JsonOptions& options)
{
    using namespace util;
    FieldToJson(jdata["AdditionalWidth"], data.AdditionalWidth, options);
    FieldToJson(jdata["AdditionalHeight"], data.AdditionalHeight, options);
}

/// Manual raw struct functon to be used for Decoded_D3D12_CLEAR_VALUE conversion.
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VALUE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Depth"], obj.Depth, options);
    FieldToJson(jdata["Stencil"], obj.Stencil, options);
}
/** @} */

inline bool RepresentBinaryFile(const util::JsonOptions& json_options, nlohmann::ordered_json& jdata, std::string_view filename_base, const uint64_t instance_counter, const PointerDecoder<uint8_t>& data)
{
    return RepresentBinaryFile(json_options, jdata, filename_base, instance_counter, data.GetLength(), data.GetPointer());
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_FRAME_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_FRAME_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["PresentCount"], decoded_value.PresentCount, options);
        FieldToJson(jdata["PresentRefreshCount"], decoded_value.PresentRefreshCount, options);
        FieldToJson(jdata["SyncRefreshCount"], decoded_value.SyncRefreshCount, options);
        FieldToJson(jdata["SyncQPCTime"], meta_struct.SyncQPCTime, options);
        FieldToJson(jdata["SyncGPUTime"], meta_struct.SyncGPUTime, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MAPPED_RECT& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MAPPED_RECT& meta_struct = *data;
        FieldToJson(jdata["Pitch"], decoded_value.Pitch, options);
        FieldToJson(jdata["pBits"], meta_struct.pBits, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const LUID& decoded_value = *data->decoded_value;
        const Decoded_LUID& meta_struct = *data;
        FieldToJson(jdata["LowPart"], decoded_value.LowPart, options);
        FieldToJson(jdata["HighPart"], decoded_value.HighPart, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description, options);
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options);
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options);
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options);
        FieldToJson(jdata["Revision"], decoded_value.Revision, options);
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options);
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options);
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options);
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTPUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTPUT_DESC& meta_struct = *data;
        FieldToJson(jdata["DeviceName"], meta_struct.DeviceName, options);
        FieldToJson(jdata["DesktopCoordinates"], meta_struct.DesktopCoordinates, options);
        Bool32ToJson(jdata["AttachedToDesktop"], decoded_value.AttachedToDesktop, options);
        FieldToJson(jdata["Rotation"], decoded_value.Rotation, options);
        FieldToJson(jdata["Monitor"], meta_struct.Monitor, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SHARED_RESOURCE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SHARED_RESOURCE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SHARED_RESOURCE& meta_struct = *data;
        FieldToJson(jdata["Handle"], meta_struct.Handle, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SURFACE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SURFACE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SURFACE_DESC& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_DESC& meta_struct = *data;
        FieldToJson(jdata["BufferDesc"], meta_struct.BufferDesc, options);
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options);
        FieldToJson(jdata["BufferUsage"], decoded_value.BufferUsage, options);
        FieldToJson(jdata["BufferCount"], decoded_value.BufferCount, options);
        FieldToJson(jdata["OutputWindow"], meta_struct.OutputWindow, options);
        Bool32ToJson(jdata["Windowed"], decoded_value.Windowed, options);
        FieldToJson(jdata["SwapEffect"], decoded_value.SwapEffect, options);
        FieldToJson(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC1& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description, options);
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options);
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options);
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options);
        FieldToJson(jdata["Revision"], decoded_value.Revision, options);
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options);
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options);
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options);
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid, options);
        FieldToJson(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DISPLAY_COLOR_SPACE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_DISPLAY_COLOR_SPACE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_DISPLAY_COLOR_SPACE& meta_struct = *data;
        FieldToJson(jdata["PrimaryCoordinates"], meta_struct.PrimaryCoordinates, options);
        FieldToJson(jdata["WhitePoints"], meta_struct.WhitePoints, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_MOVE_RECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_MOVE_RECT& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_MOVE_RECT& meta_struct = *data;
        FieldToJson(jdata["SourcePoint"], meta_struct.SourcePoint, options);
        FieldToJson(jdata["DestinationRect"], meta_struct.DestinationRect, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_DESC& meta_struct = *data;
        FieldToJson(jdata["ModeDesc"], meta_struct.ModeDesc, options);
        FieldToJson(jdata["Rotation"], decoded_value.Rotation, options);
        Bool32ToJson(jdata["DesktopImageInSystemMemory"], decoded_value.DesktopImageInSystemMemory, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_POSITION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_POINTER_POSITION& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_POINTER_POSITION& meta_struct = *data;
        FieldToJson(jdata["Position"], meta_struct.Position, options);
        Bool32ToJson(jdata["Visible"], decoded_value.Visible, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_POINTER_SHAPE_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["Pitch"], decoded_value.Pitch, options);
        FieldToJson(jdata["HotSpot"], meta_struct.HotSpot, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_FRAME_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_FRAME_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_FRAME_INFO& meta_struct = *data;
        FieldToJson(jdata["LastPresentTime"], meta_struct.LastPresentTime, options);
        FieldToJson(jdata["LastMouseUpdateTime"], meta_struct.LastMouseUpdateTime, options);
        FieldToJson(jdata["AccumulatedFrames"], decoded_value.AccumulatedFrames, options);
        Bool32ToJson(jdata["RectsCoalesced"], decoded_value.RectsCoalesced, options);
        Bool32ToJson(jdata["ProtectedContentMaskedOut"], decoded_value.ProtectedContentMaskedOut, options);
        FieldToJson(jdata["PointerPosition"], meta_struct.PointerPosition, options);
        FieldToJson(jdata["TotalMetadataBufferSize"], decoded_value.TotalMetadataBufferSize, options);
        FieldToJson(jdata["PointerShapeBufferSize"], decoded_value.PointerShapeBufferSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MODE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MODE_DESC1& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["RefreshRate"], meta_struct.RefreshRate, options);
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["ScanlineOrdering"], decoded_value.ScanlineOrdering, options);
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options);
        Bool32ToJson(jdata["Stereo"], decoded_value.Stereo, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_DESC1& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        Bool32ToJson(jdata["Stereo"], decoded_value.Stereo, options);
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options);
        FieldToJson(jdata["BufferUsage"], decoded_value.BufferUsage, options);
        FieldToJson(jdata["BufferCount"], decoded_value.BufferCount, options);
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options);
        FieldToJson(jdata["SwapEffect"], decoded_value.SwapEffect, options);
        FieldToJson(jdata["AlphaMode"], decoded_value.AlphaMode, options);
        FieldToJson(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC& meta_struct = *data;
        FieldToJson(jdata["RefreshRate"], meta_struct.RefreshRate, options);
        FieldToJson(jdata["ScanlineOrdering"], decoded_value.ScanlineOrdering, options);
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options);
        Bool32ToJson(jdata["Windowed"], decoded_value.Windowed, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_PRESENT_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_PRESENT_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_PRESENT_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["DirtyRectsCount"], decoded_value.DirtyRectsCount, options);
        FieldToJson(jdata["pDirtyRects"], meta_struct.pDirtyRects, options);
        FieldToJson(jdata["pScrollRect"], meta_struct.pScrollRect, options);
        FieldToJson(jdata["pScrollOffset"], meta_struct.pScrollOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC2& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description, options);
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options);
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options);
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options);
        FieldToJson(jdata["Revision"], decoded_value.Revision, options);
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options);
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options);
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options);
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid, options);
        FieldToJson(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson(jdata["GraphicsPreemptionGranularity"], decoded_value.GraphicsPreemptionGranularity, options);
        FieldToJson(jdata["ComputePreemptionGranularity"], decoded_value.ComputePreemptionGranularity, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MATRIX_3X2_F* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MATRIX_3X2_F& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MATRIX_3X2_F& meta_struct = *data;
        FieldToJson(jdata["_11"], decoded_value._11, options);
        FieldToJson(jdata["_12"], decoded_value._12, options);
        FieldToJson(jdata["_21"], decoded_value._21, options);
        FieldToJson(jdata["_22"], decoded_value._22, options);
        FieldToJson(jdata["_31"], decoded_value._31, options);
        FieldToJson(jdata["_32"], decoded_value._32, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_DECODE_SWAP_CHAIN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC& meta_struct = *data;
        FieldToJson(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS_MEDIA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_FRAME_STATISTICS_MEDIA& decoded_value = *data->decoded_value;
        const Decoded_DXGI_FRAME_STATISTICS_MEDIA& meta_struct = *data;
        FieldToJson(jdata["PresentCount"], decoded_value.PresentCount, options);
        FieldToJson(jdata["PresentRefreshCount"], decoded_value.PresentRefreshCount, options);
        FieldToJson(jdata["SyncRefreshCount"], decoded_value.SyncRefreshCount, options);
        FieldToJson(jdata["SyncQPCTime"], meta_struct.SyncQPCTime, options);
        FieldToJson(jdata["SyncGPUTime"], meta_struct.SyncGPUTime, options);
        FieldToJson(jdata["CompositionMode"], decoded_value.CompositionMode, options);
        FieldToJson(jdata["ApprovedPresentDuration"], decoded_value.ApprovedPresentDuration, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_QUERY_VIDEO_MEMORY_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO& meta_struct = *data;
        FieldToJson(jdata["Budget"], decoded_value.Budget, options);
        FieldToJson(jdata["CurrentUsage"], decoded_value.CurrentUsage, options);
        FieldToJson(jdata["AvailableForReservation"], decoded_value.AvailableForReservation, options);
        FieldToJson(jdata["CurrentReservation"], decoded_value.CurrentReservation, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_HDR_METADATA_HDR10& decoded_value = *data->decoded_value;
        const Decoded_DXGI_HDR_METADATA_HDR10& meta_struct = *data;
        FieldToJson(jdata["RedPrimary"], meta_struct.RedPrimary, options);
        FieldToJson(jdata["GreenPrimary"], meta_struct.GreenPrimary, options);
        FieldToJson(jdata["BluePrimary"], meta_struct.BluePrimary, options);
        FieldToJson(jdata["WhitePoint"], meta_struct.WhitePoint, options);
        FieldToJson(jdata["MaxMasteringLuminance"], decoded_value.MaxMasteringLuminance, options);
        FieldToJson(jdata["MinMasteringLuminance"], decoded_value.MinMasteringLuminance, options);
        FieldToJson(jdata["MaxContentLightLevel"], decoded_value.MaxContentLightLevel, options);
        FieldToJson(jdata["MaxFrameAverageLightLevel"], decoded_value.MaxFrameAverageLightLevel, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10PLUS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_HDR_METADATA_HDR10PLUS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_HDR_METADATA_HDR10PLUS& meta_struct = *data;
        FieldToJson(jdata["Data"], meta_struct.Data, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC3& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC3& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description, options);
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options);
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options);
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options);
        FieldToJson(jdata["Revision"], decoded_value.Revision, options);
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options);
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options);
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options);
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid, options);
        FieldToJson(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson(jdata["GraphicsPreemptionGranularity"], decoded_value.GraphicsPreemptionGranularity, options);
        FieldToJson(jdata["ComputePreemptionGranularity"], decoded_value.ComputePreemptionGranularity, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTPUT_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTPUT_DESC1& meta_struct = *data;
        FieldToJson(jdata["DeviceName"], meta_struct.DeviceName, options);
        FieldToJson(jdata["DesktopCoordinates"], meta_struct.DesktopCoordinates, options);
        Bool32ToJson(jdata["AttachedToDesktop"], decoded_value.AttachedToDesktop, options);
        FieldToJson(jdata["Rotation"], decoded_value.Rotation, options);
        FieldToJson(jdata["Monitor"], meta_struct.Monitor, options);
        FieldToJson(jdata["BitsPerColor"], decoded_value.BitsPerColor, options);
        FieldToJson(jdata["ColorSpace"], decoded_value.ColorSpace, options);
        FieldToJson(jdata["RedPrimary"], meta_struct.RedPrimary, options);
        FieldToJson(jdata["GreenPrimary"], meta_struct.GreenPrimary, options);
        FieldToJson(jdata["BluePrimary"], meta_struct.BluePrimary, options);
        FieldToJson(jdata["WhitePoint"], meta_struct.WhitePoint, options);
        FieldToJson(jdata["MinLuminance"], decoded_value.MinLuminance, options);
        FieldToJson(jdata["MaxLuminance"], decoded_value.MaxLuminance, options);
        FieldToJson(jdata["MaxFullFrameLuminance"], decoded_value.MaxFullFrameLuminance, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RATIONAL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_RATIONAL& decoded_value = *data->decoded_value;
        const Decoded_DXGI_RATIONAL& meta_struct = *data;
        FieldToJson(jdata["Numerator"], decoded_value.Numerator, options);
        FieldToJson(jdata["Denominator"], decoded_value.Denominator, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SAMPLE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SAMPLE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SAMPLE_DESC& meta_struct = *data;
        FieldToJson(jdata["Count"], decoded_value.Count, options);
        FieldToJson(jdata["Quality"], decoded_value.Quality, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RGB* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_RGB& decoded_value = *data->decoded_value;
        const Decoded_DXGI_RGB& meta_struct = *data;
        FieldToJson(jdata["Red"], decoded_value.Red, options);
        FieldToJson(jdata["Green"], decoded_value.Green, options);
        FieldToJson(jdata["Blue"], decoded_value.Blue, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3DCOLORVALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3DCOLORVALUE& decoded_value = *data->decoded_value;
        const Decoded_D3DCOLORVALUE& meta_struct = *data;
        FieldToJson(jdata["r"], decoded_value.r, options);
        FieldToJson(jdata["g"], decoded_value.g, options);
        FieldToJson(jdata["b"], decoded_value.b, options);
        FieldToJson(jdata["a"], decoded_value.a, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_GAMMA_CONTROL& decoded_value = *data->decoded_value;
        const Decoded_DXGI_GAMMA_CONTROL& meta_struct = *data;
        FieldToJson(jdata["Scale"], meta_struct.Scale, options);
        FieldToJson(jdata["Offset"], meta_struct.Offset, options);
        FieldToJson(jdata["GammaCurve"], meta_struct.GammaCurve, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_GAMMA_CONTROL_CAPABILITIES& decoded_value = *data->decoded_value;
        const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES& meta_struct = *data;
        Bool32ToJson(jdata["ScaleAndOffsetSupported"], decoded_value.ScaleAndOffsetSupported, options);
        FieldToJson(jdata["MaxConvertedValue"], decoded_value.MaxConvertedValue, options);
        FieldToJson(jdata["MinConvertedValue"], decoded_value.MinConvertedValue, options);
        FieldToJson(jdata["NumGammaControlPoints"], decoded_value.NumGammaControlPoints, options);
        FieldToJson(jdata["ControlPointPositions"], meta_struct.ControlPointPositions, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MODE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MODE_DESC& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["RefreshRate"], meta_struct.RefreshRate, options);
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["ScanlineOrdering"], decoded_value.ScanlineOrdering, options);
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_DC_HUFFMAN_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE& meta_struct = *data;
        FieldToJson(jdata["CodeCounts"], meta_struct.CodeCounts, options);
        FieldToJson(jdata["CodeValues"], meta_struct.CodeValues, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_AC_HUFFMAN_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE& meta_struct = *data;
        FieldToJson(jdata["CodeCounts"], meta_struct.CodeCounts, options);
        FieldToJson(jdata["CodeValues"], meta_struct.CodeValues, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_QUANTIZATION_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_QUANTIZATION_TABLE& meta_struct = *data;
        FieldToJson(jdata["Elements"], meta_struct.Elements, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMMAND_QUEUE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMMAND_QUEUE_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson(jdata["Priority"], decoded_value.Priority, options);
        FieldToJson_D3D12_COMMAND_QUEUE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INPUT_ELEMENT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INPUT_ELEMENT_DESC& meta_struct = *data;
        FieldToJson(jdata["SemanticName"], meta_struct.SemanticName, options);
        FieldToJson(jdata["SemanticIndex"], decoded_value.SemanticIndex, options);
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["InputSlot"], decoded_value.InputSlot, options);
        FieldToJson(jdata["AlignedByteOffset"], decoded_value.AlignedByteOffset, options);
        FieldToJson(jdata["InputSlotClass"], decoded_value.InputSlotClass, options);
        FieldToJson(jdata["InstanceDataStepRate"], decoded_value.InstanceDataStepRate, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SO_DECLARATION_ENTRY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SO_DECLARATION_ENTRY& meta_struct = *data;
        FieldToJson(jdata["Stream"], decoded_value.Stream, options);
        FieldToJson(jdata["SemanticName"], meta_struct.SemanticName, options);
        FieldToJson(jdata["SemanticIndex"], decoded_value.SemanticIndex, options);
        FieldToJson(jdata["StartComponent"], decoded_value.StartComponent, options);
        FieldToJson(jdata["ComponentCount"], decoded_value.ComponentCount, options);
        FieldToJson(jdata["OutputSlot"], decoded_value.OutputSlot, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEWPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEWPORT& meta_struct = *data;
        FieldToJson(jdata["TopLeftX"], decoded_value.TopLeftX, options);
        FieldToJson(jdata["TopLeftY"], decoded_value.TopLeftY, options);
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["MinDepth"], decoded_value.MinDepth, options);
        FieldToJson(jdata["MaxDepth"], decoded_value.MaxDepth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BOX& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BOX& meta_struct = *data;
        FieldToJson(jdata["left"], decoded_value.left, options);
        FieldToJson(jdata["top"], decoded_value.top, options);
        FieldToJson(jdata["front"], decoded_value.front, options);
        FieldToJson(jdata["right"], decoded_value.right, options);
        FieldToJson(jdata["bottom"], decoded_value.bottom, options);
        FieldToJson(jdata["back"], decoded_value.back, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCILOP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCILOP_DESC& meta_struct = *data;
        FieldToJson(jdata["StencilFailOp"], decoded_value.StencilFailOp, options);
        FieldToJson(jdata["StencilDepthFailOp"], decoded_value.StencilDepthFailOp, options);
        FieldToJson(jdata["StencilPassOp"], decoded_value.StencilPassOp, options);
        FieldToJson(jdata["StencilFunc"], decoded_value.StencilFunc, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC& meta_struct = *data;
        Bool32ToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options);
        FieldToJson(jdata["DepthWriteMask"], decoded_value.DepthWriteMask, options);
        FieldToJson(jdata["DepthFunc"], decoded_value.DepthFunc, options);
        Bool32ToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilReadMask"], decoded_value.StencilReadMask, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options);
        FieldToJson(jdata["FrontFace"], meta_struct.FrontFace, options);
        FieldToJson(jdata["BackFace"], meta_struct.BackFace, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC1& meta_struct = *data;
        Bool32ToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options);
        FieldToJson(jdata["DepthWriteMask"], decoded_value.DepthWriteMask, options);
        FieldToJson(jdata["DepthFunc"], decoded_value.DepthFunc, options);
        Bool32ToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilReadMask"], decoded_value.StencilReadMask, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options);
        FieldToJson(jdata["FrontFace"], meta_struct.FrontFace, options);
        FieldToJson(jdata["BackFace"], meta_struct.BackFace, options);
        Bool32ToJson(jdata["DepthBoundsTestEnable"], decoded_value.DepthBoundsTestEnable, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCILOP_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCILOP_DESC1& meta_struct = *data;
        FieldToJson(jdata["StencilFailOp"], decoded_value.StencilFailOp, options);
        FieldToJson(jdata["StencilDepthFailOp"], decoded_value.StencilDepthFailOp, options);
        FieldToJson(jdata["StencilPassOp"], decoded_value.StencilPassOp, options);
        FieldToJson(jdata["StencilFunc"], decoded_value.StencilFunc, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilReadMask"], decoded_value.StencilReadMask, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC2& meta_struct = *data;
        Bool32ToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options);
        FieldToJson(jdata["DepthWriteMask"], decoded_value.DepthWriteMask, options);
        FieldToJson(jdata["DepthFunc"], decoded_value.DepthFunc, options);
        Bool32ToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options);
        FieldToJson(jdata["FrontFace"], meta_struct.FrontFace, options);
        FieldToJson(jdata["BackFace"], meta_struct.BackFace, options);
        Bool32ToJson(jdata["DepthBoundsTestEnable"], decoded_value.DepthBoundsTestEnable, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_TARGET_BLEND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_TARGET_BLEND_DESC& meta_struct = *data;
        Bool32ToJson(jdata["BlendEnable"], decoded_value.BlendEnable, options);
        Bool32ToJson(jdata["LogicOpEnable"], decoded_value.LogicOpEnable, options);
        FieldToJson(jdata["SrcBlend"], decoded_value.SrcBlend, options);
        FieldToJson(jdata["DestBlend"], decoded_value.DestBlend, options);
        FieldToJson(jdata["BlendOp"], decoded_value.BlendOp, options);
        FieldToJson(jdata["SrcBlendAlpha"], decoded_value.SrcBlendAlpha, options);
        FieldToJson(jdata["DestBlendAlpha"], decoded_value.DestBlendAlpha, options);
        FieldToJson(jdata["BlendOpAlpha"], decoded_value.BlendOpAlpha, options);
        FieldToJson(jdata["LogicOp"], decoded_value.LogicOp, options);
        FieldToJsonAsFixedWidthBinary(jdata["RenderTargetWriteMask"], decoded_value.RenderTargetWriteMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BLEND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BLEND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BLEND_DESC& meta_struct = *data;
        Bool32ToJson(jdata["AlphaToCoverageEnable"], decoded_value.AlphaToCoverageEnable, options);
        Bool32ToJson(jdata["IndependentBlendEnable"], decoded_value.IndependentBlendEnable, options);
        FieldToJson(jdata["RenderTarget"], meta_struct.RenderTarget, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC& meta_struct = *data;
        FieldToJson(jdata["FillMode"], decoded_value.FillMode, options);
        FieldToJson(jdata["CullMode"], decoded_value.CullMode, options);
        Bool32ToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options);
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options);
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options);
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options);
        Bool32ToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options);
        Bool32ToJson(jdata["MultisampleEnable"], decoded_value.MultisampleEnable, options);
        Bool32ToJson(jdata["AntialiasedLineEnable"], decoded_value.AntialiasedLineEnable, options);
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options);
        FieldToJson(jdata["ConservativeRaster"], decoded_value.ConservativeRaster, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC1& meta_struct = *data;
        FieldToJson(jdata["FillMode"], decoded_value.FillMode, options);
        FieldToJson(jdata["CullMode"], decoded_value.CullMode, options);
        Bool32ToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options);
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options);
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options);
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options);
        Bool32ToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options);
        Bool32ToJson(jdata["MultisampleEnable"], decoded_value.MultisampleEnable, options);
        Bool32ToJson(jdata["AntialiasedLineEnable"], decoded_value.AntialiasedLineEnable, options);
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options);
        FieldToJson(jdata["ConservativeRaster"], decoded_value.ConservativeRaster, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC2& meta_struct = *data;
        FieldToJson(jdata["FillMode"], decoded_value.FillMode, options);
        FieldToJson(jdata["CullMode"], decoded_value.CullMode, options);
        Bool32ToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options);
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options);
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options);
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options);
        Bool32ToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options);
        FieldToJson(jdata["LineRasterizationMode"], decoded_value.LineRasterizationMode, options);
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options);
        FieldToJson(jdata["ConservativeRaster"], decoded_value.ConservativeRaster, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_BYTECODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_BYTECODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_BYTECODE& meta_struct = *data;
        static thread_local uint64_t D3D12_SHADER_BYTECODE_pShaderBytecode_counter{ 0 };
        const bool written = RepresentBinaryFile(options, jdata["pShaderBytecode"], "D3D12_SHADER_BYTECODE.pShaderBytecode", D3D12_SHADER_BYTECODE_pShaderBytecode_counter, meta_struct.pShaderBytecode);
        D3D12_SHADER_BYTECODE_pShaderBytecode_counter += written;

        FieldToJson(jdata["BytecodeLength"], decoded_value.BytecodeLength, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STREAM_OUTPUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STREAM_OUTPUT_DESC& meta_struct = *data;
        FieldToJson(jdata["pSODeclaration"], meta_struct.pSODeclaration, options);
        FieldToJson(jdata["NumEntries"], decoded_value.NumEntries, options);
        FieldToJson(jdata["pBufferStrides"], meta_struct.pBufferStrides, options);
        FieldToJson(jdata["NumStrides"], decoded_value.NumStrides, options);
        FieldToJson(jdata["RasterizedStream"], decoded_value.RasterizedStream, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_LAYOUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INPUT_LAYOUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INPUT_LAYOUT_DESC& meta_struct = *data;
        FieldToJson(jdata["pInputElementDescs"], meta_struct.pInputElementDescs, options);
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CACHED_PIPELINE_STATE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CACHED_PIPELINE_STATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CACHED_PIPELINE_STATE& meta_struct = *data;
        FieldToJson(jdata["pCachedBlob"], meta_struct.pCachedBlob, options);
        FieldToJson(jdata["CachedBlobSizeInBytes"], decoded_value.CachedBlobSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GRAPHICS_PIPELINE_STATE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC& meta_struct = *data;
        FieldToJson(jdata["pRootSignature"], meta_struct.pRootSignature, options);
        FieldToJson(jdata["VS"], meta_struct.VS, options);
        FieldToJson(jdata["PS"], meta_struct.PS, options);
        FieldToJson(jdata["DS"], meta_struct.DS, options);
        FieldToJson(jdata["HS"], meta_struct.HS, options);
        FieldToJson(jdata["GS"], meta_struct.GS, options);
        FieldToJson(jdata["StreamOutput"], meta_struct.StreamOutput, options);
        FieldToJson(jdata["BlendState"], meta_struct.BlendState, options);
        FieldToJsonAsFixedWidthBinary(jdata["SampleMask"], decoded_value.SampleMask, options);
        FieldToJson(jdata["RasterizerState"], meta_struct.RasterizerState, options);
        FieldToJson(jdata["DepthStencilState"], meta_struct.DepthStencilState, options);
        FieldToJson(jdata["InputLayout"], meta_struct.InputLayout, options);
        FieldToJson(jdata["IBStripCutValue"], decoded_value.IBStripCutValue, options);
        FieldToJson(jdata["PrimitiveTopologyType"], decoded_value.PrimitiveTopologyType, options);
        FieldToJson(jdata["NumRenderTargets"], decoded_value.NumRenderTargets, options);
        FieldToJson(jdata["RTVFormats"], meta_struct.RTVFormats, options);
        FieldToJson(jdata["DSVFormat"], decoded_value.DSVFormat, options);
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask, options);
        FieldToJson(jdata["CachedPSO"], meta_struct.CachedPSO, options);
        FieldToJson_D3D12_PIPELINE_STATE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMPUTE_PIPELINE_STATE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC& meta_struct = *data;
        FieldToJson(jdata["pRootSignature"], meta_struct.pRootSignature, options);
        FieldToJson(jdata["CS"], meta_struct.CS, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask, options);
        FieldToJson(jdata["CachedPSO"], meta_struct.CachedPSO, options);
        FieldToJson_D3D12_PIPELINE_STATE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RT_FORMAT_ARRAY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RT_FORMAT_ARRAY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RT_FORMAT_ARRAY& meta_struct = *data;
        FieldToJson(jdata["RTFormats"], meta_struct.RTFormats, options);
        FieldToJson(jdata["NumRenderTargets"], decoded_value.NumRenderTargets, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS& meta_struct = *data;
        Bool32ToJson(jdata["DoublePrecisionFloatShaderOps"], decoded_value.DoublePrecisionFloatShaderOps, options);
        Bool32ToJson(jdata["OutputMergerLogicOp"], decoded_value.OutputMergerLogicOp, options);
        FieldToJson_D3D12_SHADER_MIN_PRECISION_SUPPORT(jdata["MinPrecisionSupport"], decoded_value.MinPrecisionSupport, options);
        FieldToJson(jdata["TiledResourcesTier"], decoded_value.TiledResourcesTier, options);
        FieldToJson(jdata["ResourceBindingTier"], decoded_value.ResourceBindingTier, options);
        Bool32ToJson(jdata["PSSpecifiedStencilRefSupported"], decoded_value.PSSpecifiedStencilRefSupported, options);
        Bool32ToJson(jdata["TypedUAVLoadAdditionalFormats"], decoded_value.TypedUAVLoadAdditionalFormats, options);
        Bool32ToJson(jdata["ROVsSupported"], decoded_value.ROVsSupported, options);
        FieldToJson(jdata["ConservativeRasterizationTier"], decoded_value.ConservativeRasterizationTier, options);
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], decoded_value.MaxGPUVirtualAddressBitsPerResource, options);
        Bool32ToJson(jdata["StandardSwizzle64KBSupported"], decoded_value.StandardSwizzle64KBSupported, options);
        FieldToJson(jdata["CrossNodeSharingTier"], decoded_value.CrossNodeSharingTier, options);
        Bool32ToJson(jdata["CrossAdapterRowMajorTextureSupported"], decoded_value.CrossAdapterRowMajorTextureSupported, options);
        Bool32ToJson(jdata["VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation"], decoded_value.VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation, options);
        FieldToJson(jdata["ResourceHeapTier"], decoded_value.ResourceHeapTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1& meta_struct = *data;
        Bool32ToJson(jdata["WaveOps"], decoded_value.WaveOps, options);
        FieldToJson(jdata["WaveLaneCountMin"], decoded_value.WaveLaneCountMin, options);
        FieldToJson(jdata["WaveLaneCountMax"], decoded_value.WaveLaneCountMax, options);
        FieldToJson(jdata["TotalLaneCount"], decoded_value.TotalLaneCount, options);
        Bool32ToJson(jdata["ExpandedComputeResourceStates"], decoded_value.ExpandedComputeResourceStates, options);
        Bool32ToJson(jdata["Int64ShaderOps"], decoded_value.Int64ShaderOps, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2& meta_struct = *data;
        Bool32ToJson(jdata["DepthBoundsTestSupported"], decoded_value.DepthBoundsTestSupported, options);
        FieldToJson(jdata["ProgrammableSamplePositionsTier"], decoded_value.ProgrammableSamplePositionsTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE& meta_struct = *data;
        FieldToJson(jdata["HighestVersion"], decoded_value.HighestVersion, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ARCHITECTURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options);
        Bool32ToJson(jdata["TileBasedRenderer"], decoded_value.TileBasedRenderer, options);
        Bool32ToJson(jdata["UMA"], decoded_value.UMA, options);
        Bool32ToJson(jdata["CacheCoherentUMA"], decoded_value.CacheCoherentUMA, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ARCHITECTURE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options);
        Bool32ToJson(jdata["TileBasedRenderer"], decoded_value.TileBasedRenderer, options);
        Bool32ToJson(jdata["UMA"], decoded_value.UMA, options);
        Bool32ToJson(jdata["CacheCoherentUMA"], decoded_value.CacheCoherentUMA, options);
        Bool32ToJson(jdata["IsolatedMMU"], decoded_value.IsolatedMMU, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FEATURE_LEVELS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS& meta_struct = *data;
        FieldToJson(jdata["NumFeatureLevels"], decoded_value.NumFeatureLevels, options);
        FieldToJson(jdata["pFeatureLevelsRequested"], meta_struct.pFeatureLevelsRequested, options);
        FieldToJson(jdata["MaxSupportedFeatureLevel"], decoded_value.MaxSupportedFeatureLevel, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADER_MODEL& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL& meta_struct = *data;
        FieldToJson(jdata["HighestShaderModel"], decoded_value.HighestShaderModel, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FORMAT_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson_D3D12_FORMAT_SUPPORT1(jdata["Support1"], decoded_value.Support1, options);
        FieldToJson_D3D12_FORMAT_SUPPORT2(jdata["Support2"], decoded_value.Support2, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["SampleCount"], decoded_value.SampleCount, options);
        FieldToJson_D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson(jdata["NumQualityLevels"], decoded_value.NumQualityLevels, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FORMAT_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["PlaneCount"], decoded_value.PlaneCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], decoded_value.MaxGPUVirtualAddressBitsPerResource, options);
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerProcess"], decoded_value.MaxGPUVirtualAddressBitsPerProcess, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADER_CACHE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE& meta_struct = *data;
        FieldToJson_D3D12_SHADER_CACHE_SUPPORT_FLAGS(jdata["SupportFlags"], decoded_value.SupportFlags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& meta_struct = *data;
        FieldToJson(jdata["CommandListType"], decoded_value.CommandListType, options);
        FieldToJson(jdata["Priority"], decoded_value.Priority, options);
        Bool32ToJson(jdata["PriorityForTypeIsSupported"], decoded_value.PriorityForTypeIsSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS3& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3& meta_struct = *data;
        Bool32ToJson(jdata["CopyQueueTimestampQueriesSupported"], decoded_value.CopyQueueTimestampQueriesSupported, options);
        Bool32ToJson(jdata["CastingFullyTypedFormatSupported"], decoded_value.CastingFullyTypedFormatSupported, options);
        FieldToJson_D3D12_COMMAND_LIST_SUPPORT_FLAGS(jdata["WriteBufferImmediateSupportFlags"], decoded_value.WriteBufferImmediateSupportFlags, options);
        FieldToJson(jdata["ViewInstancingTier"], decoded_value.ViewInstancingTier, options);
        Bool32ToJson(jdata["BarycentricsSupported"], decoded_value.BarycentricsSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_EXISTING_HEAPS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS& meta_struct = *data;
        Bool32ToJson(jdata["Supported"], decoded_value.Supported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_DISPLAYABLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE& meta_struct = *data;
        Bool32ToJson(jdata["DisplayableTexture"], decoded_value.DisplayableTexture, options);
        FieldToJson(jdata["SharedResourceCompatibilityTier"], decoded_value.SharedResourceCompatibilityTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS4& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4& meta_struct = *data;
        Bool32ToJson(jdata["MSAA64KBAlignedTextureSupported"], decoded_value.MSAA64KBAlignedTextureSupported, options);
        FieldToJson(jdata["SharedResourceCompatibilityTier"], decoded_value.SharedResourceCompatibilityTier, options);
        Bool32ToJson(jdata["Native16BitShaderOpsSupported"], decoded_value.Native16BitShaderOpsSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SERIALIZATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SERIALIZATION& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options);
        FieldToJson(jdata["HeapSerializationTier"], decoded_value.HeapSerializationTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_CROSS_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_CROSS_NODE& meta_struct = *data;
        FieldToJson(jdata["SharingTier"], decoded_value.SharingTier, options);
        Bool32ToJson(jdata["AtomicShaderInstructions"], decoded_value.AtomicShaderInstructions, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS5& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5& meta_struct = *data;
        Bool32ToJson(jdata["SRVOnlyTiledResourceTier3"], decoded_value.SRVOnlyTiledResourceTier3, options);
        FieldToJson(jdata["RenderPassesTier"], decoded_value.RenderPassesTier, options);
        FieldToJson(jdata["RaytracingTier"], decoded_value.RaytracingTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS6& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6& meta_struct = *data;
        Bool32ToJson(jdata["AdditionalShadingRatesSupported"], decoded_value.AdditionalShadingRatesSupported, options);
        Bool32ToJson(jdata["PerPrimitiveShadingRateSupportedWithViewportIndexing"], decoded_value.PerPrimitiveShadingRateSupportedWithViewportIndexing, options);
        FieldToJson(jdata["VariableShadingRateTier"], decoded_value.VariableShadingRateTier, options);
        FieldToJson(jdata["ShadingRateImageTileSize"], decoded_value.ShadingRateImageTileSize, options);
        Bool32ToJson(jdata["BackgroundProcessingSupported"], decoded_value.BackgroundProcessingSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS7& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7& meta_struct = *data;
        FieldToJson(jdata["MeshShaderTier"], decoded_value.MeshShaderTier, options);
        FieldToJson(jdata["SamplerFeedbackTier"], decoded_value.SamplerFeedbackTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_QUERY_META_COMMAND& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND& meta_struct = *data;
        FieldToJson(jdata["CommandId"], meta_struct.CommandId, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask, options);
        FieldToJson(jdata["pQueryInputData"], meta_struct.pQueryInputData, options);
        FieldToJson(jdata["QueryInputDataSizeInBytes"], decoded_value.QueryInputDataSizeInBytes, options);
        FieldToJson(jdata["pQueryOutputData"], meta_struct.pQueryOutputData, options);
        FieldToJson(jdata["QueryOutputDataSizeInBytes"], decoded_value.QueryOutputDataSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS8& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8& meta_struct = *data;
        Bool32ToJson(jdata["UnalignedBlockTexturesSupported"], decoded_value.UnalignedBlockTexturesSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS9& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9& meta_struct = *data;
        Bool32ToJson(jdata["MeshShaderPipelineStatsSupported"], decoded_value.MeshShaderPipelineStatsSupported, options);
        Bool32ToJson(jdata["MeshShaderSupportsFullRangeRenderTargetArrayIndex"], decoded_value.MeshShaderSupportsFullRangeRenderTargetArrayIndex, options);
        Bool32ToJson(jdata["AtomicInt64OnTypedResourceSupported"], decoded_value.AtomicInt64OnTypedResourceSupported, options);
        Bool32ToJson(jdata["AtomicInt64OnGroupSharedSupported"], decoded_value.AtomicInt64OnGroupSharedSupported, options);
        Bool32ToJson(jdata["DerivativesInMeshAndAmplificationShadersSupported"], decoded_value.DerivativesInMeshAndAmplificationShadersSupported, options);
        FieldToJson(jdata["WaveMMATier"], decoded_value.WaveMMATier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS10& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10& meta_struct = *data;
        Bool32ToJson(jdata["VariableRateShadingSumCombinerSupported"], decoded_value.VariableRateShadingSumCombinerSupported, options);
        Bool32ToJson(jdata["MeshShaderPerPrimitiveShadingRateSupported"], decoded_value.MeshShaderPerPrimitiveShadingRateSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS11& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11& meta_struct = *data;
        Bool32ToJson(jdata["AtomicInt64OnDescriptorHeapResourceSupported"], decoded_value.AtomicInt64OnDescriptorHeapResourceSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS12& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12& meta_struct = *data;
        FieldToJson(jdata["MSPrimitivesPipelineStatisticIncludesCulledPrimitives"], decoded_value.MSPrimitivesPipelineStatisticIncludesCulledPrimitives, options);
        Bool32ToJson(jdata["EnhancedBarriersSupported"], decoded_value.EnhancedBarriersSupported, options);
        Bool32ToJson(jdata["RelaxedFormatCastingSupported"], decoded_value.RelaxedFormatCastingSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS13& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13& meta_struct = *data;
        Bool32ToJson(jdata["UnrestrictedBufferTextureCopyPitchSupported"], decoded_value.UnrestrictedBufferTextureCopyPitchSupported, options);
        Bool32ToJson(jdata["UnrestrictedVertexElementAlignmentSupported"], decoded_value.UnrestrictedVertexElementAlignmentSupported, options);
        Bool32ToJson(jdata["InvertedViewportHeightFlipsYSupported"], decoded_value.InvertedViewportHeightFlipsYSupported, options);
        Bool32ToJson(jdata["InvertedViewportDepthFlipsZSupported"], decoded_value.InvertedViewportDepthFlipsZSupported, options);
        Bool32ToJson(jdata["TextureCopyBetweenDimensionsSupported"], decoded_value.TextureCopyBetweenDimensionsSupported, options);
        Bool32ToJson(jdata["AlphaBlendFactorSupported"], decoded_value.AlphaBlendFactorSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS14& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14& meta_struct = *data;
        Bool32ToJson(jdata["AdvancedTextureOpsSupported"], decoded_value.AdvancedTextureOpsSupported, options);
        Bool32ToJson(jdata["WriteableMSAATexturesSupported"], decoded_value.WriteableMSAATexturesSupported, options);
        Bool32ToJson(jdata["IndependentFrontAndBackStencilRefMaskSupported"], decoded_value.IndependentFrontAndBackStencilRefMaskSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS15& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15& meta_struct = *data;
        Bool32ToJson(jdata["TriangleFanSupported"], decoded_value.TriangleFanSupported, options);
        Bool32ToJson(jdata["DynamicIndexBufferStripCutSupported"], decoded_value.DynamicIndexBufferStripCutSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS16& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16& meta_struct = *data;
        Bool32ToJson(jdata["DynamicDepthBiasSupported"], decoded_value.DynamicDepthBiasSupported, options);
        Bool32ToJson(jdata["GPUUploadHeapSupported"], decoded_value.GPUUploadHeapSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS17& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17& meta_struct = *data;
        Bool32ToJson(jdata["NonNormalizedCoordinateSamplersSupported"], decoded_value.NonNormalizedCoordinateSamplersSupported, options);
        Bool32ToJson(jdata["ManualWriteTrackingResourceSupported"], decoded_value.ManualWriteTrackingResourceSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS18& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18& meta_struct = *data;
        Bool32ToJson(jdata["RenderPassesValid"], decoded_value.RenderPassesValid, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS19& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19& meta_struct = *data;
        Bool32ToJson(jdata["MismatchingOutputDimensionsSupported"], decoded_value.MismatchingOutputDimensionsSupported, options);
        FieldToJson(jdata["SupportedSampleCountsWithNoOutputs"], decoded_value.SupportedSampleCountsWithNoOutputs, options);
        Bool32ToJson(jdata["PointSamplingAddressesNeverRoundUp"], decoded_value.PointSamplingAddressesNeverRoundUp, options);
        Bool32ToJson(jdata["RasterizerDesc2Supported"], decoded_value.RasterizerDesc2Supported, options);
        Bool32ToJson(jdata["NarrowQuadrilateralLinesSupported"], decoded_value.NarrowQuadrilateralLinesSupported, options);
        Bool32ToJson(jdata["AnisoFilterWithPointMipSupported"], decoded_value.AnisoFilterWithPointMipSupported, options);
        FieldToJson(jdata["MaxSamplerDescriptorHeapSize"], decoded_value.MaxSamplerDescriptorHeapSize, options);
        FieldToJson(jdata["MaxSamplerDescriptorHeapSizeWithStaticSamplers"], decoded_value.MaxSamplerDescriptorHeapSizeWithStaticSamplers, options);
        FieldToJson(jdata["MaxViewDescriptorHeapSize"], decoded_value.MaxViewDescriptorHeapSize, options);
        Bool32ToJson(jdata["ComputeOnlyCustomHeapSupported"], decoded_value.ComputeOnlyCustomHeapSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALLOCATION_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALLOCATION_INFO& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options);
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALLOCATION_INFO1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options);
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options);
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HEAP_PROPERTIES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HEAP_PROPERTIES& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson(jdata["CPUPageProperty"], decoded_value.CPUPageProperty, options);
        FieldToJson(jdata["MemoryPoolPreference"], decoded_value.MemoryPoolPreference, options);
        FieldToJsonAsFixedWidthBinary(jdata["CreationNodeMask"], decoded_value.CreationNodeMask, options);
        FieldToJsonAsFixedWidthBinary(jdata["VisibleNodeMask"], decoded_value.VisibleNodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HEAP_DESC& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options);
        FieldToJson(jdata["Properties"], meta_struct.Properties, options);
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options);
        FieldToJson_D3D12_HEAP_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MIP_REGION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MIP_REGION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MIP_REGION& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["Depth"], decoded_value.Depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_DESC& meta_struct = *data;
        FieldToJson(jdata["Dimension"], decoded_value.Dimension, options);
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options);
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["DepthOrArraySize"], decoded_value.DepthOrArraySize, options);
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options);
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options);
        FieldToJson(jdata["Layout"], decoded_value.Layout, options);
        FieldToJson_D3D12_RESOURCE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_DESC1& meta_struct = *data;
        FieldToJson(jdata["Dimension"], decoded_value.Dimension, options);
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options);
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["DepthOrArraySize"], decoded_value.DepthOrArraySize, options);
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options);
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options);
        FieldToJson(jdata["Layout"], decoded_value.Layout, options);
        FieldToJson_D3D12_RESOURCE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson(jdata["SamplerFeedbackMipRegion"], meta_struct.SamplerFeedbackMipRegion, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_VALUE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_VALUE& meta_struct = *data;
        FieldToJson(jdata["Depth"], decoded_value.Depth, options);
        FieldToJson(jdata["Stencil"], decoded_value.Stencil, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CLEAR_VALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CLEAR_VALUE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CLEAR_VALUE& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        if(graphics::dx12::IsDepthStencilFormat(decoded_value.Format))
        {
            FieldToJson(jdata["DepthStencil"], decoded_value.DepthStencil, options);
        }
        else
        {
            FieldToJson(jdata["Color"], decoded_value.Color, options);
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RANGE& meta_struct = *data;
        FieldToJson(jdata["Begin"], decoded_value.Begin, options);
        FieldToJson(jdata["End"], decoded_value.End, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE_UINT64* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RANGE_UINT64& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RANGE_UINT64& meta_struct = *data;
        FieldToJson(jdata["Begin"], decoded_value.Begin, options);
        FieldToJson(jdata["End"], decoded_value.End, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_RANGE_UINT64& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64& meta_struct = *data;
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options);
        FieldToJson(jdata["Range"], meta_struct.Range, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_INFO& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options);
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options);
        FieldToJson(jdata["DepthPitch"], decoded_value.DepthPitch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILED_RESOURCE_COORDINATE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILED_RESOURCE_COORDINATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILED_RESOURCE_COORDINATE& meta_struct = *data;
        FieldToJson(jdata["X"], decoded_value.X, options);
        FieldToJson(jdata["Y"], decoded_value.Y, options);
        FieldToJson(jdata["Z"], decoded_value.Z, options);
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_REGION_SIZE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILE_REGION_SIZE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILE_REGION_SIZE& meta_struct = *data;
        FieldToJson(jdata["NumTiles"], decoded_value.NumTiles, options);
        Bool32ToJson(jdata["UseBox"], decoded_value.UseBox, options);
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["Depth"], decoded_value.Depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_TILING* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_TILING& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_TILING& meta_struct = *data;
        FieldToJson(jdata["WidthInTiles"], decoded_value.WidthInTiles, options);
        FieldToJson(jdata["HeightInTiles"], decoded_value.HeightInTiles, options);
        FieldToJson(jdata["DepthInTiles"], decoded_value.DepthInTiles, options);
        FieldToJson(jdata["StartTileIndexInOverallResource"], decoded_value.StartTileIndexInOverallResource, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_SHAPE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILE_SHAPE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILE_SHAPE& meta_struct = *data;
        FieldToJson(jdata["WidthInTexels"], decoded_value.WidthInTexels, options);
        FieldToJson(jdata["HeightInTexels"], decoded_value.HeightInTexels, options);
        FieldToJson(jdata["DepthInTexels"], decoded_value.DepthInTexels, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PACKED_MIP_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PACKED_MIP_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PACKED_MIP_INFO& meta_struct = *data;
        FieldToJson(jdata["NumStandardMips"], decoded_value.NumStandardMips, options);
        FieldToJson(jdata["NumPackedMips"], decoded_value.NumPackedMips, options);
        FieldToJson(jdata["NumTilesForPackedMips"], decoded_value.NumTilesForPackedMips, options);
        FieldToJson(jdata["StartTileIndexInOverallResource"], decoded_value.StartTileIndexInOverallResource, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_TRANSITION_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER& meta_struct = *data;
        FieldToJson(jdata["pResource"], meta_struct.pResource, options);
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options);
        FieldToJson_D3D12_RESOURCE_STATES(jdata["StateBefore"], decoded_value.StateBefore, options);
        FieldToJson_D3D12_RESOURCE_STATES(jdata["StateAfter"], decoded_value.StateAfter, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALIASING_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALIASING_BARRIER& meta_struct = *data;
        FieldToJson(jdata["pResourceBefore"], meta_struct.pResourceBefore, options);
        FieldToJson(jdata["pResourceAfter"], meta_struct.pResourceAfter, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_UAV_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_UAV_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_UAV_BARRIER& meta_struct = *data;
        FieldToJson(jdata["pResource"], meta_struct.pResource, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_BARRIER& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson_D3D12_RESOURCE_BARRIER_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        switch(decoded_value.Type)
        {
            case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
            {
                FieldToJson(jdata["Transition"], meta_struct.Transition, options);
                break;
            }
            case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
            {
                FieldToJson(jdata["Aliasing"], meta_struct.Aliasing, options);
                break;
            }
            case D3D12_RESOURCE_BARRIER_TYPE_UAV:
            {
                FieldToJson(jdata["UAV"], meta_struct.UAV, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RESOURCE_BARRIER_TYPE in D3D12_RESOURCE_BARRIER.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_FOOTPRINT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_FOOTPRINT& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["Depth"], decoded_value.Depth, options);
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options);
        FieldToJson(jdata["Footprint"], meta_struct.Footprint, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_COPY_LOCATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXTURE_COPY_LOCATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXTURE_COPY_LOCATION& meta_struct = *data;
        FieldToJson(jdata["pResource"], meta_struct.pResource, options);
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        switch(decoded_value.Type)
        {
            case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:
            {
                FieldToJson(jdata["SubresourceIndex"], decoded_value.SubresourceIndex, options);
                break;
            }
            case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:
            {
                FieldToJson(jdata["PlacedFootprint"], meta_struct.PlacedFootprint, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_TEXTURE_COPY_TYPE in D3D12_TEXTURE_COPY_LOCATION.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_POSITION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLE_POSITION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLE_POSITION& meta_struct = *data;
        FieldToJson(jdata["X"], decoded_value.X, options);
        FieldToJson(jdata["Y"], decoded_value.Y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCE_LOCATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEW_INSTANCE_LOCATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEW_INSTANCE_LOCATION& meta_struct = *data;
        FieldToJson(jdata["ViewportArrayIndex"], decoded_value.ViewportArrayIndex, options);
        FieldToJson(jdata["RenderTargetArrayIndex"], decoded_value.RenderTargetArrayIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCING_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEW_INSTANCING_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEW_INSTANCING_DESC& meta_struct = *data;
        FieldToJson(jdata["ViewInstanceCount"], decoded_value.ViewInstanceCount, options);
        FieldToJson(jdata["pViewInstanceLocations"], meta_struct.pViewInstanceLocations, options);
        FieldToJson_D3D12_VIEW_INSTANCING_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_SRV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options);
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options);
        FieldToJson(jdata["StructureByteStride"], decoded_value.StructureByteStride, options);
        FieldToJson_D3D12_BUFFER_SRV_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options);
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options);
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options);
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options);
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options);
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options);
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options);
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXCUBE_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXCUBE_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options);
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXCUBE_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXCUBE_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options);
        FieldToJson(jdata["First2DArrayFace"], decoded_value.First2DArrayFace, options);
        FieldToJson(jdata["NumCubes"], decoded_value.NumCubes, options);
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_SRV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& meta_struct = *data;
        FieldToJsonAsHex(jdata["Location"], decoded_value.Location, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_RESOURCE_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options);
        FieldToJson(jdata["Shader4ComponentMapping"], decoded_value.Shader4ComponentMapping, options);
        switch(decoded_value.ViewDimension)
        {
            case D3D12_SRV_DIMENSION_BUFFER:
            {
                FieldToJson(jdata["Buffer"], meta_struct.Buffer, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE3D:
            {
                FieldToJson(jdata["Texture3D"], meta_struct.Texture3D, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURECUBE:
            {
                FieldToJson(jdata["TextureCube"], meta_struct.TextureCube, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
            {
                FieldToJson(jdata["TextureCubeArray"], meta_struct.TextureCubeArray, options);
                break;
            }
            case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
            {
                FieldToJson(jdata["RaytracingAccelerationStructure"], meta_struct.RaytracingAccelerationStructure, options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CONSTANT_BUFFER_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC& meta_struct = *data;
        FieldToJsonAsHex(jdata["BufferLocation"], decoded_value.BufferLocation, options);
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLER_DESC& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options);
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options);
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options);
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options);
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options);
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options);
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options);
        FieldToJson(jdata["BorderColor"], meta_struct.BorderColor, options);
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options);
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLER_DESC2& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options);
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options);
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options);
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options);
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options);
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options);
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options);
        if(decoded_value.Flags & D3D12_SAMPLER_FLAG_UINT_BORDER_COLOR)
        {
            FieldToJson(jdata["UintBorderColor"], decoded_value.UintBorderColor, options);
        }
        else
        {
            FieldToJson(jdata["FloatBorderColor"], decoded_value.FloatBorderColor, options);
        }
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options);
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options);
        FieldToJson_D3D12_SAMPLER_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_UAV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options);
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options);
        FieldToJson(jdata["StructureByteStride"], decoded_value.StructureByteStride, options);
        FieldToJson(jdata["CounterOffsetInBytes"], decoded_value.CounterOffsetInBytes, options);
        FieldToJson_D3D12_BUFFER_UAV_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_UAV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
        FieldToJson(jdata["FirstWSlice"], decoded_value.FirstWSlice, options);
        FieldToJson(jdata["WSize"], decoded_value.WSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_UNORDERED_ACCESS_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options);
        switch(decoded_value.ViewDimension)
        {
            case D3D12_UAV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero-valued ViewDimension is meaningless. Is struct corrupted?", options);
                break;
            }
            case D3D12_UAV_DIMENSION_BUFFER:
            {
                FieldToJson(jdata["Buffer"], meta_struct.Buffer, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE3D:
            {
                FieldToJson(jdata["Texture3D"], meta_struct.Texture3D, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "ViewDimension with unknown value. Is struct corrupted?", options);
                FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ViewDimension), options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_RTV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options);
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_RTV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
        FieldToJson(jdata["FirstWSlice"], decoded_value.FirstWSlice, options);
        FieldToJson(jdata["WSize"], decoded_value.WSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_TARGET_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_TARGET_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options);
        switch(decoded_value.ViewDimension)
        {
            case D3D12_RTV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC.", options);
                break;
            }
            case D3D12_RTV_DIMENSION_BUFFER:
            {
                FieldToJson(jdata["Buffer"], meta_struct.Buffer, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE3D:
            {
                FieldToJson(jdata["Texture3D"], meta_struct.Texture3D, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC. Corrupt struct?", options);
                FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ViewDimension), options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_DSV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options);
        FieldToJson_D3D12_DSV_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        switch(decoded_value.ViewDimension)
        {
            case D3D12_DSV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero D3D12_DSV_DIMENSION in D3D12_DEPTH_STENCIL_VIEW_DESC.", options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DSV_DIMENSION in D3D12_DEPTH_STENCIL_VIEW_DESC. Corrupt struct?", options);
                FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ViewDimension), options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_HEAP_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options);
        FieldToJson_D3D12_DESCRIPTOR_HEAP_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_RANGE& meta_struct = *data;
        FieldToJson(jdata["RangeType"], decoded_value.RangeType, options);
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options);
        FieldToJson(jdata["BaseShaderRegister"], decoded_value.BaseShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options);
        FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], decoded_value.OffsetInDescriptorsFromTableStart, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR_TABLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE& meta_struct = *data;
        FieldToJson(jdata["NumDescriptorRanges"], decoded_value.NumDescriptorRanges, options);
        FieldToJson(jdata["pDescriptorRanges"], meta_struct.pDescriptorRanges, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_CONSTANTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_CONSTANTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_CONSTANTS& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options);
        FieldToJson(jdata["Num32BitValues"], decoded_value.Num32BitValues, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_PARAMETER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_PARAMETER& meta_struct = *data;
        FieldToJson(jdata["ParameterType"], decoded_value.ParameterType, options);
        switch(decoded_value.ParameterType)
        {
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                FieldToJson(jdata["DescriptorTable"], meta_struct.DescriptorTable, options);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            {
                FieldToJson(jdata["Constants"], meta_struct.Constants, options);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            {
                FieldToJson(jdata["Descriptor"], meta_struct.Descriptor, options);
                break;
            }
        }
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATIC_SAMPLER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATIC_SAMPLER_DESC& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options);
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options);
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options);
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options);
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options);
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options);
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options);
        FieldToJson(jdata["BorderColor"], decoded_value.BorderColor, options);
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options);
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options);
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options);
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATIC_SAMPLER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATIC_SAMPLER_DESC1& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options);
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options);
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options);
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options);
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options);
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options);
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options);
        FieldToJson(jdata["BorderColor"], decoded_value.BorderColor, options);
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options);
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options);
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options);
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options);
        FieldToJson_D3D12_SAMPLER_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options);
        FieldToJson(jdata["pParameters"], meta_struct.pParameters, options);
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options);
        FieldToJson(jdata["pStaticSamplers"], meta_struct.pStaticSamplers, options);
        FieldToJson_D3D12_ROOT_SIGNATURE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_RANGE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_RANGE1& meta_struct = *data;
        FieldToJson(jdata["RangeType"], decoded_value.RangeType, options);
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options);
        FieldToJson(jdata["BaseShaderRegister"], decoded_value.BaseShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options);
        FieldToJson_D3D12_DESCRIPTOR_RANGE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], decoded_value.OffsetInDescriptorsFromTableStart, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR_TABLE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1& meta_struct = *data;
        FieldToJson(jdata["NumDescriptorRanges"], decoded_value.NumDescriptorRanges, options);
        FieldToJson(jdata["pDescriptorRanges"], meta_struct.pDescriptorRanges, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR1& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options);
        FieldToJson_D3D12_ROOT_DESCRIPTOR_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_PARAMETER1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_PARAMETER1& meta_struct = *data;
        FieldToJson(jdata["ParameterType"], decoded_value.ParameterType, options);
        switch (decoded_value.ParameterType)
        {
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                FieldToJson(jdata["DescriptorTable"], meta_struct.DescriptorTable, options);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            {
                FieldToJson(jdata["Constants"], meta_struct.Constants, options);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            {
                FieldToJson(jdata["Descriptor"], meta_struct.Descriptor, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_ROOT_PARAMETER_TYPE in D3D12_ROOT_PARAMETER1.", options);
                FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ParameterType), options);
                break;
            }
        }
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC1& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options);
        FieldToJson(jdata["pParameters"], meta_struct.pParameters, options);
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options);
        FieldToJson(jdata["pStaticSamplers"], meta_struct.pStaticSamplers, options);
        FieldToJson_D3D12_ROOT_SIGNATURE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC2& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options);
        FieldToJson(jdata["pParameters"], meta_struct.pParameters, options);
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options);
        FieldToJson(jdata["pStaticSamplers"], meta_struct.pStaticSamplers, options);
        FieldToJson_D3D12_ROOT_SIGNATURE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["Version"], decoded_value.Version, options);
        switch (decoded_value.Version)
        {
            case D3D_ROOT_SIGNATURE_VERSION_1_0:
            {
                FieldToJson(jdata["Desc_1_0"], meta_struct.Desc_1_0, options);
                break;
            }
            case D3D_ROOT_SIGNATURE_VERSION_1_1:
            {
                FieldToJson(jdata["Desc_1_1"], meta_struct.Desc_1_1, options);
                break;
            }
            case D3D_ROOT_SIGNATURE_VERSION_1_2:
            {
                FieldToJson(jdata["Desc_1_2"], meta_struct.Desc_1_2, options);
                GFXRECON_LOG_ERROR("Unknown D3D_ROOT_SIGNATURE_VERSION_1_2 in D3D12_VERSIONED_ROOT_SIGNATURE_DESC.");
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D_ROOT_SIGNATURE_VERSION in D3D12_VERSIONED_ROOT_SIGNATURE_DESC.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_DESCRIPTOR_HANDLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE& meta_struct = *data;
        FieldToJson(jdata["ptr"], decoded_value.ptr, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISCARD_REGION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISCARD_REGION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISCARD_REGION& meta_struct = *data;
        FieldToJson(jdata["NumRects"], decoded_value.NumRects, options);
        FieldToJson(jdata["pRects"], meta_struct.pRects, options);
        FieldToJson(jdata["FirstSubresource"], decoded_value.FirstSubresource, options);
        FieldToJson(jdata["NumSubresources"], decoded_value.NumSubresources, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_HEAP_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson(jdata["Count"], decoded_value.Count, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_PIPELINE_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["IAVertices"], decoded_value.IAVertices, options);
        FieldToJson(jdata["IAPrimitives"], decoded_value.IAPrimitives, options);
        FieldToJson(jdata["VSInvocations"], decoded_value.VSInvocations, options);
        FieldToJson(jdata["GSInvocations"], decoded_value.GSInvocations, options);
        FieldToJson(jdata["GSPrimitives"], decoded_value.GSPrimitives, options);
        FieldToJson(jdata["CInvocations"], decoded_value.CInvocations, options);
        FieldToJson(jdata["CPrimitives"], decoded_value.CPrimitives, options);
        FieldToJson(jdata["PSInvocations"], decoded_value.PSInvocations, options);
        FieldToJson(jdata["HSInvocations"], decoded_value.HSInvocations, options);
        FieldToJson(jdata["DSInvocations"], decoded_value.DSInvocations, options);
        FieldToJson(jdata["CSInvocations"], decoded_value.CSInvocations, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1& meta_struct = *data;
        FieldToJson(jdata["IAVertices"], decoded_value.IAVertices, options);
        FieldToJson(jdata["IAPrimitives"], decoded_value.IAPrimitives, options);
        FieldToJson(jdata["VSInvocations"], decoded_value.VSInvocations, options);
        FieldToJson(jdata["GSInvocations"], decoded_value.GSInvocations, options);
        FieldToJson(jdata["GSPrimitives"], decoded_value.GSPrimitives, options);
        FieldToJson(jdata["CInvocations"], decoded_value.CInvocations, options);
        FieldToJson(jdata["CPrimitives"], decoded_value.CPrimitives, options);
        FieldToJson(jdata["PSInvocations"], decoded_value.PSInvocations, options);
        FieldToJson(jdata["HSInvocations"], decoded_value.HSInvocations, options);
        FieldToJson(jdata["DSInvocations"], decoded_value.DSInvocations, options);
        FieldToJson(jdata["CSInvocations"], decoded_value.CSInvocations, options);
        FieldToJson(jdata["ASInvocations"], decoded_value.ASInvocations, options);
        FieldToJson(jdata["MSInvocations"], decoded_value.MSInvocations, options);
        FieldToJson(jdata["MSPrimitives"], decoded_value.MSPrimitives, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_SO_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_SO_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["NumPrimitivesWritten"], decoded_value.NumPrimitivesWritten, options);
        FieldToJson(jdata["PrimitivesStorageNeeded"], decoded_value.PrimitivesStorageNeeded, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STREAM_OUTPUT_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW& meta_struct = *data;
        FieldToJsonAsHex(jdata["BufferLocation"], decoded_value.BufferLocation, options);
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options);
        FieldToJsonAsHex(jdata["BufferFilledSizeLocation"], decoded_value.BufferFilledSizeLocation, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRAW_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRAW_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["VertexCountPerInstance"], decoded_value.VertexCountPerInstance, options);
        FieldToJson(jdata["InstanceCount"], decoded_value.InstanceCount, options);
        FieldToJson(jdata["StartVertexLocation"], decoded_value.StartVertexLocation, options);
        FieldToJson(jdata["StartInstanceLocation"], decoded_value.StartInstanceLocation, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRAW_INDEXED_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["IndexCountPerInstance"], decoded_value.IndexCountPerInstance, options);
        FieldToJson(jdata["InstanceCount"], decoded_value.InstanceCount, options);
        FieldToJson(jdata["StartIndexLocation"], decoded_value.StartIndexLocation, options);
        FieldToJson(jdata["BaseVertexLocation"], decoded_value.BaseVertexLocation, options);
        FieldToJson(jdata["StartInstanceLocation"], decoded_value.StartInstanceLocation, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["ThreadGroupCountX"], decoded_value.ThreadGroupCountX, options);
        FieldToJson(jdata["ThreadGroupCountY"], decoded_value.ThreadGroupCountY, options);
        FieldToJson(jdata["ThreadGroupCountZ"], decoded_value.ThreadGroupCountZ, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERTEX_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERTEX_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERTEX_BUFFER_VIEW& meta_struct = *data;
        FieldToJsonAsHex(jdata["BufferLocation"], decoded_value.BufferLocation, options);
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options);
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDEX_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INDEX_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INDEX_BUFFER_VIEW& meta_struct = *data;
        FieldToJsonAsHex(jdata["BufferLocation"], decoded_value.BufferLocation, options);
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options);
        FieldToJson(jdata["Format"], decoded_value.Format, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDIRECT_ARGUMENT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INDIRECT_ARGUMENT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INDIRECT_ARGUMENT_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        switch (decoded_value.Type)
        {
            case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW:
            case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED:
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH:
            {
                // No data to output for draws and dispatches, they are parameterless tags.
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW:
            {
                auto& vb = jdata["VertexBuffer"];
                FieldToJson(vb["Slot"], decoded_value.VertexBuffer.Slot, options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW:
            {
                // No parameters to output.
                FieldToJson(jdata["comment"], "There must be a D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED in the same sequence.", options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT:
            {
                auto& c = jdata["Constant"];
                FieldToJson(c["RootParameterIndex"], decoded_value.Constant.RootParameterIndex, options);
                FieldToJson(c["DestOffsetIn32BitValues"], decoded_value.Constant.DestOffsetIn32BitValues, options);
                FieldToJson(c["Num32BitValuesToSet"], decoded_value.Constant.Num32BitValuesToSet, options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW:
            {
                auto& cbv = jdata["ConstantBufferView"];
                FieldToJson(cbv["RootParameterIndex"], decoded_value.ConstantBufferView.RootParameterIndex, options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW:
            {
                auto& srv = jdata["ShaderResourceView"];
                FieldToJson(srv["RootParameterIndex"], decoded_value.ShaderResourceView.RootParameterIndex, options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW:
            {
                auto& uav = jdata["UnorderedAccessView"];
                FieldToJson(uav["RootParameterIndex"], decoded_value.UnorderedAccessView.RootParameterIndex, options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS:
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_MESH:
            {
                // No data to output for draws and dispatches, they are parameterless tags.
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_INDIRECT_ARGUMENT_TYPE in D3D12_INDIRECT_ARGUMENT_DESC.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMMAND_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMMAND_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["ByteStride"], decoded_value.ByteStride, options);
        FieldToJson(jdata["NumArgumentDescs"], decoded_value.NumArgumentDescs, options);
        FieldToJson(jdata["pArgumentDescs"], meta_struct.pArgumentDescs, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& meta_struct = *data;
        FieldToJsonAsHex(jdata["Dest"], decoded_value.Dest, options);
        FieldToJson(jdata["Value"], decoded_value.Value, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options);
        FieldToJson_D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS(jdata["Support"], decoded_value.Support, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC& meta_struct = *data;
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask, options);
        FieldToJson_D3D12_PROTECTED_RESOURCE_SESSION_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_META_COMMAND_PARAMETER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_META_COMMAND_PARAMETER_DESC& meta_struct = *data;
        FieldToJson(jdata["Name"], meta_struct.Name, options);
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson_D3D12_META_COMMAND_PARAMETER_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson_D3D12_RESOURCE_STATES(jdata["RequiredResourceState"], decoded_value.RequiredResourceState, options);
        FieldToJson(jdata["StructureOffset"], decoded_value.StructureOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_META_COMMAND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_META_COMMAND_DESC& meta_struct = *data;
        FieldToJson(jdata["Id"], meta_struct.Id, options);
        FieldToJson(jdata["Name"], meta_struct.Name, options);
        FieldToJson_D3D12_GRAPHICS_STATES(jdata["InitializationDirtyState"], decoded_value.InitializationDirtyState, options);
        FieldToJson_D3D12_GRAPHICS_STATES(jdata["ExecutionDirtyState"], decoded_value.ExecutionDirtyState, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_OBJECT_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_OBJECT_CONFIG& meta_struct = *data;
        FieldToJson_D3D12_STATE_OBJECT_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE& meta_struct = *data;
        FieldToJson(jdata["pGlobalRootSignature"], meta_struct.pGlobalRootSignature, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_LOCAL_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_LOCAL_ROOT_SIGNATURE& meta_struct = *data;
        FieldToJson(jdata["pLocalRootSignature"], meta_struct.pLocalRootSignature, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_NODE_MASK& decoded_value = *data->decoded_value;
        const Decoded_D3D12_NODE_MASK& meta_struct = *data;
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_EXPORT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXPORT_DESC& meta_struct = *data;
        FieldToJson(jdata["Name"], meta_struct.Name, options);
        FieldToJson(jdata["ExportToRename"], meta_struct.ExportToRename, options);
        FieldToJson_D3D12_EXPORT_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DXIL_LIBRARY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DXIL_LIBRARY_DESC& meta_struct = *data;
        FieldToJson(jdata["DXILLibrary"], meta_struct.DXILLibrary, options);
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options);
        FieldToJson(jdata["pExports"], meta_struct.pExports, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_EXISTING_COLLECTION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXISTING_COLLECTION_DESC& meta_struct = *data;
        FieldToJson(jdata["pExistingCollection"], meta_struct.pExistingCollection, options);
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options);
        FieldToJson(jdata["pExports"], meta_struct.pExports, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& meta_struct = *data;
        FieldToJson(jdata["pSubobjectToAssociate"], meta_struct.pSubobjectToAssociate, options);
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options);
        FieldToJson(jdata["pExports"], meta_struct.pExports, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& meta_struct = *data;
        FieldToJson(jdata["SubobjectToAssociate"], meta_struct.SubobjectToAssociate, options);
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options);
        FieldToJson(jdata["pExports"], meta_struct.pExports, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HIT_GROUP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HIT_GROUP_DESC& meta_struct = *data;
        FieldToJson(jdata["HitGroupExport"], meta_struct.HitGroupExport, options);
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson(jdata["AnyHitShaderImport"], meta_struct.AnyHitShaderImport, options);
        FieldToJson(jdata["ClosestHitShaderImport"], meta_struct.ClosestHitShaderImport, options);
        FieldToJson(jdata["IntersectionShaderImport"], meta_struct.IntersectionShaderImport, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_SHADER_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_SHADER_CONFIG& meta_struct = *data;
        FieldToJson(jdata["MaxPayloadSizeInBytes"], decoded_value.MaxPayloadSizeInBytes, options);
        FieldToJson(jdata["MaxAttributeSizeInBytes"], decoded_value.MaxAttributeSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_PIPELINE_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG& meta_struct = *data;
        FieldToJson(jdata["MaxTraceRecursionDepth"], decoded_value.MaxTraceRecursionDepth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_PIPELINE_CONFIG1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1& meta_struct = *data;
        FieldToJson(jdata["MaxTraceRecursionDepth"], decoded_value.MaxTraceRecursionDepth, options);
        FieldToJson_D3D12_RAYTRACING_PIPELINE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_OBJECT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_OBJECT_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson(jdata["NumSubobjects"], decoded_value.NumSubobjects, options);
        FieldToJson(jdata["pSubobjects"], meta_struct.pSubobjects, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& meta_struct = *data;
        FieldToJsonAsHex(jdata["StartAddress"], decoded_value.StartAddress, options);
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE& meta_struct = *data;
        FieldToJsonAsHex(jdata["StartAddress"], decoded_value.StartAddress, options);
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& meta_struct = *data;
        FieldToJsonAsHex(jdata["StartAddress"], decoded_value.StartAddress, options);
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options);
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& meta_struct = *data;
        FieldToJsonAsHex(jdata["Transform3x4"], decoded_value.Transform3x4, options);
        FieldToJson(jdata["IndexFormat"], decoded_value.IndexFormat, options);
        FieldToJson(jdata["VertexFormat"], decoded_value.VertexFormat, options);
        FieldToJson(jdata["IndexCount"], decoded_value.IndexCount, options);
        FieldToJson(jdata["VertexCount"], decoded_value.VertexCount, options);
        FieldToJsonAsHex(jdata["IndexBuffer"], decoded_value.IndexBuffer, options);
        FieldToJson(jdata["VertexBuffer"], meta_struct.VertexBuffer, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_AABB* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_AABB& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_AABB& meta_struct = *data;
        FieldToJson(jdata["MinX"], decoded_value.MinX, options);
        FieldToJson(jdata["MinY"], decoded_value.MinY, options);
        FieldToJson(jdata["MinZ"], decoded_value.MinZ, options);
        FieldToJson(jdata["MaxX"], decoded_value.MaxX, options);
        FieldToJson(jdata["MaxY"], decoded_value.MaxY, options);
        FieldToJson(jdata["MaxZ"], decoded_value.MaxZ, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& meta_struct = *data;
        FieldToJson(jdata["AABBCount"], decoded_value.AABBCount, options);
        FieldToJson(jdata["AABBs"], meta_struct.AABBs, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& meta_struct = *data;
        FieldToJsonAsHex(jdata["DestBuffer"], decoded_value.DestBuffer, options);
        FieldToJson(jdata["InfoType"], decoded_value.InfoType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& meta_struct = *data;
        FieldToJson(jdata["CompactedSizeInBytes"], decoded_value.CompactedSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& meta_struct = *data;
        FieldToJson(jdata["DecodedSizeInBytes"], decoded_value.DecodedSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson(jdata["NumDescs"], decoded_value.NumDescs, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& meta_struct = *data;
        FieldToJson(jdata["SerializedSizeInBytes"], decoded_value.SerializedSizeInBytes, options);
        FieldToJson(jdata["NumBottomLevelAccelerationStructurePointers"], decoded_value.NumBottomLevelAccelerationStructurePointers, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& meta_struct = *data;
        FieldToJson(jdata["DriverOpaqueGUID"], meta_struct.DriverOpaqueGUID, options);
        FieldToJson(jdata["DriverOpaqueVersioningData"], meta_struct.DriverOpaqueVersioningData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& meta_struct = *data;
        FieldToJson(jdata["DriverMatchingIdentifier"], meta_struct.DriverMatchingIdentifier, options);
        FieldToJson(jdata["SerializedSizeInBytesIncludingHeader"], decoded_value.SerializedSizeInBytesIncludingHeader, options);
        FieldToJson(jdata["DeserializedSizeInBytes"], decoded_value.DeserializedSizeInBytes, options);
        FieldToJson(jdata["NumBottomLevelAccelerationStructurePointersAfterHeader"], decoded_value.NumBottomLevelAccelerationStructurePointersAfterHeader, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& meta_struct = *data;
        FieldToJson(jdata["CurrentSizeInBytes"], decoded_value.CurrentSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_INSTANCE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_INSTANCE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_INSTANCE_DESC& meta_struct = *data;
        FieldToJson(jdata["Transform"], meta_struct.Transform, options);
        FieldToJson(jdata["InstanceID"], decoded_value.InstanceID, options);
        FieldToJsonAsFixedWidthBinary(jdata["InstanceMask"], decoded_value.InstanceMask, options);
        FieldToJson(jdata["InstanceContributionToHitGroupIndex"], decoded_value.InstanceContributionToHitGroupIndex, options);
        FieldToJson(jdata["Flags"], decoded_value.Flags, options);
        FieldToJsonAsHex(jdata["AccelerationStructure"], decoded_value.AccelerationStructure, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson_D3D12_RAYTRACING_GEOMETRY_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        switch(decoded_value.Type)
        {
            case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
            {
                FieldToJson(jdata["Triangles"], meta_struct.Triangles, options);
                break;
            }
            case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
            {
                FieldToJson(jdata["AABBs"], meta_struct.AABBs, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RAYTRACING_GEOMETRY_TYPE in D3D12_RAYTRACING_GEOMETRY_DESC.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson(jdata["NumDescs"], decoded_value.NumDescs, options);
        FieldToJson(jdata["DescsLayout"], decoded_value.DescsLayout, options);
        switch(decoded_value.Type)
        {
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
            {
                FieldToJsonAsHex(jdata["InstanceDescs"], decoded_value.InstanceDescs, options);
                break;
            }
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
            {
                switch(decoded_value.DescsLayout)
                {
                    case D3D12_ELEMENTS_LAYOUT_ARRAY:
                    {
                        FieldToJson(jdata["pGeometryDescs"], meta_struct.pGeometryDescs, options);
                        break;
                    }
                    case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:
                    {
                        FieldToJson(jdata["ppGeometryDescs"], meta_struct.ppGeometryDescs, options);
                        break;
                    }
                }
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE in D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& meta_struct = *data;
        FieldToJsonAsHex(jdata["DestAccelerationStructureData"], decoded_value.DestAccelerationStructureData, options);
        FieldToJson(jdata["Inputs"], meta_struct.Inputs, options);
        FieldToJsonAsHex(jdata["SourceAccelerationStructureData"], decoded_value.SourceAccelerationStructureData, options);
        FieldToJsonAsHex(jdata["ScratchAccelerationStructureData"], decoded_value.ScratchAccelerationStructureData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& meta_struct = *data;
        FieldToJson(jdata["ResultDataMaxSizeInBytes"], decoded_value.ResultDataMaxSizeInBytes, options);
        FieldToJson(jdata["ScratchDataSizeInBytes"], decoded_value.ScratchDataSizeInBytes, options);
        FieldToJson(jdata["UpdateScratchDataSizeInBytes"], decoded_value.UpdateScratchDataSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_AUTO_BREADCRUMB_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_AUTO_BREADCRUMB_NODE& meta_struct = *data;
        FieldToJson(jdata["pCommandListDebugNameA"], meta_struct.pCommandListDebugNameA, options);
        FieldToJson(jdata["pCommandListDebugNameW"], meta_struct.pCommandListDebugNameW, options);
        FieldToJson(jdata["pCommandQueueDebugNameA"], meta_struct.pCommandQueueDebugNameA, options);
        FieldToJson(jdata["pCommandQueueDebugNameW"], meta_struct.pCommandQueueDebugNameW, options);
        FieldToJson(jdata["pCommandList"], meta_struct.pCommandList, options);
        FieldToJson(jdata["pCommandQueue"], meta_struct.pCommandQueue, options);
        FieldToJson(jdata["BreadcrumbCount"], decoded_value.BreadcrumbCount, options);
        FieldToJson(jdata["pLastBreadcrumbValue"], meta_struct.pLastBreadcrumbValue, options);
        FieldToJson(jdata["pCommandHistory"], meta_struct.pCommandHistory, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_BREADCRUMB_CONTEXT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT& meta_struct = *data;
        FieldToJson(jdata["BreadcrumbIndex"], decoded_value.BreadcrumbIndex, options);
        FieldToJson(jdata["pContextString"], meta_struct.pContextString, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_AUTO_BREADCRUMB_NODE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_AUTO_BREADCRUMB_NODE1& meta_struct = *data;
        FieldToJson(jdata["pCommandListDebugNameA"], meta_struct.pCommandListDebugNameA, options);
        FieldToJson(jdata["pCommandListDebugNameW"], meta_struct.pCommandListDebugNameW, options);
        FieldToJson(jdata["pCommandQueueDebugNameA"], meta_struct.pCommandQueueDebugNameA, options);
        FieldToJson(jdata["pCommandQueueDebugNameW"], meta_struct.pCommandQueueDebugNameW, options);
        FieldToJson(jdata["pCommandList"], meta_struct.pCommandList, options);
        FieldToJson(jdata["pCommandQueue"], meta_struct.pCommandQueue, options);
        FieldToJson(jdata["BreadcrumbCount"], decoded_value.BreadcrumbCount, options);
        FieldToJson(jdata["pLastBreadcrumbValue"], meta_struct.pLastBreadcrumbValue, options);
        FieldToJson(jdata["pCommandHistory"], meta_struct.pCommandHistory, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
        FieldToJson(jdata["BreadcrumbContextsCount"], decoded_value.BreadcrumbContextsCount, options);
        FieldToJson(jdata["pBreadcrumbContexts"], meta_struct.pBreadcrumbContexts, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA& meta_struct = *data;
        FieldToJson_D3D12_DRED_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], meta_struct.pHeadAutoBreadcrumbNode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_ALLOCATION_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_ALLOCATION_NODE& meta_struct = *data;
        FieldToJson(jdata["ObjectNameA"], meta_struct.ObjectNameA, options);
        FieldToJson(jdata["ObjectNameW"], meta_struct.ObjectNameW, options);
        FieldToJson(jdata["AllocationType"], decoded_value.AllocationType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_ALLOCATION_NODE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_ALLOCATION_NODE1& meta_struct = *data;
        FieldToJson(jdata["ObjectNameA"], meta_struct.ObjectNameA, options);
        FieldToJson(jdata["ObjectNameW"], meta_struct.ObjectNameW, options);
        FieldToJson(jdata["AllocationType"], decoded_value.AllocationType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
        FieldToJson(jdata["pObject"], meta_struct.pObject, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& meta_struct = *data;
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], meta_struct.pHeadAutoBreadcrumbNode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& meta_struct = *data;
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], meta_struct.pHeadAutoBreadcrumbNode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT& meta_struct = *data;
        FieldToJsonAsHex(jdata["PageFaultVA"], decoded_value.PageFaultVA, options);
        FieldToJson(jdata["pHeadExistingAllocationNode"], meta_struct.pHeadExistingAllocationNode, options);
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], meta_struct.pHeadRecentFreedAllocationNode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1& meta_struct = *data;
        FieldToJsonAsHex(jdata["PageFaultVA"], decoded_value.PageFaultVA, options);
        FieldToJson(jdata["pHeadExistingAllocationNode"], meta_struct.pHeadExistingAllocationNode, options);
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], meta_struct.pHeadRecentFreedAllocationNode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2& meta_struct = *data;
        FieldToJsonAsHex(jdata["PageFaultVA"], decoded_value.PageFaultVA, options);
        FieldToJson(jdata["pHeadExistingAllocationNode"], meta_struct.pHeadExistingAllocationNode, options);
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], meta_struct.pHeadRecentFreedAllocationNode, options);
        FieldToJson_D3D12_DRED_PAGE_FAULT_FLAGS(jdata["PageFaultFlags"], decoded_value.PageFaultFlags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1& meta_struct = *data;
        HresultToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options);
        FieldToJson(jdata["AutoBreadcrumbsOutput"], meta_struct.AutoBreadcrumbsOutput, options);
        FieldToJson(jdata["PageFaultOutput"], meta_struct.PageFaultOutput, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2& meta_struct = *data;
        HresultToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options);
        FieldToJson(jdata["AutoBreadcrumbsOutput"], meta_struct.AutoBreadcrumbsOutput, options);
        FieldToJson(jdata["PageFaultOutput"], meta_struct.PageFaultOutput, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3& meta_struct = *data;
        HresultToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options);
        FieldToJson(jdata["AutoBreadcrumbsOutput"], meta_struct.AutoBreadcrumbsOutput, options);
        FieldToJson(jdata["PageFaultOutput"], meta_struct.PageFaultOutput, options);
        FieldToJson(jdata["DeviceState"], decoded_value.DeviceState, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& meta_struct = *data;
        FieldToJson(jdata["Version"], decoded_value.Version, options);
        switch(decoded_value.Version)
        {
            case D3D12_DRED_VERSION_1_0:
            {
                FieldToJson(jdata["Dred_1_0"], meta_struct.Dred_1_0, options);
                break;
            }
            case D3D12_DRED_VERSION_1_1:
            {
                FieldToJson(jdata["Dred_1_1"], meta_struct.Dred_1_1, options);
                break;
            }
            case D3D12_DRED_VERSION_1_2:
            {
                FieldToJson(jdata["Dred_1_2"], meta_struct.Dred_1_2, options);
                break;
            }
            case D3D12_DRED_VERSION_1_3:
            {
                FieldToJson(jdata["Dred_1_3"], meta_struct.Dred_1_3, options);
                FieldToJson(jdata[format::kNameWarning], "Dred_1_3 is not supported by GFXR at this time. Please file an issue quoting this text if this is a blocker for you.", options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DRED_VERSION in D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options);
        FieldToJson(jdata["Count"], decoded_value.Count, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options);
        FieldToJson(jdata["Count"], decoded_value.Count, options);
        FieldToJson(jdata["pTypes"], meta_struct.pTypes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1& meta_struct = *data;
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask, options);
        FieldToJson_D3D12_PROTECTED_RESOURCE_SESSION_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson(jdata["ProtectionType"], meta_struct.ProtectionType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["ClearValue"], meta_struct.ClearValue, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["AdditionalWidth"], decoded_value.AdditionalWidth, options);
        FieldToJson(jdata["AdditionalHeight"], decoded_value.AdditionalHeight, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        switch(decoded_value.Type)
        {
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR:
            {
                FieldToJson(jdata["Clear"], meta_struct.Clear, options);
                break;
            }
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER:
            if(decoded_value.PreserveLocal.AdditionalWidth != 0U || decoded_value.PreserveLocal.AdditionalHeight != 0U)
            {
                FieldToJson(jdata[format::kNameWarning], "Additional width and height should be zero (see DirectX Specs).", options);
            }
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_SRV:
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_UAV:
            {
                FieldToJson(jdata["PreserveLocal"], decoded_value.PreserveLocal, options);
                break;
            }
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_DISCARD:
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE:
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_NO_ACCESS:
            // No parameters to these cases.
            break;

            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE in D3D12_RENDER_PASS_BEGINNING_ACCESS.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["SrcSubresource"], decoded_value.SrcSubresource, options);
        FieldToJson(jdata["DstSubresource"], decoded_value.DstSubresource, options);
        FieldToJson(jdata["DstX"], decoded_value.DstX, options);
        FieldToJson(jdata["DstY"], decoded_value.DstY, options);
        FieldToJson(jdata["SrcRect"], meta_struct.SrcRect, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["pSrcResource"], meta_struct.pSrcResource, options);
        FieldToJson(jdata["pDstResource"], meta_struct.pDstResource, options);
        FieldToJson(jdata["SubresourceCount"], decoded_value.SubresourceCount, options);
        FieldToJson(jdata["pSubresourceParameters"], meta_struct.pSubresourceParameters, options);
        FieldToJson(jdata["Format"], decoded_value.Format, options);
        FieldToJson(jdata["ResolveMode"], decoded_value.ResolveMode, options);
        Bool32ToJson(jdata["PreserveResolveSource"], decoded_value.PreserveResolveSource, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["AdditionalWidth"], decoded_value.AdditionalWidth, options);
        FieldToJson(jdata["AdditionalHeight"], decoded_value.AdditionalHeight, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        switch(decoded_value.Type)
        {
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_DISCARD:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_NO_ACCESS:
            // No parameters to these cases.
            break;

            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE:
            {
                FieldToJson(jdata["Resolve"], meta_struct.Resolve, options);
                break;
            }
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_SRV:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_UAV:
            {
                FieldToJson(jdata["PreserveLocal"], decoded_value.PreserveLocal, options);
                break;
            }

            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RENDER_PASS_ENDING_ACCESS_TYPE in D3D12_RENDER_PASS_ENDING_ACCESS.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_RENDER_TARGET_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC& meta_struct = *data;
        FieldToJson(jdata["cpuDescriptor"], meta_struct.cpuDescriptor, options);
        FieldToJson(jdata["BeginningAccess"], meta_struct.BeginningAccess, options);
        FieldToJson(jdata["EndingAccess"], meta_struct.EndingAccess, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& meta_struct = *data;
        FieldToJson(jdata["cpuDescriptor"], meta_struct.cpuDescriptor, options);
        FieldToJson(jdata["DepthBeginningAccess"], meta_struct.DepthBeginningAccess, options);
        FieldToJson(jdata["StencilBeginningAccess"], meta_struct.StencilBeginningAccess, options);
        FieldToJson(jdata["DepthEndingAccess"], meta_struct.DepthEndingAccess, options);
        FieldToJson(jdata["StencilEndingAccess"], meta_struct.StencilEndingAccess, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_RAYS_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_RAYS_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_RAYS_DESC& meta_struct = *data;
        FieldToJson(jdata["RayGenerationShaderRecord"], meta_struct.RayGenerationShaderRecord, options);
        FieldToJson(jdata["MissShaderTable"], meta_struct.MissShaderTable, options);
        FieldToJson(jdata["HitGroupTable"], meta_struct.HitGroupTable, options);
        FieldToJson(jdata["CallableShaderTable"], meta_struct.CallableShaderTable, options);
        FieldToJson(jdata["Width"], decoded_value.Width, options);
        FieldToJson(jdata["Height"], decoded_value.Height, options);
        FieldToJson(jdata["Depth"], decoded_value.Depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_CACHE_SESSION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_CACHE_SESSION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_CACHE_SESSION_DESC& meta_struct = *data;
        FieldToJson(jdata["Identifier"], meta_struct.Identifier, options);
        FieldToJson(jdata["Mode"], decoded_value.Mode, options);
        FieldToJson_D3D12_SHADER_CACHE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson(jdata["MaximumInMemoryCacheSizeBytes"], decoded_value.MaximumInMemoryCacheSizeBytes, options);
        FieldToJson(jdata["MaximumInMemoryCacheEntries"], decoded_value.MaximumInMemoryCacheEntries, options);
        FieldToJson(jdata["MaximumValueFileSizeBytes"], decoded_value.MaximumValueFileSizeBytes, options);
        FieldToJson(jdata["Version"], decoded_value.Version, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BARRIER_SUBRESOURCE_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE& meta_struct = *data;
        FieldToJson(jdata["IndexOrFirstMipLevel"], decoded_value.IndexOrFirstMipLevel, options);
        FieldToJson(jdata["NumMipLevels"], decoded_value.NumMipLevels, options);
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options);
        FieldToJson(jdata["NumArraySlices"], decoded_value.NumArraySlices, options);
        FieldToJson(jdata["FirstPlane"], decoded_value.FirstPlane, options);
        FieldToJson(jdata["NumPlanes"], decoded_value.NumPlanes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_BARRIER& meta_struct = *data;
        FieldToJson(jdata["SyncBefore"], decoded_value.SyncBefore, options);
        FieldToJson(jdata["SyncAfter"], decoded_value.SyncAfter, options);
        FieldToJson(jdata["AccessBefore"], decoded_value.AccessBefore, options);
        FieldToJson(jdata["AccessAfter"], decoded_value.AccessAfter, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXTURE_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXTURE_BARRIER& meta_struct = *data;
        FieldToJson(jdata["SyncBefore"], decoded_value.SyncBefore, options);
        FieldToJson(jdata["SyncAfter"], decoded_value.SyncAfter, options);
        FieldToJson(jdata["AccessBefore"], decoded_value.AccessBefore, options);
        FieldToJson(jdata["AccessAfter"], decoded_value.AccessAfter, options);
        FieldToJson(jdata["LayoutBefore"], decoded_value.LayoutBefore, options);
        FieldToJson(jdata["LayoutAfter"], decoded_value.LayoutAfter, options);
        FieldToJson(jdata["pResource"], meta_struct.pResource, options);
        FieldToJson(jdata["Subresources"], meta_struct.Subresources, options);
        FieldToJson_D3D12_TEXTURE_BARRIER_FLAGS(jdata["Flags"], decoded_value.Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_BARRIER& meta_struct = *data;
        FieldToJson(jdata["SyncBefore"], decoded_value.SyncBefore, options);
        FieldToJson(jdata["SyncAfter"], decoded_value.SyncAfter, options);
        FieldToJson(jdata["AccessBefore"], decoded_value.AccessBefore, options);
        FieldToJson(jdata["AccessAfter"], decoded_value.AccessAfter, options);
        FieldToJson(jdata["pResource"], meta_struct.pResource, options);
        FieldToJson(jdata["Offset"], decoded_value.Offset, options);
        FieldToJson(jdata["Size"], decoded_value.Size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_GROUP* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BARRIER_GROUP& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BARRIER_GROUP& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        FieldToJson(jdata["NumBarriers"], decoded_value.NumBarriers, options);
        switch(decoded_value.Type)
        {
            case D3D12_BARRIER_TYPE_GLOBAL:
            {
                FieldToJson(jdata["pGlobalBarriers"], meta_struct.global_barriers, options);
                break;
            }
            case D3D12_BARRIER_TYPE_TEXTURE:
            {
                FieldToJson(jdata["pTextureBarriers"], meta_struct.texture_barriers, options);
                break;
            }
            case D3D12_BARRIER_TYPE_BUFFER:
            {
                FieldToJson(jdata["pBufferBarriers"], meta_struct.buffer_barriers, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_BARRIER_TYPE in D3D12_BARRIER_GROUP.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_DATA& meta_struct = *data;
        FieldToJson(jdata["pData"], meta_struct.pData, options);
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options);
        FieldToJson(jdata["SlicePitch"], decoded_value.SlicePitch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MEMCPY_DEST* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MEMCPY_DEST& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MEMCPY_DEST& meta_struct = *data;
        FieldToJson(jdata["pData"], meta_struct.pData, options);
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options);
        FieldToJson(jdata["SlicePitch"], decoded_value.SlicePitch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_CONFIGURATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_CONFIGURATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_CONFIGURATION_DESC& meta_struct = *data;
        FieldToJson_D3D12_DEVICE_FLAGS(jdata["Flags"], decoded_value.Flags, options);
        FieldToJson(jdata["GpuBasedValidationFlags"], decoded_value.GpuBasedValidationFlags, options);
        FieldToJson(jdata["SDKVersion"], decoded_value.SDKVersion, options);
        FieldToJson(jdata["NumEnabledExperimentalFeatures"], decoded_value.NumEnabledExperimentalFeatures, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_MESH_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["ThreadGroupCountX"], decoded_value.ThreadGroupCountX, options);
        FieldToJson(jdata["ThreadGroupCountY"], decoded_value.ThreadGroupCountY, options);
        FieldToJson(jdata["ThreadGroupCountZ"], decoded_value.ThreadGroupCountZ, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D_SHADER_MACRO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D_SHADER_MACRO& decoded_value = *data->decoded_value;
        const Decoded_D3D_SHADER_MACRO& meta_struct = *data;
        FieldToJson(jdata["Name"], meta_struct.Name, options);
        FieldToJson(jdata["Definition"], meta_struct.Definition, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& meta_struct = *data;
        FieldToJson(jdata["MaxMessagesPerCommandList"], decoded_value.MaxMessagesPerCommandList, options);
        FieldToJson(jdata["DefaultShaderPatchMode"], decoded_value.DefaultShaderPatchMode, options);
        FieldToJson_D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS(jdata["PipelineStateCreateFlags"], decoded_value.PipelineStateCreateFlags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& meta_struct = *data;
        FieldToJson(jdata["SlowdownFactor"], decoded_value.SlowdownFactor, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& meta_struct = *data;
        FieldToJson(jdata["ShaderPatchMode"], decoded_value.ShaderPatchMode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MESSAGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MESSAGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MESSAGE& meta_struct = *data;
        FieldToJson(jdata["Category"], decoded_value.Category, options);
        FieldToJson(jdata["Severity"], decoded_value.Severity, options);
        FieldToJson(jdata["ID"], decoded_value.ID, options);
        FieldToJson(jdata["pDescription"], meta_struct.pDescription, options);
        FieldToJson(jdata["DescriptionByteLength"], decoded_value.DescriptionByteLength, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INFO_QUEUE_FILTER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INFO_QUEUE_FILTER_DESC& meta_struct = *data;
        FieldToJson(jdata["NumCategories"], decoded_value.NumCategories, options);
        FieldToJson(jdata["pCategoryList"], meta_struct.pCategoryList, options);
        FieldToJson(jdata["NumSeverities"], decoded_value.NumSeverities, options);
        FieldToJson(jdata["pSeverityList"], meta_struct.pSeverityList, options);
        FieldToJson(jdata["NumIDs"], decoded_value.NumIDs, options);
        FieldToJson(jdata["pIDList"], meta_struct.pIDList, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INFO_QUEUE_FILTER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INFO_QUEUE_FILTER& meta_struct = *data;
        FieldToJson(jdata["AllowList"], meta_struct.AllowList, options);
        FieldToJson(jdata["DenyList"], meta_struct.DenyList, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const tagRECT& decoded_value = *data->decoded_value;
        const Decoded_tagRECT& meta_struct = *data;
        FieldToJson(jdata["left"], decoded_value.left, options);
        FieldToJson(jdata["top"], decoded_value.top, options);
        FieldToJson(jdata["right"], decoded_value.right, options);
        FieldToJson(jdata["bottom"], decoded_value.bottom, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const tagPOINT& decoded_value = *data->decoded_value;
        const Decoded_tagPOINT& meta_struct = *data;
        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const _SECURITY_ATTRIBUTES& decoded_value = *data->decoded_value;
        const Decoded__SECURITY_ATTRIBUTES& meta_struct = *data;
        FieldToJson(jdata["nLength"], decoded_value.nLength, options);
        FieldToJson(jdata["lpSecurityDescriptor"], meta_struct.lpSecurityDescriptor, options);
        Bool32ToJson(jdata["bInheritHandle"], decoded_value.bInheritHandle, options);
    }
}

// TODO Move all these manual functions out of the generator and into a .cpp file.

/// @defgroup custom_dx12_struct_decoders_to_json_bodies Custom implementations for
/// troublesome structs.
/// We put the custom implementations in the generator Python rather than
/// creating a whole new compilation unit for them.
/** @{*/

// Decoded_LARGE_INTEGER won't be generated as it is a <winnt.h> struct rather than D3D12.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const LARGE_INTEGER& decoded_value = *data->decoded_value;
        FieldToJson(jdata, decoded_value.QuadPart, options);
    }
}

// Generated version tries to read the struct members rather than doing the "fake enum" thing.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_GUID* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const GUID& decoded_value = *data->decoded_value;
        FieldToJson(jdata, decoded_value, options);
    }
}

/// Dump all the fields of the custom struct, even though not all need be populated.
/// @note D3D12 doesn't define names for these: the underlying struct is just a void pointer
/// and a byte count with the structure defined in documentation. See:
/// <https://learn.microsoft.com/en-us/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc>
/// See also: framework\decode\custom_dx12_struct_decoders.cpp
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PIPELINE_STATE_STREAM_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct.
        //FieldToJson(jdata["root_signature_ptr"], meta_struct.root_signature_ptr, options);
        FieldToJson(jdata[format::kNameWarning], "D3D12_PIPELINE_STATE_STREAM_DESC.root_signature_ptr is not supported.", options);
        FieldToJson(jdata["root_signature_ptr"], "@todo Get this field to convert cleanly.", options);
        FieldToJson(jdata["vs_bytecode"], meta_struct.vs_bytecode, options);
        FieldToJson(jdata["ps_bytecode"], meta_struct.ps_bytecode, options);
        FieldToJson(jdata["ds_bytecode"], meta_struct.ds_bytecode, options);
        FieldToJson(jdata["hs_bytecode"], meta_struct.hs_bytecode, options);
        FieldToJson(jdata["gs_bytecode"], meta_struct.gs_bytecode, options);
        FieldToJson(jdata["cs_bytecode"], meta_struct.cs_bytecode, options);
        FieldToJson(jdata["as_bytecode"], meta_struct.as_bytecode, options);
        FieldToJson(jdata["ms_bytecode"], meta_struct.ms_bytecode, options);
        FieldToJson(jdata["stream_output"], meta_struct.stream_output, options);
        FieldToJson(jdata["blend"], meta_struct.blend, options);
        FieldToJson(jdata["rasterizer"], meta_struct.rasterizer, options);
        FieldToJson(jdata["depth_stencil"], meta_struct.depth_stencil, options);
        FieldToJson(jdata["input_layout"], meta_struct.input_layout, options);
        FieldToJson(jdata["render_target_formats"], meta_struct.render_target_formats, options);
        FieldToJson(jdata["sample_desc"], meta_struct.sample_desc, options);
        FieldToJson(jdata["cached_pso"], meta_struct.cached_pso, options);
        FieldToJson(jdata["depth_stencil1"], meta_struct.depth_stencil1, options);
        FieldToJson(jdata["view_instancing"], meta_struct.view_instancing, options);
    }
}

// The decoded struct has a custom implementation.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_SUBOBJECT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_SUBOBJECT& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        switch(decoded_value.Type)
        {
            case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:
            FieldToJson(jdata["state_object_config"], meta_struct.state_object_config, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:
            FieldToJson(jdata["global_root_signature"], meta_struct.global_root_signature, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:
            FieldToJson(jdata["local_root_signature"], meta_struct.local_root_signature, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:
            FieldToJson(jdata["node_mask"], meta_struct.node_mask, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:
            FieldToJson(jdata["dxil_library_desc"], meta_struct.dxil_library_desc, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:
            FieldToJson(jdata["existing_collection_desc"], meta_struct.existing_collection_desc, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            FieldToJson(jdata["subobject_to_exports_association"], meta_struct.subobject_to_exports_association, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            FieldToJson(jdata["dxil_subobject_to_exports_association"], meta_struct.dxil_subobject_to_exports_association, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:
            FieldToJson(jdata["raytracing_shader_config"], meta_struct.raytracing_shader_config, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:
            FieldToJson(jdata["raytracing_pipeline_config"], meta_struct.raytracing_pipeline_config, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:
            FieldToJson(jdata["hit_group_desc"], meta_struct.hit_group_desc, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1:
            FieldToJson(jdata["raytracing_pipeline_config1"], meta_struct.raytracing_pipeline_config1, options);
            break;
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_STATE_SUBOBJECT_TYPE in D3D12_STATE_SUBOBJECT.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CPU_DESCRIPTOR_HANDLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& meta_struct = *data;
        // FieldToJson(jdata[format::kNameInfo], "heap_id and index were copied out of ptr by a custom encoder at capture time, and ptr was never stored in the capture file.", options);
        FieldToJson(jdata["heap_id"], meta_struct.heap_id, options);
        FieldToJson(jdata["index"], meta_struct.index, options);
    }
}

/** @} */


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
