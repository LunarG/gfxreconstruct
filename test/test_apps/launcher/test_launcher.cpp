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

#include <acquired_image_app.h>
#include <host_image_copy_app.h>
#include <pipeline_binaries_app.h>
#include <shader_objects_app.h>
#include <sparse_resources_app.h>
#include <triangle_app.h>
#include <triangle_extra_device_app.h>

#ifdef __linux__
#include <external_memory_fd_export_app.h>
#include <external_memory_fd_import_app.h>
#include <wait_for_present_app.h>
#endif

#include <algorithm>

#include <util/logging.h>
#include <util/strings.h>
#include <util/argument_parser.h>

#include <tools/tool_settings.h>

#if defined(__ANDROID__)
#include <ahb_app.h>

#include <util/android/activity.h>
#include <util/android/intent.h>
#endif

const char kOptions[] = "-h|--help";
const char kArguments[] = "--wsi";

static const char* kAppNames[] = { "acquired-image",
                                   "host-image-copy",
                                   "multisample-depth",
                                   "pipeline-binaries",
                                   "shader-objects",
                                   "sparse-resources",
                                   "triangle",
                                   "triangle-extra-device",
#ifdef __linux__
                                   "external-memory-fd-export",
                                   "external-memory-fd-import",
                                   "wait-for-present",
#endif
#ifdef __ANDROID__
                                   "ahb"
#endif
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

    if (app_name == "acquired-image")
    {
        app = std::make_unique<gfxrecon::test_app::acquired_image::App>();
    }
    else if (app_name == "triangle")
    {
        app = std::make_unique<gfxrecon::test_app::triangle::App>();
    }
    else if (app_name == "triangle-extra-device")
    {
        app = std::make_unique<gfxrecon::test_app::triangle_extra_device::App>();
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
    else if (app_name == "sparse-resources")
    {
        app = std::make_unique<gfxrecon::test_app::sparse_resources::App>();
    }
#ifdef __linux__
    else if (app_name == "external-memory-fd-export")
    {
        app = std::make_unique<gfxrecon::test_app::external_memory_fd_export::App>();
    }
    else if (app_name == "external-memory-fd-import")
    {
        app = std::make_unique<gfxrecon::test_app::external_memory_fd_import::App>();
    }
    else if (app_name == "wait-for-present")
    {
        app = std::make_unique<gfxrecon::test_app::wait_for_present::App>();
    }
#endif // __linux__
#if defined(__ANDROID__)
    else if (app_name == "ahb")
    {
        app = std::make_unique<gfxrecon::test_app::ahb::App>();
    }

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
    auto application = std::make_unique<gfxrecon::application::Application>(kApplicationName, nullptr);
    application->InitializeWsiContext(VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, android_app);
#else
    // Select WSI context based on CLI
    std::string wsi_extension = GetFirstWsiExtensionName(GetWsiPlatform(arg_parser));
    auto        application   = std::make_unique<gfxrecon::application::Application>(app_name, wsi_extension, nullptr);
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
