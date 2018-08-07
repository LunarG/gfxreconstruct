/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "application/win32_application.h"
#include "application/win32_window.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

Win32Application::Win32Application()
{

}

LRESULT WINAPI Win32Application::WindowProcVk(HWND window, unsigned int msg, WPARAM wp, LPARAM lp) {
    auto *const app = (Win32Application *)GetWindowLongPtr(window, GWLP_USERDATA);
    std::vector<format::Window*> windows_copy;
    switch (msg)
    {
        case WM_KEYUP:
        {
            switch (wp)
            {
                case VK_SPACE:
                    app->SetPaused(!app->GetPaused());
                    break;
                case VK_ESCAPE:
                    DestroyWindow(window);
                    PostQuitMessage(0);
                    break;
                default:
                    break;
            }
            return S_OK;
        }
        case WM_NCCREATE:
            // Changes made with SetWindowLongPtr will not take effect until SetWindowPos is called.
            SetWindowLongPtr(window, GWLP_USERDATA, (LONG_PTR)((CREATESTRUCT *)lp)->lpCreateParams);
            SetWindowPos(window, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
            return DefWindowProc(window, msg, wp, lp);
        case WM_CLOSE:
            windows_copy = app->windows;
            for (auto window : windows_copy)
            {
                window->Destroy();
            }
            // fall-thru
        case WM_DESTROY:
            PostQuitMessage(0);
            return S_OK;
        default:
            return DefWindowProc(window, msg, wp, lp);
    }
}

void Win32Application::ProcessEvents(bool wait_for_input)
{
    MSG msg = {};
    while (true)
    {
        bool found_message;
        if (wait_for_input)
        {
            found_message = (GetMessage(&msg, nullptr, 0, 0) > 0);
        }
        else
        {
            found_message = PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE);
        }

        if (found_message)
        {
            if (msg.message == WM_QUIT)
            {
                exit(0);  // Prevents crashing due to vulkan cmds being on different thread than WindowProcVk
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            break;
        }
    }
}

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)
