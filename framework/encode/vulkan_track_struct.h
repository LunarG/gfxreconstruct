/*
** Copyright (c) 2024 LunarG, Inc.
** Copyright (c) 2018-2023 Valve Corporation
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

#include "graphics/vulkan_struct_deep_copy.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(vulkan_trackers)

/**
 * @brief   TrackStruct can be used to track (deep-copy) a provided vulkan-struct-pointer.
 *
 * @param   value       pointer to an arbitrary vulkan-struct.
 * @param   out_data    reference to an output std::unique_pointer
 * @return  a void-pointer to the tracked struct-memory.
 */
inline void* TrackStruct(const void* value, std::unique_ptr<uint8_t[]>& out_data)
{
    size_t num_bytes = graphics::vulkan_struct_deep_copy_pnext(value, nullptr);
    out_data         = std::make_unique<uint8_t[]>(num_bytes);
    graphics::vulkan_struct_deep_copy_pnext(value, out_data.get());
    return out_data.get();
}

/**
 * @brief   TrackStructs can be used to track (deep-copy) an array of vulkan-structures.
 *
 * @tparam  T           structure-type
 * @param   structs     an array of vulkan-structures
 * @param   count       element count in structs-array
 * @param   out_data    reference to an output-array or nullptr
 * @return  a typed pointer to the beginning of the tracked struct-memory.
 */
template <typename T>
inline T* TrackStructs(const T* structs, uint32_t count, std::unique_ptr<uint8_t[]>& out_data)
{
    size_t num_bytes = graphics::vulkan_struct_deep_copy(structs, count, nullptr);
    out_data         = std::make_unique<uint8_t[]>(num_bytes);
    graphics::vulkan_struct_deep_copy(structs, count, out_data.get());
    return reinterpret_cast<T*>(out_data.get());
}

GFXRECON_END_NAMESPACE(vulkan_trackers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
