/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "image_writer.h"

#include "platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(imagewriter)

const uint16_t kBmpBitCount = 32; // Expecting 32-bit BGRA bitmap data.
const uint32_t kBmpBpp      = 4;  // Expecting 4 bytes per pixel for 32-bit BGRA bitmap data.

bool WriteBmpImage(const std::string& filename, uint32_t width, uint32_t height, uint64_t data_size, const void* data)
{
    bool     success    = false;
    uint32_t row_pitch  = width * kBmpBpp;
    uint32_t image_size = height * row_pitch;

    if (image_size <= data_size)
    {
        FILE*   file   = nullptr;
        int32_t result = util::platform::FileOpen(&file, filename.c_str(), "wb");

        if ((result == 0) && (file != nullptr))
        {
            BmpFileHeader file_header;
            BmpInfoHeader info_header;

            file_header.type      = ('M' << 8) | 'B';
            file_header.reserved1 = 0;
            file_header.reserved2 = 0;
            file_header.off_bits  = sizeof(file_header) + sizeof(info_header);
            file_header.size      = image_size + file_header.off_bits;

            info_header.size             = sizeof(info_header);
            info_header.width            = width;
            info_header.height           = height;
            info_header.planes           = 1;
            info_header.bit_count        = kBmpBitCount;
            info_header.compression      = 0;
            info_header.size_image       = 0;
            info_header.x_pels_per_meter = 0;
            info_header.y_pels_per_meter = 0;
            info_header.clr_used         = 0;
            info_header.clr_important    = 0;

            util::platform::FileWrite(&file_header, sizeof(file_header), 1, file);
            util::platform::FileWrite(&info_header, sizeof(info_header), 1, file);

            // Y needs to be inverted when writing the bitmap data.
            auto height_1 = height - 1;
            auto bytes    = reinterpret_cast<const uint8_t*>(data);

            for (uint32_t i = 0; i < height; ++i)
            {
                util::platform::FileWrite(&bytes[(height_1 - i) * row_pitch], 1, row_pitch, file);
            }

            if (!ferror(file))
            {
                success = true;
            }

            util::platform::FileClose(file);
        }
    }

    return success;
}

GFXRECON_END_NAMESPACE(imagewriter)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
