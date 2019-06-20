/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_UTIL_MEMORY_OUTPUT_STREAM_H
#define GFXRECON_UTIL_MEMORY_OUTPUT_STREAM_H

#include "util/defines.h"
#include "util/output_stream.h"

#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class MemoryOutputStream : public OutputStream
{
  public:
    const size_t kDefaultBufferSize = 512;

  public:
    MemoryOutputStream();

    MemoryOutputStream(size_t initial_size);

    MemoryOutputStream(const void* initial_data, size_t initial_data_size);

    virtual ~MemoryOutputStream() override;

    virtual bool IsValid() override { return true; }

    virtual void Reset() override { buffer_.clear(); };

    virtual size_t Write(const void* data, size_t len) override;

    const uint8_t* GetData() const { return buffer_.data(); }

    size_t GetDataSize() const { return buffer_.size(); }

  private:
    std::vector<uint8_t> buffer_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_MEMORY_OUTPUT_STREAM_H
