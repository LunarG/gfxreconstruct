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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class Log
{
  public:
    // Logging types
    enum Severity : uint32_t
    {
        kCommandSeverity = 0,
        kDebugSeverity,
        kInfoSeverity,
        kWarningSeverity,
        kErrorSeverity,
        kFatalSeverity,
        kAlwaysOutputSeverity = 0xFFFFFFFF
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

    static inline std::string SeverityToString(Severity severity);
    static void               Init(Severity    min_severity               = kErrorSeverity,
                                   const char* log_file_name              = NULL,
                                   bool        leave_file_open            = true,
                                   bool        create_new_file_on_open    = true,
                                   bool        flush_after_write          = false,
                                   bool        break_on_error             = false,
                                   bool        output_detailed_log_info   = false,
                                   bool        write_to_console           = true,
                                   bool        errors_to_stderr           = true,
                                   bool        output_to_win_debug_string = false,
                                   bool        use_indent                 = false);
    static void               Release();
    static inline bool        WillOutputMessage(Severity severity);
    static void
                       LogMessage(Severity severity, const char* file, const char* function, const char* line, const char* message, ...);
    static inline void IncreaseIndent()
    {
        if (settings_.use_indent)
        {
            settings_.indent++;
        }
    }
    static inline void DecreaseIndent()
    {
        if (settings_.use_indent)
        {
            settings_.indent--;
        }
    }

  private:
    static std::string ConvertFormatVaListToString(const std::string& format_string, va_list& var_args);

    static Settings settings_;
};

bool Log::WillOutputMessage(Log::Severity severity)
{
    // We're always going to output something at "kAlwaysOutputSeverity", so check other cases.
    if (severity < kAlwaysOutputSeverity)
    {
        Severity min_acceptable = settings_.min_severity;
        // If we're to output errors to the console, we'll also accept errors
        if (settings_.output_errors_to_stderr && settings_.write_to_console && min_acceptable > kErrorSeverity)
        {
            min_acceptable = kErrorSeverity;
        }
        if (severity < min_acceptable)
        {
            return false;
        }
    }
    return true;
}

std::string Log::SeverityToString(Log::Severity severity)
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
        case kAlwaysOutputSeverity:
            // Don't write any severity string for "Always"
            return "";
        default:
            return "UNKNOWN";
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
        Log::IncreaseIndent();
    }

    ~CommandTrace()
    {
        Log::DecreaseIndent();
        LogMessage(kCommandSeverity, _file.c_str(), _function.c_str(), "", "Exiting %s", _function.c_str());
    }

  private:
    std::string _file;
    std::string _function;
};

#endif

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

// Functions defined outside of the namespace for easier use
#define GFXRECON_WRITE_CONSOLE(message, ...)                                                \
    if (gfxrecon::util::Log::WillOutputMessage(gfxrecon::util::Log::kAlwaysOutputSeverity)) \
    {                                                                                       \
        gfxrecon::util::Log::LogMessage(gfxrecon::util::Log::kAlwaysOutputSeverity,         \
                                        __FILE__,                                           \
                                        __FUNCTION__,                                       \
                                        GFXRECON_STR(__LINE__),                             \
                                        message,                                            \
                                        ##__VA_ARGS__);                                     \
    }
#define GFXRECON_LOG_FATAL(message, ...)                                             \
    if (gfxrecon::util::Log::WillOutputMessage(gfxrecon::util::Log::kFatalSeverity)) \
    {                                                                                \
        gfxrecon::util::Log::LogMessage(gfxrecon::util::Log::kFatalSeverity,         \
                                        __FILE__,                                    \
                                        __FUNCTION__,                                \
                                        GFXRECON_STR(__LINE__),                      \
                                        message,                                     \
                                        ##__VA_ARGS__);                              \
    }
#define GFXRECON_LOG_ERROR(message, ...)                                             \
    if (gfxrecon::util::Log::WillOutputMessage(gfxrecon::util::Log::kErrorSeverity)) \
    {                                                                                \
        gfxrecon::util::Log::LogMessage(gfxrecon::util::Log::kErrorSeverity,         \
                                        __FILE__,                                    \
                                        __FUNCTION__,                                \
                                        GFXRECON_STR(__LINE__),                      \
                                        message,                                     \
                                        ##__VA_ARGS__);                              \
    }
#define GFXRECON_LOG_WARNING(message, ...)                                             \
    if (gfxrecon::util::Log::WillOutputMessage(gfxrecon::util::Log::kWarningSeverity)) \
    {                                                                                  \
        gfxrecon::util::Log::LogMessage(gfxrecon::util::Log::kWarningSeverity,         \
                                        __FILE__,                                      \
                                        __FUNCTION__,                                  \
                                        GFXRECON_STR(__LINE__),                        \
                                        message,                                       \
                                        ##__VA_ARGS__);                                \
    }
#define GFXRECON_LOG_INFO(message, ...)                                             \
    if (gfxrecon::util::Log::WillOutputMessage(gfxrecon::util::Log::kInfoSeverity)) \
    {                                                                               \
        gfxrecon::util::Log::LogMessage(gfxrecon::util::Log::kInfoSeverity,         \
                                        __FILE__,                                   \
                                        __FUNCTION__,                               \
                                        GFXRECON_STR(__LINE__),                     \
                                        message,                                    \
                                        ##__VA_ARGS__);                             \
    }
#define GFXRECON_LOG_DEBUG(message, ...)                                             \
    if (gfxrecon::util::Log::WillOutputMessage(gfxrecon::util::Log::kDebugSeverity)) \
    {                                                                                \
        gfxrecon::util::Log::LogMessage(gfxrecon::util::Log::kDebugSeverity,         \
                                        __FILE__,                                    \
                                        __FUNCTION__,                                \
                                        GFXRECON_STR(__LINE__),                      \
                                        message,                                     \
                                        ##__VA_ARGS__);                              \
    }

#ifdef GFXRECON_ENABLE_COMMAND_TRACE

#define GFXRECON_LOG_COMMAND() gfxrecon::util::CommandTrace command_trace(__FILE__, __FUNCTION__)

#else

// If not defined, make this a NOOP so we don't waste any time in a standard trace session on
// creating/destroying a class we don't care about.
#define GFXRECON_LOG_COMMAND()

#endif

#endif // GFXRECON_UTIL_LOGGING_H
