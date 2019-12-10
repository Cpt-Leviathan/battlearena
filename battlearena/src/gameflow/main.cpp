#include "../utils/includes.h"
#include "gameflow.h"


//attention il faudrait mettre des majuscule au nom des objet
int main(int argc, char **args) {
    setup *settings = new setup();
    gameflow *flow = new gameflow();
    settings->initialize(800, 600);
    flow->initialize(settings);
    //drawAxis();
    while(flow->getIsRunning()){
        flow->updateFlow();
    }
    flow->cleanFlow();
    settings->clear();
    return 0;
}