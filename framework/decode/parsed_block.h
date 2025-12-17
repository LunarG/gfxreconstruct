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

#include "format/format_util.h"
#include "decode/api_payload.h"
#include "decode/block_buffer.h"
#include "format/format_util.h"
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
    };

    // In order to minimize memory migration overhead for both preloaded and non-preloaded dispatch, we have three
    // modes of operation:
    //
    // kNonOwnedReference:
    //     For immediate dispatch of ParsedBlocks, unowned references are sufficient.
    //     NOTE: As the ParsedBlock's constructed under this policy may have pointers referring to the BlockBuffer
    //           contents, the ParsedBlock must not be retained or used after BlockBuffer reuse/reset/destruction.
    // kOwnedReferenceAsNeeded:
    //     For preloaded dispatch, we can minimize the retained memory by only owning references for blocks that are
    //     actually referenced during replay (either uncompressed, or deferred compressed)
    // kOwnedReference:
    //     For preloaded dispatch where raw block data is needed after parsing (for example to support re-compression)
    //     or Decoders/Consumers that want to access the raw block data.
    //
    enum BlockReferencePolicy
    {
        kNonOwnedReference,      // Store a "Borrowed" reference to the block data buffer
        kOwnedReferenceAsNeeded, // Store an owned reference as needed, or not at all
        kOwnedReference          // Always store an owned reference to the block data buffer
    };

    using PoolEntry         = util::HeapBufferPool::Entry; // Placeholder for buffer pool
    using UncompressedStore = PoolEntry;

    bool IsValid() const { return state_ != BlockState::kInvalid; }
    bool IsReady() const { return state_ == BlockState::kReady; }
    bool IsVisitable() const { return (state_ == BlockState::kReady) || (state_ == BlockState::kDeferredDecompress); }
    bool IsUnknown() const { return state_ == BlockState::kUnknown; }
    bool NeedsDecompression() const { return state_ == BlockState::kDeferredDecompress; }
    BlockState            GetState() const { return state_; }
    const util::DataSpan& GetBlockData() const { return block_data_; }
    const DispatchArgs&   GetArgs() const { return dispatch_args_; }
    explicit              operator bool() const { return IsValid(); }

    template <typename T>
    bool Holds() const
    {
        using Store = DispatchStore<T>;
        return std::holds_alternative<Store>(dispatch_args_);
    }

    template <typename T>
    const T& Get() const
    {
        using Store = DispatchStore<T>;
        GFXRECON_ASSERT(Holds<T>());
        return *(std::get<Store>(dispatch_args_));
    }

    template <typename T>
    T& Get()
    {
        using Store = DispatchStore<T>;
        GFXRECON_ASSERT(Holds<T>());
        return *(std::get<Store>(dispatch_args_));
    }

    // Move only (has owning data)
    ParsedBlock(ParsedBlock&&) noexcept            = default;
    ParsedBlock& operator=(ParsedBlock&&) noexcept = default;

    // Copy verboten
    ParsedBlock(const ParsedBlock&)            = delete;
    ParsedBlock& operator=(const ParsedBlock&) = delete;

    // The *BlockTag tags aren't really needed, we could just overload on BlockState or UncompressedStore, but I want to
    // make this more obvious.  The goal is to allow simple constructors covering all use cases to ensure RVO works
    // well.
    //
    // NOTE: Passing tags "by value" to avoid adding unnecessary references to the call stack, also consistent with STL
    //       tag argument usage

    // Create an empty block with no valid data
    struct InvalidBlockTag
    {};
    ParsedBlock(const InvalidBlockTag) : block_data_(), uncompressed_store_(), state_(BlockState::kInvalid) {}

    // Create an unparsed block, either because the block type is unknown, or that is known, but has no
    // matching Args struct
    struct UnknownBlockTag
    {};
    ParsedBlock(const UnknownBlockTag, util::DataSpan&& block_data) :
        block_data_(std::move(block_data)), uncompressed_store_(), state_(BlockState::kUnknown)
    {}

    //  Create a block that must not be compressed with asserts on tag construction
    struct IncompressibleBlockTag
    {
        IncompressibleBlockTag() = delete;
        IncompressibleBlockTag(const BlockBuffer& block_buffer)
        {
            GFXRECON_ASSERT(!format::IsBlockCompressed(block_buffer.Header().type));
        }
    };
    static util::DataSpan MakeIncompressibleBlockData(BlockBuffer&         block_buffer,
                                                      BlockReferencePolicy policy,
                                                      bool                 references_block_buffer) noexcept;
    template <typename ArgPayload>
    ParsedBlock(IncompressibleBlockTag,
                BlockBuffer&         block_buffer,
                BlockReferencePolicy policy,
                bool                 references_block_buffer,
                ArgPayload&&         args) :
        block_data_(MakeIncompressibleBlockData(block_buffer, policy, references_block_buffer)),
        uncompressed_store_(), dispatch_args_(MakeDispatchArgs(std::forward<ArgPayload>(args))), state_(kReady)
    {}

    // Create a non-compressed block of a compressible block base type
    // TODO: Is there a clean way to static assert that a block *type* is compressible here?
    struct UncompressedBlockTag
    {};
    static util::DataSpan MakeUncompressedBlockData(BlockBuffer& block_buffer, BlockReferencePolicy policy) noexcept;
    template <typename ArgPayload>
    ParsedBlock(UncompressedBlockTag, BlockBuffer& block_buffer, BlockReferencePolicy policy, ArgPayload&& args) :
        block_data_(MakeUncompressedBlockData(block_buffer, policy)), uncompressed_store_(),
        dispatch_args_(MakeDispatchArgs(std::forward<ArgPayload>(args))), state_(kReady)
    {}

    // Create a block that has been decompressed on construction
    struct DecompressedBlockTag
    {};
    static util::DataSpan MakeDecompressedBlockData(BlockBuffer& block_buffer, BlockReferencePolicy policy) noexcept;
    template <typename ArgPayload>
    ParsedBlock(DecompressedBlockTag,
                BlockBuffer&         block_buffer,
                BlockReferencePolicy policy,
                UncompressedStore&&  uncompressed_store,
                ArgPayload&&         args) :
        block_data_(MakeDecompressedBlockData(block_buffer, policy)),
        uncompressed_store_(std::move(uncompressed_store)),
        dispatch_args_(MakeDispatchArgs(std::forward<ArgPayload>(args))), state_(kReady)
    {}

    // Created a block with deferred decompression
    struct DeferredDecompressBlockTag
    {};
    static util::DataSpan MakeDeferredDecompressBlockData(BlockBuffer&         block_buffer,
                                                          BlockReferencePolicy policy) noexcept;
    template <typename ArgPayload>
    ParsedBlock(DeferredDecompressBlockTag, BlockBuffer& block_buffer, BlockReferencePolicy policy, ArgPayload&& args) :
        block_data_(MakeDeferredDecompressBlockData(block_buffer, policy)), uncompressed_store_(),
        dispatch_args_(MakeDispatchArgs(std::forward<ArgPayload>(args))), state_(kDeferredDecompress)
    {}

    [[nodiscard]] bool Decompress(BlockParser& parser);

  private:
    template <typename Args>
    BlockBuffer::BlockSpan GetCompressedSpan(Args& args);
    void                   UpdateUncompressedStore(UncompressedStore&& from_store);

    template <typename ArgPayload>
    void TouchUpArgsData()
    {
        using Args = std::decay_t<ArgPayload>;
        static_assert(DispatchTraits<Args>::kHasData);
        // Get is valid on empty (returns nullptr)
        Get<Args>().data = uncompressed_store_.template GetAs<const uint8_t>();
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
