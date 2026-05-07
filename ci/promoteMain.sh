#!/usr/bin/env bash
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
