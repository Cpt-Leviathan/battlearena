//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_TANKMANAGER_H
#define BATTLEARENA_TANKMANAGER_H


#include "../utils/includes.h"
#include "../entities/Tank.h"
class tankManager {
private:
    Tank *tank;
    std::vector<Tank*>* tankList;
public:
    tankManager();
    ~tankManager();
    void update();
};


#endif //BATTLEARENA_TANKMANAGER_H
