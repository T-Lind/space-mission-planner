#ifndef PROPULSION_SYSTEM_H
#define PROPULSION_SYSTEM_H

#include <string>

class PropulsionSystem {
public:
    PropulsionSystem();

    // Set the propulsion type (e.g., "Chemical", "Ion", "Nuclear")
    void setPropulsionType(const std::string& type);

    // Get the specific impulse (Isp) of the selected propulsion system (in seconds)
    double getSpecificImpulse() const;

    // Get the thrust of the propulsion system (in Newtons)
    double getThrust() const;

private:
    std::string propulsionType;
    double specificImpulse; // Specific impulse (Isp) in seconds
    double thrust;          // Thrust in Newtons

    void configurePropulsion();
};

#endif
