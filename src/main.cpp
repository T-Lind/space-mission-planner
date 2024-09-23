#include "../include/planetary_data.h"
#include "../include/propulsion_system.h"
#include "../include/trajectory_calculator.h"
#include "../include/fuel_estimator.h"
#include "../include/launch_window_calculator.h"
#include "../include/mission_planner.h"

int main() {
    MissionPlanner planner;
    planner.run();

    return 0;
}
