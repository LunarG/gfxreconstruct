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

#include "decode/file_processor.h"
#include "format/format_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class PreloadFileProcessor : public FileProcessor
{
  public:
    PreloadFileProcessor();

    // Preloads *count* frames to continuous, expandable memory buffer
    void PreloadNextFrames(size_t count);

  private:
    class PreloadBuffer
    {
      public:
        PreloadBuffer();

        // Ensures the buffer can store additional *size* bytes
        void Reserve(size_t size);

        // Copies the preloaded data from the internal container into the provided destination buffer
        // Accounts for current replay position
        size_t Read(void* destination, size_t destination_size);

        // Copies provided object of type T into the preload buffer
        // Returns a pointer to inserted object in the container
        template <typename T>
        inline void* Add(T* data)
        {
            return &*container_.insert(
                container_.end(), reinterpret_cast<char*>(data), reinterpret_cast<char*>(data) + sizeof(T));
        }

        // Allocates *size* bytes in the preload buffer
        // Returns the pointer to initialized memory
        inline void* Add(size_t size) { return &*container_.insert(container_.end(), size, 0); }

        // Indicates whether the preloaded calls have been replayed in full
        inline bool ReplayFinished() { return !container_.empty() && replay_offset_ >= container_.size(); }

        // Clears the preload buffer, resets internal state
        void Reset();

      private:
        std::vector<char> container_;
        size_t            replay_offset_;

    } preload_buffer_;

    enum class PreloadStatus
    {
        kInactive,
        kRecord,
        kReplay
    } status_;

    bool ProcessBlocks() override;

    bool ReadBytes(void* buffer, size_t buffer_size) override;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H
