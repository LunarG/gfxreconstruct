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
ParsedBlock::BlockSpan ParsedBlock::GetCompressedSpan(Args& args)
{
    if constexpr (DispatchTraits<Args>::kHasData)
    {
        // The data field for a deferred decompresion points to the start of the compressed block
        GFXRECON_ASSERT(state_ == BlockState::kDeferredDecompress);
        GFXRECON_ASSERT(block_data_ != nullptr);
        const size_t block_size = GetBlockSize();
        const size_t offset     = args.data - block_data_;

        // Assure that the compressed data pointer is within block_data span
        GFXRECON_ASSERT(args.data >= block_data_);
        GFXRECON_ASSERT(offset <= block_size);

        uint64_t compressed_size = block_size - offset;

        return BlockSpan(block_data_ + offset, compressed_size);
    }
    return BlockSpan();
}

size_t ParsedBlock::GetBlockSize() const noexcept
{
    size_t block_size = 0;
    if (block_data_ != nullptr)
    {
        // The block size is stored in the first 8 bytes of the block data
        // NOTE: The conversion to size_t is safe, as it was validated when the block was read
        // NOTE: This assumes std::max_align_t allignment for the block data buffer (which is true)
        // NOTE: If the header is ever redefined to encode the size differently, this will need to be updated
        uint64_t block_size_from_header = *reinterpret_cast<const uint64_t*>(block_data_);
        block_size                      = static_cast<size_t>(block_size_from_header) + sizeof(format::BlockHeader);
    }
    return block_size;
}

ParsedBlock::BlockSpan ParsedBlock::GetBlockSpan() const noexcept
{
    size_t size = GetBlockSize();
    return { block_data_, size };
}

bool ParsedBlock::Decompress(BlockParser& parser, util::HeapBuffer& working_store)
{
    // Shouldn't call this unless we know it's needed
    // Also, not safe if it isn't needed...
    if (!NeedsDecompression())
    {
        return IsReady();
    }

    auto decompress = [this, &parser, &working_store](auto&& args_store) {
        if constexpr (std::is_same_v<std::decay_t<decltype(args_store)>, std::monostate>)
        {
            parser.HandleBlockReadError(kErrorReadingCompressedBlockData,
                                        "Block is invalid or unknown, but is marked as needing decompression");
            GFXRECON_ASSERT(false && "Cannot decompress a block with no DispatchArgs");
            // We tried to compress an unknown or invalid block that was in kDeferredDecompress state, which shouldn't
            // be possible.
            state_ = BlockState::kInvalid;
        }
        else
        {
            auto& args = *args_store;
            using Args = std::decay_t<decltype(args)>;
            if constexpr (DispatchTraits<Args>::kHasData)
            {
                auto compressed_span   = GetCompressedSpan(args);
                auto uncompressed_size = GetDispatchArgsDataSize(args);
                working_store.ReserveDiscarding(uncompressed_size);
                auto uncompressed_store =
                    parser.DecompressSpan(compressed_span, uncompressed_size, working_store.get());
                if (uncompressed_store != nullptr)
                {
                    // Patch the data buffer pointer, and shift ownership of the backing store to the parsed block
                    args.data = uncompressed_store;
                    state_    = BlockState::kReady;
                }
            }
        }
    };

    std::visit(decompress, dispatch_args_);
    return IsReady();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
