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

#ifndef GFXRECON_URIL_COMPILER_DIAGNOSTICS_H
#define GFXRECON_URIL_COMPILER_DIAGNOSTICS_H

#if defined(__clang__)
#define GFXRECON_BEGIN_SUPPRESS_APPLE_SDK_WARNINGS                                                     \
    _Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"") \
        _Pragma("clang diagnostic ignored \"-Welaborated-enum-base\"")                                 \
            _Pragma("clang diagnostic ignored \"-Wdeprecated-anon-enum-enum-conversion\"")             \
                _Pragma("clang diagnostic ignored \"-Wdeprecated-enum-enum-conversion\"")              \
                    _Pragma("clang diagnostic ignored \"-Wavailability\"")
#else
#define GFXRECON_BEGIN_SUPPRESS_APPLE_SDK_WARNINGS
#endif

#ifdef __clang__
#define GFXRECON_END_SUPPRESS_APPLE_SDK_WARNINGS _Pragma("clang diagnostic pop")
#else
#define GFXRECON_END_SUPPRESS_APPLE_SDK_WARNINGS
#endif

#endif // GFXRECON_URIL_COMPILER_DIAGNOSTICS_H
