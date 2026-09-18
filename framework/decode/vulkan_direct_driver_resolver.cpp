
#include "decode/vulkan_direct_driver_resolver.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// The names that a driver entry point commonly has. This list mirrors the one that the capture layer probes.
const char* const kDirectDriverEntryPointNames[] = { "vk_icdGetInstanceProcAddr", "vkGetInstanceProcAddr" };

DirectDriverLoadOps GetDefaultDirectDriverLoadOps()
{
    return { util::platform::OpenLibrary, util::platform::GetProcAddress, util::platform::CloseLibrary };
}

DirectDriverResolveResult
ResolveDirectDriver(const DirectDriverInfo& info, const std::string& override_path, const DirectDriverLoadOps& ops)
{
    DirectDriverResolveResult result;

    const bool use_override = !override_path.empty();
    if (!use_override && ((info.header.flags & format::kDirectDriverInfoInExecutable) != 0))
    {
        result.message = "the entry point was inside the captured application executable (" + info.module_path +
                         "), which replay cannot load; give the driver library with --direct-driver-lib";
        return result;
    }

    result.library_path = use_override ? override_path : info.module_path;
    if (result.library_path.empty())
    {
        result.message = "the capture did not record a module path for the entry point; give the driver library "
                         "with --direct-driver-lib";
        return result;
    }

    util::platform::LibraryHandle library = ops.open_library(result.library_path.c_str());
    if (library == nullptr)
    {
        result.message = "could not open the driver library \"" + result.library_path + "\"";
        return result;
    }

    // The recorded name comes first. The common names cover a remap to a different driver library.
    std::vector<const char*> candidates;
    if (!info.symbol_name.empty())
    {
        candidates.push_back(info.symbol_name.c_str());
    }
    for (const char* name : kDirectDriverEntryPointNames)
    {
        if (info.symbol_name != name)
        {
            candidates.push_back(name);
        }
    }

    for (const char* name : candidates)
    {
        void* address = ops.get_proc_address(library, name);
        if (address != nullptr)
        {
            result.entry_point = reinterpret_cast<PFN_vkGetInstanceProcAddr>(address);
            result.library     = library;
            result.symbol_name = name;
            return result;
        }
    }

    ops.close_library(library);

    result.message = "the driver library \"" + result.library_path + "\" has no entry point named";
    for (size_t i = 0; i < candidates.size(); ++i)
    {
        result.message += (i == 0) ? " \"" : " or \"";
        result.message += candidates[i];
        result.message += "\"";
    }
    return result;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
