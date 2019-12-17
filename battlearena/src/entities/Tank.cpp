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
    glScalef(10,10,10);
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
    //#endRoues

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

    glPopMatrix();
    glPushMatrix();
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
            position.y-=velociteZ*sin((rotation*M_PI)/180.0);
            break;
        case Direction::RECULE:
            position.x-=velociteX*cos((rotation*M_PI)/180.0);
            position.y+=velociteZ*sin((rotation*M_PI)/180.0);
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
            //camera.update(rotation);
            break;
        case Direction::TOURNER_CANON_DROITE:
            rotationCanon-=vitesseRotationCanon;
            if(rotationCanon<-360.0)
                rotationCanon+=360.0;
            //camera.update(rotationCanon);
            //camera.update(rotation);
            break;
    }
    this->direction=direction;

    //drawTank();
}

void Tank::initiliser() {
    position={25,30};
    dernierePosition=position;
    params = gluNewQuadric();
    velociteX=10;
    velociteZ=10;
    vitesseRotation=4;
    vitesseRotationCanon=4;
    camera.initialiser();
    direction=Direction ::NONE;
    rotation=180;
    rotationCanon=180;
    pointDeVie=0;


}

void Tank::tirer() {
    Bullet b;
    b.position.x=position.x+30*cos((rotationCanon*M_PI)/180.0);;
    b.position.y=position.y-30*sin((rotationCanon*M_PI)/180.0);
    b.initialiser(rotationCanon);
    std::cout<<"rotationCanon "<<rotationCanon<<std::endl;
    bullet.bullets.push_back(b);

}

const SDL_Point &Tank::getPosition() const {
    return position;
}

const SDL_Point &Tank::getDernierePosition() const {
    return dernierePosition;
}

void Tank::setPosition(const SDL_Point &position) {
    Tank::position = position;
}

void Tank::setDernierePosition(const SDL_Point &dernierePosition) {
    Tank::dernierePosition = dernierePosition;
}

void Tank::recevoirDommage(int bulletDommage){
    pointDeVie-=bulletDommage;
    if (pointDeVie <= 0);
        //Die();
}
