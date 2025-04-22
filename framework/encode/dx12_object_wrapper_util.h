/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

#include "encode/handle_unwrap_memory.h"
#include "encode/iunknown_wrapper.h"
#include "format/format.h"
#include "util/defines.h"

#include <mutex>

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
template <typename Object>
Object* GetWrappedObject(Object* wrapped_object)
{
    return (wrapped_object != nullptr)
               ? reinterpret_cast<IUnknown_Wrapper*>(wrapped_object)->GetWrappedObjectAs<Object>()
               : nullptr;
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
template <typename Object>
const Object* GetWrappedObject(const Object* wrapped_object)
{
    return (wrapped_object != nullptr)
               ? reinterpret_cast<const IUnknown_Wrapper*>(wrapped_object)->GetWrappedObjectAs<Object>()
               : nullptr;
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
IUnknown* GetWrappedObject<IUnknown>(IUnknown* wrapped_object);

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
const IUnknown* GetWrappedObject<IUnknown>(const IUnknown* wrapped_object);

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
template <typename Object>
format::HandleId GetDx12WrappedId(const Object* wrapped_object)
{
    return (wrapped_object != nullptr) ? reinterpret_cast<const IUnknown_Wrapper*>(wrapped_object)->GetCaptureId()
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
format::HandleId GetDx12WrappedId<IUnknown>(const IUnknown* wrapped_object);

//----------------------------------------------------------------------------
/// \brief Unwraps an array of handles.
///
/// Returns an array of unwrapped objects retrieved from the objects in an
/// array of object wrappers.  The unwrapped object will be stored at the
/// same index in the array as the object wrapper that is was retrieved from.
/// The caller must provide a pointer to a HandleUnwrapMemory object that
/// will provide the memory used to store the unwrapped objects.  If the
/// pointer to the object wrapper array is null, or the array size is zero,
/// the pointer to the object wrapper array will be returned with no other
/// action performed.
///
/// \param objects       Pointer to an array of object wrappers to be
///                      processed for unwrapping.
/// \param len           Number of items in the array of object wrappers.
/// \param unwrap_memory Pointer to a HandleUnwrapMemory object that will
///                      provide the memory used to store the unwrapped
///                      objects.
///
/// \return Pointer to the array of unwrapped objects, stored in memory
///         provided by the HandleUnwrapMemory object, if the array of
///         object wrappers is not empty.  Pointer to the array of object
///         wrappers if the array is empty.
//----------------------------------------------------------------------------
template <typename Object>
Object* const* UnwrapObjects(Object* const* objects, uint32_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((objects != nullptr) && (len > 0))
    {
        assert(unwrap_memory != nullptr);

        size_t num_bytes         = len * sizeof(Object*);
        auto   unwrapped_objects = reinterpret_cast<Object**>(unwrap_memory->GetBuffer(num_bytes));

        for (uint32_t i = 0; i < len; ++i)
        {
            unwrapped_objects[i] = GetWrappedObject<Object>(objects[i]);
        }

        return unwrapped_objects;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return objects;
}

//----------------------------------------------------------------------------
/// \brief Unwraps an array of handles.
///
/// Returns an array of unwrapped objects retrieved from the objects in an
/// array of object wrappers.  The unwrapped object will be stored at the
/// same index in the array as the object wrapper that is was retrieved from.
/// The caller must provide a pointer to a HandleUnwrapMemory object that
/// will provide the memory used to store the unwrapped objects.  If the
/// pointer to the object wrapper array is null, or the array size is zero,
/// the pointer to the object wrapper array will be returned with no other
/// action performed.
///
/// \param objects       Pointer to an array of object wrappers to be
///                      processed for unwrapping.
/// \param len           Number of items in the array of object wrappers.
/// \param unwrap_memory Pointer to a HandleUnwrapMemory object that will
///                      provide the memory used to store the unwrapped
///                      objects.
///
/// \return Pointer to the array of unwrapped objects, stored in memory
///         provided by the HandleUnwrapMemory object, if the array of
///         object wrappers is not empty.  Pointer to the array of object
///         wrappers if the array is empty.
//----------------------------------------------------------------------------
template <typename Object>
Object** UnwrapObjects(Object** objects, uint32_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((objects != nullptr) && (len > 0))
    {
        assert(unwrap_memory != nullptr);

        size_t num_bytes         = len * sizeof(Object*);
        auto   unwrapped_objects = reinterpret_cast<Object**>(unwrap_memory->GetBuffer(num_bytes));

        for (uint32_t i = 0; i < len; ++i)
        {
            unwrapped_objects[i] = GetWrappedObject<Object>(objects[i]);
        }

        return unwrapped_objects;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return objects;
}

//----------------------------------------------------------------------------
/// \brief Utility function to add an object wrapper to a table.
///
/// Add an object wrapper entry to a table keyed by the pointer of the
/// unwrapped object.
///
/// \param object          A pointer to the unwrapped object to be used as
///                        the key for the map entry.
/// \param wrapper         A pointer to the wrapper to be added to the map.
/// \param object_map      A reference to the map that the wrapper will be
///                        added to.
/// \param object_map_lock A reference to a std::mutex to be locked when the
///                        object_map is modified.
//----------------------------------------------------------------------------
template <typename Object, typename Wrapper, typename Map>
void AddWrapperMapEntry(Object* object, Wrapper* wrapper, Map& object_map, std::mutex& object_map_lock)
{
    std::lock_guard<std::mutex> lock(object_map_lock);
    object_map[object] = wrapper;
}

//----------------------------------------------------------------------------
/// \brief Utility function to remove an object wrapper from a table.
///
/// Remove an object wrapper entry from a table.
///
/// \param object          A pointer to the unwrapped object to be used as
///                        the key for the map entry.
/// \param object_map      A reference to the map that the wrapper will be
///                        removed from.
/// \param object_map_lock A reference to a std::mutex to be locked when the
///                        object_map is modified.
//----------------------------------------------------------------------------
template <typename Object, typename Map>
void RemoveWrapperMapEntry(Object* object, Map& object_map, std::mutex& object_map_lock)
{
    std::lock_guard<std::mutex> lock(object_map_lock);
    object_map.erase(object);
}

//----------------------------------------------------------------------------
/// \brief Utility function to retrieve an object wrapper from a table.
///
/// Retreive an object wrapper entry from a table.
///
/// \param object          A pointer to the unwrapped object to be used as
///                        the key for the map entry.
/// \param object_map      A reference to the map that the wrapper will be
///                        retrieved from.
/// \param object_map_lock A reference to a std::mutex to be locked when the
///                        object_map is accessed.
///
/// \return A pointer to the wrapper object retrieved from the map.
//----------------------------------------------------------------------------
template <typename Wrapper, typename Object, typename Map>
Wrapper* FindMapEntry(Object* object, Map& object_map, std::mutex& object_map_lock)
{
    Wrapper*            wrapper = nullptr;
    Map::const_iterator entry;

    {
        std::lock_guard<std::mutex> lock(object_map_lock);
        entry = object_map.find(object);
    }

    if (entry != object_map.end())
    {
        wrapper = entry->second;
    }

    return wrapper;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_UTIL_H
