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

#include "set_environment_app.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(set_environment)

static void SetEnvironmentVariable(const char* name, const char* value)
{
#if defined(__linux__) || defined(__APPLE__)
    setenv(name, value, 1);
#elif defined(_WIN32)
    ::SetEnvironmentVariableA(name, value);
#else
#error "Unsupported platform"
#endif
}

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    // Set environment variables for the test before the instance is created.
    SetEnvironmentVariable("GFXRECON_CAPTURE_ENVIRONMENT", "TEST_NAME_1,TEST_NAME_2");
    SetEnvironmentVariable("TEST_NAME_1", "TEST_VALUE_1");
    SetEnvironmentVariable("TEST_NAME_2", "TEST_VALUE_2");

    TestAppBase::configure_instance_builder(instance_builder, test_config);
}

bool App::frame(const int frame_num)
{
    return false;
}

GFXRECON_END_NAMESPACE(set_environment)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
