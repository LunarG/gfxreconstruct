
#ifndef GFXRECON_DECODE_VULKAN_DIRECT_DRIVER_RESOLVER_H
#define GFXRECON_DECODE_VULKAN_DIRECT_DRIVER_RESOLVER_H

#include "format/format.h"
#include "util/defines.h"
#include "util/platform.h"

#include "vulkan/vulkan.h"

#include <string>
#include <string_view>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// SetDirectDriverInfoCommand with the strings copied out of the block buffer
struct DirectDriverInfo
{
    format::SetDirectDriverInfoCommand header{};
    std::string                        module_path;
    std::string                        symbol_name;
};

// The library operations that the resolver uses. Tests inject fakes here.
struct DirectDriverLoadOps
{
    util::platform::LibraryHandle (*open_library)(const char* library_path);
    void* (*get_proc_address)(util::platform::LibraryHandle library, const char* symbol_name);
    void (*close_library)(util::platform::LibraryHandle library);
};

// The operations that open real libraries with the platform functions.
DirectDriverLoadOps GetDefaultDirectDriverLoadOps();

struct DirectDriverResolveResult
{
    PFN_vkGetInstanceProcAddr     entry_point{ nullptr };
    util::platform::LibraryHandle library{ nullptr }; // Open while the entry point is in use. The caller closes it.
    std::string                   library_path;       // The path that was opened.
    std::string                   symbol_name;        // The exported name that resolved to the entry point.
    std::string                   message;            // The reason, when the resolve failed.

    bool Succeeded() const { return entry_point != nullptr; }
};

// Load the driver that a SetDirectDriverInfoCommand block describes and resolve its entry point.
//
// `override_path` replaces the recorded module path when it is not empty. The recorded symbol name is tried
// first. When it is empty or does not resolve, the common entry point names are tried in order.
// On failure the returned library is null, nothing stays open, and `message` says why.
DirectDriverResolveResult
ResolveDirectDriver(const DirectDriverInfo& info, const std::string& override_path, const DirectDriverLoadOps& ops);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DIRECT_DRIVER_RESOLVER_H
