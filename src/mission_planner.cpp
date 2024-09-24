#include "../include/mission_planner.h"
#include <iostream>
#include <fstream>

MissionPlanner::MissionPlanner()
        : fuelEstimator() {}

void MissionPlanner::run(bool userInput) {
    if (userInput) {
        getUserInput();
    }
    calculateMission();
    displayResults();
}

void MissionPlanner::run() {
    run(true);
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
    std::cout << "Enter window duration (days): ";
    std::cin >> windowDuration;
    numberOfWindows = 5;


    int transferTypeInput;
    std::cout << "Enter transfer type (0: Hohmann, 1: Bi-Elliptic, 2: Fast Transfer): ";
    std::cin >> transferTypeInput;

    if (transferTypeInput < 0 || transferTypeInput > 2) {
        std::cerr << "Invalid transfer type!" << std::endl;
        return;
    }

    transferType = static_cast<TrajectoryCalculator::TransferType>(transferTypeInput);
}

void MissionPlanner::setData(std::string targetPlanet, double payloadWeight, double fuelBudget, int windowDuration,
                             int numberOfWindows, std::string propulsionType, TrajectoryCalculator::TransferType transferType) {
    this->targetPlanet = targetPlanet;
    this->payloadWeight = payloadWeight;
    this->fuelBudget = fuelBudget;
    this->windowDuration = windowDuration;
    this->numberOfWindows = numberOfWindows;
    this->propulsionType = propulsionType;
    this->transferType = transferType;
}

void MissionPlanner::calculateMission() {
    propulsionSystem.setPropulsionType(propulsionType);

    // Note that assigning deltaV here overwrites the member variable!
    deltaV = trajectoryCalculator.calculateTrajectory(targetPlanet, payloadWeight, propulsionSystem, transferType);
    if (deltaV == -1) {
        std::cerr << "Invalid planet name or transfer type!" << std::endl;
        return;
    }
}

void MissionPlanner::displayResults() {
    std::cout << "Delta-V required: " << deltaV << " m/s" << std::endl;

    double requiredFuelMass = fuelEstimator.estimateFuelRequired(deltaV, payloadWeight, propulsionSystem);
    std::cout << "Required fuel mass: " << requiredFuelMass << " kg" << std::endl;

    int daysTilNextLaunchWindow = launchWindowCalculator.calculateNextLaunchWindow(targetPlanet, 267);

    std::cout << "Days until next launch window: " << daysTilNextLaunchWindow << std::endl;
}

void MissionPlanner::saveDataForVaryingPayloads(const std::string &filename, double minPayload, double maxPayload,
                                                double step) {
    {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        outFile << "PayloadWeight,RequiredFuelMass\n";
        std::cout << "PayloadWeight,RequiredFuelMass" << std::endl;

        for (double payload = minPayload; payload <= maxPayload; payload += step) {
            setData(targetPlanet, payload, fuelBudget, windowDuration, numberOfWindows, propulsionType, transferType);
            calculateMission();
            double requiredFuelMass = fuelEstimator.estimateFuelRequired(deltaV, payload, propulsionSystem);
            outFile << payload << "," << requiredFuelMass << "\n";
//            std::cout << "Payload: " << payload << " kg, Fuel: " << requiredFuelMass << " kg" << std::endl;
            std::cout << payload << "," << requiredFuelMass << std::endl;
        }
    }

    std::cout << "Data saved to " << filename << std::endl;
}