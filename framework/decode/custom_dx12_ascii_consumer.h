/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_CUSTOM_DX12_ASCII_CONSUMER_H
#define GFXRECON_CUSTOM_DX12_ASCII_CONSUMER_H

#include "decode/custom_dx12_struct_decoders.h"
#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "generated/generated_dx12_struct_decoders.h"
#include "generated/generated_dx12_struct_to_string.h"
#include "generated/generated_dx12_enum_to_string.h"
#include "util/defines.h"
#include "util/to_string.h"
#include "custom_dx12_to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

///////////////////////////////////////////////////////////////////////////////
// NOTE : It would be much nicer to route return values through the generic
//  ToString() mechanism...it will take some thought to figure out how to do
//  that in the generators in a straight forward way...ultimately it's only a
//  handful of API calls that need this treatment so it's not pressing.
template <typename DX12ReturnType>
inline std::string DX12ReturnValueToString(const DX12ReturnType& return_value,
                                           util::ToStringFlags   to_string_flags,
                                           uint32_t              tab_count,
                                           uint32_t              tab_size)
{
    return util::ToString(return_value, to_string_flags, tab_count, tab_size);
}

template <>
inline std::string DX12ReturnValueToString<Decoded_LUID>(const Decoded_LUID& return_value,
                                                         util::ToStringFlags to_string_flags,
                                                         uint32_t            tab_count,
                                                         uint32_t            tab_size)
{
    return util::ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
}

template <>
inline std::string DX12ReturnValueToString<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1>(
    const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1& return_value,
    util::ToStringFlags                                   to_string_flags,
    uint32_t                                              tab_count,
    uint32_t                                              tab_size)
{
    return util::ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
}

template <>
inline std::string DX12ReturnValueToString<Decoded_D3D12_RESOURCE_ALLOCATION_INFO>(
    const Decoded_D3D12_RESOURCE_ALLOCATION_INFO& return_value,
    util::ToStringFlags                           to_string_flags,
    uint32_t                                      tab_count,
    uint32_t                                      tab_size)
{
    return util::ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
}

template <>
inline std::string
DX12ReturnValueToString<Decoded_D3D12_RESOURCE_DESC1>(const Decoded_D3D12_RESOURCE_DESC1& return_value,
                                                      util::ToStringFlags                 to_string_flags,
                                                      uint32_t                            tab_count,
                                                      uint32_t                            tab_size)
{
    return util::ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
}

template <>
inline std::string DX12ReturnValueToString<Decoded_D3D12_SHADER_CACHE_SESSION_DESC>(
    const Decoded_D3D12_SHADER_CACHE_SESSION_DESC& return_value,
    util::ToStringFlags                            to_string_flags,
    uint32_t                                       tab_count,
    uint32_t                                       tab_size)
{
    return util::ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
}
///////////////////////////////////////////////////////////////////////////////

template <typename EnumType>
inline std::string EnumPointerDecoderToString(PointerDecoder<EnumType>* pObj)
{
    auto pDecodedObj = pObj ? pObj->GetPointer() : nullptr;
    return pDecodedObj ? ('"' + util::ToString(*pDecodedObj) + '"') : "null";
}

