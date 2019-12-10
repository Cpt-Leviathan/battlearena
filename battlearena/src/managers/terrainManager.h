//
// Created by jmarierr on 2019-12-10.
//

#ifndef BATTLEARENA_TERRAINMANAGER_H
#define BATTLEARENA_TERRAINMANAGER_H

#include "../utils/includes.h"
#include "../entities/terrain.h"
class terrainManager {
private:
    terrain *arena;
public:
    terrainManager();
    ~terrainManager();
    void updateManager();
};


#endif //BATTLEARENA_TERRAINMANAGER_H
