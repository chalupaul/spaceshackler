#ifndef PRESSURETANK_H
#define PRESSURETANK_H

#include <map>

class PressureTank
{
public:
  PressureTank(double rValue, double psiMax, double volume);  // Default constructor
  double rValue;                                              // Resistance to temperature change
  double flowVolume = 1000;                                   // Amount of particles in moles released every second
  double psiMax;                                              // Maximum pressure the tank can hold before explosion
  int health = 100;                                           // Internal hit points of the object
  double volume;                                              // Volume of canister.
  std::map<std::string, double> contents;                     // Contents of tank.
  void addContents(std::string elementName, double quantity); // Mix contents into the tank
  std::map<std::string, double> dispense(void);               // Retreive elements blended in quantities of flowVolume
};

#endif