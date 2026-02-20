/*
** Copyright (c) 2020-2026 LunarG, Inc.
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

#ifndef GFXRECON_INFO_API_INTERFACE_H
#define GFXRECON_INFO_API_INTERFACE_H

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

enum class FrameMarkerTypes : std::uint32_t
{
    kImplicit = 0,
    kExplicit,
};

enum class InfoOutputLevel : std::uint32_t
{
    kBasic = 0,
    kVerbose,
};

class InfoApiInterface
{
  public:
    virtual ~InfoApiInterface() = default;

    virtual format::ApiFamilyId ApiFamilyId()                                                                = 0;
    virtual std::string         ApiLabel()                                                                   = 0;
    virtual std::string         ApiHeaderVersionString()                                                     = 0;
    virtual void                RegisterApiDecodeComponents(gfxrecon::decode::FileProcessor& file_processor) = 0;
    virtual bool                ApiWasDetected()                                                             = 0;

    virtual void OutputExeInfo()                   = 0;
    virtual void OutputApplicationInfo()           = 0;
    virtual void OutputEnvironment()               = 0;
    virtual void OutputFileInfo()                  = 0;
    virtual void OutputInfo(InfoOutputLevel level) = 0;

    virtual void             GetFrameStart()       = 0;
    virtual FrameMarkerTypes GetFrameMarkerType()  = 0;
    virtual uint32_t         GetActualFrameCount() = 0;
    virtual uint32_t         GetBlankFrameCount()  = 0;
    uint32_t                 GetTotalFrameCount() { return GetActualFrameCount() + GetBlankFrameCount(); }
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INFO_API_INTERFACE_H
