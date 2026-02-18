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
