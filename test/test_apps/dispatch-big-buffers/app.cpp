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

#include <dispatch_big_buffers_app.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(dispatch_big_buffers)

// SPIR-V (glslangValidator -V) of the compute shader below. Every dispatch runs it over the whole big buffer: each
// invocation walks the buffer with a grid-wide stride, replaces every element by an LCG step mixed with the
// push-constant seed and accumulates what it wrote. The accumulated values are reduced per workgroup and stored in the
// small result buffer, so every dispatch leaves a different, cheap-to-dump summary of the gigabyte it touched.
//
//   #version 450
//
//   layout(local_size_x = 256, local_size_y = 1, local_size_z = 1) in;
//
//   layout(set = 0, binding = 0) buffer BigBuffer
//   {
//       uint data[];
//   };
//
//   layout(set = 0, binding = 1) buffer ResultBuffer
//   {
//       uint workgroup_sums[];
//   };
//
//   layout(push_constant) uniform Params
//   {
//       uint element_count;
//       uint seed;
//   };
//
//   shared uint partial_sums[256];
//
//   void main()
//   {
//       const uint stride = gl_NumWorkGroups.x * gl_WorkGroupSize.x;
//
//       uint accumulated = 0u;
//       for (uint i = gl_GlobalInvocationID.x; i < element_count; i += stride)
//       {
//           const uint value = data[i] * 1664525u + 1013904223u + seed;
//           data[i]          = value;
//           accumulated += value;
//       }
//
//       partial_sums[gl_LocalInvocationIndex] = accumulated;
//       barrier();
//
//       for (uint offset = gl_WorkGroupSize.x / 2u; offset > 0u; offset >>= 1u)
//       {
//           if (gl_LocalInvocationIndex < offset)
//           {
//               partial_sums[gl_LocalInvocationIndex] += partial_sums[gl_LocalInvocationIndex + offset];
//           }
//           barrier();
//       }
//
//       if (gl_LocalInvocationIndex == 0u)
//       {
//           workgroup_sums[gl_WorkGroupID.x] = partial_sums[0];
//       }
//   }
static const uint32_t kComputeShaderSpirv[] = {
    0x07230203, 0x00010000, 0x0008000b, 0x00000075, 0x00000000, 0x00020011, 0x00000001, 0x0006000b, 0x00000001,
    0x4c534c47, 0x6474732e, 0x3035342e, 0x00000000, 0x0003000e, 0x00000000, 0x00000001, 0x0009000f, 0x00000005,
    0x00000004, 0x6e69616d, 0x00000000, 0x0000000b, 0x00000014, 0x00000044, 0x0000006e, 0x00060010, 0x00000004,
    0x00000011, 0x00000100, 0x00000001, 0x00000001, 0x00030003, 0x00000002, 0x000001c2, 0x00040005, 0x00000004,
    0x6e69616d, 0x00000000, 0x00040005, 0x00000008, 0x69727473, 0x00006564, 0x00070005, 0x0000000b, 0x4e5f6c67,
    0x6f576d75, 0x72476b72, 0x7370756f, 0x00000000, 0x00050005, 0x00000012, 0x75636361, 0x616c756d, 0x00646574,
    0x00030005, 0x00000013, 0x00000069, 0x00080005, 0x00000014, 0x475f6c67, 0x61626f6c, 0x766e496c, 0x7461636f,
    0x496e6f69, 0x00000044, 0x00040005, 0x0000001d, 0x61726150, 0x0000736d, 0x00070006, 0x0000001d, 0x00000000,
    0x6d656c65, 0x5f746e65, 0x6e756f63, 0x00000074, 0x00050006, 0x0000001d, 0x00000001, 0x64656573, 0x00000000,
    0x00030005, 0x0000001f, 0x00000000, 0x00040005, 0x00000027, 0x756c6176, 0x00000065, 0x00050005, 0x00000029,
    0x42676942, 0x65666675, 0x00000072, 0x00050006, 0x00000029, 0x00000000, 0x61746164, 0x00000000, 0x00030005,
    0x0000002b, 0x00000000, 0x00060005, 0x00000043, 0x74726170, 0x5f6c6169, 0x736d7573, 0x00000000, 0x00080005,
    0x00000044, 0x4c5f6c67, 0x6c61636f, 0x6f766e49, 0x69746163, 0x6e496e6f, 0x00786564, 0x00040005, 0x0000004b,
    0x7366666f, 0x00007465, 0x00060005, 0x0000006b, 0x75736552, 0x7542746c, 0x72656666, 0x00000000, 0x00070006,
    0x0000006b, 0x00000000, 0x6b726f77, 0x756f7267, 0x75735f70, 0x0000736d, 0x00030005, 0x0000006d, 0x00000000,
    0x00060005, 0x0000006e, 0x575f6c67, 0x476b726f, 0x70756f72, 0x00004449, 0x00040047, 0x0000000b, 0x0000000b,
    0x00000018, 0x00040047, 0x00000014, 0x0000000b, 0x0000001c, 0x00030047, 0x0000001d, 0x00000002, 0x00050048,
    0x0000001d, 0x00000000, 0x00000023, 0x00000000, 0x00050048, 0x0000001d, 0x00000001, 0x00000023, 0x00000004,
    0x00040047, 0x00000028, 0x00000006, 0x00000004, 0x00030047, 0x00000029, 0x00000003, 0x00050048, 0x00000029,
    0x00000000, 0x00000023, 0x00000000, 0x00040047, 0x0000002b, 0x00000021, 0x00000000, 0x00040047, 0x0000002b,
    0x00000022, 0x00000000, 0x00040047, 0x00000044, 0x0000000b, 0x0000001d, 0x00040047, 0x0000006a, 0x00000006,
    0x00000004, 0x00030047, 0x0000006b, 0x00000003, 0x00050048, 0x0000006b, 0x00000000, 0x00000023, 0x00000000,
    0x00040047, 0x0000006d, 0x00000021, 0x00000001, 0x00040047, 0x0000006d, 0x00000022, 0x00000000, 0x00040047,
    0x0000006e, 0x0000000b, 0x0000001a, 0x00040047, 0x00000074, 0x0000000b, 0x00000019, 0x00020013, 0x00000002,
    0x00030021, 0x00000003, 0x00000002, 0x00040015, 0x00000006, 0x00000020, 0x00000000, 0x00040020, 0x00000007,
    0x00000007, 0x00000006, 0x00040017, 0x00000009, 0x00000006, 0x00000003, 0x00040020, 0x0000000a, 0x00000001,
    0x00000009, 0x0004003b, 0x0000000a, 0x0000000b, 0x00000001, 0x0004002b, 0x00000006, 0x0000000c, 0x00000000,
    0x00040020, 0x0000000d, 0x00000001, 0x00000006, 0x0004002b, 0x00000006, 0x00000010, 0x00000100, 0x0004003b,
    0x0000000a, 0x00000014, 0x00000001, 0x0004001e, 0x0000001d, 0x00000006, 0x00000006, 0x00040020, 0x0000001e,
    0x00000009, 0x0000001d, 0x0004003b, 0x0000001e, 0x0000001f, 0x00000009, 0x00040015, 0x00000020, 0x00000020,
    0x00000001, 0x0004002b, 0x00000020, 0x00000021, 0x00000000, 0x00040020, 0x00000022, 0x00000009, 0x00000006,
    0x00020014, 0x00000025, 0x0003001d, 0x00000028, 0x00000006, 0x0003001e, 0x00000029, 0x00000028, 0x00040020,
    0x0000002a, 0x00000002, 0x00000029, 0x0004003b, 0x0000002a, 0x0000002b, 0x00000002, 0x00040020, 0x0000002d,
    0x00000002, 0x00000006, 0x0004002b, 0x00000006, 0x00000030, 0x0019660d, 0x0004002b, 0x00000006, 0x00000032,
    0x3c6ef35f, 0x0004002b, 0x00000020, 0x00000034, 0x00000001, 0x0004001c, 0x00000041, 0x00000006, 0x00000010,
    0x00040020, 0x00000042, 0x00000004, 0x00000041, 0x0004003b, 0x00000042, 0x00000043, 0x00000004, 0x0004003b,
    0x0000000d, 0x00000044, 0x00000001, 0x00040020, 0x00000047, 0x00000004, 0x00000006, 0x0004002b, 0x00000006,
    0x00000049, 0x00000002, 0x0004002b, 0x00000006, 0x0000004a, 0x00000108, 0x0004002b, 0x00000006, 0x0000004c,
    0x00000080, 0x0004002b, 0x00000006, 0x00000063, 0x00000001, 0x0003001d, 0x0000006a, 0x00000006, 0x0003001e,
    0x0000006b, 0x0000006a, 0x00040020, 0x0000006c, 0x00000002, 0x0000006b, 0x0004003b, 0x0000006c, 0x0000006d,
    0x00000002, 0x0004003b, 0x0000000a, 0x0000006e, 0x00000001, 0x0006002c, 0x00000009, 0x00000074, 0x00000010,
    0x00000063, 0x00000063, 0x00050036, 0x00000002, 0x00000004, 0x00000000, 0x00000003, 0x000200f8, 0x00000005,
    0x0004003b, 0x00000007, 0x00000008, 0x00000007, 0x0004003b, 0x00000007, 0x00000012, 0x00000007, 0x0004003b,
    0x00000007, 0x00000013, 0x00000007, 0x0004003b, 0x00000007, 0x00000027, 0x00000007, 0x0004003b, 0x00000007,
    0x0000004b, 0x00000007, 0x00050041, 0x0000000d, 0x0000000e, 0x0000000b, 0x0000000c, 0x0004003d, 0x00000006,
    0x0000000f, 0x0000000e, 0x00050084, 0x00000006, 0x00000011, 0x0000000f, 0x00000010, 0x0003003e, 0x00000008,
    0x00000011, 0x0003003e, 0x00000012, 0x0000000c, 0x00050041, 0x0000000d, 0x00000015, 0x00000014, 0x0000000c,
    0x0004003d, 0x00000006, 0x00000016, 0x00000015, 0x0003003e, 0x00000013, 0x00000016, 0x000200f9, 0x00000017,
    0x000200f8, 0x00000017, 0x000400f6, 0x00000019, 0x0000001a, 0x00000000, 0x000200f9, 0x0000001b, 0x000200f8,
    0x0000001b, 0x0004003d, 0x00000006, 0x0000001c, 0x00000013, 0x00050041, 0x00000022, 0x00000023, 0x0000001f,
    0x00000021, 0x0004003d, 0x00000006, 0x00000024, 0x00000023, 0x000500b0, 0x00000025, 0x00000026, 0x0000001c,
    0x00000024, 0x000400fa, 0x00000026, 0x00000018, 0x00000019, 0x000200f8, 0x00000018, 0x0004003d, 0x00000006,
    0x0000002c, 0x00000013, 0x00060041, 0x0000002d, 0x0000002e, 0x0000002b, 0x00000021, 0x0000002c, 0x0004003d,
    0x00000006, 0x0000002f, 0x0000002e, 0x00050084, 0x00000006, 0x00000031, 0x0000002f, 0x00000030, 0x00050080,
    0x00000006, 0x00000033, 0x00000031, 0x00000032, 0x00050041, 0x00000022, 0x00000035, 0x0000001f, 0x00000034,
    0x0004003d, 0x00000006, 0x00000036, 0x00000035, 0x00050080, 0x00000006, 0x00000037, 0x00000033, 0x00000036,
    0x0003003e, 0x00000027, 0x00000037, 0x0004003d, 0x00000006, 0x00000038, 0x00000013, 0x0004003d, 0x00000006,
    0x00000039, 0x00000027, 0x00060041, 0x0000002d, 0x0000003a, 0x0000002b, 0x00000021, 0x00000038, 0x0003003e,
    0x0000003a, 0x00000039, 0x0004003d, 0x00000006, 0x0000003b, 0x00000027, 0x0004003d, 0x00000006, 0x0000003c,
    0x00000012, 0x00050080, 0x00000006, 0x0000003d, 0x0000003c, 0x0000003b, 0x0003003e, 0x00000012, 0x0000003d,
    0x000200f9, 0x0000001a, 0x000200f8, 0x0000001a, 0x0004003d, 0x00000006, 0x0000003e, 0x00000008, 0x0004003d,
    0x00000006, 0x0000003f, 0x00000013, 0x00050080, 0x00000006, 0x00000040, 0x0000003f, 0x0000003e, 0x0003003e,
    0x00000013, 0x00000040, 0x000200f9, 0x00000017, 0x000200f8, 0x00000019, 0x0004003d, 0x00000006, 0x00000045,
    0x00000044, 0x0004003d, 0x00000006, 0x00000046, 0x00000012, 0x00050041, 0x00000047, 0x00000048, 0x00000043,
    0x00000045, 0x0003003e, 0x00000048, 0x00000046, 0x000400e0, 0x00000049, 0x00000049, 0x0000004a, 0x0003003e,
    0x0000004b, 0x0000004c, 0x000200f9, 0x0000004d, 0x000200f8, 0x0000004d, 0x000400f6, 0x0000004f, 0x00000050,
    0x00000000, 0x000200f9, 0x00000051, 0x000200f8, 0x00000051, 0x0004003d, 0x00000006, 0x00000052, 0x0000004b,
    0x000500ac, 0x00000025, 0x00000053, 0x00000052, 0x0000000c, 0x000400fa, 0x00000053, 0x0000004e, 0x0000004f,
    0x000200f8, 0x0000004e, 0x0004003d, 0x00000006, 0x00000054, 0x00000044, 0x0004003d, 0x00000006, 0x00000055,
    0x0000004b, 0x000500b0, 0x00000025, 0x00000056, 0x00000054, 0x00000055, 0x000300f7, 0x00000058, 0x00000000,
    0x000400fa, 0x00000056, 0x00000057, 0x00000058, 0x000200f8, 0x00000057, 0x0004003d, 0x00000006, 0x00000059,
    0x00000044, 0x0004003d, 0x00000006, 0x0000005a, 0x00000044, 0x0004003d, 0x00000006, 0x0000005b, 0x0000004b,
    0x00050080, 0x00000006, 0x0000005c, 0x0000005a, 0x0000005b, 0x00050041, 0x00000047, 0x0000005d, 0x00000043,
    0x0000005c, 0x0004003d, 0x00000006, 0x0000005e, 0x0000005d, 0x00050041, 0x00000047, 0x0000005f, 0x00000043,
    0x00000059, 0x0004003d, 0x00000006, 0x00000060, 0x0000005f, 0x00050080, 0x00000006, 0x00000061, 0x00000060,
    0x0000005e, 0x00050041, 0x00000047, 0x00000062, 0x00000043, 0x00000059, 0x0003003e, 0x00000062, 0x00000061,
    0x000200f9, 0x00000058, 0x000200f8, 0x00000058, 0x000400e0, 0x00000049, 0x00000049, 0x0000004a, 0x000200f9,
    0x00000050, 0x000200f8, 0x00000050, 0x0004003d, 0x00000006, 0x00000064, 0x0000004b, 0x000500c2, 0x00000006,
    0x00000065, 0x00000064, 0x00000063, 0x0003003e, 0x0000004b, 0x00000065, 0x000200f9, 0x0000004d, 0x000200f8,
    0x0000004f, 0x0004003d, 0x00000006, 0x00000066, 0x00000044, 0x000500aa, 0x00000025, 0x00000067, 0x00000066,
    0x0000000c, 0x000300f7, 0x00000069, 0x00000000, 0x000400fa, 0x00000067, 0x00000068, 0x00000069, 0x000200f8,
    0x00000068, 0x00050041, 0x0000000d, 0x0000006f, 0x0000006e, 0x0000000c, 0x0004003d, 0x00000006, 0x00000070,
    0x0000006f, 0x00050041, 0x00000047, 0x00000071, 0x00000043, 0x00000021, 0x0004003d, 0x00000006, 0x00000072,
    0x00000071, 0x00060041, 0x0000002d, 0x00000073, 0x0000006d, 0x00000021, 0x00000070, 0x0003003e, 0x00000073,
    0x00000072, 0x000200f9, 0x00000069, 0x000200f8, 0x00000069, 0x000100fd, 0x00010038
};

