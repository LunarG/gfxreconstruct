/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_UTIL_LOGGING_H
#define GFXRECON_UTIL_LOGGING_H

#include "util/defines.h"
#include "util/platform.h"

#include <cstdarg>
#include <string>
#include <cstring>
#include <cstdio>

#if defined(__ANDROID__)
#include <android/log.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(logging)

// Logging types
enum Severity : uint32_t
{
    kCommandSeverity = 0,
    kDebugSeverity,
    kInfoSeverity,
    kWarningSeverity,
    kErrorSeverity,
    kFatalSeverity,
    kNoWritePrefix = 0xFFFFFFFF
};

struct Settings
{
    // General settings
    Severity    min_severity;             // Any severity >= to this value will print
    bool        output_detailed_log_info; // Output detailed log messages
    bool        flush_after_write;        // Flush the file/console after every log write
    bool        use_indent;               // Write out messages using indenting
    uint32_t    indent;                   // Number of indents to shift this message
    std::string indent_spaces;            // String of spaces used for each indent
    bool        break_on_error;           // If an error occurs, force a break

    // File settings
    bool        write_to_file;   // Write info to a file
    bool        leave_file_open; // When we write, keep the file open for more efficient writing
    std::string file_name;       // Name of the file (including path)
    FILE*       file_pointer;    // Pointer to opened file

    // Console settings
    bool write_to_console;           // Write info out to the console
    bool output_errors_to_stderr;    // Output errors to stderr versus stdout
    bool output_to_win_debug_string; // Windows-specific output messages to OutputDebugString

    // Constructor used for default initialization
    Settings() :
        min_severity(kErrorSeverity), output_detailed_log_info(false), flush_after_write(false), use_indent(false),
        indent(0), indent_spaces(std::string("   ")), break_on_error(false), write_to_file(false),
        leave_file_open(true), file_name(std::string("")), file_pointer(nullptr), write_to_console(true),
        output_errors_to_stderr(true), output_to_win_debug_string(false)
    {}
};

static Settings g_settings;

// General Logging functions
inline std::string SeverityToString(Severity severity)
{
    switch (severity)
    {
        case kCommandSeverity:
            return "COMMAND";
        case kDebugSeverity:
            return "DEBUG";
        case kInfoSeverity:
            return "INFO";
        case kWarningSeverity:
            return "WARNING";
        case kErrorSeverity:
            return "ERROR";
        case kFatalSeverity:
            return "FATAL";
        case kNoWritePrefix:
            // Don't write any severity string for "Always"
            return "";
        default:
            return "UNKNOWN";
    }
}

static std::string ConvertFormatVaListToString(const std::string& format_string, va_list& var_args)
{
    va_list var_args_copy;
    va_copy(var_args_copy, var_args);
    try
    {
        // Determine how much space is needed in the new string
        const int32_t sz = std::vsnprintf(nullptr, 0, format_string.c_str(), var_args) + 1;

        // Create a result string and clear it with spaces and then copy the formatted
        // string results into it.
        std::string result_string(sz, ' ');
        std::vsnprintf(&result_string.front(), sz, format_string.c_str(), var_args_copy);
        va_end(var_args_copy);
        return result_string;
    }
    catch (...)
    {
        va_end(var_args_copy);
        return "";
    }
}

inline void Init(Severity    min_severity               = kErrorSeverity,
                 const char* log_file_name              = NULL,
                 bool        leave_file_open            = true,
                 bool        create_new_file_on_open    = true,
                 bool        flush_after_write          = false,
                 bool        break_on_error             = false,
                 bool        output_detailed_log_info   = false,
                 bool        write_to_console           = true,
                 bool        errors_to_stderr           = true,
                 bool        output_to_win_debug_string = false,
                 bool        use_indent                 = false)
{
    g_settings.min_severity = min_severity;
    if (NULL != log_file_name && strlen(log_file_name) > 0)
    {
        // Erase any previous contents
        char file_modifiers[8] = "w";
        if (!create_new_file_on_open)
        {
            file_modifiers[0] = 'a';
        }
        if (!platform::FileOpen(&g_settings.file_pointer, log_file_name, &file_modifiers[0]))
        {
            g_settings.write_to_file   = true;
            g_settings.leave_file_open = leave_file_open;
            g_settings.file_name       = log_file_name;
            if (!g_settings.leave_file_open)
            {
                platform::FileClose(g_settings.file_pointer);
            }
        }
    }
    g_settings.flush_after_write          = flush_after_write;
    g_settings.break_on_error             = break_on_error;
    g_settings.output_detailed_log_info   = output_detailed_log_info;
    g_settings.write_to_console           = write_to_console;
    g_settings.output_errors_to_stderr    = errors_to_stderr;
    g_settings.output_to_win_debug_string = output_to_win_debug_string;
    g_settings.use_indent                 = use_indent;
}

