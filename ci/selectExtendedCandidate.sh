#!/usr/bin/env bash
set -euo pipefail

output_dir="${1:-ci-metadata}"
marker_ref="refs/heads/ci/gfxr-dev-tested"
remote_marker_ref="refs/remotes/origin/ci/gfxr-dev-tested"
remote_main_ref="refs/remotes/origin/main"

mkdir -p "$output_dir"

git fetch origin \
    "+main:${remote_main_ref}" \
    "+${marker_ref}:${remote_marker_ref}"

tested_commit="$(git rev-parse "$remote_marker_ref")"
main_commit="$(git rev-parse "$remote_main_ref")"

if [[ ! "$tested_commit" =~ ^[0-9a-fA-F]{40}$ ]]; then
    echo "Invalid tested commit SHA from $marker_ref: $tested_commit" >&2
    exit 1
fi

printf '%s\n' "$tested_commit" > "${output_dir}/extended-tested-commit.txt"
printf '%s\n' "$main_commit" > "${output_dir}/extended-main-commit.txt"

if [[ "$main_commit" == "$tested_commit" ]]; then
    printf '%s\n' 'false' > "${output_dir}/extended-should-run.txt"
    echo "origin/main already points to $tested_commit; skipping extended tests."
    exit 0
fi

if ! git merge-base --is-ancestor "$main_commit" "$tested_commit"; then
    echo "Refusing to test/promote $tested_commit: origin/main $main_commit is not an ancestor." >&2
    exit 1
fi

printf '%s\n' 'true' > "${output_dir}/extended-should-run.txt"
echo "Selected extended candidate $tested_commit"
