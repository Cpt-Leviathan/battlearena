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
    glClearColor(.0f, .0f, .0f, .0f);
    glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,300, 0.001f, 0, 0, 0, 0, 1, 0);
    //gestion evenement
    SDL_PollEvent(&event);
    state = SDL_GetKeyboardState(NULL);
    if (event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
    //dessin des differents objet dans la fenetre
    //drawAxis(2);
    drawAxis(10);
    terrain->updateManager();
    //pause dans l image
    //SDL_Delay(1);

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