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

Dx12DumpResources::~Dx12DumpResources()
{
    EndFile();
}

void Dx12DumpResources::WriteResources(nlohmann::ordered_json&              jdata,
                                       const std::string&                   prefix_file_name,
                                       const std::vector<CopyResourceData>& resource_datas)
{
    uint32_t i = 0;
    for (const auto& resouce : resource_datas)
    {
        WriteResource(jdata[i], prefix_file_name, resouce);
        ++i;
    }
}

void Dx12DumpResources::WriteResource(nlohmann::ordered_json& jdata,
                                      const std::string&      prefix_file_name,
                                      const CopyResourceData& resource_data)
{
    std::string file_name = prefix_file_name + "_resource_id_" + std::to_string(resource_data.source_resource_id);

    if (!resource_data.before_data.empty())
    {
        util::FieldToJson(jdata["resource_id"], resource_data.source_resource_id, json_options_);
        for (const auto sub_index : resource_data.subresource_indices)
        {
            auto& jdata_sub = jdata["subresource"][sub_index];
            util::FieldToJson(jdata_sub["index"], sub_index, json_options_);
            util::FieldToJson(jdata_sub["offset"], resource_data.offsets[sub_index], json_options_);
            util::FieldToJson(jdata_sub["size"], resource_data.sizes[sub_index], json_options_);

            std::string before_file_name = file_name + "_subresource_" + std::to_string(sub_index) + "_before.bin";
            util::FieldToJson(jdata_sub["before_file_name"], before_file_name.c_str(), json_options_);

            std::string before_filepath = gfxrecon::util::filepath::Join(json_options_.root_dir, before_file_name);
            WriteBinaryFile(before_filepath,
                            resource_data.before_data,
                            resource_data.offsets[sub_index],
                            resource_data.sizes[sub_index]);

            if (!resource_data.after_data.empty())
            {
                std::string after_file_name = file_name + "_subresource_" + std::to_string(sub_index) + "_after.bin";
                util::FieldToJson(jdata_sub["after_file_name"], after_file_name.c_str(), json_options_);

                std::string after_filepath = gfxrecon::util::filepath::Join(json_options_.root_dir, after_file_name);
                WriteBinaryFile(after_filepath,
                                resource_data.after_data,
                                resource_data.offsets[sub_index],
                                resource_data.sizes[sub_index]);
            }
        }
    }
}

