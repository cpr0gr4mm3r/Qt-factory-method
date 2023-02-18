#include "motorbike.h"
#include "logger.h"

Motorbike::Motorbike(const std::string &identifier): Vehicle(identifier)
{

}

void Motorbike::start()
{
    m_running = true;
    m_logger->addLine("Motorbike was started.");
}

void Motorbike::stop()
{
    m_running = false;
    m_logger->addLine("Motorbike was stopped.");
}
