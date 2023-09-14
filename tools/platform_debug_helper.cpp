/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2023 LunarG, Inc.
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

#include <cstdlib>
#include <cctype>

#if defined(WIN32)

#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <crtdbg.h>

DWORD DisableDebugPopup(void)
{
    static char contents[512];
    DWORD       stored = GetEnvironmentVariableA("GFXRECON_NO_DEBUG_POPUP", contents, sizeof(contents));

    // Succeed contents for GFXRECON_NO_DEBUG_POPUP are 1 char or longer and they fit in the buffer
    // 0 is a valid return value but that means the env var is undefined or defined but empty
    bool non_empty     = stored >= 1;
    bool was_too_large = stored == sizeof(contents);

    if (non_empty && !was_too_large)
    {
        bool not_all_spaces = false;
        for (const char* c = contents; *c; c++)
        {
            if (!isspace(static_cast<unsigned char>(*c)))
            {
                not_all_spaces = true;
                break;
            }
        }

        char* endptr     = nullptr;
        bool  value      = strtoul(contents, &endptr, 10);
        bool  valid_zero = (value == 0) && (endptr == contents + strlen(contents));

        if (not_all_spaces && !valid_zero)
        {
            _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
            _set_error_mode(_OUT_TO_STDERR);
            SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);
            _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
            _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
            _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
            _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
            _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
            _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
        }
    }

    return stored;
}

extern "C"
{
    // We create a new program section here which is initialized before C++ dynamic
    // initializers, so that initializing this variable forces the function above to be called early
    // in program execution.
    // For more information on this linker section declaration, please see
    // https://learn.microsoft.com/en-us/cpp/c-runtime-library/crt-initialization?view=msvc-170 .
#pragma section(".CRT$XCT", read)
    __declspec(allocate(".CRT$XCT")) DWORD gfxrecon_disable_popup_result = DisableDebugPopup();
}

#endif /* defined(WIN32) */
