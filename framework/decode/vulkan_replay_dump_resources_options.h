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

#ifndef GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_OPTIONS_H
#define GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_OPTIONS_H

#include "util/options.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static const char* kVDROptions                         = "DumpResourcesOptions";
static const char* kVDROptionScale                     = "Scale";
static const char* kVDROptionImageFormat               = "ImageFormat";
static const char* kVDROptionOutputDir                 = "OutputDir";
static const char* kVDROptionBefore                    = "DumpBeforeCommand";
static const char* kVDROptionDumpDepth                 = "DumpDepth";
static const char* kVDROptionColorAttachmentIndex      = "ColorAttachmentIndex";
static const char* kVDROptionDumpVertexIndexBuffer     = "DumpVertexIndexBuffer";
static const char* kVDROptionDumpAllDescriptors        = "DumpAllDescriptors";
static const char* kVDROptionDumpAllImageSubresources  = "DumpAllImageSubresources";
static const char* kVDROptionDumpRawImages             = "DumpRawImages";
static const char* kVDROptionDumpSeparateAlpha         = "DumpSeparateAlpha";
static const char* kVDROptionDumpUnusedVertexBindings  = "DumpUnusedVertexBindings";
static const char* kVDROptionJsonOutputPerCommand      = "JsonOutputPerCommand";
static const char* kVDROptionBinaryFileCompressionType = "BinaryFileCompressionType";
static const char* kVDROptionDumpBuildAccelerationStructuresInputBuffers =
    "DumpBuildAccelerationStructuresInputBuffers";

static const char* ImageFormatToString(gfxrecon::util::ScreenshotFormat format)
{
    switch (format)
    {
        case gfxrecon::util::ScreenshotFormat::kBmp:
            return gfxrecon::util::kScreenshotFormatBmp;
        case gfxrecon::util::ScreenshotFormat::kPng:
            return gfxrecon::util::kScreenshotFormatPng;
        default:
            GFXRECON_LOG_WARNING("%s(): Unrecognized image format %d", __func__, static_cast<int>(format));
            return gfxrecon::util::kScreenshotFormatBmp;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_OPTIONS_H
