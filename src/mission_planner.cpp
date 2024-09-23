#include "../include/mission_planner.h"
#include <iostream>

MissionPlanner::MissionPlanner()
        : fuelEstimator(0, 0, 0)
{}

void MissionPlanner::run() {
    getUserInput();
    calculateMission();
    displayResults();
}

void MissionPlanner::getUserInput() {
    std::cout << "Enter target planet: ";
    std::cin >> targetPlanet;
    std::cout << "Enter payload weight (kg): ";
    std::cin >> payloadWeight;
    std::cout << "Enter fuel budget (kg): ";
    std::cin >> fuelBudget;
    std::cout << "Enter propulsion type (Chemical, Ion, Nuclear): ";
    std::cin >> propulsionType;

    int transferTypeInput;
    std::cout << "Enter transfer type (0: Hohmann, 1: Bi-Elliptic, 2: Fast Transfer): ";
    std::cin >> transferTypeInput;

    if (transferTypeInput < 0 || transferTypeInput > 2) {
        std::cerr << "Invalid transfer type!" << std::endl;
        return;
    }

    transferType = static_cast<TrajectoryCalculator::TransferType>(transferTypeInput);
}

void MissionPlanner::calculateMission() {
    propulsionSystem.setPropulsionType(propulsionType);

    double deltaV = trajectoryCalculator.calculateTrajectory(targetPlanet, payloadWeight, propulsionSystem, transferType);
    if (deltaV == -1) {
        std::cerr << "Invalid planet name or transfer type!" << std::endl;
        return;
    }

    fuelEstimator = FuelEstimator(payloadWeight, propulsionSystem.getSpecificImpulse(), deltaV);
}

void MissionPlanner::displayResults() {
    double requiredFuelMass = fuelEstimator.calculateFuelMass();
    std::cout << "Required fuel mass: " << requiredFuelMass << " kg" << std::endl;

    int numberOfWindows = 5;
    std::vector<std::pair<std::string, std::string>> launchWindows = launchWindowCalculator.calculateLaunchWindows(targetPlanet, numberOfWindows);

    std::cout << "Launch windows for " << targetPlanet << ":" << std::endl;
    for (const auto& window : launchWindows) {
        std::cout << "Start: " << window.first << ", End: " << window.second << std::endl;
    }
}
