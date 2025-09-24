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

#ifndef GFXRECON_LOGGING_TARGETS_H
#define GFXRECON_LOGGING_TARGETS_H

#include "util/defines.h"
#include "util/logging_common.h"

#if defined(__ANDROID__)
#include <android/log.h>
#endif

#include <fstream>
#include <memory>
#include <mutex>
#include <string>
#include <variant>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(logging)

// Logging target types (also used as an array index)
enum LoggingTargetType
{
    kTarget_Invalid = -1,

    kTarget_StdOut,
    kTarget_StdErr,
    kTarget_FileOut,
    kTarget_DebugView,

    kTarget_Count
};

enum LoggingExtendedOption
{
    kOption_WriteErrors = 0,
    kOption_FileName,
    kOption_FileCreateNew,
    kOption_FileLeaveOpen,
};

// A base class for defining how to query a setting from a given source.
class LoggingTargetBase
{
  public:
    LoggingTargetBase()
    {
#if defined(__ANDROID__)
        // Default Android tag to just be generic "gfxrecon".
        // We can always override this later with tool name.
        android_message_tag_ = "gfxrecon";
#endif
    }

    ~LoggingTargetBase() {}

    void SetEnable(bool enable)
    {
        enabled_ = enable;
    }
    virtual void SetSeverity(LoggingSeverity severity)
    {
        min_severity_ = severity;
    }
    LoggingSeverity GetSeverity()
    {
        return min_severity_;
    }
    bool SupportsIndent()
    {
        return use_indent_;
    }
    void SetFlushAfterWrite(bool flush)
    {
        flush_after_write_ = flush;
    }

    // Some extended options are specific to a target type.
    virtual void SetBoolExtendedOption(LoggingExtendedOption option, bool value) {}
    virtual void SetStringExtendedOption(LoggingExtendedOption option, std::string value) {}

    virtual bool WillOutputMessage(LoggingSeverity severity)
    {
        return enabled_ && severity >= min_severity_;
    }

#if defined(__ANDROID__)
    void SetAndroidMessageTag(const std::string& tag)
    {
        android_message_tag_ = tag;
    }
#endif // __ANDROID__

    virtual void LogMessage(LoggingSeverity severity, const std::string& message) {}

  protected:
#if defined(__ANDROID__)
    android_LogPriority SeverityToAndroidLogPriority(LoggingSeverity severity);
#endif // __ANDROID__

    bool enabled_{ false };
    bool use_indent_{ true };
    bool flush_after_write_{ false };
#if defined(__ANDROID__)
    std::string android_message_tag_;
#endif
    LoggingSeverity min_severity_{ LoggingSeverity::kInfo };
};

class LoggingTargetStdout : public LoggingTargetBase
{
  public:
    LoggingTargetStdout() {}

    // We override this because we may want to send errors specifically to the
    // stderr output if that option is enabled.  Meaning we don't output them to
    // stdout.
    bool WillOutputMessage(LoggingSeverity severity) override;

    void LogMessage(LoggingSeverity severity, const std::string& message) override;

    // Some extended options are specific to a target type.
    void SetBoolExtendedOption(LoggingExtendedOption option, bool value) override;

  private:
    // This is set to false if errors are re-directed to stderr
    bool output_errors_{ true };
};

class LoggingTargetStderr : public LoggingTargetBase
{
  public:
    LoggingTargetStderr();

    // If this is enabled, we don't want to adjust this output beyond errors
    void SetSeverity(LoggingSeverity severity) override {}

    // We override this because we don't want Always level messages going out
    // on stderr.
    bool WillOutputMessage(LoggingSeverity severity) override;

    void LogMessage(LoggingSeverity severity, const std::string& message) override;
};

class LoggingTargetDebugView : public LoggingTargetBase
{
  public:
    LoggingTargetDebugView();

    void LogMessage(LoggingSeverity severity, const std::string& message) override;
};

class LoggingTargetFile : public LoggingTargetBase
{
  public:
    LoggingTargetFile() {}

    // Some extended options are specific to a target type.
    void SetBoolExtendedOption(LoggingExtendedOption option, bool value) override;
    void SetStringExtendedOption(LoggingExtendedOption option, std::string value) override;

    void LogMessage(LoggingSeverity severity, const std::string& message) override;

  private:
    bool OpenFile();
    void CloseFile();

    std::string              log_file_name_;
    std::ofstream            log_stream_;
    bool                     create_new_{ true };
    bool                     leave_open_{ false };
    inline static std::mutex file_mut_;
};

GFXRECON_END_NAMESPACE(logging)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_LOGGING_TARGETS_H
