#include "planefactory.h"
#include "datamodel/models/plane.h"
#include <QString>

PlaneFactory::PlaneFactory()
{

}

Vehicle* PlaneFactory::factoryMethod()
{
    return new Plane(QString("PLANE_%1").arg(rand()).toStdString());
}
