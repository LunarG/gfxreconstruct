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

#ifndef GFXRECON_INFO_WRITER_H
#define GFXRECON_INFO_WRITER_H

#include "util/defines.h"

#include <fstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

class InfoWriter
{
  public:
    virtual ~InfoWriter() = default;

    void SetOutputFile(const std::string& file_name)
    {
        output_file_.open(file_name);
        if (!output_file_.is_open())
        {
            GFXRECON_LOG_ERROR((std::string("Failed to open file ") + file_name + "\n").c_str());
        }
    }

    void OutputErrorsWarningsToConsole(bool console) { errors_warnings_always_to_console_ = console; }

    void Print(const std::string& message)
    {
        if (output_file_.is_open())
        {
            output_file_ << message << std::endl;
        }
        else
        {
            GFXRECON_WRITE_CONSOLE(message.c_str());
        }
    }

    void PrintError(const std::string& message)
    {
        // If writing a JSON output, we don't want errors in the JSON, so force
        // those out to the console
        if (!errors_warnings_always_to_console_ && output_file_.is_open())
        {
            output_file_ << "ERROR:" << message << std::endl;
        }
        else
        {
            GFXRECON_LOG_ERROR(message.c_str());
        }
    }
    void PrintWarning(const std::string& message)
    {
        // If writing a JSON output, we don't want warnings in the JSON, so force
        // those out to the console
        if (!errors_warnings_always_to_console_ && output_file_.is_open())
        {
            output_file_ << "WARNING:" << message << std::endl;
        }
        else
        {
            GFXRECON_LOG_WARNING(message.c_str());
        }
    }

  private:
    std::ofstream output_file_;
    bool          errors_warnings_always_to_console_{ false };
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INFO_WRITER_H
