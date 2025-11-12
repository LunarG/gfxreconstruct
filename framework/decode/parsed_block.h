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

#ifndef GFXRECON_DECODE_PARSED_BLOCK_H
#define GFXRECON_DECODE_PARSED_BLOCK_H

#include "decode/api_payload.h"
#include "decode/block_buffer.h"
#include "util/span.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class BlockParser;

// -----------------------------------------------------------------------------
// ParsedBlock
//
// Purpose:
//   ParsedBlock owns a captured block (mapped or heap), plus optional
//   uncompressed data and decoded arguments.
//
//   The current form is intentionally verbose for prototype and implementation
//   of Parser/Processor logic but can be significantly reduced.
//
// Current status:
//   sizeof(ParsedBlock) ~ 136 B
//
// Oversized elements:
//   Uses util::DataSpan for ownership/view coupling (48 B).
//   UncompressedStore holds HeapBufferPool::Entry
//       (Entry = 24 B, includes embedded pool* 8 B).
//
// Improvement plan (target size ~ 104-112 B):
//   * Rewrite util::DataSpan as util::DataBuffer:
//       - DataBuffer wraps valid storage variants (mapped or heap).
//       - Removes data_/size_ shortcuts from DataSpan.
//       - data()/size() provided via visitor (slow path).
//       - Use make_span(buffer, off, len) for fast, non-owning access.
//       - Expected savings: ~16 B (on 64-bit).
//
//   * Refactor UncompressedStore:
//       - Perhap refactor Entry to hide pool as prefix to the allocation
//       - Perhaps hide HeapBuffer size as hidden prefix
//       - Expected saving: 8-16 B
//
//   * Keep DispatchArgs (56 B) for now:
//       - Size matches ~95% of blocks.
//       - 8-byte variant overhead simplifies anonymized usage.
// -----------------------------------------------------------------------------
class ParsedBlock
{
  public:
    enum BlockState
    {
        kInvalid = 0,        // Set on read error (typically block size doesn't match expected parsed size)
        kUnknown,            // Set when block is of an unknown type (no parsing done beyond header)
        kReady,              // Set when block is decompressed, or doesn't need to be
        kDeferredDecompress, // Set when block type is compressed, but decompression was suppressed
        kSkip,               // Set when block should be skipped
    };

    using PoolEntry         = util::HeapBufferPool::Entry; // Placeholder for buffer pool
    using UncompressedStore = PoolEntry;

    bool IsValid() const { return state_ != BlockState::kInvalid; }
    bool IsReady() const { return state_ == BlockState::kReady; }
    bool IsVisitable() const { return (state_ == BlockState::kReady) || (state_ == BlockState::kDeferredDecompress); }
    bool IsUnknown() const { return state_ == BlockState::kUnknown; }
    bool IsSkip() const { return state_ == BlockState::kSkip; }
    bool NeedsDecompression() const { return state_ == BlockState::kDeferredDecompress; }
    BlockState            GetState() const { return state_; }
    const util::DataSpan& GetBlockData() const { return block_data_; }
    const DispatchArgs&   GetArgs() const { return dispatch_args_; }
    explicit              operator bool() const { return IsValid(); }

    // Move only (has owning data)
    ParsedBlock(ParsedBlock&&) noexcept            = default;
    ParsedBlock& operator=(ParsedBlock&&) noexcept = default;

    // Copy verboten
    ParsedBlock(const ParsedBlock&)            = delete;
    ParsedBlock& operator=(const ParsedBlock&) = delete;

    // the EmptyBlockTag tag isn't really needed, we could just overload on BlockState, but I want to make this more
    // obvious.
    struct EmptyBlockTag
    {};
    ParsedBlock(const EmptyBlockTag&, BlockState reason) : block_data_(), uncompressed_store_(), state_(reason) {}

    // NOTE: need to ensure correct state is state vis-a-vis uncompressed store
    // This is called for compressed blocks to provide the backing store for the uncompress parameter block views
    // Needs update when deferred decompression is added
    template <typename ArgPayload>
    ParsedBlock(util::DataSpan&& block_data, ArgPayload&& args, UncompressedStore&& uncompressed_store) :
        block_data_(std::move(block_data)), uncompressed_store_(std::move(uncompressed_store)),
        dispatch_args_(MakeDispatchArgs(std::forward<ArgPayload>(args))), state_(BlockState::kReady)
    {}

    // This is called for for when blocks are parsed with deferred decompression
    template <typename ArgPayload>
    ParsedBlock(util::DataSpan&& block_data, ArgPayload&& args, bool is_compressed) :
        block_data_(std::move(block_data)), uncompressed_store_(),
        dispatch_args_(MakeDispatchArgs(std::forward<ArgPayload>(args))),
        state_(is_compressed ? BlockState::kDeferredDecompress : BlockState::kReady)
    {}

    void Decompress(BlockParser& parser);

  private:
    template <typename Args>
    BlockBuffer::BlockSpan GetCompressedSpan(Args& args);
    template <typename Args>
    static BlockBuffer::BlockSpan::size_type GetUncompressedSize(Args& args);
    void                                     UpdateUncompressedStore(UncompressedStore&& from_store);

    template <typename ArgPayload>
    static DispatchArgs MakeDispatchArgs(ArgPayload&& payload)
    {
        using Args     = util::RemoveCvRef_t<ArgPayload>;
        using ArgStore = DispatchStore<Args>;

        static_assert(util::IsVariantAlternative_v<ArgStore, DispatchArgs>,
                      "Invalid ArgPayload type, not storable in DispatchArgs");
        static_assert(std::is_constructible_v<Args, ArgPayload&&>,
                      "DispatchArgs alternative not constructible from supplied payload");

        return DispatchArgs(std::in_place_type<ArgStore>, std::forward<ArgPayload>(payload));
    }

    // The original contents of the read block (also backing store for uncompressed parameter views)
    util::DataSpan block_data_;

    // Backing store for the uncompressed parameter buffer, if needed.
    UncompressedStore uncompressed_store_;

    // Variant of all parsed results
    DispatchArgs dispatch_args_; // Variant with a type decoded block
    BlockState   state_ = BlockState::kInvalid;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PARSED_BLOCK_H
