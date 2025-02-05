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
/// @file Streaming into a file using the platform FILE abstractions.

#ifndef GFXRECON_UTIL_FILE_OUTPUT_STREAM_H
#define GFXRECON_UTIL_FILE_OUTPUT_STREAM_H

#include "util/defines.h"
#include "util/output_stream.h"
#include "util/platform.h"
#include "util/thread_data.h"

#include <cstdint>
#include <cstdio>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

/// @brief An implementation of the abstract OuptutStream interface which writes
/// to a file or sequence of files.
class FileOutputStream : public OutputStream
{
  public:
    /// @param buffer_size Controls the size of file stream buffer. If buffer_size is 0,
    /// file writes will be unbuffered.
    FileOutputStream(const std::string& filename, size_t buffer_size, bool append = false);

    FileOutputStream(FILE* file, bool owned = false);

    /// @brief Change from current file to a new one, closing the old only if it was owned.
    /// @param file The new file to stream writes into.
    virtual void Reset(FILE* file);

    virtual ~FileOutputStream() override;

    virtual bool IsValid() override { return (file_ != nullptr); }

    virtual bool Write(const void* data, size_t len) override;

    virtual void Flush() override { platform::FileFlush(file_); }

    virtual int64_t GetOffset() const { return platform::FileTell(file_); }

  protected:
    FileOutputStream(const FileOutputStream&)            = delete;
    FileOutputStream& operator=(const FileOutputStream&) = delete;
    FILE*             file_;
    bool              own_file_;
};

class FileNoLockOutputStream : public FileOutputStream
{
  public:
    /// @param buffer_size Controls the size of file stream buffer. If buffer_size is 0,
    /// file writes will be unbuffered.
    FileNoLockOutputStream(const std::string& filename, size_t buffer_size, bool append = false) :
        FileOutputStream(filename, buffer_size, append)
    {}
    FileNoLockOutputStream(FILE* file, bool owned = false) : FileOutputStream(file, owned) {}

    virtual bool Write(const void* data, size_t len) override;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_FILE_OUTPUT_STREAM_H
