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

// Catch must come before the Vulkan headers.
#include <catch2/catch.hpp>

#include "generated/generated_vulkan_consumer_stage.h"

#include <string>
#include <vector>

using namespace gfxrecon::decode;
namespace format = gfxrecon::format;

namespace
{

class RecordingConsumer : public VulkanConsumer
{
  public:
    // Copying args is safe only because CmdDraw holds plain values and no arena pointers.
    void Process_vkCmdDraw(const ApiCallInfo&, args::CmdDraw& args) override { draws.push_back(args); }

    void Process_vkCmdDispatch(const ApiCallInfo&, args::CmdDispatch&) override { ++dispatches; }

    std::vector<args::CmdDraw> draws;
    uint32_t                   dispatches = 0;
};

class SuppressStage : public VulkanConsumerStage
{
  public:
    void Process_vkCmdDraw(const ApiCallInfo&, args::CmdDraw&) override { ++suppressed; }

    uint32_t suppressed = 0;
};

class EditStage : public VulkanConsumerStage
{
  public:
    void Process_vkCmdDraw(const ApiCallInfo& call_info, args::CmdDraw& args) override
    {
        args.vertexCount = 42;
        Forward(call_info, args);
    }
};

class ExpandStage : public VulkanConsumerStage
{
  public:
    void Process_vkCmdDraw(const ApiCallInfo& call_info, args::CmdDraw& args) override
    {
        Forward(call_info, args);
        Forward(call_info, args);
    }
};

class TemplateUpdateCounter : public VulkanConsumer
{
  public:
    // Counts instead of copying, because args.pData points into the decode arena.
    void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&, args::UpdateDescriptorSetWithTemplate&) override
    {
        ++updates;
    }

    uint32_t updates = 0;
};

class PushTemplateCounter : public VulkanConsumer
{
  public:
    void Process_vkCmdPushDescriptorSetWithTemplate(const ApiCallInfo&,
                                                    args::CmdPushDescriptorSetWithTemplate&) override
    {
        ++core;
    }

    void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo&,
                                                       args::CmdPushDescriptorSetWithTemplateKHR&) override
    {
        ++khr;
    }

    uint32_t core = 0;
    uint32_t khr  = 0;
};

// Logs the name of every hand-declared VulkanConsumerBase method it receives.
class HandDeclaredLog : public VulkanConsumer
{
  public:
    void StartLooping() override { names.push_back("StartLooping"); }

    void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&, args::UpdateDescriptorSetWithTemplate&) override
    {
        names.push_back("UpdateDescriptorSetWithTemplate");
    }

    void Process_vkCmdPushDescriptorSetWithTemplate(const ApiCallInfo&,
                                                    args::CmdPushDescriptorSetWithTemplate&) override
    {
        names.push_back("CmdPushDescriptorSetWithTemplate");
    }

    void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo&,
                                                       args::CmdPushDescriptorSetWithTemplateKHR&) override
    {
        names.push_back("CmdPushDescriptorSetWithTemplateKHR");
    }

    void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&,
                                                      args::UpdateDescriptorSetWithTemplateKHR&) override
    {
        names.push_back("UpdateDescriptorSetWithTemplateKHR");
    }

    void Process_vkCmdPushDescriptorSetWithTemplate2(const ApiCallInfo&,
                                                     args::CmdPushDescriptorSetWithTemplate2&) override
    {
        names.push_back("CmdPushDescriptorSetWithTemplate2");
    }

    void Process_vkCmdPushDescriptorSetWithTemplate2KHR(const ApiCallInfo&,
                                                        args::CmdPushDescriptorSetWithTemplate2KHR&) override
    {
        names.push_back("CmdPushDescriptorSetWithTemplate2KHR");
    }

    void Process_vkCreateRayTracingPipelinesKHR(const ApiCallInfo&, args::CreateRayTracingPipelinesKHR&) override
    {
        names.push_back("CreateRayTracingPipelinesKHR");
    }

    void ProcessSetTlasToBlasRelationCommand(format::HandleId                     tlas,
                                             const std::vector<format::HandleId>& blases) override
    {
        names.push_back("SetTlasToBlasRelation");
        last_tlas   = tlas;
        last_blases = blases;
    }

    std::vector<std::string>      names;
    format::HandleId              last_tlas = 0;
    std::vector<format::HandleId> last_blases;
};

// Sends a call knowing only its args type, the way generic stage code does.
template <typename ArgsT>
void SendByType(VulkanConsumer& consumer, ArgsT& args)
{
    consumer.Process(ApiCallInfo{}, args);
}

} // namespace

TEST_CASE("Stage forwards a call unchanged", "[stage]")
{
    VulkanConsumerStage stage;
    RecordingConsumer   recorder;
    stage.AddNext(&recorder);

    args::CmdDraw draw{ 1, 3, 1, 0, 0 };
    stage.Process_vkCmdDraw(ApiCallInfo{}, draw);

    REQUIRE(recorder.draws.size() == 1);
    CHECK(recorder.draws[0].commandBuffer == 1);
    CHECK(recorder.draws[0].vertexCount == 3);
}

TEST_CASE("Stage suppresses a call", "[stage]")
{
    SuppressStage     stage;
    RecordingConsumer recorder;
    stage.AddNext(&recorder);

    args::CmdDraw draw{};
    stage.Process_vkCmdDraw(ApiCallInfo{}, draw);

    CHECK(stage.suppressed == 1);
    CHECK(recorder.draws.empty());
}

