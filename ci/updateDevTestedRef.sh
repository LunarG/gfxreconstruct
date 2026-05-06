#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
    echo "usage: $0 <tested-commit-sha>" >&2
    exit 2
fi

tested_commit="$1"
marker_ref="refs/heads/ci/gfxr-dev-tested"
remote_tracking_ref="refs/remotes/origin/ci/gfxr-dev-tested"

if [[ ! "$tested_commit" =~ ^[0-9a-fA-F]{40}$ ]]; then
    echo "Invalid tested commit SHA: $tested_commit" >&2
    exit 2
fi

git cat-file -e "${tested_commit}^{commit}"

if git ls-remote --exit-code --heads origin ci/gfxr-dev-tested >/dev/null 2>&1; then
    git fetch origin "+${marker_ref}:${remote_tracking_ref}"
    current_marker="$(git rev-parse "$remote_tracking_ref")"

    if [[ "$current_marker" == "$tested_commit" ]]; then
        echo "Dev tested marker already points to $tested_commit"
        exit 0
    fi

    if git merge-base --is-ancestor "$tested_commit" "$current_marker"; then
        echo "A newer tested commit is already recorded: $current_marker"
        exit 0
    fi

    if ! git merge-base --is-ancestor "$current_marker" "$tested_commit"; then
        echo "Refusing to update dev tested marker from divergent commit $current_marker to $tested_commit" >&2
        exit 1
    fi
fi

git push origin "${tested_commit}:${marker_ref}"
