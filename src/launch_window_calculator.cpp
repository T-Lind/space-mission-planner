#include "../include/launch_window_calculator.h"
#include <cmath> // For fabs and cos/sin functions
#include <iostream> // For debugging output

LaunchWindowCalculator::LaunchWindowCalculator() {}

int LaunchWindowCalculator::calculateNextLaunchWindow(const std::string& targetPlanet, int currentDayOfYear) {
    double earthPosition = planetaryData.getPlanetPosition("Earth", currentDayOfYear);
    double targetPosition = planetaryData.getPlanetPosition(targetPlanet, currentDayOfYear);

    if (targetPosition == -1) {
        return -1;
    }

    double currentPhaseAngle = calculatePhaseAngle(earthPosition, targetPosition);

    // Ideal phase angle for a Hohmann transfer to Mars (~44 degrees) TODO: Make this configurable for diff planets
    double optimalPhaseAngle = 44.0;

    return findNextOptimalLaunchWindow(currentPhaseAngle, optimalPhaseAngle, planetaryData.getPlanetOrbitalPeriod(targetPlanet));
}

double LaunchWindowCalculator::calculatePhaseAngle(double earthPosition, double targetPosition) {
    return fabs(targetPosition - earthPosition);
}

// Find the next launch window based on phase angles
int LaunchWindowCalculator::findNextOptimalLaunchWindow(double currentPhaseAngle, double optimalPhaseAngle, double planetOrbitalPeriod) {
    // Propagate forward until the phase angle matches the optimal value
    double phaseDifference = optimalPhaseAngle - currentPhaseAngle;
    if (phaseDifference < 0) {
        phaseDifference += 360.0; // Ensure the phase angle is positive
    }

    // Calculate the time it will take to reach the ideal phase angle
    double timeToNextWindow = planetOrbitalPeriod * (phaseDifference / 360.0);
    return static_cast<int>(timeToNextWindow);
}
