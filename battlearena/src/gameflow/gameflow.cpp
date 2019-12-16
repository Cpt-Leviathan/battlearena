//
// Created by jmarierr on 2019-12-09.
//

#include "gameflow.h"

gameflow::gameflow(int nbPlayers, int screenWidth, int screenHeight) : nbPlayers(nbPlayers), screenWidth(screenWidth), screenHeight(screenHeight){
    x1 = 10;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    switch(nbPlayers){
        case 1:
            vpWidth = screenWidth;
            vpHeight = screenHeight;
            break;
        case 2:
            vpWidth = screenWidth;
            vpHeight = screenHeight / 2;
            break;
//        case 3:
//            vpWidth = screenWidth / 2;
//            vpHeight = screenHeight / 2;
//        case 4: ;       //3 and 4 : same screen size
    }
//    for(int i = 0; i < nbPlayers; i++){
//        setViewport.push_back()
//    }
}

gameflow::~gameflow(){

}

void gameflow::initialize(setup* _settings){
    isRunning = true;
    settings = _settings;
    terrain = new terrainManager();
    tank=new tankManager();
    tank->initialiser();
}

void gameflow::manageEvents() {
    flow::manageEvents();
    if (state[SDL_SCANCODE_A]) {

        tank->update(Direction::TOURNER_CANON_GAUCHE);
    }
    if (state[SDL_SCANCODE_D]) {
        tank->update(Direction::TOURNER_CANON_DROITE);

    }
    if (state[SDL_SCANCODE_RIGHT]) {
        tank->update(Direction::TOURNER_DROITE);

    }
    if (state[SDL_SCANCODE_LEFT]) {
        tank->update(Direction::TOURNER_GAUCHE);
    }
    if (state[SDL_SCANCODE_DOWN]) {
        tank->update(Direction::RECULE);
        //angle+5;
    }
    if (state[SDL_SCANCODE_UP]) {
        tank->update(Direction::AVANCE);
    }
    if (state[SDL_SCANCODE_SPACE]) {
        tank->update();
    }
    //TESTS - to remove later
//    f++;
//    if (f % 5 == 0) {
//        if (state[SDL_SCANCODE_W]) {
//            x1++;
//        }
//        if (state[SDL_SCANCODE_S])
//            x1--;
//
//        if (state[SDL_SCANCODE_UP])
//            x2++;
//
//        if (state[SDL_SCANCODE_DOWN])
//            x2--;
//
//        if (state[SDL_SCANCODE_A])
//            y1++;
//        if (state[SDL_SCANCODE_D])
//            y1--;
//        if (state[SDL_SCANCODE_LEFT])
//            y2++;
//        if (state[SDL_SCANCODE_RIGHT])
//            y2--;
//    }
//    f %= 5;
}

void gameflow::updateFlow(){
    clearWindow();

    manageEvents();
    draw();
    pauseFrame();
    updateWindow();
}

void gameflow::draw(){
    for(int i = 0; i < nbPlayers; i++) {
        if (nbPlayers == 2) {
            glViewport(0, i * vpHeight, vpWidth, vpHeight);
        }
        if (i == 0) {
            //gluLookAt(x1, 10, y1, 0, 10, 0, 0, 1, 0);
            gluLookAt(tank->getTank()->camera.getCamera()->eyeX + tank->getTank()->getPosition().x,
                      tank->getTank()->camera.getCamera()->eyeY,
                      tank->getTank()->camera.getCamera()->eyeZ + tank->getTank()->getPosition().y,
                      tank->getTank()->getPosition().x, 0, tank->getTank()->getPosition().y,
                      0, 1, 0
            );
            glPushMatrix();
            terrain->updateManager();
            tank->getTank()->drawTank();
            tank->getTank()->bullet.update();
            for (int j = 0; j < tank->getTank()->bullet.bullets.size(); j++) {

                tank->getTank()->bullet.bullets[j].drawBullet();
            }
            glPopMatrix();
        } else if (i == 1){
            gluLookAt(x2, 10, y2, 10, 10, 5, 0, 1, 0);
            terrain->updateManager();
        }
        //tank->update();
    }
}

void gameflow::cleanFlow(){
    delete(settings);
    //delete(state);
}

bool gameflow::getIsRunning() const{
    return isRunning;
}