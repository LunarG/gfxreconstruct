#include "verify-gfxr.h"

#include <gtest/gtest.h>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <filesystem>
#include <system_error>
#include <nlohmann/json.hpp>
#include <stdlib.h>

#include <format/format_json.h>
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
    if (std::any_of(
            std::begin(kIgnoredKeys), std::end(kIgnoredKeys), [&](const char* ignored) { return key == ignored; }))
    {
        return true;
    }
    return std::any_of(std::begin(kIgnoredKeyPrefixes), std::end(kIgnoredKeyPrefixes), [&](const char* prefix) {
        return key.starts_with(prefix);
    });
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
                if (std::any_of(std::begin(kAhbBufferMarkers), std::end(kAhbBufferMarkers), [&](const char* marker) {
                        return value == marker;
                    }))
                {
                    skip_next_buffer = true;
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
static const char* CONVERT_FILENAME = "gfxrecon-convert";
static const char* REPLAY_FILENAME  = "gfxrecon-replay";
#elif defined(_WIN32)
static const char* CONVERT_FILENAME = "gfxrecon-convert.exe";
static const char* REPLAY_FILENAME  = "gfxrecon-replay.exe";
#endif

// The name of the running gtest case as a file name part, for example
// "CaptureApps_Serialized.CorrectGFXR_triangle". Every output file of a case carries it, so cases
// that share an app and run in parallel under ctest never touch each other's files.
static std::string current_test_id()
{
    const testing::TestInfo* info = testing::UnitTest::GetInstance()->current_test_info();
    std::string id = info != nullptr ? std::string(info->test_suite_name()) + "." + info->name() : "no_test";
    for (char& c : id)
    {
        if (!std::isalnum(static_cast<unsigned char>(c)) && c != '.' && c != '_' && c != '-')
        {
            c = '_';
        }
    }
    return id;
}

struct Paths
{
    // "<app>.<test id>", the stem of every file this case writes.
    std::string output_stem;

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

    void trimming_paths(const char* test_name, const char* trimming_frames, bool trigger_trimming)
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

        // The layer puts the trimming suffix before the extension of GFXRECON_CAPTURE_FILE.
        capture_trimming_path.append(output_stem + trimming_suffix + ".gfxr");

        known_good_trimming_path.append("known_good");
        known_good_trimming_path.append(test_name + trimming_suffix + ".gfxr");

        app_trimming_json_path = std::filesystem::path{ capture_trimming_path };
        app_trimming_json_path.replace_extension(".json");

        // The converted known good goes next to the capture, under the case's name, and not next to
        // the known-good file, which every case of this app would share.
        known_good_trimming_json_path = base_path;
        known_good_trimming_json_path.append(output_stem + trimming_suffix + ".known_good.json");
    }

    Paths(const char* test_name, const char* trimming_frames, bool trigger_trimming)
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

        output_stem = std::string(test_name) + "." + current_test_id();
        capture_path.append(output_stem + ".gfxr");

        // The known-good file is an input and keeps the app name.
        known_good_path.append("known_good");
        known_good_path.append(test_name + std::string(".gfxr"));

        app_json_path = std::filesystem::path{ capture_path };
        app_json_path.replace_extension(".json");

        known_good_json_path = base_path;
        known_good_json_path.append(output_stem + ".known_good.json");

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

int run_command(const std::filesystem::path& working_directory,
                const std::filesystem::path& command,
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
static void remove_previous_outputs(std::initializer_list<std::filesystem::path> paths)
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

void run_trimming_app(const Paths& paths, const char* test_name, const char* trimming_frames, bool trigger_trimming)
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
    result = run_command(paths.base_path,
                         paths.convert_path,
                         { "--output", paths.app_trimming_json_path.string(), paths.capture_trimming_path.string() });
    ASSERT_EQ(result, 0) << "trimming command failed " << paths.convert_path << " " << paths.capture_trimming_path
                         << " in path " << paths.base_path;

    // convert known good gfxr
    result = run_command(
        paths.base_path,
        paths.convert_path,
        { "--output", paths.known_good_trimming_json_path.string(), paths.known_good_trimming_path.string() });
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

void verify_gfxr(const char* test_name, const char* trimming_frames, bool trigger_trimming)
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
    result = run_command(
        paths.base_path, paths.convert_path, { "--output", paths.app_json_path.string(), paths.capture_path.string() });
    ASSERT_EQ(result, 0) << "command failed " << paths.convert_path << " " << paths.capture_path << " in path "
                         << paths.base_path;

    // convert known good gfxr
    result = run_command(paths.base_path,
                         paths.convert_path,
                         { "--output", paths.known_good_json_path.string(), paths.known_good_path.string() });
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

static void run_capture_app(EnvironmentVariables& env_vars, const Paths& paths, const char* test_name)
{
    bool working_directory_exists = std::filesystem::exists(paths.working_directory);
    ASSERT_TRUE(working_directory_exists) << "working directory does not exist: " << paths.working_directory;

    // Remove stale captures so a failure to produce a capture file assume the stale capture was the one produced.
    std::error_code remove_error;
    std::filesystem::remove(paths.capture_path, remove_error);
    ASSERT_FALSE(remove_error) << "could not remove stale capture file: " << paths.capture_path << " - "
                               << remove_error.message();

    // Run the app with capture enabled to produce the gfxr to replay.
    env_vars.SetEnv("GFXRECON_CAPTURE_FILE", paths.capture_path.string().c_str());
    auto result = run_command(paths.working_directory, paths.full_executable_path, { test_name });
    ASSERT_EQ(result, 0) << "capture command failed " << paths.full_executable_path << " " << test_name << " in path "
                         << paths.working_directory;

    ASSERT_TRUE(std::filesystem::exists(paths.capture_path)) << "capture file was not produced: " << paths.capture_path;
}

static void run_replay(const Paths& paths, const std::vector<std::string>& extra_replay_args)
{
    std::vector<std::string> replay_args = { "--swapchain", "offscreen" };
    replay_args.insert(replay_args.end(), extra_replay_args.begin(), extra_replay_args.end());
    replay_args.push_back(paths.capture_path.string());

    auto result = run_command(paths.base_path, paths.replay_path, replay_args);
    ASSERT_EQ(result, 0) << "replay command failed " << paths.replay_path << " for capture " << paths.capture_path
                         << " in path " << paths.base_path;
}

void verify_gfxr_serialized(const char* test_name)
{
    EnvironmentVariables env_vars;
    env_vars.SetEnv("GFXRECON_FORCE_COMMAND_SERIALIZATION", "true");
    verify_gfxr(test_name);
}

void verify_no_capture(const char* test_name)
{
    EnvironmentVariables env_vars;

    Paths paths{ test_name, nullptr, false };

    bool working_directory_exists = std::filesystem::exists(paths.working_directory);
    ASSERT_TRUE(working_directory_exists) << "working directory does not exist: " << paths.working_directory;

    // The layer's own log proves that the layer loaded and chose to stay passive. Without it, a run
    // with no layer at all would also produce no capture file and pass.
    std::filesystem::path layer_log_path{ paths.base_path };
    layer_log_path.append(paths.output_stem + ".layer.log");
    remove_previous_outputs({ paths.capture_path, layer_log_path });

    // The launcher is named gfxrecon-test-launcher, so this name never matches.
    env_vars.SetEnv("GFXRECON_CAPTURE_PROCESS_NAME", "gfxrecon-no-such-process");
    env_vars.SetEnv("GFXRECON_CAPTURE_FILE", paths.capture_path.string().c_str());
    env_vars.SetEnv("GFXRECON_LOG_FILE", layer_log_path.string().c_str());
    int result = run_command(paths.working_directory, paths.full_executable_path, { test_name });
    ASSERT_EQ(result, 0) << "command failed " << paths.full_executable_path << " " << test_name << " in path "
                         << paths.working_directory;
    ASSERT_FALSE(std::filesystem::exists(paths.capture_path))
        << "capture file was produced with a process name that does not match: " << paths.capture_path;

    std::ifstream layer_log_file{ layer_log_path };
    ASSERT_TRUE(layer_log_file.is_open()) << "the layer wrote no log file, so it did not load: " << layer_log_path;
    const std::string layer_log{ std::istreambuf_iterator<char>(layer_log_file), std::istreambuf_iterator<char>() };
    EXPECT_NE(layer_log.find("Initializing GFXReconstruct capture layer"), std::string::npos)
        << "the layer did not log its initialization: " << layer_log_path;
    EXPECT_NE(layer_log.find("does not match current process"), std::string::npos)
        << "the layer did not log the process name mismatch: " << layer_log_path;
    EXPECT_EQ(layer_log.find("Recording graphics API capture"), std::string::npos)
        << "the layer started a capture with a process name that does not match: " << layer_log_path;
}

void capture_and_replay(const char* test_name, std::vector<std::string> extra_replay_args)
{
    EnvironmentVariables env_vars;
    Paths                paths{ test_name, nullptr, false };

    ASSERT_NO_FATAL_FAILURE(run_capture_app(env_vars, paths, test_name));

    // The gfxreconstruct capture layer is still enabled in the environment, so point GFXRECON_CAPTURE_FILE at a
    // throwaway path for the replay step. This keeps the layer (if it loads during replay) from re-capturing over the
    // input gfxr we are about to read.
    std::filesystem::path replay_capture_path{ paths.base_path };
    replay_capture_path.append(paths.capture_path.stem().string() + "_replay.gfxr");
    env_vars.SetEnv("GFXRECON_CAPTURE_FILE", replay_capture_path.string().c_str());

    ASSERT_NO_FATAL_FAILURE(run_replay(paths, extra_replay_args));
}

static void count_calls_in_json(const std::filesystem::path&     json_path,
                                const std::vector<std::string>&  function_names,
                                std::map<std::string, uint32_t>& counts)
{
    std::ifstream json_file{ json_path };
    ASSERT_TRUE(json_file.is_open()) << "converted json file: " << json_path << " would not open";

    auto json = nlohmann::json::parse(json_file);

    counts.clear();
    for (const auto& function_name : function_names)
    {
        counts[function_name] = 0;
    }

    for (const auto& block : json)
    {
        auto function = block.find(gfxrecon::format::kNameFunction);
        if (function == block.end())
        {
            continue;
        }

        auto name = function->find(gfxrecon::format::kNameName);
        if (name == function->end() || !name->is_string())
        {
            continue;
        }

        auto entry = counts.find(name->get<std::string>());
        if (entry != counts.end())
        {
            ++entry->second;
        }
    }
}

void capture_app(const char* test_name)
{
    EnvironmentVariables env_vars;
    Paths                paths{ test_name, nullptr, false };

    ASSERT_NO_FATAL_FAILURE(run_capture_app(env_vars, paths, test_name));
}

void replay_and_count_recapture(const char*                      test_name,
                                std::vector<std::string>         extra_replay_args,
                                const std::string&               recapture_suffix,
                                const std::vector<std::string>&  function_names,
                                std::map<std::string, uint32_t>& counts)
{
    EnvironmentVariables env_vars;
    Paths                paths{ test_name, nullptr, false };

    ASSERT_TRUE(std::filesystem::exists(paths.capture_path))
        << "no capture to replay: " << paths.capture_path << " - call capture_app() first";

    std::filesystem::path recapture_path{ paths.base_path };
    recapture_path.append(paths.capture_path.stem().string() + recapture_suffix + ".gfxr");

    // Remove stale recaptures so the counts cannot come from a stale file.
    std::error_code remove_error;
    std::filesystem::remove(recapture_path, remove_error);
    ASSERT_FALSE(remove_error) << "could not remove stale recapture file: " << recapture_path << " - "
                               << remove_error.message();

    // The gfxreconstruct capture layer is still enabled in the environment, so the replay process is itself captured
    // into this file. Pointing the layer here also keeps it from re-capturing over the input gfxr we are about to read.
    env_vars.SetEnv("GFXRECON_CAPTURE_FILE", recapture_path.string().c_str());

    ASSERT_NO_FATAL_FAILURE(run_replay(paths, extra_replay_args));

    ASSERT_TRUE(std::filesystem::exists(recapture_path))
        << "the replay was not recaptured into " << recapture_path
        << ": the gfxreconstruct capture layer did not load during replay";

    // convert the recapture
    auto result = run_command(paths.base_path, paths.convert_path, { recapture_path.string() });
    ASSERT_EQ(result, 0) << "command failed " << paths.convert_path << " " << recapture_path << " in path "
                         << paths.base_path;

    std::filesystem::path recapture_json_path{ recapture_path };
    recapture_json_path.replace_extension(".json");

    ASSERT_NO_FATAL_FAILURE(count_calls_in_json(recapture_json_path, function_names, counts));
}

// Keeps every block of a screenshot results json but the header: its versions, capture path and options differ
// between builds and machines, while the frame blocks and the summary are what the test checks.
static bool clean_screenshot_json(int depth, nlohmann::json::parse_event_t event, nlohmann::json& parsed)
{
    if (event == nlohmann::json::parse_event_t::object_end && depth == 1 && parsed.contains("header"))
    {
        return false;
    }
    return true;
}

void capture_and_verify_screenshots(const char* test_name, std::vector<std::string> screenshot_args)
{
    EnvironmentVariables env_vars;

    Paths paths{ test_name, nullptr, false };
    int   result;

    bool working_directory_exists = std::filesystem::exists(paths.working_directory);
    ASSERT_TRUE(working_directory_exists) << "working directory does not exist: " << paths.working_directory;

    std::filesystem::path replay_capture_path{ paths.base_path };
    replay_capture_path.append(paths.output_stem + "_replay.gfxr");
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

    // The screenshots and the results json carry this prefix and land in the test directory, where replay runs. With
    // no --screenshot-dir the file names in the json hold no path separator, so they match on every platform.
    const std::string     prefix = test_name + std::string("-screenshots");
    std::filesystem::path result_json_path{ paths.base_path };
    result_json_path.append(prefix + ".json");

    // A replay that fails to write the json must not pass against the file of an earlier run.
    std::filesystem::remove(result_json_path);

    std::vector<std::string> replay_args = {
        "--swapchain", "offscreen", "--screenshot-prefix", prefix, "--screenshot-results"
    };
    replay_args.insert(replay_args.end(), screenshot_args.begin(), screenshot_args.end());
    replay_args.push_back(paths.capture_path.string());

    result = run_command(paths.base_path, paths.replay_path, replay_args);
    ASSERT_EQ(result, 0) << "replay command failed " << paths.replay_path << " for capture " << paths.capture_path
                         << " in path " << paths.base_path;

    std::ifstream result_file{ result_json_path };
    ASSERT_TRUE(result_file.is_open()) << "screenshot results json: " << result_json_path << " would not open";
    auto result_json = nlohmann::json::parse(result_file, clean_screenshot_json);

    std::filesystem::path reference_json_path{ paths.base_path };
    reference_json_path.append("known_good");
    reference_json_path.append("screenshots");
    reference_json_path.append(test_name + std::string(".json"));

    std::ifstream reference_file{ reference_json_path };
    ASSERT_TRUE(reference_file.is_open())
        << "reference screenshot results json: " << reference_json_path << " would not open";
    auto reference_json = nlohmann::json::parse(reference_file, clean_screenshot_json);

    auto diff = nlohmann::json::diff(reference_json, result_json);
    ASSERT_EQ(diff.size(), 0) << std::setw(4) << diff;

    // Every output the json reports as written must be on disk.
    for (const auto& block : result_json)
    {
        if (!block.contains("outputs"))
        {
            continue;
        }

        for (const auto& output : block["outputs"])
        {
            if (output.value("status", "") != "written")
            {
                continue;
            }

            std::filesystem::path file_path{ paths.base_path };
            file_path.append(output["file"].get<std::string>());
            ASSERT_TRUE(std::filesystem::exists(file_path))
                << "screenshot file reported as written is missing: " << file_path;
        }
    }
}
