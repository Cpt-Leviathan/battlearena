//
// Created by jmarierr on 2019-12-10.
//

#include "wall.h"

wall::wall(int x, int y, int width, int length, GLuint texture) : x(x), y(y), width(width), length(length), idTexture(texture){
    height = 20;
}
wall::~wall(){
    glDeleteTextures(1, &idTexture);
    glDeleteLists(idList, 1);
}

void wall::createWall(){
    idList = glGenLists(1);
    width *= 2;
    length *= 2;
    glNewList(idList, GL_COMPILE);
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, idTexture);
        glTranslated(x, 0, y);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);glVertex3d(0, 0, 0);
            glTexCoord2f(1, 0);glVertex3d(0, 0, length);
            glTexCoord2f(1, 1);glVertex3d(width, 0, length);
            glTexCoord2f(0, 1);glVertex3d(width, 0, 0);

            glTexCoord2f(0, 0);glVertex3d(0, 0, 0);
            glTexCoord2f(1, 0);glVertex3d(0, 0, length);
            glTexCoord2f(1, 1);glVertex3d(0, height, length);
            glTexCoord2f(0, 1);glVertex3d(0, height, 0);

            glTexCoord2f(0, 0);glVertex3d(0, 0, 0);
            glTexCoord2f(1, 0);glVertex3d(0, height, 0);
            glTexCoord2f(1, 1);glVertex3d(width, height, 0);
            glTexCoord2f(0, 1);glVertex3d(width, 0, 0);

            glTexCoord2f(0, 0);glVertex3d(width, 0, 0);
            glTexCoord2f(1, 0);glVertex3d(width, height, 0);
            glTexCoord2f(1, 1);glVertex3d(width, height, length);
            glTexCoord2f(0, 1);glVertex3d(width, 0, length);

            glTexCoord2f(0, 0);glVertex3d(width, 0, length);
            glTexCoord2f(1, 0);glVertex3d(width, height, length);
            glTexCoord2f(1, 1);glVertex3d(0, height, length);
            glTexCoord2f(0, 1);glVertex3d(0, 0, length);

            glTexCoord2f(0, 0);glVertex3d(0, height, length);
            glTexCoord2f(1, 0);glVertex3d(width, height, length);
            glTexCoord2f(1, 1);glVertex3d(width, height, 0);
            glTexCoord2f(0, 1);glVertex3d(0, height, 0);
        glEnd();
        glPopMatrix();
    glEndList();
}
