//
// Created by jmarierr on 2019-12-09.
//

#ifndef BATTLEARENA_SETUP_H
#define BATTLEARENA_SETUP_H

#include "../utils/includes.h"

class setup {
private:
    SDL_Window *win = nullptr;
    SDL_GLContext  context;
    std::string terrainfile;

public:
    int width = 0, height = 0;
    setup();
    ~setup();
    void initialize(int width, int height);
    void clear();
    const std::string &getTerrainfile() const;
    void setTerrainfile(const std::string &terrainfile);
    SDL_Window* getWin();

};


#endif //BATTLEARENA_SETUP_H
