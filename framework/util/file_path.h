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

#ifndef GFXRECON_UTIL_FILE_PATH_H
#define GFXRECON_UTIL_FILE_PATH_H

#include "util/defines.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(filepath)

#if defined(WIN32)
const char kPathSep         = '\\';
const char kPathSepStr[]    = "\\";
const char kAltPathSep      = '/';
const char kAltPathSepStr[] = "/";
#else
const char kPathSep      = '/';
const char kPathSepStr[] = "/";
#endif

bool Exists(const std::string& path);

bool IsFile(const std::string& path);

bool IsDirectory(const std::string& path);

std::string Join(const std::string& lhs, const std::string& rhs);

std::string InsertFilenamePostfix(const std::string& filename, const std::string& postfix);

std::string GetBasedir(const std::string& path);

std::string GetFilename(const std::string& path);

std::string GetFilenameStem(const std::string& path);

std::string GetFilenameExtension(const std::string& path);

bool MakeDirectory(const std::string& path);

std::string GenerateTimestampedFilename(const std::string& filename, bool use_gmt = false);

bool GetWindowsSystemLibrariesPath(std::string& base_path);

GFXRECON_END_NAMESPACE(filepath)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_FILE_PATH_H
