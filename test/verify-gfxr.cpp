#include "verify-gfxr.h"

#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <stdlib.h>

#include <util/logging.h>

// Keys whose values differ between two captures of one app, or between two machines. The comparison
// drops each of them wherever it appears.
static const char* const kIgnoredKeys[] = {
    "api_version",         // The version that the layer reports. It moves with every header update.
    "apiVersion",          // The same value in VkApplicationInfo and VkPhysicalDeviceProperties.
    "hinstance",           // Win32 handles differ per process.
    "hwnd",                //
    "pipelineCacheUUID",   // Driver identity.
    "pipeline_cache_uuid", //
    "ppData",              // Host pointers that vkMapMemory returns.
    "fd",                  // File descriptors from an external memory export.
    "app_name",            // The path of the launcher differs per machine.
};

// A key that starts with one of these names a function pointer, which differs per process.
static const char* const kIgnoredKeyPrefixes[] = { "pfn" };

// A top-level block that holds one of these keys is dropped whole. The header carries the source
// path and the tool version. An annotation carries per-run text.
static const char* const kIgnoredBlockKeys[] = { "header", "annotation" };

// The Android hardware buffer import struct and the AHB properties query carry a "buffer" field that
// is a host pointer. Only that "buffer" must go. The value that names the struct or the call arrives
// first, and the "buffer" key arrives in a later event.
static const char* const kAhbBufferMarkers[] = { "VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID",
                                                 "vkGetAndroidHardwareBufferPropertiesANDROID" };

static bool is_ignored_key(const std::string& key)
{
    for (const char* ignored : kIgnoredKeys)
    {
        if (key == ignored)
        {
            return true;
        }
    }
    for (const char* prefix : kIgnoredKeyPrefixes)
    {
        if (key.rfind(prefix, 0) == 0)
        {
            return true;
        }
    }
    return false;
}

bool clean_gfxr_json(int depth, nlohmann::json::parse_event_t event, nlohmann::json& parsed)
{
    // The marker value and the "buffer" key arrive in separate events. This flag carries the state
    // between them, and the "buffer" key resets it.
    static bool skip_next_buffer = false;

    switch (event)
    {
        case nlohmann::json::parse_event_t::key:
        {
            const std::string key = parsed.get<std::string>();
            if (is_ignored_key(key))
            {
                return false;
            }
            if (skip_next_buffer && key == "buffer")
            {
                skip_next_buffer = false;
                return false;
            }
            break;
        }
        case nlohmann::json::parse_event_t::value:
        {
            if (parsed.is_string())
            {
                const std::string value = parsed.get<std::string>();
                for (const char* marker : kAhbBufferMarkers)
                {
                    if (value == marker)
                    {
                        skip_next_buffer = true;
                    }
                }
            }
            break;
        }
        case nlohmann::json::parse_event_t::object_end:
        {
            if (depth == 1)
            {
                for (const char* block_key : kIgnoredBlockKeys)
                {
                    if (parsed.contains(block_key))
                    {
                        return false;
                    }
                }
            }
            break;
        }
        default:
            break;
    }

    return true;
}

#if defined(__linux__) || defined(__APPLE__)
static char const* CONVERT_FILENAME = "gfxrecon-convert";
static char const* REPLAY_FILENAME  = "gfxrecon-replay";
#elif defined(_WIN32)
static char const* CONVERT_FILENAME = "gfxrecon-convert.exe";
static char const* REPLAY_FILENAME  = "gfxrecon-replay.exe";
#endif

struct Paths
{
    std::filesystem::path base_path{ std::filesystem::current_path() };
    std::filesystem::path working_directory{ base_path };
    std::filesystem::path full_app_directory{ base_path };
    std::filesystem::path full_executable_path;
    std::filesystem::path convert_path{ base_path };
    std::filesystem::path replay_path{ base_path };
    std::filesystem::path capture_path{ base_path };
    std::filesystem::path known_good_path{ base_path };
    std::filesystem::path app_json_path;
    std::filesystem::path known_good_json_path;

    std::filesystem::path capture_trimming_path{ base_path };
    std::filesystem::path known_good_trimming_path{ base_path };
    std::filesystem::path app_trimming_json_path;
    std::filesystem::path known_good_trimming_json_path;

    void trimming_paths(char const* test_name, char const* trimming_frames, bool trigger_trimming)
    {
        std::string trimming_suffix;
        if (trimming_frames != nullptr)
        {
            GFXRECON_ASSERT(!trigger_trimming);

            // Trimming suffix is like "_frame_10" or "_frames_10_through_100"
            std::string s_trimming_frames = trimming_frames;
            trimming_suffix               = "_frame";
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
        }
        else if (trigger_trimming)
        {
            trimming_suffix = "_trim_trigger";
        }

        std::string capture_trimming_file = test_name + trimming_suffix;
        capture_trimming_file += ".gfxr";
        capture_trimming_path.append(capture_trimming_file);

        known_good_trimming_path.append("known_good");
        known_good_trimming_path.append(capture_trimming_file);

        app_trimming_json_path = std::filesystem::path{ capture_trimming_path };
        app_trimming_json_path.replace_extension(".json");

        known_good_trimming_json_path = std::filesystem::path{ known_good_trimming_path };
        known_good_trimming_json_path.replace_extension(".json");
    }

