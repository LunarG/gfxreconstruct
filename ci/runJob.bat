git submodule update --init --recursive
git describe --tags --always

if not defined TEST_SUITE_BRANCH (
    if exist test_suite.ref (
        set /p TEST_SUITE_BRANCH=<test_suite.ref
    ) else (
        set TEST_SUITE_BRANCH=master
    )
)

set /a clonetestloop=0
:clone_suites
git clone --verbose %TEST_SUITE_REPO% ci-gfxr-suites
if %errorlevel% equ 0 goto :clone_suites_done
if exist ci-gfxr-suites/ rmdir /s /q ci-gfxr-suites
set /a clonetestloop+=1
if %clonetestloop% gtr 3 ( 
    echo tried to clone %TEST_SUITE_REPO% too many times, giving up
    exit 1
)
waitfor forever /t 60 2>nul
goto :clone_suites
:clone_suites_done
git -C ci-gfxr-suites config --add remote.origin.fetch "+refs/pull/*/head:refs/remotes/origin/pr/*"
git -C ci-gfxr-suites fetch origin
git -C ci-gfxr-suites checkout %TEST_SUITE_BRANCH% || exit /b
git -C ci-gfxr-suites submodule update --init --recursive
git -C ci-gfxr-suites describe --tags --always

if not defined TEST_COMMIT (
    if exist test.ref (
        set /p TEST_COMMIT=<test.ref
    ) else (
        set TEST_COMMIT=master
    )
)

set /a clonetestloop=0
:clone_tests
git clone --verbose %TEST_REPO% VulkanTests
if %errorlevel% equ 0 goto :clone_tests_done
if exist VulkanTests/ rmdir /s /q VulkanTests
set /a clonetestloop+=1
if %clonetestloop% gtr 3 ( 
    echo tried to clone %TEST_REPO% too many times, giving up
    exit 1
)
waitfor forever /t 60 2>nul
goto :clone_tests
:clone_tests_done
git -C VulkanTests config --add remote.origin.fetch "+refs/pull/*/head:refs/remotes/origin/pr/*"
git -C VulkanTests fetch origin
git -C VulkanTests checkout %TEST_COMMIT% || exit /b
git -C VulkanTests submodule update --init --recursive
git -C VulkanTests describe --tags --always

cmake --version
python --version

python -m venv %WORKSPACE%\python-venv
%WORKSPACE%\python-venv\Scripts\python -m pip install --no-cache-dir -r VulkanTests\requirements.txt > %WORKSPACE%\python-venv.txt 2>&1 || exit /b

%WORKSPACE%\python-venv\Scripts\python VulkanTests\gfxrecontest.py --compiler vs2022 --build-mode %BUILD_MODE% --bits %BITS% %WINDOWS_TEST_ARGS% --suite "ci-gfxr-suites\%GFXRECON_TRACE_SUBDIR%\%TEST_SUITE%" --trace-dir "%GFXRECON_TRACE_DIR%" --result-dir "%RESULTS_DIR%"
