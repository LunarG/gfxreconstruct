#!/usr/bin/env bash
# This script runs at the start of gfxr-extended.
#
# It reads the commit SHA that the latest successful gfxr/dev build published
# to the ci/gfxr-dev-tested Git marker ref.  It then compares that commit to
# main and writes small result files for the Jenkinsfile to read.
#
# Output files:
# - extended-tested-commit.txt: the exact commit extended should test
# - extended-main-commit.txt: the current origin/main commit
# - extended-should-run.txt: "true" when extended should test/promote, otherwise
#   "false" when main is already at the tested commit
#
# set -euo pipefail makes the script stop on command failures, unset variables,
# and failed commands inside pipelines.
set -euo pipefail

# Jenkins passes an output directory as the first argument.  If it does not, use
# ci-metadata by default.
output_dir="${1:-ci-metadata}"
marker_ref="refs/heads/ci/gfxr-dev-tested"
remote_marker_ref="refs/remotes/origin/ci/gfxr-dev-tested"
remote_main_ref="refs/remotes/origin/main"

mkdir -p "$output_dir"

# Fetch both refs into explicit remote-tracking refs so the rest of the script
# compares stable local names.
git fetch origin \
    "+main:${remote_main_ref}" \
    "+${marker_ref}:${remote_marker_ref}"

tested_commit="$(git rev-parse "$remote_marker_ref")"
main_commit="$(git rev-parse "$remote_main_ref")"

# The marker must resolve to a full SHA.  If it does not, fail before running
# any expensive extended tests.
if [[ ! "$tested_commit" =~ ^[0-9a-fA-F]{40}$ ]]; then
    echo "Invalid tested commit SHA from $marker_ref: $tested_commit" >&2
    exit 1
fi

# Write the selected values for Jenkins to read with readFile().
printf '%s\n' "$tested_commit" > "${output_dir}/extended-tested-commit.txt"
printf '%s\n' "$main_commit" > "${output_dir}/extended-main-commit.txt"

# If main already points at the tested commit, there is nothing to promote.
if [[ "$main_commit" == "$tested_commit" ]]; then
    printf '%s\n' 'false' > "${output_dir}/extended-should-run.txt"
    echo "origin/main already points to $tested_commit; skipping extended tests."
    exit 0
fi

# Promotion is only safe if main can be fast-forwarded to the tested commit.
# If main is not an ancestor, fail before running extended.
if ! git merge-base --is-ancestor "$main_commit" "$tested_commit"; then
    echo "Refusing to test/promote $tested_commit: origin/main $main_commit is not an ancestor." >&2
    exit 1
fi

# Extended should run, and promotion may later fast-forward main to this commit.
printf '%s\n' 'true' > "${output_dir}/extended-should-run.txt"
echo "Selected extended candidate $tested_commit"
