cmake --version
python --version

python VulkanTests\gfxrecontest.py --compiler vs2022 --build-mode %BUILD_MODE% --bits %BITS% %WINDOWS_TEST_ARGS% --suite "ci-gfxr-suites\%GFXRECON_TRACE_SUBDIR%\%TEST_SUITE%" --trace-dir "%GFXRECON_TRACE_DIR%" --result-dir "%RESULTS_DIR%"