// Every dispatch reads and writes the whole big buffer. Dumping N dispatches with a per-dispatch copy of it needs N
// times this size of device memory on top of the buffer itself.
const VkDeviceSize BIG_BUFFER_SIZE = 1024ull * 1024ull * 1024ull;
const uint32_t     ELEMENT_COUNT   = static_cast<uint32_t>(BIG_BUFFER_SIZE / sizeof(uint32_t));

// One uint per workgroup: the summary each dispatch leaves behind, small enough to dump for every dispatch.
const uint32_t     WORKGROUP_COUNT    = 16384;
const VkDeviceSize RESULT_BUFFER_SIZE = WORKGROUP_COUNT * sizeof(uint32_t);

const uint32_t DISPATCH_COUNT = 16;

const int NUM_FRAMES = 2;
#define IS_RUNNING(frame_num) frame_num < NUM_FRAMES;

// Layout of the push constant block in process.comp
struct PushConstants
{
    uint32_t element_count;
    uint32_t seed;
};

void App::configure_device_builder(test::DeviceBuilder&        device_builder,
                                   test::PhysicalDevice const& physical_device,
                                   vkmock::TestConfig*         test_config)
{
    GFXRECON_UNREFERENCED_PARAMETER(physical_device);
    GFXRECON_UNREFERENCED_PARAMETER(test_config);

    // Fail allocations once the VRAM heap is full instead of spilling into system memory, so a dump-resources run
    // that keeps too many copies alive ends with VK_ERROR_OUT_OF_DEVICE_MEMORY rather than by thrashing the host.
    if (device_builder.enable_extension_if_present(VK_AMD_MEMORY_OVERALLOCATION_BEHAVIOR_EXTENSION_NAME))
    {
        overallocation_info_.sType                  = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD;
        overallocation_info_.pNext                  = nullptr;
        overallocation_info_.overallocationBehavior = VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD;
        device_builder.add_pNext(&overallocation_info_);
    }
}

