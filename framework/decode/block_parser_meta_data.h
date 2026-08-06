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
// from the reserved MetaDataType range. BlockParser::ParseMetaData consults the table below for any
// meta-data type its built-in parsers do not recognize, and skips the block as unsupported only if
// no entry claims it -- so entries can never shadow a known block type.
//
// This build defines no extended types, so the table is empty and the lookup compiles away. A build
// that adds API families of its own supplies its parsers by placing its own copy of this header
// earlier on the include path of the gfxrecon_decode target; see the table in that copy for the
// types it handles.
// -----------------------------------------------------------------------------

#ifndef GFXRECON_DECODE_BLOCK_PARSER_META_DATA_H
#define GFXRECON_DECODE_BLOCK_PARSER_META_DATA_H

#include "format/format.h"
#include "util/defines.h"

#include <array>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class BlockBuffer;
class BlockParser;
class ParsedBlock;

// A parser is called with the block's MetaDataId and a BlockBuffer whose read position is
// immediately past that id -- the same state BlockParser's built-in parsers start from. It builds a
// block using the parser's parsing primitives (ReadParameterBuffer, Emplace,
// MakeCompressibleParsedBlock, ...) and returns it, or returns nullptr to decline the block, leaving
// it to the unsupported-block handling.
//
// The block a parser returns carries one of the payloads in DispatchArgs (api_payload.h).
// ExtendedMetaDataArgs is the payload meant for these types: it passes the block's parameter data
// through undecoded to ApiDecoder::DispatchExtendedMetaDataBlock on the decoder that claims the
// MetaDataId, so the parser here does not have to understand the payload -- only how to find it.
using ExtendedMetaDataParser = ParsedBlock* (*)(BlockParser&       parser,
                                                format::MetaDataId meta_data_id,
                                                BlockBuffer&       block_buffer);

struct ExtendedMetaDataEntry
{
    format::MetaDataType   meta_data_type;
    ExtendedMetaDataParser parse;
};

inline constexpr std::array<ExtendedMetaDataEntry, 0> kExtendedMetaDataParsers{};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_BLOCK_PARSER_META_DATA_H
