/*
** Copyright (c) 2022 LunarG, Inc.
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
/// @file Custom code used when outputing a textual representation of a capture.
#ifndef GFXRECON_CUSTOM_VULKAN_ASCII_CONSUMER_H
#define GFXRECON_CUSTOM_VULKAN_ASCII_CONSUMER_H

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_to_string.h"
#include "generated/generated_vulkan_struct_decoders_to_string.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "util/defines.h"
#include "util/to_string.h"
#include "util/custom_vulkan_to_string.h"
#include "custom_vulkan_struct_decoders_to_string.h"


#include "vulkan/vulkan.h"

#include <sstream>
#include <string>


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// String representation of empty array.
constexpr auto GFXRECON_TOJSON_EMPTY_ARRAY = "[]";
/// String representation of a null pointer.
constexpr auto GFXRECON_TOJSON_NULL = "null";

inline std::string HandleIdToString(format::HandleId handleId)
{
    std::stringstream strStrm;
    if (handleId)
    {
        strStrm << "\"0x" << std::hex << handleId << "\"";
    }
    else
    {
        strStrm << "\"VK_NULL_HANDLE\"";
    }
    return strStrm.str();
}

template <typename VkHandleType>
inline std::string HandlePointerDecoderToString(HandlePointerDecoder<VkHandleType>* pObj)
{
    auto pDecodedObj = pObj ? pObj->GetPointer() : nullptr;
    return HandleIdToString(pDecodedObj ? *pDecodedObj : format::kNullHandleId);
}

template <typename VkEnumType>
inline std::string EnumPointerDecoderToString(PointerDecoder<VkEnumType>* pObj)
{
    auto pDecodedObj = pObj ? pObj->GetPointer() : nullptr;
    return pDecodedObj ? ('"' + util::ToString(*pDecodedObj) + '"') : "null";
}

template <typename T>
inline std::string DataPointerDecoderToString(const T& pObj)
{
    // NOTE : Currently we just output the integer value of data void pointers, for
    //  fields that use a PointerDecoder<> we output the address of the decoder
    //  itself...this isn't terribly useful, but the capture time address wouldn't
    //  be a terribly useful thing anyway.  There are structures that have data
    //  fields that can be interpreted correctly...if we want to output interpreted
    //  void pointer data we can implement custom handlers for those structures.
    return "\"" + util::PtrToString(pObj) + "\"";
}

/// Template which unwraps the decoder type for a Vulkan Struct to the
/// underlying Vulkan version before dispatching to a generated to-string
/// function for that type.
/// @note This is broken: any handle in a struct will be VK_NULL_HANDLE in the
/// string generated.
/// @fixme: either:
/// 1. dispatch to a new set of to-string functions which handle the
/// wrapper type directly, or
/// 2. generate specialisations of this dispatcher which
/// stuff our handle IDs into the handles as shown in the manually-written example,
/// below, or
/// 3. generate to-strings for the decoded types which do the stuffing and then call the existing
///    ToString()s.

/// Pointers to primitive types like integers and to arrays will come through here:
template <typename PointerDecoderType>
inline std::string PointerDecoderToString(PointerDecoderType* pObj,
                                          util::ToStringFlags toStringFlags = util::kToString_Default,
                                          uint32_t            tabCount      = 0,
                                          uint32_t            tabSize       = 4)
{
    // Get a pointer to the raw vulkan type:
    auto pDecodedObj = pObj ? pObj->GetPointer() : nullptr;
    // Call a function for the raw Vulkan type:
    return pDecodedObj ? util::ToString(*pDecodedObj, toStringFlags, tabCount, tabSize) : "null";
}

/// Overloaded function specialising dispatch for structs.
template <typename StructType>
inline std::string PointerDecoderToString(StructPointerDecoder<StructType>* pObj,
                                          util::ToStringFlags toStringFlags,
                                          uint32_t            tabCount,
                                          uint32_t            tabSize)
{
    std::string str = "null";
    if(nullptr != pObj)
    {
        auto pMetaObj = pObj->GetMetaStructPointer();
        // If there was no struct pointer provided by the app, e.g. for allocation
        // callbacks, we'll have a null pointer here too.
        if(nullptr != pMetaObj)
        {
            str = util::ToString(*pMetaObj, toStringFlags, tabCount, tabSize);
        }
        else
        {
            auto vkStructPtr = pObj->GetPointer();
            if(nullptr != vkStructPtr)
            {
                str = util::ToString(*vkStructPtr, toStringFlags, tabCount, tabSize);
            }
        }
    }
    return str;
}

inline std::string DescriptorUpdateTemplateDecoderToString(const DescriptorUpdateTemplateDecoder* pObj,
                                                           util::ToStringFlags toStringFlags = util::kToString_Default,
                                                           uint32_t            tabCount      = 0,
                                                           uint32_t            tabSize       = 4)
{
    VkWriteDescriptorSet                         writeDescriptorSet{};
    VkWriteDescriptorSetAccelerationStructureKHR writeDescriptorSetAccelerationStructure{};
    if (pObj)
    {

        writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        if (pObj->GetImageInfoCount())
        {
            writeDescriptorSet.descriptorCount = static_cast<uint32_t>(pObj->GetImageInfoCount());
            writeDescriptorSet.pImageInfo      = pObj->GetImageInfoPointer();
        }
        else if (pObj->GetBufferInfoCount())
        {
            writeDescriptorSet.descriptorCount = static_cast<uint32_t>(pObj->GetBufferInfoCount());
            writeDescriptorSet.pBufferInfo     = pObj->GetBufferInfoPointer();
        }
        else if (pObj->GetTexelBufferViewCount())
        {
            writeDescriptorSet.descriptorCount  = static_cast<uint32_t>(pObj->GetTexelBufferViewCount());
            writeDescriptorSet.pTexelBufferView = pObj->GetTexelBufferViewPointer();
        }
        else if (pObj->GetAccelerationStructureKHRCount())
        {
            writeDescriptorSet.descriptorCount = static_cast<uint32_t>(pObj->GetAccelerationStructureKHRCount());
            writeDescriptorSet.pNext           = &writeDescriptorSetAccelerationStructure;
            writeDescriptorSetAccelerationStructure.sType =
                VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR;
            writeDescriptorSetAccelerationStructure.accelerationStructureCount =
                static_cast<uint32_t>(pObj->GetAccelerationStructureKHRCount());
            writeDescriptorSetAccelerationStructure.pAccelerationStructures =
                pObj->GetAccelerationStructureKHRPointer();
        }
    }
    return util::ToString(writeDescriptorSet, toStringFlags, tabCount, tabSize);
}

inline std::string StringDecoderToString(const StringDecoder* pObj)
{
    auto pDecodedString = pObj ? pObj->GetPointer() : nullptr;
    return pDecodedString ? ('"' + std::string(pDecodedString) + '"') : "null";
}

template <typename CountType>
inline uint32_t GetCount(CountType countObj)
{
    return static_cast<uint32_t>(countObj);
}

template <>
inline uint32_t GetCount<PointerDecoder<uint32_t>*>(PointerDecoder<uint32_t>* pCountObj)
{
    auto pDecodedCountObj = pCountObj ? pCountObj->GetPointer() : nullptr;
    return pDecodedCountObj ? *pDecodedCountObj : 0;
}

template <typename CountType, typename VkHandleType>
inline std::string HandlePointerDecoderArrayToString(const CountType&                    countObj,
                                                     HandlePointerDecoder<VkHandleType>* pObjs,
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
        [&](uint32_t i) { return HandleIdToString((format::HandleId)pObjs->GetPointer()[i]); });
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
        [&](uint32_t i)
        {
            //Original iterating over raw Vulkan Structs:
            return ToString(pObjs->GetPointer()[i], toStringFlags, tabCount + 1, tabSize);
        }
    );
}

template <typename Decoded_VkStructType>
inline std::string PointerDecoderArrayToString(const StructPointerDecoder<Decoded_VkStructType>& pObjsPointerDecoder,
                                               util::ToStringFlags toStringFlags = util::kToString_Default,
                                               uint32_t            tabCount      = 0,
                                               uint32_t            tabSize       = 4)
{
    using namespace util;
    const size_t countObj = pObjsPointerDecoder.GetLength();
    const Decoded_VkStructType* pObjs = pObjsPointerDecoder.GetMetaStructPointer();

    return ArrayToString(
        GetCount(countObj),
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs && (pObjs != nullptr); },
        [&](uint32_t i)
        {
            return ToString(pObjs[i], toStringFlags, tabCount + 1, tabSize);
        }
    );
}

template <typename Decoded_VkStructType>
inline std::string PointerDecoderArrayToString(const StructPointerDecoder<Decoded_VkStructType>* pObjsPointerDecoder,
                                               util::ToStringFlags toStringFlags = util::kToString_Default,
                                               uint32_t            tabCount      = 0,
                                               uint32_t            tabSize       = 4)
{
    if(nullptr != pObjsPointerDecoder)
    {
        return PointerDecoderArrayToString(*pObjsPointerDecoder, toStringFlags, tabCount, tabSize);
    }
    // We represent a null pointer as an empty array on a single line.
    return GFXRECON_TOJSON_EMPTY_ARRAY;
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
        [&](uint32_t i) { return '"' + ToString(pObjs->GetPointer()[i], toStringFlags, tabCount + 1, tabSize) + '"'; });
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CUSTOM_VULKAN_ASCII_CONSUMER_H
