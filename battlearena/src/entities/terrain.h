//
// Created by jmarierr on 2019-12-10.
//

#ifndef BATTLEARENA_TERRAIN_H
#define BATTLEARENA_TERRAIN_H

#include "../utils/includes.h"
#include "wall.h"
#include "ui/hud.h"

class terrain {
private:
    int width, length, tileWidth, tileLength;
    GLuint idList;
    GLuint idGroundTex, idWallTex;
    //int divisionsX, divisionsZ;  //nombre de divisions pour les murs sur les axes x et z
    std::vector<wall*>* walls;

public:
    hud* h;
    terrain();
    ~terrain();
    void readFile(std::string path);
    void createTerrain();
    GLuint getIdList() const;
    std::vector<wall *> *getWalls() const;

    int getWidth() const;

    int getLength() const;

    int getTileWidth() const;

    int getTileLength() const;
};


#endif //BATTLEARENA_TERRAIN_H