inline void Release()
{
    if (g_settings.write_to_file && g_settings.leave_file_open)
    {
        platform::FileClose(g_settings.file_pointer);
    }
}

inline void
LogMessage(Severity severity, const char* file, const char* function, const char* line, const char* message, ...)
{
    bool  opened_file     = false;
    bool  write_indent    = g_settings.use_indent && g_settings.indent > 0;
    bool  message_written = false;
    FILE* log_file_ptr;

    // Log message prefix
    const char  process_tag[] = "gfxrecon";
    std::string prefix        = "";

    // If this is a "console write" always output style string, we don't want any
    // decorations before the string.
    if (severity != kNoWritePrefix)
    {
        prefix += "[";
        prefix += process_tag;
        prefix += "] ";
        prefix += SeverityToString(severity);
        if (g_settings.output_detailed_log_info)
        {
            prefix += " | ";
            prefix += file;
            prefix += ",";
            prefix += function;
            prefix += "(";
            prefix += line;
            prefix += ")";
        }
        prefix += " - ";
    }

    for (uint32_t output_target = 0; output_target < 2; ++output_target)
    {
        bool write_prefix_and_indents = (severity != kNoWritePrefix);
        switch (output_target)
        {
            case 0: // Output to console
                if (!g_settings.write_to_console)
                {
                    continue;
                }

#if defined(__ANDROID__)
                // Never add prefixes or indents for the Android console logging.
                write_prefix_and_indents = false;
#else  // !__ANDROID__
                if (kErrorSeverity <= severity && g_settings.output_errors_to_stderr)
                {
                    log_file_ptr = stderr;
                }
                else
                {
                    log_file_ptr = stdout;
                }
#endif // !__ANDROID__
                break;

            case 1: // Output to file
                if (!g_settings.write_to_file)
                {
                    continue;
                }
                if (g_settings.leave_file_open)
                {
                    log_file_ptr = g_settings.file_pointer;
                }
                else if (severity >= g_settings.min_severity)
                {
                    if (!platform::FileOpen(&log_file_ptr, g_settings.file_name.c_str(), "a"))
                    {
                        opened_file = true;
                    }
                }
                break;
        }

        // Only write out messages the user is interested in or errors if we're
        // re-directing errors to stderr
        if (severity < g_settings.min_severity &&
            !(output_target == 0 && severity >= kErrorSeverity && g_settings.output_errors_to_stderr))
        {
            continue;
        }

        if (write_prefix_and_indents)
        {
            platform::FilePuts(prefix.c_str(), log_file_ptr);
            if (write_indent)
            {
                for (uint32_t iii = 0; iii < g_settings.indent; ++iii)
                {
                    platform::FilePuts(g_settings.indent_spaces.c_str(), log_file_ptr);
                }
            }
        }

        va_list valist;
        va_start(valist, message);
        std::string generated_string = ConvertFormatVaListToString(message, valist);
        va_end(valist);

#if defined(WIN32)
        // Console output on Windows should be sent to OutputDebugString
        // whenever the user requests it.
        if (output_target == 0 && g_settings.output_to_win_debug_string)
        {
            OutputDebugStringA(generated_string.c_str());
        }
        else
#elif defined(__ANDROID__)
        // Console output for Android always needs to be sent to Logcat.
        if (output_target == 0)
        {
            switch (severity)
            {
                case kDebugSeverity:
                    __android_log_print(ANDROID_LOG_DEBUG, process_tag, "%s", generated_string.c_str());
                    break;
                case kInfoSeverity:
                    __android_log_print(ANDROID_LOG_INFO, process_tag, "%s", generated_string.c_str());
                    break;
                case kWarningSeverity:
                    __android_log_print(ANDROID_LOG_WARN, process_tag, "%s", generated_string.c_str());
                    break;
                case kErrorSeverity:
                    __android_log_print(ANDROID_LOG_ERROR, process_tag, "%s", generated_string.c_str());
                    break;
                case kFatalSeverity:
                    __android_log_print(ANDROID_LOG_FATAL, process_tag, "%s", generated_string.c_str());
                    break;
                default:
                    __android_log_print(ANDROID_LOG_VERBOSE, process_tag, "%s", generated_string.c_str());
                    break;
            }
        }
        else
#endif // __ANDROID__
        {
            platform::FilePuts(generated_string.c_str(), log_file_ptr);
            platform::FilePuts("\n", log_file_ptr);
            if (g_settings.flush_after_write)
            {
                platform::FileFlush(log_file_ptr);
            }
            if (output_target == 1 && opened_file && !g_settings.leave_file_open)
            {
                platform::FileClose(log_file_ptr);
            }
        }
    }

    // Break on error if necessary, failing message should be this one
    // (also the last one written).
    if (severity != kNoWritePrefix && kErrorSeverity <= severity && g_settings.break_on_error)
    {
        platform::TriggerDebugBreak();
    }
}

