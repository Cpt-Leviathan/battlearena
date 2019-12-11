//
// Created by jmarierr on 2019-12-09.
//

#include "Tank.h"

void Tank::drawCube(float x, float y, float z,int type){
    glScalef(x,y,z);
    if(type==1){
        glColor3f(0.8, 0.8, 0.8);
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
    glTranslatef(0,1,0);
    drawCube(3, 1, 2, 1);
    glScalef(0.33333f,1,0.5f);
    glTranslatef(0,1,0);
    drawCube(2.5, 1, 1.5, 1);


}