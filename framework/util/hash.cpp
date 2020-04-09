/*
** Copyright (c) 2020 Valve Corporation
** Copyright (c) 2020 LunarG, Inc.
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

#include "util/hash.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(hash)

uint32_t CheckSum(const uint32_t* code, size_t code_size)
{
    uint32_t sum            = 0;
    size_t   uint_code_size = code_size / sizeof(uint32_t);
    for (size_t i = 0; i < uint_code_size; i++)
    {
        uint32_t u = code[i];
        uint32_t s = i % 32;
        sum ^= (u << s) | (u >> (32 - s));
    }
    return sum;
}

GFXRECON_END_NAMESPACE(hash)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
