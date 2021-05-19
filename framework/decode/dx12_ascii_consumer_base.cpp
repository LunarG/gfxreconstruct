/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "decode/dx12_ascii_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

Dx12AsciiConsumerBase::Dx12AsciiConsumerBase() : m_file(nullptr) {}

Dx12AsciiConsumerBase::~Dx12AsciiConsumerBase()
{
    Destroy();
}

void Dx12AsciiConsumerBase::Initialize(const std::string& filename, FILE* file)
{
    m_filename = filename;
    m_file     = file;
}

void Dx12AsciiConsumerBase::Destroy()
{
    m_file = nullptr;
}

void Dx12AsciiConsumerBase::Process_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                                     HRESULT          original_result,
                                                                     D3D12_FEATURE    feature,
                                                                     const void*      capture_feature_data,
                                                                     void*            replay_feature_data,
                                                                     UINT             feature_data_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(object_id);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(feature);
    GFXRECON_UNREFERENCED_PARAMETER(capture_feature_data);
    GFXRECON_UNREFERENCED_PARAMETER(replay_feature_data);
    GFXRECON_UNREFERENCED_PARAMETER(feature_data_size);

    fprintf(GetFile(), "%s\n", "ID3D12Device::CheckFeatureSupport");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
