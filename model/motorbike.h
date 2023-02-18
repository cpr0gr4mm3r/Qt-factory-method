#ifndef MOTORBIKE_H
#define MOTORBIKE_H


#include "vehicle.h"

class Motorbike: public Vehicle
{
public:
    Motorbike(const std::string &identifier);

    void start() override;
    void stop() override;

};

#endif // MOTORBIKE_H
