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

private:
    void getUserInput();

    std::string targetPlanet;
    double payloadWeight;
    double fuelBudget;
    double windowDuration;
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