#include "car.h"
#include "logger.h"

Car::Car(const std::string &identifier): Vehicle(identifier)
{

}

void Car::start()
{
    m_running = true;
    m_logger->addLine("Car was started.");
}

void Car::stop()
{
    m_running = false;
    m_logger->addLine("Car was stopped.");
}
