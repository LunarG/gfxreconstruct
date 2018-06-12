/*
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

#include "util/platform.h"
#include "util/file_output_stream.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

FileOutputStream::FileOutputStream(const std::string& filename, bool append) :
    file_(nullptr),
    own_file_(true)
{
    // TODO: Log an error if file open failed.
    platform::FileOpen(&file_, filename.c_str(), append ? "ab" : "wb");
}

FileOutputStream::FileOutputStream(FILE* file, bool owned) :
    file_(file),
    own_file_(owned)
{
}

FileOutputStream::~FileOutputStream()
{
    if ((file_ != nullptr) && own_file_)
    {
        platform::FileClose(file_);
    }
}

size_t FileOutputStream::Write(const void* data, size_t len)
{
    return platform::FileWriteNolock(data, 1, len, file_);
}

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)
