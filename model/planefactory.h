#ifndef PLANEFACTORY_H
#define PLANEFACTORY_H


#include "vehiclefactory.h"

class PlaneFactory: public VehicleFactory
{
public:
    PlaneFactory();

    Vehicle* factoryMethod() override;
};

#endif // PLANEFACTORY_H
