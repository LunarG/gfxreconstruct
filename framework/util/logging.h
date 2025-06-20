/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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
        Severity    min_severity{ kInfoSeverity };     // Any severity >= to this value will print
        bool        output_detailed_log_info{ false }; // Output detailed log messages
        bool        flush_after_write{ false };        // Flush the file/console after every log write
        bool        use_indent{ false };               // Write out messages using indenting
        uint32_t    indent{ 0 };                       // Number of indents to shift this message
        std::string indent_spaces{ "    " };           // String of spaces used for each indent
        bool        break_on_error{ false };           // If an error occurs, force a break

        // File settings
        bool        write_to_file{ false };  // Write info to a file
        bool        create_new{ true };      // Overwrite any previous version of the file every Init call.
        bool        leave_file_open{ true }; // When we write, keep the file open for more efficient writing
        std::string file_name;               // Name of the file (including path)
        FILE*       file_pointer{ nullptr }; // Pointer to opened file

        // Console settings
        bool write_to_console{ true };           // Write info out to the console
        bool output_errors_to_stderr{ true };    // Output errors to stderr versus stdout
        bool output_to_os_debug_string{ false }; // Windows-specific output messages to OutputDebugString
    };

    static void Init(Severity    min_severity              = kInfoSeverity,
                     const char* log_file_name             = nullptr,
                     bool        leave_file_open           = true,
                     bool        create_new_file_on_open   = true,
                     bool        flush_after_write         = false,
                     bool        break_on_error            = false,
                     bool        output_detailed_log_info  = false,
                     bool        write_to_console          = true,
                     bool        errors_to_stderr          = true,
                     bool        output_to_os_debug_string = false,
                     bool        use_indent                = false);

    static void Init(const Settings& settings);

    static void Release();

    static void
    LogMessage(Severity severity, const char* file, const char* function, const char* line, const char* message, ...);

    static void IncreaseIndent()
    {
        if (settings_.use_indent)
        {
            settings_.indent++;
        }
    }

    static void DecreaseIndent()
    {
        if (settings_.use_indent)
        {
            settings_.indent--;
        }
    }

    static bool WillOutputMessage(Severity severity)
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

    static std::string SeverityToString(Severity severity)
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

    // Returns true if Severity was successfully parsed into parsed_severity. Returns false if the string could not be
    // parsed as a Severity and parsed_severity is not modified.
    static bool StringToSeverity(const std::string& value_string, Severity& parsed_severity)
    {
        bool parse_success = true;

        if (platform::StringCompareNoCase("debug", value_string.c_str()) == 0)
        {
            parsed_severity = Severity::kDebugSeverity;
        }
        else if (platform::StringCompareNoCase("info", value_string.c_str()) == 0)
        {
            parsed_severity = Severity::kInfoSeverity;
        }
        else if (platform::StringCompareNoCase("warning", value_string.c_str()) == 0)
        {
            parsed_severity = Severity::kWarningSeverity;
        }
        else if (platform::StringCompareNoCase("error", value_string.c_str()) == 0)
        {
            parsed_severity = Severity::kErrorSeverity;
        }
        else if (util::platform::StringCompareNoCase("fatal", value_string.c_str()) == 0)
        {
            parsed_severity = Severity::kFatalSeverity;
        }
        else
        {
            parse_success = false;
        }

        return parse_success;
    }

    static Severity GetSeverity() { return settings_.min_severity; }

  private:
    static std::string ConvertFormatVaListToString(const std::string& format_string, va_list& var_args);

    static Settings settings_;
};

#ifdef GFXRECON_ENABLE_COMMAND_TRACE

class CommandTrace
{
  public:
    CommandTrace(const char* file, const char* function)
    {
        _file     = file;
        _function = function;
        Log::LogMessage(
            Log::Severity::kCommandSeverity, _file.c_str(), _function.c_str(), "", "Entering %s", _function.c_str());
        Log::IncreaseIndent();
    }

    ~CommandTrace()
    {
        Log::DecreaseIndent();
        Log::LogMessage(
            Log::Severity::kCommandSeverity, _file.c_str(), _function.c_str(), "", "Exiting %s", _function.c_str());
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

#define GFXRECON_LOG_ONCE(X)         \
    {                                \
        static bool log_once = true; \
        if (log_once)                \
        {                            \
            X;                       \
            log_once = false;        \
        }                            \
    }

// clang-format off
#define GFXRECON_WRITE_CONSOLE_ONCE(message, ...) GFXRECON_LOG_ONCE(GFXRECON_WRITE_CONSOLE(message, ##__VA_ARGS__))
#define GFXRECON_LOG_FATAL_ONCE(message, ...)     GFXRECON_LOG_ONCE(GFXRECON_LOG_FATAL(message, ##__VA_ARGS__))
#define GFXRECON_LOG_ERROR_ONCE(message, ...)     GFXRECON_LOG_ONCE(GFXRECON_LOG_ERROR(message, ##__VA_ARGS__))
#define GFXRECON_LOG_WARNING_ONCE(message, ...)   GFXRECON_LOG_ONCE(GFXRECON_LOG_WARNING(message, ##__VA_ARGS__))
#define GFXRECON_LOG_INFO_ONCE(message, ...)      GFXRECON_LOG_ONCE(GFXRECON_LOG_INFO(message, ##__VA_ARGS__))
#define GFXRECON_LOG_DEBUG_ONCE(message, ...)     GFXRECON_LOG_ONCE(GFXRECON_LOG_DEBUG(message, ##__VA_ARGS__))
// clang-format on

#ifdef NDEBUG // release version

// Release build: enable GFXRECON_ENABLE_RELEASE_ASSERTS to see assert output
#ifdef GFXRECON_ENABLE_RELEASE_ASSERTS
#define GFXRECON_ASSERT(EXP)                                                            \
    if (!(EXP))                                                                         \
    {                                                                                   \
        GFXRECON_LOG_FATAL("Assertion failed: '%s' (%s:%d)", #EXP, __FILE__, __LINE__); \
    }

// Release build: asserts are by default a no-op
#else
#define GFXRECON_ASSERT(EXP) ((void)0);
#endif

// Debug build
#else
#define GFXRECON_ASSERT(EXP)                                                            \
    if (!(EXP))                                                                         \
    {                                                                                   \
        GFXRECON_LOG_FATAL("Assertion failed: '%s' (%s:%d)", #EXP, __FILE__, __LINE__); \
    }                                                                                   \
    assert(EXP);
#endif

#ifdef GFXRECON_ENABLE_COMMAND_TRACE

#define GFXRECON_LOG_COMMAND() gfxrecon::util::CommandTrace command_trace(__FILE__, __FUNCTION__);

#else

// If not defined, make this a NOOP so we don't waste any time in a standard trace session on
// creating/destroying a class we don't care about.
#define GFXRECON_LOG_COMMAND()

#endif

#endif // GFXRECON_UTIL_LOGGING_H
