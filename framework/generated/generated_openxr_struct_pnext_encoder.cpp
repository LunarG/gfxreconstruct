/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos OpenXR XML API Registry.
**
*/

#ifdef ENABLE_OPENXR_SUPPORT

#include "generated/generated_openxr_struct_encoders.h"

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/openxr_capture_manager.h"
#include "util/defines.h"

#include "openxr/openxr.h"
#include "openxr/openxr_platform.h"

#include <cassert>
#include <cstdio>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodePNextStruct(ParameterEncoder* encoder, const void* value)
{
    assert(encoder != nullptr);

    auto base = reinterpret_cast<const XrBaseInStructure*>(value);

    // Ignore the structures added to the pnext chain by the loader.
    while ((base != nullptr)
    {
        base = base->pNext;
    }

    if (base != nullptr)
    {
        switch (base->sType)
        {
        default:
            {
                // pNext is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see if it points to a recognized value.
                int32_t message_size = std::snprintf(nullptr, 0, "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);
                std::unique_ptr<char[]> message = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.
                std::snprintf(message.get(), (message_size + 1), "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);
                OpenXrCaptureManager::Get()->WriteDisplayMessageCmd(message.get());
                GFXRECON_LOG_WARNING("%s", message.get());
                EncodePNextStruct(encoder, base->pNext);
            }
            break;
        }
    }
    else
    {
        // pNext was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.
        encoder->EncodeStructPtrPreamble(nullptr);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
