#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
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

from reg import Registry


# TODO: Remove it in the future
class DX12Registry(Registry):

    # Method override
    def apiGen(self):
        """Generate interface for specified versions using the current
        generator and generator options"""
        # The purpose is to remove a warning msg: WARNING: No matching API versions found!
        self.gen.logMsg('diag', '**************************************')
        self.gen.logMsg('diag', '  Registry.apiGen file:',
                        self.genOpts.filename,
                        'api:', self.genOpts.apiname,
                        'profile:', self.genOpts.profile)
        self.gen.logMsg('diag', '**************************************')

        # Reset required/declared flags for all features
        self.apiReset()

        self.gen.beginFile(self.genOpts)
        self.gen.beginFeature({}, False)
        self.gen.genType()
        self.gen.generateFeature()
        self.gen.endFeature()
        self.gen.endFile()
