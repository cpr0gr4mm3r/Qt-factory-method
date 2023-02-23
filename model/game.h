#ifndef GAME_H
#define GAME_H


#include <vector>
#include <string>

class User;
class Vehicle;
class VehicleFactory;

class Game
{
private:
    User* m_user;
    std::vector<VehicleFactory*> m_vehicleFactories;
public:
    Game(const std::string &name, const std::string &age, const bool &carLicense, const bool &motorbikeLicense, const bool &boatLicense, const bool &planeLicense, const std::vector<VehicleFactory*> &vehicleFactories);
    void startGameLogic();
    bool userHasLicenseForVehicle(Vehicle* vehicle) const;
    std::vector<Vehicle*> getUserVehicles() const;
};

#endif // GAME_H
