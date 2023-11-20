/*
** Copyright (c) 2021 Samsung
** Copyright (c) 2023 Google
** Copyright (c) 2023 LunarG, Inc
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

#ifndef GFXRECON_DECODE_VULKAN_CPP_UTIL_DATAPACK_H
#define GFXRECON_DECODE_VULKAN_CPP_UTIL_DATAPACK_H

#include <map>
#include <string>

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct SavedFileInfo
{
    std::string file_path;
    uint64_t    byte_offset;
};

class DataFilePacker
{
  public:
    DataFilePacker() : data_file_counter_(0) {}

    void                Initialize(const std::string& outDir,
                                   const std::string& prefix,
                                   const std::string& suffix,
                                   uint32_t           sizeLimitInBytes);
    const SavedFileInfo AddFileContents(const uint8_t* data, const uint64_t dataSize);

  private:
    void NewTargetFile(void);
    void WriteContentsToFile(const std::string& filePath, uint64_t fileOffset, uint64_t size, const uint8_t* data);

    struct SavedFile
    {
        std::string file_path;
        uint64_t    current_size;
    };

    std::string out_dir_;
    std::string prefix_;
    std::string suffix_;
    uint32_t    size_limit_in_bytes_;
    uint32_t    data_file_counter_;

    std::map<uint64_t, SavedFileInfo> data_file_map_;
    SavedFile                         current_data_file_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_CPP_UTIL_DATAPACK_H
