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
#include "util/strings.h"
#include "format/format_json.h"

#include <codecvt> // For encoding wstring_view to utf8.

#if defined(D3D12_SUPPORT)
#include <winerror.h> // D3D12 and DXGI HRESULT return values.
// Still needed for D3D12 return values
// <https://learn.microsoft.com/en-us/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues>
#include <d3d12.h>
#include <d3d9.h>
#include <unordered_map>
#include "generated/generated_dx12_enum_to_json.h"
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

void FieldToJson(nlohmann::ordered_json& jdata, const LUID& data, const util::JsonOptions& options)
{
    FieldToJson(jdata, *reinterpret_cast<const int64_t*>(&data), options);
}

void FieldToJson(nlohmann::ordered_json& jdata, const LARGE_INTEGER& data, const util::JsonOptions& options)
{
    FieldToJson(jdata["QuadPart"], data.QuadPart, options);
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

void Bool32ToJson(nlohmann::ordered_json& jdata, const uint32_t& data, const util::JsonOptions& options)
{
    jdata = static_cast<bool>(data);
}

void FieldToJson(nlohmann::ordered_json& jdata, const short& data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const int& data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const long& data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const long long& data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const unsigned short& data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const unsigned int& data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const unsigned long& data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const unsigned long long& data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const std::nullptr_t data, const JsonOptions& options)
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
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif
    std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    jdata = utf8_conv.to_bytes(data.data(), data.data() + data.length());
}

#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

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

#if defined(D3D12_SUPPORT)
void FieldToJson(nlohmann::ordered_json&                                  jdata,
                 const format::InitDx12AccelerationStructureGeometryDesc& data,
                 const util::JsonOptions&                                 options)
{
    /// @todo handle enums and so on.
    FieldToJson(jdata["geometry_type"], static_cast<D3D12_RAYTRACING_GEOMETRY_TYPE>(data.geometry_type), options);
    FieldToJson_D3D12_RAYTRACING_GEOMETRY_FLAGS(
        jdata["geometry_flags"], static_cast<D3D12_RAYTRACING_GEOMETRY_FLAGS>(data.geometry_flags), options);
    FieldToJson(jdata["aabbs_count"], data.aabbs_count, options);
    FieldToJson(jdata["aabbs_stride"], data.aabbs_stride, options);
    Bool32ToJson(jdata["triangles_has_transform"], data.triangles_has_transform, options);
    FieldToJson(jdata["triangles_index_format"], static_cast<DXGI_FORMAT>(data.triangles_index_format), options);
    FieldToJson(jdata["triangles_vertex_format"], static_cast<DXGI_FORMAT>(data.triangles_vertex_format), options);
    FieldToJson(jdata["triangles_index_count"], data.triangles_index_count, options);
    FieldToJson(jdata["triangles_vertex_count"], data.triangles_vertex_count, options);
    FieldToJson(jdata["triangles_vertex_stride"], data.triangles_vertex_stride, options);
}
#endif // defined(D3D12_SUPPORT)

void FieldToJson(nlohmann::ordered_json& jdata, const format::DxgiAdapterDesc& data, const util::JsonOptions& options)
{
    FieldToJson(jdata["Description"], std::wstring_view(data.Description), options);
    FieldToJson(jdata["VendorId"], data.VendorId, options);
    FieldToJson(jdata["DeviceId"], data.DeviceId, options);
    FieldToJson(jdata["SubSysId"], data.SubSysId, options);
    FieldToJson(jdata["Revision"], data.Revision, options);
    FieldToJson(jdata["DedicatedVideoMemory"], data.DedicatedVideoMemory, options);
    FieldToJson(jdata["DedicatedSystemMemory"], data.DedicatedSystemMemory, options);
    FieldToJson(jdata["SharedSystemMemory"], data.SharedSystemMemory, options);
    FieldToJson(jdata["LuidLowPart"], data.LuidLowPart, options);
    FieldToJson(jdata["LuidHighPar"], data.LuidHighPart, options);
    // Should we break out the packed data? (2 bits (LSB) to store Type and 30 bits for object ID)
    FieldToJson(jdata["extra_info"], data.extra_info, options);
}

