/*
 * Copyright 2026 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if !defined(__ANDROID__) && !defined(GFXR_TEST_BYPASS_ANDROID_CHECK)
#error "This file must only be included in Android builds."
#endif

#include <gfxr/replay_event_plugin.h>
#include <util/logging.h>
#include <dlfcn.h>
#include <string>
#include <cstdlib>
#include <cinttypes>
#include <thread>
#include <chrono>
#include "renderdoc_app.h"

/**
 * @brief Struct representing the state of the RenderDoc replay capture plugin.
 *
 * This plugin hooks into replay events to trigger RenderDoc frame captures.
 *
 * NOTE: This file is designed for Android only. It intentionally uses POSIX-specific
 * dynamic loading (<dlfcn.h>) instead of cross-platform abstractions, and hardcodes
 * the Android package data path for captures.
 */
struct RenderDocCapturePlugin
{
    GfxrReplayPluginV1   base;                      ///< Base replay plugin interface.
    RENDERDOC_API_1_4_0* rdoc_api        = nullptr; ///< Pointer to the loaded RenderDoc API.
    void*                rdoc_lib_handle = nullptr; ///< Handle returned by dlopen, used to dlclose on exit.
    bool                 capture_started = false;   ///< True if a frame capture is in progress.
    bool                 capture_done    = false;   ///< True if we have finished at least one capture.
    std::string          renderdoc_lib_path;        ///< Optional custom path to the RenderDoc library.
    uint64_t target_frame = 0; ///< The 1-based relative target frame to capture. A value of 0 is a special fallback
                               ///< that means capture the first replayed frame.
    uint64_t captured_frame_index = 0; ///< The 0-based event->frame_index of the frame currently being captured.
};

/**
 * @brief Dynamically loads the RenderDoc library and retrieves its API entry points.
 *
 * It attempts to load from a custom path if configured, or falls back to RTLD_DEFAULT
 * if RenderDoc was already injected globally.
 *
 * Upon completion, if the library is successfully loaded, `plugin->rdoc_api` is populated
 * with the library's function pointers. If the API cannot be loaded, `plugin->rdoc_api`
 * remains `nullptr` and an error is safely logged.
 *
 * @param plugin Pointer to the plugin state structure.
 */
static void load_renderdoc_api(RenderDocCapturePlugin* plugin)
{
    if (plugin->rdoc_api != nullptr)
    {
        return;
    }

    pRENDERDOC_GetAPI rdoc_get_api = nullptr;

    // Try loading custom library path first if provided
    if (!plugin->renderdoc_lib_path.empty())
    {
        GFXRECON_LOG_INFO("Attempting to load RenderDoc from custom path: %s", plugin->renderdoc_lib_path.c_str());
        void* mod = dlopen(plugin->renderdoc_lib_path.c_str(), RTLD_NOW);
        if (mod != nullptr)
        {
            rdoc_get_api = reinterpret_cast<pRENDERDOC_GetAPI>(dlsym(mod, "RENDERDOC_GetAPI"));
            if (rdoc_get_api != nullptr)
            {
                plugin->rdoc_lib_handle = mod;
            }
            else
            {
                dlclose(mod);
            }
        }
        else
        {
            const char* err = dlerror();
            GFXRECON_LOG_WARNING("Failed to dlopen custom RenderDoc path: %s, error: %s",
                                 plugin->renderdoc_lib_path.c_str(),
                                 err ? err : "Unknown error");
        }
    }

    if (rdoc_get_api == nullptr)
    {
        // Try RTLD_DEFAULT first since RenderDoc layer might be globally loaded
        rdoc_get_api = reinterpret_cast<pRENDERDOC_GetAPI>(dlsym(RTLD_DEFAULT, "RENDERDOC_GetAPI"));
    }

    if (rdoc_get_api != nullptr)
    {
        int ret = rdoc_get_api(eRENDERDOC_API_Version_1_4_0, reinterpret_cast<void**>(&plugin->rdoc_api));
        if (ret == 1)
        {
            GFXRECON_LOG_INFO("Successfully loaded RenderDoc API on-demand");
            plugin->rdoc_api->SetCaptureFilePathTemplate(
                "/data/data/com.lunarg.gfxreconstruct.replay/files/gfxrecon_renderdoc_capture");
            return;
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to get RenderDoc API pointer on-demand");
            plugin->rdoc_api = nullptr;
            if (plugin->rdoc_lib_handle != nullptr)
            {
                dlclose(plugin->rdoc_lib_handle);
                plugin->rdoc_lib_handle = nullptr;
            }
        }
    }

    if (plugin->rdoc_api == nullptr)
    {
        if (plugin->renderdoc_lib_path.empty())
        {
            GFXRECON_LOG_ERROR("Failed to find RenderDoc injected globally, and no custom plugin path was provided! "
                               "You must provide the path to the RenderDoc library in the plugin arguments if it is "
                               "not injected by the system.");
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to load RenderDoc API from the provided custom path.");
        }
    }
}

