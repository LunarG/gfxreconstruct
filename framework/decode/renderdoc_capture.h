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

#ifndef GFXRECON_DECODE_RENDERDOC_CAPTURE_H
#define GFXRECON_DECODE_RENDERDOC_CAPTURE_H

#include "util/defines.h"
#include <string>

#include "renderdoc_app.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Retrieve the RenderDoc API pointer if available.
const RENDERDOC_API_1_0_0* GetRenderDocApi();

// Check if RenderDoc capture is enabled via system property.
bool ShouldCreateRenderDocCapture();

// Get the capture file path template.
std::string GetRenderDocCaptureFilePathTemplate(const std::string& gfxr_filepath);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_RENDERDOC_CAPTURE_H
