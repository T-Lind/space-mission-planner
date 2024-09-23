#include "../include/launch_window_calculator.h"
#include <unordered_map>
#include <cmath> // for fabs
#include <ctime> // for time_t, struct tm, mktime, strftime
#include <sstream> // for std::ostringstream

LaunchWindowCalculator::LaunchWindowCalculator() {
    // Initialize orbital periods (in Earth days)
    orbitalPeriods = {
        {"Mercury", 87.97},
        {"Venus", 224.70},
        {"Earth", 365.25},
        {"Mars", 686.98},
        {"Jupiter", 4332.59},
        {"Saturn", 10759.22},
        {"Uranus", 30688.5},
        {"Neptune", 60182.0}
    };
}

double LaunchWindowCalculator::calculateSynodicPeriod(double orbitalPeriod1, double orbitalPeriod2) const {
    return fabs(1.0 / ((1.0 / orbitalPeriod1) - (1.0 / orbitalPeriod2)));
}

double LaunchWindowCalculator::getOrbitalPeriod(const std::string& planet) const {
    if (orbitalPeriods.find(planet) != orbitalPeriods.end()) {
        return orbitalPeriods.at(planet);
    } else {
        return -1; // Return -1 for unknown planet
    }
}

std::vector<std::pair<std::string, std::string>> LaunchWindowCalculator::calculateLaunchWindows(const std::string& targetPlanet, int numberOfWindows) {
    std::vector<std::pair<std::string, std::string>> launchWindows;

    double earthOrbitalPeriod = getOrbitalPeriod("Earth");
    double targetOrbitalPeriod = getOrbitalPeriod(targetPlanet);

    if (earthOrbitalPeriod == -1 || targetOrbitalPeriod == -1) {
        return launchWindows; // Return empty vector if planet is unknown
    }

    double synodicPeriod = calculateSynodicPeriod(earthOrbitalPeriod, targetOrbitalPeriod);

    // Start from the current date
    time_t now = time(0);
    struct tm startDate = *gmtime(&now);

    for (int i = 0; i < numberOfWindows; ++i) {
        // Calculate the next launch window date
        startDate.tm_mday += static_cast<int>(synodicPeriod);
        mktime(&startDate); // Normalize the date

        // Format the date as a string
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &startDate);
        std::string launchDate(buffer);

        // Calculate the end of the launch window (assuming a 10-day window for simplicity)
        startDate.tm_mday += 10;
        mktime(&startDate); // Normalize the date
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &startDate);
        std::string endDate(buffer);

        launchWindows.push_back(std::make_pair(launchDate, endDate));

        // Reset the start date to the end of the current window
        startDate.tm_mday -= 10;
        mktime(&startDate); // Normalize the date
    }

    return launchWindows;
}