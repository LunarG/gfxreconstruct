/*
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

#ifndef BRIMSTONE_UTIL_LOGGING_H
#define BRIMSTONE_UTIL_LOGGING_H

#include "util/platform.h"

#include <cstdarg>
#include <string>
#include <cstring>

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)
BRIMSTONE_BEGIN_NAMESPACE(logging)

// Logging types
enum Severity
{
   SEVERITY_COMMANDS = 0,
   SEVERITY_DEBUG,
   SEVERITY_INFO,
   SEVERITY_WARNING,
   SEVERITY_ERROR,
   SEVERITY_FATAL,
};

struct Settings
{
    // General settings
    Severity min_severity;          // Any severity >= to this value will print
    bool output_detailed_log_info;  // Output detailed log messages
    bool flush_after_write;         // Flush the file/console after every log write
    bool use_indent;                // Write out messages using indenting
    uint32_t indent;                // Number of indents to shift this message
    std::string indent_spaces;      // String of spaces used for each indent
    bool break_on_error;            // If an error occurs, force a break

    // File settings
    bool write_to_file;             // Write info to a file
    bool leave_file_open;           // When we write, keep the file open for more efficient writing
    std::string file_name;          // Name of the file (including path)
    FILE* file_pointer;             // Pointer to opened file

    // Console settings
    bool write_to_console;          // Write info out to the console
    bool output_errors_to_stderr;   // Output errors to stderr versus stdout

    // Constructor used for default initialization
    Settings() : min_severity(SEVERITY_ERROR), output_detailed_log_info(false),
                 flush_after_write(false), use_indent(false), indent(0),
                 indent_spaces(std::string("   ")), break_on_error(false), write_to_file(false),
                 leave_file_open(true), file_name(std::string("")), file_pointer(nullptr),
                 write_to_console(true), output_errors_to_stderr(true)
    {
    }
};

static Settings g_settings;

// General Logging functions
std::string SeverityToString(Severity severity)
{
    switch (severity) {
        case SEVERITY_COMMANDS:
            return "COMMAND";
        case SEVERITY_DEBUG:
            return "DEBUG";
        case SEVERITY_INFO:
            return "INFO";
        case SEVERITY_WARNING:
            return "WARNING";
        case SEVERITY_ERROR:
            return "ERROR";
        case SEVERITY_FATAL:
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}

void Init(Severity min_severity = SEVERITY_ERROR, const char* log_file_name = NULL, bool leave_file_open = true,
          bool create_new_file_on_open = true, bool flush_after_write = false, bool break_on_error = false,
          bool output_detailed_log_info = false, bool write_to_console = true, bool errors_to_stderr = true,
          bool use_indent = false)
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
            g_settings.write_to_file = true;
            g_settings.leave_file_open = leave_file_open;
            g_settings.file_name = log_file_name;
            if (!g_settings.leave_file_open)
            {
                platform::FileClose(g_settings.file_pointer);
            }
        }
    }
    g_settings.flush_after_write = flush_after_write;
    g_settings.break_on_error = break_on_error;
    g_settings.output_detailed_log_info = output_detailed_log_info;
    g_settings.write_to_console = write_to_console;
    g_settings.output_errors_to_stderr = errors_to_stderr;
    g_settings.use_indent = use_indent;
}

void Release()
{
    if (g_settings.write_to_file && g_settings.leave_file_open)
    {
        platform::FileClose(g_settings.file_pointer);
    }
}

void LogMessage(Severity severity, const char* file, const char* function, const char* line,
                const char* message, ...)
{
    bool opened_file = false;
    bool write_indent = g_settings.use_indent && g_settings.indent > 0;
    bool message_written = false;
    FILE* log_file_ptr;

    // Log message prefix
    std::string prefix = "[Brimstone] ";
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

    for (uint32_t output_target = 0; output_target < 2; ++output_target)
    {
        switch (output_target)
        {
            case 0: // Output to console
                if (!g_settings.write_to_console)
                {
                    continue;
                }

                if (SEVERITY_ERROR <= severity && g_settings.output_errors_to_stderr)
                {
                    log_file_ptr = stderr;
                }
                else
                {
                    log_file_ptr = stdout;
                }
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
            !(output_target == 0 && severity >= SEVERITY_ERROR && g_settings.output_errors_to_stderr))
        {
            continue;
        }

        platform::FilePuts(prefix.c_str(), log_file_ptr);
        if (write_indent)
        {
            for (uint32_t iii = 0; iii < g_settings.indent; ++iii)
            {
                platform::FilePuts(g_settings.indent_spaces.c_str(), log_file_ptr);
            }
        }

        va_list valist;
        va_start(valist, message);
        platform::FileVprintf(log_file_ptr, message, valist);
        va_end(valist);
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

    // Break on error if necessary, failing message should be this one
    // (also the last one written).
    if (SEVERITY_ERROR <= severity && g_settings.break_on_error)
    {
        platform::TriggerDebugBreak();
    }
}

#ifdef BRIMSTONE_ENABLE_COMMAND_TRACE

class CommandTrace
{
  public:
    CommandTrace(const char* file, const char* function)
    {
        _file = file;
        _function = function;
        LogMessage(SEVERITY_COMMANDS, _file.c_str(), _function.c_str(), "", "Entering %s", _function.c_str());
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
        LogMessage(SEVERITY_COMMANDS, _file.c_str(), _function.c_str(), "", "Exiting %s", _function.c_str());
    }

  private:
    std::string _file;
    std::string _function;
};

#endif

BRIMSTONE_END_NAMESPACE(logging)
BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

// Functions defined outside of the namespace for easier use
#define BRIMSTONE_LOG_FATAL(message, ...) do { \
        brimstone::utils::logging::LogMessage(brimstone::utils::logging::SEVERITY_FATAL, \
                                              __FILE__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__); \
    } while (0)
#define BRIMSTONE_LOG_ERROR(message, ...) do { \
        brimstone::utils::logging::LogMessage(brimstone::utils::logging::SEVERITY_ERROR, \
                                              __FILE__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__); \
    } while (0)
#define BRIMSTONE_LOG_WARNING(message, ...) do { \
        brimstone::utils::logging::LogMessage(brimstone::utils::logging::SEVERITY_WARNING, \
                                              __FILE__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__); \
    } while (0)
#define BRIMSTONE_LOG_INFO(message, ...) do { \
        brimstone::utils::logging::LogMessage(brimstone::utils::logging::SEVERITY_INFO, \
                                              __FILE__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__); \
    } while (0)
#define BRIMSTONE_LOG_DEBUG(message, ...) do { \
        brimstone::utils::logging::LogMessage(brimstone::utils::logging::SEVERITY_DEBUG, \
                                              __FILE__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__); \
    } while (0)

#ifdef BRIMSTONE_ENABLE_COMMAND_TRACE

#define BRIMSTONE_LOG_COMMAND() brimstone::utils::logging CommandTrace command_trace(__FILE__, __FUNCTION__);

#else

// If not defined, make this a NOOP so we don't waste any time in a standard trace session on
// creating/destroying a class we don't care about.
#define BRIMSTONE_LOG_COMMAND()

#endif 

#endif // BRIMSTONE_UTIL_LOGGING_H
