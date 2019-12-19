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
#include <SDL2/SDL_mixer.h>

class Tank:public IDestructive {
private:
    GLUquadric* params;
    float velociteX;
    float velociteZ;
    float rotation;
    float rotationCanon;
    float vitesseRotationCanon;
    float vitesseRotation;
    SDL_Point position;
    SDL_Point dernierePosition;
    //SDL_Point possitionTir;
    int pointDeVie;
    Mix_Music *music = nullptr;
    int id;


public:
    bool isAlive;
    Direction direction;
    CameraManager camera;
    bulletManager bullet;
    Tank(int id);
    const SDL_Point &getPosition() const;

    void drawCube(float x, float y, float z,int type);
    void drawTank();
    ~Tank();
    void deplacer(Direction direction);
    void initiliser();
    void tirer();
    void recevoirDommage(int bulletDommage) override;

    const SDL_Point &getDernierePosition() const;

    void setPosition(const SDL_Point &position);

    void setDernierePosition(const SDL_Point &dernierePosition);

    int getId() const;

    void setId(int id);
};


#endif //BATTLEARENA_TANK_H
