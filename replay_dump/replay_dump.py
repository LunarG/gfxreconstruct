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
from dataclasses import dataclass
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
EXIT_SUITE_FAILED = 4

API_DUMP_LAYER = "VK_LAYER_LUNARG_api_dump"
API_DUMP_MANIFEST = "VkLayer_api_dump.json"
REPLAY_ENV_VAR = "GFXRECON_REPLAY"
LOADER_LAYER_FILTER_ENV_VARS = (
    "VK_LOADER_LAYERS_DISABLE",
    "VK_LOADER_LAYERS_ENABLE",
)
MAX_DIFFS = 200
IGNORED_COMPARE_KEYS = {
    "address",
    "api_version",
    "apiVersion",
    "hinstance",
    "hwnd",
    "pipelineCacheUUID",
    "pipeline_cache_uuid",
    "ppData",
    "fd",
    "app_name",
}


class ReplayDumpError(Exception):
    """An error with a specific process exit code."""

    def __init__(self, message, exit_code):
        super().__init__(message)
        self.exit_code = exit_code


@dataclass
class SingleTestResult:
    name: str
    passed: bool
    output_path: Path
    failure_path: Path = None
    failure_kind: str = None
    message: str = None


def parse_args(argv):
    parser = argparse.ArgumentParser(
        description="Replay a gfxreconstruct capture and write a JSON Vulkan API dump."
    )
    parser.add_argument(
        "capture_path", nargs="?", help="gfxreconstruct capture input path"
    )
    parser.add_argument(
        "--output",
        dest="output_path",
        help="generated JSON API dump output path",
    )
    parser.add_argument(
        "--compare",
        dest="compare_path",
        help="reference JSON API dump path to compare against",
    )
    parser.add_argument(
        "--headless",
        action="store_true",
        help="run gfxrecon-replay without creating windows by passing --wsi headless --swapchain offscreen",
    )
    parser.add_argument(
        "--replay-arg",
        dest="replay_args",
        action="append",
        default=[],
        help="extra argument to pass to gfxrecon-replay; repeat for multiple arguments",
    )
    parser.add_argument(
        "--suite-dir",
        dest="suite_dir",
        help="root directory containing replay suite files and reference dumps",
    )
    parser.add_argument(
        "--trace-dir",
        dest="trace_dir",
        help="root directory containing trace captures",
    )
    parser.add_argument(
        "--suite",
        dest="suite_path",
        help="suite JSON path relative to suite-dir",
    )
    parser.add_argument(
        "--output-dir",
        dest="output_dir",
        help="directory for suite output artifacts",
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


def should_ignore_compare_key(key):
    return key in IGNORED_COMPARE_KEYS or key.startswith("pfn")


def clean_compare_json_node(value, path, depth, key):
    """Return False to remove this node from JSON comparison."""
    if key is not None and should_ignore_compare_key(key):
        return False

    if depth == 1 and isinstance(value, dict):
        if "header" in value or "annotation" in value:
            return False

    return True


def normalize_dump_for_compare(value, path="$", depth=0, key=None):
    if not clean_compare_json_node(value, path, depth, key):
        return False

    if isinstance(value, dict):
        for child_key in list(value.keys()):
            child_path = json_path(path, child_key)
            if not normalize_dump_for_compare(
                value[child_key], child_path, depth + 1, child_key
            ):
                del value[child_key]
        return True

    if isinstance(value, list):
        kept_items = []
        for index, item in enumerate(value):
            child_path = json_path(path, index)
            if normalize_dump_for_compare(item, child_path, depth + 1):
                kept_items.append(item)
        value[:] = kept_items
        return True

    return True


def warn(message):
    print("Warning: {}".format(message), file=sys.stderr)


def parse_sdk_version(name):
    try:
        return [int(component) for component in name.split(".")]
    except ValueError:
        return None


def get_default_sdk_root():
    if sys.platform.startswith("linux"):
        return Path("~/sdks").expanduser()
    if sys.platform == "darwin":
        return Path("~/VulkanSDK").expanduser()
    if sys.platform == "win32":
        return Path("C:/VulkanSDK")
    fail(
        "Unsupported platform for Vulkan SDK discovery: {}".format(sys.platform),
        EXIT_INVALID_INPUT,
    )


def discover_latest_sdk_root():
    sdk_root = get_default_sdk_root()
    print("Searching Vulkan SDK root: {}".format(sdk_root))
    if not sdk_root.exists():
        fail("Vulkan SDK root does not exist: {}".format(sdk_root), EXIT_INVALID_INPUT)
    if not sdk_root.is_dir():
        fail(
            "Vulkan SDK root is not a directory: {}".format(sdk_root),
            EXIT_INVALID_INPUT,
        )

    try:
        children = list(sdk_root.iterdir())
    except OSError as err:
        fail(
            "Failed to scan Vulkan SDK root {}: {}".format(sdk_root, err),
            EXIT_INVALID_INPUT,
        )

    candidates = []
    for child in children:
        try:
            if not child.is_dir():
                continue
        except OSError as err:
            warn("Ignoring SDK candidate {}: {}".format(child, err))
            continue

        version = parse_sdk_version(child.name)
        if version is None:
            warn("Ignoring SDK candidate with non-version name: {}".format(child))
            continue
        candidates.append((version, child))

    if not candidates:
        fail(
            "No valid Vulkan SDK directories found under {}".format(sdk_root),
            EXIT_INVALID_INPUT,
        )

    _version, selected = max(candidates, key=lambda candidate: candidate[0])
    try:
        selected = selected.resolve()
    except OSError as err:
        warn("Failed to resolve Vulkan SDK path {}: {}".format(selected, err))
        selected = selected.absolute()
    print("Selected Vulkan SDK root: {}".format(selected))
    return selected


def windows_sdk_search_dirs(sdk_root):
    bits = os.environ.get("BITS", "64")
    suffix = "32" if bits == "32" else ""
    expected = [
        sdk_root / "Bin{}".format(suffix),
        sdk_root / "Lib{}".format(suffix),
    ]
    optional = [sdk_root / "Tools{}".format(suffix)]

    search_dirs = []
    for path in expected:
        if path.is_dir():
            search_dirs.append(path)
        else:
            warn("Expected Vulkan SDK directory is absent: {}".format(path))
    for path in optional:
        if path.is_dir():
            search_dirs.append(path)
    search_dirs.append(sdk_root)
    return search_dirs


def linux_sdk_search_dirs(sdk_root):
    bits = os.environ.get("BITS", "64")
    if bits == "32":
        preferred = [sdk_root / "x86", sdk_root / "i386", sdk_root / "i686"]
    else:
        preferred = [sdk_root / "x86_64"]

    search_dirs = [path for path in preferred if path.is_dir()]
    search_dirs.append(sdk_root)
    return search_dirs


def get_sdk_search_dirs(sdk_root):
    if sys.platform == "win32":
        return windows_sdk_search_dirs(sdk_root)
    if sys.platform.startswith("linux"):
        return linux_sdk_search_dirs(sdk_root)
    return [sdk_root]


def find_file_in_dirs(search_dirs, filename):
    def onerror(err):
        warn("Skipping SDK directory during search: {}".format(err))

    for search_dir in search_dirs:
        if not search_dir.is_dir():
            warn("Skipping absent SDK search directory: {}".format(search_dir))
            continue
        matches = []
        for root, _dirs, files in os.walk(search_dir, onerror=onerror):
            if filename in files:
                matches.append(Path(root) / filename)
        if matches:
            selected = sorted(matches, key=lambda path: str(path))[0]
            try:
                return selected.resolve()
            except OSError as err:
                warn("Failed to resolve SDK component path {}: {}".format(selected, err))
                return selected.absolute()

    return None


def prepend_env_path(env, name, path):
    path_text = str(path)
    existing = env.get(name)
    if existing:
        env[name] = path_text + os.pathsep + existing
    else:
        env[name] = path_text


def configure_api_dump_layer_path(env):
    sdk_root = discover_latest_sdk_root()
    search_dirs = get_sdk_search_dirs(sdk_root)
    print(
        "Searching Vulkan SDK directories: {}".format(
            ", ".join(str(path) for path in search_dirs)
        )
    )

    manifest_path = find_file_in_dirs(search_dirs, API_DUMP_MANIFEST)
    if manifest_path is None:
        fail(
            "{} was not found under selected Vulkan SDK root {}".format(
                API_DUMP_MANIFEST, sdk_root
            ),
            EXIT_INVALID_INPUT,
        )

    print("Selected API dump layer manifest: {}".format(manifest_path))
    prepend_env_path(env, "VK_LAYER_PATH", manifest_path.parent)


def build_replay_environment(output_path):
    env = os.environ.copy()
    env["VK_INSTANCE_LAYERS"] = API_DUMP_LAYER
    configure_api_dump_layer_path(env)
    for name in LOADER_LAYER_FILTER_ENV_VARS:
        print("{}={}".format(name, env.get(name, "")))

    output_name = str(output_path)
    # Current LunarG settings names and older aliases are both set so the
    # script works across Vulkan SDK versions in common use.
    for prefix in ("VK_LUNARG_API_DUMP", "VK_API_DUMP", "VK_APIDUMP"):
        env["{}_OUTPUT_FORMAT".format(prefix)] = "json"
        env["{}_LOG_FILENAME".format(prefix)] = output_name
        env["{}_FLUSH".format(prefix)] = "true"
        env["{}_NO_ADDR".format(prefix)] = "true"

    env["VK_LUNARG_API_DUMP_FILE"] = "true"
    env["VK_API_DUMP_FILE"] = "true"
    env["VK_APIDUMP_FILE"] = "true"
    return env


def run_replay(replay_tool, replay_args, capture_path, output_path):
    if output_path.exists():
        try:
            output_path.unlink()
        except OSError as err:
            fail(
                "Failed to remove existing output dump {}: {}".format(output_path, err),
                EXIT_DUMP_FAILED,
            )

    command = [replay_tool] + replay_args + [str(capture_path)]
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


def format_context_label(value):
    if not isinstance(value, dict):
        return None

    name = value.get("name")
    type_name = value.get("type")
    return_type = value.get("returnType")

    if name is not None and return_type is not None and "args" in value:
        return "{} -> {}".format(name, return_type)
    if name is not None and type_name is not None:
        return "{}: {}".format(name, type_name)
    if name is not None:
        return str(name)
    if type_name is not None:
        return str(type_name)
    return None


def extend_context(context, reference, generated):
    label = format_context_label(reference)
    if label is None:
        label = format_context_label(generated)
    if label is None or (context and context[-1] == label):
        return context
    return context + [label]


def format_context(context):
    if not context:
        return ""
    return "; context: {}".format(" / ".join(context))


def diff_json(reference, generated, path="$", diffs=None, context=None):
    if diffs is None:
        diffs = []
    if context is None:
        context = []
    if len(diffs) >= MAX_DIFFS:
        return diffs

    context = extend_context(context, reference, generated)

    if isinstance(reference, dict) and isinstance(generated, dict):
        reference_keys = set(reference.keys())
        generated_keys = set(generated.keys())
        for key in sorted(reference_keys - generated_keys):
            diffs.append(
                "{}: missing key in generated dump; expected {}{}".format(
                    json_path(path, key),
                    format_json_value(reference[key]),
                    format_context(context),
                )
            )
            if len(diffs) >= MAX_DIFFS:
                return diffs
        for key in sorted(generated_keys - reference_keys):
            diffs.append(
                "{}: extra key in generated dump; value {}{}".format(
                    json_path(path, key),
                    format_json_value(generated[key]),
                    format_context(context),
                )
            )
            if len(diffs) >= MAX_DIFFS:
                return diffs
        for key in sorted(reference_keys & generated_keys):
            diff_json(
                reference[key],
                generated[key],
                json_path(path, key),
                diffs,
                context,
            )
            if len(diffs) >= MAX_DIFFS:
                return diffs
        return diffs

    if isinstance(reference, list) and isinstance(generated, list):
        if len(reference) != len(generated):
            diffs.append(
                "{}: array length changed from {} to {}{}".format(
                    path, len(reference), len(generated), format_context(context)
                )
            )
            if len(diffs) >= MAX_DIFFS:
                return diffs
        for index, (reference_item, generated_item) in enumerate(
            zip(reference, generated)
        ):
            diff_json(
                reference_item,
                generated_item,
                json_path(path, index),
                diffs,
                context,
            )
            if len(diffs) >= MAX_DIFFS:
                return diffs
        return diffs

    if reference != generated:
        diffs.append(
            "{}: value changed from {} to {}{}".format(
                path,
                format_json_value(reference),
                format_json_value(generated),
                format_context(context),
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


def get_compare_failure_text(reference, generated):
    diffs = diff_json(reference, generated)
    lines = ["Generated dump differs from reference dump", "Differences:"]
    for diff in diffs:
        lines.append("  - {}".format(diff))
    if len(diffs) >= MAX_DIFFS:
        lines.append("  - Diff truncated after {} differences.".format(MAX_DIFFS))
    return "\n".join(lines) + "\n"


def run_single_capture_test(
    name,
    capture_path,
    output_path,
    compare_path=None,
    replay_args=None,
    headless=False,
    replay_tool=None,
):
    if replay_args is None:
        replay_args = []
    replay_args = list(replay_args)
    if headless:
        replay_args = ["--wsi", "headless", "--swapchain", "offscreen"] + replay_args

    validate_capture_path(capture_path)
    validate_output_path(output_path)

    reference_dump = None
    if compare_path is not None:
        validate_compare_path(compare_path)
        reference_dump = load_json_dump(compare_path, "Reference")

    if replay_tool is None:
        replay_tool = validate_replay_tool()
    run_replay(replay_tool, replay_args, capture_path, output_path)
    generated_dump = load_json_dump(output_path, "Generated")

    if reference_dump is not None:
        normalize_dump_for_compare(reference_dump)
        normalize_dump_for_compare(generated_dump)
        compare_dumps(reference_dump, generated_dump)

    return SingleTestResult(name=name, passed=True, output_path=output_path)


def is_suite_mode(args):
    return any(
        value is not None
        for value in (args.suite_dir, args.trace_dir, args.suite_path, args.output_dir)
    )


def validate_single_mode_args(args):
    if args.capture_path is None:
        fail("CAPTURE_PATH is required in single-capture mode", EXIT_INVALID_INPUT)
    if args.output_path is None:
        fail("--output is required in single-capture mode", EXIT_INVALID_INPUT)


def validate_suite_mode_args(args):
    missing = []
    for option_name, value in (
        ("--suite-dir", args.suite_dir),
        ("--trace-dir", args.trace_dir),
        ("--suite", args.suite_path),
        ("--output-dir", args.output_dir),
    ):
        if value is None:
            missing.append(option_name)
    if missing:
        fail(
            "Suite mode requires {}".format(", ".join(missing)),
            EXIT_INVALID_INPUT,
        )
    if args.capture_path is not None:
        fail("CAPTURE_PATH is invalid in suite mode", EXIT_INVALID_INPUT)
    if args.output_path is not None:
        fail("--output is invalid in suite mode", EXIT_INVALID_INPUT)
    if args.compare_path is not None:
        fail("--compare is invalid in suite mode", EXIT_INVALID_INPUT)
    if args.replay_args:
        fail("--replay-arg is invalid in suite mode", EXIT_INVALID_INPUT)
    if Path(args.suite_path).is_absolute():
        fail("--suite must be relative to --suite-dir", EXIT_INVALID_INPUT)


def validate_suite_root_paths(suite_dir, trace_dir):
    for label, path in (("Suite directory", suite_dir), ("Trace directory", trace_dir)):
        if not path.exists():
            fail("{} does not exist: {}".format(label, path), EXIT_INVALID_INPUT)
        if not path.is_dir():
            fail("{} is not a directory: {}".format(label, path), EXIT_INVALID_INPUT)


def validate_suite_name(name, index):
    if not isinstance(name, str):
        fail(
            "Suite entry {} field 'name' must be a string".format(index),
            EXIT_INVALID_INPUT,
        )
    if name.strip() == "":
        fail(
            "Suite entry {} field 'name' must not be empty".format(index),
            EXIT_INVALID_INPUT,
        )
    if "/" in name or "\\" in name or name in (".", ".."):
        fail(
            "Suite entry {} field 'name' is not safe as one path segment: {}".format(
                index, name
            ),
            EXIT_INVALID_INPUT,
        )


def validate_suite_relative_path(entry, field, index):
    value = entry.get(field)
    if not isinstance(value, str):
        fail(
            "Suite entry {} field '{}' must be a string".format(index, field),
            EXIT_INVALID_INPUT,
        )
    if Path(value).is_absolute():
        fail(
            "Suite entry {} field '{}' must be relative: {}".format(
                index, field, value
            ),
            EXIT_INVALID_INPUT,
        )
    return value


def load_suite_file(suite_file_path):
    if not suite_file_path.exists():
        fail("Suite file does not exist: {}".format(suite_file_path), EXIT_INVALID_INPUT)
    if not suite_file_path.is_file():
        fail("Suite path is not a file: {}".format(suite_file_path), EXIT_INVALID_INPUT)
    try:
        with suite_file_path.open("r", encoding="utf-8") as suite_file:
            suite = json.load(suite_file)
    except OSError as err:
        fail(
            "Failed to read suite file {}: {}".format(suite_file_path, err),
            EXIT_INVALID_INPUT,
        )
    except json.JSONDecodeError as err:
        fail(
            "Suite file is invalid JSON at line {}, column {}: {}".format(
                err.lineno, err.colno, err.msg
            ),
            EXIT_INVALID_INPUT,
        )
    if not isinstance(suite, list):
        fail("Suite JSON root must be a list", EXIT_INVALID_INPUT)
    return suite


def validate_suite_entries(suite):
    names = set()
    validated = []
    for index, entry in enumerate(suite):
        if not isinstance(entry, dict):
            fail("Suite entry {} must be an object".format(index), EXIT_INVALID_INPUT)

        for field in ("name", "trace", "reference"):
            if field not in entry:
                fail(
                    "Suite entry {} is missing required field '{}'".format(index, field),
                    EXIT_INVALID_INPUT,
                )

        name = entry["name"]
        validate_suite_name(name, index)
        if name in names:
            fail(
                "Suite entry {} has duplicate name: {}".format(index, name),
                EXIT_INVALID_INPUT,
            )
        names.add(name)

        trace = validate_suite_relative_path(entry, "trace", index)
        reference = validate_suite_relative_path(entry, "reference", index)

        replay_args = entry.get("replay_args", [])
        if not isinstance(replay_args, list) or not all(
            isinstance(item, str) for item in replay_args
        ):
            fail(
                "Suite entry {} field 'replay_args' must be a list of strings".format(
                    index
                ),
                EXIT_INVALID_INPUT,
            )

        validated.append(
            {
                "name": name,
                "trace": trace,
                "reference": reference,
                "replay_args": list(replay_args),
            }
        )
    return validated


def make_artifact_log(path, message):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as log_file:
        log_file.write(message)
        if not message.endswith("\n"):
            log_file.write("\n")


def run_suite_entry(entry, suite_base_dir, trace_base_dir, output_dir, headless, replay_tool):
    test_dir = output_dir / entry["name"]
    output_path = test_dir / "output.json"
    capture_path = trace_base_dir / entry["trace"]
    compare_path = suite_base_dir / entry["reference"]
    try:
        test_dir.mkdir(parents=True, exist_ok=True)
        return run_single_capture_test(
            entry["name"],
            capture_path,
            output_path,
            compare_path=compare_path,
            replay_args=entry["replay_args"],
            headless=headless,
            replay_tool=replay_tool,
        )
    except ReplayDumpError as err:
        if err.exit_code == EXIT_COMPARE_FAILED:
            failure_path = test_dir / "diff.log"
            try:
                reference_dump = load_json_dump(compare_path, "Reference")
                generated_dump = load_json_dump(output_path, "Generated")
                normalize_dump_for_compare(reference_dump)
                normalize_dump_for_compare(generated_dump)
                message = get_compare_failure_text(reference_dump, generated_dump)
            except ReplayDumpError:
                message = "{}\n".format(err)
            failure_kind = "diff"
        else:
            failure_path = test_dir / "error.log"
            message = "{}\n".format(err)
            failure_kind = "error"
        make_artifact_log(failure_path, message)
        return SingleTestResult(
            name=entry["name"],
            passed=False,
            output_path=output_path,
            failure_path=failure_path,
            failure_kind=failure_kind,
            message=str(err),
        )


def run_suite(args):
    validate_suite_mode_args(args)

    suite_dir = Path(args.suite_dir)
    trace_dir = Path(args.trace_dir)
    output_dir = Path(args.output_dir)
    suite_base_dir = suite_dir
    trace_base_dir = trace_dir
    suite_file_path = suite_base_dir / args.suite_path

    validate_suite_root_paths(suite_dir, trace_dir)
    suite = validate_suite_entries(load_suite_file(suite_file_path))
    try:
        output_dir.mkdir(parents=True, exist_ok=True)
    except OSError as err:
        fail(
            "Failed to create suite output directory {}: {}".format(output_dir, err),
            EXIT_INVALID_INPUT,
        )
    replay_tool = validate_replay_tool()

    print("Suite: {}".format(suite_file_path))
    print("Tests: {}".format(len(suite)))

    results = []
    total = len(suite)
    for index, entry in enumerate(suite, start=1):
        print("[{}/{}] running {}".format(index, total, entry["name"]))
        result = run_suite_entry(
            entry,
            suite_base_dir,
            trace_base_dir,
            output_dir,
            args.headless,
            replay_tool,
        )
        results.append(result)
        if result.passed:
            print("PASS {}".format(result.output_path))
        else:
            print("FAIL {} {}".format(result.name, result.failure_path))

    failures = [result for result in results if not result.passed]
    passes = len(results) - len(failures)
    print("Summary: total={} pass={} fail={}".format(len(results), passes, len(failures)))
    for failure in failures:
        print("FAILED {} {}".format(failure.name, failure.failure_path))

    if failures:
        return EXIT_SUITE_FAILED
    return EXIT_SUCCESS


def run(argv):
    args = parse_args(argv)
    if is_suite_mode(args):
        return run_suite(args)

    validate_single_mode_args(args)
    run_single_capture_test(
        "single",
        Path(args.capture_path),
        Path(args.output_path),
        compare_path=Path(args.compare_path) if args.compare_path else None,
        replay_args=args.replay_args,
        headless=args.headless,
    )
    return EXIT_SUCCESS


def main(argv=None):
    try:
        return run(sys.argv[1:] if argv is None else argv)
    except ReplayDumpError as err:
        print("Error: {}".format(err), file=sys.stderr)
        return err.exit_code


if __name__ == "__main__":
    sys.exit(main())
