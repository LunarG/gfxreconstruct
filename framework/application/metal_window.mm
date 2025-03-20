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

#include "application/metal_window.h"
#include "application/metal_context.h"
#include "application/application.h"

#include <Carbon/Carbon.h>
#include <QuartzCore/QuartzCore.h>

#if !__has_feature(objc_arc)
#error "Compile this with -fobjc-arc"
#endif

typedef void (^GFXReconKeyCallback)(gfxrecon::application::Application*);

@interface GFXReconWindowDelegate : NSObject <NSWindowDelegate>
- (void)windowWillClose:(NSNotification*)notification;
@end

@implementation GFXReconWindowDelegate
- (void)windowWillClose:(NSNotification*)notification
{
    GFXRECON_LOG_DEBUG_ONCE("User closed window");
    [NSApp terminate:self];
}
@end

@interface                                               GFXReconView : NSView
@property(nonatomic) gfxrecon::application::Application* app;
- (instancetype)initWithFrame:(NSRect)frame app:(gfxrecon::application::Application*)app;
@end

@implementation GFXReconView

- (instancetype)initWithFrame:(NSRect)frame app:(gfxrecon::application::Application*)app
{
    self = [super initWithFrame:frame];
    if (self)
    {
        _app = app;
    }
    return self;
}

- (void)keyDown:(NSEvent*)event
{
    if (!_app)
        return;
    switch ([event keyCode])
    {
        case kVK_Space:
        case kVK_ANSI_P:
            _app->SetPaused(!_app->GetPaused());
            break;

        case kVK_Escape:
            [NSApp terminate:self];
            break;

        case kVK_RightArrow:
        case kVK_ANSI_N:
            if (_app->GetPaused())
                _app->PlaySingleFrame();
            break;
    }
}

- (BOOL)acceptsFirstResponder
{
    return YES;
}

@end

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

static NSString* NSStringFromStdString(const std::string& std_string)
{
    return [[NSString alloc] initWithBytes:std_string.data() length:std_string.size() encoding:NSUTF8StringEncoding];
}

MetalWindow::MetalWindow(MetalContext* metal_context) :
    window_delegate_(nil), metal_context_(metal_context), window_(nil), layer_(nil), width_(0), height_(0)
{}

MetalWindow::~MetalWindow() = default;

bool MetalWindow::Create(const std::string& title,
                         const int32_t      xpos,
                         const int32_t      ypos,
                         const uint32_t     width,
                         const uint32_t     height,
                         bool               force_windowed)
{
    @autoreleasepool
    {
        window_delegate_               = [GFXReconWindowDelegate new];
        NSScreen*         screen       = [NSScreen mainScreen];
        NSRect            screen_frame = [screen convertRectToBacking:[screen frame]];
        NSWindowStyleMask style        = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable |
                                  NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable;
        if (width >= screen_frame.size.width && height >= screen_frame.size.height)
            style |= NSWindowStyleMaskFullScreen;

        auto frame_rect = NSMakeRect(xpos, ypos, width, height);
        window_ = [[NSWindow alloc] initWithContentRect:frame_rect
                                              styleMask:style
                                                backing:NSBackingStoreBuffered
                                                  defer:NO];
        [window_ setDelegate:window_delegate_];
        [window_ setCollectionBehavior:NSWindowCollectionBehaviorManaged | NSWindowCollectionBehaviorFullScreenPrimary | NSWindowCollectionBehaviorFullScreenAllowsTiling];
        layer_ = [CAMetalLayer layer];
        NSView* content = [[GFXReconView alloc] initWithFrame:frame_rect
                                                          app:metal_context_->GetApplication()];
        [window_ setContentView:content];
        [content setWantsLayer:YES];
        [content setLayer:layer_];

        // avoid highDPI settings, i.e. ignore [window_ backingScaleFactor]
        [layer_ setContentsScale:1.0];
        SetTitle(title);
        SetSize(width, height);
        SetPosition(xpos, ypos);
        SetForeground();
    }
    if (window_)
    {
        metal_context_->RegisterWindow(this);
        return true;
    }
    return false;
}

bool MetalWindow::Destroy()
{
    if (window_)
    {
        [static_cast<GFXReconView*>([window_ contentView]) setApp:nil];
        [window_ setDelegate:nil];
        [window_ close];
        metal_context_->UnregisterWindow(this);
    }
    layer_  = nil;
    window_ = nil;
    return true;
}

void MetalWindow::SetTitle(const std::string& title)
{
    @autoreleasepool
    {
        [window_ setTitle:NSStringFromStdString(title)];
    }
}

