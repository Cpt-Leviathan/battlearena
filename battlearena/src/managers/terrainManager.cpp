//
// Created by jmarierr on 2019-12-10.
//

#include "terrainManager.h"

terrainManager::terrainManager(){
    arena = new terrain();
    walls=arena->getWalls();
}

terrainManager::~terrainManager(){
    delete (arena);
}

void terrainManager::updateManager(){

    glCallList(arena->getIdList());
    //drawAxis(50);
    glPushMatrix();
    glTranslatef(-arena->getWidth(), 0, -arena->getLength());
    //drawAxis(50);
    for(wall* w: *arena->getWalls()){
        glCallList(w->getIdList());
    }
    glPopMatrix();
}