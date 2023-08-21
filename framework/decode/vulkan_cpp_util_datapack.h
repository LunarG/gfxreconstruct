/*
** Copyright (c) 2021 Samsung
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
    std::string filePath;
    uint64_t    byteOffset;
};

class DataFilePacker
{
  public:
    DataFilePacker() : m_dataFileCounter(0) {}

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
        std::string filePath;
        uint64_t    currentSize;
    };

    std::string m_outDir;
    std::string m_prefix;
    std::string m_suffix;
    uint32_t    m_sizeLimitInBytes;
    uint32_t    m_dataFileCounter;

    std::map<uint64_t, SavedFileInfo> m_dataFileMap;
    SavedFile                         m_currentDataFile;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_CPP_UTIL_DATAPACK_H