template <typename DecodedType>
inline std::string PointerDecoderToString(PointerDecoder<DecodedType>* pObj,
                                          util::ToStringFlags          toStringFlags = util::kToString_Default,
                                          uint32_t                     tabCount      = 0,
                                          uint32_t                     tabSize       = 4)
{
    auto pDecodedObj = pObj ? pObj->GetPointer() : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

template <typename T, typename OutputT = T>
inline std::string PointerDecoderToString(PointerDecoder<T, OutputT>* pObj,
                                          util::ToStringFlags         toStringFlags = util::kToString_Default,
                                          uint32_t                    tabCount      = 0,
                                          uint32_t                    tabSize       = 4)
{
    auto pDecodedObj = pObj ? pObj->GetPointer() : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

template <typename DecodedStructureType>
inline std::string StructPointerDecoderToString(StructPointerDecoder<DecodedStructureType>* pObj,
                                                util::ToStringFlags toStringFlags = util::kToString_Default,
                                                uint32_t            tabCount      = 0,
                                                uint32_t            tabSize       = 4)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

template <typename StringDecoderType>
inline std::string StringDecoderToString(StringDecoderType*  pObj,
                                         util::ToStringFlags toStringFlags = util::kToString_Default,
                                         uint32_t            tabCount      = 0,
                                         uint32_t            tabSize       = 4)
{
    auto pDecodedObj = pObj ? pObj->GetPointer() : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

template <typename T>
inline std::string OutPtrDecoderToString(HandlePointerDecoder<T*>* pObj)
{
    auto pDecodedObj = pObj ? pObj->GetPointer() : nullptr;
    return pDecodedObj ? std::to_string(static_cast<uint64_t>(*pDecodedObj)) : "null";
}

template <typename CountType>
inline size_t GetCount(CountType countObj)
{
    return static_cast<size_t>(countObj);
}

template <>
inline size_t GetCount<PointerDecoder<UINT>*>(PointerDecoder<UINT>* pCountObj)
{
    auto pDecodedCountObj = pCountObj ? pCountObj->GetPointer() : nullptr;
    return static_cast<size_t>(pDecodedCountObj ? *pDecodedCountObj : 0);
}

template <>
inline size_t GetCount<PointerDecoder<SIZE_T>*>(PointerDecoder<SIZE_T>* pCountObj)
{
    auto pDecodedCountObj = pCountObj ? pCountObj->GetPointer() : nullptr;
    return static_cast<size_t>(pDecodedCountObj ? *pDecodedCountObj : 0);
}

template <typename CountType, typename PointerDecoderType>
inline std::string PointerDecoderArrayToString(const CountType&    countObj,
                                               PointerDecoderType* pObjs,
                                               util::ToStringFlags toStringFlags = util::kToString_Default,
                                               uint32_t            tabCount      = 0,
                                               uint32_t            tabSize       = 4)
{
    using namespace util;
    return ArrayToString(
        GetCount(countObj),
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs && !pObjs->IsNull(); },
        [&](size_t i) { return ToString(pObjs->GetPointer()[i], toStringFlags, tabCount + 1, tabSize); });
}

template <typename CountType, typename PointerDecoderType>
inline std::string EnumPointerDecoderArrayToString(const CountType&    countObj,
                                                   PointerDecoderType* pObjs,
                                                   util::ToStringFlags toStringFlags = util::kToString_Default,
                                                   uint32_t            tabCount      = 0,
                                                   uint32_t            tabSize       = 4)
{
    using namespace util;
    return ArrayToString(
        GetCount(countObj),
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs && !pObjs->IsNull(); },
        [&](size_t i) { return '"' + ToString(pObjs->GetPointer()[i], toStringFlags, tabCount + 1, tabSize) + '"'; });
}

template <typename CountType, typename StructPointerDecoderType>
inline std::string StructPointerDecoderArrayToString(const CountType&          countObj,
                                                     StructPointerDecoderType* pObjs,
                                                     util::ToStringFlags       toStringFlags = util::kToString_Default,
                                                     uint32_t                  tabCount      = 0,
                                                     uint32_t                  tabSize       = 4)
{
    using namespace util;
    return ArrayToString(
        GetCount(countObj),
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs && !pObjs->IsNull(); },
        [&](size_t i) {
            return ToString(*pObjs->GetMetaStructPointer()[i].decoded_value, toStringFlags, tabCount + 1, tabSize);
        });
}

///////////////////////////////////////////////////////////////////////////////
// The following StructPointerDecoder<> types require custom handling
template <typename DecodedStructureType>
typename DecodedStructureType::struct_type GetNestedDecodedStructure(const DecodedStructureType* pObj)
{
    return pObj && pObj->decoded_value ? *pObj->decoded_value : typename DecodedStructureType::struct_type{};
}

template <typename DecodedStructureType>
typename const DecodedStructureType::struct_type&
GetNestedMetaStructure(const StructPointerDecoder<DecodedStructureType>* pObj)
{
    static const DecodedStructureType::struct_type sDefault{};
    auto                                           pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    return pDecodedObj ? *pDecodedObj : sDefault;
}

