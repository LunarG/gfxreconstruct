# Contributing to the GFXReconstruct Project

Guidelines for contributing to the GFXReconstruct project.

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2018-2021 LunarG, Inc.

## **Index**

1. [Introduction](#introduction)
1. [Repository Dependencies](#repository-dependencies)
1. [Submitting Changes](#submitting-changes)
    1. [Coding Conventions and Formatting](#coding-conventions-and-formatting)
    1. [Verifying Changes with the Build Script](#verifying-changes-with-the-build-script)
    1. [Python code style](#python-code-style)
    1. [Testing Your Changes](#testing-your-changes)
1. [Contributor License Agreement](#contributor-license-agreement-cla)
1. [License and Copyrights](#license-and-copyrights)
1. [GFXReconstruct PR Process](#gfxreconstruct-pr-process)
1. [Platform-specific ClangFormat Installation](#platform-specific-clangformat-installation)

## **Introduction**

Although the GFXReconstruct project is under active development, external
contributions are always welcome.  Open issues and available tasks can
can be found in the project
[issues list](https://github.com/LunarG/gfxreconstruct/issues).  When
working on changes that are not already in the issues list, please
consider creating a new issue to avoid duplication of effort, and
feel free to contact any of the project developers should you wish to
coordinate further.

Repository Issue labels:

- _Bug_:          These issues refer to invalid or broken functionality and
 are the highest priority.
- _Enhancement_:  These issues refer to tasks for extending or improving the
 GFXReconstruct software.

If you would like to work on an issue that is already assigned, please coordinate
with the current assignee.

## Repository Dependencies

As mentioned in the [build guide](./BUILD.md), submodules are updated as the
GFXReconstruct project is updated to support new Vulkan API releases.
If a submodule update like the one below pulls in a new version of the
Vulkan headers at `external/Vulkan-Headers` and your in-flight branch has
touched Python files related to code generation, you may need to run the
Python 3 code generator.  The minimum required Python version is 3.8.

```bash
git submodule update
```

To do that, `cd` to `framework/generated` and run:

```bash
python3 generate_vulkan.py 
```

## **Submitting Changes**

Changes to the GFXReconstruct project should be made on the `dev` branch, which
is periodically merged to the `master` branch for project releases.  Incoming
submissions should adhere to the following:

- Ensure that the issue has not already been addressed by searching the project's
GitHub Issues and Pull Requests.
- Use the existing GitHub fork and pull request process.
  This involves [forking the repository](https://help.github.com/articles/fork-a-repo/),
  creating a branch with your commits, and then [submitting a pull request](https://help.github.com/articles/using-pull-requests/).
- Implement and submit changes against the `dev` branch.
- Please read and adhere to the style and process [guidelines](#coding-conventions-and-formatting) documented below.

### **Coding Conventions and Formatting**

- Changes to the GFXReconstruct project's C++ code should conform to the coding
  style defined by the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- C++ Code formatting is managed with a custom ClangFormat configuration file.
  This is the `.clang-format` file found at the base of the repo tree.
  It is intended for use with **ClangFormat version 9.0.1**.
  - ClangFormat version 9.0.1 can be obtained by installing the LLVM 9.0.1
    package available from the [LLVM Download Page](https://releases.llvm.org/download.html),
    or [see below](#platform-specific-clangformat-installation) for
    platform-specific installation notes.
- C++ code formatting can be applied to pending changes with the `clang-format`
  or `git clang-format` commands.
  - A sample git workflow may look like:

```bash
# Make changes to the source.
$ git add -u .
$ git clang-format

# Check for changes applied by clang-format, and if so:
$ git add -u .

$ git commit
```

- **Commit Messages**
  - Limit the subject line to 50 characters -- this allows the information
    to display correctly in git/Github logs
  - Separate subject from body with a blank line
  - Wrap the body at 72 characters
  - Capitalize the subject line
  - Do not end the subject line with a period
  - Use the body to explain what and why vs. how
  - Use the imperative mode in the subject line; this just means to write it
      as a command (e.g. Fix the sprocket)

Strive for commits that implement a single or related set of functionality,
using as many commits as is necessary (more is better).
That said, please ensure that the repository compiles and passes tests without
error for each commit in your pull request.

**NOTE:** To be accepted into the repository, the pull request must
[pass all tests](#testing your changes) on all supported platforms
-- the automatic Github Travis and AppVeyor continuous integration features will
assist in enforcing this requirement.

### **Verifying Changes with the Build Script**

For desktop, the Python 3 `scripts\build.py` script can be used to verify changes
before they are committed.  By default, the script performs a pre-build step to
verify that the formatting of uncommitted changes adheres to the project's
ClangFormat style.

The build script also has an option to apply `clang-format` to project files
before build.  Run the script with the `-h` option for additional usage
information.
### **Python code style**

- Changes to the GFXReconstruct project's Python code should conform to the
  coding style defined by [PEP 8](https://www.python.org/dev/peps/pep-0008/)
  - Python code formatting may be automatically applied with
    [yapf](https://github.com/google/yapf), based on the rules specified in
    the repository's .style.yapf file, using the following command:

```bash
# Apply formatting to files in place.
$ yapf -i <files>

# Apply formatting to all python files in this path.
$ yapf -i -r <path>
```

### **Python code style**

- Changes to the GFXReconstruct project's Python code should conform to the
  coding style defined by [PEP 8](https://www.python.org/dev/peps/pep-0008/)
  - Python code formatting may be automatically applied with
    [yapf](https://github.com/google/yapf), based on the rules specified in
    the repository's .style.yapf file, using the following command:

```bash
# Apply formatting to files in place.
$ yapf -i <files>

# Apply formatting to all python files in this path.
$ yapf -i -r <path>
```

### **Testing Your Changes**

- Enable the VK_LAYER_LUNARG_gfxreconstruct layer for several Vulkan
  applications and record traces.
  - It is recommended to record at least the following freely available
    applications:
    - LunarG Cube demo
    - DOTA2 (on Steam)
  - If there is a particular application you're making adjustments for, record
    that as well.
- Play back each recording using the playback application
- Feel free to subject your code changes to other tests as well!

## **Contributor License Agreement (CLA)**

You will be prompted with a one-time "click-through" CLA dialog as part of
submitting your pull request or other contribution to GitHub.

## **License and Copyrights**

All contributions made to the GFXReconstruct repository are LunarG branded and
as such, any new files need to have the MIT license and copyright included.
Please see an existing file in this repository for an example.

All contributions made to the LunarG repositories are to be made under the
MIT license and any new files need to include this license and any applicable
copyrights.

You can include your individual copyright after any existing copyrights.

## **GFXReconstruct PR Process**

### Creating development branches

Create your branch in your personal fork of [LunarG/gfxreconstruct](https://github.com/LunarG/gfxreconstruct).  We recommend using a name describing the change, e.g. `fix-XYZ` (where `XYZ` is the issue number) or `name-of-feature`, based on the `dev` branch.
> E.g.  `fix-341` or `track-parent-info`

### During Development

* Don’t hand-edit C++ headers or implementation files in `framework/generated`.  To change those files, edit the Python generator scripts and run the generator (`python3 generate_vulkan.py` or `python3 generate_dx12.py`).
* Review [earlier sections](#coding-conventions-and-formatting) of this document for coding style guidelines.
* Attempt to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html). 
* Attempt to follow the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines). 
* Use `GFXRECON_ASSERT `and not `assert.`
* Prefer explicit comparison against `nullptr.`
    * e.g. use `if(pointer_variable == nullptr).`
* Avoid editing code unrelated to the new functionality or bugfix. We want to be able to cleanly revert your commits later if there turns out to be a problem with them, and keeping PRs atomic helps with that.
* Avoid mentioning game or application names in commit messages and avoid mentioning specific companies (fixes should not be specific to a game or application anyway).
* Keep the commit message summary (the first line) to 50 characters, make the second line blank, and format the remainder of the message to 72-characters.
    * Why?  [Because a 50-character commit summary works well](https://cbea.ms/git-commit/) with `git log --oneline --graph` on an 80-column window,  e.g.: ![git log --oneline --graph on an 80-column window](docs/img/gfxreconstruct-pr-process-01.png "git log --oneline --graph on an 80-column window")
    * Of course there are always exceptions.  Prefer clarity in the history over pedantically keeping under limits.

### Checklist before PR creation

* Run `git clang-format` and commit the changes and push before making the PR.  (There’s no real danger to the build if you forget; GitHub Actions CI will fail on the PR until `clang-format` is applied anyway.)
* Squash commits like “apply clang-format” or “clean up”.  Squash pairs of commits that introduce a change and revert the change.  Multiple commits within a single PR are encouraged if the PR contains sub-functions that make sense to be represented individually in the Git history.
* Create a PR with a descriptive subject, like “Fix crash in vulkaninfo” or “Add tracking for all types derived from Wrapper” and create a helpful description.  If a PR is submitted in order to share and receive comments and run CI before the PR is submitted for final approvals, mark it as Draft in Github.
* In the case of an issue fix, put the issue number being fixed in the final commit message or at least in the PR description so the Github issue and PR are linked, and the issue is updated when the PR is merged.  It has to be a particular phrasing to match the pattern to link the PR with the issue, like “fixes #341”; see [the Github page on this.](https://docs.github.com/en/issues/tracking-your-work-with-issues/linking-a-pull-request-to-an-issue#linking-a-pull-request-to-an-issue-using-a-keyword)
    * E.g. `Fixes #341`

### Checklist before PR merge

* Did relevant test cases get run by hand against the PR?  e.g. Android Vulkan replay, DX12 trimmed capture, `convert`, etc - include them and the tested hardware / driver configuration in a comment in the PR.
* Did Github Workflows CI pass? This is the "checks passed" or "checks failed" section at the bottom of the PR and represents whether the automated build in a container succeeded.  This set of “CI builds” includes no replay of capture files.
![Github Workflows CI Screenshot](docs/img/gfxreconstruct-pr-process-02.png "Github Workflows CI Screenshot")
* Did the PR change `gfxrecon-convert `output?
    * If so, does the output still appear correct for changed items? Include a cut-and-paste of output before and after for review.
    * Does the output validate correctly e.g. through the JSON tool [`jq`](https://stedolan.github.io/jq/)?

## **Platform-specific ClangFormat Installation**

The following is a collection of notes for obtaining ClangFormat version 9.0.1
on various platforms.

### **Visual Studio**

- Visual Studio 2019 has built-in support for ClangFormat version 9.
- Visual Studio 2017 has built-in support for an older version of ClangFormat,
  but can be changed to use a separately installed ClangFormat version 9
  by following the instructions described here:
  - Under **Tools->Options...**, expand **Text Editor > C/C++ > Formatting**.
    At the bottom is a checkbox for **Use custom clang-format.exe file**.
    Select this, and browse to the location of the 9.0.1 version of
    `clang-format.exe` that was installed separately.

### **Ubuntu**

For Ubuntu 20, `clang-format-9` is the default provided by the package manager.

For earlier versions of Ubuntu, the required version of `clang-format` can be
obtained through the [LLVM toolchain repository](https://apt.llvm.org) by
following the instructions described here:


On any version of Ubuntu, continue with:

```bash
sudo apt update
sudo apt-get install clang-format-9 clang-tidy-9
```

Configure `clang-format` and `clang-tidy` so that the new version is used by default:

```bash
sudo update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-9 900
sudo update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-9 900
```
