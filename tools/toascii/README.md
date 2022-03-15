### To ASCII

The `gfxrecon-toascii.exe` converts GFXReconstruct capture files to text.
The text output is formatted as JSON and written by default to a .txt file in the directory of the specified GFXReconstruct capture file. Use `--output` to override the default filename for the output.

```text
gfxrecon-toascii.exe - A tool to convert GFXReconstruct capture files to text.

Usage:
  gfxrecon-toascii.exe [-h | --help] [--version] [--output filename] <file>

Required arguments:
  <file>                Path to the GFXReconstruct capture file to be converted
                        to text.

Optional arguments:
  -h                    Print usage information and exit (same as --help).
  --version             Print version information and exit.
  --output filename     Write output to the provided filename.
```

