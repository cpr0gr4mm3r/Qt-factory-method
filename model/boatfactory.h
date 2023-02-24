#ifndef BOATFACTORY_H
#define BOATFACTORY_H


#include "vehiclefactory.h"

/**
 * @brief The BoatFactory class is used to create an instance of type Boat. Generates vehicules of boat type.
 */
class BoatFactory: public VehicleFactory
{
public:
    /**
     * @brief BoatFactory. Constructor.
     */
    BoatFactory();

    /**
     * @brief factoryMethod. Creates an instance of type Boat.
     * @return The new boat instance.
     */
    Vehicle* factoryMethod() override;
};

#endif // BOATFACTORY_H
