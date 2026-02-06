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
#include "format/format_util.h"
#include "util/span.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class BlockParser;

// -----------------------------------------------------------------------------
// ParsedBlock
//
// Purpose:
//   ParsedBlock contains the results of parsing a BlockBuffer, including
//   pointers to the original data and decoded arguments, with all needed
//   memory owned by either the BlockBatch or the BlockParser.
// -----------------------------------------------------------------------------
class ParsedBlock
{
  public:
    using BlockSpan = util::Span<const uint8_t>;
    enum class BlockState : uint8_t
    {
        kInvalid = 0,        // Set on read error (typically block size doesn't match expected parsed size)
        kUnknown,            // Set when block is of an unknown type (no parsing done beyond header)
        kReady,              // Set when block is decompressed, or doesn't need to be
        kDeferredDecompress, // Set when block type is compressed, but decompression was suppressed
    };

    bool IsValid() const noexcept { return state_ != BlockState::kInvalid; }
    bool IsReady() const noexcept { return state_ == BlockState::kReady; }
    bool IsVisitable() const noexcept
    {
        return (state_ == BlockState::kReady) || (state_ == BlockState::kDeferredDecompress);
    }
    bool                  IsUnknown() const noexcept { return state_ == BlockState::kUnknown; }
    bool NeedsDecompression() const { return state_ == BlockState::kDeferredDecompress; }
    BlockState            GetState() const noexcept { return state_; }
    uint64_t              GetBlockIndex() const noexcept { return block_index_; }
    const uint8_t*        GetBlockData() const noexcept { return block_data_; }
    size_t                GetBlockSize() const noexcept;
    BlockSpan             GetBlockSpan() const noexcept;
    const DispatchArgs&   GetArgs() const noexcept { return dispatch_args_; }
    explicit              operator bool() const noexcept { return IsValid(); }

    // Accessors used by various ParsedBlock consumers
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
    template <typename Allocator>
    ParsedBlock(Allocator&, const InvalidBlockTag, uint64_t block_index) :
        block_index_(block_index), block_data_(), state_(BlockState::kInvalid)
    {}

    // Create an unparsed block, either because the block type is unknown, or that is known, but has no
    // matching Args struct
    struct UnknownBlockTag
    {};
    template <typename Allocator>
    ParsedBlock(Allocator&, const UnknownBlockTag, uint64_t block_index, const uint8_t* block_data) :
        block_index_(block_index), block_data_(block_data), state_(BlockState::kUnknown)
    {}

    template <typename Allocator, typename ArgPayload>
    ParsedBlock(Allocator&     allocator,
                BlockState     initial_state,
                uint64_t       block_index,
                const uint8_t* block_data,
                ArgPayload&&   args) :
        block_index_(block_index),
        block_data_(block_data), dispatch_args_(MakeDispatchArgs(std::forward<ArgPayload>(args), allocator)),
        state_(initial_state), is_trivial_(DispatchTraits<ArgPayload>::kIsTrivial)
    {}

    [[nodiscard]] bool Decompress(BlockParser& parser);

    ParsedBlock* GetNext() { return next_; }
    void         SetNext(ParsedBlock* next)
    {
        // If we want to allow insertion, need to save and return old next_,
        // but for now just assert it's null.
        GFXRECON_ASSERT(next_ == nullptr);
        next_ = next;
    }

    bool IsTriviallyDestructible() const noexcept { return is_trivial_; }

    bool IsFrameBoundary() const noexcept { return is_frame_boundary_; }

    void SetFrameBoundaryFlag(const bool frame_boundary) noexcept { is_frame_boundary_ = frame_boundary; }

  private:
    template <typename Args>
    BlockSpan GetCompressedSpan(Args& args);

    // Needed for replay index based block skipping
    uint64_t block_index_{ 0 };

    // The original contents of the read block (if retained)
    const uint8_t* block_data_;

    // Variant of all parsed results
    DispatchArgs dispatch_args_; // Variant with a type decoded block

    // Linked list next pointer for BlockBatch
    ParsedBlock* next_ = nullptr;

    BlockState   state_ = BlockState::kInvalid;
    bool         is_trivial_ : 1        = true;
    bool         is_frame_boundary_ : 1 = false;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PARSED_BLOCK_H
