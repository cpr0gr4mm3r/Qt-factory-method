#include "game.h"
#include "vehiclefactory.h"
#include "user.h"
#include "vehicle.h"

using namespace std;

Game::Game(std::string name, std::string age, vector<VehicleFactory*> vehicleFactories): m_vehicleFactories(vehicleFactories)
{
    m_user = new User(name, age);
    for (vector<VehicleFactory*>::iterator vehiclesFactoryIterator = m_vehicleFactories.begin(); vehiclesFactoryIterator != m_vehicleFactories.end(); vehiclesFactoryIterator++)
    {
        m_user->addVehicle((*vehiclesFactoryIterator)->factoryMethod());
    }
}

void Game::startGameLogic()
{
    m_user->getVehicle("BOAT")->start();
    m_user->getVehicle("CAR")->start();
    m_user->getVehicle("MOTORBIKE")->start();
    m_user->getVehicle("PLANE")->start();
}

User* Game::getUser()
{
    return m_user;
}
