/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_VULKAN_STRUCT_DEEP_COPY_H
#define GFXRECON_GRAPHICS_VULKAN_STRUCT_DEEP_COPY_H

#include "util/defines.h"
#include <cstddef>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

/**
 * @brief   vulkan_struct_deep_copy can be used to create deep-copies of vulkan-structures.
 *
 * In addition to copying the structs, all pointer-members, including pNext-chains,
 * are copied recursively, and the copied pointers adjusted to point into output-memory.
 * All data is stored in a provided, contiguous memory-block.
 * To determine the required amount of memory for the operation, run it dry once
 * by setting out_data to nullptr and use the return-value to allocate enough space.
 *
 * @tparam  T           structure-type
 * @param   structs     an array of vulkan-structures
 * @param   count       element count in structs-array
 * @param   out_data    pointer to an output-array or nullptr
 * @return  number of bytes required for deep-copy
 */
template <typename T>
size_t vulkan_struct_deep_copy(const T* structs, uint32_t count, uint8_t* out_data);

/**
 * @brief   vulkan_struct_deep_copy_pnext is similar to 'vulkan_struct_deep_copy',
 *          with additional type-resolution based on sType-member.
 *
 * @param   pNext       a pointer to a pNext-chain
 * @param   out_data    pointer to an output-array or nullptr
 * @return  number of bytes required for deep-copy
 */
size_t vulkan_struct_deep_copy_pnext(const void* pNext, uint8_t* out_data);

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_STRUCT_DEEP_COPY_H