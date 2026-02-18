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
