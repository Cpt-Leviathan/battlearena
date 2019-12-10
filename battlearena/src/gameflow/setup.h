//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_SETUP_H
#define BATTLEARENA_SETUP_H

#include "../utils/includes.h"

class setup {
private:
    SDL_Window *win;
    SDL_GLContext  context;
    int width, height;
public:
    setup();
    ~setup();
    void initialize(int width, int height);
    void clear();
    SDL_Window* getWin();
};


#endif //BATTLEARENA_SETUP_H
