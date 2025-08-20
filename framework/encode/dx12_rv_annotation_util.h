/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_RV_ANNOTATION_UTIL_H
#define GFXRECON_ENCODE_RV_ANNOTATION_UTIL_H

#include "util/defines.h"

#include <map>
#include <memory>
#include <vector>

#if defined(WIN32)
#include <D3D12.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class RvAnnotationUtil
{
  public:
    static constexpr uint8_t kMaskSizeOfBits = 16;

    static constexpr uint16_t kGPUVAMask      = 0x7ABC;
    static constexpr uint16_t kDescriptorMask = 0x5DEF;
    static constexpr uint64_t kShaderIDMask   = 0x57BD37BD12345678ull;

#if defined(WIN32)
    static void AddRvAnnotation(D3D12_GPU_VIRTUAL_ADDRESS* result);

    static void AddRvAnnotation(D3D12_GPU_DESCRIPTOR_HANDLE* result);

    static void AddRvAnnotation(void** result);

    static void RemoveRvAnnotation(D3D12_GPU_VIRTUAL_ADDRESS& value);

    static void RemoveRvAnnotation(D3D12_GPU_DESCRIPTOR_HANDLE& value);

    template <class T, class... Dependencies>
    static std::unique_ptr<T> RemoveStructRvAnnotations(const T* structure, Dependencies&... dependences)
    {
        std::unique_ptr<T> unannotated_structs = std::make_unique<T>();
        *unannotated_structs                   = *structure;
        RemoveStructRvAnnotation(*unannotated_structs, dependences...);
        return std::move(unannotated_structs);
    }

    template <class T, class... Dependencies>
    static std::unique_ptr<T[]> RemoveStructArrayRvAnnotations(const T* structures, UINT count)
    {
        std::unique_ptr<T[]> unannotated_structs = std::make_unique<T[]>(count);
        for (UINT idx = 0; idx < count; ++idx)
        {
            unannotated_structs[idx] = structures[idx];
            RemoveStructRvAnnotation(unannotated_structs[idx]);
        }
        return std::move(unannotated_structs);
    }

    template <class T, class... Dependencies>
    static std::unique_ptr<T> AddStructRvAnnotations(const T* structure, Dependencies&... dependences)
    {
        std::unique_ptr<T> annotated_structs = std::make_unique<T>();
        *annotated_structs                   = *structure;
        AddStructRvAnnotation(*annotated_structs, dependences...);
        return std::move(annotated_structs);
    }

    template <class T, class... Dependencies>
    static std::unique_ptr<T[]> AddStructArrayRvAnnotations(const T* structures, UINT count)
    {
        std::unique_ptr<T[]> annotated_structs = std::make_unique<T[]>(count);
        for (UINT idx = 0; idx < count; ++idx)
        {
            annotated_structs[idx] = structures[idx];
            AddStructRvAnnotation(annotated_structs[idx]);
        }
        return std::move(annotated_structs);
    }

  private:
    static void RemoveStructRvAnnotation(D3D12_INDEX_BUFFER_VIEW& param);

    static void RemoveStructRvAnnotation(D3D12_VERTEX_BUFFER_VIEW& param);

    static void RemoveStructRvAnnotation(D3D12_STREAM_OUTPUT_BUFFER_VIEW& param);

    static void RemoveStructRvAnnotation(D3D12_CONSTANT_BUFFER_VIEW_DESC& param);

    static void RemoveStructRvAnnotation(D3D12_SHADER_RESOURCE_VIEW_DESC& param);

    static void RemoveStructRvAnnotation(D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& param);

    static void RemoveStructRvAnnotation(D3D12_DISPATCH_RAYS_DESC& param);

    static void RemoveStructRvAnnotation(D3D12_RAYTRACING_GEOMETRY_DESC& params);

    static void RemoveStructRvAnnotation(D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& param,
                                         std::unique_ptr<D3D12_RAYTRACING_GEOMETRY_DESC[]>&  geometry_desc);

    static void RemoveStructRvAnnotation(D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& param,
                                         std::unique_ptr<D3D12_RAYTRACING_GEOMETRY_DESC[]>&    geometry_descs);

    static void RemoveStructRvAnnotation(D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& param);

    static void RemoveStructRvAnnotation(D3D12_GPU_VIRTUAL_ADDRESS& param);

    static void AddStructRvAnnotation(D3D12_INDEX_BUFFER_VIEW& param);

    static void AddStructRvAnnotation(D3D12_VERTEX_BUFFER_VIEW& param);

    static void AddStructRvAnnotation(D3D12_STREAM_OUTPUT_BUFFER_VIEW& param);

    static void AddStructRvAnnotation(D3D12_CONSTANT_BUFFER_VIEW_DESC& param);

    static void AddStructRvAnnotation(D3D12_SHADER_RESOURCE_VIEW_DESC& param);

    static void AddStructRvAnnotation(D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& param);

    static void AddStructRvAnnotation(D3D12_DISPATCH_RAYS_DESC& param);

    static void AddStructRvAnnotation(D3D12_RAYTRACING_GEOMETRY_DESC& params);

    static void AddStructRvAnnotation(D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& param,
                                      std::unique_ptr<D3D12_RAYTRACING_GEOMETRY_DESC[]>&  geometry_desc);

    static void AddStructRvAnnotation(D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& param,
                                      std::unique_ptr<D3D12_RAYTRACING_GEOMETRY_DESC[]>&    geometry_descs);

    static void AddStructRvAnnotation(D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& param);

    static void AddStructRvAnnotation(D3D12_GPU_VIRTUAL_ADDRESS& param);
#endif
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_RV_ANNOTATION_UTIL_H
