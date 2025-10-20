#include <string>
#include "heat_flow.hpp"
#include "heat_flow_printer.hpp"

std::string HeatFlowPrinter::pretty_print(const HeatFlow &heatFlow) const
{

   std::string output = "";

   std::vector<HeatFlow::Section> rod = heatFlow.getRod();

   for (int i = 0; i < rod.size(); i++)
   {
      output += "[" + std::to_string(rod[i].temp) + "]";
   }

   return output;
}
