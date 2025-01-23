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

#ifndef GFXRECON_UTIL_ALIGNED_VALUE_H
#define GFXRECON_UTIL_ALIGNED_VALUE_H

#include "util/defines.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

/**
 * @brief   is_pow_2 can be used to determine if value is a power-of-two.
 *
 * @param   v   an integer-value
 * @return  true, if provided value is a power-of-two.
 */
inline constexpr bool is_pow_2(uint64_t value)
{
    return !(value & (value - 1));
}

/**
 * @brief   next_pow_2 will return the next power of two, following a provided value.
 *          it will return value, if that was already a power-of-two.
 *
 * @param   v   provided integer-value
 * @return  v, if that already was a power-of-two, otherwise the next power-of-two following it.
 */
inline constexpr uint64_t next_pow_2(uint64_t v)
{
    if (is_pow_2(v))
    {
        return v;
    }
    v--;
    v |= v >> 1U;
    v |= v >> 2U;
    v |= v >> 4U;
    v |= v >> 8U;
    v |= v >> 16U;
    v |= v >> 32U;
    v++;
    return v;
}

/**
 * @brief   Return a value, equal or larger to a provided value, which is aligned to a provided alignment.
 *
 * @param   value       provided integer-value
 * @param   alignment   provided alignment, needs to be a power-of-two
 * @return  an aligned value.
 */
inline constexpr uint64_t aligned_value(uint64_t value, uint64_t alignment)
{
    GFXRECON_ASSERT(is_pow_2(alignment));
    return alignment ? (value + alignment - 1) & ~(alignment - 1) : value;
}

/**
 * @brief   Perform an integer-division, round up to the next value.
 *
 * @param   nom     provided nominator
 * @param   denom   provided denominator
 * @return  result of integer-division, rounded to next value.
 */
inline constexpr uint32_t div_up(uint32_t nom, uint32_t denom)
{
    GFXRECON_ASSERT(denom > 0);
    return (nom + denom - 1) / denom;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // #define GFXRECON_UTIL_ALIGNED_VALUE_H
