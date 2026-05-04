# Copyright (c) 2026 Valve Corporation
# Copyright (c) 2026 LunarG, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.

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

if [ -z "${TEST_BRANCH:-}" ]; then
  if [ -f "test.ref" ]; then
    IFS= read -r TEST_BRANCH < test.ref
  else
    TEST_BRANCH="master"
  fi
  export TEST_BRANCH
fi

git clone --verbose $TEST_REPO VulkanTests
git -C VulkanTests config --add remote.origin.fetch "+refs/pull/*/head:refs/remotes/origin/pr/*"
git -C VulkanTests fetch origin
git -C VulkanTests checkout $TEST_BRANCH
git -C VulkanTests submodule update --init --recursive
git -C VulkanTests describe --tags --always

cmake --version
python3 --version

python3 -m venv $WORKSPACE/python-venv
$WORKSPACE/python-venv/bin/python3 -m pip install --no-cache-dir -r VulkanTests/requirements.txt > $WORKSPACE/python-venv.txt 2>&1

$WORKSPACE/python-venv/bin/python3 VulkanTests/gfxrecontest.py --build-mode ${BUILD_MODE} --bits ${BITS} $LINUX_TEST_ARGS --suite "ci-gfxr-suites/$GFXRECON_TRACE_SUBDIR/$TEST_SUITE" --trace-dir "$GFXRECON_TRACE_DIR" --result-dir "$RESULTS_DIR"
