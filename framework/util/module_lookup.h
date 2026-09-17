
#ifndef GFXRECON_UTIL_MODULE_LOOKUP_H
#define GFXRECON_UTIL_MODULE_LOOKUP_H

#include "util/defines.h"

#include <cstdint>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(platform)

// **NOTE**: The purpose behind this functionality is to enable support of the
//           VK_LUNARG_direct_driver_loading extension in GFXR.

// Description of the loaded module that contains a code address.
struct ModuleAddressInfo
{
    // Absolute path of the module. Empty when the path is not known.
    std::string module_path;

    // Exported symbol name that resolves to the address. Empty when no candidate name matched.
    std::string symbol_name;

    // The address minus the base address of the module. Zero when the base address is not known.
    uint64_t module_offset{ 0 };

    // True when the module is the executable of the current process.
    bool in_executable{ false };
};

// Get the absolute path of the executable of the current process. Return an empty string on failure.
std::string GetExecutablePath();

// Find the loaded module that contains an address and fill `info`.
// The function probes each name in `candidate_symbols` in order. The first name that resolves to
// `address` is stored in `info->symbol_name`.
// Return false when no loaded module contains the address. `info` is then left unchanged.
bool GetModuleAddressInfo(const void*                     address,
                          const std::vector<const char*>& candidate_symbols,
                          ModuleAddressInfo*              info);

GFXRECON_END_NAMESPACE(platform)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_MODULE_LOOKUP_H
