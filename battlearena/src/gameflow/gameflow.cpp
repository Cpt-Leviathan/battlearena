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
    terrain = new terrainManager();
}

void gameflow::updateFlow(){
//Nettoyer la fenetre
    glClearColor(1.f, 1.f, 1.f, 1.f);

    //pb est ici

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(5,5,5, 0, 0, 0, 0, 1, 0);
    //gestion evenement
    SDL_PollEvent(&event);
    state = SDL_GetKeyboardState(NULL);
    if (event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
    //dessin des differents objet dans la fenetre
    drawAxis(2);

    terrain->updateManager();
    //pause dans l image
    //SDL_Delay(1);
    tank->update();
    //mise a jour de l ecran
    glFlush();
    SDL_GL_SwapWindow(settings->getWin());
}

void gameflow::cleanFlow(){
    delete(settings);
    delete(state);
}

bool gameflow::getIsRunning(){
    return isRunning;
}