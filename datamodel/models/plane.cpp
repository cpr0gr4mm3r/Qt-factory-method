#include "plane.h"
#include "logger.h"

Plane::Plane(const std::string &identifier): Vehicle(identifier)
{

}

void Plane::start()
{
    m_running = true;
    m_logger->addLine("Plane was started.");
}

void Plane::stop()
{
    m_running = false;
    m_logger->addLine("Plane was stopped.");
}
