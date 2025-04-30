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

#include <multisample_depth_app.h>
#include <external_memory_fd_export_app.h>
#include <external_memory_fd_import_app.h>
#include <host_image_copy_app.h>
#include <pipeline_binaries_app.h>
#include <shader_objects_app.h>
#include <triangle_app.h>

#include <algorithm>

#include <util/logging.h>
#include <util/strings.h>
#include <util/argument_parser.h>

#if defined(__ANDROID__)
#include <util/android/activity.h>
#include <util/android/intent.h>
#endif

const char kHelpShortOption[] = "-h";
const char kHelpLongOption[]  = "--help";

const char kOptions[] = "-h|--help";

static const char* kAppNames[] = {
    "external-memory-fd-export",
    "external-memory-fd-import",
    "host-image-copy",
    "multisample-depth",
    "pipeline-binaries",
    "shader-objects",
    "triangle",
};

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
    GFXRECON_WRITE_CONSOLE("  %s [-h | --help] <test_name>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <test_name>\tName of the test app to launch.");
    GFXRECON_WRITE_CONSOLE("             \tOptions are: ");
    for (auto& app_name : kAppNames)
    {
        GFXRECON_WRITE_CONSOLE("             \t  %s", app_name);
    }
}

bool CheckOptionPrintUsage(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kHelpShortOption) || arg_parser.IsOptionSet(kHelpLongOption))
    {
        PrintUsage(exe_name);
        return true;
    }

    return false;
}

std::unique_ptr<gfxrecon::test::TestAppBase> CreateTestApp(
#if defined(__ANDROID__)
    struct android_app* android_app,
#endif
    const std::string& app_name)
{
    // Make sure the app name is within the options
    bool found = false;
    for (auto* name : kAppNames)
    {
        if (app_name == name)
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        return nullptr;
    }

    // Now instantiate the app
    std::unique_ptr<gfxrecon::test::TestAppBase> app;

    if (app_name == "triangle")
    {
        app = std::make_unique<gfxrecon::test_app::triangle::App>();
    }
    else if (app_name == "external-memory-fd-export")
    {
        app = std::make_unique<gfxrecon::test_app::external_memory_fd_export::App>();
    }
    else if (app_name == "external-memory-fd-import")
    {
        app = std::make_unique<gfxrecon::test_app::external_memory_fd_import::App>();
    }
    else if (app_name == "host-image-copy")
    {
        app = std::make_unique<gfxrecon::test_app::host_image_copy::App>();
    }
    else if (app_name == "multisample-depth")
    {
        app = std::make_unique<gfxrecon::test_app::multisample_depth::App>();
    }
    else if (app_name == "pipeline-binaries")
    {
        app = std::make_unique<gfxrecon::test_app::pipeline_binaries::App>();
    }
    else if (app_name == "shader-objects")
    {
        app = std::make_unique<gfxrecon::test_app::shader_objects::App>();
    }

#if defined(__ANDROID__)
    app->set_android_app(android_app);
#endif

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

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, "");

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

    std::unique_ptr<gfxrecon::test::TestAppBase> app = CreateTestApp(
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
int main(int argc, const char* argv[])
{
    exit(inner_main(argc, argv));
}
#endif
