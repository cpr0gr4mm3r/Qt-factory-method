#ifndef MARBLEVIRTUALGLOBE_H
#define MARBLEVIRTUALGLOBE_H

#include <QWidget>
#include <marble/MarbleWidget.h>

/**
 * @brief The MarbleVirtualGlobe class acts a display on Marble geographic open source project, developed by KDE.
 */
class MarbleVirtualGlobe: public Marble::MarbleWidget
{
    Q_OBJECT

public:
    /**
     * @brief MarbleVirtualGlobe. Constructor.
     * @param parent. The object used to invoke all the ascendant contructors of ascendant classes.
     */
    MarbleVirtualGlobe(QWidget* parent);

    /**
     * @brief m_longitude. The user longitude of the driver used to center on the virtual globe.
     */
    double m_longitude;

    /**
     * @brief m_latitude. The user latitude of the driver used to center on the virtual globe.
     */
    double m_latitude;

    /**
     * @brief m_altitude. The user altitude of the driver used to center on the virtual globe.
     */
    double m_altitude;

private slots:
    /**
     * @brief switchToProjection. Slot that shall be connected to the currentIndexChanged signal of the combo box related to the marble projection.
     * @param index. Index that represents the projection (Spherical or Mercator).
     */
    void switchToProjection(int index);
    /**
     * @brief receiveLongitudeFromGui. Slot used to get the user longitude entered in the user longitude line edit of main window.
     */
    void receiveLongitudeFromGui(const QString &);
    /**
     * @brief receiveLatitudeFromGui. Slot used to get the user latitude entered in the user latitude line edit of main window.
     */
    void receiveLatitudeFromGui(const QString &);
    /**
     * @brief receiveAltitudeFromGui. Slot used to get the user altitude entered in the user altitude line edit of main window.
     */
    void receiveAltitudeFromGui(const QString &);
    /**
     * @brief updatePosition. Slot used to center the virtual globe in the desired (longitude, latitude, altitude) position.
     */
    void updatePosition();
};

#endif // MARBLEVIRTUALGLOBE_H
