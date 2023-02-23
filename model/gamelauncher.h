#ifndef GAMELAUNCHER_H
#define GAMELAUNCHER_H


#include <vector>
#include <map>
#include <QObject>
#include "vehicle.h"

class Game;
class VehicleTableModel;
class QStringListModel;

/**
 * @brief The GameLauncher class. This class acts a controller in the model view controller design pattern.
 */
class GameLauncher : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief GameLauncher. Constructor.
     * @param parent. This is the parent widget, it is used for Qt purposes.
     */
    explicit GameLauncher(QObject * parent = 0);
    /**
     * @brief initGame. Initializes the game creating instances of the user and vehicles by using the vehicles factories.
     */
    void initGame();
    /**
     * @brief updateState. Wrapper that updates the state of a certain vehicle.
     * @param name. User name used to get the proper information of the game list.
     * @param vehicleIdentifier. Vehicle identifier used to get the proper information of the above user.
     */
    void updateState(const std::string &name, const std::string &vehicleIdentifier);
    /**
     * @brief isInitializated. Indicates if the game has been already initialized.
     * @return. true if the game has been already initialized or false in otherwise..
     */
    bool isInitializated() {return m_initializated;}
    /**
     * @brief sendModelsToGuiByUser. Sends all the models to the main window.
     * @param userName. User name used to get the proper information of the game list.
     */
    void sendModelsToGuiByUser(const std::string &userName);

private:
    /**
     * @brief updateState. Updates the state of a certain vehicle.
     * @param name. User name used to get the proper information of the game list.
     * @param vehicle. Vehicle identifier used to get the proper information of the above user.
     * @return. true if the state of the vehicle was updated or false in otherwise.
     */
    bool updateState(const std::string &name, Vehicle* vehicle);
    /**
     * @brief sendLogsModelToGui. Sends the log models to the main window.
     * @param userName. User name used to get the proper information of the game list.
     */
    void sendLogsModelToGui(const std::string &userName);

private:
    /**
     * @brief m_userName. The user name of the driver used to create an User instance.
     */
    std::string m_userName;
    /**
     * @brief m_userAge. The user age of the driver used to create an User instance.
     */
    std::string m_userAge;
    /**
     * @brief m_carLicense. The car license flag that indicates if the driver has a car license used to create an User instance.
     */
    bool m_carLicense;
    /**
     * @brief m_motorbikeLicense. The motorbike license flag that indicates if the driver has a car license used to create an User instance.
     */
    bool m_motorbikeLicense;
    /**
     * @brief m_boatLicense. The boat license flag that indicates if the driver has a car license used to create an User instance.
     */
    bool m_boatLicense;
    /**
     * @brief m_planeLicense. The plane license flag that indicates if the driver has a car license used to create an User instance.
     */
    bool m_planeLicense;
    /**
     * @brief m_initializated. Flag that indicates if the game was initialized.
     */
    bool m_initializated;
    /**
     * @brief m_loggerList. Object that contains the log lines of the program.
     */
    QStringList m_loggerList;
    /**
     * @brief m_games. The game list with information related to user and vehicles.
     */
    std::map<std::string, Game*> m_games;

signals:
    /**
     * @brief sendModelToGui. Signal used to send the VehicleTableModel to main window of the application to show the vehicles information in the table view.
     * @param vehicleTableModel. The VehicleTableModel that implements QAbstractTableModel that handles the vehicle information.
     */
    void sendModelToGui(VehicleTableModel* vehicleTableModel);
    /**
     * @brief sendLogsModelToGui. Signal used to send the logs model to main window of the application to show the logs in the list view.
     * @param model. The logs model that handles the logs application information.
     */
    void sendLogsModelToGui(QStringListModel* model);
    /**
     * @brief sendVehiclesToGui. Signal used to send the vehicle list to main window of the application to show the vehicles information in the table widget.
     * @param vehicles. The vehicles list that handles the vehicle information.
     */
    void sendVehiclesToGui(std::vector<Vehicle*> vehicles);

private slots:
    /**
     * @brief receiveNameFromGui. Slot used to get the user name entered in the user name line edit of main window.
     * @param name
     */
    void receiveNameFromGui(const std::string &name);
    /**
     * @brief receiveAgeFromGui. Slot used to get the user age entered in the user age line edit of main window.
     * @param age
     */
    void receiveAgeFromGui(const std::string &age);
    /**
     * @brief receiveCarLicenseFromGui. Slot used to get the car license flag entered in the car license checkbox of main window.
     * @param carLicense. Boolean flag that identifies the car license.
     */
    void receiveCarLicenseFromGui(const bool &carLicense);
    /**
     * @brief receiveMotorbikeLicenseFromGui Slot used to get the motorbike license flag entered in the motorbike license checkbox of main window.
     * @param motorbikeLicense. Boolean flag that identifies the motorbike license.
     */
    void receiveMotorbikeLicenseFromGui(const bool &motorbikeLicense);
    /**
     * @brief receiveBoatLicenseFromGui Slot used to get the boat license flag entered in the boat license checkbox of main window.
     * @param boatLicense. Boolean flag that identifies the boat license.
     */
    void receiveBoatLicenseFromGui(const bool &boatLicense);
    /**
     * @brief receivePlaneLicenseFromGui Slot used to get the plane license flag entered in the plane license checkbox of main window.
     * @param planeLicense. Boolean flag that identifies the plane license.
     */
    void receivePlaneLicenseFromGui(const bool &planeLicense);

};

#endif // GAMELAUNCHER_H
