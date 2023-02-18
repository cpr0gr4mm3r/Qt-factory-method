#ifndef PLANE_H
#define PLANE_H


#include "vehicle.h"

class Plane: public Vehicle
{
public:
    Plane(const std::string &identifier);

    void start() override;
    void stop() override;

};

#endif // PLANE_H
