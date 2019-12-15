//
// Created by jmarierr on 2019-12-09.
//

#include "bulletManager.h"

bulletManager::bulletManager() {

}

bulletManager::~bulletManager() {

}

void bulletManager::update() {
    for (int i = 0; i < bullets.size(); i++) {

        if (bullets[i].estExpire()) {
            gluDeleteQuadric(bullets[i].params);
            bullets.erase(bullets.begin()+i);
        } else {
            bullets[i].update();
        }
    }

}

void bulletManager::initialiser() {

}
