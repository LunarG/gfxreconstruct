/*
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

#include "graphics/dx12_dump_resources.h"
// TODO: It should change the file name of "vulkan"
#include "generated/generated_vulkan_struct_to_json.h"
#include "util/platform.h"
#include "util/logging.h"
#include "util/image_writer.h"
#include "util/json_util.h"
#include "graphics/dx12_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// TEST_READABLE is only for test because data type could be various.
// But here uses fixed type.
// According to the resource's desc.Dimension, float is for buffer, image is for the others.
const bool TEST_READABLE = false;

Dx12DumpResources::Dx12DumpResources() : json_file_handle_(nullptr) {}

Dx12DumpResources::~Dx12DumpResources() {}

void Dx12DumpResources::StartDump(const TrackDumpResources& resources)
{
    WriteBlockStart();

    util::FieldToJson(drawcall_["block_index"], resources.target.drawcall_block_index, json_options_);
    util::FieldToJson(drawcall_["execute_block_index"], resources.target.execute_block_index, json_options_);
}

void Dx12DumpResources::WriteResource(const CopyResourceData&                             resource_data,
                                      const std::vector<std::pair<std::string, int32_t>>& json_path,
                                      const std::string&                                  file_name,
                                      const std::string&                                  type)
{
    if (resource_data.source_resource_id == format::kNullHandleId)
    {
        return;
    }

    auto* jdata_sub = &drawcall_;
    for (const auto& path : json_path)
    {
        if (path.second == format::kNoneIndex)
        {
            jdata_sub = &(*jdata_sub)[path.first];
        }
        else
        {
            jdata_sub = &(*jdata_sub)[path.first][path.second];
        }
    }
    std::string prefix_file_name = json_options_.data_sub_dir + "_" + file_name;
    WriteResource(*jdata_sub, prefix_file_name, type, resource_data);

    if (TEST_READABLE)
    {
        TestWriteReadableResource(prefix_file_name, type, resource_data);
    }
}

void Dx12DumpResources::CloseDump()
{
    json_data_[NameDrawCall()] = drawcall_;
    WriteBlockEnd();
    EndFile();
}

void Dx12DumpResources::WriteResource(nlohmann::ordered_json& jdata,
                                      const std::string&      prefix_file_name,
                                      const std::string&      suffix,
                                      const CopyResourceData& resource_data)
{
    if (resource_data.source_resource_id == format::kNullHandleId)
    {
        return;
    }

    std::string file_name = prefix_file_name + "_res_id_" + std::to_string(resource_data.source_resource_id);

    util::FieldToJson(jdata["res_id"], resource_data.source_resource_id, json_options_);
    std::string json_path = suffix + "_file_name";
    for (const auto sub_index : resource_data.subresource_indices)
    {
        auto offset = resource_data.subresource_offsets[sub_index];
        auto size   = resource_data.subresource_sizes[sub_index];

        auto& jdata_sub = jdata["sub"][sub_index];
        util::FieldToJson(jdata_sub["index"], sub_index, json_options_);
        util::FieldToJson(jdata_sub["offset"], offset, json_options_);
        util::FieldToJson(jdata_sub["size"], size, json_options_);

        // Write data.
        GFXRECON_ASSERT(!resource_data.datas[sub_index].empty());

        std::string file_name_sub = file_name + "_sub_" + std::to_string(sub_index) + "_" + suffix + ".bin ";
        util::FieldToJson(jdata_sub[json_path], file_name_sub.c_str(), json_options_);

        std::string file_path = gfxrecon::util::filepath::Join(json_options_.root_dir, file_name_sub);
        WriteBinaryFile(file_path, resource_data.datas[sub_index], offset, size);
    }
}

void Dx12DumpResources::TestWriteReadableResource(const std::string&      prefix_file_name,
                                                  const std::string&      suffix,
                                                  const CopyResourceData& resource_data)
{
    if (resource_data.source_resource_id == format::kNullHandleId)
    {
        return;
    }

    if (resource_data.desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        TestWriteFloatResource(prefix_file_name, suffix, resource_data);
    }
    else
    {
        TestWriteImageResource(prefix_file_name, suffix, resource_data);
    }
}

void Dx12DumpResources::TestWriteFloatResource(const std::string&      prefix_file_name,
                                               const std::string&      suffix,
                                               const CopyResourceData& resource_data)
{
    std::string file_name = prefix_file_name + "_res_id_" + std::to_string(resource_data.source_resource_id);

    for (const auto sub_index : resource_data.subresource_indices)
    {
        auto offset    = resource_data.subresource_offsets[sub_index];
        auto data_size = resource_data.subresource_sizes[sub_index];

        // Write data.
        GFXRECON_ASSERT(!resource_data.datas[sub_index].empty());

        auto        data_begin_sub = reinterpret_cast<const float*>(resource_data.datas[sub_index].data() + offset);
        uint32_t    size           = data_size / (sizeof(float));
        std::string data           = "";
        for (uint32_t i = 0; i < size; ++i)
        {
            data += std::to_string(data_begin_sub[i]);
            data += "\n";
        }

        std::string file_name_sub = file_name + "_sub_" + std::to_string(sub_index) + "_" + suffix + ".txt";
        std::string file_path     = gfxrecon::util::filepath::Join(json_options_.root_dir, file_name_sub);
        FILE*       file_handle;
        util::platform::FileOpen(&file_handle, file_path.c_str(), "w");
        util::platform::FilePuts(data.c_str(), file_handle);
        util::platform::FileClose(file_handle);
    }
}

void Dx12DumpResources::TestWriteImageResource(const std::string&      prefix_file_name,
                                               const std::string&      suffix,
                                               const CopyResourceData& resource_data)
{
    std::string file_name = prefix_file_name + "_res_id_" + std::to_string(resource_data.source_resource_id);

    for (const auto sub_index : resource_data.subresource_indices)
    {
        auto offset = resource_data.subresource_offsets[sub_index];
        auto size   = resource_data.subresource_sizes[sub_index];

        std::string file_name_sub = file_name + "_sub_" + std::to_string(sub_index);

        // WriteBmpImage expects 4 bytes per pixel.
        uint64_t row_pitch_aligned_size = ((size + (resource_data.footprints[sub_index].Footprint.RowPitch - 1)) /
                                           resource_data.footprints[sub_index].Footprint.RowPitch) *
                                          resource_data.footprints[sub_index].Footprint.RowPitch;
        double bytes_per_pixel = static_cast<double>(row_pitch_aligned_size) /
                                 (static_cast<double>(resource_data.footprints[sub_index].Footprint.RowPitch / 4) *
                                  resource_data.footprints[sub_index].Footprint.Height);
        if (bytes_per_pixel != 4.0)
        {
            GFXRECON_LOG_WARNING("Dump images could not be created for before and after resource of "
                                 "'%s_before\\after.bmp'. Only formats "
                                 "with 4 bytes per pixel are supported. Current format %" PRIu32
                                 " is %.2f bytes per pixel.",
                                 file_name_sub.c_str(),
                                 resource_data.footprints[sub_index].Footprint.Format,
                                 bytes_per_pixel);
            continue;
        }

        // Write data.
        GFXRECON_ASSERT(!resource_data.datas[sub_index].empty());

        file_name_sub += "_" + suffix + ".bmp ";
        std::string file_path = gfxrecon::util::filepath::Join(json_options_.root_dir, file_name_sub);
        if (!util::imagewriter::WriteBmpImage(file_path,
                                              resource_data.footprints[sub_index].Footprint.Width,
                                              resource_data.footprints[sub_index].Footprint.Height,
                                              size,
                                              resource_data.datas[sub_index].data() + offset,
                                              resource_data.footprints[sub_index].Footprint.RowPitch))
        {
            GFXRECON_LOG_ERROR("Dump image could not be created: failed to write BMP file %s", file_name_sub.c_str());
        }
    }
}

std::unique_ptr<Dx12DumpResources> Dx12DumpResources::Create(const Dx12DumpResourcesConfig& config)
{
    std::unique_ptr<Dx12DumpResources> out(new Dx12DumpResources());

    if (out != nullptr)
    {
        if (out->Init(config) != S_OK)
        {
            GFXRECON_LOG_WARNING("Dx12DumpResources initialization failed");
        }
    }
    return std::move(out);
}

HRESULT Dx12DumpResources::Init(const Dx12DumpResourcesConfig& config)
{
    HRESULT result       = S_OK;
    json_options_.format = kDefaultDumpResourcesFileFormat;

    json_filename_    = config.captured_file_name;
    auto ext_pos      = json_filename_.find_last_of(".");
    auto path_sep_pos = json_filename_.find_last_of(util::filepath::kPathSepStr);
    if (ext_pos != std::string::npos && (path_sep_pos == std::string::npos || ext_pos > path_sep_pos))
    {
        json_filename_ = json_filename_.substr(0, ext_pos);
    }
    json_filename_ += "_resources_submit_" + std::to_string(config.dump_resources_target.submit_index) + "_command_" +
                      std::to_string(config.dump_resources_target.command_index) + "_drawcall_" +
                      std::to_string(config.dump_resources_target.drawcall_index) + "." +
                      util::get_json_format(json_options_.format);

    json_options_.data_sub_dir = util::filepath::GetFilenameStem(json_filename_);
    json_options_.root_dir     = util::filepath::GetBasedir(json_filename_);

    util::platform::FileOpen(&json_file_handle_, json_filename_.c_str(), "w");

    header_["source-path"] = config.captured_file_name;

    StartFile();

    // Emit the header object as the first line of the file:
    WriteBlockStart();
    json_data_["source-path"] = header_;
    WriteBlockEnd();

    return result;
}

void Dx12DumpResources::StartFile()
{
    num_objects_ = 0;
    if (json_options_.format == util::JsonFormat::JSON)
    {
        util::platform::FilePuts("[\n", json_file_handle_);
    }
}

void Dx12DumpResources::EndFile()
{
    if (json_file_handle_ != nullptr)
    {
        if (json_options_.format == util::JsonFormat::JSON)
        {
            util::platform::FilePuts("\n]\n", json_file_handle_);
        }
        else
        {
            util::platform::FilePuts("\n", json_file_handle_);
        }
        util::platform::FileClose(json_file_handle_);
        json_file_handle_ = nullptr;
    }
}

void Dx12DumpResources::WriteBlockStart()
{
    json_data_.clear(); // < Dominates profiling (1/2).
    num_objects_++;
}

void Dx12DumpResources::WriteBlockEnd()
{
    if (num_objects_ > 1)
    {
        util::platform::FilePuts(json_options_.format == util::JsonFormat::JSONL ? "\n" : ",\n", json_file_handle_);
    }
    // Dominates profiling (2/2):
    const std::string block =
        json_data_.dump(json_options_.format == util::JsonFormat::JSONL ? -1 : util::kJsonIndentWidth);
    util::platform::FileWriteNoLock(block.data(), sizeof(std::string::value_type), block.length(), json_file_handle_);
    util::platform::FileFlush(json_file_handle_); /// @todo Implement a FileFlushNoLock() for all platforms.
}

bool Dx12DumpResources::WriteBinaryFile(const std::string&          filename,
                                        const std::vector<uint8_t>& data,
                                        uint64_t                    offset,
                                        uint64_t                    size)
{
    FILE* file_output = nullptr;
    if (util::platform::FileOpen(&file_output, filename.c_str(), "wb") == 0)
    {
        util::platform::FileWrite(data.data() + offset, size, 1, file_output);
        util::platform::FileClose(file_output);
        return true;
    }
    return false;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
