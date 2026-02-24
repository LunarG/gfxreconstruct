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
git -C ci-gfxr-suites config --add remote.origin.fetch "+refs/pull/*/head:refs/remotes/origin/pr/*"
git -C ci-gfxr-suites fetch origin
git -C ci-gfxr-suites checkout $TEST_SUITE_BRANCH
git -C ci-gfxr-suites submodule update --init --recursive
git -C ci-gfxr-suites describe --tags --always

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
git -C VulkanTests config --add remote.origin.fetch "+refs/pull/*/head:refs/remotes/origin/pr/*"
git -C VulkanTests fetch origin
git -C VulkanTests checkout $TEST_COMMIT
git -C VulkanTests submodule update --init --recursive
git -C VulkanTests describe --tags --always

cmake --version
python3 --version

python3 -m venv $WORKSPACE/python-venv
$WORKSPACE/python-venv/bin/python3 -m pip install --no-cache-dir -r VulkanTests/requirements.txt > $WORKSPACE/python-venv.txt 2>&1

$WORKSPACE/python-venv/bin/python3 VulkanTests/gfxrecontest.py --build-mode ${BUILD_MODE} --bits ${BITS} $LINUX_TEST_ARGS --suite "ci-gfxr-suites/$GFXRECON_TRACE_SUBDIR/$TEST_SUITE" --trace-dir "$GFXRECON_TRACE_DIR" --result-dir "$RESULTS_DIR"
