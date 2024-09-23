#ifndef SLINGSHOT_OPTIMIZER_H
#define SLINGSHOT_OPTIMIZER_H

#include <string>
#include "planetary_data.h"

class SlingshotOptimizer {
public:
    SlingshotOptimizer();

    // Calculate optimal slingshot trajectory
    double calculateSlingshot(const std::string& targetPlanet);

private:
    PlanetaryData planetaryData;

    double gravitationalAssist(const std::string& assistingPlanet); // Helper function for calculating assist
};

#endif
