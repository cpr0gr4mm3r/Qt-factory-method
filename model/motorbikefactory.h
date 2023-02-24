#ifndef MOTORBIKEFACTORY_H
#define MOTORBIKEFACTORY_H


#include "vehiclefactory.h"

/**
 * @brief The MotorbikeFactory class is used to create an instance of type Motorbike. Generates vehicules of motorbike type.
 */
class MotorbikeFactory: public VehicleFactory
{
public:
    /**
     * @brief MotorbikeFactory. Constructor.
     */
    MotorbikeFactory();

    /**
     * @brief factoryMethod. Creates an instance of type Motorbike.
     * @return The new motorbike instance.
     */
    Vehicle* factoryMethod() override;
};

#endif // MOTORBIKEFACTORY_H
