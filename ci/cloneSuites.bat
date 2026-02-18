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
cd ci-gfxr-suites
git checkout %TEST_SUITE_BRANCH% || exit /b
git submodule update --init --recursive
git describe --tags --always
cd ..
