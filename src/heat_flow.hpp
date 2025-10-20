#pragma once

#include <string>
#include <vector>

class HeatFlow
{
public:
    double K;
    struct Section
    {
        double temp;
        bool isSourceOrSink;
        double val;
    };
    std::vector<Section> rod;
    int length;
    HeatFlow(double initialTemp, double K, int length);
    void setSource(int index, double temp);
    void tick();
    const std::vector<Section> &getRod() const;
};
