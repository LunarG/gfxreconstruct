cmake --version
python3 --version

python3 VulkanTests/gfxrecontest.py --build-mode ${BUILD_MODE} --bits ${BITS} $LINUX_TEST_ARGS --suite "ci-gfxr-suites/$GFXRECON_TRACE_SUBDIR/$TEST_SUITE" --trace-dir "$GFXRECON_TRACE_DIR" --result-dir "$RESULTS_DIR"
