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

# This script runs at the end of a successful gfxr/dev build.
#
# Its job is to publish the exact commit SHA that dev just tested.  Extended
# later reads this Git ref and tests/promotes that exact commit, instead of
# looking at the moving dev branch.
#
# The marker ref is updated with a normal, non-force Git push.  That is
# intentional: if a newer dev build has already moved the marker forward, an
# older build finishing late must not move it backward.
#
# set -euo pipefail makes the script stop on command failures, unset variables,
# and failed commands inside pipelines.
set -euo pipefail

# The script expects exactly one command-line argument: the commit SHA to publish.
if [[ $# -ne 1 ]]; then
    echo "usage: $0 <tested-commit-sha>" >&2
    exit 2
fi

tested_commit="$1"
marker_ref="refs/heads/ci/gfxr-dev-tested"
remote_tracking_ref="refs/remotes/origin/ci/gfxr-dev-tested"

# Only full commit SHAs are accepted.  This prevents branch names or other
# revspecs from accidentally being pushed to the marker ref.
if [[ ! "$tested_commit" =~ ^[0-9a-fA-F]{40}$ ]]; then
    echo "Invalid tested commit SHA: $tested_commit" >&2
    exit 2
fi

# Verify the SHA exists in this checkout before trying to publish it.
git cat-file -e "${tested_commit}^{commit}"

# If the marker already exists, fetch its current value so we can decide whether
# this build is allowed to update it.  git ls-remote exits 2 when the ref is not
# found; other failures, including auth and network failures, should stop here.
set +e
git ls-remote --exit-code --heads origin ci/gfxr-dev-tested >/dev/null
ls_remote_status=$?
set -e

if [[ $ls_remote_status -eq 0 ]]; then
    git fetch origin "+${marker_ref}:${remote_tracking_ref}"
    current_marker="$(git rev-parse "$remote_tracking_ref")"

    # Nothing to do if another run already recorded this exact commit.
    if [[ "$current_marker" == "$tested_commit" ]]; then
        echo "Dev tested marker already points to $tested_commit"
        exit 0
    fi

    # If the existing marker is newer than this build's commit, leave it alone.
    # This handles the case where an older Jenkins build finishes after a newer one.
    if git merge-base --is-ancestor "$tested_commit" "$current_marker"; then
        echo "A newer tested commit is already recorded: $current_marker"
        exit 0
    fi

    # If neither commit is an ancestor of the other, history diverged.  Do not
    # guess which one should win.
    if ! git merge-base --is-ancestor "$current_marker" "$tested_commit"; then
        echo "Refusing to update dev tested marker from divergent commit $current_marker to $tested_commit" >&2
        exit 1
    fi
elif [[ $ls_remote_status -ne 2 ]]; then
    echo "Unable to query dev tested marker ref" >&2
    exit "$ls_remote_status"
fi

# Publish the tested commit.  This is a non-force push, so GitHub also protects
# us from moving the marker backward if another job updates it at the same time.
git push origin "${tested_commit}:${marker_ref}"
