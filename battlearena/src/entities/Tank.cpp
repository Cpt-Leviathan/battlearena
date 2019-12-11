//
// Created by jmarierr on 2019-12-09.
//

#include "Tank.h"

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
    params = gluNewQuadric();
    glTranslatef(0,0.5f,0);
    drawCube(1.5f, 0.5f, 1, 2);
    glScalef(0.666666f,2,1);
    glTranslatef(0,0.5f,0);
    drawCube(1, 0.5f, 0.5f, 1);
    glScalef(1,2,2);

    //canon
    glTranslatef(0,0.25f,0);
    glColor3f(1, 1, 0);
    glRotatef(90,0,1,0);
    gluCylinder(params,0.1f,0.1f,3,100,100);
    glRotatef(-90,0,1,0);
    glTranslatef(0,-0.75f,1);


    //roue1
    glScalef(2,0.4f,0.5f);
    gluSphere(params, 1,20,20);
    //roue2
    glTranslatef(0,0,-4);
    gluSphere(params, 1,20,20);





}