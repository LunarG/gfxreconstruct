/*
** Copyright (c) 2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "decode/resource_util.h"

#include "util/platform.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(resource)

void CopyImageSubresourceMemory(
    uint8_t* dst, const uint8_t* src, size_t offset, size_t size, size_t dst_row_pitch, size_t src_row_pitch)
{
    if (src_row_pitch == dst_row_pitch)
    {
        // Copy entire range without adjustment.
        util::platform::MemoryCopy(dst + offset, size, src, size);
    }
    else
    {
        size_t copy_row_pitch = std::min(dst_row_pitch, src_row_pitch);

        size_t start_row  = offset / src_row_pitch;
        size_t row_offset = offset % src_row_pitch;

        if (row_offset >= copy_row_pitch)
        {
            // When the dst row pitch is smaller than the src row pitch, and the offset points to
            // padding at the end of the row, which is outside the bounds of the dst row pitch, we
            // advance to the start of the next row.  If the write was only to the padding, we set both
            // row_offset and data_size to zero and don't copy anything.
            size -= std::min(src_row_pitch - row_offset, size);
            row_offset = 0;
            ++start_row;
        }

        const uint8_t* copy_src = src;
        uint8_t*       copy_dst = reinterpret_cast<uint8_t*>(dst) + (start_row * dst_row_pitch) + row_offset;

        // Process first partial row.
        if (row_offset > 0)
        {
            // Handle row with both partial begin and end positions.
            size_t copy_size = std::min(copy_row_pitch - row_offset, size);
            util::platform::MemoryCopy(copy_dst, copy_size, copy_src, copy_size);

            copy_src += src_row_pitch - row_offset;
            copy_dst += dst_row_pitch - row_offset;

            size -= std::min(src_row_pitch - row_offset, size);
        }

        // Process remaining rows.
        if (size > 0)
        {
            size_t total_rows    = size / src_row_pitch;
            size_t row_remainder = size % src_row_pitch;

            // First process the complete rows.
            for (size_t i = 0; i < total_rows; ++i)
            {
                size_t copy_size = copy_row_pitch;
                util::platform::MemoryCopy(copy_dst, copy_size, copy_src, copy_size);

                copy_src += src_row_pitch;
                copy_dst += dst_row_pitch;
            }

            // Process a partial end row.
            if (row_remainder != 0)
            {
                size_t copy_size = std::min(copy_row_pitch, row_remainder);
                util::platform::MemoryCopy(copy_dst, copy_size, copy_src, copy_size);
            }
        }
    }
}

GFXRECON_END_NAMESPACE(enumutil)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
