#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H


class Vehicle;

class VehicleFactory
{
public:
    VehicleFactory();

    virtual Vehicle* factoryMethod() = 0;

    void testVehicle();
};

#endif // VEHICLEFACTORY_H
