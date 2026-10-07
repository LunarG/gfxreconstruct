
#include "util/module_lookup.h"

#include "util/logging.h"
#include "util/platform.h"

#include <utility>

#if defined(_WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else
#include <dlfcn.h>
#include <climits>
#include <cstdlib>
#if defined(__APPLE__)
#include <mach-o/dyld.h>
#else
#include <unistd.h>
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(platform)

GFXRECON_BEGIN_NAMESPACE(local_utils)

#if defined(_WIN32)

// Convert a wide string to a UTF8 value.
std::string WideStringToUtf8(const std::wstring& wide)
{
    if (wide.empty())
    {
        return std::string();
    }

    // Two-pass: once figure out size, second do the actual string generation.
    int size = WideCharToMultiByte(CP_UTF8, 0, wide.c_str(), -1, nullptr, 0, nullptr, nullptr);
    if (size <= 0)
    {
        return std::string();
    }

    std::string result(static_cast<size_t>(size), '\0');
    WideCharToMultiByte(CP_UTF8, 0, wide.c_str(), -1, result.data(), size, nullptr, nullptr);
    result.resize(static_cast<size_t>(size) - 1); // Drop the terminator.
    return result;
}

// Get the file name of a module in UTF8.
std::string GetModuleUtf8Filename(HMODULE module)
{
    std::wstring buffer(MAX_PATH, L'\0');
    for (;;)
    {
        DWORD length = GetModuleFileNameW(module, buffer.data(), static_cast<DWORD>(buffer.size()));
        if (length == 0)
        {
            return std::string();
        }
        if (length < buffer.size())
        {
            buffer.resize(length);
            return WideStringToUtf8(buffer);
        }
        buffer.resize(buffer.size() * 2);
    }
}

#else

// Resolve a path to its absolute form. Return the input when the file cannot be resolved.
// A driver inside an Android APK, or a library in the macOS shared cache, is not a file on disk.
std::string ResolveAbsolutePath(const char* path)
{
    char resolved[PATH_MAX];
    if (realpath(path, resolved) != nullptr)
    {
        return std::string(resolved);
    }
    return std::string(path);
}

#endif

// Probe the candidate names in the module. Store the first name that resolves to `address`.
void ProbeSymbols(LibraryHandle                   module,
                  const void*                     address,
                  const std::vector<const char*>& candidate_symbols,
                  ModuleAddressInfo*              info)
{
    for (const char* name : candidate_symbols)
    {
        // Qualify the call. On Windows, argument-dependent lookup on HMODULE also finds the Win32 GetProcAddress.
        if ((name != nullptr) && (platform::GetProcAddress(module, name) == address))
        {
            info->symbol_name = name;
            return;
        }
    }
    GFXRECON_LOG_WARNING("Failed to discover any symbols requested from module");
}

GFXRECON_END_NAMESPACE(local_utils)

std::string GetExecutablePath()
{
#if defined(_WIN32)
    return local_utils::GetModuleUtf8Filename(nullptr);
#elif defined(__APPLE__)
    uint32_t size = 0;
    _NSGetExecutablePath(nullptr, &size); // Query the required size.
    std::vector<char> buffer(size + 1, '\0');
    if (_NSGetExecutablePath(buffer.data(), &size) != 0)
    {
        return std::string();
    }
    return local_utils::ResolveAbsolutePath(buffer.data());
#else
    char    buffer[PATH_MAX];
    ssize_t length = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (length <= 0)
    {
        return std::string();
    }
    buffer[length] = '\0';
    return std::string(buffer);
#endif
}

bool GetModuleAddressInfo(const void*                     address,
                          const std::vector<const char*>& candidate_symbols,
                          ModuleAddressInfo*              info)
{
    if ((address == nullptr) || (info == nullptr))
    {
        return false;
    }

    ModuleAddressInfo result;

#if defined(_WIN32)
    HMODULE module = nullptr;
    if (!GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                            static_cast<LPCWSTR>(address),
                            &module) ||
        (module == nullptr))
    {
        return false;
    }

    result.module_path   = local_utils::GetModuleUtf8Filename(module);
    result.module_offset = reinterpret_cast<uintptr_t>(address) - reinterpret_cast<uintptr_t>(module);
    result.in_executable = (module == GetModuleHandleW(nullptr));

    // The module is loaded. GetProcAddress needs no extra reference.
    local_utils::ProbeSymbols(module, address, candidate_symbols, &result);
#else
    Dl_info dl_info{};
    if ((dladdr(address, &dl_info) == 0) || (dl_info.dli_fname == nullptr))
    {
        return false;
    }

    result.module_path = local_utils::ResolveAbsolutePath(dl_info.dli_fname);
    if (dl_info.dli_fbase != nullptr)
    {
        result.module_offset = reinterpret_cast<uintptr_t>(address) - reinterpret_cast<uintptr_t>(dl_info.dli_fbase);
    }

    // For the executable, dladdr reports the path from argv[0]. Compare against the real executable path.
    const std::string executable_path = GetExecutablePath();
    result.in_executable              = !executable_path.empty() && (result.module_path == executable_path);

    // The module is already loaded, so this open only adds a reference. The close drops it again.
    LibraryHandle module = OpenLibrary(dl_info.dli_fname);
    if (module != nullptr)
    {
        local_utils::ProbeSymbols(module, address, candidate_symbols, &result);
        CloseLibrary(module);
    }
#endif

    *info = std::move(result);
    return true;
}

GFXRECON_END_NAMESPACE(platform)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
