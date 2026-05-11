#!/usr/bin/env python3
#
# Copyright (c) 2026 Advanced Micro Devices, Inc. All rights reserved
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.

"""Replay a gfxreconstruct capture and dump Vulkan API calls as JSON."""

import argparse
import json
import os
from pathlib import Path
import subprocess
import sys


EXIT_SUCCESS = 0
EXIT_REPLAY_FAILED = 1
EXIT_INVALID_INPUT = 2
EXIT_DUMP_FAILED = 3
EXIT_COMPARE_FAILED = 4

API_DUMP_LAYER = "VK_LAYER_LUNARG_api_dump"
REPLAY_ENV_VAR = "GFXRECON_REPLAY"
MAX_DIFFS = 200


class ReplayDumpError(Exception):
    """An error with a specific process exit code."""

    def __init__(self, message, exit_code):
        super().__init__(message)
        self.exit_code = exit_code


def parse_args(argv):
    parser = argparse.ArgumentParser(
        description="Replay a gfxreconstruct capture and write a JSON Vulkan API dump."
    )
    parser.add_argument("capture_path", help="gfxreconstruct capture input path")
    parser.add_argument(
        "--output",
        dest="output_path",
        required=True,
        help="generated JSON API dump output path",
    )
    parser.add_argument(
        "--compare",
        dest="compare_path",
        help="reference JSON API dump path to compare against",
    )
    return parser.parse_args(argv)


def fail(message, exit_code):
    raise ReplayDumpError(message, exit_code)


def validate_capture_path(capture_path):
    if not capture_path.exists():
        fail("Capture path does not exist: {}".format(capture_path), EXIT_INVALID_INPUT)
    if not capture_path.is_file():
        fail("Capture path is not a file: {}".format(capture_path), EXIT_INVALID_INPUT)


def validate_output_path(output_path):
    parent = output_path.parent
    if not parent.exists():
        fail(
            "Output parent directory does not exist: {}".format(parent),
            EXIT_INVALID_INPUT,
        )
    if not parent.is_dir():
        fail(
            "Output parent path is not a directory: {}".format(parent),
            EXIT_INVALID_INPUT,
        )
    if not os.access(parent, os.W_OK):
        fail(
            "Output parent directory is not writable: {}".format(parent),
            EXIT_INVALID_INPUT,
        )


def validate_compare_path(compare_path):
    if not compare_path.exists():
        fail(
            "Reference dump path does not exist: {}".format(compare_path),
            EXIT_INVALID_INPUT,
        )
    if not compare_path.is_file():
        fail(
            "Reference dump path is not a file: {}".format(compare_path),
            EXIT_INVALID_INPUT,
        )
    if not os.access(compare_path, os.R_OK):
        fail(
            "Reference dump path is not readable: {}".format(compare_path),
            EXIT_INVALID_INPUT,
        )


def validate_replay_tool():
    replay_tool = os.environ.get(REPLAY_ENV_VAR)
    if replay_tool is None or replay_tool.strip() == "":
        fail("{} is unset or empty".format(REPLAY_ENV_VAR), EXIT_INVALID_INPUT)

    replay_tool_path = Path(replay_tool)
    if not replay_tool_path.exists():
        fail(
            "{} does not exist: {}".format(REPLAY_ENV_VAR, replay_tool_path),
            EXIT_INVALID_INPUT,
        )
    if not replay_tool_path.is_file():
        fail(
            "{} is not a file: {}".format(REPLAY_ENV_VAR, replay_tool_path),
            EXIT_INVALID_INPUT,
        )
    if not os.access(replay_tool_path, os.X_OK):
        fail(
            "{} is not executable: {}".format(REPLAY_ENV_VAR, replay_tool_path),
            EXIT_INVALID_INPUT,
        )
    return replay_tool


def load_json_dump(path, label):
    if not path.exists():
        fail("{} dump does not exist: {}".format(label, path), EXIT_DUMP_FAILED)
    if not path.is_file():
        fail("{} dump path is not a file: {}".format(label, path), EXIT_DUMP_FAILED)
    if path.stat().st_size == 0:
        fail("{} dump is empty: {}".format(label, path), EXIT_DUMP_FAILED)

    try:
        with path.open("r", encoding="utf-8") as json_file:
            parsed = json.load(json_file)
    except OSError as err:
        fail(
            "Failed to read {} dump {}: {}".format(label, path, err),
            EXIT_DUMP_FAILED,
        )
    except json.JSONDecodeError as err:
        fail(
            "{} dump is invalid JSON at line {}, column {}: {}".format(
                label, err.lineno, err.colno, err.msg
            ),
            EXIT_DUMP_FAILED,
        )

    if not isinstance(parsed, (dict, list)):
        fail("{} dump has a scalar JSON root: {}".format(label, path), EXIT_DUMP_FAILED)
    return parsed


