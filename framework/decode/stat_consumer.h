/*
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_STAT_CONSUMER_H
#define GFXRECON_DECODE_STAT_CONSUMER_H

#include "decode/api_decoder.h"
#include "stat_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class StatConsumer : public StatConsumerBase
{
  public:
    StatConsumer() {}
    const std::string GetAppExeName() const { return exe_info.AppExeName; }
    uint32_t          GetTrimmedStartFrame() const { return trimmed_frame_; }
    uint32_t*         GetAppVersion() { return exe_info.AppVersion; }
    char*             GetCompanyName() { return exe_info.CompanyName; }
    char*             GetFileDescription() { return exe_info.FileDescription; }
    char*             GetFileVersion() { return exe_info.FileVersion; }
    char*             GetInternalName() { return exe_info.InternalName; }
    char*             GetOriginalFileName() { return exe_info.OriginalFilename; }
    char*             GetProductName() { return exe_info.ProductName; }
    char*             GetProductVersion() { return exe_info.ProductVersion; }
    virtual void      Process_ExeFileInfo(gfxrecon::util::filepath::ExeFileInfo& info)
    {
        GFXRECON_LOG_INFO("Found captured executable info");
        exe_info        = info;
        found_exe_info_ = true;
    }

    virtual bool IsComplete(uint64_t current_block_index)
    {
        return (current_block_index >= MaxBlockIdx) || (found_exe_info_ == true);
    }

    virtual void ProcessStateBeginMarker(uint64_t frame_number) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(frame_number);
        // Theres should only be one of these in a capture file.
        trimmed_frame_ = static_cast<uint32_t>(frame_number);
    }

  private:
    static int const                      MaxBlockIdx = 50;
    gfxrecon::util::filepath::ExeFileInfo exe_info = {};
    uint32_t                              trimmed_frame_{ 0 };
    bool                                  found_exe_info_{ false };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_STAT_CONSUMER_H
