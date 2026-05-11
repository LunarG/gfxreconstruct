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

import io
import os
from pathlib import Path
import stat
import tempfile
import unittest
from unittest import mock

from replay_dump import replay_dump


class ReplayDumpTest(unittest.TestCase):
    def make_file(self, directory, name, contents="data"):
        path = Path(directory) / name
        path.write_text(contents, encoding="utf-8")
        return path

    def make_fake_replay(self, directory, dump_contents='{"calls": []}'):
        path = Path(directory) / "fake_replay.py"
        path.write_text(
            "\n".join(
                [
                    "#!/usr/bin/env python3",
                    "import os",
                    "import sys",
                    "assert len(sys.argv) == 2",
                    "assert os.environ['VK_INSTANCE_LAYERS'] == 'VK_LAYER_LUNARG_api_dump'",
                    "output = os.environ['VK_LUNARG_API_DUMP_LOG_FILENAME']",
                    "assert os.environ['VK_LUNARG_API_DUMP_OUTPUT_FORMAT'] == 'json'",
                    "assert os.environ['VK_LUNARG_API_DUMP_FILE'] == 'true'",
                    "with open(output, 'w', encoding='utf-8') as f:",
                    "    f.write({!r})".format(dump_contents),
                ]
            ),
            encoding="utf-8",
        )
        path.chmod(path.stat().st_mode | stat.S_IXUSR)
        return path

    def run_main(self, argv, env):
        stdout = io.StringIO()
        stderr = io.StringIO()
        with mock.patch.dict(os.environ, env, clear=True):
            with mock.patch("sys.stdout", stdout), mock.patch("sys.stderr", stderr):
                exit_code = replay_dump.main(argv)
        return exit_code, stdout.getvalue(), stderr.getvalue()

    def test_generate_mode_argument_parsing(self):
        args = replay_dump.parse_args(["capture.gfxr", "--output", "dump.json"])
        self.assertEqual("capture.gfxr", args.capture_path)
        self.assertEqual("dump.json", args.output_path)
        self.assertIsNone(args.compare_path)

    def test_compare_mode_argument_parsing(self):
        args = replay_dump.parse_args(
            ["capture.gfxr", "--output", "dump.json", "--compare", "ref.json"]
        )
        self.assertEqual("capture.gfxr", args.capture_path)
        self.assertEqual("dump.json", args.output_path)
        self.assertEqual("ref.json", args.compare_path)

    def test_missing_required_arguments_exit_with_invalid_input(self):
        with mock.patch("sys.stderr", io.StringIO()):
            with self.assertRaises(SystemExit) as context:
                replay_dump.parse_args(["capture.gfxr"])
        self.assertEqual(replay_dump.EXIT_INVALID_INPUT, context.exception.code)

    def test_missing_environment_variable(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            capture = self.make_file(temp_dir, "capture.gfxr")
            output = Path(temp_dir) / "dump.json"
            exit_code, _, stderr = self.run_main([str(capture), "--output", str(output)], {})
        self.assertEqual(replay_dump.EXIT_INVALID_INPUT, exit_code)
        self.assertIn("GFXRECON_REPLAY", stderr)

    def test_invalid_replay_executable(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            capture = self.make_file(temp_dir, "capture.gfxr")
            output = Path(temp_dir) / "dump.json"
            replay = self.make_file(temp_dir, "not_executable")
            exit_code, _, stderr = self.run_main(
                [str(capture), "--output", str(output)],
                {"GFXRECON_REPLAY": str(replay)},
            )
        self.assertEqual(replay_dump.EXIT_INVALID_INPUT, exit_code)
        self.assertIn("not executable", stderr)

    def test_invalid_capture_path(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            replay = self.make_fake_replay(temp_dir)
            output = Path(temp_dir) / "dump.json"
            capture = Path(temp_dir) / "missing.gfxr"
            exit_code, _, stderr = self.run_main(
                [str(capture), "--output", str(output)],
                {"GFXRECON_REPLAY": str(replay)},
            )
        self.assertEqual(replay_dump.EXIT_INVALID_INPUT, exit_code)
        self.assertIn("Capture path does not exist", stderr)

    def test_invalid_output_parent_directory(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            replay = self.make_fake_replay(temp_dir)
            capture = self.make_file(temp_dir, "capture.gfxr")
            output = Path(temp_dir) / "missing" / "dump.json"
            exit_code, _, stderr = self.run_main(
                [str(capture), "--output", str(output)],
                {"GFXRECON_REPLAY": str(replay)},
            )
        self.assertEqual(replay_dump.EXIT_INVALID_INPUT, exit_code)
        self.assertIn("Output parent directory does not exist", stderr)

    def test_invalid_comparison_path(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            capture = self.make_file(temp_dir, "capture.gfxr")
            output = Path(temp_dir) / "dump.json"
            reference = Path(temp_dir) / "missing.json"
            exit_code, _, stderr = self.run_main(
                [str(capture), "--output", str(output), "--compare", str(reference)],
                {},
            )
        self.assertEqual(replay_dump.EXIT_INVALID_INPUT, exit_code)
        self.assertIn("Reference dump path does not exist", stderr)

    def test_invalid_generated_json(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            replay = self.make_fake_replay(temp_dir, "{")
            capture = self.make_file(temp_dir, "capture.gfxr")
            output = Path(temp_dir) / "dump.json"
            exit_code, _, stderr = self.run_main(
                [str(capture), "--output", str(output)],
                {"GFXRECON_REPLAY": str(replay)},
            )
        self.assertEqual(replay_dump.EXIT_DUMP_FAILED, exit_code)
        self.assertIn("Generated dump is invalid JSON", stderr)

    def test_invalid_reference_json(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            capture = self.make_file(temp_dir, "capture.gfxr")
            output = Path(temp_dir) / "dump.json"
            reference = self.make_file(temp_dir, "reference.json", "{")
            exit_code, _, stderr = self.run_main(
                [str(capture), "--output", str(output), "--compare", str(reference)],
                {},
            )
        self.assertEqual(replay_dump.EXIT_DUMP_FAILED, exit_code)
        self.assertIn("Reference dump is invalid JSON", stderr)

    def test_equal_json_objects_with_different_key_order(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            replay = self.make_fake_replay(temp_dir, '{"b": 2, "a": 1}')
            capture = self.make_file(temp_dir, "capture.gfxr")
            output = Path(temp_dir) / "dump.json"
            reference = self.make_file(temp_dir, "reference.json", '{"a": 1, "b": 2}')
            exit_code, stdout, _ = self.run_main(
                [str(capture), "--output", str(output), "--compare", str(reference)],
                {"GFXRECON_REPLAY": str(replay)},
            )
        self.assertEqual(replay_dump.EXIT_SUCCESS, exit_code)
        self.assertIn("JSON comparison passed", stdout)

    def test_different_scalar_values(self):
        diffs = replay_dump.diff_json({"a": 1}, {"a": 2})
        self.assertEqual(['$.a: value changed from 1 to 2'], diffs)

    def test_missing_object_keys(self):
        diffs = replay_dump.diff_json({"a": 1}, {})
        self.assertEqual(['$.a: missing key in generated dump; expected 1'], diffs)

    def test_extra_object_keys(self):
        diffs = replay_dump.diff_json({}, {"a": 1})
        self.assertEqual(['$.a: extra key in generated dump; value 1'], diffs)

    def test_different_array_lengths(self):
        diffs = replay_dump.diff_json([1, 2], [1])
        self.assertEqual(["$: array length changed from 2 to 1"], diffs)

    def test_different_array_element_values(self):
        diffs = replay_dump.diff_json([{"a": 1}], [{"a": 2}])
        self.assertEqual(['$[0].a: value changed from 1 to 2'], diffs)


if __name__ == "__main__":
    unittest.main()
