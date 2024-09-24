#ifndef MISSION_PLANNER_H
#define MISSION_PLANNER_H

#include <string>
#include "trajectory_calculator.h"
#include "fuel_estimator.h"
#include "launch_window_calculator.h"
#include "planetary_data.h"
#include "propulsion_system.h"

class MissionPlanner {
public:
    MissionPlanner();

    void run();
    void run(bool userInput);

    void setData(std::string targetPlanet, double payloadWeight, double fuelBudget, int windowDuration,
                 int numberOfWindows, std::string propulsionType, TrajectoryCalculator::TransferType transferType);

    void saveDataForVaryingPayloads(const std::string& filename, double minPayload, double maxPayload, double stepSize);

private:
    void getUserInput();

    std::string targetPlanet;
    double payloadWeight;
    double fuelBudget;
    int windowDuration;
    int numberOfWindows;
    std::string propulsionType;

    TrajectoryCalculator::TransferType transferType;

    TrajectoryCalculator trajectoryCalculator;
    FuelEstimator fuelEstimator;
    LaunchWindowCalculator launchWindowCalculator;
    PlanetaryData planetaryData;
    PropulsionSystem propulsionSystem;

    double deltaV;  // output variable to keep track of

    void calculateMission();

    void displayResults();
};

#endif