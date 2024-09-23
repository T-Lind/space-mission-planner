#include "../include/fuel_estimator.h"
#include <cmath> // for exp

FuelEstimator::FuelEstimator(double payloadWeight, double specificImpulse, double deltaV)
    : payloadWeight(payloadWeight), specificImpulse(specificImpulse), deltaV(deltaV) {}

double FuelEstimator::calculateFuelMass() const {
    // Tsiolkovsky rocket equation: m_fuel = m_payload * (exp(deltaV / (Isp * g0)) - 1)
    const double g0 = 9.80665; // Standard gravity in m/s^2
    return payloadWeight * (std::exp(deltaV / (specificImpulse * g0)) - 1);
}