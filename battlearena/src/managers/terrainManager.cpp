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
    glCallList(arena->getIdListe());
}