#ifndef CAR_H
#define CAR_H


#include "vehicle.h"
#include <string>

class Car: public Vehicle
{
private:
    std::string m_identifier;
public:
    Car(const std::string &identifier);

    void start() override;
    void stop() override;

};

#endif // CAR_H
