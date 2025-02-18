//
// Created by jmarierr on 2019-12-09.
//

#include "setup.h"
setup::~setup()= default;
setup::setup(){}

void setup::initialize(int _width, int _height){
   // terrainfile = "../../assets/terrain/1.txt";

    width = _width;
    height = _height;

    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_Init(MIX_INIT_MP3);
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK);
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);

    if(SDL_NumJoysticks()>=1){
        std::cout<<"manette connectée"<<std::endl;
        SDL_Joystick *joystick=SDL_JoystickOpen(0);

        std::cout<<"joystick name: "<<SDL_JoystickName(0)<<std::endl;
        std::cout<<"num axe: "<<SDL_JoystickNumAxes(joystick)<<std::endl;
        std::cout<<"num button: "<<SDL_JoystickNumButtons(joystick)<<std::endl;
        std::cout<<"num balls: "<<SDL_JoystickNumBalls(joystick)<<std::endl;
        std::cout<<"num hats: "<<SDL_JoystickNumHats(joystick)<<std::endl;
    }
    //init fenetre en opengl
    win = SDL_CreateWindow("Battle Arena",
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           width, height,
                           SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    context = SDL_GL_CreateContext(win);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
//    SDL_GL_SetSwapInterval(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );
    gluPerspective(70, (double) 800.0 / 600.0, 1, 1000);

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
