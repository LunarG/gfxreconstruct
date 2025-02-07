/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#include <test_app_base.h>

#include <SDL3/SDL_main.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

GFXRECON_BEGIN_NAMESPACE(test_app)

GFXRECON_BEGIN_NAMESPACE(host_image_copy)

class App : public gfxrecon::test::TestAppBase
{
  public:
    App() = default;

  private:
    VkPhysicalDeviceHostImageCopyFeaturesEXT host_image_copy_features_;

    VkQueue  queue_;
    uint32_t queue_index_;

    const uint32_t image_width_  = 256u;
    const uint32_t image_height_ = 256u;
    const uint32_t buffer_size_  = image_width_ * image_height_ * 4u;

    VkBuffer       src_buffer_;
    VkDeviceMemory src_buffer_memory_;
    VkBuffer       dst_buffer_;
    VkDeviceMemory dst_buffer_memory_;
    VkImage        src_image_;
    VkDeviceMemory src_image_memory_;
    VkImage        dst_image_;
    VkDeviceMemory dst_image_memory_;

    VkCommandPool   command_pool_;
    VkCommandBuffer command_buffer_;
    VkFence         fence_;

    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector) override;

    void configure_device_builder(test::DeviceBuilder&        device_builder,
                                  test::PhysicalDevice const& physical_device) override;

    uint32_t find_memory_type(uint32_t memoryTypeBits, VkMemoryPropertyFlags memory_property_flags);
    void     create_buffers_and_images();
    void     allocate_command_buffer();
    void     cleanup() override;
    bool     frame(const int frame_num) override;
    void     setup() override;
};

void App::configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector)
{
    phys_device_selector.add_required_extension("VK_KHR_copy_commands2");
    phys_device_selector.add_required_extension("VK_KHR_format_feature_flags2");
    phys_device_selector.add_required_extension("VK_EXT_host_image_copy");
}

void App::configure_device_builder(test::DeviceBuilder& device_builder, test::PhysicalDevice const& physical_device)
{
    host_image_copy_features_.sType         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT;
    host_image_copy_features_.pNext         = nullptr;
    host_image_copy_features_.hostImageCopy = VK_TRUE;
    device_builder.add_pNext(&host_image_copy_features_);
}

uint32_t App::find_memory_type(uint32_t memoryTypeBits, VkMemoryPropertyFlags memory_property_flags)
{
    VkPhysicalDeviceMemoryProperties memory_properties;
    init.inst_disp.getPhysicalDeviceMemoryProperties(init.physical_device, &memory_properties);

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        if ((memoryTypeBits & (1 << i)) && (memory_properties.memoryTypes[i].propertyFlags & memory_property_flags) > 0)
        {
            return i;
            break;
        }
    }

    throw std::runtime_error("Could not find required memory type");
}

