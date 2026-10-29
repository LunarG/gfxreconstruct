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

#ifndef GFXRECON_DECODE_FRAME_BOUNDARY_TRACKER_H
#define GFXRECON_DECODE_FRAME_BOUNDARY_TRACKER_H

#include "decode/api_payload.h"
#include "decode/file_processor_types.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "util/defines.h"

#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Decides where frames end in a capture file and counts them.
// A frame-end marker always ends a frame. A present-type call ends one only when the capture does not use frame
// markers.
class FrameBoundaryTracker
{
  public:
    // files from a format version with explicit frame markers use them.
    void ProcessFileHeader(const format::FileHeader& file_header);

    // an operation annotation from a gfxrecon version with frame markers means the capture uses them.
    void ProcessAnnotation(const AnnotationArgs& annotation);

    // the state-end marker holds the first frame of a trimmed capture.
    void ProcessStateEndMarker(const StateEndMarkerArgs& state_end);

    // returns true if the call ends the current frame.
    bool IsFrameDelimiter(format::ApiCallId call_id) const;

    // checks the marker's frame number against the count. Returns true, as a frame-end marker always ends a frame.
    bool ProcessFrameEndMarker(const FrameEndMarkerArgs& end_frame);

    // Advances to the next frame. Call once the frame-ending block has been processed.
    void EndFrame();

    uint64_t GetFrameNumber() const noexcept { return frame_number_; }
    bool     UsesFrameMarkers() const noexcept { return capture_uses_frame_markers_; }
    bool     FileSupportsFrameMarkers() const noexcept { return file_supports_frame_markers_; }

  private:
    uint64_t frame_number_{ file_processor::kFirstFrame };
    bool     capture_uses_frame_markers_{ false };
    bool     file_supports_frame_markers_{ false };
    bool     pending_capture_uses_frame_markers_{ false };

    // frame offset for trimmed captures: set from the state-end marker's frame number.
    uint64_t first_frame_{ file_processor::kFirstFrame + 1 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FRAME_BOUNDARY_TRACKER_H
