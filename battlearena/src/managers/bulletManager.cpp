//
// Created by jmarierr on 2019-12-09.
//

#include "bulletManager.h"

bulletManager::bulletManager() {

}

bulletManager::~bulletManager() {

}

void bulletManager::update(terrainManager *terrain) {
    for (int i = 0; i < bullets.size(); i++) {
        int nbCollision=0;
        for(wall* w : *terrain->walls) {
            if(!((bullets[i].position.x-10>=w->x-550)||
                 (bullets[i].position.x+10<=w->x-650)||
                 bullets[i].position.y-5>=w->y-200||
                 bullets[i].position.y+5<=w->y-300)) {

                nbCollision++;

            }
        }
        if (bullets[i].estExpire()||nbCollision!=0|| !bullets[i].isAlive) {
            gluDeleteQuadric(bullets[i].params);
            bullets.erase(bullets.begin()+i);
        } else {
            bullets[i].update();
        }
    }

}

void bulletManager::initialiser() {

}
