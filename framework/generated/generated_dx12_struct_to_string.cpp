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

std::string ToString(const DXGI_FRAME_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const DXGI_MAPPED_RECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Pitch", toStringFlags, tabCount, tabSize, ToString(obj.Pitch, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBits", toStringFlags, tabCount, tabSize, (obj.pBits ? ToString(*obj.pBits, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

std::string ToString(const LUID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "LowPart", toStringFlags, tabCount, tabSize, ToString(obj.LowPart, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HighPart", toStringFlags, tabCount, tabSize, ToString(obj.HighPart, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_ADAPTER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, Quote(WCharArrayToString(obj.Description)));
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

std::string ToString(const DXGI_OUTPUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceName", toStringFlags, tabCount, tabSize, Quote(WCharArrayToString(obj.DeviceName)));
            FieldToString(strStrm, false, "DesktopCoordinates", toStringFlags, tabCount, tabSize, ToString(obj.DesktopCoordinates, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AttachedToDesktop", toStringFlags, tabCount, tabSize, ToString(obj.AttachedToDesktop, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Rotation", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Rotation)));
            FieldToString(strStrm, false, "Monitor", toStringFlags, tabCount, tabSize, HandleIdToString(obj.Monitor));
        }
    );
}

std::string ToString(const DXGI_SHARED_RESOURCE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Handle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.Handle));
        }
    );
}

std::string ToString(const DXGI_SURFACE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_SWAP_CHAIN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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
            FieldToString(strStrm, false, "SwapEffect", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SwapEffect)));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_ADAPTER_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, Quote(WCharArrayToString(obj.Description)));
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

std::string ToString(const DXGI_OUTDUPL_MOVE_RECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SourcePoint", toStringFlags, tabCount, tabSize, ToString(obj.SourcePoint, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DestinationRect", toStringFlags, tabCount, tabSize, ToString(obj.DestinationRect, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_OUTDUPL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ModeDesc", toStringFlags, tabCount, tabSize, ToString(obj.ModeDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Rotation", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Rotation)));
            FieldToString(strStrm, false, "DesktopImageInSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.DesktopImageInSystemMemory, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_OUTDUPL_POINTER_POSITION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Position", toStringFlags, tabCount, tabSize, ToString(obj.Position, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Visible", toStringFlags, tabCount, tabSize, ToString(obj.Visible, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_OUTDUPL_POINTER_SHAPE_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const DXGI_OUTDUPL_FRAME_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const DXGI_MODE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RefreshRate", toStringFlags, tabCount, tabSize, ToString(obj.RefreshRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "ScanlineOrdering", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ScanlineOrdering)));
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Scaling)));
            FieldToString(strStrm, false, "Stereo", toStringFlags, tabCount, tabSize, ToString(obj.Stereo, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_SWAP_CHAIN_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "Stereo", toStringFlags, tabCount, tabSize, ToString(obj.Stereo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BufferUsage", toStringFlags, tabCount, tabSize, ToString(obj.BufferUsage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BufferCount", toStringFlags, tabCount, tabSize, ToString(obj.BufferCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Scaling)));
            FieldToString(strStrm, false, "SwapEffect", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SwapEffect)));
            FieldToString(strStrm, false, "AlphaMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AlphaMode)));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RefreshRate", toStringFlags, tabCount, tabSize, ToString(obj.RefreshRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ScanlineOrdering", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ScanlineOrdering)));
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Scaling)));
            FieldToString(strStrm, false, "Windowed", toStringFlags, tabCount, tabSize, ToString(obj.Windowed, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_PRESENT_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const DXGI_ADAPTER_DESC2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, Quote(WCharArrayToString(obj.Description)));
            FieldToString(strStrm, false, "VendorId", toStringFlags, tabCount, tabSize, ToString(obj.VendorId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceId", toStringFlags, tabCount, tabSize, ToString(obj.DeviceId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SubSysId", toStringFlags, tabCount, tabSize, ToString(obj.SubSysId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Revision", toStringFlags, tabCount, tabSize, ToString(obj.Revision, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedVideoMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedVideoMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SharedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.SharedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, ToString(obj.AdapterLuid, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "GraphicsPreemptionGranularity", toStringFlags, tabCount, tabSize, Quote(ToString(obj.GraphicsPreemptionGranularity)));
            FieldToString(strStrm, false, "ComputePreemptionGranularity", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ComputePreemptionGranularity)));
        }
    );
}

