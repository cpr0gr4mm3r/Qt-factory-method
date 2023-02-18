#ifndef LOGGER_H
#define LOGGER_H


#include <string>
#include <vector>

class Logger
{
public:
    Logger();
    addLine(const std::string &line);
    std::vector<std::string> getLines(){return m_logLines;}
    void clearLines();
private:
    std::vector<std::string> m_logLines;
};

#endif // LOGGER_H