void Dx12DumpResources::WriteResources(const TrackDumpResources& resources)
{
    WriteMetaCommandToFile("resources", [&](auto& jdata) {
        // vertex
        WriteResources(jdata["vertex"], json_options_.data_sub_dir, resources.copy_vertex_resources);

        // index
        WriteResource(jdata["index"], json_options_.data_sub_dir, resources.copy_index_resource);

        // descriptor
        uint32_t index = 0;
        for (const auto& heap_data : resources.descriptor_heap_datas)
        {
            auto& jdata_sub = jdata["descriptor_heap"][index];
            util::FieldToJson(jdata_sub["heap_id"], resources.target.descriptor_heap_ids[index], json_options_);

            std::string filename =
                json_options_.data_sub_dir + "_heap_id_" + std::to_string(resources.target.descriptor_heap_ids[index]);
            WriteResources(jdata_sub["constant_buffer"], filename, heap_data.copy_constant_buffer_resources);
            WriteResources(jdata_sub["shader_resource"], filename, heap_data.copy_shader_resources);

            uint32_t uav_index = 0;
            for (const auto& uav_data : heap_data.copy_unordered_accesses)
            {
                WriteResource(jdata_sub["unordered_access"][uav_index]["reousrce"], filename, uav_data.resource);
                WriteResource(
                    jdata_sub["unordered_access"][uav_index]["counter_resource"], filename, uav_data.counter_resource);
                ++uav_index;
            }
            ++index;
        }

        // render target
        WriteResources(jdata["render_target"], json_options_.data_sub_dir, resources.copy_render_target_resources);
        WriteResource(jdata["depth_stencil"], json_options_.data_sub_dir, resources.copy_depth_stencil_resource);

        // ExecuteIndirect
        WriteResource(
            jdata["ExecuteIndirect_argument"], json_options_.data_sub_dir, resources.copy_exe_indirect_argument);
        WriteResource(jdata["ExecuteIndirect_count"], json_options_.data_sub_dir, resources.copy_exe_indirect_count);
    });

    if (TEST_READABLE)
    {
        std::string prefix_file_name =
            gfxrecon::util::filepath::Join(json_options_.root_dir, json_options_.data_sub_dir);

        // vertex
        TestWriteReadableResources(prefix_file_name, resources.copy_vertex_resources);

        // index
        TestWriteReadableResource(prefix_file_name, resources.copy_index_resource);

        // descriptor
        uint32_t index = 0;
        for (const auto& heap_data : resources.descriptor_heap_datas)
        {
            TestWriteReadableResources(prefix_file_name + "_heap_id_" +
                                           std::to_string(resources.target.descriptor_heap_ids[index]),
                                       heap_data.copy_constant_buffer_resources);

            TestWriteReadableResources(prefix_file_name + "_heap_id_" +
                                           std::to_string(resources.target.descriptor_heap_ids[index]),
                                       heap_data.copy_shader_resources);

            for (const auto& uav_data : heap_data.copy_unordered_accesses)
            {
                TestWriteReadableResource(prefix_file_name + "_heap_id_" +
                                              std::to_string(resources.target.descriptor_heap_ids[index]),
                                          uav_data.resource);
                TestWriteReadableResource(prefix_file_name + "_heap_id_" +
                                              std::to_string(resources.target.descriptor_heap_ids[index]),
                                          uav_data.counter_resource);
            }
            ++index;
        }

        // render target
        TestWriteReadableResources(prefix_file_name, resources.copy_render_target_resources);
        TestWriteReadableResource(prefix_file_name, resources.copy_depth_stencil_resource);

        // ExecuteIndirect
        TestWriteReadableResource(prefix_file_name, resources.copy_exe_indirect_argument);
        TestWriteReadableResource(prefix_file_name, resources.copy_exe_indirect_count);
    }
}

void Dx12DumpResources::TestWriteReadableResources(const std::string&                   prefix_file_name,
                                                   const std::vector<CopyResourceData>& resource_datas)
{
    for (const auto& resource : resource_datas)
    {
        TestWriteReadableResource(prefix_file_name, resource);
    }
}

void Dx12DumpResources::TestWriteReadableResource(const std::string&      prefix_file_name,
                                                  const CopyResourceData& resource_data)
{
    if (resource_data.desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        TestWriteFloatResource(prefix_file_name, resource_data);
    }
    else
    {
        TestWriteImageResource(prefix_file_name, resource_data);
    }
}

void Dx12DumpResources::TestWriteFloatResource(const std::string&      prefix_file_name,
                                               const CopyResourceData& resource_data)
{
    std::string file_name = prefix_file_name + "_resource_id_" + std::to_string(resource_data.source_resource_id);

    if (!resource_data.before_data.empty())
    {
        for (const auto sub_index : resource_data.subresource_indices)
        {
            auto before_data_begin_sub =
                reinterpret_cast<const float*>(resource_data.before_data.data() + resource_data.offsets[sub_index]);
            uint32_t    size        = resource_data.sizes[sub_index] / (sizeof(float));
            std::string before_data = "";
            for (uint32_t i = 0; i < size; ++i)
            {
                before_data += std::to_string(before_data_begin_sub[i]);
                before_data += "\n";
            }

            std::string before_file_name = file_name + "_subresource_" + std::to_string(sub_index) + "_before.txt";
            FILE*       before_file_handle;
            util::platform::FileOpen(&before_file_handle, before_file_name.c_str(), "w");
            util::platform::FilePuts(before_data.c_str(), before_file_handle);
            util::platform::FileClose(before_file_handle);

            if (!resource_data.after_data.empty())
            {
                auto after_data_begin_sub =
                    reinterpret_cast<const float*>(resource_data.after_data.data() + resource_data.offsets[sub_index]);
                std::string after_data = "";
                for (uint32_t i = 0; i < size; ++i)
                {
                    after_data += std::to_string(after_data_begin_sub[i]);
                    after_data += "\n";
                }

                std::string after_file_name = file_name + "_subresource_" + std::to_string(sub_index) + "_after.txt";
                FILE*       after_file_handle;
                util::platform::FileOpen(&after_file_handle, after_file_name.c_str(), "w");
                util::platform::FilePuts(after_data.c_str(), after_file_handle);
                util::platform::FileClose(after_file_handle);
            }
        }
    }
}

