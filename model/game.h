#ifndef GAME_H
#define GAME_H


#include <vector>
#include <string>

class User;
class Vehicle;
class VehicleFactory;

/**
 * @brief The Game class stores an user with a vehicles list and applies a small logic while a vehicle is started.
 */
class Game
{
private:
    /**
     * @brief m_user. It is the driver of a vehicle.
     */
    User* m_user;
    /**
     * @brief m_vehicleFactories. It is a vector that keeps a list with the different factories to vehicle creation.
     */
    std::vector<VehicleFactory*> m_vehicleFactories;
public:
    /**
     * @brief Game. Constructor.
     * @param name. The user name of the driver.
     * @param age. The user age of the driver.
     * @param carLicense. The car license flag that indicates if the driver has a car license.
     * @param motorbikeLicense. The motorbike license flag that indicates if the driver has a car license.
     * @param boatLicense. The boat license flag that indicates if the driver has a car license.
     * @param planeLicense. The plane license flag that indicates if the driver has a car license.
     * @param vehicleFactories. The vector that keeps a list with the different factories to vehicle creation.
     */
    Game(const std::string &name, const std::string &age, const bool &carLicense, const bool &motorbikeLicense, const bool &boatLicense, const bool &planeLicense, const std::vector<VehicleFactory*> &vehicleFactories);
    /**
     * @brief startGameLogic. Starts the game by trying to start the engine of the vehicles for the user.
     */
    void startGameLogic();
    /**
     * @brief userHasLicenseForVehicle. Indicates if the user has a driver license for a certain vehicle.
     * @param vehicle. Vehicle assigned to the user to be used to check.
     * @return. true if the user has a driver license and false in otherwise.
     */
    bool userHasLicenseForVehicle(Vehicle* vehicle) const;
    /**
     * @brief getUserVehicles. Get the vehicles of the user.
     * @return. A STL vector with the vehicles.
     */
    std::vector<Vehicle*> getUserVehicles() const;
};

#endif // GAME_H