/**
 * @brief Ensures the RenderDoc API is loaded and starts a frame capture if not already running.
 *
 * @param plugin Pointer to the plugin state structure.
 * @param event_type The replay event type triggering this capture (used for logging).
 * @param frame_index The frame index when the capture is started.
 */
static void ensure_api_loaded_and_start_capture(RenderDocCapturePlugin* plugin,
                                                uint32_t                event_type,
                                                uint64_t                frame_index)
{
    if (plugin->capture_started || plugin->capture_done)
    {
        return;
    }

    if (plugin->rdoc_api == nullptr)
    {
        load_renderdoc_api(plugin);
    }

    if (plugin->rdoc_api != nullptr)
    {
        GFXRECON_LOG_INFO(
            "Starting RenderDoc capture on event %u (frame_index: %" PRIu64 ")...", event_type, frame_index);
        plugin->rdoc_api->StartFrameCapture(nullptr, nullptr);
        plugin->capture_started = true;
    }
}

/**
 * @brief Stops any active capture and destroys the plugin instance.
 *
 * @param self Base interface pointer to the plugin.
 */
static void destroy(GfxrReplayPluginV1* self)
{
    if (self == NULL)
    {
        GFXRECON_LOG_ERROR("Received NULL plugin instance");
        return;
    }

    RenderDocCapturePlugin* plugin = reinterpret_cast<RenderDocCapturePlugin*>(self);
    if (plugin->rdoc_api != nullptr && (plugin->capture_started || plugin->capture_done))
    {
        if (plugin->capture_started)
        {
            GFXRECON_LOG_INFO("Stopping RenderDoc capture in destroy...");
            int result = plugin->rdoc_api->EndFrameCapture(nullptr, nullptr);
            GFXRECON_LOG_INFO("RenderDoc capture stopped in destroy. Result: %d", result);
        }

        GFXRECON_LOG_INFO("Destroying RenderDoc capture plugin, waiting for disk flush...");
        // RenderDoc writes to disk asynchronously. We cannot cleanly poll it via IsFrameCapturing.
        // Sleep briefly to afford it time before process exit.
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    else
    {
        GFXRECON_LOG_INFO("Destroying RenderDoc capture plugin (no capture performed)...");
    }

    // Intentionally omitting dlclose(plugin->rdoc_lib_handle) to avoid segfaults
    // from lingering background threads writing to disk on shutdown.

    delete plugin;
}

/**
 * @brief Handles replay events forwarded by the player.
 *
 * It initiates a frame capture when the player reaches the target frame and stops it
 * at the end of that same frame.
 *
 * @param self Base interface pointer to the plugin.
 * @param event The replay event header.
 * @return GfxrReplayPluginResult GFXR_REPLAY_PLUGIN_RESULT_OK on success, or GFXR_REPLAY_PLUGIN_RESULT_ERROR.
 */
static GfxrReplayPluginResult on_event(GfxrReplayPluginV1* self, const GfxrReplayEventHeader* event)
{
    if (self == NULL || event == NULL)
    {
        return GFXR_REPLAY_PLUGIN_RESULT_ERROR;
    }

    RenderDocCapturePlugin* plugin = reinterpret_cast<RenderDocCapturePlugin*>(self);

    switch (event->type)
    {
        case GFXR_REPLAY_EVENT_STATE_LOADING_COMPLETE:
        {
            // The presence of this event confirms we are playing a trimmed trace.

            // If a capture was started at FRAME_BEGIN, it was done under the assumption
            // that this might be an untrimmed trace. Since we just received STATE_LOADING_COMPLETE,
            // we now know it is a trimmed trace. We must discard that early capture because
            // it incorrectly contains the state setup commands.
            if (plugin->capture_started && plugin->rdoc_api != nullptr)
            {
                plugin->rdoc_api->DiscardFrameCapture(nullptr, nullptr);
                plugin->capture_started = false;
            }

            // For the first replayed frame of a trimmed trace, if we want to capture it,
            // we must start capturing immediately after state loading completes, to exclude
            // the state setup work. We expect target_frame to be a 1-based relative index,
            // so event->frame_index + 1 gives us the current relative playback frame (1, 2, ...).
            if (plugin->target_frame == 0 || plugin->target_frame == (event->frame_index + 1))
            {
                ensure_api_loaded_and_start_capture(plugin, event->type, event->frame_index);
                if (plugin->capture_started)
                {
                    plugin->captured_frame_index = event->frame_index;
                }
            }
            break;
        }
        case GFXR_REPLAY_EVENT_FRAME_BEGIN:
        {
            // If target_frame is 0 (capture first frame), we start the capture speculatively on the
            // first replayed frame because:
            // 1) For a full trace, we must start it now (at FRAME_BEGIN) or we will miss the setup.
            // 2) For a trimmed trace, this speculative capture will be discarded when
            //    STATE_LOADING_COMPLETE fires to exclude the state setup work.
            bool is_speculative_first_replayed_frame_capture_for_full_trace =
                (plugin->target_frame == 0 && event->frame_index == 0);

            // Using relative frame indexing: event->frame_index + 1 is the relative 1-based replayed frame.
            if ((plugin->target_frame != 0 && plugin->target_frame == (event->frame_index + 1)) ||
                is_speculative_first_replayed_frame_capture_for_full_trace)
            {
                ensure_api_loaded_and_start_capture(plugin, event->type, event->frame_index);
                if (plugin->capture_started)
                {
                    plugin->captured_frame_index = event->frame_index;
                }
            }
            break;
        }
        case GFXR_REPLAY_EVENT_FRAME_END:
        {
            // If we are currently capturing and this is the frame we intended to capture, stop the capture.
            if (plugin->capture_started && event->frame_index == plugin->captured_frame_index &&
                plugin->rdoc_api != nullptr)
            {
                GFXRECON_LOG_INFO("Stopping RenderDoc capture on FRAME_END (frame_index: %" PRIu64 ")...",
                                  event->frame_index);
                int result = plugin->rdoc_api->EndFrameCapture(nullptr, nullptr);
                GFXRECON_LOG_INFO("RenderDoc capture stopped. Result: %d", result);
                plugin->capture_started = false;
                plugin->capture_done    = true;
            }
            break;
        }
        default:
            break;
    }

    return GFXR_REPLAY_PLUGIN_RESULT_OK;
}

/**
 * @brief Exported entry point to instantiate a new RenderDoc replay plugin.
 *
 * This function initializes the plugin object, parses configuration parameters
 * (e.g. RenderDoc library path and target frame), and maps the API function pointers.
 *
 * Parameter syntax in `create_info->plugin_params`:
 * `<lib_path>;frame=<target_frame>`
 * Example: `librenderdoc.so;frame=100` (captures frame 100) or just `librenderdoc.so` (defaults to frame 0).
 *
 * @param create_info Input structures with creation configurations.
 * @return GfxrReplayPluginV1* Pointer to the plugin base interface structure, or nullptr on failure.
 */
GFXR_REPLAY_PLUGIN_EXPORT GfxrReplayPluginV1* gfxrCreateReplayPluginV1(const GfxrReplayPluginCreateInfo* create_info)
{
    if (create_info == NULL)
    {
        GFXRECON_LOG_ERROR("Create info is NULL");
        return NULL;
    }

    if (create_info->abi_version != GFXR_REPLAY_PLUGIN_ABI_VERSION)
    {
        GFXRECON_LOG_ERROR("Unsupported plugin ABI version %u", create_info->abi_version);
        return NULL;
    }

    if (create_info->struct_size != sizeof(GfxrReplayPluginCreateInfo))
    {
        GFXRECON_LOG_ERROR("Unexpected create info struct size %u", create_info->struct_size);
        return NULL;
    }

    GFXRECON_LOG_INFO("Creating RenderDoc capture plugin");

    RenderDocCapturePlugin* plugin = new RenderDocCapturePlugin;
    plugin->base.abi_version       = GFXR_REPLAY_PLUGIN_ABI_VERSION;
    plugin->base.struct_size       = sizeof(GfxrReplayPluginV1);
    plugin->base.destroy           = destroy;
    plugin->base.on_event          = on_event;
    plugin->capture_started        = false;

    if (create_info->plugin_params != nullptr && create_info->plugin_params[0] != '\0')
    {
        std::string params(create_info->plugin_params);
        size_t      semi = params.find(';');
        std::string lib_path_part;
        std::string extra_part;
        if (semi != std::string::npos)
        {
            lib_path_part = params.substr(0, semi);
            extra_part    = params.substr(semi + 1);
        }
        else
        {
            if (params.find("frame=") == 0)
            {
                extra_part = params;
            }
            else
            {
                lib_path_part = params;
            }
        }

        plugin->renderdoc_lib_path = lib_path_part;

        if (!extra_part.empty())
        {
            size_t eq = extra_part.find("frame=");
            if (eq != std::string::npos)
            {
                std::string val_str  = extra_part.substr(eq + 6);
                plugin->target_frame = std::strtoull(val_str.c_str(), nullptr, 10);
            }
        }
        else
        {
            plugin->target_frame = 0;
        }
        GFXRECON_LOG_INFO("RenderDoc plugin configured with custom library path: %s, target_frame: %" PRIu64 "",
                          plugin->renderdoc_lib_path.c_str(),
                          plugin->target_frame);
    }

    if (plugin->renderdoc_lib_path.empty())
    {
        GFXRECON_LOG_FATAL("RenderDoc library path is required but was not provided in plugin parameters.");
        delete plugin;
        return nullptr;
    }

    return &plugin->base;
}
