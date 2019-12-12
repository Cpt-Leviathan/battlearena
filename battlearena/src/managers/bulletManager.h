//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_BULLETMANAGER_H
#define BATTLEARENA_BULLETMANAGER_H


#include "../utils/includes.h"
#include "../entities/Bullet.h"
#include <vector>

class bulletManager {
private:

public:
    std::vector<Bullet> bullets;
    bulletManager();
    ~bulletManager();
    void update();
    void initialiser();

};


#endif //BATTLEARENA_BULLETMANAGER_H
