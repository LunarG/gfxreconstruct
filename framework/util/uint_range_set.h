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

#ifndef GFXRECON_UTIL_UINT_RANGE_SET_H
#define GFXRECON_UTIL_UINT_RANGE_SET_H

#include "util/defines.h"
#include "util/options.h"

#include <algorithm>
#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Compact set of inclusive uint32_t ranges, merged across overlaps and adjacent endpoints.
class UintRangeSet
{
  public:
    void SetRanges(std::vector<UintRange> ranges)
    {
        std::sort(ranges.begin(), ranges.end(), [](const auto& a, const auto& b) { return a.first < b.first; });
        ranges_.clear();
        for (const auto& range : ranges)
        {
            if (range.first > range.last)
            {
                continue;
            }
            if (!ranges_.empty() &&
                static_cast<uint64_t>(range.first) <= static_cast<uint64_t>(ranges_.back().last) + 1)
            {
                ranges_.back().last = std::max(ranges_.back().last, range.last);
            }
            else
            {
                ranges_.push_back(range);
            }
        }
    }

    bool Contains(uint64_t value) const
    {
        const auto range =
            std::lower_bound(ranges_.begin(), ranges_.end(), value, [](const auto& range, uint64_t index) {
                return range.last < index;
            });
        return (range != ranges_.end()) && (range->first <= value);
    }

  private:
    std::vector<UintRange> ranges_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_UINT_RANGE_SET_H
