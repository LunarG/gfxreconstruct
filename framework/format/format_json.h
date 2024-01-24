/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2023 LunarG, Inc.
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
/// @file Definitions used by the JSON representation of the capture file format.

#ifndef GFXRECON_FORMAT_FORMAT_JSON_H
#define GFXRECON_FORMAT_FORMAT_JSON_H
#include "format.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(format)

/// @defgroup JSONFieldNames The names of fields used in the top-level structure
/// of the JSON representation of capture files
/// @{
constexpr const char* kNameMeta{ "meta" };
constexpr const char* kNameState{ "state" };
constexpr const char* kNameFrame{ "frame" };
constexpr const char* kNameFunction{ "function" };
constexpr const char* kNameMethod{ "method" };
constexpr const char* kNameObject{ "object" };
constexpr const char* kNameObjectType{ "type" };
constexpr const char* kNameObjectHandle{ "handle" };
constexpr const char* kNameName{ "name" };
constexpr const char* kNameIndex{ "index" };
constexpr const char* kNameThread{ "thread" };
constexpr const char* kNameReturn{ "return" };
constexpr const char* kNameArgs{ "args" };
constexpr const char* kNameData{ "data" };
/// @}

constexpr const char* kValBinary{ "[Binary data]" };
constexpr const char* kValWriteFailed{ "[Unable to write file]" };

/// @defgroup JSONMetaNames The names of fields used to convey out of band information like warnings and errors
/// generated during conversion but not present in binary file.
/// @{
constexpr const char* kNameDebug{ "DEBUG" };
constexpr const char* kNameInfo{ "INFO" };
constexpr const char* kNameWarning{ "WARNING" };
constexpr const char* kNameError{ "ERROR" };
/// @}

/// The thread ID to use when the thread ID is not known.
constexpr format::ThreadId kNameUnknownThreadId{ gfxrecon::format::ThreadId(-1) };

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FORMAT_FORMAT_JSON_H
