#include "../include/propulsion_system.h"

// Constructor initializes with a default propulsion type
PropulsionSystem::PropulsionSystem() : propulsionType("Chemical"), specificImpulse(0), thrust(0) {
    configurePropulsion(); // Configure default propulsion values
}

// Set the propulsion type (e.g., "Chemical", "Ion") and configure values accordingly
void PropulsionSystem::setPropulsionType(const std::string& type) {
    propulsionType = type;
    configurePropulsion(); // Reconfigure based on new type
}

// Return the specific impulse (Isp) of the propulsion system
double PropulsionSystem::getSpecificImpulse() const {
    return specificImpulse;
}

// Return the thrust of the propulsion system
double PropulsionSystem::getThrust() const {
    return thrust;
}

// Internal function to configure propulsion system based on the type
void PropulsionSystem::configurePropulsion() {
    if (propulsionType == "Chemical") {
        specificImpulse = 300.0;  // Typical chemical rocket Isp (in seconds)
        thrust = 7.0e6;           // Thrust in Newtons (example value)
    } else if (propulsionType == "Ion") {
        specificImpulse = 3000.0; // Ion thruster Isp (in seconds)
        thrust = 0.25;            // Low thrust (in Newtons)
    } else if (propulsionType == "Nuclear") {
        specificImpulse = 900.0;  // Nuclear thermal rocket Isp (in seconds)
        thrust = 1.0e6;           // Thrust in Newtons
    } else {
        // Default to Chemical if unknown propulsion type
        specificImpulse = 300.0;
        thrust = 7.0e6;
    }
}