template <>
inline std::string StructPointerDecoderArrayToString(const UINT&                                           countObj,
                                                     StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pObjs,
                                                     util::ToStringFlags toStringFlags,
                                                     uint32_t            tabCount,
                                                     uint32_t            tabSize)
{
    using namespace util;
    return ArrayToString(
        GetCount(countObj),
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs && !pObjs->IsNull(); },
        [&](size_t i) {
            auto obj = *pObjs->GetMetaStructPointer()[i].decoded_value;
            switch (obj.Type)
            {
                case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
                {
                    auto pTransition = pObjs->GetMetaStructPointer()[i].Transition;
                    obj.Transition   = GetNestedDecodedStructure(pTransition);
                    obj.Transition.pResource =
                        pTransition ? reinterpret_cast<ID3D12Resource*>(pTransition->pResource) : nullptr;
                }
                break;
                case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
                {
                    auto pAliasing = pObjs->GetMetaStructPointer()[i].Aliasing;
                    obj.Aliasing   = GetNestedDecodedStructure(pAliasing);
                    obj.Aliasing.pResourceBefore =
                        pAliasing ? reinterpret_cast<ID3D12Resource*>(pAliasing->pResourceBefore) : nullptr;
                    obj.Aliasing.pResourceAfter =
                        pAliasing ? reinterpret_cast<ID3D12Resource*>(pAliasing->pResourceAfter) : nullptr;
                }
                break;
                case D3D12_RESOURCE_BARRIER_TYPE_UAV:
                {

                    auto pUav         = pObjs->GetMetaStructPointer()[i].UAV;
                    obj.UAV           = GetNestedDecodedStructure(pUav);
                    obj.UAV.pResource = pUav ? reinterpret_cast<ID3D12Resource*>(pUav->pResource) : nullptr;
                }
                break;
                default:
                {
                }
            }
            return ToString(obj, toStringFlags, tabCount + 1, tabSize);
        });
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_TEXTURE_COPY_LOCATION>(
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pObj,
    util::ToStringFlags                                        toStringFlags,
    uint32_t                                                   tabCount,
    uint32_t                                                   tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        if (obj.Type == D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT)
        {
            obj.PlacedFootprint = GetNestedDecodedStructure(pMetaStructPointer->PlacedFootprint);
        }
        obj.pResource = reinterpret_cast<ID3D12Resource*>(pMetaStructPointer->pResource);
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>(
    StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pObj,
    util::ToStringFlags                                            toStringFlags,
    uint32_t                                                       tabCount,
    uint32_t                                                       tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        switch (obj.ViewDimension)
        {
            case D3D12_SRV_DIMENSION_BUFFER:
            {
                obj.Buffer = GetNestedDecodedStructure(pMetaStructPointer->Buffer);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE1D:
            {
                obj.Texture1D = GetNestedDecodedStructure(pMetaStructPointer->Texture1D);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            {
                obj.Texture1DArray = GetNestedDecodedStructure(pMetaStructPointer->Texture1DArray);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2D:
            {
                obj.Texture2D = GetNestedDecodedStructure(pMetaStructPointer->Texture2D);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            {
                obj.Texture2DArray = GetNestedDecodedStructure(pMetaStructPointer->Texture2DArray);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            {
                obj.Texture2DMS = GetNestedDecodedStructure(pMetaStructPointer->Texture2DMS);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            {
                obj.Texture2DMSArray = GetNestedDecodedStructure(pMetaStructPointer->Texture2DMSArray);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE3D:
            {
                obj.Texture3D = GetNestedDecodedStructure(pMetaStructPointer->Texture3D);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURECUBE:
            {
                obj.TextureCube = GetNestedDecodedStructure(pMetaStructPointer->TextureCube);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
            {
                obj.TextureCubeArray = GetNestedDecodedStructure(pMetaStructPointer->TextureCubeArray);
            }
            break;
            case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
            {
                obj.RaytracingAccelerationStructure =
                    GetNestedDecodedStructure(pMetaStructPointer->RaytracingAccelerationStructure);
            }
            break;
            default:
            {
            }
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>(
    StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>* pObj,
    util::ToStringFlags                                             toStringFlags,
    uint32_t                                                        tabCount,
    uint32_t                                                        tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        switch (obj.ViewDimension)
        {
            case D3D12_SRV_DIMENSION_BUFFER:
            {
                obj.Buffer = GetNestedDecodedStructure(pMetaStructPointer->Buffer);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE1D:
            {
                obj.Texture1D = GetNestedDecodedStructure(pMetaStructPointer->Texture1D);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            {
                obj.Texture1DArray = GetNestedDecodedStructure(pMetaStructPointer->Texture1DArray);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2D:
            {
                obj.Texture2D = GetNestedDecodedStructure(pMetaStructPointer->Texture2D);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            {
                obj.Texture2DArray = GetNestedDecodedStructure(pMetaStructPointer->Texture2DArray);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE3D:
            {
                obj.Texture3D = GetNestedDecodedStructure(pMetaStructPointer->Texture3D);
            }
            break;
            default:
            {
            }
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>(
    StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pObj,
    util::ToStringFlags                                          toStringFlags,
    uint32_t                                                     tabCount,
    uint32_t                                                     tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        switch (obj.ViewDimension)
        {
            case D3D12_SRV_DIMENSION_BUFFER:
            {
                obj.Buffer = GetNestedDecodedStructure(pMetaStructPointer->Buffer);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE1D:
            {
                obj.Texture1D = GetNestedDecodedStructure(pMetaStructPointer->Texture1D);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            {
                obj.Texture1DArray = GetNestedDecodedStructure(pMetaStructPointer->Texture1DArray);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2D:
            {
                obj.Texture2D = GetNestedDecodedStructure(pMetaStructPointer->Texture2D);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            {
                obj.Texture2DArray = GetNestedDecodedStructure(pMetaStructPointer->Texture2DArray);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            {
                obj.Texture2DMS = GetNestedDecodedStructure(pMetaStructPointer->Texture2DMS);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            {
                obj.Texture2DMSArray = GetNestedDecodedStructure(pMetaStructPointer->Texture2DMSArray);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE3D:
            {
                obj.Texture3D = GetNestedDecodedStructure(pMetaStructPointer->Texture3D);
            }
            break;
            default:
            {
            }
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>(
    StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pObj,
    util::ToStringFlags                                          toStringFlags,
    uint32_t                                                     tabCount,
    uint32_t                                                     tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        switch (obj.ViewDimension)
        {
            case D3D12_SRV_DIMENSION_TEXTURE1D:
            {
                obj.Texture1D = GetNestedDecodedStructure(pMetaStructPointer->Texture1D);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            {
                obj.Texture1DArray = GetNestedDecodedStructure(pMetaStructPointer->Texture1DArray);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2D:
            {
                obj.Texture2D = GetNestedDecodedStructure(pMetaStructPointer->Texture2D);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            {
                obj.Texture2DArray = GetNestedDecodedStructure(pMetaStructPointer->Texture2DArray);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            {
                obj.Texture2DMS = GetNestedDecodedStructure(pMetaStructPointer->Texture2DMS);
            }
            break;
            case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            {
                obj.Texture2DMSArray = GetNestedDecodedStructure(pMetaStructPointer->Texture2DMSArray);
            }
            break;
            default:
            {
            }
            break;
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string
StructPointerDecoderToString<Decoded_D3D12_ROOT_PARAMETER>(StructPointerDecoder<Decoded_D3D12_ROOT_PARAMETER>* pObj,
                                                           util::ToStringFlags toStringFlags,
                                                           uint32_t            tabCount,
                                                           uint32_t            tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        switch (obj.ParameterType)
        {
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                obj.DescriptorTable = GetNestedDecodedStructure(pMetaStructPointer->DescriptorTable);
            }
            break;
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            {
                obj.Constants = GetNestedDecodedStructure(pMetaStructPointer->Constants);
            }
            break;
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            default:
            {
                obj.Descriptor = GetNestedDecodedStructure(pMetaStructPointer->Descriptor);
            }
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string
StructPointerDecoderToString<Decoded_D3D12_ROOT_PARAMETER1>(StructPointerDecoder<Decoded_D3D12_ROOT_PARAMETER1>* pObj,
                                                            util::ToStringFlags toStringFlags,
                                                            uint32_t            tabCount,
                                                            uint32_t            tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        switch (obj.ParameterType)
        {
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                obj.DescriptorTable = GetNestedDecodedStructure(pMetaStructPointer->DescriptorTable);
            }
            break;
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            {
                obj.Constants = GetNestedDecodedStructure(pMetaStructPointer->Constants);
            }
            break;
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            default:
            {
                obj.Descriptor = GetNestedDecodedStructure(pMetaStructPointer->Descriptor);
            }
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>(
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pObj,
    util::ToStringFlags                                                toStringFlags,
    uint32_t                                                           tabCount,
    uint32_t                                                           tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        switch (obj.Version)
        {
            case D3D_ROOT_SIGNATURE_VERSION_1_0:
            {
                obj.Desc_1_0 = GetNestedDecodedStructure(pMetaStructPointer->Desc_1_0);
            }
            break;
            case D3D_ROOT_SIGNATURE_VERSION_1_1:
            {
                obj.Desc_1_1 = GetNestedDecodedStructure(pMetaStructPointer->Desc_1_1);
            }
            break;
            default:
            {
            }
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_INDIRECT_ARGUMENT_DESC>(
    StructPointerDecoder<Decoded_D3D12_INDIRECT_ARGUMENT_DESC>* pObj,
    util::ToStringFlags                                         toStringFlags,
    uint32_t                                                    tabCount,
    uint32_t                                                    tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_RAYTRACING_GEOMETRY_DESC>(
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_GEOMETRY_DESC>* pObj,
    util::ToStringFlags                                           toStringFlags,
    uint32_t                                                      tabCount,
    uint32_t                                                      tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        switch (obj.Type)
        {
            case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
            {
                obj.Triangles = GetNestedDecodedStructure(pMetaStructPointer->Triangles);
            }
            break;
            case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
            {
                obj.AABBs = GetNestedDecodedStructure(pMetaStructPointer->AABBs);
            }
            break;
            default:
            {
            }
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>(
    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>* pObj,
    util::ToStringFlags                                                                 toStringFlags,
    uint32_t                                                                            tabCount,
    uint32_t                                                                            tabSize)
{
    // TODO : Untested
    // TODO : Unimplemented; need to determine correct handling for
    // D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS::InstanceDescs
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS>(
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS>* pObj,
    util::ToStringFlags                                               toStringFlags,
    uint32_t                                                          tabCount,
    uint32_t                                                          tabSize)
{
    // TODO : Untested
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        if (obj.Type == D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR)
        {
            obj.Clear = GetNestedDecodedStructure(pMetaStructPointer->Clear);
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS>(
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS>* pObj,
    util::ToStringFlags                                            toStringFlags,
    uint32_t                                                       tabCount,
    uint32_t                                                       tabSize)
{
    // TODO : Untested
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        if (obj.Type == D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE)
        {
            obj.Resolve = GetNestedDecodedStructure(pMetaStructPointer->Resolve);
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string
StructPointerDecoderToString<Decoded_LARGE_INTEGER>(StructPointerDecoder<Decoded_LARGE_INTEGER>* pObj,
                                                    util::ToStringFlags                          toStringFlags,
                                                    uint32_t                                     tabCount,
                                                    uint32_t                                     tabSize)
{
    // TODO : Untested
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>(
    StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pObj,
    util::ToStringFlags                                             toStringFlags,
    uint32_t                                                        tabCount,
    uint32_t                                                        tabSize)
{
    // TODO : Untested
    // TODO : Unimplemented; need to determine correct handling for Decoded_D3D12_PIPELINE_STATE_STREAM_DESC
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

template <>
inline std::string StructPointerDecoderToString<Decoded_D3D12_STATE_OBJECT_DESC>(
    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pObj,
    util::ToStringFlags                                    toStringFlags,
    uint32_t                                               tabCount,
    uint32_t                                               tabSize)
{
    // TODO : Untested
    // TODO : Unimplemented; need to determine correct handling for Decoded_D3D12_STATE_OBJECT_DESC::subobject_stride
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

template <>
inline std::string
StructPointerDecoderToString<Decoded_D3D12_STATE_SUBOBJECT>(StructPointerDecoder<Decoded_D3D12_STATE_SUBOBJECT>* pObj,
                                                            util::ToStringFlags toStringFlags,
                                                            uint32_t            tabCount,
                                                            uint32_t            tabSize)
{
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    if (pDecodedObj)
    {
        auto obj = *pDecodedObj;
        switch (obj.Type)
        {
            case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->state_object_config);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->global_root_signature);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->local_root_signature);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->node_mask);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->dxil_library_desc);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->existing_collection_desc);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->subobject_to_exports_association);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->dxil_subobject_to_exports_association);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->raytracing_shader_config);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->raytracing_pipeline_config);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->hit_group_desc);
            }
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1:
            {
                obj.pDesc = &GetNestedMetaStructure(pMetaStructPointer->raytracing_pipeline_config1);
            }
            break;
            default:
            {
            }
        }
        return util::ToString(obj, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
inline std::string
StructPointerDecoderToString<Decoded__SECURITY_ATTRIBUTES>(StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pObj,
                                                           util::ToStringFlags toStringFlags,
                                                           uint32_t            tabCount,
                                                           uint32_t            tabSize)
{
    // TODO : Untested
    auto pMetaStructPointer = pObj ? pObj->GetMetaStructPointer() : nullptr;
    auto pDecodedObj        = pMetaStructPointer ? pMetaStructPointer->decoded_value : nullptr;
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CUSTOM_DX12_ASCII_CONSUMER_H
