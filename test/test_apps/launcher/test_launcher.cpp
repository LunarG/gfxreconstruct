/*
** Copyright (c) 2025-2026 LunarG, Inc.
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

// The app headers and the app list. CMake generates both from test/test_apps/TestAppList.cmake.
#include "test_app_includes.h"
#include "test_app_list.h"

#include <algorithm>

#include <util/logging.h>
#include <util/strings.h>
#include <util/argument_parser.h>

#include <tools/tool_settings.h>
#include <tools/tool_command_line.h>

#if defined(__ANDROID__)
#include <util/android/activity.h>
#include <util/android/intent.h>
#endif

const char kOptions[]   = "-h|--help";
const char kArguments[] = "--wsi";

// The names that the launcher accepts, one per app in this build. screenshot-frame-boundaries is a
// CUSTOM entry in the list: it runs under one name per frame boundary mechanism, so its names are
// written here by hand.
#define GFXRECON_TEST_APP_NAME(ident, name) name,
// clang-format off
static const char* kAppNames[] = {
    GFXRECON_TEST_APP_LIST(GFXRECON_TEST_APP_NAME)
    "screenshot-frame-boundary-command-buffer",
    "screenshot-frame-boundary-ext",
    "screenshot-frame-boundary-android",
};
// clang-format on
#undef GFXRECON_TEST_APP_NAME

void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n%s - A launcher for GFXReconstruct test apps.\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s\t[-h | --help]", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t\t\t\t[--wsi <platform>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t\t<test_name>\n");
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <test_name>\tName of the test app to launch.");
    GFXRECON_WRITE_CONSOLE("             \tOptions are: ");
    for (auto& app_name : kAppNames)
    {
        GFXRECON_WRITE_CONSOLE("             \t  %s", app_name);
    }
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  --wsi <platform>\tUse the specified wsi platform.");
    GFXRECON_WRITE_CONSOLE("                  \tAvailable platforms are: %s", GetWsiArgString().c_str());
}

std::unique_ptr<gfxrecon::test::TestAppBase>
CreateTestApp(std::unique_ptr<gfxrecon::application::Application> application,
#if defined(__ANDROID__)
              struct android_app* android_app,
#endif
              const std::string& app_name)
{
    // One test per app in this build, from the generated list. A name that matches none leaves
    // app empty, and the caller reports it.
    std::unique_ptr<gfxrecon::test::TestAppBase> app;
#define GFXRECON_TEST_APP_CREATE(ident, name)                     \
    if (app_name == name)                                         \
    {                                                             \
        app = std::make_unique<gfxrecon::test_app::ident::App>(); \
    }
    GFXRECON_TEST_APP_LIST(GFXRECON_TEST_APP_CREATE)
#undef GFXRECON_TEST_APP_CREATE

    // screenshot-frame-boundaries takes the boundary mechanism as a constructor argument, so its
    // three names are matched by hand.
    using ScreenshotApp = gfxrecon::test_app::screenshot_frame_boundaries::App;
    if (app_name == "screenshot-frame-boundary-command-buffer")
    {
        app = std::make_unique<ScreenshotApp>(ScreenshotApp::Boundary::kCommandBufferLabel);
    }
    else if (app_name == "screenshot-frame-boundary-ext")
    {
        app = std::make_unique<ScreenshotApp>(ScreenshotApp::Boundary::kFrameBoundaryEXT);
    }
    else if (app_name == "screenshot-frame-boundary-android")
    {
        app = std::make_unique<ScreenshotApp>(ScreenshotApp::Boundary::kFrameBoundaryANDROID);
    }
    if (app == nullptr)
    {
        return nullptr;
    }

#if defined(__ANDROID__)
    app->set_android_app(android_app);
#endif // __ANDROID__

    app->SetApplication(std::move(application));

    return app;
}

int inner_main(
#if defined(__ANDROID__)
    struct android_app* android_app,
#endif
    int         argc,
    const char* argv[])
{
    gfxrecon::util::Log::Init();

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

    if (CheckOptionPrintUsage(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        return 0;
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
    {
        PrintUsage(argv[0]);
        gfxrecon::util::Log::Release();
        return -1;
    }

    const auto& positional_arguments = arg_parser.GetPositionalArguments();
    const auto& app_name             = positional_arguments[0];

#ifdef __ANDROID__
    auto application = std::make_unique<gfxrecon::application::Application>(
        kApplicationName, nullptr, VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, android_app);
#else
    // Select WSI context based on CLI
    std::string wsi_extension = GetFirstWsiExtensionName(GetWsiPlatform(arg_parser));
    auto application = std::make_unique<gfxrecon::application::Application>(app_name, nullptr, wsi_extension, nullptr);
#endif

    std::unique_ptr<gfxrecon::test::TestAppBase> app = CreateTestApp(std::move(application),
#if defined(__ANDROID__)
                                                                     android_app,
#endif
                                                                     app_name);
    if (app == nullptr)
    {
        GFXRECON_LOG_ERROR("Failed to create test app with name: %s", app_name.c_str());
        PrintUsage(argv[0]);
        gfxrecon::util::Log::Release();
        return -1;
    }

    try
    {
        app->run(app_name);
        gfxrecon::util::Log::Release();
        return 0;
    }
    catch (const std::exception& e)
    {
        GFXRECON_LOG_ERROR(e.what());
        gfxrecon::util::Log::Release();
        return -1;
    }
}

#if defined(__ANDROID__)
void android_main(struct android_app* android_app)
{
    std::string args = gfxrecon::util::GetIntentExtra(android_app, "args");

    // Intent args to argc/argv
    auto arg_list = gfxrecon::util::strings::SplitString(args, ' ');

    int argc = static_cast<int>(arg_list.size() + 1);

    std::vector<const char*> argv;
    argv.reserve(argc);
    argv.push_back("test_launcher");
    for (auto& arg : arg_list)
    {
        argv.push_back(arg.c_str());
    };

    inner_main(android_app, argc, argv.data());

    gfxrecon::util::DestroyActivity(android_app);
    raise(SIGTERM);
}
#else
int main(int argc, char* argv[])
{
    exit(inner_main(argc, const_cast<const char**>(argv)));
}
#endif
