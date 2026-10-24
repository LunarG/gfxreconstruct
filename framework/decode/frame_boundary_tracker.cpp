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

#include "decode/frame_boundary_tracker.h"
#include "format/format_util.h"
#include "util/logging.h"

#include <cinttypes>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void FrameBoundaryTracker::ProcessFileHeader(const format::FileHeader& file_header)
{
    auto file_version = GFXRECON_MAKE_FILE_VERSION(file_header.major_version, file_header.minor_version);
    if (file_version >= GFXRECON_EXPLICIT_FRAME_MARKER_FILE_VERSION)
    {
        capture_uses_frame_markers_  = true;
        file_supports_frame_markers_ = true;
    }
}

void FrameBoundaryTracker::ProcessAnnotation(const AnnotationArgs& annotation)
{
    if (annotation.type == gfxrecon::format::AnnotationType::kJson &&
        annotation.label.compare(gfxrecon::format::kAnnotationLabelOperation) == 0)
    {
        format::GfxrVersion version = format::ParseVersionFromOperations(annotation.annotation_data.c_str());
        if (version.SupportsFrameMarkers())
        {
            GFXRECON_ASSERT(frame_number_ == file_processor::kFirstFrame);
            capture_uses_frame_markers_  = true;
            file_supports_frame_markers_ = true;
        }
    }
}

void FrameBoundaryTracker::ProcessStateEndMarker(const StateEndMarkerArgs& state_end)
{
    first_frame_ = state_end.frame_number;
}

bool FrameBoundaryTracker::IsFrameDelimiter(format::ApiCallId call_id) const
{
    if (capture_uses_frame_markers_)
    {
        return false;
    }
    return ((call_id == format::ApiCallId::ApiCall_vkQueuePresentKHR) ||
            (call_id == format::ApiCallId::ApiCall_vkFrameBoundaryANDROID) ||
            (call_id == format::ApiCallId::ApiCall_IDXGISwapChain_Present) ||
            (call_id == format::ApiCallId::ApiCall_IDXGISwapChain1_Present1) ||
            (call_id == format::ApiCallId::ApiCall_xrEndFrame));
}

bool FrameBoundaryTracker::ProcessFrameEndMarker(const FrameEndMarkerArgs& end_frame)
{
    if (capture_uses_frame_markers_ && (frame_number_ != (end_frame.frame_number - first_frame_)))
    {
        GFXRECON_LOG_ERROR("Frame end marker frame number (%" PRIu64 ") does not match current frame number (%" PRIu64
                           ")",
                           end_frame.frame_number - first_frame_,
                           frame_number_);
    }
    if (!capture_uses_frame_markers_)
    {
        pending_capture_uses_frame_markers_ = true;
    }
    return true;
}

void FrameBoundaryTracker::EndFrame()
{
    if (pending_capture_uses_frame_markers_)
    {
        GFXRECON_ASSERT(!capture_uses_frame_markers_);
        capture_uses_frame_markers_         = true;
        pending_capture_uses_frame_markers_ = false;
        frame_number_                       = file_processor::kFirstFrame;
        GFXRECON_LOG_WARNING("Explicit frame markers found in file format (0.0) file w/ gfxrecon-version < (1.0.1). "
                             "Patch input file format with 'gfxrecon-file-version-patch'");
    }

    ++frame_number_;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
