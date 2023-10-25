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
#include "generated_dx12_struct_to_json.h"
#include "generated_dx12_struct_decoders.h"
#include "decode/custom_dx12_struct_decoders.h"
#include "decode/decode_json_util.h"
#include "graphics/dx12_util.h"
#include "util/json_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::JsonOptions;

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_FRAME_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_FRAME_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["PresentCount"], decoded_value.PresentCount, options); //
        FieldToJson(jdata["PresentRefreshCount"], decoded_value.PresentRefreshCount, options); //
        FieldToJson(jdata["SyncRefreshCount"], decoded_value.SyncRefreshCount, options); //
        ; ///< @todo Generate for SyncQPCTime[None]: LARGE_INTEGER [is_struct]
        ; ///< @todo Generate for SyncGPUTime[None]: LARGE_INTEGER [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MAPPED_RECT& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MAPPED_RECT& meta_struct = *data;
        FieldToJson(jdata["Pitch"], decoded_value.Pitch, options); //
        ; ///< @todo Generate for pBits[None]: BYTE [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const LUID& decoded_value = *data->decoded_value;
        const Decoded_LUID& meta_struct = *data;
        FieldToJson(jdata["LowPart"], decoded_value.LowPart, options); //
        FieldToJson(jdata["HighPart"], decoded_value.HighPart, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC& meta_struct = *data;
        ; ///< @todo Generate for Description[128]: wchar_t [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); //
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); //
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); //
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); //
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); //
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); //
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); //
        ; ///< @todo Generate for AdapterLuid[None]: LUID [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTPUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTPUT_DESC& meta_struct = *data;
        ; ///< @todo Generate for DeviceName[32]: wchar_t [is_array]
        ; ///< @todo Generate for DesktopCoordinates[None]: tagRECT [is_struct]
        FieldToJson(jdata["AttachedToDesktop"], decoded_value.AttachedToDesktop, options); //
        FieldToJson(jdata["Rotation"], decoded_value.Rotation, options); // [is_enum]
        ; ///< @todo Generate for Monitor[None]: void [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SHARED_RESOURCE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SHARED_RESOURCE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SHARED_RESOURCE& meta_struct = *data;
        ; ///< @todo Generate for Handle[None]: void [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SURFACE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SURFACE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SURFACE_DESC& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_DESC& meta_struct = *data;
        ; ///< @todo Generate for BufferDesc[None]: DXGI_MODE_DESC [is_struct]
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        FieldToJson(jdata["BufferUsage"], decoded_value.BufferUsage, options); //
        FieldToJson(jdata["BufferCount"], decoded_value.BufferCount, options); //
        ; ///< @todo Generate for OutputWindow[None]: void [is_pointer]
        FieldToJson(jdata["Windowed"], decoded_value.Windowed, options); //
        FieldToJson(jdata["SwapEffect"], decoded_value.SwapEffect, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC1& meta_struct = *data;
        ; ///< @todo Generate for Description[128]: wchar_t [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); //
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); //
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); //
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); //
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); //
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); //
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); //
        ; ///< @todo Generate for AdapterLuid[None]: LUID [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DISPLAY_COLOR_SPACE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_DISPLAY_COLOR_SPACE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_DISPLAY_COLOR_SPACE& meta_struct = *data;
        ; ///< @todo Generate for PrimaryCoordinates[16]: FLOAT [is_array]
        ; ///< @todo Generate for WhitePoints[32]: FLOAT [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_MOVE_RECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_MOVE_RECT& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_MOVE_RECT& meta_struct = *data;
        ; ///< @todo Generate for SourcePoint[None]: tagPOINT [is_struct]
        ; ///< @todo Generate for DestinationRect[None]: tagRECT [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_DESC& meta_struct = *data;
        ; ///< @todo Generate for ModeDesc[None]: DXGI_MODE_DESC [is_struct]
        FieldToJson(jdata["Rotation"], decoded_value.Rotation, options); // [is_enum]
        FieldToJson(jdata["DesktopImageInSystemMemory"], decoded_value.DesktopImageInSystemMemory, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_POSITION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_POINTER_POSITION& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_POINTER_POSITION& meta_struct = *data;
        ; ///< @todo Generate for Position[None]: tagPOINT [is_struct]
        FieldToJson(jdata["Visible"], decoded_value.Visible, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_POINTER_SHAPE_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); //
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        FieldToJson(jdata["Pitch"], decoded_value.Pitch, options); //
        ; ///< @todo Generate for HotSpot[None]: tagPOINT [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_FRAME_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_FRAME_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_FRAME_INFO& meta_struct = *data;
        ; ///< @todo Generate for LastPresentTime[None]: LARGE_INTEGER [is_struct]
        ; ///< @todo Generate for LastMouseUpdateTime[None]: LARGE_INTEGER [is_struct]
        FieldToJson(jdata["AccumulatedFrames"], decoded_value.AccumulatedFrames, options); //
        FieldToJson(jdata["RectsCoalesced"], decoded_value.RectsCoalesced, options); //
        FieldToJson(jdata["ProtectedContentMaskedOut"], decoded_value.ProtectedContentMaskedOut, options); //
        ; ///< @todo Generate for PointerPosition[None]: DXGI_OUTDUPL_POINTER_POSITION [is_struct]
        FieldToJson(jdata["TotalMetadataBufferSize"], decoded_value.TotalMetadataBufferSize, options); //
        FieldToJson(jdata["PointerShapeBufferSize"], decoded_value.PointerShapeBufferSize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MODE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MODE_DESC1& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        ; ///< @todo Generate for RefreshRate[None]: DXGI_RATIONAL [is_struct]
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["ScanlineOrdering"], decoded_value.ScanlineOrdering, options); // [is_enum]
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options); // [is_enum]
        FieldToJson(jdata["Stereo"], decoded_value.Stereo, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_DESC1& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["Stereo"], decoded_value.Stereo, options); //
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        FieldToJson(jdata["BufferUsage"], decoded_value.BufferUsage, options); //
        FieldToJson(jdata["BufferCount"], decoded_value.BufferCount, options); //
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options); // [is_enum]
        FieldToJson(jdata["SwapEffect"], decoded_value.SwapEffect, options); // [is_enum]
        FieldToJson(jdata["AlphaMode"], decoded_value.AlphaMode, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC& meta_struct = *data;
        ; ///< @todo Generate for RefreshRate[None]: DXGI_RATIONAL [is_struct]
        FieldToJson(jdata["ScanlineOrdering"], decoded_value.ScanlineOrdering, options); // [is_enum]
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options); // [is_enum]
        FieldToJson(jdata["Windowed"], decoded_value.Windowed, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_PRESENT_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_PRESENT_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_PRESENT_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["DirtyRectsCount"], decoded_value.DirtyRectsCount, options); //
        ; ///< @todo Generate for pDirtyRects[DirtyRectsCount]: tagRECT [is_pointer] [is_array] [is_struct]
        ; ///< @todo Generate for pScrollRect[None]: tagRECT [is_pointer] [is_struct]
        ; ///< @todo Generate for pScrollOffset[None]: tagPOINT [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC2& meta_struct = *data;
        ; ///< @todo Generate for Description[128]: wchar_t [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); //
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); //
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); //
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); //
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); //
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); //
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); //
        ; ///< @todo Generate for AdapterLuid[None]: LUID [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); //
        FieldToJson(jdata["GraphicsPreemptionGranularity"], decoded_value.GraphicsPreemptionGranularity, options); // [is_enum]
        FieldToJson(jdata["ComputePreemptionGranularity"], decoded_value.ComputePreemptionGranularity, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MATRIX_3X2_F* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MATRIX_3X2_F& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MATRIX_3X2_F& meta_struct = *data;
        FieldToJson(jdata["_11"], decoded_value._11, options); //
        FieldToJson(jdata["_12"], decoded_value._12, options); //
        FieldToJson(jdata["_21"], decoded_value._21, options); //
        FieldToJson(jdata["_22"], decoded_value._22, options); //
        FieldToJson(jdata["_31"], decoded_value._31, options); //
        FieldToJson(jdata["_32"], decoded_value._32, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_DECODE_SWAP_CHAIN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC& meta_struct = *data;
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS_MEDIA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_FRAME_STATISTICS_MEDIA& decoded_value = *data->decoded_value;
        const Decoded_DXGI_FRAME_STATISTICS_MEDIA& meta_struct = *data;
        FieldToJson(jdata["PresentCount"], decoded_value.PresentCount, options); //
        FieldToJson(jdata["PresentRefreshCount"], decoded_value.PresentRefreshCount, options); //
        FieldToJson(jdata["SyncRefreshCount"], decoded_value.SyncRefreshCount, options); //
        ; ///< @todo Generate for SyncQPCTime[None]: LARGE_INTEGER [is_struct]
        ; ///< @todo Generate for SyncGPUTime[None]: LARGE_INTEGER [is_struct]
        FieldToJson(jdata["CompositionMode"], decoded_value.CompositionMode, options); // [is_enum]
        FieldToJson(jdata["ApprovedPresentDuration"], decoded_value.ApprovedPresentDuration, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_QUERY_VIDEO_MEMORY_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO& meta_struct = *data;
        FieldToJson(jdata["Budget"], decoded_value.Budget, options); //
        FieldToJson(jdata["CurrentUsage"], decoded_value.CurrentUsage, options); //
        FieldToJson(jdata["AvailableForReservation"], decoded_value.AvailableForReservation, options); //
        FieldToJson(jdata["CurrentReservation"], decoded_value.CurrentReservation, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_HDR_METADATA_HDR10& decoded_value = *data->decoded_value;
        const Decoded_DXGI_HDR_METADATA_HDR10& meta_struct = *data;
        ; ///< @todo Generate for RedPrimary[2]: UINT16 [is_array]
        ; ///< @todo Generate for GreenPrimary[2]: UINT16 [is_array]
        ; ///< @todo Generate for BluePrimary[2]: UINT16 [is_array]
        ; ///< @todo Generate for WhitePoint[2]: UINT16 [is_array]
        FieldToJson(jdata["MaxMasteringLuminance"], decoded_value.MaxMasteringLuminance, options); //
        FieldToJson(jdata["MinMasteringLuminance"], decoded_value.MinMasteringLuminance, options); //
        FieldToJson(jdata["MaxContentLightLevel"], decoded_value.MaxContentLightLevel, options); //
        FieldToJson(jdata["MaxFrameAverageLightLevel"], decoded_value.MaxFrameAverageLightLevel, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10PLUS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_HDR_METADATA_HDR10PLUS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_HDR_METADATA_HDR10PLUS& meta_struct = *data;
        ; ///< @todo Generate for Data[72]: BYTE [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC3& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC3& meta_struct = *data;
        ; ///< @todo Generate for Description[128]: wchar_t [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); //
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); //
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); //
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); //
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); //
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); //
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); //
        ; ///< @todo Generate for AdapterLuid[None]: LUID [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        FieldToJson(jdata["GraphicsPreemptionGranularity"], decoded_value.GraphicsPreemptionGranularity, options); // [is_enum]
        FieldToJson(jdata["ComputePreemptionGranularity"], decoded_value.ComputePreemptionGranularity, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTPUT_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTPUT_DESC1& meta_struct = *data;
        ; ///< @todo Generate for DeviceName[32]: wchar_t [is_array]
        ; ///< @todo Generate for DesktopCoordinates[None]: tagRECT [is_struct]
        FieldToJson(jdata["AttachedToDesktop"], decoded_value.AttachedToDesktop, options); //
        FieldToJson(jdata["Rotation"], decoded_value.Rotation, options); // [is_enum]
        ; ///< @todo Generate for Monitor[None]: void [is_pointer]
        FieldToJson(jdata["BitsPerColor"], decoded_value.BitsPerColor, options); //
        FieldToJson(jdata["ColorSpace"], decoded_value.ColorSpace, options); // [is_enum]
        ; ///< @todo Generate for RedPrimary[2]: FLOAT [is_array]
        ; ///< @todo Generate for GreenPrimary[2]: FLOAT [is_array]
        ; ///< @todo Generate for BluePrimary[2]: FLOAT [is_array]
        ; ///< @todo Generate for WhitePoint[2]: FLOAT [is_array]
        FieldToJson(jdata["MinLuminance"], decoded_value.MinLuminance, options); //
        FieldToJson(jdata["MaxLuminance"], decoded_value.MaxLuminance, options); //
        FieldToJson(jdata["MaxFullFrameLuminance"], decoded_value.MaxFullFrameLuminance, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RATIONAL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_RATIONAL& decoded_value = *data->decoded_value;
        const Decoded_DXGI_RATIONAL& meta_struct = *data;
        FieldToJson(jdata["Numerator"], decoded_value.Numerator, options); //
        FieldToJson(jdata["Denominator"], decoded_value.Denominator, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SAMPLE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SAMPLE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SAMPLE_DESC& meta_struct = *data;
        FieldToJson(jdata["Count"], decoded_value.Count, options); //
        FieldToJson(jdata["Quality"], decoded_value.Quality, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RGB* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_RGB& decoded_value = *data->decoded_value;
        const Decoded_DXGI_RGB& meta_struct = *data;
        FieldToJson(jdata["Red"], decoded_value.Red, options); //
        FieldToJson(jdata["Green"], decoded_value.Green, options); //
        FieldToJson(jdata["Blue"], decoded_value.Blue, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3DCOLORVALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3DCOLORVALUE& decoded_value = *data->decoded_value;
        const Decoded_D3DCOLORVALUE& meta_struct = *data;
        FieldToJson(jdata["r"], decoded_value.r, options); //
        FieldToJson(jdata["g"], decoded_value.g, options); //
        FieldToJson(jdata["b"], decoded_value.b, options); //
        FieldToJson(jdata["a"], decoded_value.a, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_GAMMA_CONTROL& decoded_value = *data->decoded_value;
        const Decoded_DXGI_GAMMA_CONTROL& meta_struct = *data;
        ; ///< @todo Generate for Scale[None]: DXGI_RGB [is_struct]
        ; ///< @todo Generate for Offset[None]: DXGI_RGB [is_struct]
        ; ///< @todo Generate for GammaCurve[1025]: DXGI_RGB [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_GAMMA_CONTROL_CAPABILITIES& decoded_value = *data->decoded_value;
        const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES& meta_struct = *data;
        FieldToJson(jdata["ScaleAndOffsetSupported"], decoded_value.ScaleAndOffsetSupported, options); //
        FieldToJson(jdata["MaxConvertedValue"], decoded_value.MaxConvertedValue, options); //
        FieldToJson(jdata["MinConvertedValue"], decoded_value.MinConvertedValue, options); //
        FieldToJson(jdata["NumGammaControlPoints"], decoded_value.NumGammaControlPoints, options); //
        ; ///< @todo Generate for ControlPointPositions[1025]: float [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MODE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MODE_DESC& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        ; ///< @todo Generate for RefreshRate[None]: DXGI_RATIONAL [is_struct]
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["ScanlineOrdering"], decoded_value.ScanlineOrdering, options); // [is_enum]
        FieldToJson(jdata["Scaling"], decoded_value.Scaling, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_DC_HUFFMAN_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE& meta_struct = *data;
        ; ///< @todo Generate for CodeCounts[12]: BYTE [is_array]
        ; ///< @todo Generate for CodeValues[12]: BYTE [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_AC_HUFFMAN_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE& meta_struct = *data;
        ; ///< @todo Generate for CodeCounts[16]: BYTE [is_array]
        ; ///< @todo Generate for CodeValues[162]: BYTE [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_QUANTIZATION_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_QUANTIZATION_TABLE& meta_struct = *data;
        ; ///< @todo Generate for Elements[64]: BYTE [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMMAND_QUEUE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMMAND_QUEUE_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["Priority"], decoded_value.Priority, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INPUT_ELEMENT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INPUT_ELEMENT_DESC& meta_struct = *data;
        ; ///< @todo Generate for SemanticName[None]: char [is_pointer]
        FieldToJson(jdata["SemanticIndex"], decoded_value.SemanticIndex, options); //
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["InputSlot"], decoded_value.InputSlot, options); //
        FieldToJson(jdata["AlignedByteOffset"], decoded_value.AlignedByteOffset, options); //
        FieldToJson(jdata["InputSlotClass"], decoded_value.InputSlotClass, options); // [is_enum]
        FieldToJson(jdata["InstanceDataStepRate"], decoded_value.InstanceDataStepRate, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SO_DECLARATION_ENTRY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SO_DECLARATION_ENTRY& meta_struct = *data;
        FieldToJson(jdata["Stream"], decoded_value.Stream, options); //
        ; ///< @todo Generate for SemanticName[None]: char [is_pointer]
        FieldToJson(jdata["SemanticIndex"], decoded_value.SemanticIndex, options); //
        FieldToJson(jdata["StartComponent"], decoded_value.StartComponent, options); //
        FieldToJson(jdata["ComponentCount"], decoded_value.ComponentCount, options); //
        FieldToJson(jdata["OutputSlot"], decoded_value.OutputSlot, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEWPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEWPORT& meta_struct = *data;
        FieldToJson(jdata["TopLeftX"], decoded_value.TopLeftX, options); //
        FieldToJson(jdata["TopLeftY"], decoded_value.TopLeftY, options); //
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        FieldToJson(jdata["MinDepth"], decoded_value.MinDepth, options); //
        FieldToJson(jdata["MaxDepth"], decoded_value.MaxDepth, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BOX& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BOX& meta_struct = *data;
        FieldToJson(jdata["left"], decoded_value.left, options); //
        FieldToJson(jdata["top"], decoded_value.top, options); //
        FieldToJson(jdata["front"], decoded_value.front, options); //
        FieldToJson(jdata["right"], decoded_value.right, options); //
        FieldToJson(jdata["bottom"], decoded_value.bottom, options); //
        FieldToJson(jdata["back"], decoded_value.back, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCILOP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCILOP_DESC& meta_struct = *data;
        FieldToJson(jdata["StencilFailOp"], decoded_value.StencilFailOp, options); // [is_enum]
        FieldToJson(jdata["StencilDepthFailOp"], decoded_value.StencilDepthFailOp, options); // [is_enum]
        FieldToJson(jdata["StencilPassOp"], decoded_value.StencilPassOp, options); // [is_enum]
        FieldToJson(jdata["StencilFunc"], decoded_value.StencilFunc, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC& meta_struct = *data;
        FieldToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options); //
        FieldToJson(jdata["DepthWriteMask"], decoded_value.DepthWriteMask, options); // [is_enum]
        FieldToJson(jdata["DepthFunc"], decoded_value.DepthFunc, options); // [is_enum]
        FieldToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options); //
        FieldToJson(jdata["StencilReadMask"], decoded_value.StencilReadMask, options); //
        FieldToJson(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options); //
        ; ///< @todo Generate for FrontFace[None]: D3D12_DEPTH_STENCILOP_DESC [is_struct]
        ; ///< @todo Generate for BackFace[None]: D3D12_DEPTH_STENCILOP_DESC [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC1& meta_struct = *data;
        FieldToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options); //
        FieldToJson(jdata["DepthWriteMask"], decoded_value.DepthWriteMask, options); // [is_enum]
        FieldToJson(jdata["DepthFunc"], decoded_value.DepthFunc, options); // [is_enum]
        FieldToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options); //
        FieldToJson(jdata["StencilReadMask"], decoded_value.StencilReadMask, options); //
        FieldToJson(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options); //
        ; ///< @todo Generate for FrontFace[None]: D3D12_DEPTH_STENCILOP_DESC [is_struct]
        ; ///< @todo Generate for BackFace[None]: D3D12_DEPTH_STENCILOP_DESC [is_struct]
        FieldToJson(jdata["DepthBoundsTestEnable"], decoded_value.DepthBoundsTestEnable, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCILOP_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCILOP_DESC1& meta_struct = *data;
        FieldToJson(jdata["StencilFailOp"], decoded_value.StencilFailOp, options); // [is_enum]
        FieldToJson(jdata["StencilDepthFailOp"], decoded_value.StencilDepthFailOp, options); // [is_enum]
        FieldToJson(jdata["StencilPassOp"], decoded_value.StencilPassOp, options); // [is_enum]
        FieldToJson(jdata["StencilFunc"], decoded_value.StencilFunc, options); // [is_enum]
        FieldToJson(jdata["StencilReadMask"], decoded_value.StencilReadMask, options); //
        FieldToJson(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC2& meta_struct = *data;
        FieldToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options); //
        FieldToJson(jdata["DepthWriteMask"], decoded_value.DepthWriteMask, options); // [is_enum]
        FieldToJson(jdata["DepthFunc"], decoded_value.DepthFunc, options); // [is_enum]
        FieldToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options); //
        ; ///< @todo Generate for FrontFace[None]: D3D12_DEPTH_STENCILOP_DESC1 [is_struct]
        ; ///< @todo Generate for BackFace[None]: D3D12_DEPTH_STENCILOP_DESC1 [is_struct]
        FieldToJson(jdata["DepthBoundsTestEnable"], decoded_value.DepthBoundsTestEnable, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_TARGET_BLEND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_TARGET_BLEND_DESC& meta_struct = *data;
        FieldToJson(jdata["BlendEnable"], decoded_value.BlendEnable, options); //
        FieldToJson(jdata["LogicOpEnable"], decoded_value.LogicOpEnable, options); //
        FieldToJson(jdata["SrcBlend"], decoded_value.SrcBlend, options); // [is_enum]
        FieldToJson(jdata["DestBlend"], decoded_value.DestBlend, options); // [is_enum]
        FieldToJson(jdata["BlendOp"], decoded_value.BlendOp, options); // [is_enum]
        FieldToJson(jdata["SrcBlendAlpha"], decoded_value.SrcBlendAlpha, options); // [is_enum]
        FieldToJson(jdata["DestBlendAlpha"], decoded_value.DestBlendAlpha, options); // [is_enum]
        FieldToJson(jdata["BlendOpAlpha"], decoded_value.BlendOpAlpha, options); // [is_enum]
        FieldToJson(jdata["LogicOp"], decoded_value.LogicOp, options); // [is_enum]
        FieldToJson(jdata["RenderTargetWriteMask"], decoded_value.RenderTargetWriteMask, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BLEND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BLEND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BLEND_DESC& meta_struct = *data;
        FieldToJson(jdata["AlphaToCoverageEnable"], decoded_value.AlphaToCoverageEnable, options); //
        FieldToJson(jdata["IndependentBlendEnable"], decoded_value.IndependentBlendEnable, options); //
        ; ///< @todo Generate for RenderTarget[8]: D3D12_RENDER_TARGET_BLEND_DESC [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC& meta_struct = *data;
        FieldToJson(jdata["FillMode"], decoded_value.FillMode, options); // [is_enum]
        FieldToJson(jdata["CullMode"], decoded_value.CullMode, options); // [is_enum]
        FieldToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options); //
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options); //
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options); //
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options); //
        FieldToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options); //
        FieldToJson(jdata["MultisampleEnable"], decoded_value.MultisampleEnable, options); //
        FieldToJson(jdata["AntialiasedLineEnable"], decoded_value.AntialiasedLineEnable, options); //
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options); //
        FieldToJson(jdata["ConservativeRaster"], decoded_value.ConservativeRaster, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC1& meta_struct = *data;
        FieldToJson(jdata["FillMode"], decoded_value.FillMode, options); // [is_enum]
        FieldToJson(jdata["CullMode"], decoded_value.CullMode, options); // [is_enum]
        FieldToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options); //
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options); //
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options); //
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options); //
        FieldToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options); //
        FieldToJson(jdata["MultisampleEnable"], decoded_value.MultisampleEnable, options); //
        FieldToJson(jdata["AntialiasedLineEnable"], decoded_value.AntialiasedLineEnable, options); //
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options); //
        FieldToJson(jdata["ConservativeRaster"], decoded_value.ConservativeRaster, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC2& meta_struct = *data;
        FieldToJson(jdata["FillMode"], decoded_value.FillMode, options); // [is_enum]
        FieldToJson(jdata["CullMode"], decoded_value.CullMode, options); // [is_enum]
        FieldToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options); //
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options); //
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options); //
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options); //
        FieldToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options); //
        FieldToJson(jdata["LineRasterizationMode"], decoded_value.LineRasterizationMode, options); // [is_enum]
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options); //
        FieldToJson(jdata["ConservativeRaster"], decoded_value.ConservativeRaster, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_BYTECODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_BYTECODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_BYTECODE& meta_struct = *data;
        ; ///< @todo Generate for pShaderBytecode[BytecodeLength]: void [is_pointer] [is_array]
        FieldToJson(jdata["BytecodeLength"], decoded_value.BytecodeLength, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STREAM_OUTPUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STREAM_OUTPUT_DESC& meta_struct = *data;
        ; ///< @todo Generate for pSODeclaration[NumEntries]: D3D12_SO_DECLARATION_ENTRY [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumEntries"], decoded_value.NumEntries, options); //
        ; ///< @todo Generate for pBufferStrides[NumStrides]: UINT [is_pointer] [is_array]
        FieldToJson(jdata["NumStrides"], decoded_value.NumStrides, options); //
        FieldToJson(jdata["RasterizedStream"], decoded_value.RasterizedStream, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_LAYOUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INPUT_LAYOUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INPUT_LAYOUT_DESC& meta_struct = *data;
        ; ///< @todo Generate for pInputElementDescs[NumElements]: D3D12_INPUT_ELEMENT_DESC [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CACHED_PIPELINE_STATE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CACHED_PIPELINE_STATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CACHED_PIPELINE_STATE& meta_struct = *data;
        ; ///< @todo Generate for pCachedBlob[CachedBlobSizeInBytes]: void [is_pointer] [is_array]
        FieldToJson(jdata["CachedBlobSizeInBytes"], decoded_value.CachedBlobSizeInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GRAPHICS_PIPELINE_STATE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC& meta_struct = *data;
        ; ///< @todo Generate for pRootSignature[None]: ID3D12RootSignature [is_pointer]
        ; ///< @todo Generate for VS[None]: D3D12_SHADER_BYTECODE [is_struct]
        ; ///< @todo Generate for PS[None]: D3D12_SHADER_BYTECODE [is_struct]
        ; ///< @todo Generate for DS[None]: D3D12_SHADER_BYTECODE [is_struct]
        ; ///< @todo Generate for HS[None]: D3D12_SHADER_BYTECODE [is_struct]
        ; ///< @todo Generate for GS[None]: D3D12_SHADER_BYTECODE [is_struct]
        ; ///< @todo Generate for StreamOutput[None]: D3D12_STREAM_OUTPUT_DESC [is_struct]
        ; ///< @todo Generate for BlendState[None]: D3D12_BLEND_DESC [is_struct]
        FieldToJson(jdata["SampleMask"], decoded_value.SampleMask, options); //
        ; ///< @todo Generate for RasterizerState[None]: D3D12_RASTERIZER_DESC [is_struct]
        ; ///< @todo Generate for DepthStencilState[None]: D3D12_DEPTH_STENCIL_DESC [is_struct]
        ; ///< @todo Generate for InputLayout[None]: D3D12_INPUT_LAYOUT_DESC [is_struct]
        FieldToJson(jdata["IBStripCutValue"], decoded_value.IBStripCutValue, options); // [is_enum]
        FieldToJson(jdata["PrimitiveTopologyType"], decoded_value.PrimitiveTopologyType, options); // [is_enum]
        FieldToJson(jdata["NumRenderTargets"], decoded_value.NumRenderTargets, options); //
        ; ///< @todo Generate for RTVFormats[8]: DXGI_FORMAT [is_array] [is_enum]
        FieldToJson(jdata["DSVFormat"], decoded_value.DSVFormat, options); // [is_enum]
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); //
        ; ///< @todo Generate for CachedPSO[None]: D3D12_CACHED_PIPELINE_STATE [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMPUTE_PIPELINE_STATE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC& meta_struct = *data;
        ; ///< @todo Generate for pRootSignature[None]: ID3D12RootSignature [is_pointer]
        ; ///< @todo Generate for CS[None]: D3D12_SHADER_BYTECODE [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); //
        ; ///< @todo Generate for CachedPSO[None]: D3D12_CACHED_PIPELINE_STATE [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RT_FORMAT_ARRAY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RT_FORMAT_ARRAY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RT_FORMAT_ARRAY& meta_struct = *data;
        ; ///< @todo Generate for RTFormats[8]: DXGI_FORMAT [is_array] [is_enum]
        FieldToJson(jdata["NumRenderTargets"], decoded_value.NumRenderTargets, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PIPELINE_STATE_STREAM_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); //
        ; ///< @todo Generate for pPipelineStateSubobjectStream[None]: void [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS& meta_struct = *data;
        FieldToJson(jdata["DoublePrecisionFloatShaderOps"], decoded_value.DoublePrecisionFloatShaderOps, options); //
        FieldToJson(jdata["OutputMergerLogicOp"], decoded_value.OutputMergerLogicOp, options); //
        FieldToJson(jdata["MinPrecisionSupport"], decoded_value.MinPrecisionSupport, options); // [is_enum]
        FieldToJson(jdata["TiledResourcesTier"], decoded_value.TiledResourcesTier, options); // [is_enum]
        FieldToJson(jdata["ResourceBindingTier"], decoded_value.ResourceBindingTier, options); // [is_enum]
        FieldToJson(jdata["PSSpecifiedStencilRefSupported"], decoded_value.PSSpecifiedStencilRefSupported, options); //
        FieldToJson(jdata["TypedUAVLoadAdditionalFormats"], decoded_value.TypedUAVLoadAdditionalFormats, options); //
        FieldToJson(jdata["ROVsSupported"], decoded_value.ROVsSupported, options); //
        FieldToJson(jdata["ConservativeRasterizationTier"], decoded_value.ConservativeRasterizationTier, options); // [is_enum]
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], decoded_value.MaxGPUVirtualAddressBitsPerResource, options); //
        FieldToJson(jdata["StandardSwizzle64KBSupported"], decoded_value.StandardSwizzle64KBSupported, options); //
        FieldToJson(jdata["CrossNodeSharingTier"], decoded_value.CrossNodeSharingTier, options); // [is_enum]
        FieldToJson(jdata["CrossAdapterRowMajorTextureSupported"], decoded_value.CrossAdapterRowMajorTextureSupported, options); //
        FieldToJson(jdata["VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation"], decoded_value.VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation, options); //
        FieldToJson(jdata["ResourceHeapTier"], decoded_value.ResourceHeapTier, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1& meta_struct = *data;
        FieldToJson(jdata["WaveOps"], decoded_value.WaveOps, options); //
        FieldToJson(jdata["WaveLaneCountMin"], decoded_value.WaveLaneCountMin, options); //
        FieldToJson(jdata["WaveLaneCountMax"], decoded_value.WaveLaneCountMax, options); //
        FieldToJson(jdata["TotalLaneCount"], decoded_value.TotalLaneCount, options); //
        FieldToJson(jdata["ExpandedComputeResourceStates"], decoded_value.ExpandedComputeResourceStates, options); //
        FieldToJson(jdata["Int64ShaderOps"], decoded_value.Int64ShaderOps, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2& meta_struct = *data;
        FieldToJson(jdata["DepthBoundsTestSupported"], decoded_value.DepthBoundsTestSupported, options); //
        FieldToJson(jdata["ProgrammableSamplePositionsTier"], decoded_value.ProgrammableSamplePositionsTier, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE& meta_struct = *data;
        FieldToJson(jdata["HighestVersion"], decoded_value.HighestVersion, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ARCHITECTURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); //
        FieldToJson(jdata["TileBasedRenderer"], decoded_value.TileBasedRenderer, options); //
        FieldToJson(jdata["UMA"], decoded_value.UMA, options); //
        FieldToJson(jdata["CacheCoherentUMA"], decoded_value.CacheCoherentUMA, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ARCHITECTURE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); //
        FieldToJson(jdata["TileBasedRenderer"], decoded_value.TileBasedRenderer, options); //
        FieldToJson(jdata["UMA"], decoded_value.UMA, options); //
        FieldToJson(jdata["CacheCoherentUMA"], decoded_value.CacheCoherentUMA, options); //
        FieldToJson(jdata["IsolatedMMU"], decoded_value.IsolatedMMU, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FEATURE_LEVELS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS& meta_struct = *data;
        FieldToJson(jdata["NumFeatureLevels"], decoded_value.NumFeatureLevels, options); //
        ; ///< @todo Generate for pFeatureLevelsRequested[NumFeatureLevels]: D3D_FEATURE_LEVEL [is_pointer] [is_array] [is_enum]
        FieldToJson(jdata["MaxSupportedFeatureLevel"], decoded_value.MaxSupportedFeatureLevel, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADER_MODEL& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL& meta_struct = *data;
        FieldToJson(jdata["HighestShaderModel"], decoded_value.HighestShaderModel, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FORMAT_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["Support1"], decoded_value.Support1, options); // [is_enum]
        FieldToJson(jdata["Support2"], decoded_value.Support2, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["SampleCount"], decoded_value.SampleCount, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        FieldToJson(jdata["NumQualityLevels"], decoded_value.NumQualityLevels, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FORMAT_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["PlaneCount"], decoded_value.PlaneCount, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], decoded_value.MaxGPUVirtualAddressBitsPerResource, options); //
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerProcess"], decoded_value.MaxGPUVirtualAddressBitsPerProcess, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADER_CACHE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE& meta_struct = *data;
        FieldToJson(jdata["SupportFlags"], decoded_value.SupportFlags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& meta_struct = *data;
        FieldToJson(jdata["CommandListType"], decoded_value.CommandListType, options); // [is_enum]
        FieldToJson(jdata["Priority"], decoded_value.Priority, options); //
        FieldToJson(jdata["PriorityForTypeIsSupported"], decoded_value.PriorityForTypeIsSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS3& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3& meta_struct = *data;
        FieldToJson(jdata["CopyQueueTimestampQueriesSupported"], decoded_value.CopyQueueTimestampQueriesSupported, options); //
        FieldToJson(jdata["CastingFullyTypedFormatSupported"], decoded_value.CastingFullyTypedFormatSupported, options); //
        FieldToJson(jdata["WriteBufferImmediateSupportFlags"], decoded_value.WriteBufferImmediateSupportFlags, options); // [is_enum]
        FieldToJson(jdata["ViewInstancingTier"], decoded_value.ViewInstancingTier, options); // [is_enum]
        FieldToJson(jdata["BarycentricsSupported"], decoded_value.BarycentricsSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_EXISTING_HEAPS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS& meta_struct = *data;
        FieldToJson(jdata["Supported"], decoded_value.Supported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_DISPLAYABLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE& meta_struct = *data;
        FieldToJson(jdata["DisplayableTexture"], decoded_value.DisplayableTexture, options); //
        FieldToJson(jdata["SharedResourceCompatibilityTier"], decoded_value.SharedResourceCompatibilityTier, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS4& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4& meta_struct = *data;
        FieldToJson(jdata["MSAA64KBAlignedTextureSupported"], decoded_value.MSAA64KBAlignedTextureSupported, options); //
        FieldToJson(jdata["SharedResourceCompatibilityTier"], decoded_value.SharedResourceCompatibilityTier, options); // [is_enum]
        FieldToJson(jdata["Native16BitShaderOpsSupported"], decoded_value.Native16BitShaderOpsSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SERIALIZATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SERIALIZATION& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); //
        FieldToJson(jdata["HeapSerializationTier"], decoded_value.HeapSerializationTier, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_CROSS_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_CROSS_NODE& meta_struct = *data;
        FieldToJson(jdata["SharingTier"], decoded_value.SharingTier, options); // [is_enum]
        FieldToJson(jdata["AtomicShaderInstructions"], decoded_value.AtomicShaderInstructions, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS5& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5& meta_struct = *data;
        FieldToJson(jdata["SRVOnlyTiledResourceTier3"], decoded_value.SRVOnlyTiledResourceTier3, options); //
        FieldToJson(jdata["RenderPassesTier"], decoded_value.RenderPassesTier, options); // [is_enum]
        FieldToJson(jdata["RaytracingTier"], decoded_value.RaytracingTier, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS6& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6& meta_struct = *data;
        FieldToJson(jdata["AdditionalShadingRatesSupported"], decoded_value.AdditionalShadingRatesSupported, options); //
        FieldToJson(jdata["PerPrimitiveShadingRateSupportedWithViewportIndexing"], decoded_value.PerPrimitiveShadingRateSupportedWithViewportIndexing, options); //
        FieldToJson(jdata["VariableShadingRateTier"], decoded_value.VariableShadingRateTier, options); // [is_enum]
        FieldToJson(jdata["ShadingRateImageTileSize"], decoded_value.ShadingRateImageTileSize, options); //
        FieldToJson(jdata["BackgroundProcessingSupported"], decoded_value.BackgroundProcessingSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS7& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7& meta_struct = *data;
        FieldToJson(jdata["MeshShaderTier"], decoded_value.MeshShaderTier, options); // [is_enum]
        FieldToJson(jdata["SamplerFeedbackTier"], decoded_value.SamplerFeedbackTier, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_QUERY_META_COMMAND& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND& meta_struct = *data;
        ; ///< @todo Generate for CommandId[None]: GUID [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); //
        ; ///< @todo Generate for pQueryInputData[QueryInputDataSizeInBytes]: void [is_pointer] [is_array]
        FieldToJson(jdata["QueryInputDataSizeInBytes"], decoded_value.QueryInputDataSizeInBytes, options); //
        ; ///< @todo Generate for pQueryOutputData[QueryOutputDataSizeInBytes]: void [is_pointer] [is_array]
        FieldToJson(jdata["QueryOutputDataSizeInBytes"], decoded_value.QueryOutputDataSizeInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS8& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8& meta_struct = *data;
        FieldToJson(jdata["UnalignedBlockTexturesSupported"], decoded_value.UnalignedBlockTexturesSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS9& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9& meta_struct = *data;
        FieldToJson(jdata["MeshShaderPipelineStatsSupported"], decoded_value.MeshShaderPipelineStatsSupported, options); //
        FieldToJson(jdata["MeshShaderSupportsFullRangeRenderTargetArrayIndex"], decoded_value.MeshShaderSupportsFullRangeRenderTargetArrayIndex, options); //
        FieldToJson(jdata["AtomicInt64OnTypedResourceSupported"], decoded_value.AtomicInt64OnTypedResourceSupported, options); //
        FieldToJson(jdata["AtomicInt64OnGroupSharedSupported"], decoded_value.AtomicInt64OnGroupSharedSupported, options); //
        FieldToJson(jdata["DerivativesInMeshAndAmplificationShadersSupported"], decoded_value.DerivativesInMeshAndAmplificationShadersSupported, options); //
        FieldToJson(jdata["WaveMMATier"], decoded_value.WaveMMATier, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS10& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10& meta_struct = *data;
        FieldToJson(jdata["VariableRateShadingSumCombinerSupported"], decoded_value.VariableRateShadingSumCombinerSupported, options); //
        FieldToJson(jdata["MeshShaderPerPrimitiveShadingRateSupported"], decoded_value.MeshShaderPerPrimitiveShadingRateSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS11& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11& meta_struct = *data;
        FieldToJson(jdata["AtomicInt64OnDescriptorHeapResourceSupported"], decoded_value.AtomicInt64OnDescriptorHeapResourceSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS12& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12& meta_struct = *data;
        FieldToJson(jdata["MSPrimitivesPipelineStatisticIncludesCulledPrimitives"], decoded_value.MSPrimitivesPipelineStatisticIncludesCulledPrimitives, options); // [is_enum]
        FieldToJson(jdata["EnhancedBarriersSupported"], decoded_value.EnhancedBarriersSupported, options); //
        FieldToJson(jdata["RelaxedFormatCastingSupported"], decoded_value.RelaxedFormatCastingSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS13& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13& meta_struct = *data;
        FieldToJson(jdata["UnrestrictedBufferTextureCopyPitchSupported"], decoded_value.UnrestrictedBufferTextureCopyPitchSupported, options); //
        FieldToJson(jdata["UnrestrictedVertexElementAlignmentSupported"], decoded_value.UnrestrictedVertexElementAlignmentSupported, options); //
        FieldToJson(jdata["InvertedViewportHeightFlipsYSupported"], decoded_value.InvertedViewportHeightFlipsYSupported, options); //
        FieldToJson(jdata["InvertedViewportDepthFlipsZSupported"], decoded_value.InvertedViewportDepthFlipsZSupported, options); //
        FieldToJson(jdata["TextureCopyBetweenDimensionsSupported"], decoded_value.TextureCopyBetweenDimensionsSupported, options); //
        FieldToJson(jdata["AlphaBlendFactorSupported"], decoded_value.AlphaBlendFactorSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS14& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14& meta_struct = *data;
        FieldToJson(jdata["AdvancedTextureOpsSupported"], decoded_value.AdvancedTextureOpsSupported, options); //
        FieldToJson(jdata["WriteableMSAATexturesSupported"], decoded_value.WriteableMSAATexturesSupported, options); //
        FieldToJson(jdata["IndependentFrontAndBackStencilRefMaskSupported"], decoded_value.IndependentFrontAndBackStencilRefMaskSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS15& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15& meta_struct = *data;
        FieldToJson(jdata["TriangleFanSupported"], decoded_value.TriangleFanSupported, options); //
        FieldToJson(jdata["DynamicIndexBufferStripCutSupported"], decoded_value.DynamicIndexBufferStripCutSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS16& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16& meta_struct = *data;
        FieldToJson(jdata["DynamicDepthBiasSupported"], decoded_value.DynamicDepthBiasSupported, options); //
        FieldToJson(jdata["GPUUploadHeapSupported"], decoded_value.GPUUploadHeapSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS17& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17& meta_struct = *data;
        FieldToJson(jdata["NonNormalizedCoordinateSamplersSupported"], decoded_value.NonNormalizedCoordinateSamplersSupported, options); //
        FieldToJson(jdata["ManualWriteTrackingResourceSupported"], decoded_value.ManualWriteTrackingResourceSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS18& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18& meta_struct = *data;
        FieldToJson(jdata["RenderPassesValid"], decoded_value.RenderPassesValid, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS19& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19& meta_struct = *data;
        FieldToJson(jdata["MismatchingOutputDimensionsSupported"], decoded_value.MismatchingOutputDimensionsSupported, options); //
        FieldToJson(jdata["SupportedSampleCountsWithNoOutputs"], decoded_value.SupportedSampleCountsWithNoOutputs, options); //
        FieldToJson(jdata["PointSamplingAddressesNeverRoundUp"], decoded_value.PointSamplingAddressesNeverRoundUp, options); //
        FieldToJson(jdata["RasterizerDesc2Supported"], decoded_value.RasterizerDesc2Supported, options); //
        FieldToJson(jdata["NarrowQuadrilateralLinesSupported"], decoded_value.NarrowQuadrilateralLinesSupported, options); //
        FieldToJson(jdata["AnisoFilterWithPointMipSupported"], decoded_value.AnisoFilterWithPointMipSupported, options); //
        FieldToJson(jdata["MaxSamplerDescriptorHeapSize"], decoded_value.MaxSamplerDescriptorHeapSize, options); //
        FieldToJson(jdata["MaxSamplerDescriptorHeapSizeWithStaticSamplers"], decoded_value.MaxSamplerDescriptorHeapSizeWithStaticSamplers, options); //
        FieldToJson(jdata["MaxViewDescriptorHeapSize"], decoded_value.MaxViewDescriptorHeapSize, options); //
        FieldToJson(jdata["ComputeOnlyCustomHeapSupported"], decoded_value.ComputeOnlyCustomHeapSupported, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALLOCATION_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALLOCATION_INFO& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); //
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALLOCATION_INFO1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); //
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); //
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HEAP_PROPERTIES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HEAP_PROPERTIES& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["CPUPageProperty"], decoded_value.CPUPageProperty, options); // [is_enum]
        FieldToJson(jdata["MemoryPoolPreference"], decoded_value.MemoryPoolPreference, options); // [is_enum]
        FieldToJson(jdata["CreationNodeMask"], decoded_value.CreationNodeMask, options); //
        FieldToJson(jdata["VisibleNodeMask"], decoded_value.VisibleNodeMask, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HEAP_DESC& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); //
        ; ///< @todo Generate for Properties[None]: D3D12_HEAP_PROPERTIES [is_struct]
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MIP_REGION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MIP_REGION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MIP_REGION& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_DESC& meta_struct = *data;
        FieldToJson(jdata["Dimension"], decoded_value.Dimension, options); // [is_enum]
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); //
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        FieldToJson(jdata["DepthOrArraySize"], decoded_value.DepthOrArraySize, options); //
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); //
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        FieldToJson(jdata["Layout"], decoded_value.Layout, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_DESC1& meta_struct = *data;
        FieldToJson(jdata["Dimension"], decoded_value.Dimension, options); // [is_enum]
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); //
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        FieldToJson(jdata["DepthOrArraySize"], decoded_value.DepthOrArraySize, options); //
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); //
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        FieldToJson(jdata["Layout"], decoded_value.Layout, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        ; ///< @todo Generate for SamplerFeedbackMipRegion[None]: D3D12_MIP_REGION [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_VALUE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_VALUE& meta_struct = *data;
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); //
        FieldToJson(jdata["Stencil"], decoded_value.Stencil, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RANGE& meta_struct = *data;
        FieldToJson(jdata["Begin"], decoded_value.Begin, options); //
        FieldToJson(jdata["End"], decoded_value.End, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE_UINT64* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RANGE_UINT64& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RANGE_UINT64& meta_struct = *data;
        FieldToJson(jdata["Begin"], decoded_value.Begin, options); //
        FieldToJson(jdata["End"], decoded_value.End, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_RANGE_UINT64& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64& meta_struct = *data;
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options); //
        ; ///< @todo Generate for Range[None]: D3D12_RANGE_UINT64 [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_INFO& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); //
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); //
        FieldToJson(jdata["DepthPitch"], decoded_value.DepthPitch, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILED_RESOURCE_COORDINATE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILED_RESOURCE_COORDINATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILED_RESOURCE_COORDINATE& meta_struct = *data;
        FieldToJson(jdata["X"], decoded_value.X, options); //
        FieldToJson(jdata["Y"], decoded_value.Y, options); //
        FieldToJson(jdata["Z"], decoded_value.Z, options); //
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_REGION_SIZE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILE_REGION_SIZE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILE_REGION_SIZE& meta_struct = *data;
        FieldToJson(jdata["NumTiles"], decoded_value.NumTiles, options); //
        FieldToJson(jdata["UseBox"], decoded_value.UseBox, options); //
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_TILING* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_TILING& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_TILING& meta_struct = *data;
        FieldToJson(jdata["WidthInTiles"], decoded_value.WidthInTiles, options); //
        FieldToJson(jdata["HeightInTiles"], decoded_value.HeightInTiles, options); //
        FieldToJson(jdata["DepthInTiles"], decoded_value.DepthInTiles, options); //
        FieldToJson(jdata["StartTileIndexInOverallResource"], decoded_value.StartTileIndexInOverallResource, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_SHAPE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILE_SHAPE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILE_SHAPE& meta_struct = *data;
        FieldToJson(jdata["WidthInTexels"], decoded_value.WidthInTexels, options); //
        FieldToJson(jdata["HeightInTexels"], decoded_value.HeightInTexels, options); //
        FieldToJson(jdata["DepthInTexels"], decoded_value.DepthInTexels, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PACKED_MIP_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PACKED_MIP_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PACKED_MIP_INFO& meta_struct = *data;
        FieldToJson(jdata["NumStandardMips"], decoded_value.NumStandardMips, options); //
        FieldToJson(jdata["NumPackedMips"], decoded_value.NumPackedMips, options); //
        FieldToJson(jdata["NumTilesForPackedMips"], decoded_value.NumTilesForPackedMips, options); //
        FieldToJson(jdata["StartTileIndexInOverallResource"], decoded_value.StartTileIndexInOverallResource, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_TRANSITION_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER& meta_struct = *data;
        ; ///< @todo Generate for pResource[None]: ID3D12Resource [is_pointer]
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options); //
        FieldToJson(jdata["StateBefore"], decoded_value.StateBefore, options); // [is_enum]
        FieldToJson(jdata["StateAfter"], decoded_value.StateAfter, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALIASING_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALIASING_BARRIER& meta_struct = *data;
        ; ///< @todo Generate for pResourceBefore[None]: ID3D12Resource [is_pointer]
        ; ///< @todo Generate for pResourceAfter[None]: ID3D12Resource [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_UAV_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_UAV_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_UAV_BARRIER& meta_struct = *data;
        ; ///< @todo Generate for pResource[None]: ID3D12Resource [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_FOOTPRINT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_FOOTPRINT& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); //
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); //
        ; ///< @todo Generate for Footprint[None]: D3D12_SUBRESOURCE_FOOTPRINT [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_POSITION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLE_POSITION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLE_POSITION& meta_struct = *data;
        FieldToJson(jdata["X"], decoded_value.X, options); //
        FieldToJson(jdata["Y"], decoded_value.Y, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCE_LOCATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEW_INSTANCE_LOCATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEW_INSTANCE_LOCATION& meta_struct = *data;
        FieldToJson(jdata["ViewportArrayIndex"], decoded_value.ViewportArrayIndex, options); //
        FieldToJson(jdata["RenderTargetArrayIndex"], decoded_value.RenderTargetArrayIndex, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCING_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEW_INSTANCING_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEW_INSTANCING_DESC& meta_struct = *data;
        FieldToJson(jdata["ViewInstanceCount"], decoded_value.ViewInstanceCount, options); //
        ; ///< @todo Generate for pViewInstanceLocations[ViewInstanceCount]: D3D12_VIEW_INSTANCE_LOCATION [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_SRV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options); //
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); //
        FieldToJson(jdata["StructureByteStride"], decoded_value.StructureByteStride, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); //
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); //
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); //
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); //
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); //
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); //
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); //
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); //
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); //
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); //
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); //
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); //
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXCUBE_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXCUBE_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); //
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); //
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXCUBE_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXCUBE_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); //
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); //
        FieldToJson(jdata["First2DArrayFace"], decoded_value.First2DArrayFace, options); //
        FieldToJson(jdata["NumCubes"], decoded_value.NumCubes, options); //
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_SRV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& meta_struct = *data;
        FieldToJson(jdata["Location"], decoded_value.Location, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_RESOURCE_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options); // [is_enum]
        FieldToJson(jdata["Shader4ComponentMapping"], decoded_value.Shader4ComponentMapping, options); //
        ; ///< @todo ALERT: Union member 0 of D3D12_SHADER_RESOURCE_VIEW_DESC needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CONSTANT_BUFFER_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); //
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLER_DESC& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options); // [is_enum]
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options); // [is_enum]
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options); // [is_enum]
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options); // [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); //
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); //
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options); // [is_enum]
        ; ///< @todo Generate for BorderColor[4]: FLOAT [is_array]
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); //
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLER_DESC2& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options); // [is_enum]
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options); // [is_enum]
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options); // [is_enum]
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options); // [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); //
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); //
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_SAMPLER_DESC2 needs special handling.
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); //
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_UAV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options); //
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); //
        FieldToJson(jdata["StructureByteStride"], decoded_value.StructureByteStride, options); //
        FieldToJson(jdata["CounterOffsetInBytes"], decoded_value.CounterOffsetInBytes, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_UAV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
        FieldToJson(jdata["FirstWSlice"], decoded_value.FirstWSlice, options); //
        FieldToJson(jdata["WSize"], decoded_value.WSize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_UNORDERED_ACCESS_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_UNORDERED_ACCESS_VIEW_DESC needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_RTV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options); //
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_RTV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
        FieldToJson(jdata["FirstWSlice"], decoded_value.FirstWSlice, options); //
        FieldToJson(jdata["WSize"], decoded_value.WSize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_TARGET_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_TARGET_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_RENDER_TARGET_VIEW_DESC needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); //
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_DSV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["ViewDimension"], decoded_value.ViewDimension, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_DEPTH_STENCIL_VIEW_DESC needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_HEAP_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_RANGE& meta_struct = *data;
        FieldToJson(jdata["RangeType"], decoded_value.RangeType, options); // [is_enum]
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options); //
        FieldToJson(jdata["BaseShaderRegister"], decoded_value.BaseShaderRegister, options); //
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); //
        FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], decoded_value.OffsetInDescriptorsFromTableStart, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR_TABLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE& meta_struct = *data;
        FieldToJson(jdata["NumDescriptorRanges"], decoded_value.NumDescriptorRanges, options); //
        ; ///< @todo Generate for pDescriptorRanges[NumDescriptorRanges]: D3D12_DESCRIPTOR_RANGE [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_CONSTANTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_CONSTANTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_CONSTANTS& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); //
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); //
        FieldToJson(jdata["Num32BitValues"], decoded_value.Num32BitValues, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); //
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_PARAMETER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_PARAMETER& meta_struct = *data;
        FieldToJson(jdata["ParameterType"], decoded_value.ParameterType, options); // [is_enum]
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
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATIC_SAMPLER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATIC_SAMPLER_DESC& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options); // [is_enum]
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options); // [is_enum]
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options); // [is_enum]
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options); // [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); //
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); //
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options); // [is_enum]
        FieldToJson(jdata["BorderColor"], decoded_value.BorderColor, options); // [is_enum]
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); //
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); //
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); //
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); //
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATIC_SAMPLER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATIC_SAMPLER_DESC1& meta_struct = *data;
        FieldToJson(jdata["Filter"], decoded_value.Filter, options); // [is_enum]
        FieldToJson(jdata["AddressU"], decoded_value.AddressU, options); // [is_enum]
        FieldToJson(jdata["AddressV"], decoded_value.AddressV, options); // [is_enum]
        FieldToJson(jdata["AddressW"], decoded_value.AddressW, options); // [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); //
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); //
        FieldToJson(jdata["ComparisonFunc"], decoded_value.ComparisonFunc, options); // [is_enum]
        FieldToJson(jdata["BorderColor"], decoded_value.BorderColor, options); // [is_enum]
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); //
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); //
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); //
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); //
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options); //
        ; ///< @todo Generate for pParameters[NumParameters]: D3D12_ROOT_PARAMETER [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options); //
        ; ///< @todo Generate for pStaticSamplers[NumStaticSamplers]: D3D12_STATIC_SAMPLER_DESC [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_RANGE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_RANGE1& meta_struct = *data;
        FieldToJson(jdata["RangeType"], decoded_value.RangeType, options); // [is_enum]
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options); //
        FieldToJson(jdata["BaseShaderRegister"], decoded_value.BaseShaderRegister, options); //
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], decoded_value.OffsetInDescriptorsFromTableStart, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR_TABLE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1& meta_struct = *data;
        FieldToJson(jdata["NumDescriptorRanges"], decoded_value.NumDescriptorRanges, options); //
        ; ///< @todo Generate for pDescriptorRanges[NumDescriptorRanges]: D3D12_DESCRIPTOR_RANGE1 [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR1& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); //
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_PARAMETER1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_PARAMETER1& meta_struct = *data;
        FieldToJson(jdata["ParameterType"], decoded_value.ParameterType, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_ROOT_PARAMETER1 needs special handling.
        FieldToJson(jdata["ShaderVisibility"], decoded_value.ShaderVisibility, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC1& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options); //
        ; ///< @todo Generate for pParameters[NumParameters]: D3D12_ROOT_PARAMETER1 [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options); //
        ; ///< @todo Generate for pStaticSamplers[NumStaticSamplers]: D3D12_STATIC_SAMPLER_DESC [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC2& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options); //
        ; ///< @todo Generate for pParameters[NumParameters]: D3D12_ROOT_PARAMETER1 [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options); //
        ; ///< @todo Generate for pStaticSamplers[NumStaticSamplers]: D3D12_STATIC_SAMPLER_DESC1 [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["Version"], decoded_value.Version, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_VERSIONED_ROOT_SIGNATURE_DESC needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CPU_DESCRIPTOR_HANDLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& meta_struct = *data;
        FieldToJson(jdata["ptr"], decoded_value.ptr, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_DESCRIPTOR_HANDLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE& meta_struct = *data;
        FieldToJson(jdata["ptr"], decoded_value.ptr, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISCARD_REGION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISCARD_REGION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISCARD_REGION& meta_struct = *data;
        FieldToJson(jdata["NumRects"], decoded_value.NumRects, options); //
        ; ///< @todo Generate for pRects[NumRects]: tagRECT [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["FirstSubresource"], decoded_value.FirstSubresource, options); //
        FieldToJson(jdata["NumSubresources"], decoded_value.NumSubresources, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_HEAP_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["Count"], decoded_value.Count, options); //
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_PIPELINE_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["IAVertices"], decoded_value.IAVertices, options); //
        FieldToJson(jdata["IAPrimitives"], decoded_value.IAPrimitives, options); //
        FieldToJson(jdata["VSInvocations"], decoded_value.VSInvocations, options); //
        FieldToJson(jdata["GSInvocations"], decoded_value.GSInvocations, options); //
        FieldToJson(jdata["GSPrimitives"], decoded_value.GSPrimitives, options); //
        FieldToJson(jdata["CInvocations"], decoded_value.CInvocations, options); //
        FieldToJson(jdata["CPrimitives"], decoded_value.CPrimitives, options); //
        FieldToJson(jdata["PSInvocations"], decoded_value.PSInvocations, options); //
        FieldToJson(jdata["HSInvocations"], decoded_value.HSInvocations, options); //
        FieldToJson(jdata["DSInvocations"], decoded_value.DSInvocations, options); //
        FieldToJson(jdata["CSInvocations"], decoded_value.CSInvocations, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1& meta_struct = *data;
        FieldToJson(jdata["IAVertices"], decoded_value.IAVertices, options); //
        FieldToJson(jdata["IAPrimitives"], decoded_value.IAPrimitives, options); //
        FieldToJson(jdata["VSInvocations"], decoded_value.VSInvocations, options); //
        FieldToJson(jdata["GSInvocations"], decoded_value.GSInvocations, options); //
        FieldToJson(jdata["GSPrimitives"], decoded_value.GSPrimitives, options); //
        FieldToJson(jdata["CInvocations"], decoded_value.CInvocations, options); //
        FieldToJson(jdata["CPrimitives"], decoded_value.CPrimitives, options); //
        FieldToJson(jdata["PSInvocations"], decoded_value.PSInvocations, options); //
        FieldToJson(jdata["HSInvocations"], decoded_value.HSInvocations, options); //
        FieldToJson(jdata["DSInvocations"], decoded_value.DSInvocations, options); //
        FieldToJson(jdata["CSInvocations"], decoded_value.CSInvocations, options); //
        FieldToJson(jdata["ASInvocations"], decoded_value.ASInvocations, options); //
        FieldToJson(jdata["MSInvocations"], decoded_value.MSInvocations, options); //
        FieldToJson(jdata["MSPrimitives"], decoded_value.MSPrimitives, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_SO_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_SO_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["NumPrimitivesWritten"], decoded_value.NumPrimitivesWritten, options); //
        FieldToJson(jdata["PrimitivesStorageNeeded"], decoded_value.PrimitivesStorageNeeded, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STREAM_OUTPUT_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); //
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); //
        FieldToJson(jdata["BufferFilledSizeLocation"], decoded_value.BufferFilledSizeLocation, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRAW_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRAW_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["VertexCountPerInstance"], decoded_value.VertexCountPerInstance, options); //
        FieldToJson(jdata["InstanceCount"], decoded_value.InstanceCount, options); //
        FieldToJson(jdata["StartVertexLocation"], decoded_value.StartVertexLocation, options); //
        FieldToJson(jdata["StartInstanceLocation"], decoded_value.StartInstanceLocation, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRAW_INDEXED_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["IndexCountPerInstance"], decoded_value.IndexCountPerInstance, options); //
        FieldToJson(jdata["InstanceCount"], decoded_value.InstanceCount, options); //
        FieldToJson(jdata["StartIndexLocation"], decoded_value.StartIndexLocation, options); //
        FieldToJson(jdata["BaseVertexLocation"], decoded_value.BaseVertexLocation, options); //
        FieldToJson(jdata["StartInstanceLocation"], decoded_value.StartInstanceLocation, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["ThreadGroupCountX"], decoded_value.ThreadGroupCountX, options); //
        FieldToJson(jdata["ThreadGroupCountY"], decoded_value.ThreadGroupCountY, options); //
        FieldToJson(jdata["ThreadGroupCountZ"], decoded_value.ThreadGroupCountZ, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERTEX_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERTEX_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERTEX_BUFFER_VIEW& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); //
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); //
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDEX_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INDEX_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INDEX_BUFFER_VIEW& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); //
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); //
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDIRECT_ARGUMENT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INDIRECT_ARGUMENT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INDIRECT_ARGUMENT_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_INDIRECT_ARGUMENT_DESC needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMMAND_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMMAND_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["ByteStride"], decoded_value.ByteStride, options); //
        FieldToJson(jdata["NumArgumentDescs"], decoded_value.NumArgumentDescs, options); //
        ; ///< @todo Generate for pArgumentDescs[NumArgumentDescs]: D3D12_INDIRECT_ARGUMENT_DESC [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& meta_struct = *data;
        FieldToJson(jdata["Dest"], decoded_value.Dest, options); //
        FieldToJson(jdata["Value"], decoded_value.Value, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); //
        FieldToJson(jdata["Support"], decoded_value.Support, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC& meta_struct = *data;
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_META_COMMAND_PARAMETER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_META_COMMAND_PARAMETER_DESC& meta_struct = *data;
        ; ///< @todo Generate for Name[None]: wchar_t [is_pointer]
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        FieldToJson(jdata["RequiredResourceState"], decoded_value.RequiredResourceState, options); // [is_enum]
        FieldToJson(jdata["StructureOffset"], decoded_value.StructureOffset, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_META_COMMAND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_META_COMMAND_DESC& meta_struct = *data;
        ; ///< @todo Generate for Id[None]: GUID [is_struct]
        ; ///< @todo Generate for Name[None]: wchar_t [is_pointer]
        FieldToJson(jdata["InitializationDirtyState"], decoded_value.InitializationDirtyState, options); // [is_enum]
        FieldToJson(jdata["ExecutionDirtyState"], decoded_value.ExecutionDirtyState, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_SUBOBJECT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_SUBOBJECT& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        ; ///< @todo Generate for pDesc[None]: void [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_OBJECT_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_OBJECT_CONFIG& meta_struct = *data;
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE& meta_struct = *data;
        ; ///< @todo Generate for pGlobalRootSignature[None]: ID3D12RootSignature [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_LOCAL_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_LOCAL_ROOT_SIGNATURE& meta_struct = *data;
        ; ///< @todo Generate for pLocalRootSignature[None]: ID3D12RootSignature [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_NODE_MASK& decoded_value = *data->decoded_value;
        const Decoded_D3D12_NODE_MASK& meta_struct = *data;
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_EXPORT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXPORT_DESC& meta_struct = *data;
        ; ///< @todo Generate for Name[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for ExportToRename[None]: wchar_t [is_pointer]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DXIL_LIBRARY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DXIL_LIBRARY_DESC& meta_struct = *data;
        ; ///< @todo Generate for DXILLibrary[None]: D3D12_SHADER_BYTECODE [is_struct]
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options); //
        ; ///< @todo Generate for pExports[NumExports]: D3D12_EXPORT_DESC [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_EXISTING_COLLECTION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXISTING_COLLECTION_DESC& meta_struct = *data;
        ; ///< @todo Generate for pExistingCollection[None]: ID3D12StateObject [is_pointer]
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options); //
        ; ///< @todo Generate for pExports[NumExports]: D3D12_EXPORT_DESC [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& meta_struct = *data;
        ; ///< @todo Generate for pSubobjectToAssociate[None]: D3D12_STATE_SUBOBJECT [is_pointer] [is_struct]
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options); //
        ; ///< @todo Generate for pExports[NumExports]: wchar_t [is_pointer] [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& meta_struct = *data;
        ; ///< @todo Generate for SubobjectToAssociate[None]: wchar_t [is_pointer]
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options); //
        ; ///< @todo Generate for pExports[NumExports]: wchar_t [is_pointer] [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HIT_GROUP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HIT_GROUP_DESC& meta_struct = *data;
        ; ///< @todo Generate for HitGroupExport[None]: wchar_t [is_pointer]
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        ; ///< @todo Generate for AnyHitShaderImport[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for ClosestHitShaderImport[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for IntersectionShaderImport[None]: wchar_t [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_SHADER_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_SHADER_CONFIG& meta_struct = *data;
        FieldToJson(jdata["MaxPayloadSizeInBytes"], decoded_value.MaxPayloadSizeInBytes, options); //
        FieldToJson(jdata["MaxAttributeSizeInBytes"], decoded_value.MaxAttributeSizeInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_PIPELINE_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG& meta_struct = *data;
        FieldToJson(jdata["MaxTraceRecursionDepth"], decoded_value.MaxTraceRecursionDepth, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_PIPELINE_CONFIG1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1& meta_struct = *data;
        FieldToJson(jdata["MaxTraceRecursionDepth"], decoded_value.MaxTraceRecursionDepth, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_OBJECT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_OBJECT_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["NumSubobjects"], decoded_value.NumSubobjects, options); //
        ; ///< @todo Generate for pSubobjects[NumSubobjects]: D3D12_STATE_SUBOBJECT [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& meta_struct = *data;
        FieldToJson(jdata["StartAddress"], decoded_value.StartAddress, options); //
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE& meta_struct = *data;
        FieldToJson(jdata["StartAddress"], decoded_value.StartAddress, options); //
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& meta_struct = *data;
        FieldToJson(jdata["StartAddress"], decoded_value.StartAddress, options); //
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); //
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& meta_struct = *data;
        FieldToJson(jdata["Transform3x4"], decoded_value.Transform3x4, options); //
        FieldToJson(jdata["IndexFormat"], decoded_value.IndexFormat, options); // [is_enum]
        FieldToJson(jdata["VertexFormat"], decoded_value.VertexFormat, options); // [is_enum]
        FieldToJson(jdata["IndexCount"], decoded_value.IndexCount, options); //
        FieldToJson(jdata["VertexCount"], decoded_value.VertexCount, options); //
        FieldToJson(jdata["IndexBuffer"], decoded_value.IndexBuffer, options); //
        ; ///< @todo Generate for VertexBuffer[None]: D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_AABB* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_AABB& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_AABB& meta_struct = *data;
        FieldToJson(jdata["MinX"], decoded_value.MinX, options); //
        FieldToJson(jdata["MinY"], decoded_value.MinY, options); //
        FieldToJson(jdata["MinZ"], decoded_value.MinZ, options); //
        FieldToJson(jdata["MaxX"], decoded_value.MaxX, options); //
        FieldToJson(jdata["MaxY"], decoded_value.MaxY, options); //
        FieldToJson(jdata["MaxZ"], decoded_value.MaxZ, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& meta_struct = *data;
        FieldToJson(jdata["AABBCount"], decoded_value.AABBCount, options); //
        ; ///< @todo Generate for AABBs[None]: D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& meta_struct = *data;
        FieldToJson(jdata["DestBuffer"], decoded_value.DestBuffer, options); //
        FieldToJson(jdata["InfoType"], decoded_value.InfoType, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& meta_struct = *data;
        FieldToJson(jdata["CompactedSizeInBytes"], decoded_value.CompactedSizeInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& meta_struct = *data;
        FieldToJson(jdata["DecodedSizeInBytes"], decoded_value.DecodedSizeInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["NumDescs"], decoded_value.NumDescs, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& meta_struct = *data;
        FieldToJson(jdata["SerializedSizeInBytes"], decoded_value.SerializedSizeInBytes, options); //
        FieldToJson(jdata["NumBottomLevelAccelerationStructurePointers"], decoded_value.NumBottomLevelAccelerationStructurePointers, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& meta_struct = *data;
        ; ///< @todo Generate for DriverOpaqueGUID[None]: GUID [is_struct]
        ; ///< @todo Generate for DriverOpaqueVersioningData[16]: BYTE [is_array]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& meta_struct = *data;
        ; ///< @todo Generate for DriverMatchingIdentifier[None]: D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER [is_struct]
        FieldToJson(jdata["SerializedSizeInBytesIncludingHeader"], decoded_value.SerializedSizeInBytesIncludingHeader, options); //
        FieldToJson(jdata["DeserializedSizeInBytes"], decoded_value.DeserializedSizeInBytes, options); //
        FieldToJson(jdata["NumBottomLevelAccelerationStructurePointersAfterHeader"], decoded_value.NumBottomLevelAccelerationStructurePointersAfterHeader, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& meta_struct = *data;
        FieldToJson(jdata["CurrentSizeInBytes"], decoded_value.CurrentSizeInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_INSTANCE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_INSTANCE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_INSTANCE_DESC& meta_struct = *data;
        ; ///< @todo Generate for Transform[12]: FLOAT [is_array]
        FieldToJson(jdata["InstanceID"], decoded_value.InstanceID, options); //
        FieldToJson(jdata["InstanceMask"], decoded_value.InstanceMask, options); //
        FieldToJson(jdata["InstanceContributionToHitGroupIndex"], decoded_value.InstanceContributionToHitGroupIndex, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); //
        FieldToJson(jdata["AccelerationStructure"], decoded_value.AccelerationStructure, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_RAYTRACING_GEOMETRY_DESC needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        FieldToJson(jdata["NumDescs"], decoded_value.NumDescs, options); //
        FieldToJson(jdata["DescsLayout"], decoded_value.DescsLayout, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& meta_struct = *data;
        FieldToJson(jdata["DestAccelerationStructureData"], decoded_value.DestAccelerationStructureData, options); //
        ; ///< @todo Generate for Inputs[None]: D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS [is_struct]
        FieldToJson(jdata["SourceAccelerationStructureData"], decoded_value.SourceAccelerationStructureData, options); //
        FieldToJson(jdata["ScratchAccelerationStructureData"], decoded_value.ScratchAccelerationStructureData, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& meta_struct = *data;
        FieldToJson(jdata["ResultDataMaxSizeInBytes"], decoded_value.ResultDataMaxSizeInBytes, options); //
        FieldToJson(jdata["ScratchDataSizeInBytes"], decoded_value.ScratchDataSizeInBytes, options); //
        FieldToJson(jdata["UpdateScratchDataSizeInBytes"], decoded_value.UpdateScratchDataSizeInBytes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_AUTO_BREADCRUMB_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_AUTO_BREADCRUMB_NODE& meta_struct = *data;
        ; ///< @todo Generate for pCommandListDebugNameA[None]: char [is_pointer]
        ; ///< @todo Generate for pCommandListDebugNameW[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for pCommandQueueDebugNameA[None]: char [is_pointer]
        ; ///< @todo Generate for pCommandQueueDebugNameW[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for pCommandList[None]: ID3D12GraphicsCommandList [is_pointer]
        ; ///< @todo Generate for pCommandQueue[None]: ID3D12CommandQueue [is_pointer]
        FieldToJson(jdata["BreadcrumbCount"], decoded_value.BreadcrumbCount, options); //
        ; ///< @todo Generate for pLastBreadcrumbValue[None]: UINT32 [is_pointer]
        ; ///< @todo Generate for pCommandHistory[BreadcrumbCount]: D3D12_AUTO_BREADCRUMB_OP [is_pointer] [is_array] [is_enum]
        ; ///< @todo Generate for pNext[None]: D3D12_AUTO_BREADCRUMB_NODE [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_BREADCRUMB_CONTEXT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT& meta_struct = *data;
        FieldToJson(jdata["BreadcrumbIndex"], decoded_value.BreadcrumbIndex, options); //
        ; ///< @todo Generate for pContextString[None]: wchar_t [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_AUTO_BREADCRUMB_NODE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_AUTO_BREADCRUMB_NODE1& meta_struct = *data;
        ; ///< @todo Generate for pCommandListDebugNameA[None]: char [is_pointer]
        ; ///< @todo Generate for pCommandListDebugNameW[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for pCommandQueueDebugNameA[None]: char [is_pointer]
        ; ///< @todo Generate for pCommandQueueDebugNameW[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for pCommandList[None]: ID3D12GraphicsCommandList [is_pointer]
        ; ///< @todo Generate for pCommandQueue[None]: ID3D12CommandQueue [is_pointer]
        FieldToJson(jdata["BreadcrumbCount"], decoded_value.BreadcrumbCount, options); //
        ; ///< @todo Generate for pLastBreadcrumbValue[None]: UINT [is_pointer]
        ; ///< @todo Generate for pCommandHistory[BreadcrumbCount]: D3D12_AUTO_BREADCRUMB_OP [is_pointer] [is_array] [is_enum]
        ; ///< @todo Generate for pNext[None]: D3D12_AUTO_BREADCRUMB_NODE1 [is_pointer] [is_struct]
        FieldToJson(jdata["BreadcrumbContextsCount"], decoded_value.BreadcrumbContextsCount, options); //
        ; ///< @todo Generate for pBreadcrumbContexts[BreadcrumbContextsCount]: D3D12_DRED_BREADCRUMB_CONTEXT [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA& meta_struct = *data;
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        ; ///< @todo Generate for pHeadAutoBreadcrumbNode[None]: D3D12_AUTO_BREADCRUMB_NODE [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_ALLOCATION_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_ALLOCATION_NODE& meta_struct = *data;
        ; ///< @todo Generate for ObjectNameA[None]: char [is_pointer]
        ; ///< @todo Generate for ObjectNameW[None]: wchar_t [is_pointer]
        FieldToJson(jdata["AllocationType"], decoded_value.AllocationType, options); // [is_enum]
        ; ///< @todo Generate for pNext[None]: D3D12_DRED_ALLOCATION_NODE [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_ALLOCATION_NODE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_ALLOCATION_NODE1& meta_struct = *data;
        ; ///< @todo Generate for ObjectNameA[None]: char [is_pointer]
        ; ///< @todo Generate for ObjectNameW[None]: wchar_t [is_pointer]
        FieldToJson(jdata["AllocationType"], decoded_value.AllocationType, options); // [is_enum]
        ; ///< @todo Generate for pNext[None]: D3D12_DRED_ALLOCATION_NODE1 [is_pointer] [is_struct]
        ; ///< @todo Generate for pObject[None]: IUnknown [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& meta_struct = *data;
        ; ///< @todo Generate for pHeadAutoBreadcrumbNode[None]: D3D12_AUTO_BREADCRUMB_NODE [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& meta_struct = *data;
        ; ///< @todo Generate for pHeadAutoBreadcrumbNode[None]: D3D12_AUTO_BREADCRUMB_NODE1 [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT& meta_struct = *data;
        FieldToJson(jdata["PageFaultVA"], decoded_value.PageFaultVA, options); //
        ; ///< @todo Generate for pHeadExistingAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE [is_pointer] [is_struct]
        ; ///< @todo Generate for pHeadRecentFreedAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1& meta_struct = *data;
        FieldToJson(jdata["PageFaultVA"], decoded_value.PageFaultVA, options); //
        ; ///< @todo Generate for pHeadExistingAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1 [is_pointer] [is_struct]
        ; ///< @todo Generate for pHeadRecentFreedAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1 [is_pointer] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2& meta_struct = *data;
        FieldToJson(jdata["PageFaultVA"], decoded_value.PageFaultVA, options); //
        ; ///< @todo Generate for pHeadExistingAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1 [is_pointer] [is_struct]
        ; ///< @todo Generate for pHeadRecentFreedAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1 [is_pointer] [is_struct]
        FieldToJson(jdata["PageFaultFlags"], decoded_value.PageFaultFlags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1& meta_struct = *data;
        FieldToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options); //
        ; ///< @todo Generate for AutoBreadcrumbsOutput[None]: D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT [is_struct]
        ; ///< @todo Generate for PageFaultOutput[None]: D3D12_DRED_PAGE_FAULT_OUTPUT [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2& meta_struct = *data;
        FieldToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options); //
        ; ///< @todo Generate for AutoBreadcrumbsOutput[None]: D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1 [is_struct]
        ; ///< @todo Generate for PageFaultOutput[None]: D3D12_DRED_PAGE_FAULT_OUTPUT1 [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3& meta_struct = *data;
        FieldToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options); //
        ; ///< @todo Generate for AutoBreadcrumbsOutput[None]: D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1 [is_struct]
        ; ///< @todo Generate for PageFaultOutput[None]: D3D12_DRED_PAGE_FAULT_OUTPUT2 [is_struct]
        FieldToJson(jdata["DeviceState"], decoded_value.DeviceState, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& meta_struct = *data;
        FieldToJson(jdata["Version"], decoded_value.Version, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); //
        FieldToJson(jdata["Count"], decoded_value.Count, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); //
        FieldToJson(jdata["Count"], decoded_value.Count, options); //
        ; ///< @todo Generate for pTypes[Count]: GUID [is_pointer] [is_array] [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1& meta_struct = *data;
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); //
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        ; ///< @todo Generate for ProtectionType[None]: GUID [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& meta_struct = *data;
        ; ///< @todo Generate for ClearValue[None]: D3D12_CLEAR_VALUE [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["AdditionalWidth"], decoded_value.AdditionalWidth, options); //
        FieldToJson(jdata["AdditionalHeight"], decoded_value.AdditionalHeight, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_RENDER_PASS_BEGINNING_ACCESS needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["SrcSubresource"], decoded_value.SrcSubresource, options); //
        FieldToJson(jdata["DstSubresource"], decoded_value.DstSubresource, options); //
        FieldToJson(jdata["DstX"], decoded_value.DstX, options); //
        FieldToJson(jdata["DstY"], decoded_value.DstY, options); //
        ; ///< @todo Generate for SrcRect[None]: tagRECT [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& meta_struct = *data;
        ; ///< @todo Generate for pSrcResource[None]: ID3D12Resource [is_pointer]
        ; ///< @todo Generate for pDstResource[None]: ID3D12Resource [is_pointer]
        FieldToJson(jdata["SubresourceCount"], decoded_value.SubresourceCount, options); //
        ; ///< @todo Generate for pSubresourceParameters[SubresourceCount]: D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["Format"], decoded_value.Format, options); // [is_enum]
        FieldToJson(jdata["ResolveMode"], decoded_value.ResolveMode, options); // [is_enum]
        FieldToJson(jdata["PreserveResolveSource"], decoded_value.PreserveResolveSource, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["AdditionalWidth"], decoded_value.AdditionalWidth, options); //
        FieldToJson(jdata["AdditionalHeight"], decoded_value.AdditionalHeight, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
        ; ///< @todo ALERT: Union member 0 of D3D12_RENDER_PASS_ENDING_ACCESS needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_RENDER_TARGET_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC& meta_struct = *data;
        ; ///< @todo Generate for cpuDescriptor[None]: D3D12_CPU_DESCRIPTOR_HANDLE [is_struct]
        ; ///< @todo Generate for BeginningAccess[None]: D3D12_RENDER_PASS_BEGINNING_ACCESS [is_struct]
        ; ///< @todo Generate for EndingAccess[None]: D3D12_RENDER_PASS_ENDING_ACCESS [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& meta_struct = *data;
        ; ///< @todo Generate for cpuDescriptor[None]: D3D12_CPU_DESCRIPTOR_HANDLE [is_struct]
        ; ///< @todo Generate for DepthBeginningAccess[None]: D3D12_RENDER_PASS_BEGINNING_ACCESS [is_struct]
        ; ///< @todo Generate for StencilBeginningAccess[None]: D3D12_RENDER_PASS_BEGINNING_ACCESS [is_struct]
        ; ///< @todo Generate for DepthEndingAccess[None]: D3D12_RENDER_PASS_ENDING_ACCESS [is_struct]
        ; ///< @todo Generate for StencilEndingAccess[None]: D3D12_RENDER_PASS_ENDING_ACCESS [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_RAYS_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_RAYS_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_RAYS_DESC& meta_struct = *data;
        ; ///< @todo Generate for RayGenerationShaderRecord[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE [is_struct]
        ; ///< @todo Generate for MissShaderTable[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE [is_struct]
        ; ///< @todo Generate for HitGroupTable[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE [is_struct]
        ; ///< @todo Generate for CallableShaderTable[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE [is_struct]
        FieldToJson(jdata["Width"], decoded_value.Width, options); //
        FieldToJson(jdata["Height"], decoded_value.Height, options); //
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_CACHE_SESSION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_CACHE_SESSION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_CACHE_SESSION_DESC& meta_struct = *data;
        ; ///< @todo Generate for Identifier[None]: GUID [is_struct]
        FieldToJson(jdata["Mode"], decoded_value.Mode, options); // [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        FieldToJson(jdata["MaximumInMemoryCacheSizeBytes"], decoded_value.MaximumInMemoryCacheSizeBytes, options); //
        FieldToJson(jdata["MaximumInMemoryCacheEntries"], decoded_value.MaximumInMemoryCacheEntries, options); //
        FieldToJson(jdata["MaximumValueFileSizeBytes"], decoded_value.MaximumValueFileSizeBytes, options); //
        FieldToJson(jdata["Version"], decoded_value.Version, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BARRIER_SUBRESOURCE_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE& meta_struct = *data;
        FieldToJson(jdata["IndexOrFirstMipLevel"], decoded_value.IndexOrFirstMipLevel, options); //
        FieldToJson(jdata["NumMipLevels"], decoded_value.NumMipLevels, options); //
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); //
        FieldToJson(jdata["NumArraySlices"], decoded_value.NumArraySlices, options); //
        FieldToJson(jdata["FirstPlane"], decoded_value.FirstPlane, options); //
        FieldToJson(jdata["NumPlanes"], decoded_value.NumPlanes, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_BARRIER& meta_struct = *data;
        FieldToJson(jdata["SyncBefore"], decoded_value.SyncBefore, options); // [is_enum]
        FieldToJson(jdata["SyncAfter"], decoded_value.SyncAfter, options); // [is_enum]
        FieldToJson(jdata["AccessBefore"], decoded_value.AccessBefore, options); // [is_enum]
        FieldToJson(jdata["AccessAfter"], decoded_value.AccessAfter, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXTURE_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXTURE_BARRIER& meta_struct = *data;
        FieldToJson(jdata["SyncBefore"], decoded_value.SyncBefore, options); // [is_enum]
        FieldToJson(jdata["SyncAfter"], decoded_value.SyncAfter, options); // [is_enum]
        FieldToJson(jdata["AccessBefore"], decoded_value.AccessBefore, options); // [is_enum]
        FieldToJson(jdata["AccessAfter"], decoded_value.AccessAfter, options); // [is_enum]
        FieldToJson(jdata["LayoutBefore"], decoded_value.LayoutBefore, options); // [is_enum]
        FieldToJson(jdata["LayoutAfter"], decoded_value.LayoutAfter, options); // [is_enum]
        ; ///< @todo Generate for pResource[None]: ID3D12Resource [is_pointer]
        ; ///< @todo Generate for Subresources[None]: D3D12_BARRIER_SUBRESOURCE_RANGE [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_BARRIER& meta_struct = *data;
        FieldToJson(jdata["SyncBefore"], decoded_value.SyncBefore, options); // [is_enum]
        FieldToJson(jdata["SyncAfter"], decoded_value.SyncAfter, options); // [is_enum]
        FieldToJson(jdata["AccessBefore"], decoded_value.AccessBefore, options); // [is_enum]
        FieldToJson(jdata["AccessAfter"], decoded_value.AccessAfter, options); // [is_enum]
        ; ///< @todo Generate for pResource[None]: ID3D12Resource [is_pointer]
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); //
        FieldToJson(jdata["Size"], decoded_value.Size, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_DATA& meta_struct = *data;
        ; ///< @todo Generate for pData[None]: void [is_pointer]
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); //
        FieldToJson(jdata["SlicePitch"], decoded_value.SlicePitch, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MEMCPY_DEST* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MEMCPY_DEST& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MEMCPY_DEST& meta_struct = *data;
        ; ///< @todo Generate for pData[None]: void [is_pointer]
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); //
        FieldToJson(jdata["SlicePitch"], decoded_value.SlicePitch, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_CONFIGURATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_CONFIGURATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_CONFIGURATION_DESC& meta_struct = *data;
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
        FieldToJson(jdata["GpuBasedValidationFlags"], decoded_value.GpuBasedValidationFlags, options); //
        FieldToJson(jdata["SDKVersion"], decoded_value.SDKVersion, options); //
        FieldToJson(jdata["NumEnabledExperimentalFeatures"], decoded_value.NumEnabledExperimentalFeatures, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_MESH_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["ThreadGroupCountX"], decoded_value.ThreadGroupCountX, options); //
        FieldToJson(jdata["ThreadGroupCountY"], decoded_value.ThreadGroupCountY, options); //
        FieldToJson(jdata["ThreadGroupCountZ"], decoded_value.ThreadGroupCountZ, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D_SHADER_MACRO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D_SHADER_MACRO& decoded_value = *data->decoded_value;
        const Decoded_D3D_SHADER_MACRO& meta_struct = *data;
        ; ///< @todo Generate for Name[None]: char [is_pointer]
        ; ///< @todo Generate for Definition[None]: char [is_pointer]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& meta_struct = *data;
        FieldToJson(jdata["MaxMessagesPerCommandList"], decoded_value.MaxMessagesPerCommandList, options); //
        FieldToJson(jdata["DefaultShaderPatchMode"], decoded_value.DefaultShaderPatchMode, options); // [is_enum]
        FieldToJson(jdata["PipelineStateCreateFlags"], decoded_value.PipelineStateCreateFlags, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& meta_struct = *data;
        FieldToJson(jdata["SlowdownFactor"], decoded_value.SlowdownFactor, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& meta_struct = *data;
        FieldToJson(jdata["ShaderPatchMode"], decoded_value.ShaderPatchMode, options); // [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MESSAGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MESSAGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MESSAGE& meta_struct = *data;
        FieldToJson(jdata["Category"], decoded_value.Category, options); // [is_enum]
        FieldToJson(jdata["Severity"], decoded_value.Severity, options); // [is_enum]
        FieldToJson(jdata["ID"], decoded_value.ID, options); // [is_enum]
        ; ///< @todo Generate for pDescription[None]: char [is_pointer]
        FieldToJson(jdata["DescriptionByteLength"], decoded_value.DescriptionByteLength, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INFO_QUEUE_FILTER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INFO_QUEUE_FILTER_DESC& meta_struct = *data;
        FieldToJson(jdata["NumCategories"], decoded_value.NumCategories, options); //
        ; ///< @todo Generate for pCategoryList[NumCategories]: D3D12_MESSAGE_CATEGORY [is_pointer] [is_array] [is_enum]
        FieldToJson(jdata["NumSeverities"], decoded_value.NumSeverities, options); //
        ; ///< @todo Generate for pSeverityList[NumSeverities]: D3D12_MESSAGE_SEVERITY [is_pointer] [is_array] [is_enum]
        FieldToJson(jdata["NumIDs"], decoded_value.NumIDs, options); //
        ; ///< @todo Generate for pIDList[NumIDs]: D3D12_MESSAGE_ID [is_pointer] [is_array] [is_enum]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INFO_QUEUE_FILTER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INFO_QUEUE_FILTER& meta_struct = *data;
        ; ///< @todo Generate for AllowList[None]: D3D12_INFO_QUEUE_FILTER_DESC [is_struct]
        ; ///< @todo Generate for DenyList[None]: D3D12_INFO_QUEUE_FILTER_DESC [is_struct]
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const tagRECT& decoded_value = *data->decoded_value;
        const Decoded_tagRECT& meta_struct = *data;
        FieldToJson(jdata["left"], decoded_value.left, options); //
        FieldToJson(jdata["top"], decoded_value.top, options); //
        FieldToJson(jdata["right"], decoded_value.right, options); //
        FieldToJson(jdata["bottom"], decoded_value.bottom, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const tagPOINT& decoded_value = *data->decoded_value;
        const Decoded_tagPOINT& meta_struct = *data;
        FieldToJson(jdata["x"], decoded_value.x, options); //
        FieldToJson(jdata["y"], decoded_value.y, options); //
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const _SECURITY_ATTRIBUTES& decoded_value = *data->decoded_value;
        const Decoded__SECURITY_ATTRIBUTES& meta_struct = *data;
        FieldToJson(jdata["nLength"], decoded_value.nLength, options); //
        ; ///< @todo Generate for lpSecurityDescriptor[None]: void [is_pointer]
        FieldToJson(jdata["bInheritHandle"], decoded_value.bInheritHandle, options); //
    }
}

/// @todo Put the custom implementations in the generator Python here rather than
/// creating a whole new compilation unit for them.

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
            auto& color = jdata["Color"];
            FieldToJson(color[0], decoded_value.Color[0], options);
            FieldToJson(color[1], decoded_value.Color[1], options);
            FieldToJson(color[2], decoded_value.Color[2], options);
            FieldToJson(color[3], decoded_value.Color[3], options);
            FieldToJson(color, &meta_struct.Color, options);
            FieldToJson(color, decoded_value.Color, options);
            FieldToJson(color, decoded_value.Color, 4, options);

            /// @todo look at this in the debugger and choose one of the compact options.
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
