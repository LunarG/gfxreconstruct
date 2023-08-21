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

#include "decode/vulkan_cpp_util_datapack.h"

#include "util/file_path.h"
#include "util/platform.h"
#include "util/xxhash64.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void DataFilePacker::Initialize(const std::string& outDir,
                                const std::string& prefix,
                                const std::string& suffix,
                                uint32_t           sizeLimitInBytes)
{
    m_outDir           = outDir;
    m_prefix           = prefix;
    m_suffix           = suffix;
    m_sizeLimitInBytes = sizeLimitInBytes;

    NewTargetFile();
}

const SavedFileInfo DataFilePacker::AddFileContents(const uint8_t* data, const uint64_t dataSize)
{
    uint64_t hashValue = XXHash64::hash(data, dataSize, 0);

    SavedFileInfo& dataEntry = m_dataFileMap[hashValue];

    if (dataEntry.filePath.empty())
    {
        /* The binary contents is not found in any previous chunk. */
        if (m_currentDataFile.currentSize > m_sizeLimitInBytes)
        {
            /* Reached the current file size limit, create a new data chunk. */
            NewTargetFile();
        }

        dataEntry.filePath   = m_currentDataFile.filePath;
        dataEntry.byteOffset = m_currentDataFile.currentSize;

        WriteContentsToFile(util::filepath::Join(m_outDir, dataEntry.filePath), dataEntry.byteOffset, dataSize, data);

        m_currentDataFile.currentSize += dataSize;
    }

    return dataEntry;
}

void DataFilePacker::NewTargetFile(void)
{
    m_currentDataFile = SavedFile{ m_prefix + std::to_string(++m_dataFileCounter) + "." + m_suffix, 0 };
}

void DataFilePacker::WriteContentsToFile(const std::string& filePath,
                                         uint64_t           fileOffset,
                                         uint64_t           size,
                                         const uint8_t*     data)
{
    FILE*   fp     = nullptr;
    int32_t result = util::platform::FileOpen(&fp, filePath.c_str(), "ab");

    if (result != 0)
    {
        fprintf(stderr, "Error while opening file: %s\n", filePath.c_str());
        return;
    }

    util::platform::FileSeek(fp, fileOffset, util::platform::FileSeekCurrent);

    size_t written_size = util::platform::FileWrite(data, sizeof(uint8_t), size, fp);
    if (written_size != size)
    {
        fprintf(stderr, "Error while saving data into %s\n", filePath.c_str());
    }

    util::platform::FileClose(fp);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
