#include <string>
#include "heat_flow.hpp"
#include <map>

HeatFlow::HeatFlow(double initialTemp, double K, int length)
{
  this->K = K;
  this->length = length;

  for (int i = 0; i < length; i++)
  {

    Section s = {initialTemp, false, 0.0};
    rod.push_back(s);
  }
}

void HeatFlow::setSource(int index, double temp)
{

  if (index >= 0 && index < length)
  {
    rod[index] = {temp, true, temp};
  }
}

void HeatFlow::tick()
{

  std::vector<Section> nextRod = rod;

  for (int i = 0; i < rod.size(); i++)
  {
    if (rod[i].isSourceOrSink)
    {
      nextRod[i].temp = rod[i].val;
    }
    else
    {
      double leftTemp;
      double rightTemp;
      if (i == 0)
      {
        leftTemp = rod[i].temp;
      }
      else
      {
        leftTemp = rod[i - 1].temp;
      }

      if (i == rod.size() - 1)
      {
        rightTemp = rod[i].temp;
      }
      else
      {
        rightTemp = rod[i + 1].temp;
      }

      nextRod[i].temp = rod[i].temp + K * (leftTemp - 2 * rod[i].temp + rightTemp);
    }
  }

  rod = nextRod;
}

const std::vector<HeatFlow::Section> &HeatFlow::getRod() const
{
  return rod;
}
