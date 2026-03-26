/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_CONVERT_D3D12_FEATURE_H
#define GFXRECON_CONVERT_D3D12_FEATURE_H

#if defined(D3D12_SUPPORT)

#include "convert_feature.h"

#include "generated/generated_dx12_json_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(convert)

using Dx12JsonConsumer =
    gfxrecon::decode::MetadataJsonConsumer<gfxrecon::decode::MarkerJsonConsumer<gfxrecon::decode::Dx12JsonConsumer>>;

class ConvertD3d12Feature : public ConvertFeature
{
  public:
    virtual ~ConvertD3d12Feature() = default;

    // Simple "getter" style methods
    std::string Label() override { return "D3D12"; }

    // Method to register this features's decoder elements with the containers
    // FileProcessor
    void RegisterDecodeComponents(gfxrecon::decode::FileProcessor& file_processor) override;

    // Method to register/unregister this the json writer with the json consumer
    void RegisterJsonWriter(gfxrecon::decode::JsonWriter* json_writer) override;
    void UnregisterJsonWriter() override;

  private:
    Dx12JsonConsumer              dx12_json_consumer_;
    gfxrecon::decode::Dx12Decoder dx12_decoder_;
};

GFXRECON_END_NAMESPACE(convert)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT

#endif // GFXRECON_CONVERT_D3D12_FEATURE_H
