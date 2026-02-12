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

#include "decode/block_parser.h"
#include "decode/parsed_block.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename Args>
BlockBuffer::BlockSpan ParsedBlock::GetCompressedSpan(Args& args)
{
    if constexpr (DispatchTraits<Args>::kHasData)
    {
        // The data field for a deferred decompresion points to the start of the compressed block
        GFXRECON_ASSERT(state_ == kDeferredDecompress);
        GFXRECON_ASSERT(!block_data_.empty());
        // Assure that the data pointer is within block_data span (part 1)
        GFXRECON_ASSERT(args.data >= block_data_.GetDataAs<uint8_t>());
        const size_t offset = args.data - block_data_.GetDataAs<uint8_t>();

        // Assure that the data pointer is within block_data span (part 2)
        GFXRECON_ASSERT(offset <= block_data_.size());
        return block_data_.AsSpan(offset);
    }
    return BlockBuffer::BlockSpan();
}

bool ParsedBlock::Decompress(BlockParser& parser)
{
    // Shouldn't call this unless we know it's needed
    // Also, not safe if it isn't needed...
    if (!NeedsDecompression())
    {
        return IsReady();
    }

    auto decompress = [this, &parser](auto&& args_store) {
        auto& args = *args_store;
        using Args = std::decay_t<decltype(args)>;
        if constexpr (DispatchTraits<Args>::kHasData)
        {
            auto              compressed_span    = GetCompressedSpan(args);
            auto              uncompressed_size  = GetDispatchArgsDataSize(args);
            UncompressedStore uncompressed_store = parser.DecompressSpan(compressed_span, uncompressed_size);
            if (!uncompressed_store.empty())
            {
                // Patch the data buffer pointer, and shift ownership of the backing store to the parsed block
                args.data = uncompressed_store.template GetAs<const uint8_t>();
                UpdateUncompressedStore(std::move(uncompressed_store));
            }
        }
    };

    std::visit(decompress, dispatch_args_);
    return IsReady();
}

void ParsedBlock::UpdateUncompressedStore(UncompressedStore&& from_store)
{
    GFXRECON_ASSERT(state_ == kDeferredDecompress);
    state_              = kReady;
    uncompressed_store_ = std::move(from_store);
}

util::DataSpan ParsedBlock::MakeIncompressibleBlockData(BlockBuffer&         block_buffer,
                                                        BlockReferencePolicy policy,
                                                        bool                 references_block_buffer) noexcept
{
    if ((policy == ParsedBlock::kOwnedReference) ||
        ((policy == ParsedBlock::kOwnedReferenceAsNeeded) && references_block_buffer))
    {
        // Use case:
        //     Preload replay of incompressible blocks that reference the raw block data as the *Arg::data parameter
        //     buffer
        return block_buffer.ReleaseData();
    }

    // Use case:
    //     Immediate dispatch or usage within the life span of the block buffer
    return block_buffer.MakeNonOwnedData();
}

util::DataSpan ParsedBlock::MakeUncompressedBlockData(BlockBuffer& block_buffer, BlockReferencePolicy policy) noexcept
{
    if ((policy == ParsedBlock::kOwnedReference) || (policy == ParsedBlock::kOwnedReferenceAsNeeded))
    {
        // Use case:
        //     Preload replay noncompressed blocks that reference the raw block data as the *Arg::data parameter buffer
        return block_buffer.ReleaseData();
    }

    // Use case:
    //     Immediate dispatch or usage within the life span of the block buffer
    return block_buffer.MakeNonOwnedData();
}

util::DataSpan ParsedBlock::MakeDecompressedBlockData(BlockBuffer& block_buffer, BlockReferencePolicy policy) noexcept
{
    if (policy == kOwnedReference)
    {
        // Use case:
        //    If decoders/consumer that require block data exist during Preload replay
        return block_buffer.ReleaseData();
    }
    else if (policy == kNonOwnedReference)
    {
        // Use case:
        //    For immediate dispatch with raw block consuming decoder/consumers or
        return block_buffer.MakeNonOwnedData();
    }

    // Use case:
    //    Preload replay without raw block consuming decoder/consumers (likely/performance mode of
    //    operation) NOTE: it is invalid to access the raw block data in this use case
    return util::DataSpan();
}

util::DataSpan ParsedBlock::MakeDeferredDecompressBlockData(BlockBuffer&         block_buffer,
                                                            BlockReferencePolicy policy) noexcept
{
    if (policy == kNonOwnedReference)
    {
        // Use case:
        //     FileTransformer does deferred decompression within the lifespan of the block_buffer
        return block_buffer.MakeNonOwnedData();
    }

    // Use case:
    //     Preload replay deferred decompression is long after the block_buffer has be reused or destructed
    return block_buffer.ReleaseData();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
