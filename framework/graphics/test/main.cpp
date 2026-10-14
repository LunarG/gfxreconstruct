///////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2019 Advanced Micro Devices, Inc.All rights reserved
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
/// \author AMD Developer Tools Team
/// \description gfxrecon_graphics test main entry point
///////////////////////////////////////////////////////////////////////////////

#define CATCH_CONFIG_MAIN
#include <numeric>
#include <catch2/catch.hpp>

#include "graphics/vulkan_feature_util.h"
#include "graphics/vulkan_shader_group_handle.h"

TEST_CASE("vulkan_shader_group_handle - create empty handles", "[]")
{
    gfxrecon::graphics::shader_group_handle_t one, two;

    // check for all zeros
    uint8_t data[gfxrecon::graphics::shader_group_handle_t::MAX_HANDLE_SIZE] = {};
    REQUIRE(memcmp(one.data, data, gfxrecon::graphics::shader_group_handle_t::MAX_HANDLE_SIZE) == 0);

    REQUIRE(one == two);
    REQUIRE_FALSE(one != two);

    auto three = one;
    REQUIRE(one == three);
}

TEST_CASE("vulkan_shader_group_handle - create handles", "[]")
{
    std::vector<uint8_t> data(32);
    std::iota(data.begin(), data.end(), 0);
    gfxrecon::graphics::shader_group_handle_t one(data.data(), data.size());

    data[31] = 99;
    gfxrecon::graphics::shader_group_handle_t two(data.data(), data.size());
    REQUIRE(one != two);

    // check hashing via std::hash
    std::hash<gfxrecon::graphics::shader_group_handle_t> hasher;
    REQUIRE(hasher(one) != hasher(two));
}

