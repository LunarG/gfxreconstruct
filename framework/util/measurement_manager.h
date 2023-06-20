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

#ifndef GFXRECON_UTIL_MEASUREMENT_MANAGER_H
#define GFXRECON_UTIL_MEASUREMENT_MANAGER_H

#include "util/defines.h"
#include "util/platform.h"
#include "nlohmann/json.hpp"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class MeasurementFile
{
  public:
    MeasurementFile(const std::string& file_name);
    nlohmann::json& GetRoot() { return root_; }
    ~MeasurementFile();

  private:
    std::string    file_name_;
    nlohmann::json root_;
};

class MeasurementManager
{
  public:
    static void Open(const std::string& file_name);

    static std::optional<MeasurementFile>& GetFile() { return file_; }

    template <typename TValue>
    static void WriteApplication(const std::string& key, const TValue& value)
    {
        if (file_.has_value())
        {
            file_->GetRoot()["application"][key] = value;
        }
    }

    template <typename TValue>
    static void WriteFrameRange(const std::string& key, const TValue& value)
    {
        if (file_.has_value())
        {
            file_->GetRoot()["frame_ranges"][0][key] = value;
        }
    }

    static void SaveAndClose();

  private:
    MeasurementManager()  = default;
    ~MeasurementManager() = default;

    static std::optional<MeasurementFile> file_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_MEASUREMENT_MANAGER_H
