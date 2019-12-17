//
// Created by jmarierr on 2019-12-10.
//

#ifndef BATTLEARENA_WALL_H
#define BATTLEARENA_WALL_H
#include "../utils/includes.h"

class wall {
private:
    int width, length, height;
    GLuint idTexture;
    GLuint idList;
public:
    int x, y;
    wall(int x, int y, int width, int length, GLuint texture);
    ~wall();
    void createWall();      //Trump made that function
    GLuint getIdTexture() const {
        return idTexture;
    }
    GLuint getIdList() const {
        return idList;
    }


};


#endif //BATTLEARENA_WALL_H
