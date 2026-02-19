/*
** Copyright (c) 2025 LunarG, Inc.
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
#include "util/logging_targets.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(logging)

#if defined(__ANDROID__)
android_LogPriority LoggingTargetBase::SeverityToAndroidLogPriority(LoggingSeverity severity)
{
    switch (severity)
    {
        case LoggingSeverity::kDebug:
            return ANDROID_LOG_DEBUG;
        case LoggingSeverity::kInfo:
            return ANDROID_LOG_INFO;
        case LoggingSeverity::kWarning:
            return ANDROID_LOG_WARN;
        case LoggingSeverity::kError:
            return ANDROID_LOG_ERROR;
        case LoggingSeverity::kFatal:
            return ANDROID_LOG_FATAL;
        default:
            return ANDROID_LOG_VERBOSE;
    }
}
#endif // __ANDROID__

bool LoggingTargetStdout::WillOutputMessage(LoggingSeverity severity)
{
    // If the message should not be output, do not output it.
    // That includes when errors should go to stderr instead of stdout.
    if (!enabled_ || (!output_errors_ && (severity == LoggingSeverity::kError || severity == LoggingSeverity::kFatal)))
    {
        return false;
    }

    return severity == LoggingSeverity::kAlwaysOutput || severity >= min_severity_;
}

void LoggingTargetStdout::LogMessage(LoggingSeverity severity, const std::string& message)
{
    if (!WillOutputMessage(severity))
    {
        return;
    }

#if defined(__ANDROID__)
    android_LogPriority android_severity = SeverityToAndroidLogPriority(severity);

    // For Android, we treat fatal errors as an assert
    if (severity == LoggingSeverity::kFatal)
    {
        __android_log_assert(nullptr, android_message_tag_.c_str(), "%s", message.c_str());
    }
    else
    {
        __android_log_print(android_severity, android_message_tag_.c_str(), "%s", message.c_str());
    }
#else
    platform::FilePuts(message.c_str(), stdout);
    platform::FilePuts("\n", stdout);

    if (flush_after_write_)
    {
        platform::FileFlush(stdout);
    }
#endif
}

void LoggingTargetStdout::SetBoolExtendedOption(LoggingExtendedOption option, bool value)
{
    if (option == kOption_WriteErrors)
    {
        output_errors_ = value;
    }
}

LoggingTargetStderr::LoggingTargetStderr()
{
    min_severity_ = LoggingSeverity::kError;
}

bool LoggingTargetStderr::WillOutputMessage(LoggingSeverity severity)
{
    // If the message should not be output, do not output it.
    if (!enabled_)
    {
        return false;
    }

    // We do not want to output "Always" messages to stderr.  It ends up
    // duplicating messages going to stdout.
    return ((severity != LoggingSeverity::kAlwaysOutput) && (severity >= min_severity_));
}

void LoggingTargetStderr::LogMessage(LoggingSeverity severity, const std::string& message)
{
    if (!WillOutputMessage(severity))
    {
        return;
    }

    platform::FilePuts(message.c_str(), stderr);
    platform::FilePuts("\n", stderr);
    if (flush_after_write_)
    {
        platform::FileFlush(stderr);
    }
}

LoggingTargetDebugView::LoggingTargetDebugView()
{
    use_indent_ = false;
}

void LoggingTargetDebugView::LogMessage(LoggingSeverity severity, const std::string& message)
{
#if defined(WIN32)
    if (!WillOutputMessage(severity))
    {
        return;
    }

    OutputDebugStringA(message.c_str());
#endif
}

void LoggingTargetFile::SetBoolExtendedOption(LoggingExtendedOption option, bool value)
{
    switch (option)
    {
        case kOption_FileCreateNew:
            create_new_ = value;
            break;
        case kOption_FileLeaveOpen:
            leave_open_ = value;
            break;
        default:
            break;
    }
}

void LoggingTargetFile::SetStringExtendedOption(LoggingExtendedOption option, std::string value)
{
    if (option == kOption_FileName)
    {
        bool succeeded = true;
        if (log_stream_.is_open() && value != log_file_name_)
        {
            CloseFile();
        }

        if (value != log_file_name_ || create_new_)
        {
            log_file_name_ = value;
            succeeded      = succeeded && OpenFile();
        }
        enabled_ = succeeded;
    }
}

bool LoggingTargetFile::OpenFile()
{
    bool success = false;

    const std::lock_guard<std::mutex> lock(file_mut_);

    // Erase any previous contents
    std::ofstream::openmode open_mode = std::ofstream::out;
    if (!create_new_)
    {
        open_mode |= std::ofstream::app;
    }
    else
    {
        open_mode |= std::ofstream::trunc;
    }

    log_stream_.open(log_file_name_, open_mode);
    if (log_stream_.is_open())
    {
        if (!leave_open_)
        {
            CloseFile();
        }
        success = true;
    }
    else
    {
        GFXRECON_LOG_FATAL("Failed opening log file %s with returned result %d", log_file_name_.c_str(), errno);
    }

    return success;
}

void LoggingTargetFile::CloseFile()
{
    const std::lock_guard<std::mutex> lock(file_mut_);
    if (log_stream_.is_open())
    {
        log_stream_.close();
    }
}

void LoggingTargetFile::LogMessage(LoggingSeverity severity, const std::string& message)
{
    if (!WillOutputMessage(severity))
    {
        return;
    }

    if (!leave_open_)
    {
        if (!OpenFile())
        {
            GFXRECON_LOG_ERROR_ONCE("Failed to open log file %s", log_file_name_.c_str());
            return;
        }
    }

    {
        const std::lock_guard<std::mutex> lock(file_mut_);
        log_stream_ << message.c_str() << std::endl;

        if (flush_after_write_)
        {
            log_stream_.flush();
        }
    }

    if (!leave_open_)
    {
        CloseFile();
    }
}

GFXRECON_END_NAMESPACE(logging)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
