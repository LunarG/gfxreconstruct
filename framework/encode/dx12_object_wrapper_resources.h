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

#ifndef GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_RESOURCES_H
#define GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_RESOURCES_H

#include "encode/iunknown_wrapper.h"
#include "util/defines.h"

#include <atomic>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

//----------------------------------------------------------------------------
/// \brief A class to track resources shared by IUnknown_Wrapper objects.
///
/// A class used to share resources between related IUnknown_Wrapper objects.
/// Includes a shared reference count, which represents the combined
/// reference count of all objects that reference it.  Intended to be
/// associated with pointers to the same wrapped object having different
/// interfaces/IIDs (e.g. objects retrieved through QueryInterface), to keep
/// all objects active until they have been released by the application.  May
/// be extended to include interface-specific resources.
//----------------------------------------------------------------------------
class DxWrapperResources
{
  public:
    //----------------------------------------------------------------------------
    /// Constructor receiving a pointer to an object to track.
    ///
    /// \param wrapper  Pointer to an IUnknown_Wrapper object to be added to the
    ///                 internal list of referenced objects.  Typically a pointer
    ///                 to the object creating the DXWrapperResources object.
    //----------------------------------------------------------------------------
    DxWrapperResources(IUnknown_Wrapper* wrapper);

    //----------------------------------------------------------------------------
    /// Destructor responsible for destroying tracked IUnknown_Wrapper objects.
    //----------------------------------------------------------------------------
    virtual ~DxWrapperResources();

    //----------------------------------------------------------------------------
    /// \brief Add an IUnknown_Wrapper object to the list of tracked objects.
    ///
    /// Adds an IUnknown_Wrapper object to the list of tracked objects, without
    /// altering the shared reference count.
    ///
    /// \param wrapper  Pointer to an IUnknown_Wrapper object to be added to the
    ///                 internal list of referenced objects.
    //----------------------------------------------------------------------------
    void AddWrapper(IUnknown_Wrapper* wrapper) { wrappers_.push_back(wrapper); }

    //----------------------------------------------------------------------------
    /// Increments the shared reference count.
    ///
    /// \return The post-increment reference count.
    //----------------------------------------------------------------------------
    unsigned long IncrementSharedCount() { return ++shared_count_; }

    //----------------------------------------------------------------------------
    /// Decrements the shared reference count.
    ///
    /// \return The post-decrement reference count.
    //----------------------------------------------------------------------------
    unsigned long DecrementSharedCount() { return --shared_count_; }

  private:
    std::atomic<unsigned long> shared_count_; ///< Shared reference count, representing the combined reference count of
                                              ///< all tracked IUnknown_Wrapper objects.
    std::vector<IUnknown_Wrapper*> wrappers_; ///< List of tracked IUnknown_Wrapper objects.
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_RESOURCES_H
