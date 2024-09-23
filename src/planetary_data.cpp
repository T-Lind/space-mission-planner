#include "../include/planetary_data.h"
#include <stdexcept>

PlanetaryData::PlanetaryData() {
    initializeData();
}

double PlanetaryData::getDistanceToPlanet(const std::string& planet) const {
    if (planetDistances.find(planet) != planetDistances.end()) {
        return planetDistances.at(planet);
    } else {
        throw std::invalid_argument("Unknown planet: " + planet);
    }
}

double PlanetaryData::getPlanetMass(const std::string& planet) const {
    if (planetMasses.find(planet) != planetMasses.end()) {
        return planetMasses.at(planet);
    } else {
        throw std::invalid_argument("Unknown planet: " + planet);
    }
}

void PlanetaryData::initializeData() {
    planetDistances = {
            {"Mercury", 91.69},
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
