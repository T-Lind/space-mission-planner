#include "../include/launch_window_calculator.h"
#include <unordered_map>
#include <cmath>
#include <stdexcept>
#include <chrono>

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
    if (std::fabs(orbitalPeriod1 - orbitalPeriod2) < 1e-10) {
        throw std::invalid_argument("Cannot calculate synodic period between identical orbits");
    }
    return std::fabs(1.0 / ((1.0 / orbitalPeriod1) - (1.0 / orbitalPeriod2)));
}

double LaunchWindowCalculator::getOrbitalPeriod(const std::string& planet) const {
    auto it = orbitalPeriods.find(planet);
    if (it != orbitalPeriods.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Unknown planet: " + planet);
    }
}

std::vector<std::pair<std::string, std::string>> LaunchWindowCalculator::calculateLaunchWindows(const std::string& targetPlanet, int numberOfWindows, int windowDuration) {
    std::vector<std::pair<std::string, std::string>> launchWindows;

    if (targetPlanet == "Earth") {
        throw std::invalid_argument("Cannot calculate launch windows from Earth to Earth");
    }

    double earthOrbitalPeriod = getOrbitalPeriod("Earth");
    double targetOrbitalPeriod = getOrbitalPeriod(targetPlanet);

    double synodicPeriod = calculateSynodicPeriod(earthOrbitalPeriod, targetOrbitalPeriod);

    // Start from the current date
    auto now = std::chrono::system_clock::now();
    auto startDate = std::chrono::floor<std::chrono::days>(now);

    for (int i = 0; i < numberOfWindows; ++i) {
        // Calculate the next launch window date
        startDate += std::chrono::duration_cast<std::chrono::days>(std::chrono::duration<double>(synodicPeriod * 86400.0));

        // Format the date as a string
        auto launchDate = std::chrono::year_month_day(startDate);
        std::string launchDateStr = std::to_string(static_cast<int>(launchDate.year())) + "-" +
                                    std::to_string(static_cast<unsigned>(launchDate.month())) + "-" +
                                    std::to_string(static_cast<unsigned>(launchDate.day()));

        // Calculate the end of the launch window
        auto endDate = startDate + std::chrono::days(windowDuration);
        auto endDateYmd = std::chrono::year_month_day(endDate);
        std::string endDateStr = std::to_string(static_cast<int>(endDateYmd.year())) + "-" +
                                 std::to_string(static_cast<unsigned>(endDateYmd.month())) + "-" +
                                 std::to_string(static_cast<unsigned>(endDateYmd.day()));

        launchWindows.emplace_back(launchDateStr, endDateStr);
    }

    return launchWindows;
}