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
    return std::filesystem::current_path() / (test_file_name(test_name) + "_replay_events.txt");
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
