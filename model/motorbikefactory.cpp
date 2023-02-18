#include "motorbikefactory.h"
#include "motorbike.h"
#include <QString>

MotorbikeFactory::MotorbikeFactory()
{

}

Vehicle* MotorbikeFactory::factoryMethod()
{
    return new Motorbike(QString("MOTORBIKE_%1").arg(rand()).toStdString());

}
