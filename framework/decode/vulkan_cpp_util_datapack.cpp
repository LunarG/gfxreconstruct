//
// Copyright (c) 2021 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2023 LunarG, Inc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <functional>

#include "decode/vulkan_cpp_util_datapack.h"

#include "util/hash.h"
#include "util/file_path.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void DataFilePacker::Initialize(const std::string& outDir,
                                const std::string& prefix,
                                const std::string& suffix,
                                uint32_t           sizeLimitInBytes)
{
    out_dir_             = outDir;
    prefix_              = prefix;
    suffix_              = suffix;
    size_limit_in_bytes_ = sizeLimitInBytes;

    NewTargetFile();
}

const SavedFileInfo DataFilePacker::AddFileContents(const uint8_t* data, const size_t dataSize)
{
    const uint64_t hash_value = util::hash::GenerateCheckSum<uint64_t>(data, dataSize);
    SavedFileInfo& data_entry = data_file_map_[hash_value];

    if (data_entry.file_path.empty())
    {
        // The binary contents is not found in any previous chunk.
        if (current_data_file_.current_size > size_limit_in_bytes_)
        {
            // Reached the current file size limit, create a new data chunk.
            NewTargetFile();
        }

        data_entry.file_path   = current_data_file_.file_path;
        data_entry.byte_offset = current_data_file_.current_size;

        WriteContentsToFile(
            util::filepath::Join(out_dir_, data_entry.file_path), data_entry.byte_offset, dataSize, data);

        current_data_file_.current_size += dataSize;
    }

    return data_entry;
}

void DataFilePacker::NewTargetFile(void)
{
    current_data_file_ = SavedFile{ prefix_ + std::to_string(++data_file_counter_) + "." + suffix_, 0 };
}

void DataFilePacker::WriteContentsToFile(const std::string& file_path,
                                         uint64_t           fileOffset,
                                         uint64_t           size,
                                         const uint8_t*     data)
{
    FILE*   fp     = nullptr;
    int32_t result = util::platform::FileOpen(&fp, file_path.c_str(), "ab");

    if (result != 0)
    {
        fprintf(stderr, "Error while opening file: %s\n", file_path.c_str());
        return;
    }

    util::platform::FileSeek(fp, fileOffset, util::platform::FileSeekCurrent);

    if (!util::platform::FileWrite(data, size, fp))
    {
        fprintf(stderr, "Error while saving data into %s\n", file_path.c_str());
    }

    util::platform::FileClose(fp);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
