/*
 * Copyright (c) 2026 Google LLC
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

#include "decode/renderdoc_capture.h"

#include <dlfcn.h>
#include "util/logging.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace {

RENDERDOC_API_1_0_0* LoadRenderDocApi()
{
    // Check if the RenderDoc layer is already loaded in the process.
    // RTLD_NOLOAD means we don't load it if it's not there, we just check if it is already loaded.
    void* renderdoc_so = dlopen("libVkLayer_GLES_RenderDoc.so", RTLD_NOW | RTLD_NOLOAD);
    if (renderdoc_so == nullptr)
    {
        GFXRECON_LOG_DEBUG("RenderDoc layer libVkLayer_GLES_RenderDoc.so is not loaded in the process.");
        return nullptr;
    }

    (void)dlerror(); // Clear previous error
    pRENDERDOC_GetAPI RENDERDOC_GetAPI = reinterpret_cast<pRENDERDOC_GetAPI>(
        dlsym(renderdoc_so, "RENDERDOC_GetAPI"));
    if (RENDERDOC_GetAPI == nullptr)
    {
        GFXRECON_LOG_WARNING("Failed to dlsym RENDERDOC_GetAPI: %s", dlerror());
        return nullptr;
    }

    RENDERDOC_API_1_0_0* renderdoc_api = nullptr;
    if (RENDERDOC_GetAPI(eRENDERDOC_API_Version_1_0_0, reinterpret_cast<void**>(&renderdoc_api)) != 1)
    {
        GFXRECON_LOG_WARNING("RENDERDOC_GetAPI failed to retrieve API pointer.");
        return nullptr;
    }

    int major = 0;
    int minor = 0;
    int patch = 0;
    renderdoc_api->GetAPIVersion(&major, &minor, &patch);
    GFXRECON_LOG_INFO("Loaded RenderDoc In-Application API v%d.%d.%d", major, minor, patch);
    return renderdoc_api;
}

} // namespace

const RENDERDOC_API_1_0_0* GetRenderDocApi()
{
    static const RENDERDOC_API_1_0_0* const renderdoc_api = LoadRenderDocApi();
    return renderdoc_api;
}

bool ShouldCreateRenderDocCapture()
{
    std::string property = util::platform::GetEnv("debug.gfxrecon.replay.renderdoc_capture");
    return property == "true" || property == "1";
}

std::string GetRenderDocCaptureFilePathTemplate(const std::string& gfxr_filepath)
{
    // Extract stem (filename without extension)
    std::string filename = gfxr_filepath;
    size_t last_slash = filename.find_last_of('/');
    if (last_slash != std::string::npos) {
        filename = filename.substr(last_slash + 1);
    }
    size_t last_dot = filename.find_last_of('.');
    if (last_dot != std::string::npos) {
        filename = filename.substr(0, last_dot);
    }

    // Target directory on Android
    std::string capture_dir = "/sdcard/Android/media/com.lunarg.gfxreconstruct.replay/files/RenderDoc";
    
    // Return template: dir/stem_capture (RenderDoc will append frame info and .rdc extension)
    return capture_dir + "/" + filename + "_capture";
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
