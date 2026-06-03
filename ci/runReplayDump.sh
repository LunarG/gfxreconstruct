#!/usr/bin/env bash

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

set -e

export GFXRECON_REPLAY="$(find "$(pwd)/build" -name gfxrecon-replay -type f -executable | head -n 1)"
echo "GFXRECON_REPLAY=${GFXRECON_REPLAY}"

"${WORKSPACE}/python-venv/bin/python3" replay_dump/replay_dump.py \
    --trace-dir "${GFXRECON_TRACE_DIR}" \
    --suite-dir ci-gfxr-suites \
    --suite "${REPLAY_DUMP_SUITE}" \
    --output-dir "${RESULTS_DIR}/replay-dump" \
    --headless
