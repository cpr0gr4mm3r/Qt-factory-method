#ifndef UTILITIES_H
#define UTILITIES_H

/**
 * @brief The Utilities class used to support to other classes.
 */
class Utilities
{
public:
    /**
     * @brief ageIsValid. Static method that checks if the age is a valid data.
     * @param age. The age in string format to be validate.
     */
    static ageIsValid(const QString &age)
    {
        bool ok;
        age.toInt(&ok, 10);
        return ok;
    }
};

#endif // UTILITIES_H
