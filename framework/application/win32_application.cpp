/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "application/win32_application.h"

#include "application/win32_window.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

Win32Application::Win32Application(const std::string& name, bool dpi_aware) : Application(name)
{
    if (dpi_aware)
    {
        SetProcessDPIAware();
    }
}

bool Win32Application::Initialize(decode::FileProcessor* file_processor)
{
    // No additional initialization is required for WIN32.
    SetFileProcessor(file_processor);
    return true;
}

LRESULT WINAPI Win32Application::WindowProc(HWND window, unsigned int msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
        case WM_KEYUP:
        {
            switch (wp)
            {
                case VK_SPACE:
                case 'P':
                {
                    auto app = reinterpret_cast<Win32Application*>(GetWindowLongPtr(window, GWLP_USERDATA));
                    app->SetPaused(!app->GetPaused());
                    break;
                }
                case VK_ESCAPE:
                    PostQuitMessage(0);
                    break;
                default:
                    return DefWindowProc(window, msg, wp, lp);
            }
            break;
        }
        case WM_KEYDOWN:
        {
            switch (wp)
            {
                // Using WM_KEYDOWN for repeat when key is held down.
                case VK_RIGHT:
                case 'N':
                {
                    auto app = reinterpret_cast<Win32Application*>(GetWindowLongPtr(window, GWLP_USERDATA));
                    if (app->GetPaused())
                    {
                        app->PlaySingleFrame();
                    }
                    break;
                }
                default:
                    return DefWindowProc(window, msg, wp, lp);
            }
            break;
        }
        case WM_SYSKEYUP:
        {
            switch (wp)
            {
                // Override the default F10 behavior for menu bar activation, which effectively suspends replay until
                // F10 is pushed a second time or the user interacts with the window.
                case VK_F10:
                    break;
                default:
                    return DefWindowProc(window, msg, wp, lp);
            }
            break;
        }
        case WM_CLOSE:
            PostQuitMessage(0);
            break;
        case WM_NCCREATE:
            // Changes made with SetWindowLongPtr will not take effect until SetWindowPos is called.
            SetWindowLongPtr(window, GWLP_USERDATA, (LONG_PTR)((CREATESTRUCT*)lp)->lpCreateParams);
            SetWindowPos(window, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
            // Intentional fall through.
        default:
            return DefWindowProc(window, msg, wp, lp);
    }

    return 0;
}

void Win32Application::ProcessEvents(bool wait_for_input)
{
    // Process all pending events.
    while (IsRunning())
    {
        MSG  msg           = {};
        bool found_message = false;

        if (wait_for_input)
        {
            found_message = (GetMessage(&msg, nullptr, 0, 0) > 0);

            // Stop waiting after the first event or this function never will exit.
            wait_for_input = false;
        }
        else
        {
            found_message = (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) != 0);
        }

        if (found_message)
        {
            if (msg.message == WM_QUIT)
            {
                StopRunning();
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            break;
        }
    }
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
