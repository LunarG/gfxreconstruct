/*
** Copyright (c) 2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "util/measurement_manager.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::optional<MeasurementFile> MeasurementManager::file_;

MeasurementFile::MeasurementFile(const std::string& file_name) :
    file_name_(file_name),
    root_({ { "application", nlohmann::json::object() }, { "frame_ranges", nlohmann::json::array() } })
{
    // To avoid thinking an ancient file is the result of this run
    std::remove(file_name.c_str());
}

MeasurementFile::~MeasurementFile()
{
    FILE*   file_pointer = nullptr;
    int32_t result       = platform::FileOpen(&file_pointer, file_name_.c_str(), "w");
    if (result != 0)
    {
        GFXRECON_LOG_ERROR("Failed to open measurements file '%s' (Error %i).", file_name_.c_str(), result);
        GFXRECON_LOG_ERROR("%s", std::strerror(result));
        return;
    }

    std::string json_string = root_.dump(4); // TODO: '--measurement-file-pretty' option with/without identation ?

    size_t size_written = platform::FileWrite(json_string.data(), 1, json_string.size(), file_pointer);

    platform::FileClose(file_pointer);

    // It either writes a fully valid file, or it doesn't write anything !
    if (size_written != json_string.size())
    {
        std::remove(file_name_.c_str());
    }
}

void MeasurementManager::Open(const std::string& file_name)
{
    GFXRECON_ASSERT(!file_name.empty()); // A better check than the file name is valid would be welcome
    GFXRECON_ASSERT(!file_.has_value()); // For now we don't handle multiple files at the same time

    if (!file_name.empty())
    {
        file_.emplace(file_name);
    }
}

void MeasurementManager::SaveAndClose()
{
    file_.reset();
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
