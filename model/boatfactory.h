#ifndef BOATFACTORY_H
#define BOATFACTORY_H


#include "vehiclefactory.h"

class BoatFactory: public VehicleFactory
{
public:
    BoatFactory();

    Vehicle* factoryMethod() override;
};

#endif // BOATFACTORY_H
