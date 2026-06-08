/*
** Copyright (c) 2026 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include <iostream>

#include <vulkan/vulkan_core.h>

#include "debug_utils_app.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(debug_utils)

void App::configure_instance_builder(gfxrecon::test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    instance_builder.enable_extension("VK_EXT_debug_report");
    instance_builder.enable_extension("VK_EXT_debug_utils");
    instance_builder.set_headless(true);
}

void App::configure_device_builder(gfxrecon::test::DeviceBuilder& device_builder,
                                   test::PhysicalDevice const&    physical_device,
                                   vkmock::TestConfig*            test_config)
{
    // This device extension may not be available without a supporting layer enabled
    device_builder.enable_extension_if_present("VK_EXT_debug_marker");
}

bool App::frame(const int frame_num)
{
    return false;
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(gfxrecon::test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    auto queue_family_index = init.device.get_queue_index(gfxrecon::test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");

    command_pool_ = gfxrecon::test::create_command_pool(init.disp, *queue_family_index);

    VkResult                    result;
    VkCommandBuffer             command_buffer;
    VkCommandBufferAllocateInfo allocate_info{
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, nullptr, command_pool_, VK_COMMAND_BUFFER_LEVEL_PRIMARY, 1
    };
    result = init.disp.allocateCommandBuffers(&allocate_info, &command_buffer);
    VERIFY_VK_RESULT("failed to allocate command buffer", result)

    VkCommandBufferBeginInfo begin_info{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    result = init.disp.beginCommandBuffer(command_buffer, &begin_info);
    VERIFY_VK_RESULT("failed to begin command buffer", result)

    // VK_EXT_debug_marker
    if (init.physical_device.is_extension_present(VK_EXT_DEBUG_MARKER_EXTENSION_NAME))
    {
        // vkDebugMarkerSetObjectNameEXT
        VkDebugMarkerObjectNameInfoEXT name_info{ VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT,
                                                  nullptr,
                                                  VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT,
                                                  reinterpret_cast<uint64_t>(command_buffer),
                                                  "command_buffer" };
        init.disp.fp_vkDebugMarkerSetObjectNameEXT(init.device, &name_info);

        // vkDebugMarkerSetObjectTagEXT
        const char*                   tag = "command_buffer";
        VkDebugMarkerObjectTagInfoEXT tag_info{ VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT,
                                                nullptr,
                                                VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT,
                                                reinterpret_cast<uint64_t>(command_buffer),
                                                1,
                                                strlen(tag),
                                                tag };
        init.disp.fp_vkDebugMarkerSetObjectTagEXT(init.device, &tag_info);

        // vkCmdDebugMarkerBeginEXT
        VkDebugMarkerMarkerInfoEXT marker_info{
            VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT, nullptr, "marker name", { 0.5f, 0.5f, 0.5f, 1.0f }
        };
        init.disp.fp_vkCmdDebugMarkerBeginEXT(command_buffer, &marker_info);

        // vkCmdDebugMarkerEndEXT
        init.disp.fp_vkCmdDebugMarkerEndEXT(command_buffer);

        // vkCmdDebugMarkerInsertEXT
        init.disp.fp_vkCmdDebugMarkerInsertEXT(command_buffer, &marker_info);
    }

    // VK_EXT_debug_report
    {
        // vkCreateDebugReportCallbackEXT
        PFN_vkDebugReportCallbackEXT       callback_func = [](VkDebugReportFlagsEXT      flags,
                                                        VkDebugReportObjectTypeEXT objectType,
                                                        uint64_t                   object,
                                                        size_t                     location,
                                                        int32_t                    messageCode,
                                                        const char*                pLayerPrefix,
                                                        const char*                pMessage,
                                                        void* pUserData) -> VkBool32 { return VK_FALSE; };
        VkDebugReportCallbackCreateInfoEXT callback_info{ VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT,
                                                          nullptr,
                                                          VK_DEBUG_REPORT_INFORMATION_BIT_EXT |
                                                              VK_DEBUG_REPORT_WARNING_BIT_EXT |
                                                              VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT |
                                                              VK_DEBUG_REPORT_ERROR_BIT_EXT |
                                                              VK_DEBUG_REPORT_DEBUG_BIT_EXT,
                                                          callback_func,
                                                          reinterpret_cast<void*>(0x01234567) };
        VkDebugReportCallbackEXT           debug_report_callback;
        init.inst_disp.fp_vkCreateDebugReportCallbackEXT(
            init.instance, &callback_info, nullptr, &debug_report_callback);

        // vkDebugReportMessageEXT
        init.inst_disp.fp_vkDebugReportMessageEXT(init.instance,
                                                  VK_DEBUG_REPORT_INFORMATION_BIT_EXT,
                                                  VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT,
                                                  reinterpret_cast<uint64_t>(command_buffer),
                                                  2,
                                                  -2,
                                                  "gfxrecon-test-app-debug-utils",
                                                  "message");

        // vkDestroyDebugReportCallbackEXT
        init.inst_disp.fp_vkDestroyDebugReportCallbackEXT(init.instance, debug_report_callback, nullptr);
    }

    // VK_EXT_debug_utils
    // vkCmdBeginDebugUtilsLabelEXT
    // vkCmdEndDebugUtilsLabelEXT
    // vkCmdInsertDebugUtilsLabelEXT
    {
        VkDebugUtilsLabelEXT label_info{
            VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, nullptr, "label name", { 0.5f, 0.5f, 0.5f, 1.0f }
        };
        init.disp.fp_vkCmdBeginDebugUtilsLabelEXT(command_buffer, &label_info);
        init.disp.fp_vkCmdEndDebugUtilsLabelEXT(command_buffer);
        init.disp.fp_vkCmdInsertDebugUtilsLabelEXT(command_buffer, &label_info);
    }

    // vkCreateDebugUtilsMessengerEXT
    // vkDestroyDebugUtilsMessengerEXT
    {
        PFN_vkDebugUtilsMessengerCallbackEXT callback_func =
            [](VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
               VkDebugUtilsMessageTypeFlagsEXT             messageType,
               const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
               void*                                       pUserData) -> VkBool32 { return VK_FALSE; };
        VkDebugUtilsMessengerCreateInfoEXT create_info{
            VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
            nullptr,
            0,
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
            VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
            callback_func,
            nullptr,
        };
        VkDebugUtilsMessengerEXT debug_messenger;
        init.inst_disp.fp_vkCreateDebugUtilsMessengerEXT(init.instance, &create_info, nullptr, &debug_messenger);
        init.inst_disp.fp_vkDestroyDebugUtilsMessengerEXT(init.instance, debug_messenger, nullptr);
    }

    // vkQueueBeginDebugUtilsLabelEXT
    // vkQueueEndDebugUtilsLabelEXT
    // vkQueueInsertDebugUtilsLabelEXT
    {
        VkDebugUtilsLabelEXT label_info{
            VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, nullptr, "label name", { 0.5f, 0.5f, 0.5f, 1.0f }
        };
        init.disp.fp_vkQueueBeginDebugUtilsLabelEXT(graphics_queue_, &label_info);
        init.disp.fp_vkQueueEndDebugUtilsLabelEXT(graphics_queue_);
        init.disp.fp_vkQueueInsertDebugUtilsLabelEXT(graphics_queue_, &label_info);
    }

    // vkSetDebugUtilsObjectNameEXT
    {
        VkDebugUtilsObjectNameInfoEXT name_info{ VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,
                                                 nullptr,
                                                 VK_OBJECT_TYPE_COMMAND_BUFFER,
                                                 reinterpret_cast<uint64_t>(command_buffer),
                                                 "command_buffer" };
        init.disp.fp_vkSetDebugUtilsObjectNameEXT(init.device, &name_info);
    }

    // vkSetDebugUtilsObjectTagEXT
    {
        VkDebugUtilsObjectTagInfoEXT tag_info{ VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT,
                                               nullptr,
                                               VK_OBJECT_TYPE_COMMAND_BUFFER,
                                               reinterpret_cast<uint64_t>(command_buffer),
                                               1, // tag version
                                               strlen("command_buffer"),
                                               "command_buffer" };
        init.disp.fp_vkSetDebugUtilsObjectTagEXT(init.device, &tag_info);
    }

    // vkSubmitDebugUtilsMessageEXT
    {
        VkDebugUtilsLabelEXT queue_label{
            VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, nullptr, "queue label", { 0.5f, 0.5f, 0.5f, 1.0f }
        };

        VkDebugUtilsLabelEXT cmd_buf_label{
            VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, nullptr, "command buffer label", { 0.5f, 0.5f, 0.5f, 1.0f }
        };

        VkDebugUtilsObjectNameInfoEXT object_info{ VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,
                                                   nullptr,
                                                   VK_OBJECT_TYPE_COMMAND_BUFFER,
                                                   reinterpret_cast<uint64_t>(command_buffer),
                                                   "command_buffer" };

        VkDebugUtilsMessengerCallbackDataEXT callback_data{
            VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT,
            nullptr,
            0,
            "message id",
            999,
            "message",
            1,
            &queue_label,
            1,
            &cmd_buf_label,
            1,
            &object_info,
        };

        init.inst_disp.fp_vkSubmitDebugUtilsMessageEXT(init.instance,
                                                       VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT,
                                                       VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT,
                                                       &callback_data);
    }

    result = init.disp.endCommandBuffer(command_buffer);
    VERIFY_VK_RESULT("failed to end command buffer", result);

    VkSubmitInfo submitInfo{
        VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr, 0, nullptr, nullptr, 1, &command_buffer, 0, nullptr
    };
    result = init.disp.queueSubmit(graphics_queue_, 1, &submitInfo, VK_NULL_HANDLE);
    VERIFY_VK_RESULT("failed to submit queue", result);

    init.disp.queueWaitIdle(graphics_queue_);
    init.disp.destroyCommandPool(command_pool_, nullptr);
}

GFXRECON_END_NAMESPACE(debug_utils)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
