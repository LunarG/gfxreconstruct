/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "util/logging.h"
#include "util/date_time.h"

#include <cstdarg>
#include <string>
#include <cstring>
#include <cstdio>

#if defined(__ANDROID__)
#include <android/log.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

Log::Settings Log::settings_;

std::string Log::ConvertFormatVaListToString(const std::string& format_string, va_list& var_args)
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

void Log::Init(Severity    min_severity,
               const char* log_file_name,
               bool        leave_file_open,
               bool        create_new_file_on_open,
               bool        flush_after_write,
               bool        break_on_error,
               bool        output_detailed_log_info,
               bool        output_timestamps,
               bool        write_to_console,
               bool        errors_to_stderr,
               bool        output_to_os_debug_string,
               bool        use_indent)
{
    settings_.min_severity = min_severity;
    if ((log_file_name != nullptr) && (strlen(log_file_name) > 0))
    {
        // Erase any previous contents
        std::string file_modifiers = "w";
        if (!create_new_file_on_open)
        {
            file_modifiers = "a";
        }

        int32_t result = platform::FileOpen(&settings_.file_pointer, log_file_name, file_modifiers.c_str());
        if (result == 0)
        {
            settings_.write_to_file   = true;
            settings_.leave_file_open = leave_file_open;
            settings_.file_name       = log_file_name;
            if (!settings_.leave_file_open)
            {
                platform::FileClose(settings_.file_pointer);
                settings_.file_pointer = nullptr;
            }
        }
    }
    settings_.create_new                = create_new_file_on_open;
    settings_.flush_after_write         = flush_after_write;
    settings_.break_on_error            = break_on_error;
    settings_.output_detailed_log_info  = output_detailed_log_info;
    settings_.output_timestamps         = output_timestamps;
    settings_.write_to_console          = write_to_console;
    settings_.output_errors_to_stderr   = errors_to_stderr;
    settings_.output_to_os_debug_string = output_to_os_debug_string;
    settings_.use_indent                = use_indent;
}

void Log::Init(const util::Log::Settings& settings)
{
    settings_ = settings;
    if (!settings.file_name.empty())
    {
        // Erase any previous contents
        std::string file_modifiers = "w";
        if (!settings.create_new)
        {
            file_modifiers = "a";
        }

        int32_t result =
            platform::FileOpen(&settings_.file_pointer, settings.file_name.c_str(), file_modifiers.c_str());
        if (result == 0)
        {
            settings_.write_to_file = true;
            if (!settings_.leave_file_open)
            {
                platform::FileClose(settings_.file_pointer);
                settings_.file_pointer = nullptr;
            }
        }
    }
}

void Log::Release()
{
    if (settings_.write_to_file && settings_.leave_file_open)
    {
        platform::FileClose(settings_.file_pointer);
        settings_.file_pointer  = nullptr;
        settings_.write_to_file = false;
    }
}

void Log::LogMessage(
    Log::Severity severity, const char* file, const char* function, const char* line, const char* message, ...)
{
    bool  opened_file      = false;
    bool  write_indent     = settings_.use_indent && (settings_.indent > 0);
    bool  output_to_stderr = false;
    FILE* log_file_ptr;

    // Log message prefix
    const char  process_tag[] = "gfxrecon";
    std::string prefix;

    if (severity != kAlwaysOutputSeverity)
    {
        // If the severity is an error (or worse) we always want to output it to stderr at least if the
        // user has enabled that in the settings.
        if ((severity >= kErrorSeverity) && settings_.write_to_console && settings_.output_errors_to_stderr)
        {
            output_to_stderr = true;
        }

        // Only add a string prefix if this isn't a string that always outputs.
        prefix += "[";
        prefix += process_tag;
        if (settings_.output_timestamps)
        {
            prefix += "]";
            prefix += "[";
            prefix += std::to_string(util::datetime::GetBootTime());
        }
        prefix += "] ";
        prefix += SeverityToString(severity);
        if (settings_.output_detailed_log_info)
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

    va_list valist;
    va_start(valist, message);
    std::string generated_string = ConvertFormatVaListToString(message, valist);
    va_end(valist);

    for (uint32_t output_target = 0; output_target < 2; ++output_target)
    {
        bool write_prefix_and_indents = (severity != kAlwaysOutputSeverity);
        switch (output_target)
        {
            case 0: // Output to console
#if defined(WIN32)
                    // On Windows, pass 0 should output to console or debug string if enabled.
                if (!settings_.write_to_console && !settings_.output_to_os_debug_string)
#else
                if (!settings_.write_to_console)
#endif
                {
                    continue;
                }

#if defined(__ANDROID__)
                // Never add prefixes or indents for the Android console logging.
                write_prefix_and_indents = false;
#else  // !__ANDROID__
                if (output_to_stderr)
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
                // Only continue if we're writing to a file and the severity is one we've
                // enabled.
                if (!settings_.write_to_file || (severity < settings_.min_severity))
                {
                    continue;
                }
                if (settings_.leave_file_open)
                {
                    log_file_ptr = settings_.file_pointer;
                }
                else if (severity >= settings_.min_severity)
                {
                    int32_t result = platform::FileOpen(&log_file_ptr, settings_.file_name.c_str(), "a");
                    if (result == 0)
                    {
                        opened_file = true;
                    }
                }
                break;
        }

        std::string output_message;
        if (write_prefix_and_indents)
        {
            output_message = prefix;
            if (write_indent)
            {
                for (uint32_t iii = 0; iii < settings_.indent; ++iii)
                {
                    output_message += settings_.indent_spaces;
                }
            }
        }
        output_message += generated_string;

#if defined(WIN32)
        // Console output on Windows should be sent to OutputDebugString
        // whenever the user requests it.
        if (output_target == 0 && settings_.output_to_os_debug_string)
        {
            OutputDebugStringA(output_message.c_str());
        }
        else
#elif defined(__ANDROID__)
        // Console output for Android always needs to be sent to Logcat.
        // So, ignore the "output_to_os_debug_string" flag and just always do it.
        if (output_target == 0)
        {
            switch (severity)
            {
                case kDebugSeverity:
                    __android_log_print(ANDROID_LOG_DEBUG, process_tag, "%s", output_message.c_str());
                    break;
                case kInfoSeverity:
                    __android_log_print(ANDROID_LOG_INFO, process_tag, "%s", output_message.c_str());
                    break;
                case kWarningSeverity:
                    __android_log_print(ANDROID_LOG_WARN, process_tag, "%s", output_message.c_str());
                    break;
                case kErrorSeverity:
                    __android_log_print(ANDROID_LOG_ERROR, process_tag, "%s", output_message.c_str());
                    break;
                case kFatalSeverity:
                    __android_log_assert(nullptr, process_tag, "%s", output_message.c_str());
                    break;
                default:
                    __android_log_print(ANDROID_LOG_VERBOSE, process_tag, "%s", output_message.c_str());
                    break;
            }
        }
        else
#endif // __ANDROID__
        {
            platform::FilePuts(output_message.c_str(), log_file_ptr);

            // Write the newline since we want to separate each log-line but don't
            // want the messages themselves to have to add it.
            output_message = "\n";
            platform::FileWrite(output_message.c_str(), 1, log_file_ptr);

            if (settings_.flush_after_write || settings_.leave_file_open)
            {
                platform::FileFlush(log_file_ptr);
            }
            if ((output_target == 1) && opened_file && !settings_.leave_file_open)
            {
                platform::FileClose(log_file_ptr);
            }
        }
    }

    // Break on error if necessary, failing message should be this one
    // (also the last one written).
    if ((kAlwaysOutputSeverity > severity) && (kErrorSeverity <= severity) && settings_.break_on_error)
    {
        platform::TriggerDebugBreak();
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
