#ifndef PLANE_H
#define PLANE_H


#include "vehicle.h"

/**
 * @brief The Plane class represents the model that identifies a vehicle of plane type.
 */
class Plane: public Vehicle
{
public:
    /**
     * @brief Plane. Constructor.
     * @param identifier. Unique string used to perform queries.
     */
    Plane(const std::string &identifier);

    /**
     * @brief start. Override method that starts the engine of a plane.
     */
    void start() override;
    /**
     * @brief stop Override method that stops the engine of a plane.
     */
    void stop() override;

};

#endif // PLANE_H