void MetalWindow::SetPosition(const int32_t x, const int32_t y)
{
    @autoreleasepool
    {
        if ([window_ styleMask] & NSWindowStyleMaskFullScreen)
            return;
        NSScreen* screen       = [window_ screen];
        NSRect    screen_frame = [screen convertRectToBacking:[window_ contentRectForFrameRect:[screen frame]]];
        NSRect    window_frame = [screen convertRectToBacking:[window_ contentRectForFrameRect:[window_ frame]]];
        window_frame.origin.x =
            std::max<CGFloat>(0, std::min<CGFloat>(x, screen_frame.size.width - window_frame.size.width));
        window_frame.origin.y =
            std::max<CGFloat>(0, std::min<CGFloat>(y, screen_frame.size.height - window_frame.size.height));
        [window_ setFrameOrigin:[window_ frameRectForContentRect:[screen convertRectFromBacking:window_frame]].origin];
    }
}

void MetalWindow::SetSize(const uint32_t width, const uint32_t height)
{
    if (width_ == width && height_ == height)
        return;
    @autoreleasepool
    {
        width_                         = width;
        height_                        = height;
        NSScreen*         screen       = [window_ screen];
        NSRect            screen_frame = [screen convertRectToBacking:[window_ contentRectForFrameRect:[screen frame]]];
        bool              fullscreen   = width >= screen_frame.size.width && height >= screen_frame.size.height;
        NSWindowStyleMask style        = [window_ styleMask];
        if (fullscreen)
        {
            if (!(style & NSWindowStyleMaskFullScreen))
                [window_ toggleFullScreen:nil];
        }
        else
        {
            if (style & NSWindowStyleMaskFullScreen)
                [window_ toggleFullScreen:nil];
            NSRect window_frame      = [screen convertRectToBacking:[window_ contentRectForFrameRect:[window_ frame]]];
            window_frame.size.width  = std::min<CGFloat>(screen_frame.size.width, width);
            window_frame.size.height = std::min<CGFloat>(screen_frame.size.height, height);
            window_frame.origin.x    = std::max<CGFloat>(
                0, std::min<CGFloat>(window_frame.origin.x, screen_frame.size.width - window_frame.size.width));
            window_frame.origin.y = std::max<CGFloat>(
                0, std::min<CGFloat>(window_frame.origin.y, screen_frame.size.height - window_frame.size.height));
            [window_ setFrame:[window_ frameRectForContentRect: window_frame] display:YES];

            NSSize content_size;
            content_size.width = window_frame.size.width;
            content_size.height = window_frame.size.height;
            [window_ setContentSize: content_size];
        }
    }
}

void MetalWindow::SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform)
{
    GFXRECON_UNREFERENCED_PARAMETER(pre_transform);
    SetSize(width, height);
}

void MetalWindow::SetVisibility(bool show)
{
    [window_ setIsVisible:show];
}

void MetalWindow::SetForeground()
{
    [window_ makeKeyAndOrderFront:nil];
}

bool MetalWindow::GetNativeHandle(HandleType type, void** handle)
{
    switch (type)
    {
        case Window::kMetalLayer:
            *handle = (__bridge void*)layer_;
            return true;
        default:
            return false;
    }
}

std::string MetalWindow::GetWsiExtension() const
{
    return VK_EXT_METAL_SURFACE_EXTENSION_NAME;
}

VkExtent2D MetalWindow::GetSize() const
{
    return { width_, height_ };
}

VkResult MetalWindow::CreateSurface(const graphics::VulkanInstanceTable* table,
                                    VkInstance                           instance,
                                    VkFlags                              flags,
                                    VkSurfaceKHR*                        pSurface)
{
    if (table)
    {
        VkMetalSurfaceCreateInfoEXT create_info = { VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT };
        create_info.pLayer                      = layer_;

        return table->CreateMetalSurfaceEXT(instance, &create_info, nullptr, pSurface);
    }

    return VK_ERROR_INITIALIZATION_FAILED;
}

void MetalWindow::DestroySurface(const graphics::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface)
{
    if (table)
        table->DestroySurfaceKHR(instance, surface, nullptr);
}

MetalWindowFactory::MetalWindowFactory(MetalContext* metal_context) : metal_context_(metal_context)
{
    assert(metal_context_);
}

decode::Window* MetalWindowFactory::Create(
    const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, bool force_windowed)
{
    assert(metal_context_);
    decode::Window* window      = new MetalWindow(metal_context_);
    Application*    application = metal_context_->GetApplication();
    window->Create(application->GetName(), x, y, width, height, force_windowed);
    return window;
}

void MetalWindowFactory::Destroy(decode::Window* window)
{
    if (window)
    {
        window->Destroy();
        delete window;
    }
}

VkBool32 MetalWindowFactory::GetPhysicalDevicePresentationSupport(const graphics::VulkanInstanceTable* table,
                                                                  VkPhysicalDevice                     physical_device,
                                                                  uint32_t queue_family_index)
{
    return true;
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
