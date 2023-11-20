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

/// @defgroup ManualD3D12StructFieldToJsons Manual functions to convert structs.
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
/** @} */

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_FRAME_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_FRAME_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["PresentCount"], decoded_value.PresentCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PresentRefreshCount"], decoded_value.PresentRefreshCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SyncRefreshCount"], decoded_value.SyncRefreshCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SyncQPCTime"], meta_struct.SyncQPCTime, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["SyncGPUTime"], meta_struct.SyncGPUTime, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MAPPED_RECT& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MAPPED_RECT& meta_struct = *data;
        FieldToJson(jdata["Pitch"], decoded_value.Pitch, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pBits"], meta_struct.pBits, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const LUID& decoded_value = *data->decoded_value;
        const Decoded_LUID& meta_struct = *data;
        FieldToJson(jdata["LowPart"], decoded_value.LowPart, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["HighPart"], decoded_value.HighPart, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTPUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTPUT_DESC& meta_struct = *data;
        FieldToJson(jdata["DeviceName"], meta_struct.DeviceName, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["DesktopCoordinates"], meta_struct.DesktopCoordinates, options); // Complex types and handles plumb to the decoded struct [is_struct]
        Bool32ToJson(jdata["AttachedToDesktop"], decoded_value.AttachedToDesktop, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["Rotation"], decoded_value.Rotation, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Monitor"], meta_struct.Monitor, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SHARED_RESOURCE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SHARED_RESOURCE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SHARED_RESOURCE& meta_struct = *data;
        FieldToJson(jdata["Handle"], meta_struct.Handle, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SURFACE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SURFACE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SURFACE_DESC& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_DESC& meta_struct = *data;
        FieldToJson(jdata["BufferDesc"], meta_struct.BufferDesc, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["BufferUsage"], decoded_value.BufferUsage, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["BufferCount"], decoded_value.BufferCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["OutputWindow"], meta_struct.OutputWindow, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        Bool32ToJson(jdata["Windowed"], decoded_value.Windowed, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["SwapEffect"], decoded_value.SwapEffect, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC1& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DISPLAY_COLOR_SPACE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_DISPLAY_COLOR_SPACE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_DISPLAY_COLOR_SPACE& meta_struct = *data;
        FieldToJson(jdata["PrimaryCoordinates"], meta_struct.PrimaryCoordinates, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["WhitePoints"], meta_struct.WhitePoints, options); // Complex types and handles plumb to the decoded struct [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_MOVE_RECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_MOVE_RECT& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_MOVE_RECT& meta_struct = *data;
        FieldToJson(jdata["SourcePoint"], meta_struct.SourcePoint, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["DestinationRect"], meta_struct.DestinationRect, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_DESC& meta_struct = *data;
        FieldToJson(jdata["ModeDesc"], meta_struct.ModeDesc, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Rotation"], decoded_value.Rotation, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["DesktopImageInSystemMemory"], decoded_value.DesktopImageInSystemMemory, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_POSITION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_POINTER_POSITION& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_POINTER_POSITION& meta_struct = *data;
        FieldToJson(jdata["Position"], meta_struct.Position, options); // Complex types and handles plumb to the decoded struct [is_struct]
        Bool32ToJson(jdata["Visible"], decoded_value.Visible, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_POINTER_SHAPE_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Pitch"], decoded_value.Pitch, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["HotSpot"], meta_struct.HotSpot, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_FRAME_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_FRAME_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_FRAME_INFO& meta_struct = *data;
        FieldToJson(jdata["LastPresentTime"], meta_struct.LastPresentTime, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["LastMouseUpdateTime"], meta_struct.LastMouseUpdateTime, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["AccumulatedFrames"], decoded_value.AccumulatedFrames, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["RectsCoalesced"], decoded_value.RectsCoalesced, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["ProtectedContentMaskedOut"], decoded_value.ProtectedContentMaskedOut, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["PointerPosition"], meta_struct.PointerPosition, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["TotalMetadataBufferSize"], decoded_value.TotalMetadataBufferSize, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PointerShapeBufferSize"], decoded_value.PointerShapeBufferSize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MODE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MODE_DESC1& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RefreshRate"], meta_struct.RefreshRate, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ScanlineOrdering"], decoded_value.ScanlineOrdering, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["Stereo"], decoded_value.Stereo, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_DESC1& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["Stereo"], decoded_value.Stereo, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["BufferUsage"], decoded_value.BufferUsage, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["BufferCount"], decoded_value.BufferCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SwapEffect"], decoded_value.SwapEffect, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AlphaMode"], decoded_value.AlphaMode, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC& meta_struct = *data;
        FieldToJson(jdata["RefreshRate"], meta_struct.RefreshRate, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["ScanlineOrdering"], decoded_value.ScanlineOrdering, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["Windowed"], decoded_value.Windowed, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_PRESENT_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_PRESENT_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_PRESENT_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["DirtyRectsCount"], decoded_value.DirtyRectsCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pDirtyRects"], meta_struct.pDirtyRects, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["pScrollRect"], meta_struct.pScrollRect, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
        FieldToJson(jdata["pScrollOffset"], meta_struct.pScrollOffset, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC2& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["GraphicsPreemptionGranularity"], decoded_value.GraphicsPreemptionGranularity, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ComputePreemptionGranularity"], decoded_value.ComputePreemptionGranularity, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MATRIX_3X2_F* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MATRIX_3X2_F& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MATRIX_3X2_F& meta_struct = *data;
        FieldToJson(jdata["_11"], decoded_value._11, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["_12"], decoded_value._12, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["_21"], decoded_value._21, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["_22"], decoded_value._22, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["_31"], decoded_value._31, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["_32"], decoded_value._32, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_DECODE_SWAP_CHAIN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC& meta_struct = *data;
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS_MEDIA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_FRAME_STATISTICS_MEDIA& decoded_value = *data->decoded_value;
        const Decoded_DXGI_FRAME_STATISTICS_MEDIA& meta_struct = *data;
        FieldToJson(jdata["PresentCount"], decoded_value.PresentCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PresentRefreshCount"], decoded_value.PresentRefreshCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SyncRefreshCount"], decoded_value.SyncRefreshCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SyncQPCTime"], meta_struct.SyncQPCTime, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["SyncGPUTime"], meta_struct.SyncGPUTime, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["CompositionMode"], decoded_value.CompositionMode, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ApprovedPresentDuration"], decoded_value.ApprovedPresentDuration, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_QUERY_VIDEO_MEMORY_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO& meta_struct = *data;
        FieldToJson(jdata["Budget"], decoded_value.Budget, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CurrentUsage"], decoded_value.CurrentUsage, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AvailableForReservation"], decoded_value.AvailableForReservation, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CurrentReservation"], decoded_value.CurrentReservation, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_HDR_METADATA_HDR10& decoded_value = *data->decoded_value;
        const Decoded_DXGI_HDR_METADATA_HDR10& meta_struct = *data;
        FieldToJson(jdata["RedPrimary"], meta_struct.RedPrimary, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["GreenPrimary"], meta_struct.GreenPrimary, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["BluePrimary"], meta_struct.BluePrimary, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["WhitePoint"], meta_struct.WhitePoint, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["MaxMasteringLuminance"], decoded_value.MaxMasteringLuminance, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MinMasteringLuminance"], decoded_value.MinMasteringLuminance, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxContentLightLevel"], decoded_value.MaxContentLightLevel, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxFrameAverageLightLevel"], decoded_value.MaxFrameAverageLightLevel, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10PLUS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_HDR_METADATA_HDR10PLUS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_HDR_METADATA_HDR10PLUS& meta_struct = *data;
        FieldToJson(jdata["Data"], meta_struct.Data, options); // Complex types and handles plumb to the decoded struct [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC3& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC3& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["GraphicsPreemptionGranularity"], decoded_value.GraphicsPreemptionGranularity, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ComputePreemptionGranularity"], decoded_value.ComputePreemptionGranularity, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTPUT_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTPUT_DESC1& meta_struct = *data;
        FieldToJson(jdata["DeviceName"], meta_struct.DeviceName, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["DesktopCoordinates"], meta_struct.DesktopCoordinates, options); // Complex types and handles plumb to the decoded struct [is_struct]
        Bool32ToJson(jdata["AttachedToDesktop"], decoded_value.AttachedToDesktop, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["Rotation"], decoded_value.Rotation, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Monitor"], meta_struct.Monitor, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["BitsPerColor"], decoded_value.BitsPerColor, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ColorSpace"], decoded_value.ColorSpace, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["RedPrimary"], meta_struct.RedPrimary, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["GreenPrimary"], meta_struct.GreenPrimary, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["BluePrimary"], meta_struct.BluePrimary, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["WhitePoint"], meta_struct.WhitePoint, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["MinLuminance"], decoded_value.MinLuminance, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxLuminance"], decoded_value.MaxLuminance, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxFullFrameLuminance"], decoded_value.MaxFullFrameLuminance, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RATIONAL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_RATIONAL& decoded_value = *data->decoded_value;
        const Decoded_DXGI_RATIONAL& meta_struct = *data;
        FieldToJson(jdata["Numerator"], decoded_value.Numerator, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Denominator"], decoded_value.Denominator, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SAMPLE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SAMPLE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SAMPLE_DESC& meta_struct = *data;
        FieldToJson(jdata["Count"], decoded_value.Count, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Quality"], decoded_value.Quality, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RGB* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_RGB& decoded_value = *data->decoded_value;
        const Decoded_DXGI_RGB& meta_struct = *data;
        FieldToJson(jdata["Red"], decoded_value.Red, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Green"], decoded_value.Green, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Blue"], decoded_value.Blue, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3DCOLORVALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3DCOLORVALUE& decoded_value = *data->decoded_value;
        const Decoded_D3DCOLORVALUE& meta_struct = *data;
        FieldToJson(jdata["r"], decoded_value.r, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["g"], decoded_value.g, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["b"], decoded_value.b, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["a"], decoded_value.a, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_GAMMA_CONTROL& decoded_value = *data->decoded_value;
        const Decoded_DXGI_GAMMA_CONTROL& meta_struct = *data;
        FieldToJson(jdata["Scale"], meta_struct.Scale, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Offset"], meta_struct.Offset, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["GammaCurve"], meta_struct.GammaCurve, options); // Complex types and handles plumb to the decoded struct [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_GAMMA_CONTROL_CAPABILITIES& decoded_value = *data->decoded_value;
        const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES& meta_struct = *data;
        Bool32ToJson(jdata["ScaleAndOffsetSupported"], decoded_value.ScaleAndOffsetSupported, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["MaxConvertedValue"], decoded_value.MaxConvertedValue, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MinConvertedValue"], decoded_value.MinConvertedValue, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumGammaControlPoints"], decoded_value.NumGammaControlPoints, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ControlPointPositions"], meta_struct.ControlPointPositions, options); // Complex types and handles plumb to the decoded struct [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MODE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MODE_DESC& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RefreshRate"], meta_struct.RefreshRate, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ScanlineOrdering"], decoded_value.ScanlineOrdering, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_DC_HUFFMAN_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE& meta_struct = *data;
        FieldToJson(jdata["CodeCounts"], meta_struct.CodeCounts, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["CodeValues"], meta_struct.CodeValues, options); // Complex types and handles plumb to the decoded struct [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_AC_HUFFMAN_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE& meta_struct = *data;
        FieldToJson(jdata["CodeCounts"], meta_struct.CodeCounts, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["CodeValues"], meta_struct.CodeValues, options); // Complex types and handles plumb to the decoded struct [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_QUANTIZATION_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_QUANTIZATION_TABLE& meta_struct = *data;
        FieldToJson(jdata["Elements"], meta_struct.Elements, options); // Complex types and handles plumb to the decoded struct [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMMAND_QUEUE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMMAND_QUEUE_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Priority"], decoded_value.Priority, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INPUT_ELEMENT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INPUT_ELEMENT_DESC& meta_struct = *data;
        FieldToJson(jdata["SemanticName"], meta_struct.SemanticName, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["SemanticIndex"], decoded_value.SemanticIndex, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["InputSlot"], decoded_value.InputSlot, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AlignedByteOffset"], decoded_value.AlignedByteOffset, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["InputSlotClass"], decoded_value.InputSlotClass, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["InstanceDataStepRate"], decoded_value.InstanceDataStepRate, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SO_DECLARATION_ENTRY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SO_DECLARATION_ENTRY& meta_struct = *data;
        FieldToJson(jdata["Stream"], decoded_value.Stream, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SemanticName"], meta_struct.SemanticName, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["SemanticIndex"], decoded_value.SemanticIndex, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StartComponent"], decoded_value.StartComponent, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ComponentCount"], decoded_value.ComponentCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["OutputSlot"], decoded_value.OutputSlot, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEWPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEWPORT& meta_struct = *data;
        FieldToJson(jdata["TopLeftX"], decoded_value.TopLeftX, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["TopLeftY"], decoded_value.TopLeftY, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MinDepth"], decoded_value.MinDepth, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxDepth"], decoded_value.MaxDepth, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BOX& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BOX& meta_struct = *data;
        FieldToJson(jdata["left"], decoded_value.left, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["top"], decoded_value.top, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["front"], decoded_value.front, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["right"], decoded_value.right, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["bottom"], decoded_value.bottom, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["back"], decoded_value.back, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCILOP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCILOP_DESC& meta_struct = *data;
        FieldToJson(jdata["StencilFailOp"], decoded_value.StencilFailOp, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["StencilDepthFailOp"], decoded_value.StencilDepthFailOp, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["StencilPassOp"], decoded_value.StencilPassOp, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["StencilFunc"], decoded_value.StencilFunc, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC& meta_struct = *data;
        Bool32ToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["DepthWriteMask"], decoded_value.DepthWriteMask, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["DepthFunc"], decoded_value.DepthFunc, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["StencilReadMask"], decoded_value.StencilReadMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FrontFace"], meta_struct.FrontFace, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["BackFace"], meta_struct.BackFace, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC1& meta_struct = *data;
        Bool32ToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["DepthWriteMask"], decoded_value.DepthWriteMask, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["DepthFunc"], decoded_value.DepthFunc, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["StencilReadMask"], decoded_value.StencilReadMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FrontFace"], meta_struct.FrontFace, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["BackFace"], meta_struct.BackFace, options); // Complex types and handles plumb to the decoded struct [is_struct]
        Bool32ToJson(jdata["DepthBoundsTestEnable"], decoded_value.DepthBoundsTestEnable, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCILOP_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCILOP_DESC1& meta_struct = *data;
        FieldToJson(jdata["StencilFailOp"], decoded_value.StencilFailOp, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["StencilDepthFailOp"], decoded_value.StencilDepthFailOp, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["StencilPassOp"], decoded_value.StencilPassOp, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["StencilFunc"], decoded_value.StencilFunc, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["StencilReadMask"], decoded_value.StencilReadMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC2& meta_struct = *data;
        Bool32ToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["DepthWriteMask"], decoded_value.DepthWriteMask, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["DepthFunc"], decoded_value.DepthFunc, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["FrontFace"], meta_struct.FrontFace, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["BackFace"], meta_struct.BackFace, options); // Complex types and handles plumb to the decoded struct [is_struct]
        Bool32ToJson(jdata["DepthBoundsTestEnable"], decoded_value.DepthBoundsTestEnable, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_TARGET_BLEND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_TARGET_BLEND_DESC& meta_struct = *data;
        Bool32ToJson(jdata["BlendEnable"], decoded_value.BlendEnable, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["LogicOpEnable"], decoded_value.LogicOpEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["SrcBlend"], decoded_value.SrcBlend, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["DestBlend"], decoded_value.DestBlend, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["BlendOp"], decoded_value.BlendOp, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SrcBlendAlpha"], decoded_value.SrcBlendAlpha, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["DestBlendAlpha"], decoded_value.DestBlendAlpha, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["BlendOpAlpha"], decoded_value.BlendOpAlpha, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["LogicOp"], decoded_value.LogicOp, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["RenderTargetWriteMask"], decoded_value.RenderTargetWriteMask, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BLEND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BLEND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BLEND_DESC& meta_struct = *data;
        Bool32ToJson(jdata["AlphaToCoverageEnable"], decoded_value.AlphaToCoverageEnable, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["IndependentBlendEnable"], decoded_value.IndependentBlendEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["RenderTarget"], meta_struct.RenderTarget, options); // Complex types and handles plumb to the decoded struct [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC& meta_struct = *data;
        FieldToJson(jdata["FillMode"], decoded_value.FillMode, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["CullMode"], decoded_value.CullMode, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["MultisampleEnable"], decoded_value.MultisampleEnable, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["AntialiasedLineEnable"], decoded_value.AntialiasedLineEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ConservativeRaster"], decoded_value.ConservativeRaster, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC1& meta_struct = *data;
        FieldToJson(jdata["FillMode"], decoded_value.FillMode, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["CullMode"], decoded_value.CullMode, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["MultisampleEnable"], decoded_value.MultisampleEnable, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["AntialiasedLineEnable"], decoded_value.AntialiasedLineEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ConservativeRaster"], decoded_value.ConservativeRaster, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC2& meta_struct = *data;
        FieldToJson(jdata["FillMode"], decoded_value.FillMode, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["CullMode"], decoded_value.CullMode, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["LineRasterizationMode"], decoded_value.LineRasterizationMode, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ConservativeRaster"], decoded_value.ConservativeRaster, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_BYTECODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_BYTECODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_BYTECODE& meta_struct = *data;
        FieldToJson(jdata["pShaderBytecode"], meta_struct.pShaderBytecode, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array]
        FieldToJson(jdata["BytecodeLength"], decoded_value.BytecodeLength, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STREAM_OUTPUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STREAM_OUTPUT_DESC& meta_struct = *data;
        FieldToJson(jdata["pSODeclaration"], meta_struct.pSODeclaration, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumEntries"], decoded_value.NumEntries, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pBufferStrides"], meta_struct.pBufferStrides, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array]
        FieldToJson(jdata["NumStrides"], decoded_value.NumStrides, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RasterizedStream"], decoded_value.RasterizedStream, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_LAYOUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INPUT_LAYOUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INPUT_LAYOUT_DESC& meta_struct = *data;
        FieldToJson(jdata["pInputElementDescs"], meta_struct.pInputElementDescs, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CACHED_PIPELINE_STATE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CACHED_PIPELINE_STATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CACHED_PIPELINE_STATE& meta_struct = *data;
        FieldToJson(jdata["pCachedBlob"], meta_struct.pCachedBlob, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array]
        FieldToJson(jdata["CachedBlobSizeInBytes"], decoded_value.CachedBlobSizeInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GRAPHICS_PIPELINE_STATE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC& meta_struct = *data;
        FieldToJson(jdata["pRootSignature"], meta_struct.pRootSignature, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["VS"], meta_struct.VS, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["PS"], meta_struct.PS, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["DS"], meta_struct.DS, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["HS"], meta_struct.HS, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["GS"], meta_struct.GS, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["StreamOutput"], meta_struct.StreamOutput, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["BlendState"], meta_struct.BlendState, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["SampleMask"], decoded_value.SampleMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RasterizerState"], meta_struct.RasterizerState, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["DepthStencilState"], meta_struct.DepthStencilState, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["InputLayout"], meta_struct.InputLayout, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["IBStripCutValue"], decoded_value.IBStripCutValue, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["PrimitiveTopologyType"], decoded_value.PrimitiveTopologyType, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["NumRenderTargets"], decoded_value.NumRenderTargets, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RTVFormats"], meta_struct.RTVFormats, options); // Complex types and handles plumb to the decoded struct [is_array] [is_enum]
        FieldToJson(jdata["DSVFormat"], decoded_value.DSVFormat, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CachedPSO"], meta_struct.CachedPSO, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMPUTE_PIPELINE_STATE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC& meta_struct = *data;
        FieldToJson(jdata["pRootSignature"], meta_struct.pRootSignature, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["CS"], meta_struct.CS, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CachedPSO"], meta_struct.CachedPSO, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RT_FORMAT_ARRAY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RT_FORMAT_ARRAY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RT_FORMAT_ARRAY& meta_struct = *data;
        FieldToJson(jdata["RTFormats"], meta_struct.RTFormats, options); // Complex types and handles plumb to the decoded struct [is_array] [is_enum]
        FieldToJson(jdata["NumRenderTargets"], decoded_value.NumRenderTargets, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS& meta_struct = *data;
        Bool32ToJson(jdata["DoublePrecisionFloatShaderOps"], decoded_value.DoublePrecisionFloatShaderOps, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["OutputMergerLogicOp"], decoded_value.OutputMergerLogicOp, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["MinPrecisionSupport"], decoded_value.MinPrecisionSupport, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["TiledResourcesTier"], decoded_value.TiledResourcesTier, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ResourceBindingTier"], decoded_value.ResourceBindingTier, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["PSSpecifiedStencilRefSupported"], decoded_value.PSSpecifiedStencilRefSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["TypedUAVLoadAdditionalFormats"], decoded_value.TypedUAVLoadAdditionalFormats, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["ROVsSupported"], decoded_value.ROVsSupported, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["ConservativeRasterizationTier"], decoded_value.ConservativeRasterizationTier, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], decoded_value.MaxGPUVirtualAddressBitsPerResource, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["StandardSwizzle64KBSupported"], decoded_value.StandardSwizzle64KBSupported, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["CrossNodeSharingTier"], decoded_value.CrossNodeSharingTier, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["CrossAdapterRowMajorTextureSupported"], decoded_value.CrossAdapterRowMajorTextureSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation"], decoded_value.VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["ResourceHeapTier"], decoded_value.ResourceHeapTier, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1& meta_struct = *data;
        Bool32ToJson(jdata["WaveOps"], decoded_value.WaveOps, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["WaveLaneCountMin"], decoded_value.WaveLaneCountMin, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["WaveLaneCountMax"], decoded_value.WaveLaneCountMax, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["TotalLaneCount"], decoded_value.TotalLaneCount, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["ExpandedComputeResourceStates"], decoded_value.ExpandedComputeResourceStates, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["Int64ShaderOps"], decoded_value.Int64ShaderOps, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2& meta_struct = *data;
        Bool32ToJson(jdata["DepthBoundsTestSupported"], decoded_value.DepthBoundsTestSupported, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["ProgrammableSamplePositionsTier"], decoded_value.ProgrammableSamplePositionsTier, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE& meta_struct = *data;
        FieldToJson(jdata["HighestVersion"], decoded_value.HighestVersion, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ARCHITECTURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["TileBasedRenderer"], decoded_value.TileBasedRenderer, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["UMA"], decoded_value.UMA, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["CacheCoherentUMA"], decoded_value.CacheCoherentUMA, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ARCHITECTURE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["TileBasedRenderer"], decoded_value.TileBasedRenderer, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["UMA"], decoded_value.UMA, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["CacheCoherentUMA"], decoded_value.CacheCoherentUMA, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["IsolatedMMU"], decoded_value.IsolatedMMU, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FEATURE_LEVELS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS& meta_struct = *data;
        FieldToJson(jdata["NumFeatureLevels"], decoded_value.NumFeatureLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pFeatureLevelsRequested"], meta_struct.pFeatureLevelsRequested, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_enum]
        FieldToJson(jdata["MaxSupportedFeatureLevel"], decoded_value.MaxSupportedFeatureLevel, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADER_MODEL& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL& meta_struct = *data;
        FieldToJson(jdata["HighestShaderModel"], decoded_value.HighestShaderModel, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FORMAT_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Support1"], decoded_value.Support1, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Support2"], decoded_value.Support2, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SampleCount"], decoded_value.SampleCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["NumQualityLevels"], decoded_value.NumQualityLevels, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FORMAT_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["PlaneCount"], decoded_value.PlaneCount, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], decoded_value.MaxGPUVirtualAddressBitsPerResource, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerProcess"], decoded_value.MaxGPUVirtualAddressBitsPerProcess, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADER_CACHE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE& meta_struct = *data;
        FieldToJson(jdata["SupportFlags"], decoded_value.SupportFlags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& meta_struct = *data;
        FieldToJson(jdata["CommandListType"], decoded_value.CommandListType, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Priority"], decoded_value.Priority, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["PriorityForTypeIsSupported"], decoded_value.PriorityForTypeIsSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS3& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3& meta_struct = *data;
        Bool32ToJson(jdata["CopyQueueTimestampQueriesSupported"], decoded_value.CopyQueueTimestampQueriesSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["CastingFullyTypedFormatSupported"], decoded_value.CastingFullyTypedFormatSupported, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["WriteBufferImmediateSupportFlags"], decoded_value.WriteBufferImmediateSupportFlags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ViewInstancingTier"], decoded_value.ViewInstancingTier, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["BarycentricsSupported"], decoded_value.BarycentricsSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_EXISTING_HEAPS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS& meta_struct = *data;
        Bool32ToJson(jdata["Supported"], decoded_value.Supported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_DISPLAYABLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE& meta_struct = *data;
        Bool32ToJson(jdata["DisplayableTexture"], decoded_value.DisplayableTexture, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["SharedResourceCompatibilityTier"], decoded_value.SharedResourceCompatibilityTier, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS4& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4& meta_struct = *data;
        Bool32ToJson(jdata["MSAA64KBAlignedTextureSupported"], decoded_value.MSAA64KBAlignedTextureSupported, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["SharedResourceCompatibilityTier"], decoded_value.SharedResourceCompatibilityTier, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["Native16BitShaderOpsSupported"], decoded_value.Native16BitShaderOpsSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SERIALIZATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SERIALIZATION& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["HeapSerializationTier"], decoded_value.HeapSerializationTier, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_CROSS_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_CROSS_NODE& meta_struct = *data;
        FieldToJson(jdata["SharingTier"], decoded_value.SharingTier, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["AtomicShaderInstructions"], decoded_value.AtomicShaderInstructions, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS5& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5& meta_struct = *data;
        Bool32ToJson(jdata["SRVOnlyTiledResourceTier3"], decoded_value.SRVOnlyTiledResourceTier3, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["RenderPassesTier"], decoded_value.RenderPassesTier, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["RaytracingTier"], decoded_value.RaytracingTier, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS6& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6& meta_struct = *data;
        Bool32ToJson(jdata["AdditionalShadingRatesSupported"], decoded_value.AdditionalShadingRatesSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["PerPrimitiveShadingRateSupportedWithViewportIndexing"], decoded_value.PerPrimitiveShadingRateSupportedWithViewportIndexing, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["VariableShadingRateTier"], decoded_value.VariableShadingRateTier, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ShadingRateImageTileSize"], decoded_value.ShadingRateImageTileSize, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["BackgroundProcessingSupported"], decoded_value.BackgroundProcessingSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS7& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7& meta_struct = *data;
        FieldToJson(jdata["MeshShaderTier"], decoded_value.MeshShaderTier, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SamplerFeedbackTier"], decoded_value.SamplerFeedbackTier, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_QUERY_META_COMMAND& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND& meta_struct = *data;
        FieldToJson(jdata["CommandId"], meta_struct.CommandId, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pQueryInputData"], meta_struct.pQueryInputData, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array]
        FieldToJson(jdata["QueryInputDataSizeInBytes"], decoded_value.QueryInputDataSizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pQueryOutputData"], meta_struct.pQueryOutputData, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array]
        FieldToJson(jdata["QueryOutputDataSizeInBytes"], decoded_value.QueryOutputDataSizeInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS8& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8& meta_struct = *data;
        Bool32ToJson(jdata["UnalignedBlockTexturesSupported"], decoded_value.UnalignedBlockTexturesSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS9& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9& meta_struct = *data;
        Bool32ToJson(jdata["MeshShaderPipelineStatsSupported"], decoded_value.MeshShaderPipelineStatsSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["MeshShaderSupportsFullRangeRenderTargetArrayIndex"], decoded_value.MeshShaderSupportsFullRangeRenderTargetArrayIndex, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["AtomicInt64OnTypedResourceSupported"], decoded_value.AtomicInt64OnTypedResourceSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["AtomicInt64OnGroupSharedSupported"], decoded_value.AtomicInt64OnGroupSharedSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["DerivativesInMeshAndAmplificationShadersSupported"], decoded_value.DerivativesInMeshAndAmplificationShadersSupported, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["WaveMMATier"], decoded_value.WaveMMATier, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS10& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10& meta_struct = *data;
        Bool32ToJson(jdata["VariableRateShadingSumCombinerSupported"], decoded_value.VariableRateShadingSumCombinerSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["MeshShaderPerPrimitiveShadingRateSupported"], decoded_value.MeshShaderPerPrimitiveShadingRateSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS11& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11& meta_struct = *data;
        Bool32ToJson(jdata["AtomicInt64OnDescriptorHeapResourceSupported"], decoded_value.AtomicInt64OnDescriptorHeapResourceSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS12& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12& meta_struct = *data;
        FieldToJson(jdata["MSPrimitivesPipelineStatisticIncludesCulledPrimitives"], decoded_value.MSPrimitivesPipelineStatisticIncludesCulledPrimitives, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["EnhancedBarriersSupported"], decoded_value.EnhancedBarriersSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["RelaxedFormatCastingSupported"], decoded_value.RelaxedFormatCastingSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS13& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13& meta_struct = *data;
        Bool32ToJson(jdata["UnrestrictedBufferTextureCopyPitchSupported"], decoded_value.UnrestrictedBufferTextureCopyPitchSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["UnrestrictedVertexElementAlignmentSupported"], decoded_value.UnrestrictedVertexElementAlignmentSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["InvertedViewportHeightFlipsYSupported"], decoded_value.InvertedViewportHeightFlipsYSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["InvertedViewportDepthFlipsZSupported"], decoded_value.InvertedViewportDepthFlipsZSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["TextureCopyBetweenDimensionsSupported"], decoded_value.TextureCopyBetweenDimensionsSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["AlphaBlendFactorSupported"], decoded_value.AlphaBlendFactorSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS14& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14& meta_struct = *data;
        Bool32ToJson(jdata["AdvancedTextureOpsSupported"], decoded_value.AdvancedTextureOpsSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["WriteableMSAATexturesSupported"], decoded_value.WriteableMSAATexturesSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["IndependentFrontAndBackStencilRefMaskSupported"], decoded_value.IndependentFrontAndBackStencilRefMaskSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS15& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15& meta_struct = *data;
        Bool32ToJson(jdata["TriangleFanSupported"], decoded_value.TriangleFanSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["DynamicIndexBufferStripCutSupported"], decoded_value.DynamicIndexBufferStripCutSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS16& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16& meta_struct = *data;
        Bool32ToJson(jdata["DynamicDepthBiasSupported"], decoded_value.DynamicDepthBiasSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["GPUUploadHeapSupported"], decoded_value.GPUUploadHeapSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS17& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17& meta_struct = *data;
        Bool32ToJson(jdata["NonNormalizedCoordinateSamplersSupported"], decoded_value.NonNormalizedCoordinateSamplersSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["ManualWriteTrackingResourceSupported"], decoded_value.ManualWriteTrackingResourceSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS18& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18& meta_struct = *data;
        Bool32ToJson(jdata["RenderPassesValid"], decoded_value.RenderPassesValid, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS19& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19& meta_struct = *data;
        Bool32ToJson(jdata["MismatchingOutputDimensionsSupported"], decoded_value.MismatchingOutputDimensionsSupported, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["SupportedSampleCountsWithNoOutputs"], decoded_value.SupportedSampleCountsWithNoOutputs, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["PointSamplingAddressesNeverRoundUp"], decoded_value.PointSamplingAddressesNeverRoundUp, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["RasterizerDesc2Supported"], decoded_value.RasterizerDesc2Supported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["NarrowQuadrilateralLinesSupported"], decoded_value.NarrowQuadrilateralLinesSupported, options); // Basic data plumbs to raw struct [is_bool]
        Bool32ToJson(jdata["AnisoFilterWithPointMipSupported"], decoded_value.AnisoFilterWithPointMipSupported, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["MaxSamplerDescriptorHeapSize"], decoded_value.MaxSamplerDescriptorHeapSize, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxSamplerDescriptorHeapSizeWithStaticSamplers"], decoded_value.MaxSamplerDescriptorHeapSizeWithStaticSamplers, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxViewDescriptorHeapSize"], decoded_value.MaxViewDescriptorHeapSize, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["ComputeOnlyCustomHeapSupported"], decoded_value.ComputeOnlyCustomHeapSupported, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALLOCATION_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALLOCATION_INFO& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALLOCATION_INFO1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HEAP_PROPERTIES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HEAP_PROPERTIES& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["CPUPageProperty"], decoded_value.CPUPageProperty, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["MemoryPoolPreference"], decoded_value.MemoryPoolPreference, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["CreationNodeMask"], decoded_value.CreationNodeMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["VisibleNodeMask"], decoded_value.VisibleNodeMask, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HEAP_DESC& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Properties"], meta_struct.Properties, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MIP_REGION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MIP_REGION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MIP_REGION& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_DESC& meta_struct = *data;
        FieldToJson(jdata["Dimension"], decoded_value.Dimension, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DepthOrArraySize"], decoded_value.DepthOrArraySize, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Layout"], decoded_value.Layout, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_DESC1& meta_struct = *data;
        FieldToJson(jdata["Dimension"], decoded_value.Dimension, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DepthOrArraySize"], decoded_value.DepthOrArraySize, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Layout"], decoded_value.Layout, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SamplerFeedbackMipRegion"], meta_struct.SamplerFeedbackMipRegion, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_VALUE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_VALUE& meta_struct = *data;
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Stencil"], decoded_value.Stencil, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RANGE& meta_struct = *data;
        FieldToJson(jdata["Begin"], decoded_value.Begin, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["End"], decoded_value.End, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE_UINT64* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RANGE_UINT64& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RANGE_UINT64& meta_struct = *data;
        FieldToJson(jdata["Begin"], decoded_value.Begin, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["End"], decoded_value.End, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_RANGE_UINT64& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64& meta_struct = *data;
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Range"], meta_struct.Range, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_INFO& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DepthPitch"], decoded_value.DepthPitch, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILED_RESOURCE_COORDINATE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILED_RESOURCE_COORDINATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILED_RESOURCE_COORDINATE& meta_struct = *data;
        FieldToJson(jdata["X"], decoded_value.X, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Y"], decoded_value.Y, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Z"], decoded_value.Z, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_REGION_SIZE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILE_REGION_SIZE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILE_REGION_SIZE& meta_struct = *data;
        FieldToJson(jdata["NumTiles"], decoded_value.NumTiles, options); // Basic data plumbs to raw struct
        Bool32ToJson(jdata["UseBox"], decoded_value.UseBox, options); // Basic data plumbs to raw struct [is_bool]
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_TILING* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_TILING& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_TILING& meta_struct = *data;
        FieldToJson(jdata["WidthInTiles"], decoded_value.WidthInTiles, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["HeightInTiles"], decoded_value.HeightInTiles, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DepthInTiles"], decoded_value.DepthInTiles, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StartTileIndexInOverallResource"], decoded_value.StartTileIndexInOverallResource, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_SHAPE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILE_SHAPE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILE_SHAPE& meta_struct = *data;
        FieldToJson(jdata["WidthInTexels"], decoded_value.WidthInTexels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["HeightInTexels"], decoded_value.HeightInTexels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DepthInTexels"], decoded_value.DepthInTexels, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PACKED_MIP_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PACKED_MIP_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PACKED_MIP_INFO& meta_struct = *data;
        FieldToJson(jdata["NumStandardMips"], decoded_value.NumStandardMips, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumPackedMips"], decoded_value.NumPackedMips, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumTilesForPackedMips"], decoded_value.NumTilesForPackedMips, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StartTileIndexInOverallResource"], decoded_value.StartTileIndexInOverallResource, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_TRANSITION_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER& meta_struct = *data;
        FieldToJson(jdata["pResource"], meta_struct.pResource, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StateBefore"], decoded_value.StateBefore, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["StateAfter"], decoded_value.StateAfter, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALIASING_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALIASING_BARRIER& meta_struct = *data;
        FieldToJson(jdata["pResourceBefore"], meta_struct.pResourceBefore, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pResourceAfter"], meta_struct.pResourceAfter, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_UAV_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_UAV_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_UAV_BARRIER& meta_struct = *data;
        FieldToJson(jdata["pResource"], meta_struct.pResource, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_FOOTPRINT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_FOOTPRINT& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Footprint"], meta_struct.Footprint, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_POSITION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLE_POSITION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLE_POSITION& meta_struct = *data;
        FieldToJson(jdata["X"], decoded_value.X, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Y"], decoded_value.Y, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCE_LOCATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEW_INSTANCE_LOCATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEW_INSTANCE_LOCATION& meta_struct = *data;
        FieldToJson(jdata["ViewportArrayIndex"], decoded_value.ViewportArrayIndex, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RenderTargetArrayIndex"], decoded_value.RenderTargetArrayIndex, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCING_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEW_INSTANCING_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEW_INSTANCING_DESC& meta_struct = *data;
        FieldToJson(jdata["ViewInstanceCount"], decoded_value.ViewInstanceCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pViewInstanceLocations"], meta_struct.pViewInstanceLocations, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_SRV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StructureByteStride"], decoded_value.StructureByteStride, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXCUBE_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXCUBE_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXCUBE_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXCUBE_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["First2DArrayFace"], decoded_value.First2DArrayFace, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumCubes"], decoded_value.NumCubes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_SRV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& meta_struct = *data;
        FieldToJson(jdata["Location"], decoded_value.Location, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_RESOURCE_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Shader4ComponentMapping"], decoded_value.Shader4ComponentMapping, options); // Basic data plumbs to raw struct
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
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLER_DESC& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["BorderColor"], meta_struct.BorderColor, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLER_DESC2& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options); // Basic data plumbs to raw struct [is_enum]
        if(decoded_value.Flags & D3D12_SAMPLER_FLAG_UINT_BORDER_COLOR)
        {
            FieldToJson(jdata["UintBorderColor"], decoded_value.UintBorderColor, options);
        }
        else
        {
            FieldToJson(jdata["FloatBorderColor"], decoded_value.FloatBorderColor, options);
        }
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_UAV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StructureByteStride"], decoded_value.StructureByteStride, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CounterOffsetInBytes"], decoded_value.CounterOffsetInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_UAV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstWSlice"], decoded_value.FirstWSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["WSize"], decoded_value.WSize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_UNORDERED_ACCESS_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options); // Basic data plumbs to raw struct [is_enum]
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
                FieldToJson(jdata["Texture2DMS"], "Field missing from Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC.", options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], "Field missing from Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC.", options);
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
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_RTV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstWSlice"], decoded_value.FirstWSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["WSize"], decoded_value.WSize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_TARGET_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_TARGET_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options); // Basic data plumbs to raw struct [is_enum]
        switch(decoded_value.ViewDimension)
        {
            case D3D12_RTV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC. Uninitialised struct?", options);
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
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_DSV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        switch(decoded_value.ViewDimension)
        {
            case D3D12_DSV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC. Uninitialised struct?", options);
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
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_RANGE& meta_struct = *data;
        FieldToJson(jdata["RangeType"], decoded_value.RangeType, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["BaseShaderRegister"], decoded_value.BaseShaderRegister, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], decoded_value.OffsetInDescriptorsFromTableStart, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR_TABLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE& meta_struct = *data;
        FieldToJson(jdata["NumDescriptorRanges"], decoded_value.NumDescriptorRanges, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pDescriptorRanges"], meta_struct.pDescriptorRanges, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_CONSTANTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_CONSTANTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_CONSTANTS& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Num32BitValues"], decoded_value.Num32BitValues, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_PARAMETER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_PARAMETER& meta_struct = *data;
        FieldToJson(jdata["ParameterType"], decoded_value.ParameterType, options); // Basic data plumbs to raw struct [is_enum]
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
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATIC_SAMPLER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATIC_SAMPLER_DESC& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["BorderColor"], decoded_value.BorderColor, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATIC_SAMPLER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATIC_SAMPLER_DESC1& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["BorderColor"], decoded_value.BorderColor, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pParameters"], meta_struct.pParameters, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pStaticSamplers"], meta_struct.pStaticSamplers, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_RANGE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_RANGE1& meta_struct = *data;
        FieldToJson(jdata["RangeType"], decoded_value.RangeType, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["BaseShaderRegister"], decoded_value.BaseShaderRegister, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], decoded_value.OffsetInDescriptorsFromTableStart, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR_TABLE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1& meta_struct = *data;
        FieldToJson(jdata["NumDescriptorRanges"], decoded_value.NumDescriptorRanges, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pDescriptorRanges"], meta_struct.pDescriptorRanges, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR1& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_PARAMETER1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_PARAMETER1& meta_struct = *data;
        FieldToJson(jdata["ParameterType"], decoded_value.ParameterType, options); // Basic data plumbs to raw struct [is_enum]
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
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_ROOT_PARAMETER_TYPE in D3D12_ROOT_PARAMETER1. Uninitialised or corrupt struct?", options);
                FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ParameterType), options);
                break;
            }
        }
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC1& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pParameters"], meta_struct.pParameters, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pStaticSamplers"], meta_struct.pStaticSamplers, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC2& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pParameters"], meta_struct.pParameters, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pStaticSamplers"], meta_struct.pStaticSamplers, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["Version"], decoded_value.Version, options); // Basic data plumbs to raw struct [is_enum]
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
                /// @todo Uncomment this once the union member is added to the decoded struct: FieldToJson(jdata["Desc_1_2"], meta_struct.Desc_1_2, options);
                GFXRECON_LOG_ERROR("Unknown D3D_ROOT_SIGNATURE_VERSION_1_2 in D3D12_VERSIONED_ROOT_SIGNATURE_DESC.");
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D_ROOT_SIGNATURE_VERSION in D3D12_VERSIONED_ROOT_SIGNATURE_DESC. Uninitialised or corrupt struct?", options);
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
        FieldToJson(jdata["ptr"], decoded_value.ptr, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_DESCRIPTOR_HANDLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE& meta_struct = *data;
        FieldToJson(jdata["ptr"], decoded_value.ptr, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISCARD_REGION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISCARD_REGION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISCARD_REGION& meta_struct = *data;
        FieldToJson(jdata["NumRects"], decoded_value.NumRects, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pRects"], meta_struct.pRects, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["FirstSubresource"], decoded_value.FirstSubresource, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumSubresources"], decoded_value.NumSubresources, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_HEAP_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Count"], decoded_value.Count, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_PIPELINE_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["IAVertices"], decoded_value.IAVertices, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["IAPrimitives"], decoded_value.IAPrimitives, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["VSInvocations"], decoded_value.VSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["GSInvocations"], decoded_value.GSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["GSPrimitives"], decoded_value.GSPrimitives, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CInvocations"], decoded_value.CInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CPrimitives"], decoded_value.CPrimitives, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PSInvocations"], decoded_value.PSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["HSInvocations"], decoded_value.HSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DSInvocations"], decoded_value.DSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CSInvocations"], decoded_value.CSInvocations, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1& meta_struct = *data;
        FieldToJson(jdata["IAVertices"], decoded_value.IAVertices, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["IAPrimitives"], decoded_value.IAPrimitives, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["VSInvocations"], decoded_value.VSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["GSInvocations"], decoded_value.GSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["GSPrimitives"], decoded_value.GSPrimitives, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CInvocations"], decoded_value.CInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CPrimitives"], decoded_value.CPrimitives, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PSInvocations"], decoded_value.PSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["HSInvocations"], decoded_value.HSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DSInvocations"], decoded_value.DSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["CSInvocations"], decoded_value.CSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ASInvocations"], decoded_value.ASInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MSInvocations"], decoded_value.MSInvocations, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MSPrimitives"], decoded_value.MSPrimitives, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_SO_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_SO_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["NumPrimitivesWritten"], decoded_value.NumPrimitivesWritten, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["PrimitivesStorageNeeded"], decoded_value.PrimitivesStorageNeeded, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STREAM_OUTPUT_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["BufferFilledSizeLocation"], decoded_value.BufferFilledSizeLocation, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRAW_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRAW_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["VertexCountPerInstance"], decoded_value.VertexCountPerInstance, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["InstanceCount"], decoded_value.InstanceCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StartVertexLocation"], decoded_value.StartVertexLocation, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StartInstanceLocation"], decoded_value.StartInstanceLocation, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRAW_INDEXED_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["IndexCountPerInstance"], decoded_value.IndexCountPerInstance, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["InstanceCount"], decoded_value.InstanceCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StartIndexLocation"], decoded_value.StartIndexLocation, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["BaseVertexLocation"], decoded_value.BaseVertexLocation, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StartInstanceLocation"], decoded_value.StartInstanceLocation, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["ThreadGroupCountX"], decoded_value.ThreadGroupCountX, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ThreadGroupCountY"], decoded_value.ThreadGroupCountY, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ThreadGroupCountZ"], decoded_value.ThreadGroupCountZ, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERTEX_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERTEX_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERTEX_BUFFER_VIEW& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDEX_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INDEX_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INDEX_BUFFER_VIEW& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDIRECT_ARGUMENT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INDIRECT_ARGUMENT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INDIRECT_ARGUMENT_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
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
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_INDIRECT_ARGUMENT_TYPE in D3D12_INDIRECT_ARGUMENT_DESC. Uninitialised or corrupt struct?", options);
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
        FieldToJson(jdata["ByteStride"], decoded_value.ByteStride, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumArgumentDescs"], decoded_value.NumArgumentDescs, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pArgumentDescs"], meta_struct.pArgumentDescs, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& meta_struct = *data;
        FieldToJson(jdata["Dest"], decoded_value.Dest, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Value"], decoded_value.Value, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Support"], decoded_value.Support, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC& meta_struct = *data;
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_META_COMMAND_PARAMETER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_META_COMMAND_PARAMETER_DESC& meta_struct = *data;
        FieldToJson(jdata["Name"], meta_struct.Name, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["RequiredResourceState"], decoded_value.RequiredResourceState, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["StructureOffset"], decoded_value.StructureOffset, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_META_COMMAND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_META_COMMAND_DESC& meta_struct = *data;
        FieldToJson(jdata["Id"], meta_struct.Id, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Name"], meta_struct.Name, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["InitializationDirtyState"], decoded_value.InitializationDirtyState, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ExecutionDirtyState"], decoded_value.ExecutionDirtyState, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_OBJECT_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_OBJECT_CONFIG& meta_struct = *data;
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE& meta_struct = *data;
        FieldToJson(jdata["pGlobalRootSignature"], meta_struct.pGlobalRootSignature, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_LOCAL_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_LOCAL_ROOT_SIGNATURE& meta_struct = *data;
        FieldToJson(jdata["pLocalRootSignature"], meta_struct.pLocalRootSignature, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_NODE_MASK& decoded_value = *data->decoded_value;
        const Decoded_D3D12_NODE_MASK& meta_struct = *data;
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_EXPORT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXPORT_DESC& meta_struct = *data;
        FieldToJson(jdata["Name"], meta_struct.Name, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["ExportToRename"], meta_struct.ExportToRename, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DXIL_LIBRARY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DXIL_LIBRARY_DESC& meta_struct = *data;
        FieldToJson(jdata["DXILLibrary"], meta_struct.DXILLibrary, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pExports"], meta_struct.pExports, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_EXISTING_COLLECTION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXISTING_COLLECTION_DESC& meta_struct = *data;
        FieldToJson(jdata["pExistingCollection"], meta_struct.pExistingCollection, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pExports"], meta_struct.pExports, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& meta_struct = *data;
        FieldToJson(jdata["pSubobjectToAssociate"], meta_struct.pSubobjectToAssociate, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pExports"], meta_struct.pExports, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& meta_struct = *data;
        FieldToJson(jdata["SubobjectToAssociate"], meta_struct.SubobjectToAssociate, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pExports"], meta_struct.pExports, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HIT_GROUP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HIT_GROUP_DESC& meta_struct = *data;
        FieldToJson(jdata["HitGroupExport"], meta_struct.HitGroupExport, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AnyHitShaderImport"], meta_struct.AnyHitShaderImport, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["ClosestHitShaderImport"], meta_struct.ClosestHitShaderImport, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["IntersectionShaderImport"], meta_struct.IntersectionShaderImport, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_SHADER_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_SHADER_CONFIG& meta_struct = *data;
        FieldToJson(jdata["MaxPayloadSizeInBytes"], decoded_value.MaxPayloadSizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxAttributeSizeInBytes"], decoded_value.MaxAttributeSizeInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_PIPELINE_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG& meta_struct = *data;
        FieldToJson(jdata["MaxTraceRecursionDepth"], decoded_value.MaxTraceRecursionDepth, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_PIPELINE_CONFIG1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1& meta_struct = *data;
        FieldToJson(jdata["MaxTraceRecursionDepth"], decoded_value.MaxTraceRecursionDepth, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_OBJECT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_OBJECT_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["NumSubobjects"], decoded_value.NumSubobjects, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pSubobjects"], meta_struct.pSubobjects, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& meta_struct = *data;
        FieldToJson(jdata["StartAddress"], decoded_value.StartAddress, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE& meta_struct = *data;
        FieldToJson(jdata["StartAddress"], decoded_value.StartAddress, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& meta_struct = *data;
        FieldToJson(jdata["StartAddress"], decoded_value.StartAddress, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& meta_struct = *data;
        FieldToJson(jdata["Transform3x4"], decoded_value.Transform3x4, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["IndexFormat"], decoded_value.IndexFormat, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["VertexFormat"], decoded_value.VertexFormat, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["IndexCount"], decoded_value.IndexCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["VertexCount"], decoded_value.VertexCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["IndexBuffer"], decoded_value.IndexBuffer, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["VertexBuffer"], meta_struct.VertexBuffer, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_AABB* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_AABB& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_AABB& meta_struct = *data;
        FieldToJson(jdata["MinX"], decoded_value.MinX, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MinY"], decoded_value.MinY, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MinZ"], decoded_value.MinZ, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxX"], decoded_value.MaxX, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxY"], decoded_value.MaxY, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaxZ"], decoded_value.MaxZ, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& meta_struct = *data;
        FieldToJson(jdata["AABBCount"], decoded_value.AABBCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AABBs"], meta_struct.AABBs, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& meta_struct = *data;
        FieldToJson(jdata["DestBuffer"], decoded_value.DestBuffer, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["InfoType"], decoded_value.InfoType, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& meta_struct = *data;
        FieldToJson(jdata["CompactedSizeInBytes"], decoded_value.CompactedSizeInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& meta_struct = *data;
        FieldToJson(jdata["DecodedSizeInBytes"], decoded_value.DecodedSizeInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["NumDescs"], decoded_value.NumDescs, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& meta_struct = *data;
        FieldToJson(jdata["SerializedSizeInBytes"], decoded_value.SerializedSizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumBottomLevelAccelerationStructurePointers"], decoded_value.NumBottomLevelAccelerationStructurePointers, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& meta_struct = *data;
        FieldToJson(jdata["DriverOpaqueGUID"], meta_struct.DriverOpaqueGUID, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["DriverOpaqueVersioningData"], meta_struct.DriverOpaqueVersioningData, options); // Complex types and handles plumb to the decoded struct [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& meta_struct = *data;
        FieldToJson(jdata["DriverMatchingIdentifier"], meta_struct.DriverMatchingIdentifier, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["SerializedSizeInBytesIncludingHeader"], decoded_value.SerializedSizeInBytesIncludingHeader, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DeserializedSizeInBytes"], decoded_value.DeserializedSizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumBottomLevelAccelerationStructurePointersAfterHeader"], decoded_value.NumBottomLevelAccelerationStructurePointersAfterHeader, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& meta_struct = *data;
        FieldToJson(jdata["CurrentSizeInBytes"], decoded_value.CurrentSizeInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_INSTANCE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_INSTANCE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_INSTANCE_DESC& meta_struct = *data;
        FieldToJson(jdata["Transform"], meta_struct.Transform, options); // Complex types and handles plumb to the decoded struct [is_array]
        FieldToJson(jdata["InstanceID"], decoded_value.InstanceID, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["InstanceMask"], decoded_value.InstanceMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["InstanceContributionToHitGroupIndex"], decoded_value.InstanceContributionToHitGroupIndex, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AccelerationStructure"], decoded_value.AccelerationStructure, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
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
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RAYTRACING_GEOMETRY_TYPE in D3D12_RAYTRACING_GEOMETRY_DESC. Uninitialised or corrupt struct?", options);
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
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["NumDescs"], decoded_value.NumDescs, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DescsLayout"], decoded_value.DescsLayout, options); // Basic data plumbs to raw struct [is_enum]
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
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE in D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS. Uninitialised or corrupt struct?", options);
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
        FieldToJson(jdata["DestAccelerationStructureData"], decoded_value.DestAccelerationStructureData, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Inputs"], meta_struct.Inputs, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["SourceAccelerationStructureData"], decoded_value.SourceAccelerationStructureData, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ScratchAccelerationStructureData"], decoded_value.ScratchAccelerationStructureData, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& meta_struct = *data;
        FieldToJson(jdata["ResultDataMaxSizeInBytes"], decoded_value.ResultDataMaxSizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ScratchDataSizeInBytes"], decoded_value.ScratchDataSizeInBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["UpdateScratchDataSizeInBytes"], decoded_value.UpdateScratchDataSizeInBytes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_AUTO_BREADCRUMB_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_AUTO_BREADCRUMB_NODE& meta_struct = *data;
        FieldToJson(jdata["pCommandListDebugNameA"], meta_struct.pCommandListDebugNameA, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandListDebugNameW"], meta_struct.pCommandListDebugNameW, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandQueueDebugNameA"], meta_struct.pCommandQueueDebugNameA, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandQueueDebugNameW"], meta_struct.pCommandQueueDebugNameW, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandList"], meta_struct.pCommandList, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandQueue"], meta_struct.pCommandQueue, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["BreadcrumbCount"], decoded_value.BreadcrumbCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pLastBreadcrumbValue"], meta_struct.pLastBreadcrumbValue, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandHistory"], meta_struct.pCommandHistory, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_enum]
        FieldToJson(jdata["pNext"], meta_struct.pNext, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_BREADCRUMB_CONTEXT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT& meta_struct = *data;
        FieldToJson(jdata["BreadcrumbIndex"], decoded_value.BreadcrumbIndex, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pContextString"], meta_struct.pContextString, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_AUTO_BREADCRUMB_NODE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_AUTO_BREADCRUMB_NODE1& meta_struct = *data;
        FieldToJson(jdata["pCommandListDebugNameA"], meta_struct.pCommandListDebugNameA, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandListDebugNameW"], meta_struct.pCommandListDebugNameW, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandQueueDebugNameA"], meta_struct.pCommandQueueDebugNameA, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandQueueDebugNameW"], meta_struct.pCommandQueueDebugNameW, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandList"], meta_struct.pCommandList, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandQueue"], meta_struct.pCommandQueue, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["BreadcrumbCount"], decoded_value.BreadcrumbCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pLastBreadcrumbValue"], meta_struct.pLastBreadcrumbValue, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pCommandHistory"], meta_struct.pCommandHistory, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_enum]
        FieldToJson(jdata["pNext"], meta_struct.pNext, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
        FieldToJson(jdata["BreadcrumbContextsCount"], decoded_value.BreadcrumbContextsCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pBreadcrumbContexts"], meta_struct.pBreadcrumbContexts, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA& meta_struct = *data;
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], meta_struct.pHeadAutoBreadcrumbNode, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_ALLOCATION_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_ALLOCATION_NODE& meta_struct = *data;
        FieldToJson(jdata["ObjectNameA"], meta_struct.ObjectNameA, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["ObjectNameW"], meta_struct.ObjectNameW, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["AllocationType"], decoded_value.AllocationType, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["pNext"], meta_struct.pNext, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_ALLOCATION_NODE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_ALLOCATION_NODE1& meta_struct = *data;
        FieldToJson(jdata["ObjectNameA"], meta_struct.ObjectNameA, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["ObjectNameW"], meta_struct.ObjectNameW, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["AllocationType"], decoded_value.AllocationType, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["pNext"], meta_struct.pNext, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
        FieldToJson(jdata["pObject"], meta_struct.pObject, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& meta_struct = *data;
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], meta_struct.pHeadAutoBreadcrumbNode, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& meta_struct = *data;
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], meta_struct.pHeadAutoBreadcrumbNode, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT& meta_struct = *data;
        FieldToJson(jdata["PageFaultVA"], decoded_value.PageFaultVA, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pHeadExistingAllocationNode"], meta_struct.pHeadExistingAllocationNode, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], meta_struct.pHeadRecentFreedAllocationNode, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1& meta_struct = *data;
        FieldToJson(jdata["PageFaultVA"], decoded_value.PageFaultVA, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pHeadExistingAllocationNode"], meta_struct.pHeadExistingAllocationNode, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], meta_struct.pHeadRecentFreedAllocationNode, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2& meta_struct = *data;
        FieldToJson(jdata["PageFaultVA"], decoded_value.PageFaultVA, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pHeadExistingAllocationNode"], meta_struct.pHeadExistingAllocationNode, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], meta_struct.pHeadRecentFreedAllocationNode, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_struct]
        FieldToJson(jdata["PageFaultFlags"], decoded_value.PageFaultFlags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1& meta_struct = *data;
        FieldToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AutoBreadcrumbsOutput"], meta_struct.AutoBreadcrumbsOutput, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["PageFaultOutput"], meta_struct.PageFaultOutput, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2& meta_struct = *data;
        FieldToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AutoBreadcrumbsOutput"], meta_struct.AutoBreadcrumbsOutput, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["PageFaultOutput"], meta_struct.PageFaultOutput, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3& meta_struct = *data;
        FieldToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AutoBreadcrumbsOutput"], meta_struct.AutoBreadcrumbsOutput, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["PageFaultOutput"], meta_struct.PageFaultOutput, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["DeviceState"], decoded_value.DeviceState, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& meta_struct = *data;
        FieldToJson(jdata["Version"], decoded_value.Version, options); // Basic data plumbs to raw struct [is_enum]
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
                // This field was missing in the custom struct at time of writing.
                // See issue and revise this codegen by uncommenting line below when the issue
                // is fixed <https://github.com/LunarG/gfxreconstruct/issues/1351>
                // FieldToJson(jdata["Dred_1_3"], meta_struct.Dred_1_3, options);
                FieldToJson(jdata[format::kNameWarning], "Dred_1_3 is not supported by GFXR at this time. Please file an issue quoting this text if this is a blocker for you.", options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DRED_VERSION in D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA. Uninitialised or corrupt struct?", options);
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
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Count"], decoded_value.Count, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Count"], decoded_value.Count, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pTypes"], meta_struct.pTypes, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1& meta_struct = *data;
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ProtectionType"], meta_struct.ProtectionType, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["ClearValue"], meta_struct.ClearValue, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["AdditionalWidth"], decoded_value.AdditionalWidth, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AdditionalHeight"], decoded_value.AdditionalHeight, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
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
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE in D3D12_RENDER_PASS_BEGINNING_ACCESS. Uninitialised or corrupt struct?", options);
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
        FieldToJson(jdata["SrcSubresource"], decoded_value.SrcSubresource, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DstSubresource"], decoded_value.DstSubresource, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DstX"], decoded_value.DstX, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DstY"], decoded_value.DstY, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SrcRect"], meta_struct.SrcRect, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["pSrcResource"], meta_struct.pSrcResource, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["pDstResource"], meta_struct.pDstResource, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["SubresourceCount"], decoded_value.SubresourceCount, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pSubresourceParameters"], meta_struct.pSubresourceParameters, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["Format"], decoded_value.Format, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ResolveMode"], decoded_value.ResolveMode, options); // Basic data plumbs to raw struct [is_enum]
        Bool32ToJson(jdata["PreserveResolveSource"], decoded_value.PreserveResolveSource, options); // Basic data plumbs to raw struct [is_bool]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["AdditionalWidth"], decoded_value.AdditionalWidth, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["AdditionalHeight"], decoded_value.AdditionalHeight, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
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
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RENDER_PASS_ENDING_ACCESS_TYPE in D3D12_RENDER_PASS_ENDING_ACCESS. Uninitialised or corrupt struct?", options);
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
        FieldToJson(jdata["cpuDescriptor"], meta_struct.cpuDescriptor, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["BeginningAccess"], meta_struct.BeginningAccess, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["EndingAccess"], meta_struct.EndingAccess, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& meta_struct = *data;
        FieldToJson(jdata["cpuDescriptor"], meta_struct.cpuDescriptor, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["DepthBeginningAccess"], meta_struct.DepthBeginningAccess, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["StencilBeginningAccess"], meta_struct.StencilBeginningAccess, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["DepthEndingAccess"], meta_struct.DepthEndingAccess, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["StencilEndingAccess"], meta_struct.StencilEndingAccess, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_RAYS_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_RAYS_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_RAYS_DESC& meta_struct = *data;
        FieldToJson(jdata["RayGenerationShaderRecord"], meta_struct.RayGenerationShaderRecord, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["MissShaderTable"], meta_struct.MissShaderTable, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["HitGroupTable"], meta_struct.HitGroupTable, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["CallableShaderTable"], meta_struct.CallableShaderTable, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Width"], decoded_value.Width, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Height"], decoded_value.Height, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_CACHE_SESSION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_CACHE_SESSION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_CACHE_SESSION_DESC& meta_struct = *data;
        FieldToJson(jdata["Identifier"], meta_struct.Identifier, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Mode"], decoded_value.Mode, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["MaximumInMemoryCacheSizeBytes"], decoded_value.MaximumInMemoryCacheSizeBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaximumInMemoryCacheEntries"], decoded_value.MaximumInMemoryCacheEntries, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["MaximumValueFileSizeBytes"], decoded_value.MaximumValueFileSizeBytes, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Version"], decoded_value.Version, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BARRIER_SUBRESOURCE_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE& meta_struct = *data;
        FieldToJson(jdata["IndexOrFirstMipLevel"], decoded_value.IndexOrFirstMipLevel, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumMipLevels"], decoded_value.NumMipLevels, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumArraySlices"], decoded_value.NumArraySlices, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["FirstPlane"], decoded_value.FirstPlane, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumPlanes"], decoded_value.NumPlanes, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_BARRIER& meta_struct = *data;
        FieldToJson(jdata["SyncBefore"], decoded_value.SyncBefore, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SyncAfter"], decoded_value.SyncAfter, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AccessBefore"], decoded_value.AccessBefore, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AccessAfter"], decoded_value.AccessAfter, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXTURE_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXTURE_BARRIER& meta_struct = *data;
        FieldToJson(jdata["SyncBefore"], decoded_value.SyncBefore, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SyncAfter"], decoded_value.SyncAfter, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AccessBefore"], decoded_value.AccessBefore, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AccessAfter"], decoded_value.AccessAfter, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["LayoutBefore"], decoded_value.LayoutBefore, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["LayoutAfter"], decoded_value.LayoutAfter, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["pResource"], meta_struct.pResource, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["Subresources"], meta_struct.Subresources, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_BARRIER& meta_struct = *data;
        FieldToJson(jdata["SyncBefore"], decoded_value.SyncBefore, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["SyncAfter"], decoded_value.SyncAfter, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AccessBefore"], decoded_value.AccessBefore, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["AccessAfter"], decoded_value.AccessAfter, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["pResource"], meta_struct.pResource, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["Size"], decoded_value.Size, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_DATA& meta_struct = *data;
        FieldToJson(jdata["pData"], meta_struct.pData, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SlicePitch"], decoded_value.SlicePitch, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MEMCPY_DEST* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MEMCPY_DEST& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MEMCPY_DEST& meta_struct = *data;
        FieldToJson(jdata["pData"], meta_struct.pData, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SlicePitch"], decoded_value.SlicePitch, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_CONFIGURATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_CONFIGURATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_CONFIGURATION_DESC& meta_struct = *data;
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["GpuBasedValidationFlags"], decoded_value.GpuBasedValidationFlags, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["SDKVersion"], decoded_value.SDKVersion, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["NumEnabledExperimentalFeatures"], decoded_value.NumEnabledExperimentalFeatures, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_MESH_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["ThreadGroupCountX"], decoded_value.ThreadGroupCountX, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ThreadGroupCountY"], decoded_value.ThreadGroupCountY, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["ThreadGroupCountZ"], decoded_value.ThreadGroupCountZ, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D_SHADER_MACRO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D_SHADER_MACRO& decoded_value = *data->decoded_value;
        const Decoded_D3D_SHADER_MACRO& meta_struct = *data;
        FieldToJson(jdata["Name"], meta_struct.Name, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["Definition"], meta_struct.Definition, options); // Complex types and handles plumb to the decoded struct [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& meta_struct = *data;
        FieldToJson(jdata["MaxMessagesPerCommandList"], decoded_value.MaxMessagesPerCommandList, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["DefaultShaderPatchMode"], decoded_value.DefaultShaderPatchMode, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["PipelineStateCreateFlags"], decoded_value.PipelineStateCreateFlags, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& meta_struct = *data;
        FieldToJson(jdata["SlowdownFactor"], decoded_value.SlowdownFactor, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& meta_struct = *data;
        FieldToJson(jdata["ShaderPatchMode"], decoded_value.ShaderPatchMode, options); // Basic data plumbs to raw struct [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MESSAGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MESSAGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MESSAGE& meta_struct = *data;
        FieldToJson(jdata["Category"], decoded_value.Category, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["Severity"], decoded_value.Severity, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["ID"], decoded_value.ID, options); // Basic data plumbs to raw struct [is_enum]
        FieldToJson(jdata["pDescription"], meta_struct.pDescription, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        FieldToJson(jdata["DescriptionByteLength"], decoded_value.DescriptionByteLength, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INFO_QUEUE_FILTER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INFO_QUEUE_FILTER_DESC& meta_struct = *data;
        FieldToJson(jdata["NumCategories"], decoded_value.NumCategories, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pCategoryList"], meta_struct.pCategoryList, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_enum]
        FieldToJson(jdata["NumSeverities"], decoded_value.NumSeverities, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pSeverityList"], meta_struct.pSeverityList, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_enum]
        FieldToJson(jdata["NumIDs"], decoded_value.NumIDs, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["pIDList"], meta_struct.pIDList, options); // Complex types and handles plumb to the decoded struct [is_pointer] [is_array] [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INFO_QUEUE_FILTER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INFO_QUEUE_FILTER& meta_struct = *data;
        FieldToJson(jdata["AllowList"], meta_struct.AllowList, options); // Complex types and handles plumb to the decoded struct [is_struct]
        FieldToJson(jdata["DenyList"], meta_struct.DenyList, options); // Complex types and handles plumb to the decoded struct [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const tagRECT& decoded_value = *data->decoded_value;
        const Decoded_tagRECT& meta_struct = *data;
        FieldToJson(jdata["left"], decoded_value.left, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["top"], decoded_value.top, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["right"], decoded_value.right, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["bottom"], decoded_value.bottom, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const tagPOINT& decoded_value = *data->decoded_value;
        const Decoded_tagPOINT& meta_struct = *data;
        FieldToJson(jdata["x"], decoded_value.x, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["y"], decoded_value.y, options); // Basic data plumbs to raw struct
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const _SECURITY_ATTRIBUTES& decoded_value = *data->decoded_value;
        const Decoded__SECURITY_ATTRIBUTES& meta_struct = *data;
        FieldToJson(jdata["nLength"], decoded_value.nLength, options); // Basic data plumbs to raw struct
        FieldToJson(jdata["lpSecurityDescriptor"], meta_struct.lpSecurityDescriptor, options); // Complex types and handles plumb to the decoded struct [is_pointer]
        Bool32ToJson(jdata["bInheritHandle"], decoded_value.bInheritHandle, options); // Basic data plumbs to raw struct [is_bool]
    }
}

/// @defgroup custom_dx12_struct_decoders_to_json_body_generators Custom implementations
/// for troublesome structs.
/// We put the custom implementations in the generator Python here rather than
/// creating a whole new compilation unit for them.
/** @{*/
// Won't be generated as is a <winnt.h> struct.
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

// The decoded struct has a custom implementation.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PIPELINE_STATE_STREAM_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct.
        /// @todo This needs custom handling:
        FieldToJson(jdata["pPipelineStateSubobjectStream"], "ToDo: custom handler required.", options); // Any pointer or thing with a pointer or a handle plumbs to the Decoded type [is_pointer]
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
        FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
        /// @todo This needs custom handling:
        FieldToJson(jdata["pDesc"], "ToDo: custom handler required.", options); // Any pointer or thing with a pointer or a handle plumbs to the Decoded type [is_pointer]
    }
}



//  ============================================================================================================================
/// @todo Pull out the structs below which only fail due to having a union member and use the union injection mechanism instead.

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_GROUP* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BARRIER_GROUP& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BARRIER_GROUP& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["NumBarriers"], decoded_value.NumBarriers, options); //
        /// @todo Implement this union: FieldToJson(jdata[""], decoded_value., options); //
    }
}

/// Manual raw struct functon to be used for Decoded_D3D12_CLEAR_VALUE conversion.
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VALUE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Depth"], obj.Depth, options);
    FieldToJson(jdata["Stencil"], obj.Stencil, options);
}

// D3D12_CLEAR_VALUE contains a union so we need to output depending on the format.
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

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_BARRIER& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        /// @todo Implement this union: FieldToJson(jdata[""], decoded_value., options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_COPY_LOCATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXTURE_COPY_LOCATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXTURE_COPY_LOCATION& meta_struct = *data;
        ; ///< @todo Generate for pResource[None]: ID3D12Resource [is_pointer]
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        /// @todo Implement this union: FieldToJson(jdata[""], decoded_value., options); //
    }
}

/** @} */

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
