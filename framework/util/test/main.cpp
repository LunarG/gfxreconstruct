///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
// Copyright (c) 2022 Valve Corporation
// Copyright (c) 2022-2023 LunarG, Inc.
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
/// @file gfxrecon_util test main entry point
///////////////////////////////////////////////////////////////////////////////

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "util/to_string.h"
#include "util/strings.h"
#include "util/date_time.h"
#include "util/logging.h"
#include "generated/generated_vulkan_enum_to_string.h"

using namespace gfxrecon::util::strings;
using namespace gfxrecon::util::datetime;

TEST_CASE("Quote", "[to_string]")
{
    using namespace gfxrecon::util;
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kDebugSeverity);

    REQUIRE(gfxrecon::util::Quote("") == "\"\"");
    REQUIRE(gfxrecon::util::Quote(std::string("")) == "\"\"");

    REQUIRE(gfxrecon::util::Quote("VK_STENCIL_FACE_FRONT_BIT") == "\"VK_STENCIL_FACE_FRONT_BIT\"");
    REQUIRE(gfxrecon::util::Quote(std::string("VK_STENCIL_FACE_FRONT_BIT")) == "\"VK_STENCIL_FACE_FRONT_BIT\"");

    REQUIRE(gfxrecon::util::Quote("\"VK_STENCIL_FACE_FRONT_BIT\"") == "\"\"VK_STENCIL_FACE_FRONT_BIT\"\"");

    gfxrecon::util::Log::Release();
}

/// Light test of generated code for converting 64 bit enums and 64bit bitflags
/// composed of them into strings.
TEST_CASE("Enum64ToString", "[to_string]")
{
    using namespace gfxrecon::util;
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kDebugSeverity);

    REQUIRE(VkAccessFlagBits2ToString(VK_ACCESS_2_NONE) == "VK_ACCESS_2_NONE");
    REQUIRE(VkAccessFlagBits2ToString(VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV) ==
            "VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV");

    REQUIRE(VkAccessFlags2ToString(VK_ACCESS_2_SHADER_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT) ==
            "VK_ACCESS_2_SHADER_READ_BIT|VK_ACCESS_2_MEMORY_WRITE_BIT");
    REQUIRE(
        VkAccessFlags2ToString(VK_ACCESS_2_SHADER_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT |
                               VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT) ==
        "VK_ACCESS_2_SHADER_READ_BIT|VK_ACCESS_2_MEMORY_WRITE_BIT|VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT");
    REQUIRE(VkAccessFlags2ToString(VK_ACCESS_2_SHADER_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT |
                                   VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR |
                                   VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT |
                                   VK_ACCESS_2_MICROMAP_READ_BIT_EXT) ==
            "VK_ACCESS_2_SHADER_READ_BIT|VK_ACCESS_2_MEMORY_WRITE_BIT|VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR|"
            "VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_"
            "EXT|VK_ACCESS_2_MICROMAP_READ_BIT_EXT");

    REQUIRE(VkFormatFeatureFlagBits2ToString(VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT) ==
            "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT");
    // Note KHR suffix is stripped as the two consts have the same value:
    REQUIRE(VkFormatFeatureFlagBits2ToString(VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT_KHR) ==
            "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT");
    REQUIRE(VkFormatFeatureFlagBits2ToString(VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV) ==
            "VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV");
    REQUIRE(VkFormatFeatureFlags2ToString(
                VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT | VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT |
                VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT |
                VK_FORMAT_FEATURE_2_DISJOINT_BIT | VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR |
                VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT |
                VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR |
                VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM) ==
            "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT|VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT|VK_FORMAT_FEATURE_2_"
            "SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT|"
            "VK_FORMAT_FEATURE_2_DISJOINT_BIT|"
            "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR|"
            "VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR|"
            "VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT|"
            "VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM");

    REQUIRE(VkPipelineStageFlagBits2ToString(VK_PIPELINE_STAGE_2_NONE) == "VK_PIPELINE_STAGE_2_NONE");
    REQUIRE(VkPipelineStageFlagBits2ToString(VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT_KHR) ==
            "VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT");
    REQUIRE(VkPipelineStageFlagBits2ToString(VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT) ==
            "VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT");
    REQUIRE(VkPipelineStageFlagBits2ToString(VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT) ==
            "VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT");
    REQUIRE(VkPipelineStageFlags2ToString(
                VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT_KHR | VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT |
                VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT) == "VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT|VK_PIPELINE_STAGE_2_"
                                                         "VERTEX_SHADER_BIT|VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT");
    gfxrecon::util::Log::Release();
}

