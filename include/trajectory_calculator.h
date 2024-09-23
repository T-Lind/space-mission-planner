#ifndef TRAJECTORY_CALCULATOR_H
#define TRAJECTORY_CALCULATOR_H

#include <string>
#include "planetary_data.h"
#include "propulsion_system.h"

class TrajectoryCalculator {
public:
    TrajectoryCalculator();

    double calculateTrajectory(const std::string& targetPlanet, double payloadWeight, const PropulsionSystem& propulsionSystem);

    // Different types of transfer trajectories
    enum TransferType {
        HOHMANN,
        BI_ELLIPTIC,
        FAST_TRANSFER
    };
    double calculateTrajectory(const std::string& targetPlanet, double payloadWeight, const PropulsionSystem& propulsionSystem, TransferType transferType);


private:
    double hohmannTransfer(const std::string& targetPlanet, double payloadWeight, const PropulsionSystem& propulsionSystem);

    double biEllipticTransfer(const std::string& targetPlanet, double payloadWeight, const PropulsionSystem& propulsionSystem);

    double fastTransfer(const std::string& targetPlanet, double payloadWeight, const PropulsionSystem& propulsionSystem);

    PlanetaryData planetaryData;
};

#endif
