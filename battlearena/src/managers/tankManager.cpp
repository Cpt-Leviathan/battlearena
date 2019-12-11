//
// Created by jmarierr on 2019-12-09.
//

#include "tankManager.h"

tankManager::tankManager() {
    tank=new Tank();
}

tankManager::~tankManager() {
    delete tank;
}

void tankManager::update() {
    tank->drawTank();
}
