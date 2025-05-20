#include "verify-gfxr.h"

#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <stdlib.h>

#include <util/logging.h>

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
        default:
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
    std::filesystem::path working_directory{ base_path };
    std::filesystem::path full_app_directory{ base_path };
    std::filesystem::path full_executable_path;
    std::filesystem::path convert_path{ base_path };
    std::filesystem::path capture_path{ base_path };
    std::filesystem::path known_good_path{ base_path };
    std::filesystem::path app_json_path;
    std::filesystem::path known_good_json_path;

    std::filesystem::path capture_trimming_path{ base_path };
    std::filesystem::path known_good_trimming_path{ base_path };
    std::filesystem::path app_trimming_json_path;
    std::filesystem::path known_good_trimming_json_path;

    void trimming_paths(char const* test_name, char const* known_gfxr_path, char const* trimming_frames)
    {
        // Trimming suffix is like "_frame_10" or "_frames_10_through_100"
        std::string s_trimming_frames = trimming_frames;
        std::string trimming_suffix   = "_frame";
        std::string range_begin       = "";
        std::string range_end         = "";

        auto index = s_trimming_frames.find("-");
        if (index == std::string::npos)
        {
            range_begin = s_trimming_frames;
        }
        else
        {
            range_begin = s_trimming_frames.substr(0, index);
            range_end   = s_trimming_frames.substr(index + 1);
        }

        if (!range_end.empty())
        {
            trimming_suffix += "s";
        }
        trimming_suffix += "_";
        trimming_suffix += range_begin;
        if (!range_end.empty())
        {
            trimming_suffix += "_through_";
            trimming_suffix += range_end;
        }

        std::string capture_trimming_file = "actual";
        capture_trimming_file += trimming_suffix;
        capture_trimming_file += ".gfxr";
        capture_trimming_path.append("test_apps");
        capture_trimming_path.append(test_name);
        capture_trimming_path.append(capture_trimming_file);

        std::string s_known_gfxr_path        = known_gfxr_path;
        index                                = s_known_gfxr_path.find(".gfxr");
        std::string known_gfxr_trimming_path = s_known_gfxr_path.substr(0, index);
        known_gfxr_trimming_path += trimming_suffix;
        known_gfxr_trimming_path += ".gfxr";
        known_good_trimming_path.append("known_good");
        known_good_trimming_path.append(known_gfxr_trimming_path);

        app_trimming_json_path = std::filesystem::path{ capture_trimming_path };
        app_trimming_json_path.replace_extension(".json");

        known_good_trimming_json_path = std::filesystem::path{ known_good_trimming_path };
        known_good_trimming_json_path.replace_extension(".json");
    }

    Paths(char const* test_name, char const* known_gfxr_path, char const* trimming_frames)
    {
        full_app_directory.append("test_apps");
        working_directory = full_app_directory;
        working_directory.append("res");

        full_app_directory.append("launcher");
        full_executable_path = full_app_directory;

#ifdef WIN32
        full_executable_path.append("gfxrecon-test-launcher.exe");
#else
        full_executable_path.append("gfxrecon-test-launcher");
#endif

        convert_path.append(CONVERT_FILENAME);

        capture_path.append("test_apps");
        capture_path.append(test_name);
        std::string gfxr_file_name = test_name + std::string(".gfxr");
        capture_path.append(gfxr_file_name);

        known_good_path.append("known_good");
        known_good_path.append(known_gfxr_path);

        app_json_path = std::filesystem::path{ capture_path };
        app_json_path.replace_extension(".json");

        known_good_json_path = std::filesystem::path{ known_good_path };
        known_good_json_path.replace_extension(".json");

        if (trimming_frames)
        {
            trimming_paths(test_name, known_gfxr_path, trimming_frames);
        }
    }
};

// destructor unsets all env vars. It helps when the user forget to unset to affect the other tests.
class EnvironmentVariables
{
  private:
    std::unordered_map<std::string, std::string> env_vars;

  public:
    ~EnvironmentVariables()
    {
        for (auto& env_var : env_vars)
        {
#if defined(__linux__) || defined(__APPLE__)
            unsetenv(env_var.first.c_str());
#elif defined(_WIN32)
            _putenv_s(env_var.first.c_str(), "");
#else
#error "Unsupported platform"
#endif
        }
        env_vars.clear();
    }

    void SetEnv(const char* env_name, const char* env_var)
    {
#if defined(__linux__) || defined(__APPLE__)
        ASSERT_EQ(setenv(env_name, env_var, 1), 0) << "set env var: " << env_name << ": " << env_var << " failed.";
#elif defined(_WIN32)
        ASSERT_EQ(_putenv_s(env_name, env_var), 0) << "set env var: " << env_name << ": " << env_var << " failed.";
#else
#error "Unsupported platform"
#endif
        env_vars.insert(std::pair(env_name, env_var));
    }

