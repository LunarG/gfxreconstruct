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
** This file is generated from dx12_struct_to_json_body_generator.py.
**
*/

#include "generated_dx12_struct_to_json.h"
#include "generated_dx12_enum_to_json.h"
#include "decode/custom_dx12_to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FRAME_STATISTICS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["PresentCount"], obj.PresentCount, options); // base case
    FieldToJson(jdata["PresentRefreshCount"], obj.PresentRefreshCount, options); // base case
    FieldToJson(jdata["SyncRefreshCount"], obj.SyncRefreshCount, options); // base case
    ; ///< @todo Generate for SyncQPCTime[None]: LARGE_INTEGER
    ; ///< @todo Generate for SyncGPUTime[None]: LARGE_INTEGER
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MAPPED_RECT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Pitch"], obj.Pitch, options); // base case
    ; ///< @todo Generate for pBits[None]: BYTE
}

void FieldToJson(nlohmann::ordered_json& jdata, const LUID& obj, const JsonOptions& options)
{
    FieldToJson(jdata["LowPart"], obj.LowPart, options); // base case
    FieldToJson(jdata["HighPart"], obj.HighPart, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Description[128]: wchar_t
    FieldToJson(jdata["VendorId"], obj.VendorId, options); // base case
    FieldToJson(jdata["DeviceId"], obj.DeviceId, options); // base case
    FieldToJson(jdata["SubSysId"], obj.SubSysId, options); // base case
    FieldToJson(jdata["Revision"], obj.Revision, options); // base case
    FieldToJson(jdata["DedicatedVideoMemory"], obj.DedicatedVideoMemory, options); // base case
    FieldToJson(jdata["DedicatedSystemMemory"], obj.DedicatedSystemMemory, options); // base case
    FieldToJson(jdata["SharedSystemMemory"], obj.SharedSystemMemory, options); // base case
    ; ///< @todo Generate for AdapterLuid[None]: LUID
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTPUT_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for DeviceName[32]: wchar_t
    ; ///< @todo Generate for DesktopCoordinates[None]: tagRECT
    FieldToJson(jdata["AttachedToDesktop"], obj.AttachedToDesktop, options); // base case
    FieldToJson(jdata["Rotation"], ToString(obj.Rotation), options); // enum
    ; ///< @todo Generate for Monitor[None]: void
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SHARED_RESOURCE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Handle[None]: void
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SURFACE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for BufferDesc[None]: DXGI_MODE_DESC
    ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC
    FieldToJson(jdata["BufferUsage"], obj.BufferUsage, options); // base case
    FieldToJson(jdata["BufferCount"], obj.BufferCount, options); // base case
    ; ///< @todo Generate for OutputWindow[None]: void
    FieldToJson(jdata["Windowed"], obj.Windowed, options); // base case
    FieldToJson(jdata["SwapEffect"], ToString(obj.SwapEffect), options); // enum
    FieldToJson(jdata["Flags"], obj.Flags, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_DESC1& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Description[128]: wchar_t
    FieldToJson(jdata["VendorId"], obj.VendorId, options); // base case
    FieldToJson(jdata["DeviceId"], obj.DeviceId, options); // base case
    FieldToJson(jdata["SubSysId"], obj.SubSysId, options); // base case
    FieldToJson(jdata["Revision"], obj.Revision, options); // base case
    FieldToJson(jdata["DedicatedVideoMemory"], obj.DedicatedVideoMemory, options); // base case
    FieldToJson(jdata["DedicatedSystemMemory"], obj.DedicatedSystemMemory, options); // base case
    FieldToJson(jdata["SharedSystemMemory"], obj.SharedSystemMemory, options); // base case
    ; ///< @todo Generate for AdapterLuid[None]: LUID
    FieldToJson(jdata["Flags"], obj.Flags, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_DISPLAY_COLOR_SPACE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for PrimaryCoordinates[16]: FLOAT
    ; ///< @todo Generate for WhitePoints[32]: FLOAT
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_MOVE_RECT& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for SourcePoint[None]: tagPOINT
    ; ///< @todo Generate for DestinationRect[None]: tagRECT
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for ModeDesc[None]: DXGI_MODE_DESC
    FieldToJson(jdata["Rotation"], ToString(obj.Rotation), options); // enum
    FieldToJson(jdata["DesktopImageInSystemMemory"], obj.DesktopImageInSystemMemory, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_POINTER_POSITION& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Position[None]: tagPOINT
    FieldToJson(jdata["Visible"], obj.Visible, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_POINTER_SHAPE_INFO& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], obj.Type, options); // base case
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    FieldToJson(jdata["Pitch"], obj.Pitch, options); // base case
    ; ///< @todo Generate for HotSpot[None]: tagPOINT
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_FRAME_INFO& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for LastPresentTime[None]: LARGE_INTEGER
    ; ///< @todo Generate for LastMouseUpdateTime[None]: LARGE_INTEGER
    FieldToJson(jdata["AccumulatedFrames"], obj.AccumulatedFrames, options); // base case
    FieldToJson(jdata["RectsCoalesced"], obj.RectsCoalesced, options); // base case
    FieldToJson(jdata["ProtectedContentMaskedOut"], obj.ProtectedContentMaskedOut, options); // base case
    ; ///< @todo Generate for PointerPosition[None]: DXGI_OUTDUPL_POINTER_POSITION
    FieldToJson(jdata["TotalMetadataBufferSize"], obj.TotalMetadataBufferSize, options); // base case
    FieldToJson(jdata["PointerShapeBufferSize"], obj.PointerShapeBufferSize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_DESC1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    ; ///< @todo Generate for RefreshRate[None]: DXGI_RATIONAL
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ScanlineOrdering"], ToString(obj.ScanlineOrdering), options); // enum
    FieldToJson(jdata["Scaling"], ToString(obj.Scaling), options); // enum
    FieldToJson(jdata["Stereo"], obj.Stereo, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_DESC1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["Stereo"], obj.Stereo, options); // base case
    ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC
    FieldToJson(jdata["BufferUsage"], obj.BufferUsage, options); // base case
    FieldToJson(jdata["BufferCount"], obj.BufferCount, options); // base case
    FieldToJson(jdata["Scaling"], ToString(obj.Scaling), options); // enum
    FieldToJson(jdata["SwapEffect"], ToString(obj.SwapEffect), options); // enum
    FieldToJson(jdata["AlphaMode"], ToString(obj.AlphaMode), options); // enum
    FieldToJson(jdata["Flags"], obj.Flags, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for RefreshRate[None]: DXGI_RATIONAL
    FieldToJson(jdata["ScanlineOrdering"], ToString(obj.ScanlineOrdering), options); // enum
    FieldToJson(jdata["Scaling"], ToString(obj.Scaling), options); // enum
    FieldToJson(jdata["Windowed"], obj.Windowed, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_PRESENT_PARAMETERS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DirtyRectsCount"], obj.DirtyRectsCount, options); // base case
    ; ///< @todo Generate for pDirtyRects[DirtyRectsCount]: tagRECT
    ; ///< @todo Generate for pScrollRect[None]: tagRECT
    ; ///< @todo Generate for pScrollOffset[None]: tagPOINT
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_DESC2& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Description[128]: wchar_t
    FieldToJson(jdata["VendorId"], obj.VendorId, options); // base case
    FieldToJson(jdata["DeviceId"], obj.DeviceId, options); // base case
    FieldToJson(jdata["SubSysId"], obj.SubSysId, options); // base case
    FieldToJson(jdata["Revision"], obj.Revision, options); // base case
    FieldToJson(jdata["DedicatedVideoMemory"], obj.DedicatedVideoMemory, options); // base case
    FieldToJson(jdata["DedicatedSystemMemory"], obj.DedicatedSystemMemory, options); // base case
    FieldToJson(jdata["SharedSystemMemory"], obj.SharedSystemMemory, options); // base case
    ; ///< @todo Generate for AdapterLuid[None]: LUID
    FieldToJson(jdata["Flags"], obj.Flags, options); // base case
    FieldToJson(jdata["GraphicsPreemptionGranularity"], ToString(obj.GraphicsPreemptionGranularity), options); // enum
    FieldToJson(jdata["ComputePreemptionGranularity"], ToString(obj.ComputePreemptionGranularity), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MATRIX_3X2_F& obj, const JsonOptions& options)
{
    FieldToJson(jdata["_11"], obj._11, options); // base case
    FieldToJson(jdata["_12"], obj._12, options); // base case
    FieldToJson(jdata["_21"], obj._21, options); // base case
    FieldToJson(jdata["_22"], obj._22, options); // base case
    FieldToJson(jdata["_31"], obj._31, options); // base case
    FieldToJson(jdata["_32"], obj._32, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_DECODE_SWAP_CHAIN_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Flags"], obj.Flags, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FRAME_STATISTICS_MEDIA& obj, const JsonOptions& options)
{
    FieldToJson(jdata["PresentCount"], obj.PresentCount, options); // base case
    FieldToJson(jdata["PresentRefreshCount"], obj.PresentRefreshCount, options); // base case
    FieldToJson(jdata["SyncRefreshCount"], obj.SyncRefreshCount, options); // base case
    ; ///< @todo Generate for SyncQPCTime[None]: LARGE_INTEGER
    ; ///< @todo Generate for SyncGPUTime[None]: LARGE_INTEGER
    FieldToJson(jdata["CompositionMode"], ToString(obj.CompositionMode), options); // enum
    FieldToJson(jdata["ApprovedPresentDuration"], obj.ApprovedPresentDuration, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_QUERY_VIDEO_MEMORY_INFO& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Budget"], obj.Budget, options); // base case
    FieldToJson(jdata["CurrentUsage"], obj.CurrentUsage, options); // base case
    FieldToJson(jdata["AvailableForReservation"], obj.AvailableForReservation, options); // base case
    FieldToJson(jdata["CurrentReservation"], obj.CurrentReservation, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HDR_METADATA_HDR10& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for RedPrimary[2]: UINT16
    ; ///< @todo Generate for GreenPrimary[2]: UINT16
    ; ///< @todo Generate for BluePrimary[2]: UINT16
    ; ///< @todo Generate for WhitePoint[2]: UINT16
    FieldToJson(jdata["MaxMasteringLuminance"], obj.MaxMasteringLuminance, options); // base case
    FieldToJson(jdata["MinMasteringLuminance"], obj.MinMasteringLuminance, options); // base case
    FieldToJson(jdata["MaxContentLightLevel"], obj.MaxContentLightLevel, options); // base case
    FieldToJson(jdata["MaxFrameAverageLightLevel"], obj.MaxFrameAverageLightLevel, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HDR_METADATA_HDR10PLUS& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Data[72]: BYTE
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_DESC3& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Description[128]: wchar_t
    FieldToJson(jdata["VendorId"], obj.VendorId, options); // base case
    FieldToJson(jdata["DeviceId"], obj.DeviceId, options); // base case
    FieldToJson(jdata["SubSysId"], obj.SubSysId, options); // base case
    FieldToJson(jdata["Revision"], obj.Revision, options); // base case
    FieldToJson(jdata["DedicatedVideoMemory"], obj.DedicatedVideoMemory, options); // base case
    FieldToJson(jdata["DedicatedSystemMemory"], obj.DedicatedSystemMemory, options); // base case
    FieldToJson(jdata["SharedSystemMemory"], obj.SharedSystemMemory, options); // base case
    ; ///< @todo Generate for AdapterLuid[None]: LUID
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata["GraphicsPreemptionGranularity"], ToString(obj.GraphicsPreemptionGranularity), options); // enum
    FieldToJson(jdata["ComputePreemptionGranularity"], ToString(obj.ComputePreemptionGranularity), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTPUT_DESC1& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for DeviceName[32]: wchar_t
    ; ///< @todo Generate for DesktopCoordinates[None]: tagRECT
    FieldToJson(jdata["AttachedToDesktop"], obj.AttachedToDesktop, options); // base case
    FieldToJson(jdata["Rotation"], ToString(obj.Rotation), options); // enum
    ; ///< @todo Generate for Monitor[None]: void
    FieldToJson(jdata["BitsPerColor"], obj.BitsPerColor, options); // base case
    FieldToJson(jdata["ColorSpace"], ToString(obj.ColorSpace), options); // enum
    ; ///< @todo Generate for RedPrimary[2]: FLOAT
    ; ///< @todo Generate for GreenPrimary[2]: FLOAT
    ; ///< @todo Generate for BluePrimary[2]: FLOAT
    ; ///< @todo Generate for WhitePoint[2]: FLOAT
    FieldToJson(jdata["MinLuminance"], obj.MinLuminance, options); // base case
    FieldToJson(jdata["MaxLuminance"], obj.MaxLuminance, options); // base case
    FieldToJson(jdata["MaxFullFrameLuminance"], obj.MaxFullFrameLuminance, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RATIONAL& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Numerator"], obj.Numerator, options); // base case
    FieldToJson(jdata["Denominator"], obj.Denominator, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SAMPLE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Count"], obj.Count, options); // base case
    FieldToJson(jdata["Quality"], obj.Quality, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RGB& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Red"], obj.Red, options); // base case
    FieldToJson(jdata["Green"], obj.Green, options); // base case
    FieldToJson(jdata["Blue"], obj.Blue, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3DCOLORVALUE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["r"], obj.r, options); // base case
    FieldToJson(jdata["g"], obj.g, options); // base case
    FieldToJson(jdata["b"], obj.b, options); // base case
    FieldToJson(jdata["a"], obj.a, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GAMMA_CONTROL& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Scale[None]: DXGI_RGB
    ; ///< @todo Generate for Offset[None]: DXGI_RGB
    ; ///< @todo Generate for GammaCurve[1025]: DXGI_RGB
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GAMMA_CONTROL_CAPABILITIES& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ScaleAndOffsetSupported"], obj.ScaleAndOffsetSupported, options); // base case
    FieldToJson(jdata["MaxConvertedValue"], obj.MaxConvertedValue, options); // base case
    FieldToJson(jdata["MinConvertedValue"], obj.MinConvertedValue, options); // base case
    FieldToJson(jdata["NumGammaControlPoints"], obj.NumGammaControlPoints, options); // base case
    ; ///< @todo Generate for ControlPointPositions[1025]: float
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    ; ///< @todo Generate for RefreshRate[None]: DXGI_RATIONAL
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ScanlineOrdering"], ToString(obj.ScanlineOrdering), options); // enum
    FieldToJson(jdata["Scaling"], ToString(obj.Scaling), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_JPEG_DC_HUFFMAN_TABLE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for CodeCounts[12]: BYTE
    ; ///< @todo Generate for CodeValues[12]: BYTE
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_JPEG_AC_HUFFMAN_TABLE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for CodeCounts[16]: BYTE
    ; ///< @todo Generate for CodeValues[162]: BYTE
}

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_JPEG_QUANTIZATION_TABLE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Elements[64]: BYTE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["Priority"], obj.Priority, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata["NodeMask"], obj.NodeMask, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INPUT_ELEMENT_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for SemanticName[None]: char
    FieldToJson(jdata["SemanticIndex"], obj.SemanticIndex, options); // base case
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["InputSlot"], obj.InputSlot, options); // base case
    FieldToJson(jdata["AlignedByteOffset"], obj.AlignedByteOffset, options); // base case
    FieldToJson(jdata["InputSlotClass"], ToString(obj.InputSlotClass), options); // enum
    FieldToJson(jdata["InstanceDataStepRate"], obj.InstanceDataStepRate, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SO_DECLARATION_ENTRY& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Stream"], obj.Stream, options); // base case
    ; ///< @todo Generate for SemanticName[None]: char
    FieldToJson(jdata["SemanticIndex"], obj.SemanticIndex, options); // base case
    FieldToJson(jdata["StartComponent"], obj.StartComponent, options); // base case
    FieldToJson(jdata["ComponentCount"], obj.ComponentCount, options); // base case
    FieldToJson(jdata["OutputSlot"], obj.OutputSlot, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEWPORT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["TopLeftX"], obj.TopLeftX, options); // base case
    FieldToJson(jdata["TopLeftY"], obj.TopLeftY, options); // base case
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    FieldToJson(jdata["MinDepth"], obj.MinDepth, options); // base case
    FieldToJson(jdata["MaxDepth"], obj.MaxDepth, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BOX& obj, const JsonOptions& options)
{
    FieldToJson(jdata["left"], obj.left, options); // base case
    FieldToJson(jdata["top"], obj.top, options); // base case
    FieldToJson(jdata["front"], obj.front, options); // base case
    FieldToJson(jdata["right"], obj.right, options); // base case
    FieldToJson(jdata["bottom"], obj.bottom, options); // base case
    FieldToJson(jdata["back"], obj.back, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCILOP_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["StencilFailOp"], ToString(obj.StencilFailOp), options); // enum
    FieldToJson(jdata["StencilDepthFailOp"], ToString(obj.StencilDepthFailOp), options); // enum
    FieldToJson(jdata["StencilPassOp"], ToString(obj.StencilPassOp), options); // enum
    FieldToJson(jdata["StencilFunc"], ToString(obj.StencilFunc), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DepthEnable"], obj.DepthEnable, options); // base case
    FieldToJson(jdata["DepthWriteMask"], ToString(obj.DepthWriteMask), options); // enum
    FieldToJson(jdata["DepthFunc"], ToString(obj.DepthFunc), options); // enum
    FieldToJson(jdata["StencilEnable"], obj.StencilEnable, options); // base case
    FieldToJson(jdata["StencilReadMask"], obj.StencilReadMask, options); // base case
    FieldToJson(jdata["StencilWriteMask"], obj.StencilWriteMask, options); // base case
    ; ///< @todo Generate for FrontFace[None]: D3D12_DEPTH_STENCILOP_DESC
    ; ///< @todo Generate for BackFace[None]: D3D12_DEPTH_STENCILOP_DESC
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_DESC1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DepthEnable"], obj.DepthEnable, options); // base case
    FieldToJson(jdata["DepthWriteMask"], ToString(obj.DepthWriteMask), options); // enum
    FieldToJson(jdata["DepthFunc"], ToString(obj.DepthFunc), options); // enum
    FieldToJson(jdata["StencilEnable"], obj.StencilEnable, options); // base case
    FieldToJson(jdata["StencilReadMask"], obj.StencilReadMask, options); // base case
    FieldToJson(jdata["StencilWriteMask"], obj.StencilWriteMask, options); // base case
    ; ///< @todo Generate for FrontFace[None]: D3D12_DEPTH_STENCILOP_DESC
    ; ///< @todo Generate for BackFace[None]: D3D12_DEPTH_STENCILOP_DESC
    FieldToJson(jdata["DepthBoundsTestEnable"], obj.DepthBoundsTestEnable, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCILOP_DESC1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["StencilFailOp"], ToString(obj.StencilFailOp), options); // enum
    FieldToJson(jdata["StencilDepthFailOp"], ToString(obj.StencilDepthFailOp), options); // enum
    FieldToJson(jdata["StencilPassOp"], ToString(obj.StencilPassOp), options); // enum
    FieldToJson(jdata["StencilFunc"], ToString(obj.StencilFunc), options); // enum
    FieldToJson(jdata["StencilReadMask"], obj.StencilReadMask, options); // base case
    FieldToJson(jdata["StencilWriteMask"], obj.StencilWriteMask, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_DESC2& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DepthEnable"], obj.DepthEnable, options); // base case
    FieldToJson(jdata["DepthWriteMask"], ToString(obj.DepthWriteMask), options); // enum
    FieldToJson(jdata["DepthFunc"], ToString(obj.DepthFunc), options); // enum
    FieldToJson(jdata["StencilEnable"], obj.StencilEnable, options); // base case
    ; ///< @todo Generate for FrontFace[None]: D3D12_DEPTH_STENCILOP_DESC1
    ; ///< @todo Generate for BackFace[None]: D3D12_DEPTH_STENCILOP_DESC1
    FieldToJson(jdata["DepthBoundsTestEnable"], obj.DepthBoundsTestEnable, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_TARGET_BLEND_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["BlendEnable"], obj.BlendEnable, options); // base case
    FieldToJson(jdata["LogicOpEnable"], obj.LogicOpEnable, options); // base case
    FieldToJson(jdata["SrcBlend"], ToString(obj.SrcBlend), options); // enum
    FieldToJson(jdata["DestBlend"], ToString(obj.DestBlend), options); // enum
    FieldToJson(jdata["BlendOp"], ToString(obj.BlendOp), options); // enum
    FieldToJson(jdata["SrcBlendAlpha"], ToString(obj.SrcBlendAlpha), options); // enum
    FieldToJson(jdata["DestBlendAlpha"], ToString(obj.DestBlendAlpha), options); // enum
    FieldToJson(jdata["BlendOpAlpha"], ToString(obj.BlendOpAlpha), options); // enum
    FieldToJson(jdata["LogicOp"], ToString(obj.LogicOp), options); // enum
    FieldToJson(jdata["RenderTargetWriteMask"], obj.RenderTargetWriteMask, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BLEND_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["AlphaToCoverageEnable"], obj.AlphaToCoverageEnable, options); // base case
    FieldToJson(jdata["IndependentBlendEnable"], obj.IndependentBlendEnable, options); // base case
    ; ///< @todo Generate for RenderTarget[8]: D3D12_RENDER_TARGET_BLEND_DESC
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RASTERIZER_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["FillMode"], ToString(obj.FillMode), options); // enum
    FieldToJson(jdata["CullMode"], ToString(obj.CullMode), options); // enum
    FieldToJson(jdata["FrontCounterClockwise"], obj.FrontCounterClockwise, options); // base case
    FieldToJson(jdata["DepthBias"], obj.DepthBias, options); // base case
    FieldToJson(jdata["DepthBiasClamp"], obj.DepthBiasClamp, options); // base case
    FieldToJson(jdata["SlopeScaledDepthBias"], obj.SlopeScaledDepthBias, options); // base case
    FieldToJson(jdata["DepthClipEnable"], obj.DepthClipEnable, options); // base case
    FieldToJson(jdata["MultisampleEnable"], obj.MultisampleEnable, options); // base case
    FieldToJson(jdata["AntialiasedLineEnable"], obj.AntialiasedLineEnable, options); // base case
    FieldToJson(jdata["ForcedSampleCount"], obj.ForcedSampleCount, options); // base case
    FieldToJson(jdata["ConservativeRaster"], ToString(obj.ConservativeRaster), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RASTERIZER_DESC1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["FillMode"], ToString(obj.FillMode), options); // enum
    FieldToJson(jdata["CullMode"], ToString(obj.CullMode), options); // enum
    FieldToJson(jdata["FrontCounterClockwise"], obj.FrontCounterClockwise, options); // base case
    FieldToJson(jdata["DepthBias"], obj.DepthBias, options); // base case
    FieldToJson(jdata["DepthBiasClamp"], obj.DepthBiasClamp, options); // base case
    FieldToJson(jdata["SlopeScaledDepthBias"], obj.SlopeScaledDepthBias, options); // base case
    FieldToJson(jdata["DepthClipEnable"], obj.DepthClipEnable, options); // base case
    FieldToJson(jdata["MultisampleEnable"], obj.MultisampleEnable, options); // base case
    FieldToJson(jdata["AntialiasedLineEnable"], obj.AntialiasedLineEnable, options); // base case
    FieldToJson(jdata["ForcedSampleCount"], obj.ForcedSampleCount, options); // base case
    FieldToJson(jdata["ConservativeRaster"], ToString(obj.ConservativeRaster), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RASTERIZER_DESC2& obj, const JsonOptions& options)
{
    FieldToJson(jdata["FillMode"], ToString(obj.FillMode), options); // enum
    FieldToJson(jdata["CullMode"], ToString(obj.CullMode), options); // enum
    FieldToJson(jdata["FrontCounterClockwise"], obj.FrontCounterClockwise, options); // base case
    FieldToJson(jdata["DepthBias"], obj.DepthBias, options); // base case
    FieldToJson(jdata["DepthBiasClamp"], obj.DepthBiasClamp, options); // base case
    FieldToJson(jdata["SlopeScaledDepthBias"], obj.SlopeScaledDepthBias, options); // base case
    FieldToJson(jdata["DepthClipEnable"], obj.DepthClipEnable, options); // base case
    FieldToJson(jdata["LineRasterizationMode"], ToString(obj.LineRasterizationMode), options); // enum
    FieldToJson(jdata["ForcedSampleCount"], obj.ForcedSampleCount, options); // base case
    FieldToJson(jdata["ConservativeRaster"], ToString(obj.ConservativeRaster), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_BYTECODE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pShaderBytecode[BytecodeLength]: void
    FieldToJson(jdata["BytecodeLength"], obj.BytecodeLength, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STREAM_OUTPUT_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pSODeclaration[NumEntries]: D3D12_SO_DECLARATION_ENTRY
    FieldToJson(jdata["NumEntries"], obj.NumEntries, options); // base case
    ; ///< @todo Generate for pBufferStrides[NumStrides]: UINT
    FieldToJson(jdata["NumStrides"], obj.NumStrides, options); // base case
    FieldToJson(jdata["RasterizedStream"], obj.RasterizedStream, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INPUT_LAYOUT_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pInputElementDescs[NumElements]: D3D12_INPUT_ELEMENT_DESC
    FieldToJson(jdata["NumElements"], obj.NumElements, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CACHED_PIPELINE_STATE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pCachedBlob[CachedBlobSizeInBytes]: void
    FieldToJson(jdata["CachedBlobSizeInBytes"], obj.CachedBlobSizeInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GRAPHICS_PIPELINE_STATE_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pRootSignature[None]: ID3D12RootSignature
    ; ///< @todo Generate for VS[None]: D3D12_SHADER_BYTECODE
    ; ///< @todo Generate for PS[None]: D3D12_SHADER_BYTECODE
    ; ///< @todo Generate for DS[None]: D3D12_SHADER_BYTECODE
    ; ///< @todo Generate for HS[None]: D3D12_SHADER_BYTECODE
    ; ///< @todo Generate for GS[None]: D3D12_SHADER_BYTECODE
    ; ///< @todo Generate for StreamOutput[None]: D3D12_STREAM_OUTPUT_DESC
    ; ///< @todo Generate for BlendState[None]: D3D12_BLEND_DESC
    FieldToJson(jdata["SampleMask"], obj.SampleMask, options); // base case
    ; ///< @todo Generate for RasterizerState[None]: D3D12_RASTERIZER_DESC
    ; ///< @todo Generate for DepthStencilState[None]: D3D12_DEPTH_STENCIL_DESC
    ; ///< @todo Generate for InputLayout[None]: D3D12_INPUT_LAYOUT_DESC
    FieldToJson(jdata["IBStripCutValue"], ToString(obj.IBStripCutValue), options); // enum
    FieldToJson(jdata["PrimitiveTopologyType"], ToString(obj.PrimitiveTopologyType), options); // enum
    FieldToJson(jdata["NumRenderTargets"], obj.NumRenderTargets, options); // base case
    ; ///< @todo Generate for RTVFormats[8]: DXGI_FORMAT
    FieldToJson(jdata["DSVFormat"], ToString(obj.DSVFormat), options); // enum
    ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC
    FieldToJson(jdata["NodeMask"], obj.NodeMask, options); // base case
    ; ///< @todo Generate for CachedPSO[None]: D3D12_CACHED_PIPELINE_STATE
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMPUTE_PIPELINE_STATE_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pRootSignature[None]: ID3D12RootSignature
    ; ///< @todo Generate for CS[None]: D3D12_SHADER_BYTECODE
    FieldToJson(jdata["NodeMask"], obj.NodeMask, options); // base case
    ; ///< @todo Generate for CachedPSO[None]: D3D12_CACHED_PIPELINE_STATE
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RT_FORMAT_ARRAY& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for RTFormats[8]: DXGI_FORMAT
    FieldToJson(jdata["NumRenderTargets"], obj.NumRenderTargets, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_STREAM_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SizeInBytes"], obj.SizeInBytes, options); // base case
    ; ///< @todo Generate for pPipelineStateSubobjectStream[None]: void
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DoublePrecisionFloatShaderOps"], obj.DoublePrecisionFloatShaderOps, options); // base case
    FieldToJson(jdata["OutputMergerLogicOp"], obj.OutputMergerLogicOp, options); // base case
    FieldToJson(jdata["MinPrecisionSupport"], ToString(obj.MinPrecisionSupport), options); // enum
    FieldToJson(jdata["TiledResourcesTier"], ToString(obj.TiledResourcesTier), options); // enum
    FieldToJson(jdata["ResourceBindingTier"], ToString(obj.ResourceBindingTier), options); // enum
    FieldToJson(jdata["PSSpecifiedStencilRefSupported"], obj.PSSpecifiedStencilRefSupported, options); // base case
    FieldToJson(jdata["TypedUAVLoadAdditionalFormats"], obj.TypedUAVLoadAdditionalFormats, options); // base case
    FieldToJson(jdata["ROVsSupported"], obj.ROVsSupported, options); // base case
    FieldToJson(jdata["ConservativeRasterizationTier"], ToString(obj.ConservativeRasterizationTier), options); // enum
    FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], obj.MaxGPUVirtualAddressBitsPerResource, options); // base case
    FieldToJson(jdata["StandardSwizzle64KBSupported"], obj.StandardSwizzle64KBSupported, options); // base case
    FieldToJson(jdata["CrossNodeSharingTier"], ToString(obj.CrossNodeSharingTier), options); // enum
    FieldToJson(jdata["CrossAdapterRowMajorTextureSupported"], obj.CrossAdapterRowMajorTextureSupported, options); // base case
    FieldToJson(jdata["VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation"], obj.VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation, options); // base case
    FieldToJson(jdata["ResourceHeapTier"], ToString(obj.ResourceHeapTier), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["WaveOps"], obj.WaveOps, options); // base case
    FieldToJson(jdata["WaveLaneCountMin"], obj.WaveLaneCountMin, options); // base case
    FieldToJson(jdata["WaveLaneCountMax"], obj.WaveLaneCountMax, options); // base case
    FieldToJson(jdata["TotalLaneCount"], obj.TotalLaneCount, options); // base case
    FieldToJson(jdata["ExpandedComputeResourceStates"], obj.ExpandedComputeResourceStates, options); // base case
    FieldToJson(jdata["Int64ShaderOps"], obj.Int64ShaderOps, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS2& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DepthBoundsTestSupported"], obj.DepthBoundsTestSupported, options); // base case
    FieldToJson(jdata["ProgrammableSamplePositionsTier"], ToString(obj.ProgrammableSamplePositionsTier), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_ROOT_SIGNATURE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["HighestVersion"], ToString(obj.HighestVersion), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_ARCHITECTURE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NodeIndex"], obj.NodeIndex, options); // base case
    FieldToJson(jdata["TileBasedRenderer"], obj.TileBasedRenderer, options); // base case
    FieldToJson(jdata["UMA"], obj.UMA, options); // base case
    FieldToJson(jdata["CacheCoherentUMA"], obj.CacheCoherentUMA, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_ARCHITECTURE1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NodeIndex"], obj.NodeIndex, options); // base case
    FieldToJson(jdata["TileBasedRenderer"], obj.TileBasedRenderer, options); // base case
    FieldToJson(jdata["UMA"], obj.UMA, options); // base case
    FieldToJson(jdata["CacheCoherentUMA"], obj.CacheCoherentUMA, options); // base case
    FieldToJson(jdata["IsolatedMMU"], obj.IsolatedMMU, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_FEATURE_LEVELS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumFeatureLevels"], obj.NumFeatureLevels, options); // base case
    ; ///< @todo Generate for pFeatureLevelsRequested[NumFeatureLevels]: D3D_FEATURE_LEVEL
    FieldToJson(jdata["MaxSupportedFeatureLevel"], ToString(obj.MaxSupportedFeatureLevel), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_SHADER_MODEL& obj, const JsonOptions& options)
{
    FieldToJson(jdata["HighestShaderModel"], ToString(obj.HighestShaderModel), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_FORMAT_SUPPORT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["Support1"], ToString(obj.Support1), options); // enum
    FieldToJson(jdata["Support2"], ToString(obj.Support2), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["SampleCount"], obj.SampleCount, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata["NumQualityLevels"], obj.NumQualityLevels, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_FORMAT_INFO& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["PlaneCount"], obj.PlaneCount, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], obj.MaxGPUVirtualAddressBitsPerResource, options); // base case
    FieldToJson(jdata["MaxGPUVirtualAddressBitsPerProcess"], obj.MaxGPUVirtualAddressBitsPerProcess, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_SHADER_CACHE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SupportFlags"], ToString(obj.SupportFlags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& obj, const JsonOptions& options)
{
    FieldToJson(jdata["CommandListType"], ToString(obj.CommandListType), options); // enum
    FieldToJson(jdata["Priority"], obj.Priority, options); // base case
    FieldToJson(jdata["PriorityForTypeIsSupported"], obj.PriorityForTypeIsSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS3& obj, const JsonOptions& options)
{
    FieldToJson(jdata["CopyQueueTimestampQueriesSupported"], obj.CopyQueueTimestampQueriesSupported, options); // base case
    FieldToJson(jdata["CastingFullyTypedFormatSupported"], obj.CastingFullyTypedFormatSupported, options); // base case
    FieldToJson(jdata["WriteBufferImmediateSupportFlags"], ToString(obj.WriteBufferImmediateSupportFlags), options); // enum
    FieldToJson(jdata["ViewInstancingTier"], ToString(obj.ViewInstancingTier), options); // enum
    FieldToJson(jdata["BarycentricsSupported"], obj.BarycentricsSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_EXISTING_HEAPS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Supported"], obj.Supported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_DISPLAYABLE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DisplayableTexture"], obj.DisplayableTexture, options); // base case
    FieldToJson(jdata["SharedResourceCompatibilityTier"], ToString(obj.SharedResourceCompatibilityTier), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS4& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MSAA64KBAlignedTextureSupported"], obj.MSAA64KBAlignedTextureSupported, options); // base case
    FieldToJson(jdata["SharedResourceCompatibilityTier"], ToString(obj.SharedResourceCompatibilityTier), options); // enum
    FieldToJson(jdata["Native16BitShaderOpsSupported"], obj.Native16BitShaderOpsSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_SERIALIZATION& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NodeIndex"], obj.NodeIndex, options); // base case
    FieldToJson(jdata["HeapSerializationTier"], ToString(obj.HeapSerializationTier), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_CROSS_NODE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SharingTier"], ToString(obj.SharingTier), options); // enum
    FieldToJson(jdata["AtomicShaderInstructions"], obj.AtomicShaderInstructions, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS5& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SRVOnlyTiledResourceTier3"], obj.SRVOnlyTiledResourceTier3, options); // base case
    FieldToJson(jdata["RenderPassesTier"], ToString(obj.RenderPassesTier), options); // enum
    FieldToJson(jdata["RaytracingTier"], ToString(obj.RaytracingTier), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS6& obj, const JsonOptions& options)
{
    FieldToJson(jdata["AdditionalShadingRatesSupported"], obj.AdditionalShadingRatesSupported, options); // base case
    FieldToJson(jdata["PerPrimitiveShadingRateSupportedWithViewportIndexing"], obj.PerPrimitiveShadingRateSupportedWithViewportIndexing, options); // base case
    FieldToJson(jdata["VariableShadingRateTier"], ToString(obj.VariableShadingRateTier), options); // enum
    FieldToJson(jdata["ShadingRateImageTileSize"], obj.ShadingRateImageTileSize, options); // base case
    FieldToJson(jdata["BackgroundProcessingSupported"], obj.BackgroundProcessingSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS7& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MeshShaderTier"], ToString(obj.MeshShaderTier), options); // enum
    FieldToJson(jdata["SamplerFeedbackTier"], ToString(obj.SamplerFeedbackTier), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_QUERY_META_COMMAND& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for CommandId[None]: GUID
    FieldToJson(jdata["NodeMask"], obj.NodeMask, options); // base case
    ; ///< @todo Generate for pQueryInputData[QueryInputDataSizeInBytes]: void
    FieldToJson(jdata["QueryInputDataSizeInBytes"], obj.QueryInputDataSizeInBytes, options); // base case
    ; ///< @todo Generate for pQueryOutputData[QueryOutputDataSizeInBytes]: void
    FieldToJson(jdata["QueryOutputDataSizeInBytes"], obj.QueryOutputDataSizeInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS8& obj, const JsonOptions& options)
{
    FieldToJson(jdata["UnalignedBlockTexturesSupported"], obj.UnalignedBlockTexturesSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS9& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MeshShaderPipelineStatsSupported"], obj.MeshShaderPipelineStatsSupported, options); // base case
    FieldToJson(jdata["MeshShaderSupportsFullRangeRenderTargetArrayIndex"], obj.MeshShaderSupportsFullRangeRenderTargetArrayIndex, options); // base case
    FieldToJson(jdata["AtomicInt64OnTypedResourceSupported"], obj.AtomicInt64OnTypedResourceSupported, options); // base case
    FieldToJson(jdata["AtomicInt64OnGroupSharedSupported"], obj.AtomicInt64OnGroupSharedSupported, options); // base case
    FieldToJson(jdata["DerivativesInMeshAndAmplificationShadersSupported"], obj.DerivativesInMeshAndAmplificationShadersSupported, options); // base case
    FieldToJson(jdata["WaveMMATier"], ToString(obj.WaveMMATier), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS10& obj, const JsonOptions& options)
{
    FieldToJson(jdata["VariableRateShadingSumCombinerSupported"], obj.VariableRateShadingSumCombinerSupported, options); // base case
    FieldToJson(jdata["MeshShaderPerPrimitiveShadingRateSupported"], obj.MeshShaderPerPrimitiveShadingRateSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS11& obj, const JsonOptions& options)
{
    FieldToJson(jdata["AtomicInt64OnDescriptorHeapResourceSupported"], obj.AtomicInt64OnDescriptorHeapResourceSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS12& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MSPrimitivesPipelineStatisticIncludesCulledPrimitives"], ToString(obj.MSPrimitivesPipelineStatisticIncludesCulledPrimitives), options); // enum
    FieldToJson(jdata["EnhancedBarriersSupported"], obj.EnhancedBarriersSupported, options); // base case
    FieldToJson(jdata["RelaxedFormatCastingSupported"], obj.RelaxedFormatCastingSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS13& obj, const JsonOptions& options)
{
    FieldToJson(jdata["UnrestrictedBufferTextureCopyPitchSupported"], obj.UnrestrictedBufferTextureCopyPitchSupported, options); // base case
    FieldToJson(jdata["UnrestrictedVertexElementAlignmentSupported"], obj.UnrestrictedVertexElementAlignmentSupported, options); // base case
    FieldToJson(jdata["InvertedViewportHeightFlipsYSupported"], obj.InvertedViewportHeightFlipsYSupported, options); // base case
    FieldToJson(jdata["InvertedViewportDepthFlipsZSupported"], obj.InvertedViewportDepthFlipsZSupported, options); // base case
    FieldToJson(jdata["TextureCopyBetweenDimensionsSupported"], obj.TextureCopyBetweenDimensionsSupported, options); // base case
    FieldToJson(jdata["AlphaBlendFactorSupported"], obj.AlphaBlendFactorSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS14& obj, const JsonOptions& options)
{
    FieldToJson(jdata["AdvancedTextureOpsSupported"], obj.AdvancedTextureOpsSupported, options); // base case
    FieldToJson(jdata["WriteableMSAATexturesSupported"], obj.WriteableMSAATexturesSupported, options); // base case
    FieldToJson(jdata["IndependentFrontAndBackStencilRefMaskSupported"], obj.IndependentFrontAndBackStencilRefMaskSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS15& obj, const JsonOptions& options)
{
    FieldToJson(jdata["TriangleFanSupported"], obj.TriangleFanSupported, options); // base case
    FieldToJson(jdata["DynamicIndexBufferStripCutSupported"], obj.DynamicIndexBufferStripCutSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS16& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DynamicDepthBiasSupported"], obj.DynamicDepthBiasSupported, options); // base case
    FieldToJson(jdata["GPUUploadHeapSupported"], obj.GPUUploadHeapSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS17& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NonNormalizedCoordinateSamplersSupported"], obj.NonNormalizedCoordinateSamplersSupported, options); // base case
    FieldToJson(jdata["ManualWriteTrackingResourceSupported"], obj.ManualWriteTrackingResourceSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS18& obj, const JsonOptions& options)
{
    FieldToJson(jdata["RenderPassesValid"], obj.RenderPassesValid, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS19& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MismatchingOutputDimensionsSupported"], obj.MismatchingOutputDimensionsSupported, options); // base case
    FieldToJson(jdata["SupportedSampleCountsWithNoOutputs"], obj.SupportedSampleCountsWithNoOutputs, options); // base case
    FieldToJson(jdata["PointSamplingAddressesNeverRoundUp"], obj.PointSamplingAddressesNeverRoundUp, options); // base case
    FieldToJson(jdata["RasterizerDesc2Supported"], obj.RasterizerDesc2Supported, options); // base case
    FieldToJson(jdata["NarrowQuadrilateralLinesSupported"], obj.NarrowQuadrilateralLinesSupported, options); // base case
    FieldToJson(jdata["AnisoFilterWithPointMipSupported"], obj.AnisoFilterWithPointMipSupported, options); // base case
    FieldToJson(jdata["MaxSamplerDescriptorHeapSize"], obj.MaxSamplerDescriptorHeapSize, options); // base case
    FieldToJson(jdata["MaxSamplerDescriptorHeapSizeWithStaticSamplers"], obj.MaxSamplerDescriptorHeapSizeWithStaticSamplers, options); // base case
    FieldToJson(jdata["MaxViewDescriptorHeapSize"], obj.MaxViewDescriptorHeapSize, options); // base case
    FieldToJson(jdata["ComputeOnlyCustomHeapSupported"], obj.ComputeOnlyCustomHeapSupported, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_ALLOCATION_INFO& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SizeInBytes"], obj.SizeInBytes, options); // base case
    FieldToJson(jdata["Alignment"], obj.Alignment, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_ALLOCATION_INFO1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Offset"], obj.Offset, options); // base case
    FieldToJson(jdata["Alignment"], obj.Alignment, options); // base case
    FieldToJson(jdata["SizeInBytes"], obj.SizeInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_PROPERTIES& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["CPUPageProperty"], ToString(obj.CPUPageProperty), options); // enum
    FieldToJson(jdata["MemoryPoolPreference"], ToString(obj.MemoryPoolPreference), options); // enum
    FieldToJson(jdata["CreationNodeMask"], obj.CreationNodeMask, options); // base case
    FieldToJson(jdata["VisibleNodeMask"], obj.VisibleNodeMask, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SizeInBytes"], obj.SizeInBytes, options); // base case
    ; ///< @todo Generate for Properties[None]: D3D12_HEAP_PROPERTIES
    FieldToJson(jdata["Alignment"], obj.Alignment, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MIP_REGION& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    FieldToJson(jdata["Depth"], obj.Depth, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Dimension"], ToString(obj.Dimension), options); // enum
    FieldToJson(jdata["Alignment"], obj.Alignment, options); // base case
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    FieldToJson(jdata["DepthOrArraySize"], obj.DepthOrArraySize, options); // base case
    FieldToJson(jdata["MipLevels"], obj.MipLevels, options); // base case
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC
    FieldToJson(jdata["Layout"], ToString(obj.Layout), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_DESC1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Dimension"], ToString(obj.Dimension), options); // enum
    FieldToJson(jdata["Alignment"], obj.Alignment, options); // base case
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    FieldToJson(jdata["DepthOrArraySize"], obj.DepthOrArraySize, options); // base case
    FieldToJson(jdata["MipLevels"], obj.MipLevels, options); // base case
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    ; ///< @todo Generate for SampleDesc[None]: DXGI_SAMPLE_DESC
    FieldToJson(jdata["Layout"], ToString(obj.Layout), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    ; ///< @todo Generate for SamplerFeedbackMipRegion[None]: D3D12_MIP_REGION
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VALUE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Depth"], obj.Depth, options); // base case
    FieldToJson(jdata["Stencil"], obj.Stencil, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RANGE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Begin"], obj.Begin, options); // base case
    FieldToJson(jdata["End"], obj.End, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RANGE_UINT64& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Begin"], obj.Begin, options); // base case
    FieldToJson(jdata["End"], obj.End, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBRESOURCE_RANGE_UINT64& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Subresource"], obj.Subresource, options); // base case
    ; ///< @todo Generate for Range[None]: D3D12_RANGE_UINT64
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBRESOURCE_INFO& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Offset"], obj.Offset, options); // base case
    FieldToJson(jdata["RowPitch"], obj.RowPitch, options); // base case
    FieldToJson(jdata["DepthPitch"], obj.DepthPitch, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILED_RESOURCE_COORDINATE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["X"], obj.X, options); // base case
    FieldToJson(jdata["Y"], obj.Y, options); // base case
    FieldToJson(jdata["Z"], obj.Z, options); // base case
    FieldToJson(jdata["Subresource"], obj.Subresource, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_REGION_SIZE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumTiles"], obj.NumTiles, options); // base case
    FieldToJson(jdata["UseBox"], obj.UseBox, options); // base case
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    FieldToJson(jdata["Depth"], obj.Depth, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBRESOURCE_TILING& obj, const JsonOptions& options)
{
    FieldToJson(jdata["WidthInTiles"], obj.WidthInTiles, options); // base case
    FieldToJson(jdata["HeightInTiles"], obj.HeightInTiles, options); // base case
    FieldToJson(jdata["DepthInTiles"], obj.DepthInTiles, options); // base case
    FieldToJson(jdata["StartTileIndexInOverallResource"], obj.StartTileIndexInOverallResource, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_SHAPE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["WidthInTexels"], obj.WidthInTexels, options); // base case
    FieldToJson(jdata["HeightInTexels"], obj.HeightInTexels, options); // base case
    FieldToJson(jdata["DepthInTexels"], obj.DepthInTexels, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PACKED_MIP_INFO& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumStandardMips"], obj.NumStandardMips, options); // base case
    FieldToJson(jdata["NumPackedMips"], obj.NumPackedMips, options); // base case
    FieldToJson(jdata["NumTilesForPackedMips"], obj.NumTilesForPackedMips, options); // base case
    FieldToJson(jdata["StartTileIndexInOverallResource"], obj.StartTileIndexInOverallResource, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_TRANSITION_BARRIER& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pResource[None]: ID3D12Resource
    FieldToJson(jdata["Subresource"], obj.Subresource, options); // base case
    FieldToJson(jdata["StateBefore"], ToString(obj.StateBefore), options); // enum
    FieldToJson(jdata["StateAfter"], ToString(obj.StateAfter), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_ALIASING_BARRIER& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pResourceBefore[None]: ID3D12Resource
    ; ///< @todo Generate for pResourceAfter[None]: ID3D12Resource
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_UAV_BARRIER& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pResource[None]: ID3D12Resource
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBRESOURCE_FOOTPRINT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    FieldToJson(jdata["Depth"], obj.Depth, options); // base case
    FieldToJson(jdata["RowPitch"], obj.RowPitch, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Offset"], obj.Offset, options); // base case
    ; ///< @todo Generate for Footprint[None]: D3D12_SUBRESOURCE_FOOTPRINT
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLE_POSITION& obj, const JsonOptions& options)
{
    FieldToJson(jdata["X"], obj.X, options); // base case
    FieldToJson(jdata["Y"], obj.Y, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCE_LOCATION& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ViewportArrayIndex"], obj.ViewportArrayIndex, options); // base case
    FieldToJson(jdata["RenderTargetArrayIndex"], obj.RenderTargetArrayIndex, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ViewInstanceCount"], obj.ViewInstanceCount, options); // base case
    ; ///< @todo Generate for pViewInstanceLocations[ViewInstanceCount]: D3D12_VIEW_INSTANCE_LOCATION
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["FirstElement"], obj.FirstElement, options); // base case
    FieldToJson(jdata["NumElements"], obj.NumElements, options); // base case
    FieldToJson(jdata["StructureByteStride"], obj.StructureByteStride, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MostDetailedMip"], obj.MostDetailedMip, options); // base case
    FieldToJson(jdata["MipLevels"], obj.MipLevels, options); // base case
    FieldToJson(jdata["ResourceMinLODClamp"], obj.ResourceMinLODClamp, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_ARRAY_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MostDetailedMip"], obj.MostDetailedMip, options); // base case
    FieldToJson(jdata["MipLevels"], obj.MipLevels, options); // base case
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
    FieldToJson(jdata["ResourceMinLODClamp"], obj.ResourceMinLODClamp, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MostDetailedMip"], obj.MostDetailedMip, options); // base case
    FieldToJson(jdata["MipLevels"], obj.MipLevels, options); // base case
    FieldToJson(jdata["PlaneSlice"], obj.PlaneSlice, options); // base case
    FieldToJson(jdata["ResourceMinLODClamp"], obj.ResourceMinLODClamp, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_ARRAY_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MostDetailedMip"], obj.MostDetailedMip, options); // base case
    FieldToJson(jdata["MipLevels"], obj.MipLevels, options); // base case
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
    FieldToJson(jdata["PlaneSlice"], obj.PlaneSlice, options); // base case
    FieldToJson(jdata["ResourceMinLODClamp"], obj.ResourceMinLODClamp, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX3D_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MostDetailedMip"], obj.MostDetailedMip, options); // base case
    FieldToJson(jdata["MipLevels"], obj.MipLevels, options); // base case
    FieldToJson(jdata["ResourceMinLODClamp"], obj.ResourceMinLODClamp, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXCUBE_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MostDetailedMip"], obj.MostDetailedMip, options); // base case
    FieldToJson(jdata["MipLevels"], obj.MipLevels, options); // base case
    FieldToJson(jdata["ResourceMinLODClamp"], obj.ResourceMinLODClamp, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXCUBE_ARRAY_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MostDetailedMip"], obj.MostDetailedMip, options); // base case
    FieldToJson(jdata["MipLevels"], obj.MipLevels, options); // base case
    FieldToJson(jdata["First2DArrayFace"], obj.First2DArrayFace, options); // base case
    FieldToJson(jdata["NumCubes"], obj.NumCubes, options); // base case
    FieldToJson(jdata["ResourceMinLODClamp"], obj.ResourceMinLODClamp, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["UnusedField_NothingToDefine"], obj.UnusedField_NothingToDefine, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_ARRAY_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Location"], obj.Location, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_RESOURCE_VIEW_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
    FieldToJson(jdata["Shader4ComponentMapping"], obj.Shader4ComponentMapping, options); // base case
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CONSTANT_BUFFER_VIEW_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["BufferLocation"], obj.BufferLocation, options); // base case
    FieldToJson(jdata["SizeInBytes"], obj.SizeInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Filter"], ToString(obj.Filter), options); // enum
    FieldToJson(jdata["AddressU"], ToString(obj.AddressU), options); // enum
    FieldToJson(jdata["AddressV"], ToString(obj.AddressV), options); // enum
    FieldToJson(jdata["AddressW"], ToString(obj.AddressW), options); // enum
    FieldToJson(jdata["MipLODBias"], obj.MipLODBias, options); // base case
    FieldToJson(jdata["MaxAnisotropy"], obj.MaxAnisotropy, options); // base case
    FieldToJson(jdata["ComparisonFunc"], ToString(obj.ComparisonFunc), options); // enum
    ; ///< @todo Generate for BorderColor[4]: FLOAT
    FieldToJson(jdata["MinLOD"], obj.MinLOD, options); // base case
    FieldToJson(jdata["MaxLOD"], obj.MaxLOD, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_DESC2& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Filter"], ToString(obj.Filter), options); // enum
    FieldToJson(jdata["AddressU"], ToString(obj.AddressU), options); // enum
    FieldToJson(jdata["AddressV"], ToString(obj.AddressV), options); // enum
    FieldToJson(jdata["AddressW"], ToString(obj.AddressW), options); // enum
    FieldToJson(jdata["MipLODBias"], obj.MipLODBias, options); // base case
    FieldToJson(jdata["MaxAnisotropy"], obj.MaxAnisotropy, options); // base case
    FieldToJson(jdata["ComparisonFunc"], ToString(obj.ComparisonFunc), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
    FieldToJson(jdata["MinLOD"], obj.MinLOD, options); // base case
    FieldToJson(jdata["MaxLOD"], obj.MaxLOD, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_UAV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["FirstElement"], obj.FirstElement, options); // base case
    FieldToJson(jdata["NumElements"], obj.NumElements, options); // base case
    FieldToJson(jdata["StructureByteStride"], obj.StructureByteStride, options); // base case
    FieldToJson(jdata["CounterOffsetInBytes"], obj.CounterOffsetInBytes, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_UAV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_ARRAY_UAV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_UAV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
    FieldToJson(jdata["PlaneSlice"], obj.PlaneSlice, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_ARRAY_UAV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
    FieldToJson(jdata["PlaneSlice"], obj.PlaneSlice, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_UAV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["UnusedField_NothingToDefine"], obj.UnusedField_NothingToDefine, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_ARRAY_UAV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX3D_UAV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
    FieldToJson(jdata["FirstWSlice"], obj.FirstWSlice, options); // base case
    FieldToJson(jdata["WSize"], obj.WSize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_UNORDERED_ACCESS_VIEW_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_RTV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["FirstElement"], obj.FirstElement, options); // base case
    FieldToJson(jdata["NumElements"], obj.NumElements, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_RTV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_ARRAY_RTV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_RTV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
    FieldToJson(jdata["PlaneSlice"], obj.PlaneSlice, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_RTV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["UnusedField_NothingToDefine"], obj.UnusedField_NothingToDefine, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_ARRAY_RTV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
    FieldToJson(jdata["PlaneSlice"], obj.PlaneSlice, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_ARRAY_RTV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX3D_RTV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
    FieldToJson(jdata["FirstWSlice"], obj.FirstWSlice, options); // base case
    FieldToJson(jdata["WSize"], obj.WSize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_TARGET_VIEW_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_DSV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_ARRAY_DSV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_DSV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_ARRAY_DSV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MipSlice"], obj.MipSlice, options); // base case
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_DSV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["UnusedField_NothingToDefine"], obj.UnusedField_NothingToDefine, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_ARRAY_DSV& obj, const JsonOptions& options)
{
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["ArraySize"], obj.ArraySize, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VIEW_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["NumDescriptors"], obj.NumDescriptors, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata["NodeMask"], obj.NodeMask, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["RangeType"], ToString(obj.RangeType), options); // enum
    FieldToJson(jdata["NumDescriptors"], obj.NumDescriptors, options); // base case
    FieldToJson(jdata["BaseShaderRegister"], obj.BaseShaderRegister, options); // base case
    FieldToJson(jdata["RegisterSpace"], obj.RegisterSpace, options); // base case
    FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], obj.OffsetInDescriptorsFromTableStart, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_TABLE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumDescriptorRanges"], obj.NumDescriptorRanges, options); // base case
    ; ///< @todo Generate for pDescriptorRanges[NumDescriptorRanges]: D3D12_DESCRIPTOR_RANGE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_CONSTANTS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ShaderRegister"], obj.ShaderRegister, options); // base case
    FieldToJson(jdata["RegisterSpace"], obj.RegisterSpace, options); // base case
    FieldToJson(jdata["Num32BitValues"], obj.Num32BitValues, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ShaderRegister"], obj.ShaderRegister, options); // base case
    FieldToJson(jdata["RegisterSpace"], obj.RegisterSpace, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ParameterType"], ToString(obj.ParameterType), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
    FieldToJson(jdata["ShaderVisibility"], ToString(obj.ShaderVisibility), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATIC_SAMPLER_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Filter"], ToString(obj.Filter), options); // enum
    FieldToJson(jdata["AddressU"], ToString(obj.AddressU), options); // enum
    FieldToJson(jdata["AddressV"], ToString(obj.AddressV), options); // enum
    FieldToJson(jdata["AddressW"], ToString(obj.AddressW), options); // enum
    FieldToJson(jdata["MipLODBias"], obj.MipLODBias, options); // base case
    FieldToJson(jdata["MaxAnisotropy"], obj.MaxAnisotropy, options); // base case
    FieldToJson(jdata["ComparisonFunc"], ToString(obj.ComparisonFunc), options); // enum
    FieldToJson(jdata["BorderColor"], ToString(obj.BorderColor), options); // enum
    FieldToJson(jdata["MinLOD"], obj.MinLOD, options); // base case
    FieldToJson(jdata["MaxLOD"], obj.MaxLOD, options); // base case
    FieldToJson(jdata["ShaderRegister"], obj.ShaderRegister, options); // base case
    FieldToJson(jdata["RegisterSpace"], obj.RegisterSpace, options); // base case
    FieldToJson(jdata["ShaderVisibility"], ToString(obj.ShaderVisibility), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATIC_SAMPLER_DESC1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Filter"], ToString(obj.Filter), options); // enum
    FieldToJson(jdata["AddressU"], ToString(obj.AddressU), options); // enum
    FieldToJson(jdata["AddressV"], ToString(obj.AddressV), options); // enum
    FieldToJson(jdata["AddressW"], ToString(obj.AddressW), options); // enum
    FieldToJson(jdata["MipLODBias"], obj.MipLODBias, options); // base case
    FieldToJson(jdata["MaxAnisotropy"], obj.MaxAnisotropy, options); // base case
    FieldToJson(jdata["ComparisonFunc"], ToString(obj.ComparisonFunc), options); // enum
    FieldToJson(jdata["BorderColor"], ToString(obj.BorderColor), options); // enum
    FieldToJson(jdata["MinLOD"], obj.MinLOD, options); // base case
    FieldToJson(jdata["MaxLOD"], obj.MaxLOD, options); // base case
    FieldToJson(jdata["ShaderRegister"], obj.ShaderRegister, options); // base case
    FieldToJson(jdata["RegisterSpace"], obj.RegisterSpace, options); // base case
    FieldToJson(jdata["ShaderVisibility"], ToString(obj.ShaderVisibility), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumParameters"], obj.NumParameters, options); // base case
    ; ///< @todo Generate for pParameters[NumParameters]: D3D12_ROOT_PARAMETER
    FieldToJson(jdata["NumStaticSamplers"], obj.NumStaticSamplers, options); // base case
    ; ///< @todo Generate for pStaticSamplers[NumStaticSamplers]: D3D12_STATIC_SAMPLER_DESC
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["RangeType"], ToString(obj.RangeType), options); // enum
    FieldToJson(jdata["NumDescriptors"], obj.NumDescriptors, options); // base case
    FieldToJson(jdata["BaseShaderRegister"], obj.BaseShaderRegister, options); // base case
    FieldToJson(jdata["RegisterSpace"], obj.RegisterSpace, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], obj.OffsetInDescriptorsFromTableStart, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_TABLE1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumDescriptorRanges"], obj.NumDescriptorRanges, options); // base case
    ; ///< @todo Generate for pDescriptorRanges[NumDescriptorRanges]: D3D12_DESCRIPTOR_RANGE1
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ShaderRegister"], obj.ShaderRegister, options); // base case
    FieldToJson(jdata["RegisterSpace"], obj.RegisterSpace, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ParameterType"], ToString(obj.ParameterType), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
    FieldToJson(jdata["ShaderVisibility"], ToString(obj.ShaderVisibility), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_DESC1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumParameters"], obj.NumParameters, options); // base case
    ; ///< @todo Generate for pParameters[NumParameters]: D3D12_ROOT_PARAMETER1
    FieldToJson(jdata["NumStaticSamplers"], obj.NumStaticSamplers, options); // base case
    ; ///< @todo Generate for pStaticSamplers[NumStaticSamplers]: D3D12_STATIC_SAMPLER_DESC
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_DESC2& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumParameters"], obj.NumParameters, options); // base case
    ; ///< @todo Generate for pParameters[NumParameters]: D3D12_ROOT_PARAMETER1
    FieldToJson(jdata["NumStaticSamplers"], obj.NumStaticSamplers, options); // base case
    ; ///< @todo Generate for pStaticSamplers[NumStaticSamplers]: D3D12_STATIC_SAMPLER_DESC1
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Version"], ToString(obj.Version), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CPU_DESCRIPTOR_HANDLE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ptr"], obj.ptr, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_DESCRIPTOR_HANDLE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ptr"], obj.ptr, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISCARD_REGION& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumRects"], obj.NumRects, options); // base case
    ; ///< @todo Generate for pRects[NumRects]: tagRECT
    FieldToJson(jdata["FirstSubresource"], obj.FirstSubresource, options); // base case
    FieldToJson(jdata["NumSubresources"], obj.NumSubresources, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_HEAP_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["Count"], obj.Count, options); // base case
    FieldToJson(jdata["NodeMask"], obj.NodeMask, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_DATA_PIPELINE_STATISTICS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["IAVertices"], obj.IAVertices, options); // base case
    FieldToJson(jdata["IAPrimitives"], obj.IAPrimitives, options); // base case
    FieldToJson(jdata["VSInvocations"], obj.VSInvocations, options); // base case
    FieldToJson(jdata["GSInvocations"], obj.GSInvocations, options); // base case
    FieldToJson(jdata["GSPrimitives"], obj.GSPrimitives, options); // base case
    FieldToJson(jdata["CInvocations"], obj.CInvocations, options); // base case
    FieldToJson(jdata["CPrimitives"], obj.CPrimitives, options); // base case
    FieldToJson(jdata["PSInvocations"], obj.PSInvocations, options); // base case
    FieldToJson(jdata["HSInvocations"], obj.HSInvocations, options); // base case
    FieldToJson(jdata["DSInvocations"], obj.DSInvocations, options); // base case
    FieldToJson(jdata["CSInvocations"], obj.CSInvocations, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["IAVertices"], obj.IAVertices, options); // base case
    FieldToJson(jdata["IAPrimitives"], obj.IAPrimitives, options); // base case
    FieldToJson(jdata["VSInvocations"], obj.VSInvocations, options); // base case
    FieldToJson(jdata["GSInvocations"], obj.GSInvocations, options); // base case
    FieldToJson(jdata["GSPrimitives"], obj.GSPrimitives, options); // base case
    FieldToJson(jdata["CInvocations"], obj.CInvocations, options); // base case
    FieldToJson(jdata["CPrimitives"], obj.CPrimitives, options); // base case
    FieldToJson(jdata["PSInvocations"], obj.PSInvocations, options); // base case
    FieldToJson(jdata["HSInvocations"], obj.HSInvocations, options); // base case
    FieldToJson(jdata["DSInvocations"], obj.DSInvocations, options); // base case
    FieldToJson(jdata["CSInvocations"], obj.CSInvocations, options); // base case
    FieldToJson(jdata["ASInvocations"], obj.ASInvocations, options); // base case
    FieldToJson(jdata["MSInvocations"], obj.MSInvocations, options); // base case
    FieldToJson(jdata["MSPrimitives"], obj.MSPrimitives, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_DATA_SO_STATISTICS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumPrimitivesWritten"], obj.NumPrimitivesWritten, options); // base case
    FieldToJson(jdata["PrimitivesStorageNeeded"], obj.PrimitivesStorageNeeded, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STREAM_OUTPUT_BUFFER_VIEW& obj, const JsonOptions& options)
{
    FieldToJson(jdata["BufferLocation"], obj.BufferLocation, options); // base case
    FieldToJson(jdata["SizeInBytes"], obj.SizeInBytes, options); // base case
    FieldToJson(jdata["BufferFilledSizeLocation"], obj.BufferFilledSizeLocation, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRAW_ARGUMENTS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["VertexCountPerInstance"], obj.VertexCountPerInstance, options); // base case
    FieldToJson(jdata["InstanceCount"], obj.InstanceCount, options); // base case
    FieldToJson(jdata["StartVertexLocation"], obj.StartVertexLocation, options); // base case
    FieldToJson(jdata["StartInstanceLocation"], obj.StartInstanceLocation, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRAW_INDEXED_ARGUMENTS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["IndexCountPerInstance"], obj.IndexCountPerInstance, options); // base case
    FieldToJson(jdata["InstanceCount"], obj.InstanceCount, options); // base case
    FieldToJson(jdata["StartIndexLocation"], obj.StartIndexLocation, options); // base case
    FieldToJson(jdata["BaseVertexLocation"], obj.BaseVertexLocation, options); // base case
    FieldToJson(jdata["StartInstanceLocation"], obj.StartInstanceLocation, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_ARGUMENTS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ThreadGroupCountX"], obj.ThreadGroupCountX, options); // base case
    FieldToJson(jdata["ThreadGroupCountY"], obj.ThreadGroupCountY, options); // base case
    FieldToJson(jdata["ThreadGroupCountZ"], obj.ThreadGroupCountZ, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VERTEX_BUFFER_VIEW& obj, const JsonOptions& options)
{
    FieldToJson(jdata["BufferLocation"], obj.BufferLocation, options); // base case
    FieldToJson(jdata["SizeInBytes"], obj.SizeInBytes, options); // base case
    FieldToJson(jdata["StrideInBytes"], obj.StrideInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDEX_BUFFER_VIEW& obj, const JsonOptions& options)
{
    FieldToJson(jdata["BufferLocation"], obj.BufferLocation, options); // base case
    FieldToJson(jdata["SizeInBytes"], obj.SizeInBytes, options); // base case
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDIRECT_ARGUMENT_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_SIGNATURE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ByteStride"], obj.ByteStride, options); // base case
    FieldToJson(jdata["NumArgumentDescs"], obj.NumArgumentDescs, options); // base case
    ; ///< @todo Generate for pArgumentDescs[NumArgumentDescs]: D3D12_INDIRECT_ARGUMENT_DESC
    FieldToJson(jdata["NodeMask"], obj.NodeMask, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Dest"], obj.Dest, options); // base case
    FieldToJson(jdata["Value"], obj.Value, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NodeIndex"], obj.NodeIndex, options); // base case
    FieldToJson(jdata["Support"], ToString(obj.Support), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NodeMask"], obj.NodeMask, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Name[None]: wchar_t
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata["RequiredResourceState"], ToString(obj.RequiredResourceState), options); // enum
    FieldToJson(jdata["StructureOffset"], obj.StructureOffset, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Id[None]: GUID
    ; ///< @todo Generate for Name[None]: wchar_t
    FieldToJson(jdata["InitializationDirtyState"], ToString(obj.InitializationDirtyState), options); // enum
    FieldToJson(jdata["ExecutionDirtyState"], ToString(obj.ExecutionDirtyState), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_SUBOBJECT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    ; ///< @todo Generate for pDesc[None]: void
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_CONFIG& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GLOBAL_ROOT_SIGNATURE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pGlobalRootSignature[None]: ID3D12RootSignature
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LOCAL_ROOT_SIGNATURE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pLocalRootSignature[None]: ID3D12RootSignature
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_NODE_MASK& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NodeMask"], obj.NodeMask, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXPORT_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Name[None]: wchar_t
    ; ///< @todo Generate for ExportToRename[None]: wchar_t
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DXIL_LIBRARY_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for DXILLibrary[None]: D3D12_SHADER_BYTECODE
    FieldToJson(jdata["NumExports"], obj.NumExports, options); // base case
    ; ///< @todo Generate for pExports[NumExports]: D3D12_EXPORT_DESC
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXISTING_COLLECTION_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pExistingCollection[None]: ID3D12StateObject
    FieldToJson(jdata["NumExports"], obj.NumExports, options); // base case
    ; ///< @todo Generate for pExports[NumExports]: D3D12_EXPORT_DESC
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pSubobjectToAssociate[None]: D3D12_STATE_SUBOBJECT
    FieldToJson(jdata["NumExports"], obj.NumExports, options); // base case
    ; ///< @todo Generate for pExports[NumExports]: wchar_t
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for SubobjectToAssociate[None]: wchar_t
    FieldToJson(jdata["NumExports"], obj.NumExports, options); // base case
    ; ///< @todo Generate for pExports[NumExports]: wchar_t
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HIT_GROUP_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for HitGroupExport[None]: wchar_t
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    ; ///< @todo Generate for AnyHitShaderImport[None]: wchar_t
    ; ///< @todo Generate for ClosestHitShaderImport[None]: wchar_t
    ; ///< @todo Generate for IntersectionShaderImport[None]: wchar_t
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_SHADER_CONFIG& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MaxPayloadSizeInBytes"], obj.MaxPayloadSizeInBytes, options); // base case
    FieldToJson(jdata["MaxAttributeSizeInBytes"], obj.MaxAttributeSizeInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_CONFIG& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MaxTraceRecursionDepth"], obj.MaxTraceRecursionDepth, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_CONFIG1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MaxTraceRecursionDepth"], obj.MaxTraceRecursionDepth, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["NumSubobjects"], obj.NumSubobjects, options); // base case
    ; ///< @todo Generate for pSubobjects[NumSubobjects]: D3D12_STATE_SUBOBJECT
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["StartAddress"], obj.StartAddress, options); // base case
    FieldToJson(jdata["StrideInBytes"], obj.StrideInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["StartAddress"], obj.StartAddress, options); // base case
    FieldToJson(jdata["SizeInBytes"], obj.SizeInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["StartAddress"], obj.StartAddress, options); // base case
    FieldToJson(jdata["SizeInBytes"], obj.SizeInBytes, options); // base case
    FieldToJson(jdata["StrideInBytes"], obj.StrideInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Transform3x4"], obj.Transform3x4, options); // base case
    FieldToJson(jdata["IndexFormat"], ToString(obj.IndexFormat), options); // enum
    FieldToJson(jdata["VertexFormat"], ToString(obj.VertexFormat), options); // enum
    FieldToJson(jdata["IndexCount"], obj.IndexCount, options); // base case
    FieldToJson(jdata["VertexCount"], obj.VertexCount, options); // base case
    FieldToJson(jdata["IndexBuffer"], obj.IndexBuffer, options); // base case
    ; ///< @todo Generate for VertexBuffer[None]: D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_AABB& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MinX"], obj.MinX, options); // base case
    FieldToJson(jdata["MinY"], obj.MinY, options); // base case
    FieldToJson(jdata["MinZ"], obj.MinZ, options); // base case
    FieldToJson(jdata["MaxX"], obj.MaxX, options); // base case
    FieldToJson(jdata["MaxY"], obj.MaxY, options); // base case
    FieldToJson(jdata["MaxZ"], obj.MaxZ, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["AABBCount"], obj.AABBCount, options); // base case
    ; ///< @todo Generate for AABBs[None]: D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DestBuffer"], obj.DestBuffer, options); // base case
    FieldToJson(jdata["InfoType"], ToString(obj.InfoType), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["CompactedSizeInBytes"], obj.CompactedSizeInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DecodedSizeInBytes"], obj.DecodedSizeInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["NumDescs"], obj.NumDescs, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SerializedSizeInBytes"], obj.SerializedSizeInBytes, options); // base case
    FieldToJson(jdata["NumBottomLevelAccelerationStructurePointers"], obj.NumBottomLevelAccelerationStructurePointers, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for DriverOpaqueGUID[None]: GUID
    ; ///< @todo Generate for DriverOpaqueVersioningData[16]: BYTE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for DriverMatchingIdentifier[None]: D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER
    FieldToJson(jdata["SerializedSizeInBytesIncludingHeader"], obj.SerializedSizeInBytesIncludingHeader, options); // base case
    FieldToJson(jdata["DeserializedSizeInBytes"], obj.DeserializedSizeInBytes, options); // base case
    FieldToJson(jdata["NumBottomLevelAccelerationStructurePointersAfterHeader"], obj.NumBottomLevelAccelerationStructurePointersAfterHeader, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["CurrentSizeInBytes"], obj.CurrentSizeInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_INSTANCE_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Transform[12]: FLOAT
    FieldToJson(jdata["InstanceID"], obj.InstanceID, options); // base case
    FieldToJson(jdata["InstanceMask"], obj.InstanceMask, options); // base case
    FieldToJson(jdata["InstanceContributionToHitGroupIndex"], obj.InstanceContributionToHitGroupIndex, options); // base case
    FieldToJson(jdata["Flags"], obj.Flags, options); // base case
    FieldToJson(jdata["AccelerationStructure"], obj.AccelerationStructure, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata["NumDescs"], obj.NumDescs, options); // base case
    FieldToJson(jdata["DescsLayout"], ToString(obj.DescsLayout), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DestAccelerationStructureData"], obj.DestAccelerationStructureData, options); // base case
    ; ///< @todo Generate for Inputs[None]: D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS
    FieldToJson(jdata["SourceAccelerationStructureData"], obj.SourceAccelerationStructureData, options); // base case
    FieldToJson(jdata["ScratchAccelerationStructureData"], obj.ScratchAccelerationStructureData, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ResultDataMaxSizeInBytes"], obj.ResultDataMaxSizeInBytes, options); // base case
    FieldToJson(jdata["ScratchDataSizeInBytes"], obj.ScratchDataSizeInBytes, options); // base case
    FieldToJson(jdata["UpdateScratchDataSizeInBytes"], obj.UpdateScratchDataSizeInBytes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AUTO_BREADCRUMB_NODE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pCommandListDebugNameA[None]: char
    ; ///< @todo Generate for pCommandListDebugNameW[None]: wchar_t
    ; ///< @todo Generate for pCommandQueueDebugNameA[None]: char
    ; ///< @todo Generate for pCommandQueueDebugNameW[None]: wchar_t
    ; ///< @todo Generate for pCommandList[None]: ID3D12GraphicsCommandList
    ; ///< @todo Generate for pCommandQueue[None]: ID3D12CommandQueue
    FieldToJson(jdata["BreadcrumbCount"], obj.BreadcrumbCount, options); // base case
    ; ///< @todo Generate for pLastBreadcrumbValue[None]: UINT32
    ; ///< @todo Generate for pCommandHistory[BreadcrumbCount]: D3D12_AUTO_BREADCRUMB_OP
    ; ///< @todo Generate for pNext[None]: D3D12_AUTO_BREADCRUMB_NODE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_BREADCRUMB_CONTEXT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["BreadcrumbIndex"], obj.BreadcrumbIndex, options); // base case
    ; ///< @todo Generate for pContextString[None]: wchar_t
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AUTO_BREADCRUMB_NODE1& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pCommandListDebugNameA[None]: char
    ; ///< @todo Generate for pCommandListDebugNameW[None]: wchar_t
    ; ///< @todo Generate for pCommandQueueDebugNameA[None]: char
    ; ///< @todo Generate for pCommandQueueDebugNameW[None]: wchar_t
    ; ///< @todo Generate for pCommandList[None]: ID3D12GraphicsCommandList
    ; ///< @todo Generate for pCommandQueue[None]: ID3D12CommandQueue
    FieldToJson(jdata["BreadcrumbCount"], obj.BreadcrumbCount, options); // base case
    ; ///< @todo Generate for pLastBreadcrumbValue[None]: UINT
    ; ///< @todo Generate for pCommandHistory[BreadcrumbCount]: D3D12_AUTO_BREADCRUMB_OP
    ; ///< @todo Generate for pNext[None]: D3D12_AUTO_BREADCRUMB_NODE1
    FieldToJson(jdata["BreadcrumbContextsCount"], obj.BreadcrumbContextsCount, options); // base case
    ; ///< @todo Generate for pBreadcrumbContexts[BreadcrumbContextsCount]: D3D12_DRED_BREADCRUMB_CONTEXT
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_REMOVED_EXTENDED_DATA& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    ; ///< @todo Generate for pHeadAutoBreadcrumbNode[None]: D3D12_AUTO_BREADCRUMB_NODE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ALLOCATION_NODE& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for ObjectNameA[None]: char
    ; ///< @todo Generate for ObjectNameW[None]: wchar_t
    FieldToJson(jdata["AllocationType"], ToString(obj.AllocationType), options); // enum
    ; ///< @todo Generate for pNext[None]: D3D12_DRED_ALLOCATION_NODE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ALLOCATION_NODE1& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for ObjectNameA[None]: char
    ; ///< @todo Generate for ObjectNameW[None]: wchar_t
    FieldToJson(jdata["AllocationType"], ToString(obj.AllocationType), options); // enum
    ; ///< @todo Generate for pNext[None]: D3D12_DRED_ALLOCATION_NODE1
    ; ///< @todo Generate for pObject[None]: IUnknown
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pHeadAutoBreadcrumbNode[None]: D3D12_AUTO_BREADCRUMB_NODE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pHeadAutoBreadcrumbNode[None]: D3D12_AUTO_BREADCRUMB_NODE1
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_OUTPUT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["PageFaultVA"], obj.PageFaultVA, options); // base case
    ; ///< @todo Generate for pHeadExistingAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE
    ; ///< @todo Generate for pHeadRecentFreedAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_OUTPUT1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["PageFaultVA"], obj.PageFaultVA, options); // base case
    ; ///< @todo Generate for pHeadExistingAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1
    ; ///< @todo Generate for pHeadRecentFreedAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_OUTPUT2& obj, const JsonOptions& options)
{
    FieldToJson(jdata["PageFaultVA"], obj.PageFaultVA, options); // base case
    ; ///< @todo Generate for pHeadExistingAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1
    ; ///< @todo Generate for pHeadRecentFreedAllocationNode[None]: D3D12_DRED_ALLOCATION_NODE1
    FieldToJson(jdata["PageFaultFlags"], ToString(obj.PageFaultFlags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DeviceRemovedReason"], obj.DeviceRemovedReason, options); // base case
    ; ///< @todo Generate for AutoBreadcrumbsOutput[None]: D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT
    ; ///< @todo Generate for PageFaultOutput[None]: D3D12_DRED_PAGE_FAULT_OUTPUT
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DeviceRemovedReason"], obj.DeviceRemovedReason, options); // base case
    ; ///< @todo Generate for AutoBreadcrumbsOutput[None]: D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1
    ; ///< @todo Generate for PageFaultOutput[None]: D3D12_DRED_PAGE_FAULT_OUTPUT1
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& obj, const JsonOptions& options)
{
    FieldToJson(jdata["DeviceRemovedReason"], obj.DeviceRemovedReason, options); // base case
    ; ///< @todo Generate for AutoBreadcrumbsOutput[None]: D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1
    ; ///< @todo Generate for PageFaultOutput[None]: D3D12_DRED_PAGE_FAULT_OUTPUT2
    FieldToJson(jdata["DeviceState"], ToString(obj.DeviceState), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Version"], ToString(obj.Version), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NodeIndex"], obj.NodeIndex, options); // base case
    FieldToJson(jdata["Count"], obj.Count, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NodeIndex"], obj.NodeIndex, options); // base case
    FieldToJson(jdata["Count"], obj.Count, options); // base case
    ; ///< @todo Generate for pTypes[Count]: GUID
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NodeMask"], obj.NodeMask, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    ; ///< @todo Generate for ProtectionType[None]: GUID
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for ClearValue[None]: D3D12_CLEAR_VALUE
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["AdditionalWidth"], obj.AdditionalWidth, options); // base case
    FieldToJson(jdata["AdditionalHeight"], obj.AdditionalHeight, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SrcSubresource"], obj.SrcSubresource, options); // base case
    FieldToJson(jdata["DstSubresource"], obj.DstSubresource, options); // base case
    FieldToJson(jdata["DstX"], obj.DstX, options); // base case
    FieldToJson(jdata["DstY"], obj.DstY, options); // base case
    ; ///< @todo Generate for SrcRect[None]: tagRECT
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pSrcResource[None]: ID3D12Resource
    ; ///< @todo Generate for pDstResource[None]: ID3D12Resource
    FieldToJson(jdata["SubresourceCount"], obj.SubresourceCount, options); // base case
    ; ///< @todo Generate for pSubresourceParameters[SubresourceCount]: D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ResolveMode"], ToString(obj.ResolveMode), options); // enum
    FieldToJson(jdata["PreserveResolveSource"], obj.PreserveResolveSource, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["AdditionalWidth"], obj.AdditionalWidth, options); // base case
    FieldToJson(jdata["AdditionalHeight"], obj.AdditionalHeight, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata[""], obj., options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_RENDER_TARGET_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for cpuDescriptor[None]: D3D12_CPU_DESCRIPTOR_HANDLE
    ; ///< @todo Generate for BeginningAccess[None]: D3D12_RENDER_PASS_BEGINNING_ACCESS
    ; ///< @todo Generate for EndingAccess[None]: D3D12_RENDER_PASS_ENDING_ACCESS
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for cpuDescriptor[None]: D3D12_CPU_DESCRIPTOR_HANDLE
    ; ///< @todo Generate for DepthBeginningAccess[None]: D3D12_RENDER_PASS_BEGINNING_ACCESS
    ; ///< @todo Generate for StencilBeginningAccess[None]: D3D12_RENDER_PASS_BEGINNING_ACCESS
    ; ///< @todo Generate for DepthEndingAccess[None]: D3D12_RENDER_PASS_ENDING_ACCESS
    ; ///< @todo Generate for StencilEndingAccess[None]: D3D12_RENDER_PASS_ENDING_ACCESS
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_RAYS_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for RayGenerationShaderRecord[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE
    ; ///< @todo Generate for MissShaderTable[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE
    ; ///< @todo Generate for HitGroupTable[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE
    ; ///< @todo Generate for CallableShaderTable[None]: D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE
    FieldToJson(jdata["Width"], obj.Width, options); // base case
    FieldToJson(jdata["Height"], obj.Height, options); // base case
    FieldToJson(jdata["Depth"], obj.Depth, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_SESSION_DESC& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Identifier[None]: GUID
    FieldToJson(jdata["Mode"], ToString(obj.Mode), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata["MaximumInMemoryCacheSizeBytes"], obj.MaximumInMemoryCacheSizeBytes, options); // base case
    FieldToJson(jdata["MaximumInMemoryCacheEntries"], obj.MaximumInMemoryCacheEntries, options); // base case
    FieldToJson(jdata["MaximumValueFileSizeBytes"], obj.MaximumValueFileSizeBytes, options); // base case
    FieldToJson(jdata["Version"], obj.Version, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_SUBRESOURCE_RANGE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["IndexOrFirstMipLevel"], obj.IndexOrFirstMipLevel, options); // base case
    FieldToJson(jdata["NumMipLevels"], obj.NumMipLevels, options); // base case
    FieldToJson(jdata["FirstArraySlice"], obj.FirstArraySlice, options); // base case
    FieldToJson(jdata["NumArraySlices"], obj.NumArraySlices, options); // base case
    FieldToJson(jdata["FirstPlane"], obj.FirstPlane, options); // base case
    FieldToJson(jdata["NumPlanes"], obj.NumPlanes, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GLOBAL_BARRIER& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SyncBefore"], ToString(obj.SyncBefore), options); // enum
    FieldToJson(jdata["SyncAfter"], ToString(obj.SyncAfter), options); // enum
    FieldToJson(jdata["AccessBefore"], ToString(obj.AccessBefore), options); // enum
    FieldToJson(jdata["AccessAfter"], ToString(obj.AccessAfter), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_BARRIER& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SyncBefore"], ToString(obj.SyncBefore), options); // enum
    FieldToJson(jdata["SyncAfter"], ToString(obj.SyncAfter), options); // enum
    FieldToJson(jdata["AccessBefore"], ToString(obj.AccessBefore), options); // enum
    FieldToJson(jdata["AccessAfter"], ToString(obj.AccessAfter), options); // enum
    FieldToJson(jdata["LayoutBefore"], ToString(obj.LayoutBefore), options); // enum
    FieldToJson(jdata["LayoutAfter"], ToString(obj.LayoutAfter), options); // enum
    ; ///< @todo Generate for pResource[None]: ID3D12Resource
    ; ///< @todo Generate for Subresources[None]: D3D12_BARRIER_SUBRESOURCE_RANGE
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_BARRIER& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SyncBefore"], ToString(obj.SyncBefore), options); // enum
    FieldToJson(jdata["SyncAfter"], ToString(obj.SyncAfter), options); // enum
    FieldToJson(jdata["AccessBefore"], ToString(obj.AccessBefore), options); // enum
    FieldToJson(jdata["AccessAfter"], ToString(obj.AccessAfter), options); // enum
    ; ///< @todo Generate for pResource[None]: ID3D12Resource
    FieldToJson(jdata["Offset"], obj.Offset, options); // base case
    FieldToJson(jdata["Size"], obj.Size, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBRESOURCE_DATA& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pData[None]: void
    FieldToJson(jdata["RowPitch"], obj.RowPitch, options); // base case
    FieldToJson(jdata["SlicePitch"], obj.SlicePitch, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MEMCPY_DEST& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pData[None]: void
    FieldToJson(jdata["RowPitch"], obj.RowPitch, options); // base case
    FieldToJson(jdata["SlicePitch"], obj.SlicePitch, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_CONFIGURATION_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata["GpuBasedValidationFlags"], obj.GpuBasedValidationFlags, options); // base case
    FieldToJson(jdata["SDKVersion"], obj.SDKVersion, options); // base case
    FieldToJson(jdata["NumEnabledExperimentalFeatures"], obj.NumEnabledExperimentalFeatures, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_MESH_ARGUMENTS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ThreadGroupCountX"], obj.ThreadGroupCountX, options); // base case
    FieldToJson(jdata["ThreadGroupCountY"], obj.ThreadGroupCountY, options); // base case
    FieldToJson(jdata["ThreadGroupCountZ"], obj.ThreadGroupCountZ, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_MACRO& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for Name[None]: char
    ; ///< @todo Generate for Definition[None]: char
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["MaxMessagesPerCommandList"], obj.MaxMessagesPerCommandList, options); // base case
    FieldToJson(jdata["DefaultShaderPatchMode"], ToString(obj.DefaultShaderPatchMode), options); // enum
    FieldToJson(jdata["PipelineStateCreateFlags"], ToString(obj.PipelineStateCreateFlags), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& obj, const JsonOptions& options)
{
    FieldToJson(jdata["SlowdownFactor"], obj.SlowdownFactor, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ShaderPatchMode"], ToString(obj.ShaderPatchMode), options); // enum
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Category"], ToString(obj.Category), options); // enum
    FieldToJson(jdata["Severity"], ToString(obj.Severity), options); // enum
    FieldToJson(jdata["ID"], ToString(obj.ID), options); // enum
    ; ///< @todo Generate for pDescription[None]: char
    FieldToJson(jdata["DescriptionByteLength"], obj.DescriptionByteLength, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INFO_QUEUE_FILTER_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["NumCategories"], obj.NumCategories, options); // base case
    ; ///< @todo Generate for pCategoryList[NumCategories]: D3D12_MESSAGE_CATEGORY
    FieldToJson(jdata["NumSeverities"], obj.NumSeverities, options); // base case
    ; ///< @todo Generate for pSeverityList[NumSeverities]: D3D12_MESSAGE_SEVERITY
    FieldToJson(jdata["NumIDs"], obj.NumIDs, options); // base case
    ; ///< @todo Generate for pIDList[NumIDs]: D3D12_MESSAGE_ID
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INFO_QUEUE_FILTER& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for AllowList[None]: D3D12_INFO_QUEUE_FILTER_DESC
    ; ///< @todo Generate for DenyList[None]: D3D12_INFO_QUEUE_FILTER_DESC
}

void FieldToJson(nlohmann::ordered_json& jdata, const tagRECT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["left"], obj.left, options); // base case
    FieldToJson(jdata["top"], obj.top, options); // base case
    FieldToJson(jdata["right"], obj.right, options); // base case
    FieldToJson(jdata["bottom"], obj.bottom, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const tagPOINT& obj, const JsonOptions& options)
{
    FieldToJson(jdata["x"], obj.x, options); // base case
    FieldToJson(jdata["y"], obj.y, options); // base case
}

void FieldToJson(nlohmann::ordered_json& jdata, const _SECURITY_ATTRIBUTES& obj, const JsonOptions& options)
{
    FieldToJson(jdata["nLength"], obj.nLength, options); // base case
    ; ///< @todo Generate for lpSecurityDescriptor[None]: void
    FieldToJson(jdata["bInheritHandle"], obj.bInheritHandle, options); // base case
}

/// Put the custom implementations in the generator Python here rather than
/// creating a whole new compilation unit for them.
/// @note, not all of these may be needed for the convert tool if it uses the decoded struct
/// equivalents so complete the ones with todos as needed on-demand.

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CLEAR_VALUE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_COPY_LOCATION& obj, const JsonOptions& options)
{
    ; ///< @todo Generate for pResource[None]: ID3D12Resource
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_RESOURCE_VIEW_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
    FieldToJson(jdata["Shader4ComponentMapping"], obj.Shader4ComponentMapping, options); // base case
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_DESC2& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Filter"], ToString(obj.Filter), options); // enum
    FieldToJson(jdata["AddressU"], ToString(obj.AddressU), options); // enum
    FieldToJson(jdata["AddressV"], ToString(obj.AddressV), options); // enum
    FieldToJson(jdata["AddressW"], ToString(obj.AddressW), options); // enum
    FieldToJson(jdata["MipLODBias"], obj.MipLODBias, options); // base case
    FieldToJson(jdata["MaxAnisotropy"], obj.MaxAnisotropy, options); // base case
    FieldToJson(jdata["ComparisonFunc"], ToString(obj.ComparisonFunc), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    FieldToJson(jdata["MinLOD"], obj.MinLOD, options); // base case
    FieldToJson(jdata["MaxLOD"], obj.MaxLOD, options); // base case
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_UNORDERED_ACCESS_VIEW_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_TARGET_VIEW_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VIEW_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
    FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ParameterType"], ToString(obj.ParameterType), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    FieldToJson(jdata["ShaderVisibility"], ToString(obj.ShaderVisibility), options); // enum
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER1& obj, const JsonOptions& options)
{
    FieldToJson(jdata["ParameterType"], ToString(obj.ParameterType), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    FieldToJson(jdata["ShaderVisibility"], ToString(obj.ShaderVisibility), options); // enum
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Version"], ToString(obj.Version), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDIRECT_ARGUMENT_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_DESC& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
    FieldToJson(jdata["NumDescs"], obj.NumDescs, options); // base case
    FieldToJson(jdata["DescsLayout"], ToString(obj.DescsLayout), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Version"], ToString(obj.Version), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_GROUP& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
    FieldToJson(jdata["NumBarriers"], obj.NumBarriers, options); // base case
    /// @todo FieldToJson(jdata[""], obj., options); // base case
    GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \"" __FUNCTION__ "\"");
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
