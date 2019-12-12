//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_TANK_H
#define BATTLEARENA_TANK_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Direction.h"
#include "../managers/bulletManager.h"
#include "../managers/CameraManager.h"
#include "IDestructive.h"
#include <vector>
#include <math.h>

class Tank:IDestructive {
private:
    GLUquadric* params;
    Direction direction;
    float velociteX;
    float velociteZ;
    float rotation;
    float rotationCanon;
    float vitesseRotationCanon;
    float vitesseRotation;
    SDL_Point position;
    //SDL_Point possitionTir;
    int pointDeVie;



public:
    CameraManager camera;
    bulletManager bullet;

    const SDL_Point &getPosition() const;

    void drawCube(float x, float y, float z,int type);
    void drawTank();
    ~Tank();
    void deplacer(Direction direction);
    void initiliser();
    void tirer();
    void recevoirDommage(int bulletDommage) override;
};


#endif //BATTLEARENA_TANK_H
