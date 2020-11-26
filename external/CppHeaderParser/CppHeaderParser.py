#!/usr/bin/python
#
# Author: Jashua R. Cloutier (contact via https://bitbucket.org/senex)
# Project: http://senexcanis.com/open-source/cppheaderparser/
#
# Copyright (C) 2011, Jashua R. Cloutier
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in
#   the documentation and/or other materials provided with the
#   distribution.
#
# * Neither the name of Jashua R. Cloutier nor the names of its
#   contributors may be used to endorse or promote products derived from
#   this software without specific prior written permission.  Stories,
#   blog entries etc making reference to this project may mention the
#   name Jashua R. Cloutier in terms of project originator/creator etc.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
#
# The CppHeaderParser.py script is written in Python 2.4 and released to
# the open source community for continuous improvements under the BSD
# 2.0 new license, which can be found at:
#
#   http://www.opensource.org/licenses/bsd-license.php
#

from __future__ import print_function


from collections import deque
import os
import sys
import re
import io

import inspect

from .lexer import Lexer
from .doxygen import extract_doxygen_method_params

try:
    from .version import __version__
except ImportError:
    __version__ = "devel"

version = __version__

# Controls error_print
print_errors = 1
# Controls warning_print
print_warnings = 1
# Controls debug_print
debug = 1 if os.environ.get("CPPHEADERPARSER_DEBUG") == "1" else 0
# Controls trace_print
debug_trace = 0

if sys.version_info >= (3, 3):
    # `raise e from src_e` syntax only supported on python 3.3+
    exec("def raise_exc(e, src_e): raise e from src_e", globals())
else:

    def raise_exc(e, src_e):
        raise e


def error_print(fmt, *args):
    if print_errors:
        fmt = "[%4d] " + fmt
        args = (inspect.currentframe().f_back.f_lineno,) + args
        print(fmt % args)


def warning_print(fmt, *args):
    if print_warnings:
        fmt = "[%4d] " + fmt
        args = (inspect.currentframe().f_back.f_lineno,) + args
        print(fmt % args)


if debug:

    def debug_print(fmt, *args):
        fmt = "[%4d] " + fmt
        args = (inspect.currentframe().f_back.f_lineno,) + args
        print(fmt % args)


else:

    def debug_print(fmt, *args):
        pass


if debug_trace:

    def trace_print(*args):
        sys.stdout.write("[%s] " % (inspect.currentframe().f_back.f_lineno))
        for a in args:
            sys.stdout.write("%s " % a)
        sys.stdout.write("\n")


else:

    def trace_print(*args):
        pass


#: Access specifiers
supportedAccessSpecifier = ["public", "protected", "private"]

#: Symbols to ignore, usually special macros
ignoreSymbols = ["Q_OBJECT"]


# Track what was added in what order and at what depth
parseHistory = []


def is_namespace(nameStack):
    """Determines if a namespace is being specified"""
    if len(nameStack) == 0:
        return False
    if nameStack[0] == "namespace":
        return True
    return False


_fundamentals = {
    "size_t",
    "struct",
    "union",
    "unsigned",
    "signed",
    "bool",
    "char",
    "short",
    "int",
    "float",
    "double",
    "long",
    "void",
    "*",
}


def is_fundamental(s):
    for a in s.split():
        if a not in _fundamentals:
            return False
    return True


def is_function_pointer_stack(stack):
    """Count how many non-nested paranthesis are in the stack.  Useful for determining if a stack is a function pointer"""
    paren_depth = 0
    paren_count = 0
    star_after_first_paren = False
    last_e = None
    for e in stack:
        if e == "(":
            paren_depth += 1
        elif e == ")" and paren_depth > 0:
            paren_depth -= 1
            if paren_depth == 0:
                paren_count += 1
        elif e == "*" and last_e == "(" and paren_count == 0 and paren_depth == 1:
            star_after_first_paren = True
        last_e = e

    if star_after_first_paren and paren_count == 2:
        return True
    else:
        return False


def is_method_namestack(stack):
    r = False
    if "(" not in stack:
        r = False
    elif stack[0] == "typedef":
        r = False  # TODO deal with typedef function prototypes
    # elif '=' in stack and stack.index('=') < stack.index('(') and stack[stack.index('=')-1] != 'operator': r = False    #disabled July6th - allow all operators
    elif "operator" in stack:
        r = True  # allow all operators
    elif "{" in stack and stack.index("{") < stack.index("("):
        r = False  # struct that looks like a method/class
    elif "(" in stack and ")" in stack:
        if stack[-1] == ":":
            r = True
        elif "{" in stack and "}" in stack:
            r = True
        elif stack[-1] == ";":
            if is_function_pointer_stack(stack):
                r = False
            else:
                r = True
        elif "{" in stack:
            r = True  # ideally we catch both braces... TODO
    else:
        r = False
    # Test for case of property set to something with parens such as "static const int CONST_A = (1 << 7) - 1;"
    if r and "(" in stack and "=" in stack and "operator" not in stack:
        if stack.index("=") < stack.index("("):
            r = False
    return r


def is_property_namestack(nameStack):
    r = False
    if "(" not in nameStack and ")" not in nameStack:
        r = True
    elif (
        "(" in nameStack
        and "=" in nameStack
        and nameStack.index("=") < nameStack.index("(")
    ):
        r = True
    # See if we are a function pointer
    if not r and is_function_pointer_stack(nameStack):
        r = True
    return r


def is_enum_namestack(nameStack):
    """Determines if a namestack is an enum namestack"""
    if not nameStack:
        return False
    if nameStack[0] == "enum":
        return True
    if len(nameStack) > 1 and nameStack[0] == "typedef" and nameStack[1] == "enum":
        return True
    return False


def set_location_info(thing, location):
    filename, line_number = location
    if filename:
        thing["filename"] = filename
    thing["line_number"] = line_number


_nhack = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")


def _split_namespace(namestack):
    """
    Given a list of name elements, find the namespace portion
    and return that as a string

    :rtype: Tuple[str, list]
    """
    # TODO: this should be using tokens instead of nhack

    last_colon = None
    for i, n in enumerate(namestack):
        if n == "::":
            last_colon = i
        if i and n != "::" and not _nhack.match(n):
            break

    if last_colon:
        ns, namestack = (
            "".join(namestack[: last_colon + 1]),
            namestack[last_colon + 1 :],
        )
    else:
        ns = ""

    return ns, namestack


def _iter_ns_str_reversed(namespace):
    """
    Take a namespace string, and yield successively smaller portions
    of it (ex foo::bar::baz::, foo::bar::, foo::). The last item yielded
    will always be an empty string
    """
    if namespace:
        parts = namespace.split("::")
        for i in range(len(parts) - 1, 0, -1):
            yield "::".join(parts[:i]) + "::"

    yield ""


def _split_by_comma(namestack):
    while namestack:
        if "," not in namestack:
            yield namestack
            break
        idx = namestack.index(",")
        ns = namestack[:idx]
        yield ns
        namestack = namestack[idx + 1 :]


class TagStr(str):
    """Wrapper for a string that allows us to store the line number associated with it"""

    def __new__(cls, *args, **kwargs):
        location = kwargs.pop("location")
        s = str.__new__(cls, *args, **kwargs)
        s.location = location
        return s


class CppParseError(Exception):
    def __init__(self, msg, tok=None):
        Exception.__init__(self, msg)
        self.tok = tok


class CppTemplateParam(dict):
    """
    Dictionary that contains the following:

    - ``decltype`` - If True, this is a decltype
    - ``param`` - Parameter value or typename
    - ``params`` - Only present if a template specialization. Is a list of
        :class:`.CppTemplateParam`
    - ``...`` - If True, indicates a parameter pack
    """

    def __init__(self):
        self["param"] = ""
        self["decltype"] = False
        self["..."] = False

    def __str__(self):
        s = []
        if self["decltype"]:
            s.append("decltype")

        s.append(self["param"])

        params = self.get("params")
        if params is not None:
            s.append("<%s>" % ",".join(str(p) for p in params))

        if self["..."]:
            if s:
                s[-1] = s[-1] + "..."
            else:
                s.append("...")

        return "".join(s)


class CppBaseDecl(dict):
    """
    Dictionary that contains the following

    - ``access`` - Anything in supportedAccessSpecifier
    - ``class`` - Name of the type, along with template specializations
    - ``decl_name`` - Name of the type only
    - ``decl_params`` - Only present if a template specialization (Foo<int>).
      Is a list of :class:`.CppTemplateParam`.
    - ``decltype`` - True/False indicates a decltype, the contents are in
      ``decl_name``
    - ``virtual`` - True/False indicates virtual inheritance
    - ``...`` - True/False indicates a parameter pack

    """

    def __init__(self, default_access):
        self["access"] = default_access
        self["class"] = ""
        self["decl_name"] = ""
        self["decltype"] = False
        self["virtual"] = False
        self["..."] = False

    def _fix_classname(self):
        # set class to the full decl for legacy reasons
        params = self.get("decl_params")

        if self["decltype"]:
            s = "decltype"
        else:
            s = ""

        s += self["decl_name"]
        if params:
            s += "<%s>" % (",".join(str(p) for p in params))

        if self["..."]:
            s += "..."

        return s


def _consume_parens(stack):
    i = 0
    sl = len(stack)
    nested = 1
    while i < sl:
        t = stack[i]
        i += 1
        if t == ")":
            nested -= 1
            if nested == 0:
                return i
        elif t == "(":
            nested += 1

    raise CppParseError("Unmatched (")


def _parse_template_decl(stack):
    debug_print("_parse_template_decl: %s", stack)
    params = []
    param = CppTemplateParam()
    i = 0
    sl = len(stack)
    init = True
    require_ending = False
    while i < sl:
        t = stack[i]
        i += 1
        if init:
            init = False
            if t == "decltype":
                param["decltype"] = True
                continue

        if t == ",":
            params.append(param)
            init = True
            require_ending = False
            param = CppTemplateParam()

            continue
        elif t == ">":
            params.append(param)
            return params, i - 1

        if require_ending:
            raise CppParseError("expected comma, found %s" % t)

        if t == "...":
            param["..."] = True
            require_ending = True
        elif t == "(":
            s = stack[i:]
            n = _consume_parens(s)
            i += n
            param["param"] = param["param"] + "".join(s[:n])
        else:
            if t and t[0] == "<":
                param["params"], n = _parse_template_decl([t[1:]] + stack[i:])
                i += n
            else:
                param["param"] = param["param"] + t

    raise CppParseError("Unmatched <")


def _parse_cppclass_name(c, stack):
    # ignore first thing
    i = 1
    sl = len(stack)
    name = ""
    require_ending = False
    while i < sl:
        t = stack[i]
        i += 1

        if t == ":":
            if i >= sl:
                raise CppParseError("class decl ended with ':'")
            break
        elif t == "::":
            name += "::"
            continue
        elif t == "final":
            c["final"] = True
            continue

        if require_ending:
            raise CppParseError("Unexpected '%s' in class" % ("".join(stack[i - 1 :])))

        if t and t[0] == "<":
            c["class_params"], n = _parse_template_decl([t[1:]] + stack[i:])
            i += n
            require_ending = True
        else:
            name += t

    c["namespace"] = ""

    # backwards compat
    if name.startswith("anon-"):
        if (
            name.startswith("anon-class-")
            or name.startswith("anon-struct-")
            or name.startswith("anon-union-")
        ):
            name = "<" + name + ">"
    c["name"] = name
    c["bare_name"] = name
    debug_print("Found class '%s'", name)

    # backwards compat
    classParams = c.get("class_params")
    if classParams is not None:
        c["name"] = c["name"] + "<%s>" % ",".join(str(p) for p in classParams)

    return i


def _parse_cpp_base(stack, default_access):
    debug_print("Parsing base: %s (access %s)", stack, default_access)
    inherits = []
    i = 0
    sl = len(stack)
    init = True
    base = CppBaseDecl(default_access)
    require_ending = False
    while i < sl:
        t = stack[i]
        i += 1

        if init:
            if t in supportedAccessSpecifier:
                base["access"] = t
                continue
            elif t == "virtual":
                base["virtual"] = True
                continue

            init = False

            if t == "decltype":
                base["decltype"] = True
                continue

        if t == ",":
            inherits.append(base)
            base = CppBaseDecl(default_access)
            init = True
            require_ending = False
            continue

        if require_ending:
            if t == "::":
                if "decl_params" in base:
                    base["decl_name"] = base._fix_classname()
                    del base["decl_params"]
                    base["..."]
                require_ending = False
            else:
                raise CppParseError("expected comma, found '%s'" % t)

        if t == "(":
            s = stack[i:]
            n = _consume_parens(s)
            i += n
            base["decl_name"] = base["decl_name"] + "".join(s[:n])
        elif t == "...":
            base["..."] = True
            require_ending = True
        else:
            if t[0] == "<":
                base["decl_params"], n = _parse_template_decl([t[1:]] + stack[i:])
                i += n
                require_ending = True
            else:
                base["decl_name"] = base["decl_name"] + t

    # backwards compat
    inherits.append(base)
    for base in inherits:
        base["class"] = base._fix_classname()

    return inherits