    void UnsetEnv(const char* env_name)
    {
#if defined(__linux__) || defined(__APPLE__)
        ASSERT_EQ(unsetenv(env_name), 0) << "unset env var: " << env_name << " failed.";
#elif defined(_WIN32)
        ASSERT_EQ(_putenv_s(env_name, ""), 0) << "unset env var: " << env_name << " failed.";
#else
#error "Unsupported platform"
#endif
        auto entry = env_vars.find(env_name);
        if (entry != env_vars.end())
        {
            env_vars.erase(entry);
        }
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

void run_in_background(const char* test_name)
{
    Paths paths{ test_name, "", nullptr };
    run_command(paths.working_directory, paths.full_executable_path, { test_name, "&" });
}

void run_trimming_app(const Paths& paths, const char* test_name, char const* trimming_frames)
{
    EnvironmentVariables env_vars;

    // To not affect the other tests, set env var programmatically, and unset it when it isn't needed.
    env_vars.SetEnv("GFXRECON_CAPTURE_FRAMES", trimming_frames);

    auto result = run_command(paths.working_directory, paths.full_executable_path, { test_name });
    ASSERT_EQ(result, 0) << "trimming command failed " << paths.full_executable_path << " in path "
                         << paths.working_directory;

    env_vars.UnsetEnv("GFXRECON_CAPTURE_FRAMES");

    // convert actual gfxr
    result = run_command(paths.base_path, paths.convert_path, { paths.capture_trimming_path.string() });
    ASSERT_EQ(result, 0) << "trimming command failed " << paths.convert_path << " " << paths.capture_trimming_path
                         << " in path " << paths.base_path;

    // convert known good gfxr
    result = run_command(paths.base_path, paths.convert_path, { paths.known_good_trimming_path.string() });
    ASSERT_EQ(result, 0) << "trimming command failed " << paths.convert_path << " " << paths.known_good_trimming_path
                         << " in path " << paths.base_path;

    std::ifstream app_trimming_file{ paths.app_trimming_json_path };
    ASSERT_TRUE(app_trimming_file.is_open())
        << "app trimming json file: " << paths.app_trimming_json_path << " would not open";
    auto app_trimming_json = nlohmann::json::parse(app_trimming_file, clean_gfxr_json);

    std::ifstream known_trimming_file{ paths.known_good_trimming_json_path };
    ASSERT_TRUE(known_trimming_file.is_open())
        << "known good trimming json file: " << paths.known_good_trimming_json_path << " would not open ";
    auto known_trimming_json = nlohmann::json::parse(known_trimming_file, clean_gfxr_json);

    auto trimming_diff = nlohmann::json::diff(known_trimming_json, app_trimming_json);
    ASSERT_EQ(trimming_diff.size(), 0) << std::setw(4) << trimming_diff;
}

void verify_gfxr(const char* test_name, char const* known_gfxr_path, char const* trimming_frames)
{
    Paths paths{ test_name, known_gfxr_path, trimming_frames };
    int   result;

    // run app
    setenv("GFXRECON_CAPTURE_FILE", paths.capture_path.c_str(), 1);
    result = run_command(paths.working_directory, paths.full_executable_path, { test_name });
    ASSERT_EQ(result, 0) << "command failed " << paths.full_executable_path << " " << test_name << " in path "
                         << paths.working_directory;

    // convert actual gfxr
    result = run_command(paths.base_path, paths.convert_path, { paths.capture_path.string() });
    ASSERT_EQ(result, 0) << "command failed " << paths.convert_path << " " << paths.capture_path << " in path "
                         << paths.base_path;

    // convert known good gfxr
    result = run_command(paths.base_path, paths.convert_path, { paths.known_good_path.string() });
    ASSERT_EQ(result, 0) << "command failed " << paths.convert_path << " " << paths.known_good_path << " in path "
                         << paths.base_path;

    std::ifstream app_file{ paths.app_json_path };
    ASSERT_TRUE(app_file.is_open()) << "app json file: " << paths.app_json_path << " would not open";
    auto app_json = nlohmann::json::parse(app_file, clean_gfxr_json);

    std::ifstream known_file{ paths.known_good_json_path };
    ASSERT_TRUE(known_file.is_open()) << "known good json file: " << paths.known_good_json_path << " would not open";
    auto known_json = nlohmann::json::parse(known_file, clean_gfxr_json);

    auto diff = nlohmann::json::diff(known_json, app_json);
    ASSERT_EQ(diff.size(), 0) << std::setw(4) << diff;

    if (trimming_frames)
    {
        run_trimming_app(paths, test_name, trimming_frames);
    }
}
