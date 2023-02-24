#ifndef VEHICLE_H
#define VEHICLE_H


#include <string>

class Logger;

/**
 * @brief The Vehicle class represents the model that identifies a generic vehicle. Acts a model in the model view controller design pattern.
 */
class Vehicle
{
private:
    /**
     * @brief m_identifier. Unique string used perform queries.
     */
    std::string m_identifier;
protected:
    /**
     * @brief m_logger. The logger object used to inform to the user the vehicle operations.
     */
    Logger* m_logger;
    /**
     * @brief m_running. The flag that indicates if the vehicle is running.
     */
    bool m_running;
public:
    /**
     * @brief Car. Constructor.
     * @param identifier. Unique string used perform queries.
     */
    Vehicle(const std::string &identifier);

    /**
     * @brief getIdentifier. Accessor method to return the unique string used perform queries.
     * @return The vehicle identifier.
     */
    std::string getIdentifier() const {return m_identifier;}

    /**
     * @brief getLogger. Accessor method to return the logger object used to inform to the user the vehicle operations.
     * @return The logger instance.
     */
    Logger* getLogger() {return m_logger;}

    /**
     * @brief isRunning. Indicates if the vehicle is running.
     * @return true if the vehicle is running or false in otherwise.
     */
    bool isRunning() const {return m_running;}

    /**
     * @brief start. Pure virtual method that defines a vehicle behavior for start the engine.
     */
    virtual void start() = 0;
    /**
     * @brief stop. Pure virtual method that defines a vehicle behavior for stop the engine.
     */
    virtual void stop() = 0;
};

#endif // VEHICLE_H
