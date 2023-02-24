#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "datamodel/models/vehicle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GameLauncher;
class VehicleTableModel;
class QStringListModel;

/**
 * @brief The MainWindow class acts a view in the model view controller design pattern.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow. Constructor.
     * @param parent. The object used to invoke all the ascendant contructors of ascendant classes.
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * Destructor.
     */
    ~MainWindow();

private:
    /**
     * @brief m_gameLauncher. The game launcher that acts a controller in the model view controller design pattern. Used to initialize the game.
     */
    GameLauncher* m_gameLauncher;

private:
    /**
     * @brief processInformation. Performs the proper checks related to the information entered by the user and then starts the game.
     */
    void processInformation();

signals:
    /**
     * @brief sendNameToGameLauncher. Signal that sends the user name to the controller.
     * @param name. User name for the driver entered by the user.
     */
    void sendNameToGameLauncher(const std::string &name);
    /**
     * @brief sendAgeToGameLauncher. Signal that sends the user age to the controller.
     * @param age. User age for the driver entered by the user.
     */
    void sendAgeToGameLauncher(const std::string &age);
    /**
     * @brief sendCarLicenseToGameLauncher. Signal that sends the car license flag to the controller.
     * @param carLicense. Flag that indicates if the driver has a car license entered by the user.
     */
    void sendCarLicenseToGameLauncher(const bool &carLicense);
    /**
     * @brief sendMotorbikeLicenseToGameLauncher. Signal that sends the motorbike license flag to the controller.
     * @param motorbikeLicense. Flag that indicates if the driver has a motorbike license entered by the user.
     */
    void sendMotorbikeLicenseToGameLauncher(const bool &motorbikeLicense);
    /**
     * @brief sendBoatLicenseToGameLauncher. Signal that sends the boat license flag to the controller.
     * @param boatLicense. Flag that indicates if the driver has a boat license entered by the user.
     */
    void sendBoatLicenseToGameLauncher(const bool &boatLicense);
    /**
     * @brief sendPlaneLicenseToGameLauncher. Signal that sends the plane license flag to the controller.
     * @param planeLicense. Flag that indicates if the driver has a plane license entered by the user.
     */
    void sendPlaneLicenseToGameLauncher(const bool &planeLicense);

private slots:
    /**
     * @brief onUserNameLineEditTextChanged. Slot that shall be connected to the textChanged signal of the line edit related to the user name to perform an action.
     * @param arg1. The content entered by the user in the related line edit.
     */
    void onUserNameLineEditTextChanged(const QString &arg1);
    /**
     * @brief onUserAgeLineEditTextChanged. Slot that shall be connected to the textChanged signal of the line edit related to the user age to perform an action.
     * @param arg1. The content entered by the user in the related line edit.
     */
    void onUserAgeLineEditTextChanged(const QString &arg1);
    /**
     * @brief receiveModelFromGameLauncher. Slot that shall be connected to the proper controller signal that sends the vehicle table model.
     * @param vehicleTableModel. The model used to be interpreted by the proper table view to display the data.
     */
    void receiveModelFromGameLauncher(VehicleTableModel* vehicleTableModel);
    /**
     * @brief receiveLogsModelFromGameLauncher. Slot that shall be connected to the proper controller signal that sends the string list log model.
     * @param model. The model used to be interpreted by the proper table view to display the data.
     */
    void receiveLogsModelFromGameLauncher(QStringListModel* model);
    /**
     * @brief refreshVehiclesTableWidget. Slot that shall be connected to the proper controller signal that sends the vehicles list.
     * @param vehicles. The vehicles list used to be added by the proper table widget to display the data.
     */
    void refreshVehiclesTableWidget(std::vector<Vehicle*> vehicles);
    /**
     * @brief onCarLicenseCheckBoxStateChanged. Slot that shall be connected to the stateChanged signal of the check box related to the car license flag to perform an action.
     * @param arg1. The state set by the user in the related check box.
     */
    void onCarLicenseCheckBoxStateChanged(int arg1);
    /**
     * @brief onMotorcycleLicenseCheckBoxStateChanged. Slot that shall be connected to the stateChanged signal of the check box related to the motorcycle license flag to perform an action.
     * @param arg1. The state set by the user in the related check box.
     */
    void onMotorcycleLicenseCheckBoxStateChanged(int arg1);
    /**
     * @brief onBoatLicenseCheckBoxStateChanged. Slot that shall be connected to the stateChanged signal of the check box related to the boat license flag to perform an action.
     * @param arg1. The state set by the user in the related check box.
     */
    void onBoatLicenseCheckBoxStateChanged(int arg1);
    /**
     * @brief onPlaneLicenseCheckBoxStateChanged. Slot that shall be connected to the stateChanged signal of the check box related to the plane license flag to perform an action.
     * @param arg1. The state set by the user in the related check box.
     */
    void onPlaneLicenseCheckBoxStateChanged(int arg1);
    /**
     * @brief onStartGamePushButtonClicked. Slot that shall be connected to the clicked signal of the push button used to start the game.
     */
    void onStartGamePushButtonClicked();
    /**
     * @brief onChangeStatePushButtonClicked. Slot that shall be connected to the clicked signal of the push button used to start/stop the engine of the desired vehicle.
     */
    void onChangeStatePushButtonClicked();

private:
    /**
     * @brief ui. User interface object that contains all the visual components of the main window.
     */
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