#ifdef GFXRECON_ENABLE_COMMAND_TRACE

class CommandTrace
{
  public:
    CommandTrace(const char* file, const char* function)
    {
        _file     = file;
        _function = function;
        LogMessage(kCommandSeverity, _file.c_str(), _function.c_str(), "", "Entering %s", _function.c_str());
        if (g_settings.use_indent)
        {
            g_settings.indent++;
        }
    }

    ~CommandTrace()
    {
        if (g_settings.use_indent)
        {
            g_settings.indent--;
        }
        LogMessage(kCommandSeverity, _file.c_str(), _function.c_str(), "", "Exiting %s", _function.c_str());
    }

  private:
    std::string _file;
    std::string _function;
};

#endif

GFXRECON_END_NAMESPACE(logging)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

// Functions defined outside of the namespace for easier use
#define GFXRECON_WRITE_CONSOLE(message, ...)                                     \
    gfxrecon::util::logging::LogMessage(gfxrecon::util::logging::kNoWritePrefix, \
                                        __FILE__,                                \
                                        __FUNCTION__,                            \
                                        GFXRECON_STR(__LINE__),                  \
                                        message,                                 \
                                        ##__VA_ARGS__)
#define GFXRECON_LOG_FATAL(message, ...)                                         \
    gfxrecon::util::logging::LogMessage(gfxrecon::util::logging::kFatalSeverity, \
                                        __FILE__,                                \
                                        __FUNCTION__,                            \
                                        GFXRECON_STR(__LINE__),                  \
                                        message,                                 \
                                        ##__VA_ARGS__)
#define GFXRECON_LOG_ERROR(message, ...)                                         \
    gfxrecon::util::logging::LogMessage(gfxrecon::util::logging::kErrorSeverity, \
                                        __FILE__,                                \
                                        __FUNCTION__,                            \
                                        GFXRECON_STR(__LINE__),                  \
                                        message,                                 \
                                        ##__VA_ARGS__)
#define GFXRECON_LOG_WARNING(message, ...)                                         \
    gfxrecon::util::logging::LogMessage(gfxrecon::util::logging::kWarningSeverity, \
                                        __FILE__,                                  \
                                        __FUNCTION__,                              \
                                        GFXRECON_STR(__LINE__),                    \
                                        message,                                   \
                                        ##__VA_ARGS__)
#define GFXRECON_LOG_INFO(message, ...)                                         \
    gfxrecon::util::logging::LogMessage(gfxrecon::util::logging::kInfoSeverity, \
                                        __FILE__,                               \
                                        __FUNCTION__,                           \
                                        GFXRECON_STR(__LINE__),                 \
                                        message,                                \
                                        ##__VA_ARGS__)
#define GFXRECON_LOG_DEBUG(message, ...)                                         \
    gfxrecon::util::logging::LogMessage(gfxrecon::util::logging::kDebugSeverity, \
                                        __FILE__,                                \
                                        __FUNCTION__,                            \
                                        GFXRECON_STR(__LINE__),                  \
                                        message,                                 \
                                        ##__VA_ARGS__)

#ifdef GFXRECON_ENABLE_COMMAND_TRACE

#define GFXRECON_LOG_COMMAND() gfxrecon::util::logging CommandTrace command_trace(__FILE__, __FUNCTION__)

#else

// If not defined, make this a NOOP so we don't waste any time in a standard trace session on
// creating/destroying a class we don't care about.
#define GFXRECON_LOG_COMMAND()

#endif

#endif // GFXRECON_UTIL_LOGGING_H
