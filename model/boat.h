#ifndef BOAT_H
#define BOAT_H


#include "vehicle.h"

class Boat: public Vehicle
{
public:
    Boat(const std::string &identifier);

    void start() override;
    void stop() override;
};

#endif // BOAT_H
