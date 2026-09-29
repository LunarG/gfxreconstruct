/*
** Copyright (c) 2026 Arm Limited <open-source-office@arm.com>
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

#ifndef GFXRECON_DECODE_VULKAN_API_CALL_READER_H
#define GFXRECON_DECODE_VULKAN_API_CALL_READER_H

#include "decode/vulkan_native_call_callbacks.h"
#include "util/defines.h"

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#if defined(_WIN32)
#if defined(GFXRECON_VULKAN_API_READER_EXPORTS)
#define GFXRECON_VULKAN_API_READER_EXPORT __declspec(dllexport)
#elif defined(GFXRECON_VULKAN_API_READER_SHARED)
#define GFXRECON_VULKAN_API_READER_EXPORT __declspec(dllimport)
#else
#define GFXRECON_VULKAN_API_READER_EXPORT
#endif
#elif defined(__GNUC__) && (__GNUC__ >= 4)
#define GFXRECON_VULKAN_API_READER_EXPORT __attribute__((visibility("default")))
#else
#define GFXRECON_VULKAN_API_READER_EXPORT
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(format)
struct FileHeader;
GFXRECON_END_NAMESPACE(format)
GFXRECON_BEGIN_NAMESPACE(decode)

enum BlockIOError : int32_t;
class VulkanConsumer;

/// A Vulkan-only facade for reading API calls from a gfxreconstruct capture.
///
/// Metadata commands and frame/state marker callbacks are not dispatched to
/// the consumer. The native-callback reader can opt in to FillMemory metadata
/// through SetMemoryUpdateCallback. A caller-provided consumer must outlive
/// the reader.
class GFXRECON_VULKAN_API_READER_EXPORT VulkanApiCallReader
{
  public:
    /// Construct a reader that dispatches to registered native Vulkan callbacks.
    explicit VulkanApiCallReader(uint64_t block_limit = 0);

    /// Construct a reader that dispatches decoded VulkanConsumer callbacks.
    explicit VulkanApiCallReader(VulkanConsumer& consumer, uint64_t block_limit = 0);

    ~VulkanApiCallReader();

    VulkanApiCallReader(const VulkanApiCallReader&)            = delete;
    VulkanApiCallReader& operator=(const VulkanApiCallReader&) = delete;
    VulkanApiCallReader(VulkanApiCallReader&&)                 = delete;
    VulkanApiCallReader& operator=(VulkanApiCallReader&&)      = delete;

    bool Initialize(const std::string& filename);

    /// Process calls through the next frame boundary.
    /// Returns true when more frames remain. Check GetErrorState() when false.
    bool ProcessNextFrame();

    /// Process all remaining Vulkan calls. Returns false on an I/O error or a
    /// strict native-callback error.
    bool ProcessAllFrames();

    BlockIOError GetErrorState() const;

    bool EntireFileWasProcessed() const;

    uint64_t GetCurrentFrameNumber() const;

    uint64_t GetCurrentBlockIndex() const;

    const format::FileHeader& GetFileHeader() const;

    /// Register a native Vulkan function by its Vulkan command name. The
    /// callback's return value is ignored; the captured return value is exposed
    /// through the call hooks. Registering nullptr removes an existing callback.
    /// Returns false for an unsupported command name or when this reader was
    /// constructed with an external VulkanConsumer.
    bool RegisterCallback(const std::string& name, PFN_vkVoidFunction callback);

    bool RegisterCallback(const std::string& name, std::nullptr_t)
    {
        return RegisterCallback(name, static_cast<PFN_vkVoidFunction>(nullptr));
    }

    template <typename Function>
    bool RegisterCallback(const std::string& name, Function callback)
    {
        return RegisterCallback(name, reinterpret_cast<PFN_vkVoidFunction>(callback));
    }

    /// Register a table of callbacks. Returns the number accepted. Unknown
    /// commands and malformed entries are appended to rejected_entries when it
    /// is non-null.
    size_t RegisterCallbacks(const VulkanNativeCallbackEntry*                    entries,
                             size_t                                              count,
                             std::vector<VulkanNativeCallbackRegistrationError>* rejected_entries = nullptr);

    bool GetSupportedCallbackInfo(const std::string& name, VulkanNativeCommandInfo* info) const;

    bool SetMissingCallbackPolicy(VulkanNativeMissingCallbackPolicy policy);

    VulkanNativeMissingCallbackPolicy GetMissingCallbackPolicy() const;

    bool HasNativeCallError() const;

    const VulkanNativeCallError& GetLastNativeCallError() const;

    void ClearNativeCallError();

    bool SetPreCallHook(VulkanNativeCallCallbacks::CallHook hook, void* user_data);

    bool SetPostCallHook(VulkanNativeCallCallbacks::CallHook hook, void* user_data);

    bool SetMissingCallbackHook(VulkanNativeCallCallbacks::CallHook hook, void* user_data);

    /// Register for captured writes to mapped device memory. The update data
    /// is only valid for the duration of the callback. Passing nullptr disables
    /// FillMemory decoding. Returns false for an external-consumer reader.
    bool SetMemoryUpdateCallback(VulkanNativeCallCallbacks::MemoryUpdateCallback callback, void* user_data);

    /// Register for captured physical-device memory properties. The callback
    /// receives SetDeviceMemoryPropertiesCommand metadata in trace order.
    /// Passing nullptr disables metadata decoding. Returns false for an
    /// external-consumer reader.
    bool SetDeviceMemoryPropertiesCallback(VulkanNativeCallCallbacks::DeviceMemoryPropertiesCallback callback,
                                           void*                                                     user_data);

    bool SetResourceInitializationBeginCallback(VulkanNativeCallCallbacks::ResourceInitializationBeginCallback callback,
                                                void* user_data);

    bool SetBufferInitializationCallback(VulkanNativeCallCallbacks::BufferInitializationCallback callback,
                                         void*                                                   user_data);

    bool SetImageInitializationCallback(VulkanNativeCallCallbacks::ImageInitializationCallback callback,
                                        void*                                                  user_data);

    /// The end callback is the resource-initialization completion boundary.
    /// Consumers issuing asynchronous GPU uploads should submit them and
    /// establish completion before returning from this callback.
    bool SetResourceInitializationEndCallback(VulkanNativeCallCallbacks::ResourceInitializationEndCallback callback,
                                              void*                                                        user_data);

    bool SetDeviceAddressFixupCallback(VulkanNativeCallCallbacks::DeviceAddressFixupCallback callback, void* user_data);

    bool SetShaderGroupHandleFixupCallback(VulkanNativeCallCallbacks::ShaderGroupHandleFixupCallback callback,
                                           void*                                                     user_data);

    /// Register for parsed metacommands that are skipped because no native
    /// importer callback handles them. Returns false for an external-consumer
    /// reader.
    bool SetUnhandledMetaCommandCallback(VulkanNativeCallCallbacks::UnhandledMetaCommandCallback callback,
                                         void*                                                   user_data);

    /// Register for captured opaque Vulkan object addresses. The reader resolves
    /// the object type and native handle when the owning object is known.
    bool SetOpaqueAddressCallback(VulkanNativeCallCallbacks::OpaqueAddressCallback callback, void* user_data);

    bool SetAccelerationStructuresBuildCallback(VulkanNativeCallCallbacks::AccelerationStructuresBuildCallback callback,
                                                void* user_data);

    bool SetAccelerationStructuresCopyCallback(VulkanNativeCallCallbacks::AccelerationStructuresCopyCallback callback,
                                               void*                                                         user_data);

    bool SetAccelerationStructureWritePropertiesCallback(
        VulkanNativeCallCallbacks::AccelerationStructureWritePropertiesCallback callback, void* user_data);

  private:
    class Impl;
    std::unique_ptr<Impl> impl_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_API_CALL_READER_H
