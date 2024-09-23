cmake_minimum_required(VERSION 3.0)
project(space_mission_planner)

set(CMAKE_CXX_STANDARD 20)

add_executable(space_mission_planner
        src/main.cpp
        include/mission_planner.h
        src/planetary_data.cpp
        src/propulsion_system.cpp
        include/trajectory_calculator.h
        src/trajectory_calculator.cpp
        src/fuel_estimator.cpp
        include/fuel_estimator.h
        include/launch_window_calculator.h
        src/launch_window_calculator.cpp
        src/mission_planner.cpp)
