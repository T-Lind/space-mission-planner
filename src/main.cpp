#include "../include/planetary_data.h"
#include "../include/propulsion_system.h"
#include "../include/trajectory_calculator.h"
#include "../include/fuel_estimator.h"
#include "../include/launch_window_calculator.h"
#include "../include/mission_planner.h"
#include <filesystem>
#include <iostream>

int main() {
    std::string directory = R"(C:\Users\tenant\CLionProjects\space-mission-planner\data\)";
    if (!std::filesystem::exists(directory)) {
        std::filesystem::create_directories(directory);
    }

    MissionPlanner planner;
    std::cout << "Running mission planner with Hohmann Transfer to Mars..." << std::endl;
    planner.setData("Mars", 1000, 10000, 100, 5,
                    "Chemical", TrajectoryCalculator::TransferType::HOHMANN);
    planner.run(false);



    std::cout << "Running mission planner with Bi-Elliptic Transfer to Mars..." << std::endl;
    planner.setData("Mars", 1000, 10000, 100, 5,
                    "Chemical", TrajectoryCalculator::TransferType::BI_ELLIPTIC);
    planner.run(false);

    std::cout << "Running mission planner with Fast Transfer to Mars..." << std::endl;
    planner.setData("Mars", 1000, 10000, 100, 5,
                    "Chemical", TrajectoryCalculator::TransferType::FAST_TRANSFER);
    planner.run(false);
    return 0;
}