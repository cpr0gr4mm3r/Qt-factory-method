#ifndef VEHICLE_H
#define VEHICLE_H


#include <string>

class Logger;

class Vehicle
{
private:
    std::string m_identifier;
protected:
    Logger* m_logger;
    bool m_running;
public:
    Vehicle(const std::string &identifier);

    std::string getIdentifier() const {return m_identifier;}
    void setIdentifier(const std::string &identifier) {m_identifier = identifier;}

    Logger* getLogger() {return m_logger;}

    bool isRunning() const {return m_running;}

    virtual void start() = 0;
    virtual void stop() = 0;
};

#endif // VEHICLE_H
