#ifndef CAR_H
#define CAR_H


#include "vehicle.h"

/**
 * @brief The Car class represents the model that identifies a vehicle of car type.
 */
class Car: public Vehicle
{
public:
    /**
     * @brief Car. Constructor.
     * @param identifier. Unique string used to perform queries.
     */
    Car(const std::string &identifier);

    /**
     * @brief start. Override method that starts the engine of a car.
     */
    void start() override;
    /**
     * @brief stop Override method that stops the engine of a car.
     */
    void stop() override;

};

#endif // CAR_H
