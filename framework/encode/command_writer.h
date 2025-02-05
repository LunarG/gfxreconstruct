/*
 ** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_COMMAND_WRITER_H
#define GFXRECON_ENCODE_COMMAND_WRITER_H

#include "format/format.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/thread_data.h"
#include "util/output_stream.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

/**
 * @brief `CommandWriter` is a utility for writing commands to an `OutputStream`.
 */
class CommandWriter
{
  public:
    CommandWriter(util::ThreadData* thread_data, util::OutputStream* output_stream, util::Compressor* compressor);

    void WriteInitBufferCmd(format::ApiFamilyId p_api_family,
                            format::HandleId    p_device_id,
                            format::HandleId    p_buffer_id,
                            uint64_t            p_offset,
                            uint64_t            p_size,
                            const void*         p_data);

    void WriteInitImageCmd(format::ApiFamilyId          p_api_family,
                           format::HandleId             p_device_id,
                           format::HandleId             p_image_id,
                           uint32_t                     p_aspect,
                           uint32_t                     p_layout,
                           uint32_t                     p_mip_levels,
                           const std::vector<uint64_t>& p_level_sizes,
                           uint64_t                     p_size,
                           const void*                  p_data);

  private:
    util::ThreadData*   thread_data_;
    util::OutputStream* output_stream_;
    util::Compressor*   compressor_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_COMMAND_WRITER_H
