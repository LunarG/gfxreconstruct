/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include <cassert>
#include <cstdint>
#include <limits>
#include <utility>
#include <type_traits>

#ifndef GFXRECON_UTIL_DEFINES_H
#define GFXRECON_UTIL_DEFINES_H

#if defined(_WIN64) || defined(__LP64__)
#define GFXRECON_ARCH64
#endif

#define GFXRECON_BEGIN_NAMESPACE(x) \
    namespace x                     \
    {
#define GFXRECON_END_NAMESPACE(x) }

#define GFXRECON_UNREFERENCED_PARAMETER(x) ((void)x)

// Use two macros for the x is a macro case, to ensure macro expansion is applied to x prior to string conversion.
#define GFXRECON_STR_EXPAND(x) #x
#define GFXRECON_STR(x) GFXRECON_STR_EXPAND(x)

#define GFXRECON_MAKE_FOURCC(c0, c1, c2, c3)                                                            \
    (static_cast<uint32_t>(c0) | (static_cast<uint32_t>(c1) << 8) | (static_cast<uint32_t>(c2) << 16) | \
     (static_cast<uint32_t>(c3) << 24))

//  CONVERSION_DATA_LOSS needs this so it can't be in an include, but I can match the include where it *would* be
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
template <typename To, typename From>
struct IsSafeIntegralAssign
{
    using Source = std::remove_cvref_t<From>;
    using Dest   = std::remove_cvref_t<To>;
    static_assert(std::is_integral_v<Source> && std::is_integral_v<Dest>);

    static constexpr bool value =
        std::cmp_less_equal(std::numeric_limits<Dest>::min(), std::numeric_limits<Source>::min()) &&
        std::cmp_less_equal(std::numeric_limits<Source>::max(), std::numeric_limits<Dest>::max());
};

template <typename T, typename U>
inline constexpr bool IsSafeIntegralAssign_v = IsSafeIntegralAssign<T, U>::value;

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#ifdef NDEBUG
#define GFXRECON_CHECK_CONVERSION_DATA_LOSS(DestType, Value) ((void)0)
#define GFXRECON_NARROWING_CAST(Type, Value) static_cast<Type>(Value)
#define GFXRECON_NARROWING_ASSIGN(Dest, Value) (Dest) = static_cast<std::remove_cvref_t<decltype(Dest)>>(Value)
#else
// Determine if a type conversion would result in a loss of data.  Intended to check uint64_t to size_t conversions.
#define GFXRECON_CHECK_CONVERSION_DATA_LOSS(DestType, Value)                            \
    do                                                                                  \
    {                                                                                   \
        using ValueType = std::remove_cvref_t<decltype(Value)>;                         \
        if constexpr (!gfxrecon::util::IsSafeIntegralAssign_v<DestType, ValueType>)     \
        {                                                                               \
            assert(std::cmp_less_equal(std::numeric_limits<DestType>::min(), (Value))); \
            assert(std::cmp_less_equal((Value), std::numeric_limits<DestType>::max())); \
        }                                                                               \
    } while (0)

#define GFXRECON_NARROWING_CAST(Type, Value)                                                                     \
    (gfxrecon::util::IsSafeIntegralAssign_v<Type, decltype(Value)> ? static_cast<Type>(Value) : ([&]() -> Type { \
        auto _value = (Value);                                                                                   \
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(Type, _value);                                                       \
        return static_cast<Type>(_value);                                                                        \
    })())

#define GFXRECON_NARROWING_ASSIGN(Dest, Value) \
    (Dest) = GFXRECON_NARROWING_CAST(std::remove_cvref_t<decltype(Dest)>, (Value))

#endif // NDEBUG

// Safely release a dynamic allocation.
#define GFXRECON_SAFE_DELETE(p)    \
    {                     \
        if (p != nullptr) \
        {                 \
            delete p;     \
            p = nullptr;  \
        }                 \
    }

// Useful to avoid sign extension when converting a 32bit pointer to uint64_t
template <typename T>
static constexpr uint64_t GFXRECON_PTR_TO_UINT64(T ptr)
{
    return static_cast<uint64_t>(reinterpret_cast<uintptr_t>(ptr));
}

#ifdef NDEBUG
#define GFXRECON_RELEASE_BUILD 1
#else
#define GFXRECON_DEBUG_BUILD 1
#endif

#if defined(__GNUC__) && __GNUC__ >= 4
#define GFXR_EXPORT __attribute__((visibility("default")))
#else
#define GFXR_EXPORT
#endif

#endif // GFXRECON_UTIL_DEFINES_H
