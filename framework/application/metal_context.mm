/*
 ** Copyright (c) 2023 Codeweavers, Inc.
 ** Copyright (c) 2023 LunarG, Inc.
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

#include "application/metal_context.h"
#include "application/metal_window.h"
#include "application/application.h"
#include <AppKit/AppKit.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

MetalContext::MetalContext(Application* application) : WsiContext(application)
{
    if (!NSApp)
    {
        @autoreleasepool
        {
            [NSApplication sharedApplication];
            [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
            [NSApp finishLaunching];
            [NSApp activateIgnoringOtherApps:YES];
        }
    }
    window_factory_ = std::make_unique<MetalWindowFactory>(this);
}

void MetalContext::ProcessEvents(bool wait_for_input)
{
    assert(application_);

    @autoreleasepool
    {
        while (true)
        {
            NSDate* timeout = wait_for_input ? [NSDate distantFuture] : nil;
            NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                                untilDate:timeout
                                                   inMode:NSDefaultRunLoopMode
                                                  dequeue:YES];
            if (!event)
                break;
            [NSApp sendEvent:event];
            wait_for_input = false;
        }
    }
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
