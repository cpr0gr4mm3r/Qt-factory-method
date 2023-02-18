#ifndef CARFACTORY_H
#define CARFACTORY_H


#include "vehiclefactory.h"

class CarFactory: public VehicleFactory
{
public:
    CarFactory();

    Vehicle* factoryMethod() override;
};

#endif // CARFACTORY_H
