#include "vehiclefactory.h"
#include "vehicle.h"

VehicleFactory::VehicleFactory()
{

}

void VehicleFactory::testVehicle()
{
    srand((unsigned) time(NULL));
    Vehicle* vehicle = factoryMethod();
    vehicle->start();
    vehicle->start();
    delete vehicle;
}
