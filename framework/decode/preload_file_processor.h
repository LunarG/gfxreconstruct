/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H
#define GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H

#include <deque>

#include "decode/file_processor.h"
#include "format/format_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class PreloadFileProcessor : public FileProcessor
{
  public:
    using Base = FileProcessor;
    PreloadFileProcessor();

    // Preloads *count* frames to continuous, expandable memory buffer
    void PreloadNextFrames(size_t count);
    // Replaces ProcessBlocksOneFrame() to just read blocks into memory buffer
    bool PreloadBlocksOneFrame();

  private:
    bool ReadBytes(void* buffer, size_t buffer_size) override;
    bool SkipBytes(size_t skip_size) override;

    class BlockBuffer
    {
      public:
        bool IsValid() const { return data_.get() != nullptr; }
        bool IsEof() const { return read_pos_ >= size_; }

        template <typename T>
        bool Read(T& value)
        {
            bool success = Read<T>(value, read_pos_);
            if (success)
            {
                read_pos_ += sizeof(T);
            }
            return success;
        }

        template <typename T>
        bool Read(T& value, size_t at) const
        {
            // Ensure that this isn't being misused.
            static_assert(std::is_trivially_copyable_v<T>, "Read<T> requires a trivially copyable type");
            if (IsAvailableAt(sizeof(value), at))
            {
                memcpy(&value, data_.get() + at, sizeof(value));
                return true;
            }
            return false;
        }

        bool ReadBytes(void* buffer, size_t buffer_size);

        bool ReadBytes(void* buffer, size_t buffer_size, size_t at) const;

        size_t Size() const { return size_; }

        size_t ReadPos() const { return read_pos_; }

        BlockBuffer(const format::BlockHeader& header) : header_(header)
        {
            size_ = header.size + sizeof(header);
            data_ = std::make_unique<char[]>(size_);
            memcpy(data_.get(), &header, sizeof(header));
        }

        char* GetPayload() { return data_.get() + sizeof(format::BlockHeader); }

        bool IsFrameDelimiter(const FileProcessor& file_processor) const;

        bool SeekForward(size_t size);

        bool IsAvailable(size_t size) const { return IsAvailableAt(size, read_pos_); }
        bool IsAvailableAt(size_t size, size_t at) const { return Size() >= (at + size); }

      private:
        format::BlockHeader header_;
        size_t              size_{ 0 };
        size_t              read_pos_{ 0 };

        std::unique_ptr<char[]> data_;
    };

    void AdvanceBlockAtEof(const BlockBuffer& block_buffer);
    bool AddBlockBuffer(const format::BlockHeader& header);

    std::deque<BlockBuffer> pending_block_buffers_;
    std::deque<BlockBuffer> block_buffers_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H
