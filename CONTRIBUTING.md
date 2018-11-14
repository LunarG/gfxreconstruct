## How to Contribute to the GFXReconstruct Repository


### **The Repository**

The source code for GFXReconstruct tools is sponsored by Valve and LunarG.
* [GFXReconstruct](https://github.com/LunarG/gfxreconstruct)


### **The Vulkan Ecosystem Needs Your Help**

The Vulkan VK_LAYER_LUNARG_gfxreconstruct layer and tools are important
components in the Vulkan Ecosystem.
While there are often active and organized development efforts underway to
improve the functionality
and coverage of this layer, there are always opportunities for anyone to help
by contributing.
The easiest method for contribuiting is to examine the
[issues list](https://github.com/LunarG/gfxreconstruct/issues) in this repository
and look for issues that are of interest

Of course, if you have your own work in mind, please open an issue to describe
it and assign it to yourself.
Finally, please feel free to contact any of the developers that are actively
contributing should you wish to coordinate further.

Repository Issue labels:

* _Bug_:          These issues refer to invalid or broken functionality and
 are the highest priority.
* _Enhancement_:  These issues refer to ideas for extending or improving the
 GFXReconstruct layer or tools.

It is the maintainers goal for all issues to be assigned within one business
day of their submission.
If you choose to work on an issue that is assigned, simply coordinate with the
current assignee.


### **How to Submit Fixes**

* **Ensure that the bug was not already reported or fixed** by searching on
GitHub under Issues and Pull Requests.
* Use the existing GitHub forking and pull request process.
  This will involve [forking the repository](https://help.github.com/articles/fork-a-repo/),
  creating a branch with your commits, and then [submitting a pull request](https://help.github.com/articles/using-pull-requests/).
* Please read and adhere to the style and process [guidelines ](#coding-conventions-and-formatting) enumerated below.
* Please base your fixes on the master branch.


#### **Coding Conventions and Formatting**
* The coding style is a custom clang-format style defined in the .clang-format
  file at the base of the repo tree.
* Run **clang-format** on your changes to maintain consistent formatting
    * There are `.clang-format files` present in the repository to define
      clang-format settings which are found and used automatically by clang-format.
    * A sample git workflow may look like:

>        # Make changes to the source.
>        $ git add -u .
>        $ git clang-format --style=file
>        # Check to see if clang-format made any changes and if they are OK.
>        $ git add -u .
>        $ git commit

* **Commit Messages**
    * Limit the subject line to 50 characters -- this allows the information
      to display correctly in git/Github logs
    * Separate subject from body with a blank line
    * Wrap the body at 72 characters
    * Capitalize the subject line
    * Do not end the subject line with a period
    * Use the body to explain what and why vs. how
    * Use the imperative mode in the subject line. This just means to write it
      as a command (e.g. Fix the sprocket)

Strive for commits that implement a single or related set of functionality,
using as many commits as is necessary (more is better).
That said, please ensure that the repository compiles and passes tests without
error for each commit in your pull request.

**NOTE:** to be accepted into the repository, the pull request must
[pass all tests](#testing your changes) on all supported platforms
-- the automatic Github Travis and AppVeyor continuous integration features will
assist in enforcing this requirement.


#### **Testing Your Changes**
* Enable the VK_LAYER_LUNARG_gfxreconstruct layer for several Vulkan
  applications and record traces.
  * It is recommended to record at least the following freely available
    applications:
    * LunarG Cube demo
    * DOTA2 (on Steam)
  * If there is a particular application you're making adjustments for, record
    that as well.
* Play back each recording using the playback application
* Feel free to subject your code changes to other tests as well!


### **Contributor License Agreement (CLA)**

You will be prompted with a one-time "click-through" CLA dialog as part of
submitting your pull request or other contribution to GitHub.

### **License and Copyrights**

All contributions made to the GFXReconstruct repository are LunarG branded and
as such, any new files need to have the Apache 2.0 style license and copyright
included.
Please see an existing file in this repository for an example.

All contributions made to the LunarG repositories are to be made under the
Apache 2.0 license and any new files need to include this license and any
applicable copyrights.

You can include your individual copyright after any existing copyrights.
