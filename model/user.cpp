#include "user.h"
#include "vehicle.h"
#include <QString>

using namespace std;

User::User(std::string name, std::string age): m_name(name), m_age(age)
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
