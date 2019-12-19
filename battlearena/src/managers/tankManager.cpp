//
// Created by jmarierr on 2019-12-09.
//

#include "tankManager.h"

tankManager::tankManager(int nbPlayers) {
    for (int i = 0; i < nbPlayers; i++) {
        tankList.push_back(new Tank(i));
    }


}

tankManager::~tankManager() {
    for(auto t : tankList){
        delete t;
    }
    tankList.clear();

}

void tankManager::update(Direction direction, int idTank) {
    tankList[idTank]->deplacer(direction);

}

void tankManager::update(int idTank) {
    tankList[idTank]->tirer();
}

void tankManager::update() {
    for (Tank* t : tankList) {
        if(!t->isAlive)
            tankList.erase(tankList.begin()+t->getId());
    }

}

void tankManager::initialiser() {
    for (Tank* t : tankList) {
        t->initiliser();
    }

}


