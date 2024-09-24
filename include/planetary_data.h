#ifndef PLANETARY_DATA_H
#define PLANETARY_DATA_H

#include <string>
#include <unordered_map>

class PlanetaryData {
public:
    PlanetaryData();

    // Retrieve distance to a planet in million km
    double getDistanceToPlanet(const std::string& planetName);

    // Retrieve mass of a planet in kg
    double getPlanetMass(const std::string& planetName);

    // Retrieve orbital period of a planet in days
    double getPlanetOrbitalPeriod(const std::string& planetName);

    // Retrieve the current angular position of a planet (in degrees) based on the day of the year
    double getPlanetPosition(const std::string& planetName, int dayOfYear);

private:
    // Planetary distance data in million km
    std::unordered_map<std::string, double> distanceToPlanet;

    // Planetary mass data in kg
    std::unordered_map<std::string, double> planetMass;

    // Planetary orbital period data in days
    std::unordered_map<std::string, double> planetOrbitalPeriod;
};

#endif
