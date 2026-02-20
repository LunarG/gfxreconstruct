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

#ifndef GFXRECON_INFO_CONTAINER_H
#define GFXRECON_INFO_CONTAINER_H

#include "util/defines.h"

#include "info_api_interface.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

class InfoContainer
{
  public:
    InfoContainer();
    ~InfoContainer();

    bool RegisterApiInterface(InfoApiInterface* api_interface);

    bool ProcessCommandLine((int argc, const char** argv));

    bool ProcessCapture();

    bool OutputContent();

  protected:
    void PrintUsage();
    void PrintVersion();

    void WriteOutput(const char* format_string, ...);

  private:
    std::string                                    app_name_;
    InfoOutputLevel                                output_level_{ InfoOutputLevel::kBasic };
    std::vector<std::unique_ptr<InfoApiInterface>> api_interfaces_;
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INFO_CONTAINER_H
