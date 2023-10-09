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
#include "generated_dx12_struct_decoders.h"

#include "util/json_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::JsonOptions;

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_FRAME_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_FRAME_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["PresentCount"], decoded_value.PresentCount, options); // base case
        FieldToJson(jdata["PresentRefreshCount"], decoded_value.PresentRefreshCount, options); // base case
        FieldToJson(jdata["SyncRefreshCount"], decoded_value.SyncRefreshCount, options); // base case
        ; ///< @todo Generate for SyncQPCTime[None]: LARGE_INTEGER [is_struct]
        ; ///< @todo Generate for SyncGPUTime[None]: LARGE_INTEGER [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_MAPPED_RECT& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MAPPED_RECT& meta_struct = *data;
        FieldToJson(jdata["Pitch"], decoded_value.Pitch, options); // base case
        ; ///< @todo Generate for pBits[None]: BYTE [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const LUID& decoded_value = *data->decoded_value;
        const Decoded_LUID& meta_struct = *data;
        FieldToJson(jdata["LowPart"], decoded_value.LowPart, options); // base case
        FieldToJson(jdata["HighPart"], decoded_value.HighPart, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC& meta_struct = *data;
        ; ///< @todo Generate for Description[128]: wchar_t [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); // base case
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); // base case
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); // base case
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); // base case
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); // base case
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); // base case
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); // base case
        ; ///< @todo Generate for AdapterLuid[None]: LUID [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_OUTPUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTPUT_DESC& meta_struct = *data;
        ; ///< @todo Generate for DeviceName[32]: wchar_t [is_array]
        ; ///< @todo Generate for DesktopCoordinates[None]: tagRECT [is_struct]
        FieldToJson(jdata["AttachedToDesktop"], decoded_value.AttachedToDesktop, options); // base case
        ; ///< @todo Generate for Rotation[None]: DXGI_MODE_ROTATION [is_enum]
        ; ///< @todo Generate for Monitor[None]: void [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SHARED_RESOURCE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_SHARED_RESOURCE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SHARED_RESOURCE& meta_struct = *data;
        ; ///< @todo Generate for Handle[None]: void [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SURFACE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_SURFACE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SURFACE_DESC& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_DESC& meta_struct = *data;
        ; ///< @todo Generate for BufferDesc[None]: DXGI_MODE_DESC [is_struct]
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        FieldToJson(jdata["BufferUsage"], decoded_value.BufferUsage, options); // base case
        FieldToJson(jdata["BufferCount"], decoded_value.BufferCount, options); // base case
        ; ///< @todo Generate for OutputWindow[None]: void [is_pointer]
        FieldToJson(jdata["Windowed"], decoded_value.Windowed, options); // base case
        ; ///< @todo Generate for SwapEffect[None]: DXGI_SWAP_EFFECT [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC1& meta_struct = *data;
        ; ///< @todo Generate for Description[128]: wchar_t [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); // base case
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); // base case
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); // base case
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); // base case
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); // base case
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); // base case
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); // base case
        ; ///< @todo Generate for AdapterLuid[None]: LUID [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_MOVE_RECT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_MOVE_RECT& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_MOVE_RECT& meta_struct = *data;
        ; ///< @todo Generate for SourcePoint[None]: tagPOINT [is_struct]
        ; ///< @todo Generate for DestinationRect[None]: tagRECT [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_DESC& meta_struct = *data;
        ; ///< @todo Generate for ModeDesc[None]: DXGI_MODE_DESC [is_struct]
        ; ///< @todo Generate for Rotation[None]: DXGI_MODE_ROTATION [is_enum]
        FieldToJson(jdata["DesktopImageInSystemMemory"], decoded_value.DesktopImageInSystemMemory, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_POSITION* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_POINTER_POSITION& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_POINTER_POSITION& meta_struct = *data;
        ; ///< @todo Generate for Position[None]: tagPOINT [is_struct]
        FieldToJson(jdata["Visible"], decoded_value.Visible, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_POINTER_SHAPE_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options); // base case
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        FieldToJson(jdata["Pitch"], decoded_value.Pitch, options); // base case
        ; ///< @todo Generate for HotSpot[None]: tagPOINT [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_FRAME_INFO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_FRAME_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_FRAME_INFO& meta_struct = *data;
        ; ///< @todo Generate for LastPresentTime[None]: LARGE_INTEGER [is_struct]
        ; ///< @todo Generate for LastMouseUpdateTime[None]: LARGE_INTEGER [is_struct]
        FieldToJson(jdata["AccumulatedFrames"], decoded_value.AccumulatedFrames, options); // base case
        FieldToJson(jdata["RectsCoalesced"], decoded_value.RectsCoalesced, options); // base case
        FieldToJson(jdata["ProtectedContentMaskedOut"], decoded_value.ProtectedContentMaskedOut, options); // base case
        ; ///< @todo Generate for PointerPosition[None]: DXGI_OUTDUPL_POINTER_POSITION [is_struct]
        FieldToJson(jdata["TotalMetadataBufferSize"], decoded_value.TotalMetadataBufferSize, options); // base case
        FieldToJson(jdata["PointerShapeBufferSize"], decoded_value.PointerShapeBufferSize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_MODE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MODE_DESC1& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        ; ///< @todo Generate for RefreshRate[None]: DXGI_RATIONAL [is_struct]
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        ; ///< @todo Generate for ScanlineOrdering[None]: DXGI_MODE_SCANLINE_ORDER [is_enum]
        ; ///< @todo Generate for Scaling[None]: DXGI_MODE_SCALING [is_enum]
        FieldToJson(jdata["Stereo"], decoded_value.Stereo, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_DESC1& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        FieldToJson(jdata["Stereo"], decoded_value.Stereo, options); // base case
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        FieldToJson(jdata["BufferUsage"], decoded_value.BufferUsage, options); // base case
        FieldToJson(jdata["BufferCount"], decoded_value.BufferCount, options); // base case
        ; ///< @todo Generate for Scaling[None]: DXGI_SCALING [is_enum]
        ; ///< @todo Generate for SwapEffect[None]: DXGI_SWAP_EFFECT [is_enum]
        ; ///< @todo Generate for AlphaMode[None]: DXGI_ALPHA_MODE [is_enum]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC& meta_struct = *data;
        ; ///< @todo Generate for RefreshRate[None]: DXGI_RATIONAL [is_struct]
        ; ///< @todo Generate for ScanlineOrdering[None]: DXGI_MODE_SCANLINE_ORDER [is_enum]
        ; ///< @todo Generate for Scaling[None]: DXGI_MODE_SCALING [is_enum]
        FieldToJson(jdata["Windowed"], decoded_value.Windowed, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_PRESENT_PARAMETERS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_PRESENT_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_PRESENT_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["DirtyRectsCount"], decoded_value.DirtyRectsCount, options); // base case
        ; ///< @todo Generate for pDirtyRects[DirtyRectsCount]: tagRECT [is_pointer] [is_array] [is_struct]
        ; ///< @todo Generate for pScrollRect[None]: tagRECT [is_pointer] [is_struct]
        ; ///< @todo Generate for pScrollOffset[None]: tagPOINT [is_pointer] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC2& meta_struct = *data;
        ; ///< @todo Generate for Description[128]: wchar_t [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); // base case
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); // base case
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); // base case
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); // base case
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); // base case
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); // base case
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); // base case
        ; ///< @todo Generate for AdapterLuid[None]: LUID [is_struct]
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // base case
        ; ///< @todo Generate for GraphicsPreemptionGranularity[None]: DXGI_GRAPHICS_PREEMPTION_GRANULARITY [is_enum]
        ; ///< @todo Generate for ComputePreemptionGranularity[None]: DXGI_COMPUTE_PREEMPTION_GRANULARITY [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MATRIX_3X2_F* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_MATRIX_3X2_F& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MATRIX_3X2_F& meta_struct = *data;
        FieldToJson(jdata["_11"], decoded_value._11, options); // base case
        FieldToJson(jdata["_12"], decoded_value._12, options); // base case
        FieldToJson(jdata["_21"], decoded_value._21, options); // base case
        FieldToJson(jdata["_22"], decoded_value._22, options); // base case
        FieldToJson(jdata["_31"], decoded_value._31, options); // base case
        FieldToJson(jdata["_32"], decoded_value._32, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_DECODE_SWAP_CHAIN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC& meta_struct = *data;
        FieldToJson(jdata["Flags"], decoded_value.Flags, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS_MEDIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_FRAME_STATISTICS_MEDIA& decoded_value = *data->decoded_value;
        const Decoded_DXGI_FRAME_STATISTICS_MEDIA& meta_struct = *data;
        FieldToJson(jdata["PresentCount"], decoded_value.PresentCount, options); // base case
        FieldToJson(jdata["PresentRefreshCount"], decoded_value.PresentRefreshCount, options); // base case
        FieldToJson(jdata["SyncRefreshCount"], decoded_value.SyncRefreshCount, options); // base case
        ; ///< @todo Generate for SyncQPCTime[None]: LARGE_INTEGER [is_struct]
        ; ///< @todo Generate for SyncGPUTime[None]: LARGE_INTEGER [is_struct]
        ; ///< @todo Generate for CompositionMode[None]: DXGI_FRAME_PRESENTATION_MODE [is_enum]
        FieldToJson(jdata["ApprovedPresentDuration"], decoded_value.ApprovedPresentDuration, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_QUERY_VIDEO_MEMORY_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO& meta_struct = *data;
        FieldToJson(jdata["Budget"], decoded_value.Budget, options); // base case
        FieldToJson(jdata["CurrentUsage"], decoded_value.CurrentUsage, options); // base case
        FieldToJson(jdata["AvailableForReservation"], decoded_value.AvailableForReservation, options); // base case
        FieldToJson(jdata["CurrentReservation"], decoded_value.CurrentReservation, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_HDR_METADATA_HDR10& decoded_value = *data->decoded_value;
        const Decoded_DXGI_HDR_METADATA_HDR10& meta_struct = *data;
        ; ///< @todo Generate for RedPrimary[2]: UINT16 [is_array]
        ; ///< @todo Generate for GreenPrimary[2]: UINT16 [is_array]
        ; ///< @todo Generate for BluePrimary[2]: UINT16 [is_array]
        ; ///< @todo Generate for WhitePoint[2]: UINT16 [is_array]
        FieldToJson(jdata["MaxMasteringLuminance"], decoded_value.MaxMasteringLuminance, options); // base case
        FieldToJson(jdata["MinMasteringLuminance"], decoded_value.MinMasteringLuminance, options); // base case
        FieldToJson(jdata["MaxContentLightLevel"], decoded_value.MaxContentLightLevel, options); // base case
        FieldToJson(jdata["MaxFrameAverageLightLevel"], decoded_value.MaxFrameAverageLightLevel, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10PLUS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_HDR_METADATA_HDR10PLUS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_HDR_METADATA_HDR10PLUS& meta_struct = *data;
        ; ///< @todo Generate for Data[72]: BYTE [is_array]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC3* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC3& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC3& meta_struct = *data;
        ; ///< @todo Generate for Description[128]: wchar_t [is_array]
        FieldToJson(jdata["VendorId"], decoded_value.VendorId, options); // base case
        FieldToJson(jdata["DeviceId"], decoded_value.DeviceId, options); // base case
        FieldToJson(jdata["SubSysId"], decoded_value.SubSysId, options); // base case
        FieldToJson(jdata["Revision"], decoded_value.Revision, options); // base case
        FieldToJson(jdata["DedicatedVideoMemory"], decoded_value.DedicatedVideoMemory, options); // base case
        FieldToJson(jdata["DedicatedSystemMemory"], decoded_value.DedicatedSystemMemory, options); // base case
        FieldToJson(jdata["SharedSystemMemory"], decoded_value.SharedSystemMemory, options); // base case
        ; ///< @todo Generate for AdapterLuid[None]: LUID [is_struct]
        ; ///< @todo Generate for Flags[None]: DXGI_ADAPTER_FLAG3 [is_enum]
        ; ///< @todo Generate for GraphicsPreemptionGranularity[None]: DXGI_GRAPHICS_PREEMPTION_GRANULARITY [is_enum]
        ; ///< @todo Generate for ComputePreemptionGranularity[None]: DXGI_COMPUTE_PREEMPTION_GRANULARITY [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_OUTPUT_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTPUT_DESC1& meta_struct = *data;
        ; ///< @todo Generate for DeviceName[32]: wchar_t [is_array]
        ; ///< @todo Generate for DesktopCoordinates[None]: tagRECT [is_struct]
        FieldToJson(jdata["AttachedToDesktop"], decoded_value.AttachedToDesktop, options); // base case
        ; ///< @todo Generate for Rotation[None]: DXGI_MODE_ROTATION [is_enum]
        ; ///< @todo Generate for Monitor[None]: void [is_pointer]
        FieldToJson(jdata["BitsPerColor"], decoded_value.BitsPerColor, options); // base case
        ; ///< @todo Generate for ColorSpace[None]: DXGI_COLOR_SPACE_TYPE [is_enum]
        ; ///< @todo Generate for RedPrimary[2]: FLOAT [is_array]
        ; ///< @todo Generate for GreenPrimary[2]: FLOAT [is_array]
        ; ///< @todo Generate for BluePrimary[2]: FLOAT [is_array]
        ; ///< @todo Generate for WhitePoint[2]: FLOAT [is_array]
        FieldToJson(jdata["MinLuminance"], decoded_value.MinLuminance, options); // base case
        FieldToJson(jdata["MaxLuminance"], decoded_value.MaxLuminance, options); // base case
        FieldToJson(jdata["MaxFullFrameLuminance"], decoded_value.MaxFullFrameLuminance, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RATIONAL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_RATIONAL& decoded_value = *data->decoded_value;
        const Decoded_DXGI_RATIONAL& meta_struct = *data;
        FieldToJson(jdata["Numerator"], decoded_value.Numerator, options); // base case
        FieldToJson(jdata["Denominator"], decoded_value.Denominator, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SAMPLE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_SAMPLE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SAMPLE_DESC& meta_struct = *data;
        FieldToJson(jdata["Count"], decoded_value.Count, options); // base case
        FieldToJson(jdata["Quality"], decoded_value.Quality, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RGB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_RGB& decoded_value = *data->decoded_value;
        const Decoded_DXGI_RGB& meta_struct = *data;
        FieldToJson(jdata["Red"], decoded_value.Red, options); // base case
        FieldToJson(jdata["Green"], decoded_value.Green, options); // base case
        FieldToJson(jdata["Blue"], decoded_value.Blue, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3DCOLORVALUE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3DCOLORVALUE& decoded_value = *data->decoded_value;
        const Decoded_D3DCOLORVALUE& meta_struct = *data;
        FieldToJson(jdata["r"], decoded_value.r, options); // base case
        FieldToJson(jdata["g"], decoded_value.g, options); // base case
        FieldToJson(jdata["b"], decoded_value.b, options); // base case
        FieldToJson(jdata["a"], decoded_value.a, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_GAMMA_CONTROL& decoded_value = *data->decoded_value;
        const Decoded_DXGI_GAMMA_CONTROL& meta_struct = *data;
        ; ///< @todo Generate for Scale[None]: DXGI_RGB [is_struct]
        ; ///< @todo Generate for Offset[None]: DXGI_RGB [is_struct]
        ; ///< @todo Generate for GammaCurve[1025]: DXGI_RGB [is_array] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_GAMMA_CONTROL_CAPABILITIES& decoded_value = *data->decoded_value;
        const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES& meta_struct = *data;
        FieldToJson(jdata["ScaleAndOffsetSupported"], decoded_value.ScaleAndOffsetSupported, options); // base case
        FieldToJson(jdata["MaxConvertedValue"], decoded_value.MaxConvertedValue, options); // base case
        FieldToJson(jdata["MinConvertedValue"], decoded_value.MinConvertedValue, options); // base case
        FieldToJson(jdata["NumGammaControlPoints"], decoded_value.NumGammaControlPoints, options); // base case
        ; ///< @todo Generate for ControlPointPositions[1025]: float [is_array]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_MODE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MODE_DESC& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        ; ///< @todo Generate for RefreshRate[None]: DXGI_RATIONAL [is_struct]
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        ; ///< @todo Generate for ScanlineOrdering[None]: DXGI_MODE_SCANLINE_ORDER [is_enum]
        ; ///< @todo Generate for Scaling[None]: DXGI_MODE_SCALING [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_DC_HUFFMAN_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE& meta_struct = *data;
        ; ///< @todo Generate for CodeCounts[12]: BYTE [is_array]
        ; ///< @todo Generate for CodeValues[12]: BYTE [is_array]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_AC_HUFFMAN_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE& meta_struct = *data;
        ; ///< @todo Generate for CodeCounts[16]: BYTE [is_array]
        ; ///< @todo Generate for CodeValues[162]: BYTE [is_array]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_QUANTIZATION_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_QUANTIZATION_TABLE& meta_struct = *data;
        ; ///< @todo Generate for Elements[64]: BYTE [is_array]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_COMMAND_QUEUE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMMAND_QUEUE_DESC& meta_struct = *data;
        ; ///< @todo Generate for Type[None]: D3D12_COMMAND_LIST_TYPE [is_enum]
        FieldToJson(jdata["Priority"], decoded_value.Priority, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_COMMAND_QUEUE_FLAGS [is_enum]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_INPUT_ELEMENT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INPUT_ELEMENT_DESC& meta_struct = *data;
        ; ///< @todo Generate for SemanticName[None]: char [is_pointer]
        FieldToJson(jdata["SemanticIndex"], decoded_value.SemanticIndex, options); // base case
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        FieldToJson(jdata["InputSlot"], decoded_value.InputSlot, options); // base case
        FieldToJson(jdata["AlignedByteOffset"], decoded_value.AlignedByteOffset, options); // base case
        ; ///< @todo Generate for InputSlotClass[None]: D3D12_INPUT_CLASSIFICATION [is_enum]
        FieldToJson(jdata["InstanceDataStepRate"], decoded_value.InstanceDataStepRate, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SO_DECLARATION_ENTRY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SO_DECLARATION_ENTRY& meta_struct = *data;
        FieldToJson(jdata["Stream"], decoded_value.Stream, options); // base case
        ; ///< @todo Generate for SemanticName[None]: char [is_pointer]
        FieldToJson(jdata["SemanticIndex"], decoded_value.SemanticIndex, options); // base case
        FieldToJson(jdata["StartComponent"], decoded_value.StartComponent, options); // base case
        FieldToJson(jdata["ComponentCount"], decoded_value.ComponentCount, options); // base case
        FieldToJson(jdata["OutputSlot"], decoded_value.OutputSlot, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_VIEWPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEWPORT& meta_struct = *data;
        FieldToJson(jdata["TopLeftX"], decoded_value.TopLeftX, options); // base case
        FieldToJson(jdata["TopLeftY"], decoded_value.TopLeftY, options); // base case
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        FieldToJson(jdata["MinDepth"], decoded_value.MinDepth, options); // base case
        FieldToJson(jdata["MaxDepth"], decoded_value.MaxDepth, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_BOX& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BOX& meta_struct = *data;
        FieldToJson(jdata["left"], decoded_value.left, options); // base case
        FieldToJson(jdata["top"], decoded_value.top, options); // base case
        FieldToJson(jdata["front"], decoded_value.front, options); // base case
        FieldToJson(jdata["right"], decoded_value.right, options); // base case
        FieldToJson(jdata["bottom"], decoded_value.bottom, options); // base case
        FieldToJson(jdata["back"], decoded_value.back, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCILOP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCILOP_DESC& meta_struct = *data;
        ; ///< @todo Generate for StencilFailOp[None]: D3D12_STENCIL_OP [is_enum]
        ; ///< @todo Generate for StencilDepthFailOp[None]: D3D12_STENCIL_OP [is_enum]
        ; ///< @todo Generate for StencilPassOp[None]: D3D12_STENCIL_OP [is_enum]
        ; ///< @todo Generate for StencilFunc[None]: D3D12_COMPARISON_FUNC [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC& meta_struct = *data;
        FieldToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options); // base case
        ; ///< @todo Generate for DepthWriteMask[None]: D3D12_DEPTH_WRITE_MASK [is_enum]
        ; ///< @todo Generate for DepthFunc[None]: D3D12_COMPARISON_FUNC [is_enum]
        FieldToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options); // base case
        FieldToJson(jdata["StencilReadMask"], decoded_value.StencilReadMask, options); // base case
        FieldToJson(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options); // base case
        ; ///< @todo Generate for FrontFace[None]: D3D12_DEPTH_STENCILOP_DESC [is_struct]
        ; ///< @todo Generate for BackFace[None]: D3D12_DEPTH_STENCILOP_DESC [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC1& meta_struct = *data;
        FieldToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options); // base case
        ; ///< @todo Generate for DepthWriteMask[None]: D3D12_DEPTH_WRITE_MASK [is_enum]
        ; ///< @todo Generate for DepthFunc[None]: D3D12_COMPARISON_FUNC [is_enum]
        FieldToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options); // base case
        FieldToJson(jdata["StencilReadMask"], decoded_value.StencilReadMask, options); // base case
        FieldToJson(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options); // base case
        ; ///< @todo Generate for FrontFace[None]: D3D12_DEPTH_STENCILOP_DESC [is_struct]
        ; ///< @todo Generate for BackFace[None]: D3D12_DEPTH_STENCILOP_DESC [is_struct]
        FieldToJson(jdata["DepthBoundsTestEnable"], decoded_value.DepthBoundsTestEnable, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCILOP_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCILOP_DESC1& meta_struct = *data;
        ; ///< @todo Generate for StencilFailOp[None]: D3D12_STENCIL_OP [is_enum]
        ; ///< @todo Generate for StencilDepthFailOp[None]: D3D12_STENCIL_OP [is_enum]
        ; ///< @todo Generate for StencilPassOp[None]: D3D12_STENCIL_OP [is_enum]
        ; ///< @todo Generate for StencilFunc[None]: D3D12_COMPARISON_FUNC [is_enum]
        FieldToJson(jdata["StencilReadMask"], decoded_value.StencilReadMask, options); // base case
        FieldToJson(jdata["StencilWriteMask"], decoded_value.StencilWriteMask, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC2& meta_struct = *data;
        FieldToJson(jdata["DepthEnable"], decoded_value.DepthEnable, options); // base case
        ; ///< @todo Generate for DepthWriteMask[None]: D3D12_DEPTH_WRITE_MASK [is_enum]
        ; ///< @todo Generate for DepthFunc[None]: D3D12_COMPARISON_FUNC [is_enum]
        FieldToJson(jdata["StencilEnable"], decoded_value.StencilEnable, options); // base case
        ; ///< @todo Generate for FrontFace[None]: D3D12_DEPTH_STENCILOP_DESC1 [is_struct]
        ; ///< @todo Generate for BackFace[None]: D3D12_DEPTH_STENCILOP_DESC1 [is_struct]
        FieldToJson(jdata["DepthBoundsTestEnable"], decoded_value.DepthBoundsTestEnable, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_TARGET_BLEND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_TARGET_BLEND_DESC& meta_struct = *data;
        FieldToJson(jdata["BlendEnable"], decoded_value.BlendEnable, options); // base case
        FieldToJson(jdata["LogicOpEnable"], decoded_value.LogicOpEnable, options); // base case
        ; ///< @todo Generate for SrcBlend[None]: D3D12_BLEND [is_enum]
        ; ///< @todo Generate for DestBlend[None]: D3D12_BLEND [is_enum]
        ; ///< @todo Generate for BlendOp[None]: D3D12_BLEND_OP [is_enum]
        ; ///< @todo Generate for SrcBlendAlpha[None]: D3D12_BLEND [is_enum]
        ; ///< @todo Generate for DestBlendAlpha[None]: D3D12_BLEND [is_enum]
        ; ///< @todo Generate for BlendOpAlpha[None]: D3D12_BLEND_OP [is_enum]
        ; ///< @todo Generate for LogicOp[None]: D3D12_LOGIC_OP [is_enum]
        FieldToJson(jdata["RenderTargetWriteMask"], decoded_value.RenderTargetWriteMask, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BLEND_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_BLEND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BLEND_DESC& meta_struct = *data;
        FieldToJson(jdata["AlphaToCoverageEnable"], decoded_value.AlphaToCoverageEnable, options); // base case
        FieldToJson(jdata["IndependentBlendEnable"], decoded_value.IndependentBlendEnable, options); // base case
        ; ///< @todo Generate for RenderTarget[8]: D3D12_RENDER_TARGET_BLEND_DESC [is_array] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC& meta_struct = *data;
        ; ///< @todo Generate for FillMode[None]: D3D12_FILL_MODE [is_enum]
        ; ///< @todo Generate for CullMode[None]: D3D12_CULL_MODE [is_enum]
        FieldToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options); // base case
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options); // base case
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options); // base case
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options); // base case
        FieldToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options); // base case
        FieldToJson(jdata["MultisampleEnable"], decoded_value.MultisampleEnable, options); // base case
        FieldToJson(jdata["AntialiasedLineEnable"], decoded_value.AntialiasedLineEnable, options); // base case
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options); // base case
        ; ///< @todo Generate for ConservativeRaster[None]: D3D12_CONSERVATIVE_RASTERIZATION_MODE [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC1& meta_struct = *data;
        ; ///< @todo Generate for FillMode[None]: D3D12_FILL_MODE [is_enum]
        ; ///< @todo Generate for CullMode[None]: D3D12_CULL_MODE [is_enum]
        FieldToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options); // base case
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options); // base case
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options); // base case
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options); // base case
        FieldToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options); // base case
        FieldToJson(jdata["MultisampleEnable"], decoded_value.MultisampleEnable, options); // base case
        FieldToJson(jdata["AntialiasedLineEnable"], decoded_value.AntialiasedLineEnable, options); // base case
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options); // base case
        ; ///< @todo Generate for ConservativeRaster[None]: D3D12_CONSERVATIVE_RASTERIZATION_MODE [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC2& meta_struct = *data;
        ; ///< @todo Generate for FillMode[None]: D3D12_FILL_MODE [is_enum]
        ; ///< @todo Generate for CullMode[None]: D3D12_CULL_MODE [is_enum]
        FieldToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise, options); // base case
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias, options); // base case
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp, options); // base case
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias, options); // base case
        FieldToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable, options); // base case
        ; ///< @todo Generate for LineRasterizationMode[None]: D3D12_LINE_RASTERIZATION_MODE [is_enum]
        FieldToJson(jdata["ForcedSampleCount"], decoded_value.ForcedSampleCount, options); // base case
        ; ///< @todo Generate for ConservativeRaster[None]: D3D12_CONSERVATIVE_RASTERIZATION_MODE [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_BYTECODE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_BYTECODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_BYTECODE& meta_struct = *data;
        ; ///< @todo Generate for pShaderBytecode[BytecodeLength]: void [is_pointer] [is_array]
        FieldToJson(jdata["BytecodeLength"], decoded_value.BytecodeLength, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_STREAM_OUTPUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STREAM_OUTPUT_DESC& meta_struct = *data;
        ; ///< @todo Generate for pSODeclaration[NumEntries]: D3D12_SO_DECLARATION_ENTRY [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumEntries"], decoded_value.NumEntries, options); // base case
        ; ///< @todo Generate for pBufferStrides[NumStrides]: UINT [is_pointer] [is_array]
        FieldToJson(jdata["NumStrides"], decoded_value.NumStrides, options); // base case
        FieldToJson(jdata["RasterizedStream"], decoded_value.RasterizedStream, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_LAYOUT_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_INPUT_LAYOUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INPUT_LAYOUT_DESC& meta_struct = *data;
        ; ///< @todo Generate for pInputElementDescs[NumElements]: D3D12_INPUT_ELEMENT_DESC [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CACHED_PIPELINE_STATE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_CACHED_PIPELINE_STATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CACHED_PIPELINE_STATE& meta_struct = *data;
        ; ///< @todo Generate for pCachedBlob[CachedBlobSizeInBytes]: void [is_pointer] [is_array]
        FieldToJson(jdata["CachedBlobSizeInBytes"], decoded_value.CachedBlobSizeInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* data, const JsonOptions& options)
{
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
        FieldToJson(jdata["SampleMask"], decoded_value.SampleMask, options); // base case
        ; ///< @todo Generate for RasterizerState[None]: D3D12_RASTERIZER_DESC [is_struct]
        ; ///< @todo Generate for DepthStencilState[None]: D3D12_DEPTH_STENCIL_DESC [is_struct]
        ; ///< @todo Generate for InputLayout[None]: D3D12_INPUT_LAYOUT_DESC [is_struct]
        ; ///< @todo Generate for IBStripCutValue[None]: D3D12_INDEX_BUFFER_STRIP_CUT_VALUE [is_enum]
        ; ///< @todo Generate for PrimitiveTopologyType[None]: D3D12_PRIMITIVE_TOPOLOGY_TYPE [is_enum]
        FieldToJson(jdata["NumRenderTargets"], decoded_value.NumRenderTargets, options); // base case
        ; ///< @todo Generate for RTVFormats[8]: DXGI_FORMAT [is_array] [is_enum]
        ; ///< @todo Generate for DSVFormat[None]: DXGI_FORMAT [is_enum]
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // base case
        ; ///< @todo Generate for CachedPSO[None]: D3D12_CACHED_PIPELINE_STATE [is_struct]
        ; ///< @todo Generate for Flags[None]: D3D12_PIPELINE_STATE_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_COMPUTE_PIPELINE_STATE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC& meta_struct = *data;
        ; ///< @todo Generate for pRootSignature[None]: ID3D12RootSignature [is_pointer]
        ; ///< @todo Generate for CS[None]: D3D12_SHADER_BYTECODE [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // base case
        ; ///< @todo Generate for CachedPSO[None]: D3D12_CACHED_PIPELINE_STATE [is_struct]
        ; ///< @todo Generate for Flags[None]: D3D12_PIPELINE_STATE_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RT_FORMAT_ARRAY* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RT_FORMAT_ARRAY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RT_FORMAT_ARRAY& meta_struct = *data;
        ; ///< @todo Generate for RTFormats[8]: DXGI_FORMAT [is_array] [is_enum]
        FieldToJson(jdata["NumRenderTargets"], decoded_value.NumRenderTargets, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS& meta_struct = *data;
        FieldToJson(jdata["DoublePrecisionFloatShaderOps"], decoded_value.DoublePrecisionFloatShaderOps, options); // base case
        FieldToJson(jdata["OutputMergerLogicOp"], decoded_value.OutputMergerLogicOp, options); // base case
        ; ///< @todo Generate for MinPrecisionSupport[None]: D3D12_SHADER_MIN_PRECISION_SUPPORT [is_enum]
        ; ///< @todo Generate for TiledResourcesTier[None]: D3D12_TILED_RESOURCES_TIER [is_enum]
        ; ///< @todo Generate for ResourceBindingTier[None]: D3D12_RESOURCE_BINDING_TIER [is_enum]
        FieldToJson(jdata["PSSpecifiedStencilRefSupported"], decoded_value.PSSpecifiedStencilRefSupported, options); // base case
        FieldToJson(jdata["TypedUAVLoadAdditionalFormats"], decoded_value.TypedUAVLoadAdditionalFormats, options); // base case
        FieldToJson(jdata["ROVsSupported"], decoded_value.ROVsSupported, options); // base case
        ; ///< @todo Generate for ConservativeRasterizationTier[None]: D3D12_CONSERVATIVE_RASTERIZATION_TIER [is_enum]
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], decoded_value.MaxGPUVirtualAddressBitsPerResource, options); // base case
        FieldToJson(jdata["StandardSwizzle64KBSupported"], decoded_value.StandardSwizzle64KBSupported, options); // base case
        ; ///< @todo Generate for CrossNodeSharingTier[None]: D3D12_CROSS_NODE_SHARING_TIER [is_enum]
        FieldToJson(jdata["CrossAdapterRowMajorTextureSupported"], decoded_value.CrossAdapterRowMajorTextureSupported, options); // base case
        FieldToJson(jdata["VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation"], decoded_value.VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation, options); // base case
        ; ///< @todo Generate for ResourceHeapTier[None]: D3D12_RESOURCE_HEAP_TIER [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1& meta_struct = *data;
        FieldToJson(jdata["WaveOps"], decoded_value.WaveOps, options); // base case
        FieldToJson(jdata["WaveLaneCountMin"], decoded_value.WaveLaneCountMin, options); // base case
        FieldToJson(jdata["WaveLaneCountMax"], decoded_value.WaveLaneCountMax, options); // base case
        FieldToJson(jdata["TotalLaneCount"], decoded_value.TotalLaneCount, options); // base case
        FieldToJson(jdata["ExpandedComputeResourceStates"], decoded_value.ExpandedComputeResourceStates, options); // base case
        FieldToJson(jdata["Int64ShaderOps"], decoded_value.Int64ShaderOps, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2& meta_struct = *data;
        FieldToJson(jdata["DepthBoundsTestSupported"], decoded_value.DepthBoundsTestSupported, options); // base case
        ; ///< @todo Generate for ProgrammableSamplePositionsTier[None]: D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE& meta_struct = *data;
        ; ///< @todo Generate for HighestVersion[None]: D3D_ROOT_SIGNATURE_VERSION [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ARCHITECTURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // base case
        FieldToJson(jdata["TileBasedRenderer"], decoded_value.TileBasedRenderer, options); // base case
        FieldToJson(jdata["UMA"], decoded_value.UMA, options); // base case
        FieldToJson(jdata["CacheCoherentUMA"], decoded_value.CacheCoherentUMA, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ARCHITECTURE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // base case
        FieldToJson(jdata["TileBasedRenderer"], decoded_value.TileBasedRenderer, options); // base case
        FieldToJson(jdata["UMA"], decoded_value.UMA, options); // base case
        FieldToJson(jdata["CacheCoherentUMA"], decoded_value.CacheCoherentUMA, options); // base case
        FieldToJson(jdata["IsolatedMMU"], decoded_value.IsolatedMMU, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FEATURE_LEVELS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS& meta_struct = *data;
        FieldToJson(jdata["NumFeatureLevels"], decoded_value.NumFeatureLevels, options); // base case
        ; ///< @todo Generate for pFeatureLevelsRequested[NumFeatureLevels]: D3D_FEATURE_LEVEL [is_pointer] [is_array] [is_enum]
        ; ///< @todo Generate for MaxSupportedFeatureLevel[None]: D3D_FEATURE_LEVEL [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADER_MODEL& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL& meta_struct = *data;
        ; ///< @todo Generate for HighestShaderModel[None]: D3D_SHADER_MODEL [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FORMAT_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT& meta_struct = *data;
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        ; ///< @todo Generate for Support1[None]: D3D12_FORMAT_SUPPORT1 [is_enum]
        ; ///< @todo Generate for Support2[None]: D3D12_FORMAT_SUPPORT2 [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& meta_struct = *data;
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        FieldToJson(jdata["SampleCount"], decoded_value.SampleCount, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS [is_enum]
        FieldToJson(jdata["NumQualityLevels"], decoded_value.NumQualityLevels, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FORMAT_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO& meta_struct = *data;
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        FieldToJson(jdata["PlaneCount"], decoded_value.PlaneCount, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], decoded_value.MaxGPUVirtualAddressBitsPerResource, options); // base case
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerProcess"], decoded_value.MaxGPUVirtualAddressBitsPerProcess, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADER_CACHE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE& meta_struct = *data;
        ; ///< @todo Generate for SupportFlags[None]: D3D12_SHADER_CACHE_SUPPORT_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& meta_struct = *data;
        ; ///< @todo Generate for CommandListType[None]: D3D12_COMMAND_LIST_TYPE [is_enum]
        FieldToJson(jdata["Priority"], decoded_value.Priority, options); // base case
        FieldToJson(jdata["PriorityForTypeIsSupported"], decoded_value.PriorityForTypeIsSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS3& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3& meta_struct = *data;
        FieldToJson(jdata["CopyQueueTimestampQueriesSupported"], decoded_value.CopyQueueTimestampQueriesSupported, options); // base case
        FieldToJson(jdata["CastingFullyTypedFormatSupported"], decoded_value.CastingFullyTypedFormatSupported, options); // base case
        ; ///< @todo Generate for WriteBufferImmediateSupportFlags[None]: D3D12_COMMAND_LIST_SUPPORT_FLAGS [is_enum]
        ; ///< @todo Generate for ViewInstancingTier[None]: D3D12_VIEW_INSTANCING_TIER [is_enum]
        FieldToJson(jdata["BarycentricsSupported"], decoded_value.BarycentricsSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_EXISTING_HEAPS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS& meta_struct = *data;
        FieldToJson(jdata["Supported"], decoded_value.Supported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_DISPLAYABLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE& meta_struct = *data;
        FieldToJson(jdata["DisplayableTexture"], decoded_value.DisplayableTexture, options); // base case
        ; ///< @todo Generate for SharedResourceCompatibilityTier[None]: D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS4& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4& meta_struct = *data;
        FieldToJson(jdata["MSAA64KBAlignedTextureSupported"], decoded_value.MSAA64KBAlignedTextureSupported, options); // base case
        ; ///< @todo Generate for SharedResourceCompatibilityTier[None]: D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER [is_enum]
        FieldToJson(jdata["Native16BitShaderOpsSupported"], decoded_value.Native16BitShaderOpsSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SERIALIZATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SERIALIZATION& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // base case
        ; ///< @todo Generate for HeapSerializationTier[None]: D3D12_HEAP_SERIALIZATION_TIER [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_CROSS_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_CROSS_NODE& meta_struct = *data;
        ; ///< @todo Generate for SharingTier[None]: D3D12_CROSS_NODE_SHARING_TIER [is_enum]
        FieldToJson(jdata["AtomicShaderInstructions"], decoded_value.AtomicShaderInstructions, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS5& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5& meta_struct = *data;
        FieldToJson(jdata["SRVOnlyTiledResourceTier3"], decoded_value.SRVOnlyTiledResourceTier3, options); // base case
        ; ///< @todo Generate for RenderPassesTier[None]: D3D12_RENDER_PASS_TIER [is_enum]
        ; ///< @todo Generate for RaytracingTier[None]: D3D12_RAYTRACING_TIER [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS6& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6& meta_struct = *data;
        FieldToJson(jdata["AdditionalShadingRatesSupported"], decoded_value.AdditionalShadingRatesSupported, options); // base case
        FieldToJson(jdata["PerPrimitiveShadingRateSupportedWithViewportIndexing"], decoded_value.PerPrimitiveShadingRateSupportedWithViewportIndexing, options); // base case
        ; ///< @todo Generate for VariableShadingRateTier[None]: D3D12_VARIABLE_SHADING_RATE_TIER [is_enum]
        FieldToJson(jdata["ShadingRateImageTileSize"], decoded_value.ShadingRateImageTileSize, options); // base case
        FieldToJson(jdata["BackgroundProcessingSupported"], decoded_value.BackgroundProcessingSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS7& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7& meta_struct = *data;
        ; ///< @todo Generate for MeshShaderTier[None]: D3D12_MESH_SHADER_TIER [is_enum]
        ; ///< @todo Generate for SamplerFeedbackTier[None]: D3D12_SAMPLER_FEEDBACK_TIER [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_QUERY_META_COMMAND& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND& meta_struct = *data;
        ; ///< @todo Generate for CommandId[None]: GUID [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // base case
        ; ///< @todo Generate for pQueryInputData[QueryInputDataSizeInBytes]: void [is_pointer] [is_array]
        FieldToJson(jdata["QueryInputDataSizeInBytes"], decoded_value.QueryInputDataSizeInBytes, options); // base case
        ; ///< @todo Generate for pQueryOutputData[QueryOutputDataSizeInBytes]: void [is_pointer] [is_array]
        FieldToJson(jdata["QueryOutputDataSizeInBytes"], decoded_value.QueryOutputDataSizeInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS8& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8& meta_struct = *data;
        FieldToJson(jdata["UnalignedBlockTexturesSupported"], decoded_value.UnalignedBlockTexturesSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS9& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9& meta_struct = *data;
        FieldToJson(jdata["MeshShaderPipelineStatsSupported"], decoded_value.MeshShaderPipelineStatsSupported, options); // base case
        FieldToJson(jdata["MeshShaderSupportsFullRangeRenderTargetArrayIndex"], decoded_value.MeshShaderSupportsFullRangeRenderTargetArrayIndex, options); // base case
        FieldToJson(jdata["AtomicInt64OnTypedResourceSupported"], decoded_value.AtomicInt64OnTypedResourceSupported, options); // base case
        FieldToJson(jdata["AtomicInt64OnGroupSharedSupported"], decoded_value.AtomicInt64OnGroupSharedSupported, options); // base case
        FieldToJson(jdata["DerivativesInMeshAndAmplificationShadersSupported"], decoded_value.DerivativesInMeshAndAmplificationShadersSupported, options); // base case
        ; ///< @todo Generate for WaveMMATier[None]: D3D12_WAVE_MMA_TIER [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS10& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10& meta_struct = *data;
        FieldToJson(jdata["VariableRateShadingSumCombinerSupported"], decoded_value.VariableRateShadingSumCombinerSupported, options); // base case
        FieldToJson(jdata["MeshShaderPerPrimitiveShadingRateSupported"], decoded_value.MeshShaderPerPrimitiveShadingRateSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS11& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11& meta_struct = *data;
        FieldToJson(jdata["AtomicInt64OnDescriptorHeapResourceSupported"], decoded_value.AtomicInt64OnDescriptorHeapResourceSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS12& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12& meta_struct = *data;
        ; ///< @todo Generate for MSPrimitivesPipelineStatisticIncludesCulledPrimitives[None]: D3D12_TRI_STATE [is_enum]
        FieldToJson(jdata["EnhancedBarriersSupported"], decoded_value.EnhancedBarriersSupported, options); // base case
        FieldToJson(jdata["RelaxedFormatCastingSupported"], decoded_value.RelaxedFormatCastingSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS13& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13& meta_struct = *data;
        FieldToJson(jdata["UnrestrictedBufferTextureCopyPitchSupported"], decoded_value.UnrestrictedBufferTextureCopyPitchSupported, options); // base case
        FieldToJson(jdata["UnrestrictedVertexElementAlignmentSupported"], decoded_value.UnrestrictedVertexElementAlignmentSupported, options); // base case
        FieldToJson(jdata["InvertedViewportHeightFlipsYSupported"], decoded_value.InvertedViewportHeightFlipsYSupported, options); // base case
        FieldToJson(jdata["InvertedViewportDepthFlipsZSupported"], decoded_value.InvertedViewportDepthFlipsZSupported, options); // base case
        FieldToJson(jdata["TextureCopyBetweenDimensionsSupported"], decoded_value.TextureCopyBetweenDimensionsSupported, options); // base case
        FieldToJson(jdata["AlphaBlendFactorSupported"], decoded_value.AlphaBlendFactorSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS14& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14& meta_struct = *data;
        FieldToJson(jdata["AdvancedTextureOpsSupported"], decoded_value.AdvancedTextureOpsSupported, options); // base case
        FieldToJson(jdata["WriteableMSAATexturesSupported"], decoded_value.WriteableMSAATexturesSupported, options); // base case
        FieldToJson(jdata["IndependentFrontAndBackStencilRefMaskSupported"], decoded_value.IndependentFrontAndBackStencilRefMaskSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS15& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15& meta_struct = *data;
        FieldToJson(jdata["TriangleFanSupported"], decoded_value.TriangleFanSupported, options); // base case
        FieldToJson(jdata["DynamicIndexBufferStripCutSupported"], decoded_value.DynamicIndexBufferStripCutSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS16& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16& meta_struct = *data;
        FieldToJson(jdata["DynamicDepthBiasSupported"], decoded_value.DynamicDepthBiasSupported, options); // base case
        FieldToJson(jdata["GPUUploadHeapSupported"], decoded_value.GPUUploadHeapSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS17& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17& meta_struct = *data;
        FieldToJson(jdata["NonNormalizedCoordinateSamplersSupported"], decoded_value.NonNormalizedCoordinateSamplersSupported, options); // base case
        FieldToJson(jdata["ManualWriteTrackingResourceSupported"], decoded_value.ManualWriteTrackingResourceSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS18& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18& meta_struct = *data;
        FieldToJson(jdata["RenderPassesValid"], decoded_value.RenderPassesValid, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS19& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19& meta_struct = *data;
        FieldToJson(jdata["MismatchingOutputDimensionsSupported"], decoded_value.MismatchingOutputDimensionsSupported, options); // base case
        FieldToJson(jdata["SupportedSampleCountsWithNoOutputs"], decoded_value.SupportedSampleCountsWithNoOutputs, options); // base case
        FieldToJson(jdata["PointSamplingAddressesNeverRoundUp"], decoded_value.PointSamplingAddressesNeverRoundUp, options); // base case
        FieldToJson(jdata["RasterizerDesc2Supported"], decoded_value.RasterizerDesc2Supported, options); // base case
        FieldToJson(jdata["NarrowQuadrilateralLinesSupported"], decoded_value.NarrowQuadrilateralLinesSupported, options); // base case
        FieldToJson(jdata["AnisoFilterWithPointMipSupported"], decoded_value.AnisoFilterWithPointMipSupported, options); // base case
        FieldToJson(jdata["MaxSamplerDescriptorHeapSize"], decoded_value.MaxSamplerDescriptorHeapSize, options); // base case
        FieldToJson(jdata["MaxSamplerDescriptorHeapSizeWithStaticSamplers"], decoded_value.MaxSamplerDescriptorHeapSizeWithStaticSamplers, options); // base case
        FieldToJson(jdata["MaxViewDescriptorHeapSize"], decoded_value.MaxViewDescriptorHeapSize, options); // base case
        FieldToJson(jdata["ComputeOnlyCustomHeapSupported"], decoded_value.ComputeOnlyCustomHeapSupported, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALLOCATION_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALLOCATION_INFO& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // base case
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALLOCATION_INFO1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); // base case
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); // base case
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_HEAP_PROPERTIES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HEAP_PROPERTIES& meta_struct = *data;
        ; ///< @todo Generate for Type[None]: D3D12_HEAP_TYPE [is_enum]
        ; ///< @todo Generate for CPUPageProperty[None]: D3D12_CPU_PAGE_PROPERTY [is_enum]
        ; ///< @todo Generate for MemoryPoolPreference[None]: D3D12_MEMORY_POOL [is_enum]
        FieldToJson(jdata["CreationNodeMask"], decoded_value.CreationNodeMask, options); // base case
        FieldToJson(jdata["VisibleNodeMask"], decoded_value.VisibleNodeMask, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HEAP_DESC& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // base case
        ; ///< @todo Generate for Properties[None]: D3D12_HEAP_PROPERTIES [is_struct]
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_HEAP_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MIP_REGION* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_MIP_REGION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MIP_REGION& meta_struct = *data;
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_DESC& meta_struct = *data;
        ; ///< @todo Generate for Dimension[None]: D3D12_RESOURCE_DIMENSION [is_enum]
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); // base case
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        FieldToJson(jdata["DepthOrArraySize"], decoded_value.DepthOrArraySize, options); // base case
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // base case
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        ; ///< @todo Generate for Layout[None]: D3D12_TEXTURE_LAYOUT [is_enum]
        ; ///< @todo Generate for Flags[None]: D3D12_RESOURCE_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_DESC1& meta_struct = *data;
        ; ///< @todo Generate for Dimension[None]: D3D12_RESOURCE_DIMENSION [is_enum]
        FieldToJson(jdata["Alignment"], decoded_value.Alignment, options); // base case
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        FieldToJson(jdata["DepthOrArraySize"], decoded_value.DepthOrArraySize, options); // base case
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // base case
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC [is_struct]
        ; ///< @todo Generate for Layout[None]: D3D12_TEXTURE_LAYOUT [is_enum]
        ; ///< @todo Generate for Flags[None]: D3D12_RESOURCE_FLAGS [is_enum]
        ; ///< @todo Generate for SamplerFeedbackMipRegion[None]: D3D12_MIP_REGION [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VALUE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_VALUE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_VALUE& meta_struct = *data;
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); // base case
        FieldToJson(jdata["Stencil"], decoded_value.Stencil, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RANGE& meta_struct = *data;
        FieldToJson(jdata["Begin"], decoded_value.Begin, options); // base case
        FieldToJson(jdata["End"], decoded_value.End, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE_UINT64* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RANGE_UINT64& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RANGE_UINT64& meta_struct = *data;
        FieldToJson(jdata["Begin"], decoded_value.Begin, options); // base case
        FieldToJson(jdata["End"], decoded_value.End, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_RANGE_UINT64& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64& meta_struct = *data;
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options); // base case
        ; ///< @todo Generate for Range[None]: D3D12_RANGE_UINT64 [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_INFO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_INFO& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); // base case
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); // base case
        FieldToJson(jdata["DepthPitch"], decoded_value.DepthPitch, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILED_RESOURCE_COORDINATE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TILED_RESOURCE_COORDINATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILED_RESOURCE_COORDINATE& meta_struct = *data;
        FieldToJson(jdata["X"], decoded_value.X, options); // base case
        FieldToJson(jdata["Y"], decoded_value.Y, options); // base case
        FieldToJson(jdata["Z"], decoded_value.Z, options); // base case
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_REGION_SIZE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TILE_REGION_SIZE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILE_REGION_SIZE& meta_struct = *data;
        FieldToJson(jdata["NumTiles"], decoded_value.NumTiles, options); // base case
        FieldToJson(jdata["UseBox"], decoded_value.UseBox, options); // base case
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_TILING* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_TILING& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_TILING& meta_struct = *data;
        FieldToJson(jdata["WidthInTiles"], decoded_value.WidthInTiles, options); // base case
        FieldToJson(jdata["HeightInTiles"], decoded_value.HeightInTiles, options); // base case
        FieldToJson(jdata["DepthInTiles"], decoded_value.DepthInTiles, options); // base case
        FieldToJson(jdata["StartTileIndexInOverallResource"], decoded_value.StartTileIndexInOverallResource, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_SHAPE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TILE_SHAPE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILE_SHAPE& meta_struct = *data;
        FieldToJson(jdata["WidthInTexels"], decoded_value.WidthInTexels, options); // base case
        FieldToJson(jdata["HeightInTexels"], decoded_value.HeightInTexels, options); // base case
        FieldToJson(jdata["DepthInTexels"], decoded_value.DepthInTexels, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PACKED_MIP_INFO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_PACKED_MIP_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PACKED_MIP_INFO& meta_struct = *data;
        FieldToJson(jdata["NumStandardMips"], decoded_value.NumStandardMips, options); // base case
        FieldToJson(jdata["NumPackedMips"], decoded_value.NumPackedMips, options); // base case
        FieldToJson(jdata["NumTilesForPackedMips"], decoded_value.NumTilesForPackedMips, options); // base case
        FieldToJson(jdata["StartTileIndexInOverallResource"], decoded_value.StartTileIndexInOverallResource, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_TRANSITION_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER& meta_struct = *data;
        ; ///< @todo Generate for pResource[None]: ID3D12Resource [is_pointer]
        FieldToJson(jdata["Subresource"], decoded_value.Subresource, options); // base case
        ; ///< @todo Generate for StateBefore[None]: D3D12_RESOURCE_STATES [is_enum]
        ; ///< @todo Generate for StateAfter[None]: D3D12_RESOURCE_STATES [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALIASING_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALIASING_BARRIER& meta_struct = *data;
        ; ///< @todo Generate for pResourceBefore[None]: ID3D12Resource [is_pointer]
        ; ///< @todo Generate for pResourceAfter[None]: ID3D12Resource [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_UAV_BARRIER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_UAV_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_UAV_BARRIER& meta_struct = *data;
        ; ///< @todo Generate for pResource[None]: ID3D12Resource [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_FOOTPRINT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_FOOTPRINT& meta_struct = *data;
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); // base case
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT& meta_struct = *data;
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); // base case
        ; ///< @todo Generate for Footprint[None]: D3D12_SUBRESOURCE_FOOTPRINT [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_POSITION* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLE_POSITION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLE_POSITION& meta_struct = *data;
        FieldToJson(jdata["X"], decoded_value.X, options); // base case
        FieldToJson(jdata["Y"], decoded_value.Y, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCE_LOCATION* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_VIEW_INSTANCE_LOCATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEW_INSTANCE_LOCATION& meta_struct = *data;
        FieldToJson(jdata["ViewportArrayIndex"], decoded_value.ViewportArrayIndex, options); // base case
        FieldToJson(jdata["RenderTargetArrayIndex"], decoded_value.RenderTargetArrayIndex, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCING_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_VIEW_INSTANCING_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEW_INSTANCING_DESC& meta_struct = *data;
        FieldToJson(jdata["ViewInstanceCount"], decoded_value.ViewInstanceCount, options); // base case
        ; ///< @todo Generate for pViewInstanceLocations[ViewInstanceCount]: D3D12_VIEW_INSTANCE_LOCATION [is_pointer] [is_array] [is_struct]
        ; ///< @todo Generate for Flags[None]: D3D12_VIEW_INSTANCING_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_SRV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options); // base case
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); // base case
        FieldToJson(jdata["StructureByteStride"], decoded_value.StructureByteStride, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_BUFFER_SRV_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // base case
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // base case
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // base case
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // base case
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // base case
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // base case
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // base case
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // base case
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // base case
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // base case
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // base case
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // base case
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEXCUBE_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXCUBE_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // base case
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // base case
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_ARRAY_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEXCUBE_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXCUBE_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["MostDetailedMip"], decoded_value.MostDetailedMip, options); // base case
        FieldToJson(jdata["MipLevels"], decoded_value.MipLevels, options); // base case
        FieldToJson(jdata["First2DArrayFace"], decoded_value.First2DArrayFace, options); // base case
        FieldToJson(jdata["NumCubes"], decoded_value.NumCubes, options); // base case
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_SRV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_SRV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& meta_struct = *data;
        FieldToJson(jdata["Location"], decoded_value.Location, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_CONSTANT_BUFFER_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); // base case
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLER_DESC& meta_struct = *data;
        ; ///< @todo Generate for Filter[None]: D3D12_FILTER [is_enum]
        ; ///< @todo Generate for AddressU[None]: D3D12_TEXTURE_ADDRESS_MODE [is_enum]
        ; ///< @todo Generate for AddressV[None]: D3D12_TEXTURE_ADDRESS_MODE [is_enum]
        ; ///< @todo Generate for AddressW[None]: D3D12_TEXTURE_ADDRESS_MODE [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); // base case
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); // base case
        ; ///< @todo Generate for ComparisonFunc[None]: D3D12_COMPARISON_FUNC [is_enum]
        ; ///< @todo Generate for BorderColor[4]: FLOAT [is_array]
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); // base case
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_UAV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_UAV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options); // base case
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); // base case
        FieldToJson(jdata["StructureByteStride"], decoded_value.StructureByteStride, options); // base case
        FieldToJson(jdata["CounterOffsetInBytes"], decoded_value.CounterOffsetInBytes, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_BUFFER_UAV_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_UAV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_UAV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_UAV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_UAV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_UAV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_UAV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_UAV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_UAV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_UAV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_UAV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        FieldToJson(jdata["FirstWSlice"], decoded_value.FirstWSlice, options); // base case
        FieldToJson(jdata["WSize"], decoded_value.WSize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_RTV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_RTV& meta_struct = *data;
        FieldToJson(jdata["FirstElement"], decoded_value.FirstElement, options); // base case
        FieldToJson(jdata["NumElements"], decoded_value.NumElements, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_RTV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_RTV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_RTV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_RTV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_RTV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_RTV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        FieldToJson(jdata["PlaneSlice"], decoded_value.PlaneSlice, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_RTV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_RTV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_RTV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_RTV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        FieldToJson(jdata["FirstWSlice"], decoded_value.FirstWSlice, options); // base case
        FieldToJson(jdata["WSize"], decoded_value.WSize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_DSV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_DSV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_DSV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_DSV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["MipSlice"], decoded_value.MipSlice, options); // base case
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_DSV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_DSV& meta_struct = *data;
        FieldToJson(jdata["UnusedField_NothingToDefine"], decoded_value.UnusedField_NothingToDefine, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_DSV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_DSV& meta_struct = *data;
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["ArraySize"], decoded_value.ArraySize, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_HEAP_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_HEAP_DESC& meta_struct = *data;
        ; ///< @todo Generate for Type[None]: D3D12_DESCRIPTOR_HEAP_TYPE [is_enum]
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_DESCRIPTOR_HEAP_FLAGS [is_enum]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_RANGE& meta_struct = *data;
        ; ///< @todo Generate for RangeType[None]: D3D12_DESCRIPTOR_RANGE_TYPE [is_enum]
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options); // base case
        FieldToJson(jdata["BaseShaderRegister"], decoded_value.BaseShaderRegister, options); // base case
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // base case
        FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], decoded_value.OffsetInDescriptorsFromTableStart, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR_TABLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE& meta_struct = *data;
        FieldToJson(jdata["NumDescriptorRanges"], decoded_value.NumDescriptorRanges, options); // base case
        ; ///< @todo Generate for pDescriptorRanges[NumDescriptorRanges]: D3D12_DESCRIPTOR_RANGE [is_pointer] [is_array] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_CONSTANTS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_CONSTANTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_CONSTANTS& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); // base case
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // base case
        FieldToJson(jdata["Num32BitValues"], decoded_value.Num32BitValues, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); // base case
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_STATIC_SAMPLER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATIC_SAMPLER_DESC& meta_struct = *data;
        ; ///< @todo Generate for Filter[None]: D3D12_FILTER [is_enum]
        ; ///< @todo Generate for AddressU[None]: D3D12_TEXTURE_ADDRESS_MODE [is_enum]
        ; ///< @todo Generate for AddressV[None]: D3D12_TEXTURE_ADDRESS_MODE [is_enum]
        ; ///< @todo Generate for AddressW[None]: D3D12_TEXTURE_ADDRESS_MODE [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); // base case
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); // base case
        ; ///< @todo Generate for ComparisonFunc[None]: D3D12_COMPARISON_FUNC [is_enum]
        ; ///< @todo Generate for BorderColor[None]: D3D12_STATIC_BORDER_COLOR [is_enum]
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); // base case
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); // base case
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); // base case
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // base case
        ; ///< @todo Generate for ShaderVisibility[None]: D3D12_SHADER_VISIBILITY [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_STATIC_SAMPLER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATIC_SAMPLER_DESC1& meta_struct = *data;
        ; ///< @todo Generate for Filter[None]: D3D12_FILTER [is_enum]
        ; ///< @todo Generate for AddressU[None]: D3D12_TEXTURE_ADDRESS_MODE [is_enum]
        ; ///< @todo Generate for AddressV[None]: D3D12_TEXTURE_ADDRESS_MODE [is_enum]
        ; ///< @todo Generate for AddressW[None]: D3D12_TEXTURE_ADDRESS_MODE [is_enum]
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias, options); // base case
        FieldToJson(jdata["MaxAnisotropy"], decoded_value.MaxAnisotropy, options); // base case
        ; ///< @todo Generate for ComparisonFunc[None]: D3D12_COMPARISON_FUNC [is_enum]
        ; ///< @todo Generate for BorderColor[None]: D3D12_STATIC_BORDER_COLOR [is_enum]
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD, options); // base case
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD, options); // base case
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); // base case
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // base case
        ; ///< @todo Generate for ShaderVisibility[None]: D3D12_SHADER_VISIBILITY [is_enum]
        ; ///< @todo Generate for Flags[None]: D3D12_SAMPLER_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options); // base case
        ; ///< @todo Generate for pParameters[NumParameters]: D3D12_ROOT_PARAMETER [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options); // base case
        ; ///< @todo Generate for pStaticSamplers[NumStaticSamplers]: D3D12_STATIC_SAMPLER_DESC [is_pointer] [is_array] [is_struct]
        ; ///< @todo Generate for Flags[None]: D3D12_ROOT_SIGNATURE_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_RANGE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_RANGE1& meta_struct = *data;
        ; ///< @todo Generate for RangeType[None]: D3D12_DESCRIPTOR_RANGE_TYPE [is_enum]
        FieldToJson(jdata["NumDescriptors"], decoded_value.NumDescriptors, options); // base case
        FieldToJson(jdata["BaseShaderRegister"], decoded_value.BaseShaderRegister, options); // base case
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_DESCRIPTOR_RANGE_FLAGS [is_enum]
        FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], decoded_value.OffsetInDescriptorsFromTableStart, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR_TABLE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1& meta_struct = *data;
        FieldToJson(jdata["NumDescriptorRanges"], decoded_value.NumDescriptorRanges, options); // base case
        ; ///< @todo Generate for pDescriptorRanges[NumDescriptorRanges]: D3D12_DESCRIPTOR_RANGE1 [is_pointer] [is_array] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR1& meta_struct = *data;
        FieldToJson(jdata["ShaderRegister"], decoded_value.ShaderRegister, options); // base case
        FieldToJson(jdata["RegisterSpace"], decoded_value.RegisterSpace, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_ROOT_DESCRIPTOR_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC1& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options); // base case
        ; ///< @todo Generate for pParameters[NumParameters]: D3D12_ROOT_PARAMETER1 [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options); // base case
        ; ///< @todo Generate for pStaticSamplers[NumStaticSamplers]: D3D12_STATIC_SAMPLER_DESC [is_pointer] [is_array] [is_struct]
        ; ///< @todo Generate for Flags[None]: D3D12_ROOT_SIGNATURE_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC2& meta_struct = *data;
        FieldToJson(jdata["NumParameters"], decoded_value.NumParameters, options); // base case
        ; ///< @todo Generate for pParameters[NumParameters]: D3D12_ROOT_PARAMETER1 [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NumStaticSamplers"], decoded_value.NumStaticSamplers, options); // base case
        ; ///< @todo Generate for pStaticSamplers[NumStaticSamplers]: D3D12_STATIC_SAMPLER_DESC1 [is_pointer] [is_array] [is_struct]
        ; ///< @todo Generate for Flags[None]: D3D12_ROOT_SIGNATURE_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISCARD_REGION* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DISCARD_REGION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISCARD_REGION& meta_struct = *data;
        FieldToJson(jdata["NumRects"], decoded_value.NumRects, options); // base case
        ; ///< @todo Generate for pRects[NumRects]: tagRECT [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["FirstSubresource"], decoded_value.FirstSubresource, options); // base case
        FieldToJson(jdata["NumSubresources"], decoded_value.NumSubresources, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_HEAP_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_HEAP_DESC& meta_struct = *data;
        ; ///< @todo Generate for Type[None]: D3D12_QUERY_HEAP_TYPE [is_enum]
        FieldToJson(jdata["Count"], decoded_value.Count, options); // base case
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_PIPELINE_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["IAVertices"], decoded_value.IAVertices, options); // base case
        FieldToJson(jdata["IAPrimitives"], decoded_value.IAPrimitives, options); // base case
        FieldToJson(jdata["VSInvocations"], decoded_value.VSInvocations, options); // base case
        FieldToJson(jdata["GSInvocations"], decoded_value.GSInvocations, options); // base case
        FieldToJson(jdata["GSPrimitives"], decoded_value.GSPrimitives, options); // base case
        FieldToJson(jdata["CInvocations"], decoded_value.CInvocations, options); // base case
        FieldToJson(jdata["CPrimitives"], decoded_value.CPrimitives, options); // base case
        FieldToJson(jdata["PSInvocations"], decoded_value.PSInvocations, options); // base case
        FieldToJson(jdata["HSInvocations"], decoded_value.HSInvocations, options); // base case
        FieldToJson(jdata["DSInvocations"], decoded_value.DSInvocations, options); // base case
        FieldToJson(jdata["CSInvocations"], decoded_value.CSInvocations, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1& meta_struct = *data;
        FieldToJson(jdata["IAVertices"], decoded_value.IAVertices, options); // base case
        FieldToJson(jdata["IAPrimitives"], decoded_value.IAPrimitives, options); // base case
        FieldToJson(jdata["VSInvocations"], decoded_value.VSInvocations, options); // base case
        FieldToJson(jdata["GSInvocations"], decoded_value.GSInvocations, options); // base case
        FieldToJson(jdata["GSPrimitives"], decoded_value.GSPrimitives, options); // base case
        FieldToJson(jdata["CInvocations"], decoded_value.CInvocations, options); // base case
        FieldToJson(jdata["CPrimitives"], decoded_value.CPrimitives, options); // base case
        FieldToJson(jdata["PSInvocations"], decoded_value.PSInvocations, options); // base case
        FieldToJson(jdata["HSInvocations"], decoded_value.HSInvocations, options); // base case
        FieldToJson(jdata["DSInvocations"], decoded_value.DSInvocations, options); // base case
        FieldToJson(jdata["CSInvocations"], decoded_value.CSInvocations, options); // base case
        FieldToJson(jdata["ASInvocations"], decoded_value.ASInvocations, options); // base case
        FieldToJson(jdata["MSInvocations"], decoded_value.MSInvocations, options); // base case
        FieldToJson(jdata["MSPrimitives"], decoded_value.MSPrimitives, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_SO_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_SO_STATISTICS& meta_struct = *data;
        FieldToJson(jdata["NumPrimitivesWritten"], decoded_value.NumPrimitivesWritten, options); // base case
        FieldToJson(jdata["PrimitivesStorageNeeded"], decoded_value.PrimitivesStorageNeeded, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_STREAM_OUTPUT_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); // base case
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // base case
        FieldToJson(jdata["BufferFilledSizeLocation"], decoded_value.BufferFilledSizeLocation, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_ARGUMENTS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DRAW_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRAW_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["VertexCountPerInstance"], decoded_value.VertexCountPerInstance, options); // base case
        FieldToJson(jdata["InstanceCount"], decoded_value.InstanceCount, options); // base case
        FieldToJson(jdata["StartVertexLocation"], decoded_value.StartVertexLocation, options); // base case
        FieldToJson(jdata["StartInstanceLocation"], decoded_value.StartInstanceLocation, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DRAW_INDEXED_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["IndexCountPerInstance"], decoded_value.IndexCountPerInstance, options); // base case
        FieldToJson(jdata["InstanceCount"], decoded_value.InstanceCount, options); // base case
        FieldToJson(jdata["StartIndexLocation"], decoded_value.StartIndexLocation, options); // base case
        FieldToJson(jdata["BaseVertexLocation"], decoded_value.BaseVertexLocation, options); // base case
        FieldToJson(jdata["StartInstanceLocation"], decoded_value.StartInstanceLocation, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_ARGUMENTS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["ThreadGroupCountX"], decoded_value.ThreadGroupCountX, options); // base case
        FieldToJson(jdata["ThreadGroupCountY"], decoded_value.ThreadGroupCountY, options); // base case
        FieldToJson(jdata["ThreadGroupCountZ"], decoded_value.ThreadGroupCountZ, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERTEX_BUFFER_VIEW* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_VERTEX_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERTEX_BUFFER_VIEW& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); // base case
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // base case
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDEX_BUFFER_VIEW* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_INDEX_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INDEX_BUFFER_VIEW& meta_struct = *data;
        FieldToJson(jdata["BufferLocation"], decoded_value.BufferLocation, options); // base case
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // base case
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_SIGNATURE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_COMMAND_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMMAND_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["ByteStride"], decoded_value.ByteStride, options); // base case
        FieldToJson(jdata["NumArgumentDescs"], decoded_value.NumArgumentDescs, options); // base case
        ; ///< @todo Generate for pArgumentDescs[NumArgumentDescs]: D3D12_INDIRECT_ARGUMENT_DESC [is_pointer] [is_array] [is_struct]
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& meta_struct = *data;
        FieldToJson(jdata["Dest"], decoded_value.Dest, options); // base case
        FieldToJson(jdata["Value"], decoded_value.Value, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // base case
        ; ///< @todo Generate for Support[None]: D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC& meta_struct = *data;
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_PROTECTED_RESOURCE_SESSION_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_META_COMMAND_PARAMETER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_META_COMMAND_PARAMETER_DESC& meta_struct = *data;
        ; ///< @todo Generate for Name[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for Type[None]: D3D12_META_COMMAND_PARAMETER_TYPE [is_enum]
        ; ///< @todo Generate for Flags[None]: D3D12_META_COMMAND_PARAMETER_FLAGS [is_enum]
        ; ///< @todo Generate for RequiredResourceState[None]: D3D12_RESOURCE_STATES [is_enum]
        FieldToJson(jdata["StructureOffset"], decoded_value.StructureOffset, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_META_COMMAND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_META_COMMAND_DESC& meta_struct = *data;
        ; ///< @todo Generate for Id[None]: GUID [is_struct]
        ; ///< @todo Generate for Name[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for InitializationDirtyState[None]: D3D12_GRAPHICS_STATES [is_enum]
        ; ///< @todo Generate for ExecutionDirtyState[None]: D3D12_GRAPHICS_STATES [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_STATE_OBJECT_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_OBJECT_CONFIG& meta_struct = *data;
        ; ///< @todo Generate for Flags[None]: D3D12_STATE_OBJECT_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE& meta_struct = *data;
        ; ///< @todo Generate for pGlobalRootSignature[None]: ID3D12RootSignature [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_LOCAL_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_LOCAL_ROOT_SIGNATURE& meta_struct = *data;
        ; ///< @todo Generate for pLocalRootSignature[None]: ID3D12RootSignature [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_NODE_MASK& decoded_value = *data->decoded_value;
        const Decoded_D3D12_NODE_MASK& meta_struct = *data;
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_EXPORT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXPORT_DESC& meta_struct = *data;
        ; ///< @todo Generate for Name[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for ExportToRename[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for Flags[None]: D3D12_EXPORT_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DXIL_LIBRARY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DXIL_LIBRARY_DESC& meta_struct = *data;
        ; ///< @todo Generate for DXILLibrary[None]: D3D12_SHADER_BYTECODE [is_struct]
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options); // base case
        ; ///< @todo Generate for pExports[NumExports]: D3D12_EXPORT_DESC [is_pointer] [is_array] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_EXISTING_COLLECTION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXISTING_COLLECTION_DESC& meta_struct = *data;
        ; ///< @todo Generate for pExistingCollection[None]: ID3D12StateObject [is_pointer]
        FieldToJson(jdata["NumExports"], decoded_value.NumExports, options); // base case
        ; ///< @todo Generate for pExports[NumExports]: D3D12_EXPORT_DESC [is_pointer] [is_array] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_HIT_GROUP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HIT_GROUP_DESC& meta_struct = *data;
        ; ///< @todo Generate for HitGroupExport[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for Type[None]: D3D12_HIT_GROUP_TYPE [is_enum]
        ; ///< @todo Generate for AnyHitShaderImport[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for ClosestHitShaderImport[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for IntersectionShaderImport[None]: wchar_t [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_SHADER_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_SHADER_CONFIG& meta_struct = *data;
        FieldToJson(jdata["MaxPayloadSizeInBytes"], decoded_value.MaxPayloadSizeInBytes, options); // base case
        FieldToJson(jdata["MaxAttributeSizeInBytes"], decoded_value.MaxAttributeSizeInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_PIPELINE_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG& meta_struct = *data;
        FieldToJson(jdata["MaxTraceRecursionDepth"], decoded_value.MaxTraceRecursionDepth, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_PIPELINE_CONFIG1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1& meta_struct = *data;
        FieldToJson(jdata["MaxTraceRecursionDepth"], decoded_value.MaxTraceRecursionDepth, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_RAYTRACING_PIPELINE_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& meta_struct = *data;
        FieldToJson(jdata["StartAddress"], decoded_value.StartAddress, options); // base case
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE& meta_struct = *data;
        FieldToJson(jdata["StartAddress"], decoded_value.StartAddress, options); // base case
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& meta_struct = *data;
        FieldToJson(jdata["StartAddress"], decoded_value.StartAddress, options); // base case
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // base case
        FieldToJson(jdata["StrideInBytes"], decoded_value.StrideInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& meta_struct = *data;
        FieldToJson(jdata["Transform3x4"], decoded_value.Transform3x4, options); // base case
        ; ///< @todo Generate for IndexFormat[None]: DXGI_FORMAT [is_enum]
        ; ///< @todo Generate for VertexFormat[None]: DXGI_FORMAT [is_enum]
        FieldToJson(jdata["IndexCount"], decoded_value.IndexCount, options); // base case
        FieldToJson(jdata["VertexCount"], decoded_value.VertexCount, options); // base case
        FieldToJson(jdata["IndexBuffer"], decoded_value.IndexBuffer, options); // base case
        ; ///< @todo Generate for VertexBuffer[None]: D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_AABB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_AABB& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_AABB& meta_struct = *data;
        FieldToJson(jdata["MinX"], decoded_value.MinX, options); // base case
        FieldToJson(jdata["MinY"], decoded_value.MinY, options); // base case
        FieldToJson(jdata["MinZ"], decoded_value.MinZ, options); // base case
        FieldToJson(jdata["MaxX"], decoded_value.MaxX, options); // base case
        FieldToJson(jdata["MaxY"], decoded_value.MaxY, options); // base case
        FieldToJson(jdata["MaxZ"], decoded_value.MaxZ, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& meta_struct = *data;
        FieldToJson(jdata["AABBCount"], decoded_value.AABBCount, options); // base case
        ; ///< @todo Generate for AABBs[None]: D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& meta_struct = *data;
        FieldToJson(jdata["DestBuffer"], decoded_value.DestBuffer, options); // base case
        ; ///< @todo Generate for InfoType[None]: D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& meta_struct = *data;
        FieldToJson(jdata["CompactedSizeInBytes"], decoded_value.CompactedSizeInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& meta_struct = *data;
        FieldToJson(jdata["DecodedSizeInBytes"], decoded_value.DecodedSizeInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& meta_struct = *data;
        ; ///< @todo Generate for Type[None]: D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE [is_enum]
        FieldToJson(jdata["NumDescs"], decoded_value.NumDescs, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& meta_struct = *data;
        FieldToJson(jdata["SerializedSizeInBytes"], decoded_value.SerializedSizeInBytes, options); // base case
        FieldToJson(jdata["NumBottomLevelAccelerationStructurePointers"], decoded_value.NumBottomLevelAccelerationStructurePointers, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& meta_struct = *data;
        ; ///< @todo Generate for DriverOpaqueGUID[None]: GUID [is_struct]
        ; ///< @todo Generate for DriverOpaqueVersioningData[16]: BYTE [is_array]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& meta_struct = *data;
        ; ///< @todo Generate for DriverMatchingIdentifier[None]: D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER [is_struct]
        FieldToJson(jdata["SerializedSizeInBytesIncludingHeader"], decoded_value.SerializedSizeInBytesIncludingHeader, options); // base case
        FieldToJson(jdata["DeserializedSizeInBytes"], decoded_value.DeserializedSizeInBytes, options); // base case
        FieldToJson(jdata["NumBottomLevelAccelerationStructurePointersAfterHeader"], decoded_value.NumBottomLevelAccelerationStructurePointersAfterHeader, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& meta_struct = *data;
        FieldToJson(jdata["CurrentSizeInBytes"], decoded_value.CurrentSizeInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& meta_struct = *data;
        FieldToJson(jdata["DestAccelerationStructureData"], decoded_value.DestAccelerationStructureData, options); // base case
        ; ///< @todo Generate for Inputs[None]: D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS [is_struct]
        FieldToJson(jdata["SourceAccelerationStructureData"], decoded_value.SourceAccelerationStructureData, options); // base case
        FieldToJson(jdata["ScratchAccelerationStructureData"], decoded_value.ScratchAccelerationStructureData, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& meta_struct = *data;
        FieldToJson(jdata["ResultDataMaxSizeInBytes"], decoded_value.ResultDataMaxSizeInBytes, options); // base case
        FieldToJson(jdata["ScratchDataSizeInBytes"], decoded_value.ScratchDataSizeInBytes, options); // base case
        FieldToJson(jdata["UpdateScratchDataSizeInBytes"], decoded_value.UpdateScratchDataSizeInBytes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE* data, const JsonOptions& options)
{
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
        FieldToJson(jdata["BreadcrumbCount"], decoded_value.BreadcrumbCount, options); // base case
        ; ///< @todo Generate for pLastBreadcrumbValue[None]: UINT32 [is_pointer]
        ; ///< @todo Generate for pCommandHistory[BreadcrumbCount]: D3D12_AUTO_BREADCRUMB_OP [is_pointer] [is_array] [is_enum]
        ; ///< @todo Generate for pNext[None]: D3D12_AUTO_BREADCRUMB_NODE [is_pointer] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DRED_BREADCRUMB_CONTEXT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT& meta_struct = *data;
        FieldToJson(jdata["BreadcrumbIndex"], decoded_value.BreadcrumbIndex, options); // base case
        ; ///< @todo Generate for pContextString[None]: wchar_t [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1* data, const JsonOptions& options)
{
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
        FieldToJson(jdata["BreadcrumbCount"], decoded_value.BreadcrumbCount, options); // base case
        ; ///< @todo Generate for pLastBreadcrumbValue[None]: UINT [is_pointer]
        ; ///< @todo Generate for pCommandHistory[BreadcrumbCount]: D3D12_AUTO_BREADCRUMB_OP [is_pointer] [is_array] [is_enum]
        ; ///< @todo Generate for pNext[None]: D3D12_AUTO_BREADCRUMB_NODE1 [is_pointer] [is_struct]
        FieldToJson(jdata["BreadcrumbContextsCount"], decoded_value.BreadcrumbContextsCount, options); // base case
        ; ///< @todo Generate for pBreadcrumbContexts[BreadcrumbContextsCount]: D3D12_DRED_BREADCRUMB_CONTEXT [is_pointer] [is_array] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA& meta_struct = *data;
        ; ///< @todo Generate for Flags[None]: D3D12_DRED_FLAGS [is_enum]
        ; ///< @todo Generate for pHeadAutoBreadcrumbNode[None]: D3D12_AUTO_BREADCRUMB_NODE [is_pointer] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DRED_ALLOCATION_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_ALLOCATION_NODE& meta_struct = *data;
        ; ///< @todo Generate for ObjectNameA[None]: char [is_pointer]
        ; ///< @todo Generate for ObjectNameW[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for AllocationType[None]: D3D12_DRED_ALLOCATION_TYPE [is_enum]
        ; ///< @todo Generate for pNext[None]: D3D12_DRED_ALLOCATION_NODE [is_pointer] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DRED_ALLOCATION_NODE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_ALLOCATION_NODE1& meta_struct = *data;
        ; ///< @todo Generate for ObjectNameA[None]: char [is_pointer]
        ; ///< @todo Generate for ObjectNameW[None]: wchar_t [is_pointer]
        ; ///< @todo Generate for AllocationType[None]: D3D12_DRED_ALLOCATION_TYPE [is_enum]
        ; ///< @todo Generate for pNext[None]: D3D12_DRED_ALLOCATION_NODE1 [is_pointer] [is_struct]
        ; ///< @todo Generate for pObject[None]: IUnknown [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& meta_struct = *data;
        ; ///< @todo Generate for pHeadAutoBreadcrumbNode[None]: D3D12_AUTO_BREADCRUMB_NODE [is_pointer] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& meta_struct = *data;
        ; ///< @todo Generate for pHeadAutoBreadcrumbNode[None]: D3D12_AUTO_BREADCRUMB_NODE1 [is_pointer] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT& meta_struct = *data;
        FieldToJson(jdata["PageFaultVA"], decoded_value.PageFaultVA, options); // base case
        ; ///< @todo Generate for pHeadExistingAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE [is_pointer] [is_struct]
        ; ///< @todo Generate for pHeadRecentFreedAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE [is_pointer] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1& meta_struct = *data;
        FieldToJson(jdata["PageFaultVA"], decoded_value.PageFaultVA, options); // base case
        ; ///< @todo Generate for pHeadExistingAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1 [is_pointer] [is_struct]
        ; ///< @todo Generate for pHeadRecentFreedAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1 [is_pointer] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2& meta_struct = *data;
        FieldToJson(jdata["PageFaultVA"], decoded_value.PageFaultVA, options); // base case
        ; ///< @todo Generate for pHeadExistingAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1 [is_pointer] [is_struct]
        ; ///< @todo Generate for pHeadRecentFreedAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1 [is_pointer] [is_struct]
        ; ///< @todo Generate for PageFaultFlags[None]: D3D12_DRED_PAGE_FAULT_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1& meta_struct = *data;
        FieldToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options); // base case
        ; ///< @todo Generate for AutoBreadcrumbsOutput[None]: D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT [is_struct]
        ; ///< @todo Generate for PageFaultOutput[None]: D3D12_DRED_PAGE_FAULT_OUTPUT [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2& meta_struct = *data;
        FieldToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options); // base case
        ; ///< @todo Generate for AutoBreadcrumbsOutput[None]: D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1 [is_struct]
        ; ///< @todo Generate for PageFaultOutput[None]: D3D12_DRED_PAGE_FAULT_OUTPUT1 [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3& meta_struct = *data;
        FieldToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason, options); // base case
        ; ///< @todo Generate for AutoBreadcrumbsOutput[None]: D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1 [is_struct]
        ; ///< @todo Generate for PageFaultOutput[None]: D3D12_DRED_PAGE_FAULT_OUTPUT2 [is_struct]
        ; ///< @todo Generate for DeviceState[None]: D3D12_DRED_DEVICE_STATE [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // base case
        FieldToJson(jdata["Count"], decoded_value.Count, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& meta_struct = *data;
        FieldToJson(jdata["NodeIndex"], decoded_value.NodeIndex, options); // base case
        FieldToJson(jdata["Count"], decoded_value.Count, options); // base case
        ; ///< @todo Generate for pTypes[Count]: GUID [is_pointer] [is_array] [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1& meta_struct = *data;
        FieldToJson(jdata["NodeMask"], decoded_value.NodeMask, options); // base case
        ; ///< @todo Generate for Flags[None]: D3D12_PROTECTED_RESOURCE_SESSION_FLAGS [is_enum]
        ; ///< @todo Generate for ProtectionType[None]: GUID [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& meta_struct = *data;
        ; ///< @todo Generate for ClearValue[None]: D3D12_CLEAR_VALUE [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["AdditionalWidth"], decoded_value.AdditionalWidth, options); // base case
        FieldToJson(jdata["AdditionalHeight"], decoded_value.AdditionalHeight, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["SrcSubresource"], decoded_value.SrcSubresource, options); // base case
        FieldToJson(jdata["DstSubresource"], decoded_value.DstSubresource, options); // base case
        FieldToJson(jdata["DstX"], decoded_value.DstX, options); // base case
        FieldToJson(jdata["DstY"], decoded_value.DstY, options); // base case
        ; ///< @todo Generate for SrcRect[None]: tagRECT [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& meta_struct = *data;
        ; ///< @todo Generate for pSrcResource[None]: ID3D12Resource [is_pointer]
        ; ///< @todo Generate for pDstResource[None]: ID3D12Resource [is_pointer]
        FieldToJson(jdata["SubresourceCount"], decoded_value.SubresourceCount, options); // base case
        ; ///< @todo Generate for pSubresourceParameters[SubresourceCount]: D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS [is_pointer] [is_array] [is_struct]
        ; ///< @todo Generate for Format[None]: DXGI_FORMAT [is_enum]
        ; ///< @todo Generate for ResolveMode[None]: D3D12_RESOLVE_MODE [is_enum]
        FieldToJson(jdata["PreserveResolveSource"], decoded_value.PreserveResolveSource, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["AdditionalWidth"], decoded_value.AdditionalWidth, options); // base case
        FieldToJson(jdata["AdditionalHeight"], decoded_value.AdditionalHeight, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_RENDER_TARGET_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC& meta_struct = *data;
        ; ///< @todo Generate for cpuDescriptor[None]: D3D12_CPU_DESCRIPTOR_HANDLE [is_struct]
        ; ///< @todo Generate for BeginningAccess[None]: D3D12_RENDER_PASS_BEGINNING_ACCESS [is_struct]
        ; ///< @todo Generate for EndingAccess[None]: D3D12_RENDER_PASS_ENDING_ACCESS [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& meta_struct = *data;
        ; ///< @todo Generate for cpuDescriptor[None]: D3D12_CPU_DESCRIPTOR_HANDLE [is_struct]
        ; ///< @todo Generate for DepthBeginningAccess[None]: D3D12_RENDER_PASS_BEGINNING_ACCESS [is_struct]
        ; ///< @todo Generate for StencilBeginningAccess[None]: D3D12_RENDER_PASS_BEGINNING_ACCESS [is_struct]
        ; ///< @todo Generate for DepthEndingAccess[None]: D3D12_RENDER_PASS_ENDING_ACCESS [is_struct]
        ; ///< @todo Generate for StencilEndingAccess[None]: D3D12_RENDER_PASS_ENDING_ACCESS [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_RAYS_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_RAYS_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_RAYS_DESC& meta_struct = *data;
        ; ///< @todo Generate for RayGenerationShaderRecord[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE [is_struct]
        ; ///< @todo Generate for MissShaderTable[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE [is_struct]
        ; ///< @todo Generate for HitGroupTable[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE [is_struct]
        ; ///< @todo Generate for CallableShaderTable[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE [is_struct]
        FieldToJson(jdata["Width"], decoded_value.Width, options); // base case
        FieldToJson(jdata["Height"], decoded_value.Height, options); // base case
        FieldToJson(jdata["Depth"], decoded_value.Depth, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_CACHE_SESSION_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_CACHE_SESSION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_CACHE_SESSION_DESC& meta_struct = *data;
        ; ///< @todo Generate for Identifier[None]: GUID [is_struct]
        ; ///< @todo Generate for Mode[None]: D3D12_SHADER_CACHE_MODE [is_enum]
        ; ///< @todo Generate for Flags[None]: D3D12_SHADER_CACHE_FLAGS [is_enum]
        FieldToJson(jdata["MaximumInMemoryCacheSizeBytes"], decoded_value.MaximumInMemoryCacheSizeBytes, options); // base case
        FieldToJson(jdata["MaximumInMemoryCacheEntries"], decoded_value.MaximumInMemoryCacheEntries, options); // base case
        FieldToJson(jdata["MaximumValueFileSizeBytes"], decoded_value.MaximumValueFileSizeBytes, options); // base case
        FieldToJson(jdata["Version"], decoded_value.Version, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_BARRIER_SUBRESOURCE_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE& meta_struct = *data;
        FieldToJson(jdata["IndexOrFirstMipLevel"], decoded_value.IndexOrFirstMipLevel, options); // base case
        FieldToJson(jdata["NumMipLevels"], decoded_value.NumMipLevels, options); // base case
        FieldToJson(jdata["FirstArraySlice"], decoded_value.FirstArraySlice, options); // base case
        FieldToJson(jdata["NumArraySlices"], decoded_value.NumArraySlices, options); // base case
        FieldToJson(jdata["FirstPlane"], decoded_value.FirstPlane, options); // base case
        FieldToJson(jdata["NumPlanes"], decoded_value.NumPlanes, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_BARRIER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_BARRIER& meta_struct = *data;
        ; ///< @todo Generate for SyncBefore[None]: D3D12_BARRIER_SYNC [is_enum]
        ; ///< @todo Generate for SyncAfter[None]: D3D12_BARRIER_SYNC [is_enum]
        ; ///< @todo Generate for AccessBefore[None]: D3D12_BARRIER_ACCESS [is_enum]
        ; ///< @todo Generate for AccessAfter[None]: D3D12_BARRIER_ACCESS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_BARRIER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_TEXTURE_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXTURE_BARRIER& meta_struct = *data;
        ; ///< @todo Generate for SyncBefore[None]: D3D12_BARRIER_SYNC [is_enum]
        ; ///< @todo Generate for SyncAfter[None]: D3D12_BARRIER_SYNC [is_enum]
        ; ///< @todo Generate for AccessBefore[None]: D3D12_BARRIER_ACCESS [is_enum]
        ; ///< @todo Generate for AccessAfter[None]: D3D12_BARRIER_ACCESS [is_enum]
        ; ///< @todo Generate for LayoutBefore[None]: D3D12_BARRIER_LAYOUT [is_enum]
        ; ///< @todo Generate for LayoutAfter[None]: D3D12_BARRIER_LAYOUT [is_enum]
        ; ///< @todo Generate for pResource[None]: ID3D12Resource [is_pointer]
        ; ///< @todo Generate for Subresources[None]: D3D12_BARRIER_SUBRESOURCE_RANGE [is_struct]
        ; ///< @todo Generate for Flags[None]: D3D12_TEXTURE_BARRIER_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_BARRIER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_BARRIER& meta_struct = *data;
        ; ///< @todo Generate for SyncBefore[None]: D3D12_BARRIER_SYNC [is_enum]
        ; ///< @todo Generate for SyncAfter[None]: D3D12_BARRIER_SYNC [is_enum]
        ; ///< @todo Generate for AccessBefore[None]: D3D12_BARRIER_ACCESS [is_enum]
        ; ///< @todo Generate for AccessAfter[None]: D3D12_BARRIER_ACCESS [is_enum]
        ; ///< @todo Generate for pResource[None]: ID3D12Resource [is_pointer]
        FieldToJson(jdata["Offset"], decoded_value.Offset, options); // base case
        FieldToJson(jdata["Size"], decoded_value.Size, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_DATA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_DATA& meta_struct = *data;
        ; ///< @todo Generate for pData[None]: void [is_pointer]
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); // base case
        FieldToJson(jdata["SlicePitch"], decoded_value.SlicePitch, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MEMCPY_DEST* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_MEMCPY_DEST& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MEMCPY_DEST& meta_struct = *data;
        ; ///< @todo Generate for pData[None]: void [is_pointer]
        FieldToJson(jdata["RowPitch"], decoded_value.RowPitch, options); // base case
        FieldToJson(jdata["SlicePitch"], decoded_value.SlicePitch, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_CONFIGURATION_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_CONFIGURATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_CONFIGURATION_DESC& meta_struct = *data;
        ; ///< @todo Generate for Flags[None]: D3D12_DEVICE_FLAGS [is_enum]
        FieldToJson(jdata["GpuBasedValidationFlags"], decoded_value.GpuBasedValidationFlags, options); // base case
        FieldToJson(jdata["SDKVersion"], decoded_value.SDKVersion, options); // base case
        FieldToJson(jdata["NumEnabledExperimentalFeatures"], decoded_value.NumEnabledExperimentalFeatures, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_MESH_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS& meta_struct = *data;
        FieldToJson(jdata["ThreadGroupCountX"], decoded_value.ThreadGroupCountX, options); // base case
        FieldToJson(jdata["ThreadGroupCountY"], decoded_value.ThreadGroupCountY, options); // base case
        FieldToJson(jdata["ThreadGroupCountZ"], decoded_value.ThreadGroupCountZ, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D_SHADER_MACRO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D_SHADER_MACRO& decoded_value = *data->decoded_value;
        const Decoded_D3D_SHADER_MACRO& meta_struct = *data;
        ; ///< @todo Generate for Name[None]: char [is_pointer]
        ; ///< @todo Generate for Definition[None]: char [is_pointer]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& meta_struct = *data;
        FieldToJson(jdata["MaxMessagesPerCommandList"], decoded_value.MaxMessagesPerCommandList, options); // base case
        ; ///< @todo Generate for DefaultShaderPatchMode[None]: D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE [is_enum]
        ; ///< @todo Generate for PipelineStateCreateFlags[None]: D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& meta_struct = *data;
        FieldToJson(jdata["SlowdownFactor"], decoded_value.SlowdownFactor, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& meta_struct = *data;
        ; ///< @todo Generate for ShaderPatchMode[None]: D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MESSAGE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_MESSAGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MESSAGE& meta_struct = *data;
        ; ///< @todo Generate for Category[None]: D3D12_MESSAGE_CATEGORY [is_enum]
        ; ///< @todo Generate for Severity[None]: D3D12_MESSAGE_SEVERITY [is_enum]
        ; ///< @todo Generate for ID[None]: D3D12_MESSAGE_ID [is_enum]
        ; ///< @todo Generate for pDescription[None]: char [is_pointer]
        FieldToJson(jdata["DescriptionByteLength"], decoded_value.DescriptionByteLength, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_INFO_QUEUE_FILTER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INFO_QUEUE_FILTER_DESC& meta_struct = *data;
        FieldToJson(jdata["NumCategories"], decoded_value.NumCategories, options); // base case
        ; ///< @todo Generate for pCategoryList[NumCategories]: D3D12_MESSAGE_CATEGORY [is_pointer] [is_array] [is_enum]
        FieldToJson(jdata["NumSeverities"], decoded_value.NumSeverities, options); // base case
        ; ///< @todo Generate for pSeverityList[NumSeverities]: D3D12_MESSAGE_SEVERITY [is_pointer] [is_array] [is_enum]
        FieldToJson(jdata["NumIDs"], decoded_value.NumIDs, options); // base case
        ; ///< @todo Generate for pIDList[NumIDs]: D3D12_MESSAGE_ID [is_pointer] [is_array] [is_enum]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const D3D12_INFO_QUEUE_FILTER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INFO_QUEUE_FILTER& meta_struct = *data;
        ; ///< @todo Generate for AllowList[None]: D3D12_INFO_QUEUE_FILTER_DESC [is_struct]
        ; ///< @todo Generate for DenyList[None]: D3D12_INFO_QUEUE_FILTER_DESC [is_struct]
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const tagRECT& decoded_value = *data->decoded_value;
        const Decoded_tagRECT& meta_struct = *data;
        FieldToJson(jdata["left"], decoded_value.left, options); // base case
        FieldToJson(jdata["top"], decoded_value.top, options); // base case
        FieldToJson(jdata["right"], decoded_value.right, options); // base case
        FieldToJson(jdata["bottom"], decoded_value.bottom, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const tagPOINT& decoded_value = *data->decoded_value;
        const Decoded_tagPOINT& meta_struct = *data;
        FieldToJson(jdata["x"], decoded_value.x, options); // base case
        FieldToJson(jdata["y"], decoded_value.y, options); // base case
        /// @todo Follow the pNext chain, if any.
    }
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
