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

#ifndef GFXRECON_UTIL_FILE_PATH_H
#define GFXRECON_UTIL_FILE_PATH_H

#include "util/date_time.h"
#include "util/defines.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(filepath)

inline std::string GenerateTimestampedFilename(const std::string& filename, bool use_gmt = false)
{
    std::string file_extension;
    std::string core_filename;
    size_t      period_loc = filename.rfind('.');

    if (period_loc != std::string::npos)
    {
        file_extension = filename.substr(period_loc, filename.length() - period_loc + 1);
        core_filename  = filename.substr(0, period_loc);
    }
    else
    {
        file_extension = "";
        core_filename  = filename;
    }

    return core_filename + "_" + util::datetime::GetDateTimeString(use_gmt) + file_extension;
}

GFXRECON_END_NAMESPACE(filepath)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_FILE_PATH_H
