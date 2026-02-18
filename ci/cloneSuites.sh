if [ -z "${TEST_SUITE_BRANCH:-}" ]; then
  if [ -f "test_suite.ref" ]; then
    IFS= read -r TEST_SUITE_BRANCH < test_suite.ref
  else
    TEST_SUITE_BRANCH="master"
  fi
  export TEST_SUITE_BRANCH
fi

git init ci-gfxr-suites
cd ci-gfxr-suites
git remote add origin $TEST_SUITE_REPO
git fetch --depth 1 --verbose origin $TEST_SUITE_BRANCH
git checkout FETCH_HEAD
git submodule update --init --recursive --depth 1
git describe --tags --always
cd ..