void App::create_buffer(VkDeviceSize size, VkBufferUsageFlags usage, VkBuffer* buffer, VkDeviceMemory* memory)
{
    VkBufferCreateInfo buffer_info = {};
    buffer_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_info.size               = size;
    buffer_info.usage              = usage;
    buffer_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;
    VERIFY_VK_RESULT("failed to create buffer", init.disp.createBuffer(&buffer_info, nullptr, buffer));

    VkMemoryRequirements memory_requirements;
    init.disp.getBufferMemoryRequirements(*buffer, &memory_requirements);

    // Device-local only: the buffers are initialized on the GPU, so the capture does not carry their contents and
    // the copies made by dump-resources compete with them for the same heap.
    VkMemoryAllocateInfo allocate_info = {};
    allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.allocationSize       = memory_requirements.size;
    allocate_info.memoryTypeIndex =
        find_memory_type(memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    VERIFY_VK_RESULT("failed to allocate buffer memory", init.disp.allocateMemory(&allocate_info, nullptr, memory));

    VERIFY_VK_RESULT("failed to bind buffer memory", init.disp.bindBufferMemory(*buffer, *memory, 0));
}

void App::create_buffers()
{
    create_buffer(BIG_BUFFER_SIZE,
                  VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                  &big_buffer_,
                  &big_buffer_memory_);
    create_buffer(RESULT_BUFFER_SIZE,
                  VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                  &result_buffer_,
                  &result_buffer_memory_);
}

void App::initialize_buffers()
{
    // One-time GPU-side initialization, so that no buffer content goes through host memory.
    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandBufferCount          = 1;
    allocate_info.commandPool                 = command_pools_[0];
    VkCommandBuffer command_buffer;
    VERIFY_VK_RESULT("failed to allocate command buffer",
                     init.disp.allocateCommandBuffers(&allocate_info, &command_buffer));

    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    VERIFY_VK_RESULT("failed to begin command buffer", init.disp.beginCommandBuffer(command_buffer, &begin_info));

    init.disp.cmdFillBuffer(command_buffer, big_buffer_, 0, VK_WHOLE_SIZE, 1);
    init.disp.cmdFillBuffer(command_buffer, result_buffer_, 0, VK_WHOLE_SIZE, 0);

    VkMemoryBarrier barrier = {};
    barrier.sType           = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
    barrier.srcAccessMask   = VK_ACCESS_TRANSFER_WRITE_BIT;
    barrier.dstAccessMask   = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT;
    init.disp.cmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                 VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                 0,
                                 1,
                                 &barrier,
                                 0,
                                 nullptr,
                                 0,
                                 nullptr);

    VERIFY_VK_RESULT("failed to end command buffer", init.disp.endCommandBuffer(command_buffer));

    VkSubmitInfo submit_info       = {};
    submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &command_buffer;
    VERIFY_VK_RESULT("failed to submit queue", init.disp.queueSubmit(graphics_queue_, 1, &submit_info, VK_NULL_HANDLE));
    VERIFY_VK_RESULT("failed to wait for queue", init.disp.queueWaitIdle(graphics_queue_));

    init.disp.freeCommandBuffers(command_pools_[0], 1, &command_buffer);
}

