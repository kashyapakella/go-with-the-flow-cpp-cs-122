#include <string>
#include "heat_flow.hpp"

class HeatFlowPrinter
{
public:
    std::string pretty_print(const HeatFlow &heatFlow) const;
};