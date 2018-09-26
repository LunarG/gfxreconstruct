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

#ifndef BRIMSTONE_FILE_PROCESSOR_H
#define BRIMSTONE_FILE_PROCESSOR_H

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

#include "util/defines.h"
#include "util/compressor.h"
#include "format/api_call_id.h"
#include "format/decoder.h"
#include "format/format.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class FileProcessor
{
public:
    FileProcessor();

    ~FileProcessor();

    void AddDecoder(Decoder* decoder) { decoders_.push_back(decoder); }

    void RemoveDecoder(Decoder* decoder) { decoders_.erase(std::remove(decoders_.begin(), decoders_.end(), decoder), decoders_.end()); }

    bool Initialize(const std::string& filename);

    bool ProcessNextFrame();

    bool ProcessAllFrames();

    const FileHeader& GetFileHeader() const { return file_header_; }

    const std::vector<FileOptionPair>& GetFileOptions() const { return file_options_; }

    uint64_t NumBytesRead() { return bytes_read_; }

private:
    bool ReadFileHeader();

    bool ReadBlockHeader(BlockHeader* block_header);

    bool ReadParameterBuffer(size_t buffer_size);

    bool ReadCompressedParameterBuffer(size_t compressed_buffer_size, size_t expected_uncompressed_size, size_t* uncompressed_buffer_size);

    bool ReadBytes(void* buffer, size_t buffer_size);

    bool SkipBytes(size_t skip_size);

    bool ProcessFunctionCall(const BlockHeader& block_header, ApiCallId call_id);

    bool ProcessMetaData(const BlockHeader& block_header, MetaDataType meta_type);

    bool IsFrameDelimiter(ApiCallId call_id) const;

    bool IsFileHeaderValid() const { return (file_header_.fourcc == BRIMSTONE_FOURCC) ? true : false; }

    bool IsFileValid() const { return (file_descriptor_ && !feof(file_descriptor_) && !ferror(file_descriptor_)) ? true : false; }

private:
    FILE*                       file_descriptor_;
    std::string                 filename_;
    FileHeader                  file_header_;
    std::vector<FileOptionPair> file_options_;
    EnabledOptions              enabled_options_;
    uint64_t                    bytes_read_;
    std::vector<Decoder*>       decoders_;
    std::vector<uint8_t>        parameter_buffer_;
    std::vector<uint8_t>        compressed_parameter_buffer_;
    util::Compressor*           compressor_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_DECODER_H
