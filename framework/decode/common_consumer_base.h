/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_COMMONCONSUMER_BASE_H
#define GFXRECON_DECODE_COMMONCONSUMER_BASE_H

#include "decode/metadata_consumer_base.h"
#include "decode/marker_consumer_base.h"
#include "decode/api_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "util/defines.h"

#include <numeric>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class CommonConsumerBase : public MetadataConsumerBase, public MarkerConsumerBase
{
  public:
    CommonConsumerBase() {}

    virtual ~CommonConsumerBase() {}

    virtual void WaitDevicesIdle() {}

    virtual bool IsComplete(uint64_t block_index) { return false; }

    virtual void Process_ExeFileInfo(util::filepath::FileInfo& info_record) {}

    virtual void SetCurrentBlockIndex(uint64_t block_index) override { block_index_ = block_index; }
};

/* Utility */
template <typename IT, typename CONVERTER>
std::string toStringJoin(IT first, IT last, CONVERTER toStringMethod, const std::string separator)
{
    if (first == last)
    {
        return "";
    }

    std::string start = toStringMethod(*first);
    first++;

    return std::accumulate(
        first, last, start, [&](std::string prev, typename std::iterator_traits<IT>::value_type current) {
            return prev + separator + toStringMethod(current);
        });
}

template <typename T1, typename T2>
class PointerPairContainer
{
  public:
    /* Support pointer pairs for now */
    static_assert(std::is_pointer<T1>::value, "T1 of pair must be a pointer");
    static_assert(std::is_pointer<T2>::value, "T2 of pair must be a pointer");

    struct PointerPair
    {
        T1 t1;
        T2 t2;
        PointerPair(T1 t1, T2 t2) : t1(t1), t2(t2) {}
    };

    class PointerPairIterator
    {
      public:
        using iterator_category = std::input_iterator_tag;
        using value_type        = PointerPair;
        using difference_type   = PointerPair;
        using pointer           = PointerPair*;
        using reference         = PointerPair&;

        PointerPairIterator(T1 t1, T2 t2) : t1(t1), t2(t2) {}

        PointerPairIterator& operator++()
        {
            ++t1;
            ++t2;
            return *this;
        }

        PointerPairIterator operator++(int)
        {
            PointerPairIterator current(t1, t2);
            ++t1;
            ++t2;
            return current;
        }

        bool operator==(const PointerPairIterator& rhs) const { return (t1 == rhs.t1) && (t2 == rhs.t2); }

        bool operator!=(const PointerPairIterator& rhs) const { return (t1 != rhs.t1) || (t2 != rhs.t2); }

        PointerPair operator*() { return PointerPair(t1, t2); }

      private:
        T1 t1;
        T2 t2;
    };

    PointerPairContainer(T1 t1, T2 t2, size_t count) : m_t1(t1), m_t2(t2), m_count(count) {}

    PointerPairIterator begin(void) const { return PointerPairIterator(m_t1, m_t2); }
    PointerPairIterator end(void) const { return PointerPairIterator(m_t1 + m_count, m_t2 + m_count); }

  private:
    T1     m_t1;
    T2     m_t2;
    size_t m_count;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_COMMONCONSUMER_BASE_H
