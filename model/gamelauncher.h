#ifndef GAMELAUNCHER_H
#define GAMELAUNCHER_H


#include <vector>
#include <map>
#include <QObject>

class Game;
class Vehicle;
class VehicleTableModel;

class GameLauncher : public QObject
{
    Q_OBJECT

public:
    explicit GameLauncher(QObject * parent = 0);
    void initGame();
    bool isInitializated() {return m_initializated;}
    bool hasLicenseForVehicleByUser(const std::string &userName, Vehicle* vehicle) const;
    std::vector<Vehicle*> getVehiclesByUser(const std::string &userName) const;
    void sendModelToGuiByUser(const std::string &userName);

private:
    std::string m_userName;
    std::string m_userAge;
    bool m_carLicense;
    bool m_motorbikeLicense;
    bool m_boatLicense;
    bool m_planeLicense;
    bool m_initializated;

signals:
    void sendModelToGui(VehicleTableModel* vehicleTableModel);

private slots:
    void receiveNameFromGui(const std::string &name);
    void receiveAgeFromGui(const std::string &age);
    void receiveCarLicenseFromGui(const bool &carLicense);
    void receiveMotorbikeLicenseFromGui(const bool &motorbikeLicense);
    void receiveBoatLicenseFromGui(const bool &boatLicense);
    void receivePlaneLicenseFromGui(const bool &planeLicense);

private:
    std::map<std::string, Game*> m_games;
};

#endif // GAMELAUNCHER_H
