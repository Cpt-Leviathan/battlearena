//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_GAMEFLOW_H
#define BATTLEARENA_GAMEFLOW_H

#include "../utils/includes.h"
#include "../managers/terrainManager.h"

class gameflow {
private:
    bool isRunning;
    SDL_Event event;
    const Uint8 *state;
    setup* settings;
    terrainManager* terrain;

public:
    gameflow();
    ~gameflow();
    void initialize(setup* _settings);
    void updateFlow();
    void cleanFlow();

    bool getIsRunning();
};


#endif //BATTLEARENA_GAMEFLOW_H
