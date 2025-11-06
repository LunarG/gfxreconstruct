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

enum BlockReadError : int32_t
{
    kEndOfFile                         = 1, // when block reading is EOF at a block boundary
    kErrorNone                         = 0,
    kErrorInvalidFileDescriptor        = -1,
    kErrorOpeningFile                  = -2,
    kErrorReadingFile                  = -3, // ferror() returned true at start of frame processing.
    kErrorReadingFileHeader            = -4,
    kErrorReadingBlockHeader           = -5,
    kErrorReadingCompressedBlockHeader = -6,
    kErrorReadingBlockData             = -7,
    kErrorReadingCompressedBlockData   = -8,
    kErrorInvalidFourCC                = -9,
    kErrorUnsupportedCompressionType   = -10
};

// TODO: Find a better allocator (or improve this one), and share with FileInputStream
using BufferPool = util::HeapBufferPool::PoolPtr;

class BlockParser
{
  public:
    enum DecompressionPolicy
    {
        kAlways = 0,     // Always decompress parameter data when parsing blocks
        kNever,          // Never decompress parameter data when parsing blocks
        kQueueOptimized, // Decompress only "small" blocks deferring large block to JIT decompression, suitable for
                         // block preload/preparsed content
    };

    // The threshold is based on a trade off, maximize the number blocks with no decompression at replay
    // but minimizing the memory overhead of the non-deferred compressions.
    static constexpr size_t kSmallThreshold = 96 + sizeof(format::BlockHeader); // 83% of blocks, 26% of bytes

    using UncompressedStore = ParsedBlock::UncompressedStore;

    void SetFrameNumber(uint64_t frame_number) noexcept { frame_number_ = frame_number; }
    void SetBlockIndex(uint64_t block_index) noexcept { block_index_ = block_index; }

    [[nodiscard]] uint64_t GetFrameNumber() const noexcept { return frame_number_; }
    [[nodiscard]] uint64_t GetBlockIndex() const noexcept { return block_index_; }

    // Parse the block header and load a block buffer
    BlockReadError ReadBlockBuffer(FileInputStreamPtr& input_stream, BlockBuffer& block_buffer);

    // Define parsers for every block and sub-block type
    ParsedBlock ParseBlock(BlockBuffer& block_buffer);
    ParsedBlock ParseFunctionCall(BlockBuffer& block_buffer);
    ParsedBlock ParseMethodCall(BlockBuffer& block_buffer);
    ParsedBlock ParseMetaData(BlockBuffer& block_buffer);
    ParsedBlock ParseFrameMarker(BlockBuffer& block_buffer);
    ParsedBlock ParseStateMarker(BlockBuffer& block_buffer);
    ParsedBlock ParseAnnotation(BlockBuffer& block_buffer);

    void                           HandleBlockReadError(BlockReadError error_code, const char* error_message);
    ParsedBlock::UncompressedStore DecompressSpan(const BlockBuffer::BlockSpan& compressed_span, size_t expanded_size);

    using ErrorHandler = std::function<void(BlockReadError, const char*)>;
    BlockParser(const ErrorHandler& err, BufferPool& pool, util::Compressor* compressor) :
        pool_(pool), err_handler_(err), compressor_(compressor)
    {}

    void                SetDecompressionPolicy(DecompressionPolicy policy) { decompression_policy_ = policy; }
    DecompressionPolicy GetDecompressionPolicy() const { return decompression_policy_; }

    class DecompressionVisitor
    {
      public:
        template <typename Args>
        void Visit(ParsedBlock& parsed_block, Args& args)
        {
            // Shouldn't call this unless we know it's needed
            // Also, not safe if it isn't needed...
            GFXRECON_ASSERT(parsed_block.NeedsDecompression());
            if constexpr (DispatchTraits<Args>::kHasData)
            {
                auto compressed_span     = parsed_block.GetCompressedSpan(args);
                auto uncompressed_size   = ParsedBlock::GetUncompressedSize(args);
                auto uncompressed_buffer = parser_.DecompressSpan(compressed_span, uncompressed_size);
                // Patch the data buffer pointer, and shift ownership of the backing store to the parsed block
                args.data = uncompressed_buffer.template GetAs<const uint8_t>();
                parsed_block.UpdateUncompressedStore(std::move(uncompressed_buffer));
            }
        }
        DecompressionVisitor(BlockParser& parser) : parser_(parser) {}

      private:
        BlockParser& parser_;
    };

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
    bool                DecompressWhenParsed(const ParsedBlock& parsed_block);
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
