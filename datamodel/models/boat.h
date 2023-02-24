#ifndef BOAT_H
#define BOAT_H


#include "vehicle.h"

/**
 * @brief The Boat class represents the model that identifies a vehicle of boat type.
 */
class Boat: public Vehicle
{
public:
    /**
     * @brief Boat. Constructor.
     * @param identifier. Unique string used to perform queries.
     */
    Boat(const std::string &identifier);

    /**
     * @brief start. Override method that starts the engine of a boat.
     */
    void start() override;
    /**
     * @brief stop Override method that stops the engine of a boat.
     */
    void stop() override;
};

#endif // BOAT_H
