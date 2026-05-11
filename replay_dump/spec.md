# API Dump Replay Regression Test Script Spec

## 1. Overview

Build a Python command-line script in `replay_dump/` that replays gfxreconstruct captures and records Vulkan API calls through `VK_LAYER_LUNARG_api_dump`.

The script supports two modes:

1. Generate mode: replay one capture and write a JSON API dump.
2. Compare mode: replay one capture, write a JSON API dump, and compare it against an existing JSON dump.

The script exists to create known-good replay dumps and detect regressions in Vulkan API call output.

Success criteria:

- The script runs gfxreconstruct replay against a specified capture.
- The script writes a required JSON dump output file.
- The replay executable path comes from an environment variable.
- The script compares JSON dumps when a comparison file is provided.
- The script prints a diff when JSON comparison fails.
- The script exits non-zero on invalid input, replay failure, dump failure, invalid JSON, or comparison failure.

## 2. Scope

### In Scope

- Python script under `replay_dump/`.
- One capture per script invocation.
- Generate mode.
- Compare mode.
- JSON API dump output.
- JSON parsing and structural comparison.
- Human-readable diff output for comparison failures.
- Clear exit codes for test automation.

### Out of Scope

- CI integration.
- Batch processing multiple captures.
- Automatic known-good dump updates.
- Dump normalization for nondeterministic values.
- Installing Vulkan SDK, gfxreconstruct, or Vulkan layers.
- GPU, driver, or ICD matrix testing.

## 3. Definitions

| Term | Definition |
| --- | --- |
| Capture | A gfxreconstruct capture file used as replay input. |
| Replay tool | The gfxreconstruct replay executable. |
| API dump | JSON output generated from Vulkan API calls during replay. |
| Generated dump | The JSON API dump produced by the current run. |
| Reference dump | Existing known-good JSON dump used for comparison. |
| Generate mode | Mode that only creates a generated dump. |
| Compare mode | Mode that creates a generated dump and compares it to a reference dump. |
| Regression | Any structural JSON difference between generated dump and reference dump. |
| JSON compare | Parse both dump files as JSON and compare parsed values, not raw bytes. |

## 4. Requirements

### Functional Requirements

#### Script Location

The script MUST live under:

```text
replay_dump/
```

The initial script filename MUST be:

```text
replay_dump/replay_dump.py
```

#### CLI Inputs

The script MUST expose this CLI:

```text
python3 replay_dump/replay_dump.py CAPTURE_PATH --output OUTPUT_JSON_PATH [--compare REFERENCE_JSON_PATH]
```

The script MUST require:

- `CAPTURE_PATH`
- `--output OUTPUT_JSON_PATH`

The script MUST accept:

- `--compare REFERENCE_JSON_PATH`

If `--compare` is omitted, the script MUST run in generate mode.

If `--compare` is provided, the script MUST run in compare mode.

#### Replay Tool Environment Variable

The script MUST read the replay executable path from:

```text
GFXRECON_REPLAY
```

The script MUST fail before replay if `GFXRECON_REPLAY` is unset, empty, missing, or non-executable.

#### Replay Execution

The script MUST execute the replay tool using Python subprocess APIs without shell invocation.

The script MUST pass the capture path to the replay executable.

The script MUST enable:

```text
VK_LAYER_LUNARG_api_dump
```

The implementation MUST configure `VK_LAYER_LUNARG_api_dump` so the dump is written as JSON to `--output`.

The implementation MUST verify the exact supported api dump layer settings from the installed Vulkan SDK/API dump layer behavior while implementing.

The implementation MUST verify the replay executable argument format against the gfxreconstruct replay tool while implementing.

Replay stdout and stderr MUST be captured or forwarded in a way that failure output remains visible to the caller.

#### Dump Output

The generated dump MUST be JSON.

The script MUST create or overwrite the output file.

After replay succeeds, the script MUST verify:

- output file exists
- output file is non-empty
- output file parses as valid JSON

If any of those checks fail, the script MUST exit with dump failure.

#### JSON Comparison

Compare mode MUST parse both generated and reference dumps as JSON.

Comparison MUST be performed on parsed JSON values.

Object key ordering MUST NOT affect comparison.

Array ordering MUST affect comparison.

Numeric, string, boolean, null, object, and array values MUST follow Python JSON value equality semantics.

If parsed JSON values are equal, the script MUST exit successfully.

