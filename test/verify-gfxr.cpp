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

void verify_gfxr(char const* app_directory, char const* app_executable, char const* known_gfxr_path)
{
    std::system("set");
    auto base_path = std::filesystem::current_path();

    std::filesystem::path full_app_directory(base_path);
    full_app_directory.append("test_apps");
    full_app_directory.append(app_directory);

    std::filesystem::path full_executable_path(full_app_directory);
    full_executable_path.append(app_executable);

    std::filesystem::current_path(full_app_directory);
    auto app_result = std::system(full_executable_path.string().c_str());
    std::filesystem::current_path(base_path);
    ASSERT_EQ(app_result, 0) << "command failed " << app_executable << " in path " << full_app_directory;

    std::filesystem::path convert_path{base_path};
    convert_path.append("gfxrecon-convert.exe");

    std::filesystem::path capture_path{ base_path };
    capture_path.append("test_apps");
    capture_path.append(app_directory);
    capture_path.append("actual.gfxr");

    std::string app_convert_command;
    app_convert_command += convert_path.string();
    app_convert_command += " ";
    app_convert_command += capture_path.string();
    auto app_convert_result = std::system(app_convert_command.c_str());
    ASSERT_EQ(app_convert_result, 0) << "command failed " << app_convert_command;

    std::filesystem::path known_good_path{ base_path };
    known_good_path.append("known_good");
    known_good_path.append(known_gfxr_path);

    std::string known_good_convert_command;
    known_good_convert_command += convert_path.string();
    known_good_convert_command += " ";
    known_good_convert_command += known_good_path.string();
    auto known_good_convert_result = std::system(known_good_convert_command.c_str());
    ASSERT_EQ(known_good_convert_result, 0) << "command failed " << known_good_convert_command;

    std::filesystem::path app_json_path{ capture_path };
    app_json_path.replace_extension(".json");
    std::ifstream app_file{ app_json_path };
    ASSERT_TRUE(app_file.is_open()) << "app json file would not open";
    auto app_json = nlohmann::json::parse(app_file, clean_gfxr_json);

    std::filesystem::path known_good_json_path{ known_good_path };
    known_good_json_path.replace_extension(".json");
    std::ifstream known_file{ known_good_json_path };
    ASSERT_TRUE(known_file.is_open()) << "known good json file would not open";
    auto known_json = nlohmann::json::parse(known_file, clean_gfxr_json);

    auto diff = nlohmann::json::diff(known_json, app_json);
    ASSERT_EQ(diff.size(), 0) << diff;
}