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

#ifndef GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_UTIL_H
#define GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_UTIL_H

#include "encode/iunknown_wrapper.h"
#include "format/format.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

//----------------------------------------------------------------------------
/// \brief Retrieves an object from an object wrapper.
///
/// Retrieves a wrapped object from an object wrapper.  Assumes that
/// #wrapped_object, when not null, is a valid wrapped object.  The IUnknown
/// function overload should be used when #wrapped_object is not guaranteed
/// to be an object wrapper.
///
/// \param wrapped_object Pointer to the object wrapper to be processed.
///
/// \return A pointer to the object retrieved from the object wrapper, or
///         nullptr if #wrapped_object was null.
//----------------------------------------------------------------------------
template <typename Wrapper, typename Object>
Object* GetWrappedObject(Object* wrapped_object)
{
    Object* object = nullptr;

    if (wrapped_object != nullptr)
    {
        reinterpret_cast<Wrapper*>(wrapped_object)->GetWrappedObject(&object);
    }

    return object;
}

//----------------------------------------------------------------------------
/// \brief Retrieves a const object from a const object wrapper.
///
/// Retrieves a wrapped object from a const object wrapper.  Assumes that
/// #wrapped_object, when not null, is a valid wrapped object.  The IUnknown
/// function overload should be used when #wrapped_object is not guaranteed
/// to be an object wrapper.
///
/// \param wrapped_object Const pointer to the object wrapper to be processed.
///
/// \return A const pointer to the object retrieved from the object wrapper,
///         or nullptr if #wrapped_object was null.
//----------------------------------------------------------------------------
template <typename Wrapper, typename Object>
const Object* GetWrappedObject(const Object* wrapped_object)
{
    const Object* object = nullptr;

    if (wrapped_object != nullptr)
    {
        reinterpret_cast<const Wrapper*>(wrapped_object)->GetWrappedObject(&object);
    }

    return object;
}

//----------------------------------------------------------------------------
/// \brief Retrieves an object from an object wrapper.
///
/// Retrieves a wrapped object from an object wrapper.  This version of the
/// function is overloaded for the IUnknown type, which uses
/// IUnknown::QueryInterface() to determine if #wrapped_object is really
/// an object wrapper before attempting to process it for unwrapping.  If the
/// query fails, unwrapping will be skipped and the value of the unmodified
/// #wrapped_object parameter will be returned.
///
/// \param wrapped_object Pointer to the object wrapper to be processed.
///
/// \return A pointer to the object retrieved from the object wrapper, or
///         nullptr if #wrapped_object was either null or was not a valid
///         object wrapper.
//----------------------------------------------------------------------------
template <>
IUnknown* GetWrappedObject<IUnknown_Wrapper, IUnknown>(IUnknown* wrapped_object);

//----------------------------------------------------------------------------
/// \brief Retrieves a const object from a const object wrapper.
///
/// Retrieves a const wrapped object from a const object wrapper.  This
/// version of the function is overloaded for the IUnknown type, which
/// uses IUnknown::QueryInterface() to determine if #wrapped_object is really
/// an object wrapper before attempting to process it for unwrapping.  If the
/// query fails, unwrapping will be skipped and the value of the unmodified
/// #wrapped_object parameter will be returned.
///
/// \param wrapped_object Pointer to the object wrapper to be processed.
///
/// \return A pointer to the object retrieved from the object wrapper, or
///         nullptr if #wrapped_object was either null or was not a valid
///         object wrapper.
//----------------------------------------------------------------------------
template <>
const IUnknown* GetWrappedObject<IUnknown_Wrapper, IUnknown>(const IUnknown* wrapped_object);

//----------------------------------------------------------------------------
/// \brief Retrieves an object ID from an object wrapper.
///
/// Retrieves an object ID from an object wrapper.  Assumes that
/// #wrapped_object, when not null, is a valid wrapped object.  The IUnknown
/// function overload should be used when #wrapped_object is not guaranteed
/// to be an object wrapper.
///
/// \param wrapped_object Pointer to the object wrapper to be processed.
///
/// \return The unique object ID retrieved from the object wrapper, or
///         format::kNullHandleId if #wrapped_object was null.
//----------------------------------------------------------------------------
template <typename Wrapper, typename Object>
format::HandleId GetWrappedId(const Object* wrapped_object)
{
    return (wrapped_object != nullptr) ? reinterpret_cast<const Wrapper*>(wrapped_object)->GetCaptureId()
                                       : format::kNullHandleId;
}

//----------------------------------------------------------------------------
/// \brief Retrieves an object ID from a const object wrapper.
///
/// Retrieves an object ID from a const object wrapper.  This version of the
/// function is overloaded for the IUnknown type, which uses
/// IUnknown::QueryInterface() to determine if #wrapped_object is really
/// an object wrapper before attempting to retrieve an ID from it.  If the
/// query fails, ID retrieval will be skipped and format::kNullHandleId will
/// be returned.
///
/// \param wrapped_object Pointer to the object wrapper to be processed.
///
/// \return The unique object ID retrieved from the object wrapper, or
///         format::kNullHandleId if #wrapped_object was either null or was
///         not a valid object wrapper.
//----------------------------------------------------------------------------
template <>
format::HandleId GetWrappedId<IUnknown_Wrapper, IUnknown>(const IUnknown* wrapped_object);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_UTIL_H