void App::create_descriptor_set()
{
    VkDescriptorSetLayoutBinding bindings[2] = {};
    for (uint32_t binding = 0; binding < 2; ++binding)
    {
        bindings[binding].binding         = binding;
        bindings[binding].descriptorType  = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        bindings[binding].descriptorCount = 1;
        bindings[binding].stageFlags      = VK_SHADER_STAGE_COMPUTE_BIT;
    }

    VkDescriptorSetLayoutCreateInfo layout_info = {};
    layout_info.sType                           = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layout_info.bindingCount                    = 2;
    layout_info.pBindings                       = bindings;
    VERIFY_VK_RESULT("failed to create descriptor set layout",
                     init.disp.createDescriptorSetLayout(&layout_info, nullptr, &descriptor_set_layout_));

    VkDescriptorPoolSize pool_size = {};
    pool_size.type                 = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    pool_size.descriptorCount      = 2;

    VkDescriptorPoolCreateInfo pool_info = {};
    pool_info.sType                      = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    pool_info.maxSets                    = 1;
    pool_info.poolSizeCount              = 1;
    pool_info.pPoolSizes                 = &pool_size;
    VERIFY_VK_RESULT("failed to create descriptor pool",
                     init.disp.createDescriptorPool(&pool_info, nullptr, &descriptor_pool_));

    VkDescriptorSetAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    allocate_info.descriptorPool              = descriptor_pool_;
    allocate_info.descriptorSetCount          = 1;
    allocate_info.pSetLayouts                 = &descriptor_set_layout_;
    VERIFY_VK_RESULT("failed to allocate descriptor set",
                     init.disp.allocateDescriptorSets(&allocate_info, &descriptor_set_));

    VkDescriptorBufferInfo buffer_infos[2] = {};
    buffer_infos[0].buffer                 = big_buffer_;
    buffer_infos[0].range                  = VK_WHOLE_SIZE;
    buffer_infos[1].buffer                 = result_buffer_;
    buffer_infos[1].range                  = VK_WHOLE_SIZE;

    VkWriteDescriptorSet writes[2] = {};
    for (uint32_t binding = 0; binding < 2; ++binding)
    {
        writes[binding].sType           = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        writes[binding].dstSet          = descriptor_set_;
        writes[binding].dstBinding      = binding;
        writes[binding].descriptorCount = 1;
        writes[binding].descriptorType  = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        writes[binding].pBufferInfo     = &buffer_infos[binding];
    }
    init.disp.updateDescriptorSets(2, writes, 0, nullptr);
}

