#ifndef FUEL_ESTIMATOR_H
#define FUEL_ESTIMATOR_H

class FuelEstimator {
public:
    FuelEstimator(double payloadWeight, double specificImpulse, double deltaV);

    double calculateFuelMass() const;

private:
    double payloadWeight;
    double specificImpulse;
    double deltaV;
};

#endif