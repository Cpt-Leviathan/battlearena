//
// Created by jmarierr on 2019-12-09.
//

#include "gameflow.h"

gameflow::gameflow(){

}

gameflow::~gameflow(){

}

void gameflow::initialize(setup* _settings){
    isRunning = true;
    settings = _settings;
    terrain = new terrainManager();
}

void gameflow::updateFlow(){
    clearWindow();

    gluLookAt(0,700, 0.001f, 0, 0, 0, 0, 1, 0);

    manageEvents();

    draw();

    pauseFrame();

    updateWindow();
}

void gameflow::draw(){
    terrain->updateManager();
    //tank->update();
}

void gameflow::cleanFlow(){
    delete(settings);
    delete(state);
}

bool gameflow::getIsRunning() const{
    return isRunning;
}