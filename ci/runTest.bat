cmake --version
python --version

rem Windows needs to explicitly exit on failure, as cmd.exe won't do so automatically
echo creating Python virtual environment in %WORKSPACE%\python-venv...
python -m venv "%WORKSPACE%\python-venv"
"%WORKSPACE%\python-venv\Scripts\python" -m pip install --no-cache-dir -r VulkanTests\requirements.txt > "%WORKSPACE%\python-venv.txt" 2>&1 || exit /b

"%WORKSPACE%\python-venv\Scripts\python" VulkanTests\gfxrecontest.py --compiler vs2022 --build-mode %BUILD_MODE% --bits %BITS% %WINDOWS_TEST_ARGS% --suite "ci-gfxr-suites\%GFXRECON_TRACE_SUBDIR%\%TEST_SUITE%" --trace-dir "%GFXRECON_TRACE_DIR%" --result-dir "%RESULTS_DIR%"
