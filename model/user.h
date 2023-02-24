#ifndef USER_H
#define USER_H


#include <string>
#include <vector>

class Vehicle;

/**
 * @brief The User class represents the model that identifies a user.
 */
class User
{
private:
    /**
     * @brief m_name. The user name of the driver.
     */
    std::string m_name;
    /**
     * @brief m_age. The user age of the driver.
     */
    std::string m_age;
    /**
     * @brief m_carLicense. The car license flag that indicates if the driver has a car license.
     */
    bool m_carLicense;
    /**
     * @brief m_motorbikeLicense. The motorbike license flag that indicates if the driver has a car license.
     */
    bool m_motorbikeLicense;
    /**
     * @brief m_boatLicense. The boat license flag that indicates if the driver has a car license.
     */
    bool m_boatLicense;
    /**
     * @brief m_planeLicense. The plane license flag that indicates if the driver has a car license.
     */
    bool m_planeLicense;
    /**
     * @brief m_vehicles. The vehicles list that belong to the user.
     */
    std::vector<Vehicle*> m_vehicles;

public:
    /**
     * @brief User. Constructor.
     * @param name. The user name of the driver.
     * @param age. The user age of the driver.
     * @param carLicense. The car license flag that indicates if the driver has a car license.
     * @param motorbikeLicense. The motorbike license flag that indicates if the driver has a car license.
     * @param boatLicense. The boat license flag that indicates if the driver has a car license.
     * @param planeLicense. The plane license flag that indicates if the driver has a car license.
     */
    User(std::string name, std::string age, bool carLicense, bool motorbikeLicense, bool boatLicense, bool planeLicense);

    /**
     * @brief getVehicle. Accessor method to return a vehicle.
     * @param identifier. Unique string used to get the proper vehicle in the vehicles list.
     * @return The vehicle that matches with the identifier.
     */
    Vehicle* getVehicle(const std::string &identifier);
    /**
     * @brief addVehicle. Adds a vehicle in the vehicles list.
     * @param vehicle. The vehicle object that will be added in the vehicles list.
     */
    void addVehicle(Vehicle* vehicle);

    /**
     * @brief getVehicles. Accessor method to return the vehicles list.
     * @return A STL vector with the vehicles list.
     */
    std::vector<Vehicle*> getVehicles() const {return m_vehicles;}

    /**
     * @brief hasLicenseForVehicle. Indicates if the driver has a license to drive a certain vehicle.
     * @param vehicle. The vehicle to be used to perform the operation.
     * @return true if the user can drive the vehicle or false in otherwise.
     */
    bool hasLicenseForVehicle(Vehicle* vehicle);

};

#endif // USER_H
