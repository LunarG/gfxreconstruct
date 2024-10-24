/*
** Copyright (c) 2020-2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_COMMON_HANDLE_MAPPERS_H
#define GFXRECON_DECODE_COMMON_HANDLE_MAPPERS_H

template <typename T>
void MapStructArrayHandles(T* structs, size_t len, const CommonObjectInfoTable& object_info_table)
{
    if (structs != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            MapStructHandles(&structs[i], object_info_table);
        }
    }
}

template <typename T>
void AddStructArrayHandles(format::HandleId               parent_id,
                           const T*                       id_wrappers,
                           size_t                         id_len,
                           const typename T::struct_type* handle_structs,
                           size_t                         handle_len,
                           CommonObjectInfoTable*         object_info_table)
{
    if (id_wrappers != nullptr && handle_structs != nullptr)
    {
        // TODO: Improved handling of array size mismatch.
        size_t len = std::min(id_len, handle_len);
        for (size_t i = 0; i < len; ++i)
        {
            AddStructHandles(parent_id, &id_wrappers[i], &handle_structs[i], object_info_table);
        }
    }
}

template <typename T>
void SetStructArrayHandleLengths(T* wrappers, size_t len)
{
    if (wrappers != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            SetStructHandleLengths(&wrappers[i]);
        }
    }
}

#endif // GFXRECON_DECODE_COMMON_HANDLE_MAPPERS_H
