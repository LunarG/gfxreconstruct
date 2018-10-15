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

#include "format/format_util.h"
#include "util/logging.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

bool ValidateFileHeader(const FileHeader& header)
{
    bool valid = true;

    if (header.fourcc != BRIMSTONE_FOURCC)
    {
        BRIMSTONE_LOG_ERROR("Invalid file: File header does not contain the expected unrecognized four character code.");
        valid = false;
    }

    // TODO: Verify version is supported.

    return valid;
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
