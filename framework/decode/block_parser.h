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
        kQueueOptimized, // Decompress only "small" blocks, deferring large blocks to JIT decompression, suitable for
                         // block preload/preparsed content
    };

    // Threshold data came from a histogram of numerous large traces and is chosen to
    // reduce the number of deferred decompressions at a reasonable marginal memory cost.
    // Memory "Penalty" or "Savings" below are based on the size of enqueued ParsedBlocks for replay.
    //
    // For a threshold of 512 bytes:
    // - Penalty of 74% memory vs. kNever (all deferred), performing > 99% of decompression operations at parse time.
    // - Savings of 42% memory vs. kAlways (none deferred), requiring only < 1% decompressions at replay time.
    //
    // Another choice would be 256: offers 2% lower memory penalty, but doubles replay decompressions vs. 512.
    // - Penalty of 72% memory vs. kNever, performing > 98% of decompression operations at parse time.
    // - Savings of 43% memory vs. kAlways, requiring < 2% decompressions at replay time

    // NOTE: The threshold computation was based on assumptions of compression ratios that need to validated with
    //       additional instrumentation.

    // Minimizes decompression and allocator activity during replay from queue
    static constexpr size_t kDeferThreshold = 512 + sizeof(format::BlockHeader); // 99% of blocks, 37% of bytes

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

    struct DecompressionResult
    {
        ParsedBlock::UncompressedStore decompressed_store = {};
        bool                           success            = false;
    };
    DecompressionResult DecompressSpan(const BlockBuffer::BlockSpan& compressed_span, size_t expanded_size);

    using ErrorHandler = std::function<void(BlockIOError, const char*)>;
    BlockParser(const ErrorHandler& err, BufferPool& pool, util::Compressor* compressor) :
        pool_(pool), err_handler_(err), compressor_(compressor)
    {}

    void                SetDecompressionPolicy(DecompressionPolicy policy) { decompression_policy_ = policy; }
    DecompressionPolicy GetDecompressionPolicy() const { return decompression_policy_; }
    size_t              GetDeferThreshold() const { return kDeferThreshold; }
    bool                ShouldTrim(ParsedBlock& parsed_block);

  private:
    struct ParameterReadResult
    {
        bool                   success           = true;
        bool                   is_compressed     = false;
        size_t                 uncompressed_size = 0;
        BlockBuffer::BlockSpan buffer;
    };
    constexpr static uint64_t kReadSizeFromBuffer = std::numeric_limits<std::uint64_t>::max();
    ParameterReadResult
    ReadParameterBuffer(const char* label, BlockBuffer& block_buffer, uint64_t uncompressed_size = kReadSizeFromBuffer);
    static bool ShouldDefer(size_t block_size);
    bool        DecompressWhenParsed(const ParsedBlock& parsed_block);

    BufferPool          pool_; // TODO: Get a better pool, and share with FileInputStream
    const ErrorHandler& err_handler_;
    util::Compressor*   compressor_           = nullptr;
    DecompressionPolicy decompression_policy_ = DecompressionPolicy::kAlways;

    uint64_t frame_number_ = 0;
    uint64_t block_index_  = 0;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif // GFXRECON_DECODE_BLOCK_PARSER_H
