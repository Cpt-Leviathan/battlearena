//
// Created by jmarierr on 2019-12-09.
//

#include "Tank.h"

Tank::~Tank() {
    gluDeleteQuadric(params);
}

void Tank::drawCube(float x, float y, float z,int type){
    glScalef(x,y,z);
    if(type==1){
        glColor3f(1, 0, 0);
    }
    else if(type==2){
        glColor3f(0.1, 0, 0.1);
    }
    glBegin(GL_QUADS);

    if (type==0) {
        glColor3f(1, 0, 0);
    }
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);

    //cyan
    if (type==0) {
        glColor3f(0, 1, 1);
    }
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    //vert
    if (type==0) {
        glColor3f(0, 1, 0);
    }
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);



    //blue
    if (type==0) {
        glColor3f(0, 0, 1);
    }
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);

    //violet
    if (type==0) {
        glColor3f(1, 0, 1);
    }
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);


    //jaune
    if (type==0) {
        glColor3f(1, 1, 0);
    }
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1);

    glEnd();

}

void Tank::drawTank(){
    glPopMatrix();
    glPushMatrix();

    glTranslatef(position.x, 0, position.y);
    glRotatef(rotation,0,1,0);
    glTranslatef(0,0.5f,0);
    drawCube(1.5f, 0.5f, 1, 2);
    glScalef(0.666666f,2,1);

    //roues
    glColor3f(1, 1, 0);
    glTranslatef(0,0,1);
    //roue1
    glScalef(2,0.4f,0.5f);
    gluSphere(params, 1,20,20);
    //roue2
    glTranslatef(0,0,-4);
    gluSphere(params, 1,20,20);
    glScalef(0.5f,2.5f,2);
    //#endroues

    glTranslatef(0,0,1);
    glRotatef(-rotation,0,1,0);

    glTranslatef(0,0.5f,0);
    glRotatef(rotationCanon,0,1,0);
    drawCube(1, 0.5f, 0.5f, 1);
    glScalef(1,2,2);



    //canon
    glTranslatef(0,0.25f,0);
    glColor3f(1, 1, 0);
    glRotatef(90,0,1,0);
    gluCylinder(params,0.1f,0.1f,3,100,100);
    glRotatef(-90,0,1,0);
    glTranslatef(0,-0.75f,1);
    glRotatef(-rotationCanon,0,1,0);

    //roue1
    //glScalef(2,0.4f,0.5f);
    //gluSphere(params, 1,20,20);
    //roue2
    //glTranslatef(0,0,-4);
    //gluSphere(params, 1,20,20);

}

void Tank::deplacer(Direction direction) {
    switch (direction){
        case Direction::AVANCE:
            position.x+=velociteX*cos((rotation*M_PI)/180.0);
            position.y+=velociteZ*sin((rotation*M_PI)/180.0);
            break;
        case Direction::RECULE:
            position.x-=velociteX*cos((rotation*M_PI)/180.0);
            position.y-=velociteZ*sin((rotation*M_PI)/180.0);
            break;
        case Direction::TOURNER_GAUCHE:
            rotation+=vitesseRotation;
            if(rotation>360.0)
                rotation-=360.0;
            //camera.update(rotationCanon);
            camera.update(rotation);

            break;
        case Direction::TOURNER_DROITE:
            rotation-=vitesseRotation;
            if(rotation<-360.0)
                rotation+=360.0;
            //camera.update(rotationCanon);
            camera.update(rotation);
            break;
        case Direction::TOURNER_CANON_GAUCHE:
            rotationCanon+=vitesseRotationCanon;
            if(rotationCanon>360.0)
                rotationCanon-=360.0;
            //camera.update(rotationCanon);
            camera.update(rotation);
            break;
        case Direction::TOURNER_CANON_DROITE:
            rotationCanon-=vitesseRotationCanon;
            if(rotationCanon<-360.0)
                rotationCanon+=360.0;
            //camera.update(rotationCanon);
            camera.update(rotation);
            break;
    }

    //drawTank();
}

void Tank::initiliser() {
    params = gluNewQuadric();
    position={25,10};
    velociteX=3;
    velociteZ=3;
    vitesseRotation=4;
    vitesseRotationCanon=4;
    camera.initialiser();
    direction=Direction ::AVANCE;
    rotation=0;
    rotationCanon=0;
    pointDeVie=0;


}

const SDL_Point &Tank::getPosition() const {
    return position;
}

