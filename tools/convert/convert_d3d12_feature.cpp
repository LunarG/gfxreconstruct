/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#if defined(D3D12_SUPPORT)

#include "convert_feature.h"

#include "decode/dx12_detection_consumer.h"
#include "generated/generated_dx12_decoder.h"
#include "generated/generated_dx12_json_consumer.h"
#include "util/feature_module_registry.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(convert)

using Dx12JsonConsumer =
    gfxrecon::decode::MetadataJsonConsumer<gfxrecon::decode::MarkerJsonConsumer<gfxrecon::decode::Dx12JsonConsumer>>;

class Dx12ConvertFeature
    : public ConvertFeature<Dx12JsonConsumer, gfxrecon::decode::Dx12Decoder, decode::Dx12DetectionConsumer>
{
  public:
    Dx12ConvertFeature() : ConvertFeature(decode::Dx12DetectionConsumer::kNoBlockLimit) {}
    bool WasDetected() const final { return detect_consumer_.WasD3D12APIDetected(); }
};

// Register this class as a feature in a module registry
GFXR_UTIL_REGISTER_FEATURE_CREATOR(ConvertFeatureBase, Dx12ConvertFeature);

GFXRECON_END_NAMESPACE(convert)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT
