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

#include "util/file_output_stream.h"

#include "util/logging.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

FileOutputStream::FileOutputStream(const std::string& filename, bool append) : file_(nullptr), own_file_(true)
{
    const char* mode   = append ? "ab" : "wb";
    int32_t     result = platform::FileOpen(&file_, filename.c_str(), mode);

    if (file_ == nullptr)
    {
        GFXRECON_LOG_ERROR("fopen(%s, %s) failed (errno = %d)", filename.c_str(), mode, result);
    }
}

FileOutputStream::FileOutputStream(FILE* file, bool owned) : file_(file), own_file_(owned) {}

FileOutputStream::~FileOutputStream()
{
    if ((file_ != nullptr) && own_file_)
    {
        platform::FileClose(file_);
    }
}

size_t FileOutputStream::Write(const void* data, size_t len)
{
    return platform::FileWriteNoLock(data, 1, len, file_);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
