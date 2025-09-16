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

size_t WriteBuffer(const std::string& filename, const void* data, size_t size, const Compressor* compressor)
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

    bool   success;
    size_t bytes_written;
    if (compressor != nullptr)
    {
        std::vector<uint8_t> compressed_data;
        const size_t         compressed_size =
            compressor->Compress(size, static_cast<const uint8_t*>(data), &compressed_data, 0);

        if (compressed_size)
        {
            success       = util::platform::FileWrite(compressed_data.data(), compressed_size, file);
            bytes_written = compressed_size;
        }
        else
        {
            success       = util::platform::FileWrite(data, size, file);
            bytes_written = size;
        }
    }
    else
    {
        success       = util::platform::FileWrite(data, size, file);
        bytes_written = size;
    }

    util::platform::FileClose(file);

    return success ? bytes_written : 0;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(bufferwriter)