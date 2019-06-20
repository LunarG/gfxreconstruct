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
