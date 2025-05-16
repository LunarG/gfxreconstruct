/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "format/format_util.h"

#include "util/logging.h"
#include "util/lz4_compressor.h"
#include "util/zlib_compressor.h"
#include "util/zstd_compressor.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(format)

bool ValidateFileHeader(const FileHeader& header)
{
    bool valid = true;

    if (header.fourcc != GFXRECON_FOURCC)
    {
        GFXRECON_LOG_ERROR("Invalid file: File header does not contain the expected unrecognized four character code.");
        valid = false;
    }

    // TODO: Verify version is supported.

    return valid;
}

util::Compressor* CreateCompressor(CompressionType type)
{
    util::Compressor* compressor = nullptr;

    switch (type)
    {
        case kLz4:
#if defined(GFXRECON_ENABLE_LZ4_COMPRESSION)
            compressor = new util::Lz4Compressor();
#else
            GFXRECON_LOG_ERROR(
                "Failed to initialize compression module: Application was built with LZ4 compression disabled.");
#endif // GFXRECON_ENABLE_LZ4_COMPRESSION
            break;
        case kZlib:
#if defined(GFXRECON_ENABLE_ZLIB_COMPRESSION)
            compressor = new util::ZlibCompressor();
#else
            GFXRECON_LOG_ERROR(
                "Failed to initialize compression module: Application was built with zlib compression disabled.");
#endif // GFXRECON_ENABLE_ZLIB_COMPRESSION
            break;
        case kZstd:
#if defined(GFXRECON_ENABLE_ZSTD_COMPRESSION)
            compressor = new util::ZstdCompressor();
#else
            GFXRECON_LOG_ERROR(
                "Failed to initialize compression module: Application was built with Zstandard compression disabled.");
#endif // GFXRECON_ENABLE_ZSTD_COMPRESSION
            break;
        case kNone:
            // Nothing to do here.
            break;
        default:
            GFXRECON_LOG_ERROR("Failed to initialize compression module: Unrecognized compression type ID %d", type);
            break;
    }

    return compressor;
}

std::string GetCompressionTypeName(CompressionType type)
{
    switch (type)
    {
        case kLz4:
            return "LZ4";
        case kZlib:
            return "zlib";
        case kZstd:
            return "Zstandard";
        case kNone:
            return "None";
        default:
            break;
    }

    return "";
}

static std::unordered_map<ApiCallId, const char*> api_id_map = {
#include "generated/generated_api_call_id_string_pairs.h"
};

std::string GetApiCallName(ApiCallId call_id)
{
    auto name_it = api_id_map.find(call_id);
    if (name_it != api_id_map.end())
        return name_it->second;

    GFXRECON_ASSERT("INVALID CALL ID");
    return "INVALID_CALL_ID";
}

std::string GetApiFamilyName(ApiFamilyId family_id)
{
    std::string family_name;
    switch (family_id)
    {
        default:
            GFXRECON_ASSERT("INVALID FAMILY ID");
            family_name = "INVALID_FAMILY_ID";
            break;
        case format::ApiFamily_Vulkan:
            family_name = "Vulkan ";
            break;
        case format::ApiFamily_Dxgi:
            family_name = "Dxgi ";
            break;
        case format::ApiFamily_D3D12:
            family_name = "D3D12 ";
            break;
        case format::ApiFamily_AGS:
            family_name = "AGS ";
            break;
        case format::ApiFamily_D3D11:
            family_name = "D3D11 ";
            break;
        case format::ApiFamily_D3D11On12:
            family_name = "D3D11On12 ";
            break;
        case format::ApiFamily_OpenXR:
            family_name = "OpenXR ";
            break;
    }

    return family_name;
}

std::string GetApiCallFamilyName(ApiCallId call_id)
{
    return GetApiFamilyName(GetApiCallFamily(call_id));
}

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)
