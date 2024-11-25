#include <fstream>
#include <gtest/gtest.h>
#include <filesystem>
#include <nlohmann/json.hpp>

char const* const APP_RUN_DIRECTORY = "triangle";
char const* const APP_PATH          = "Debug/gfxrecon-testapp-triangle.exe";
char const* const CAPTURE_FILE      = "triangle.gfxr";
char const* const KNOWN_GFXR_PATH   = "triangle.gfxr";

char const* APP_PATH_BASE        = std::getenv("APP_PATH_BASE");
char const* KNOWN_GFXR_PATH_BASE = std::getenv("KNOWN_GFXR_PATH_BASE");
char const* MOCK_DRIVER_PATH     = std::getenv("MOCK_DRIVER_PATH");
char const* GFXR_LAYER_PATH      = std::getenv("GFXR_LAYER_PATH");
char const* GFXR_CONVERT_PATH    = std::getenv("GFXR_CONVERT_PATH");

void execute(std::string const& command) {}

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

TEST(Triangle, CorrectGFXR)
{
    std::filesystem::path app_run_directory{ APP_PATH_BASE };
    app_run_directory.append(APP_RUN_DIRECTORY);

    std::filesystem::path app_path{ app_run_directory };
    app_path.append(APP_PATH);

    std::string app_command;
    app_command += "set \"VK_DRIVER_FILES=";
    app_command += MOCK_DRIVER_PATH;
    app_command += "\" & set \"VK_LAYER_PATH=";
    app_command += GFXR_LAYER_PATH;
    app_command += "\" & set \"VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct\"";
    app_command += " & set \"GFXRECON_CAPTURE_FILE=";
    app_command += CAPTURE_FILE;
    app_command += "\" & set \"GFXRECON_CAPTURE_FILE_TIMESTAMP=false\"";
    app_command += " & cd ";
    app_command += app_run_directory.string();
    app_command += " & ";
    app_command += app_path.string();
    auto app_result = std::system(app_command.c_str());
    ASSERT_EQ(app_result, 0) << "command failed " << app_command;

    std::filesystem::path capture_path{ app_run_directory };
    capture_path.append(CAPTURE_FILE);
    std::string app_convert_command;
    app_convert_command += GFXR_CONVERT_PATH;
    app_convert_command += " ";
    app_convert_command += capture_path.string();
    auto app_convert_result = std::system(app_convert_command.c_str());
    ASSERT_EQ(app_convert_result, 0) << "command failed " << app_convert_command;

    std::filesystem::path known_good_path{ KNOWN_GFXR_PATH_BASE };
    known_good_path.append(KNOWN_GFXR_PATH);
    std::string known_good_convert_command;
    known_good_convert_command += GFXR_CONVERT_PATH;
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
