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

#ifndef GFXRECON_UTIL_TYPE_TRAITS_EXTRAS_H
#define GFXRECON_UTIL_TYPE_TRAITS_EXTRAS_H

#include <cstddef>
#include <type_traits>
#include <variant>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Metaprogramming utilities
// remove_cvref is C++ 20 and later
template <typename T>
using RemoveCvRef_t = std::remove_cv_t<std::remove_reference_t<T>>;

template <typename T, typename... Types>
struct ExactTypeMatchesAny : std::bool_constant<(std::is_same_v<T, Types> || ...)>
{};

template <typename T, typename... Types>
inline constexpr bool ExactTypeMatchesAny_v = ExactTypeMatchesAny<T, Types...>::value;

template <typename T, typename... Types>
struct RemoveCvRefTypeMatchesAny : std::bool_constant<(std::is_same_v<RemoveCvRef_t<T>, RemoveCvRef_t<Types>> || ...)>
{};

// Primary template.
// Will result in compile error if the partial specialization fails on non-variant type
template <typename T, typename Variant>
struct IsVariantAlternative;

// Uses a fold expression to OR together whether
template <typename T, typename... Alternatives>
struct IsVariantAlternative<T, std::variant<Alternatives...>> : RemoveCvRefTypeMatchesAny<T, Alternatives...>
{};

template <typename T, typename Variant>
inline constexpr bool IsVariantAlternative_v = IsVariantAlternative<T, RemoveCvRef_t<Variant>>::value;

// NOTE: int8_t and uint8_t aren't on this list as that is not fully portable.  However for all platforms where they are
// byte equivalent
//       we'll define a ::value of true.
template <typename T>
struct IsByteEquivalent : ExactTypeMatchesAny<std::remove_cv_t<T>, std::byte, char, signed char, unsigned char>
{};
template <typename T>
inline constexpr bool IsByteEquivalent_v = IsByteEquivalent<T>::value;

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_TYPE_TRAITS_EXTRAS_H
