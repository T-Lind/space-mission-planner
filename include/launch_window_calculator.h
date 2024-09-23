#ifndef LAUNCH_WINDOW_CALCULATOR_H
#define LAUNCH_WINDOW_CALCULATOR_H

#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

class LaunchWindowCalculator {
public:
    LaunchWindowCalculator();

    std::vector<std::pair<std::string, std::string>>
    calculateLaunchWindows(const std::string &targetPlanet, int numberOfWindows, int windowDuration);

private:
    double calculateSynodicPeriod(double orbitalPeriod1, double orbitalPeriod2) const;

    double getOrbitalPeriod(const std::string& planet) const;

    std::unordered_map<std::string, double> orbitalPeriods;

};

#endif