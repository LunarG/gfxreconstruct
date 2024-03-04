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

#ifndef GFXRECON_DECODE_FILE_TRANSFORMER_H
#define GFXRECON_DECODE_FILE_TRANSFORMER_H

#include "format/format.h"
#include "util/defines.h"
#include "util/compressor.h"

#include <cstdio>
#include <memory>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class FileTransformer
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
        kErrorSeekingFile                  = -11,
        kErrorWritingFile                  = -12,
        kErrorWritingFileHeader            = -13,
        kErrorWritingBlockHeader           = -14,
        kErrorWritingCompressedBlockHeader = -15,
        kErrorWritingBlockData             = -16,
        kErrorWritingCompressedBlockData   = -17,
        kErrorCopyingBlockData             = -18,
        kErrorUnsupportedBlockType         = -19
    };

  public:
    FileTransformer();

    virtual ~FileTransformer();

    bool Initialize(const std::string& input_filename, const std::string& output_filename);

    // Returns false if processing failed.  Use GetErrorState() to determine error condition for failure case.
    bool Process();

    const format::FileHeader& GetFileHeader() const { return file_header_; }

    const std::vector<format::FileOptionPair>& GetFileOptions() const { return file_options_; }

    uint64_t GetNumBytesRead() const { return bytes_read_; }

    uint64_t GetNumBytesWritten() const { return bytes_written_; }

    Error GetErrorState() const { return error_state_; }

  protected:
    bool IsFileHeaderValid() const { return (file_header_.fourcc == GFXRECON_FOURCC); }

    bool IsFileValid(FILE* fd) const { return ((fd != nullptr) && !feof(fd) && !ferror(fd)); }

    bool IsLoadingState() const { return loading_state_; }

    std::vector<uint8_t>& GetParameterBuffer() { return parameter_buffer_; }

    const std::vector<uint8_t>& GetParameterBuffer() const { return parameter_buffer_; }

    std::vector<uint8_t>& GetCompressedParameterBuffer() { return compressed_parameter_buffer_; }

    const std::vector<uint8_t>& GetCompressedParameterBuffer() const { return compressed_parameter_buffer_; }

    util::Compressor* GetCompressor() { return compressor_.get(); }

    const util::Compressor* GetCompressor() const { return compressor_.get(); }

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

    void HandleBlockWriteError(Error error_code, const char* error_message);

    void HandleBlockCopyError(Error error_code, const char* error_message);

    bool CreateCompressor(format::CompressionType type, std::unique_ptr<util::Compressor>* compressor);

    virtual bool WriteFileHeader(const format::FileHeader& header, const std::vector<format::FileOptionPair>& options);

    virtual bool ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id);

    virtual bool
    ProcessMethodCall(const format::BlockHeader& block_header, format::ApiCallId call_id, uint64_t block_index = 0);

    virtual bool ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id);

    virtual bool ProcessStateMarker(const format::BlockHeader& block_header, format::MarkerType marker_type);

    uint64_t GetCurrentBlockIndex() { return block_index_; }

  private:
    bool ProcessFileHeader();

    bool ProcessNextBlock();

    bool ReadBlockHeader(format::BlockHeader* block_header);

  protected:
    FILE*                               input_file_;
    FILE*                               output_file_;
    format::FileHeader                  file_header_;
    std::vector<format::FileOptionPair> file_options_;
    format::EnabledOptions              enabled_options_;
    uint64_t                            bytes_read_;
    uint64_t                            bytes_written_;
    Error                               error_state_;
    bool                                loading_state_;
    std::vector<uint8_t>                parameter_buffer_;
    std::vector<uint8_t>                compressed_parameter_buffer_;
    std::unique_ptr<util::Compressor>   compressor_;
    uint64_t                            block_index_{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FILE_TRANSFORMER_H
