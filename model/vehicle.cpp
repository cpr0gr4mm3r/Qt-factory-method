#include "vehicle.h"
#include "logger.h"

Vehicle::Vehicle(const std::string &identifier): m_identifier(identifier)
{
    m_logger = new Logger();
    m_logger->addLine("Vehicle with identifier " + identifier + " was created.");
}
