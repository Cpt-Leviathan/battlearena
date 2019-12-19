//
// Created by jmarierr on 2019-12-09.
//

#include "Bullet.h"

Bullet::~Bullet() {
}

void Bullet::update() {
    if(tempsExpiration>0) {


        position.x += velociteX * cos((angleTir * M_PI) / 180.0);
        position.y -= velociteZ * sin((angleTir * M_PI) / 180.0);

    }
}

void Bullet::drawBullet() {

    glTranslatef(position.x,1,position.y);
    update();
    glRotatef(angleTir+90,0,1,0);
    glScalef(10,10,10);
    gluCylinder(params,0.2f,0.2f,1,20,20);
    glTranslatef(0,0,1);
    gluCylinder(params,.5f,0.1f,1,20,20);
    glPopMatrix();
    glPushMatrix();
    tempsExpiration--;

}

void Bullet::initialiser(float angle){
    params = gluNewQuadric();
    velociteX=10;
    velociteZ=10;
    tempsExpiration=10;
    isAlive=true;
    angleTir=angle;


}

void Bullet::atteindreCible(IDestructive *destructive, int degat) {
    destructive->recevoirDommage(degat);

}

bool Bullet::estExpire() {
    if(tempsExpiration<0)
        return true;
    else
        return false;
}

