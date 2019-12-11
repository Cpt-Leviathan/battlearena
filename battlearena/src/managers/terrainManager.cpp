//
// Created by jmarierr on 2019-12-10.
//

#include "terrainManager.h"

terrainManager::terrainManager(){
    arena = new terrain();
}

terrainManager::~terrainManager(){
    delete (arena);
}

void terrainManager::updateManager(){

    glCallList(arena->getIdList());
    drawAxis(10);
    glTranslatef(-arena->getWidth() + arena->getTileWidth() / 2, 0, -arena->getLength() + arena->getTileLength() / 2);
    drawAxis(10);
    for(wall* w: *arena->getWalls()){
        glCallList(w->getIdList());
    }
}