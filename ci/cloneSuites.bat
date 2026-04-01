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

if exist ci-gfxr-suites rmdir /s /q ci-gfxr-suites

if not defined TEST_SUITE_BRANCH (
    if exist test_suite.ref (
        set /p TEST_SUITE_BRANCH=<test_suite.ref
    ) else (
        set TEST_SUITE_BRANCH=master
    )
)

git init ci-gfxr-suites
cd ci-gfxr-suites
git remote add origin %TEST_SUITE_REPO%
git config --add remote.origin.fetch "+refs/pull/*/head:refs/remotes/origin/pr/*"

git config remote.origin.promisor true
git config remote.origin.partialclonefilter "blob:none"
git sparse-checkout init --cone
git sparse-checkout set %GFXRECON_TRACE_SUBDIR%

set /a clonetestloop=0
:fetch_suites
git fetch --depth 1 --filter=blob:none --verbose origin %TEST_SUITE_BRANCH%
if %errorlevel% equ 0 goto :fetch_suites_done
set /a clonetestloop+=1
if %clonetestloop% gtr 3 (
    echo tried to fetch %TEST_SUITE_REPO% too many times, giving up
    exit 1
)
waitfor forever /t 60 2>nul
goto :fetch_suites
:fetch_suites_done

git checkout FETCH_HEAD || exit /b
git describe --tags --always
dir
cd ..
