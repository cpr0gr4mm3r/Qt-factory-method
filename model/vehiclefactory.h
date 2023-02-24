#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H


class Vehicle;

/**
 * @brief The VehicleFactory class represents a generic factory of vehicles.
 */
class VehicleFactory
{
public:
    /**
     * @brief VehicleFactory. Constructor.
     */
    VehicleFactory();

    /**
     * @brief factoryMethod. Pure virtual method that defines the vehicle factory behavior intended to create an instance of type Vehicle.
     * @return The new vehicle instance.
     */
    virtual Vehicle* factoryMethod() = 0;

    /**
     * @brief testVehicle. Tests a vehicle by running and stopping the engine.
     */
    void testVehicle();
};

#endif // VEHICLEFACTORY_H