void Dx12DumpResources::TestWriteImageResource(const std::string&      prefix_file_name,
                                               const CopyResourceData& resource_data)
{
    std::string file_name = prefix_file_name + "_resource_id_" + std::to_string(resource_data.source_resource_id);

    if (!resource_data.before_data.empty())
    {
        for (const auto sub_index : resource_data.subresource_indices)
        {
            std::string before_file_name = file_name + "_subresource_" + std::to_string(sub_index);

            // WriteBmpImage expects 4 bytes per pixel.
            double bytes_per_pixel = static_cast<double>(resource_data.sizes[sub_index]) /
                                     (static_cast<double>(resource_data.footprints[sub_index].Footprint.RowPitch / 4) *
                                      resource_data.footprints[sub_index].Footprint.Height);
            if (bytes_per_pixel != 4.0)
            {
                GFXRECON_LOG_WARNING("Dump images could not be created for before and after resource of "
                                     "'%s_before\\after.bmp'. Only formats "
                                     "with 4 bytes per pixel are supported. Current format %" PRIu32
                                     " is %.2f bytes per pixel.",
                                     before_file_name.c_str(),
                                     resource_data.footprints[sub_index].Footprint.Format,
                                     bytes_per_pixel);
                continue;
            }

            before_file_name += "_before.bmp";
            if (!util::imagewriter::WriteBmpImage(before_file_name,
                                                  resource_data.footprints[sub_index].Footprint.Width,
                                                  resource_data.footprints[sub_index].Footprint.Height,
                                                  resource_data.sizes[sub_index],
                                                  resource_data.before_data.data() + resource_data.offsets[sub_index],
                                                  resource_data.footprints[sub_index].Footprint.RowPitch))
            {
                GFXRECON_LOG_ERROR("Dump image could not be created: failed to write BMP file %s",
                                   before_file_name.c_str());
            }

            if (!resource_data.after_data.empty())
            {
                std::string after_file_name = file_name + "_subresource_" + std::to_string(sub_index) + "_after.bmp";
                if (!util::imagewriter::WriteBmpImage(after_file_name,
                                                      resource_data.footprints[sub_index].Footprint.Width,
                                                      resource_data.footprints[sub_index].Footprint.Height,
                                                      resource_data.sizes[sub_index],
                                                      resource_data.after_data.data() +
                                                          resource_data.offsets[sub_index],
                                                      resource_data.footprints[sub_index].Footprint.RowPitch))
                {
                    GFXRECON_LOG_ERROR("Dump image could not be created: failed to write BMP file %s",
                                       after_file_name.c_str());
                }
            }
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
    return result;
}

void Dx12DumpResources::StartFile()
{
    num_objects_ = 0;
    if (json_options_.format == util::JsonFormat::JSON)
    {
        util::platform::FilePuts("[\n", json_file_handle_);
    }

    // Emit the header object as the first line of the file:
    WriteBlockStart();
    json_data_["header"] = header_;
    WriteBlockEnd();
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
