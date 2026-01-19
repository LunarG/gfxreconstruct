git submodule update --init --recursive
git describe --tags --always

if [ -z "${TEST_SUITE_BRANCH:-}" ]; then
  if [ -f "test_suite.ref" ]; then
    IFS= read -r TEST_SUITE_BRANCH < test_suite.ref
  else
    TEST_SUITE_BRANCH="master"
  fi
  export TEST_SUITE_BRANCH
fi

git clone --verbose $TEST_SUITE_REPO ci-gfxr-suites
cd ci-gfxr-suites
git checkout $TEST_SUITE_BRANCH
git submodule update --init --recursive
git describe --tags --always
cd ..

if [ -z "${TEST_COMMIT:-}" ]; then
  if [ -f "test.ref" ]; then
    IFS= read -r TEST_COMMIT < test.ref
  else
    TEST_COMMIT="master"
  fi
  export TEST_COMMIT
fi

git clone --verbose $TEST_REPO VulkanTests
cd VulkanTests
git checkout $TEST_COMMIT
git submodule update --init --recursive
git describe --tags --always
cd ..
cmake --version
python3 --version
python3 VulkanTests/gfxrecontest.py --os AndroidTestOS --build-mode $BUILD_MODE $ANDROID_TEST_ARGS --suite "ci-gfxr-suites/$GFXRECON_TRACE_SUBDIR/$TEST_SUITE" --trace-dir "$GFXRECON_TRACE_DIR" --result-dir "$RESULTS_DIR"