#include "user.h"
#include "vehicle.h"
#include "car.h"
#include "motorbike.h"
#include "boat.h"
#include "plane.h"
#include <QString>

using namespace std;

User::User(std::string name, std::string age, bool carLicense, bool motorbikeLicense, bool boatLicense, bool planeLicense):
    m_name(name),
    m_age(age),
    m_carLicense(carLicense),
    m_motorbikeLicense(motorbikeLicense),
    m_boatLicense(boatLicense),
    m_planeLicense(planeLicense)
{

}

Vehicle* User::getVehicle(const string &identifier)
{
    Vehicle* returnedVehicle = 0;
    for (vector<Vehicle*>::iterator vehicleIterator = m_vehicles.begin(); vehicleIterator != m_vehicles.end(); vehicleIterator++)
    {
        if (QString::fromStdString((*vehicleIterator)->getIdentifier()).contains(QString::fromStdString(identifier)))
        {
            returnedVehicle = *vehicleIterator;
            break;
        }
    }
    return returnedVehicle;
}

void User::addVehicle(Vehicle* vehicle)
{
    m_vehicles.push_back(vehicle);
}

bool User::hasLicenseForVehicle(Vehicle* vehicle)
{
    bool hasLicense = false;
    if (dynamic_cast<Car*>(vehicle) && m_carLicense)
    {
        hasLicense = true;
    }
    else if (dynamic_cast<Motorbike*>(vehicle) && m_motorbikeLicense)
    {
        hasLicense = true;
    }
    else if (dynamic_cast<Boat*>(vehicle) && m_boatLicense)
    {
        hasLicense = true;
    }
    else if (dynamic_cast<Plane*>(vehicle) && m_planeLicense)
    {
        hasLicense = true;
    }
    return hasLicense;
}
