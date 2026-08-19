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

#include "util/android/activity.h"

#include "util/logging.h"

#include <android_native_app_glue.h>

#include <chrono>
#include <cinttypes>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Maximum amount of time to wait for APP_CMD_DESTROY before giving up and continuing with shutdown.
constexpr std::chrono::milliseconds kDestroyTimeout{ 5000 };

void DestroyActivity(struct android_app* app)
{
    ANativeActivity_finish(app->activity);

    // Wait for APP_CMD_DESTROY. The wait is bounded because this runs during final shutdown: if the command never
    // arrives, shutdown must continue instead of hanging the process.
    const auto deadline = std::chrono::steady_clock::now() + kDestroyTimeout;

    while (app->destroyRequested == 0)
    {
        // ALooper_pollOnce() takes a whole number of milliseconds, so the remainder of the wait is truncated to that
        // resolution.  A sub-millisecond remainder truncates to zero and ends the wait, which is the intent.
        const std::chrono::milliseconds remaining =
            std::chrono::duration_cast<std::chrono::milliseconds>(deadline - std::chrono::steady_clock::now());

        if (remaining <= std::chrono::milliseconds::zero())
        {
            GFXRECON_LOG_WARNING("Timed out after %" PRId64 " ms waiting for APP_CMD_DESTROY; continuing with shutdown",
                                 static_cast<int64_t>(kDestroyTimeout.count()));
            break;
        }

        struct android_poll_source* source = nullptr;
        int                         events = 0;
        const int                   result =
            ALooper_pollOnce(static_cast<int>(remaining.count()), nullptr, &events, reinterpret_cast<void**>(&source));

        // An event dispatched to a registered looper callback, an ALooper_wake(), or a file descriptor with no
        // android_poll_source all mean APP_CMD_DESTROY has not been received yet, so keep polling until the deadline
        // expires.  Only ALOOPER_POLL_ERROR is unrecoverable.
        if (result == ALOOPER_POLL_ERROR)
        {
            GFXRECON_LOG_WARNING("ALooper_pollOnce() failed while waiting for APP_CMD_DESTROY; continuing with "
                                 "shutdown");
            break;
        }

        if (source != nullptr)
        {
            source->process(app, source);
        }
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
