#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GameLauncher;
class VehicleTableModel;
class Vehicle;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    GameLauncher* m_gameLauncher;
    QStringListModel* m_model;
    QStringList m_list;

private:
    std::vector<Vehicle*> getVehiclesByCurrentUser();
    void addLogs();
    void refreshTable();
    void processInformation();
    void updateState(Vehicle* vehicle);

signals:
    void sendNameToGameLauncher(const std::string &name);
    void sendAgeToGameLauncher(const std::string &age);
    void sendCarLicenseToGameLauncher(const bool &carLicense);
    void sendMotorbikeLicenseToGameLauncher(const bool &motorbikeLicense);
    void sendBoatLicenseToGameLauncher(const bool &boatLicense);
    void sendPlaneLicenseToGameLauncher(const bool &planeLicense);

private slots:
    void onUserNameLineEditTextChanged(const QString &arg1);
    void onUserAgeLineEditTextChanged(const QString &arg1);
    void receiveModelFromGameLauncher(VehicleTableModel* vehicleTableModel);
    void onCarLicenseCheckBoxStateChanged(int arg1);
    void onMotorcycleLicenseCheckBoxStateChanged(int arg1);
    void onBoatLicenseCheckBoxStateChanged(int arg1);
    void onPlaneLicenseCheckBoxStateChanged(int arg1);
    void onStartGamePushButtonClicked();
    void onChangeStatePushButtonClicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
