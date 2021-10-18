/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "application/wsi_context.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

WsiContext::WsiContext(Application* application) : application_(application)
{
    assert(application_);
}

WsiContext ::~WsiContext()
{
    if (!windows_.empty())
    {
        GFXRECON_LOG_INFO("WsiContext is destroying windows that were not previously destroyed by their owner");

        for (auto window : windows_)
        {
            delete window;
        }
    }
}

bool WsiContext::RegisterWindow(decode::Window* window)
{
    assert(window != nullptr);

    if (std::find(windows_.begin(), windows_.end(), window) != windows_.end())
    {
        GFXRECON_LOG_INFO("A window was registered with the WsiContext more than once");
        return false;
    }

    windows_.push_back(window);

    return true;
}

bool WsiContext::UnregisterWindow(decode::Window* window)
{
    assert(window != nullptr);

    auto pos = std::find(windows_.begin(), windows_.end(), window);

    if (pos == windows_.end())
    {
        GFXRECON_LOG_INFO(
            "A remove window request was made for an window that was never registered with the WsiContext");
        return false;
    }

    windows_.erase(pos);

    return true;
}

void WsiContext::ProcessEvents(bool wait_for_input)
{
    GFXRECON_UNREFERENCED_PARAMETER(wait_for_input);
    // NOOP :
}

bool WsiContext::Valid() const
{
    return window_factory_ != nullptr;
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
