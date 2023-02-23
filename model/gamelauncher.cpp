#include "gamelauncher.h"
#include "boatfactory.h"
#include "carfactory.h"
#include "motorbikefactory.h"
#include "planefactory.h"
#include "game.h"
#include "vehicletablemodel.h"

using namespace std;

GameLauncher::GameLauncher(QObject *parent): m_initializated(false), m_carLicense(false), m_motorbikeLicense(false), m_boatLicense(false), m_planeLicense(false)
{

}

void GameLauncher::initGame()
{
    vector<VehicleFactory*> vehicleFactories;
    vehicleFactories.push_back(new BoatFactory());
    vehicleFactories.push_back(new CarFactory());
    vehicleFactories.push_back(new MotorbikeFactory());
    vehicleFactories.push_back(new PlaneFactory());
    Game* game = new Game(m_userName, m_userAge, m_carLicense, m_motorbikeLicense, m_boatLicense, m_planeLicense, vehicleFactories);
    game->startGameLogic();
    m_games[m_userName] = game;
    sendModelToGuiByUser(m_userName);
    m_initializated = true;
}

bool GameLauncher::hasLicenseForVehicleByUser(const string &userName, Vehicle* vehicle) const
{
    return m_games.at(userName)->userHasLicenseForVehicle(vehicle);
}

vector<Vehicle*> GameLauncher::getVehiclesByUser(const string &userName) const
{
    return m_games.at(userName)->getUserVehicles();
}

void GameLauncher::receiveNameFromGui(const string &name)
{
    m_userName = name;
}

void GameLauncher::receiveAgeFromGui(const string &age)
{
    m_userAge = age;
}

void GameLauncher::receiveCarLicenseFromGui(const bool &carLicense)
{
    m_carLicense = carLicense;
}

void GameLauncher::receiveMotorbikeLicenseFromGui(const bool &motorbikeLicense)
{
    m_motorbikeLicense = motorbikeLicense;
}

void GameLauncher::receiveBoatLicenseFromGui(const bool &boatLicense)
{
    m_boatLicense = boatLicense;
}

void GameLauncher::receivePlaneLicenseFromGui(const bool &planeLicense)
{
    m_planeLicense = planeLicense;
}

void GameLauncher::sendModelToGuiByUser(const string &userName)
{
    emit sendModelToGui(new VehicleTableModel(this, m_games.at(userName)->getUserVehicles()));
}
