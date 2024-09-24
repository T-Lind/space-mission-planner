#ifndef LAUNCH_WINDOW_CALCULATOR_H
#define LAUNCH_WINDOW_CALCULATOR_H

#include <string>
#include "planetary_data.h"

class LaunchWindowCalculator {
public:
    // Constructor
    LaunchWindowCalculator();

    // Calculate the next launch window based on the current date
    // Returns time in days until the next launch window
    int calculateNextLaunchWindow(const std::string& targetPlanet, int currentDayOfYear);

private:
    PlanetaryData planetaryData; // To retrieve planetary orbital and position data

    // Calculate the current phase angle between Earth and the target planet
    static double calculatePhaseAngle(double earthPosition, double targetPosition);

    // Find the next time the phase angle matches the optimal value for a transfer
    static int findNextOptimalLaunchWindow(double currentPhaseAngle, double optimalPhaseAngle, double planetOrbitalPeriod);
};

#endif
