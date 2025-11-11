/*
** Copyright (c) 2022 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#include "dx12_file_optimizer.h"

#include "format/format_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

void Dx12FileOptimizer::SetFillCommandResourceValues(
    const decode::Dx12FillCommandResourceValueMap* fill_command_resource_values,
    bool                                           inject_noop_resource_value_optimization)
{
    inject_noop_resource_value_optimization_ = inject_noop_resource_value_optimization;

    fill_command_resource_values_ = fill_command_resource_values;
    if (fill_command_resource_values_ != nullptr)
    {
        // A NOOP RV optimization block should only be added if there weren't any real fill_command_resource_values
        // found.
        GFXRECON_ASSERT((inject_noop_resource_value_optimization_ == false) || fill_command_resource_values->empty());

        resource_values_iter_ = fill_command_resource_values_->begin();
    }
}

bool Dx12FileOptimizer::AddFillMemoryResourceValueCommand()
{
    bool success = true;

    GFXRECON_ASSERT(resource_values_iter_->first == GetCurrentBlockIndex());

    format::FillMemoryResourceValueCommandHeader rv_header;
    rv_header.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    rv_header.meta_header.meta_data_id      = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_D3D12,
                                                                format::MetaDataType::kFillMemoryResourceValueCommand);
    rv_header.thread_id                     = 0;
    rv_header.resource_value_count          = resource_values_iter_->second.size();

    size_t       header_size = sizeof(format::FillMemoryResourceValueCommandHeader);
    const size_t uncompressed_size =
        resource_values_iter_->second.size() * (sizeof(format::ResourceValueType) + sizeof(uint64_t));

    bool not_compressed = true;

    if (uncompressed_size > 0)
    {
        write_buffer_.clear();
        write_buffer_.resize(uncompressed_size);

        // Write resource value data to uncompressed buffer.
        auto type_data_pos = write_buffer_.data();
        auto offset_data_pos =
            write_buffer_.data() + (rv_header.resource_value_count * sizeof(format::ResourceValueType));
        for (const auto& resource_value_pair : resource_values_iter_->second)
        {
            auto type   = resource_value_pair.type;
            auto offset = resource_value_pair.offset;

            util::platform::MemoryCopy(type_data_pos, sizeof(type), &type, sizeof(type));
            util::platform::MemoryCopy(offset_data_pos, sizeof(offset), &offset, sizeof(offset));

            type_data_pos += sizeof(resource_value_pair.type);
            offset_data_pos += sizeof(resource_value_pair.offset);
        }
        GFXRECON_ASSERT(type_data_pos ==
                        (write_buffer_.data() + (rv_header.resource_value_count * sizeof(format::ResourceValueType))));
        GFXRECON_ASSERT(offset_data_pos == (write_buffer_.data() + uncompressed_size));

        std::vector<uint8_t> compressed_write_buffer;

        if (GetCompressor() != nullptr)
        {
            size_t compressed_size =
                GetCompressor()->Compress(write_buffer_.size(), write_buffer_.data(), &compressed_write_buffer, 0);

            if ((compressed_size > 0) && (compressed_size < uncompressed_size))
            {
                not_compressed = false;

                // Calculate size of packet with compressed data size.
                rv_header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(rv_header) + compressed_size;
                rv_header.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                success = success && WriteBytes(&rv_header, header_size);
                success = success && WriteBytes(compressed_write_buffer.data(), compressed_size);
            }
        }
    }

    // If the data was not compressed, write the uncompressed data here.
    if (not_compressed)
    {
        // Calculate size of packet with uncompressed data size.
        rv_header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(rv_header) + uncompressed_size;

        success = success && WriteBytes(&rv_header, header_size);
        success = success && WriteBytes(write_buffer_.data(), uncompressed_size);
    }

    ++resource_values_iter_;
    ++num_optimized_fill_commands_;

    return success;
}

template <typename Args>
decode::FileTransformer::VisitResult Dx12FileOptimizer::VisitMetaData([[maybe_unused]] const Args& args)
{
    constexpr bool kIsFillMemoryCommand      = std::is_same_v<decode::FillMemoryArgs, Args>;
    constexpr bool kIsInitSubresourceCommand = std::is_same_v<decode::InitSubresourceArgs, Args>;
    // If needed, add a FillMemoryResourceValueCommand before the fill memory command.
    if constexpr (kIsFillMemoryCommand || kIsInitSubresourceCommand)
    {
        GFXRECON_ASSERT(!kIsFillMemoryCommand ||
                        (format::MetaDataType::kFillMemoryCommand == format::GetMetaDataType(args.meta_data_id)));
        GFXRECON_ASSERT(!kIsInitSubresourceCommand ||
                        (format::MetaDataType::kInitSubresourceCommand == format::GetMetaDataType(args.meta_data_id)));

        if ((fill_command_resource_values_ != nullptr) && (!fill_command_resource_values_->empty()))
        {
            if ((resource_values_iter_ != fill_command_resource_values_->end()) &&
                (resource_values_iter_->first == GetCurrentBlockIndex()))
            {
                if (!AddFillMemoryResourceValueCommand())
                {
                    GFXRECON_LOG_ERROR("Failed to write the FillMemoryResourceValueCommand needed for DXR or EI "
                                       "optimization. Optimized file may be invalid.");
                }
            }
        }
        else if (inject_noop_resource_value_optimization_)
        {
            // Only inject one noop block.
            inject_noop_resource_value_optimization_ = false;

            decode::Dx12FillCommandResourceValueMap rvm;
            rvm[GetCurrentBlockIndex()]   = {};
            fill_command_resource_values_ = &rvm;
            resource_values_iter_         = fill_command_resource_values_->begin();

            if (!AddFillMemoryResourceValueCommand())
            {
                GFXRECON_LOG_ERROR("Failed to write the FillMemoryResourceValueCommand needed for DXR/EI optimization. "
                                   "Optimized file may be invalid.");
            }

            fill_command_resource_values_ = nullptr;
            resource_values_iter_         = {};
        }
    }

    // Always passthrough, even on failure.
    return kNeedsPassthrough;
}

bool Dx12FileOptimizer::ProcessMetaData(decode::ParsedBlock& parsed_block)
{
    auto                meta_visitor = [this](const auto& store) { return VisitMetaData(*store); };
    VisitResult         result       = std::visit(meta_visitor, parsed_block.GetArgs());

    if (result == kNeedsPassthrough)
    {
        return FileOptimizer::ProcessMetaData(parsed_block);
    }

    return result == kSuccess;
}

GFXRECON_END_NAMESPACE(gfxrecon)
