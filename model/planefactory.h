#ifndef PLANEFACTORY_H
#define PLANEFACTORY_H


#include "vehiclefactory.h"

/**
 * @brief The PlaneFactory class is used to create an instance of type Plane. Generates vehicules of plane type.
 */
class PlaneFactory: public VehicleFactory
{
public:
    /**
     * @brief PlaneFactory. Constructor.
     */
    PlaneFactory();

    /**
     * @brief factoryMethod. Creates an instance of type Plane.
     * @return The new plane instance.
     */
    Vehicle* factoryMethod() override;
};

#endif // PLANEFACTORY_H
