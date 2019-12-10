//
// Created by jmarierr on 2019-12-10.
//

#include "terrain.h"

terrain::terrain(){
    tileWidth = tileLength = 50;
    idGroundTex = loadTexture("../assets/terrain/sand.jpg");
    idWallTex = loadTexture("../assets/terrain/rock.jpg");
    readFile("../assets/terrain/1.txt");
    createTerrain();
}

terrain::~terrain(){
    glDeleteTextures(1,&idGroundTex);
    glDeleteTextures(1,&idWallTex);
    glDeleteLists(idListe, 1);
}
void terrain::readFile(std::string path){
    std::ifstream infile;
    infile.open(path);
    if (!infile) {
        std::cout << "Unable to open file datafile.txt";
    }
    else {
        std::string line;
        int nbLine = 0;
        std::getline(infile, line);
        while (std::getline(infile, line)) {
            width = tileWidth * line.size();
            nbLine++;
        }
        width = line.size() * tileWidth;
        length = nbLine * tileLength;

        infile.close();
    }
}

void terrain::createTerrain(){
    idListe = glGenLists(1);
    glNewList(idListe, GL_COMPILE);
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, idGroundTex);
        glBegin(GL_QUADS);
            glVertex3d(-width / 2, 0, -length / 2);
            glVertex3d(width / 2, 0, -length / 2);
            glVertex3d(width / 2, 0, length / 2);
            glVertex3d(-width / 2, 0, length / 2);
        glEnd();
        glPopMatrix();
    glEndList();
}

GLuint terrain::getIdListe() const {
    return idListe;
}
