#ifndef CAR_H
#define CAR_H


#include "vehicle.h"

class Car: public Vehicle
{
public:
    Car(const std::string &identifier);

    void start() override;
    void stop() override;

};

#endif // CAR_H
