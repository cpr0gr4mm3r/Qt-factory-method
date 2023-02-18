#ifndef GAMELAUNCHER_H
#define GAMELAUNCHER_H


#include <vector>

class Game;
class Vehicle;

class GameLauncher
{
public:
    GameLauncher();

    std::vector<Vehicle*> getVehicles();
private:
    Game* m_game;
};

#endif // GAMELAUNCHER_H
