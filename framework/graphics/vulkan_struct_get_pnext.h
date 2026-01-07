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

//! concept definition for a vulkan-struct
template <class T>
concept VulkanStruct = requires(T t) {
    // sType exists and is accessible
    t.sType;

    // check type of sType
    requires std::is_same_v<decltype(t.sType), VkStructureType>;

    // pNext exists and is accessible
    t.pNext;

    // check type of pNext
    requires std::is_same_v<decltype(t.pNext), void*> || std::is_same_v<decltype(t.pNext), const void*> ||
                 std::is_same_v<decltype(t.pNext), const VkBaseInStructure*> ||
                 std::is_same_v<decltype(t.pNext), VkBaseOutStructure*>;
};

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
template <VulkanStruct T, VulkanStruct Parent_T>
static const T* vulkan_struct_get_pnext(const Parent_T* parent)
{
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
template <VulkanStruct T, VulkanStruct Parent_T>
static T* vulkan_struct_get_pnext(Parent_T* parent)
{
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

/**
 * @brief   vulkan_struct_remove_pnext can be used to remove elements in-place from a
 *          provided structure's pNext-chain by their type.
 *
 * Searches through the parent's pNext-chain for the first struct with the requested struct_type.
 * @p T and @p Parent_T must be Vulkan structure-types. Returns nullptr if no matching struct could be found.
 *
 * @tparam  T           the structure-type to remove from pNext-chain
 * @tparam  Parent_T    implicit type of provided structure
 * @param   parent      pointer to a non-const vulkan-structure containing a pNext-chain.
 * @return  a typed pointer to a structure removed from the pNext-chain or nullptr.
 */
template <VulkanStruct T, VulkanStruct Parent_T>
static T* vulkan_struct_remove_pnext(Parent_T* parent)
{
    if (parent != nullptr)
    {
        auto prev_struct    = reinterpret_cast<VkBaseOutStructure*>(parent);
        auto current_struct = reinterpret_cast<VkBaseOutStructure*>(parent)->pNext;

        while (current_struct != nullptr)
        {
            if (current_struct->sType == gfxrecon::util::GetSType<T>())
            {
                prev_struct->pNext = current_struct->pNext;
                return reinterpret_cast<T*>(current_struct);
            }
            prev_struct    = current_struct;
            current_struct = current_struct->pNext;
        }
    }
    return nullptr;
}

/**
 * @brief   vulkan_struct_add_pnext can be used to add elements into a pNext-chain.
 *
 * Searches through the parent's pNext-chain to avoid duplicates. Inserts 'pnext_struct' at front of pNext-chain.
 *
 * @tparam  T           the structure-type added to the pNext-chain
 * @tparam  Parent_T    implicit type of provided structure
 * @param   parent      pointer to a non-const vulkan-structure containing a pNext-chain.
 */
template <VulkanStruct T, VulkanStruct Parent_T>
static void vulkan_struct_add_pnext(Parent_T* parent, T* pnext_struct)
{
    // remove potential duplicate
    vulkan_struct_remove_pnext<T>(parent);

    if (parent != nullptr && pnext_struct != nullptr)
    {
        // cast input-pointers to VkBaseOutStructure*
        auto* parent_out       = reinterpret_cast<VkBaseOutStructure*>(parent);
        auto* pnext_struct_out = reinterpret_cast<VkBaseOutStructure*>(pnext_struct);

        // insert pnext_struct at front of pNext-chain
        auto* current_pnext     = parent_out->pNext;
        parent_out->pNext       = pnext_struct_out;
        pnext_struct_out->pNext = current_pnext;
    }
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_STRUCT_GET_PNEXT_H