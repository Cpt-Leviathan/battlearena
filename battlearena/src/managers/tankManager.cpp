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

void tankManager::update(Direction direction) {
    tank->deplacer(direction);
}

void tankManager::update() {
    tank->tirer();
}

void tankManager::initialiser() {
    tank->initiliser();
}

Tank *tankManager::getTank() const {
    return tank;
}
