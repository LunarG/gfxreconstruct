#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2021 Valve Corporation
# Copyright (c) 2018-2025 LunarG, Inc.
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
#
# The content of this file was derived from the Khronos Registry cgenerator.py
# and related Python files found in the KhronosGroup/Vulkan-Headers GitHub repository.
#
# Copyright (c) 2013-2016 The Khronos Group Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# The content of this file was derived from the Khronos Registry cgenerator.py
# and related Python files found in the KhronosGroup/Vulkan-Headers GitHub repository.

import os,re,sys,json
from collections import OrderedDict
from khronos_base_generator import (KhronosBaseGeneratorOptions, KhronosBaseGenerator, make_re_string, ValueInfo, write)
from generator import GeneratorOptions, OutputGenerator, noneStr, regSortFeatures, write
from xrconventions import OpenXRConventions

# Descriptive names for various regexp patterns used to select versions and extensions.
_default_extensions = 'openxr'
_extensions = _features = []
_emit_extensions = []

# Exclude extensions from code generation.
# Note this doesn't totally eliminate them. ToString and ToJson functions for enums
# will always be generated but functions and structs can be screened out by editing
# the blocklists files such as the vulkan default openxr default "openxr_generators/blacklists.json".
# Note, this doesn't hide them from the  application, but lets them bypass our
# layer during capture, meaning we will not call any of their functions at
# replay.
# To screen an extension out from the list reported to the application it should
# be added to the list kUnsupportedDeviceExtensions in trace_layer.cpp.
_remove_extensions = []

# Turn lists of names/patterns into matching regular expressions.
# From Khronos genvk.py
_add_extensions_pat = make_re_string(_extensions)
_remove_extensions_pat = make_re_string(_remove_extensions)
_emit_extensions_pat = make_re_string(_emit_extensions, '.*')
_features_pat = make_re_string(_features, '.*')


class OpenXrBaseGeneratorOptions(KhronosBaseGeneratorOptions):
    """OpenXrBaseGeneratorOptions - subclass of KhronosGeneratorOptions.
    Options for OpenXr API parameter encoding and decoding C++ code generation.

    Adds options used by FrameworkGenerator objects during C++ language
    code generation.

    Additional members
      blacklists - Path to JSON file listing apicalls and structs to ignore.
      platform_types - Path to JSON file listing platform (WIN32, X11, etc.)
        specific types that are defined outside of the OpenXr header.

    Additional members (from Khronos Registry COptionsGenerator)
      prefix_text - list of strings to prefix generated header with
        (usually a copyright statement + calling convention macros).
      protect_file - True if multiple inclusion protection should be
        generated (based on the filename) around the entire header.
      apicall - string to use for the function declaration prefix,
        such as APICALL on Windows.
      apientry - string to use for the calling convention macro,
        in typedefs, such as APIENTRY.
      apientryp - string to use for the calling convention macro
        in function pointer typedefs, such as APIENTRYP.
      indent_func_proto - True if prototype declarations should put each
        parameter on a separate line
      indent_func_pointer - True if typedefed function pointers should put each
        parameter on a separate line
      align_func_param - if nonzero and parameters are being put on a
        separate line, align parameter names at the specified column
      replay_overrides - Path to JSON file listing OpenXr API calls to
        override on replay.
      dump_resources_overrides - Path to JSON file listing OpenXr API
        calls to override on replay.
      replay_async_overrides - Path to JSON file listing OpenXr API calls
        to override on replay.
      extra_headers - headers to include in addition to the standard Khronos API
    """

    def __init__(
        self,
        blacklists=None,
        platform_types=None,
        # Khronos CGeneratorOptions
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        conventions=OpenXRConventions(),
        apicall='XRAPI_ATTR ',
        apientry='XRAPI_CALL ',
        apientryp='XRAPI_PTR *',
        indent_func_proto=True,
        align_func_param=48,
        sort_procedure=regSortFeatures,
        apiname='openxr',
        profile=None,
        versions=_features_pat,
        emit_versions=_features_pat,
        default_extensions=_default_extensions,
        add_extensions=_add_extensions_pat,
        remove_extensions=_remove_extensions_pat,
        emit_extensions=_emit_extensions_pat,
        replay_overrides=None,
        dump_resources_overrides=None,
        replay_async_overrides=None,
        extra_headers=[],
        extra_manual_commands=[],
    ):
        KhronosBaseGeneratorOptions.__init__(
            self,
            blacklists=blacklists,
            platform_types=platform_types,
            filename=filename,
            directory=directory,
            prefix_text=prefix_text,
            protect_file=protect_file,
            protect_feature=protect_feature,
            conventions=conventions,
            apicall=apicall,
            apientry=apientry,
            apientryp=apientryp,
            indent_func_proto=True,
            align_func_param=align_func_param,
            sort_procedure=sort_procedure,
            apiname=apiname,
            profile=profile,
            versions=versions,
            emit_versions=emit_versions,
            default_extensions=_default_extensions,
            add_extensions=add_extensions,
            remove_extensions=remove_extensions,
            emit_extensions=emit_extensions,
            replay_overrides=replay_overrides,
            dump_resources_overrides=dump_resources_overrides,
            replay_async_overrides=replay_async_overrides,
            extra_headers=extra_headers,
            extra_manual_commands=extra_manual_commands,
        )

        self.begin_end_file_data.guards.append(('if', 'ENABLE_OPENXR_SUPPORT'))
        self.begin_end_file_data.common_api_headers = [
            'format/platform_types.h',
            '',
            'openxr/openxr.h',
            'openxr/openxr_loader_negotiation.h',
            'openxr/openxr_platform.h',
        ]

