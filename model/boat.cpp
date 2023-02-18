#include "boat.h"
#include "logger.h"

Boat::Boat(const std::string &identifier): Vehicle(identifier)
{

}

void Boat::start()
{
    m_running = true;
    m_logger->addLine("Boat was started.");
}

void Boat::stop()
{
    m_running = false;
    m_logger->addLine("Boat was stopped.");
}
