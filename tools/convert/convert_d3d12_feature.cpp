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

#include "convert_d3d12_feature.h"

#include "util/feature_module_registry.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(convert)

// Register this class as a feature in a module registry
GFXR_UTIL_REGISTER_FEATURE_CREATOR(ConvertFeature, ConvertD3d12Feature)

void ConvertD3d12Feature::RegisterDecodeComponents(gfxrecon::decode::FileProcessor& file_processor)
{
    dx12_decoder_.AddConsumer(&dx12_json_consumer_);
    file_processor.AddDecoder(&dx12_decoder_);
}

void ConvertD3d12Feature::RegisterJsonWriter(gfxrecon::decode::JsonWriter* json_writer)
{
    dx12_json_consumer_.Initialize(json_writer);
}

void ConvertD3d12Feature::UnregisterJsonWriter()
{
    // If CONVERT_EXPERIMENTAL_D3D12 was set, then cleanup DX12 consumer
    dx12_json_consumer_.Destroy();
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT
