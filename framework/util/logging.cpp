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

constexpr char g_process_tag[] = "gfxrecon";

GFXRECON_BEGIN_NAMESPACE(logging)

std::unique_ptr<LoggingManager> LoggingManager::singleton_;
std::once_flag                  LoggingManager::singleton_flag_;

LoggingManager& LoggingManager::GetSingleton()
{
    std::call_once(singleton_flag_, [&]() { singleton_.reset(new LoggingManager()); });
    return *singleton_;
}

LoggingManager::LoggingManager()
{
    const std::lock_guard<std::mutex> lock(target_mut_);

    // Initialize the unique pointers to be empty
    for (auto& tgt : logging_targets_)
    {
        tgt.reset(nullptr);
    }
}

LoggingManager::~LoggingManager() {}

void LoggingManager::LogMessage(LoggingSeverity severity, const std::string& message)
{
    const std::lock_guard<std::mutex> lock(target_mut_);

    for (auto& tgt : logging_targets_)
    {
        if (tgt)
        {
            tgt->LogMessage(severity, message);
        }
    }
}

void LoggingManager::SetMinimumSeverity(LoggingSeverity severity)
{
    const std::lock_guard<std::mutex> lock(target_mut_);

    for (auto& tgt : logging_targets_)
    {
        if (tgt)
        {
            tgt->SetSeverity(severity);
        }
    }
}

void LoggingManager::LogMessage(LoggingSeverity    severity,
                                const std::string& indented_message,
                                const std::string& non_indented_message)
{
    bool use_indent = indent_supported_ && indented_message.length() != non_indented_message.length();
    if (!use_indent)
    {
        LogMessage(severity, non_indented_message);
    }
    else
    {
        const std::lock_guard<std::mutex> lock(target_mut_);

        for (auto& tgt : logging_targets_)
        {
            if (tgt)
            {
                if (tgt->SupportsIndent())
                {
                    tgt->LogMessage(severity, indented_message);
                }
                else
                {
                    tgt->LogMessage(severity, non_indented_message);
                }
            }
        }
    }
}

void LoggingManager::UpdateStdOutTarget(bool write_to_console, bool write_to_stderr, bool flush_after_write)
{
    const std::lock_guard<std::mutex> lock(target_mut_);

    if (write_to_console)
    {
        if (!logging_targets_[kTarget_StdOut])
        {
            logging_targets_[kTarget_StdOut] = std::make_unique<logging::LoggingTargetStdout>();
            GFXRECON_ASSERT(logging_targets_[kTarget_StdOut]);
        }

        logging_targets_[kTarget_StdOut]->SetEnable(true);
        logging_targets_[kTarget_StdOut]->SetFlushAfterWrite(flush_after_write);

#if !defined(__ANDROID__)
        logging_targets_[kTarget_StdOut]->SetBoolExtendedOption(kOption_WriteErrors, !write_to_stderr);
#endif
    }
    else if (logging_targets_[kTarget_StdOut])
    {
        // Just disable it
        logging_targets_[kTarget_StdOut]->SetEnable(false);
    }
}

void LoggingManager::UpdateStdErrTarget(bool write_to_stderr, bool flush_after_write)
{
    // Android doesn't easily support separate stdout/stderr
#if !defined(__ANDROID__)
    const std::lock_guard<std::mutex> lock(target_mut_);

    if (write_to_stderr)
    {
        if (!logging_targets_[kTarget_StdErr])
        {
            logging_targets_[kTarget_StdErr] = std::make_unique<logging::LoggingTargetStderr>();
            GFXRECON_ASSERT(logging_targets_[kTarget_StdErr]);
        }

        logging_targets_[kTarget_StdErr]->SetEnable(true);
        logging_targets_[kTarget_StdErr]->SetFlushAfterWrite(flush_after_write);
    }
    else if (logging_targets_[kTarget_StdErr])
    {
        // Just disable it
        logging_targets_[kTarget_StdErr]->SetEnable(false);
    }
#endif // !defined(__ANDROID__)
}

bool LoggingManager::UpdateFileTarget(
    bool write_to_file, const std::string& file_name, bool create_new, bool leave_open, bool flush_after_write)
{
    const std::lock_guard<std::mutex> lock(target_mut_);

    bool succeeded = true;
    if (write_to_file)
    {
        if (!logging_targets_[kTarget_FileOut])
        {
            logging_targets_[kTarget_FileOut] = std::make_unique<logging::LoggingTargetFile>();
        }

        if (logging_targets_[kTarget_FileOut])
        {
            logging_targets_[kTarget_FileOut]->SetBoolExtendedOption(kOption_FileCreateNew, create_new);
            logging_targets_[kTarget_FileOut]->SetBoolExtendedOption(kOption_FileLeaveOpen, leave_open);
            logging_targets_[kTarget_FileOut]->SetStringExtendedOption(kOption_FileName, file_name);
            logging_targets_[kTarget_FileOut]->SetFlushAfterWrite(flush_after_write);
        }
    }
    else if (logging_targets_[kTarget_FileOut])
    {
        // Just disable it
        logging_targets_[kTarget_FileOut]->SetEnable(false);
    }
    return succeeded;
}

