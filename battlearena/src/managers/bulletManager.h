//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_BULLETMANAGER_H
#define BATTLEARENA_BULLETMANAGER_H


#include "../utils/includes.h"
#include "../entities/bullet.h"

class bulletManager {
public:
    bulletManager();
    ~bulletManager();
    void update();
    void initialiser();

};


#endif //BATTLEARENA_BULLETMANAGER_H
