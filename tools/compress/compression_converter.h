/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
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
    virtual bool WriteFileHeader(const format::FileHeader&                  header,
                                 const std::vector<format::FileOptionPair>& options) override;

    virtual bool ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id) override;

    virtual bool ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type) override;

  private:
    bool WriteFunctionCall(format::ApiCallId call_id, format::ThreadId thread_id, size_t buffer_size);

    bool WriteFillMemoryMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type);

    bool WriteInitBufferMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type);

    bool WriteInitImageMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type);

  private:
    bool                              decompressing_;
    format::CompressionType           target_compression_type_;
    std::unique_ptr<util::Compressor> target_compressor_;
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_COMPRESSION_CONVERTER_H
