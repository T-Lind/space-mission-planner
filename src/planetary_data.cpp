#include "../include/planetary_data.h"
#include <cmath> // For fmod

// Constructor
PlanetaryData::PlanetaryData() {
    // Initialize planetary distances in million km
    distanceToPlanet["Mars"] = 78.34;
    distanceToPlanet["Venus"] = 41.44;
    distanceToPlanet["Earth"] = 0.0; // Earth is the reference point
    // Add more planets...

    // Initialize planetary masses in kg
    planetMass["Mars"] = 6.4171e23;
    planetMass["Venus"] = 4.8675e24;
    planetMass["Earth"] = 5.972e24;

    // Add more planets...

    // Initialize planetary orbital periods in days
    planetOrbitalPeriod["Mars"] = 687.0; // Mars orbital period in Earth days
    planetOrbitalPeriod["Venus"] = 224.7; // Venus orbital period in Earth days
    planetOrbitalPeriod["Earth"] = 365.0; // Earth orbital period in Earth days
}

// Get distance to planet
double PlanetaryData::getDistanceToPlanet(const std::string& planetName) {
    if (distanceToPlanet.find(planetName) != distanceToPlanet.end()) {
        return distanceToPlanet[planetName];
    } else {
        return -1; // Invalid planet
    }
}

// Get mass of planet
double PlanetaryData::getPlanetMass(const std::string& planetName) {
    if (planetMass.find(planetName) != planetMass.end()) {
        return planetMass[planetName];
    } else {
        return -1; // Invalid planet
    }
}

// Get orbital period of planet
double PlanetaryData::getPlanetOrbitalPeriod(const std::string& planetName) {
    if (planetOrbitalPeriod.find(planetName) != planetOrbitalPeriod.end()) {
        return planetOrbitalPeriod[planetName];
    } else {
        return -1; // Invalid planet
    }
}

// Calculate the angular position of the planet in its orbit (in degrees) based on the day of the year
double PlanetaryData::getPlanetPosition(const std::string& planetName, int dayOfYear) {
    // Retrieve the orbital period of the planet
    double orbitalPeriod = getPlanetOrbitalPeriod(planetName);

    if (orbitalPeriod == -1) {
        // Invalid planet name
        return -1;
    }

    // Calculate the angular position (theta) using the formula:
    // theta = (360 * dayOfYear / orbitalPeriod) % 360
    double position = fmod((360.0 * dayOfYear) / orbitalPeriod, 360.0);

    return position;
}