If parsed JSON values differ, the script MUST print a human-readable diff and exit with comparison failure.

The diff MUST identify changed JSON paths.

The diff MUST include enough context to determine:

- missing keys
- extra keys
- changed scalar values
- changed array lengths
- changed array elements

#### Exit Codes

| Exit Code | Meaning |
| --- | --- |
| `0` | Success. Replay completed and comparison passed if requested. |
| `1` | Replay failed. |
| `2` | Invalid arguments or invalid environment configuration. |
| `3` | Dump generation or JSON parsing failed. |
| `4` | JSON comparison failed. |

## 5. Data Model

### CLI Arguments

| Field | Type | Required | Description |
| --- | --- | --- | --- |
| `capture_path` | path | yes | gfxreconstruct capture input. |
| `output_path` | path | yes | generated JSON dump path. |
| `compare_path` | path | no | reference JSON dump path. |

### Parsed Dump

The script MUST treat dump contents as generic JSON.

Allowed root JSON types:

- object
- array

The script MUST reject scalar root values.

## 6. System Behavior

### Generate Mode

1. Parse CLI arguments.
2. Validate capture file.
3. Validate output parent directory.
4. Validate `GFXRECON_REPLAY`.
5. Configure replay environment for JSON api dump output.
6. Run replay.
7. If replay fails, exit `1`.
8. Validate generated dump exists and is non-empty.
9. Parse generated dump as JSON.
10. Exit `0`.

### Compare Mode

1. Parse CLI arguments.
2. Validate capture file.
3. Validate output parent directory.
4. Validate reference dump exists and is readable.
5. Parse reference dump as JSON before replay.
6. Validate `GFXRECON_REPLAY`.
7. Configure replay environment for JSON api dump output.
8. Run replay.
9. If replay fails, exit `1`.
10. Validate generated dump exists and is non-empty.
11. Parse generated dump as JSON.
12. Compare parsed generated JSON to parsed reference JSON.
13. If equal, print comparison success and exit `0`.
14. If different, print JSON diff and exit `4`.

## 7. Edge Cases

The script MUST fail with exit code `2` when:

- required CLI arguments are missing
- capture path does not exist
- capture path is not a file
- output parent directory does not exist
- output parent directory is not writable
- `GFXRECON_REPLAY` is unset or empty
- `GFXRECON_REPLAY` does not exist
- `GFXRECON_REPLAY` is not executable
- compare path does not exist
- compare path is not readable

The script MUST fail with exit code `3` when:

- generated dump is missing
- generated dump is empty
- generated dump is invalid JSON
- reference dump is invalid JSON
- either parsed dump has a scalar JSON root

The script MUST fail with exit code `4` when:

- generated JSON and reference JSON differ

## 8. Interfaces

### Generate Known-Good Dump

```text
GFXRECON_REPLAY=/path/to/gfxrecon-replay \
python3 replay_dump/replay_dump.py capture.gfxr --output known_good.json
```

### Compare Against Known-Good Dump

```text
GFXRECON_REPLAY=/path/to/gfxrecon-replay \
python3 replay_dump/replay_dump.py capture.gfxr --output current.json --compare known_good.json
```

## 9. Validation

### Unit Tests

Tests MUST cover:

- generate-mode argument parsing
- compare-mode argument parsing
- missing environment variable
- invalid replay executable
- invalid capture path
- invalid output parent directory
- invalid comparison path
- invalid generated JSON
- invalid reference JSON
- equal JSON objects with different key order
- different scalar values
- missing object keys
- extra object keys
- different array lengths
- different array element values

### Integration Tests

Manual integration validation MUST cover:

- generating a JSON dump from a real gfxreconstruct capture
- comparing a newly generated dump against a known-good dump
- modifying the reference dump and confirming comparison failure with diff output

## 10. Open Questions

None for the initial implementation.

## Ambiguities Resolved

- Script location is `replay_dump/`.
- No CI integration is required now.
- Dump normalization is deferred.
- Compare mode requires a diff.
- Dump format is JSON.
- Comparison is parsed JSON comparison, not byte comparison.
- API dump layer configuration and replay argument details are implementation tasks, not unresolved spec questions.

## Assumptions Made

- The initial script name is `replay_dump/replay_dump.py`.
- JSON object key order is insignificant.
- JSON array order is significant.
- JSON scalar root dumps are invalid for this use case.
