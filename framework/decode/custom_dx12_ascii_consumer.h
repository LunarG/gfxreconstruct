/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_CUSTOM_DX12_ASCII_CONSUMER_H
#define GFXRECON_CUSTOM_DX12_ASCII_CONSUMER_H

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "generated/generated_dx12_struct_decoders.h"
#include "generated/generated_dx12_struct_to_string.h"
#include "generated/generated_dx12_enum_to_string.h"
#include "util/defines.h"
#include "util/to_string.h"
#include "custom_dx12_to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

inline std::string HandleIdToString(format::HandleId handleId)
{
    std::stringstream strStrm;
    if (handleId)
    {
        strStrm << "\"0x" << reinterpret_cast<const void*>(handleId) << "\"";
    }
    else
    {
        strStrm << "\"NULL\"";
    }
    return strStrm.str();
}

template <typename DX12ReturnType>
inline std::string DX12ReturnValueToString(const DX12ReturnType& return_value, util::ToStringFlags to_string_flags, uint32_t tab_count, uint32_t tab_size)
{
    return "TODO : return_value";
}

template <typename PointerDecoderType>
inline std::string PointerDecoderToString(PointerDecoderType* pObj,
                                          util::ToStringFlags toStringFlags = util::kToString_Default,
                                          uint32_t            tabCount      = 0,
                                          uint32_t            tabSize       = 4)
{
    auto pDecodedObj = pObj ? pObj->GetPointer() : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

template <typename CountType>
inline uint32_t GetCount(CountType countObj)
{
    return static_cast<uint32_t>(countObj);
}

template <>
inline uint32_t GetCount<PointerDecoder<UINT>*>(PointerDecoder<UINT>* pCountObj)
{
    auto pDecodedCountObj = pCountObj ? pCountObj->GetPointer() : nullptr;
    return pDecodedCountObj ? *pDecodedCountObj : 0;
}

template <typename CountType, typename PointerDecoderType>
inline std::string PointerDecoderArrayToString(const CountType&    countObj,
                                               PointerDecoderType* pObjs,
                                               util::ToStringFlags toStringFlags = util::kToString_Default,
                                               uint32_t            tabCount      = 0,
                                               uint32_t            tabSize       = 4)
{
    using namespace util;
    return ArrayToString(
        GetCount(countObj),
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs && !pObjs->IsNull(); },
        [&](uint32_t i) { return ToString(pObjs->GetPointer()[i], toStringFlags, tabCount + 1, tabSize); });
}

template <typename CountType, typename PointerDecoderType>
inline std::string EnumPointerDecoderArrayToString(const CountType&    countObj,
                                                   PointerDecoderType* pObjs,
                                                   util::ToStringFlags toStringFlags = util::kToString_Default,
                                                   uint32_t            tabCount      = 0,
                                                   uint32_t            tabSize       = 4)
{
    using namespace util;
    return ArrayToString(
        GetCount(countObj),
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs && !pObjs->IsNull(); },
        [&](uint32_t i) { return '"' + ToString(pObjs->GetPointer()[i], toStringFlags, tabCount + 1, tabSize) + '"'; });
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CUSTOM_DX12_ASCII_CONSUMER_H
