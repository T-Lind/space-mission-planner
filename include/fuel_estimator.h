#ifndef FUEL_ESTIMATOR_H
#define FUEL_ESTIMATOR_H

#include "propulsion_system.h"

class FuelEstimator {
public:
    // Constructor
    FuelEstimator();

    // Estimate the fuel required for the mission
    // Takes delta-v (in m/s), payload weight (in kg), and propulsion system
    // Returns fuel mass required in kg
    double estimateFuelRequired(double deltaV, double payloadWeight, const PropulsionSystem& propulsionSystem);

private:
    const double g0 = 9.81; // Earth's gravity constant (m/s^2)

    // Calculate fuel mass using the Tsiolkovsky rocket equation
    double calculateFuelMass(double deltaV, double Isp, double payloadWeight);
};

#endif
