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

#ifndef GFXRECON_UTIL_OUTPUT_STREAM_H
#define GFXRECON_UTIL_OUTPUT_STREAM_H

#include "util/defines.h"

#include <cstddef>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class OutputStream
{
  public:
    virtual ~OutputStream() {}

    virtual bool IsValid() { return false; }

    virtual void Reset() {}

    virtual size_t Write(const void* data, size_t len) = 0;

    virtual void Flush() {}
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_OUTPUT_STREAM_H