void App::create_compute_pipeline()
{
    VkShaderModuleCreateInfo shader_module_info = {};
    shader_module_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    shader_module_info.codeSize                 = sizeof(kComputeShaderSpirv);
    shader_module_info.pCode                    = kComputeShaderSpirv;
    VERIFY_VK_RESULT("failed to create compute shader module",
                     init.disp.createShaderModule(&shader_module_info, nullptr, &compute_shader_));

    VkPushConstantRange push_constant_range = {};
    push_constant_range.stageFlags          = VK_SHADER_STAGE_COMPUTE_BIT;
    push_constant_range.offset              = 0;
    push_constant_range.size                = sizeof(PushConstants);

    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.setLayoutCount             = 1;
    pipeline_layout_info.pSetLayouts                = &descriptor_set_layout_;
    pipeline_layout_info.pushConstantRangeCount     = 1;
    pipeline_layout_info.pPushConstantRanges        = &push_constant_range;
    VERIFY_VK_RESULT("failed to create pipeline layout",
                     init.disp.createPipelineLayout(&pipeline_layout_info, nullptr, &pipeline_layout_));

    VkComputePipelineCreateInfo pipeline_info = {};
    pipeline_info.sType                       = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
    pipeline_info.stage.sType                 = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    pipeline_info.stage.stage                 = VK_SHADER_STAGE_COMPUTE_BIT;
    pipeline_info.stage.module                = compute_shader_;
    pipeline_info.stage.pName                 = "main";
    pipeline_info.layout                      = pipeline_layout_;
    VERIFY_VK_RESULT("failed to create compute pipeline",
                     init.disp.createComputePipelines(VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &compute_pipeline_));
}