class CppClass(dict):
    """
    Dictionary that contains at least the following keys:

    * ``name`` - Name of the class
    * ``doxygen`` - Doxygen comments associated with the class if they exist
    * ``inherits`` - List of Classes that this one inherits. Values are
      :class:`.CppBaseDecl`
    * ``methods`` - Dictionary where keys are from supportedAccessSpecifier
      and values are a lists of :class:`.CppMethod`
    * ``namespace`` - Namespace of class
    * ``properties`` - Dictionary where keys are from supportedAccessSpecifier
      and values are lists of :class:`.CppVariable`
    * ``enums`` - Dictionary where keys are from supportedAccessSpecifier and
      values are lists of :class:`.CppEnum`
    * ``nested_classes`` - Classes and structs defined within this class
    * ``final`` - True if final
    * ``abstract`` - True if abstract
    * ``using`` - Using directives in this class scope: key is name for lookup,
      value is :class:`.CppVariable`
    * ``parent`` - If not None, the class that this class is nested in

    An example of how this could look is as follows::

        {
            'name': ""
            'inherits':[]
            'methods':
            {
                'public':[],
                'protected':[],
                'private':[]
            },
            'properties':
            {
                'public':[],
                'protected':[],
                'private':[]
            },
            'enums':
            {
                'public':[],
                'protected':[],
                'private':[]
            }
        }
    """

    def get_all_methods(self):
        r = []
        for typ in supportedAccessSpecifier:
            r += self["methods"][typ]
        return r

    def get_all_method_names(self):
        r = []
        for typ in supportedAccessSpecifier:
            r += self.get_method_names(typ)  # returns list
        return r

    def get_all_pure_virtual_methods(self):
        r = {}
        for typ in supportedAccessSpecifier:
            r.update(self.get_pure_virtual_methods(typ))  # returns dict
        return r

    def get_method_names(self, type="public"):
        return [meth["name"] for meth in self["methods"][type]]

    def get_pure_virtual_methods(self, type="public"):
        r = {}
        for meth in self["methods"][type]:
            if meth["pure_virtual"]:
                r[meth["name"]] = meth
        return r

    def _lookup_type(self, name):
        # TODO: should have indexes for these lookups... and they
        #       should be more unified
        for access in supportedAccessSpecifier:
            for e in self["enums"][access]:
                if e.get("name") == name:
                    return {
                        "enum": self["name"] + "::" + e["name"],
                        "type": e["name"],
                        "namespace": e["namespace"],
                    }
        for n in self["nested_classes"]:
            if n["name"] == name:
                return {"raw_type": self["name"] + "::" + n["name"], "type": n["name"]}

    def __init__(self, nameStack, curTemplate, doxygen, location, defaultAccess):
        self["nested_classes"] = []
        self["parent"] = None
        self["abstract"] = False
        self["final"] = False
        self._public_enums = {}
        self._public_typedefs = {}
        self._public_forward_declares = []
        self["namespace"] = ""
        self["using"] = {}

        debug_print("Class:    %s", nameStack)
        debug_print("Template: %s", curTemplate)

        if len(nameStack) < 2:
            nameStack.insert(1, "")  # anonymous struct
        if doxygen:
            self["doxygen"] = doxygen

        # consume name of class, with any namespaces or templates
        n = _parse_cppclass_name(self, nameStack)

        # consume bases
        baseStack = nameStack[n:]
        if baseStack:
            self["inherits"] = _parse_cpp_base(baseStack, defaultAccess)
        else:
            self["inherits"] = []

        set_location_info(self, location)

        if curTemplate:
            self["template"] = curTemplate
            trace_print("Setting template to '%s'" % self["template"])

        methodAccessSpecificList = {}
        propertyAccessSpecificList = {}
        enumAccessSpecificList = {}
        typedefAccessSpecificList = {}
        forwardAccessSpecificList = {}

        for accessSpecifier in supportedAccessSpecifier:
            methodAccessSpecificList[accessSpecifier] = []
            propertyAccessSpecificList[accessSpecifier] = []
            enumAccessSpecificList[accessSpecifier] = []
            typedefAccessSpecificList[accessSpecifier] = []
            forwardAccessSpecificList[accessSpecifier] = []

        self["methods"] = methodAccessSpecificList
        self["properties"] = propertyAccessSpecificList
        self["enums"] = enumAccessSpecificList
        self["typedefs"] = typedefAccessSpecificList
        self["forward_declares"] = forwardAccessSpecificList

    def show(self):
        """Convert class to a string"""
        namespace_prefix = ""
        if self["namespace"]:
            namespace_prefix = self["namespace"] + "::"
        rtn = "%s %s" % (self["declaration_method"], namespace_prefix + self["name"])
        if self["final"]:
            rtn += " final"
        if self["abstract"]:
            rtn += "    (abstract)\n"
        else:
            rtn += "\n"

        if "doxygen" in list(self.keys()):
            rtn += self["doxygen"] + "\n"
        if "parent" in list(self.keys()) and self["parent"]:
            rtn += "parent class: " + self["parent"]["name"] + "\n"

        if "inherits" in list(self.keys()):
            rtn += "  Inherits: "
            for inheritClass in self["inherits"]:
                if inheritClass["virtual"]:
                    rtn += "virtual "
                rtn += "%s %s, " % (inheritClass["access"], inheritClass["class"])
            rtn += "\n"
        rtn += "  {\n"
        for accessSpecifier in supportedAccessSpecifier:
            rtn += "    %s\n" % (accessSpecifier)
            # Enums
            if len(self["enums"][accessSpecifier]):
                rtn += "        <Enums>\n"
            for enum in self["enums"][accessSpecifier]:
                rtn += "            %s\n" % (repr(enum))
            # Properties
            if len(self["properties"][accessSpecifier]):
                rtn += "        <Properties>\n"
            for property in self["properties"][accessSpecifier]:
                rtn += "            %s\n" % (repr(property))
            # Methods
            if len(self["methods"][accessSpecifier]):
                rtn += "        <Methods>\n"
            for method in self["methods"][accessSpecifier]:
                rtn += "\t\t" + method.show() + "\n"
        rtn += "  }\n"
        print(rtn)

    def __str__(self):
        """Convert class to a string"""
        namespace_prefix = ""
        if self["namespace"]:
            namespace_prefix = self["namespace"] + "::"
        rtn = "%s %s" % (self["declaration_method"], namespace_prefix + self["name"])
        if self["final"]:
            rtn += " final"
        if self["abstract"]:
            rtn += "    (abstract)\n"
        else:
            rtn += "\n"

        if "doxygen" in list(self.keys()):
            rtn += self["doxygen"] + "\n"
        if "parent" in list(self.keys()) and self["parent"]:
            rtn += "parent class: " + self["parent"]["name"] + "\n"

        if "inherits" in list(self.keys()) and len(self["inherits"]):
            rtn += "Inherits: "
            for inheritClass in self["inherits"]:
                if inheritClass.get("virtual", False):
                    rtn += "virtual "
                rtn += "%s %s, " % (inheritClass["access"], inheritClass["class"])
            rtn += "\n"
        rtn += "{\n"
        for accessSpecifier in supportedAccessSpecifier:
            rtn += "%s\n" % (accessSpecifier)
            # Enums
            if len(self["enums"][accessSpecifier]):
                rtn += "    // Enums\n"
            for enum in self["enums"][accessSpecifier]:
                rtn += "    %s\n" % (repr(enum))
            # Properties
            if len(self["properties"][accessSpecifier]):
                rtn += "    // Properties\n"
            for property in self["properties"][accessSpecifier]:
                rtn += "    %s\n" % (repr(property))
            # Methods
            if len(self["methods"][accessSpecifier]):
                rtn += "    // Methods\n"
            for method in self["methods"][accessSpecifier]:
                rtn += "   %s\n" % (repr(method))
        rtn += "}\n"
        return rtn


class CppUnion(CppClass):
    """
    Dictionary that contains at least the following keys:

    * ``name`` - Name of the union
    * ``doxygen`` - Doxygen comments associated with the union if they exist
    * ``members`` - List of members of the union
    """

    def __init__(self, nameStack, doxygen, location):
        CppClass.__init__(self, nameStack, None, doxygen, location, "public")
        self["members"] = self["properties"]["public"]

    def transform_to_union_keys(self):
        print("union keys: %s" % list(self.keys()))
        for key in [
            "inherits",
            "parent",
            "abstract",
            "namespace",
            "typedefs",
            "methods",
        ]:
            del self[key]

    def show(self):
        """Convert class to a string"""
        print(self)

    def __str__(self):
        """Convert class to a string"""
        namespace_prefix = ""
        if self["namespace"]:
            namespace_prefix = self["namespace"] + "::"
        rtn = "%s %s" % (self["declaration_method"], namespace_prefix + self["name"])
        if self["abstract"]:
            rtn += "    (abstract)\n"
        else:
            rtn += "\n"

        if "doxygen" in list(self.keys()):
            rtn += self["doxygen"] + "\n"
        if "parent" in list(self.keys()) and self["parent"]:
            rtn += "parent class: " + self["parent"]["name"] + "\n"

        rtn += "{\n"
        for member in self["members"]:
            rtn += "    %s\n" % (repr(member))
        rtn += "}\n"
        return rtn


class _CppMethod(dict):
    def _params_helper1(self, stack):
        # deal with "throw" keyword
        if "throw" in stack:
            stack = stack[: stack.index("throw")]

        ## remove GCC keyword __attribute__(...) and preserve returns ##
        cleaned = []
        hit = False
        hitOpen = 0
        hitClose = 0
        for a in stack:
            if a == "__attribute__":
                hit = True
            if hit:
                if a == "(":
                    hitOpen += 1
                elif a == ")":
                    hitClose += 1
                if a == ")" and hitOpen == hitClose:
                    hit = False
            else:
                cleaned.append(a)
        stack = cleaned

        # also deal with attribute((const)) function prefix #
        # TODO this needs to be better #
        if len(stack) > 5:
            a = "".join(stack)
            if a.startswith("((__const__))"):
                stack = stack[5:]
            elif a.startswith("__attribute__((__const__))"):
                stack = stack[6:]

        stack = stack[stack.index("(") + 1 :]
        if not stack:
            return []
        if (
            len(stack) >= 3 and stack[0] == ")" and stack[1] == ":"
        ):  # is this always a constructor?
            self["constructor"] = True
            return []

        stack.reverse()
        _end_ = stack.index(")")
        stack.reverse()
        stack = stack[: len(stack) - (_end_ + 1)]
        if "(" not in stack:
            return stack  # safe to return, no defaults that init a class

        return stack

    def _params_helper2(self, params):
        for p in params:
            p["method"] = self  # save reference in variable to parent method
            p["parent"] = self
            if "::" in p["type"]:
                ns = p["type"].split("::")[0]
                if ns not in Resolver.NAMESPACES and ns in Resolver.CLASSES:
                    p["type"] = self["namespace"] + p["type"]
            else:
                p["namespace"] = self["namespace"]


class CppMethod(_CppMethod):
    """
    Dictionary that contains at least the following keys:

    * ``rtnType`` - Return type of the method (ex. "int")
    * ``name`` - Name of the method
    * ``doxygen`` - Doxygen comments associated with the method if they exist
    * ``parameters`` - List of :class:`.CppVariable`
    * ``parent`` - If not None, the class this method belongs to
    """

    def show(self):
        r = ["method name: %s (%s)" % (self["name"], self["debug"])]
        if self["returns"]:
            r.append("returns: %s" % self["returns"])
        if self["parameters"]:
            r.append("number arguments: %s" % len(self["parameters"]))
        if self["pure_virtual"]:
            r.append("pure virtual: %s" % self["pure_virtual"])
        if self["constructor"]:
            r.append("constructor")
        if self["destructor"]:
            r.append("destructor")
        return "\n\t\t  ".join(r)

    def __init__(self, nameStack, curClass, methinfo, curTemplate, doxygen, location):
        debug_print("Method:   %s", nameStack)
        debug_print("Template: %s", curTemplate)

        if doxygen:
            self["doxygen"] = doxygen

        # Remove leading keywords
        for i, word in enumerate(nameStack):
            if word not in Resolver.C_KEYWORDS:
                nameStack = nameStack[i:]
                break

        if "operator" in nameStack:
            rtnType = " ".join(nameStack[: nameStack.index("operator")])
            self["name"] = "".join(
                nameStack[nameStack.index("operator") : nameStack.index("(")]
            )
        else:
            rtnType = " ".join(nameStack[: nameStack.index("(") - 1])
            self["name"] = " ".join(
                nameStack[nameStack.index("(") - 1 : nameStack.index("(")]
            )

        if len(rtnType) == 0 or self["name"] == curClass:
            rtnType = "void"

        self["rtnType"] = (
            rtnType.replace(" :: ", "::")
            .replace(" < ", "<")
            .replace(" > ", "> ")
            .replace(">>", "> >")
            .replace(" ,", ",")
        )

        # deal with "noexcept" specifier/operator
        self["noexcept"] = None
        if "noexcept" in nameStack:
            noexcept_idx = nameStack.index("noexcept")
            hit = True
            cleaned = nameStack[:noexcept_idx]
            parentCount = 0
            noexcept = "noexcept"
            for a in nameStack[noexcept_idx + 1 :]:
                if a == "noexcept":
                    hit = True
                if hit:
                    if a == "(":
                        parentCount += 1
                    elif a == ")":
                        parentCount -= 1
                    elif parentCount == 0 and a != "noexcept":
                        hit = False
                        cleaned.append(a)
                        continue  # noexcept without parenthesis
                    if a == ")" and parentCount == 0:
                        hit = False
                    noexcept += a
                else:
                    cleaned.append(a)
            self["noexcept"] = noexcept
            nameStack = cleaned

        for spec in ["const", "final", "override"]:
            self[spec] = False
            for i in reversed(nameStack):
                if i == spec:
                    self[spec] = True
                    break
                elif i == ")":
                    break

        self.update(methinfo)
        set_location_info(self, location)

        paramsStack = self._params_helper1(nameStack)

        debug_print("curTemplate: %s", curTemplate)
        if curTemplate:
            self["template"] = curTemplate
            debug_print("SET self['template'] to `%s`", self["template"])

        params = []
        # See if there is a doxygen comment for the variable
        if "doxygen" in self:
            doxyVarDesc = extract_doxygen_method_params(self["doxygen"])
        else:
            doxyVarDesc = {}

        # non-vararg by default
        self["vararg"] = False
        # Create the variable now
        while len(paramsStack):
            # Find commas that are not nexted in <>'s like template types
            open_template_count = 0
            open_paren_count = 0
            open_brace_count = 0
            param_separator = 0
            i = 0
            for elm in paramsStack:
                if elm in "<>(){},":
                    if elm == ",":
                        if (
                            open_template_count == 0
                            and open_paren_count == 0
                            and open_brace_count == 0
                        ):
                            param_separator = i
                            break
                    elif "<" == elm:
                        open_template_count += 1
                    elif ">" == elm:
                        open_template_count -= 1
                    elif "(" == elm:
                        open_paren_count += 1
                    elif ")" == elm:
                        open_paren_count -= 1
                    elif "{" == elm:
                        open_brace_count += 1
                    elif "}" == elm:
                        open_brace_count -= 1
                i += 1

            if param_separator:
                tpstack = paramsStack[0:param_separator]
                param = CppVariable(
                    tpstack,
                    None,
                    getattr(tpstack[0], "location", location),
                    doxyVarDesc=doxyVarDesc,
                )
                if len(list(param.keys())):
                    params.append(param)
                paramsStack = paramsStack[param_separator + 1 :]
            elif len(paramsStack) and paramsStack[0] == "...":
                self["vararg"] = True
                paramsStack = paramsStack[1:]
            else:
                param = CppVariable(
                    paramsStack,
                    None,
                    getattr(paramsStack[0], "location", location),
                    doxyVarDesc=doxyVarDesc,
                )
                if len(list(param.keys())):
                    params.append(param)
                break

        # foo(void) should be zero parameters
        if len(params) == 1 and params[0]["type"] == "void":
            params = []

        self["parameters"] = params
        self._params_helper2(params)  # mods params inplace

    def __str__(self):
        filter_keys = ("parent", "defined", "operator", "returns_reference")
        cpy = dict((k, v) for (k, v) in list(self.items()) if k not in filter_keys)
        return "%s" % cpy


