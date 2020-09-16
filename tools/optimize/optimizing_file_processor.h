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

#ifndef GFXRECON_OPTIMIZING_FILE_PPROCESSOR_H
#define GFXRECON_OPTIMIZING_FILE_PPROCESSOR_H

#include "format/format.h"
#include "util/compressor.h"

#include <cstdio>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

class OptimizingFileProcessor
{
  public:
    enum Error : int32_t
    {
        kErrorNone                         = 0,
        kErrorInvalidFileDescriptor        = -1,
        kErrorOpeningFile                  = -2,
        kErrorReadingFile                  = -3,
        kErrorReadingFileHeader            = -4,
        kErrorReadingBlockHeader           = -5,
        kErrorReadingCompressedBlockHeader = -6,
        kErrorReadingBlockData             = -7,
        kErrorReadingCompressedBlockData   = -8,
        kErrorInvalidFourCC                = -9,
        kErrorUnsupportedCompressionType   = -10,
        kErrorWritingFile                  = -11,
        kErrorWritingFileHeader            = -12,
        kErrorWritingBlockHeader           = -13,
        kErrorWritingCompressedBlockHeader = -14,
        kErrorWritingBlockData             = -15,
        kErrorWritingCompressedBlockData   = -16
    };

  public:
    OptimizingFileProcessor(const std::unordered_set<format::HandleId>& unreferenced_ids);

    OptimizingFileProcessor(std::unordered_set<format::HandleId>&& unreferenced_ids);

    ~OptimizingFileProcessor();

    bool Initialize(const std::string& input_filename, const std::string& output_filename);

    // Returns false if processing failed.  Use GetErrorState() to determine error condition for failure case.
    bool Process();

    uint64_t GetNumBytesRead() const { return bytes_read_; }

    uint64_t GetNumBytesWritten() const { return bytes_written_; }

    Error GetErrorState() const { return error_state_; }

  private:
    bool ProcessFileHeader();

    bool ProcessNextBlock();

    bool ReadBlockHeader(format::BlockHeader* block_header);

    bool WriteBlockHeader(const format::BlockHeader& block_header);

    bool ReadParameterBuffer(size_t buffer_size);

    bool ReadCompressedParameterBuffer(size_t  compressed_buffer_size,
                                       size_t  expected_uncompressed_size,
                                       size_t* uncompressed_buffer_size);

    bool ReadBytes(void* buffer, size_t buffer_size);

    bool WriteBytes(const void* buffer, size_t buffer_size);

    bool SkipBytes(uint64_t skip_size);

    bool CopyBytes(uint64_t copy_size);

    void HandleBlockReadError(Error error_code, const char* error_message);

    bool ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id);

    bool ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type);

    bool ProcessStateMarker(const format::BlockHeader& block_header, format::MarkerType marker_type);

    bool FilterInitBufferMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type);

    bool FilterInitImageMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type);

    bool IsFileHeaderValid() const { return (file_header_.fourcc == GFXRECON_FOURCC); }

    bool IsFileValid(FILE* fd) const { return ((fd != nullptr) && !feof(fd) && !ferror(fd)); }

  private:
    std::unordered_set<format::HandleId> unreferenced_ids_;
    FILE*                                input_file_;
    FILE*                                output_file_;
    format::FileHeader                   file_header_;
    std::vector<format::FileOptionPair>  file_options_;
    format::EnabledOptions               enabled_options_;
    uint64_t                             bytes_read_;
    uint64_t                             bytes_written_;
    Error                                error_state_;
    bool                                 loading_state_;
    std::vector<uint8_t>                 parameter_buffer_;
    std::vector<uint8_t>                 compressed_parameter_buffer_;
    std::unique_ptr<util::Compressor>    compressor_;
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_OPTIMIZING_FILE_PPROCESSOR_H