bool App::frame(const int frame_num)
{
    init.disp.waitForFences(1, &sync_.in_flight_fences[current_frame_], VK_TRUE, UINT64_MAX);

    uint32_t image_index = 0;
    VkResult result      = init.disp.acquireNextImageKHR(
        init.swapchain, UINT64_MAX, sync_.available_semaphores[current_frame_], VK_NULL_HANDLE, &image_index);

    if (result == VK_ERROR_OUT_OF_DATE_KHR)
    {
        recreate_swapchain(true);
        return IS_RUNNING(frame_num);
    }
    else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
    {
        throw test::vulkan_exception("failed to acquire next image", result);
    }

    if (sync_.image_in_flight[image_index] != VK_NULL_HANDLE)
    {
        init.disp.waitForFences(1, &sync_.image_in_flight[image_index], VK_TRUE, UINT64_MAX);
    }
    sync_.image_in_flight[image_index] = sync_.in_flight_fences[current_frame_];

    init.disp.resetCommandPool(command_pools_[current_frame_], 0);
    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandBufferCount          = 1;
    allocate_info.commandPool                 = command_pools_[current_frame_];
    VkCommandBuffer command_buffer;
    result = init.disp.allocateCommandBuffers(&allocate_info, &command_buffer);
    VERIFY_VK_RESULT("failed to allocate command buffer", result);

    {
        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        result                              = init.disp.beginCommandBuffer(command_buffer, &begin_info);
        VERIFY_VK_RESULT("failed to begin command buffer", result);

        // The test does not render: transition the acquired image straight to PRESENT_SRC so it can be presented.
        {
            VkImageMemoryBarrier image_barrier        = {};
            image_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            image_barrier.image                       = init.swapchain_images[image_index];
            image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
            image_barrier.newLayout                   = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
            image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            image_barrier.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
            image_barrier.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
            image_barrier.srcAccessMask               = VK_ACCESS_NONE;
            image_barrier.dstAccessMask               = VK_ACCESS_NONE;
            init.disp.cmdPipelineBarrier(command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &image_barrier);
        }

        init.disp.cmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, compute_pipeline_);
        init.disp.cmdBindDescriptorSets(
            command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_layout_, 0, 1, &descriptor_set_, 0, nullptr);

        // Every dispatch rewrites the whole big buffer from what the previous one left, so the dispatches are
        // serialized with a compute-to-compute barrier. A different seed per dispatch keeps their results apart.
        VkMemoryBarrier barrier = {};
        barrier.sType           = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
        barrier.srcAccessMask   = VK_ACCESS_SHADER_WRITE_BIT;
        barrier.dstAccessMask   = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT;

        for (uint32_t dispatch = 0; dispatch < DISPATCH_COUNT; ++dispatch)
        {
            const PushConstants push_constants{ ELEMENT_COUNT,
                                                static_cast<uint32_t>(frame_num) * DISPATCH_COUNT + dispatch + 1 };
            init.disp.cmdPushConstants(command_buffer,
                                       pipeline_layout_,
                                       VK_SHADER_STAGE_COMPUTE_BIT,
                                       0,
                                       sizeof(push_constants),
                                       &push_constants);
            init.disp.cmdDispatch(command_buffer, WORKGROUP_COUNT, 1, 1);
            init.disp.cmdPipelineBarrier(command_buffer,
                                         VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                         VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                         0,
                                         1,
                                         &barrier,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr);
        }

        result = init.disp.endCommandBuffer(command_buffer);
        VERIFY_VK_RESULT("failed to end command buffer", result);
    }

    VkSubmitInfo submitInfo = {};
    submitInfo.sType        = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore          wait_semaphores[] = { sync_.available_semaphores[current_frame_] };
    VkPipelineStageFlags wait_stages[]     = { VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT };
    submitInfo.waitSemaphoreCount          = 1;
    submitInfo.pWaitSemaphores             = wait_semaphores;
    submitInfo.pWaitDstStageMask           = wait_stages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers    = &command_buffer;

    VkSemaphore signal_semaphores[] = { sync_.finished_semaphore[image_index] };
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores    = signal_semaphores;

    init.disp.resetFences(1, &sync_.in_flight_fences[current_frame_]);

    result = init.disp.queueSubmit(graphics_queue_, 1, &submitInfo, sync_.in_flight_fences[current_frame_]);
    VERIFY_VK_RESULT("failed to submit queue", result);

    VkPresentInfoKHR present_info = {};
    present_info.sType            = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    present_info.waitSemaphoreCount = 1;
    present_info.pWaitSemaphores    = signal_semaphores;

    VkSwapchainKHR swapChains[] = { init.swapchain };
    present_info.swapchainCount = 1;
    present_info.pSwapchains    = swapChains;

    present_info.pImageIndices = &image_index;

    result = init.disp.queuePresentKHR(present_queue_, &present_info);
    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR)
    {
        recreate_swapchain(true);
        return frame_num >= NUM_FRAMES;
    }
    VERIFY_VK_RESULT("failed to present queue", result);

    current_frame_ = (current_frame_ + 1) % MAX_FRAMES_IN_FLIGHT;

    return IS_RUNNING(frame_num);
}

