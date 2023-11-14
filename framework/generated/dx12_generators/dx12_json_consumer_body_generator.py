#!/usr/bin/env python3
#
# Copyright (c) 2021, 2023 LunarG, Inc.
# Copyright (c) 2023 Valve Corporation
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

import json
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator, Dx12GeneratorOptions
from dx12_json_consumer_header_generator import Dx12JsonConsumerHeaderGenerator, Dx12JsonConsumerHeaderGeneratorOptions
from reformat_code import format_cpp_code, remove_leading_empty_lines


class Dx12JsonBodyGeneratorOptions(Dx12JsonConsumerHeaderGeneratorOptions):

    def __init__(
        self,
        constructor_args,
        # Path to JSON file listing Vulkan API calls to override on capture.
        json_overrides=None,
        # Path to JSON file listing apicalls and structs to ignore.
        blacklists=None,
        # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        platform_types=None,
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True
    ):
        Dx12JsonConsumerHeaderGeneratorOptions.__init__(
            self, constructor_args, blacklists, platform_types, filename,
            directory, prefix_text, protect_file, protect_feature
        )
        self.json_overrides = json_overrides


class Dx12JsonConsumerBodyGenerator(Dx12JsonConsumerHeaderGenerator):

    JSON_OVERRIDES = {}

    def beginFile(self, genOpts):
        # The following functions/methods may require custom handling
        # @todo Turn Evaluate each of these, turn them back on in a blocklists.json and write the code to deal with them.
        # -- self.APICALL_BLACKLIST.append('D3D12CreateRootSignatureDeserializer')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12RootSignatureDeserializer_GetRootSignatureDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Heap_GetDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Resource_GetDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12DescriptorHeap_GetDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12CommandQueue_GetDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device_GetResourceAllocationInfo')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device_GetCustomHeapProperties')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device_GetAdapterLuid')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12ProtectedResourceSession_GetDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device4_GetResourceAllocationInfo1')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12GraphicsCommandList_ResourceBarrier')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12InfoQueue_GetMessage')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12InfoQueue_GetStorageFilter')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12InfoQueue_GetRetrievalFilter')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device_CreateRootSignature')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12CommandList_GetType')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device1_CreatePipelineLibrary')
        Dx12JsonConsumerHeaderGenerator.beginFile(self, genOpts)
        if genOpts.json_overrides:
            overrides = json.loads(open(genOpts.json_overrides, 'r').read())
            self.JSON_OVERRIDES = overrides

    def write_include(self):
        write(format_cpp_code('''
            /// @todo Optimise this include list. Pos, only include most specific [util|decode]/x_json_util.h variant since we have the convention that they include each other.
            #include "generated_dx12_json_consumer.h"
            #include "generated_dx12_enum_to_json.h"
            #include "generated_dx12_struct_decoders_to_json.h"
            #include "decode/dx12_enum_util.h"
            #include "decode/dx12_decode_json_util.h"
            #include "decode/decode_json_util.h"
            #include "decode/json_writer.h"
            #include "util/to_string.h"
            #include "format/format_json.h"

            #include <winerror.h> // D3D12 and DXGI HRESULT return values.
            // Still needed for D3D12 return values <https://learn.microsoft.com/en-us/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues>
            #include <d3d9.h>
            #include <unordered_map>

        '''), file=self.outFile)
        self.newline()

    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)
        write(format_cpp_code('''
            // const char * might be better to avoid two copies of each string in the process at runtime (one in the static data section for the literal string and one on the heap in the map).
            // Even better would be for this to be a const array of pairs of HRESULT and const char*const with a flat_map style adaptor so the "map" itself could live in the const data section rather than being heap allocated as it is now.
            const static std::unordered_map<HRESULT, std::string> kHresults {
                // Basic names for zero and one from <winerror.h> also used by D3D12:
                {S_OK, "S_OK"},
                {S_FALSE,"S_FALSE"},
                // D3D12 Errors from <winerror.h>:
                // <https://learn.microsoft.com/en-us/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues>
                {D3D12_ERROR_ADAPTER_NOT_FOUND, "D3D12_ERROR_ADAPTER_NOT_FOUND"},
                {D3D12_ERROR_DRIVER_VERSION_MISMATCH, "D3D12_ERROR_DRIVER_VERSION_MISMATCH"},
                {D3D12_ERROR_INVALID_REDIST, "D3D12_ERROR_INVALID_REDIST"},
                // D3D9 Errors inherited by D3D12:
                {D3DERR_INVALIDCALL, "D3DERR_INVALIDCALL"},
                {D3DERR_WASSTILLDRAWING, "D3DERR_WASSTILLDRAWING"},
                // DXGI Errors from <winerror.h>:
                // https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/dxgi-error
                {DXGI_ERROR_ACCESS_DENIED, "DXGI_ERROR_ACCESS_DENIED"},
                {DXGI_ERROR_ACCESS_LOST, "DXGI_ERROR_ACCESS_LOST"},
                {DXGI_ERROR_ALREADY_EXISTS, "DXGI_ERROR_ALREADY_EXISTS"},
                {DXGI_ERROR_CANNOT_PROTECT_CONTENT, "DXGI_ERROR_CANNOT_PROTECT_CONTENT"},
                {DXGI_ERROR_DEVICE_HUNG, "DXGI_ERROR_DEVICE_HUNG"},
                {DXGI_ERROR_DEVICE_REMOVED, "DXGI_ERROR_DEVICE_REMOVED"},
                {DXGI_ERROR_DEVICE_RESET, "DXGI_ERROR_DEVICE_RESET"},
                {DXGI_ERROR_DRIVER_INTERNAL_ERROR, "DXGI_ERROR_DRIVER_INTERNAL_ERROR"},
                {DXGI_ERROR_FRAME_STATISTICS_DISJOINT, "DXGI_ERROR_FRAME_STATISTICS_DISJOINT"},
                {DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE, "DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE"},
                {DXGI_ERROR_INVALID_CALL, "DXGI_ERROR_INVALID_CALL"},
                {DXGI_ERROR_MORE_DATA, "DXGI_ERROR_MORE_DATA"},
                {DXGI_ERROR_NAME_ALREADY_EXISTS, "DXGI_ERROR_NAME_ALREADY_EXISTS"},
                {DXGI_ERROR_NONEXCLUSIVE, "DXGI_ERROR_NONEXCLUSIVE"},
                {DXGI_ERROR_NOT_CURRENTLY_AVAILABLE, "DXGI_ERROR_NOT_CURRENTLY_AVAILABLE"},
                {DXGI_ERROR_NOT_FOUND, "DXGI_ERROR_NOT_FOUND"},
                {DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED, "DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED"},
                {DXGI_ERROR_REMOTE_OUTOFMEMORY, "DXGI_ERROR_REMOTE_OUTOFMEMORY"},
                {DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE, "DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE"},
                {DXGI_ERROR_SDK_COMPONENT_MISSING, "DXGI_ERROR_SDK_COMPONENT_MISSING"},
                {DXGI_ERROR_SESSION_DISCONNECTED, "DXGI_ERROR_SESSION_DISCONNECTED"},
                {DXGI_ERROR_UNSUPPORTED, "DXGI_ERROR_UNSUPPORTED"},
                {DXGI_ERROR_WAIT_TIMEOUT, "DXGI_ERROR_WAIT_TIMEOUT"},
                {DXGI_ERROR_WAS_STILL_DRAWING, "DXGI_ERROR_WAS_STILL_DRAWING"},
                // Extra OLE Codes from <winerror.h> (we should never see these from DX12/DXGI but just in case):
                {E_UNEXPECTED, "E_UNEXPECTED"},
                {E_NOINTERFACE, "E_NOINTERFACE"},
                {E_POINTER, "E_POINTER"},
                {E_HANDLE, "E_HANDLE"},
                {E_ABORT, "E_ABORT"},
                {E_ACCESSDENIED, "E_ACCESSDENIED"},
                // Misc errors:
                {E_FAIL, "E_FAIL"},
                {E_OUTOFMEMORY, "E_OUTOFMEMORY"},
                {E_INVALIDARG, "E_INVALIDARG"},
                {E_NOTIMPL, "E_NOTIMPL"},
            };

            /// @brief Turn a D3D12 or DXGI HRESULT into a string with the same character
            /// sequence as the identifier of the C macro defining it in a header like
            /// winerror.h. 
            /// @param hresult A D3D12 or DXGI result code.
            static std::string HresultToString(const HRESULT hresult)
            {
                const auto found = kHresults.find(hresult);
                std::string result;
                if(found != kHresults.end())
                {
                    result = found->second;
                }
                else
                {
                    result = util::to_hex_variable_width(static_cast<unsigned long>(hresult));
                    GFXRECON_LOG_DEBUG("HresultToString() passed unkown HRESULT: %s.", result.c_str());
                }
                return result;
            }

            static void HresultToJson(nlohmann::ordered_json& jdata, const HRESULT hresult, const util::JsonOptions& options)
            {
                FieldToJson(jdata, HresultToString(hresult), options);
            }
        '''), file=self.outFile)
        self.newline()
        self.write_dx12_consumer_class('Json')

    def get_decoder_class_define(self, consumer_type):
        declaration = ''
        indent = ''
        function_class = 'Dx12{}Consumer::'.format(consumer_type)
        class_end = ''
        return (declaration, indent, function_class, class_end)

    def get_consumer_function_body(self, class_name, method_info, return_type):
        class_method_name = method_info['name']
        code = '''
            {
                using namespace gfxrecon::util;
        '''
        if(class_name == None or len(class_name) == 0):
            code += self.make_consumer_func_body(method_info, return_type)
        else:
            code += self.make_consumer_method_body(class_name, method_info, return_type)

        code += "\n}"
        code = "\n" + format_cpp_code(code)
        return code

    ## Generate a FieldToJson appropriate to the return type.
    ## @param func_type Either "function" or "method" for expected use.
    ## @todo factor out a function to be used everywhere for generating FieldToJSON functions for all the cases.
    def make_return(self, func_type, return_type):
        type_start = return_type.split()[0]
        ret_line = "FieldToJson({0}[format::kNameReturn], return_value, options);\n"
        if "void" in return_type:
            ret_line = "// Nothing returned.\n"
        elif "BOOL" in return_type:
            ret_line = "Bool32ToJson({0}[format::kNameReturn], return_value, options);\n"
        elif "HRESULT" in return_type:
            ret_line = "HresultToJson({0}[format::kNameReturn], return_value, options);\n"
        elif self.is_struct(type_start) or (type_start == "const" and "_DESC * " in return_type):
            ret_line = "// Structs use the default signature:\n" + ret_line
        elif return_type.startswith("HANDLE "):
            ## This is a Windows handle, probably to a waitable object so we output it as a JSON number:
            ## <https://learn.microsoft.com/en-us/windows/win32/sysinfo/handles-and-objects>
            ## <https://learn.microsoft.com/en-us/windows/win32/sync/wait-functions>
            ret_line = "// Using the default for the underlying type of " + type_start + ":\n" + ret_line
        elif return_type.startswith("D3D12_GPU_VIRTUAL_ADDRESS") or return_type.startswith("LPVOID"):
            ret_line = "FieldToJsonAsHex({0}[format::kNameReturn], return_value, options);\n"
        elif return_type.startswith("UINT ") or return_type.startswith("UINT64 ") or return_type.startswith("ULONG ") or return_type.startswith("SIZE_T "):
            ret_line = "// The default will resolve correctly for " + type_start + ":\n" + ret_line
        elif type_start.endswith("_FLAGS") or type_start.endswith("D3D12_DEBUG_FEATURE"):
            # Flags may convert incorrectly here or in arguments of struct fields but that should probably be addressed in the EnumToString function generator:
            # <https://github.com/LunarG/gfxreconstruct/issues/1349>
            ret_line = "// A flags enum uses the default signature:\n" + ret_line
        elif self.is_enum(type_start):
            ret_line = "// A regular non-flags enum uses the default signature:\n" + ret_line
        else:
            msg = "An unknown return type was seen in generation. Defaulting to the base converter signature."
            print("ALERT: " + msg + " (" + return_type + ")")
            ret_line = "// " + msg + "\n" + ret_line

        ret_line = ret_line.format(func_type)
        return ret_line

    def make_consumer_func_body(self, method_info, return_type):
        # Deal with the function's returned value:
        if return_type != 'HRESULT WINAPI':
            print ("Warning - Unexpected return type:", return_type)
        ret_line = self.make_return("function", return_type)

        code = '''
            nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "{}");
            const JsonOptions& options = writer_->GetOptions();
        '''
        code += ret_line
        code += '''nlohmann::ordered_json& args = function[format::kNameArgs];
            {{
        '''
        # Generate a correct FieldToJson for each argument:
        for parameter in method_info['parameters']:
            value = self.get_value_info(parameter)
            code += "    " + self.make_field_to_json("args", value, "options") + "\n"

        code += remove_leading_empty_lines('''
                }}
            writer_->WriteBlockEnd();
        ''')
        code = code.format(method_info['name'])
        return code

    def make_consumer_method_body(self, class_name, method_info, return_type):
        code = '''
            nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "{0}", object_id, "{1}");
            const JsonOptions& options = writer_->GetOptions();
        '''

        # Deal with the function's returned value:
        ret_line = self.make_return("method", return_type)
        code += ret_line

        # Deal with function argumentS:
        if len(method_info['parameters']) > 0:
            code += '''nlohmann::ordered_json& args = method[format::kNameArgs];
                {{
            '''
            # Generate a correct FieldToJson for each argument:
            for parameter in method_info['parameters']:
                value = self.get_value_info(parameter)
                code += "    " + self.make_field_to_json("args", value, "options") + "\n"
            code += "}}\n"

        code += "writer_->WriteBlockEnd();"
        code = code.format(class_name, method_info['name'])
        return code

    ## @todo Move this to a common base class shared with Dx12StructDecodersToJsonBodyGenerator
    ## if the types used for arguments and struct properties are compatible.
    ## @todo format::HandleId shows up tagged as a pointer but we output it as a decimal uint64_t. Make it a hex value?
    def make_field_to_json(self, parent_name, value, options_name):
        field_to_json = 'FieldToJson({0}["{1}"], {1}, {2});'.format(parent_name, value.name, options_name)
        if "BOOL" in value.base_type:
            field_to_json = 'Bool32ToJson({0}["{1}"], {1}, {2});'.format(parent_name, value.name, options_name)

        # Comment the line with some type info:
        if value.is_pointer:
            # Pointer to POD, struct, enum, string, scalar or array can all have same signature:
            if value.is_array:
                field_to_json += " // [pointer to array]"
                if "*" in value.array_length:
                    field_to_json += ' [value.array_length: "{}"]'.format(value.array_length)
            else:
                field_to_json += " // [pointer to single value]"
        else:
            if value.is_array:
                field_to_json += " // [direct array]"
                pass
            else:
                if self.is_handle(value.base_type):
                    field_to_json = 'static_assert(false, "Unhandled handle.")'
                    field_to_json += " // [non-pointer, non-array, handle]"
                else:
                    field_to_json += " // [non-pointer, non-array, non-handle]"

        return field_to_json