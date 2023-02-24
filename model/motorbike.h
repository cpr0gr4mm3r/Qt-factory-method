#ifndef MOTORBIKE_H
#define MOTORBIKE_H


#include "vehicle.h"

/**
 * @brief The Motorbike class represents the model that identifies a vehicle of motorbike type.
 */
class Motorbike: public Vehicle
{
public:
    /**
     * @brief Motorbike. Constructor.
     * @param identifier. Unique string used to perform queries.
     */
    Motorbike(const std::string &identifier);

    /**
     * @brief start. Override method that starts the engine of a motorbike.
     */
    void start() override;
    /**
     * @brief stop Override method that stops the engine of a motorbike.
     */
    void stop() override;

};

#endif // MOTORBIKE_H
