#include "game.h"
#include "datamodel/factories/vehiclefactory.h"
#include "user.h"
#include "vehicle.h"

using namespace std;

Game::Game(const string &name, const string &age, const bool &carLicense, const bool &motorbikeLicense, const bool &boatLicense, const bool &planeLicense, const vector<VehicleFactory*> &vehicleFactories): m_vehicleFactories(vehicleFactories)
{
    m_user = new User(name, age, carLicense, motorbikeLicense, boatLicense, planeLicense);
    for (vector<VehicleFactory*>::iterator vehiclesFactoryIterator = m_vehicleFactories.begin(); vehiclesFactoryIterator != m_vehicleFactories.end(); vehiclesFactoryIterator++)
    {
        m_user->addVehicle((*vehiclesFactoryIterator)->factoryMethod());
    }
}

void Game::startGameLogic()
{
    vector<Vehicle*> vehicles = m_user->getVehicles();
    for (vector<Vehicle*>::iterator vehiclesIterator = vehicles.begin(); vehiclesIterator != vehicles.end(); vehiclesIterator++)
    {
        if (m_user->hasLicenseForVehicle((*vehiclesIterator)))
        {
            (*vehiclesIterator)->start();
        }
    }
}

bool Game::userHasLicenseForVehicle(Vehicle* vehicle) const
{
    return m_user->hasLicenseForVehicle(vehicle);
}

vector<Vehicle*> Game::getUserVehicles() const
{
    return m_user->getVehicles();
}
