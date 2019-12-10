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
    std::string terrainfile;
public:
    setup();
    ~setup();
    void initialize(int width, int height);
    void clear();
    const std::string &getTerrainfile() const;
    void setTerrainfile(const std::string &terrainfile);
    SDL_Window* getWin();

};


#endif //BATTLEARENA_SETUP_H
