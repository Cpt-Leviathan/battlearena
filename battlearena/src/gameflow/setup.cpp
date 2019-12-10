//
// Created by jmarierr on 2019-12-09.
//

#include "setup.h"

setup::~setup()= default;
setup::setup(){}

void setup::initialize(int _width, int _height){
    terrainfile = "../../assets/terrain/1.txt";
    width = _width;
    height = _height;
    SDL_Init(SDL_INIT_EVERYTHING);

    //init fenetre en opengl
    win = SDL_CreateWindow("OpenGl Test",
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           width, height,
                           SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    context = SDL_GL_CreateContext(win);

//    SDL_GL_SetSwapInterval(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );
    gluOrtho2D(0,800,0,600);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void setup::clear(){
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

SDL_Window* setup::getWin(){
    return win;
}

const std::string &setup::getTerrainfile() const {
    return terrainfile;
}

void setup::setTerrainfile(const std::string &terrainfile) {
    setup::terrainfile = terrainfile;
}