TEST_CASE("to_binary_fixed_width", "[to_string]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kDebugSeverity);
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(0)) == "0b00000000");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(255)) == "0b11111111");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(1)) == "0b00000001");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(2)) == "0b00000010");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(4)) == "0b00000100");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(8)) == "0b00001000");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(16)) == "0b00010000");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(32)) == "0b00100000");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(64)) == "0b01000000");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(128)) == "0b10000000");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(41)) == "0b00101001");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(83)) == "0b01010011");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(137)) == "0b10001001");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(173)) == "0b10101101");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(179)) == "0b10110011");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint8_t(241)) == "0b11110001");

    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint16_t(0)) == "0b0000000000000000");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint16_t(65535)) == "0b1111111111111111");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint16_t(4096)) == "0b0001000000000000");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint16_t(32768 + 1024 + 8)) == "0b1000010000001000");

    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint32_t(0)) == "0b00000000000000000000000000000000");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint32_t(4294967295)) == "0b11111111111111111111111111111111");

    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint64_t(0)) ==
            "0b0000000000000000000000000000000000000000000000000000000000000000");
    REQUIRE(gfxrecon::util::to_binary_fixed_width(uint64_t(4294967295ULL * 4294967296ULL + 4294967295ULL)) ==
            "0b1111111111111111111111111111111111111111111111111111111111111111");

    gfxrecon::util::Log::Release();
}

TEST_CASE("TabRight", "[strings]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kDebugSeverity);

    REQUIRE(gfxrecon::util::strings::TabRight("") == "\t");
    REQUIRE(gfxrecon::util::strings::TabRight("\n") == "\t\n\t");
    REQUIRE(gfxrecon::util::strings::TabRight("\t") == "\t\t");
    REQUIRE(gfxrecon::util::strings::TabRight("\t\t") == "\t\t\t");
    REQUIRE(gfxrecon::util::strings::TabRight("l1\nl2\nl3") == "\tl1\n\tl2\n\tl3");
    REQUIRE_FALSE(gfxrecon::util::strings::TabRight("l1\nl2\n\nl3") == "\tl1\n\tl2\n\tl3");

    gfxrecon::util::Log::Release();
}

TEST_CASE("SplitString", "[strings]")
{
    using std::string;
    auto s = [](auto x) { return string{ x }; };

    gfxrecon::util::Log::Init(gfxrecon::util::Log::kDebugSeverity);

    REQUIRE(gfxrecon::util::strings::SplitString("", '+') == std::vector<string>());
    REQUIRE(gfxrecon::util::strings::SplitString("a", '.') == std::vector<string>({ s("a") }));
    REQUIRE(gfxrecon::util::strings::SplitString("foobar", '.') == std::vector<string>({ s("foobar") }));
    REQUIRE(gfxrecon::util::strings::SplitString("+", '+') == std::vector<string>());
    REQUIRE(gfxrecon::util::strings::SplitString("++", '+') == std::vector<string>());
    REQUIRE(gfxrecon::util::strings::SplitString("+++", '+') == std::vector<string>());
    REQUIRE(gfxrecon::util::strings::SplitString("++++++++++++++++++++", '+') == std::vector<string>());
    REQUIRE(gfxrecon::util::strings::SplitString("+++++++++++++++++++++", '+') == std::vector<string>());
    REQUIRE(gfxrecon::util::strings::SplitString(" + ", '+') == std::vector<string>({ s(" "), s(" ") }));
    REQUIRE(gfxrecon::util::strings::SplitString("z+y", '+') == std::vector<string>({ s("z"), s("y") }));
    REQUIRE(gfxrecon::util::strings::SplitString(".a..b...c....d.....", '.') ==
            std::vector<string>({ s('a'), s('b'), s('c'), s('d') }));
    REQUIRE(gfxrecon::util::strings::SplitString(".a..b...c....d.....", ',') ==
            std::vector<string>({ s(".a..b...c....d.....") }));
    REQUIRE(gfxrecon::util::strings::SplitString(".a..b...c,,,,d.....", ',') ==
            std::vector<string>({ s(".a..b...c"), s("d.....") }));

    gfxrecon::util::Log::Release();
}

