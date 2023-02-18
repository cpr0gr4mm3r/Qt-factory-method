#ifndef UTILITIES_H
#define UTILITIES_H

class Utilities
{
public:
    static ageIsValid(const QString &age)
    {
        bool ok;
        age.toInt(&ok, 10);
        return ok;
    }
};

#endif // UTILITIES_H
