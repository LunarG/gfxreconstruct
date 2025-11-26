/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_INFO_OUTPUT_H
#define GFXRECON_UTIL_INFO_OUTPUT_H

#include "util/defines.h"
#include "util/logging.h"

#include "nlohmann/json.hpp"

#include <fstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Global variables defining where we should output results to
enum InfoOutputFormat
{
    kInfoOutputFmt_Text = 0,
    kInfoOutputFmt_Json
};

class InfoOutputInterface
{
  public:
    virtual std::pair<const std::string, const nlohmann::json*> GenerateJson() const    = 0;
    virtual const std::vector<std::string>                      GenerateStrings() const = 0;
};

class InfoWriter
{
  public:
    InfoWriter() {}
    ~InfoWriter() {}

    void AddInfoOutputItem(const InfoOutputInterface* io)
    {
        if (io)
        {
            info_output_vec_.push_back(io);
        }
    }

    void SetFileTarget(const std::string& filename)
    {
        if (output_file.is_open())
        {
            output_file.close();
        }
        output_file.open(filename);
    }

    void SetOutputFormat(InfoOutputFormat format)
    {
        format_ = format;
        if (format_ == kInfoOutputFmt_Json)
        {
            json_content_ = new nlohmann::json();
        }
    }
    InfoOutputFormat GetOutputFormat() { return format_; }

    void AddMessage(const std::string& message) { messages_.push_back(message); }

    void AddWarning(const std::string& message) { messages_.push_back(std::string("WARNING: ") + message); }

    void AddError(const std::string& message) { messages_.push_back(std::string("ERROR: ") + message); }

    void AddJsonNode(const std::string& node_label, const nlohmann::json& json_obj)
    {
        (*json_content_)[node_label.c_str()] = json_obj;
    }

    void GenerateOutput()
    {
        for (auto& message : messages_)
        {
            GFXRECON_WRITE_CONSOLE(message.c_str());
        }
        switch (format_)
        {
            case kInfoOutputFmt_Text:
            {
                for (const auto& info : info_output_vec_)
                {
                    for (auto& str : info->GenerateStrings())
                    {
                        WriteOutput(str);
                    }
                }
                break;
            }
            case kInfoOutputFmt_Json:
            {
                for (const auto& info : info_output_vec_)
                {
                    auto new_pair                            = info->GenerateJson();
                    (*json_content_)[new_pair.first.c_str()] = *new_pair.second;
                }
                WriteOutput(json_content_->dump(4, ' ', true).c_str());
                break;
            }
        }
    }

  private:
    // Write the output where it needs to go
    void WriteOutput(const std::string& out_string)
    {
        if (output_file.is_open())
        {
            GFXRECON_ASSERT(output_file.is_open());
            output_file << out_string.c_str() << std::endl;
        }
        else
        {
            GFXRECON_WRITE_CONSOLE(out_string.c_str());
        }
    }

    std::ofstream                           output_file;
    InfoOutputFormat                        format_{ kInfoOutputFmt_Text };
    nlohmann::json*                         json_content_{ nullptr };
    std::vector<const InfoOutputInterface*> info_output_vec_;
    std::vector<std::string>                messages_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_INFO_OUTPUT_H