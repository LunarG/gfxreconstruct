/*
** Copyright (c) 2023 LunarG, Inc.
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

#include "buffer_writer.h"
#include "platform.h"
#include "logging.h"
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(bufferwriter)

bool WriteBuffer(const std::string& filename, const void* data, size_t size, const Compressor* compressor)
{
    assert(data);
    assert(size);

    FILE*   file   = nullptr;
    int32_t result = util::platform::FileOpen(&file, filename.c_str(), "wb");

    GFXRECON_LOG_INFO("%s(): Writing file \"%s\"", __func__, filename.c_str())

    if ((result) || (file == nullptr))
    {
        GFXRECON_LOG_ERROR("%s() Failed to open file (%s)", __func__, strerror(errno));
        return false;
    }

    bool success;
    if (compressor != nullptr)
    {
        std::vector<uint8_t> compressed_data;
        size_t compressed_size = compressor->Compress(size, static_cast<const uint8_t*>(data), &compressed_data, 0);
        if (compressed_size > 0)
        {
            success = util::platform::FileWrite(compressed_data.data(), compressed_size, file);
        }
        else
        {
            GFXRECON_LOG_WARNING("Compression failed for file %s. File's content will be uncompressed.",
                                 filename.c_str())
            success = util::platform::FileWrite(data, size, file);
        }
    }
    else
    {
        success = util::platform::FileWrite(data, size, file);
    }

    util::platform::FileClose(file);

    return success;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(bufferwriter)