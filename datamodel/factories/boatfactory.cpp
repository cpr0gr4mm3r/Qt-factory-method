#include "boatfactory.h"
#include "datamodel/models/boat.h"
#include <QString>

BoatFactory::BoatFactory()
{

}

Vehicle* BoatFactory::factoryMethod()
{
    return new Boat(QString("BOAT_%1").arg(rand()).toStdString());
}