    Paths(char const* test_name, char const* trimming_frames, bool trigger_trimming)
    {
        working_directory = full_app_directory;
        working_directory.append("res");
        full_app_directory.append("test_apps");

        full_app_directory.append("launcher");
        full_executable_path = full_app_directory;

#ifdef WIN32
        full_executable_path.append("gfxrecon-test-launcher.exe");
#else
        full_executable_path.append("gfxrecon-test-launcher");
#endif

        convert_path.append(CONVERT_FILENAME);
        replay_path.append(REPLAY_FILENAME);

        std::string gfxr_file_name = test_name + std::string(".gfxr");
        capture_path.append(gfxr_file_name);

        known_good_path.append("known_good");
        known_good_path.append(gfxr_file_name);

        app_json_path = std::filesystem::path{ capture_path };
        app_json_path.replace_extension(".json");

        known_good_json_path = std::filesystem::path{ known_good_path };
        known_good_json_path.replace_extension(".json");

        if (trimming_frames != nullptr || trigger_trimming)
        {
            trimming_paths(test_name, trimming_frames, trigger_trimming);
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

// Remove the outputs of an earlier run. When they stay in place and the app writes no capture, the
// convert step reads the old file and the case passes for the wrong reason.
void remove_previous_outputs(std::initializer_list<std::filesystem::path> paths)
{
    for (const auto& path : paths)
    {
        std::error_code error;
        std::filesystem::remove(path, error);
    }
}

void run_in_background(const char* test_name)
{
    Paths paths{ test_name, nullptr, false };
    run_command(paths.working_directory, paths.full_executable_path, { test_name, "&" });
}

void run_trimming_app(const Paths& paths, const char* test_name, char const* trimming_frames, bool trigger_trimming)
{
    EnvironmentVariables env_vars;

    // To not affect the other tests, set env var programmatically, and unset it when it isn't needed.
    if (trimming_frames != nullptr)
    {
        env_vars.SetEnv("GFXRECON_CAPTURE_FRAMES", trimming_frames);
    }
    else
    {
        GFXRECON_ASSERT(trigger_trimming);
        env_vars.SetEnv("GFXRECON_CAPTURE_TRIGGER", "F12");
    }

    remove_previous_outputs(
        { paths.capture_trimming_path, paths.app_trimming_json_path, paths.known_good_trimming_json_path });

    auto result = run_command(paths.working_directory, paths.full_executable_path, { test_name });
    ASSERT_EQ(result, 0) << "trimming command failed " << paths.full_executable_path << " in path "
                         << paths.working_directory;
    ASSERT_TRUE(std::filesystem::exists(paths.capture_trimming_path))
        << "trimmed capture file was not produced: " << paths.capture_trimming_path;

    env_vars.UnsetEnv("GFXRECON_CAPTURE_FRAMES");
    env_vars.UnsetEnv("GFXRECON_CAPTURE_TRIGGER");

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

void verify_gfxr(const char* test_name, char const* trimming_frames, bool trigger_trimming)
{
    EnvironmentVariables env_vars;

    Paths paths{ test_name, trimming_frames, trigger_trimming };
    int   result;

    bool workind_directory_exists = std::filesystem::exists(paths.working_directory);
    ASSERT_TRUE(workind_directory_exists) << "working directory does not exist: " << paths.working_directory;

    remove_previous_outputs({ paths.capture_path, paths.app_json_path, paths.known_good_json_path });

    // run app
    env_vars.SetEnv("GFXRECON_CAPTURE_FILE", paths.capture_path.string().c_str());
    result = run_command(paths.working_directory, paths.full_executable_path, { test_name });
    ASSERT_EQ(result, 0) << "command failed " << paths.full_executable_path << " " << test_name << " in path "
                         << paths.working_directory;
    ASSERT_TRUE(std::filesystem::exists(paths.capture_path)) << "capture file was not produced: " << paths.capture_path;

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

    if (trimming_frames || trigger_trimming)
    {
        run_trimming_app(paths, test_name, trimming_frames, trigger_trimming);
    }
}

void capture_and_replay(const char* test_name, std::vector<std::string> extra_replay_args)
{
    EnvironmentVariables env_vars;

    Paths paths{ test_name, nullptr, false };
    int   result;

    bool working_directory_exists = std::filesystem::exists(paths.working_directory);
    ASSERT_TRUE(working_directory_exists) << "working directory does not exist: " << paths.working_directory;

    std::filesystem::path replay_capture_path{ paths.base_path };
    replay_capture_path.append(test_name + std::string("_replay.gfxr"));
    remove_previous_outputs({ paths.capture_path, replay_capture_path });

    // Run the app with capture enabled to produce the gfxr to replay.
    env_vars.SetEnv("GFXRECON_CAPTURE_FILE", paths.capture_path.string().c_str());
    result = run_command(paths.working_directory, paths.full_executable_path, { test_name });
    ASSERT_EQ(result, 0) << "capture command failed " << paths.full_executable_path << " " << test_name << " in path "
                         << paths.working_directory;

    ASSERT_TRUE(std::filesystem::exists(paths.capture_path)) << "capture file was not produced: " << paths.capture_path;

    // The gfxreconstruct capture layer is still enabled in the environment, so point GFXRECON_CAPTURE_FILE at a
    // throwaway path for the replay step. This keeps the layer (if it loads during replay) from re-capturing over the
    // input gfxr we are about to read.
    env_vars.SetEnv("GFXRECON_CAPTURE_FILE", replay_capture_path.string().c_str());

    // Replay the capture headless (offscreen swapchain) against the mock ICD, forwarding any extra arguments.
    // Asserts the replay tool exits successfully (no crash, assertion, or replay error).
    std::vector<std::string> replay_args = { "--swapchain", "offscreen" };
    replay_args.insert(replay_args.end(), extra_replay_args.begin(), extra_replay_args.end());
    replay_args.push_back(paths.capture_path.string());

    result = run_command(paths.base_path, paths.replay_path, replay_args);
    ASSERT_EQ(result, 0) << "replay command failed " << paths.replay_path << " for capture " << paths.capture_path
                         << " in path " << paths.base_path;
}
