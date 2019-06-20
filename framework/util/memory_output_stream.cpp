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

#include "util/memory_output_stream.h"

#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

MemoryOutputStream::MemoryOutputStream()
{
    buffer_.reserve(kDefaultBufferSize);
}

MemoryOutputStream::MemoryOutputStream(size_t initial_size)
{
    buffer_.reserve(initial_size);
}

MemoryOutputStream::MemoryOutputStream(const void* initial_data, size_t initial_data_size)
{
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(initial_data);
    buffer_.insert(buffer_.end(), bytes, bytes + initial_data_size);
}

MemoryOutputStream::~MemoryOutputStream() {}

size_t MemoryOutputStream::Write(const void* data, size_t len)
{
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
    buffer_.insert(buffer_.end(), bytes, bytes + len);

    return len;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
