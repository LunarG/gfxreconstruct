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

#ifndef GFXRECON_ENCODE_IUNKNOWN_WRAPPER_UTIL_H
#define GFXRECON_ENCODE_IUNKNOWN_WRAPPER_UTIL_H

#include "format/format.h"
#include "util/defines.h"

#include <atomic>
#include <comdef.h>
#include <guiddef.h>
#include <Unknwn.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class DxWrapperResources;

//----------------------------------------------------------------------------
/// \brief An IID, with value E00BB2CC-162E-4AAD-9769-EDE6915395F6, that may
///        be used to determine if an object with a Direct3D class type is
///        really a wrapped object.
//----------------------------------------------------------------------------
const IID IID_IUnknown_Wrapper = { 0xe00bb2cc, 0x162e, 0x4aad, { 0x97, 0x69, 0xed, 0xe6, 0x91, 0x53, 0x95, 0xf6 } };

//----------------------------------------------------------------------------
/// \brief A wrapper class for the IUnknown class type.
///
/// A wrapper class for the IUnknown class type, to serve as the base class
/// for Direct3D wrapper classes.  Provides implementations for common
/// wrapper functionality.
//----------------------------------------------------------------------------
MIDL_INTERFACE("E00BB2CC-162E-4AAD-9769-EDE6915395F6")
IUnknown_Wrapper : public IUnknown
{
  public:
    // The use of 'MIDL_INTERFACE' instead of 'class' produces incorrect formatting around IUnknown.
    // clang-format off

    //----------------------------------------------------------------------------
    /// Constructor receiving a pointer to an object to be wrapped.
    ///
    /// \param riid           IID of the object to be wrapped.
    /// \param wrapped_object Pointer to the object to be wrapped.
    /// \param resources      Pointer to a DxWrapperResources object that is
    ///                       responsible for maintaining a shared reference
    ///                       count between related objects.
    //----------------------------------------------------------------------------
    IUnknown_Wrapper(REFIID riid, IUnknown* wrapped_object, DxWrapperResources* resources = nullptr);

    //----------------------------------------------------------------------------
    /// \brief QueryInterface implementation.
    ///
    /// An implementation of QueryInterface to call QueryInterface on the wrapped
    /// object and wrap the retrieved object before returning it to the caller.
    /// When #riid is #IID_IUnknown_Wrapper, #object is set to the wrapper's this
    /// pointer without incrementing the wrapper's reference count.
    ///
    /// \param riid   IID specifying the type of object to retrieve.
    /// \param object Address of the pointer to which the retrieved object
    ///               will be assigned.
    ///
    /// \return An HRESULT error code specifying query success or failure.
    //----------------------------------------------------------------------------
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** object) override;

    //----------------------------------------------------------------------------
    /// \brief Increment the wrapper's reference counts.
    ///
    /// Increments both the wrapper's individual reference count and the shared
    /// reference count maintained by #resources_.
    ///
    /// \return The post-increment individual reference count.
    //----------------------------------------------------------------------------
    virtual ULONG STDMETHODCALLTYPE AddRef() override;

    //----------------------------------------------------------------------------
    /// \brief Decrement the wrapper's reference counts.
    ///
    /// Decrements both the wrapper's individual reference count and the shared
    /// reference count maintained by #resources_.
    ///
    /// \return The post-decrement individual reference count.
    //----------------------------------------------------------------------------
    virtual ULONG STDMETHODCALLTYPE Release() override;

    //----------------------------------------------------------------------------
    /// Get the IID of the wrapped object's interface.
    ///
    /// \return The wrapped object's IID.
    //----------------------------------------------------------------------------
    REFIID GetRiid() const { return riid_; }

    //----------------------------------------------------------------------------
    /// Get the unique ID assigned to the wrapped object.
    ///
    /// \return The object's unique ID.
    //----------------------------------------------------------------------------
    uint64_t GetCaptureId() const { return capture_id_; }

    //----------------------------------------------------------------------------
    /// Get the wrapped object.
    ///
    /// \param object Address of the pointer to which the wrapped object will be
    ///               assigned.
    //----------------------------------------------------------------------------
    void GetWrappedObject(IUnknown** object)
    {
        if (object != nullptr)
        {
            (*object) = object_;
        }
    }

    //----------------------------------------------------------------------------
    /// Get the wrapped object.
    ///
    /// \param object Address of the pointer to which the wrapped object will be
    ///               assigned.
    //----------------------------------------------------------------------------
    void GetWrappedObject(const IUnknown** object) const
    {
        if (object != nullptr)
        {
            (*object) = object_;
        }
    }

    //----------------------------------------------------------------------------
    /// \brief Destroy the object wrapper.
    ///
    /// Releases the wrapped object and destroys the current wrapper.  Intended
    /// to be called by #resources_ when the shared reference count reaches zero.
    //----------------------------------------------------------------------------
    void Destroy()
    {
        resources_ = nullptr;
        object_    = nullptr;
        delete this;
    }

  protected:
    ~IUnknown_Wrapper() {}

  private:
    typedef _com_ptr_t<_com_IIID<IUnknown, &__uuidof(IUnknown)>> IUnknownPtr;

  private:
    REFIID                         riid_;       ///< IID of the wrapped object's interface.
    IUnknownPtr                    object_;     ///< Pointer to the wrapped object.
    format::HandleId               capture_id_; ///< Interface-specific unique ID assigned to the wrapped object.
    std::atomic<unsigned long>     ref_count_;  ///< Wrapper's reference count.
    DxWrapperResources*            resources_;  ///< Internal state object for maintaining a shared reference
                                                ///< count between related objects.
    // clang-format on
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_IUNKNOWN_WRAPPER_UTIL_H
