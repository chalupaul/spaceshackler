#include <map>
#include <string>
#include "pressureTank.hpp"
#include "elements.hpp"

void PressureTank::addContents(std::string elementName, double quantity)
{
    if (contents.find(elementName) != contents.end())
    {
        contents[elementName] = contents[elementName] + (quantity * ELEMENTS[elementName]);
    }
    else
    {
        contents[elementName] = quantity * ELEMENTS[elementName];
    }
};
std::map<std::string, double> PressureTank::dispense(void)
{
    // Extract mixed elements from contents.
    // Elements are retrieved as percentages of the total.
    double totalAmount = 0;
    for (const auto &kv : contents)
    {
        totalAmount += kv.second;
    };
    // Now get extract proportionate gasses from the tank
    std::map<std::string, double> returnMixture;
    for (const auto &kv : contents)
    {
        double targetPercent = kv.second / totalAmount;
        double targetVolume = targetPercent * flowVolume;
        // Now remove percentages of the gases
        if (kv.second >= targetVolume)
        {
            returnMixture[kv.first] = targetVolume * ELEMENTS[kv.first];
            contents[kv.first] = contents[kv.first] - targetVolume;
        }
        else
        {
            //TODO: If there are 4 units left and you need to extract 8,
            //      you can't go -4. So just give it all. There's probably
            //      a way to deal with the fact that the sums won't equal flowVolume
            //      and more of the other gasses should be taken out to compensate but
            //      for now just mind the gap.
            returnMixture[kv.first] = contents[kv.first] * ELEMENTS[kv.first];
            contents[kv.first] = 0.0;
        };
    };
};
