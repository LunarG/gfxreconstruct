/*
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

#ifndef BRIMSTONE_FORMAT_STRING_ARRAY_DECODER_H
#define BRIMSTONE_FORMAT_STRING_ARRAY_DECODER_H

#include <memory>

#include "util/defines.h"
#include "format/pointer_decoder_base.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class StringArrayDecoder : public PointerDecoderBase
{
public:
    StringArrayDecoder() { }

    ~StringArrayDecoder() { DestroyStrings(); }

    uint32_t* GetStringAttributes() const { return string_attributes_.get(); }

    uint64_t* GetStringAddresses() const { return string_addresses_.get(); }

    size_t* GetStringLengths() const { return string_lengths_.get(); }

    char** GetPointer() const { return strings_.get(); }

    size_t Decode(const uint8_t* buffer, size_t buffer_size);

private:
    void DestroyStrings();

private:
    std::unique_ptr<char*[]>        strings_;
    std::unique_ptr<uint32_t[]>     string_attributes_;
    std::unique_ptr<uint64_t[]>     string_addresses_;
    std::unique_ptr<size_t[]>       string_lengths_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_POINTER_DECODER_H