void LoggingManager::UpdateDebugViewTarget(bool enabled)
{
#if defined(WIN32)
    const std::lock_guard<std::mutex> lock(target_mut_);

    if (enabled)
    {
        if (!logging_targets_[kTarget_DebugView])
        {
            logging_targets_[kTarget_DebugView] = std::make_unique<logging::LoggingTargetDebugView>();
            GFXRECON_ASSERT(logging_targets_[kTarget_DebugView]);
        }

        logging_targets_[kTarget_DebugView]->SetEnable(true);
    }
    else if (logging_targets_[kTarget_DebugView])
    {
        // Just disable it
        logging_targets_[kTarget_DebugView]->SetEnable(false);
    }
#else
    if (enabled)
    {
        GFXRECON_LOG_ERROR("DebugView Logging target not supported on this platform");
    }
#endif // defined(WIN32)
}

GFXRECON_END_NAMESPACE(logging)

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

void Log::UpdateLogManagerComponents(gfxrecon::util::logging::LoggingManager& log_mgr)
{
    log_mgr.UpdateStdOutTarget(
        settings_.write_to_console, settings_.output_errors_to_stderr, settings_.flush_after_write);
    log_mgr.UpdateStdErrTarget(settings_.output_errors_to_stderr, settings_.flush_after_write);
    if (!log_mgr.UpdateFileTarget(settings_.write_to_file,
                                  settings_.file_name,
                                  settings_.create_new,
                                  settings_.leave_file_open,
                                  settings_.flush_after_write))
    {
        GFXRECON_LOG_ERROR("Failed to create LoggingTargetFile");
        settings_.write_to_file   = false;
        settings_.leave_file_open = false;
        settings_.file_name       = "";
    }
    log_mgr.UpdateDebugViewTarget(settings_.output_to_os_debug_string);
    log_mgr.SetMinimumSeverity(settings_.min_severity);

    // If using indent is enabled, tell the log manager
    if (settings_.use_indent)
    {
        log_mgr.EnableIndentSupport();
    }
}

void Log::Init(LoggingSeverity min_severity)
{
    settings_.min_severity = min_severity;
    UpdateLogManagerComponents(logging::LoggingManager::GetSingleton());
}

void Log::UpdateWithSettings(const util::Log::Settings& settings)
{
    auto& log_mgr = logging::LoggingManager::GetSingleton();

    // Update only the settings that have changed from the default.
    // This will override everything else since it comes from the command-line.
    Settings default_settings{};
    if (default_settings.min_severity != settings.min_severity)
    {
        settings_.min_severity = settings.min_severity;
        log_mgr.SetMinimumSeverity(settings_.min_severity);
    }
    if (default_settings.output_detailed_log_info != settings.output_detailed_log_info)
    {
        settings_.output_detailed_log_info = settings.output_detailed_log_info;
    }
    if (default_settings.output_timestamps != settings.output_timestamps)
    {
        settings_.output_timestamps = settings.output_timestamps;
    }
    if (default_settings.flush_after_write != settings.flush_after_write)
    {
        settings_.flush_after_write = settings.flush_after_write;
    }
    if (default_settings.use_indent != settings.use_indent)
    {
        settings_.use_indent    = settings.use_indent;
        settings_.indent        = settings.indent;
        settings_.indent_spaces = settings.indent_spaces;
    }
    if (default_settings.break_on_error != settings.break_on_error)
    {
        settings_.break_on_error = settings.break_on_error;
    }
    if (default_settings.write_to_file != settings.write_to_file)
    {
        settings_.write_to_file   = settings.write_to_file;
        settings_.create_new      = settings.create_new;
        settings_.leave_file_open = settings.leave_file_open;
        settings_.file_name       = settings.file_name;
    }
    if (default_settings.write_to_console != settings.write_to_console)
    {
        settings_.write_to_console = settings.write_to_console;
    }
    if (default_settings.output_errors_to_stderr != settings.output_errors_to_stderr)
    {
        settings_.output_errors_to_stderr = settings.output_errors_to_stderr;
    }
    if (default_settings.output_to_os_debug_string != settings.output_to_os_debug_string)
    {
        settings_.output_to_os_debug_string = settings.output_to_os_debug_string;
    }

    // Update the log targets as necessary
    UpdateLogManagerComponents(log_mgr);
}

void Log::LogMessage(
    LoggingSeverity severity, const char* file, const char* function, const char* line, const char* message, ...)
{
    bool        write_indent = settings_.use_indent && (settings_.indent > 0);
    std::string indented_version;
    std::string non_indented_version;

    // Only add a string prefix if this isn't a string that always outputs.
    std::string prefix;
    if (LoggingSeverity::kAlwaysOutput != severity)
    {
        prefix += "[";
        prefix += g_process_tag;
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

    // Generate the complete string from the incoming variable parameter list
    va_list valist;
    va_start(valist, message);
    std::string generated_string = ConvertFormatVaListToString(message, valist);
    va_end(valist);

    non_indented_version = prefix + generated_string;
    if (write_indent)
    {
        indented_version = prefix;
        if (settings_.use_indent)
        {
            for (uint32_t iii = 0; iii < settings_.indent; ++iii)
            {
                indented_version += settings_.indent_spaces;
            }
        }
        indented_version += generated_string;
        logging::LoggingManager::GetSingleton().LogMessage(severity, indented_version, non_indented_version);
    }
    else
    {
        logging::LoggingManager::GetSingleton().LogMessage(severity, non_indented_version);
    }

    // Break on error if necessary, failing message should be this one
    // (also the last one written).
    if ((LoggingSeverity::kAlwaysOutput != severity) && (LoggingSeverity::kError <= severity) &&
        settings_.break_on_error)
    {
        platform::TriggerDebugBreak();
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
