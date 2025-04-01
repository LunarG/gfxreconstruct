/*
** Copyright (c) 2024 LunarG, Inc.
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

#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include <iostream>

#include <vulkan/vulkan_core.h>

#include <util/logging.h>

#include <test_app_base.h>

#ifdef __linux__
#define HAVE_MSGHDR_MSG_CONTROL
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

GFXRECON_BEGIN_NAMESPACE(test_app)

GFXRECON_BEGIN_NAMESPACE(external_memory_fd_export)

class App : public gfxrecon::test::TestAppBase
{
  public:
    App()                      = default;
    virtual ~App()             = default;
    App(const App&)            = delete;
    App& operator=(const App&) = delete;
    App(App&&)                 = delete;
    App& operator=(App&&)      = delete;

  private:
    const uint32_t buffer_size_       = sizeof(uint32_t[42]);
    VkBuffer       buffer_            = VK_NULL_HANDLE;
    VkDeviceMemory exportable_memory_ = VK_NULL_HANDLE;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config) override;
    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                            vkmock::TestConfig*           test_config) override;

    uint32_t find_memory_type(uint32_t memoryTypeBits, VkMemoryPropertyFlags memory_property_flags);
    void     create_buffer();

    int     get_exportable_fd();
    void    send_exportable_fd(int exportable_fd);
    ssize_t send_int(int conn_fd, int data);

    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;
};

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    instance_builder.enable_extension(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME);
    instance_builder.set_headless(true);
}

void App::configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                             vkmock::TestConfig*           test_config)
{
    phys_device_selector.add_required_extension(VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME);
    phys_device_selector.add_required_extension(VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME);
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

    throw std::runtime_error("Export App Could not find required memory type");
}

void App::create_buffer()
{
    VkExternalMemoryBufferCreateInfo external_mem_buf_create_info = {};
    external_mem_buf_create_info.sType       = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO;
    external_mem_buf_create_info.handleTypes = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT;

    VkBufferCreateInfo buffer_create_info    = {};
    buffer_create_info.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.pNext                 = &external_mem_buf_create_info;
    buffer_create_info.flags                 = 0u;
    buffer_create_info.size                  = buffer_size_;
    buffer_create_info.usage                 = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    buffer_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    buffer_create_info.queueFamilyIndexCount = 0u;
    buffer_create_info.pQueueFamilyIndices   = nullptr;
    VkResult result                          = init.disp.createBuffer(&buffer_create_info, nullptr, &buffer_);
    VERIFY_VK_RESULT("Export App Failed to create buffer", result);

    VkMemoryRequirements buf_mem_requirements;
    init.disp.getBufferMemoryRequirements(buffer_, &buf_mem_requirements);

    VkExportMemoryAllocateInfo export_mem_alloc_info = {};
    export_mem_alloc_info.sType                      = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO;
    export_mem_alloc_info.handleTypes                = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT;

    VkMemoryAllocateInfo buf_mem_allocate_info;
    buf_mem_allocate_info.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    buf_mem_allocate_info.pNext          = &export_mem_alloc_info;
    buf_mem_allocate_info.allocationSize = buf_mem_requirements.size;
    buf_mem_allocate_info.memoryTypeIndex =
        find_memory_type(buf_mem_requirements.memoryTypeBits,
                         VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    result = init.disp.allocateMemory(&buf_mem_allocate_info, nullptr, &exportable_memory_);
    VERIFY_VK_RESULT("Export App Failed to exportable memory", result);

    result = init.disp.bindBufferMemory(buffer_, exportable_memory_, 0u);
    VERIFY_VK_RESULT("Export App Failed to bind memory", result);

    uint32_t* data = nullptr;
    result         = init.disp.mapMemory(exportable_memory_, 0u, buffer_size_, 0u, reinterpret_cast<void**>(&data));
    VERIFY_VK_RESULT("Export App Failed to map buffer memory", result);
    for (uint32_t i = 0; i < buffer_size_ / sizeof(uint32_t); ++i)
    {
        data[i] = i;
    }

    init.disp.unmapMemory(exportable_memory_);
}

int App::get_exportable_fd()
{
    VkMemoryGetFdInfoKHR get_fd_info = {};
    get_fd_info.sType                = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
    get_fd_info.handleType           = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT;
    get_fd_info.memory               = exportable_memory_;

    int      exportable_fd = -1;
    VkResult result        = init.disp.getMemoryFdKHR(&get_fd_info, &exportable_fd);
    VERIFY_VK_RESULT("Export App Failed to get memory fd", result);
    return exportable_fd;
}

void App::send_exportable_fd(int exportable_fd)
{
    // Need to send the fd to the importer process
    int external_socket = socket(PF_UNIX, SOCK_STREAM, 0);
    if (external_socket < 0)
    {
        GFXRECON_LOG_ERROR("Export App Failed to create socket (%d)", external_socket);
    }
    sockaddr_un un = {};
    un.sun_family  = AF_UNIX;

    const char* socket_name = "/tmp/.external-memory";
    snprintf(un.sun_path, sizeof(un.sun_path), "%s", socket_name);
    unlink(un.sun_path);

    int result = bind(external_socket, reinterpret_cast<struct sockaddr*>(&un), sizeof(un));
    if (result)
    {
        GFXRECON_LOG_ERROR("Export App Failed to bind socket (%d)", result);
    }

    result = listen(external_socket, 1);
    if (result < 0)
    {
        GFXRECON_LOG_ERROR("Export App Failed to listen on socket (%d)", result);
    }

    GFXRECON_LOG_INFO("Waiting for importer to connect");
    // Blocking
    int conn_fd = accept(external_socket, nullptr, nullptr);
    if (conn_fd < 0)
    {
        GFXRECON_LOG_ERROR("Export App Failed to accept on socket (%d)", conn_fd);
    }

    // Send fd
    ssize_t send_result = send_int(conn_fd, exportable_fd);
    if (send_result < 0)
    {
        GFXRECON_LOG_ERROR("Export App Failed to send_int on socket (%d)", send_result);
    }

    close(conn_fd);
    close(external_socket);
}

ssize_t App::send_int(int conn_fd, int data)
{
    struct msghdr msg = {};
    struct iovec  iov[1];

#ifdef HAVE_MSGHDR_MSG_CONTROL
    union
    {
        struct cmsghdr cm;
        char           control[CMSG_SPACE(sizeof(int))];
    } control_un = {};

    msg.msg_control    = control_un.control;
    msg.msg_controllen = sizeof(control_un.control);

    struct cmsghdr* cmptr                     = CMSG_FIRSTHDR(&msg);
    cmptr->cmsg_len                           = CMSG_LEN(sizeof(int));
    cmptr->cmsg_level                         = SOL_SOCKET;
    cmptr->cmsg_type                          = SCM_RIGHTS;
    *reinterpret_cast<int*>(CMSG_DATA(cmptr)) = data;
#else
    msg.msg_accrights    = (caddr_t)&data;
    msg.msg_accrightslen = sizeof(int);
#endif

    msg.msg_name    = NULL;
    msg.msg_namelen = 0;

    char c[]        = "1";
    iov[0].iov_base = c;
    iov[0].iov_len  = 1;
    msg.msg_iov     = iov;
    msg.msg_iovlen  = 1;

    return sendmsg(conn_fd, &msg, 0);
}

bool App::frame(const int frame_num)
{
    return false;
}

void App::cleanup()
{
    init.disp.destroyBuffer(buffer_, nullptr);
    init.disp.freeMemory(exportable_memory_, nullptr);
}

void App::setup()
{
    create_buffer();
    int fd = get_exportable_fd();
    GFXRECON_LOG_INFO("Exporting fd (%d)", fd);
    send_exportable_fd(fd);
}

GFXRECON_END_NAMESPACE(external_memory_fd_export)

GFXRECON_END_NAMESPACE(test_app)

GFXRECON_END_NAMESPACE(gfxrecon)

int main(int argc, char* argv[])
{
    try
    {
        gfxrecon::test_app::external_memory_fd_export::App app;
        app.run("external memory fd export");
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}