def build_replay_environment(output_path):
    env = os.environ.copy()
    env["VK_INSTANCE_LAYERS"] = API_DUMP_LAYER

    output_name = str(output_path)
    # Current LunarG settings names and older aliases are both set so the
    # script works across Vulkan SDK versions in common use.
    for prefix in ("VK_LUNARG_API_DUMP", "VK_API_DUMP", "VK_APIDUMP"):
        env["{}_OUTPUT_FORMAT".format(prefix)] = "json"
        env["{}_LOG_FILENAME".format(prefix)] = output_name
        env["{}_FLUSH".format(prefix)] = "true"

    env["VK_LUNARG_API_DUMP_FILE"] = "true"
    env["VK_API_DUMP_FILE"] = "true"
    env["VK_APIDUMP_FILE"] = "true"
    return env


def run_replay(replay_tool, capture_path, output_path):
    if output_path.exists():
        try:
            output_path.unlink()
        except OSError as err:
            fail(
                "Failed to remove existing output dump {}: {}".format(output_path, err),
                EXIT_DUMP_FAILED,
            )

    command = [replay_tool, str(capture_path)]
    print("Running: {}".format(" ".join(command)))
    result = subprocess.run(
        command,
        env=build_replay_environment(output_path),
        text=True,
        capture_output=True,
        shell=False,
    )

    if result.stdout:
        print(result.stdout, end="")
    if result.stderr:
        print(result.stderr, end="", file=sys.stderr)

    if result.returncode != 0:
        fail(
            "Replay failed with exit code {}".format(result.returncode),
            EXIT_REPLAY_FAILED,
        )


def format_path_component(key):
    if isinstance(key, int):
        return "[{}]".format(key)
    if key.isidentifier():
        return ".{}".format(key)
    return "[{}]".format(json.dumps(key))


def json_path(parent, key):
    return "{}{}".format(parent, format_path_component(key))


def format_json_value(value):
    return json.dumps(value, sort_keys=True)


def diff_json(reference, generated, path="$", diffs=None):
    if diffs is None:
        diffs = []
    if len(diffs) >= MAX_DIFFS:
        return diffs

    if isinstance(reference, dict) and isinstance(generated, dict):
        reference_keys = set(reference.keys())
        generated_keys = set(generated.keys())
        for key in sorted(reference_keys - generated_keys):
            diffs.append(
                "{}: missing key in generated dump; expected {}".format(
                    json_path(path, key), format_json_value(reference[key])
                )
            )
            if len(diffs) >= MAX_DIFFS:
                return diffs
        for key in sorted(generated_keys - reference_keys):
            diffs.append(
                "{}: extra key in generated dump; value {}".format(
                    json_path(path, key), format_json_value(generated[key])
                )
            )
            if len(diffs) >= MAX_DIFFS:
                return diffs
        for key in sorted(reference_keys & generated_keys):
            diff_json(reference[key], generated[key], json_path(path, key), diffs)
            if len(diffs) >= MAX_DIFFS:
                return diffs
        return diffs

    if isinstance(reference, list) and isinstance(generated, list):
        if len(reference) != len(generated):
            diffs.append(
                "{}: array length changed from {} to {}".format(
                    path, len(reference), len(generated)
                )
            )
            if len(diffs) >= MAX_DIFFS:
                return diffs
        for index, (reference_item, generated_item) in enumerate(
            zip(reference, generated)
        ):
            diff_json(reference_item, generated_item, json_path(path, index), diffs)
            if len(diffs) >= MAX_DIFFS:
                return diffs
        return diffs

    if reference != generated:
        diffs.append(
            "{}: value changed from {} to {}".format(
                path, format_json_value(reference), format_json_value(generated)
            )
        )
    return diffs


def compare_dumps(reference, generated):
    if reference == generated:
        print("JSON comparison passed.")
        return

    diffs = diff_json(reference, generated)
    print("JSON comparison failed. Differences:")
    for diff in diffs:
        print("  - {}".format(diff))
    if len(diffs) >= MAX_DIFFS:
        print("  - Diff truncated after {} differences.".format(MAX_DIFFS))
    fail("Generated dump differs from reference dump", EXIT_COMPARE_FAILED)


def run(argv):
    args = parse_args(argv)
    capture_path = Path(args.capture_path)
    output_path = Path(args.output_path)
    compare_path = Path(args.compare_path) if args.compare_path else None

    validate_capture_path(capture_path)
    validate_output_path(output_path)

    reference_dump = None
    if compare_path is not None:
        validate_compare_path(compare_path)
        reference_dump = load_json_dump(compare_path, "Reference")

    replay_tool = validate_replay_tool()
    run_replay(replay_tool, capture_path, output_path)
    generated_dump = load_json_dump(output_path, "Generated")

    if reference_dump is not None:
        compare_dumps(reference_dump, generated_dump)

    return EXIT_SUCCESS


def main(argv=None):
    try:
        return run(sys.argv[1:] if argv is None else argv)
    except ReplayDumpError as err:
        print("Error: {}".format(err), file=sys.stderr)
        return err.exit_code


if __name__ == "__main__":
    sys.exit(main())
