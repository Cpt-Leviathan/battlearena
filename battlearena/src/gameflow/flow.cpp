//
// Created by jmarierr on 2019-12-11.
//

#include "flow.h"

flow::flow(){

}

flow::~flow(){

}
void flow::initialize(setup* _settings){

}

void flow::updateFlow(){

}

void flow::clearWindow(){
    glClearColor(.0f, .0f, .0f, .0f);
    glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);

    glClearColor(1.f, 1.f, 1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
}

void flow::manageEvents(){
    SDL_PollEvent(&event);
    state = SDL_GetKeyboardState(NULL);
    if (event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
}

void flow::draw(){

}

void flow::pauseFrame() {
    //SDL_Delay(1);
}

void flow::updateWindow(){
    glFlush();
    SDL_GL_SwapWindow(settings->getWin());
}

void flow::cleanFlow(){

}

bool flow::getIsRunning() const {
    return isRunning;
}
