@REM Copyright (c) 2026 Valve Corporation
@REM Copyright (c) 2026 LunarG, Inc.
@REM
@REM Permission is hereby granted, free of charge, to any person obtaining a
@REM copy of this software and associated documentation files (the "Software"),
@REM to deal in the Software without restriction, including without limitation
@REM the rights to use, copy, modify, merge, publish, distribute, sublicense,
@REM and/or sell copies of the Software, and to permit persons to whom the
@REM Software is furnished to do so, subject to the following conditions:
@REM
@REM The above copyright notice and this permission notice shall be included in
@REM all copies or substantial portions of the Software.
@REM
@REM THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
@REM IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
@REM FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
@REM AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
@REM LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
@REM FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
@REM DEALINGS IN THE SOFTWARE.

cmake --version
python --version

rem Windows needs to explicitly exit on failure, as cmd.exe won't do so automatically
echo creating Python virtual environment in %WORKSPACE%\python-venv...
python -m venv "%WORKSPACE%\python-venv"
"%WORKSPACE%\python-venv\Scripts\python" -m pip install --no-cache-dir -r VulkanTests\requirements.txt > "%WORKSPACE%\python-venv.txt" 2>&1 || exit /b

"%WORKSPACE%\python-venv\Scripts\python" VulkanTests\gfxrecontest.py --compiler vs2022 --build-mode %BUILD_MODE% --bits %BITS% %WINDOWS_TEST_ARGS% --suite "ci-gfxr-suites\%GFXRECON_TRACE_SUBDIR%\%TEST_SUITE%" --trace-dir "%GFXRECON_TRACE_DIR%" --result-dir "%RESULTS_DIR%"
