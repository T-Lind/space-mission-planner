#include "../include/planetary_data.h"

// Constructor to initialize the data
PlanetaryData::PlanetaryData() {
    initializeData(); // Populate the maps with planet data
}

// Returns the distance from Earth to the target planet
double PlanetaryData::getDistanceToPlanet(const std::string& planet) const {
    if (planetDistances.find(planet) != planetDistances.end()) {
        return planetDistances.at(planet);
    } else {
        return -1; // Return -1 for unknown planet
    }
}

// Returns the mass of the target planet
double PlanetaryData::getPlanetMass(const std::string& planet) const {
    if (planetMasses.find(planet) != planetMasses.end()) {
        return planetMasses.at(planet);
    } else {
        return -1; // Return -1 for unknown planet
    }
}

// Private method to initialize data
void PlanetaryData::initializeData() {
    // Add sample planetary data (distances in million km, masses in kg)
    planetDistances = {
            {"Mercury", 91.69},  // Closest distance from Earth in million km
            {"Venus", 41.40},
            {"Mars", 78.34},
            {"Jupiter", 628.73},
            {"Saturn", 1277.42},
            {"Uranus", 2721.85},
            {"Neptune", 4354.77}
    };

    planetMasses = {
            {"Mercury", 3.3011e23},  // Mass in kg
            {"Venus", 4.8675e24},
            {"Mars", 6.4171e23},
            {"Jupiter", 1.8982e27},
            {"Saturn", 5.6834e26},
            {"Uranus", 8.6810e25},
            {"Neptune", 1.02413e26}
    };
}
