#include <gtest/gtest.h>

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include <gfxr/replay_event_plugin.h>

#include "verify-gfxr.h"

/**
 * Replay a capture with --wait-before-frame and --wait-before-first-submit and assert that replay
 * emits the wait events the plugin ABI promises.
 */

namespace
{

// Replay sleeps this long before the first queue submit of each replayed frame.
constexpr uint32_t kWaitBeforeFrameMs = 20;

// Replay sleeps until this much time has elapsed since it parsed its options, once per process.
constexpr uint32_t kWaitBeforeFirstSubmitMs = 200;

// One line of the recorder plugin's output, parsed into its key=value fields.
using RecordedEvent = std::map<std::string, std::string>;

// The value the recorder wrote for `key`, or an empty string and a failure naming the missing field.
std::string field(const RecordedEvent& event, const std::string& key)
{
    auto entry = event.find(key);
    if (entry == event.end())
    {
        ADD_FAILURE() << "the recorder did not write a '" << key << "' field";
        return std::string();
    }

    return entry->second;
}

// Every field these tests read is unsigned. A signed one, such as a queue submit result, needs its
// own accessor: stoull silently wraps a negative value rather than rejecting it.
uint64_t unsigned_field(const RecordedEvent& event, const std::string& key)
{
    std::string value = field(event, key);
    return value.empty() ? 0 : std::stoull(value);
}

uint32_t event_type(const RecordedEvent& event)
{
    return static_cast<uint32_t>(unsigned_field(event, "type"));
}

// The recorder plugin ships next to the test runner, and both run from the install tree.
std::filesystem::path recorder_plugin_path()
{
    return std::filesystem::current_path() / REPLAY_EVENT_RECORDER_NAME;
}

// Quoted so that an install path containing spaces survives the shell.
std::string quoted(const std::filesystem::path& path)
{
    return "\"" + path.string() + "\"";
}

std::vector<RecordedEvent> read_recorded_events(const std::filesystem::path& path)
{
    std::vector<RecordedEvent> events;

    std::ifstream stream(path);
    EXPECT_TRUE(stream.is_open()) << "the recorder plugin did not write " << path;

    std::string line;
    while (std::getline(stream, line))
    {
        RecordedEvent      event;
        std::istringstream pairs(line);
        std::string        pair;

        while (pairs >> pair)
        {
            size_t separator = pair.find('=');
            if (separator == std::string::npos)
            {
                ADD_FAILURE() << "the recorder wrote '" << pair << "', which is not a key=value pair";
                continue;
            }

            event[pair.substr(0, separator)] = pair.substr(separator + 1);
        }

        events.push_back(event);
    }

    return events;
}

std::vector<RecordedEvent> events_of_type(const std::vector<RecordedEvent>& events, uint32_t type)
{
    std::vector<RecordedEvent> matches;
    for (const RecordedEvent& event : events)
    {
        if (event_type(event) == type)
        {
            matches.push_back(event);
        }
    }
    return matches;
}

// Replay the named capture with the recorder plugin attached, and return everything it recorded.
std::vector<RecordedEvent> replay_and_record_events(const char* test_name, std::vector<std::string> extra_replay_args)
{
    std::filesystem::path events_path =
        std::filesystem::current_path() / (std::string(test_name) + "_replay_events.txt");
    std::filesystem::remove(events_path);

    extra_replay_args.push_back("--replay-event-plugin-path");
    extra_replay_args.push_back(quoted(recorder_plugin_path()));
    extra_replay_args.push_back("--replay-event-plugin-params");
    extra_replay_args.push_back(quoted(events_path));

    capture_and_replay(test_name, extra_replay_args);

    return read_recorded_events(events_path);
}

} // namespace

TEST(ReplayWaitOptions, WaitBeforeFrameEmitsAWaitPerFrame)
{
    std::vector<RecordedEvent> events =
        replay_and_record_events("triangle", { "--wait-before-frame", std::to_string(kWaitBeforeFrameMs) });

    std::vector<RecordedEvent> wait_begins = events_of_type(events, GFXR_REPLAY_EVENT_WAIT_BEGIN);

    EXPECT_GT(wait_begins.size(), 1) << "--wait-before-frame emitted " << wait_begins.size()
                                     << " waits, so it did not wait before every frame";
    EXPECT_EQ(events_of_type(events, GFXR_REPLAY_EVENT_WAIT_END).size(), wait_begins.size());

    for (const RecordedEvent& wait_begin : wait_begins)
    {
        EXPECT_EQ(unsigned_field(wait_begin, "requested_duration_ms"), kWaitBeforeFrameMs);
    }
}

TEST(ReplayWaitOptions, WaitBeforeFirstSubmitEmitsOneWait)
{
    std::vector<RecordedEvent> events = replay_and_record_events(
        "triangle", { "--wait-before-first-submit", std::to_string(kWaitBeforeFirstSubmitMs) });

    std::vector<RecordedEvent> wait_begins = events_of_type(events, GFXR_REPLAY_EVENT_WAIT_BEGIN);

    ASSERT_EQ(wait_begins.size(), 1) << "the first queue submit is only delayed once per replay";
    EXPECT_EQ(events_of_type(events, GFXR_REPLAY_EVENT_WAIT_END).size(), 1);

    // Check the wait was for a valid time.
    EXPECT_GT(unsigned_field(wait_begins.front(), "requested_duration_ms"), 0);
}

TEST(ReplayWaitOptions, NoWaitOptionEmitsNoWaitEvents)
{
    std::vector<RecordedEvent> events = replay_and_record_events("triangle", {});

    EXPECT_FALSE(events.empty()) << "the recorder plugin received no events at all";
    EXPECT_TRUE(events_of_type(events, GFXR_REPLAY_EVENT_WAIT_BEGIN).empty());
    EXPECT_TRUE(events_of_type(events, GFXR_REPLAY_EVENT_WAIT_END).empty());
}
