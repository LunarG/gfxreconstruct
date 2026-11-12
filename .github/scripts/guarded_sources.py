#!/usr/bin/env python3
"""List sources whose preprocessor conditionals reference the given macros.

Usage: guarded_sources.py <macro-alternation> [--headers]

Prints path regexes for every .cpp file (or, with --headers, a single
alternation of every .h file) under framework/, tools/ and layer/ that
contains a preprocessor conditional naming one of the macros, e.g.:

    guarded_sources.py 'WIN32|_WIN32|D3D12_SUPPORT'

The output is meant for run-clang-tidy.py: the .cpp regexes as its source
filter arguments and the header alternation as its -header-filter value.
CI uses this to run clang-tidy on Windows over just the code that the
Linux clang-tidy job never sees.
"""

import re
import subprocess
import sys


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__.splitlines()[2])
    # Keep '\n' as-is on Windows: a '\r\n' separator would leave a stray
    # '\r' in the regexes after shell word splitting.
    sys.stdout.reconfigure(newline='\n')
    macros = sys.argv[1]
    pattern = rf'#\s*(if|ifdef|ifndef|elif).*\b({macros})\b'
    result = subprocess.run(
        ['git', 'grep', '-lE', pattern, '--',
         'framework', 'tools', 'layer', ':!framework/generated'],
        capture_output=True,
        text=True)
    # git grep exits 1 on "no matches", which is not an error here.
    if result.returncode > 1:
        sys.stderr.write(result.stderr)
        sys.exit(result.returncode)
    files = result.stdout.split()

    def path_regex(path):
        # Match both separators so the regexes also work against the paths
        # in a Windows compile database.
        return re.escape(path).replace('/', r'[/\\]')

    if '--headers' in sys.argv[2:]:
        headers = [path_regex(f) for f in files if f.endswith('.h')]
        print('|'.join(headers) or '^$')
    else:
        print('\n'.join(path_regex(f) for f in files if f.endswith('.cpp')))


if __name__ == '__main__':
    main()
