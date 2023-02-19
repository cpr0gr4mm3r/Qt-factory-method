#ifndef GAMELAUNCHER_H
#define GAMELAUNCHER_H


#include <vector>
#include <QObject>

class Game;
class Vehicle;

class GameLauncher : public QObject
{
    Q_OBJECT

public:
    explicit GameLauncher(QObject * parent = 0);
    std::vector<Vehicle*> getVehicles();

private:
    std::string m_userName;
    std::string m_userAge;

private slots:
    void receive_name_from_gui(std::string name);
    void receive_age_from_gui(std::string age);

private:
    Game* m_game;
};

#endif // GAMELAUNCHER_H
