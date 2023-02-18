#ifndef MOTORBIKEFACTORY_H
#define MOTORBIKEFACTORY_H


#include "vehiclefactory.h"

class MotorbikeFactory: public VehicleFactory
{
public:
    MotorbikeFactory();

    Vehicle* factoryMethod() override;
};

#endif // MOTORBIKEFACTORY_H