TEST_CASE("Stage passes through calls it does not override", "[stage]")
{
    SuppressStage     stage;
    RecordingConsumer recorder;
    stage.AddNext(&recorder);

    args::CmdDraw     draw{};
    args::CmdDispatch dispatch{};
    stage.Process_vkCmdDraw(ApiCallInfo{}, draw);
    stage.Process_vkCmdDispatch(ApiCallInfo{}, dispatch);

    CHECK(recorder.draws.empty());
    CHECK(recorder.dispatches == 1);
}

TEST_CASE("Stage edits a call before forwarding", "[stage]")
{
    EditStage         stage;
    RecordingConsumer recorder;
    stage.AddNext(&recorder);

    args::CmdDraw draw{ 1, 3, 1, 0, 0 };
    stage.Process_vkCmdDraw(ApiCallInfo{}, draw);

    REQUIRE(recorder.draws.size() == 1);
    CHECK(recorder.draws[0].vertexCount == 42);

    // The edit is in place, so the caller's args change too.
    CHECK(draw.vertexCount == 42);
}

TEST_CASE("Stage expands one call into two", "[stage]")
{
    ExpandStage       stage;
    RecordingConsumer recorder;
    stage.AddNext(&recorder);

    args::CmdDraw draw{};
    stage.Process_vkCmdDraw(ApiCallInfo{}, draw);

    CHECK(recorder.draws.size() == 2);
}

TEST_CASE("Stage forks a call to every next consumer", "[stage]")
{
    VulkanConsumerStage stage;
    RecordingConsumer   first;
    RecordingConsumer   second;
    stage.AddNext(&first);
    stage.AddNext(&second);

    args::CmdDraw draw{};
    stage.Process_vkCmdDraw(ApiCallInfo{}, draw);

    CHECK(first.draws.size() == 1);
    CHECK(second.draws.size() == 1);
}

TEST_CASE("Process overload reaches the per-command virtual", "[stage]")
{
    RecordingConsumer recorder;

    args::CmdDraw draw{ 1, 3, 1, 0, 0 };
    SendByType(recorder, draw);

    REQUIRE(recorder.draws.size() == 1);
    CHECK(recorder.draws[0].vertexCount == 3);
}

TEST_CASE("Process overload reaches a hand-declared virtual", "[stage]")
{
    TemplateUpdateCounter counter;

    args::UpdateDescriptorSetWithTemplate update{};
    SendByType(counter, update);

    CHECK(counter.updates == 1);
}

TEST_CASE("Process overload keeps a KHR call apart from its core twin", "[stage]")
{
    PushTemplateCounter counter;

    // The KHR args derive from the core args, so both overloads accept a KHR call.
    // The exact match must win.
    args::CmdPushDescriptorSetWithTemplate    push{};
    args::CmdPushDescriptorSetWithTemplateKHR push_khr{};
    SendByType(counter, push);
    SendByType(counter, push_khr);

    CHECK(counter.core == 1);
    CHECK(counter.khr == 1);
}

TEST_CASE("Stage passes through hand-declared Vulkan methods", "[stage]")
{
    VulkanConsumerStage stage;
    HandDeclaredLog     log;
    stage.AddNext(&log);

    args::UpdateDescriptorSetWithTemplate      update{};
    args::CmdPushDescriptorSetWithTemplate     push{};
    args::CmdPushDescriptorSetWithTemplateKHR  push_khr{};
    args::UpdateDescriptorSetWithTemplateKHR   update_khr{};
    args::CmdPushDescriptorSetWithTemplate2    push2{};
    args::CmdPushDescriptorSetWithTemplate2KHR push2_khr{};
    args::CreateRayTracingPipelinesKHR         pipelines{};

    stage.StartLooping();
    stage.Process_vkUpdateDescriptorSetWithTemplate(ApiCallInfo{}, update);
    stage.Process_vkCmdPushDescriptorSetWithTemplate(ApiCallInfo{}, push);
    stage.Process_vkCmdPushDescriptorSetWithTemplateKHR(ApiCallInfo{}, push_khr);
    stage.Process_vkUpdateDescriptorSetWithTemplateKHR(ApiCallInfo{}, update_khr);
    stage.Process_vkCmdPushDescriptorSetWithTemplate2(ApiCallInfo{}, push2);
    stage.Process_vkCmdPushDescriptorSetWithTemplate2KHR(ApiCallInfo{}, push2_khr);
    stage.Process_vkCreateRayTracingPipelinesKHR(ApiCallInfo{}, pipelines);
    stage.ProcessSetTlasToBlasRelationCommand(7, { 8, 9 });

    CHECK(log.names == std::vector<std::string>{ "StartLooping",
                                                 "UpdateDescriptorSetWithTemplate",
                                                 "CmdPushDescriptorSetWithTemplate",
                                                 "CmdPushDescriptorSetWithTemplateKHR",
                                                 "UpdateDescriptorSetWithTemplateKHR",
                                                 "CmdPushDescriptorSetWithTemplate2",
                                                 "CmdPushDescriptorSetWithTemplate2KHR",
                                                 "CreateRayTracingPipelinesKHR",
                                                 "SetTlasToBlasRelation" });
    CHECK(log.last_tlas == 7);
    CHECK(log.last_blases == std::vector<format::HandleId>{ 8, 9 });
}
