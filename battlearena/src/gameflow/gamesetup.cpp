//
// Created by jmarierr on 2019-12-11.
//

#include "gamesetup.h"
int gamesetup::nbPlayers = 2;
int gamesetup::gameTimer;
std::string gamesetup::mapFile = "../assets/terrain/1.txt";

gamesetup::gamesetup(){

}

gamesetup::~gamesetup(){

}

int gamesetup::getNbPlayers() {
    return nbPlayers;
}

int gamesetup::getGameTimer() {
    return gameTimer;
}

const std::string &gamesetup::getMapFile() {
    return mapFile;
}

void gamesetup::setNbPlayers(int nbPlayers) {
    gamesetup::nbPlayers = nbPlayers;
}

void gamesetup::setGameTimer(int gameTimer) {
    gamesetup::gameTimer = gameTimer;
}

void gamesetup::setMapFile(const std::string &mapFile) {
    gamesetup::mapFile = mapFile;
}
