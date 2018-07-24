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

    // TODO: Add file processing options.
    bool Initialize(const std::string& file_name);

    bool ProcessNextFrame();

    bool ProcessAllFrames();

private:
    bool ReadFileHeader();

    bool ReadBlockHeader(BlockHeader* block_header);

    bool ReadFunctionCallHeader(FunctionCallHeader* function_call_header);

    bool ReadParameterBuffer(size_t buffer_size);

    size_t ReadBytes(void* buffer, size_t buffer_size);

    void ProcessFunctionCall(ApiCallId call_id, const uint8_t* parameter_buffer, size_t buffer_size);

    bool IsFrameDelimiter(ApiCallId call_id) const;

    bool IsFileHeaderValid() const { return (file_header_.fourcc == BRIMSTONE_FOURCC) ? true : false; }

    bool IsFileValid() const { return (file_descriptor_ && !feof(file_descriptor_) && !ferror(file_descriptor_)) ? true : false; }

private:
    FILE*                       file_descriptor_;
    std::string                 file_name_;
    FileHeader                  file_header_;
    EnabledOptions              file_options_;
    uint64_t                    bytes_read_;
    std::vector<Decoder*>       decoders_;
    std::vector<uint8_t>        parameter_buffer_;

};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_DECODER_H
