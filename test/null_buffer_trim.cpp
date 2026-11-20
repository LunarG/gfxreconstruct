// SPDX-License-Identifier: MIT
// Regression repro for trimmed snapshots of an explicitly written NULL buffer descriptor.
// No buffer allocations, window, device addresses or external-memory imports.
// Windows: compiler prompt with Vulkan SDK headers/libraries on INCLUDE/LIB;
// built capture/validation layers on VK_LAYER_PATH, and GFXReconstruct tools on PATH.
//   cl /nologo /EHsc /std:c++17 test/null_buffer_trim.cpp /link vulkan-1.lib /OUT:null-buffer.exe
//   set GFXRECON_CAPTURE_QUEUE_SUBMITS=0
//   set GFXRECON_CAPTURE_FILE=null.gfxr
//   set GFXRECON_CAPTURE_FILE_TIMESTAMP=false
//   set VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_KHRONOS_validation
//   null-buffer.exe
//   set VK_INSTANCE_LAYERS=VK_LAYER_KHRONOS_validation
//   gfxrecon-replay --wsi headless null_queue_submit_0.gfxr
// The original run and fixed trimmed replay must have no validation errors.
// Before the fix, replay reports VUID-vkCmdDispatch-None-08114.
// Linux build: c++ -std=c++17 test/null_buffer_trim.cpp -lvulkan -o null-buffer
// Return77 means unsupported hardware; validation messages determine the result.
#include <vulkan/vulkan.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define CHECK(call)                                              \
    do                                                           \
    {                                                            \
        const VkResult r = (call);                               \
        if (r != VK_SUCCESS)                                     \
        {                                                        \
            std::fprintf(stderr, "%s: VkResult %d\n", #call, r); \
            std::exit(1);                                        \
        }                                                        \
    } while (0)

// SPIR-V1.3: layout(local_size_x=1) in;
// layout(set=0,binding=0,std430) buffer Output { uint value; } output;
// void main() { output.value = 1; }
static const uint32_t kShader[] = {
    0x07230203, 0x00010300, 0x00000000, 0x0000000d, 0x00000000, 0x00020011, 0x00000001, 0x0003000e, 0x00000000,
    0x00000001, 0x0005000f, 0x00000005, 0x0000000a, 0x6e69616d, 0x00000000, 0x00060010, 0x0000000a, 0x00000011,
    0x00000001, 0x00000001, 0x00000001, 0x00030047, 0x00000006, 0x00000002, 0x00050048, 0x00000006, 0x00000000,
    0x00000023, 0x00000000, 0x00040047, 0x00000008, 0x00000022, 0x00000000, 0x00040047, 0x00000008, 0x00000021,
    0x00000000, 0x00020013, 0x00000001, 0x00030021, 0x00000002, 0x00000001, 0x00040015, 0x00000003, 0x00000020,
    0x00000000, 0x0004002b, 0x00000003, 0x00000004, 0x00000000, 0x0004002b, 0x00000003, 0x00000005, 0x00000001,
    0x0003001e, 0x00000006, 0x00000003, 0x00040020, 0x00000007, 0x0000000c, 0x00000006, 0x0004003b, 0x00000007,
    0x00000008, 0x0000000c, 0x00040020, 0x00000009, 0x0000000c, 0x00000003, 0x00050036, 0x00000001, 0x0000000a,
    0x00000000, 0x00000002, 0x000200f8, 0x0000000b, 0x00050041, 0x00000009, 0x0000000c, 0x00000008, 0x00000004,
    0x0003003e, 0x0000000c, 0x00000005, 0x000100fd, 0x00010038,
};

int main()
{
    VkApplicationInfo app{ VK_STRUCTURE_TYPE_APPLICATION_INFO };
    app.pApplicationName = "explicit-null-buffer";
    app.apiVersion       = VK_API_VERSION_1_2;
    VkInstanceCreateInfo ici{ VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO };
    ici.pApplicationInfo = &app;
    VkInstance instance{};
    CHECK(vkCreateInstance(&ici, nullptr, &instance));
    uint32_t count{};
    CHECK(vkEnumeratePhysicalDevices(instance, &count, nullptr));
    std::vector<VkPhysicalDevice> devices(count);
    CHECK(vkEnumeratePhysicalDevices(instance, &count, devices.data()));
    VkPhysicalDevice physical{};
    uint32_t         family{};
    for (auto candidate : devices)
    {
        VkPhysicalDeviceProperties properties{};
        vkGetPhysicalDeviceProperties(candidate, &properties);
        if (properties.apiVersion < VK_API_VERSION_1_2)
            continue;
        CHECK(vkEnumerateDeviceExtensionProperties(candidate, nullptr, &count, nullptr));
        std::vector<VkExtensionProperties> extensions(count);
        CHECK(vkEnumerateDeviceExtensionProperties(candidate, nullptr, &count, extensions.data()));
        bool supported = false;
        for (const auto& extension : extensions)
            supported |= std::strcmp(extension.extensionName, VK_EXT_ROBUSTNESS_2_EXTENSION_NAME) == 0;
        if (!supported)
            continue;
        VkPhysicalDeviceRobustness2FeaturesEXT robustness{
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT
        };
        VkPhysicalDeviceFeatures2 features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2 };
        features.pNext = &robustness;
        vkGetPhysicalDeviceFeatures2(candidate, &features);
        if (!robustness.nullDescriptor)
            continue;
        vkGetPhysicalDeviceQueueFamilyProperties(candidate, &count, nullptr);
        std::vector<VkQueueFamilyProperties> queues(count);
        vkGetPhysicalDeviceQueueFamilyProperties(candidate, &count, queues.data());
        for (uint32_t i = 0; i < count; ++i)
            if (queues[i].queueCount && (queues[i].queueFlags & VK_QUEUE_COMPUTE_BIT))
            {
                physical = candidate;
                family   = i;
                break;
            }
        if (physical)
            break;
    }
    if (!physical)
    {
        std::puts("SKIP: no compute device supporting EXT_robustness2.nullDescriptor");
        vkDestroyInstance(instance, nullptr);
        return 77;
    }
    const float             priority = 1;
    VkDeviceQueueCreateInfo qci{ VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO };
    qci.queueFamilyIndex = family;
    qci.queueCount       = 1;
    qci.pQueuePriorities = &priority;
    VkPhysicalDeviceRobustness2FeaturesEXT robustness{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT };
    robustness.nullDescriptor    = VK_TRUE;
    const char*        extension = VK_EXT_ROBUSTNESS_2_EXTENSION_NAME;
    VkDeviceCreateInfo dci{ VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO };
    dci.pNext                   = &robustness;
    dci.queueCreateInfoCount    = 1;
    dci.pQueueCreateInfos       = &qci;
    dci.enabledExtensionCount   = 1;
    dci.ppEnabledExtensionNames = &extension;
    VkDevice device{};
    CHECK(vkCreateDevice(physical, &dci, nullptr, &device));
    VkQueue queue{};
    vkGetDeviceQueue(device, family, 0, &queue);
    VkDescriptorSetLayoutBinding binding{
        0, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 1, VK_SHADER_STAGE_COMPUTE_BIT, nullptr
    };
    VkDescriptorSetLayoutCreateInfo li{ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO };
    li.bindingCount = 1;
    li.pBindings    = &binding;
    VkDescriptorSetLayout set_layout{};
    CHECK(vkCreateDescriptorSetLayout(device, &li, nullptr, &set_layout));
    VkDescriptorPoolSize       pool_size{ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 1 };
    VkDescriptorPoolCreateInfo pi{ VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO };
    pi.maxSets       = 1;
    pi.poolSizeCount = 1;
    pi.pPoolSizes    = &pool_size;
    VkDescriptorPool pool{};
    CHECK(vkCreateDescriptorPool(device, &pi, nullptr, &pool));
    VkDescriptorSetAllocateInfo si{ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO };
    si.descriptorPool     = pool;
    si.descriptorSetCount = 1;
    si.pSetLayouts        = &set_layout;
    VkDescriptorSet set{};
    CHECK(vkAllocateDescriptorSets(device, &si, &set));
    VkDescriptorBufferInfo null_buffer{ VK_NULL_HANDLE, 0, VK_WHOLE_SIZE };
    VkWriteDescriptorSet   write{ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET };
    write.dstSet          = set;
    write.descriptorCount = 1;
    write.descriptorType  = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    write.pBufferInfo     = &null_buffer;
    vkUpdateDescriptorSets(device, 1, &write, 0, nullptr);
    VkPipelineLayoutCreateInfo pli{ VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO };
    pli.setLayoutCount = 1;
    pli.pSetLayouts    = &set_layout;
    VkPipelineLayout layout{};
    CHECK(vkCreatePipelineLayout(device, &pli, nullptr, &layout));
    VkShaderModuleCreateInfo mi{ VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO };
    mi.codeSize = sizeof(kShader);
    mi.pCode    = kShader;
    VkShaderModule module{};
    CHECK(vkCreateShaderModule(device, &mi, nullptr, &module));
    VkComputePipelineCreateInfo ci{ VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO };
    ci.layout       = layout;
    ci.stage.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    ci.stage.stage  = VK_SHADER_STAGE_COMPUTE_BIT;
    ci.stage.module = module;
    ci.stage.pName  = "main";
    VkPipeline pipeline{};
    CHECK(vkCreateComputePipelines(device, VK_NULL_HANDLE, 1, &ci, nullptr, &pipeline));
    VkCommandPoolCreateInfo cpi{ VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    cpi.queueFamilyIndex = family;
    VkCommandPool command_pool{};
    CHECK(vkCreateCommandPool(device, &cpi, nullptr, &command_pool));
    VkCommandBufferAllocateInfo ca{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    ca.commandPool        = command_pool;
    ca.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    ca.commandBufferCount = 1;
    VkCommandBuffer command{};
    CHECK(vkAllocateCommandBuffers(device, &ca, &command));
    VkCommandBufferBeginInfo begin{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    CHECK(vkBeginCommandBuffer(command, &begin));
    vkCmdBindPipeline(command, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline);
    vkCmdBindDescriptorSets(command, VK_PIPELINE_BIND_POINT_COMPUTE, layout, 0, 1, &set, 0, nullptr);
    vkCmdDispatch(command, 1, 1, 1);
    CHECK(vkEndCommandBuffer(command));
    VkFenceCreateInfo fi{ VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
    VkFence           fence{};
    CHECK(vkCreateFence(device, &fi, nullptr, &fence));
    VkSubmitInfo submit{ VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit.commandBufferCount = 1;
    submit.pCommandBuffers    = &command;
    CHECK(vkQueueSubmit(queue, 1, &submit, fence));
    CHECK(vkWaitForFences(device, 1, &fence, VK_TRUE, UINT64_MAX));
    vkDestroyFence(device, fence, nullptr);
    vkDestroyCommandPool(device, command_pool, nullptr);
    vkDestroyPipeline(device, pipeline, nullptr);
    vkDestroyShaderModule(device, module, nullptr);
    vkDestroyPipelineLayout(device, layout, nullptr);
    vkDestroyDescriptorPool(device, pool, nullptr);
    vkDestroyDescriptorSetLayout(device, set_layout, nullptr);
    vkDestroyDevice(device, nullptr);
    vkDestroyInstance(instance, nullptr);
    std::puts("Completed: inspect validation log and trimmed descriptor restore write.");
}