void App::create_buffers_and_images()
{
    VkBufferCreateInfo buffer_create_info;
    buffer_create_info.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.pNext                 = nullptr;
    buffer_create_info.flags                 = 0u;
    buffer_create_info.size                  = buffer_size_;
    buffer_create_info.usage                 = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    buffer_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    buffer_create_info.queueFamilyIndexCount = 0u;
    buffer_create_info.pQueueFamilyIndices   = nullptr;
    init.disp.createBuffer(&buffer_create_info, nullptr, &src_buffer_);

    VkMemoryRequirements src_buffer_memory_requirements;
    init.disp.getBufferMemoryRequirements(src_buffer_, &src_buffer_memory_requirements);

    VkMemoryAllocateInfo src_buffer_memory_allocate_info;
    src_buffer_memory_allocate_info.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    src_buffer_memory_allocate_info.pNext          = nullptr;
    src_buffer_memory_allocate_info.allocationSize = src_buffer_memory_requirements.size;
    src_buffer_memory_allocate_info.memoryTypeIndex =
        find_memory_type(src_buffer_memory_requirements.memoryTypeBits,
                         VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    init.disp.allocateMemory(&src_buffer_memory_allocate_info, nullptr, &src_buffer_memory_);
    init.disp.bindBufferMemory(src_buffer_, src_buffer_memory_, 0u);

    buffer_create_info.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    init.disp.createBuffer(&buffer_create_info, nullptr, &dst_buffer_);

    VkMemoryRequirements dst_buffer_memory_requirements;
    init.disp.getBufferMemoryRequirements(dst_buffer_, &dst_buffer_memory_requirements);

    VkMemoryAllocateInfo dst_buffer_memory_allocate_info;
    dst_buffer_memory_allocate_info.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    dst_buffer_memory_allocate_info.pNext          = nullptr;
    dst_buffer_memory_allocate_info.allocationSize = dst_buffer_memory_requirements.size;
    dst_buffer_memory_allocate_info.memoryTypeIndex =
        find_memory_type(dst_buffer_memory_requirements.memoryTypeBits,
                         VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    init.disp.allocateMemory(&dst_buffer_memory_allocate_info, nullptr, &dst_buffer_memory_);
    init.disp.bindBufferMemory(dst_buffer_, dst_buffer_memory_, 0u);

    VkImageCreateInfo image_create_info;
    image_create_info.sType       = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_create_info.pNext       = nullptr;
    image_create_info.flags       = 0u;
    image_create_info.imageType   = VK_IMAGE_TYPE_2D;
    image_create_info.format      = VK_FORMAT_R8G8B8A8_UNORM;
    image_create_info.extent      = { image_width_, image_height_, 1u };
    image_create_info.mipLevels   = 1u;
    image_create_info.arrayLayers = 1u;
    image_create_info.samples     = VK_SAMPLE_COUNT_1_BIT;
    image_create_info.tiling      = VK_IMAGE_TILING_OPTIMAL;
    image_create_info.usage =
        VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT;
    image_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    image_create_info.queueFamilyIndexCount = 0u;
    image_create_info.pQueueFamilyIndices   = nullptr;
    image_create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;
    init.disp.createImage(&image_create_info, nullptr, &src_image_);

    VkMemoryRequirements src_image_memory_requirements;
    init.disp.getImageMemoryRequirements(src_image_, &src_image_memory_requirements);

    VkMemoryAllocateInfo src_image_memory_allocate_info;
    src_image_memory_allocate_info.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    src_image_memory_allocate_info.pNext          = nullptr;
    src_image_memory_allocate_info.allocationSize = src_image_memory_requirements.size;
    src_image_memory_allocate_info.memoryTypeIndex =
        find_memory_type(src_image_memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    init.disp.allocateMemory(&src_image_memory_allocate_info, nullptr, &src_image_memory_);
    init.disp.bindImageMemory(src_image_, src_image_memory_, 0u);

    init.disp.createImage(&image_create_info, nullptr, &dst_image_);

    VkMemoryRequirements dst_image_memory_requirements;
    init.disp.getImageMemoryRequirements(src_image_, &dst_image_memory_requirements);

    VkMemoryAllocateInfo dst_image_memory_allocate_info;
    dst_image_memory_allocate_info.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    dst_image_memory_allocate_info.pNext          = nullptr;
    dst_image_memory_allocate_info.allocationSize = dst_image_memory_requirements.size;
    dst_image_memory_allocate_info.memoryTypeIndex =
        find_memory_type(dst_image_memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    init.disp.allocateMemory(&dst_image_memory_allocate_info, nullptr, &dst_image_memory_);
    init.disp.bindImageMemory(dst_image_, dst_image_memory_, 0u);
}

void App::allocate_command_buffer()
{
    VkCommandPoolCreateInfo command_pool_create_info;
    command_pool_create_info.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    command_pool_create_info.pNext            = nullptr;
    command_pool_create_info.flags            = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    command_pool_create_info.queueFamilyIndex = queue_index_;
    init.disp.createCommandPool(&command_pool_create_info, nullptr, &command_pool_);

    VkCommandBufferAllocateInfo command_buffer_allocate_info;
    command_buffer_allocate_info.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    command_buffer_allocate_info.pNext              = nullptr;
    command_buffer_allocate_info.commandPool        = command_pool_;
    command_buffer_allocate_info.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    command_buffer_allocate_info.commandBufferCount = 1u;
    init.disp.allocateCommandBuffers(&command_buffer_allocate_info, &command_buffer_);
}

bool App::frame(const int frame_num)
{
    VkResult result = VK_SUCCESS;

    bool memory_to_image = frame_num == 0;

    VkHostImageLayoutTransitionInfoEXT host_image_layout_transition_infos[2];
    host_image_layout_transition_infos[0].sType     = VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT;
    host_image_layout_transition_infos[0].pNext     = nullptr;
    host_image_layout_transition_infos[0].image     = src_image_;
    host_image_layout_transition_infos[0].oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    host_image_layout_transition_infos[0].newLayout = VK_IMAGE_LAYOUT_GENERAL;
    host_image_layout_transition_infos[0].subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    host_image_layout_transition_infos[0].subresourceRange.baseMipLevel   = 0u;
    host_image_layout_transition_infos[0].subresourceRange.levelCount     = 1u;
    host_image_layout_transition_infos[0].subresourceRange.baseArrayLayer = 0u;
    host_image_layout_transition_infos[0].subresourceRange.layerCount     = 1u;
    host_image_layout_transition_infos[1].sType     = VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT;
    host_image_layout_transition_infos[1].pNext     = nullptr;
    host_image_layout_transition_infos[1].image     = dst_image_;
    host_image_layout_transition_infos[1].oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    host_image_layout_transition_infos[1].newLayout = VK_IMAGE_LAYOUT_GENERAL;
    host_image_layout_transition_infos[1].subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    host_image_layout_transition_infos[1].subresourceRange.baseMipLevel   = 0u;
    host_image_layout_transition_infos[1].subresourceRange.levelCount     = 1u;
    host_image_layout_transition_infos[1].subresourceRange.baseArrayLayer = 0u;
    host_image_layout_transition_infos[1].subresourceRange.layerCount     = 1u;
    result = init.disp.transitionImageLayoutEXT(2u, host_image_layout_transition_infos);
    VERIFY_VK_RESULT("failed to transition image layouts", result);

    uint32_t* src_data;
    result = init.disp.mapMemory(src_buffer_memory_, 0u, buffer_size_, 0u, (void**)&src_data);
    VERIFY_VK_RESULT("failed to map src buffer memory", result);
    for (uint32_t i = 0; i < buffer_size_ / sizeof(uint32_t); ++i)
    {
        src_data[i] = i + 1;
    }

    uint32_t* dst_data;
    result = init.disp.mapMemory(dst_buffer_memory_, 0u, buffer_size_, 0u, (void**)&dst_data);
    VERIFY_VK_RESULT("failed to map memory", result);

    if (memory_to_image)
    {
        VkMemoryToImageCopyEXT memory_to_image_copy;
        memory_to_image_copy.sType                           = VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT;
        memory_to_image_copy.pNext                           = nullptr;
        memory_to_image_copy.pHostPointer                    = src_data;
        memory_to_image_copy.memoryRowLength                 = 0u;
        memory_to_image_copy.memoryImageHeight               = 0u;
        memory_to_image_copy.imageSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        memory_to_image_copy.imageSubresource.mipLevel       = 0u;
        memory_to_image_copy.imageSubresource.baseArrayLayer = 0u;
        memory_to_image_copy.imageSubresource.layerCount     = 1u;
        memory_to_image_copy.imageOffset                     = { 0, 0, 0 };
        memory_to_image_copy.imageExtent                     = { image_width_, image_height_, 1u };

        VkCopyMemoryToImageInfoEXT copy_memory_to_image_info;
        copy_memory_to_image_info.sType          = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT;
        copy_memory_to_image_info.pNext          = nullptr;
        copy_memory_to_image_info.flags          = 0u;
        copy_memory_to_image_info.dstImage       = src_image_;
        copy_memory_to_image_info.dstImageLayout = VK_IMAGE_LAYOUT_GENERAL;
        copy_memory_to_image_info.regionCount    = 1u;
        copy_memory_to_image_info.pRegions       = &memory_to_image_copy;
        result                                   = init.disp.copyMemoryToImageEXT(&copy_memory_to_image_info);
        VERIFY_VK_RESULT("failed to copy memory to image", result);
    }
    else
    {
        VkCommandBufferBeginInfo command_buffer_begin_info;
        command_buffer_begin_info.sType            = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        command_buffer_begin_info.pNext            = nullptr;
        command_buffer_begin_info.flags            = 0u;
        command_buffer_begin_info.pInheritanceInfo = nullptr;
        result = init.disp.beginCommandBuffer(command_buffer_, &command_buffer_begin_info);
        VERIFY_VK_RESULT("failed to begin command buffer", result);

        VkBufferImageCopy buffer_image_copy;
        buffer_image_copy.bufferOffset                    = 0u;
        buffer_image_copy.bufferRowLength                 = 0u;
        buffer_image_copy.bufferImageHeight               = 0u;
        buffer_image_copy.imageSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        buffer_image_copy.imageSubresource.mipLevel       = 0u;
        buffer_image_copy.imageSubresource.baseArrayLayer = 0u;
        buffer_image_copy.imageSubresource.layerCount     = 1u;
        buffer_image_copy.imageOffset                     = { 0, 0, 0 };
        buffer_image_copy.imageExtent                     = { image_width_, image_height_, 1u };
        init.disp.cmdCopyBufferToImage(
            command_buffer_, src_buffer_, src_image_, VK_IMAGE_LAYOUT_GENERAL, 1u, &buffer_image_copy);

        result = init.disp.endCommandBuffer(command_buffer_);
        VERIFY_VK_RESULT("failed to end command buffer", result);

        result = init.disp.resetFences(1u, &fence_);
        VERIFY_VK_RESULT("failed to reset fence", result);

        VkSubmitInfo submit_info;
        submit_info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submit_info.pNext                = nullptr;
        submit_info.waitSemaphoreCount   = 0u;
        submit_info.pWaitSemaphores      = nullptr;
        submit_info.pWaitDstStageMask    = nullptr;
        submit_info.commandBufferCount   = 1u;
        submit_info.pCommandBuffers      = &command_buffer_;
        submit_info.signalSemaphoreCount = 0u;
        submit_info.pSignalSemaphores    = nullptr;
        result                           = init.disp.queueSubmit(queue_, 1u, &submit_info, fence_);
        VERIFY_VK_RESULT("failed to submit command buffer", result);
        result = init.disp.waitForFences(1u, &fence_, VK_TRUE, UINT64_MAX);
        VERIFY_VK_RESULT("failed to wait for fences", result);
    }

    VkImageCopy2 image_copy;
    image_copy.sType                         = VK_STRUCTURE_TYPE_IMAGE_COPY_2;
    image_copy.pNext                         = nullptr;
    image_copy.srcSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    image_copy.srcSubresource.mipLevel       = 0u;
    image_copy.srcSubresource.baseArrayLayer = 0u;
    image_copy.srcSubresource.layerCount     = 1u;
    image_copy.srcOffset                     = { 0, 0, 0 };
    image_copy.dstSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    image_copy.dstSubresource.mipLevel       = 0u;
    image_copy.dstSubresource.baseArrayLayer = 0u;
    image_copy.dstSubresource.layerCount     = 1u;
    image_copy.dstOffset                     = { 0, 0, 0 };
    image_copy.extent                        = { image_width_, image_height_, 1u };

    VkCopyImageToImageInfoEXT copy_image_to_image_info;
    copy_image_to_image_info.sType          = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT;
    copy_image_to_image_info.pNext          = nullptr;
    copy_image_to_image_info.flags          = 0u;
    copy_image_to_image_info.srcImage       = src_image_;
    copy_image_to_image_info.srcImageLayout = VK_IMAGE_LAYOUT_GENERAL;
    copy_image_to_image_info.dstImage       = dst_image_;
    copy_image_to_image_info.dstImageLayout = VK_IMAGE_LAYOUT_GENERAL;
    copy_image_to_image_info.regionCount    = 1u;
    copy_image_to_image_info.pRegions       = &image_copy;
    result                                  = init.disp.copyImageToImageEXT(&copy_image_to_image_info);
    VERIFY_VK_RESULT("failed to copy image to image", result);

    if (memory_to_image)
    {
        VkImageToMemoryCopyEXT image_to_memory_copy;
        image_to_memory_copy.sType                           = VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT;
        image_to_memory_copy.pNext                           = nullptr;
        image_to_memory_copy.pHostPointer                    = dst_data;
        image_to_memory_copy.memoryRowLength                 = 0u;
        image_to_memory_copy.memoryImageHeight               = 0u;
        image_to_memory_copy.imageSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        image_to_memory_copy.imageSubresource.mipLevel       = 0u;
        image_to_memory_copy.imageSubresource.baseArrayLayer = 0u;
        image_to_memory_copy.imageSubresource.layerCount     = 1u;
        image_to_memory_copy.imageOffset                     = { 0, 0, 0 };
        image_to_memory_copy.imageExtent                     = { image_width_, image_height_, 1u };

        VkCopyImageToMemoryInfoEXT copy_image_to_memory_info;
        copy_image_to_memory_info.sType          = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT;
        copy_image_to_memory_info.pNext          = nullptr;
        copy_image_to_memory_info.flags          = 0u;
        copy_image_to_memory_info.srcImage       = dst_image_;
        copy_image_to_memory_info.srcImageLayout = VK_IMAGE_LAYOUT_GENERAL;
        copy_image_to_memory_info.regionCount    = 1u;
        copy_image_to_memory_info.pRegions       = &image_to_memory_copy;
        init.disp.copyImageToMemoryEXT(&copy_image_to_memory_info);
    }
    else
    {
        VkCommandBufferBeginInfo command_buffer_begin_info;
        command_buffer_begin_info.sType            = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        command_buffer_begin_info.pNext            = nullptr;
        command_buffer_begin_info.flags            = 0u;
        command_buffer_begin_info.pInheritanceInfo = nullptr;
        result = init.disp.beginCommandBuffer(command_buffer_, &command_buffer_begin_info);
        VERIFY_VK_RESULT("failed to begin command buffer", result);

        VkBufferImageCopy buffer_image_copy;
        buffer_image_copy.bufferOffset                    = 0u;
        buffer_image_copy.bufferRowLength                 = 0u;
        buffer_image_copy.bufferImageHeight               = 0u;
        buffer_image_copy.imageSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        buffer_image_copy.imageSubresource.mipLevel       = 0u;
        buffer_image_copy.imageSubresource.baseArrayLayer = 0u;
        buffer_image_copy.imageSubresource.layerCount     = 1u;
        buffer_image_copy.imageOffset                     = { 0, 0, 0 };
        buffer_image_copy.imageExtent                     = { image_width_, image_height_, 1u };
        init.disp.cmdCopyImageToBuffer(
            command_buffer_, dst_image_, VK_IMAGE_LAYOUT_GENERAL, dst_buffer_, 1u, &buffer_image_copy);

        result = init.disp.endCommandBuffer(command_buffer_);
        VERIFY_VK_RESULT("failed to end command buffer", result);

        result = init.disp.resetFences(1u, &fence_);
        VERIFY_VK_RESULT("failed to reset fence", result);

        VkSubmitInfo submit_info;
        submit_info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submit_info.pNext                = nullptr;
        submit_info.waitSemaphoreCount   = 0u;
        submit_info.pWaitSemaphores      = nullptr;
        submit_info.pWaitDstStageMask    = nullptr;
        submit_info.commandBufferCount   = 1u;
        submit_info.pCommandBuffers      = &command_buffer_;
        submit_info.signalSemaphoreCount = 0u;
        submit_info.pSignalSemaphores    = nullptr;
        result                           = init.disp.queueSubmit(queue_, 1u, &submit_info, fence_);
        VERIFY_VK_RESULT("failed to submit command buffer", result);
        result = init.disp.waitForFences(1u, &fence_, VK_TRUE, UINT64_MAX);
        VERIFY_VK_RESULT("failed to wait for fence", result);
    }

    if (memcmp(src_data, dst_data, buffer_size_) != 0)
    {
        throw std::runtime_error("memory does not match");
    }

    init.disp.unmapMemory(src_buffer_memory_);
    init.disp.unmapMemory(dst_buffer_memory_);

    return frame_num < 1;
}

void App::cleanup()
{
    init.disp.destroyBuffer(src_buffer_, nullptr);
    init.disp.freeMemory(src_buffer_memory_, nullptr);
    init.disp.destroyBuffer(dst_buffer_, nullptr);
    init.disp.freeMemory(dst_buffer_memory_, nullptr);
    init.disp.destroyImage(src_image_, nullptr);
    init.disp.freeMemory(src_image_memory_, nullptr);
    init.disp.destroyImage(dst_image_, nullptr);
    init.disp.freeMemory(dst_image_memory_, nullptr);

    init.disp.destroyCommandPool(command_pool_, nullptr);
    init.disp.destroyFence(fence_, nullptr);
}

void App::setup()
{
    auto transfer_queue = init.device.get_queue(gfxrecon::test::QueueType::transfer);
    if (!transfer_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    queue_       = *transfer_queue;
    queue_index_ = init.device.get_queue_index(gfxrecon::test::QueueType::transfer).value();

    create_buffers_and_images();
    allocate_command_buffer();

    VkFenceCreateInfo fence_create_info;
    fence_create_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fence_create_info.pNext = nullptr;
    fence_create_info.flags = 0u;
    init.disp.createFence(&fence_create_info, nullptr, &fence_);
}

GFXRECON_END_NAMESPACE(host_image_copy)

GFXRECON_END_NAMESPACE(test_app)

GFXRECON_END_NAMESPACE(gfxrecon)

int main(int argc, char* argv[])
{
    try
    {
        gfxrecon::test_app::host_image_copy::App app{};
        app.run("host image copy");
        return 0;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }
}
