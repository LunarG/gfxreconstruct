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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <> std::string ToString<DXGI_FRAME_STATISTICS>(const DXGI_FRAME_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PresentCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PresentRefreshCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SyncRefreshCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SyncQPCTime", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SyncGPUTime", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_MAPPED_RECT>(const DXGI_MAPPED_RECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Pitch", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pBits", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<LUID>(const LUID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "LowPart", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "HighPart", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_ADAPTER_DESC>(const DXGI_ADAPTER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VendorId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DeviceId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SubSysId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Revision", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DedicatedVideoMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DedicatedSystemMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SharedSystemMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_OUTPUT_DESC>(const DXGI_OUTPUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceName", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DesktopCoordinates", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AttachedToDesktop", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Rotation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Monitor", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_SHARED_RESOURCE>(const DXGI_SHARED_RESOURCE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Handle", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_SURFACE_DESC>(const DXGI_SURFACE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_SWAP_CHAIN_DESC>(const DXGI_SWAP_CHAIN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferDesc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BufferUsage", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BufferCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "OutputWindow", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Windowed", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SwapEffect", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_ADAPTER_DESC1>(const DXGI_ADAPTER_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VendorId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DeviceId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SubSysId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Revision", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DedicatedVideoMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DedicatedSystemMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SharedSystemMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_DISPLAY_COLOR_SPACE>(const DXGI_DISPLAY_COLOR_SPACE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PrimaryCoordinates", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "WhitePoints", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_OUTDUPL_MOVE_RECT>(const DXGI_OUTDUPL_MOVE_RECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SourcePoint", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DestinationRect", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_OUTDUPL_DESC>(const DXGI_OUTDUPL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ModeDesc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Rotation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DesktopImageInSystemMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_OUTDUPL_POINTER_POSITION>(const DXGI_OUTDUPL_POINTER_POSITION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Position", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Visible", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_OUTDUPL_POINTER_SHAPE_INFO>(const DXGI_OUTDUPL_POINTER_SHAPE_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Pitch", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "HotSpot", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_OUTDUPL_FRAME_INFO>(const DXGI_OUTDUPL_FRAME_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "LastPresentTime", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "LastMouseUpdateTime", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AccumulatedFrames", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RectsCoalesced", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ProtectedContentMaskedOut", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PointerPosition", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "TotalMetadataBufferSize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PointerShapeBufferSize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_MODE_DESC1>(const DXGI_MODE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RefreshRate", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ScanlineOrdering", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Stereo", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_SWAP_CHAIN_DESC1>(const DXGI_SWAP_CHAIN_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Stereo", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BufferUsage", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BufferCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SwapEffect", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AlphaMode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_SWAP_CHAIN_FULLSCREEN_DESC>(const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RefreshRate", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ScanlineOrdering", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Windowed", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_PRESENT_PARAMETERS>(const DXGI_PRESENT_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DirtyRectsCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pDirtyRects", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pScrollRect", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pScrollOffset", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_ADAPTER_DESC2>(const DXGI_ADAPTER_DESC2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VendorId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DeviceId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SubSysId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Revision", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DedicatedVideoMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DedicatedSystemMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SharedSystemMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "GraphicsPreemptionGranularity", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ComputePreemptionGranularity", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_MATRIX_3X2_F>(const DXGI_MATRIX_3X2_F& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "_11", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "_12", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "_21", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "_22", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "_31", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "_32", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_DECODE_SWAP_CHAIN_DESC>(const DXGI_DECODE_SWAP_CHAIN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_FRAME_STATISTICS_MEDIA>(const DXGI_FRAME_STATISTICS_MEDIA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PresentCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PresentRefreshCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SyncRefreshCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SyncQPCTime", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SyncGPUTime", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CompositionMode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ApprovedPresentDuration", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_QUERY_VIDEO_MEMORY_INFO>(const DXGI_QUERY_VIDEO_MEMORY_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Budget", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CurrentUsage", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AvailableForReservation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CurrentReservation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_HDR_METADATA_HDR10>(const DXGI_HDR_METADATA_HDR10& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RedPrimary", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "GreenPrimary", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BluePrimary", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "WhitePoint", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxMasteringLuminance", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MinMasteringLuminance", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxContentLightLevel", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxFrameAverageLightLevel", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_HDR_METADATA_HDR10PLUS>(const DXGI_HDR_METADATA_HDR10PLUS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Data", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_ADAPTER_DESC3>(const DXGI_ADAPTER_DESC3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Description", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VendorId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DeviceId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SubSysId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Revision", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DedicatedVideoMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DedicatedSystemMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SharedSystemMemory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "GraphicsPreemptionGranularity", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ComputePreemptionGranularity", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_OUTPUT_DESC1>(const DXGI_OUTPUT_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceName", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DesktopCoordinates", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AttachedToDesktop", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Rotation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Monitor", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BitsPerColor", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ColorSpace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RedPrimary", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "GreenPrimary", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BluePrimary", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "WhitePoint", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MinLuminance", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxLuminance", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxFullFrameLuminance", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_RATIONAL>(const DXGI_RATIONAL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Numerator", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Denominator", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_SAMPLE_DESC>(const DXGI_SAMPLE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Count", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Quality", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_RGB>(const DXGI_RGB& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Red", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Green", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Blue", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3DCOLORVALUE>(const D3DCOLORVALUE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "r", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "g", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "b", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "a", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_GAMMA_CONTROL>(const DXGI_GAMMA_CONTROL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Scale", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Offset", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "GammaCurve", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_GAMMA_CONTROL_CAPABILITIES>(const DXGI_GAMMA_CONTROL_CAPABILITIES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ScaleAndOffsetSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxConvertedValue", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MinConvertedValue", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumGammaControlPoints", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ControlPointPositions", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_MODE_DESC>(const DXGI_MODE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RefreshRate", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ScanlineOrdering", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Scaling", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_JPEG_DC_HUFFMAN_TABLE>(const DXGI_JPEG_DC_HUFFMAN_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CodeCounts", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CodeValues", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_JPEG_AC_HUFFMAN_TABLE>(const DXGI_JPEG_AC_HUFFMAN_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CodeCounts", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CodeValues", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<DXGI_JPEG_QUANTIZATION_TABLE>(const DXGI_JPEG_QUANTIZATION_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Elements", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_COMMAND_QUEUE_DESC>(const D3D12_COMMAND_QUEUE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Priority", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_INPUT_ELEMENT_DESC>(const D3D12_INPUT_ELEMENT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SemanticName", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SemanticIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InputSlot", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AlignedByteOffset", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InputSlotClass", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InstanceDataStepRate", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SO_DECLARATION_ENTRY>(const D3D12_SO_DECLARATION_ENTRY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Stream", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SemanticName", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SemanticIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StartComponent", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ComponentCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "OutputSlot", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_VIEWPORT>(const D3D12_VIEWPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "TopLeftX", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "TopLeftY", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MinDepth", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxDepth", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_BOX>(const D3D12_BOX& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "left", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "top", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "front", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "right", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "bottom", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "back", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DEPTH_STENCILOP_DESC>(const D3D12_DEPTH_STENCILOP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StencilFailOp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilDepthFailOp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilPassOp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilFunc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DEPTH_STENCIL_DESC>(const D3D12_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthWriteMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthFunc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilReadMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilWriteMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FrontFace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BackFace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DEPTH_STENCIL_DESC1>(const D3D12_DEPTH_STENCIL_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthWriteMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthFunc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilReadMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilWriteMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FrontFace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BackFace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthBoundsTestEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_TARGET_BLEND_DESC>(const D3D12_RENDER_TARGET_BLEND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BlendEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "LogicOpEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SrcBlend", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DestBlend", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BlendOp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SrcBlendAlpha", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DestBlendAlpha", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BlendOpAlpha", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "LogicOp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RenderTargetWriteMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_BLEND_DESC>(const D3D12_BLEND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AlphaToCoverageEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "IndependentBlendEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RenderTarget", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RASTERIZER_DESC>(const D3D12_RASTERIZER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FillMode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CullMode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FrontCounterClockwise", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthBias", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthBiasClamp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SlopeScaledDepthBias", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthClipEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MultisampleEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AntialiasedLineEnable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ForcedSampleCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ConservativeRaster", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SHADER_BYTECODE>(const D3D12_SHADER_BYTECODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pShaderBytecode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BytecodeLength", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_STREAM_OUTPUT_DESC>(const D3D12_STREAM_OUTPUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pSODeclaration", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumEntries", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pBufferStrides", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumStrides", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RasterizedStream", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_INPUT_LAYOUT_DESC>(const D3D12_INPUT_LAYOUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pInputElementDescs", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_CACHED_PIPELINE_STATE>(const D3D12_CACHED_PIPELINE_STATE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pCachedBlob", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CachedBlobSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_GRAPHICS_PIPELINE_STATE_DESC>(const D3D12_GRAPHICS_PIPELINE_STATE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pRootSignature", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VS", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PS", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DS", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "HS", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "GS", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StreamOutput", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BlendState", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SampleMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RasterizerState", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthStencilState", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InputLayout", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "IBStripCutValue", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PrimitiveTopologyType", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumRenderTargets", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RTVFormats", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DSVFormat", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CachedPSO", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_COMPUTE_PIPELINE_STATE_DESC>(const D3D12_COMPUTE_PIPELINE_STATE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pRootSignature", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CS", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CachedPSO", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RT_FORMAT_ARRAY>(const D3D12_RT_FORMAT_ARRAY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RTFormats", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumRenderTargets", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS>(const D3D12_FEATURE_DATA_D3D12_OPTIONS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DoublePrecisionFloatShaderOps", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "OutputMergerLogicOp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MinPrecisionSupport", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "TiledResourcesTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ResourceBindingTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PSSpecifiedStencilRefSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "TypedUAVLoadAdditionalFormats", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ROVsSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ConservativeRasterizationTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxGPUVirtualAddressBitsPerResource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StandardSwizzle64KBSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CrossNodeSharingTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CrossAdapterRowMajorTextureSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ResourceHeapTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS1>(const D3D12_FEATURE_DATA_D3D12_OPTIONS1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "WaveOps", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "WaveLaneCountMin", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "WaveLaneCountMax", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "TotalLaneCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ExpandedComputeResourceStates", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Int64ShaderOps", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS2>(const D3D12_FEATURE_DATA_D3D12_OPTIONS2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DepthBoundsTestSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ProgrammableSamplePositionsTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_ROOT_SIGNATURE>(const D3D12_FEATURE_DATA_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "HighestVersion", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_ARCHITECTURE>(const D3D12_FEATURE_DATA_ARCHITECTURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "TileBasedRenderer", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "UMA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CacheCoherentUMA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_ARCHITECTURE1>(const D3D12_FEATURE_DATA_ARCHITECTURE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "TileBasedRenderer", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "UMA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CacheCoherentUMA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "IsolatedMMU", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_FEATURE_LEVELS>(const D3D12_FEATURE_DATA_FEATURE_LEVELS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumFeatureLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pFeatureLevelsRequested", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxSupportedFeatureLevel", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_SHADER_MODEL>(const D3D12_FEATURE_DATA_SHADER_MODEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "HighestShaderModel", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_FORMAT_SUPPORT>(const D3D12_FEATURE_DATA_FORMAT_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Support1", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Support2", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS>(const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SampleCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumQualityLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_FORMAT_INFO>(const D3D12_FEATURE_DATA_FORMAT_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PlaneCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT>(const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxGPUVirtualAddressBitsPerResource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxGPUVirtualAddressBitsPerProcess", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_SHADER_CACHE>(const D3D12_FEATURE_DATA_SHADER_CACHE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SupportFlags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY>(const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CommandListType", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Priority", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PriorityForTypeIsSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS3>(const D3D12_FEATURE_DATA_D3D12_OPTIONS3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CopyQueueTimestampQueriesSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CastingFullyTypedFormatSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "WriteBufferImmediateSupportFlags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ViewInstancingTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BarycentricsSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_EXISTING_HEAPS>(const D3D12_FEATURE_DATA_EXISTING_HEAPS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Supported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS4>(const D3D12_FEATURE_DATA_D3D12_OPTIONS4& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MSAA64KBAlignedTextureSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SharedResourceCompatibilityTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Native16BitShaderOpsSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_SERIALIZATION>(const D3D12_FEATURE_DATA_SERIALIZATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "HeapSerializationTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_CROSS_NODE>(const D3D12_FEATURE_DATA_CROSS_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SharingTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AtomicShaderInstructions", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS5>(const D3D12_FEATURE_DATA_D3D12_OPTIONS5& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SRVOnlyTiledResourceTier3", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RenderPassesTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RaytracingTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS6>(const D3D12_FEATURE_DATA_D3D12_OPTIONS6& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AdditionalShadingRatesSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PerPrimitiveShadingRateSupportedWithViewportIndexing", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VariableShadingRateTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ShadingRateImageTileSize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BackgroundProcessingSupported", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS7>(const D3D12_FEATURE_DATA_D3D12_OPTIONS7& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MeshShaderTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SamplerFeedbackTier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_QUERY_META_COMMAND>(const D3D12_FEATURE_DATA_QUERY_META_COMMAND& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CommandId", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pQueryInputData", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "QueryInputDataSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pQueryOutputData", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "QueryOutputDataSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_ALLOCATION_INFO>(const D3D12_RESOURCE_ALLOCATION_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_ALLOCATION_INFO1>(const D3D12_RESOURCE_ALLOCATION_INFO1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Offset", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_HEAP_PROPERTIES>(const D3D12_HEAP_PROPERTIES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CPUPageProperty", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MemoryPoolPreference", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CreationNodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VisibleNodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_HEAP_DESC>(const D3D12_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Properties", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_MIP_REGION>(const D3D12_MIP_REGION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_DESC>(const D3D12_RESOURCE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Dimension", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthOrArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Layout", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_DESC1>(const D3D12_RESOURCE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Dimension", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Alignment", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthOrArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SampleDesc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Layout", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SamplerFeedbackMipRegion", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DEPTH_STENCIL_VALUE>(const D3D12_DEPTH_STENCIL_VALUE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Depth", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Stencil", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RANGE>(const D3D12_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Begin", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "End", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RANGE_UINT64>(const D3D12_RANGE_UINT64& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Begin", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "End", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SUBRESOURCE_RANGE_UINT64>(const D3D12_SUBRESOURCE_RANGE_UINT64& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Subresource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Range", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SUBRESOURCE_INFO>(const D3D12_SUBRESOURCE_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Offset", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RowPitch", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthPitch", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TILED_RESOURCE_COORDINATE>(const D3D12_TILED_RESOURCE_COORDINATE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "X", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Y", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Z", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TILE_REGION_SIZE>(const D3D12_TILE_REGION_SIZE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumTiles", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "UseBox", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SUBRESOURCE_TILING>(const D3D12_SUBRESOURCE_TILING& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "WidthInTiles", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "HeightInTiles", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthInTiles", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StartTileIndexInOverallResource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TILE_SHAPE>(const D3D12_TILE_SHAPE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "WidthInTexels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "HeightInTexels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthInTexels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_PACKED_MIP_INFO>(const D3D12_PACKED_MIP_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumStandardMips", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumPackedMips", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumTilesForPackedMips", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StartTileIndexInOverallResource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_TRANSITION_BARRIER>(const D3D12_RESOURCE_TRANSITION_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StateBefore", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StateAfter", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_ALIASING_BARRIER>(const D3D12_RESOURCE_ALIASING_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResourceBefore", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pResourceAfter", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RESOURCE_UAV_BARRIER>(const D3D12_RESOURCE_UAV_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SUBRESOURCE_FOOTPRINT>(const D3D12_SUBRESOURCE_FOOTPRINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RowPitch", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>(const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Offset", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Footprint", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SAMPLE_POSITION>(const D3D12_SAMPLE_POSITION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "X", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Y", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_VIEW_INSTANCE_LOCATION>(const D3D12_VIEW_INSTANCE_LOCATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ViewportArrayIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RenderTargetArrayIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_VIEW_INSTANCING_DESC>(const D3D12_VIEW_INSTANCING_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ViewInstanceCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pViewInstanceLocations", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_BUFFER_SRV>(const D3D12_BUFFER_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StructureByteStride", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_SRV>(const D3D12_TEX1D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_ARRAY_SRV>(const D3D12_TEX1D_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_SRV>(const D3D12_TEX2D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_ARRAY_SRV>(const D3D12_TEX2D_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX3D_SRV>(const D3D12_TEX3D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEXCUBE_SRV>(const D3D12_TEXCUBE_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEXCUBE_ARRAY_SRV>(const D3D12_TEXCUBE_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MostDetailedMip", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLevels", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "First2DArrayFace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumCubes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ResourceMinLODClamp", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_SRV>(const D3D12_TEX2DMS_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_ARRAY_SRV>(const D3D12_TEX2DMS_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Location", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_CONSTANT_BUFFER_VIEW_DESC>(const D3D12_CONSTANT_BUFFER_VIEW_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferLocation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SAMPLER_DESC>(const D3D12_SAMPLER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Filter", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AddressU", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AddressV", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AddressW", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLODBias", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxAnisotropy", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ComparisonFunc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BorderColor", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MinLOD", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxLOD", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_BUFFER_UAV>(const D3D12_BUFFER_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StructureByteStride", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CounterOffsetInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_UAV>(const D3D12_TEX1D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_ARRAY_UAV>(const D3D12_TEX1D_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_UAV>(const D3D12_TEX2D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_ARRAY_UAV>(const D3D12_TEX2D_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX3D_UAV>(const D3D12_TEX3D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstWSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "WSize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_BUFFER_RTV>(const D3D12_BUFFER_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_RTV>(const D3D12_TEX1D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_ARRAY_RTV>(const D3D12_TEX1D_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_RTV>(const D3D12_TEX2D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_RTV>(const D3D12_TEX2DMS_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_ARRAY_RTV>(const D3D12_TEX2D_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PlaneSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_ARRAY_RTV>(const D3D12_TEX2DMS_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX3D_RTV>(const D3D12_TEX3D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstWSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "WSize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_DSV>(const D3D12_TEX1D_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX1D_ARRAY_DSV>(const D3D12_TEX1D_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_DSV>(const D3D12_TEX2D_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2D_ARRAY_DSV>(const D3D12_TEX2D_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MipSlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_DSV>(const D3D12_TEX2DMS_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "UnusedField_NothingToDefine", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_TEX2DMS_ARRAY_DSV>(const D3D12_TEX2DMS_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstArraySlice", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ArraySize", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DESCRIPTOR_HEAP_DESC>(const D3D12_DESCRIPTOR_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumDescriptors", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DESCRIPTOR_RANGE>(const D3D12_DESCRIPTOR_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RangeType", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumDescriptors", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BaseShaderRegister", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "OffsetInDescriptorsFromTableStart", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_DESCRIPTOR_TABLE>(const D3D12_ROOT_DESCRIPTOR_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumDescriptorRanges", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pDescriptorRanges", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_CONSTANTS>(const D3D12_ROOT_CONSTANTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderRegister", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Num32BitValues", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_DESCRIPTOR>(const D3D12_ROOT_DESCRIPTOR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderRegister", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_STATIC_SAMPLER_DESC>(const D3D12_STATIC_SAMPLER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Filter", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AddressU", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AddressV", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AddressW", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MipLODBias", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxAnisotropy", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ComparisonFunc", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BorderColor", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MinLOD", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxLOD", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ShaderRegister", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ShaderVisibility", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_SIGNATURE_DESC>(const D3D12_ROOT_SIGNATURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumParameters", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pParameters", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumStaticSamplers", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pStaticSamplers", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DESCRIPTOR_RANGE1>(const D3D12_DESCRIPTOR_RANGE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RangeType", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumDescriptors", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BaseShaderRegister", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "OffsetInDescriptorsFromTableStart", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_DESCRIPTOR_TABLE1>(const D3D12_ROOT_DESCRIPTOR_TABLE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumDescriptorRanges", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pDescriptorRanges", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_DESCRIPTOR1>(const D3D12_ROOT_DESCRIPTOR1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderRegister", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RegisterSpace", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_ROOT_SIGNATURE_DESC1>(const D3D12_ROOT_SIGNATURE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumParameters", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pParameters", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumStaticSamplers", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pStaticSamplers", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DISCARD_REGION>(const D3D12_DISCARD_REGION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumRects", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pRects", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "FirstSubresource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumSubresources", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_QUERY_HEAP_DESC>(const D3D12_QUERY_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Count", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_QUERY_DATA_PIPELINE_STATISTICS>(const D3D12_QUERY_DATA_PIPELINE_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "IAVertices", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "IAPrimitives", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VSInvocations", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "GSInvocations", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "GSPrimitives", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CInvocations", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CPrimitives", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PSInvocations", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "HSInvocations", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DSInvocations", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CSInvocations", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_QUERY_DATA_SO_STATISTICS>(const D3D12_QUERY_DATA_SO_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumPrimitivesWritten", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PrimitivesStorageNeeded", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_STREAM_OUTPUT_BUFFER_VIEW>(const D3D12_STREAM_OUTPUT_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferLocation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BufferFilledSizeLocation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DRAW_ARGUMENTS>(const D3D12_DRAW_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "VertexCountPerInstance", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InstanceCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StartVertexLocation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StartInstanceLocation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DRAW_INDEXED_ARGUMENTS>(const D3D12_DRAW_INDEXED_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "IndexCountPerInstance", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InstanceCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StartIndexLocation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BaseVertexLocation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StartInstanceLocation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DISPATCH_ARGUMENTS>(const D3D12_DISPATCH_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ThreadGroupCountX", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ThreadGroupCountY", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ThreadGroupCountZ", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_VERTEX_BUFFER_VIEW>(const D3D12_VERTEX_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferLocation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StrideInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_INDEX_BUFFER_VIEW>(const D3D12_INDEX_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BufferLocation", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_COMMAND_SIGNATURE_DESC>(const D3D12_COMMAND_SIGNATURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ByteStride", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumArgumentDescs", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pArgumentDescs", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>(const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Dest", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Value", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT>(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Support", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_PROTECTED_RESOURCE_SESSION_DESC>(const D3D12_PROTECTED_RESOURCE_SESSION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_META_COMMAND_PARAMETER_DESC>(const D3D12_META_COMMAND_PARAMETER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Name", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RequiredResourceState", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StructureOffset", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_META_COMMAND_DESC>(const D3D12_META_COMMAND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Id", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Name", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InitializationDirtyState", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ExecutionDirtyState", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_STATE_OBJECT_CONFIG>(const D3D12_STATE_OBJECT_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_GLOBAL_ROOT_SIGNATURE>(const D3D12_GLOBAL_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pGlobalRootSignature", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_LOCAL_ROOT_SIGNATURE>(const D3D12_LOCAL_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pLocalRootSignature", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_NODE_MASK>(const D3D12_NODE_MASK& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_EXPORT_DESC>(const D3D12_EXPORT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Name", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ExportToRename", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DXIL_LIBRARY_DESC>(const D3D12_DXIL_LIBRARY_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DXILLibrary", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumExports", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pExports", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_EXISTING_COLLECTION_DESC>(const D3D12_EXISTING_COLLECTION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pExistingCollection", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumExports", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pExports", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION>(const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SubobjectToAssociate", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumExports", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pExports", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_HIT_GROUP_DESC>(const D3D12_HIT_GROUP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "HitGroupExport", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AnyHitShaderImport", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ClosestHitShaderImport", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "IntersectionShaderImport", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_SHADER_CONFIG>(const D3D12_RAYTRACING_SHADER_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxPayloadSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxAttributeSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_PIPELINE_CONFIG>(const D3D12_RAYTRACING_PIPELINE_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxTraceRecursionDepth", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_PIPELINE_CONFIG1>(const D3D12_RAYTRACING_PIPELINE_CONFIG1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxTraceRecursionDepth", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE>(const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StartAddress", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StrideInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_GPU_VIRTUAL_ADDRESS_RANGE>(const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StartAddress", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE>(const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "StartAddress", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StrideInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC>(const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Transform3x4", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "IndexFormat", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VertexFormat", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "IndexCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VertexCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "IndexBuffer", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "VertexBuffer", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_AABB>(const D3D12_RAYTRACING_AABB& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MinX", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MinY", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MinZ", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxX", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxY", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MaxZ", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_GEOMETRY_AABBS_DESC>(const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AABBCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AABBs", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DestBuffer", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InfoType", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CompactedSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DecodedSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER>(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumDescs", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SerializedSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumBottomLevelAccelerationStructurePointers", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>(const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DriverOpaqueGUID", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DriverOpaqueVersioningData", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER>(const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DriverMatchingIdentifier", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SerializedSizeInBytesIncludingHeader", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DeserializedSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumBottomLevelAccelerationStructurePointersAfterHeader", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "CurrentSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_INSTANCE_DESC>(const D3D12_RAYTRACING_INSTANCE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Transform", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InstanceID", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InstanceMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "InstanceContributionToHitGroupIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AccelerationStructure", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DestAccelerationStructureData", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Inputs", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SourceAccelerationStructureData", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ScratchAccelerationStructureData", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ResultDataMaxSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ScratchDataSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "UpdateScratchDataSizeInBytes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_AUTO_BREADCRUMB_NODE>(const D3D12_AUTO_BREADCRUMB_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pCommandListDebugNameA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandListDebugNameW", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandQueueDebugNameA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandQueueDebugNameW", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandList", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandQueue", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BreadcrumbCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pLastBreadcrumbValue", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandHistory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_BREADCRUMB_CONTEXT>(const D3D12_DRED_BREADCRUMB_CONTEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "BreadcrumbIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pContextString", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_AUTO_BREADCRUMB_NODE1>(const D3D12_AUTO_BREADCRUMB_NODE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pCommandListDebugNameA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandListDebugNameW", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandQueueDebugNameA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandQueueDebugNameW", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandList", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandQueue", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BreadcrumbCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pLastBreadcrumbValue", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCommandHistory", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BreadcrumbContextsCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pBreadcrumbContexts", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DEVICE_REMOVED_EXTENDED_DATA>(const D3D12_DEVICE_REMOVED_EXTENDED_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pHeadAutoBreadcrumbNode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_ALLOCATION_NODE>(const D3D12_DRED_ALLOCATION_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ObjectNameA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ObjectNameW", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AllocationType", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_ALLOCATION_NODE1>(const D3D12_DRED_ALLOCATION_NODE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ObjectNameA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ObjectNameW", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AllocationType", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pObject", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pHeadAutoBreadcrumbNode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pHeadAutoBreadcrumbNode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_PAGE_FAULT_OUTPUT>(const D3D12_DRED_PAGE_FAULT_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PageFaultVA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pHeadExistingAllocationNode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pHeadRecentFreedAllocationNode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DRED_PAGE_FAULT_OUTPUT1>(const D3D12_DRED_PAGE_FAULT_OUTPUT1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "PageFaultVA", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pHeadExistingAllocationNode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pHeadRecentFreedAllocationNode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DEVICE_REMOVED_EXTENDED_DATA1>(const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceRemovedReason", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AutoBreadcrumbsOutput", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PageFaultOutput", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DEVICE_REMOVED_EXTENDED_DATA2>(const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "DeviceRemovedReason", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "AutoBreadcrumbsOutput", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PageFaultOutput", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT>(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Count", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES>(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeIndex", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Count", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pTypes", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_PROTECTED_RESOURCE_SESSION_DESC1>(const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NodeMask", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ProtectionType", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS>(const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ClearValue", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS>(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SrcSubresource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DstSubresource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DstX", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DstY", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SrcRect", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS>(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pSrcResource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pDstResource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SubresourceCount", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pSubresourceParameters", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ResolveMode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PreserveResolveSource", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_PASS_RENDER_TARGET_DESC>(const D3D12_RENDER_PASS_RENDER_TARGET_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "cpuDescriptor", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "BeginningAccess", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "EndingAccess", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>(const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "cpuDescriptor", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthBeginningAccess", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilBeginningAccess", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DepthEndingAccess", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "StencilEndingAccess", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DISPATCH_RAYS_DESC>(const D3D12_DISPATCH_RAYS_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RayGenerationShaderRecord", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "MissShaderTable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "HitGroupTable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "CallableShaderTable", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_SUBRESOURCE_DATA>(const D3D12_SUBRESOURCE_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pData", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RowPitch", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SlicePitch", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_MEMCPY_DEST>(const D3D12_MEMCPY_DEST& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pData", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "RowPitch", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "SlicePitch", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DISPATCH_MESH_ARGUMENTS>(const D3D12_DISPATCH_MESH_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ThreadGroupCountX", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ThreadGroupCountY", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ThreadGroupCountZ", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D_SHADER_MACRO>(const D3D_SHADER_MACRO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Name", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Definition", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS>(const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "MaxMessagesPerCommandList", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DefaultShaderPatchMode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "PipelineStateCreateFlags", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR>(const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SlowdownFactor", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS>(const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ShaderPatchMode", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_MESSAGE>(const D3D12_MESSAGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Category", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Severity", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "ID", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pDescription", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DescriptionByteLength", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_INFO_QUEUE_FILTER_DESC>(const D3D12_INFO_QUEUE_FILTER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "NumCategories", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pCategoryList", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumSeverities", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pSeverityList", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "NumIDs", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "pIDList", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<D3D12_INFO_QUEUE_FILTER>(const D3D12_INFO_QUEUE_FILTER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "AllowList", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "DenyList", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<GUID>(const GUID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Data1", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Data2", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Data3", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "Data4", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<tagRECT>(const tagRECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "left", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "top", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "right", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "bottom", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<tagPOINT>(const tagPOINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "x", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "y", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}

template <> std::string ToString<_SECURITY_ATTRIBUTES>(const _SECURITY_ATTRIBUTES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "nLength", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "lpSecurityDescriptor", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
            FieldToString(strStrm, false, "bInheritHandle", toStringFlags, tabCount, tabSize, static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`"));
        }
    );
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
