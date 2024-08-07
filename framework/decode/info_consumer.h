/*
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_INFO_CONSUMER_H
#define GFXRECON_DECODE_INFO_CONSUMER_H

#include "decode/api_decoder.h"
#include "info_consumer.h"
#include "util/strings.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class InfoConsumer
{
  public:
    InfoConsumer() {}
    InfoConsumer(bool short_version) { short_version_ = short_version; }
    const std::string GetAppExeName() const { return exe_info.AppName; }
    const uint32_t*   GetAppVersion() const { return exe_info.AppVersion; }
    const char*       GetCompanyName() const { return exe_info.CompanyName; }
    const char*       GetFileDescription() const { return exe_info.FileDescription; }
    const char*       GetFileVersion() const { return exe_info.FileVersion; }
    const char*       GetInternalName() const { return exe_info.InternalName; }
    const char*       GetOriginalFileName() const { return exe_info.OriginalFilename; }
    const char*       GetProductName() const { return exe_info.ProductName; }
    const char*       GetProductVersion() const { return exe_info.ProductVersion; }
    const std::vector<std::string>& GetEnvironmentVariables() const { return env_vars; }

    void Process_ExeFileInfo(gfxrecon::util::filepath::FileInfo& info)
    {
        exe_info        = info;
        found_exe_info_ = true;
    }

    const char* GetDriverDesc() const { return driver_info; }

    void Process_DriverInfo(const char* info_record)
    {
        util::platform::StringCopy(driver_info,
                                   gfxrecon::util::filepath::kMaxDriverInfoSize,
                                   info_record,
                                   gfxrecon::util::filepath::kMaxDriverInfoSize);
        found_driver_info_ = true;
    }

    bool IsComplete(uint64_t current_block_index)
    {
        if (short_version_ == true)
        {
            return (current_block_index >= MaxBlockIdx) || (found_exe_info_ && found_driver_info_);
        }
        else
        {
            return found_exe_info_ && found_driver_info_;
        }
    }

    void Process_SetEnvironmentVariablesCommand(format::SetEnvironmentVariablesCommand& header, const char* env_string)
    {
        env_vars = util::strings::SplitString(std::string_view(env_string), format::kEnvironmentStringDelimeter);
    }

  private:
    static int const                   MaxBlockIdx                                               = 50;
    char                               driver_info[gfxrecon::util::filepath::kMaxDriverInfoSize] = {};
    bool                               short_version_{ false };
    bool                               found_driver_info_{ false };
    gfxrecon::util::filepath::FileInfo exe_info = {};
    bool                               found_exe_info_{ false };
    std::vector<std::string>           env_vars;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_INFO_CONSUMER_H
