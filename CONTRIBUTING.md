# Contributing to the GFXReconstruct Project

Guidelines for contributing to the GFXReconstruct project.

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2018-2020 LunarG, Inc.

## **Index**

1. [Introduction](#introduction)
2. [Submitting Changes](#submitting-changes)
    1. [Coding Conventions and Formatting](#coding-conventions-and-formatting)
    2. [Verifying Changes with the Build Script](#verifying-changes-with-the-build-script)
    3. [Testing Your Changes](#testing-your-changes)
3. [Contributor License Agreement](#contributor-license-agreement-cla)
4. [License and Copyrights](#license-and-copyrights)
5. [Platform-specific ClangFormat Installation](#platform-specific-clangformat-installation)

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

- Changes to the GFXReconstruct project should conform to the coding style
  defined by the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Code formatting is managed with a custom ClangFormat configuration file.
  This is the `.clang-format` file found at the base of the repo tree.
  It is intended for use with **ClangFormat version 9.0.1**.
  - ClangFormat version 9.0.1 can be obtained by installing the LLVM 9.0.1
    package available from the [LLVM Download Page](https://releases.llvm.org/download.html),
    or [see below](#platform-specific-clangformat-installation) for
    platform-specific installation notes.
- Formatting can be applied to pending changes with the `clang-format` or
  `git clang-format` commands.
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
as such, any new files need to have the Apache 2.0 style license and copyright
included.
Please see an existing file in this repository for an example.

All contributions made to the LunarG repositories are to be made under the
Apache 2.0 license and any new files need to include this license and any
applicable copyrights.

You can include your individual copyright after any existing copyrights.

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

- Ubuntu 18 (Bionic)

```bash
echo "deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-9 main" | sudo tee /etc/apt/sources.list.d/llvm.list
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
```

- Ubuntu 16 (Xenial)

```bash
echo "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-9 main" | sudo tee /etc/apt/sources.list.d/llvm.list
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
```

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
