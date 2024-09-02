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

#ifndef GFXRECON_GRAPHICS_VULKAN_STRUCT_GET_PNEXT_H
#define GFXRECON_GRAPHICS_VULKAN_STRUCT_GET_PNEXT_H

#include "util/defines.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_stype_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

template <typename T, typename = int>
struct is_vulkan_struct : std::false_type
{};

template <typename T>
struct is_vulkan_struct<T, decltype((void)T::sType, 0)>
    : std::is_same<decltype(T::sType), VkStructureType>
{};

template <typename T>
inline constexpr bool is_vulkan_struct_v = is_vulkan_struct<T>::value;

/**
 * @brief   vulkan_struct_get_pnext can be used to retrieve elements of a
 *          provided structure's pNext-chain by their type.
 *
 * Searches through the parent's pNext-chain for the first struct with the requested struct_type.
 * @p T and @p Parent_T must be Vulkan structure-types. Returns nullptr if no matching struct could be found.

 * @tparam  T           the structure-type to retrieve from pNext-chain
 * @tparam  Parent_T    implicit type of provided structure
 * @param   parent      pointer to a const vulkan-structure containing a pNext-chain.
 * @return  a typed const-pointer to a structure found in the pNext-chain or nullptr.
 */
template <typename T, typename Parent_T>
static const T* vulkan_struct_get_pnext(const Parent_T* parent)
{
    static_assert(is_vulkan_struct<T>() && is_vulkan_struct<Parent_T>());

    if (parent != nullptr)
    {
        auto current_struct = reinterpret_cast<const VkBaseInStructure*>(parent->pNext);

        while (current_struct != nullptr)
        {
            if (current_struct->sType == gfxrecon::util::GetSType<T>())
            {
                return reinterpret_cast<const T*>(current_struct);
            }
            current_struct = current_struct->pNext;
        }
    }
    return nullptr;
}

/**
 * @brief   vulkan_struct_get_pnext can be used to retrieve elements of a
 *          provided structure's pNext-chain by their type.
 *
 * Searches through the parent's pNext-chain for the first struct with the requested struct_type.
 * @p T and @p Parent_T must be Vulkan structure-types. Returns nullptr if no matching struct could be found.
 *
 * @tparam  T           the structure-type to retrieve from pNext-chain
 * @tparam  Parent_T    implicit type of provided structure
 * @param   parent      pointer to a non-const vulkan-structure containing a pNext-chain.
 * @return  a typed pointer to a structure found in the pNext-chain or nullptr.
 */
template <typename T, typename Parent_T>
static T* vulkan_struct_get_pnext(Parent_T* parent)
{
    static_assert(is_vulkan_struct<T>() && is_vulkan_struct<Parent_T>());

    if (parent != nullptr)
    {
        auto current_struct = reinterpret_cast<VkBaseOutStructure*>(parent)->pNext;

        while (current_struct != nullptr)
        {
            if (current_struct->sType == gfxrecon::util::GetSType<T>())
            {
                return reinterpret_cast<T*>(current_struct);
            }
            current_struct = current_struct->pNext;
        }
    }
    return nullptr;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_STRUCT_GET_PNEXT_H