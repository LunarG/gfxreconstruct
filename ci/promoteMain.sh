#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
    echo "usage: $0 <tested-commit-sha>" >&2
    exit 2
fi

tested_commit="$1"

if [[ ! "$tested_commit" =~ ^[0-9a-fA-F]{40}$ ]]; then
    echo "Invalid tested commit SHA: $tested_commit" >&2
    exit 2
fi

git fetch origin \
    +main:refs/remotes/origin/main \
    +refs/heads/ci/gfxr-dev-tested:refs/remotes/origin/ci/gfxr-dev-tested
git checkout -B main origin/main
git cat-file -e "${tested_commit}^{commit}"

current_main="$(git rev-parse HEAD)"
if [[ "$current_main" == "$tested_commit" ]]; then
    echo "main already points to $tested_commit"
    exit 0
fi

git merge-base --is-ancestor HEAD "$tested_commit"
git merge --ff-only "$tested_commit"
git push origin main
