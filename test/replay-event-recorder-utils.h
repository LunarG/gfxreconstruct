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

#ifndef GFXRECONSTRUCT_REPLAY_EVENT_RECORDER_UTILS_H
#define GFXRECONSTRUCT_REPLAY_EVENT_RECORDER_UTILS_H

#include <gfxr/replay_event_plugin.h>

#include <cstddef>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

/// Returned by index_of_first_event() when no event of the type was recorded.
constexpr size_t kEventNotFound = static_cast<size_t>(-1);

/**
 * One line of the replay event recorder plugin's output.
 */
struct RecordedEvent
{
    uint32_t type = 0;
    /// Every key=value pair the recorder wrote for the event, as text. Read them with unsigned_field() or
    /// signed_field().
    std::map<std::string, std::string> fields;
};

/**
 * Run capture_and_replay() for test_name with the replay event recorder plugin attached to the replay, and read back
 * every event it recorded.
 *
 * @param test_name         - the name of the test app to launch, capture and replay
 * @param extra_replay_args - additional arguments forwarded verbatim to gfxrecon-replay
 * @param[out] events       - every recorded event, in the order replay emitted them
 * @param trimming_frames   - the frames to capture or nullptr to capture every frame
 *
 * @note expects the same environment variables as verify_gfxr().
 */
void replay_and_record_events(const char*                 test_name,
                              std::vector<std::string>    extra_replay_args,
                              std::vector<RecordedEvent>& events,
                              const char*                 trimming_frames = nullptr);

/**
 * Read a field of a recorded event as an unsigned value, e.g. "timestamp_ns" or "submit_index".
 *
 * @return the value of the field, or 0 and a test failure naming the field if the recorder did not write it
 */
uint64_t unsigned_field(const RecordedEvent& event, const std::string& key);

/**
 * Read a field of a recorded event as a signed value, e.g. "result".
 *
 * @return the value of the field, or 0 and a test failure naming the field if the recorder did not write it
 */
int64_t signed_field(const RecordedEvent& event, const std::string& key);

/**
 * Find the first recorded event of a type.
 *
 * @param events - the events replay_and_record_events() read back
 * @param type   - the event type to look for
 *
 * @return the index of the first event of that type in events, or kEventNotFound if there is none
 */
size_t index_of_first_event(const std::vector<RecordedEvent>& events, GfxrReplayEventType type);

/**
 * Collect every recorded event of a type.
 *
 * @param events - the events replay_and_record_events() read back
 * @param type   - the event type to look for
 *
 * @return the events of that type, in the order replay emitted them
 */
std::vector<RecordedEvent> events_of_type(const std::vector<RecordedEvent>& events, GfxrReplayEventType type);

#endif // GFXRECONSTRUCT_REPLAY_EVENT_RECORDER_UTILS_H
