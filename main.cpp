#include <iostream>

#include "src/heat_flow.hpp"
#include "src/heat_flow_printer.hpp"

int main()
{
  HeatFlow heatFlow(10.0, 0.1, 5);
  HeatFlowPrinter printer;
  std::cout << printer.pretty_print(heatFlow) << "\n";
  heatFlow.setSource(0, 100.0);
  std::cout << printer.pretty_print(heatFlow) << "\n";
  heatFlow.tick();
  std::cout << printer.pretty_print(heatFlow) << "\n";
  heatFlow.tick();
  std::cout << printer.pretty_print(heatFlow);
}
