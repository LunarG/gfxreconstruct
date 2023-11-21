/*
** Copyright (c) 2022-2023 LunarG, Inc.
** Copyright (c) 2023 Valve Corporation.
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

#include "util/json_util.h"
#include "util/to_string.h"
#include "util/logging.h"

#include <codecvt> // For encoding wstring_view to utf8.

#if defined(D3D12_SUPPORT)
#include <winerror.h> // D3D12 and DXGI HRESULT return values.
// Still needed for D3D12 return values
// <https://learn.microsoft.com/en-us/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues>
#include <d3d9.h>
#include <unordered_map>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

void FieldToJson(nlohmann::ordered_json& jdata, const float data[4], const util::JsonOptions& options)
{
    FieldToJson(jdata, data, 4, options);
}

void FieldToJson(nlohmann::ordered_json& jdata, const uint32_t data[4], const util::JsonOptions& options)
{
    FieldToJson(jdata, data, 4, options);
}

void FieldToJson(nlohmann::ordered_json& jdata, const uint64_t data[4], const util::JsonOptions& options)
{
    FieldToJson(jdata, data, 4, options);
}

void HandleToJson(nlohmann::ordered_json& jdata, const format::HandleId handle, const JsonOptions& options)
{
    if (options.hex_handles)
    {
        // A JSON string
        jdata = util::to_hex_variable_width(handle);
    }
    else
    {
        // A JSON number
        jdata = handle;
    }
}

void HandleToJson(nlohmann::ordered_json& jdata,
                  const format::HandleId* data,
                  size_t                  num_elements,
                  const JsonOptions&      options)
{
    if (data)
    {
        for (size_t i = 0; i < num_elements; ++i)
        {
            HandleToJson(jdata[i], data[i], options);
        }
    }
    else
    {
        jdata = nullptr;
    }
}

// The following look trivial but there is some work in a header-only
// library hidden in the assignments so we can give the inlining of that code a
// natural place to stop right here.

void Bool32ToJson(nlohmann::ordered_json& jdata, const uint32_t data, const util::JsonOptions& options)
{
    jdata = static_cast<bool>(data);
}

void FieldToJson(nlohmann::ordered_json& jdata, short data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, int data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, long data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, long long data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, unsigned short data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, unsigned int data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, unsigned long data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, unsigned long long data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, float data, const JsonOptions& options)
{
    if (std::isnan(data))
    {
        GFXRECON_LOG_WARNING_ONCE("Converting a NAN to zero.");
        data = 0.0f;
    }
    else if (std::isinf(data))
    {
        GFXRECON_LOG_WARNING_ONCE("Converting an infinity to max or min.");
        if (data < 0)
        {
            data = std::numeric_limits<float>::min();
        }
        else
        {
            data = std::numeric_limits<float>::max();
        }
    }
    // Normal and denormal/subnormal numbers pass through unchanged and unremarked.

    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, double data, const util::JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const std::string_view data, const util::JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const std::wstring_view data, const util::JsonOptions& options)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
    jdata = utf8_conv.to_bytes(data.data(), data.data() + data.length());
}

#if defined(D3D12_SUPPORT)

// const char * might be better to avoid two copies of each string in the process at runtime (one in the static data
// section for the literal string and one on the heap in the map). Even better would be for this to be a const array of
// pairs of HRESULT and const char*const with a flat_map style adaptor so the "map" itself could live in the const data
// section rather than being heap allocated as it is now. Possibly expand with more from
// <https://learn.microsoft.com/en-us/windows/win32/com/com-error-codes-10> as docs for
// D3D12_DEVICE_REMOVED_EXTENDED_DATA1's HRESULT member lead there.
const static std::unordered_map<HRESULT, std::string> kHresults{
    // Basic names for zero and one from <winerror.h> also used by D3D12:
    { S_OK, "S_OK" },
    { S_FALSE, "S_FALSE" },
    // D3D12 Errors from <winerror.h>:
    // <https://learn.microsoft.com/en-us/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues>
    { D3D12_ERROR_ADAPTER_NOT_FOUND, "D3D12_ERROR_ADAPTER_NOT_FOUND" },
    { D3D12_ERROR_DRIVER_VERSION_MISMATCH, "D3D12_ERROR_DRIVER_VERSION_MISMATCH" },
    { D3D12_ERROR_INVALID_REDIST, "D3D12_ERROR_INVALID_REDIST" },
    // D3D9 Errors inherited by D3D12:
    { D3DERR_INVALIDCALL, "D3DERR_INVALIDCALL" },
    { D3DERR_WASSTILLDRAWING, "D3DERR_WASSTILLDRAWING" },
    // DXGI Errors from <winerror.h>:
    // https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/dxgi-error
    { DXGI_ERROR_ACCESS_DENIED, "DXGI_ERROR_ACCESS_DENIED" },
    { DXGI_ERROR_ACCESS_LOST, "DXGI_ERROR_ACCESS_LOST" },
    { DXGI_ERROR_ALREADY_EXISTS, "DXGI_ERROR_ALREADY_EXISTS" },
    { DXGI_ERROR_CANNOT_PROTECT_CONTENT, "DXGI_ERROR_CANNOT_PROTECT_CONTENT" },
    { DXGI_ERROR_DEVICE_HUNG, "DXGI_ERROR_DEVICE_HUNG" },
    { DXGI_ERROR_DEVICE_REMOVED, "DXGI_ERROR_DEVICE_REMOVED" },
    { DXGI_ERROR_DEVICE_RESET, "DXGI_ERROR_DEVICE_RESET" },
    { DXGI_ERROR_DRIVER_INTERNAL_ERROR, "DXGI_ERROR_DRIVER_INTERNAL_ERROR" },
    { DXGI_ERROR_FRAME_STATISTICS_DISJOINT, "DXGI_ERROR_FRAME_STATISTICS_DISJOINT" },
    { DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE, "DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE" },
    { DXGI_ERROR_INVALID_CALL, "DXGI_ERROR_INVALID_CALL" },
    { DXGI_ERROR_MORE_DATA, "DXGI_ERROR_MORE_DATA" },
    { DXGI_ERROR_NAME_ALREADY_EXISTS, "DXGI_ERROR_NAME_ALREADY_EXISTS" },
    { DXGI_ERROR_NONEXCLUSIVE, "DXGI_ERROR_NONEXCLUSIVE" },
    { DXGI_ERROR_NOT_CURRENTLY_AVAILABLE, "DXGI_ERROR_NOT_CURRENTLY_AVAILABLE" },
    { DXGI_ERROR_NOT_FOUND, "DXGI_ERROR_NOT_FOUND" },
    { DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED, "DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED" },
    { DXGI_ERROR_REMOTE_OUTOFMEMORY, "DXGI_ERROR_REMOTE_OUTOFMEMORY" },
    { DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE, "DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE" },
    { DXGI_ERROR_SDK_COMPONENT_MISSING, "DXGI_ERROR_SDK_COMPONENT_MISSING" },
    { DXGI_ERROR_SESSION_DISCONNECTED, "DXGI_ERROR_SESSION_DISCONNECTED" },
    { DXGI_ERROR_UNSUPPORTED, "DXGI_ERROR_UNSUPPORTED" },
    { DXGI_ERROR_WAIT_TIMEOUT, "DXGI_ERROR_WAIT_TIMEOUT" },
    { DXGI_ERROR_WAS_STILL_DRAWING, "DXGI_ERROR_WAS_STILL_DRAWING" },
    // Extra OLE Codes from <winerror.h> (we should never see these from DX12/DXGI but just in case):
    { E_UNEXPECTED, "E_UNEXPECTED" },
    { E_NOINTERFACE, "E_NOINTERFACE" },
    { E_POINTER, "E_POINTER" },
    { E_HANDLE, "E_HANDLE" },
    { E_ABORT, "E_ABORT" },
    { E_ACCESSDENIED, "E_ACCESSDENIED" },
    // Misc errors:
    { E_FAIL, "E_FAIL" },
    { E_OUTOFMEMORY, "E_OUTOFMEMORY" },
    { E_INVALIDARG, "E_INVALIDARG" },
    { E_NOTIMPL, "E_NOTIMPL" },
};

/// @brief Turn a D3D12 or DXGI HRESULT into a string with the same character
/// sequence as the identifier of the C macro defining it in a header like
/// winerror.h.
/// @param hresult A D3D12 or DXGI result code.
std::string HresultToString(const HRESULT hresult)
{
    const auto  found = kHresults.find(hresult);
    std::string result;
    if (found != kHresults.end())
    {
        result = found->second;
    }
    else
    {
        result = util::to_hex_variable_width(static_cast<unsigned long>(hresult));
        GFXRECON_LOG_DEBUG("HresultToString() passed unkown HRESULT: %s.", result.c_str());
    }
    return result;
}

void HresultToJson(nlohmann::ordered_json& jdata, const HRESULT hresult, const util::JsonOptions& options)
{
    FieldToJson(jdata, HresultToString(hresult), options);
}

#endif

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)