#include "../include/fuel_estimator.h"
#include <cmath>
// Constructor
FuelEstimator::FuelEstimator() {}

// Estimate the fuel required for the mission
double FuelEstimator::estimateFuelRequired(double deltaV, double payloadWeight, const PropulsionSystem& propulsionSystem) {
    // Get the specific impulse (Isp) from the propulsion system
    double specificImpulse = propulsionSystem.getSpecificImpulse();

    // Use the Tsiolkovsky rocket equation to calculate the required fuel mass
    return calculateFuelMass(deltaV, specificImpulse, payloadWeight);
}

// Private function to calculate fuel mass using the rocket equation
double FuelEstimator::calculateFuelMass(double deltaV, double Isp, double payloadWeight) {
    // Rocket equation: deltaV = Isp * g0 * ln(m0/mf)
    // Rearranging to solve for fuel mass:
    // m0 = mf * exp(deltaV / (Isp * g0))
    // fuelMass = m0 - mf
    double exhaustVelocity = Isp * g0; // Isp * g0 gives the exhaust velocity
    double massRatio = exp(deltaV / exhaustVelocity); // m0/mf ratio
    double initialMass = payloadWeight * massRatio; // m0 = mf * massRatio

    // Fuel mass is the difference between initial mass (m0) and final mass (mf)
    double fuelMass = initialMass - payloadWeight;

    return fuelMass;
}