void FieldToJson(nlohmann::ordered_json& jdata, const format::Dx12RuntimeInfo& data, const util::JsonOptions& options)
{
    FieldToJson(jdata["version"], data.version, util::filepath::kFileVersionSize, options);
    FieldToJson(jdata["src"], util::strings::ViewOfCharArray(data.src, util::filepath::kMaxFilePropertySize), options);
}

void FieldToJson(nlohmann::ordered_json& jdata, const util::filepath::FileInfo& data, const util::JsonOptions& options)
{
    FieldToJson(jdata["ProductVersion"],
                strings::ViewOfCharArray(data.ProductVersion, filepath::kMaxFilePropertySize),
                options);
    FieldToJson(
        jdata["FileVersion"], strings::ViewOfCharArray(data.FileVersion, filepath::kMaxFilePropertySize), options);
    FieldToJson(jdata["AppVersion"], data.AppVersion, filepath::kMaxFilePropertySize, options);
    FieldToJson(jdata["AppName"], strings::ViewOfCharArray(data.AppName, filepath::kMaxFilePropertySize), options);
    FieldToJson(
        jdata["CompanyName"], strings::ViewOfCharArray(data.CompanyName, filepath::kMaxFilePropertySize), options);
    FieldToJson(jdata["FileDescription"],
                strings::ViewOfCharArray(data.FileDescription, filepath::kMaxFilePropertySize),
                options);
    FieldToJson(
        jdata["InternalName"], strings::ViewOfCharArray(data.InternalName, filepath::kMaxFilePropertySize), options);
    FieldToJson(jdata["OriginalFilename"],
                strings::ViewOfCharArray(data.OriginalFilename, filepath::kMaxFilePropertySize),
                options);
    FieldToJson(
        jdata["ProductName"], strings::ViewOfCharArray(data.ProductName, filepath::kMaxFilePropertySize), options);
}

#endif

static std::string GenerateFilename(const std::string_view filename, const uint64_t instance_counter)
{
    std::string fullname{ filename };
    return fullname.append("-").append(std::to_string(instance_counter)).append(".bin");
}

static bool WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data)
{
    FILE* file_output = nullptr;
    bool  written_all = false;
    if (util::platform::FileOpen(&file_output, filename.c_str(), "wb") == 0)
    {
        const uint64_t written = util::platform::FileWrite(data, 1, static_cast<size_t>(data_size), file_output);
        if (written >= data_size)
        {
            written_all = true;
        }
        else
        {
            GFXRECON_LOG_ERROR(
                "Only wrote %" PRIu64 " bytes of %" PRIu64 " data to file %s.", written, data_size, filename.c_str());
        }
        util::platform::FileClose(file_output);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to open file %s for writing.", filename.c_str());
    }
    return written_all;
}

bool RepresentBinaryFile(const util::JsonOptions& json_options,
                         nlohmann::ordered_json&  jdata,
                         std::string_view         filename_base,
                         const uint64_t           instance_counter,
                         const uint64_t           data_size,
                         const uint8_t* const     data)
{
    bool written = false;
    // If the data is null or empty, put a null in the JSON.
    if (data_size < 1 || nullptr == data)
    {
        FieldToJson(jdata, nullptr, json_options);
    }
    else
    {
        if (json_options.dump_binaries)
        {
            std::string filename = GenerateFilename(filename_base, instance_counter);
            std::string basename = gfxrecon::util::filepath::Join(json_options.data_sub_dir, filename);
            std::string filepath = gfxrecon::util::filepath::Join(json_options.root_dir, basename);
            if (WriteBinaryFile(filepath, data_size, data))
            {
                FieldToJson(jdata, basename, json_options);
                written = true;
            }
            else
            {
                FieldToJson(jdata, format::kValWriteFailed, json_options);
            }
        }
        else
        {
            FieldToJson(jdata, format::kValBinary, json_options);
        }
    }
    return written;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)