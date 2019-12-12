//
// Created by jmarierr on 2019-12-10.
//

#include "terrain.h"
#include "../gameflow/gamesetup.h"

terrain::terrain(){
    tileWidth = tileLength = 50;
    walls = new std::vector<wall*>();
    idGroundTex = loadTexture("../assets/sand.jpg");

    idWallTex = loadTexture("../assets/rock.jpg");
    readFile(gamesetup::mapFile);
    createTerrain();
}

terrain::~terrain(){
    for(wall* w: *walls){
        delete(w);
    }
    glDeleteTextures(1,&idGroundTex);
    glDeleteLists(idList, 1);
}
void terrain::readFile(const std::string path) {
    std::ifstream infile;

    infile.open(path);
    //compte le nombre de rangee se trouve dans le fichier pour pouvoir utiliser Length plus tard
    if (infile) {
        std::string line;
        int nbLine = 0;
        while (std::getline(infile, line)) {
            nbLine++;
        }
        length = nbLine * tileLength;
        infile.close();
    }

    infile.open(path);
    if (!infile) {
        std::cout << "Unable to open file datafile.txt";
    }
    //lire le fichier txt et creer un mur dependement de ce que contient le fichier
    else {
        std::string line;
        int nbLine = 0;
            while (std::getline(infile, line)) {
            width = tileWidth * line.size();
            for(int i = 0; i < line.size(); i++){
                if(line[i] == '1'){
                    walls->push_back(new wall(tileWidth * 2 * i, tileLength * 2 * nbLine, tileWidth, tileLength, idWallTex));
                }
            }
            nbLine++;
        }
        infile.close();
    }
}

void terrain::createTerrain(){
    idList = glGenLists(1);
    glNewList(idList, GL_COMPILE);
        glPushMatrix();
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, idGroundTex);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);glVertex3d(-width, 0, -length);
            glTexCoord2f(0, 50);glVertex3d(width, 0, -length);
            glTexCoord2f(50, 50);glVertex3d(width, 0, length);
            glTexCoord2f(50, 0);glVertex3d(-width, 0, length);
        glEnd();
        glPopMatrix();
    glEndList();

    //glTranslatef(width - tileWidth/2, 0, -length + tileLength / 2);
    for(wall* w : *walls){
        w->createWall();
    }

}

GLuint terrain::getIdList() const {
    return idList;
}

std::vector<wall*> *terrain::getWalls() const {
    return walls;
}

int terrain::getWidth() const {
    return width;
}

int terrain::getLength() const {
    return length;
}

int terrain::getTileWidth() const {
    return tileWidth;
}

int terrain::getTileLength() const {
    return tileLength;
}
