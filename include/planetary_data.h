#ifndef PLANETARY_DATA_H
#define PLANETARY_DATA_H

#include <string>
#include <unordered_map>

class PlanetaryData {
public:
    PlanetaryData();

    double getDistanceToPlanet(const std::string& planet) const;

    double getPlanetMass(const std::string& planet) const;

    // Additional planet data retrieval functions can be added later
    // Example: Orbital period, gravity, etc.

private:
    std::unordered_map<std::string, double> planetDistances; // Distance in million km
    std::unordered_map<std::string, double> planetMasses;    // Mass in kg

    void initializeData(); // Load hardcoded planetary data
};

#endif
