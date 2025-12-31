/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_BLOCK_PARSER_H
#define GFXRECON_DECODE_BLOCK_PARSER_H

#include "decode/parsed_block.h"
#include "util/heap_buffer.h"
#include "util/file_input_stream.h"

#include <functional>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// As the BlockParser is doing all the Read/Peek, this is the best place to define this
// NOTE: Eventually FileInputStream will be an abstract base class for whatever input stream is in use
using FileInputStream    = util::FStreamFileInputStream;
using FileInputStreamPtr = std::shared_ptr<FileInputStream>;

enum BlockIOError : int32_t
{
    kEndOfFile                         = 1, // when block reading is EOF at a block boundary
    kErrorNone                         = 0,
    kErrorInvalidFileDescriptor        = -1,
    kErrorOpeningFile                  = -2,
    kErrorReadingFile                  = -3, // ferror() return true at start of file
    kErrorReadingFileHeader            = -4,
    kErrorReadingBlockHeader           = -5,
    kErrorReadingCompressedBlockHeader = -6,
    kErrorReadingBlockData             = -7,
    kErrorReadingCompressedBlockData   = -8,
    kErrorInvalidFourCC                = -9,
    kErrorUnsupportedCompressionType   = -10,
    kErrorSeekingFile                  = -11, // Additional error types from FileTransformer
    kErrorWritingFile                  = -12,
    kErrorWritingFileHeader            = -13,
    kErrorWritingBlockHeader           = -14,
    kErrorWritingCompressedBlockHeader = -15,
    kErrorWritingBlockData             = -16,
    kErrorWritingCompressedBlockData   = -17,
    kErrorCopyingBlockData             = -18,
    kErrorUnsupportedBlockType         = -19

};

// TODO: Find a better allocator (or improve this one), and share with FileInputStream
using BufferPool = util::HeapBufferPool::PoolPtr;

class BlockParser
{
  public:
    // The three use cases are:
    // Always: non-preloaded replay
    // Never:  file transforming tools that pass through most blocks without decoding
    // Queue Optimized: pre-loaded replay of ParsedBlocks
    enum DecompressionPolicy
    {
        kAlways = 0,     // Always decompress parameter data when parsing blocks
        kNever,          // Never decompress parameter data when parsing blocks
        kQueueOptimized, // Decompress only "small" blocks deferring large block to JIT decompression, suitable for
                         // block preload/preparsed content
    };

    // The threshold is based on a trade off, maximize the number blocks with no decompression at replay
    // but minimizing the memory overhead of the non-deferred compressions.
    //
    // Threshhold data came from a histogram of numerous large traces and is chosen as a trade-off
    // that allows the majority of blocks to be decompressed when parsed and enqueued (for preloaded replay), while
    // the 3/4 of the *bytes* are not decompressed when enqueued, limiting the memory impact
    static constexpr size_t kDeferThreshold = 96 + sizeof(format::BlockHeader); // 83% of blocks, 26% of bytes

    using UncompressedStore = ParsedBlock::UncompressedStore;

    void SetFrameNumber(uint64_t frame_number) noexcept { frame_number_ = frame_number; }
    void SetBlockIndex(uint64_t block_index) noexcept { block_index_ = block_index; }

    [[nodiscard]] uint64_t GetFrameNumber() const noexcept { return frame_number_; }
    [[nodiscard]] uint64_t GetBlockIndex() const noexcept { return block_index_; }

    // Parse the block header and load a block buffer
    BlockIOError ReadBlockBuffer(FileInputStreamPtr& input_stream, BlockBuffer& block_buffer);

    // Define parsers for every block and sub-block type
    ParsedBlock ParseBlock(BlockBuffer& block_buffer);
    ParsedBlock ParseFunctionCall(BlockBuffer& block_buffer);
    ParsedBlock ParseMethodCall(BlockBuffer& block_buffer);
    ParsedBlock ParseMetaData(BlockBuffer& block_buffer);
    ParsedBlock ParseFrameMarker(BlockBuffer& block_buffer);
    ParsedBlock ParseStateMarker(BlockBuffer& block_buffer);
    ParsedBlock ParseAnnotation(BlockBuffer& block_buffer);

    void HandleBlockReadError(BlockIOError error_code, const char* error_message);
    void
    WarnUnknownBlock(const BlockBuffer& block_buffer, const char* sub_type_label = nullptr, uint32_t sub_type = 0U);

    bool ShouldDeferDecompression(size_t block_size);

    // Control use of parser local storage for decompression
    struct UseParserLocalStorageTag
    {};
    bool                           DecompressSpan(const BlockBuffer::BlockSpan&   compressed_span,
                                                  size_t                          expanded_size,
                                                  ParsedBlock::UncompressedStore& uncompressed_buffer);
    ParsedBlock::UncompressedStore DecompressSpan(const BlockBuffer::BlockSpan& compressed_span, size_t expanded_size);
    const uint8_t*
    DecompressSpan(const BlockBuffer::BlockSpan& compressed_span, size_t expanded_size, UseParserLocalStorageTag);

    using ErrorHandler = std::function<void(BlockIOError, const char*)>;
    BlockParser(ErrorHandler err, BufferPool& pool, util::Compressor* compressor) :
        pool_(pool), err_handler_(std::move(err)), compressor_(compressor)
    {}
    BlockParser() = delete;

    void SetDecompressionPolicy(DecompressionPolicy policy) noexcept { decompression_policy_ = policy; }
    void SetBlockReferencePolicy(ParsedBlock::BlockReferencePolicy policy) noexcept
    {
        block_reference_policy_ = policy;
    }

    DecompressionPolicy               GetDecompressionPolicy() const noexcept { return decompression_policy_; }
    ParsedBlock::BlockReferencePolicy GetBlockReferencePolicy() const noexcept { return block_reference_policy_; }

  private:
    struct ParameterReadResult
    {
        bool                   success           = true;
        bool                   is_compressed     = false;
        size_t                 uncompressed_size = 0;
        BlockBuffer::BlockSpan buffer;
    };

    template <typename ArgPayload>
    [[nodiscard]] ParsedBlock MakeCompressibleParsedBlock(BlockBuffer&                            block_buffer,
                                                          const BlockParser::ParameterReadResult& result,
                                                          ArgPayload&&                            args);

    template <typename ArgPayload>
    ParsedBlock
    MakeIncompressibleParsedBlock(BlockBuffer& block_buffer, ArgPayload&& args, bool references_block_buffer = false);

    constexpr static uint64_t kReadSizeFromBuffer = std::numeric_limits<std::uint64_t>::max();
    ParameterReadResult
    ReadParameterBuffer(const char* label, BlockBuffer& block_buffer, uint64_t uncompressed_size = kReadSizeFromBuffer);

    BufferPool                        pool_; // TODO: Get a better pool, and share with FileInputStream
    ErrorHandler                      err_handler_;
    util::Compressor*                 compressor_             = nullptr;
    DecompressionPolicy               decompression_policy_   = DecompressionPolicy::kAlways;
    ParsedBlock::BlockReferencePolicy block_reference_policy_ = ParsedBlock::BlockReferencePolicy::kNonOwnedReference;

    uint64_t frame_number_ = 0;
    uint64_t block_index_  = 0;

    ParsedBlock::UncompressedStore uncompressed_working_buffer_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif // GFXRECON_DECODE_BLOCK_PARSER_H
