#include "../include/trajectory_calculator.h"
#include <cmath>
#include <iostream>

// Gravitational constant (G) in m^3 kg^-1 s^-2
const double G = 6.67430e-11;
// Mass of Earth in kg
const double massEarth = 5.972e24;
// Radius of Earth's orbit (1 AU in km, converted to meters)
const double earthOrbitRadius = 1.496e11;

// Constructor
TrajectoryCalculator::TrajectoryCalculator() {}

// Calculate the optimal trajectory based on the selected transfer type
double TrajectoryCalculator::calculateTrajectory(const std::string& targetPlanet, double payloadWeight, const PropulsionSystem& propulsionSystem, TransferType transferType) {
    switch (transferType) {
        case HOHMANN:
            return hohmannTransfer(targetPlanet, payloadWeight, propulsionSystem);
        case BI_ELLIPTIC:
            return biEllipticTransfer(targetPlanet, payloadWeight, propulsionSystem);
        case FAST_TRANSFER:
            return fastTransfer(targetPlanet, payloadWeight, propulsionSystem);
        default:
            std::cerr << "Invalid transfer type!" << std::endl;
            return -1;
    }
}

// Perform Hohmann transfer calculation
double TrajectoryCalculator::hohmannTransfer(const std::string& targetPlanet, double payloadWeight, const PropulsionSystem& propulsionSystem) {
    double planetDistanceMillionKm = planetaryData.getDistanceToPlanet(targetPlanet);
    if (planetDistanceMillionKm == -1) {
        return -1; // Return -1 for invalid planet
    }

    double targetOrbitRadius = planetDistanceMillionKm * 1e9 * 1000;
    double semiMajorAxis = (earthOrbitRadius + targetOrbitRadius) / 2.0;

    double deltaV1 = sqrt(G * massEarth / earthOrbitRadius) * (sqrt(2 * targetOrbitRadius / (earthOrbitRadius + targetOrbitRadius)) - 1);
    double deltaV2 = sqrt(G * massEarth / targetOrbitRadius) * (1 - sqrt(2 * earthOrbitRadius / (earthOrbitRadius + targetOrbitRadius)));

    return deltaV1 + deltaV2;
}

// Perform Bi-Elliptic transfer calculation
double TrajectoryCalculator::biEllipticTransfer(const std::string& targetPlanet, double payloadWeight, const PropulsionSystem& propulsionSystem) {
    double planetDistanceMillionKm = planetaryData.getDistanceToPlanet(targetPlanet);
    if (planetDistanceMillionKm == -1) {
        throw std::invalid_argument("Invalid planet");
    }

    double targetOrbitRadius = planetDistanceMillionKm * 1e9 * 1000;
    double intermediateOrbitRadius = 2 * targetOrbitRadius; // Example intermediate orbit radius

    double deltaV1 = sqrt(G * massEarth / earthOrbitRadius) * (sqrt(2 * intermediateOrbitRadius / (earthOrbitRadius + intermediateOrbitRadius)) - 1);
    double deltaV2 = sqrt(G * massEarth / intermediateOrbitRadius) * (sqrt(2 * targetOrbitRadius / (intermediateOrbitRadius + targetOrbitRadius)) - sqrt(2 * earthOrbitRadius / (earthOrbitRadius + intermediateOrbitRadius)));
    double deltaV3 = sqrt(G * massEarth / targetOrbitRadius) * (1 - sqrt(2 * intermediateOrbitRadius / (intermediateOrbitRadius + targetOrbitRadius)));

    return deltaV1 + deltaV2 + deltaV3;
}


double TrajectoryCalculator::fastTransfer(const std::string& targetPlanet, double payloadWeight, const PropulsionSystem& propulsionSystem) {
    double planetDistanceMillionKm = planetaryData.getDistanceToPlanet(targetPlanet);
    if (planetDistanceMillionKm == -1) {
        throw std::invalid_argument("Invalid planet");
    }

    double targetOrbitRadius = planetDistanceMillionKm * 1e9 * 1000;

    double deltaV1 = sqrt(G * massEarth / earthOrbitRadius) * (sqrt(2 * targetOrbitRadius / (earthOrbitRadius + targetOrbitRadius)) - 1);
    double deltaV2 = sqrt(G * massEarth / targetOrbitRadius) * (1 - sqrt(2 * earthOrbitRadius / (earthOrbitRadius + targetOrbitRadius)));

    // Increase deltaV1 and deltaV2 by a factor to simulate a faster transfer
    double fastTransferFactor = 1.5; // Example factor, adjust as needed
    deltaV1 *= fastTransferFactor;
    deltaV2 *= fastTransferFactor;

    return deltaV1 + deltaV2;
}
