//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_BULLET_H
#define BATTLEARENA_BULLET_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "IDestructive.h"


class Bullet {
private:

    float velociteX;
    float velociteZ;
    float tempsExpiration;
    bool isAlive;
    Uint32 lastTime;

public:
    GLUquadric* params;
    SDL_Point position;
    float angleTir;
    ~Bullet();
    void update();
    void drawBullet();
    void initialiser(float angle);
    void atteindreCible(IDestructive destructive, int degat);
    bool estExpire();


};


#endif //BATTLEARENA_BULLET_H
