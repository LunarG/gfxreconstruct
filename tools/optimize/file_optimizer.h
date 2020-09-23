/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_FILE_OPTIMIZER_H
#define GFXRECON_FILE_OPTIMIZER_H

#include "decode/file_transformer.h"
#include "util/defines.h"

#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

class FileOptimizer : public decode::FileTransformer
{
  public:
    FileOptimizer(const std::unordered_set<format::HandleId>& unreferenced_ids);

    FileOptimizer(std::unordered_set<format::HandleId>&& unreferenced_ids);

  protected:
    virtual bool ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type) override;

  private:
    bool FilterInitBufferMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type);

    bool FilterInitImageMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type);

  private:
    std::unordered_set<format::HandleId> unreferenced_ids_;
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FILE_OPTIMIZER_H
