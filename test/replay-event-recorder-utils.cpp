#include "replay-event-recorder-utils.h"

#include "verify-gfxr.h"

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>
#include <sstream>

static std::filesystem::path recorder_plugin_path()
{
    return std::filesystem::current_path() / REPLAY_EVENT_RECORDER_NAME;
}

static std::string quoted(const std::filesystem::path& path)
{
    return "\"" + path.string() + "\"";
}

static std::filesystem::path recorded_events_path(const char* test_name)
{
    std::string name{ test_name };

    const auto* test_info = ::testing::UnitTest::GetInstance()->current_test_info();
    if (test_info != nullptr)
    {
        name += std::string{ "_" } + test_info->test_suite_name() + "_" + test_info->name();
    }

    return std::filesystem::current_path() / (name + "_replay_events.txt");
}

static void read_recorded_events(const std::filesystem::path& path, std::vector<RecordedEvent>& events)
{
    std::ifstream stream(path);
    ASSERT_TRUE(stream.is_open()) << "the recorder plugin did not write " << path;

    events.clear();

    std::string line;
    while (std::getline(stream, line))
    {
        // Each line is whitespace separated key=value pairs, e.g. "type=3 abi=1 size=32 frame=0 ...".
        RecordedEvent      event;
        std::istringstream pairs(line);
        std::string        pair;

        while (pairs >> pair)
        {
            const size_t separator = pair.find('=');
            if (separator == std::string::npos)
            {
                ADD_FAILURE() << "the recorder wrote '" << pair << "', which is not a key=value pair";
                continue;
            }

            event.fields[pair.substr(0, separator)] = pair.substr(separator + 1);
        }

        auto type = event.fields.find("type");
        ASSERT_NE(type, event.fields.end()) << "the recorder wrote '" << line << "', which has no type";
        event.type = static_cast<uint32_t>(std::stoul(type->second));

        events.push_back(std::move(event));
    }
}

void replay_and_record_events(const char*                 test_name,
                              std::vector<std::string>    extra_replay_args,
                              std::vector<RecordedEvent>& events)
{
    const std::filesystem::path events_path = recorded_events_path(test_name);
    std::filesystem::remove(events_path);

    extra_replay_args.push_back("--replay-event-plugin-path");
    extra_replay_args.push_back(quoted(recorder_plugin_path()));
    extra_replay_args.push_back("--replay-event-plugin-params");
    extra_replay_args.push_back(quoted(events_path));

    ASSERT_NO_FATAL_FAILURE(capture_and_replay(test_name, extra_replay_args));
    ASSERT_NO_FATAL_FAILURE(read_recorded_events(events_path, events));
}

static const std::string* find_field(const RecordedEvent& event, const std::string& key)
{
    auto entry = event.fields.find(key);
    if (entry == event.fields.end())
    {
        ADD_FAILURE() << "the recorder did not write a '" << key << "' field for an event of type " << event.type;
        return nullptr;
    }

    return &entry->second;
}

uint64_t unsigned_field(const RecordedEvent& event, const std::string& key)
{
    const std::string* value = find_field(event, key);
    return (value == nullptr) ? 0 : std::stoull(*value);
}

int64_t signed_field(const RecordedEvent& event, const std::string& key)
{
    const std::string* value = find_field(event, key);
    return (value == nullptr) ? 0 : std::stoll(*value);
}

size_t index_of_first_event(const std::vector<RecordedEvent>& events, GfxrReplayEventType type)
{
    for (size_t i = 0; i < events.size(); ++i)
    {
        if (events[i].type == type)
        {
            return i;
        }
    }
    return kEventNotFound;
}

std::vector<RecordedEvent> events_of_type(const std::vector<RecordedEvent>& events, GfxrReplayEventType type)
{
    std::vector<RecordedEvent> matches;
    for (const RecordedEvent& event : events)
    {
        if (event.type == type)
        {
            matches.push_back(event);
        }
    }
    return matches;
}
