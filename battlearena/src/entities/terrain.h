//
// Created by jmarierr on 2019-12-10.
//

#ifndef BATTLEARENA_TERRAIN_H
#define BATTLEARENA_TERRAIN_H

#include "../utils/includes.h"
#include "wall.h"
class terrain {
private:
    double width, length, tileWidth, tileLength;
    GLuint idListe;
    GLuint idGroundTex, idWallTex;
    int divisionsX, divisionsZ;  //nombre de divisions pour les murs sur les axes x et z
    std::vector<GLuint>* walls;
public:
    terrain();
    ~terrain();
    void readFile(std::string path);
    void createTerrain();
    GLuint getIdListe() const;
};


#endif //BATTLEARENA_TERRAIN_H
