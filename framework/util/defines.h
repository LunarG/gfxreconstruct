/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include <cassert>
#include <cstdint>
#include <limits>

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

// Determine if a type conversion would result in a loss of data.  Intended to check uint64_t to size_t conversions.
#define GFXRECON_CHECK_CONVERSION_DATA_LOSS(DstType, Value) assert(std::numeric_limits<DstType>::max() >= Value);

#endif // GFXRECON_UTIL_DEFINES_H
