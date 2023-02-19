#include "gamelauncher.h"
#include "boatfactory.h"
#include "carfactory.h"
#include "motorbikefactory.h"
#include "planefactory.h"
#include "game.h"
#include "user.h"
#include <iostream>

GameLauncher::GameLauncher(QObject *parent)
{
    std::vector<VehicleFactory*> vehicleFactories;
    vehicleFactories.push_back(new BoatFactory());
    vehicleFactories.push_back(new CarFactory());
    vehicleFactories.push_back(new MotorbikeFactory());
    vehicleFactories.push_back(new PlaneFactory());
    m_game = new Game(m_userName, m_userAge, vehicleFactories);
    m_game->startGameLogic();
}

std::vector<Vehicle*> GameLauncher::getVehicles()
{
    return m_game->getUser()->getVehicles();
}

void GameLauncher::receive_name_from_gui(std::string name)
{
    std::cout << "Name received from gui: " << name << std::endl;
    m_userName = name;
}

void GameLauncher::receive_age_from_gui(std::string age)
{
    std::cout << "Age received from gui: " << age << std::endl;
    m_userAge = age;
}
