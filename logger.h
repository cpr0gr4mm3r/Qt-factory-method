#ifndef LOGGER_H
#define LOGGER_H


#include <string>
#include <vector>

/**
 * @brief The Logger class is used to trace the events that the program performs.
 */
class Logger
{
public:
    /**
     * @brief Logger. Constructor.
     */
    Logger();
    /**
     * @brief addLine. Adds a new entry log.
     * @param line. The line that will be added in the log.
     */
    addLine(const std::string &line);
    /**
     * @brief getLines. Accessor method that returns the log lines.
     * @return The log lines to be used for a external class.
     */
    std::vector<std::string> getLines(){return m_logLines;}
    /**
     * @brief clearLines. Removes all the log entries.
     */
    void clearLines();
private:
    /**
     * @brief m_logLines. Log entries list.
     */
    std::vector<std::string> m_logLines;
};

#endif // LOGGER_H
