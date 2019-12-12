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
    tank=new tankManager();
    tank->initialiser();
}

void gameflow::updateFlow(){
//Nettoyer la fenetre
    glClearColor(1.f, 1.f, 1.f, 1.f);

    //pb est ici

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();



    //gestion evenement
    SDL_PollEvent(&event);
    state = SDL_GetKeyboardState(NULL);
    if (event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
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
    gluLookAt(tank->getTank()->camera.getCamera()->eyeX+tank->getTank()->getPosition().x,
            tank->getTank()->camera.getCamera()->eyeY,
            tank->getTank()->camera.getCamera()->eyeZ+tank->getTank()->getPosition().y,
            tank->getTank()->getPosition().x, 0, tank->getTank()->getPosition().y,
            0, 1, 0
            );
    glPushMatrix();


    //dessin des differents objet dans la fenetre
    drawAxis(2);
    terrain->updateManager();

    tank->getTank()->drawTank();
    tank->getTank()->bullet.update();
    for (int i = 0; i < tank->getTank()->bullet.bullets.size(); i++) {

        tank->getTank()->bullet.bullets[i].drawBullet();
        /*if(tank->getTank()->bullet.bullets[i].estExpire()){

        }
        else{

        }*/
    }
    glPopMatrix();

    //pause dans l image
    SDL_Delay(100);

    //mise a jour de l ecran
    glFlush();
    SDL_GL_SwapWindow(settings->getWin());
}

void gameflow::cleanFlow(){
    delete(settings);
    //delete(state);
}

bool gameflow::getIsRunning(){
    return isRunning;
}