void App::cleanup()
{
    init.disp.destroyPipeline(compute_pipeline_, nullptr);
    init.disp.destroyPipelineLayout(pipeline_layout_, nullptr);
    init.disp.destroyShaderModule(compute_shader_, nullptr);

    init.disp.destroyDescriptorPool(descriptor_pool_, nullptr);
    init.disp.destroyDescriptorSetLayout(descriptor_set_layout_, nullptr);

    init.disp.destroyBuffer(big_buffer_, nullptr);
    init.disp.freeMemory(big_buffer_memory_, nullptr);
    init.disp.destroyBuffer(result_buffer_, nullptr);
    init.disp.freeMemory(result_buffer_memory_, nullptr);

    for (size_t i = 0; i < sync_.finished_semaphore.size(); ++i)
    {
        init.disp.destroySemaphore(sync_.finished_semaphore[i], nullptr);
    }
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
    {
        init.disp.destroySemaphore(sync_.available_semaphores[i], nullptr);
        init.disp.destroyFence(sync_.in_flight_fences[i], nullptr);
    }

    for (auto command_pool : command_pools_)
    {
        init.disp.destroyCommandPool(command_pool, nullptr);
    }
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    auto present_queue = init.device.get_queue(test::QueueType::present);
    if (!present_queue.has_value())
        throw std::runtime_error("could not get present queue");
    present_queue_ = *present_queue;

    auto queue_family_index = init.device.get_queue_index(test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    for (auto& command_pool : command_pools_)
    {
        command_pool = test::create_command_pool(init.disp, *queue_family_index);
    }

    sync_ = test::create_sync_objects(init.swapchain, init.disp, MAX_FRAMES_IN_FLIGHT);

    create_buffers();
    create_descriptor_set();
    create_compute_pipeline();
    initialize_buffers();
}

GFXRECON_END_NAMESPACE(dispatch_big_buffers)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
