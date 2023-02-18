#include "logger.h"
#include <iostream>

using namespace std;

Logger::Logger()
{

}

Logger::addLine(const std::string &line)
{
    cout << line << endl;
    m_logLines.push_back(line);
}

void Logger::clearLines()
{
    m_logLines.clear();
}
