#include "vehiclefactory.h"
#include "datamodel/models/vehicle.h"

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
