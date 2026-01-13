/*
** Copyright (c) 2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
*/

#ifndef GFXRECON_DECODE_DX12_ENUM_UTIL_H
#define GFXRECON_DECODE_DX12_ENUM_UTIL_H

#include "util/defines.h"

#include <d3d12.h>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(enumutil)

static std::string GetResultValueString(HRESULT result)
{
    // clang-format off
    switch (result)
    {
        case S_OK:                                      return "S_OK";
        case S_FALSE:                                   return "S_FALSE";
        case E_ABORT:                                   return "E_ABORT";
        case E_ACCESSDENIED:                            return "E_ACCESSDENIED";
        case E_FAIL:                                    return "E_FAIL";
        case E_HANDLE:                                  return "E_HANDLE";
        case E_INVALIDARG:                              return "E_INVALIDARG";
        case E_NOINTERFACE:                             return "E_NOINTERFACE";
        case E_NOTIMPL:                                 return "E_NOTIMPL";
        case E_OUTOFMEMORY:                             return "E_OUTOFMEMORY";
        case E_POINTER:                                 return "E_POINTER";
        case E_UNEXPECTED:                              return "E_UNEXPECTED";
        case DXGI_ERROR_ACCESS_DENIED:                  return "DXGI_ERROR_ACCESS_DENIED";
        case DXGI_ERROR_ACCESS_LOST:                    return "DXGI_ERROR_ACCESS_LOST";
        case DXGI_ERROR_ALREADY_EXISTS:                 return "DXGI_ERROR_ALREADY_EXISTS";
        case DXGI_ERROR_CANNOT_PROTECT_CONTENT:         return "DXGI_ERROR_CANNOT_PROTECT_CONTENT";
        case DXGI_ERROR_DEVICE_HUNG:                    return "DXGI_ERROR_DEVICE_HUNG";
        case DXGI_ERROR_DEVICE_REMOVED:                 return "DXGI_ERROR_DEVICE_REMOVED";
        case DXGI_ERROR_DEVICE_RESET:                   return "DXGI_ERROR_DEVICE_RESET";
        case DXGI_ERROR_DRIVER_INTERNAL_ERROR:          return "DXGI_ERROR_DRIVER_INTERNAL_ERROR";
        case DXGI_ERROR_FRAME_STATISTICS_DISJOINT:      return "DXGI_ERROR_FRAME_STATISTICS_DISJOINT";
        case DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE:   return "DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE";
        case DXGI_ERROR_INVALID_CALL:                   return "DXGI_ERROR_INVALID_CALL";
        case DXGI_ERROR_MORE_DATA:                      return "DXGI_ERROR_MORE_DATA";
        case DXGI_ERROR_NAME_ALREADY_EXISTS:            return "DXGI_ERROR_NAME_ALREADY_EXISTS";
        case DXGI_ERROR_NONEXCLUSIVE:                   return "DXGI_ERROR_NONEXCLUSIVE";
        case DXGI_ERROR_NOT_CURRENTLY_AVAILABLE:        return "DXGI_ERROR_NOT_CURRENTLY_AVAILABLE";
        case DXGI_ERROR_NOT_FOUND:                      return "DXGI_ERROR_NOT_FOUND";
        case DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED:     return "DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED";
        case DXGI_ERROR_REMOTE_OUTOFMEMORY:             return "DXGI_ERROR_REMOTE_OUTOFMEMORY";
        case DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE:       return "DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE";
        case DXGI_ERROR_SDK_COMPONENT_MISSING:          return "DXGI_ERROR_SDK_COMPONENT_MISSING";
        case DXGI_ERROR_SESSION_DISCONNECTED:           return "DXGI_ERROR_SESSION_DISCONNECTED";
        case DXGI_ERROR_UNSUPPORTED:                    return "DXGI_ERROR_UNSUPPORTED";
        case DXGI_ERROR_WAIT_TIMEOUT:                   return "DXGI_ERROR_WAIT_TIMEOUT";
        case DXGI_ERROR_WAS_STILL_DRAWING:              return "DXGI_ERROR_WAS_STILL_DRAWING";
        case D3D12_ERROR_ADAPTER_NOT_FOUND:             return "D3D12_ERROR_ADAPTER_NOT_FOUND";
        case D3D12_ERROR_DRIVER_VERSION_MISMATCH:       return "D3D12_ERROR_DRIVER_VERSION_MISMATCH";
        case D3D12_ERROR_INVALID_REDIST:                return "D3D12_ERROR_INVALID_REDIST";
        case DXGI_STATUS_OCCLUDED:                      return "DXGI_STATUS_OCCLUDED";
        case DXGI_STATUS_MODE_CHANGED:                  return "DXGI_STATUS_MODE_CHANGED";
        case DXGI_STATUS_MODE_CHANGE_IN_PROGRESS:       return "DXGI_STATUS_MODE_CHANGE_IN_PROGRESS";
        default:                                        return std::to_string(result);
    }
    // clang-format on
}

/**
 * Get HRESULT code description.
 *
 * Returns a string describing the specified HRESULT code.  The descriptions are based on the language in the Dx12 API
 * specification or winerror.h.
 *
 * @param value HRESULT code to process.
 * @return String describing the specified HRESULT code.
 */
