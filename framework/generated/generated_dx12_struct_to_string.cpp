/*
** Copyright (c) 2021 LunarG, Inc.
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
** This file is generated from dx12_struct_to_string_body_generator.py.
**
*/

#include "generated_dx12_struct_to_string.h"
#include "decode/custom_dx12_ascii_consumer.h"
#include "decode/custom_dx12_to_string.h"
#include "generated_dx12_enum_to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

template <> std::string ToString<DXGI_FRAME_STATISTICS>(const DXGI_FRAME_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PresentCount", toStringFlags, tabCount, tabSize, ToString(obj.PresentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PresentRefreshCount", toStringFlags, tabCount, tabSize, ToString(obj.PresentRefreshCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SyncRefreshCount", toStringFlags, tabCount, tabSize, ToString(obj.SyncRefreshCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SyncQPCTime", toStringFlags, tabCount, tabSize, ToString(obj.SyncQPCTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SyncGPUTime", toStringFlags, tabCount, tabSize, ToString(obj.SyncGPUTime, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_MAPPED_RECT>(const DXGI_MAPPED_RECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Pitch", toStringFlags, tabCount, tabSize, ToString(obj.Pitch, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBits", toStringFlags, tabCount, tabSize, (obj.pBits ? ToString(*obj.pBits, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<LUID>(const LUID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "LowPart", toStringFlags, tabCount, tabSize, ToString(obj.LowPart, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HighPart", toStringFlags, tabCount, tabSize, ToString(obj.HighPart, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_ADAPTER_DESC>(const DXGI_ADAPTER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, '"' + WCharArrayToString(obj.Description) + '"');
            FieldToString(strStrm, false, "VendorId", toStringFlags, tabCount, tabSize, ToString(obj.VendorId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceId", toStringFlags, tabCount, tabSize, ToString(obj.DeviceId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SubSysId", toStringFlags, tabCount, tabSize, ToString(obj.SubSysId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Revision", toStringFlags, tabCount, tabSize, ToString(obj.Revision, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedVideoMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedVideoMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SharedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.SharedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, ToString(obj.AdapterLuid, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_OUTPUT_DESC>(const DXGI_OUTPUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceName", toStringFlags, tabCount, tabSize, '"' + WCharArrayToString(obj.DeviceName) + '"');
            FieldToString(strStrm, false, "DesktopCoordinates", toStringFlags, tabCount, tabSize, ToString(obj.DesktopCoordinates, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AttachedToDesktop", toStringFlags, tabCount, tabSize, ToString(obj.AttachedToDesktop, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Rotation", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Rotation, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Monitor", toStringFlags, tabCount, tabSize, HandleIdToString(obj.Monitor));
        }
    );
}

template <> std::string ToString<DXGI_SHARED_RESOURCE>(const DXGI_SHARED_RESOURCE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Handle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.Handle));
        }
    );
}

template <> std::string ToString<DXGI_SURFACE_DESC>(const DXGI_SURFACE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_SWAP_CHAIN_DESC>(const DXGI_SWAP_CHAIN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferDesc", toStringFlags, tabCount, tabSize, ToString(obj.BufferDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BufferUsage", toStringFlags, tabCount, tabSize, ToString(obj.BufferUsage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BufferCount", toStringFlags, tabCount, tabSize, ToString(obj.BufferCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputWindow", toStringFlags, tabCount, tabSize, HandleIdToString(obj.OutputWindow));
            FieldToString(strStrm, false, "Windowed", toStringFlags, tabCount, tabSize, ToString(obj.Windowed, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SwapEffect", toStringFlags, tabCount, tabSize, '"' + ToString(obj.SwapEffect, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_ADAPTER_DESC1>(const DXGI_ADAPTER_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, '"' + WCharArrayToString(obj.Description) + '"');
            FieldToString(strStrm, false, "VendorId", toStringFlags, tabCount, tabSize, ToString(obj.VendorId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceId", toStringFlags, tabCount, tabSize, ToString(obj.DeviceId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SubSysId", toStringFlags, tabCount, tabSize, ToString(obj.SubSysId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Revision", toStringFlags, tabCount, tabSize, ToString(obj.Revision, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedVideoMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedVideoMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SharedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.SharedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, ToString(obj.AdapterLuid, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_OUTDUPL_MOVE_RECT>(const DXGI_OUTDUPL_MOVE_RECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SourcePoint", toStringFlags, tabCount, tabSize, ToString(obj.SourcePoint, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DestinationRect", toStringFlags, tabCount, tabSize, ToString(obj.DestinationRect, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_OUTDUPL_DESC>(const DXGI_OUTDUPL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ModeDesc", toStringFlags, tabCount, tabSize, ToString(obj.ModeDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Rotation", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Rotation, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "DesktopImageInSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.DesktopImageInSystemMemory, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_OUTDUPL_POINTER_POSITION>(const DXGI_OUTDUPL_POINTER_POSITION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Position", toStringFlags, tabCount, tabSize, ToString(obj.Position, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Visible", toStringFlags, tabCount, tabSize, ToString(obj.Visible, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_OUTDUPL_POINTER_SHAPE_INFO>(const DXGI_OUTDUPL_POINTER_SHAPE_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, ToString(obj.Type, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Pitch", toStringFlags, tabCount, tabSize, ToString(obj.Pitch, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HotSpot", toStringFlags, tabCount, tabSize, ToString(obj.HotSpot, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_OUTDUPL_FRAME_INFO>(const DXGI_OUTDUPL_FRAME_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "LastPresentTime", toStringFlags, tabCount, tabSize, ToString(obj.LastPresentTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "LastMouseUpdateTime", toStringFlags, tabCount, tabSize, ToString(obj.LastMouseUpdateTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AccumulatedFrames", toStringFlags, tabCount, tabSize, ToString(obj.AccumulatedFrames, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RectsCoalesced", toStringFlags, tabCount, tabSize, ToString(obj.RectsCoalesced, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ProtectedContentMaskedOut", toStringFlags, tabCount, tabSize, ToString(obj.ProtectedContentMaskedOut, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PointerPosition", toStringFlags, tabCount, tabSize, ToString(obj.PointerPosition, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TotalMetadataBufferSize", toStringFlags, tabCount, tabSize, ToString(obj.TotalMetadataBufferSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PointerShapeBufferSize", toStringFlags, tabCount, tabSize, ToString(obj.PointerShapeBufferSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_MODE_DESC1>(const DXGI_MODE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RefreshRate", toStringFlags, tabCount, tabSize, ToString(obj.RefreshRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ScanlineOrdering", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ScanlineOrdering, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Scaling, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Stereo", toStringFlags, tabCount, tabSize, ToString(obj.Stereo, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_SWAP_CHAIN_DESC1>(const DXGI_SWAP_CHAIN_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Stereo", toStringFlags, tabCount, tabSize, ToString(obj.Stereo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BufferUsage", toStringFlags, tabCount, tabSize, ToString(obj.BufferUsage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BufferCount", toStringFlags, tabCount, tabSize, ToString(obj.BufferCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Scaling, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "SwapEffect", toStringFlags, tabCount, tabSize, '"' + ToString(obj.SwapEffect, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "AlphaMode", toStringFlags, tabCount, tabSize, '"' + ToString(obj.AlphaMode, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_SWAP_CHAIN_FULLSCREEN_DESC>(const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RefreshRate", toStringFlags, tabCount, tabSize, ToString(obj.RefreshRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ScanlineOrdering", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ScanlineOrdering, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Scaling, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Windowed", toStringFlags, tabCount, tabSize, ToString(obj.Windowed, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_PRESENT_PARAMETERS>(const DXGI_PRESENT_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DirtyRectsCount", toStringFlags, tabCount, tabSize, ToString(obj.DirtyRectsCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDirtyRects", toStringFlags, tabCount, tabSize, ArrayToString(obj.DirtyRectsCount, obj.pDirtyRects, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pScrollRect", toStringFlags, tabCount, tabSize, (obj.pScrollRect ? ToString(*obj.pScrollRect, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pScrollOffset", toStringFlags, tabCount, tabSize, (obj.pScrollOffset ? ToString(*obj.pScrollOffset, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<DXGI_ADAPTER_DESC2>(const DXGI_ADAPTER_DESC2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, '"' + WCharArrayToString(obj.Description) + '"');
            FieldToString(strStrm, false, "VendorId", toStringFlags, tabCount, tabSize, ToString(obj.VendorId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceId", toStringFlags, tabCount, tabSize, ToString(obj.DeviceId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SubSysId", toStringFlags, tabCount, tabSize, ToString(obj.SubSysId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Revision", toStringFlags, tabCount, tabSize, ToString(obj.Revision, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedVideoMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedVideoMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SharedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.SharedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, ToString(obj.AdapterLuid, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "GraphicsPreemptionGranularity", toStringFlags, tabCount, tabSize, '"' + ToString(obj.GraphicsPreemptionGranularity, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ComputePreemptionGranularity", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ComputePreemptionGranularity, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<DXGI_MATRIX_3X2_F>(const DXGI_MATRIX_3X2_F& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "_11", toStringFlags, tabCount, tabSize, ToString(obj._11, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "_12", toStringFlags, tabCount, tabSize, ToString(obj._12, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "_21", toStringFlags, tabCount, tabSize, ToString(obj._21, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "_22", toStringFlags, tabCount, tabSize, ToString(obj._22, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "_31", toStringFlags, tabCount, tabSize, ToString(obj._31, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "_32", toStringFlags, tabCount, tabSize, ToString(obj._32, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_DECODE_SWAP_CHAIN_DESC>(const DXGI_DECODE_SWAP_CHAIN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_FRAME_STATISTICS_MEDIA>(const DXGI_FRAME_STATISTICS_MEDIA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PresentCount", toStringFlags, tabCount, tabSize, ToString(obj.PresentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PresentRefreshCount", toStringFlags, tabCount, tabSize, ToString(obj.PresentRefreshCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SyncRefreshCount", toStringFlags, tabCount, tabSize, ToString(obj.SyncRefreshCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SyncQPCTime", toStringFlags, tabCount, tabSize, ToString(obj.SyncQPCTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SyncGPUTime", toStringFlags, tabCount, tabSize, ToString(obj.SyncGPUTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CompositionMode", toStringFlags, tabCount, tabSize, '"' + ToString(obj.CompositionMode, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ApprovedPresentDuration", toStringFlags, tabCount, tabSize, ToString(obj.ApprovedPresentDuration, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_QUERY_VIDEO_MEMORY_INFO>(const DXGI_QUERY_VIDEO_MEMORY_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Budget", toStringFlags, tabCount, tabSize, ToString(obj.Budget, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CurrentUsage", toStringFlags, tabCount, tabSize, ToString(obj.CurrentUsage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AvailableForReservation", toStringFlags, tabCount, tabSize, ToString(obj.AvailableForReservation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CurrentReservation", toStringFlags, tabCount, tabSize, ToString(obj.CurrentReservation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_HDR_METADATA_HDR10>(const DXGI_HDR_METADATA_HDR10& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RedPrimary", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.RedPrimary, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "GreenPrimary", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.GreenPrimary, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BluePrimary", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.BluePrimary, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WhitePoint", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.WhitePoint, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxMasteringLuminance", toStringFlags, tabCount, tabSize, ToString(obj.MaxMasteringLuminance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinMasteringLuminance", toStringFlags, tabCount, tabSize, ToString(obj.MinMasteringLuminance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxContentLightLevel", toStringFlags, tabCount, tabSize, ToString(obj.MaxContentLightLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxFrameAverageLightLevel", toStringFlags, tabCount, tabSize, ToString(obj.MaxFrameAverageLightLevel, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_HDR_METADATA_HDR10PLUS>(const DXGI_HDR_METADATA_HDR10PLUS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Data", toStringFlags, tabCount, tabSize, ArrayToString(72, obj.Data, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_ADAPTER_DESC3>(const DXGI_ADAPTER_DESC3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, '"' + WCharArrayToString(obj.Description) + '"');
            FieldToString(strStrm, false, "VendorId", toStringFlags, tabCount, tabSize, ToString(obj.VendorId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceId", toStringFlags, tabCount, tabSize, ToString(obj.DeviceId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SubSysId", toStringFlags, tabCount, tabSize, ToString(obj.SubSysId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Revision", toStringFlags, tabCount, tabSize, ToString(obj.Revision, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedVideoMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedVideoMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SharedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.SharedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, ToString(obj.AdapterLuid, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "GraphicsPreemptionGranularity", toStringFlags, tabCount, tabSize, '"' + ToString(obj.GraphicsPreemptionGranularity, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ComputePreemptionGranularity", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ComputePreemptionGranularity, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<DXGI_OUTPUT_DESC1>(const DXGI_OUTPUT_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceName", toStringFlags, tabCount, tabSize, '"' + WCharArrayToString(obj.DeviceName) + '"');
            FieldToString(strStrm, false, "DesktopCoordinates", toStringFlags, tabCount, tabSize, ToString(obj.DesktopCoordinates, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AttachedToDesktop", toStringFlags, tabCount, tabSize, ToString(obj.AttachedToDesktop, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Rotation", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Rotation, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Monitor", toStringFlags, tabCount, tabSize, HandleIdToString(obj.Monitor));
            FieldToString(strStrm, false, "BitsPerColor", toStringFlags, tabCount, tabSize, ToString(obj.BitsPerColor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ColorSpace", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ColorSpace, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "RedPrimary", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.RedPrimary, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "GreenPrimary", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.GreenPrimary, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BluePrimary", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.BluePrimary, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WhitePoint", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.WhitePoint, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinLuminance", toStringFlags, tabCount, tabSize, ToString(obj.MinLuminance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxLuminance", toStringFlags, tabCount, tabSize, ToString(obj.MaxLuminance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxFullFrameLuminance", toStringFlags, tabCount, tabSize, ToString(obj.MaxFullFrameLuminance, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_RATIONAL>(const DXGI_RATIONAL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Numerator", toStringFlags, tabCount, tabSize, ToString(obj.Numerator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Denominator", toStringFlags, tabCount, tabSize, ToString(obj.Denominator, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_SAMPLE_DESC>(const DXGI_SAMPLE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Count", toStringFlags, tabCount, tabSize, ToString(obj.Count, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Quality", toStringFlags, tabCount, tabSize, ToString(obj.Quality, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_RGB>(const DXGI_RGB& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Red", toStringFlags, tabCount, tabSize, ToString(obj.Red, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Green", toStringFlags, tabCount, tabSize, ToString(obj.Green, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Blue", toStringFlags, tabCount, tabSize, ToString(obj.Blue, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3DCOLORVALUE>(const D3DCOLORVALUE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "r", toStringFlags, tabCount, tabSize, ToString(obj.r, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "g", toStringFlags, tabCount, tabSize, ToString(obj.g, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "b", toStringFlags, tabCount, tabSize, ToString(obj.b, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "a", toStringFlags, tabCount, tabSize, ToString(obj.a, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_GAMMA_CONTROL>(const DXGI_GAMMA_CONTROL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Scale", toStringFlags, tabCount, tabSize, ToString(obj.Scale, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Offset", toStringFlags, tabCount, tabSize, ToString(obj.Offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "GammaCurve", toStringFlags, tabCount, tabSize, ArrayToString(1025, obj.GammaCurve, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_GAMMA_CONTROL_CAPABILITIES>(const DXGI_GAMMA_CONTROL_CAPABILITIES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ScaleAndOffsetSupported", toStringFlags, tabCount, tabSize, ToString(obj.ScaleAndOffsetSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxConvertedValue", toStringFlags, tabCount, tabSize, ToString(obj.MaxConvertedValue, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinConvertedValue", toStringFlags, tabCount, tabSize, ToString(obj.MinConvertedValue, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumGammaControlPoints", toStringFlags, tabCount, tabSize, ToString(obj.NumGammaControlPoints, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ControlPointPositions", toStringFlags, tabCount, tabSize, ArrayToString(1025, obj.ControlPointPositions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_MODE_DESC>(const DXGI_MODE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RefreshRate", toStringFlags, tabCount, tabSize, ToString(obj.RefreshRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ScanlineOrdering", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ScanlineOrdering, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Scaling, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<DXGI_JPEG_DC_HUFFMAN_TABLE>(const DXGI_JPEG_DC_HUFFMAN_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CodeCounts", toStringFlags, tabCount, tabSize, ArrayToString(12, obj.CodeCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CodeValues", toStringFlags, tabCount, tabSize, ArrayToString(12, obj.CodeValues, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_JPEG_AC_HUFFMAN_TABLE>(const DXGI_JPEG_AC_HUFFMAN_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CodeCounts", toStringFlags, tabCount, tabSize, ArrayToString(16, obj.CodeCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CodeValues", toStringFlags, tabCount, tabSize, ArrayToString(162, obj.CodeValues, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<DXGI_JPEG_QUANTIZATION_TABLE>(const DXGI_JPEG_QUANTIZATION_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Elements", toStringFlags, tabCount, tabSize, ArrayToString(64, obj.Elements, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_COMMAND_QUEUE_DESC>(const D3D12_COMMAND_QUEUE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Priority", toStringFlags, tabCount, tabSize, ToString(obj.Priority, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_INPUT_ELEMENT_DESC>(const D3D12_INPUT_ELEMENT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SemanticName", toStringFlags, tabCount, tabSize, (obj.SemanticName ? ToString(*obj.SemanticName, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "SemanticIndex", toStringFlags, tabCount, tabSize, ToString(obj.SemanticIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "InputSlot", toStringFlags, tabCount, tabSize, ToString(obj.InputSlot, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AlignedByteOffset", toStringFlags, tabCount, tabSize, ToString(obj.AlignedByteOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InputSlotClass", toStringFlags, tabCount, tabSize, '"' + ToString(obj.InputSlotClass, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "InstanceDataStepRate", toStringFlags, tabCount, tabSize, ToString(obj.InstanceDataStepRate, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_SO_DECLARATION_ENTRY>(const D3D12_SO_DECLARATION_ENTRY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Stream", toStringFlags, tabCount, tabSize, ToString(obj.Stream, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SemanticName", toStringFlags, tabCount, tabSize, (obj.SemanticName ? ToString(*obj.SemanticName, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "SemanticIndex", toStringFlags, tabCount, tabSize, ToString(obj.SemanticIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StartComponent", toStringFlags, tabCount, tabSize, ToString(obj.StartComponent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ComponentCount", toStringFlags, tabCount, tabSize, ToString(obj.ComponentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputSlot", toStringFlags, tabCount, tabSize, ToString(obj.OutputSlot, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_VIEWPORT>(const D3D12_VIEWPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "TopLeftX", toStringFlags, tabCount, tabSize, ToString(obj.TopLeftX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TopLeftY", toStringFlags, tabCount, tabSize, ToString(obj.TopLeftY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinDepth", toStringFlags, tabCount, tabSize, ToString(obj.MinDepth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxDepth", toStringFlags, tabCount, tabSize, ToString(obj.MaxDepth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_BOX>(const D3D12_BOX& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "left", toStringFlags, tabCount, tabSize, ToString(obj.left, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "top", toStringFlags, tabCount, tabSize, ToString(obj.top, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "front", toStringFlags, tabCount, tabSize, ToString(obj.front, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "right", toStringFlags, tabCount, tabSize, ToString(obj.right, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bottom", toStringFlags, tabCount, tabSize, ToString(obj.bottom, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "back", toStringFlags, tabCount, tabSize, ToString(obj.back, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DEPTH_STENCILOP_DESC>(const D3D12_DEPTH_STENCILOP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StencilFailOp", toStringFlags, tabCount, tabSize, '"' + ToString(obj.StencilFailOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "StencilDepthFailOp", toStringFlags, tabCount, tabSize, '"' + ToString(obj.StencilDepthFailOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "StencilPassOp", toStringFlags, tabCount, tabSize, '"' + ToString(obj.StencilPassOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "StencilFunc", toStringFlags, tabCount, tabSize, '"' + ToString(obj.StencilFunc, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_DEPTH_STENCIL_DESC>(const D3D12_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthWriteMask", toStringFlags, tabCount, tabSize, '"' + ToString(obj.DepthWriteMask, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "DepthFunc", toStringFlags, tabCount, tabSize, '"' + ToString(obj.DepthFunc, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "StencilEnable", toStringFlags, tabCount, tabSize, ToString(obj.StencilEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilReadMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilReadMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilWriteMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FrontFace", toStringFlags, tabCount, tabSize, ToString(obj.FrontFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BackFace", toStringFlags, tabCount, tabSize, ToString(obj.BackFace, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DEPTH_STENCIL_DESC1>(const D3D12_DEPTH_STENCIL_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthWriteMask", toStringFlags, tabCount, tabSize, '"' + ToString(obj.DepthWriteMask, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "DepthFunc", toStringFlags, tabCount, tabSize, '"' + ToString(obj.DepthFunc, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "StencilEnable", toStringFlags, tabCount, tabSize, ToString(obj.StencilEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilReadMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilReadMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilWriteMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FrontFace", toStringFlags, tabCount, tabSize, ToString(obj.FrontFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BackFace", toStringFlags, tabCount, tabSize, ToString(obj.BackFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBoundsTestEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthBoundsTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_TARGET_BLEND_DESC>(const D3D12_RENDER_TARGET_BLEND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BlendEnable", toStringFlags, tabCount, tabSize, ToString(obj.BlendEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "LogicOpEnable", toStringFlags, tabCount, tabSize, ToString(obj.LogicOpEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SrcBlend", toStringFlags, tabCount, tabSize, '"' + ToString(obj.SrcBlend, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "DestBlend", toStringFlags, tabCount, tabSize, '"' + ToString(obj.DestBlend, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "BlendOp", toStringFlags, tabCount, tabSize, '"' + ToString(obj.BlendOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "SrcBlendAlpha", toStringFlags, tabCount, tabSize, '"' + ToString(obj.SrcBlendAlpha, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "DestBlendAlpha", toStringFlags, tabCount, tabSize, '"' + ToString(obj.DestBlendAlpha, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "BlendOpAlpha", toStringFlags, tabCount, tabSize, '"' + ToString(obj.BlendOpAlpha, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "LogicOp", toStringFlags, tabCount, tabSize, '"' + ToString(obj.LogicOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "RenderTargetWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.RenderTargetWriteMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_BLEND_DESC>(const D3D12_BLEND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AlphaToCoverageEnable", toStringFlags, tabCount, tabSize, ToString(obj.AlphaToCoverageEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "IndependentBlendEnable", toStringFlags, tabCount, tabSize, ToString(obj.IndependentBlendEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RenderTarget", toStringFlags, tabCount, tabSize, ArrayToString(8, obj.RenderTarget, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RASTERIZER_DESC>(const D3D12_RASTERIZER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FillMode", toStringFlags, tabCount, tabSize, '"' + ToString(obj.FillMode, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "CullMode", toStringFlags, tabCount, tabSize, '"' + ToString(obj.CullMode, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "FrontCounterClockwise", toStringFlags, tabCount, tabSize, ToString(obj.FrontCounterClockwise, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBias", toStringFlags, tabCount, tabSize, ToString(obj.DepthBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBiasClamp", toStringFlags, tabCount, tabSize, ToString(obj.DepthBiasClamp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SlopeScaledDepthBias", toStringFlags, tabCount, tabSize, ToString(obj.SlopeScaledDepthBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthClipEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthClipEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MultisampleEnable", toStringFlags, tabCount, tabSize, ToString(obj.MultisampleEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AntialiasedLineEnable", toStringFlags, tabCount, tabSize, ToString(obj.AntialiasedLineEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ForcedSampleCount", toStringFlags, tabCount, tabSize, ToString(obj.ForcedSampleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConservativeRaster", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ConservativeRaster, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_SHADER_BYTECODE>(const D3D12_SHADER_BYTECODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pShaderBytecode", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pShaderBytecode));
            FieldToString(strStrm, false, "BytecodeLength", toStringFlags, tabCount, tabSize, ToString(obj.BytecodeLength, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_STREAM_OUTPUT_DESC>(const D3D12_STREAM_OUTPUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pSODeclaration", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumEntries, obj.pSODeclaration, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumEntries", toStringFlags, tabCount, tabSize, ToString(obj.NumEntries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBufferStrides", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumStrides, obj.pBufferStrides, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumStrides", toStringFlags, tabCount, tabSize, ToString(obj.NumStrides, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RasterizedStream", toStringFlags, tabCount, tabSize, ToString(obj.RasterizedStream, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_INPUT_LAYOUT_DESC>(const D3D12_INPUT_LAYOUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pInputElementDescs", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumElements, obj.pInputElementDescs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, ToString(obj.NumElements, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_CACHED_PIPELINE_STATE>(const D3D12_CACHED_PIPELINE_STATE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pCachedBlob", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pCachedBlob));
            FieldToString(strStrm, false, "CachedBlobSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.CachedBlobSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_GRAPHICS_PIPELINE_STATE_DESC>(const D3D12_GRAPHICS_PIPELINE_STATE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pRootSignature", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pRootSignature));
            FieldToString(strStrm, false, "VS", toStringFlags, tabCount, tabSize, ToString(obj.VS, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PS", toStringFlags, tabCount, tabSize, ToString(obj.PS, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DS", toStringFlags, tabCount, tabSize, ToString(obj.DS, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HS", toStringFlags, tabCount, tabSize, ToString(obj.HS, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "GS", toStringFlags, tabCount, tabSize, ToString(obj.GS, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StreamOutput", toStringFlags, tabCount, tabSize, ToString(obj.StreamOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BlendState", toStringFlags, tabCount, tabSize, ToString(obj.BlendState, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SampleMask", toStringFlags, tabCount, tabSize, ToString(obj.SampleMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RasterizerState", toStringFlags, tabCount, tabSize, ToString(obj.RasterizerState, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthStencilState", toStringFlags, tabCount, tabSize, ToString(obj.DepthStencilState, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InputLayout", toStringFlags, tabCount, tabSize, ToString(obj.InputLayout, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "IBStripCutValue", toStringFlags, tabCount, tabSize, '"' + ToString(obj.IBStripCutValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "PrimitiveTopologyType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.PrimitiveTopologyType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "NumRenderTargets", toStringFlags, tabCount, tabSize, ToString(obj.NumRenderTargets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RTVFormats", toStringFlags, tabCount, tabSize, ArrayToString(8, obj.RTVFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DSVFormat", toStringFlags, tabCount, tabSize, '"' + ToString(obj.DSVFormat, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CachedPSO", toStringFlags, tabCount, tabSize, ToString(obj.CachedPSO, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_COMPUTE_PIPELINE_STATE_DESC>(const D3D12_COMPUTE_PIPELINE_STATE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pRootSignature", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pRootSignature));
            FieldToString(strStrm, false, "CS", toStringFlags, tabCount, tabSize, ToString(obj.CS, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CachedPSO", toStringFlags, tabCount, tabSize, ToString(obj.CachedPSO, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_RT_FORMAT_ARRAY>(const D3D12_RT_FORMAT_ARRAY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RTFormats", toStringFlags, tabCount, tabSize, ArrayToString(8, obj.RTFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumRenderTargets", toStringFlags, tabCount, tabSize, ToString(obj.NumRenderTargets, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS>(const D3D12_FEATURE_DATA_D3D12_OPTIONS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DoublePrecisionFloatShaderOps", toStringFlags, tabCount, tabSize, ToString(obj.DoublePrecisionFloatShaderOps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputMergerLogicOp", toStringFlags, tabCount, tabSize, ToString(obj.OutputMergerLogicOp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinPrecisionSupport", toStringFlags, tabCount, tabSize, '"' + ToString(obj.MinPrecisionSupport, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "TiledResourcesTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.TiledResourcesTier, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ResourceBindingTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ResourceBindingTier, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "PSSpecifiedStencilRefSupported", toStringFlags, tabCount, tabSize, ToString(obj.PSSpecifiedStencilRefSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TypedUAVLoadAdditionalFormats", toStringFlags, tabCount, tabSize, ToString(obj.TypedUAVLoadAdditionalFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ROVsSupported", toStringFlags, tabCount, tabSize, ToString(obj.ROVsSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConservativeRasterizationTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ConservativeRasterizationTier, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "MaxGPUVirtualAddressBitsPerResource", toStringFlags, tabCount, tabSize, ToString(obj.MaxGPUVirtualAddressBitsPerResource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StandardSwizzle64KBSupported", toStringFlags, tabCount, tabSize, ToString(obj.StandardSwizzle64KBSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CrossNodeSharingTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.CrossNodeSharingTier, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "CrossAdapterRowMajorTextureSupported", toStringFlags, tabCount, tabSize, ToString(obj.CrossAdapterRowMajorTextureSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation", toStringFlags, tabCount, tabSize, ToString(obj.VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ResourceHeapTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ResourceHeapTier, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS1>(const D3D12_FEATURE_DATA_D3D12_OPTIONS1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "WaveOps", toStringFlags, tabCount, tabSize, ToString(obj.WaveOps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WaveLaneCountMin", toStringFlags, tabCount, tabSize, ToString(obj.WaveLaneCountMin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WaveLaneCountMax", toStringFlags, tabCount, tabSize, ToString(obj.WaveLaneCountMax, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TotalLaneCount", toStringFlags, tabCount, tabSize, ToString(obj.TotalLaneCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ExpandedComputeResourceStates", toStringFlags, tabCount, tabSize, ToString(obj.ExpandedComputeResourceStates, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Int64ShaderOps", toStringFlags, tabCount, tabSize, ToString(obj.Int64ShaderOps, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS2>(const D3D12_FEATURE_DATA_D3D12_OPTIONS2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthBoundsTestSupported", toStringFlags, tabCount, tabSize, ToString(obj.DepthBoundsTestSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ProgrammableSamplePositionsTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ProgrammableSamplePositionsTier, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_ROOT_SIGNATURE>(const D3D12_FEATURE_DATA_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "HighestVersion", toStringFlags, tabCount, tabSize, '"' + ToString(obj.HighestVersion, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_ARCHITECTURE>(const D3D12_FEATURE_DATA_ARCHITECTURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, ToString(obj.NodeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TileBasedRenderer", toStringFlags, tabCount, tabSize, ToString(obj.TileBasedRenderer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "UMA", toStringFlags, tabCount, tabSize, ToString(obj.UMA, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CacheCoherentUMA", toStringFlags, tabCount, tabSize, ToString(obj.CacheCoherentUMA, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_ARCHITECTURE1>(const D3D12_FEATURE_DATA_ARCHITECTURE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, ToString(obj.NodeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TileBasedRenderer", toStringFlags, tabCount, tabSize, ToString(obj.TileBasedRenderer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "UMA", toStringFlags, tabCount, tabSize, ToString(obj.UMA, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CacheCoherentUMA", toStringFlags, tabCount, tabSize, ToString(obj.CacheCoherentUMA, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "IsolatedMMU", toStringFlags, tabCount, tabSize, ToString(obj.IsolatedMMU, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_FEATURE_LEVELS>(const D3D12_FEATURE_DATA_FEATURE_LEVELS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumFeatureLevels", toStringFlags, tabCount, tabSize, ToString(obj.NumFeatureLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFeatureLevelsRequested", toStringFlags, tabCount, tabSize, EnumArrayToString(obj.NumFeatureLevels, obj.pFeatureLevelsRequested, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxSupportedFeatureLevel", toStringFlags, tabCount, tabSize, '"' + ToString(obj.MaxSupportedFeatureLevel, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_SHADER_MODEL>(const D3D12_FEATURE_DATA_SHADER_MODEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "HighestShaderModel", toStringFlags, tabCount, tabSize, '"' + ToString(obj.HighestShaderModel, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_FORMAT_SUPPORT>(const D3D12_FEATURE_DATA_FORMAT_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Support1", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Support1, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Support2", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Support2, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS>(const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "SampleCount", toStringFlags, tabCount, tabSize, ToString(obj.SampleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "NumQualityLevels", toStringFlags, tabCount, tabSize, ToString(obj.NumQualityLevels, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_FORMAT_INFO>(const D3D12_FEATURE_DATA_FORMAT_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "PlaneCount", toStringFlags, tabCount, tabSize, ToString(obj.PlaneCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT>(const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxGPUVirtualAddressBitsPerResource", toStringFlags, tabCount, tabSize, ToString(obj.MaxGPUVirtualAddressBitsPerResource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxGPUVirtualAddressBitsPerProcess", toStringFlags, tabCount, tabSize, ToString(obj.MaxGPUVirtualAddressBitsPerProcess, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_SHADER_CACHE>(const D3D12_FEATURE_DATA_SHADER_CACHE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SupportFlags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.SupportFlags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY>(const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CommandListType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.CommandListType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Priority", toStringFlags, tabCount, tabSize, ToString(obj.Priority, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PriorityForTypeIsSupported", toStringFlags, tabCount, tabSize, ToString(obj.PriorityForTypeIsSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS3>(const D3D12_FEATURE_DATA_D3D12_OPTIONS3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CopyQueueTimestampQueriesSupported", toStringFlags, tabCount, tabSize, ToString(obj.CopyQueueTimestampQueriesSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CastingFullyTypedFormatSupported", toStringFlags, tabCount, tabSize, ToString(obj.CastingFullyTypedFormatSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WriteBufferImmediateSupportFlags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.WriteBufferImmediateSupportFlags, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ViewInstancingTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewInstancingTier, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "BarycentricsSupported", toStringFlags, tabCount, tabSize, ToString(obj.BarycentricsSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_EXISTING_HEAPS>(const D3D12_FEATURE_DATA_EXISTING_HEAPS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Supported", toStringFlags, tabCount, tabSize, ToString(obj.Supported, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS4>(const D3D12_FEATURE_DATA_D3D12_OPTIONS4& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MSAA64KBAlignedTextureSupported", toStringFlags, tabCount, tabSize, ToString(obj.MSAA64KBAlignedTextureSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SharedResourceCompatibilityTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.SharedResourceCompatibilityTier, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Native16BitShaderOpsSupported", toStringFlags, tabCount, tabSize, ToString(obj.Native16BitShaderOpsSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_SERIALIZATION>(const D3D12_FEATURE_DATA_SERIALIZATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, ToString(obj.NodeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HeapSerializationTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.HeapSerializationTier, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_CROSS_NODE>(const D3D12_FEATURE_DATA_CROSS_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SharingTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.SharingTier, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "AtomicShaderInstructions", toStringFlags, tabCount, tabSize, ToString(obj.AtomicShaderInstructions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS5>(const D3D12_FEATURE_DATA_D3D12_OPTIONS5& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SRVOnlyTiledResourceTier3", toStringFlags, tabCount, tabSize, ToString(obj.SRVOnlyTiledResourceTier3, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RenderPassesTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.RenderPassesTier, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "RaytracingTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.RaytracingTier, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS6>(const D3D12_FEATURE_DATA_D3D12_OPTIONS6& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AdditionalShadingRatesSupported", toStringFlags, tabCount, tabSize, ToString(obj.AdditionalShadingRatesSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PerPrimitiveShadingRateSupportedWithViewportIndexing", toStringFlags, tabCount, tabSize, ToString(obj.PerPrimitiveShadingRateSupportedWithViewportIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VariableShadingRateTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.VariableShadingRateTier, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ShadingRateImageTileSize", toStringFlags, tabCount, tabSize, ToString(obj.ShadingRateImageTileSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BackgroundProcessingSupported", toStringFlags, tabCount, tabSize, ToString(obj.BackgroundProcessingSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS7>(const D3D12_FEATURE_DATA_D3D12_OPTIONS7& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MeshShaderTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.MeshShaderTier, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "SamplerFeedbackTier", toStringFlags, tabCount, tabSize, '"' + ToString(obj.SamplerFeedbackTier, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_QUERY_META_COMMAND>(const D3D12_FEATURE_DATA_QUERY_META_COMMAND& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CommandId", toStringFlags, tabCount, tabSize, ToString(obj.CommandId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueryInputData", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pQueryInputData));
            FieldToString(strStrm, false, "QueryInputDataSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.QueryInputDataSizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueryOutputData", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pQueryOutputData));
            FieldToString(strStrm, false, "QueryOutputDataSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.QueryOutputDataSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_ALLOCATION_INFO>(const D3D12_RESOURCE_ALLOCATION_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, ToString(obj.Alignment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_ALLOCATION_INFO1>(const D3D12_RESOURCE_ALLOCATION_INFO1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Offset", toStringFlags, tabCount, tabSize, ToString(obj.Offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, ToString(obj.Alignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_HEAP_PROPERTIES>(const D3D12_HEAP_PROPERTIES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "CPUPageProperty", toStringFlags, tabCount, tabSize, '"' + ToString(obj.CPUPageProperty, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "MemoryPoolPreference", toStringFlags, tabCount, tabSize, '"' + ToString(obj.MemoryPoolPreference, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "CreationNodeMask", toStringFlags, tabCount, tabSize, ToString(obj.CreationNodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VisibleNodeMask", toStringFlags, tabCount, tabSize, ToString(obj.VisibleNodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_HEAP_DESC>(const D3D12_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Properties", toStringFlags, tabCount, tabSize, ToString(obj.Properties, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, ToString(obj.Alignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_MIP_REGION>(const D3D12_MIP_REGION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, ToString(obj.Depth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_DESC>(const D3D12_RESOURCE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Dimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Dimension, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, ToString(obj.Alignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthOrArraySize", toStringFlags, tabCount, tabSize, ToString(obj.DepthOrArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Layout", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Layout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_DESC1>(const D3D12_RESOURCE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Dimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Dimension, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, ToString(obj.Alignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthOrArraySize", toStringFlags, tabCount, tabSize, ToString(obj.DepthOrArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Layout", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Layout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "SamplerFeedbackMipRegion", toStringFlags, tabCount, tabSize, ToString(obj.SamplerFeedbackMipRegion, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DEPTH_STENCIL_VALUE>(const D3D12_DEPTH_STENCIL_VALUE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Depth", toStringFlags, tabCount, tabSize, ToString(obj.Depth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Stencil", toStringFlags, tabCount, tabSize, ToString(obj.Stencil, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RANGE>(const D3D12_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Begin", toStringFlags, tabCount, tabSize, ToString(obj.Begin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "End", toStringFlags, tabCount, tabSize, ToString(obj.End, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RANGE_UINT64>(const D3D12_RANGE_UINT64& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Begin", toStringFlags, tabCount, tabSize, ToString(obj.Begin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "End", toStringFlags, tabCount, tabSize, ToString(obj.End, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_SUBRESOURCE_RANGE_UINT64>(const D3D12_SUBRESOURCE_RANGE_UINT64& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Subresource", toStringFlags, tabCount, tabSize, ToString(obj.Subresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Range", toStringFlags, tabCount, tabSize, ToString(obj.Range, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_SUBRESOURCE_INFO>(const D3D12_SUBRESOURCE_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Offset", toStringFlags, tabCount, tabSize, ToString(obj.Offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RowPitch", toStringFlags, tabCount, tabSize, ToString(obj.RowPitch, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthPitch", toStringFlags, tabCount, tabSize, ToString(obj.DepthPitch, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TILED_RESOURCE_COORDINATE>(const D3D12_TILED_RESOURCE_COORDINATE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "X", toStringFlags, tabCount, tabSize, ToString(obj.X, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Y", toStringFlags, tabCount, tabSize, ToString(obj.Y, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Z", toStringFlags, tabCount, tabSize, ToString(obj.Z, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, ToString(obj.Subresource, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TILE_REGION_SIZE>(const D3D12_TILE_REGION_SIZE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumTiles", toStringFlags, tabCount, tabSize, ToString(obj.NumTiles, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "UseBox", toStringFlags, tabCount, tabSize, ToString(obj.UseBox, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, ToString(obj.Depth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_SUBRESOURCE_TILING>(const D3D12_SUBRESOURCE_TILING& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "WidthInTiles", toStringFlags, tabCount, tabSize, ToString(obj.WidthInTiles, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HeightInTiles", toStringFlags, tabCount, tabSize, ToString(obj.HeightInTiles, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthInTiles", toStringFlags, tabCount, tabSize, ToString(obj.DepthInTiles, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StartTileIndexInOverallResource", toStringFlags, tabCount, tabSize, ToString(obj.StartTileIndexInOverallResource, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TILE_SHAPE>(const D3D12_TILE_SHAPE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "WidthInTexels", toStringFlags, tabCount, tabSize, ToString(obj.WidthInTexels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HeightInTexels", toStringFlags, tabCount, tabSize, ToString(obj.HeightInTexels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthInTexels", toStringFlags, tabCount, tabSize, ToString(obj.DepthInTexels, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_PACKED_MIP_INFO>(const D3D12_PACKED_MIP_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumStandardMips", toStringFlags, tabCount, tabSize, ToString(obj.NumStandardMips, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumPackedMips", toStringFlags, tabCount, tabSize, ToString(obj.NumPackedMips, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumTilesForPackedMips", toStringFlags, tabCount, tabSize, ToString(obj.NumTilesForPackedMips, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StartTileIndexInOverallResource", toStringFlags, tabCount, tabSize, ToString(obj.StartTileIndexInOverallResource, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_TRANSITION_BARRIER>(const D3D12_RESOURCE_TRANSITION_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResource));
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, ToString(obj.Subresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StateBefore", toStringFlags, tabCount, tabSize, '"' + ToString(obj.StateBefore, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "StateAfter", toStringFlags, tabCount, tabSize, '"' + ToString(obj.StateAfter, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_ALIASING_BARRIER>(const D3D12_RESOURCE_ALIASING_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResourceBefore", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResourceBefore));
            FieldToString(strStrm, false, "pResourceAfter", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResourceAfter));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_UAV_BARRIER>(const D3D12_RESOURCE_UAV_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResource));
        }
    );
}

template <> std::string ToString<D3D12_SUBRESOURCE_FOOTPRINT>(const D3D12_SUBRESOURCE_FOOTPRINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, ToString(obj.Depth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RowPitch", toStringFlags, tabCount, tabSize, ToString(obj.RowPitch, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>(const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Offset", toStringFlags, tabCount, tabSize, ToString(obj.Offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Footprint", toStringFlags, tabCount, tabSize, ToString(obj.Footprint, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_SAMPLE_POSITION>(const D3D12_SAMPLE_POSITION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "X", toStringFlags, tabCount, tabSize, ToString(obj.X, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Y", toStringFlags, tabCount, tabSize, ToString(obj.Y, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_VIEW_INSTANCE_LOCATION>(const D3D12_VIEW_INSTANCE_LOCATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ViewportArrayIndex", toStringFlags, tabCount, tabSize, ToString(obj.ViewportArrayIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RenderTargetArrayIndex", toStringFlags, tabCount, tabSize, ToString(obj.RenderTargetArrayIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_VIEW_INSTANCING_DESC>(const D3D12_VIEW_INSTANCING_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ViewInstanceCount", toStringFlags, tabCount, tabSize, ToString(obj.ViewInstanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewInstanceLocations", toStringFlags, tabCount, tabSize, ArrayToString(obj.ViewInstanceCount, obj.pViewInstanceLocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_BUFFER_SRV>(const D3D12_BUFFER_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, ToString(obj.FirstElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, ToString(obj.NumElements, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StructureByteStride", toStringFlags, tabCount, tabSize, ToString(obj.StructureByteStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_SRV>(const D3D12_TEX1D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, ToString(obj.ResourceMinLODClamp, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_ARRAY_SRV>(const D3D12_TEX1D_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, ToString(obj.ResourceMinLODClamp, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_SRV>(const D3D12_TEX2D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, ToString(obj.ResourceMinLODClamp, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_ARRAY_SRV>(const D3D12_TEX2D_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, ToString(obj.ResourceMinLODClamp, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX3D_SRV>(const D3D12_TEX3D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, ToString(obj.ResourceMinLODClamp, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEXCUBE_SRV>(const D3D12_TEXCUBE_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, ToString(obj.ResourceMinLODClamp, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEXCUBE_ARRAY_SRV>(const D3D12_TEXCUBE_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "First2DArrayFace", toStringFlags, tabCount, tabSize, ToString(obj.First2DArrayFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumCubes", toStringFlags, tabCount, tabSize, ToString(obj.NumCubes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, ToString(obj.ResourceMinLODClamp, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_SRV>(const D3D12_TEX2DMS_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, ToString(obj.UnusedField_NothingToDefine, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_ARRAY_SRV>(const D3D12_TEX2DMS_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Location", toStringFlags, tabCount, tabSize, ToString(obj.Location, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_CONSTANT_BUFFER_VIEW_DESC>(const D3D12_CONSTANT_BUFFER_VIEW_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferLocation", toStringFlags, tabCount, tabSize, ToString(obj.BufferLocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_SAMPLER_DESC>(const D3D12_SAMPLER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Filter", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Filter, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "AddressU", toStringFlags, tabCount, tabSize, '"' + ToString(obj.AddressU, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "AddressV", toStringFlags, tabCount, tabSize, '"' + ToString(obj.AddressV, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "AddressW", toStringFlags, tabCount, tabSize, '"' + ToString(obj.AddressW, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "MipLODBias", toStringFlags, tabCount, tabSize, ToString(obj.MipLODBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxAnisotropy", toStringFlags, tabCount, tabSize, ToString(obj.MaxAnisotropy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ComparisonFunc", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ComparisonFunc, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "BorderColor", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.BorderColor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinLOD", toStringFlags, tabCount, tabSize, ToString(obj.MinLOD, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxLOD", toStringFlags, tabCount, tabSize, ToString(obj.MaxLOD, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_BUFFER_UAV>(const D3D12_BUFFER_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, ToString(obj.FirstElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, ToString(obj.NumElements, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StructureByteStride", toStringFlags, tabCount, tabSize, ToString(obj.StructureByteStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CounterOffsetInBytes", toStringFlags, tabCount, tabSize, ToString(obj.CounterOffsetInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_UAV>(const D3D12_TEX1D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_ARRAY_UAV>(const D3D12_TEX1D_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_UAV>(const D3D12_TEX2D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_ARRAY_UAV>(const D3D12_TEX2D_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX3D_UAV>(const D3D12_TEX3D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstWSlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstWSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WSize", toStringFlags, tabCount, tabSize, ToString(obj.WSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_BUFFER_RTV>(const D3D12_BUFFER_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, ToString(obj.FirstElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, ToString(obj.NumElements, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_RTV>(const D3D12_TEX1D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_ARRAY_RTV>(const D3D12_TEX1D_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_RTV>(const D3D12_TEX2D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_RTV>(const D3D12_TEX2DMS_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, ToString(obj.UnusedField_NothingToDefine, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_ARRAY_RTV>(const D3D12_TEX2D_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_ARRAY_RTV>(const D3D12_TEX2DMS_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX3D_RTV>(const D3D12_TEX3D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstWSlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstWSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WSize", toStringFlags, tabCount, tabSize, ToString(obj.WSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_DSV>(const D3D12_TEX1D_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_ARRAY_DSV>(const D3D12_TEX1D_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_DSV>(const D3D12_TEX2D_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_ARRAY_DSV>(const D3D12_TEX2D_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_DSV>(const D3D12_TEX2DMS_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, ToString(obj.UnusedField_NothingToDefine, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_ARRAY_DSV>(const D3D12_TEX2DMS_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DESCRIPTOR_HEAP_DESC>(const D3D12_DESCRIPTOR_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "NumDescriptors", toStringFlags, tabCount, tabSize, ToString(obj.NumDescriptors, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DESCRIPTOR_RANGE>(const D3D12_DESCRIPTOR_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RangeType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.RangeType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "NumDescriptors", toStringFlags, tabCount, tabSize, ToString(obj.NumDescriptors, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BaseShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.BaseShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OffsetInDescriptorsFromTableStart", toStringFlags, tabCount, tabSize, ToString(obj.OffsetInDescriptorsFromTableStart, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_DESCRIPTOR_TABLE>(const D3D12_ROOT_DESCRIPTOR_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumDescriptorRanges", toStringFlags, tabCount, tabSize, ToString(obj.NumDescriptorRanges, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorRanges", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumDescriptorRanges, obj.pDescriptorRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_CONSTANTS>(const D3D12_ROOT_CONSTANTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.ShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Num32BitValues", toStringFlags, tabCount, tabSize, ToString(obj.Num32BitValues, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_DESCRIPTOR>(const D3D12_ROOT_DESCRIPTOR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.ShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_STATIC_SAMPLER_DESC>(const D3D12_STATIC_SAMPLER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Filter", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Filter, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "AddressU", toStringFlags, tabCount, tabSize, '"' + ToString(obj.AddressU, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "AddressV", toStringFlags, tabCount, tabSize, '"' + ToString(obj.AddressV, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "AddressW", toStringFlags, tabCount, tabSize, '"' + ToString(obj.AddressW, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "MipLODBias", toStringFlags, tabCount, tabSize, ToString(obj.MipLODBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxAnisotropy", toStringFlags, tabCount, tabSize, ToString(obj.MaxAnisotropy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ComparisonFunc", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ComparisonFunc, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "BorderColor", toStringFlags, tabCount, tabSize, '"' + ToString(obj.BorderColor, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "MinLOD", toStringFlags, tabCount, tabSize, ToString(obj.MinLOD, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxLOD", toStringFlags, tabCount, tabSize, ToString(obj.MaxLOD, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.ShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ShaderVisibility", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ShaderVisibility, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_ROOT_SIGNATURE_DESC>(const D3D12_ROOT_SIGNATURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumParameters", toStringFlags, tabCount, tabSize, ToString(obj.NumParameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pParameters", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumParameters, obj.pParameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumStaticSamplers", toStringFlags, tabCount, tabSize, ToString(obj.NumStaticSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStaticSamplers", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumStaticSamplers, obj.pStaticSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_DESCRIPTOR_RANGE1>(const D3D12_DESCRIPTOR_RANGE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RangeType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.RangeType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "NumDescriptors", toStringFlags, tabCount, tabSize, ToString(obj.NumDescriptors, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BaseShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.BaseShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "OffsetInDescriptorsFromTableStart", toStringFlags, tabCount, tabSize, ToString(obj.OffsetInDescriptorsFromTableStart, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_DESCRIPTOR_TABLE1>(const D3D12_ROOT_DESCRIPTOR_TABLE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumDescriptorRanges", toStringFlags, tabCount, tabSize, ToString(obj.NumDescriptorRanges, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorRanges", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumDescriptorRanges, obj.pDescriptorRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_DESCRIPTOR1>(const D3D12_ROOT_DESCRIPTOR1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.ShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_ROOT_SIGNATURE_DESC1>(const D3D12_ROOT_SIGNATURE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumParameters", toStringFlags, tabCount, tabSize, ToString(obj.NumParameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pParameters", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumParameters, obj.pParameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumStaticSamplers", toStringFlags, tabCount, tabSize, ToString(obj.NumStaticSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStaticSamplers", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumStaticSamplers, obj.pStaticSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_DISCARD_REGION>(const D3D12_DISCARD_REGION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumRects", toStringFlags, tabCount, tabSize, ToString(obj.NumRects, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRects", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumRects, obj.pRects, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstSubresource", toStringFlags, tabCount, tabSize, ToString(obj.FirstSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumSubresources", toStringFlags, tabCount, tabSize, ToString(obj.NumSubresources, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_QUERY_HEAP_DESC>(const D3D12_QUERY_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Count", toStringFlags, tabCount, tabSize, ToString(obj.Count, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_QUERY_DATA_PIPELINE_STATISTICS>(const D3D12_QUERY_DATA_PIPELINE_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "IAVertices", toStringFlags, tabCount, tabSize, ToString(obj.IAVertices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "IAPrimitives", toStringFlags, tabCount, tabSize, ToString(obj.IAPrimitives, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VSInvocations", toStringFlags, tabCount, tabSize, ToString(obj.VSInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "GSInvocations", toStringFlags, tabCount, tabSize, ToString(obj.GSInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "GSPrimitives", toStringFlags, tabCount, tabSize, ToString(obj.GSPrimitives, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CInvocations", toStringFlags, tabCount, tabSize, ToString(obj.CInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CPrimitives", toStringFlags, tabCount, tabSize, ToString(obj.CPrimitives, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PSInvocations", toStringFlags, tabCount, tabSize, ToString(obj.PSInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HSInvocations", toStringFlags, tabCount, tabSize, ToString(obj.HSInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DSInvocations", toStringFlags, tabCount, tabSize, ToString(obj.DSInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CSInvocations", toStringFlags, tabCount, tabSize, ToString(obj.CSInvocations, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_QUERY_DATA_SO_STATISTICS>(const D3D12_QUERY_DATA_SO_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumPrimitivesWritten", toStringFlags, tabCount, tabSize, ToString(obj.NumPrimitivesWritten, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PrimitivesStorageNeeded", toStringFlags, tabCount, tabSize, ToString(obj.PrimitivesStorageNeeded, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_STREAM_OUTPUT_BUFFER_VIEW>(const D3D12_STREAM_OUTPUT_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferLocation", toStringFlags, tabCount, tabSize, ToString(obj.BufferLocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BufferFilledSizeLocation", toStringFlags, tabCount, tabSize, ToString(obj.BufferFilledSizeLocation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DRAW_ARGUMENTS>(const D3D12_DRAW_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "VertexCountPerInstance", toStringFlags, tabCount, tabSize, ToString(obj.VertexCountPerInstance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InstanceCount", toStringFlags, tabCount, tabSize, ToString(obj.InstanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StartVertexLocation", toStringFlags, tabCount, tabSize, ToString(obj.StartVertexLocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StartInstanceLocation", toStringFlags, tabCount, tabSize, ToString(obj.StartInstanceLocation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DRAW_INDEXED_ARGUMENTS>(const D3D12_DRAW_INDEXED_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "IndexCountPerInstance", toStringFlags, tabCount, tabSize, ToString(obj.IndexCountPerInstance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InstanceCount", toStringFlags, tabCount, tabSize, ToString(obj.InstanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StartIndexLocation", toStringFlags, tabCount, tabSize, ToString(obj.StartIndexLocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BaseVertexLocation", toStringFlags, tabCount, tabSize, ToString(obj.BaseVertexLocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StartInstanceLocation", toStringFlags, tabCount, tabSize, ToString(obj.StartInstanceLocation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DISPATCH_ARGUMENTS>(const D3D12_DISPATCH_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ThreadGroupCountX", toStringFlags, tabCount, tabSize, ToString(obj.ThreadGroupCountX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ThreadGroupCountY", toStringFlags, tabCount, tabSize, ToString(obj.ThreadGroupCountY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ThreadGroupCountZ", toStringFlags, tabCount, tabSize, ToString(obj.ThreadGroupCountZ, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_VERTEX_BUFFER_VIEW>(const D3D12_VERTEX_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferLocation", toStringFlags, tabCount, tabSize, ToString(obj.BufferLocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StrideInBytes", toStringFlags, tabCount, tabSize, ToString(obj.StrideInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_INDEX_BUFFER_VIEW>(const D3D12_INDEX_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferLocation", toStringFlags, tabCount, tabSize, ToString(obj.BufferLocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_COMMAND_SIGNATURE_DESC>(const D3D12_COMMAND_SIGNATURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ByteStride", toStringFlags, tabCount, tabSize, ToString(obj.ByteStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumArgumentDescs", toStringFlags, tabCount, tabSize, ToString(obj.NumArgumentDescs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pArgumentDescs", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumArgumentDescs, obj.pArgumentDescs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>(const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Dest", toStringFlags, tabCount, tabSize, ToString(obj.Dest, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Value", toStringFlags, tabCount, tabSize, ToString(obj.Value, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT>(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, ToString(obj.NodeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Support", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Support, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_PROTECTED_RESOURCE_SESSION_DESC>(const D3D12_PROTECTED_RESOURCE_SESSION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_META_COMMAND_PARAMETER_DESC>(const D3D12_META_COMMAND_PARAMETER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Name", toStringFlags, tabCount, tabSize, (obj.Name ? ToString(*obj.Name, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "RequiredResourceState", toStringFlags, tabCount, tabSize, '"' + ToString(obj.RequiredResourceState, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "StructureOffset", toStringFlags, tabCount, tabSize, ToString(obj.StructureOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_META_COMMAND_DESC>(const D3D12_META_COMMAND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Id", toStringFlags, tabCount, tabSize, ToString(obj.Id, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Name", toStringFlags, tabCount, tabSize, (obj.Name ? ToString(*obj.Name, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "InitializationDirtyState", toStringFlags, tabCount, tabSize, '"' + ToString(obj.InitializationDirtyState, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ExecutionDirtyState", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ExecutionDirtyState, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_STATE_OBJECT_CONFIG>(const D3D12_STATE_OBJECT_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_GLOBAL_ROOT_SIGNATURE>(const D3D12_GLOBAL_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pGlobalRootSignature", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pGlobalRootSignature));
        }
    );
}

template <> std::string ToString<D3D12_LOCAL_ROOT_SIGNATURE>(const D3D12_LOCAL_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pLocalRootSignature", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pLocalRootSignature));
        }
    );
}

template <> std::string ToString<D3D12_NODE_MASK>(const D3D12_NODE_MASK& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_EXPORT_DESC>(const D3D12_EXPORT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Name", toStringFlags, tabCount, tabSize, (obj.Name ? ToString(*obj.Name, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "ExportToRename", toStringFlags, tabCount, tabSize, (obj.ExportToRename ? ToString(*obj.ExportToRename, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_DXIL_LIBRARY_DESC>(const D3D12_DXIL_LIBRARY_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DXILLibrary", toStringFlags, tabCount, tabSize, ToString(obj.DXILLibrary, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumExports", toStringFlags, tabCount, tabSize, ToString(obj.NumExports, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExports", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumExports, obj.pExports, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_EXISTING_COLLECTION_DESC>(const D3D12_EXISTING_COLLECTION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pExistingCollection", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pExistingCollection));
            FieldToString(strStrm, false, "NumExports", toStringFlags, tabCount, tabSize, ToString(obj.NumExports, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExports", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumExports, obj.pExports, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_HIT_GROUP_DESC>(const D3D12_HIT_GROUP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "HitGroupExport", toStringFlags, tabCount, tabSize, (obj.HitGroupExport ? ToString(*obj.HitGroupExport, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "AnyHitShaderImport", toStringFlags, tabCount, tabSize, (obj.AnyHitShaderImport ? ToString(*obj.AnyHitShaderImport, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "ClosestHitShaderImport", toStringFlags, tabCount, tabSize, (obj.ClosestHitShaderImport ? ToString(*obj.ClosestHitShaderImport, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "IntersectionShaderImport", toStringFlags, tabCount, tabSize, (obj.IntersectionShaderImport ? ToString(*obj.IntersectionShaderImport, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_SHADER_CONFIG>(const D3D12_RAYTRACING_SHADER_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxPayloadSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.MaxPayloadSizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxAttributeSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.MaxAttributeSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_PIPELINE_CONFIG>(const D3D12_RAYTRACING_PIPELINE_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxTraceRecursionDepth", toStringFlags, tabCount, tabSize, ToString(obj.MaxTraceRecursionDepth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_PIPELINE_CONFIG1>(const D3D12_RAYTRACING_PIPELINE_CONFIG1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxTraceRecursionDepth", toStringFlags, tabCount, tabSize, ToString(obj.MaxTraceRecursionDepth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE>(const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StartAddress", toStringFlags, tabCount, tabSize, ToString(obj.StartAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StrideInBytes", toStringFlags, tabCount, tabSize, ToString(obj.StrideInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_GPU_VIRTUAL_ADDRESS_RANGE>(const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StartAddress", toStringFlags, tabCount, tabSize, ToString(obj.StartAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE>(const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StartAddress", toStringFlags, tabCount, tabSize, ToString(obj.StartAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StrideInBytes", toStringFlags, tabCount, tabSize, ToString(obj.StrideInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC>(const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Transform3x4", toStringFlags, tabCount, tabSize, ToString(obj.Transform3x4, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "IndexFormat", toStringFlags, tabCount, tabSize, '"' + ToString(obj.IndexFormat, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "VertexFormat", toStringFlags, tabCount, tabSize, '"' + ToString(obj.VertexFormat, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "IndexCount", toStringFlags, tabCount, tabSize, ToString(obj.IndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VertexCount", toStringFlags, tabCount, tabSize, ToString(obj.VertexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "IndexBuffer", toStringFlags, tabCount, tabSize, ToString(obj.IndexBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VertexBuffer", toStringFlags, tabCount, tabSize, ToString(obj.VertexBuffer, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_AABB>(const D3D12_RAYTRACING_AABB& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MinX", toStringFlags, tabCount, tabSize, ToString(obj.MinX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinY", toStringFlags, tabCount, tabSize, ToString(obj.MinY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinZ", toStringFlags, tabCount, tabSize, ToString(obj.MinZ, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxX", toStringFlags, tabCount, tabSize, ToString(obj.MaxX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxY", toStringFlags, tabCount, tabSize, ToString(obj.MaxY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxZ", toStringFlags, tabCount, tabSize, ToString(obj.MaxZ, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_GEOMETRY_AABBS_DESC>(const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AABBCount", toStringFlags, tabCount, tabSize, ToString(obj.AABBCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AABBs", toStringFlags, tabCount, tabSize, ToString(obj.AABBs, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DestBuffer", toStringFlags, tabCount, tabSize, ToString(obj.DestBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InfoType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.InfoType, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CompactedSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.CompactedSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DecodedSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.DecodedSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER>(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "NumDescs", toStringFlags, tabCount, tabSize, ToString(obj.NumDescs, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SerializedSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SerializedSizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumBottomLevelAccelerationStructurePointers", toStringFlags, tabCount, tabSize, ToString(obj.NumBottomLevelAccelerationStructurePointers, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>(const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DriverOpaqueGUID", toStringFlags, tabCount, tabSize, ToString(obj.DriverOpaqueGUID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DriverOpaqueVersioningData", toStringFlags, tabCount, tabSize, ArrayToString(16, obj.DriverOpaqueVersioningData, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER>(const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DriverMatchingIdentifier", toStringFlags, tabCount, tabSize, ToString(obj.DriverMatchingIdentifier, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SerializedSizeInBytesIncludingHeader", toStringFlags, tabCount, tabSize, ToString(obj.SerializedSizeInBytesIncludingHeader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeserializedSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.DeserializedSizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumBottomLevelAccelerationStructurePointersAfterHeader", toStringFlags, tabCount, tabSize, ToString(obj.NumBottomLevelAccelerationStructurePointersAfterHeader, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CurrentSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.CurrentSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DestAccelerationStructureData", toStringFlags, tabCount, tabSize, ToString(obj.DestAccelerationStructureData, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Inputs", toStringFlags, tabCount, tabSize, ToString(obj.Inputs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SourceAccelerationStructureData", toStringFlags, tabCount, tabSize, ToString(obj.SourceAccelerationStructureData, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ScratchAccelerationStructureData", toStringFlags, tabCount, tabSize, ToString(obj.ScratchAccelerationStructureData, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ResultDataMaxSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.ResultDataMaxSizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ScratchDataSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.ScratchDataSizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "UpdateScratchDataSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.UpdateScratchDataSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_AUTO_BREADCRUMB_NODE>(const D3D12_AUTO_BREADCRUMB_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pCommandListDebugNameA", toStringFlags, tabCount, tabSize, (obj.pCommandListDebugNameA ? ToString(*obj.pCommandListDebugNameA, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pCommandListDebugNameW", toStringFlags, tabCount, tabSize, (obj.pCommandListDebugNameW ? ToString(*obj.pCommandListDebugNameW, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pCommandQueueDebugNameA", toStringFlags, tabCount, tabSize, (obj.pCommandQueueDebugNameA ? ToString(*obj.pCommandQueueDebugNameA, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pCommandQueueDebugNameW", toStringFlags, tabCount, tabSize, (obj.pCommandQueueDebugNameW ? ToString(*obj.pCommandQueueDebugNameW, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pCommandList", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pCommandList));
            FieldToString(strStrm, false, "pCommandQueue", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pCommandQueue));
            FieldToString(strStrm, false, "BreadcrumbCount", toStringFlags, tabCount, tabSize, ToString(obj.BreadcrumbCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pLastBreadcrumbValue", toStringFlags, tabCount, tabSize, (obj.pLastBreadcrumbValue ? ToString(*obj.pLastBreadcrumbValue, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pCommandHistory", toStringFlags, tabCount, tabSize, EnumArrayToString(obj.BreadcrumbCount, obj.pCommandHistory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, (obj.pNext ? ToString(*obj.pNext, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_BREADCRUMB_CONTEXT>(const D3D12_DRED_BREADCRUMB_CONTEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BreadcrumbIndex", toStringFlags, tabCount, tabSize, ToString(obj.BreadcrumbIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pContextString", toStringFlags, tabCount, tabSize, (obj.pContextString ? ToString(*obj.pContextString, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<D3D12_AUTO_BREADCRUMB_NODE1>(const D3D12_AUTO_BREADCRUMB_NODE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pCommandListDebugNameA", toStringFlags, tabCount, tabSize, (obj.pCommandListDebugNameA ? ToString(*obj.pCommandListDebugNameA, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pCommandListDebugNameW", toStringFlags, tabCount, tabSize, (obj.pCommandListDebugNameW ? ToString(*obj.pCommandListDebugNameW, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pCommandQueueDebugNameA", toStringFlags, tabCount, tabSize, (obj.pCommandQueueDebugNameA ? ToString(*obj.pCommandQueueDebugNameA, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pCommandQueueDebugNameW", toStringFlags, tabCount, tabSize, (obj.pCommandQueueDebugNameW ? ToString(*obj.pCommandQueueDebugNameW, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pCommandList", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pCommandList));
            FieldToString(strStrm, false, "pCommandQueue", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pCommandQueue));
            FieldToString(strStrm, false, "BreadcrumbCount", toStringFlags, tabCount, tabSize, ToString(obj.BreadcrumbCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pLastBreadcrumbValue", toStringFlags, tabCount, tabSize, (obj.pLastBreadcrumbValue ? ToString(*obj.pLastBreadcrumbValue, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pCommandHistory", toStringFlags, tabCount, tabSize, EnumArrayToString(obj.BreadcrumbCount, obj.pCommandHistory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, (obj.pNext ? ToString(*obj.pNext, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "BreadcrumbContextsCount", toStringFlags, tabCount, tabSize, ToString(obj.BreadcrumbContextsCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBreadcrumbContexts", toStringFlags, tabCount, tabSize, ArrayToString(obj.BreadcrumbContextsCount, obj.pBreadcrumbContexts, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DEVICE_REMOVED_EXTENDED_DATA>(const D3D12_DEVICE_REMOVED_EXTENDED_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pHeadAutoBreadcrumbNode", toStringFlags, tabCount, tabSize, (obj.pHeadAutoBreadcrumbNode ? ToString(*obj.pHeadAutoBreadcrumbNode, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_ALLOCATION_NODE>(const D3D12_DRED_ALLOCATION_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ObjectNameA", toStringFlags, tabCount, tabSize, (obj.ObjectNameA ? ToString(*obj.ObjectNameA, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "ObjectNameW", toStringFlags, tabCount, tabSize, (obj.ObjectNameW ? ToString(*obj.ObjectNameW, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "AllocationType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.AllocationType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, (obj.pNext ? ToString(*obj.pNext, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_ALLOCATION_NODE1>(const D3D12_DRED_ALLOCATION_NODE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ObjectNameA", toStringFlags, tabCount, tabSize, (obj.ObjectNameA ? ToString(*obj.ObjectNameA, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "ObjectNameW", toStringFlags, tabCount, tabSize, (obj.ObjectNameW ? ToString(*obj.ObjectNameW, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "AllocationType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.AllocationType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, (obj.pNext ? ToString(*obj.pNext, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pObject", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pObject));
        }
    );
}

template <> std::string ToString<D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pHeadAutoBreadcrumbNode", toStringFlags, tabCount, tabSize, (obj.pHeadAutoBreadcrumbNode ? ToString(*obj.pHeadAutoBreadcrumbNode, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pHeadAutoBreadcrumbNode", toStringFlags, tabCount, tabSize, (obj.pHeadAutoBreadcrumbNode ? ToString(*obj.pHeadAutoBreadcrumbNode, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_PAGE_FAULT_OUTPUT>(const D3D12_DRED_PAGE_FAULT_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PageFaultVA", toStringFlags, tabCount, tabSize, ToString(obj.PageFaultVA, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pHeadExistingAllocationNode", toStringFlags, tabCount, tabSize, (obj.pHeadExistingAllocationNode ? ToString(*obj.pHeadExistingAllocationNode, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pHeadRecentFreedAllocationNode", toStringFlags, tabCount, tabSize, (obj.pHeadRecentFreedAllocationNode ? ToString(*obj.pHeadRecentFreedAllocationNode, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_PAGE_FAULT_OUTPUT1>(const D3D12_DRED_PAGE_FAULT_OUTPUT1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PageFaultVA", toStringFlags, tabCount, tabSize, ToString(obj.PageFaultVA, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pHeadExistingAllocationNode", toStringFlags, tabCount, tabSize, (obj.pHeadExistingAllocationNode ? ToString(*obj.pHeadExistingAllocationNode, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pHeadRecentFreedAllocationNode", toStringFlags, tabCount, tabSize, (obj.pHeadRecentFreedAllocationNode ? ToString(*obj.pHeadRecentFreedAllocationNode, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<D3D12_DEVICE_REMOVED_EXTENDED_DATA1>(const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceRemovedReason", toStringFlags, tabCount, tabSize, ToString(obj.DeviceRemovedReason, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AutoBreadcrumbsOutput", toStringFlags, tabCount, tabSize, ToString(obj.AutoBreadcrumbsOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PageFaultOutput", toStringFlags, tabCount, tabSize, ToString(obj.PageFaultOutput, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DEVICE_REMOVED_EXTENDED_DATA2>(const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceRemovedReason", toStringFlags, tabCount, tabSize, ToString(obj.DeviceRemovedReason, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AutoBreadcrumbsOutput", toStringFlags, tabCount, tabSize, ToString(obj.AutoBreadcrumbsOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PageFaultOutput", toStringFlags, tabCount, tabSize, ToString(obj.PageFaultOutput, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT>(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, ToString(obj.NodeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Count", toStringFlags, tabCount, tabSize, ToString(obj.Count, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES>(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, ToString(obj.NodeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Count", toStringFlags, tabCount, tabSize, ToString(obj.Count, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTypes", toStringFlags, tabCount, tabSize, ArrayToString(obj.Count, obj.pTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_PROTECTED_RESOURCE_SESSION_DESC1>(const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ProtectionType", toStringFlags, tabCount, tabSize, ToString(obj.ProtectionType, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS>(const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ClearValue", toStringFlags, tabCount, tabSize, ToString(obj.ClearValue, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS>(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SrcSubresource", toStringFlags, tabCount, tabSize, ToString(obj.SrcSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DstSubresource", toStringFlags, tabCount, tabSize, ToString(obj.DstSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DstX", toStringFlags, tabCount, tabSize, ToString(obj.DstX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DstY", toStringFlags, tabCount, tabSize, ToString(obj.DstY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SrcRect", toStringFlags, tabCount, tabSize, ToString(obj.SrcRect, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS>(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pSrcResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pSrcResource));
            FieldToString(strStrm, false, "pDstResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pDstResource));
            FieldToString(strStrm, false, "SubresourceCount", toStringFlags, tabCount, tabSize, ToString(obj.SubresourceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubresourceParameters", toStringFlags, tabCount, tabSize, ArrayToString(obj.SubresourceCount, obj.pSubresourceParameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ResolveMode", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ResolveMode, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "PreserveResolveSource", toStringFlags, tabCount, tabSize, ToString(obj.PreserveResolveSource, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_PASS_RENDER_TARGET_DESC>(const D3D12_RENDER_PASS_RENDER_TARGET_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "cpuDescriptor", toStringFlags, tabCount, tabSize, ToString(obj.cpuDescriptor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BeginningAccess", toStringFlags, tabCount, tabSize, ToString(obj.BeginningAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "EndingAccess", toStringFlags, tabCount, tabSize, ToString(obj.EndingAccess, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>(const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "cpuDescriptor", toStringFlags, tabCount, tabSize, ToString(obj.cpuDescriptor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBeginningAccess", toStringFlags, tabCount, tabSize, ToString(obj.DepthBeginningAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilBeginningAccess", toStringFlags, tabCount, tabSize, ToString(obj.StencilBeginningAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthEndingAccess", toStringFlags, tabCount, tabSize, ToString(obj.DepthEndingAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilEndingAccess", toStringFlags, tabCount, tabSize, ToString(obj.StencilEndingAccess, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DISPATCH_RAYS_DESC>(const D3D12_DISPATCH_RAYS_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RayGenerationShaderRecord", toStringFlags, tabCount, tabSize, ToString(obj.RayGenerationShaderRecord, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MissShaderTable", toStringFlags, tabCount, tabSize, ToString(obj.MissShaderTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HitGroupTable", toStringFlags, tabCount, tabSize, ToString(obj.HitGroupTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CallableShaderTable", toStringFlags, tabCount, tabSize, ToString(obj.CallableShaderTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, ToString(obj.Depth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_SUBRESOURCE_DATA>(const D3D12_SUBRESOURCE_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pData", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pData));
            FieldToString(strStrm, false, "RowPitch", toStringFlags, tabCount, tabSize, ToString(obj.RowPitch, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SlicePitch", toStringFlags, tabCount, tabSize, ToString(obj.SlicePitch, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_MEMCPY_DEST>(const D3D12_MEMCPY_DEST& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pData", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pData));
            FieldToString(strStrm, false, "RowPitch", toStringFlags, tabCount, tabSize, ToString(obj.RowPitch, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SlicePitch", toStringFlags, tabCount, tabSize, ToString(obj.SlicePitch, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DISPATCH_MESH_ARGUMENTS>(const D3D12_DISPATCH_MESH_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ThreadGroupCountX", toStringFlags, tabCount, tabSize, ToString(obj.ThreadGroupCountX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ThreadGroupCountY", toStringFlags, tabCount, tabSize, ToString(obj.ThreadGroupCountY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ThreadGroupCountZ", toStringFlags, tabCount, tabSize, ToString(obj.ThreadGroupCountZ, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D_SHADER_MACRO>(const D3D_SHADER_MACRO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Name", toStringFlags, tabCount, tabSize, (obj.Name ? ToString(*obj.Name, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "Definition", toStringFlags, tabCount, tabSize, (obj.Definition ? ToString(*obj.Definition, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS>(const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxMessagesPerCommandList", toStringFlags, tabCount, tabSize, ToString(obj.MaxMessagesPerCommandList, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DefaultShaderPatchMode", toStringFlags, tabCount, tabSize, '"' + ToString(obj.DefaultShaderPatchMode, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "PipelineStateCreateFlags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.PipelineStateCreateFlags, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR>(const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SlowdownFactor", toStringFlags, tabCount, tabSize, ToString(obj.SlowdownFactor, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS>(const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderPatchMode", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ShaderPatchMode, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <> std::string ToString<D3D12_MESSAGE>(const D3D12_MESSAGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Category", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Category, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Severity", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Severity, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ID", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ID, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pDescription", toStringFlags, tabCount, tabSize, (obj.pDescription ? ToString(*obj.pDescription, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "DescriptionByteLength", toStringFlags, tabCount, tabSize, ToString(obj.DescriptionByteLength, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_INFO_QUEUE_FILTER_DESC>(const D3D12_INFO_QUEUE_FILTER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumCategories", toStringFlags, tabCount, tabSize, ToString(obj.NumCategories, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCategoryList", toStringFlags, tabCount, tabSize, EnumArrayToString(obj.NumCategories, obj.pCategoryList, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumSeverities", toStringFlags, tabCount, tabSize, ToString(obj.NumSeverities, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSeverityList", toStringFlags, tabCount, tabSize, EnumArrayToString(obj.NumSeverities, obj.pSeverityList, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumIDs", toStringFlags, tabCount, tabSize, ToString(obj.NumIDs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIDList", toStringFlags, tabCount, tabSize, EnumArrayToString(obj.NumIDs, obj.pIDList, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<D3D12_INFO_QUEUE_FILTER>(const D3D12_INFO_QUEUE_FILTER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AllowList", toStringFlags, tabCount, tabSize, ToString(obj.AllowList, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DenyList", toStringFlags, tabCount, tabSize, ToString(obj.DenyList, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<GUID>(const GUID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Data1", toStringFlags, tabCount, tabSize, ToString(obj.Data1, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Data2", toStringFlags, tabCount, tabSize, ToString(obj.Data2, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Data3", toStringFlags, tabCount, tabSize, ToString(obj.Data3, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Data4", toStringFlags, tabCount, tabSize, ArrayToString(8, obj.Data4, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<tagRECT>(const tagRECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "left", toStringFlags, tabCount, tabSize, ToString(obj.left, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "top", toStringFlags, tabCount, tabSize, ToString(obj.top, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "right", toStringFlags, tabCount, tabSize, ToString(obj.right, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bottom", toStringFlags, tabCount, tabSize, ToString(obj.bottom, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<tagPOINT>(const tagPOINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "x", toStringFlags, tabCount, tabSize, ToString(obj.x, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "y", toStringFlags, tabCount, tabSize, ToString(obj.y, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<_SECURITY_ATTRIBUTES>(const _SECURITY_ATTRIBUTES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "nLength", toStringFlags, tabCount, tabSize, ToString(obj.nLength, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lpSecurityDescriptor", toStringFlags, tabCount, tabSize, HandleIdToString(obj.lpSecurityDescriptor));
            FieldToString(strStrm, false, "bInheritHandle", toStringFlags, tabCount, tabSize, ToString(obj.bInheritHandle, toStringFlags, tabCount, tabSize));
        }
    );
}


GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
