cmake --version
python3 --version

echo creating Python virtual environment in $WORKSPACE/python-venv...
python3 -m venv "$WORKSPACE/python-venv"
"$WORKSPACE/python-venv/bin/python3" -m pip install --no-cache-dir -r VulkanTests/requirements.txt > "$WORKSPACE/python-venv.txt" 2>&1

"$WORKSPACE/python-venv/bin/python3" VulkanTests/gfxrecontest.py --android-reuse-package --os AndroidTestOS --build-mode $BUILD_MODE $ANDROID_TEST_ARGS --suite "ci-gfxr-suites/$GFXRECON_TRACE_SUBDIR/$TEST_SUITE" --trace-dir "$GFXRECON_TRACE_DIR" --result-dir "$RESULTS_DIR"