TEST_CASE("FilterPNextFeatures - remove unsupported", "[feature_util]")
{
    VkPhysicalDeviceFragmentDensityMapFeaturesEXT fdm_features = {
        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT, nullptr
    };

    VkPhysicalDeviceFragmentShadingRateFeaturesKHR fsr_features = {
        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR, nullptr
    };

    VkPhysicalDeviceDepthClipEnableFeaturesEXT dce_features = {
        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT, nullptr
    };

    // Common setup for 2-element chain tests
    fdm_features.pNext             = &fsr_features;
    fsr_features.pNext             = nullptr;
    VkDeviceCreateInfo create_info = { VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO, &fdm_features };

    SECTION("Both extensions enabled - nothing removed")
    {
        std::vector<const char*> enabled = { "VK_EXT_fragment_density_map", "VK_KHR_fragment_shading_rate" };

        gfxrecon::graphics::feature_util::FilterPNextFeatures(&create_info, enabled);

        REQUIRE(create_info.pNext == &fdm_features);
        REQUIRE(fdm_features.pNext == &fsr_features);
        REQUIRE(fsr_features.pNext == nullptr);
    }

    SECTION("One extension disabled - that struct removed")
    {
        // VK_EXT_fragment_density_map is NOT enabled
        std::vector<const char*> enabled = { "VK_KHR_fragment_shading_rate" };

        gfxrecon::graphics::feature_util::FilterPNextFeatures(&create_info, enabled);

        // fdm_features should be removed, create_info.pNext should point to fsr_features
        REQUIRE(create_info.pNext == &fsr_features);
        REQUIRE(fsr_features.pNext == nullptr);
    }

    SECTION("Other extension disabled - that struct removed")
    {
        // VK_KHR_fragment_shading_rate is NOT enabled
        std::vector<const char*> enabled = { "VK_EXT_fragment_density_map" };

        gfxrecon::graphics::feature_util::FilterPNextFeatures(&create_info, enabled);

        // fsr_features should be removed, fdm_features.pNext should be nullptr
        REQUIRE(create_info.pNext == &fdm_features);
        REQUIRE(fdm_features.pNext == nullptr);
    }

    SECTION("Both extensions disabled - both removed")
    {
        std::vector<const char*> enabled = {};

        gfxrecon::graphics::feature_util::FilterPNextFeatures(&create_info, enabled);

        REQUIRE(create_info.pNext == nullptr);
    }

    SECTION("Null createInfo - does not crash")
    {
        REQUIRE_NOTHROW(gfxrecon::graphics::feature_util::FilterPNextFeatures(nullptr, {}));
    }

    SECTION("Empty pNext - leaves nullptr")
    {
        VkDeviceCreateInfo       empty_create_info = { VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO, nullptr };
        std::vector<const char*> enabled           = {};
        gfxrecon::graphics::feature_util::FilterPNextFeatures(&empty_create_info, enabled);
        REQUIRE(empty_create_info.pNext == nullptr);
    }

    SECTION("Removal from middle of the chain")
    {
        // Link 3 features: fdm -> dce -> fsr
        fdm_features.pNext                    = &dce_features;
        dce_features.pNext                    = &fsr_features;
        fsr_features.pNext                    = nullptr;
        VkDeviceCreateInfo middle_create_info = { VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO, &fdm_features };

        // VK_EXT_depth_clip_enable (middle) is NOT enabled, others are
        std::vector<const char*> enabled = { "VK_EXT_fragment_density_map", "VK_KHR_fragment_shading_rate" };

        gfxrecon::graphics::feature_util::FilterPNextFeatures(&middle_create_info, enabled);

        // dce_features should be removed, fdm_features.pNext should point to fsr_features
        REQUIRE(middle_create_info.pNext == &fdm_features);
        REQUIRE(fdm_features.pNext == &fsr_features);
        REQUIRE(fsr_features.pNext == nullptr);
    }

    SECTION("Non-feature structure in the chain is not removed")
    {
        VkDeviceGroupDeviceCreateInfo group_create_info = { VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO,
                                                            nullptr };

        // Link: fdm -> group -> fsr
        fdm_features.pNext                   = &group_create_info;
        group_create_info.pNext              = &fsr_features;
        fsr_features.pNext                   = nullptr;
        VkDeviceCreateInfo mixed_create_info = { VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO, &fdm_features };

        // Disable both features. group_create_info should remain.
        std::vector<const char*> enabled = {};

        gfxrecon::graphics::feature_util::FilterPNextFeatures(&mixed_create_info, enabled);

        // fdm_features and fsr_features should be removed.
        // mixed_create_info.pNext should point to group_create_info.
        REQUIRE(mixed_create_info.pNext == &group_create_info);
        REQUIRE(group_create_info.pNext == nullptr);
    }

    SECTION("Multi-extension mapping - kept when either extension is enabled")
    {
        VkPhysicalDeviceRobustness2FeaturesKHR robustness2_features = {
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR, nullptr
        };
        VkDeviceCreateInfo rob_create_info = { VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO, &robustness2_features };

        // Test with only VK_EXT_robustness2 enabled
        std::vector<const char*> enabled_ext = { "VK_EXT_robustness2" };
        gfxrecon::graphics::feature_util::FilterPNextFeatures(&rob_create_info, enabled_ext);
        REQUIRE(rob_create_info.pNext == &robustness2_features);

        // Test with only VK_KHR_robustness2 enabled
        rob_create_info.pNext                = &robustness2_features;
        std::vector<const char*> enabled_khr = { "VK_KHR_robustness2" };
        gfxrecon::graphics::feature_util::FilterPNextFeatures(&rob_create_info, enabled_khr);
        REQUIRE(rob_create_info.pNext == &robustness2_features);

        // Test with neither enabled - should be removed
        rob_create_info.pNext                 = &robustness2_features;
        std::vector<const char*> enabled_none = { "VK_KHR_surface" };
        gfxrecon::graphics::feature_util::FilterPNextFeatures(&rob_create_info, enabled_none);
        REQUIRE(rob_create_info.pNext == nullptr);
    }

    SECTION("Ratified EXT extension retains vendor-aliased feature structure")
    {
        VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT raster_features = {
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT, nullptr
        };
        VkDeviceCreateInfo raster_create_info = { VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO, &raster_features };

        // Test with only ratified VK_EXT_rasterization_order_attachment_access enabled
        std::vector<const char*> enabled_ratified = { "VK_EXT_rasterization_order_attachment_access" };
        gfxrecon::graphics::feature_util::FilterPNextFeatures(&raster_create_info, enabled_ratified);
        REQUIRE(raster_create_info.pNext == &raster_features);

        // Test with vendor VK_ARM_rasterization_order_attachment_access enabled
        raster_create_info.pNext             = &raster_features;
        std::vector<const char*> enabled_arm = { "VK_ARM_rasterization_order_attachment_access" };
        gfxrecon::graphics::feature_util::FilterPNextFeatures(&raster_create_info, enabled_arm);
        REQUIRE(raster_create_info.pNext == &raster_features);

        // Test with neither enabled
        raster_create_info.pNext              = &raster_features;
        std::vector<const char*> enabled_none = {};
        gfxrecon::graphics::feature_util::FilterPNextFeatures(&raster_create_info, enabled_none);
        REQUIRE(raster_create_info.pNext == nullptr);
    }
}