_var_keywords = {
    n: 0
    for n in "constant constexpr reference pointer static typedefs class fundamental unresolved".split()
}


class _CppVariable(dict):
    def _name_stack_helper(self, stack):
        stack = list(stack)
        if "=" not in stack:  # TODO refactor me
            # check for array[n] and deal with funny array syntax: "int myvar:99"
            array = []
            while stack and stack[-1].isdigit():
                array.append(stack.pop())
            if array:
                array.reverse()
                self["array"] = int("".join(array))
            if stack and stack[-1].endswith(":"):
                stack[-1] = stack[-1][:-1]

        while stack and not stack[-1]:
            stack.pop()  # can be empty
        return stack

    def init(self):
        # assert self['name']    # allow unnamed variables, methods like this: "void func(void);"
        a = []
        self["aliases"] = []
        self["parent"] = None
        self["typedef"] = None
        self.update(_var_keywords)
        for b in self["type"].split():
            if b == "__const__":
                b = "const"
            a.append(b)
        self["type"] = " ".join(a)


class CppVariable(_CppVariable):
    """
    Dictionary that contains at least the following keys:

    * ``type`` - Type for the variable (ex. "const string &")
    * ``name`` - Name of the variable (ex. "numItems")
    * ``namespace`` - Namespace
    * ``desc`` - If a method/function parameter, doxygen description for this parameter (optional)
    * ``doxygen`` - If a normal property/variable, doxygen description for this
    * ``default`` - Default value of the variable, this key will only
      exist if there is a default value
    * ``extern`` - True if its an extern, False if not
    * ``parent`` - If not None, either the class this is a property of, or the
      method this variable is a parameter in
    """

    Vars = []

    def __init__(self, nameStack, doxygen, location, **kwargs):
        debug_print("var trace %s", nameStack)
        if len(nameStack) and nameStack[0] == "extern":
            self["extern"] = True
            del nameStack[0]
        else:
            self["extern"] = False

        _stack_ = nameStack
        if "[" in nameStack:  # strip off array informatin
            arrayStack = nameStack[nameStack.index("[") :]
            if nameStack.count("[") > 1:
                debug_print("Multi dimensional array")
                debug_print("arrayStack=%s", arrayStack)
                nums = [x for x in arrayStack if x.isdigit()]
                # Calculate size by multiplying all dimensions
                p = 1
                for n in nums:
                    p *= int(n)
                # Multi dimensional array
                self["array_size"] = p
                self["multi_dimensional_array"] = 1
                self["multi_dimensional_array_size"] = "x".join(nums)
            else:
                debug_print("Array")
                if len(arrayStack) == 3:
                    self["array_size"] = arrayStack[1]
            nameStack = nameStack[: nameStack.index("[")]
            self["array"] = 1
        else:
            self["array"] = 0
        nameStack = self._name_stack_helper(nameStack)

        if doxygen:
            self["doxygen"] = doxygen

        debug_print("Variable: %s", nameStack)

        set_location_info(self, location)
        self["function_pointer"] = 0

        if len(nameStack) < 2:  # +++
            if len(nameStack) == 1:
                self["type"] = nameStack[0]
                self["name"] = ""
            else:
                error_print("%s", _stack_)
                assert 0

        elif is_function_pointer_stack(nameStack):  # function pointer
            self["type"] = " ".join(
                nameStack[: nameStack.index("(") + 2]
                + nameStack[nameStack.index(")") :]
            )
            self["name"] = " ".join(
                nameStack[nameStack.index("(") + 2 : nameStack.index(")")]
            )
            self["function_pointer"] = 1

        elif "=" in nameStack:
            self["type"] = " ".join(nameStack[: nameStack.index("=") - 1])
            self["name"] = nameStack[nameStack.index("=") - 1]
            default = " ".join(nameStack[nameStack.index("=") + 1 :])
            default = self._filter_name(default)
            self["default"] = default
            # backwards compat; deprecate camelCase in dicts
            self["defaultValue"] = default

        elif is_fundamental(nameStack[-1]) or nameStack[-1] in [">", "<", ":", "."]:
            # Un named parameter
            self["type"] = " ".join(nameStack)
            self["name"] = ""

        else:  # common case
            self["type"] = " ".join(nameStack[:-1])
            self["name"] = nameStack[-1]

        self["type"] = self._filter_name(self["type"])

        # Optional doxygen description
        try:
            self["desc"] = kwargs["doxyVarDesc"][self["name"]]
        except:
            pass

        self.init()
        CppVariable.Vars.append(self)  # save and resolve later

    def _filter_name(self, name):
        name = name.replace(" :", ":").replace(": ", ":")
        name = name.replace(" < ", "<")
        name = name.replace(" > ", "> ").replace(">>", "> >")
        name = name.replace(") >", ")>")
        name = name.replace(" {", "{").replace(" }", "}")
        name = name.replace(" ,", ",")
        return name

    def __str__(self):
        keys_white_list = [
            "constant",
            "name",
            "reference",
            "type",
            "static",
            "pointer",
            "desc",
            "line_number",
            "extern",
        ]
        cpy = dict((k, v) for (k, v) in list(self.items()) if k in keys_white_list)
        if "array_size" in self:
            cpy["array_size"] = self["array_size"]
        return "%s" % cpy


class _CppEnum(dict):
    def resolve_enum_values(self, values):
        """Evaluates the values list of dictionaries passed in and figures out what the enum value
        for each enum is editing in place:

        Example
        From: [{'name': 'ORANGE'},
               {'name': 'RED'},
               {'name': 'GREEN', 'value': '8'}]
        To:   [{'name': 'ORANGE', 'value': 0},
               {'name': 'RED', 'value': 1},
               {'name': 'GREEN', 'value': 8}]
        """
        t = int
        i = 0
        names = [v["name"] for v in values]
        for v in values:
            if "value" in v:
                a = v["value"].strip()
                # Remove single quotes from single quoted chars (unless part of some expression
                if len(a) == 3 and a[0] == "'" and a[2] == "'":
                    a = v["value"] = a[1]
                if a.lower().startswith("0x"):
                    try:
                        i = a = int(a, 16)
                    except:
                        pass
                elif a.isdigit():
                    i = a = int(a)
                elif a in names:
                    for other in values:
                        if other["name"] == a:
                            v["value"] = other["value"]
                            break

                elif '"' in a or "'" in a:
                    t = str  # only if there are quotes it this a string enum
                else:
                    try:
                        a = i = ord(a)
                    except:
                        pass
                # Allow access of what is in the file pre-convert if converted
                if v["value"] != str(a):
                    v["raw_value"] = v["value"]
                v["value"] = a
            else:
                v["value"] = i
            try:
                v["value"] = v["value"].replace(" < < ", " << ").replace(" >> ", " >> ")
            except:
                pass
            i += 1
        self["type"] = t


class CppEnum(_CppEnum):
    """Contains the following keys:

    * ``name`` - Name of the enum (ex. "ItemState")
    * ``namespace`` - Namespace containing the enum
    * ``isclass`` - True if created via 'enum class' or 'enum struct'
    * ``values`` - List of values. The values are a dictionary with
      the following key/values:

      - ``name`` - name of the key (ex. "PARSING_HEADER"),
      - ``value`` - Specified value of the enum, this key will only exist
        if a value for a given enum value was defined
    """

    def __init__(self, name, doxygen, location):
        if doxygen:
            self["doxygen"] = doxygen
        if name:
            self["name"] = name
        self["namespace"] = ""
        self["typedef"] = False
        self["isclass"] = False
        self["values"] = []
        set_location_info(self, location)


class _CppPreprocessorLiteral(dict):
    """Implementation for #pragmas, #defines and #includes, contains the
    following keys:

    * ``value`` the value literal of the preprocessor item
    * ``line_number`` line number at which the item was found
    """

    def __init__(self, macro, location):
        self["value"] = re.split("[\t ]+", macro, 1)[1].strip()
        set_location_info(self, location)

    def __str__(self):
        return self["value"]


# Implementation is shared between CppPragma, CppDefine, CppInclude but they are
# distinct so that they may diverge if required without interface-breaking
# changes
class CppPragma(_CppPreprocessorLiteral):
    pass


class CppDefine(_CppPreprocessorLiteral):
    pass


class CppInclude(_CppPreprocessorLiteral):
    pass


C99_NONSTANDARD = {
    "int8": "signed char",
    "int16": "short int",
    "int32": "int",
    "int64": "int64_t",  # this can be: long int (64bit), or long long int (32bit)
    "uint": "unsigned int",
    "uint8": "unsigned char",
    "uint16": "unsigned short int",
    "uint32": "unsigned int",
    "uint64": "uint64_t",  # depends on host bits
}


def standardize_fundamental(s):
    if s in C99_NONSTANDARD:
        return C99_NONSTANDARD[s]
    else:
        return s


