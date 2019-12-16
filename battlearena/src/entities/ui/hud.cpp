//
// Created by jmarierr on 2019-12-12.
//

#include "hud.h"

hud::hud(){
    idHealthTex = loadTexture("../../assets/ui/healthbar.png");
    createHealthUI();
}

hud::~hud(){
    glDeleteTextures(1, &idHealthTex);
}

void hud::draw(){
    glCallList(idList);
}

void hud::createHealthUI(){
    idList = glGenLists(1);
    glNewList(idList, GL_COMPILE);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, 1.0, 1.0, 0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        glPushMatrix();
        glBindTexture(idHealthTex, GL_TEXTURE_2D);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 1.0);   glVertex2f(0.05, 0.05);
            glTexCoord2f(1.0, 1.0); glVertex2f(0.03, 0.05);
            glTexCoord2f(1.0, 0); glVertex2f(0.3, 0.05);
            glTexCoord2f(0, 0); glVertex2f(0.05, 0.15);
        glEnd();
        glPopMatrix();

        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
    glEndList();
}