static const char* GetResultDescription(HRESULT result)
{
    // clang-format off
    switch (result)
    {
        case S_OK:                                      return "Operation successful";
        case S_FALSE:                                   return "Alternate success value, indicating a successful but nonstandard completion (the precise meaning depends on context).";
        case E_ABORT:                                   return "Operation aborted";
        case E_ACCESSDENIED:                            return "General access denied error";
        case E_FAIL:                                    return "Unspecified failure";
        case E_HANDLE:                                  return "Handle that is not valid";
        case E_INVALIDARG:                              return "One or more arguments are not valid";
        case E_NOINTERFACE:                             return "No such interface supported";
        case E_NOTIMPL:                                 return "Not implemented";
        case E_OUTOFMEMORY:                             return "Failed to allocate necessary memory";
        case E_POINTER:                                 return "Pointer that is not valid";
        case E_UNEXPECTED:                              return "Unexpected failure";
        case DXGI_ERROR_ACCESS_DENIED:                  return "You tried to use a resource to which you did not have the required access privileges. This error is most typically caused when you write to a shared resource with read-only access.";
        case DXGI_ERROR_ACCESS_LOST:                    return "The desktop duplication interface is invalid. The desktop duplication interface typically becomes invalid when a different type of image is displayed on the desktop.";
        case DXGI_ERROR_ALREADY_EXISTS:                 return "The desired element already exists. This is returned by DXGIDeclareAdapterRemovalSupport if it is not the first time that the function is called.";
        case DXGI_ERROR_CANNOT_PROTECT_CONTENT:         return "DXGI can't provide content protection on the swap chain. This error is typically caused by an older driver, or when you use a swap chain that is incompatible with content protection.";
        case DXGI_ERROR_DEVICE_HUNG:                    return "The application's device failed due to badly formed commands sent by the application. This is an design-time issue that should be investigated and fixed.";
        case DXGI_ERROR_DEVICE_REMOVED:                 return "The video card has been physically removed from the system, or a driver upgrade for the video card has occurred. The application should destroy and recreate the device. For help debugging the problem, call ID3D12Device::GetDeviceRemovedReason.";
        case DXGI_ERROR_DEVICE_RESET:                   return "The device failed due to a badly formed command. This is a run-time issue; The application should destroy and recreate the device.";
        case DXGI_ERROR_DRIVER_INTERNAL_ERROR:          return "The driver encountered a problem and was put into the device removed state.";
        case DXGI_ERROR_FRAME_STATISTICS_DISJOINT:      return "An event (for example, a power cycle) interrupted the gathering of presentation statistics.";
        case DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE:   return "The application attempted to acquire exclusive ownership of an output, but failed because some other application (or device within the application) already acquired ownership.";
        case DXGI_ERROR_INVALID_CALL:                   return "The application provided invalid parameter data; this must be debugged and fixed before the application is released.";
        case DXGI_ERROR_MORE_DATA:                      return "The buffer supplied by the application is not big enough to hold the requested data.";
        case DXGI_ERROR_NAME_ALREADY_EXISTS:            return "The supplied name of a resource in a call to IDXGIResource1::CreateSharedHandle is already associated with some other resource.";
        case DXGI_ERROR_NONEXCLUSIVE:                   return "A global counter resource is in use, and the Direct3D device can't currently use the counter resource.";
        case DXGI_ERROR_NOT_CURRENTLY_AVAILABLE:        return "The resource or request is not currently available, but it might become available later.";
        case DXGI_ERROR_NOT_FOUND:                      return "When calling IDXGIObject::GetPrivateData, the GUID passed in is not recognized as one previously passed to IDXGIObject::SetPrivateData or IDXGIObject::SetPrivateDataInterface. When calling IDXGIFactory::EnumAdapters or IDXGIAdapter::EnumOutputs, the enumerated ordinal is out of range.";
        case DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED:     return "Reserved";
        case DXGI_ERROR_REMOTE_OUTOFMEMORY:             return "Reserved";
        case DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE:       return "The DXGI output (monitor) to which the swap chain content was restricted is now disconnected or changed.";
        case DXGI_ERROR_SDK_COMPONENT_MISSING:          return "The operation depends on an SDK component that is missing or mismatched.";
        case DXGI_ERROR_SESSION_DISCONNECTED:           return "The Remote Desktop Services session is currently disconnected.";
        case DXGI_ERROR_UNSUPPORTED:                    return "The requested functionality is not supported by the device or the driver.";
        case DXGI_ERROR_WAIT_TIMEOUT:                   return "The time-out interval elapsed before the next desktop frame was available.";
        case DXGI_ERROR_WAS_STILL_DRAWING:              return "The GPU was busy at the moment when a call was made to perform an operation, and did not execute or schedule the operation.";
        case D3D12_ERROR_ADAPTER_NOT_FOUND:             return "The specified cached PSO was created on a different adapter and cannot be reused on the current adapter.";
        case D3D12_ERROR_DRIVER_VERSION_MISMATCH:       return "The specified cached PSO was created on a different driver version and cannot be reused on the current adapter.";
        case D3D12_ERROR_INVALID_REDIST:                return "The D3D12 SDK version configuration of the host exe is invalid.";
        case DXGI_STATUS_OCCLUDED:                      return "The window content is not visible. When receiving this status, an application can stop rendering and use DXGI_PRESENT_TEST to determine when to resume rendering. You will not receive DXGI_STATUS_OCCLUDED if you're using a flip model swap chain.";
        case DXGI_STATUS_MODE_CHANGED:                  return "The desktop display mode has been changed, there might be color conversion/stretching. The application should call IDXGISwapChain::ResizeBuffers to match the new display mode.";
        case DXGI_STATUS_MODE_CHANGE_IN_PROGRESS:       return "IDXGISwapChain::ResizeTarget and IDXGISwapChain::SetFullscreenState will return DXGI_STATUS_MODE_CHANGE_IN_PROGRESS if a fullscreen/windowed mode transition is occurring when either API is called.";
        default:                                        return "An error has occurred";
    }
    // clang-format on
}

GFXRECON_END_NAMESPACE(enumutil)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_ENUM_UTIL_H
