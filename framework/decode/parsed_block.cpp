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

template <typename Args>
BlockBuffer::BlockSpan::size_type ParsedBlock::GetUncompressedSize(Args& args)
{
    if constexpr (DispatchTraits<Args>::kHasDataSize)
    {
        return args.data_size;
    }
    else if constexpr (DispatchTraits<Args>::kHasCommandHeader)
    {
        return args.command_header.data_size;
    }
    return 0;
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
            auto compressed_span     = GetCompressedSpan(args);
            auto uncompressed_size   = GetUncompressedSize(args);
            auto result              = parser.DecompressSpan(compressed_span, uncompressed_size);
            if (result.success)
            {
                // Patch the data buffer pointer, and shift ownership of the backing store to the parsed block
                args.data = result.decompressed_store.template GetAs<const uint8_t>();
                UpdateUncompressedStore(std::move(result.decompressed_store));
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