TEST_CASE("RemoveWhitespace", "[strings]")
{
    using std::string;
    auto s = [](auto x) { return string{ x }; };

    gfxrecon::util::Log::Init(gfxrecon::util::Log::kDebugSeverity);

    string s1{ "1 2 3 4 5 6 7 8 9 10" };
    gfxrecon::util::strings::RemoveWhitespace(s1);
    REQUIRE(s1 == "12345678910");

    string s2{ "    left" };
    gfxrecon::util::strings::RemoveWhitespace(s2);
    REQUIRE(s2 == "left");

    {
        string s3{ "right      " };
        gfxrecon::util::strings::RemoveWhitespace(s3);
        REQUIRE(s3 == "right");
    }
    {
        string s3{ " \t\n\n\n\t   £$%Keep_Me+*&  \r\f\t\f\t \f\r\t\n\n\n\n " };
        gfxrecon::util::strings::RemoveWhitespace(s3);
        REQUIRE(s3 == "£$%Keep_Me+*&");
        // Check that repeated applications don't change an already-shrunk string:
        for (int i = 0; i < 100; ++i)
        {
            gfxrecon::util::strings::RemoveWhitespace(s3);
            REQUIRE(s3 == "£$%Keep_Me+*&");
        }
    }
    {
        string s3{ " \t\n\n\n\t   £$%\t\tK  e\n\n\n\n\re \f\rp_\nM\t e+*&  \r\f\t\f\t \f\r\t\n\n\n\n " };
        gfxrecon::util::strings::RemoveWhitespace(s3);
        REQUIRE(s3 == "£$%Keep_Me+*&");
    }

    gfxrecon::util::Log::Release();
}

