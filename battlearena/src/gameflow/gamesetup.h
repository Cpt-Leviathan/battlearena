//
// Created by jmarierr on 2019-12-11.
//

#ifndef BATTLEARENA_GAMESETUP_H
#define BATTLEARENA_GAMESETUP_H

#include "../utils/includes.h"
namespace gs{

}

class gamesetup {
public:
    static int nbPlayers;
    static int gameTimer;
    static std::string mapFile;

    gamesetup();
    ~gamesetup();
    static void setNbPlayers(int nbPlayers);
    static void setGameTimer(int gameTimer);
    static void setMapFile(const std::string &mapFile);
    static int getNbPlayers();
    static int getGameTimer();
    static const std::string &getMapFile();
};

#endif //BATTLEARENA_GAMESETUP_H
