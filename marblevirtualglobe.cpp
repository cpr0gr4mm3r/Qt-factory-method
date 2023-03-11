#include "marblevirtualglobe.h"
#include <marble/MarbleDirs.h>

using namespace Marble;

MarbleVirtualGlobe::MarbleVirtualGlobe(QWidget* parent)
{
    MarbleDirs::setMarbleDataPath(QString("C:%1Program Files (x86)%1marble%1data").arg(QDir::separator()));
    MarbleDirs::setMarblePluginPath(QString("C:%1Program Files (x86)%1marble%1plugins").arg(QDir::separator()));
    zoomView(500);
    setProjection(Marble::Spherical);
    setMapThemeId("earth/openstreetmap/openstreetmap.dgml");

    setWindowTitle("Hello Marble!");
}

void MarbleVirtualGlobe::switchToProjection(int index)
{
    setProjection(index);
}

void MarbleVirtualGlobe::receiveLongitudeFromGui(const QString &longitude)
{
    m_longitude = longitude.toDouble();
}

void MarbleVirtualGlobe::receiveLatitudeFromGui(const QString &latitude)
{
    m_latitude = latitude.toDouble();
}

void MarbleVirtualGlobe::receiveAltitudeFromGui(const QString &altitude)
{
    m_altitude = altitude.toDouble();
}

void MarbleVirtualGlobe::updatePosition()
{
    centerOn(GeoDataCoordinates(m_longitude, m_latitude, m_altitude, GeoDataCoordinates::Degree));
    zoomView(3000);
}
