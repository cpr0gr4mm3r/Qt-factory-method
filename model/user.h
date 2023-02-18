#ifndef USER_H
#define USER_H


#include <string>
#include <vector>

class Vehicle;

class User
{
private:
    std::string m_name;
    unsigned char m_age;
    std::vector<Vehicle*> m_vehicles;

public:
    User();

    std::string getName() {return m_name;}
    void setName(const std::string &name) {m_name = name;}

    unsigned char getAge() {return m_age;}
    void setAge(const unsigned char &age) {m_age = age;}

    Vehicle* getVehicle(const std::string &identifier);
    void addVehicle(Vehicle* vehicle);

    std::vector<Vehicle*> getVehicles(){return m_vehicles;}

};

#endif // USER_H
