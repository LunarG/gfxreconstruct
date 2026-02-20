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

git config remote.origin.promisor true
git config remote.origin.partialclonefilter "blob:none"

set /a clonetestloop=0
:fetch_suites
git fetch --depth 1 --verbose origin %TEST_SUITE_BRANCH%
if %errorlevel% equ 0 goto :fetch_suites_done
set /a clonetestloop+=1
if %clonetestloop% gtr 3 (
    echo tried to fetch %TEST_SUITE_REPO% too many times, giving up
    exit 1
)
waitfor forever /t 60 2>nul
goto :fetch_suites
:fetch_suites_done

git sparse-checkout init --cone
git sparse-checkout set %GFXRECON_TRACE_SUBDIR%

git checkout FETCH_HEAD || exit /b
git submodule update --init --recursive --depth 1
git describe --tags --always
cd ..