TEST_CASE("UtcString", "[datetime]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kDebugSeverity);

    // Looking for clean output like zero: 1970-01-01T00:00:00Z
    REQUIRE(UtcString(0) == "1970-01-01T00:00:00Z");
    REQUIRE(UtcString(1) == "1970-01-01T00:00:01Z");
    REQUIRE(UtcString(60 * 60) == "1970-01-01T01:00:00Z");
    REQUIRE(UtcString(60 * 60 + 1) == "1970-01-01T01:00:01Z");
    REQUIRE(UtcString(60 * 60 + 61) == "1970-01-01T01:01:01Z");
    REQUIRE(UtcString(60 * 60 + 61) == "1970-01-01T01:01:01Z");

    const unsigned min       = 60;
    const unsigned hour      = min * 60;
    const unsigned day       = hour * 24;
    const unsigned year      = 525600 * min;
    const unsigned leap_year = year + day;

    REQUIRE(UtcString(year) == "1971-01-01T00:00:00Z");
    REQUIRE(UtcString(year * 2) == "1972-01-01T00:00:00Z");
    REQUIRE(UtcString(year * 8 + leap_year * 2) == "1980-01-01T00:00:00Z");
    REQUIRE(UtcString(year * 11 + leap_year * 3 + 31 * 3 * day + 28 * day + 17 * day + 11 * hour + 28 * min + 59) ==
            "1984-05-18T11:28:59Z");
    REQUIRE(UtcString(year * 23 + leap_year * 7) == "2000-01-01T00:00:00Z");
    REQUIRE(UtcString(year * 23 + leap_year * 7 + 29 * day + 31 * day * 4 + 30 * day * 2) == "2000-08-01T00:00:00Z");
    REQUIRE(UtcString(year * 23 + leap_year * 7 + 29 * day + 31 * day * 4 + 30 * day * 2 + 30 * day) ==
            "2000-08-31T00:00:00Z");
    REQUIRE(UtcString(year * 23 + leap_year * 7 + 29 * day + 31 * day * 4 + 30 * day * 2 + 30 * day + 23 * hour) ==
            "2000-08-31T23:00:00Z");
    REQUIRE(UtcString(year * 23 + leap_year * 7 + 29 * day + 31 * day * 4 + 30 * day * 2 + 30 * day + 23 * hour +
                      47 * min) == "2000-08-31T23:47:00Z");
    REQUIRE(UtcString(year * 23 + leap_year * 7 + 29 * day + 31 * day * 4 + 30 * day * 2 + 30 * day + 23 * hour +
                      47 * min + 54) == "2000-08-31T23:47:54Z");

    auto one_thousand = UtcString(1000);
    auto two_thousand = UtcString(2000);
    REQUIRE(one_thousand[19] == 'Z');
    REQUIRE(two_thousand[19] == 'Z');
    REQUIRE(one_thousand.length() == 20);
    REQUIRE(two_thousand.length() == 20);

    // Pump some random time points between -2'147'483'648 and 2'147'483'647 through conversion
    // and check that they have the correct length and punctuation:
    const time_t time_points[]{
        1110797,    1490769,    3976212,    5465697,    6237413,    9351446,    10731844,   12202301,   15533617,
        21337614,   22327966,   24650085,   27246781,   29010007,   30729052,   32154271,   34620851,   37834780,
        37925620,   39434894,   40563221,   41365961,   43581973,   44635838,   44897388,   45001162,   46149110,
        47247729,   49732615,   57043628,   60080370,   62899577,   62911872,   66878415,   69572658,   75073195,
        75822726,   79458740,   79575604,   80900240,   81253552,   85803541,   87179572,   94806097,   97715605,
        98834000,   102984479,  104355380,  105023196,  106883678,  109948256,  111725946,  113437519,  120043461,
        122009721,  123312065,  126306075,  126460034,  127371037,  127592007,  128695752,  130817317,  135750511,
        141552483,  148596256,  156256754,  162702935,  168069317,  168149708,  169021252,  169789030,  174051305,
        176436401,  176640315,  176742956,  183231714,  184003749,  186715900,  193230575,  197335799,  199763489,
        202435474,  204634777,  204986597,  208964101,  211117052,  211930356,  212609014,  214176470,  214941000,
        219493598,  225128793,  225368827,  227508565,  231567946,  232889100,  233616045,  235114646,  238011451,
        239466721,  245810132,  246897628,  251434959,  253593427,  259346527,  261244917,  263315823,  265530179,
        265704716,  266811726,  267425984,  271148970,  271435088,  271679981,  272307283,  277947108,  279526360,
        284971093,  286246426,  286343060,  287557337,  288500208,  288682458,  288834402,  289118924,  289260349,
        290141890,  296044860,  302745870,  304960359,  310562262,  314197065,  314664422,  314946723,  316065142,
        318251184,  319000478,  320593653,  321738131,  326778925,  328483867,  328540959,  329298078,  330257211,
        331907843,  334473517,  334473592,  337592496,  341511890,  344314323,  348745353,  352864953,  355355497,
        355682004,  357626615,  359078823,  359253320,  360662379,  364694491,  364802900,  368641877,  373951987,
        374455821,  378434166,  381138736,  385769892,  389582889,  389767905,  392728225,  399549585,  400034232,
        401465131,  407117309,  410219471,  410407379,  410754867,  419249228,  424950316,  427596149,  429720163,
        429910543,  435424044,  436684752,  438332941,  442890760,  443160093,  443558898,  443651323,  446111079,
        446924727,  451164705,  451713433,  453396336,  454439330,  454674827,  455343962,  456012431,  457463705,
        458640584,  458915671,  462153656,  464725577,  466070722,  466894111,  468454703,  468609986,  468817195,
        469077366,  474058097,  476722728,  480340444,  483757153,  484159209,  484480941,  484948238,  487059438,
        487779678,  490241620,  491008159,  493916325,  497641422,  499126710,  501047933,  501631889,  509487718,
        509811089,  514478243,  514691210,  515779051,  516681689,  523413348,  523963438,  530912064,  531425628,
        533324817,  533505674,  534275775,  537610079,  540979134,  542242259,  542949057,  557269507,  558828716,
        564348945,  564686011,  570944932,  571082450,  576084666,  580244517,  583837826,  586553711,  588548438,
        589668253,  590374728,  599651730,  612407963,  612719016,  615121223,  616262464,  617784177,  619776196,
        624705237,  625109995,  625130038,  625775184,  630160442,  635724026,  638992085,  641245271,  643836584,
        646940650,  648718253,  649744589,  650582021,  650762872,  650924551,  652597246,  656732541,  660901898,
        664647911,  665804056,  666787845,  669191321,  669308375,  670659615,  673048757,  674807972,  675768732,
        676749627,  678833244,  682729525,  683786125,  686793455,  690371644,  692720419,  693611041,  693908297,
        695600153,  702416309,  707538158,  708142456,  708393379,  709237230,  712993710,  713359079,  714991546,
        720615818,  723074211,  726847115,  727192903,  731864002,  735396834,  735938487,  736344305,  737732500,
        740243573,  741088717,  741532070,  743320548,  744061016,  745529719,  745952625,  747485128,  749488443,
        752473127,  755217166,  755321571,  758016140,  758904398,  761417474,  765083683,  770309767,  774443661,
        777201125,  780312562,  780767671,  781721675,  785105125,  789174515,  792750997,  792909961,  792972475,
        796797399,  798868896,  802429529,  803100302,  803522141,  803938218,  805032091,  809909463,  810570061,
        813310762,  813961595,  816373392,  817815204,  824449977,  824722202,  824847255,  827146895,  828479377,
        829405445,  837402296,  838452927,  843008500,  844576607,  848251197,  851824558,  856758848,  857289302,
        858195950,  859128583,  866196631,  866285647,  868509144,  868760562,  875116206,  879316896,  879503032,
        881137518,  881515444,  885511007,  888639780,  892919137,  893564811,  893683445,  895947274,  896542133,
        903512645,  904304974,  904467320,  905516784,  906119196,  914028183,  914695565,  915583319,  922608537,
        928486487,  930542340,  934029765,  934031625,  934238504,  934591110,  934660806,  934856737,  936099590,
        936367633,  936418267,  936806128,  939577030,  941460710,  941566727,  942540980,  942589827,  944365477,
        944484548,  945845674,  946247880,  949183216,  951804040,  952204185,  952515203,  953114293,  953145993,
        958070269,  959670220,  960202840,  964552975,  965028994,  965853230,  968314524,  972318298,  976996956,
        978012122,  978556120,  981235128,  983015399,  985385020,  987376632,  994993335,  998705456,  1001018343,
        1007340863, 1011149839, 1016087758, 1016420313, 1021724154, 1022023200, 1023165018, 1023699196, 1026733605,
        1026986159, 1029444450, 1034023081, 1036840951, 1037601587, 1042266960, 1043361322, 1044841389, 1047925484,
        1054577688, 1056520206, 1057304463, 1063073355, 1067614917, 1069965291, 1069980252, 1073601371, 1078514213,
        1079275231, 1079388289, 1082579314, 1083032340, 1084245554, 1086800106, 1087068586, 1088433174, 1092929000,
        1094415636, 1094429439, 1096656824, 1100508502, 1101906092, 1102985382, 1104603993, 1108257222, 1109256162,
        1115123486, 1115160545, 1119541743, 1120403254, 1123316323, 1123947836, 1126611139, 1127839885, 1128248061,
        1132191041, 1132350550, 1134172889, 1135323828, 1136748911, 1137663431, 1140088950, 1140718959, 1142172011,
        1145643673, 1145791714, 1147531654, 1153330372, 1155514698, 1159598480, 1162171411, 1163136594, 1164156082,
        1165331974, 1165873236, 1168179929, 1168316797, 1169512698, 1171280022, 1172694693, 1173201212, 1173901474,
        1173922025, 1177583988, 1178359170, 1178935335, 1178995258, 1180310736, 1180659811, 1188333677, 1189312253,
        1189318819, 1193412174, 1193609283, 1194000172, 1194695395, 1195864109, 1202909981, 1204300724, 1206896626,
        1207873429, 1209292539, 1210394005, 1211303598, 1215881693, 1219383316, 1222353324, 1223060464, 1223162889,
        1223499995, 1226278658, 1230019384, 1231941646, 1232662111, 1232792766, 1236735151, 1237576462, 1237742546,
        1243273193, 1244790394, 1247178429, 1247463864, 1252413994, 1253745476, 1254173910, 1257466205, 1260345347,
        1260512083, 1262211364, 1263819292, 1266117605, 1267760476, 1268722698, 1272237794, 1273157839, 1276560885,
        1279843333, 1281270340, 1281817823, 1283591960, 1288167842, 1288850739, 1294372167, 1295703700, 1296022795,
        1301195533, 1309203970, 1311227779, 1314346030, 1316800768, 1329147340, 1330504520, 1333715778, 1334852387,
        1336631927, 1336679260, 1336831646, 1342914545, 1343862751, 1345132191, 1345225633, 1346844220, 1347430089,
        1350429945, 1350710413, 1352322695, 1355113436, 1358933581, 1359213212, 1359879921, 1365277430, 1366617748,
        1367663169, 1370094095, 1370907053, 1371745768, 1373612279, 1374314573, 1374500992, 1376677566, 1379252550,
        1380497288, 1383987729, 1384472788, 1385298701, 1386509933, 1393687414, 1394144363, 1397356561, 1398115357,
        1400123362, 1400373681, 1402706380, 1406584013, 1407133209, 1413224248, 1414767890, 1419747793, 1422609619,
        1423862559, 1423954085, 1428882360, 1430392671, 1431782956, 1433432635, 1433490432, 1436076821, 1439460479,
        1440704862, 1442989041, 1445576194, 1449977544, 1452433095, 1452909794, 1455429581, 1460153418, 1461947702,
        1464015489, 1464645136, 1466649013, 1467147058, 1468530117, 1469232338, 1469376553, 1472768195, 1474187406,
        1476466469, 1478491105, 1481570069, 1483100279, 1483476436, 1484128497, 1488614464, 1495169785, 1497102308,
        1500377950, 1501053805, 1502821404, 1513588800, 1513801821, 1521129866, 1521652994, 1522938155, 1525699506,
        1525872539, 1526707661, 1528114641, 1528437586, 1528769419, 1529403595, 1533773558, 1533894649, 1543016773,
        1550582159, 1551202837, 1552504109, 1553206320, 1553926194, 1554288739, 1555669339, 1556403594, 1564604662,
        1564888062, 1566695773, 1567282668, 1569327757, 1571061148, 1571408182, 1571901030, 1575076470, 1575362161,
        1576064356, 1577270470, 1577288142, 1578271825, 1578955990, 1579361543, 1579756447, 1579831787, 1582743132,
        1588536764, 1592455258, 1594742368, 1595904496, 1600005562, 1603221877, 1603787339, 1606955395, 1607016585,
        1607662263, 1608852748, 1609530094, 1609819092, 1610616171, 1611269419, 1614556848, 1617619395, 1618379121,
        1618854538, 1619171560, 1622484261, 1629616452, 1630559582, 1631724917, 1633757478, 1635455668, 1637226962,
        1637305803, 1637337508, 1637375843, 1639246077, 1639416654, 1641678763, 1646166483, 1652070197, 1652234022,
        1652370198, 1654862163, 1657376156, 1658020157, 1658621369, 1662546153, 1663052857, 1664013043, 1666155828,
        1668589638, 1669167176, 1669978571, 1670630470, 1671743830, 1672543760, 1674510912, 1675114341, 1678298423,
        1679425982, 1682024000, 1683081093, 1688172007, 1688785866, 1688948743, 1691571725, 1697069433, 1698409987,
        1707406872, 1708429284, 1710260843, 1711527058, 1719942913, 1720038396, 1721997793, 1723721784, 1725174170,
        1725426464, 1727252557, 1727951627, 1729716782, 1730585132, 1730910772, 1733046027, 1733556387, 1734054383,
        1738531058, 1740215932, 1742295644, 1747035585, 1747707498, 1748447738, 1750794226, 1750971221, 1755095919,
        1759712714, 1762616248, 1762950293, 1765093231, 1767140918, 1768387755, 1775661096, 1775673494, 1776226394,
        1781762890, 1782620546, 1783610529, 1785922791, 1791940538, 1792004194, 1793965456, 1796154020, 1800928799,
        1802443578, 1805154759, 1808197117, 1810744864, 1810988144, 1811059011, 1816233708, 1816457942, 1819235842,
        1820378112, 1820978462, 1822305572, 1824411218, 1825212880, 1827222068, 1829459239, 1829470277, 1830856220,
        1832834418, 1833072372, 1833267212, 1833803325, 1834481012, 1835576464, 1837422958, 1839959408, 1843802937,
        1844519146, 1846087604, 1847945887, 1849758084, 1854266032, 1856240256, 1859242673, 1861937749, 1863269901,
        1866471194, 1867956696, 1868992884, 1870477765, 1873394740, 1874507401, 1875880787, 1877535675, 1878934010,
        1879727428, 1888631243, 1891039342, 1894689027, 1894753347, 1895139720, 1898383738, 1900904656, 1903423404,
        1904858655, 1910677491, 1916123046, 1919076946, 1927479231, 1927631327, 1927643790, 1927784091, 1930717958,
        1931229989, 1936706721, 1936721919, 1939699928, 1946032949, 1947095805, 1948971675, 1951494176, 1952288549,
        1958256481, 1961390402, 1961807274, 1964138353, 1965177828, 1967941185, 1968144236, 1972063417, 1972814182,
        1973463682, 1974931343, 1975074147, 1975370506, 1978106499, 1978993276, 1981613796, 1984259061, 1984467273,
        1985960735, 1986927720, 1987124462, 1987504628, 1987985117, 1989810570, 1990757645, 1994018445, 1995123091,
        1996983359, 2002277834, 2003959166, 2005783379, 2006798957, 2007435284, 2009102676, 2010800784, 2012073303,
        2021333056, 2023303672, 2024252407, 2024706186, 2026594157, 2027107277, 2027888664, 2034906500, 2035529371,
        2036728016, 2038105483, 2040360375, 2043730219, 2047060325, 2048940028, 2052099375, 2053673945, 2054796956,
        2055247658, 2056652083, 2057045565, 2060833072, 2061662083, 2068164387, 2069405882, 2069921167, 2071643291,
        2072122651, 2073784851, 2073867840, 2074926144, 2080513333, 2082120704, 2084801782, 2087656173, 2088000695,
        2089878037, 2090946752, 2100841550, 2101904213, 2101910716, 2103543930, 2103736248, 2104451370, 2106668147,
        2108351847, 2109352711, 2109678776, 2112639095, 2117439714, 2119770664, 2120814374, 2123696944, 2124611801,
        2126074193, 2126455380, 2129522844, 2130837185, 2131235422, 2135830518, 2141382199, 2144364437, 2146314920,
        2146898310
    };

    for (const time_t time_point : time_points)
    {
        const auto ran = UtcString(time_point);

        REQUIRE(ran.length() == 20);
        REQUIRE(ran[4] == '-');
        REQUIRE(ran[7] == '-');
        REQUIRE(ran[10] == 'T');
        REQUIRE(ran[16] == ':');
        REQUIRE(ran[13] == ':');
        REQUIRE(ran[19] == 'Z');
    }

    gfxrecon::util::Log::Release();
}

