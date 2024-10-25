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

#include "util/file_output_stream.h"

#include "util/logging.h"
#include "util/platform.h"
#include <cstring>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

FileOutputStream::FileOutputStream(const std::string& filename, size_t buffer_size, bool append) :
    file_(nullptr), own_file_(true)
{
    const char* mode   = append ? "ab" : "wb";
    int32_t     result = platform::FileOpen(&file_, filename.c_str(), mode);

    if (file_ != nullptr)
    {
        result = platform::SetFileBufferSize(file_, buffer_size);
        if (result != 0)
        {
            GFXRECON_LOG_WARNING("Failed to set file buffer size. File writing performance may be affected.");
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("fopen(%s, %s) failed (errno = %d: %s)", filename.c_str(), mode, result, strerror(result));
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

void FileOutputStream::Reset(FILE* file)
{
    if ((file_ != nullptr) && own_file_)
    {
        platform::FileClose(file_);
    }

    file_ = file;
}

bool FileOutputStream::Write(const void* data, size_t len)
{
    return platform::FileWrite(data, len, file_);
}

bool FileNoLockOutputStream::Write(const void* data, size_t len)
{
    return platform::FileWriteNoLock(data, len, file_);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