class Resolver(object):
    C_FUNDAMENTAL = "size_t unsigned signed bool char wchar short int float double long void".split()
    C_FUNDAMENTAL += "struct union enum".split()
    C_FUNDAMENTAL = set(C_FUNDAMENTAL)

    C_MODIFIERS = "* & const constexpr static mutable".split()
    C_MODIFIERS = set(C_MODIFIERS)

    C_KEYWORDS = "extern virtual static explicit inline friend".split()
    C_KEYWORDS = set(C_KEYWORDS)

    SubTypedefs = {}  # TODO deprecate?
    NAMESPACES = []
    CLASSES = {}

    def initextra(self):
        self.typedefs = {}
        self.typedefs_order = []
        self.classes_order = []
        self.namespaces = Resolver.NAMESPACES  # save all namespaces
        self.stack = (
            []
        )  # full name stack, good idea to keep both stacks? (simple stack and full stack)
        self._classes_brace_level = {}  # class name : level
        self._forward_decls = []
        self._template_typenames = []  # template<typename XXX>

    def current_namespace(self):
        return self.cur_namespace(True)

    def cur_namespace(self, add_double_colon=False):
        rtn = ""
        i = 0
        while i < len(self.nameSpaces):
            rtn += self.nameSpaces[i]
            if add_double_colon or i < len(self.nameSpaces) - 1:
                rtn += "::"
            i += 1
        return rtn

    def guess_ctypes_type(self, string):
        pointers = string.count("*")
        string = string.replace("*", "")

        a = string.split()
        if "unsigned" in a:
            u = "u"
        else:
            u = ""
        if "long" in a and "double" in a:
            b = "longdouble"  # there is no ctypes.c_ulongdouble (this is a 64bit float?)
        elif a.count("long") == 2 and "int" in a:
            b = "%sint64" % u
        elif a.count("long") == 2:
            b = "%slonglong" % u
        elif "long" in a:
            b = "%slong" % u
        elif "double" in a:
            b = "double"  # no udouble in ctypes
        elif "short" in a:
            b = "%sshort" % u
        elif "char" in a:
            b = "%schar" % u
        elif "wchar" in a:
            b = "wchar"
        elif "bool" in a:
            b = "bool"
        elif "float" in a:
            b = "float"

        elif "int" in a:
            b = "%sint" % u
        elif "int8" in a:
            b = "int8"
        elif "int16" in a:
            b = "int16"
        elif "int32" in a:
            b = "int32"
        elif "int64" in a:
            b = "int64"

        elif "uint" in a:
            b = "uint"
        elif "uint8" in a:
            b = "uint8"
        elif "uint16" in a:
            b = "uint16"
        elif "uint32" in a:
            b = "uint32"
        elif "uint64" in a:
            b = "uint64"

        elif "size_t" in a:
            b = "size_t"
        elif "void" in a:
            b = "void_p"

        elif string in ("struct", "union"):
            b = "void_p"  # what should be done here? don't trust struct, it could be a class, no need to expose via ctypes
        else:
            b = "void_p"

        if not pointers:
            return "ctypes.c_%s" % b
        else:
            x = ""
            for i in range(pointers):
                x += "ctypes.POINTER("
            x += "ctypes.c_%s" % b
            x += ")" * pointers
            return x

    def _remove_modifiers(self, vtype):
        return " ".join(x for x in vtype.split() if x not in self.C_MODIFIERS)

    def _create_raw_type(self, vtype):
        lt = vtype.find("<")
        if lt != -1:
            gt = vtype.rfind(">")
            vtype = (
                self._remove_modifiers(vtype[:lt])
                + vtype[lt : gt + 1]
                + self._remove_modifiers(vtype[gt + 1 :])
            )
        else:
            vtype = self._remove_modifiers(vtype)

        return vtype

    def resolve_type(self, string, result):  # recursive
        """
        keeps track of useful things like: how many pointers, number of typedefs, is fundamental or a class, etc...
        """
        ## be careful with templates, what is inside <something*> can be a pointer but the overall type is not a pointer
        ## these come before a template
        s = string.split("<")[0].split()
        result["constant"] += s.count("const")
        result["constexpr"] += s.count("constexpr")
        result["static"] += s.count("static")
        result["mutable"] = "mutable" in s

        ## these come after a template
        s = string.split(">")[-1]
        result["pointer"] += s.count("*")
        result["reference"] += s.count("&")

        x = string
        alias = False
        for a in self.C_MODIFIERS:
            x = x.replace(a, "")
        for y in x.split():
            if y not in self.C_FUNDAMENTAL:
                alias = y
                break

        # if alias == 'class':
        #    result['class'] = result['name']    # forward decl of class
        #    result['forward_decl'] = True
        if alias == "__extension__":
            result["fundamental_extension"] = True
        elif alias:
            if alias in result["aliases"]:
                # already resolved
                return
            result["aliases"].append(alias)
            if alias in C99_NONSTANDARD:
                result["type"] = C99_NONSTANDARD[alias]
                result["typedef"] = alias
                result["typedefs"] += 1
            elif alias in self.typedefs:
                result["typedefs"] += 1
                result["typedef"] = alias
                self.resolve_type(self.typedefs[alias], result)
            elif alias in self.classes:
                klass = self.classes[alias]
                result["fundamental"] = False
                result["class"] = klass
                result["unresolved"] = False
            else:
                used = None

                # Search for in parents
                if not used:
                    parent = result["parent"]
                    while parent:
                        p_using = parent.get("using")
                        if p_using:
                            used = p_using.get(alias)
                            if used:
                                break
                        lookup = getattr(parent, "_lookup_type", None)
                        if lookup:
                            used = lookup(alias)
                            if used:
                                break
                        parent = parent["parent"]

                if not used and self.using:
                    # search for type in all enclosing namespaces
                    # TODO: would be nice if namespaces were an object?
                    for ns in _iter_ns_str_reversed(result.get("namespace", "")):
                        nsalias = ns + alias
                        used = self.using.get(nsalias)
                        if used:
                            break

                if used:
                    for i in ("enum", "type", "namespace", "ctypes_type", "raw_type"):
                        if i in used:
                            result[i] = used[i]
                    result["unresolved"] = False
        else:
            result["fundamental"] = True
            result["unresolved"] = False

    def finalize_vars(self):
        # for c in self.classes.values():
        #    for var in c.get_all_properties(): var['parent'] = c['name']

        ## RESOLVE ##
        for var in CppVariable.Vars:
            self.resolve_type(var["type"], var)
            # if 'method' in var and var['method']['name'] ==  '_notifyCurrentCamera': print(var); assert 0

        # then find concrete type and best guess ctypes type #
        for var in CppVariable.Vars:
            if not var["aliases"]:  # var['fundamental']:
                var["ctypes_type"] = self.guess_ctypes_type(var["type"])
            else:
                var["unresolved"] = False  # below may test to True
                if var["class"]:
                    var["ctypes_type"] = "ctypes.c_void_p"
                else:
                    assert var["aliases"]
                    tag = var["aliases"][0]

                    klass = None
                    nestedEnum = None
                    nestedStruct = None
                    nestedTypedef = None

                    parent = var["parent"]
                    while parent:
                        nestedEnum = getattr(parent, "_public_enums", {}).get(tag)
                        if nestedEnum:
                            break
                        nestedTypedef = getattr(parent, "_public_typedefs", {}).get(tag)
                        if nestedTypedef:
                            break
                        parent = parent["parent"]

                    if "<" in tag:  # should also contain '>'
                        var["template"] = tag  # do not resolve templates
                        var["ctypes_type"] = "ctypes.c_void_p"
                        var["unresolved"] = True

                    elif nestedEnum:
                        enum = nestedEnum
                        etype = enum.get("type")
                        if etype is int:
                            var["ctypes_type"] = "ctypes.c_int"
                            var["raw_type"] = "int"

                        elif etype is str:
                            var["ctypes_type"] = "ctypes.c_char_p"
                            var["raw_type"] = "char*"

                        if "method" in var:
                            var["enum"] = var["method"]["path"] + "::" + enum["name"]
                        else:
                            var["enum"] = enum["name"]
                        var["fundamental"] = True

                    elif nestedStruct:
                        var["ctypes_type"] = "ctypes.c_void_p"
                        var["raw_type"] = (
                            var["method"]["path"] + "::" + nestedStruct["type"]
                        )
                        var["fundamental"] = False

                    elif nestedTypedef:
                        var["fundamental"] = is_fundamental(nestedTypedef)
                        if not var["fundamental"] and "method" in var:
                            var["raw_type"] = var["method"]["path"] + "::" + tag

                    else:
                        _tag = tag
                        if "::" in tag and tag.split("::")[0] in self.namespaces:
                            tag = tag.split("::")[-1]
                        con = self.concrete_typedef(_tag)
                        if con:
                            var["concrete_type"] = con
                            var["ctypes_type"] = self.guess_ctypes_type(
                                var["concrete_type"]
                            )

                        elif tag in self._forward_decls:
                            var["forward_declared"] = tag
                            var["ctypes_type"] = "ctypes.c_void_p"

                        elif tag in self.global_enums:
                            enum = self.global_enums[tag]
                            enum_type = enum.get("type")
                            if enum_type is int:
                                var["ctypes_type"] = "ctypes.c_int"
                                var["raw_type"] = "int"
                            elif enum_type is str:
                                var["ctypes_type"] = "ctypes.c_char_p"
                                var["raw_type"] = "char*"
                            var["enum"] = enum["namespace"] + enum["name"]
                            var["fundamental"] = True

                        elif var["parent"] and var["unresolved"]:
                            warning_print("WARN unresolved %s", _tag)
                            var["ctypes_type"] = "ctypes.c_void_p"
                            var["unresolved"] = True

                        elif tag.count("::") == 1:
                            trace_print("trying to find nested something in", tag)
                            a = tag.split("::")[0]
                            b = tag.split("::")[-1]
                            if (
                                a in self.classes
                            ):  # a::b is most likely something nested in a class
                                klass = self.classes[a]
                                if b in klass._public_enums:
                                    trace_print("...found nested enum", b)
                                    enum = klass._public_enums[b]
                                    etype = enum.get("type")
                                    if etype is int:
                                        var["ctypes_type"] = "ctypes.c_int"
                                        var["raw_type"] = "int"
                                    elif etype is str:
                                        var["ctypes_type"] = "ctypes.c_char_p"
                                        var["raw_type"] = "char*"
                                    try:
                                        if "method" in var:
                                            var["enum"] = (
                                                var["method"]["path"]
                                                + "::"
                                                + enum["name"]
                                            )
                                        else:  # class property
                                            var["unresolved"] = True
                                    except:
                                        var["unresolved"] = True

                                    var["fundamental"] = True

                                else:
                                    var["unresolved"] = True  # TODO klass._public_xxx

                            elif (
                                a in self.namespaces
                            ):  # a::b can also be a nested namespace
                                if b in self.global_enums:
                                    enum = self.global_enums[b]
                                    trace_print(enum)
                                trace_print(var)
                                assert 0

                            elif (
                                b in self.global_enums
                            ):  # falling back, this is a big ugly
                                enum = self.global_enums[b]
                                assert a in enum["namespace"].split("::")
                                etype = enum.get("type")
                                if etype is int:
                                    var["ctypes_type"] = "ctypes.c_int"
                                    var["raw_type"] = "int"
                                elif etype is str:
                                    var["ctypes_type"] = "ctypes.c_char_p"
                                    var["raw_type"] = "char*"
                                var["fundamental"] = True

                            else:  # boost::gets::crazy
                                trace_print("NAMESPACES", self.namespaces)
                                trace_print(a, b)
                                trace_print("---- boost gets crazy ----")
                                var["ctypes_type"] = "ctypes.c_void_p"
                                var["unresolved"] = True

                        elif "namespace" in var and self.concrete_typedef(
                            var["namespace"] + tag
                        ):
                            # print( 'TRYING WITH NS', var['namespace'] )
                            con = self.concrete_typedef(var["namespace"] + tag)
                            if con:
                                var["typedef"] = var["namespace"] + tag
                                var["type"] = con
                                if "struct" in con.split():
                                    var["raw_type"] = var["typedef"]
                                    var["ctypes_type"] = "ctypes.c_void_p"
                                else:
                                    self.resolve_type(var["type"], var)
                                    var["ctypes_type"] = self.guess_ctypes_type(
                                        var["type"]
                                    )

                        elif "::" in var:
                            var["ctypes_type"] = "ctypes.c_void_p"
                            var["unresolved"] = True

                        elif tag in self.SubTypedefs:  # TODO remove SubTypedefs
                            if (
                                "property_of_class" in var
                                or "property_of_struct" in var
                            ):
                                trace_print(
                                    "class:", self.SubTypedefs[tag], "tag:", tag
                                )
                                var["typedef"] = self.SubTypedefs[tag]  # class name
                                var["ctypes_type"] = "ctypes.c_void_p"
                            else:
                                trace_print("WARN-this should almost never happen!")
                                trace_print(var)
                                trace_print("-" * 80)
                                var["unresolved"] = True

                        elif tag in self._template_typenames:
                            var["typename"] = tag
                            var["ctypes_type"] = "ctypes.c_void_p"
                            var[
                                "unresolved"
                            ] = True  # TODO, how to deal with templates?

                        elif tag.startswith(
                            "_"
                        ):  # assume starting with underscore is not important for wrapping
                            warning_print("WARN unresolved %s", _tag)
                            var["ctypes_type"] = "ctypes.c_void_p"
                            var["unresolved"] = True

                        else:
                            trace_print("WARN: unknown type", var)
                            assert (
                                "property_of_class" in var or "property_of_struct"
                            )  # only allow this case
                            var["unresolved"] = True

                    ## if not resolved and is a method param, not going to wrap these methods  ##
                    if var["unresolved"] and "method" in var:
                        var["method"]["unresolved_parameters"] = True

        # create stripped raw_type #
        for var in CppVariable.Vars:
            if "raw_type" not in var:
                var["raw_type"] = self._create_raw_type(var["type"])

                # if 'AutoConstantEntry' in var['raw_type']: print(var); assert 0
                if var["class"]:
                    if "::" not in var["raw_type"]:
                        if not var["class"]["parent"]:
                            var["raw_type"] = (
                                var["class"]["namespace"] + "::" + var["raw_type"]
                            )
                        else:
                            parent = var["class"]["parent"]
                            var["raw_type"] = (
                                parent["namespace"]
                                + "::"
                                + var["class"]["name"]
                                + "::"
                                + var["raw_type"]
                            )

                    elif (
                        "::" in var["raw_type"]
                        and var["raw_type"].split("::")[0] not in self.namespaces
                    ):
                        var["raw_type"] = (
                            var["class"]["namespace"] + "::" + var["raw_type"]
                        )
                    else:
                        var["unresolved"] = True

                elif "forward_declared" in var and "namespace" in var:
                    if "::" not in var["raw_type"]:
                        var["raw_type"] = var["namespace"] + var["raw_type"]
                    elif (
                        "::" in var["raw_type"]
                        and var["raw_type"].split("::")[0] in self.namespaces
                    ):
                        pass
                    else:
                        trace_print("-" * 80)
                        trace_print(var)
                        raise NotImplementedError

            ## need full name space for classes in raw type ##
            if var["raw_type"].startswith("::"):
                # print(var)
                # print('NAMESPACE', var['class']['namespace'])
                # print( 'PARENT NS', var['class']['parent']['namespace'] )
                # assert 0
                var["unresolved"] = True
                if "method" in var:
                    var["method"]["unresolved_parameters"] = True
                # var['raw_type'] = var['raw_type'][2:]

        # Take care of #defines and #pragmas etc
        trace_print("Processing precomp_macro_buf: %s" % self._precomp_macro_buf)
        for m, location in self._precomp_macro_buf:
            macro = m.replace("<CppHeaderParser_newline_temp_replacement>\\n", "\n")
            ml = macro.lower()
            try:
                if ml.startswith("#define"):
                    trace_print("Adding #define %s" % macro)
                    define = CppDefine(macro, location)
                    self.defines.append(define["value"])
                    self.defines_detail.append(define)
                elif ml.startswith("#pragma"):
                    trace_print("Adding #pragma %s" % macro)
                    pragma = CppPragma(macro, location)
                    self.pragmas_detail.append(pragma)
                    self.pragmas.append(pragma["value"])
                elif ml.startswith("#include"):
                    trace_print("Adding #include %s" % macro)
                    include = CppInclude(macro, location)
                    self.includes.append(include["value"])
                    self.includes_detail.append(include)
                else:
                    debug_print("Cant detect what to do with precomp macro '%s'", macro)
            except:
                pass
        self._precomp_macro_buf = None

    def concrete_typedef(self, key):
        if key not in self.typedefs:
            # print( 'FAILED typedef', key )
            return None
        while key in self.typedefs:
            prev = key
            key = self.typedefs[key]
            if "<" in key or ">" in key:
                return prev  # stop at template
            if key.startswith("std::"):
                return key  # stop at std lib
        return key


