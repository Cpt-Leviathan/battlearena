//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_TANK_H
#define BATTLEARENA_TANK_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Tank {
private:
    GLUquadric* params;
public:
    void drawCube(float x, float y, float z,int type);
    void drawTank();
};


#endif //BATTLEARENA_TANK_H
