/*
** Copyright (c) 2026 Arm Limited <open-source-office@arm.com>
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

#include <catch2/catch.hpp>

#include "format/format_util.h"

TEST_CASE("File header validation ignores the Arm trace flag", "[format]")
{
    gfxrecon::format::FileHeader header{};
    header.fourcc        = GFXRECON_FOURCC;
    header.major_version = GFXRECON_CURRENT_FILE_MAJOR | gfxrecon::format::kArmTraceFileVersionFlag;
    header.minor_version = GFXRECON_CURRENT_FILE_MINOR;

    CHECK(gfxrecon::format::GetFileFormatMajorVersion(header) == GFXRECON_CURRENT_FILE_MAJOR);
    CHECK(gfxrecon::format::ValidateFileHeader(header));
}

TEST_CASE("File header validation still rejects unsupported Arm trace versions", "[format]")
{
    gfxrecon::format::FileHeader header{};
    header.fourcc        = GFXRECON_FOURCC;
    header.major_version = GFXRECON_CURRENT_FILE_MAJOR | gfxrecon::format::kArmTraceFileVersionFlag;
    header.minor_version = GFXRECON_CURRENT_FILE_MINOR + 1;

    CHECK_FALSE(gfxrecon::format::ValidateFileHeader(header));

    header.major_version = 0x40000000u;
    header.minor_version = GFXRECON_CURRENT_FILE_MINOR;
    CHECK_FALSE(gfxrecon::format::ValidateFileHeader(header));
}
