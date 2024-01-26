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
// float for vertex, index, constant buffer, shader resource(buffer), ExecuteIndirect
// image for shader resource(texture), render target.
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
        auto sub_count = resource_data.offsets.size();
        for (uint32_t i = 0; i < sub_count; ++i)
        {
            auto& jdata_sub = jdata["subresource"][i];
            util::FieldToJson(jdata_sub["index"], i, json_options_);
            util::FieldToJson(jdata_sub["offset"], resource_data.offsets[i], json_options_);
            util::FieldToJson(jdata_sub["size"], resource_data.sizes[i], json_options_);

            std::string before_file_name = file_name + "_subresource_" + std::to_string(i) + "_before.bin";
            util::FieldToJson(jdata_sub["before_file_name"], before_file_name.c_str(), json_options_);

            std::string filepath = gfxrecon::util::filepath::Join(json_options_.root_dir, before_file_name);
            WriteBinaryFile(filepath, resource_data.before_data, resource_data.offsets[i], resource_data.sizes[i]);
        }
    }
    if (!resource_data.after_data.empty())
    {
        auto sub_count = resource_data.offsets.size();
        for (uint32_t i = 0; i < sub_count; ++i)
        {
            auto&       jdata_sub       = jdata["subresource"][i];
            std::string after_file_name = file_name + "_subresource_" + std::to_string(i) + "_after.bin";
            util::FieldToJson(jdata_sub["after_file_name"], after_file_name.c_str(), json_options_);

            std::string filepath = gfxrecon::util::filepath::Join(json_options_.root_dir, after_file_name);
            WriteBinaryFile(filepath, resource_data.after_data, resource_data.offsets[i], resource_data.sizes[i]);
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
        TestWriteFloatResources(prefix_file_name, resources.copy_vertex_resources);

        // index
        TestWriteFloatResource(prefix_file_name, resources.copy_index_resource);

        // descriptor
        uint32_t index = 0;
        for (const auto& heap_data : resources.descriptor_heap_datas)
        {
            TestWriteFloatResources(prefix_file_name + "_heap_id_" +
                                        std::to_string(resources.target.descriptor_heap_ids[index]),
                                    heap_data.copy_constant_buffer_resources);

            for (const auto& shader_res : heap_data.copy_shader_resources)
            {
                if (shader_res.desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
                {
                    TestWriteFloatResource(prefix_file_name + "_heap_id_" +
                                               std::to_string(resources.target.descriptor_heap_ids[index]),
                                           shader_res);
                }
                else
                {
                    TestWriteImageResource(prefix_file_name + "_heap_id_" +
                                               std::to_string(resources.target.descriptor_heap_ids[index]),
                                           shader_res);
                }
            }
            ++index;
        }

        // render target
        TestWriteImageResources(prefix_file_name, resources.copy_render_target_resources);
        TestWriteImageResource(prefix_file_name, resources.copy_depth_stencil_resource);

        // ExecuteIndirect
        TestWriteFloatResource(prefix_file_name, resources.copy_exe_indirect_argument);
        TestWriteFloatResource(prefix_file_name, resources.copy_exe_indirect_count);
    }
}

void Dx12DumpResources::TestWriteFloatResources(const std::string&                   prefix_file_name,
                                                const std::vector<CopyResourceData>& resource_datas)
{
    for (const auto& resource : resource_datas)
    {
        TestWriteFloatResource(prefix_file_name, resource);
    }
}

void Dx12DumpResources::TestWriteFloatResource(const std::string&      prefix_file_name,
                                               const CopyResourceData& resource_data)
{
    std::string file_name = prefix_file_name + "_resource_id_" + std::to_string(resource_data.source_resource_id);

    if (!resource_data.before_data.empty())
    {
        auto* data_begin = reinterpret_cast<const float*>(resource_data.before_data.data());
        auto  size       = resource_data.offsets.size();
        for (uint32_t i = 0; i < size; ++i)
        {
            auto        data_begin_sub = data_begin + resource_data.offsets[i];
            uint32_t    size           = resource_data.sizes[i] / (sizeof(float));
            std::string data           = "";
            for (uint32_t i = 0; i < size; ++i)
            {
                data += std::to_string(data_begin_sub[i]);
                data += "\n";
            }

            std::string before_file_name = file_name + "_subresource_" + std::to_string(i) + "_before.txt";
            FILE*       file_handle;
            util::platform::FileOpen(&file_handle, before_file_name.c_str(), "w");
            util::platform::FilePuts(data.c_str(), file_handle);
            util::platform::FileClose(file_handle);
        }
    }
    if (!resource_data.after_data.empty())
    {
        auto* data_begin = reinterpret_cast<const float*>(resource_data.after_data.data());
        auto  size       = resource_data.offsets.size();
        for (uint32_t i = 0; i < size; ++i)
        {
            auto        data_begin_sub = data_begin + resource_data.offsets[i];
            uint32_t    size           = resource_data.sizes[i] / (sizeof(float));
            std::string data           = "";
            for (uint32_t i = 0; i < size; ++i)
            {
                data += std::to_string(data_begin_sub[i]);
                data += "\n";
            }

            std::string after_file_name = file_name + "_subresource_" + std::to_string(i) + "_after.txt";
            FILE*       file_handle;
            util::platform::FileOpen(&file_handle, after_file_name.c_str(), "w");
            util::platform::FilePuts(data.c_str(), file_handle);
            util::platform::FileClose(file_handle);
        }
    }
}

void Dx12DumpResources::TestWriteImageResources(const std::string&                   prefix_file_name,
                                                const std::vector<CopyResourceData>& resource_datas)
{
    for (const auto& resouce : resource_datas)
    {
        TestWriteImageResource(prefix_file_name, resouce);
    }
}

void Dx12DumpResources::TestWriteImageResource(const std::string&      prefix_file_name,
                                               const CopyResourceData& resource_data)
{
    std::string file_name = prefix_file_name + "_resource_id_" + std::to_string(resource_data.source_resource_id);

    if (!resource_data.before_data.empty())
    {
        auto size = resource_data.offsets.size();
        for (uint32_t i = 0; i < size; ++i)
        {
            std::string before_file_name = file_name + "_subresource_" + std::to_string(i);

            // WriteBmpImage expects 4 bytes per pixel.
            double bytes_per_pixel = static_cast<double>(resource_data.sizes[i]) /
                                     (static_cast<double>(resource_data.footprints[i].Footprint.RowPitch / 4) *
                                      resource_data.footprints[i].Footprint.Height);
            if (bytes_per_pixel != 4.0)
            {
                GFXRECON_LOG_WARNING("Dump images could not be created for before and after resource of "
                                     "'%s_before\\after.bmp'. Only formats "
                                     "with 4 bytes per pixel are supported. Current format %" PRIu32
                                     " is %.2f bytes per pixel.",
                                     before_file_name.c_str(),
                                     resource_data.footprints[i].Footprint.Format,
                                     bytes_per_pixel);
                continue;
            }

            before_file_name += "_before.bmp";
            if (!util::imagewriter::WriteBmpImage(before_file_name,
                                                  resource_data.footprints[i].Footprint.Width,
                                                  resource_data.footprints[i].Footprint.Height,
                                                  resource_data.sizes[i],
                                                  resource_data.before_data.data() + resource_data.offsets[i],
                                                  resource_data.footprints[i].Footprint.RowPitch))
            {
                GFXRECON_LOG_ERROR("Dump image could not be created: failed to write BMP file %s",
                                   before_file_name.c_str());
            }
        }
    }
    if (!resource_data.after_data.empty())
    {
        auto size = resource_data.offsets.size();
        for (uint32_t i = 0; i < size; ++i)
        {
            // WriteBmpImage expects 4 bytes per pixel.
            double bytes_per_pixel = static_cast<double>(resource_data.sizes[i]) /
                                     (static_cast<double>(resource_data.footprints[i].Footprint.RowPitch / 4) *
                                      resource_data.footprints[i].Footprint.Height);
            if (bytes_per_pixel != 4.0)
            {
                continue;
            }

            std::string after_file_name = file_name + "_subresource_" + std::to_string(i) + "_after.bmp";
            if (!util::imagewriter::WriteBmpImage(after_file_name,
                                                  resource_data.footprints[i].Footprint.Width,
                                                  resource_data.footprints[i].Footprint.Height,
                                                  resource_data.sizes[i],
                                                  resource_data.after_data.data() + resource_data.offsets[i],
                                                  resource_data.footprints[i].Footprint.RowPitch))
            {
                GFXRECON_LOG_ERROR("Dump image could not be created: failed to write BMP file %s",
                                   after_file_name.c_str());
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
