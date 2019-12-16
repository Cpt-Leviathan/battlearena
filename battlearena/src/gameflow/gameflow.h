//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_GAMEFLOW_H
#define BATTLEARENA_GAMEFLOW_H

#include "../utils/includes.h"
#include "../managers/terrainManager.h"
#include "../managers/tankManager.h"
#include "flow.h"

class gameflow : public flow {
private:
    terrainManager* terrain;
    tankManager* tank;
    int nbPlayers, screenWidth, screenHeight;
//    std::vector<void (*)(GLint x, GLint y, GLsizei width, GLsizei height)> setViewport; //list of viewport to be used in the loop and draw each players view
    GLsizei vpWidth, vpHeight; // size of viewport width/height
    int x1, x2, y1, y2; //test
    int f = 0;
public:
    gameflow(int nbPlayers, int screenWidth, int screenHeight);
    ~gameflow();
    void initialize(setup* _settings) override;
    void manageEvents() override;
    void updateFlow() override;
    void draw() override;
    void clearFlow() override;
    bool getIsRunning() const override;
};


#endif //BATTLEARENA_GAMEFLOW_H
