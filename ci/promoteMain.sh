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

# This script runs after gfxr-extended tests pass.
#
# It promotes main to the exact commit that extended tested.  Promotion is done
# with a fast-forward-only merge from the tested SHA.  The script never merges
# the moving dev branch name and never force-pushes main.
#
# set -euo pipefail makes the script stop on command failures, unset variables,
# and failed commands inside pipelines.
set -euo pipefail

# The script expects exactly one command-line argument: the commit SHA to promote.
if [[ $# -ne 1 ]]; then
    echo "usage: $0 <tested-commit-sha>" >&2
    exit 2
fi

tested_commit="$1"

# Only allow a full SHA.  The goal is to promote the tested commit, not whatever
# a branch name happens to point at later.
if [[ ! "$tested_commit" =~ ^[0-9a-fA-F]{40}$ ]]; then
    echo "Invalid tested commit SHA: $tested_commit" >&2
    exit 2
fi

# Fetch main and the marker ref.  The marker fetch makes sure the tested commit
# object is available in this fresh promotion workspace.
git fetch origin \
    +main:refs/remotes/origin/main \
    +refs/heads/ci/gfxr-dev-tested:refs/remotes/origin/ci/gfxr-dev-tested

# Start from the current remote main, not from whatever branch Jenkins checked
# out before this script ran.
git checkout -B main origin/main

# Verify the tested commit exists locally.
git cat-file -e "${tested_commit}^{commit}"

current_main="$(git rev-parse HEAD)"

# If another run already promoted this commit, exit successfully.
if [[ "$current_main" == "$tested_commit" ]]; then
    echo "main already points to $tested_commit"
    exit 0
fi

# Require a fast-forward path from current main to the tested commit.
git merge-base --is-ancestor HEAD "$tested_commit"

# Move local main to the tested commit without creating a merge commit.
git merge --ff-only "$tested_commit"

# Push the fast-forwarded main branch.  This is a normal push, not force.
git push origin main
