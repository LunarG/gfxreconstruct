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

#include "util/file_path.h"

#include "util/date_time.h"

#if defined(WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

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

bool Exists(const std::string& path)
{
#if defined(WIN32)
    return (GetFileAttributesA(path.c_str()) != INVALID_FILE_ATTRIBUTES);
#else
    struct stat info;
    return (stat(path.c_str(), &info) == 0);
#endif
}

bool IsFile(const std::string& path)
{
    bool is_file = false;

#if defined(WIN32)
    DWORD attribs = GetFileAttributesA(path.c_str());
    if ((attribs != INVALID_FILE_ATTRIBUTES) && ((attribs & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY))
    {
        is_file = true;
    }
#else
    struct stat info;
    if ((stat(path.c_str(), &info) == 0) && (S_ISREG(info.st_mode)))
    {
        is_file = true;
    }
#endif

    return is_file;
}

bool IsDirectory(const std::string& path)
{
    bool is_dir = false;

#if defined(WIN32)
    DWORD attribs = GetFileAttributesA(path.c_str());
    if ((attribs != INVALID_FILE_ATTRIBUTES) && ((attribs & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY))
    {
        is_dir = true;
    }
#else
    struct stat info;
    if ((stat(path.c_str(), &info) == 0) && (S_ISDIR(info.st_mode)))
    {
        is_dir = true;
    }
#endif

    return is_dir;
}

std::string Join(const std::string& lhs, const std::string& rhs)
{
    std::string joined;

    if (!lhs.empty())
    {
        joined = lhs;

        if (!rhs.empty())
        {
            bool lhs_has_sep = (lhs.back() == kPathSep);
            bool rhs_has_sep = (rhs.front() == kPathSep);

#if defined(WIN32)
            // For Windows, we can accept either path separator.
            lhs_has_sep = lhs_has_sep || (lhs.back() == kAltPathSep);
            rhs_has_sep = rhs_has_sep || (rhs.front() == kAltPathSep);
#endif

            if (lhs_has_sep && rhs_has_sep)
            {
                // Both strings to be joined have a separator, so strip the separator from rhs.
                joined += rhs.substr(1, std::string::npos);
            }
            else
            {
                // Only one string has a path seprator and both can be joined without modification, or neither string
                // has a path separator and it has to be added.
                if (!lhs_has_sep && !rhs_has_sep)
                {
                    joined += kPathSep;
                }

                joined += rhs;
            }
        }
    }
    else if (!rhs.empty())
    {
        // When lhs is empty, we can use rhs without additional processing.
        joined = rhs;
    }

    return joined;
}

std::string InsertFilenamePostfix(const std::string& filename, const std::string& postfix)
{
    std::string file_extension;
    std::string file_part;
    size_t      sep_index = filename.rfind('.');

    if (sep_index != std::string::npos)
    {
        file_extension = filename.substr(sep_index);
        file_part      = filename.substr(0, sep_index);

        return file_part + postfix + file_extension;
    }

    return filename + postfix;
}

std::string GenerateTimestampedFilename(const std::string& filename, bool use_gmt)
{
    std::string timestamp = "_";
    timestamp += util::datetime::GetDateTimeString(use_gmt);
    return InsertFilenamePostfix(filename, timestamp);
}

GFXRECON_END_NAMESPACE(filepath)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
