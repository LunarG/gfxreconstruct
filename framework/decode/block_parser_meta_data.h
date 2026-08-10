/*
** Copyright (c) 2026 LunarG, Inc.
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

// -----------------------------------------------------------------------------
// Extended meta-data block types
//
// An API family may define meta-data blocks whose layout BlockParser does not know, using values
// from the reserved MetaDataType range. BlockParser::ParseMetaData calls ParseExtendedMetaData below
// for any meta-data type its built-in parsers do not recognize, and skips the block as unsupported
// only if that call declines it -- so an extended parser can never shadow a known block type.
//
// How the lookup is performed is entirely this header's business; BlockParser knows only the one
// function. This build defines no extended types, so the implementation is a constant nullptr and
// the call compiles away. A build that adds API families of its own supplies its parsers by placing
// its own copy of this header earlier on the include path of the gfxrecon_decode target, and is free
// to dispatch however suits the number of types it handles.
// -----------------------------------------------------------------------------

#ifndef GFXRECON_DECODE_BLOCK_PARSER_META_DATA_H
#define GFXRECON_DECODE_BLOCK_PARSER_META_DATA_H

#include "decode/block_parser.h"
#include "format/format.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Parses a meta-data block whose type none of BlockParser's built-in parsers recognize.
//
// block_buffer's read position is immediately past the MetaDataId -- the same state the built-in
// parsers start from. An implementation builds its block using parser_interface, which is the only
// access it has to the parser; see ExtendedParseInterface for the available primitives and, in
// particular, for the threading contract governing what a parser may touch and where it may
// allocate.
//
// The block an implementation returns carries one of the payloads in DispatchArgs (api_payload.h).
// ExtendedMetaDataArgs is the payload meant for these types: it passes the block's parameter data
// through undecoded to ApiDecoder::DispatchExtendedMetaDataBlock on the decoder that claims the
// MetaDataId, so the parser here does not have to understand the payload -- only how to find it.
//
// Returns the parsed block, or nullptr to decline -- because no parser handles meta_data_type, or
// because the one that does could not parse this block. The caller then applies its usual
// unsupported-block handling, which works from the start of the block rather than from the read
// position, so declining part-way through a block is safe. Declining without having consumed
// anything is still the clearer contract to write to.
//
// **NOTE about Threading**: the BlockParser runs on the block-processing thread. In async mode
// that thread is AsyncProcessor::ThreadMain, which is *not* the thread that dispatches the
// resulting ParsedBlocks -- batches cross to the dispatch thread through the AsyncProcessor batch
// queue.
// An extended parser therefore must:
//   * Allocate only through this interface. Emplace/EmplaceBlock place data in the current
//     BlockBatch, which is what is handed to the dispatch thread; anything allocated elsewhere
//     has no defined lifetime on the far side.
//   * Not touch decoder, consumer, or replay state. None of it is owned by this thread. In
//     particular, the payload a parser builds is interpreted later, on the dispatch thread, by
//     the decoder that claims its MetaDataId.
//   * Not retain pointers into the parser's decompression scratch buffer, which is reused by the
//     next block. Payloads that reference block data must go through
//     MakeCompressibleParsedBlock/MakeIncompressibleParsedBlock, which handle retention
//     according to the current OperationMode.
inline ParsedBlock* ParseExtendedMetaData(ExtendedParseInterface& /* parser_interface */,
                                          format::MetaDataType /* meta_data_type */,
                                          format::MetaDataId /* meta_data_id */,
                                          BlockBuffer& /* block_buffer */)
{
    // This build defines no extended meta-data types.
    return nullptr;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_BLOCK_PARSER_META_DATA_H
