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

    }

}

gameflow::~gameflow(){

}

void gameflow::initialize(setup* _settings){
    isRunning = true;
    settings = _settings;
    terrain = new terrainManager();
    tank=new tankManager(nbPlayers);

    tank->initialiser();
}

void gameflow::manageEvents() {
    flow::manageEvents();
    //controle 1er tank
    if (state[SDL_SCANCODE_A]) {

        tank->update(Direction::TOURNER_CANON_GAUCHE,0);
    }
    if (state[SDL_SCANCODE_D]) {
        tank->update(Direction::TOURNER_CANON_DROITE,0);

    }
    if (state[SDL_SCANCODE_RIGHT]) {
        tank->update(Direction::TOURNER_DROITE,0);

    }
    if (state[SDL_SCANCODE_LEFT]) {
        tank->update(Direction::TOURNER_GAUCHE,0);
    }
    if (state[SDL_SCANCODE_DOWN]) {
        tank->update(Direction::RECULE,0);
        //angle+5;
    }
    if (state[SDL_SCANCODE_UP]) {
        tank->update(Direction::AVANCE,0);
    }
    if (state[SDL_SCANCODE_SPACE]) {
        tank->update(0);
    }


    //controle 2eme tank

    if (state[SDL_SCANCODE_END]) {

        tank->update(Direction::TOURNER_CANON_GAUCHE,1);
    }
    if (state[SDL_SCANCODE_HOME]) {
        tank->update(Direction::TOURNER_CANON_DROITE,1);

    }
    if (state[SDL_SCANCODE_L]) {
        tank->update(Direction::TOURNER_DROITE,1);

    }
    if (state[SDL_SCANCODE_J]) {
        tank->update(Direction::TOURNER_GAUCHE,1);
    }
    if (state[SDL_SCANCODE_K]) {
        tank->update(Direction::RECULE,1);
        //angle+5;
    }
    if (state[SDL_SCANCODE_I]) {
        tank->update(Direction::AVANCE,1);
    }
    if (state[SDL_SCANCODE_KP_ENTER]) {
        tank->update(1);
    }

    if(tank->tankList.size()==1){
        isRunning=false;
    }

    //SDL_WaitEvent(&event);
    SDL_JoystickEventState(SDL_ENABLE);
    SDL_JoystickUpdate();
    if(event.type==SDL_JOYAXISMOTION){
        if(event.jaxis.which==0) {
            if( event.jaxis.axis == 0 )
            {
                //Left of dead zone
                if( event.jaxis.value < -0 )
                {
                    tank->update(Direction::TOURNER_GAUCHE,0);
                }
                    //Right of dead zone
                else if( event.jaxis.value > 0 )
                {
                    tank->update(Direction::TOURNER_DROITE,0);
                }

            }
            else if( event.jaxis.axis == 1 )
            {
                //Below of dead zone
                if( event.jaxis.value < -0 )
                {
                    tank->update(Direction::RECULE,0);
                }
                    //Above of dead zone
                else if( event.jaxis.value > 0 )
                {
                    tank->update(Direction::AVANCE,0);
                }
            }
        }
    }
    if ( event.type == SDL_JOYHATMOTION )
    {
        // Mouvement d'un chapeau
        // Nous devons donc utiliser le champ jhat

        if ( event.jhat.value == SDL_HAT_DOWN )
        {
            tank->update(Direction::RECULE,0);
        }
        if ( event.jhat.value == SDL_HAT_LEFT )
        {
            tank->update(Direction::TOURNER_GAUCHE,0);
        }
        if ( event.jhat.value == SDL_HAT_RIGHT )
        {
            tank->update(Direction::TOURNER_DROITE,0);
        }
        if ( event.jhat.value == SDL_HAT_UP )
        {
            tank->update(Direction::AVANCE,0);
        }
    }
    if(event.type==SDL_JOYBUTTONDOWN){


            if(event.jbutton.button==0){
                if(event.jbutton.which==0){
                    tank->update(0);
                }
            }

                printf("Appui sur le bouton %d du joystick %d\n",
                       event.jbutton.button,
                       event.jbutton.which);


    }

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
            gluLookAt(tank->tankList[0]->camera.getCamera()->eyeX + tank->tankList[0]->getPosition().x,
                    tank->tankList[0]->camera.getCamera()->eyeY,
                    tank->tankList[0]->camera.getCamera()->eyeZ + tank->tankList[0]->getPosition().y,
                    tank->tankList[0]->getPosition().x, 0, tank->tankList[0]->getPosition().y,
                      0, 1, 0
            );
            glPushMatrix();
            terrain->updateManager();
            for (int k = 0; k < nbPlayers; k++) {
                //verifier si le bullet a atteint la cible
                for (int j = 0; j < tank->tankList[k]->bullet.bullets.size(); j++) {
                    int nbCibleTouche= 0;
                    for (Tank* t: tank->tankList) {
                        if(t->getId()!=k){
                            std::cout<<"bullet "<<j<<" player "<<k<<" x "<<tank->tankList[k]->bullet.bullets[j].position.x<<" y "<<tank->tankList[k]->bullet.bullets[j].position.y<<std::endl;
                            std::cout<<"playerX "<<t->getPosition().x<<" playerY "<<t->getPosition().y<<std::endl;
                            if(!((t->getPosition().x-15>=tank->tankList[k]->bullet.bullets[j].position.x+10)||
                                 (t->getPosition().x+20<=tank->tankList[k]->bullet.bullets[j].position.x-10)||
                                 t->getPosition().y-10>=tank->tankList[k]->bullet.bullets[j].position.y+5||
                                 t->getPosition().y+10<=tank->tankList[k]->bullet.bullets[j].position.x-5))   {

                                t->recevoirDommage(4);
                                nbCibleTouche++;

                            }
                        }
                    }
                    if(nbCibleTouche!=0){
                        tank->tankList[k]->bullet.bullets[j].isAlive= false;
                    }
                }


                //verifier collision tank avec murs
                int nbCollision= 0;
                for(wall* w : *terrain->walls) {
                    if(!((tank->tankList[k]->getPosition().x-15>=w->x-550)||
                         (tank->tankList[k]->getPosition().x+20<=w->x-650)||
                         tank->tankList[k]->getPosition().y-10>=w->y-200||
                         tank->tankList[k]->getPosition().y+10<=w->y-300))   {

                        nbCollision++;

                    }
                }
                if(nbCollision!=0){
                    tank->tankList[k]->setPosition(tank->tankList[0]->getDernierePosition());
                }
                tank->tankList[k]->drawTank();
                tank->tankList[k]->bullet.update(terrain);
                for (int j = 0; j < tank->tankList[k]->bullet.bullets.size(); j++) {

                    tank->tankList[k]->bullet.bullets[j].drawBullet();
                }
                tank->tankList[k]->setDernierePosition(tank->tankList[k]->getPosition());
                tank->update();
            }
            glPopMatrix();
        } else if (i == 1){
             gluLookAt(x2, 10, y2, 10, 10, 5, 0, 1, 0);
            /*gluLookAt(tank->tankList[1]->camera.getCamera()->eyeX + tank->tankList[1]->getPosition().x,
                      tank->tankList[1]->camera.getCamera()->eyeY,
                      tank->tankList[1]->camera.getCamera()->eyeZ + tank->tankList[1]->getPosition().y,
                      tank->tankList[1]->getPosition().x, 0, tank->tankList[1]->getPosition().y,
                      0, 1, 0
            );*/
            terrain->updateManager();
            for (int k = 0; k < nbPlayers; k++) {
//verifier si le bullet a atteint la cible
                for (int j = 0; j < tank->tankList[k]->bullet.bullets.size(); j++) {
                    int nbCibleTouche= 0;
                    for (Tank* t: tank->tankList) {
                        if(t->getId()!=k){
                            if(!((t->getPosition().x-15>=tank->tankList[k]->bullet.bullets[j].position.x+5)||
                                 (t->getPosition().x+20<=tank->tankList[k]->bullet.bullets[j].position.x-5)||
                                 t->getPosition().y-10>=tank->tankList[k]->bullet.bullets[j].position.y+5||
                                 t->getPosition().y+10<=tank->tankList[k]->bullet.bullets[j].position.x-5)){

                                t->recevoirDommage(4);
                                nbCibleTouche++;

                            }
                        }
                    }
                    if(nbCibleTouche!=0){
                        tank->tankList[k]->bullet.bullets[j].isAlive= false;
                    }
                }
                //verifier collision tank avec murs
                int nbCollision= 0;
                for(wall* w : *terrain->walls) {
                    if(!((tank->tankList[k]->getPosition().x-15>=w->x-550)||
                         (tank->tankList[k]->getPosition().x+20<=w->x-650)||
                         tank->tankList[k]->getPosition().y-10>=w->y-200||
                         tank->tankList[k]->getPosition().y+10<=w->y-300))   {

                        nbCollision++;

                    }
                }
                if(nbCollision!=0){
                    tank->tankList[k]->setPosition(tank->tankList[0]->getDernierePosition());
                }
                tank->tankList[k]->drawTank();
                tank->tankList[k]->bullet.update(terrain);
                for (int j = 0; j < tank->tankList[k]->bullet.bullets.size(); j++) {

                    tank->tankList[k]->bullet.bullets[j].drawBullet();
                }
                tank->tankList[k]->setDernierePosition(tank->tankList[k]->getPosition());

            }            glPopMatrix();
        }
    }
}

void gameflow::clearFlow(){
    delete(settings);
}

bool gameflow::getIsRunning() const{
    return isRunning;
}