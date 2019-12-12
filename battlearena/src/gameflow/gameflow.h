//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_GAMEFLOW_H
#define BATTLEARENA_GAMEFLOW_H

#include "../utils/includes.h"
#include "../managers/terrainManager.h"
#include "../managers/tankManager.h"
#include "flow.h"
class gameflow : flow {
private:

    terrainManager* terrain;
    tankManager* tank;

public:
    gameflow();
    ~gameflow();
    void initialize(setup* _settings) override;
    void updateFlow() override;
    void draw() override;
    void cleanFlow() override;
    bool getIsRunning() const override;
};


#endif //BATTLEARENA_GAMEFLOW_H
