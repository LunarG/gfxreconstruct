/*
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef BRIMSTONE_DECOMPRESS_DECODER_H
#define BRIMSTONE_DECOMPRESS_DECODER_H

#include <mutex>
#include <string>

#include "format/decoder.h"

#include "util/file_output_stream.h"
#include "util/memory_output_stream.h"
#include "util/compressor.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

enum DecompressMode : uint32_t
{
    kNone       = 0,
    kDecompress = 1,
    kCompress   = 2
};

class DecompressDecoder : public Decoder
{
  public:
    virtual ~DecompressDecoder() { Destroy(); }

    bool Initialize(std::string                        filename,
                    const FileHeader&                  file_header,
                    const std::vector<FileOptionPair>& option_list,
                    util::CompressionType              target_compression_type);
    void Destroy();

    virtual bool SupportsApiCall(ApiCallId call_id) override
    {
        return ((call_id >= 0x1000) && (call_id <= 0x112b)) ? true : false;
    }
    virtual void
    DecodeFunctionCall(ApiCallId call_id, const ApiCallOptions& call_options, const uint8_t* buffer, size_t buffer_size);

    virtual void DispatchDisplayMessageCommand(const std::string& message) override;
    virtual void
                 DispatchFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;
    virtual void DispatchResizeWindowCommand(HandleId surface_id, uint32_t width, uint32_t height) override;

    uint64_t     NumBytesWritten() { return bytes_written_; }

  private:
    DecompressMode                          decompress_mode_;
    std::unique_ptr<util::FileOutputStream> file_stream_;
    std::string                             filename_;
    std::mutex                              file_lock_;
    uint64_t                                bytes_written_;
    std::vector<uint8_t>                    compressed_buffer_;
    util::Compressor*                       compressor_;
    bool                                    write_thread_id_;
    bool                                    write_begin_end_times_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_DECOMPRESS_DECODER_H