class OpenXrBaseGenerator(KhronosBaseGenerator):
    """OpenXrBaseGenerator - subclass of KhronosBaseGenerator.
    Base class providing common operations used to generate C++-language code for framework
      components that encode and decode OpenXr API parameters.
    Base class for OpenXr API parameter encoding and decoding generators.
    """

    def __init__(
        self,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout
    ):
        KhronosBaseGenerator.__init__(
            self,
            err_file = err_file,
            warn_file = warn_file,
            diag_file = diag_file)

        self.SUPPORTED_SUBSETS= [ "openxr"]

        # Platform specific structure types that have been defined extarnally to the OpenXr header.
        self.PLATFORM_STRUCTS.append('timespec')

        # Add OpenXr specific encode_types
        self.encode_types['XR_DEFINE_ATOM'] = 'UInt64'
        self.encode_types['XR_DEFINE_OPAQUE_64'] = 'UInt64'

        # Add Vulkan handle types to handle list
        self.handle_names.add('VkInstance')
        self.handle_names.add('VkPhysicalDevice')
        self.handle_names.add('VkDevice')
        self.handle_names.add('VkImage')
        self.handle_names.add('VkCommandBuffer')
        self.handle_names.add('VkQueue')
        self.handle_names.add('VkSurfaceKHR')
        self.handle_names.add('VkSwapchainKHR')

        # Add Vulkan enums
        self.enum_names.add('VkResult')
        self.enum_names.add('VkFormat')
        self.enum_names.add('VkFilter')
        self.enum_names.add('VkSamplerMipmapMode')
        self.enum_names.add('VkSamplerAddressMode')
        self.enum_names.add('VkComponentSwizzle')

        # Vulkan flag types
        # Updated as of v1.4.304 using
        # TODO: Automate extraction of this information from the Vulkan xml or header
        #
        # sed -n "s/typedef \(VkFlags6*4*\)  *\(.*\);/'\2': '\1',/p" vulkan_core.h
        vulkan_flags_types = {
            'VkAccessFlags': 'VkFlags',
            'VkImageAspectFlags': 'VkFlags',
            'VkFormatFeatureFlags': 'VkFlags',
            'VkImageCreateFlags': 'VkFlags',
            'VkSampleCountFlags': 'VkFlags',
            'VkImageUsageFlags': 'VkFlags',
            'VkInstanceCreateFlags': 'VkFlags',
            'VkMemoryHeapFlags': 'VkFlags',
            'VkMemoryPropertyFlags': 'VkFlags',
            'VkQueueFlags': 'VkFlags',
            'VkDeviceCreateFlags': 'VkFlags',
            'VkDeviceQueueCreateFlags': 'VkFlags',
            'VkPipelineStageFlags': 'VkFlags',
            'VkMemoryMapFlags': 'VkFlags',
            'VkSparseMemoryBindFlags': 'VkFlags',
            'VkSparseImageFormatFlags': 'VkFlags',
            'VkFenceCreateFlags': 'VkFlags',
            'VkSemaphoreCreateFlags': 'VkFlags',
            'VkEventCreateFlags': 'VkFlags',
            'VkQueryPipelineStatisticFlags': 'VkFlags',
            'VkQueryPoolCreateFlags': 'VkFlags',
            'VkQueryResultFlags': 'VkFlags',
            'VkBufferCreateFlags': 'VkFlags',
            'VkBufferUsageFlags': 'VkFlags',
            'VkBufferViewCreateFlags': 'VkFlags',
            'VkImageViewCreateFlags': 'VkFlags',
            'VkShaderModuleCreateFlags': 'VkFlags',
            'VkPipelineCacheCreateFlags': 'VkFlags',
            'VkColorComponentFlags': 'VkFlags',
            'VkPipelineCreateFlags': 'VkFlags',
            'VkPipelineShaderStageCreateFlags': 'VkFlags',
            'VkCullModeFlags': 'VkFlags',
            'VkPipelineVertexInputStateCreateFlags': 'VkFlags',
            'VkPipelineInputAssemblyStateCreateFlags': 'VkFlags',
            'VkPipelineTessellationStateCreateFlags': 'VkFlags',
            'VkPipelineViewportStateCreateFlags': 'VkFlags',
            'VkPipelineRasterizationStateCreateFlags': 'VkFlags',
            'VkPipelineMultisampleStateCreateFlags': 'VkFlags',
            'VkPipelineDepthStencilStateCreateFlags': 'VkFlags',
            'VkPipelineColorBlendStateCreateFlags': 'VkFlags',
            'VkPipelineDynamicStateCreateFlags': 'VkFlags',
            'VkPipelineLayoutCreateFlags': 'VkFlags',
            'VkShaderStageFlags': 'VkFlags',
            'VkSamplerCreateFlags': 'VkFlags',
            'VkDescriptorPoolCreateFlags': 'VkFlags',
            'VkDescriptorPoolResetFlags': 'VkFlags',
            'VkDescriptorSetLayoutCreateFlags': 'VkFlags',
            'VkAttachmentDescriptionFlags': 'VkFlags',
            'VkDependencyFlags': 'VkFlags',
            'VkFramebufferCreateFlags': 'VkFlags',
            'VkRenderPassCreateFlags': 'VkFlags',
            'VkSubpassDescriptionFlags': 'VkFlags',
            'VkCommandPoolCreateFlags': 'VkFlags',
            'VkCommandPoolResetFlags': 'VkFlags',
            'VkCommandBufferUsageFlags': 'VkFlags',
            'VkQueryControlFlags': 'VkFlags',
            'VkCommandBufferResetFlags': 'VkFlags',
            'VkStencilFaceFlags': 'VkFlags',
            'VkSubgroupFeatureFlags': 'VkFlags',
            'VkPeerMemoryFeatureFlags': 'VkFlags',
            'VkMemoryAllocateFlags': 'VkFlags',
            'VkCommandPoolTrimFlags': 'VkFlags',
            'VkDescriptorUpdateTemplateCreateFlags': 'VkFlags',
            'VkExternalMemoryHandleTypeFlags': 'VkFlags',
            'VkExternalMemoryFeatureFlags': 'VkFlags',
            'VkExternalFenceHandleTypeFlags': 'VkFlags',
            'VkExternalFenceFeatureFlags': 'VkFlags',
            'VkFenceImportFlags': 'VkFlags',
            'VkSemaphoreImportFlags': 'VkFlags',
            'VkExternalSemaphoreHandleTypeFlags': 'VkFlags',
            'VkExternalSemaphoreFeatureFlags': 'VkFlags',
            'VkResolveModeFlags': 'VkFlags',
            'VkDescriptorBindingFlags': 'VkFlags',
            'VkSemaphoreWaitFlags': 'VkFlags',
            'VkPipelineCreationFeedbackFlags': 'VkFlags',
            'VkToolPurposeFlags': 'VkFlags',
            'VkPrivateDataSlotCreateFlags': 'VkFlags',
            'VkPipelineStageFlags2': 'VkFlags64',
            'VkPipelineStageFlagBits2': 'VkFlags64',
            'VkAccessFlags2': 'VkFlags64',
            'VkAccessFlagBits2': 'VkFlags64',
            'VkSubmitFlags': 'VkFlags',
            'VkRenderingFlags': 'VkFlags',
            'VkFormatFeatureFlags2': 'VkFlags64',
            'VkFormatFeatureFlagBits2': 'VkFlags64',
            'VkMemoryUnmapFlags': 'VkFlags',
            'VkPipelineCreateFlags2': 'VkFlags64',
            'VkPipelineCreateFlagBits2': 'VkFlags64',
            'VkBufferUsageFlags2': 'VkFlags64',
            'VkBufferUsageFlagBits2': 'VkFlags64',
            'VkHostImageCopyFlags': 'VkFlags',
            'VkCompositeAlphaFlagsKHR': 'VkFlags',
            'VkSurfaceTransformFlagsKHR': 'VkFlags',
            'VkSwapchainCreateFlagsKHR': 'VkFlags',
            'VkDeviceGroupPresentModeFlagsKHR': 'VkFlags',
            'VkDisplayModeCreateFlagsKHR': 'VkFlags',
            'VkDisplayPlaneAlphaFlagsKHR': 'VkFlags',
            'VkDisplaySurfaceCreateFlagsKHR': 'VkFlags',
            'VkVideoCodecOperationFlagsKHR': 'VkFlags',
            'VkVideoChromaSubsamplingFlagsKHR': 'VkFlags',
            'VkVideoComponentBitDepthFlagsKHR': 'VkFlags',
            'VkVideoCapabilityFlagsKHR': 'VkFlags',
            'VkVideoSessionCreateFlagsKHR': 'VkFlags',
            'VkVideoSessionParametersCreateFlagsKHR': 'VkFlags',
            'VkVideoBeginCodingFlagsKHR': 'VkFlags',
            'VkVideoEndCodingFlagsKHR': 'VkFlags',
            'VkVideoCodingControlFlagsKHR': 'VkFlags',
            'VkVideoDecodeCapabilityFlagsKHR': 'VkFlags',
            'VkVideoDecodeUsageFlagsKHR': 'VkFlags',
            'VkVideoDecodeFlagsKHR': 'VkFlags',
            'VkVideoEncodeH264CapabilityFlagsKHR': 'VkFlags',
            'VkVideoEncodeH264StdFlagsKHR': 'VkFlags',
            'VkVideoEncodeH264RateControlFlagsKHR': 'VkFlags',
            'VkVideoEncodeH265CapabilityFlagsKHR': 'VkFlags',
            'VkVideoEncodeH265StdFlagsKHR': 'VkFlags',
            'VkVideoEncodeH265CtbSizeFlagsKHR': 'VkFlags',
            'VkVideoEncodeH265TransformBlockSizeFlagsKHR': 'VkFlags',
            'VkVideoEncodeH265RateControlFlagsKHR': 'VkFlags',
            'VkVideoDecodeH264PictureLayoutFlagsKHR': 'VkFlags',
            'VkPerformanceCounterDescriptionFlagsKHR': 'VkFlags',
            'VkAcquireProfilingLockFlagsKHR': 'VkFlags',
            'VkVideoEncodeFlagsKHR': 'VkFlags',
            'VkVideoEncodeCapabilityFlagsKHR': 'VkFlags',
            'VkVideoEncodeRateControlModeFlagsKHR': 'VkFlags',
            'VkVideoEncodeFeedbackFlagsKHR': 'VkFlags',
            'VkVideoEncodeUsageFlagsKHR': 'VkFlags',
            'VkVideoEncodeContentFlagsKHR': 'VkFlags',
            'VkVideoEncodeRateControlFlagsKHR': 'VkFlags',
            'VkVideoEncodeAV1CapabilityFlagsKHR': 'VkFlags',
            'VkVideoEncodeAV1StdFlagsKHR': 'VkFlags',
            'VkVideoEncodeAV1SuperblockSizeFlagsKHR': 'VkFlags',
            'VkVideoEncodeAV1RateControlFlagsKHR': 'VkFlags',
            'VkDebugReportFlagsEXT': 'VkFlags',
            'VkPipelineRasterizationStateStreamCreateFlagsEXT': 'VkFlags',
            'VkExternalMemoryHandleTypeFlagsNV': 'VkFlags',
            'VkExternalMemoryFeatureFlagsNV': 'VkFlags',
            'VkConditionalRenderingFlagsEXT': 'VkFlags',
            'VkSurfaceCounterFlagsEXT': 'VkFlags',
            'VkPipelineViewportSwizzleStateCreateFlagsNV': 'VkFlags',
            'VkPipelineDiscardRectangleStateCreateFlagsEXT': 'VkFlags',
            'VkPipelineRasterizationConservativeStateCreateFlagsEXT': 'VkFlags',
            'VkPipelineRasterizationDepthClipStateCreateFlagsEXT': 'VkFlags',
            'VkDebugUtilsMessengerCallbackDataFlagsEXT': 'VkFlags',
            'VkDebugUtilsMessageTypeFlagsEXT': 'VkFlags',
            'VkDebugUtilsMessageSeverityFlagsEXT': 'VkFlags',
            'VkDebugUtilsMessengerCreateFlagsEXT': 'VkFlags',
            'VkPipelineCoverageToColorStateCreateFlagsNV': 'VkFlags',
            'VkPipelineCoverageModulationStateCreateFlagsNV': 'VkFlags',
            'VkValidationCacheCreateFlagsEXT': 'VkFlags',
            'VkGeometryFlagsKHR': 'VkFlags',
            'VkGeometryInstanceFlagsKHR': 'VkFlags',
            'VkBuildAccelerationStructureFlagsKHR': 'VkFlags',
            'VkPipelineCompilerControlFlagsAMD': 'VkFlags',
            'VkShaderCorePropertiesFlagsAMD': 'VkFlags',
            'VkPipelineCoverageReductionStateCreateFlagsNV': 'VkFlags',
            'VkHeadlessSurfaceCreateFlagsEXT': 'VkFlags',
            'VkPresentScalingFlagsEXT': 'VkFlags',
            'VkPresentGravityFlagsEXT': 'VkFlags',
            'VkIndirectStateFlagsNV': 'VkFlags',
            'VkIndirectCommandsLayoutUsageFlagsNV': 'VkFlags',
            'VkDeviceMemoryReportFlagsEXT': 'VkFlags',
            'VkDeviceDiagnosticsConfigFlagsNV': 'VkFlags',
            'VkGraphicsPipelineLibraryFlagsEXT': 'VkFlags',
            'VkAccelerationStructureMotionInfoFlagsNV': 'VkFlags',
            'VkAccelerationStructureMotionInstanceFlagsNV': 'VkFlags',
            'VkImageCompressionFlagsEXT': 'VkFlags',
            'VkImageCompressionFixedRateFlagsEXT': 'VkFlags',
            'VkDeviceAddressBindingFlagsEXT': 'VkFlags',
            'VkFrameBoundaryFlagsEXT': 'VkFlags',
            'VkBuildMicromapFlagsEXT': 'VkFlags',
            'VkMicromapCreateFlagsEXT': 'VkFlags',
            'VkPhysicalDeviceSchedulingControlsFlagsARM': 'VkFlags64',
            'VkPhysicalDeviceSchedulingControlsFlagBitsARM': 'VkFlags64',
            'VkMemoryDecompressionMethodFlagBitsNV': 'VkFlags64',
            'VkMemoryDecompressionMethodFlagsNV': 'VkFlags64',
            'VkDirectDriverLoadingFlagsLUNARG': 'VkFlags',
            'VkOpticalFlowGridSizeFlagsNV': 'VkFlags',
            'VkOpticalFlowUsageFlagsNV': 'VkFlags',
            'VkOpticalFlowSessionCreateFlagsNV': 'VkFlags',
            'VkOpticalFlowExecuteFlagsNV': 'VkFlags',
            'VkShaderCreateFlagsEXT': 'VkFlags',
            'VkIndirectCommandsInputModeFlagsEXT': 'VkFlags',
            'VkIndirectCommandsLayoutUsageFlagsEXT': 'VkFlags',
            'VkAccelerationStructureCreateFlagsKHR': 'VkFlags',
        }
        self.flags_types.update(vulkan_flags_types)

    def beginFile(self, gen_opts):
        """Method override."""
        KhronosBaseGenerator.beginFile(self, gen_opts)

    def endFile(self):
        """Method override. Generate code for the feature."""
        KhronosBaseGenerator.endFile(self)

    def beginFeature(self, interface, emit):
        """Method override. Start processing in superclass."""
        KhronosBaseGenerator.beginFeature(self, interface, emit)

    def endFeature(self):
        """Method override. Generate code for the feature."""
        KhronosBaseGenerator.endFeature(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        super().genStruct(typeinfo, typename, alias)

        if not alias:
            self.check_struct_member_handles(
                typename, self.structs_with_handles
            )

    def get_feature_protect(self, interface):
        """Return appropriate feature protect string from 'platform' tag on feature.
        """
        # TODO: This should probably be in a JSON file.
        platform_dict = {
             'android': 'XR_USE_PLATFORM_ANDROID',
            'wayland': 'XR_USE_PLATFORM_WAYLAND',
            'win32': 'XR_USE_PLATFORM_WIN32',
            'xcb': 'XR_USE_PLATFORM_XCB',
            'xlib': 'XR_USE_PLATFORM_XLIB',
        }

        platform = interface.get('platform')
        if platform and platform in platform_dict:
            return platform_dict[platform]
        return None

    def get_handle_wrapper(self, base_type):
        handle_wrapper = ''
        if base_type.startswith('Vk'):
            handle_wrapper = 'vulkan_wrappers::'
        else:
            handle_wrapper = 'openxr_wrappers::'
        handle_wrapper += base_type[2:] + 'Wrapper'
        return handle_wrapper

    def get_atom_encode_text(self, type_name):
        return 'OpenXrAtom'

    def get_opaque_encode_text(self, type_name):
        return 'OpenXrOpaque'

    def add_remaining_base_types(self, name, type_info):
            if type_info == 'XR_DEFINE_ATOM':
                self.atom_names.add(name)
            elif type_info == 'XR_DEFINE_OPAQUE_64':
                self.opaque_names.add(name)
            elif not name == 'XrTime':
                super().add_remaining_base_types(name, type_info)