TEST_CASE("ExpandPathVariables", "[strings]")
{
    using namespace gfxrecon::util;

    Log::Init(Log::kDebugSeverity);

    filepath::FileInfo info{};

    // Empty AppName
    REQUIRE(ExpandPathVariables(info, "${AppName}/file.gfxr") == "/file.gfxr");
#ifdef __ANDROID__
    REQUIRE(ExpandPathVariables(info, "${AppName}/${InternalDataPath}") == "//data/data/");
#endif

#define APP_NAME "com.example.app"
    const char* app_name = APP_NAME;
    strncpy(info.AppName, app_name, std::strlen(app_name));

    const std::string expected_internal = "/data/data/" APP_NAME;

    // No variables
    REQUIRE(ExpandPathVariables(info, "/foo/bar.txt") == "/foo/bar.txt");
    // AppName variable
    REQUIRE(ExpandPathVariables(info, "${AppName}/file.gfxr") == APP_NAME "/file.gfxr");
    // Empty path
    REQUIRE(ExpandPathVariables(info, "") == "");
    // Multiple occurrences
    REQUIRE(ExpandPathVariables(info, "${AppName}/${AppName}/${AppName}") == APP_NAME "/" APP_NAME "/" APP_NAME);
    // Unknown variable (should remain unchanged)
    REQUIRE(ExpandPathVariables(info, "${UnknownVar}/file.gfxr") == "${UnknownVar}/file.gfxr");

#ifdef __ANDROID__
    // InternalDataPath variable
    REQUIRE(ExpandPathVariables(info, "${InternalDataPath}/file.gfxr") == expected_internal + "/file.gfxr");
    // Both variables
    REQUIRE(ExpandPathVariables(info, "${InternalDataPath}/${AppName}/file.gfxr") == expected_internal + "/" APP_NAME
                                                                                                         "/file.gfxr");
    // Mixed known and unknown variables
    REQUIRE(ExpandPathVariables(info, "${AppName}/${UnknownVar}/${InternalDataPath}") ==
            APP_NAME "/${UnknownVar}/" + expected_internal);
#endif

    Log::Release();
}
