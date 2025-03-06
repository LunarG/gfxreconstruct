#include "verify-gfxr.h"

#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <stdlib.h>

bool clean_gfxr_json(int depth, nlohmann::json::parse_event_t event, nlohmann::json& parsed)
{
    switch (event)
    {
        case nlohmann::json::parse_event_t::key:
        {
            auto key = to_string(parsed);
            if (std::strncmp("\"pfn\"", key.c_str(), 4) == 0)
                return false;
            if (key == "\"hinstance\"")
                return false;
            if (key == "\"hwnd\"")
                return false;
            if (key == "\"pipelineCacheUUID\"")
                return false;
            if (key == "\"ppData\"")
                return false;
        }
        break;
        case nlohmann::json::parse_event_t::object_end:
            if (depth == 1 && parsed.contains("header"))
                return false;
            if (depth == 1 && parsed.contains("annotation"))
                return false;
            if (depth == 1 && parsed.contains("meta"))
                return false;
            break;
    }

    return true;
}

#if defined(__linux__) || defined(__APPLE__)
static char const* CONVERT_FILENAME = "gfxrecon-convert";
#elif defined(_WIN32)
static char const* CONVERT_FILENAME = "gfxrecon-convert.exe";
#endif

struct Paths
{
    std::filesystem::path base_path{ std::filesystem::current_path() };
    std::filesystem::path full_app_directory{ base_path };
    std::filesystem::path full_executable_path;
    std::filesystem::path convert_path{ base_path };
    std::filesystem::path capture_path{ base_path };
    std::filesystem::path known_good_path{ base_path };
    std::filesystem::path app_json_path;
    std::filesystem::path known_good_json_path;

    Paths(char const* app_directory, char const* app_executable, char const* known_gfxr_path)
    {
        full_app_directory.append("test_apps");
        full_app_directory.append(app_directory);

        full_executable_path = std::filesystem::path{ full_app_directory };
        full_executable_path.append(app_executable);

        convert_path.append(CONVERT_FILENAME);

        capture_path.append("test_apps");
        capture_path.append(app_directory);
        capture_path.append("actual.gfxr");

        known_good_path.append("known_good");
        known_good_path.append(known_gfxr_path);

        app_json_path = std::filesystem::path{ capture_path };
        app_json_path.replace_extension(".json");

        known_good_json_path = std::filesystem::path{ known_good_path };
        known_good_json_path.replace_extension(".json");
    }
};

int run_command(std::filesystem::path const& working_directory,
                std::filesystem::path const& command,
                std::vector<std::string>     args)
{
    std::string command_string;
    command_string += command.string();
    for (auto& arg : args)
    {
        command_string += " ";
        command_string += arg;
    }

    auto previous_path = std::filesystem::current_path();
    std::filesystem::current_path(working_directory);
    auto result = std::system(command_string.c_str());
    std::filesystem::current_path(previous_path);
    return result;
}

void verify_gfxr(char const* app_directory, char const* app_executable, char const* known_gfxr_path)
{
    Paths paths{ app_directory, app_executable, known_gfxr_path };

    int result;

    // run app
    result = run_command(paths.full_app_directory, paths.full_executable_path, {});
    ASSERT_EQ(result, 0) << "command failed " << paths.full_executable_path << " in path " << paths.full_app_directory;

    // convert actual gfxr
    result = run_command(paths.base_path, paths.convert_path, { paths.capture_path.string() });
    ASSERT_EQ(result, 0) << "command failed " << paths.convert_path << " " << paths.capture_path << " in path "
                         << paths.base_path;

    // convert known good gfxr
    result = run_command(paths.base_path, paths.convert_path, { paths.known_good_path.string() });
    ASSERT_EQ(result, 0) << "command failed " << paths.convert_path << " " << paths.known_good_path << " in path "
                         << paths.base_path;

    std::ifstream app_file{ paths.app_json_path };
    ASSERT_TRUE(app_file.is_open()) << "app json file would not open";
    auto app_json = nlohmann::json::parse(app_file, clean_gfxr_json);

    std::ifstream known_file{ paths.known_good_json_path };
    ASSERT_TRUE(known_file.is_open()) << "known good json file would not open";
    auto known_json = nlohmann::json::parse(known_file, clean_gfxr_json);

    auto diff = nlohmann::json::diff(known_json, app_json);
    ASSERT_EQ(diff.size(), 0) << std::setw(4) << diff;
}