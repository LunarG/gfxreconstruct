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
    // before
    if (resource_data.before_resource)
    {
        util::FieldToJson(jdata["resource_id"], resource_data.source_resource_id, json_options_);
        util::FieldToJson(jdata["offset"], resource_data.source_offset, json_options_);
        util::FieldToJson(jdata["size"], resource_data.source_size, json_options_);

        std::string file_name =
            prefix_file_name + "_resource_id_" + std::to_string(resource_data.source_resource_id) + "_before.bin";
        util::FieldToJson(jdata["before_file_name"], file_name.c_str(), json_options_);

        uint8_t* data_begin;
        auto     hr = resource_data.before_resource->Map(0, nullptr, reinterpret_cast<void**>(&data_begin));
        if (!SUCCEEDED(hr))
        {
            GFXRECON_LOG_ERROR("Failed to map resource data for before resource %" PRIu64,
                               resource_data.source_resource_id);
        }

        std::string filepath = gfxrecon::util::filepath::Join(json_options_.root_dir, file_name);
        WriteBinaryFile(filepath, resource_data.source_size, data_begin);

        resource_data.before_resource->Unmap(0, nullptr);
    }
    // after
    if (resource_data.after_resource)
    {
        std::string file_name =
            prefix_file_name + "_resource_id_" + std::to_string(resource_data.source_resource_id) + "_after.bin";
        util::FieldToJson(jdata["after_file_name"], file_name.c_str(), json_options_);

        uint8_t* data_begin;
        auto     hr = resource_data.after_resource->Map(0, nullptr, reinterpret_cast<void**>(&data_begin));
        if (!SUCCEEDED(hr))
        {
            GFXRECON_LOG_ERROR("Failed to map resource data for after resource %" PRIu64,
                               resource_data.source_resource_id);
        }

        std::string filepath = gfxrecon::util::filepath::Join(json_options_.root_dir, file_name);
        WriteBinaryFile(filepath, resource_data.source_size, data_begin);

        resource_data.after_resource->Unmap(0, nullptr);
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
            std::string filename =
                json_options_.data_sub_dir + "_heap_id_" + std::to_string(resources.target.descriptor_heap_ids[index]);
            WriteResources(
                jdata["descriptor_heap"][index]["constant_buffer"], filename, heap_data.copy_constant_buffer_resources);
            WriteResources(
                jdata["descriptor_heap"][index]["shader_resource"], filename, heap_data.copy_shader_resources);
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

    if (resource_data.before_resource)
    {
        float*      data_begin;
        D3D12_RANGE read_Range = { 0, 0 };
        resource_data.before_resource->Map(0, &read_Range, reinterpret_cast<void**>(&data_begin));

        uint32_t    size = resource_data.source_size / (sizeof(float));
        std::string data = "";
        for (uint32_t i = 0; i < size; ++i)
        {
            data += std::to_string(data_begin[i]);
            data += "\n";
        }
        resource_data.before_resource->Unmap(0, nullptr);

        std::string before_file_name = file_name + "_before.txt";
        FILE*       file_handle;
        util::platform::FileOpen(&file_handle, before_file_name.c_str(), "w");
        util::platform::FilePuts(data.c_str(), file_handle);
        util::platform::FileClose(file_handle);
    }
    if (resource_data.after_resource)
    {
        float*      data_begin;
        D3D12_RANGE read_Range = { 0, 0 };

        resource_data.after_resource->Map(0, &read_Range, reinterpret_cast<void**>(&data_begin));

        uint32_t    size = resource_data.source_size / (sizeof(float));
        std::string data = "";
        for (uint32_t i = 0; i < size; ++i)
        {
            data += std::to_string(data_begin[i]);
            data += "\n";
        }
        resource_data.after_resource->Unmap(0, nullptr);

        std::string after_file_name = file_name + "_after.txt";
        FILE*       file_handle;
        util::platform::FileOpen(&file_handle, after_file_name.c_str(), "w");
        util::platform::FilePuts(data.c_str(), file_handle);
        util::platform::FileClose(file_handle);
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

    // WriteBmpImage expects 4 bytes per pixel.
    double bytes_per_pixel = static_cast<double>(resource_data.source_size) /
                             (static_cast<double>(resource_data.source_footprint.Footprint.RowPitch / 4) *
                              resource_data.source_footprint.Footprint.Height);
    if (bytes_per_pixel != 4.0)
    {
        GFXRECON_LOG_WARNING("Dump images could not be created for before and after resource of '%s'. Only formats "
                             "with 4 bytes per pixel are supported. Current format %" PRIu32
                             " is %.2f bytes per pixel.",
                             file_name.c_str(),
                             resource_data.source_footprint.Footprint.Format,
                             bytes_per_pixel);
        return;
    }

    if (resource_data.before_resource)
    {
        std::string before_file_name = file_name + "_before.bmp";

        uint8_t*    data_begin;
        D3D12_RANGE read_Range = { 0, 0 };
        resource_data.before_resource->Map(0, &read_Range, reinterpret_cast<void**>(&data_begin));

        if (!util::imagewriter::WriteBmpImage(before_file_name,
                                              resource_data.source_footprint.Footprint.Width,
                                              resource_data.source_footprint.Footprint.Height,
                                              resource_data.source_size,
                                              data_begin,
                                              resource_data.source_footprint.Footprint.RowPitch))
        {
            GFXRECON_LOG_ERROR("Dump image could not be created: failed to write BMP file %s",
                               before_file_name.c_str());
        }
        resource_data.before_resource->Unmap(0, nullptr);
    }
    if (resource_data.after_resource)
    {
        std::string after_file_name = file_name + "_after.bmp";

        uint8_t*    data_begin;
        D3D12_RANGE read_Range = { 0, 0 };
        resource_data.after_resource->Map(0, &read_Range, reinterpret_cast<void**>(&data_begin));

        if (!util::imagewriter::WriteBmpImage(after_file_name,
                                              resource_data.source_footprint.Footprint.Width,
                                              resource_data.source_footprint.Footprint.Height,
                                              resource_data.source_size,
                                              data_begin,
                                              resource_data.source_footprint.Footprint.RowPitch))
        {
            GFXRECON_LOG_ERROR("Dump image could not be created: failed to write BMP file %s", after_file_name.c_str());
        }
        resource_data.after_resource->Unmap(0, nullptr);
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

bool Dx12DumpResources::WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data)
{
    FILE* file_output = nullptr;
    if (util::platform::FileOpen(&file_output, filename.c_str(), "wb") == 0)
    {
        util::platform::FileWrite(data, static_cast<size_t>(data_size), 1, file_output);
        util::platform::FileClose(file_output);
        return true;
    }
    return false;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
