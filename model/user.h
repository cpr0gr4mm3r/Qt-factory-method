#ifndef USER_H
#define USER_H


#include <string>
#include <vector>

class Vehicle;

class User
{
private:
    std::string m_name;
    std::string m_age;
    bool m_carLicense;
    bool m_motorbikeLicense;
    bool m_boatLicense;
    bool m_planeLicense;
    std::vector<Vehicle*> m_vehicles;

public:
    User(std::string name, std::string age, bool carLicense, bool motorbikeLicense, bool boatLicense, bool planeLicense);

    Vehicle* getVehicle(const std::string &identifier);
    void addVehicle(Vehicle* vehicle);

    std::vector<Vehicle*> getVehicles() const {return m_vehicles;}

    bool hasLicenseForVehicle(Vehicle* vehicle);

};

#endif // USER_H