std::string ToString(const DXGI_MATRIX_3X2_F& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const DXGI_DECODE_SWAP_CHAIN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_FRAME_STATISTICS_MEDIA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PresentCount", toStringFlags, tabCount, tabSize, ToString(obj.PresentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PresentRefreshCount", toStringFlags, tabCount, tabSize, ToString(obj.PresentRefreshCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SyncRefreshCount", toStringFlags, tabCount, tabSize, ToString(obj.SyncRefreshCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SyncQPCTime", toStringFlags, tabCount, tabSize, ToString(obj.SyncQPCTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SyncGPUTime", toStringFlags, tabCount, tabSize, ToString(obj.SyncGPUTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CompositionMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.CompositionMode)));
            FieldToString(strStrm, false, "ApprovedPresentDuration", toStringFlags, tabCount, tabSize, ToString(obj.ApprovedPresentDuration, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_QUERY_VIDEO_MEMORY_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const DXGI_HDR_METADATA_HDR10& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const DXGI_HDR_METADATA_HDR10PLUS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Data", toStringFlags, tabCount, tabSize, ArrayToString(72, obj.Data, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_ADAPTER_DESC3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, Quote(WCharArrayToString(obj.Description)));
            FieldToString(strStrm, false, "VendorId", toStringFlags, tabCount, tabSize, ToString(obj.VendorId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceId", toStringFlags, tabCount, tabSize, ToString(obj.DeviceId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SubSysId", toStringFlags, tabCount, tabSize, ToString(obj.SubSysId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Revision", toStringFlags, tabCount, tabSize, ToString(obj.Revision, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedVideoMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedVideoMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DedicatedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.DedicatedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SharedSystemMemory", toStringFlags, tabCount, tabSize, ToString(obj.SharedSystemMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, ToString(obj.AdapterLuid, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "GraphicsPreemptionGranularity", toStringFlags, tabCount, tabSize, Quote(ToString(obj.GraphicsPreemptionGranularity)));
            FieldToString(strStrm, false, "ComputePreemptionGranularity", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ComputePreemptionGranularity)));
        }
    );
}

std::string ToString(const DXGI_OUTPUT_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceName", toStringFlags, tabCount, tabSize, Quote(WCharArrayToString(obj.DeviceName)));
            FieldToString(strStrm, false, "DesktopCoordinates", toStringFlags, tabCount, tabSize, ToString(obj.DesktopCoordinates, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AttachedToDesktop", toStringFlags, tabCount, tabSize, ToString(obj.AttachedToDesktop, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Rotation", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Rotation)));
            FieldToString(strStrm, false, "Monitor", toStringFlags, tabCount, tabSize, HandleIdToString(obj.Monitor));
            FieldToString(strStrm, false, "BitsPerColor", toStringFlags, tabCount, tabSize, ToString(obj.BitsPerColor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ColorSpace", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ColorSpace)));
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

std::string ToString(const DXGI_RATIONAL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Numerator", toStringFlags, tabCount, tabSize, ToString(obj.Numerator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Denominator", toStringFlags, tabCount, tabSize, ToString(obj.Denominator, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_SAMPLE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Count", toStringFlags, tabCount, tabSize, ToString(obj.Count, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Quality", toStringFlags, tabCount, tabSize, ToString(obj.Quality, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_RGB& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3DCOLORVALUE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const DXGI_GAMMA_CONTROL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const DXGI_GAMMA_CONTROL_CAPABILITIES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const DXGI_MODE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RefreshRate", toStringFlags, tabCount, tabSize, ToString(obj.RefreshRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "ScanlineOrdering", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ScanlineOrdering)));
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Scaling)));
        }
    );
}

std::string ToString(const DXGI_JPEG_DC_HUFFMAN_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CodeCounts", toStringFlags, tabCount, tabSize, ArrayToString(12, obj.CodeCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CodeValues", toStringFlags, tabCount, tabSize, ArrayToString(12, obj.CodeValues, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_JPEG_AC_HUFFMAN_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CodeCounts", toStringFlags, tabCount, tabSize, ArrayToString(16, obj.CodeCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CodeValues", toStringFlags, tabCount, tabSize, ArrayToString(162, obj.CodeValues, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const DXGI_JPEG_QUANTIZATION_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Elements", toStringFlags, tabCount, tabSize, ArrayToString(64, obj.Elements, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_COMMAND_QUEUE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "Priority", toStringFlags, tabCount, tabSize, ToString(obj.Priority, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_INPUT_ELEMENT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SemanticName", toStringFlags, tabCount, tabSize, (obj.SemanticName ? ToString(*obj.SemanticName, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "SemanticIndex", toStringFlags, tabCount, tabSize, ToString(obj.SemanticIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "InputSlot", toStringFlags, tabCount, tabSize, ToString(obj.InputSlot, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AlignedByteOffset", toStringFlags, tabCount, tabSize, ToString(obj.AlignedByteOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InputSlotClass", toStringFlags, tabCount, tabSize, Quote(ToString(obj.InputSlotClass)));
            FieldToString(strStrm, false, "InstanceDataStepRate", toStringFlags, tabCount, tabSize, ToString(obj.InstanceDataStepRate, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_SO_DECLARATION_ENTRY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_VIEWPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_BOX& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DEPTH_STENCILOP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StencilFailOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilFailOp)));
            FieldToString(strStrm, false, "StencilDepthFailOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilDepthFailOp)));
            FieldToString(strStrm, false, "StencilPassOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilPassOp)));
            FieldToString(strStrm, false, "StencilFunc", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilFunc)));
        }
    );
}

std::string ToString(const D3D12_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthWriteMask", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DepthWriteMask)));
            FieldToString(strStrm, false, "DepthFunc", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DepthFunc)));
            FieldToString(strStrm, false, "StencilEnable", toStringFlags, tabCount, tabSize, ToString(obj.StencilEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilReadMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilReadMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilWriteMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FrontFace", toStringFlags, tabCount, tabSize, ToString(obj.FrontFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BackFace", toStringFlags, tabCount, tabSize, ToString(obj.BackFace, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_DEPTH_STENCIL_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthWriteMask", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DepthWriteMask)));
            FieldToString(strStrm, false, "DepthFunc", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DepthFunc)));
            FieldToString(strStrm, false, "StencilEnable", toStringFlags, tabCount, tabSize, ToString(obj.StencilEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilReadMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilReadMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilWriteMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FrontFace", toStringFlags, tabCount, tabSize, ToString(obj.FrontFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BackFace", toStringFlags, tabCount, tabSize, ToString(obj.BackFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBoundsTestEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthBoundsTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_DEPTH_STENCILOP_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StencilFailOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilFailOp)));
            FieldToString(strStrm, false, "StencilDepthFailOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilDepthFailOp)));
            FieldToString(strStrm, false, "StencilPassOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilPassOp)));
            FieldToString(strStrm, false, "StencilFunc", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilFunc)));
            FieldToString(strStrm, false, "StencilReadMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilReadMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilWriteMask, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_DEPTH_STENCIL_DESC2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthWriteMask", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DepthWriteMask)));
            FieldToString(strStrm, false, "DepthFunc", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DepthFunc)));
            FieldToString(strStrm, false, "StencilEnable", toStringFlags, tabCount, tabSize, ToString(obj.StencilEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FrontFace", toStringFlags, tabCount, tabSize, ToString(obj.FrontFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BackFace", toStringFlags, tabCount, tabSize, ToString(obj.BackFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBoundsTestEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthBoundsTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RENDER_TARGET_BLEND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BlendEnable", toStringFlags, tabCount, tabSize, ToString(obj.BlendEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "LogicOpEnable", toStringFlags, tabCount, tabSize, ToString(obj.LogicOpEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SrcBlend", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SrcBlend)));
            FieldToString(strStrm, false, "DestBlend", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DestBlend)));
            FieldToString(strStrm, false, "BlendOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BlendOp)));
            FieldToString(strStrm, false, "SrcBlendAlpha", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SrcBlendAlpha)));
            FieldToString(strStrm, false, "DestBlendAlpha", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DestBlendAlpha)));
            FieldToString(strStrm, false, "BlendOpAlpha", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BlendOpAlpha)));
            FieldToString(strStrm, false, "LogicOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.LogicOp)));
            FieldToString(strStrm, false, "RenderTargetWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.RenderTargetWriteMask, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_BLEND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_RASTERIZER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FillMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.FillMode)));
            FieldToString(strStrm, false, "CullMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.CullMode)));
            FieldToString(strStrm, false, "FrontCounterClockwise", toStringFlags, tabCount, tabSize, ToString(obj.FrontCounterClockwise, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBias", toStringFlags, tabCount, tabSize, ToString(obj.DepthBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBiasClamp", toStringFlags, tabCount, tabSize, ToString(obj.DepthBiasClamp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SlopeScaledDepthBias", toStringFlags, tabCount, tabSize, ToString(obj.SlopeScaledDepthBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthClipEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthClipEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MultisampleEnable", toStringFlags, tabCount, tabSize, ToString(obj.MultisampleEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AntialiasedLineEnable", toStringFlags, tabCount, tabSize, ToString(obj.AntialiasedLineEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ForcedSampleCount", toStringFlags, tabCount, tabSize, ToString(obj.ForcedSampleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConservativeRaster", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ConservativeRaster)));
        }
    );
}

std::string ToString(const D3D12_SHADER_BYTECODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pShaderBytecode", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pShaderBytecode));
            FieldToString(strStrm, false, "BytecodeLength", toStringFlags, tabCount, tabSize, ToString(obj.BytecodeLength, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_STREAM_OUTPUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_INPUT_LAYOUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pInputElementDescs", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumElements, obj.pInputElementDescs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, ToString(obj.NumElements, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_CACHED_PIPELINE_STATE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pCachedBlob", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pCachedBlob));
            FieldToString(strStrm, false, "CachedBlobSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.CachedBlobSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_GRAPHICS_PIPELINE_STATE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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
            FieldToString(strStrm, false, "IBStripCutValue", toStringFlags, tabCount, tabSize, Quote(ToString(obj.IBStripCutValue)));
            FieldToString(strStrm, false, "PrimitiveTopologyType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.PrimitiveTopologyType)));
            FieldToString(strStrm, false, "NumRenderTargets", toStringFlags, tabCount, tabSize, ToString(obj.NumRenderTargets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RTVFormats", toStringFlags, tabCount, tabSize, EnumArrayToString(8, obj.RTVFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DSVFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DSVFormat)));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CachedPSO", toStringFlags, tabCount, tabSize, ToString(obj.CachedPSO, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_COMPUTE_PIPELINE_STATE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pRootSignature", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pRootSignature));
            FieldToString(strStrm, false, "CS", toStringFlags, tabCount, tabSize, ToString(obj.CS, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CachedPSO", toStringFlags, tabCount, tabSize, ToString(obj.CachedPSO, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_RT_FORMAT_ARRAY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RTFormats", toStringFlags, tabCount, tabSize, EnumArrayToString(8, obj.RTFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumRenderTargets", toStringFlags, tabCount, tabSize, ToString(obj.NumRenderTargets, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DoublePrecisionFloatShaderOps", toStringFlags, tabCount, tabSize, ToString(obj.DoublePrecisionFloatShaderOps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputMergerLogicOp", toStringFlags, tabCount, tabSize, ToString(obj.OutputMergerLogicOp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinPrecisionSupport", toStringFlags, tabCount, tabSize, Quote(ToString(obj.MinPrecisionSupport)));
            FieldToString(strStrm, false, "TiledResourcesTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.TiledResourcesTier)));
            FieldToString(strStrm, false, "ResourceBindingTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ResourceBindingTier)));
            FieldToString(strStrm, false, "PSSpecifiedStencilRefSupported", toStringFlags, tabCount, tabSize, ToString(obj.PSSpecifiedStencilRefSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TypedUAVLoadAdditionalFormats", toStringFlags, tabCount, tabSize, ToString(obj.TypedUAVLoadAdditionalFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ROVsSupported", toStringFlags, tabCount, tabSize, ToString(obj.ROVsSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConservativeRasterizationTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ConservativeRasterizationTier)));
            FieldToString(strStrm, false, "MaxGPUVirtualAddressBitsPerResource", toStringFlags, tabCount, tabSize, ToString(obj.MaxGPUVirtualAddressBitsPerResource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StandardSwizzle64KBSupported", toStringFlags, tabCount, tabSize, ToString(obj.StandardSwizzle64KBSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CrossNodeSharingTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.CrossNodeSharingTier)));
            FieldToString(strStrm, false, "CrossAdapterRowMajorTextureSupported", toStringFlags, tabCount, tabSize, ToString(obj.CrossAdapterRowMajorTextureSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation", toStringFlags, tabCount, tabSize, ToString(obj.VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ResourceHeapTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ResourceHeapTier)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthBoundsTestSupported", toStringFlags, tabCount, tabSize, ToString(obj.DepthBoundsTestSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ProgrammableSamplePositionsTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ProgrammableSamplePositionsTier)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "HighestVersion", toStringFlags, tabCount, tabSize, Quote(ToString(obj.HighestVersion)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_ARCHITECTURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_FEATURE_DATA_ARCHITECTURE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_FEATURE_DATA_FEATURE_LEVELS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumFeatureLevels", toStringFlags, tabCount, tabSize, ToString(obj.NumFeatureLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFeatureLevelsRequested", toStringFlags, tabCount, tabSize, EnumArrayToString(obj.NumFeatureLevels, obj.pFeatureLevelsRequested, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxSupportedFeatureLevel", toStringFlags, tabCount, tabSize, Quote(ToString(obj.MaxSupportedFeatureLevel)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_SHADER_MODEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "HighestShaderModel", toStringFlags, tabCount, tabSize, Quote(ToString(obj.HighestShaderModel)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_FORMAT_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "Support1", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Support1)));
            FieldToString(strStrm, false, "Support2", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Support2)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "SampleCount", toStringFlags, tabCount, tabSize, ToString(obj.SampleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "NumQualityLevels", toStringFlags, tabCount, tabSize, ToString(obj.NumQualityLevels, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_FORMAT_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "PlaneCount", toStringFlags, tabCount, tabSize, ToString(obj.PlaneCount, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxGPUVirtualAddressBitsPerResource", toStringFlags, tabCount, tabSize, ToString(obj.MaxGPUVirtualAddressBitsPerResource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxGPUVirtualAddressBitsPerProcess", toStringFlags, tabCount, tabSize, ToString(obj.MaxGPUVirtualAddressBitsPerProcess, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_SHADER_CACHE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SupportFlags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SupportFlags)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CommandListType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.CommandListType)));
            FieldToString(strStrm, false, "Priority", toStringFlags, tabCount, tabSize, ToString(obj.Priority, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PriorityForTypeIsSupported", toStringFlags, tabCount, tabSize, ToString(obj.PriorityForTypeIsSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CopyQueueTimestampQueriesSupported", toStringFlags, tabCount, tabSize, ToString(obj.CopyQueueTimestampQueriesSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CastingFullyTypedFormatSupported", toStringFlags, tabCount, tabSize, ToString(obj.CastingFullyTypedFormatSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WriteBufferImmediateSupportFlags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.WriteBufferImmediateSupportFlags)));
            FieldToString(strStrm, false, "ViewInstancingTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ViewInstancingTier)));
            FieldToString(strStrm, false, "BarycentricsSupported", toStringFlags, tabCount, tabSize, ToString(obj.BarycentricsSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_EXISTING_HEAPS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Supported", toStringFlags, tabCount, tabSize, ToString(obj.Supported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_DISPLAYABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DisplayableTexture", toStringFlags, tabCount, tabSize, ToString(obj.DisplayableTexture, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SharedResourceCompatibilityTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SharedResourceCompatibilityTier)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS4& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MSAA64KBAlignedTextureSupported", toStringFlags, tabCount, tabSize, ToString(obj.MSAA64KBAlignedTextureSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SharedResourceCompatibilityTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SharedResourceCompatibilityTier)));
            FieldToString(strStrm, false, "Native16BitShaderOpsSupported", toStringFlags, tabCount, tabSize, ToString(obj.Native16BitShaderOpsSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_SERIALIZATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, ToString(obj.NodeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HeapSerializationTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.HeapSerializationTier)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_CROSS_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SharingTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SharingTier)));
            FieldToString(strStrm, false, "AtomicShaderInstructions", toStringFlags, tabCount, tabSize, ToString(obj.AtomicShaderInstructions, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS5& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SRVOnlyTiledResourceTier3", toStringFlags, tabCount, tabSize, ToString(obj.SRVOnlyTiledResourceTier3, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RenderPassesTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.RenderPassesTier)));
            FieldToString(strStrm, false, "RaytracingTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.RaytracingTier)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS6& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AdditionalShadingRatesSupported", toStringFlags, tabCount, tabSize, ToString(obj.AdditionalShadingRatesSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PerPrimitiveShadingRateSupportedWithViewportIndexing", toStringFlags, tabCount, tabSize, ToString(obj.PerPrimitiveShadingRateSupportedWithViewportIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VariableShadingRateTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.VariableShadingRateTier)));
            FieldToString(strStrm, false, "ShadingRateImageTileSize", toStringFlags, tabCount, tabSize, ToString(obj.ShadingRateImageTileSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BackgroundProcessingSupported", toStringFlags, tabCount, tabSize, ToString(obj.BackgroundProcessingSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS7& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MeshShaderTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.MeshShaderTier)));
            FieldToString(strStrm, false, "SamplerFeedbackTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SamplerFeedbackTier)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_QUERY_META_COMMAND& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS8& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnalignedBlockTexturesSupported", toStringFlags, tabCount, tabSize, ToString(obj.UnalignedBlockTexturesSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS9& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MeshShaderPipelineStatsSupported", toStringFlags, tabCount, tabSize, ToString(obj.MeshShaderPipelineStatsSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MeshShaderSupportsFullRangeRenderTargetArrayIndex", toStringFlags, tabCount, tabSize, ToString(obj.MeshShaderSupportsFullRangeRenderTargetArrayIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AtomicInt64OnTypedResourceSupported", toStringFlags, tabCount, tabSize, ToString(obj.AtomicInt64OnTypedResourceSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AtomicInt64OnGroupSharedSupported", toStringFlags, tabCount, tabSize, ToString(obj.AtomicInt64OnGroupSharedSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DerivativesInMeshAndAmplificationShadersSupported", toStringFlags, tabCount, tabSize, ToString(obj.DerivativesInMeshAndAmplificationShadersSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WaveMMATier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.WaveMMATier)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS10& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "VariableRateShadingSumCombinerSupported", toStringFlags, tabCount, tabSize, ToString(obj.VariableRateShadingSumCombinerSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MeshShaderPerPrimitiveShadingRateSupported", toStringFlags, tabCount, tabSize, ToString(obj.MeshShaderPerPrimitiveShadingRateSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS11& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AtomicInt64OnDescriptorHeapResourceSupported", toStringFlags, tabCount, tabSize, ToString(obj.AtomicInt64OnDescriptorHeapResourceSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS12& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MSPrimitivesPipelineStatisticIncludesCulledPrimitives", toStringFlags, tabCount, tabSize, Quote(ToString(obj.MSPrimitivesPipelineStatisticIncludesCulledPrimitives)));
            FieldToString(strStrm, false, "EnhancedBarriersSupported", toStringFlags, tabCount, tabSize, ToString(obj.EnhancedBarriersSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RelaxedFormatCastingSupported", toStringFlags, tabCount, tabSize, ToString(obj.RelaxedFormatCastingSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS13& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnrestrictedBufferTextureCopyPitchSupported", toStringFlags, tabCount, tabSize, ToString(obj.UnrestrictedBufferTextureCopyPitchSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "UnrestrictedVertexElementAlignmentSupported", toStringFlags, tabCount, tabSize, ToString(obj.UnrestrictedVertexElementAlignmentSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InvertedViewportHeightFlipsYSupported", toStringFlags, tabCount, tabSize, ToString(obj.InvertedViewportHeightFlipsYSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InvertedViewportDepthFlipsZSupported", toStringFlags, tabCount, tabSize, ToString(obj.InvertedViewportDepthFlipsZSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TextureCopyBetweenDimensionsSupported", toStringFlags, tabCount, tabSize, ToString(obj.TextureCopyBetweenDimensionsSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AlphaBlendFactorSupported", toStringFlags, tabCount, tabSize, ToString(obj.AlphaBlendFactorSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS14& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AdvancedTextureOpsSupported", toStringFlags, tabCount, tabSize, ToString(obj.AdvancedTextureOpsSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WriteableMSAATexturesSupported", toStringFlags, tabCount, tabSize, ToString(obj.WriteableMSAATexturesSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "IndependentFrontAndBackStencilRefMaskSupported", toStringFlags, tabCount, tabSize, ToString(obj.IndependentFrontAndBackStencilRefMaskSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS15& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "TriangleFanSupported", toStringFlags, tabCount, tabSize, ToString(obj.TriangleFanSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DynamicIndexBufferStripCutSupported", toStringFlags, tabCount, tabSize, ToString(obj.DynamicIndexBufferStripCutSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RESOURCE_ALLOCATION_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, ToString(obj.Alignment, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RESOURCE_ALLOCATION_INFO1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_HEAP_PROPERTIES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "CPUPageProperty", toStringFlags, tabCount, tabSize, Quote(ToString(obj.CPUPageProperty)));
            FieldToString(strStrm, false, "MemoryPoolPreference", toStringFlags, tabCount, tabSize, Quote(ToString(obj.MemoryPoolPreference)));
            FieldToString(strStrm, false, "CreationNodeMask", toStringFlags, tabCount, tabSize, ToString(obj.CreationNodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VisibleNodeMask", toStringFlags, tabCount, tabSize, ToString(obj.VisibleNodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Properties", toStringFlags, tabCount, tabSize, ToString(obj.Properties, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, ToString(obj.Alignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_MIP_REGION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_RESOURCE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Dimension", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Dimension)));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, ToString(obj.Alignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthOrArraySize", toStringFlags, tabCount, tabSize, ToString(obj.DepthOrArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Layout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Layout)));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_RESOURCE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Dimension", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Dimension)));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, ToString(obj.Alignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthOrArraySize", toStringFlags, tabCount, tabSize, ToString(obj.DepthOrArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Layout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Layout)));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "SamplerFeedbackMipRegion", toStringFlags, tabCount, tabSize, ToString(obj.SamplerFeedbackMipRegion, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_DEPTH_STENCIL_VALUE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Depth", toStringFlags, tabCount, tabSize, ToString(obj.Depth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Stencil", toStringFlags, tabCount, tabSize, ToString(obj.Stencil, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Begin", toStringFlags, tabCount, tabSize, ToString(obj.Begin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "End", toStringFlags, tabCount, tabSize, ToString(obj.End, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RANGE_UINT64& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Begin", toStringFlags, tabCount, tabSize, ToString(obj.Begin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "End", toStringFlags, tabCount, tabSize, ToString(obj.End, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_SUBRESOURCE_RANGE_UINT64& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Subresource", toStringFlags, tabCount, tabSize, ToString(obj.Subresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Range", toStringFlags, tabCount, tabSize, ToString(obj.Range, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_SUBRESOURCE_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TILED_RESOURCE_COORDINATE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TILE_REGION_SIZE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_SUBRESOURCE_TILING& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TILE_SHAPE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_PACKED_MIP_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_RESOURCE_TRANSITION_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResource));
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, ToString(obj.Subresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StateBefore", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StateBefore)));
            FieldToString(strStrm, false, "StateAfter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StateAfter)));
        }
    );
}

std::string ToString(const D3D12_RESOURCE_ALIASING_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResourceBefore", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResourceBefore));
            FieldToString(strStrm, false, "pResourceAfter", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResourceAfter));
        }
    );
}

std::string ToString(const D3D12_RESOURCE_UAV_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResource));
        }
    );
}

std::string ToString(const D3D12_SUBRESOURCE_FOOTPRINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, ToString(obj.Depth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RowPitch", toStringFlags, tabCount, tabSize, ToString(obj.RowPitch, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Offset", toStringFlags, tabCount, tabSize, ToString(obj.Offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Footprint", toStringFlags, tabCount, tabSize, ToString(obj.Footprint, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_SAMPLE_POSITION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "X", toStringFlags, tabCount, tabSize, ToString(obj.X, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Y", toStringFlags, tabCount, tabSize, ToString(obj.Y, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_VIEW_INSTANCE_LOCATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ViewportArrayIndex", toStringFlags, tabCount, tabSize, ToString(obj.ViewportArrayIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RenderTargetArrayIndex", toStringFlags, tabCount, tabSize, ToString(obj.RenderTargetArrayIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_VIEW_INSTANCING_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ViewInstanceCount", toStringFlags, tabCount, tabSize, ToString(obj.ViewInstanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewInstanceLocations", toStringFlags, tabCount, tabSize, ArrayToString(obj.ViewInstanceCount, obj.pViewInstanceLocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_BUFFER_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, ToString(obj.FirstElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, ToString(obj.NumElements, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StructureByteStride", toStringFlags, tabCount, tabSize, ToString(obj.StructureByteStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_TEX1D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX1D_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX2D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX2D_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX3D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEXCUBE_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEXCUBE_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX2DMS_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, ToString(obj.UnusedField_NothingToDefine, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX2DMS_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Location", toStringFlags, tabCount, tabSize, ToString(obj.Location, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_CONSTANT_BUFFER_VIEW_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferLocation", toStringFlags, tabCount, tabSize, ToString(obj.BufferLocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_SAMPLER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Filter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Filter)));
            FieldToString(strStrm, false, "AddressU", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AddressU)));
            FieldToString(strStrm, false, "AddressV", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AddressV)));
            FieldToString(strStrm, false, "AddressW", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AddressW)));
            FieldToString(strStrm, false, "MipLODBias", toStringFlags, tabCount, tabSize, ToString(obj.MipLODBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxAnisotropy", toStringFlags, tabCount, tabSize, ToString(obj.MaxAnisotropy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ComparisonFunc", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ComparisonFunc)));
            FieldToString(strStrm, false, "BorderColor", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.BorderColor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinLOD", toStringFlags, tabCount, tabSize, ToString(obj.MinLOD, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxLOD", toStringFlags, tabCount, tabSize, ToString(obj.MaxLOD, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_BUFFER_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, ToString(obj.FirstElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, ToString(obj.NumElements, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StructureByteStride", toStringFlags, tabCount, tabSize, ToString(obj.StructureByteStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CounterOffsetInBytes", toStringFlags, tabCount, tabSize, ToString(obj.CounterOffsetInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_TEX1D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX1D_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX2D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX2D_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX2DMS_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, ToString(obj.UnusedField_NothingToDefine, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX2DMS_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX3D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_BUFFER_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, ToString(obj.FirstElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, ToString(obj.NumElements, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX1D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX1D_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX2D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX2DMS_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, ToString(obj.UnusedField_NothingToDefine, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX2D_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX2DMS_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX3D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX1D_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX1D_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX2D_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX2D_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_TEX2DMS_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, ToString(obj.UnusedField_NothingToDefine, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_TEX2DMS_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_DESCRIPTOR_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "NumDescriptors", toStringFlags, tabCount, tabSize, ToString(obj.NumDescriptors, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_DESCRIPTOR_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RangeType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.RangeType)));
            FieldToString(strStrm, false, "NumDescriptors", toStringFlags, tabCount, tabSize, ToString(obj.NumDescriptors, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BaseShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.BaseShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OffsetInDescriptorsFromTableStart", toStringFlags, tabCount, tabSize, ToString(obj.OffsetInDescriptorsFromTableStart, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_ROOT_DESCRIPTOR_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumDescriptorRanges", toStringFlags, tabCount, tabSize, ToString(obj.NumDescriptorRanges, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorRanges", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumDescriptorRanges, obj.pDescriptorRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_ROOT_CONSTANTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_ROOT_DESCRIPTOR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.ShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_STATIC_SAMPLER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Filter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Filter)));
            FieldToString(strStrm, false, "AddressU", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AddressU)));
            FieldToString(strStrm, false, "AddressV", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AddressV)));
            FieldToString(strStrm, false, "AddressW", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AddressW)));
            FieldToString(strStrm, false, "MipLODBias", toStringFlags, tabCount, tabSize, ToString(obj.MipLODBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxAnisotropy", toStringFlags, tabCount, tabSize, ToString(obj.MaxAnisotropy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ComparisonFunc", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ComparisonFunc)));
            FieldToString(strStrm, false, "BorderColor", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BorderColor)));
            FieldToString(strStrm, false, "MinLOD", toStringFlags, tabCount, tabSize, ToString(obj.MinLOD, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxLOD", toStringFlags, tabCount, tabSize, ToString(obj.MaxLOD, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.ShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ShaderVisibility", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ShaderVisibility)));
        }
    );
}

std::string ToString(const D3D12_ROOT_SIGNATURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumParameters", toStringFlags, tabCount, tabSize, ToString(obj.NumParameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pParameters", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumParameters, obj.pParameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumStaticSamplers", toStringFlags, tabCount, tabSize, ToString(obj.NumStaticSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStaticSamplers", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumStaticSamplers, obj.pStaticSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_DESCRIPTOR_RANGE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RangeType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.RangeType)));
            FieldToString(strStrm, false, "NumDescriptors", toStringFlags, tabCount, tabSize, ToString(obj.NumDescriptors, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BaseShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.BaseShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "OffsetInDescriptorsFromTableStart", toStringFlags, tabCount, tabSize, ToString(obj.OffsetInDescriptorsFromTableStart, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_ROOT_DESCRIPTOR_TABLE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumDescriptorRanges", toStringFlags, tabCount, tabSize, ToString(obj.NumDescriptorRanges, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorRanges", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumDescriptorRanges, obj.pDescriptorRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_ROOT_DESCRIPTOR1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderRegister", toStringFlags, tabCount, tabSize, ToString(obj.ShaderRegister, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, ToString(obj.RegisterSpace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_ROOT_SIGNATURE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumParameters", toStringFlags, tabCount, tabSize, ToString(obj.NumParameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pParameters", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumParameters, obj.pParameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumStaticSamplers", toStringFlags, tabCount, tabSize, ToString(obj.NumStaticSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStaticSamplers", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumStaticSamplers, obj.pStaticSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_DISCARD_REGION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_QUERY_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "Count", toStringFlags, tabCount, tabSize, ToString(obj.Count, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_QUERY_DATA_PIPELINE_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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
            FieldToString(strStrm, false, "ASInvocations", toStringFlags, tabCount, tabSize, ToString(obj.ASInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MSInvocations", toStringFlags, tabCount, tabSize, ToString(obj.MSInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MSPrimitives", toStringFlags, tabCount, tabSize, ToString(obj.MSPrimitives, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_QUERY_DATA_SO_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumPrimitivesWritten", toStringFlags, tabCount, tabSize, ToString(obj.NumPrimitivesWritten, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PrimitivesStorageNeeded", toStringFlags, tabCount, tabSize, ToString(obj.PrimitivesStorageNeeded, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_STREAM_OUTPUT_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DRAW_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DRAW_INDEXED_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DISPATCH_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_VERTEX_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_INDEX_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferLocation", toStringFlags, tabCount, tabSize, ToString(obj.BufferLocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
        }
    );
}

std::string ToString(const D3D12_COMMAND_SIGNATURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Dest", toStringFlags, tabCount, tabSize, ToString(obj.Dest, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Value", toStringFlags, tabCount, tabSize, ToString(obj.Value, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, ToString(obj.NodeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Support", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Support)));
        }
    );
}

std::string ToString(const D3D12_PROTECTED_RESOURCE_SESSION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_META_COMMAND_PARAMETER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Name", toStringFlags, tabCount, tabSize, (obj.Name ? ToString(*obj.Name, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "RequiredResourceState", toStringFlags, tabCount, tabSize, Quote(ToString(obj.RequiredResourceState)));
            FieldToString(strStrm, false, "StructureOffset", toStringFlags, tabCount, tabSize, ToString(obj.StructureOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_META_COMMAND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Id", toStringFlags, tabCount, tabSize, ToString(obj.Id, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Name", toStringFlags, tabCount, tabSize, (obj.Name ? ToString(*obj.Name, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "InitializationDirtyState", toStringFlags, tabCount, tabSize, Quote(ToString(obj.InitializationDirtyState)));
            FieldToString(strStrm, false, "ExecutionDirtyState", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ExecutionDirtyState)));
        }
    );
}

std::string ToString(const D3D12_STATE_OBJECT_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_GLOBAL_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pGlobalRootSignature", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pGlobalRootSignature));
        }
    );
}

std::string ToString(const D3D12_LOCAL_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pLocalRootSignature", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pLocalRootSignature));
        }
    );
}

std::string ToString(const D3D12_NODE_MASK& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_EXPORT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Name", toStringFlags, tabCount, tabSize, (obj.Name ? ToString(*obj.Name, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "ExportToRename", toStringFlags, tabCount, tabSize, (obj.ExportToRename ? ToString(*obj.ExportToRename, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_DXIL_LIBRARY_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_EXISTING_COLLECTION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_HIT_GROUP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "HitGroupExport", toStringFlags, tabCount, tabSize, (obj.HitGroupExport ? ToString(*obj.HitGroupExport, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "AnyHitShaderImport", toStringFlags, tabCount, tabSize, (obj.AnyHitShaderImport ? ToString(*obj.AnyHitShaderImport, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "ClosestHitShaderImport", toStringFlags, tabCount, tabSize, (obj.ClosestHitShaderImport ? ToString(*obj.ClosestHitShaderImport, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "IntersectionShaderImport", toStringFlags, tabCount, tabSize, (obj.IntersectionShaderImport ? ToString(*obj.IntersectionShaderImport, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

std::string ToString(const D3D12_RAYTRACING_SHADER_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxPayloadSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.MaxPayloadSizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxAttributeSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.MaxAttributeSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RAYTRACING_PIPELINE_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxTraceRecursionDepth", toStringFlags, tabCount, tabSize, ToString(obj.MaxTraceRecursionDepth, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RAYTRACING_PIPELINE_CONFIG1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxTraceRecursionDepth", toStringFlags, tabCount, tabSize, ToString(obj.MaxTraceRecursionDepth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StartAddress", toStringFlags, tabCount, tabSize, ToString(obj.StartAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StrideInBytes", toStringFlags, tabCount, tabSize, ToString(obj.StrideInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StartAddress", toStringFlags, tabCount, tabSize, ToString(obj.StartAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Transform3x4", toStringFlags, tabCount, tabSize, ToString(obj.Transform3x4, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "IndexFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.IndexFormat)));
            FieldToString(strStrm, false, "VertexFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.VertexFormat)));
            FieldToString(strStrm, false, "IndexCount", toStringFlags, tabCount, tabSize, ToString(obj.IndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VertexCount", toStringFlags, tabCount, tabSize, ToString(obj.VertexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "IndexBuffer", toStringFlags, tabCount, tabSize, ToString(obj.IndexBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "VertexBuffer", toStringFlags, tabCount, tabSize, ToString(obj.VertexBuffer, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RAYTRACING_AABB& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AABBCount", toStringFlags, tabCount, tabSize, ToString(obj.AABBCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AABBs", toStringFlags, tabCount, tabSize, ToString(obj.AABBs, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DestBuffer", toStringFlags, tabCount, tabSize, ToString(obj.DestBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InfoType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.InfoType)));
        }
    );
}

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CompactedSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.CompactedSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DecodedSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.DecodedSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "NumDescs", toStringFlags, tabCount, tabSize, ToString(obj.NumDescs, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SerializedSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SerializedSizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumBottomLevelAccelerationStructurePointers", toStringFlags, tabCount, tabSize, ToString(obj.NumBottomLevelAccelerationStructurePointers, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DriverOpaqueGUID", toStringFlags, tabCount, tabSize, ToString(obj.DriverOpaqueGUID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DriverOpaqueVersioningData", toStringFlags, tabCount, tabSize, ArrayToString(16, obj.DriverOpaqueVersioningData, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CurrentSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.CurrentSizeInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_AUTO_BREADCRUMB_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DRED_BREADCRUMB_CONTEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BreadcrumbIndex", toStringFlags, tabCount, tabSize, ToString(obj.BreadcrumbIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pContextString", toStringFlags, tabCount, tabSize, (obj.pContextString ? ToString(*obj.pContextString, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

std::string ToString(const D3D12_AUTO_BREADCRUMB_NODE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DEVICE_REMOVED_EXTENDED_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "pHeadAutoBreadcrumbNode", toStringFlags, tabCount, tabSize, (obj.pHeadAutoBreadcrumbNode ? ToString(*obj.pHeadAutoBreadcrumbNode, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

std::string ToString(const D3D12_DRED_ALLOCATION_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ObjectNameA", toStringFlags, tabCount, tabSize, (obj.ObjectNameA ? ToString(*obj.ObjectNameA, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "ObjectNameW", toStringFlags, tabCount, tabSize, (obj.ObjectNameW ? ToString(*obj.ObjectNameW, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "AllocationType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AllocationType)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, (obj.pNext ? ToString(*obj.pNext, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

std::string ToString(const D3D12_DRED_ALLOCATION_NODE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ObjectNameA", toStringFlags, tabCount, tabSize, (obj.ObjectNameA ? ToString(*obj.ObjectNameA, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "ObjectNameW", toStringFlags, tabCount, tabSize, (obj.ObjectNameW ? ToString(*obj.ObjectNameW, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "AllocationType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AllocationType)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, (obj.pNext ? ToString(*obj.pNext, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pObject", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pObject));
        }
    );
}

std::string ToString(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pHeadAutoBreadcrumbNode", toStringFlags, tabCount, tabSize, (obj.pHeadAutoBreadcrumbNode ? ToString(*obj.pHeadAutoBreadcrumbNode, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

std::string ToString(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pHeadAutoBreadcrumbNode", toStringFlags, tabCount, tabSize, (obj.pHeadAutoBreadcrumbNode ? ToString(*obj.pHeadAutoBreadcrumbNode, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

std::string ToString(const D3D12_DRED_PAGE_FAULT_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DRED_PAGE_FAULT_OUTPUT1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DRED_PAGE_FAULT_OUTPUT2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PageFaultVA", toStringFlags, tabCount, tabSize, ToString(obj.PageFaultVA, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pHeadExistingAllocationNode", toStringFlags, tabCount, tabSize, (obj.pHeadExistingAllocationNode ? ToString(*obj.pHeadExistingAllocationNode, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pHeadRecentFreedAllocationNode", toStringFlags, tabCount, tabSize, (obj.pHeadRecentFreedAllocationNode ? ToString(*obj.pHeadRecentFreedAllocationNode, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "PageFaultFlags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.PageFaultFlags)));
        }
    );
}

std::string ToString(const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceRemovedReason", toStringFlags, tabCount, tabSize, ToString(obj.DeviceRemovedReason, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AutoBreadcrumbsOutput", toStringFlags, tabCount, tabSize, ToString(obj.AutoBreadcrumbsOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PageFaultOutput", toStringFlags, tabCount, tabSize, ToString(obj.PageFaultOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceState", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DeviceState)));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, ToString(obj.NodeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Count", toStringFlags, tabCount, tabSize, ToString(obj.Count, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeMask", toStringFlags, tabCount, tabSize, ToString(obj.NodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "ProtectionType", toStringFlags, tabCount, tabSize, ToString(obj.ProtectionType, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ClearValue", toStringFlags, tabCount, tabSize, ToString(obj.ClearValue, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pSrcResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pSrcResource));
            FieldToString(strStrm, false, "pDstResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pDstResource));
            FieldToString(strStrm, false, "SubresourceCount", toStringFlags, tabCount, tabSize, ToString(obj.SubresourceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubresourceParameters", toStringFlags, tabCount, tabSize, ArrayToString(obj.SubresourceCount, obj.pSubresourceParameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "ResolveMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ResolveMode)));
            FieldToString(strStrm, false, "PreserveResolveSource", toStringFlags, tabCount, tabSize, ToString(obj.PreserveResolveSource, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_RENDER_PASS_RENDER_TARGET_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DISPATCH_RAYS_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_SHADER_CACHE_SESSION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Identifier", toStringFlags, tabCount, tabSize, ToString(obj.Identifier, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Mode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Mode)));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "MaximumInMemoryCacheSizeBytes", toStringFlags, tabCount, tabSize, ToString(obj.MaximumInMemoryCacheSizeBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaximumInMemoryCacheEntries", toStringFlags, tabCount, tabSize, ToString(obj.MaximumInMemoryCacheEntries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaximumValueFileSizeBytes", toStringFlags, tabCount, tabSize, ToString(obj.MaximumValueFileSizeBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Version", toStringFlags, tabCount, tabSize, ToString(obj.Version, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_BARRIER_SUBRESOURCE_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "IndexOrFirstMipLevel", toStringFlags, tabCount, tabSize, ToString(obj.IndexOrFirstMipLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumMipLevels", toStringFlags, tabCount, tabSize, ToString(obj.NumMipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumArraySlices", toStringFlags, tabCount, tabSize, ToString(obj.NumArraySlices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstPlane", toStringFlags, tabCount, tabSize, ToString(obj.FirstPlane, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumPlanes", toStringFlags, tabCount, tabSize, ToString(obj.NumPlanes, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_GLOBAL_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SyncBefore", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SyncBefore)));
            FieldToString(strStrm, false, "SyncAfter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SyncAfter)));
            FieldToString(strStrm, false, "AccessBefore", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AccessBefore)));
            FieldToString(strStrm, false, "AccessAfter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AccessAfter)));
        }
    );
}

std::string ToString(const D3D12_TEXTURE_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SyncBefore", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SyncBefore)));
            FieldToString(strStrm, false, "SyncAfter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SyncAfter)));
            FieldToString(strStrm, false, "AccessBefore", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AccessBefore)));
            FieldToString(strStrm, false, "AccessAfter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AccessAfter)));
            FieldToString(strStrm, false, "LayoutBefore", toStringFlags, tabCount, tabSize, Quote(ToString(obj.LayoutBefore)));
            FieldToString(strStrm, false, "LayoutAfter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.LayoutAfter)));
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResource));
            FieldToString(strStrm, false, "Subresources", toStringFlags, tabCount, tabSize, ToString(obj.Subresources, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
        }
    );
}

std::string ToString(const D3D12_BUFFER_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SyncBefore", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SyncBefore)));
            FieldToString(strStrm, false, "SyncAfter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SyncAfter)));
            FieldToString(strStrm, false, "AccessBefore", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AccessBefore)));
            FieldToString(strStrm, false, "AccessAfter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AccessAfter)));
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResource));
            FieldToString(strStrm, false, "Offset", toStringFlags, tabCount, tabSize, ToString(obj.Offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Size", toStringFlags, tabCount, tabSize, ToString(obj.Size, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_SUBRESOURCE_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_MEMCPY_DEST& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_DEVICE_CONFIGURATION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "GpuBasedValidationFlags", toStringFlags, tabCount, tabSize, ToString(obj.GpuBasedValidationFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SDKVersion", toStringFlags, tabCount, tabSize, ToString(obj.SDKVersion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumEnabledExperimentalFeatures", toStringFlags, tabCount, tabSize, ToString(obj.NumEnabledExperimentalFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_DISPATCH_MESH_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D_SHADER_MACRO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Name", toStringFlags, tabCount, tabSize, (obj.Name ? ToString(*obj.Name, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "Definition", toStringFlags, tabCount, tabSize, (obj.Definition ? ToString(*obj.Definition, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

std::string ToString(const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxMessagesPerCommandList", toStringFlags, tabCount, tabSize, ToString(obj.MaxMessagesPerCommandList, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DefaultShaderPatchMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DefaultShaderPatchMode)));
            FieldToString(strStrm, false, "PipelineStateCreateFlags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.PipelineStateCreateFlags)));
        }
    );
}

std::string ToString(const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SlowdownFactor", toStringFlags, tabCount, tabSize, ToString(obj.SlowdownFactor, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderPatchMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ShaderPatchMode)));
        }
    );
}

std::string ToString(const D3D12_MESSAGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Category", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Category)));
            FieldToString(strStrm, false, "Severity", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Severity)));
            FieldToString(strStrm, false, "ID", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ID)));
            FieldToString(strStrm, false, "pDescription", toStringFlags, tabCount, tabSize, (obj.pDescription ? ToString(*obj.pDescription, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "DescriptionByteLength", toStringFlags, tabCount, tabSize, ToString(obj.DescriptionByteLength, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D12_INFO_QUEUE_FILTER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D12_INFO_QUEUE_FILTER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AllowList", toStringFlags, tabCount, tabSize, ToString(obj.AllowList, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DenyList", toStringFlags, tabCount, tabSize, ToString(obj.DenyList, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_INPUT_ELEMENT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SemanticName", toStringFlags, tabCount, tabSize, (obj.SemanticName ? ToString(*obj.SemanticName, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "SemanticIndex", toStringFlags, tabCount, tabSize, ToString(obj.SemanticIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "InputSlot", toStringFlags, tabCount, tabSize, ToString(obj.InputSlot, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AlignedByteOffset", toStringFlags, tabCount, tabSize, ToString(obj.AlignedByteOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InputSlotClass", toStringFlags, tabCount, tabSize, Quote(ToString(obj.InputSlotClass)));
            FieldToString(strStrm, false, "InstanceDataStepRate", toStringFlags, tabCount, tabSize, ToString(obj.InstanceDataStepRate, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_SO_DECLARATION_ENTRY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_VIEWPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_DRAW_INSTANCED_INDIRECT_ARGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_DRAW_INDEXED_INSTANCED_INDIRECT_ARGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_BOX& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_DEPTH_STENCILOP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StencilFailOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilFailOp)));
            FieldToString(strStrm, false, "StencilDepthFailOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilDepthFailOp)));
            FieldToString(strStrm, false, "StencilPassOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilPassOp)));
            FieldToString(strStrm, false, "StencilFunc", toStringFlags, tabCount, tabSize, Quote(ToString(obj.StencilFunc)));
        }
    );
}

std::string ToString(const D3D11_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthWriteMask", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DepthWriteMask)));
            FieldToString(strStrm, false, "DepthFunc", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DepthFunc)));
            FieldToString(strStrm, false, "StencilEnable", toStringFlags, tabCount, tabSize, ToString(obj.StencilEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilReadMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilReadMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StencilWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.StencilWriteMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FrontFace", toStringFlags, tabCount, tabSize, ToString(obj.FrontFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BackFace", toStringFlags, tabCount, tabSize, ToString(obj.BackFace, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_RENDER_TARGET_BLEND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BlendEnable", toStringFlags, tabCount, tabSize, ToString(obj.BlendEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SrcBlend", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SrcBlend)));
            FieldToString(strStrm, false, "DestBlend", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DestBlend)));
            FieldToString(strStrm, false, "BlendOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BlendOp)));
            FieldToString(strStrm, false, "SrcBlendAlpha", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SrcBlendAlpha)));
            FieldToString(strStrm, false, "DestBlendAlpha", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DestBlendAlpha)));
            FieldToString(strStrm, false, "BlendOpAlpha", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BlendOpAlpha)));
            FieldToString(strStrm, false, "RenderTargetWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.RenderTargetWriteMask, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_BLEND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_RASTERIZER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FillMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.FillMode)));
            FieldToString(strStrm, false, "CullMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.CullMode)));
            FieldToString(strStrm, false, "FrontCounterClockwise", toStringFlags, tabCount, tabSize, ToString(obj.FrontCounterClockwise, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBias", toStringFlags, tabCount, tabSize, ToString(obj.DepthBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBiasClamp", toStringFlags, tabCount, tabSize, ToString(obj.DepthBiasClamp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SlopeScaledDepthBias", toStringFlags, tabCount, tabSize, ToString(obj.SlopeScaledDepthBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthClipEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthClipEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ScissorEnable", toStringFlags, tabCount, tabSize, ToString(obj.ScissorEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MultisampleEnable", toStringFlags, tabCount, tabSize, ToString(obj.MultisampleEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AntialiasedLineEnable", toStringFlags, tabCount, tabSize, ToString(obj.AntialiasedLineEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_MAPPED_SUBRESOURCE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pData", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pData));
            FieldToString(strStrm, false, "RowPitch", toStringFlags, tabCount, tabSize, ToString(obj.RowPitch, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthPitch", toStringFlags, tabCount, tabSize, ToString(obj.DepthPitch, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_BUFFER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ByteWidth", toStringFlags, tabCount, tabSize, ToString(obj.ByteWidth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Usage", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Usage)));
            FieldToString(strStrm, false, "BindFlags", toStringFlags, tabCount, tabSize, ToString(obj.BindFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CPUAccessFlags", toStringFlags, tabCount, tabSize, ToString(obj.CPUAccessFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MiscFlags", toStringFlags, tabCount, tabSize, ToString(obj.MiscFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StructureByteStride", toStringFlags, tabCount, tabSize, ToString(obj.StructureByteStride, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEXTURE1D_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "Usage", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Usage)));
            FieldToString(strStrm, false, "BindFlags", toStringFlags, tabCount, tabSize, ToString(obj.BindFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CPUAccessFlags", toStringFlags, tabCount, tabSize, ToString(obj.CPUAccessFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MiscFlags", toStringFlags, tabCount, tabSize, ToString(obj.MiscFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEXTURE2D_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Usage", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Usage)));
            FieldToString(strStrm, false, "BindFlags", toStringFlags, tabCount, tabSize, ToString(obj.BindFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CPUAccessFlags", toStringFlags, tabCount, tabSize, ToString(obj.CPUAccessFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MiscFlags", toStringFlags, tabCount, tabSize, ToString(obj.MiscFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEXTURE3D_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, ToString(obj.Depth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "Usage", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Usage)));
            FieldToString(strStrm, false, "BindFlags", toStringFlags, tabCount, tabSize, ToString(obj.BindFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CPUAccessFlags", toStringFlags, tabCount, tabSize, ToString(obj.CPUAccessFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MiscFlags", toStringFlags, tabCount, tabSize, ToString(obj.MiscFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_BUFFEREX_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, ToString(obj.FirstElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, ToString(obj.NumElements, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX1D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX1D_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX3D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEXCUBE_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEXCUBE_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "First2DArrayFace", toStringFlags, tabCount, tabSize, ToString(obj.First2DArrayFace, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumCubes", toStringFlags, tabCount, tabSize, ToString(obj.NumCubes, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2DMS_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, ToString(obj.UnusedField_NothingToDefine, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2DMS_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX1D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX1D_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TEX2D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2DMS_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, ToString(obj.UnusedField_NothingToDefine, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TEX2DMS_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX3D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TEX1D_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX1D_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TEX2D_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TEX2DMS_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, ToString(obj.UnusedField_NothingToDefine, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2DMS_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_BUFFER_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, ToString(obj.FirstElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, ToString(obj.NumElements, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX1D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX1D_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TEX2D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TEX3D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_SAMPLER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Filter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Filter)));
            FieldToString(strStrm, false, "AddressU", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AddressU)));
            FieldToString(strStrm, false, "AddressV", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AddressV)));
            FieldToString(strStrm, false, "AddressW", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AddressW)));
            FieldToString(strStrm, false, "MipLODBias", toStringFlags, tabCount, tabSize, ToString(obj.MipLODBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxAnisotropy", toStringFlags, tabCount, tabSize, ToString(obj.MaxAnisotropy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ComparisonFunc", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ComparisonFunc)));
            FieldToString(strStrm, false, "BorderColor", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.BorderColor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MinLOD", toStringFlags, tabCount, tabSize, ToString(obj.MinLOD, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxLOD", toStringFlags, tabCount, tabSize, ToString(obj.MaxLOD, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_QUERY_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Query", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Query)));
            FieldToString(strStrm, false, "MiscFlags", toStringFlags, tabCount, tabSize, ToString(obj.MiscFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_QUERY_DATA_TIMESTAMP_DISJOINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Frequency", toStringFlags, tabCount, tabSize, ToString(obj.Frequency, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Disjoint", toStringFlags, tabCount, tabSize, ToString(obj.Disjoint, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_QUERY_DATA_PIPELINE_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_QUERY_DATA_SO_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumPrimitivesWritten", toStringFlags, tabCount, tabSize, ToString(obj.NumPrimitivesWritten, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PrimitivesStorageNeeded", toStringFlags, tabCount, tabSize, ToString(obj.PrimitivesStorageNeeded, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_COUNTER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Counter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Counter)));
            FieldToString(strStrm, false, "MiscFlags", toStringFlags, tabCount, tabSize, ToString(obj.MiscFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_COUNTER_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "LastDeviceDependentCounter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.LastDeviceDependentCounter)));
            FieldToString(strStrm, false, "NumSimultaneousCounters", toStringFlags, tabCount, tabSize, ToString(obj.NumSimultaneousCounters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumDetectableParallelUnits", toStringFlags, tabCount, tabSize, ToString(obj.NumDetectableParallelUnits, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_CLASS_INSTANCE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "InstanceId", toStringFlags, tabCount, tabSize, ToString(obj.InstanceId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InstanceIndex", toStringFlags, tabCount, tabSize, ToString(obj.InstanceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TypeId", toStringFlags, tabCount, tabSize, ToString(obj.TypeId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConstantBuffer", toStringFlags, tabCount, tabSize, ToString(obj.ConstantBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BaseConstantBufferOffset", toStringFlags, tabCount, tabSize, ToString(obj.BaseConstantBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BaseTexture", toStringFlags, tabCount, tabSize, ToString(obj.BaseTexture, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BaseSampler", toStringFlags, tabCount, tabSize, ToString(obj.BaseSampler, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Created", toStringFlags, tabCount, tabSize, ToString(obj.Created, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_THREADING& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DriverConcurrentCreates", toStringFlags, tabCount, tabSize, ToString(obj.DriverConcurrentCreates, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DriverCommandLists", toStringFlags, tabCount, tabSize, ToString(obj.DriverCommandLists, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_DOUBLES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DoublePrecisionFloatShaderOps", toStringFlags, tabCount, tabSize, ToString(obj.DoublePrecisionFloatShaderOps, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_FORMAT_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "InFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.InFormat)));
            FieldToString(strStrm, false, "OutFormatSupport", toStringFlags, tabCount, tabSize, ToString(obj.OutFormatSupport, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_FORMAT_SUPPORT2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "InFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.InFormat)));
            FieldToString(strStrm, false, "OutFormatSupport2", toStringFlags, tabCount, tabSize, ToString(obj.OutFormatSupport2, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x", toStringFlags, tabCount, tabSize, ToString(obj.ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "OutputMergerLogicOp", toStringFlags, tabCount, tabSize, ToString(obj.OutputMergerLogicOp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "UAVOnlyRenderingForcedSampleCount", toStringFlags, tabCount, tabSize, ToString(obj.UAVOnlyRenderingForcedSampleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DiscardAPIsSeenByDriver", toStringFlags, tabCount, tabSize, ToString(obj.DiscardAPIsSeenByDriver, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FlagsForUpdateAndCopySeenByDriver", toStringFlags, tabCount, tabSize, ToString(obj.FlagsForUpdateAndCopySeenByDriver, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ClearView", toStringFlags, tabCount, tabSize, ToString(obj.ClearView, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CopyWithOverlap", toStringFlags, tabCount, tabSize, ToString(obj.CopyWithOverlap, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConstantBufferPartialUpdate", toStringFlags, tabCount, tabSize, ToString(obj.ConstantBufferPartialUpdate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConstantBufferOffsetting", toStringFlags, tabCount, tabSize, ToString(obj.ConstantBufferOffsetting, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MapNoOverwriteOnDynamicConstantBuffer", toStringFlags, tabCount, tabSize, ToString(obj.MapNoOverwriteOnDynamicConstantBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MapNoOverwriteOnDynamicBufferSRV", toStringFlags, tabCount, tabSize, ToString(obj.MapNoOverwriteOnDynamicBufferSRV, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MultisampleRTVWithForcedSampleCountOne", toStringFlags, tabCount, tabSize, ToString(obj.MultisampleRTVWithForcedSampleCountOne, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SAD4ShaderInstructions", toStringFlags, tabCount, tabSize, ToString(obj.SAD4ShaderInstructions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ExtendedDoublesShaderInstructions", toStringFlags, tabCount, tabSize, ToString(obj.ExtendedDoublesShaderInstructions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ExtendedResourceSharing", toStringFlags, tabCount, tabSize, ToString(obj.ExtendedResourceSharing, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_ARCHITECTURE_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "TileBasedDeferredRenderer", toStringFlags, tabCount, tabSize, ToString(obj.TileBasedDeferredRenderer, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D9_OPTIONS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FullNonPow2TextureSupport", toStringFlags, tabCount, tabSize, ToString(obj.FullNonPow2TextureSupport, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SupportsDepthAsTextureWithLessEqualComparisonFilter", toStringFlags, tabCount, tabSize, ToString(obj.SupportsDepthAsTextureWithLessEqualComparisonFilter, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PixelShaderMinPrecision", toStringFlags, tabCount, tabSize, ToString(obj.PixelShaderMinPrecision, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AllOtherShaderStagesMinPrecision", toStringFlags, tabCount, tabSize, ToString(obj.AllOtherShaderStagesMinPrecision, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "TiledResourcesTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.TiledResourcesTier)));
            FieldToString(strStrm, false, "MinMaxFiltering", toStringFlags, tabCount, tabSize, ToString(obj.MinMaxFiltering, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ClearViewAlsoSupportsDepthOnlyFormats", toStringFlags, tabCount, tabSize, ToString(obj.ClearViewAlsoSupportsDepthOnlyFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MapOnDefaultBuffers", toStringFlags, tabCount, tabSize, ToString(obj.MapOnDefaultBuffers, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SimpleInstancingSupported", toStringFlags, tabCount, tabSize, ToString(obj.SimpleInstancingSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_MARKER_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Profile", toStringFlags, tabCount, tabSize, ToString(obj.Profile, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D9_OPTIONS1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FullNonPow2TextureSupported", toStringFlags, tabCount, tabSize, ToString(obj.FullNonPow2TextureSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthAsTextureWithLessEqualComparisonFilterSupported", toStringFlags, tabCount, tabSize, ToString(obj.DepthAsTextureWithLessEqualComparisonFilterSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SimpleInstancingSupported", toStringFlags, tabCount, tabSize, ToString(obj.SimpleInstancingSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TextureCubeFaceRenderTargetWithNonCubeDepthStencilSupported", toStringFlags, tabCount, tabSize, ToString(obj.TextureCubeFaceRenderTargetWithNonCubeDepthStencilSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PSSpecifiedStencilRefSupported", toStringFlags, tabCount, tabSize, ToString(obj.PSSpecifiedStencilRefSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TypedUAVLoadAdditionalFormats", toStringFlags, tabCount, tabSize, ToString(obj.TypedUAVLoadAdditionalFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ROVsSupported", toStringFlags, tabCount, tabSize, ToString(obj.ROVsSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConservativeRasterizationTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ConservativeRasterizationTier)));
            FieldToString(strStrm, false, "TiledResourcesTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.TiledResourcesTier)));
            FieldToString(strStrm, false, "MapOnDefaultTextures", toStringFlags, tabCount, tabSize, ToString(obj.MapOnDefaultTextures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StandardSwizzle", toStringFlags, tabCount, tabSize, ToString(obj.StandardSwizzle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "UnifiedMemoryArchitecture", toStringFlags, tabCount, tabSize, ToString(obj.UnifiedMemoryArchitecture, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "VPAndRTArrayIndexFromAnyShaderFeedingRasterizer", toStringFlags, tabCount, tabSize, ToString(obj.VPAndRTArrayIndexFromAnyShaderFeedingRasterizer, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxGPUVirtualAddressBitsPerResource", toStringFlags, tabCount, tabSize, ToString(obj.MaxGPUVirtualAddressBitsPerResource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxGPUVirtualAddressBitsPerProcess", toStringFlags, tabCount, tabSize, ToString(obj.MaxGPUVirtualAddressBitsPerProcess, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_SHADER_CACHE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SupportFlags", toStringFlags, tabCount, tabSize, ToString(obj.SupportFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS5& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SharedResourceTier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SharedResourceTier)));
        }
    );
}

std::string ToString(const CD3D11_VIDEO_DEFAULT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
        }
    );
}

std::string ToString(const D3D11_VIDEO_DECODER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Guid", toStringFlags, tabCount, tabSize, ToString(obj.Guid, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SampleWidth", toStringFlags, tabCount, tabSize, ToString(obj.SampleWidth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SampleHeight", toStringFlags, tabCount, tabSize, ToString(obj.SampleHeight, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.OutputFormat)));
        }
    );
}

std::string ToString(const D3D11_VIDEO_DECODER_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "guidConfigBitstreamEncryption", toStringFlags, tabCount, tabSize, ToString(obj.guidConfigBitstreamEncryption, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "guidConfigMBcontrolEncryption", toStringFlags, tabCount, tabSize, ToString(obj.guidConfigMBcontrolEncryption, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "guidConfigResidDiffEncryption", toStringFlags, tabCount, tabSize, ToString(obj.guidConfigResidDiffEncryption, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigBitstreamRaw", toStringFlags, tabCount, tabSize, ToString(obj.ConfigBitstreamRaw, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigMBcontrolRasterOrder", toStringFlags, tabCount, tabSize, ToString(obj.ConfigMBcontrolRasterOrder, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigResidDiffHost", toStringFlags, tabCount, tabSize, ToString(obj.ConfigResidDiffHost, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigSpatialResid8", toStringFlags, tabCount, tabSize, ToString(obj.ConfigSpatialResid8, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigResid8Subtraction", toStringFlags, tabCount, tabSize, ToString(obj.ConfigResid8Subtraction, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigSpatialHost8or9Clipping", toStringFlags, tabCount, tabSize, ToString(obj.ConfigSpatialHost8or9Clipping, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigSpatialResidInterleaved", toStringFlags, tabCount, tabSize, ToString(obj.ConfigSpatialResidInterleaved, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigIntraResidUnsigned", toStringFlags, tabCount, tabSize, ToString(obj.ConfigIntraResidUnsigned, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigResidDiffAccelerator", toStringFlags, tabCount, tabSize, ToString(obj.ConfigResidDiffAccelerator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigHostInverseScan", toStringFlags, tabCount, tabSize, ToString(obj.ConfigHostInverseScan, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigSpecificIDCT", toStringFlags, tabCount, tabSize, ToString(obj.ConfigSpecificIDCT, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Config4GroupedCoefs", toStringFlags, tabCount, tabSize, ToString(obj.Config4GroupedCoefs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigMinRenderTargetBuffCount", toStringFlags, tabCount, tabSize, ToString(obj.ConfigMinRenderTargetBuffCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigDecoderSpecific", toStringFlags, tabCount, tabSize, ToString(obj.ConfigDecoderSpecific, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AES_CTR_IV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "IV", toStringFlags, tabCount, tabSize, ToString(obj.IV, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Count", toStringFlags, tabCount, tabSize, ToString(obj.Count, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_ENCRYPTED_BLOCK_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumEncryptedBytesAtBeginning", toStringFlags, tabCount, tabSize, ToString(obj.NumEncryptedBytesAtBeginning, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumBytesInSkipPattern", toStringFlags, tabCount, tabSize, ToString(obj.NumBytesInSkipPattern, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumBytesInEncryptPattern", toStringFlags, tabCount, tabSize, ToString(obj.NumBytesInEncryptPattern, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_DECODER_BUFFER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BufferType)));
            FieldToString(strStrm, false, "BufferIndex", toStringFlags, tabCount, tabSize, ToString(obj.BufferIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DataOffset", toStringFlags, tabCount, tabSize, ToString(obj.DataOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, ToString(obj.DataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstMBaddress", toStringFlags, tabCount, tabSize, ToString(obj.FirstMBaddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumMBsInBuffer", toStringFlags, tabCount, tabSize, ToString(obj.NumMBsInBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Stride", toStringFlags, tabCount, tabSize, ToString(obj.Stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ReservedBits", toStringFlags, tabCount, tabSize, ToString(obj.ReservedBits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIV", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pIV));
            FieldToString(strStrm, false, "IVSize", toStringFlags, tabCount, tabSize, ToString(obj.IVSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PartialEncryption", toStringFlags, tabCount, tabSize, ToString(obj.PartialEncryption, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "EncryptedBlockInfo", toStringFlags, tabCount, tabSize, ToString(obj.EncryptedBlockInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_DECODER_EXTENSION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Function", toStringFlags, tabCount, tabSize, ToString(obj.Function, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPrivateInputData", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pPrivateInputData));
            FieldToString(strStrm, false, "PrivateInputDataSize", toStringFlags, tabCount, tabSize, ToString(obj.PrivateInputDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPrivateOutputData", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pPrivateOutputData));
            FieldToString(strStrm, false, "PrivateOutputDataSize", toStringFlags, tabCount, tabSize, ToString(obj.PrivateOutputDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ResourceCount", toStringFlags, tabCount, tabSize, ToString(obj.ResourceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppResourceList", toStringFlags, tabCount, tabSize, HandleIdToString(obj.ppResourceList));
        }
    );
}

std::string ToString(const D3D11_VIDEO_PROCESSOR_CAPS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceCaps", toStringFlags, tabCount, tabSize, ToString(obj.DeviceCaps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FeatureCaps", toStringFlags, tabCount, tabSize, ToString(obj.FeatureCaps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FilterCaps", toStringFlags, tabCount, tabSize, ToString(obj.FilterCaps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InputFormatCaps", toStringFlags, tabCount, tabSize, ToString(obj.InputFormatCaps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AutoStreamCaps", toStringFlags, tabCount, tabSize, ToString(obj.AutoStreamCaps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StereoCaps", toStringFlags, tabCount, tabSize, ToString(obj.StereoCaps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RateConversionCapsCount", toStringFlags, tabCount, tabSize, ToString(obj.RateConversionCapsCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxInputStreams", toStringFlags, tabCount, tabSize, ToString(obj.MaxInputStreams, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxStreamStates", toStringFlags, tabCount, tabSize, ToString(obj.MaxStreamStates, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PastFrames", toStringFlags, tabCount, tabSize, ToString(obj.PastFrames, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FutureFrames", toStringFlags, tabCount, tabSize, ToString(obj.FutureFrames, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ProcessorCaps", toStringFlags, tabCount, tabSize, ToString(obj.ProcessorCaps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ITelecineCaps", toStringFlags, tabCount, tabSize, ToString(obj.ITelecineCaps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CustomRateCount", toStringFlags, tabCount, tabSize, ToString(obj.CustomRateCount, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_CONTENT_PROTECTION_CAPS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Caps", toStringFlags, tabCount, tabSize, ToString(obj.Caps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "KeyExchangeTypeCount", toStringFlags, tabCount, tabSize, ToString(obj.KeyExchangeTypeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BlockAlignmentSize", toStringFlags, tabCount, tabSize, ToString(obj.BlockAlignmentSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ProtectedMemorySize", toStringFlags, tabCount, tabSize, ToString(obj.ProtectedMemorySize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_PROCESSOR_CUSTOM_RATE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CustomRate", toStringFlags, tabCount, tabSize, ToString(obj.CustomRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputFrames", toStringFlags, tabCount, tabSize, ToString(obj.OutputFrames, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InputInterlaced", toStringFlags, tabCount, tabSize, ToString(obj.InputInterlaced, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InputFramesOrFields", toStringFlags, tabCount, tabSize, ToString(obj.InputFramesOrFields, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_PROCESSOR_FILTER_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Minimum", toStringFlags, tabCount, tabSize, ToString(obj.Minimum, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Maximum", toStringFlags, tabCount, tabSize, ToString(obj.Maximum, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Default", toStringFlags, tabCount, tabSize, ToString(obj.Default, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Multiplier", toStringFlags, tabCount, tabSize, ToString(obj.Multiplier, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_PROCESSOR_CONTENT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "InputFrameFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.InputFrameFormat)));
            FieldToString(strStrm, false, "InputFrameRate", toStringFlags, tabCount, tabSize, ToString(obj.InputFrameRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InputWidth", toStringFlags, tabCount, tabSize, ToString(obj.InputWidth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InputHeight", toStringFlags, tabCount, tabSize, ToString(obj.InputHeight, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputFrameRate", toStringFlags, tabCount, tabSize, ToString(obj.OutputFrameRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputWidth", toStringFlags, tabCount, tabSize, ToString(obj.OutputWidth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputHeight", toStringFlags, tabCount, tabSize, ToString(obj.OutputHeight, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Usage", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Usage)));
        }
    );
}

std::string ToString(const D3D11_VIDEO_COLOR_RGBA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "R", toStringFlags, tabCount, tabSize, ToString(obj.R, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "G", toStringFlags, tabCount, tabSize, ToString(obj.G, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "B", toStringFlags, tabCount, tabSize, ToString(obj.B, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "A", toStringFlags, tabCount, tabSize, ToString(obj.A, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_COLOR_YCbCrA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Y", toStringFlags, tabCount, tabSize, ToString(obj.Y, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Cb", toStringFlags, tabCount, tabSize, ToString(obj.Cb, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Cr", toStringFlags, tabCount, tabSize, ToString(obj.Cr, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "A", toStringFlags, tabCount, tabSize, ToString(obj.A, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_PROCESSOR_COLOR_SPACE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Usage", toStringFlags, tabCount, tabSize, ToString(obj.Usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RGB_Range", toStringFlags, tabCount, tabSize, ToString(obj.RGB_Range, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "YCbCr_Matrix", toStringFlags, tabCount, tabSize, ToString(obj.YCbCr_Matrix, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "YCbCr_xvYCC", toStringFlags, tabCount, tabSize, ToString(obj.YCbCr_xvYCC, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Nominal_Range", toStringFlags, tabCount, tabSize, ToString(obj.Nominal_Range, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Reserved", toStringFlags, tabCount, tabSize, ToString(obj.Reserved, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_PROCESSOR_STREAM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Enable", toStringFlags, tabCount, tabSize, ToString(obj.Enable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputIndex", toStringFlags, tabCount, tabSize, ToString(obj.OutputIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InputFrameOrField", toStringFlags, tabCount, tabSize, ToString(obj.InputFrameOrField, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PastFrames", toStringFlags, tabCount, tabSize, ToString(obj.PastFrames, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FutureFrames", toStringFlags, tabCount, tabSize, ToString(obj.FutureFrames, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppPastSurfaces", toStringFlags, tabCount, tabSize, HandleIdToString(obj.ppPastSurfaces));
            FieldToString(strStrm, false, "pInputSurface", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pInputSurface));
            FieldToString(strStrm, false, "ppFutureSurfaces", toStringFlags, tabCount, tabSize, HandleIdToString(obj.ppFutureSurfaces));
            FieldToString(strStrm, false, "ppPastSurfacesRight", toStringFlags, tabCount, tabSize, HandleIdToString(obj.ppPastSurfacesRight));
            FieldToString(strStrm, false, "pInputSurfaceRight", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pInputSurfaceRight));
            FieldToString(strStrm, false, "ppFutureSurfacesRight", toStringFlags, tabCount, tabSize, HandleIdToString(obj.ppFutureSurfacesRight));
        }
    );
}

std::string ToString(const D3D11_OMAC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Omac", toStringFlags, tabCount, tabSize, ArrayToString(16, obj.Omac, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "QueryType", toStringFlags, tabCount, tabSize, ToString(obj.QueryType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hChannel", toStringFlags, tabCount, tabSize, HandleIdToString(obj.hChannel));
            FieldToString(strStrm, false, "SequenceNumber", toStringFlags, tabCount, tabSize, ToString(obj.SequenceNumber, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "omac", toStringFlags, tabCount, tabSize, ToString(obj.omac, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "QueryType", toStringFlags, tabCount, tabSize, ToString(obj.QueryType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hChannel", toStringFlags, tabCount, tabSize, HandleIdToString(obj.hChannel));
            FieldToString(strStrm, false, "SequenceNumber", toStringFlags, tabCount, tabSize, ToString(obj.SequenceNumber, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ReturnCode", toStringFlags, tabCount, tabSize, ToString(obj.ReturnCode, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_PROTECTION_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ProtectionFlags", toStringFlags, tabCount, tabSize, ToString(obj.ProtectionFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_CHANNEL_TYPE_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ChannelType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ChannelType)));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.DeviceHandle));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Input", toStringFlags, tabCount, tabSize, ToString(obj.Input, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DecoderHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.DecoderHandle));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DecoderHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.DecoderHandle));
            FieldToString(strStrm, false, "CryptoSessionHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.CryptoSessionHandle));
            FieldToString(strStrm, false, "DeviceHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.DeviceHandle));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "RestrictedSharedResourceProcessCount", toStringFlags, tabCount, tabSize, ToString(obj.RestrictedSharedResourceProcessCount, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Input", toStringFlags, tabCount, tabSize, ToString(obj.Input, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ProcessIndex", toStringFlags, tabCount, tabSize, ToString(obj.ProcessIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ProcessIndex", toStringFlags, tabCount, tabSize, ToString(obj.ProcessIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ProcessIdentifier", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ProcessIdentifier)));
            FieldToString(strStrm, false, "ProcessHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.ProcessHandle));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "UnrestrictedProtectedSharedResourceCount", toStringFlags, tabCount, tabSize, ToString(obj.UnrestrictedProtectedSharedResourceCount, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Input", toStringFlags, tabCount, tabSize, ToString(obj.Input, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.DeviceHandle));
            FieldToString(strStrm, false, "CryptoSessionHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.CryptoSessionHandle));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.DeviceHandle));
            FieldToString(strStrm, false, "CryptoSessionHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.CryptoSessionHandle));
            FieldToString(strStrm, false, "OutputIDCount", toStringFlags, tabCount, tabSize, ToString(obj.OutputIDCount, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Input", toStringFlags, tabCount, tabSize, ToString(obj.Input, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.DeviceHandle));
            FieldToString(strStrm, false, "CryptoSessionHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.CryptoSessionHandle));
            FieldToString(strStrm, false, "OutputIDIndex", toStringFlags, tabCount, tabSize, ToString(obj.OutputIDIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DeviceHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.DeviceHandle));
            FieldToString(strStrm, false, "CryptoSessionHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.CryptoSessionHandle));
            FieldToString(strStrm, false, "OutputIDIndex", toStringFlags, tabCount, tabSize, ToString(obj.OutputIDIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "OutputID", toStringFlags, tabCount, tabSize, ToString(obj.OutputID, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "BusType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BusType)));
            FieldToString(strStrm, false, "AccessibleInContiguousBlocks", toStringFlags, tabCount, tabSize, ToString(obj.AccessibleInContiguousBlocks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AccessibleInNonContiguousBlocks", toStringFlags, tabCount, tabSize, ToString(obj.AccessibleInNonContiguousBlocks, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_COUNT_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "EncryptionGuidCount", toStringFlags, tabCount, tabSize, ToString(obj.EncryptionGuidCount, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Input", toStringFlags, tabCount, tabSize, ToString(obj.Input, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "EncryptionGuidIndex", toStringFlags, tabCount, tabSize, ToString(obj.EncryptionGuidIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "EncryptionGuidIndex", toStringFlags, tabCount, tabSize, ToString(obj.EncryptionGuidIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "EncryptionGuid", toStringFlags, tabCount, tabSize, ToString(obj.EncryptionGuid, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_QUERY_CURRENT_ACCESSIBILITY_ENCRYPTION_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Output", toStringFlags, tabCount, tabSize, ToString(obj.Output, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "EncryptionGuid", toStringFlags, tabCount, tabSize, ToString(obj.EncryptionGuid, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "omac", toStringFlags, tabCount, tabSize, ToString(obj.omac, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigureType", toStringFlags, tabCount, tabSize, ToString(obj.ConfigureType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hChannel", toStringFlags, tabCount, tabSize, HandleIdToString(obj.hChannel));
            FieldToString(strStrm, false, "SequenceNumber", toStringFlags, tabCount, tabSize, ToString(obj.SequenceNumber, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "omac", toStringFlags, tabCount, tabSize, ToString(obj.omac, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConfigureType", toStringFlags, tabCount, tabSize, ToString(obj.ConfigureType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hChannel", toStringFlags, tabCount, tabSize, HandleIdToString(obj.hChannel));
            FieldToString(strStrm, false, "SequenceNumber", toStringFlags, tabCount, tabSize, ToString(obj.SequenceNumber, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ReturnCode", toStringFlags, tabCount, tabSize, ToString(obj.ReturnCode, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_INITIALIZE_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Parameters", toStringFlags, tabCount, tabSize, ToString(obj.Parameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StartSequenceQuery", toStringFlags, tabCount, tabSize, ToString(obj.StartSequenceQuery, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StartSequenceConfigure", toStringFlags, tabCount, tabSize, ToString(obj.StartSequenceConfigure, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_PROTECTION_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Parameters", toStringFlags, tabCount, tabSize, ToString(obj.Parameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Protections", toStringFlags, tabCount, tabSize, ToString(obj.Protections, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Parameters", toStringFlags, tabCount, tabSize, ToString(obj.Parameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DecoderHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.DecoderHandle));
            FieldToString(strStrm, false, "CryptoSessionHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.CryptoSessionHandle));
            FieldToString(strStrm, false, "DeviceHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.DeviceHandle));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Parameters", toStringFlags, tabCount, tabSize, ToString(obj.Parameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ProcessType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ProcessType)));
            FieldToString(strStrm, false, "ProcessHandle", toStringFlags, tabCount, tabSize, HandleIdToString(obj.ProcessHandle));
            FieldToString(strStrm, false, "AllowAccess", toStringFlags, tabCount, tabSize, ToString(obj.AllowAccess, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION_INPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Parameters", toStringFlags, tabCount, tabSize, ToString(obj.Parameters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "EncryptionGuid", toStringFlags, tabCount, tabSize, ToString(obj.EncryptionGuid, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_VDOV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.ArraySlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_VPIV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.ArraySlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_VPOV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_ARRAY_VPOV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_RENDER_TARGET_BLEND_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BlendEnable", toStringFlags, tabCount, tabSize, ToString(obj.BlendEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "LogicOpEnable", toStringFlags, tabCount, tabSize, ToString(obj.LogicOpEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SrcBlend", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SrcBlend)));
            FieldToString(strStrm, false, "DestBlend", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DestBlend)));
            FieldToString(strStrm, false, "BlendOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BlendOp)));
            FieldToString(strStrm, false, "SrcBlendAlpha", toStringFlags, tabCount, tabSize, Quote(ToString(obj.SrcBlendAlpha)));
            FieldToString(strStrm, false, "DestBlendAlpha", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DestBlendAlpha)));
            FieldToString(strStrm, false, "BlendOpAlpha", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BlendOpAlpha)));
            FieldToString(strStrm, false, "LogicOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.LogicOp)));
            FieldToString(strStrm, false, "RenderTargetWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.RenderTargetWriteMask, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_BLEND_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_RASTERIZER_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FillMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.FillMode)));
            FieldToString(strStrm, false, "CullMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.CullMode)));
            FieldToString(strStrm, false, "FrontCounterClockwise", toStringFlags, tabCount, tabSize, ToString(obj.FrontCounterClockwise, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBias", toStringFlags, tabCount, tabSize, ToString(obj.DepthBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBiasClamp", toStringFlags, tabCount, tabSize, ToString(obj.DepthBiasClamp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SlopeScaledDepthBias", toStringFlags, tabCount, tabSize, ToString(obj.SlopeScaledDepthBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthClipEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthClipEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ScissorEnable", toStringFlags, tabCount, tabSize, ToString(obj.ScissorEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MultisampleEnable", toStringFlags, tabCount, tabSize, ToString(obj.MultisampleEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AntialiasedLineEnable", toStringFlags, tabCount, tabSize, ToString(obj.AntialiasedLineEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ForcedSampleCount", toStringFlags, tabCount, tabSize, ToString(obj.ForcedSampleCount, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ClearSize", toStringFlags, tabCount, tabSize, ToString(obj.ClearSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "EncryptedSize", toStringFlags, tabCount, tabSize, ToString(obj.EncryptedSize, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_DECODER_BUFFER_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BufferType)));
            FieldToString(strStrm, false, "DataOffset", toStringFlags, tabCount, tabSize, ToString(obj.DataOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, ToString(obj.DataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIV", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pIV));
            FieldToString(strStrm, false, "IVSize", toStringFlags, tabCount, tabSize, ToString(obj.IVSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubSampleMappingBlock", toStringFlags, tabCount, tabSize, ArrayToString(obj.SubSampleMappingCount, obj.pSubSampleMappingBlock, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SubSampleMappingCount", toStringFlags, tabCount, tabSize, ToString(obj.SubSampleMappingCount, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pCryptoSession", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pCryptoSession));
            FieldToString(strStrm, false, "BlobSize", toStringFlags, tabCount, tabSize, ToString(obj.BlobSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBlob", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pBlob));
            FieldToString(strStrm, false, "pKeyInfoId", toStringFlags, tabCount, tabSize, (obj.pKeyInfoId ? ToString(*obj.pKeyInfoId, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "PrivateDataSize", toStringFlags, tabCount, tabSize, ToString(obj.PrivateDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPrivateData", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pPrivateData));
        }
    );
}

std::string ToString(const D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Enable", toStringFlags, tabCount, tabSize, ToString(obj.Enable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
        }
    );
}

std::string ToString(const D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PrivateDataSize", toStringFlags, tabCount, tabSize, ToString(obj.PrivateDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HWProtectionDataSize", toStringFlags, tabCount, tabSize, ToString(obj.HWProtectionDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pbInput", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.pbInput, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PrivateDataSize", toStringFlags, tabCount, tabSize, ToString(obj.PrivateDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MaxHWProtectionDataSize", toStringFlags, tabCount, tabSize, ToString(obj.MaxHWProtectionDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "HWProtectionDataSize", toStringFlags, tabCount, tabSize, ToString(obj.HWProtectionDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TransportTime", toStringFlags, tabCount, tabSize, ToString(obj.TransportTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ExecutionTime", toStringFlags, tabCount, tabSize, ToString(obj.ExecutionTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pbOutput", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.pbOutput, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "HWProtectionFunctionID", toStringFlags, tabCount, tabSize, ToString(obj.HWProtectionFunctionID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInputData", toStringFlags, tabCount, tabSize, (obj.pInputData ? ToString(*obj.pInputData, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pOutputData", toStringFlags, tabCount, tabSize, (obj.pOutputData ? ToString(*obj.pOutputData, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "Status", toStringFlags, tabCount, tabSize, ToString(obj.Status, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_SAMPLE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "ColorSpace", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ColorSpace)));
        }
    );
}

std::string ToString(const D3D11_TILED_RESOURCE_COORDINATE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TILE_REGION_SIZE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumTiles", toStringFlags, tabCount, tabSize, ToString(obj.NumTiles, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bUseBox", toStringFlags, tabCount, tabSize, ToString(obj.bUseBox, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, ToString(obj.Depth, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_SUBRESOURCE_TILING& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TILE_SHAPE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_PACKED_MIP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TEXTURE2D_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, ToString(obj.SampleDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Usage", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Usage)));
            FieldToString(strStrm, false, "BindFlags", toStringFlags, tabCount, tabSize, ToString(obj.BindFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CPUAccessFlags", toStringFlags, tabCount, tabSize, ToString(obj.CPUAccessFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MiscFlags", toStringFlags, tabCount, tabSize, ToString(obj.MiscFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TextureLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.TextureLayout)));
        }
    );
}

std::string ToString(const D3D11_TEXTURE3D_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, ToString(obj.Width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, ToString(obj.Height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, ToString(obj.Depth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "Usage", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Usage)));
            FieldToString(strStrm, false, "BindFlags", toStringFlags, tabCount, tabSize, ToString(obj.BindFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CPUAccessFlags", toStringFlags, tabCount, tabSize, ToString(obj.CPUAccessFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MiscFlags", toStringFlags, tabCount, tabSize, ToString(obj.MiscFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "TextureLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.TextureLayout)));
        }
    );
}

std::string ToString(const D3D11_RASTERIZER_DESC2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FillMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.FillMode)));
            FieldToString(strStrm, false, "CullMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.CullMode)));
            FieldToString(strStrm, false, "FrontCounterClockwise", toStringFlags, tabCount, tabSize, ToString(obj.FrontCounterClockwise, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBias", toStringFlags, tabCount, tabSize, ToString(obj.DepthBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthBiasClamp", toStringFlags, tabCount, tabSize, ToString(obj.DepthBiasClamp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SlopeScaledDepthBias", toStringFlags, tabCount, tabSize, ToString(obj.SlopeScaledDepthBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DepthClipEnable", toStringFlags, tabCount, tabSize, ToString(obj.DepthClipEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ScissorEnable", toStringFlags, tabCount, tabSize, ToString(obj.ScissorEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MultisampleEnable", toStringFlags, tabCount, tabSize, ToString(obj.MultisampleEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AntialiasedLineEnable", toStringFlags, tabCount, tabSize, ToString(obj.AntialiasedLineEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ForcedSampleCount", toStringFlags, tabCount, tabSize, ToString(obj.ForcedSampleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ConservativeRaster", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ConservativeRaster)));
        }
    );
}

std::string ToString(const D3D11_TEX2D_SRV1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_ARRAY_SRV1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, ToString(obj.MostDetailedMip, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, ToString(obj.MipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, ToString(obj.FirstArraySlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, ToString(obj.ArraySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_RTV1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_ARRAY_RTV1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_TEX2D_UAV1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, ToString(obj.MipSlice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, ToString(obj.PlaneSlice, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_TEX2D_ARRAY_UAV1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const D3D11_QUERY_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Query", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Query)));
            FieldToString(strStrm, false, "MiscFlags", toStringFlags, tabCount, tabSize, ToString(obj.MiscFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ContextType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ContextType)));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DecoderDesc", toStringFlags, tabCount, tabSize, ToString(obj.DecoderDesc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Components", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Components)));
            FieldToString(strStrm, false, "BinCount", toStringFlags, tabCount, tabSize, ToString(obj.BinCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CounterBitDepth", toStringFlags, tabCount, tabSize, ToString(obj.CounterBitDepth, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_VIDEO_DECODER_BUFFER_DESC2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BufferType)));
            FieldToString(strStrm, false, "DataOffset", toStringFlags, tabCount, tabSize, ToString(obj.DataOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, ToString(obj.DataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIV", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pIV));
            FieldToString(strStrm, false, "IVSize", toStringFlags, tabCount, tabSize, ToString(obj.IVSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubSampleMappingBlock", toStringFlags, tabCount, tabSize, ArrayToString(obj.SubSampleMappingCount, obj.pSubSampleMappingBlock, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "SubSampleMappingCount", toStringFlags, tabCount, tabSize, ToString(obj.SubSampleMappingCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "cBlocksStripeEncrypted", toStringFlags, tabCount, tabSize, ToString(obj.cBlocksStripeEncrypted, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "cBlocksStripeClear", toStringFlags, tabCount, tabSize, ToString(obj.cBlocksStripeClear, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS4& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ExtendedNV12SharedTextureSupported", toStringFlags, tabCount, tabSize, ToString(obj.ExtendedNV12SharedTextureSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const D3D11_RESOURCE_FLAGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BindFlags", toStringFlags, tabCount, tabSize, ToString(obj.BindFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MiscFlags", toStringFlags, tabCount, tabSize, ToString(obj.MiscFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "CPUAccessFlags", toStringFlags, tabCount, tabSize, ToString(obj.CPUAccessFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "StructureByteStride", toStringFlags, tabCount, tabSize, ToString(obj.StructureByteStride, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const tagRECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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

std::string ToString(const tagPOINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "x", toStringFlags, tabCount, tabSize, ToString(obj.x, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "y", toStringFlags, tabCount, tabSize, ToString(obj.y, toStringFlags, tabCount, tabSize));
        }
    );
}

std::string ToString(const tagSIZE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "cx", toStringFlags, tabCount, tabSize, ToString(obj.cx, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "cy", toStringFlags, tabCount, tabSize, ToString(obj.cy, toStringFlags, tabCount, tabSize));
        }
    );
}


GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
