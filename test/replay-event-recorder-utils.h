#ifndef GFXRECONSTRUCT_REPLAY_EVENT_RECORDER_UTILS_H
#define GFXRECONSTRUCT_REPLAY_EVENT_RECORDER_UTILS_H

#include <gfxr/replay_event_plugin.h>

#include <cstddef>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

/**
 * One line of the replay event recorder plugin's output.
 */
struct RecordedEvent
{
    uint32_t type = 0;
    /// Every key=value pair the recorder wrote for the event, as text. Read them with unsigned_field().
    std::map<std::string, std::string> fields;
};

/**
 * Run capture_and_replay() for test_name with the replay event recorder plugin attached to the replay, and read back
 * every event it recorded.
 *
 * @param test_name         - the name of the test app to launch, capture and replay
 * @param extra_replay_args - additional arguments forwarded verbatim to gfxrecon-replay
 * @param[out] events       - every recorded event, in the order replay emitted them
 *
 * @note expects the same environment variables as verify_gfxr().
 */
void replay_and_record_events(const char*                 test_name,
                              std::vector<std::string>    extra_replay_args,
                              std::vector<RecordedEvent>& events);

/**
 * Read a field of a recorded event as an unsigned value, e.g. "timestamp_ns" or "submit_index".
 *
 * @return the value of the field, or 0 and a test failure naming the field if the recorder did not write it
 */
uint64_t unsigned_field(const RecordedEvent& event, const std::string& key);

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
