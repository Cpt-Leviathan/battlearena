//
// Created by jmarierr on 2019-12-09.
//

#include "gameflow.h"

gameflow::gameflow(){

}

gameflow::~gameflow(){

}

void gameflow::initialize(setup* _settings){
    isRunning = true;
    settings = _settings;
}

void gameflow::updateFlow(){
//Nettoyer la fenetre
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);


    //gestion evenement
    SDL_PollEvent(&event);
    state = SDL_GetKeyboardState(NULL);
    if (event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
    //dessin des differents objet dans la fenetre

    //pause dans l image
    SDL_Delay(1);
    //mise a jour de l ecran

    glFlush();
    SDL_GL_SwapWindow(settings->getWin());
}

void gameflow::cleanFlow(){

}

bool gameflow::getIsRunning(){
    return isRunning;
}