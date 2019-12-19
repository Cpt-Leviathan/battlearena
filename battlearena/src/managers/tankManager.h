//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_TANKMANAGER_H
#define BATTLEARENA_TANKMANAGER_H


#include "../utils/includes.h"
#include "../entities/Tank.h"
class tankManager {
private:
    //Tank *tank;

public:
    std::vector<Tank*> tankList;

    tankManager(int nbPlayers);
    ~tankManager();
    void update(Direction direction,int idTank);
    void update(int idTank);
    void update();
    void initialiser();


};


#endif //BATTLEARENA_TANKMANAGER_H