class _CppHeader(Resolver):
    def finalize(self):
        self.finalize_vars()
        # finalize classes and method returns types
        for cls in list(self.classes.values()):
            for meth in cls.get_all_methods():
                if meth["pure_virtual"]:
                    cls["abstract"] = True

                # hack
                rtnType = {
                    "aliases": [],
                    "parent": cls,
                    "unresolved": True,
                    "constant": 0,
                    "constexpr": 0,
                    "static": 0,
                    "pointer": 0,
                    "reference": 0,
                    "typedefs": 0,
                }
                self.resolve_type(meth["rtnType"], rtnType)
                if not rtnType["unresolved"]:
                    if "enum" in rtnType:
                        meth["rtnType"] = rtnType["enum"]
                    elif "raw_type" in rtnType:
                        meth["rtnType"] = rtnType["raw_type"]

                # TODO: all of this needs to die and be replaced by CppVariable

                if (
                    not meth["returns_fundamental"]
                    and meth["returns"] in C99_NONSTANDARD
                ):
                    meth["returns"] = C99_NONSTANDARD[meth["returns"]]
                    meth["returns_fundamental"] = True

                elif not meth["returns_fundamental"]:  # describe the return type
                    con = None
                    if cls["namespace"] and "::" not in meth["returns"]:
                        con = self.concrete_typedef(
                            cls["namespace"] + "::" + meth["returns"]
                        )
                    else:
                        con = self.concrete_typedef(meth["returns"])

                    if con:
                        meth["returns_concrete"] = con
                        meth["returns_fundamental"] = is_fundamental(con)

                    elif meth["returns"] in self.classes:
                        trace_print("meth returns class:", meth["returns"])
                        meth["returns_class"] = True

                    elif meth["returns"] in self.SubTypedefs:
                        meth["returns_class"] = True
                        meth["returns_nested"] = self.SubTypedefs[meth["returns"]]

                    elif meth["returns"] in cls._public_enums:
                        enum = cls._public_enums[meth["returns"]]
                        meth["returns_enum"] = enum.get("type")
                        meth["returns_fundamental"] = True
                        if enum.get("type") == int:
                            meth["returns"] = "int"
                        else:
                            meth["returns"] = "char*"

                    elif meth["returns"] in self.global_enums:
                        enum = self.global_enums[meth["returns"]]
                        meth["returns_enum"] = enum.get("type")
                        meth["returns_fundamental"] = True
                        if enum.get("type") == int:
                            meth["returns"] = "int"
                        else:
                            meth["returns"] = "char*"

                    elif meth["returns"].count("::") == 1:
                        trace_print(meth)
                        a, b = meth["returns"].split("::")
                        if a in self.namespaces:
                            if b in self.classes:
                                klass = self.classes[b]
                                meth["returns_class"] = a + "::" + b
                            elif "<" in b and ">" in b:
                                meth["returns_unknown"] = True
                            elif b in self.global_enums:
                                enum = self.global_enums[b]
                                meth["returns_enum"] = enum.get("type")
                                meth["returns_fundamental"] = True
                                if enum.get("type") == int:
                                    meth["returns"] = "int"
                                else:
                                    meth["returns"] = "char*"

                            else:
                                trace_print(a, b)
                                trace_print(meth)
                                meth["returns_unknown"] = True  # +++

                        elif a in self.classes:
                            klass = self.classes[a]
                            if b in klass._public_enums:
                                trace_print("...found nested enum", b)
                                enum = klass._public_enums[b]
                                meth["returns_enum"] = enum.get("type")
                                meth["returns_fundamental"] = True
                                if enum.get("type") == int:
                                    meth["returns"] = "int"
                                else:
                                    meth["returns"] = "char*"

                            elif b in klass._public_forward_declares:
                                meth["returns_class"] = True

                            elif b in klass._public_typedefs:
                                typedef = klass._public_typedefs[b]
                                meth["returns_fundamental"] = is_fundamental(typedef)

                            else:
                                trace_print(
                                    meth
                                )  # should be a nested class, TODO fix me.
                                meth["returns_unknown"] = True

                    elif "::" in meth["returns"]:
                        trace_print("TODO namespace or extra nested return:", meth)
                        meth["returns_unknown"] = True
                    else:
                        trace_print(
                            "WARN: UNKNOWN RETURN", meth["name"], meth["returns"]
                        )
                        meth["returns_unknown"] = True

                if meth["returns"].startswith(":: "):
                    meth["returns"] = meth["returns"].replace(":: ", "::")

        for cls in list(self.classes.values()):
            methnames = cls.get_all_method_names()
            pvm = cls.get_all_pure_virtual_methods()

            for d in cls["inherits"]:
                c = d["class"]
                a = d["access"]  # do not depend on this to be 'public'
                trace_print("PARENT CLASS:", c)
                if c not in self.classes:
                    trace_print("WARN: parent class not found")
                if c in self.classes and self.classes[c]["abstract"]:
                    p = self.classes[c]
                    for meth in p.get_all_methods():  # p["methods"]["public"]:
                        trace_print(
                            "\t\tmeth",
                            meth["name"],
                            "pure virtual",
                            meth["pure_virtual"],
                        )
                        if meth["pure_virtual"] and meth["name"] not in methnames:
                            cls["abstract"] = True
                            break

    _method_type_defaults = {
        n: False
        for n in "defined deleted pure_virtual operator constructor destructor extern template virtual static explicit inline friend returns returns_pointer returns_fundamental returns_class default".split()
    }

    def parse_method_type(self, stack):
        trace_print("meth type info", stack)
        info = {
            "debug": " ".join(stack)
            .replace(" :: ", "::")
            .replace(" < ", "<")
            .replace(" > ", "> ")
            .replace(" >", ">")
            .replace(">>", "> >")
            .replace(">>", "> >"),
            "class": None,
            "namespace": self.cur_namespace(add_double_colon=True),
        }

        info.update(self._method_type_defaults)

        header = stack[: stack.index("(")]
        header = " ".join(header)
        header = header.replace(" :: ", "::")
        header = header.replace(" < ", "<")
        header = header.replace(" > ", "> ")
        header = header.replace("default ", "default")
        header = header.strip()

        if stack[-1] == "{":
            info["defined"] = True
            self._discard_contents("{", "}")
            self.braceHandled = True
        elif stack[-1] == ";":
            info["defined"] = False
        elif stack[-1] == ":":
            info["defined"] = True
            self._discard_ctor_initializer()
            self.braceHandled = True
        else:
            assert 0

        if len(stack) > 3 and stack[-1] == ";" and stack[-3] == "=":
            if stack[-2] == "0":
                info["pure_virtual"] = True
            elif stack[-2] == "delete":
                info["deleted"] = True

        r = header.split()
        name = None
        if "operator" in stack:  # rare case op overload defined outside of class
            op = stack[stack.index("operator") + 1 : stack.index("(")]
            op = "".join(op)
            if not op:
                if " ".join(["operator", "(", ")", "("]) in " ".join(stack):
                    op = "()"
                else:
                    trace_print("Error parsing operator")
                    return None

            info["operator"] = op
            name = "operator" + op
            a = stack[: stack.index("operator")]

        elif r:
            name = r[-1]
            a = r[:-1]  # strip name

        if name is None:
            return None
        # if name.startswith('~'): name = name[1:]

        while a and a[0] == "}":  # strip - can have multiple } }
            a = a[1:]

        if "::" in name:
            # klass,name = name.split('::')    # methods can be defined outside of class
            klass = name[: name.rindex("::")]
            name = name.split("::")[-1]
            info["class"] = klass
            if klass in self.classes and not self.curClass:
                # Class function defined outside the class
                return None
        #    info['name'] = name
        # else: info['name'] = name

        if name.startswith("~"):
            info["destructor"] = True
            if "default;" in stack:
                info["defined"] = True
                info["default"] = True
            name = name[1:]
        elif not a or (name == self.curClass and len(self.curClass)):
            info["constructor"] = True
            if "default;" in stack:
                info["defined"] = True
                info["default"] = True

        info["name"] = name

        for tag in self.C_KEYWORDS:
            if tag in a:
                info[tag] = True
                a.remove(tag)  # inplace
        if "template" in a:
            a.remove("template")
            b = " ".join(a)
            if ">" in b:
                info["template"] = b[: b.index(">") + 1]
                info["returns"] = b[
                    b.index(">") + 1 :
                ]  # find return type, could be incorrect... TODO
                if "<typename" in info["template"].split():
                    typname = info["template"].split()[-1]
                    typname = typname[:-1]  # strip '>'
                    if typname not in self._template_typenames:
                        self._template_typenames.append(typname)
            else:
                info["returns"] = " ".join(a)
        else:
            info["returns"] = " ".join(a)
        info["returns"] = info["returns"].replace(" <", "<").strip()

        ## be careful with templates, do not count pointers inside template
        info["returns_pointer"] = info["returns"].split(">")[-1].count("*")
        if info["returns_pointer"]:
            info["returns"] = info["returns"].replace("*", "").strip()

        info["returns_reference"] = "&" in info["returns"]
        if info["returns"]:
            info["returns"] = info["returns"].replace("&", "").strip()

        a = []
        for b in info["returns"].split():
            if b == "__const__":
                info["returns_const"] = True
            elif b == "const":
                info["returns_const"] = True
            else:
                a.append(b)
        info["returns"] = " ".join(a)

        info["returns_fundamental"] = is_fundamental(info["returns"])
        return info

    def _evaluate_method_stack(self):
        """Create a method out of the name stack"""

        info = self.parse_method_type(self.stack)
        if info:
            if (
                info["class"] and info["class"] in self.classes
            ):  # case where methods are defined outside of class
                newMethod = CppMethod(
                    self.nameStack,
                    info["name"],
                    info,
                    self.curTemplate,
                    self._get_stmt_doxygen(),
                    self._get_location(self.nameStack),
                )
                klass = self.classes[info["class"]]
                klass["methods"]["public"].append(newMethod)
                newMethod["parent"] = klass
                if klass["namespace"]:
                    newMethod["path"] = klass["namespace"] + "::" + klass["name"]
                else:
                    newMethod["path"] = klass["name"]

            elif self.curClass:  # normal case
                newMethod = CppMethod(
                    self.nameStack,
                    self.curClass,
                    info,
                    self.curTemplate,
                    self._get_stmt_doxygen(),
                    self._get_location(self.nameStack),
                )
                klass = self.classes[self.curClass]
                klass["methods"][self.curAccessSpecifier].append(newMethod)
                newMethod["parent"] = klass
                if klass["namespace"]:
                    newMethod["path"] = klass["namespace"] + "::" + klass["name"]
                else:
                    newMethod["path"] = klass["name"]
            else:  # non class functions
                debug_print("FREE FUNCTION")
                newMethod = CppMethod(
                    self.nameStack,
                    None,
                    info,
                    self.curTemplate,
                    self._get_stmt_doxygen(),
                    self._get_location(self.nameStack),
                )
                newMethod["parent"] = None
                self.functions.append(newMethod)
            global parseHistory
            parseHistory.append(
                {
                    "braceDepth": self.braceDepth,
                    "item_type": "method",
                    "item": newMethod,
                }
            )
        else:
            trace_print("free function?", self.nameStack)

        self.stack = []
        self.stmtTokens = []

    def _parse_typedef(self, stack, namespace=""):
        if not stack or "typedef" not in stack:
            return
        stack = list(stack)  # copy just to be safe
        if stack[-1] == ";":
            stack.pop()

        while stack and stack[-1].isdigit():
            stack.pop()  # throw away array size for now

        idx = stack.index("typedef")
        if stack[-1] == "]":
            try:
                name = namespace + "".join(stack[-4:])
                # Strip off the array part so the rest of the parsing is better
                stack = stack[:-3]
            except:
                name = namespace + stack[-1]
        else:
            name = namespace + stack[-1]
        s = ""
        for a in stack[idx + 1 : -1]:
            if a == "{":
                break
            if not s or s[-1] in ":<>" or a in ":<>":
                s += a  # keep compact
            else:
                s += " " + a  # spacing

        r = {"name": name, "raw": s, "type": s}
        if not is_fundamental(s):
            if "struct" in s.split():
                pass  # TODO is this right? "struct ns::something"
            elif "::" not in s:
                s = (
                    namespace + s
                )  # only add the current name space if no namespace given
            r["type"] = s
        if s:
            return r

    def _evaluate_typedef(self):
        ns = self.cur_namespace(add_double_colon=True)
        res = self._parse_typedef(self.stack, ns)
        if res:
            name = res["name"]
            self.typedefs[name] = res["type"]
            if name not in self.typedefs_order:
                self.typedefs_order.append(name)

    def _evaluate_property_stack(self, clearStack=True, addToVar=None):
        """Create a Property out of the name stack"""
        global parseHistory
        debug_print("trace")
        if self.nameStack[0] == "typedef":
            assert self.stack and self.stack[-1] == ";"
            if self.curClass:
                typedef = self._parse_typedef(self.stack)
                name = typedef["name"]
                klass = self.classes[self.curClass]
                klass["typedefs"][self.curAccessSpecifier].append(name)
                if self.curAccessSpecifier == "public":
                    klass._public_typedefs[name] = typedef["type"]
                Resolver.SubTypedefs[name] = self.curClass
            else:
                assert 0
        elif self.curClass:
            if len(self.nameStack) == 1:
                # See if we can de anonymize the type
                filteredParseHistory = [
                    h for h in parseHistory if h["braceDepth"] == self.braceDepth
                ]
                if (
                    len(filteredParseHistory)
                    and filteredParseHistory[-1]["item_type"] == "class"
                ):
                    self.nameStack.insert(0, filteredParseHistory[-1]["item"]["name"])
                    debug_print(
                        "DEANONYMOIZING %s to type '%s'",
                        self.nameStack[1],
                        self.nameStack[0],
                    )
            if "," in self.nameStack:  # Maybe we have a variable list
                # Figure out what part is the variable separator but remember templates of function pointer
                # First find left most comma outside of a > and )
                leftMostComma = 0
                for i in range(0, len(self.nameStack)):
                    name = self.nameStack[i]
                    if name in (">", ")"):
                        leftMostComma = 0
                    if leftMostComma == 0 and name == ",":
                        leftMostComma = i
                # Is it really a list of variables?
                if leftMostComma != 0:
                    trace_print(
                        "Multiple variables for namestack in %s.  Separating processing"
                        % self.nameStack
                    )
                    orig_nameStack = self.nameStack[:]

                    type_nameStack = orig_nameStack[: leftMostComma - 1]
                    for name in orig_nameStack[leftMostComma - 1 :: 2]:
                        self.nameStack = type_nameStack + [name]
                        self._evaluate_property_stack(
                            clearStack=False, addToVar=addToVar
                        )
                    return

            newVar = CppVariable(
                self.nameStack,
                self._get_stmt_doxygen(),
                self._get_location(self.nameStack),
            )
            newVar["namespace"] = self.current_namespace()
            if self.curClass:
                klass = self.classes[self.curClass]
                klass["properties"][self.curAccessSpecifier].append(newVar)
                newVar["property_of_class"] = klass["name"]
                newVar["parent"] = klass
            parseHistory.append(
                {"braceDepth": self.braceDepth, "item_type": "variable", "item": newVar}
            )
            if addToVar:
                newVar.update(addToVar)
        else:
            debug_print("Found Global variable")
            newVar = CppVariable(
                self.nameStack,
                self._get_stmt_doxygen(),
                self._get_location(self.nameStack),
            )
            if addToVar:
                newVar.update(addToVar)
            self.variables.append(newVar)

        if clearStack:
            self.stack = []  # CLEAR STACK
            self.stmtTokens = []

    def _evaluate_class_stack(self):
        """Create a Class out of the name stack (but not its parts)"""
        # dont support sub classes today
        # print( 'eval class stack', self.nameStack )
        parent = self.curClass
        if parent:
            debug_print("found nested subclass")
            self.accessSpecifierStack.append(self.curAccessSpecifier)

        # When dealing with typedefed structs, get rid of typedef keyword to handle later on
        if self.nameStack[0] == "typedef":
            del self.nameStack[0]

        if len(self.nameStack) == 1:
            if self.nameStack[0] == "struct":
                self.anon_struct_counter += 1
                # We cant handle more than 1 anonymous struct, so name them uniquely
                self.nameStack.append("anon-struct-%d" % self.anon_struct_counter)
            elif self.nameStack[0] == "union":
                self.anon_union_counter += 1
                # We cant handle more than 1 anonymous union, so name them uniquely
                self.nameStack.append("anon-union-%d" % self.anon_union_counter)
            elif self.nameStack[0] == "class":
                self.anon_class_counter += 1
                # We cant handle more than 1 anonymous class, so name them uniquely
                self.nameStack.append("anon-class-%d" % self.anon_class_counter)

        if self.nameStack[0] == "class":
            self.curAccessSpecifier = "private"
        else:  # struct/union
            self.curAccessSpecifier = "public"
        debug_print(
            "curAccessSpecifier changed/defaulted to %s", self.curAccessSpecifier
        )
        if self.nameStack[0] == "union":
            newClass = CppUnion(
                self.nameStack,
                self._get_stmt_doxygen(),
                self._get_location(self.nameStack),
            )
        else:
            newClass = CppClass(
                self.nameStack,
                self.curTemplate,
                self._get_stmt_doxygen(),
                self._get_location(self.nameStack),
                self.curAccessSpecifier,
            )
        newClass["declaration_method"] = self.nameStack[0]
        self.classes_order.append(newClass)  # good idea to save ordering
        self.stack = []  # fixes if class declared with ';' in closing brace
        self.stmtTokens = []
        classKey = newClass["name"]

        if parent:
            newClass["namespace"] = self.classes[parent]["namespace"] + "::" + parent
            newClass["parent"] = self.classes[parent]
            newClass["access_in_parent"] = self.accessSpecifierStack[-1]
            self.classes[parent]["nested_classes"].append(newClass)
            ## supports nested classes with the same name ##
            self.curClass = key = parent + "::" + classKey
            self._classes_brace_level[key] = self.braceDepth

        elif newClass["parent"]:  # nested class defined outside of parent.  A::B {...}
            pcls = newClass["parent"]
            parent = pcls["name"]
            newClass["namespace"] = pcls["namespace"] + "::" + parent
            pcls["nested_classes"].append(newClass)
            ## supports nested classes with the same name ##
            self.curClass = key = parent + "::" + classKey
            self._classes_brace_level[key] = self.braceDepth

        else:
            newClass["namespace"] = self.cur_namespace()
            self.curClass = key = classKey
            self._classes_brace_level[classKey] = self.braceDepth

        if not key.endswith("::") and not key.endswith(" ") and len(key) != 0:
            if key in self.classes:
                trace_print("ERROR name collision:", key)
                self.classes[key].show()
                trace_print("-" * 80)
                newClass.show()
                assert key not in self.classes  # namespace collision
        self.classes[key] = newClass
        global parseHistory
        parseHistory.append(
            {"braceDepth": self.braceDepth, "item_type": "class", "item": newClass}
        )

    def evalute_forward_decl(self):
        trace_print("FORWARD DECL", self.nameStack)
        assert self.nameStack[0] in ("class", "struct")
        name = self.nameStack[-1]
        if self.curClass:
            klass = self.classes[self.curClass]
            klass["forward_declares"][self.curAccessSpecifier].append(name)
            if self.curAccessSpecifier == "public":
                klass._public_forward_declares.append(name)
        else:
            self._forward_decls.append(name)


