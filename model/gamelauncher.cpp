#include "gamelauncher.h"
#include "boatfactory.h"
#include "carfactory.h"
#include "motorbikefactory.h"
#include "planefactory.h"
#include "game.h"
#include "user.h"

GameLauncher::GameLauncher()
{
    std::vector<VehicleFactory*> vehicleFactories;
    vehicleFactories.push_back(new BoatFactory());
    vehicleFactories.push_back(new CarFactory());
    vehicleFactories.push_back(new MotorbikeFactory());
    vehicleFactories.push_back(new PlaneFactory());
    m_game = new Game(vehicleFactories);
    m_game->startGameLogic();
}

std::vector<Vehicle*> GameLauncher::getVehicles()
{
    return m_game->getUser()->getVehicles();
}
