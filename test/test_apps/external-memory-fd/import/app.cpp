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

GFXRECON_BEGIN_NAMESPACE(external_memory_fd_import)

class App : public gfxrecon::test::TestAppBase
{
  public:
    App();
    virtual ~App()             = default;
    App(const App&)            = delete;
    App& operator=(const App&) = delete;
    App(App&&)                 = delete;
    App& operator=(App&&)      = delete;

  private:
    constexpr static size_t EXPECTED_MEMORY_LEN = 42;

    uint32_t       expected_memory_[EXPECTED_MEMORY_LEN] = {};
    const uint32_t buffer_size_                          = sizeof(expected_memory_);
    VkBuffer       buffer_                               = VK_NULL_HANDLE;
    VkDeviceMemory imported_memory_                      = VK_NULL_HANDLE;
    int            import_socket_                        = -1;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config) override;
    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                            vkmock::TestConfig*           test_config) override;

    uint32_t find_memory_type(uint32_t memoryTypeBits, VkMemoryPropertyFlags memory_property_flags);
    void     create_buffer_from_fd(int imported_fd);

    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;
};

App::App()
{
    for (uint32_t i = 0; i < EXPECTED_MEMORY_LEN; ++i)
    {
        expected_memory_[i] = i;
    }
}

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
        test_config->map_addr_override           = expected_memory_;
    }
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

    throw std::runtime_error("Import App Could not find required memory type");
}

int receive_int(int socket)
{
    struct msghdr msg = {};
    struct iovec  iov[1];
    int           newfd       = -1;
    int           imported_fd = -1;

#ifdef HAVE_MSGHDR_MSG_CONTROL
    union
    {
        struct cmsghdr cm;
        char           control[CMSG_SPACE(sizeof(int))];
    } control_un          = {};
    struct cmsghdr* cmptr = nullptr;

    msg.msg_control    = control_un.control;
    msg.msg_controllen = sizeof(control_un.control);
#else
    msg.msg_accrights    = (caddr_t)&newfd;
    msg.msg_accrightslen = sizeof(int);
#endif

    msg.msg_name    = nullptr;
    msg.msg_namelen = 0;

    char c          = 0;
    iov[0].iov_base = reinterpret_cast<void*>(&c);
    iov[0].iov_len  = 1;
    msg.msg_iov     = iov;
    msg.msg_iovlen  = 1;

    ssize_t n = recvmsg(socket, &msg, 0);
    if (n <= 0)
    {
        GFXRECON_LOG_ERROR("Import App Failed to receive message");
        GFXRECON_ASSERT(false);
    }

#ifdef HAVE_MSGHDR_MSG_CONTROL
    if ((cmptr = CMSG_FIRSTHDR(&msg)) != NULL && cmptr->cmsg_len == CMSG_LEN(sizeof(int)))
    {
        if (cmptr->cmsg_level != SOL_SOCKET)
        {
            GFXRECON_LOG_ERROR("Import App control level != SOL_SOCKET");
            return -1;
        }
        if (cmptr->cmsg_type != SCM_RIGHTS)
        {
            GFXRECON_LOG_ERROR("Import App control type != SCM_RIGHTS");
            return -1;
        }
        imported_fd = *reinterpret_cast<int*>(CMSG_DATA(cmptr));
    }
    else
    {
        imported_fd = -1; /* descriptor was not passed */
    }
#else
    if (msg.msg_accrightslen == sizeof(int))
    {
        imported_fd = newfd;
    }
    else
    {
        imported_fd = -1; /* descriptor was not passed */
    }
#endif

    return imported_fd;
}


int create_import_socket()
{
    GFXRECON_LOG_INFO("Import App Connecting to exporter");

    int import_socket = socket(PF_UNIX, SOCK_STREAM, 0);
    if (import_socket < 0)
    {
        GFXRECON_LOG_ERROR("Import App Failed to create socket (%d)", import_socket);
    }

    sockaddr_un un          = {};
    un.sun_family           = AF_UNIX;
    const char* socket_name = "/tmp/.external-memory";
    snprintf(un.sun_path, sizeof(un.sun_path), "%s", socket_name);

    int connect_result = connect(import_socket, reinterpret_cast<struct sockaddr*>(&un), sizeof(un));
    if (connect_result < 0)
    {
        GFXRECON_LOG_ERROR("Import App Failed to connect to socket (%d)", connect_result);
    }
    return import_socket;
}

int receive_importable_fd(int import_socket)
{
    int imported_fd = receive_int(import_socket);
    if (imported_fd < 0)
    {
        GFXRECON_LOG_ERROR("Import App Failed to receive int from socket (%d)", imported_fd);
    }

    return imported_fd;
}

void App::create_buffer_from_fd(int imported_fd)
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
    VERIFY_VK_RESULT("Import App Failed to create buffer", result);

    VkMemoryRequirements buf_mem_requirements;
    init.disp.getBufferMemoryRequirements(buffer_, &buf_mem_requirements);

    VkImportMemoryFdInfoKHR import_mem_fd_info = {};
    import_mem_fd_info.sType                   = VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR;
    import_mem_fd_info.handleType              = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT;
    import_mem_fd_info.fd                      = imported_fd;

    VkMemoryAllocateInfo mem_alloc_info = {};
    mem_alloc_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    mem_alloc_info.allocationSize       = buffer_size_;
    mem_alloc_info.memoryTypeIndex =
        find_memory_type(buf_mem_requirements.memoryTypeBits,
                         VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    mem_alloc_info.pNext = &import_mem_fd_info;

    result = init.disp.allocateMemory(&mem_alloc_info, nullptr, &imported_memory_);
    VERIFY_VK_RESULT("Import App Failed to import memory", result);

    result = init.disp.bindBufferMemory(buffer_, imported_memory_, 0u);
    VERIFY_VK_RESULT("Import App Failed to bind memory", result);

    uint32_t* data = nullptr;
    result         = init.disp.mapMemory(imported_memory_, 0u, buffer_size_, 0u, reinterpret_cast<void**>(&data));
    VERIFY_VK_RESULT("Import App Failed to map buffer memory", result);
    for (uint32_t i = 0; i < buffer_size_ / sizeof(uint32_t); ++i)
    {
        if (data[i] != expected_memory_[i])
        {
            GFXRECON_LOG_ERROR("Import App Memory check failed")
            GFXRECON_ASSERT(false);
        }
    }
    GFXRECON_LOG_INFO("Import App Memory imported correctly");
    init.disp.unmapMemory(imported_memory_);
}

bool App::frame(const int frame_num)
{
    return false;
}

void App::cleanup()
{
    init.disp.destroyBuffer(buffer_, nullptr);
    init.disp.freeMemory(imported_memory_, nullptr);

    close(import_socket_);
}

void App::setup()
{
    import_socket_ = create_import_socket();
    int import_fd = receive_importable_fd(import_socket_);
    if(import_fd >= 0) {
       create_buffer_from_fd(import_fd);
    }
}

GFXRECON_END_NAMESPACE(external_memory_fd_import)

GFXRECON_END_NAMESPACE(test_app)

GFXRECON_END_NAMESPACE(gfxrecon)

int main(int argc, char* argv[])
{
    try
    {
        gfxrecon::test_app::external_memory_fd_import::App app{};
        app.run("external memory fd import");
        return 0;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }
}
