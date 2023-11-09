/*
** Copyright (c) 2023 LunarG, Inc.
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

/// @file Base class for generated DX12 consumer which outputs JSON and associated utilities.

#ifndef GFXRECON_DECODE_DX12_JSON_CONSUMER_BASE_H
#define GFXRECON_DECODE_DX12_JSON_CONSUMER_BASE_H

#include "generated/generated_dx12_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class JsonWriter;

/// @file Base class for generated DX12 consumer which outputs a JSON representation of a captured stream.
class Dx12JsonConsumerBase : public Dx12Consumer
{
  public:
    Dx12JsonConsumerBase();
    virtual ~Dx12JsonConsumerBase() override;

    void Initialize(JsonWriter* writer);

    void Destroy();

    bool IsValid() const;

    /// @defGroup ApiAgnosticMetaBlocksUsedOnlyByDx12 Metablocks used by only DX12.
    /// @{
    /// @todo kCreateHeapAllocationCommand
    /// @todo kInitSubresourceCommand
    /// @todo kInitDx12AccelerationStructureCommand
    /// @todo kFillMemoryResourceValueCommand
    /// @todo kDxgiAdapterInfoCommand
    /// @todo kDriverInfoCommand
    /// @todo kDx12RuntimeInfoCommand (only used by stats consumer)
    /// @}

  protected:
    JsonWriter* writer_{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_JSON_CONSUMER_BASE_H
