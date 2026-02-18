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
cd VulkanTests
git checkout %TEST_COMMIT% || exit /b
git submodule update --init --recursive
git describe --tags --always
cd ..
