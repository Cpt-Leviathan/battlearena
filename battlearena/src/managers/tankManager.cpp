//
// Created by jmarierr on 2019-12-09.
//

#include "tankManager.h"

tankManager::tankManager() {
    tank=new Tank();

}

tankManager::~tankManager() {
    for(auto t : *tankList){
        delete t;
    }
    tankList->clear();
    delete tankList;
    delete tank;
}

void tankManager::update() {
    tank->drawTank();
}
