#include "gamelauncher.h"
#include "datamodel/factories/boatfactory.h"
#include "datamodel/factories/carfactory.h"
#include "datamodel/factories/motorbikefactory.h"
#include "datamodel/factories/planefactory.h"
#include "datamodel/models/game.h"
#include "logger.h"
#include "datamodel/models/vehicletablemodel.h"
#include <QStringListModel>

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
    m_initializated = true;
    sendModelsToGuiByUser(m_userName);
}

bool GameLauncher::updateState(const string &name, Vehicle* vehicle)
{
    bool getLicenseForVehicle(m_games.at(name)->userHasLicenseForVehicle(vehicle));
    bool stateChanged = false;
    if (getLicenseForVehicle && vehicle->isRunning())
    {
        vehicle->stop();
        stateChanged = true;
    }
    else if (getLicenseForVehicle)
    {
        vehicle->start();
        stateChanged = true;
    }
    return stateChanged;
}

void GameLauncher::updateState(const string &userName, const string &vehicleIdentifier)
{
    Vehicle* returnedVehicle = nullptr;
    std::vector<Vehicle*> vehicles = m_games.at(userName)->getUserVehicles();
    for (std::vector<Vehicle*>::iterator vehicleIterator = vehicles.begin(); vehicleIterator != vehicles.end(); vehicleIterator++)
    {
        (*vehicleIterator)->getLogger()->clearLines();
        if (QString::fromStdString((*vehicleIterator)->getIdentifier()).contains(QString::fromStdString(vehicleIdentifier)))
        {
            returnedVehicle = *vehicleIterator;
            break;
        }
    }
    if (returnedVehicle)
    {
        if (updateState(userName, returnedVehicle))
        {
            sendModelsToGuiByUser(userName);
        }
    }
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

void GameLauncher::sendLogsModelToGui(const string &userName)
{
    std::vector<Vehicle*> vehicles = m_games.at(userName)->getUserVehicles();
    QStringListModel* model = new QStringListModel(this);
    for (std::vector<Vehicle*>::iterator vehicleIterator = vehicles.begin(); vehicleIterator != vehicles.end(); vehicleIterator++)
    {
        std::vector<std::string> lines = (*vehicleIterator)->getLogger()->getLines();
        for (std::vector<std::string>::iterator lineIterator = lines.begin(); lineIterator != lines.end(); lineIterator++)
        {
            m_loggerList << QString::fromStdString(*lineIterator);
        }
        (*vehicleIterator)->getLogger()->clearLines();
    }
    model->setStringList(m_loggerList);
    emit sendLogsModelToGui(model);
}

void GameLauncher::sendModelsToGuiByUser(const string &userName)
{
    emit sendModelToGui(new VehicleTableModel(this, m_games.at(userName)->getUserVehicles()));
    emit sendVehiclesToGui(m_games.at(userName)->getUserVehicles());
    sendLogsModelToGui(userName);
}
