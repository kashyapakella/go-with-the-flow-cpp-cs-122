#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/heat_flow.hpp"

TEST_CASE("HeatFlow initializes correctly")
{

    HeatFlow heatFlow(10.0, 0.1, 5);
    std::vector<HeatFlow::Section> rod = heatFlow.getRod();
    REQUIRE(rod.size() == 5);

    for (int i = 0; i < rod.size(); i++)
    {
        REQUIRE(rod[i].temp == 10.0);
    }
}

TEST_CASE("HeatFlow tick updates")
{

    HeatFlow heatFlow(10.0, 0.1, 5);
    heatFlow.setSource(0, 100.0);

    heatFlow.tick();

    std::vector<HeatFlow::Section> rod = heatFlow.getRod();

    REQUIRE(rod[0].temp == 100.0);
    REQUIRE(rod[1].temp == 19.0);
    REQUIRE(rod[2].temp == 10.0);
}

TEST_CASE("Z")
{

    HeatFlow heatFlow(10.0, 0.1, 0);
    std::vector<HeatFlow::Section> rod = heatFlow.getRod();
    REQUIRE(rod.size() == 0);
}

TEST_CASE("O")
{

    HeatFlow heatFlow(10.0, 0.1, 1);
    std::vector<HeatFlow::Section> rod = heatFlow.getRod();
    REQUIRE(rod.size() == 1);

    for (int i = 0; i < rod.size(); i++)
    {
        REQUIRE(rod[i].temp == 10.0);
    }
}

TEST_CASE("M")
{

    HeatFlow heatFlow(10.0, 0.1, 10);
    std::vector<HeatFlow::Section> rod = heatFlow.getRod();
    REQUIRE(rod.size() == 10);

    for (int i = 0; i < rod.size(); i++)
    {
        REQUIRE(rod[i].temp == 10.0);
    }
}
