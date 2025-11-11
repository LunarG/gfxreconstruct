/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_COMPRESSION_CONVERTER_H
#define GFXRECON_COMPRESSION_CONVERTER_H

#include "decode/file_transformer.h"
#include "format/format.h"
#include "util/compressor.h"
#include "util/defines.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

class CompressionConverter : public decode::FileTransformer
{
  public:
    CompressionConverter();

    virtual ~CompressionConverter() override;

    bool Initialize(const std::string&      input_filename,
                    const std::string&      output_filename,
                    format::CompressionType target_compression_type);

  protected:
    bool WriteFileHeader(const format::FileHeader& header, const std::vector<format::FileOptionPair>& options) override;

    bool ProcessFunctionCall(decode::ParsedBlock& parsed_block) override;
    bool ProcessMethodCall(decode::ParsedBlock& parsed_block) override;

    bool ProcessMetaData(decode::ParsedBlock& parsed_block) override;

  private:
    bool
    WriteFunctionCall(format::ApiCallId call_id, format::ThreadId thread_id, size_t buffer_size, const uint8_t* buffer);

    bool WriteMethodCall(format::ApiCallId call_id,
                         format::HandleId  object_id,
                         format::ThreadId  thread_id,
                         size_t            buffer_size,
                         const uint8_t*    buffer);

    // Specialists called by the vistor in ProcessMetaData
    VisitResult WriteMetaData(const decode::FillMemoryArgs& args);
    VisitResult WriteMetaData(const decode::InitBufferArgs& args);
    VisitResult WriteMetaData(const decode::InitImageArgs& args);
    VisitResult WriteMetaData(const decode::InitSubresourceArgs& args);
    VisitResult WriteMetaData(const decode::InitDx12AccelerationStructureArgs& args);
    VisitResult WriteMetaData(const decode::FillMemoryResourceValueArgs& args);

    template <typename Args>
    VisitResult WriteMetaData(Args&)
    {
        return kNeedsPassthrough;
    }

    void PrepMetadataBlock(format::MetaDataHeader& meta_data_header,
                           format::MetaDataId      meta_data_id,
                           const uint8_t*&         data_address,
                           size_t&                 data_size);

  private:
    bool                              decompressing_;
    format::CompressionType           target_compression_type_;
    std::unique_ptr<util::Compressor> target_compressor_;
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_COMPRESSION_CONVERTER_H