# fmt: off
_namestack_append_tokens = {
    "{",
    "}",
    "[",
    "]",
    "=",
    ",",
    "\\",
    "DIVIDE",
    "|",
    "%",
    "^",
    "!",
    "NUMBER",
    "FLOAT_NUMBER",
    "-",
    "+",
    "STRING_LITERAL",
    "ELLIPSIS",
    "DBL_COLON",
    "SHIFT_LEFT",
}

_namestack_pass_tokens = {
    "'",
    "." # preserve behaviour and eat individual fullstops
}

_namestack_str_tokens = {
    "NAME",
    "&",
    "*",
    "<",
    ">",
    "CHAR_LITERAL"
}
# fmt: on


class CppHeader(_CppHeader):
    """Parsed C++ class header"""

    IGNORE_NAMES = "__extension__".split()

    def show(self):
        for className in list(self.classes.keys()):
            self.classes[className].show()

    def __init__(self, headerFileName, argType="file", encoding=None, **kwargs):
        """Create the parsed C++ header file parse tree

        headerFileName - Name of the file to parse OR actual file contents (depends on argType)
        argType - Indicates how to interpret headerFileName as a file string or file name
        kwargs - Supports the following keywords
        """
        ## reset global state ##
        CppVariable.Vars = []

        if argType == "file":
            self.headerFileName = os.path.expandvars(headerFileName)
            self.mainClass = os.path.split(self.headerFileName)[1][:-2]
            headerFileStr = ""
        elif argType == "string":
            self.headerFileName = ""
            self.mainClass = "???"
            headerFileStr = headerFileName
        else:
            raise Exception("Arg type must be either file or string")
        self.curClass = ""

        # nested classes have parent::nested, but no extra namespace,
        # this keeps the API compatible, TODO proper namespace for everything.
        Resolver.CLASSES = {}

        #: Dictionary of classes found in the header file. The key is the name
        #: of the class, value is :class:`.CppClass`
        self.classes = Resolver.CLASSES

        #: List of free functions as :class:`.CppMethod`
        self.functions = []

        #: List of #pragma directives found as strings
        self.pragmas = []

        #: List of pragmas with location information
        self.pragmas_detail = []

        #: List of #define directives found
        self.defines = []

        #: List of #define directives found, with location information
        self.defines_detail = []

        #: List of #include directives found
        self.includes = []

        #: List of #include directives found with location information
        self.includes_detail = []

        #: Filenames encountered in #line directives while parsing
        self.headerFileNames = []

        self._precomp_macro_buf = (
            []
        )  # for internal purposes, will end up filling out pragmras and defines at the end

        #: List of enums in this header as :class:`.CppEnum`
        self.enums = []

        #: List of variables in this header as :class:`.CppVariable`
        self.variables = []
        self.global_enums = {}
        self.nameStack = []

        #: Namespaces in this header
        self.nameSpaces = []
        self.curAccessSpecifier = "private"  # private is default
        self.curTemplate = None
        self.accessSpecifierStack = []
        debug_print(
            "curAccessSpecifier changed/defaulted to %s", self.curAccessSpecifier
        )
        self.initextra()
        # Old namestacks for a given level
        self.nameStackHistory = []
        self.anon_struct_counter = 0
        self.anon_union_counter = 0
        self.anon_class_counter = 0

        #: Using directives in this header outside of class scope: key is
        #: full name for lookup, value is :class:`.CppVariable`
        self.using = {}

        if len(self.headerFileName):
            fd = io.open(self.headerFileName, "r", encoding=encoding)
            headerFileStr = "".join(fd.readlines())
            fd.close()

        # Make sure supportedAccessSpecifier are sane
        for i in range(0, len(supportedAccessSpecifier)):
            if " " not in supportedAccessSpecifier[i]:
                continue
            supportedAccessSpecifier[i] = re.sub(
                "[ ]+", " ", supportedAccessSpecifier[i]
            ).strip()

        # Change multi line #defines and expressions to single lines maintaining line nubmers
        # Based from http://stackoverflow.com/questions/2424458/regular-expression-to-match-cs-multiline-preprocessor-statements
        matches = re.findall(r"(?m)^(?:.*\\\r?\n)+.*$", headerFileStr)
        is_define = re.compile(r"[ \t\v]*#[Dd][Ee][Ff][Ii][Nn][Ee]")
        for m in matches:
            # Keep the newlines so that linecount doesnt break
            num_newlines = len([a for a in m if a == "\n"])
            if is_define.match(m):
                new_m = m.replace("\n", "<CppHeaderParser_newline_temp_replacement>\\n")
            else:
                # Just expression taking up multiple lines, make it take 1 line for easier parsing
                new_m = m.replace("\\\n", " ")
            if num_newlines > 0:
                new_m += "\n" * (num_newlines)
            headerFileStr = headerFileStr.replace(m, new_m)

        # Filter out Extern "C" statements.  These are order dependent
        matches = re.findall(
            re.compile(r'extern[\t ]+"[Cc]"[\t \n\r]*{', re.DOTALL), headerFileStr
        )
        for m in matches:
            # Keep the newlines so that linecount doesnt break
            num_newlines = len([a for a in m if a == "\n"])
            headerFileStr = headerFileStr.replace(m, "\n" * num_newlines)
        headerFileStr = re.sub(r'extern[ ]+"[Cc]"[ ]*', "", headerFileStr)

        # Filter out any ignore symbols that end with "()" to account for #define magic functions
        for ignore in ignoreSymbols:
            if not ignore.endswith("()"):
                continue
            while True:
                locStart = headerFileStr.find(ignore[:-1])
                if locStart == -1:
                    break
                locEnd = None
                # Now walk till we find the last paren and account for sub parens
                parenCount = 1
                inQuotes = False
                for i in range(locStart + len(ignore) - 1, len(headerFileStr)):
                    c = headerFileStr[i]
                    if not inQuotes:
                        if c == "(":
                            parenCount += 1
                        elif c == ")":
                            parenCount -= 1
                        elif c == '"':
                            inQuotes = True
                        if parenCount == 0:
                            locEnd = i + 1
                            break
                    else:
                        if c == '"' and headerFileStr[i - 1] != "\\":
                            inQuotes = False

                if locEnd:
                    # Strip it out but keep the linecount the same so line numbers are right
                    match_str = headerFileStr[locStart:locEnd]
                    debug_print("Striping out '%s'", match_str)
                    num_newlines = len([a for a in match_str if a == "\n"])
                    headerFileStr = headerFileStr.replace(
                        headerFileStr[locStart:locEnd], "\n" * num_newlines
                    )

        self.braceDepth = 0

        lex = Lexer(self.headerFileName)
        lex.input(headerFileStr)
        self.lex = lex
        self.headerFileNames = lex.filenames

        #
        # A note on parsing methodology
        #
        # The idea here is to consume as many tokens as needed to determine
        # what the thing is that we're parsing. While some items can be identified
        # early, typically the code below consumes until a '{', '}', or ; and
        # then looks at the accumulated tokens to figure out what it is.
        #
        # Unfortunately, the code isn't always particularly consistent (but
        # it's slowly getting there!), so take this with a grain of salt.
        #

        self._doxygen_cache = None
        self.braceHandled = False
        tok = None
        self.stmtTokens = []
        parenDepth = 0

        try:
            while True:
                tok = lex.token(eof_ok=True)
                if not tok:
                    break
                tok.value = TagStr(tok.value, location=tok.location)

                # debug_print("TOK: %s", tok)
                if tok.type == "NAME":
                    if tok.value in self.IGNORE_NAMES:
                        continue
                    elif tok.value == "template":
                        self._doxygen_cache = self.lex.get_doxygen()
                        self._parse_template()
                        continue
                    elif tok.value == "alignas":
                        self._parse_attribute_specifier_seq(tok)
                        continue
                    elif tok.value == "__attribute__":
                        self._parse_gcc_attribute()
                        continue
                    elif not self.stack and tok.value == "static_assert":
                        self._next_token_must_be("(")
                        self._discard_contents("(", ")")
                        continue

                elif tok.type == "DBL_LBRACKET":
                    self._parse_attribute_specifier_seq(tok)
                    continue

                # TODO: get rid of stack, move to stmtTokens
                self.stack.append(tok.value)
                self.stmtTokens.append(tok)

                nslen = len(self.nameStack)

                if tok.type in ("PRECOMP_MACRO", "PRECOMP_MACRO_CONT"):
                    debug_print("PRECOMP: %s", tok)
                    self._precomp_macro_buf.append((tok.value, tok.location))
                    self.stack = []
                    self.stmtTokens = []
                    self.nameStack = []
                    continue

                if parenDepth == 0 and tok.type == "{":
                    if len(self.nameStack) >= 2 and is_namespace(
                        self.nameStack
                    ):  # namespace {} with no name used in boost, this sets default?
                        if (
                            self.nameStack[1]
                            == "__IGNORED_NAMESPACE__CppHeaderParser__"
                        ):  # Used in filtering extern "C"
                            self.nameStack[1] = ""
                        self.nameSpaces.append(self.nameStack[1])
                        ns = self.cur_namespace()
                        self.stack = []
                        self.stmtTokens = []
                        if ns not in self.namespaces:
                            self.namespaces.append(ns)
                    # Detect special condition of macro magic before class declaration so we
                    # can filter it out
                    if "class" in self.nameStack and self.nameStack[0] != "class":
                        classLocationNS = self.nameStack.index("class")
                        classLocationS = self.stack.index("class")
                        if (
                            "(" not in self.nameStack[classLocationNS:]
                            and self.nameStack[classLocationNS - 1] != "enum"
                        ):
                            debug_print(
                                "keyword 'class' found in unexpected location in nameStack, must be following #define magic.  Process that before moving on"
                            )
                            origNameStack = self.nameStack
                            origStack = self.stack
                            # Process first part of stack which is probably #define macro magic and may cause issues
                            self.nameStack = self.nameStack[:classLocationNS]
                            self.stack = self.stack[:classLocationS]
                            try:
                                self._evaluate_stack()
                            except:
                                debug_print("Error processing #define magic... Oh well")
                            # Process rest of stack
                            self.nameStack = origNameStack[classLocationNS:]
                            self.stack = origStack[classLocationS:]

                    # If set to True, indicates that the callee consumed
                    # all of the tokens between { and }
                    self.braceHandled = False
                    if self.nameStack:
                        self._evaluate_stack()
                    if self.stack and self.stack[0] == "class":
                        self.stack = []
                        self.stmtTokens = []
                    if not self.braceHandled:
                        self.braceDepth += 1

                elif parenDepth == 0 and tok.type == "}":
                    if self.braceDepth == 0:
                        continue
                    if self.braceDepth == len(self.nameSpaces):
                        tmp = self.nameSpaces.pop()
                        self.stack = []  # clear stack when namespace ends?
                        self.stmtTokens = []
                    else:
                        self._evaluate_stack()
                    self.braceDepth -= 1

                    # if self.curClass:
                    #     debug_print(
                    #         "CURBD %s", self._classes_brace_level[self.curClass]
                    #     )

                    if (self.braceDepth == 0) or (
                        self.curClass
                        and self._classes_brace_level[self.curClass] == self.braceDepth
                    ):
                        trace_print("END OF CLASS DEF")
                        if self.accessSpecifierStack:
                            self.curAccessSpecifier = self.accessSpecifierStack[-1]
                            self.accessSpecifierStack = self.accessSpecifierStack[:-1]
                        if self.curClass and self.classes[self.curClass]["parent"]:
                            thisClass = self.classes[self.curClass]
                            self.curClass = self.curClass[
                                : -(len(thisClass["name"]) + 2)
                            ]

                            # Detect anonymous union members
                            if (
                                self.curClass
                                and thisClass["declaration_method"] == "union"
                                and thisClass["name"].startswith("<")
                                and self.lex.token_if(";")
                            ):
                                debug_print("Creating anonymous union")
                                # Force the processing of an anonymous union
                                self.nameStack = [""]
                                self.stack = self.nameStack + [";"]
                                debug_print("pre eval anon stack")
                                self._evaluate_stack(";")
                                debug_print("post eval anon stack")
                                self.stack = []
                                self.nameStack = []
                                self.stmtTokens = []
                        else:
                            self.curClass = ""
                        self.stack = []
                        self.stmtTokens = []
                elif tok.type in _namestack_append_tokens:
                    self.nameStack.append(tok.value)
                    nameStackAppended = True
                elif tok.type in _namestack_pass_tokens:
                    pass
                elif tok.type in _namestack_str_tokens:
                    if tok.value in ignoreSymbols:
                        debug_print("Ignore symbol %s", tok.value)
                    elif tok.value == "class":
                        self.nameStack.append(tok.value)
                    else:
                        self.nameStack.append(tok.value)
                elif tok.type == ":":
                    if self.nameStack and self.nameStack[0] in supportedAccessSpecifier:
                        specifier = " ".join(self.nameStack)
                        if specifier in supportedAccessSpecifier:
                            self.curAccessSpecifier = specifier
                        else:
                            self.curAccessSpecifier = self.nameStack[0]
                        debug_print(
                            "curAccessSpecifier updated to %s", self.curAccessSpecifier
                        )
                        self.nameStack = []
                        self.stack = []
                        self.stmtTokens = []
                    elif is_method_namestack(self.stack):
                        debug_print("trace")
                        self._evaluate_method_stack()
                        self.nameStack = []
                        self.stack = []
                        self.stmtTokens = []
                    else:
                        self.nameStack.append(tok.value)

                elif tok.type == ";":
                    self._evaluate_stack(tok.type)
                    self.stack = []
                    self.nameStack = []
                    self.stmtTokens = []
                elif tok.type == "(":
                    parenDepth += 1
                    self.nameStack.append(tok.value)
                    nameStackAppended = True
                elif tok.type == ")":
                    self.nameStack.append(tok.value)
                    nameStackAppended = True
                    if parenDepth != 0:
                        parenDepth -= 1

                newNsLen = len(self.nameStack)
                if nslen != newNsLen and newNsLen == 1:
                    if not self.curTemplate:
                        self._doxygen_cache = self.lex.get_doxygen()

        except Exception as e:
            if debug:
                raise
            context = ""
            if isinstance(e, CppParseError):
                context = ": " + str(e)
                if e.tok:
                    tok = e.tok

            if tok:
                filename, lineno = tok.location
                msg = (
                    "Not able to parse %s on line %d evaluating '%s'%s\nError around: %s"
                    % (filename, lineno, tok.value, context, " ".join(self.nameStack))
                )
            else:
                msg = "Error parsing %s%s\nError around: %s" % (
                    self.headerFileName,
                    context,
                    " ".join(self.nameStack),
                )

            raise_exc(
                CppParseError(msg),
                e,
            )

        self.finalize()
        global parseHistory
        parseHistory = []
        # Delete some temporary variables
        for key in [
            "_precomp_macro_buf",
            "_doxygen_cache",
            "braceHandled",
            "lex",
            "nameStack",
            "nameSpaces",
            "curAccessSpecifier",
            "accessSpecifierStack",
            "nameStackHistory",
            "anon_struct_counter",
            "anon_union_counter",
            "anon_class_counter",
            "_classes_brace_level",
            "_forward_decls",
            "stack",
            "mainClass",
            "_template_typenames",
            "braceDepth",
            "stmtTokens",
            "typedefs_order",
            "curTemplate",
        ]:
            del self.__dict__[key]

    def _get_location(self, stack):
        if stack:
            location = getattr(stack[0], "location", None)
            if location is not None:
                return location

        return self.lex.current_location()

    def _get_stmt_doxygen(self):
        # retrieves the doxygen comment associated with an accumulated
        # statement (since doxygen comments have to be retrieved immediately)
        doxygen, self._doxygen_cache = self._doxygen_cache, ""
        if not doxygen:
            doxygen = self.lex.get_doxygen()
        return doxygen

    def _parse_error(self, tokens, expected):
        if not tokens:
            # common case after a failed token_if
            errtok = self.lex.token()
        else:
            errtok = tokens[-1]
        if expected:
            expected = ", expected '" + expected + "'"

        msg = "unexpected '%s'%s" % (errtok.value, expected)

        # TODO: better error message
        return CppParseError(msg, errtok)

    def _next_token_must_be(self, *tokenTypes):
        tok = self.lex.token()
        if tok.type not in tokenTypes:
            raise self._parse_error((tok,), "' or '".join(tokenTypes))
        return tok

    _end_balanced_tokens = {">", "}", "]", ")", "DBL_RBRACKET"}
    _balanced_token_map = {
        "<": ">",
        "{": "}",
        "(": ")",
        "[": "]",
        "DBL_LBRACKET": "DBL_RBRACKET",
    }

    def _consume_balanced_tokens(self, *init_tokens):

        _balanced_token_map = self._balanced_token_map

        consumed = list(init_tokens)
        match_stack = deque((_balanced_token_map[tok.type] for tok in consumed))
        get_token = self.lex.token

        while True:
            tok = get_token()
            consumed.append(tok)

            if tok.type in self._end_balanced_tokens:
                expected = match_stack.pop()
                if tok.type != expected:
                    # hack: ambiguous right-shift issues here, really
                    # should be looking at the context
                    if tok.type == ">":
                        tok = self.lex.token_if(">")
                        if tok:
                            consumed.append(tok)
                            match_stack.append(expected)
                            continue

                    raise self._parse_error(consumed, expected)
                if len(match_stack) == 0:
                    return consumed

                continue

            next_end = _balanced_token_map.get(tok.type)
            if next_end:
                match_stack.append(next_end)

    def _discard_contents(self, start_type, end_type):
        # use this instead of consume_balanced_tokens because
        # we don't care at all about the internals
        level = 1
        get_token = self.lex.token
        while True:
            tok = get_token()
            if tok.type == start_type:
                level += 1
            elif tok.type == end_type:
                level -= 1
                if level == 0:
                    break

    def _discard_ctor_initializer(self):
        """
        ctor_initializer: ":" mem_initializer_list

        mem_initializer_list: mem_initializer ["..."]
                            | mem_initializer "," mem_initializer_list ["..."]

        mem_initializer: mem_initializer_id "(" [expression_list] ")"
                       | mem_initializer_id braced_init_list

        mem_initializer_id: class_or_decltype
                          | IDENTIFIER
        """
        debug_print("discarding ctor intializer")
        # all of this is discarded.. the challenge is to determine
        # when the initializer ends and the function starts
        while True:
            tok = self.lex.token()
            if tok.type == "DBL_COLON":
                tok = self.lex.token()

            if tok.type == "decltype":
                tok = self._next_token_must_be("(")
                self._consume_balanced_tokens(tok)
                tok = self.lex.token()

            # each initializer is either foo() or foo{}, so look for that
            while True:
                if tok.type not in ("{", "("):
                    tok = self.lex.token()
                    continue

                if tok.type == "{":
                    self._discard_contents("{", "}")
                elif tok.type == "(":
                    self._discard_contents("(", ")")

                tok = self.lex.token()
                break

            # at the end
            if tok.type == "ELLIPSIS":
                tok = self.lex.token()

            if tok.type == ",":
                continue
            elif tok.type == "{":
                # reached the function
                self._discard_contents("{", "}")
                return
            else:
                raise self._parse_error((tok,), ",' or '{")

    def _evaluate_stack(self, token=None):
        """Evaluates the current name stack"""

        nameStackCopy = self.nameStack[:]

        debug_print(
            "Evaluating stack %s\n       BraceDepth: %s (called from %d)",
            self.nameStack,
            self.braceDepth,
            inspect.currentframe().f_back.f_lineno,
        )

        # Handle special case of overloading operator ()
        if "operator()(" in "".join(self.nameStack):
            operator_index = self.nameStack.index("operator")
            self.nameStack.pop(operator_index + 2)
            self.nameStack.pop(operator_index + 1)
            self.nameStack[operator_index] = "operator()"

        if len(self.curClass):
            debug_print("%s (%s) ", self.curClass, self.curAccessSpecifier)
        else:
            debug_print("<anonymous> (%s) ", self.curAccessSpecifier)

        # Filter special case of array with casting in it
        try:
            bracePos = self.nameStack.index("[")
            parenPos = self.nameStack.index("(")
            if bracePos == parenPos - 1:
                endParen = self.nameStack.index(")")
                self.nameStack = (
                    self.nameStack[: bracePos + 1] + self.nameStack[endParen + 1 :]
                )
                debug_print("Filtered namestack to=%s", self.nameStack)
        except:
            pass

        # if 'typedef' in self.nameStack: self._evaluate_typedef()        # allows nested typedefs, probably a bad idea
        if (
            not self.curClass
            and "typedef" in self.nameStack
            and (
                (
                    "struct" not in self.nameStack
                    and "union" not in self.nameStack
                    and "enum" not in self.nameStack
                )
                or self.stack[-1] == ";"
            )
        ):
            debug_print("trace")
            trace_print("typedef %s", self.stack)
            self._evaluate_typedef()
            return

        elif len(self.nameStack) == 0:
            debug_print("trace (Empty Stack)")
            return
        elif self.nameStack[0] == "namespace":
            # Taken care of outside of here
            pass
        elif len(self.nameStack) == 2 and self.nameStack[0] == "extern":
            debug_print("trace extern")
            self.stack = []
            self.stmtTokens = []
        elif (
            len(self.nameStack) == 2 and self.nameStack[0] == "friend"
        ):  # friend class declaration
            pass
        elif len(self.nameStack) >= 2 and self.nameStack[0] == "using":
            if self.nameStack[1] == "namespace":
                pass
            else:
                if len(self.nameStack) > 3 and self.nameStack[2] == "=":
                    # using foo = ns::bar
                    # -> type alias: same behavior in all scopes
                    alias = self.nameStack[1]
                    ns, stack = _split_namespace(self.nameStack[3:])
                    atype = CppVariable(
                        stack, self._get_stmt_doxygen(), self._get_location(stack)
                    )

                    # namespace refers to the embedded type
                    atype["namespace"] = ns
                    atype["using_type"] = "typealias"
                    atype["typealias"] = alias
                else:
                    # using foo::bar
                    # -> in global scope this is bringing in something
                    #    from a different namespace
                    # -> in class scope this is bringing in a member
                    #    from a base class
                    ns, stack = _split_namespace(self.nameStack[1:])
                    atype = CppVariable(
                        stack, self._get_stmt_doxygen(), self._get_location(stack)
                    )
                    alias = atype["type"]
                    atype["using_type"] = "declaration"
                    if self.curClass:
                        atype["baseclass"] = ns
                    else:
                        atype["namespace"] = ns

                atype["raw_type"] = ns + atype["type"]

                if self.curClass:
                    klass = self.classes[self.curClass]
                    klass["using"][alias] = atype
                else:
                    # lookup is done
                    alias = self.current_namespace() + alias
                    self.using[alias] = atype
        elif is_method_namestack(self.stack) and "(" in self.nameStack:
            debug_print("trace")
            self._evaluate_method_stack()
        elif is_enum_namestack(self.nameStack):
            debug_print("trace")
            self._parse_enum()
            self.stack = []
            self.stmtTokens = []
        elif (
            len(self.nameStack) == 1
            and len(self.nameStackHistory) > self.braceDepth
            and (
                self.nameStackHistory[self.braceDepth][0][0:2] == ["typedef", "struct"]
                or self.nameStackHistory[self.braceDepth][0][0:2]
                == ["typedef", "union"]
            )
        ):
            # Look for the name of a typedef struct: struct typedef {...] StructName; or unions to get renamed
            debug_print("found the naming of a union")
            type_name_to_rename = self.nameStackHistory[self.braceDepth][1]
            new_name = self.nameStack[0]
            type_to_rename = self.classes[type_name_to_rename]
            type_to_rename["name"] = self.nameStack[0]
            # Now re install it in its new location
            self.classes[new_name] = type_to_rename
            if new_name != type_name_to_rename:
                del self.classes[type_name_to_rename]
        elif is_property_namestack(self.nameStack) and self.stack[-1] == ";":
            debug_print("trace")
            if self.nameStack[0] in ("class", "struct") and len(self.stack) == 3:
                self.evalute_forward_decl()
            elif len(self.nameStack) >= 2 and (
                self.nameStack[0] == "friend" and self.nameStack[1] == "class"
            ):
                pass
            else:
                self._evaluate_property_stack()  # catches class props and structs in a namespace

        elif (
            self.nameStack[0] in ("class", "struct", "union")
            or self.nameStack[0] == "typedef"
            and self.nameStack[1] in ("struct", "union")
        ):
            # Parsing a union can reuse much of the class parsing
            debug_print("trace")
            self._evaluate_class_stack()

        elif not self.curClass:
            debug_print("trace")
        elif self.braceDepth < 1:
            debug_print("trace")
            # Ignore global stuff for now
            debug_print("Global stuff: %s" % self.nameStack)
        elif self.braceDepth > len(self.nameSpaces) + 1:
            debug_print("trace")
        else:
            debug_print("Discarded statement %s" % (self.nameStack,))

        try:
            self.nameStackHistory[self.braceDepth] = (nameStackCopy, self.curClass)
        except:
            self.nameStackHistory.append((nameStackCopy, self.curClass))

        # its a little confusing to have some if/else above return and others not, and then clearning the nameStack down here
        self.nameStack = []
        self.lex.doxygenCommentCache = ""
        self.curTemplate = None

    def _parse_template(self):
        tok = self._next_token_must_be("<")
        consumed = self._consume_balanced_tokens(tok)
        tmpl = " ".join(tok.value for tok in consumed)
        tmpl = (
            tmpl.replace(" :: ", "::")
            .replace(" <", "<")
            .replace("< ", "<")
            .replace(" >", ">")
            .replace("> ", ">")
            .replace(" , ", ", ")
            .replace(" = ", "=")
        )
        self.curTemplate = "template" + tmpl

    def _parse_gcc_attribute(self):
        tok1 = self._next_token_must_be("(")
        tok2 = self._next_token_must_be("(")
        self._consume_balanced_tokens(tok1, tok2)

    _attribute_specifier_seq_start_types = ("DBL_LBRACKET", "NAME")
    _attribute_specifier_seq_start_values = ("[[", "alignas")

    def _parse_attribute_specifier_seq(self, tok):
        # TODO: retain the attributes and do something with them
        # attrs = []

        while True:
            if tok.type == "DBL_LBRACKET":
                tokens = self._consume_balanced_tokens(tok)
                # attrs.append(Attribute(tokens))
            elif tok.type == "NAME" and tok.value == "alignas":
                next_tok = self._next_token_must_be("(")
                tokens = self._consume_balanced_tokens(next_tok)
                # attrs.append(AlignasAttribute(tokens))
            else:
                self.lex.return_token(tok)
                break

            # multiple attributes can be specified
            tok = self.lex.token_if(*self._attribute_specifier_seq_start_types)
            if tok is None:
                break

        # return attrs

    def _parse_enum(self):
        """
        opaque_enum_declaration: enum_key [attribute_specifier_seq] IDENTIFIER [enum_base] ";"

        enum_specifier: enum_head "{" [enumerator_list] "}"
                      | enum_head "{" enumerator_list "," "}"

        enum_head: enum_key [attribute_specifier_seq] [IDENTIFIER] [enum_base]
                 | enum_key [attribute_specifier_seq] nested_name_specifier IDENTIFIER [enum_base]

        enum_key: "enum"
                | "enum" "class"
                | "enum" "struct"

        enum_base: ":" type_specifier_seq
        """
        debug_print("parsing enum")

        is_typedef = False
        self.lex.return_tokens(self.stmtTokens)

        doxygen = self._get_stmt_doxygen()

        tok = self.lex.token()
        if tok.value == "typedef":
            is_typedef = True
            tok = self.lex.token()

        if tok.value != "enum":
            raise self._parse_error((tok,), "enum")

        location = tok.location

        is_class = False
        nametok = self.lex.token()
        if nametok.value in ("class", "struct"):
            is_class = True
            nametok = self.lex.token()

        if nametok.value == "__attribute__":
            self._parse_gcc_attribute()
            nametok = self.lex.token()

        if nametok.value in self._attribute_specifier_seq_start_values:
            self._parse_attribute_specifier_seq(nametok)
            nametok = self.lex.token()

        # TODO: nested_name_specifier
        name = ""
        if nametok.type == "NAME":
            name = nametok.value
            debug_print("enum name is '%s'", name)
            tok = self.lex.token()
        else:
            debug_print("anonymous enum")
            tok = nametok

        base = []
        if tok.type == ":":
            while True:
                tok = self.lex.token()
                if tok.type in ("{", ";"):
                    break
                base.append(tok.value)

        newEnum = CppEnum(name, doxygen, location)
        if is_typedef:
            newEnum["typedef"] = True
        if is_class:
            newEnum["isclass"] = True
        if base:
            newEnum["type"] = "".join(base)

        instancesData = []

        if tok.type == "{":
            self.braceHandled = True
            self._parse_enumerator_list(newEnum["values"])
            newEnum.resolve_enum_values(newEnum["values"])
            tok = self.lex.token()

        if tok.value == "__attribute__":
            self._parse_gcc_attribute()
            tok = self.lex.token()

        if tok.type == "NAME":
            if newEnum["typedef"]:
                newEnum["name"] = tok.value
                self._next_token_must_be(";")
            else:
                # this is an instance of the enum
                instancesData.append(tok.value)
                while True:
                    tok = self.lex.token()
                    if tok.type == ";":
                        break
                    instancesData.append(tok.value)
        elif tok.type != ";":
            raise self._parse_error((tok,), ";")

        self._install_enum(newEnum, instancesData)

    def _install_enum(self, newEnum, instancesData):
        if len(self.curClass):
            newEnum["namespace"] = self.cur_namespace(False)
            klass = self.classes[self.curClass]
            klass["enums"][self.curAccessSpecifier].append(newEnum)
            if self.curAccessSpecifier == "public" and "name" in newEnum:
                klass._public_enums[newEnum["name"]] = newEnum
        else:
            newEnum["namespace"] = self.cur_namespace(True)
            self.enums.append(newEnum)
            if "name" in newEnum and newEnum["name"]:
                self.global_enums[newEnum["name"]] = newEnum

        # This enum has instances, turn them into properties
        if instancesData:
            instances = list(_split_by_comma(instancesData))
            instanceType = "enum"
            if "name" in newEnum:
                instanceType = newEnum["name"]
            addToVar = {"enum_type": newEnum}
            for instance in instances:
                self.nameStack = [instanceType] + instance
                self._evaluate_property_stack(clearStack=False, addToVar=addToVar)

    def _parse_enumerator_list(self, values):
        """
        enumerator_list: enumerator_definition
                       | enumerator_list "," enumerator_definition

        enumerator_definition: enumerator
                             | enumerator "=" constant_expression

        enumerator: IDENTIFIER
        """
        while True:
            name_tok = self._next_token_must_be("}", "NAME")
            if name_tok.value == "}":
                return

            value = {"name": name_tok.value}
            doxygen = self.lex.get_doxygen()
            if doxygen:
                value["doxygen"] = doxygen
            values.append(value)

            debug_print("enumerator value '%s'", value["name"])

            tok = self._next_token_must_be("}", ",", "=", "DBL_LBRACKET")
            if tok.type == "DBL_LBRACKET":
                self._parse_attribute_specifier_seq(tok)
                tok = self._next_token_must_be("}", ",", "=")

            if tok.type == "}":
                return
            elif tok.type == ",":
                continue
            elif tok.type == "=":
                v = []
                while True:
                    tok = self.lex.token()
                    if tok.type == "}":
                        value["value"] = " ".join(v)
                        return
                    elif tok.type == ",":
                        value["value"] = " ".join(v)
                        break
                    elif tok.type in self._balanced_token_map:
                        v.extend(t.value for t in self._consume_balanced_tokens(tok))
                    else:
                        v.append(tok.value)

    def _strip_parent_keys(self):
        """Strip all parent (and method) keys to prevent loops"""
        obj_queue = [self]
        while len(obj_queue):
            obj = obj_queue.pop()
            trace_print("pop %s type %s" % (obj, type(obj)))
            try:
                if "parent" in obj.keys():
                    del obj["parent"]
                    trace_print("Stripped parent from %s" % obj.keys())
            except:
                pass
            try:
                if "method" in obj.keys():
                    del obj["method"]
                    trace_print("Stripped method from %s" % obj.keys())
            except:
                pass
            # Figure out what sub types are one of ours
            try:
                if not hasattr(obj, "keys"):
                    obj = obj.__dict__
                for k in obj.keys():
                    trace_print("-Try key %s" % (k))
                    trace_print("-type  %s" % (type(obj[k])))
                    if k in ["nameStackHistory", "parent", "_public_typedefs"]:
                        continue
                    if type(obj[k]) == list:
                        for i in obj[k]:
                            trace_print("push l %s" % i)
                            obj_queue.append(i)
                    elif type(obj[k]) == dict:
                        if len(obj):
                            trace_print("push d %s" % obj[k])
                            obj_queue.append(obj[k])
                    elif type(obj[k]) == type(type(0)):
                        if type(obj[k]) == int:
                            obj[k] = "int"
                        elif type(obj[k]) == str:
                            obj[k] = "string"
                        else:
                            obj[k] = "???"
                    trace_print("next key\n")
            except:
                trace_print("Exception")

    def toJSON(self, indent=4, separators=None):
        """Converts a parsed structure to JSON"""
        import json

        self._strip_parent_keys()
        try:
            del self.__dict__["classes_order"]
        except:
            pass
        return json.dumps(self.__dict__, indent=indent, separators=separators)

    def __repr__(self):
        rtn = {
            "classes": self.classes,
            "functions": self.functions,
            "enums": self.enums,
            "variables": self.variables,
        }
        return repr(rtn)

    def __str__(self):
        rtn = ""
        for className in list(self.classes.keys()):
            rtn += "%s\n" % self.classes[className]
        if self.functions:
            rtn += "// functions\n"
            for f in self.functions:
                rtn += "%s\n" % f
        if self.variables:
            rtn += "// variables\n"
            for f in self.variables:
                rtn += "%s\n" % f
        if self.enums:
            rtn += "// enums\n"
            for f in self.enums:
                rtn += "%s\n" % f
        return rtn
