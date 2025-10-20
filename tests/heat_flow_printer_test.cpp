#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/heat_flow_printer.hpp"

TEST_CASE("Pretty_print works")
{
    HeatFlow heatFlow(10.0, 0.1, 5);
    heatFlow.setSource(0, 100.0);

    HeatFlowPrinter printer;

    std::string output = printer.pretty_print(heatFlow);

    REQUIRE(output == "[100.000000][10.000000][10.000000][10.000000][10.000000]");
}
