//
// Created by jmarierr on 2019-12-12.
//

#ifndef BATTLEARENA_HUD_H
#define BATTLEARENA_HUD_H

#include "../../utils/includes.h"

class hud {
private:
    GLuint idHealthTex;
    GLuint idList;
public:
    hud();
    ~hud();
    void draw();
    void createHealthUI();
};


#endif //BATTLEARENA_HUD_H
