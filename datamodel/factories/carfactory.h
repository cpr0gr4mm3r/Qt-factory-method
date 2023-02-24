#ifndef CARFACTORY_H
#define CARFACTORY_H


#include "vehiclefactory.h"

/**
 * @brief The CarFactory class is used to create an instance of type Car. Generates vehicules of car type.
 */
class CarFactory: public VehicleFactory
{
public:
    /**
     * @brief CarFactory. Constructor.
     */
    CarFactory();

    /**
     * @brief factoryMethod. Creates an instance of type Car.
     * @return The new car instance.
     */
    Vehicle* factoryMethod() override;
};

#endif // CARFACTORY_H
