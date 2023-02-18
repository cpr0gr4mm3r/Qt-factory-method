#ifndef GAME_H
#define GAME_H


#include <vector>

class User;
class VehicleFactory;

class Game
{
private:
    User* m_user;
    std::vector<VehicleFactory*> m_vehicleFactories;
public:
    Game(std::vector<VehicleFactory*> vehicleFactories);
    void startGameLogic();

    User* getUser();
};

#endif // GAME_H
