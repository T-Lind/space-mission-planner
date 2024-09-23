#ifndef PLANETARY_DATA_H
#define PLANETARY_DATA_H

#include <string>
#include <unordered_map>

class PlanetaryData {
public:
    PlanetaryData();

    // Fetch distance from Earth to the target planet (in millions of km)
    double getDistanceToPlanet(const std::string& planet) const;

    // Fetch mass of the target planet (in kg)
    double getPlanetMass(const std::string& planet) const;

    // Additional planet data retrieval functions can be added later
    // Example: Orbital period, gravity, etc.

private:
    std::unordered_map<std::string, double> planetDistances; // Distance in million km
    std::unordered_map<std::string, double> planetMasses;    // Mass in kg

    void initializeData(); // Load hardcoded planetary data or later from external source
};

#endif
